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
#include <StepRepr_CompositeShapeAspect.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepData_Logical.hxx>
#include <StepDimTol_Datum.hxx>
#include <StepDimTol_CommonDatum.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_CommonDatum(py::module &mod){

py::class_<StepDimTol_CommonDatum, opencascade::handle<StepDimTol_CommonDatum>, StepRepr_CompositeShapeAspect> cls_StepDimTol_CommonDatum(mod, "StepDimTol_CommonDatum", "Representation of STEP entity CommonDatum");

// Constructors
cls_StepDimTol_CommonDatum.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_CommonDatum.def("Init", (void (StepDimTol_CommonDatum::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_CommonDatum::Init, "Initialize all fields (own and inherited)", py::arg("theShapeAspect_Name"), py::arg("theShapeAspect_Description"), py::arg("theShapeAspect_OfShape"), py::arg("theShapeAspect_ProductDefinitional"), py::arg("theDatum_Name"), py::arg("theDatum_Description"), py::arg("theDatum_OfShape"), py::arg("theDatum_ProductDefinitional"), py::arg("theDatum_Identification"));
cls_StepDimTol_CommonDatum.def("Datum", (opencascade::handle<StepDimTol_Datum> (StepDimTol_CommonDatum::*)() const) &StepDimTol_CommonDatum::Datum, "Returns data for supertype Datum");
cls_StepDimTol_CommonDatum.def("SetDatum", (void (StepDimTol_CommonDatum::*)(const opencascade::handle<StepDimTol_Datum> &)) &StepDimTol_CommonDatum::SetDatum, "Set data for supertype Datum", py::arg("theDatum"));
cls_StepDimTol_CommonDatum.def_static("get_type_name_", (const char * (*)()) &StepDimTol_CommonDatum::get_type_name, "None");
cls_StepDimTol_CommonDatum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_CommonDatum::get_type_descriptor, "None");
cls_StepDimTol_CommonDatum.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_CommonDatum::*)() const) &StepDimTol_CommonDatum::DynamicType, "None");

// Enums

}