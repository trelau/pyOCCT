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
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_HArray1OfFaceBound.hxx>
#include <StepShape_FaceBound.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_Face.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_Face(py::module &mod){

py::class_<StepShape_Face, opencascade::handle<StepShape_Face>, StepShape_TopologicalRepresentationItem> cls_StepShape_Face(mod, "StepShape_Face", "None");

// Constructors
cls_StepShape_Face.def(py::init<>());

// Fields

// Methods
cls_StepShape_Face.def("Init", (void (StepShape_Face::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfFaceBound> &)) &StepShape_Face::Init, "None", py::arg("aName"), py::arg("aBounds"));
cls_StepShape_Face.def("SetBounds", (void (StepShape_Face::*)(const opencascade::handle<StepShape_HArray1OfFaceBound> &)) &StepShape_Face::SetBounds, "None", py::arg("aBounds"));
cls_StepShape_Face.def("Bounds", (opencascade::handle<StepShape_HArray1OfFaceBound> (StepShape_Face::*)() const) &StepShape_Face::Bounds, "None");
cls_StepShape_Face.def("BoundsValue", (opencascade::handle<StepShape_FaceBound> (StepShape_Face::*)(const Standard_Integer) const) &StepShape_Face::BoundsValue, "None", py::arg("num"));
cls_StepShape_Face.def("NbBounds", (Standard_Integer (StepShape_Face::*)() const) &StepShape_Face::NbBounds, "None");
cls_StepShape_Face.def_static("get_type_name_", (const char * (*)()) &StepShape_Face::get_type_name, "None");
cls_StepShape_Face.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Face::get_type_descriptor, "None");
cls_StepShape_Face.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Face::*)() const) &StepShape_Face::DynamicType, "None");

// Enums

}