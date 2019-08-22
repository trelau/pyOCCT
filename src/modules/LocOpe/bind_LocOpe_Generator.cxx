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
#include <LocOpe_GeneratedShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <LocOpe_Generator.hxx>

void bind_LocOpe_Generator(py::module &mod){

py::class_<LocOpe_Generator> cls_LocOpe_Generator(mod, "LocOpe_Generator", "None");

// Constructors
cls_LocOpe_Generator.def(py::init<>());
cls_LocOpe_Generator.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_LocOpe_Generator.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Generator::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Generator.def_static("operator delete_", (void (*)(void *)) &LocOpe_Generator::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Generator.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Generator::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Generator.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Generator::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Generator.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Generator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Generator.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Generator::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Generator.def("Init", (void (LocOpe_Generator::*)(const TopoDS_Shape &)) &LocOpe_Generator::Init, "Initializes the algorithm on the shape <S>.", py::arg("S"));
cls_LocOpe_Generator.def("Perform", (void (LocOpe_Generator::*)(const opencascade::handle<LocOpe_GeneratedShape> &)) &LocOpe_Generator::Perform, "None", py::arg("G"));
cls_LocOpe_Generator.def("IsDone", (Standard_Boolean (LocOpe_Generator::*)() const) &LocOpe_Generator::IsDone, "None");
cls_LocOpe_Generator.def("ResultingShape", (const TopoDS_Shape & (LocOpe_Generator::*)() const) &LocOpe_Generator::ResultingShape, "Returns the new shape");
cls_LocOpe_Generator.def("Shape", (const TopoDS_Shape & (LocOpe_Generator::*)() const) &LocOpe_Generator::Shape, "Returns the initial shape");
cls_LocOpe_Generator.def("DescendantFace", (const TopTools_ListOfShape & (LocOpe_Generator::*)(const TopoDS_Face &)) &LocOpe_Generator::DescendantFace, "Returns the descendant face of <F>. <F> may belong to the original shape or to the 'generated' shape. The returned face may be a null shape (when <F> disappears).", py::arg("F"));

// Enums

}