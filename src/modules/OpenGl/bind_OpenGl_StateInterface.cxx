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
#include <NCollection_SparseArrayBase.hxx>
#include <OpenGl_ShaderStates.hxx>

void bind_OpenGl_StateInterface(py::module &mod){

py::class_<OpenGl_StateInterface> cls_OpenGl_StateInterface(mod, "OpenGl_StateInterface", "Defines interface for OpenGL state.");

// Constructors
cls_OpenGl_StateInterface.def(py::init<>());

// Fields

// Methods
cls_OpenGl_StateInterface.def("Index", (Standard_Size (OpenGl_StateInterface::*)() const) &OpenGl_StateInterface::Index, "Returns current state index.");
cls_OpenGl_StateInterface.def("Update", (void (OpenGl_StateInterface::*)()) &OpenGl_StateInterface::Update, "Increment current state.");

// Enums

}