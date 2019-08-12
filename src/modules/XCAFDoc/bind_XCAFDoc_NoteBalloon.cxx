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
#include <XCAFDoc_NoteComment.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_NoteBalloon.hxx>
#include <Standard_Type.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TDF_Attribute.hxx>

void bind_XCAFDoc_NoteBalloon(py::module &mod){

py::class_<XCAFDoc_NoteBalloon, opencascade::handle<XCAFDoc_NoteBalloon>, XCAFDoc_NoteComment> cls_XCAFDoc_NoteBalloon(mod, "XCAFDoc_NoteBalloon", "A comment note attribute. Contains a textual comment.");

// Constructors
cls_XCAFDoc_NoteBalloon.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_NoteBalloon.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_NoteBalloon::get_type_name, "None");
cls_XCAFDoc_NoteBalloon.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_NoteBalloon::get_type_descriptor, "None");
cls_XCAFDoc_NoteBalloon.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_NoteBalloon::*)() const) &XCAFDoc_NoteBalloon::DynamicType, "None");
cls_XCAFDoc_NoteBalloon.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_NoteBalloon::GetID, "Returns default attribute GUID");
cls_XCAFDoc_NoteBalloon.def_static("Get_", (opencascade::handle<XCAFDoc_NoteBalloon> (*)(const TDF_Label &)) &XCAFDoc_NoteBalloon::Get, "Finds a reference attribute on the given label and returns it, if it is found", py::arg("theLabel"));
cls_XCAFDoc_NoteBalloon.def_static("Set_", (opencascade::handle<XCAFDoc_NoteBalloon> (*)(const TDF_Label &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &XCAFDoc_NoteBalloon::Set, "Create (if not exist) a comment note on the given label.", py::arg("theLabel"), py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theComment"));
cls_XCAFDoc_NoteBalloon.def("ID", (const Standard_GUID & (XCAFDoc_NoteBalloon::*)() const) &XCAFDoc_NoteBalloon::ID, "None");
cls_XCAFDoc_NoteBalloon.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_NoteBalloon::*)() const) &XCAFDoc_NoteBalloon::NewEmpty, "None");

// Enums

}