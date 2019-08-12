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
#include <StepRepr_RepresentationItem.hxx>
#include <StepRepr_ItemDefinedTransformation.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ItemDefinedTransformation(py::module &mod){

py::class_<StepRepr_ItemDefinedTransformation, opencascade::handle<StepRepr_ItemDefinedTransformation>, Standard_Transient> cls_StepRepr_ItemDefinedTransformation(mod, "StepRepr_ItemDefinedTransformation", "Added from StepRepr Rev2 to Rev4");

// Constructors
cls_StepRepr_ItemDefinedTransformation.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ItemDefinedTransformation.def("Init", (void (StepRepr_ItemDefinedTransformation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_ItemDefinedTransformation::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aTransformItem1"), py::arg("aTransformItem2"));
cls_StepRepr_ItemDefinedTransformation.def("SetName", (void (StepRepr_ItemDefinedTransformation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ItemDefinedTransformation::SetName, "None", py::arg("aName"));
cls_StepRepr_ItemDefinedTransformation.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ItemDefinedTransformation::*)() const) &StepRepr_ItemDefinedTransformation::Name, "None");
cls_StepRepr_ItemDefinedTransformation.def("SetDescription", (void (StepRepr_ItemDefinedTransformation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ItemDefinedTransformation::SetDescription, "None", py::arg("aDescription"));
cls_StepRepr_ItemDefinedTransformation.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ItemDefinedTransformation::*)() const) &StepRepr_ItemDefinedTransformation::Description, "None");
cls_StepRepr_ItemDefinedTransformation.def("SetTransformItem1", (void (StepRepr_ItemDefinedTransformation::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_ItemDefinedTransformation::SetTransformItem1, "None", py::arg("aItem"));
cls_StepRepr_ItemDefinedTransformation.def("TransformItem1", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_ItemDefinedTransformation::*)() const) &StepRepr_ItemDefinedTransformation::TransformItem1, "None");
cls_StepRepr_ItemDefinedTransformation.def("SetTransformItem2", (void (StepRepr_ItemDefinedTransformation::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_ItemDefinedTransformation::SetTransformItem2, "None", py::arg("aItem"));
cls_StepRepr_ItemDefinedTransformation.def("TransformItem2", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_ItemDefinedTransformation::*)() const) &StepRepr_ItemDefinedTransformation::TransformItem2, "None");
cls_StepRepr_ItemDefinedTransformation.def_static("get_type_name_", (const char * (*)()) &StepRepr_ItemDefinedTransformation::get_type_name, "None");
cls_StepRepr_ItemDefinedTransformation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ItemDefinedTransformation::get_type_descriptor, "None");
cls_StepRepr_ItemDefinedTransformation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ItemDefinedTransformation::*)() const) &StepRepr_ItemDefinedTransformation::DynamicType, "None");

// Enums

}