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
#include <StepGeom_BoundedSurface.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_RectangularTrimmedSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_RectangularTrimmedSurface(py::module &mod){

py::class_<StepGeom_RectangularTrimmedSurface, opencascade::handle<StepGeom_RectangularTrimmedSurface>, StepGeom_BoundedSurface> cls_StepGeom_RectangularTrimmedSurface(mod, "StepGeom_RectangularTrimmedSurface", "None");

// Constructors
cls_StepGeom_RectangularTrimmedSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_RectangularTrimmedSurface.def("Init", (void (StepGeom_RectangularTrimmedSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &StepGeom_RectangularTrimmedSurface::Init, "None", py::arg("aName"), py::arg("aBasisSurface"), py::arg("aU1"), py::arg("aU2"), py::arg("aV1"), py::arg("aV2"), py::arg("aUsense"), py::arg("aVsense"));
cls_StepGeom_RectangularTrimmedSurface.def("SetBasisSurface", (void (StepGeom_RectangularTrimmedSurface::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_RectangularTrimmedSurface::SetBasisSurface, "None", py::arg("aBasisSurface"));
cls_StepGeom_RectangularTrimmedSurface.def("BasisSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::BasisSurface, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetU1", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Real)) &StepGeom_RectangularTrimmedSurface::SetU1, "None", py::arg("aU1"));
cls_StepGeom_RectangularTrimmedSurface.def("U1", (Standard_Real (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::U1, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetU2", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Real)) &StepGeom_RectangularTrimmedSurface::SetU2, "None", py::arg("aU2"));
cls_StepGeom_RectangularTrimmedSurface.def("U2", (Standard_Real (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::U2, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetV1", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Real)) &StepGeom_RectangularTrimmedSurface::SetV1, "None", py::arg("aV1"));
cls_StepGeom_RectangularTrimmedSurface.def("V1", (Standard_Real (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::V1, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetV2", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Real)) &StepGeom_RectangularTrimmedSurface::SetV2, "None", py::arg("aV2"));
cls_StepGeom_RectangularTrimmedSurface.def("V2", (Standard_Real (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::V2, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetUsense", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Boolean)) &StepGeom_RectangularTrimmedSurface::SetUsense, "None", py::arg("aUsense"));
cls_StepGeom_RectangularTrimmedSurface.def("Usense", (Standard_Boolean (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::Usense, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetVsense", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Boolean)) &StepGeom_RectangularTrimmedSurface::SetVsense, "None", py::arg("aVsense"));
cls_StepGeom_RectangularTrimmedSurface.def("Vsense", (Standard_Boolean (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::Vsense, "None");
cls_StepGeom_RectangularTrimmedSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_RectangularTrimmedSurface::get_type_name, "None");
cls_StepGeom_RectangularTrimmedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_RectangularTrimmedSurface::get_type_descriptor, "None");
cls_StepGeom_RectangularTrimmedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::DynamicType, "None");

// Enums

}