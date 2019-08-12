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
#include <StepElement_SurfaceSectionField.hxx>
#include <StepElement_SurfaceElementProperty.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_SurfaceElementProperty(py::module &mod){

py::class_<StepElement_SurfaceElementProperty, opencascade::handle<StepElement_SurfaceElementProperty>, Standard_Transient> cls_StepElement_SurfaceElementProperty(mod, "StepElement_SurfaceElementProperty", "Representation of STEP entity SurfaceElementProperty");

// Constructors
cls_StepElement_SurfaceElementProperty.def(py::init<>());

// Fields

// Methods
cls_StepElement_SurfaceElementProperty.def("Init", (void (StepElement_SurfaceElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepElement_SurfaceSectionField> &)) &StepElement_SurfaceElementProperty::Init, "Initialize all fields (own and inherited)", py::arg("aPropertyId"), py::arg("aDescription"), py::arg("aSection"));
cls_StepElement_SurfaceElementProperty.def("PropertyId", (opencascade::handle<TCollection_HAsciiString> (StepElement_SurfaceElementProperty::*)() const) &StepElement_SurfaceElementProperty::PropertyId, "Returns field PropertyId");
cls_StepElement_SurfaceElementProperty.def("SetPropertyId", (void (StepElement_SurfaceElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_SurfaceElementProperty::SetPropertyId, "Set field PropertyId", py::arg("PropertyId"));
cls_StepElement_SurfaceElementProperty.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepElement_SurfaceElementProperty::*)() const) &StepElement_SurfaceElementProperty::Description, "Returns field Description");
cls_StepElement_SurfaceElementProperty.def("SetDescription", (void (StepElement_SurfaceElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_SurfaceElementProperty::SetDescription, "Set field Description", py::arg("Description"));
cls_StepElement_SurfaceElementProperty.def("Section", (opencascade::handle<StepElement_SurfaceSectionField> (StepElement_SurfaceElementProperty::*)() const) &StepElement_SurfaceElementProperty::Section, "Returns field Section");
cls_StepElement_SurfaceElementProperty.def("SetSection", (void (StepElement_SurfaceElementProperty::*)(const opencascade::handle<StepElement_SurfaceSectionField> &)) &StepElement_SurfaceElementProperty::SetSection, "Set field Section", py::arg("Section"));
cls_StepElement_SurfaceElementProperty.def_static("get_type_name_", (const char * (*)()) &StepElement_SurfaceElementProperty::get_type_name, "None");
cls_StepElement_SurfaceElementProperty.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_SurfaceElementProperty::get_type_descriptor, "None");
cls_StepElement_SurfaceElementProperty.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_SurfaceElementProperty::*)() const) &StepElement_SurfaceElementProperty::DynamicType, "None");

// Enums

}