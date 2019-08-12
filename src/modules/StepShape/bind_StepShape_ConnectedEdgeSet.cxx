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
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_HArray1OfEdge.hxx>
#include <StepShape_ConnectedEdgeSet.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_ConnectedEdgeSet(py::module &mod){

py::class_<StepShape_ConnectedEdgeSet, opencascade::handle<StepShape_ConnectedEdgeSet>, StepShape_TopologicalRepresentationItem> cls_StepShape_ConnectedEdgeSet(mod, "StepShape_ConnectedEdgeSet", "Representation of STEP entity ConnectedEdgeSet");

// Constructors
cls_StepShape_ConnectedEdgeSet.def(py::init<>());

// Fields

// Methods
cls_StepShape_ConnectedEdgeSet.def("Init", (void (StepShape_ConnectedEdgeSet::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfEdge> &)) &StepShape_ConnectedEdgeSet::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aCesEdges"));
cls_StepShape_ConnectedEdgeSet.def("CesEdges", (opencascade::handle<StepShape_HArray1OfEdge> (StepShape_ConnectedEdgeSet::*)() const) &StepShape_ConnectedEdgeSet::CesEdges, "Returns field CesEdges");
cls_StepShape_ConnectedEdgeSet.def("SetCesEdges", (void (StepShape_ConnectedEdgeSet::*)(const opencascade::handle<StepShape_HArray1OfEdge> &)) &StepShape_ConnectedEdgeSet::SetCesEdges, "Set field CesEdges", py::arg("CesEdges"));
cls_StepShape_ConnectedEdgeSet.def_static("get_type_name_", (const char * (*)()) &StepShape_ConnectedEdgeSet::get_type_name, "None");
cls_StepShape_ConnectedEdgeSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ConnectedEdgeSet::get_type_descriptor, "None");
cls_StepShape_ConnectedEdgeSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ConnectedEdgeSet::*)() const) &StepShape_ConnectedEdgeSet::DynamicType, "None");

// Enums

}