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

#ifndef _WIN32
#include <xTypes.h>
#endif

#include <Aspect_TypeOfDeflection.hxx>
#include <Aspect_TypeOfHighlightMethod.hxx>
#include <Standard_OutOfRange.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Handle.hxx>
#include <Aspect_AspectFillAreaDefinitionError.hxx>
#include <Standard_Type.hxx>
#include <Aspect_PolygonOffsetMode.hxx>
#include <Aspect_InteriorStyle.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Aspect_HatchStyle.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <Aspect_IdentDefinitionError.hxx>
#include <Aspect_GenId.hxx>
#include <Aspect_Handle.hxx>
#include <Aspect_RenderingContext.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_Background.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <Aspect_GradientBackground.hxx>
#include <Aspect_FBConfig.hxx>
#include <Aspect_FillMethod.hxx>
#include <Aspect_TypeOfResize.hxx>
#include <Aspect_Drawable.hxx>
#include <Aspect_WindowDefinitionError.hxx>
#include <Aspect_WindowError.hxx>
#include <Standard_Transient.hxx>
#include <Aspect_Window.hxx>
#include <Aspect_AspectLineDefinitionError.hxx>
#include <Aspect_TypeOfStyleText.hxx>
#include <Aspect_TypeOfDisplayText.hxx>
#include <Aspect_AspectMarkerDefinitionError.hxx>
#include <Aspect_TypeOfTriedronPosition.hxx>
#include <Aspect_TypeOfFacingModel.hxx>
#include <Aspect_TypeOfColorScaleData.hxx>
#include <Aspect_TypeOfColorScalePosition.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Aspect_SequenceOfColor.hxx>
#include <Aspect_GridDrawMode.hxx>
#include <Aspect_GridType.hxx>
#include <Aspect_Grid.hxx>
#include <Standard_DomainError.hxx>
#include <Aspect_BadAccess.hxx>
#include <Aspect_CircularGrid.hxx>
#include <Aspect_Display.hxx>
#include <Aspect_XAtom.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Aspect_DisplayConnectionDefinitionError.hxx>
#include <Aspect_DriverDefinitionError.hxx>
#include <Aspect_GraphicDeviceDefinitionError.hxx>
#include <Aspect_NeutralWindow.hxx>
#include <Aspect_RectangularGrid.hxx>
#include <Aspect_TypeOfColorScaleOrientation.hxx>
#include <Aspect_TypeOfConstraint.hxx>
#include <Aspect_TypeOfDrawMode.hxx>
#include <Aspect_TypeOfEdge.hxx>
#include <Aspect_TypeOfLayer.hxx>
#include <Aspect_TypeOfPrimitive.hxx>
#include <Aspect_WidthOfLine.hxx>
#include <Aspect_XWD.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(Aspect, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Quantity");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfDeflection.hxx
	py::enum_<Aspect_TypeOfDeflection>(mod, "Aspect_TypeOfDeflection", "Defines if the maximal chordial deflection used when drawing an object is absolute or relative to the size of the object.")
		.value("Aspect_TOD_RELATIVE", Aspect_TypeOfDeflection::Aspect_TOD_RELATIVE)
		.value("Aspect_TOD_ABSOLUTE", Aspect_TypeOfDeflection::Aspect_TOD_ABSOLUTE)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfHighlightMethod.hxx
	py::enum_<Aspect_TypeOfHighlightMethod>(mod, "Aspect_TypeOfHighlightMethod", "Definition of a highlight method")
		.value("Aspect_TOHM_COLOR", Aspect_TypeOfHighlightMethod::Aspect_TOHM_COLOR)
		.value("Aspect_TOHM_BOUNDBOX", Aspect_TypeOfHighlightMethod::Aspect_TOHM_BOUNDBOX)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_PolygonOffsetMode.hxx
	mod.attr("Aspect_POM_Off") = py::cast(int(Aspect_POM_Off));
	mod.attr("Aspect_POM_Fill") = py::cast(int(Aspect_POM_Fill));
	mod.attr("Aspect_POM_Line") = py::cast(int(Aspect_POM_Line));
	mod.attr("Aspect_POM_Point") = py::cast(int(Aspect_POM_Point));
	mod.attr("Aspect_POM_All") = py::cast(int(Aspect_POM_All));
	mod.attr("Aspect_POM_None") = py::cast(int(Aspect_POM_None));
	mod.attr("Aspect_POM_Mask") = py::cast(int(Aspect_POM_Mask));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_InteriorStyle.hxx
	py::enum_<Aspect_InteriorStyle>(mod, "Aspect_InteriorStyle", "Definition of interior types for primitive faces.")
		.value("Aspect_IS_EMPTY", Aspect_InteriorStyle::Aspect_IS_EMPTY)
		.value("Aspect_IS_HOLLOW", Aspect_InteriorStyle::Aspect_IS_HOLLOW)
		.value("Aspect_IS_HATCH", Aspect_InteriorStyle::Aspect_IS_HATCH)
		.value("Aspect_IS_SOLID", Aspect_InteriorStyle::Aspect_IS_SOLID)
		.value("Aspect_IS_HIDDENLINE", Aspect_InteriorStyle::Aspect_IS_HIDDENLINE)
		.value("Aspect_IS_POINT", Aspect_InteriorStyle::Aspect_IS_POINT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfLine.hxx
	py::enum_<Aspect_TypeOfLine>(mod, "Aspect_TypeOfLine", "Definition of line types")
		.value("Aspect_TOL_EMPTY", Aspect_TypeOfLine::Aspect_TOL_EMPTY)
		.value("Aspect_TOL_SOLID", Aspect_TypeOfLine::Aspect_TOL_SOLID)
		.value("Aspect_TOL_DASH", Aspect_TypeOfLine::Aspect_TOL_DASH)
		.value("Aspect_TOL_DOT", Aspect_TypeOfLine::Aspect_TOL_DOT)
		.value("Aspect_TOL_DOTDASH", Aspect_TypeOfLine::Aspect_TOL_DOTDASH)
		.value("Aspect_TOL_USERDEFINED", Aspect_TypeOfLine::Aspect_TOL_USERDEFINED)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_HatchStyle.hxx
	py::enum_<Aspect_HatchStyle>(mod, "Aspect_HatchStyle", "Definition of all available hatch styles.")
		.value("Aspect_HS_SOLID", Aspect_HatchStyle::Aspect_HS_SOLID)
		.value("Aspect_HS_HORIZONTAL", Aspect_HatchStyle::Aspect_HS_HORIZONTAL)
		.value("Aspect_HS_HORIZONTAL_WIDE", Aspect_HatchStyle::Aspect_HS_HORIZONTAL_WIDE)
		.value("Aspect_HS_VERTICAL", Aspect_HatchStyle::Aspect_HS_VERTICAL)
		.value("Aspect_HS_VERTICAL_WIDE", Aspect_HatchStyle::Aspect_HS_VERTICAL_WIDE)
		.value("Aspect_HS_DIAGONAL_45", Aspect_HatchStyle::Aspect_HS_DIAGONAL_45)
		.value("Aspect_HS_DIAGONAL_45_WIDE", Aspect_HatchStyle::Aspect_HS_DIAGONAL_45_WIDE)
		.value("Aspect_HS_DIAGONAL_135", Aspect_HatchStyle::Aspect_HS_DIAGONAL_135)
		.value("Aspect_HS_DIAGONAL_135_WIDE", Aspect_HatchStyle::Aspect_HS_DIAGONAL_135_WIDE)
		.value("Aspect_HS_GRID", Aspect_HatchStyle::Aspect_HS_GRID)
		.value("Aspect_HS_GRID_WIDE", Aspect_HatchStyle::Aspect_HS_GRID_WIDE)
		.value("Aspect_HS_GRID_DIAGONAL", Aspect_HatchStyle::Aspect_HS_GRID_DIAGONAL)
		.value("Aspect_HS_GRID_DIAGONAL_WIDE", Aspect_HatchStyle::Aspect_HS_GRID_DIAGONAL_WIDE)
		.value("Aspect_HS_NB", Aspect_HatchStyle::Aspect_HS_NB)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfMarker.hxx
	py::enum_<Aspect_TypeOfMarker>(mod, "Aspect_TypeOfMarker", "Definition of types of markers")
		.value("Aspect_TOM_EMPTY", Aspect_TypeOfMarker::Aspect_TOM_EMPTY)
		.value("Aspect_TOM_POINT", Aspect_TypeOfMarker::Aspect_TOM_POINT)
		.value("Aspect_TOM_PLUS", Aspect_TypeOfMarker::Aspect_TOM_PLUS)
		.value("Aspect_TOM_STAR", Aspect_TypeOfMarker::Aspect_TOM_STAR)
		.value("Aspect_TOM_X", Aspect_TypeOfMarker::Aspect_TOM_X)
		.value("Aspect_TOM_O", Aspect_TypeOfMarker::Aspect_TOM_O)
		.value("Aspect_TOM_O_POINT", Aspect_TypeOfMarker::Aspect_TOM_O_POINT)
		.value("Aspect_TOM_O_PLUS", Aspect_TypeOfMarker::Aspect_TOM_O_PLUS)
		.value("Aspect_TOM_O_STAR", Aspect_TypeOfMarker::Aspect_TOM_O_STAR)
		.value("Aspect_TOM_O_X", Aspect_TypeOfMarker::Aspect_TOM_O_X)
		.value("Aspect_TOM_RING1", Aspect_TypeOfMarker::Aspect_TOM_RING1)
		.value("Aspect_TOM_RING2", Aspect_TypeOfMarker::Aspect_TOM_RING2)
		.value("Aspect_TOM_RING3", Aspect_TypeOfMarker::Aspect_TOM_RING3)
		.value("Aspect_TOM_BALL", Aspect_TypeOfMarker::Aspect_TOM_BALL)
		.value("Aspect_TOM_USERDEFINED", Aspect_TypeOfMarker::Aspect_TOM_USERDEFINED)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_GradientFillMethod.hxx
	py::enum_<Aspect_GradientFillMethod>(mod, "Aspect_GradientFillMethod", "Defines the fill methods to write gradient background in a window.")
		.value("Aspect_GFM_NONE", Aspect_GradientFillMethod::Aspect_GFM_NONE)
		.value("Aspect_GFM_HOR", Aspect_GradientFillMethod::Aspect_GFM_HOR)
		.value("Aspect_GFM_VER", Aspect_GradientFillMethod::Aspect_GFM_VER)
		.value("Aspect_GFM_DIAG1", Aspect_GradientFillMethod::Aspect_GFM_DIAG1)
		.value("Aspect_GFM_DIAG2", Aspect_GradientFillMethod::Aspect_GFM_DIAG2)
		.value("Aspect_GFM_CORNER1", Aspect_GradientFillMethod::Aspect_GFM_CORNER1)
		.value("Aspect_GFM_CORNER2", Aspect_GradientFillMethod::Aspect_GFM_CORNER2)
		.value("Aspect_GFM_CORNER3", Aspect_GradientFillMethod::Aspect_GFM_CORNER3)
		.value("Aspect_GFM_CORNER4", Aspect_GradientFillMethod::Aspect_GFM_CORNER4)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_FillMethod.hxx
	py::enum_<Aspect_FillMethod>(mod, "Aspect_FillMethod", "Defines the fill methods to write bitmaps in a window.")
		.value("Aspect_FM_NONE", Aspect_FillMethod::Aspect_FM_NONE)
		.value("Aspect_FM_CENTERED", Aspect_FillMethod::Aspect_FM_CENTERED)
		.value("Aspect_FM_TILED", Aspect_FillMethod::Aspect_FM_TILED)
		.value("Aspect_FM_STRETCH", Aspect_FillMethod::Aspect_FM_STRETCH)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfResize.hxx
	py::enum_<Aspect_TypeOfResize>(mod, "Aspect_TypeOfResize", "Defines the type of Resize Window method applied by the user.")
		.value("Aspect_TOR_UNKNOWN", Aspect_TypeOfResize::Aspect_TOR_UNKNOWN)
		.value("Aspect_TOR_NO_BORDER", Aspect_TypeOfResize::Aspect_TOR_NO_BORDER)
		.value("Aspect_TOR_TOP_BORDER", Aspect_TypeOfResize::Aspect_TOR_TOP_BORDER)
		.value("Aspect_TOR_RIGHT_BORDER", Aspect_TypeOfResize::Aspect_TOR_RIGHT_BORDER)
		.value("Aspect_TOR_BOTTOM_BORDER", Aspect_TypeOfResize::Aspect_TOR_BOTTOM_BORDER)
		.value("Aspect_TOR_LEFT_BORDER", Aspect_TypeOfResize::Aspect_TOR_LEFT_BORDER)
		.value("Aspect_TOR_TOP_AND_RIGHT_BORDER", Aspect_TypeOfResize::Aspect_TOR_TOP_AND_RIGHT_BORDER)
		.value("Aspect_TOR_RIGHT_AND_BOTTOM_BORDER", Aspect_TypeOfResize::Aspect_TOR_RIGHT_AND_BOTTOM_BORDER)
		.value("Aspect_TOR_BOTTOM_AND_LEFT_BORDER", Aspect_TypeOfResize::Aspect_TOR_BOTTOM_AND_LEFT_BORDER)
		.value("Aspect_TOR_LEFT_AND_TOP_BORDER", Aspect_TypeOfResize::Aspect_TOR_LEFT_AND_TOP_BORDER)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfStyleText.hxx
	py::enum_<Aspect_TypeOfStyleText>(mod, "Aspect_TypeOfStyleText", "Define the style of the text.")
		.value("Aspect_TOST_NORMAL", Aspect_TypeOfStyleText::Aspect_TOST_NORMAL)
		.value("Aspect_TOST_ANNOTATION", Aspect_TypeOfStyleText::Aspect_TOST_ANNOTATION)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfDisplayText.hxx
	py::enum_<Aspect_TypeOfDisplayText>(mod, "Aspect_TypeOfDisplayText", "Define the display type of the text.")
		.value("Aspect_TODT_NORMAL", Aspect_TypeOfDisplayText::Aspect_TODT_NORMAL)
		.value("Aspect_TODT_SUBTITLE", Aspect_TypeOfDisplayText::Aspect_TODT_SUBTITLE)
		.value("Aspect_TODT_DEKALE", Aspect_TypeOfDisplayText::Aspect_TODT_DEKALE)
		.value("Aspect_TODT_BLEND", Aspect_TypeOfDisplayText::Aspect_TODT_BLEND)
		.value("Aspect_TODT_DIMENSION", Aspect_TypeOfDisplayText::Aspect_TODT_DIMENSION)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfTriedronPosition.hxx
	py::enum_<Aspect_TypeOfTriedronPosition>(mod, "Aspect_TypeOfTriedronPosition", "Definition of the Trihedron position in the views. It is defined as a bitmask to simplify handling vertical and horizontal alignment independently.")
		.value("Aspect_TOTP_CENTER", Aspect_TypeOfTriedronPosition::Aspect_TOTP_CENTER)
		.value("Aspect_TOTP_TOP", Aspect_TypeOfTriedronPosition::Aspect_TOTP_TOP)
		.value("Aspect_TOTP_BOTTOM", Aspect_TypeOfTriedronPosition::Aspect_TOTP_BOTTOM)
		.value("Aspect_TOTP_LEFT", Aspect_TypeOfTriedronPosition::Aspect_TOTP_LEFT)
		.value("Aspect_TOTP_RIGHT", Aspect_TypeOfTriedronPosition::Aspect_TOTP_RIGHT)
		.value("Aspect_TOTP_LEFT_LOWER", Aspect_TypeOfTriedronPosition::Aspect_TOTP_LEFT_LOWER)
		.value("Aspect_TOTP_LEFT_UPPER", Aspect_TypeOfTriedronPosition::Aspect_TOTP_LEFT_UPPER)
		.value("Aspect_TOTP_RIGHT_LOWER", Aspect_TypeOfTriedronPosition::Aspect_TOTP_RIGHT_LOWER)
		.value("Aspect_TOTP_RIGHT_UPPER", Aspect_TypeOfTriedronPosition::Aspect_TOTP_RIGHT_UPPER)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfFacingModel.hxx
	py::enum_<Aspect_TypeOfFacingModel>(mod, "Aspect_TypeOfFacingModel", "None")
		.value("Aspect_TOFM_BOTH_SIDE", Aspect_TypeOfFacingModel::Aspect_TOFM_BOTH_SIDE)
		.value("Aspect_TOFM_BACK_SIDE", Aspect_TypeOfFacingModel::Aspect_TOFM_BACK_SIDE)
		.value("Aspect_TOFM_FRONT_SIDE", Aspect_TypeOfFacingModel::Aspect_TOFM_FRONT_SIDE)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfColorScaleData.hxx
	py::enum_<Aspect_TypeOfColorScaleData>(mod, "Aspect_TypeOfColorScaleData", "Defines the using type of colors and labels")
		.value("Aspect_TOCSD_AUTO", Aspect_TypeOfColorScaleData::Aspect_TOCSD_AUTO)
		.value("Aspect_TOCSD_USER", Aspect_TypeOfColorScaleData::Aspect_TOCSD_USER)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfColorScalePosition.hxx
	py::enum_<Aspect_TypeOfColorScalePosition>(mod, "Aspect_TypeOfColorScalePosition", "Defines the type of position for color scale labels")
		.value("Aspect_TOCSP_NONE", Aspect_TypeOfColorScalePosition::Aspect_TOCSP_NONE)
		.value("Aspect_TOCSP_LEFT", Aspect_TypeOfColorScalePosition::Aspect_TOCSP_LEFT)
		.value("Aspect_TOCSP_RIGHT", Aspect_TypeOfColorScalePosition::Aspect_TOCSP_RIGHT)
		.value("Aspect_TOCSP_CENTER", Aspect_TypeOfColorScalePosition::Aspect_TOCSP_CENTER)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_GridDrawMode.hxx
	py::enum_<Aspect_GridDrawMode>(mod, "Aspect_GridDrawMode", "Defines the grid draw mode. The grid may be drawn by using lines or points.")
		.value("Aspect_GDM_Lines", Aspect_GridDrawMode::Aspect_GDM_Lines)
		.value("Aspect_GDM_Points", Aspect_GridDrawMode::Aspect_GDM_Points)
		.value("Aspect_GDM_None", Aspect_GridDrawMode::Aspect_GDM_None)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_GridType.hxx
	py::enum_<Aspect_GridType>(mod, "Aspect_GridType", "Defines the grid type : Rectangular or Circular.")
		.value("Aspect_GT_Rectangular", Aspect_GridType::Aspect_GT_Rectangular)
		.value("Aspect_GT_Circular", Aspect_GridType::Aspect_GT_Circular)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_XAtom.hxx
	py::enum_<Aspect_XAtom>(mod, "Aspect_XAtom", "Defines custom identifiers(atoms) for X window custom named properties")
		.value("Aspect_XA_DELETE_WINDOW", Aspect_XAtom::Aspect_XA_DELETE_WINDOW)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfColorScaleOrientation.hxx
	py::enum_<Aspect_TypeOfColorScaleOrientation>(mod, "Aspect_TypeOfColorScaleOrientation", "Defines the type of color scale orientation")
		.value("Aspect_TOCSO_NONE", Aspect_TypeOfColorScaleOrientation::Aspect_TOCSO_NONE)
		.value("Aspect_TOCSO_LEFT", Aspect_TypeOfColorScaleOrientation::Aspect_TOCSO_LEFT)
		.value("Aspect_TOCSO_RIGHT", Aspect_TypeOfColorScaleOrientation::Aspect_TOCSO_RIGHT)
		.value("Aspect_TOCSO_CENTER", Aspect_TypeOfColorScaleOrientation::Aspect_TOCSO_CENTER)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfConstraint.hxx
	py::enum_<Aspect_TypeOfConstraint>(mod, "Aspect_TypeOfConstraint", "Definition of the attachment for the layers")
		.value("Aspect_TOC_BOTTOM_LEFT", Aspect_TypeOfConstraint::Aspect_TOC_BOTTOM_LEFT)
		.value("Aspect_TOC_BOTTOM_RIGHT", Aspect_TypeOfConstraint::Aspect_TOC_BOTTOM_RIGHT)
		.value("Aspect_TOC_TOP_LEFT", Aspect_TypeOfConstraint::Aspect_TOC_TOP_LEFT)
		.value("Aspect_TOC_TOP_RIGHT", Aspect_TypeOfConstraint::Aspect_TOC_TOP_RIGHT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfDrawMode.hxx
	py::enum_<Aspect_TypeOfDrawMode>(mod, "Aspect_TypeOfDrawMode", "Definition of the draw modes")
		.value("Aspect_TODM_REPLACE", Aspect_TypeOfDrawMode::Aspect_TODM_REPLACE)
		.value("Aspect_TODM_ERASE", Aspect_TypeOfDrawMode::Aspect_TODM_ERASE)
		.value("Aspect_TODM_XOR", Aspect_TypeOfDrawMode::Aspect_TODM_XOR)
		.value("Aspect_TODM_XORLIGHT", Aspect_TypeOfDrawMode::Aspect_TODM_XORLIGHT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfEdge.hxx
	py::enum_<Aspect_TypeOfEdge>(mod, "Aspect_TypeOfEdge", "Definition of edge visibility")
		.value("Aspect_TOE_VISIBLE", Aspect_TypeOfEdge::Aspect_TOE_VISIBLE)
		.value("Aspect_TOE_INVISIBLE", Aspect_TypeOfEdge::Aspect_TOE_INVISIBLE)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfLayer.hxx
	py::enum_<Aspect_TypeOfLayer>(mod, "Aspect_TypeOfLayer", "Modes of drawing for the objects in a layer")
		.value("Aspect_TOL_OVERLAY", Aspect_TypeOfLayer::Aspect_TOL_OVERLAY)
		.value("Aspect_TOL_UNDERLAY", Aspect_TypeOfLayer::Aspect_TOL_UNDERLAY)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_TypeOfPrimitive.hxx
	py::enum_<Aspect_TypeOfPrimitive>(mod, "Aspect_TypeOfPrimitive", "None")
		.value("Aspect_TOP_UNKNOWN", Aspect_TypeOfPrimitive::Aspect_TOP_UNKNOWN)
		.value("Aspect_TOP_POLYLINE", Aspect_TypeOfPrimitive::Aspect_TOP_POLYLINE)
		.value("Aspect_TOP_POLYGON", Aspect_TypeOfPrimitive::Aspect_TOP_POLYGON)
		.value("Aspect_TOP_SEGMENTS", Aspect_TypeOfPrimitive::Aspect_TOP_SEGMENTS)
		.value("Aspect_TOP_ARCS", Aspect_TypeOfPrimitive::Aspect_TOP_ARCS)
		.value("Aspect_TOP_POLYARCS", Aspect_TypeOfPrimitive::Aspect_TOP_POLYARCS)
		.value("Aspect_TOP_POINTS", Aspect_TypeOfPrimitive::Aspect_TOP_POINTS)
		.value("Aspect_TOP_MARKERS", Aspect_TypeOfPrimitive::Aspect_TOP_MARKERS)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_WidthOfLine.hxx
	py::enum_<Aspect_WidthOfLine>(mod, "Aspect_WidthOfLine", "Definition of line types")
		.value("Aspect_WOL_THIN", Aspect_WidthOfLine::Aspect_WOL_THIN)
		.value("Aspect_WOL_MEDIUM", Aspect_WidthOfLine::Aspect_WOL_MEDIUM)
		.value("Aspect_WOL_THICK", Aspect_WidthOfLine::Aspect_WOL_THICK)
		.value("Aspect_WOL_VERYTHICK", Aspect_WidthOfLine::Aspect_WOL_VERYTHICK)
		.value("Aspect_WOL_USERDEFINED", Aspect_WidthOfLine::Aspect_WOL_USERDEFINED)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_AspectFillAreaDefinitionError.hxx
	py::class_<Aspect_AspectFillAreaDefinitionError, opencascade::handle<Aspect_AspectFillAreaDefinitionError>, Standard_OutOfRange> cls_Aspect_AspectFillAreaDefinitionError(mod, "Aspect_AspectFillAreaDefinitionError", "None");
	cls_Aspect_AspectFillAreaDefinitionError.def(py::init<>());
	cls_Aspect_AspectFillAreaDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Aspect_AspectFillAreaDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_AspectFillAreaDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_AspectFillAreaDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_AspectFillAreaDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_AspectFillAreaDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_AspectFillAreaDefinitionError> (*)(const Standard_CString)) &Aspect_AspectFillAreaDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Aspect_AspectFillAreaDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_AspectFillAreaDefinitionError::get_type_name, "None");
	cls_Aspect_AspectFillAreaDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_AspectFillAreaDefinitionError::get_type_descriptor, "None");
	cls_Aspect_AspectFillAreaDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_AspectFillAreaDefinitionError::*)() const ) &Aspect_AspectFillAreaDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_IdentDefinitionError.hxx
	py::class_<Aspect_IdentDefinitionError, opencascade::handle<Aspect_IdentDefinitionError>, Standard_OutOfRange> cls_Aspect_IdentDefinitionError(mod, "Aspect_IdentDefinitionError", "None");
	cls_Aspect_IdentDefinitionError.def(py::init<>());
	cls_Aspect_IdentDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Aspect_IdentDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_IdentDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_IdentDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_IdentDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_IdentDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_IdentDefinitionError> (*)(const Standard_CString)) &Aspect_IdentDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Aspect_IdentDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_IdentDefinitionError::get_type_name, "None");
	cls_Aspect_IdentDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_IdentDefinitionError::get_type_descriptor, "None");
	cls_Aspect_IdentDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_IdentDefinitionError::*)() const ) &Aspect_IdentDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_GenId.hxx
	py::class_<Aspect_GenId, std::unique_ptr<Aspect_GenId, Deleter<Aspect_GenId>>> cls_Aspect_GenId(mod, "Aspect_GenId", "This class permits the creation and control of integer identifiers.");
	cls_Aspect_GenId.def(py::init<>());
	cls_Aspect_GenId.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLow"), py::arg("theUpper"));
	cls_Aspect_GenId.def("Free", (void (Aspect_GenId::*)()) &Aspect_GenId::Free, "Free all identifiers - make the whole range available again.");
	cls_Aspect_GenId.def("Free", (void (Aspect_GenId::*)(const Standard_Integer)) &Aspect_GenId::Free, "Free specified identifier. Warning - method has no protection against double-freeing!", py::arg("theId"));
	cls_Aspect_GenId.def("HasFree", (Standard_Boolean (Aspect_GenId::*)() const ) &Aspect_GenId::HasFree, "Returns true if there are available identifiers in range.");
	cls_Aspect_GenId.def("Available", (Standard_Integer (Aspect_GenId::*)() const ) &Aspect_GenId::Available, "Returns the number of available identifiers.");
	cls_Aspect_GenId.def("Lower", (Standard_Integer (Aspect_GenId::*)() const ) &Aspect_GenId::Lower, "Returns the lower identifier in range.");
	cls_Aspect_GenId.def("Next", (Standard_Integer (Aspect_GenId::*)()) &Aspect_GenId::Next, "Returns the next available identifier. Warning: Raises IdentDefinitionError if all identifiers are busy.");
	cls_Aspect_GenId.def("Upper", (Standard_Integer (Aspect_GenId::*)() const ) &Aspect_GenId::Upper, "Returns the upper identifier in range.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_Background.hxx
	py::class_<Aspect_Background, std::unique_ptr<Aspect_Background, Deleter<Aspect_Background>>> cls_Aspect_Background(mod, "Aspect_Background", "This class allows the definition of a window background.");
	cls_Aspect_Background.def(py::init<>());
	cls_Aspect_Background.def(py::init<const Quantity_Color &>(), py::arg("AColor"));
	cls_Aspect_Background.def("SetColor", (void (Aspect_Background::*)(const Quantity_Color &)) &Aspect_Background::SetColor, "Modifies the colour of the window background <me>.", py::arg("AColor"));
	cls_Aspect_Background.def("Color", (Quantity_Color (Aspect_Background::*)() const ) &Aspect_Background::Color, "Returns the colour of the window background <me>.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_GradientBackground.hxx
	py::class_<Aspect_GradientBackground, std::unique_ptr<Aspect_GradientBackground, Deleter<Aspect_GradientBackground>>, Aspect_Background> cls_Aspect_GradientBackground(mod, "Aspect_GradientBackground", "This class allows the definition of a window gradient background.");
	cls_Aspect_GradientBackground.def(py::init<>());
	cls_Aspect_GradientBackground.def(py::init<const Quantity_Color &, const Quantity_Color &>(), py::arg("AColor1"), py::arg("AColor2"));
	cls_Aspect_GradientBackground.def(py::init<const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod>(), py::arg("AColor1"), py::arg("AColor2"), py::arg("AMethod"));
	cls_Aspect_GradientBackground.def("SetColors", [](Aspect_GradientBackground &self, const Quantity_Color & a0, const Quantity_Color & a1) -> void { return self.SetColors(a0, a1); }, py::arg("AColor1"), py::arg("AColor2"));
	cls_Aspect_GradientBackground.def("SetColors", (void (Aspect_GradientBackground::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod)) &Aspect_GradientBackground::SetColors, "Modifies the colours of the window gradient background <me>.", py::arg("AColor1"), py::arg("AColor2"), py::arg("AMethod"));
	cls_Aspect_GradientBackground.def("Colors", (void (Aspect_GradientBackground::*)(Quantity_Color &, Quantity_Color &) const ) &Aspect_GradientBackground::Colors, "Returns colours of the window gradient background <me>.", py::arg("AColor1"), py::arg("AColor2"));
	cls_Aspect_GradientBackground.def("BgGradientFillMethod", (Aspect_GradientFillMethod (Aspect_GradientBackground::*)() const ) &Aspect_GradientBackground::BgGradientFillMethod, "Returns the current gradient background fill mode.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_WindowDefinitionError.hxx
	py::class_<Aspect_WindowDefinitionError, opencascade::handle<Aspect_WindowDefinitionError>, Standard_OutOfRange> cls_Aspect_WindowDefinitionError(mod, "Aspect_WindowDefinitionError", "None");
	cls_Aspect_WindowDefinitionError.def(py::init<>());
	cls_Aspect_WindowDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Aspect_WindowDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_WindowDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_WindowDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_WindowDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_WindowDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_WindowDefinitionError> (*)(const Standard_CString)) &Aspect_WindowDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Aspect_WindowDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_WindowDefinitionError::get_type_name, "None");
	cls_Aspect_WindowDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_WindowDefinitionError::get_type_descriptor, "None");
	cls_Aspect_WindowDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_WindowDefinitionError::*)() const ) &Aspect_WindowDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_WindowError.hxx
	py::class_<Aspect_WindowError, opencascade::handle<Aspect_WindowError>, Standard_OutOfRange> cls_Aspect_WindowError(mod, "Aspect_WindowError", "None");
	cls_Aspect_WindowError.def(py::init<>());
	cls_Aspect_WindowError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Aspect_WindowError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_WindowError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_WindowError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_WindowError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_WindowError.def_static("NewInstance_", (opencascade::handle<Aspect_WindowError> (*)(const Standard_CString)) &Aspect_WindowError::NewInstance, "None", py::arg("theMessage"));
	cls_Aspect_WindowError.def_static("get_type_name_", (const char * (*)()) &Aspect_WindowError::get_type_name, "None");
	cls_Aspect_WindowError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_WindowError::get_type_descriptor, "None");
	cls_Aspect_WindowError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_WindowError::*)() const ) &Aspect_WindowError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_Window.hxx
	py::class_<Aspect_Window, opencascade::handle<Aspect_Window>, Standard_Transient> cls_Aspect_Window(mod, "Aspect_Window", "Defines a window.");
	cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Aspect_Background &)) &Aspect_Window::SetBackground, "Modifies the window background.", py::arg("ABack"));
	cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Quantity_Color &)) &Aspect_Window::SetBackground, "Modifies the window background.", py::arg("color"));
	cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Aspect_GradientBackground &)) &Aspect_Window::SetBackground, "Modifies the window gradient background.", py::arg("ABackground"));
	cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod)) &Aspect_Window::SetBackground, "Modifies the window gradient background.", py::arg("theFirstColor"), py::arg("theSecondColor"), py::arg("theFillMethod"));
	cls_Aspect_Window.def("Map", (void (Aspect_Window::*)() const ) &Aspect_Window::Map, "Opens the window <me>.");
	cls_Aspect_Window.def("Unmap", (void (Aspect_Window::*)() const ) &Aspect_Window::Unmap, "Closes the window <me>.");
	cls_Aspect_Window.def("DoResize", (Aspect_TypeOfResize (Aspect_Window::*)() const ) &Aspect_Window::DoResize, "Apply the resizing to the window <me>.");
	cls_Aspect_Window.def("DoMapping", (Standard_Boolean (Aspect_Window::*)() const ) &Aspect_Window::DoMapping, "Apply the mapping change to the window <me>. and returns TRUE if the window is mapped at screen.");
	cls_Aspect_Window.def("Background", (Aspect_Background (Aspect_Window::*)() const ) &Aspect_Window::Background, "Returns the window background.");
	cls_Aspect_Window.def("BackgroundFillMethod", (Aspect_FillMethod (Aspect_Window::*)() const ) &Aspect_Window::BackgroundFillMethod, "Returns the current image background fill mode.");
	cls_Aspect_Window.def("GradientBackground", (Aspect_GradientBackground (Aspect_Window::*)() const ) &Aspect_Window::GradientBackground, "Returns the window gradient background.");
	cls_Aspect_Window.def("IsMapped", (Standard_Boolean (Aspect_Window::*)() const ) &Aspect_Window::IsMapped, "Returns True if the window <me> is opened and False if the window is closed.");
	cls_Aspect_Window.def("IsVirtual", (Standard_Boolean (Aspect_Window::*)() const ) &Aspect_Window::IsVirtual, "Returns True if the window <me> is virtual");
	cls_Aspect_Window.def("SetVirtual", (void (Aspect_Window::*)(const Standard_Boolean)) &Aspect_Window::SetVirtual, "Setup the virtual state", py::arg("theVirtual"));
	cls_Aspect_Window.def("Ratio", (Standard_Real (Aspect_Window::*)() const ) &Aspect_Window::Ratio, "Returns The Window RATIO equal to the physical WIDTH/HEIGHT dimensions");
	cls_Aspect_Window.def("Position", [](Aspect_Window &self, Standard_Integer & X1, Standard_Integer & Y1, Standard_Integer & X2, Standard_Integer & Y2){ self.Position(X1, Y1, X2, Y2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(X1, Y1, X2, Y2); }, "Returns The Window POSITION in PIXEL", py::arg("X1"), py::arg("Y1"), py::arg("X2"), py::arg("Y2"));
	cls_Aspect_Window.def("Size", [](Aspect_Window &self, Standard_Integer & Width, Standard_Integer & Height){ self.Size(Width, Height); return std::tuple<Standard_Integer &, Standard_Integer &>(Width, Height); }, "Returns The Window SIZE in PIXEL", py::arg("Width"), py::arg("Height"));
	cls_Aspect_Window.def("NativeHandle", (Aspect_Drawable (Aspect_Window::*)() const ) &Aspect_Window::NativeHandle, "Returns native Window handle (HWND on Windows, Window with Xlib, and so on)");
	cls_Aspect_Window.def("NativeParentHandle", (Aspect_Drawable (Aspect_Window::*)() const ) &Aspect_Window::NativeParentHandle, "Returns parent of native Window handle (HWND on Windows, Window with Xlib, and so on)");
	cls_Aspect_Window.def("NativeFBConfig", (Aspect_FBConfig (Aspect_Window::*)() const ) &Aspect_Window::NativeFBConfig, "Returns native Window FB config (GLXFBConfig on Xlib)");
	cls_Aspect_Window.def_static("get_type_name_", (const char * (*)()) &Aspect_Window::get_type_name, "None");
	cls_Aspect_Window.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_Window::get_type_descriptor, "None");
	cls_Aspect_Window.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_Window::*)() const ) &Aspect_Window::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_AspectLineDefinitionError.hxx
	py::class_<Aspect_AspectLineDefinitionError, opencascade::handle<Aspect_AspectLineDefinitionError>, Standard_OutOfRange> cls_Aspect_AspectLineDefinitionError(mod, "Aspect_AspectLineDefinitionError", "None");
	cls_Aspect_AspectLineDefinitionError.def(py::init<>());
	cls_Aspect_AspectLineDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Aspect_AspectLineDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_AspectLineDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_AspectLineDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_AspectLineDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_AspectLineDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_AspectLineDefinitionError> (*)(const Standard_CString)) &Aspect_AspectLineDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Aspect_AspectLineDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_AspectLineDefinitionError::get_type_name, "None");
	cls_Aspect_AspectLineDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_AspectLineDefinitionError::get_type_descriptor, "None");
	cls_Aspect_AspectLineDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_AspectLineDefinitionError::*)() const ) &Aspect_AspectLineDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_AspectMarkerDefinitionError.hxx
	py::class_<Aspect_AspectMarkerDefinitionError, opencascade::handle<Aspect_AspectMarkerDefinitionError>, Standard_OutOfRange> cls_Aspect_AspectMarkerDefinitionError(mod, "Aspect_AspectMarkerDefinitionError", "None");
	cls_Aspect_AspectMarkerDefinitionError.def(py::init<>());
	cls_Aspect_AspectMarkerDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Aspect_AspectMarkerDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_AspectMarkerDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_AspectMarkerDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_AspectMarkerDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_AspectMarkerDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_AspectMarkerDefinitionError> (*)(const Standard_CString)) &Aspect_AspectMarkerDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Aspect_AspectMarkerDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_AspectMarkerDefinitionError::get_type_name, "None");
	cls_Aspect_AspectMarkerDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_AspectMarkerDefinitionError::get_type_descriptor, "None");
	cls_Aspect_AspectMarkerDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_AspectMarkerDefinitionError::*)() const ) &Aspect_AspectMarkerDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_Grid.hxx
	py::class_<Aspect_Grid, opencascade::handle<Aspect_Grid>, Standard_Transient> cls_Aspect_Grid(mod, "Aspect_Grid", "None");
	cls_Aspect_Grid.def_static("get_type_name_", (const char * (*)()) &Aspect_Grid::get_type_name, "None");
	cls_Aspect_Grid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_Grid::get_type_descriptor, "None");
	cls_Aspect_Grid.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_Grid::*)() const ) &Aspect_Grid::DynamicType, "None");
	cls_Aspect_Grid.def("SetXOrigin", (void (Aspect_Grid::*)(const Standard_Real)) &Aspect_Grid::SetXOrigin, "defines the x Origin of the grid.", py::arg("anOrigin"));
	cls_Aspect_Grid.def("SetYOrigin", (void (Aspect_Grid::*)(const Standard_Real)) &Aspect_Grid::SetYOrigin, "defines the y Origin of the grid.", py::arg("anOrigin"));
	cls_Aspect_Grid.def("SetRotationAngle", (void (Aspect_Grid::*)(const Standard_Real)) &Aspect_Grid::SetRotationAngle, "defines the orientation of the grid.", py::arg("anAngle"));
	cls_Aspect_Grid.def("Rotate", (void (Aspect_Grid::*)(const Standard_Real)) &Aspect_Grid::Rotate, "Rotate the grid from a relative angle.", py::arg("anAngle"));
	cls_Aspect_Grid.def("Translate", (void (Aspect_Grid::*)(const Standard_Real, const Standard_Real)) &Aspect_Grid::Translate, "Translate the grid from a relative distance.", py::arg("aDx"), py::arg("aDy"));
	cls_Aspect_Grid.def("SetColors", (void (Aspect_Grid::*)(const Quantity_Color &, const Quantity_Color &)) &Aspect_Grid::SetColors, "Change the colors of the grid", py::arg("aColor"), py::arg("aTenthColor"));
	cls_Aspect_Grid.def("Hit", [](Aspect_Grid &self, const Standard_Real X, const Standard_Real Y, Standard_Real & gridX, Standard_Real & gridY){ self.Hit(X, Y, gridX, gridY); return std::tuple<Standard_Real &, Standard_Real &>(gridX, gridY); }, "returns the point of the grid the closest to the point X,Y if the grid is active. If the grid is not active returns X,Y.", py::arg("X"), py::arg("Y"), py::arg("gridX"), py::arg("gridY"));
	cls_Aspect_Grid.def("Compute", [](Aspect_Grid &self, const Standard_Real X, const Standard_Real Y, Standard_Real & gridX, Standard_Real & gridY){ self.Compute(X, Y, gridX, gridY); return std::tuple<Standard_Real &, Standard_Real &>(gridX, gridY); }, "returns the point of the grid the closest to the point X,Y", py::arg("X"), py::arg("Y"), py::arg("gridX"), py::arg("gridY"));
	cls_Aspect_Grid.def("Activate", (void (Aspect_Grid::*)()) &Aspect_Grid::Activate, "activates the grid. The Hit method will return gridx and gridx computed according to the steps of the grid.");
	cls_Aspect_Grid.def("Deactivate", (void (Aspect_Grid::*)()) &Aspect_Grid::Deactivate, "deactivates the grid. The hit method will return gridx and gridx as the enter value X & Y.");
	cls_Aspect_Grid.def("XOrigin", (Standard_Real (Aspect_Grid::*)() const ) &Aspect_Grid::XOrigin, "returns the x Origin of the grid.");
	cls_Aspect_Grid.def("YOrigin", (Standard_Real (Aspect_Grid::*)() const ) &Aspect_Grid::YOrigin, "returns the x Origin of the grid.");
	cls_Aspect_Grid.def("RotationAngle", (Standard_Real (Aspect_Grid::*)() const ) &Aspect_Grid::RotationAngle, "returns the x Angle of the grid.");
	cls_Aspect_Grid.def("IsActive", (Standard_Boolean (Aspect_Grid::*)() const ) &Aspect_Grid::IsActive, "Returns TRUE when the grid is active.");
	cls_Aspect_Grid.def("Colors", (void (Aspect_Grid::*)(Quantity_Color &, Quantity_Color &) const ) &Aspect_Grid::Colors, "Returns the colors of the grid.", py::arg("aColor"), py::arg("aTenthColor"));
	cls_Aspect_Grid.def("SetDrawMode", (void (Aspect_Grid::*)(const Aspect_GridDrawMode)) &Aspect_Grid::SetDrawMode, "Change the grid aspect.", py::arg("aDrawMode"));
	cls_Aspect_Grid.def("DrawMode", (Aspect_GridDrawMode (Aspect_Grid::*)() const ) &Aspect_Grid::DrawMode, "Returns the grid aspect.");
	cls_Aspect_Grid.def("Display", (void (Aspect_Grid::*)()) &Aspect_Grid::Display, "Display the grid at screen.");
	cls_Aspect_Grid.def("Erase", (void (Aspect_Grid::*)() const ) &Aspect_Grid::Erase, "Erase the grid from screen.");
	cls_Aspect_Grid.def("IsDisplayed", (Standard_Boolean (Aspect_Grid::*)() const ) &Aspect_Grid::IsDisplayed, "Returns TRUE when the grid is displayed at screen.");
	cls_Aspect_Grid.def("Init", (void (Aspect_Grid::*)()) &Aspect_Grid::Init, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_BadAccess.hxx
	py::class_<Aspect_BadAccess, opencascade::handle<Aspect_BadAccess>, Standard_DomainError> cls_Aspect_BadAccess(mod, "Aspect_BadAccess", "None");
	cls_Aspect_BadAccess.def(py::init<>());
	cls_Aspect_BadAccess.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Aspect_BadAccess.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_BadAccess::Raise, "None", py::arg("theMessage"));
	cls_Aspect_BadAccess.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_BadAccess::Raise, "None", py::arg("theMessage"));
	cls_Aspect_BadAccess.def_static("NewInstance_", (opencascade::handle<Aspect_BadAccess> (*)(const Standard_CString)) &Aspect_BadAccess::NewInstance, "None", py::arg("theMessage"));
	cls_Aspect_BadAccess.def_static("get_type_name_", (const char * (*)()) &Aspect_BadAccess::get_type_name, "None");
	cls_Aspect_BadAccess.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_BadAccess::get_type_descriptor, "None");
	cls_Aspect_BadAccess.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_BadAccess::*)() const ) &Aspect_BadAccess::DynamicType, "None");

	// Callback for Aspect_CircularGrid.
	class PyCallback_Aspect_CircularGrid : public Aspect_CircularGrid {
	public:
		using Aspect_CircularGrid::Aspect_CircularGrid;

		void Display() override { PYBIND11_OVERLOAD_PURE(void, Aspect_CircularGrid, Display, ); }
		void Erase() const  override { PYBIND11_OVERLOAD_PURE(void, Aspect_CircularGrid, Erase, ); }
		Standard_Boolean IsDisplayed() const  override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, Aspect_CircularGrid, IsDisplayed, ); }
		void UpdateDisplay() override { PYBIND11_OVERLOAD_PURE(void, Aspect_CircularGrid, UpdateDisplay, ); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_CircularGrid.hxx
	py::class_<Aspect_CircularGrid, opencascade::handle<Aspect_CircularGrid>, PyCallback_Aspect_CircularGrid, Aspect_Grid> cls_Aspect_CircularGrid(mod, "Aspect_CircularGrid", "None");
	cls_Aspect_CircularGrid.def(py::init<const Standard_Real, const Standard_Integer>(), py::arg("aRadiusStep"), py::arg("aDivisionNumber"));
	cls_Aspect_CircularGrid.def(py::init<const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("aRadiusStep"), py::arg("aDivisionNumber"), py::arg("XOrigin"));
	cls_Aspect_CircularGrid.def(py::init<const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("aRadiusStep"), py::arg("aDivisionNumber"), py::arg("XOrigin"), py::arg("anYOrigin"));
	cls_Aspect_CircularGrid.def(py::init<const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("aRadiusStep"), py::arg("aDivisionNumber"), py::arg("XOrigin"), py::arg("anYOrigin"), py::arg("aRotationAngle"));
	cls_Aspect_CircularGrid.def_static("get_type_name_", (const char * (*)()) &Aspect_CircularGrid::get_type_name, "None");
	cls_Aspect_CircularGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_CircularGrid::get_type_descriptor, "None");
	cls_Aspect_CircularGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_CircularGrid::*)() const ) &Aspect_CircularGrid::DynamicType, "None");
	cls_Aspect_CircularGrid.def("SetRadiusStep", (void (Aspect_CircularGrid::*)(const Standard_Real)) &Aspect_CircularGrid::SetRadiusStep, "defines the x step of the grid.", py::arg("aStep"));
	cls_Aspect_CircularGrid.def("SetDivisionNumber", (void (Aspect_CircularGrid::*)(const Standard_Integer)) &Aspect_CircularGrid::SetDivisionNumber, "defines the step of the grid.", py::arg("aNumber"));
	cls_Aspect_CircularGrid.def("SetGridValues", (void (Aspect_CircularGrid::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real)) &Aspect_CircularGrid::SetGridValues, "None", py::arg("XOrigin"), py::arg("YOrigin"), py::arg("RadiusStep"), py::arg("DivisionNumber"), py::arg("RotationAngle"));
	cls_Aspect_CircularGrid.def("Compute", [](Aspect_CircularGrid &self, const Standard_Real X, const Standard_Real Y, Standard_Real & gridX, Standard_Real & gridY){ self.Compute(X, Y, gridX, gridY); return std::tuple<Standard_Real &, Standard_Real &>(gridX, gridY); }, "returns the point of the grid the closest to the point X,Y", py::arg("X"), py::arg("Y"), py::arg("gridX"), py::arg("gridY"));
	cls_Aspect_CircularGrid.def("RadiusStep", (Standard_Real (Aspect_CircularGrid::*)() const ) &Aspect_CircularGrid::RadiusStep, "returns the x step of the grid.");
	cls_Aspect_CircularGrid.def("DivisionNumber", (Standard_Integer (Aspect_CircularGrid::*)() const ) &Aspect_CircularGrid::DivisionNumber, "returns the x step of the grid.");
	cls_Aspect_CircularGrid.def("Init", (void (Aspect_CircularGrid::*)()) &Aspect_CircularGrid::Init, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_DisplayConnection.hxx
	py::class_<Aspect_DisplayConnection, opencascade::handle<Aspect_DisplayConnection>, Standard_Transient> cls_Aspect_DisplayConnection(mod, "Aspect_DisplayConnection", "This class creates and provides connection with X server. Raises exception if can not connect to X server. On Windows and Mac OS X (in case when Cocoa used) platforms this class do nothing. WARRNING: Do not close display connection manualy!");
	cls_Aspect_DisplayConnection.def(py::init<>());
	cls_Aspect_DisplayConnection.def_static("get_type_name_", (const char * (*)()) &Aspect_DisplayConnection::get_type_name, "None");
	cls_Aspect_DisplayConnection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_DisplayConnection::get_type_descriptor, "None");
	cls_Aspect_DisplayConnection.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_DisplayConnection::*)() const ) &Aspect_DisplayConnection::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_DisplayConnectionDefinitionError.hxx
	py::class_<Aspect_DisplayConnectionDefinitionError, opencascade::handle<Aspect_DisplayConnectionDefinitionError>, Standard_OutOfRange> cls_Aspect_DisplayConnectionDefinitionError(mod, "Aspect_DisplayConnectionDefinitionError", "None");
	cls_Aspect_DisplayConnectionDefinitionError.def(py::init<>());
	cls_Aspect_DisplayConnectionDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Aspect_DisplayConnectionDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_DisplayConnectionDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_DisplayConnectionDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_DisplayConnectionDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_DisplayConnectionDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_DisplayConnectionDefinitionError> (*)(const Standard_CString)) &Aspect_DisplayConnectionDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Aspect_DisplayConnectionDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_DisplayConnectionDefinitionError::get_type_name, "None");
	cls_Aspect_DisplayConnectionDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_DisplayConnectionDefinitionError::get_type_descriptor, "None");
	cls_Aspect_DisplayConnectionDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_DisplayConnectionDefinitionError::*)() const ) &Aspect_DisplayConnectionDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_DriverDefinitionError.hxx
	py::class_<Aspect_DriverDefinitionError, opencascade::handle<Aspect_DriverDefinitionError>, Standard_OutOfRange> cls_Aspect_DriverDefinitionError(mod, "Aspect_DriverDefinitionError", "None");
	cls_Aspect_DriverDefinitionError.def(py::init<>());
	cls_Aspect_DriverDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Aspect_DriverDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_DriverDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_DriverDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_DriverDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_DriverDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_DriverDefinitionError> (*)(const Standard_CString)) &Aspect_DriverDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Aspect_DriverDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_DriverDefinitionError::get_type_name, "None");
	cls_Aspect_DriverDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_DriverDefinitionError::get_type_descriptor, "None");
	cls_Aspect_DriverDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_DriverDefinitionError::*)() const ) &Aspect_DriverDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_GraphicDeviceDefinitionError.hxx
	py::class_<Aspect_GraphicDeviceDefinitionError, opencascade::handle<Aspect_GraphicDeviceDefinitionError>, Standard_OutOfRange> cls_Aspect_GraphicDeviceDefinitionError(mod, "Aspect_GraphicDeviceDefinitionError", "None");
	cls_Aspect_GraphicDeviceDefinitionError.def(py::init<>());
	cls_Aspect_GraphicDeviceDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Aspect_GraphicDeviceDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_GraphicDeviceDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_GraphicDeviceDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_GraphicDeviceDefinitionError::Raise, "None", py::arg("theMessage"));
	cls_Aspect_GraphicDeviceDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_GraphicDeviceDefinitionError> (*)(const Standard_CString)) &Aspect_GraphicDeviceDefinitionError::NewInstance, "None", py::arg("theMessage"));
	cls_Aspect_GraphicDeviceDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_GraphicDeviceDefinitionError::get_type_name, "None");
	cls_Aspect_GraphicDeviceDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_GraphicDeviceDefinitionError::get_type_descriptor, "None");
	cls_Aspect_GraphicDeviceDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_GraphicDeviceDefinitionError::*)() const ) &Aspect_GraphicDeviceDefinitionError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_NeutralWindow.hxx
	py::class_<Aspect_NeutralWindow, opencascade::handle<Aspect_NeutralWindow>, Aspect_Window> cls_Aspect_NeutralWindow(mod, "Aspect_NeutralWindow", "Defines a platform-neutral window. This class is intended to be used in context when window management (including OpenGL context creation) is performed on application side (e.g. using external framework).");
	cls_Aspect_NeutralWindow.def(py::init<>());
	cls_Aspect_NeutralWindow.def_static("get_type_name_", (const char * (*)()) &Aspect_NeutralWindow::get_type_name, "None");
	cls_Aspect_NeutralWindow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_NeutralWindow::get_type_descriptor, "None");
	cls_Aspect_NeutralWindow.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_NeutralWindow::*)() const ) &Aspect_NeutralWindow::DynamicType, "None");
	cls_Aspect_NeutralWindow.def("NativeHandle", (Aspect_Drawable (Aspect_NeutralWindow::*)() const ) &Aspect_NeutralWindow::NativeHandle, "Return native handle of this drawable.");
	cls_Aspect_NeutralWindow.def("NativeParentHandle", (Aspect_Drawable (Aspect_NeutralWindow::*)() const ) &Aspect_NeutralWindow::NativeParentHandle, "Return native handle of the parent drawable.");
	cls_Aspect_NeutralWindow.def("NativeFBConfig", (Aspect_FBConfig (Aspect_NeutralWindow::*)() const ) &Aspect_NeutralWindow::NativeFBConfig, "Return FBConfig.");
	cls_Aspect_NeutralWindow.def("SetNativeHandle", (Standard_Boolean (Aspect_NeutralWindow::*)(Aspect_Drawable)) &Aspect_NeutralWindow::SetNativeHandle, "Set native handle.", py::arg("theWindow"));
	cls_Aspect_NeutralWindow.def("SetNativeHandles", (Standard_Boolean (Aspect_NeutralWindow::*)(Aspect_Drawable, Aspect_Drawable, Aspect_FBConfig)) &Aspect_NeutralWindow::SetNativeHandles, "Set native handles.", py::arg("theWindow"), py::arg("theParentWindow"), py::arg("theFbConfig"));
	cls_Aspect_NeutralWindow.def("IsMapped", (Standard_Boolean (Aspect_NeutralWindow::*)() const ) &Aspect_NeutralWindow::IsMapped, "Return true if window is not hidden.");
	cls_Aspect_NeutralWindow.def("Map", (void (Aspect_NeutralWindow::*)() const ) &Aspect_NeutralWindow::Map, "Change window mapped flag to TRUE.");
	cls_Aspect_NeutralWindow.def("Unmap", (void (Aspect_NeutralWindow::*)() const ) &Aspect_NeutralWindow::Unmap, "Change window mapped flag to FALSE.");
	cls_Aspect_NeutralWindow.def("DoResize", (Aspect_TypeOfResize (Aspect_NeutralWindow::*)() const ) &Aspect_NeutralWindow::DoResize, "Resize window - do nothing.");
	cls_Aspect_NeutralWindow.def("DoMapping", (Standard_Boolean (Aspect_NeutralWindow::*)() const ) &Aspect_NeutralWindow::DoMapping, "Map window - do nothing.");
	cls_Aspect_NeutralWindow.def("Ratio", (Standard_Real (Aspect_NeutralWindow::*)() const ) &Aspect_NeutralWindow::Ratio, "Returns window ratio equal to the physical width/height dimensions.");
	cls_Aspect_NeutralWindow.def("Position", [](Aspect_NeutralWindow &self, Standard_Integer & theX1, Standard_Integer & theY1, Standard_Integer & theX2, Standard_Integer & theY2){ self.Position(theX1, theY1, theX2, theY2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(theX1, theY1, theX2, theY2); }, "Return the window position.", py::arg("theX1"), py::arg("theY1"), py::arg("theX2"), py::arg("theY2"));
	cls_Aspect_NeutralWindow.def("SetPosition", (Standard_Boolean (Aspect_NeutralWindow::*)(Standard_Integer, Standard_Integer)) &Aspect_NeutralWindow::SetPosition, "Set the window position.", py::arg("theX1"), py::arg("theY1"));
	cls_Aspect_NeutralWindow.def("SetPosition", (Standard_Boolean (Aspect_NeutralWindow::*)(Standard_Integer, Standard_Integer, Standard_Integer, Standard_Integer)) &Aspect_NeutralWindow::SetPosition, "Set the window position.", py::arg("theX1"), py::arg("theY1"), py::arg("theX2"), py::arg("theY2"));
	cls_Aspect_NeutralWindow.def("Size", [](Aspect_NeutralWindow &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.Size(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "Return the window size.", py::arg("theWidth"), py::arg("theHeight"));
	cls_Aspect_NeutralWindow.def("SetSize", (Standard_Boolean (Aspect_NeutralWindow::*)(const Standard_Integer, const Standard_Integer)) &Aspect_NeutralWindow::SetSize, "Set the window size.", py::arg("theWidth"), py::arg("theHeight"));

	// Callback for Aspect_RectangularGrid.
	class PyCallback_Aspect_RectangularGrid : public Aspect_RectangularGrid {
	public:
		using Aspect_RectangularGrid::Aspect_RectangularGrid;

		void Display() override { PYBIND11_OVERLOAD_PURE(void, Aspect_RectangularGrid, Display, ); }
		void Erase() const  override { PYBIND11_OVERLOAD_PURE(void, Aspect_RectangularGrid, Erase, ); }
		Standard_Boolean IsDisplayed() const  override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, Aspect_RectangularGrid, IsDisplayed, ); }
		void UpdateDisplay() override { PYBIND11_OVERLOAD_PURE(void, Aspect_RectangularGrid, UpdateDisplay, ); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_RectangularGrid.hxx
	py::class_<Aspect_RectangularGrid, opencascade::handle<Aspect_RectangularGrid>, PyCallback_Aspect_RectangularGrid, Aspect_Grid> cls_Aspect_RectangularGrid(mod, "Aspect_RectangularGrid", "None");
	cls_Aspect_RectangularGrid.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("aXStep"), py::arg("aYStep"));
	cls_Aspect_RectangularGrid.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("aXStep"), py::arg("aYStep"), py::arg("anXOrigin"));
	cls_Aspect_RectangularGrid.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("aXStep"), py::arg("aYStep"), py::arg("anXOrigin"), py::arg("anYOrigin"));
	cls_Aspect_RectangularGrid.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("aXStep"), py::arg("aYStep"), py::arg("anXOrigin"), py::arg("anYOrigin"), py::arg("aFirstAngle"));
	cls_Aspect_RectangularGrid.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("aXStep"), py::arg("aYStep"), py::arg("anXOrigin"), py::arg("anYOrigin"), py::arg("aFirstAngle"), py::arg("aSecondAngle"));
	cls_Aspect_RectangularGrid.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("aXStep"), py::arg("aYStep"), py::arg("anXOrigin"), py::arg("anYOrigin"), py::arg("aFirstAngle"), py::arg("aSecondAngle"), py::arg("aRotationAngle"));
	cls_Aspect_RectangularGrid.def_static("get_type_name_", (const char * (*)()) &Aspect_RectangularGrid::get_type_name, "None");
	cls_Aspect_RectangularGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_RectangularGrid::get_type_descriptor, "None");
	cls_Aspect_RectangularGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_RectangularGrid::*)() const ) &Aspect_RectangularGrid::DynamicType, "None");
	cls_Aspect_RectangularGrid.def("SetXStep", (void (Aspect_RectangularGrid::*)(const Standard_Real)) &Aspect_RectangularGrid::SetXStep, "defines the x step of the grid.", py::arg("aStep"));
	cls_Aspect_RectangularGrid.def("SetYStep", (void (Aspect_RectangularGrid::*)(const Standard_Real)) &Aspect_RectangularGrid::SetYStep, "defines the y step of the grid.", py::arg("aStep"));
	cls_Aspect_RectangularGrid.def("SetAngle", (void (Aspect_RectangularGrid::*)(const Standard_Real, const Standard_Real)) &Aspect_RectangularGrid::SetAngle, "defines the angle of the second network the fist angle is given relatively to the horizontal. the second angle is given relatively to the vertical.", py::arg("anAngle1"), py::arg("anAngle2"));
	cls_Aspect_RectangularGrid.def("SetGridValues", (void (Aspect_RectangularGrid::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Aspect_RectangularGrid::SetGridValues, "None", py::arg("XOrigin"), py::arg("YOrigin"), py::arg("XStep"), py::arg("YStep"), py::arg("RotationAngle"));
	cls_Aspect_RectangularGrid.def("Compute", [](Aspect_RectangularGrid &self, const Standard_Real X, const Standard_Real Y, Standard_Real & gridX, Standard_Real & gridY){ self.Compute(X, Y, gridX, gridY); return std::tuple<Standard_Real &, Standard_Real &>(gridX, gridY); }, "returns the point of the grid the closest to the point X,Y", py::arg("X"), py::arg("Y"), py::arg("gridX"), py::arg("gridY"));
	cls_Aspect_RectangularGrid.def("XStep", (Standard_Real (Aspect_RectangularGrid::*)() const ) &Aspect_RectangularGrid::XStep, "returns the x step of the grid.");
	cls_Aspect_RectangularGrid.def("YStep", (Standard_Real (Aspect_RectangularGrid::*)() const ) &Aspect_RectangularGrid::YStep, "returns the x step of the grid.");
	cls_Aspect_RectangularGrid.def("FirstAngle", (Standard_Real (Aspect_RectangularGrid::*)() const ) &Aspect_RectangularGrid::FirstAngle, "returns the x Angle of the grid, relatively to the horizontal.");
	cls_Aspect_RectangularGrid.def("SecondAngle", (Standard_Real (Aspect_RectangularGrid::*)() const ) &Aspect_RectangularGrid::SecondAngle, "returns the y Angle of the grid, relatively to the vertical.");
	cls_Aspect_RectangularGrid.def("Init", (void (Aspect_RectangularGrid::*)()) &Aspect_RectangularGrid::Init, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_XWD.hxx
	py::class_<_xwd_file_header, std::unique_ptr<_xwd_file_header, Deleter<_xwd_file_header>>> cls__xwd_file_header(mod, "_xwd_file_header", "None");
	cls__xwd_file_header.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_XWD.hxx
	py::class_<_xcolor, std::unique_ptr<_xcolor, Deleter<_xcolor>>> cls__xcolor(mod, "_xcolor", "None");
	cls__xcolor.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_PolygonOffsetMode.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_Handle.hxx
	other_mod = py::module::import("OCCT.Standard");
	if (py::hasattr(other_mod, "Standard_Address")) {
		mod.attr("HANDLE") = other_mod.attr("Standard_Address");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_Handle.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_RenderingContext.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_FBConfig.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_Drawable.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_SequenceOfColor.hxx
	bind_NCollection_Sequence<Quantity_Color>(mod, "Aspect_SequenceOfColor");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_Display.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_XWD.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_XWD.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Aspect_XWD.hxx

}
