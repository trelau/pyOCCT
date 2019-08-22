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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_ListOfShape.hxx>
#include <LocOpe_FindEdges.hxx>

void bind_LocOpe_FindEdges(py::module &mod){

py::class_<LocOpe_FindEdges> cls_LocOpe_FindEdges(mod, "LocOpe_FindEdges", "None");

// Constructors
cls_LocOpe_FindEdges.def(py::init<>());
cls_LocOpe_FindEdges.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("FFrom"), py::arg("FTo"));

// Fields

// Methods
// cls_LocOpe_FindEdges.def_static("operator new_", (void * (*)(size_t)) &LocOpe_FindEdges::operator new, "None", py::arg("theSize"));
// cls_LocOpe_FindEdges.def_static("operator delete_", (void (*)(void *)) &LocOpe_FindEdges::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_FindEdges.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_FindEdges::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_FindEdges.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_FindEdges::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_FindEdges.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_FindEdges::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_FindEdges.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_FindEdges::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_FindEdges.def("Set", (void (LocOpe_FindEdges::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &LocOpe_FindEdges::Set, "None", py::arg("FFrom"), py::arg("FTo"));
cls_LocOpe_FindEdges.def("InitIterator", (void (LocOpe_FindEdges::*)()) &LocOpe_FindEdges::InitIterator, "None");
cls_LocOpe_FindEdges.def("More", (Standard_Boolean (LocOpe_FindEdges::*)() const) &LocOpe_FindEdges::More, "None");
cls_LocOpe_FindEdges.def("EdgeFrom", (const TopoDS_Edge & (LocOpe_FindEdges::*)() const) &LocOpe_FindEdges::EdgeFrom, "None");
cls_LocOpe_FindEdges.def("EdgeTo", (const TopoDS_Edge & (LocOpe_FindEdges::*)() const) &LocOpe_FindEdges::EdgeTo, "None");
cls_LocOpe_FindEdges.def("Next", (void (LocOpe_FindEdges::*)()) &LocOpe_FindEdges::Next, "None");

// Enums

}