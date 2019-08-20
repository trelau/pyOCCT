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

void bind_OpenGl_OitState(py::module &mod){

py::class_<OpenGl_OitState, std::unique_ptr<OpenGl_OitState>, OpenGl_StateInterface> cls_OpenGl_OitState(mod, "OpenGl_OitState", "Defines generic state of order-independent transparency rendering properties.");

// Constructors
cls_OpenGl_OitState.def(py::init<>());

// Fields

// Methods
cls_OpenGl_OitState.def("Set", (void (OpenGl_OitState::*)(const bool, const float)) &OpenGl_OitState::Set, "Sets the uniform values.", py::arg("theToEnableWrite"), py::arg("theDepthFactor"));
cls_OpenGl_OitState.def("ToEnableWrite", (bool (OpenGl_OitState::*)() const) &OpenGl_OitState::ToEnableWrite, "Returns flag indicating whether writing of output for OIT processing should be enabled/disabled.");
cls_OpenGl_OitState.def("DepthFactor", (float (OpenGl_OitState::*)() const) &OpenGl_OitState::DepthFactor, "Returns factor defining influence of depth component of a fragment to its final coverage coefficient.");

// Enums

}