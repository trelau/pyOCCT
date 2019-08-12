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
#include <StepRepr_Representation.hxx>
#include <Standard_Handle.hxx>
#include <StepRepr_DefinitionalRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_DefinitionalRepresentation(py::module &mod){

py::class_<StepRepr_DefinitionalRepresentation, opencascade::handle<StepRepr_DefinitionalRepresentation>, StepRepr_Representation> cls_StepRepr_DefinitionalRepresentation(mod, "StepRepr_DefinitionalRepresentation", "None");

// Constructors
cls_StepRepr_DefinitionalRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepRepr_DefinitionalRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_DefinitionalRepresentation::get_type_name, "None");
cls_StepRepr_DefinitionalRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_DefinitionalRepresentation::get_type_descriptor, "None");
cls_StepRepr_DefinitionalRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_DefinitionalRepresentation::*)() const) &StepRepr_DefinitionalRepresentation::DynamicType, "None");

// Enums

}