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
#include <IntPatch_Polygo.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IntPatch_WLine.hxx>
#include <IntPatch_RLine.hxx>
#include <gp_Pnt2d.hxx>
#include <IntPatch_IType.hxx>
#include <IntPatch_PolyLine.hxx>

void bind_IntPatch_PolyLine(py::module &mod){

py::class_<IntPatch_PolyLine, std::unique_ptr<IntPatch_PolyLine, Deleter<IntPatch_PolyLine>>, IntPatch_Polygo> cls_IntPatch_PolyLine(mod, "IntPatch_PolyLine", "None");

// Constructors
cls_IntPatch_PolyLine.def(py::init<>());
cls_IntPatch_PolyLine.def(py::init<const Standard_Real>(), py::arg("InitDefle"));

// Fields

// Methods
// cls_IntPatch_PolyLine.def_static("operator new_", (void * (*)(size_t)) &IntPatch_PolyLine::operator new, "None", py::arg("theSize"));
// cls_IntPatch_PolyLine.def_static("operator delete_", (void (*)(void *)) &IntPatch_PolyLine::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_PolyLine.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_PolyLine::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_PolyLine.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_PolyLine::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_PolyLine.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_PolyLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_PolyLine.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_PolyLine::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_PolyLine.def("SetWLine", (void (IntPatch_PolyLine::*)(const Standard_Boolean, const opencascade::handle<IntPatch_WLine> &)) &IntPatch_PolyLine::SetWLine, "None", py::arg("OnFirst"), py::arg("Line"));
cls_IntPatch_PolyLine.def("SetRLine", (void (IntPatch_PolyLine::*)(const Standard_Boolean, const opencascade::handle<IntPatch_RLine> &)) &IntPatch_PolyLine::SetRLine, "None", py::arg("OnFirst"), py::arg("Line"));
cls_IntPatch_PolyLine.def("ResetError", (void (IntPatch_PolyLine::*)()) &IntPatch_PolyLine::ResetError, "None");
cls_IntPatch_PolyLine.def("NbPoints", (Standard_Integer (IntPatch_PolyLine::*)() const) &IntPatch_PolyLine::NbPoints, "None");
cls_IntPatch_PolyLine.def("Point", (gp_Pnt2d (IntPatch_PolyLine::*)(const Standard_Integer) const) &IntPatch_PolyLine::Point, "None", py::arg("Index"));

// Enums

}