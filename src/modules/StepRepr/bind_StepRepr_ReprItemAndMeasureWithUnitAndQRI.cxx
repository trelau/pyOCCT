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
#include <StepRepr_ReprItemAndMeasureWithUnit.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepShape_QualifiedRepresentationItem.hxx>
#include <StepRepr_ReprItemAndMeasureWithUnitAndQRI.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ReprItemAndMeasureWithUnitAndQRI(py::module &mod){

py::class_<StepRepr_ReprItemAndMeasureWithUnitAndQRI, opencascade::handle<StepRepr_ReprItemAndMeasureWithUnitAndQRI>, StepRepr_ReprItemAndMeasureWithUnit> cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI(mod, "StepRepr_ReprItemAndMeasureWithUnitAndQRI", "Base class for complex types (MEASURE_REPRESENTATION_ITEM, MEASURE_WITH_UNIT, QUALIFIED_REPRESENTATION_ITEM REPRESENTATION_ITEM, LENGTH_MEASURE_WITH_UNIT/PLANE_ANGLE_MEASURE_WITH_UNIT).");

// Constructors
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def("Init", (void (StepRepr_ReprItemAndMeasureWithUnitAndQRI::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepShape_QualifiedRepresentationItem>)) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::Init, "None", py::arg("aMWU"), py::arg("aRI"), py::arg("aQRI"));
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def("SetQualifiedRepresentationItem", (void (StepRepr_ReprItemAndMeasureWithUnitAndQRI::*)(const opencascade::handle<StepShape_QualifiedRepresentationItem> &)) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::SetQualifiedRepresentationItem, "None", py::arg("aQRI"), py::call_guard<ImportStepShape>());
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def("GetQualifiedRepresentationItem", (opencascade::handle<StepShape_QualifiedRepresentationItem> (StepRepr_ReprItemAndMeasureWithUnitAndQRI::*)() const) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::GetQualifiedRepresentationItem, "None", py::call_guard<ImportStepShape>());
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def_static("get_type_name_", (const char * (*)()) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::get_type_name, "None");
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::get_type_descriptor, "None");
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ReprItemAndMeasureWithUnitAndQRI::*)() const) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::DynamicType, "None");

// Enums

}