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
#include <StepShape_HArray1OfOrientedEdge.hxx>
#include <StepShape_OrientedEdge.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_Path.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_Path(py::module &mod){

py::class_<StepShape_Path, opencascade::handle<StepShape_Path>, StepShape_TopologicalRepresentationItem> cls_StepShape_Path(mod, "StepShape_Path", "None");

// Constructors
cls_StepShape_Path.def(py::init<>());

// Fields

// Methods
cls_StepShape_Path.def("Init", (void (StepShape_Path::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfOrientedEdge> &)) &StepShape_Path::Init, "None", py::arg("aName"), py::arg("aEdgeList"));
cls_StepShape_Path.def("SetEdgeList", (void (StepShape_Path::*)(const opencascade::handle<StepShape_HArray1OfOrientedEdge> &)) &StepShape_Path::SetEdgeList, "None", py::arg("aEdgeList"));
cls_StepShape_Path.def("EdgeList", (opencascade::handle<StepShape_HArray1OfOrientedEdge> (StepShape_Path::*)() const) &StepShape_Path::EdgeList, "None");
cls_StepShape_Path.def("EdgeListValue", (opencascade::handle<StepShape_OrientedEdge> (StepShape_Path::*)(const Standard_Integer) const) &StepShape_Path::EdgeListValue, "None", py::arg("num"));
cls_StepShape_Path.def("NbEdgeList", (Standard_Integer (StepShape_Path::*)() const) &StepShape_Path::NbEdgeList, "None");
cls_StepShape_Path.def_static("get_type_name_", (const char * (*)()) &StepShape_Path::get_type_name, "None");
cls_StepShape_Path.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Path::get_type_descriptor, "None");
cls_StepShape_Path.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Path::*)() const) &StepShape_Path::DynamicType, "None");

// Enums

}