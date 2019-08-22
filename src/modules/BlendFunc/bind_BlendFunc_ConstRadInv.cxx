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
#include <Blend_FuncInv.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <BlendFunc_ConstRadInv.hxx>

void bind_BlendFunc_ConstRadInv(py::module &mod){

py::class_<BlendFunc_ConstRadInv, Blend_FuncInv> cls_BlendFunc_ConstRadInv(mod, "BlendFunc_ConstRadInv", "None");

// Constructors
cls_BlendFunc_ConstRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Fields

// Methods
// cls_BlendFunc_ConstRadInv.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_ConstRadInv::operator new, "None", py::arg("theSize"));
// cls_BlendFunc_ConstRadInv.def_static("operator delete_", (void (*)(void *)) &BlendFunc_ConstRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BlendFunc_ConstRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_ConstRadInv::operator new[], "None", py::arg("theSize"));
// cls_BlendFunc_ConstRadInv.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_ConstRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BlendFunc_ConstRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_ConstRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BlendFunc_ConstRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_ConstRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BlendFunc_ConstRadInv.def("Set", (void (BlendFunc_ConstRadInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_ConstRadInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
cls_BlendFunc_ConstRadInv.def("GetTolerance", (void (BlendFunc_ConstRadInv::*)(math_Vector &, const Standard_Real) const) &BlendFunc_ConstRadInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BlendFunc_ConstRadInv.def("GetBounds", (void (BlendFunc_ConstRadInv::*)(math_Vector &, math_Vector &) const) &BlendFunc_ConstRadInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BlendFunc_ConstRadInv.def("IsSolution", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ConstRadInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BlendFunc_ConstRadInv.def("NbEquations", (Standard_Integer (BlendFunc_ConstRadInv::*)() const) &BlendFunc_ConstRadInv::NbEquations, "returns the number of equations of the function.");
cls_BlendFunc_ConstRadInv.def("Value", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_ConstRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BlendFunc_ConstRadInv.def("Derivatives", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ConstRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BlendFunc_ConstRadInv.def("Values", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ConstRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BlendFunc_ConstRadInv.def("Set", (void (BlendFunc_ConstRadInv::*)(const Standard_Real, const Standard_Integer)) &BlendFunc_ConstRadInv::Set, "None", py::arg("R"), py::arg("Choix"));

// Enums

}