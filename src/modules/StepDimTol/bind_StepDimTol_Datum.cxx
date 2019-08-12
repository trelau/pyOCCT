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
#include <StepDimTol_Datum.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_Datum(py::module &mod){

py::class_<StepDimTol_Datum, opencascade::handle<StepDimTol_Datum>, StepRepr_ShapeAspect> cls_StepDimTol_Datum(mod, "StepDimTol_Datum", "Representation of STEP entity Datum");

// Constructors
cls_StepDimTol_Datum.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_Datum.def("Init", (void (StepDimTol_Datum::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_Datum::Init, "Initialize all fields (own and inherited)", py::arg("theShapeAspect_Name"), py::arg("theShapeAspect_Description"), py::arg("theShapeAspect_OfShape"), py::arg("theShapeAspect_ProductDefinitional"), py::arg("theIdentification"));
cls_StepDimTol_Datum.def("Identification", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_Datum::*)() const) &StepDimTol_Datum::Identification, "Returns field Identification");
cls_StepDimTol_Datum.def("SetIdentification", (void (StepDimTol_Datum::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_Datum::SetIdentification, "Set field Identification", py::arg("theIdentification"));
cls_StepDimTol_Datum.def_static("get_type_name_", (const char * (*)()) &StepDimTol_Datum::get_type_name, "None");
cls_StepDimTol_Datum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_Datum::get_type_descriptor, "None");
cls_StepDimTol_Datum.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_Datum::*)() const) &StepDimTol_Datum::DynamicType, "None");

// Enums

}