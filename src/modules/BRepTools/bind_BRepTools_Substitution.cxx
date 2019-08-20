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
#include <Standard_TypeDef.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepTools_Substitution.hxx>

void bind_BRepTools_Substitution(py::module &mod){

py::class_<BRepTools_Substitution, std::unique_ptr<BRepTools_Substitution>> cls_BRepTools_Substitution(mod, "BRepTools_Substitution", "A tool to substitute subshapes by other shapes.");

// Constructors
cls_BRepTools_Substitution.def(py::init<>());

// Fields

// Methods
// cls_BRepTools_Substitution.def_static("operator new_", (void * (*)(size_t)) &BRepTools_Substitution::operator new, "None", py::arg("theSize"));
// cls_BRepTools_Substitution.def_static("operator delete_", (void (*)(void *)) &BRepTools_Substitution::operator delete, "None", py::arg("theAddress"));
// cls_BRepTools_Substitution.def_static("operator new[]_", (void * (*)(size_t)) &BRepTools_Substitution::operator new[], "None", py::arg("theSize"));
// cls_BRepTools_Substitution.def_static("operator delete[]_", (void (*)(void *)) &BRepTools_Substitution::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTools_Substitution.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTools_Substitution::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTools_Substitution.def_static("operator delete_", (void (*)(void *, void *)) &BRepTools_Substitution::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTools_Substitution.def("Clear", (void (BRepTools_Substitution::*)()) &BRepTools_Substitution::Clear, "Reset all the fields.");
cls_BRepTools_Substitution.def("Substitute", (void (BRepTools_Substitution::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepTools_Substitution::Substitute, "<Oldshape> will be replaced by <NewShapes>.", py::arg("OldShape"), py::arg("NewShapes"));
cls_BRepTools_Substitution.def("Build", (void (BRepTools_Substitution::*)(const TopoDS_Shape &)) &BRepTools_Substitution::Build, "Build NewShape from <S> if its subshapes has modified.", py::arg("S"));
cls_BRepTools_Substitution.def("IsCopied", (Standard_Boolean (BRepTools_Substitution::*)(const TopoDS_Shape &) const) &BRepTools_Substitution::IsCopied, "Returns True if <S> has been replaced .", py::arg("S"));
cls_BRepTools_Substitution.def("Copy", (const TopTools_ListOfShape & (BRepTools_Substitution::*)(const TopoDS_Shape &) const) &BRepTools_Substitution::Copy, "Returns the set of shapes substitued to <S> .", py::arg("S"));

// Enums

}