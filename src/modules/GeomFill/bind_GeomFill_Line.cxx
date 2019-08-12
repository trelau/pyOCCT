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
#include <GeomFill_Line.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_Line(py::module &mod){

py::class_<GeomFill_Line, opencascade::handle<GeomFill_Line>, Standard_Transient> cls_GeomFill_Line(mod, "GeomFill_Line", "class for instantiation of AppBlend");

// Constructors
cls_GeomFill_Line.def(py::init<>());
cls_GeomFill_Line.def(py::init<const Standard_Integer>(), py::arg("NbPoints"));

// Fields

// Methods
cls_GeomFill_Line.def("NbPoints", (Standard_Integer (GeomFill_Line::*)() const) &GeomFill_Line::NbPoints, "None");
cls_GeomFill_Line.def("Point", (Standard_Integer (GeomFill_Line::*)(const Standard_Integer) const) &GeomFill_Line::Point, "None", py::arg("Index"));
cls_GeomFill_Line.def_static("get_type_name_", (const char * (*)()) &GeomFill_Line::get_type_name, "None");
cls_GeomFill_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_Line::get_type_descriptor, "None");
cls_GeomFill_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_Line::*)() const) &GeomFill_Line::DynamicType, "None");

// Enums

}