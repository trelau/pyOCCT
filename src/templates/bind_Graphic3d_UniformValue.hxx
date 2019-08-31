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
#ifndef __Graphic3d_UniformValue__
#define __Graphic3d_UniformValue__

#include <Graphic3d_ShaderVariable.hxx>
#include <Standard_TypeDef.hxx>

template <typename T>
void bind_Graphic3d_UniformValue(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<Graphic3d_UniformValue<T>, Graphic3d_ValueInterface> cls_Graphic3d_UniformValue(mod, name.c_str(), "Describes specific value of custom uniform variable.", local);

// Constructors
cls_Graphic3d_UniformValue.def(py::init<const T &>(), py::arg("theValue"));

// Fields
cls_Graphic3d_UniformValue.def_readwrite("Value", &Graphic3d_UniformValue<T>::Value, "Value of custom uniform variable.");

// Methods
cls_Graphic3d_UniformValue.def("TypeID", (Standard_Size (Graphic3d_UniformValue<T>::*)() const) &Graphic3d_UniformValue<T>::TypeID, "Returns unique identifier of value type.");

}

#endif