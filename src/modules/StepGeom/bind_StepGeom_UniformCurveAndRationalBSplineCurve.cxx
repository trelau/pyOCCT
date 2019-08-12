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
#include <StepGeom_UniformCurve.hxx>
#include <StepGeom_RationalBSplineCurve.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepGeom_UniformCurveAndRationalBSplineCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_UniformCurveAndRationalBSplineCurve(py::module &mod){

py::class_<StepGeom_UniformCurveAndRationalBSplineCurve, opencascade::handle<StepGeom_UniformCurveAndRationalBSplineCurve>, StepGeom_BSplineCurve> cls_StepGeom_UniformCurveAndRationalBSplineCurve(mod, "StepGeom_UniformCurveAndRationalBSplineCurve", "None");

// Constructors
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_UniformCurve> &, const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_UniformCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aUniformCurve"), py::arg("aRationalBSplineCurve"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_UniformCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("SetUniformCurve", (void (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_UniformCurve> &)) &StepGeom_UniformCurveAndRationalBSplineCurve::SetUniformCurve, "None", py::arg("aUniformCurve"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("UniformCurve", (opencascade::handle<StepGeom_UniformCurve> (StepGeom_UniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_UniformCurveAndRationalBSplineCurve::UniformCurve, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("SetRationalBSplineCurve", (void (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_UniformCurveAndRationalBSplineCurve::SetRationalBSplineCurve, "None", py::arg("aRationalBSplineCurve"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("RationalBSplineCurve", (opencascade::handle<StepGeom_RationalBSplineCurve> (StepGeom_UniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_UniformCurveAndRationalBSplineCurve::RationalBSplineCurve, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("SetWeightsData", (void (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_UniformCurveAndRationalBSplineCurve::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("WeightsData", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_UniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_UniformCurveAndRationalBSplineCurve::WeightsData, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("WeightsDataValue", (Standard_Real (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_UniformCurveAndRationalBSplineCurve::WeightsDataValue, "None", py::arg("num"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("NbWeightsData", (Standard_Integer (StepGeom_UniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_UniformCurveAndRationalBSplineCurve::NbWeightsData, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_UniformCurveAndRationalBSplineCurve::get_type_name, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_UniformCurveAndRationalBSplineCurve::get_type_descriptor, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_UniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_UniformCurveAndRationalBSplineCurve::DynamicType, "None");

// Enums

}