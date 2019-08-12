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
#include <TopOpeBRepDS_Config.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_ShapeShapeInterference.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRepDS_ShapeShapeInterference(py::module &mod){

py::class_<TopOpeBRepDS_ShapeShapeInterference, opencascade::handle<TopOpeBRepDS_ShapeShapeInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_ShapeShapeInterference(mod, "TopOpeBRepDS_ShapeShapeInterference", "Interference");

// Constructors
cls_TopOpeBRepDS_ShapeShapeInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config>(), py::arg("T"), py::arg("ST"), py::arg("S"), py::arg("GT"), py::arg("G"), py::arg("GBound"), py::arg("C"));

// Fields

// Methods
cls_TopOpeBRepDS_ShapeShapeInterference.def("Config", (TopOpeBRepDS_Config (TopOpeBRepDS_ShapeShapeInterference::*)() const) &TopOpeBRepDS_ShapeShapeInterference::Config, "None");
cls_TopOpeBRepDS_ShapeShapeInterference.def("GBound", (Standard_Boolean (TopOpeBRepDS_ShapeShapeInterference::*)() const) &TopOpeBRepDS_ShapeShapeInterference::GBound, "None");
cls_TopOpeBRepDS_ShapeShapeInterference.def("SetGBound", (void (TopOpeBRepDS_ShapeShapeInterference::*)(const Standard_Boolean)) &TopOpeBRepDS_ShapeShapeInterference::SetGBound, "None", py::arg("b"));
cls_TopOpeBRepDS_ShapeShapeInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_ShapeShapeInterference::get_type_name, "None");
cls_TopOpeBRepDS_ShapeShapeInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_ShapeShapeInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_ShapeShapeInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_ShapeShapeInterference::*)() const) &TopOpeBRepDS_ShapeShapeInterference::DynamicType, "None");

// Enums

}