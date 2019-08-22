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
#include <Blend_CSFunction.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Law_Function.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <BlendFunc_SectionShape.hxx>
#include <gp_Circ.hxx>
#include <Blend_Point.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Convert_ParameterisationType.hxx>
#include <BlendFunc_CSCircular.hxx>

void bind_BlendFunc_CSCircular(py::module &mod){

py::class_<BlendFunc_CSCircular, Blend_CSFunction> cls_BlendFunc_CSCircular(mod, "BlendFunc_CSCircular", "None");

// Constructors
cls_BlendFunc_CSCircular.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S"), py::arg("C"), py::arg("CGuide"), py::arg("L"));

// Fields

// Methods
// cls_BlendFunc_CSCircular.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_CSCircular::operator new, "None", py::arg("theSize"));
// cls_BlendFunc_CSCircular.def_static("operator delete_", (void (*)(void *)) &BlendFunc_CSCircular::operator delete, "None", py::arg("theAddress"));
// cls_BlendFunc_CSCircular.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_CSCircular::operator new[], "None", py::arg("theSize"));
// cls_BlendFunc_CSCircular.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_CSCircular::operator delete[], "None", py::arg("theAddress"));
// cls_BlendFunc_CSCircular.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_CSCircular::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BlendFunc_CSCircular.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_CSCircular::operator delete, "None", py::arg(""), py::arg(""));
cls_BlendFunc_CSCircular.def("NbVariables", (Standard_Integer (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::NbVariables, "None");
cls_BlendFunc_CSCircular.def("NbEquations", (Standard_Integer (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::NbEquations, "returns the number of equations of the function (3).");
cls_BlendFunc_CSCircular.def("Value", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, math_Vector &)) &BlendFunc_CSCircular::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BlendFunc_CSCircular.def("Derivatives", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, math_Matrix &)) &BlendFunc_CSCircular::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BlendFunc_CSCircular.def("Values", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_CSCircular::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BlendFunc_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const Standard_Real)) &BlendFunc_CSCircular::Set, "None", py::arg("Param"));
cls_BlendFunc_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real)) &BlendFunc_CSCircular::Set, "None", py::arg("First"), py::arg("Last"));
cls_BlendFunc_CSCircular.def("GetTolerance", (void (BlendFunc_CSCircular::*)(math_Vector &, const Standard_Real) const) &BlendFunc_CSCircular::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BlendFunc_CSCircular.def("GetBounds", (void (BlendFunc_CSCircular::*)(math_Vector &, math_Vector &) const) &BlendFunc_CSCircular::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BlendFunc_CSCircular.def("IsSolution", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, const Standard_Real)) &BlendFunc_CSCircular::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BlendFunc_CSCircular.def("PointOnS", (const gp_Pnt & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::PointOnS, "None");
cls_BlendFunc_CSCircular.def("PointOnC", (const gp_Pnt & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::PointOnC, "None");
cls_BlendFunc_CSCircular.def("Pnt2d", (const gp_Pnt2d & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::Pnt2d, "Returns U,V coordinates of the point on the surface.");
cls_BlendFunc_CSCircular.def("ParameterOnC", (Standard_Real (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::ParameterOnC, "Returns parameter of the point on the curve.");
cls_BlendFunc_CSCircular.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::IsTangencyPoint, "None");
cls_BlendFunc_CSCircular.def("TangentOnS", (const gp_Vec & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::TangentOnS, "None");
cls_BlendFunc_CSCircular.def("Tangent2d", (const gp_Vec2d & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::Tangent2d, "None");
cls_BlendFunc_CSCircular.def("TangentOnC", (const gp_Vec & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::TangentOnC, "None");
cls_BlendFunc_CSCircular.def("Tangent", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &) const) &BlendFunc_CSCircular::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surface) at these points.", py::arg("U"), py::arg("V"), py::arg("TgS"), py::arg("NormS"));
cls_BlendFunc_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Integer)) &BlendFunc_CSCircular::Set, "None", py::arg("Radius"), py::arg("Choix"));
cls_BlendFunc_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const BlendFunc_SectionShape)) &BlendFunc_CSCircular::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BlendFunc_CSCircular.def("Section", [](BlendFunc_CSCircular &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, const Standard_Real W, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, W, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BlendFunc_CSCircular.def("Section", (Standard_Boolean (BlendFunc_CSCircular::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BlendFunc_CSCircular.def("GetSection", (Standard_Boolean (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &)) &BlendFunc_CSCircular::GetSection, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("tabP"), py::arg("tabV"));
cls_BlendFunc_CSCircular.def("IsRational", (Standard_Boolean (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::IsRational, "Returns if the section is rationnal");
cls_BlendFunc_CSCircular.def("GetSectionSize", (Standard_Real (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::GetSectionSize, "Returns the length of the maximum section");
cls_BlendFunc_CSCircular.def("GetMinimalWeight", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfReal &) const) &BlendFunc_CSCircular::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BlendFunc_CSCircular.def("NbIntervals", (Standard_Integer (BlendFunc_CSCircular::*)(const GeomAbs_Shape) const) &BlendFunc_CSCircular::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BlendFunc_CSCircular.def("Intervals", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_CSCircular::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BlendFunc_CSCircular.def("GetShape", [](BlendFunc_CSCircular &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BlendFunc_CSCircular.def("GetTolerance", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_CSCircular::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BlendFunc_CSCircular.def("Knots", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Knots, "None", py::arg("TKnots"));
cls_BlendFunc_CSCircular.def("Mults", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfInteger &)) &BlendFunc_CSCircular::Mults, "None", py::arg("TMults"));
cls_BlendFunc_CSCircular.def("Section", (Standard_Boolean (BlendFunc_CSCircular::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BlendFunc_CSCircular.def("Section", (void (BlendFunc_CSCircular::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BlendFunc_CSCircular.def("Resolution", [](BlendFunc_CSCircular &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// Enums

}