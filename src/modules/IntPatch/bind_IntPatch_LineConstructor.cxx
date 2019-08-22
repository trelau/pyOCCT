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
#include <Standard_TypeDef.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <Standard_Handle.hxx>
#include <IntPatch_Line.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <IntPatch_LineConstructor.hxx>

void bind_IntPatch_LineConstructor(py::module &mod){

py::class_<IntPatch_LineConstructor> cls_IntPatch_LineConstructor(mod, "IntPatch_LineConstructor", "The intersections algorithms compute the intersection on two surfaces and return the intersections lines as IntPatch_Line.");

// Constructors
cls_IntPatch_LineConstructor.def(py::init<const Standard_Integer>(), py::arg("mode"));

// Fields

// Methods
// cls_IntPatch_LineConstructor.def_static("operator new_", (void * (*)(size_t)) &IntPatch_LineConstructor::operator new, "None", py::arg("theSize"));
// cls_IntPatch_LineConstructor.def_static("operator delete_", (void (*)(void *)) &IntPatch_LineConstructor::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_LineConstructor.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_LineConstructor::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_LineConstructor.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_LineConstructor::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_LineConstructor.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_LineConstructor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_LineConstructor.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_LineConstructor::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_LineConstructor.def("Perform", (void (IntPatch_LineConstructor::*)(const IntPatch_SequenceOfLine &, const opencascade::handle<IntPatch_Line> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real)) &IntPatch_LineConstructor::Perform, "None", py::arg("SL"), py::arg("L"), py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("Tol"));
cls_IntPatch_LineConstructor.def("NbLines", (Standard_Integer (IntPatch_LineConstructor::*)() const) &IntPatch_LineConstructor::NbLines, "None");
cls_IntPatch_LineConstructor.def("Line", (opencascade::handle<IntPatch_Line> (IntPatch_LineConstructor::*)(const Standard_Integer) const) &IntPatch_LineConstructor::Line, "None", py::arg("index"));

// Enums

}