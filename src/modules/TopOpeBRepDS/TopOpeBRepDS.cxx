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

void bind_TopOpeBRepDS_Config(py::module &);
void bind_TopOpeBRepDS_Kind(py::module &);
void bind_TopOpeBRepDS_CheckStatus(py::module &);
void bind_TopOpeBRepDS_Transition(py::module &);
void bind_TopOpeBRepDS_Interference(py::module &);
void bind_TopOpeBRepDS_ListOfInterference(py::module &);
void bind_TopOpeBRepDS_ListIteratorOfListOfInterference(py::module &);
void bind_TopOpeBRepDS_ShapeShapeInterference(py::module &);
void bind_TopOpeBRepDS_CurvePointInterference(py::module &);
void bind_TopOpeBRepDS_EdgeVertexInterference(py::module &);
void bind_TopOpeBRepDS_FaceEdgeInterference(py::module &);
void bind_TopOpeBRepDS_InterferenceIterator(py::module &);
void bind_TopOpeBRepDS_Surface(py::module &);
void bind_TopOpeBRepDS_GeometryData(py::module &);
void bind_TopOpeBRepDS_SurfaceData(py::module &);
void bind_TopOpeBRepDS_MapOfSurface(py::module &);
void bind_TopOpeBRepDS_DataMapIteratorOfMapOfSurface(py::module &);
void bind_TopOpeBRepDS_Curve(py::module &);
void bind_TopOpeBRepDS_CurveData(py::module &);
void bind_TopOpeBRepDS_MapOfCurve(py::module &);
void bind_TopOpeBRepDS_DataMapIteratorOfMapOfCurve(py::module &);
void bind_TopOpeBRepDS_Point(py::module &);
void bind_TopOpeBRepDS_PointData(py::module &);
void bind_TopOpeBRepDS_MapOfPoint(py::module &);
void bind_TopOpeBRepDS_DataMapIteratorOfMapOfPoint(py::module &);
void bind_TopOpeBRepDS_ShapeData(py::module &);
void bind_TopOpeBRepDS_MapOfShapeData(py::module &);
void bind_TopOpeBRepDS_ShapeSurface(py::module &);
void bind_TopOpeBRepDS_DataMapIteratorOfShapeSurface(py::module &);
void bind_TopOpeBRepDS_ShapeWithState(py::module &);
void bind_TopOpeBRepDS_IndexedDataMapOfShapeWithState(py::module &);
void bind_TopOpeBRepDS_DataStructure(py::module &);
void bind_TopOpeBRepDS_HDataStructure(py::module &);
void bind_TopOpeBRepDS_PDataStructure(py::module &);
void bind_TopOpeBRepDS_SurfaceCurveInterference(py::module &);
void bind_TopOpeBRepDS_BuildTool(py::module &);
void bind_TopOpeBRepDS_ListOfShapeOn1State(py::module &);
void bind_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State(py::module &);
void bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfShapeListOfShapeOn1State(py::module &);
void bind_TopOpeBRepDS_DataMapOfShapeState(py::module &);
void bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfShapeState(py::module &);
void bind_TopOpeBRepDS(py::module &);
void bind_TopOpeBRepDS_DataMapOfIntegerListOfInterference(py::module &);
void bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference(py::module &);
void bind_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference(py::module &);
void bind_TopOpeBRepDS_DataMapOfInterferenceListOfInterference(py::module &);
void bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfInterferenceListOfInterference(py::module &);
void bind_TopOpeBRepDS_Association(py::module &);
void bind_TopOpeBRepDS_DataMapOfCheckStatus(py::module &);
void bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfCheckStatus(py::module &);
void bind_TopOpeBRepDS_Check(py::module &);
void bind_TopOpeBRepDS_CurveExplorer(py::module &);
void bind_TopOpeBRepDS_CurveIterator(py::module &);
void bind_TopOpeBRepDS_DataMapOfInterferenceShape(py::module &);
void bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfInterferenceShape(py::module &);
void bind_TopOpeBRepDS_MapOfIntegerShapeData(py::module &);
void bind_TopOpeBRepDS_DataMapIteratorOfMapOfIntegerShapeData(py::module &);
void bind_TopOpeBRepDS_DoubleMapOfIntegerShape(py::module &);
void bind_TopOpeBRepDS_DoubleMapIteratorOfDoubleMapOfIntegerShape(py::module &);
void bind_TopOpeBRepDS_Dumper(py::module &);
void bind_TopOpeBRepDS_Edge3dInterferenceTool(py::module &);
void bind_TopOpeBRepDS_EdgeInterferenceTool(py::module &);
void bind_TopOpeBRepDS_EIR(py::module &);
void bind_TopOpeBRepDS_Explorer(py::module &);
void bind_TopOpeBRepDS_FaceInterferenceTool(py::module &);
void bind_TopOpeBRepDS_Filter(py::module &);
void bind_TopOpeBRepDS_FIR(py::module &);
void bind_TopOpeBRepDS_GapFiller(py::module &);
void bind_TopOpeBRepDS_GapTool(py::module &);
void bind_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference(py::module &);
void bind_TopOpeBRepDS_IndexedDataMapOfVertexPoint(py::module &);
void bind_TopOpeBRepDS_InterferenceTool(py::module &);
void bind_TopOpeBRepDS_Marker(py::module &);
void bind_TopOpeBRepDS_PointExplorer(py::module &);
void bind_TopOpeBRepDS_PointIterator(py::module &);
void bind_TopOpeBRepDS_Reducer(py::module &);
void bind_TopOpeBRepDS_SolidSurfaceInterference(py::module &);
void bind_TopOpeBRepDS_SurfaceExplorer(py::module &);
void bind_TopOpeBRepDS_SurfaceIterator(py::module &);
void bind_TopOpeBRepDS_TKI(py::module &);
void bind_TopOpeBRepDS_TOOL(py::module &);

PYBIND11_MODULE(TopOpeBRepDS, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TopOpeBRepTool");
py::module::import("OCCT.BRep");
py::module::import("OCCT.TopTrans");

bind_TopOpeBRepDS_Config(mod);
bind_TopOpeBRepDS_Kind(mod);
bind_TopOpeBRepDS_CheckStatus(mod);
bind_TopOpeBRepDS_Transition(mod);
bind_TopOpeBRepDS_Interference(mod);
bind_TopOpeBRepDS_ListOfInterference(mod);
bind_TopOpeBRepDS_ListIteratorOfListOfInterference(mod);
bind_TopOpeBRepDS_ShapeShapeInterference(mod);
bind_TopOpeBRepDS_CurvePointInterference(mod);
bind_TopOpeBRepDS_EdgeVertexInterference(mod);
bind_TopOpeBRepDS_FaceEdgeInterference(mod);
bind_TopOpeBRepDS_InterferenceIterator(mod);
bind_TopOpeBRepDS_Surface(mod);
bind_TopOpeBRepDS_GeometryData(mod);
bind_TopOpeBRepDS_SurfaceData(mod);
bind_TopOpeBRepDS_MapOfSurface(mod);
bind_TopOpeBRepDS_DataMapIteratorOfMapOfSurface(mod);
bind_TopOpeBRepDS_Curve(mod);
bind_TopOpeBRepDS_CurveData(mod);
bind_TopOpeBRepDS_MapOfCurve(mod);
bind_TopOpeBRepDS_DataMapIteratorOfMapOfCurve(mod);
bind_TopOpeBRepDS_Point(mod);
bind_TopOpeBRepDS_PointData(mod);
bind_TopOpeBRepDS_MapOfPoint(mod);
bind_TopOpeBRepDS_DataMapIteratorOfMapOfPoint(mod);
bind_TopOpeBRepDS_ShapeData(mod);
bind_TopOpeBRepDS_MapOfShapeData(mod);
bind_TopOpeBRepDS_ShapeSurface(mod);
bind_TopOpeBRepDS_DataMapIteratorOfShapeSurface(mod);
bind_TopOpeBRepDS_ShapeWithState(mod);
bind_TopOpeBRepDS_IndexedDataMapOfShapeWithState(mod);
bind_TopOpeBRepDS_DataStructure(mod);
bind_TopOpeBRepDS_HDataStructure(mod);
bind_TopOpeBRepDS_PDataStructure(mod);
bind_TopOpeBRepDS_SurfaceCurveInterference(mod);
bind_TopOpeBRepDS_BuildTool(mod);
bind_TopOpeBRepDS_ListOfShapeOn1State(mod);
bind_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State(mod);
bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfShapeListOfShapeOn1State(mod);
bind_TopOpeBRepDS_DataMapOfShapeState(mod);
bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfShapeState(mod);
bind_TopOpeBRepDS(mod);
bind_TopOpeBRepDS_DataMapOfIntegerListOfInterference(mod);
bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference(mod);
bind_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference(mod);
bind_TopOpeBRepDS_DataMapOfInterferenceListOfInterference(mod);
bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfInterferenceListOfInterference(mod);
bind_TopOpeBRepDS_Association(mod);
bind_TopOpeBRepDS_DataMapOfCheckStatus(mod);
bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfCheckStatus(mod);
bind_TopOpeBRepDS_Check(mod);
bind_TopOpeBRepDS_CurveExplorer(mod);
bind_TopOpeBRepDS_CurveIterator(mod);
bind_TopOpeBRepDS_DataMapOfInterferenceShape(mod);
bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfInterferenceShape(mod);
bind_TopOpeBRepDS_MapOfIntegerShapeData(mod);
bind_TopOpeBRepDS_DataMapIteratorOfMapOfIntegerShapeData(mod);
bind_TopOpeBRepDS_DoubleMapOfIntegerShape(mod);
bind_TopOpeBRepDS_DoubleMapIteratorOfDoubleMapOfIntegerShape(mod);
bind_TopOpeBRepDS_Dumper(mod);
bind_TopOpeBRepDS_Edge3dInterferenceTool(mod);
bind_TopOpeBRepDS_EdgeInterferenceTool(mod);
bind_TopOpeBRepDS_EIR(mod);
bind_TopOpeBRepDS_Explorer(mod);
bind_TopOpeBRepDS_FaceInterferenceTool(mod);
bind_TopOpeBRepDS_Filter(mod);
bind_TopOpeBRepDS_FIR(mod);
bind_TopOpeBRepDS_GapFiller(mod);
bind_TopOpeBRepDS_GapTool(mod);
bind_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference(mod);
bind_TopOpeBRepDS_IndexedDataMapOfVertexPoint(mod);
bind_TopOpeBRepDS_InterferenceTool(mod);
bind_TopOpeBRepDS_Marker(mod);
bind_TopOpeBRepDS_PointExplorer(mod);
bind_TopOpeBRepDS_PointIterator(mod);
bind_TopOpeBRepDS_Reducer(mod);
bind_TopOpeBRepDS_SolidSurfaceInterference(mod);
bind_TopOpeBRepDS_SurfaceExplorer(mod);
bind_TopOpeBRepDS_SurfaceIterator(mod);
bind_TopOpeBRepDS_TKI(mod);
bind_TopOpeBRepDS_TOOL(mod);

}
