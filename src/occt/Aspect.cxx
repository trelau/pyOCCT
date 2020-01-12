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

#ifndef _WIN32
#include <xTypes.h>
#endif

#include <Aspect_TypeOfLine.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <Aspect_TypeOfDeflection.hxx>
#include <Aspect_TypeOfHighlightMethod.hxx>
#include <Aspect_InteriorStyle.hxx>
#include <Aspect_TypeOfDisplayText.hxx>
#include <Aspect_TypeOfStyleText.hxx>
#include <Aspect_HatchStyle.hxx>
#include <Aspect_TypeOfTriedronPosition.hxx>
#include <Aspect_VKey.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <Aspect_FillMethod.hxx>
#include <Aspect_TypeOfResize.hxx>
#include <Aspect_TypeOfFacingModel.hxx>
#include <Aspect_TypeOfColorScaleData.hxx>
#include <Aspect_TypeOfColorScalePosition.hxx>
#include <Aspect_GridDrawMode.hxx>
#include <Aspect_GridType.hxx>
#include <Aspect_XAtom.hxx>
#include <Aspect_TypeOfColorScaleOrientation.hxx>
#include <Aspect_WidthOfLine.hxx>
#include <Aspect_VKeyFlags.hxx>
#include <Aspect_PolygonOffsetMode.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Aspect_GenId.hxx>
#include <Aspect_Handle.hxx>
#include <Aspect_RenderingContext.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_Background.hxx>
#include <Aspect_GradientBackground.hxx>
#include <Aspect_FBConfig.hxx>
#include <Aspect_Drawable.hxx>
#include <Standard_Transient.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Standard_Std.hxx>
#include <Aspect_Window.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Sequence.hxx>
#include <Aspect_SequenceOfColor.hxx>
#include <Aspect_VKeySet.hxx>
#include <Standard_Mutex.hxx>
#include <NCollection_Array1.hxx>
#include <NCollection_Vec2.hxx>
#include <Aspect_Touch.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <Aspect_TouchMap.hxx>
#include <Aspect_ScrollDelta.hxx>
#include <Standard_OutOfRange.hxx>
#include <Aspect_AspectFillAreaDefinitionError.hxx>
#include <Standard_SStream.hxx>
#include <Aspect_AspectLineDefinitionError.hxx>
#include <Aspect_AspectMarkerDefinitionError.hxx>
#include <Aspect_Grid.hxx>
#include <Aspect_CircularGrid.hxx>
#include <Aspect_Display.hxx>
#include <Aspect_DisplayConnectionDefinitionError.hxx>
#include <Aspect_GraphicDeviceDefinitionError.hxx>
#include <Aspect_IdentDefinitionError.hxx>
#include <Aspect_NeutralWindow.hxx>
#include <Aspect_RectangularGrid.hxx>
#include <Aspect_WindowDefinitionError.hxx>
#include <Aspect_WindowError.hxx>
#include <Aspect_XWD.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>

PYBIND11_MODULE(Aspect, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");

// ENUM: ASPECT_TYPEOFLINE
py::enum_<Aspect_TypeOfLine>(mod, "Aspect_TypeOfLine", "Definition of line types")
	.value("Aspect_TOL_EMPTY", Aspect_TypeOfLine::Aspect_TOL_EMPTY)
	.value("Aspect_TOL_SOLID", Aspect_TypeOfLine::Aspect_TOL_SOLID)
	.value("Aspect_TOL_DASH", Aspect_TypeOfLine::Aspect_TOL_DASH)
	.value("Aspect_TOL_DOT", Aspect_TypeOfLine::Aspect_TOL_DOT)
	.value("Aspect_TOL_DOTDASH", Aspect_TypeOfLine::Aspect_TOL_DOTDASH)
	.value("Aspect_TOL_USERDEFINED", Aspect_TypeOfLine::Aspect_TOL_USERDEFINED)
	.export_values();


// ENUM: ASPECT_TYPEOFMARKER
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


// ENUM: ASPECT_TYPEOFDEFLECTION
py::enum_<Aspect_TypeOfDeflection>(mod, "Aspect_TypeOfDeflection", "Defines if the maximal chordial deflection used when drawing an object is absolute or relative to the size of the object.")
	.value("Aspect_TOD_RELATIVE", Aspect_TypeOfDeflection::Aspect_TOD_RELATIVE)
	.value("Aspect_TOD_ABSOLUTE", Aspect_TypeOfDeflection::Aspect_TOD_ABSOLUTE)
	.export_values();


// ENUM: ASPECT_TYPEOFHIGHLIGHTMETHOD
py::enum_<Aspect_TypeOfHighlightMethod>(mod, "Aspect_TypeOfHighlightMethod", "Definition of a highlight method")
	.value("Aspect_TOHM_COLOR", Aspect_TypeOfHighlightMethod::Aspect_TOHM_COLOR)
	.value("Aspect_TOHM_BOUNDBOX", Aspect_TypeOfHighlightMethod::Aspect_TOHM_BOUNDBOX)
	.export_values();


// ENUM: ASPECT_INTERIORSTYLE
py::enum_<Aspect_InteriorStyle>(mod, "Aspect_InteriorStyle", "Interior types for primitive faces.")
	.value("Aspect_IS_EMPTY", Aspect_InteriorStyle::Aspect_IS_EMPTY)
	.value("Aspect_IS_SOLID", Aspect_InteriorStyle::Aspect_IS_SOLID)
	.value("Aspect_IS_HATCH", Aspect_InteriorStyle::Aspect_IS_HATCH)
	.value("Aspect_IS_HIDDENLINE", Aspect_InteriorStyle::Aspect_IS_HIDDENLINE)
	.value("Aspect_IS_POINT", Aspect_InteriorStyle::Aspect_IS_POINT)
	.value("Aspect_IS_HOLLOW", Aspect_InteriorStyle::Aspect_IS_HOLLOW)
	.export_values();


// ENUM: ASPECT_TYPEOFDISPLAYTEXT
py::enum_<Aspect_TypeOfDisplayText>(mod, "Aspect_TypeOfDisplayText", "Define the display type of the text.")
	.value("Aspect_TODT_NORMAL", Aspect_TypeOfDisplayText::Aspect_TODT_NORMAL)
	.value("Aspect_TODT_SUBTITLE", Aspect_TypeOfDisplayText::Aspect_TODT_SUBTITLE)
	.value("Aspect_TODT_DEKALE", Aspect_TypeOfDisplayText::Aspect_TODT_DEKALE)
	.value("Aspect_TODT_BLEND", Aspect_TypeOfDisplayText::Aspect_TODT_BLEND)
	.value("Aspect_TODT_DIMENSION", Aspect_TypeOfDisplayText::Aspect_TODT_DIMENSION)
	.value("Aspect_TODT_SHADOW", Aspect_TypeOfDisplayText::Aspect_TODT_SHADOW)
	.export_values();


// ENUM: ASPECT_TYPEOFSTYLETEXT
py::enum_<Aspect_TypeOfStyleText>(mod, "Aspect_TypeOfStyleText", "Define the style of the text.")
	.value("Aspect_TOST_NORMAL", Aspect_TypeOfStyleText::Aspect_TOST_NORMAL)
	.value("Aspect_TOST_ANNOTATION", Aspect_TypeOfStyleText::Aspect_TOST_ANNOTATION)
	.export_values();


// ENUM: ASPECT_HATCHSTYLE
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


// ENUM: ASPECT_TYPEOFTRIEDRONPOSITION
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


// ENUM: ASPECT_VKEYBASIC
py::enum_<Aspect_VKeyBasic>(mod, "Aspect_VKeyBasic", "Enumeration defining virtual keys irrelevant to current keyboard layout for simplified hot-keys management logic.")
	.value("Aspect_VKey_UNKNOWN", Aspect_VKeyBasic::Aspect_VKey_UNKNOWN)
	.value("Aspect_VKey_A", Aspect_VKeyBasic::Aspect_VKey_A)
	.value("Aspect_VKey_B", Aspect_VKeyBasic::Aspect_VKey_B)
	.value("Aspect_VKey_C", Aspect_VKeyBasic::Aspect_VKey_C)
	.value("Aspect_VKey_D", Aspect_VKeyBasic::Aspect_VKey_D)
	.value("Aspect_VKey_E", Aspect_VKeyBasic::Aspect_VKey_E)
	.value("Aspect_VKey_F", Aspect_VKeyBasic::Aspect_VKey_F)
	.value("Aspect_VKey_G", Aspect_VKeyBasic::Aspect_VKey_G)
	.value("Aspect_VKey_H", Aspect_VKeyBasic::Aspect_VKey_H)
	.value("Aspect_VKey_I", Aspect_VKeyBasic::Aspect_VKey_I)
	.value("Aspect_VKey_J", Aspect_VKeyBasic::Aspect_VKey_J)
	.value("Aspect_VKey_K", Aspect_VKeyBasic::Aspect_VKey_K)
	.value("Aspect_VKey_L", Aspect_VKeyBasic::Aspect_VKey_L)
	.value("Aspect_VKey_M", Aspect_VKeyBasic::Aspect_VKey_M)
	.value("Aspect_VKey_N", Aspect_VKeyBasic::Aspect_VKey_N)
	.value("Aspect_VKey_O", Aspect_VKeyBasic::Aspect_VKey_O)
	.value("Aspect_VKey_P", Aspect_VKeyBasic::Aspect_VKey_P)
	.value("Aspect_VKey_Q", Aspect_VKeyBasic::Aspect_VKey_Q)
	.value("Aspect_VKey_R", Aspect_VKeyBasic::Aspect_VKey_R)
	.value("Aspect_VKey_S", Aspect_VKeyBasic::Aspect_VKey_S)
	.value("Aspect_VKey_T", Aspect_VKeyBasic::Aspect_VKey_T)
	.value("Aspect_VKey_U", Aspect_VKeyBasic::Aspect_VKey_U)
	.value("Aspect_VKey_V", Aspect_VKeyBasic::Aspect_VKey_V)
	.value("Aspect_VKey_W", Aspect_VKeyBasic::Aspect_VKey_W)
	.value("Aspect_VKey_X", Aspect_VKeyBasic::Aspect_VKey_X)
	.value("Aspect_VKey_Y", Aspect_VKeyBasic::Aspect_VKey_Y)
	.value("Aspect_VKey_Z", Aspect_VKeyBasic::Aspect_VKey_Z)
	.value("Aspect_VKey_0", Aspect_VKeyBasic::Aspect_VKey_0)
	.value("Aspect_VKey_1", Aspect_VKeyBasic::Aspect_VKey_1)
	.value("Aspect_VKey_2", Aspect_VKeyBasic::Aspect_VKey_2)
	.value("Aspect_VKey_3", Aspect_VKeyBasic::Aspect_VKey_3)
	.value("Aspect_VKey_4", Aspect_VKeyBasic::Aspect_VKey_4)
	.value("Aspect_VKey_5", Aspect_VKeyBasic::Aspect_VKey_5)
	.value("Aspect_VKey_6", Aspect_VKeyBasic::Aspect_VKey_6)
	.value("Aspect_VKey_7", Aspect_VKeyBasic::Aspect_VKey_7)
	.value("Aspect_VKey_8", Aspect_VKeyBasic::Aspect_VKey_8)
	.value("Aspect_VKey_9", Aspect_VKeyBasic::Aspect_VKey_9)
	.value("Aspect_VKey_F1", Aspect_VKeyBasic::Aspect_VKey_F1)
	.value("Aspect_VKey_F2", Aspect_VKeyBasic::Aspect_VKey_F2)
	.value("Aspect_VKey_F3", Aspect_VKeyBasic::Aspect_VKey_F3)
	.value("Aspect_VKey_F4", Aspect_VKeyBasic::Aspect_VKey_F4)
	.value("Aspect_VKey_F5", Aspect_VKeyBasic::Aspect_VKey_F5)
	.value("Aspect_VKey_F6", Aspect_VKeyBasic::Aspect_VKey_F6)
	.value("Aspect_VKey_F7", Aspect_VKeyBasic::Aspect_VKey_F7)
	.value("Aspect_VKey_F8", Aspect_VKeyBasic::Aspect_VKey_F8)
	.value("Aspect_VKey_F9", Aspect_VKeyBasic::Aspect_VKey_F9)
	.value("Aspect_VKey_F10", Aspect_VKeyBasic::Aspect_VKey_F10)
	.value("Aspect_VKey_F11", Aspect_VKeyBasic::Aspect_VKey_F11)
	.value("Aspect_VKey_F12", Aspect_VKeyBasic::Aspect_VKey_F12)
	.value("Aspect_VKey_Up", Aspect_VKeyBasic::Aspect_VKey_Up)
	.value("Aspect_VKey_Down", Aspect_VKeyBasic::Aspect_VKey_Down)
	.value("Aspect_VKey_Left", Aspect_VKeyBasic::Aspect_VKey_Left)
	.value("Aspect_VKey_Right", Aspect_VKeyBasic::Aspect_VKey_Right)
	.value("Aspect_VKey_Plus", Aspect_VKeyBasic::Aspect_VKey_Plus)
	.value("Aspect_VKey_Minus", Aspect_VKeyBasic::Aspect_VKey_Minus)
	.value("Aspect_VKey_Equal", Aspect_VKeyBasic::Aspect_VKey_Equal)
	.value("Aspect_VKey_PageUp", Aspect_VKeyBasic::Aspect_VKey_PageUp)
	.value("Aspect_VKey_PageDown", Aspect_VKeyBasic::Aspect_VKey_PageDown)
	.value("Aspect_VKey_Home", Aspect_VKeyBasic::Aspect_VKey_Home)
	.value("Aspect_VKey_End", Aspect_VKeyBasic::Aspect_VKey_End)
	.value("Aspect_VKey_Escape", Aspect_VKeyBasic::Aspect_VKey_Escape)
	.value("Aspect_VKey_Back", Aspect_VKeyBasic::Aspect_VKey_Back)
	.value("Aspect_VKey_Enter", Aspect_VKeyBasic::Aspect_VKey_Enter)
	.value("Aspect_VKey_Backspace", Aspect_VKeyBasic::Aspect_VKey_Backspace)
	.value("Aspect_VKey_Space", Aspect_VKeyBasic::Aspect_VKey_Space)
	.value("Aspect_VKey_Delete", Aspect_VKeyBasic::Aspect_VKey_Delete)
	.value("Aspect_VKey_Tilde", Aspect_VKeyBasic::Aspect_VKey_Tilde)
	.value("Aspect_VKey_Tab", Aspect_VKeyBasic::Aspect_VKey_Tab)
	.value("Aspect_VKey_Comma", Aspect_VKeyBasic::Aspect_VKey_Comma)
	.value("Aspect_VKey_Period", Aspect_VKeyBasic::Aspect_VKey_Period)
	.value("Aspect_VKey_Semicolon", Aspect_VKeyBasic::Aspect_VKey_Semicolon)
	.value("Aspect_VKey_Slash", Aspect_VKeyBasic::Aspect_VKey_Slash)
	.value("Aspect_VKey_BracketLeft", Aspect_VKeyBasic::Aspect_VKey_BracketLeft)
	.value("Aspect_VKey_Backslash", Aspect_VKeyBasic::Aspect_VKey_Backslash)
	.value("Aspect_VKey_BracketRight", Aspect_VKeyBasic::Aspect_VKey_BracketRight)
	.value("Aspect_VKey_Apostrophe", Aspect_VKeyBasic::Aspect_VKey_Apostrophe)
	.value("Aspect_VKey_Numlock", Aspect_VKeyBasic::Aspect_VKey_Numlock)
	.value("Aspect_VKey_Scroll", Aspect_VKeyBasic::Aspect_VKey_Scroll)
	.value("Aspect_VKey_Numpad0", Aspect_VKeyBasic::Aspect_VKey_Numpad0)
	.value("Aspect_VKey_Numpad1", Aspect_VKeyBasic::Aspect_VKey_Numpad1)
	.value("Aspect_VKey_Numpad2", Aspect_VKeyBasic::Aspect_VKey_Numpad2)
	.value("Aspect_VKey_Numpad3", Aspect_VKeyBasic::Aspect_VKey_Numpad3)
	.value("Aspect_VKey_Numpad4", Aspect_VKeyBasic::Aspect_VKey_Numpad4)
	.value("Aspect_VKey_Numpad5", Aspect_VKeyBasic::Aspect_VKey_Numpad5)
	.value("Aspect_VKey_Numpad6", Aspect_VKeyBasic::Aspect_VKey_Numpad6)
	.value("Aspect_VKey_Numpad7", Aspect_VKeyBasic::Aspect_VKey_Numpad7)
	.value("Aspect_VKey_Numpad8", Aspect_VKeyBasic::Aspect_VKey_Numpad8)
	.value("Aspect_VKey_Numpad9", Aspect_VKeyBasic::Aspect_VKey_Numpad9)
	.value("Aspect_VKey_NumpadMultiply", Aspect_VKeyBasic::Aspect_VKey_NumpadMultiply)
	.value("Aspect_VKey_NumpadAdd", Aspect_VKeyBasic::Aspect_VKey_NumpadAdd)
	.value("Aspect_VKey_NumpadSubtract", Aspect_VKeyBasic::Aspect_VKey_NumpadSubtract)
	.value("Aspect_VKey_NumpadDivide", Aspect_VKeyBasic::Aspect_VKey_NumpadDivide)
	.value("Aspect_VKey_MediaNextTrack", Aspect_VKeyBasic::Aspect_VKey_MediaNextTrack)
	.value("Aspect_VKey_MediaPreviousTrack", Aspect_VKeyBasic::Aspect_VKey_MediaPreviousTrack)
	.value("Aspect_VKey_MediaStop", Aspect_VKeyBasic::Aspect_VKey_MediaStop)
	.value("Aspect_VKey_MediaPlayPause", Aspect_VKeyBasic::Aspect_VKey_MediaPlayPause)
	.value("Aspect_VKey_VolumeMute", Aspect_VKeyBasic::Aspect_VKey_VolumeMute)
	.value("Aspect_VKey_VolumeDown", Aspect_VKeyBasic::Aspect_VKey_VolumeDown)
	.value("Aspect_VKey_VolumeUp", Aspect_VKeyBasic::Aspect_VKey_VolumeUp)
	.value("Aspect_VKey_BrowserBack", Aspect_VKeyBasic::Aspect_VKey_BrowserBack)
	.value("Aspect_VKey_BrowserForward", Aspect_VKeyBasic::Aspect_VKey_BrowserForward)
	.value("Aspect_VKey_BrowserRefresh", Aspect_VKeyBasic::Aspect_VKey_BrowserRefresh)
	.value("Aspect_VKey_BrowserStop", Aspect_VKeyBasic::Aspect_VKey_BrowserStop)
	.value("Aspect_VKey_BrowserSearch", Aspect_VKeyBasic::Aspect_VKey_BrowserSearch)
	.value("Aspect_VKey_BrowserFavorites", Aspect_VKeyBasic::Aspect_VKey_BrowserFavorites)
	.value("Aspect_VKey_BrowserHome", Aspect_VKeyBasic::Aspect_VKey_BrowserHome)
	.value("Aspect_VKey_Shift", Aspect_VKeyBasic::Aspect_VKey_Shift)
	.value("Aspect_VKey_Control", Aspect_VKeyBasic::Aspect_VKey_Control)
	.value("Aspect_VKey_Alt", Aspect_VKeyBasic::Aspect_VKey_Alt)
	.value("Aspect_VKey_Menu", Aspect_VKeyBasic::Aspect_VKey_Menu)
	.value("Aspect_VKey_Meta", Aspect_VKeyBasic::Aspect_VKey_Meta)
	.value("Aspect_VKey_NavInteract", Aspect_VKeyBasic::Aspect_VKey_NavInteract)
	.value("Aspect_VKey_NavForward", Aspect_VKeyBasic::Aspect_VKey_NavForward)
	.value("Aspect_VKey_NavBackward", Aspect_VKeyBasic::Aspect_VKey_NavBackward)
	.value("Aspect_VKey_NavSlideLeft", Aspect_VKeyBasic::Aspect_VKey_NavSlideLeft)
	.value("Aspect_VKey_NavSlideRight", Aspect_VKeyBasic::Aspect_VKey_NavSlideRight)
	.value("Aspect_VKey_NavSlideUp", Aspect_VKeyBasic::Aspect_VKey_NavSlideUp)
	.value("Aspect_VKey_NavSlideDown", Aspect_VKeyBasic::Aspect_VKey_NavSlideDown)
	.value("Aspect_VKey_NavRollCCW", Aspect_VKeyBasic::Aspect_VKey_NavRollCCW)
	.value("Aspect_VKey_NavRollCW", Aspect_VKeyBasic::Aspect_VKey_NavRollCW)
	.value("Aspect_VKey_NavLookLeft", Aspect_VKeyBasic::Aspect_VKey_NavLookLeft)
	.value("Aspect_VKey_NavLookRight", Aspect_VKeyBasic::Aspect_VKey_NavLookRight)
	.value("Aspect_VKey_NavLookUp", Aspect_VKeyBasic::Aspect_VKey_NavLookUp)
	.value("Aspect_VKey_NavLookDown", Aspect_VKeyBasic::Aspect_VKey_NavLookDown)
	.value("Aspect_VKey_NavCrouch", Aspect_VKeyBasic::Aspect_VKey_NavCrouch)
	.value("Aspect_VKey_NavJump", Aspect_VKeyBasic::Aspect_VKey_NavJump)
	.value("Aspect_VKey_NavThrustForward", Aspect_VKeyBasic::Aspect_VKey_NavThrustForward)
	.value("Aspect_VKey_NavThrustBackward", Aspect_VKeyBasic::Aspect_VKey_NavThrustBackward)
	.value("Aspect_VKey_NavThrustStop", Aspect_VKeyBasic::Aspect_VKey_NavThrustStop)
	.value("Aspect_VKey_NavSpeedIncrease", Aspect_VKeyBasic::Aspect_VKey_NavSpeedIncrease)
	.value("Aspect_VKey_NavSpeedDecrease", Aspect_VKeyBasic::Aspect_VKey_NavSpeedDecrease)
	.export_values();


// ENUM: ASPECT_GRADIENTFILLMETHOD
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


// ENUM: ASPECT_FILLMETHOD
py::enum_<Aspect_FillMethod>(mod, "Aspect_FillMethod", "Defines the fill methods to write bitmaps in a window.")
	.value("Aspect_FM_NONE", Aspect_FillMethod::Aspect_FM_NONE)
	.value("Aspect_FM_CENTERED", Aspect_FillMethod::Aspect_FM_CENTERED)
	.value("Aspect_FM_TILED", Aspect_FillMethod::Aspect_FM_TILED)
	.value("Aspect_FM_STRETCH", Aspect_FillMethod::Aspect_FM_STRETCH)
	.export_values();


// ENUM: ASPECT_TYPEOFRESIZE
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


// ENUM: ASPECT_TYPEOFFACINGMODEL
py::enum_<Aspect_TypeOfFacingModel>(mod, "Aspect_TypeOfFacingModel", "None")
	.value("Aspect_TOFM_BOTH_SIDE", Aspect_TypeOfFacingModel::Aspect_TOFM_BOTH_SIDE)
	.value("Aspect_TOFM_BACK_SIDE", Aspect_TypeOfFacingModel::Aspect_TOFM_BACK_SIDE)
	.value("Aspect_TOFM_FRONT_SIDE", Aspect_TypeOfFacingModel::Aspect_TOFM_FRONT_SIDE)
	.export_values();


// ENUM: ASPECT_TYPEOFCOLORSCALEDATA
py::enum_<Aspect_TypeOfColorScaleData>(mod, "Aspect_TypeOfColorScaleData", "Defines the using type of colors and labels")
	.value("Aspect_TOCSD_AUTO", Aspect_TypeOfColorScaleData::Aspect_TOCSD_AUTO)
	.value("Aspect_TOCSD_USER", Aspect_TypeOfColorScaleData::Aspect_TOCSD_USER)
	.export_values();


// ENUM: ASPECT_TYPEOFCOLORSCALEPOSITION
py::enum_<Aspect_TypeOfColorScalePosition>(mod, "Aspect_TypeOfColorScalePosition", "Defines the type of position for color scale labels")
	.value("Aspect_TOCSP_NONE", Aspect_TypeOfColorScalePosition::Aspect_TOCSP_NONE)
	.value("Aspect_TOCSP_LEFT", Aspect_TypeOfColorScalePosition::Aspect_TOCSP_LEFT)
	.value("Aspect_TOCSP_RIGHT", Aspect_TypeOfColorScalePosition::Aspect_TOCSP_RIGHT)
	.value("Aspect_TOCSP_CENTER", Aspect_TypeOfColorScalePosition::Aspect_TOCSP_CENTER)
	.export_values();


// ENUM: ASPECT_GRIDDRAWMODE
py::enum_<Aspect_GridDrawMode>(mod, "Aspect_GridDrawMode", "Defines the grid draw mode. The grid may be drawn by using lines or points.")
	.value("Aspect_GDM_Lines", Aspect_GridDrawMode::Aspect_GDM_Lines)
	.value("Aspect_GDM_Points", Aspect_GridDrawMode::Aspect_GDM_Points)
	.value("Aspect_GDM_None", Aspect_GridDrawMode::Aspect_GDM_None)
	.export_values();


// ENUM: ASPECT_GRIDTYPE
py::enum_<Aspect_GridType>(mod, "Aspect_GridType", "Defines the grid type : Rectangular or Circular.")
	.value("Aspect_GT_Rectangular", Aspect_GridType::Aspect_GT_Rectangular)
	.value("Aspect_GT_Circular", Aspect_GridType::Aspect_GT_Circular)
	.export_values();


// ENUM: ASPECT_XATOM
py::enum_<Aspect_XAtom>(mod, "Aspect_XAtom", "Defines custom identifiers(atoms) for X window custom named properties")
	.value("Aspect_XA_DELETE_WINDOW", Aspect_XAtom::Aspect_XA_DELETE_WINDOW)
	.export_values();


// ENUM: ASPECT_TYPEOFCOLORSCALEORIENTATION
py::enum_<Aspect_TypeOfColorScaleOrientation>(mod, "Aspect_TypeOfColorScaleOrientation", "Defines the type of color scale orientation")
	.value("Aspect_TOCSO_NONE", Aspect_TypeOfColorScaleOrientation::Aspect_TOCSO_NONE)
	.value("Aspect_TOCSO_LEFT", Aspect_TypeOfColorScaleOrientation::Aspect_TOCSO_LEFT)
	.value("Aspect_TOCSO_RIGHT", Aspect_TypeOfColorScaleOrientation::Aspect_TOCSO_RIGHT)
	.value("Aspect_TOCSO_CENTER", Aspect_TypeOfColorScaleOrientation::Aspect_TOCSO_CENTER)
	.export_values();


// ENUM: ASPECT_WIDTHOFLINE
py::enum_<Aspect_WidthOfLine>(mod, "Aspect_WidthOfLine", "Definition of line types")
	.value("Aspect_WOL_THIN", Aspect_WidthOfLine::Aspect_WOL_THIN)
	.value("Aspect_WOL_MEDIUM", Aspect_WidthOfLine::Aspect_WOL_MEDIUM)
	.value("Aspect_WOL_THICK", Aspect_WidthOfLine::Aspect_WOL_THICK)
	.value("Aspect_WOL_VERYTHICK", Aspect_WidthOfLine::Aspect_WOL_VERYTHICK)
	.value("Aspect_WOL_USERDEFINED", Aspect_WidthOfLine::Aspect_WOL_USERDEFINED)
	.export_values();


// FUNCTION: ASPECT_VKEY2MODIFIER
mod.def("Aspect_VKey2Modifier", (Aspect_VKeyFlags (*) (Aspect_VKey)) &Aspect_VKey2Modifier, "Return modifier flags for specified modifier key.", py::arg("theKey"));

// TYPEDEF: ASPECT_POLYGONOFFSETMODE

// TYPEDEF: ASPECT_VKEYFLAGS

// TYPEDEF: ASPECT_VKEYMOUSE
if (py::hasattr(mod, "Aspect_VKeyFlags")) {
	mod.attr("Aspect_VKeyMouse") = mod.attr("Aspect_VKeyFlags");
}

// TYPEDEF: ASPECT_VKEY
if (py::hasattr(mod, "Aspect_VKeyFlags")) {
	mod.attr("Aspect_VKey") = mod.attr("Aspect_VKeyFlags");
}

// CLASS: ASPECT_GENID
py::class_<Aspect_GenId> cls_Aspect_GenId(mod, "Aspect_GenId", "This class permits the creation and control of integer identifiers.");

// Constructors
cls_Aspect_GenId.def(py::init<>());
cls_Aspect_GenId.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLow"), py::arg("theUpper"));

// Methods
// cls_Aspect_GenId.def_static("operator new_", (void * (*)(size_t)) &Aspect_GenId::operator new, "None", py::arg("theSize"));
// cls_Aspect_GenId.def_static("operator delete_", (void (*)(void *)) &Aspect_GenId::operator delete, "None", py::arg("theAddress"));
// cls_Aspect_GenId.def_static("operator new[]_", (void * (*)(size_t)) &Aspect_GenId::operator new[], "None", py::arg("theSize"));
// cls_Aspect_GenId.def_static("operator delete[]_", (void (*)(void *)) &Aspect_GenId::operator delete[], "None", py::arg("theAddress"));
// cls_Aspect_GenId.def_static("operator new_", (void * (*)(size_t, void *)) &Aspect_GenId::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Aspect_GenId.def_static("operator delete_", (void (*)(void *, void *)) &Aspect_GenId::operator delete, "None", py::arg(""), py::arg(""));
cls_Aspect_GenId.def("Free", (void (Aspect_GenId::*)()) &Aspect_GenId::Free, "Free all identifiers - make the whole range available again.");
cls_Aspect_GenId.def("Free", (void (Aspect_GenId::*)(const Standard_Integer)) &Aspect_GenId::Free, "Free specified identifier. Warning - method has no protection against double-freeing!", py::arg("theId"));
cls_Aspect_GenId.def("HasFree", (Standard_Boolean (Aspect_GenId::*)() const) &Aspect_GenId::HasFree, "Returns true if there are available identifiers in range.");
cls_Aspect_GenId.def("Available", (Standard_Integer (Aspect_GenId::*)() const) &Aspect_GenId::Available, "Returns the number of available identifiers.");
cls_Aspect_GenId.def("Lower", (Standard_Integer (Aspect_GenId::*)() const) &Aspect_GenId::Lower, "Returns the lower identifier in range.");
cls_Aspect_GenId.def("Next", (Standard_Integer (Aspect_GenId::*)()) &Aspect_GenId::Next, "Returns the next available identifier. Warning: Raises IdentDefinitionError if all identifiers are busy.");
cls_Aspect_GenId.def("Next", [](Aspect_GenId &self, Standard_Integer & theId){ Standard_Boolean rv = self.Next(theId); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theId); }, "Generates the next available identifier.", py::arg("theId"));
cls_Aspect_GenId.def("Upper", (Standard_Integer (Aspect_GenId::*)() const) &Aspect_GenId::Upper, "Returns the upper identifier in range.");

// TYPEDEF: HANDLE

// TYPEDEF: ASPECT_HANDLE

// TYPEDEF: ASPECT_RENDERINGCONTEXT

// CLASS: ASPECT_BACKGROUND
py::class_<Aspect_Background> cls_Aspect_Background(mod, "Aspect_Background", "This class allows the definition of a window background.");

// Constructors
cls_Aspect_Background.def(py::init<>());
cls_Aspect_Background.def(py::init<const Quantity_Color &>(), py::arg("AColor"));

// Methods
// cls_Aspect_Background.def_static("operator new_", (void * (*)(size_t)) &Aspect_Background::operator new, "None", py::arg("theSize"));
// cls_Aspect_Background.def_static("operator delete_", (void (*)(void *)) &Aspect_Background::operator delete, "None", py::arg("theAddress"));
// cls_Aspect_Background.def_static("operator new[]_", (void * (*)(size_t)) &Aspect_Background::operator new[], "None", py::arg("theSize"));
// cls_Aspect_Background.def_static("operator delete[]_", (void (*)(void *)) &Aspect_Background::operator delete[], "None", py::arg("theAddress"));
// cls_Aspect_Background.def_static("operator new_", (void * (*)(size_t, void *)) &Aspect_Background::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Aspect_Background.def_static("operator delete_", (void (*)(void *, void *)) &Aspect_Background::operator delete, "None", py::arg(""), py::arg(""));
cls_Aspect_Background.def("SetColor", (void (Aspect_Background::*)(const Quantity_Color &)) &Aspect_Background::SetColor, "Modifies the colour of the window background <me>.", py::arg("AColor"));
cls_Aspect_Background.def("Color", (Quantity_Color (Aspect_Background::*)() const) &Aspect_Background::Color, "Returns the colour of the window background <me>.");

// CLASS: ASPECT_GRADIENTBACKGROUND
py::class_<Aspect_GradientBackground, Aspect_Background> cls_Aspect_GradientBackground(mod, "Aspect_GradientBackground", "This class allows the definition of a window gradient background.");

// Constructors
cls_Aspect_GradientBackground.def(py::init<>());
cls_Aspect_GradientBackground.def(py::init<const Quantity_Color &, const Quantity_Color &>(), py::arg("AColor1"), py::arg("AColor2"));
cls_Aspect_GradientBackground.def(py::init<const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod>(), py::arg("AColor1"), py::arg("AColor2"), py::arg("AMethod"));

// Methods
// cls_Aspect_GradientBackground.def_static("operator new_", (void * (*)(size_t)) &Aspect_GradientBackground::operator new, "None", py::arg("theSize"));
// cls_Aspect_GradientBackground.def_static("operator delete_", (void (*)(void *)) &Aspect_GradientBackground::operator delete, "None", py::arg("theAddress"));
// cls_Aspect_GradientBackground.def_static("operator new[]_", (void * (*)(size_t)) &Aspect_GradientBackground::operator new[], "None", py::arg("theSize"));
// cls_Aspect_GradientBackground.def_static("operator delete[]_", (void (*)(void *)) &Aspect_GradientBackground::operator delete[], "None", py::arg("theAddress"));
// cls_Aspect_GradientBackground.def_static("operator new_", (void * (*)(size_t, void *)) &Aspect_GradientBackground::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Aspect_GradientBackground.def_static("operator delete_", (void (*)(void *, void *)) &Aspect_GradientBackground::operator delete, "None", py::arg(""), py::arg(""));
cls_Aspect_GradientBackground.def("SetColors", [](Aspect_GradientBackground &self, const Quantity_Color & a0, const Quantity_Color & a1) -> void { return self.SetColors(a0, a1); });
cls_Aspect_GradientBackground.def("SetColors", (void (Aspect_GradientBackground::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod)) &Aspect_GradientBackground::SetColors, "Modifies the colours of the window gradient background <me>.", py::arg("AColor1"), py::arg("AColor2"), py::arg("AMethod"));
cls_Aspect_GradientBackground.def("Colors", (void (Aspect_GradientBackground::*)(Quantity_Color &, Quantity_Color &) const) &Aspect_GradientBackground::Colors, "Returns colours of the window gradient background <me>.", py::arg("AColor1"), py::arg("AColor2"));
cls_Aspect_GradientBackground.def("BgGradientFillMethod", (Aspect_GradientFillMethod (Aspect_GradientBackground::*)() const) &Aspect_GradientBackground::BgGradientFillMethod, "Returns the current gradient background fill mode.");

// TYPEDEF: ASPECT_FBCONFIG

// TYPEDEF: ASPECT_DRAWABLE

// CLASS: ASPECT_WINDOW
py::class_<Aspect_Window, opencascade::handle<Aspect_Window>, Standard_Transient> cls_Aspect_Window(mod, "Aspect_Window", "Defines a window.");

// Methods
cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Aspect_Background &)) &Aspect_Window::SetBackground, "Modifies the window background.", py::arg("ABack"));
cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Quantity_Color &)) &Aspect_Window::SetBackground, "Modifies the window background.", py::arg("color"));
cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Aspect_GradientBackground &)) &Aspect_Window::SetBackground, "Modifies the window gradient background.", py::arg("ABackground"));
cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod)) &Aspect_Window::SetBackground, "Modifies the window gradient background.", py::arg("theFirstColor"), py::arg("theSecondColor"), py::arg("theFillMethod"));
cls_Aspect_Window.def("Map", (void (Aspect_Window::*)() const) &Aspect_Window::Map, "Opens the window <me>.");
cls_Aspect_Window.def("Unmap", (void (Aspect_Window::*)() const) &Aspect_Window::Unmap, "Closes the window <me>.");
cls_Aspect_Window.def("DoResize", (Aspect_TypeOfResize (Aspect_Window::*)() const) &Aspect_Window::DoResize, "Apply the resizing to the window <me>.");
cls_Aspect_Window.def("DoMapping", (Standard_Boolean (Aspect_Window::*)() const) &Aspect_Window::DoMapping, "Apply the mapping change to the window <me>. and returns TRUE if the window is mapped at screen.");
cls_Aspect_Window.def("Background", (Aspect_Background (Aspect_Window::*)() const) &Aspect_Window::Background, "Returns the window background.");
cls_Aspect_Window.def("BackgroundFillMethod", (Aspect_FillMethod (Aspect_Window::*)() const) &Aspect_Window::BackgroundFillMethod, "Returns the current image background fill mode.");
cls_Aspect_Window.def("GradientBackground", (Aspect_GradientBackground (Aspect_Window::*)() const) &Aspect_Window::GradientBackground, "Returns the window gradient background.");
cls_Aspect_Window.def("IsMapped", (Standard_Boolean (Aspect_Window::*)() const) &Aspect_Window::IsMapped, "Returns True if the window <me> is opened and False if the window is closed.");
cls_Aspect_Window.def("IsVirtual", (Standard_Boolean (Aspect_Window::*)() const) &Aspect_Window::IsVirtual, "Returns True if the window <me> is virtual");
cls_Aspect_Window.def("SetVirtual", (void (Aspect_Window::*)(const Standard_Boolean)) &Aspect_Window::SetVirtual, "Setup the virtual state", py::arg("theVirtual"));
cls_Aspect_Window.def("Ratio", (Standard_Real (Aspect_Window::*)() const) &Aspect_Window::Ratio, "Returns The Window RATIO equal to the physical WIDTH/HEIGHT dimensions");
cls_Aspect_Window.def("Position", [](Aspect_Window &self, Standard_Integer & X1, Standard_Integer & Y1, Standard_Integer & X2, Standard_Integer & Y2){ self.Position(X1, Y1, X2, Y2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(X1, Y1, X2, Y2); }, "Returns The Window POSITION in PIXEL", py::arg("X1"), py::arg("Y1"), py::arg("X2"), py::arg("Y2"));
cls_Aspect_Window.def("Size", [](Aspect_Window &self, Standard_Integer & Width, Standard_Integer & Height){ self.Size(Width, Height); return std::tuple<Standard_Integer &, Standard_Integer &>(Width, Height); }, "Returns The Window SIZE in PIXEL", py::arg("Width"), py::arg("Height"));
cls_Aspect_Window.def("NativeHandle", (Aspect_Drawable (Aspect_Window::*)() const) &Aspect_Window::NativeHandle, "Returns native Window handle (HWND on Windows, Window with Xlib, and so on)");
cls_Aspect_Window.def("NativeParentHandle", (Aspect_Drawable (Aspect_Window::*)() const) &Aspect_Window::NativeParentHandle, "Returns parent of native Window handle (HWND on Windows, Window with Xlib, and so on)");
cls_Aspect_Window.def("NativeFBConfig", (Aspect_FBConfig (Aspect_Window::*)() const) &Aspect_Window::NativeFBConfig, "Returns native Window FB config (GLXFBConfig on Xlib)");
cls_Aspect_Window.def("SetTitle", (void (Aspect_Window::*)(const TCollection_AsciiString &)) &Aspect_Window::SetTitle, "Sets window title.", py::arg("theTitle"));
cls_Aspect_Window.def("InvalidateContent", (void (Aspect_Window::*)(const opencascade::handle<Aspect_DisplayConnection> &)) &Aspect_Window::InvalidateContent, "Invalidate entire window content.", py::arg("theDisp"));
cls_Aspect_Window.def_static("get_type_name_", (const char * (*)()) &Aspect_Window::get_type_name, "None");
cls_Aspect_Window.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_Window::get_type_descriptor, "None");
cls_Aspect_Window.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_Window::*)() const) &Aspect_Window::DynamicType, "None");

// TYPEDEF: ASPECT_SEQUENCEOFCOLOR
bind_NCollection_Sequence<Quantity_Color>(mod, "Aspect_SequenceOfColor", py::module_local(false));

// CLASS: ASPECT_VKEYSET
py::class_<Aspect_VKeySet, opencascade::handle<Aspect_VKeySet>, Standard_Transient> cls_Aspect_VKeySet(mod, "Aspect_VKeySet", "Structure defining key state.");

// Constructors
cls_Aspect_VKeySet.def(py::init<>());

// Methods
cls_Aspect_VKeySet.def_static("get_type_name_", (const char * (*)()) &Aspect_VKeySet::get_type_name, "None");
cls_Aspect_VKeySet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_VKeySet::get_type_descriptor, "None");
cls_Aspect_VKeySet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_VKeySet::*)() const) &Aspect_VKeySet::DynamicType, "None");
cls_Aspect_VKeySet.def("Modifiers", (Aspect_VKeyFlags (Aspect_VKeySet::*)() const) &Aspect_VKeySet::Modifiers, "Return active modifiers.");
cls_Aspect_VKeySet.def("DownTime", (double (Aspect_VKeySet::*)(Aspect_VKey) const) &Aspect_VKeySet::DownTime, "Return timestamp of press event.", py::arg("theKey"));
cls_Aspect_VKeySet.def("TimeUp", (double (Aspect_VKeySet::*)(Aspect_VKey) const) &Aspect_VKeySet::TimeUp, "Return timestamp of release event.", py::arg("theKey"));
cls_Aspect_VKeySet.def("IsFreeKey", (bool (Aspect_VKeySet::*)(Aspect_VKey) const) &Aspect_VKeySet::IsFreeKey, "Return TRUE if key is in Free state.", py::arg("theKey"));
cls_Aspect_VKeySet.def("IsKeyDown", (bool (Aspect_VKeySet::*)(Aspect_VKey) const) &Aspect_VKeySet::IsKeyDown, "Return TRUE if key is in Pressed state.", py::arg("theKey"));
cls_Aspect_VKeySet.def("Reset", (void (Aspect_VKeySet::*)()) &Aspect_VKeySet::Reset, "Reset the key state into unpressed state.");
cls_Aspect_VKeySet.def("KeyDown", [](Aspect_VKeySet &self, Aspect_VKey a0, double a1) -> void { return self.KeyDown(a0, a1); });
cls_Aspect_VKeySet.def("KeyDown", (void (Aspect_VKeySet::*)(Aspect_VKey, double, double)) &Aspect_VKeySet::KeyDown, "Press key.", py::arg("theKey"), py::arg("theTime"), py::arg("thePressure"));
cls_Aspect_VKeySet.def("KeyUp", (void (Aspect_VKeySet::*)(Aspect_VKey, double)) &Aspect_VKeySet::KeyUp, "Release key.", py::arg("theKey"), py::arg("theTime"));
cls_Aspect_VKeySet.def("KeyFromAxis", (void (Aspect_VKeySet::*)(Aspect_VKey, Aspect_VKey, double, double)) &Aspect_VKeySet::KeyFromAxis, "Simulate key up/down events from axis value.", py::arg("theNegative"), py::arg("thePositive"), py::arg("theTime"), py::arg("thePressure"));
cls_Aspect_VKeySet.def("HoldDuration", (bool (Aspect_VKeySet::*)(Aspect_VKey, double, double &)) &Aspect_VKeySet::HoldDuration, "Return duration of the button in pressed state.", py::arg("theKey"), py::arg("theTime"), py::arg("theDuration"));
cls_Aspect_VKeySet.def("HoldDuration", (bool (Aspect_VKeySet::*)(Aspect_VKey, double, double &, double &)) &Aspect_VKeySet::HoldDuration, "Return duration of the button in pressed state.", py::arg("theKey"), py::arg("theTime"), py::arg("theDuration"), py::arg("thePressure"));

// CLASS: ASPECT_TOUCH
py::class_<Aspect_Touch> cls_Aspect_Touch(mod, "Aspect_Touch", "Structure holding touch position - original and current location.");

// Constructors
cls_Aspect_Touch.def(py::init<>());
cls_Aspect_Touch.def(py::init<const NCollection_Vec2<Standard_Real> &, Standard_Boolean>(), py::arg("thePnt"), py::arg("theIsPreciseDevice"));
cls_Aspect_Touch.def(py::init<Standard_Real, Standard_Real, Standard_Boolean>(), py::arg("theX"), py::arg("theY"), py::arg("theIsPreciseDevice"));

// Fields
cls_Aspect_Touch.def_readwrite("From", &Aspect_Touch::From, "original touch position");
cls_Aspect_Touch.def_readwrite("To", &Aspect_Touch::To, "current touch position");
cls_Aspect_Touch.def_readwrite("IsPreciseDevice", &Aspect_Touch::IsPreciseDevice, "precise device input (e.g. mouse cursor, NOT emulated from touch screen)");

// Methods
cls_Aspect_Touch.def("Delta", (NCollection_Vec2<Standard_Real> (Aspect_Touch::*)() const) &Aspect_Touch::Delta, "Return values delta.");

// TYPEDEF: ASPECT_TOUCHMAP
bind_NCollection_IndexedDataMap<unsigned long long, Aspect_Touch, NCollection_DefaultHasher<unsigned long long> >(mod, "Aspect_TouchMap", py::module_local(false));

// CLASS: ASPECT_SCROLLDELTA
py::class_<Aspect_ScrollDelta> cls_Aspect_ScrollDelta(mod, "Aspect_ScrollDelta", "Parameters for mouse scroll action.");

// Constructors
cls_Aspect_ScrollDelta.def(py::init<>());
cls_Aspect_ScrollDelta.def(py::init<const NCollection_Vec2<int> &, Standard_Real>(), py::arg("thePnt"), py::arg("theValue"));
cls_Aspect_ScrollDelta.def(py::init<const NCollection_Vec2<int> &, Standard_Real, Aspect_VKeyFlags>(), py::arg("thePnt"), py::arg("theValue"), py::arg("theFlags"));
cls_Aspect_ScrollDelta.def(py::init<Standard_Real>(), py::arg("theValue"));
cls_Aspect_ScrollDelta.def(py::init<Standard_Real, Aspect_VKeyFlags>(), py::arg("theValue"), py::arg("theFlags"));

// Fields
cls_Aspect_ScrollDelta.def_readwrite("Point", &Aspect_ScrollDelta::Point, "scale position");
cls_Aspect_ScrollDelta.def_readwrite("Delta", &Aspect_ScrollDelta::Delta, "delta in pixels");
cls_Aspect_ScrollDelta.def_readwrite("Flags", &Aspect_ScrollDelta::Flags, "key flags");

// Methods
cls_Aspect_ScrollDelta.def("HasPoint", (bool (Aspect_ScrollDelta::*)() const) &Aspect_ScrollDelta::HasPoint, "Return true if action has point defined.");
cls_Aspect_ScrollDelta.def("ResetPoint", (void (Aspect_ScrollDelta::*)()) &Aspect_ScrollDelta::ResetPoint, "Reset at point.");

// CLASS: ASPECT_ASPECTFILLAREADEFINITIONERROR
py::class_<Aspect_AspectFillAreaDefinitionError, opencascade::handle<Aspect_AspectFillAreaDefinitionError>, Standard_OutOfRange> cls_Aspect_AspectFillAreaDefinitionError(mod, "Aspect_AspectFillAreaDefinitionError", "None");

// Constructors
cls_Aspect_AspectFillAreaDefinitionError.def(py::init<>());
cls_Aspect_AspectFillAreaDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Aspect_AspectFillAreaDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_AspectFillAreaDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_AspectFillAreaDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_AspectFillAreaDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_AspectFillAreaDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_AspectFillAreaDefinitionError> (*)(const Standard_CString)) &Aspect_AspectFillAreaDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_Aspect_AspectFillAreaDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_AspectFillAreaDefinitionError::get_type_name, "None");
cls_Aspect_AspectFillAreaDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_AspectFillAreaDefinitionError::get_type_descriptor, "None");
cls_Aspect_AspectFillAreaDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_AspectFillAreaDefinitionError::*)() const) &Aspect_AspectFillAreaDefinitionError::DynamicType, "None");

// CLASS: ASPECT_ASPECTLINEDEFINITIONERROR
py::class_<Aspect_AspectLineDefinitionError, opencascade::handle<Aspect_AspectLineDefinitionError>, Standard_OutOfRange> cls_Aspect_AspectLineDefinitionError(mod, "Aspect_AspectLineDefinitionError", "None");

// Constructors
cls_Aspect_AspectLineDefinitionError.def(py::init<>());
cls_Aspect_AspectLineDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Aspect_AspectLineDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_AspectLineDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_AspectLineDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_AspectLineDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_AspectLineDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_AspectLineDefinitionError> (*)(const Standard_CString)) &Aspect_AspectLineDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_Aspect_AspectLineDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_AspectLineDefinitionError::get_type_name, "None");
cls_Aspect_AspectLineDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_AspectLineDefinitionError::get_type_descriptor, "None");
cls_Aspect_AspectLineDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_AspectLineDefinitionError::*)() const) &Aspect_AspectLineDefinitionError::DynamicType, "None");

// CLASS: ASPECT_ASPECTMARKERDEFINITIONERROR
py::class_<Aspect_AspectMarkerDefinitionError, opencascade::handle<Aspect_AspectMarkerDefinitionError>, Standard_OutOfRange> cls_Aspect_AspectMarkerDefinitionError(mod, "Aspect_AspectMarkerDefinitionError", "None");

// Constructors
cls_Aspect_AspectMarkerDefinitionError.def(py::init<>());
cls_Aspect_AspectMarkerDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Aspect_AspectMarkerDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_AspectMarkerDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_AspectMarkerDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_AspectMarkerDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_AspectMarkerDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_AspectMarkerDefinitionError> (*)(const Standard_CString)) &Aspect_AspectMarkerDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_Aspect_AspectMarkerDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_AspectMarkerDefinitionError::get_type_name, "None");
cls_Aspect_AspectMarkerDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_AspectMarkerDefinitionError::get_type_descriptor, "None");
cls_Aspect_AspectMarkerDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_AspectMarkerDefinitionError::*)() const) &Aspect_AspectMarkerDefinitionError::DynamicType, "None");

// CLASS: ASPECT_GRID
py::class_<Aspect_Grid, opencascade::handle<Aspect_Grid>, Standard_Transient> cls_Aspect_Grid(mod, "Aspect_Grid", "None");

// Methods
cls_Aspect_Grid.def_static("get_type_name_", (const char * (*)()) &Aspect_Grid::get_type_name, "None");
cls_Aspect_Grid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_Grid::get_type_descriptor, "None");
cls_Aspect_Grid.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_Grid::*)() const) &Aspect_Grid::DynamicType, "None");
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
cls_Aspect_Grid.def("XOrigin", (Standard_Real (Aspect_Grid::*)() const) &Aspect_Grid::XOrigin, "returns the x Origin of the grid.");
cls_Aspect_Grid.def("YOrigin", (Standard_Real (Aspect_Grid::*)() const) &Aspect_Grid::YOrigin, "returns the x Origin of the grid.");
cls_Aspect_Grid.def("RotationAngle", (Standard_Real (Aspect_Grid::*)() const) &Aspect_Grid::RotationAngle, "returns the x Angle of the grid.");
cls_Aspect_Grid.def("IsActive", (Standard_Boolean (Aspect_Grid::*)() const) &Aspect_Grid::IsActive, "Returns TRUE when the grid is active.");
cls_Aspect_Grid.def("Colors", (void (Aspect_Grid::*)(Quantity_Color &, Quantity_Color &) const) &Aspect_Grid::Colors, "Returns the colors of the grid.", py::arg("aColor"), py::arg("aTenthColor"));
cls_Aspect_Grid.def("SetDrawMode", (void (Aspect_Grid::*)(const Aspect_GridDrawMode)) &Aspect_Grid::SetDrawMode, "Change the grid aspect.", py::arg("aDrawMode"));
cls_Aspect_Grid.def("DrawMode", (Aspect_GridDrawMode (Aspect_Grid::*)() const) &Aspect_Grid::DrawMode, "Returns the grid aspect.");
cls_Aspect_Grid.def("Display", (void (Aspect_Grid::*)()) &Aspect_Grid::Display, "Display the grid at screen.");
cls_Aspect_Grid.def("Erase", (void (Aspect_Grid::*)() const) &Aspect_Grid::Erase, "Erase the grid from screen.");
cls_Aspect_Grid.def("IsDisplayed", (Standard_Boolean (Aspect_Grid::*)() const) &Aspect_Grid::IsDisplayed, "Returns TRUE when the grid is displayed at screen.");
cls_Aspect_Grid.def("Init", (void (Aspect_Grid::*)()) &Aspect_Grid::Init, "None");

// CLASS: ASPECT_CIRCULARGRID
py::class_<Aspect_CircularGrid, opencascade::handle<Aspect_CircularGrid>, Aspect_Grid> cls_Aspect_CircularGrid(mod, "Aspect_CircularGrid", "None");

// Methods
cls_Aspect_CircularGrid.def_static("get_type_name_", (const char * (*)()) &Aspect_CircularGrid::get_type_name, "None");
cls_Aspect_CircularGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_CircularGrid::get_type_descriptor, "None");
cls_Aspect_CircularGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_CircularGrid::*)() const) &Aspect_CircularGrid::DynamicType, "None");
cls_Aspect_CircularGrid.def("SetRadiusStep", (void (Aspect_CircularGrid::*)(const Standard_Real)) &Aspect_CircularGrid::SetRadiusStep, "defines the x step of the grid.", py::arg("aStep"));
cls_Aspect_CircularGrid.def("SetDivisionNumber", (void (Aspect_CircularGrid::*)(const Standard_Integer)) &Aspect_CircularGrid::SetDivisionNumber, "defines the step of the grid.", py::arg("aNumber"));
cls_Aspect_CircularGrid.def("SetGridValues", (void (Aspect_CircularGrid::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real)) &Aspect_CircularGrid::SetGridValues, "None", py::arg("XOrigin"), py::arg("YOrigin"), py::arg("RadiusStep"), py::arg("DivisionNumber"), py::arg("RotationAngle"));
cls_Aspect_CircularGrid.def("Compute", [](Aspect_CircularGrid &self, const Standard_Real X, const Standard_Real Y, Standard_Real & gridX, Standard_Real & gridY){ self.Compute(X, Y, gridX, gridY); return std::tuple<Standard_Real &, Standard_Real &>(gridX, gridY); }, "returns the point of the grid the closest to the point X,Y", py::arg("X"), py::arg("Y"), py::arg("gridX"), py::arg("gridY"));
cls_Aspect_CircularGrid.def("RadiusStep", (Standard_Real (Aspect_CircularGrid::*)() const) &Aspect_CircularGrid::RadiusStep, "returns the x step of the grid.");
cls_Aspect_CircularGrid.def("DivisionNumber", (Standard_Integer (Aspect_CircularGrid::*)() const) &Aspect_CircularGrid::DivisionNumber, "returns the x step of the grid.");
cls_Aspect_CircularGrid.def("Init", (void (Aspect_CircularGrid::*)()) &Aspect_CircularGrid::Init, "None");

// TYPEDEF: ASPECT_DISPLAY

// CLASS: ASPECT_DISPLAYCONNECTION
py::class_<Aspect_DisplayConnection, opencascade::handle<Aspect_DisplayConnection>, Standard_Transient> cls_Aspect_DisplayConnection(mod, "Aspect_DisplayConnection", "This class creates and provides connection with X server. Raises exception if can not connect to X server. On Windows and Mac OS X (in case when Cocoa used) platforms this class do nothing. WARRNING: Do not close display connection manualy!");

// Constructors
cls_Aspect_DisplayConnection.def(py::init<>());

// Methods
cls_Aspect_DisplayConnection.def_static("get_type_name_", (const char * (*)()) &Aspect_DisplayConnection::get_type_name, "None");
cls_Aspect_DisplayConnection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_DisplayConnection::get_type_descriptor, "None");
cls_Aspect_DisplayConnection.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_DisplayConnection::*)() const) &Aspect_DisplayConnection::DynamicType, "None");

// CLASS: ASPECT_DISPLAYCONNECTIONDEFINITIONERROR
py::class_<Aspect_DisplayConnectionDefinitionError, opencascade::handle<Aspect_DisplayConnectionDefinitionError>, Standard_OutOfRange> cls_Aspect_DisplayConnectionDefinitionError(mod, "Aspect_DisplayConnectionDefinitionError", "None");

// Constructors
cls_Aspect_DisplayConnectionDefinitionError.def(py::init<>());
cls_Aspect_DisplayConnectionDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Aspect_DisplayConnectionDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_DisplayConnectionDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_DisplayConnectionDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_DisplayConnectionDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_DisplayConnectionDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_DisplayConnectionDefinitionError> (*)(const Standard_CString)) &Aspect_DisplayConnectionDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_Aspect_DisplayConnectionDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_DisplayConnectionDefinitionError::get_type_name, "None");
cls_Aspect_DisplayConnectionDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_DisplayConnectionDefinitionError::get_type_descriptor, "None");
cls_Aspect_DisplayConnectionDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_DisplayConnectionDefinitionError::*)() const) &Aspect_DisplayConnectionDefinitionError::DynamicType, "None");

// CLASS: ASPECT_GRAPHICDEVICEDEFINITIONERROR
py::class_<Aspect_GraphicDeviceDefinitionError, opencascade::handle<Aspect_GraphicDeviceDefinitionError>, Standard_OutOfRange> cls_Aspect_GraphicDeviceDefinitionError(mod, "Aspect_GraphicDeviceDefinitionError", "None");

// Constructors
cls_Aspect_GraphicDeviceDefinitionError.def(py::init<>());
cls_Aspect_GraphicDeviceDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Aspect_GraphicDeviceDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_GraphicDeviceDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_GraphicDeviceDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_GraphicDeviceDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_GraphicDeviceDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_GraphicDeviceDefinitionError> (*)(const Standard_CString)) &Aspect_GraphicDeviceDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_Aspect_GraphicDeviceDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_GraphicDeviceDefinitionError::get_type_name, "None");
cls_Aspect_GraphicDeviceDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_GraphicDeviceDefinitionError::get_type_descriptor, "None");
cls_Aspect_GraphicDeviceDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_GraphicDeviceDefinitionError::*)() const) &Aspect_GraphicDeviceDefinitionError::DynamicType, "None");

// CLASS: ASPECT_IDENTDEFINITIONERROR
py::class_<Aspect_IdentDefinitionError, opencascade::handle<Aspect_IdentDefinitionError>, Standard_OutOfRange> cls_Aspect_IdentDefinitionError(mod, "Aspect_IdentDefinitionError", "None");

// Constructors
cls_Aspect_IdentDefinitionError.def(py::init<>());
cls_Aspect_IdentDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Aspect_IdentDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_IdentDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_IdentDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_IdentDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_IdentDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_IdentDefinitionError> (*)(const Standard_CString)) &Aspect_IdentDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_Aspect_IdentDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_IdentDefinitionError::get_type_name, "None");
cls_Aspect_IdentDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_IdentDefinitionError::get_type_descriptor, "None");
cls_Aspect_IdentDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_IdentDefinitionError::*)() const) &Aspect_IdentDefinitionError::DynamicType, "None");

// CLASS: ASPECT_NEUTRALWINDOW
py::class_<Aspect_NeutralWindow, opencascade::handle<Aspect_NeutralWindow>, Aspect_Window> cls_Aspect_NeutralWindow(mod, "Aspect_NeutralWindow", "Defines a platform-neutral window. This class is intended to be used in context when window management (including OpenGL context creation) is performed on application side (e.g. using external framework).");

// Constructors
cls_Aspect_NeutralWindow.def(py::init<>());

// Methods
cls_Aspect_NeutralWindow.def_static("get_type_name_", (const char * (*)()) &Aspect_NeutralWindow::get_type_name, "None");
cls_Aspect_NeutralWindow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_NeutralWindow::get_type_descriptor, "None");
cls_Aspect_NeutralWindow.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::DynamicType, "None");
cls_Aspect_NeutralWindow.def("NativeHandle", (Aspect_Drawable (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::NativeHandle, "Return native handle of this drawable.");
cls_Aspect_NeutralWindow.def("NativeParentHandle", (Aspect_Drawable (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::NativeParentHandle, "Return native handle of the parent drawable.");
cls_Aspect_NeutralWindow.def("NativeFBConfig", (Aspect_FBConfig (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::NativeFBConfig, "Return FBConfig.");
cls_Aspect_NeutralWindow.def("SetNativeHandle", (Standard_Boolean (Aspect_NeutralWindow::*)(Aspect_Drawable)) &Aspect_NeutralWindow::SetNativeHandle, "Set native handle.", py::arg("theWindow"));
cls_Aspect_NeutralWindow.def("SetNativeHandles", (Standard_Boolean (Aspect_NeutralWindow::*)(Aspect_Drawable, Aspect_Drawable, Aspect_FBConfig)) &Aspect_NeutralWindow::SetNativeHandles, "Set native handles.", py::arg("theWindow"), py::arg("theParentWindow"), py::arg("theFbConfig"));
cls_Aspect_NeutralWindow.def("IsMapped", (Standard_Boolean (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::IsMapped, "Return true if window is not hidden.");
cls_Aspect_NeutralWindow.def("Map", (void (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::Map, "Change window mapped flag to TRUE.");
cls_Aspect_NeutralWindow.def("Unmap", (void (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::Unmap, "Change window mapped flag to FALSE.");
cls_Aspect_NeutralWindow.def("DoResize", (Aspect_TypeOfResize (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::DoResize, "Resize window - do nothing.");
cls_Aspect_NeutralWindow.def("DoMapping", (Standard_Boolean (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::DoMapping, "Map window - do nothing.");
cls_Aspect_NeutralWindow.def("Ratio", (Standard_Real (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::Ratio, "Returns window ratio equal to the physical width/height dimensions.");
cls_Aspect_NeutralWindow.def("Position", [](Aspect_NeutralWindow &self, Standard_Integer & theX1, Standard_Integer & theY1, Standard_Integer & theX2, Standard_Integer & theY2){ self.Position(theX1, theY1, theX2, theY2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(theX1, theY1, theX2, theY2); }, "Return the window position.", py::arg("theX1"), py::arg("theY1"), py::arg("theX2"), py::arg("theY2"));
cls_Aspect_NeutralWindow.def("SetPosition", (Standard_Boolean (Aspect_NeutralWindow::*)(Standard_Integer, Standard_Integer)) &Aspect_NeutralWindow::SetPosition, "Set the window position.", py::arg("theX1"), py::arg("theY1"));
cls_Aspect_NeutralWindow.def("SetPosition", (Standard_Boolean (Aspect_NeutralWindow::*)(Standard_Integer, Standard_Integer, Standard_Integer, Standard_Integer)) &Aspect_NeutralWindow::SetPosition, "Set the window position.", py::arg("theX1"), py::arg("theY1"), py::arg("theX2"), py::arg("theY2"));
cls_Aspect_NeutralWindow.def("Size", [](Aspect_NeutralWindow &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.Size(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "Return the window size.", py::arg("theWidth"), py::arg("theHeight"));
cls_Aspect_NeutralWindow.def("SetSize", (Standard_Boolean (Aspect_NeutralWindow::*)(const Standard_Integer, const Standard_Integer)) &Aspect_NeutralWindow::SetSize, "Set the window size.", py::arg("theWidth"), py::arg("theHeight"));

// CLASS: ASPECT_RECTANGULARGRID
py::class_<Aspect_RectangularGrid, opencascade::handle<Aspect_RectangularGrid>, Aspect_Grid> cls_Aspect_RectangularGrid(mod, "Aspect_RectangularGrid", "None");

// Methods
cls_Aspect_RectangularGrid.def_static("get_type_name_", (const char * (*)()) &Aspect_RectangularGrid::get_type_name, "None");
cls_Aspect_RectangularGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_RectangularGrid::get_type_descriptor, "None");
cls_Aspect_RectangularGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_RectangularGrid::*)() const) &Aspect_RectangularGrid::DynamicType, "None");
cls_Aspect_RectangularGrid.def("SetXStep", (void (Aspect_RectangularGrid::*)(const Standard_Real)) &Aspect_RectangularGrid::SetXStep, "defines the x step of the grid.", py::arg("aStep"));
cls_Aspect_RectangularGrid.def("SetYStep", (void (Aspect_RectangularGrid::*)(const Standard_Real)) &Aspect_RectangularGrid::SetYStep, "defines the y step of the grid.", py::arg("aStep"));
cls_Aspect_RectangularGrid.def("SetAngle", (void (Aspect_RectangularGrid::*)(const Standard_Real, const Standard_Real)) &Aspect_RectangularGrid::SetAngle, "defines the angle of the second network the fist angle is given relatively to the horizontal. the second angle is given relatively to the vertical.", py::arg("anAngle1"), py::arg("anAngle2"));
cls_Aspect_RectangularGrid.def("SetGridValues", (void (Aspect_RectangularGrid::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Aspect_RectangularGrid::SetGridValues, "None", py::arg("XOrigin"), py::arg("YOrigin"), py::arg("XStep"), py::arg("YStep"), py::arg("RotationAngle"));
cls_Aspect_RectangularGrid.def("Compute", [](Aspect_RectangularGrid &self, const Standard_Real X, const Standard_Real Y, Standard_Real & gridX, Standard_Real & gridY){ self.Compute(X, Y, gridX, gridY); return std::tuple<Standard_Real &, Standard_Real &>(gridX, gridY); }, "returns the point of the grid the closest to the point X,Y", py::arg("X"), py::arg("Y"), py::arg("gridX"), py::arg("gridY"));
cls_Aspect_RectangularGrid.def("XStep", (Standard_Real (Aspect_RectangularGrid::*)() const) &Aspect_RectangularGrid::XStep, "returns the x step of the grid.");
cls_Aspect_RectangularGrid.def("YStep", (Standard_Real (Aspect_RectangularGrid::*)() const) &Aspect_RectangularGrid::YStep, "returns the x step of the grid.");
cls_Aspect_RectangularGrid.def("FirstAngle", (Standard_Real (Aspect_RectangularGrid::*)() const) &Aspect_RectangularGrid::FirstAngle, "returns the x Angle of the grid, relatively to the horizontal.");
cls_Aspect_RectangularGrid.def("SecondAngle", (Standard_Real (Aspect_RectangularGrid::*)() const) &Aspect_RectangularGrid::SecondAngle, "returns the y Angle of the grid, relatively to the vertical.");
cls_Aspect_RectangularGrid.def("Init", (void (Aspect_RectangularGrid::*)()) &Aspect_RectangularGrid::Init, "None");

// CLASS: ASPECT_WINDOWDEFINITIONERROR
py::class_<Aspect_WindowDefinitionError, opencascade::handle<Aspect_WindowDefinitionError>, Standard_OutOfRange> cls_Aspect_WindowDefinitionError(mod, "Aspect_WindowDefinitionError", "None");

// Constructors
cls_Aspect_WindowDefinitionError.def(py::init<>());
cls_Aspect_WindowDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Aspect_WindowDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_WindowDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_WindowDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_WindowDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_WindowDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_WindowDefinitionError> (*)(const Standard_CString)) &Aspect_WindowDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_Aspect_WindowDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_WindowDefinitionError::get_type_name, "None");
cls_Aspect_WindowDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_WindowDefinitionError::get_type_descriptor, "None");
cls_Aspect_WindowDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_WindowDefinitionError::*)() const) &Aspect_WindowDefinitionError::DynamicType, "None");

// CLASS: ASPECT_WINDOWERROR
py::class_<Aspect_WindowError, opencascade::handle<Aspect_WindowError>, Standard_OutOfRange> cls_Aspect_WindowError(mod, "Aspect_WindowError", "None");

// Constructors
cls_Aspect_WindowError.def(py::init<>());
cls_Aspect_WindowError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Aspect_WindowError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_WindowError::Raise, "None", py::arg("theMessage"));
cls_Aspect_WindowError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_WindowError::Raise, "None", py::arg("theMessage"));
cls_Aspect_WindowError.def_static("NewInstance_", (opencascade::handle<Aspect_WindowError> (*)(const Standard_CString)) &Aspect_WindowError::NewInstance, "None", py::arg("theMessage"));
cls_Aspect_WindowError.def_static("get_type_name_", (const char * (*)()) &Aspect_WindowError::get_type_name, "None");
cls_Aspect_WindowError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_WindowError::get_type_descriptor, "None");
cls_Aspect_WindowError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_WindowError::*)() const) &Aspect_WindowError::DynamicType, "None");

// TYPEDEF: CARD32
if (py::hasattr(mod, "Aspect_VKeyFlags")) {
	mod.attr("CARD32") = mod.attr("Aspect_VKeyFlags");
}

// CLASS: _XWD_FILE_HEADER
py::class_<_xwd_file_header> cls__xwd_file_header(mod, "_xwd_file_header", "None");

// Constructors
cls__xwd_file_header.def(py::init<>());

// Fields
cls__xwd_file_header.def_readwrite("header_size", &_xwd_file_header::header_size, "None");
cls__xwd_file_header.def_readwrite("file_version", &_xwd_file_header::file_version, "None");
cls__xwd_file_header.def_readwrite("pixmap_format", &_xwd_file_header::pixmap_format, "None");
cls__xwd_file_header.def_readwrite("pixmap_depth", &_xwd_file_header::pixmap_depth, "None");
cls__xwd_file_header.def_readwrite("pixmap_width", &_xwd_file_header::pixmap_width, "None");
cls__xwd_file_header.def_readwrite("pixmap_height", &_xwd_file_header::pixmap_height, "None");
cls__xwd_file_header.def_readwrite("xoffset", &_xwd_file_header::xoffset, "None");
cls__xwd_file_header.def_readwrite("byte_order", &_xwd_file_header::byte_order, "None");
cls__xwd_file_header.def_readwrite("bitmap_unit", &_xwd_file_header::bitmap_unit, "None");
cls__xwd_file_header.def_readwrite("bitmap_bit_order", &_xwd_file_header::bitmap_bit_order, "None");
cls__xwd_file_header.def_readwrite("bitmap_pad", &_xwd_file_header::bitmap_pad, "None");
cls__xwd_file_header.def_readwrite("bits_per_pixel", &_xwd_file_header::bits_per_pixel, "None");
cls__xwd_file_header.def_readwrite("bytes_per_line", &_xwd_file_header::bytes_per_line, "None");
cls__xwd_file_header.def_readwrite("visual_class", &_xwd_file_header::visual_class, "None");
cls__xwd_file_header.def_readwrite("red_mask", &_xwd_file_header::red_mask, "None");
cls__xwd_file_header.def_readwrite("green_mask", &_xwd_file_header::green_mask, "None");
cls__xwd_file_header.def_readwrite("blue_mask", &_xwd_file_header::blue_mask, "None");
cls__xwd_file_header.def_readwrite("bits_per_rgb", &_xwd_file_header::bits_per_rgb, "None");
cls__xwd_file_header.def_readwrite("colormap_entries", &_xwd_file_header::colormap_entries, "None");
cls__xwd_file_header.def_readwrite("ncolors", &_xwd_file_header::ncolors, "None");
cls__xwd_file_header.def_readwrite("window_width", &_xwd_file_header::window_width, "None");
cls__xwd_file_header.def_readwrite("window_height", &_xwd_file_header::window_height, "None");
cls__xwd_file_header.def_readwrite("window_x", &_xwd_file_header::window_x, "None");
cls__xwd_file_header.def_readwrite("window_y", &_xwd_file_header::window_y, "None");
cls__xwd_file_header.def_readwrite("window_bdrwidth", &_xwd_file_header::window_bdrwidth, "None");

// TYPEDEF: XWDFILEHEADER
if (py::hasattr(mod, "_xwd_file_header")) {
	mod.attr("XWDFileHeader") = mod.attr("_xwd_file_header");
}

// CLASS: _XCOLOR
py::class_<_xcolor> cls__xcolor(mod, "_xcolor", "None");

// Constructors
cls__xcolor.def(py::init<>());

// Fields
cls__xcolor.def_readwrite("pixel", &_xcolor::pixel, "None");
cls__xcolor.def_readwrite("red", &_xcolor::red, "None");
cls__xcolor.def_readwrite("green", &_xcolor::green, "None");
cls__xcolor.def_readwrite("blue", &_xcolor::blue, "None");
cls__xcolor.def_readwrite("flags", &_xcolor::flags, "None");
cls__xcolor.def_readwrite("pad", &_xcolor::pad, "None");

// TYPEDEF: XCOLOR
if (py::hasattr(mod, "_xcolor")) {
	mod.attr("XColor") = mod.attr("_xcolor");
}


}
