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
#include <math_Matrix.hxx>
#include <gp_Lin.hxx>
#include <Blend_Point.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <BlendFunc_Chamfer.hxx>
#include <BRepBlend_Chamfer.hxx>

void bind_BRepBlend_Chamfer(py::module &mod){

py::class_<BlendFunc_Chamfer, std::unique_ptr<BlendFunc_Chamfer, Deleter<BlendFunc_Chamfer>>, Blend_Function> cls_BRepBlend_Chamfer(mod, "BRepBlend_Chamfer", "None", py::module_local());

// Constructors
cls_BRepBlend_Chamfer.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("CG"));

// Fields

// Methods
// cls_BRepBlend_Chamfer.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_Chamfer::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_Chamfer.def_static("operator delete_", (void (*)(void *)) &BlendFunc_Chamfer::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_Chamfer.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_Chamfer::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_Chamfer.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_Chamfer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_Chamfer.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_Chamfer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_Chamfer.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_Chamfer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_Chamfer.def("NbEquations", (Standard_Integer (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_Chamfer.def("Value", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, math_Vector &)) &BlendFunc_Chamfer::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_Chamfer.def("Derivatives", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, math_Matrix &)) &BlendFunc_Chamfer::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_Chamfer.def("Values", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_Chamfer::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_Chamfer.def("Set", (void (BlendFunc_Chamfer::*)(const Standard_Real)) &BlendFunc_Chamfer::Set, "None", py::arg("Param"));
cls_BRepBlend_Chamfer.def("Set", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real)) &BlendFunc_Chamfer::Set, "None", py::arg("First"), py::arg("Last"));
cls_BRepBlend_Chamfer.def("GetTolerance", (void (BlendFunc_Chamfer::*)(math_Vector &, const Standard_Real) const) &BlendFunc_Chamfer::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_Chamfer.def("GetBounds", (void (BlendFunc_Chamfer::*)(math_Vector &, math_Vector &) const) &BlendFunc_Chamfer::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_Chamfer.def("IsSolution", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, const Standard_Real)) &BlendFunc_Chamfer::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_Chamfer.def("GetMinimalDistance", (Standard_Real (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_Chamfer.def("PointOnS1", (const gp_Pnt & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::PointOnS1, "None");
cls_BRepBlend_Chamfer.def("PointOnS2", (const gp_Pnt & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::PointOnS2, "None");
cls_BRepBlend_Chamfer.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::IsTangencyPoint, "None");
cls_BRepBlend_Chamfer.def("TangentOnS1", (const gp_Vec & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::TangentOnS1, "None");
cls_BRepBlend_Chamfer.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::Tangent2dOnS1, "None");
cls_BRepBlend_Chamfer.def("TangentOnS2", (const gp_Vec & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::TangentOnS2, "None");
cls_BRepBlend_Chamfer.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::Tangent2dOnS2, "None");
cls_BRepBlend_Chamfer.def("Tangent", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BlendFunc_Chamfer::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
cls_BRepBlend_Chamfer.def("Set", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_Chamfer::Set, "Sets the distances and the 'quadrant'.", py::arg("Dist1"), py::arg("Dist2"), py::arg("Choix"));
cls_BRepBlend_Chamfer.def("IsRational", (Standard_Boolean (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::IsRational, "Returns False");
cls_BRepBlend_Chamfer.def("GetSectionSize", (Standard_Real (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_Chamfer.def("GetMinimalWeight", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfReal &) const) &BlendFunc_Chamfer::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_Chamfer.def("NbIntervals", (Standard_Integer (BlendFunc_Chamfer::*)(const GeomAbs_Shape) const) &BlendFunc_Chamfer::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_Chamfer.def("Intervals", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_Chamfer::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepBlend_Chamfer.def("GetShape", [](BlendFunc_Chamfer &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_Chamfer.def("GetTolerance", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_Chamfer::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_Chamfer.def("Knots", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_Chamfer.def("Mults", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfInteger &)) &BlendFunc_Chamfer::Mults, "None", py::arg("TMults"));
cls_BRepBlend_Chamfer.def("Section", [](BlendFunc_Chamfer &self, const Standard_Real Param, const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Lin & C){ self.Section(Param, U1, V1, U2, V2, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "Obsolete method", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_Chamfer.def("Section", (Standard_Boolean (BlendFunc_Chamfer::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_Chamfer.def("Section", (Standard_Boolean (BlendFunc_Chamfer::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_Chamfer.def("Section", (void (BlendFunc_Chamfer::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_Chamfer.def("Resolution", [](BlendFunc_Chamfer &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// Enums

}