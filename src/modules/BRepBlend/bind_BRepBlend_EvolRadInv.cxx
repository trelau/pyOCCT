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
#include <Adaptor2d_HCurve2d.hxx>
#include <math_Matrix.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Law_Function.hxx>
#include <BlendFunc_EvolRadInv.hxx>
#include <BRepBlend_EvolRadInv.hxx>

void bind_BRepBlend_EvolRadInv(py::module &mod){

py::class_<BlendFunc_EvolRadInv, Blend_FuncInv> cls_BRepBlend_EvolRadInv(mod, "BRepBlend_EvolRadInv", "None", py::module_local());

// Constructors
cls_BRepBlend_EvolRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"), py::arg("Law"));

// Fields

// Methods
// cls_BRepBlend_EvolRadInv.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_EvolRadInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_EvolRadInv.def_static("operator delete_", (void (*)(void *)) &BlendFunc_EvolRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_EvolRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_EvolRadInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_EvolRadInv.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_EvolRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_EvolRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_EvolRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_EvolRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_EvolRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_EvolRadInv.def("Set", (void (BlendFunc_EvolRadInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_EvolRadInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
cls_BRepBlend_EvolRadInv.def("GetTolerance", (void (BlendFunc_EvolRadInv::*)(math_Vector &, const Standard_Real) const) &BlendFunc_EvolRadInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_EvolRadInv.def("GetBounds", (void (BlendFunc_EvolRadInv::*)(math_Vector &, math_Vector &) const) &BlendFunc_EvolRadInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_EvolRadInv.def("IsSolution", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_EvolRadInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_EvolRadInv.def("NbEquations", (Standard_Integer (BlendFunc_EvolRadInv::*)() const) &BlendFunc_EvolRadInv::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_EvolRadInv.def("Value", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_EvolRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_EvolRadInv.def("Derivatives", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_EvolRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_EvolRadInv.def("Values", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_EvolRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_EvolRadInv.def("Set", (void (BlendFunc_EvolRadInv::*)(const Standard_Integer)) &BlendFunc_EvolRadInv::Set, "None", py::arg("Choix"));

// Enums

}