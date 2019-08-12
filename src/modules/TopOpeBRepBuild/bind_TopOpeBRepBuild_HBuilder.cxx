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
#include <Standard_Transient.hxx>
#include <TopOpeBRepDS_BuildTool.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_State.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TopOpeBRepBuild_Builder.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <Standard_Type.hxx>
#include <TopOpeBRepBuild_Builder1.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TColStd_DataMapOfIntegerListOfInteger.hxx>

void bind_TopOpeBRepBuild_HBuilder(py::module &mod){

py::class_<TopOpeBRepBuild_HBuilder, opencascade::handle<TopOpeBRepBuild_HBuilder>, Standard_Transient> cls_TopOpeBRepBuild_HBuilder(mod, "TopOpeBRepBuild_HBuilder", "The HBuilder algorithm constructs topological objects from an existing topology and new geometries attached to the topology. It is used to construct the result of a topological operation; the existing topologies are the parts involved in the topological operation and the new geometries are the intersection lines and points.");

// Constructors
cls_TopOpeBRepBuild_HBuilder.def(py::init<const TopOpeBRepDS_BuildTool &>(), py::arg("BT"));

// Fields

// Methods
cls_TopOpeBRepBuild_HBuilder.def("BuildTool", (const TopOpeBRepDS_BuildTool & (TopOpeBRepBuild_HBuilder::*)() const) &TopOpeBRepBuild_HBuilder::BuildTool, "None");
cls_TopOpeBRepBuild_HBuilder.def("Perform", (void (TopOpeBRepBuild_HBuilder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepBuild_HBuilder::Perform, "Stores the data structure <HDS>, Create shapes from the new geometries described in <HDS>.", py::arg("HDS"));
cls_TopOpeBRepBuild_HBuilder.def("Perform", (void (TopOpeBRepBuild_HBuilder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_HBuilder::Perform, "Same as previous + evaluates if an operation performed on shapes S1,S2 is a particular case.", py::arg("HDS"), py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_HBuilder.def("Clear", (void (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::Clear, "Removes all split and merge already performed. Does NOT clear the handled DS.");
cls_TopOpeBRepBuild_HBuilder.def("DataStructure", (opencascade::handle<TopOpeBRepDS_HDataStructure> (TopOpeBRepBuild_HBuilder::*)() const) &TopOpeBRepBuild_HBuilder::DataStructure, "returns the DS handled by this builder");
cls_TopOpeBRepBuild_HBuilder.def("ChangeBuildTool", (TopOpeBRepDS_BuildTool & (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::ChangeBuildTool, "None");
cls_TopOpeBRepBuild_HBuilder.def("MergeShapes", (void (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State, const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_HBuilder::MergeShapes, "Merges the two shapes <S1> and <S2> keeping the parts of states <TB1>,<TB2> in <S1>,<S2>.", py::arg("S1"), py::arg("TB1"), py::arg("S2"), py::arg("TB2"));
cls_TopOpeBRepBuild_HBuilder.def("MergeSolids", (void (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State, const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_HBuilder::MergeSolids, "Merges the two solids <S1> and <S2> keeping the parts in each solid of states <TB1> and <TB2>.", py::arg("S1"), py::arg("TB1"), py::arg("S2"), py::arg("TB2"));
cls_TopOpeBRepBuild_HBuilder.def("MergeSolid", (void (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_HBuilder::MergeSolid, "Merges the solid <S> keeping the parts of state <TB>.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_HBuilder.def("IsSplit", (Standard_Boolean (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_HBuilder::IsSplit, "Returns True if the shape <S> has been split.", py::arg("S"), py::arg("ToBuild"));
cls_TopOpeBRepBuild_HBuilder.def("Splits", (const TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_HBuilder::Splits, "Returns the split parts <ToBuild> of shape <S>.", py::arg("S"), py::arg("ToBuild"));
cls_TopOpeBRepBuild_HBuilder.def("IsMerged", (Standard_Boolean (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_HBuilder::IsMerged, "Returns True if the shape <S> has been merged.", py::arg("S"), py::arg("ToBuild"));
cls_TopOpeBRepBuild_HBuilder.def("Merged", (const TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_HBuilder::Merged, "Returns the merged parts <ToBuild> of shape <S>.", py::arg("S"), py::arg("ToBuild"));
cls_TopOpeBRepBuild_HBuilder.def("NewVertex", (const TopoDS_Shape & (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer) const) &TopOpeBRepBuild_HBuilder::NewVertex, "Returns the vertex created on point <I>.", py::arg("I"));
cls_TopOpeBRepBuild_HBuilder.def("NewEdges", (const TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer) const) &TopOpeBRepBuild_HBuilder::NewEdges, "Returns the edges created on curve <I>.", py::arg("I"));
cls_TopOpeBRepBuild_HBuilder.def("ChangeNewEdges", (TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer)) &TopOpeBRepBuild_HBuilder::ChangeNewEdges, "Returns the edges created on curve <I>.", py::arg("I"));
cls_TopOpeBRepBuild_HBuilder.def("NewFaces", (const TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer) const) &TopOpeBRepBuild_HBuilder::NewFaces, "Returns the faces created on surface <I>.", py::arg("I"));
cls_TopOpeBRepBuild_HBuilder.def("Section", (const TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::Section, "None");
cls_TopOpeBRepBuild_HBuilder.def("InitExtendedSectionDS", [](TopOpeBRepBuild_HBuilder &self) -> void { return self.InitExtendedSectionDS(); });
cls_TopOpeBRepBuild_HBuilder.def("InitExtendedSectionDS", (void (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer)) &TopOpeBRepBuild_HBuilder::InitExtendedSectionDS, "None", py::arg("k"));
cls_TopOpeBRepBuild_HBuilder.def("InitSection", [](TopOpeBRepBuild_HBuilder &self) -> void { return self.InitSection(); });
cls_TopOpeBRepBuild_HBuilder.def("InitSection", (void (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer)) &TopOpeBRepBuild_HBuilder::InitSection, "None", py::arg("k"));
cls_TopOpeBRepBuild_HBuilder.def("MoreSection", (Standard_Boolean (TopOpeBRepBuild_HBuilder::*)() const) &TopOpeBRepBuild_HBuilder::MoreSection, "None");
cls_TopOpeBRepBuild_HBuilder.def("NextSection", (void (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::NextSection, "None");
cls_TopOpeBRepBuild_HBuilder.def("CurrentSection", (const TopoDS_Shape & (TopOpeBRepBuild_HBuilder::*)() const) &TopOpeBRepBuild_HBuilder::CurrentSection, "None");
cls_TopOpeBRepBuild_HBuilder.def("GetDSEdgeFromSectEdge", (Standard_Integer (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepBuild_HBuilder::GetDSEdgeFromSectEdge, "None", py::arg("E"), py::arg("rank"));
cls_TopOpeBRepBuild_HBuilder.def("GetDSFaceFromDSEdge", (TColStd_ListOfInteger & (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepBuild_HBuilder::GetDSFaceFromDSEdge, "None", py::arg("indexEdg"), py::arg("rank"));
cls_TopOpeBRepBuild_HBuilder.def("GetDSCurveFromSectEdge", (Standard_Integer (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_HBuilder::GetDSCurveFromSectEdge, "None", py::arg("SectEdge"));
cls_TopOpeBRepBuild_HBuilder.def("GetDSFaceFromDSCurve", (Standard_Integer (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepBuild_HBuilder::GetDSFaceFromDSCurve, "None", py::arg("indexCur"), py::arg("rank"));
cls_TopOpeBRepBuild_HBuilder.def("GetDSPointFromNewVertex", (Standard_Integer (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_HBuilder::GetDSPointFromNewVertex, "None", py::arg("NewVert"));
cls_TopOpeBRepBuild_HBuilder.def("EdgeCurveAncestors", [](TopOpeBRepBuild_HBuilder &self, const TopoDS_Shape & E, TopoDS_Shape & F1, TopoDS_Shape & F2, Standard_Integer & IC){ Standard_Boolean rv = self.EdgeCurveAncestors(E, F1, F2, IC); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, IC); }, "search for the couple of face F1,F2 (from arguments of supra Perform(S1,S2,HDS)) method which intersection gives section edge E built on an intersection curve. returns True if F1,F2 have been valued. returns False if E is not a section edge built on intersection curve IC.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("IC"));
cls_TopOpeBRepBuild_HBuilder.def("EdgeSectionAncestors", (Standard_Boolean (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_HBuilder::EdgeSectionAncestors, "search for the couple of face F1,F2 (from arguments of supra Perform(S1,S2,HDS)) method which intersection gives section edge E built on at least one edge . returns True if F1,F2 have been valued. returns False if E is not a section edge built on at least one edge of S1 and/or S2. LE1,LE2 are edges of S1,S2 which common part is edge E. LE1 or LE2 may be empty() but not both.", py::arg("E"), py::arg("LF1"), py::arg("LF2"), py::arg("LE1"), py::arg("LE2"));
cls_TopOpeBRepBuild_HBuilder.def("IsKPart", (Standard_Integer (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::IsKPart, "Returns 0 is standard operation, != 0 if particular case");
cls_TopOpeBRepBuild_HBuilder.def("MergeKPart", (void (TopOpeBRepBuild_HBuilder::*)(const TopAbs_State, const TopAbs_State)) &TopOpeBRepBuild_HBuilder::MergeKPart, "None", py::arg("TB1"), py::arg("TB2"));
cls_TopOpeBRepBuild_HBuilder.def("ChangeBuilder", (TopOpeBRepBuild_Builder & (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::ChangeBuilder, "None");
cls_TopOpeBRepBuild_HBuilder.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepBuild_HBuilder::get_type_name, "None");
cls_TopOpeBRepBuild_HBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepBuild_HBuilder::get_type_descriptor, "None");
cls_TopOpeBRepBuild_HBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepBuild_HBuilder::*)() const) &TopOpeBRepBuild_HBuilder::DynamicType, "None");

// Enums

}