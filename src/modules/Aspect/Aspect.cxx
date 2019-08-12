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

void bind_Aspect_TypeOfDeflection(py::module &);
void bind_Aspect_TypeOfHighlightMethod(py::module &);
void bind_Aspect_InteriorStyle(py::module &);
void bind_Aspect_TypeOfLine(py::module &);
void bind_Aspect_HatchStyle(py::module &);
void bind_Aspect_TypeOfMarker(py::module &);
void bind_Aspect_GradientFillMethod(py::module &);
void bind_Aspect_FillMethod(py::module &);
void bind_Aspect_TypeOfResize(py::module &);
void bind_Aspect_TypeOfStyleText(py::module &);
void bind_Aspect_TypeOfDisplayText(py::module &);
void bind_Aspect_TypeOfTriedronPosition(py::module &);
void bind_Aspect_TypeOfFacingModel(py::module &);
void bind_Aspect_TypeOfColorScaleData(py::module &);
void bind_Aspect_TypeOfColorScalePosition(py::module &);
void bind_Aspect_GridDrawMode(py::module &);
void bind_Aspect_GridType(py::module &);
void bind_Aspect_XAtom(py::module &);
void bind_Aspect_TypeOfColorScaleOrientation(py::module &);
void bind_Aspect_WidthOfLine(py::module &);
void bind_Aspect_AspectFillAreaDefinitionError(py::module &);
void bind_Aspect_PolygonOffsetMode(py::module &);
void bind_Aspect_GenId(py::module &);
void bind_HANDLE(py::module &);
void bind_Aspect_Handle(py::module &);
void bind_Aspect_RenderingContext(py::module &);
void bind_Aspect_Background(py::module &);
void bind_Aspect_GradientBackground(py::module &);
void bind_Aspect_FBConfig(py::module &);
void bind_Aspect_Drawable(py::module &);
void bind_Aspect_Window(py::module &);
void bind_Aspect_AspectLineDefinitionError(py::module &);
void bind_Aspect_AspectMarkerDefinitionError(py::module &);
void bind_Aspect_SequenceOfColor(py::module &);
void bind_Aspect_Grid(py::module &);
void bind_Aspect_CircularGrid(py::module &);
void bind_Aspect_Display(py::module &);
void bind_Aspect_DisplayConnection(py::module &);
void bind_Aspect_DisplayConnectionDefinitionError(py::module &);
void bind_Aspect_GraphicDeviceDefinitionError(py::module &);
void bind_Aspect_IdentDefinitionError(py::module &);
void bind_Aspect_NeutralWindow(py::module &);
void bind_Aspect_RectangularGrid(py::module &);
void bind_Aspect_WindowDefinitionError(py::module &);
void bind_Aspect_WindowError(py::module &);
void bind_CARD32(py::module &);
void bind__xwd_file_header(py::module &);
void bind_XWDFileHeader(py::module &);
void bind__xcolor(py::module &);
void bind_XColor(py::module &);

PYBIND11_MODULE(Aspect, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.NCollection");

bind_Aspect_TypeOfDeflection(mod);
bind_Aspect_TypeOfHighlightMethod(mod);
bind_Aspect_InteriorStyle(mod);
bind_Aspect_TypeOfLine(mod);
bind_Aspect_HatchStyle(mod);
bind_Aspect_TypeOfMarker(mod);
bind_Aspect_GradientFillMethod(mod);
bind_Aspect_FillMethod(mod);
bind_Aspect_TypeOfResize(mod);
bind_Aspect_TypeOfStyleText(mod);
bind_Aspect_TypeOfDisplayText(mod);
bind_Aspect_TypeOfTriedronPosition(mod);
bind_Aspect_TypeOfFacingModel(mod);
bind_Aspect_TypeOfColorScaleData(mod);
bind_Aspect_TypeOfColorScalePosition(mod);
bind_Aspect_GridDrawMode(mod);
bind_Aspect_GridType(mod);
bind_Aspect_XAtom(mod);
bind_Aspect_TypeOfColorScaleOrientation(mod);
bind_Aspect_WidthOfLine(mod);
bind_Aspect_AspectFillAreaDefinitionError(mod);
bind_Aspect_PolygonOffsetMode(mod);
bind_Aspect_GenId(mod);
bind_HANDLE(mod);
bind_Aspect_Handle(mod);
bind_Aspect_RenderingContext(mod);
bind_Aspect_Background(mod);
bind_Aspect_GradientBackground(mod);
bind_Aspect_FBConfig(mod);
bind_Aspect_Drawable(mod);
bind_Aspect_Window(mod);
bind_Aspect_AspectLineDefinitionError(mod);
bind_Aspect_AspectMarkerDefinitionError(mod);
bind_Aspect_SequenceOfColor(mod);
bind_Aspect_Grid(mod);
bind_Aspect_CircularGrid(mod);
bind_Aspect_Display(mod);
bind_Aspect_DisplayConnection(mod);
bind_Aspect_DisplayConnectionDefinitionError(mod);
bind_Aspect_GraphicDeviceDefinitionError(mod);
bind_Aspect_IdentDefinitionError(mod);
bind_Aspect_NeutralWindow(mod);
bind_Aspect_RectangularGrid(mod);
bind_Aspect_WindowDefinitionError(mod);
bind_Aspect_WindowError(mod);
bind_CARD32(mod);
bind__xwd_file_header(mod);
bind_XWDFileHeader(mod);
bind__xcolor(mod);
bind_XColor(mod);

}
