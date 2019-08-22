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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_State.hxx>
#include <BRepOffset_Analyse.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopoDS_Wire.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Standard_Handle.hxx>
#include <BRepAlgo_AsDes.hxx>
#include <BRepAlgo_Image.hxx>
#include <Geom_Curve.hxx>
#include <BRepOffset_Tool.hxx>

void bind_BRepOffset_Tool(py::module &mod){

py::class_<BRepOffset_Tool> cls_BRepOffset_Tool(mod, "BRepOffset_Tool", "None");

// Constructors

// Fields

// Methods
// cls_BRepOffset_Tool.def_static("operator new_", (void * (*)(size_t)) &BRepOffset_Tool::operator new, "None", py::arg("theSize"));
// cls_BRepOffset_Tool.def_static("operator delete_", (void (*)(void *)) &BRepOffset_Tool::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffset_Tool.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffset_Tool::operator new[], "None", py::arg("theSize"));
// cls_BRepOffset_Tool.def_static("operator delete[]_", (void (*)(void *)) &BRepOffset_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffset_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffset_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffset_Tool.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffset_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffset_Tool.def_static("EdgeVertices_", (void (*)(const TopoDS_Edge &, TopoDS_Vertex &, TopoDS_Vertex &)) &BRepOffset_Tool::EdgeVertices, "<V1> is the FirstVertex ,<V2> is the Last Vertex of <Edge> taking account the orientation of Edge.", py::arg("E"), py::arg("V1"), py::arg("V2"));
cls_BRepOffset_Tool.def_static("OriEdgeInFace_", (TopAbs_Orientation (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepOffset_Tool::OriEdgeInFace, "returns the cumul of the orientation of <Edge> and thc containing wire in <Face>", py::arg("E"), py::arg("F"));
cls_BRepOffset_Tool.def_static("OrientSection_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, TopAbs_Orientation &, TopAbs_Orientation &)) &BRepOffset_Tool::OrientSection, "<E> is a section between <F1> and <F2>. Computes <O1> the orientation of <E> in <F1> influenced by <F2>. idem for <O2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("O1"), py::arg("O2"));
cls_BRepOffset_Tool.def_static("FindCommonShapes_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &BRepOffset_Tool::FindCommonShapes, "Looks for the common Vertices and Edges between faces <theF1> and <theF2>. Returns TRUE if common shapes have been found. <theLE> will contain the found common edges; <theLV> will contain the found common vertices.", py::arg("theF1"), py::arg("theF2"), py::arg("theLE"), py::arg("theLV"));
cls_BRepOffset_Tool.def_static("FindCommonShapes_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopAbs_ShapeEnum, TopTools_ListOfShape &)) &BRepOffset_Tool::FindCommonShapes, "Looks for the common shapes of type <theType> between shapes <theS1> and <theS2>. Returns TRUE if common shapes have been found. <theLSC> will contain the found common shapes.", py::arg("theS1"), py::arg("theS2"), py::arg("theType"), py::arg("theLSC"));
cls_BRepOffset_Tool.def_static("Inter3D_", [](const TopoDS_Face & a0, const TopoDS_Face & a1, TopTools_ListOfShape & a2, TopTools_ListOfShape & a3, const TopAbs_State a4, const TopoDS_Edge & a5) -> void { return BRepOffset_Tool::Inter3D(a0, a1, a2, a3, a4, a5); });
cls_BRepOffset_Tool.def_static("Inter3D_", (void (*)(const TopoDS_Face &, const TopoDS_Face &, TopTools_ListOfShape &, TopTools_ListOfShape &, const TopAbs_State, const TopoDS_Edge &, const Standard_Boolean)) &BRepOffset_Tool::Inter3D, "Computes the Section betwwen <F1> and <F2> the edges solution are stored in <LInt1> with the orientation on <F1>, the sames edges are stored in <Lint2> with the orientation on <F2>.", py::arg("F1"), py::arg("F2"), py::arg("LInt1"), py::arg("LInt2"), py::arg("Side"), py::arg("RefEdge"), py::arg("IsRefEdgeDefined"));
cls_BRepOffset_Tool.def_static("TryProject_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const TopTools_ListOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &, const TopAbs_State, const Standard_Real)) &BRepOffset_Tool::TryProject, "Find if the edges <Edges> of the face <F2> are on the face <F1>. Set in <LInt1> <LInt2> the updated edges. If all the edges are computed, returns true.", py::arg("F1"), py::arg("F2"), py::arg("Edges"), py::arg("LInt1"), py::arg("LInt2"), py::arg("Side"), py::arg("TolConf"));
cls_BRepOffset_Tool.def_static("PipeInter_", (void (*)(const TopoDS_Face &, const TopoDS_Face &, TopTools_ListOfShape &, TopTools_ListOfShape &, const TopAbs_State)) &BRepOffset_Tool::PipeInter, "None", py::arg("F1"), py::arg("F2"), py::arg("LInt1"), py::arg("LInt2"), py::arg("Side"));
cls_BRepOffset_Tool.def_static("Inter2d_", (void (*)(const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Edge &, TopTools_ListOfShape &, const Standard_Real)) &BRepOffset_Tool::Inter2d, "None", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("LV"), py::arg("Tol"));
cls_BRepOffset_Tool.def_static("InterOrExtent_", (void (*)(const TopoDS_Face &, const TopoDS_Face &, TopTools_ListOfShape &, TopTools_ListOfShape &, const TopAbs_State)) &BRepOffset_Tool::InterOrExtent, "None", py::arg("F1"), py::arg("F2"), py::arg("LInt1"), py::arg("LInt2"), py::arg("Side"));
cls_BRepOffset_Tool.def_static("CheckBounds_", [](const TopoDS_Face & F, const BRepOffset_Analyse & Analyse, Standard_Boolean & enlargeU, Standard_Boolean & enlargeVfirst, Standard_Boolean & enlargeVlast){ BRepOffset_Tool::CheckBounds(F, Analyse, enlargeU, enlargeVfirst, enlargeVlast); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(enlargeU, enlargeVfirst, enlargeVlast); }, "None", py::arg("F"), py::arg("Analyse"), py::arg("enlargeU"), py::arg("enlargeVfirst"), py::arg("enlargeVlast"));
cls_BRepOffset_Tool.def_static("EnLargeFace_", [](const TopoDS_Face & a0, TopoDS_Face & a1, const Standard_Boolean a2) -> Standard_Boolean { return BRepOffset_Tool::EnLargeFace(a0, a1, a2); });
cls_BRepOffset_Tool.def_static("EnLargeFace_", [](const TopoDS_Face & a0, TopoDS_Face & a1, const Standard_Boolean a2, const Standard_Boolean a3) -> Standard_Boolean { return BRepOffset_Tool::EnLargeFace(a0, a1, a2, a3); });
cls_BRepOffset_Tool.def_static("EnLargeFace_", [](const TopoDS_Face & a0, TopoDS_Face & a1, const Standard_Boolean a2, const Standard_Boolean a3, const Standard_Boolean a4) -> Standard_Boolean { return BRepOffset_Tool::EnLargeFace(a0, a1, a2, a3, a4); });
cls_BRepOffset_Tool.def_static("EnLargeFace_", [](const TopoDS_Face & a0, TopoDS_Face & a1, const Standard_Boolean a2, const Standard_Boolean a3, const Standard_Boolean a4, const Standard_Boolean a5) -> Standard_Boolean { return BRepOffset_Tool::EnLargeFace(a0, a1, a2, a3, a4, a5); });
cls_BRepOffset_Tool.def_static("EnLargeFace_", [](const TopoDS_Face & a0, TopoDS_Face & a1, const Standard_Boolean a2, const Standard_Boolean a3, const Standard_Boolean a4, const Standard_Boolean a5, const Standard_Boolean a6) -> Standard_Boolean { return BRepOffset_Tool::EnLargeFace(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepOffset_Tool.def_static("EnLargeFace_", (Standard_Boolean (*)(const TopoDS_Face &, TopoDS_Face &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Integer)) &BRepOffset_Tool::EnLargeFace, "if <ChangeGeom> is TRUE , the surface can be changed . if <UpdatePCurve> is TRUE, update the pcurves of the edges of <F> on the new surface.if the surface has been changed, Returns True if The Surface of <NF> has changed. <ExtensionMode> is a mode of extension of the surface of the face: if <ExtensionMode> equals 1, potentially infinite surfaces are extended by maximum value, and limited surfaces are extended by 25%. if <ExtensionMode> equals 2, potentially infinite surfaces are extended by 10*(correspondent size of face), and limited surfaces are extended by 100%.", py::arg("F"), py::arg("NF"), py::arg("ChangeGeom"), py::arg("UpDatePCurve"), py::arg("enlargeU"), py::arg("enlargeVfirst"), py::arg("enlargeVlast"), py::arg("ExtensionMode"));
cls_BRepOffset_Tool.def_static("ExtentFace_", (void (*)(const TopoDS_Face &, TopTools_DataMapOfShapeShape &, TopTools_DataMapOfShapeShape &, const TopAbs_State, const Standard_Real, TopoDS_Face &)) &BRepOffset_Tool::ExtentFace, "None", py::arg("F"), py::arg("ConstShapes"), py::arg("ToBuild"), py::arg("Side"), py::arg("TolConf"), py::arg("NF"));
cls_BRepOffset_Tool.def_static("BuildNeighbour_", (void (*)(const TopoDS_Wire &, const TopoDS_Face &, TopTools_DataMapOfShapeShape &, TopTools_DataMapOfShapeShape &)) &BRepOffset_Tool::BuildNeighbour, "Via the wire explorer store in <NOnV1> for an Edge <E> of <W> his Edge neighbour on the first vertex <V1> of <E>. Store in NOnV2 the Neighbour of <E>on the last vertex <V2> of <E>.", py::arg("W"), py::arg("F"), py::arg("NOnV1"), py::arg("NOnV2"));
cls_BRepOffset_Tool.def_static("MapVertexEdges_", (void (*)(const TopoDS_Shape &, TopTools_DataMapOfShapeListOfShape &)) &BRepOffset_Tool::MapVertexEdges, "Store in MVE for a vertex <V> in <S> the incident edges <E> in <S>. An Edge is Store only one Time for a vertex.", py::arg("S"), py::arg("MVE"));
cls_BRepOffset_Tool.def_static("Deboucle3D_", (TopoDS_Shape (*)(const TopoDS_Shape &, const TopTools_MapOfShape &)) &BRepOffset_Tool::Deboucle3D, "Remove the non valid part of an offsetshape 1 - Remove all the free boundary and the faces connex to such edges. 2 - Remove all the shapes not valid in the result (according to the side of offseting) in this verion only the first point is implemented.", py::arg("S"), py::arg("Boundary"));
cls_BRepOffset_Tool.def_static("CorrectOrientation_", (void (*)(const TopoDS_Shape &, const TopTools_IndexedMapOfShape &, opencascade::handle<BRepAlgo_AsDes> &, BRepAlgo_Image &, const Standard_Real)) &BRepOffset_Tool::CorrectOrientation, "None", py::arg("SI"), py::arg("NewEdges"), py::arg("AsDes"), py::arg("InitOffset"), py::arg("Offset"));
cls_BRepOffset_Tool.def_static("Gabarit_", (Standard_Real (*)(const opencascade::handle<Geom_Curve> &)) &BRepOffset_Tool::Gabarit, "None", py::arg("aCurve"));
cls_BRepOffset_Tool.def_static("CheckPlanesNormals_", [](const TopoDS_Face & a0, const TopoDS_Face & a1) -> Standard_Boolean { return BRepOffset_Tool::CheckPlanesNormals(a0, a1); });
cls_BRepOffset_Tool.def_static("CheckPlanesNormals_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const Standard_Real)) &BRepOffset_Tool::CheckPlanesNormals, "Compares the normal directions of the planar faces and returns TRUE if the directions are the same with the given precision.", py::arg("theFace1"), py::arg("theFace2"), py::arg("theTolAng"));

// Enums

}