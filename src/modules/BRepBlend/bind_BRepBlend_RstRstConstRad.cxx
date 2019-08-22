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
#include <Blend_RstRstFunction.hxx>
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
#include <Blend_DecrochStatus.hxx>
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
#include <BRepBlend_RstRstConstRad.hxx>

void bind_BRepBlend_RstRstConstRad(py::module &mod){

py::class_<BRepBlend_RstRstConstRad, Blend_RstRstFunction> cls_BRepBlend_RstRstConstRad(mod, "BRepBlend_RstRstConstRad", "Copy of CSConstRad with a pcurve on surface as support.");

// Constructors
cls_BRepBlend_RstRstConstRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("Surf1"), py::arg("Rst1"), py::arg("Surf2"), py::arg("Rst2"), py::arg("CGuide"));

// Fields

// Methods
// cls_BRepBlend_RstRstConstRad.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_RstRstConstRad::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_RstRstConstRad.def_static("operator delete_", (void (*)(void *)) &BRepBlend_RstRstConstRad::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_RstRstConstRad.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_RstRstConstRad::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_RstRstConstRad.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_RstRstConstRad::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_RstRstConstRad.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_RstRstConstRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_RstRstConstRad.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_RstRstConstRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_RstRstConstRad.def("NbVariables", (Standard_Integer (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::NbVariables, "Returns 2.");
cls_BRepBlend_RstRstConstRad.def("NbEquations", (Standard_Integer (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::NbEquations, "Returns 2.");
cls_BRepBlend_RstRstConstRad.def("Value", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const math_Vector &, math_Vector &)) &BRepBlend_RstRstConstRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_RstRstConstRad.def("Derivatives", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const math_Vector &, math_Matrix &)) &BRepBlend_RstRstConstRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_RstRstConstRad.def("Values", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_RstRstConstRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_RstRstConstRad.def("Set", (void (BRepBlend_RstRstConstRad::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_RstRstConstRad::Set, "None", py::arg("SurfRef1"), py::arg("RstRef1"), py::arg("SurfRef2"), py::arg("RstRef2"));
cls_BRepBlend_RstRstConstRad.def("Set", (void (BRepBlend_RstRstConstRad::*)(const Standard_Real)) &BRepBlend_RstRstConstRad::Set, "None", py::arg("Param"));
cls_BRepBlend_RstRstConstRad.def("Set", (void (BRepBlend_RstRstConstRad::*)(const Standard_Real, const Standard_Real)) &BRepBlend_RstRstConstRad::Set, "Sets the bounds of the parametric interval on the guide line. This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_BRepBlend_RstRstConstRad.def("GetTolerance", (void (BRepBlend_RstRstConstRad::*)(math_Vector &, const Standard_Real) const) &BRepBlend_RstRstConstRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_RstRstConstRad.def("GetBounds", (void (BRepBlend_RstRstConstRad::*)(math_Vector &, math_Vector &) const) &BRepBlend_RstRstConstRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_RstRstConstRad.def("IsSolution", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const math_Vector &, const Standard_Real)) &BRepBlend_RstRstConstRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_RstRstConstRad.def("GetMinimalDistance", (Standard_Real (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_RstRstConstRad.def("PointOnRst1", (const gp_Pnt & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::PointOnRst1, "None");
cls_BRepBlend_RstRstConstRad.def("PointOnRst2", (const gp_Pnt & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::PointOnRst2, "None");
cls_BRepBlend_RstRstConstRad.def("Pnt2dOnRst1", (const gp_Pnt2d & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::Pnt2dOnRst1, "Returns U,V coordinates of the point on the surface.");
cls_BRepBlend_RstRstConstRad.def("Pnt2dOnRst2", (const gp_Pnt2d & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::Pnt2dOnRst2, "Returns U,V coordinates of the point on the curve on surface.");
cls_BRepBlend_RstRstConstRad.def("ParameterOnRst1", (Standard_Real (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::ParameterOnRst1, "Returns parameter of the point on the curve.");
cls_BRepBlend_RstRstConstRad.def("ParameterOnRst2", (Standard_Real (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::ParameterOnRst2, "Returns parameter of the point on the curve.");
cls_BRepBlend_RstRstConstRad.def("IsTangencyPoint", (Standard_Boolean (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::IsTangencyPoint, "None");
cls_BRepBlend_RstRstConstRad.def("TangentOnRst1", (const gp_Vec & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::TangentOnRst1, "None");
cls_BRepBlend_RstRstConstRad.def("Tangent2dOnRst1", (const gp_Vec2d & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::Tangent2dOnRst1, "None");
cls_BRepBlend_RstRstConstRad.def("TangentOnRst2", (const gp_Vec & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::TangentOnRst2, "None");
cls_BRepBlend_RstRstConstRad.def("Tangent2dOnRst2", (const gp_Vec2d & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::Tangent2dOnRst2, "None");
cls_BRepBlend_RstRstConstRad.def("Decroch", (Blend_DecrochStatus (BRepBlend_RstRstConstRad::*)(const math_Vector &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BRepBlend_RstRstConstRad::Decroch, "Permet d ' implementer un critere de decrochage specifique a la fonction.", py::arg("Sol"), py::arg("NRst1"), py::arg("TgRst1"), py::arg("NRst2"), py::arg("TgRst2"));
cls_BRepBlend_RstRstConstRad.def("Set", (void (BRepBlend_RstRstConstRad::*)(const Standard_Real, const Standard_Integer)) &BRepBlend_RstRstConstRad::Set, "None", py::arg("Radius"), py::arg("Choix"));
cls_BRepBlend_RstRstConstRad.def("Set", (void (BRepBlend_RstRstConstRad::*)(const BlendFunc_SectionShape)) &BRepBlend_RstRstConstRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_RstRstConstRad.def("CenterCircleRst1Rst2", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const gp_Pnt &, const gp_Pnt &, const gp_Vec &, gp_Pnt &, gp_Vec &) const) &BRepBlend_RstRstConstRad::CenterCircleRst1Rst2, "Give the center of circle define by PtRst1, PtRst2 and radius ray.", py::arg("PtRst1"), py::arg("PtRst2"), py::arg("np"), py::arg("Center"), py::arg("VdMed"));
cls_BRepBlend_RstRstConstRad.def("Section", [](BRepBlend_RstRstConstRad &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_RstRstConstRad.def("IsRational", (Standard_Boolean (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_RstRstConstRad.def("GetSectionSize", (Standard_Real (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_RstRstConstRad.def("GetMinimalWeight", (void (BRepBlend_RstRstConstRad::*)(TColStd_Array1OfReal &) const) &BRepBlend_RstRstConstRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_RstRstConstRad.def("NbIntervals", (Standard_Integer (BRepBlend_RstRstConstRad::*)(const GeomAbs_Shape) const) &BRepBlend_RstRstConstRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_RstRstConstRad.def("Intervals", (void (BRepBlend_RstRstConstRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepBlend_RstRstConstRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>. The array must provide enough room to accomodate for the parameters. i.e. T.Length() > NbIntervals()", py::arg("T"), py::arg("S"));
cls_BRepBlend_RstRstConstRad.def("GetShape", [](BRepBlend_RstRstConstRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_RstRstConstRad.def("GetTolerance", (void (BRepBlend_RstRstConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BRepBlend_RstRstConstRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_RstRstConstRad.def("Knots", (void (BRepBlend_RstRstConstRad::*)(TColStd_Array1OfReal &)) &BRepBlend_RstRstConstRad::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_RstRstConstRad.def("Mults", (void (BRepBlend_RstRstConstRad::*)(TColStd_Array1OfInteger &)) &BRepBlend_RstRstConstRad::Mults, "None", py::arg("TMults"));
cls_BRepBlend_RstRstConstRad.def("Section", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_RstRstConstRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_RstRstConstRad.def("Section", (void (BRepBlend_RstRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BRepBlend_RstRstConstRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_RstRstConstRad.def("Section", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_RstRstConstRad::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_RstRstConstRad.def("Resolution", [](BRepBlend_RstRstConstRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// Enums

}