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
#include <Blend_AppFunction.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Blend_Point.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <Blend_SurfRstFunction.hxx>

void bind_Blend_SurfRstFunction(py::module &mod){

py::class_<Blend_SurfRstFunction, Blend_AppFunction> cls_Blend_SurfRstFunction(mod, "Blend_SurfRstFunction", "Deferred class for a function used to compute a blending surface between a surface and a pcurve on an other Surface, using a guide line. The vector <X> used in Value, Values and Derivatives methods may be the vector of the parametric coordinates U,V, W of the extremities of a section on the surface and the curve.");

// Fields

// Methods
// cls_Blend_SurfRstFunction.def_static("operator new_", (void * (*)(size_t)) &Blend_SurfRstFunction::operator new, "None", py::arg("theSize"));
// cls_Blend_SurfRstFunction.def_static("operator delete_", (void (*)(void *)) &Blend_SurfRstFunction::operator delete, "None", py::arg("theAddress"));
// cls_Blend_SurfRstFunction.def_static("operator new[]_", (void * (*)(size_t)) &Blend_SurfRstFunction::operator new[], "None", py::arg("theSize"));
// cls_Blend_SurfRstFunction.def_static("operator delete[]_", (void (*)(void *)) &Blend_SurfRstFunction::operator delete[], "None", py::arg("theAddress"));
// cls_Blend_SurfRstFunction.def_static("operator new_", (void * (*)(size_t, void *)) &Blend_SurfRstFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Blend_SurfRstFunction.def_static("operator delete_", (void (*)(void *, void *)) &Blend_SurfRstFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_Blend_SurfRstFunction.def("NbVariables", (Standard_Integer (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::NbVariables, "Returns 3 (default value). Can be redefined.");
cls_Blend_SurfRstFunction.def("NbEquations", (Standard_Integer (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::NbEquations, "returns the number of equations of the function.");
cls_Blend_SurfRstFunction.def("Value", (Standard_Boolean (Blend_SurfRstFunction::*)(const math_Vector &, math_Vector &)) &Blend_SurfRstFunction::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_Blend_SurfRstFunction.def("Derivatives", (Standard_Boolean (Blend_SurfRstFunction::*)(const math_Vector &, math_Matrix &)) &Blend_SurfRstFunction::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_Blend_SurfRstFunction.def("Values", (Standard_Boolean (Blend_SurfRstFunction::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Blend_SurfRstFunction::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_Blend_SurfRstFunction.def("Set", (void (Blend_SurfRstFunction::*)(const Standard_Real)) &Blend_SurfRstFunction::Set, "Sets the value of the parameter along the guide line. This determines the plane in which the solution has to be found.", py::arg("Param"));
cls_Blend_SurfRstFunction.def("Set", (void (Blend_SurfRstFunction::*)(const Standard_Real, const Standard_Real)) &Blend_SurfRstFunction::Set, "Sets the bounds of the parametric interval on the guide line. This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_Blend_SurfRstFunction.def("GetTolerance", (void (Blend_SurfRstFunction::*)(math_Vector &, const Standard_Real) const) &Blend_SurfRstFunction::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each variable; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_Blend_SurfRstFunction.def("GetBounds", (void (Blend_SurfRstFunction::*)(math_Vector &, math_Vector &) const) &Blend_SurfRstFunction::GetBounds, "Returns in the vector InfBound the lowest values allowed for each variables. Returns in the vector SupBound the greatest values allowed for each of the 3 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_Blend_SurfRstFunction.def("IsSolution", (Standard_Boolean (Blend_SurfRstFunction::*)(const math_Vector &, const Standard_Real)) &Blend_SurfRstFunction::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space. The computation is made at the current value of the parameter on the guide line.", py::arg("Sol"), py::arg("Tol"));
cls_Blend_SurfRstFunction.def("GetMinimalDistance", (Standard_Real (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_Blend_SurfRstFunction.def("Pnt1", (const gp_Pnt & (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::Pnt1, "Returns the point on the first support.");
cls_Blend_SurfRstFunction.def("Pnt2", (const gp_Pnt & (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::Pnt2, "Returns the point on the seconde support.");
cls_Blend_SurfRstFunction.def("PointOnS", (const gp_Pnt & (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::PointOnS, "Returns the point on the surface.");
cls_Blend_SurfRstFunction.def("PointOnRst", (const gp_Pnt & (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::PointOnRst, "Returns the point on the curve.");
cls_Blend_SurfRstFunction.def("Pnt2dOnS", (const gp_Pnt2d & (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::Pnt2dOnS, "Returns U,V coordinates of the point on the surface.");
cls_Blend_SurfRstFunction.def("Pnt2dOnRst", (const gp_Pnt2d & (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::Pnt2dOnRst, "Returns U,V coordinates of the point on the curve on surface.");
cls_Blend_SurfRstFunction.def("ParameterOnRst", (Standard_Real (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::ParameterOnRst, "Returns parameter of the point on the curve.");
cls_Blend_SurfRstFunction.def("IsTangencyPoint", (Standard_Boolean (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::IsTangencyPoint, "Returns True when it is not possible to compute the tangent vectors at PointOnS and/or PointOnRst.");
cls_Blend_SurfRstFunction.def("TangentOnS", (const gp_Vec & (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::TangentOnS, "Returns the tangent vector at PointOnS, in 3d space.");
cls_Blend_SurfRstFunction.def("Tangent2dOnS", (const gp_Vec2d & (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::Tangent2dOnS, "Returns the tangent vector at PointOnS, in the parametric space of the first surface.");
cls_Blend_SurfRstFunction.def("TangentOnRst", (const gp_Vec & (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::TangentOnRst, "Returns the tangent vector at PointOnC, in 3d space.");
cls_Blend_SurfRstFunction.def("Tangent2dOnRst", (const gp_Vec2d & (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::Tangent2dOnRst, "Returns the tangent vector at PointOnRst, in the parametric space of the second surface.");
cls_Blend_SurfRstFunction.def("Decroch", (Standard_Boolean (Blend_SurfRstFunction::*)(const math_Vector &, gp_Vec &, gp_Vec &) const) &Blend_SurfRstFunction::Decroch, "Enables implementation of a criterion of decrochage specific to the function.", py::arg("Sol"), py::arg("NS"), py::arg("TgS"));
cls_Blend_SurfRstFunction.def("IsRational", (Standard_Boolean (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::IsRational, "Returns if the section is rationnal");
cls_Blend_SurfRstFunction.def("GetSectionSize", (Standard_Real (Blend_SurfRstFunction::*)() const) &Blend_SurfRstFunction::GetSectionSize, "Returns the length of the maximum section");
cls_Blend_SurfRstFunction.def("GetMinimalWeight", (void (Blend_SurfRstFunction::*)(TColStd_Array1OfReal &) const) &Blend_SurfRstFunction::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_Blend_SurfRstFunction.def("NbIntervals", (Standard_Integer (Blend_SurfRstFunction::*)(const GeomAbs_Shape) const) &Blend_SurfRstFunction::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_Blend_SurfRstFunction.def("Intervals", (void (Blend_SurfRstFunction::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Blend_SurfRstFunction::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Blend_SurfRstFunction.def("GetShape", [](Blend_SurfRstFunction &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_Blend_SurfRstFunction.def("GetTolerance", (void (Blend_SurfRstFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &Blend_SurfRstFunction::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_Blend_SurfRstFunction.def("Knots", (void (Blend_SurfRstFunction::*)(TColStd_Array1OfReal &)) &Blend_SurfRstFunction::Knots, "None", py::arg("TKnots"));
cls_Blend_SurfRstFunction.def("Mults", (void (Blend_SurfRstFunction::*)(TColStd_Array1OfInteger &)) &Blend_SurfRstFunction::Mults, "None", py::arg("TMults"));
cls_Blend_SurfRstFunction.def("Section", (Standard_Boolean (Blend_SurfRstFunction::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &Blend_SurfRstFunction::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_Blend_SurfRstFunction.def("Section", (Standard_Boolean (Blend_SurfRstFunction::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &Blend_SurfRstFunction::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_Blend_SurfRstFunction.def("Section", (void (Blend_SurfRstFunction::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &Blend_SurfRstFunction::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));

// Enums

}