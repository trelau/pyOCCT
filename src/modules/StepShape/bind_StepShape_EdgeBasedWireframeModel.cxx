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
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_HArray1OfConnectedEdgeSet.hxx>
#include <StepShape_EdgeBasedWireframeModel.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_EdgeBasedWireframeModel(py::module &mod){

py::class_<StepShape_EdgeBasedWireframeModel, opencascade::handle<StepShape_EdgeBasedWireframeModel>, StepGeom_GeometricRepresentationItem> cls_StepShape_EdgeBasedWireframeModel(mod, "StepShape_EdgeBasedWireframeModel", "Representation of STEP entity EdgeBasedWireframeModel");

// Constructors
cls_StepShape_EdgeBasedWireframeModel.def(py::init<>());

// Fields

// Methods
cls_StepShape_EdgeBasedWireframeModel.def("Init", (void (StepShape_EdgeBasedWireframeModel::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfConnectedEdgeSet> &)) &StepShape_EdgeBasedWireframeModel::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aEbwmBoundary"));
cls_StepShape_EdgeBasedWireframeModel.def("EbwmBoundary", (opencascade::handle<StepShape_HArray1OfConnectedEdgeSet> (StepShape_EdgeBasedWireframeModel::*)() const) &StepShape_EdgeBasedWireframeModel::EbwmBoundary, "Returns field EbwmBoundary");
cls_StepShape_EdgeBasedWireframeModel.def("SetEbwmBoundary", (void (StepShape_EdgeBasedWireframeModel::*)(const opencascade::handle<StepShape_HArray1OfConnectedEdgeSet> &)) &StepShape_EdgeBasedWireframeModel::SetEbwmBoundary, "Set field EbwmBoundary", py::arg("EbwmBoundary"));
cls_StepShape_EdgeBasedWireframeModel.def_static("get_type_name_", (const char * (*)()) &StepShape_EdgeBasedWireframeModel::get_type_name, "None");
cls_StepShape_EdgeBasedWireframeModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_EdgeBasedWireframeModel::get_type_descriptor, "None");
cls_StepShape_EdgeBasedWireframeModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_EdgeBasedWireframeModel::*)() const) &StepShape_EdgeBasedWireframeModel::DynamicType, "None");

// Enums

}