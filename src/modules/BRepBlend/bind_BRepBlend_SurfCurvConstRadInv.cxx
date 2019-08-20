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
#include <Blend_SurfCurvFuncInv.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <BRepBlend_SurfCurvConstRadInv.hxx>

void bind_BRepBlend_SurfCurvConstRadInv(py::module &mod){

py::class_<BRepBlend_SurfCurvConstRadInv, std::unique_ptr<BRepBlend_SurfCurvConstRadInv>, Blend_SurfCurvFuncInv> cls_BRepBlend_SurfCurvConstRadInv(mod, "BRepBlend_SurfCurvConstRadInv", "Function of reframing between a restriction surface of the surface and a curve. Class used to compute a solution of the surfRstConstRad problem on a done restriction of the surface. The vector <X> used in Value, Values and Derivatives methods has to be the vector of the parametric coordinates wguide, wcurv, wrst where wguide is the parameter on the guide line, wcurv is the parameter on the curve, wrst is the parameter on the restriction on the surface.");

// Constructors
cls_BRepBlend_SurfCurvConstRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"), py::arg("Cg"));

// Fields

// Methods
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfCurvConstRadInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfCurvConstRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfCurvConstRadInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfCurvConstRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfCurvConstRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfCurvConstRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfCurvConstRadInv.def("Set", (void (BRepBlend_SurfCurvConstRadInv::*)(const Standard_Real, const Standard_Integer)) &BRepBlend_SurfCurvConstRadInv::Set, "None", py::arg("R"), py::arg("Choix"));
cls_BRepBlend_SurfCurvConstRadInv.def("NbEquations", (Standard_Integer (BRepBlend_SurfCurvConstRadInv::*)() const) &BRepBlend_SurfCurvConstRadInv::NbEquations, "returns 3.");
cls_BRepBlend_SurfCurvConstRadInv.def("Value", (Standard_Boolean (BRepBlend_SurfCurvConstRadInv::*)(const math_Vector &, math_Vector &)) &BRepBlend_SurfCurvConstRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_SurfCurvConstRadInv.def("Derivatives", (Standard_Boolean (BRepBlend_SurfCurvConstRadInv::*)(const math_Vector &, math_Matrix &)) &BRepBlend_SurfCurvConstRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_SurfCurvConstRadInv.def("Values", (Standard_Boolean (BRepBlend_SurfCurvConstRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_SurfCurvConstRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_SurfCurvConstRadInv.def("Set", (void (BRepBlend_SurfCurvConstRadInv::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_SurfCurvConstRadInv::Set, "Set the restriction on which a solution has to be found.", py::arg("Rst"));
cls_BRepBlend_SurfCurvConstRadInv.def("GetTolerance", (void (BRepBlend_SurfCurvConstRadInv::*)(math_Vector &, const Standard_Real) const) &BRepBlend_SurfCurvConstRadInv::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each of the 3 variables; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_SurfCurvConstRadInv.def("GetBounds", (void (BRepBlend_SurfCurvConstRadInv::*)(math_Vector &, math_Vector &) const) &BRepBlend_SurfCurvConstRadInv::GetBounds, "Returns in the vector InfBound the lowest values allowed for each of the 3 variables. Returns in the vector SupBound the greatest values allowed for each of the 3 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_SurfCurvConstRadInv.def("IsSolution", (Standard_Boolean (BRepBlend_SurfCurvConstRadInv::*)(const math_Vector &, const Standard_Real)) &BRepBlend_SurfCurvConstRadInv::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space.", py::arg("Sol"), py::arg("Tol"));

// Enums

}