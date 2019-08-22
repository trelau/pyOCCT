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
#include <gp_Pnt2d.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <Extrema_LocEPCOfLocateExtPC2d.hxx>
#include <Extrema_ELPCOfLocateExtPC2d.hxx>
#include <GeomAbs_CurveType.hxx>
#include <Extrema_LocateExtPC2d.hxx>

void bind_Extrema_LocateExtPC2d(py::module &mod){

py::class_<Extrema_LocateExtPC2d> cls_Extrema_LocateExtPC2d(mod, "Extrema_LocateExtPC2d", "None");

// Constructors
cls_Extrema_LocateExtPC2d.def(py::init<>());
cls_Extrema_LocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("TolF"));
cls_Extrema_LocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("Umin"), py::arg("Usup"), py::arg("TolF"));

// Fields

// Methods
// cls_Extrema_LocateExtPC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocateExtPC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocateExtPC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_LocateExtPC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocateExtPC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocateExtPC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocateExtPC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocateExtPC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocateExtPC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocateExtPC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocateExtPC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocateExtPC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocateExtPC2d.def("Initialize", (void (Extrema_LocateExtPC2d::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_LocateExtPC2d::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("Umin"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_LocateExtPC2d.def("Perform", (void (Extrema_LocateExtPC2d::*)(const gp_Pnt2d &, const Standard_Real)) &Extrema_LocateExtPC2d::Perform, "None", py::arg("P"), py::arg("U0"));
cls_Extrema_LocateExtPC2d.def("IsDone", (Standard_Boolean (Extrema_LocateExtPC2d::*)() const) &Extrema_LocateExtPC2d::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocateExtPC2d.def("SquareDistance", (Standard_Real (Extrema_LocateExtPC2d::*)() const) &Extrema_LocateExtPC2d::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocateExtPC2d.def("IsMin", (Standard_Boolean (Extrema_LocateExtPC2d::*)() const) &Extrema_LocateExtPC2d::IsMin, "Returns True if the extremum distance is a minimum.");
cls_Extrema_LocateExtPC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_LocateExtPC2d::*)() const) &Extrema_LocateExtPC2d::Point, "Returns the point of the extremum distance.");

// Enums

}