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

void bind_XCAFDoc_ColorType(py::module &);
void bind_XCAFDoc_DataMapOfShapeLabel(py::module &);
void bind_XCAFDoc_DataMapIteratorOfDataMapOfShapeLabel(py::module &);
void bind_XCAFDoc_DimTolTool(py::module &);
void bind_XCAFDoc(py::module &);
void bind_XCAFDoc_Area(py::module &);
void bind_XCAFDoc_AssemblyItemId(py::module &);
void bind_XCAFDoc_AssemblyItemRef(py::module &);
void bind_XCAFDoc_Centroid(py::module &);
void bind_XCAFDoc_ClippingPlaneTool(py::module &);
void bind_XCAFDoc_Color(py::module &);
void bind_XCAFDoc_ColorTool(py::module &);
void bind_XCAFDoc_Datum(py::module &);
void bind_XCAFDoc_Dimension(py::module &);
void bind_XCAFDoc_DimTol(py::module &);
void bind_XCAFDoc_DocumentTool(py::module &);
void bind_XCAFDoc_Editor(py::module &);
void bind_XCAFDoc_GeomTolerance(py::module &);
void bind_XCAFDoc_GraphNodeSequence(py::module &);
void bind_XCAFDoc_GraphNode(py::module &);
void bind_XCAFDoc_LayerTool(py::module &);
void bind_XCAFDoc_Location(py::module &);
void bind_XCAFDoc_Material(py::module &);
void bind_XCAFDoc_MaterialTool(py::module &);
void bind_XCAFDoc_Note(py::module &);
void bind_XCAFDoc_NoteComment(py::module &);
void bind_XCAFDoc_NoteBalloon(py::module &);
void bind_XCAFDoc_NoteBinData(py::module &);
void bind_XCAFDoc_NotesTool(py::module &);
void bind_XCAFDoc_PartId(py::module &);
void bind_XCAFDoc_ShapeMapTool(py::module &);
void bind_XCAFDoc_ShapeTool(py::module &);
void bind_XCAFDoc_View(py::module &);
void bind_XCAFDoc_ViewTool(py::module &);
void bind_XCAFDoc_Volume(py::module &);

PYBIND11_MODULE(XCAFDoc, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.XCAFDimTolObjects");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.TDataStd");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.XCAFNoteObjects");
py::module::import("OCCT.OSD");
py::module::import("OCCT.XCAFView");

bind_XCAFDoc_ColorType(mod);
bind_XCAFDoc_DataMapOfShapeLabel(mod);
bind_XCAFDoc_DataMapIteratorOfDataMapOfShapeLabel(mod);
bind_XCAFDoc_DimTolTool(mod);
bind_XCAFDoc(mod);
bind_XCAFDoc_Area(mod);
bind_XCAFDoc_AssemblyItemId(mod);
bind_XCAFDoc_AssemblyItemRef(mod);
bind_XCAFDoc_Centroid(mod);
bind_XCAFDoc_ClippingPlaneTool(mod);
bind_XCAFDoc_Color(mod);
bind_XCAFDoc_ColorTool(mod);
bind_XCAFDoc_Datum(mod);
bind_XCAFDoc_Dimension(mod);
bind_XCAFDoc_DimTol(mod);
bind_XCAFDoc_DocumentTool(mod);
bind_XCAFDoc_Editor(mod);
bind_XCAFDoc_GeomTolerance(mod);
bind_XCAFDoc_GraphNodeSequence(mod);
bind_XCAFDoc_GraphNode(mod);
bind_XCAFDoc_LayerTool(mod);
bind_XCAFDoc_Location(mod);
bind_XCAFDoc_Material(mod);
bind_XCAFDoc_MaterialTool(mod);
bind_XCAFDoc_Note(mod);
bind_XCAFDoc_NoteComment(mod);
bind_XCAFDoc_NoteBalloon(mod);
bind_XCAFDoc_NoteBinData(mod);
bind_XCAFDoc_NotesTool(mod);
bind_XCAFDoc_PartId(mod);
bind_XCAFDoc_ShapeMapTool(mod);
bind_XCAFDoc_ShapeTool(mod);
bind_XCAFDoc_View(mod);
bind_XCAFDoc_ViewTool(mod);
bind_XCAFDoc_Volume(mod);

}
