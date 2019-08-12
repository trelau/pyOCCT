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
#include <Standard_Handle.hxx>
#include <OpenGl_Context.hxx>
#include <Graphic3d_Buffer.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OpenGl_VertexBuffer.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_VertexBuffer(py::module &mod){

py::class_<OpenGl_VertexBuffer, opencascade::handle<OpenGl_VertexBuffer>, OpenGl_Resource> cls_OpenGl_VertexBuffer(mod, "OpenGl_VertexBuffer", "Vertex Buffer Object - is a general storage object for vertex attributes (position, normal, color). Notice that you should use OpenGl_IndexBuffer specialization for array of indices.");

// Constructors
cls_OpenGl_VertexBuffer.def(py::init<>());

// Fields

// Methods
cls_OpenGl_VertexBuffer.def("GetTarget", (GLenum (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::GetTarget, "None");
cls_OpenGl_VertexBuffer.def("IsValid", (bool (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::IsValid, "Returns true if current object was initialized");
cls_OpenGl_VertexBuffer.def("GetComponentsNb", (GLuint (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::GetComponentsNb, "Returns the number of components per generic vertex attribute.");
cls_OpenGl_VertexBuffer.def("GetElemsNb", (GLsizei (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::GetElemsNb, "Returns number of vertex attributes / number of vertices.");
cls_OpenGl_VertexBuffer.def("GetDataType", (GLenum (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::GetDataType, "Returns data type of each component in the array.");
cls_OpenGl_VertexBuffer.def("GetDataOffset", (GLubyte * (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::GetDataOffset, "Returns offset to data, NULL by default");
cls_OpenGl_VertexBuffer.def("Create", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_VertexBuffer::Create, "Creates VBO name (id) if not yet generated. Data should be initialized by another method.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("Release", (void (OpenGl_VertexBuffer::*)(OpenGl_Context *)) &OpenGl_VertexBuffer::Release, "Destroy object - will release GPU memory if any.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("Bind", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBuffer::Bind, "Bind this VBO.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("Unbind", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBuffer::Unbind, "Unbind this VBO.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("Init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLfloat *)) &OpenGl_VertexBuffer::Init, "Notice that VBO will be unbound after this call.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("Init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLuint *)) &OpenGl_VertexBuffer::Init, "Notice that VBO will be unbound after this call.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("Init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLushort *)) &OpenGl_VertexBuffer::Init, "Notice that VBO will be unbound after this call.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("Init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLubyte *)) &OpenGl_VertexBuffer::Init, "Notice that VBO will be unbound after this call.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("SubData", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLfloat *)) &OpenGl_VertexBuffer::SubData, "Notice that VBO will be unbound after this call. Function replaces portion of data within this VBO using glBufferSubData(). The VBO should be initialized before call.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("SubData", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLuint *)) &OpenGl_VertexBuffer::SubData, "Notice that VBO will be unbound after this call. Function replaces portion of data within this VBO using glBufferSubData(). The VBO should be initialized before call.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("SubData", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLushort *)) &OpenGl_VertexBuffer::SubData, "Notice that VBO will be unbound after this call. Function replaces portion of data within this VBO using glBufferSubData(). The VBO should be initialized before call.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("SubData", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLubyte *)) &OpenGl_VertexBuffer::SubData, "Notice that VBO will be unbound after this call. Function replaces portion of data within this VBO using glBufferSubData(). The VBO should be initialized before call.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("BindVertexAttrib", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint) const) &OpenGl_VertexBuffer::BindVertexAttrib, "Bind this VBO to active GLSL program.", py::arg("theGlCtx"), py::arg("theAttribLoc"));
cls_OpenGl_VertexBuffer.def("UnbindVertexAttrib", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint) const) &OpenGl_VertexBuffer::UnbindVertexAttrib, "Unbind any VBO from active GLSL program.", py::arg("theGlCtx"), py::arg("theAttribLoc"));
cls_OpenGl_VertexBuffer.def("BindAttribute", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TypeOfAttribute) const) &OpenGl_VertexBuffer::BindAttribute, "Bind this VBO and enable specified attribute in OpenGl_Context::ActiveProgram() or FFP.", py::arg("theCtx"), py::arg("theMode"));
cls_OpenGl_VertexBuffer.def("UnbindAttribute", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TypeOfAttribute) const) &OpenGl_VertexBuffer::UnbindAttribute, "Unbind this VBO and disable specified attribute in OpenGl_Context::ActiveProgram() or FFP.", py::arg("theCtx"), py::arg("theMode"));
cls_OpenGl_VertexBuffer.def("EstimatedDataSize", (Standard_Size (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::EstimatedDataSize, "Returns estimated GPU memory usage for holding data without considering overheads and allocation alignment rules.");
cls_OpenGl_VertexBuffer.def_static("sizeOfGlType_", (size_t (*)(const GLenum)) &OpenGl_VertexBuffer::sizeOfGlType, "Returns size of specified GL type", py::arg("theType"));
cls_OpenGl_VertexBuffer.def("init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const void *, const GLenum, const GLsizei)) &OpenGl_VertexBuffer::init, "Initialize buffer with new data.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"), py::arg("theDataType"), py::arg("theStride"));
cls_OpenGl_VertexBuffer.def("init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const void *, const GLenum)) &OpenGl_VertexBuffer::init, "Initialize buffer with new data.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"), py::arg("theDataType"));
cls_OpenGl_VertexBuffer.def("subData", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const void *, const GLenum)) &OpenGl_VertexBuffer::subData, "Update part of the buffer with new data.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"), py::arg("theDataType"));
cls_OpenGl_VertexBuffer.def_static("bindAttribute_", (void (*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TypeOfAttribute, const GLint, const GLenum, const GLsizei, const GLvoid *)) &OpenGl_VertexBuffer::bindAttribute, "Setup array pointer - either for active GLSL program OpenGl_Context::ActiveProgram() or for FFP using bindFixed() when no program bound.", py::arg("theGlCtx"), py::arg("theMode"), py::arg("theNbComp"), py::arg("theDataType"), py::arg("theStride"), py::arg("theOffset"));
cls_OpenGl_VertexBuffer.def_static("unbindAttribute_", (void (*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TypeOfAttribute)) &OpenGl_VertexBuffer::unbindAttribute, "Disable GLSL array pointer - either for active GLSL program OpenGl_Context::ActiveProgram() or for FFP using unbindFixed() when no program bound.", py::arg("theGlCtx"), py::arg("theMode"));
cls_OpenGl_VertexBuffer.def("HasColorAttribute", (bool (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::HasColorAttribute, "Returns true if buffer contains per-vertex color attribute");
cls_OpenGl_VertexBuffer.def("HasNormalAttribute", (bool (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::HasNormalAttribute, "Returns true if buffer contains per-vertex normal attribute");
cls_OpenGl_VertexBuffer.def("BindAllAttributes", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBuffer::BindAllAttributes, "Bind all vertex attributes to active program OpenGl_Context::ActiveProgram() or for FFP. Default implementation does nothing.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("BindPositionAttribute", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBuffer::BindPositionAttribute, "Bind vertex position attribute only. Default implementation does nothing.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("UnbindAllAttributes", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBuffer::UnbindAllAttributes, "Unbind all vertex attributes. Default implementation does nothing.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def_static("get_type_name_", (const char * (*)()) &OpenGl_VertexBuffer::get_type_name, "None");
cls_OpenGl_VertexBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_VertexBuffer::get_type_descriptor, "None");
cls_OpenGl_VertexBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::DynamicType, "None");

// Enums

}