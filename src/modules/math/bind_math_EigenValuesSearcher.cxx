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
#include <TColStd_Array1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <math_EigenValuesSearcher.hxx>

void bind_math_EigenValuesSearcher(py::module &mod){

py::class_<math_EigenValuesSearcher, std::unique_ptr<math_EigenValuesSearcher, Deleter<math_EigenValuesSearcher>>> cls_math_EigenValuesSearcher(mod, "math_EigenValuesSearcher", "This class finds eigen values and vectors of real symmetric tridiagonal matrix");

// Constructors
cls_math_EigenValuesSearcher.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("Diagonal"), py::arg("Subdiagonal"));

// Fields

// Methods
// cls_math_EigenValuesSearcher.def_static("operator new_", (void * (*)(size_t)) &math_EigenValuesSearcher::operator new, "None", py::arg("theSize"));
// cls_math_EigenValuesSearcher.def_static("operator delete_", (void (*)(void *)) &math_EigenValuesSearcher::operator delete, "None", py::arg("theAddress"));
// cls_math_EigenValuesSearcher.def_static("operator new[]_", (void * (*)(size_t)) &math_EigenValuesSearcher::operator new[], "None", py::arg("theSize"));
// cls_math_EigenValuesSearcher.def_static("operator delete[]_", (void (*)(void *)) &math_EigenValuesSearcher::operator delete[], "None", py::arg("theAddress"));
// cls_math_EigenValuesSearcher.def_static("operator new_", (void * (*)(size_t, void *)) &math_EigenValuesSearcher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_EigenValuesSearcher.def_static("operator delete_", (void (*)(void *, void *)) &math_EigenValuesSearcher::operator delete, "None", py::arg(""), py::arg(""));
cls_math_EigenValuesSearcher.def("IsDone", (Standard_Boolean (math_EigenValuesSearcher::*)() const) &math_EigenValuesSearcher::IsDone, "Returns Standard_True if computation is performed successfully.");
cls_math_EigenValuesSearcher.def("Dimension", (Standard_Integer (math_EigenValuesSearcher::*)() const) &math_EigenValuesSearcher::Dimension, "Returns the dimension of matrix");
cls_math_EigenValuesSearcher.def("EigenValue", (Standard_Real (math_EigenValuesSearcher::*)(const Standard_Integer) const) &math_EigenValuesSearcher::EigenValue, "Returns the Index_th eigen value of matrix Index must be in [1, Dimension()]", py::arg("Index"));
cls_math_EigenValuesSearcher.def("EigenVector", (math_Vector (math_EigenValuesSearcher::*)(const Standard_Integer) const) &math_EigenValuesSearcher::EigenVector, "Returns the Index_th eigen vector of matrix Index must be in [1, Dimension()]", py::arg("Index"));

// Enums

}