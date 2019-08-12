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
#include <Blend_SurfRstFunction.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor2d_HCurve2d.hxx>
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
#include <TColStd_Array1OfReal.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Blend_Point.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
#include <Convert_ParameterisationType.hxx>
#include <BRepBlend_SurfRstEvolRad.hxx>

void bind_BRepBlend_SurfRstEvolRad(py::module &mod){

py::class_<BRepBlend_SurfRstEvolRad, std::unique_ptr<BRepBlend_SurfRstEvolRad, Deleter<BRepBlend_SurfRstEvolRad>>, Blend_SurfRstFunction> cls_BRepBlend_SurfRstEvolRad(mod, "BRepBlend_SurfRstEvolRad", "Function to approximate by AppSurface for Edge/Face and evolutif radius");

// Constructors
cls_BRepBlend_SurfRstEvolRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("Surf"), py::arg("SurfRst"), py::arg("Rst"), py::arg("CGuide"), py::arg("Evol"));

// Fields

// Methods
// cls_BRepBlend_SurfRstEvolRad.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfRstEvolRad::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstEvolRad.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfRstEvolRad::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstEvolRad.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfRstEvolRad::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstEvolRad.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfRstEvolRad::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstEvolRad.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfRstEvolRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfRstEvolRad.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfRstEvolRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfRstEvolRad.def("NbVariables", (Standard_Integer (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::NbVariables, "Returns 3.");
cls_BRepBlend_SurfRstEvolRad.def("NbEquations", (Standard_Integer (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::NbEquations, "Returns 3.");
cls_BRepBlend_SurfRstEvolRad.def("Value", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const math_Vector &, math_Vector &)) &BRepBlend_SurfRstEvolRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_SurfRstEvolRad.def("Derivatives", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const math_Vector &, math_Matrix &)) &BRepBlend_SurfRstEvolRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_SurfRstEvolRad.def("Values", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_SurfRstEvolRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_SurfRstEvolRad.def("Set", (void (BRepBlend_SurfRstEvolRad::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_SurfRstEvolRad::Set, "None", py::arg("SurfRef"), py::arg("RstRef"));
cls_BRepBlend_SurfRstEvolRad.def("Set", (void (BRepBlend_SurfRstEvolRad::*)(const Standard_Real)) &BRepBlend_SurfRstEvolRad::Set, "None", py::arg("Param"));
cls_BRepBlend_SurfRstEvolRad.def("Set", (void (BRepBlend_SurfRstEvolRad::*)(const Standard_Real, const Standard_Real)) &BRepBlend_SurfRstEvolRad::Set, "Sets the bounds of the parametric interval on the guide line. This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_BRepBlend_SurfRstEvolRad.def("GetTolerance", (void (BRepBlend_SurfRstEvolRad::*)(math_Vector &, const Standard_Real) const) &BRepBlend_SurfRstEvolRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_SurfRstEvolRad.def("GetBounds", (void (BRepBlend_SurfRstEvolRad::*)(math_Vector &, math_Vector &) const) &BRepBlend_SurfRstEvolRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_SurfRstEvolRad.def("IsSolution", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const math_Vector &, const Standard_Real)) &BRepBlend_SurfRstEvolRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_SurfRstEvolRad.def("GetMinimalDistance", (Standard_Real (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_SurfRstEvolRad.def("PointOnS", (const gp_Pnt & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::PointOnS, "None");
cls_BRepBlend_SurfRstEvolRad.def("PointOnRst", (const gp_Pnt & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::PointOnRst, "None");
cls_BRepBlend_SurfRstEvolRad.def("Pnt2dOnS", (const gp_Pnt2d & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::Pnt2dOnS, "Returns U,V coordinates of the point on the surface.");
cls_BRepBlend_SurfRstEvolRad.def("Pnt2dOnRst", (const gp_Pnt2d & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::Pnt2dOnRst, "Returns U,V coordinates of the point on the curve on surface.");
cls_BRepBlend_SurfRstEvolRad.def("ParameterOnRst", (Standard_Real (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::ParameterOnRst, "Returns parameter of the point on the curve.");
cls_BRepBlend_SurfRstEvolRad.def("IsTangencyPoint", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::IsTangencyPoint, "None");
cls_BRepBlend_SurfRstEvolRad.def("TangentOnS", (const gp_Vec & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::TangentOnS, "None");
cls_BRepBlend_SurfRstEvolRad.def("Tangent2dOnS", (const gp_Vec2d & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::Tangent2dOnS, "None");
cls_BRepBlend_SurfRstEvolRad.def("TangentOnRst", (const gp_Vec & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::TangentOnRst, "None");
cls_BRepBlend_SurfRstEvolRad.def("Tangent2dOnRst", (const gp_Vec2d & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::Tangent2dOnRst, "None");
cls_BRepBlend_SurfRstEvolRad.def("Decroch", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const math_Vector &, gp_Vec &, gp_Vec &) const) &BRepBlend_SurfRstEvolRad::Decroch, "Permet d ' implementer un critere de decrochage specifique a la fonction.", py::arg("Sol"), py::arg("NS"), py::arg("TgS"));
cls_BRepBlend_SurfRstEvolRad.def("Set", (void (BRepBlend_SurfRstEvolRad::*)(const Standard_Integer)) &BRepBlend_SurfRstEvolRad::Set, "None", py::arg("Choix"));
cls_BRepBlend_SurfRstEvolRad.def("Set", (void (BRepBlend_SurfRstEvolRad::*)(const BlendFunc_SectionShape)) &BRepBlend_SurfRstEvolRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_SurfRstEvolRad.def("Section", [](BRepBlend_SurfRstEvolRad &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, const Standard_Real W, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, W, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_SurfRstEvolRad.def("IsRational", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_SurfRstEvolRad.def("GetSectionSize", (Standard_Real (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_SurfRstEvolRad.def("GetMinimalWeight", (void (BRepBlend_SurfRstEvolRad::*)(TColStd_Array1OfReal &) const) &BRepBlend_SurfRstEvolRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_SurfRstEvolRad.def("NbIntervals", (Standard_Integer (BRepBlend_SurfRstEvolRad::*)(const GeomAbs_Shape) const) &BRepBlend_SurfRstEvolRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_SurfRstEvolRad.def("Intervals", (void (BRepBlend_SurfRstEvolRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepBlend_SurfRstEvolRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>. The array must provide enough room to accomodate for the parameters. i.e. T.Length() > NbIntervals()", py::arg("T"), py::arg("S"));
cls_BRepBlend_SurfRstEvolRad.def("GetShape", [](BRepBlend_SurfRstEvolRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_SurfRstEvolRad.def("GetTolerance", (void (BRepBlend_SurfRstEvolRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BRepBlend_SurfRstEvolRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_SurfRstEvolRad.def("Knots", (void (BRepBlend_SurfRstEvolRad::*)(TColStd_Array1OfReal &)) &BRepBlend_SurfRstEvolRad::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_SurfRstEvolRad.def("Mults", (void (BRepBlend_SurfRstEvolRad::*)(TColStd_Array1OfInteger &)) &BRepBlend_SurfRstEvolRad::Mults, "None", py::arg("TMults"));
cls_BRepBlend_SurfRstEvolRad.def("Section", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstEvolRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_SurfRstEvolRad.def("Section", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstEvolRad::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_SurfRstEvolRad.def("Section", (void (BRepBlend_SurfRstEvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstEvolRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_SurfRstEvolRad.def("Resolution", [](BRepBlend_SurfRstEvolRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// Enums

}