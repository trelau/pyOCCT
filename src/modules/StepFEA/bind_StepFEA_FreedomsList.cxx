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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <StepFEA_HArray1OfDegreeOfFreedom.hxx>
#include <StepFEA_FreedomsList.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FreedomsList(py::module &mod){

py::class_<StepFEA_FreedomsList, opencascade::handle<StepFEA_FreedomsList>, Standard_Transient> cls_StepFEA_FreedomsList(mod, "StepFEA_FreedomsList", "Representation of STEP entity FreedomsList");

// Constructors
cls_StepFEA_FreedomsList.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FreedomsList.def("Init", (void (StepFEA_FreedomsList::*)(const opencascade::handle<StepFEA_HArray1OfDegreeOfFreedom> &)) &StepFEA_FreedomsList::Init, "Initialize all fields (own and inherited)", py::arg("aFreedoms"));
cls_StepFEA_FreedomsList.def("Freedoms", (opencascade::handle<StepFEA_HArray1OfDegreeOfFreedom> (StepFEA_FreedomsList::*)() const) &StepFEA_FreedomsList::Freedoms, "Returns field Freedoms");
cls_StepFEA_FreedomsList.def("SetFreedoms", (void (StepFEA_FreedomsList::*)(const opencascade::handle<StepFEA_HArray1OfDegreeOfFreedom> &)) &StepFEA_FreedomsList::SetFreedoms, "Set field Freedoms", py::arg("Freedoms"));
cls_StepFEA_FreedomsList.def_static("get_type_name_", (const char * (*)()) &StepFEA_FreedomsList::get_type_name, "None");
cls_StepFEA_FreedomsList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FreedomsList::get_type_descriptor, "None");
cls_StepFEA_FreedomsList.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FreedomsList::*)() const) &StepFEA_FreedomsList::DynamicType, "None");

// Enums

}