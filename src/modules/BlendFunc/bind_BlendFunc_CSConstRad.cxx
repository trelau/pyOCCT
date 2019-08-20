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
#include <BlendFunc_CSConstRad.hxx>

void bind_BlendFunc_CSConstRad(py::module &mod){

py::class_<BlendFunc_CSConstRad, std::unique_ptr<BlendFunc_CSConstRad>, Blend_CSFunction> cls_BlendFunc_CSConstRad(mod, "BlendFunc_CSConstRad", "None");

// Constructors
cls_BlendFunc_CSConstRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"), py::arg("CGuide"));

// Fields

// Methods
// cls_BlendFunc_CSConstRad.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_CSConstRad::operator new, "None", py::arg("theSize"));
// cls_BlendFunc_CSConstRad.def_static("operator delete_", (void (*)(void *)) &BlendFunc_CSConstRad::operator delete, "None", py::arg("theAddress"));
// cls_BlendFunc_CSConstRad.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_CSConstRad::operator new[], "None", py::arg("theSize"));
// cls_BlendFunc_CSConstRad.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_CSConstRad::operator delete[], "None", py::arg("theAddress"));
// cls_BlendFunc_CSConstRad.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_CSConstRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BlendFunc_CSConstRad.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_CSConstRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BlendFunc_CSConstRad.def("NbEquations", (Standard_Integer (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::NbEquations, "returns the number of equations of the function (3).");
cls_BlendFunc_CSConstRad.def("Value", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, math_Vector &)) &BlendFunc_CSConstRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BlendFunc_CSConstRad.def("Derivatives", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, math_Matrix &)) &BlendFunc_CSConstRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BlendFunc_CSConstRad.def("Values", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_CSConstRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BlendFunc_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const Standard_Real)) &BlendFunc_CSConstRad::Set, "None", py::arg("Param"));
cls_BlendFunc_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real)) &BlendFunc_CSConstRad::Set, "None", py::arg("First"), py::arg("Last"));
cls_BlendFunc_CSConstRad.def("GetTolerance", (void (BlendFunc_CSConstRad::*)(math_Vector &, const Standard_Real) const) &BlendFunc_CSConstRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BlendFunc_CSConstRad.def("GetBounds", (void (BlendFunc_CSConstRad::*)(math_Vector &, math_Vector &) const) &BlendFunc_CSConstRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BlendFunc_CSConstRad.def("IsSolution", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, const Standard_Real)) &BlendFunc_CSConstRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BlendFunc_CSConstRad.def("PointOnS", (const gp_Pnt & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::PointOnS, "None");
cls_BlendFunc_CSConstRad.def("PointOnC", (const gp_Pnt & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::PointOnC, "None");
cls_BlendFunc_CSConstRad.def("Pnt2d", (const gp_Pnt2d & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::Pnt2d, "Returns U,V coordinates of the point on the surface.");
cls_BlendFunc_CSConstRad.def("ParameterOnC", (Standard_Real (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::ParameterOnC, "Returns parameter of the point on the curve.");
cls_BlendFunc_CSConstRad.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::IsTangencyPoint, "None");
cls_BlendFunc_CSConstRad.def("TangentOnS", (const gp_Vec & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::TangentOnS, "None");
cls_BlendFunc_CSConstRad.def("Tangent2d", (const gp_Vec2d & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::Tangent2d, "None");
cls_BlendFunc_CSConstRad.def("TangentOnC", (const gp_Vec & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::TangentOnC, "None");
cls_BlendFunc_CSConstRad.def("Tangent", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &) const) &BlendFunc_CSConstRad::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surface) at these points.", py::arg("U"), py::arg("V"), py::arg("TgS"), py::arg("NormS"));
cls_BlendFunc_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Integer)) &BlendFunc_CSConstRad::Set, "None", py::arg("Radius"), py::arg("Choix"));
cls_BlendFunc_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const BlendFunc_SectionShape)) &BlendFunc_CSConstRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BlendFunc_CSConstRad.def("Section", [](BlendFunc_CSConstRad &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, const Standard_Real W, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, W, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BlendFunc_CSConstRad.def("Section", (Standard_Boolean (BlendFunc_CSConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BlendFunc_CSConstRad.def("GetSection", (Standard_Boolean (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &)) &BlendFunc_CSConstRad::GetSection, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("tabP"), py::arg("tabV"));
cls_BlendFunc_CSConstRad.def("IsRational", (Standard_Boolean (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::IsRational, "Returns if the section is rationnal");
cls_BlendFunc_CSConstRad.def("GetSectionSize", (Standard_Real (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::GetSectionSize, "Returns the length of the maximum section");
cls_BlendFunc_CSConstRad.def("GetMinimalWeight", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfReal &) const) &BlendFunc_CSConstRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BlendFunc_CSConstRad.def("NbIntervals", (Standard_Integer (BlendFunc_CSConstRad::*)(const GeomAbs_Shape) const) &BlendFunc_CSConstRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BlendFunc_CSConstRad.def("Intervals", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_CSConstRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>. The array must provide enough room to accomodate for the parameters. i.e. T.Length() > NbIntervals() raises OutOfRange from Standard", py::arg("T"), py::arg("S"));
cls_BlendFunc_CSConstRad.def("GetShape", [](BlendFunc_CSConstRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BlendFunc_CSConstRad.def("GetTolerance", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_CSConstRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BlendFunc_CSConstRad.def("Knots", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Knots, "None", py::arg("TKnots"));
cls_BlendFunc_CSConstRad.def("Mults", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfInteger &)) &BlendFunc_CSConstRad::Mults, "None", py::arg("TMults"));
cls_BlendFunc_CSConstRad.def("Section", (Standard_Boolean (BlendFunc_CSConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BlendFunc_CSConstRad.def("Section", (void (BlendFunc_CSConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BlendFunc_CSConstRad.def("Resolution", [](BlendFunc_CSConstRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// Enums

}