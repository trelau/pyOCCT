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
#include <Graphic3d_TextureMap.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_Texture2D.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Graphic3d_NameOfTexture2D.hxx>
#include <Image_PixMap.hxx>
#include <Graphic3d_TypeOfTexture.hxx>

void bind_Graphic3d_Texture2D(py::module &mod){

py::class_<Graphic3d_Texture2D, opencascade::handle<Graphic3d_Texture2D>, Graphic3d_TextureMap> cls_Graphic3d_Texture2D(mod, "Graphic3d_Texture2D", "This abstract class for managing 2D textures");

// Constructors

// Fields

// Methods
cls_Graphic3d_Texture2D.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Texture2D::get_type_name, "None");
cls_Graphic3d_Texture2D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Texture2D::get_type_descriptor, "None");
cls_Graphic3d_Texture2D.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Texture2D::*)() const) &Graphic3d_Texture2D::DynamicType, "None");
cls_Graphic3d_Texture2D.def_static("NumberOfTextures_", (Standard_Integer (*)()) &Graphic3d_Texture2D::NumberOfTextures, "Returns the number of predefined textures.");
cls_Graphic3d_Texture2D.def_static("TextureName_", (TCollection_AsciiString (*)(const Standard_Integer)) &Graphic3d_Texture2D::TextureName, "Returns the name of the predefined texture of rank <aRank>", py::arg("theRank"));
cls_Graphic3d_Texture2D.def("Name", (Graphic3d_NameOfTexture2D (Graphic3d_Texture2D::*)() const) &Graphic3d_Texture2D::Name, "Returns the name of the predefined textures or NOT_2D_UNKNOWN when the name is given as a filename.");
cls_Graphic3d_Texture2D.def("SetImage", (void (Graphic3d_Texture2D::*)(const opencascade::handle<Image_PixMap> &)) &Graphic3d_Texture2D::SetImage, "Assign new image to the texture. Note that this method does not invalidate already uploaded resources - consider calling ::UpdateRevision() if needed.", py::arg("thePixMap"));
cls_Graphic3d_Texture2D.def("HasMipMaps", (Standard_Boolean (Graphic3d_Texture2D::*)() const) &Graphic3d_Texture2D::HasMipMaps, "Return true if mip-maps should be used.");
cls_Graphic3d_Texture2D.def("SetMipMaps", (void (Graphic3d_Texture2D::*)(const Standard_Boolean)) &Graphic3d_Texture2D::SetMipMaps, "Set if mip-maps should be used (generated if needed). Note that this method should be called before loading / using the texture.", py::arg("theToUse"));

// Enums

}