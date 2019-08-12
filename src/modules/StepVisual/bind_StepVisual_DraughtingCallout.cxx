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
#include <StepVisual_HArray1OfDraughtingCalloutElement.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_DraughtingCalloutElement.hxx>
#include <StepVisual_DraughtingCallout.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_DraughtingCallout(py::module &mod){

py::class_<StepVisual_DraughtingCallout, opencascade::handle<StepVisual_DraughtingCallout>, StepGeom_GeometricRepresentationItem> cls_StepVisual_DraughtingCallout(mod, "StepVisual_DraughtingCallout", "None");

// Constructors
cls_StepVisual_DraughtingCallout.def(py::init<>());

// Fields

// Methods
cls_StepVisual_DraughtingCallout.def("Init", (void (StepVisual_DraughtingCallout::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfDraughtingCalloutElement> &)) &StepVisual_DraughtingCallout::Init, "Init", py::arg("theName"), py::arg("theContents"));
cls_StepVisual_DraughtingCallout.def("Contents", (opencascade::handle<StepVisual_HArray1OfDraughtingCalloutElement> (StepVisual_DraughtingCallout::*)() const) &StepVisual_DraughtingCallout::Contents, "Returns field Contents");
cls_StepVisual_DraughtingCallout.def("SetContents", (void (StepVisual_DraughtingCallout::*)(const opencascade::handle<StepVisual_HArray1OfDraughtingCalloutElement> &)) &StepVisual_DraughtingCallout::SetContents, "Set field Contents", py::arg("theContents"));
cls_StepVisual_DraughtingCallout.def("NbContents", (Standard_Integer (StepVisual_DraughtingCallout::*)() const) &StepVisual_DraughtingCallout::NbContents, "Returns number of Contents");
cls_StepVisual_DraughtingCallout.def("ContentsValue", (StepVisual_DraughtingCalloutElement (StepVisual_DraughtingCallout::*)(const Standard_Integer) const) &StepVisual_DraughtingCallout::ContentsValue, "Returns Contents with the given number", py::arg("theNum"));
cls_StepVisual_DraughtingCallout.def("SetContentsValue", (void (StepVisual_DraughtingCallout::*)(const Standard_Integer, const StepVisual_DraughtingCalloutElement &)) &StepVisual_DraughtingCallout::SetContentsValue, "Sets Contents with given number", py::arg("theNum"), py::arg("theItem"));
cls_StepVisual_DraughtingCallout.def_static("get_type_name_", (const char * (*)()) &StepVisual_DraughtingCallout::get_type_name, "None");
cls_StepVisual_DraughtingCallout.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_DraughtingCallout::get_type_descriptor, "None");
cls_StepVisual_DraughtingCallout.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_DraughtingCallout::*)() const) &StepVisual_DraughtingCallout::DynamicType, "None");

// Enums

}