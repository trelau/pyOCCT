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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <MAT_Bisector.hxx>
#include <MAT_Edge.hxx>
#include <Standard_Type.hxx>

void bind_MAT_Edge(py::module &mod){

py::class_<MAT_Edge, opencascade::handle<MAT_Edge>, Standard_Transient> cls_MAT_Edge(mod, "MAT_Edge", "None");

// Constructors
cls_MAT_Edge.def(py::init<>());

// Fields

// Methods
cls_MAT_Edge.def("EdgeNumber", (void (MAT_Edge::*)(const Standard_Integer)) &MAT_Edge::EdgeNumber, "None", py::arg("anumber"));
cls_MAT_Edge.def("FirstBisector", (void (MAT_Edge::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_Edge::FirstBisector, "None", py::arg("abisector"));
cls_MAT_Edge.def("SecondBisector", (void (MAT_Edge::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_Edge::SecondBisector, "None", py::arg("abisector"));
cls_MAT_Edge.def("Distance", (void (MAT_Edge::*)(const Standard_Real)) &MAT_Edge::Distance, "None", py::arg("adistance"));
cls_MAT_Edge.def("IntersectionPoint", (void (MAT_Edge::*)(const Standard_Integer)) &MAT_Edge::IntersectionPoint, "None", py::arg("apoint"));
cls_MAT_Edge.def("EdgeNumber", (Standard_Integer (MAT_Edge::*)() const) &MAT_Edge::EdgeNumber, "None");
cls_MAT_Edge.def("FirstBisector", (opencascade::handle<MAT_Bisector> (MAT_Edge::*)() const) &MAT_Edge::FirstBisector, "None");
cls_MAT_Edge.def("SecondBisector", (opencascade::handle<MAT_Bisector> (MAT_Edge::*)() const) &MAT_Edge::SecondBisector, "None");
cls_MAT_Edge.def("Distance", (Standard_Real (MAT_Edge::*)() const) &MAT_Edge::Distance, "None");
cls_MAT_Edge.def("IntersectionPoint", (Standard_Integer (MAT_Edge::*)() const) &MAT_Edge::IntersectionPoint, "None");
cls_MAT_Edge.def("Dump", (void (MAT_Edge::*)(const Standard_Integer, const Standard_Integer) const) &MAT_Edge::Dump, "None", py::arg("ashift"), py::arg("alevel"));
cls_MAT_Edge.def_static("get_type_name_", (const char * (*)()) &MAT_Edge::get_type_name, "None");
cls_MAT_Edge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Edge::get_type_descriptor, "None");
cls_MAT_Edge.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Edge::*)() const) &MAT_Edge::DynamicType, "None");

// Enums

}