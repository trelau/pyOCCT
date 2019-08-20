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
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <BlendFunc_Tensor.hxx>

void bind_BlendFunc_Tensor(py::module &mod){

py::class_<BlendFunc_Tensor, std::unique_ptr<BlendFunc_Tensor>> cls_BlendFunc_Tensor(mod, "BlendFunc_Tensor", "used to store the 'gradient of gradient'");

// Constructors
cls_BlendFunc_Tensor.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("NbRow"), py::arg("NbCol"), py::arg("NbMat"));

// Fields

// Methods
// cls_BlendFunc_Tensor.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_Tensor::operator new, "None", py::arg("theSize"));
// cls_BlendFunc_Tensor.def_static("operator delete_", (void (*)(void *)) &BlendFunc_Tensor::operator delete, "None", py::arg("theAddress"));
// cls_BlendFunc_Tensor.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_Tensor::operator new[], "None", py::arg("theSize"));
// cls_BlendFunc_Tensor.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_Tensor::operator delete[], "None", py::arg("theAddress"));
// cls_BlendFunc_Tensor.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_Tensor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BlendFunc_Tensor.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_Tensor::operator delete, "None", py::arg(""), py::arg(""));
cls_BlendFunc_Tensor.def("Init", (void (BlendFunc_Tensor::*)(const Standard_Real)) &BlendFunc_Tensor::Init, "Initialize all the elements of a Tensor to InitialValue.", py::arg("InitialValue"));
cls_BlendFunc_Tensor.def("Value", (const Standard_Real & (BlendFunc_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &BlendFunc_Tensor::Value, "accesses (in read or write mode) the value of index <Row>, <Col> and <Mat> of a Tensor. An exception is raised if <Row>, <Col> or <Mat> are not in the correct range.", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
cls_BlendFunc_Tensor.def("__call__", (const Standard_Real & (BlendFunc_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &BlendFunc_Tensor::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
cls_BlendFunc_Tensor.def("ChangeValue", (Standard_Real & (BlendFunc_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &BlendFunc_Tensor::ChangeValue, "accesses (in read or write mode) the value of index <Row>, <Col> and <Mat> of a Tensor. An exception is raised if <Row>, <Col> or <Mat> are not in the correct range.", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
cls_BlendFunc_Tensor.def("__call__", (Standard_Real & (BlendFunc_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &BlendFunc_Tensor::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
cls_BlendFunc_Tensor.def("Multiply", (void (BlendFunc_Tensor::*)(const math_Vector &, math_Matrix &) const) &BlendFunc_Tensor::Multiply, "None", py::arg("Right"), py::arg("Product"));

// Enums

}