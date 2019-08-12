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
#include <Standard_TypeDef.hxx>
#include <IGESGeom_CircularArc.hxx>
#include <IGESGeom_CompositeCurve.hxx>
#include <IGESDimen_PointDimension.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_PointDimension(py::module &mod){

py::class_<IGESDimen_PointDimension, opencascade::handle<IGESDimen_PointDimension>, IGESData_IGESEntity> cls_IGESDimen_PointDimension(mod, "IGESDimen_PointDimension", "defines IGES Point Dimension, Type <220> Form <0>, in package IGESDimen A Point Dimension Entity consists of a leader, text, and an optional circle or hexagon enclosing the text IGES specs for this entity mention SimpleClosedPlanarCurve Entity(106/63)which is not listed in LIST.Text In the sequel we have ignored this & considered only the other two entity for representing the hexagon or circle enclosing the text.");

// Constructors
cls_IGESDimen_PointDimension.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_PointDimension.def("Init", (void (IGESDimen_PointDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESData_IGESEntity> &)) &IGESDimen_PointDimension::Init, "None", py::arg("aNote"), py::arg("anArrow"), py::arg("aGeom"));
cls_IGESDimen_PointDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::Note, "None");
cls_IGESDimen_PointDimension.def("LeaderArrow", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::LeaderArrow, "None");
cls_IGESDimen_PointDimension.def("GeomCase", (Standard_Integer (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::GeomCase, "returns the type of geometric entity. 0 if no hexagon or circle encloses the text 1 if CircularArc 2 if CompositeCurve 3 otherwise");
cls_IGESDimen_PointDimension.def("Geom", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::Geom, "returns the Geometry Entity, Null handle if GeomCase(me) .eq. 0");
cls_IGESDimen_PointDimension.def("CircularArc", (opencascade::handle<IGESGeom_CircularArc> (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::CircularArc, "returns Null handle if GeomCase(me) .ne. 1");
cls_IGESDimen_PointDimension.def("CompositeCurve", (opencascade::handle<IGESGeom_CompositeCurve> (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::CompositeCurve, "returns Null handle if GeomCase(me) .ne. 2");
cls_IGESDimen_PointDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_PointDimension::get_type_name, "None");
cls_IGESDimen_PointDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_PointDimension::get_type_descriptor, "None");
cls_IGESDimen_PointDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::DynamicType, "None");

// Enums

}