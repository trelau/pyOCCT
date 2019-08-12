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
#include <StepRepr_ShapeAspect.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepData_Logical.hxx>
#include <StepDimTol_DatumOrCommonDatum.hxx>
#include <Standard_TypeDef.hxx>
#include <StepDimTol_HArray1OfDatumReferenceModifier.hxx>
#include <StepDimTol_DatumReferenceModifier.hxx>
#include <StepDimTol_GeneralDatumReference.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_GeneralDatumReference(py::module &mod){

py::class_<StepDimTol_GeneralDatumReference, opencascade::handle<StepDimTol_GeneralDatumReference>, StepRepr_ShapeAspect> cls_StepDimTol_GeneralDatumReference(mod, "StepDimTol_GeneralDatumReference", "Representation of STEP entity GeneralDatumReference");

// Constructors
cls_StepDimTol_GeneralDatumReference.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_GeneralDatumReference.def("Init", (void (StepDimTol_GeneralDatumReference::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const StepDimTol_DatumOrCommonDatum &, const Standard_Boolean, const opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier> &)) &StepDimTol_GeneralDatumReference::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theOfShape"), py::arg("theProductDefinitional"), py::arg("theBase"), py::arg("theHasModifiers"), py::arg("theModifiers"));
cls_StepDimTol_GeneralDatumReference.def("Base", (StepDimTol_DatumOrCommonDatum (StepDimTol_GeneralDatumReference::*)()) &StepDimTol_GeneralDatumReference::Base, "Returns field Base");
cls_StepDimTol_GeneralDatumReference.def("SetBase", (void (StepDimTol_GeneralDatumReference::*)(const StepDimTol_DatumOrCommonDatum &)) &StepDimTol_GeneralDatumReference::SetBase, "Set field Base", py::arg("theBase"));
cls_StepDimTol_GeneralDatumReference.def("HasModifiers", (Standard_Boolean (StepDimTol_GeneralDatumReference::*)() const) &StepDimTol_GeneralDatumReference::HasModifiers, "Indicates is field Modifiers exist");
cls_StepDimTol_GeneralDatumReference.def("Modifiers", (opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier> (StepDimTol_GeneralDatumReference::*)()) &StepDimTol_GeneralDatumReference::Modifiers, "Returns field Modifiers");
cls_StepDimTol_GeneralDatumReference.def("SetModifiers", (void (StepDimTol_GeneralDatumReference::*)(const opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier> &)) &StepDimTol_GeneralDatumReference::SetModifiers, "Set field Modifiers", py::arg("theModifiers"));
cls_StepDimTol_GeneralDatumReference.def("NbModifiers", (Standard_Integer (StepDimTol_GeneralDatumReference::*)() const) &StepDimTol_GeneralDatumReference::NbModifiers, "Returns number of Modifiers");
cls_StepDimTol_GeneralDatumReference.def("ModifiersValue", (StepDimTol_DatumReferenceModifier (StepDimTol_GeneralDatumReference::*)(const Standard_Integer) const) &StepDimTol_GeneralDatumReference::ModifiersValue, "Returns Modifiers with the given number", py::arg("theNum"));
cls_StepDimTol_GeneralDatumReference.def("ModifiersValue", (void (StepDimTol_GeneralDatumReference::*)(const Standard_Integer, const StepDimTol_DatumReferenceModifier &)) &StepDimTol_GeneralDatumReference::ModifiersValue, "Sets Modifiers with given number", py::arg("theNum"), py::arg("theItem"));
cls_StepDimTol_GeneralDatumReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeneralDatumReference::get_type_name, "None");
cls_StepDimTol_GeneralDatumReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeneralDatumReference::get_type_descriptor, "None");
cls_StepDimTol_GeneralDatumReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeneralDatumReference::*)() const) &StepDimTol_GeneralDatumReference::DynamicType, "None");

// Enums

}