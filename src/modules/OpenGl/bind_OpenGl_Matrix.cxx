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
#include <OpenGl_Matrix.hxx>

void bind_OpenGl_Matrix(py::module &mod){

py::class_<OpenGl_Matrix, std::unique_ptr<OpenGl_Matrix, Deleter<OpenGl_Matrix>>> cls_OpenGl_Matrix(mod, "OpenGl_Matrix", "None");

// Constructors

// Fields
// cls_OpenGl_Matrix.def_readwrite("mat", &OpenGl_Matrix::mat, "None");

// Methods
// cls_OpenGl_Matrix.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Matrix::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Matrix.def_static("operator delete_", (void (*)(void *)) &OpenGl_Matrix::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Matrix.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Matrix::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Matrix.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Matrix::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Matrix.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Matrix::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Matrix.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Matrix::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}