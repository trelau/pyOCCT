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

void bind_BRepMesh_DegreeOfFreedom(py::module &);
void bind_BRepMesh_FactoryError(py::module &);
void bind_BRepMesh_Status(py::module &);
void bind_HashCode(py::module &);
void bind_BRepMesh_OrientedEdge(py::module &);
void bind_BRepMesh_Edge(py::module &);
void bind_BRepMesh_Triangle(py::module &);
void bind_BRepMesh_PairOfPolygon(py::module &);
void bind_BRepMesh_PairOfIndex(py::module &);
void bind_BRepMesh_Circle(py::module &);
void bind_BRepMesh_CircleInspector(py::module &);
void bind_BRepMesh_CircleTool(py::module &);
void bind_BRepMesh_Classifier(py::module &);
void bind_BRepMesh_Vertex(py::module &);
void bind_BRepMesh_VertexInspector(py::module &);
void bind_BRepMesh_VertexTool(py::module &);
void bind_BRepMesh_DataStructureOfDelaun(py::module &);
void bind_BRepMesh_GeomTool(py::module &);
void bind_BRepMesh_Delaun(py::module &);
void bind_BRepMesh_PluginEntryType(py::module &);
void bind_BRepMesh_DiscretRoot(py::module &);
void bind_BRepMesh_DiscretFactory(py::module &);
void bind_BRepMesh_EdgeParameterProvider(py::module &);
void bind_BRepMesh_IEdgeTool(py::module &);
void bind_BRepMesh_EdgeTessellationExtractor(py::module &);
void bind_BRepMesh_FaceAttribute(py::module &);
void bind_BRepMesh_EdgeTessellator(py::module &);
void bind_BRepMesh_ShapeTool(py::module &);
void bind_BRepMesh_FastDiscret(py::module &);
void bind_BRepMesh_FastDiscretFace(py::module &);
void bind_BRepMesh_IncrementalMesh(py::module &);
void bind_BRepMesh_SelectorOfDataStructureOfDelaun(py::module &);
void bind_BRepMesh_WireChecker(py::module &);
void bind_BRepMesh_WireInterferenceChecker(py::module &);

PYBIND11_MODULE(BRepMesh, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Poly");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Precision");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.BRepTopAdaptor");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.GCPnts");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Plugin");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.BRep");

bind_BRepMesh_DegreeOfFreedom(mod);
bind_BRepMesh_FactoryError(mod);
bind_BRepMesh_Status(mod);
bind_HashCode(mod);
bind_BRepMesh_OrientedEdge(mod);
bind_BRepMesh_Edge(mod);
bind_BRepMesh_Triangle(mod);
bind_BRepMesh_PairOfPolygon(mod);
bind_BRepMesh_PairOfIndex(mod);
bind_BRepMesh_Circle(mod);
bind_BRepMesh_CircleInspector(mod);
bind_BRepMesh_CircleTool(mod);
bind_BRepMesh_Classifier(mod);
bind_BRepMesh_Vertex(mod);
bind_BRepMesh_VertexInspector(mod);
bind_BRepMesh_VertexTool(mod);
bind_BRepMesh_DataStructureOfDelaun(mod);
bind_BRepMesh_GeomTool(mod);
bind_BRepMesh_Delaun(mod);
bind_BRepMesh_PluginEntryType(mod);
bind_BRepMesh_DiscretRoot(mod);
bind_BRepMesh_DiscretFactory(mod);
bind_BRepMesh_EdgeParameterProvider(mod);
bind_BRepMesh_IEdgeTool(mod);
bind_BRepMesh_EdgeTessellationExtractor(mod);
bind_BRepMesh_FaceAttribute(mod);
bind_BRepMesh_EdgeTessellator(mod);
bind_BRepMesh_ShapeTool(mod);
bind_BRepMesh_FastDiscret(mod);
bind_BRepMesh_FastDiscretFace(mod);
bind_BRepMesh_IncrementalMesh(mod);
bind_BRepMesh_SelectorOfDataStructureOfDelaun(mod);
bind_BRepMesh_WireChecker(mod);
bind_BRepMesh_WireInterferenceChecker(mod);

}
