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

void bind_IGESDraw_ConnectPoint(py::module &);
void bind_IGESDraw_Array1OfConnectPoint(py::module &);
void bind_IGESDraw_HArray1OfConnectPoint(py::module &);
void bind_IGESDraw(py::module &);
void bind_IGESDraw_Array1OfViewKindEntity(py::module &);
void bind_IGESDraw_CircArraySubfigure(py::module &);
void bind_IGESDraw_HArray1OfViewKindEntity(py::module &);
void bind_IGESDraw_Drawing(py::module &);
void bind_IGESDraw_DrawingWithRotation(py::module &);
void bind_IGESDraw_GeneralModule(py::module &);
void bind_IGESDraw_LabelDisplay(py::module &);
void bind_IGESDraw_NetworkSubfigure(py::module &);
void bind_IGESDraw_NetworkSubfigureDef(py::module &);
void bind_IGESDraw_PerspectiveView(py::module &);
void bind_IGESDraw_Planar(py::module &);
void bind_IGESDraw_Protocol(py::module &);
void bind_IGESDraw_ReadWriteModule(py::module &);
void bind_IGESDraw_RectArraySubfigure(py::module &);
void bind_IGESDraw_SegmentedViewsVisible(py::module &);
void bind_IGESDraw_SpecificModule(py::module &);
void bind_IGESDraw_ToolCircArraySubfigure(py::module &);
void bind_IGESDraw_ToolConnectPoint(py::module &);
void bind_IGESDraw_ToolDrawing(py::module &);
void bind_IGESDraw_ToolDrawingWithRotation(py::module &);
void bind_IGESDraw_ToolLabelDisplay(py::module &);
void bind_IGESDraw_ToolNetworkSubfigure(py::module &);
void bind_IGESDraw_ToolNetworkSubfigureDef(py::module &);
void bind_IGESDraw_ToolPerspectiveView(py::module &);
void bind_IGESDraw_ToolPlanar(py::module &);
void bind_IGESDraw_ToolRectArraySubfigure(py::module &);
void bind_IGESDraw_ToolSegmentedViewsVisible(py::module &);
void bind_IGESDraw_ToolView(py::module &);
void bind_IGESDraw_ToolViewsVisible(py::module &);
void bind_IGESDraw_ToolViewsVisibleWithAttr(py::module &);
void bind_IGESDraw_View(py::module &);
void bind_IGESDraw_ViewsVisible(py::module &);
void bind_IGESDraw_ViewsVisibleWithAttr(py::module &);

PYBIND11_MODULE(IGESDraw, mod) {

py::module::import("OCCT.IGESData");
py::module::import("OCCT.gp");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.IGESGraph");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Interface");
py::module::import("OCCT.IGESDimen");
py::module::import("OCCT.IGESGeom");
py::module::import("OCCT.IGESBasic");
py::module::import("OCCT.Message");

bind_IGESDraw_ConnectPoint(mod);
bind_IGESDraw_Array1OfConnectPoint(mod);
bind_IGESDraw_HArray1OfConnectPoint(mod);
bind_IGESDraw(mod);
bind_IGESDraw_Array1OfViewKindEntity(mod);
bind_IGESDraw_CircArraySubfigure(mod);
bind_IGESDraw_HArray1OfViewKindEntity(mod);
bind_IGESDraw_Drawing(mod);
bind_IGESDraw_DrawingWithRotation(mod);
bind_IGESDraw_GeneralModule(mod);
bind_IGESDraw_LabelDisplay(mod);
bind_IGESDraw_NetworkSubfigure(mod);
bind_IGESDraw_NetworkSubfigureDef(mod);
bind_IGESDraw_PerspectiveView(mod);
bind_IGESDraw_Planar(mod);
bind_IGESDraw_Protocol(mod);
bind_IGESDraw_ReadWriteModule(mod);
bind_IGESDraw_RectArraySubfigure(mod);
bind_IGESDraw_SegmentedViewsVisible(mod);
bind_IGESDraw_SpecificModule(mod);
bind_IGESDraw_ToolCircArraySubfigure(mod);
bind_IGESDraw_ToolConnectPoint(mod);
bind_IGESDraw_ToolDrawing(mod);
bind_IGESDraw_ToolDrawingWithRotation(mod);
bind_IGESDraw_ToolLabelDisplay(mod);
bind_IGESDraw_ToolNetworkSubfigure(mod);
bind_IGESDraw_ToolNetworkSubfigureDef(mod);
bind_IGESDraw_ToolPerspectiveView(mod);
bind_IGESDraw_ToolPlanar(mod);
bind_IGESDraw_ToolRectArraySubfigure(mod);
bind_IGESDraw_ToolSegmentedViewsVisible(mod);
bind_IGESDraw_ToolView(mod);
bind_IGESDraw_ToolViewsVisible(mod);
bind_IGESDraw_ToolViewsVisibleWithAttr(mod);
bind_IGESDraw_View(mod);
bind_IGESDraw_ViewsVisible(mod);
bind_IGESDraw_ViewsVisibleWithAttr(mod);

}
