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
#include <TopOpeBRepDS_BuildTool.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopAbs_State.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.hxx>
#include <TopOpeBRepBuild_EdgeBuilder.hxx>
#include <TopOpeBRepBuild_FaceBuilder.hxx>
#include <TopOpeBRepBuild_SolidBuilder.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <TopOpeBRepBuild_GTopo.hxx>
#include <TopOpeBRepBuild_ShellFaceSet.hxx>
#include <TopOpeBRepDS_SurfaceIterator.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TopOpeBRepBuild_WireEdgeSet.hxx>
#include <TopOpeBRepDS_CurveIterator.hxx>
#include <TopOpeBRepBuild_PaveSet.hxx>
#include <TopOpeBRepDS_PointIterator.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <gp_Pnt.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopOpeBRepBuild_ShapeSet.hxx>
#include <TopOpeBRepTool_ShapeExplorer.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>
#include <TopTools_HArray1OfShape.hxx>
#include <TopTools_HArray1OfListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopOpeBRepTool_ShapeClassifier.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopOpeBRepBuild_Builder.hxx>

void bind_TopOpeBRepBuild_Builder(py::module &mod){

py::class_<TopOpeBRepBuild_Builder, std::unique_ptr<TopOpeBRepBuild_Builder, Deleter<TopOpeBRepBuild_Builder>>> cls_TopOpeBRepBuild_Builder(mod, "TopOpeBRepBuild_Builder", "The Builder algorithm constructs topological objects from an existing topology and new geometries attached to the topology. It is used to construct the result of a topological operation; the existing topologies are the parts involved in the topological operation and the new geometries are the intersection lines and points.");

// Constructors
cls_TopOpeBRepBuild_Builder.def(py::init<const TopOpeBRepDS_BuildTool &>(), py::arg("BT"));

// Fields

// Methods
// cls_TopOpeBRepBuild_Builder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_Builder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Builder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_Builder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_Builder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Builder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_Builder.def("ChangeBuildTool", (TopOpeBRepDS_BuildTool & (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::ChangeBuildTool, "None");
cls_TopOpeBRepBuild_Builder.def("BuildTool", (const TopOpeBRepDS_BuildTool & (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::BuildTool, "None");
cls_TopOpeBRepBuild_Builder.def("Perform", (void (TopOpeBRepBuild_Builder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepBuild_Builder::Perform, "Stores the data structure <HDS>, Create shapes from the new geometries.", py::arg("HDS"));
cls_TopOpeBRepBuild_Builder.def("Perform", (void (TopOpeBRepBuild_Builder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::Perform, "Stores the data structure <HDS>, Create shapes from the new geometries, Evaluates if an operation performed on shapes S1,S2 is a particular case.", py::arg("HDS"), py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("DataStructure", (opencascade::handle<TopOpeBRepDS_HDataStructure> (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::DataStructure, "returns the DS handled by this builder");
cls_TopOpeBRepBuild_Builder.def("Clear", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::Clear, "Removes all splits and merges already performed. Does NOT clear the handled DS.");
cls_TopOpeBRepBuild_Builder.def("MergeEdges", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3) -> void { return self.MergeEdges(a0, a1, a2, a3); });
cls_TopOpeBRepBuild_Builder.def("MergeEdges", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3, const Standard_Boolean a4) -> void { return self.MergeEdges(a0, a1, a2, a3, a4); });
cls_TopOpeBRepBuild_Builder.def("MergeEdges", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3, const Standard_Boolean a4, const Standard_Boolean a5) -> void { return self.MergeEdges(a0, a1, a2, a3, a4, a5); });
cls_TopOpeBRepBuild_Builder.def("MergeEdges", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopAbs_State, const TopTools_ListOfShape &, const TopAbs_State, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &TopOpeBRepBuild_Builder::MergeEdges, "Merges the two edges <S1> and <S2> keeping the parts in each edge of states <TB1> and <TB2>. Booleans onA, onB, onAB indicate wheter parts of edges found as state ON respectively on first, second, and both shapes must be (or not) built.", py::arg("L1"), py::arg("TB1"), py::arg("L2"), py::arg("TB2"), py::arg("onA"), py::arg("onB"), py::arg("onAB"));
cls_TopOpeBRepBuild_Builder.def("MergeFaces", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3) -> void { return self.MergeFaces(a0, a1, a2, a3); });
cls_TopOpeBRepBuild_Builder.def("MergeFaces", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3, const Standard_Boolean a4) -> void { return self.MergeFaces(a0, a1, a2, a3, a4); });
cls_TopOpeBRepBuild_Builder.def("MergeFaces", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3, const Standard_Boolean a4, const Standard_Boolean a5) -> void { return self.MergeFaces(a0, a1, a2, a3, a4, a5); });
cls_TopOpeBRepBuild_Builder.def("MergeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopAbs_State, const TopTools_ListOfShape &, const TopAbs_State, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &TopOpeBRepBuild_Builder::MergeFaces, "Merges the two faces <S1> and <S2> keeping the parts in each face of states <TB1> and <TB2>.", py::arg("S1"), py::arg("TB1"), py::arg("S2"), py::arg("TB2"), py::arg("onA"), py::arg("onB"), py::arg("onAB"));
cls_TopOpeBRepBuild_Builder.def("MergeSolids", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State, const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::MergeSolids, "Merges the two solids <S1> and <S2> keeping the parts in each solid of states <TB1> and <TB2>.", py::arg("S1"), py::arg("TB1"), py::arg("S2"), py::arg("TB2"));
cls_TopOpeBRepBuild_Builder.def("MergeShapes", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State, const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::MergeShapes, "Merges the two shapes <S1> and <S2> keeping the parts of states <TB1>,<TB2> in <S1>,<S2>.", py::arg("S1"), py::arg("TB1"), py::arg("S2"), py::arg("TB2"));
cls_TopOpeBRepBuild_Builder.def("End", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::End, "None");
cls_TopOpeBRepBuild_Builder.def("Classify", (Standard_Boolean (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::Classify, "None");
cls_TopOpeBRepBuild_Builder.def("ChangeClassify", (void (TopOpeBRepBuild_Builder::*)(const Standard_Boolean)) &TopOpeBRepBuild_Builder::ChangeClassify, "None", py::arg("B"));
cls_TopOpeBRepBuild_Builder.def("MergeSolid", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::MergeSolid, "Merges the solid <S> keeping the parts of state <TB>.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("NewVertex", (const TopoDS_Shape & (TopOpeBRepBuild_Builder::*)(const Standard_Integer) const) &TopOpeBRepBuild_Builder::NewVertex, "Returns the vertex created on point <I>.", py::arg("I"));
cls_TopOpeBRepBuild_Builder.def("NewEdges", (const TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)(const Standard_Integer) const) &TopOpeBRepBuild_Builder::NewEdges, "Returns the edges created on curve <I>.", py::arg("I"));
cls_TopOpeBRepBuild_Builder.def("NewFaces", (const TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)(const Standard_Integer) const) &TopOpeBRepBuild_Builder::NewFaces, "Returns the faces created on surface <I>.", py::arg("I"));
cls_TopOpeBRepBuild_Builder.def("IsSplit", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_Builder::IsSplit, "Returns True if the shape <S> has been split.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("Splits", (const TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_Builder::Splits, "Returns the split parts <TB> of shape <S>.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("IsMerged", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_Builder::IsMerged, "Returns True if the shape <S> has been merged.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("Merged", (const TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_Builder::Merged, "Returns the merged parts <TB> of shape <S>.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("InitSection", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::InitSection, "None");
cls_TopOpeBRepBuild_Builder.def("SplitSectionEdges", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::SplitSectionEdges, "create parts ON solid of section edges");
cls_TopOpeBRepBuild_Builder.def("SplitSectionEdge", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::SplitSectionEdge, "create parts ON solid of section edges", py::arg("E"));
cls_TopOpeBRepBuild_Builder.def("SectionCurves", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::SectionCurves, "return the section edges built on new curves.", py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("SectionEdges", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::SectionEdges, "return the parts of edges found ON the boundary of the two arguments S1,S2 of Perform()", py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("FillSecEdgeAncestorMap", (void (TopOpeBRepBuild_Builder::*)(const Standard_Integer, const TopTools_MapOfShape &, TopTools_DataMapOfShapeShape &) const) &TopOpeBRepBuild_Builder::FillSecEdgeAncestorMap, "Fills anAncMap with pairs (edge,ancestor edge) for each split from the map aMapON for the shape object identified by ShapeRank", py::arg("aShapeRank"), py::arg("aMapON"), py::arg("anAncMap"));
cls_TopOpeBRepBuild_Builder.def("Section", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::Section, "return all section edges.", py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("Section", (const TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::Section, "None");
cls_TopOpeBRepBuild_Builder.def("BuildVertices", (void (TopOpeBRepBuild_Builder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepBuild_Builder::BuildVertices, "update the DS by creating new geometries. create vertices on DS points.", py::arg("DS"));
cls_TopOpeBRepBuild_Builder.def("BuildEdges", (void (TopOpeBRepBuild_Builder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepBuild_Builder::BuildEdges, "update the DS by creating new geometries. create shapes from the new geometries.", py::arg("DS"));
cls_TopOpeBRepBuild_Builder.def("MSplit", (const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State & (TopOpeBRepBuild_Builder::*)(const TopAbs_State) const) &TopOpeBRepBuild_Builder::MSplit, "None", py::arg("s"));
cls_TopOpeBRepBuild_Builder.def("ChangeMSplit", (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State & (TopOpeBRepBuild_Builder::*)(const TopAbs_State)) &TopOpeBRepBuild_Builder::ChangeMSplit, "None", py::arg("s"));
cls_TopOpeBRepBuild_Builder.def("MakeEdges", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_EdgeBuilder &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::MakeEdges, "None", py::arg("E"), py::arg("B"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("MakeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_FaceBuilder &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::MakeFaces, "None", py::arg("F"), py::arg("B"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("MakeSolids", (void (TopOpeBRepBuild_Builder::*)(TopOpeBRepBuild_SolidBuilder &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::MakeSolids, "None", py::arg("B"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("MakeShells", (void (TopOpeBRepBuild_Builder::*)(TopOpeBRepBuild_SolidBuilder &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::MakeShells, "None", py::arg("B"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("ChangeSplit", (TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::ChangeSplit, "Returns a ref.on the list of shapes connected to <S> as <TB> split parts of <S>. Mark <S> as split in <TB> parts.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("Opec12", (Standard_Boolean (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::Opec12, "None");
cls_TopOpeBRepBuild_Builder.def("Opec21", (Standard_Boolean (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::Opec21, "None");
cls_TopOpeBRepBuild_Builder.def("Opecom", (Standard_Boolean (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::Opecom, "None");
cls_TopOpeBRepBuild_Builder.def("Opefus", (Standard_Boolean (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::Opefus, "None");
cls_TopOpeBRepBuild_Builder.def("ShapePosition", (TopAbs_State (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::ShapePosition, "None", py::arg("S"), py::arg("LS"));
cls_TopOpeBRepBuild_Builder.def("KeepShape", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::KeepShape, "None", py::arg("S"), py::arg("LS"), py::arg("T"));
cls_TopOpeBRepBuild_Builder.def_static("TopType_", (TopAbs_ShapeEnum (*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::TopType, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def_static("Reverse_", (Standard_Boolean (*)(const TopAbs_State, const TopAbs_State)) &TopOpeBRepBuild_Builder::Reverse, "None", py::arg("T1"), py::arg("T2"));
cls_TopOpeBRepBuild_Builder.def_static("Orient_", (TopAbs_Orientation (*)(const TopAbs_Orientation, const Standard_Boolean)) &TopOpeBRepBuild_Builder::Orient, "None", py::arg("O"), py::arg("R"));
cls_TopOpeBRepBuild_Builder.def("FindSameDomain", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::FindSameDomain, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("FindSameDomainSameOrientation", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::FindSameDomainSameOrientation, "None", py::arg("LSO"), py::arg("LDO"));
cls_TopOpeBRepBuild_Builder.def("MapShapes", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::MapShapes, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("ClearMaps", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::ClearMaps, "None");
cls_TopOpeBRepBuild_Builder.def("FindSameRank", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const Standard_Integer, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::FindSameRank, "None", py::arg("L1"), py::arg("R"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("ShapeRank", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::ShapeRank, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("IsShapeOf", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Integer) const) &TopOpeBRepBuild_Builder::IsShapeOf, "None", py::arg("S"), py::arg("I12"));
cls_TopOpeBRepBuild_Builder.def_static("Contains_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::Contains, "None", py::arg("S"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("FindIsKPart", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::FindIsKPart, "None");
cls_TopOpeBRepBuild_Builder.def("IsKPart", (Standard_Integer (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::IsKPart, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPart", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPart, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPart", (void (TopOpeBRepBuild_Builder::*)(const TopAbs_State, const TopAbs_State)) &TopOpeBRepBuild_Builder::MergeKPart, "None", py::arg("TB1"), py::arg("TB2"));
cls_TopOpeBRepBuild_Builder.def("MergeKPartiskole", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPartiskole, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPartiskoletge", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPartiskoletge, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPartisdisj", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPartisdisj, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPartisfafa", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPartisfafa, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPartissoso", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPartissoso, "None");
cls_TopOpeBRepBuild_Builder.def("KPiskole", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPiskole, "None");
cls_TopOpeBRepBuild_Builder.def("KPiskoletge", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPiskoletge, "None");
cls_TopOpeBRepBuild_Builder.def("KPisdisj", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPisdisj, "None");
cls_TopOpeBRepBuild_Builder.def("KPisfafa", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPisfafa, "None");
cls_TopOpeBRepBuild_Builder.def("KPissoso", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPissoso, "None");
cls_TopOpeBRepBuild_Builder.def("KPClearMaps", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPClearMaps, "None");
cls_TopOpeBRepBuild_Builder.def("KPlhg", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::KPlhg, "None", py::arg("S"), py::arg("T"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("KPlhg", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum) const) &TopOpeBRepBuild_Builder::KPlhg, "None", py::arg("S"), py::arg("T"));
cls_TopOpeBRepBuild_Builder.def("KPlhsd", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::KPlhsd, "None", py::arg("S"), py::arg("T"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("KPlhsd", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum) const) &TopOpeBRepBuild_Builder::KPlhsd, "None", py::arg("S"), py::arg("T"));
cls_TopOpeBRepBuild_Builder.def("KPclasSS", (TopAbs_State (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::KPclasSS, "None", py::arg("S1"), py::arg("exceptLS1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("KPclasSS", (TopAbs_State (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::KPclasSS, "None", py::arg("S1"), py::arg("exceptS1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("KPclasSS", (TopAbs_State (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::KPclasSS, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("KPiskolesh", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::KPiskolesh, "None", py::arg("S"), py::arg("LS"), py::arg("LF"));
cls_TopOpeBRepBuild_Builder.def("KPiskoletgesh", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::KPiskoletgesh, "None", py::arg("S"), py::arg("LS"), py::arg("LF"));
cls_TopOpeBRepBuild_Builder.def("KPSameDomain", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::KPSameDomain, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("KPisdisjsh", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::KPisdisjsh, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("KPisfafash", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::KPisfafash, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("KPissososh", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::KPissososh, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("KPiskoleanalyse", [](TopOpeBRepBuild_Builder &self, const TopAbs_State FT1, const TopAbs_State FT2, const TopAbs_State ST1, const TopAbs_State ST2, Standard_Integer & I, Standard_Integer & I1, Standard_Integer & I2){ self.KPiskoleanalyse(FT1, FT2, ST1, ST2, I, I1, I2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(I, I1, I2); }, "None", py::arg("FT1"), py::arg("FT2"), py::arg("ST1"), py::arg("ST2"), py::arg("I"), py::arg("I1"), py::arg("I2"));
cls_TopOpeBRepBuild_Builder.def("KPiskoletgeanalyse", [](TopOpeBRepBuild_Builder &self, const TopOpeBRepDS_Config Conf, const TopAbs_State ST1, const TopAbs_State ST2, Standard_Integer & I){ self.KPiskoletgeanalyse(Conf, ST1, ST2, I); return I; }, "None", py::arg("Conf"), py::arg("ST1"), py::arg("ST2"), py::arg("I"));
cls_TopOpeBRepBuild_Builder.def("KPisdisjanalyse", [](TopOpeBRepBuild_Builder &self, const TopAbs_State ST1, const TopAbs_State ST2, Standard_Integer & I, Standard_Integer & IC1, Standard_Integer & IC2){ self.KPisdisjanalyse(ST1, ST2, I, IC1, IC2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(I, IC1, IC2); }, "None", py::arg("ST1"), py::arg("ST2"), py::arg("I"), py::arg("IC1"), py::arg("IC2"));
cls_TopOpeBRepBuild_Builder.def_static("KPls_", (Standard_Integer (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::KPls, "None", py::arg("S"), py::arg("T"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def_static("KPls_", (Standard_Integer (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_Builder::KPls, "None", py::arg("S"), py::arg("T"));
cls_TopOpeBRepBuild_Builder.def("KPclassF", (TopAbs_State (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::KPclassF, "None", py::arg("F1"), py::arg("F2"));
cls_TopOpeBRepBuild_Builder.def("KPclassFF", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopAbs_State &, TopAbs_State &)) &TopOpeBRepBuild_Builder::KPclassFF, "None", py::arg("F1"), py::arg("F2"), py::arg("T1"), py::arg("T2"));
cls_TopOpeBRepBuild_Builder.def("KPiskoleFF", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopAbs_State &, TopAbs_State &)) &TopOpeBRepBuild_Builder::KPiskoleFF, "None", py::arg("F1"), py::arg("F2"), py::arg("T1"), py::arg("T2"));
cls_TopOpeBRepBuild_Builder.def_static("KPContains_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::KPContains, "None", py::arg("S"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("KPmakeface", (TopoDS_Shape (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopAbs_State, const TopAbs_State, const Standard_Boolean, const Standard_Boolean)) &TopOpeBRepBuild_Builder::KPmakeface, "None", py::arg("F1"), py::arg("LF2"), py::arg("T1"), py::arg("T2"), py::arg("R1"), py::arg("R2"));
cls_TopOpeBRepBuild_Builder.def_static("KPreturn_", (Standard_Integer (*)(const Standard_Integer)) &TopOpeBRepBuild_Builder::KPreturn, "None", py::arg("KP"));
cls_TopOpeBRepBuild_Builder.def("SplitEvisoONperiodicF", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::SplitEvisoONperiodicF, "None");
cls_TopOpeBRepBuild_Builder.def("GMergeSolids", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GMergeSolids, "None", py::arg("LSO1"), py::arg("LSO2"), py::arg("G"));
cls_TopOpeBRepBuild_Builder.def("GFillSolidsSFS", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GFillSolidsSFS, "None", py::arg("LSO1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GFillSolidSFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GFillSolidSFS, "None", py::arg("SO1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GFillSurfaceTopologySFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GFillSurfaceTopologySFS, "None", py::arg("SO1"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GFillSurfaceTopologySFS", (void (TopOpeBRepBuild_Builder::*)(const TopOpeBRepDS_SurfaceIterator &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &) const) &TopOpeBRepBuild_Builder::GFillSurfaceTopologySFS, "None", py::arg("IT"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GFillShellSFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GFillShellSFS, "None", py::arg("SH1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GFillFaceSFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GFillFaceSFS, "None", py::arg("F1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GSplitFaceSFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GSplitFaceSFS, "None", py::arg("F1"), py::arg("LSclass"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GMergeFaceSFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GMergeFaceSFS, "None", py::arg("F"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GSplitFace", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GSplitFace, "None", py::arg("F"), py::arg("G"), py::arg("LSclass"));
cls_TopOpeBRepBuild_Builder.def("AddONPatchesSFS", (void (TopOpeBRepBuild_Builder::*)(const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::AddONPatchesSFS, "None", py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("FillOnPatches", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopoDS_Shape &, const TopTools_IndexedMapOfOrientedShape &)) &TopOpeBRepBuild_Builder::FillOnPatches, "None", py::arg("anEdgesON"), py::arg("aBaseFace"), py::arg("avoidMap"));
cls_TopOpeBRepBuild_Builder.def("FindFacesTouchingEdge", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Integer, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::FindFacesTouchingEdge, "None", py::arg("aFace"), py::arg("anEdge"), py::arg("aShRank"), py::arg("aFaces"));
cls_TopOpeBRepBuild_Builder.def("GMergeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GMergeFaces, "None", py::arg("LF1"), py::arg("LF2"), py::arg("G"));
cls_TopOpeBRepBuild_Builder.def("GFillFacesWES", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillFacesWES, "None", py::arg("LF1"), py::arg("LF2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillFacesWESK", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &, const Standard_Integer)) &TopOpeBRepBuild_Builder::GFillFacesWESK, "None", py::arg("LF1"), py::arg("LF2"), py::arg("G"), py::arg("WES"), py::arg("K"));
cls_TopOpeBRepBuild_Builder.def("GFillFacesWESMakeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GFillFacesWESMakeFaces, "None", py::arg("LF1"), py::arg("LF2"), py::arg("LSO"), py::arg("G"));
cls_TopOpeBRepBuild_Builder.def("GFillFaceWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillFaceWES, "None", py::arg("F"), py::arg("LF2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillCurveTopologyWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillCurveTopologyWES, "None", py::arg("F"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillCurveTopologyWES", (void (TopOpeBRepBuild_Builder::*)(const TopOpeBRepDS_CurveIterator &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &) const) &TopOpeBRepBuild_Builder::GFillCurveTopologyWES, "None", py::arg("IT"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillONPartsWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, const TopTools_ListOfShape &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillONPartsWES, "None", py::arg("F"), py::arg("G"), py::arg("LSclass"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillWireWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillWireWES, "None", py::arg("W"), py::arg("LF2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillEdgeWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillEdgeWES, "None", py::arg("E"), py::arg("LF2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GSplitEdgeWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GSplitEdgeWES, "None", py::arg("E"), py::arg("LF2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GMergeEdgeWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GMergeEdgeWES, "None", py::arg("E"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GSplitEdge", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GSplitEdge, "None", py::arg("E"), py::arg("G"), py::arg("LSclass"));
cls_TopOpeBRepBuild_Builder.def("GMergeEdges", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GMergeEdges, "None", py::arg("LE1"), py::arg("LE2"), py::arg("G"));
cls_TopOpeBRepBuild_Builder.def("GFillEdgesPVS", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_PaveSet &)) &TopOpeBRepBuild_Builder::GFillEdgesPVS, "None", py::arg("LE1"), py::arg("LE2"), py::arg("G"), py::arg("PVS"));
cls_TopOpeBRepBuild_Builder.def("GFillEdgePVS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_PaveSet &)) &TopOpeBRepBuild_Builder::GFillEdgePVS, "None", py::arg("E"), py::arg("LE2"), py::arg("G"), py::arg("PVS"));
cls_TopOpeBRepBuild_Builder.def("GFillPointTopologyPVS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_PaveSet &)) &TopOpeBRepBuild_Builder::GFillPointTopologyPVS, "None", py::arg("E"), py::arg("G"), py::arg("PVS"));
cls_TopOpeBRepBuild_Builder.def("GFillPointTopologyPVS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepDS_PointIterator &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_PaveSet &) const) &TopOpeBRepBuild_Builder::GFillPointTopologyPVS, "None", py::arg("E"), py::arg("IT"), py::arg("G"), py::arg("PVS"));
cls_TopOpeBRepBuild_Builder.def("GParamOnReference", [](TopOpeBRepBuild_Builder &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P){ Standard_Boolean rv = self.GParamOnReference(V, E, P); return std::tuple<Standard_Boolean, Standard_Real &>(rv, P); }, "None", py::arg("V"), py::arg("E"), py::arg("P"));
cls_TopOpeBRepBuild_Builder.def("GKeepShape", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::GKeepShape, "None", py::arg("S"), py::arg("Lref"), py::arg("T"));
cls_TopOpeBRepBuild_Builder.def("GKeepShape1", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopAbs_State, TopAbs_State &)) &TopOpeBRepBuild_Builder::GKeepShape1, "return True if S is classified <T> / Lref shapes", py::arg("S"), py::arg("Lref"), py::arg("T"), py::arg("pos"));
cls_TopOpeBRepBuild_Builder.def("GKeepShapes", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopAbs_State, const TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GKeepShapes, "add to Lou the shapes of Lin classified <T> / Lref shapes. Lou is not cleared. (S is a dummy trace argument)", py::arg("S"), py::arg("Lref"), py::arg("T"), py::arg("Lin"), py::arg("Lou"));
cls_TopOpeBRepBuild_Builder.def("GSFSMakeSolids", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_ShellFaceSet &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GSFSMakeSolids, "None", py::arg("SOF"), py::arg("SFS"), py::arg("LOSO"));
cls_TopOpeBRepBuild_Builder.def("GSOBUMakeSolids", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_SolidBuilder &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GSOBUMakeSolids, "None", py::arg("SOF"), py::arg("SOBU"), py::arg("LOSO"));
cls_TopOpeBRepBuild_Builder.def("GWESMakeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_WireEdgeSet &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GWESMakeFaces, "None", py::arg("FF"), py::arg("WES"), py::arg("LOF"));
cls_TopOpeBRepBuild_Builder.def("GFABUMakeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_FaceBuilder &, TopTools_ListOfShape &, TopTools_DataMapOfShapeInteger &)) &TopOpeBRepBuild_Builder::GFABUMakeFaces, "None", py::arg("FF"), py::arg("FABU"), py::arg("LOF"), py::arg("MWisOld"));
cls_TopOpeBRepBuild_Builder.def("RegularizeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::RegularizeFaces, "None", py::arg("FF"), py::arg("lnewFace"), py::arg("LOF"));
cls_TopOpeBRepBuild_Builder.def("RegularizeFace", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::RegularizeFace, "None", py::arg("FF"), py::arg("newFace"), py::arg("LOF"));
cls_TopOpeBRepBuild_Builder.def("RegularizeSolids", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::RegularizeSolids, "None", py::arg("SS"), py::arg("lnewSolid"), py::arg("LOS"));
cls_TopOpeBRepBuild_Builder.def("RegularizeSolid", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::RegularizeSolid, "None", py::arg("SS"), py::arg("newSolid"), py::arg("LOS"));
cls_TopOpeBRepBuild_Builder.def("GPVSMakeEdges", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_PaveSet &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GPVSMakeEdges, "None", py::arg("EF"), py::arg("PVS"), py::arg("LOE"));
cls_TopOpeBRepBuild_Builder.def("GEDBUMakeEdges", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_EdgeBuilder &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GEDBUMakeEdges, "None", py::arg("EF"), py::arg("EDBU"), py::arg("LOE"));
cls_TopOpeBRepBuild_Builder.def("GToSplit", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_Builder::GToSplit, "None", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("GToMerge", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::GToMerge, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def_static("GTakeCommonOfSame_", (Standard_Boolean (*)(const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GTakeCommonOfSame, "None", py::arg("G"));
cls_TopOpeBRepBuild_Builder.def_static("GTakeCommonOfDiff_", (Standard_Boolean (*)(const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GTakeCommonOfDiff, "None", py::arg("G"));
cls_TopOpeBRepBuild_Builder.def("GFindSamDom", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GFindSamDom, "None", py::arg("S"), py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("GFindSamDom", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GFindSamDom, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("GFindSamDomSODO", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GFindSamDomSODO, "None", py::arg("S"), py::arg("LSO"), py::arg("LDO"));
cls_TopOpeBRepBuild_Builder.def("GFindSamDomSODO", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GFindSamDomSODO, "None", py::arg("LSO"), py::arg("LDO"));
cls_TopOpeBRepBuild_Builder.def("GMapShapes", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::GMapShapes, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("GClearMaps", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::GClearMaps, "None");
cls_TopOpeBRepBuild_Builder.def("GFindSameRank", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const Standard_Integer, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GFindSameRank, "None", py::arg("L1"), py::arg("R"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("GShapeRank", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::GShapeRank, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("GIsShapeOf", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Integer) const) &TopOpeBRepBuild_Builder::GIsShapeOf, "None", py::arg("S"), py::arg("I12"));
cls_TopOpeBRepBuild_Builder.def_static("GContains_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GContains, "None", py::arg("S"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def_static("GCopyList_", (void (*)(const TopTools_ListOfShape &, const Standard_Integer, const Standard_Integer, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GCopyList, "None", py::arg("Lin"), py::arg("i1"), py::arg("i2"), py::arg("Lou"));
cls_TopOpeBRepBuild_Builder.def_static("GCopyList_", (void (*)(const TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GCopyList, "None", py::arg("Lin"), py::arg("Lou"));
cls_TopOpeBRepBuild_Builder.def("GdumpLS", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GdumpLS, "None", py::arg("L"));
cls_TopOpeBRepBuild_Builder.def_static("GdumpPNT_", (void (*)(const gp_Pnt &)) &TopOpeBRepBuild_Builder::GdumpPNT, "None", py::arg("P"));
cls_TopOpeBRepBuild_Builder.def_static("GdumpORIPARPNT_", (void (*)(const TopAbs_Orientation, const Standard_Real, const gp_Pnt &)) &TopOpeBRepBuild_Builder::GdumpORIPARPNT, "None", py::arg("o"), py::arg("p"), py::arg("Pnt"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHA", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0) -> void { return self.GdumpSHA(a0); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHA", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpSHA, "None", py::arg("S"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHAORI", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0) -> void { return self.GdumpSHAORI(a0); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHAORI", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpSHAORI, "None", py::arg("S"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHAORIGEO", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0) -> void { return self.GdumpSHAORIGEO(a0); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHAORIGEO", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpSHAORIGEO, "None", py::arg("S"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const Standard_Integer a0, const TopAbs_State a1) -> void { return self.GdumpSHASTA(a0, a1); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const Standard_Integer a0, const TopAbs_State a1, const TCollection_AsciiString & a2) -> void { return self.GdumpSHASTA(a0, a1, a2); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", (void (TopOpeBRepBuild_Builder::*)(const Standard_Integer, const TopAbs_State, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_Builder::GdumpSHASTA, "None", py::arg("iS"), py::arg("T"), py::arg("a"), py::arg("b"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0, const TopAbs_State a1) -> void { return self.GdumpSHASTA(a0, a1); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0, const TopAbs_State a1, const TCollection_AsciiString & a2) -> void { return self.GdumpSHASTA(a0, a1, a2); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_Builder::GdumpSHASTA, "None", py::arg("S"), py::arg("T"), py::arg("a"), py::arg("b"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const Standard_Integer a0, const TopAbs_State a1, const TopOpeBRepBuild_ShapeSet & a2) -> void { return self.GdumpSHASTA(a0, a1, a2); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const Standard_Integer a0, const TopAbs_State a1, const TopOpeBRepBuild_ShapeSet & a2, const TCollection_AsciiString & a3) -> void { return self.GdumpSHASTA(a0, a1, a2, a3); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const Standard_Integer a0, const TopAbs_State a1, const TopOpeBRepBuild_ShapeSet & a2, const TCollection_AsciiString & a3, const TCollection_AsciiString & a4) -> void { return self.GdumpSHASTA(a0, a1, a2, a3, a4); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", (void (TopOpeBRepBuild_Builder::*)(const Standard_Integer, const TopAbs_State, const TopOpeBRepBuild_ShapeSet &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_Builder::GdumpSHASTA, "None", py::arg("iS"), py::arg("T"), py::arg("SS"), py::arg("a"), py::arg("b"), py::arg("c"));
cls_TopOpeBRepBuild_Builder.def("GdumpEDG", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0) -> void { return self.GdumpEDG(a0); });
cls_TopOpeBRepBuild_Builder.def("GdumpEDG", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpEDG, "None", py::arg("S"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpEDGVER", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> void { return self.GdumpEDGVER(a0, a1); });
cls_TopOpeBRepBuild_Builder.def("GdumpEDGVER", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpEDGVER, "None", py::arg("E"), py::arg("V"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpSAMDOM", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0) -> void { return self.GdumpSAMDOM(a0); });
cls_TopOpeBRepBuild_Builder.def("GdumpSAMDOM", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpSAMDOM, "None", py::arg("L"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpEXP", (void (TopOpeBRepBuild_Builder::*)(const TopOpeBRepTool_ShapeExplorer &) const) &TopOpeBRepBuild_Builder::GdumpEXP, "None", py::arg("E"));
cls_TopOpeBRepBuild_Builder.def("GdumpSOBU", (void (TopOpeBRepBuild_Builder::*)(TopOpeBRepBuild_SolidBuilder &) const) &TopOpeBRepBuild_Builder::GdumpSOBU, "None", py::arg("SB"));
cls_TopOpeBRepBuild_Builder.def("GdumpFABU", (void (TopOpeBRepBuild_Builder::*)(TopOpeBRepBuild_FaceBuilder &) const) &TopOpeBRepBuild_Builder::GdumpFABU, "None", py::arg("FB"));
cls_TopOpeBRepBuild_Builder.def("GdumpEDBU", (void (TopOpeBRepBuild_Builder::*)(TopOpeBRepBuild_EdgeBuilder &) const) &TopOpeBRepBuild_Builder::GdumpEDBU, "None", py::arg("EB"));
cls_TopOpeBRepBuild_Builder.def("GtraceSPS", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const Standard_Integer) const) &TopOpeBRepBuild_Builder::GtraceSPS, "None", py::arg("iS"));
cls_TopOpeBRepBuild_Builder.def("GtraceSPS", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const Standard_Integer, const Standard_Integer) const) &TopOpeBRepBuild_Builder::GtraceSPS, "None", py::arg("iS"), py::arg("jS"));
cls_TopOpeBRepBuild_Builder.def("GtraceSPS", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::GtraceSPS, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("GtraceSPS", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & S, Standard_Integer & IS){ Standard_Boolean rv = self.GtraceSPS(S, IS); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, IS); }, "None", py::arg("S"), py::arg("IS"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHASETreset", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::GdumpSHASETreset, "None");
cls_TopOpeBRepBuild_Builder.def("GdumpSHASETindex", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::GdumpSHASETindex, "None");
cls_TopOpeBRepBuild_Builder.def_static("PrintGeo_", (void (*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::PrintGeo, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def_static("PrintSur_", (void (*)(const TopoDS_Face &)) &TopOpeBRepBuild_Builder::PrintSur, "None", py::arg("F"));
cls_TopOpeBRepBuild_Builder.def_static("PrintCur_", (void (*)(const TopoDS_Edge &)) &TopOpeBRepBuild_Builder::PrintCur, "None", py::arg("E"));
cls_TopOpeBRepBuild_Builder.def_static("PrintPnt_", (void (*)(const TopoDS_Vertex &)) &TopOpeBRepBuild_Builder::PrintPnt, "None", py::arg("V"));
cls_TopOpeBRepBuild_Builder.def_static("PrintOri_", (void (*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::PrintOri, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def_static("StringState_", (TCollection_AsciiString (*)(const TopAbs_State)) &TopOpeBRepBuild_Builder::StringState, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def_static("GcheckNBOUNDS_", (Standard_Boolean (*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::GcheckNBOUNDS, "None", py::arg("E"));

// Enums

}