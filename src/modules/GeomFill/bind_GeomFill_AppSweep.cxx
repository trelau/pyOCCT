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
#include <AppBlend_Approx.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Approx_ParametrizationType.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_Line.hxx>
#include <GeomFill_SweepSectionGenerator.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColgp_SequenceOfArray1OfPnt2d.hxx>
#include <GeomFill_AppSweep.hxx>

void bind_GeomFill_AppSweep(py::module &mod){

py::class_<GeomFill_AppSweep, std::unique_ptr<GeomFill_AppSweep>, AppBlend_Approx> cls_GeomFill_AppSweep(mod, "GeomFill_AppSweep", "Approximate a sweep surface passing by all the curves described in the SweepSectionGenerator.");

// Constructors
cls_GeomFill_AppSweep.def(py::init<>());
cls_GeomFill_AppSweep.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"));
cls_GeomFill_AppSweep.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"), py::arg("KnownParameters"));

// Fields

// Methods
// cls_GeomFill_AppSweep.def_static("operator new_", (void * (*)(size_t)) &GeomFill_AppSweep::operator new, "None", py::arg("theSize"));
// cls_GeomFill_AppSweep.def_static("operator delete_", (void (*)(void *)) &GeomFill_AppSweep::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_AppSweep.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_AppSweep::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_AppSweep.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_AppSweep::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_AppSweep.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_AppSweep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_AppSweep.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_AppSweep::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_AppSweep.def("Init", [](GeomFill_AppSweep &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomFill_AppSweep.def("Init", (void (GeomFill_AppSweep::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean)) &GeomFill_AppSweep::Init, "None", py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"), py::arg("KnownParameters"));
cls_GeomFill_AppSweep.def("SetParType", (void (GeomFill_AppSweep::*)(const Approx_ParametrizationType)) &GeomFill_AppSweep::SetParType, "Define the type of parametrization used in the approximation", py::arg("ParType"));
cls_GeomFill_AppSweep.def("SetContinuity", (void (GeomFill_AppSweep::*)(const GeomAbs_Shape)) &GeomFill_AppSweep::SetContinuity, "Define the Continuity used in the approximation", py::arg("C"));
cls_GeomFill_AppSweep.def("SetCriteriumWeight", (void (GeomFill_AppSweep::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_AppSweep::SetCriteriumWeight, "define the Weights associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_GeomFill_AppSweep.def("ParType", (Approx_ParametrizationType (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::ParType, "returns the type of parametrization used in the approximation");
cls_GeomFill_AppSweep.def("Continuity", (GeomAbs_Shape (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::Continuity, "returns the Continuity used in the approximation");
cls_GeomFill_AppSweep.def("CriteriumWeight", [](GeomFill_AppSweep &self, Standard_Real & W1, Standard_Real & W2, Standard_Real & W3){ self.CriteriumWeight(W1, W2, W3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(W1, W2, W3); }, "returns the Weights (as percent) associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_GeomFill_AppSweep.def("Perform", [](GeomFill_AppSweep &self, const opencascade::handle<GeomFill_Line> & a0, GeomFill_SweepSectionGenerator & a1) -> void { return self.Perform(a0, a1); });
cls_GeomFill_AppSweep.def("Perform", (void (GeomFill_AppSweep::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SweepSectionGenerator &, const Standard_Boolean)) &GeomFill_AppSweep::Perform, "None", py::arg("Lin"), py::arg("SecGen"), py::arg("SpApprox"));
cls_GeomFill_AppSweep.def("PerformSmoothing", (void (GeomFill_AppSweep::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SweepSectionGenerator &)) &GeomFill_AppSweep::PerformSmoothing, "None", py::arg("Lin"), py::arg("SecGen"));
cls_GeomFill_AppSweep.def("Perform", (void (GeomFill_AppSweep::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SweepSectionGenerator &, const Standard_Integer)) &GeomFill_AppSweep::Perform, "None", py::arg("Lin"), py::arg("SecGen"), py::arg("NbMaxP"));
cls_GeomFill_AppSweep.def("IsDone", (Standard_Boolean (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::IsDone, "None");
cls_GeomFill_AppSweep.def("SurfShape", [](GeomFill_AppSweep &self, Standard_Integer & UDegree, Standard_Integer & VDegree, Standard_Integer & NbUPoles, Standard_Integer & NbVPoles, Standard_Integer & NbUKnots, Standard_Integer & NbVKnots){ self.SurfShape(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); }, "None", py::arg("UDegree"), py::arg("VDegree"), py::arg("NbUPoles"), py::arg("NbVPoles"), py::arg("NbUKnots"), py::arg("NbVKnots"));
cls_GeomFill_AppSweep.def("Surface", (void (GeomFill_AppSweep::*)(TColgp_Array2OfPnt &, TColStd_Array2OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const) &GeomFill_AppSweep::Surface, "None", py::arg("TPoles"), py::arg("TWeights"), py::arg("TUKnots"), py::arg("TVKnots"), py::arg("TUMults"), py::arg("TVMults"));
cls_GeomFill_AppSweep.def("UDegree", (Standard_Integer (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::UDegree, "None");
cls_GeomFill_AppSweep.def("VDegree", (Standard_Integer (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::VDegree, "None");
cls_GeomFill_AppSweep.def("SurfPoles", (const TColgp_Array2OfPnt & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfPoles, "None");
cls_GeomFill_AppSweep.def("SurfWeights", (const TColStd_Array2OfReal & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfWeights, "None");
cls_GeomFill_AppSweep.def("SurfUKnots", (const TColStd_Array1OfReal & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfUKnots, "None");
cls_GeomFill_AppSweep.def("SurfVKnots", (const TColStd_Array1OfReal & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfVKnots, "None");
cls_GeomFill_AppSweep.def("SurfUMults", (const TColStd_Array1OfInteger & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfUMults, "None");
cls_GeomFill_AppSweep.def("SurfVMults", (const TColStd_Array1OfInteger & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfVMults, "None");
cls_GeomFill_AppSweep.def("NbCurves2d", (Standard_Integer (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::NbCurves2d, "None");
cls_GeomFill_AppSweep.def("Curves2dShape", [](GeomFill_AppSweep &self, Standard_Integer & Degree, Standard_Integer & NbPoles, Standard_Integer & NbKnots){ self.Curves2dShape(Degree, NbPoles, NbKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(Degree, NbPoles, NbKnots); }, "None", py::arg("Degree"), py::arg("NbPoles"), py::arg("NbKnots"));
cls_GeomFill_AppSweep.def("Curve2d", (void (GeomFill_AppSweep::*)(const Standard_Integer, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &GeomFill_AppSweep::Curve2d, "None", py::arg("Index"), py::arg("TPoles"), py::arg("TKnots"), py::arg("TMults"));
cls_GeomFill_AppSweep.def("Curves2dDegree", (Standard_Integer (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::Curves2dDegree, "None");
cls_GeomFill_AppSweep.def("Curve2dPoles", (const TColgp_Array1OfPnt2d & (GeomFill_AppSweep::*)(const Standard_Integer) const) &GeomFill_AppSweep::Curve2dPoles, "None", py::arg("Index"));
cls_GeomFill_AppSweep.def("Curves2dKnots", (const TColStd_Array1OfReal & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::Curves2dKnots, "None");
cls_GeomFill_AppSweep.def("Curves2dMults", (const TColStd_Array1OfInteger & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::Curves2dMults, "None");
cls_GeomFill_AppSweep.def("TolReached", [](GeomFill_AppSweep &self, Standard_Real & Tol3d, Standard_Real & Tol2d){ self.TolReached(Tol3d, Tol2d); return std::tuple<Standard_Real &, Standard_Real &>(Tol3d, Tol2d); }, "None", py::arg("Tol3d"), py::arg("Tol2d"));
cls_GeomFill_AppSweep.def("TolCurveOnSurf", (Standard_Real (GeomFill_AppSweep::*)(const Standard_Integer) const) &GeomFill_AppSweep::TolCurveOnSurf, "None", py::arg("Index"));

// Enums

}