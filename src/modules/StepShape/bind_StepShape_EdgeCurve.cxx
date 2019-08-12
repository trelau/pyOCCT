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
#include <StepGeom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_EdgeCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_EdgeCurve(py::module &mod){

py::class_<StepShape_EdgeCurve, opencascade::handle<StepShape_EdgeCurve>, StepShape_Edge> cls_StepShape_EdgeCurve(mod, "StepShape_EdgeCurve", "None");

// Constructors
cls_StepShape_EdgeCurve.def(py::init<>());

// Fields

// Methods
cls_StepShape_EdgeCurve.def("Init", (void (StepShape_EdgeCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Vertex> &, const opencascade::handle<StepShape_Vertex> &, const opencascade::handle<StepGeom_Curve> &, const Standard_Boolean)) &StepShape_EdgeCurve::Init, "None", py::arg("aName"), py::arg("aEdgeStart"), py::arg("aEdgeEnd"), py::arg("aEdgeGeometry"), py::arg("aSameSense"));
cls_StepShape_EdgeCurve.def("SetEdgeGeometry", (void (StepShape_EdgeCurve::*)(const opencascade::handle<StepGeom_Curve> &)) &StepShape_EdgeCurve::SetEdgeGeometry, "None", py::arg("aEdgeGeometry"));
cls_StepShape_EdgeCurve.def("EdgeGeometry", (opencascade::handle<StepGeom_Curve> (StepShape_EdgeCurve::*)() const) &StepShape_EdgeCurve::EdgeGeometry, "None");
cls_StepShape_EdgeCurve.def("SetSameSense", (void (StepShape_EdgeCurve::*)(const Standard_Boolean)) &StepShape_EdgeCurve::SetSameSense, "None", py::arg("aSameSense"));
cls_StepShape_EdgeCurve.def("SameSense", (Standard_Boolean (StepShape_EdgeCurve::*)() const) &StepShape_EdgeCurve::SameSense, "None");
cls_StepShape_EdgeCurve.def_static("get_type_name_", (const char * (*)()) &StepShape_EdgeCurve::get_type_name, "None");
cls_StepShape_EdgeCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_EdgeCurve::get_type_descriptor, "None");
cls_StepShape_EdgeCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_EdgeCurve::*)() const) &StepShape_EdgeCurve::DynamicType, "None");

// Enums

}