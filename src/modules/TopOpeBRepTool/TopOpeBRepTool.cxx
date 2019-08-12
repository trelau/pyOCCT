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

void bind_TopOpeBRepTool_OutCurveType(py::module &);
void bind_TopOpeBRepTool_ShapeExplorer(py::module &);
void bind_TopOpeBRepTool_BoxSort(py::module &);
void bind_TopOpeBRepTool_PShapeClassifier(py::module &);
void bind_TopOpeBRepTool_GeomTool(py::module &);
void bind_TopOpeBRepTool_CurveTool(py::module &);
void bind_TopOpeBRepTool_Plos(py::module &);
void bind_TopOpeBRepTool_PSoClassif(py::module &);
void bind_TopOpeBRepTool_SolidClassifier(py::module &);
void bind_TopOpeBRepTool_ShapeClassifier(py::module &);
void bind_TopOpeBRepTool(py::module &);
void bind_TopOpeBRepTool_AncestorsTool(py::module &);
void bind_TopOpeBRepTool_IndexedDataMapOfShapeBox(py::module &);
void bind_TopOpeBRepTool_HBoxTool(py::module &);
void bind_TopOpeBRepTool_C2DF(py::module &);
void bind_TopOpeBRepTool_IndexedDataMapOfShapeBox2d(py::module &);
void bind_TopOpeBRepTool_face(py::module &);
void bind_TopOpeBRepTool_DataMapOfShapeface(py::module &);
void bind_TopOpeBRepTool_DataMapIteratorOfDataMapOfShapeface(py::module &);
void bind_TopOpeBRepTool_CLASSI(py::module &);
void bind_TopOpeBRepTool_connexity(py::module &);
void bind_TopOpeBRepTool_DataMapOfOrientedShapeC2DF(py::module &);
void bind_TopOpeBRepTool_DataMapIteratorOfDataMapOfOrientedShapeC2DF(py::module &);
void bind_TopOpeBRepTool_CORRISO(py::module &);
void bind_TopOpeBRepTool_ListOfC2DF(py::module &);
void bind_TopOpeBRepTool_ListIteratorOfListOfC2DF(py::module &);
void bind_TopOpeBRepTool_DataMapOfShapeListOfC2DF(py::module &);
void bind_TopOpeBRepTool_DataMapIteratorOfDataMapOfShapeListOfC2DF(py::module &);
void bind_TopOpeBRepTool_FuseEdges(py::module &);
void bind_TopOpeBRepTool_IndexedDataMapOfShapeconnexity(py::module &);
void bind_TopOpeBRepTool_IndexedDataMapOfSolidClassifier(py::module &);
void bind_TopOpeBRepTool_makeTransition(py::module &);
void bind_TopOpeBRepTool_mkTondgE(py::module &);
void bind_TopOpeBRepTool_PurgeInternalEdges(py::module &);
void bind_TopOpeBRepTool_REGUS(py::module &);
void bind_TopOpeBRepTool_REGUW(py::module &);
void bind_TopOpeBRepTool_ShapeTool(py::module &);
void bind_TopOpeBRepTool_TOOL(py::module &);

PYBIND11_MODULE(TopOpeBRepTool, mod) {

py::module::import("OCCT.TopExp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.BRepClass3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.BRep");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.BRepAdaptor");

bind_TopOpeBRepTool_OutCurveType(mod);
bind_TopOpeBRepTool_ShapeExplorer(mod);
bind_TopOpeBRepTool_BoxSort(mod);
bind_TopOpeBRepTool_PShapeClassifier(mod);
bind_TopOpeBRepTool_GeomTool(mod);
bind_TopOpeBRepTool_CurveTool(mod);
bind_TopOpeBRepTool_Plos(mod);
bind_TopOpeBRepTool_PSoClassif(mod);
bind_TopOpeBRepTool_SolidClassifier(mod);
bind_TopOpeBRepTool_ShapeClassifier(mod);
bind_TopOpeBRepTool(mod);
bind_TopOpeBRepTool_AncestorsTool(mod);
bind_TopOpeBRepTool_IndexedDataMapOfShapeBox(mod);
bind_TopOpeBRepTool_HBoxTool(mod);
bind_TopOpeBRepTool_C2DF(mod);
bind_TopOpeBRepTool_IndexedDataMapOfShapeBox2d(mod);
bind_TopOpeBRepTool_face(mod);
bind_TopOpeBRepTool_DataMapOfShapeface(mod);
bind_TopOpeBRepTool_DataMapIteratorOfDataMapOfShapeface(mod);
bind_TopOpeBRepTool_CLASSI(mod);
bind_TopOpeBRepTool_connexity(mod);
bind_TopOpeBRepTool_DataMapOfOrientedShapeC2DF(mod);
bind_TopOpeBRepTool_DataMapIteratorOfDataMapOfOrientedShapeC2DF(mod);
bind_TopOpeBRepTool_CORRISO(mod);
bind_TopOpeBRepTool_ListOfC2DF(mod);
bind_TopOpeBRepTool_ListIteratorOfListOfC2DF(mod);
bind_TopOpeBRepTool_DataMapOfShapeListOfC2DF(mod);
bind_TopOpeBRepTool_DataMapIteratorOfDataMapOfShapeListOfC2DF(mod);
bind_TopOpeBRepTool_FuseEdges(mod);
bind_TopOpeBRepTool_IndexedDataMapOfShapeconnexity(mod);
bind_TopOpeBRepTool_IndexedDataMapOfSolidClassifier(mod);
bind_TopOpeBRepTool_makeTransition(mod);
bind_TopOpeBRepTool_mkTondgE(mod);
bind_TopOpeBRepTool_PurgeInternalEdges(mod);
bind_TopOpeBRepTool_REGUS(mod);
bind_TopOpeBRepTool_REGUW(mod);
bind_TopOpeBRepTool_ShapeTool(mod);
bind_TopOpeBRepTool_TOOL(mod);

}
