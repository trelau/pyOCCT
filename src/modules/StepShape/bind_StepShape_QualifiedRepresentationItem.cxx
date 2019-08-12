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
#include <StepRepr_RepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_HArray1OfValueQualifier.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_ValueQualifier.hxx>
#include <StepShape_QualifiedRepresentationItem.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_QualifiedRepresentationItem(py::module &mod){

py::class_<StepShape_QualifiedRepresentationItem, opencascade::handle<StepShape_QualifiedRepresentationItem>, StepRepr_RepresentationItem> cls_StepShape_QualifiedRepresentationItem(mod, "StepShape_QualifiedRepresentationItem", "Added for Dimensional Tolerances");

// Constructors
cls_StepShape_QualifiedRepresentationItem.def(py::init<>());

// Fields

// Methods
cls_StepShape_QualifiedRepresentationItem.def("Init", (void (StepShape_QualifiedRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_QualifiedRepresentationItem::Init, "None", py::arg("aName"), py::arg("qualifiers"));
cls_StepShape_QualifiedRepresentationItem.def("Qualifiers", (opencascade::handle<StepShape_HArray1OfValueQualifier> (StepShape_QualifiedRepresentationItem::*)() const) &StepShape_QualifiedRepresentationItem::Qualifiers, "None");
cls_StepShape_QualifiedRepresentationItem.def("NbQualifiers", (Standard_Integer (StepShape_QualifiedRepresentationItem::*)() const) &StepShape_QualifiedRepresentationItem::NbQualifiers, "None");
cls_StepShape_QualifiedRepresentationItem.def("SetQualifiers", (void (StepShape_QualifiedRepresentationItem::*)(const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_QualifiedRepresentationItem::SetQualifiers, "None", py::arg("qualifiers"));
cls_StepShape_QualifiedRepresentationItem.def("QualifiersValue", (StepShape_ValueQualifier (StepShape_QualifiedRepresentationItem::*)(const Standard_Integer) const) &StepShape_QualifiedRepresentationItem::QualifiersValue, "None", py::arg("num"));
cls_StepShape_QualifiedRepresentationItem.def("SetQualifiersValue", (void (StepShape_QualifiedRepresentationItem::*)(const Standard_Integer, const StepShape_ValueQualifier &)) &StepShape_QualifiedRepresentationItem::SetQualifiersValue, "None", py::arg("num"), py::arg("aqualifier"));
cls_StepShape_QualifiedRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepShape_QualifiedRepresentationItem::get_type_name, "None");
cls_StepShape_QualifiedRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_QualifiedRepresentationItem::get_type_descriptor, "None");
cls_StepShape_QualifiedRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_QualifiedRepresentationItem::*)() const) &StepShape_QualifiedRepresentationItem::DynamicType, "None");

// Enums

}