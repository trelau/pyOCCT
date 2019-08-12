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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESAppli_Node.hxx>
#include <IGESDefs_HArray1OfTabularData.hxx>
#include <IGESDefs_TabularData.hxx>
#include <IGESAppli_NodalConstraint.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_NodalConstraint(py::module &mod){

py::class_<IGESAppli_NodalConstraint, opencascade::handle<IGESAppli_NodalConstraint>, IGESData_IGESEntity> cls_IGESAppli_NodalConstraint(mod, "IGESAppli_NodalConstraint", "defines NodalConstraint, Type <418> Form <0> in package IGESAppli Relates loads and/or constraints to specific nodes in the Finite Element Model by creating a relation between Node entities and Tabular Data Property that contains the load or constraint data");

// Constructors
cls_IGESAppli_NodalConstraint.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_NodalConstraint.def("Init", (void (IGESAppli_NodalConstraint::*)(const Standard_Integer, const opencascade::handle<IGESAppli_Node> &, const opencascade::handle<IGESDefs_HArray1OfTabularData> &)) &IGESAppli_NodalConstraint::Init, "This method is used to set the fields of the class NodalConstraint - aType : Loads / Constraints - aNode : the Node - allTabData : Tabular Data Property carrying the load or constraint vector", py::arg("aType"), py::arg("aNode"), py::arg("allTabData"));
cls_IGESAppli_NodalConstraint.def("NbCases", (Standard_Integer (IGESAppli_NodalConstraint::*)() const) &IGESAppli_NodalConstraint::NbCases, "returns total number of cases");
cls_IGESAppli_NodalConstraint.def("Type", (Standard_Integer (IGESAppli_NodalConstraint::*)() const) &IGESAppli_NodalConstraint::Type, "returns whether Loads (1) or Constraints (2)");
cls_IGESAppli_NodalConstraint.def("NodeEntity", (opencascade::handle<IGESAppli_Node> (IGESAppli_NodalConstraint::*)() const) &IGESAppli_NodalConstraint::NodeEntity, "returns the Node");
cls_IGESAppli_NodalConstraint.def("TabularData", (opencascade::handle<IGESDefs_TabularData> (IGESAppli_NodalConstraint::*)(const Standard_Integer) const) &IGESAppli_NodalConstraint::TabularData, "returns Tabular Data Property carrying load or constraint vector raises exception if Index <= 0 or Index > NbCases", py::arg("Index"));
cls_IGESAppli_NodalConstraint.def_static("get_type_name_", (const char * (*)()) &IGESAppli_NodalConstraint::get_type_name, "None");
cls_IGESAppli_NodalConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_NodalConstraint::get_type_descriptor, "None");
cls_IGESAppli_NodalConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_NodalConstraint::*)() const) &IGESAppli_NodalConstraint::DynamicType, "None");

// Enums

}