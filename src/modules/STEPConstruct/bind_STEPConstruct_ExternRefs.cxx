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
#include <STEPConstruct_Tool.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_ApplicationProtocolDefinition.hxx>
#include <StepAP214_AppliedDocumentReference.hxx>
#include <StepBasic_DocumentFile.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <StepBasic_ProductRelatedProductCategory.hxx>
#include <StepBasic_DocumentType.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <StepBasic_ProductContext.hxx>
#include <STEPConstruct_ExternRefs.hxx>

void bind_STEPConstruct_ExternRefs(py::module &mod){

py::class_<STEPConstruct_ExternRefs, std::unique_ptr<STEPConstruct_ExternRefs>, STEPConstruct_Tool> cls_STEPConstruct_ExternRefs(mod, "STEPConstruct_ExternRefs", "Provides a tool for analyzing (reading) and creating (writing) references to external files in STEP");

// Constructors
cls_STEPConstruct_ExternRefs.def(py::init<>());
cls_STEPConstruct_ExternRefs.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));

// Fields

// Methods
// cls_STEPConstruct_ExternRefs.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_ExternRefs::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_ExternRefs.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_ExternRefs::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_ExternRefs.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_ExternRefs::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_ExternRefs.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_ExternRefs::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_ExternRefs.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_ExternRefs::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_ExternRefs.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_ExternRefs::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_ExternRefs.def("Init", (Standard_Boolean (STEPConstruct_ExternRefs::*)(const opencascade::handle<XSControl_WorkSession> &)) &STEPConstruct_ExternRefs::Init, "Initializes tool; returns True if succeeded", py::arg("WS"));
cls_STEPConstruct_ExternRefs.def("Clear", (void (STEPConstruct_ExternRefs::*)()) &STEPConstruct_ExternRefs::Clear, "Clears internal fields (list of defined extern refs)");
cls_STEPConstruct_ExternRefs.def("LoadExternRefs", (Standard_Boolean (STEPConstruct_ExternRefs::*)()) &STEPConstruct_ExternRefs::LoadExternRefs, "Searches current STEP model for external references and loads them to the internal data structures NOTE: does not clear data structures before loading");
cls_STEPConstruct_ExternRefs.def("NbExternRefs", (Standard_Integer (STEPConstruct_ExternRefs::*)() const) &STEPConstruct_ExternRefs::NbExternRefs, "Returns number of defined extern references");
cls_STEPConstruct_ExternRefs.def("FileName", (Standard_CString (STEPConstruct_ExternRefs::*)(const Standard_Integer) const) &STEPConstruct_ExternRefs::FileName, "Returns filename for numth extern reference Returns Null if FileName is not defined or bad", py::arg("num"));
cls_STEPConstruct_ExternRefs.def("ProdDef", (opencascade::handle<StepBasic_ProductDefinition> (STEPConstruct_ExternRefs::*)(const Standard_Integer) const) &STEPConstruct_ExternRefs::ProdDef, "Returns ProductDefinition to which numth extern reference is associated. Returns Null if cannot be detected or if extern reference is not associated to SDR in a proper way.", py::arg("num"));
cls_STEPConstruct_ExternRefs.def("Format", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_ExternRefs::*)(const Standard_Integer) const) &STEPConstruct_ExternRefs::Format, "Returns format identification string for the extern document Returns Null handle if format is not defined", py::arg("num"));
cls_STEPConstruct_ExternRefs.def("AddExternRef", (Standard_Integer (STEPConstruct_ExternRefs::*)(const Standard_CString, const opencascade::handle<StepBasic_ProductDefinition> &, const Standard_CString)) &STEPConstruct_ExternRefs::AddExternRef, "Create a new external reference with specified attributes attached to a given SDR <format> can be Null string, in that case this information is not written. Else, it can be 'STEP AP214' or 'STEP AP203' Returns index of a new extern ref", py::arg("filename"), py::arg("PD"), py::arg("format"));
cls_STEPConstruct_ExternRefs.def("checkAP214Shared", (void (STEPConstruct_ExternRefs::*)()) &STEPConstruct_ExternRefs::checkAP214Shared, "Check (create if it is null) all shared entities for the model");
cls_STEPConstruct_ExternRefs.def("WriteExternRefs", (Standard_Integer (STEPConstruct_ExternRefs::*)(const Standard_Integer) const) &STEPConstruct_ExternRefs::WriteExternRefs, "Adds all the currently defined external refs to the model Returns number of written extern refs", py::arg("num"));
cls_STEPConstruct_ExternRefs.def("SetAP214APD", (void (STEPConstruct_ExternRefs::*)(const opencascade::handle<StepBasic_ApplicationProtocolDefinition> &)) &STEPConstruct_ExternRefs::SetAP214APD, "Set the ApplicationProtocolDefinition of the PDM schema", py::arg("APD"));
cls_STEPConstruct_ExternRefs.def("GetAP214APD", (opencascade::handle<StepBasic_ApplicationProtocolDefinition> (STEPConstruct_ExternRefs::*)()) &STEPConstruct_ExternRefs::GetAP214APD, "Returns the ApplicationProtocolDefinition of the PDM schema NOTE: if not defined then create new APD with new Application Context");

// Enums

}