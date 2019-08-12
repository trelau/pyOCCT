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
#include <Standard_Handle.hxx>
#include <Graphic3d_LightSet.hxx>

void bind_OpenGl_LightSourceState(py::module &mod){

py::class_<OpenGl_LightSourceState, std::unique_ptr<OpenGl_LightSourceState, Deleter<OpenGl_LightSourceState>>, OpenGl_StateInterface> cls_OpenGl_LightSourceState(mod, "OpenGl_LightSourceState", "Defines state of OCCT light sources.");

// Constructors
cls_OpenGl_LightSourceState.def(py::init<>());

// Fields

// Methods
cls_OpenGl_LightSourceState.def("Set", (void (OpenGl_LightSourceState::*)(const opencascade::handle<Graphic3d_LightSet> &)) &OpenGl_LightSourceState::Set, "Sets new light sources.", py::arg("theLightSources"));
cls_OpenGl_LightSourceState.def("LightSources", (const opencascade::handle<Graphic3d_LightSet> & (OpenGl_LightSourceState::*)() const) &OpenGl_LightSourceState::LightSources, "Returns current list of light sources.");

// Enums

}