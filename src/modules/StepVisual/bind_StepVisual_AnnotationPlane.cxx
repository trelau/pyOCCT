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
#include <StepVisual_HArray1OfAnnotationPlaneElement.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_AnnotationPlaneElement.hxx>
#include <StepVisual_AnnotationPlane.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_AnnotationPlane(py::module &mod){

py::class_<StepVisual_AnnotationPlane, opencascade::handle<StepVisual_AnnotationPlane>, StepVisual_AnnotationOccurrence> cls_StepVisual_AnnotationPlane(mod, "StepVisual_AnnotationPlane", "None");

// Constructors
cls_StepVisual_AnnotationPlane.def(py::init<>());

// Fields

// Methods
cls_StepVisual_AnnotationPlane.def("Init", (void (StepVisual_AnnotationPlane::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<StepVisual_HArray1OfAnnotationPlaneElement> &)) &StepVisual_AnnotationPlane::Init, "None", py::arg("theName"), py::arg("theStyles"), py::arg("theItem"), py::arg("theElements"));
cls_StepVisual_AnnotationPlane.def("Elements", (opencascade::handle<StepVisual_HArray1OfAnnotationPlaneElement> (StepVisual_AnnotationPlane::*)() const) &StepVisual_AnnotationPlane::Elements, "Returns field Elements");
cls_StepVisual_AnnotationPlane.def("SetElements", (void (StepVisual_AnnotationPlane::*)(const opencascade::handle<StepVisual_HArray1OfAnnotationPlaneElement> &)) &StepVisual_AnnotationPlane::SetElements, "Set field Elements", py::arg("theElements"));
cls_StepVisual_AnnotationPlane.def("NbElements", (Standard_Integer (StepVisual_AnnotationPlane::*)() const) &StepVisual_AnnotationPlane::NbElements, "Returns number of Elements");
cls_StepVisual_AnnotationPlane.def("ElementsValue", (StepVisual_AnnotationPlaneElement (StepVisual_AnnotationPlane::*)(const Standard_Integer) const) &StepVisual_AnnotationPlane::ElementsValue, "Returns Elements with the given number", py::arg("theNum"));
cls_StepVisual_AnnotationPlane.def("SetElementsValue", (void (StepVisual_AnnotationPlane::*)(const Standard_Integer, const StepVisual_AnnotationPlaneElement &)) &StepVisual_AnnotationPlane::SetElementsValue, "Sets Elements with given number", py::arg("theNum"), py::arg("theItem"));
cls_StepVisual_AnnotationPlane.def_static("get_type_name_", (const char * (*)()) &StepVisual_AnnotationPlane::get_type_name, "None");
cls_StepVisual_AnnotationPlane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AnnotationPlane::get_type_descriptor, "None");
cls_StepVisual_AnnotationPlane.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AnnotationPlane::*)() const) &StepVisual_AnnotationPlane::DynamicType, "None");

// Enums

}