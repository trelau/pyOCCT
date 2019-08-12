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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <MeshVS_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <MeshVS_DataMapOfIntegerBoolean.hxx>
#include <TColStd_DataMapOfIntegerReal.hxx>
#include <MeshVS_DataMapOfIntegerColor.hxx>
#include <MeshVS_DataMapOfIntegerMaterial.hxx>
#include <MeshVS_DataMapOfIntegerAsciiString.hxx>

void bind_MeshVS_Drawer(py::module &mod){

py::class_<MeshVS_Drawer, opencascade::handle<MeshVS_Drawer>, Standard_Transient> cls_MeshVS_Drawer(mod, "MeshVS_Drawer", "This class provided the common interface to share between classes big set of constants affecting to object appearance. By default, this class can store integers, doubles, OCC colors, OCC materials. Each of OCC enum members can be stored as integers.");

// Constructors

// Fields

// Methods
cls_MeshVS_Drawer.def("Assign", (void (MeshVS_Drawer::*)(const opencascade::handle<MeshVS_Drawer> &)) &MeshVS_Drawer::Assign, "This method copies other drawer contents to this.", py::arg("aDrawer"));
cls_MeshVS_Drawer.def("SetInteger", (void (MeshVS_Drawer::*)(const Standard_Integer, const Standard_Integer)) &MeshVS_Drawer::SetInteger, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("SetDouble", (void (MeshVS_Drawer::*)(const Standard_Integer, const Standard_Real)) &MeshVS_Drawer::SetDouble, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("SetBoolean", (void (MeshVS_Drawer::*)(const Standard_Integer, const Standard_Boolean)) &MeshVS_Drawer::SetBoolean, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("SetColor", (void (MeshVS_Drawer::*)(const Standard_Integer, const Quantity_Color &)) &MeshVS_Drawer::SetColor, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("SetMaterial", (void (MeshVS_Drawer::*)(const Standard_Integer, const Graphic3d_MaterialAspect &)) &MeshVS_Drawer::SetMaterial, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("SetAsciiString", (void (MeshVS_Drawer::*)(const Standard_Integer, const TCollection_AsciiString &)) &MeshVS_Drawer::SetAsciiString, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetInteger", [](MeshVS_Drawer &self, const Standard_Integer Key, Standard_Integer & Value){ Standard_Boolean rv = self.GetInteger(Key, Value); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, Value); }, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetDouble", [](MeshVS_Drawer &self, const Standard_Integer Key, Standard_Real & Value){ Standard_Boolean rv = self.GetDouble(Key, Value); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Value); }, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetBoolean", [](MeshVS_Drawer &self, const Standard_Integer Key, Standard_Boolean & Value){ Standard_Boolean rv = self.GetBoolean(Key, Value); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, Value); }, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetColor", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, Quantity_Color &) const) &MeshVS_Drawer::GetColor, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetMaterial", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, Graphic3d_MaterialAspect &) const) &MeshVS_Drawer::GetMaterial, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("GetAsciiString", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, TCollection_AsciiString &) const) &MeshVS_Drawer::GetAsciiString, "None", py::arg("Key"), py::arg("Value"));
cls_MeshVS_Drawer.def("RemoveInteger", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveInteger, "None", py::arg("Key"));
cls_MeshVS_Drawer.def("RemoveDouble", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveDouble, "None", py::arg("Key"));
cls_MeshVS_Drawer.def("RemoveBoolean", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveBoolean, "None", py::arg("Key"));
cls_MeshVS_Drawer.def("RemoveColor", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveColor, "None", py::arg("Key"));
cls_MeshVS_Drawer.def("RemoveMaterial", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveMaterial, "None", py::arg("Key"));
cls_MeshVS_Drawer.def("RemoveAsciiString", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveAsciiString, "None", py::arg("Key"));
cls_MeshVS_Drawer.def_static("get_type_name_", (const char * (*)()) &MeshVS_Drawer::get_type_name, "None");
cls_MeshVS_Drawer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_Drawer::get_type_descriptor, "None");
cls_MeshVS_Drawer.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_Drawer::*)() const) &MeshVS_Drawer::DynamicType, "None");

// Enums

}