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
#include <StepVisual_PresentationRepresentationSelect.hxx>
#include <Standard_Handle.hxx>
#include <StepVisual_PresentedItem.hxx>
#include <StepVisual_PresentedItemRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_PresentedItemRepresentation(py::module &mod){

py::class_<StepVisual_PresentedItemRepresentation, opencascade::handle<StepVisual_PresentedItemRepresentation>, Standard_Transient> cls_StepVisual_PresentedItemRepresentation(mod, "StepVisual_PresentedItemRepresentation", "Added from StepVisual Rev2 to Rev4");

// Constructors
cls_StepVisual_PresentedItemRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepVisual_PresentedItemRepresentation.def("Init", (void (StepVisual_PresentedItemRepresentation::*)(const StepVisual_PresentationRepresentationSelect &, const opencascade::handle<StepVisual_PresentedItem> &)) &StepVisual_PresentedItemRepresentation::Init, "None", py::arg("aPresentation"), py::arg("aItem"));
cls_StepVisual_PresentedItemRepresentation.def("SetPresentation", (void (StepVisual_PresentedItemRepresentation::*)(const StepVisual_PresentationRepresentationSelect &)) &StepVisual_PresentedItemRepresentation::SetPresentation, "None", py::arg("aPresentation"));
cls_StepVisual_PresentedItemRepresentation.def("Presentation", (StepVisual_PresentationRepresentationSelect (StepVisual_PresentedItemRepresentation::*)() const) &StepVisual_PresentedItemRepresentation::Presentation, "None");
cls_StepVisual_PresentedItemRepresentation.def("SetItem", (void (StepVisual_PresentedItemRepresentation::*)(const opencascade::handle<StepVisual_PresentedItem> &)) &StepVisual_PresentedItemRepresentation::SetItem, "None", py::arg("aItem"));
cls_StepVisual_PresentedItemRepresentation.def("Item", (opencascade::handle<StepVisual_PresentedItem> (StepVisual_PresentedItemRepresentation::*)() const) &StepVisual_PresentedItemRepresentation::Item, "None");
cls_StepVisual_PresentedItemRepresentation.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentedItemRepresentation::get_type_name, "None");
cls_StepVisual_PresentedItemRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentedItemRepresentation::get_type_descriptor, "None");
cls_StepVisual_PresentedItemRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentedItemRepresentation::*)() const) &StepVisual_PresentedItemRepresentation::DynamicType, "None");

// Enums

}