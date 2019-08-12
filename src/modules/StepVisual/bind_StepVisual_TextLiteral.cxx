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
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Axis2Placement.hxx>
#include <StepVisual_TextPath.hxx>
#include <StepVisual_FontSelect.hxx>
#include <StepVisual_TextLiteral.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_TextLiteral(py::module &mod){

py::class_<StepVisual_TextLiteral, opencascade::handle<StepVisual_TextLiteral>, StepGeom_GeometricRepresentationItem> cls_StepVisual_TextLiteral(mod, "StepVisual_TextLiteral", "None");

// Constructors
cls_StepVisual_TextLiteral.def(py::init<>());

// Fields

// Methods
cls_StepVisual_TextLiteral.def("Init", (void (StepVisual_TextLiteral::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const StepGeom_Axis2Placement &, const opencascade::handle<TCollection_HAsciiString> &, const StepVisual_TextPath, const StepVisual_FontSelect &)) &StepVisual_TextLiteral::Init, "None", py::arg("aName"), py::arg("aLiteral"), py::arg("aPlacement"), py::arg("aAlignment"), py::arg("aPath"), py::arg("aFont"));
cls_StepVisual_TextLiteral.def("SetLiteral", (void (StepVisual_TextLiteral::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_TextLiteral::SetLiteral, "None", py::arg("aLiteral"));
cls_StepVisual_TextLiteral.def("Literal", (opencascade::handle<TCollection_HAsciiString> (StepVisual_TextLiteral::*)() const) &StepVisual_TextLiteral::Literal, "None");
cls_StepVisual_TextLiteral.def("SetPlacement", (void (StepVisual_TextLiteral::*)(const StepGeom_Axis2Placement &)) &StepVisual_TextLiteral::SetPlacement, "None", py::arg("aPlacement"));
cls_StepVisual_TextLiteral.def("Placement", (StepGeom_Axis2Placement (StepVisual_TextLiteral::*)() const) &StepVisual_TextLiteral::Placement, "None");
cls_StepVisual_TextLiteral.def("SetAlignment", (void (StepVisual_TextLiteral::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_TextLiteral::SetAlignment, "None", py::arg("aAlignment"));
cls_StepVisual_TextLiteral.def("Alignment", (opencascade::handle<TCollection_HAsciiString> (StepVisual_TextLiteral::*)() const) &StepVisual_TextLiteral::Alignment, "None");
cls_StepVisual_TextLiteral.def("SetPath", (void (StepVisual_TextLiteral::*)(const StepVisual_TextPath)) &StepVisual_TextLiteral::SetPath, "None", py::arg("aPath"));
cls_StepVisual_TextLiteral.def("Path", (StepVisual_TextPath (StepVisual_TextLiteral::*)() const) &StepVisual_TextLiteral::Path, "None");
cls_StepVisual_TextLiteral.def("SetFont", (void (StepVisual_TextLiteral::*)(const StepVisual_FontSelect &)) &StepVisual_TextLiteral::SetFont, "None", py::arg("aFont"));
cls_StepVisual_TextLiteral.def("Font", (StepVisual_FontSelect (StepVisual_TextLiteral::*)() const) &StepVisual_TextLiteral::Font, "None");
cls_StepVisual_TextLiteral.def_static("get_type_name_", (const char * (*)()) &StepVisual_TextLiteral::get_type_name, "None");
cls_StepVisual_TextLiteral.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TextLiteral::get_type_descriptor, "None");
cls_StepVisual_TextLiteral.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TextLiteral::*)() const) &StepVisual_TextLiteral::DynamicType, "None");

// Enums

}