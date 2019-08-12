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
#include <StepGeom_Surface.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_CartesianTransformationOperator3d.hxx>
#include <StepGeom_SurfaceReplica.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_SurfaceReplica(py::module &mod){

py::class_<StepGeom_SurfaceReplica, opencascade::handle<StepGeom_SurfaceReplica>, StepGeom_Surface> cls_StepGeom_SurfaceReplica(mod, "StepGeom_SurfaceReplica", "None");

// Constructors
cls_StepGeom_SurfaceReplica.def(py::init<>());

// Fields

// Methods
cls_StepGeom_SurfaceReplica.def("Init", (void (StepGeom_SurfaceReplica::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepGeom_CartesianTransformationOperator3d> &)) &StepGeom_SurfaceReplica::Init, "None", py::arg("aName"), py::arg("aParentSurface"), py::arg("aTransformation"));
cls_StepGeom_SurfaceReplica.def("SetParentSurface", (void (StepGeom_SurfaceReplica::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_SurfaceReplica::SetParentSurface, "None", py::arg("aParentSurface"));
cls_StepGeom_SurfaceReplica.def("ParentSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_SurfaceReplica::*)() const) &StepGeom_SurfaceReplica::ParentSurface, "None");
cls_StepGeom_SurfaceReplica.def("SetTransformation", (void (StepGeom_SurfaceReplica::*)(const opencascade::handle<StepGeom_CartesianTransformationOperator3d> &)) &StepGeom_SurfaceReplica::SetTransformation, "None", py::arg("aTransformation"));
cls_StepGeom_SurfaceReplica.def("Transformation", (opencascade::handle<StepGeom_CartesianTransformationOperator3d> (StepGeom_SurfaceReplica::*)() const) &StepGeom_SurfaceReplica::Transformation, "None");
cls_StepGeom_SurfaceReplica.def_static("get_type_name_", (const char * (*)()) &StepGeom_SurfaceReplica::get_type_name, "None");
cls_StepGeom_SurfaceReplica.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SurfaceReplica::get_type_descriptor, "None");
cls_StepGeom_SurfaceReplica.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SurfaceReplica::*)() const) &StepGeom_SurfaceReplica::DynamicType, "None");

// Enums

}