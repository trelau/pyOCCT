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
#include <BRepBlend_SurfRstConstRad.hxx>

void bind_BRepBlend_SurfRstConstRad(py::module &mod){

py::class_<BRepBlend_SurfRstConstRad, std::unique_ptr<BRepBlend_SurfRstConstRad>, Blend_SurfRstFunction> cls_BRepBlend_SurfRstConstRad(mod, "BRepBlend_SurfRstConstRad", "Copy of CSConstRad with pcurve on surface as support.");

// Constructors
cls_BRepBlend_SurfRstConstRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("Surf"), py::arg("SurfRst"), py::arg("Rst"), py::arg("CGuide"));

// Fields

// Methods
// cls_BRepBlend_SurfRstConstRad.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfRstConstRad::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstConstRad.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfRstConstRad::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstConstRad.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfRstConstRad::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstConstRad.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfRstConstRad::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstConstRad.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfRstConstRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfRstConstRad.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfRstConstRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfRstConstRad.def("NbVariables", (Standard_Integer (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::NbVariables, "Returns 3.");
cls_BRepBlend_SurfRstConstRad.def("NbEquations", (Standard_Integer (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::NbEquations, "Returns 3.");
cls_BRepBlend_SurfRstConstRad.def("Value", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const math_Vector &, math_Vector &)) &BRepBlend_SurfRstConstRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_SurfRstConstRad.def("Derivatives", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const math_Vector &, math_Matrix &)) &BRepBlend_SurfRstConstRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_SurfRstConstRad.def("Values", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_SurfRstConstRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_SurfRstConstRad.def("Set", (void (BRepBlend_SurfRstConstRad::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_SurfRstConstRad::Set, "None", py::arg("SurfRef"), py::arg("RstRef"));
cls_BRepBlend_SurfRstConstRad.def("Set", (void (BRepBlend_SurfRstConstRad::*)(const Standard_Real)) &BRepBlend_SurfRstConstRad::Set, "None", py::arg("Param"));
cls_BRepBlend_SurfRstConstRad.def("Set", (void (BRepBlend_SurfRstConstRad::*)(const Standard_Real, const Standard_Real)) &BRepBlend_SurfRstConstRad::Set, "Sets the bounds of the parametric interval on the guide line. This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_BRepBlend_SurfRstConstRad.def("GetTolerance", (void (BRepBlend_SurfRstConstRad::*)(math_Vector &, const Standard_Real) const) &BRepBlend_SurfRstConstRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_SurfRstConstRad.def("GetBounds", (void (BRepBlend_SurfRstConstRad::*)(math_Vector &, math_Vector &) const) &BRepBlend_SurfRstConstRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_SurfRstConstRad.def("IsSolution", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const math_Vector &, const Standard_Real)) &BRepBlend_SurfRstConstRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_SurfRstConstRad.def("GetMinimalDistance", (Standard_Real (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_SurfRstConstRad.def("PointOnS", (const gp_Pnt & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::PointOnS, "None");
cls_BRepBlend_SurfRstConstRad.def("PointOnRst", (const gp_Pnt & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::PointOnRst, "None");
cls_BRepBlend_SurfRstConstRad.def("Pnt2dOnS", (const gp_Pnt2d & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::Pnt2dOnS, "Returns U,V coordinates of the point on the surface.");
cls_BRepBlend_SurfRstConstRad.def("Pnt2dOnRst", (const gp_Pnt2d & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::Pnt2dOnRst, "Returns U,V coordinates of the point on the curve on surface.");
cls_BRepBlend_SurfRstConstRad.def("ParameterOnRst", (Standard_Real (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::ParameterOnRst, "Returns parameter of the point on the curve.");
cls_BRepBlend_SurfRstConstRad.def("IsTangencyPoint", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::IsTangencyPoint, "None");
cls_BRepBlend_SurfRstConstRad.def("TangentOnS", (const gp_Vec & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::TangentOnS, "None");
cls_BRepBlend_SurfRstConstRad.def("Tangent2dOnS", (const gp_Vec2d & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::Tangent2dOnS, "None");
cls_BRepBlend_SurfRstConstRad.def("TangentOnRst", (const gp_Vec & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::TangentOnRst, "None");
cls_BRepBlend_SurfRstConstRad.def("Tangent2dOnRst", (const gp_Vec2d & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::Tangent2dOnRst, "None");
cls_BRepBlend_SurfRstConstRad.def("Decroch", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const math_Vector &, gp_Vec &, gp_Vec &) const) &BRepBlend_SurfRstConstRad::Decroch, "Enables implementation of a criterion of decrochage specific to the function. Warning: Can be called without previous call of issolution but the values calculated can be senseless.", py::arg("Sol"), py::arg("NS"), py::arg("TgS"));
cls_BRepBlend_SurfRstConstRad.def("Set", (void (BRepBlend_SurfRstConstRad::*)(const Standard_Real, const Standard_Integer)) &BRepBlend_SurfRstConstRad::Set, "None", py::arg("Radius"), py::arg("Choix"));
cls_BRepBlend_SurfRstConstRad.def("Set", (void (BRepBlend_SurfRstConstRad::*)(const BlendFunc_SectionShape)) &BRepBlend_SurfRstConstRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_SurfRstConstRad.def("Section", [](BRepBlend_SurfRstConstRad &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, const Standard_Real W, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, W, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_SurfRstConstRad.def("IsRational", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_SurfRstConstRad.def("GetSectionSize", (Standard_Real (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_SurfRstConstRad.def("GetMinimalWeight", (void (BRepBlend_SurfRstConstRad::*)(TColStd_Array1OfReal &) const) &BRepBlend_SurfRstConstRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_SurfRstConstRad.def("NbIntervals", (Standard_Integer (BRepBlend_SurfRstConstRad::*)(const GeomAbs_Shape) const) &BRepBlend_SurfRstConstRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_SurfRstConstRad.def("Intervals", (void (BRepBlend_SurfRstConstRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepBlend_SurfRstConstRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>. The array must provide enough room to accomodate for the parameters. i.e. T.Length() > NbIntervals()", py::arg("T"), py::arg("S"));
cls_BRepBlend_SurfRstConstRad.def("GetShape", [](BRepBlend_SurfRstConstRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_SurfRstConstRad.def("GetTolerance", (void (BRepBlend_SurfRstConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BRepBlend_SurfRstConstRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_SurfRstConstRad.def("Knots", (void (BRepBlend_SurfRstConstRad::*)(TColStd_Array1OfReal &)) &BRepBlend_SurfRstConstRad::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_SurfRstConstRad.def("Mults", (void (BRepBlend_SurfRstConstRad::*)(TColStd_Array1OfInteger &)) &BRepBlend_SurfRstConstRad::Mults, "None", py::arg("TMults"));
cls_BRepBlend_SurfRstConstRad.def("Section", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstConstRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_SurfRstConstRad.def("Section", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstConstRad::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_SurfRstConstRad.def("Section", (void (BRepBlend_SurfRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstConstRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_SurfRstConstRad.def("Resolution", [](BRepBlend_SurfRstConstRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// Enums

}