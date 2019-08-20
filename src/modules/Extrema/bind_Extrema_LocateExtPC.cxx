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
#include <gp_Pnt.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv.hxx>
#include <Extrema_LocEPCOfLocateExtPC.hxx>
#include <Extrema_ELPCOfLocateExtPC.hxx>
#include <GeomAbs_CurveType.hxx>
#include <Extrema_LocateExtPC.hxx>

void bind_Extrema_LocateExtPC(py::module &mod){

py::class_<Extrema_LocateExtPC, std::unique_ptr<Extrema_LocateExtPC>> cls_Extrema_LocateExtPC(mod, "Extrema_LocateExtPC", "None");

// Constructors
cls_Extrema_LocateExtPC.def(py::init<>());
cls_Extrema_LocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("TolF"));
cls_Extrema_LocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("Umin"), py::arg("Usup"), py::arg("TolF"));

// Fields

// Methods
// cls_Extrema_LocateExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocateExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocateExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_LocateExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocateExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocateExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocateExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocateExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocateExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocateExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocateExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocateExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocateExtPC.def("Initialize", (void (Extrema_LocateExtPC::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_LocateExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("Umin"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_LocateExtPC.def("Perform", (void (Extrema_LocateExtPC::*)(const gp_Pnt &, const Standard_Real)) &Extrema_LocateExtPC::Perform, "None", py::arg("P"), py::arg("U0"));
cls_Extrema_LocateExtPC.def("IsDone", (Standard_Boolean (Extrema_LocateExtPC::*)() const) &Extrema_LocateExtPC::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocateExtPC.def("SquareDistance", (Standard_Real (Extrema_LocateExtPC::*)() const) &Extrema_LocateExtPC::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocateExtPC.def("IsMin", (Standard_Boolean (Extrema_LocateExtPC::*)() const) &Extrema_LocateExtPC::IsMin, "Returns True if the extremum distance is a minimum.");
cls_Extrema_LocateExtPC.def("Point", (const Extrema_POnCurv & (Extrema_LocateExtPC::*)() const) &Extrema_LocateExtPC::Point, "Returns the point of the extremum distance.");

// Enums

}