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
#include <TCollection_HAsciiString.hxx>
#include <StepVisual_HArray1OfLayeredItem.hxx>
#include <StepVisual_LayeredItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_PresentationLayerAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_PresentationLayerAssignment(py::module &mod){

py::class_<StepVisual_PresentationLayerAssignment, opencascade::handle<StepVisual_PresentationLayerAssignment>, Standard_Transient> cls_StepVisual_PresentationLayerAssignment(mod, "StepVisual_PresentationLayerAssignment", "None");

// Constructors
cls_StepVisual_PresentationLayerAssignment.def(py::init<>());

// Fields

// Methods
cls_StepVisual_PresentationLayerAssignment.def("Init", (void (StepVisual_PresentationLayerAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfLayeredItem> &)) &StepVisual_PresentationLayerAssignment::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aAssignedItems"));
cls_StepVisual_PresentationLayerAssignment.def("SetName", (void (StepVisual_PresentationLayerAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_PresentationLayerAssignment::SetName, "None", py::arg("aName"));
cls_StepVisual_PresentationLayerAssignment.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_PresentationLayerAssignment::*)() const) &StepVisual_PresentationLayerAssignment::Name, "None");
cls_StepVisual_PresentationLayerAssignment.def("SetDescription", (void (StepVisual_PresentationLayerAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_PresentationLayerAssignment::SetDescription, "None", py::arg("aDescription"));
cls_StepVisual_PresentationLayerAssignment.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepVisual_PresentationLayerAssignment::*)() const) &StepVisual_PresentationLayerAssignment::Description, "None");
cls_StepVisual_PresentationLayerAssignment.def("SetAssignedItems", (void (StepVisual_PresentationLayerAssignment::*)(const opencascade::handle<StepVisual_HArray1OfLayeredItem> &)) &StepVisual_PresentationLayerAssignment::SetAssignedItems, "None", py::arg("aAssignedItems"));
cls_StepVisual_PresentationLayerAssignment.def("AssignedItems", (opencascade::handle<StepVisual_HArray1OfLayeredItem> (StepVisual_PresentationLayerAssignment::*)() const) &StepVisual_PresentationLayerAssignment::AssignedItems, "None");
cls_StepVisual_PresentationLayerAssignment.def("AssignedItemsValue", (StepVisual_LayeredItem (StepVisual_PresentationLayerAssignment::*)(const Standard_Integer) const) &StepVisual_PresentationLayerAssignment::AssignedItemsValue, "None", py::arg("num"));
cls_StepVisual_PresentationLayerAssignment.def("NbAssignedItems", (Standard_Integer (StepVisual_PresentationLayerAssignment::*)() const) &StepVisual_PresentationLayerAssignment::NbAssignedItems, "None");
cls_StepVisual_PresentationLayerAssignment.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationLayerAssignment::get_type_name, "None");
cls_StepVisual_PresentationLayerAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationLayerAssignment::get_type_descriptor, "None");
cls_StepVisual_PresentationLayerAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationLayerAssignment::*)() const) &StepVisual_PresentationLayerAssignment::DynamicType, "None");

// Enums

}