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
#include <Standard_Handle.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box2d.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <IntPatch_PolyArc.hxx>

void bind_IntPatch_PolyArc(py::module &mod){

py::class_<IntPatch_PolyArc, IntPatch_Polygo> cls_IntPatch_PolyArc(mod, "IntPatch_PolyArc", "None");

// Constructors
cls_IntPatch_PolyArc.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, const Standard_Real, const Standard_Real, const Bnd_Box2d &>(), py::arg("A"), py::arg("NbSample"), py::arg("Pfirst"), py::arg("Plast"), py::arg("BoxOtherPolygon"));

// Fields

// Methods
// cls_IntPatch_PolyArc.def_static("operator new_", (void * (*)(size_t)) &IntPatch_PolyArc::operator new, "None", py::arg("theSize"));
// cls_IntPatch_PolyArc.def_static("operator delete_", (void (*)(void *)) &IntPatch_PolyArc::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_PolyArc.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_PolyArc::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_PolyArc.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_PolyArc::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_PolyArc.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_PolyArc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_PolyArc.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_PolyArc::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_PolyArc.def("Closed", (Standard_Boolean (IntPatch_PolyArc::*)() const) &IntPatch_PolyArc::Closed, "None");
cls_IntPatch_PolyArc.def("NbPoints", (Standard_Integer (IntPatch_PolyArc::*)() const) &IntPatch_PolyArc::NbPoints, "None");
cls_IntPatch_PolyArc.def("Point", (gp_Pnt2d (IntPatch_PolyArc::*)(const Standard_Integer) const) &IntPatch_PolyArc::Point, "None", py::arg("Index"));
cls_IntPatch_PolyArc.def("Parameter", (Standard_Real (IntPatch_PolyArc::*)(const Standard_Integer) const) &IntPatch_PolyArc::Parameter, "None", py::arg("Index"));
cls_IntPatch_PolyArc.def("SetOffset", (void (IntPatch_PolyArc::*)(const Standard_Real, const Standard_Real)) &IntPatch_PolyArc::SetOffset, "None", py::arg("OffsetX"), py::arg("OffsetY"));

// Enums

}