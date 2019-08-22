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
#include <Blend_Function.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Blend_Point.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <gp_Ax1.hxx>
#include <BlendFunc_Ruled.hxx>

void bind_BlendFunc_Ruled(py::module &mod){

py::class_<BlendFunc_Ruled, Blend_Function> cls_BlendFunc_Ruled(mod, "BlendFunc_Ruled", "None");

// Constructors
cls_BlendFunc_Ruled.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Fields

// Methods
// cls_BlendFunc_Ruled.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_Ruled::operator new, "None", py::arg("theSize"));
// cls_BlendFunc_Ruled.def_static("operator delete_", (void (*)(void *)) &BlendFunc_Ruled::operator delete, "None", py::arg("theAddress"));
// cls_BlendFunc_Ruled.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_Ruled::operator new[], "None", py::arg("theSize"));
// cls_BlendFunc_Ruled.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_Ruled::operator delete[], "None", py::arg("theAddress"));
// cls_BlendFunc_Ruled.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_Ruled::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BlendFunc_Ruled.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_Ruled::operator delete, "None", py::arg(""), py::arg(""));
cls_BlendFunc_Ruled.def("NbEquations", (Standard_Integer (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::NbEquations, "returns the number of equations of the function.");
cls_BlendFunc_Ruled.def("Value", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, math_Vector &)) &BlendFunc_Ruled::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BlendFunc_Ruled.def("Derivatives", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, math_Matrix &)) &BlendFunc_Ruled::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BlendFunc_Ruled.def("Values", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_Ruled::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BlendFunc_Ruled.def("Set", (void (BlendFunc_Ruled::*)(const Standard_Real)) &BlendFunc_Ruled::Set, "None", py::arg("Param"));
cls_BlendFunc_Ruled.def("Set", (void (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real)) &BlendFunc_Ruled::Set, "None", py::arg("First"), py::arg("Last"));
cls_BlendFunc_Ruled.def("GetTolerance", (void (BlendFunc_Ruled::*)(math_Vector &, const Standard_Real) const) &BlendFunc_Ruled::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BlendFunc_Ruled.def("GetBounds", (void (BlendFunc_Ruled::*)(math_Vector &, math_Vector &) const) &BlendFunc_Ruled::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BlendFunc_Ruled.def("IsSolution", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, const Standard_Real)) &BlendFunc_Ruled::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BlendFunc_Ruled.def("GetMinimalDistance", (Standard_Real (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BlendFunc_Ruled.def("PointOnS1", (const gp_Pnt & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::PointOnS1, "None");
cls_BlendFunc_Ruled.def("PointOnS2", (const gp_Pnt & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::PointOnS2, "None");
cls_BlendFunc_Ruled.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::IsTangencyPoint, "None");
cls_BlendFunc_Ruled.def("TangentOnS1", (const gp_Vec & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::TangentOnS1, "None");
cls_BlendFunc_Ruled.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::Tangent2dOnS1, "None");
cls_BlendFunc_Ruled.def("TangentOnS2", (const gp_Vec & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::TangentOnS2, "None");
cls_BlendFunc_Ruled.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::Tangent2dOnS2, "None");
cls_BlendFunc_Ruled.def("Tangent", (void (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BlendFunc_Ruled::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
cls_BlendFunc_Ruled.def("GetSection", (Standard_Boolean (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &)) &BlendFunc_Ruled::GetSection, "None", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("tabP"), py::arg("tabV"));
cls_BlendFunc_Ruled.def("IsRational", (Standard_Boolean (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::IsRational, "Returns False");
cls_BlendFunc_Ruled.def("GetSectionSize", (Standard_Real (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::GetSectionSize, "Returns the length of the maximum section");
cls_BlendFunc_Ruled.def("GetMinimalWeight", (void (BlendFunc_Ruled::*)(TColStd_Array1OfReal &) const) &BlendFunc_Ruled::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BlendFunc_Ruled.def("NbIntervals", (Standard_Integer (BlendFunc_Ruled::*)(const GeomAbs_Shape) const) &BlendFunc_Ruled::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BlendFunc_Ruled.def("Intervals", (void (BlendFunc_Ruled::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_Ruled::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BlendFunc_Ruled.def("GetShape", [](BlendFunc_Ruled &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BlendFunc_Ruled.def("GetTolerance", (void (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_Ruled::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BlendFunc_Ruled.def("Knots", (void (BlendFunc_Ruled::*)(TColStd_Array1OfReal &)) &BlendFunc_Ruled::Knots, "None", py::arg("TKnots"));
cls_BlendFunc_Ruled.def("Mults", (void (BlendFunc_Ruled::*)(TColStd_Array1OfInteger &)) &BlendFunc_Ruled::Mults, "None", py::arg("TMults"));
cls_BlendFunc_Ruled.def("Section", (Standard_Boolean (BlendFunc_Ruled::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Ruled::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BlendFunc_Ruled.def("Section", (Standard_Boolean (BlendFunc_Ruled::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Ruled::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BlendFunc_Ruled.def("Section", (void (BlendFunc_Ruled::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_Ruled::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BlendFunc_Ruled.def("AxeRot", (gp_Ax1 (BlendFunc_Ruled::*)(const Standard_Real)) &BlendFunc_Ruled::AxeRot, "None", py::arg("Prm"));
cls_BlendFunc_Ruled.def("Resolution", [](BlendFunc_Ruled &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// Enums

}