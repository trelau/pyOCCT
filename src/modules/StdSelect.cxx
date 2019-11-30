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
#include <StdSelect_TypeOfSelectionImage.hxx>
#include <StdSelect_DisplayMode.hxx>
#include <StdSelect_TypeOfEdge.hxx>
#include <StdSelect_TypeOfFace.hxx>
#include <StdSelect_SensitivityMode.hxx>
#include <StdSelect_TypeOfResult.hxx>
#include <SelectMgr_ViewerSelector.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <V3d_View.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Image_PixMap.hxx>
#include <SelectMgr_Selection.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Std.hxx>
#include <StdSelect_ViewerSelector3d.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_SequenceOfStructure.hxx>
#include <Standard.hxx>
#include <Prs3d_Drawer.hxx>
#include <StdSelect_BRepSelectionTool.hxx>
#include <StdSelect_BRepOwner.hxx>
#include <StdSelect_EdgeFilter.hxx>
#include <StdSelect_FaceFilter.hxx>
#include <StdSelect_ShapeTypeFilter.hxx>
#include <StdSelect_Prs.hxx>
#include <StdSelect_Shape.hxx>
#include <StdSelect.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <TopoDS_Shape.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <TopLoc_Location.hxx>
#include <V3d_Viewer.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Face.hxx>
#include <Select3D_EntitySequence.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <SelectMgr_Filter.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <StdSelect_IndexedDataMapOfOwnerPrs.hxx>
#include <PrsMgr_PresentableObject.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>

PYBIND11_MODULE(StdSelect, mod) {

py::module::import("OCCT.SelectMgr");
py::module::import("OCCT.Standard");
py::module::import("OCCT.V3d");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Image");
py::module::import("OCCT.gp");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.PrsMgr");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Select3D");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom");

// ENUM: STDSELECT_TYPEOFSELECTIONIMAGE
py::enum_<StdSelect_TypeOfSelectionImage>(mod, "StdSelect_TypeOfSelectionImage", "Type of output selection image.")
	.value("StdSelect_TypeOfSelectionImage_NormalizedDepth", StdSelect_TypeOfSelectionImage::StdSelect_TypeOfSelectionImage_NormalizedDepth)
	.value("StdSelect_TypeOfSelectionImage_NormalizedDepthInverted", StdSelect_TypeOfSelectionImage::StdSelect_TypeOfSelectionImage_NormalizedDepthInverted)
	.value("StdSelect_TypeOfSelectionImage_UnnormalizedDepth", StdSelect_TypeOfSelectionImage::StdSelect_TypeOfSelectionImage_UnnormalizedDepth)
	.value("StdSelect_TypeOfSelectionImage_ColoredDetectedObject", StdSelect_TypeOfSelectionImage::StdSelect_TypeOfSelectionImage_ColoredDetectedObject)
	.value("StdSelect_TypeOfSelectionImage_ColoredEntity", StdSelect_TypeOfSelectionImage::StdSelect_TypeOfSelectionImage_ColoredEntity)
	.value("StdSelect_TypeOfSelectionImage_ColoredOwner", StdSelect_TypeOfSelectionImage::StdSelect_TypeOfSelectionImage_ColoredOwner)
	.value("StdSelect_TypeOfSelectionImage_ColoredSelectionMode", StdSelect_TypeOfSelectionImage::StdSelect_TypeOfSelectionImage_ColoredSelectionMode)
	.export_values();


// ENUM: STDSELECT_DISPLAYMODE
py::enum_<StdSelect_DisplayMode>(mod, "StdSelect_DisplayMode", "None")
	.value("StdSelect_DM_Wireframe", StdSelect_DisplayMode::StdSelect_DM_Wireframe)
	.value("StdSelect_DM_Shading", StdSelect_DisplayMode::StdSelect_DM_Shading)
	.value("StdSelect_DM_HLR", StdSelect_DisplayMode::StdSelect_DM_HLR)
	.export_values();


// ENUM: STDSELECT_TYPEOFEDGE
py::enum_<StdSelect_TypeOfEdge>(mod, "StdSelect_TypeOfEdge", "Provides values for different types of edges. These values are used to filter edges in frameworks inheriting StdSelect_EdgeFilter.")
	.value("StdSelect_AnyEdge", StdSelect_TypeOfEdge::StdSelect_AnyEdge)
	.value("StdSelect_Line", StdSelect_TypeOfEdge::StdSelect_Line)
	.value("StdSelect_Circle", StdSelect_TypeOfEdge::StdSelect_Circle)
	.export_values();


// ENUM: STDSELECT_TYPEOFFACE
py::enum_<StdSelect_TypeOfFace>(mod, "StdSelect_TypeOfFace", "Provides values for different types of faces. These values are used to filter faces in frameworks inheriting StdSelect_FaceFilter.")
	.value("StdSelect_AnyFace", StdSelect_TypeOfFace::StdSelect_AnyFace)
	.value("StdSelect_Plane", StdSelect_TypeOfFace::StdSelect_Plane)
	.value("StdSelect_Cylinder", StdSelect_TypeOfFace::StdSelect_Cylinder)
	.value("StdSelect_Sphere", StdSelect_TypeOfFace::StdSelect_Sphere)
	.value("StdSelect_Torus", StdSelect_TypeOfFace::StdSelect_Torus)
	.value("StdSelect_Revol", StdSelect_TypeOfFace::StdSelect_Revol)
	.value("StdSelect_Cone", StdSelect_TypeOfFace::StdSelect_Cone)
	.export_values();


// ENUM: STDSELECT_SENSITIVITYMODE
py::enum_<StdSelect_SensitivityMode>(mod, "StdSelect_SensitivityMode", "Selection sensitivity mode. SM_WINDOW mode uses the specified pixel tolerance to compute the sensitivity value, SM_VIEW mode allows to define the sensitivity manually.")
	.value("StdSelect_SM_WINDOW", StdSelect_SensitivityMode::StdSelect_SM_WINDOW)
	.value("StdSelect_SM_VIEW", StdSelect_SensitivityMode::StdSelect_SM_VIEW)
	.export_values();


// ENUM: STDSELECT_TYPEOFRESULT
py::enum_<StdSelect_TypeOfResult>(mod, "StdSelect_TypeOfResult", "Provides values for type of result. These are used to specify whether the result is to be simple or whether it may be multiple.")
	.value("StdSelect_TOR_SIMPLE", StdSelect_TypeOfResult::StdSelect_TOR_SIMPLE)
	.value("StdSelect_TOR_MULTIPLE", StdSelect_TypeOfResult::StdSelect_TOR_MULTIPLE)
	.export_values();


// CLASS: STDSELECT_VIEWERSELECTOR3D
py::class_<StdSelect_ViewerSelector3d, opencascade::handle<StdSelect_ViewerSelector3d>, SelectMgr_ViewerSelector> cls_StdSelect_ViewerSelector3d(mod, "StdSelect_ViewerSelector3d", "Selector Usable by Viewers from V3d");

// Constructors
cls_StdSelect_ViewerSelector3d.def(py::init<>());

// Methods
cls_StdSelect_ViewerSelector3d.def("SetPixelTolerance", (void (StdSelect_ViewerSelector3d::*)(const Standard_Integer)) &StdSelect_ViewerSelector3d::SetPixelTolerance, "Sets the pixel tolerance <theTolerance>.", py::arg("theTolerance"));
cls_StdSelect_ViewerSelector3d.def("PixelTolerance", (Standard_Integer (StdSelect_ViewerSelector3d::*)() const) &StdSelect_ViewerSelector3d::PixelTolerance, "Returns the pixel tolerance.");
cls_StdSelect_ViewerSelector3d.def("Pick", (void (StdSelect_ViewerSelector3d::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &)) &StdSelect_ViewerSelector3d::Pick, "Picks the sensitive entity at the pixel coordinates of the mouse <theXPix> and <theYPix>. The selector looks for touched areas and owners.", py::arg("theXPix"), py::arg("theYPix"), py::arg("theView"));
cls_StdSelect_ViewerSelector3d.def("Pick", (void (StdSelect_ViewerSelector3d::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &)) &StdSelect_ViewerSelector3d::Pick, "Picks the sensitive entity according to the minimum and maximum pixel values <theXPMin>, <theYPMin>, <theXPMax> and <theYPMax> defining a 2D area for selection in the 3D view aView.", py::arg("theXPMin"), py::arg("theYPMin"), py::arg("theXPMax"), py::arg("theYPMax"), py::arg("theView"));
cls_StdSelect_ViewerSelector3d.def("Pick", (void (StdSelect_ViewerSelector3d::*)(const TColgp_Array1OfPnt2d &, const opencascade::handle<V3d_View> &)) &StdSelect_ViewerSelector3d::Pick, "pick action - input pixel values for polyline selection for selection.", py::arg("thePolyline"), py::arg("theView"));
cls_StdSelect_ViewerSelector3d.def("ToPixMap", [](StdSelect_ViewerSelector3d &self, Image_PixMap & a0, const opencascade::handle<V3d_View> & a1, const StdSelect_TypeOfSelectionImage a2) -> Standard_Boolean { return self.ToPixMap(a0, a1, a2); });
cls_StdSelect_ViewerSelector3d.def("ToPixMap", (Standard_Boolean (StdSelect_ViewerSelector3d::*)(Image_PixMap &, const opencascade::handle<V3d_View> &, const StdSelect_TypeOfSelectionImage, const Standard_Integer)) &StdSelect_ViewerSelector3d::ToPixMap, "Dump of detection results into image. This method performs axis picking for each pixel in the image and generates a color depending on picking results and selection image type.", py::arg("theImage"), py::arg("theView"), py::arg("theType"), py::arg("thePickedIndex"));
cls_StdSelect_ViewerSelector3d.def("DisplaySensitive", (void (StdSelect_ViewerSelector3d::*)(const opencascade::handle<V3d_View> &)) &StdSelect_ViewerSelector3d::DisplaySensitive, "Displays sensitives in view <theView>.", py::arg("theView"));
cls_StdSelect_ViewerSelector3d.def("ClearSensitive", (void (StdSelect_ViewerSelector3d::*)(const opencascade::handle<V3d_View> &)) &StdSelect_ViewerSelector3d::ClearSensitive, "None", py::arg("theView"));
cls_StdSelect_ViewerSelector3d.def("DisplaySensitive", [](StdSelect_ViewerSelector3d &self, const opencascade::handle<SelectMgr_Selection> & a0, const gp_Trsf & a1, const opencascade::handle<V3d_View> & a2) -> void { return self.DisplaySensitive(a0, a1, a2); });
cls_StdSelect_ViewerSelector3d.def("DisplaySensitive", (void (StdSelect_ViewerSelector3d::*)(const opencascade::handle<SelectMgr_Selection> &, const gp_Trsf &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &StdSelect_ViewerSelector3d::DisplaySensitive, "None", py::arg("theSel"), py::arg("theTrsf"), py::arg("theView"), py::arg("theToClearOthers"));
cls_StdSelect_ViewerSelector3d.def_static("get_type_name_", (const char * (*)()) &StdSelect_ViewerSelector3d::get_type_name, "None");
cls_StdSelect_ViewerSelector3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_ViewerSelector3d::get_type_descriptor, "None");
cls_StdSelect_ViewerSelector3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_ViewerSelector3d::*)() const) &StdSelect_ViewerSelector3d::DynamicType, "None");

// CLASS: STDSELECT
py::class_<StdSelect> cls_StdSelect(mod, "StdSelect", "The StdSelect package provides the following services - the definition of selection modes for topological shapes - the definition of several concrete filtertandard Selection2d.ap classes - 2D and 3D viewer selectors. Note that each new Interactive Object must have all its selection modes defined. Standard Classes is useful to build 3D Selectable Objects, and to process 3D Selections:");

// Methods
// cls_StdSelect.def_static("operator new_", (void * (*)(size_t)) &StdSelect::operator new, "None", py::arg("theSize"));
// cls_StdSelect.def_static("operator delete_", (void (*)(void *)) &StdSelect::operator delete, "None", py::arg("theAddress"));
// cls_StdSelect.def_static("operator new[]_", (void * (*)(size_t)) &StdSelect::operator new[], "None", py::arg("theSize"));
// cls_StdSelect.def_static("operator delete[]_", (void (*)(void *)) &StdSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StdSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StdSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdSelect.def_static("operator delete_", (void (*)(void *, void *)) &StdSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StdSelect.def_static("SetDrawerForBRepOwner_", (void (*)(const opencascade::handle<SelectMgr_Selection> &, const opencascade::handle<Prs3d_Drawer> &)) &StdSelect::SetDrawerForBRepOwner, "puts The same drawer in every BRepOwner Of SensitivePrimitive Used Only for hilight Of BRepOwner...", py::arg("aSelection"), py::arg("aDrawer"));

// CLASS: STDSELECT_BREPOWNER
py::class_<StdSelect_BRepOwner, opencascade::handle<StdSelect_BRepOwner>, SelectMgr_EntityOwner> cls_StdSelect_BRepOwner(mod, "StdSelect_BRepOwner", "Defines Specific Owners for Sensitive Primitives (Sensitive Segments,Circles...). Used in Dynamic Selection Mechanism. A BRepOwner has an Owner (the shape it represents) and Users (One or More Transient entities). The highlight-unhighlight methods are empty and must be redefined by each User.");

// Constructors
cls_StdSelect_BRepOwner.def(py::init<const Standard_Integer>(), py::arg("aPriority"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &, const Standard_Integer>(), py::arg("aShape"), py::arg("aPriority"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &, const Standard_Integer, const Standard_Boolean>(), py::arg("aShape"), py::arg("aPriority"), py::arg("ComesFromDecomposition"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &, const opencascade::handle<SelectMgr_SelectableObject> &>(), py::arg("aShape"), py::arg("theOrigin"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &, const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer>(), py::arg("aShape"), py::arg("theOrigin"), py::arg("aPriority"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &, const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const Standard_Boolean>(), py::arg("aShape"), py::arg("theOrigin"), py::arg("aPriority"), py::arg("FromDecomposition"));

// Methods
cls_StdSelect_BRepOwner.def_static("get_type_name_", (const char * (*)()) &StdSelect_BRepOwner::get_type_name, "None");
cls_StdSelect_BRepOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_BRepOwner::get_type_descriptor, "None");
cls_StdSelect_BRepOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_BRepOwner::*)() const) &StdSelect_BRepOwner::DynamicType, "None");
cls_StdSelect_BRepOwner.def("HasShape", (Standard_Boolean (StdSelect_BRepOwner::*)() const) &StdSelect_BRepOwner::HasShape, "returns False if no shape was set");
cls_StdSelect_BRepOwner.def("Shape", (const TopoDS_Shape & (StdSelect_BRepOwner::*)() const) &StdSelect_BRepOwner::Shape, "Returns the shape.");
cls_StdSelect_BRepOwner.def("HasHilightMode", (Standard_Boolean (StdSelect_BRepOwner::*)() const) &StdSelect_BRepOwner::HasHilightMode, "Returns true if this framework has a highlight mode defined for it.");
cls_StdSelect_BRepOwner.def("SetHilightMode", (void (StdSelect_BRepOwner::*)(const Standard_Integer)) &StdSelect_BRepOwner::SetHilightMode, "Sets the highlight mode for this framework. This defines the type of display used to highlight the owner of the shape when it is detected by the selector. The default type of display is wireframe, defined by the index 0.", py::arg("theMode"));
cls_StdSelect_BRepOwner.def("ResetHilightMode", (void (StdSelect_BRepOwner::*)()) &StdSelect_BRepOwner::ResetHilightMode, "Resets the higlight mode for this framework. This defines the type of display used to highlight the owner of the shape when it is detected by the selector. The default type of display is wireframe, defined by the index 0.");
cls_StdSelect_BRepOwner.def("HilightMode", (Standard_Integer (StdSelect_BRepOwner::*)() const) &StdSelect_BRepOwner::HilightMode, "Returns the highlight mode for this framework. This defines the type of display used to highlight the owner of the shape when it is detected by the selector. The default type of display is wireframe, defined by the index 0.");
cls_StdSelect_BRepOwner.def("IsHilighted", [](StdSelect_BRepOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> Standard_Boolean { return self.IsHilighted(a0); });
cls_StdSelect_BRepOwner.def("IsHilighted", (Standard_Boolean (StdSelect_BRepOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const) &StdSelect_BRepOwner::IsHilighted, "Returns true if an object with the selection mode aMode is highlighted in the presentation manager aPM.", py::arg("aPM"), py::arg("aMode"));
cls_StdSelect_BRepOwner.def("HilightWithColor", [](StdSelect_BRepOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); });
cls_StdSelect_BRepOwner.def("HilightWithColor", (void (StdSelect_BRepOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &StdSelect_BRepOwner::HilightWithColor, "None", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
cls_StdSelect_BRepOwner.def("Unhilight", [](StdSelect_BRepOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); });
cls_StdSelect_BRepOwner.def("Unhilight", (void (StdSelect_BRepOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &StdSelect_BRepOwner::Unhilight, "Removes highlighting from the type of shape identified the selection mode aMode in the presentation manager aPM.", py::arg("aPM"), py::arg("aMode"));
cls_StdSelect_BRepOwner.def("Clear", [](StdSelect_BRepOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Clear(a0); });
cls_StdSelect_BRepOwner.def("Clear", (void (StdSelect_BRepOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &StdSelect_BRepOwner::Clear, "Clears the presentation manager object aPM of all shapes with the selection mode aMode.", py::arg("aPM"), py::arg("aMode"));
cls_StdSelect_BRepOwner.def("SetLocation", (void (StdSelect_BRepOwner::*)(const TopLoc_Location &)) &StdSelect_BRepOwner::SetLocation, "None", py::arg("aLoc"));
cls_StdSelect_BRepOwner.def("UpdateHighlightTrsf", (void (StdSelect_BRepOwner::*)(const opencascade::handle<V3d_Viewer> &, const opencascade::handle<PrsMgr_PresentationManager3d> &, const Standard_Integer)) &StdSelect_BRepOwner::UpdateHighlightTrsf, "Implements immediate application of location transformation of parent object to dynamic highlight structure", py::arg("theViewer"), py::arg("theManager"), py::arg("theDispMode"));

// CLASS: STDSELECT_BREPSELECTIONTOOL
py::class_<StdSelect_BRepSelectionTool> cls_StdSelect_BRepSelectionTool(mod, "StdSelect_BRepSelectionTool", "Tool to create specific selections (sets of primitives) for Shapes from Topology. These Selections may be used in dynamic selection Mechanism Given a Shape and a mode of selection (selection of vertices, edges,faces ...) , This Tool Computes corresponding sensitive primitives, puts them in an entity called Selection (see package SelectMgr) and returns it.");

// Methods
// cls_StdSelect_BRepSelectionTool.def_static("operator new_", (void * (*)(size_t)) &StdSelect_BRepSelectionTool::operator new, "None", py::arg("theSize"));
// cls_StdSelect_BRepSelectionTool.def_static("operator delete_", (void (*)(void *)) &StdSelect_BRepSelectionTool::operator delete, "None", py::arg("theAddress"));
// cls_StdSelect_BRepSelectionTool.def_static("operator new[]_", (void * (*)(size_t)) &StdSelect_BRepSelectionTool::operator new[], "None", py::arg("theSize"));
// cls_StdSelect_BRepSelectionTool.def_static("operator delete[]_", (void (*)(void *)) &StdSelect_BRepSelectionTool::operator delete[], "None", py::arg("theAddress"));
// cls_StdSelect_BRepSelectionTool.def_static("operator new_", (void * (*)(size_t, void *)) &StdSelect_BRepSelectionTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdSelect_BRepSelectionTool.def_static("operator delete_", (void (*)(void *, void *)) &StdSelect_BRepSelectionTool::operator delete, "None", py::arg(""), py::arg(""));
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const TopoDS_Shape & a1, const TopAbs_ShapeEnum a2, const Standard_Real a3, const Standard_Real a4) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const TopoDS_Shape & a1, const TopAbs_ShapeEnum a2, const Standard_Real a3, const Standard_Real a4, const Standard_Boolean a5) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const TopoDS_Shape & a1, const TopAbs_ShapeEnum a2, const Standard_Real a3, const Standard_Real a4, const Standard_Boolean a5, const Standard_Integer a6) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5, a6); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const TopoDS_Shape & a1, const TopAbs_ShapeEnum a2, const Standard_Real a3, const Standard_Real a4, const Standard_Boolean a5, const Standard_Integer a6, const Standard_Integer a7) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", (void (*)(const opencascade::handle<SelectMgr_Selection> &, const TopoDS_Shape &, const TopAbs_ShapeEnum, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Real)) &StdSelect_BRepSelectionTool::Load, "Decomposition of <aShape> into sensitive entities following a mode of decomposition <aType>. These entities are stored in <aSelection>. BrepOwners are created to store the identity of the picked shapes during the selection process. In those BRepOwners is also stored the original shape. But One can't get the selectable object which was decomposed to give the sensitive entities. maximal parameter is used for infinite objects, to limit the sensitive Domain.... If AutoTriangulation = True, a Triangulation will be computed for faces which have no existing one. if AutoTriangulation = False the old algorithm will be called to compute sensitive entities on faces.", py::arg("aSelection"), py::arg("aShape"), py::arg("aType"), py::arg("theDeflection"), py::arg("theDeviationAngle"), py::arg("AutoTriangulation"), py::arg("aPriority"), py::arg("NbPOnEdge"), py::arg("MaximalParameter"));
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const opencascade::handle<SelectMgr_SelectableObject> & a1, const TopoDS_Shape & a2, const TopAbs_ShapeEnum a3, const Standard_Real a4, const Standard_Real a5) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const opencascade::handle<SelectMgr_SelectableObject> & a1, const TopoDS_Shape & a2, const TopAbs_ShapeEnum a3, const Standard_Real a4, const Standard_Real a5, const Standard_Boolean a6) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5, a6); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const opencascade::handle<SelectMgr_SelectableObject> & a1, const TopoDS_Shape & a2, const TopAbs_ShapeEnum a3, const Standard_Real a4, const Standard_Real a5, const Standard_Boolean a6, const Standard_Integer a7) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", [](const opencascade::handle<SelectMgr_Selection> & a0, const opencascade::handle<SelectMgr_SelectableObject> & a1, const TopoDS_Shape & a2, const TopAbs_ShapeEnum a3, const Standard_Real a4, const Standard_Real a5, const Standard_Boolean a6, const Standard_Integer a7, const Standard_Integer a8) -> void { return StdSelect_BRepSelectionTool::Load(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_StdSelect_BRepSelectionTool.def_static("Load_", (void (*)(const opencascade::handle<SelectMgr_Selection> &, const opencascade::handle<SelectMgr_SelectableObject> &, const TopoDS_Shape &, const TopAbs_ShapeEnum, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Real)) &StdSelect_BRepSelectionTool::Load, "Same functionnalities ; the only difference is that the selectable object from which the selection comes is stored in each Sensitive EntityOwner; decomposition of <aShape> into sensitive entities following a mode of decomposition <aType>. These entities are stored in <aSelection> The Major difference is that the known users are first inserted in the BRepOwners. the original shape is the last user... (see EntityOwner from SelectBasics and BrepOwner)...", py::arg("aSelection"), py::arg("Origin"), py::arg("aShape"), py::arg("aType"), py::arg("theDeflection"), py::arg("theDeviationAngle"), py::arg("AutoTriangulation"), py::arg("aPriority"), py::arg("NbPOnEdge"), py::arg("MaximalParameter"));
cls_StdSelect_BRepSelectionTool.def_static("GetStandardPriority_", (Standard_Integer (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &StdSelect_BRepSelectionTool::GetStandardPriority, "Returns the standard priority of the shape aShap having the type aType. This priority is passed to a StdSelect_BRepOwner object. You can use the function Load to modify the selection priority of an owner to make one entity more selectable than another one.", py::arg("theShape"), py::arg("theType"));
cls_StdSelect_BRepSelectionTool.def_static("ComputeSensitive_", [](const TopoDS_Shape & a0, const opencascade::handle<SelectMgr_EntityOwner> & a1, const opencascade::handle<SelectMgr_Selection> & a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5, const Standard_Real a6) -> void { return StdSelect_BRepSelectionTool::ComputeSensitive(a0, a1, a2, a3, a4, a5, a6); });
cls_StdSelect_BRepSelectionTool.def_static("ComputeSensitive_", (void (*)(const TopoDS_Shape &, const opencascade::handle<SelectMgr_EntityOwner> &, const opencascade::handle<SelectMgr_Selection> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Boolean)) &StdSelect_BRepSelectionTool::ComputeSensitive, "Computes the sensitive primitives, stores them in the SelectMgr_Selection object, and returns this object.", py::arg("theShape"), py::arg("theOwner"), py::arg("theSelection"), py::arg("theDeflection"), py::arg("theDeflAngle"), py::arg("theNbPOnEdge"), py::arg("theMaxiParam"), py::arg("theAutoTriang"));
cls_StdSelect_BRepSelectionTool.def_static("GetSensitiveForFace_", [](const TopoDS_Face & a0, const opencascade::handle<SelectMgr_EntityOwner> & a1, Select3D_EntitySequence & a2) -> Standard_Boolean { return StdSelect_BRepSelectionTool::GetSensitiveForFace(a0, a1, a2); });
cls_StdSelect_BRepSelectionTool.def_static("GetSensitiveForFace_", [](const TopoDS_Face & a0, const opencascade::handle<SelectMgr_EntityOwner> & a1, Select3D_EntitySequence & a2, const Standard_Boolean a3) -> Standard_Boolean { return StdSelect_BRepSelectionTool::GetSensitiveForFace(a0, a1, a2, a3); });
cls_StdSelect_BRepSelectionTool.def_static("GetSensitiveForFace_", [](const TopoDS_Face & a0, const opencascade::handle<SelectMgr_EntityOwner> & a1, Select3D_EntitySequence & a2, const Standard_Boolean a3, const Standard_Integer a4) -> Standard_Boolean { return StdSelect_BRepSelectionTool::GetSensitiveForFace(a0, a1, a2, a3, a4); });
cls_StdSelect_BRepSelectionTool.def_static("GetSensitiveForFace_", [](const TopoDS_Face & a0, const opencascade::handle<SelectMgr_EntityOwner> & a1, Select3D_EntitySequence & a2, const Standard_Boolean a3, const Standard_Integer a4, const Standard_Real a5) -> Standard_Boolean { return StdSelect_BRepSelectionTool::GetSensitiveForFace(a0, a1, a2, a3, a4, a5); });
cls_StdSelect_BRepSelectionTool.def_static("GetSensitiveForFace_", (Standard_Boolean (*)(const TopoDS_Face &, const opencascade::handle<SelectMgr_EntityOwner> &, Select3D_EntitySequence &, const Standard_Boolean, const Standard_Integer, const Standard_Real, const Standard_Boolean)) &StdSelect_BRepSelectionTool::GetSensitiveForFace, "Creates the 3D sensitive entities for Face selection.", py::arg("theFace"), py::arg("theOwner"), py::arg("theOutList"), py::arg("theAutoTriang"), py::arg("theNbPOnEdge"), py::arg("theMaxiParam"), py::arg("theInteriorFlag"));
cls_StdSelect_BRepSelectionTool.def_static("GetEdgeSensitive_", (void (*)(const TopoDS_Shape &, const opencascade::handle<SelectMgr_EntityOwner> &, const opencascade::handle<SelectMgr_Selection> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, opencascade::handle<Select3D_SensitiveEntity> &)) &StdSelect_BRepSelectionTool::GetEdgeSensitive, "Create a sensitive edge or sensitive wire.", py::arg("theShape"), py::arg("theOwner"), py::arg("theSelection"), py::arg("theDeflection"), py::arg("theDeviationAngle"), py::arg("theNbPOnEdge"), py::arg("theMaxiParam"), py::arg("theSensitive"));
cls_StdSelect_BRepSelectionTool.def_static("PreBuildBVH_", (void (*)(const opencascade::handle<SelectMgr_Selection> &)) &StdSelect_BRepSelectionTool::PreBuildBVH, "Traverses the selection given and pre-builds BVH trees for heavyweight sensitive entities containing more than BVH_PRIMITIVE_LIMIT (defined in .cxx file) sub-elements.", py::arg("theSelection"));

// CLASS: STDSELECT_EDGEFILTER
py::class_<StdSelect_EdgeFilter, opencascade::handle<StdSelect_EdgeFilter>, SelectMgr_Filter> cls_StdSelect_EdgeFilter(mod, "StdSelect_EdgeFilter", "A framework to define a filter to select a specific type of edge. The types available include: - any edge - a linear edge - a circular edge.");

// Constructors
cls_StdSelect_EdgeFilter.def(py::init<const StdSelect_TypeOfEdge>(), py::arg("Edge"));

// Methods
cls_StdSelect_EdgeFilter.def("SetType", (void (StdSelect_EdgeFilter::*)(const StdSelect_TypeOfEdge)) &StdSelect_EdgeFilter::SetType, "Sets the type of edge aNewType. aNewType is to be highlighted in selection.", py::arg("aNewType"));
cls_StdSelect_EdgeFilter.def("Type", (StdSelect_TypeOfEdge (StdSelect_EdgeFilter::*)() const) &StdSelect_EdgeFilter::Type, "Returns the type of edge to be highlighted in selection.");
cls_StdSelect_EdgeFilter.def("IsOk", (Standard_Boolean (StdSelect_EdgeFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &StdSelect_EdgeFilter::IsOk, "None", py::arg("anobj"));
cls_StdSelect_EdgeFilter.def("ActsOn", (Standard_Boolean (StdSelect_EdgeFilter::*)(const TopAbs_ShapeEnum) const) &StdSelect_EdgeFilter::ActsOn, "None", py::arg("aStandardMode"));
cls_StdSelect_EdgeFilter.def_static("get_type_name_", (const char * (*)()) &StdSelect_EdgeFilter::get_type_name, "None");
cls_StdSelect_EdgeFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_EdgeFilter::get_type_descriptor, "None");
cls_StdSelect_EdgeFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_EdgeFilter::*)() const) &StdSelect_EdgeFilter::DynamicType, "None");

// CLASS: STDSELECT_FACEFILTER
py::class_<StdSelect_FaceFilter, opencascade::handle<StdSelect_FaceFilter>, SelectMgr_Filter> cls_StdSelect_FaceFilter(mod, "StdSelect_FaceFilter", "A framework to define a filter to select a specific type of face. The types available include: - any face - a planar face - a cylindrical face - a spherical face - a toroidal face - a revol face.");

// Constructors
cls_StdSelect_FaceFilter.def(py::init<const StdSelect_TypeOfFace>(), py::arg("aTypeOfFace"));

// Methods
cls_StdSelect_FaceFilter.def("SetType", (void (StdSelect_FaceFilter::*)(const StdSelect_TypeOfFace)) &StdSelect_FaceFilter::SetType, "Sets the type of face aNewType. aNewType is to be highlighted in selection.", py::arg("aNewType"));
cls_StdSelect_FaceFilter.def("Type", (StdSelect_TypeOfFace (StdSelect_FaceFilter::*)() const) &StdSelect_FaceFilter::Type, "Returns the type of face to be highlighted in selection.");
cls_StdSelect_FaceFilter.def("IsOk", (Standard_Boolean (StdSelect_FaceFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &StdSelect_FaceFilter::IsOk, "None", py::arg("anobj"));
cls_StdSelect_FaceFilter.def("ActsOn", (Standard_Boolean (StdSelect_FaceFilter::*)(const TopAbs_ShapeEnum) const) &StdSelect_FaceFilter::ActsOn, "None", py::arg("aStandardMode"));
cls_StdSelect_FaceFilter.def_static("get_type_name_", (const char * (*)()) &StdSelect_FaceFilter::get_type_name, "None");
cls_StdSelect_FaceFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_FaceFilter::get_type_descriptor, "None");
cls_StdSelect_FaceFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_FaceFilter::*)() const) &StdSelect_FaceFilter::DynamicType, "None");

// CLASS: STDSELECT_PRS
py::class_<StdSelect_Prs, opencascade::handle<StdSelect_Prs>, Prs3d_Presentation> cls_StdSelect_Prs(mod, "StdSelect_Prs", "allows entities owners to be hilighted independantly from PresentableObjects");

// Constructors
cls_StdSelect_Prs.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("aStructureManager"));

// Methods
cls_StdSelect_Prs.def("Manager", (const opencascade::handle<Graphic3d_StructureManager> & (StdSelect_Prs::*)() const) &StdSelect_Prs::Manager, "None");
cls_StdSelect_Prs.def_static("get_type_name_", (const char * (*)()) &StdSelect_Prs::get_type_name, "None");
cls_StdSelect_Prs.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_Prs::get_type_descriptor, "None");
cls_StdSelect_Prs.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_Prs::*)() const) &StdSelect_Prs::DynamicType, "None");

// TYPEDEF: STDSELECT_INDEXEDDATAMAPOFOWNERPRS
bind_NCollection_IndexedDataMap<opencascade::handle<SelectMgr_EntityOwner>, opencascade::handle<StdSelect_Prs>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "StdSelect_IndexedDataMapOfOwnerPrs", py::module_local(false));

// CLASS: STDSELECT_SHAPE
py::class_<StdSelect_Shape, opencascade::handle<StdSelect_Shape>, PrsMgr_PresentableObject> cls_StdSelect_Shape(mod, "StdSelect_Shape", "Presentable shape only for purpose of display for BRepOwner...");

// Constructors
cls_StdSelect_Shape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_StdSelect_Shape.def(py::init<const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &>(), py::arg("theShape"), py::arg("theDrawer"));

// Methods
cls_StdSelect_Shape.def_static("get_type_name_", (const char * (*)()) &StdSelect_Shape::get_type_name, "None");
cls_StdSelect_Shape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_Shape::get_type_descriptor, "None");
cls_StdSelect_Shape.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_Shape::*)() const) &StdSelect_Shape::DynamicType, "None");
cls_StdSelect_Shape.def("Compute", [](StdSelect_Shape &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Presentation> & a1) -> void { return self.Compute(a0, a1); });
cls_StdSelect_Shape.def("Compute", (void (StdSelect_Shape::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Presentation> &, const Standard_Integer)) &StdSelect_Shape::Compute, "None", py::arg("aPresentationManager"), py::arg("aPresentation"), py::arg("aMode"));
cls_StdSelect_Shape.def("Compute", (void (StdSelect_Shape::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &StdSelect_Shape::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_StdSelect_Shape.def("Shape", (const TopoDS_Shape & (StdSelect_Shape::*)() const) &StdSelect_Shape::Shape, "None");
cls_StdSelect_Shape.def("Shape", (void (StdSelect_Shape::*)(const TopoDS_Shape &)) &StdSelect_Shape::Shape, "None", py::arg("theShape"));

// CLASS: STDSELECT_SHAPETYPEFILTER
py::class_<StdSelect_ShapeTypeFilter, opencascade::handle<StdSelect_ShapeTypeFilter>, SelectMgr_Filter> cls_StdSelect_ShapeTypeFilter(mod, "StdSelect_ShapeTypeFilter", "A filter framework which allows you to define a filter for a specific shape type. The types available include: - compound - compsolid - solid - shell - face - wire - edge - vertex.");

// Constructors
cls_StdSelect_ShapeTypeFilter.def(py::init<const TopAbs_ShapeEnum>(), py::arg("aType"));

// Methods
cls_StdSelect_ShapeTypeFilter.def("IsOk", (Standard_Boolean (StdSelect_ShapeTypeFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &StdSelect_ShapeTypeFilter::IsOk, "None", py::arg("anobj"));
cls_StdSelect_ShapeTypeFilter.def("Type", (TopAbs_ShapeEnum (StdSelect_ShapeTypeFilter::*)() const) &StdSelect_ShapeTypeFilter::Type, "Returns the type of shape selected by the filter.");
cls_StdSelect_ShapeTypeFilter.def("ActsOn", (Standard_Boolean (StdSelect_ShapeTypeFilter::*)(const TopAbs_ShapeEnum) const) &StdSelect_ShapeTypeFilter::ActsOn, "None", py::arg("aStandardMode"));
cls_StdSelect_ShapeTypeFilter.def_static("get_type_name_", (const char * (*)()) &StdSelect_ShapeTypeFilter::get_type_name, "None");
cls_StdSelect_ShapeTypeFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_ShapeTypeFilter::get_type_descriptor, "None");
cls_StdSelect_ShapeTypeFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_ShapeTypeFilter::*)() const) &StdSelect_ShapeTypeFilter::DynamicType, "None");


}
