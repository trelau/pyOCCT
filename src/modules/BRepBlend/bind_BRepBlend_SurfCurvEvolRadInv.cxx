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
#include <Law_Function.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <BRepBlend_SurfCurvEvolRadInv.hxx>

void bind_BRepBlend_SurfCurvEvolRadInv(py::module &mod){

py::class_<BRepBlend_SurfCurvEvolRadInv, std::unique_ptr<BRepBlend_SurfCurvEvolRadInv, Deleter<BRepBlend_SurfCurvEvolRadInv>>, Blend_SurfCurvFuncInv> cls_BRepBlend_SurfCurvEvolRadInv(mod, "BRepBlend_SurfCurvEvolRadInv", "Function of reframing between a surface restriction of the surface and a curve. Class used to compute a solution of the surfRstConstRad problem on a done restriction of the surface. The vector <X> used in Value, Values and Derivatives methods has to be the vector of the parametric coordinates wguide, wcurv, wrst where wguide is the parameter on the guide line, wcurv is the parameter on the curve, wrst is the parameter on the restriction on the surface.");

// Constructors
cls_BRepBlend_SurfCurvEvolRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S"), py::arg("C"), py::arg("Cg"), py::arg("Evol"));

// Fields

// Methods
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfCurvEvolRadInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfCurvEvolRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfCurvEvolRadInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfCurvEvolRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfCurvEvolRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfCurvEvolRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfCurvEvolRadInv.def("Set", (void (BRepBlend_SurfCurvEvolRadInv::*)(const Standard_Integer)) &BRepBlend_SurfCurvEvolRadInv::Set, "None", py::arg("Choix"));
cls_BRepBlend_SurfCurvEvolRadInv.def("NbEquations", (Standard_Integer (BRepBlend_SurfCurvEvolRadInv::*)() const) &BRepBlend_SurfCurvEvolRadInv::NbEquations, "returns 3.");
cls_BRepBlend_SurfCurvEvolRadInv.def("Value", (Standard_Boolean (BRepBlend_SurfCurvEvolRadInv::*)(const math_Vector &, math_Vector &)) &BRepBlend_SurfCurvEvolRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_SurfCurvEvolRadInv.def("Derivatives", (Standard_Boolean (BRepBlend_SurfCurvEvolRadInv::*)(const math_Vector &, math_Matrix &)) &BRepBlend_SurfCurvEvolRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_SurfCurvEvolRadInv.def("Values", (Standard_Boolean (BRepBlend_SurfCurvEvolRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_SurfCurvEvolRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_SurfCurvEvolRadInv.def("Set", (void (BRepBlend_SurfCurvEvolRadInv::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_SurfCurvEvolRadInv::Set, "Set the restriction on which a solution has to be found.", py::arg("Rst"));
cls_BRepBlend_SurfCurvEvolRadInv.def("GetTolerance", (void (BRepBlend_SurfCurvEvolRadInv::*)(math_Vector &, const Standard_Real) const) &BRepBlend_SurfCurvEvolRadInv::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each of the 3 variables; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_SurfCurvEvolRadInv.def("GetBounds", (void (BRepBlend_SurfCurvEvolRadInv::*)(math_Vector &, math_Vector &) const) &BRepBlend_SurfCurvEvolRadInv::GetBounds, "Returns in the vector InfBound the lowest values allowed for each of the 3 variables. Returns in the vector SupBound the greatest values allowed for each of the 3 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_SurfCurvEvolRadInv.def("IsSolution", (Standard_Boolean (BRepBlend_SurfCurvEvolRadInv::*)(const math_Vector &, const Standard_Real)) &BRepBlend_SurfCurvEvolRadInv::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space.", py::arg("Sol"), py::arg("Tol"));

// Enums

}