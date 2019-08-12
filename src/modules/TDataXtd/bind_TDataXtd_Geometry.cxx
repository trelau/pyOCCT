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
#include <TDF_Attribute.hxx>
#include <Standard_Handle.hxx>
#include <TDataXtd_Geometry.hxx>
#include <TDF_Label.hxx>
#include <TDataXtd_GeometryEnum.hxx>
#include <TNaming_NamedShape.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <Standard_GUID.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataXtd_Geometry(py::module &mod){

py::class_<TDataXtd_Geometry, opencascade::handle<TDataXtd_Geometry>, TDF_Attribute> cls_TDataXtd_Geometry(mod, "TDataXtd_Geometry", "This class is used to model construction geometry. The specific geometric construction of the attribute is defined by an element of the enumeration TDataXtd_GeometryEnum. This attribute may also be used to qualify underlying geometry of the associated NamedShape. for Constructuion element by example.");

// Constructors
cls_TDataXtd_Geometry.def(py::init<>());

// Fields

// Methods
cls_TDataXtd_Geometry.def_static("Set_", (opencascade::handle<TDataXtd_Geometry> (*)(const TDF_Label &)) &TDataXtd_Geometry::Set, "API class methods ================= Finds, or creates, a Geometry attribute defined by the label label. The default type of geometry is the value ANY_GEOM of the enumeration TDataXtd_GeometryEnum. To specify another value of this enumeration, use the function SetType.", py::arg("label"));
cls_TDataXtd_Geometry.def_static("Type_", (TDataXtd_GeometryEnum (*)(const TDF_Label &)) &TDataXtd_Geometry::Type, "Returns the label L used to define the type of geometric construction for the geometry attribute.", py::arg("L"));
cls_TDataXtd_Geometry.def_static("Type_", (TDataXtd_GeometryEnum (*)(const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_Geometry::Type, "Returns the topological attribute S used to define the type of geometric construction for the geometry attribute.", py::arg("S"));
cls_TDataXtd_Geometry.def_static("Point_", (Standard_Boolean (*)(const TDF_Label &, gp_Pnt &)) &TDataXtd_Geometry::Point, "Returns the point attribute defined by the label L and the point G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Point_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Pnt &)) &TDataXtd_Geometry::Point, "Returns the point attribute defined by the topological attribute S and the point G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Axis_", (Standard_Boolean (*)(const TDF_Label &, gp_Ax1 &)) &TDataXtd_Geometry::Axis, "Returns the axis attribute defined by the label L and the axis G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Axis_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Ax1 &)) &TDataXtd_Geometry::Axis, "Returns the axis attribute defined by the topological attribute S and the axis G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Line_", (Standard_Boolean (*)(const TDF_Label &, gp_Lin &)) &TDataXtd_Geometry::Line, "Returns the line attribute defined by the label L and the line G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Line_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Lin &)) &TDataXtd_Geometry::Line, "Returns the line attribute defined by the topological attribute S and the line G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Circle_", (Standard_Boolean (*)(const TDF_Label &, gp_Circ &)) &TDataXtd_Geometry::Circle, "Returns the circle attribute defined by the label L and the circle G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Circle_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Circ &)) &TDataXtd_Geometry::Circle, "Returns the circle attribute defined by the topological attribute S and the circle G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Ellipse_", (Standard_Boolean (*)(const TDF_Label &, gp_Elips &)) &TDataXtd_Geometry::Ellipse, "Returns the ellipse attribute defined by the label L and the ellipse G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Ellipse_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Elips &)) &TDataXtd_Geometry::Ellipse, "Returns the ellipse attribute defined by the topological attribute S and the ellipse G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Plane_", (Standard_Boolean (*)(const TDF_Label &, gp_Pln &)) &TDataXtd_Geometry::Plane, "Returns the plane attribute defined by the label L and the plane G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Plane_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Pln &)) &TDataXtd_Geometry::Plane, "Returns the plane attribute defined by the topological attribute S and the plane G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Cylinder_", (Standard_Boolean (*)(const TDF_Label &, gp_Cylinder &)) &TDataXtd_Geometry::Cylinder, "Returns the cylinder attribute defined by the label L and the cylinder G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Cylinder_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Cylinder &)) &TDataXtd_Geometry::Cylinder, "Returns the cylinder attribute defined by the topological attribute S and the cylinder G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Geometry::GetID, "Returns the GUID for geometry attributes.");
cls_TDataXtd_Geometry.def("SetType", (void (TDataXtd_Geometry::*)(const TDataXtd_GeometryEnum)) &TDataXtd_Geometry::SetType, "Returns the type of geometric construction T of this attribute. T will be a value of the enumeration TDataXtd_GeometryEnum.", py::arg("T"));
cls_TDataXtd_Geometry.def("GetType", (TDataXtd_GeometryEnum (TDataXtd_Geometry::*)() const) &TDataXtd_Geometry::GetType, "Returns the type of geometric construction.");
cls_TDataXtd_Geometry.def("ID", (const Standard_GUID & (TDataXtd_Geometry::*)() const) &TDataXtd_Geometry::ID, "None");
cls_TDataXtd_Geometry.def("Restore", (void (TDataXtd_Geometry::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Geometry::Restore, "None", py::arg("with"));
cls_TDataXtd_Geometry.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Geometry::*)() const) &TDataXtd_Geometry::NewEmpty, "None");
cls_TDataXtd_Geometry.def("Paste", (void (TDataXtd_Geometry::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Geometry::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataXtd_Geometry.def("Dump", (Standard_OStream & (TDataXtd_Geometry::*)(Standard_OStream &) const) &TDataXtd_Geometry::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Geometry.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Geometry::get_type_name, "None");
cls_TDataXtd_Geometry.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Geometry::get_type_descriptor, "None");
cls_TDataXtd_Geometry.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Geometry::*)() const) &TDataXtd_Geometry::DynamicType, "None");

// Enums

}