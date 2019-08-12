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

void bind_StepToTopoDS_BuilderError(py::module &);
void bind_StepToTopoDS_TranslateShellError(py::module &);
void bind_StepToTopoDS_TranslateFaceError(py::module &);
void bind_StepToTopoDS_TranslateEdgeError(py::module &);
void bind_StepToTopoDS_TranslateVertexError(py::module &);
void bind_StepToTopoDS_TranslateVertexLoopError(py::module &);
void bind_StepToTopoDS_TranslatePolyLoopError(py::module &);
void bind_StepToTopoDS_GeometricToolError(py::module &);
void bind_StepToTopoDS_TranslateEdgeLoopError(py::module &);
void bind_StepToTopoDS_DataMapOfRI(py::module &);
void bind_StepToTopoDS_DataMapIteratorOfDataMapOfRI(py::module &);
void bind_StepToTopoDS_DataMapOfRINames(py::module &);
void bind_StepToTopoDS_DataMapIteratorOfDataMapOfRINames(py::module &);
void bind_StepToTopoDS_NMTool(py::module &);
void bind_StepToTopoDS(py::module &);
void bind_StepToTopoDS_Root(py::module &);
void bind_StepToTopoDS_Builder(py::module &);
void bind_StepToTopoDS_CartesianPointHasher(py::module &);
void bind_StepToTopoDS_DataMapOfTRI(py::module &);
void bind_StepToTopoDS_DataMapIteratorOfDataMapOfTRI(py::module &);
void bind_StepToTopoDS_PointPair(py::module &);
void bind_StepToTopoDS_PointPairHasher(py::module &);
void bind_StepToTopoDS_PointEdgeMap(py::module &);
void bind_StepToTopoDS_DataMapIteratorOfPointEdgeMap(py::module &);
void bind_StepToTopoDS_PointVertexMap(py::module &);
void bind_StepToTopoDS_DataMapIteratorOfPointVertexMap(py::module &);
void bind_StepToTopoDS_GeometricTool(py::module &);
void bind_StepToTopoDS_MakeTransformed(py::module &);
void bind_StepToTopoDS_Tool(py::module &);
void bind_StepToTopoDS_TranslateCompositeCurve(py::module &);
void bind_StepToTopoDS_TranslateCurveBoundedSurface(py::module &);
void bind_StepToTopoDS_TranslateEdge(py::module &);
void bind_StepToTopoDS_TranslateEdgeLoop(py::module &);
void bind_StepToTopoDS_TranslateFace(py::module &);
void bind_StepToTopoDS_TranslatePolyLoop(py::module &);
void bind_StepToTopoDS_TranslateShell(py::module &);
void bind_StepToTopoDS_TranslateVertex(py::module &);
void bind_StepToTopoDS_TranslateVertexLoop(py::module &);

PYBIND11_MODULE(StepToTopoDS, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.Transfer");
py::module::import("OCCT.StepGeom");
py::module::import("OCCT.Geom");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");

bind_StepToTopoDS_BuilderError(mod);
bind_StepToTopoDS_TranslateShellError(mod);
bind_StepToTopoDS_TranslateFaceError(mod);
bind_StepToTopoDS_TranslateEdgeError(mod);
bind_StepToTopoDS_TranslateVertexError(mod);
bind_StepToTopoDS_TranslateVertexLoopError(mod);
bind_StepToTopoDS_TranslatePolyLoopError(mod);
bind_StepToTopoDS_GeometricToolError(mod);
bind_StepToTopoDS_TranslateEdgeLoopError(mod);
bind_StepToTopoDS_DataMapOfRI(mod);
bind_StepToTopoDS_DataMapIteratorOfDataMapOfRI(mod);
bind_StepToTopoDS_DataMapOfRINames(mod);
bind_StepToTopoDS_DataMapIteratorOfDataMapOfRINames(mod);
bind_StepToTopoDS_NMTool(mod);
bind_StepToTopoDS(mod);
bind_StepToTopoDS_Root(mod);
bind_StepToTopoDS_Builder(mod);
bind_StepToTopoDS_CartesianPointHasher(mod);
bind_StepToTopoDS_DataMapOfTRI(mod);
bind_StepToTopoDS_DataMapIteratorOfDataMapOfTRI(mod);
bind_StepToTopoDS_PointPair(mod);
bind_StepToTopoDS_PointPairHasher(mod);
bind_StepToTopoDS_PointEdgeMap(mod);
bind_StepToTopoDS_DataMapIteratorOfPointEdgeMap(mod);
bind_StepToTopoDS_PointVertexMap(mod);
bind_StepToTopoDS_DataMapIteratorOfPointVertexMap(mod);
bind_StepToTopoDS_GeometricTool(mod);
bind_StepToTopoDS_MakeTransformed(mod);
bind_StepToTopoDS_Tool(mod);
bind_StepToTopoDS_TranslateCompositeCurve(mod);
bind_StepToTopoDS_TranslateCurveBoundedSurface(mod);
bind_StepToTopoDS_TranslateEdge(mod);
bind_StepToTopoDS_TranslateEdgeLoop(mod);
bind_StepToTopoDS_TranslateFace(mod);
bind_StepToTopoDS_TranslatePolyLoop(mod);
bind_StepToTopoDS_TranslateShell(mod);
bind_StepToTopoDS_TranslateVertex(mod);
bind_StepToTopoDS_TranslateVertexLoop(mod);

}
