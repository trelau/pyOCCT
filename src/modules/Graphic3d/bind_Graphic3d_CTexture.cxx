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
#include <Standard_Handle.hxx>
#include <Graphic3d_TextureMap.hxx>
#include <Graphic3d_CTexture.hxx>

void bind_Graphic3d_CTexture(py::module &mod){

py::class_<Graphic3d_CTexture> cls_Graphic3d_CTexture(mod, "Graphic3d_CTexture", "None");

// Constructors
cls_Graphic3d_CTexture.def(py::init<>());

// Fields
cls_Graphic3d_CTexture.def_readwrite("TextureMap", &Graphic3d_CTexture::TextureMap, "handle to texture");
cls_Graphic3d_CTexture.def_readwrite("doTextureMap", &Graphic3d_CTexture::doTextureMap, "flag indicates to use texture or not");

// Methods

// Enums

}