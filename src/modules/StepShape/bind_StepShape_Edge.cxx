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
#include <StepShape_Vertex.hxx>
#include <StepShape_Edge.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_Edge(py::module &mod){

py::class_<StepShape_Edge, opencascade::handle<StepShape_Edge>, StepShape_TopologicalRepresentationItem> cls_StepShape_Edge(mod, "StepShape_Edge", "None");

// Constructors
cls_StepShape_Edge.def(py::init<>());

// Fields

// Methods
cls_StepShape_Edge.def("Init", (void (StepShape_Edge::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Vertex> &, const opencascade::handle<StepShape_Vertex> &)) &StepShape_Edge::Init, "None", py::arg("aName"), py::arg("aEdgeStart"), py::arg("aEdgeEnd"));
cls_StepShape_Edge.def("SetEdgeStart", (void (StepShape_Edge::*)(const opencascade::handle<StepShape_Vertex> &)) &StepShape_Edge::SetEdgeStart, "None", py::arg("aEdgeStart"));
cls_StepShape_Edge.def("EdgeStart", (opencascade::handle<StepShape_Vertex> (StepShape_Edge::*)() const) &StepShape_Edge::EdgeStart, "None");
cls_StepShape_Edge.def("SetEdgeEnd", (void (StepShape_Edge::*)(const opencascade::handle<StepShape_Vertex> &)) &StepShape_Edge::SetEdgeEnd, "None", py::arg("aEdgeEnd"));
cls_StepShape_Edge.def("EdgeEnd", (opencascade::handle<StepShape_Vertex> (StepShape_Edge::*)() const) &StepShape_Edge::EdgeEnd, "None");
cls_StepShape_Edge.def_static("get_type_name_", (const char * (*)()) &StepShape_Edge::get_type_name, "None");
cls_StepShape_Edge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Edge::get_type_descriptor, "None");
cls_StepShape_Edge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Edge::*)() const) &StepShape_Edge::DynamicType, "None");

// Enums

}