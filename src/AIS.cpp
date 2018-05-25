/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <AIS_KindOfSurface.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Standard_Handle.hxx>
#include <Poly_Triangulation.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <AIS_Triangulation.hxx>
#include <Standard_Transient.hxx>
#include <V3d_Viewer.hxx>
#include <AIS_DisplayStatus.hxx>
#include <TCollection_ExtendedString.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Prs3d_Drawer.hxx>
#include <Prs3d_TypeOfHighlight.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <V3d_View.hxx>
#include <TopLoc_Location.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_TransModeFlags.hxx>
#include <gp_Pnt.hxx>
#include <AIS_StatusOfDetection.hxx>
#include <TopoDS_Shape.hxx>
#include <Prs3d_BasicAspect.hxx>
#include <AIS_StatusOfPick.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <SelectMgr_IndexedMapOfOwner.hxx>
#include <SelectMgr_ListOfFilter.hxx>
#include <SelectMgr_Filter.hxx>
#include <SelectMgr_PickingStrategy.hxx>
#include <SelectMgr_SelectionManager.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <StdSelect_ViewerSelector3d.hxx>
#include <AIS_ListOfInteractive.hxx>
#include <Aspect_TypeOfFacingModel.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Prs3d_LineAspect.hxx>
#include <AIS_TypeOfIso.hxx>
#include <AIS_LocalContext.hxx>
#include <AIS_ClearMode.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <AIS_InteractiveContext.hxx>
#include <Quantity_NameOfColor.hxx>
#include <AIS_TypeOfAttribute.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <AIS_GraphicTool.hxx>
#include <AIS_Selection.hxx>
#include <SelectMgr_OrFilter.hxx>
#include <TColStd_MapOfTransient.hxx>
#include <TCollection_AsciiString.hxx>
#include <AIS_LocalStatus.hxx>
#include <AIS_GlobalStatus.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <Prs3d_Presentation.hxx>
#include <Bnd_Box.hxx>
#include <SelectMgr_Selection.hxx>
#include <Geom_Point.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <TopoDS_Vertex.hxx>
#include <AIS_Point.hxx>
#include <Geom_Line.hxx>
#include <Geom_Axis2Placement.hxx>
#include <AIS_TypeOfAxis.hxx>
#include <Geom_Axis1Placement.hxx>
#include <AIS_Axis.hxx>
#include <Prs3d_DatumMode.hxx>
#include <Prs3d_DatumParts.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>
#include <AIS_Trihedron.hxx>
#include <Geom_Plane.hxx>
#include <AIS_Line.hxx>
#include <AIS_PlaneTrihedron.hxx>
#include <Geom_Circle.hxx>
#include <AIS_Circle.hxx>
#include <AIS_TypeOfPlane.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <AIS_Plane.hxx>
#include <Prs3d_TypeOfHLR.hxx>
#include <gp_Pnt2d.hxx>
#include <AIS_Shape.hxx>
#include <PrsMgr_TypeOfPresentation3d.hxx>
#include <gp_Trsf.hxx>
#include <AIS_ConnectedInteractive.hxx>
#include <AIS_MultipleConnectedInteractive.hxx>
#include <AIS_DimensionSelectionMode.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <AIS_DimensionOwner.hxx>
#include <AIS_KindOfDimension.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <AIS_Relation.hxx>
#include <AIS_EllipseRadiusDimension.hxx>
#include <AIS_MaxRadiusDimension.hxx>
#include <AIS_MinRadiusDimension.hxx>
#include <AIS_Chamf2dDimension.hxx>
#include <AIS_Chamf3dDimension.hxx>
#include <AIS_OffsetDimension.hxx>
#include <TopoDS_Wire.hxx>
#include <AIS_FixRelation.hxx>
#include <AIS_PerpendicularRelation.hxx>
#include <AIS_ParallelRelation.hxx>
#include <AIS_TangentRelation.hxx>
#include <AIS_ConcentricRelation.hxx>
#include <TColStd_ListOfTransient.hxx>
#include <AIS_IdenticRelation.hxx>
#include <AIS_SymmetricRelation.hxx>
#include <AIS_MidPointRelation.hxx>
#include <TopoDS_Edge.hxx>
#include <AIS_EqualRadiusRelation.hxx>
#include <AIS_TypeOfDist.hxx>
#include <AIS_EqualDistanceRelation.hxx>
#include <AIS_TypeFilter.hxx>
#include <AIS_SignatureFilter.hxx>
#include <AIS_ExclusionFilter.hxx>
#include <AIS_AttributeFilter.hxx>
#include <AIS_C0RegularityFilter.hxx>
#include <AIS_BadEdgeFilter.hxx>
#include <AIS_SelectStatus.hxx>
#include <AIS_NListOfEntityOwner.hxx>
#include <gp_Lin.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pln.hxx>
#include <Geom_Surface.hxx>
#include <gp_Dir.hxx>
#include <gp_Elips.hxx>
#include <AIS.hxx>
#include <AIS_DisplaySpecialSymbol.hxx>
#include <Prs3d_DimensionAspect.hxx>
#include <AIS_Dimension.hxx>
#include <AIS_TypeOfAngle.hxx>
#include <AIS_TypeOfAngleArrowVisibility.hxx>
#include <AIS_AngleDimension.hxx>
#include <AIS_AnimationTimer.hxx>
#include <AIS_Animation.hxx>
#include <NCollection_Sequence.hxx>
#include <Graphic3d_Camera.hxx>
#include <AIS_AnimationCamera.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <AIS_DataMapOfSelStat.hxx>
#include <NCollection_BaseSequence.hxx>
#include <AIS_SequenceOfInteractive.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <AIS_DataMapOfILC.hxx>
#include <AIS_DataMapOfIOStatus.hxx>
#include <AIS_DisplayMode.hxx>
#include <AIS_AnimationObject.hxx>
#include <AIS_ColoredDrawer.hxx>
#include <AIS_DataMapOfShapeDrawer.hxx>
#include <AIS_ColoredShape.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Aspect_TypeOfColorScaleData.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Aspect_SequenceOfColor.hxx>
#include <Aspect_TypeOfColorScalePosition.hxx>
#include <AIS_ColorScale.hxx>
#include <AIS_ConnectStatus.hxx>
#include <AIS_DataMapofIntegerListOfinteractive.hxx>
#include <gp_Circ.hxx>
#include <AIS_DiameterDimension.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <AIS_IndexedDataMapOfOwnerPrs.hxx>
#include <AIS_KindOfRelation.hxx>
#include <AIS_KindOfUnit.hxx>
#include <AIS_LengthDimension.hxx>
#include <AIS_ManipulatorMode.hxx>
#include <AIS_Manipulator.hxx>
#include <gp_Ax2.hxx>
#include <AIS_ManipulatorOwner.hxx>
#include <NCollection_Map.hxx>
#include <AIS_MapOfInteractive.hxx>
#include <Graphic3d_ArrayOfPoints.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <Quantity_HArray1OfColor.hxx>
#include <TColgp_HArray1OfDir.hxx>
#include <AIS_PointCloud.hxx>
#include <AIS_RadiusDimension.hxx>
#include <Graphic3d_Vec2.hxx>
#include <AIS_RubberBand.hxx>
#include <AIS_SequenceOfDimension.hxx>
#include <AIS_StandardDatum.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <Font_FontAspect.hxx>
#include <Aspect_TypeOfDisplayText.hxx>
#include <AIS_TextLabel.hxx>
#include <Image_PixMap.hxx>
#include <AIS_TexturedShape.hxx>
#include <AIS_TrihedronSelectionMode.hxx>
#include <AIS_TrihedronOwner.hxx>
#include <NCollection_Templates.hpp>

void init_AIS_1(py::module &);


PYBIND11_MODULE(AIS, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Poly");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.V3d");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Prs3d");
	py::module::import("OCCT.SelectMgr");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.Graphic3d");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.PrsMgr");
	py::module::import("OCCT.StdSelect");
	py::module::import("OCCT.Aspect");
	py::module::import("OCCT.Quantity");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Select3D");
	py::module::import("OCCT.DsgPrs");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Font");
	py::module::import("OCCT.Image");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_KindOfSurface.hxx
	py::enum_<AIS_KindOfSurface>(mod, "AIS_KindOfSurface", "None")
		.value("AIS_KOS_Plane", AIS_KindOfSurface::AIS_KOS_Plane)
		.value("AIS_KOS_Cylinder", AIS_KindOfSurface::AIS_KOS_Cylinder)
		.value("AIS_KOS_Cone", AIS_KindOfSurface::AIS_KOS_Cone)
		.value("AIS_KOS_Sphere", AIS_KindOfSurface::AIS_KOS_Sphere)
		.value("AIS_KOS_Torus", AIS_KindOfSurface::AIS_KOS_Torus)
		.value("AIS_KOS_Revolution", AIS_KindOfSurface::AIS_KOS_Revolution)
		.value("AIS_KOS_Extrusion", AIS_KindOfSurface::AIS_KOS_Extrusion)
		.value("AIS_KOS_OtherSurface", AIS_KindOfSurface::AIS_KOS_OtherSurface)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_DimensionSelectionMode.hxx
	py::enum_<AIS_DimensionSelectionMode>(mod, "AIS_DimensionSelectionMode", "Specifies dimension selection modes.")
		.value("AIS_DSM_All", AIS_DimensionSelectionMode::AIS_DSM_All)
		.value("AIS_DSM_Line", AIS_DimensionSelectionMode::AIS_DSM_Line)
		.value("AIS_DSM_Text", AIS_DimensionSelectionMode::AIS_DSM_Text)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_DisplaySpecialSymbol.hxx
	py::enum_<AIS_DisplaySpecialSymbol>(mod, "AIS_DisplaySpecialSymbol", "Specifies dimension special symbol display options")
		.value("AIS_DSS_No", AIS_DisplaySpecialSymbol::AIS_DSS_No)
		.value("AIS_DSS_Before", AIS_DisplaySpecialSymbol::AIS_DSS_Before)
		.value("AIS_DSS_After", AIS_DisplaySpecialSymbol::AIS_DSS_After)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_KindOfInteractive.hxx
	py::enum_<AIS_KindOfInteractive>(mod, "AIS_KindOfInteractive", "Declares the type of Interactive Object. This is one of the following: - the Datum - the Object - the Relation - the Dimension - the None type. The Datum is the construction element. These include points, lines, axes and planes. The object brings together topological shapes. The Relation includes dimensions and constraints. The Dimension includes length, radius, diameter and angle dimensions. When the object is of an unknown type, the None type is declared.")
		.value("AIS_KOI_None", AIS_KindOfInteractive::AIS_KOI_None)
		.value("AIS_KOI_Datum", AIS_KindOfInteractive::AIS_KOI_Datum)
		.value("AIS_KOI_Shape", AIS_KindOfInteractive::AIS_KOI_Shape)
		.value("AIS_KOI_Object", AIS_KindOfInteractive::AIS_KOI_Object)
		.value("AIS_KOI_Relation", AIS_KindOfInteractive::AIS_KOI_Relation)
		.value("AIS_KOI_Dimension", AIS_KindOfInteractive::AIS_KOI_Dimension)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_KindOfDimension.hxx
	py::enum_<AIS_KindOfDimension>(mod, "AIS_KindOfDimension", "Declares the kinds of dimensions needed in the display of Interactive Objects.")
		.value("AIS_KOD_NONE", AIS_KindOfDimension::AIS_KOD_NONE)
		.value("AIS_KOD_LENGTH", AIS_KindOfDimension::AIS_KOD_LENGTH)
		.value("AIS_KOD_PLANEANGLE", AIS_KindOfDimension::AIS_KOD_PLANEANGLE)
		.value("AIS_KOD_SOLIDANGLE", AIS_KindOfDimension::AIS_KOD_SOLIDANGLE)
		.value("AIS_KOD_AREA", AIS_KindOfDimension::AIS_KOD_AREA)
		.value("AIS_KOD_VOLUME", AIS_KindOfDimension::AIS_KOD_VOLUME)
		.value("AIS_KOD_MASS", AIS_KindOfDimension::AIS_KOD_MASS)
		.value("AIS_KOD_TIME", AIS_KindOfDimension::AIS_KOD_TIME)
		.value("AIS_KOD_RADIUS", AIS_KindOfDimension::AIS_KOD_RADIUS)
		.value("AIS_KOD_DIAMETER", AIS_KindOfDimension::AIS_KOD_DIAMETER)
		.value("AIS_KOD_CHAMF2D", AIS_KindOfDimension::AIS_KOD_CHAMF2D)
		.value("AIS_KOD_CHAMF3D", AIS_KindOfDimension::AIS_KOD_CHAMF3D)
		.value("AIS_KOD_OFFSET", AIS_KindOfDimension::AIS_KOD_OFFSET)
		.value("AIS_KOD_ELLIPSERADIUS", AIS_KindOfDimension::AIS_KOD_ELLIPSERADIUS)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_TypeOfAngle.hxx
	py::enum_<AIS_TypeOfAngle>(mod, "AIS_TypeOfAngle", "Declares the type of angle.")
		.value("AIS_TOA_Interior", AIS_TypeOfAngle::AIS_TOA_Interior)
		.value("AIS_TOA_Exterior", AIS_TypeOfAngle::AIS_TOA_Exterior)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_TypeOfAngleArrowVisibility.hxx
	py::enum_<AIS_TypeOfAngleArrowVisibility>(mod, "AIS_TypeOfAngleArrowVisibility", "Declares what arrows are visible on angle presentation")
		.value("AIS_TOAV_Both", AIS_TypeOfAngleArrowVisibility::AIS_TOAV_Both)
		.value("AIS_TOAV_First", AIS_TypeOfAngleArrowVisibility::AIS_TOAV_First)
		.value("AIS_TOAV_Second", AIS_TypeOfAngleArrowVisibility::AIS_TOAV_Second)
		.value("AIS_TOAV_None", AIS_TypeOfAngleArrowVisibility::AIS_TOAV_None)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_ClearMode.hxx
	py::enum_<AIS_ClearMode>(mod, "AIS_ClearMode", "Declares which entities in an opened local context are to be cleared of mode settings. Temporary graphic presentations such as those for sub-shapes, for example, are only created for the selection process. By means of these enumerations, they can be cleared from local context.")
		.value("AIS_CM_All", AIS_ClearMode::AIS_CM_All)
		.value("AIS_CM_Interactive", AIS_ClearMode::AIS_CM_Interactive)
		.value("AIS_CM_Filters", AIS_ClearMode::AIS_CM_Filters)
		.value("AIS_CM_StandardModes", AIS_ClearMode::AIS_CM_StandardModes)
		.value("AIS_CM_TemporaryShapePrs", AIS_ClearMode::AIS_CM_TemporaryShapePrs)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_StatusOfDetection.hxx
	py::enum_<AIS_StatusOfDetection>(mod, "AIS_StatusOfDetection", "None")
		.value("AIS_SOD_Error", AIS_StatusOfDetection::AIS_SOD_Error)
		.value("AIS_SOD_Nothing", AIS_StatusOfDetection::AIS_SOD_Nothing)
		.value("AIS_SOD_AllBad", AIS_StatusOfDetection::AIS_SOD_AllBad)
		.value("AIS_SOD_Selected", AIS_StatusOfDetection::AIS_SOD_Selected)
		.value("AIS_SOD_OnlyOneDetected", AIS_StatusOfDetection::AIS_SOD_OnlyOneDetected)
		.value("AIS_SOD_OnlyOneGood", AIS_StatusOfDetection::AIS_SOD_OnlyOneGood)
		.value("AIS_SOD_SeveralGood", AIS_StatusOfDetection::AIS_SOD_SeveralGood)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_StatusOfPick.hxx
	py::enum_<AIS_StatusOfPick>(mod, "AIS_StatusOfPick", "None")
		.value("AIS_SOP_Error", AIS_StatusOfPick::AIS_SOP_Error)
		.value("AIS_SOP_NothingSelected", AIS_StatusOfPick::AIS_SOP_NothingSelected)
		.value("AIS_SOP_Removed", AIS_StatusOfPick::AIS_SOP_Removed)
		.value("AIS_SOP_OneSelected", AIS_StatusOfPick::AIS_SOP_OneSelected)
		.value("AIS_SOP_SeveralSelected", AIS_StatusOfPick::AIS_SOP_SeveralSelected)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_SelectStatus.hxx
	py::enum_<AIS_SelectStatus>(mod, "AIS_SelectStatus", "None")
		.value("AIS_SS_Added", AIS_SelectStatus::AIS_SS_Added)
		.value("AIS_SS_Removed", AIS_SelectStatus::AIS_SS_Removed)
		.value("AIS_SS_NotDone", AIS_SelectStatus::AIS_SS_NotDone)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_DisplayStatus.hxx
	py::enum_<AIS_DisplayStatus>(mod, "AIS_DisplayStatus", "To give the display status of an Interactive Object. This will be one of the following: - DS_Displayed: the Interactive Object is displayed in the main viewer; - DS_Erased: the Interactive Object is hidden in main viewer; - DS_Temporary: the Interactive Object is temporarily displayed; - DS_None: the Interactive Object is nowhere displayed.")
		.value("AIS_DS_Displayed", AIS_DisplayStatus::AIS_DS_Displayed)
		.value("AIS_DS_Erased", AIS_DisplayStatus::AIS_DS_Erased)
		.value("AIS_DS_Temporary", AIS_DisplayStatus::AIS_DS_Temporary)
		.value("AIS_DS_None", AIS_DisplayStatus::AIS_DS_None)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_DisplayMode.hxx
	py::enum_<AIS_DisplayMode>(mod, "AIS_DisplayMode", "Sets display modes other than neutral point ones, for interactive objects. The possibilities include: - wireframe, - shaded,")
		.value("AIS_WireFrame", AIS_DisplayMode::AIS_WireFrame)
		.value("AIS_Shaded", AIS_DisplayMode::AIS_Shaded)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_TypeOfIso.hxx
	py::enum_<AIS_TypeOfIso>(mod, "AIS_TypeOfIso", "Declares the type of isoparameter displayed.")
		.value("AIS_TOI_IsoU", AIS_TypeOfIso::AIS_TOI_IsoU)
		.value("AIS_TOI_IsoV", AIS_TypeOfIso::AIS_TOI_IsoV)
		.value("AIS_TOI_Both", AIS_TypeOfIso::AIS_TOI_Both)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_TypeOfAxis.hxx
	py::enum_<AIS_TypeOfAxis>(mod, "AIS_TypeOfAxis", "Declares the type of axis.")
		.value("AIS_TOAX_Unknown", AIS_TypeOfAxis::AIS_TOAX_Unknown)
		.value("AIS_TOAX_XAxis", AIS_TypeOfAxis::AIS_TOAX_XAxis)
		.value("AIS_TOAX_YAxis", AIS_TypeOfAxis::AIS_TOAX_YAxis)
		.value("AIS_TOAX_ZAxis", AIS_TypeOfAxis::AIS_TOAX_ZAxis)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_ConnectStatus.hxx
	py::enum_<AIS_ConnectStatus>(mod, "AIS_ConnectStatus", "Gives the status of connection of an Interactive Object. This will be one of the following: - No connection - Connection - Transformation - Both connection and transformation This enumeration is used in AIS_ConnectedInteractive. Transform indicates that the Interactive Object reference geometry has changed location relative to the reference geometry.")
		.value("AIS_CS_None", AIS_ConnectStatus::AIS_CS_None)
		.value("AIS_CS_Connection", AIS_ConnectStatus::AIS_CS_Connection)
		.value("AIS_CS_Transform", AIS_ConnectStatus::AIS_CS_Transform)
		.value("AIS_CS_Both", AIS_ConnectStatus::AIS_CS_Both)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_TypeOfDist.hxx
	py::enum_<AIS_TypeOfDist>(mod, "AIS_TypeOfDist", "To declare the type of distance.")
		.value("AIS_TOD_Unknown", AIS_TypeOfDist::AIS_TOD_Unknown)
		.value("AIS_TOD_Horizontal", AIS_TypeOfDist::AIS_TOD_Horizontal)
		.value("AIS_TOD_Vertical", AIS_TypeOfDist::AIS_TOD_Vertical)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_TypeOfAttribute.hxx
	py::enum_<AIS_TypeOfAttribute>(mod, "AIS_TypeOfAttribute", "None")
		.value("AIS_TOA_Line", AIS_TypeOfAttribute::AIS_TOA_Line)
		.value("AIS_TOA_Dimension", AIS_TypeOfAttribute::AIS_TOA_Dimension)
		.value("AIS_TOA_Wire", AIS_TypeOfAttribute::AIS_TOA_Wire)
		.value("AIS_TOA_Plane", AIS_TypeOfAttribute::AIS_TOA_Plane)
		.value("AIS_TOA_Vector", AIS_TypeOfAttribute::AIS_TOA_Vector)
		.value("AIS_TOA_UIso", AIS_TypeOfAttribute::AIS_TOA_UIso)
		.value("AIS_TOA_VIso", AIS_TypeOfAttribute::AIS_TOA_VIso)
		.value("AIS_TOA_Free", AIS_TypeOfAttribute::AIS_TOA_Free)
		.value("AIS_TOA_UnFree", AIS_TypeOfAttribute::AIS_TOA_UnFree)
		.value("AIS_TOA_Section", AIS_TypeOfAttribute::AIS_TOA_Section)
		.value("AIS_TOA_Hidden", AIS_TypeOfAttribute::AIS_TOA_Hidden)
		.value("AIS_TOA_Seen", AIS_TypeOfAttribute::AIS_TOA_Seen)
		.value("AIS_TOA_FirstAxis", AIS_TypeOfAttribute::AIS_TOA_FirstAxis)
		.value("AIS_TOA_SecondAxis", AIS_TypeOfAttribute::AIS_TOA_SecondAxis)
		.value("AIS_TOA_ThirdAxis", AIS_TypeOfAttribute::AIS_TOA_ThirdAxis)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_KindOfRelation.hxx
	py::enum_<AIS_KindOfRelation>(mod, "AIS_KindOfRelation", "None")
		.value("AIS_KOR_NONE", AIS_KindOfRelation::AIS_KOR_NONE)
		.value("AIS_KOR_CONCENTRIC", AIS_KindOfRelation::AIS_KOR_CONCENTRIC)
		.value("AIS_KOR_EQUALDISTANCE", AIS_KindOfRelation::AIS_KOR_EQUALDISTANCE)
		.value("AIS_KOR_EQUALRADIUS", AIS_KindOfRelation::AIS_KOR_EQUALRADIUS)
		.value("AIS_KOR_FIX", AIS_KindOfRelation::AIS_KOR_FIX)
		.value("AIS_KOR_IDENTIC", AIS_KindOfRelation::AIS_KOR_IDENTIC)
		.value("AIS_KOR_OFFSET", AIS_KindOfRelation::AIS_KOR_OFFSET)
		.value("AIS_KOR_PARALLEL", AIS_KindOfRelation::AIS_KOR_PARALLEL)
		.value("AIS_KOR_PERPENDICULAR", AIS_KindOfRelation::AIS_KOR_PERPENDICULAR)
		.value("AIS_KOR_TANGENT", AIS_KindOfRelation::AIS_KOR_TANGENT)
		.value("AIS_KOR_SYMMETRIC", AIS_KindOfRelation::AIS_KOR_SYMMETRIC)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_KindOfUnit.hxx
	py::enum_<AIS_KindOfUnit>(mod, "AIS_KindOfUnit", "Declares the type of Interactive Object unit.")
		.value("AIS_TOU_LENGTH", AIS_KindOfUnit::AIS_TOU_LENGTH)
		.value("AIS_TOU_SURFACE", AIS_KindOfUnit::AIS_TOU_SURFACE)
		.value("AIS_TOU_VOLUME", AIS_KindOfUnit::AIS_TOU_VOLUME)
		.value("AIS_TOU_PLANE_ANGLE", AIS_KindOfUnit::AIS_TOU_PLANE_ANGLE)
		.value("AIS_TOU_SOLID_ANGLE", AIS_KindOfUnit::AIS_TOU_SOLID_ANGLE)
		.value("AIS_TOU_MASS", AIS_KindOfUnit::AIS_TOU_MASS)
		.value("AIS_TOU_FORCE", AIS_KindOfUnit::AIS_TOU_FORCE)
		.value("AIS_TOU_TIME", AIS_KindOfUnit::AIS_TOU_TIME)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_ManipulatorMode.hxx
	py::enum_<AIS_ManipulatorMode>(mod, "AIS_ManipulatorMode", "Mode to make definite kind of transformations with AIS_Manipulator object.")
		.value("AIS_MM_None", AIS_ManipulatorMode::AIS_MM_None)
		.value("AIS_MM_Translation", AIS_ManipulatorMode::AIS_MM_Translation)
		.value("AIS_MM_Rotation", AIS_ManipulatorMode::AIS_MM_Rotation)
		.value("AIS_MM_Scaling", AIS_ManipulatorMode::AIS_MM_Scaling)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_TypeOfPlane.hxx
	py::enum_<AIS_TypeOfPlane>(mod, "AIS_TypeOfPlane", "Declares the type of plane.")
		.value("AIS_TOPL_Unknown", AIS_TypeOfPlane::AIS_TOPL_Unknown)
		.value("AIS_TOPL_XYPlane", AIS_TypeOfPlane::AIS_TOPL_XYPlane)
		.value("AIS_TOPL_XZPlane", AIS_TypeOfPlane::AIS_TOPL_XZPlane)
		.value("AIS_TOPL_YZPlane", AIS_TypeOfPlane::AIS_TOPL_YZPlane)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_StandardDatum.hxx
	py::enum_<AIS_StandardDatum>(mod, "AIS_StandardDatum", "Declares the type of standard datum of an Interactive Object.")
		.value("AIS_SD_None", AIS_StandardDatum::AIS_SD_None)
		.value("AIS_SD_Point", AIS_StandardDatum::AIS_SD_Point)
		.value("AIS_SD_Axis", AIS_StandardDatum::AIS_SD_Axis)
		.value("AIS_SD_Trihedron", AIS_StandardDatum::AIS_SD_Trihedron)
		.value("AIS_SD_PlaneTrihedron", AIS_StandardDatum::AIS_SD_PlaneTrihedron)
		.value("AIS_SD_Line", AIS_StandardDatum::AIS_SD_Line)
		.value("AIS_SD_Circle", AIS_StandardDatum::AIS_SD_Circle)
		.value("AIS_SD_Plane", AIS_StandardDatum::AIS_SD_Plane)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_TrihedronSelectionMode.hxx
	py::enum_<AIS_TrihedronSelectionMode>(mod, "AIS_TrihedronSelectionMode", "Enumeration defining selection modes supported by AIS_Trihedron.")
		.value("AIS_TrihedronSelectionMode_EntireObject", AIS_TrihedronSelectionMode::AIS_TrihedronSelectionMode_EntireObject)
		.value("AIS_TrihedronSelectionMode_Origin", AIS_TrihedronSelectionMode::AIS_TrihedronSelectionMode_Origin)
		.value("AIS_TrihedronSelectionMode_Axes", AIS_TrihedronSelectionMode::AIS_TrihedronSelectionMode_Axes)
		.value("AIS_TrihedronSelectionMode_MainPlanes", AIS_TrihedronSelectionMode::AIS_TrihedronSelectionMode_MainPlanes)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_InteractiveObject.hxx
	py::class_<AIS_InteractiveObject, opencascade::handle<AIS_InteractiveObject>, SelectMgr_SelectableObject> cls_AIS_InteractiveObject(mod, "AIS_InteractiveObject", "Defines a class of objects with display and selection services. Entities which are visualized and selected are Interactive Objects. You can make use of classes of standard Interactive Objects for which all necessary methods have already been programmed, or you can implement your own classes of Interactive Objects. Specific attributes of entities such as arrow aspect for dimensions must be loaded in a Drawer. This Drawer is then applied to the Interactive Object in view. There are four types of Interactive Object in AIS: the construction element or Datum, the Relation, which includes both dimensions and constraints, the Object, and finally, when the object is of an unknown type, the None type. Inside these categories, a signature, or index, provides the possibility of additional characterization. By default, the Interactive Object has a None type and a signature of 0. If you want to give a particular type and signature to your interactive object, you must redefine the methods, Signature and Type. Warning In the case of attribute methods, methods for standard attributes are virtual. They must be redefined by the inheriting classes. Setcolor for a point and Setcolor for a plane, for example, do not affect the same attributes in the Drawer.");
	cls_AIS_InteractiveObject.def_static("get_type_name_", (const char * (*)()) &AIS_InteractiveObject::get_type_name, "None");
	cls_AIS_InteractiveObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_InteractiveObject::get_type_descriptor, "None");
	cls_AIS_InteractiveObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::DynamicType, "None");
	cls_AIS_InteractiveObject.def("Type", (AIS_KindOfInteractive (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::Type, "Returns the kind of Interactive Object: - None - Datum - Relation - Object By default, the interactive object has a None type. Because specific shapes entail different behavior according to their sub-shapes, you may need to create a Local Context. This will allow you to specify the additional characteristics which you need to handle these shapes.");
	cls_AIS_InteractiveObject.def("Signature", (Standard_Integer (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::Signature, "Specifies additional characteristics of Interactive Objects. A signature is, in fact, an index with integer values assigned different properties. This method is frequently used in conjuction with Type to give a particular type and signature to an Interactive Object. By default, the Interactive Object has a None type and a signature of 0. Among the datums, this signature is attributed to the shape The remaining datums have the following default signatures: - Point signature 1 - Axis signature 2 - Trihedron signature 3 - PlaneTrihedron signature 4 - Line signature 5 - Circle signature 6 - Plane signature 7.");
	cls_AIS_InteractiveObject.def("AcceptShapeDecomposition", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::AcceptShapeDecomposition, "Informs the graphic context that the interactive Object may be decomposed into sub-shapes for dynamic selection. The most used Interactive Object is AIS_Shape. Activation methods for standard selection modes are proposed in the Interactive Context. These include selection by vertex or by edges. For datums with the same behavior as AIS_Shape, such as vetices and edges, we must redefine the virtual method so that AcceptShapeDecomposition returns false. Rule for selection : Mode 0 : Selection of the interactive Object itself Mode 1 : Selection of vertices Mode 2 : Selection Of Edges Mode 3 : Selection Of Wires Mode 4 : Selection Of Faces ...");
	cls_AIS_InteractiveObject.def("SetCurrentFacingModel", [](AIS_InteractiveObject &self) -> void { return self.SetCurrentFacingModel(); });
	cls_AIS_InteractiveObject.def("SetCurrentFacingModel", (void (AIS_InteractiveObject::*)(const Aspect_TypeOfFacingModel)) &AIS_InteractiveObject::SetCurrentFacingModel, "change the current facing model apply on polygons for SetColor(), SetTransparency(), SetMaterial() methods default facing model is Aspect_TOFM_TWO_SIDE. This mean that attributes is applying both on the front and back face.", py::arg("aModel"));
	cls_AIS_InteractiveObject.def("CurrentFacingModel", (Aspect_TypeOfFacingModel (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::CurrentFacingModel, "Returns the current facing model which is in effect.");
	cls_AIS_InteractiveObject.def("SetColor", (void (AIS_InteractiveObject::*)(const Quantity_Color &)) &AIS_InteractiveObject::SetColor, "Only the interactive object knowns which Drawer attribute is affected by the color, if any (ex: for a wire,it's the wireaspect field of the drawer, but for a vertex, only the point aspect field is affected by the color). WARNING : Do not forget to set the corresponding fields here (hasOwnColor and myDrawer->SetColor())", py::arg("theColor"));
	cls_AIS_InteractiveObject.def("UnsetColor", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetColor, "Removes color settings. Only the Interactive Object knows which Drawer attribute is affected by the color setting. For a wire, for example, wire aspect is the attribute affected. For a vertex, however, only point aspect is affected by the color setting.");
	cls_AIS_InteractiveObject.def("SetWidth", (void (AIS_InteractiveObject::*)(const Standard_Real)) &AIS_InteractiveObject::SetWidth, "Allows you to provide the setting aValue for width. Only the Interactive Object knows which Drawer attribute is affected by the width setting.", py::arg("aValue"));
	cls_AIS_InteractiveObject.def("UnsetWidth", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetWidth, "None");
	cls_AIS_InteractiveObject.def("AcceptDisplayMode", (Standard_Boolean (AIS_InteractiveObject::*)(const Standard_Integer) const ) &AIS_InteractiveObject::AcceptDisplayMode, "Returns true if the class of objects accepts the display mode aMode. The interactive context can have a default mode of representation for the set of Interactive Objects. This mode may not be accepted by a given class of objects. Consequently, this virtual method allowing us to get information about the class in question must be implemented.", py::arg("aMode"));
	cls_AIS_InteractiveObject.def("DefaultDisplayMode", (Standard_Integer (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::DefaultDisplayMode, "Returns the default display mode. This method is to be implemented when the main mode is not mode 0.");
	cls_AIS_InteractiveObject.def("Redisplay", [](AIS_InteractiveObject &self) -> void { return self.Redisplay(); });
	cls_AIS_InteractiveObject.def("Redisplay", (void (AIS_InteractiveObject::*)(const Standard_Boolean)) &AIS_InteractiveObject::Redisplay, "Updates the active presentation; if <AllModes> = Standard_True all the presentations inside are recomputed. IMPORTANT: It is preferable to call Redisplay method of corresponding AIS_InteractiveContext instance for cases when it is accessible. This method just redirects call to myCTXPtr, so this class field must be up to date for proper result.", py::arg("AllModes"));
	cls_AIS_InteractiveObject.def("SetInfiniteState", [](AIS_InteractiveObject &self) -> void { return self.SetInfiniteState(); });
	cls_AIS_InteractiveObject.def("SetInfiniteState", (void (AIS_InteractiveObject::*)(const Standard_Boolean)) &AIS_InteractiveObject::SetInfiniteState, "Sets the infinite state flag aFlage. if <aFlag> = True , the interactiveObject is considered as infinite, i.e. its graphic presentations are not taken in account for View FitAll...", py::arg("aFlag"));
	cls_AIS_InteractiveObject.def("IsInfinite", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::IsInfinite, "Returns true if the interactive object is infinite. In this case, its graphic presentations are not taken into account in the fit-all view.");
	cls_AIS_InteractiveObject.def("HasInteractiveContext", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::HasInteractiveContext, "Indicates whether the Interactive Object has a pointer to an interactive context.");
	cls_AIS_InteractiveObject.def("GetContext", (opencascade::handle<AIS_InteractiveContext> (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::GetContext, "Returns the context pointer to the interactive context.");
	cls_AIS_InteractiveObject.def("SetContext", (void (AIS_InteractiveObject::*)(const opencascade::handle<AIS_InteractiveContext> &)) &AIS_InteractiveObject::SetContext, "Sets the interactive context aCtx and provides a link to the default drawing tool or 'Drawer' if there is none.", py::arg("aCtx"));
	cls_AIS_InteractiveObject.def("HasOwner", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::HasOwner, "Returns true if the object has an owner attributed to it. The owner can be a shape for a set of sub-shapes or a sub-shape for sub-shapes which it is composed of, and takes the form of a transient.");
	cls_AIS_InteractiveObject.def("GetOwner", (const opencascade::handle<Standard_Transient> & (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::GetOwner, "Returns the owner of the Interactive Object. The owner can be a shape for a set of sub-shapes or a sub-shape for sub-shapes which it is composed of, and takes the form of a transient. There are two types of owners: - Direct owners, decomposition shapes such as edges, wires, and faces. - Users, presentable objects connecting to sensitive primitives, or a shape which has been decomposed.");
	cls_AIS_InteractiveObject.def("SetOwner", (void (AIS_InteractiveObject::*)(const opencascade::handle<Standard_Transient> &)) &AIS_InteractiveObject::SetOwner, "Allows you to attribute the owner theApplicativeEntity to an Interactive Object. This can be a shape for a set of sub-shapes or a sub-shape for sub-shapes which it is composed of. The owner takes the form of a transient.", py::arg("theApplicativeEntity"));
	cls_AIS_InteractiveObject.def("ClearOwner", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::ClearOwner, "Each Interactive Object has methods which allow us to attribute an Owner to it in the form of a Transient. This method removes the owner from the graphic entity.");
	cls_AIS_InteractiveObject.def("HasDisplayMode", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::HasDisplayMode, "Returns true if the Interactive Object has a display mode setting. Otherwise, it is displayed in Neutral Point.");
	cls_AIS_InteractiveObject.def("SetDisplayMode", (void (AIS_InteractiveObject::*)(const Standard_Integer)) &AIS_InteractiveObject::SetDisplayMode, "Sets the display mode aMode for the interactive object. An object can have its own temporary display mode, which is different from that proposed by the interactive context. The range of possibilities currently proposed is the following: - AIS_WireFrame - AIS_Shaded This range can, however, be extended through the creation of new display modes.", py::arg("aMode"));
	cls_AIS_InteractiveObject.def("UnsetDisplayMode", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetDisplayMode, "Removes display mode settings from the interactive object.");
	cls_AIS_InteractiveObject.def("DisplayMode", (Standard_Integer (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::DisplayMode, "Returns the display mode setting of the Interactive Object. The range of possibilities is the following: - AIS_WireFrame - AIS_Shaded This range can, however, be extended through the creation of new display modes.");
	cls_AIS_InteractiveObject.def("HasHilightMode", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::HasHilightMode, "Returns true if the Interactive Object is in highlight mode.");
	cls_AIS_InteractiveObject.def("HilightMode", (Standard_Integer (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::HilightMode, "Returns highlight display mode. This is obsolete method for backward compatibility - use ::HilightAttributes() and ::DynamicHilightAttributes() instead.");
	cls_AIS_InteractiveObject.def("SetHilightMode", (void (AIS_InteractiveObject::*)(const Standard_Integer)) &AIS_InteractiveObject::SetHilightMode, "Sets highlight display mode. This is obsolete method for backward compatibility - use ::HilightAttributes() and ::DynamicHilightAttributes() instead.", py::arg("theMode"));
	cls_AIS_InteractiveObject.def("UnsetHilightMode", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetHilightMode, "Unsets highlight display mode.");
	cls_AIS_InteractiveObject.def("HasColor", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::HasColor, "Returns true if the Interactive Object has color.");
	cls_AIS_InteractiveObject.def("Color", (void (AIS_InteractiveObject::*)(Quantity_Color &) const ) &AIS_InteractiveObject::Color, "Returns the color setting of the Interactive Object.", py::arg("theColor"));
	cls_AIS_InteractiveObject.def("HasWidth", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::HasWidth, "Returns true if the Interactive Object has width.");
	cls_AIS_InteractiveObject.def("Width", (Standard_Real (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::Width, "Returns the width setting of the Interactive Object.");
	cls_AIS_InteractiveObject.def("HasMaterial", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::HasMaterial, "Returns true if the Interactive Object has a setting for material.");
	cls_AIS_InteractiveObject.def("Material", (Graphic3d_NameOfMaterial (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::Material, "Returns the current material setting. This will be on of the following materials: - Brass - Bronze - Gold - Pewter - Silver - Stone.");
	cls_AIS_InteractiveObject.def("SetMaterial", (void (AIS_InteractiveObject::*)(const Graphic3d_MaterialAspect &)) &AIS_InteractiveObject::SetMaterial, "Sets the material aMat defining this display attribute for the interactive object. Material aspect determines shading aspect, color and transparency of visible entities.", py::arg("aName"));
	cls_AIS_InteractiveObject.def("UnsetMaterial", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetMaterial, "Removes the setting for material.");
	cls_AIS_InteractiveObject.def("SetTransparency", [](AIS_InteractiveObject &self) -> void { return self.SetTransparency(); });
	cls_AIS_InteractiveObject.def("SetTransparency", (void (AIS_InteractiveObject::*)(const Standard_Real)) &AIS_InteractiveObject::SetTransparency, "Attributes a setting aValue for transparency. The transparency value should be between 0.0 and 1.0. At 0.0 an object will be totally opaque, and at 1.0, fully transparent. Warning At a value of 1.0, there may be nothing visible.", py::arg("aValue"));
	cls_AIS_InteractiveObject.def("IsTransparent", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::IsTransparent, "Returns true if there is a transparency setting.");
	cls_AIS_InteractiveObject.def("Transparency", (Standard_Real (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::Transparency, "Returns the transparency setting. This will be between 0.0 and 1.0. At 0.0 an object will be totally opaque, and at 1.0, fully transparent.");
	cls_AIS_InteractiveObject.def("UnsetTransparency", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetTransparency, "Removes the transparency setting. The object is opaque by default.");
	cls_AIS_InteractiveObject.def("UnsetAttributes", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetAttributes, "Clears settings provided by the drawing tool aDrawer.");
	cls_AIS_InteractiveObject.def("HasPresentation", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::HasPresentation, "Returns TRUE when this object has a presentation in the current DisplayMode()");
	cls_AIS_InteractiveObject.def("Presentation", (opencascade::handle<Prs3d_Presentation> (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::Presentation, "Returns the current presentation of this object according to the current DisplayMode()");
	cls_AIS_InteractiveObject.def("SetAspect", (void (AIS_InteractiveObject::*)(const opencascade::handle<Prs3d_BasicAspect> &)) &AIS_InteractiveObject::SetAspect, "Sets the graphic basic aspect to the current presentation.", py::arg("anAspect"));
	cls_AIS_InteractiveObject.def("SetPolygonOffsets", [](AIS_InteractiveObject &self, const Standard_Integer a0) -> void { return self.SetPolygonOffsets(a0); }, py::arg("aMode"));
	cls_AIS_InteractiveObject.def("SetPolygonOffsets", [](AIS_InteractiveObject &self, const Standard_Integer a0, const Standard_ShortReal a1) -> void { return self.SetPolygonOffsets(a0, a1); }, py::arg("aMode"), py::arg("aFactor"));
	cls_AIS_InteractiveObject.def("SetPolygonOffsets", (void (AIS_InteractiveObject::*)(const Standard_Integer, const Standard_ShortReal, const Standard_ShortReal)) &AIS_InteractiveObject::SetPolygonOffsets, "Sets up polygon offsets for this object. It modifies all existing presentations of <anObj> (if any), so it is reasonable to call this method after <anObj> has been displayed. Otherwise, Compute() method should pass Graphic3d_AspectFillArea3d aspect from <myDrawer> to Graphic3d_Group to make polygon offsets work.", py::arg("aMode"), py::arg("aFactor"), py::arg("aUnits"));
	cls_AIS_InteractiveObject.def("HasPolygonOffsets", (Standard_Boolean (AIS_InteractiveObject::*)() const ) &AIS_InteractiveObject::HasPolygonOffsets, "Returns Standard_True if <myDrawer> has non-null shading aspect");
	cls_AIS_InteractiveObject.def("PolygonOffsets", [](AIS_InteractiveObject &self, Standard_Integer & aMode, Standard_ShortReal & aFactor, Standard_ShortReal & aUnits){ self.PolygonOffsets(aMode, aFactor, aUnits); return aMode; }, "Retrieves current polygon offsets settings from <myDrawer>.", py::arg("aMode"), py::arg("aFactor"), py::arg("aUnits"));
	cls_AIS_InteractiveObject.def("BoundingBox", (void (AIS_InteractiveObject::*)(Bnd_Box &)) &AIS_InteractiveObject::BoundingBox, "Returns bounding box of object correspondingly to its current display mode.", py::arg("theBndBox"));
	cls_AIS_InteractiveObject.def("SetIsoOnTriangulation", (void (AIS_InteractiveObject::*)(const Standard_Boolean)) &AIS_InteractiveObject::SetIsoOnTriangulation, "Enables or disables on-triangulation build of isolines according to the flag given.", py::arg("theIsEnabled"));
	cls_AIS_InteractiveObject.def("SynchronizeAspects", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::SynchronizeAspects, "Synchronize presentation aspects after their modification.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_InteractiveContext.hxx
	py::class_<AIS_InteractiveContext, opencascade::handle<AIS_InteractiveContext>, Standard_Transient> cls_AIS_InteractiveContext(mod, "AIS_InteractiveContext", "The Interactive Context allows you to manage graphic behavior and selection of Interactive Objects in one or more viewers. Class methods make this highly transparent. It is essential to remember that an Interactive Object which is already known by the Interactive Context must be modified using Context methods. You can only directly call the methods available for an Interactive Object if it has not been loaded into an Interactive Context.");
	cls_AIS_InteractiveContext.def(py::init<const opencascade::handle<V3d_Viewer> &>(), py::arg("MainViewer"));
	cls_AIS_InteractiveContext.def_static("get_type_name_", (const char * (*)()) &AIS_InteractiveContext::get_type_name, "None");
	cls_AIS_InteractiveContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_InteractiveContext::get_type_descriptor, "None");
	cls_AIS_InteractiveContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DynamicType, "None");
	cls_AIS_InteractiveContext.def("DisplayStatus", (AIS_DisplayStatus (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::DisplayStatus, "Returns the display status of the entity anIobj. This will be one of the following: - AIS_DS_Displayed displayed in main viewer - AIS_DS_Erased hidden in main viewer - AIS_DS_Temporary temporarily displayed - AIS_DS_None nowhere displayed.", py::arg("anIobj"));
	cls_AIS_InteractiveContext.def("Status", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, TCollection_ExtendedString &) const ) &AIS_InteractiveContext::Status, "Returns the status of the Interactive Context for the view of the Interactive Object.", py::arg("anObj"), py::arg("astatus"));
	cls_AIS_InteractiveContext.def("IsDisplayed", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::IsDisplayed, "Returns true if Object is displayed in the interactive context.", py::arg("anIobj"));
	cls_AIS_InteractiveContext.def("IsDisplayed", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer) const ) &AIS_InteractiveContext::IsDisplayed, "None", py::arg("aniobj"), py::arg("aMode"));
	cls_AIS_InteractiveContext.def("SetAutoActivateSelection", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::SetAutoActivateSelection, "Enable or disable automatic activation of default selection mode while displaying the object.", py::arg("theIsAuto"));
	cls_AIS_InteractiveContext.def("GetAutoActivateSelection", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::GetAutoActivateSelection, "Manages displaying the new object should also automatically activate default selection mode; TRUE by default.");
	cls_AIS_InteractiveContext.def("Display", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Display, "Displays the object in this Context using default Display Mode. This will be the object's default display mode, if there is one. Otherwise, it will be the context mode. The Interactive Object's default selection mode is activated if GetAutoActivateSelection() is TRUE. In general, this is 0.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("Display", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Boolean a3) -> void { return self.Display(a0, a1, a2, a3); }, py::arg("theIObj"), py::arg("theDispMode"), py::arg("theSelectionMode"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("Display", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Boolean a3, const Standard_Boolean a4) -> void { return self.Display(a0, a1, a2, a3, a4); }, py::arg("theIObj"), py::arg("theDispMode"), py::arg("theSelectionMode"), py::arg("theToUpdateViewer"), py::arg("theToAllowDecomposition"));
	cls_AIS_InteractiveContext.def("Display", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const AIS_DisplayStatus)) &AIS_InteractiveContext::Display, "Sets status, display mode and selection mode for specified Object If theSelectionMode equals -1, theIObj will not be activated: it will be displayed but will not be selectable.", py::arg("theIObj"), py::arg("theDispMode"), py::arg("theSelectionMode"), py::arg("theToUpdateViewer"), py::arg("theToAllowDecomposition"), py::arg("theDispStatus"));
	cls_AIS_InteractiveContext.def("Load", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.Load(a0); }, py::arg("aniobj"));
	cls_AIS_InteractiveContext.def("Load", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1) -> void { return self.Load(a0, a1); }, py::arg("aniobj"), py::arg("SelectionMode"));
	cls_AIS_InteractiveContext.def("Load", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::Load, "Allows you to load the Interactive Object with a given selection mode, and/or with the desired decomposition option, whether the object is visualized or not. If AllowDecomp = Standard_True and, if the interactive object is of the 'Shape' type, these 'standard' selection modes will be automatically activated as a function of the modes present in the Local Context. The loaded objects will be selectable but displayable in highlighting only when detected by the Selector. This method is available only when Local Contexts are open.", py::arg("aniobj"), py::arg("SelectionMode"), py::arg("AllowDecomp"));
	cls_AIS_InteractiveContext.def("Erase", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Erase, "Hides the object. The object's presentations are simply flagged as invisible and therefore excluded from redrawing. To show hidden objects, use Display().", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("EraseAll", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::EraseAll, "Hides all objects. The object's presentations are simply flagged as invisible and therefore excluded from redrawing. To show all hidden objects, use DisplayAll().", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("DisplayAll", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::DisplayAll, "Displays all hidden objects.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("EraseSelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::EraseSelected, "Hides selected objects. The object's presentations are simply flagged as invisible and therefore excluded from redrawing. To show hidden objects, use Display().", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("DisplaySelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::DisplaySelected, "Displays current objects.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("ClearPrs", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::ClearPrs, "Empties the graphic presentation of the mode indexed by aMode. Warning! Removes theIObj. theIObj is still active if it was previously activated.", py::arg("theIObj"), py::arg("theMode"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("Remove", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Remove, "Removes Object from every viewer.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("RemoveAll", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::RemoveAll, "Removes all the objects from all opened Local Contexts and from the Neutral Point.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("Redisplay", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Boolean a1) -> void { return self.Redisplay(a0, a1); }, py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("Redisplay", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean, const Standard_Boolean)) &AIS_InteractiveContext::Redisplay, "Recomputes the seen parts presentation of the Object. If theAllModes equals true, all presentations are present in the object even if unseen.", py::arg("theIObj"), py::arg("theToUpdateViewer"), py::arg("theAllModes"));
	cls_AIS_InteractiveContext.def("Redisplay", (void (AIS_InteractiveContext::*)(const AIS_KindOfInteractive, const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::Redisplay, "Recomputes the Prs/Selection of displayed objects of a given type and a given signature. if signature = -1 doesn't take signature criterion.", py::arg("theTypeOfObject"), py::arg("theSignature"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("RecomputePrsOnly", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Boolean a1) -> void { return self.RecomputePrsOnly(a0, a1); }, py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("RecomputePrsOnly", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean, const Standard_Boolean)) &AIS_InteractiveContext::RecomputePrsOnly, "Recomputes the displayed presentations, flags the others. Doesn't update presentations.", py::arg("theIObj"), py::arg("theToUpdateViewer"), py::arg("theAllModes"));
	cls_AIS_InteractiveContext.def("RecomputeSelectionOnly", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::RecomputeSelectionOnly, "Recomputes the active selections, flags the others. Doesn't update presentations.", py::arg("anIObj"));
	cls_AIS_InteractiveContext.def("Update", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Update, "Updates displayed interactive object by checking and recomputing its flagged as 'to be recomputed' presentation and selection structures. This method does not force any recomputation on its own. The method recomputes selections even if they are loaded without activation in particular selector.", py::arg("theIObj"), py::arg("theUpdateViewer"));
	cls_AIS_InteractiveContext.def("HighlightStyle", (const opencascade::handle<Prs3d_Drawer> & (AIS_InteractiveContext::*)(const Prs3d_TypeOfHighlight) const ) &AIS_InteractiveContext::HighlightStyle, "Returns highlight style settings.", py::arg("theStyleType"));
	cls_AIS_InteractiveContext.def("SetHighlightStyle", (void (AIS_InteractiveContext::*)(const Prs3d_TypeOfHighlight, const opencascade::handle<Prs3d_Drawer> &)) &AIS_InteractiveContext::SetHighlightStyle, "Setup highlight style settings.", py::arg("theStyleType"), py::arg("theStyle"));
	cls_AIS_InteractiveContext.def("HighlightStyle", (const opencascade::handle<Prs3d_Drawer> & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::HighlightStyle, "Returns current dynamic highlight style settings. By default: - the color of dynamic highlight is Quantity_NOC_CYAN1; - the presentation for dynamic highlight is completely opaque; - the type of highlight is Aspect_TOHM_COLOR.");
	cls_AIS_InteractiveContext.def("SetHighlightStyle", (void (AIS_InteractiveContext::*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_InteractiveContext::SetHighlightStyle, "Setup the style of dynamic highlighting.", py::arg("theStyle"));
	cls_AIS_InteractiveContext.def("SelectionStyle", (const opencascade::handle<Prs3d_Drawer> & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::SelectionStyle, "Returns current selection style settings. By default: - the color of selection is Quantity_NOC_GRAY80; - the presentation for selection is completely opaque; - the type of highlight is Aspect_TOHM_COLOR.");
	cls_AIS_InteractiveContext.def("SetSelectionStyle", (void (AIS_InteractiveContext::*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_InteractiveContext::SetSelectionStyle, "Setup the style of selection highlighting.", py::arg("theStyle"));
	cls_AIS_InteractiveContext.def("HighlightStyle", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, opencascade::handle<Prs3d_Drawer> &) const ) &AIS_InteractiveContext::HighlightStyle, "Returns highlight style of the object if it is marked as highlighted via global status", py::arg("theObj"), py::arg("theStyle"));
	cls_AIS_InteractiveContext.def("HighlightStyle", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &, opencascade::handle<Prs3d_Drawer> &) const ) &AIS_InteractiveContext::HighlightStyle, "Returns highlight style of the owner if it is selected", py::arg("theOwner"), py::arg("theStyle"));
	cls_AIS_InteractiveContext.def("IsHilighted", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::IsHilighted, "Returns true if the object is marked as highlighted via its global status", py::arg("theObj"));
	cls_AIS_InteractiveContext.def("IsHilighted", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const ) &AIS_InteractiveContext::IsHilighted, "Returns true if the owner is marked as selected", py::arg("theOwner"));
	cls_AIS_InteractiveContext.def("Hilight", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Hilight, "Updates the display in the viewer to take dynamic detection into account. On dynamic detection by the mouse cursor, sensitive primitives are highlighted. The highlight color of entities detected by mouse movement is white by default.", py::arg("theObj"), py::arg("theIsToUpdateViewer"));
	cls_AIS_InteractiveContext.def("HilightWithColor", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean)) &AIS_InteractiveContext::HilightWithColor, "Changes the color of all the lines of the object in view.", py::arg("theObj"), py::arg("theStyle"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("Unhilight", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Unhilight, "Removes hilighting from the Object.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("DisplayPriority", (Standard_Integer (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::DisplayPriority, "Returns the display priority of the Object.", py::arg("theIObj"));
	cls_AIS_InteractiveContext.def("SetDisplayPriority", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_InteractiveContext::SetDisplayPriority, "Sets the display priority of the seen parts presentation of the Object.", py::arg("theIObj"), py::arg("thePriority"));
	cls_AIS_InteractiveContext.def("GetZLayer", (Standard_Integer (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::GetZLayer, "Get Z layer id set for displayed interactive object.", py::arg("theIObj"));
	cls_AIS_InteractiveContext.def("SetZLayer", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_InteractiveContext::SetZLayer, "Set Z layer id for interactive object. The Z layers can be used to display temporarily presentations of some object in front of the other objects in the scene. The ids for Z layers are generated by V3d_Viewer.", py::arg("theIObj"), py::arg("theLayerId"));
	cls_AIS_InteractiveContext.def("SetViewAffinity", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::SetViewAffinity, "Setup object visibility in specified view. Has no effect if object is not displayed in this context.", py::arg("theIObj"), py::arg("theView"), py::arg("theIsVisible"));
	cls_AIS_InteractiveContext.def("DisplayMode", (Standard_Integer (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DisplayMode, "Returns the Display Mode setting to be used by default.");
	cls_AIS_InteractiveContext.def("SetDisplayMode", (void (AIS_InteractiveContext::*)(const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::SetDisplayMode, "Sets the display mode of seen Interactive Objects (which have no overridden Display Mode).", py::arg("theMode"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetDisplayMode", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::SetDisplayMode, "Sets the display mode of seen Interactive Objects. theMode provides the display mode index of the entity theIObj.", py::arg("theIObj"), py::arg("theMode"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("UnsetDisplayMode", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetDisplayMode, "Unsets the display mode of seen Interactive Objects.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetLocation", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const TopLoc_Location &)) &AIS_InteractiveContext::SetLocation, "Puts the location on the initial graphic representation and the selection for the Object.", py::arg("theObject"), py::arg("theLocation"));
	cls_AIS_InteractiveContext.def("ResetLocation", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::ResetLocation, "Puts the Object back into its initial position.", py::arg("theObject"));
	cls_AIS_InteractiveContext.def("HasLocation", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::HasLocation, "Returns true if the Object has a location.", py::arg("theObject"));
	cls_AIS_InteractiveContext.def("Location", (TopLoc_Location (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::Location, "Returns the location of the Object.", py::arg("theObject"));
	cls_AIS_InteractiveContext.def("SetTransformPersistence", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Graphic3d_TransformPers> &)) &AIS_InteractiveContext::SetTransformPersistence, "Sets transform persistence.", py::arg("theObject"), py::arg("theTrsfPers"));
	cls_AIS_InteractiveContext.def("SetTransformPersistence", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Graphic3d_TransModeFlags & a1) -> void { return self.SetTransformPersistence(a0, a1); }, py::arg("theObj"), py::arg("theFlag"));
	cls_AIS_InteractiveContext.def("SetTransformPersistence", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Graphic3d_TransModeFlags &, const gp_Pnt &)) &AIS_InteractiveContext::SetTransformPersistence, "None", py::arg("theObj"), py::arg("theFlag"), py::arg("thePoint"));
	cls_AIS_InteractiveContext.def("SetPixelTolerance", [](AIS_InteractiveContext &self) -> void { return self.SetPixelTolerance(); });
	cls_AIS_InteractiveContext.def("SetPixelTolerance", (void (AIS_InteractiveContext::*)(const Standard_Integer)) &AIS_InteractiveContext::SetPixelTolerance, "Setup pixel tolerance for MoveTo() operation.", py::arg("thePrecision"));
	cls_AIS_InteractiveContext.def("PixelTolerance", (Standard_Integer (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::PixelTolerance, "Returns the pixel tolerance, default is 2. Pixel Tolerance extends sensitivity within MoveTo() operation (picking by point) and can be adjusted by application based on user input precision (e.g. screen pixel density, input device precision, etc.).");
	cls_AIS_InteractiveContext.def("SetSelectionSensitivity", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Integer)) &AIS_InteractiveContext::SetSelectionSensitivity, "Allows to manage sensitivity of a particular selection of interactive object theObject and changes previous sensitivity value of all sensitive entities in selection with theMode to the given theNewSensitivity.", py::arg("theObject"), py::arg("theMode"), py::arg("theNewSensitivity"));
	cls_AIS_InteractiveContext.def("MoveTo", (AIS_StatusOfDetection (AIS_InteractiveContext::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::MoveTo, "Relays mouse position in pixels theXPix and theYPix to the interactive context selectors. This is done by the view theView passing this position to the main viewer and updating it. Functions in both Neutral Point and local contexts. If theToRedrawOnUpdate is set to false, callee should call RedrawImmediate() to highlight detected object.", py::arg("theXPix"), py::arg("theYPix"), py::arg("theView"), py::arg("theToRedrawOnUpdate"));
	cls_AIS_InteractiveContext.def("HasDetected", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::HasDetected, "Returns true if there is a mouse-detected entity in context.");
	cls_AIS_InteractiveContext.def("DetectedOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DetectedOwner, "Returns the owner of the detected sensitive primitive which is currently dynamically highlighted. WARNING! This method is irrelevant to InitDetected()/MoreDetected()/NextDetected().");
	cls_AIS_InteractiveContext.def("DetectedInteractive", (opencascade::handle<AIS_InteractiveObject> (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DetectedInteractive, "Returns the interactive objects last detected in context. In general this is just a wrapper for Handle(AIS_InteractiveObject)::DownCast(DetectedOwner()->Selectable()).");
	cls_AIS_InteractiveContext.def("HasDetectedShape", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::HasDetectedShape, "Returns true if there is a detected shape in local context.");
	cls_AIS_InteractiveContext.def("DetectedShape", (const TopoDS_Shape & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DetectedShape, "Returns the shape detected in local context.");
	cls_AIS_InteractiveContext.def("HasNextDetected", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::HasNextDetected, "returns True if other entities were detected in the last mouse detection");
	cls_AIS_InteractiveContext.def("HilightNextDetected", [](AIS_InteractiveContext &self, const opencascade::handle<V3d_View> & a0) -> Standard_Integer { return self.HilightNextDetected(a0); }, py::arg("theView"));
	cls_AIS_InteractiveContext.def("HilightNextDetected", (Standard_Integer (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::HilightNextDetected, "If more than 1 object is detected by the selector, only the 'best' owner is hilighted at the mouse position. This Method allows the user to hilight one after another the other detected entities. If The method select is called, the selected entity will be the hilighted one! WARNING: Loop Method. When all the detected entities have been hilighted, the next call will hilight the first one again.", py::arg("theView"), py::arg("theToRedrawImmediate"));
	cls_AIS_InteractiveContext.def("HilightPreviousDetected", [](AIS_InteractiveContext &self, const opencascade::handle<V3d_View> & a0) -> Standard_Integer { return self.HilightPreviousDetected(a0); }, py::arg("theView"));
	cls_AIS_InteractiveContext.def("HilightPreviousDetected", (Standard_Integer (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::HilightPreviousDetected, "Same as previous methods in reverse direction.", py::arg("theView"), py::arg("theToRedrawImmediate"));
	cls_AIS_InteractiveContext.def("InitDetected", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::InitDetected, "Initialization for iteration through mouse-detected objects in interactive context or in local context if it is opened.");
	cls_AIS_InteractiveContext.def("MoreDetected", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::MoreDetected, "Return TRUE if there is more mouse-detected objects after the current one during iteration through mouse-detected interactive objects.");
	cls_AIS_InteractiveContext.def("NextDetected", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::NextDetected, "Gets next current object during iteration through mouse-detected interactive objects.");
	cls_AIS_InteractiveContext.def("DetectedCurrentOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DetectedCurrentOwner, "Returns the owner from detected list pointed by current iterator position. WARNING! This method is irrelevant to DetectedOwner() which returns last picked Owner regardless of iterator position!");
	cls_AIS_InteractiveContext.def("SetSelectedAspect", (void (AIS_InteractiveContext::*)(const opencascade::handle<Prs3d_BasicAspect> &, const Standard_Boolean)) &AIS_InteractiveContext::SetSelectedAspect, "Sets the graphic basic aspect to the current presentation of ALL selected objects.", py::arg("theAspect"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("AddSelect", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_InteractiveContext::AddSelect, "Adds object in the selection.", py::arg("theObject"));
	cls_AIS_InteractiveContext.def("AddSelect", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::AddSelect, "Adds object in the selection.", py::arg("theObject"));
	cls_AIS_InteractiveContext.def("Select", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::Select, "Selects everything found in the bounding rectangle defined by the pixel minima and maxima, XPMin, YPMin, XPMax, and YPMax in the view. The objects detected are passed to the main viewer, which is then updated.", py::arg("theXPMin"), py::arg("theYPMin"), py::arg("theXPMax"), py::arg("theYPMax"), py::arg("theView"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("Select", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const TColgp_Array1OfPnt2d &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::Select, "polyline selection; clears the previous picked list", py::arg("thePolyline"), py::arg("theView"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("Select", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::Select, "Stores and hilights the previous detected; Unhilights the previous picked.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::ShiftSelect, "Adds the last detected to the list of previous picked. If the last detected was already declared as picked, removes it from the Picked List.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const TColgp_Array1OfPnt2d &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::ShiftSelect, "Adds the last detected to the list of previous picked. If the last detected was already declared as picked, removes it from the Picked List.", py::arg("thePolyline"), py::arg("theView"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::ShiftSelect, "Rectangle of selection; adds new detected entities into the picked list, removes the detected entities that were already stored.", py::arg("theXPMin"), py::arg("theYPMin"), py::arg("theXPMax"), py::arg("theYPMax"), py::arg("theView"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("FitSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::FitSelected, "Fits the view correspondingly to the bounds of selected objects. Infinite objects are ignored if infinite state of AIS_InteractiveObject is set to true.", py::arg("theView"), py::arg("theMargin"), py::arg("theToUpdate"));
	cls_AIS_InteractiveContext.def("FitSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &)) &AIS_InteractiveContext::FitSelected, "Fits the view correspondingly to the bounds of selected objects. Infinite objects are ignored if infinite state of AIS_InteractiveObject is set to true.", py::arg("theView"));
	cls_AIS_InteractiveContext.def("SetToHilightSelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::SetToHilightSelected, "Specify whether selected object must be hilighted when mouse cursor is moved above it (in MoveTo method). By default this value is false and selected object is not hilighted in this case.", py::arg("toHilight"));
	cls_AIS_InteractiveContext.def("ToHilightSelected", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::ToHilightSelected, "Return value specified whether selected object must be hilighted when mouse cursor is moved above it");
	cls_AIS_InteractiveContext.def("SetSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Boolean)) &AIS_InteractiveContext::SetSelected, "Unhighlights previously selected owners and marks them as not selected. Marks owner given as selected and highlights it. Performs selection filters check.", py::arg("theOwners"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::SetSelected, "Puts the interactive object aniObj in the list of selected objects. Performs selection filters check.", py::arg("theObject"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("AddOrRemoveSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::AddOrRemoveSelected, "Allows to highlight or unhighlight the owner given depending on its selection status", py::arg("theObject"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("HilightSelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::HilightSelected, "Highlights selected objects.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("UnhilightSelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::UnhilightSelected, "Removes highlighting from selected objects.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("UpdateSelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::UpdateSelected, "Updates the list of selected objects: i.e. highlights the newely selected ones and unhighlights previously selected objects.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("ClearSelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::ClearSelected, "Empties previous selected objects in order to get the selected objects detected by the selector using UpdateSelected.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("AddOrRemoveSelected", (void (AIS_InteractiveContext::*)(const TopoDS_Shape &, const Standard_Boolean)) &AIS_InteractiveContext::AddOrRemoveSelected, "No right to Add a selected Shape (Internal Management of shape Selection). A Previous selected shape may only be removed.", py::arg("theShape"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("AddOrRemoveSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Boolean)) &AIS_InteractiveContext::AddOrRemoveSelected, "Allows to highlight or unhighlight the owner given depending on its selection status", py::arg("theOwner"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("IsSelected", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const ) &AIS_InteractiveContext::IsSelected, "Returns true is the owner given is selected", py::arg("theOwner"));
	cls_AIS_InteractiveContext.def("IsSelected", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::IsSelected, "Returns true is the object given is selected", py::arg("theObj"));
	cls_AIS_InteractiveContext.def("FirstSelectedObject", (opencascade::handle<AIS_InteractiveObject> (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::FirstSelectedObject, "Returns the first selected object in the list of current selected.");
	cls_AIS_InteractiveContext.def("NbSelected", (Standard_Integer (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::NbSelected, "Count a number of selected entities using InitSelected()+MoreSelected()+NextSelected() iterator.");
	cls_AIS_InteractiveContext.def("InitSelected", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::InitSelected, "Initializes a scan of the selected objects.");
	cls_AIS_InteractiveContext.def("MoreSelected", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::MoreSelected, "Returns true if there is another object found by the scan of the list of selected objects.");
	cls_AIS_InteractiveContext.def("NextSelected", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::NextSelected, "Continues the scan to the next object in the list of selected objects.");
	cls_AIS_InteractiveContext.def("SelectedOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::SelectedOwner, "Returns the owner of the selected entity.");
	cls_AIS_InteractiveContext.def("SelectedInteractive", (opencascade::handle<AIS_InteractiveObject> (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::SelectedInteractive, "Return Handle(AIS_InteractiveObject)::DownCast (SelectedOwner()->Selectable()).");
	cls_AIS_InteractiveContext.def("HasSelectedShape", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::HasSelectedShape, "Returns TRUE if the interactive context has a shape selected.");
	cls_AIS_InteractiveContext.def("SelectedShape", (TopoDS_Shape (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::SelectedShape, "Returns the selected shape. Basically it is just a shape returned stored by StdSelect_BRepOwner with graphic transformation being applied:");
	cls_AIS_InteractiveContext.def("HasApplicative", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::HasApplicative, "Returns SelectedInteractive()->HasOwner().");
	cls_AIS_InteractiveContext.def("Applicative", (opencascade::handle<Standard_Transient> (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::Applicative, "Returns SelectedInteractive()->GetOwner().");
	cls_AIS_InteractiveContext.def("BeginImmediateDraw", (Standard_Boolean (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::BeginImmediateDraw, "initializes the list of presentations to be displayed returns False if no local context is opened.");
	cls_AIS_InteractiveContext.def("ImmediateAdd", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> Standard_Boolean { return self.ImmediateAdd(a0); }, py::arg("theObj"));
	cls_AIS_InteractiveContext.def("ImmediateAdd", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_InteractiveContext::ImmediateAdd, "returns True if <anIObj> has been stored in the list.", py::arg("theObj"), py::arg("theMode"));
	cls_AIS_InteractiveContext.def("EndImmediateDraw", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &)) &AIS_InteractiveContext::EndImmediateDraw, "returns True if the immediate display has been done.", py::arg("theView"));
	cls_AIS_InteractiveContext.def("EndImmediateDraw", (Standard_Boolean (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::EndImmediateDraw, "Uses the First Active View of Main Viewer! returns True if the immediate display has been done.");
	cls_AIS_InteractiveContext.def("IsImmediateModeOn", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::IsImmediateModeOn, "None");
	cls_AIS_InteractiveContext.def("RedrawImmediate", (void (AIS_InteractiveContext::*)(const opencascade::handle<V3d_Viewer> &)) &AIS_InteractiveContext::RedrawImmediate, "Redraws immediate structures in all views of the viewer given taking into account its visibility.", py::arg("theViewer"));
	cls_AIS_InteractiveContext.def("Activate", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.Activate(a0); }, py::arg("anIobj"));
	cls_AIS_InteractiveContext.def("Activate", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1) -> void { return self.Activate(a0, a1); }, py::arg("anIobj"), py::arg("aMode"));
	cls_AIS_InteractiveContext.def("Activate", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::Activate, "Activates the selection mode aMode whose index is given, for the given interactive entity anIobj.", py::arg("anIobj"), py::arg("aMode"), py::arg("theIsForce"));
	cls_AIS_InteractiveContext.def("Activate", [](AIS_InteractiveContext &self, const Standard_Integer a0) -> void { return self.Activate(a0); }, py::arg("theMode"));
	cls_AIS_InteractiveContext.def("Activate", (void (AIS_InteractiveContext::*)(const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::Activate, "Activates the given selection mode for the all displayed objects.", py::arg("theMode"), py::arg("theIsForce"));
	cls_AIS_InteractiveContext.def("Deactivate", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::Deactivate, "Deactivates all the activated selection modes of an object.", py::arg("anIObj"));
	cls_AIS_InteractiveContext.def("Deactivate", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_InteractiveContext::Deactivate, "Deactivates all the activated selection modes of the interactive object anIobj with a given selection mode aMode.", py::arg("anIobj"), py::arg("aMode"));
	cls_AIS_InteractiveContext.def("Deactivate", (void (AIS_InteractiveContext::*)(const Standard_Integer)) &AIS_InteractiveContext::Deactivate, "Deactivates the given selection mode for all displayed objects.", py::arg("theMode"));
	cls_AIS_InteractiveContext.def("Deactivate", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::Deactivate, "Deactivates all the activated selection mode at all displayed objects.");
	cls_AIS_InteractiveContext.def("ActivatedModes", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, TColStd_ListOfInteger &) const ) &AIS_InteractiveContext::ActivatedModes, "Returns the list of activated selection modes in an open context.", py::arg("anIobj"), py::arg("theList"));
	cls_AIS_InteractiveContext.def("EntityOwners", [](AIS_InteractiveContext &self, opencascade::handle<SelectMgr_IndexedMapOfOwner> & a0, const opencascade::handle<AIS_InteractiveObject> & a1) -> void { return self.EntityOwners(a0, a1); }, py::arg("theOwners"), py::arg("theIObj"));
	cls_AIS_InteractiveContext.def("EntityOwners", (void (AIS_InteractiveContext::*)(opencascade::handle<SelectMgr_IndexedMapOfOwner> &, const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer) const ) &AIS_InteractiveContext::EntityOwners, "Returns a collection containing all entity owners created for the interactive object in specified selection mode (in all active modes if the Mode == -1)", py::arg("theOwners"), py::arg("theIObj"), py::arg("theMode"));
	cls_AIS_InteractiveContext.def("Filters", (const SelectMgr_ListOfFilter & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::Filters, "Returns the list of filters active in a local context.");
	cls_AIS_InteractiveContext.def("AddFilter", (void (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_Filter> &)) &AIS_InteractiveContext::AddFilter, "Allows you to add the filter.", py::arg("theFilter"));
	cls_AIS_InteractiveContext.def("RemoveFilter", (void (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_Filter> &)) &AIS_InteractiveContext::RemoveFilter, "Removes a filter from context.", py::arg("theFilter"));
	cls_AIS_InteractiveContext.def("RemoveFilters", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::RemoveFilters, "Remove all filters from context.");
	cls_AIS_InteractiveContext.def("PickingStrategy", (SelectMgr_PickingStrategy (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::PickingStrategy, "Return picking strategy; SelectMgr_PickingStrategy_FirstAcceptable by default.");
	cls_AIS_InteractiveContext.def("SetPickingStrategy", (void (AIS_InteractiveContext::*)(const SelectMgr_PickingStrategy)) &AIS_InteractiveContext::SetPickingStrategy, "Setup picking strategy - which entities detected by picking line will be accepted, considering Selection Filters. By default (SelectMgr_PickingStrategy_FirstAcceptable), Selection Filters reduce the list of entities so that the context accepts topmost in remaining.", py::arg("theStrategy"));
	cls_AIS_InteractiveContext.def("DefaultDrawer", (const opencascade::handle<Prs3d_Drawer> & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DefaultDrawer, "Returns the default attribute manager. This contains all the color and line attributes which can be used by interactive objects which do not have their own attributes.");
	cls_AIS_InteractiveContext.def("CurrentViewer", (const opencascade::handle<V3d_Viewer> & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::CurrentViewer, "Returns the current viewer.");
	cls_AIS_InteractiveContext.def("SelectionManager", (const opencascade::handle<SelectMgr_SelectionManager> & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::SelectionManager, "None");
	cls_AIS_InteractiveContext.def("MainPrsMgr", (const opencascade::handle<PrsMgr_PresentationManager3d> & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::MainPrsMgr, "None");
	cls_AIS_InteractiveContext.def("MainSelector", (const opencascade::handle<StdSelect_ViewerSelector3d> & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::MainSelector, "None");
	cls_AIS_InteractiveContext.def("UpdateCurrentViewer", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::UpdateCurrentViewer, "Updates the current viewer.");
	cls_AIS_InteractiveContext.def("DisplayedObjects", [](AIS_InteractiveContext &self, AIS_ListOfInteractive & a0) -> void { return self.DisplayedObjects(a0); }, py::arg("aListOfIO"));
	cls_AIS_InteractiveContext.def("DisplayedObjects", (void (AIS_InteractiveContext::*)(AIS_ListOfInteractive &, const Standard_Boolean) const ) &AIS_InteractiveContext::DisplayedObjects, "Returns the list of displayed objects of a particular Type WhichKind and Signature WhichSignature. By Default, WhichSignature equals -1. This means that there is a check on type only.", py::arg("aListOfIO"), py::arg("OnlyFromNeutral"));
	cls_AIS_InteractiveContext.def("DisplayedObjects", [](AIS_InteractiveContext &self, const AIS_KindOfInteractive a0, const Standard_Integer a1, AIS_ListOfInteractive & a2) -> void { return self.DisplayedObjects(a0, a1, a2); }, py::arg("WhichKind"), py::arg("WhichSignature"), py::arg("aListOfIO"));
	cls_AIS_InteractiveContext.def("DisplayedObjects", (void (AIS_InteractiveContext::*)(const AIS_KindOfInteractive, const Standard_Integer, AIS_ListOfInteractive &, const Standard_Boolean) const ) &AIS_InteractiveContext::DisplayedObjects, "gives the list of displayed objects of a particular Type and signature. by Default, <WhichSignature> = -1 means control only on <WhichKind>.", py::arg("WhichKind"), py::arg("WhichSignature"), py::arg("aListOfIO"), py::arg("OnlyFromNeutral"));
	cls_AIS_InteractiveContext.def("ErasedObjects", (void (AIS_InteractiveContext::*)(AIS_ListOfInteractive &) const ) &AIS_InteractiveContext::ErasedObjects, "Returns the list theListOfIO of erased objects (hidden objects) particular Type WhichKind and Signature WhichSignature. By Default, WhichSignature equals 1. This means that there is a check on type only.", py::arg("theListOfIO"));
	cls_AIS_InteractiveContext.def("ErasedObjects", (void (AIS_InteractiveContext::*)(const AIS_KindOfInteractive, const Standard_Integer, AIS_ListOfInteractive &) const ) &AIS_InteractiveContext::ErasedObjects, "gives the list of erased objects (hidden objects) Type and signature by Default, <WhichSignature> = -1 means control only on <WhichKind>.", py::arg("WhichKind"), py::arg("WhichSignature"), py::arg("theListOfIO"));
	cls_AIS_InteractiveContext.def("ObjectsByDisplayStatus", (void (AIS_InteractiveContext::*)(const AIS_DisplayStatus, AIS_ListOfInteractive &) const ) &AIS_InteractiveContext::ObjectsByDisplayStatus, "Returns the list theListOfIO of objects with indicated display status particular Type WhichKind and Signature WhichSignature. By Default, WhichSignature equals 1. This means that there is a check on type only.", py::arg("theStatus"), py::arg("theListOfIO"));
	cls_AIS_InteractiveContext.def("ObjectsByDisplayStatus", (void (AIS_InteractiveContext::*)(const AIS_KindOfInteractive, const Standard_Integer, const AIS_DisplayStatus, AIS_ListOfInteractive &) const ) &AIS_InteractiveContext::ObjectsByDisplayStatus, "gives the list of objects with indicated display status Type and signature by Default, <WhichSignature> = -1 means control only on <WhichKind>.", py::arg("WhichKind"), py::arg("WhichSignature"), py::arg("theStatus"), py::arg("theListOfIO"));
	cls_AIS_InteractiveContext.def("ObjectsInside", [](AIS_InteractiveContext &self, AIS_ListOfInteractive & a0) -> void { return self.ObjectsInside(a0); }, py::arg("aListOfIO"));
	cls_AIS_InteractiveContext.def("ObjectsInside", [](AIS_InteractiveContext &self, AIS_ListOfInteractive & a0, const AIS_KindOfInteractive a1) -> void { return self.ObjectsInside(a0, a1); }, py::arg("aListOfIO"), py::arg("WhichKind"));
	cls_AIS_InteractiveContext.def("ObjectsInside", (void (AIS_InteractiveContext::*)(AIS_ListOfInteractive &, const AIS_KindOfInteractive, const Standard_Integer) const ) &AIS_InteractiveContext::ObjectsInside, "fills <aListOfIO> with objects of a particular Type and Signature with no consideration of display status. by Default, <WhichSignature> = -1 means control only on <WhichKind>. if <WhichKind> = AIS_KOI_None and <WhichSignature> = -1, all the objects are put into the list.", py::arg("aListOfIO"), py::arg("WhichKind"), py::arg("WhichSignature"));
	cls_AIS_InteractiveContext.def("RebuildSelectionStructs", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::RebuildSelectionStructs, "Rebuilds 1st level of BVH selection forcibly");
	cls_AIS_InteractiveContext.def("Disconnect", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.Disconnect(a0); }, py::arg("theAssembly"));
	cls_AIS_InteractiveContext.def("Disconnect", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::Disconnect, "Disconnects theObjToDisconnect from theAssembly and removes dependent selection structures", py::arg("theAssembly"), py::arg("theObjToDisconnect"));
	cls_AIS_InteractiveContext.def("ObjectsForView", [](AIS_InteractiveContext &self, AIS_ListOfInteractive & a0, const opencascade::handle<V3d_View> & a1, const Standard_Boolean a2) -> void { return self.ObjectsForView(a0, a1, a2); }, py::arg("theListOfIO"), py::arg("theView"), py::arg("theIsVisibleInView"));
	cls_AIS_InteractiveContext.def("ObjectsForView", (void (AIS_InteractiveContext::*)(AIS_ListOfInteractive &, const opencascade::handle<V3d_View> &, const Standard_Boolean, const AIS_DisplayStatus) const ) &AIS_InteractiveContext::ObjectsForView, "Query objects visible or hidden in specified view due to affinity mask.", py::arg("theListOfIO"), py::arg("theView"), py::arg("theIsVisibleInView"), py::arg("theStatus"));
	cls_AIS_InteractiveContext.def("PurgeDisplay", (Standard_Integer (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::PurgeDisplay, "Clears all the structures which don't belong to objects displayed at neutral point only effective when no Local Context is opened... returns the number of removed structures from the viewers.");
	cls_AIS_InteractiveContext.def("DisplayActiveSensitive", (void (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &)) &AIS_InteractiveContext::DisplayActiveSensitive, "Visualization of sensitives - for debugging purposes!", py::arg("aView"));
	cls_AIS_InteractiveContext.def("ClearActiveSensitive", (void (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &)) &AIS_InteractiveContext::ClearActiveSensitive, "Clear visualization of sensitives.", py::arg("aView"));
	cls_AIS_InteractiveContext.def("DisplayActiveSensitive", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<V3d_View> &)) &AIS_InteractiveContext::DisplayActiveSensitive, "Visualization of sensitives - for debugging purposes!", py::arg("anObject"), py::arg("aView"));
	cls_AIS_InteractiveContext.def("SetLocalAttributes", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean)) &AIS_InteractiveContext::SetLocalAttributes, "Sets the graphic attributes of the interactive object, such as visualization mode, color, and material.", py::arg("theIObj"), py::arg("theDrawer"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("UnsetLocalAttributes", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetLocalAttributes, "Removes the settings for local attributes of the Object and returns to defaults.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetCurrentFacingModel", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.SetCurrentFacingModel(a0); }, py::arg("aniobj"));
	cls_AIS_InteractiveContext.def("SetCurrentFacingModel", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Aspect_TypeOfFacingModel)) &AIS_InteractiveContext::SetCurrentFacingModel, "change the current facing model apply on polygons for SetColor(), SetTransparency(), SetMaterial() methods default facing model is Aspect_TOFM_TWO_SIDE. This mean that attributes is applying both on the front and back face.", py::arg("aniobj"), py::arg("aModel"));
	cls_AIS_InteractiveContext.def("HasColor", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::HasColor, "Returns true if a view of the Interactive Object has color.", py::arg("aniobj"));
	cls_AIS_InteractiveContext.def("Color", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, Quantity_Color &) const ) &AIS_InteractiveContext::Color, "Returns the color of the Object in the interactive context.", py::arg("aniobj"), py::arg("acolor"));
	cls_AIS_InteractiveContext.def("SetColor", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Quantity_Color &, const Standard_Boolean)) &AIS_InteractiveContext::SetColor, "Sets the color of the selected entity.", py::arg("theIObj"), py::arg("theColor"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("UnsetColor", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetColor, "Removes the color selection for the selected entity.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("Width", (Standard_Real (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::Width, "Returns the width of the Interactive Object in the interactive context.", py::arg("aniobj"));
	cls_AIS_InteractiveContext.def("SetWidth", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetWidth, "Sets the width of the Object.", py::arg("theIObj"), py::arg("theValue"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("UnsetWidth", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetWidth, "Removes the width setting of the Object.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetMaterial", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Graphic3d_MaterialAspect &, const Standard_Boolean)) &AIS_InteractiveContext::SetMaterial, "Provides the type of material setting for the view of the Object.", py::arg("theIObj"), py::arg("theMaterial"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("UnsetMaterial", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetMaterial, "Removes the type of material setting for viewing the Object.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetTransparency", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetTransparency, "Provides the transparency settings for viewing the Object. The transparency value aValue may be between 0.0, opaque, and 1.0, fully transparent.", py::arg("theIObj"), py::arg("theValue"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("UnsetTransparency", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetTransparency, "Removes the transparency settings for viewing the Object.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetPolygonOffsets", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_ShortReal, const Standard_ShortReal, const Standard_Boolean)) &AIS_InteractiveContext::SetPolygonOffsets, "Sets up polygon offsets for the given AIS_InteractiveObject. It simply calls AIS_InteractiveObject::SetPolygonOffsets().", py::arg("theIObj"), py::arg("theMode"), py::arg("theFactor"), py::arg("theUnits"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("HasPolygonOffsets", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::HasPolygonOffsets, "Simply calls AIS_InteractiveObject::HasPolygonOffsets().", py::arg("anObj"));
	cls_AIS_InteractiveContext.def("PolygonOffsets", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & anObj, Standard_Integer & aMode, Standard_ShortReal & aFactor, Standard_ShortReal & aUnits){ self.PolygonOffsets(anObj, aMode, aFactor, aUnits); return aMode; }, "Retrieves current polygon offsets settings for Object.", py::arg("anObj"), py::arg("aMode"), py::arg("aFactor"), py::arg("aUnits"));
	cls_AIS_InteractiveContext.def("SetTrihedronSize", (void (AIS_InteractiveContext::*)(const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetTrihedronSize, "Sets the size aSize of the trihedron. Is used to change the default value 100 mm for display of trihedra. Use of this function in one of your own interactive objects requires a call to the Compute function of the new class. This will recalculate the presentation for every trihedron displayed.", py::arg("theSize"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("TrihedronSize", (Standard_Real (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::TrihedronSize, "returns the current value of trihedron size.");
	cls_AIS_InteractiveContext.def("SetPlaneSize", (void (AIS_InteractiveContext::*)(const Standard_Real, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetPlaneSize, "Sets the plane size defined by the length in the X direction XSize and that in the Y direction YSize.", py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetPlaneSize", (void (AIS_InteractiveContext::*)(const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetPlaneSize, "Sets the plane size aSize.", py::arg("theSize"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("PlaneSize", [](AIS_InteractiveContext &self, Standard_Real & XSize, Standard_Real & YSize){ Standard_Boolean rv = self.PlaneSize(XSize, YSize); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, XSize, YSize); }, "Returns true if the length in the X direction XSize is the same as that in the Y direction YSize.", py::arg("XSize"), py::arg("YSize"));
	cls_AIS_InteractiveContext.def("SetDeviationCoefficient", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetDeviationCoefficient, "Sets the deviation coefficient theCoefficient. Drawings of curves or patches are made with respect to a maximal chordal deviation. A Deviation coefficient is used in the shading display mode. The shape is seen decomposed into triangles. These are used to calculate reflection of light from the surface of the object. The triangles are formed from chords of the curves in the shape. The deviation coefficient theCoefficient gives the highest value of the angle with which a chord can deviate from a tangent to a curve. If this limit is reached, a new triangle is begun. This deviation is absolute and is set through the method: SetMaximalChordialDeviation. The default value is 0.001. In drawing shapes, however, you are allowed to ask for a relative deviation. This deviation will be: SizeOfObject * DeviationCoefficient.", py::arg("theIObj"), py::arg("theCoefficient"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetDeviationAngle", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetDeviationAngle, "None", py::arg("theIObj"), py::arg("theAngle"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetAngleAndDeviation", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetAngleAndDeviation, "Calls the AIS_Shape SetAngleAndDeviation to set both Angle and Deviation coefficients", py::arg("theIObj"), py::arg("theAngle"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetHLRDeviationCoefficient", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetHLRDeviationCoefficient, "Sets the deviation coefficient aCoefficient for removal of hidden lines created by different viewpoints in different presentations. The Default value is 0.02.", py::arg("theIObj"), py::arg("theCoefficient"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetHLRDeviationAngle", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetHLRDeviationAngle, "None", py::arg("theIObj"), py::arg("theAngle"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetHLRAngleAndDeviation", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetHLRAngleAndDeviation, "Computes a HLRAngle and a HLRDeviationCoefficient by means of the angle anAngle and sets the corresponding methods in the default drawing tool with these values.", py::arg("theIObj"), py::arg("theAngle"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SetDeviationCoefficient", (void (AIS_InteractiveContext::*)(const Standard_Real)) &AIS_InteractiveContext::SetDeviationCoefficient, "Sets the deviation coefficient theCoefficient. Drawings of curves or patches are made with respect to a maximal chordal deviation. A Deviation coefficient is used in the shading display mode. The shape is seen decomposed into triangles. These are used to calculate reflection of light from the surface of the object. The triangles are formed from chords of the curves in the shape. The deviation coefficient theCoefficient gives the highest value of the angle with which a chord can deviate from a tangent to a curve. If this limit is reached, a new triangle is begun. This deviation is absolute and is set through the method: SetMaximalChordialDeviation. The default value is 0.001. In drawing shapes, however, you are allowed to ask for a relative deviation. This deviation will be: SizeOfObject * DeviationCoefficient.", py::arg("theCoefficient"));
	cls_AIS_InteractiveContext.def("DeviationCoefficient", (Standard_Real (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DeviationCoefficient, "Returns the deviation coefficient. Drawings of curves or patches are made with respect to a maximal chordal deviation. A Deviation coefficient is used in the shading display mode. The shape is seen decomposed into triangles. These are used to calculate reflection of light from the surface of the object. The triangles are formed from chords of the curves in the shape. The deviation coefficient gives the highest value of the angle with which a chord can deviate from a tangent to a curve. If this limit is reached, a new triangle is begun. This deviation is absolute and is set through Prs3d_Drawer::SetMaximalChordialDeviation. The default value is 0.001. In drawing shapes, however, you are allowed to ask for a relative deviation. This deviation will be: SizeOfObject * DeviationCoefficient.");
	cls_AIS_InteractiveContext.def("SetDeviationAngle", (void (AIS_InteractiveContext::*)(const Standard_Real)) &AIS_InteractiveContext::SetDeviationAngle, "default 12 degrees", py::arg("anAngle"));
	cls_AIS_InteractiveContext.def("DeviationAngle", (Standard_Real (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DeviationAngle, "None");
	cls_AIS_InteractiveContext.def("SetHLRDeviationCoefficient", (void (AIS_InteractiveContext::*)(const Standard_Real)) &AIS_InteractiveContext::SetHLRDeviationCoefficient, "Sets the deviation coefficient aCoefficient for removal of hidden lines created by different viewpoints in different presentations. The Default value is 0.02.", py::arg("aCoefficient"));
	cls_AIS_InteractiveContext.def("HLRDeviationCoefficient", (Standard_Real (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::HLRDeviationCoefficient, "Returns the real number value of the hidden line removal deviation coefficient. A Deviation coefficient is used in the shading display mode. The shape is seen decomposed into triangles. These are used to calculate reflection of light from the surface of the object. The triangles are formed from chords of the curves in the shape. The deviation coefficient give the highest value of the angle with which a chord can deviate from a tangent to a curve. If this limit is reached, a new triangle is begun. To find the hidden lines, hidden line display mode entails recalculation of the view at each different projector perspective. Because hidden lines entail calculations of more than usual complexity to decompose them into these triangles, a deviation coefficient allowing greater tolerance is used. This increases efficiency in calculation. The Default value is 0.02.");
	cls_AIS_InteractiveContext.def("SetHLRAngle", (void (AIS_InteractiveContext::*)(const Standard_Real)) &AIS_InteractiveContext::SetHLRAngle, "Sets the HLR angle.", py::arg("theAngle"));
	cls_AIS_InteractiveContext.def("HLRAngle", (Standard_Real (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::HLRAngle, "Returns the real number value of the deviation angle in hidden line removal views in this interactive context. The default value is 20*PI/180.");
	cls_AIS_InteractiveContext.def("SetHLRAngleAndDeviation", (void (AIS_InteractiveContext::*)(const Standard_Real)) &AIS_InteractiveContext::SetHLRAngleAndDeviation, "compute with theAngle a HLRAngle and a HLRDeviationCoefficient and set them in myHLRAngle and in myHLRDeviationCoefficient of myDefaultDrawer; theAngle is in radian; ( 1 deg < angle in deg < 20 deg)", py::arg("theAngle"));
	cls_AIS_InteractiveContext.def("HiddenLineAspect", (opencascade::handle<Prs3d_LineAspect> (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::HiddenLineAspect, "Initializes hidden line aspect in the default drawing tool, or Drawer. The default values are: Color: Quantity_NOC_YELLOW Type of line: Aspect_TOL_DASH Width: 1.");
	cls_AIS_InteractiveContext.def("SetHiddenLineAspect", (void (AIS_InteractiveContext::*)(const opencascade::handle<Prs3d_LineAspect> &) const ) &AIS_InteractiveContext::SetHiddenLineAspect, "Sets the hidden line aspect anAspect. Aspect defines display attributes for hidden lines in HLR projections.", py::arg("anAspect"));
	cls_AIS_InteractiveContext.def("DrawHiddenLine", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DrawHiddenLine, "returns Standard_True if the hidden lines are to be drawn. By default the hidden lines are not drawn.");
	cls_AIS_InteractiveContext.def("EnableDrawHiddenLine", (void (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::EnableDrawHiddenLine, "None");
	cls_AIS_InteractiveContext.def("DisableDrawHiddenLine", (void (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DisableDrawHiddenLine, "None");
	cls_AIS_InteractiveContext.def("SetIsoNumber", [](AIS_InteractiveContext &self, const Standard_Integer a0) -> void { return self.SetIsoNumber(a0); }, py::arg("NbIsos"));
	cls_AIS_InteractiveContext.def("SetIsoNumber", (void (AIS_InteractiveContext::*)(const Standard_Integer, const AIS_TypeOfIso)) &AIS_InteractiveContext::SetIsoNumber, "Sets the number of U and V isoparameters displayed.", py::arg("NbIsos"), py::arg("WhichIsos"));
	cls_AIS_InteractiveContext.def("IsoNumber", [](AIS_InteractiveContext &self) -> Standard_Integer { return self.IsoNumber(); });
	cls_AIS_InteractiveContext.def("IsoNumber", (Standard_Integer (AIS_InteractiveContext::*)(const AIS_TypeOfIso)) &AIS_InteractiveContext::IsoNumber, "Returns the number of U and V isoparameters displayed.", py::arg("WhichIsos"));
	cls_AIS_InteractiveContext.def("IsoOnPlane", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::IsoOnPlane, "Returns True if drawing isoparameters on planes is enabled.", py::arg("SwitchOn"));
	cls_AIS_InteractiveContext.def("IsoOnPlane", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::IsoOnPlane, "Returns True if drawing isoparameters on planes is enabled. if <forUIsos> = False,");
	cls_AIS_InteractiveContext.def("IsoOnTriangulation", (void (AIS_InteractiveContext::*)(const Standard_Boolean, const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::IsoOnTriangulation, "Enables or disables on-triangulation build for isolines for a particular object. In case if on-triangulation builder is disabled, default on-plane builder will compute isolines for the object given.", py::arg("theIsEnabled"), py::arg("theObject"));
	cls_AIS_InteractiveContext.def("IsoOnTriangulation", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::IsoOnTriangulation, "Enables or disables on-triangulation build for isolines for default drawer. In case if on-triangulation builder is disabled, default on-plane builder will compute isolines for the object given.", py::arg("theToSwitchOn"));
	cls_AIS_InteractiveContext.def("IsoOnTriangulation", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::IsoOnTriangulation, "Returns true if drawing isolines on triangulation algorithm is enabled.");
	cls_AIS_InteractiveContext.def("HasOpenedContext", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::HasOpenedContext, "Returns true if there is an open context.");
	cls_AIS_InteractiveContext.def("HighestIndex", (Standard_Integer (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::HighestIndex, "None");
	cls_AIS_InteractiveContext.def("LocalContext", (opencascade::handle<AIS_LocalContext> (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::LocalContext, "For advanced usage! You should use other (non-internal) methods of class AIS_InteractiveContext without trying to obtain an instance of AIS_LocalContext.");
	cls_AIS_InteractiveContext.def("LocalSelector", (opencascade::handle<StdSelect_ViewerSelector3d> (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::LocalSelector, "None");
	cls_AIS_InteractiveContext.def("OpenLocalContext", [](AIS_InteractiveContext &self) -> Standard_Integer { return self.OpenLocalContext(); });
	cls_AIS_InteractiveContext.def("OpenLocalContext", [](AIS_InteractiveContext &self, const Standard_Boolean a0) -> Standard_Integer { return self.OpenLocalContext(a0); }, py::arg("UseDisplayedObjects"));
	cls_AIS_InteractiveContext.def("OpenLocalContext", [](AIS_InteractiveContext &self, const Standard_Boolean a0, const Standard_Boolean a1) -> Standard_Integer { return self.OpenLocalContext(a0, a1); }, py::arg("UseDisplayedObjects"), py::arg("AllowShapeDecomposition"));
	cls_AIS_InteractiveContext.def("OpenLocalContext", [](AIS_InteractiveContext &self, const Standard_Boolean a0, const Standard_Boolean a1, const Standard_Boolean a2) -> Standard_Integer { return self.OpenLocalContext(a0, a1, a2); }, py::arg("UseDisplayedObjects"), py::arg("AllowShapeDecomposition"), py::arg("AcceptEraseOfObjects"));
	cls_AIS_InteractiveContext.def("OpenLocalContext", (Standard_Integer (AIS_InteractiveContext::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &AIS_InteractiveContext::OpenLocalContext, "Opens local contexts and specifies how this is to be done. The options listed above function in the following manner: - UseDisplayedObjects - allows you to load or not load the interactive objects visualized at Neutral Point in the local context which you open. If false, the local context is empty after being opened. If true, the objects at Neutral Point are loaded by their default selection mode. - AllowShapeDecomposition - AIS_Shape allows or prevents decomposition in standard shape location mode of objects at Neutral Point which are type-'privileged'. This Flag is only taken into account when UseDisplayedObjects is true. - AcceptEraseOfObjects - authorises other local contexts to erase the interactive objects present in this context. This option is rarely used. - BothViewers - Has no use currently defined. This method returns the index of the created local context. It should be kept and used to close the context. Opening a local context allows you to prepare an environment for temporary presentations and selections which will disappear once the local context is closed. You can open several local contexts, but only the last one will be active.", py::arg("UseDisplayedObjects"), py::arg("AllowShapeDecomposition"), py::arg("AcceptEraseOfObjects"), py::arg("BothViewers"));
	cls_AIS_InteractiveContext.def("CloseLocalContext", [](AIS_InteractiveContext &self) -> void { return self.CloseLocalContext(); });
	cls_AIS_InteractiveContext.def("CloseLocalContext", [](AIS_InteractiveContext &self, const Standard_Integer a0) -> void { return self.CloseLocalContext(a0); }, py::arg("theIndex"));
	cls_AIS_InteractiveContext.def("CloseLocalContext", (void (AIS_InteractiveContext::*)(const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::CloseLocalContext, "Allows you to close local contexts. For greater security, you should close the context with the index Index given on opening. When you close a local context, the one before, which is still on the stack, reactivates. If none is left, you return to Neutral Point. If a local context is open and if updateviewer equals Standard_False, the presentation of the Interactive Object activates the selection mode; the object is displayed but no viewer will be updated. Warning When the index isn't specified, the current context is closed. This option can be dangerous, as other Interactive Functions can open local contexts without necessarily warning the user.", py::arg("theIndex"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("IndexOfCurrentLocal", (Standard_Integer (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::IndexOfCurrentLocal, "returns -1 if no opened local context.");
	cls_AIS_InteractiveContext.def("CloseAllContexts", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::CloseAllContexts, "Allows you to close all local contexts at one go and return to Neutral Point. If a local context is open and if updateviewer equals Standard_False, the presentation of the Interactive Object activates the selection mode; the object is displayed but no viewer will be updated.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("ResetOriginalState", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::ResetOriginalState, "to be used only with no opened local context.. displays and activates objects in their original state before local contexts were opened...", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("ClearLocalContext", [](AIS_InteractiveContext &self) -> void { return self.ClearLocalContext(); });
	cls_AIS_InteractiveContext.def("ClearLocalContext", (void (AIS_InteractiveContext::*)(const AIS_ClearMode)) &AIS_InteractiveContext::ClearLocalContext, "clears Objects/Filters/Activated Modes list in the current opened local context.", py::arg("TheMode"));
	cls_AIS_InteractiveContext.def("UseDisplayedObjects", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::UseDisplayedObjects, "None");
	cls_AIS_InteractiveContext.def("NotUseDisplayedObjects", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::NotUseDisplayedObjects, "when a local Context is opened, one is able to use/not use the displayed objects at neutral point at anytime.");
	cls_AIS_InteractiveContext.def("SetShapeDecomposition", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::SetShapeDecomposition, "to be Used only with opened local context and if <anIobj> is of type shape... if <aStatus> = True <anIobj> will be sensitive to shape selection modes activation. = False, <anIobj> will not be sensitive any more.", py::arg("anIobj"), py::arg("aStatus"));
	cls_AIS_InteractiveContext.def("SetTemporaryAttributes", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean)) &AIS_InteractiveContext::SetTemporaryAttributes, "Sets the temporary graphic attributes of the entity anObj. These are provided by the attribute manager aDrawer and are valid for a particular local context only. If a local context is open and if updateviewer equals Standard_False, the presentation of the Interactive Object activates the selection mode; the object is displayed but no viewer will be updated.", py::arg("theIObj"), py::arg("theDrawer"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("ActivateStandardMode", (void (AIS_InteractiveContext::*)(const TopAbs_ShapeEnum)) &AIS_InteractiveContext::ActivateStandardMode, "Provides an alternative to the Display methods when activating specific selection modes. This has the effect of activating the corresponding selection mode aStandardActivation for all objects in Local Context which accept decomposition into sub-shapes. Every new Object which has been loaded into the interactive context and which answers these decomposition criteria is automatically activated according to these modes. Warning If you have opened a local context by loading an object with the default options (<AllowShapeDecomposition >= Standard_True), all objects of the 'Shape' type are also activated with the same modes. You can act on the state of these 'Standard' objects by using SetShapeDecomposition(Status).", py::arg("aStandardActivation"));
	cls_AIS_InteractiveContext.def("DeactivateStandardMode", (void (AIS_InteractiveContext::*)(const TopAbs_ShapeEnum)) &AIS_InteractiveContext::DeactivateStandardMode, "Provides an alternative to the Display methods when deactivating specific selection modes. This has the effect of deactivating the corresponding selection mode aStandardActivation for all objects in Local Context which accept decomposition into sub-shapes.", py::arg("aStandardActivation"));
	cls_AIS_InteractiveContext.def("ActivatedStandardModes", (const TColStd_ListOfInteger & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::ActivatedStandardModes, "Returns the list of activated standard selection modes available in a local context.");
	cls_AIS_InteractiveContext.def("IsInLocal", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & anObject, Standard_Integer & TheIndex){ Standard_Boolean rv = self.IsInLocal(anObject, TheIndex); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, TheIndex); }, "returns if possible, the first local context where the object is seen", py::arg("anObject"), py::arg("TheIndex"));
	cls_AIS_InteractiveContext.def("SetAutomaticHilight", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::SetAutomaticHilight, "Sets the highlighting status aStatus of detected and selected entities. Whether you are in Neutral Point or local context, this is automatically managed by the Interactive Context. This function allows you to disconnect the automatic mode.", py::arg("aStatus"));
	cls_AIS_InteractiveContext.def("AutomaticHilight", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::AutomaticHilight, "Returns true if the automatic highlight mode is active in an open context.");
	cls_AIS_InteractiveContext.def("KeepTemporary", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> Standard_Boolean { return self.KeepTemporary(a0); }, py::arg("anIObj"));
	cls_AIS_InteractiveContext.def("KeepTemporary", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_InteractiveContext::KeepTemporary, "Changes the status of a temporary object. It will be kept at the neutral point, i.e. put in the list of displayed objects along with its temporary attributes. These include display mode and selection mode, for example. Returns true if done. inWhichLocal gives the local context in which anIObj is displayed. By default, the index -1 refers to the last Local Context opened.", py::arg("anIObj"), py::arg("InWhichLocal"));
	cls_AIS_InteractiveContext.def("SetCurrentObject", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::SetCurrentObject, "Updates the view of the current object in open context. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("AddOrRemoveCurrentObject", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::AddOrRemoveCurrentObject, "Allows to add or remove the object given to the list of current and highlight/unhighlight it correspondingly. Is valid for global context only; for local context use method AddOrRemoveSelected. Since this method makes sence only for neutral point selection of a whole object, if 0 selection of the object is empty this method simply does nothing.", py::arg("theObj"), py::arg("theIsToUpdateViewer"));
	cls_AIS_InteractiveContext.def("UpdateCurrent", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::UpdateCurrent, "Updates the list of current objects, i.e. hilights new current objects, removes hilighting from former current objects. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.");
	cls_AIS_InteractiveContext.def("IsCurrent", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_InteractiveContext::IsCurrent, "Returns true if there is a non-null interactive object in Neutral Point. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.", py::arg("theObject"));
	cls_AIS_InteractiveContext.def("InitCurrent", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::InitCurrent, "Initializes a scan of the current selected objects in Neutral Point. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.");
	cls_AIS_InteractiveContext.def("MoreCurrent", (Standard_Boolean (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::MoreCurrent, "Returns true if there is another object found by the scan of the list of current objects. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.");
	cls_AIS_InteractiveContext.def("NextCurrent", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::NextCurrent, "Continues the scan to the next object in the list of current objects. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.");
	cls_AIS_InteractiveContext.def("Current", (opencascade::handle<AIS_InteractiveObject> (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::Current, "Returns the current interactive object. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.");
	cls_AIS_InteractiveContext.def("NbCurrents", (Standard_Integer (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::NbCurrents, "None");
	cls_AIS_InteractiveContext.def("HilightCurrents", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::HilightCurrents, "Highlights current objects. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("UnhilightCurrents", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::UnhilightCurrents, "Removes highlighting from current objects. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("ClearCurrents", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::ClearCurrents, "Empties previous current objects in order to get the current objects detected by the selector using UpdateCurrent. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("DetectedCurrentShape", (const TopoDS_Shape & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DetectedCurrentShape, "Returns current mouse-detected shape or empty (null) shape, if current interactive object is not a shape (AIS_Shape) or there is no current mouse-detected interactive object at all. DetectedCurrentOwner()/InitDetected()/MoreDetected()/NextDetected().");
	cls_AIS_InteractiveContext.def("DetectedCurrentObject", (opencascade::handle<AIS_InteractiveObject> (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::DetectedCurrentObject, "Returns current mouse-detected interactive object or null object, if there is no currently detected interactives DetectedCurrentOwner()/InitDetected()/MoreDetected()/NextDetected().");
	cls_AIS_InteractiveContext.def("SubIntensityColor", (const Quantity_Color & (AIS_InteractiveContext::*)() const ) &AIS_InteractiveContext::SubIntensityColor, "Sub-intensity allows temporary highlighting of particular objects with specified color in a manner of selection highlight, but without actual selection (e.g., global status and owner's selection state will not be updated). The method returns the color of such highlighting. By default, it is Quantity_NOC_GRAY40.");
	cls_AIS_InteractiveContext.def("SetSubIntensityColor", (void (AIS_InteractiveContext::*)(const Quantity_Color &)) &AIS_InteractiveContext::SetSubIntensityColor, "Sub-intensity allows temporary highlighting of particular objects with specified color in a manner of selection highlight, but without actual selection (e.g., global status and owner's selection state will not be updated). The method sets up the color for such highlighting. By default, this is Quantity_NOC_GRAY40.", py::arg("theColor"));
	cls_AIS_InteractiveContext.def("SubIntensityOn", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::SubIntensityOn, "Highlights, and removes highlights from, the displayed object which is displayed at Neutral Point with subintensity color. Available only for active local context. There is no effect if there is no local context. If a local context is open, the presentation of the Interactive Object activates the selection mode.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SubIntensityOff", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::SubIntensityOff, "Removes the subintensity option for the entity. If a local context is open, the presentation of the Interactive Object activates the selection mode.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SubIntensityOn", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::SubIntensityOn, "hilights/unhilights displayed objects which are displayed at neutral state with subintensity color. Available only for active local context. No effect if no local context.", py::arg("theToUpdateViewer"));
	cls_AIS_InteractiveContext.def("SubIntensityOff", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::SubIntensityOff, "Removes subintensity option for all objects.", py::arg("theToUpdateViewer"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_GraphicTool.hxx
	py::class_<AIS_GraphicTool, std::unique_ptr<AIS_GraphicTool, Deleter<AIS_GraphicTool>>> cls_AIS_GraphicTool(mod, "AIS_GraphicTool", "None");
	cls_AIS_GraphicTool.def(py::init<>());
	cls_AIS_GraphicTool.def_static("GetLineColor_", (Quantity_NameOfColor (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute)) &AIS_GraphicTool::GetLineColor, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"));
	cls_AIS_GraphicTool.def_static("GetLineColor_", (void (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute, Quantity_Color &)) &AIS_GraphicTool::GetLineColor, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"), py::arg("TheLineColor"));
	cls_AIS_GraphicTool.def_static("GetLineWidth_", (Standard_Real (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute)) &AIS_GraphicTool::GetLineWidth, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"));
	cls_AIS_GraphicTool.def_static("GetLineType_", (Aspect_TypeOfLine (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute)) &AIS_GraphicTool::GetLineType, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"));
	cls_AIS_GraphicTool.def_static("GetLineAtt_", [](const opencascade::handle<Prs3d_Drawer> & aDrawer, const AIS_TypeOfAttribute TheTypeOfAttributes, Quantity_NameOfColor & aCol, Standard_Real & aWidth, Aspect_TypeOfLine & aTyp){ AIS_GraphicTool::GetLineAtt(aDrawer, TheTypeOfAttributes, aCol, aWidth, aTyp); return aWidth; }, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"), py::arg("aCol"), py::arg("aWidth"), py::arg("aTyp"));
	cls_AIS_GraphicTool.def_static("GetInteriorColor_", (Quantity_NameOfColor (*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_GraphicTool::GetInteriorColor, "None", py::arg("aDrawer"));
	cls_AIS_GraphicTool.def_static("GetInteriorColor_", (void (*)(const opencascade::handle<Prs3d_Drawer> &, Quantity_Color &)) &AIS_GraphicTool::GetInteriorColor, "None", py::arg("aDrawer"), py::arg("aColor"));
	cls_AIS_GraphicTool.def_static("GetMaterial_", (Graphic3d_MaterialAspect (*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_GraphicTool::GetMaterial, "None", py::arg("aDrawer"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_LocalContext.hxx
	py::class_<AIS_LocalContext, opencascade::handle<AIS_LocalContext>, Standard_Transient> cls_AIS_LocalContext(mod, "AIS_LocalContext", "Defines a specific context for selection. It becomes possible to: + Load InteractiveObjects with a mode to be activated + associate InteractiveObjects with a set of temporary selectable Objects.... + + activate StandardMode of selection for Entities inheriting BasicShape from AIS (Selection Of vertices, edges, wires,faces... + Add Filters acting on detected owners of sensitive primitives");
	cls_AIS_LocalContext.def(py::init<>());
	cls_AIS_LocalContext.def(py::init<const opencascade::handle<AIS_InteractiveContext> &, const Standard_Integer>(), py::arg("aCtx"), py::arg("anIndex"));
	cls_AIS_LocalContext.def(py::init<const opencascade::handle<AIS_InteractiveContext> &, const Standard_Integer, const Standard_Boolean>(), py::arg("aCtx"), py::arg("anIndex"), py::arg("LoadDisplayed"));
	cls_AIS_LocalContext.def(py::init<const opencascade::handle<AIS_InteractiveContext> &, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("aCtx"), py::arg("anIndex"), py::arg("LoadDisplayed"), py::arg("AcceptStandardModes"));
	cls_AIS_LocalContext.def(py::init<const opencascade::handle<AIS_InteractiveContext> &, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("aCtx"), py::arg("anIndex"), py::arg("LoadDisplayed"), py::arg("AcceptStandardModes"), py::arg("AcceptErase"));
	cls_AIS_LocalContext.def(py::init<const opencascade::handle<AIS_InteractiveContext> &, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("aCtx"), py::arg("anIndex"), py::arg("LoadDisplayed"), py::arg("AcceptStandardModes"), py::arg("AcceptErase"), py::arg("UseBothViewers"));
	cls_AIS_LocalContext.def("AcceptErase", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::AcceptErase, "authorize or not others contexts to erase temporary displayed objects here;", py::arg("aStatus"));
	cls_AIS_LocalContext.def("AcceptErase", (Standard_Boolean (AIS_LocalContext::*)() const ) &AIS_LocalContext::AcceptErase, "None");
	cls_AIS_LocalContext.def("SetContext", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveContext> &)) &AIS_LocalContext::SetContext, "None", py::arg("aCtx"));
	cls_AIS_LocalContext.def("Selection", (const opencascade::handle<AIS_Selection> (AIS_LocalContext::*)() const ) &AIS_LocalContext::Selection, "None");
	cls_AIS_LocalContext.def("Terminate", [](AIS_LocalContext &self) -> void { return self.Terminate(); });
	cls_AIS_LocalContext.def("Terminate", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::Terminate, "None", py::arg("updateviewer"));
	cls_AIS_LocalContext.def("Display", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> Standard_Boolean { return self.Display(a0); }, py::arg("anInteractive"));
	cls_AIS_LocalContext.def("Display", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1) -> Standard_Boolean { return self.Display(a0, a1); }, py::arg("anInteractive"), py::arg("DisplayMode"));
	cls_AIS_LocalContext.def("Display", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1, const Standard_Boolean a2) -> Standard_Boolean { return self.Display(a0, a1, a2); }, py::arg("anInteractive"), py::arg("DisplayMode"), py::arg("AllowShapeDecomposition"));
	cls_AIS_LocalContext.def("Display", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Boolean, const Standard_Integer)) &AIS_LocalContext::Display, "returns true if done...", py::arg("anInteractive"), py::arg("DisplayMode"), py::arg("AllowShapeDecomposition"), py::arg("ActivationMode"));
	cls_AIS_LocalContext.def("Load", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> Standard_Boolean { return self.Load(a0); }, py::arg("anInteractive"));
	cls_AIS_LocalContext.def("Load", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.Load(a0, a1); }, py::arg("anInteractive"), py::arg("AllowShapeDecomposition"));
	cls_AIS_LocalContext.def("Load", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean, const Standard_Integer)) &AIS_LocalContext::Load, "loads <anInteractive> with nodisplay... returns true if done", py::arg("anInteractive"), py::arg("AllowShapeDecomposition"), py::arg("ActivationMode"));
	cls_AIS_LocalContext.def("Erase", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::Erase, "returns true if done...", py::arg("anInteractive"));
	cls_AIS_LocalContext.def("Remove", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::Remove, "None", py::arg("aSelectable"));
	cls_AIS_LocalContext.def("ClearPrs", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_LocalContext::ClearPrs, "None", py::arg("anInteractive"), py::arg("aMode"));
	cls_AIS_LocalContext.def("SetShapeDecomposition", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_LocalContext::SetShapeDecomposition, "allows or forbids the shape decomposition into Activated Standard Mode for <aStoredObject> does nothing if the object doesn't inherits BasicShape from AIS", py::arg("aStoredObject"), py::arg("aStatus"));
	cls_AIS_LocalContext.def("Clear", [](AIS_LocalContext &self) -> void { return self.Clear(); });
	cls_AIS_LocalContext.def("Clear", (void (AIS_LocalContext::*)(const AIS_ClearMode)) &AIS_LocalContext::Clear, "according to <atype> , clears the different parts of the selector (filters, modeof activation, objects...)", py::arg("atype"));
	cls_AIS_LocalContext.def("ActivateMode", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_LocalContext::ActivateMode, "optional : activation of a mode which is not 0 for a selectable...", py::arg("aSelectable"), py::arg("aMode"));
	cls_AIS_LocalContext.def("DeactivateMode", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_LocalContext::DeactivateMode, "None", py::arg("aSelectable"), py::arg("aMode"));
	cls_AIS_LocalContext.def("Deactivate", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::Deactivate, "None", py::arg("aSelectable"));
	cls_AIS_LocalContext.def("ActivateStandardMode", (void (AIS_LocalContext::*)(const TopAbs_ShapeEnum)) &AIS_LocalContext::ActivateStandardMode, "decomposition of shapes into <aType>", py::arg("aType"));
	cls_AIS_LocalContext.def("DeactivateStandardMode", (void (AIS_LocalContext::*)(const TopAbs_ShapeEnum)) &AIS_LocalContext::DeactivateStandardMode, "None", py::arg("aType"));
	cls_AIS_LocalContext.def("StandardModes", (const TColStd_ListOfInteger & (AIS_LocalContext::*)() const ) &AIS_LocalContext::StandardModes, "None");
	cls_AIS_LocalContext.def("AddFilter", (void (AIS_LocalContext::*)(const opencascade::handle<SelectMgr_Filter> &)) &AIS_LocalContext::AddFilter, "None", py::arg("aFilter"));
	cls_AIS_LocalContext.def("RemoveFilter", (void (AIS_LocalContext::*)(const opencascade::handle<SelectMgr_Filter> &)) &AIS_LocalContext::RemoveFilter, "None", py::arg("aFilter"));
	cls_AIS_LocalContext.def("ListOfFilter", (const SelectMgr_ListOfFilter & (AIS_LocalContext::*)() const ) &AIS_LocalContext::ListOfFilter, "None");
	cls_AIS_LocalContext.def("Filter", (const opencascade::handle<SelectMgr_OrFilter> & (AIS_LocalContext::*)() const ) &AIS_LocalContext::Filter, "None");
	cls_AIS_LocalContext.def("SetAutomaticHilight", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::SetAutomaticHilight, "if <aStatus> = True , the shapes or subshapes detected by the selector will be automatically hilighted in the main viewer. Else the user has to manage the detected shape outside the Shape Selector....", py::arg("aStatus"));
	cls_AIS_LocalContext.def("AutomaticHilight", (Standard_Boolean (AIS_LocalContext::*)() const ) &AIS_LocalContext::AutomaticHilight, "None");
	cls_AIS_LocalContext.def("MoveTo", (AIS_StatusOfDetection (AIS_LocalContext::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::MoveTo, "None", py::arg("theXpix"), py::arg("theYpix"), py::arg("theView"), py::arg("theToRedrawImmediate"));
	cls_AIS_LocalContext.def("HasNextDetected", (Standard_Boolean (AIS_LocalContext::*)() const ) &AIS_LocalContext::HasNextDetected, "returns True if more than one entity was detected at the last Mouse position.");
	cls_AIS_LocalContext.def("HilightNextDetected", (Standard_Integer (AIS_LocalContext::*)(const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::HilightNextDetected, "returns True if last detected. the next detected will be first one (endless loop)", py::arg("theView"), py::arg("theToRedrawImmediate"));
	cls_AIS_LocalContext.def("HilightPreviousDetected", (Standard_Integer (AIS_LocalContext::*)(const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::HilightPreviousDetected, "None", py::arg("theView"), py::arg("theToRedrawImmediate"));
	cls_AIS_LocalContext.def("UnhilightLastDetected", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<V3d_Viewer> &)) &AIS_LocalContext::UnhilightLastDetected, "returns True if something was done...", py::arg("theViewer"));
	cls_AIS_LocalContext.def("UnhilightLastDetected", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<V3d_View> &)) &AIS_LocalContext::UnhilightLastDetected, "returns True if something was done...", py::arg("theView"));
	cls_AIS_LocalContext.def("AddSelect", (AIS_StatusOfPick (AIS_LocalContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_LocalContext::AddSelect, "returns the number of selected", py::arg("theObject"));
	cls_AIS_LocalContext.def("Select", [](AIS_LocalContext &self) -> AIS_StatusOfPick { return self.Select(); });
	cls_AIS_LocalContext.def("Select", (AIS_StatusOfPick (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::Select, "None", py::arg("updateviewer"));
	cls_AIS_LocalContext.def("ShiftSelect", [](AIS_LocalContext &self) -> AIS_StatusOfPick { return self.ShiftSelect(); });
	cls_AIS_LocalContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::ShiftSelect, "None", py::arg("updateviewer"));
	cls_AIS_LocalContext.def("Select", [](AIS_LocalContext &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const opencascade::handle<V3d_View> & a4) -> AIS_StatusOfPick { return self.Select(a0, a1, a2, a3, a4); }, py::arg("XPMin"), py::arg("YPMin"), py::arg("XPMax"), py::arg("YPMax"), py::arg("aView"));
	cls_AIS_LocalContext.def("Select", (AIS_StatusOfPick (AIS_LocalContext::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::Select, "None", py::arg("XPMin"), py::arg("YPMin"), py::arg("XPMax"), py::arg("YPMax"), py::arg("aView"), py::arg("updateviewer"));
	cls_AIS_LocalContext.def("ShiftSelect", [](AIS_LocalContext &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const opencascade::handle<V3d_View> & a4) -> AIS_StatusOfPick { return self.ShiftSelect(a0, a1, a2, a3, a4); }, py::arg("XPMin"), py::arg("YPMin"), py::arg("XPMax"), py::arg("YPMax"), py::arg("aView"));
	cls_AIS_LocalContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_LocalContext::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::ShiftSelect, "None", py::arg("XPMin"), py::arg("YPMin"), py::arg("XPMax"), py::arg("YPMax"), py::arg("aView"), py::arg("updateviewer"));
	cls_AIS_LocalContext.def("Select", [](AIS_LocalContext &self, const TColgp_Array1OfPnt2d & a0, const opencascade::handle<V3d_View> & a1) -> AIS_StatusOfPick { return self.Select(a0, a1); }, py::arg("Polyline"), py::arg("aView"));
	cls_AIS_LocalContext.def("Select", (AIS_StatusOfPick (AIS_LocalContext::*)(const TColgp_Array1OfPnt2d &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::Select, "None", py::arg("Polyline"), py::arg("aView"), py::arg("updateviewer"));
	cls_AIS_LocalContext.def("ShiftSelect", [](AIS_LocalContext &self, const TColgp_Array1OfPnt2d & a0, const opencascade::handle<V3d_View> & a1) -> AIS_StatusOfPick { return self.ShiftSelect(a0, a1); }, py::arg("Polyline"), py::arg("aView"));
	cls_AIS_LocalContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_LocalContext::*)(const TColgp_Array1OfPnt2d &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::ShiftSelect, "None", py::arg("Polyline"), py::arg("aView"), py::arg("updateviewer"));
	cls_AIS_LocalContext.def("HilightPicked", [](AIS_LocalContext &self) -> void { return self.HilightPicked(); });
	cls_AIS_LocalContext.def("HilightPicked", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::HilightPicked, "None", py::arg("updateviewer"));
	cls_AIS_LocalContext.def("UnhilightPicked", [](AIS_LocalContext &self) -> void { return self.UnhilightPicked(); });
	cls_AIS_LocalContext.def("UnhilightPicked", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::UnhilightPicked, "None", py::arg("updateviewer"));
	cls_AIS_LocalContext.def("UpdateSelected", [](AIS_LocalContext &self) -> void { return self.UpdateSelected(); });
	cls_AIS_LocalContext.def("UpdateSelected", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::UpdateSelected, "None", py::arg("updateviewer"));
	cls_AIS_LocalContext.def("UpdateSelected", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.UpdateSelected(a0); }, py::arg("anobj"));
	cls_AIS_LocalContext.def("UpdateSelected", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_LocalContext::UpdateSelected, "Part of advanced selection highlighting mechanism. If no owners belonging to anobj are selected, calls anobj->ClearSelected(), otherwise calls anobj->HilightSelected(). This method can be used to avoid redrawing the whole selection belonging to several Selectable Objects.", py::arg("anobj"), py::arg("updateviewer"));
	cls_AIS_LocalContext.def("SetSelected", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.SetSelected(a0); }, py::arg("anobj"));
	cls_AIS_LocalContext.def("SetSelected", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_LocalContext::SetSelected, "useful to update selection with objects coming from Collector or stack", py::arg("anobj"), py::arg("updateviewer"));
	cls_AIS_LocalContext.def("AddOrRemoveSelected", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.AddOrRemoveSelected(a0); }, py::arg("anobj"));
	cls_AIS_LocalContext.def("AddOrRemoveSelected", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_LocalContext::AddOrRemoveSelected, "useful to update selection with objects coming from Collector or stack", py::arg("anobj"), py::arg("updateviewer"));
	cls_AIS_LocalContext.def("AddOrRemoveSelected", [](AIS_LocalContext &self, const TopoDS_Shape & a0) -> void { return self.AddOrRemoveSelected(a0); }, py::arg("aShape"));
	cls_AIS_LocalContext.def("AddOrRemoveSelected", (void (AIS_LocalContext::*)(const TopoDS_Shape &, const Standard_Boolean)) &AIS_LocalContext::AddOrRemoveSelected, "None", py::arg("aShape"), py::arg("updateviewer"));
	cls_AIS_LocalContext.def("AddOrRemoveSelected", [](AIS_LocalContext &self, const opencascade::handle<SelectMgr_EntityOwner> & a0) -> void { return self.AddOrRemoveSelected(a0); }, py::arg("theOwner"));
	cls_AIS_LocalContext.def("AddOrRemoveSelected", (void (AIS_LocalContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Boolean)) &AIS_LocalContext::AddOrRemoveSelected, "None", py::arg("theOwner"), py::arg("toUpdateViewer"));
	cls_AIS_LocalContext.def("ClearSelected", [](AIS_LocalContext &self) -> void { return self.ClearSelected(); });
	cls_AIS_LocalContext.def("ClearSelected", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::ClearSelected, "Clears local context selection.", py::arg("toUpdateViewer"));
	cls_AIS_LocalContext.def("ClearOutdatedSelection", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_LocalContext::ClearOutdatedSelection, "Clears outdated selection and detection of owners for the interactive object. Use this method if selection structures of the interactive object have changed. The method unhilights and removes outdated entity owners from lists of selected and detected owners.", py::arg("theIO"), py::arg("toClearDeactivated"));
	cls_AIS_LocalContext.def("HasDetected", (Standard_Boolean (AIS_LocalContext::*)() const ) &AIS_LocalContext::HasDetected, "None");
	cls_AIS_LocalContext.def("InitDetected", (void (AIS_LocalContext::*)()) &AIS_LocalContext::InitDetected, "Initialization for iteration through mouse-detected objects in local context.");
	cls_AIS_LocalContext.def("MoreDetected", (Standard_Boolean (AIS_LocalContext::*)() const ) &AIS_LocalContext::MoreDetected, "Returns true if there is more mouse-detected objects after the current one during iteration through mouse-detected interactive objects.");
	cls_AIS_LocalContext.def("NextDetected", (void (AIS_LocalContext::*)()) &AIS_LocalContext::NextDetected, "Gets next current object during iteration through mouse-detected interactive objects.");
	cls_AIS_LocalContext.def("DetectedCurrentOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_LocalContext::*)() const ) &AIS_LocalContext::DetectedCurrentOwner, "Returns current mouse-detected Owner or null object if there is no current detected.");
	cls_AIS_LocalContext.def("DetectedCurrentShape", (const TopoDS_Shape & (AIS_LocalContext::*)() const ) &AIS_LocalContext::DetectedCurrentShape, "Returns current mouse-detected shape or empty (null) shape, if current interactive object is not a shape (AIS_Shape) or there is no current mouse-detected interactive object at all.");
	cls_AIS_LocalContext.def("DetectedCurrentObject", (opencascade::handle<AIS_InteractiveObject> (AIS_LocalContext::*)() const ) &AIS_LocalContext::DetectedCurrentObject, "Returns current mouse-detected interactive object or null object if there is no current detected.");
	cls_AIS_LocalContext.def("HasDetectedShape", (Standard_Boolean (AIS_LocalContext::*)() const ) &AIS_LocalContext::HasDetectedShape, "None");
	cls_AIS_LocalContext.def("DetectedShape", (const TopoDS_Shape & (AIS_LocalContext::*)() const ) &AIS_LocalContext::DetectedShape, "None");
	cls_AIS_LocalContext.def("DetectedInteractive", (opencascade::handle<AIS_InteractiveObject> (AIS_LocalContext::*)() const ) &AIS_LocalContext::DetectedInteractive, "None");
	cls_AIS_LocalContext.def("DetectedOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_LocalContext::*)() const ) &AIS_LocalContext::DetectedOwner, "None");
	cls_AIS_LocalContext.def("InitSelected", (void (AIS_LocalContext::*)()) &AIS_LocalContext::InitSelected, "None");
	cls_AIS_LocalContext.def("MoreSelected", (Standard_Boolean (AIS_LocalContext::*)() const ) &AIS_LocalContext::MoreSelected, "None");
	cls_AIS_LocalContext.def("NextSelected", (void (AIS_LocalContext::*)()) &AIS_LocalContext::NextSelected, "None");
	cls_AIS_LocalContext.def("HasShape", (Standard_Boolean (AIS_LocalContext::*)() const ) &AIS_LocalContext::HasShape, "returns TRUE if the detected entity is a shape coming from a Decomposition of an element.");
	cls_AIS_LocalContext.def("HasSelectedShape", (Standard_Boolean (AIS_LocalContext::*)() const ) &AIS_LocalContext::HasSelectedShape, "returns true if current selection is not empty and the owner of selected object contains a shape. This method does not take into account decomposition status of detected shape.");
	cls_AIS_LocalContext.def("SelectedShape", (TopoDS_Shape (AIS_LocalContext::*)() const ) &AIS_LocalContext::SelectedShape, "None");
	cls_AIS_LocalContext.def("SelectedOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_LocalContext::*)() const ) &AIS_LocalContext::SelectedOwner, "None");
	cls_AIS_LocalContext.def("IsSelected", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_LocalContext::IsSelected, "None", py::arg("aniobj"));
	cls_AIS_LocalContext.def("IsSelected", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const ) &AIS_LocalContext::IsSelected, "None", py::arg("anOwner"));
	cls_AIS_LocalContext.def("SelectedInteractive", (opencascade::handle<AIS_InteractiveObject> (AIS_LocalContext::*)() const ) &AIS_LocalContext::SelectedInteractive, "None");
	cls_AIS_LocalContext.def("HasApplicative", (Standard_Boolean (AIS_LocalContext::*)() const ) &AIS_LocalContext::HasApplicative, "returns TRUE if an interactive element was associated with the current picked entity.");
	cls_AIS_LocalContext.def("SelectedApplicative", (const opencascade::handle<Standard_Transient> & (AIS_LocalContext::*)() const ) &AIS_LocalContext::SelectedApplicative, "None");
	cls_AIS_LocalContext.def("SetDisplayPriority", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_LocalContext::SetDisplayPriority, "None", py::arg("anObject"), py::arg("Prior"));
	cls_AIS_LocalContext.def("DisplayedObjects", (Standard_Integer (AIS_LocalContext::*)(TColStd_MapOfTransient &) const ) &AIS_LocalContext::DisplayedObjects, "None", py::arg("theMapToFill"));
	cls_AIS_LocalContext.def("IsIn", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_LocalContext::IsIn, "None", py::arg("anObject"));
	cls_AIS_LocalContext.def("IsDisplayed", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_LocalContext::IsDisplayed, "None", py::arg("anObject"));
	cls_AIS_LocalContext.def("IsDisplayed", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer) const ) &AIS_LocalContext::IsDisplayed, "None", py::arg("anObject"), py::arg("aMode"));
	cls_AIS_LocalContext.def("SelectionModes", (const TColStd_ListOfInteger & (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_LocalContext::SelectionModes, "None", py::arg("anObject"));
	cls_AIS_LocalContext.def("SubIntensityOn", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::SubIntensityOn, "None", py::arg("anObject"));
	cls_AIS_LocalContext.def("SubIntensityOff", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::SubIntensityOff, "None", py::arg("anObject"));
	cls_AIS_LocalContext.def("Hilight", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::Hilight, "None", py::arg("anObject"));
	cls_AIS_LocalContext.def("Hilight", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Prs3d_Drawer> &)) &AIS_LocalContext::Hilight, "None", py::arg("theObj"), py::arg("theStyle"));
	cls_AIS_LocalContext.def("Unhilight", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::Unhilight, "None", py::arg("anObject"));
	cls_AIS_LocalContext.def("IsHilighted", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_LocalContext::IsHilighted, "None", py::arg("anObject"));
	cls_AIS_LocalContext.def("HighlightStyle", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, opencascade::handle<Prs3d_Drawer> &) const ) &AIS_LocalContext::HighlightStyle, "None", py::arg("theObject"), py::arg("theStyle"));
	cls_AIS_LocalContext.def("SetPixelTolerance", [](AIS_LocalContext &self) -> void { return self.SetPixelTolerance(); });
	cls_AIS_LocalContext.def("SetPixelTolerance", (void (AIS_LocalContext::*)(const Standard_Integer)) &AIS_LocalContext::SetPixelTolerance, "Define the current selection sensitivity for this local context according to the view size.", py::arg("aPrecision"));
	cls_AIS_LocalContext.def("PixelTolerance", (Standard_Integer (AIS_LocalContext::*)() const ) &AIS_LocalContext::PixelTolerance, "Returns the pixel tolerance.");
	cls_AIS_LocalContext.def("SetSelectionSensitivity", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Integer)) &AIS_LocalContext::SetSelectionSensitivity, "Allows to manage sensitivity of a particular selection of interactive object theObject and changes previous sensitivity value of all sensitive entities in selection with theMode to the given theNewSensitivity.", py::arg("theObject"), py::arg("theMode"), py::arg("theNewSensitivity"));
	cls_AIS_LocalContext.def("BeginImmediateDraw", (Standard_Boolean (AIS_LocalContext::*)()) &AIS_LocalContext::BeginImmediateDraw, "Resets the transient list of presentations previously displayed in immediate mode and begins accumulation of new list by following AddToImmediateList()/Color()/Highlight() calls.");
	cls_AIS_LocalContext.def("ClearImmediateDraw", (void (AIS_LocalContext::*)()) &AIS_LocalContext::ClearImmediateDraw, "Resets the transient list of presentations previously displayed in immediate mode.");
	cls_AIS_LocalContext.def("ImmediateAdd", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> Standard_Boolean { return self.ImmediateAdd(a0); }, py::arg("theObj"));
	cls_AIS_LocalContext.def("ImmediateAdd", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_LocalContext::ImmediateAdd, "Stores presentation theMode of object theObj in the transient list of presentations to be displayed in immediate mode. Will be taken in account in EndImmediateDraw method.", py::arg("theObj"), py::arg("theMode"));
	cls_AIS_LocalContext.def("EndImmediateDraw", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<V3d_Viewer> &)) &AIS_LocalContext::EndImmediateDraw, "Allows rapid drawing of the view theView by avoiding an update of the whole background.", py::arg("theViewer"));
	cls_AIS_LocalContext.def("IsImmediateModeOn", (Standard_Boolean (AIS_LocalContext::*)() const ) &AIS_LocalContext::IsImmediateModeOn, "Returns true if Presentation Manager is accumulating transient list of presentations to be displayed in immediate mode.");
	cls_AIS_LocalContext.def("Status", (TCollection_AsciiString (AIS_LocalContext::*)() const ) &AIS_LocalContext::Status, "None");
	cls_AIS_LocalContext.def("Status", (const opencascade::handle<AIS_LocalStatus> & (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_LocalContext::Status, "None", py::arg("anObject"));
	cls_AIS_LocalContext.def("LoadContextObjects", (void (AIS_LocalContext::*)()) &AIS_LocalContext::LoadContextObjects, "None");
	cls_AIS_LocalContext.def("UnloadContextObjects", (void (AIS_LocalContext::*)()) &AIS_LocalContext::UnloadContextObjects, "None");
	cls_AIS_LocalContext.def("DisplaySensitive", (void (AIS_LocalContext::*)(const opencascade::handle<V3d_View> &)) &AIS_LocalContext::DisplaySensitive, "None", py::arg("aView"));
	cls_AIS_LocalContext.def("ClearSensitive", (void (AIS_LocalContext::*)(const opencascade::handle<V3d_View> &)) &AIS_LocalContext::ClearSensitive, "None", py::arg("aView"));
	cls_AIS_LocalContext.def("MainSelector", (const opencascade::handle<StdSelect_ViewerSelector3d> & (AIS_LocalContext::*)() const ) &AIS_LocalContext::MainSelector, "None");
	cls_AIS_LocalContext.def("FindSelectedOwnerFromIO", (opencascade::handle<SelectMgr_EntityOwner> (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const ) &AIS_LocalContext::FindSelectedOwnerFromIO, "None", py::arg("anIObj"));
	cls_AIS_LocalContext.def("FindSelectedOwnerFromShape", (opencascade::handle<SelectMgr_EntityOwner> (AIS_LocalContext::*)(const TopoDS_Shape &) const ) &AIS_LocalContext::FindSelectedOwnerFromShape, "None", py::arg("aShape"));
	cls_AIS_LocalContext.def("RestoreActivatedModes", (void (AIS_LocalContext::*)() const ) &AIS_LocalContext::RestoreActivatedModes, "Iterates through all interactive objects of local context and activates selection modes stored in local status");
	cls_AIS_LocalContext.def_static("get_type_name_", (const char * (*)()) &AIS_LocalContext::get_type_name, "None");
	cls_AIS_LocalContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_LocalContext::get_type_descriptor, "None");
	cls_AIS_LocalContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_LocalContext::*)() const ) &AIS_LocalContext::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\AIS_LocalStatus.hxx
	py::class_<AIS_LocalStatus, opencascade::handle<AIS_LocalStatus>, Standard_Transient> cls_AIS_LocalStatus(mod, "AIS_LocalStatus", "Stored Info about temporary objects.");
	cls_AIS_LocalStatus.def(py::init<>());
	cls_AIS_LocalStatus.def(py::init<const Standard_Boolean>(), py::arg("theIsTemporary"));
	cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"));
	cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Integer>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"), py::arg("theDisplayMode"));
	cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"), py::arg("theDisplayMode"), py::arg("theSelectionMode"));
	cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"), py::arg("theDisplayMode"), py::arg("theSelectionMode"), py::arg("theHilightMode"));
	cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"), py::arg("theDisplayMode"), py::arg("theSelectionMode"), py::arg("theHilightMode"), py::arg("theIsSubIntensity"));
	cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const opencascade::handle<Prs3d_Drawer> &>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"), py::arg("theDisplayMode"), py::arg("theSelectionMode"), py::arg("theHilightMode"), py::arg("theIsSubIntensity"), py::arg("theStyle"));
	cls_AIS_LocalStatus.def_static("get_type_name_", (const char * (*)()) &AIS_LocalStatus::get_type_name, "None");
	cls_AIS_LocalStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_LocalStatus::get_type_descriptor, "None");
	cls_AIS_LocalStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_LocalStatus::*)() const ) &AIS_LocalStatus::DynamicType, "None");
	cls_AIS_LocalStatus.def("Decomposed", (Standard_Boolean (AIS_LocalStatus::*)() const ) &AIS_LocalStatus::Decomposed, "None");
	cls_AIS_LocalStatus.def("IsTemporary", (Standard_Boolean (AIS_LocalStatus::*)() const ) &AIS_LocalStatus::IsTemporary, "None");
	cls_AIS_LocalStatus.def("DisplayMode", (Standard_Integer (AIS_LocalStatus::*)() const ) &AIS_LocalStatus::DisplayMode, "None");
	cls_AIS_LocalStatus.def("SelectionModes", (const TColStd_ListOfInteger & (AIS_LocalStatus::*)() const ) &AIS_LocalStatus::SelectionModes, "None");
	cls_AIS_LocalStatus.def("IsActivated", (Standard_Boolean (AIS_LocalStatus::*)(const Standard_Integer) const ) &AIS_LocalStatus::IsActivated, "None", py::arg("aSelMode"));
	cls_AIS_LocalStatus.def("HilightMode", (Standard_Integer (AIS_LocalStatus::*)() const ) &AIS_LocalStatus::HilightMode, "None");
	cls_AIS_LocalStatus.def("IsSubIntensityOn", (Standard_Boolean (AIS_LocalStatus::*)() const ) &AIS_LocalStatus::IsSubIntensityOn, "None");
	cls_AIS_LocalStatus.def("HilightStyle", (const opencascade::handle<Prs3d_Drawer> & (AIS_LocalStatus::*)() const ) &AIS_LocalStatus::HilightStyle, "None");
	cls_AIS_LocalStatus.def("SetDecomposition", (void (AIS_LocalStatus::*)(const Standard_Boolean)) &AIS_LocalStatus::SetDecomposition, "None", py::arg("astatus"));
	cls_AIS_LocalStatus.def("SetTemporary", (void (AIS_LocalStatus::*)(const Standard_Boolean)) &AIS_LocalStatus::SetTemporary, "None", py::arg("astatus"));
	cls_AIS_LocalStatus.def("SetDisplayMode", (void (AIS_LocalStatus::*)(const Standard_Integer)) &AIS_LocalStatus::SetDisplayMode, "None", py::arg("aMode"));
	cls_AIS_LocalStatus.def("SetFirstDisplay", (void (AIS_LocalStatus::*)(const Standard_Boolean)) &AIS_LocalStatus::SetFirstDisplay, "None", py::arg("aStatus"));
	cls_AIS_LocalStatus.def("IsFirstDisplay", (Standard_Boolean (AIS_LocalStatus::*)() const ) &AIS_LocalStatus::IsFirstDisplay, "None");
	cls_AIS_LocalStatus.def("AddSelectionMode", (void (AIS_LocalStatus::*)(const Standard_Integer)) &AIS_LocalStatus::AddSelectionMode, "None", py::arg("aMode"));
	cls_AIS_LocalStatus.def("RemoveSelectionMode", (void (AIS_LocalStatus::*)(const Standard_Integer)) &AIS_LocalStatus::RemoveSelectionMode, "None", py::arg("aMode"));
	cls_AIS_LocalStatus.def("ClearSelectionModes", (void (AIS_LocalStatus::*)()) &AIS_LocalStatus::ClearSelectionModes, "None");
	cls_AIS_LocalStatus.def("IsSelModeIn", (Standard_Boolean (AIS_LocalStatus::*)(const Standard_Integer) const ) &AIS_LocalStatus::IsSelModeIn, "None", py::arg("aMode"));
	cls_AIS_LocalStatus.def("SetHilightMode", (void (AIS_LocalStatus::*)(const Standard_Integer)) &AIS_LocalStatus::SetHilightMode, "None", py::arg("aMode"));
	cls_AIS_LocalStatus.def("SetHilightStyle", (void (AIS_LocalStatus::*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_LocalStatus::SetHilightStyle, "None", py::arg("theStyle"));
	cls_AIS_LocalStatus.def("SubIntensityOn", (void (AIS_LocalStatus::*)()) &AIS_LocalStatus::SubIntensityOn, "None");
	cls_AIS_LocalStatus.def("SubIntensityOff", (void (AIS_LocalStatus::*)()) &AIS_LocalStatus::SubIntensityOff, "None");
	cls_AIS_LocalStatus.def("SetPreviousState", (void (AIS_LocalStatus::*)(const opencascade::handle<Standard_Transient> &)) &AIS_LocalStatus::SetPreviousState, "None", py::arg("aStatus"));
	cls_AIS_LocalStatus.def("PreviousState", (const opencascade::handle<Standard_Transient> & (AIS_LocalStatus::*)() const ) &AIS_LocalStatus::PreviousState, "None");

	init_AIS_1(mod);

}
