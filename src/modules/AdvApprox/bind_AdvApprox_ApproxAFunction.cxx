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
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <GeomAbs_Shape.hxx>
#include <AdvApprox_EvaluatorFunction.hxx>
#include <AdvApprox_Cutting.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColgp_HArray2OfPnt2d.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_OStream.hxx>
#include <AdvApprox_ApproxAFunction.hxx>

void bind_AdvApprox_ApproxAFunction(py::module &mod){

py::class_<AdvApprox_ApproxAFunction, std::unique_ptr<AdvApprox_ApproxAFunction, Deleter<AdvApprox_ApproxAFunction>>> cls_AdvApprox_ApproxAFunction(mod, "AdvApprox_ApproxAFunction", "this approximate a given function");

// Constructors
cls_AdvApprox_ApproxAFunction.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const AdvApprox_EvaluatorFunction &>(), py::arg("Num1DSS"), py::arg("Num2DSS"), py::arg("Num3DSS"), py::arg("OneDTol"), py::arg("TwoDTol"), py::arg("ThreeDTol"), py::arg("First"), py::arg("Last"), py::arg("Continuity"), py::arg("MaxDeg"), py::arg("MaxSeg"), py::arg("Func"));
cls_AdvApprox_ApproxAFunction.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const AdvApprox_EvaluatorFunction &, const AdvApprox_Cutting &>(), py::arg("Num1DSS"), py::arg("Num2DSS"), py::arg("Num3DSS"), py::arg("OneDTol"), py::arg("TwoDTol"), py::arg("ThreeDTol"), py::arg("First"), py::arg("Last"), py::arg("Continuity"), py::arg("MaxDeg"), py::arg("MaxSeg"), py::arg("Func"), py::arg("CutTool"));

// Fields

// Methods
// cls_AdvApprox_ApproxAFunction.def_static("operator new_", (void * (*)(size_t)) &AdvApprox_ApproxAFunction::operator new, "None", py::arg("theSize"));
// cls_AdvApprox_ApproxAFunction.def_static("operator delete_", (void (*)(void *)) &AdvApprox_ApproxAFunction::operator delete, "None", py::arg("theAddress"));
// cls_AdvApprox_ApproxAFunction.def_static("operator new[]_", (void * (*)(size_t)) &AdvApprox_ApproxAFunction::operator new[], "None", py::arg("theSize"));
// cls_AdvApprox_ApproxAFunction.def_static("operator delete[]_", (void (*)(void *)) &AdvApprox_ApproxAFunction::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApprox_ApproxAFunction.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApprox_ApproxAFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApprox_ApproxAFunction.def_static("operator delete_", (void (*)(void *, void *)) &AdvApprox_ApproxAFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApprox_ApproxAFunction.def_static("Approximation_", [](const Standard_Integer TotalDimension, const Standard_Integer TotalNumSS, const TColStd_Array1OfInteger & LocalDimension, const Standard_Real First, const Standard_Real Last, AdvApprox_EvaluatorFunction & Evaluator, const AdvApprox_Cutting & CutTool, const Standard_Integer ContinuityOrder, const Standard_Integer NumMaxCoeffs, const Standard_Integer MaxSegments, const TColStd_Array1OfReal & TolerancesArray, const Standard_Integer code_precis, Standard_Integer & NumCurves, TColStd_Array1OfInteger & NumCoeffPerCurveArray, TColStd_Array1OfReal & LocalCoefficientArray, TColStd_Array1OfReal & IntervalsArray, TColStd_Array1OfReal & ErrorMaxArray, TColStd_Array1OfReal & AverageErrorArray, Standard_Integer & ErrorCode){ AdvApprox_ApproxAFunction::Approximation(TotalDimension, TotalNumSS, LocalDimension, First, Last, Evaluator, CutTool, ContinuityOrder, NumMaxCoeffs, MaxSegments, TolerancesArray, code_precis, NumCurves, NumCoeffPerCurveArray, LocalCoefficientArray, IntervalsArray, ErrorMaxArray, AverageErrorArray, ErrorCode); return std::tuple<Standard_Integer &, Standard_Integer &>(NumCurves, ErrorCode); }, "None", py::arg("TotalDimension"), py::arg("TotalNumSS"), py::arg("LocalDimension"), py::arg("First"), py::arg("Last"), py::arg("Evaluator"), py::arg("CutTool"), py::arg("ContinuityOrder"), py::arg("NumMaxCoeffs"), py::arg("MaxSegments"), py::arg("TolerancesArray"), py::arg("code_precis"), py::arg("NumCurves"), py::arg("NumCoeffPerCurveArray"), py::arg("LocalCoefficientArray"), py::arg("IntervalsArray"), py::arg("ErrorMaxArray"), py::arg("AverageErrorArray"), py::arg("ErrorCode"));
cls_AdvApprox_ApproxAFunction.def("IsDone", (Standard_Boolean (AdvApprox_ApproxAFunction::*)() const) &AdvApprox_ApproxAFunction::IsDone, "None");
cls_AdvApprox_ApproxAFunction.def("HasResult", (Standard_Boolean (AdvApprox_ApproxAFunction::*)() const) &AdvApprox_ApproxAFunction::HasResult, "None");
cls_AdvApprox_ApproxAFunction.def("Poles1d", (opencascade::handle<TColStd_HArray2OfReal> (AdvApprox_ApproxAFunction::*)() const) &AdvApprox_ApproxAFunction::Poles1d, "returns the poles from the algorithms as is");
cls_AdvApprox_ApproxAFunction.def("Poles2d", (opencascade::handle<TColgp_HArray2OfPnt2d> (AdvApprox_ApproxAFunction::*)() const) &AdvApprox_ApproxAFunction::Poles2d, "returns the poles from the algorithms as is");
cls_AdvApprox_ApproxAFunction.def("Poles", (opencascade::handle<TColgp_HArray2OfPnt> (AdvApprox_ApproxAFunction::*)() const) &AdvApprox_ApproxAFunction::Poles, "-- returns the poles from the algorithms as is");
cls_AdvApprox_ApproxAFunction.def("NbPoles", (Standard_Integer (AdvApprox_ApproxAFunction::*)() const) &AdvApprox_ApproxAFunction::NbPoles, "as the name says");
cls_AdvApprox_ApproxAFunction.def("Poles1d", (void (AdvApprox_ApproxAFunction::*)(const Standard_Integer, TColStd_Array1OfReal &) const) &AdvApprox_ApproxAFunction::Poles1d, "returns the poles at Index from the 1d subspace", py::arg("Index"), py::arg("P"));
cls_AdvApprox_ApproxAFunction.def("Poles2d", (void (AdvApprox_ApproxAFunction::*)(const Standard_Integer, TColgp_Array1OfPnt2d &) const) &AdvApprox_ApproxAFunction::Poles2d, "returns the poles at Index from the 2d subspace", py::arg("Index"), py::arg("P"));
cls_AdvApprox_ApproxAFunction.def("Poles", (void (AdvApprox_ApproxAFunction::*)(const Standard_Integer, TColgp_Array1OfPnt &) const) &AdvApprox_ApproxAFunction::Poles, "returns the poles at Index from the 3d subspace", py::arg("Index"), py::arg("P"));
cls_AdvApprox_ApproxAFunction.def("Degree", (Standard_Integer (AdvApprox_ApproxAFunction::*)() const) &AdvApprox_ApproxAFunction::Degree, "None");
cls_AdvApprox_ApproxAFunction.def("NbKnots", (Standard_Integer (AdvApprox_ApproxAFunction::*)() const) &AdvApprox_ApproxAFunction::NbKnots, "None");
cls_AdvApprox_ApproxAFunction.def("NumSubSpaces", (Standard_Integer (AdvApprox_ApproxAFunction::*)(const Standard_Integer) const) &AdvApprox_ApproxAFunction::NumSubSpaces, "None", py::arg("Dimension"));
cls_AdvApprox_ApproxAFunction.def("Knots", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_ApproxAFunction::*)() const) &AdvApprox_ApproxAFunction::Knots, "None");
cls_AdvApprox_ApproxAFunction.def("Multiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (AdvApprox_ApproxAFunction::*)() const) &AdvApprox_ApproxAFunction::Multiplicities, "None");
cls_AdvApprox_ApproxAFunction.def("MaxError", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_ApproxAFunction::*)(const Standard_Integer) const) &AdvApprox_ApproxAFunction::MaxError, "returns the error as is in the algorithms", py::arg("Dimension"));
cls_AdvApprox_ApproxAFunction.def("AverageError", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_ApproxAFunction::*)(const Standard_Integer) const) &AdvApprox_ApproxAFunction::AverageError, "returns the error as is in the algorithms", py::arg("Dimension"));
cls_AdvApprox_ApproxAFunction.def("MaxError", (Standard_Real (AdvApprox_ApproxAFunction::*)(const Standard_Integer, const Standard_Integer) const) &AdvApprox_ApproxAFunction::MaxError, "None", py::arg("Dimension"), py::arg("Index"));
cls_AdvApprox_ApproxAFunction.def("AverageError", (Standard_Real (AdvApprox_ApproxAFunction::*)(const Standard_Integer, const Standard_Integer) const) &AdvApprox_ApproxAFunction::AverageError, "None", py::arg("Dimension"), py::arg("Index"));
cls_AdvApprox_ApproxAFunction.def("Dump", (void (AdvApprox_ApproxAFunction::*)(Standard_OStream &) const) &AdvApprox_ApproxAFunction::Dump, "diplay information on approximation.", py::arg("o"));

// Enums

}