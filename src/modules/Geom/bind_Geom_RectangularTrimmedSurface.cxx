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
#include <Geom_BoundedSurface.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf2d.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <Standard_Type.hxx>

void bind_Geom_RectangularTrimmedSurface(py::module &mod){

py::class_<Geom_RectangularTrimmedSurface, opencascade::handle<Geom_RectangularTrimmedSurface>, Geom_BoundedSurface> cls_Geom_RectangularTrimmedSurface(mod, "Geom_RectangularTrimmedSurface", "Describes a portion of a surface (a patch) limited by two values of the u parameter in the u parametric direction, and two values of the v parameter in the v parametric direction. The domain of the trimmed surface must be within the domain of the surface being trimmed. The trimmed surface is defined by: - the basis surface, and - the values (umin, umax) and (vmin, vmax) which limit it in the u and v parametric directions. The trimmed surface is built from a copy of the basis surface. Therefore, when the basis surface is modified the trimmed surface is not changed. Consequently, the trimmed surface does not necessarily have the same orientation as the basis surface. Warning: The case of surface being trimmed is periodic and parametrics values are outside the domain is possible. But, domain of the trimmed surface can be translated by (n X) the period.");

// Constructors
cls_Geom_RectangularTrimmedSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Geom_RectangularTrimmedSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("USense"));
cls_Geom_RectangularTrimmedSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("USense"), py::arg("VSense"));
cls_Geom_RectangularTrimmedSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("Param1"), py::arg("Param2"), py::arg("UTrim"));
cls_Geom_RectangularTrimmedSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("Param1"), py::arg("Param2"), py::arg("UTrim"), py::arg("Sense"));

// Fields

// Methods
cls_Geom_RectangularTrimmedSurface.def("SetTrim", [](Geom_RectangularTrimmedSurface &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.SetTrim(a0, a1, a2, a3); });
cls_Geom_RectangularTrimmedSurface.def("SetTrim", [](Geom_RectangularTrimmedSurface &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Boolean a4) -> void { return self.SetTrim(a0, a1, a2, a3, a4); });
cls_Geom_RectangularTrimmedSurface.def("SetTrim", (void (Geom_RectangularTrimmedSurface::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &Geom_RectangularTrimmedSurface::SetTrim, "Modifies this patch by changing the trim values applied to the original surface The u parametric direction of this patch is oriented from U1 to U2. The v parametric direction of this patch is oriented from V1 to V2. USense and VSense are used for the construction only if the surface is periodic in the corresponding parametric direction, and define the available part of the surface; by default in this case, this patch has the same orientation as the basis surface. Raised if The BasisSurface is not periodic in the UDirection and U1 or U2 are out of the bounds of the BasisSurface. The BasisSurface is not periodic in the VDirection and V1 or V2 are out of the bounds of the BasisSurface. U1 = U2 or V1 = V2", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("USense"), py::arg("VSense"));
cls_Geom_RectangularTrimmedSurface.def("SetTrim", [](Geom_RectangularTrimmedSurface &self, const Standard_Real a0, const Standard_Real a1, const Standard_Boolean a2) -> void { return self.SetTrim(a0, a1, a2); });
cls_Geom_RectangularTrimmedSurface.def("SetTrim", (void (Geom_RectangularTrimmedSurface::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &Geom_RectangularTrimmedSurface::SetTrim, "Modifies this patch by changing the trim values applied to the original surface The basis surface is trimmed only in one parametric direction: if UTrim is true, the surface is trimmed in the u parametric direction; if it is false, it is trimmed in the v parametric direction. In the 'trimmed' direction, this patch is oriented from Param1 to Param2. If the basis surface is periodic in the 'trimmed' direction, Sense defines its available part. By default in this case, this patch has the same orientation as the basis surface in this parametric direction. If the basis surface is closed or periodic in the other parametric direction (i.e. not the 'trimmed' direction), this patch has the same characteristics as the basis surface in that parametric direction. Raised if The BasisSurface is not periodic in the considered direction and Param1 or Param2 are out of the bounds of the BasisSurface. Param1 = Param2", py::arg("Param1"), py::arg("Param2"), py::arg("UTrim"), py::arg("Sense"));
cls_Geom_RectangularTrimmedSurface.def("BasisSurface", (opencascade::handle<Geom_Surface> (Geom_RectangularTrimmedSurface::*)() const) &Geom_RectangularTrimmedSurface::BasisSurface, "Returns the Basis surface of <me>.");
cls_Geom_RectangularTrimmedSurface.def("UReverse", (void (Geom_RectangularTrimmedSurface::*)()) &Geom_RectangularTrimmedSurface::UReverse, "Changes the orientation of this patch in the u parametric direction. The bounds of the surface are not changed, but the given parametric direction is reversed. Hence the orientation of the surface is reversed.");
cls_Geom_RectangularTrimmedSurface.def("UReversedParameter", (Standard_Real (Geom_RectangularTrimmedSurface::*)(const Standard_Real) const) &Geom_RectangularTrimmedSurface::UReversedParameter, "Computes the u parameter on the modified surface, produced by when reversing its u parametric direction, for any point of u parameter U on this patch.", py::arg("U"));
cls_Geom_RectangularTrimmedSurface.def("VReverse", (void (Geom_RectangularTrimmedSurface::*)()) &Geom_RectangularTrimmedSurface::VReverse, "Changes the orientation of this patch in the v parametric direction. The bounds of the surface are not changed, but the given parametric direction is reversed. Hence the orientation of the surface is reversed.");
cls_Geom_RectangularTrimmedSurface.def("VReversedParameter", (Standard_Real (Geom_RectangularTrimmedSurface::*)(const Standard_Real) const) &Geom_RectangularTrimmedSurface::VReversedParameter, "Computes the v parameter on the modified surface, produced by when reversing its v parametric direction, for any point of v parameter V on this patch.", py::arg("V"));
cls_Geom_RectangularTrimmedSurface.def("Bounds", [](Geom_RectangularTrimmedSurface &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "Returns the parametric bounds U1, U2, V1 and V2 of this patch.", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Geom_RectangularTrimmedSurface.def("Continuity", (GeomAbs_Shape (Geom_RectangularTrimmedSurface::*)() const) &Geom_RectangularTrimmedSurface::Continuity, "Returns the continuity of the surface : C0 : only geometric continuity, C1 : continuity of the first derivative all along the Surface, C2 : continuity of the second derivative all along the Surface, C3 : continuity of the third derivative all along the Surface, CN : the order of continuity is infinite.");
cls_Geom_RectangularTrimmedSurface.def("IsUClosed", (Standard_Boolean (Geom_RectangularTrimmedSurface::*)() const) &Geom_RectangularTrimmedSurface::IsUClosed, "Returns true if this patch is closed in the given parametric direction.");
cls_Geom_RectangularTrimmedSurface.def("IsVClosed", (Standard_Boolean (Geom_RectangularTrimmedSurface::*)() const) &Geom_RectangularTrimmedSurface::IsVClosed, "Returns true if this patch is closed in the given parametric direction.");
cls_Geom_RectangularTrimmedSurface.def("IsCNu", (Standard_Boolean (Geom_RectangularTrimmedSurface::*)(const Standard_Integer) const) &Geom_RectangularTrimmedSurface::IsCNu, "Returns true if the order of derivation in the U parametric direction is N. Raised if N < 0.", py::arg("N"));
cls_Geom_RectangularTrimmedSurface.def("IsCNv", (Standard_Boolean (Geom_RectangularTrimmedSurface::*)(const Standard_Integer) const) &Geom_RectangularTrimmedSurface::IsCNv, "Returns true if the order of derivation in the V parametric direction is N. Raised if N < 0.", py::arg("N"));
cls_Geom_RectangularTrimmedSurface.def("IsUPeriodic", (Standard_Boolean (Geom_RectangularTrimmedSurface::*)() const) &Geom_RectangularTrimmedSurface::IsUPeriodic, "Returns true if this patch is periodic and not trimmed in the given parametric direction.");
cls_Geom_RectangularTrimmedSurface.def("UPeriod", (Standard_Real (Geom_RectangularTrimmedSurface::*)() const) &Geom_RectangularTrimmedSurface::UPeriod, "Returns the period of this patch in the u parametric direction. raises if the surface is not uperiodic.");
cls_Geom_RectangularTrimmedSurface.def("IsVPeriodic", (Standard_Boolean (Geom_RectangularTrimmedSurface::*)() const) &Geom_RectangularTrimmedSurface::IsVPeriodic, "Returns true if this patch is periodic and not trimmed in the given parametric direction.");
cls_Geom_RectangularTrimmedSurface.def("VPeriod", (Standard_Real (Geom_RectangularTrimmedSurface::*)() const) &Geom_RectangularTrimmedSurface::VPeriod, "Returns the period of this patch in the v parametric direction. raises if the surface is not vperiodic. value and derivatives");
cls_Geom_RectangularTrimmedSurface.def("UIso", (opencascade::handle<Geom_Curve> (Geom_RectangularTrimmedSurface::*)(const Standard_Real) const) &Geom_RectangularTrimmedSurface::UIso, "computes the U isoparametric curve.", py::arg("U"));
cls_Geom_RectangularTrimmedSurface.def("VIso", (opencascade::handle<Geom_Curve> (Geom_RectangularTrimmedSurface::*)(const Standard_Real) const) &Geom_RectangularTrimmedSurface::VIso, "Computes the V isoparametric curve.", py::arg("V"));
cls_Geom_RectangularTrimmedSurface.def("D0", (void (Geom_RectangularTrimmedSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Geom_RectangularTrimmedSurface::D0, "Can be raised if the basis surface is an OffsetSurface.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Geom_RectangularTrimmedSurface.def("D1", (void (Geom_RectangularTrimmedSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_RectangularTrimmedSurface::D1, "The returned derivatives have the same orientation as the derivatives of the basis surface even if the trimmed surface has not the same parametric orientation. Warning! UndefinedDerivative raised if the continuity of the surface is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Geom_RectangularTrimmedSurface.def("D2", (void (Geom_RectangularTrimmedSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_RectangularTrimmedSurface::D2, "The returned derivatives have the same orientation as the derivatives of the basis surface even if the trimmed surface has not the same parametric orientation. Warning! UndefinedDerivative raised if the continuity of the surface is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Geom_RectangularTrimmedSurface.def("D3", (void (Geom_RectangularTrimmedSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_RectangularTrimmedSurface::D3, "The returned derivatives have the same orientation as the derivatives of the basis surface even if the trimmed surface has not the same parametric orientation. Warning UndefinedDerivative raised if the continuity of the surface is not C3.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Geom_RectangularTrimmedSurface.def("DN", (gp_Vec (Geom_RectangularTrimmedSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Geom_RectangularTrimmedSurface::DN, "The returned derivative has the same orientation as the derivative of the basis surface even if the trimmed surface has not the same parametric orientation. Warning! UndefinedDerivative raised if the continuity of the surface is not CNu in the U parametric direction and CNv in the V parametric direction. RangeError Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Geom_RectangularTrimmedSurface.def("Transform", (void (Geom_RectangularTrimmedSurface::*)(const gp_Trsf &)) &Geom_RectangularTrimmedSurface::Transform, "Applies the transformation T to this patch. Warning As a consequence, the basis surface included in the data structure of this patch is also modified.", py::arg("T"));
cls_Geom_RectangularTrimmedSurface.def("TransformParameters", [](Geom_RectangularTrimmedSurface &self, Standard_Real & U, Standard_Real & V, const gp_Trsf & T){ self.TransformParameters(U, V, T); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Computes the parameters on the transformed surface for the transform of the point of parameters U,V on <me>.", py::arg("U"), py::arg("V"), py::arg("T"));
cls_Geom_RectangularTrimmedSurface.def("ParametricTransformation", (gp_GTrsf2d (Geom_RectangularTrimmedSurface::*)(const gp_Trsf &) const) &Geom_RectangularTrimmedSurface::ParametricTransformation, "Returns a 2d transformation used to find the new parameters of a point on the transformed surface.", py::arg("T"));
cls_Geom_RectangularTrimmedSurface.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_RectangularTrimmedSurface::*)() const) &Geom_RectangularTrimmedSurface::Copy, "Creates a new object which is a copy of this patch.");
cls_Geom_RectangularTrimmedSurface.def_static("get_type_name_", (const char * (*)()) &Geom_RectangularTrimmedSurface::get_type_name, "None");
cls_Geom_RectangularTrimmedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_RectangularTrimmedSurface::get_type_descriptor, "None");
cls_Geom_RectangularTrimmedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_RectangularTrimmedSurface::*)() const) &Geom_RectangularTrimmedSurface::DynamicType, "None");

// Enums

}