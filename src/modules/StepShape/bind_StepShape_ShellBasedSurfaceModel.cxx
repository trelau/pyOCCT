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
#include <StepShape_HArray1OfShell.hxx>
#include <StepShape_Shell.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_ShellBasedSurfaceModel.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_ShellBasedSurfaceModel(py::module &mod){

py::class_<StepShape_ShellBasedSurfaceModel, opencascade::handle<StepShape_ShellBasedSurfaceModel>, StepGeom_GeometricRepresentationItem> cls_StepShape_ShellBasedSurfaceModel(mod, "StepShape_ShellBasedSurfaceModel", "None");

// Constructors
cls_StepShape_ShellBasedSurfaceModel.def(py::init<>());

// Fields

// Methods
cls_StepShape_ShellBasedSurfaceModel.def("Init", (void (StepShape_ShellBasedSurfaceModel::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfShell> &)) &StepShape_ShellBasedSurfaceModel::Init, "None", py::arg("aName"), py::arg("aSbsmBoundary"));
cls_StepShape_ShellBasedSurfaceModel.def("SetSbsmBoundary", (void (StepShape_ShellBasedSurfaceModel::*)(const opencascade::handle<StepShape_HArray1OfShell> &)) &StepShape_ShellBasedSurfaceModel::SetSbsmBoundary, "None", py::arg("aSbsmBoundary"));
cls_StepShape_ShellBasedSurfaceModel.def("SbsmBoundary", (opencascade::handle<StepShape_HArray1OfShell> (StepShape_ShellBasedSurfaceModel::*)() const) &StepShape_ShellBasedSurfaceModel::SbsmBoundary, "None");
cls_StepShape_ShellBasedSurfaceModel.def("SbsmBoundaryValue", (StepShape_Shell (StepShape_ShellBasedSurfaceModel::*)(const Standard_Integer) const) &StepShape_ShellBasedSurfaceModel::SbsmBoundaryValue, "None", py::arg("num"));
cls_StepShape_ShellBasedSurfaceModel.def("NbSbsmBoundary", (Standard_Integer (StepShape_ShellBasedSurfaceModel::*)() const) &StepShape_ShellBasedSurfaceModel::NbSbsmBoundary, "None");
cls_StepShape_ShellBasedSurfaceModel.def_static("get_type_name_", (const char * (*)()) &StepShape_ShellBasedSurfaceModel::get_type_name, "None");
cls_StepShape_ShellBasedSurfaceModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ShellBasedSurfaceModel::get_type_descriptor, "None");
cls_StepShape_ShellBasedSurfaceModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ShellBasedSurfaceModel::*)() const) &StepShape_ShellBasedSurfaceModel::DynamicType, "None");

// Enums

}