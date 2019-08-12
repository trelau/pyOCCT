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
#include <Adaptor2d_HCurve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_Transition.hxx>
#include <BRepBlend_PointOnRst.hxx>

void bind_BRepBlend_PointOnRst(py::module &mod){

py::class_<BRepBlend_PointOnRst, std::unique_ptr<BRepBlend_PointOnRst, Deleter<BRepBlend_PointOnRst>>> cls_BRepBlend_PointOnRst(mod, "BRepBlend_PointOnRst", "Definition of an intersection point between a line and a restriction on a surface. Such a point is contains geometrical informations (see the Value method) and logical informations.");

// Constructors
cls_BRepBlend_PointOnRst.def(py::init<>());
cls_BRepBlend_PointOnRst.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const IntSurf_Transition &, const IntSurf_Transition &>(), py::arg("A"), py::arg("Param"), py::arg("TLine"), py::arg("TArc"));

// Fields

// Methods
// cls_BRepBlend_PointOnRst.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_PointOnRst::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_PointOnRst.def_static("operator delete_", (void (*)(void *)) &BRepBlend_PointOnRst::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_PointOnRst.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_PointOnRst::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_PointOnRst.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_PointOnRst::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_PointOnRst.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_PointOnRst::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_PointOnRst.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_PointOnRst::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_PointOnRst.def("SetArc", (void (BRepBlend_PointOnRst::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const IntSurf_Transition &, const IntSurf_Transition &)) &BRepBlend_PointOnRst::SetArc, "Sets the values of a point which is on the arc A, at parameter Param.", py::arg("A"), py::arg("Param"), py::arg("TLine"), py::arg("TArc"));
cls_BRepBlend_PointOnRst.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (BRepBlend_PointOnRst::*)() const) &BRepBlend_PointOnRst::Arc, "Returns the arc of restriction containing the vertex.");
cls_BRepBlend_PointOnRst.def("TransitionOnLine", (const IntSurf_Transition & (BRepBlend_PointOnRst::*)() const) &BRepBlend_PointOnRst::TransitionOnLine, "Returns the transition of the point on the line on surface.");
cls_BRepBlend_PointOnRst.def("TransitionOnArc", (const IntSurf_Transition & (BRepBlend_PointOnRst::*)() const) &BRepBlend_PointOnRst::TransitionOnArc, "Returns the transition of the point on the arc returned by Arc().");
cls_BRepBlend_PointOnRst.def("ParameterOnArc", (Standard_Real (BRepBlend_PointOnRst::*)() const) &BRepBlend_PointOnRst::ParameterOnArc, "Returns the parameter of the point on the arc returned by the method Arc().");

// Enums

}