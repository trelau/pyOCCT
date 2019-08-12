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
#include <Plate_D1.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NLPlate_HPG1Constraint.hxx>
#include <Standard_Type.hxx>

void bind_NLPlate_HPG1Constraint(py::module &mod){

py::class_<NLPlate_HPG1Constraint, opencascade::handle<NLPlate_HPG1Constraint>, NLPlate_HGPPConstraint> cls_NLPlate_HPG1Constraint(mod, "NLPlate_HPG1Constraint", "define a PinPoint (no G0) G1 Constraint used to load a Non Linear Plate");

// Constructors
cls_NLPlate_HPG1Constraint.def(py::init<const gp_XY &, const Plate_D1 &>(), py::arg("UV"), py::arg("D1T"));

// Fields

// Methods
cls_NLPlate_HPG1Constraint.def("SetIncrementalLoadAllowed", (void (NLPlate_HPG1Constraint::*)(const Standard_Boolean)) &NLPlate_HPG1Constraint::SetIncrementalLoadAllowed, "None", py::arg("ILA"));
cls_NLPlate_HPG1Constraint.def("SetOrientation", [](NLPlate_HPG1Constraint &self) -> void { return self.SetOrientation(); });
cls_NLPlate_HPG1Constraint.def("SetOrientation", (void (NLPlate_HPG1Constraint::*)(const Standard_Integer)) &NLPlate_HPG1Constraint::SetOrientation, "None", py::arg("Orient"));
cls_NLPlate_HPG1Constraint.def("IncrementalLoadAllowed", (Standard_Boolean (NLPlate_HPG1Constraint::*)() const) &NLPlate_HPG1Constraint::IncrementalLoadAllowed, "None");
cls_NLPlate_HPG1Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG1Constraint::*)() const) &NLPlate_HPG1Constraint::ActiveOrder, "None");
cls_NLPlate_HPG1Constraint.def("IsG0", (Standard_Boolean (NLPlate_HPG1Constraint::*)() const) &NLPlate_HPG1Constraint::IsG0, "None");
cls_NLPlate_HPG1Constraint.def("Orientation", (Standard_Integer (NLPlate_HPG1Constraint::*)()) &NLPlate_HPG1Constraint::Orientation, "None");
cls_NLPlate_HPG1Constraint.def("G1Target", (const Plate_D1 & (NLPlate_HPG1Constraint::*)() const) &NLPlate_HPG1Constraint::G1Target, "None");
cls_NLPlate_HPG1Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG1Constraint::get_type_name, "None");
cls_NLPlate_HPG1Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG1Constraint::get_type_descriptor, "None");
cls_NLPlate_HPG1Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG1Constraint::*)() const) &NLPlate_HPG1Constraint::DynamicType, "None");

// Enums

}