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

void bind_Prs3d_VertexDrawMode(py::module &);
void bind_Prs3d_TypeOfHLR(py::module &);
void bind_Prs3d_DimensionArrowOrientation(py::module &);
void bind_Prs3d_DimensionTextHorizontalPosition(py::module &);
void bind_Prs3d_DimensionTextVerticalPosition(py::module &);
void bind_Prs3d_TypeOfHighlight(py::module &);
void bind_Prs3d_DatumAttribute(py::module &);
void bind_Prs3d_DatumAxes(py::module &);
void bind_Prs3d_DatumMode(py::module &);
void bind_Prs3d_DatumParts(py::module &);
void bind_Prs3d_TypeOfLinePicking(py::module &);
void bind_Prs3d_DimensionUnits(py::module &);
void bind_Prs3d_Drawer(py::module &);
void bind_Graphic3d_HighlightStyle(py::module &);
void bind_Prs3d_Presentation(py::module &);
void bind_Prs3d_BasicAspect(py::module &);
void bind_Prs3d_ArrowAspect(py::module &);
void bind_Prs3d_LineAspect(py::module &);
void bind_Prs3d_TextAspect(py::module &);
void bind_Prs3d_DimensionAspect(py::module &);
void bind_Prs3d_Projector(py::module &);
void bind_Prs3d_ShadingAspect(py::module &);
void bind_Prs3d_PointAspect(py::module &);
void bind_Prs3d_DatumAspect(py::module &);
void bind_Prs3d_Root(py::module &);
void bind_Prs3d_NListOfSequenceOfPnt(py::module &);
void bind_Prs3d(py::module &);
void bind_Prs3d_Arrow(py::module &);
void bind_Prs3d_InvalidAngle(py::module &);
void bind_Prs3d_IsoAspect(py::module &);
void bind_Prs3d_NListIteratorOfListOfSequenceOfPnt(py::module &);
void bind_Prs3d_PlaneAspect(py::module &);
void bind_Prs3d_PresentationShadow(py::module &);
void bind_Prs3d_ShapeTool(py::module &);
void bind_Prs3d_Text(py::module &);
void bind_Prs3d_ToolQuadric(py::module &);
void bind_Prs3d_ToolCylinder(py::module &);
void bind_Prs3d_ToolDisk(py::module &);
void bind_Prs3d_ToolSphere(py::module &);

PYBIND11_MODULE(Prs3d, mod) {

py::module::import("OCCT.TCollection");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Aspect");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.HLRAlgo");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Poly");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.TopExp");

bind_Prs3d_VertexDrawMode(mod);
bind_Prs3d_TypeOfHLR(mod);
bind_Prs3d_DimensionArrowOrientation(mod);
bind_Prs3d_DimensionTextHorizontalPosition(mod);
bind_Prs3d_DimensionTextVerticalPosition(mod);
bind_Prs3d_TypeOfHighlight(mod);
bind_Prs3d_DatumAttribute(mod);
bind_Prs3d_DatumAxes(mod);
bind_Prs3d_DatumMode(mod);
bind_Prs3d_DatumParts(mod);
bind_Prs3d_TypeOfLinePicking(mod);
bind_Prs3d_DimensionUnits(mod);
bind_Prs3d_Drawer(mod);
bind_Graphic3d_HighlightStyle(mod);
bind_Prs3d_Presentation(mod);
bind_Prs3d_BasicAspect(mod);
bind_Prs3d_ArrowAspect(mod);
bind_Prs3d_LineAspect(mod);
bind_Prs3d_TextAspect(mod);
bind_Prs3d_DimensionAspect(mod);
bind_Prs3d_Projector(mod);
bind_Prs3d_ShadingAspect(mod);
bind_Prs3d_PointAspect(mod);
bind_Prs3d_DatumAspect(mod);
bind_Prs3d_Root(mod);
bind_Prs3d_NListOfSequenceOfPnt(mod);
bind_Prs3d(mod);
bind_Prs3d_Arrow(mod);
bind_Prs3d_InvalidAngle(mod);
bind_Prs3d_IsoAspect(mod);
bind_Prs3d_NListIteratorOfListOfSequenceOfPnt(mod);
bind_Prs3d_PlaneAspect(mod);
bind_Prs3d_PresentationShadow(mod);
bind_Prs3d_ShapeTool(mod);
bind_Prs3d_Text(mod);
bind_Prs3d_ToolQuadric(mod);
bind_Prs3d_ToolCylinder(mod);
bind_Prs3d_ToolDisk(mod);
bind_Prs3d_ToolSphere(mod);

}
