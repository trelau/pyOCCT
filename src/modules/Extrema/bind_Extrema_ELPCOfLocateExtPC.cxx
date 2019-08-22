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
#include <Extrema_ExtPElC.hxx>
#include <Extrema_SequenceOfPOnCurv.hxx>
#include <Extrema_EPCOfELPCOfLocateExtPC.hxx>
#include <GeomAbs_CurveType.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_ELPCOfLocateExtPC.hxx>

void bind_Extrema_ELPCOfLocateExtPC(py::module &mod){

py::class_<Extrema_ELPCOfLocateExtPC> cls_Extrema_ELPCOfLocateExtPC(mod, "Extrema_ELPCOfLocateExtPC", "None");

// Constructors
cls_Extrema_ELPCOfLocateExtPC.def(py::init<>());
cls_Extrema_ELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_ELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &>(), py::arg("P"), py::arg("C"));
cls_Extrema_ELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("TolF"));

// Fields

// Methods
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_ELPCOfLocateExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_ELPCOfLocateExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ELPCOfLocateExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ELPCOfLocateExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ELPCOfLocateExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ELPCOfLocateExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ELPCOfLocateExtPC.def("Initialize", [](Extrema_ELPCOfLocateExtPC &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_Extrema_ELPCOfLocateExtPC.def("Initialize", (void (Extrema_ELPCOfLocateExtPC::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ELPCOfLocateExtPC::Initialize, "initializes the fields of the algorithm.", py::arg("C"), py::arg("Uinf"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_ELPCOfLocateExtPC.def("Perform", (void (Extrema_ELPCOfLocateExtPC::*)(const gp_Pnt &)) &Extrema_ELPCOfLocateExtPC::Perform, "An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_ELPCOfLocateExtPC.def("IsDone", (Standard_Boolean (Extrema_ELPCOfLocateExtPC::*)() const) &Extrema_ELPCOfLocateExtPC::IsDone, "True if the distances are found.");
cls_Extrema_ELPCOfLocateExtPC.def("SquareDistance", (Standard_Real (Extrema_ELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_ELPCOfLocateExtPC::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
cls_Extrema_ELPCOfLocateExtPC.def("NbExt", (Standard_Integer (Extrema_ELPCOfLocateExtPC::*)() const) &Extrema_ELPCOfLocateExtPC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ELPCOfLocateExtPC.def("IsMin", (Standard_Boolean (Extrema_ELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_ELPCOfLocateExtPC::IsMin, "Returns True if the <N>th extremum distance is a minimum.", py::arg("N"));
cls_Extrema_ELPCOfLocateExtPC.def("Point", (const Extrema_POnCurv & (Extrema_ELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_ELPCOfLocateExtPC::Point, "Returns the point of the <N>th extremum distance.", py::arg("N"));
cls_Extrema_ELPCOfLocateExtPC.def("TrimmedSquareDistances", [](Extrema_ELPCOfLocateExtPC &self, Standard_Real & dist1, Standard_Real & dist2, gp_Pnt & P1, gp_Pnt & P2){ self.TrimmedSquareDistances(dist1, dist2, P1, P2); return std::tuple<Standard_Real &, Standard_Real &>(dist1, dist2); }, "if the curve is a trimmed curve, dist1 is a square distance between <P> and the point of parameter FirstParameter <P1> and dist2 is a square distance between <P> and the point of parameter LastParameter <P2>.", py::arg("dist1"), py::arg("dist2"), py::arg("P1"), py::arg("P2"));

// Enums

}