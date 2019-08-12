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
#include <Graphic3d_CView.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <OpenGl_Caps.hxx>
#include <OpenGl_Context.hxx>
#include <Standard_TypeDef.hxx>
#include <Aspect_Window.hxx>
#include <Aspect_RenderingContext.hxx>
#include <Graphic3d_GraduatedTrihedron.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Image_PixMap.hxx>
#include <Graphic3d_BufferType.hxx>
#include <Graphic3d_ExportFormat.hxx>
#include <Graphic3d_SortType.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_ZLayerSettings.hxx>
#include <Bnd_Box.hxx>
#include <Graphic3d_Camera.hxx>
#include <Standard_Transient.hxx>
#include <Aspect_Background.hxx>
#include <Aspect_GradientBackground.hxx>
#include <TCollection_AsciiString.hxx>
#include <Aspect_FillMethod.hxx>
#include <Graphic3d_TextureEnv.hxx>
#include <Graphic3d_TypeOfBackfacingModel.hxx>
#include <gp_XYZ.hxx>
#include <Graphic3d_LightSet.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <TColStd_IndexedDataMapOfStringString.hxx>
#include <Graphic3d_DiagnosticInfo.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <OpenGl_GraduatedTrihedron.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <OpenGl_LayerList.hxx>
#include <OpenGl_Window.hxx>
#include <OpenGl_TextureSet.hxx>
#include <OpenGl_BVHTreeSelector.hxx>
#include <OpenGl_FrameBuffer.hxx>
#include <OpenGl_Workspace.hxx>
#include <Graphic3d_CStructure.hxx>
#include <OpenGl_VertexBuffer.hxx>
#include <Graphic3d_WorldViewProjState.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OpenGl_View.hxx>
#include <OpenGl_FrameStatsPrs.hxx>
#include <OpenGl_AspectFace.hxx>
#include <OpenGl_BackgroundArray.hxx>
#include <Graphic3d_ToneMappingMethod.hxx>
#include <OpenGl_Structure.hxx>
#include <OpenGl_Vec.hxx>
#include <OpenGl_SceneGeometry.hxx>
#include <Geom_Transformation.hxx>
#include <OpenGl_PrimitiveArray.hxx>
#include <Graphic3d_IndexBuffer.hxx>
#include <TCollection_ExtendedString.hxx>
#include <OpenGl_ShaderObject.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <BVH_Builder.hxx>
#include <OpenGl_TextureBufferArb.hxx>
#include <OpenGl_Texture.hxx>
#include <math_BullardGenerator.hxx>
#include <OpenGl_TileSampler.hxx>
#include <Standard.hxx>
#include <Standard_Type.hxx>
#include <OpenGl_FrameStats.hxx>

void bind_OpenGl_View(py::module &mod){

/*
py::class_<OpenGl_View, opencascade::handle<OpenGl_View>, Graphic3d_CView> cls_OpenGl_View(mod, "OpenGl_View", "Implementation of OpenGl view.");

// Constructors
cls_OpenGl_View.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const opencascade::handle<OpenGl_GraphicDriver> &, const opencascade::handle<OpenGl_Caps> &, OpenGl_StateCounter *>(), py::arg("theMgr"), py::arg("theDriver"), py::arg("theCaps"), py::arg("theCounter"));

// Fields

// Methods
cls_OpenGl_View.def("ReleaseGlResources", (void (OpenGl_View::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_View::ReleaseGlResources, "None", py::arg("theCtx"));
cls_OpenGl_View.def("Remove", (void (OpenGl_View::*)()) &OpenGl_View::Remove, "Deletes and erases the view.");
cls_OpenGl_View.def("SetImmediateModeDrawToFront", (Standard_Boolean (OpenGl_View::*)(const Standard_Boolean)) &OpenGl_View::SetImmediateModeDrawToFront, "Returns previous mode.", py::arg("theDrawToFrontBuffer"));
cls_OpenGl_View.def("SetWindow", (void (OpenGl_View::*)(const opencascade::handle<Aspect_Window> &, const Aspect_RenderingContext)) &OpenGl_View::SetWindow, "Creates and maps rendering window to the view.", py::arg("theWindow"), py::arg("theContext"));
cls_OpenGl_View.def("Window", (opencascade::handle<Aspect_Window> (OpenGl_View::*)() const) &OpenGl_View::Window, "Returns window associated with the view.");
cls_OpenGl_View.def("IsDefined", (Standard_Boolean (OpenGl_View::*)() const) &OpenGl_View::IsDefined, "Returns True if the window associated to the view is defined.");
cls_OpenGl_View.def("Resized", (void (OpenGl_View::*)()) &OpenGl_View::Resized, "Handle changing size of the rendering window.");
cls_OpenGl_View.def("Redraw", (void (OpenGl_View::*)()) &OpenGl_View::Redraw, "Redraw content of the view.");
cls_OpenGl_View.def("RedrawImmediate", (void (OpenGl_View::*)()) &OpenGl_View::RedrawImmediate, "Redraw immediate content of the view.");
cls_OpenGl_View.def("Invalidate", (void (OpenGl_View::*)()) &OpenGl_View::Invalidate, "Marks BVH tree for given priority list as dirty and marks primitive set for rebuild.");
cls_OpenGl_View.def("IsInvalidated", (Standard_Boolean (OpenGl_View::*)()) &OpenGl_View::IsInvalidated, "Return true if view content cache has been invalidated.");
cls_OpenGl_View.def("GetGraduatedTrihedron", (const Graphic3d_GraduatedTrihedron & (OpenGl_View::*)()) &OpenGl_View::GetGraduatedTrihedron, "Returns data of a graduated trihedron");
cls_OpenGl_View.def("GraduatedTrihedronDisplay", (void (OpenGl_View::*)(const Graphic3d_GraduatedTrihedron &)) &OpenGl_View::GraduatedTrihedronDisplay, "Displays Graduated Trihedron.", py::arg("theTrihedronData"));
cls_OpenGl_View.def("GraduatedTrihedronErase", (void (OpenGl_View::*)()) &OpenGl_View::GraduatedTrihedronErase, "Erases Graduated Trihedron.");
cls_OpenGl_View.def("GraduatedTrihedronMinMaxValues", (void (OpenGl_View::*)(const Graphic3d_Vec3, const Graphic3d_Vec3)) &OpenGl_View::GraduatedTrihedronMinMaxValues, "Sets minimum and maximum points of scene bounding box for Graduated Trihedron stored in graphic view object.", py::arg("theMin"), py::arg("theMax"));
cls_OpenGl_View.def("BufferDump", (Standard_Boolean (OpenGl_View::*)(Image_PixMap &, const Graphic3d_BufferType &)) &OpenGl_View::BufferDump, "Dump active rendering buffer into specified memory buffer. In Ray-Tracing allow to get a raw HDR buffer using Graphic3d_BT_RGB_RayTraceHdrLeft buffer type, only Left view will be dumped ignoring stereoscopic parameter.", py::arg("theImage"), py::arg("theBufferType"));
cls_OpenGl_View.def("Export", [](OpenGl_View &self, const Standard_CString a0, const Graphic3d_ExportFormat a1) -> Standard_Boolean { return self.Export(a0, a1); });
cls_OpenGl_View.def("Export", (Standard_Boolean (OpenGl_View::*)(const Standard_CString, const Graphic3d_ExportFormat, const Graphic3d_SortType)) &OpenGl_View::Export, "Export scene into the one of the Vector graphics formats (SVG, PS, PDF...). In contrast to Bitmaps, Vector graphics is scalable (so you may got quality benefits on printing to laser printer). Notice however that results may differ a lot and do not contain some elements.", py::arg("theFileName"), py::arg("theFormat"), py::arg("theSortType"));
cls_OpenGl_View.def("InvalidateBVHData", (void (OpenGl_View::*)(const Graphic3d_ZLayerId)) &OpenGl_View::InvalidateBVHData, "Marks BVH tree and the set of BVH primitives of correspondent priority list with id theLayerId as outdated.", py::arg("theLayerId"));
cls_OpenGl_View.def("AddZLayer", (void (OpenGl_View::*)(const Graphic3d_ZLayerId)) &OpenGl_View::AddZLayer, "Insert a new top-level z layer with the given ID.", py::arg("theLayerId"));
cls_OpenGl_View.def("RemoveZLayer", (void (OpenGl_View::*)(const Graphic3d_ZLayerId)) &OpenGl_View::RemoveZLayer, "Remove a z layer with the given ID.", py::arg("theLayerId"));
cls_OpenGl_View.def("SetZLayerSettings", (void (OpenGl_View::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &)) &OpenGl_View::SetZLayerSettings, "Sets the settings for a single Z layer of specified view.", py::arg("theLayerId"), py::arg("theSettings"));
cls_OpenGl_View.def("ZLayerMax", (Standard_Integer (OpenGl_View::*)() const) &OpenGl_View::ZLayerMax, "Returns the maximum Z layer ID. First layer ID is Graphic3d_ZLayerId_Default, last ID is ZLayerMax().");
cls_OpenGl_View.def("InvalidateZLayerBoundingBox", (void (OpenGl_View::*)(const Graphic3d_ZLayerId) const) &OpenGl_View::InvalidateZLayerBoundingBox, "Returns the bounding box of all structures displayed in the Z layer. Never fails. If Z layer does not exist nothing happens.", py::arg("theLayerId"));
cls_OpenGl_View.def("ZLayerBoundingBox", (Bnd_Box (OpenGl_View::*)(const Graphic3d_ZLayerId, const opencascade::handle<Graphic3d_Camera> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean) const) &OpenGl_View::ZLayerBoundingBox, "Returns the bounding box of all structures displayed in the Z layer. If Z layer does not exist the empty box is returned.", py::arg("theLayerId"), py::arg("theCamera"), py::arg("theWindowWidth"), py::arg("theWindowHeight"), py::arg("theToIncludeAuxiliary"));
cls_OpenGl_View.def("FBO", (opencascade::handle<Standard_Transient> (OpenGl_View::*)() const) &OpenGl_View::FBO, "Returns pointer to an assigned framebuffer object.");
cls_OpenGl_View.def("SetFBO", (void (OpenGl_View::*)(const opencascade::handle<Standard_Transient> &)) &OpenGl_View::SetFBO, "Sets framebuffer object for offscreen rendering.", py::arg("theFbo"));
cls_OpenGl_View.def("FBOCreate", (opencascade::handle<Standard_Transient> (OpenGl_View::*)(const Standard_Integer, const Standard_Integer)) &OpenGl_View::FBOCreate, "Generate offscreen FBO in the graphic library. If not supported on hardware returns NULL.", py::arg("theWidth"), py::arg("theHeight"));
cls_OpenGl_View.def("FBORelease", (void (OpenGl_View::*)(opencascade::handle<Standard_Transient> &)) &OpenGl_View::FBORelease, "Remove offscreen FBO from the graphic library", py::arg("theFbo"));
cls_OpenGl_View.def("FBOGetDimensions", [](OpenGl_View &self, const opencascade::handle<Standard_Transient> & theFbo, Standard_Integer & theWidth, Standard_Integer & theHeight, Standard_Integer & theWidthMax, Standard_Integer & theHeightMax){ self.FBOGetDimensions(theFbo, theWidth, theHeight, theWidthMax, theHeightMax); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(theWidth, theHeight, theWidthMax, theHeightMax); }, "Read offscreen FBO configuration.", py::arg("theFbo"), py::arg("theWidth"), py::arg("theHeight"), py::arg("theWidthMax"), py::arg("theHeightMax"));
cls_OpenGl_View.def("FBOChangeViewport", (void (OpenGl_View::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Integer)) &OpenGl_View::FBOChangeViewport, "Change offscreen FBO viewport.", py::arg("theFbo"), py::arg("theWidth"), py::arg("theHeight"));
cls_OpenGl_View.def("Background", (Aspect_Background (OpenGl_View::*)() const) &OpenGl_View::Background, "Returns background fill color.");
cls_OpenGl_View.def("SetBackground", (void (OpenGl_View::*)(const Aspect_Background &)) &OpenGl_View::SetBackground, "Sets background fill color.", py::arg("theBackground"));
cls_OpenGl_View.def("GradientBackground", (Aspect_GradientBackground (OpenGl_View::*)() const) &OpenGl_View::GradientBackground, "Returns gradient background fill colors.");
cls_OpenGl_View.def("SetGradientBackground", (void (OpenGl_View::*)(const Aspect_GradientBackground &)) &OpenGl_View::SetGradientBackground, "Sets gradient background fill colors.", py::arg("theBackground"));
cls_OpenGl_View.def("BackgroundImage", (TCollection_AsciiString (OpenGl_View::*)()) &OpenGl_View::BackgroundImage, "Returns background image texture file path.");
cls_OpenGl_View.def("SetBackgroundImage", (void (OpenGl_View::*)(const TCollection_AsciiString &)) &OpenGl_View::SetBackgroundImage, "Sets background image texture file path.", py::arg("theFilePath"));
cls_OpenGl_View.def("BackgroundImageStyle", (Aspect_FillMethod (OpenGl_View::*)() const) &OpenGl_View::BackgroundImageStyle, "Returns background image fill style.");
cls_OpenGl_View.def("SetBackgroundImageStyle", (void (OpenGl_View::*)(const Aspect_FillMethod)) &OpenGl_View::SetBackgroundImageStyle, "Sets background image fill style.", py::arg("theFillStyle"));
cls_OpenGl_View.def("TextureEnv", (opencascade::handle<Graphic3d_TextureEnv> (OpenGl_View::*)() const) &OpenGl_View::TextureEnv, "Returns environment texture set for the view.");
cls_OpenGl_View.def("SetTextureEnv", (void (OpenGl_View::*)(const opencascade::handle<Graphic3d_TextureEnv> &)) &OpenGl_View::SetTextureEnv, "Sets environment texture for the view.", py::arg("theTextureEnv"));
cls_OpenGl_View.def("IsCullingEnabled", (Standard_Boolean (OpenGl_View::*)() const) &OpenGl_View::IsCullingEnabled, "Returns the state of frustum culling optimization.");
cls_OpenGl_View.def("SetCullingEnabled", (void (OpenGl_View::*)(const Standard_Boolean)) &OpenGl_View::SetCullingEnabled, "Enables or disables frustum culling optimization.", py::arg("theIsEnabled"));
cls_OpenGl_View.def("BackfacingModel", (Graphic3d_TypeOfBackfacingModel (OpenGl_View::*)() const) &OpenGl_View::BackfacingModel, "Return backfacing model used for the view.");
cls_OpenGl_View.def("SetBackfacingModel", (void (OpenGl_View::*)(const Graphic3d_TypeOfBackfacingModel)) &OpenGl_View::SetBackfacingModel, "Sets backfacing model for the view.", py::arg("theModel"));
cls_OpenGl_View.def("Camera", (const opencascade::handle<Graphic3d_Camera> & (OpenGl_View::*)() const) &OpenGl_View::Camera, "Returns camera object of the view.");
cls_OpenGl_View.def("LocalOrigin", (const gp_XYZ & (OpenGl_View::*)() const) &OpenGl_View::LocalOrigin, "Returns local camera origin currently set for rendering, might be modified during rendering.");
cls_OpenGl_View.def("SetLocalOrigin", (void (OpenGl_View::*)(const gp_XYZ &)) &OpenGl_View::SetLocalOrigin, "Setup local camera origin currently set for rendering.", py::arg("theOrigin"));
cls_OpenGl_View.def("SetCamera", (void (OpenGl_View::*)(const opencascade::handle<Graphic3d_Camera> &)) &OpenGl_View::SetCamera, "Sets camera used by the view.", py::arg("theCamera"));
cls_OpenGl_View.def("Lights", (const opencascade::handle<Graphic3d_LightSet> & (OpenGl_View::*)() const) &OpenGl_View::Lights, "Returns list of lights of the view.");
cls_OpenGl_View.def("SetLights", (void (OpenGl_View::*)(const opencascade::handle<Graphic3d_LightSet> &)) &OpenGl_View::SetLights, "Sets list of lights for the view.", py::arg("theLights"));
cls_OpenGl_View.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (OpenGl_View::*)() const) &OpenGl_View::ClipPlanes, "Returns list of clip planes set for the view.");
cls_OpenGl_View.def("SetClipPlanes", (void (OpenGl_View::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &OpenGl_View::SetClipPlanes, "Sets list of clip planes for the view.", py::arg("thePlanes"));
cls_OpenGl_View.def("DiagnosticInformation", (void (OpenGl_View::*)(TColStd_IndexedDataMapOfStringString &, Graphic3d_DiagnosticInfo) const) &OpenGl_View::DiagnosticInformation, "Fill in the dictionary with diagnostic info. Should be called within rendering thread.", py::arg("theDict"), py::arg("theFlags"));
cls_OpenGl_View.def("BackgroundColor", (const Quantity_ColorRGBA & (OpenGl_View::*)() const) &OpenGl_View::BackgroundColor, "Returns background color.");
cls_OpenGl_View.def("ChangeGraduatedTrihedron", (OpenGl_GraduatedTrihedron & (OpenGl_View::*)()) &OpenGl_View::ChangeGraduatedTrihedron, "Change graduated trihedron.");
cls_OpenGl_View.def("SetTextureEnv", (void (OpenGl_View::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_TextureEnv> &)) &OpenGl_View::SetTextureEnv, "None", py::arg("theCtx"), py::arg("theTexture"));
cls_OpenGl_View.def("SetBackgroundTextureStyle", (void (OpenGl_View::*)(const Aspect_FillMethod)) &OpenGl_View::SetBackgroundTextureStyle, "None", py::arg("FillStyle"));
cls_OpenGl_View.def("SetBackgroundGradient", (void (OpenGl_View::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod)) &OpenGl_View::SetBackgroundGradient, "None", py::arg("AColor1"), py::arg("AColor2"), py::arg("AType"));
cls_OpenGl_View.def("SetBackgroundGradientType", (void (OpenGl_View::*)(const Aspect_GradientFillMethod)) &OpenGl_View::SetBackgroundGradientType, "None", py::arg("AType"));
cls_OpenGl_View.def("LayerList", (const OpenGl_LayerList & (OpenGl_View::*)() const) &OpenGl_View::LayerList, "Returns list of OpenGL Z-layers.");
cls_OpenGl_View.def("GlWindow", (const opencascade::handle<OpenGl_Window> (OpenGl_View::*)() const) &OpenGl_View::GlWindow, "Returns OpenGL window implementation.");
cls_OpenGl_View.def("GlTextureEnv", (const opencascade::handle<OpenGl_TextureSet> & (OpenGl_View::*)() const) &OpenGl_View::GlTextureEnv, "Returns OpenGL environment map.");
cls_OpenGl_View.def("BVHTreeSelector", (const OpenGl_BVHTreeSelector & (OpenGl_View::*)() const) &OpenGl_View::BVHTreeSelector, "Returns selector for BVH tree, providing a possibility to store information about current view volume and to detect which objects are overlapping it.");
cls_OpenGl_View.def("HasImmediateStructures", (bool (OpenGl_View::*)() const) &OpenGl_View::HasImmediateStructures, "Returns true if there are immediate structures to display");
// cls_OpenGl_View.def_static("operator new_", (void * (*)(size_t)) &OpenGl_View::operator new, "None", py::arg("theSize"));
// cls_OpenGl_View.def_static("operator delete_", (void (*)(void *)) &OpenGl_View::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_View.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_View::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_View.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_View::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_View.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_View::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_View.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_View::operator delete, "None", py::arg(""), py::arg(""));
cls_OpenGl_View.def_static("get_type_name_", (const char * (*)()) &OpenGl_View::get_type_name, "None");
cls_OpenGl_View.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_View::get_type_descriptor, "None");
cls_OpenGl_View.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_View::*)() const) &OpenGl_View::DynamicType, "None");

// Enums
*/

}