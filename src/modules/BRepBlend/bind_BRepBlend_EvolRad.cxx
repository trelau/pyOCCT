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
#include <gp_Circ.hxx>
#include <Blend_Point.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Law_Function.hxx>
#include <BlendFunc_EvolRad.hxx>
#include <BRepBlend_EvolRad.hxx>

void bind_BRepBlend_EvolRad(py::module &mod){

py::class_<BlendFunc_EvolRad, std::unique_ptr<BlendFunc_EvolRad>, Blend_Function> cls_BRepBlend_EvolRad(mod, "BRepBlend_EvolRad", "None", py::module_local());

// Constructors
cls_BRepBlend_EvolRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"), py::arg("Law"));

// Fields

// Methods
// cls_BRepBlend_EvolRad.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_EvolRad::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_EvolRad.def_static("operator delete_", (void (*)(void *)) &BlendFunc_EvolRad::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_EvolRad.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_EvolRad::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_EvolRad.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_EvolRad::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_EvolRad.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_EvolRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_EvolRad.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_EvolRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_EvolRad.def("NbEquations", (Standard_Integer (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_EvolRad.def("Value", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, math_Vector &)) &BlendFunc_EvolRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_EvolRad.def("Derivatives", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, math_Matrix &)) &BlendFunc_EvolRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_EvolRad.def("Values", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_EvolRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const Standard_Real)) &BlendFunc_EvolRad::Set, "None", py::arg("Param"));
cls_BRepBlend_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const Standard_Real, const Standard_Real)) &BlendFunc_EvolRad::Set, "None", py::arg("First"), py::arg("Last"));
cls_BRepBlend_EvolRad.def("GetTolerance", (void (BlendFunc_EvolRad::*)(math_Vector &, const Standard_Real) const) &BlendFunc_EvolRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_EvolRad.def("GetBounds", (void (BlendFunc_EvolRad::*)(math_Vector &, math_Vector &) const) &BlendFunc_EvolRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_EvolRad.def("IsSolution", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, const Standard_Real)) &BlendFunc_EvolRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_EvolRad.def("GetMinimalDistance", (Standard_Real (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_EvolRad.def("PointOnS1", (const gp_Pnt & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::PointOnS1, "None");
cls_BRepBlend_EvolRad.def("PointOnS2", (const gp_Pnt & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::PointOnS2, "None");
cls_BRepBlend_EvolRad.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::IsTangencyPoint, "None");
cls_BRepBlend_EvolRad.def("TangentOnS1", (const gp_Vec & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::TangentOnS1, "None");
cls_BRepBlend_EvolRad.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::Tangent2dOnS1, "None");
cls_BRepBlend_EvolRad.def("TangentOnS2", (const gp_Vec & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::TangentOnS2, "None");
cls_BRepBlend_EvolRad.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::Tangent2dOnS2, "None");
cls_BRepBlend_EvolRad.def("Tangent", (void (BlendFunc_EvolRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BlendFunc_EvolRad::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
cls_BRepBlend_EvolRad.def("TwistOnS1", (Standard_Boolean (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::TwistOnS1, "None");
cls_BRepBlend_EvolRad.def("TwistOnS2", (Standard_Boolean (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::TwistOnS2, "None");
cls_BRepBlend_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const Standard_Integer)) &BlendFunc_EvolRad::Set, "None", py::arg("Choix"));
cls_BRepBlend_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const BlendFunc_SectionShape)) &BlendFunc_EvolRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_EvolRad.def("Section", [](BlendFunc_EvolRad &self, const Standard_Real Param, const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U1, V1, U2, V2, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "Method for graphic traces", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_EvolRad.def("IsRational", (Standard_Boolean (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_EvolRad.def("GetSectionSize", (Standard_Real (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_EvolRad.def("GetMinimalWeight", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfReal &) const) &BlendFunc_EvolRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_EvolRad.def("NbIntervals", (Standard_Integer (BlendFunc_EvolRad::*)(const GeomAbs_Shape) const) &BlendFunc_EvolRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_EvolRad.def("Intervals", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_EvolRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepBlend_EvolRad.def("GetShape", [](BlendFunc_EvolRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_EvolRad.def("GetTolerance", (void (BlendFunc_EvolRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_EvolRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_EvolRad.def("Knots", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_EvolRad.def("Mults", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfInteger &)) &BlendFunc_EvolRad::Mults, "None", py::arg("TMults"));
cls_BRepBlend_EvolRad.def("Section", (Standard_Boolean (BlendFunc_EvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_EvolRad.def("Section", (Standard_Boolean (BlendFunc_EvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_EvolRad.def("Section", (void (BlendFunc_EvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_EvolRad.def("Resolution", [](BlendFunc_EvolRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// Enums

}