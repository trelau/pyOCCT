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
#include <Geom_ElementarySurface.hxx>
#include <gp_Ax3.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Cone.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf2d.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <gp_Vec.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_ConicalSurface.hxx>
#include <Standard_Type.hxx>

void bind_Geom_ConicalSurface(py::module &mod){

py::class_<Geom_ConicalSurface, opencascade::handle<Geom_ConicalSurface>, Geom_ElementarySurface> cls_Geom_ConicalSurface(mod, "Geom_ConicalSurface", "Describes a cone. A cone is defined by the half-angle at its apex, and is positioned in space by a coordinate system (a gp_Ax3 object) and a reference radius as follows: - The 'main Axis' of the coordinate system is the axis of revolution of the cone. - The plane defined by the origin, the 'X Direction' and the 'Y Direction' of the coordinate system is the reference plane of the cone. The intersection of the cone with this reference plane is a circle of radius equal to the reference radius. - The apex of the cone is on the negative side of the 'main Axis' of the coordinate system if the half-angle is positive, and on the positive side if the half-angle is negative. This coordinate system is the 'local coordinate system' of the cone. The following apply: - Rotation around its 'main Axis', in the trigonometric sense given by the 'X Direction' and the 'Y Direction', defines the u parametric direction. - Its 'X Axis' gives the origin for the u parameter. - Its 'main Direction' is the v parametric direction of the cone. - Its origin is the origin of the v parameter. The parametric range of the two parameters is: - [ 0, 2.*Pi ] for u, and - ] -infinity, +infinity [ for v The parametric equation of the cone is: P(u, v) = O + (R + v*sin(Ang)) * (cos(u)*XDir + sin(u)*YDir) + v*cos(Ang)*ZDir where: - O, XDir, YDir and ZDir are respectively the origin, the 'X Direction', the 'Y Direction' and the 'Z Direction' of the cone's local coordinate system, - Ang is the half-angle at the apex of the cone, and - R is the reference radius.");

// Constructors
cls_Geom_ConicalSurface.def(py::init<const gp_Ax3 &, const Standard_Real, const Standard_Real>(), py::arg("A3"), py::arg("Ang"), py::arg("Radius"));
cls_Geom_ConicalSurface.def(py::init<const gp_Cone &>(), py::arg("C"));

// Fields

// Methods
cls_Geom_ConicalSurface.def("SetCone", (void (Geom_ConicalSurface::*)(const gp_Cone &)) &Geom_ConicalSurface::SetCone, "Set <me> so that <me> has the same geometric properties as C.", py::arg("C"));
cls_Geom_ConicalSurface.def("SetRadius", (void (Geom_ConicalSurface::*)(const Standard_Real)) &Geom_ConicalSurface::SetRadius, "Changes the radius of the conical surface in the placement plane (Z = 0, V = 0). The local coordinate system is not modified. Raised if R < 0.0", py::arg("R"));
cls_Geom_ConicalSurface.def("SetSemiAngle", (void (Geom_ConicalSurface::*)(const Standard_Real)) &Geom_ConicalSurface::SetSemiAngle, "Changes the semi angle of the conical surface.", py::arg("Ang"));
cls_Geom_ConicalSurface.def("Cone", (gp_Cone (Geom_ConicalSurface::*)() const) &Geom_ConicalSurface::Cone, "returns a non transient cone with the same geometric properties as <me>.");
cls_Geom_ConicalSurface.def("UReversedParameter", (Standard_Real (Geom_ConicalSurface::*)(const Standard_Real) const) &Geom_ConicalSurface::UReversedParameter, "return 2.PI - U.", py::arg("U"));
cls_Geom_ConicalSurface.def("VReversedParameter", (Standard_Real (Geom_ConicalSurface::*)(const Standard_Real) const) &Geom_ConicalSurface::VReversedParameter, "Computes the u (or v) parameter on the modified surface, when reversing its u (or v) parametric direction, for any point of u parameter U (or of v parameter V) on this cone. In the case of a cone, these functions return respectively: - 2.*Pi - U, -V.", py::arg("V"));
cls_Geom_ConicalSurface.def("VReverse", (void (Geom_ConicalSurface::*)()) &Geom_ConicalSurface::VReverse, "Changes the orientation of this cone in the v parametric direction. The bounds of the surface are not changed but the v parametric direction is reversed. As a consequence, for a cone: - the 'main Direction' of the local coordinate system is reversed, and - the half-angle at the apex is inverted.");
cls_Geom_ConicalSurface.def("TransformParameters", [](Geom_ConicalSurface &self, Standard_Real & U, Standard_Real & V, const gp_Trsf & T){ self.TransformParameters(U, V, T); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Computes the parameters on the transformed surface for the transform of the point of parameters U,V on <me>.", py::arg("U"), py::arg("V"), py::arg("T"));
cls_Geom_ConicalSurface.def("ParametricTransformation", (gp_GTrsf2d (Geom_ConicalSurface::*)(const gp_Trsf &) const) &Geom_ConicalSurface::ParametricTransformation, "Returns a 2d transformation used to find the new parameters of a point on the transformed surface.", py::arg("T"));
cls_Geom_ConicalSurface.def("Apex", (gp_Pnt (Geom_ConicalSurface::*)() const) &Geom_ConicalSurface::Apex, "Computes the apex of this cone. It is on the negative side of the axis of revolution of this cone if the half-angle at the apex is positive, and on the positive side of the 'main Axis' if the half-angle is negative.");
cls_Geom_ConicalSurface.def("Bounds", [](Geom_ConicalSurface &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "The conical surface is infinite in the V direction so V1 = Realfirst from Standard and V2 = RealLast. U1 = 0 and U2 = 2*PI.", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Geom_ConicalSurface.def("Coefficients", [](Geom_ConicalSurface &self, Standard_Real & A1, Standard_Real & A2, Standard_Real & A3, Standard_Real & B1, Standard_Real & B2, Standard_Real & B3, Standard_Real & C1, Standard_Real & C2, Standard_Real & C3, Standard_Real & D){ self.Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); }, "Returns the coefficients of the implicit equation of the quadric in the absolute cartesian coordinate system : These coefficients are normalized. A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) + 2.(C1.X + C2.Y + C3.Z) + D = 0.0", py::arg("A1"), py::arg("A2"), py::arg("A3"), py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("D"));
cls_Geom_ConicalSurface.def("RefRadius", (Standard_Real (Geom_ConicalSurface::*)() const) &Geom_ConicalSurface::RefRadius, "Returns the reference radius of this cone. The reference radius is the radius of the circle formed by the intersection of this cone and its reference plane (i.e. the plane defined by the origin, 'X Direction' and 'Y Direction' of the local coordinate system of this cone). If the apex of this cone is on the origin of the local coordinate system of this cone, the returned value is 0.");
cls_Geom_ConicalSurface.def("SemiAngle", (Standard_Real (Geom_ConicalSurface::*)() const) &Geom_ConicalSurface::SemiAngle, "returns the semi-angle of the conical surface ]0.0, PI/2[.");
cls_Geom_ConicalSurface.def("IsUClosed", (Standard_Boolean (Geom_ConicalSurface::*)() const) &Geom_ConicalSurface::IsUClosed, "returns True.");
cls_Geom_ConicalSurface.def("IsVClosed", (Standard_Boolean (Geom_ConicalSurface::*)() const) &Geom_ConicalSurface::IsVClosed, "returns False.");
cls_Geom_ConicalSurface.def("IsUPeriodic", (Standard_Boolean (Geom_ConicalSurface::*)() const) &Geom_ConicalSurface::IsUPeriodic, "Returns True.");
cls_Geom_ConicalSurface.def("IsVPeriodic", (Standard_Boolean (Geom_ConicalSurface::*)() const) &Geom_ConicalSurface::IsVPeriodic, "Returns False.");
cls_Geom_ConicalSurface.def("UIso", (opencascade::handle<Geom_Curve> (Geom_ConicalSurface::*)(const Standard_Real) const) &Geom_ConicalSurface::UIso, "Builds the U isoparametric line of this cone. The origin of this line is on the reference plane of this cone (i.e. the plane defined by the origin, 'X Direction' and 'Y Direction' of the local coordinate system of this cone).", py::arg("U"));
cls_Geom_ConicalSurface.def("VIso", (opencascade::handle<Geom_Curve> (Geom_ConicalSurface::*)(const Standard_Real) const) &Geom_ConicalSurface::VIso, "Builds the V isoparametric circle of this cone. It is the circle on this cone, located in the plane of Z coordinate V*cos(Semi-Angle) in the local coordinate system of this cone. The 'Axis' of this circle is the axis of revolution of this cone. Its starting point is defined by the 'X Direction' of this cone. Warning If the V isoparametric circle is close to the apex of this cone, the radius of the circle becomes very small. It is possible to have a circle with radius equal to 0.0.", py::arg("V"));
cls_Geom_ConicalSurface.def("D0", (void (Geom_ConicalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Geom_ConicalSurface::D0, "Computes the point P (U, V) on the surface. P (U, V) = Loc + (RefRadius + V * sin (Semi-Angle)) * (cos (U) * XDir + sin (U) * YDir) + V * cos (Semi-Angle) * ZDir where Loc is the origin of the placement plane (XAxis, YAxis) XDir is the direction of the XAxis and YDir the direction of the YAxis.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Geom_ConicalSurface.def("D1", (void (Geom_ConicalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_ConicalSurface::D1, "Computes the current point and the first derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Geom_ConicalSurface.def("D2", (void (Geom_ConicalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_ConicalSurface::D2, "Computes the current point, the first and the second derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Geom_ConicalSurface.def("D3", (void (Geom_ConicalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_ConicalSurface::D3, "Computes the current point, the first,the second and the third derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Geom_ConicalSurface.def("DN", (gp_Vec (Geom_ConicalSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Geom_ConicalSurface::DN, "Computes the derivative of order Nu in the u parametric direction, and Nv in the v parametric direction at the point of parameters (U, V) of this cone. Exceptions Standard_RangeError if: - Nu + Nv is less than 1, - Nu or Nv is negative.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Geom_ConicalSurface.def("Transform", (void (Geom_ConicalSurface::*)(const gp_Trsf &)) &Geom_ConicalSurface::Transform, "Applies the transformation T to this cone.", py::arg("T"));
cls_Geom_ConicalSurface.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_ConicalSurface::*)() const) &Geom_ConicalSurface::Copy, "Creates a new object which is a copy of this cone.");
cls_Geom_ConicalSurface.def_static("get_type_name_", (const char * (*)()) &Geom_ConicalSurface::get_type_name, "None");
cls_Geom_ConicalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_ConicalSurface::get_type_descriptor, "None");
cls_Geom_ConicalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_ConicalSurface::*)() const) &Geom_ConicalSurface::DynamicType, "None");

// Enums

}