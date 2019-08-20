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
#include <Prs3d_ToolQuadric.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Prs3d_ToolCylinder.hxx>

void bind_Prs3d_ToolCylinder(py::module &mod){

py::class_<Prs3d_ToolCylinder, std::unique_ptr<Prs3d_ToolCylinder>, Prs3d_ToolQuadric> cls_Prs3d_ToolCylinder(mod, "Prs3d_ToolCylinder", "Standard presentation algorithm that outputs graphical primitives for cylindrical surface.");

// Constructors
cls_Prs3d_ToolCylinder.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("theBottomRad"), py::arg("theTopRad"), py::arg("theHeight"), py::arg("theNbSlices"), py::arg("theNbStacks"));

// Fields

// Methods
cls_Prs3d_ToolCylinder.def_static("Create_", (opencascade::handle<Graphic3d_ArrayOfTriangles> (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const gp_Trsf &)) &Prs3d_ToolCylinder::Create, "Generate primitives for 3D quadric surface and return a filled array.", py::arg("theBottomRad"), py::arg("theTopRad"), py::arg("theHeight"), py::arg("theNbSlices"), py::arg("theNbStacks"), py::arg("theTrsf"));

// Enums

}