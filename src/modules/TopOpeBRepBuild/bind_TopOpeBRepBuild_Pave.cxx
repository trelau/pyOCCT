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
#include <TopOpeBRepBuild_Loop.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_Pave.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRepBuild_Pave(py::module &mod){

py::class_<TopOpeBRepBuild_Pave, opencascade::handle<TopOpeBRepBuild_Pave>, TopOpeBRepBuild_Loop> cls_TopOpeBRepBuild_Pave(mod, "TopOpeBRepBuild_Pave", "None");

// Constructors
cls_TopOpeBRepBuild_Pave.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean>(), py::arg("V"), py::arg("P"), py::arg("bound"));

// Fields

// Methods
cls_TopOpeBRepBuild_Pave.def("HasSameDomain", (void (TopOpeBRepBuild_Pave::*)(const Standard_Boolean)) &TopOpeBRepBuild_Pave::HasSameDomain, "None", py::arg("b"));
cls_TopOpeBRepBuild_Pave.def("SameDomain", (void (TopOpeBRepBuild_Pave::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Pave::SameDomain, "None", py::arg("VSD"));
cls_TopOpeBRepBuild_Pave.def("HasSameDomain", (Standard_Boolean (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::HasSameDomain, "None");
cls_TopOpeBRepBuild_Pave.def("SameDomain", (const TopoDS_Shape & (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::SameDomain, "None");
cls_TopOpeBRepBuild_Pave.def("Vertex", (const TopoDS_Shape & (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::Vertex, "None");
cls_TopOpeBRepBuild_Pave.def("ChangeVertex", (TopoDS_Shape & (TopOpeBRepBuild_Pave::*)()) &TopOpeBRepBuild_Pave::ChangeVertex, "None");
cls_TopOpeBRepBuild_Pave.def("Parameter", (Standard_Real (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::Parameter, "None");
cls_TopOpeBRepBuild_Pave.def("Parameter", (void (TopOpeBRepBuild_Pave::*)(const Standard_Real)) &TopOpeBRepBuild_Pave::Parameter, "None", py::arg("Par"));
cls_TopOpeBRepBuild_Pave.def("InterferenceType", (TopOpeBRepDS_Kind & (TopOpeBRepBuild_Pave::*)()) &TopOpeBRepBuild_Pave::InterferenceType, "None");
cls_TopOpeBRepBuild_Pave.def("IsShape", (Standard_Boolean (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::IsShape, "None");
cls_TopOpeBRepBuild_Pave.def("Shape", (const TopoDS_Shape & (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::Shape, "None");
cls_TopOpeBRepBuild_Pave.def("Dump", (void (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::Dump, "None");
cls_TopOpeBRepBuild_Pave.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepBuild_Pave::get_type_name, "None");
cls_TopOpeBRepBuild_Pave.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepBuild_Pave::get_type_descriptor, "None");
cls_TopOpeBRepBuild_Pave.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::DynamicType, "None");

// Enums

}