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
#include <gp_Sphere.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_SphericalSurface.hxx>
#include <Standard_Type.hxx>

void bind_Geom_SphericalSurface(py::module &mod){

py::class_<Geom_SphericalSurface, opencascade::handle<Geom_SphericalSurface>, Geom_ElementarySurface> cls_Geom_SphericalSurface(mod, "Geom_SphericalSurface", "Describes a sphere. A sphere is defined by its radius, and is positioned in space by a coordinate system (a gp_Ax3 object), the origin of which is the center of the sphere. This coordinate system is the 'local coordinate system' of the sphere. The following apply: - Rotation around its 'main Axis', in the trigonometric sense given by the 'X Direction' and the 'Y Direction', defines the u parametric direction. - Its 'X Axis' gives the origin for the u parameter. - The 'reference meridian' of the sphere is a half-circle, of radius equal to the radius of the sphere. It is located in the plane defined by the origin, 'X Direction' and 'main Direction', centered on the origin, and positioned on the positive side of the 'X Axis'. - Rotation around the 'Y Axis' gives the v parameter on the reference meridian. - The 'X Axis' gives the origin of the v parameter on the reference meridian. - The v parametric direction is oriented by the 'main Direction', i.e. when v increases, the Z coordinate increases. (This implies that the 'Y Direction' orients the reference meridian only when the local coordinate system is indirect.) - The u isoparametric curve is a half-circle obtained by rotating the reference meridian of the sphere through an angle u around the 'main Axis', in the trigonometric sense defined by the 'X Direction' and the 'Y Direction'. The parametric equation of the sphere is: P(u,v) = O + R*cos(v)*(cos(u)*XDir + sin(u)*YDir)+R*sin(v)*ZDir where: - O, XDir, YDir and ZDir are respectively the origin, the 'X Direction', the 'Y Direction' and the 'Z Direction' of its local coordinate system, and - R is the radius of the sphere. The parametric range of the two parameters is: - [ 0, 2.*Pi ] for u, and - [ - Pi/2., + Pi/2. ] for v.");

// Constructors
cls_Geom_SphericalSurface.def(py::init<const gp_Ax3 &, const Standard_Real>(), py::arg("A3"), py::arg("Radius"));
cls_Geom_SphericalSurface.def(py::init<const gp_Sphere &>(), py::arg("S"));

// Fields

// Methods
cls_Geom_SphericalSurface.def("SetRadius", (void (Geom_SphericalSurface::*)(const Standard_Real)) &Geom_SphericalSurface::SetRadius, "Assigns the value R to the radius of this sphere. Exceptions Standard_ConstructionError if R is less than 0.0.", py::arg("R"));
cls_Geom_SphericalSurface.def("SetSphere", (void (Geom_SphericalSurface::*)(const gp_Sphere &)) &Geom_SphericalSurface::SetSphere, "Converts the gp_Sphere S into this sphere.", py::arg("S"));
cls_Geom_SphericalSurface.def("Sphere", (gp_Sphere (Geom_SphericalSurface::*)() const) &Geom_SphericalSurface::Sphere, "Returns a non persistent sphere with the same geometric properties as <me>.");
cls_Geom_SphericalSurface.def("UReversedParameter", (Standard_Real (Geom_SphericalSurface::*)(const Standard_Real) const) &Geom_SphericalSurface::UReversedParameter, "Computes the u parameter on the modified surface, when reversing its u parametric direction, for any point of u parameter U on this sphere. In the case of a sphere, these functions returns 2.PI - U.", py::arg("U"));
cls_Geom_SphericalSurface.def("VReversedParameter", (Standard_Real (Geom_SphericalSurface::*)(const Standard_Real) const) &Geom_SphericalSurface::VReversedParameter, "Computes the v parameter on the modified surface, when reversing its v parametric direction, for any point of v parameter V on this sphere. In the case of a sphere, these functions returns -U.", py::arg("V"));
cls_Geom_SphericalSurface.def("Area", (Standard_Real (Geom_SphericalSurface::*)() const) &Geom_SphericalSurface::Area, "Computes the aera of the spherical surface.");
cls_Geom_SphericalSurface.def("Bounds", [](Geom_SphericalSurface &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "Returns the parametric bounds U1, U2, V1 and V2 of this sphere. For a sphere: U1 = 0, U2 = 2*PI, V1 = -PI/2, V2 = PI/2.", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Geom_SphericalSurface.def("Coefficients", [](Geom_SphericalSurface &self, Standard_Real & A1, Standard_Real & A2, Standard_Real & A3, Standard_Real & B1, Standard_Real & B2, Standard_Real & B3, Standard_Real & C1, Standard_Real & C2, Standard_Real & C3, Standard_Real & D){ self.Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); }, "Returns the coefficients of the implicit equation of the quadric in the absolute cartesian coordinates system : These coefficients are normalized. A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) + 2.(C1.X + C2.Y + C3.Z) + D = 0.0", py::arg("A1"), py::arg("A2"), py::arg("A3"), py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("D"));
cls_Geom_SphericalSurface.def("Radius", (Standard_Real (Geom_SphericalSurface::*)() const) &Geom_SphericalSurface::Radius, "Computes the coefficients of the implicit equation of this quadric in the absolute Cartesian coordinate system: A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) + 2.(C1.X + C2.Y + C3.Z) + D = 0.0 An implicit normalization is applied (i.e. A1 = A2 = 1. in the local coordinate system of this sphere).");
cls_Geom_SphericalSurface.def("Volume", (Standard_Real (Geom_SphericalSurface::*)() const) &Geom_SphericalSurface::Volume, "Computes the volume of the spherical surface.");
cls_Geom_SphericalSurface.def("IsUClosed", (Standard_Boolean (Geom_SphericalSurface::*)() const) &Geom_SphericalSurface::IsUClosed, "Returns True.");
cls_Geom_SphericalSurface.def("IsVClosed", (Standard_Boolean (Geom_SphericalSurface::*)() const) &Geom_SphericalSurface::IsVClosed, "Returns False.");
cls_Geom_SphericalSurface.def("IsUPeriodic", (Standard_Boolean (Geom_SphericalSurface::*)() const) &Geom_SphericalSurface::IsUPeriodic, "Returns True.");
cls_Geom_SphericalSurface.def("IsVPeriodic", (Standard_Boolean (Geom_SphericalSurface::*)() const) &Geom_SphericalSurface::IsVPeriodic, "Returns False.");
cls_Geom_SphericalSurface.def("UIso", (opencascade::handle<Geom_Curve> (Geom_SphericalSurface::*)(const Standard_Real) const) &Geom_SphericalSurface::UIso, "Computes the U isoparametric curve. The U isoparametric curves of the surface are defined by the section of the spherical surface with plane obtained by rotation of the plane (Location, XAxis, ZAxis) around ZAxis. This plane defines the origin of parametrization u. For a SphericalSurface the UIso curve is a Circle. Warnings : The radius of this circle can be zero.", py::arg("U"));
cls_Geom_SphericalSurface.def("VIso", (opencascade::handle<Geom_Curve> (Geom_SphericalSurface::*)(const Standard_Real) const) &Geom_SphericalSurface::VIso, "Computes the V isoparametric curve. The V isoparametric curves of the surface are defined by the section of the spherical surface with plane parallel to the plane (Location, XAxis, YAxis). This plane defines the origin of parametrization V. Be careful if V is close to PI/2 or 3*PI/2 the radius of the circle becomes tiny. It is not forbidden in this toolkit to create circle with radius = 0.0 For a SphericalSurface the VIso curve is a Circle. Warnings : The radius of this circle can be zero.", py::arg("V"));
cls_Geom_SphericalSurface.def("D0", (void (Geom_SphericalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Geom_SphericalSurface::D0, "Computes the point P (U, V) on the surface. P (U, V) = Loc + Radius * Sin (V) * Zdir + Radius * Cos (V) * (cos (U) * XDir + sin (U) * YDir) where Loc is the origin of the placement plane (XAxis, YAxis) XDir is the direction of the XAxis and YDir the direction of the YAxis and ZDir the direction of the ZAxis.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Geom_SphericalSurface.def("D1", (void (Geom_SphericalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_SphericalSurface::D1, "Computes the current point and the first derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Geom_SphericalSurface.def("D2", (void (Geom_SphericalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_SphericalSurface::D2, "Computes the current point, the first and the second derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Geom_SphericalSurface.def("D3", (void (Geom_SphericalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_SphericalSurface::D3, "Computes the current point, the first,the second and the third derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Geom_SphericalSurface.def("DN", (gp_Vec (Geom_SphericalSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Geom_SphericalSurface::DN, "Computes the derivative of order Nu in the direction u and Nv in the direction v. Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Geom_SphericalSurface.def("Transform", (void (Geom_SphericalSurface::*)(const gp_Trsf &)) &Geom_SphericalSurface::Transform, "Applies the transformation T to this sphere.", py::arg("T"));
cls_Geom_SphericalSurface.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_SphericalSurface::*)() const) &Geom_SphericalSurface::Copy, "Creates a new object which is a copy of this sphere.");
cls_Geom_SphericalSurface.def_static("get_type_name_", (const char * (*)()) &Geom_SphericalSurface::get_type_name, "None");
cls_Geom_SphericalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_SphericalSurface::get_type_descriptor, "None");
cls_Geom_SphericalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_SphericalSurface::*)() const) &Geom_SphericalSurface::DynamicType, "None");

// Enums

}