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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_ListOfShape.hxx>
#include <LocOpe_FindEdgesInFace.hxx>

void bind_LocOpe_FindEdgesInFace(py::module &mod){

py::class_<LocOpe_FindEdgesInFace> cls_LocOpe_FindEdgesInFace(mod, "LocOpe_FindEdgesInFace", "None");

// Constructors
cls_LocOpe_FindEdgesInFace.def(py::init<>());
cls_LocOpe_FindEdgesInFace.def(py::init<const TopoDS_Shape &, const TopoDS_Face &>(), py::arg("S"), py::arg("F"));

// Fields

// Methods
// cls_LocOpe_FindEdgesInFace.def_static("operator new_", (void * (*)(size_t)) &LocOpe_FindEdgesInFace::operator new, "None", py::arg("theSize"));
// cls_LocOpe_FindEdgesInFace.def_static("operator delete_", (void (*)(void *)) &LocOpe_FindEdgesInFace::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_FindEdgesInFace.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_FindEdgesInFace::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_FindEdgesInFace.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_FindEdgesInFace::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_FindEdgesInFace.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_FindEdgesInFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_FindEdgesInFace.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_FindEdgesInFace::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_FindEdgesInFace.def("Set", (void (LocOpe_FindEdgesInFace::*)(const TopoDS_Shape &, const TopoDS_Face &)) &LocOpe_FindEdgesInFace::Set, "None", py::arg("S"), py::arg("F"));
cls_LocOpe_FindEdgesInFace.def("Init", (void (LocOpe_FindEdgesInFace::*)()) &LocOpe_FindEdgesInFace::Init, "None");
cls_LocOpe_FindEdgesInFace.def("More", (Standard_Boolean (LocOpe_FindEdgesInFace::*)() const) &LocOpe_FindEdgesInFace::More, "None");
cls_LocOpe_FindEdgesInFace.def("Edge", (const TopoDS_Edge & (LocOpe_FindEdgesInFace::*)() const) &LocOpe_FindEdgesInFace::Edge, "None");
cls_LocOpe_FindEdgesInFace.def("Next", (void (LocOpe_FindEdgesInFace::*)()) &LocOpe_FindEdgesInFace::Next, "None");

// Enums

}