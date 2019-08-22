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
#include <Approx_SweepFunction.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <AdvApprox_EvaluatorFunction.hxx>
#include <AdvApprox_Cutting.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColgp_SequenceOfArray1OfPnt2d.hxx>
#include <Approx_HArray1OfGTrsf2d.hxx>
#include <gp_Vec.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <TColgp_HArray1OfVec2d.hxx>
#include <Approx_SweepApproximation.hxx>

void bind_Approx_SweepApproximation(py::module &mod){

py::class_<Approx_SweepApproximation> cls_Approx_SweepApproximation(mod, "Approx_SweepApproximation", "Approximation of an Surface S(u,v) (and eventually associate 2d Curves) defined by section's law.");

// Constructors
cls_Approx_SweepApproximation.def(py::init<const opencascade::handle<Approx_SweepFunction> &>(), py::arg("Func"));

// Fields

// Methods
// cls_Approx_SweepApproximation.def_static("operator new_", (void * (*)(size_t)) &Approx_SweepApproximation::operator new, "None", py::arg("theSize"));
// cls_Approx_SweepApproximation.def_static("operator delete_", (void (*)(void *)) &Approx_SweepApproximation::operator delete, "None", py::arg("theAddress"));
// cls_Approx_SweepApproximation.def_static("operator new[]_", (void * (*)(size_t)) &Approx_SweepApproximation::operator new[], "None", py::arg("theSize"));
// cls_Approx_SweepApproximation.def_static("operator delete[]_", (void (*)(void *)) &Approx_SweepApproximation::operator delete[], "None", py::arg("theAddress"));
// cls_Approx_SweepApproximation.def_static("operator new_", (void * (*)(size_t, void *)) &Approx_SweepApproximation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Approx_SweepApproximation.def_static("operator delete_", (void (*)(void *, void *)) &Approx_SweepApproximation::operator delete, "None", py::arg(""), py::arg(""));
cls_Approx_SweepApproximation.def("Perform", [](Approx_SweepApproximation &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); });
cls_Approx_SweepApproximation.def("Perform", [](Approx_SweepApproximation &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const GeomAbs_Shape a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_Approx_SweepApproximation.def("Perform", [](Approx_SweepApproximation &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const GeomAbs_Shape a6, const Standard_Integer a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_Approx_SweepApproximation.def("Perform", (void (Approx_SweepApproximation::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &Approx_SweepApproximation::Perform, "Perform the Approximation [First, Last] : Approx_SweepApproximation.cdl Tol3d : Tolerance to surface approximation Tol2d : Tolerance used to perform curve approximation Normaly the 2d curve are approximated with a tolerance given by the resolution on support surfaces, but if this tolerance is too large Tol2d is used. TolAngular : Tolerance (in radian) to control the angle beetween tangents on the section law and tangent of iso-v on approximed surface Continuity : The continuity in v waiting on the surface Degmax : The maximum degree in v requiered on the surface Segmax : The maximum number of span in v requiered on the surface Warning : The continuity ci can be obtained only if Ft is Ci", py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("BoundTol"), py::arg("Tol2d"), py::arg("TolAngular"), py::arg("Continuity"), py::arg("Degmax"), py::arg("Segmax"));
cls_Approx_SweepApproximation.def("Eval", [](Approx_SweepApproximation &self, const Standard_Real Parameter, const Standard_Integer DerivativeRequest, const Standard_Real First, const Standard_Real Last, Standard_Real & Result){ Standard_Integer rv = self.Eval(Parameter, DerivativeRequest, First, Last, Result); return std::tuple<Standard_Integer, Standard_Real &>(rv, Result); }, "The EvaluatorFunction from AdvApprox;", py::arg("Parameter"), py::arg("DerivativeRequest"), py::arg("First"), py::arg("Last"), py::arg("Result"));
cls_Approx_SweepApproximation.def("IsDone", (Standard_Boolean (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::IsDone, "returns if we have an result");
cls_Approx_SweepApproximation.def("SurfShape", [](Approx_SweepApproximation &self, Standard_Integer & UDegree, Standard_Integer & VDegree, Standard_Integer & NbUPoles, Standard_Integer & NbVPoles, Standard_Integer & NbUKnots, Standard_Integer & NbVKnots){ self.SurfShape(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); }, "None", py::arg("UDegree"), py::arg("VDegree"), py::arg("NbUPoles"), py::arg("NbVPoles"), py::arg("NbUKnots"), py::arg("NbVKnots"));
cls_Approx_SweepApproximation.def("Surface", (void (Approx_SweepApproximation::*)(TColgp_Array2OfPnt &, TColStd_Array2OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const) &Approx_SweepApproximation::Surface, "None", py::arg("TPoles"), py::arg("TWeights"), py::arg("TUKnots"), py::arg("TVKnots"), py::arg("TUMults"), py::arg("TVMults"));
cls_Approx_SweepApproximation.def("UDegree", (Standard_Integer (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::UDegree, "None");
cls_Approx_SweepApproximation.def("VDegree", (Standard_Integer (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::VDegree, "None");
cls_Approx_SweepApproximation.def("SurfPoles", (const TColgp_Array2OfPnt & (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::SurfPoles, "None");
cls_Approx_SweepApproximation.def("SurfWeights", (const TColStd_Array2OfReal & (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::SurfWeights, "None");
cls_Approx_SweepApproximation.def("SurfUKnots", (const TColStd_Array1OfReal & (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::SurfUKnots, "None");
cls_Approx_SweepApproximation.def("SurfVKnots", (const TColStd_Array1OfReal & (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::SurfVKnots, "None");
cls_Approx_SweepApproximation.def("SurfUMults", (const TColStd_Array1OfInteger & (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::SurfUMults, "None");
cls_Approx_SweepApproximation.def("SurfVMults", (const TColStd_Array1OfInteger & (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::SurfVMults, "None");
cls_Approx_SweepApproximation.def("MaxErrorOnSurf", (Standard_Real (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::MaxErrorOnSurf, "returns the maximum error in the suface approximation.");
cls_Approx_SweepApproximation.def("AverageErrorOnSurf", (Standard_Real (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::AverageErrorOnSurf, "returns the average error in the suface approximation.");
cls_Approx_SweepApproximation.def("NbCurves2d", (Standard_Integer (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::NbCurves2d, "None");
cls_Approx_SweepApproximation.def("Curves2dShape", [](Approx_SweepApproximation &self, Standard_Integer & Degree, Standard_Integer & NbPoles, Standard_Integer & NbKnots){ self.Curves2dShape(Degree, NbPoles, NbKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(Degree, NbPoles, NbKnots); }, "None", py::arg("Degree"), py::arg("NbPoles"), py::arg("NbKnots"));
cls_Approx_SweepApproximation.def("Curve2d", (void (Approx_SweepApproximation::*)(const Standard_Integer, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &Approx_SweepApproximation::Curve2d, "None", py::arg("Index"), py::arg("TPoles"), py::arg("TKnots"), py::arg("TMults"));
cls_Approx_SweepApproximation.def("Curves2dDegree", (Standard_Integer (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::Curves2dDegree, "None");
cls_Approx_SweepApproximation.def("Curve2dPoles", (const TColgp_Array1OfPnt2d & (Approx_SweepApproximation::*)(const Standard_Integer) const) &Approx_SweepApproximation::Curve2dPoles, "None", py::arg("Index"));
cls_Approx_SweepApproximation.def("Curves2dKnots", (const TColStd_Array1OfReal & (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::Curves2dKnots, "None");
cls_Approx_SweepApproximation.def("Curves2dMults", (const TColStd_Array1OfInteger & (Approx_SweepApproximation::*)() const) &Approx_SweepApproximation::Curves2dMults, "None");
cls_Approx_SweepApproximation.def("Max2dError", (Standard_Real (Approx_SweepApproximation::*)(const Standard_Integer) const) &Approx_SweepApproximation::Max2dError, "returns the maximum error of the <Index> 2d curve approximation.", py::arg("Index"));
cls_Approx_SweepApproximation.def("Average2dError", (Standard_Real (Approx_SweepApproximation::*)(const Standard_Integer) const) &Approx_SweepApproximation::Average2dError, "returns the average error of the <Index> 2d curve approximation.", py::arg("Index"));
cls_Approx_SweepApproximation.def("TolCurveOnSurf", (Standard_Real (Approx_SweepApproximation::*)(const Standard_Integer) const) &Approx_SweepApproximation::TolCurveOnSurf, "returns the maximum 3d error of the <Index> 2d curve approximation on the Surface.", py::arg("Index"));
cls_Approx_SweepApproximation.def("Dump", (void (Approx_SweepApproximation::*)(Standard_OStream &) const) &Approx_SweepApproximation::Dump, "display information on approximation.", py::arg("o"));

// Enums

}