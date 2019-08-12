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
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf2d.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_SurfaceOfLinearExtrusion.hxx>
#include <Standard_Type.hxx>
#include <GeomEvaluator_SurfaceOfExtrusion.hxx>

void bind_Geom_SurfaceOfLinearExtrusion(py::module &mod){

py::class_<Geom_SurfaceOfLinearExtrusion, opencascade::handle<Geom_SurfaceOfLinearExtrusion>, Geom_SweptSurface> cls_Geom_SurfaceOfLinearExtrusion(mod, "Geom_SurfaceOfLinearExtrusion", "Describes a surface of linear extrusion ('extruded surface'), e.g. a generalized cylinder. Such a surface is obtained by sweeping a curve (called the 'extruded curve' or 'basis') in a given direction (referred to as the 'direction of extrusion' and defined by a unit vector). The u parameter is along the extruded curve. The v parameter is along the direction of extrusion. The parameter range for the u parameter is defined by the reference curve. The parameter range for the v parameter is ] - infinity, + infinity [. The position of the curve gives the origin of the v parameter. The surface is 'CN' in the v parametric direction. The form of a surface of linear extrusion is generally a ruled surface (GeomAbs_RuledForm). It can be: - a cylindrical surface, if the extruded curve is a circle, or a trimmed circle, with an axis parallel to the direction of extrusion (GeomAbs_CylindricalForm), or - a planar surface, if the extruded curve is a line (GeomAbs_PlanarForm). Note: The surface of extrusion is built from a copy of the original basis curve, so the original curve is not modified when the surface is modified. Warning Degenerate surfaces are not detected. A degenerate surface is obtained, for example, when the extruded curve is a line and the direction of extrusion is parallel to that line.");

// Constructors
cls_Geom_SurfaceOfLinearExtrusion.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Dir &>(), py::arg("C"), py::arg("V"));

// Fields

// Methods
cls_Geom_SurfaceOfLinearExtrusion.def("SetDirection", (void (Geom_SurfaceOfLinearExtrusion::*)(const gp_Dir &)) &Geom_SurfaceOfLinearExtrusion::SetDirection, "Assigns V as the 'direction of extrusion' for this surface of linear extrusion.", py::arg("V"));
cls_Geom_SurfaceOfLinearExtrusion.def("SetBasisCurve", (void (Geom_SurfaceOfLinearExtrusion::*)(const opencascade::handle<Geom_Curve> &)) &Geom_SurfaceOfLinearExtrusion::SetBasisCurve, "Modifies this surface of linear extrusion by redefining its 'basis curve' (the 'extruded curve').", py::arg("C"));
cls_Geom_SurfaceOfLinearExtrusion.def("UReverse", (void (Geom_SurfaceOfLinearExtrusion::*)()) &Geom_SurfaceOfLinearExtrusion::UReverse, "Changes the orientation of this surface of linear extrusion in the u parametric direction. The bounds of the surface are not changed, but the given parametric direction is reversed. Hence the orientation of the surface is reversed. In the case of a surface of linear extrusion: - UReverse reverses the basis curve, and - VReverse reverses the direction of linear extrusion.");
cls_Geom_SurfaceOfLinearExtrusion.def("UReversedParameter", (Standard_Real (Geom_SurfaceOfLinearExtrusion::*)(const Standard_Real) const) &Geom_SurfaceOfLinearExtrusion::UReversedParameter, "Computes the u parameter on the modified surface, produced by reversing its u parametric direction, for any point of u parameter U on this surface of linear extrusion. In the case of an extruded surface: - UReverseParameter returns the reversed parameter given by the function ReversedParameter called with U on the basis curve,", py::arg("U"));
cls_Geom_SurfaceOfLinearExtrusion.def("VReverse", (void (Geom_SurfaceOfLinearExtrusion::*)()) &Geom_SurfaceOfLinearExtrusion::VReverse, "Changes the orientation of this surface of linear extrusion in the v parametric direction. The bounds of the surface are not changed, but the given parametric direction is reversed. Hence the orientation of the surface is reversed. In the case of a surface of linear extrusion: - UReverse reverses the basis curve, and - VReverse reverses the direction of linear extrusion.");
cls_Geom_SurfaceOfLinearExtrusion.def("VReversedParameter", (Standard_Real (Geom_SurfaceOfLinearExtrusion::*)(const Standard_Real) const) &Geom_SurfaceOfLinearExtrusion::VReversedParameter, "Computes the v parameter on the modified surface, produced by reversing its u v parametric direction, for any point of v parameter V on this surface of linear extrusion. In the case of an extruded surface VReverse returns -V.", py::arg("V"));
cls_Geom_SurfaceOfLinearExtrusion.def("Bounds", [](Geom_SurfaceOfLinearExtrusion &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "Returns the parametric bounds U1, U2, V1 and V2 of this surface of linear extrusion. A surface of linear extrusion is infinite in the v parametric direction, so: - V1 = Standard_Real::RealFirst() - V2 = Standard_Real::RealLast().", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Geom_SurfaceOfLinearExtrusion.def("IsUClosed", (Standard_Boolean (Geom_SurfaceOfLinearExtrusion::*)() const) &Geom_SurfaceOfLinearExtrusion::IsUClosed, "IsUClosed returns true if the 'basis curve' of this surface of linear extrusion is closed.");
cls_Geom_SurfaceOfLinearExtrusion.def("IsVClosed", (Standard_Boolean (Geom_SurfaceOfLinearExtrusion::*)() const) &Geom_SurfaceOfLinearExtrusion::IsVClosed, "IsVClosed always returns false.");
cls_Geom_SurfaceOfLinearExtrusion.def("IsCNu", (Standard_Boolean (Geom_SurfaceOfLinearExtrusion::*)(const Standard_Integer) const) &Geom_SurfaceOfLinearExtrusion::IsCNu, "IsCNu returns true if the degree of continuity for the 'basis curve' of this surface of linear extrusion is at least N. Raises RangeError if N < 0.", py::arg("N"));
cls_Geom_SurfaceOfLinearExtrusion.def("IsCNv", (Standard_Boolean (Geom_SurfaceOfLinearExtrusion::*)(const Standard_Integer) const) &Geom_SurfaceOfLinearExtrusion::IsCNv, "IsCNv always returns true.", py::arg("N"));
cls_Geom_SurfaceOfLinearExtrusion.def("IsUPeriodic", (Standard_Boolean (Geom_SurfaceOfLinearExtrusion::*)() const) &Geom_SurfaceOfLinearExtrusion::IsUPeriodic, "IsUPeriodic returns true if the 'basis curve' of this surface of linear extrusion is periodic.");
cls_Geom_SurfaceOfLinearExtrusion.def("IsVPeriodic", (Standard_Boolean (Geom_SurfaceOfLinearExtrusion::*)() const) &Geom_SurfaceOfLinearExtrusion::IsVPeriodic, "IsVPeriodic always returns false.");
cls_Geom_SurfaceOfLinearExtrusion.def("UIso", (opencascade::handle<Geom_Curve> (Geom_SurfaceOfLinearExtrusion::*)(const Standard_Real) const) &Geom_SurfaceOfLinearExtrusion::UIso, "Computes the U isoparametric curve of this surface of linear extrusion. This is the line parallel to the direction of extrusion, passing through the point of parameter U of the basis curve.", py::arg("U"));
cls_Geom_SurfaceOfLinearExtrusion.def("VIso", (opencascade::handle<Geom_Curve> (Geom_SurfaceOfLinearExtrusion::*)(const Standard_Real) const) &Geom_SurfaceOfLinearExtrusion::VIso, "Computes the V isoparametric curve of this surface of linear extrusion. This curve is obtained by translating the extruded curve in the direction of extrusion, with the magnitude V.", py::arg("V"));
cls_Geom_SurfaceOfLinearExtrusion.def("D0", (void (Geom_SurfaceOfLinearExtrusion::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Geom_SurfaceOfLinearExtrusion::D0, "Computes the point P (U, V) on the surface. The parameter U is the parameter on the extruded curve. The parametrization V is a linear parametrization, and the direction of parametrization is the direction of extrusion. If the point is on the extruded curve, V = 0.0", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Geom_SurfaceOfLinearExtrusion.def("D1", (void (Geom_SurfaceOfLinearExtrusion::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_SurfaceOfLinearExtrusion::D1, "Computes the current point and the first derivatives in the directions U and V. Raises UndefinedDerivative if the continuity of the surface is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Geom_SurfaceOfLinearExtrusion.def("D2", (void (Geom_SurfaceOfLinearExtrusion::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_SurfaceOfLinearExtrusion::D2, "--- Purpose ; Computes the current point, the first and the second derivatives in the directions U and V. Raises UndefinedDerivative if the continuity of the surface is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Geom_SurfaceOfLinearExtrusion.def("D3", (void (Geom_SurfaceOfLinearExtrusion::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_SurfaceOfLinearExtrusion::D3, "Computes the current point, the first,the second and the third derivatives in the directions U and V. Raises UndefinedDerivative if the continuity of the surface is not C3.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Geom_SurfaceOfLinearExtrusion.def("DN", (gp_Vec (Geom_SurfaceOfLinearExtrusion::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Geom_SurfaceOfLinearExtrusion::DN, "Computes the derivative of order Nu in the direction u and Nv in the direction v. Raises UndefinedDerivative if the continuity of the surface is not CNu in the u direction and CNv in the v direction. Raises RangeError if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Geom_SurfaceOfLinearExtrusion.def("Transform", (void (Geom_SurfaceOfLinearExtrusion::*)(const gp_Trsf &)) &Geom_SurfaceOfLinearExtrusion::Transform, "Applies the transformation T to this surface of linear extrusion.", py::arg("T"));
cls_Geom_SurfaceOfLinearExtrusion.def("TransformParameters", [](Geom_SurfaceOfLinearExtrusion &self, Standard_Real & U, Standard_Real & V, const gp_Trsf & T){ self.TransformParameters(U, V, T); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Computes the parameters on the transformed surface for the transform of the point of parameters U,V on <me>.", py::arg("U"), py::arg("V"), py::arg("T"));
cls_Geom_SurfaceOfLinearExtrusion.def("ParametricTransformation", (gp_GTrsf2d (Geom_SurfaceOfLinearExtrusion::*)(const gp_Trsf &) const) &Geom_SurfaceOfLinearExtrusion::ParametricTransformation, "Returns a 2d transformation used to find the new parameters of a point on the transformed surface.", py::arg("T"));
cls_Geom_SurfaceOfLinearExtrusion.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_SurfaceOfLinearExtrusion::*)() const) &Geom_SurfaceOfLinearExtrusion::Copy, "Creates a new object which is a copy of this surface of linear extrusion.");
cls_Geom_SurfaceOfLinearExtrusion.def_static("get_type_name_", (const char * (*)()) &Geom_SurfaceOfLinearExtrusion::get_type_name, "None");
cls_Geom_SurfaceOfLinearExtrusion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_SurfaceOfLinearExtrusion::get_type_descriptor, "None");
cls_Geom_SurfaceOfLinearExtrusion.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_SurfaceOfLinearExtrusion::*)() const) &Geom_SurfaceOfLinearExtrusion::DynamicType, "None");

// Enums

}