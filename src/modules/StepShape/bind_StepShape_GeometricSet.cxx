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
#include <StepShape_HArray1OfGeometricSetSelect.hxx>
#include <StepShape_GeometricSetSelect.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_GeometricSet.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_GeometricSet(py::module &mod){

py::class_<StepShape_GeometricSet, opencascade::handle<StepShape_GeometricSet>, StepGeom_GeometricRepresentationItem> cls_StepShape_GeometricSet(mod, "StepShape_GeometricSet", "None");

// Constructors
cls_StepShape_GeometricSet.def(py::init<>());

// Fields

// Methods
cls_StepShape_GeometricSet.def("Init", (void (StepShape_GeometricSet::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfGeometricSetSelect> &)) &StepShape_GeometricSet::Init, "None", py::arg("aName"), py::arg("aElements"));
cls_StepShape_GeometricSet.def("SetElements", (void (StepShape_GeometricSet::*)(const opencascade::handle<StepShape_HArray1OfGeometricSetSelect> &)) &StepShape_GeometricSet::SetElements, "None", py::arg("aElements"));
cls_StepShape_GeometricSet.def("Elements", (opencascade::handle<StepShape_HArray1OfGeometricSetSelect> (StepShape_GeometricSet::*)() const) &StepShape_GeometricSet::Elements, "None");
cls_StepShape_GeometricSet.def("ElementsValue", (StepShape_GeometricSetSelect (StepShape_GeometricSet::*)(const Standard_Integer) const) &StepShape_GeometricSet::ElementsValue, "None", py::arg("num"));
cls_StepShape_GeometricSet.def("NbElements", (Standard_Integer (StepShape_GeometricSet::*)() const) &StepShape_GeometricSet::NbElements, "None");
cls_StepShape_GeometricSet.def_static("get_type_name_", (const char * (*)()) &StepShape_GeometricSet::get_type_name, "None");
cls_StepShape_GeometricSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_GeometricSet::get_type_descriptor, "None");
cls_StepShape_GeometricSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_GeometricSet::*)() const) &StepShape_GeometricSet::DynamicType, "None");

// Enums

}