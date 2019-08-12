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
#include <NLPlate_HPG0G1Constraint.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <Plate_D1.hxx>
#include <Plate_D2.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NLPlate_HPG0G2Constraint.hxx>
#include <Standard_Type.hxx>

void bind_NLPlate_HPG0G2Constraint(py::module &mod){

py::class_<NLPlate_HPG0G2Constraint, opencascade::handle<NLPlate_HPG0G2Constraint>, NLPlate_HPG0G1Constraint> cls_NLPlate_HPG0G2Constraint(mod, "NLPlate_HPG0G2Constraint", "define a PinPoint G0+G2 Constraint used to load a Non Linear Plate");

// Constructors
cls_NLPlate_HPG0G2Constraint.def(py::init<const gp_XY &, const gp_XYZ &, const Plate_D1 &, const Plate_D2 &>(), py::arg("UV"), py::arg("Value"), py::arg("D1T"), py::arg("D2T"));

// Fields

// Methods
cls_NLPlate_HPG0G2Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG0G2Constraint::*)() const) &NLPlate_HPG0G2Constraint::ActiveOrder, "None");
cls_NLPlate_HPG0G2Constraint.def("G2Target", (const Plate_D2 & (NLPlate_HPG0G2Constraint::*)() const) &NLPlate_HPG0G2Constraint::G2Target, "None");
cls_NLPlate_HPG0G2Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG0G2Constraint::get_type_name, "None");
cls_NLPlate_HPG0G2Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG0G2Constraint::get_type_descriptor, "None");
cls_NLPlate_HPG0G2Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG0G2Constraint::*)() const) &NLPlate_HPG0G2Constraint::DynamicType, "None");

// Enums

}