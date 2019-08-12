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
#include <StepFEA_ElementOrElementGroup.hxx>
#include <Standard_Handle.hxx>
#include <StepElement_AnalysisItemWithinRepresentation.hxx>
#include <StepElement_ElementAspect.hxx>
#include <StepFEA_ElementGeometricRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_ElementGeometricRelationship(py::module &mod){

py::class_<StepFEA_ElementGeometricRelationship, opencascade::handle<StepFEA_ElementGeometricRelationship>, Standard_Transient> cls_StepFEA_ElementGeometricRelationship(mod, "StepFEA_ElementGeometricRelationship", "Representation of STEP entity ElementGeometricRelationship");

// Constructors
cls_StepFEA_ElementGeometricRelationship.def(py::init<>());

// Fields

// Methods
cls_StepFEA_ElementGeometricRelationship.def("Init", (void (StepFEA_ElementGeometricRelationship::*)(const StepFEA_ElementOrElementGroup &, const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &, const StepElement_ElementAspect &)) &StepFEA_ElementGeometricRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aElementRef"), py::arg("aItem"), py::arg("aAspect"));
cls_StepFEA_ElementGeometricRelationship.def("ElementRef", (StepFEA_ElementOrElementGroup (StepFEA_ElementGeometricRelationship::*)() const) &StepFEA_ElementGeometricRelationship::ElementRef, "Returns field ElementRef");
cls_StepFEA_ElementGeometricRelationship.def("SetElementRef", (void (StepFEA_ElementGeometricRelationship::*)(const StepFEA_ElementOrElementGroup &)) &StepFEA_ElementGeometricRelationship::SetElementRef, "Set field ElementRef", py::arg("ElementRef"));
cls_StepFEA_ElementGeometricRelationship.def("Item", (opencascade::handle<StepElement_AnalysisItemWithinRepresentation> (StepFEA_ElementGeometricRelationship::*)() const) &StepFEA_ElementGeometricRelationship::Item, "Returns field Item");
cls_StepFEA_ElementGeometricRelationship.def("SetItem", (void (StepFEA_ElementGeometricRelationship::*)(const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &)) &StepFEA_ElementGeometricRelationship::SetItem, "Set field Item", py::arg("Item"));
cls_StepFEA_ElementGeometricRelationship.def("Aspect", (StepElement_ElementAspect (StepFEA_ElementGeometricRelationship::*)() const) &StepFEA_ElementGeometricRelationship::Aspect, "Returns field Aspect");
cls_StepFEA_ElementGeometricRelationship.def("SetAspect", (void (StepFEA_ElementGeometricRelationship::*)(const StepElement_ElementAspect &)) &StepFEA_ElementGeometricRelationship::SetAspect, "Set field Aspect", py::arg("Aspect"));
cls_StepFEA_ElementGeometricRelationship.def_static("get_type_name_", (const char * (*)()) &StepFEA_ElementGeometricRelationship::get_type_name, "None");
cls_StepFEA_ElementGeometricRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ElementGeometricRelationship::get_type_descriptor, "None");
cls_StepFEA_ElementGeometricRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ElementGeometricRelationship::*)() const) &StepFEA_ElementGeometricRelationship::DynamicType, "None");

// Enums

}