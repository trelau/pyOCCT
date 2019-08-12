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
#include <StepGeom_BezierCurve.hxx>
#include <StepGeom_RationalBSplineCurve.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepGeom_BezierCurveAndRationalBSplineCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_BezierCurveAndRationalBSplineCurve(py::module &mod){

py::class_<StepGeom_BezierCurveAndRationalBSplineCurve, opencascade::handle<StepGeom_BezierCurveAndRationalBSplineCurve>, StepGeom_BSplineCurve> cls_StepGeom_BezierCurveAndRationalBSplineCurve(mod, "StepGeom_BezierCurveAndRationalBSplineCurve", "None");

// Constructors
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_BezierCurve> &, const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_BezierCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aBezierCurve"), py::arg("aRationalBSplineCurve"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BezierCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("SetBezierCurve", (void (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_BezierCurve> &)) &StepGeom_BezierCurveAndRationalBSplineCurve::SetBezierCurve, "None", py::arg("aBezierCurve"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("BezierCurve", (opencascade::handle<StepGeom_BezierCurve> (StepGeom_BezierCurveAndRationalBSplineCurve::*)() const) &StepGeom_BezierCurveAndRationalBSplineCurve::BezierCurve, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("SetRationalBSplineCurve", (void (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_BezierCurveAndRationalBSplineCurve::SetRationalBSplineCurve, "None", py::arg("aRationalBSplineCurve"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("RationalBSplineCurve", (opencascade::handle<StepGeom_RationalBSplineCurve> (StepGeom_BezierCurveAndRationalBSplineCurve::*)() const) &StepGeom_BezierCurveAndRationalBSplineCurve::RationalBSplineCurve, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("SetWeightsData", (void (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BezierCurveAndRationalBSplineCurve::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("WeightsData", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BezierCurveAndRationalBSplineCurve::*)() const) &StepGeom_BezierCurveAndRationalBSplineCurve::WeightsData, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("WeightsDataValue", (Standard_Real (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_BezierCurveAndRationalBSplineCurve::WeightsDataValue, "None", py::arg("num"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("NbWeightsData", (Standard_Integer (StepGeom_BezierCurveAndRationalBSplineCurve::*)() const) &StepGeom_BezierCurveAndRationalBSplineCurve::NbWeightsData, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_BezierCurveAndRationalBSplineCurve::get_type_name, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BezierCurveAndRationalBSplineCurve::get_type_descriptor, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BezierCurveAndRationalBSplineCurve::*)() const) &StepGeom_BezierCurveAndRationalBSplineCurve::DynamicType, "None");

// Enums

}