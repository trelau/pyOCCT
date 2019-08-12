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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Vec.hxx>
#include <GeomFill_Tensor.hxx>
#include <GeomFill_FunctionDraft.hxx>

void bind_GeomFill_FunctionDraft(py::module &mod){

py::class_<GeomFill_FunctionDraft, std::unique_ptr<GeomFill_FunctionDraft, Deleter<GeomFill_FunctionDraft>>, math_FunctionSetWithDerivatives> cls_GeomFill_FunctionDraft(mod, "GeomFill_FunctionDraft", "None");

// Constructors
cls_GeomFill_FunctionDraft.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"));

// Fields

// Methods
// cls_GeomFill_FunctionDraft.def_static("operator new_", (void * (*)(size_t)) &GeomFill_FunctionDraft::operator new, "None", py::arg("theSize"));
// cls_GeomFill_FunctionDraft.def_static("operator delete_", (void (*)(void *)) &GeomFill_FunctionDraft::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_FunctionDraft.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_FunctionDraft::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_FunctionDraft.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_FunctionDraft::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_FunctionDraft.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_FunctionDraft::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_FunctionDraft.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_FunctionDraft::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_FunctionDraft.def("NbVariables", (Standard_Integer (GeomFill_FunctionDraft::*)() const) &GeomFill_FunctionDraft::NbVariables, "returns the number of variables of the function.");
cls_GeomFill_FunctionDraft.def("NbEquations", (Standard_Integer (GeomFill_FunctionDraft::*)() const) &GeomFill_FunctionDraft::NbEquations, "returns the number of equations of the function.");
cls_GeomFill_FunctionDraft.def("Value", (Standard_Boolean (GeomFill_FunctionDraft::*)(const math_Vector &, math_Vector &)) &GeomFill_FunctionDraft::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_GeomFill_FunctionDraft.def("Derivatives", (Standard_Boolean (GeomFill_FunctionDraft::*)(const math_Vector &, math_Matrix &)) &GeomFill_FunctionDraft::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_GeomFill_FunctionDraft.def("Values", (Standard_Boolean (GeomFill_FunctionDraft::*)(const math_Vector &, math_Vector &, math_Matrix &)) &GeomFill_FunctionDraft::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_GeomFill_FunctionDraft.def("DerivT", (Standard_Boolean (GeomFill_FunctionDraft::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real, const gp_Vec &, const Standard_Real, math_Vector &)) &GeomFill_FunctionDraft::DerivT, "returns the values <F> of the T derivatives for the parameter Param .", py::arg("C"), py::arg("Param"), py::arg("W"), py::arg("dN"), py::arg("teta"), py::arg("F"));
cls_GeomFill_FunctionDraft.def("Deriv2T", (Standard_Boolean (GeomFill_FunctionDraft::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real, const gp_Vec &, const Standard_Real, math_Vector &)) &GeomFill_FunctionDraft::Deriv2T, "returns the values <F> of the T2 derivatives for the parameter Param .", py::arg("C"), py::arg("Param"), py::arg("W"), py::arg("d2N"), py::arg("teta"), py::arg("F"));
cls_GeomFill_FunctionDraft.def("DerivTX", (Standard_Boolean (GeomFill_FunctionDraft::*)(const gp_Vec &, const Standard_Real, math_Matrix &)) &GeomFill_FunctionDraft::DerivTX, "returns the values <D> of the TX derivatives for the parameter Param .", py::arg("dN"), py::arg("teta"), py::arg("D"));
cls_GeomFill_FunctionDraft.def("Deriv2X", (Standard_Boolean (GeomFill_FunctionDraft::*)(const math_Vector &, GeomFill_Tensor &)) &GeomFill_FunctionDraft::Deriv2X, "returns the values <T> of the X2 derivatives for the parameter Param .", py::arg("X"), py::arg("T"));

// Enums

}