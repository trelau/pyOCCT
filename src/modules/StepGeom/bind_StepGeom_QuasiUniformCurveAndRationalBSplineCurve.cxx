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
#include <StepGeom_QuasiUniformCurve.hxx>
#include <StepGeom_RationalBSplineCurve.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepGeom_QuasiUniformCurveAndRationalBSplineCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_QuasiUniformCurveAndRationalBSplineCurve(py::module &mod){

py::class_<StepGeom_QuasiUniformCurveAndRationalBSplineCurve, opencascade::handle<StepGeom_QuasiUniformCurveAndRationalBSplineCurve>, StepGeom_BSplineCurve> cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve(mod, "StepGeom_QuasiUniformCurveAndRationalBSplineCurve", "None");

// Constructors
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_QuasiUniformCurve> &, const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aQuasiUniformCurve"), py::arg("aRationalBSplineCurve"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("SetQuasiUniformCurve", (void (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_QuasiUniformCurve> &)) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::SetQuasiUniformCurve, "None", py::arg("aQuasiUniformCurve"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("QuasiUniformCurve", (opencascade::handle<StepGeom_QuasiUniformCurve> (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::QuasiUniformCurve, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("SetRationalBSplineCurve", (void (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::SetRationalBSplineCurve, "None", py::arg("aRationalBSplineCurve"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("RationalBSplineCurve", (opencascade::handle<StepGeom_RationalBSplineCurve> (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::RationalBSplineCurve, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("SetWeightsData", (void (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("WeightsData", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::WeightsData, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("WeightsDataValue", (Standard_Real (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::WeightsDataValue, "None", py::arg("num"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("NbWeightsData", (Standard_Integer (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::NbWeightsData, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::get_type_name, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::get_type_descriptor, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::DynamicType, "None");

// Enums

}