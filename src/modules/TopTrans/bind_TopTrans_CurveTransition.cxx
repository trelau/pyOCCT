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
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopAbs_State.hxx>
#include <TopTrans_CurveTransition.hxx>

void bind_TopTrans_CurveTransition(py::module &mod){

py::class_<TopTrans_CurveTransition> cls_TopTrans_CurveTransition(mod, "TopTrans_CurveTransition", "This algorithm is used to compute the transition of a Curve intersecting a curvilinear boundary.");

// Constructors
cls_TopTrans_CurveTransition.def(py::init<>());

// Fields

// Methods
// cls_TopTrans_CurveTransition.def_static("operator new_", (void * (*)(size_t)) &TopTrans_CurveTransition::operator new, "None", py::arg("theSize"));
// cls_TopTrans_CurveTransition.def_static("operator delete_", (void (*)(void *)) &TopTrans_CurveTransition::operator delete, "None", py::arg("theAddress"));
// cls_TopTrans_CurveTransition.def_static("operator new[]_", (void * (*)(size_t)) &TopTrans_CurveTransition::operator new[], "None", py::arg("theSize"));
// cls_TopTrans_CurveTransition.def_static("operator delete[]_", (void (*)(void *)) &TopTrans_CurveTransition::operator delete[], "None", py::arg("theAddress"));
// cls_TopTrans_CurveTransition.def_static("operator new_", (void * (*)(size_t, void *)) &TopTrans_CurveTransition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTrans_CurveTransition.def_static("operator delete_", (void (*)(void *, void *)) &TopTrans_CurveTransition::operator delete, "None", py::arg(""), py::arg(""));
cls_TopTrans_CurveTransition.def("Reset", (void (TopTrans_CurveTransition::*)(const gp_Dir &, const gp_Dir &, const Standard_Real)) &TopTrans_CurveTransition::Reset, "Initialize a Transition with the local description of a Curve.", py::arg("Tgt"), py::arg("Norm"), py::arg("Curv"));
cls_TopTrans_CurveTransition.def("Reset", (void (TopTrans_CurveTransition::*)(const gp_Dir &)) &TopTrans_CurveTransition::Reset, "Initialize a Transition with the local description of a straigth line.", py::arg("Tgt"));
cls_TopTrans_CurveTransition.def("Compare", (void (TopTrans_CurveTransition::*)(const Standard_Real, const gp_Dir &, const gp_Dir &, const Standard_Real, const TopAbs_Orientation, const TopAbs_Orientation)) &TopTrans_CurveTransition::Compare, "Add a curve element to the boundary. If Or is REVERSED the curve is before the intersection, else if Or is FORWARD the curv is after the intersection and if Or is INTERNAL the intersection is in the middle of the curv.", py::arg("Tole"), py::arg("Tang"), py::arg("Norm"), py::arg("Curv"), py::arg("S"), py::arg("Or"));
cls_TopTrans_CurveTransition.def("StateBefore", (TopAbs_State (TopTrans_CurveTransition::*)() const) &TopTrans_CurveTransition::StateBefore, "returns the state of the curve before the intersection, this is the position relative to the boundary of a point very close to the intersection on the negative side of the tangent.");
cls_TopTrans_CurveTransition.def("StateAfter", (TopAbs_State (TopTrans_CurveTransition::*)() const) &TopTrans_CurveTransition::StateAfter, "returns the state of the curve after the intersection, this is the position relative to the boundary of a point very close to the intersection on the positive side of the tangent.");

// Enums

}