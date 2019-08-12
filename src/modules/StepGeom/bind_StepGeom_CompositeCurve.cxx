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
#include <StepGeom_HArray1OfCompositeCurveSegment.hxx>
#include <StepData_Logical.hxx>
#include <StepGeom_CompositeCurveSegment.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_CompositeCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_CompositeCurve(py::module &mod){

py::class_<StepGeom_CompositeCurve, opencascade::handle<StepGeom_CompositeCurve>, StepGeom_BoundedCurve> cls_StepGeom_CompositeCurve(mod, "StepGeom_CompositeCurve", "None");

// Constructors
cls_StepGeom_CompositeCurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_CompositeCurve.def("Init", (void (StepGeom_CompositeCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_HArray1OfCompositeCurveSegment> &, const StepData_Logical)) &StepGeom_CompositeCurve::Init, "None", py::arg("aName"), py::arg("aSegments"), py::arg("aSelfIntersect"));
cls_StepGeom_CompositeCurve.def("SetSegments", (void (StepGeom_CompositeCurve::*)(const opencascade::handle<StepGeom_HArray1OfCompositeCurveSegment> &)) &StepGeom_CompositeCurve::SetSegments, "None", py::arg("aSegments"));
cls_StepGeom_CompositeCurve.def("Segments", (opencascade::handle<StepGeom_HArray1OfCompositeCurveSegment> (StepGeom_CompositeCurve::*)() const) &StepGeom_CompositeCurve::Segments, "None");
cls_StepGeom_CompositeCurve.def("SegmentsValue", (opencascade::handle<StepGeom_CompositeCurveSegment> (StepGeom_CompositeCurve::*)(const Standard_Integer) const) &StepGeom_CompositeCurve::SegmentsValue, "None", py::arg("num"));
cls_StepGeom_CompositeCurve.def("NbSegments", (Standard_Integer (StepGeom_CompositeCurve::*)() const) &StepGeom_CompositeCurve::NbSegments, "None");
cls_StepGeom_CompositeCurve.def("SetSelfIntersect", (void (StepGeom_CompositeCurve::*)(const StepData_Logical)) &StepGeom_CompositeCurve::SetSelfIntersect, "None", py::arg("aSelfIntersect"));
cls_StepGeom_CompositeCurve.def("SelfIntersect", (StepData_Logical (StepGeom_CompositeCurve::*)() const) &StepGeom_CompositeCurve::SelfIntersect, "None");
cls_StepGeom_CompositeCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_CompositeCurve::get_type_name, "None");
cls_StepGeom_CompositeCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CompositeCurve::get_type_descriptor, "None");
cls_StepGeom_CompositeCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CompositeCurve::*)() const) &StepGeom_CompositeCurve::DynamicType, "None");

// Enums

}