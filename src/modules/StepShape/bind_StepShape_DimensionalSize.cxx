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
#include <StepRepr_ShapeAspect.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_DimensionalSize.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_DimensionalSize(py::module &mod){

py::class_<StepShape_DimensionalSize, opencascade::handle<StepShape_DimensionalSize>, Standard_Transient> cls_StepShape_DimensionalSize(mod, "StepShape_DimensionalSize", "Representation of STEP entity DimensionalSize");

// Constructors
cls_StepShape_DimensionalSize.def(py::init<>());

// Fields

// Methods
cls_StepShape_DimensionalSize.def("Init", (void (StepShape_DimensionalSize::*)(const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_DimensionalSize::Init, "Initialize all fields (own and inherited)", py::arg("aAppliesTo"), py::arg("aName"));
cls_StepShape_DimensionalSize.def("AppliesTo", (opencascade::handle<StepRepr_ShapeAspect> (StepShape_DimensionalSize::*)() const) &StepShape_DimensionalSize::AppliesTo, "Returns field AppliesTo");
cls_StepShape_DimensionalSize.def("SetAppliesTo", (void (StepShape_DimensionalSize::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepShape_DimensionalSize::SetAppliesTo, "Set field AppliesTo", py::arg("AppliesTo"));
cls_StepShape_DimensionalSize.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepShape_DimensionalSize::*)() const) &StepShape_DimensionalSize::Name, "Returns field Name");
cls_StepShape_DimensionalSize.def("SetName", (void (StepShape_DimensionalSize::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_DimensionalSize::SetName, "Set field Name", py::arg("Name"));
cls_StepShape_DimensionalSize.def_static("get_type_name_", (const char * (*)()) &StepShape_DimensionalSize::get_type_name, "None");
cls_StepShape_DimensionalSize.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_DimensionalSize::get_type_descriptor, "None");
cls_StepShape_DimensionalSize.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_DimensionalSize::*)() const) &StepShape_DimensionalSize::DynamicType, "None");

// Enums

}