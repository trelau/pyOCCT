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
#include <StepFEA_FeaGroup.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepFEA_FeaModel.hxx>
#include <StepFEA_HArray1OfElementRepresentation.hxx>
#include <StepFEA_ElementGroup.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_ElementGroup(py::module &mod){

py::class_<StepFEA_ElementGroup, opencascade::handle<StepFEA_ElementGroup>, StepFEA_FeaGroup> cls_StepFEA_ElementGroup(mod, "StepFEA_ElementGroup", "Representation of STEP entity ElementGroup");

// Constructors
cls_StepFEA_ElementGroup.def(py::init<>());

// Fields

// Methods
cls_StepFEA_ElementGroup.def("Init", (void (StepFEA_ElementGroup::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_FeaModel> &, const opencascade::handle<StepFEA_HArray1OfElementRepresentation> &)) &StepFEA_ElementGroup::Init, "Initialize all fields (own and inherited)", py::arg("aGroup_Name"), py::arg("aGroup_Description"), py::arg("aFeaGroup_ModelRef"), py::arg("aElements"));
cls_StepFEA_ElementGroup.def("Elements", (opencascade::handle<StepFEA_HArray1OfElementRepresentation> (StepFEA_ElementGroup::*)() const) &StepFEA_ElementGroup::Elements, "Returns field Elements");
cls_StepFEA_ElementGroup.def("SetElements", (void (StepFEA_ElementGroup::*)(const opencascade::handle<StepFEA_HArray1OfElementRepresentation> &)) &StepFEA_ElementGroup::SetElements, "Set field Elements", py::arg("Elements"));
cls_StepFEA_ElementGroup.def_static("get_type_name_", (const char * (*)()) &StepFEA_ElementGroup::get_type_name, "None");
cls_StepFEA_ElementGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ElementGroup::get_type_descriptor, "None");
cls_StepFEA_ElementGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ElementGroup::*)() const) &StepFEA_ElementGroup::DynamicType, "None");

// Enums

}