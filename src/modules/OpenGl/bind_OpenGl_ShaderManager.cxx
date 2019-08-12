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
#include <OpenGl_ShaderManager.hxx>
#include <Standard_Type.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <OpenGl_Context.hxx>
#include <gp_XYZ.hxx>
#include <gp.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <TCollection_AsciiString.hxx>
#include <OpenGl_TextureSet.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <Graphic3d_AlphaMode.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Graphic3d_StereoMode.hxx>
#include <OpenGl_ShaderStates.hxx>
#include <Graphic3d_LightSet.hxx>
#include <OpenGl_Vec.hxx>
#include <OpenGl_MaterialState.hxx>
#include <OpenGl_Material.hxx>
#include <OpenGl_View.hxx>
#include <OpenGl_SetOfShaderPrograms.hxx>
#include <NCollection_Array1.hxx>

void bind_OpenGl_ShaderManager(py::module &mod){

py::class_<OpenGl_ShaderManager, opencascade::handle<OpenGl_ShaderManager>, Standard_Transient> cls_OpenGl_ShaderManager(mod, "OpenGl_ShaderManager", "This class is responsible for managing shader programs.");

// Constructors
cls_OpenGl_ShaderManager.def(py::init<OpenGl_Context *>(), py::arg("theContext"));

// Fields

// Methods
cls_OpenGl_ShaderManager.def_static("get_type_name_", (const char * (*)()) &OpenGl_ShaderManager::get_type_name, "None");
cls_OpenGl_ShaderManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_ShaderManager::get_type_descriptor, "None");
cls_OpenGl_ShaderManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::DynamicType, "None");
cls_OpenGl_ShaderManager.def("clear", (void (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::clear, "Release all resources.");
cls_OpenGl_ShaderManager.def("LocalOrigin", (const gp_XYZ & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::LocalOrigin, "Return local camera transformation.");
cls_OpenGl_ShaderManager.def("SetLocalOrigin", (void (OpenGl_ShaderManager::*)(const gp_XYZ &)) &OpenGl_ShaderManager::SetLocalOrigin, "Setup local camera transformation for compensating float precision issues.", py::arg("theOrigin"));
cls_OpenGl_ShaderManager.def("Create", (Standard_Boolean (OpenGl_ShaderManager::*)(const opencascade::handle<Graphic3d_ShaderProgram> &, TCollection_AsciiString &, opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::Create, "Creates new shader program or re-use shared instance.", py::arg("theProxy"), py::arg("theShareKey"), py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("Unregister", (void (OpenGl_ShaderManager::*)(TCollection_AsciiString &, opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::Unregister, "Unregisters specified shader program.", py::arg("theShareKey"), py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("ShaderPrograms", (const OpenGl_ShaderProgramList & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::ShaderPrograms, "Returns list of registered shader programs.");
cls_OpenGl_ShaderManager.def("IsEmpty", (Standard_Boolean (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::IsEmpty, "Returns true if no program objects are registered in the manager.");
cls_OpenGl_ShaderManager.def("BindFaceProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_TextureSet> &, const Graphic3d_TypeOfShadingModel, const Graphic3d_AlphaMode, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::BindFaceProgram, "Bind program for filled primitives rendering", py::arg("theTextures"), py::arg("theShadingModel"), py::arg("theAlphaMode"), py::arg("theHasVertColor"), py::arg("theEnableEnvMap"), py::arg("theCustomProgram"));
cls_OpenGl_ShaderManager.def("BindLineProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_TextureSet> &, const Aspect_TypeOfLine, const Graphic3d_TypeOfShadingModel, const Graphic3d_AlphaMode, const Standard_Boolean, const opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::BindLineProgram, "Bind program for line rendering", py::arg("theTextures"), py::arg("theLineType"), py::arg("theShadingModel"), py::arg("theAlphaMode"), py::arg("theHasVertColor"), py::arg("theCustomProgram"));
cls_OpenGl_ShaderManager.def("BindMarkerProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_TextureSet> &, const Graphic3d_TypeOfShadingModel, const Graphic3d_AlphaMode, const Standard_Boolean, const opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::BindMarkerProgram, "Bind program for point rendering", py::arg("theTextures"), py::arg("theShadingModel"), py::arg("theAlphaMode"), py::arg("theHasVertColor"), py::arg("theCustomProgram"));
cls_OpenGl_ShaderManager.def("BindFontProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::BindFontProgram, "Bind program for rendering alpha-textured font.", py::arg("theCustomProgram"));
cls_OpenGl_ShaderManager.def("BindFboBlitProgram", (Standard_Boolean (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::BindFboBlitProgram, "Bind program for FBO blit operation.");
cls_OpenGl_ShaderManager.def("BindOitCompositingProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const Standard_Boolean)) &OpenGl_ShaderManager::BindOitCompositingProgram, "Bind program for blended order-independent transparency buffers compositing.", py::arg("theIsMSAAEnabled"));
cls_OpenGl_ShaderManager.def("BindStereoProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const Graphic3d_StereoMode)) &OpenGl_ShaderManager::BindStereoProgram, "Bind program for rendering stereoscopic image.", py::arg("theStereoMode"));
cls_OpenGl_ShaderManager.def("LightSourceState", (const OpenGl_LightSourceState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::LightSourceState, "Returns current state of OCCT light sources.");
cls_OpenGl_ShaderManager.def("UpdateLightSourceStateTo", (void (OpenGl_ShaderManager::*)(const opencascade::handle<Graphic3d_LightSet> &)) &OpenGl_ShaderManager::UpdateLightSourceStateTo, "Updates state of OCCT light sources.", py::arg("theLights"));
cls_OpenGl_ShaderManager.def("UpdateLightSourceState", (void (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::UpdateLightSourceState, "Invalidate state of OCCT light sources.");
cls_OpenGl_ShaderManager.def("PushLightSourceState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushLightSourceState, "Pushes current state of OCCT light sources to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("ProjectionState", (const OpenGl_ProjectionState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::ProjectionState, "Returns current state of OCCT projection transform.");
cls_OpenGl_ShaderManager.def("UpdateProjectionStateTo", (void (OpenGl_ShaderManager::*)(const OpenGl_Mat4 &)) &OpenGl_ShaderManager::UpdateProjectionStateTo, "Updates state of OCCT projection transform.", py::arg("theProjectionMatrix"));
cls_OpenGl_ShaderManager.def("PushProjectionState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushProjectionState, "Pushes current state of OCCT projection transform to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("ModelWorldState", (const OpenGl_ModelWorldState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::ModelWorldState, "Returns current state of OCCT model-world transform.");
cls_OpenGl_ShaderManager.def("UpdateModelWorldStateTo", (void (OpenGl_ShaderManager::*)(const OpenGl_Mat4 &)) &OpenGl_ShaderManager::UpdateModelWorldStateTo, "Updates state of OCCT model-world transform.", py::arg("theModelWorldMatrix"));
cls_OpenGl_ShaderManager.def("PushModelWorldState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushModelWorldState, "Pushes current state of OCCT model-world transform to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("WorldViewState", (const OpenGl_WorldViewState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::WorldViewState, "Returns current state of OCCT world-view transform.");
cls_OpenGl_ShaderManager.def("UpdateWorldViewStateTo", (void (OpenGl_ShaderManager::*)(const OpenGl_Mat4 &)) &OpenGl_ShaderManager::UpdateWorldViewStateTo, "Updates state of OCCT world-view transform.", py::arg("theWorldViewMatrix"));
cls_OpenGl_ShaderManager.def("PushWorldViewState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushWorldViewState, "Pushes current state of OCCT world-view transform to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("UpdateClippingState", (void (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::UpdateClippingState, "Updates state of OCCT clipping planes.");
cls_OpenGl_ShaderManager.def("RevertClippingState", (void (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::RevertClippingState, "Reverts state of OCCT clipping planes.");
cls_OpenGl_ShaderManager.def("PushClippingState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushClippingState, "Pushes current state of OCCT clipping planes to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("MaterialState", (const OpenGl_MaterialState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::MaterialState, "Returns current state of material.");
cls_OpenGl_ShaderManager.def("UpdateMaterialStateTo", (void (OpenGl_ShaderManager::*)(const OpenGl_Material &, const OpenGl_Material &, const float, const bool, const bool)) &OpenGl_ShaderManager::UpdateMaterialStateTo, "Updates state of material.", py::arg("theFrontMat"), py::arg("theBackMat"), py::arg("theAlphaCutoff"), py::arg("theToDistinguish"), py::arg("theToMapTexture"));
cls_OpenGl_ShaderManager.def("UpdateMaterialState", (void (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::UpdateMaterialState, "Updates state of material.");
// cls_OpenGl_ShaderManager.def("PushMaterialState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushMaterialState, "Pushes current state of material to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("OitState", (const OpenGl_OitState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::OitState, "Returns state of OIT uniforms.");
cls_OpenGl_ShaderManager.def("SetOitState", (void (OpenGl_ShaderManager::*)(const bool, const float)) &OpenGl_ShaderManager::SetOitState, "Set the state of OIT rendering pass.", py::arg("theToEnableOitWrite"), py::arg("theDepthFactor"));
cls_OpenGl_ShaderManager.def("PushOitState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushOitState, "Pushes state of OIT uniforms to the specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("PushState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushState, "Pushes current state of OCCT graphics parameters to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("SetContext", (void (OpenGl_ShaderManager::*)(OpenGl_Context *)) &OpenGl_ShaderManager::SetContext, "Overwrites context", py::arg("theCtx"));
cls_OpenGl_ShaderManager.def("IsSameContext", (bool (OpenGl_ShaderManager::*)(OpenGl_Context *) const) &OpenGl_ShaderManager::IsSameContext, "Returns true when provided context is the same as used one by shader manager.", py::arg("theCtx"));
cls_OpenGl_ShaderManager.def("ChooseFaceShadingModel", (Graphic3d_TypeOfShadingModel (OpenGl_ShaderManager::*)(Graphic3d_TypeOfShadingModel, bool) const) &OpenGl_ShaderManager::ChooseFaceShadingModel, "Choose Shading Model for filled primitives. Fallbacks to FACET model if there are no normal attributes.", py::arg("theCustomModel"), py::arg("theHasNodalNormals"));
cls_OpenGl_ShaderManager.def("ChooseLineShadingModel", (Graphic3d_TypeOfShadingModel (OpenGl_ShaderManager::*)(Graphic3d_TypeOfShadingModel, bool) const) &OpenGl_ShaderManager::ChooseLineShadingModel, "Choose Shading Model for line primitives. Fallbacks to UNLIT model if there are no normal attributes.", py::arg("theCustomModel"), py::arg("theHasNodalNormals"));
cls_OpenGl_ShaderManager.def("ChooseMarkerShadingModel", (Graphic3d_TypeOfShadingModel (OpenGl_ShaderManager::*)(Graphic3d_TypeOfShadingModel, bool) const) &OpenGl_ShaderManager::ChooseMarkerShadingModel, "Choose Shading Model for Marker primitives.", py::arg("theCustomModel"), py::arg("theHasNodalNormals"));
cls_OpenGl_ShaderManager.def("ShadingModel", (Graphic3d_TypeOfShadingModel (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::ShadingModel, "Returns default Shading Model.");
cls_OpenGl_ShaderManager.def("SetShadingModel", (void (OpenGl_ShaderManager::*)(const Graphic3d_TypeOfShadingModel)) &OpenGl_ShaderManager::SetShadingModel, "Sets shading model.", py::arg("theModel"));
cls_OpenGl_ShaderManager.def("SetLastView", (void (OpenGl_ShaderManager::*)(const OpenGl_View *)) &OpenGl_ShaderManager::SetLastView, "Sets last view manger used with. Helps to handle matrix states in multi-view configurations.", py::arg("theLastView"));
cls_OpenGl_ShaderManager.def("IsSameView", (bool (OpenGl_ShaderManager::*)(const OpenGl_View *) const) &OpenGl_ShaderManager::IsSameView, "Returns true when provided view is the same as cached one.", py::arg("theView"));

// Enums

}