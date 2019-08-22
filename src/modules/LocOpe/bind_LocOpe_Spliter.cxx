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
#include <Standard_Handle.hxx>
#include <LocOpe_WiresOnShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <LocOpe_Spliter.hxx>

void bind_LocOpe_Spliter(py::module &mod){

py::class_<LocOpe_Spliter> cls_LocOpe_Spliter(mod, "LocOpe_Spliter", "None");

// Constructors
cls_LocOpe_Spliter.def(py::init<>());
cls_LocOpe_Spliter.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_LocOpe_Spliter.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Spliter::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Spliter.def_static("operator delete_", (void (*)(void *)) &LocOpe_Spliter::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Spliter.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Spliter::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Spliter.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Spliter::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Spliter.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Spliter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Spliter.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Spliter::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Spliter.def("Init", (void (LocOpe_Spliter::*)(const TopoDS_Shape &)) &LocOpe_Spliter::Init, "Initializes the algorithm on the shape <S>.", py::arg("S"));
cls_LocOpe_Spliter.def("Perform", (void (LocOpe_Spliter::*)(const opencascade::handle<LocOpe_WiresOnShape> &)) &LocOpe_Spliter::Perform, "None", py::arg("PW"));
cls_LocOpe_Spliter.def("IsDone", (Standard_Boolean (LocOpe_Spliter::*)() const) &LocOpe_Spliter::IsDone, "None");
cls_LocOpe_Spliter.def("ResultingShape", (const TopoDS_Shape & (LocOpe_Spliter::*)() const) &LocOpe_Spliter::ResultingShape, "Returns the new shape");
cls_LocOpe_Spliter.def("Shape", (const TopoDS_Shape & (LocOpe_Spliter::*)() const) &LocOpe_Spliter::Shape, "Returns the initial shape");
cls_LocOpe_Spliter.def("DirectLeft", (const TopTools_ListOfShape & (LocOpe_Spliter::*)() const) &LocOpe_Spliter::DirectLeft, "Returns the faces which are the left of the projected wires and which are");
cls_LocOpe_Spliter.def("Left", (const TopTools_ListOfShape & (LocOpe_Spliter::*)() const) &LocOpe_Spliter::Left, "Returns the faces of the 'left' part on the shape. (It is build from DirectLeft, with the faces connected to this set, and so on...).");
cls_LocOpe_Spliter.def("DescendantShapes", (const TopTools_ListOfShape & (LocOpe_Spliter::*)(const TopoDS_Shape &)) &LocOpe_Spliter::DescendantShapes, "Returns the list of descendant shapes of <S>.", py::arg("S"));

// Enums

}