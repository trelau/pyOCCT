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
#include <OpenGl_Context.hxx>
#include <NCollection_Buffer.hxx>
#include <OpenGl_VertexBufferCompat.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_VertexBufferCompat(py::module &mod){

py::class_<OpenGl_VertexBufferCompat, opencascade::handle<OpenGl_VertexBufferCompat>, OpenGl_VertexBuffer> cls_OpenGl_VertexBufferCompat(mod, "OpenGl_VertexBufferCompat", "Compatibility layer for old OpenGL without VBO. Make sure to pass pointer from GetDataOffset() instead of NULL. Method GetDataOffset() returns pointer to real data in this class (while base class OpenGl_VertexBuffer always return NULL).");

// Constructors
cls_OpenGl_VertexBufferCompat.def(py::init<>());

// Fields

// Methods
cls_OpenGl_VertexBufferCompat.def("Create", (bool (OpenGl_VertexBufferCompat::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_VertexBufferCompat::Create, "Creates VBO name (id) if not yet generated. Data should be initialized by another method.", py::arg("theGlCtx"));
cls_OpenGl_VertexBufferCompat.def("Release", (void (OpenGl_VertexBufferCompat::*)(OpenGl_Context *)) &OpenGl_VertexBufferCompat::Release, "Destroy object - will release memory if any.", py::arg("theGlCtx"));
cls_OpenGl_VertexBufferCompat.def("Bind", (void (OpenGl_VertexBufferCompat::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBufferCompat::Bind, "Bind this VBO.", py::arg("theGlCtx"));
cls_OpenGl_VertexBufferCompat.def("Unbind", (void (OpenGl_VertexBufferCompat::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBufferCompat::Unbind, "Unbind this VBO.", py::arg("theGlCtx"));
cls_OpenGl_VertexBufferCompat.def("initLink", (bool (OpenGl_VertexBufferCompat::*)(const opencascade::handle<NCollection_Buffer> &, const GLuint, const GLsizei, const GLenum)) &OpenGl_VertexBufferCompat::initLink, "Initialize buffer with existing data. Data will NOT be copied by this method!", py::arg("theData"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theDataType"));
cls_OpenGl_VertexBufferCompat.def("init", (bool (OpenGl_VertexBufferCompat::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const void *, const GLenum, const GLsizei)) &OpenGl_VertexBufferCompat::init, "Initialize buffer with new data (data will be copied).", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"), py::arg("theDataType"), py::arg("theStride"));
cls_OpenGl_VertexBufferCompat.def("subData", (bool (OpenGl_VertexBufferCompat::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const void *, const GLenum)) &OpenGl_VertexBufferCompat::subData, "Update part of the buffer with new data.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"), py::arg("theDataType"));
cls_OpenGl_VertexBufferCompat.def_static("get_type_name_", (const char * (*)()) &OpenGl_VertexBufferCompat::get_type_name, "None");
cls_OpenGl_VertexBufferCompat.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_VertexBufferCompat::get_type_descriptor, "None");
cls_OpenGl_VertexBufferCompat.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_VertexBufferCompat::*)() const) &OpenGl_VertexBufferCompat::DynamicType, "None");

// Enums

}