/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Prs3d_Root.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <gp_Ax1.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ArrayOfSegments.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Graphic3d_Group.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Arrow.hxx>

void bind_Prs3d_Arrow(py::module &mod){

py::class_<Prs3d_Arrow, std::unique_ptr<Prs3d_Arrow>, Prs3d_Root> cls_Prs3d_Arrow(mod, "Prs3d_Arrow", "Provides class methods to draw an arrow at a given location, along a given direction and using a given angle.");

// Constructors

// Fields

// Methods
cls_Prs3d_Arrow.def_static("DrawShaded_", (opencascade::handle<Graphic3d_ArrayOfTriangles> (*)(const gp_Ax1 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer)) &Prs3d_Arrow::DrawShaded, "Defines the representation of the arrow as shaded triangulation.", py::arg("theAxis"), py::arg("theTubeRadius"), py::arg("theAxisLength"), py::arg("theConeRadius"), py::arg("theConeLength"), py::arg("theNbFacettes"));
cls_Prs3d_Arrow.def_static("DrawSegments_", (opencascade::handle<Graphic3d_ArrayOfSegments> (*)(const gp_Pnt &, const gp_Dir &, const Standard_Real, const Standard_Real, const Standard_Integer)) &Prs3d_Arrow::DrawSegments, "Defines the representation of the arrow as a container of segments.", py::arg("theLocation"), py::arg("theDir"), py::arg("theAngle"), py::arg("theLength"), py::arg("theNbSegments"));
cls_Prs3d_Arrow.def_static("Draw_", (void (*)(const opencascade::handle<Graphic3d_Group> &, const gp_Pnt &, const gp_Dir &, const Standard_Real, const Standard_Real)) &Prs3d_Arrow::Draw, "Defines the representation of the arrow. Note that this method does NOT assign any presentation aspects to the primitives group!", py::arg("theGroup"), py::arg("theLocation"), py::arg("theDirection"), py::arg("theAngle"), py::arg("theLength"));
cls_Prs3d_Arrow.def_static("Draw_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const gp_Pnt &, const gp_Dir &, const Standard_Real, const Standard_Real)) &Prs3d_Arrow::Draw, "Alias to another method Draw() for backward compatibility.", py::arg("thePrs"), py::arg("theLocation"), py::arg("theDirection"), py::arg("theAngle"), py::arg("theLength"));

// Enums

}