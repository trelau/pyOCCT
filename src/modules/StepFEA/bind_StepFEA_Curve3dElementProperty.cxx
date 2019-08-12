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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepFEA_HArray1OfCurveElementInterval.hxx>
#include <StepFEA_HArray1OfCurveElementEndOffset.hxx>
#include <StepFEA_HArray1OfCurveElementEndRelease.hxx>
#include <StepFEA_Curve3dElementProperty.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_Curve3dElementProperty(py::module &mod){

py::class_<StepFEA_Curve3dElementProperty, opencascade::handle<StepFEA_Curve3dElementProperty>, Standard_Transient> cls_StepFEA_Curve3dElementProperty(mod, "StepFEA_Curve3dElementProperty", "Representation of STEP entity Curve3dElementProperty");

// Constructors
cls_StepFEA_Curve3dElementProperty.def(py::init<>());

// Fields

// Methods
cls_StepFEA_Curve3dElementProperty.def("Init", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_HArray1OfCurveElementInterval> &, const opencascade::handle<StepFEA_HArray1OfCurveElementEndOffset> &, const opencascade::handle<StepFEA_HArray1OfCurveElementEndRelease> &)) &StepFEA_Curve3dElementProperty::Init, "Initialize all fields (own and inherited)", py::arg("aPropertyId"), py::arg("aDescription"), py::arg("aIntervalDefinitions"), py::arg("aEndOffsets"), py::arg("aEndReleases"));
cls_StepFEA_Curve3dElementProperty.def("PropertyId", (opencascade::handle<TCollection_HAsciiString> (StepFEA_Curve3dElementProperty::*)() const) &StepFEA_Curve3dElementProperty::PropertyId, "Returns field PropertyId");
cls_StepFEA_Curve3dElementProperty.def("SetPropertyId", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_Curve3dElementProperty::SetPropertyId, "Set field PropertyId", py::arg("PropertyId"));
cls_StepFEA_Curve3dElementProperty.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepFEA_Curve3dElementProperty::*)() const) &StepFEA_Curve3dElementProperty::Description, "Returns field Description");
cls_StepFEA_Curve3dElementProperty.def("SetDescription", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_Curve3dElementProperty::SetDescription, "Set field Description", py::arg("Description"));
cls_StepFEA_Curve3dElementProperty.def("IntervalDefinitions", (opencascade::handle<StepFEA_HArray1OfCurveElementInterval> (StepFEA_Curve3dElementProperty::*)() const) &StepFEA_Curve3dElementProperty::IntervalDefinitions, "Returns field IntervalDefinitions");
cls_StepFEA_Curve3dElementProperty.def("SetIntervalDefinitions", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<StepFEA_HArray1OfCurveElementInterval> &)) &StepFEA_Curve3dElementProperty::SetIntervalDefinitions, "Set field IntervalDefinitions", py::arg("IntervalDefinitions"));
cls_StepFEA_Curve3dElementProperty.def("EndOffsets", (opencascade::handle<StepFEA_HArray1OfCurveElementEndOffset> (StepFEA_Curve3dElementProperty::*)() const) &StepFEA_Curve3dElementProperty::EndOffsets, "Returns field EndOffsets");
cls_StepFEA_Curve3dElementProperty.def("SetEndOffsets", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<StepFEA_HArray1OfCurveElementEndOffset> &)) &StepFEA_Curve3dElementProperty::SetEndOffsets, "Set field EndOffsets", py::arg("EndOffsets"));
cls_StepFEA_Curve3dElementProperty.def("EndReleases", (opencascade::handle<StepFEA_HArray1OfCurveElementEndRelease> (StepFEA_Curve3dElementProperty::*)() const) &StepFEA_Curve3dElementProperty::EndReleases, "Returns field EndReleases");
cls_StepFEA_Curve3dElementProperty.def("SetEndReleases", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<StepFEA_HArray1OfCurveElementEndRelease> &)) &StepFEA_Curve3dElementProperty::SetEndReleases, "Set field EndReleases", py::arg("EndReleases"));
cls_StepFEA_Curve3dElementProperty.def_static("get_type_name_", (const char * (*)()) &StepFEA_Curve3dElementProperty::get_type_name, "None");
cls_StepFEA_Curve3dElementProperty.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_Curve3dElementProperty::get_type_descriptor, "None");
cls_StepFEA_Curve3dElementProperty.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_Curve3dElementProperty::*)() const) &StepFEA_Curve3dElementProperty::DynamicType, "None");

// Enums

}