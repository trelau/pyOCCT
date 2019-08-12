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
#include <TopoDS_Vertex.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepFill_Section.hxx>

void bind_BRepFill_Section(py::module &mod){

py::class_<BRepFill_Section, std::unique_ptr<BRepFill_Section, Deleter<BRepFill_Section>>> cls_BRepFill_Section(mod, "BRepFill_Section", "To store section definition");

// Constructors
cls_BRepFill_Section.def(py::init<>());
cls_BRepFill_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Vertex &, const Standard_Boolean, const Standard_Boolean>(), py::arg("Profile"), py::arg("V"), py::arg("WithContact"), py::arg("WithCorrection"));

// Fields

// Methods
// cls_BRepFill_Section.def_static("operator new_", (void * (*)(size_t)) &BRepFill_Section::operator new, "None", py::arg("theSize"));
// cls_BRepFill_Section.def_static("operator delete_", (void (*)(void *)) &BRepFill_Section::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_Section.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_Section::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_Section.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_Section::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_Section.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_Section::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_Section.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_Section::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_Section.def("Set", (void (BRepFill_Section::*)(const Standard_Boolean)) &BRepFill_Section::Set, "None", py::arg("IsLaw"));
cls_BRepFill_Section.def("OriginalShape", (const TopoDS_Shape & (BRepFill_Section::*)() const) &BRepFill_Section::OriginalShape, "None");
cls_BRepFill_Section.def("Wire", (const TopoDS_Wire & (BRepFill_Section::*)() const) &BRepFill_Section::Wire, "None");
cls_BRepFill_Section.def("Vertex", (const TopoDS_Vertex & (BRepFill_Section::*)() const) &BRepFill_Section::Vertex, "None");
cls_BRepFill_Section.def("ModifiedShape", (TopoDS_Shape (BRepFill_Section::*)(const TopoDS_Shape &) const) &BRepFill_Section::ModifiedShape, "None", py::arg("theShape"));
cls_BRepFill_Section.def("IsLaw", (Standard_Boolean (BRepFill_Section::*)() const) &BRepFill_Section::IsLaw, "None");
cls_BRepFill_Section.def("IsPunctual", (Standard_Boolean (BRepFill_Section::*)() const) &BRepFill_Section::IsPunctual, "None");
cls_BRepFill_Section.def("WithContact", (Standard_Boolean (BRepFill_Section::*)() const) &BRepFill_Section::WithContact, "None");
cls_BRepFill_Section.def("WithCorrection", (Standard_Boolean (BRepFill_Section::*)() const) &BRepFill_Section::WithCorrection, "None");

// Enums

}