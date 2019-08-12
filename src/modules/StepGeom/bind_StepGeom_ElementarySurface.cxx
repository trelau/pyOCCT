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
#include <StepGeom_Axis2Placement3d.hxx>
#include <StepGeom_ElementarySurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_ElementarySurface(py::module &mod){

py::class_<StepGeom_ElementarySurface, opencascade::handle<StepGeom_ElementarySurface>, StepGeom_Surface> cls_StepGeom_ElementarySurface(mod, "StepGeom_ElementarySurface", "None");

// Constructors
cls_StepGeom_ElementarySurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_ElementarySurface.def("Init", (void (StepGeom_ElementarySurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepGeom_ElementarySurface::Init, "None", py::arg("aName"), py::arg("aPosition"));
cls_StepGeom_ElementarySurface.def("SetPosition", (void (StepGeom_ElementarySurface::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepGeom_ElementarySurface::SetPosition, "None", py::arg("aPosition"));
cls_StepGeom_ElementarySurface.def("Position", (opencascade::handle<StepGeom_Axis2Placement3d> (StepGeom_ElementarySurface::*)() const) &StepGeom_ElementarySurface::Position, "None");
cls_StepGeom_ElementarySurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_ElementarySurface::get_type_name, "None");
cls_StepGeom_ElementarySurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_ElementarySurface::get_type_descriptor, "None");
cls_StepGeom_ElementarySurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_ElementarySurface::*)() const) &StepGeom_ElementarySurface::DynamicType, "None");

// Enums

}