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
#include <IGESAppli_PWBDrilledHole.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_PWBDrilledHole(py::module &mod){

py::class_<IGESAppli_PWBDrilledHole, opencascade::handle<IGESAppli_PWBDrilledHole>, IGESData_IGESEntity> cls_IGESAppli_PWBDrilledHole(mod, "IGESAppli_PWBDrilledHole", "defines PWBDrilledHole, Type <406> Form <26> in package IGESAppli Used to identify an entity that locates a drilled hole and to specify the characteristics of the drilled hole");

// Constructors
cls_IGESAppli_PWBDrilledHole.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_PWBDrilledHole.def("Init", (void (IGESAppli_PWBDrilledHole::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer)) &IGESAppli_PWBDrilledHole::Init, "This method is used to set the fields of the class PWBDrilledHole - nbPropVal : number of property values, always = 3 - aDrillDia : Drill diameter size - aFinishDia : Finish diameter size - aCode : Function code for drilled hole", py::arg("nbPropVal"), py::arg("aDrillDia"), py::arg("aFinishDia"), py::arg("aCode"));
cls_IGESAppli_PWBDrilledHole.def("NbPropertyValues", (Standard_Integer (IGESAppli_PWBDrilledHole::*)() const) &IGESAppli_PWBDrilledHole::NbPropertyValues, "returns number of property values, always = 3");
cls_IGESAppli_PWBDrilledHole.def("DrillDiameterSize", (Standard_Real (IGESAppli_PWBDrilledHole::*)() const) &IGESAppli_PWBDrilledHole::DrillDiameterSize, "returns Drill diameter size");
cls_IGESAppli_PWBDrilledHole.def("FinishDiameterSize", (Standard_Real (IGESAppli_PWBDrilledHole::*)() const) &IGESAppli_PWBDrilledHole::FinishDiameterSize, "returns Finish diameter size");
cls_IGESAppli_PWBDrilledHole.def("FunctionCode", (Standard_Integer (IGESAppli_PWBDrilledHole::*)() const) &IGESAppli_PWBDrilledHole::FunctionCode, "returns Function code for drilled hole is 0, 1, 2, 3, 4, 5 or 5001-9999");
cls_IGESAppli_PWBDrilledHole.def_static("get_type_name_", (const char * (*)()) &IGESAppli_PWBDrilledHole::get_type_name, "None");
cls_IGESAppli_PWBDrilledHole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_PWBDrilledHole::get_type_descriptor, "None");
cls_IGESAppli_PWBDrilledHole.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_PWBDrilledHole::*)() const) &IGESAppli_PWBDrilledHole::DynamicType, "None");

// Enums

}