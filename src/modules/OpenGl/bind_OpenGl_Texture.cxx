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
#include <OpenGl_NamedResource.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Texture.hxx>
#include <Standard_Type.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Graphic3d_TextureParams.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_Sampler.hxx>
#include <Graphic3d_TextureUnit.hxx>
#include <Image_PixMap.hxx>
#include <Graphic3d_TypeOfTexture.hxx>

void bind_OpenGl_Texture(py::module &mod){

py::class_<OpenGl_Texture, opencascade::handle<OpenGl_Texture>, OpenGl_NamedResource> cls_OpenGl_Texture(mod, "OpenGl_Texture", "Texture resource.");

// Constructors
cls_OpenGl_Texture.def(py::init<>());
cls_OpenGl_Texture.def(py::init<const TCollection_AsciiString &>(), py::arg("theResourceId"));
cls_OpenGl_Texture.def(py::init<const TCollection_AsciiString &, const opencascade::handle<Graphic3d_TextureParams> &>(), py::arg("theResourceId"), py::arg("theParams"));

// Fields

// Methods
cls_OpenGl_Texture.def_static("get_type_name_", (const char * (*)()) &OpenGl_Texture::get_type_name, "None");
cls_OpenGl_Texture.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Texture::get_type_descriptor, "None");
cls_OpenGl_Texture.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Texture::*)() const) &OpenGl_Texture::DynamicType, "None");
cls_OpenGl_Texture.def_static("PixelSizeOfPixelFormat_", (Standard_Size (*)(Standard_Integer)) &OpenGl_Texture::PixelSizeOfPixelFormat, "Return pixel size of pixel format in bytes. Note that this method considers that OpenGL natively supports this pixel format, which might be not the case - in the latter case, actual pixel size might differ!", py::arg("theInternalFormat"));
cls_OpenGl_Texture.def("IsValid", (bool (OpenGl_Texture::*)() const) &OpenGl_Texture::IsValid, "Returns true if current object was initialized");
cls_OpenGl_Texture.def("GetTarget", (GLenum (OpenGl_Texture::*)() const) &OpenGl_Texture::GetTarget, "Returns target to which the texture is bound (GL_TEXTURE_1D, GL_TEXTURE_2D)");
cls_OpenGl_Texture.def("SizeX", (GLsizei (OpenGl_Texture::*)() const) &OpenGl_Texture::SizeX, "Returns texture width (0 LOD)");
cls_OpenGl_Texture.def("SizeY", (GLsizei (OpenGl_Texture::*)() const) &OpenGl_Texture::SizeY, "Returns texture height (0 LOD)");
cls_OpenGl_Texture.def("TextureId", (GLuint (OpenGl_Texture::*)() const) &OpenGl_Texture::TextureId, "Returns texture ID");
cls_OpenGl_Texture.def("GetFormat", (GLenum (OpenGl_Texture::*)() const) &OpenGl_Texture::GetFormat, "Returns texture format (not sized)");
cls_OpenGl_Texture.def("IsAlpha", (bool (OpenGl_Texture::*)() const) &OpenGl_Texture::IsAlpha, "Return true for GL_RED and GL_ALPHA formats.");
cls_OpenGl_Texture.def("SetAlpha", (void (OpenGl_Texture::*)(const bool)) &OpenGl_Texture::SetAlpha, "Setup to interprete the format as Alpha by Shader Manager (should be GL_ALPHA within compatible context or GL_RED otherwise).", py::arg("theValue"));
cls_OpenGl_Texture.def("Create", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Texture::Create, "Creates Texture id if not yet generated. Data should be initialized by another method.", py::arg("theCtx"));
cls_OpenGl_Texture.def("Release", (void (OpenGl_Texture::*)(OpenGl_Context *)) &OpenGl_Texture::Release, "Destroy object - will release GPU memory if any.", py::arg("theCtx"));
cls_OpenGl_Texture.def("Sampler", (const opencascade::handle<OpenGl_Sampler> & (OpenGl_Texture::*)() const) &OpenGl_Texture::Sampler, "Return texture sampler.");
cls_OpenGl_Texture.def("SetSampler", (void (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Sampler> &)) &OpenGl_Texture::SetSampler, "Set texture sampler.", py::arg("theSampler"));
cls_OpenGl_Texture.def("InitSamplerObject", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Texture::InitSamplerObject, "Initialize the Sampler Object (as OpenGL object).", py::arg("theCtx"));
cls_OpenGl_Texture.def("Bind", (void (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_Texture::Bind, "Bind this Texture to the unit specified in sampler parameters. Also binds Sampler Object if it is allocated.", py::arg("theCtx"));
cls_OpenGl_Texture.def("Unbind", (void (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_Texture::Unbind, "Unbind texture from the unit specified in sampler parameters. Also unbinds Sampler Object if it is allocated.", py::arg("theCtx"));
cls_OpenGl_Texture.def("Bind", (void (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit) const) &OpenGl_Texture::Bind, "Bind this Texture to specified unit. Also binds Sampler Object if it is allocated.", py::arg("theCtx"), py::arg("theTextureUnit"));
cls_OpenGl_Texture.def("Unbind", (void (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit) const) &OpenGl_Texture::Unbind, "Unbind texture from specified unit. Also unbinds Sampler Object if it is allocated.", py::arg("theCtx"), py::arg("theTextureUnit"));
cls_OpenGl_Texture.def("Revision", (Standard_Size (OpenGl_Texture::*)() const) &OpenGl_Texture::Revision, "Revision of associated data source.");
cls_OpenGl_Texture.def("SetRevision", (void (OpenGl_Texture::*)(const Standard_Size)) &OpenGl_Texture::SetRevision, "Set revision of associated data source.", py::arg("theRevision"));
cls_OpenGl_Texture.def("Init", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const Image_PixMap &, const Graphic3d_TypeOfTexture)) &OpenGl_Texture::Init, "Notice that texture will be unbound after this call.", py::arg("theCtx"), py::arg("theImage"), py::arg("theType"));
cls_OpenGl_Texture.def("Init", [](OpenGl_Texture &self, const opencascade::handle<OpenGl_Context> & a0, const GLint a1, const GLenum a2, const GLenum a3, const GLsizei a4, const GLsizei a5, const Graphic3d_TypeOfTexture a6) -> bool { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_OpenGl_Texture.def("Init", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const GLint, const GLenum, const GLenum, const GLsizei, const GLsizei, const Graphic3d_TypeOfTexture, const Image_PixMap *)) &OpenGl_Texture::Init, "Initialize the texture with specified format, size and texture type. If theImage is empty the texture data will contain trash. Notice that texture will be unbound after this call.", py::arg("theCtx"), py::arg("theTextFormat"), py::arg("thePixelFormat"), py::arg("theDataType"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theType"), py::arg("theImage"));
cls_OpenGl_Texture.def("Init2DMultisample", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLint, const GLsizei, const GLsizei)) &OpenGl_Texture::Init2DMultisample, "Initialize the 2D multisampling texture using glTexImage2DMultisample().", py::arg("theCtx"), py::arg("theNbSamples"), py::arg("theTextFormat"), py::arg("theSizeX"), py::arg("theSizeY"));
cls_OpenGl_Texture.def("InitRectangle", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const Standard_Integer, const Standard_Integer, const OpenGl_TextureFormat &)) &OpenGl_Texture::InitRectangle, "Allocates texture rectangle with specified format and size.", py::arg("theCtx"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theFormat"));
cls_OpenGl_Texture.def("Init3D", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const GLint, const GLenum, const GLenum, const Standard_Integer, const Standard_Integer, const Standard_Integer, const void *)) &OpenGl_Texture::Init3D, "Initializes 3D texture rectangle with specified format and size.", py::arg("theCtx"), py::arg("theTextFormat"), py::arg("thePixelFormat"), py::arg("theDataType"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theSizeZ"), py::arg("thePixels"));
cls_OpenGl_Texture.def("HasMipmaps", (Standard_Boolean (OpenGl_Texture::*)() const) &OpenGl_Texture::HasMipmaps, "Returns true if texture was generated within mipmaps");
cls_OpenGl_Texture.def_static("GetDataFormat_", (bool (*)(const opencascade::handle<OpenGl_Context> &, const Image_PixMap &, GLint &, GLenum &, GLenum &)) &OpenGl_Texture::GetDataFormat, "Return texture type and format by Image_PixMap data format.", py::arg("theCtx"), py::arg("theData"), py::arg("theTextFormat"), py::arg("thePixelFormat"), py::arg("theDataType"));
cls_OpenGl_Texture.def("EstimatedDataSize", (Standard_Size (OpenGl_Texture::*)() const) &OpenGl_Texture::EstimatedDataSize, "Returns estimated GPU memory usage for holding data without considering overheads and allocation alignment rules.");

// Enums

}