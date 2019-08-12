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
#include <math_FunctionSetWithDerivatives.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Blend_Point.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <Blend_AppFunction.hxx>

void bind_Blend_AppFunction(py::module &mod){

py::class_<Blend_AppFunction, std::unique_ptr<Blend_AppFunction, Deleter<Blend_AppFunction>>, math_FunctionSetWithDerivatives> cls_Blend_AppFunction(mod, "Blend_AppFunction", "Deferred class for a function used to compute a blending surface between two surfaces, using a guide line. The vector <X> used in Value, Values and Derivatives methods has to be the vector of the parametric coordinates U1,V1, U2,V2, of the extremities of a section on the first and second surface.");

// Fields

// Methods
// cls_Blend_AppFunction.def_static("operator new_", (void * (*)(size_t)) &Blend_AppFunction::operator new, "None", py::arg("theSize"));
// cls_Blend_AppFunction.def_static("operator delete_", (void (*)(void *)) &Blend_AppFunction::operator delete, "None", py::arg("theAddress"));
// cls_Blend_AppFunction.def_static("operator new[]_", (void * (*)(size_t)) &Blend_AppFunction::operator new[], "None", py::arg("theSize"));
// cls_Blend_AppFunction.def_static("operator delete[]_", (void (*)(void *)) &Blend_AppFunction::operator delete[], "None", py::arg("theAddress"));
// cls_Blend_AppFunction.def_static("operator new_", (void * (*)(size_t, void *)) &Blend_AppFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Blend_AppFunction.def_static("operator delete_", (void (*)(void *, void *)) &Blend_AppFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_Blend_AppFunction.def("NbVariables", (Standard_Integer (Blend_AppFunction::*)() const) &Blend_AppFunction::NbVariables, "returns the number of variables of the function.");
cls_Blend_AppFunction.def("NbEquations", (Standard_Integer (Blend_AppFunction::*)() const) &Blend_AppFunction::NbEquations, "returns the number of equations of the function.");
cls_Blend_AppFunction.def("Value", (Standard_Boolean (Blend_AppFunction::*)(const math_Vector &, math_Vector &)) &Blend_AppFunction::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_Blend_AppFunction.def("Derivatives", (Standard_Boolean (Blend_AppFunction::*)(const math_Vector &, math_Matrix &)) &Blend_AppFunction::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_Blend_AppFunction.def("Values", (Standard_Boolean (Blend_AppFunction::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Blend_AppFunction::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_Blend_AppFunction.def("Set", (void (Blend_AppFunction::*)(const Standard_Real)) &Blend_AppFunction::Set, "Sets the value of the parameter along the guide line. This determines the plane in which the solution has to be found.", py::arg("Param"));
cls_Blend_AppFunction.def("Set", (void (Blend_AppFunction::*)(const Standard_Real, const Standard_Real)) &Blend_AppFunction::Set, "Sets the bounds of the parametric interval on the guide line. This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_Blend_AppFunction.def("GetTolerance", (void (Blend_AppFunction::*)(math_Vector &, const Standard_Real) const) &Blend_AppFunction::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each of the 4 variables; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_Blend_AppFunction.def("GetBounds", (void (Blend_AppFunction::*)(math_Vector &, math_Vector &) const) &Blend_AppFunction::GetBounds, "Returns in the vector InfBound the lowest values allowed for each of the 4 variables. Returns in the vector SupBound the greatest values allowed for each of the 4 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_Blend_AppFunction.def("IsSolution", (Standard_Boolean (Blend_AppFunction::*)(const math_Vector &, const Standard_Real)) &Blend_AppFunction::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space. The computation is made at the current value of the parameter on the guide line.", py::arg("Sol"), py::arg("Tol"));
cls_Blend_AppFunction.def("GetMinimalDistance", (Standard_Real (Blend_AppFunction::*)() const) &Blend_AppFunction::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_Blend_AppFunction.def("Pnt1", (const gp_Pnt & (Blend_AppFunction::*)() const) &Blend_AppFunction::Pnt1, "Returns the point on the first support.");
cls_Blend_AppFunction.def("Pnt2", (const gp_Pnt & (Blend_AppFunction::*)() const) &Blend_AppFunction::Pnt2, "Returns the point on the first support.");
cls_Blend_AppFunction.def("IsRational", (Standard_Boolean (Blend_AppFunction::*)() const) &Blend_AppFunction::IsRational, "Returns if the section is rationnal");
cls_Blend_AppFunction.def("GetSectionSize", (Standard_Real (Blend_AppFunction::*)() const) &Blend_AppFunction::GetSectionSize, "Returns the length of the maximum section");
cls_Blend_AppFunction.def("GetMinimalWeight", (void (Blend_AppFunction::*)(TColStd_Array1OfReal &) const) &Blend_AppFunction::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_Blend_AppFunction.def("NbIntervals", (Standard_Integer (Blend_AppFunction::*)(const GeomAbs_Shape) const) &Blend_AppFunction::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_Blend_AppFunction.def("Intervals", (void (Blend_AppFunction::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Blend_AppFunction::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Blend_AppFunction.def("GetShape", [](Blend_AppFunction &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_Blend_AppFunction.def("GetTolerance", (void (Blend_AppFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &Blend_AppFunction::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_Blend_AppFunction.def("Knots", (void (Blend_AppFunction::*)(TColStd_Array1OfReal &)) &Blend_AppFunction::Knots, "None", py::arg("TKnots"));
cls_Blend_AppFunction.def("Mults", (void (Blend_AppFunction::*)(TColStd_Array1OfInteger &)) &Blend_AppFunction::Mults, "None", py::arg("TMults"));
cls_Blend_AppFunction.def("Section", (Standard_Boolean (Blend_AppFunction::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &Blend_AppFunction::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_Blend_AppFunction.def("Section", (void (Blend_AppFunction::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &Blend_AppFunction::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_Blend_AppFunction.def("Section", (Standard_Boolean (Blend_AppFunction::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &Blend_AppFunction::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_Blend_AppFunction.def("Resolution", [](Blend_AppFunction &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
cls_Blend_AppFunction.def("Parameter", (Standard_Real (Blend_AppFunction::*)(const Blend_Point &) const) &Blend_AppFunction::Parameter, "Returns the parameter of the point P. Used to impose the parameters in the approximation.", py::arg("P"));

// Enums

}