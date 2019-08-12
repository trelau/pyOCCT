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
#include <OpenGl_IndexBuffer.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_IndexBuffer(py::module &mod){

py::class_<OpenGl_IndexBuffer, opencascade::handle<OpenGl_IndexBuffer>, OpenGl_VertexBuffer> cls_OpenGl_IndexBuffer(mod, "OpenGl_IndexBuffer", "Index buffer is just a VBO with special target (GL_ELEMENT_ARRAY_BUFFER).");

// Constructors
cls_OpenGl_IndexBuffer.def(py::init<>());

// Fields

// Methods
cls_OpenGl_IndexBuffer.def("GetTarget", (GLenum (OpenGl_IndexBuffer::*)() const) &OpenGl_IndexBuffer::GetTarget, "None");
cls_OpenGl_IndexBuffer.def_static("get_type_name_", (const char * (*)()) &OpenGl_IndexBuffer::get_type_name, "None");
cls_OpenGl_IndexBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_IndexBuffer::get_type_descriptor, "None");
cls_OpenGl_IndexBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_IndexBuffer::*)() const) &OpenGl_IndexBuffer::DynamicType, "None");

// Enums

}