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
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <MeshVS_DisplayModeFlags.hxx>
#include <MeshVS_DataSource.hxx>
#include <MeshVS_BuilderPriority.hxx>
#include <Prs3d_Presentation.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <MeshVS_DataMapOfIntegerAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <MeshVS_TextPrsBuilder.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_TextPrsBuilder(py::module &mod){

py::class_<MeshVS_TextPrsBuilder, opencascade::handle<MeshVS_TextPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_TextPrsBuilder(mod, "MeshVS_TextPrsBuilder", "This class provides methods to create text data presentation. It store map of texts assigned with nodes or elements.");

// Constructors
cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"));
cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"));
cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"), py::arg("DS"));
cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));

// Fields

// Methods
cls_MeshVS_TextPrsBuilder.def("Build", (void (MeshVS_TextPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const) &MeshVS_TextPrsBuilder::Build, "Builds presentation of text data", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("theDisplayMode"));
cls_MeshVS_TextPrsBuilder.def("GetTexts", (const MeshVS_DataMapOfIntegerAsciiString & (MeshVS_TextPrsBuilder::*)(const Standard_Boolean) const) &MeshVS_TextPrsBuilder::GetTexts, "Returns map of text assigned with nodes ( IsElement = False ) or elements ( IsElement = True )", py::arg("IsElement"));
cls_MeshVS_TextPrsBuilder.def("SetTexts", (void (MeshVS_TextPrsBuilder::*)(const Standard_Boolean, const MeshVS_DataMapOfIntegerAsciiString &)) &MeshVS_TextPrsBuilder::SetTexts, "Sets map of text assigned with nodes or elements", py::arg("IsElement"), py::arg("Map"));
cls_MeshVS_TextPrsBuilder.def("HasTexts", (Standard_Boolean (MeshVS_TextPrsBuilder::*)(const Standard_Boolean) const) &MeshVS_TextPrsBuilder::HasTexts, "Returns True if map isn't empty", py::arg("IsElement"));
cls_MeshVS_TextPrsBuilder.def("GetText", (Standard_Boolean (MeshVS_TextPrsBuilder::*)(const Standard_Boolean, const Standard_Integer, TCollection_AsciiString &) const) &MeshVS_TextPrsBuilder::GetText, "Returns text assigned with single node or element", py::arg("IsElement"), py::arg("ID"), py::arg("Text"));
cls_MeshVS_TextPrsBuilder.def("SetText", (void (MeshVS_TextPrsBuilder::*)(const Standard_Boolean, const Standard_Integer, const TCollection_AsciiString &)) &MeshVS_TextPrsBuilder::SetText, "Sets text assigned with single node or element", py::arg("IsElement"), py::arg("ID"), py::arg("Text"));
cls_MeshVS_TextPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_TextPrsBuilder::get_type_name, "None");
cls_MeshVS_TextPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_TextPrsBuilder::get_type_descriptor, "None");
cls_MeshVS_TextPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_TextPrsBuilder::*)() const) &MeshVS_TextPrsBuilder::DynamicType, "None");

// Enums

}