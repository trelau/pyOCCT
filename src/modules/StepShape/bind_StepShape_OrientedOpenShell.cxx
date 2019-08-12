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
#include <StepShape_OpenShell.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_HArray1OfFace.hxx>
#include <StepShape_Face.hxx>
#include <StepShape_OrientedOpenShell.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_OrientedOpenShell(py::module &mod){

py::class_<StepShape_OrientedOpenShell, opencascade::handle<StepShape_OrientedOpenShell>, StepShape_OpenShell> cls_StepShape_OrientedOpenShell(mod, "StepShape_OrientedOpenShell", "None");

// Constructors
cls_StepShape_OrientedOpenShell.def(py::init<>());

// Fields

// Methods
cls_StepShape_OrientedOpenShell.def("Init", (void (StepShape_OrientedOpenShell::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_OpenShell> &, const Standard_Boolean)) &StepShape_OrientedOpenShell::Init, "None", py::arg("aName"), py::arg("aOpenShellElement"), py::arg("aOrientation"));
cls_StepShape_OrientedOpenShell.def("SetOpenShellElement", (void (StepShape_OrientedOpenShell::*)(const opencascade::handle<StepShape_OpenShell> &)) &StepShape_OrientedOpenShell::SetOpenShellElement, "None", py::arg("aOpenShellElement"));
cls_StepShape_OrientedOpenShell.def("OpenShellElement", (opencascade::handle<StepShape_OpenShell> (StepShape_OrientedOpenShell::*)() const) &StepShape_OrientedOpenShell::OpenShellElement, "None");
cls_StepShape_OrientedOpenShell.def("SetOrientation", (void (StepShape_OrientedOpenShell::*)(const Standard_Boolean)) &StepShape_OrientedOpenShell::SetOrientation, "None", py::arg("aOrientation"));
cls_StepShape_OrientedOpenShell.def("Orientation", (Standard_Boolean (StepShape_OrientedOpenShell::*)() const) &StepShape_OrientedOpenShell::Orientation, "None");
cls_StepShape_OrientedOpenShell.def("SetCfsFaces", (void (StepShape_OrientedOpenShell::*)(const opencascade::handle<StepShape_HArray1OfFace> &)) &StepShape_OrientedOpenShell::SetCfsFaces, "None", py::arg("aCfsFaces"));
cls_StepShape_OrientedOpenShell.def("CfsFaces", (opencascade::handle<StepShape_HArray1OfFace> (StepShape_OrientedOpenShell::*)() const) &StepShape_OrientedOpenShell::CfsFaces, "None");
cls_StepShape_OrientedOpenShell.def("CfsFacesValue", (opencascade::handle<StepShape_Face> (StepShape_OrientedOpenShell::*)(const Standard_Integer) const) &StepShape_OrientedOpenShell::CfsFacesValue, "None", py::arg("num"));
cls_StepShape_OrientedOpenShell.def("NbCfsFaces", (Standard_Integer (StepShape_OrientedOpenShell::*)() const) &StepShape_OrientedOpenShell::NbCfsFaces, "None");
cls_StepShape_OrientedOpenShell.def_static("get_type_name_", (const char * (*)()) &StepShape_OrientedOpenShell::get_type_name, "None");
cls_StepShape_OrientedOpenShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_OrientedOpenShell::get_type_descriptor, "None");
cls_StepShape_OrientedOpenShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_OrientedOpenShell::*)() const) &StepShape_OrientedOpenShell::DynamicType, "None");

// Enums

}