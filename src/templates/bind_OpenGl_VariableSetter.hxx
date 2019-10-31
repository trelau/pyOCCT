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
#pragma once

#include <pyOCCT_Common.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Context.hxx>
#include <Graphic3d_ShaderVariable.hxx>

template <typename T>
void bind_OpenGl_VariableSetter(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<OpenGl_VariableSetter<T>, OpenGl_SetterInterface> cls_OpenGl_VariableSetter(mod, name.c_str(), "None", local);

// Methods
cls_OpenGl_VariableSetter.def("Set", (void (OpenGl_VariableSetter<T>::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_ShaderVariable> &, OpenGl_ShaderProgram *)) &OpenGl_VariableSetter<T>::Set, "None", py::arg("theCtx"), py::arg("theVariable"), py::arg("theProgram"));

}
