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
#include <StepBasic_ApplicationContextElement.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_ApplicationContext.hxx>
#include <StepBasic_ProductConceptContext.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductConceptContext(py::module &mod){

py::class_<StepBasic_ProductConceptContext, opencascade::handle<StepBasic_ProductConceptContext>, StepBasic_ApplicationContextElement> cls_StepBasic_ProductConceptContext(mod, "StepBasic_ProductConceptContext", "Representation of STEP entity ProductConceptContext");

// Constructors
cls_StepBasic_ProductConceptContext.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductConceptContext.def("Init", (void (StepBasic_ProductConceptContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ApplicationContext> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductConceptContext::Init, "Initialize all fields (own and inherited)", py::arg("aApplicationContextElement_Name"), py::arg("aApplicationContextElement_FrameOfReference"), py::arg("aMarketSegmentType"));
cls_StepBasic_ProductConceptContext.def("MarketSegmentType", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductConceptContext::*)() const) &StepBasic_ProductConceptContext::MarketSegmentType, "Returns field MarketSegmentType");
cls_StepBasic_ProductConceptContext.def("SetMarketSegmentType", (void (StepBasic_ProductConceptContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductConceptContext::SetMarketSegmentType, "Set field MarketSegmentType", py::arg("MarketSegmentType"));
cls_StepBasic_ProductConceptContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductConceptContext::get_type_name, "None");
cls_StepBasic_ProductConceptContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductConceptContext::get_type_descriptor, "None");
cls_StepBasic_ProductConceptContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductConceptContext::*)() const) &StepBasic_ProductConceptContext::DynamicType, "None");

// Enums

}