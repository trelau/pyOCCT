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
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_HArray1OfMaterialPropertyRepresentation.hxx>
#include <StepElement_ElementMaterial.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_ElementMaterial(py::module &mod){

py::class_<StepElement_ElementMaterial, opencascade::handle<StepElement_ElementMaterial>, Standard_Transient> cls_StepElement_ElementMaterial(mod, "StepElement_ElementMaterial", "Representation of STEP entity ElementMaterial");

// Constructors
cls_StepElement_ElementMaterial.def(py::init<>());

// Fields

// Methods
cls_StepElement_ElementMaterial.def("Init", (void (StepElement_ElementMaterial::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfMaterialPropertyRepresentation> &)) &StepElement_ElementMaterial::Init, "Initialize all fields (own and inherited)", py::arg("aMaterialId"), py::arg("aDescription"), py::arg("aProperties"));
cls_StepElement_ElementMaterial.def("MaterialId", (opencascade::handle<TCollection_HAsciiString> (StepElement_ElementMaterial::*)() const) &StepElement_ElementMaterial::MaterialId, "Returns field MaterialId");
cls_StepElement_ElementMaterial.def("SetMaterialId", (void (StepElement_ElementMaterial::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_ElementMaterial::SetMaterialId, "Set field MaterialId", py::arg("MaterialId"));
cls_StepElement_ElementMaterial.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepElement_ElementMaterial::*)() const) &StepElement_ElementMaterial::Description, "Returns field Description");
cls_StepElement_ElementMaterial.def("SetDescription", (void (StepElement_ElementMaterial::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_ElementMaterial::SetDescription, "Set field Description", py::arg("Description"));
cls_StepElement_ElementMaterial.def("Properties", (opencascade::handle<StepRepr_HArray1OfMaterialPropertyRepresentation> (StepElement_ElementMaterial::*)() const) &StepElement_ElementMaterial::Properties, "Returns field Properties");
cls_StepElement_ElementMaterial.def("SetProperties", (void (StepElement_ElementMaterial::*)(const opencascade::handle<StepRepr_HArray1OfMaterialPropertyRepresentation> &)) &StepElement_ElementMaterial::SetProperties, "Set field Properties", py::arg("Properties"));
cls_StepElement_ElementMaterial.def_static("get_type_name_", (const char * (*)()) &StepElement_ElementMaterial::get_type_name, "None");
cls_StepElement_ElementMaterial.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_ElementMaterial::get_type_descriptor, "None");
cls_StepElement_ElementMaterial.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_ElementMaterial::*)() const) &StepElement_ElementMaterial::DynamicType, "None");

// Enums

}