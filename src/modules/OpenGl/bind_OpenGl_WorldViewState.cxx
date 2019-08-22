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
#include <OpenGl_ShaderStates.hxx>
#include <OpenGl_Vec.hxx>

void bind_OpenGl_WorldViewState(py::module &mod){

py::class_<OpenGl_WorldViewState, OpenGl_StateInterface> cls_OpenGl_WorldViewState(mod, "OpenGl_WorldViewState", "Defines state of OCCT world-view transformation.");

// Constructors
cls_OpenGl_WorldViewState.def(py::init<>());

// Fields

// Methods
cls_OpenGl_WorldViewState.def("Set", (void (OpenGl_WorldViewState::*)(const OpenGl_Mat4 &)) &OpenGl_WorldViewState::Set, "Sets new world-view matrix.", py::arg("theWorldViewMatrix"));
cls_OpenGl_WorldViewState.def("WorldViewMatrix", (const OpenGl_Mat4 & (OpenGl_WorldViewState::*)() const) &OpenGl_WorldViewState::WorldViewMatrix, "Returns current world-view matrix.");
cls_OpenGl_WorldViewState.def("WorldViewMatrixInverse", (const OpenGl_Mat4 & (OpenGl_WorldViewState::*)() const) &OpenGl_WorldViewState::WorldViewMatrixInverse, "Returns inverse of current world-view matrix.");

// Enums

}