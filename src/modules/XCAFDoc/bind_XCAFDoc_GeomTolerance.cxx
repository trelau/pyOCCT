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
#include <Standard_Handle.hxx>
#include <XCAFDoc_GeomTolerance.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <XCAFDimTolObjects_GeomToleranceObject.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_GeomTolerance(py::module &mod){

py::class_<XCAFDoc_GeomTolerance, opencascade::handle<XCAFDoc_GeomTolerance>, TDF_Attribute> cls_XCAFDoc_GeomTolerance(mod, "XCAFDoc_GeomTolerance", "Attribute to store dimension and tolerance");

// Constructors
cls_XCAFDoc_GeomTolerance.def(py::init<>());
// cls_XCAFDoc_GeomTolerance.def(py::init<const opencascade::handle<XCAFDoc_GeomTolerance> &>(), py::arg("theObj"));

// Fields

// Methods
cls_XCAFDoc_GeomTolerance.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_GeomTolerance::GetID, "None");
cls_XCAFDoc_GeomTolerance.def_static("Set_", (opencascade::handle<XCAFDoc_GeomTolerance> (*)(const TDF_Label &)) &XCAFDoc_GeomTolerance::Set, "None", py::arg("theLabel"));
cls_XCAFDoc_GeomTolerance.def("SetObject", (void (XCAFDoc_GeomTolerance::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDoc_GeomTolerance::SetObject, "Updates parent's label and its sub-labels with data taken from theGeomToleranceObject. Old data associated with the label will be lost.", py::arg("theGeomToleranceObject"));
cls_XCAFDoc_GeomTolerance.def("GetObject", (opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> (XCAFDoc_GeomTolerance::*)() const) &XCAFDoc_GeomTolerance::GetObject, "Returns geometry tolerance object data taken from the paren's label and its sub-labels.");
cls_XCAFDoc_GeomTolerance.def("ID", (const Standard_GUID & (XCAFDoc_GeomTolerance::*)() const) &XCAFDoc_GeomTolerance::ID, "None");
cls_XCAFDoc_GeomTolerance.def("Restore", (void (XCAFDoc_GeomTolerance::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_GeomTolerance::Restore, "None", py::arg("With"));
cls_XCAFDoc_GeomTolerance.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_GeomTolerance::*)() const) &XCAFDoc_GeomTolerance::NewEmpty, "None");
cls_XCAFDoc_GeomTolerance.def("Paste", (void (XCAFDoc_GeomTolerance::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_GeomTolerance::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_GeomTolerance.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_GeomTolerance::get_type_name, "None");
cls_XCAFDoc_GeomTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_GeomTolerance::get_type_descriptor, "None");
cls_XCAFDoc_GeomTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_GeomTolerance::*)() const) &XCAFDoc_GeomTolerance::DynamicType, "None");

// Enums

}