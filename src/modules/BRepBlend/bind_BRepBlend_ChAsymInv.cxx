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
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <BlendFunc_ChAsymInv.hxx>
#include <BRepBlend_ChAsymInv.hxx>

void bind_BRepBlend_ChAsymInv(py::module &mod){

py::class_<BlendFunc_ChAsymInv, std::unique_ptr<BlendFunc_ChAsymInv, Deleter<BlendFunc_ChAsymInv>>, Blend_FuncInv> cls_BRepBlend_ChAsymInv(mod, "BRepBlend_ChAsymInv", "None", py::module_local());

// Constructors
cls_BRepBlend_ChAsymInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Fields

// Methods
// cls_BRepBlend_ChAsymInv.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_ChAsymInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_ChAsymInv.def_static("operator delete_", (void (*)(void *)) &BlendFunc_ChAsymInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_ChAsymInv.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_ChAsymInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_ChAsymInv.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_ChAsymInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_ChAsymInv.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_ChAsymInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_ChAsymInv.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_ChAsymInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_ChAsymInv.def("Set", (void (BlendFunc_ChAsymInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_ChAsymInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
cls_BRepBlend_ChAsymInv.def("GetTolerance", (void (BlendFunc_ChAsymInv::*)(math_Vector &, const Standard_Real) const) &BlendFunc_ChAsymInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_ChAsymInv.def("GetBounds", (void (BlendFunc_ChAsymInv::*)(math_Vector &, math_Vector &) const) &BlendFunc_ChAsymInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_ChAsymInv.def("IsSolution", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ChAsymInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_ChAsymInv.def("NbEquations", (Standard_Integer (BlendFunc_ChAsymInv::*)() const) &BlendFunc_ChAsymInv::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_ChAsymInv.def("ComputeValues", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, const Standard_Integer, const Standard_Integer)) &BlendFunc_ChAsymInv::ComputeValues, "computes the values <F> of the derivatives for the variable <X> between DegF and DegL. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("DegF"), py::arg("DegL"));
cls_BRepBlend_ChAsymInv.def("Value", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_ChAsymInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_ChAsymInv.def("Derivatives", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ChAsymInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_ChAsymInv.def("Values", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ChAsymInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_ChAsymInv.def("Set", (void (BlendFunc_ChAsymInv::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_ChAsymInv::Set, "None", py::arg("Dist1"), py::arg("Angle"), py::arg("Choix"));

// Enums

}