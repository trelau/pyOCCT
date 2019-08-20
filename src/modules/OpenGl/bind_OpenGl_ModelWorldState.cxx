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

void bind_OpenGl_ModelWorldState(py::module &mod){

py::class_<OpenGl_ModelWorldState, std::unique_ptr<OpenGl_ModelWorldState>, OpenGl_StateInterface> cls_OpenGl_ModelWorldState(mod, "OpenGl_ModelWorldState", "Defines state of OCCT model-world transformation.");

// Constructors
cls_OpenGl_ModelWorldState.def(py::init<>());

// Fields

// Methods
cls_OpenGl_ModelWorldState.def("Set", (void (OpenGl_ModelWorldState::*)(const OpenGl_Mat4 &)) &OpenGl_ModelWorldState::Set, "Sets new model-world matrix.", py::arg("theModelWorldMatrix"));
cls_OpenGl_ModelWorldState.def("ModelWorldMatrix", (const OpenGl_Mat4 & (OpenGl_ModelWorldState::*)() const) &OpenGl_ModelWorldState::ModelWorldMatrix, "Returns current model-world matrix.");
cls_OpenGl_ModelWorldState.def("ModelWorldMatrixInverse", (const OpenGl_Mat4 & (OpenGl_ModelWorldState::*)() const) &OpenGl_ModelWorldState::ModelWorldMatrixInverse, "Returns inverse of current model-world matrix.");

// Enums

}