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
#include <OpenGl_Resource.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_FrameBuffer.hxx>
#include <Image_PixMap.hxx>
#include <Graphic3d_BufferType.hxx>
#include <OpenGl_Texture.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <NCollection_Vector.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_FrameBuffer(py::module &mod){

py::class_<OpenGl_FrameBuffer, opencascade::handle<OpenGl_FrameBuffer>, OpenGl_Resource> cls_OpenGl_FrameBuffer(mod, "OpenGl_FrameBuffer", "Class implements FrameBuffer Object (FBO) resource intended for off-screen rendering.");

// Constructors
cls_OpenGl_FrameBuffer.def(py::init<>());

// Fields

// Methods
cls_OpenGl_FrameBuffer.def_static("BufferDump_", (Standard_Boolean (*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_FrameBuffer> &, Image_PixMap &, Graphic3d_BufferType)) &OpenGl_FrameBuffer::BufferDump, "Dump content into image.", py::arg("theGlCtx"), py::arg("theFbo"), py::arg("theImage"), py::arg("theBufferType"));
cls_OpenGl_FrameBuffer.def("Release", (void (OpenGl_FrameBuffer::*)(OpenGl_Context *)) &OpenGl_FrameBuffer::Release, "Destroy object - will release GPU memory if any.", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("NbSamples", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::NbSamples, "Number of multisampling samples.");
cls_OpenGl_FrameBuffer.def("NbColorBuffers", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::NbColorBuffers, "Number of color buffers.");
cls_OpenGl_FrameBuffer.def("HasColor", (bool (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::HasColor, "Return true if FBO has been created with color attachment.");
cls_OpenGl_FrameBuffer.def("HasDepth", (bool (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::HasDepth, "Return true if FBO has been created with depth attachment.");
cls_OpenGl_FrameBuffer.def("GetSizeX", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetSizeX, "Textures width.");
cls_OpenGl_FrameBuffer.def("GetSizeY", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetSizeY, "Textures height.");
cls_OpenGl_FrameBuffer.def("GetVPSizeX", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetVPSizeX, "Viewport width.");
cls_OpenGl_FrameBuffer.def("GetVPSizeY", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetVPSizeY, "Viewport height.");
cls_OpenGl_FrameBuffer.def("GetInitVPSizeX", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetInitVPSizeX, "Viewport width.");
cls_OpenGl_FrameBuffer.def("GetInitVPSizeY", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetInitVPSizeY, "Viewport height.");
cls_OpenGl_FrameBuffer.def("IsValid", (Standard_Boolean (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::IsValid, "Returns true if current object was initialized");
cls_OpenGl_FrameBuffer.def("Init", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const OpenGl_ColorFormats & a3, const opencascade::handle<OpenGl_Texture> & a4) -> Standard_Boolean { return self.Init(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("Init", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const OpenGl_ColorFormats &, const opencascade::handle<OpenGl_Texture> &, const GLsizei)) &OpenGl_FrameBuffer::Init, "Initialize FBO for rendering into single/multiple color buffer and depth textures.", py::arg("theGlCtx"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theColorFormats"), py::arg("theDepthStencilTexture"), py::arg("theNbSamples"));
cls_OpenGl_FrameBuffer.def("Init", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const GLint a3, const GLint a4) -> Standard_Boolean { return self.Init(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("Init", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLint, const GLint, const GLsizei)) &OpenGl_FrameBuffer::Init, "Initialize FBO for rendering into textures.", py::arg("theGlCtx"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theColorFormat"), py::arg("theDepthFormat"), py::arg("theNbSamples"));
cls_OpenGl_FrameBuffer.def("Init", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const OpenGl_ColorFormats & a3, const GLint a4) -> Standard_Boolean { return self.Init(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("Init", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const OpenGl_ColorFormats &, const GLint, const GLsizei)) &OpenGl_FrameBuffer::Init, "Initialize FBO for rendering into single/multiple color buffer and depth textures.", py::arg("theGlCtx"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theColorFormats"), py::arg("theDepthFormat"), py::arg("theNbSamples"));
cls_OpenGl_FrameBuffer.def("InitLazy", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const GLint a3, const GLint a4) -> Standard_Boolean { return self.InitLazy(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("InitLazy", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLint, const GLint, const GLsizei)) &OpenGl_FrameBuffer::InitLazy, "(Re-)initialize FBO with specified dimensions.", py::arg("theGlCtx"), py::arg("theViewportSizeX"), py::arg("theViewportSizeY"), py::arg("theColorFormat"), py::arg("theDepthFormat"), py::arg("theNbSamples"));
cls_OpenGl_FrameBuffer.def("InitLazy", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const OpenGl_ColorFormats & a3, const GLint a4) -> Standard_Boolean { return self.InitLazy(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("InitLazy", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const OpenGl_ColorFormats &, const GLint, const GLsizei)) &OpenGl_FrameBuffer::InitLazy, "(Re-)initialize FBO with specified dimensions.", py::arg("theGlCtx"), py::arg("theViewportSizeX"), py::arg("theViewportSizeY"), py::arg("theColorFormats"), py::arg("theDepthFormat"), py::arg("theNbSamples"));
cls_OpenGl_FrameBuffer.def("InitLazy", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const OpenGl_FrameBuffer &)) &OpenGl_FrameBuffer::InitLazy, "(Re-)initialize FBO with properties taken from another FBO.", py::arg("theGlCtx"), py::arg("theFbo"));
cls_OpenGl_FrameBuffer.def("InitWithRB", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const GLint a3, const GLint a4) -> Standard_Boolean { return self.InitWithRB(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("InitWithRB", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLint, const GLint, const GLuint)) &OpenGl_FrameBuffer::InitWithRB, "(Re-)initialize FBO with specified dimensions. The Render Buffer Objects will be used for Color, Depth and Stencil attachments (as opposite to textures).", py::arg("theGlCtx"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theColorFormat"), py::arg("theDepthFormat"), py::arg("theColorRBufferFromWindow"));
cls_OpenGl_FrameBuffer.def("InitWrapper", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::InitWrapper, "Initialize class from currently bound FBO. Retrieved OpenGL objects will not be destroyed on Release.", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("SetupViewport", (void (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::SetupViewport, "Setup viewport to render into FBO", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("ChangeViewport", (void (OpenGl_FrameBuffer::*)(const GLsizei, const GLsizei)) &OpenGl_FrameBuffer::ChangeViewport, "Override viewport settings", py::arg("theVPSizeX"), py::arg("theVPSizeY"));
cls_OpenGl_FrameBuffer.def("BindBuffer", (void (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::BindBuffer, "Bind frame buffer for drawing and reading (to render into the texture).", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("BindDrawBuffer", (void (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::BindDrawBuffer, "Bind frame buffer for drawing GL_DRAW_FRAMEBUFFER (to render into the texture).", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("BindReadBuffer", (void (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::BindReadBuffer, "Bind frame buffer for reading GL_READ_FRAMEBUFFER", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("UnbindBuffer", (void (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::UnbindBuffer, "Unbind frame buffer.", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("ColorTexture", [](OpenGl_FrameBuffer &self) -> const opencascade::handle<OpenGl_Texture> & { return self.ColorTexture(); });
cls_OpenGl_FrameBuffer.def("ColorTexture", (const opencascade::handle<OpenGl_Texture> & (OpenGl_FrameBuffer::*)(const GLint) const) &OpenGl_FrameBuffer::ColorTexture, "Returns the color texture for the given color buffer index.", py::arg("theColorBufferIndex"));
cls_OpenGl_FrameBuffer.def("DepthStencilTexture", (const opencascade::handle<OpenGl_Texture> & (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::DepthStencilTexture, "Returns the depth-stencil texture.");
cls_OpenGl_FrameBuffer.def("ColorRenderBuffer", (GLuint (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::ColorRenderBuffer, "Returns the color Render Buffer.");
cls_OpenGl_FrameBuffer.def("DepthStencilRenderBuffer", (GLuint (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::DepthStencilRenderBuffer, "Returns the depth Render Buffer.");
cls_OpenGl_FrameBuffer.def("EstimatedDataSize", (Standard_Size (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::EstimatedDataSize, "Returns estimated GPU memory usage for holding data without considering overheads and allocation alignment rules.");
cls_OpenGl_FrameBuffer.def_static("get_type_name_", (const char * (*)()) &OpenGl_FrameBuffer::get_type_name, "None");
cls_OpenGl_FrameBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_FrameBuffer::get_type_descriptor, "None");
cls_OpenGl_FrameBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::DynamicType, "None");

// Enums

}