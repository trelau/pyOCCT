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
#include <GeomFill_SectionGenerator.hxx>
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
#include <GeomFill_AppSurf.hxx>

void bind_GeomFill_AppSurf(py::module &mod){

py::class_<GeomFill_AppSurf, AppBlend_Approx> cls_GeomFill_AppSurf(mod, "GeomFill_AppSurf", "Approximate a BSplineSurface passing by all the curves described in the SectionGenerator");

// Constructors
cls_GeomFill_AppSurf.def(py::init<>());
cls_GeomFill_AppSurf.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"));
cls_GeomFill_AppSurf.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"), py::arg("KnownParameters"));

// Fields

// Methods
// cls_GeomFill_AppSurf.def_static("operator new_", (void * (*)(size_t)) &GeomFill_AppSurf::operator new, "None", py::arg("theSize"));
// cls_GeomFill_AppSurf.def_static("operator delete_", (void (*)(void *)) &GeomFill_AppSurf::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_AppSurf.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_AppSurf::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_AppSurf.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_AppSurf::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_AppSurf.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_AppSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_AppSurf.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_AppSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_AppSurf.def("Init", [](GeomFill_AppSurf &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomFill_AppSurf.def("Init", (void (GeomFill_AppSurf::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean)) &GeomFill_AppSurf::Init, "None", py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"), py::arg("KnownParameters"));
cls_GeomFill_AppSurf.def("SetParType", (void (GeomFill_AppSurf::*)(const Approx_ParametrizationType)) &GeomFill_AppSurf::SetParType, "Define the type of parametrization used in the approximation", py::arg("ParType"));
cls_GeomFill_AppSurf.def("SetContinuity", (void (GeomFill_AppSurf::*)(const GeomAbs_Shape)) &GeomFill_AppSurf::SetContinuity, "Define the Continuity used in the approximation", py::arg("C"));
cls_GeomFill_AppSurf.def("SetCriteriumWeight", (void (GeomFill_AppSurf::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_AppSurf::SetCriteriumWeight, "define the Weights associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_GeomFill_AppSurf.def("ParType", (Approx_ParametrizationType (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::ParType, "returns the type of parametrization used in the approximation");
cls_GeomFill_AppSurf.def("Continuity", (GeomAbs_Shape (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::Continuity, "returns the Continuity used in the approximation");
cls_GeomFill_AppSurf.def("CriteriumWeight", [](GeomFill_AppSurf &self, Standard_Real & W1, Standard_Real & W2, Standard_Real & W3){ self.CriteriumWeight(W1, W2, W3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(W1, W2, W3); }, "returns the Weights (as percent) associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_GeomFill_AppSurf.def("Perform", [](GeomFill_AppSurf &self, const opencascade::handle<GeomFill_Line> & a0, GeomFill_SectionGenerator & a1) -> void { return self.Perform(a0, a1); });
cls_GeomFill_AppSurf.def("Perform", (void (GeomFill_AppSurf::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SectionGenerator &, const Standard_Boolean)) &GeomFill_AppSurf::Perform, "None", py::arg("Lin"), py::arg("SecGen"), py::arg("SpApprox"));
cls_GeomFill_AppSurf.def("PerformSmoothing", (void (GeomFill_AppSurf::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SectionGenerator &)) &GeomFill_AppSurf::PerformSmoothing, "None", py::arg("Lin"), py::arg("SecGen"));
cls_GeomFill_AppSurf.def("Perform", (void (GeomFill_AppSurf::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SectionGenerator &, const Standard_Integer)) &GeomFill_AppSurf::Perform, "None", py::arg("Lin"), py::arg("SecGen"), py::arg("NbMaxP"));
cls_GeomFill_AppSurf.def("IsDone", (Standard_Boolean (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::IsDone, "None");
cls_GeomFill_AppSurf.def("SurfShape", [](GeomFill_AppSurf &self, Standard_Integer & UDegree, Standard_Integer & VDegree, Standard_Integer & NbUPoles, Standard_Integer & NbVPoles, Standard_Integer & NbUKnots, Standard_Integer & NbVKnots){ self.SurfShape(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); }, "None", py::arg("UDegree"), py::arg("VDegree"), py::arg("NbUPoles"), py::arg("NbVPoles"), py::arg("NbUKnots"), py::arg("NbVKnots"));
cls_GeomFill_AppSurf.def("Surface", (void (GeomFill_AppSurf::*)(TColgp_Array2OfPnt &, TColStd_Array2OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const) &GeomFill_AppSurf::Surface, "None", py::arg("TPoles"), py::arg("TWeights"), py::arg("TUKnots"), py::arg("TVKnots"), py::arg("TUMults"), py::arg("TVMults"));
cls_GeomFill_AppSurf.def("UDegree", (Standard_Integer (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::UDegree, "None");
cls_GeomFill_AppSurf.def("VDegree", (Standard_Integer (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::VDegree, "None");
cls_GeomFill_AppSurf.def("SurfPoles", (const TColgp_Array2OfPnt & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfPoles, "None");
cls_GeomFill_AppSurf.def("SurfWeights", (const TColStd_Array2OfReal & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfWeights, "None");
cls_GeomFill_AppSurf.def("SurfUKnots", (const TColStd_Array1OfReal & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfUKnots, "None");
cls_GeomFill_AppSurf.def("SurfVKnots", (const TColStd_Array1OfReal & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfVKnots, "None");
cls_GeomFill_AppSurf.def("SurfUMults", (const TColStd_Array1OfInteger & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfUMults, "None");
cls_GeomFill_AppSurf.def("SurfVMults", (const TColStd_Array1OfInteger & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfVMults, "None");
cls_GeomFill_AppSurf.def("NbCurves2d", (Standard_Integer (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::NbCurves2d, "None");
cls_GeomFill_AppSurf.def("Curves2dShape", [](GeomFill_AppSurf &self, Standard_Integer & Degree, Standard_Integer & NbPoles, Standard_Integer & NbKnots){ self.Curves2dShape(Degree, NbPoles, NbKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(Degree, NbPoles, NbKnots); }, "None", py::arg("Degree"), py::arg("NbPoles"), py::arg("NbKnots"));
cls_GeomFill_AppSurf.def("Curve2d", (void (GeomFill_AppSurf::*)(const Standard_Integer, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &GeomFill_AppSurf::Curve2d, "None", py::arg("Index"), py::arg("TPoles"), py::arg("TKnots"), py::arg("TMults"));
cls_GeomFill_AppSurf.def("Curves2dDegree", (Standard_Integer (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::Curves2dDegree, "None");
cls_GeomFill_AppSurf.def("Curve2dPoles", (const TColgp_Array1OfPnt2d & (GeomFill_AppSurf::*)(const Standard_Integer) const) &GeomFill_AppSurf::Curve2dPoles, "None", py::arg("Index"));
cls_GeomFill_AppSurf.def("Curves2dKnots", (const TColStd_Array1OfReal & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::Curves2dKnots, "None");
cls_GeomFill_AppSurf.def("Curves2dMults", (const TColStd_Array1OfInteger & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::Curves2dMults, "None");
cls_GeomFill_AppSurf.def("TolReached", [](GeomFill_AppSurf &self, Standard_Real & Tol3d, Standard_Real & Tol2d){ self.TolReached(Tol3d, Tol2d); return std::tuple<Standard_Real &, Standard_Real &>(Tol3d, Tol2d); }, "None", py::arg("Tol3d"), py::arg("Tol2d"));
cls_GeomFill_AppSurf.def("TolCurveOnSurf", (Standard_Real (GeomFill_AppSurf::*)(const Standard_Integer) const) &GeomFill_AppSurf::TolCurveOnSurf, "None", py::arg("Index"));

// Enums

}