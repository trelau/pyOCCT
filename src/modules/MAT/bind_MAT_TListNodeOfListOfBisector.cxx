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
#include <MAT_Bisector.hxx>
#include <MAT_TListNodeOfListOfBisector.hxx>
#include <Standard_Type.hxx>

void bind_MAT_TListNodeOfListOfBisector(py::module &mod){

py::class_<MAT_TListNodeOfListOfBisector, opencascade::handle<MAT_TListNodeOfListOfBisector>, Standard_Transient> cls_MAT_TListNodeOfListOfBisector(mod, "MAT_TListNodeOfListOfBisector", "None");

// Constructors
cls_MAT_TListNodeOfListOfBisector.def(py::init<>());
cls_MAT_TListNodeOfListOfBisector.def(py::init<const opencascade::handle<MAT_Bisector> &>(), py::arg("anitem"));

// Fields

// Methods
cls_MAT_TListNodeOfListOfBisector.def("GetItem", (opencascade::handle<MAT_Bisector> (MAT_TListNodeOfListOfBisector::*)() const) &MAT_TListNodeOfListOfBisector::GetItem, "None");
cls_MAT_TListNodeOfListOfBisector.def("Next", (opencascade::handle<MAT_TListNodeOfListOfBisector> (MAT_TListNodeOfListOfBisector::*)() const) &MAT_TListNodeOfListOfBisector::Next, "None");
cls_MAT_TListNodeOfListOfBisector.def("Previous", (opencascade::handle<MAT_TListNodeOfListOfBisector> (MAT_TListNodeOfListOfBisector::*)() const) &MAT_TListNodeOfListOfBisector::Previous, "None");
cls_MAT_TListNodeOfListOfBisector.def("SetItem", (void (MAT_TListNodeOfListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_TListNodeOfListOfBisector::SetItem, "None", py::arg("anitem"));
cls_MAT_TListNodeOfListOfBisector.def("Next", (void (MAT_TListNodeOfListOfBisector::*)(const opencascade::handle<MAT_TListNodeOfListOfBisector> &)) &MAT_TListNodeOfListOfBisector::Next, "None", py::arg("atlistnode"));
cls_MAT_TListNodeOfListOfBisector.def("Previous", (void (MAT_TListNodeOfListOfBisector::*)(const opencascade::handle<MAT_TListNodeOfListOfBisector> &)) &MAT_TListNodeOfListOfBisector::Previous, "None", py::arg("atlistnode"));
cls_MAT_TListNodeOfListOfBisector.def("Dummy", (void (MAT_TListNodeOfListOfBisector::*)() const) &MAT_TListNodeOfListOfBisector::Dummy, "None");
cls_MAT_TListNodeOfListOfBisector.def_static("get_type_name_", (const char * (*)()) &MAT_TListNodeOfListOfBisector::get_type_name, "None");
cls_MAT_TListNodeOfListOfBisector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_TListNodeOfListOfBisector::get_type_descriptor, "None");
cls_MAT_TListNodeOfListOfBisector.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_TListNodeOfListOfBisector::*)() const) &MAT_TListNodeOfListOfBisector::DynamicType, "None");

// Enums

}