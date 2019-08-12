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
#include <StepVisual_PlanarExtent.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Axis2Placement.hxx>
#include <StepVisual_PlanarBox.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_PlanarBox(py::module &mod){

py::class_<StepVisual_PlanarBox, opencascade::handle<StepVisual_PlanarBox>, StepVisual_PlanarExtent> cls_StepVisual_PlanarBox(mod, "StepVisual_PlanarBox", "None");

// Constructors
cls_StepVisual_PlanarBox.def(py::init<>());

// Fields

// Methods
cls_StepVisual_PlanarBox.def("Init", (void (StepVisual_PlanarBox::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const StepGeom_Axis2Placement &)) &StepVisual_PlanarBox::Init, "None", py::arg("aName"), py::arg("aSizeInX"), py::arg("aSizeInY"), py::arg("aPlacement"));
cls_StepVisual_PlanarBox.def("SetPlacement", (void (StepVisual_PlanarBox::*)(const StepGeom_Axis2Placement &)) &StepVisual_PlanarBox::SetPlacement, "None", py::arg("aPlacement"));
cls_StepVisual_PlanarBox.def("Placement", (StepGeom_Axis2Placement (StepVisual_PlanarBox::*)() const) &StepVisual_PlanarBox::Placement, "None");
cls_StepVisual_PlanarBox.def_static("get_type_name_", (const char * (*)()) &StepVisual_PlanarBox::get_type_name, "None");
cls_StepVisual_PlanarBox.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PlanarBox::get_type_descriptor, "None");
cls_StepVisual_PlanarBox.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PlanarBox::*)() const) &StepVisual_PlanarBox::DynamicType, "None");

// Enums

}