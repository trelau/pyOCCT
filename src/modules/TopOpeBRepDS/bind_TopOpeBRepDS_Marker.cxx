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
#include <TopOpeBRepDS_Marker.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfBoolean.hxx>

void bind_TopOpeBRepDS_Marker(py::module &mod){

py::class_<TopOpeBRepDS_Marker, opencascade::handle<TopOpeBRepDS_Marker>, Standard_Transient> cls_TopOpeBRepDS_Marker(mod, "TopOpeBRepDS_Marker", "None");

// Constructors
cls_TopOpeBRepDS_Marker.def(py::init<>());

// Fields

// Methods
cls_TopOpeBRepDS_Marker.def("Reset", (void (TopOpeBRepDS_Marker::*)()) &TopOpeBRepDS_Marker::Reset, "None");
cls_TopOpeBRepDS_Marker.def("Set", (void (TopOpeBRepDS_Marker::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_Marker::Set, "None", py::arg("i"), py::arg("b"));
cls_TopOpeBRepDS_Marker.def("Set", (void (TopOpeBRepDS_Marker::*)(const Standard_Boolean, const Standard_Integer, const Standard_Address)) &TopOpeBRepDS_Marker::Set, "None", py::arg("b"), py::arg("n"), py::arg("a"));
cls_TopOpeBRepDS_Marker.def("GetI", (Standard_Boolean (TopOpeBRepDS_Marker::*)(const Standard_Integer) const) &TopOpeBRepDS_Marker::GetI, "None", py::arg("i"));
cls_TopOpeBRepDS_Marker.def("Allocate", (void (TopOpeBRepDS_Marker::*)(const Standard_Integer)) &TopOpeBRepDS_Marker::Allocate, "None", py::arg("n"));
cls_TopOpeBRepDS_Marker.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Marker::get_type_name, "None");
cls_TopOpeBRepDS_Marker.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Marker::get_type_descriptor, "None");
cls_TopOpeBRepDS_Marker.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Marker::*)() const) &TopOpeBRepDS_Marker::DynamicType, "None");

// Enums

}