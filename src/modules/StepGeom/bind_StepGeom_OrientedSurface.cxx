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
#include <StepGeom_OrientedSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_OrientedSurface(py::module &mod){

py::class_<StepGeom_OrientedSurface, opencascade::handle<StepGeom_OrientedSurface>, StepGeom_Surface> cls_StepGeom_OrientedSurface(mod, "StepGeom_OrientedSurface", "Representation of STEP entity OrientedSurface");

// Constructors
cls_StepGeom_OrientedSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_OrientedSurface.def("Init", (void (StepGeom_OrientedSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean)) &StepGeom_OrientedSurface::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aOrientation"));
cls_StepGeom_OrientedSurface.def("Orientation", (Standard_Boolean (StepGeom_OrientedSurface::*)() const) &StepGeom_OrientedSurface::Orientation, "Returns field Orientation");
cls_StepGeom_OrientedSurface.def("SetOrientation", (void (StepGeom_OrientedSurface::*)(const Standard_Boolean)) &StepGeom_OrientedSurface::SetOrientation, "Set field Orientation", py::arg("Orientation"));
cls_StepGeom_OrientedSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_OrientedSurface::get_type_name, "None");
cls_StepGeom_OrientedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_OrientedSurface::get_type_descriptor, "None");
cls_StepGeom_OrientedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_OrientedSurface::*)() const) &StepGeom_OrientedSurface::DynamicType, "None");

// Enums

}