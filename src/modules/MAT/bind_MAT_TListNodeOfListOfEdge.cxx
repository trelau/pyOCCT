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
#include <MAT_TListNodeOfListOfEdge.hxx>
#include <Standard_Type.hxx>

void bind_MAT_TListNodeOfListOfEdge(py::module &mod){

py::class_<MAT_TListNodeOfListOfEdge, opencascade::handle<MAT_TListNodeOfListOfEdge>, Standard_Transient> cls_MAT_TListNodeOfListOfEdge(mod, "MAT_TListNodeOfListOfEdge", "None");

// Constructors
cls_MAT_TListNodeOfListOfEdge.def(py::init<>());
cls_MAT_TListNodeOfListOfEdge.def(py::init<const opencascade::handle<MAT_Edge> &>(), py::arg("anitem"));

// Fields

// Methods
cls_MAT_TListNodeOfListOfEdge.def("GetItem", (opencascade::handle<MAT_Edge> (MAT_TListNodeOfListOfEdge::*)() const) &MAT_TListNodeOfListOfEdge::GetItem, "None");
cls_MAT_TListNodeOfListOfEdge.def("Next", (opencascade::handle<MAT_TListNodeOfListOfEdge> (MAT_TListNodeOfListOfEdge::*)() const) &MAT_TListNodeOfListOfEdge::Next, "None");
cls_MAT_TListNodeOfListOfEdge.def("Previous", (opencascade::handle<MAT_TListNodeOfListOfEdge> (MAT_TListNodeOfListOfEdge::*)() const) &MAT_TListNodeOfListOfEdge::Previous, "None");
cls_MAT_TListNodeOfListOfEdge.def("SetItem", (void (MAT_TListNodeOfListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_TListNodeOfListOfEdge::SetItem, "None", py::arg("anitem"));
cls_MAT_TListNodeOfListOfEdge.def("Next", (void (MAT_TListNodeOfListOfEdge::*)(const opencascade::handle<MAT_TListNodeOfListOfEdge> &)) &MAT_TListNodeOfListOfEdge::Next, "None", py::arg("atlistnode"));
cls_MAT_TListNodeOfListOfEdge.def("Previous", (void (MAT_TListNodeOfListOfEdge::*)(const opencascade::handle<MAT_TListNodeOfListOfEdge> &)) &MAT_TListNodeOfListOfEdge::Previous, "None", py::arg("atlistnode"));
cls_MAT_TListNodeOfListOfEdge.def("Dummy", (void (MAT_TListNodeOfListOfEdge::*)() const) &MAT_TListNodeOfListOfEdge::Dummy, "None");
cls_MAT_TListNodeOfListOfEdge.def_static("get_type_name_", (const char * (*)()) &MAT_TListNodeOfListOfEdge::get_type_name, "None");
cls_MAT_TListNodeOfListOfEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_TListNodeOfListOfEdge::get_type_descriptor, "None");
cls_MAT_TListNodeOfListOfEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_TListNodeOfListOfEdge::*)() const) &MAT_TListNodeOfListOfEdge::DynamicType, "None");

// Enums

}