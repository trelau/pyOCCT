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

void bind_OpenGl_ProjectionState(py::module &mod){

py::class_<OpenGl_ProjectionState, std::unique_ptr<OpenGl_ProjectionState, Deleter<OpenGl_ProjectionState>>, OpenGl_StateInterface> cls_OpenGl_ProjectionState(mod, "OpenGl_ProjectionState", "Defines state of OCCT projection transformation.");

// Constructors
cls_OpenGl_ProjectionState.def(py::init<>());

// Fields

// Methods
cls_OpenGl_ProjectionState.def("Set", (void (OpenGl_ProjectionState::*)(const OpenGl_Mat4 &)) &OpenGl_ProjectionState::Set, "Sets new projection matrix.", py::arg("theProjectionMatrix"));
cls_OpenGl_ProjectionState.def("ProjectionMatrix", (const OpenGl_Mat4 & (OpenGl_ProjectionState::*)() const) &OpenGl_ProjectionState::ProjectionMatrix, "Returns current projection matrix.");
cls_OpenGl_ProjectionState.def("ProjectionMatrixInverse", (const OpenGl_Mat4 & (OpenGl_ProjectionState::*)() const) &OpenGl_ProjectionState::ProjectionMatrixInverse, "Returns inverse of current projection matrix.");

// Enums

}