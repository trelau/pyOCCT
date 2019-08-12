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
#include <OpenGl_View.hxx>
#include <OpenGl_ShaderManager.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <OpenGl_Context.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OpenGl_ShaderObject.hxx>
#include <TCollection_AsciiString.hxx>
#include <OpenGl_Vec.hxx>
#include <OpenGl_Matrix.hxx>
#include <Graphic3d_TextureUnit.hxx>

void bind_OpenGl_ShaderProgram(py::module &mod){

py::class_<OpenGl_ShaderProgram, opencascade::handle<OpenGl_ShaderProgram>, OpenGl_NamedResource> cls_OpenGl_ShaderProgram(mod, "OpenGl_ShaderProgram", "Wrapper for OpenGL program object.");

// Constructors
cls_OpenGl_ShaderProgram.def(py::init<>());
cls_OpenGl_ShaderProgram.def(py::init<const opencascade::handle<Graphic3d_ShaderProgram> &>(), py::arg("theProxy"));

// Fields

// Methods
cls_OpenGl_ShaderProgram.def_static("get_type_name_", (const char * (*)()) &OpenGl_ShaderProgram::get_type_name, "None");
cls_OpenGl_ShaderProgram.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_ShaderProgram::get_type_descriptor, "None");
cls_OpenGl_ShaderProgram.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::DynamicType, "None");
cls_OpenGl_ShaderProgram.def("Create", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_ShaderProgram::Create, "Creates new empty shader program of specified type.", py::arg("theCtx"));
cls_OpenGl_ShaderProgram.def("Release", (void (OpenGl_ShaderProgram::*)(OpenGl_Context *)) &OpenGl_ShaderProgram::Release, "Destroys shader program.", py::arg("theCtx"));
cls_OpenGl_ShaderProgram.def("EstimatedDataSize", (Standard_Size (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::EstimatedDataSize, "Returns estimated GPU memory usage - cannot be easily estimated.");
cls_OpenGl_ShaderProgram.def("AttachShader", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_ShaderObject> &)) &OpenGl_ShaderProgram::AttachShader, "Attaches shader object to the program object.", py::arg("theCtx"), py::arg("theShader"));
cls_OpenGl_ShaderProgram.def("DetachShader", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_ShaderObject> &)) &OpenGl_ShaderProgram::DetachShader, "Detaches shader object to the program object.", py::arg("theCtx"), py::arg("theShader"));
cls_OpenGl_ShaderProgram.def("Initialize", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_ShaderObjectList &)) &OpenGl_ShaderProgram::Initialize, "Initializes program object with the list of shader objects.", py::arg("theCtx"), py::arg("theShaders"));
cls_OpenGl_ShaderProgram.def("Link", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_ShaderProgram::Link, "Links the program object.", py::arg("theCtx"));
cls_OpenGl_ShaderProgram.def("FetchInfoLog", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, TCollection_AsciiString &)) &OpenGl_ShaderProgram::FetchInfoLog, "Fetches information log of the last link operation.", py::arg("theCtx"), py::arg("theLog"));
cls_OpenGl_ShaderProgram.def("ApplyVariables", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_ShaderProgram::ApplyVariables, "Fetches uniform variables from proxy shader program.", py::arg("theCtx"));
cls_OpenGl_ShaderProgram.def("IsValid", (bool (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::IsValid, "Returns true if current object was initialized");
cls_OpenGl_ShaderProgram.def("ProgramId", (GLuint (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::ProgramId, "Returns program ID");
cls_OpenGl_ShaderProgram.def("HasTessellationStage", (Standard_Boolean (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::HasTessellationStage, "Return TRUE if program defines tessellation stage.");
cls_OpenGl_ShaderProgram.def("NbLightsMax", (Standard_Integer (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::NbLightsMax, "Return the length of array of light sources (THE_MAX_LIGHTS), to be used for initialization occLightSources (OpenGl_OCC_LIGHT_SOURCE_PARAMS).");
cls_OpenGl_ShaderProgram.def("NbClipPlanesMax", (Standard_Integer (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::NbClipPlanesMax, "Return the length of array of clipping planes (THE_MAX_CLIP_PLANES), to be used for initialization occClipPlaneEquations (OpenGl_OCC_CLIP_PLANE_EQUATIONS).");
cls_OpenGl_ShaderProgram.def("NbFragmentOutputs", (Standard_Integer (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::NbFragmentOutputs, "Return the length of array of Fragment Shader outputs (THE_NB_FRAG_OUTPUTS), to be used for initialization occFragColorArray/occFragColorN.");
cls_OpenGl_ShaderProgram.def("HasAlphaTest", (Standard_Boolean (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::HasAlphaTest, "Return true if Fragment Shader should perform alpha test; FALSE by default.");
cls_OpenGl_ShaderProgram.def("HasWeightOitOutput", (Standard_Boolean (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::HasWeightOitOutput, "Return true if Fragment Shader color should output the weighted OIT coverage; FALSE by default.");
cls_OpenGl_ShaderProgram.def("GetUniformLocation", (GLint (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *) const) &OpenGl_ShaderProgram::GetUniformLocation, "Returns location of the specific uniform variable.", py::arg("theCtx"), py::arg("theName"));
cls_OpenGl_ShaderProgram.def("GetAttributeLocation", (GLint (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *) const) &OpenGl_ShaderProgram::GetAttributeLocation, "Returns index of the generic vertex attribute by variable name.", py::arg("theCtx"), py::arg("theName"));
cls_OpenGl_ShaderProgram.def("GetStateLocation", (GLint (OpenGl_ShaderProgram::*)(const GLuint) const) &OpenGl_ShaderProgram::GetStateLocation, "Returns location of the OCCT state uniform variable.", py::arg("theVariable"));
cls_OpenGl_ShaderProgram.def("GetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, OpenGl_Vec4i &) const) &OpenGl_ShaderProgram::GetUniform, "Returns the value of the integer uniform variable.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, OpenGl_Vec4i &) const) &OpenGl_ShaderProgram::GetUniform, "None", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, OpenGl_Vec4 &) const) &OpenGl_ShaderProgram::GetUniform, "Returns the value of the float uniform variable.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, OpenGl_Vec4 &) const) &OpenGl_ShaderProgram::GetUniform, "Returns the value of the float uniform variable.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, OpenGl_Vec4i &) const) &OpenGl_ShaderProgram::GetAttribute, "Returns the integer vertex attribute.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, OpenGl_Vec4i &) const) &OpenGl_ShaderProgram::GetAttribute, "Returns the integer vertex attribute.", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, OpenGl_Vec4 &) const) &OpenGl_ShaderProgram::GetAttribute, "Returns the float vertex attribute.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, OpenGl_Vec4 &) const) &OpenGl_ShaderProgram::GetAttribute, "Returns the float vertex attribute.", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttributeName", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const GLchar *)) &OpenGl_ShaderProgram::SetAttributeName, "Wrapper for glBindAttribLocation()", py::arg("theCtx"), py::arg("theIndex"), py::arg("theName"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, GLfloat)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib1f()", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLfloat)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib1f()", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec2 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib2fv()", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec2 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib2fv()", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec3 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib3fv()", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec3 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib3fv()", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec4 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib4fv()", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec4 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib4fv()", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, GLint)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform variable.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLint)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform variable.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec2i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 2D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec2i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 2D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec3i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 3D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec3i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 3D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec4i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 4D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec4i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 4D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec2u &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the unsigned integer uniform 2D vector (uvec2).", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec2u &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the unsigned integer uniform 2D vector (uvec2).", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const GLsizei, const OpenGl_Vec2u *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the uvec2 uniform array", py::arg("theCtx"), py::arg("theName"), py::arg("theCount"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const GLsizei, const OpenGl_Vec2u *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the uvec2 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, GLfloat)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform variable.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLfloat)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform variable.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec2 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 2D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec2 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 2D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec3 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 3D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec3 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 3D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec4 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec4 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0, const GLchar * a1, const OpenGl_Mat4 & a2) -> Standard_Boolean { return self.SetUniform(a0, a1, a2); });
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Mat4 &, GLboolean)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4x4 matrix.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"), py::arg("theTranspose"));
cls_OpenGl_ShaderProgram.def("SetUniform", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0, GLint a1, const OpenGl_Mat4 & a2) -> Standard_Boolean { return self.SetUniform(a0, a1, a2); });
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Mat4 &, GLboolean)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4x4 matrix.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"), py::arg("theTranspose"));
cls_OpenGl_ShaderProgram.def("SetUniform", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0, const GLchar * a1, const OpenGl_Matrix & a2) -> Standard_Boolean { return self.SetUniform(a0, a1, a2); });
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Matrix &, GLboolean)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4x4 matrix.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"), py::arg("theTranspose"));
cls_OpenGl_ShaderProgram.def("SetUniform", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0, GLint a1, const OpenGl_Matrix & a2) -> Standard_Boolean { return self.SetUniform(a0, a1, a2); });
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Matrix &, GLboolean)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4x4 matrix.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"), py::arg("theTranspose"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const Standard_ShortReal *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec2 *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float2 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec3 *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float3 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec4 *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float4 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const Standard_Integer *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec2i *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the int2 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec3i *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the int3 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec4i *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the int4 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetSampler", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const Graphic3d_TextureUnit)) &OpenGl_ShaderProgram::SetSampler, "Specifies the value of the sampler uniform variable.", py::arg("theCtx"), py::arg("theName"), py::arg("theTextureUnit"));
cls_OpenGl_ShaderProgram.def("SetSampler", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const Graphic3d_TextureUnit)) &OpenGl_ShaderProgram::SetSampler, "Specifies the value of the sampler uniform variable.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theTextureUnit"));

// Enums

}