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
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepGeom_KnotType.hxx>
#include <StepGeom_BSplineCurveWithKnots.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_BSplineCurveWithKnots(py::module &mod){

py::class_<StepGeom_BSplineCurveWithKnots, opencascade::handle<StepGeom_BSplineCurveWithKnots>, StepGeom_BSplineCurve> cls_StepGeom_BSplineCurveWithKnots(mod, "StepGeom_BSplineCurveWithKnots", "None");

// Constructors
cls_StepGeom_BSplineCurveWithKnots.def(py::init<>());

// Fields

// Methods
cls_StepGeom_BSplineCurveWithKnots.def("Init", (void (StepGeom_BSplineCurveWithKnots::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const StepGeom_KnotType)) &StepGeom_BSplineCurveWithKnots::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aKnotMultiplicities"), py::arg("aKnots"), py::arg("aKnotSpec"));
cls_StepGeom_BSplineCurveWithKnots.def("SetKnotMultiplicities", (void (StepGeom_BSplineCurveWithKnots::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineCurveWithKnots::SetKnotMultiplicities, "None", py::arg("aKnotMultiplicities"));
cls_StepGeom_BSplineCurveWithKnots.def("KnotMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::KnotMultiplicities, "None");
cls_StepGeom_BSplineCurveWithKnots.def("KnotMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineCurveWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineCurveWithKnots::KnotMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurveWithKnots.def("NbKnotMultiplicities", (Standard_Integer (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::NbKnotMultiplicities, "None");
cls_StepGeom_BSplineCurveWithKnots.def("SetKnots", (void (StepGeom_BSplineCurveWithKnots::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineCurveWithKnots::SetKnots, "None", py::arg("aKnots"));
cls_StepGeom_BSplineCurveWithKnots.def("Knots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::Knots, "None");
cls_StepGeom_BSplineCurveWithKnots.def("KnotsValue", (Standard_Real (StepGeom_BSplineCurveWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineCurveWithKnots::KnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurveWithKnots.def("NbKnots", (Standard_Integer (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::NbKnots, "None");
cls_StepGeom_BSplineCurveWithKnots.def("SetKnotSpec", (void (StepGeom_BSplineCurveWithKnots::*)(const StepGeom_KnotType)) &StepGeom_BSplineCurveWithKnots::SetKnotSpec, "None", py::arg("aKnotSpec"));
cls_StepGeom_BSplineCurveWithKnots.def("KnotSpec", (StepGeom_KnotType (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::KnotSpec, "None");
cls_StepGeom_BSplineCurveWithKnots.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineCurveWithKnots::get_type_name, "None");
cls_StepGeom_BSplineCurveWithKnots.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineCurveWithKnots::get_type_descriptor, "None");
cls_StepGeom_BSplineCurveWithKnots.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::DynamicType, "None");

// Enums

}