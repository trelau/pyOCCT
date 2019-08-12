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

void bind_TopOpeBRepBuild_LoopEnum(py::module &);
void bind_TopOpeBRepBuild_BlockBuilder(py::module &);
void bind_TopOpeBRepBuild_BlockIterator(py::module &);
void bind_TopOpeBRepBuild_Loop(py::module &);
void bind_TopOpeBRepBuild_ListOfLoop(py::module &);
void bind_TopOpeBRepBuild_ListIteratorOfListOfLoop(py::module &);
void bind_TopOpeBRepBuild_ListOfListOfLoop(py::module &);
void bind_TopOpeBRepBuild_ListIteratorOfListOfListOfLoop(py::module &);
void bind_TopOpeBRepBuild_AreaBuilder(py::module &);
void bind_TopOpeBRepBuild_Area1dBuilder(py::module &);
void bind_TopOpeBRepBuild_Area2dBuilder(py::module &);
void bind_TopOpeBRepBuild_Area3dBuilder(py::module &);
void bind_TopOpeBRepBuild_Builder(py::module &);
void bind_TopOpeBRepBuild_Builder1(py::module &);
void bind_TopOpeBRepBuild_PBuilder(py::module &);
void bind_TopOpeBRepBuild_PGTopo(py::module &);
void bind_TopOpeBRepBuild_PWireEdgeSet(py::module &);
void bind_TopOpeBRepBuild_BuilderON(py::module &);
void bind_TopOpeBRepBuild_LoopClassifier(py::module &);
void bind_TopOpeBRepBuild_CompositeClassifier(py::module &);
void bind_TopOpeBRepBuild_CorrectFace2d(py::module &);
void bind_TopOpeBRepBuild_ShapeListOfShape(py::module &);
void bind_TopOpeBRepBuild_ListOfShapeListOfShape(py::module &);
void bind_TopOpeBRepBuild_ListIteratorOfListOfShapeListOfShape(py::module &);
void bind_TopOpeBRepBuild_DataMapOfShapeListOfShapeListOfShape(py::module &);
void bind_TopOpeBRepBuild_DataMapIteratorOfDataMapOfShapeListOfShapeListOfShape(py::module &);
void bind_TopOpeBRepBuild_ShapeSet(py::module &);
void bind_TopOpeBRepBuild_WireEdgeSet(py::module &);
void bind_TopOpeBRepBuild_ShellFaceSet(py::module &);
void bind_TopOpeBRepBuild_GTopo(py::module &);
void bind_TopOpeBRepBuild_PaveClassifier(py::module &);
void bind_TopOpeBRepBuild_Pave(py::module &);
void bind_TopOpeBRepBuild_ListOfPave(py::module &);
void bind_TopOpeBRepBuild_ListIteratorOfListOfPave(py::module &);
void bind_TopOpeBRepBuild_LoopSet(py::module &);
void bind_TopOpeBRepBuild_PaveSet(py::module &);
void bind_TopOpeBRepBuild_SolidAreaBuilder(py::module &);
void bind_TopOpeBRepBuild_SolidBuilder(py::module &);
void bind_TopOpeBRepBuild_FaceAreaBuilder(py::module &);
void bind_TopOpeBRepBuild_FaceBuilder(py::module &);
void bind_TopOpeBRepBuild_EdgeBuilder(py::module &);
void bind_TopOpeBRepBuild_HBuilder(py::module &);
void bind_TopOpeBRepBuild_FuseFace(py::module &);
void bind_TopOpeBRepBuild_GIter(py::module &);
void bind_TopOpeBRepBuild_GTool(py::module &);
void bind_TopOpeBRepBuild_VertexInfo(py::module &);
void bind_TopOpeBRepBuild_IndexedDataMapOfShapeVertexInfo(py::module &);
void bind_TopOpeBRepBuild_ShellFaceClassifier(py::module &);
void bind_TopOpeBRepBuild_ShellToSolid(py::module &);
void bind_TopOpeBRepBuild_Tools(py::module &);
void bind_TopOpeBRepBuild_Tools2d(py::module &);
void bind_TopOpeBRepBuild_WireEdgeClassifier(py::module &);
void bind_TopOpeBRepBuild_WireToFace(py::module &);

PYBIND11_MODULE(TopOpeBRepBuild, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopOpeBRepDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TopOpeBRepTool");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.BRep");
py::module::import("OCCT.BRepClass");

bind_TopOpeBRepBuild_LoopEnum(mod);
bind_TopOpeBRepBuild_BlockBuilder(mod);
bind_TopOpeBRepBuild_BlockIterator(mod);
bind_TopOpeBRepBuild_Loop(mod);
bind_TopOpeBRepBuild_ListOfLoop(mod);
bind_TopOpeBRepBuild_ListIteratorOfListOfLoop(mod);
bind_TopOpeBRepBuild_ListOfListOfLoop(mod);
bind_TopOpeBRepBuild_ListIteratorOfListOfListOfLoop(mod);
bind_TopOpeBRepBuild_AreaBuilder(mod);
bind_TopOpeBRepBuild_Area1dBuilder(mod);
bind_TopOpeBRepBuild_Area2dBuilder(mod);
bind_TopOpeBRepBuild_Area3dBuilder(mod);
bind_TopOpeBRepBuild_Builder(mod);
bind_TopOpeBRepBuild_Builder1(mod);
bind_TopOpeBRepBuild_PBuilder(mod);
bind_TopOpeBRepBuild_PGTopo(mod);
bind_TopOpeBRepBuild_PWireEdgeSet(mod);
bind_TopOpeBRepBuild_BuilderON(mod);
bind_TopOpeBRepBuild_LoopClassifier(mod);
bind_TopOpeBRepBuild_CompositeClassifier(mod);
bind_TopOpeBRepBuild_CorrectFace2d(mod);
bind_TopOpeBRepBuild_ShapeListOfShape(mod);
bind_TopOpeBRepBuild_ListOfShapeListOfShape(mod);
bind_TopOpeBRepBuild_ListIteratorOfListOfShapeListOfShape(mod);
bind_TopOpeBRepBuild_DataMapOfShapeListOfShapeListOfShape(mod);
bind_TopOpeBRepBuild_DataMapIteratorOfDataMapOfShapeListOfShapeListOfShape(mod);
bind_TopOpeBRepBuild_ShapeSet(mod);
bind_TopOpeBRepBuild_WireEdgeSet(mod);
bind_TopOpeBRepBuild_ShellFaceSet(mod);
bind_TopOpeBRepBuild_GTopo(mod);
bind_TopOpeBRepBuild_PaveClassifier(mod);
bind_TopOpeBRepBuild_Pave(mod);
bind_TopOpeBRepBuild_ListOfPave(mod);
bind_TopOpeBRepBuild_ListIteratorOfListOfPave(mod);
bind_TopOpeBRepBuild_LoopSet(mod);
bind_TopOpeBRepBuild_PaveSet(mod);
bind_TopOpeBRepBuild_SolidAreaBuilder(mod);
bind_TopOpeBRepBuild_SolidBuilder(mod);
bind_TopOpeBRepBuild_FaceAreaBuilder(mod);
bind_TopOpeBRepBuild_FaceBuilder(mod);
bind_TopOpeBRepBuild_EdgeBuilder(mod);
bind_TopOpeBRepBuild_HBuilder(mod);
bind_TopOpeBRepBuild_FuseFace(mod);
bind_TopOpeBRepBuild_GIter(mod);
bind_TopOpeBRepBuild_GTool(mod);
bind_TopOpeBRepBuild_VertexInfo(mod);
bind_TopOpeBRepBuild_IndexedDataMapOfShapeVertexInfo(mod);
bind_TopOpeBRepBuild_ShellFaceClassifier(mod);
bind_TopOpeBRepBuild_ShellToSolid(mod);
bind_TopOpeBRepBuild_Tools(mod);
bind_TopOpeBRepBuild_Tools2d(mod);
bind_TopOpeBRepBuild_WireEdgeClassifier(mod);
bind_TopOpeBRepBuild_WireToFace(mod);

}
