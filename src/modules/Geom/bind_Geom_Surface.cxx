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
#include <Geom_Geometry.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf2d.hxx>
#include <Geom_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Surface(py::module &mod){

py::class_<Geom_Surface, opencascade::handle<Geom_Surface>, Geom_Geometry> cls_Geom_Surface(mod, "Geom_Surface", "Describes the common behavior of surfaces in 3D space. The Geom package provides many implementations of concrete derived surfaces, such as planes, cylinders, cones, spheres and tori, surfaces of linear extrusion, surfaces of revolution, Bezier and BSpline surfaces, and so on. The key characteristic of these surfaces is that they are parameterized. Geom_Surface demonstrates: - how to work with the parametric equation of a surface to compute the point of parameters (u, v), and, at this point, the 1st, 2nd ... Nth derivative, - how to find global information about a surface in each parametric direction (for example, level of continuity, whether the surface is closed, its periodicity, the bounds of the parameters and so on), and - how the parameters change when geometric transformations are applied to the surface, or the orientation is modified. Note that all surfaces must have a geometric continuity, and any surface is at least 'C0'. Generally, continuity is checked at construction time or when the curve is edited. Where this is not the case, the documentation makes this explicit. Warning The Geom package does not prevent the construction of surfaces with null areas, or surfaces which self-intersect.");

// Fields

// Methods
cls_Geom_Surface.def("UReverse", (void (Geom_Surface::*)()) &Geom_Surface::UReverse, "Reverses the U direction of parametrization of <me>. The bounds of the surface are not modified.");
cls_Geom_Surface.def("UReversed", (opencascade::handle<Geom_Surface> (Geom_Surface::*)() const) &Geom_Surface::UReversed, "Reverses the U direction of parametrization of <me>. The bounds of the surface are not modified. A copy of <me> is returned.");
cls_Geom_Surface.def("UReversedParameter", (Standard_Real (Geom_Surface::*)(const Standard_Real) const) &Geom_Surface::UReversedParameter, "Returns the parameter on the Ureversed surface for the point of parameter U on <me>.", py::arg("U"));
cls_Geom_Surface.def("VReverse", (void (Geom_Surface::*)()) &Geom_Surface::VReverse, "Reverses the V direction of parametrization of <me>. The bounds of the surface are not modified.");
cls_Geom_Surface.def("VReversed", (opencascade::handle<Geom_Surface> (Geom_Surface::*)() const) &Geom_Surface::VReversed, "Reverses the V direction of parametrization of <me>. The bounds of the surface are not modified. A copy of <me> is returned.");
cls_Geom_Surface.def("VReversedParameter", (Standard_Real (Geom_Surface::*)(const Standard_Real) const) &Geom_Surface::VReversedParameter, "Returns the parameter on the Vreversed surface for the point of parameter V on <me>.", py::arg("V"));
cls_Geom_Surface.def("TransformParameters", [](Geom_Surface &self, Standard_Real & U, Standard_Real & V, const gp_Trsf & T){ self.TransformParameters(U, V, T); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Computes the parameters on the transformed surface for the transform of the point of parameters U,V on <me>.", py::arg("U"), py::arg("V"), py::arg("T"));
cls_Geom_Surface.def("ParametricTransformation", (gp_GTrsf2d (Geom_Surface::*)(const gp_Trsf &) const) &Geom_Surface::ParametricTransformation, "Returns a 2d transformation used to find the new parameters of a point on the transformed surface.", py::arg("T"));
cls_Geom_Surface.def("Bounds", [](Geom_Surface &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "Returns the parametric bounds U1, U2, V1 and V2 of this surface. If the surface is infinite, this function can return a value equal to Precision::Infinite: instead of Standard_Real::LastReal.", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Geom_Surface.def("IsUClosed", (Standard_Boolean (Geom_Surface::*)() const) &Geom_Surface::IsUClosed, "Checks whether this surface is closed in the u parametric direction. Returns true if, in the u parametric direction: taking uFirst and uLast as the parametric bounds in the u parametric direction, for each parameter v, the distance between the points P(uFirst, v) and P(uLast, v) is less than or equal to gp::Resolution().");
cls_Geom_Surface.def("IsVClosed", (Standard_Boolean (Geom_Surface::*)() const) &Geom_Surface::IsVClosed, "Checks whether this surface is closed in the u parametric direction. Returns true if, in the v parametric direction: taking vFirst and vLast as the parametric bounds in the v parametric direction, for each parameter u, the distance between the points P(u, vFirst) and P(u, vLast) is less than or equal to gp::Resolution().");
cls_Geom_Surface.def("IsUPeriodic", (Standard_Boolean (Geom_Surface::*)() const) &Geom_Surface::IsUPeriodic, "Checks if this surface is periodic in the u parametric direction. Returns true if: - this surface is closed in the u parametric direction, and - there is a constant T such that the distance between the points P (u, v) and P (u + T, v) (or the points P (u, v) and P (u, v + T)) is less than or equal to gp::Resolution(). Note: T is the parametric period in the u parametric direction.");
cls_Geom_Surface.def("UPeriod", (Standard_Real (Geom_Surface::*)() const) &Geom_Surface::UPeriod, "Returns the period of this surface in the u parametric direction. raises if the surface is not uperiodic.");
cls_Geom_Surface.def("IsVPeriodic", (Standard_Boolean (Geom_Surface::*)() const) &Geom_Surface::IsVPeriodic, "Checks if this surface is periodic in the v parametric direction. Returns true if: - this surface is closed in the v parametric direction, and - there is a constant T such that the distance between the points P (u, v) and P (u + T, v) (or the points P (u, v) and P (u, v + T)) is less than or equal to gp::Resolution(). Note: T is the parametric period in the v parametric direction.");
cls_Geom_Surface.def("VPeriod", (Standard_Real (Geom_Surface::*)() const) &Geom_Surface::VPeriod, "Returns the period of this surface in the v parametric direction. raises if the surface is not vperiodic.");
cls_Geom_Surface.def("UIso", (opencascade::handle<Geom_Curve> (Geom_Surface::*)(const Standard_Real) const) &Geom_Surface::UIso, "Computes the U isoparametric curve.", py::arg("U"));
cls_Geom_Surface.def("VIso", (opencascade::handle<Geom_Curve> (Geom_Surface::*)(const Standard_Real) const) &Geom_Surface::VIso, "Computes the V isoparametric curve.", py::arg("V"));
cls_Geom_Surface.def("Continuity", (GeomAbs_Shape (Geom_Surface::*)() const) &Geom_Surface::Continuity, "Returns the Global Continuity of the surface in direction U and V : C0 : only geometric continuity, C1 : continuity of the first derivative all along the surface, C2 : continuity of the second derivative all along the surface, C3 : continuity of the third derivative all along the surface, G1 : tangency continuity all along the surface, G2 : curvature continuity all along the surface, CN : the order of continuity is infinite. Example : If the surface is C1 in the V parametric direction and C2 in the U parametric direction Shape = C1.");
cls_Geom_Surface.def("IsCNu", (Standard_Boolean (Geom_Surface::*)(const Standard_Integer) const) &Geom_Surface::IsCNu, "Returns the order of continuity of the surface in the U parametric direction. Raised if N < 0.", py::arg("N"));
cls_Geom_Surface.def("IsCNv", (Standard_Boolean (Geom_Surface::*)(const Standard_Integer) const) &Geom_Surface::IsCNv, "Returns the order of continuity of the surface in the V parametric direction. Raised if N < 0.", py::arg("N"));
cls_Geom_Surface.def("D0", (void (Geom_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Geom_Surface::D0, "Computes the point of parameter U,V on the surface.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Geom_Surface.def("D1", (void (Geom_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_Surface::D1, "Computes the point P and the first derivatives in the directions U and V at this point. Raised if the continuity of the surface is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Geom_Surface.def("D2", (void (Geom_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_Surface::D2, "Computes the point P, the first and the second derivatives in the directions U and V at this point. Raised if the continuity of the surface is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Geom_Surface.def("D3", (void (Geom_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_Surface::D3, "Computes the point P, the first,the second and the third derivatives in the directions U and V at this point. Raised if the continuity of the surface is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Geom_Surface.def("DN", (gp_Vec (Geom_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Geom_Surface::DN, "---Purpose ; Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V).", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Geom_Surface.def("Value", (gp_Pnt (Geom_Surface::*)(const Standard_Real, const Standard_Real) const) &Geom_Surface::Value, "Computes the point of parameter U on the surface.", py::arg("U"), py::arg("V"));
cls_Geom_Surface.def_static("get_type_name_", (const char * (*)()) &Geom_Surface::get_type_name, "None");
cls_Geom_Surface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Surface::get_type_descriptor, "None");
cls_Geom_Surface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Surface::*)() const) &Geom_Surface::DynamicType, "None");

// Enums

}