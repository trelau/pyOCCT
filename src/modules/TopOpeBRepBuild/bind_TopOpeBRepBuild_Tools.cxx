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
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_State.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopOpeBRepDS_DataMapOfShapeState.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopOpeBRepTool_ShapeClassifier.hxx>
#include <TopOpeBRepDS_IndexedDataMapOfShapeWithState.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Vec.hxx>
#include <TopoDS_Wire.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopOpeBRepBuild_Tools.hxx>

void bind_TopOpeBRepBuild_Tools(py::module &mod){

py::class_<TopOpeBRepBuild_Tools> cls_TopOpeBRepBuild_Tools(mod, "TopOpeBRepBuild_Tools", "Auxiliary methods used in TopOpeBRepBuild_Builder1 class");

// Constructors

// Fields

// Methods
// cls_TopOpeBRepBuild_Tools.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_Tools::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Tools.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_Tools::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Tools.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_Tools::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Tools.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_Tools::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Tools.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_Tools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_Tools.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_Tools::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_Tools.def_static("FindState_", (void (*)(const TopoDS_Shape &, const TopAbs_State, const TopAbs_ShapeEnum, const TopTools_IndexedDataMapOfShapeListOfShape &, TopTools_MapOfShape &, TopOpeBRepDS_DataMapOfShapeState &)) &TopOpeBRepBuild_Tools::FindState, "None", py::arg("aVertex"), py::arg("aState"), py::arg("aShapeEnum"), py::arg("aMapVertexEdges"), py::arg("aMapProcessedVertices"), py::arg("aMapVs"));
cls_TopOpeBRepBuild_Tools.def_static("PropagateState_", (void (*)(const TopOpeBRepDS_DataMapOfShapeState &, const TopTools_IndexedMapOfShape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, TopOpeBRepTool_ShapeClassifier &, TopOpeBRepDS_IndexedDataMapOfShapeWithState &, const TopTools_MapOfShape &)) &TopOpeBRepBuild_Tools::PropagateState, "None", py::arg("aSplEdgesState"), py::arg("anEdgesToRestMap"), py::arg("aShapeEnum1"), py::arg("aShapeEnum2"), py::arg("aShapeClassifier"), py::arg("aMapOfShapeWithState"), py::arg("anUnkStateShapes"));
cls_TopOpeBRepBuild_Tools.def_static("FindStateThroughVertex_", (TopAbs_State (*)(const TopoDS_Shape &, TopOpeBRepTool_ShapeClassifier &, TopOpeBRepDS_IndexedDataMapOfShapeWithState &, const TopTools_MapOfShape &)) &TopOpeBRepBuild_Tools::FindStateThroughVertex, "None", py::arg("aShape"), py::arg("aShapeClassifier"), py::arg("aMapOfShapeWithState"), py::arg("anAvoidSubshMap"));
cls_TopOpeBRepBuild_Tools.def_static("PropagateStateForWires_", (void (*)(const TopTools_IndexedMapOfShape &, TopOpeBRepDS_IndexedDataMapOfShapeWithState &)) &TopOpeBRepBuild_Tools::PropagateStateForWires, "None", py::arg("aFacesToRestMap"), py::arg("aMapOfShapeWithState"));
cls_TopOpeBRepBuild_Tools.def_static("SpreadStateToChild_", (void (*)(const TopoDS_Shape &, const TopAbs_State, TopOpeBRepDS_IndexedDataMapOfShapeWithState &)) &TopOpeBRepBuild_Tools::SpreadStateToChild, "None", py::arg("aShape"), py::arg("aState"), py::arg("aMapOfShapeWithState"));
cls_TopOpeBRepBuild_Tools.def_static("FindState1_", (void (*)(const TopoDS_Shape &, const TopAbs_State, const TopTools_IndexedDataMapOfShapeListOfShape &, TopTools_MapOfShape &, TopOpeBRepDS_DataMapOfShapeState &)) &TopOpeBRepBuild_Tools::FindState1, "None", py::arg("anEdge"), py::arg("aState"), py::arg("aMapEdgesFaces"), py::arg("aMapProcessedVertices"), py::arg("aMapVs"));
cls_TopOpeBRepBuild_Tools.def_static("FindState2_", (void (*)(const TopoDS_Shape &, const TopAbs_State, const TopTools_IndexedDataMapOfShapeListOfShape &, TopTools_MapOfShape &, TopOpeBRepDS_DataMapOfShapeState &)) &TopOpeBRepBuild_Tools::FindState2, "None", py::arg("anEdge"), py::arg("aState"), py::arg("aMapEdgesFaces"), py::arg("aMapProcessedEdges"), py::arg("aMapVs"));
cls_TopOpeBRepBuild_Tools.def_static("GetAdjacentFace_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopTools_IndexedDataMapOfShapeListOfShape &, TopoDS_Shape &)) &TopOpeBRepBuild_Tools::GetAdjacentFace, "None", py::arg("aFaceObj"), py::arg("anEObj"), py::arg("anEdgeFaceMap"), py::arg("anAdjFaceObj"));
cls_TopOpeBRepBuild_Tools.def_static("GetNormalToFaceOnEdge_", (void (*)(const TopoDS_Face &, const TopoDS_Edge &, gp_Vec &)) &TopOpeBRepBuild_Tools::GetNormalToFaceOnEdge, "None", py::arg("aFObj"), py::arg("anEdgeObj"), py::arg("aDirNormal"));
cls_TopOpeBRepBuild_Tools.def_static("GetNormalInNearestPoint_", (void (*)(const TopoDS_Face &, const TopoDS_Edge &, gp_Vec &)) &TopOpeBRepBuild_Tools::GetNormalInNearestPoint, "This function used to compute normal in point which is located near the point with param UV (used for computation of normals where the normal in the point UV equal to zero).", py::arg("aFace"), py::arg("anEdge"), py::arg("aNormal"));
cls_TopOpeBRepBuild_Tools.def_static("GetTangentToEdgeEdge_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Edge &, gp_Vec &)) &TopOpeBRepBuild_Tools::GetTangentToEdgeEdge, "None", py::arg("aFObj"), py::arg("anEdgeObj"), py::arg("aOriEObj"), py::arg("aTangent"));
cls_TopOpeBRepBuild_Tools.def_static("GetTangentToEdge_", (Standard_Boolean (*)(const TopoDS_Edge &, gp_Vec &)) &TopOpeBRepBuild_Tools::GetTangentToEdge, "None", py::arg("anEdgeObj"), py::arg("aTangent"));
cls_TopOpeBRepBuild_Tools.def_static("UpdatePCurves_", (void (*)(const TopoDS_Wire &, const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRepBuild_Tools::UpdatePCurves, "Recompute PCurves of the all edges from the wire on the <toFace>", py::arg("aWire"), py::arg("fromFace"), py::arg("toFace"));
cls_TopOpeBRepBuild_Tools.def_static("UpdateEdgeOnPeriodicalFace_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRepBuild_Tools::UpdateEdgeOnPeriodicalFace, "recompute PCurves of the closing (SIM , with 2 PCurves) edge on the NewFace", py::arg("aEdgeToUpdate"), py::arg("OldFace"), py::arg("NewFace"));
cls_TopOpeBRepBuild_Tools.def_static("UpdateEdgeOnFace_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRepBuild_Tools::UpdateEdgeOnFace, "recompute PCurve of the edge on the NewFace", py::arg("aEdgeToUpdate"), py::arg("OldFace"), py::arg("NewFace"));
cls_TopOpeBRepBuild_Tools.def_static("IsDegEdgesTheSame_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Tools::IsDegEdgesTheSame, "None", py::arg("anE1"), py::arg("anE2"));
cls_TopOpeBRepBuild_Tools.def_static("NormalizeFace_", (void (*)(const TopoDS_Shape &, TopoDS_Shape &)) &TopOpeBRepBuild_Tools::NormalizeFace, "test if <oldFace> does not contain INTERNAL or EXTERNAL edges and remove such edges in case of its presence. The result is stored in <corrFace>", py::arg("oldFace"), py::arg("corrFace"));
cls_TopOpeBRepBuild_Tools.def_static("CorrectFace2d_", (void (*)(const TopoDS_Shape &, TopoDS_Shape &, const TopTools_IndexedMapOfOrientedShape &, TopTools_IndexedDataMapOfShapeShape &)) &TopOpeBRepBuild_Tools::CorrectFace2d, "test if UV representation of <oldFace> is good (i.e. face is closed in 2d). if face is not closed , this method will try to close such face and will return corrected edges in the <aMapOfCorrect2dEdges>. Parameter <aSourceShapes> used to fix the edge (or wires) which should be correct (Corrector used it as a start shapes). NOTE : Parameter corrFace doesn't mean anything. If you want to use this method , rebuild resulting face after by yourself using corrected edges.", py::arg("oldFace"), py::arg("corrFace"), py::arg("aSourceShapes"), py::arg("aMapOfCorrect2dEdges"));
cls_TopOpeBRepBuild_Tools.def_static("CorrectTolerances_", [](const TopoDS_Shape & a0) -> void { return TopOpeBRepBuild_Tools::CorrectTolerances(a0); });
cls_TopOpeBRepBuild_Tools.def_static("CorrectTolerances_", (void (*)(const TopoDS_Shape &, const Standard_Real)) &TopOpeBRepBuild_Tools::CorrectTolerances, "None", py::arg("aS"), py::arg("aTolMax"));
cls_TopOpeBRepBuild_Tools.def_static("CorrectCurveOnSurface_", [](const TopoDS_Shape & a0) -> void { return TopOpeBRepBuild_Tools::CorrectCurveOnSurface(a0); });
cls_TopOpeBRepBuild_Tools.def_static("CorrectCurveOnSurface_", (void (*)(const TopoDS_Shape &, const Standard_Real)) &TopOpeBRepBuild_Tools::CorrectCurveOnSurface, "None", py::arg("aS"), py::arg("aTolMax"));
cls_TopOpeBRepBuild_Tools.def_static("CorrectPointOnCurve_", [](const TopoDS_Shape & a0) -> void { return TopOpeBRepBuild_Tools::CorrectPointOnCurve(a0); });
cls_TopOpeBRepBuild_Tools.def_static("CorrectPointOnCurve_", (void (*)(const TopoDS_Shape &, const Standard_Real)) &TopOpeBRepBuild_Tools::CorrectPointOnCurve, "None", py::arg("aS"), py::arg("aTolMax"));
cls_TopOpeBRepBuild_Tools.def_static("CheckFaceClosed2d_", (Standard_Boolean (*)(const TopoDS_Face &)) &TopOpeBRepBuild_Tools::CheckFaceClosed2d, "Checks if <theFace> has the properly closed in 2D boundary(ies)", py::arg("theFace"));

// Enums

}