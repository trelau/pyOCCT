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
#include <StepGeom_BSplineCurve.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_HArray1OfCartesianPoint.hxx>
#include <StepGeom_BSplineCurveForm.hxx>
#include <StepData_Logical.hxx>
#include <StepGeom_BSplineCurveWithKnots.hxx>
#include <StepGeom_RationalBSplineCurve.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepGeom_KnotType.hxx>
#include <StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve(py::module &mod){

py::class_<StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve, opencascade::handle<StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve>, StepGeom_BSplineCurve> cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve(mod, "StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve", "None");

// Constructors
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("Init", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_BSplineCurveWithKnots> &, const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aBSplineCurveWithKnots"), py::arg("aRationalBSplineCurve"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("Init", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const StepGeom_KnotType, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aKnotMultiplicities"), py::arg("aKnots"), py::arg("aKnotSpec"), py::arg("aWeightsData"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetBSplineCurveWithKnots", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_BSplineCurveWithKnots> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetBSplineCurveWithKnots, "None", py::arg("aBSplineCurveWithKnots"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("BSplineCurveWithKnots", (opencascade::handle<StepGeom_BSplineCurveWithKnots> (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::BSplineCurveWithKnots, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetRationalBSplineCurve", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetRationalBSplineCurve, "None", py::arg("aRationalBSplineCurve"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("RationalBSplineCurve", (opencascade::handle<StepGeom_RationalBSplineCurve> (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::RationalBSplineCurve, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetKnotMultiplicities", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetKnotMultiplicities, "None", py::arg("aKnotMultiplicities"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("KnotMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::KnotMultiplicities, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("KnotMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::KnotMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("NbKnotMultiplicities", (Standard_Integer (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::NbKnotMultiplicities, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetKnots", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetKnots, "None", py::arg("aKnots"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("Knots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::Knots, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("KnotsValue", (Standard_Real (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::KnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("NbKnots", (Standard_Integer (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::NbKnots, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetKnotSpec", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const StepGeom_KnotType)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetKnotSpec, "None", py::arg("aKnotSpec"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("KnotSpec", (StepGeom_KnotType (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::KnotSpec, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetWeightsData", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("WeightsData", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::WeightsData, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("WeightsDataValue", (Standard_Real (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::WeightsDataValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("NbWeightsData", (Standard_Integer (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::NbWeightsData, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::get_type_name, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::get_type_descriptor, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::DynamicType, "None");

// Enums

}