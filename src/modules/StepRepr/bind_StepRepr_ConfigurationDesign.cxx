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
#include <StepRepr_ConfigurationItem.hxx>
#include <StepRepr_ConfigurationDesignItem.hxx>
#include <StepRepr_ConfigurationDesign.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ConfigurationDesign(py::module &mod){

py::class_<StepRepr_ConfigurationDesign, opencascade::handle<StepRepr_ConfigurationDesign>, Standard_Transient> cls_StepRepr_ConfigurationDesign(mod, "StepRepr_ConfigurationDesign", "Representation of STEP entity ConfigurationDesign");

// Constructors
cls_StepRepr_ConfigurationDesign.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ConfigurationDesign.def("Init", (void (StepRepr_ConfigurationDesign::*)(const opencascade::handle<StepRepr_ConfigurationItem> &, const StepRepr_ConfigurationDesignItem &)) &StepRepr_ConfigurationDesign::Init, "Initialize all fields (own and inherited)", py::arg("aConfiguration"), py::arg("aDesign"));
cls_StepRepr_ConfigurationDesign.def("Configuration", (opencascade::handle<StepRepr_ConfigurationItem> (StepRepr_ConfigurationDesign::*)() const) &StepRepr_ConfigurationDesign::Configuration, "Returns field Configuration");
cls_StepRepr_ConfigurationDesign.def("SetConfiguration", (void (StepRepr_ConfigurationDesign::*)(const opencascade::handle<StepRepr_ConfigurationItem> &)) &StepRepr_ConfigurationDesign::SetConfiguration, "Set field Configuration", py::arg("Configuration"));
cls_StepRepr_ConfigurationDesign.def("Design", (StepRepr_ConfigurationDesignItem (StepRepr_ConfigurationDesign::*)() const) &StepRepr_ConfigurationDesign::Design, "Returns field Design");
cls_StepRepr_ConfigurationDesign.def("SetDesign", (void (StepRepr_ConfigurationDesign::*)(const StepRepr_ConfigurationDesignItem &)) &StepRepr_ConfigurationDesign::SetDesign, "Set field Design", py::arg("Design"));
cls_StepRepr_ConfigurationDesign.def_static("get_type_name_", (const char * (*)()) &StepRepr_ConfigurationDesign::get_type_name, "None");
cls_StepRepr_ConfigurationDesign.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ConfigurationDesign::get_type_descriptor, "None");
cls_StepRepr_ConfigurationDesign.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ConfigurationDesign::*)() const) &StepRepr_ConfigurationDesign::DynamicType, "None");

// Enums

}