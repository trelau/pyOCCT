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
#include <Blend_CurvPointFuncInv.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <BRepBlend_CurvPointRadInv.hxx>

void bind_BRepBlend_CurvPointRadInv(py::module &mod){

py::class_<BRepBlend_CurvPointRadInv, std::unique_ptr<BRepBlend_CurvPointRadInv>, Blend_CurvPointFuncInv> cls_BRepBlend_CurvPointRadInv(mod, "BRepBlend_CurvPointRadInv", "Function of reframing between a point and a curve. valid in cases of constant and progressive radius. This function is used to find a solution on a done point of the curve 1 when using RstRstConsRad or CSConstRad... The vector <X> used in Value, Values and Derivatives methods has to be the vector of the parametric coordinates w, U where w is the parameter on the guide line, U are the parametric coordinates of a point on the partner curve 2.");

// Constructors
cls_BRepBlend_CurvPointRadInv.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("C1"), py::arg("C2"));

// Fields

// Methods
// cls_BRepBlend_CurvPointRadInv.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_CurvPointRadInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_CurvPointRadInv.def_static("operator delete_", (void (*)(void *)) &BRepBlend_CurvPointRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_CurvPointRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_CurvPointRadInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_CurvPointRadInv.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_CurvPointRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_CurvPointRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_CurvPointRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_CurvPointRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_CurvPointRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_CurvPointRadInv.def("Set", (void (BRepBlend_CurvPointRadInv::*)(const Standard_Integer)) &BRepBlend_CurvPointRadInv::Set, "None", py::arg("Choix"));
cls_BRepBlend_CurvPointRadInv.def("NbEquations", (Standard_Integer (BRepBlend_CurvPointRadInv::*)() const) &BRepBlend_CurvPointRadInv::NbEquations, "returns 2.");
cls_BRepBlend_CurvPointRadInv.def("Value", (Standard_Boolean (BRepBlend_CurvPointRadInv::*)(const math_Vector &, math_Vector &)) &BRepBlend_CurvPointRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_CurvPointRadInv.def("Derivatives", (Standard_Boolean (BRepBlend_CurvPointRadInv::*)(const math_Vector &, math_Matrix &)) &BRepBlend_CurvPointRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_CurvPointRadInv.def("Values", (Standard_Boolean (BRepBlend_CurvPointRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_CurvPointRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_CurvPointRadInv.def("Set", (void (BRepBlend_CurvPointRadInv::*)(const gp_Pnt &)) &BRepBlend_CurvPointRadInv::Set, "Set the Point on which a solution has to be found.", py::arg("P"));
cls_BRepBlend_CurvPointRadInv.def("GetTolerance", (void (BRepBlend_CurvPointRadInv::*)(math_Vector &, const Standard_Real) const) &BRepBlend_CurvPointRadInv::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each of the 3 variables; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_CurvPointRadInv.def("GetBounds", (void (BRepBlend_CurvPointRadInv::*)(math_Vector &, math_Vector &) const) &BRepBlend_CurvPointRadInv::GetBounds, "Returns in the vector InfBound the lowest values allowed for each of the 3 variables. Returns in the vector SupBound the greatest values allowed for each of the 3 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_CurvPointRadInv.def("IsSolution", (Standard_Boolean (BRepBlend_CurvPointRadInv::*)(const math_Vector &, const Standard_Real)) &BRepBlend_CurvPointRadInv::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space.", py::arg("Sol"), py::arg("Tol"));

// Enums

}