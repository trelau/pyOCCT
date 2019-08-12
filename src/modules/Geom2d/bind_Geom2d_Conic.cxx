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
#include <Geom2d_Curve.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Conic.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Conic(py::module &mod){

py::class_<Geom2d_Conic, opencascade::handle<Geom2d_Conic>, Geom2d_Curve> cls_Geom2d_Conic(mod, "Geom2d_Conic", "The abstract class Conic describes the common behavior of conic curves in 2D space and, in particular, their general characteristics. The Geom2d package provides four specific classes of conics: Geom2d_Circle, Geom2d_Ellipse, Geom2d_Hyperbola and Geom2d_Parabola. A conic is positioned in the plane with a coordinate system (gp_Ax22d object), where the origin is the center of the conic (or the apex in case of a parabola). This coordinate system is the local coordinate system of the conic. It gives the conic an explicit orientation, determining the direction in which the parameter increases along the conic. The 'X Axis' of the local coordinate system also defines the origin of the parameter of the conic.");

// Fields

// Methods
cls_Geom2d_Conic.def("SetAxis", (void (Geom2d_Conic::*)(const gp_Ax22d &)) &Geom2d_Conic::SetAxis, "Modifies this conic, redefining its local coordinate system partially, by assigning P as its origin", py::arg("A"));
cls_Geom2d_Conic.def("SetXAxis", (void (Geom2d_Conic::*)(const gp_Ax2d &)) &Geom2d_Conic::SetXAxis, "None", py::arg("A"));
cls_Geom2d_Conic.def("SetYAxis", (void (Geom2d_Conic::*)(const gp_Ax2d &)) &Geom2d_Conic::SetYAxis, "Assigns the origin and unit vector of axis A to the origin of the local coordinate system of this conic and either: - its 'X Direction', or - its 'Y Direction'. The other unit vector of the local coordinate system of this conic is recomputed normal to A, without changing the orientation of the local coordinate system (right-handed or left-handed).", py::arg("A"));
cls_Geom2d_Conic.def("SetLocation", (void (Geom2d_Conic::*)(const gp_Pnt2d &)) &Geom2d_Conic::SetLocation, "Modifies this conic, redefining its local coordinate system fully, by assigning A as this coordinate system.", py::arg("P"));
cls_Geom2d_Conic.def("XAxis", (gp_Ax2d (Geom2d_Conic::*)() const) &Geom2d_Conic::XAxis, "Returns the 'XAxis' of the conic. This axis defines the origin of parametrization of the conic. This axis and the 'Yaxis' define the local coordinate system of the conic. -C++: return const&");
cls_Geom2d_Conic.def("YAxis", (gp_Ax2d (Geom2d_Conic::*)() const) &Geom2d_Conic::YAxis, "Returns the 'YAxis' of the conic. The 'YAxis' is perpendicular to the 'Xaxis'.");
cls_Geom2d_Conic.def("Eccentricity", (Standard_Real (Geom2d_Conic::*)() const) &Geom2d_Conic::Eccentricity, "returns the eccentricity value of the conic e. e = 0 for a circle 0 < e < 1 for an ellipse (e = 0 if MajorRadius = MinorRadius) e > 1 for a hyperbola e = 1 for a parabola");
cls_Geom2d_Conic.def("Location", (gp_Pnt2d (Geom2d_Conic::*)() const) &Geom2d_Conic::Location, "Returns the location point of the conic. For the circle, the ellipse and the hyperbola it is the center of the conic. For the parabola it is the vertex of the parabola.");
cls_Geom2d_Conic.def("Position", (const gp_Ax22d & (Geom2d_Conic::*)() const) &Geom2d_Conic::Position, "Returns the local coordinates system of the conic.");
cls_Geom2d_Conic.def("Reverse", (void (Geom2d_Conic::*)()) &Geom2d_Conic::Reverse, "Reverses the direction of parameterization of <me>. The local coordinate system of the conic is modified.");
cls_Geom2d_Conic.def("ReversedParameter", (Standard_Real (Geom2d_Conic::*)(const Standard_Real) const) &Geom2d_Conic::ReversedParameter, "Returns the parameter on the reversed curve for the point of parameter U on <me>.", py::arg("U"));
cls_Geom2d_Conic.def("Continuity", (GeomAbs_Shape (Geom2d_Conic::*)() const) &Geom2d_Conic::Continuity, "Returns GeomAbs_CN which is the global continuity of any conic.");
cls_Geom2d_Conic.def("IsCN", (Standard_Boolean (Geom2d_Conic::*)(const Standard_Integer) const) &Geom2d_Conic::IsCN, "Returns True, the order of continuity of a conic is infinite.", py::arg("N"));
cls_Geom2d_Conic.def_static("get_type_name_", (const char * (*)()) &Geom2d_Conic::get_type_name, "None");
cls_Geom2d_Conic.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Conic::get_type_descriptor, "None");
cls_Geom2d_Conic.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Conic::*)() const) &Geom2d_Conic::DynamicType, "None");

// Enums

}