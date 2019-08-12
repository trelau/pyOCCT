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
#include <gp_Torus.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <Standard_Type.hxx>

void bind_Geom_ToroidalSurface(py::module &mod){

py::class_<Geom_ToroidalSurface, opencascade::handle<Geom_ToroidalSurface>, Geom_ElementarySurface> cls_Geom_ToroidalSurface(mod, "Geom_ToroidalSurface", "Describes a torus. A torus is defined by its major and minor radii, and positioned in space with a coordinate system (a gp_Ax3 object) as follows: - The origin is the center of the torus. - The surface is obtained by rotating a circle around the 'main Direction'. This circle has a radius equal to the minor radius, and is located in the plane defined by the origin, 'X Direction' and 'main Direction'. It is centered on the 'X Axis', on its positive side, and positioned at a distance from the origin equal to the major radius. This circle is the 'reference circle' of the torus. - The plane defined by the origin, the 'X Direction' and the 'Y Direction' is called the 'reference plane' of the torus. This coordinate system is the 'local coordinate system' of the torus. The following apply: - Rotation around its 'main Axis', in the trigonometric sense given by 'X Direction' and 'Y Direction', defines the u parametric direction. - The 'X Axis' gives the origin for the u parameter. - Rotation around an axis parallel to the 'Y Axis' and passing through the center of the 'reference circle' gives the v parameter on the 'reference circle'. - The 'X Axis' gives the origin of the v parameter on the 'reference circle'. - The v parametric direction is oriented by the inverse of the 'main Direction', i.e. near 0, as v increases, the Z coordinate decreases. (This implies that the 'Y Direction' orients the reference circle only when the local coordinate system is direct.) - The u isoparametric curve is a circle obtained by rotating the 'reference circle' of the torus through an angle u about the 'main Axis'. The parametric equation of the torus is : P(u, v) = O + (R + r*cos(v)) * (cos(u)*XDir + sin(u)*YDir ) + r*sin(v)*ZDir, where: - O, XDir, YDir and ZDir are respectively the origin, the 'X Direction', the 'Y Direction' and the 'Z Direction' of the local coordinate system, - r and R are, respectively, the minor and major radius. The parametric range of the two parameters is: - [ 0, 2.*Pi ] for u - [ 0, 2.*Pi ] for v");

// Constructors
cls_Geom_ToroidalSurface.def(py::init<const gp_Ax3 &, const Standard_Real, const Standard_Real>(), py::arg("A3"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_Geom_ToroidalSurface.def(py::init<const gp_Torus &>(), py::arg("T"));

// Fields

// Methods
cls_Geom_ToroidalSurface.def("SetMajorRadius", (void (Geom_ToroidalSurface::*)(const Standard_Real)) &Geom_ToroidalSurface::SetMajorRadius, "Modifies this torus by changing its major radius. Exceptions Standard_ConstructionError if: - MajorRadius is negative, or - MajorRadius - r is less than or equal to gp::Resolution(), where r is the minor radius of this torus.", py::arg("MajorRadius"));
cls_Geom_ToroidalSurface.def("SetMinorRadius", (void (Geom_ToroidalSurface::*)(const Standard_Real)) &Geom_ToroidalSurface::SetMinorRadius, "Modifies this torus by changing its minor radius. Exceptions Standard_ConstructionError if: - MinorRadius is negative, or - R - MinorRadius is less than or equal to gp::Resolution(), where R is the major radius of this torus.", py::arg("MinorRadius"));
cls_Geom_ToroidalSurface.def("SetTorus", (void (Geom_ToroidalSurface::*)(const gp_Torus &)) &Geom_ToroidalSurface::SetTorus, "Converts the gp_Torus torus T into this torus.", py::arg("T"));
cls_Geom_ToroidalSurface.def("Torus", (gp_Torus (Geom_ToroidalSurface::*)() const) &Geom_ToroidalSurface::Torus, "Returns the non transient torus with the same geometric properties as <me>.");
cls_Geom_ToroidalSurface.def("UReversedParameter", (Standard_Real (Geom_ToroidalSurface::*)(const Standard_Real) const) &Geom_ToroidalSurface::UReversedParameter, "Return the parameter on the Ureversed surface for the point of parameter U on <me>. Return 2.PI - U.", py::arg("U"));
cls_Geom_ToroidalSurface.def("VReversedParameter", (Standard_Real (Geom_ToroidalSurface::*)(const Standard_Real) const) &Geom_ToroidalSurface::VReversedParameter, "Return the parameter on the Ureversed surface for the point of parameter U on <me>. Return 2.PI - U.", py::arg("U"));
cls_Geom_ToroidalSurface.def("Area", (Standard_Real (Geom_ToroidalSurface::*)() const) &Geom_ToroidalSurface::Area, "Computes the aera of the surface.");
cls_Geom_ToroidalSurface.def("Bounds", [](Geom_ToroidalSurface &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "Returns the parametric bounds U1, U2, V1 and V2 of this torus. For a torus: U1 = V1 = 0 and U2 = V2 = 2*PI .", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Geom_ToroidalSurface.def("Coefficients", (void (Geom_ToroidalSurface::*)(TColStd_Array1OfReal &) const) &Geom_ToroidalSurface::Coefficients, "Returns the coefficients of the implicit equation of the surface in the absolute cartesian coordinate system : Coef(1) * X**4 + Coef(2) * Y**4 + Coef(3) * Z**4 + Coef(4) * X**3 * Y + Coef(5) * X**3 * Z + Coef(6) * Y**3 * X + Coef(7) * Y**3 * Z + Coef(8) * Z**3 * X + Coef(9) * Z**3 * Y + Coef(10) * X**2 * Y**2 + Coef(11) * X**2 * Z**2 + Coef(12) * Y**2 * Z**2 + Coef(13) * X**3 + Coef(14) * Y**3 + Coef(15) * Z**3 + Coef(16) * X**2 * Y + Coef(17) * X**2 * Z + Coef(18) * Y**2 * X + Coef(19) * Y**2 * Z + Coef(20) * Z**2 * X + Coef(21) * Z**2 * Y + Coef(22) * X**2 + Coef(23) * Y**2 + Coef(24) * Z**2 + Coef(25) * X * Y + Coef(26) * X * Z + Coef(27) * Y * Z + Coef(28) * X + Coef(29) * Y + Coef(30) * Z + Coef(31) = 0.0 Raised if the length of Coef is lower than 31.", py::arg("Coef"));
cls_Geom_ToroidalSurface.def("MajorRadius", (Standard_Real (Geom_ToroidalSurface::*)() const) &Geom_ToroidalSurface::MajorRadius, "Returns the major radius, or the minor radius, of this torus.");
cls_Geom_ToroidalSurface.def("MinorRadius", (Standard_Real (Geom_ToroidalSurface::*)() const) &Geom_ToroidalSurface::MinorRadius, "Returns the major radius, or the minor radius, of this torus.");
cls_Geom_ToroidalSurface.def("Volume", (Standard_Real (Geom_ToroidalSurface::*)() const) &Geom_ToroidalSurface::Volume, "Computes the volume.");
cls_Geom_ToroidalSurface.def("IsUClosed", (Standard_Boolean (Geom_ToroidalSurface::*)() const) &Geom_ToroidalSurface::IsUClosed, "Returns True.");
cls_Geom_ToroidalSurface.def("IsVClosed", (Standard_Boolean (Geom_ToroidalSurface::*)() const) &Geom_ToroidalSurface::IsVClosed, "Returns True.");
cls_Geom_ToroidalSurface.def("IsUPeriodic", (Standard_Boolean (Geom_ToroidalSurface::*)() const) &Geom_ToroidalSurface::IsUPeriodic, "Returns True.");
cls_Geom_ToroidalSurface.def("IsVPeriodic", (Standard_Boolean (Geom_ToroidalSurface::*)() const) &Geom_ToroidalSurface::IsVPeriodic, "Returns True.");
cls_Geom_ToroidalSurface.def("UIso", (opencascade::handle<Geom_Curve> (Geom_ToroidalSurface::*)(const Standard_Real) const) &Geom_ToroidalSurface::UIso, "Computes the U isoparametric curve.", py::arg("U"));
cls_Geom_ToroidalSurface.def("VIso", (opencascade::handle<Geom_Curve> (Geom_ToroidalSurface::*)(const Standard_Real) const) &Geom_ToroidalSurface::VIso, "Computes the V isoparametric curve.", py::arg("V"));
cls_Geom_ToroidalSurface.def("D0", (void (Geom_ToroidalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Geom_ToroidalSurface::D0, "Computes the point P (U, V) on the surface. P (U, V) = Loc + MinorRadius * Sin (V) * Zdir + (MajorRadius + MinorRadius * Cos(V)) * (cos (U) * XDir + sin (U) * YDir) where Loc is the origin of the placement plane (XAxis, YAxis) XDir is the direction of the XAxis and YDir the direction of the YAxis and ZDir the direction of the ZAxis.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Geom_ToroidalSurface.def("D1", (void (Geom_ToroidalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_ToroidalSurface::D1, "Computes the current point and the first derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Geom_ToroidalSurface.def("D2", (void (Geom_ToroidalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_ToroidalSurface::D2, "Computes the current point, the first and the second derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Geom_ToroidalSurface.def("D3", (void (Geom_ToroidalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_ToroidalSurface::D3, "Computes the current point, the first,the second and the third derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Geom_ToroidalSurface.def("DN", (gp_Vec (Geom_ToroidalSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Geom_ToroidalSurface::DN, "Computes the derivative of order Nu in the direction u and Nv in the direction v. Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Geom_ToroidalSurface.def("Transform", (void (Geom_ToroidalSurface::*)(const gp_Trsf &)) &Geom_ToroidalSurface::Transform, "Applies the transformation T to this torus.", py::arg("T"));
cls_Geom_ToroidalSurface.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_ToroidalSurface::*)() const) &Geom_ToroidalSurface::Copy, "Creates a new object which is a copy of this torus.");
cls_Geom_ToroidalSurface.def_static("get_type_name_", (const char * (*)()) &Geom_ToroidalSurface::get_type_name, "None");
cls_Geom_ToroidalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_ToroidalSurface::get_type_descriptor, "None");
cls_Geom_ToroidalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_ToroidalSurface::*)() const) &Geom_ToroidalSurface::DynamicType, "None");

// Enums

}