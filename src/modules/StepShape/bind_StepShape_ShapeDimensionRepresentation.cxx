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
#include <StepShape_ShapeRepresentation.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_HArray1OfRepresentationItem.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <StepShape_HArray1OfShapeDimensionRepresentationItem.hxx>
#include <StepShape_ShapeDimensionRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_ShapeDimensionRepresentation(py::module &mod){

py::class_<StepShape_ShapeDimensionRepresentation, opencascade::handle<StepShape_ShapeDimensionRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_ShapeDimensionRepresentation(mod, "StepShape_ShapeDimensionRepresentation", "Representation of STEP entity ShapeDimensionRepresentation");

// Constructors
cls_StepShape_ShapeDimensionRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepShape_ShapeDimensionRepresentation.def("Init", (void (StepShape_ShapeDimensionRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &)) &StepShape_ShapeDimensionRepresentation::Init, "Initialize all fields AP214", py::arg("theName"), py::arg("theItems"), py::arg("theContextOfItems"));
cls_StepShape_ShapeDimensionRepresentation.def("Init", (void (StepShape_ShapeDimensionRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfShapeDimensionRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &)) &StepShape_ShapeDimensionRepresentation::Init, "Initialize all fields AP242", py::arg("theName"), py::arg("theItems"), py::arg("theContextOfItems"));
cls_StepShape_ShapeDimensionRepresentation.def("SetItemsAP242", (void (StepShape_ShapeDimensionRepresentation::*)(const opencascade::handle<StepShape_HArray1OfShapeDimensionRepresentationItem> &)) &StepShape_ShapeDimensionRepresentation::SetItemsAP242, "None", py::arg("theItems"));
cls_StepShape_ShapeDimensionRepresentation.def("ItemsAP242", (opencascade::handle<StepShape_HArray1OfShapeDimensionRepresentationItem> (StepShape_ShapeDimensionRepresentation::*)() const) &StepShape_ShapeDimensionRepresentation::ItemsAP242, "None");
cls_StepShape_ShapeDimensionRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_ShapeDimensionRepresentation::get_type_name, "None");
cls_StepShape_ShapeDimensionRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ShapeDimensionRepresentation::get_type_descriptor, "None");
cls_StepShape_ShapeDimensionRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ShapeDimensionRepresentation::*)() const) &StepShape_ShapeDimensionRepresentation::DynamicType, "None");

// Enums

}