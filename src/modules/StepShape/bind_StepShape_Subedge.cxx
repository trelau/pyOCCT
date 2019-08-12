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
#include <StepShape_Edge.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_Vertex.hxx>
#include <StepShape_Subedge.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_Subedge(py::module &mod){

py::class_<StepShape_Subedge, opencascade::handle<StepShape_Subedge>, StepShape_Edge> cls_StepShape_Subedge(mod, "StepShape_Subedge", "Representation of STEP entity Subedge");

// Constructors
cls_StepShape_Subedge.def(py::init<>());

// Fields

// Methods
cls_StepShape_Subedge.def("Init", (void (StepShape_Subedge::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Vertex> &, const opencascade::handle<StepShape_Vertex> &, const opencascade::handle<StepShape_Edge> &)) &StepShape_Subedge::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aEdge_EdgeStart"), py::arg("aEdge_EdgeEnd"), py::arg("aParentEdge"));
cls_StepShape_Subedge.def("ParentEdge", (opencascade::handle<StepShape_Edge> (StepShape_Subedge::*)() const) &StepShape_Subedge::ParentEdge, "Returns field ParentEdge");
cls_StepShape_Subedge.def("SetParentEdge", (void (StepShape_Subedge::*)(const opencascade::handle<StepShape_Edge> &)) &StepShape_Subedge::SetParentEdge, "Set field ParentEdge", py::arg("ParentEdge"));
cls_StepShape_Subedge.def_static("get_type_name_", (const char * (*)()) &StepShape_Subedge::get_type_name, "None");
cls_StepShape_Subedge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Subedge::get_type_descriptor, "None");
cls_StepShape_Subedge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Subedge::*)() const) &StepShape_Subedge::DynamicType, "None");

// Enums

}