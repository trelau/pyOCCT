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
#include <Standard.hxx>
#include <TColStd_Array2OfInteger.hxx>
#include <Standard_Handle.hxx>
#include <FEmTool_HAssemblyTable.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <FEmTool_ProfileMatrix.hxx>
#include <FEmTool_SeqOfLinConstr.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <FEmTool_Assembly.hxx>

void bind_FEmTool_Assembly(py::module &mod){

py::class_<FEmTool_Assembly> cls_FEmTool_Assembly(mod, "FEmTool_Assembly", "Assemble and solve system from (one dimensional) Finite Elements");

// Constructors
cls_FEmTool_Assembly.def(py::init<const TColStd_Array2OfInteger &, const opencascade::handle<FEmTool_HAssemblyTable> &>(), py::arg("Dependence"), py::arg("Table"));

// Fields

// Methods
// cls_FEmTool_Assembly.def_static("operator new_", (void * (*)(size_t)) &FEmTool_Assembly::operator new, "None", py::arg("theSize"));
// cls_FEmTool_Assembly.def_static("operator delete_", (void (*)(void *)) &FEmTool_Assembly::operator delete, "None", py::arg("theAddress"));
// cls_FEmTool_Assembly.def_static("operator new[]_", (void * (*)(size_t)) &FEmTool_Assembly::operator new[], "None", py::arg("theSize"));
// cls_FEmTool_Assembly.def_static("operator delete[]_", (void (*)(void *)) &FEmTool_Assembly::operator delete[], "None", py::arg("theAddress"));
// cls_FEmTool_Assembly.def_static("operator new_", (void * (*)(size_t, void *)) &FEmTool_Assembly::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FEmTool_Assembly.def_static("operator delete_", (void (*)(void *, void *)) &FEmTool_Assembly::operator delete, "None", py::arg(""), py::arg(""));
cls_FEmTool_Assembly.def("NullifyMatrix", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::NullifyMatrix, "Nullify all Matrix 's Coefficient");
cls_FEmTool_Assembly.def("AddMatrix", (void (FEmTool_Assembly::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const math_Matrix &)) &FEmTool_Assembly::AddMatrix, "Add an elementary Matrix in the assembly Matrix if Dependence(Dimension1,Dimension2) is False", py::arg("Element"), py::arg("Dimension1"), py::arg("Dimension2"), py::arg("Mat"));
cls_FEmTool_Assembly.def("NullifyVector", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::NullifyVector, "Nullify all Coordinate of assembly Vector (second member)");
cls_FEmTool_Assembly.def("AddVector", (void (FEmTool_Assembly::*)(const Standard_Integer, const Standard_Integer, const math_Vector &)) &FEmTool_Assembly::AddVector, "Add an elementary Vector in the assembly Vector (second member)", py::arg("Element"), py::arg("Dimension"), py::arg("Vec"));
cls_FEmTool_Assembly.def("ResetConstraint", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::ResetConstraint, "Delete all Constraints.");
cls_FEmTool_Assembly.def("NullifyConstraint", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::NullifyConstraint, "Nullify all Constraints.");
cls_FEmTool_Assembly.def("AddConstraint", (void (FEmTool_Assembly::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const math_Vector &, const Standard_Real)) &FEmTool_Assembly::AddConstraint, "None", py::arg("IndexofConstraint"), py::arg("Element"), py::arg("Dimension"), py::arg("LinearForm"), py::arg("Value"));
cls_FEmTool_Assembly.def("Solve", (Standard_Boolean (FEmTool_Assembly::*)()) &FEmTool_Assembly::Solve, "Solve the assembly system Returns Standard_False if the computation failed.");
cls_FEmTool_Assembly.def("Solution", (void (FEmTool_Assembly::*)(math_Vector &) const) &FEmTool_Assembly::Solution, "None", py::arg("Solution"));
cls_FEmTool_Assembly.def("NbGlobVar", (Standard_Integer (FEmTool_Assembly::*)() const) &FEmTool_Assembly::NbGlobVar, "None");
cls_FEmTool_Assembly.def("GetAssemblyTable", (void (FEmTool_Assembly::*)(opencascade::handle<FEmTool_HAssemblyTable> &) const) &FEmTool_Assembly::GetAssemblyTable, "None", py::arg("AssTable"));

// Enums

}