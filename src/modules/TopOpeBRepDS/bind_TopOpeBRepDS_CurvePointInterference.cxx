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
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_CurvePointInterference.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRepDS_CurvePointInterference(py::module &mod){

py::class_<TopOpeBRepDS_CurvePointInterference, opencascade::handle<TopOpeBRepDS_CurvePointInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_CurvePointInterference(mod, "TopOpeBRepDS_CurvePointInterference", "An interference with a parameter.");

// Constructors
cls_TopOpeBRepDS_CurvePointInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Real>(), py::arg("T"), py::arg("ST"), py::arg("S"), py::arg("GT"), py::arg("G"), py::arg("P"));

// Fields

// Methods
cls_TopOpeBRepDS_CurvePointInterference.def("Parameter", (Standard_Real (TopOpeBRepDS_CurvePointInterference::*)() const) &TopOpeBRepDS_CurvePointInterference::Parameter, "None");
cls_TopOpeBRepDS_CurvePointInterference.def("Parameter", (void (TopOpeBRepDS_CurvePointInterference::*)(const Standard_Real)) &TopOpeBRepDS_CurvePointInterference::Parameter, "None", py::arg("P"));
cls_TopOpeBRepDS_CurvePointInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_CurvePointInterference::get_type_name, "None");
cls_TopOpeBRepDS_CurvePointInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_CurvePointInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_CurvePointInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_CurvePointInterference::*)() const) &TopOpeBRepDS_CurvePointInterference::DynamicType, "None");

// Enums

}