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
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Blend_Point.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <Blend_Function.hxx>

void bind_Blend_Function(py::module &mod){

py::class_<Blend_Function, std::unique_ptr<Blend_Function>, Blend_AppFunction> cls_Blend_Function(mod, "Blend_Function", "Deferred class for a function used to compute a blending surface between two surfaces, using a guide line. The vector <X> used in Value, Values and Derivatives methods has to be the vector of the parametric coordinates U1,V1, U2,V2, of the extremities of a section on the first and second surface.");

// Fields

// Methods
// cls_Blend_Function.def_static("operator new_", (void * (*)(size_t)) &Blend_Function::operator new, "None", py::arg("theSize"));
// cls_Blend_Function.def_static("operator delete_", (void (*)(void *)) &Blend_Function::operator delete, "None", py::arg("theAddress"));
// cls_Blend_Function.def_static("operator new[]_", (void * (*)(size_t)) &Blend_Function::operator new[], "None", py::arg("theSize"));
// cls_Blend_Function.def_static("operator delete[]_", (void (*)(void *)) &Blend_Function::operator delete[], "None", py::arg("theAddress"));
// cls_Blend_Function.def_static("operator new_", (void * (*)(size_t, void *)) &Blend_Function::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Blend_Function.def_static("operator delete_", (void (*)(void *, void *)) &Blend_Function::operator delete, "None", py::arg(""), py::arg(""));
cls_Blend_Function.def("NbVariables", (Standard_Integer (Blend_Function::*)() const) &Blend_Function::NbVariables, "Returns 4.");
cls_Blend_Function.def("NbEquations", (Standard_Integer (Blend_Function::*)() const) &Blend_Function::NbEquations, "returns the number of equations of the function.");
cls_Blend_Function.def("Value", (Standard_Boolean (Blend_Function::*)(const math_Vector &, math_Vector &)) &Blend_Function::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_Blend_Function.def("Derivatives", (Standard_Boolean (Blend_Function::*)(const math_Vector &, math_Matrix &)) &Blend_Function::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_Blend_Function.def("Values", (Standard_Boolean (Blend_Function::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Blend_Function::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_Blend_Function.def("Set", (void (Blend_Function::*)(const Standard_Real)) &Blend_Function::Set, "Sets the value of the parameter along the guide line. This determines the plane in which the solution has to be found.", py::arg("Param"));
cls_Blend_Function.def("Set", (void (Blend_Function::*)(const Standard_Real, const Standard_Real)) &Blend_Function::Set, "Sets the bounds of the parametric interval on the guide line. This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_Blend_Function.def("GetTolerance", (void (Blend_Function::*)(math_Vector &, const Standard_Real) const) &Blend_Function::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each of the 4 variables; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_Blend_Function.def("GetBounds", (void (Blend_Function::*)(math_Vector &, math_Vector &) const) &Blend_Function::GetBounds, "Returns in the vector InfBound the lowest values allowed for each of the 4 variables. Returns in the vector SupBound the greatest values allowed for each of the 4 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_Blend_Function.def("IsSolution", (Standard_Boolean (Blend_Function::*)(const math_Vector &, const Standard_Real)) &Blend_Function::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space. The computation is made at the current value of the parameter on the guide line.", py::arg("Sol"), py::arg("Tol"));
cls_Blend_Function.def("Pnt1", (const gp_Pnt & (Blend_Function::*)() const) &Blend_Function::Pnt1, "Returns the point on the first support.");
cls_Blend_Function.def("Pnt2", (const gp_Pnt & (Blend_Function::*)() const) &Blend_Function::Pnt2, "Returns the point on the seconde support.");
cls_Blend_Function.def("PointOnS1", (const gp_Pnt & (Blend_Function::*)() const) &Blend_Function::PointOnS1, "Returns the point on the first surface, at parameter Sol(1),Sol(2) (Sol is the vector used in the call of IsSolution.");
cls_Blend_Function.def("PointOnS2", (const gp_Pnt & (Blend_Function::*)() const) &Blend_Function::PointOnS2, "Returns the point on the second surface, at parameter Sol(3),Sol(4) (Sol is the vector used in the call of IsSolution.");
cls_Blend_Function.def("IsTangencyPoint", (Standard_Boolean (Blend_Function::*)() const) &Blend_Function::IsTangencyPoint, "Returns True when it is not possible to compute the tangent vectors at PointOnS1 and/or PointOnS2.");
cls_Blend_Function.def("TangentOnS1", (const gp_Vec & (Blend_Function::*)() const) &Blend_Function::TangentOnS1, "Returns the tangent vector at PointOnS1, in 3d space.");
cls_Blend_Function.def("Tangent2dOnS1", (const gp_Vec2d & (Blend_Function::*)() const) &Blend_Function::Tangent2dOnS1, "Returns the tangent vector at PointOnS1, in the parametric space of the first surface.");
cls_Blend_Function.def("TangentOnS2", (const gp_Vec & (Blend_Function::*)() const) &Blend_Function::TangentOnS2, "Returns the tangent vector at PointOnS2, in 3d space.");
cls_Blend_Function.def("Tangent2dOnS2", (const gp_Vec2d & (Blend_Function::*)() const) &Blend_Function::Tangent2dOnS2, "Returns the tangent vector at PointOnS2, in the parametric space of the second surface.");
cls_Blend_Function.def("Tangent", (void (Blend_Function::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Blend_Function::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
cls_Blend_Function.def("TwistOnS1", (Standard_Boolean (Blend_Function::*)() const) &Blend_Function::TwistOnS1, "None");
cls_Blend_Function.def("TwistOnS2", (Standard_Boolean (Blend_Function::*)() const) &Blend_Function::TwistOnS2, "None");
cls_Blend_Function.def("GetShape", [](Blend_Function &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_Blend_Function.def("GetTolerance", (void (Blend_Function::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &Blend_Function::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_Blend_Function.def("Knots", (void (Blend_Function::*)(TColStd_Array1OfReal &)) &Blend_Function::Knots, "None", py::arg("TKnots"));
cls_Blend_Function.def("Mults", (void (Blend_Function::*)(TColStd_Array1OfInteger &)) &Blend_Function::Mults, "None", py::arg("TMults"));
cls_Blend_Function.def("Section", (Standard_Boolean (Blend_Function::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &Blend_Function::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_Blend_Function.def("Section", (void (Blend_Function::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &Blend_Function::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_Blend_Function.def("Section", (Standard_Boolean (Blend_Function::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &Blend_Function::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));

// Enums

}