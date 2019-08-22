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
#ifndef __OpenGl_MatrixState__
#define __OpenGl_MatrixState__

#include <pyOCCT_Common.hxx>
#include <OpenGl_Vec.hxx>
#include <OpenGl_MatrixState.hxx>
#include <NCollection_Vector.hxx>
#include <Standard_TypeDef.hxx>

template <typename T>
void bind_OpenGl_MatrixState(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<OpenGl_MatrixState<T>> cls_OpenGl_MatrixState(mod, name.c_str(), "Software implementation for OpenGL matrix stack.", local);

// Constructors
cls_OpenGl_MatrixState.def(py::init<>());

// Fields

// Methods
cls_OpenGl_MatrixState.def("Push", (void (OpenGl_MatrixState<T>::*)()) &OpenGl_MatrixState<T>::Push, "Pushes current matrix into stack.");
cls_OpenGl_MatrixState.def("Pop", (void (OpenGl_MatrixState<T>::*)()) &OpenGl_MatrixState<T>::Pop, "Pops matrix from stack to current.");
cls_OpenGl_MatrixState.def("Current", (const typename OpenGl::MatrixType<T>::Mat4 & (OpenGl_MatrixState<T>::*)()) &OpenGl_MatrixState<T>::Current, "Returns current matrix.");
cls_OpenGl_MatrixState.def("SetCurrent", (void (OpenGl_MatrixState<T>::*)(const typename OpenGl::MatrixType<T>::Mat4 &)) &OpenGl_MatrixState<T>::SetCurrent, "Sets given matrix as current.", py::arg("theNewCurrent"));
cls_OpenGl_MatrixState.def("ChangeCurrent", (typename OpenGl::MatrixType<T>::Mat4 & (OpenGl_MatrixState<T>::*)()) &OpenGl_MatrixState<T>::ChangeCurrent, "Change current matrix.");
cls_OpenGl_MatrixState.def("SetIdentity", (void (OpenGl_MatrixState<T>::*)()) &OpenGl_MatrixState<T>::SetIdentity, "Sets current matrix to identity.");

// Enums

}

#endif