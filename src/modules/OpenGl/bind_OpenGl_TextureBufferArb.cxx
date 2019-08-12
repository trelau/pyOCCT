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
#include <OpenGl_VertexBuffer.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_TextureBufferArb.hxx>
#include <Standard_Type.hxx>
#include <OpenGl_Context.hxx>
#include <Graphic3d_TextureUnit.hxx>

void bind_OpenGl_TextureBufferArb(py::module &mod){

py::class_<OpenGl_TextureBufferArb, opencascade::handle<OpenGl_TextureBufferArb>, OpenGl_VertexBuffer> cls_OpenGl_TextureBufferArb(mod, "OpenGl_TextureBufferArb", "Texture Buffer Object. This is a special 1D texture that VBO-style initialized. The main differences from general 1D texture: - no interpolation between field; - greater sizes; - special sampler object in GLSL shader to access data by index.");

// Constructors
cls_OpenGl_TextureBufferArb.def(py::init<>());

// Fields

// Methods
cls_OpenGl_TextureBufferArb.def_static("get_type_name_", (const char * (*)()) &OpenGl_TextureBufferArb::get_type_name, "None");
cls_OpenGl_TextureBufferArb.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_TextureBufferArb::get_type_descriptor, "None");
cls_OpenGl_TextureBufferArb.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_TextureBufferArb::*)() const) &OpenGl_TextureBufferArb::DynamicType, "None");
cls_OpenGl_TextureBufferArb.def("GetTarget", (GLenum (OpenGl_TextureBufferArb::*)() const) &OpenGl_TextureBufferArb::GetTarget, "Override VBO target");
cls_OpenGl_TextureBufferArb.def("IsValid", (bool (OpenGl_TextureBufferArb::*)() const) &OpenGl_TextureBufferArb::IsValid, "Returns true if TBO is valid. Notice that no any real GL call is performed!");
cls_OpenGl_TextureBufferArb.def("Release", (void (OpenGl_TextureBufferArb::*)(OpenGl_Context *)) &OpenGl_TextureBufferArb::Release, "Destroy object - will release GPU memory if any.", py::arg("theGlCtx"));
cls_OpenGl_TextureBufferArb.def("Create", (bool (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_TextureBufferArb::Create, "Creates VBO and Texture names (ids) if not yet generated. Data should be initialized by another method.", py::arg("theGlCtx"));
cls_OpenGl_TextureBufferArb.def("Init", (bool (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLfloat *)) &OpenGl_TextureBufferArb::Init, "Perform TBO initialization with specified data. Existing data will be deleted.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_TextureBufferArb.def("Init", (bool (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLuint *)) &OpenGl_TextureBufferArb::Init, "Perform TBO initialization with specified data. Existing data will be deleted.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_TextureBufferArb.def("Init", (bool (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLushort *)) &OpenGl_TextureBufferArb::Init, "Perform TBO initialization with specified data. Existing data will be deleted.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_TextureBufferArb.def("Init", (bool (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLubyte *)) &OpenGl_TextureBufferArb::Init, "Perform TBO initialization with specified data. Existing data will be deleted.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_TextureBufferArb.def("BindTexture", (void (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit) const) &OpenGl_TextureBufferArb::BindTexture, "Bind TBO to specified Texture Unit.", py::arg("theGlCtx"), py::arg("theTextureUnit"));
cls_OpenGl_TextureBufferArb.def("UnbindTexture", (void (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit) const) &OpenGl_TextureBufferArb::UnbindTexture, "Unbind TBO.", py::arg("theGlCtx"), py::arg("theTextureUnit"));
cls_OpenGl_TextureBufferArb.def("TextureId", (GLuint (OpenGl_TextureBufferArb::*)() const) &OpenGl_TextureBufferArb::TextureId, "Returns name of TBO.");
cls_OpenGl_TextureBufferArb.def("TextureFormat", (GLenum (OpenGl_TextureBufferArb::*)() const) &OpenGl_TextureBufferArb::TextureFormat, "Returns internal texture format.");

// Enums

}