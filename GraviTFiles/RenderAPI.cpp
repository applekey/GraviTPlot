/* =======================================================================================
   This file is released as part of GraviT - scalable, platform independent ray tracing
   tacc.github.io/GraviT

   Copyright 2013-2015 Texas Advanced Computing Center, The University of Texas at Austin
   All rights reserved.

   Licensed under the BSD 3-Clause License, (the "License"); you may not use this file
   except in compliance with the License.
   A copy of the License is included with this software in the file LICENSE.
   If your copy does not contain the License, you may obtain a copy of the License at:

       http://opensource.org/licenses/BSD-3-Clause

   Unless required by applicable law or agreed to in writing, software distributed under
   the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
   KIND, either express or implied.
   See the License for the specific language governing permissions and limitations under
   limitations under the License.

   GraviT is funded in part by the US National Science Foundation under awards ACI-1339863,
   ACI-1339881 and ACI-1339840
   ======================================================================================= */
/**
 * A simple GraviT application that loads some geometry and renders it.
 *
 * This application renders a simple scene of cones and cubes using the GraviT interface.
 * This will run in both single-process and MPI modes. You can alter the work scheduler

 * used by changing line 242.
 *
*/


#include "RenderAPI.h"


#include <algorithm>
#include <gvt/core/Math.h>
#include <gvt/core/Variant.h>
#include <gvt/core/mpi/Wrapper.h>
#include <gvt/render/RenderContext.h>
#include <gvt/render/Schedulers.h>
#include <gvt/render/Types.h>
#include <gvt/render/data/Domains.h>
#include <set>
#include <vector>

#include <tbb/task_scheduler_init.h>
#include <thread>

#ifdef GVT_RENDER_ADAPTER_EMBREE
#include <gvt/render/adapter/embree/Wrapper.h>
#endif

#ifdef GVT_RENDER_ADAPTER_MANTA
#include <gvt/render/adapter/manta/Wrapper.h>
#endif

#ifdef GVT_RENDER_ADAPTER_OPTIX
#include <gvt/render/adapter/optix/Wrapper.h>
#endif

#ifdef GVT_USE_MPE
#include "mpe.h"
#endif
#include <gvt/render/algorithm/Tracers.h>
#include <gvt/render/data/Primitives.h>
#include <gvt/render/data/scene/Image.h>
#include <gvt/render/data/scene/gvtCamera.h>

#include <float.h>


#include <iostream>

#ifdef __USE_TAU
#include <TAU.h>
#endif

#include "ParseCommandLine.h"

using namespace std;
using namespace gvt::render;

using namespace gvt::core::mpi;
using namespace gvt::render::data::scene;
using namespace gvt::render::schedule;
using namespace gvt::render::data::primitives;


void VisitAdapter::SetRayTraceProperties(RayTraceProperties properties)
{
  gravitProgramConfig.maxDepth = properties.maxDepth;
  gravitProgramConfig.raySamples = properties.raySamples;
  gravitProgramConfig.windowJitterSize = properties.windowJitterSize;
  gravitProgramConfig.backgroundColor[0] = properties.backgroundColor[0];
  gravitProgramConfig.backgroundColor[1] = properties.backgroundColor[1];
  gravitProgramConfig.backgroundColor[2] = properties.backgroundColor[2];
}

void VisitAdapter::SetLight(int numberOfLights, int * lighttypes, double * lightDirection, unsigned char * color, double * lightIntensity)
{
  gvt::render::RenderContext *cntxt = gvt::render::RenderContext::instance();
  if (cntxt == NULL) {
    std::cout << "Something went wrong initializing the context" << std::endl;
    exit(0);
  }

  gvt::core::DBNodeH root = cntxt->getRootNode();
  
  // check if lightnodes has already being created

  gvt::core::DBNodeH lightNodes = cntxt->findChildNodeByName("Lights",root.UUID());
  if(!lightNodes)
  {
    lightNodes = cntxt->createNodeFromType("Lights", "Lights", root.UUID());
  }
  else
  {
    std::cerr<<"found lights node"<<std::endl;
    cntxt->deleteChildren(lightNodes.UUID());
  }

  for(int i = 0;i < numberOfLights ;i++)
  {
    float distanceMod = -1;

    int lType = *(lighttypes+ i);

    double * center;

    if(lType == 2) // this is camera 
    {
      center = gravitProgramConfig.focalPoint;
      distanceMod = gravitProgramConfig.dataDiagonalSize;
    }
    else if(lType == 1) // this is object
    {
      center = gravitProgramConfig.dataCenter;
      distanceMod = gravitProgramConfig.dataDiagonalSize;
    }
    else
    {
      continue; // The rest are not supported for the time being
    }

    double * lDirection = lightDirection + i * 3;
    unsigned  char * lcolor = color + i * 3;
    double intensity = *(lightIntensity + i);

    glm::vec3 vLdirection(lDirection[0],lDirection[1],lDirection[2]);
    vLdirection = -vLdirection;

    glm::vec3 lPosition = glm::vec3(center[0],center[1],center[2]) + vLdirection * float(2/ intensity);

    std::cerr<<lPosition[0] <<" "<<lPosition[1]<<" "<<lPosition[2]<<std::endl;

    // assume for now that everthing is a point light
    std::string baseName = "conelight";
    baseName += baseName+std::to_string(i);


    gvt::core::DBNodeH lightNode = cntxt->createNodeFromType("PointLight", baseName.c_str(), lightNodes.UUID());

    lightNode["position"] = lPosition;
    lightNode["color"] = glm::vec3((unsigned int)lcolor[0]/(float)255, (unsigned int)lcolor[1]/(float)255, (unsigned int)lcolor[2]/(float)255);

  }
}


void VisitAdapter::SetCamera(int * imageSize, double * focalPoint, double * upVector, double * viewDirection, double zoom, double fov)
{
   
  gravitProgramConfig.focalPoint[0] = focalPoint[0];
  gravitProgramConfig.focalPoint[1] = focalPoint[1];
  gravitProgramConfig.focalPoint[2] = focalPoint[2];

  gravitProgramConfig.upVector[0] = -upVector[0];
  gravitProgramConfig.upVector[1] = -upVector[1];
  gravitProgramConfig.upVector[2] = -upVector[2];

  gravitProgramConfig.fov = fov;
  gravitProgramConfig.zoom = zoom;


  // need to invert view normal
  gravitProgramConfig.view_direction[0] = -viewDirection[0];
  gravitProgramConfig.view_direction[1] = -viewDirection[1];
  gravitProgramConfig.view_direction[2] = -viewDirection[2];

  
  gravitProgramConfig.filmSize[0] = imageSize[0];
  gravitProgramConfig.filmSize[1] = imageSize[1];

  // std::cerr<<"FocalPoint"<<focalPoint[0]<<" "<<focalPoint[1]<<" "<<focalPoint[2]<<std::endl;
  // std::cerr<<"UpVector"<<upVector[0]<<" "<<upVector[1]<<" "<<upVector[2]<<std::endl;
  // std::cerr<<"fov"<<fov<<std::endl;
  // std::cerr<<"zoom"<<zoom<<std::endl;
  // std::cerr<<"viewDirection"<<viewDirection[0]<<" "<<viewDirection[1]<<" "<<viewDirection[2]<<std::endl;
}

void VisitAdapter::Draw(unsigned char * image)
{
	std::cerr<<"entered Draw"<<std::endl;

  gvt::render::RenderContext *cntxt = gvt::render::RenderContext::instance();
  if (cntxt == NULL) {
    std::cout << "Something went wrong initializing the context" << std::endl;
    exit(0);
  }


  gvt::core::DBNodeH root = cntxt->getRootNode();

  gvt::core::DBNodeH camNode = cntxt->createNodeFromType("Camera", "conecam", root.UUID());
  gvt::core::DBNodeH filmNode = cntxt->createNodeFromType("Film", "conefilm", root.UUID());

  filmNode["width"] = gravitProgramConfig.filmSize[0];
  filmNode["height"] = gravitProgramConfig.filmSize[1];
  
  gvtPerspectiveCamera mycamera;

  // calculate cameraposition from direction and zoom

  glm::vec3 focalPoint = glm::vec3(gravitProgramConfig.focalPoint[0], gravitProgramConfig.focalPoint[1], gravitProgramConfig.focalPoint[2]);
  glm::vec3 direction = glm::vec3(gravitProgramConfig.view_direction[0],gravitProgramConfig.view_direction[1],gravitProgramConfig.view_direction[2]);
  glm::vec3 camPosition = focalPoint - (float(gravitProgramConfig.zoom ) * direction);

  float fov = gravitProgramConfig.fov;
  glm::vec3 up = glm::vec3(gravitProgramConfig.upVector[0],gravitProgramConfig.upVector[1],gravitProgramConfig.upVector[2]);

  int rayMaxDepth = gravitProgramConfig.maxDepth;
  int raySamples = gravitProgramConfig.raySamples;
  float jitterWindowSize = gravitProgramConfig.windowJitterSize;

  mycamera.setMaxDepth(rayMaxDepth);
  mycamera.setSamples(raySamples);
  mycamera.setJitterWindowSize(jitterWindowSize);
  mycamera.lookAt(camPosition, focalPoint, up);
  mycamera.setFOV(fov);
  mycamera.setFilmsize(gravitProgramConfig.filmSize[0],gravitProgramConfig.filmSize[1]);
  
  // mycamera.setFilmsize(filmNode["width"].value().toInteger(), filmNode["height"].value().toInteger());

  gvt::core::DBNodeH schedNode = cntxt->createNodeFromType("Schedule", "Enzosched", root.UUID());
  schedNode["type"] = gvt::render::scheduler::Image;
  schedNode["adapter"] = gvt::render::adapter::Embree;

  // setup image from database sizes
  Image myimage(mycamera.getFilmSizeWidth(), mycamera.getFilmSizeHeight(), "bunny");

  mycamera.AllocateCameraRays();
  mycamera.generateRays();


  gvt::render::algorithm::Tracer<ImageScheduler> tracer(mycamera.rays, myimage);
  tracer.sample_ratio = 1.0 / float(raySamples * raySamples);

  tracer();


  myimage.WriteChar(image);
  //if (MPI::COMM_WORLD.Get_size() > 1) MPI_Finalize();
}


void  VisitAdapter::SetData(double * points, int numPoints, int * edges, int numEdges, int Material, double * materialProp)
{
	std::cerr<<"entered SetData"<<std::endl;

   // MPI_Init(NULL, NULL);
   // MPI_Pcontrol(0);
   // int rank = -1;
   // MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  gvt::render::RenderContext *cntxt = gvt::render::RenderContext::instance();
  if (cntxt == NULL) {
    std::cout << "Something went wrong initializing the context" << std::endl;
    exit(0);
  }

  gvt::core::DBNodeH root = cntxt->getRootNode();



  gvt::core::DBNodeH dataNodes = cntxt->findChildNodeByName("Data",root.UUID());
  if(!dataNodes)
  {
    dataNodes = cntxt->createNodeFromType("Data", "Data", root.UUID());
  }
  else
  {
    std::cerr<<"found data node"<<std::endl;
    cntxt->deleteChildren(dataNodes.UUID());
  }



  gvt::core::DBNodeH coneMeshNode = cntxt->createNodeFromType("Mesh", "conemesh", dataNodes.UUID());
   {
	
	std::cerr << "Attribs: \n" << "Material: " << Material << "\nDiff Color: " << materialProp[0] << ", " << materialProp[1] << ", " << materialProp[2] << "\nSpec Color: " << materialProp[4] << ", " << materialProp[5] << ", " << materialProp[6] << std::endl;
	
    Mesh *mesh;
    switch (Material)
    {
	case 0:
    		mesh = new Mesh(new Lambert(glm::vec3(materialProp[0], materialProp[1], materialProp[2])));
		break;
	case 1:
    		mesh = new Mesh(new Phong(glm::vec3(materialProp[0], materialProp[1], materialProp[2]), glm::vec3(materialProp[4], materialProp[5], materialProp[6])));
		break;
	case 2:
    		mesh = new Mesh(new BlinnPhong(glm::vec3(materialProp[0], materialProp[1], materialProp[2]), glm::vec3(materialProp[4], materialProp[5], materialProp[6])));
		break;
   	default:
		exit(EXIT_FAILURE);
    }

    double * point = points;

    glm::vec3 lower(FLT_MAX,FLT_MAX,FLT_MAX);
    glm::vec3 upper(FLT_MIN,FLT_MIN,FLT_MIN);
    
    for(int i =0;i< numPoints;i++)
    {
      glm::vec3 newPoint(*point,*(point+1),*(point+2));
      mesh->addVertex(newPoint);
      point +=3;

      for (int j = 0; j < 3; j++) {
        lower[j] = (lower[j] < newPoint[j]) ? lower[j] : newPoint[j];
        upper[j] = (upper[j] > newPoint[j]) ? upper[j] : newPoint[j];
      }
    }

    int * edge = edges;
    for(int i =0;i< numEdges;i++)
    {
      mesh->addFace(*(edge), *(edge+1), *(edge+2));
      edge+=3;
    }

    mesh->generateNormals();

  
    // calculate bbox
    Box3D *meshbbox = new gvt::render::data::primitives::Box3D(lower, upper);

    // add cone mesh to the database
    gvt::core::Variant meshvariant(mesh);
    std::cout << "meshvariant " << meshvariant << std::endl;
    coneMeshNode["file"] = string("/fake/path/to/cone");
    coneMeshNode["bbox"] = (unsigned long long)meshbbox;
    coneMeshNode["ptr"] = (unsigned long long)mesh;
   }
  

  gvt::core::DBNodeH instNodes = cntxt->findChildNodeByName("Instances",root.UUID());
  if(!instNodes)
  {
    instNodes = cntxt->createNodeFromType("Instances", "Instances", root.UUID());
  }
  else
  {
    std::cerr<<"found inst nodes"<<std::endl;
    cntxt->deleteChildren(instNodes.UUID());
  }

  gvt::core::DBNodeH instnode = cntxt->createNodeFromType("Instance", "inst", instNodes.UUID());

  gvt::core::DBNodeH meshNode = coneMeshNode;
  Box3D *mbox = (Box3D *)meshNode["bbox"].value().toULongLong();

  instnode["id"] = 0; // unique id per instance
  instnode["meshRef"] = meshNode.UUID();

  // transform bunny
  float scale = 1.0;
  auto m = new glm::mat4(1.f);
  auto minv = new glm::mat4(1.f);
  auto normi = new glm::mat3(1.f);
  //*m = glm::translate(*m, glm::vec3(0, 0, 0));
  //*m *glm::mat4::createTranslation(0.0, 0.0, 0.0);
  //*m = *m * glm::mat4::createScale(scale, scale, scale);
  *m = glm::scale(*m, glm::vec3(scale, scale, scale));

  instnode["mat"] = (unsigned long long)m;
  *minv = glm::inverse(*m);
  instnode["matInv"] = (unsigned long long)minv;
  *normi = glm::transpose(glm::inverse(glm::mat3(*m)));
  instnode["normi"] = (unsigned long long)normi;

  // transform mesh bounding box
  auto il = glm::vec3((*m) * glm::vec4(mbox->bounds_min, 1.f));
  auto ih = glm::vec3((*m) * glm::vec4(mbox->bounds_max, 1.f));
  Box3D *ibox = new gvt::render::data::primitives::Box3D(il, ih);
  instnode["bbox"] = (unsigned long long)ibox;
  instnode["centroid"] = ibox->centroid();

  // find the size of the bounding box

  double bbDiagSize = powf((ih[0] - il[0]),2) + powf((ih[1] - il[1]),2) + powf((ih[2] - il[2]),2);
  bbDiagSize = powf(bbDiagSize,0.5);

  gravitProgramConfig.dataCenter[0] = (ih[0] - il[0])/2.0;
  gravitProgramConfig.dataCenter[1] = (ih[1] - il[1])/2.0;
  gravitProgramConfig.dataCenter[2] = (ih[2] - il[2])/2.0;

  gravitProgramConfig.dataDiagonalSize = bbDiagSize;

  
  // gvt::core::DBNodeH lightNodes = cntxt->createNodeFromType("Lights", "Lights", root.UUID());
  // gvt::core::DBNodeH lightNode = cntxt->createNodeFromType("PointLight", "conelight", lightNodes.UUID());
  // lightNode["position"] = glm::vec3(1.0, 0.0, 1.0);
  // lightNode["color"] = glm::vec3(1.0, 1.0, 1.0);
}


