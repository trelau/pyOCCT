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
#include <IGESDimen_CurveDimension.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_CurveDimension(py::module &mod){

py::class_<IGESDimen_CurveDimension, opencascade::handle<IGESDimen_CurveDimension>, IGESData_IGESEntity> cls_IGESDimen_CurveDimension(mod, "IGESDimen_CurveDimension", "defines CurveDimension, Type <204> Form <0> in package IGESDimen Used to dimension curves Consists of one tail segment of nonzero length beginning with an arrowhead and which serves to define the orientation");

// Constructors
cls_IGESDimen_CurveDimension.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_CurveDimension.def("Init", (void (IGESDimen_CurveDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_WitnessLine> &, const opencascade::handle<IGESDimen_WitnessLine> &)) &IGESDimen_CurveDimension::Init, "This method is used to set the fields of the class CurveDimension - aNote : General Note Entity - aCurve : First Curve Entity - anotherCurve : Second Curve Entity or a Null Handle - aLeader : First Leader Entity - anotherLeader : Second Leader Entity - aLine : First Witness Line Entity or a Null Handle - anotherLine : Second Witness Line Entity or a Null Handle", py::arg("aNote"), py::arg("aCurve"), py::arg("anotherCurve"), py::arg("aLeader"), py::arg("anotherLeader"), py::arg("aLine"), py::arg("anotherLine"));
cls_IGESDimen_CurveDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::Note, "returns the General Note Entity");
cls_IGESDimen_CurveDimension.def("FirstCurve", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::FirstCurve, "returns the First curve Entity");
cls_IGESDimen_CurveDimension.def("HasSecondCurve", (Standard_Boolean (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::HasSecondCurve, "returns False if theSecondCurve is a Null Handle.");
cls_IGESDimen_CurveDimension.def("SecondCurve", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::SecondCurve, "returns the Second curve Entity or a Null Handle.");
cls_IGESDimen_CurveDimension.def("FirstLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::FirstLeader, "returns the First Leader Entity");
cls_IGESDimen_CurveDimension.def("SecondLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::SecondLeader, "returns the Second Leader Entity");
cls_IGESDimen_CurveDimension.def("HasFirstWitnessLine", (Standard_Boolean (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::HasFirstWitnessLine, "returns False if theFirstWitnessLine is a Null Handle.");
cls_IGESDimen_CurveDimension.def("FirstWitnessLine", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::FirstWitnessLine, "returns the First Witness Line Entity or a Null Handle.");
cls_IGESDimen_CurveDimension.def("HasSecondWitnessLine", (Standard_Boolean (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::HasSecondWitnessLine, "returns False if theSecondWitnessLine is a Null Handle.");
cls_IGESDimen_CurveDimension.def("SecondWitnessLine", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::SecondWitnessLine, "returns the Second Witness Line Entity or a Null Handle.");
cls_IGESDimen_CurveDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_CurveDimension::get_type_name, "None");
cls_IGESDimen_CurveDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_CurveDimension::get_type_descriptor, "None");
cls_IGESDimen_CurveDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::DynamicType, "None");

// Enums

}