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
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepBuild_ShapeListOfShape.hxx>

void bind_TopOpeBRepBuild_ShapeListOfShape(py::module &mod){

py::class_<TopOpeBRepBuild_ShapeListOfShape, std::unique_ptr<TopOpeBRepBuild_ShapeListOfShape, Deleter<TopOpeBRepBuild_ShapeListOfShape>>> cls_TopOpeBRepBuild_ShapeListOfShape(mod, "TopOpeBRepBuild_ShapeListOfShape", "represent shape + a list of shape");

// Constructors
cls_TopOpeBRepBuild_ShapeListOfShape.def(py::init<>());
cls_TopOpeBRepBuild_ShapeListOfShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_TopOpeBRepBuild_ShapeListOfShape.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &>(), py::arg("S"), py::arg("L"));

// Fields

// Methods
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_ShapeListOfShape::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_ShapeListOfShape::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_ShapeListOfShape::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_ShapeListOfShape::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_ShapeListOfShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_ShapeListOfShape::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_ShapeListOfShape.def("List", (const TopTools_ListOfShape & (TopOpeBRepBuild_ShapeListOfShape::*)() const) &TopOpeBRepBuild_ShapeListOfShape::List, "None");
cls_TopOpeBRepBuild_ShapeListOfShape.def("ChangeList", (TopTools_ListOfShape & (TopOpeBRepBuild_ShapeListOfShape::*)()) &TopOpeBRepBuild_ShapeListOfShape::ChangeList, "None");
cls_TopOpeBRepBuild_ShapeListOfShape.def("Shape", (const TopoDS_Shape & (TopOpeBRepBuild_ShapeListOfShape::*)() const) &TopOpeBRepBuild_ShapeListOfShape::Shape, "None");
cls_TopOpeBRepBuild_ShapeListOfShape.def("ChangeShape", (TopoDS_Shape & (TopOpeBRepBuild_ShapeListOfShape::*)()) &TopOpeBRepBuild_ShapeListOfShape::ChangeShape, "None");

// Enums

}