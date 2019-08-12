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
#include <StepShape_DimensionalLocation.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepShape_DimensionalLocationWithPath.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_DimensionalLocationWithPath(py::module &mod){

py::class_<StepShape_DimensionalLocationWithPath, opencascade::handle<StepShape_DimensionalLocationWithPath>, StepShape_DimensionalLocation> cls_StepShape_DimensionalLocationWithPath(mod, "StepShape_DimensionalLocationWithPath", "Representation of STEP entity DimensionalLocationWithPath");

// Constructors
cls_StepShape_DimensionalLocationWithPath.def(py::init<>());

// Fields

// Methods
cls_StepShape_DimensionalLocationWithPath.def("Init", (void (StepShape_DimensionalLocationWithPath::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepShape_DimensionalLocationWithPath::Init, "Initialize all fields (own and inherited)", py::arg("aShapeAspectRelationship_Name"), py::arg("hasShapeAspectRelationship_Description"), py::arg("aShapeAspectRelationship_Description"), py::arg("aShapeAspectRelationship_RelatingShapeAspect"), py::arg("aShapeAspectRelationship_RelatedShapeAspect"), py::arg("aPath"));
cls_StepShape_DimensionalLocationWithPath.def("Path", (opencascade::handle<StepRepr_ShapeAspect> (StepShape_DimensionalLocationWithPath::*)() const) &StepShape_DimensionalLocationWithPath::Path, "Returns field Path");
cls_StepShape_DimensionalLocationWithPath.def("SetPath", (void (StepShape_DimensionalLocationWithPath::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepShape_DimensionalLocationWithPath::SetPath, "Set field Path", py::arg("Path"));
cls_StepShape_DimensionalLocationWithPath.def_static("get_type_name_", (const char * (*)()) &StepShape_DimensionalLocationWithPath::get_type_name, "None");
cls_StepShape_DimensionalLocationWithPath.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_DimensionalLocationWithPath::get_type_descriptor, "None");
cls_StepShape_DimensionalLocationWithPath.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_DimensionalLocationWithPath::*)() const) &StepShape_DimensionalLocationWithPath::DynamicType, "None");

// Enums

}