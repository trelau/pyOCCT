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
#include <TColStd_HArray1OfReal.hxx>
#include <StepGeom_RationalBSplineCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_RationalBSplineCurve(py::module &mod){

py::class_<StepGeom_RationalBSplineCurve, opencascade::handle<StepGeom_RationalBSplineCurve>, StepGeom_BSplineCurve> cls_StepGeom_RationalBSplineCurve(mod, "StepGeom_RationalBSplineCurve", "None");

// Constructors
cls_StepGeom_RationalBSplineCurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_RationalBSplineCurve.def("Init", (void (StepGeom_RationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_RationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_RationalBSplineCurve.def("SetWeightsData", (void (StepGeom_RationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_RationalBSplineCurve::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_RationalBSplineCurve.def("WeightsData", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_RationalBSplineCurve::*)() const) &StepGeom_RationalBSplineCurve::WeightsData, "None");
cls_StepGeom_RationalBSplineCurve.def("WeightsDataValue", (Standard_Real (StepGeom_RationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_RationalBSplineCurve::WeightsDataValue, "None", py::arg("num"));
cls_StepGeom_RationalBSplineCurve.def("NbWeightsData", (Standard_Integer (StepGeom_RationalBSplineCurve::*)() const) &StepGeom_RationalBSplineCurve::NbWeightsData, "None");
cls_StepGeom_RationalBSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_RationalBSplineCurve::get_type_name, "None");
cls_StepGeom_RationalBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_RationalBSplineCurve::get_type_descriptor, "None");
cls_StepGeom_RationalBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_RationalBSplineCurve::*)() const) &StepGeom_RationalBSplineCurve::DynamicType, "None");

// Enums

}