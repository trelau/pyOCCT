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
#include <Geom_Curve.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Conic.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Conic(py::module &mod){

py::class_<Geom_Conic, opencascade::handle<Geom_Conic>, Geom_Curve> cls_Geom_Conic(mod, "Geom_Conic", "The abstract class Conic describes the common behavior of conic curves in 3D space and, in particular, their general characteristics. The Geom package provides four concrete classes of conics: Geom_Circle, Geom_Ellipse, Geom_Hyperbola and Geom_Parabola. A conic is positioned in space with a right-handed coordinate system (gp_Ax2 object), where: - the origin is the center of the conic (or the apex in the case of a parabola), - the origin, 'X Direction' and 'Y Direction' define the plane of the conic. This coordinate system is the local coordinate system of the conic. The 'main Direction' of this coordinate system is the vector normal to the plane of the conic. The axis, of which the origin and unit vector are respectively the origin and 'main Direction' of the local coordinate system, is termed the 'Axis' or 'main Axis' of the conic. The 'main Direction' of the local coordinate system gives an explicit orientation to the conic, determining the direction in which the parameter increases along the conic. The 'X Axis' of the local coordinate system also defines the origin of the parameter of the conic.");

// Fields

// Methods
cls_Geom_Conic.def("SetAxis", (void (Geom_Conic::*)(const gp_Ax1 &)) &Geom_Conic::SetAxis, "Changes the orientation of the conic's plane. The normal axis to the plane is A1. The XAxis and the YAxis are recomputed.", py::arg("A1"));
cls_Geom_Conic.def("SetLocation", (void (Geom_Conic::*)(const gp_Pnt &)) &Geom_Conic::SetLocation, "changes the location point of the conic.", py::arg("P"));
cls_Geom_Conic.def("SetPosition", (void (Geom_Conic::*)(const gp_Ax2 &)) &Geom_Conic::SetPosition, "changes the local coordinate system of the conic.", py::arg("A2"));
cls_Geom_Conic.def("Axis", (gp_Ax1 (Geom_Conic::*)() const) &Geom_Conic::Axis, "Returns the 'main Axis' of this conic. This axis is normal to the plane of the conic.");
cls_Geom_Conic.def("Eccentricity", (Standard_Real (Geom_Conic::*)() const) &Geom_Conic::Eccentricity, "Returns the eccentricity value of the conic e. e = 0 for a circle 0 < e < 1 for an ellipse (e = 0 if MajorRadius = MinorRadius) e > 1 for a hyperbola e = 1 for a parabola Exceptions Standard_DomainError in the case of a hyperbola if its major radius is null.");
cls_Geom_Conic.def("Location", (gp_Pnt (Geom_Conic::*)() const) &Geom_Conic::Location, "Returns the location point of the conic. For the circle, the ellipse and the hyperbola it is the center of the conic. For the parabola it is the Apex of the parabola.");
cls_Geom_Conic.def("Position", (const gp_Ax2 & (Geom_Conic::*)() const) &Geom_Conic::Position, "Returns the local coordinates system of the conic. The main direction of the Axis2Placement is normal to the plane of the conic. The X direction of the Axis2placement is in the plane of the conic and corresponds to the origin for the conic's parametric value u.");
cls_Geom_Conic.def("XAxis", (gp_Ax1 (Geom_Conic::*)() const) &Geom_Conic::XAxis, "Returns the XAxis of the conic. This axis defines the origin of parametrization of the conic. This axis is perpendicular to the Axis of the conic. This axis and the Yaxis define the plane of the conic.");
cls_Geom_Conic.def("YAxis", (gp_Ax1 (Geom_Conic::*)() const) &Geom_Conic::YAxis, "Returns the YAxis of the conic. The YAxis is perpendicular to the Xaxis. This axis and the Xaxis define the plane of the conic.");
cls_Geom_Conic.def("Reverse", (void (Geom_Conic::*)()) &Geom_Conic::Reverse, "Reverses the direction of parameterization of <me>. The local coordinate system of the conic is modified.");
cls_Geom_Conic.def("ReversedParameter", (Standard_Real (Geom_Conic::*)(const Standard_Real) const) &Geom_Conic::ReversedParameter, "Returns the parameter on the reversed curve for the point of parameter U on <me>.", py::arg("U"));
cls_Geom_Conic.def("Continuity", (GeomAbs_Shape (Geom_Conic::*)() const) &Geom_Conic::Continuity, "The continuity of the conic is Cn.");
cls_Geom_Conic.def("IsCN", (Standard_Boolean (Geom_Conic::*)(const Standard_Integer) const) &Geom_Conic::IsCN, "Returns True. Raised if N < 0.", py::arg("N"));
cls_Geom_Conic.def_static("get_type_name_", (const char * (*)()) &Geom_Conic::get_type_name, "None");
cls_Geom_Conic.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Conic::get_type_descriptor, "None");
cls_Geom_Conic.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Conic::*)() const) &Geom_Conic::DynamicType, "None");

// Enums

}