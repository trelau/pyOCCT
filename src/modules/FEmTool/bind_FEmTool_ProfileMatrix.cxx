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
#include <FEmTool_SparseMatrix.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <Standard_Handle.hxx>
#include <FEmTool_ProfileMatrix.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array2OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_FEmTool_ProfileMatrix(py::module &mod){

py::class_<FEmTool_ProfileMatrix, opencascade::handle<FEmTool_ProfileMatrix>, FEmTool_SparseMatrix> cls_FEmTool_ProfileMatrix(mod, "FEmTool_ProfileMatrix", "Symmetric Sparse ProfileMatrix useful for 1D Finite Element methods");

// Constructors
cls_FEmTool_ProfileMatrix.def(py::init<const TColStd_Array1OfInteger &>(), py::arg("FirstIndexes"));

// Fields

// Methods
cls_FEmTool_ProfileMatrix.def("Init", (void (FEmTool_ProfileMatrix::*)(const Standard_Real)) &FEmTool_ProfileMatrix::Init, "None", py::arg("Value"));
cls_FEmTool_ProfileMatrix.def("ChangeValue", (Standard_Real & (FEmTool_ProfileMatrix::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_ProfileMatrix::ChangeValue, "None", py::arg("I"), py::arg("J"));
cls_FEmTool_ProfileMatrix.def("Decompose", (Standard_Boolean (FEmTool_ProfileMatrix::*)()) &FEmTool_ProfileMatrix::Decompose, "To make a Factorization of <me>");
cls_FEmTool_ProfileMatrix.def("Solve", (void (FEmTool_ProfileMatrix::*)(const math_Vector &, math_Vector &) const) &FEmTool_ProfileMatrix::Solve, "Direct Solve of AX = B", py::arg("B"), py::arg("X"));
cls_FEmTool_ProfileMatrix.def("Prepare", (Standard_Boolean (FEmTool_ProfileMatrix::*)()) &FEmTool_ProfileMatrix::Prepare, "Make Preparation to iterative solve");
cls_FEmTool_ProfileMatrix.def("Solve", [](FEmTool_ProfileMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3) -> void { return self.Solve(a0, a1, a2, a3); });
cls_FEmTool_ProfileMatrix.def("Solve", [](FEmTool_ProfileMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3, const Standard_Real a4) -> void { return self.Solve(a0, a1, a2, a3, a4); });
cls_FEmTool_ProfileMatrix.def("Solve", (void (FEmTool_ProfileMatrix::*)(const math_Vector &, const math_Vector &, math_Vector &, math_Vector &, const Standard_Real, const Standard_Integer) const) &FEmTool_ProfileMatrix::Solve, "Iterative solve of AX = B", py::arg("B"), py::arg("Init"), py::arg("X"), py::arg("Residual"), py::arg("Tolerance"), py::arg("NbIterations"));
cls_FEmTool_ProfileMatrix.def("Multiplied", (void (FEmTool_ProfileMatrix::*)(const math_Vector &, math_Vector &) const) &FEmTool_ProfileMatrix::Multiplied, "returns the product of a SparseMatrix by a vector. An exception is raised if the dimensions are different", py::arg("X"), py::arg("MX"));
cls_FEmTool_ProfileMatrix.def("RowNumber", (Standard_Integer (FEmTool_ProfileMatrix::*)() const) &FEmTool_ProfileMatrix::RowNumber, "returns the row range of a matrix.");
cls_FEmTool_ProfileMatrix.def("ColNumber", (Standard_Integer (FEmTool_ProfileMatrix::*)() const) &FEmTool_ProfileMatrix::ColNumber, "returns the column range of the matrix.");
cls_FEmTool_ProfileMatrix.def("IsInProfile", (Standard_Boolean (FEmTool_ProfileMatrix::*)(const Standard_Integer, const Standard_Integer) const) &FEmTool_ProfileMatrix::IsInProfile, "None", py::arg("i"), py::arg("j"));
cls_FEmTool_ProfileMatrix.def("OutM", (void (FEmTool_ProfileMatrix::*)() const) &FEmTool_ProfileMatrix::OutM, "None");
cls_FEmTool_ProfileMatrix.def("OutS", (void (FEmTool_ProfileMatrix::*)() const) &FEmTool_ProfileMatrix::OutS, "None");
cls_FEmTool_ProfileMatrix.def_static("get_type_name_", (const char * (*)()) &FEmTool_ProfileMatrix::get_type_name, "None");
cls_FEmTool_ProfileMatrix.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_ProfileMatrix::get_type_descriptor, "None");
cls_FEmTool_ProfileMatrix.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_ProfileMatrix::*)() const) &FEmTool_ProfileMatrix::DynamicType, "None");

// Enums

}