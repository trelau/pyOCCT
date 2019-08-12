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
#include <gp_Lin.hxx>
#include <Blend_Point.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <BlendFunc_ChAsym.hxx>
#include <BRepBlend_ChAsym.hxx>

void bind_BRepBlend_ChAsym(py::module &mod){

py::class_<BlendFunc_ChAsym, std::unique_ptr<BlendFunc_ChAsym, Deleter<BlendFunc_ChAsym>>, Blend_Function> cls_BRepBlend_ChAsym(mod, "BRepBlend_ChAsym", "None", py::module_local());

// Constructors
cls_BRepBlend_ChAsym.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Fields

// Methods
// cls_BRepBlend_ChAsym.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_ChAsym::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_ChAsym.def_static("operator delete_", (void (*)(void *)) &BlendFunc_ChAsym::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_ChAsym.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_ChAsym::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_ChAsym.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_ChAsym::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_ChAsym.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_ChAsym::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_ChAsym.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_ChAsym::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_ChAsym.def("NbEquations", (Standard_Integer (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_ChAsym.def("Set", (void (BlendFunc_ChAsym::*)(const Standard_Real)) &BlendFunc_ChAsym::Set, "None", py::arg("Param"));
cls_BRepBlend_ChAsym.def("Set", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real)) &BlendFunc_ChAsym::Set, "None", py::arg("First"), py::arg("Last"));
cls_BRepBlend_ChAsym.def("GetTolerance", (void (BlendFunc_ChAsym::*)(math_Vector &, const Standard_Real) const) &BlendFunc_ChAsym::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_ChAsym.def("GetBounds", (void (BlendFunc_ChAsym::*)(math_Vector &, math_Vector &) const) &BlendFunc_ChAsym::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_ChAsym.def("IsSolution", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ChAsym::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_ChAsym.def("GetMinimalDistance", (Standard_Real (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_ChAsym.def("ComputeValues", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, const Standard_Integer, const Standard_Integer)) &BlendFunc_ChAsym::ComputeValues, "computes the values <F> of the derivatives for the variable <X> between DegF and DegL. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("DegF"), py::arg("DegL"));
cls_BRepBlend_ChAsym.def("Value", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, math_Vector &)) &BlendFunc_ChAsym::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_ChAsym.def("Derivatives", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ChAsym::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_ChAsym.def("Values", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ChAsym::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_ChAsym.def("PointOnS1", (const gp_Pnt & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::PointOnS1, "None");
cls_BRepBlend_ChAsym.def("PointOnS2", (const gp_Pnt & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::PointOnS2, "None");
cls_BRepBlend_ChAsym.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::IsTangencyPoint, "None");
cls_BRepBlend_ChAsym.def("TangentOnS1", (const gp_Vec & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::TangentOnS1, "None");
cls_BRepBlend_ChAsym.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::Tangent2dOnS1, "None");
cls_BRepBlend_ChAsym.def("TangentOnS2", (const gp_Vec & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::TangentOnS2, "None");
cls_BRepBlend_ChAsym.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::Tangent2dOnS2, "None");
cls_BRepBlend_ChAsym.def("TwistOnS1", (Standard_Boolean (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::TwistOnS1, "None");
cls_BRepBlend_ChAsym.def("TwistOnS2", (Standard_Boolean (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::TwistOnS2, "None");
cls_BRepBlend_ChAsym.def("Tangent", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BlendFunc_ChAsym::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
cls_BRepBlend_ChAsym.def("Section", [](BlendFunc_ChAsym &self, const Standard_Real Param, const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Lin & C){ self.Section(Param, U1, V1, U2, V2, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "Utile pour une visu rapide et approximative de la surface.", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_ChAsym.def("IsRational", (Standard_Boolean (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_ChAsym.def("GetSectionSize", (Standard_Real (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_ChAsym.def("GetMinimalWeight", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfReal &) const) &BlendFunc_ChAsym::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_ChAsym.def("NbIntervals", (Standard_Integer (BlendFunc_ChAsym::*)(const GeomAbs_Shape) const) &BlendFunc_ChAsym::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_ChAsym.def("Intervals", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_ChAsym::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepBlend_ChAsym.def("GetShape", [](BlendFunc_ChAsym &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_ChAsym.def("GetTolerance", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_ChAsym::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_ChAsym.def("Knots", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_ChAsym.def("Mults", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfInteger &)) &BlendFunc_ChAsym::Mults, "None", py::arg("TMults"));
cls_BRepBlend_ChAsym.def("Section", (void (BlendFunc_ChAsym::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_ChAsym.def("Section", (Standard_Boolean (BlendFunc_ChAsym::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_ChAsym.def("Section", (Standard_Boolean (BlendFunc_ChAsym::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_ChAsym.def("Resolution", [](BlendFunc_ChAsym &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
cls_BRepBlend_ChAsym.def("Set", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_ChAsym::Set, "Sets the distances and the angle.", py::arg("Dist1"), py::arg("Angle"), py::arg("Choix"));

// Enums

}