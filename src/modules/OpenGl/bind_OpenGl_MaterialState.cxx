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
#include <OpenGl_Material.hxx>
#include <OpenGl_MaterialState.hxx>

void bind_OpenGl_MaterialState(py::module &mod){

py::class_<OpenGl_MaterialState, OpenGl_StateInterface> cls_OpenGl_MaterialState(mod, "OpenGl_MaterialState", "Defines generic state of material properties.");

// Constructors
cls_OpenGl_MaterialState.def(py::init<>());

// Fields

// Methods
cls_OpenGl_MaterialState.def("Set", (void (OpenGl_MaterialState::*)(const OpenGl_Material &, const OpenGl_Material &, const float, const bool, const bool)) &OpenGl_MaterialState::Set, "Sets new material aspect.", py::arg("theFrontMat"), py::arg("theBackMat"), py::arg("theAlphaCutoff"), py::arg("theToDistinguish"), py::arg("theToMapTexture"));
cls_OpenGl_MaterialState.def("FrontMaterial", (const OpenGl_Material & (OpenGl_MaterialState::*)() const) &OpenGl_MaterialState::FrontMaterial, "Return front material.");
cls_OpenGl_MaterialState.def("BackMaterial", (const OpenGl_Material & (OpenGl_MaterialState::*)() const) &OpenGl_MaterialState::BackMaterial, "Return back material.");
cls_OpenGl_MaterialState.def("AlphaCutoff", (float (OpenGl_MaterialState::*)() const) &OpenGl_MaterialState::AlphaCutoff, "Alpha cutoff value.");
cls_OpenGl_MaterialState.def("ToDistinguish", (bool (OpenGl_MaterialState::*)() const) &OpenGl_MaterialState::ToDistinguish, "Distinguish front/back flag.");
cls_OpenGl_MaterialState.def("ToMapTexture", (bool (OpenGl_MaterialState::*)() const) &OpenGl_MaterialState::ToMapTexture, "Flag for mapping a texture.");

// Enums

}