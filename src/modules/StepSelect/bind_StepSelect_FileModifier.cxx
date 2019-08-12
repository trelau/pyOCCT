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
#include <IFSelect_GeneralModifier.hxx>
#include <IFSelect_ContextWrite.hxx>
#include <StepData_StepWriter.hxx>
#include <Standard_Handle.hxx>
#include <StepSelect_FileModifier.hxx>
#include <Standard_Type.hxx>

void bind_StepSelect_FileModifier(py::module &mod){

py::class_<StepSelect_FileModifier, opencascade::handle<StepSelect_FileModifier>, IFSelect_GeneralModifier> cls_StepSelect_FileModifier(mod, "StepSelect_FileModifier", "None");

// Fields

// Methods
cls_StepSelect_FileModifier.def("Perform", (void (StepSelect_FileModifier::*)(IFSelect_ContextWrite &, StepData_StepWriter &) const) &StepSelect_FileModifier::Perform, "Perform the action specific to each class of File Modifier <ctx> is the ContextWrite, which brings : the model, the protocol, the file name, plus the object AppliedModifiers (not used here) and the CheckList Remark that the model has to be casted for specific access", py::arg("ctx"), py::arg("writer"));
cls_StepSelect_FileModifier.def_static("get_type_name_", (const char * (*)()) &StepSelect_FileModifier::get_type_name, "None");
cls_StepSelect_FileModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_FileModifier::get_type_descriptor, "None");
cls_StepSelect_FileModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_FileModifier::*)() const) &StepSelect_FileModifier::DynamicType, "None");

// Enums

}