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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <Standard_Handle.hxx>
#include <FEmTool_SparseMatrix.hxx>
#include <Standard_Type.hxx>

void bind_FEmTool_SparseMatrix(py::module &mod){

py::class_<FEmTool_SparseMatrix, opencascade::handle<FEmTool_SparseMatrix>, Standard_Transient> cls_FEmTool_SparseMatrix(mod, "FEmTool_SparseMatrix", "Sparse Matrix definition");

// Fields

// Methods
cls_FEmTool_SparseMatrix.def("Init", (void (FEmTool_SparseMatrix::*)(const Standard_Real)) &FEmTool_SparseMatrix::Init, "None", py::arg("Value"));
cls_FEmTool_SparseMatrix.def("ChangeValue", (Standard_Real & (FEmTool_SparseMatrix::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_SparseMatrix::ChangeValue, "None", py::arg("I"), py::arg("J"));
cls_FEmTool_SparseMatrix.def("Decompose", (Standard_Boolean (FEmTool_SparseMatrix::*)()) &FEmTool_SparseMatrix::Decompose, "To make a Factorization of <me>");
cls_FEmTool_SparseMatrix.def("Solve", (void (FEmTool_SparseMatrix::*)(const math_Vector &, math_Vector &) const) &FEmTool_SparseMatrix::Solve, "Direct Solve of AX = B", py::arg("B"), py::arg("X"));
cls_FEmTool_SparseMatrix.def("Prepare", (Standard_Boolean (FEmTool_SparseMatrix::*)()) &FEmTool_SparseMatrix::Prepare, "Make Preparation to iterative solve");
cls_FEmTool_SparseMatrix.def("Solve", [](FEmTool_SparseMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3) -> void { return self.Solve(a0, a1, a2, a3); });
cls_FEmTool_SparseMatrix.def("Solve", [](FEmTool_SparseMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3, const Standard_Real a4) -> void { return self.Solve(a0, a1, a2, a3, a4); });
cls_FEmTool_SparseMatrix.def("Solve", (void (FEmTool_SparseMatrix::*)(const math_Vector &, const math_Vector &, math_Vector &, math_Vector &, const Standard_Real, const Standard_Integer) const) &FEmTool_SparseMatrix::Solve, "Iterative solve of AX = B", py::arg("B"), py::arg("Init"), py::arg("X"), py::arg("Residual"), py::arg("Tolerance"), py::arg("NbIterations"));
cls_FEmTool_SparseMatrix.def("Multiplied", (void (FEmTool_SparseMatrix::*)(const math_Vector &, math_Vector &) const) &FEmTool_SparseMatrix::Multiplied, "returns the product of a SparseMatrix by a vector. An exception is raised if the dimensions are different", py::arg("X"), py::arg("MX"));
cls_FEmTool_SparseMatrix.def("RowNumber", (Standard_Integer (FEmTool_SparseMatrix::*)() const) &FEmTool_SparseMatrix::RowNumber, "returns the row range of a matrix.");
cls_FEmTool_SparseMatrix.def("ColNumber", (Standard_Integer (FEmTool_SparseMatrix::*)() const) &FEmTool_SparseMatrix::ColNumber, "returns the column range of the matrix.");
cls_FEmTool_SparseMatrix.def_static("get_type_name_", (const char * (*)()) &FEmTool_SparseMatrix::get_type_name, "None");
cls_FEmTool_SparseMatrix.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_SparseMatrix::get_type_descriptor, "None");
cls_FEmTool_SparseMatrix.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_SparseMatrix::*)() const) &FEmTool_SparseMatrix::DynamicType, "None");

// Enums

}