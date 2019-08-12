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
#include <StepRepr_RepresentationItem.hxx>
#include <StepRepr_Representation.hxx>
#include <StepElement_AnalysisItemWithinRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_AnalysisItemWithinRepresentation(py::module &mod){

py::class_<StepElement_AnalysisItemWithinRepresentation, opencascade::handle<StepElement_AnalysisItemWithinRepresentation>, Standard_Transient> cls_StepElement_AnalysisItemWithinRepresentation(mod, "StepElement_AnalysisItemWithinRepresentation", "Representation of STEP entity AnalysisItemWithinRepresentation");

// Constructors
cls_StepElement_AnalysisItemWithinRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepElement_AnalysisItemWithinRepresentation.def("Init", (void (StepElement_AnalysisItemWithinRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepRepr_Representation> &)) &StepElement_AnalysisItemWithinRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("aDescription"), py::arg("aItem"), py::arg("aRep"));
cls_StepElement_AnalysisItemWithinRepresentation.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepElement_AnalysisItemWithinRepresentation::*)() const) &StepElement_AnalysisItemWithinRepresentation::Name, "Returns field Name");
cls_StepElement_AnalysisItemWithinRepresentation.def("SetName", (void (StepElement_AnalysisItemWithinRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_AnalysisItemWithinRepresentation::SetName, "Set field Name", py::arg("Name"));
cls_StepElement_AnalysisItemWithinRepresentation.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepElement_AnalysisItemWithinRepresentation::*)() const) &StepElement_AnalysisItemWithinRepresentation::Description, "Returns field Description");
cls_StepElement_AnalysisItemWithinRepresentation.def("SetDescription", (void (StepElement_AnalysisItemWithinRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_AnalysisItemWithinRepresentation::SetDescription, "Set field Description", py::arg("Description"));
cls_StepElement_AnalysisItemWithinRepresentation.def("Item", (opencascade::handle<StepRepr_RepresentationItem> (StepElement_AnalysisItemWithinRepresentation::*)() const) &StepElement_AnalysisItemWithinRepresentation::Item, "Returns field Item");
cls_StepElement_AnalysisItemWithinRepresentation.def("SetItem", (void (StepElement_AnalysisItemWithinRepresentation::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepElement_AnalysisItemWithinRepresentation::SetItem, "Set field Item", py::arg("Item"));
cls_StepElement_AnalysisItemWithinRepresentation.def("Rep", (opencascade::handle<StepRepr_Representation> (StepElement_AnalysisItemWithinRepresentation::*)() const) &StepElement_AnalysisItemWithinRepresentation::Rep, "Returns field Rep");
cls_StepElement_AnalysisItemWithinRepresentation.def("SetRep", (void (StepElement_AnalysisItemWithinRepresentation::*)(const opencascade::handle<StepRepr_Representation> &)) &StepElement_AnalysisItemWithinRepresentation::SetRep, "Set field Rep", py::arg("Rep"));
cls_StepElement_AnalysisItemWithinRepresentation.def_static("get_type_name_", (const char * (*)()) &StepElement_AnalysisItemWithinRepresentation::get_type_name, "None");
cls_StepElement_AnalysisItemWithinRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_AnalysisItemWithinRepresentation::get_type_descriptor, "None");
cls_StepElement_AnalysisItemWithinRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_AnalysisItemWithinRepresentation::*)() const) &StepElement_AnalysisItemWithinRepresentation::DynamicType, "None");

// Enums

}