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
#include <Geom_SweptSurface.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <gp_Ax1.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf2d.hxx>
#include <gp_Vec.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_SurfaceOfRevolution.hxx>
#include <Standard_Type.hxx>
#include <GeomEvaluator_SurfaceOfRevolution.hxx>

void bind_Geom_SurfaceOfRevolution(py::module &mod){

py::class_<Geom_SurfaceOfRevolution, opencascade::handle<Geom_SurfaceOfRevolution>, Geom_SweptSurface> cls_Geom_SurfaceOfRevolution(mod, "Geom_SurfaceOfRevolution", "Describes a surface of revolution (revolved surface). Such a surface is obtained by rotating a curve (called the 'meridian') through a complete revolution about an axis (referred to as the 'axis of revolution'). The curve and the axis must be in the same plane (the 'reference plane' of the surface). Rotation around the axis of revolution in the trigonometric sense defines the u parametric direction. So the u parameter is an angle, and its origin is given by the position of the meridian on the surface. The parametric range for the u parameter is: [ 0, 2.*Pi ] The v parameter is that of the meridian. Note: A surface of revolution is built from a copy of the original meridian. As a result the original meridian is not modified when the surface is modified. The form of a surface of revolution is typically a general revolution surface (GeomAbs_RevolutionForm). It can be: - a conical surface, if the meridian is a line or a trimmed line (GeomAbs_ConicalForm), - a cylindrical surface, if the meridian is a line or a trimmed line parallel to the axis of revolution (GeomAbs_CylindricalForm), - a planar surface if the meridian is a line or a trimmed line perpendicular to the axis of revolution of the surface (GeomAbs_PlanarForm), - a toroidal surface, if the meridian is a circle or a trimmed circle (GeomAbs_ToroidalForm), or - a spherical surface, if the meridian is a circle, the center of which is located on the axis of the revolved surface (GeomAbs_SphericalForm). Warning Be careful not to construct a surface of revolution where the curve and the axis or revolution are not defined in the same plane. If you do not have a correct configuration, you can correct your initial curve, using a cylindrical projection in the reference plane.");

// Constructors
cls_Geom_SurfaceOfRevolution.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Ax1 &>(), py::arg("C"), py::arg("A1"));

// Fields

// Methods
cls_Geom_SurfaceOfRevolution.def("SetAxis", (void (Geom_SurfaceOfRevolution::*)(const gp_Ax1 &)) &Geom_SurfaceOfRevolution::SetAxis, "Changes the axis of revolution. Warnings : It is not checked that the axis is in the plane of the revolved curve.", py::arg("A1"));
cls_Geom_SurfaceOfRevolution.def("SetDirection", (void (Geom_SurfaceOfRevolution::*)(const gp_Dir &)) &Geom_SurfaceOfRevolution::SetDirection, "Changes the direction of the revolution axis. Warnings : It is not checked that the axis is in the plane of the revolved curve.", py::arg("V"));
cls_Geom_SurfaceOfRevolution.def("SetBasisCurve", (void (Geom_SurfaceOfRevolution::*)(const opencascade::handle<Geom_Curve> &)) &Geom_SurfaceOfRevolution::SetBasisCurve, "Changes the revolved curve of the surface. Warnings : It is not checked that the curve C is planar and that the surface axis is in the plane of the curve. It is not checked that the revolved curve C doesn't self-intersects.", py::arg("C"));
cls_Geom_SurfaceOfRevolution.def("SetLocation", (void (Geom_SurfaceOfRevolution::*)(const gp_Pnt &)) &Geom_SurfaceOfRevolution::SetLocation, "Changes the location point of the revolution axis. Warnings : It is not checked that the axis is in the plane of the revolved curve.", py::arg("P"));
cls_Geom_SurfaceOfRevolution.def("Axis", (gp_Ax1 (Geom_SurfaceOfRevolution::*)() const) &Geom_SurfaceOfRevolution::Axis, "Returns the revolution axis of the surface.");
cls_Geom_SurfaceOfRevolution.def("Location", (const gp_Pnt & (Geom_SurfaceOfRevolution::*)() const) &Geom_SurfaceOfRevolution::Location, "Returns the location point of the axis of revolution.");
cls_Geom_SurfaceOfRevolution.def("ReferencePlane", (gp_Ax2 (Geom_SurfaceOfRevolution::*)() const) &Geom_SurfaceOfRevolution::ReferencePlane, "Computes the position of the reference plane of the surface defined by the basis curve and the symmetry axis. The location point is the location point of the revolution's axis, the XDirection of the plane is given by the revolution's axis and the orientation of the normal to the plane is given by the sense of revolution.");
cls_Geom_SurfaceOfRevolution.def("UReverse", (void (Geom_SurfaceOfRevolution::*)()) &Geom_SurfaceOfRevolution::UReverse, "Changes the orientation of this surface of revolution in the u parametric direction. The bounds of the surface are not changed but the given parametric direction is reversed. Hence the orientation of the surface is reversed. As a consequence: - UReverse reverses the direction of the axis of revolution of this surface,");
cls_Geom_SurfaceOfRevolution.def("UReversedParameter", (Standard_Real (Geom_SurfaceOfRevolution::*)(const Standard_Real) const) &Geom_SurfaceOfRevolution::UReversedParameter, "Computes the u parameter on the modified surface, when reversing its u parametric direction, for any point of u parameter U on this surface of revolution. In the case of a revolved surface: - UReversedParameter returns 2.*Pi - U", py::arg("U"));
cls_Geom_SurfaceOfRevolution.def("VReverse", (void (Geom_SurfaceOfRevolution::*)()) &Geom_SurfaceOfRevolution::VReverse, "Changes the orientation of this surface of revolution in the v parametric direction. The bounds of the surface are not changed but the given parametric direction is reversed. Hence the orientation of the surface is reversed. As a consequence: - VReverse reverses the meridian of this surface of revolution.");
cls_Geom_SurfaceOfRevolution.def("VReversedParameter", (Standard_Real (Geom_SurfaceOfRevolution::*)(const Standard_Real) const) &Geom_SurfaceOfRevolution::VReversedParameter, "Computes the v parameter on the modified surface, when reversing its v parametric direction, for any point of v parameter V on this surface of revolution. In the case of a revolved surface: - VReversedParameter returns the reversed parameter given by the function ReversedParameter called with V on the meridian.", py::arg("V"));
cls_Geom_SurfaceOfRevolution.def("TransformParameters", [](Geom_SurfaceOfRevolution &self, Standard_Real & U, Standard_Real & V, const gp_Trsf & T){ self.TransformParameters(U, V, T); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Computes the parameters on the transformed surface for the transform of the point of parameters U,V on <me>.", py::arg("U"), py::arg("V"), py::arg("T"));
cls_Geom_SurfaceOfRevolution.def("ParametricTransformation", (gp_GTrsf2d (Geom_SurfaceOfRevolution::*)(const gp_Trsf &) const) &Geom_SurfaceOfRevolution::ParametricTransformation, "Returns a 2d transformation used to find the new parameters of a point on the transformed surface.", py::arg("T"));
cls_Geom_SurfaceOfRevolution.def("Bounds", [](Geom_SurfaceOfRevolution &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "Returns the parametric bounds U1, U2 , V1 and V2 of this surface. A surface of revolution is always complete, so U1 = 0, U2 = 2*PI.", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Geom_SurfaceOfRevolution.def("IsUClosed", (Standard_Boolean (Geom_SurfaceOfRevolution::*)() const) &Geom_SurfaceOfRevolution::IsUClosed, "IsUClosed always returns true.");
cls_Geom_SurfaceOfRevolution.def("IsVClosed", (Standard_Boolean (Geom_SurfaceOfRevolution::*)() const) &Geom_SurfaceOfRevolution::IsVClosed, "IsVClosed returns true if the meridian of this surface of revolution is closed.");
cls_Geom_SurfaceOfRevolution.def("IsCNu", (Standard_Boolean (Geom_SurfaceOfRevolution::*)(const Standard_Integer) const) &Geom_SurfaceOfRevolution::IsCNu, "IsCNu always returns true.", py::arg("N"));
cls_Geom_SurfaceOfRevolution.def("IsCNv", (Standard_Boolean (Geom_SurfaceOfRevolution::*)(const Standard_Integer) const) &Geom_SurfaceOfRevolution::IsCNv, "IsCNv returns true if the degree of continuity of the meridian of this surface of revolution is at least N. Raised if N < 0.", py::arg("N"));
cls_Geom_SurfaceOfRevolution.def("IsUPeriodic", (Standard_Boolean (Geom_SurfaceOfRevolution::*)() const) &Geom_SurfaceOfRevolution::IsUPeriodic, "Returns True.");
cls_Geom_SurfaceOfRevolution.def("IsVPeriodic", (Standard_Boolean (Geom_SurfaceOfRevolution::*)() const) &Geom_SurfaceOfRevolution::IsVPeriodic, "IsVPeriodic returns true if the meridian of this surface of revolution is periodic.");
cls_Geom_SurfaceOfRevolution.def("UIso", (opencascade::handle<Geom_Curve> (Geom_SurfaceOfRevolution::*)(const Standard_Real) const) &Geom_SurfaceOfRevolution::UIso, "Computes the U isoparametric curve of this surface of revolution. It is the curve obtained by rotating the meridian through an angle U about the axis of revolution.", py::arg("U"));
cls_Geom_SurfaceOfRevolution.def("VIso", (opencascade::handle<Geom_Curve> (Geom_SurfaceOfRevolution::*)(const Standard_Real) const) &Geom_SurfaceOfRevolution::VIso, "Computes the U isoparametric curve of this surface of revolution. It is the curve obtained by rotating the meridian through an angle U about the axis of revolution.", py::arg("V"));
cls_Geom_SurfaceOfRevolution.def("D0", (void (Geom_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Geom_SurfaceOfRevolution::D0, "Computes the point P (U, V) on the surface. U is the angle of the rotation around the revolution axis. The direction of this axis gives the sense of rotation. V is the parameter of the revolved curve.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Geom_SurfaceOfRevolution.def("D1", (void (Geom_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_SurfaceOfRevolution::D1, "Computes the current point and the first derivatives in the directions U and V. Raised if the continuity of the surface is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Geom_SurfaceOfRevolution.def("D2", (void (Geom_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_SurfaceOfRevolution::D2, "Computes the current point, the first and the second derivatives in the directions U and V. Raised if the continuity of the surface is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Geom_SurfaceOfRevolution.def("D3", (void (Geom_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_SurfaceOfRevolution::D3, "Computes the current point, the first,the second and the third derivatives in the directions U and V. Raised if the continuity of the surface is not C3.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Geom_SurfaceOfRevolution.def("DN", (gp_Vec (Geom_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Geom_SurfaceOfRevolution::DN, "Computes the derivative of order Nu in the direction u and Nv in the direction v.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Geom_SurfaceOfRevolution.def("Transform", (void (Geom_SurfaceOfRevolution::*)(const gp_Trsf &)) &Geom_SurfaceOfRevolution::Transform, "Applies the transformation T to this surface of revolution.", py::arg("T"));
cls_Geom_SurfaceOfRevolution.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_SurfaceOfRevolution::*)() const) &Geom_SurfaceOfRevolution::Copy, "Creates a new object which is a copy of this surface of revolution.");
cls_Geom_SurfaceOfRevolution.def_static("get_type_name_", (const char * (*)()) &Geom_SurfaceOfRevolution::get_type_name, "None");
cls_Geom_SurfaceOfRevolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_SurfaceOfRevolution::get_type_descriptor, "None");
cls_Geom_SurfaceOfRevolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_SurfaceOfRevolution::*)() const) &Geom_SurfaceOfRevolution::DynamicType, "None");

// Enums

}