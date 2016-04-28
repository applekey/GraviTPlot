// ***************************************************************************
//
// Copyright (c) 2000 - 2015, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory
// LLNL-CODE-442911
// All rights reserved.
//
// This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
// full copyright notice is contained in the file COPYRIGHT located at the root
// of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
//
// Redistribution  and  use  in  source  and  binary  forms,  with  or  without
// modification, are permitted provided that the following conditions are met:
//
//  - Redistributions of  source code must  retain the above  copyright notice,
//    this list of conditions and the disclaimer below.
//  - Redistributions in binary form must reproduce the above copyright notice,
//    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
//    documentation and/or other materials provided with the distribution.
//  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
//    be used to endorse or promote products derived from this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
// ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
// LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
// DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
// SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
// CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
// OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ***************************************************************************

package llnl.visit.plots;

import llnl.visit.AttributeSubject;
import llnl.visit.CommunicationBuffer;
import llnl.visit.Plugin;
import llnl.visit.ColorAttribute;

// ****************************************************************************
// Class: GraviTAttributes
//
// Purpose:
//    Attributes for GraviT plot
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class GraviTAttributes extends AttributeSubject implements Plugin
{
    private static int GraviTAttributes_numAdditionalAtts = 4;

    // Enum values
    public final static int MATERIALTYPE_LAMBERT = 0;
    public final static int MATERIALTYPE_PHONG = 1;
    public final static int MATERIALTYPE_BLINNPHONG = 2;


    public GraviTAttributes()
    {
        super(GraviTAttributes_numAdditionalAtts);

        DiffColor = new ColorAttribute(200, 127, 127);
        SpecColor = new ColorAttribute(127, 127, 200);
        MaxReflections = 2;
        Material = MATERIALTYPE_BLINNPHONG;
    }

    public GraviTAttributes(int nMoreFields)
    {
        super(GraviTAttributes_numAdditionalAtts + nMoreFields);

        DiffColor = new ColorAttribute(200, 127, 127);
        SpecColor = new ColorAttribute(127, 127, 200);
        MaxReflections = 2;
        Material = MATERIALTYPE_BLINNPHONG;
    }

    public GraviTAttributes(GraviTAttributes obj)
    {
        super(GraviTAttributes_numAdditionalAtts);

        DiffColor = new ColorAttribute(obj.DiffColor);
        SpecColor = new ColorAttribute(obj.SpecColor);
        MaxReflections = obj.MaxReflections;
        Material = obj.Material;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return GraviTAttributes_numAdditionalAtts;
    }

    public boolean equals(GraviTAttributes obj)
    {
        // Create the return value
        return ((DiffColor == obj.DiffColor) &&
                (SpecColor == obj.SpecColor) &&
                (MaxReflections == obj.MaxReflections) &&
                (Material == obj.Material));
    }

    public String GetName() { return "GraviT"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetDiffColor(ColorAttribute DiffColor_)
    {
        DiffColor = DiffColor_;
        Select(0);
    }

    public void SetSpecColor(ColorAttribute SpecColor_)
    {
        SpecColor = SpecColor_;
        Select(1);
    }

    public void SetMaxReflections(int MaxReflections_)
    {
        MaxReflections = MaxReflections_;
        Select(2);
    }

    public void SetMaterial(int Material_)
    {
        Material = Material_;
        Select(3);
    }

    // Property getting methods
    public ColorAttribute GetDiffColor() { return DiffColor; }
    public ColorAttribute GetSpecColor() { return SpecColor; }
    public int            GetMaxReflections() { return MaxReflections; }
    public int            GetMaterial() { return Material; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            DiffColor.Write(buf);
        if(WriteSelect(1, buf))
            SpecColor.Write(buf);
        if(WriteSelect(2, buf))
            buf.WriteInt(MaxReflections);
        if(WriteSelect(3, buf))
            buf.WriteInt(Material);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            DiffColor.Read(buf);
            Select(0);
            break;
        case 1:
            SpecColor.Read(buf);
            Select(1);
            break;
        case 2:
            SetMaxReflections(buf.ReadInt());
            break;
        case 3:
            SetMaterial(buf.ReadInt());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "DiffColor = {" + DiffColor.Red() + ", " + DiffColor.Green() + ", " + DiffColor.Blue() + ", " + DiffColor.Alpha() + "}\n";
        str = str + indent + "SpecColor = {" + SpecColor.Red() + ", " + SpecColor.Green() + ", " + SpecColor.Blue() + ", " + SpecColor.Alpha() + "}\n";
        str = str + intToString("MaxReflections", MaxReflections, indent) + "\n";
        str = str + indent + "Material = ";
        if(Material == MATERIALTYPE_LAMBERT)
            str = str + "MATERIALTYPE_LAMBERT";
        if(Material == MATERIALTYPE_PHONG)
            str = str + "MATERIALTYPE_PHONG";
        if(Material == MATERIALTYPE_BLINNPHONG)
            str = str + "MATERIALTYPE_BLINNPHONG";
        str = str + "\n";
        return str;
    }


    // Attributes
    private ColorAttribute DiffColor;
    private ColorAttribute SpecColor;
    private int            MaxReflections;
    private int            Material;
}

