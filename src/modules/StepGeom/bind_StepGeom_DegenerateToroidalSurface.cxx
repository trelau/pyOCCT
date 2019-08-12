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
#include <StepGeom_ToroidalSurface.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_DegenerateToroidalSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_DegenerateToroidalSurface(py::module &mod){

py::class_<StepGeom_DegenerateToroidalSurface, opencascade::handle<StepGeom_DegenerateToroidalSurface>, StepGeom_ToroidalSurface> cls_StepGeom_DegenerateToroidalSurface(mod, "StepGeom_DegenerateToroidalSurface", "None");

// Constructors
cls_StepGeom_DegenerateToroidalSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_DegenerateToroidalSurface.def("Init", (void (StepGeom_DegenerateToroidalSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &StepGeom_DegenerateToroidalSurface::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aMajorRadius"), py::arg("aMinorRadius"), py::arg("aSelectOuter"));
cls_StepGeom_DegenerateToroidalSurface.def("SetSelectOuter", (void (StepGeom_DegenerateToroidalSurface::*)(const Standard_Boolean)) &StepGeom_DegenerateToroidalSurface::SetSelectOuter, "None", py::arg("aSelectOuter"));
cls_StepGeom_DegenerateToroidalSurface.def("SelectOuter", (Standard_Boolean (StepGeom_DegenerateToroidalSurface::*)() const) &StepGeom_DegenerateToroidalSurface::SelectOuter, "None");
cls_StepGeom_DegenerateToroidalSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_DegenerateToroidalSurface::get_type_name, "None");
cls_StepGeom_DegenerateToroidalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_DegenerateToroidalSurface::get_type_descriptor, "None");
cls_StepGeom_DegenerateToroidalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_DegenerateToroidalSurface::*)() const) &StepGeom_DegenerateToroidalSurface::DynamicType, "None");

// Enums

}