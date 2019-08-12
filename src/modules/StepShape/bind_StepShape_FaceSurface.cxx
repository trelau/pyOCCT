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
#include <StepShape_Face.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_HArray1OfFaceBound.hxx>
#include <StepGeom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_FaceSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_FaceSurface(py::module &mod){

py::class_<StepShape_FaceSurface, opencascade::handle<StepShape_FaceSurface>, StepShape_Face> cls_StepShape_FaceSurface(mod, "StepShape_FaceSurface", "None");

// Constructors
cls_StepShape_FaceSurface.def(py::init<>());

// Fields

// Methods
cls_StepShape_FaceSurface.def("Init", (void (StepShape_FaceSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfFaceBound> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Boolean)) &StepShape_FaceSurface::Init, "None", py::arg("aName"), py::arg("aBounds"), py::arg("aFaceGeometry"), py::arg("aSameSense"));
cls_StepShape_FaceSurface.def("SetFaceGeometry", (void (StepShape_FaceSurface::*)(const opencascade::handle<StepGeom_Surface> &)) &StepShape_FaceSurface::SetFaceGeometry, "None", py::arg("aFaceGeometry"));
cls_StepShape_FaceSurface.def("FaceGeometry", (opencascade::handle<StepGeom_Surface> (StepShape_FaceSurface::*)() const) &StepShape_FaceSurface::FaceGeometry, "None");
cls_StepShape_FaceSurface.def("SetSameSense", (void (StepShape_FaceSurface::*)(const Standard_Boolean)) &StepShape_FaceSurface::SetSameSense, "None", py::arg("aSameSense"));
cls_StepShape_FaceSurface.def("SameSense", (Standard_Boolean (StepShape_FaceSurface::*)() const) &StepShape_FaceSurface::SameSense, "None");
cls_StepShape_FaceSurface.def_static("get_type_name_", (const char * (*)()) &StepShape_FaceSurface::get_type_name, "None");
cls_StepShape_FaceSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_FaceSurface::get_type_descriptor, "None");
cls_StepShape_FaceSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_FaceSurface::*)() const) &StepShape_FaceSurface::DynamicType, "None");

// Enums

}