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
#include <Standard_Handle.hxx>
#include <IGESDimen_GeneralNote.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <IGESDimen_WitnessLine.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESDimen_LinearDimension.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_LinearDimension(py::module &mod){

py::class_<IGESDimen_LinearDimension, opencascade::handle<IGESDimen_LinearDimension>, IGESData_IGESEntity> cls_IGESDimen_LinearDimension(mod, "IGESDimen_LinearDimension", "defines LinearDimension, Type <216> Form <0> in package IGESDimen Used for linear dimensioning");

// Constructors
cls_IGESDimen_LinearDimension.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_LinearDimension.def("Init", (void (IGESDimen_LinearDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_WitnessLine> &, const opencascade::handle<IGESDimen_WitnessLine> &)) &IGESDimen_LinearDimension::Init, "This method is used to set the fields of the class LinearDimension - aNote : General Note Entity - aLeader : First Leader Entity - anotherLeader : Second Leader Entity - aWitness : First Witness Line Entity or a Null Handle - anotherWitness : Second Witness Line Entity or a Null Handle", py::arg("aNote"), py::arg("aLeader"), py::arg("anotherLeader"), py::arg("aWitness"), py::arg("anotherWitness"));
cls_IGESDimen_LinearDimension.def("SetFormNumber", (void (IGESDimen_LinearDimension::*)(const Standard_Integer)) &IGESDimen_LinearDimension::SetFormNumber, "Changes FormNumber (indicates the Nature of the Dimension Unspecified, Diameter or Radius) Error if not in range [0-2]", py::arg("form"));
cls_IGESDimen_LinearDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::Note, "returns General Note Entity");
cls_IGESDimen_LinearDimension.def("FirstLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::FirstLeader, "returns first Leader Entity");
cls_IGESDimen_LinearDimension.def("SecondLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::SecondLeader, "returns second Leader Entity");
cls_IGESDimen_LinearDimension.def("HasFirstWitness", (Standard_Boolean (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::HasFirstWitness, "returns False if no first witness line");
cls_IGESDimen_LinearDimension.def("FirstWitness", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::FirstWitness, "returns first Witness Line Entity or a Null Handle");
cls_IGESDimen_LinearDimension.def("HasSecondWitness", (Standard_Boolean (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::HasSecondWitness, "returns False if no second witness line");
cls_IGESDimen_LinearDimension.def("SecondWitness", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::SecondWitness, "returns second Witness Line Entity or a Null Handle");
cls_IGESDimen_LinearDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_LinearDimension::get_type_name, "None");
cls_IGESDimen_LinearDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_LinearDimension::get_type_descriptor, "None");
cls_IGESDimen_LinearDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::DynamicType, "None");

// Enums

}