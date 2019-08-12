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
#include <OpenGl_View.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Window.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_FrameBuffer.hxx>
#include <Image_PixMap.hxx>
#include <Graphic3d_BufferType.hxx>
#include <Graphic3d_PresentationAttributes.hxx>
#include <OpenGl_Vec.hxx>
#include <OpenGl_AspectLine.hxx>
#include <OpenGl_AspectFace.hxx>
#include <OpenGl_AspectMarker.hxx>
#include <OpenGl_AspectText.hxx>
#include <OpenGl_RenderFilter.hxx>
#include <OpenGl_Matrix.hxx>
#include <OpenGl_CappingAlgo.hxx>
#include <OpenGl_TextureSet.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <OpenGl_Workspace.hxx>
#include <Standard_Type.hxx>
#include <Standard.hxx>

void bind_OpenGl_Workspace(py::module &mod){

py::class_<OpenGl_Workspace, opencascade::handle<OpenGl_Workspace>, Standard_Transient> cls_OpenGl_Workspace(mod, "OpenGl_Workspace", "Rendering workspace. Provides methods to render primitives and maintain GL state.");

// Constructors
cls_OpenGl_Workspace.def(py::init<OpenGl_View *, const opencascade::handle<OpenGl_Window> &>(), py::arg("theView"), py::arg("theWindow"));

// Fields

// Methods
cls_OpenGl_Workspace.def("Activate", (Standard_Boolean (OpenGl_Workspace::*)()) &OpenGl_Workspace::Activate, "Activate rendering context.");
cls_OpenGl_Workspace.def("View", (OpenGl_View * (OpenGl_Workspace::*)() const) &OpenGl_Workspace::View, "None");
cls_OpenGl_Workspace.def("GetGlContext", (const opencascade::handle<OpenGl_Context> & (OpenGl_Workspace::*)()) &OpenGl_Workspace::GetGlContext, "None");
cls_OpenGl_Workspace.def("FBOCreate", (opencascade::handle<OpenGl_FrameBuffer> (OpenGl_Workspace::*)(const Standard_Integer, const Standard_Integer)) &OpenGl_Workspace::FBOCreate, "None", py::arg("theWidth"), py::arg("theHeight"));
cls_OpenGl_Workspace.def("FBORelease", (void (OpenGl_Workspace::*)(opencascade::handle<OpenGl_FrameBuffer> &)) &OpenGl_Workspace::FBORelease, "None", py::arg("theFbo"));
// cls_OpenGl_Workspace.def("BufferDump", (Standard_Boolean (OpenGl_Workspace::*)(const opencascade::handle<OpenGl_FrameBuffer> &, Image_PixMap &, const Graphic3d_BufferType &)) &OpenGl_Workspace::BufferDump, "None", py::arg("theFbo"), py::arg("theImage"), py::arg("theBufferType"));
cls_OpenGl_Workspace.def("Width", (Standard_Integer (OpenGl_Workspace::*)() const) &OpenGl_Workspace::Width, "None");
cls_OpenGl_Workspace.def("Height", (Standard_Integer (OpenGl_Workspace::*)() const) &OpenGl_Workspace::Height, "None");
cls_OpenGl_Workspace.def("SetUseZBuffer", (Standard_Boolean (OpenGl_Workspace::*)(const Standard_Boolean)) &OpenGl_Workspace::SetUseZBuffer, "Setup Z-buffer usage flag (without affecting GL state!). Returns previously set flag.", py::arg("theToUse"));
cls_OpenGl_Workspace.def("UseZBuffer", (Standard_Boolean & (OpenGl_Workspace::*)()) &OpenGl_Workspace::UseZBuffer, "Returns true if usage of Z buffer is enabled.");
cls_OpenGl_Workspace.def("UseDepthWrite", (Standard_Boolean & (OpenGl_Workspace::*)()) &OpenGl_Workspace::UseDepthWrite, "Returns true if depth writing is enabled.");
cls_OpenGl_Workspace.def("IsCullingEnabled", (Standard_Boolean (OpenGl_Workspace::*)() const) &OpenGl_Workspace::IsCullingEnabled, "Returns true if clipping algorithm enabled");
cls_OpenGl_Workspace.def("ToAllowFaceCulling", (bool (OpenGl_Workspace::*)() const) &OpenGl_Workspace::ToAllowFaceCulling, "Return true if active group might activate face culling (e.g. primitives are closed).");
cls_OpenGl_Workspace.def("SetAllowFaceCulling", (void (OpenGl_Workspace::*)(bool)) &OpenGl_Workspace::SetAllowFaceCulling, "Allow or disallow face culling. This call does NOT affect current state of back face culling; ApplyAspectFace() should be called to update state.", py::arg("theToAllow"));
cls_OpenGl_Workspace.def("ToHighlight", (bool (OpenGl_Workspace::*)() const) &OpenGl_Workspace::ToHighlight, "Return true if following structures should apply highlight color.");
cls_OpenGl_Workspace.def("HighlightStyle", (const opencascade::handle<Graphic3d_PresentationAttributes> & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::HighlightStyle, "Return highlight style.");
cls_OpenGl_Workspace.def("SetHighlightStyle", (void (OpenGl_Workspace::*)(const opencascade::handle<Graphic3d_PresentationAttributes> &)) &OpenGl_Workspace::SetHighlightStyle, "Set highlight style.", py::arg("theStyle"));
cls_OpenGl_Workspace.def("LineColor", (const OpenGl_Vec4 & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::LineColor, "Return line color taking into account highlight flag.");
cls_OpenGl_Workspace.def("EdgeColor", (const OpenGl_Vec4 & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::EdgeColor, "Return edge color taking into account highlight flag.");
cls_OpenGl_Workspace.def("MarkerColor", (const OpenGl_Vec4 & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::MarkerColor, "Return marker color taking into account highlight flag.");
cls_OpenGl_Workspace.def("InteriorColor", (const OpenGl_Vec4 & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::InteriorColor, "Return Interior color taking into account highlight flag.");
cls_OpenGl_Workspace.def("TextColor", (const OpenGl_Vec4 & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::TextColor, "Return text color taking into account highlight flag.");
cls_OpenGl_Workspace.def("TextSubtitleColor", (const OpenGl_Vec4 & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::TextSubtitleColor, "Return text Subtitle color taking into account highlight flag.");
cls_OpenGl_Workspace.def("AspectLine", (const OpenGl_AspectLine * (OpenGl_Workspace::*)() const) &OpenGl_Workspace::AspectLine, "Currently set line aspect (can differ from applied).");
cls_OpenGl_Workspace.def("AspectFace", (const OpenGl_AspectFace * (OpenGl_Workspace::*)() const) &OpenGl_Workspace::AspectFace, "Currently set face aspect (can differ from applied).");
cls_OpenGl_Workspace.def("AspectMarker", (const OpenGl_AspectMarker * (OpenGl_Workspace::*)() const) &OpenGl_Workspace::AspectMarker, "Currently set marker aspect (can differ from applied).");
cls_OpenGl_Workspace.def("AspectText", (const OpenGl_AspectText * (OpenGl_Workspace::*)() const) &OpenGl_Workspace::AspectText, "Currently set text aspect (can differ from applied).");
cls_OpenGl_Workspace.def("SetAspectLine", (const OpenGl_AspectLine * (OpenGl_Workspace::*)(const OpenGl_AspectLine *)) &OpenGl_Workspace::SetAspectLine, "Assign new line aspect (will be applied within ApplyAspectLine()).", py::arg("theAspect"));
cls_OpenGl_Workspace.def("SetAspectFace", (const OpenGl_AspectFace * (OpenGl_Workspace::*)(const OpenGl_AspectFace *)) &OpenGl_Workspace::SetAspectFace, "Assign new face aspect (will be applied within ApplyAspectFace()).", py::arg("theAspect"));
cls_OpenGl_Workspace.def("SetAspectMarker", (const OpenGl_AspectMarker * (OpenGl_Workspace::*)(const OpenGl_AspectMarker *)) &OpenGl_Workspace::SetAspectMarker, "Assign new marker aspect (will be applied within ApplyAspectMarker()).", py::arg("theAspect"));
cls_OpenGl_Workspace.def("SetAspectText", (const OpenGl_AspectText * (OpenGl_Workspace::*)(const OpenGl_AspectText *)) &OpenGl_Workspace::SetAspectText, "Assign new text aspect (will be applied within ApplyAspectText()).", py::arg("theAspect"));
cls_OpenGl_Workspace.def("ApplyAspectLine", (const OpenGl_AspectLine * (OpenGl_Workspace::*)()) &OpenGl_Workspace::ApplyAspectLine, "Apply line aspect.");
cls_OpenGl_Workspace.def("ApplyAspectFace", (const OpenGl_AspectFace * (OpenGl_Workspace::*)()) &OpenGl_Workspace::ApplyAspectFace, "Apply face aspect.");
cls_OpenGl_Workspace.def("ApplyAspectMarker", (const OpenGl_AspectMarker * (OpenGl_Workspace::*)()) &OpenGl_Workspace::ApplyAspectMarker, "Apply marker aspect.");
cls_OpenGl_Workspace.def("ApplyAspectText", (const OpenGl_AspectText * (OpenGl_Workspace::*)()) &OpenGl_Workspace::ApplyAspectText, "Apply text aspect.");
// cls_OpenGl_Workspace.def("ResetAppliedAspect", (void (OpenGl_Workspace::*)()) &OpenGl_Workspace::ResetAppliedAspect, "Clear the applied aspect state to default values.");
cls_OpenGl_Workspace.def("SetRenderFilter", (void (OpenGl_Workspace::*)(const opencascade::handle<OpenGl_RenderFilter> &)) &OpenGl_Workspace::SetRenderFilter, "Set filter for restricting rendering of particular elements. Filter can be applied for rendering passes used by recursive rendering algorithms for rendering elements of groups.", py::arg("theFilter"));
cls_OpenGl_Workspace.def("GetRenderFilter", (const opencascade::handle<OpenGl_RenderFilter> & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::GetRenderFilter, "Get rendering filter.");
cls_OpenGl_Workspace.def("ViewMatrix", (const OpenGl_Matrix * (OpenGl_Workspace::*)() const) &OpenGl_Workspace::ViewMatrix, "Returns applied view matrix.");
cls_OpenGl_Workspace.def("ModelMatrix", (const OpenGl_Matrix * (OpenGl_Workspace::*)() const) &OpenGl_Workspace::ModelMatrix, "Returns applied model structure matrix.");
cls_OpenGl_Workspace.def("FontFaceAspect", (const OpenGl_AspectFace & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::FontFaceAspect, "Returns face aspect for textured font rendering.");
cls_OpenGl_Workspace.def("DefaultCappingAlgoFilter", (const opencascade::handle<OpenGl_CappingAlgoFilter> & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::DefaultCappingAlgoFilter, "Returns capping algorithm rendering filter.");
cls_OpenGl_Workspace.def("NoneCulling", (const OpenGl_AspectFace & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::NoneCulling, "Returns face aspect for none culling mode.");
cls_OpenGl_Workspace.def("FrontCulling", (const OpenGl_AspectFace & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::FrontCulling, "Returns face aspect for front face culling mode.");
cls_OpenGl_Workspace.def("SetEnvironmentTexture", (void (OpenGl_Workspace::*)(const opencascade::handle<OpenGl_TextureSet> &)) &OpenGl_Workspace::SetEnvironmentTexture, "Sets a new environment texture.", py::arg("theTexture"));
cls_OpenGl_Workspace.def("EnvironmentTexture", (const opencascade::handle<OpenGl_TextureSet> & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::EnvironmentTexture, "Returns environment texture.");
cls_OpenGl_Workspace.def_static("get_type_name_", (const char * (*)()) &OpenGl_Workspace::get_type_name, "None");
cls_OpenGl_Workspace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Workspace::get_type_descriptor, "None");
cls_OpenGl_Workspace.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::DynamicType, "None");
// cls_OpenGl_Workspace.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Workspace::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Workspace.def_static("operator delete_", (void (*)(void *)) &OpenGl_Workspace::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Workspace.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Workspace::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Workspace.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Workspace::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Workspace.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Workspace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Workspace.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Workspace::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}