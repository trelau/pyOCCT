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
#include <StepShape_HArray1OfConnectedFaceSet.hxx>
#include <StepShape_FaceBasedSurfaceModel.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_FaceBasedSurfaceModel(py::module &mod){

py::class_<StepShape_FaceBasedSurfaceModel, opencascade::handle<StepShape_FaceBasedSurfaceModel>, StepGeom_GeometricRepresentationItem> cls_StepShape_FaceBasedSurfaceModel(mod, "StepShape_FaceBasedSurfaceModel", "Representation of STEP entity FaceBasedSurfaceModel");

// Constructors
cls_StepShape_FaceBasedSurfaceModel.def(py::init<>());

// Fields

// Methods
cls_StepShape_FaceBasedSurfaceModel.def("Init", (void (StepShape_FaceBasedSurfaceModel::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfConnectedFaceSet> &)) &StepShape_FaceBasedSurfaceModel::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFbsmFaces"));
cls_StepShape_FaceBasedSurfaceModel.def("FbsmFaces", (opencascade::handle<StepShape_HArray1OfConnectedFaceSet> (StepShape_FaceBasedSurfaceModel::*)() const) &StepShape_FaceBasedSurfaceModel::FbsmFaces, "Returns field FbsmFaces");
cls_StepShape_FaceBasedSurfaceModel.def("SetFbsmFaces", (void (StepShape_FaceBasedSurfaceModel::*)(const opencascade::handle<StepShape_HArray1OfConnectedFaceSet> &)) &StepShape_FaceBasedSurfaceModel::SetFbsmFaces, "Set field FbsmFaces", py::arg("FbsmFaces"));
cls_StepShape_FaceBasedSurfaceModel.def_static("get_type_name_", (const char * (*)()) &StepShape_FaceBasedSurfaceModel::get_type_name, "None");
cls_StepShape_FaceBasedSurfaceModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_FaceBasedSurfaceModel::get_type_descriptor, "None");
cls_StepShape_FaceBasedSurfaceModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_FaceBasedSurfaceModel::*)() const) &StepShape_FaceBasedSurfaceModel::DynamicType, "None");

// Enums

}