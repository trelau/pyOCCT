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
#include <StepGeom_Curve.hxx>
#include <StepGeom_SweptSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_SweptSurface(py::module &mod){

py::class_<StepGeom_SweptSurface, opencascade::handle<StepGeom_SweptSurface>, StepGeom_Surface> cls_StepGeom_SweptSurface(mod, "StepGeom_SweptSurface", "None");

// Constructors
cls_StepGeom_SweptSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_SweptSurface.def("Init", (void (StepGeom_SweptSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &)) &StepGeom_SweptSurface::Init, "None", py::arg("aName"), py::arg("aSweptCurve"));
cls_StepGeom_SweptSurface.def("SetSweptCurve", (void (StepGeom_SweptSurface::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_SweptSurface::SetSweptCurve, "None", py::arg("aSweptCurve"));
cls_StepGeom_SweptSurface.def("SweptCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_SweptSurface::*)() const) &StepGeom_SweptSurface::SweptCurve, "None");
cls_StepGeom_SweptSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_SweptSurface::get_type_name, "None");
cls_StepGeom_SweptSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SweptSurface::get_type_descriptor, "None");
cls_StepGeom_SweptSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SweptSurface::*)() const) &StepGeom_SweptSurface::DynamicType, "None");

// Enums

}