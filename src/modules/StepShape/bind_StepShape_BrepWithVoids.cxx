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
#include <StepShape_ManifoldSolidBrep.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_ClosedShell.hxx>
#include <StepShape_HArray1OfOrientedClosedShell.hxx>
#include <StepShape_OrientedClosedShell.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_BrepWithVoids.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_BrepWithVoids(py::module &mod){

py::class_<StepShape_BrepWithVoids, opencascade::handle<StepShape_BrepWithVoids>, StepShape_ManifoldSolidBrep> cls_StepShape_BrepWithVoids(mod, "StepShape_BrepWithVoids", "None");

// Constructors
cls_StepShape_BrepWithVoids.def(py::init<>());

// Fields

// Methods
cls_StepShape_BrepWithVoids.def("Init", (void (StepShape_BrepWithVoids::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ClosedShell> &, const opencascade::handle<StepShape_HArray1OfOrientedClosedShell> &)) &StepShape_BrepWithVoids::Init, "None", py::arg("aName"), py::arg("aOuter"), py::arg("aVoids"));
cls_StepShape_BrepWithVoids.def("SetVoids", (void (StepShape_BrepWithVoids::*)(const opencascade::handle<StepShape_HArray1OfOrientedClosedShell> &)) &StepShape_BrepWithVoids::SetVoids, "None", py::arg("aVoids"));
cls_StepShape_BrepWithVoids.def("Voids", (opencascade::handle<StepShape_HArray1OfOrientedClosedShell> (StepShape_BrepWithVoids::*)() const) &StepShape_BrepWithVoids::Voids, "None");
cls_StepShape_BrepWithVoids.def("VoidsValue", (opencascade::handle<StepShape_OrientedClosedShell> (StepShape_BrepWithVoids::*)(const Standard_Integer) const) &StepShape_BrepWithVoids::VoidsValue, "None", py::arg("num"));
cls_StepShape_BrepWithVoids.def("NbVoids", (Standard_Integer (StepShape_BrepWithVoids::*)() const) &StepShape_BrepWithVoids::NbVoids, "None");
cls_StepShape_BrepWithVoids.def_static("get_type_name_", (const char * (*)()) &StepShape_BrepWithVoids::get_type_name, "None");
cls_StepShape_BrepWithVoids.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_BrepWithVoids::get_type_descriptor, "None");
cls_StepShape_BrepWithVoids.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_BrepWithVoids::*)() const) &StepShape_BrepWithVoids::DynamicType, "None");

// Enums

}