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
#include <StepVisual_HArray1OfTextOrCharacter.hxx>
#include <StepVisual_TextOrCharacter.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_CompositeText.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_CompositeText(py::module &mod){

py::class_<StepVisual_CompositeText, opencascade::handle<StepVisual_CompositeText>, StepGeom_GeometricRepresentationItem> cls_StepVisual_CompositeText(mod, "StepVisual_CompositeText", "None");

// Constructors
cls_StepVisual_CompositeText.def(py::init<>());

// Fields

// Methods
cls_StepVisual_CompositeText.def("Init", (void (StepVisual_CompositeText::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfTextOrCharacter> &)) &StepVisual_CompositeText::Init, "None", py::arg("aName"), py::arg("aCollectedText"));
cls_StepVisual_CompositeText.def("SetCollectedText", (void (StepVisual_CompositeText::*)(const opencascade::handle<StepVisual_HArray1OfTextOrCharacter> &)) &StepVisual_CompositeText::SetCollectedText, "None", py::arg("aCollectedText"));
cls_StepVisual_CompositeText.def("CollectedText", (opencascade::handle<StepVisual_HArray1OfTextOrCharacter> (StepVisual_CompositeText::*)() const) &StepVisual_CompositeText::CollectedText, "None");
cls_StepVisual_CompositeText.def("CollectedTextValue", (StepVisual_TextOrCharacter (StepVisual_CompositeText::*)(const Standard_Integer) const) &StepVisual_CompositeText::CollectedTextValue, "None", py::arg("num"));
cls_StepVisual_CompositeText.def("NbCollectedText", (Standard_Integer (StepVisual_CompositeText::*)() const) &StepVisual_CompositeText::NbCollectedText, "None");
cls_StepVisual_CompositeText.def_static("get_type_name_", (const char * (*)()) &StepVisual_CompositeText::get_type_name, "None");
cls_StepVisual_CompositeText.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CompositeText::get_type_descriptor, "None");
cls_StepVisual_CompositeText.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CompositeText::*)() const) &StepVisual_CompositeText::DynamicType, "None");

// Enums

}