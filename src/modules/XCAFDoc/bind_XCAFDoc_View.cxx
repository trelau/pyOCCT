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
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_View.hxx>
#include <TDF_Label.hxx>
#include <TDF_RelocationTable.hxx>
#include <XCAFView_Object.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_View(py::module &mod){

py::class_<XCAFDoc_View, opencascade::handle<XCAFDoc_View>, TDF_Attribute> cls_XCAFDoc_View(mod, "XCAFDoc_View", "Attribute to store view");

// Constructors
cls_XCAFDoc_View.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_View.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_View::GetID, "None");
cls_XCAFDoc_View.def_static("Set_", (opencascade::handle<XCAFDoc_View> (*)(const TDF_Label &)) &XCAFDoc_View::Set, "None", py::arg("theLabel"));
cls_XCAFDoc_View.def("ID", (const Standard_GUID & (XCAFDoc_View::*)() const) &XCAFDoc_View::ID, "None");
cls_XCAFDoc_View.def("Restore", (void (XCAFDoc_View::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_View::Restore, "None", py::arg("With"));
cls_XCAFDoc_View.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_View::*)() const) &XCAFDoc_View::NewEmpty, "None");
cls_XCAFDoc_View.def("Paste", (void (XCAFDoc_View::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_View::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_View.def("SetObject", (void (XCAFDoc_View::*)(const opencascade::handle<XCAFView_Object> &)) &XCAFDoc_View::SetObject, "Updates parent's label and its sub-labels with data taken from theViewObject. Old data associated with the label will be lost.", py::arg("theViewObject"));
cls_XCAFDoc_View.def("GetObject", (opencascade::handle<XCAFView_Object> (XCAFDoc_View::*)() const) &XCAFDoc_View::GetObject, "Returns view object data taken from the paren's label and its sub-labels.");
cls_XCAFDoc_View.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_View::get_type_name, "None");
cls_XCAFDoc_View.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_View::get_type_descriptor, "None");
cls_XCAFDoc_View.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_View::*)() const) &XCAFDoc_View::DynamicType, "None");

// Enums

}