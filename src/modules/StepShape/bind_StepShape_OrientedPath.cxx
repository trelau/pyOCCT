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
#include <StepShape_Path.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_EdgeLoop.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_HArray1OfOrientedEdge.hxx>
#include <StepShape_OrientedEdge.hxx>
#include <StepShape_OrientedPath.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_OrientedPath(py::module &mod){

py::class_<StepShape_OrientedPath, opencascade::handle<StepShape_OrientedPath>, StepShape_Path> cls_StepShape_OrientedPath(mod, "StepShape_OrientedPath", "None");

// Constructors
cls_StepShape_OrientedPath.def(py::init<>());

// Fields

// Methods
cls_StepShape_OrientedPath.def("Init", (void (StepShape_OrientedPath::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_EdgeLoop> &, const Standard_Boolean)) &StepShape_OrientedPath::Init, "None", py::arg("aName"), py::arg("aPathElement"), py::arg("aOrientation"));
cls_StepShape_OrientedPath.def("SetPathElement", (void (StepShape_OrientedPath::*)(const opencascade::handle<StepShape_EdgeLoop> &)) &StepShape_OrientedPath::SetPathElement, "None", py::arg("aPathElement"));
cls_StepShape_OrientedPath.def("PathElement", (opencascade::handle<StepShape_EdgeLoop> (StepShape_OrientedPath::*)() const) &StepShape_OrientedPath::PathElement, "None");
cls_StepShape_OrientedPath.def("SetOrientation", (void (StepShape_OrientedPath::*)(const Standard_Boolean)) &StepShape_OrientedPath::SetOrientation, "None", py::arg("aOrientation"));
cls_StepShape_OrientedPath.def("Orientation", (Standard_Boolean (StepShape_OrientedPath::*)() const) &StepShape_OrientedPath::Orientation, "None");
cls_StepShape_OrientedPath.def("SetEdgeList", (void (StepShape_OrientedPath::*)(const opencascade::handle<StepShape_HArray1OfOrientedEdge> &)) &StepShape_OrientedPath::SetEdgeList, "None", py::arg("aEdgeList"));
cls_StepShape_OrientedPath.def("EdgeList", (opencascade::handle<StepShape_HArray1OfOrientedEdge> (StepShape_OrientedPath::*)() const) &StepShape_OrientedPath::EdgeList, "None");
cls_StepShape_OrientedPath.def("EdgeListValue", (opencascade::handle<StepShape_OrientedEdge> (StepShape_OrientedPath::*)(const Standard_Integer) const) &StepShape_OrientedPath::EdgeListValue, "None", py::arg("num"));
cls_StepShape_OrientedPath.def("NbEdgeList", (Standard_Integer (StepShape_OrientedPath::*)() const) &StepShape_OrientedPath::NbEdgeList, "None");
cls_StepShape_OrientedPath.def_static("get_type_name_", (const char * (*)()) &StepShape_OrientedPath::get_type_name, "None");
cls_StepShape_OrientedPath.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_OrientedPath::get_type_descriptor, "None");
cls_StepShape_OrientedPath.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_OrientedPath::*)() const) &StepShape_OrientedPath::DynamicType, "None");

// Enums

}