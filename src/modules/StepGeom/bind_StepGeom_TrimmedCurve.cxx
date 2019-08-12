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
#include <StepGeom_Curve.hxx>
#include <StepGeom_HArray1OfTrimmingSelect.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_TrimmingPreference.hxx>
#include <StepGeom_TrimmingSelect.hxx>
#include <StepGeom_TrimmedCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_TrimmedCurve(py::module &mod){

py::class_<StepGeom_TrimmedCurve, opencascade::handle<StepGeom_TrimmedCurve>, StepGeom_BoundedCurve> cls_StepGeom_TrimmedCurve(mod, "StepGeom_TrimmedCurve", "None");

// Constructors
cls_StepGeom_TrimmedCurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_TrimmedCurve.def("Init", (void (StepGeom_TrimmedCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const opencascade::handle<StepGeom_HArray1OfTrimmingSelect> &, const opencascade::handle<StepGeom_HArray1OfTrimmingSelect> &, const Standard_Boolean, const StepGeom_TrimmingPreference)) &StepGeom_TrimmedCurve::Init, "None", py::arg("aName"), py::arg("aBasisCurve"), py::arg("aTrim1"), py::arg("aTrim2"), py::arg("aSenseAgreement"), py::arg("aMasterRepresentation"));
cls_StepGeom_TrimmedCurve.def("SetBasisCurve", (void (StepGeom_TrimmedCurve::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_TrimmedCurve::SetBasisCurve, "None", py::arg("aBasisCurve"));
cls_StepGeom_TrimmedCurve.def("BasisCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::BasisCurve, "None");
cls_StepGeom_TrimmedCurve.def("SetTrim1", (void (StepGeom_TrimmedCurve::*)(const opencascade::handle<StepGeom_HArray1OfTrimmingSelect> &)) &StepGeom_TrimmedCurve::SetTrim1, "None", py::arg("aTrim1"));
cls_StepGeom_TrimmedCurve.def("Trim1", (opencascade::handle<StepGeom_HArray1OfTrimmingSelect> (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::Trim1, "None");
cls_StepGeom_TrimmedCurve.def("Trim1Value", (StepGeom_TrimmingSelect (StepGeom_TrimmedCurve::*)(const Standard_Integer) const) &StepGeom_TrimmedCurve::Trim1Value, "None", py::arg("num"));
cls_StepGeom_TrimmedCurve.def("NbTrim1", (Standard_Integer (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::NbTrim1, "None");
cls_StepGeom_TrimmedCurve.def("SetTrim2", (void (StepGeom_TrimmedCurve::*)(const opencascade::handle<StepGeom_HArray1OfTrimmingSelect> &)) &StepGeom_TrimmedCurve::SetTrim2, "None", py::arg("aTrim2"));
cls_StepGeom_TrimmedCurve.def("Trim2", (opencascade::handle<StepGeom_HArray1OfTrimmingSelect> (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::Trim2, "None");
cls_StepGeom_TrimmedCurve.def("Trim2Value", (StepGeom_TrimmingSelect (StepGeom_TrimmedCurve::*)(const Standard_Integer) const) &StepGeom_TrimmedCurve::Trim2Value, "None", py::arg("num"));
cls_StepGeom_TrimmedCurve.def("NbTrim2", (Standard_Integer (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::NbTrim2, "None");
cls_StepGeom_TrimmedCurve.def("SetSenseAgreement", (void (StepGeom_TrimmedCurve::*)(const Standard_Boolean)) &StepGeom_TrimmedCurve::SetSenseAgreement, "None", py::arg("aSenseAgreement"));
cls_StepGeom_TrimmedCurve.def("SenseAgreement", (Standard_Boolean (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::SenseAgreement, "None");
cls_StepGeom_TrimmedCurve.def("SetMasterRepresentation", (void (StepGeom_TrimmedCurve::*)(const StepGeom_TrimmingPreference)) &StepGeom_TrimmedCurve::SetMasterRepresentation, "None", py::arg("aMasterRepresentation"));
cls_StepGeom_TrimmedCurve.def("MasterRepresentation", (StepGeom_TrimmingPreference (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::MasterRepresentation, "None");
cls_StepGeom_TrimmedCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_TrimmedCurve::get_type_name, "None");
cls_StepGeom_TrimmedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_TrimmedCurve::get_type_descriptor, "None");
cls_StepGeom_TrimmedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::DynamicType, "None");

// Enums

}