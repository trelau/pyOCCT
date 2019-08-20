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
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <TNaming_ShapesSet.hxx>
#include <TopTools_MapOfShape.hxx>

void bind_TNaming_ShapesSet(py::module &mod){

py::class_<TNaming_ShapesSet, std::unique_ptr<TNaming_ShapesSet>> cls_TNaming_ShapesSet(mod, "TNaming_ShapesSet", "None");

// Constructors
cls_TNaming_ShapesSet.def(py::init<>());
cls_TNaming_ShapesSet.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_TNaming_ShapesSet.def(py::init<const TopoDS_Shape &, const TopAbs_ShapeEnum>(), py::arg("S"), py::arg("Type"));

// Fields

// Methods
// cls_TNaming_ShapesSet.def_static("operator new_", (void * (*)(size_t)) &TNaming_ShapesSet::operator new, "None", py::arg("theSize"));
// cls_TNaming_ShapesSet.def_static("operator delete_", (void (*)(void *)) &TNaming_ShapesSet::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_ShapesSet.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_ShapesSet::operator new[], "None", py::arg("theSize"));
// cls_TNaming_ShapesSet.def_static("operator delete[]_", (void (*)(void *)) &TNaming_ShapesSet::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_ShapesSet.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_ShapesSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_ShapesSet.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_ShapesSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_ShapesSet.def("Clear", (void (TNaming_ShapesSet::*)()) &TNaming_ShapesSet::Clear, "Removes all Shapes");
cls_TNaming_ShapesSet.def("Add", (Standard_Boolean (TNaming_ShapesSet::*)(const TopoDS_Shape &)) &TNaming_ShapesSet::Add, "Adds the Shape <S>", py::arg("S"));
cls_TNaming_ShapesSet.def("Contains", (Standard_Boolean (TNaming_ShapesSet::*)(const TopoDS_Shape &) const) &TNaming_ShapesSet::Contains, "Returns True if <S> is in <me>", py::arg("S"));
cls_TNaming_ShapesSet.def("Remove", (Standard_Boolean (TNaming_ShapesSet::*)(const TopoDS_Shape &)) &TNaming_ShapesSet::Remove, "Removes <S> in <me>.", py::arg("S"));
cls_TNaming_ShapesSet.def("Add", (void (TNaming_ShapesSet::*)(const TNaming_ShapesSet &)) &TNaming_ShapesSet::Add, "Adds the shapes contained in <Shapes>.", py::arg("Shapes"));
cls_TNaming_ShapesSet.def("Filter", (void (TNaming_ShapesSet::*)(const TNaming_ShapesSet &)) &TNaming_ShapesSet::Filter, "Erases in <me> the shapes not contained in <Shapes>", py::arg("Shapes"));
cls_TNaming_ShapesSet.def("Remove", (void (TNaming_ShapesSet::*)(const TNaming_ShapesSet &)) &TNaming_ShapesSet::Remove, "Removes in <me> the shapes contained in <Shapes>", py::arg("Shapes"));
cls_TNaming_ShapesSet.def("IsEmpty", (Standard_Boolean (TNaming_ShapesSet::*)() const) &TNaming_ShapesSet::IsEmpty, "None");
cls_TNaming_ShapesSet.def("NbShapes", (Standard_Integer (TNaming_ShapesSet::*)() const) &TNaming_ShapesSet::NbShapes, "None");
cls_TNaming_ShapesSet.def("ChangeMap", (TopTools_MapOfShape & (TNaming_ShapesSet::*)()) &TNaming_ShapesSet::ChangeMap, "None");
cls_TNaming_ShapesSet.def("Map", (const TopTools_MapOfShape & (TNaming_ShapesSet::*)() const) &TNaming_ShapesSet::Map, "None");

// Enums

}