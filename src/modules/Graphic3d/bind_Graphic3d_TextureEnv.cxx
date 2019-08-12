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
#include <Graphic3d_TextureRoot.hxx>
#include <TCollection_AsciiString.hxx>
#include <Graphic3d_NameOfTextureEnv.hxx>
#include <Standard_Handle.hxx>
#include <Image_PixMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_TextureEnv.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_TextureEnv(py::module &mod){

py::class_<Graphic3d_TextureEnv, opencascade::handle<Graphic3d_TextureEnv>, Graphic3d_TextureRoot> cls_Graphic3d_TextureEnv(mod, "Graphic3d_TextureEnv", "This class provides environment texture.");

// Constructors
cls_Graphic3d_TextureEnv.def(py::init<const TCollection_AsciiString &>(), py::arg("theFileName"));
cls_Graphic3d_TextureEnv.def(py::init<const Graphic3d_NameOfTextureEnv>(), py::arg("theName"));
cls_Graphic3d_TextureEnv.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("thePixMap"));

// Fields

// Methods
cls_Graphic3d_TextureEnv.def("Name", (Graphic3d_NameOfTextureEnv (Graphic3d_TextureEnv::*)() const) &Graphic3d_TextureEnv::Name, "Returns the name of the predefined textures or NOT_ENV_UNKNOWN when the name is given as a filename.");
cls_Graphic3d_TextureEnv.def_static("NumberOfTextures_", (Standard_Integer (*)()) &Graphic3d_TextureEnv::NumberOfTextures, "Returns the number of predefined textures.");
cls_Graphic3d_TextureEnv.def_static("TextureName_", (TCollection_AsciiString (*)(const Standard_Integer)) &Graphic3d_TextureEnv::TextureName, "Returns the name of the predefined texture of rank <aRank>", py::arg("theRank"));
cls_Graphic3d_TextureEnv.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TextureEnv::get_type_name, "None");
cls_Graphic3d_TextureEnv.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TextureEnv::get_type_descriptor, "None");
cls_Graphic3d_TextureEnv.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TextureEnv::*)() const) &Graphic3d_TextureEnv::DynamicType, "None");

// Enums

}