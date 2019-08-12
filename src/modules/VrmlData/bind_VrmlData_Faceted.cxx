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
#include <VrmlData_Geometry.hxx>
#include <VrmlData_Scene.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_Faceted.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Faceted(py::module &mod){

py::class_<VrmlData_Faceted, opencascade::handle<VrmlData_Faceted>, VrmlData_Geometry> cls_VrmlData_Faceted(mod, "VrmlData_Faceted", "Common API of faceted Geometry nodes: IndexedFaceSet, ElevationGrid, Extrusion.");

// Fields

// Methods
cls_VrmlData_Faceted.def("IsCCW", (Standard_Boolean (VrmlData_Faceted::*)() const) &VrmlData_Faceted::IsCCW, "Query 'Is Counter-Clockwise' attribute");
cls_VrmlData_Faceted.def("IsSolid", (Standard_Boolean (VrmlData_Faceted::*)() const) &VrmlData_Faceted::IsSolid, "Query 'Is Solid' attribute");
cls_VrmlData_Faceted.def("IsConvex", (Standard_Boolean (VrmlData_Faceted::*)() const) &VrmlData_Faceted::IsConvex, "Query 'Is Convex' attribute");
cls_VrmlData_Faceted.def("CreaseAngle", (Standard_Real (VrmlData_Faceted::*)() const) &VrmlData_Faceted::CreaseAngle, "Query the Crease Angle");
cls_VrmlData_Faceted.def("SetCCW", (void (VrmlData_Faceted::*)(const Standard_Boolean)) &VrmlData_Faceted::SetCCW, "Set 'Is Counter-Clockwise' attribute", py::arg("theValue"));
cls_VrmlData_Faceted.def("SetSolid", (void (VrmlData_Faceted::*)(const Standard_Boolean)) &VrmlData_Faceted::SetSolid, "Set 'Is Solid' attribute", py::arg("theValue"));
cls_VrmlData_Faceted.def("SetConvex", (void (VrmlData_Faceted::*)(const Standard_Boolean)) &VrmlData_Faceted::SetConvex, "Set 'Is Convex' attribute", py::arg("theValue"));
cls_VrmlData_Faceted.def("SetCreaseAngle", (void (VrmlData_Faceted::*)(const Standard_Real)) &VrmlData_Faceted::SetCreaseAngle, "Set 'Is Convex' attribute", py::arg("theValue"));
cls_VrmlData_Faceted.def_static("get_type_name_", (const char * (*)()) &VrmlData_Faceted::get_type_name, "None");
cls_VrmlData_Faceted.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Faceted::get_type_descriptor, "None");
cls_VrmlData_Faceted.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Faceted::*)() const) &VrmlData_Faceted::DynamicType, "None");

// Enums

}