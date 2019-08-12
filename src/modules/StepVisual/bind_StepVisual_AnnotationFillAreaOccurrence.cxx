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
#include <StepVisual_AnnotationOccurrence.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepVisual_HArray1OfPresentationStyleAssignment.hxx>
#include <Standard_Transient.hxx>
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <StepVisual_AnnotationFillAreaOccurrence.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_AnnotationFillAreaOccurrence(py::module &mod){

py::class_<StepVisual_AnnotationFillAreaOccurrence, opencascade::handle<StepVisual_AnnotationFillAreaOccurrence>, StepVisual_AnnotationOccurrence> cls_StepVisual_AnnotationFillAreaOccurrence(mod, "StepVisual_AnnotationFillAreaOccurrence", "None");

// Constructors
cls_StepVisual_AnnotationFillAreaOccurrence.def(py::init<>());

// Fields

// Methods
cls_StepVisual_AnnotationFillAreaOccurrence.def("Init", (void (StepVisual_AnnotationFillAreaOccurrence::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<StepGeom_GeometricRepresentationItem> &)) &StepVisual_AnnotationFillAreaOccurrence::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theStyles"), py::arg("theItem"), py::arg("theFillStyleTarget"));
cls_StepVisual_AnnotationFillAreaOccurrence.def("FillStyleTarget", (opencascade::handle<StepGeom_GeometricRepresentationItem> (StepVisual_AnnotationFillAreaOccurrence::*)() const) &StepVisual_AnnotationFillAreaOccurrence::FillStyleTarget, "Returns field fill_style_target");
cls_StepVisual_AnnotationFillAreaOccurrence.def("SetFillStyleTarget", (void (StepVisual_AnnotationFillAreaOccurrence::*)(const opencascade::handle<StepGeom_GeometricRepresentationItem> &)) &StepVisual_AnnotationFillAreaOccurrence::SetFillStyleTarget, "Set field fill_style_target", py::arg("theTarget"));
cls_StepVisual_AnnotationFillAreaOccurrence.def_static("get_type_name_", (const char * (*)()) &StepVisual_AnnotationFillAreaOccurrence::get_type_name, "None");
cls_StepVisual_AnnotationFillAreaOccurrence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AnnotationFillAreaOccurrence::get_type_descriptor, "None");
cls_StepVisual_AnnotationFillAreaOccurrence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AnnotationFillAreaOccurrence::*)() const) &StepVisual_AnnotationFillAreaOccurrence::DynamicType, "None");

// Enums

}