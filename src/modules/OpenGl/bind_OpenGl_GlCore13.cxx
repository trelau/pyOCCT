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
#include <OpenGl_GlCore12.hxx>
#include <OpenGl_GlFunctions.hxx>
#include <OpenGl_GlCore13.hxx>

void bind_OpenGl_GlCore13(py::module &mod){

py::class_<OpenGl_GlCore13, std::unique_ptr<OpenGl_GlCore13>> cls_OpenGl_GlCore13(mod, "OpenGl_GlCore13", "OpenGL 1.3 core based on 1.2 version.");

// Constructors

// Fields

// Methods

// Enums

}