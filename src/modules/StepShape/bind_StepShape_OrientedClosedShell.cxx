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
#include <StepShape_ClosedShell.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_HArray1OfFace.hxx>
#include <StepShape_Face.hxx>
#include <StepShape_OrientedClosedShell.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_OrientedClosedShell(py::module &mod){

py::class_<StepShape_OrientedClosedShell, opencascade::handle<StepShape_OrientedClosedShell>, StepShape_ClosedShell> cls_StepShape_OrientedClosedShell(mod, "StepShape_OrientedClosedShell", "None");

// Constructors
cls_StepShape_OrientedClosedShell.def(py::init<>());

// Fields

// Methods
cls_StepShape_OrientedClosedShell.def("Init", (void (StepShape_OrientedClosedShell::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ClosedShell> &, const Standard_Boolean)) &StepShape_OrientedClosedShell::Init, "None", py::arg("aName"), py::arg("aClosedShellElement"), py::arg("aOrientation"));
cls_StepShape_OrientedClosedShell.def("SetClosedShellElement", (void (StepShape_OrientedClosedShell::*)(const opencascade::handle<StepShape_ClosedShell> &)) &StepShape_OrientedClosedShell::SetClosedShellElement, "None", py::arg("aClosedShellElement"));
cls_StepShape_OrientedClosedShell.def("ClosedShellElement", (opencascade::handle<StepShape_ClosedShell> (StepShape_OrientedClosedShell::*)() const) &StepShape_OrientedClosedShell::ClosedShellElement, "None");
cls_StepShape_OrientedClosedShell.def("SetOrientation", (void (StepShape_OrientedClosedShell::*)(const Standard_Boolean)) &StepShape_OrientedClosedShell::SetOrientation, "None", py::arg("aOrientation"));
cls_StepShape_OrientedClosedShell.def("Orientation", (Standard_Boolean (StepShape_OrientedClosedShell::*)() const) &StepShape_OrientedClosedShell::Orientation, "None");
cls_StepShape_OrientedClosedShell.def("SetCfsFaces", (void (StepShape_OrientedClosedShell::*)(const opencascade::handle<StepShape_HArray1OfFace> &)) &StepShape_OrientedClosedShell::SetCfsFaces, "None", py::arg("aCfsFaces"));
cls_StepShape_OrientedClosedShell.def("CfsFaces", (opencascade::handle<StepShape_HArray1OfFace> (StepShape_OrientedClosedShell::*)() const) &StepShape_OrientedClosedShell::CfsFaces, "None");
cls_StepShape_OrientedClosedShell.def("CfsFacesValue", (opencascade::handle<StepShape_Face> (StepShape_OrientedClosedShell::*)(const Standard_Integer) const) &StepShape_OrientedClosedShell::CfsFacesValue, "None", py::arg("num"));
cls_StepShape_OrientedClosedShell.def("NbCfsFaces", (Standard_Integer (StepShape_OrientedClosedShell::*)() const) &StepShape_OrientedClosedShell::NbCfsFaces, "None");
cls_StepShape_OrientedClosedShell.def_static("get_type_name_", (const char * (*)()) &StepShape_OrientedClosedShell::get_type_name, "None");
cls_StepShape_OrientedClosedShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_OrientedClosedShell::get_type_descriptor, "None");
cls_StepShape_OrientedClosedShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_OrientedClosedShell::*)() const) &StepShape_OrientedClosedShell::DynamicType, "None");

// Enums

}