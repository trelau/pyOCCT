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
#include <StepShape_CsgSelect.hxx>
#include <StepShape_CsgSolid.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_CsgSolid(py::module &mod){

py::class_<StepShape_CsgSolid, opencascade::handle<StepShape_CsgSolid>, StepShape_SolidModel> cls_StepShape_CsgSolid(mod, "StepShape_CsgSolid", "None");

// Constructors
cls_StepShape_CsgSolid.def(py::init<>());

// Fields

// Methods
cls_StepShape_CsgSolid.def("Init", (void (StepShape_CsgSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepShape_CsgSelect &)) &StepShape_CsgSolid::Init, "None", py::arg("aName"), py::arg("aTreeRootExpression"));
cls_StepShape_CsgSolid.def("SetTreeRootExpression", (void (StepShape_CsgSolid::*)(const StepShape_CsgSelect &)) &StepShape_CsgSolid::SetTreeRootExpression, "None", py::arg("aTreeRootExpression"));
cls_StepShape_CsgSolid.def("TreeRootExpression", (StepShape_CsgSelect (StepShape_CsgSolid::*)() const) &StepShape_CsgSolid::TreeRootExpression, "None");
cls_StepShape_CsgSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_CsgSolid::get_type_name, "None");
cls_StepShape_CsgSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_CsgSolid::get_type_descriptor, "None");
cls_StepShape_CsgSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_CsgSolid::*)() const) &StepShape_CsgSolid::DynamicType, "None");

// Enums

}