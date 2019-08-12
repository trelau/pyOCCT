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
#include <Graphic3d_DataStructureManager.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_CView.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <Graphic3d_TypeOfVisualization.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_MapOfStructure.hxx>
#include <Graphic3d_NMapOfTransient.hxx>
#include <Bnd_Box.hxx>
#include <Graphic3d_TypeOfAnswer.hxx>
#include <Graphic3d_TypeOfStructure.hxx>
#include <Geom_Transformation.hxx>
#include <Aspect_Window.hxx>
#include <Aspect_RenderingContext.hxx>
#include <Graphic3d_GraduatedTrihedron.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Image_PixMap.hxx>
#include <Graphic3d_BufferType.hxx>
#include <Graphic3d_ExportFormat.hxx>
#include <Graphic3d_SortType.hxx>
#include <Graphic3d_Camera.hxx>
#include <Graphic3d_ZLayerSettings.hxx>
#include <Standard_Transient.hxx>
#include <Graphic3d_RenderingParams.hxx>
#include <Aspect_Background.hxx>
#include <Aspect_GradientBackground.hxx>
#include <TCollection_AsciiString.hxx>
#include <Aspect_FillMethod.hxx>
#include <Graphic3d_TextureEnv.hxx>
#include <Graphic3d_TypeOfBackfacingModel.hxx>
#include <Graphic3d_LightSet.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <TColStd_IndexedDataMapOfStringString.hxx>
#include <Graphic3d_DiagnosticInfo.hxx>
#include <Graphic3d_CStructure.hxx>
#include <Graphic3d_SequenceOfStructure.hxx>

void bind_Graphic3d_CView(py::module &mod){

py::class_<Graphic3d_CView, opencascade::handle<Graphic3d_CView>, Graphic3d_DataStructureManager> cls_Graphic3d_CView(mod, "Graphic3d_CView", "Base class of a graphical view that carries out rendering process for a concrete implementation of graphical driver. Provides virtual interfaces for redrawing its contents, management of displayed structures and render settings. The source code of the class itself implements functionality related to management of computed (HLR or 'view-dependent') structures.");

// Fields

// Methods
cls_Graphic3d_CView.def_static("get_type_name_", (const char * (*)()) &Graphic3d_CView::get_type_name, "None");
cls_Graphic3d_CView.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_CView::get_type_descriptor, "None");
cls_Graphic3d_CView.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_CView::*)() const) &Graphic3d_CView::DynamicType, "None");
cls_Graphic3d_CView.def("Identification", (Standard_Integer (Graphic3d_CView::*)() const) &Graphic3d_CView::Identification, "Returns the identification number of the view.");
cls_Graphic3d_CView.def("Activate", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Activate, "Activates the view. Maps presentations defined within structure manager onto this view.");
cls_Graphic3d_CView.def("Deactivate", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Deactivate, "Deactivates the view. Unmaps presentations defined within structure manager. The view in deactivated state will ignore actions on structures such as Display().");
cls_Graphic3d_CView.def("IsActive", (Standard_Boolean (Graphic3d_CView::*)() const) &Graphic3d_CView::IsActive, "Returns the activity flag of the view.");
cls_Graphic3d_CView.def("Remove", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Remove, "Erases the view and removes from graphic driver. No more graphic operations are allowed in this view after the call.");
cls_Graphic3d_CView.def("IsRemoved", (Standard_Boolean (Graphic3d_CView::*)() const) &Graphic3d_CView::IsRemoved, "Returns true if the view was removed.");
cls_Graphic3d_CView.def("ShadingModel", (Graphic3d_TypeOfShadingModel (Graphic3d_CView::*)() const) &Graphic3d_CView::ShadingModel, "Returns default Shading Model of the view; Graphic3d_TOSM_FRAGMENT by default.");
cls_Graphic3d_CView.def("SetShadingModel", (void (Graphic3d_CView::*)(Graphic3d_TypeOfShadingModel)) &Graphic3d_CView::SetShadingModel, "Sets default Shading Model of the view. Will throw an exception on attempt to set Graphic3d_TOSM_DEFAULT.", py::arg("theModel"));
cls_Graphic3d_CView.def("VisualizationType", (Graphic3d_TypeOfVisualization (Graphic3d_CView::*)() const) &Graphic3d_CView::VisualizationType, "Returns visualization type of the view.");
cls_Graphic3d_CView.def("SetVisualizationType", (void (Graphic3d_CView::*)(const Graphic3d_TypeOfVisualization)) &Graphic3d_CView::SetVisualizationType, "Sets visualization type of the view.", py::arg("theType"));
cls_Graphic3d_CView.def("SetComputedMode", (void (Graphic3d_CView::*)(const Standard_Boolean)) &Graphic3d_CView::SetComputedMode, "Switches computed HLR mode in the view", py::arg("theMode"));
cls_Graphic3d_CView.def("ComputedMode", (Standard_Boolean (Graphic3d_CView::*)() const) &Graphic3d_CView::ComputedMode, "Returns the computed HLR mode state");
cls_Graphic3d_CView.def("ReCompute", (void (Graphic3d_CView::*)(const opencascade::handle<Graphic3d_Structure> &)) &Graphic3d_CView::ReCompute, "Computes the new presentation of the structure displayed in this view with the type Graphic3d_TOS_COMPUTED.", py::arg("theStructure"));
cls_Graphic3d_CView.def("Update", [](Graphic3d_CView &self) -> void { return self.Update(); });
cls_Graphic3d_CView.def("Update", (void (Graphic3d_CView::*)(const Graphic3d_ZLayerId)) &Graphic3d_CView::Update, "Invalidates bounding box of specified ZLayerId.", py::arg("theLayerId"));
cls_Graphic3d_CView.def("Compute", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Compute, "Computes the new presentation of the structures displayed in this view with the type Graphic3d_TOS_COMPUTED.");
cls_Graphic3d_CView.def("ContainsFacet", (Standard_Boolean (Graphic3d_CView::*)() const) &Graphic3d_CView::ContainsFacet, "Returns Standard_True if one of the structures displayed in the view contains Polygons, Triangles or Quadrangles.");
cls_Graphic3d_CView.def("ContainsFacet", (Standard_Boolean (Graphic3d_CView::*)(const Graphic3d_MapOfStructure &) const) &Graphic3d_CView::ContainsFacet, "Returns Standard_True if one of the structures in the set contains Polygons, Triangles or Quadrangles.", py::arg("theSet"));
cls_Graphic3d_CView.def("DisplayedStructures", (void (Graphic3d_CView::*)(Graphic3d_MapOfStructure &) const) &Graphic3d_CView::DisplayedStructures, "Returns the set of structures displayed in this view.", py::arg("theStructures"));
cls_Graphic3d_CView.def("NumberOfDisplayedStructures", (Standard_Integer (Graphic3d_CView::*)() const) &Graphic3d_CView::NumberOfDisplayedStructures, "Returns number of displayed structures in the view.");
cls_Graphic3d_CView.def("HiddenObjects", (const opencascade::handle<Graphic3d_NMapOfTransient> & (Graphic3d_CView::*)() const) &Graphic3d_CView::HiddenObjects, "Returns map of objects hidden within this specific view (not viewer-wise).");
cls_Graphic3d_CView.def("ChangeHiddenObjects", (opencascade::handle<Graphic3d_NMapOfTransient> & (Graphic3d_CView::*)()) &Graphic3d_CView::ChangeHiddenObjects, "Returns map of objects hidden within this specific view (not viewer-wise).");
cls_Graphic3d_CView.def("IsComputed", (Standard_Boolean (Graphic3d_CView::*)(const Standard_Integer, opencascade::handle<Graphic3d_Structure> &) const) &Graphic3d_CView::IsComputed, "Returns Standard_True in case if the structure with the given <theStructId> is in list of structures to be computed and stores computed struct to <theComputedStruct>.", py::arg("theStructId"), py::arg("theComputedStruct"));
cls_Graphic3d_CView.def("MinMaxValues", [](Graphic3d_CView &self) -> Bnd_Box { return self.MinMaxValues(); });
cls_Graphic3d_CView.def("MinMaxValues", (Bnd_Box (Graphic3d_CView::*)(const Standard_Boolean) const) &Graphic3d_CView::MinMaxValues, "Returns the bounding box of all structures displayed in the view. If theToIncludeAuxiliary is TRUE, then the boundary box also includes minimum and maximum limits of graphical elements forming parts of infinite and other auxiliary structures.", py::arg("theToIncludeAuxiliary"));
cls_Graphic3d_CView.def("MinMaxValues", [](Graphic3d_CView &self, const Graphic3d_MapOfStructure & a0) -> Bnd_Box { return self.MinMaxValues(a0); });
cls_Graphic3d_CView.def("MinMaxValues", (Bnd_Box (Graphic3d_CView::*)(const Graphic3d_MapOfStructure &, const Standard_Boolean) const) &Graphic3d_CView::MinMaxValues, "Returns the coordinates of the boundary box of all structures in the set <theSet>. If <theToIgnoreInfiniteFlag> is TRUE, then the boundary box also includes minimum and maximum limits of graphical elements forming parts of infinite structures.", py::arg("theSet"), py::arg("theToIncludeAuxiliary"));
cls_Graphic3d_CView.def("StructureManager", (const opencascade::handle<Graphic3d_StructureManager> & (Graphic3d_CView::*)() const) &Graphic3d_CView::StructureManager, "Returns the structure manager handle which manage structures associated with this view.");
cls_Graphic3d_CView.def("Redraw", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Redraw, "Redraw content of the view.");
cls_Graphic3d_CView.def("RedrawImmediate", (void (Graphic3d_CView::*)()) &Graphic3d_CView::RedrawImmediate, "Redraw immediate content of the view.");
cls_Graphic3d_CView.def("Invalidate", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Invalidate, "Invalidates content of the view but does not redraw it.");
cls_Graphic3d_CView.def("IsInvalidated", (Standard_Boolean (Graphic3d_CView::*)()) &Graphic3d_CView::IsInvalidated, "Return true if view content cache has been invalidated.");
cls_Graphic3d_CView.def("Resized", (void (Graphic3d_CView::*)()) &Graphic3d_CView::Resized, "Handle changing size of the rendering window.");
cls_Graphic3d_CView.def("SetImmediateModeDrawToFront", (Standard_Boolean (Graphic3d_CView::*)(const Standard_Boolean)) &Graphic3d_CView::SetImmediateModeDrawToFront, "Returns previous mode.", py::arg("theDrawToFrontBuffer"));
cls_Graphic3d_CView.def("SetWindow", [](Graphic3d_CView &self, const opencascade::handle<Aspect_Window> & a0) -> void { return self.SetWindow(a0); });
cls_Graphic3d_CView.def("SetWindow", (void (Graphic3d_CView::*)(const opencascade::handle<Aspect_Window> &, const Aspect_RenderingContext)) &Graphic3d_CView::SetWindow, "Creates and maps rendering window to the view.", py::arg("theWindow"), py::arg("theContext"));
cls_Graphic3d_CView.def("Window", (opencascade::handle<Aspect_Window> (Graphic3d_CView::*)() const) &Graphic3d_CView::Window, "Returns the window associated to the view.");
cls_Graphic3d_CView.def("IsDefined", (Standard_Boolean (Graphic3d_CView::*)() const) &Graphic3d_CView::IsDefined, "Returns True if the window associated to the view is defined.");
cls_Graphic3d_CView.def("GetGraduatedTrihedron", (const Graphic3d_GraduatedTrihedron & (Graphic3d_CView::*)()) &Graphic3d_CView::GetGraduatedTrihedron, "Returns data of a graduated trihedron");
cls_Graphic3d_CView.def("GraduatedTrihedronDisplay", (void (Graphic3d_CView::*)(const Graphic3d_GraduatedTrihedron &)) &Graphic3d_CView::GraduatedTrihedronDisplay, "Displays Graduated Trihedron.", py::arg("theTrihedronData"));
cls_Graphic3d_CView.def("GraduatedTrihedronErase", (void (Graphic3d_CView::*)()) &Graphic3d_CView::GraduatedTrihedronErase, "Erases Graduated Trihedron.");
cls_Graphic3d_CView.def("GraduatedTrihedronMinMaxValues", (void (Graphic3d_CView::*)(const Graphic3d_Vec3, const Graphic3d_Vec3)) &Graphic3d_CView::GraduatedTrihedronMinMaxValues, "Sets minimum and maximum points of scene bounding box for Graduated Trihedron stored in graphic view object.", py::arg("theMin"), py::arg("theMax"));
cls_Graphic3d_CView.def("BufferDump", (Standard_Boolean (Graphic3d_CView::*)(Image_PixMap &, const Graphic3d_BufferType &)) &Graphic3d_CView::BufferDump, "Dump active rendering buffer into specified memory buffer.", py::arg("theImage"), py::arg("theBufferType"));
cls_Graphic3d_CView.def("Export", [](Graphic3d_CView &self, const Standard_CString a0, const Graphic3d_ExportFormat a1) -> Standard_Boolean { return self.Export(a0, a1); });
cls_Graphic3d_CView.def("Export", (Standard_Boolean (Graphic3d_CView::*)(const Standard_CString, const Graphic3d_ExportFormat, const Graphic3d_SortType)) &Graphic3d_CView::Export, "Export scene into the one of the Vector graphics formats (SVG, PS, PDF...). In contrast to Bitmaps, Vector graphics is scalable (so you may got quality benefits on printing to laser printer). Notice however that results may differ a lot and do not contain some elements.", py::arg("theFileName"), py::arg("theFormat"), py::arg("theSortType"));
cls_Graphic3d_CView.def("InvalidateBVHData", (void (Graphic3d_CView::*)(const Graphic3d_ZLayerId)) &Graphic3d_CView::InvalidateBVHData, "Marks BVH tree and the set of BVH primitives of correspondent priority list with id theLayerId as outdated.", py::arg("theLayerId"));
cls_Graphic3d_CView.def("AddZLayer", (void (Graphic3d_CView::*)(const Graphic3d_ZLayerId)) &Graphic3d_CView::AddZLayer, "Add a new top-level z layer with ID <theLayerId> for the view. Z layers allow drawing structures in higher layers in foreground of structures in lower layers. To add a structure to desired layer on display it is necessary to set the layer ID for the structure.", py::arg("theLayerId"));
cls_Graphic3d_CView.def("ZLayerMax", (Standard_Integer (Graphic3d_CView::*)() const) &Graphic3d_CView::ZLayerMax, "Returns the maximum Z layer ID. First layer ID is Graphic3d_ZLayerId_Default, last ID is ZLayerMax().");
cls_Graphic3d_CView.def("InvalidateZLayerBoundingBox", (void (Graphic3d_CView::*)(const Graphic3d_ZLayerId) const) &Graphic3d_CView::InvalidateZLayerBoundingBox, "Returns the bounding box of all structures displayed in the Z layer.", py::arg("theLayerId"));
cls_Graphic3d_CView.def("ZLayerBoundingBox", (Bnd_Box (Graphic3d_CView::*)(const Graphic3d_ZLayerId, const opencascade::handle<Graphic3d_Camera> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean) const) &Graphic3d_CView::ZLayerBoundingBox, "Returns the bounding box of all structures displayed in the Z layer.", py::arg("theLayerId"), py::arg("theCamera"), py::arg("theWindowWidth"), py::arg("theWindowHeight"), py::arg("theToIncludeAuxiliary"));
cls_Graphic3d_CView.def("RemoveZLayer", (void (Graphic3d_CView::*)(const Graphic3d_ZLayerId)) &Graphic3d_CView::RemoveZLayer, "Remove Z layer from the specified view. All structures displayed at the moment in layer will be displayed in default layer ( the bottom-level z layer ). To unset layer ID from associated structures use method UnsetZLayer (...).", py::arg("theLayerId"));
cls_Graphic3d_CView.def("SetZLayerSettings", (void (Graphic3d_CView::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &)) &Graphic3d_CView::SetZLayerSettings, "Sets the settings for a single Z layer of specified view.", py::arg("theLayerId"), py::arg("theSettings"));
cls_Graphic3d_CView.def("ConsiderZoomPersistenceObjects", (Standard_Real (Graphic3d_CView::*)()) &Graphic3d_CView::ConsiderZoomPersistenceObjects, "Returns zoom-scale factor.");
cls_Graphic3d_CView.def("FBO", (opencascade::handle<Standard_Transient> (Graphic3d_CView::*)() const) &Graphic3d_CView::FBO, "Returns pointer to an assigned framebuffer object.");
cls_Graphic3d_CView.def("SetFBO", (void (Graphic3d_CView::*)(const opencascade::handle<Standard_Transient> &)) &Graphic3d_CView::SetFBO, "Sets framebuffer object for offscreen rendering.", py::arg("theFbo"));
cls_Graphic3d_CView.def("FBOCreate", (opencascade::handle<Standard_Transient> (Graphic3d_CView::*)(const Standard_Integer, const Standard_Integer)) &Graphic3d_CView::FBOCreate, "Generate offscreen FBO in the graphic library. If not supported on hardware returns NULL.", py::arg("theWidth"), py::arg("theHeight"));
cls_Graphic3d_CView.def("FBORelease", (void (Graphic3d_CView::*)(opencascade::handle<Standard_Transient> &)) &Graphic3d_CView::FBORelease, "Remove offscreen FBO from the graphic library", py::arg("theFbo"));
cls_Graphic3d_CView.def("FBOGetDimensions", [](Graphic3d_CView &self, const opencascade::handle<Standard_Transient> & theFbo, Standard_Integer & theWidth, Standard_Integer & theHeight, Standard_Integer & theWidthMax, Standard_Integer & theHeightMax){ self.FBOGetDimensions(theFbo, theWidth, theHeight, theWidthMax, theHeightMax); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(theWidth, theHeight, theWidthMax, theHeightMax); }, "Read offscreen FBO configuration.", py::arg("theFbo"), py::arg("theWidth"), py::arg("theHeight"), py::arg("theWidthMax"), py::arg("theHeightMax"));
cls_Graphic3d_CView.def("FBOChangeViewport", (void (Graphic3d_CView::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Integer)) &Graphic3d_CView::FBOChangeViewport, "Change offscreen FBO viewport.", py::arg("theFbo"), py::arg("theWidth"), py::arg("theHeight"));
cls_Graphic3d_CView.def("CopySettings", (void (Graphic3d_CView::*)(const opencascade::handle<Graphic3d_CView> &)) &Graphic3d_CView::CopySettings, "Copy visualization settings from another view. Method is used for cloning views in viewer when its required to create view with same view properties.", py::arg("theOther"));
cls_Graphic3d_CView.def("RenderingParams", (const Graphic3d_RenderingParams & (Graphic3d_CView::*)() const) &Graphic3d_CView::RenderingParams, "Returns current rendering parameters and effect settings.");
cls_Graphic3d_CView.def("ChangeRenderingParams", (Graphic3d_RenderingParams & (Graphic3d_CView::*)()) &Graphic3d_CView::ChangeRenderingParams, "Returns reference to current rendering parameters and effect settings.");
cls_Graphic3d_CView.def("Background", (Aspect_Background (Graphic3d_CView::*)() const) &Graphic3d_CView::Background, "Returns background fill color.");
cls_Graphic3d_CView.def("SetBackground", (void (Graphic3d_CView::*)(const Aspect_Background &)) &Graphic3d_CView::SetBackground, "Sets background fill color.", py::arg("theBackground"));
cls_Graphic3d_CView.def("GradientBackground", (Aspect_GradientBackground (Graphic3d_CView::*)() const) &Graphic3d_CView::GradientBackground, "Returns gradient background fill colors.");
cls_Graphic3d_CView.def("SetGradientBackground", (void (Graphic3d_CView::*)(const Aspect_GradientBackground &)) &Graphic3d_CView::SetGradientBackground, "Sets gradient background fill colors.", py::arg("theBackground"));
cls_Graphic3d_CView.def("BackgroundImage", (TCollection_AsciiString (Graphic3d_CView::*)()) &Graphic3d_CView::BackgroundImage, "Returns background image texture file path.");
cls_Graphic3d_CView.def("SetBackgroundImage", (void (Graphic3d_CView::*)(const TCollection_AsciiString &)) &Graphic3d_CView::SetBackgroundImage, "Sets background image texture file path.", py::arg("theFilePath"));
cls_Graphic3d_CView.def("BackgroundImageStyle", (Aspect_FillMethod (Graphic3d_CView::*)() const) &Graphic3d_CView::BackgroundImageStyle, "Returns background image fill style.");
cls_Graphic3d_CView.def("SetBackgroundImageStyle", (void (Graphic3d_CView::*)(const Aspect_FillMethod)) &Graphic3d_CView::SetBackgroundImageStyle, "Sets background image fill style.", py::arg("theFillStyle"));
cls_Graphic3d_CView.def("TextureEnv", (opencascade::handle<Graphic3d_TextureEnv> (Graphic3d_CView::*)() const) &Graphic3d_CView::TextureEnv, "Returns environment texture set for the view.");
cls_Graphic3d_CView.def("SetTextureEnv", (void (Graphic3d_CView::*)(const opencascade::handle<Graphic3d_TextureEnv> &)) &Graphic3d_CView::SetTextureEnv, "Sets environment texture for the view.", py::arg("theTextureEnv"));
cls_Graphic3d_CView.def("IsCullingEnabled", (Standard_Boolean (Graphic3d_CView::*)() const) &Graphic3d_CView::IsCullingEnabled, "Returns the state of frustum culling optimization.");
cls_Graphic3d_CView.def("SetCullingEnabled", (void (Graphic3d_CView::*)(const Standard_Boolean)) &Graphic3d_CView::SetCullingEnabled, "Enables or disables frustum culling optimization.", py::arg("theIsEnabled"));
cls_Graphic3d_CView.def("BackfacingModel", (Graphic3d_TypeOfBackfacingModel (Graphic3d_CView::*)() const) &Graphic3d_CView::BackfacingModel, "Return backfacing model used for the view.");
cls_Graphic3d_CView.def("SetBackfacingModel", (void (Graphic3d_CView::*)(const Graphic3d_TypeOfBackfacingModel)) &Graphic3d_CView::SetBackfacingModel, "Sets backfacing model for the view.", py::arg("theModel"));
cls_Graphic3d_CView.def("Camera", (const opencascade::handle<Graphic3d_Camera> & (Graphic3d_CView::*)() const) &Graphic3d_CView::Camera, "Returns camera object of the view.");
cls_Graphic3d_CView.def("SetCamera", (void (Graphic3d_CView::*)(const opencascade::handle<Graphic3d_Camera> &)) &Graphic3d_CView::SetCamera, "Sets camera used by the view.", py::arg("theCamera"));
cls_Graphic3d_CView.def("Lights", (const opencascade::handle<Graphic3d_LightSet> & (Graphic3d_CView::*)() const) &Graphic3d_CView::Lights, "Returns list of lights of the view.");
cls_Graphic3d_CView.def("SetLights", (void (Graphic3d_CView::*)(const opencascade::handle<Graphic3d_LightSet> &)) &Graphic3d_CView::SetLights, "Sets list of lights for the view.", py::arg("theLights"));
cls_Graphic3d_CView.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (Graphic3d_CView::*)() const) &Graphic3d_CView::ClipPlanes, "Returns list of clip planes set for the view.");
cls_Graphic3d_CView.def("SetClipPlanes", (void (Graphic3d_CView::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &Graphic3d_CView::SetClipPlanes, "Sets list of clip planes for the view.", py::arg("thePlanes"));
cls_Graphic3d_CView.def("DiagnosticInformation", (void (Graphic3d_CView::*)(TColStd_IndexedDataMapOfStringString &, Graphic3d_DiagnosticInfo) const) &Graphic3d_CView::DiagnosticInformation, "Fill in the dictionary with diagnostic info. Should be called within rendering thread.", py::arg("theDict"), py::arg("theFlags"));

// Enums

}