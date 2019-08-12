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
#include <MAT_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <MAT_ListOfEdge.hxx>
#include <Standard_Type.hxx>
#include <MAT_TListNodeOfListOfEdge.hxx>

void bind_MAT_ListOfEdge(py::module &mod){

py::class_<MAT_ListOfEdge, opencascade::handle<MAT_ListOfEdge>, Standard_Transient> cls_MAT_ListOfEdge(mod, "MAT_ListOfEdge", "None");

// Constructors
cls_MAT_ListOfEdge.def(py::init<>());

// Fields

// Methods
cls_MAT_ListOfEdge.def("First", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::First, "None");
cls_MAT_ListOfEdge.def("Last", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::Last, "None");
cls_MAT_ListOfEdge.def("Init", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_ListOfEdge::Init, "None", py::arg("aniten"));
cls_MAT_ListOfEdge.def("Next", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::Next, "None");
cls_MAT_ListOfEdge.def("Previous", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::Previous, "None");
cls_MAT_ListOfEdge.def("More", (Standard_Boolean (MAT_ListOfEdge::*)() const) &MAT_ListOfEdge::More, "None");
cls_MAT_ListOfEdge.def("Current", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)() const) &MAT_ListOfEdge::Current, "None");
cls_MAT_ListOfEdge.def("Current", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &) const) &MAT_ListOfEdge::Current, "None", py::arg("anitem"));
cls_MAT_ListOfEdge.def("FirstItem", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)() const) &MAT_ListOfEdge::FirstItem, "None");
cls_MAT_ListOfEdge.def("LastItem", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)() const) &MAT_ListOfEdge::LastItem, "None");
cls_MAT_ListOfEdge.def("PreviousItem", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)() const) &MAT_ListOfEdge::PreviousItem, "None");
cls_MAT_ListOfEdge.def("NextItem", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)() const) &MAT_ListOfEdge::NextItem, "None");
cls_MAT_ListOfEdge.def("Number", (Standard_Integer (MAT_ListOfEdge::*)() const) &MAT_ListOfEdge::Number, "None");
cls_MAT_ListOfEdge.def("Index", (Standard_Integer (MAT_ListOfEdge::*)() const) &MAT_ListOfEdge::Index, "None");
cls_MAT_ListOfEdge.def("Brackets", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)(const Standard_Integer)) &MAT_ListOfEdge::Brackets, "None", py::arg("anindex"));
cls_MAT_ListOfEdge.def("__call__", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)(const Standard_Integer)) &MAT_ListOfEdge::operator(), py::is_operator(), "None", py::arg("anindex"));
cls_MAT_ListOfEdge.def("Unlink", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::Unlink, "None");
cls_MAT_ListOfEdge.def("LinkBefore", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_ListOfEdge::LinkBefore, "None", py::arg("anitem"));
cls_MAT_ListOfEdge.def("LinkAfter", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_ListOfEdge::LinkAfter, "None", py::arg("anitem"));
cls_MAT_ListOfEdge.def("FrontAdd", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_ListOfEdge::FrontAdd, "None", py::arg("anitem"));
cls_MAT_ListOfEdge.def("BackAdd", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_ListOfEdge::BackAdd, "None", py::arg("anitem"));
cls_MAT_ListOfEdge.def("Permute", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::Permute, "None");
cls_MAT_ListOfEdge.def("Loop", (void (MAT_ListOfEdge::*)() const) &MAT_ListOfEdge::Loop, "None");
cls_MAT_ListOfEdge.def("IsEmpty", (Standard_Boolean (MAT_ListOfEdge::*)() const) &MAT_ListOfEdge::IsEmpty, "None");
cls_MAT_ListOfEdge.def("Dump", (void (MAT_ListOfEdge::*)(const Standard_Integer, const Standard_Integer)) &MAT_ListOfEdge::Dump, "None", py::arg("ashift"), py::arg("alevel"));
cls_MAT_ListOfEdge.def_static("get_type_name_", (const char * (*)()) &MAT_ListOfEdge::get_type_name, "None");
cls_MAT_ListOfEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_ListOfEdge::get_type_descriptor, "None");
cls_MAT_ListOfEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_ListOfEdge::*)() const) &MAT_ListOfEdge::DynamicType, "None");

// Enums

}