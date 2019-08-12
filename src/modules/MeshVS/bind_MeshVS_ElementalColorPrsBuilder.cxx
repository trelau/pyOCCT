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
#include <MeshVS_PrsBuilder.hxx>
#include <Standard_Handle.hxx>
#include <MeshVS_Mesh.hxx>
#include <MeshVS_DisplayModeFlags.hxx>
#include <MeshVS_DataSource.hxx>
#include <Standard_TypeDef.hxx>
#include <MeshVS_BuilderPriority.hxx>
#include <Prs3d_Presentation.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <MeshVS_DataMapOfIntegerColor.hxx>
#include <Quantity_Color.hxx>
#include <MeshVS_DataMapOfIntegerTwoColors.hxx>
#include <MeshVS_TwoColors.hxx>
#include <MeshVS_ElementalColorPrsBuilder.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_ElementalColorPrsBuilder(py::module &mod){

py::class_<MeshVS_ElementalColorPrsBuilder, opencascade::handle<MeshVS_ElementalColorPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_ElementalColorPrsBuilder(mod, "MeshVS_ElementalColorPrsBuilder", "This class provides methods to create presentation of elements with assigned colors. The class contains two color maps: map of same colors for front and back side of face and map of different ones,");

// Constructors
cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &>(), py::arg("Parent"));
cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Flags"));
cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"));
cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));

// Fields

// Methods
cls_MeshVS_ElementalColorPrsBuilder.def("Build", (void (MeshVS_ElementalColorPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const) &MeshVS_ElementalColorPrsBuilder::Build, "Builds presentation of elements with assigned colors.", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("DisplayMode"));
cls_MeshVS_ElementalColorPrsBuilder.def("GetColors1", (const MeshVS_DataMapOfIntegerColor & (MeshVS_ElementalColorPrsBuilder::*)() const) &MeshVS_ElementalColorPrsBuilder::GetColors1, "Returns map of colors same for front and back side of face.");
cls_MeshVS_ElementalColorPrsBuilder.def("SetColors1", (void (MeshVS_ElementalColorPrsBuilder::*)(const MeshVS_DataMapOfIntegerColor &)) &MeshVS_ElementalColorPrsBuilder::SetColors1, "Sets map of colors same for front and back side of face.", py::arg("Map"));
cls_MeshVS_ElementalColorPrsBuilder.def("HasColors1", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)() const) &MeshVS_ElementalColorPrsBuilder::HasColors1, "Returns true, if map of colors isn't empty");
cls_MeshVS_ElementalColorPrsBuilder.def("GetColor1", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, Quantity_Color &) const) &MeshVS_ElementalColorPrsBuilder::GetColor1, "Returns color assigned with element number ID", py::arg("ID"), py::arg("theColor"));
cls_MeshVS_ElementalColorPrsBuilder.def("SetColor1", (void (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, const Quantity_Color &)) &MeshVS_ElementalColorPrsBuilder::SetColor1, "Sets color assigned with element number ID", py::arg("ID"), py::arg("theColor"));
cls_MeshVS_ElementalColorPrsBuilder.def("GetColors2", (const MeshVS_DataMapOfIntegerTwoColors & (MeshVS_ElementalColorPrsBuilder::*)() const) &MeshVS_ElementalColorPrsBuilder::GetColors2, "Returns map of different colors for front and back side of face");
cls_MeshVS_ElementalColorPrsBuilder.def("SetColors2", (void (MeshVS_ElementalColorPrsBuilder::*)(const MeshVS_DataMapOfIntegerTwoColors &)) &MeshVS_ElementalColorPrsBuilder::SetColors2, "Sets map of different colors for front and back side of face", py::arg("Map"));
cls_MeshVS_ElementalColorPrsBuilder.def("HasColors2", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)() const) &MeshVS_ElementalColorPrsBuilder::HasColors2, "Returns true, if map isn't empty");
cls_MeshVS_ElementalColorPrsBuilder.def("GetColor2", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, MeshVS_TwoColors &) const) &MeshVS_ElementalColorPrsBuilder::GetColor2, "Returns colors assigned with element number ID", py::arg("ID"), py::arg("theColor"));
cls_MeshVS_ElementalColorPrsBuilder.def("GetColor2", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, Quantity_Color &, Quantity_Color &) const) &MeshVS_ElementalColorPrsBuilder::GetColor2, "Returns colors assigned with element number ID theColor1 is the front element color theColor2 is the back element color", py::arg("ID"), py::arg("theColor1"), py::arg("theColor2"));
cls_MeshVS_ElementalColorPrsBuilder.def("SetColor2", (void (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, const MeshVS_TwoColors &)) &MeshVS_ElementalColorPrsBuilder::SetColor2, "Sets colors assigned with element number ID", py::arg("ID"), py::arg("theTwoColors"));
cls_MeshVS_ElementalColorPrsBuilder.def("SetColor2", (void (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, const Quantity_Color &, const Quantity_Color &)) &MeshVS_ElementalColorPrsBuilder::SetColor2, "Sets color assigned with element number ID theColor1 is the front element color theColor2 is the back element color", py::arg("ID"), py::arg("theColor1"), py::arg("theColor2"));
cls_MeshVS_ElementalColorPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_ElementalColorPrsBuilder::get_type_name, "None");
cls_MeshVS_ElementalColorPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_ElementalColorPrsBuilder::get_type_descriptor, "None");
cls_MeshVS_ElementalColorPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_ElementalColorPrsBuilder::*)() const) &MeshVS_ElementalColorPrsBuilder::DynamicType, "None");

// Enums

}