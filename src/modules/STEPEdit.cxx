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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Protocol.hxx>
#include <StepData_StepModel.hxx>
#include <IFSelect_Signature.hxx>
#include <IFSelect_SelectSignature.hxx>
#include <STEPEdit_EditContext.hxx>
#include <STEPEdit_EditSDR.hxx>
#include <STEPEdit.hxx>
#include <IFSelect_Editor.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_EditForm.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(STEPEdit, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepData");
py::module::import("OCCT.IFSelect");
py::module::import("OCCT.TCollection");

// CLASS: STEPEDIT
py::class_<STEPEdit> cls_STEPEdit(mod, "STEPEdit", "Provides tools to exploit and edit a set of STEP data : editors, selections ..");

// Methods
// cls_STEPEdit.def_static("operator new_", (void * (*)(size_t)) &STEPEdit::operator new, "None", py::arg("theSize"));
// cls_STEPEdit.def_static("operator delete_", (void (*)(void *)) &STEPEdit::operator delete, "None", py::arg("theAddress"));
// cls_STEPEdit.def_static("operator new[]_", (void * (*)(size_t)) &STEPEdit::operator new[], "None", py::arg("theSize"));
// cls_STEPEdit.def_static("operator delete[]_", (void (*)(void *)) &STEPEdit::operator delete[], "None", py::arg("theAddress"));
// cls_STEPEdit.def_static("operator new_", (void * (*)(size_t, void *)) &STEPEdit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPEdit.def_static("operator delete_", (void (*)(void *, void *)) &STEPEdit::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPEdit.def_static("Protocol_", (opencascade::handle<Interface_Protocol> (*)()) &STEPEdit::Protocol, "Returns a Protocol fit for STEP (creates the first time)");
cls_STEPEdit.def_static("NewModel_", (opencascade::handle<StepData_StepModel> (*)()) &STEPEdit::NewModel, "Returns a new empty StepModel fit for STEP i.e. with its header determined from Protocol");
cls_STEPEdit.def_static("SignType_", (opencascade::handle<IFSelect_Signature> (*)()) &STEPEdit::SignType, "Returns a SignType fit for STEP (creates the first time)");
cls_STEPEdit.def_static("NewSelectSDR_", (opencascade::handle<IFSelect_SelectSignature> (*)()) &STEPEdit::NewSelectSDR, "Creates a Selection for ShapeDefinitionRepresentation By default searches among root entities");
cls_STEPEdit.def_static("NewSelectPlacedItem_", (opencascade::handle<IFSelect_SelectSignature> (*)()) &STEPEdit::NewSelectPlacedItem, "Creates a Selection for Placed Items, i.e. MappedItem or ContextDependentShapeRepresentation, which itself refers to a RepresentationRelationship with possible subtypes (Shape... and/or ...WithTransformation) By default in the whole StepModel");
cls_STEPEdit.def_static("NewSelectShapeRepr_", (opencascade::handle<IFSelect_SelectSignature> (*)()) &STEPEdit::NewSelectShapeRepr, "Creates a Selection for ShapeRepresentation and its sub-types, plus ContextDependentShapeRepresentation (which is not a sub-type of ShapeRepresentation) By default in the whole StepModel");

// CLASS: STEPEDIT_EDITCONTEXT
py::class_<STEPEdit_EditContext, opencascade::handle<STEPEdit_EditContext>, IFSelect_Editor> cls_STEPEdit_EditContext(mod, "STEPEdit_EditContext", "EditContext is an Editor fit for Product Definition Context (one per Model) , i.e. : - ProductDefinition - ApplicationProtocolDefinition - ProductRelatedProductCategory");

// Constructors
cls_STEPEdit_EditContext.def(py::init<>());

// Methods
cls_STEPEdit_EditContext.def("Label", (TCollection_AsciiString (STEPEdit_EditContext::*)() const) &STEPEdit_EditContext::Label, "None");
cls_STEPEdit_EditContext.def("Recognize", (Standard_Boolean (STEPEdit_EditContext::*)(const opencascade::handle<IFSelect_EditForm> &) const) &STEPEdit_EditContext::Recognize, "None", py::arg("form"));
cls_STEPEdit_EditContext.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (STEPEdit_EditContext::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &STEPEdit_EditContext::StringValue, "None", py::arg("form"), py::arg("num"));
cls_STEPEdit_EditContext.def("Apply", (Standard_Boolean (STEPEdit_EditContext::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &STEPEdit_EditContext::Apply, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_STEPEdit_EditContext.def("Load", (Standard_Boolean (STEPEdit_EditContext::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &STEPEdit_EditContext::Load, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_STEPEdit_EditContext.def_static("get_type_name_", (const char * (*)()) &STEPEdit_EditContext::get_type_name, "None");
cls_STEPEdit_EditContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPEdit_EditContext::get_type_descriptor, "None");
cls_STEPEdit_EditContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPEdit_EditContext::*)() const) &STEPEdit_EditContext::DynamicType, "None");

// CLASS: STEPEDIT_EDITSDR
py::class_<STEPEdit_EditSDR, opencascade::handle<STEPEdit_EditSDR>, IFSelect_Editor> cls_STEPEdit_EditSDR(mod, "STEPEdit_EditSDR", "EditSDR is an Editor fit for a Shape Definition Representation which designates a Product Definition");

// Constructors
cls_STEPEdit_EditSDR.def(py::init<>());

// Methods
cls_STEPEdit_EditSDR.def("Label", (TCollection_AsciiString (STEPEdit_EditSDR::*)() const) &STEPEdit_EditSDR::Label, "None");
cls_STEPEdit_EditSDR.def("Recognize", (Standard_Boolean (STEPEdit_EditSDR::*)(const opencascade::handle<IFSelect_EditForm> &) const) &STEPEdit_EditSDR::Recognize, "None", py::arg("form"));
cls_STEPEdit_EditSDR.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (STEPEdit_EditSDR::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &STEPEdit_EditSDR::StringValue, "None", py::arg("form"), py::arg("num"));
cls_STEPEdit_EditSDR.def("Apply", (Standard_Boolean (STEPEdit_EditSDR::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &STEPEdit_EditSDR::Apply, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_STEPEdit_EditSDR.def("Load", (Standard_Boolean (STEPEdit_EditSDR::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &STEPEdit_EditSDR::Load, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_STEPEdit_EditSDR.def_static("get_type_name_", (const char * (*)()) &STEPEdit_EditSDR::get_type_name, "None");
cls_STEPEdit_EditSDR.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPEdit_EditSDR::get_type_descriptor, "None");
cls_STEPEdit_EditSDR.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPEdit_EditSDR::*)() const) &STEPEdit_EditSDR::DynamicType, "None");


}
