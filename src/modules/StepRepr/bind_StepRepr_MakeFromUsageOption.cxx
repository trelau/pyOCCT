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
#include <StepRepr_ProductDefinitionUsage.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepBasic_ProductDefinitionOrReference.hxx>
#include <StepRepr_MakeFromUsageOption.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_MakeFromUsageOption(py::module &mod){

py::class_<StepRepr_MakeFromUsageOption, opencascade::handle<StepRepr_MakeFromUsageOption>, StepRepr_ProductDefinitionUsage> cls_StepRepr_MakeFromUsageOption(mod, "StepRepr_MakeFromUsageOption", "Representation of STEP entity MakeFromUsageOption");

// Constructors
cls_StepRepr_MakeFromUsageOption.def(py::init<>());

// Fields

// Methods
cls_StepRepr_MakeFromUsageOption.def("Init", (void (StepRepr_MakeFromUsageOption::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinition> &, const opencascade::handle<StepBasic_ProductDefinition> &, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_MakeFromUsageOption::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("aRanking"), py::arg("aRankingRationale"), py::arg("aQuantity"));
cls_StepRepr_MakeFromUsageOption.def("Init", (void (StepRepr_MakeFromUsageOption::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_ProductDefinitionOrReference &, const StepBasic_ProductDefinitionOrReference &, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_MakeFromUsageOption::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("aRanking"), py::arg("aRankingRationale"), py::arg("aQuantity"));
cls_StepRepr_MakeFromUsageOption.def("Ranking", (Standard_Integer (StepRepr_MakeFromUsageOption::*)() const) &StepRepr_MakeFromUsageOption::Ranking, "Returns field Ranking");
cls_StepRepr_MakeFromUsageOption.def("SetRanking", (void (StepRepr_MakeFromUsageOption::*)(const Standard_Integer)) &StepRepr_MakeFromUsageOption::SetRanking, "Set field Ranking", py::arg("Ranking"));
cls_StepRepr_MakeFromUsageOption.def("RankingRationale", (opencascade::handle<TCollection_HAsciiString> (StepRepr_MakeFromUsageOption::*)() const) &StepRepr_MakeFromUsageOption::RankingRationale, "Returns field RankingRationale");
cls_StepRepr_MakeFromUsageOption.def("SetRankingRationale", (void (StepRepr_MakeFromUsageOption::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_MakeFromUsageOption::SetRankingRationale, "Set field RankingRationale", py::arg("RankingRationale"));
cls_StepRepr_MakeFromUsageOption.def("Quantity", (opencascade::handle<StepBasic_MeasureWithUnit> (StepRepr_MakeFromUsageOption::*)() const) &StepRepr_MakeFromUsageOption::Quantity, "Returns field Quantity");
cls_StepRepr_MakeFromUsageOption.def("SetQuantity", (void (StepRepr_MakeFromUsageOption::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_MakeFromUsageOption::SetQuantity, "Set field Quantity", py::arg("Quantity"));
cls_StepRepr_MakeFromUsageOption.def_static("get_type_name_", (const char * (*)()) &StepRepr_MakeFromUsageOption::get_type_name, "None");
cls_StepRepr_MakeFromUsageOption.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_MakeFromUsageOption::get_type_descriptor, "None");
cls_StepRepr_MakeFromUsageOption.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_MakeFromUsageOption::*)() const) &StepRepr_MakeFromUsageOption::DynamicType, "None");

// Enums

}