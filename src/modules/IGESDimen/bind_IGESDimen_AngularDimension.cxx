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
#include <IGESDimen_WitnessLine.hxx>
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <gp_Pnt2d.hxx>
#include <IGESDimen_AngularDimension.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_AngularDimension(py::module &mod){

py::class_<IGESDimen_AngularDimension, opencascade::handle<IGESDimen_AngularDimension>, IGESData_IGESEntity> cls_IGESDimen_AngularDimension(mod, "IGESDimen_AngularDimension", "defines AngularDimension, Type <202> Form <0> in package IGESDimen Used to dimension angles");

// Constructors
cls_IGESDimen_AngularDimension.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_AngularDimension.def("Init", (void (IGESDimen_AngularDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_WitnessLine> &, const opencascade::handle<IGESDimen_WitnessLine> &, const gp_XY &, const Standard_Real, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_LeaderArrow> &)) &IGESDimen_AngularDimension::Init, "This method is used to set the fields of the class AngularDimension - aNote : General Note Entity - aLine : First Witness Line Entity or Null Handle - anotherLine : Second Witness Line Entity or Null Handle - aVertex : Coordinates of vertex point - aRadius : Radius of leader arcs - aLeader : First Leader Entity - anotherLeader : Second Leader Entity", py::arg("aNote"), py::arg("aLine"), py::arg("anotherLine"), py::arg("aVertex"), py::arg("aRadius"), py::arg("aLeader"), py::arg("anotherLeader"));
cls_IGESDimen_AngularDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::Note, "returns the General Note Entity of the Dimension.");
cls_IGESDimen_AngularDimension.def("HasFirstWitnessLine", (Standard_Boolean (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::HasFirstWitnessLine, "returns False if theFirstWitnessLine is Null Handle.");
cls_IGESDimen_AngularDimension.def("FirstWitnessLine", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::FirstWitnessLine, "returns the First Witness Line Entity or Null Handle.");
cls_IGESDimen_AngularDimension.def("HasSecondWitnessLine", (Standard_Boolean (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::HasSecondWitnessLine, "returns False if theSecondWitnessLine is Null Handle.");
cls_IGESDimen_AngularDimension.def("SecondWitnessLine", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::SecondWitnessLine, "returns the Second Witness Line Entity or Null Handle.");
cls_IGESDimen_AngularDimension.def("Vertex", (gp_Pnt2d (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::Vertex, "returns the co-ordinates of the Vertex point as Pnt2d from gp.");
cls_IGESDimen_AngularDimension.def("TransformedVertex", (gp_Pnt2d (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::TransformedVertex, "returns the co-ordinates of the Vertex point as Pnt2d from gp after Transformation. (Z = 0.0 for Transformation)");
cls_IGESDimen_AngularDimension.def("Radius", (Standard_Real (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::Radius, "returns the Radius of the Leader arcs.");
cls_IGESDimen_AngularDimension.def("FirstLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::FirstLeader, "returns the First Leader Entity.");
cls_IGESDimen_AngularDimension.def("SecondLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::SecondLeader, "returns the Second Leader Entity.");
cls_IGESDimen_AngularDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_AngularDimension::get_type_name, "None");
cls_IGESDimen_AngularDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_AngularDimension::get_type_descriptor, "None");
cls_IGESDimen_AngularDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::DynamicType, "None");

// Enums

}