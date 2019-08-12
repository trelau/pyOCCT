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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Graphic3d_ShaderObject.hxx>
#include <Graphic3d_Vec2.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Graphic3d_Vec4.hxx>

void bind_Graphic3d_ShaderProgram(py::module &mod){

py::class_<Graphic3d_ShaderProgram, opencascade::handle<Graphic3d_ShaderProgram>, Standard_Transient> cls_Graphic3d_ShaderProgram(mod, "Graphic3d_ShaderProgram", "This class is responsible for managing shader programs.");

// Constructors
cls_Graphic3d_ShaderProgram.def(py::init<>());

// Fields

// Methods
cls_Graphic3d_ShaderProgram.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ShaderProgram::get_type_name, "None");
cls_Graphic3d_ShaderProgram.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ShaderProgram::get_type_descriptor, "None");
cls_Graphic3d_ShaderProgram.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::DynamicType, "None");
cls_Graphic3d_ShaderProgram.def("IsDone", (Standard_Boolean (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::IsDone, "Checks if the program object is valid or not.");
cls_Graphic3d_ShaderProgram.def("GetId", (const TCollection_AsciiString & (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::GetId, "Returns unique ID used to manage resource in graphic driver.");
cls_Graphic3d_ShaderProgram.def("Header", (const TCollection_AsciiString & (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::Header, "Returns GLSL header (version code and extensions).");
cls_Graphic3d_ShaderProgram.def("SetHeader", (void (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &)) &Graphic3d_ShaderProgram::SetHeader, "Setup GLSL header containing language version code and used extensions. Will be prepended to the very beginning of the source code. Example:", py::arg("theHeader"));
cls_Graphic3d_ShaderProgram.def("AppendToHeader", (void (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &)) &Graphic3d_ShaderProgram::AppendToHeader, "Append line to GLSL header.", py::arg("theHeaderLine"));
cls_Graphic3d_ShaderProgram.def("NbLightsMax", (Standard_Integer (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::NbLightsMax, "Return the length of array of light sources (THE_MAX_LIGHTS), to be used for initialization occLightSources. Default value is THE_MAX_LIGHTS_DEFAULT.");
cls_Graphic3d_ShaderProgram.def("SetNbLightsMax", (void (Graphic3d_ShaderProgram::*)(Standard_Integer)) &Graphic3d_ShaderProgram::SetNbLightsMax, "Specify the length of array of light sources (THE_MAX_LIGHTS).", py::arg("theNbLights"));
cls_Graphic3d_ShaderProgram.def("NbClipPlanesMax", (Standard_Integer (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::NbClipPlanesMax, "Return the length of array of clipping planes (THE_MAX_CLIP_PLANES), to be used for initialization occClipPlaneEquations. Default value is THE_MAX_CLIP_PLANES_DEFAULT.");
cls_Graphic3d_ShaderProgram.def("SetNbClipPlanesMax", (void (Graphic3d_ShaderProgram::*)(Standard_Integer)) &Graphic3d_ShaderProgram::SetNbClipPlanesMax, "Specify the length of array of clipping planes (THE_MAX_CLIP_PLANES).", py::arg("theNbPlanes"));
cls_Graphic3d_ShaderProgram.def("AttachShader", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const opencascade::handle<Graphic3d_ShaderObject> &)) &Graphic3d_ShaderProgram::AttachShader, "Attaches shader object to the program object.", py::arg("theShader"));
cls_Graphic3d_ShaderProgram.def("DetachShader", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const opencascade::handle<Graphic3d_ShaderObject> &)) &Graphic3d_ShaderProgram::DetachShader, "Detaches shader object from the program object.", py::arg("theShader"));
cls_Graphic3d_ShaderProgram.def("ShaderObjects", (const Graphic3d_ShaderObjectList & (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::ShaderObjects, "Returns list of attached shader objects.");
cls_Graphic3d_ShaderProgram.def("Variables", (const Graphic3d_ShaderVariableList & (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::Variables, "The list of currently pushed but not applied custom uniform variables. This list is automatically cleared after applying to GLSL program.");
cls_Graphic3d_ShaderProgram.def("VertexAttributes", (const Graphic3d_ShaderAttributeList & (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::VertexAttributes, "Return the list of custom vertex attributes.");
cls_Graphic3d_ShaderProgram.def("SetVertexAttributes", (void (Graphic3d_ShaderProgram::*)(const Graphic3d_ShaderAttributeList &)) &Graphic3d_ShaderProgram::SetVertexAttributes, "Assign the list of custom vertex attributes. Should be done before GLSL program initialization.", py::arg("theAttributes"));
cls_Graphic3d_ShaderProgram.def("NbFragmentOutputs", (Standard_Integer (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::NbFragmentOutputs, "Returns the number (1+) of Fragment Shader outputs to be written to (more than 1 can be in case of multiple draw buffers); 1 by default.");
cls_Graphic3d_ShaderProgram.def("SetNbFragmentOutputs", (void (Graphic3d_ShaderProgram::*)(const Standard_Integer)) &Graphic3d_ShaderProgram::SetNbFragmentOutputs, "Sets the number of Fragment Shader outputs to be written to. Should be done before GLSL program initialization.", py::arg("theNbOutputs"));
cls_Graphic3d_ShaderProgram.def("HasAlphaTest", (Standard_Boolean (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::HasAlphaTest, "Return true if Fragment Shader should perform alpha test; FALSE by default.");
cls_Graphic3d_ShaderProgram.def("SetAlphaTest", (void (Graphic3d_ShaderProgram::*)(Standard_Boolean)) &Graphic3d_ShaderProgram::SetAlphaTest, "Set if Fragment Shader should perform alpha test. Note that this flag is designed for usage with - custom shader program may discard fragment regardless this flag.", py::arg("theAlphaTest"));
cls_Graphic3d_ShaderProgram.def("HasWeightOitOutput", (Standard_Boolean (Graphic3d_ShaderProgram::*)() const) &Graphic3d_ShaderProgram::HasWeightOitOutput, "Return true if Fragment Shader color should output the weighted OIT coverage; FALSE by default.");
cls_Graphic3d_ShaderProgram.def("SetWeightOitOutput", (void (Graphic3d_ShaderProgram::*)(Standard_Boolean)) &Graphic3d_ShaderProgram::SetWeightOitOutput, "Set if Fragment Shader color should output the weighted OIT coverage. Note that weighted OIT also requires at least 2 Fragment Outputs (color + coverage).", py::arg("theOutput"));
cls_Graphic3d_ShaderProgram.def("ClearVariables", (void (Graphic3d_ShaderProgram::*)()) &Graphic3d_ShaderProgram::ClearVariables, "Removes all custom uniform variables from the program.");
cls_Graphic3d_ShaderProgram.def("PushVariableFloat", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const float)) &Graphic3d_ShaderProgram::PushVariableFloat, "Pushes float uniform.", py::arg("theName"), py::arg("theValue"));
cls_Graphic3d_ShaderProgram.def("PushVariableVec2", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec2 &)) &Graphic3d_ShaderProgram::PushVariableVec2, "Pushes vec2 uniform.", py::arg("theName"), py::arg("theValue"));
cls_Graphic3d_ShaderProgram.def("PushVariableVec3", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec3 &)) &Graphic3d_ShaderProgram::PushVariableVec3, "Pushes vec3 uniform.", py::arg("theName"), py::arg("theValue"));
cls_Graphic3d_ShaderProgram.def("PushVariableVec4", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec4 &)) &Graphic3d_ShaderProgram::PushVariableVec4, "Pushes vec4 uniform.", py::arg("theName"), py::arg("theValue"));
cls_Graphic3d_ShaderProgram.def("PushVariableInt", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const int)) &Graphic3d_ShaderProgram::PushVariableInt, "Pushes int uniform.", py::arg("theName"), py::arg("theValue"));
cls_Graphic3d_ShaderProgram.def("PushVariableVec2i", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec2i &)) &Graphic3d_ShaderProgram::PushVariableVec2i, "Pushes vec2i uniform.", py::arg("theName"), py::arg("theValue"));
cls_Graphic3d_ShaderProgram.def("PushVariableVec3i", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec3i &)) &Graphic3d_ShaderProgram::PushVariableVec3i, "Pushes vec3i uniform.", py::arg("theName"), py::arg("theValue"));
cls_Graphic3d_ShaderProgram.def("PushVariableVec4i", (Standard_Boolean (Graphic3d_ShaderProgram::*)(const TCollection_AsciiString &, const Graphic3d_Vec4i &)) &Graphic3d_ShaderProgram::PushVariableVec4i, "Pushes vec4i uniform.", py::arg("theName"), py::arg("theValue"));
cls_Graphic3d_ShaderProgram.def_static("ShadersFolder_", (const TCollection_AsciiString & (*)()) &Graphic3d_ShaderProgram::ShadersFolder, "The path to GLSL programs determined from CSF_ShadersDirectory or CASROOT environment variables.");

// Enums

}