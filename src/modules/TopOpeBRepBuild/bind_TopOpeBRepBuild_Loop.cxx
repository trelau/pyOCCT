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
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepBuild_BlockIterator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_Loop.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRepBuild_Loop(py::module &mod){

py::class_<TopOpeBRepBuild_Loop, opencascade::handle<TopOpeBRepBuild_Loop>, Standard_Transient> cls_TopOpeBRepBuild_Loop(mod, "TopOpeBRepBuild_Loop", "a Loop is an existing shape (Shell,Wire) or a set of shapes (Faces,Edges) which are connex. a set of connex shape is represented by a BlockIterator");

// Constructors
cls_TopOpeBRepBuild_Loop.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_TopOpeBRepBuild_Loop.def(py::init<const TopOpeBRepBuild_BlockIterator &>(), py::arg("BI"));

// Fields

// Methods
cls_TopOpeBRepBuild_Loop.def("IsShape", (Standard_Boolean (TopOpeBRepBuild_Loop::*)() const) &TopOpeBRepBuild_Loop::IsShape, "None");
cls_TopOpeBRepBuild_Loop.def("Shape", (const TopoDS_Shape & (TopOpeBRepBuild_Loop::*)() const) &TopOpeBRepBuild_Loop::Shape, "None");
cls_TopOpeBRepBuild_Loop.def("BlockIterator", (const TopOpeBRepBuild_BlockIterator & (TopOpeBRepBuild_Loop::*)() const) &TopOpeBRepBuild_Loop::BlockIterator, "None");
cls_TopOpeBRepBuild_Loop.def("Dump", (void (TopOpeBRepBuild_Loop::*)() const) &TopOpeBRepBuild_Loop::Dump, "None");
cls_TopOpeBRepBuild_Loop.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepBuild_Loop::get_type_name, "None");
cls_TopOpeBRepBuild_Loop.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepBuild_Loop::get_type_descriptor, "None");
cls_TopOpeBRepBuild_Loop.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepBuild_Loop::*)() const) &TopOpeBRepBuild_Loop::DynamicType, "None");

// Enums

}