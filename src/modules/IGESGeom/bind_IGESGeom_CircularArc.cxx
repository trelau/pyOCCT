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
#include <gp_XY.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <IGESGeom_CircularArc.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_CircularArc(py::module &mod){

py::class_<IGESGeom_CircularArc, opencascade::handle<IGESGeom_CircularArc>, IGESData_IGESEntity> cls_IGESGeom_CircularArc(mod, "IGESGeom_CircularArc", "defines IGESCircularArc, Type <100> Form <0> in package IGESGeom A circular arc is a connected portion of a parent circle which consists of more than one point. The definition space coordinate system is always chosen so that the circular arc remains in a plane either coincident with or parallel to the XT, YT plane.");

// Constructors
cls_IGESGeom_CircularArc.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_CircularArc.def("Init", (void (IGESGeom_CircularArc::*)(const Standard_Real, const gp_XY &, const gp_XY &, const gp_XY &)) &IGESGeom_CircularArc::Init, "This method is used to set the fields of the class CircularArc - aZT : Shift above the Z plane - aCenter : Center of the circle of which the arc forms a part - aStart : Starting point of the circular arc - anEnd : Ending point of the circular arc", py::arg("aZT"), py::arg("aCenter"), py::arg("aStart"), py::arg("anEnd"));
cls_IGESGeom_CircularArc.def("Center", (gp_Pnt2d (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::Center, "returns the center of the circle of which arc forms a part");
cls_IGESGeom_CircularArc.def("TransformedCenter", (gp_Pnt (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::TransformedCenter, "returns the center of the circle of which arc forms a part after applying Transf. Matrix");
cls_IGESGeom_CircularArc.def("StartPoint", (gp_Pnt2d (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::StartPoint, "returns the start point of the arc");
cls_IGESGeom_CircularArc.def("TransformedStartPoint", (gp_Pnt (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::TransformedStartPoint, "returns the start point of the arc after applying Transf. Matrix");
cls_IGESGeom_CircularArc.def("ZPlane", (Standard_Real (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::ZPlane, "returns the parallel displacement of the plane containing the arc from the XT, YT plane");
cls_IGESGeom_CircularArc.def("EndPoint", (gp_Pnt2d (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::EndPoint, "returns the end point of the arc");
cls_IGESGeom_CircularArc.def("TransformedEndPoint", (gp_Pnt (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::TransformedEndPoint, "returns the end point of the arc after applying Transf. Matrix");
cls_IGESGeom_CircularArc.def("Radius", (Standard_Real (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::Radius, "returns the radius of the circle of which arc forms a part");
cls_IGESGeom_CircularArc.def("Angle", (Standard_Real (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::Angle, "returns the angle subtended by the arc at the center in radians");
cls_IGESGeom_CircularArc.def("Axis", (gp_Dir (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::Axis, "Z-Axis of circle (i.e. [0,0,1])");
cls_IGESGeom_CircularArc.def("TransformedAxis", (gp_Dir (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::TransformedAxis, "Z-Axis after applying Trans. Matrix");
cls_IGESGeom_CircularArc.def("IsClosed", (Standard_Boolean (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::IsClosed, "True if StartPoint = EndPoint");
cls_IGESGeom_CircularArc.def_static("get_type_name_", (const char * (*)()) &IGESGeom_CircularArc::get_type_name, "None");
cls_IGESGeom_CircularArc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_CircularArc::get_type_descriptor, "None");
cls_IGESGeom_CircularArc.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_CircularArc::*)() const) &IGESGeom_CircularArc::DynamicType, "None");

// Enums

}