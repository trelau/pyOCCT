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
#include <BRepFill_OffsetWire.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepFill_OffsetAncestors.hxx>

void bind_BRepFill_OffsetAncestors(py::module &mod){

py::class_<BRepFill_OffsetAncestors, std::unique_ptr<BRepFill_OffsetAncestors>> cls_BRepFill_OffsetAncestors(mod, "BRepFill_OffsetAncestors", "this class is used to find the generating shapes of an OffsetWire.");

// Constructors
cls_BRepFill_OffsetAncestors.def(py::init<>());
cls_BRepFill_OffsetAncestors.def(py::init<BRepFill_OffsetWire &>(), py::arg("Paral"));

// Fields

// Methods
// cls_BRepFill_OffsetAncestors.def_static("operator new_", (void * (*)(size_t)) &BRepFill_OffsetAncestors::operator new, "None", py::arg("theSize"));
// cls_BRepFill_OffsetAncestors.def_static("operator delete_", (void (*)(void *)) &BRepFill_OffsetAncestors::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_OffsetAncestors.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_OffsetAncestors::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_OffsetAncestors.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_OffsetAncestors::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_OffsetAncestors.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_OffsetAncestors::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_OffsetAncestors.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_OffsetAncestors::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_OffsetAncestors.def("Perform", (void (BRepFill_OffsetAncestors::*)(BRepFill_OffsetWire &)) &BRepFill_OffsetAncestors::Perform, "None", py::arg("Paral"));
cls_BRepFill_OffsetAncestors.def("IsDone", (Standard_Boolean (BRepFill_OffsetAncestors::*)() const) &BRepFill_OffsetAncestors::IsDone, "None");
cls_BRepFill_OffsetAncestors.def("HasAncestor", (Standard_Boolean (BRepFill_OffsetAncestors::*)(const TopoDS_Edge &) const) &BRepFill_OffsetAncestors::HasAncestor, "None", py::arg("S1"));
cls_BRepFill_OffsetAncestors.def("Ancestor", (const TopoDS_Shape & (BRepFill_OffsetAncestors::*)(const TopoDS_Edge &) const) &BRepFill_OffsetAncestors::Ancestor, "may return a Null Shape if S1 is not a subShape of <Paral>; if Perform is not done.", py::arg("S1"));

// Enums

}