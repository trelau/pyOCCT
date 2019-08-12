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
#include <Standard_TypeDef.hxx>
#include <MAT_ListOfBisector.hxx>
#include <Standard_Type.hxx>
#include <MAT_TListNodeOfListOfBisector.hxx>

void bind_MAT_ListOfBisector(py::module &mod){

py::class_<MAT_ListOfBisector, opencascade::handle<MAT_ListOfBisector>, Standard_Transient> cls_MAT_ListOfBisector(mod, "MAT_ListOfBisector", "None");

// Constructors
cls_MAT_ListOfBisector.def(py::init<>());

// Fields

// Methods
cls_MAT_ListOfBisector.def("First", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::First, "None");
cls_MAT_ListOfBisector.def("Last", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::Last, "None");
cls_MAT_ListOfBisector.def("Init", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_ListOfBisector::Init, "None", py::arg("aniten"));
cls_MAT_ListOfBisector.def("Next", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::Next, "None");
cls_MAT_ListOfBisector.def("Previous", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::Previous, "None");
cls_MAT_ListOfBisector.def("More", (Standard_Boolean (MAT_ListOfBisector::*)() const) &MAT_ListOfBisector::More, "None");
cls_MAT_ListOfBisector.def("Current", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)() const) &MAT_ListOfBisector::Current, "None");
cls_MAT_ListOfBisector.def("Current", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &) const) &MAT_ListOfBisector::Current, "None", py::arg("anitem"));
cls_MAT_ListOfBisector.def("FirstItem", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)() const) &MAT_ListOfBisector::FirstItem, "None");
cls_MAT_ListOfBisector.def("LastItem", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)() const) &MAT_ListOfBisector::LastItem, "None");
cls_MAT_ListOfBisector.def("PreviousItem", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)() const) &MAT_ListOfBisector::PreviousItem, "None");
cls_MAT_ListOfBisector.def("NextItem", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)() const) &MAT_ListOfBisector::NextItem, "None");
cls_MAT_ListOfBisector.def("Number", (Standard_Integer (MAT_ListOfBisector::*)() const) &MAT_ListOfBisector::Number, "None");
cls_MAT_ListOfBisector.def("Index", (Standard_Integer (MAT_ListOfBisector::*)() const) &MAT_ListOfBisector::Index, "None");
cls_MAT_ListOfBisector.def("Brackets", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)(const Standard_Integer)) &MAT_ListOfBisector::Brackets, "None", py::arg("anindex"));
cls_MAT_ListOfBisector.def("__call__", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)(const Standard_Integer)) &MAT_ListOfBisector::operator(), py::is_operator(), "None", py::arg("anindex"));
cls_MAT_ListOfBisector.def("Unlink", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::Unlink, "None");
cls_MAT_ListOfBisector.def("LinkBefore", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_ListOfBisector::LinkBefore, "None", py::arg("anitem"));
cls_MAT_ListOfBisector.def("LinkAfter", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_ListOfBisector::LinkAfter, "None", py::arg("anitem"));
cls_MAT_ListOfBisector.def("FrontAdd", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_ListOfBisector::FrontAdd, "None", py::arg("anitem"));
cls_MAT_ListOfBisector.def("BackAdd", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_ListOfBisector::BackAdd, "None", py::arg("anitem"));
cls_MAT_ListOfBisector.def("Permute", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::Permute, "None");
cls_MAT_ListOfBisector.def("Loop", (void (MAT_ListOfBisector::*)() const) &MAT_ListOfBisector::Loop, "None");
cls_MAT_ListOfBisector.def("IsEmpty", (Standard_Boolean (MAT_ListOfBisector::*)() const) &MAT_ListOfBisector::IsEmpty, "None");
cls_MAT_ListOfBisector.def("Dump", (void (MAT_ListOfBisector::*)(const Standard_Integer, const Standard_Integer)) &MAT_ListOfBisector::Dump, "None", py::arg("ashift"), py::arg("alevel"));
cls_MAT_ListOfBisector.def_static("get_type_name_", (const char * (*)()) &MAT_ListOfBisector::get_type_name, "None");
cls_MAT_ListOfBisector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_ListOfBisector::get_type_descriptor, "None");
cls_MAT_ListOfBisector.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_ListOfBisector::*)() const) &MAT_ListOfBisector::DynamicType, "None");

// Enums

}