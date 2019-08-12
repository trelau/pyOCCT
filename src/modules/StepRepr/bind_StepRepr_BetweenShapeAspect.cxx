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
#include <StepRepr_ContinuosShapeAspect.hxx>
#include <Standard_Handle.hxx>
#include <StepRepr_BetweenShapeAspect.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_BetweenShapeAspect(py::module &mod){

py::class_<StepRepr_BetweenShapeAspect, opencascade::handle<StepRepr_BetweenShapeAspect>, StepRepr_ContinuosShapeAspect> cls_StepRepr_BetweenShapeAspect(mod, "StepRepr_BetweenShapeAspect", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_BetweenShapeAspect.def(py::init<>());

// Fields

// Methods
cls_StepRepr_BetweenShapeAspect.def_static("get_type_name_", (const char * (*)()) &StepRepr_BetweenShapeAspect::get_type_name, "None");
cls_StepRepr_BetweenShapeAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_BetweenShapeAspect::get_type_descriptor, "None");
cls_StepRepr_BetweenShapeAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_BetweenShapeAspect::*)() const) &StepRepr_BetweenShapeAspect::DynamicType, "None");

// Enums

}