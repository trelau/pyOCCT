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
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <TDF_LabelMap.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDocStd_Modified.hxx>
#include <Standard_Type.hxx>

void bind_TDocStd_Modified(py::module &mod){

py::class_<TDocStd_Modified, opencascade::handle<TDocStd_Modified>, TDF_Attribute> cls_TDocStd_Modified(mod, "TDocStd_Modified", "Transient attribute wich register modified labels. This attribute is attached to root label.");

// Constructors
cls_TDocStd_Modified.def(py::init<>());

// Fields

// Methods
cls_TDocStd_Modified.def_static("IsEmpty_", (Standard_Boolean (*)(const TDF_Label &)) &TDocStd_Modified::IsEmpty, "API class methods =================", py::arg("access"));
cls_TDocStd_Modified.def_static("Add_", (Standard_Boolean (*)(const TDF_Label &)) &TDocStd_Modified::Add, "None", py::arg("alabel"));
cls_TDocStd_Modified.def_static("Remove_", (Standard_Boolean (*)(const TDF_Label &)) &TDocStd_Modified::Remove, "None", py::arg("alabel"));
cls_TDocStd_Modified.def_static("Contains_", (Standard_Boolean (*)(const TDF_Label &)) &TDocStd_Modified::Contains, "None", py::arg("alabel"));
cls_TDocStd_Modified.def_static("Get_", (const TDF_LabelMap & (*)(const TDF_Label &)) &TDocStd_Modified::Get, "if <IsEmpty> raise an exception.", py::arg("access"));
cls_TDocStd_Modified.def_static("Clear_", (void (*)(const TDF_Label &)) &TDocStd_Modified::Clear, "remove all modified labels. becomes empty", py::arg("access"));
cls_TDocStd_Modified.def_static("GetID_", (const Standard_GUID & (*)()) &TDocStd_Modified::GetID, "Modified methods ================");
cls_TDocStd_Modified.def("IsEmpty", (Standard_Boolean (TDocStd_Modified::*)() const) &TDocStd_Modified::IsEmpty, "None");
cls_TDocStd_Modified.def("Clear", (void (TDocStd_Modified::*)()) &TDocStd_Modified::Clear, "None");
cls_TDocStd_Modified.def("AddLabel", (Standard_Boolean (TDocStd_Modified::*)(const TDF_Label &)) &TDocStd_Modified::AddLabel, "add <L> as modified", py::arg("L"));
cls_TDocStd_Modified.def("RemoveLabel", (Standard_Boolean (TDocStd_Modified::*)(const TDF_Label &)) &TDocStd_Modified::RemoveLabel, "remove <L> as modified", py::arg("L"));
cls_TDocStd_Modified.def("Get", (const TDF_LabelMap & (TDocStd_Modified::*)() const) &TDocStd_Modified::Get, "returns modified label map");
cls_TDocStd_Modified.def("ID", (const Standard_GUID & (TDocStd_Modified::*)() const) &TDocStd_Modified::ID, "None");
cls_TDocStd_Modified.def("Restore", (void (TDocStd_Modified::*)(const opencascade::handle<TDF_Attribute> &)) &TDocStd_Modified::Restore, "None", py::arg("With"));
cls_TDocStd_Modified.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDocStd_Modified::*)() const) &TDocStd_Modified::NewEmpty, "None");
cls_TDocStd_Modified.def("Paste", (void (TDocStd_Modified::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDocStd_Modified::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDocStd_Modified.def("Dump", (Standard_OStream & (TDocStd_Modified::*)(Standard_OStream &) const) &TDocStd_Modified::Dump, "None", py::arg("anOS"));
cls_TDocStd_Modified.def_static("get_type_name_", (const char * (*)()) &TDocStd_Modified::get_type_name, "None");
cls_TDocStd_Modified.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_Modified::get_type_descriptor, "None");
cls_TDocStd_Modified.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_Modified::*)() const) &TDocStd_Modified::DynamicType, "None");

// Enums

}