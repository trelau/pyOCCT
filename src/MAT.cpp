/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <MAT_Side.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <MAT_Arc.hxx>
#include <Standard_Type.hxx>
#include <MAT_BasicElt.hxx>
#include <MAT_SequenceOfArc.hxx>
#include <MAT_SequenceOfBasicElt.hxx>
#include <MAT_Node.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <MAT_Bisector.hxx>
#include <MAT_ListOfBisector.hxx>
#include <MAT_Edge.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <MAT_DataMapOfIntegerBasicElt.hxx>
#include <MAT_Graph.hxx>
#include <MAT_DataMapOfIntegerBisector.hxx>
#include <MAT_ListOfEdge.hxx>
#include <MAT_DataMapOfIntegerArc.hxx>
#include <MAT_DataMapOfIntegerNode.hxx>
#include <MAT_TListNodeOfListOfBisector.hxx>
#include <MAT_TListNodeOfListOfEdge.hxx>
#include <MAT_Zone.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(MAT, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_Side.hxx
	py::enum_<MAT_Side>(mod, "MAT_Side", "Definition on the Left and the Right on the Fig.")
		.value("MAT_Left", MAT_Side::MAT_Left)
		.value("MAT_Right", MAT_Side::MAT_Right)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_BasicElt.hxx
	py::class_<MAT_BasicElt, opencascade::handle<MAT_BasicElt>, Standard_Transient> cls_MAT_BasicElt(mod, "MAT_BasicElt", "A BasicELt is associated to each elemtary constituant of the figure.");
	cls_MAT_BasicElt.def(py::init<const Standard_Integer>(), py::arg("anInteger"));
	cls_MAT_BasicElt.def("StartArc", (opencascade::handle<MAT_Arc> (MAT_BasicElt::*)() const ) &MAT_BasicElt::StartArc, "Return <startArcLeft> or <startArcRight> corresponding to <aSide>.");
	cls_MAT_BasicElt.def("EndArc", (opencascade::handle<MAT_Arc> (MAT_BasicElt::*)() const ) &MAT_BasicElt::EndArc, "Return <endArcLeft> or <endArcRight> corresponding to <aSide>.");
	cls_MAT_BasicElt.def("Index", (Standard_Integer (MAT_BasicElt::*)() const ) &MAT_BasicElt::Index, "Return the <index> of <me> in Graph.TheBasicElts.");
	cls_MAT_BasicElt.def("GeomIndex", (Standard_Integer (MAT_BasicElt::*)() const ) &MAT_BasicElt::GeomIndex, "Return the <GeomIndex> of <me>.");
	cls_MAT_BasicElt.def("SetStartArc", (void (MAT_BasicElt::*)(const opencascade::handle<MAT_Arc> &)) &MAT_BasicElt::SetStartArc, "None", py::arg("anArc"));
	cls_MAT_BasicElt.def("SetEndArc", (void (MAT_BasicElt::*)(const opencascade::handle<MAT_Arc> &)) &MAT_BasicElt::SetEndArc, "None", py::arg("anArc"));
	cls_MAT_BasicElt.def("SetIndex", (void (MAT_BasicElt::*)(const Standard_Integer)) &MAT_BasicElt::SetIndex, "None", py::arg("anInteger"));
	cls_MAT_BasicElt.def("SetGeomIndex", (void (MAT_BasicElt::*)(const Standard_Integer)) &MAT_BasicElt::SetGeomIndex, "None", py::arg("anInteger"));
	cls_MAT_BasicElt.def_static("get_type_name_", (const char * (*)()) &MAT_BasicElt::get_type_name, "None");
	cls_MAT_BasicElt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_BasicElt::get_type_descriptor, "None");
	cls_MAT_BasicElt.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_BasicElt::*)() const ) &MAT_BasicElt::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_Node.hxx
	py::class_<MAT_Node, opencascade::handle<MAT_Node>, Standard_Transient> cls_MAT_Node(mod, "MAT_Node", "Node of Graph.");
	cls_MAT_Node.def(py::init<const Standard_Integer, const opencascade::handle<MAT_Arc> &, const Standard_Real>(), py::arg("GeomIndex"), py::arg("LinkedArc"), py::arg("Distance"));
	cls_MAT_Node.def("GeomIndex", (Standard_Integer (MAT_Node::*)() const ) &MAT_Node::GeomIndex, "Returns the index associated of the geometric representation of <me>.");
	cls_MAT_Node.def("Index", (Standard_Integer (MAT_Node::*)() const ) &MAT_Node::Index, "Returns the index associated of the node");
	cls_MAT_Node.def("LinkedArcs", (void (MAT_Node::*)(MAT_SequenceOfArc &) const ) &MAT_Node::LinkedArcs, "Returns in <S> the Arcs linked to <me>.", py::arg("S"));
	cls_MAT_Node.def("NearElts", (void (MAT_Node::*)(MAT_SequenceOfBasicElt &) const ) &MAT_Node::NearElts, "Returns in <S> the BasicElts equidistant to <me>.", py::arg("S"));
	cls_MAT_Node.def("Distance", (Standard_Real (MAT_Node::*)() const ) &MAT_Node::Distance, "None");
	cls_MAT_Node.def("PendingNode", (Standard_Boolean (MAT_Node::*)() const ) &MAT_Node::PendingNode, "Returns True if <me> is a pending Node. (ie : the number of Arc Linked = 1)");
	cls_MAT_Node.def("OnBasicElt", (Standard_Boolean (MAT_Node::*)() const ) &MAT_Node::OnBasicElt, "Returns True if <me> belongs to the figure.");
	cls_MAT_Node.def("Infinite", (Standard_Boolean (MAT_Node::*)() const ) &MAT_Node::Infinite, "Returns True if the distance of <me> is Infinite");
	cls_MAT_Node.def("SetIndex", (void (MAT_Node::*)(const Standard_Integer)) &MAT_Node::SetIndex, "Set the index associated of the node", py::arg("anIndex"));
	cls_MAT_Node.def("SetLinkedArc", (void (MAT_Node::*)(const opencascade::handle<MAT_Arc> &)) &MAT_Node::SetLinkedArc, "None", py::arg("anArc"));
	cls_MAT_Node.def_static("get_type_name_", (const char * (*)()) &MAT_Node::get_type_name, "None");
	cls_MAT_Node.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Node::get_type_descriptor, "None");
	cls_MAT_Node.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Node::*)() const ) &MAT_Node::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_Arc.hxx
	py::class_<MAT_Arc, opencascade::handle<MAT_Arc>, Standard_Transient> cls_MAT_Arc(mod, "MAT_Arc", "An Arc is associated to each Bisecting of the mat.");
	cls_MAT_Arc.def(py::init<const Standard_Integer, const Standard_Integer, const opencascade::handle<MAT_BasicElt> &, const opencascade::handle<MAT_BasicElt> &>(), py::arg("ArcIndex"), py::arg("GeomIndex"), py::arg("FirstElement"), py::arg("SecondElement"));
	cls_MAT_Arc.def("Index", (Standard_Integer (MAT_Arc::*)() const ) &MAT_Arc::Index, "Returns the index of <me> in Graph.theArcs.");
	cls_MAT_Arc.def("GeomIndex", (Standard_Integer (MAT_Arc::*)() const ) &MAT_Arc::GeomIndex, "Returns the index associated of the geometric representation of <me>.");
	cls_MAT_Arc.def("FirstElement", (opencascade::handle<MAT_BasicElt> (MAT_Arc::*)() const ) &MAT_Arc::FirstElement, "Returns one of the BasicElt equidistant from <me>.");
	cls_MAT_Arc.def("SecondElement", (opencascade::handle<MAT_BasicElt> (MAT_Arc::*)() const ) &MAT_Arc::SecondElement, "Returns the other BasicElt equidistant from <me>.");
	cls_MAT_Arc.def("FirstNode", (opencascade::handle<MAT_Node> (MAT_Arc::*)() const ) &MAT_Arc::FirstNode, "Returns one Node extremity of <me>.");
	cls_MAT_Arc.def("SecondNode", (opencascade::handle<MAT_Node> (MAT_Arc::*)() const ) &MAT_Arc::SecondNode, "Returns the other Node extremity of <me>.");
	cls_MAT_Arc.def("TheOtherNode", (opencascade::handle<MAT_Node> (MAT_Arc::*)(const opencascade::handle<MAT_Node> &) const ) &MAT_Arc::TheOtherNode, "an Arc has two Node, if <aNode> egal one Returns the other.", py::arg("aNode"));
	cls_MAT_Arc.def("HasNeighbour", (Standard_Boolean (MAT_Arc::*)(const opencascade::handle<MAT_Node> &, const MAT_Side) const ) &MAT_Arc::HasNeighbour, "Returnst True is there is an arc linked to the Node <aNode> located on the side <aSide> of <me>; if <aNode> is not on <me>", py::arg("aNode"), py::arg("aSide"));
	cls_MAT_Arc.def("Neighbour", (opencascade::handle<MAT_Arc> (MAT_Arc::*)(const opencascade::handle<MAT_Node> &, const MAT_Side) const ) &MAT_Arc::Neighbour, "Returns the first arc linked to the Node <aNode> located on the side <aSide> of <me>; if HasNeighbour() returns FALSE.", py::arg("aNode"), py::arg("aSide"));
	cls_MAT_Arc.def("SetIndex", (void (MAT_Arc::*)(const Standard_Integer)) &MAT_Arc::SetIndex, "None", py::arg("anInteger"));
	cls_MAT_Arc.def("SetGeomIndex", (void (MAT_Arc::*)(const Standard_Integer)) &MAT_Arc::SetGeomIndex, "None", py::arg("anInteger"));
	cls_MAT_Arc.def("SetFirstElement", (void (MAT_Arc::*)(const opencascade::handle<MAT_BasicElt> &)) &MAT_Arc::SetFirstElement, "None", py::arg("aBasicElt"));
	cls_MAT_Arc.def("SetSecondElement", (void (MAT_Arc::*)(const opencascade::handle<MAT_BasicElt> &)) &MAT_Arc::SetSecondElement, "None", py::arg("aBasicElt"));
	cls_MAT_Arc.def("SetFirstNode", (void (MAT_Arc::*)(const opencascade::handle<MAT_Node> &)) &MAT_Arc::SetFirstNode, "None", py::arg("aNode"));
	cls_MAT_Arc.def("SetSecondNode", (void (MAT_Arc::*)(const opencascade::handle<MAT_Node> &)) &MAT_Arc::SetSecondNode, "None", py::arg("aNode"));
	cls_MAT_Arc.def("SetFirstArc", (void (MAT_Arc::*)(const MAT_Side, const opencascade::handle<MAT_Arc> &)) &MAT_Arc::SetFirstArc, "None", py::arg("aSide"), py::arg("anArc"));
	cls_MAT_Arc.def("SetSecondArc", (void (MAT_Arc::*)(const MAT_Side, const opencascade::handle<MAT_Arc> &)) &MAT_Arc::SetSecondArc, "None", py::arg("aSide"), py::arg("anArc"));
	cls_MAT_Arc.def("SetNeighbour", (void (MAT_Arc::*)(const MAT_Side, const opencascade::handle<MAT_Node> &, const opencascade::handle<MAT_Arc> &)) &MAT_Arc::SetNeighbour, "None", py::arg("aSide"), py::arg("aNode"), py::arg("anArc"));
	cls_MAT_Arc.def_static("get_type_name_", (const char * (*)()) &MAT_Arc::get_type_name, "None");
	cls_MAT_Arc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Arc::get_type_descriptor, "None");
	cls_MAT_Arc.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Arc::*)() const ) &MAT_Arc::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_Bisector.hxx
	py::class_<MAT_Bisector, opencascade::handle<MAT_Bisector>, Standard_Transient> cls_MAT_Bisector(mod, "MAT_Bisector", "None");
	cls_MAT_Bisector.def(py::init<>());
	cls_MAT_Bisector.def("AddBisector", (void (MAT_Bisector::*)(const opencascade::handle<MAT_Bisector> &) const ) &MAT_Bisector::AddBisector, "None", py::arg("abisector"));
	cls_MAT_Bisector.def("List", (opencascade::handle<MAT_ListOfBisector> (MAT_Bisector::*)() const ) &MAT_Bisector::List, "None");
	cls_MAT_Bisector.def("FirstBisector", (opencascade::handle<MAT_Bisector> (MAT_Bisector::*)() const ) &MAT_Bisector::FirstBisector, "None");
	cls_MAT_Bisector.def("LastBisector", (opencascade::handle<MAT_Bisector> (MAT_Bisector::*)() const ) &MAT_Bisector::LastBisector, "None");
	cls_MAT_Bisector.def("BisectorNumber", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::BisectorNumber, "None", py::arg("anumber"));
	cls_MAT_Bisector.def("IndexNumber", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::IndexNumber, "None", py::arg("anumber"));
	cls_MAT_Bisector.def("FirstEdge", (void (MAT_Bisector::*)(const opencascade::handle<MAT_Edge> &)) &MAT_Bisector::FirstEdge, "None", py::arg("anedge"));
	cls_MAT_Bisector.def("SecondEdge", (void (MAT_Bisector::*)(const opencascade::handle<MAT_Edge> &)) &MAT_Bisector::SecondEdge, "None", py::arg("anedge"));
	cls_MAT_Bisector.def("IssuePoint", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::IssuePoint, "None", py::arg("apoint"));
	cls_MAT_Bisector.def("EndPoint", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::EndPoint, "None", py::arg("apoint"));
	cls_MAT_Bisector.def("DistIssuePoint", (void (MAT_Bisector::*)(const Standard_Real)) &MAT_Bisector::DistIssuePoint, "None", py::arg("areal"));
	cls_MAT_Bisector.def("FirstVector", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::FirstVector, "None", py::arg("avector"));
	cls_MAT_Bisector.def("SecondVector", (void (MAT_Bisector::*)(const Standard_Integer)) &MAT_Bisector::SecondVector, "None", py::arg("avector"));
	cls_MAT_Bisector.def("Sense", (void (MAT_Bisector::*)(const Standard_Real)) &MAT_Bisector::Sense, "None", py::arg("asense"));
	cls_MAT_Bisector.def("FirstParameter", (void (MAT_Bisector::*)(const Standard_Real)) &MAT_Bisector::FirstParameter, "None", py::arg("aparameter"));
	cls_MAT_Bisector.def("SecondParameter", (void (MAT_Bisector::*)(const Standard_Real)) &MAT_Bisector::SecondParameter, "None", py::arg("aparameter"));
	cls_MAT_Bisector.def("BisectorNumber", (Standard_Integer (MAT_Bisector::*)() const ) &MAT_Bisector::BisectorNumber, "None");
	cls_MAT_Bisector.def("IndexNumber", (Standard_Integer (MAT_Bisector::*)() const ) &MAT_Bisector::IndexNumber, "None");
	cls_MAT_Bisector.def("FirstEdge", (opencascade::handle<MAT_Edge> (MAT_Bisector::*)() const ) &MAT_Bisector::FirstEdge, "None");
	cls_MAT_Bisector.def("SecondEdge", (opencascade::handle<MAT_Edge> (MAT_Bisector::*)() const ) &MAT_Bisector::SecondEdge, "None");
	cls_MAT_Bisector.def("IssuePoint", (Standard_Integer (MAT_Bisector::*)() const ) &MAT_Bisector::IssuePoint, "None");
	cls_MAT_Bisector.def("EndPoint", (Standard_Integer (MAT_Bisector::*)() const ) &MAT_Bisector::EndPoint, "None");
	cls_MAT_Bisector.def("DistIssuePoint", (Standard_Real (MAT_Bisector::*)() const ) &MAT_Bisector::DistIssuePoint, "None");
	cls_MAT_Bisector.def("FirstVector", (Standard_Integer (MAT_Bisector::*)() const ) &MAT_Bisector::FirstVector, "None");
	cls_MAT_Bisector.def("SecondVector", (Standard_Integer (MAT_Bisector::*)() const ) &MAT_Bisector::SecondVector, "None");
	cls_MAT_Bisector.def("Sense", (Standard_Real (MAT_Bisector::*)() const ) &MAT_Bisector::Sense, "None");
	cls_MAT_Bisector.def("FirstParameter", (Standard_Real (MAT_Bisector::*)() const ) &MAT_Bisector::FirstParameter, "None");
	cls_MAT_Bisector.def("SecondParameter", (Standard_Real (MAT_Bisector::*)() const ) &MAT_Bisector::SecondParameter, "None");
	// FIXME cls_MAT_Bisector.def("Dump", (void (MAT_Bisector::*)(const Standard_Integer, const Standard_Integer) const ) &MAT_Bisector::Dump, "None", py::arg("ashift"), py::arg("alevel"));
	cls_MAT_Bisector.def_static("get_type_name_", (const char * (*)()) &MAT_Bisector::get_type_name, "None");
	cls_MAT_Bisector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Bisector::get_type_descriptor, "None");
	cls_MAT_Bisector.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Bisector::*)() const ) &MAT_Bisector::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_Graph.hxx
	py::class_<MAT_Graph, opencascade::handle<MAT_Graph>, Standard_Transient> cls_MAT_Graph(mod, "MAT_Graph", "The Class Graph permits the exploration of the Bisector Locus.");
	cls_MAT_Graph.def(py::init<>());
	cls_MAT_Graph.def("Perform", (void (MAT_Graph::*)(const Standard_Boolean, const opencascade::handle<MAT_ListOfBisector> &, const Standard_Integer, const Standard_Integer)) &MAT_Graph::Perform, "Construct <me> from the result of the method <CreateMat> of the class <MAT> from <MAT>.", py::arg("SemiInfinite"), py::arg("TheRoots"), py::arg("NbBasicElts"), py::arg("NbArcs"));
	cls_MAT_Graph.def("Arc", (opencascade::handle<MAT_Arc> (MAT_Graph::*)(const Standard_Integer) const ) &MAT_Graph::Arc, "Return the Arc of index <Index> in <theArcs>.", py::arg("Index"));
	cls_MAT_Graph.def("BasicElt", (opencascade::handle<MAT_BasicElt> (MAT_Graph::*)(const Standard_Integer) const ) &MAT_Graph::BasicElt, "Return the BasicElt of index <Index> in <theBasicElts>.", py::arg("Index"));
	cls_MAT_Graph.def("Node", (opencascade::handle<MAT_Node> (MAT_Graph::*)(const Standard_Integer) const ) &MAT_Graph::Node, "Return the Node of index <Index> in <theNodes>.", py::arg("Index"));
	cls_MAT_Graph.def("NumberOfArcs", (Standard_Integer (MAT_Graph::*)() const ) &MAT_Graph::NumberOfArcs, "Return the number of arcs of <me>.");
	cls_MAT_Graph.def("NumberOfNodes", (Standard_Integer (MAT_Graph::*)() const ) &MAT_Graph::NumberOfNodes, "Return the number of nodes of <me>.");
	cls_MAT_Graph.def("NumberOfBasicElts", (Standard_Integer (MAT_Graph::*)() const ) &MAT_Graph::NumberOfBasicElts, "Return the number of basic elements of <me>.");
	cls_MAT_Graph.def("NumberOfInfiniteNodes", (Standard_Integer (MAT_Graph::*)() const ) &MAT_Graph::NumberOfInfiniteNodes, "Return the number of infinites nodes of <me>.");
	cls_MAT_Graph.def("FusionOfBasicElts", [](MAT_Graph &self, const Standard_Integer IndexElt1, const Standard_Integer IndexElt2, Standard_Boolean & MergeArc1, Standard_Integer & GeomIndexArc1, Standard_Integer & GeomIndexArc2, Standard_Boolean & MergeArc2, Standard_Integer & GeomIndexArc3, Standard_Integer & GeomIndexArc4){ self.FusionOfBasicElts(IndexElt1, IndexElt2, MergeArc1, GeomIndexArc1, GeomIndexArc2, MergeArc2, GeomIndexArc3, GeomIndexArc4); return std::tuple<Standard_Boolean &, Standard_Integer &, Standard_Integer &, Standard_Boolean &, Standard_Integer &, Standard_Integer &>(MergeArc1, GeomIndexArc1, GeomIndexArc2, MergeArc2, GeomIndexArc3, GeomIndexArc4); }, "Merge two BasicElts. The End of the BasicElt Elt1 of IndexElt1 becomes The End of the BasicElt Elt2 of IndexElt2. Elt2 is replaced in the arcs by Elt1, Elt2 is eliminated.", py::arg("IndexElt1"), py::arg("IndexElt2"), py::arg("MergeArc1"), py::arg("GeomIndexArc1"), py::arg("GeomIndexArc2"), py::arg("MergeArc2"), py::arg("GeomIndexArc3"), py::arg("GeomIndexArc4"));
	cls_MAT_Graph.def("CompactArcs", (void (MAT_Graph::*)()) &MAT_Graph::CompactArcs, "None");
	cls_MAT_Graph.def("CompactNodes", (void (MAT_Graph::*)()) &MAT_Graph::CompactNodes, "None");
	cls_MAT_Graph.def("ChangeBasicElts", (void (MAT_Graph::*)(const MAT_DataMapOfIntegerBasicElt &)) &MAT_Graph::ChangeBasicElts, "None", py::arg("NewMap"));
	cls_MAT_Graph.def("ChangeBasicElt", (opencascade::handle<MAT_BasicElt> (MAT_Graph::*)(const Standard_Integer)) &MAT_Graph::ChangeBasicElt, "None", py::arg("Index"));
	cls_MAT_Graph.def_static("get_type_name_", (const char * (*)()) &MAT_Graph::get_type_name, "None");
	cls_MAT_Graph.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Graph::get_type_descriptor, "None");
	cls_MAT_Graph.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Graph::*)() const ) &MAT_Graph::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_Edge.hxx
	py::class_<MAT_Edge, opencascade::handle<MAT_Edge>, Standard_Transient> cls_MAT_Edge(mod, "MAT_Edge", "None");
	cls_MAT_Edge.def(py::init<>());
	cls_MAT_Edge.def("EdgeNumber", (void (MAT_Edge::*)(const Standard_Integer)) &MAT_Edge::EdgeNumber, "None", py::arg("anumber"));
	cls_MAT_Edge.def("FirstBisector", (void (MAT_Edge::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_Edge::FirstBisector, "None", py::arg("abisector"));
	cls_MAT_Edge.def("SecondBisector", (void (MAT_Edge::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_Edge::SecondBisector, "None", py::arg("abisector"));
	cls_MAT_Edge.def("Distance", (void (MAT_Edge::*)(const Standard_Real)) &MAT_Edge::Distance, "None", py::arg("adistance"));
	cls_MAT_Edge.def("IntersectionPoint", (void (MAT_Edge::*)(const Standard_Integer)) &MAT_Edge::IntersectionPoint, "None", py::arg("apoint"));
	cls_MAT_Edge.def("EdgeNumber", (Standard_Integer (MAT_Edge::*)() const ) &MAT_Edge::EdgeNumber, "None");
	cls_MAT_Edge.def("FirstBisector", (opencascade::handle<MAT_Bisector> (MAT_Edge::*)() const ) &MAT_Edge::FirstBisector, "None");
	cls_MAT_Edge.def("SecondBisector", (opencascade::handle<MAT_Bisector> (MAT_Edge::*)() const ) &MAT_Edge::SecondBisector, "None");
	cls_MAT_Edge.def("Distance", (Standard_Real (MAT_Edge::*)() const ) &MAT_Edge::Distance, "None");
	cls_MAT_Edge.def("IntersectionPoint", (Standard_Integer (MAT_Edge::*)() const ) &MAT_Edge::IntersectionPoint, "None");
	// FIXME cls_MAT_Edge.def("Dump", (void (MAT_Edge::*)(const Standard_Integer, const Standard_Integer) const ) &MAT_Edge::Dump, "None", py::arg("ashift"), py::arg("alevel"));
	cls_MAT_Edge.def_static("get_type_name_", (const char * (*)()) &MAT_Edge::get_type_name, "None");
	cls_MAT_Edge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Edge::get_type_descriptor, "None");
	cls_MAT_Edge.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Edge::*)() const ) &MAT_Edge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_ListOfBisector.hxx
	py::class_<MAT_ListOfBisector, opencascade::handle<MAT_ListOfBisector>, Standard_Transient> cls_MAT_ListOfBisector(mod, "MAT_ListOfBisector", "None");
	cls_MAT_ListOfBisector.def(py::init<>());
	cls_MAT_ListOfBisector.def("First", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::First, "None");
	cls_MAT_ListOfBisector.def("Last", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::Last, "None");
	cls_MAT_ListOfBisector.def("Init", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_ListOfBisector::Init, "None", py::arg("aniten"));
	cls_MAT_ListOfBisector.def("Next", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::Next, "None");
	cls_MAT_ListOfBisector.def("Previous", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::Previous, "None");
	cls_MAT_ListOfBisector.def("More", (Standard_Boolean (MAT_ListOfBisector::*)() const ) &MAT_ListOfBisector::More, "None");
	cls_MAT_ListOfBisector.def("Current", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)() const ) &MAT_ListOfBisector::Current, "None");
	cls_MAT_ListOfBisector.def("Current", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &) const ) &MAT_ListOfBisector::Current, "None", py::arg("anitem"));
	cls_MAT_ListOfBisector.def("FirstItem", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)() const ) &MAT_ListOfBisector::FirstItem, "None");
	cls_MAT_ListOfBisector.def("LastItem", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)() const ) &MAT_ListOfBisector::LastItem, "None");
	cls_MAT_ListOfBisector.def("PreviousItem", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)() const ) &MAT_ListOfBisector::PreviousItem, "None");
	cls_MAT_ListOfBisector.def("NextItem", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)() const ) &MAT_ListOfBisector::NextItem, "None");
	cls_MAT_ListOfBisector.def("Number", (Standard_Integer (MAT_ListOfBisector::*)() const ) &MAT_ListOfBisector::Number, "None");
	cls_MAT_ListOfBisector.def("Index", (Standard_Integer (MAT_ListOfBisector::*)() const ) &MAT_ListOfBisector::Index, "None");
	cls_MAT_ListOfBisector.def("Brackets", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)(const Standard_Integer)) &MAT_ListOfBisector::Brackets, "None", py::arg("anindex"));
	cls_MAT_ListOfBisector.def("__call__", (opencascade::handle<MAT_Bisector> (MAT_ListOfBisector::*)(const Standard_Integer)) &MAT_ListOfBisector::operator(), py::is_operator(), "None", py::arg("anindex"));
	cls_MAT_ListOfBisector.def("Unlink", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::Unlink, "None");
	cls_MAT_ListOfBisector.def("LinkBefore", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_ListOfBisector::LinkBefore, "None", py::arg("anitem"));
	cls_MAT_ListOfBisector.def("LinkAfter", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_ListOfBisector::LinkAfter, "None", py::arg("anitem"));
	cls_MAT_ListOfBisector.def("FrontAdd", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_ListOfBisector::FrontAdd, "None", py::arg("anitem"));
	cls_MAT_ListOfBisector.def("BackAdd", (void (MAT_ListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_ListOfBisector::BackAdd, "None", py::arg("anitem"));
	cls_MAT_ListOfBisector.def("Permute", (void (MAT_ListOfBisector::*)()) &MAT_ListOfBisector::Permute, "None");
	cls_MAT_ListOfBisector.def("Loop", (void (MAT_ListOfBisector::*)() const ) &MAT_ListOfBisector::Loop, "None");
	cls_MAT_ListOfBisector.def("IsEmpty", (Standard_Boolean (MAT_ListOfBisector::*)() const ) &MAT_ListOfBisector::IsEmpty, "None");
	// FIXME cls_MAT_ListOfBisector.def("Dump", (void (MAT_ListOfBisector::*)(const Standard_Integer, const Standard_Integer)) &MAT_ListOfBisector::Dump, "None", py::arg("ashift"), py::arg("alevel"));
	cls_MAT_ListOfBisector.def_static("get_type_name_", (const char * (*)()) &MAT_ListOfBisector::get_type_name, "None");
	cls_MAT_ListOfBisector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_ListOfBisector::get_type_descriptor, "None");
	cls_MAT_ListOfBisector.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_ListOfBisector::*)() const ) &MAT_ListOfBisector::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_ListOfEdge.hxx
	py::class_<MAT_ListOfEdge, opencascade::handle<MAT_ListOfEdge>, Standard_Transient> cls_MAT_ListOfEdge(mod, "MAT_ListOfEdge", "None");
	cls_MAT_ListOfEdge.def(py::init<>());
	cls_MAT_ListOfEdge.def("First", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::First, "None");
	cls_MAT_ListOfEdge.def("Last", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::Last, "None");
	cls_MAT_ListOfEdge.def("Init", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_ListOfEdge::Init, "None", py::arg("aniten"));
	cls_MAT_ListOfEdge.def("Next", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::Next, "None");
	cls_MAT_ListOfEdge.def("Previous", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::Previous, "None");
	cls_MAT_ListOfEdge.def("More", (Standard_Boolean (MAT_ListOfEdge::*)() const ) &MAT_ListOfEdge::More, "None");
	cls_MAT_ListOfEdge.def("Current", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)() const ) &MAT_ListOfEdge::Current, "None");
	cls_MAT_ListOfEdge.def("Current", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &) const ) &MAT_ListOfEdge::Current, "None", py::arg("anitem"));
	cls_MAT_ListOfEdge.def("FirstItem", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)() const ) &MAT_ListOfEdge::FirstItem, "None");
	cls_MAT_ListOfEdge.def("LastItem", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)() const ) &MAT_ListOfEdge::LastItem, "None");
	cls_MAT_ListOfEdge.def("PreviousItem", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)() const ) &MAT_ListOfEdge::PreviousItem, "None");
	cls_MAT_ListOfEdge.def("NextItem", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)() const ) &MAT_ListOfEdge::NextItem, "None");
	cls_MAT_ListOfEdge.def("Number", (Standard_Integer (MAT_ListOfEdge::*)() const ) &MAT_ListOfEdge::Number, "None");
	cls_MAT_ListOfEdge.def("Index", (Standard_Integer (MAT_ListOfEdge::*)() const ) &MAT_ListOfEdge::Index, "None");
	cls_MAT_ListOfEdge.def("Brackets", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)(const Standard_Integer)) &MAT_ListOfEdge::Brackets, "None", py::arg("anindex"));
	cls_MAT_ListOfEdge.def("__call__", (opencascade::handle<MAT_Edge> (MAT_ListOfEdge::*)(const Standard_Integer)) &MAT_ListOfEdge::operator(), py::is_operator(), "None", py::arg("anindex"));
	cls_MAT_ListOfEdge.def("Unlink", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::Unlink, "None");
	cls_MAT_ListOfEdge.def("LinkBefore", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_ListOfEdge::LinkBefore, "None", py::arg("anitem"));
	cls_MAT_ListOfEdge.def("LinkAfter", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_ListOfEdge::LinkAfter, "None", py::arg("anitem"));
	cls_MAT_ListOfEdge.def("FrontAdd", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_ListOfEdge::FrontAdd, "None", py::arg("anitem"));
	cls_MAT_ListOfEdge.def("BackAdd", (void (MAT_ListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_ListOfEdge::BackAdd, "None", py::arg("anitem"));
	cls_MAT_ListOfEdge.def("Permute", (void (MAT_ListOfEdge::*)()) &MAT_ListOfEdge::Permute, "None");
	cls_MAT_ListOfEdge.def("Loop", (void (MAT_ListOfEdge::*)() const ) &MAT_ListOfEdge::Loop, "None");
	cls_MAT_ListOfEdge.def("IsEmpty", (Standard_Boolean (MAT_ListOfEdge::*)() const ) &MAT_ListOfEdge::IsEmpty, "None");
	// FIXME cls_MAT_ListOfEdge.def("Dump", (void (MAT_ListOfEdge::*)(const Standard_Integer, const Standard_Integer)) &MAT_ListOfEdge::Dump, "None", py::arg("ashift"), py::arg("alevel"));
	cls_MAT_ListOfEdge.def_static("get_type_name_", (const char * (*)()) &MAT_ListOfEdge::get_type_name, "None");
	cls_MAT_ListOfEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_ListOfEdge::get_type_descriptor, "None");
	cls_MAT_ListOfEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_ListOfEdge::*)() const ) &MAT_ListOfEdge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_TListNodeOfListOfBisector.hxx
	py::class_<MAT_TListNodeOfListOfBisector, opencascade::handle<MAT_TListNodeOfListOfBisector>, Standard_Transient> cls_MAT_TListNodeOfListOfBisector(mod, "MAT_TListNodeOfListOfBisector", "None");
	cls_MAT_TListNodeOfListOfBisector.def(py::init<>());
	cls_MAT_TListNodeOfListOfBisector.def(py::init<const opencascade::handle<MAT_Bisector> &>(), py::arg("anitem"));
	cls_MAT_TListNodeOfListOfBisector.def("GetItem", (opencascade::handle<MAT_Bisector> (MAT_TListNodeOfListOfBisector::*)() const ) &MAT_TListNodeOfListOfBisector::GetItem, "None");
	cls_MAT_TListNodeOfListOfBisector.def("Next", (opencascade::handle<MAT_TListNodeOfListOfBisector> (MAT_TListNodeOfListOfBisector::*)() const ) &MAT_TListNodeOfListOfBisector::Next, "None");
	cls_MAT_TListNodeOfListOfBisector.def("Previous", (opencascade::handle<MAT_TListNodeOfListOfBisector> (MAT_TListNodeOfListOfBisector::*)() const ) &MAT_TListNodeOfListOfBisector::Previous, "None");
	cls_MAT_TListNodeOfListOfBisector.def("SetItem", (void (MAT_TListNodeOfListOfBisector::*)(const opencascade::handle<MAT_Bisector> &)) &MAT_TListNodeOfListOfBisector::SetItem, "None", py::arg("anitem"));
	cls_MAT_TListNodeOfListOfBisector.def("Next", (void (MAT_TListNodeOfListOfBisector::*)(const opencascade::handle<MAT_TListNodeOfListOfBisector> &)) &MAT_TListNodeOfListOfBisector::Next, "None", py::arg("atlistnode"));
	cls_MAT_TListNodeOfListOfBisector.def("Previous", (void (MAT_TListNodeOfListOfBisector::*)(const opencascade::handle<MAT_TListNodeOfListOfBisector> &)) &MAT_TListNodeOfListOfBisector::Previous, "None", py::arg("atlistnode"));
	cls_MAT_TListNodeOfListOfBisector.def("Dummy", (void (MAT_TListNodeOfListOfBisector::*)() const ) &MAT_TListNodeOfListOfBisector::Dummy, "None");
	cls_MAT_TListNodeOfListOfBisector.def_static("get_type_name_", (const char * (*)()) &MAT_TListNodeOfListOfBisector::get_type_name, "None");
	cls_MAT_TListNodeOfListOfBisector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_TListNodeOfListOfBisector::get_type_descriptor, "None");
	cls_MAT_TListNodeOfListOfBisector.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_TListNodeOfListOfBisector::*)() const ) &MAT_TListNodeOfListOfBisector::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_TListNodeOfListOfEdge.hxx
	py::class_<MAT_TListNodeOfListOfEdge, opencascade::handle<MAT_TListNodeOfListOfEdge>, Standard_Transient> cls_MAT_TListNodeOfListOfEdge(mod, "MAT_TListNodeOfListOfEdge", "None");
	cls_MAT_TListNodeOfListOfEdge.def(py::init<>());
	cls_MAT_TListNodeOfListOfEdge.def(py::init<const opencascade::handle<MAT_Edge> &>(), py::arg("anitem"));
	cls_MAT_TListNodeOfListOfEdge.def("GetItem", (opencascade::handle<MAT_Edge> (MAT_TListNodeOfListOfEdge::*)() const ) &MAT_TListNodeOfListOfEdge::GetItem, "None");
	cls_MAT_TListNodeOfListOfEdge.def("Next", (opencascade::handle<MAT_TListNodeOfListOfEdge> (MAT_TListNodeOfListOfEdge::*)() const ) &MAT_TListNodeOfListOfEdge::Next, "None");
	cls_MAT_TListNodeOfListOfEdge.def("Previous", (opencascade::handle<MAT_TListNodeOfListOfEdge> (MAT_TListNodeOfListOfEdge::*)() const ) &MAT_TListNodeOfListOfEdge::Previous, "None");
	cls_MAT_TListNodeOfListOfEdge.def("SetItem", (void (MAT_TListNodeOfListOfEdge::*)(const opencascade::handle<MAT_Edge> &)) &MAT_TListNodeOfListOfEdge::SetItem, "None", py::arg("anitem"));
	cls_MAT_TListNodeOfListOfEdge.def("Next", (void (MAT_TListNodeOfListOfEdge::*)(const opencascade::handle<MAT_TListNodeOfListOfEdge> &)) &MAT_TListNodeOfListOfEdge::Next, "None", py::arg("atlistnode"));
	cls_MAT_TListNodeOfListOfEdge.def("Previous", (void (MAT_TListNodeOfListOfEdge::*)(const opencascade::handle<MAT_TListNodeOfListOfEdge> &)) &MAT_TListNodeOfListOfEdge::Previous, "None", py::arg("atlistnode"));
	cls_MAT_TListNodeOfListOfEdge.def("Dummy", (void (MAT_TListNodeOfListOfEdge::*)() const ) &MAT_TListNodeOfListOfEdge::Dummy, "None");
	cls_MAT_TListNodeOfListOfEdge.def_static("get_type_name_", (const char * (*)()) &MAT_TListNodeOfListOfEdge::get_type_name, "None");
	cls_MAT_TListNodeOfListOfEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_TListNodeOfListOfEdge::get_type_descriptor, "None");
	cls_MAT_TListNodeOfListOfEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_TListNodeOfListOfEdge::*)() const ) &MAT_TListNodeOfListOfEdge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_Zone.hxx
	py::class_<MAT_Zone, opencascade::handle<MAT_Zone>, Standard_Transient> cls_MAT_Zone(mod, "MAT_Zone", "Definition of Zone of Proximity of a BasicElt : ---------------------------------------------- A Zone of proximity is the set of the points which are more near from the BasicElt than any other.");
	cls_MAT_Zone.def(py::init<>());
	cls_MAT_Zone.def(py::init<const opencascade::handle<MAT_BasicElt> &>(), py::arg("aBasicElt"));
	cls_MAT_Zone.def("Perform", (void (MAT_Zone::*)(const opencascade::handle<MAT_BasicElt> &)) &MAT_Zone::Perform, "Compute the frontier of the Zone of proximity.", py::arg("aBasicElt"));
	cls_MAT_Zone.def("NumberOfArcs", (Standard_Integer (MAT_Zone::*)() const ) &MAT_Zone::NumberOfArcs, "Return the number Of Arcs On the frontier of <me>.");
	cls_MAT_Zone.def("ArcOnFrontier", (opencascade::handle<MAT_Arc> (MAT_Zone::*)(const Standard_Integer) const ) &MAT_Zone::ArcOnFrontier, "Return the Arc number <Index> on the frontier. of <me>.", py::arg("Index"));
	cls_MAT_Zone.def("NoEmptyZone", (Standard_Boolean (MAT_Zone::*)() const ) &MAT_Zone::NoEmptyZone, "Return TRUE if <me> is not empty .");
	cls_MAT_Zone.def("Limited", (Standard_Boolean (MAT_Zone::*)() const ) &MAT_Zone::Limited, "Return TRUE if <me> is Limited.");
	cls_MAT_Zone.def_static("get_type_name_", (const char * (*)()) &MAT_Zone::get_type_name, "None");
	cls_MAT_Zone.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Zone::get_type_descriptor, "None");
	cls_MAT_Zone.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Zone::*)() const ) &MAT_Zone::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_SequenceOfArc.hxx
	bind_NCollection_Sequence<opencascade::handle<MAT_Arc> >(mod, "MAT_SequenceOfArc");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_SequenceOfBasicElt.hxx
	bind_NCollection_Sequence<opencascade::handle<MAT_BasicElt> >(mod, "MAT_SequenceOfBasicElt");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_DataMapOfIntegerBasicElt.hxx
	bind_NCollection_DataMap<int, opencascade::handle<MAT_BasicElt>, NCollection_DefaultHasher<int> >(mod, "MAT_DataMapOfIntegerBasicElt");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_DataMapOfIntegerBisector.hxx
	bind_NCollection_DataMap<int, opencascade::handle<MAT_Bisector>, NCollection_DefaultHasher<int> >(mod, "MAT_DataMapOfIntegerBisector");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_DataMapOfIntegerArc.hxx
	bind_NCollection_DataMap<int, opencascade::handle<MAT_Arc>, NCollection_DefaultHasher<int> >(mod, "MAT_DataMapOfIntegerArc");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_DataMapOfIntegerNode.hxx
	bind_NCollection_DataMap<int, opencascade::handle<MAT_Node>, NCollection_DefaultHasher<int> >(mod, "MAT_DataMapOfIntegerNode");

	/* FIXME

	*/


}
