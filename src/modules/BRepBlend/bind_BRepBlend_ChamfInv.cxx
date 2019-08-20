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
#include <BlendFunc_ChamfInv.hxx>
#include <BRepBlend_ChamfInv.hxx>

void bind_BRepBlend_ChamfInv(py::module &mod){

py::class_<BlendFunc_ChamfInv, std::unique_ptr<BlendFunc_ChamfInv>, Blend_FuncInv> cls_BRepBlend_ChamfInv(mod, "BRepBlend_ChamfInv", "None", py::module_local());

// Constructors
cls_BRepBlend_ChamfInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Fields

// Methods
// cls_BRepBlend_ChamfInv.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_ChamfInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_ChamfInv.def_static("operator delete_", (void (*)(void *)) &BlendFunc_ChamfInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_ChamfInv.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_ChamfInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_ChamfInv.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_ChamfInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_ChamfInv.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_ChamfInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_ChamfInv.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_ChamfInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_ChamfInv.def("Set", (void (BlendFunc_ChamfInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_ChamfInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
cls_BRepBlend_ChamfInv.def("GetTolerance", (void (BlendFunc_ChamfInv::*)(math_Vector &, const Standard_Real) const) &BlendFunc_ChamfInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_ChamfInv.def("GetBounds", (void (BlendFunc_ChamfInv::*)(math_Vector &, math_Vector &) const) &BlendFunc_ChamfInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_ChamfInv.def("IsSolution", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ChamfInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_ChamfInv.def("NbEquations", (Standard_Integer (BlendFunc_ChamfInv::*)() const) &BlendFunc_ChamfInv::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_ChamfInv.def("Value", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_ChamfInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_ChamfInv.def("Derivatives", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ChamfInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_ChamfInv.def("Values", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ChamfInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_ChamfInv.def("Set", (void (BlendFunc_ChamfInv::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_ChamfInv::Set, "None", py::arg("Dist1"), py::arg("Dist2"), py::arg("Choix"));

// Enums

}