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
#include <StepGeom_BoundedCurve.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_HArray1OfCartesianPoint.hxx>
#include <StepGeom_BSplineCurveForm.hxx>
#include <StepData_Logical.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepGeom_BSplineCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_BSplineCurve(py::module &mod){

py::class_<StepGeom_BSplineCurve, opencascade::handle<StepGeom_BSplineCurve>, StepGeom_BoundedCurve> cls_StepGeom_BSplineCurve(mod, "StepGeom_BSplineCurve", "None");

// Constructors
cls_StepGeom_BSplineCurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_BSplineCurve.def("Init", (void (StepGeom_BSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical)) &StepGeom_BSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"));
cls_StepGeom_BSplineCurve.def("SetDegree", (void (StepGeom_BSplineCurve::*)(const Standard_Integer)) &StepGeom_BSplineCurve::SetDegree, "None", py::arg("aDegree"));
cls_StepGeom_BSplineCurve.def("Degree", (Standard_Integer (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::Degree, "None");
cls_StepGeom_BSplineCurve.def("SetControlPointsList", (void (StepGeom_BSplineCurve::*)(const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &)) &StepGeom_BSplineCurve::SetControlPointsList, "None", py::arg("aControlPointsList"));
cls_StepGeom_BSplineCurve.def("ControlPointsList", (opencascade::handle<StepGeom_HArray1OfCartesianPoint> (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::ControlPointsList, "None");
cls_StepGeom_BSplineCurve.def("ControlPointsListValue", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_BSplineCurve::*)(const Standard_Integer) const) &StepGeom_BSplineCurve::ControlPointsListValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurve.def("NbControlPointsList", (Standard_Integer (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::NbControlPointsList, "None");
cls_StepGeom_BSplineCurve.def("SetCurveForm", (void (StepGeom_BSplineCurve::*)(const StepGeom_BSplineCurveForm)) &StepGeom_BSplineCurve::SetCurveForm, "None", py::arg("aCurveForm"));
cls_StepGeom_BSplineCurve.def("CurveForm", (StepGeom_BSplineCurveForm (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::CurveForm, "None");
cls_StepGeom_BSplineCurve.def("SetClosedCurve", (void (StepGeom_BSplineCurve::*)(const StepData_Logical)) &StepGeom_BSplineCurve::SetClosedCurve, "None", py::arg("aClosedCurve"));
cls_StepGeom_BSplineCurve.def("ClosedCurve", (StepData_Logical (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::ClosedCurve, "None");
cls_StepGeom_BSplineCurve.def("SetSelfIntersect", (void (StepGeom_BSplineCurve::*)(const StepData_Logical)) &StepGeom_BSplineCurve::SetSelfIntersect, "None", py::arg("aSelfIntersect"));
cls_StepGeom_BSplineCurve.def("SelfIntersect", (StepData_Logical (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::SelfIntersect, "None");
cls_StepGeom_BSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineCurve::get_type_name, "None");
cls_StepGeom_BSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineCurve::get_type_descriptor, "None");
cls_StepGeom_BSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::DynamicType, "None");

// Enums

}