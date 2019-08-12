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
#include <StepVisual_CompositeText.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepVisual_HArray1OfTextOrCharacter.hxx>
#include <StepVisual_PlanarExtent.hxx>
#include <StepVisual_CompositeTextWithExtent.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_CompositeTextWithExtent(py::module &mod){

py::class_<StepVisual_CompositeTextWithExtent, opencascade::handle<StepVisual_CompositeTextWithExtent>, StepVisual_CompositeText> cls_StepVisual_CompositeTextWithExtent(mod, "StepVisual_CompositeTextWithExtent", "None");

// Constructors
cls_StepVisual_CompositeTextWithExtent.def(py::init<>());

// Fields

// Methods
cls_StepVisual_CompositeTextWithExtent.def("Init", (void (StepVisual_CompositeTextWithExtent::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfTextOrCharacter> &, const opencascade::handle<StepVisual_PlanarExtent> &)) &StepVisual_CompositeTextWithExtent::Init, "None", py::arg("aName"), py::arg("aCollectedText"), py::arg("aExtent"));
cls_StepVisual_CompositeTextWithExtent.def("SetExtent", (void (StepVisual_CompositeTextWithExtent::*)(const opencascade::handle<StepVisual_PlanarExtent> &)) &StepVisual_CompositeTextWithExtent::SetExtent, "None", py::arg("aExtent"));
cls_StepVisual_CompositeTextWithExtent.def("Extent", (opencascade::handle<StepVisual_PlanarExtent> (StepVisual_CompositeTextWithExtent::*)() const) &StepVisual_CompositeTextWithExtent::Extent, "None");
cls_StepVisual_CompositeTextWithExtent.def_static("get_type_name_", (const char * (*)()) &StepVisual_CompositeTextWithExtent::get_type_name, "None");
cls_StepVisual_CompositeTextWithExtent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CompositeTextWithExtent::get_type_descriptor, "None");
cls_StepVisual_CompositeTextWithExtent.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CompositeTextWithExtent::*)() const) &StepVisual_CompositeTextWithExtent::DynamicType, "None");

// Enums

}