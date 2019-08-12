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
#include <NLPlate_HGPPConstraint.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NLPlate_HPG0Constraint.hxx>
#include <Standard_Type.hxx>

void bind_NLPlate_HPG0Constraint(py::module &mod){

py::class_<NLPlate_HPG0Constraint, opencascade::handle<NLPlate_HPG0Constraint>, NLPlate_HGPPConstraint> cls_NLPlate_HPG0Constraint(mod, "NLPlate_HPG0Constraint", "define a PinPoint G0 Constraint used to load a Non Linear Plate");

// Constructors
cls_NLPlate_HPG0Constraint.def(py::init<const gp_XY &, const gp_XYZ &>(), py::arg("UV"), py::arg("Value"));

// Fields

// Methods
cls_NLPlate_HPG0Constraint.def("SetUVFreeSliding", (void (NLPlate_HPG0Constraint::*)(const Standard_Boolean)) &NLPlate_HPG0Constraint::SetUVFreeSliding, "None", py::arg("UVFree"));
cls_NLPlate_HPG0Constraint.def("SetIncrementalLoadAllowed", (void (NLPlate_HPG0Constraint::*)(const Standard_Boolean)) &NLPlate_HPG0Constraint::SetIncrementalLoadAllowed, "None", py::arg("ILA"));
cls_NLPlate_HPG0Constraint.def("UVFreeSliding", (Standard_Boolean (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::UVFreeSliding, "None");
cls_NLPlate_HPG0Constraint.def("IncrementalLoadAllowed", (Standard_Boolean (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::IncrementalLoadAllowed, "None");
cls_NLPlate_HPG0Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::ActiveOrder, "None");
cls_NLPlate_HPG0Constraint.def("IsG0", (Standard_Boolean (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::IsG0, "None");
cls_NLPlate_HPG0Constraint.def("G0Target", (const gp_XYZ & (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::G0Target, "None");
cls_NLPlate_HPG0Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG0Constraint::get_type_name, "None");
cls_NLPlate_HPG0Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG0Constraint::get_type_descriptor, "None");
cls_NLPlate_HPG0Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::DynamicType, "None");

// Enums

}