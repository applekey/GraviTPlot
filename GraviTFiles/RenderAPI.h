#ifndef _GRAVIT_PLOT_H_
#define _GRAVIT_PLOT_H_

/// to ask, save the data between invocations, how does the plugin get loaded?

class VisitAdapter{

	struct GravitProgramConfig
	{   
	    // Camera Params
	    double focalPoint[3];
	    double upVector[3];
	    double view_direction[3];
	    double fov;
	    double zoom;
	    int filmSize[2];

	    //Tracing Parms
	    int maxDepth;
	    int raySamples;
	    double windowJitterSize;
	    unsigned char backgroundColor[3];

	    // Parms from data
	    double dataCenter[3];
	    double dataDiagonalSize;
	};

struct GravitProgramConfig gravitProgramConfig;

public:

	struct RayTraceProperties
	{
		int maxDepth;
		int raySamples;
		double windowJitterSize;
		unsigned char backgroundColor[3];
	};

	void SetLight(int numberOfLights, int * lighttypes, double * lightDirection, unsigned char * color, double * lightIntensity);

    void SetRayTraceProperties(RayTraceProperties properties);

    void Draw(unsigned char * input);

	void SetData(double * points, int numPoints, int * edges, int numEdges, int Material, double * materialProp);

	void SetCamera(int* imageSize,  double * focalPoint, double * upVector, double * viewDirection, double zoom, double fov);
};

#endif
