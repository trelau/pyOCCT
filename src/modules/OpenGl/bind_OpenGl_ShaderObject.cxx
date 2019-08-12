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
#include <OpenGl_ShaderObject.hxx>
#include <Standard_Type.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_Context.hxx>
#include <TCollection_AsciiString.hxx>
#include <NCollection_SparseArrayBase.hxx>

void bind_OpenGl_ShaderObject(py::module &mod){

py::class_<OpenGl_ShaderObject, opencascade::handle<OpenGl_ShaderObject>, OpenGl_Resource> cls_OpenGl_ShaderObject(mod, "OpenGl_ShaderObject", "Wrapper for OpenGL shader object.");

// Constructors
cls_OpenGl_ShaderObject.def(py::init<GLenum>(), py::arg("theType"));

// Fields

// Methods
cls_OpenGl_ShaderObject.def_static("get_type_name_", (const char * (*)()) &OpenGl_ShaderObject::get_type_name, "None");
cls_OpenGl_ShaderObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_ShaderObject::get_type_descriptor, "None");
cls_OpenGl_ShaderObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_ShaderObject::*)() const) &OpenGl_ShaderObject::DynamicType, "None");
cls_OpenGl_ShaderObject.def("LoadSource", (Standard_Boolean (OpenGl_ShaderObject::*)(const opencascade::handle<OpenGl_Context> &, const TCollection_AsciiString &)) &OpenGl_ShaderObject::LoadSource, "Loads shader source code.", py::arg("theCtx"), py::arg("theSource"));
cls_OpenGl_ShaderObject.def("Compile", (Standard_Boolean (OpenGl_ShaderObject::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_ShaderObject::Compile, "Compiles the shader object.", py::arg("theCtx"));
cls_OpenGl_ShaderObject.def("FetchInfoLog", (Standard_Boolean (OpenGl_ShaderObject::*)(const opencascade::handle<OpenGl_Context> &, TCollection_AsciiString &)) &OpenGl_ShaderObject::FetchInfoLog, "Fetches information log of the last compile operation.", py::arg("theCtx"), py::arg("theLog"));
cls_OpenGl_ShaderObject.def("Create", (Standard_Boolean (OpenGl_ShaderObject::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_ShaderObject::Create, "Creates new empty shader object of specified type.", py::arg("theCtx"));
cls_OpenGl_ShaderObject.def("Release", (void (OpenGl_ShaderObject::*)(OpenGl_Context *)) &OpenGl_ShaderObject::Release, "Destroys shader object.", py::arg("theCtx"));
cls_OpenGl_ShaderObject.def("EstimatedDataSize", (Standard_Size (OpenGl_ShaderObject::*)() const) &OpenGl_ShaderObject::EstimatedDataSize, "Returns estimated GPU memory usage - not implemented.");
cls_OpenGl_ShaderObject.def("Type", (GLenum (OpenGl_ShaderObject::*)() const) &OpenGl_ShaderObject::Type, "Returns type of shader object.");

// Enums

}