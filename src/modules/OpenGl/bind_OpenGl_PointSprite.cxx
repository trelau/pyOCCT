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
#include <OpenGl_Texture.hxx>
#include <TCollection_AsciiString.hxx>
#include <OpenGl_Context.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_PointSprite.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_PointSprite(py::module &mod){

py::class_<OpenGl_PointSprite, opencascade::handle<OpenGl_PointSprite>, OpenGl_Texture> cls_OpenGl_PointSprite(mod, "OpenGl_PointSprite", "Point sprite resource. On modern hardware it will be texture with extra parameters. On ancient hardware sprites will be drawn using bitmaps.");

// Constructors
cls_OpenGl_PointSprite.def(py::init<const TCollection_AsciiString &>(), py::arg("theResourceId"));

// Fields

// Methods
cls_OpenGl_PointSprite.def("Release", (void (OpenGl_PointSprite::*)(OpenGl_Context *)) &OpenGl_PointSprite::Release, "Destroy object - will release GPU memory if any.", py::arg("theCtx"));
cls_OpenGl_PointSprite.def("IsDisplayList", (Standard_Boolean (OpenGl_PointSprite::*)() const) &OpenGl_PointSprite::IsDisplayList, "Returns true if this is display list bitmap");
cls_OpenGl_PointSprite.def("DrawBitmap", (void (OpenGl_PointSprite::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_PointSprite::DrawBitmap, "Draw sprite using glBitmap. Please call glRasterPos3fv() before to setup sprite position.", py::arg("theCtx"));
cls_OpenGl_PointSprite.def("SetDisplayList", (void (OpenGl_PointSprite::*)(const opencascade::handle<OpenGl_Context> &, const GLuint)) &OpenGl_PointSprite::SetDisplayList, "Initialize point sprite as display list", py::arg("theCtx"), py::arg("theBitmapList"));
cls_OpenGl_PointSprite.def_static("get_type_name_", (const char * (*)()) &OpenGl_PointSprite::get_type_name, "None");
cls_OpenGl_PointSprite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_PointSprite::get_type_descriptor, "None");
cls_OpenGl_PointSprite.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_PointSprite::*)() const) &OpenGl_PointSprite::DynamicType, "None");

// Enums

}