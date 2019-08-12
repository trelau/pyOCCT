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
#include <XCAFDoc_Datum.hxx>
#include <TDF_Label.hxx>
#include <TCollection_HAsciiString.hxx>
#include <XCAFDimTolObjects_DatumObject.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_Datum(py::module &mod){

py::class_<XCAFDoc_Datum, opencascade::handle<XCAFDoc_Datum>, TDF_Attribute> cls_XCAFDoc_Datum(mod, "XCAFDoc_Datum", "attribute to store datum");

// Constructors
cls_XCAFDoc_Datum.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_Datum.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Datum::GetID, "None");
cls_XCAFDoc_Datum.def_static("Set_", (opencascade::handle<XCAFDoc_Datum> (*)(const TDF_Label &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_Datum::Set, "None", py::arg("label"), py::arg("aName"), py::arg("aDescription"), py::arg("anIdentification"));
cls_XCAFDoc_Datum.def_static("Set_", (opencascade::handle<XCAFDoc_Datum> (*)(const TDF_Label &)) &XCAFDoc_Datum::Set, "None", py::arg("theLabel"));
cls_XCAFDoc_Datum.def("Set", (void (XCAFDoc_Datum::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_Datum::Set, "None", py::arg("aName"), py::arg("aDescription"), py::arg("anIdentification"));
cls_XCAFDoc_Datum.def("GetName", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::GetName, "None");
cls_XCAFDoc_Datum.def("GetDescription", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::GetDescription, "None");
cls_XCAFDoc_Datum.def("GetIdentification", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::GetIdentification, "None");
cls_XCAFDoc_Datum.def("GetObject", (opencascade::handle<XCAFDimTolObjects_DatumObject> (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::GetObject, "Returns dimension object data taken from the paren's label and its sub-labels.");
cls_XCAFDoc_Datum.def("SetObject", (void (XCAFDoc_Datum::*)(const opencascade::handle<XCAFDimTolObjects_DatumObject> &)) &XCAFDoc_Datum::SetObject, "Updates parent's label and its sub-labels with data taken from theDatumObject. Old data associated with the label will be lost.", py::arg("theDatumObject"));
cls_XCAFDoc_Datum.def("ID", (const Standard_GUID & (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::ID, "None");
cls_XCAFDoc_Datum.def("Restore", (void (XCAFDoc_Datum::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Datum::Restore, "None", py::arg("With"));
cls_XCAFDoc_Datum.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::NewEmpty, "None");
cls_XCAFDoc_Datum.def("Paste", (void (XCAFDoc_Datum::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Datum::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Datum.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Datum::get_type_name, "None");
cls_XCAFDoc_Datum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Datum::get_type_descriptor, "None");
cls_XCAFDoc_Datum.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Datum::*)() const) &XCAFDoc_Datum::DynamicType, "None");

// Enums

}