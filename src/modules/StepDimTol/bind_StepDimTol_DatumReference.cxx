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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepDimTol_Datum.hxx>
#include <StepDimTol_DatumReference.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_DatumReference(py::module &mod){

py::class_<StepDimTol_DatumReference, opencascade::handle<StepDimTol_DatumReference>, Standard_Transient> cls_StepDimTol_DatumReference(mod, "StepDimTol_DatumReference", "Representation of STEP entity DatumReference");

// Constructors
cls_StepDimTol_DatumReference.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_DatumReference.def("Init", (void (StepDimTol_DatumReference::*)(const Standard_Integer, const opencascade::handle<StepDimTol_Datum> &)) &StepDimTol_DatumReference::Init, "Initialize all fields (own and inherited)", py::arg("thePrecedence"), py::arg("theReferencedDatum"));
cls_StepDimTol_DatumReference.def("Precedence", (Standard_Integer (StepDimTol_DatumReference::*)() const) &StepDimTol_DatumReference::Precedence, "Returns field Precedence");
cls_StepDimTol_DatumReference.def("SetPrecedence", (void (StepDimTol_DatumReference::*)(const Standard_Integer)) &StepDimTol_DatumReference::SetPrecedence, "Set field Precedence", py::arg("thePrecedence"));
cls_StepDimTol_DatumReference.def("ReferencedDatum", (opencascade::handle<StepDimTol_Datum> (StepDimTol_DatumReference::*)() const) &StepDimTol_DatumReference::ReferencedDatum, "Returns field ReferencedDatum");
cls_StepDimTol_DatumReference.def("SetReferencedDatum", (void (StepDimTol_DatumReference::*)(const opencascade::handle<StepDimTol_Datum> &)) &StepDimTol_DatumReference::SetReferencedDatum, "Set field ReferencedDatum", py::arg("theReferencedDatum"));
cls_StepDimTol_DatumReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumReference::get_type_name, "None");
cls_StepDimTol_DatumReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumReference::get_type_descriptor, "None");
cls_StepDimTol_DatumReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumReference::*)() const) &StepDimTol_DatumReference::DynamicType, "None");

// Enums

}