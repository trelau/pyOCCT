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
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <gp_Pnt2d.hxx>
#include <Extrema_ExtElC2d.hxx>
#include <Extrema_ECC2d.hxx>
#include <Extrema_SequenceOfPOnCurv2d.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_ExtCC2d.hxx>

void bind_Extrema_ExtCC2d(py::module &mod){

py::class_<Extrema_ExtCC2d, std::unique_ptr<Extrema_ExtCC2d>> cls_Extrema_ExtCC2d(mod, "Extrema_ExtCC2d", "It calculates all the distance between two curves. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtCC2d.def(py::init<>());
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolC1"));
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolC1"), py::arg("TolC2"));
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("TolC1"));
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("TolC1"), py::arg("TolC2"));

// Fields

// Methods
// cls_Extrema_ExtCC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtCC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtCC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtCC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtCC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtCC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtCC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtCC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtCC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtCC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtCC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtCC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtCC2d.def("Initialize", [](Extrema_ExtCC2d &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_Extrema_ExtCC2d.def("Initialize", [](Extrema_ExtCC2d &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_Extrema_ExtCC2d.def("Initialize", (void (Extrema_ExtCC2d::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtCC2d::Initialize, "initializes the fields.", py::arg("C2"), py::arg("V1"), py::arg("V2"), py::arg("TolC1"), py::arg("TolC2"));
cls_Extrema_ExtCC2d.def("Perform", (void (Extrema_ExtCC2d::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &Extrema_ExtCC2d::Perform, "None", py::arg("C1"), py::arg("U1"), py::arg("U2"));
cls_Extrema_ExtCC2d.def("IsDone", (Standard_Boolean (Extrema_ExtCC2d::*)() const) &Extrema_ExtCC2d::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtCC2d.def("NbExt", (Standard_Integer (Extrema_ExtCC2d::*)() const) &Extrema_ExtCC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtCC2d.def("IsParallel", (Standard_Boolean (Extrema_ExtCC2d::*)() const) &Extrema_ExtCC2d::IsParallel, "Returns True if the two curves are parallel.");
cls_Extrema_ExtCC2d.def("SquareDistance", [](Extrema_ExtCC2d &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtCC2d.def("SquareDistance", (Standard_Real (Extrema_ExtCC2d::*)(const Standard_Integer) const) &Extrema_ExtCC2d::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtCC2d.def("Points", (void (Extrema_ExtCC2d::*)(const Standard_Integer, Extrema_POnCurv2d &, Extrema_POnCurv2d &) const) &Extrema_ExtCC2d::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));
cls_Extrema_ExtCC2d.def("TrimmedSquareDistances", [](Extrema_ExtCC2d &self, Standard_Real & dist11, Standard_Real & distP12, Standard_Real & distP21, Standard_Real & distP22, gp_Pnt2d & P11, gp_Pnt2d & P12, gp_Pnt2d & P21, gp_Pnt2d & P22){ self.TrimmedSquareDistances(dist11, distP12, distP21, distP22, P11, P12, P21, P22); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(dist11, distP12, distP21, distP22); }, "if the curve is a trimmed curve, dist11 is a square distance between the point on C1 of parameter FirstParameter and the point of parameter FirstParameter on C2.", py::arg("dist11"), py::arg("distP12"), py::arg("distP21"), py::arg("distP22"), py::arg("P11"), py::arg("P12"), py::arg("P21"), py::arg("P22"));
cls_Extrema_ExtCC2d.def("SetSingleSolutionFlag", (void (Extrema_ExtCC2d::*)(const Standard_Boolean)) &Extrema_ExtCC2d::SetSingleSolutionFlag, "Set flag for single extrema computation. Works on parametric solver only.", py::arg("theSingleSolutionFlag"));
cls_Extrema_ExtCC2d.def("GetSingleSolutionFlag", (Standard_Boolean (Extrema_ExtCC2d::*)() const) &Extrema_ExtCC2d::GetSingleSolutionFlag, "Get flag for single extrema computation. Works on parametric solver only.");

// Enums

}