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
#include <Standard_TypeDef.hxx>
#include <StepShape_Vertex.hxx>
#include <StepShape_OrientedEdge.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_OrientedEdge(py::module &mod){

py::class_<StepShape_OrientedEdge, opencascade::handle<StepShape_OrientedEdge>, StepShape_Edge> cls_StepShape_OrientedEdge(mod, "StepShape_OrientedEdge", "None");

// Constructors
cls_StepShape_OrientedEdge.def(py::init<>());

// Fields

// Methods
cls_StepShape_OrientedEdge.def("Init", (void (StepShape_OrientedEdge::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Edge> &, const Standard_Boolean)) &StepShape_OrientedEdge::Init, "None", py::arg("aName"), py::arg("aEdgeElement"), py::arg("aOrientation"));
cls_StepShape_OrientedEdge.def("SetEdgeElement", (void (StepShape_OrientedEdge::*)(const opencascade::handle<StepShape_Edge> &)) &StepShape_OrientedEdge::SetEdgeElement, "None", py::arg("aEdgeElement"));
cls_StepShape_OrientedEdge.def("EdgeElement", (opencascade::handle<StepShape_Edge> (StepShape_OrientedEdge::*)() const) &StepShape_OrientedEdge::EdgeElement, "None");
cls_StepShape_OrientedEdge.def("SetOrientation", (void (StepShape_OrientedEdge::*)(const Standard_Boolean)) &StepShape_OrientedEdge::SetOrientation, "None", py::arg("aOrientation"));
cls_StepShape_OrientedEdge.def("Orientation", (Standard_Boolean (StepShape_OrientedEdge::*)() const) &StepShape_OrientedEdge::Orientation, "None");
cls_StepShape_OrientedEdge.def("SetEdgeStart", (void (StepShape_OrientedEdge::*)(const opencascade::handle<StepShape_Vertex> &)) &StepShape_OrientedEdge::SetEdgeStart, "None", py::arg("aEdgeStart"));
cls_StepShape_OrientedEdge.def("EdgeStart", (opencascade::handle<StepShape_Vertex> (StepShape_OrientedEdge::*)() const) &StepShape_OrientedEdge::EdgeStart, "None");
cls_StepShape_OrientedEdge.def("SetEdgeEnd", (void (StepShape_OrientedEdge::*)(const opencascade::handle<StepShape_Vertex> &)) &StepShape_OrientedEdge::SetEdgeEnd, "None", py::arg("aEdgeEnd"));
cls_StepShape_OrientedEdge.def("EdgeEnd", (opencascade::handle<StepShape_Vertex> (StepShape_OrientedEdge::*)() const) &StepShape_OrientedEdge::EdgeEnd, "None");
cls_StepShape_OrientedEdge.def_static("get_type_name_", (const char * (*)()) &StepShape_OrientedEdge::get_type_name, "None");
cls_StepShape_OrientedEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_OrientedEdge::get_type_descriptor, "None");
cls_StepShape_OrientedEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_OrientedEdge::*)() const) &StepShape_OrientedEdge::DynamicType, "None");

// Enums

}