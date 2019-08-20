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
#include <StepShape_ShapeRepresentation.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_ApplicationContext.hxx>
#include <StepShape_ShapeDefinitionRepresentation.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_ProductContext.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepBasic_ProductRelatedProductCategory.hxx>
#include <STEPConstruct_Part.hxx>

void bind_STEPConstruct_Part(py::module &mod){

py::class_<STEPConstruct_Part, std::unique_ptr<STEPConstruct_Part>> cls_STEPConstruct_Part(mod, "STEPConstruct_Part", "Provides tools for creating STEP structures associated with part (SDR), such as PRODUCT, PDF etc., as requied by current schema Also allows to investigate and modify this data");

// Constructors
cls_STEPConstruct_Part.def(py::init<>());

// Fields

// Methods
// cls_STEPConstruct_Part.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_Part::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_Part.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_Part::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_Part.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_Part::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_Part.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_Part::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_Part.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_Part::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_Part.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_Part::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_Part.def("MakeSDR", (void (STEPConstruct_Part::*)(const opencascade::handle<StepShape_ShapeRepresentation> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ApplicationContext> &)) &STEPConstruct_Part::MakeSDR, "None", py::arg("aShape"), py::arg("aName"), py::arg("AC"));
cls_STEPConstruct_Part.def("ReadSDR", (void (STEPConstruct_Part::*)(const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &)) &STEPConstruct_Part::ReadSDR, "None", py::arg("aShape"));
cls_STEPConstruct_Part.def("IsDone", (Standard_Boolean (STEPConstruct_Part::*)() const) &STEPConstruct_Part::IsDone, "None");
cls_STEPConstruct_Part.def("SDRValue", (opencascade::handle<StepShape_ShapeDefinitionRepresentation> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::SDRValue, "Returns SDR or Null if not done");
cls_STEPConstruct_Part.def("SRValue", (opencascade::handle<StepShape_ShapeRepresentation> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::SRValue, "Returns SDR->UsedRepresentation() or Null if not done");
cls_STEPConstruct_Part.def("PC", (opencascade::handle<StepBasic_ProductContext> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PC, "None");
cls_STEPConstruct_Part.def("PCname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PCname, "None");
cls_STEPConstruct_Part.def("PCdisciplineType", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PCdisciplineType, "None");
cls_STEPConstruct_Part.def("SetPCname", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPCname, "None", py::arg("name"));
cls_STEPConstruct_Part.def("SetPCdisciplineType", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPCdisciplineType, "None", py::arg("label"));
cls_STEPConstruct_Part.def("AC", (opencascade::handle<StepBasic_ApplicationContext> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::AC, "None");
cls_STEPConstruct_Part.def("ACapplication", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::ACapplication, "None");
cls_STEPConstruct_Part.def("SetACapplication", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetACapplication, "None", py::arg("text"));
cls_STEPConstruct_Part.def("PDC", (opencascade::handle<StepBasic_ProductDefinitionContext> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDC, "None");
cls_STEPConstruct_Part.def("PDCname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDCname, "None");
cls_STEPConstruct_Part.def("PDCstage", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDCstage, "None");
cls_STEPConstruct_Part.def("SetPDCname", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDCname, "None", py::arg("label"));
cls_STEPConstruct_Part.def("SetPDCstage", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDCstage, "None", py::arg("label"));
cls_STEPConstruct_Part.def("Product", (opencascade::handle<StepBasic_Product> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::Product, "None");
cls_STEPConstruct_Part.def("Pid", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::Pid, "None");
cls_STEPConstruct_Part.def("Pname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::Pname, "None");
cls_STEPConstruct_Part.def("Pdescription", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::Pdescription, "None");
cls_STEPConstruct_Part.def("SetPid", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPid, "None", py::arg("id"));
cls_STEPConstruct_Part.def("SetPname", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPname, "None", py::arg("label"));
cls_STEPConstruct_Part.def("SetPdescription", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPdescription, "None", py::arg("text"));
cls_STEPConstruct_Part.def("PDF", (opencascade::handle<StepBasic_ProductDefinitionFormation> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDF, "None");
cls_STEPConstruct_Part.def("PDFid", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDFid, "None");
cls_STEPConstruct_Part.def("PDFdescription", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDFdescription, "None");
cls_STEPConstruct_Part.def("SetPDFid", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDFid, "None", py::arg("id"));
cls_STEPConstruct_Part.def("SetPDFdescription", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDFdescription, "None", py::arg("text"));
cls_STEPConstruct_Part.def("PD", (opencascade::handle<StepBasic_ProductDefinition> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PD, "None");
cls_STEPConstruct_Part.def("PDdescription", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDdescription, "None");
cls_STEPConstruct_Part.def("SetPDdescription", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDdescription, "None", py::arg("text"));
cls_STEPConstruct_Part.def("PDS", (opencascade::handle<StepRepr_ProductDefinitionShape> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDS, "None");
cls_STEPConstruct_Part.def("PDSname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDSname, "None");
cls_STEPConstruct_Part.def("PDSdescription", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDSdescription, "None");
cls_STEPConstruct_Part.def("SetPDSname", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDSname, "None", py::arg("label"));
cls_STEPConstruct_Part.def("SetPDSdescription", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDSdescription, "None", py::arg("text"));
cls_STEPConstruct_Part.def("PRPC", (opencascade::handle<StepBasic_ProductRelatedProductCategory> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PRPC, "None");
cls_STEPConstruct_Part.def("PRPCname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PRPCname, "None");
cls_STEPConstruct_Part.def("PRPCdescription", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PRPCdescription, "None");
cls_STEPConstruct_Part.def("SetPRPCname", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPRPCname, "None", py::arg("label"));
cls_STEPConstruct_Part.def("SetPRPCdescription", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPRPCdescription, "None", py::arg("text"));

// Enums

}