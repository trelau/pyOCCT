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
#include <StepShape_ManifoldSolidBrep.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_ClosedShell.hxx>
#include <StepShape_FacetedBrep.hxx>
#include <StepShape_BrepWithVoids.hxx>
#include <StepShape_HArray1OfOrientedClosedShell.hxx>
#include <StepShape_OrientedClosedShell.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_FacetedBrepAndBrepWithVoids.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_FacetedBrepAndBrepWithVoids(py::module &mod){

py::class_<StepShape_FacetedBrepAndBrepWithVoids, opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids>, StepShape_ManifoldSolidBrep> cls_StepShape_FacetedBrepAndBrepWithVoids(mod, "StepShape_FacetedBrepAndBrepWithVoids", "None");

// Constructors
cls_StepShape_FacetedBrepAndBrepWithVoids.def(py::init<>());

// Fields

// Methods
cls_StepShape_FacetedBrepAndBrepWithVoids.def("Init", (void (StepShape_FacetedBrepAndBrepWithVoids::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ClosedShell> &, const opencascade::handle<StepShape_FacetedBrep> &, const opencascade::handle<StepShape_BrepWithVoids> &)) &StepShape_FacetedBrepAndBrepWithVoids::Init, "None", py::arg("aName"), py::arg("aOuter"), py::arg("aFacetedBrep"), py::arg("aBrepWithVoids"));
cls_StepShape_FacetedBrepAndBrepWithVoids.def("Init", (void (StepShape_FacetedBrepAndBrepWithVoids::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ClosedShell> &, const opencascade::handle<StepShape_HArray1OfOrientedClosedShell> &)) &StepShape_FacetedBrepAndBrepWithVoids::Init, "None", py::arg("aName"), py::arg("aOuter"), py::arg("aVoids"));
cls_StepShape_FacetedBrepAndBrepWithVoids.def("SetFacetedBrep", (void (StepShape_FacetedBrepAndBrepWithVoids::*)(const opencascade::handle<StepShape_FacetedBrep> &)) &StepShape_FacetedBrepAndBrepWithVoids::SetFacetedBrep, "None", py::arg("aFacetedBrep"));
cls_StepShape_FacetedBrepAndBrepWithVoids.def("FacetedBrep", (opencascade::handle<StepShape_FacetedBrep> (StepShape_FacetedBrepAndBrepWithVoids::*)() const) &StepShape_FacetedBrepAndBrepWithVoids::FacetedBrep, "None");
cls_StepShape_FacetedBrepAndBrepWithVoids.def("SetBrepWithVoids", (void (StepShape_FacetedBrepAndBrepWithVoids::*)(const opencascade::handle<StepShape_BrepWithVoids> &)) &StepShape_FacetedBrepAndBrepWithVoids::SetBrepWithVoids, "None", py::arg("aBrepWithVoids"));
cls_StepShape_FacetedBrepAndBrepWithVoids.def("BrepWithVoids", (opencascade::handle<StepShape_BrepWithVoids> (StepShape_FacetedBrepAndBrepWithVoids::*)() const) &StepShape_FacetedBrepAndBrepWithVoids::BrepWithVoids, "None");
cls_StepShape_FacetedBrepAndBrepWithVoids.def("SetVoids", (void (StepShape_FacetedBrepAndBrepWithVoids::*)(const opencascade::handle<StepShape_HArray1OfOrientedClosedShell> &)) &StepShape_FacetedBrepAndBrepWithVoids::SetVoids, "None", py::arg("aVoids"));
cls_StepShape_FacetedBrepAndBrepWithVoids.def("Voids", (opencascade::handle<StepShape_HArray1OfOrientedClosedShell> (StepShape_FacetedBrepAndBrepWithVoids::*)() const) &StepShape_FacetedBrepAndBrepWithVoids::Voids, "None");
cls_StepShape_FacetedBrepAndBrepWithVoids.def("VoidsValue", (opencascade::handle<StepShape_OrientedClosedShell> (StepShape_FacetedBrepAndBrepWithVoids::*)(const Standard_Integer) const) &StepShape_FacetedBrepAndBrepWithVoids::VoidsValue, "None", py::arg("num"));
cls_StepShape_FacetedBrepAndBrepWithVoids.def("NbVoids", (Standard_Integer (StepShape_FacetedBrepAndBrepWithVoids::*)() const) &StepShape_FacetedBrepAndBrepWithVoids::NbVoids, "None");
cls_StepShape_FacetedBrepAndBrepWithVoids.def_static("get_type_name_", (const char * (*)()) &StepShape_FacetedBrepAndBrepWithVoids::get_type_name, "None");
cls_StepShape_FacetedBrepAndBrepWithVoids.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_FacetedBrepAndBrepWithVoids::get_type_descriptor, "None");
cls_StepShape_FacetedBrepAndBrepWithVoids.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_FacetedBrepAndBrepWithVoids::*)() const) &StepShape_FacetedBrepAndBrepWithVoids::DynamicType, "None");

// Enums

}