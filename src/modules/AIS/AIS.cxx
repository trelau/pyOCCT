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

void bind_AIS_KindOfSurface(py::module &);
void bind_AIS_DimensionSelectionMode(py::module &);
void bind_AIS_DisplaySpecialSymbol(py::module &);
void bind_AIS_KindOfInteractive(py::module &);
void bind_AIS_KindOfDimension(py::module &);
void bind_AIS_TypeOfAngle(py::module &);
void bind_AIS_TypeOfAngleArrowVisibility(py::module &);
void bind_AIS_SelectionModesConcurrency(py::module &);
void bind_AIS_ClearMode(py::module &);
void bind_AIS_StatusOfDetection(py::module &);
void bind_AIS_StatusOfPick(py::module &);
void bind_AIS_SelectStatus(py::module &);
void bind_AIS_DisplayStatus(py::module &);
void bind_AIS_DisplayMode(py::module &);
void bind_AIS_TypeOfIso(py::module &);
void bind_AIS_TypeOfAxis(py::module &);
void bind_AIS_ConnectStatus(py::module &);
void bind_AIS_TypeOfDist(py::module &);
void bind_AIS_TypeOfAttribute(py::module &);
void bind_AIS_KindOfRelation(py::module &);
void bind_AIS_KindOfUnit(py::module &);
void bind_AIS_ManipulatorMode(py::module &);
void bind_AIS_TypeOfPlane(py::module &);
void bind_AIS_StandardDatum(py::module &);
void bind_AIS_TrihedronSelectionMode(py::module &);
void bind_AIS(py::module &);
void bind_AIS_DimensionOwner(py::module &);
void bind_AIS_InteractiveObject(py::module &);
void bind_AIS_Dimension(py::module &);
void bind_AIS_AngleDimension(py::module &);
void bind_AIS_AnimationTimer(py::module &);
void bind_AIS_AnimationProgress(py::module &);
void bind_AIS_Animation(py::module &);
void bind_AIS_AnimationCamera(py::module &);
void bind_AIS_LocalStatus(py::module &);
void bind_AIS_DataMapOfSelStat(py::module &);
void bind_AIS_DataMapIteratorOfDataMapOfSelStat(py::module &);
void bind_AIS_SequenceOfInteractive(py::module &);
void bind_AIS_NListOfEntityOwner(py::module &);
void bind_AIS_Selection(py::module &);
void bind_AIS_LocalContext(py::module &);
void bind_AIS_DataMapOfILC(py::module &);
void bind_AIS_DataMapIteratorOfDataMapOfILC(py::module &);
void bind_AIS_GlobalStatus(py::module &);
void bind_AIS_DataMapOfIOStatus(py::module &);
void bind_AIS_DataMapIteratorOfDataMapOfIOStatus(py::module &);
void bind_AIS_ListOfInteractive(py::module &);
void bind_AIS_ListIteratorOfListOfInteractive(py::module &);
void bind_AIS_InteractiveContext(py::module &);
void bind_AIS_AnimationObject(py::module &);
void bind_AIS_AttributeFilter(py::module &);
void bind_AIS_Axis(py::module &);
void bind_AIS_BadEdgeFilter(py::module &);
void bind_AIS_C0RegularityFilter(py::module &);
void bind_AIS_Relation(py::module &);
void bind_AIS_Chamf2dDimension(py::module &);
void bind_AIS_Chamf3dDimension(py::module &);
void bind_AIS_Circle(py::module &);
void bind_AIS_ColoredDrawer(py::module &);
void bind_AIS_DataMapOfShapeDrawer(py::module &);
void bind_AIS_Shape(py::module &);
void bind_AIS_ColoredShape(py::module &);
void bind_AIS_ColorScale(py::module &);
void bind_AIS_ConcentricRelation(py::module &);
void bind_AIS_ConnectedInteractive(py::module &);
void bind_AIS_DataMapofIntegerListOfinteractive(py::module &);
void bind_AIS_DataMapIteratorOfDataMapofIntegerListOfinteractive(py::module &);
void bind_AIS_DiameterDimension(py::module &);
void bind_AIS_EllipseRadiusDimension(py::module &);
void bind_AIS_EqualDistanceRelation(py::module &);
void bind_AIS_EqualRadiusRelation(py::module &);
void bind_AIS_ExclusionFilter(py::module &);
void bind_AIS_FixRelation(py::module &);
void bind_AIS_GraphicTool(py::module &);
void bind_AIS_IdenticRelation(py::module &);
void bind_AIS_IndexedDataMapOfOwnerPrs(py::module &);
void bind_AIS_LengthDimension(py::module &);
void bind_AIS_Line(py::module &);
void bind_AIS_ManipulatorObjectSequence(py::module &);
void bind_AIS_Manipulator(py::module &);
void bind_AIS_ManipulatorOwner(py::module &);
void bind_AIS_MapOfInteractive(py::module &);
void bind_AIS_MapIteratorOfMapOfInteractive(py::module &);
void bind_AIS_MaxRadiusDimension(py::module &);
void bind_AIS_MidPointRelation(py::module &);
void bind_AIS_MinRadiusDimension(py::module &);
void bind_AIS_MultipleConnectedInteractive(py::module &);
void bind_AIS_OffsetDimension(py::module &);
void bind_AIS_ParallelRelation(py::module &);
void bind_AIS_PerpendicularRelation(py::module &);
void bind_AIS_Plane(py::module &);
void bind_AIS_PlaneTrihedron(py::module &);
void bind_AIS_Point(py::module &);
void bind_AIS_PointCloud(py::module &);
void bind_AIS_RadiusDimension(py::module &);
void bind_AIS_RubberBand(py::module &);
void bind_AIS_SequenceOfDimension(py::module &);
void bind_AIS_TypeFilter(py::module &);
void bind_AIS_SignatureFilter(py::module &);
void bind_AIS_SymmetricRelation(py::module &);
void bind_AIS_TangentRelation(py::module &);
void bind_AIS_TextLabel(py::module &);
void bind_AIS_TexturedShape(py::module &);
void bind_AIS_Triangulation(py::module &);
void bind_AIS_Trihedron(py::module &);
void bind_AIS_TrihedronOwner(py::module &);

PYBIND11_MODULE(AIS, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.Aspect");
py::module::import("OCCT.SelectMgr");
py::module::import("OCCT.PrsMgr");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.OSD");
py::module::import("OCCT.V3d");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.StdSelect");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.DsgPrs");
py::module::import("OCCT.Poly");
py::module::import("OCCT.Select3D");
py::module::import("OCCT.Font");
py::module::import("OCCT.Image");
py::module::import("OCCT.SelectBasics");

bind_AIS_KindOfSurface(mod);
bind_AIS_DimensionSelectionMode(mod);
bind_AIS_DisplaySpecialSymbol(mod);
bind_AIS_KindOfInteractive(mod);
bind_AIS_KindOfDimension(mod);
bind_AIS_TypeOfAngle(mod);
bind_AIS_TypeOfAngleArrowVisibility(mod);
bind_AIS_SelectionModesConcurrency(mod);
bind_AIS_ClearMode(mod);
bind_AIS_StatusOfDetection(mod);
bind_AIS_StatusOfPick(mod);
bind_AIS_SelectStatus(mod);
bind_AIS_DisplayStatus(mod);
bind_AIS_DisplayMode(mod);
bind_AIS_TypeOfIso(mod);
bind_AIS_TypeOfAxis(mod);
bind_AIS_ConnectStatus(mod);
bind_AIS_TypeOfDist(mod);
bind_AIS_TypeOfAttribute(mod);
bind_AIS_KindOfRelation(mod);
bind_AIS_KindOfUnit(mod);
bind_AIS_ManipulatorMode(mod);
bind_AIS_TypeOfPlane(mod);
bind_AIS_StandardDatum(mod);
bind_AIS_TrihedronSelectionMode(mod);
bind_AIS(mod);
bind_AIS_DimensionOwner(mod);
bind_AIS_InteractiveObject(mod);
bind_AIS_Dimension(mod);
bind_AIS_AngleDimension(mod);
bind_AIS_AnimationTimer(mod);
bind_AIS_AnimationProgress(mod);
bind_AIS_Animation(mod);
bind_AIS_AnimationCamera(mod);
bind_AIS_LocalStatus(mod);
bind_AIS_DataMapOfSelStat(mod);
bind_AIS_DataMapIteratorOfDataMapOfSelStat(mod);
bind_AIS_SequenceOfInteractive(mod);
bind_AIS_NListOfEntityOwner(mod);
bind_AIS_Selection(mod);
bind_AIS_LocalContext(mod);
bind_AIS_DataMapOfILC(mod);
bind_AIS_DataMapIteratorOfDataMapOfILC(mod);
bind_AIS_GlobalStatus(mod);
bind_AIS_DataMapOfIOStatus(mod);
bind_AIS_DataMapIteratorOfDataMapOfIOStatus(mod);
bind_AIS_ListOfInteractive(mod);
bind_AIS_ListIteratorOfListOfInteractive(mod);
bind_AIS_InteractiveContext(mod);
bind_AIS_AnimationObject(mod);
bind_AIS_AttributeFilter(mod);
bind_AIS_Axis(mod);
bind_AIS_BadEdgeFilter(mod);
bind_AIS_C0RegularityFilter(mod);
bind_AIS_Relation(mod);
bind_AIS_Chamf2dDimension(mod);
bind_AIS_Chamf3dDimension(mod);
bind_AIS_Circle(mod);
bind_AIS_ColoredDrawer(mod);
bind_AIS_DataMapOfShapeDrawer(mod);
bind_AIS_Shape(mod);
bind_AIS_ColoredShape(mod);
bind_AIS_ColorScale(mod);
bind_AIS_ConcentricRelation(mod);
bind_AIS_ConnectedInteractive(mod);
bind_AIS_DataMapofIntegerListOfinteractive(mod);
bind_AIS_DataMapIteratorOfDataMapofIntegerListOfinteractive(mod);
bind_AIS_DiameterDimension(mod);
bind_AIS_EllipseRadiusDimension(mod);
bind_AIS_EqualDistanceRelation(mod);
bind_AIS_EqualRadiusRelation(mod);
bind_AIS_ExclusionFilter(mod);
bind_AIS_FixRelation(mod);
bind_AIS_GraphicTool(mod);
bind_AIS_IdenticRelation(mod);
bind_AIS_IndexedDataMapOfOwnerPrs(mod);
bind_AIS_LengthDimension(mod);
bind_AIS_Line(mod);
bind_AIS_ManipulatorObjectSequence(mod);
bind_AIS_Manipulator(mod);
bind_AIS_ManipulatorOwner(mod);
bind_AIS_MapOfInteractive(mod);
bind_AIS_MapIteratorOfMapOfInteractive(mod);
bind_AIS_MaxRadiusDimension(mod);
bind_AIS_MidPointRelation(mod);
bind_AIS_MinRadiusDimension(mod);
bind_AIS_MultipleConnectedInteractive(mod);
bind_AIS_OffsetDimension(mod);
bind_AIS_ParallelRelation(mod);
bind_AIS_PerpendicularRelation(mod);
bind_AIS_Plane(mod);
bind_AIS_PlaneTrihedron(mod);
bind_AIS_Point(mod);
bind_AIS_PointCloud(mod);
bind_AIS_RadiusDimension(mod);
bind_AIS_RubberBand(mod);
bind_AIS_SequenceOfDimension(mod);
bind_AIS_TypeFilter(mod);
bind_AIS_SignatureFilter(mod);
bind_AIS_SymmetricRelation(mod);
bind_AIS_TangentRelation(mod);
bind_AIS_TextLabel(mod);
bind_AIS_TexturedShape(mod);
bind_AIS_Triangulation(mod);
bind_AIS_Trihedron(mod);
bind_AIS_TrihedronOwner(mod);

}
