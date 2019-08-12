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
#include <StepRepr_CompShAspAndDatumFeatAndShAsp.hxx>
#include <Standard_Handle.hxx>
#include <StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp(py::module &mod){

py::class_<StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp, opencascade::handle<StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp>, StepRepr_CompShAspAndDatumFeatAndShAsp> cls_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp(mod, "StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def(py::init<>());

// Fields

// Methods
cls_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def_static("get_type_name_", (const char * (*)()) &StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp::get_type_name, "None");
cls_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp::get_type_descriptor, "None");
cls_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp::*)() const) &StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp::DynamicType, "None");

// Enums

}