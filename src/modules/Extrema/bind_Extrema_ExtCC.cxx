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
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Extrema_POnCurv.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_ExtElC.hxx>
#include <Extrema_ECC.hxx>
#include <Extrema_SequenceOfPOnCurv.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_ExtCC.hxx>

void bind_Extrema_ExtCC(py::module &mod){

py::class_<Extrema_ExtCC> cls_Extrema_ExtCC(mod, "Extrema_ExtCC", "It calculates all the distance between two curves. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtCC.def(py::init<>());
cls_Extrema_ExtCC.def(py::init<const Standard_Real>(), py::arg("TolC1"));
cls_Extrema_ExtCC.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("TolC1"), py::arg("TolC2"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolC1"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolC1"), py::arg("TolC2"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("TolC1"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("TolC1"), py::arg("TolC2"));

// Fields

// Methods
// cls_Extrema_ExtCC.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtCC::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtCC.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtCC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtCC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtCC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtCC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtCC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtCC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtCC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtCC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtCC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtCC.def("SetCurve", (void (Extrema_ExtCC::*)(const Standard_Integer, const Adaptor3d_Curve &)) &Extrema_ExtCC::SetCurve, "None", py::arg("theRank"), py::arg("C"));
cls_Extrema_ExtCC.def("SetCurve", (void (Extrema_ExtCC::*)(const Standard_Integer, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &Extrema_ExtCC::SetCurve, "None", py::arg("theRank"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtCC.def("SetRange", (void (Extrema_ExtCC::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &Extrema_ExtCC::SetRange, "None", py::arg("theRank"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtCC.def("SetTolerance", (void (Extrema_ExtCC::*)(const Standard_Integer, const Standard_Real)) &Extrema_ExtCC::SetTolerance, "None", py::arg("theRank"), py::arg("Tol"));
cls_Extrema_ExtCC.def("Perform", (void (Extrema_ExtCC::*)()) &Extrema_ExtCC::Perform, "None");
cls_Extrema_ExtCC.def("IsDone", (Standard_Boolean (Extrema_ExtCC::*)() const) &Extrema_ExtCC::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtCC.def("NbExt", (Standard_Integer (Extrema_ExtCC::*)() const) &Extrema_ExtCC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtCC.def("IsParallel", (Standard_Boolean (Extrema_ExtCC::*)() const) &Extrema_ExtCC::IsParallel, "Returns True if the two curves are parallel.");
cls_Extrema_ExtCC.def("SquareDistance", [](Extrema_ExtCC &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtCC.def("SquareDistance", (Standard_Real (Extrema_ExtCC::*)(const Standard_Integer) const) &Extrema_ExtCC::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtCC.def("Points", (void (Extrema_ExtCC::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_ExtCC::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));
cls_Extrema_ExtCC.def("TrimmedSquareDistances", [](Extrema_ExtCC &self, Standard_Real & dist11, Standard_Real & distP12, Standard_Real & distP21, Standard_Real & distP22, gp_Pnt & P11, gp_Pnt & P12, gp_Pnt & P21, gp_Pnt & P22){ self.TrimmedSquareDistances(dist11, distP12, distP21, distP22, P11, P12, P21, P22); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(dist11, distP12, distP21, distP22); }, "if the curve is a trimmed curve, dist11 is a square distance between the point on C1 of parameter FirstParameter and the point of parameter FirstParameter on C2.", py::arg("dist11"), py::arg("distP12"), py::arg("distP21"), py::arg("distP22"), py::arg("P11"), py::arg("P12"), py::arg("P21"), py::arg("P22"));
cls_Extrema_ExtCC.def("SetSingleSolutionFlag", (void (Extrema_ExtCC::*)(const Standard_Boolean)) &Extrema_ExtCC::SetSingleSolutionFlag, "Set flag for single extrema computation. Works on parametric solver only.", py::arg("theSingleSolutionFlag"));
cls_Extrema_ExtCC.def("GetSingleSolutionFlag", (Standard_Boolean (Extrema_ExtCC::*)() const) &Extrema_ExtCC::GetSingleSolutionFlag, "Get flag for single extrema computation. Works on parametric solver only.");

// Enums

}