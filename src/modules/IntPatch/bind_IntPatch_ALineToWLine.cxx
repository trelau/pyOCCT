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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <IntPatch_ALine.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <gp_XYZ.hxx>
#include <IntSurf_Quadric.hxx>
#include <IntPatch_ALineToWLine.hxx>

void bind_IntPatch_ALineToWLine(py::module &mod){

py::class_<IntPatch_ALineToWLine, std::unique_ptr<IntPatch_ALineToWLine, Deleter<IntPatch_ALineToWLine>>> cls_IntPatch_ALineToWLine(mod, "IntPatch_ALineToWLine", "None");

// Constructors
cls_IntPatch_ALineToWLine.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("theS1"), py::arg("theS2"));
cls_IntPatch_ALineToWLine.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer>(), py::arg("theS1"), py::arg("theS2"), py::arg("theNbPoints"));

// Fields

// Methods
// cls_IntPatch_ALineToWLine.def_static("operator new_", (void * (*)(size_t)) &IntPatch_ALineToWLine::operator new, "None", py::arg("theSize"));
// cls_IntPatch_ALineToWLine.def_static("operator delete_", (void (*)(void *)) &IntPatch_ALineToWLine::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_ALineToWLine.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_ALineToWLine::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_ALineToWLine.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_ALineToWLine::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_ALineToWLine.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_ALineToWLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_ALineToWLine.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_ALineToWLine::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_ALineToWLine.def("SetTolOpenDomain", (void (IntPatch_ALineToWLine::*)(const Standard_Real)) &IntPatch_ALineToWLine::SetTolOpenDomain, "None", py::arg("aT"));
cls_IntPatch_ALineToWLine.def("TolOpenDomain", (Standard_Real (IntPatch_ALineToWLine::*)() const) &IntPatch_ALineToWLine::TolOpenDomain, "None");
cls_IntPatch_ALineToWLine.def("SetTolTransition", (void (IntPatch_ALineToWLine::*)(const Standard_Real)) &IntPatch_ALineToWLine::SetTolTransition, "None", py::arg("aT"));
cls_IntPatch_ALineToWLine.def("TolTransition", (Standard_Real (IntPatch_ALineToWLine::*)() const) &IntPatch_ALineToWLine::TolTransition, "None");
cls_IntPatch_ALineToWLine.def("SetTol3D", (void (IntPatch_ALineToWLine::*)(const Standard_Real)) &IntPatch_ALineToWLine::SetTol3D, "None", py::arg("aT"));
cls_IntPatch_ALineToWLine.def("Tol3D", (Standard_Real (IntPatch_ALineToWLine::*)() const) &IntPatch_ALineToWLine::Tol3D, "None");
cls_IntPatch_ALineToWLine.def("MakeWLine", (void (IntPatch_ALineToWLine::*)(const opencascade::handle<IntPatch_ALine> &, IntPatch_SequenceOfLine &) const) &IntPatch_ALineToWLine::MakeWLine, "Converts aline to the set of Walking-lines and adds them in theLines.", py::arg("aline"), py::arg("theLines"));
cls_IntPatch_ALineToWLine.def("MakeWLine", (void (IntPatch_ALineToWLine::*)(const opencascade::handle<IntPatch_ALine> &, const Standard_Real, const Standard_Real, IntPatch_SequenceOfLine &) const) &IntPatch_ALineToWLine::MakeWLine, "Converts aline (limitted by paraminf and paramsup) to the set of Walking-lines and adds them in theLines.", py::arg("aline"), py::arg("paraminf"), py::arg("paramsup"), py::arg("theLines"));

// Enums

}