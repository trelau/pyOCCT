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
#include <StepShape_DimensionalSize.hxx>
#include <Standard_Handle.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_DimensionalSizeWithPath.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_DimensionalSizeWithPath(py::module &mod){

py::class_<StepShape_DimensionalSizeWithPath, opencascade::handle<StepShape_DimensionalSizeWithPath>, StepShape_DimensionalSize> cls_StepShape_DimensionalSizeWithPath(mod, "StepShape_DimensionalSizeWithPath", "Representation of STEP entity DimensionalSizeWithPath");

// Constructors
cls_StepShape_DimensionalSizeWithPath.def(py::init<>());

// Fields

// Methods
cls_StepShape_DimensionalSizeWithPath.def("Init", (void (StepShape_DimensionalSizeWithPath::*)(const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepShape_DimensionalSizeWithPath::Init, "Initialize all fields (own and inherited)", py::arg("aDimensionalSize_AppliesTo"), py::arg("aDimensionalSize_Name"), py::arg("aPath"));
cls_StepShape_DimensionalSizeWithPath.def("Path", (opencascade::handle<StepRepr_ShapeAspect> (StepShape_DimensionalSizeWithPath::*)() const) &StepShape_DimensionalSizeWithPath::Path, "Returns field Path");
cls_StepShape_DimensionalSizeWithPath.def("SetPath", (void (StepShape_DimensionalSizeWithPath::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepShape_DimensionalSizeWithPath::SetPath, "Set field Path", py::arg("Path"));
cls_StepShape_DimensionalSizeWithPath.def_static("get_type_name_", (const char * (*)()) &StepShape_DimensionalSizeWithPath::get_type_name, "None");
cls_StepShape_DimensionalSizeWithPath.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_DimensionalSizeWithPath::get_type_descriptor, "None");
cls_StepShape_DimensionalSizeWithPath.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_DimensionalSizeWithPath::*)() const) &StepShape_DimensionalSizeWithPath::DynamicType, "None");

// Enums

}