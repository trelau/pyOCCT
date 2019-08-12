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
#include <Geom_Surface.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_OsculatingSurface.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf2d.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_OffsetSurface.hxx>
#include <Standard_Type.hxx>
#include <GeomEvaluator_OffsetSurface.hxx>

void bind_Geom_OffsetSurface(py::module &mod){

py::class_<Geom_OffsetSurface, opencascade::handle<Geom_OffsetSurface>, Geom_Surface> cls_Geom_OffsetSurface(mod, "Geom_OffsetSurface", "Describes an offset surface in 3D space. An offset surface is defined by: - the basis surface to which it is parallel, and - the distance between the offset surface and its basis surface. A point on the offset surface is built by measuring the offset value along the normal vector at a point on the basis surface. This normal vector is given by the cross product D1u^D1v, where D1u and D1v are the vectors tangential to the basis surface in the u and v parametric directions at this point. The side of the basis surface on which the offset is measured depends on the sign of the offset value. A Geom_OffsetSurface surface can be self-intersecting, even if the basis surface does not self-intersect. The self-intersecting portions are not deleted at the time of construction. Warning There must be only one normal vector defined at any point on the basis surface. This must be verified by the user as no check is made at the time of construction to detect points with multiple possible normal directions (for example, the top of a conical surface).");

// Constructors
cls_Geom_OffsetSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("S"), py::arg("Offset"));
cls_Geom_OffsetSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("isNotCheckC0"));

// Fields

// Methods
cls_Geom_OffsetSurface.def("SetBasisSurface", [](Geom_OffsetSurface &self, const opencascade::handle<Geom_Surface> & a0) -> void { return self.SetBasisSurface(a0); });
cls_Geom_OffsetSurface.def("SetBasisSurface", (void (Geom_OffsetSurface::*)(const opencascade::handle<Geom_Surface> &, const Standard_Boolean)) &Geom_OffsetSurface::SetBasisSurface, "Raised if S is not at least C1. Warnings : No check is done to verify that a unique normal direction is defined at any point of the basis surface S. If isNotCheckC0 = TRUE checking if basis surface has C0-continuity is not made. Exceptions Standard_ConstructionError if the surface S is not at least 'C1' continuous.", py::arg("S"), py::arg("isNotCheckC0"));
cls_Geom_OffsetSurface.def("SetOffsetValue", (void (Geom_OffsetSurface::*)(const Standard_Real)) &Geom_OffsetSurface::SetOffsetValue, "Changes this offset surface by assigning D as the offset value.", py::arg("D"));
cls_Geom_OffsetSurface.def("Offset", (Standard_Real (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::Offset, "Returns the offset value of this offset surface.");
cls_Geom_OffsetSurface.def("BasisSurface", (const opencascade::handle<Geom_Surface> & (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::BasisSurface, "Returns the basis surface of this offset surface. Note: The basis surface can be an offset surface.");
cls_Geom_OffsetSurface.def("OsculatingSurface", (const opencascade::handle<Geom_OsculatingSurface> & (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::OsculatingSurface, "Returns osculating surface if base surface is B-spline or Bezier");
cls_Geom_OffsetSurface.def("UReverse", (void (Geom_OffsetSurface::*)()) &Geom_OffsetSurface::UReverse, "Changes the orientation of this offset surface in the u parametric direction. The bounds of the surface are not changed but the given parametric direction is reversed.");
cls_Geom_OffsetSurface.def("UReversedParameter", (Standard_Real (Geom_OffsetSurface::*)(const Standard_Real) const) &Geom_OffsetSurface::UReversedParameter, "Computes the u parameter on the modified surface, produced by reversing the u parametric direction of this offset surface, for any point of u parameter U on this offset surface.", py::arg("U"));
cls_Geom_OffsetSurface.def("VReverse", (void (Geom_OffsetSurface::*)()) &Geom_OffsetSurface::VReverse, "Changes the orientation of this offset surface in the v parametric direction. The bounds of the surface are not changed but the given parametric direction is reversed.");
cls_Geom_OffsetSurface.def("VReversedParameter", (Standard_Real (Geom_OffsetSurface::*)(const Standard_Real) const) &Geom_OffsetSurface::VReversedParameter, "Computes the v parameter on the modified surface, produced by reversing the or v parametric direction of this offset surface, for any point of v parameter V on this offset surface.", py::arg("V"));
cls_Geom_OffsetSurface.def("Bounds", [](Geom_OffsetSurface &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "Returns the parametric bounds U1, U2, V1 and V2 of this offset surface. If the surface is infinite, this function can return: - Standard_Real::RealFirst(), or - Standard_Real::RealLast().", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Geom_OffsetSurface.def("Continuity", (GeomAbs_Shape (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::Continuity, "This method returns the continuity of the basis surface - 1. Continuity of the Offset surface : C0 : only geometric continuity, C1 : continuity of the first derivative all along the Surface, C2 : continuity of the second derivative all along the Surface, C3 : continuity of the third derivative all along the Surface, CN : the order of continuity is infinite. Example : If the basis surface is C2 in the V direction and C3 in the U direction Shape = C1. Warnings : If the basis surface has a unique normal direction defined at any point this method gives the continuity of the offset surface otherwise the effective continuity can be lower than the continuity of the basis surface - 1.");
cls_Geom_OffsetSurface.def("IsCNu", (Standard_Boolean (Geom_OffsetSurface::*)(const Standard_Integer) const) &Geom_OffsetSurface::IsCNu, "This method answer True if the continuity of the basis surface is N + 1 in the U parametric direction. We suppose in this class that a unique normal is defined at any point on the basis surface. Raised if N <0.", py::arg("N"));
cls_Geom_OffsetSurface.def("IsCNv", (Standard_Boolean (Geom_OffsetSurface::*)(const Standard_Integer) const) &Geom_OffsetSurface::IsCNv, "This method answer True if the continuity of the basis surface is N + 1 in the V parametric direction. We suppose in this class that a unique normal is defined at any point on the basis surface. Raised if N <0.", py::arg("N"));
cls_Geom_OffsetSurface.def("IsUClosed", (Standard_Boolean (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::IsUClosed, "Checks whether this offset surface is closed in the u parametric direction. Returns true if, taking uFirst and uLast as the parametric bounds in the u parametric direction, the distance between the points P(uFirst,v) and P(uLast,v) is less than or equal to gp::Resolution() for each value of the parameter v.");
cls_Geom_OffsetSurface.def("IsVClosed", (Standard_Boolean (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::IsVClosed, "Checks whether this offset surface is closed in the u or v parametric direction. Returns true if taking vFirst and vLast as the parametric bounds in the v parametric direction, the distance between the points P(u,vFirst) and P(u,vLast) is less than or equal to gp::Resolution() for each value of the parameter u.");
cls_Geom_OffsetSurface.def("IsUPeriodic", (Standard_Boolean (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::IsUPeriodic, "Returns true if this offset surface is periodic in the u parametric direction, i.e. if the basis surface of this offset surface is periodic in this direction.");
cls_Geom_OffsetSurface.def("UPeriod", (Standard_Real (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::UPeriod, "Returns the period of this offset surface in the u parametric direction respectively, i.e. the period of the basis surface of this offset surface in this parametric direction. raises if the surface is not uperiodic.");
cls_Geom_OffsetSurface.def("IsVPeriodic", (Standard_Boolean (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::IsVPeriodic, "Returns true if this offset surface is periodic in the v parametric direction, i.e. if the basis surface of this offset surface is periodic in this direction.");
cls_Geom_OffsetSurface.def("VPeriod", (Standard_Real (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::VPeriod, "Returns the period of this offset surface in the v parametric direction respectively, i.e. the period of the basis surface of this offset surface in this parametric direction. raises if the surface is not vperiodic.");
cls_Geom_OffsetSurface.def("UIso", (opencascade::handle<Geom_Curve> (Geom_OffsetSurface::*)(const Standard_Real) const) &Geom_OffsetSurface::UIso, "Computes the U isoparametric curve.", py::arg("U"));
cls_Geom_OffsetSurface.def("VIso", (opencascade::handle<Geom_Curve> (Geom_OffsetSurface::*)(const Standard_Real) const) &Geom_OffsetSurface::VIso, "Computes the V isoparametric curve.", py::arg("V"));
cls_Geom_OffsetSurface.def("D0", (void (Geom_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Geom_OffsetSurface::D0, "P (U, V) = Pbasis + Offset * Ndir where Ndir = D1Ubasis ^ D1Vbasis / ||D1Ubasis ^ D1Vbasis|| is the normal direction of the basis surface. Pbasis, D1Ubasis, D1Vbasis are the point and the first derivatives on the basis surface. If Ndir is undefined this method computes an approched normal direction using the following limited development : Ndir = N0 + DNdir/DU + DNdir/DV + Eps with Eps->0 which requires to compute the second derivatives on the basis surface. If the normal direction cannot be approximate for this order of derivation the exception UndefinedValue is raised.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Geom_OffsetSurface.def("D1", (void (Geom_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_OffsetSurface::D1, "Raised if the continuity of the basis surface is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Geom_OffsetSurface.def("D2", (void (Geom_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_OffsetSurface::D2, "---Purpose ; Raised if the continuity of the basis surface is not C3.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Geom_OffsetSurface.def("D3", (void (Geom_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_OffsetSurface::D3, "Raised if the continuity of the basis surface is not C4.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Geom_OffsetSurface.def("DN", (gp_Vec (Geom_OffsetSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Geom_OffsetSurface::DN, "Computes the derivative of order Nu in the direction u and Nv in the direction v. ---Purpose ; Raised if the continuity of the basis surface is not CNu + 1 in the U direction and CNv + 1 in the V direction. Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Geom_OffsetSurface.def("Transform", (void (Geom_OffsetSurface::*)(const gp_Trsf &)) &Geom_OffsetSurface::Transform, "Applies the transformation T to this offset surface. Note: the basis surface is also modified.", py::arg("T"));
cls_Geom_OffsetSurface.def("TransformParameters", [](Geom_OffsetSurface &self, Standard_Real & U, Standard_Real & V, const gp_Trsf & T){ self.TransformParameters(U, V, T); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Computes the parameters on the transformed surface for the transform of the point of parameters U,V on <me>.", py::arg("U"), py::arg("V"), py::arg("T"));
cls_Geom_OffsetSurface.def("ParametricTransformation", (gp_GTrsf2d (Geom_OffsetSurface::*)(const gp_Trsf &) const) &Geom_OffsetSurface::ParametricTransformation, "Returns a 2d transformation used to find the new parameters of a point on the transformed surface.", py::arg("T"));
cls_Geom_OffsetSurface.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::Copy, "Creates a new object which is a copy of this offset surface.");
cls_Geom_OffsetSurface.def("Surface", (opencascade::handle<Geom_Surface> (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::Surface, "returns an equivalent surface of the offset surface when the basis surface is a canonic surface or a rectangular limited surface on canonic surface or if the offset is null.");
cls_Geom_OffsetSurface.def("UOsculatingSurface", [](Geom_OffsetSurface &self, const Standard_Real U, const Standard_Real V, Standard_Boolean & IsOpposite, opencascade::handle<Geom_BSplineSurface> & UOsculSurf){ Standard_Boolean rv = self.UOsculatingSurface(U, V, IsOpposite, UOsculSurf); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, IsOpposite); }, "if Standard_True, L is the local osculating surface along U at the point U,V. It means that DL/DU is collinear to DS/DU . If IsOpposite == Standard_True these vectors have opposite direction.", py::arg("U"), py::arg("V"), py::arg("IsOpposite"), py::arg("UOsculSurf"));
cls_Geom_OffsetSurface.def("VOsculatingSurface", [](Geom_OffsetSurface &self, const Standard_Real U, const Standard_Real V, Standard_Boolean & IsOpposite, opencascade::handle<Geom_BSplineSurface> & VOsculSurf){ Standard_Boolean rv = self.VOsculatingSurface(U, V, IsOpposite, VOsculSurf); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, IsOpposite); }, "if Standard_True, L is the local osculating surface along V at the point U,V. It means that DL/DV is collinear to DS/DV . If IsOpposite == Standard_True these vectors have opposite direction.", py::arg("U"), py::arg("V"), py::arg("IsOpposite"), py::arg("VOsculSurf"));
cls_Geom_OffsetSurface.def("GetBasisSurfContinuity", (GeomAbs_Shape (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::GetBasisSurfContinuity, "Returns continuity of the basis surface.");
cls_Geom_OffsetSurface.def_static("get_type_name_", (const char * (*)()) &Geom_OffsetSurface::get_type_name, "None");
cls_Geom_OffsetSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_OffsetSurface::get_type_descriptor, "None");
cls_Geom_OffsetSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_OffsetSurface::*)() const) &Geom_OffsetSurface::DynamicType, "None");

// Enums

}