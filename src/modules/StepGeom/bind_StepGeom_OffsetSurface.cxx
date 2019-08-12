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
#include <Standard_TypeDef.hxx>
#include <StepData_Logical.hxx>
#include <StepGeom_OffsetSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_OffsetSurface(py::module &mod){

py::class_<StepGeom_OffsetSurface, opencascade::handle<StepGeom_OffsetSurface>, StepGeom_Surface> cls_StepGeom_OffsetSurface(mod, "StepGeom_OffsetSurface", "None");

// Constructors
cls_StepGeom_OffsetSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_OffsetSurface.def("Init", (void (StepGeom_OffsetSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Real, const StepData_Logical)) &StepGeom_OffsetSurface::Init, "None", py::arg("aName"), py::arg("aBasisSurface"), py::arg("aDistance"), py::arg("aSelfIntersect"));
cls_StepGeom_OffsetSurface.def("SetBasisSurface", (void (StepGeom_OffsetSurface::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_OffsetSurface::SetBasisSurface, "None", py::arg("aBasisSurface"));
cls_StepGeom_OffsetSurface.def("BasisSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_OffsetSurface::*)() const) &StepGeom_OffsetSurface::BasisSurface, "None");
cls_StepGeom_OffsetSurface.def("SetDistance", (void (StepGeom_OffsetSurface::*)(const Standard_Real)) &StepGeom_OffsetSurface::SetDistance, "None", py::arg("aDistance"));
cls_StepGeom_OffsetSurface.def("Distance", (Standard_Real (StepGeom_OffsetSurface::*)() const) &StepGeom_OffsetSurface::Distance, "None");
cls_StepGeom_OffsetSurface.def("SetSelfIntersect", (void (StepGeom_OffsetSurface::*)(const StepData_Logical)) &StepGeom_OffsetSurface::SetSelfIntersect, "None", py::arg("aSelfIntersect"));
cls_StepGeom_OffsetSurface.def("SelfIntersect", (StepData_Logical (StepGeom_OffsetSurface::*)() const) &StepGeom_OffsetSurface::SelfIntersect, "None");
cls_StepGeom_OffsetSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_OffsetSurface::get_type_name, "None");
cls_StepGeom_OffsetSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_OffsetSurface::get_type_descriptor, "None");
cls_StepGeom_OffsetSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_OffsetSurface::*)() const) &StepGeom_OffsetSurface::DynamicType, "None");

// Enums

}