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
#include <OpenGl_Context.hxx>
#include <OpenGl_Texture.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Sampler.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_TextureParams.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_TextureUnit.hxx>

void bind_OpenGl_Sampler(py::module &mod){

py::class_<OpenGl_Sampler, opencascade::handle<OpenGl_Sampler>, OpenGl_Resource> cls_OpenGl_Sampler(mod, "OpenGl_Sampler", "Class implements OpenGL sampler object resource that stores the sampling parameters for a texture access.");

// Constructors
cls_OpenGl_Sampler.def(py::init<const opencascade::handle<Graphic3d_TextureParams> &>(), py::arg("theParams"));

// Fields

// Methods
cls_OpenGl_Sampler.def_static("get_type_name_", (const char * (*)()) &OpenGl_Sampler::get_type_name, "None");
cls_OpenGl_Sampler.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Sampler::get_type_descriptor, "None");
cls_OpenGl_Sampler.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Sampler::*)() const) &OpenGl_Sampler::DynamicType, "None");
cls_OpenGl_Sampler.def("Release", (void (OpenGl_Sampler::*)(OpenGl_Context *)) &OpenGl_Sampler::Release, "Destroys object - will release GPU memory if any.", py::arg("theContext"));
cls_OpenGl_Sampler.def("EstimatedDataSize", (Standard_Size (OpenGl_Sampler::*)() const) &OpenGl_Sampler::EstimatedDataSize, "Returns estimated GPU memory usage - not implemented.");
cls_OpenGl_Sampler.def("Create", (Standard_Boolean (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Sampler::Create, "Creates an uninitialized sampler object.", py::arg("theContext"));
cls_OpenGl_Sampler.def("Init", (Standard_Boolean (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &, const OpenGl_Texture &)) &OpenGl_Sampler::Init, "Creates and initializes sampler object. Existing object will be reused if possible, however if existing Sampler Object has Immutable flag and texture parameters should be re-initialized, then Sampler Object will be recreated.", py::arg("theContext"), py::arg("theTexture"));
cls_OpenGl_Sampler.def("IsValid", (Standard_Boolean (OpenGl_Sampler::*)() const) &OpenGl_Sampler::IsValid, "Returns true if current object was initialized.");
cls_OpenGl_Sampler.def("Bind", (void (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Sampler::Bind, "Binds sampler object to texture unit specified in parameters.", py::arg("theCtx"));
cls_OpenGl_Sampler.def("Unbind", (void (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Sampler::Unbind, "Unbinds sampler object from texture unit specified in parameters.", py::arg("theCtx"));
cls_OpenGl_Sampler.def("Bind", (void (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit)) &OpenGl_Sampler::Bind, "Binds sampler object to the given texture unit.", py::arg("theCtx"), py::arg("theUnit"));
cls_OpenGl_Sampler.def("Unbind", (void (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit)) &OpenGl_Sampler::Unbind, "Unbinds sampler object from the given texture unit.", py::arg("theCtx"), py::arg("theUnit"));
cls_OpenGl_Sampler.def("SetParameter", (void (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &, GLenum, GLenum, GLint)) &OpenGl_Sampler::SetParameter, "Sets specific sampler parameter.", py::arg("theCtx"), py::arg("theTarget"), py::arg("theParam"), py::arg("theValue"));
cls_OpenGl_Sampler.def("SamplerID", (GLuint (OpenGl_Sampler::*)() const) &OpenGl_Sampler::SamplerID, "Returns OpenGL sampler ID.");
cls_OpenGl_Sampler.def("IsImmutable", (bool (OpenGl_Sampler::*)() const) &OpenGl_Sampler::IsImmutable, "Return immutable flag preventing further modifications of sampler parameters, FALSE by default. Immutable flag might be set when Sampler Object is used within Bindless Texture.");
cls_OpenGl_Sampler.def("SetImmutable", (void (OpenGl_Sampler::*)()) &OpenGl_Sampler::SetImmutable, "Setup immutable flag. It is not possible unsetting this flag without Sampler destruction.");
cls_OpenGl_Sampler.def("Parameters", (const opencascade::handle<Graphic3d_TextureParams> & (OpenGl_Sampler::*)()) &OpenGl_Sampler::Parameters, "Returns texture parameters.");
cls_OpenGl_Sampler.def("SetParameters", (void (OpenGl_Sampler::*)(const opencascade::handle<Graphic3d_TextureParams> &)) &OpenGl_Sampler::SetParameters, "Sets texture parameters.", py::arg("theParams"));
cls_OpenGl_Sampler.def("ToUpdateParameters", (bool (OpenGl_Sampler::*)() const) &OpenGl_Sampler::ToUpdateParameters, "Returns texture parameters initialization state.");

// Enums

}