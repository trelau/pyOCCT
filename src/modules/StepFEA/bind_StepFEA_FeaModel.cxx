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
#include <StepRepr_Representation.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_HArray1OfRepresentationItem.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>
#include <StepFEA_FeaModel.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaModel(py::module &mod){

py::class_<StepFEA_FeaModel, opencascade::handle<StepFEA_FeaModel>, StepRepr_Representation> cls_StepFEA_FeaModel(mod, "StepFEA_FeaModel", "Representation of STEP entity FeaModel");

// Constructors
cls_StepFEA_FeaModel.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaModel.def("Init", (void (StepFEA_FeaModel::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColStd_HArray1OfAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaModel::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentation_Name"), py::arg("aRepresentation_Items"), py::arg("aRepresentation_ContextOfItems"), py::arg("aCreatingSoftware"), py::arg("aIntendedAnalysisCode"), py::arg("aDescription"), py::arg("aAnalysisType"));
cls_StepFEA_FeaModel.def("CreatingSoftware", (opencascade::handle<TCollection_HAsciiString> (StepFEA_FeaModel::*)() const) &StepFEA_FeaModel::CreatingSoftware, "Returns field CreatingSoftware");
cls_StepFEA_FeaModel.def("SetCreatingSoftware", (void (StepFEA_FeaModel::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaModel::SetCreatingSoftware, "Set field CreatingSoftware", py::arg("CreatingSoftware"));
cls_StepFEA_FeaModel.def("IntendedAnalysisCode", (opencascade::handle<TColStd_HArray1OfAsciiString> (StepFEA_FeaModel::*)() const) &StepFEA_FeaModel::IntendedAnalysisCode, "Returns field IntendedAnalysisCode");
cls_StepFEA_FeaModel.def("SetIntendedAnalysisCode", (void (StepFEA_FeaModel::*)(const opencascade::handle<TColStd_HArray1OfAsciiString> &)) &StepFEA_FeaModel::SetIntendedAnalysisCode, "Set field IntendedAnalysisCode", py::arg("IntendedAnalysisCode"));
cls_StepFEA_FeaModel.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepFEA_FeaModel::*)() const) &StepFEA_FeaModel::Description, "Returns field Description");
cls_StepFEA_FeaModel.def("SetDescription", (void (StepFEA_FeaModel::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaModel::SetDescription, "Set field Description", py::arg("Description"));
cls_StepFEA_FeaModel.def("AnalysisType", (opencascade::handle<TCollection_HAsciiString> (StepFEA_FeaModel::*)() const) &StepFEA_FeaModel::AnalysisType, "Returns field AnalysisType");
cls_StepFEA_FeaModel.def("SetAnalysisType", (void (StepFEA_FeaModel::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaModel::SetAnalysisType, "Set field AnalysisType", py::arg("AnalysisType"));
cls_StepFEA_FeaModel.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaModel::get_type_name, "None");
cls_StepFEA_FeaModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaModel::get_type_descriptor, "None");
cls_StepFEA_FeaModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaModel::*)() const) &StepFEA_FeaModel::DynamicType, "None");

// Enums

}