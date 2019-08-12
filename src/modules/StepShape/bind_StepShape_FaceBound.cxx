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
#include <StepShape_Loop.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_FaceBound.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_FaceBound(py::module &mod){

py::class_<StepShape_FaceBound, opencascade::handle<StepShape_FaceBound>, StepShape_TopologicalRepresentationItem> cls_StepShape_FaceBound(mod, "StepShape_FaceBound", "None");

// Constructors
cls_StepShape_FaceBound.def(py::init<>());

// Fields

// Methods
cls_StepShape_FaceBound.def("Init", (void (StepShape_FaceBound::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Loop> &, const Standard_Boolean)) &StepShape_FaceBound::Init, "None", py::arg("aName"), py::arg("aBound"), py::arg("aOrientation"));
cls_StepShape_FaceBound.def("SetBound", (void (StepShape_FaceBound::*)(const opencascade::handle<StepShape_Loop> &)) &StepShape_FaceBound::SetBound, "None", py::arg("aBound"));
cls_StepShape_FaceBound.def("Bound", (opencascade::handle<StepShape_Loop> (StepShape_FaceBound::*)() const) &StepShape_FaceBound::Bound, "None");
cls_StepShape_FaceBound.def("SetOrientation", (void (StepShape_FaceBound::*)(const Standard_Boolean)) &StepShape_FaceBound::SetOrientation, "None", py::arg("aOrientation"));
cls_StepShape_FaceBound.def("Orientation", (Standard_Boolean (StepShape_FaceBound::*)() const) &StepShape_FaceBound::Orientation, "None");
cls_StepShape_FaceBound.def_static("get_type_name_", (const char * (*)()) &StepShape_FaceBound::get_type_name, "None");
cls_StepShape_FaceBound.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_FaceBound::get_type_descriptor, "None");
cls_StepShape_FaceBound.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_FaceBound::*)() const) &StepShape_FaceBound::DynamicType, "None");

// Enums

}