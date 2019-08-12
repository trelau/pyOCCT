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
#include <gp_Cylinder.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Standard_Type.hxx>

void bind_Geom_CylindricalSurface(py::module &mod){

py::class_<Geom_CylindricalSurface, opencascade::handle<Geom_CylindricalSurface>, Geom_ElementarySurface> cls_Geom_CylindricalSurface(mod, "Geom_CylindricalSurface", "This class defines the infinite cylindrical surface.");

// Constructors
cls_Geom_CylindricalSurface.def(py::init<const gp_Ax3 &, const Standard_Real>(), py::arg("A3"), py::arg("Radius"));
cls_Geom_CylindricalSurface.def(py::init<const gp_Cylinder &>(), py::arg("C"));

// Fields

// Methods
cls_Geom_CylindricalSurface.def("SetCylinder", (void (Geom_CylindricalSurface::*)(const gp_Cylinder &)) &Geom_CylindricalSurface::SetCylinder, "Set <me> so that <me> has the same geometric properties as C.", py::arg("C"));
cls_Geom_CylindricalSurface.def("SetRadius", (void (Geom_CylindricalSurface::*)(const Standard_Real)) &Geom_CylindricalSurface::SetRadius, "Changes the radius of the cylinder. Raised if R < 0.0", py::arg("R"));
cls_Geom_CylindricalSurface.def("Cylinder", (gp_Cylinder (Geom_CylindricalSurface::*)() const) &Geom_CylindricalSurface::Cylinder, "returns a non transient cylinder with the same geometric properties as <me>.");
cls_Geom_CylindricalSurface.def("UReversedParameter", (Standard_Real (Geom_CylindricalSurface::*)(const Standard_Real) const) &Geom_CylindricalSurface::UReversedParameter, "Return the parameter on the Ureversed surface for the point of parameter U on <me>. Return 2.PI - U.", py::arg("U"));
cls_Geom_CylindricalSurface.def("VReversedParameter", (Standard_Real (Geom_CylindricalSurface::*)(const Standard_Real) const) &Geom_CylindricalSurface::VReversedParameter, "Return the parameter on the Vreversed surface for the point of parameter V on <me>. Return -V", py::arg("V"));
cls_Geom_CylindricalSurface.def("TransformParameters", [](Geom_CylindricalSurface &self, Standard_Real & U, Standard_Real & V, const gp_Trsf & T){ self.TransformParameters(U, V, T); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Computes the parameters on the transformed surface for the transform of the point of parameters U,V on <me>. me->Transformed(T)->Value(U',V') is the same point as me->Value(U,V).Transformed(T) Where U',V' are the new values of U,V after calling me->TranformParameters(U,V,T) This methods multiplies V by T.ScaleFactor()", py::arg("U"), py::arg("V"), py::arg("T"));
cls_Geom_CylindricalSurface.def("ParametricTransformation", (gp_GTrsf2d (Geom_CylindricalSurface::*)(const gp_Trsf &) const) &Geom_CylindricalSurface::ParametricTransformation, "Returns a 2d transformation used to find the new parameters of a point on the transformed surface. me->Transformed(T)->Value(U',V') is the same point as me->Value(U,V).Transformed(T) Where U',V' are obtained by transforming U,V with th 2d transformation returned by me->ParametricTransformation(T) This methods returns a scale centered on the U axis with T.ScaleFactor", py::arg("T"));
cls_Geom_CylindricalSurface.def("Bounds", [](Geom_CylindricalSurface &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "The CylindricalSurface is infinite in the V direction so V1 = Realfirst, V2 = RealLast from package Standard. U1 = 0 and U2 = 2*PI.", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Geom_CylindricalSurface.def("Coefficients", [](Geom_CylindricalSurface &self, Standard_Real & A1, Standard_Real & A2, Standard_Real & A3, Standard_Real & B1, Standard_Real & B2, Standard_Real & B3, Standard_Real & C1, Standard_Real & C2, Standard_Real & C3, Standard_Real & D){ self.Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); }, "Returns the coefficients of the implicit equation of the quadric in the absolute cartesian coordinate system : These coefficients are normalized. A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) + 2.(C1.X + C2.Y + C3.Z) + D = 0.0", py::arg("A1"), py::arg("A2"), py::arg("A3"), py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("D"));
cls_Geom_CylindricalSurface.def("Radius", (Standard_Real (Geom_CylindricalSurface::*)() const) &Geom_CylindricalSurface::Radius, "Returns the radius of this cylinder.");
cls_Geom_CylindricalSurface.def("IsUClosed", (Standard_Boolean (Geom_CylindricalSurface::*)() const) &Geom_CylindricalSurface::IsUClosed, "Returns True.");
cls_Geom_CylindricalSurface.def("IsVClosed", (Standard_Boolean (Geom_CylindricalSurface::*)() const) &Geom_CylindricalSurface::IsVClosed, "Returns False.");
cls_Geom_CylindricalSurface.def("IsUPeriodic", (Standard_Boolean (Geom_CylindricalSurface::*)() const) &Geom_CylindricalSurface::IsUPeriodic, "Returns True.");
cls_Geom_CylindricalSurface.def("IsVPeriodic", (Standard_Boolean (Geom_CylindricalSurface::*)() const) &Geom_CylindricalSurface::IsVPeriodic, "Returns False.");
cls_Geom_CylindricalSurface.def("UIso", (opencascade::handle<Geom_Curve> (Geom_CylindricalSurface::*)(const Standard_Real) const) &Geom_CylindricalSurface::UIso, "The UIso curve is a Line. The location point of this line is on the placement plane (XAxis, YAxis) of the surface. This line is parallel to the axis of symmetry of the surface.", py::arg("U"));
cls_Geom_CylindricalSurface.def("VIso", (opencascade::handle<Geom_Curve> (Geom_CylindricalSurface::*)(const Standard_Real) const) &Geom_CylindricalSurface::VIso, "The VIso curve is a circle. The start point of this circle (U = 0) is defined with the 'XAxis' of the surface. The center of the circle is on the symmetry axis.", py::arg("V"));
cls_Geom_CylindricalSurface.def("D0", (void (Geom_CylindricalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Geom_CylindricalSurface::D0, "Computes the point P (U, V) on the surface. P (U, V) = Loc + Radius * (cos (U) * XDir + sin (U) * YDir) + V * ZDir where Loc is the origin of the placement plane (XAxis, YAxis) XDir is the direction of the XAxis and YDir the direction of the YAxis.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Geom_CylindricalSurface.def("D1", (void (Geom_CylindricalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_CylindricalSurface::D1, "Computes the current point and the first derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Geom_CylindricalSurface.def("D2", (void (Geom_CylindricalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_CylindricalSurface::D2, "Computes the current point, the first and the second derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Geom_CylindricalSurface.def("D3", (void (Geom_CylindricalSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_CylindricalSurface::D3, "Computes the current point, the first, the second and the third derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Geom_CylindricalSurface.def("DN", (gp_Vec (Geom_CylindricalSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Geom_CylindricalSurface::DN, "Computes the derivative of order Nu in the direction u and Nv in the direction v. Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Geom_CylindricalSurface.def("Transform", (void (Geom_CylindricalSurface::*)(const gp_Trsf &)) &Geom_CylindricalSurface::Transform, "Applies the transformation T to this cylinder.", py::arg("T"));
cls_Geom_CylindricalSurface.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_CylindricalSurface::*)() const) &Geom_CylindricalSurface::Copy, "Creates a new object which is a copy of this cylinder.");
cls_Geom_CylindricalSurface.def_static("get_type_name_", (const char * (*)()) &Geom_CylindricalSurface::get_type_name, "None");
cls_Geom_CylindricalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_CylindricalSurface::get_type_descriptor, "None");
cls_Geom_CylindricalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_CylindricalSurface::*)() const) &Geom_CylindricalSurface::DynamicType, "None");

// Enums

}