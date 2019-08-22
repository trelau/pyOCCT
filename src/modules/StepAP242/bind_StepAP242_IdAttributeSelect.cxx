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
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepBasic_Action.hxx>
#include <StepBasic_Address.hxx>
#include <StepBasic_ApplicationContext.hxx>
#include <StepShape_DimensionalSize.hxx>
#include <StepDimTol_GeometricTolerance.hxx>
#include <StepBasic_Group.hxx>
#include <StepBasic_ProductCategory.hxx>
#include <StepRepr_PropertyDefinition.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <StepAP242_IdAttributeSelect.hxx>

void bind_StepAP242_IdAttributeSelect(py::module &mod){

py::class_<StepAP242_IdAttributeSelect, StepData_SelectType> cls_StepAP242_IdAttributeSelect(mod, "StepAP242_IdAttributeSelect", "None");

// Constructors
cls_StepAP242_IdAttributeSelect.def(py::init<>());

// Fields

// Methods
// cls_StepAP242_IdAttributeSelect.def_static("operator new_", (void * (*)(size_t)) &StepAP242_IdAttributeSelect::operator new, "None", py::arg("theSize"));
// cls_StepAP242_IdAttributeSelect.def_static("operator delete_", (void (*)(void *)) &StepAP242_IdAttributeSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepAP242_IdAttributeSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepAP242_IdAttributeSelect::operator new[], "None", py::arg("theSize"));
// cls_StepAP242_IdAttributeSelect.def_static("operator delete[]_", (void (*)(void *)) &StepAP242_IdAttributeSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP242_IdAttributeSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP242_IdAttributeSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP242_IdAttributeSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepAP242_IdAttributeSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP242_IdAttributeSelect.def("CaseNum", (Standard_Integer (StepAP242_IdAttributeSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP242_IdAttributeSelect::CaseNum, "Recognizes a IdAttributeSelect Kind Entity that is : 1 -> Action 2 -> Address 3 -> ApplicationContext 4 -> DimensionalSize 5 -> GeometricTolerance 6 -> Group 7 -> Reserved for OrganizatonalProject (not implemented in OCCT) 8 -> ProductCategory 9 -> PropertyDefinition 10 -> Representation 11 -> ShapeAspect 12 -> ShapeAspectRelationship 0 else", py::arg("ent"));
cls_StepAP242_IdAttributeSelect.def("Action", (opencascade::handle<StepBasic_Action> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::Action, "returns Value as a Action (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("Address", (opencascade::handle<StepBasic_Address> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::Address, "returns Value as a Address (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("ApplicationContext", (opencascade::handle<StepBasic_ApplicationContext> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::ApplicationContext, "returns Value as a ApplicationContext (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("DimensionalSize", (opencascade::handle<StepShape_DimensionalSize> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::DimensionalSize, "returns Value as a DimensionalSize (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("GeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::GeometricTolerance, "returns Value as a GeometricTolerance (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("Group", (opencascade::handle<StepBasic_Group> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::Group, "returns Value as a Group (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("ProductCategory", (opencascade::handle<StepBasic_ProductCategory> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::ProductCategory, "returns Value as a ProductCategory (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("PropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::PropertyDefinition, "returns Value as a PropertyDefinition (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("Representation", (opencascade::handle<StepRepr_Representation> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::Representation, "returns Value as a Representation (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::ShapeAspectRelationship, "returns Value as a ShapeAspectRelationship (Null if another type)");

// Enums

}