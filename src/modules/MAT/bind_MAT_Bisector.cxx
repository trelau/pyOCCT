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
#include <MAT_ListOfBisector.hxx>
#include <Standard_TypeDef.hxx>
#include <MAT_Edge.hxx>
#include <Standard_Type.hxx>

void bind_MAT_Bisector(py::module &mod){

py::class_<MAT_Bisector, opencascade::handle<MAT_Bisector>, Standard_Transient> cls_MAT_Bisector(mod, "MAT_Bisector", "None");

// Constructors
cls_MAT_Bisector.def(py::init<>());

// Fields

// Methods
cls_MAT_Bisector.def("AddBisector", (void (MAT_Bisector::*)(const opencascade::handle<MAT_Bisector> &) const) &MAT_Bisector::AddBisector, "None", py::arg("abisector"));
cls_MAT_Bisector.def("List", (opencascade::handle<MAT_ListOfBisector> (MAT_Bisector::*)() const) &MAT_Bisector::List, "None");
cls_MAT_Bisector.def("FirstBisector", (opencascade::handle<MAT_Bisector> (MAT_Bisector::*)() const) &MAT_Bisector::FirstBisector, "None");
cls_MAT_Bisector.def("LastBisector", (opencascade::handle<MAT_Bisector> (MAT_Bisector::*)() const) &MAT_Bisector::LastBisector, "None");
cls_MAT_Bisector.def("BisectorNumber", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::BisectorNumber, "None", py::arg("anumber"));
cls_MAT_Bisector.def("IndexNumber", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::IndexNumber, "None", py::arg("anumber"));
cls_MAT_Bisector.def("FirstEdge", (void (MAT_Bisector::*)(const opencascade::handle<MAT_Edge> &)) &MAT_Bisector::FirstEdge, "None", py::arg("anedge"));
cls_MAT_Bisector.def("SecondEdge", (void (MAT_Bisector::*)(const opencascade::handle<MAT_Edge> &)) &MAT_Bisector::SecondEdge, "None", py::arg("anedge"));
cls_MAT_Bisector.def("IssuePoint", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::IssuePoint, "None", py::arg("apoint"));
cls_MAT_Bisector.def("EndPoint", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::EndPoint, "None", py::arg("apoint"));
cls_MAT_Bisector.def("DistIssuePoint", (void (MAT_Bisector::*)(const Standard_Real)) &MAT_Bisector::DistIssuePoint, "None", py::arg("areal"));
cls_MAT_Bisector.def("FirstVector", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::FirstVector, "None", py::arg("avector"));
cls_MAT_Bisector.def("SecondVector", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::SecondVector, "None", py::arg("avector"));
cls_MAT_Bisector.def("Sense", (void (MAT_Bisector::*)(const Standard_Real)) &MAT_Bisector::Sense, "None", py::arg("asense"));
cls_MAT_Bisector.def("FirstParameter", (void (MAT_Bisector::*)(const Standard_Real)) &MAT_Bisector::FirstParameter, "None", py::arg("aparameter"));
cls_MAT_Bisector.def("SecondParameter", (void (MAT_Bisector::*)(const Standard_Real)) &MAT_Bisector::SecondParameter, "None", py::arg("aparameter"));
cls_MAT_Bisector.def("BisectorNumber", (Standard_Integer (MAT_Bisector::*)() const) &MAT_Bisector::BisectorNumber, "None");
cls_MAT_Bisector.def("IndexNumber", (Standard_Integer (MAT_Bisector::*)() const) &MAT_Bisector::IndexNumber, "None");
cls_MAT_Bisector.def("FirstEdge", (opencascade::handle<MAT_Edge> (MAT_Bisector::*)() const) &MAT_Bisector::FirstEdge, "None");
cls_MAT_Bisector.def("SecondEdge", (opencascade::handle<MAT_Edge> (MAT_Bisector::*)() const) &MAT_Bisector::SecondEdge, "None");
cls_MAT_Bisector.def("IssuePoint", (Standard_Integer (MAT_Bisector::*)() const) &MAT_Bisector::IssuePoint, "None");
cls_MAT_Bisector.def("EndPoint", (Standard_Integer (MAT_Bisector::*)() const) &MAT_Bisector::EndPoint, "None");
cls_MAT_Bisector.def("DistIssuePoint", (Standard_Real (MAT_Bisector::*)() const) &MAT_Bisector::DistIssuePoint, "None");
cls_MAT_Bisector.def("FirstVector", (Standard_Integer (MAT_Bisector::*)() const) &MAT_Bisector::FirstVector, "None");
cls_MAT_Bisector.def("SecondVector", (Standard_Integer (MAT_Bisector::*)() const) &MAT_Bisector::SecondVector, "None");
cls_MAT_Bisector.def("Sense", (Standard_Real (MAT_Bisector::*)() const) &MAT_Bisector::Sense, "None");
cls_MAT_Bisector.def("FirstParameter", (Standard_Real (MAT_Bisector::*)() const) &MAT_Bisector::FirstParameter, "None");
cls_MAT_Bisector.def("SecondParameter", (Standard_Real (MAT_Bisector::*)() const) &MAT_Bisector::SecondParameter, "None");
cls_MAT_Bisector.def("Dump", (void (MAT_Bisector::*)(const Standard_Integer, const Standard_Integer) const) &MAT_Bisector::Dump, "None", py::arg("ashift"), py::arg("alevel"));
cls_MAT_Bisector.def_static("get_type_name_", (const char * (*)()) &MAT_Bisector::get_type_name, "None");
cls_MAT_Bisector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Bisector::get_type_descriptor, "None");
cls_MAT_Bisector.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Bisector::*)() const) &MAT_Bisector::DynamicType, "None");

// Enums

}