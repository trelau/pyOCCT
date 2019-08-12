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
#include <StepShape_Subface.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_Subface(py::module &mod){

py::class_<StepShape_Subface, opencascade::handle<StepShape_Subface>, StepShape_Face> cls_StepShape_Subface(mod, "StepShape_Subface", "Representation of STEP entity Subface");

// Constructors
cls_StepShape_Subface.def(py::init<>());

// Fields

// Methods
cls_StepShape_Subface.def("Init", (void (StepShape_Subface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfFaceBound> &, const opencascade::handle<StepShape_Face> &)) &StepShape_Subface::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFace_Bounds"), py::arg("aParentFace"));
cls_StepShape_Subface.def("ParentFace", (opencascade::handle<StepShape_Face> (StepShape_Subface::*)() const) &StepShape_Subface::ParentFace, "Returns field ParentFace");
cls_StepShape_Subface.def("SetParentFace", (void (StepShape_Subface::*)(const opencascade::handle<StepShape_Face> &)) &StepShape_Subface::SetParentFace, "Set field ParentFace", py::arg("ParentFace"));
cls_StepShape_Subface.def_static("get_type_name_", (const char * (*)()) &StepShape_Subface::get_type_name, "None");
cls_StepShape_Subface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Subface::get_type_descriptor, "None");
cls_StepShape_Subface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Subface::*)() const) &StepShape_Subface::DynamicType, "None");

// Enums

}