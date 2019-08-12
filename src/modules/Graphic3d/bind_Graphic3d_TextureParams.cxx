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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_TextureParams.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_TextureUnit.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_TypeOfTextureFilter.hxx>
#include <Graphic3d_LevelOfTextureAnisotropy.hxx>
#include <Graphic3d_Vec2.hxx>
#include <Graphic3d_TypeOfTextureMode.hxx>
#include <Graphic3d_Vec4.hxx>

void bind_Graphic3d_TextureParams(py::module &mod){

py::class_<Graphic3d_TextureParams, opencascade::handle<Graphic3d_TextureParams>, Standard_Transient> cls_Graphic3d_TextureParams(mod, "Graphic3d_TextureParams", "This class describes texture parameters.");

// Constructors
cls_Graphic3d_TextureParams.def(py::init<>());

// Fields

// Methods
cls_Graphic3d_TextureParams.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TextureParams::get_type_name, "None");
cls_Graphic3d_TextureParams.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TextureParams::get_type_descriptor, "None");
cls_Graphic3d_TextureParams.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::DynamicType, "None");
cls_Graphic3d_TextureParams.def("TextureUnit", (Graphic3d_TextureUnit (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::TextureUnit, "Default texture unit to be used, default is Graphic3d_TextureUnit_BaseColor.");
cls_Graphic3d_TextureParams.def("SetTextureUnit", (void (Graphic3d_TextureParams::*)(Graphic3d_TextureUnit)) &Graphic3d_TextureParams::SetTextureUnit, "Setup default texture unit.", py::arg("theUnit"));
cls_Graphic3d_TextureParams.def("IsModulate", (Standard_Boolean (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::IsModulate, "Returns TRUE if the texture is modulate. Default value is FALSE.");
cls_Graphic3d_TextureParams.def("SetModulate", (void (Graphic3d_TextureParams::*)(const Standard_Boolean)) &Graphic3d_TextureParams::SetModulate, "", py::arg("theToModulate"));
cls_Graphic3d_TextureParams.def("IsRepeat", (Standard_Boolean (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::IsRepeat, "Returns TRUE if the texture repeat is enabled. Default value is FALSE.");
cls_Graphic3d_TextureParams.def("SetRepeat", (void (Graphic3d_TextureParams::*)(const Standard_Boolean)) &Graphic3d_TextureParams::SetRepeat, "", py::arg("theToRepeat"));
cls_Graphic3d_TextureParams.def("Filter", (Graphic3d_TypeOfTextureFilter (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::Filter, "Returns texture interpolation filter. Default value is Graphic3d_TOTF_NEAREST.");
cls_Graphic3d_TextureParams.def("SetFilter", (void (Graphic3d_TextureParams::*)(const Graphic3d_TypeOfTextureFilter)) &Graphic3d_TextureParams::SetFilter, "", py::arg("theFilter"));
cls_Graphic3d_TextureParams.def("AnisoFilter", (Graphic3d_LevelOfTextureAnisotropy (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::AnisoFilter, "Returns level of anisontropy texture filter. Default value is Graphic3d_LOTA_OFF.");
cls_Graphic3d_TextureParams.def("SetAnisoFilter", (void (Graphic3d_TextureParams::*)(const Graphic3d_LevelOfTextureAnisotropy)) &Graphic3d_TextureParams::SetAnisoFilter, "", py::arg("theLevel"));
cls_Graphic3d_TextureParams.def("Rotation", (Standard_ShortReal (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::Rotation, "Returns rotation angle in degrees Default value is 0.");
cls_Graphic3d_TextureParams.def("SetRotation", (void (Graphic3d_TextureParams::*)(const Standard_ShortReal)) &Graphic3d_TextureParams::SetRotation, "", py::arg("theAngleDegrees"));
cls_Graphic3d_TextureParams.def("Scale", (const Graphic3d_Vec2 & (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::Scale, "Returns scale factor Default value is no scaling (1.0; 1.0).");
cls_Graphic3d_TextureParams.def("SetScale", (void (Graphic3d_TextureParams::*)(const Graphic3d_Vec2)) &Graphic3d_TextureParams::SetScale, "", py::arg("theScale"));
cls_Graphic3d_TextureParams.def("Translation", (const Graphic3d_Vec2 & (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::Translation, "Returns translation vector Default value is no translation (0.0; 0.0).");
cls_Graphic3d_TextureParams.def("SetTranslation", (void (Graphic3d_TextureParams::*)(const Graphic3d_Vec2)) &Graphic3d_TextureParams::SetTranslation, "", py::arg("theVec"));
cls_Graphic3d_TextureParams.def("GenMode", (Graphic3d_TypeOfTextureMode (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::GenMode, "Returns texture coordinates generation mode. Default value is Graphic3d_TOTM_MANUAL.");
cls_Graphic3d_TextureParams.def("GenPlaneS", (const Graphic3d_Vec4 & (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::GenPlaneS, "Returns texture coordinates generation plane S.");
cls_Graphic3d_TextureParams.def("GenPlaneT", (const Graphic3d_Vec4 & (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::GenPlaneT, "Returns texture coordinates generation plane T.");
cls_Graphic3d_TextureParams.def("SetGenMode", (void (Graphic3d_TextureParams::*)(const Graphic3d_TypeOfTextureMode, const Graphic3d_Vec4, const Graphic3d_Vec4)) &Graphic3d_TextureParams::SetGenMode, "Setup texture coordinates generation mode.", py::arg("theMode"), py::arg("thePlaneS"), py::arg("thePlaneT"));
cls_Graphic3d_TextureParams.def("SamplerRevision", (unsigned int (Graphic3d_TextureParams::*)() const) &Graphic3d_TextureParams::SamplerRevision, "Return modification counter of parameters related to sampler state.");

// Enums

}