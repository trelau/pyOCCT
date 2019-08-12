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
#include <StepAP242_ItemIdentifiedRepresentationUsage.hxx>
#include <Standard_Handle.hxx>
#include <StepAP242_DraughtingModelItemAssociation.hxx>
#include <Standard_Type.hxx>

void bind_StepAP242_DraughtingModelItemAssociation(py::module &mod){

py::class_<StepAP242_DraughtingModelItemAssociation, opencascade::handle<StepAP242_DraughtingModelItemAssociation>, StepAP242_ItemIdentifiedRepresentationUsage> cls_StepAP242_DraughtingModelItemAssociation(mod, "StepAP242_DraughtingModelItemAssociation", "Added for Dimensional Tolerances");

// Constructors
cls_StepAP242_DraughtingModelItemAssociation.def(py::init<>());

// Fields

// Methods
cls_StepAP242_DraughtingModelItemAssociation.def_static("get_type_name_", (const char * (*)()) &StepAP242_DraughtingModelItemAssociation::get_type_name, "None");
cls_StepAP242_DraughtingModelItemAssociation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP242_DraughtingModelItemAssociation::get_type_descriptor, "None");
cls_StepAP242_DraughtingModelItemAssociation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP242_DraughtingModelItemAssociation::*)() const) &StepAP242_DraughtingModelItemAssociation::DynamicType, "None");

// Enums

}