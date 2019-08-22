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
#include <NCollection_List.hxx>
#include <OpenGl_ShaderStates.hxx>

void bind_OpenGl_ClippingState(py::module &mod){

py::class_<OpenGl_ClippingState> cls_OpenGl_ClippingState(mod, "OpenGl_ClippingState", "Defines generic state of OCCT clipping state.");

// Constructors
cls_OpenGl_ClippingState.def(py::init<>());

// Fields

// Methods
cls_OpenGl_ClippingState.def("Index", (Standard_Size (OpenGl_ClippingState::*)() const) &OpenGl_ClippingState::Index, "Returns current state index.");
cls_OpenGl_ClippingState.def("Update", (void (OpenGl_ClippingState::*)()) &OpenGl_ClippingState::Update, "Updates current state.");
cls_OpenGl_ClippingState.def("Revert", (void (OpenGl_ClippingState::*)()) &OpenGl_ClippingState::Revert, "Reverts current state.");

// Enums

}