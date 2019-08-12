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
#include <StepShape_HalfSpaceSolid.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_BoxDomain.hxx>
#include <StepShape_BoxedHalfSpace.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_BoxedHalfSpace(py::module &mod){

py::class_<StepShape_BoxedHalfSpace, opencascade::handle<StepShape_BoxedHalfSpace>, StepShape_HalfSpaceSolid> cls_StepShape_BoxedHalfSpace(mod, "StepShape_BoxedHalfSpace", "None");

// Constructors
cls_StepShape_BoxedHalfSpace.def(py::init<>());

// Fields

// Methods
cls_StepShape_BoxedHalfSpace.def("Init", (void (StepShape_BoxedHalfSpace::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Boolean, const opencascade::handle<StepShape_BoxDomain> &)) &StepShape_BoxedHalfSpace::Init, "None", py::arg("aName"), py::arg("aBaseSurface"), py::arg("aAgreementFlag"), py::arg("aEnclosure"));
cls_StepShape_BoxedHalfSpace.def("SetEnclosure", (void (StepShape_BoxedHalfSpace::*)(const opencascade::handle<StepShape_BoxDomain> &)) &StepShape_BoxedHalfSpace::SetEnclosure, "None", py::arg("aEnclosure"));
cls_StepShape_BoxedHalfSpace.def("Enclosure", (opencascade::handle<StepShape_BoxDomain> (StepShape_BoxedHalfSpace::*)() const) &StepShape_BoxedHalfSpace::Enclosure, "None");
cls_StepShape_BoxedHalfSpace.def_static("get_type_name_", (const char * (*)()) &StepShape_BoxedHalfSpace::get_type_name, "None");
cls_StepShape_BoxedHalfSpace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_BoxedHalfSpace::get_type_descriptor, "None");
cls_StepShape_BoxedHalfSpace.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_BoxedHalfSpace::*)() const) &StepShape_BoxedHalfSpace::DynamicType, "None");

// Enums

}