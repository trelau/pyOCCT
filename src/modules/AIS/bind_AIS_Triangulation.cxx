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
#include <AIS_InteractiveObject.hxx>
#include <Standard_Handle.hxx>
#include <Poly_Triangulation.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <AIS_Triangulation.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_Selection.hxx>
#include <Graphic3d_Vec4.hxx>

void bind_AIS_Triangulation(py::module &mod){

py::class_<AIS_Triangulation, opencascade::handle<AIS_Triangulation>, AIS_InteractiveObject> cls_AIS_Triangulation(mod, "AIS_Triangulation", "Interactive object that draws data from Poly_Triangulation, optionally with colors associated with each triangulation vertex. For maximum efficiency colors are represented as 32-bit integers instead of classic Quantity_Color values. Interactive selection of triangles and vertices is not yet implemented.");

// Constructors
cls_AIS_Triangulation.def(py::init<const opencascade::handle<Poly_Triangulation> &>(), py::arg("aTriangulation"));

// Fields

// Methods
cls_AIS_Triangulation.def("SetColors", (void (AIS_Triangulation::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &AIS_Triangulation::SetColors, "Set the color for each node. Each 32-bit color is Alpha << 24 + Blue << 16 + Green << 8 + Red Order of color components is essential for further usage by OpenGL", py::arg("aColor"));
cls_AIS_Triangulation.def("GetColors", (opencascade::handle<TColStd_HArray1OfInteger> (AIS_Triangulation::*)() const) &AIS_Triangulation::GetColors, "Get the color for each node. Each 32-bit color is Alpha << 24 + Blue << 16 + Green << 8 + Red");
cls_AIS_Triangulation.def("HasVertexColors", (Standard_Boolean (AIS_Triangulation::*)() const) &AIS_Triangulation::HasVertexColors, "Returns true if triangulation has vertex colors.");
cls_AIS_Triangulation.def("SetTriangulation", (void (AIS_Triangulation::*)(const opencascade::handle<Poly_Triangulation> &)) &AIS_Triangulation::SetTriangulation, "None", py::arg("aTriangulation"));
cls_AIS_Triangulation.def("GetTriangulation", (opencascade::handle<Poly_Triangulation> (AIS_Triangulation::*)() const) &AIS_Triangulation::GetTriangulation, "Returns Poly_Triangulation .");
cls_AIS_Triangulation.def("SetTransparency", [](AIS_Triangulation &self) -> void { return self.SetTransparency(); });
cls_AIS_Triangulation.def("SetTransparency", (void (AIS_Triangulation::*)(const Standard_Real)) &AIS_Triangulation::SetTransparency, "Sets the value aValue for transparency in the reconstructed compound shape.", py::arg("aValue"));
cls_AIS_Triangulation.def("UnsetTransparency", (void (AIS_Triangulation::*)()) &AIS_Triangulation::UnsetTransparency, "Removes the setting for transparency in the reconstructed compound shape.");
cls_AIS_Triangulation.def_static("get_type_name_", (const char * (*)()) &AIS_Triangulation::get_type_name, "None");
cls_AIS_Triangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Triangulation::get_type_descriptor, "None");
cls_AIS_Triangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Triangulation::*)() const) &AIS_Triangulation::DynamicType, "None");

// Enums

}