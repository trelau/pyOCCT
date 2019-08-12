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
#include <IntCurve_IConicTool.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Ax22d.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Trsf2d.hxx>

void bind_IntCurve_IConicTool(py::module &mod){

py::class_<IntCurve_IConicTool, std::unique_ptr<IntCurve_IConicTool, Deleter<IntCurve_IConicTool>>> cls_IntCurve_IConicTool(mod, "IntCurve_IConicTool", "Implementation of the ImpTool from IntImpParGen for conics of gp.");

// Constructors
cls_IntCurve_IConicTool.def(py::init<>());
cls_IntCurve_IConicTool.def(py::init<const IntCurve_IConicTool &>(), py::arg("IT"));
cls_IntCurve_IConicTool.def(py::init<const gp_Elips2d &>(), py::arg("E"));
cls_IntCurve_IConicTool.def(py::init<const gp_Lin2d &>(), py::arg("L"));
cls_IntCurve_IConicTool.def(py::init<const gp_Circ2d &>(), py::arg("C"));
cls_IntCurve_IConicTool.def(py::init<const gp_Parab2d &>(), py::arg("P"));
cls_IntCurve_IConicTool.def(py::init<const gp_Hypr2d &>(), py::arg("H"));

// Fields

// Methods
// cls_IntCurve_IConicTool.def_static("operator new_", (void * (*)(size_t)) &IntCurve_IConicTool::operator new, "None", py::arg("theSize"));
// cls_IntCurve_IConicTool.def_static("operator delete_", (void (*)(void *)) &IntCurve_IConicTool::operator delete, "None", py::arg("theAddress"));
// cls_IntCurve_IConicTool.def_static("operator new[]_", (void * (*)(size_t)) &IntCurve_IConicTool::operator new[], "None", py::arg("theSize"));
// cls_IntCurve_IConicTool.def_static("operator delete[]_", (void (*)(void *)) &IntCurve_IConicTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurve_IConicTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurve_IConicTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurve_IConicTool.def_static("operator delete_", (void (*)(void *, void *)) &IntCurve_IConicTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurve_IConicTool.def("Value", (gp_Pnt2d (IntCurve_IConicTool::*)(const Standard_Real) const) &IntCurve_IConicTool::Value, "None", py::arg("X"));
cls_IntCurve_IConicTool.def("D1", (void (IntCurve_IConicTool::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &IntCurve_IConicTool::D1, "None", py::arg("U"), py::arg("P"), py::arg("T"));
cls_IntCurve_IConicTool.def("D2", (void (IntCurve_IConicTool::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &IntCurve_IConicTool::D2, "None", py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"));
cls_IntCurve_IConicTool.def("Distance", (Standard_Real (IntCurve_IConicTool::*)(const gp_Pnt2d &) const) &IntCurve_IConicTool::Distance, "Computes the value of the signed distance between the point P and the implicit curve.", py::arg("P"));
cls_IntCurve_IConicTool.def("GradDistance", (gp_Vec2d (IntCurve_IConicTool::*)(const gp_Pnt2d &) const) &IntCurve_IConicTool::GradDistance, "Computes the Gradient of the Signed Distance between a point and the implicit curve, at the point P.", py::arg("P"));
cls_IntCurve_IConicTool.def("FindParameter", (Standard_Real (IntCurve_IConicTool::*)(const gp_Pnt2d &) const) &IntCurve_IConicTool::FindParameter, "Returns the parameter U of the point on the implicit curve corresponding to the point P. The correspondance between P and the point P(U) on the implicit curve must be coherent with the way of determination of the signed distance.", py::arg("P"));

// Enums

}