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
#include <AIS_InteractiveObject.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_ArrayOfPoints.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <Quantity_HArray1OfColor.hxx>
#include <TColgp_HArray1OfDir.hxx>
#include <Bnd_Box.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_Selection.hxx>
#include <AIS_PointCloud.hxx>
#include <Standard_Type.hxx>

void bind_AIS_PointCloud(py::module &mod){

py::class_<AIS_PointCloud, opencascade::handle<AIS_PointCloud>, AIS_InteractiveObject> cls_AIS_PointCloud(mod, "AIS_PointCloud", "Interactive object for set of points. The presentation supports two display modes: - Points. - Bounding box for highlighting. Presentation provides selection by bouding box. Selection and consequently highlighting can disabled by setting default selection mode to -1. There will be no way to select object from interactive view. Any calls to AIS_InteractiveContext::AddOrRemoveSelected should be also prohibited, to avoid programmatic highlighting (workaround is setting non-supported hilight mode, e.g. 100);");

// Constructors
cls_AIS_PointCloud.def(py::init<>());

// Fields

// Methods
cls_AIS_PointCloud.def("SetPoints", (void (AIS_PointCloud::*)(const opencascade::handle<Graphic3d_ArrayOfPoints> &)) &AIS_PointCloud::SetPoints, "Sets the points from array of points. Method will not copy the input data - array will be stored as handle.", py::arg("thePoints"));
cls_AIS_PointCloud.def("SetPoints", [](AIS_PointCloud &self, const opencascade::handle<TColgp_HArray1OfPnt> & a0) -> void { return self.SetPoints(a0); });
cls_AIS_PointCloud.def("SetPoints", [](AIS_PointCloud &self, const opencascade::handle<TColgp_HArray1OfPnt> & a0, const opencascade::handle<Quantity_HArray1OfColor> & a1) -> void { return self.SetPoints(a0, a1); });
cls_AIS_PointCloud.def("SetPoints", (void (AIS_PointCloud::*)(const opencascade::handle<TColgp_HArray1OfPnt> &, const opencascade::handle<Quantity_HArray1OfColor> &, const opencascade::handle<TColgp_HArray1OfDir> &)) &AIS_PointCloud::SetPoints, "Sets the points with optional colors. The input data will be copied into internal buffer. The input arrays should have equal length, otherwise the presentation will not be computed and displayed.", py::arg("theCoords"), py::arg("theColors"), py::arg("theNormals"));
cls_AIS_PointCloud.def("GetPoints", (const opencascade::handle<Graphic3d_ArrayOfPoints> (AIS_PointCloud::*)() const) &AIS_PointCloud::GetPoints, "Get the points array. Method might be overridden to fill in points array dynamically from application data structures.");
cls_AIS_PointCloud.def("GetBoundingBox", (Bnd_Box (AIS_PointCloud::*)() const) &AIS_PointCloud::GetBoundingBox, "Get bounding box for presentation.");
cls_AIS_PointCloud.def("SetColor", (void (AIS_PointCloud::*)(const Quantity_Color &)) &AIS_PointCloud::SetColor, "Setup custom color. Affects presentation only when no per-point color attribute has been assigned.", py::arg("theColor"));
cls_AIS_PointCloud.def("UnsetColor", (void (AIS_PointCloud::*)()) &AIS_PointCloud::UnsetColor, "Restore default color.");
cls_AIS_PointCloud.def("SetMaterial", (void (AIS_PointCloud::*)(const Graphic3d_MaterialAspect &)) &AIS_PointCloud::SetMaterial, "Setup custom material. Affects presentation only when normals are defined.", py::arg("theMat"));
cls_AIS_PointCloud.def("UnsetMaterial", (void (AIS_PointCloud::*)()) &AIS_PointCloud::UnsetMaterial, "Restore default material.");
cls_AIS_PointCloud.def_static("get_type_name_", (const char * (*)()) &AIS_PointCloud::get_type_name, "None");
cls_AIS_PointCloud.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_PointCloud::get_type_descriptor, "None");
cls_AIS_PointCloud.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_PointCloud::*)() const) &AIS_PointCloud::DynamicType, "None");

// Enums
py::enum_<AIS_PointCloud::DisplayMode>(cls_AIS_PointCloud, "enumDisplayMode", "Display modes supported by this Point Cloud object")
	.value("DM_Points", AIS_PointCloud::DisplayMode::DM_Points)
	.value("DM_BndBox", AIS_PointCloud::DisplayMode::DM_BndBox)
	.export_values();
py::enum_<AIS_PointCloud::SelectionMode>(cls_AIS_PointCloud, "SelectionMode", "Selection modes supported by this Point Cloud object")
	.value("SM_Points", AIS_PointCloud::SelectionMode::SM_Points)
	.value("SM_BndBox", AIS_PointCloud::SelectionMode::SM_BndBox)
	.export_values();

}