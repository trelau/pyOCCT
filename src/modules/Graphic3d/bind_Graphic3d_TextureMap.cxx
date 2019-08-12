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
#include <Standard_TypeDef.hxx>
#include <Graphic3d_LevelOfTextureAnisotropy.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_TextureMap.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <Graphic3d_TypeOfTexture.hxx>
#include <Image_PixMap.hxx>

void bind_Graphic3d_TextureMap(py::module &mod){

py::class_<Graphic3d_TextureMap, opencascade::handle<Graphic3d_TextureMap>, Graphic3d_TextureRoot> cls_Graphic3d_TextureMap(mod, "Graphic3d_TextureMap", "This is an abstract class for managing texture applyable on polygons.");

// Constructors

// Fields

// Methods
cls_Graphic3d_TextureMap.def("EnableSmooth", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::EnableSmooth, "enable texture smoothing");
cls_Graphic3d_TextureMap.def("IsSmoothed", (Standard_Boolean (Graphic3d_TextureMap::*)() const) &Graphic3d_TextureMap::IsSmoothed, "Returns TRUE if the texture is smoothed.");
cls_Graphic3d_TextureMap.def("DisableSmooth", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::DisableSmooth, "disable texture smoothing");
cls_Graphic3d_TextureMap.def("EnableModulate", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::EnableModulate, "enable texture modulate mode. the image is modulate with the shading of the surface.");
cls_Graphic3d_TextureMap.def("DisableModulate", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::DisableModulate, "disable texture modulate mode. the image is directly decal on the surface.");
cls_Graphic3d_TextureMap.def("IsModulate", (Standard_Boolean (Graphic3d_TextureMap::*)() const) &Graphic3d_TextureMap::IsModulate, "Returns TRUE if the texture is modulate.");
cls_Graphic3d_TextureMap.def("EnableRepeat", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::EnableRepeat, "use this methods if you want to enable texture repetition on your objects.");
cls_Graphic3d_TextureMap.def("DisableRepeat", (void (Graphic3d_TextureMap::*)()) &Graphic3d_TextureMap::DisableRepeat, "use this methods if you want to disable texture repetition on your objects.");
cls_Graphic3d_TextureMap.def("IsRepeat", (Standard_Boolean (Graphic3d_TextureMap::*)() const) &Graphic3d_TextureMap::IsRepeat, "Returns TRUE if the texture repeat is enable.");
cls_Graphic3d_TextureMap.def("AnisoFilter", (Graphic3d_LevelOfTextureAnisotropy (Graphic3d_TextureMap::*)() const) &Graphic3d_TextureMap::AnisoFilter, "Returns level of anisontropy texture filter. Default value is Graphic3d_LOTA_OFF.");
cls_Graphic3d_TextureMap.def("SetAnisoFilter", (void (Graphic3d_TextureMap::*)(const Graphic3d_LevelOfTextureAnisotropy)) &Graphic3d_TextureMap::SetAnisoFilter, "", py::arg("theLevel"));
cls_Graphic3d_TextureMap.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TextureMap::get_type_name, "None");
cls_Graphic3d_TextureMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TextureMap::get_type_descriptor, "None");
cls_Graphic3d_TextureMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TextureMap::*)() const) &Graphic3d_TextureMap::DynamicType, "None");

// Enums

}