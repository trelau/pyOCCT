/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#ifndef __Graphic3d_Templates_Header__
#define __Graphic3d_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <Graphic3d_ShaderVariable.hxx>
#include <Standard_TypeDef.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
template <typename T>
void bind_Graphic3d_UniformValue(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_UniformValue<T>, std::unique_ptr<Graphic3d_UniformValue<T>, Deleter<Graphic3d_UniformValue<T>>>, Graphic3d_ValueInterface> cls(mod, name.c_str(), "Describes specific value of custom uniform variable.");
	cls.def(py::init<const T &>(), py::arg("theValue"));
	cls.def("TypeID", (Standard_Size (Graphic3d_UniformValue<T>::*)() const ) &Graphic3d_UniformValue<T>::TypeID, "Returns unique identifier of value type.");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
template <typename T>
void bind_Graphic3d_UniformValueTypeID(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\Graphic3d_ShaderVariable.hxx
	py::class_<Graphic3d_UniformValueTypeID<T>, std::unique_ptr<Graphic3d_UniformValueTypeID<T>, Deleter<Graphic3d_UniformValueTypeID<T>>>> cls(mod, name.c_str(), "Generates unique type identifier for variable value.");
	cls.def(py::init<>());

};

#endif