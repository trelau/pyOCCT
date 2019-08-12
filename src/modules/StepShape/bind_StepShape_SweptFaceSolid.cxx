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
#include <StepShape_SolidModel.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_FaceSurface.hxx>
#include <StepShape_SweptFaceSolid.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_SweptFaceSolid(py::module &mod){

py::class_<StepShape_SweptFaceSolid, opencascade::handle<StepShape_SweptFaceSolid>, StepShape_SolidModel> cls_StepShape_SweptFaceSolid(mod, "StepShape_SweptFaceSolid", "None");

// Constructors
cls_StepShape_SweptFaceSolid.def(py::init<>());

// Fields

// Methods
cls_StepShape_SweptFaceSolid.def("Init", (void (StepShape_SweptFaceSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_FaceSurface> &)) &StepShape_SweptFaceSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"));
cls_StepShape_SweptFaceSolid.def("SetSweptFace", (void (StepShape_SweptFaceSolid::*)(const opencascade::handle<StepShape_FaceSurface> &)) &StepShape_SweptFaceSolid::SetSweptFace, "None", py::arg("aSweptArea"));
cls_StepShape_SweptFaceSolid.def("SweptFace", (opencascade::handle<StepShape_FaceSurface> (StepShape_SweptFaceSolid::*)() const) &StepShape_SweptFaceSolid::SweptFace, "None");
cls_StepShape_SweptFaceSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_SweptFaceSolid::get_type_name, "None");
cls_StepShape_SweptFaceSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_SweptFaceSolid::get_type_descriptor, "None");
cls_StepShape_SweptFaceSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_SweptFaceSolid::*)() const) &StepShape_SweptFaceSolid::DynamicType, "None");

// Enums

}