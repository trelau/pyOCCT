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
#include <OpenGl_GlFunctions.hxx>
#include <OpenGl_ArbTexBindless.hxx>

void bind_OpenGl_ArbTexBindless(py::module &mod){

py::class_<OpenGl_ArbTexBindless, std::unique_ptr<OpenGl_ArbTexBindless, Deleter<OpenGl_ArbTexBindless>>> cls_OpenGl_ArbTexBindless(mod, "OpenGl_ArbTexBindless", "Provides bindless textures. This extension allows OpenGL applications to access texture objects in shaders without first binding each texture to one of a limited number of texture image units.");

// Constructors

// Fields

// Methods

// Enums

}