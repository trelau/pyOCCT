#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

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
	cls_MAT_Graph.def("FusionOfBasicElts", (void (MAT_Graph::*)(const Standard_Integer, const Standard_Integer, Standard_Boolean &, Standard_Integer &, Standard_Integer &, Standard_Boolean &, Standard_Integer &, Standard_Integer &)) &MAT_Graph::FusionOfBasicElts, "Merge two BasicElts. The End of the BasicElt Elt1 of IndexElt1 becomes The End of the BasicElt Elt2 of IndexElt2. Elt2 is replaced in the arcs by Elt1, Elt2 is eliminated.", py::arg("IndexElt1"), py::arg("IndexElt2"), py::arg("MergeArc1"), py::arg("GeomIndexArc1"), py::arg("GeomIndexArc2"), py::arg("MergeArc2"), py::arg("GeomIndexArc3"), py::arg("GeomIndexArc4"));
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

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<MAT_SequenceOfArc, std::unique_ptr<MAT_SequenceOfArc, Deleter<MAT_SequenceOfArc>>, NCollection_BaseSequence> cls_MAT_SequenceOfArc(mod, "MAT_SequenceOfArc", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_MAT_SequenceOfArc.def(py::init<>());
	cls_MAT_SequenceOfArc.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_MAT_SequenceOfArc.def(py::init([] (const MAT_SequenceOfArc &other) {return new MAT_SequenceOfArc(other);}), "Copy constructor", py::arg("other"));
	cls_MAT_SequenceOfArc.def("begin", (MAT_SequenceOfArc::iterator (MAT_SequenceOfArc::*)() const ) &MAT_SequenceOfArc::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_MAT_SequenceOfArc.def("end", (MAT_SequenceOfArc::iterator (MAT_SequenceOfArc::*)() const ) &MAT_SequenceOfArc::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_MAT_SequenceOfArc.def("cbegin", (MAT_SequenceOfArc::const_iterator (MAT_SequenceOfArc::*)() const ) &MAT_SequenceOfArc::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_MAT_SequenceOfArc.def("cend", (MAT_SequenceOfArc::const_iterator (MAT_SequenceOfArc::*)() const ) &MAT_SequenceOfArc::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_MAT_SequenceOfArc.def("Size", (Standard_Integer (MAT_SequenceOfArc::*)() const ) &MAT_SequenceOfArc::Size, "Number of items");
	cls_MAT_SequenceOfArc.def("Length", (Standard_Integer (MAT_SequenceOfArc::*)() const ) &MAT_SequenceOfArc::Length, "Number of items");
	cls_MAT_SequenceOfArc.def("Lower", (Standard_Integer (MAT_SequenceOfArc::*)() const ) &MAT_SequenceOfArc::Lower, "Method for consistency with other collections.");
	cls_MAT_SequenceOfArc.def("Upper", (Standard_Integer (MAT_SequenceOfArc::*)() const ) &MAT_SequenceOfArc::Upper, "Method for consistency with other collections.");
	cls_MAT_SequenceOfArc.def("IsEmpty", (Standard_Boolean (MAT_SequenceOfArc::*)() const ) &MAT_SequenceOfArc::IsEmpty, "Empty query");
	cls_MAT_SequenceOfArc.def("Reverse", (void (MAT_SequenceOfArc::*)()) &MAT_SequenceOfArc::Reverse, "Reverse sequence");
	cls_MAT_SequenceOfArc.def("Exchange", (void (MAT_SequenceOfArc::*)(const Standard_Integer, const Standard_Integer)) &MAT_SequenceOfArc::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_MAT_SequenceOfArc.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &MAT_SequenceOfArc::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_MAT_SequenceOfArc.def("Clear", [](MAT_SequenceOfArc &self) -> void { return self.Clear(); });
	cls_MAT_SequenceOfArc.def("Clear", (void (MAT_SequenceOfArc::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT_SequenceOfArc::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_MAT_SequenceOfArc.def("Assign", (MAT_SequenceOfArc & (MAT_SequenceOfArc::*)(const MAT_SequenceOfArc &)) &MAT_SequenceOfArc::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT_SequenceOfArc.def("assign", (MAT_SequenceOfArc & (MAT_SequenceOfArc::*)(const MAT_SequenceOfArc &)) &MAT_SequenceOfArc::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_MAT_SequenceOfArc.def("Remove", (void (MAT_SequenceOfArc::*)(MAT_SequenceOfArc::Iterator &)) &MAT_SequenceOfArc::Remove, "Remove one item", py::arg("thePosition"));
	cls_MAT_SequenceOfArc.def("Remove", (void (MAT_SequenceOfArc::*)(const Standard_Integer)) &MAT_SequenceOfArc::Remove, "Remove one item", py::arg("theIndex"));
	cls_MAT_SequenceOfArc.def("Remove", (void (MAT_SequenceOfArc::*)(const Standard_Integer, const Standard_Integer)) &MAT_SequenceOfArc::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_MAT_SequenceOfArc.def("Append", (void (MAT_SequenceOfArc::*)(const opencascade::handle<MAT_Arc> &)) &MAT_SequenceOfArc::Append, "Append one item", py::arg("theItem"));
	cls_MAT_SequenceOfArc.def("Append", (void (MAT_SequenceOfArc::*)(MAT_SequenceOfArc &)) &MAT_SequenceOfArc::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_MAT_SequenceOfArc.def("Prepend", (void (MAT_SequenceOfArc::*)(const opencascade::handle<MAT_Arc> &)) &MAT_SequenceOfArc::Prepend, "Prepend one item", py::arg("theItem"));
	cls_MAT_SequenceOfArc.def("Prepend", (void (MAT_SequenceOfArc::*)(MAT_SequenceOfArc &)) &MAT_SequenceOfArc::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_MAT_SequenceOfArc.def("InsertBefore", (void (MAT_SequenceOfArc::*)(const Standard_Integer, const opencascade::handle<MAT_Arc> &)) &MAT_SequenceOfArc::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT_SequenceOfArc.def("InsertBefore", (void (MAT_SequenceOfArc::*)(const Standard_Integer, MAT_SequenceOfArc &)) &MAT_SequenceOfArc::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT_SequenceOfArc.def("InsertAfter", (void (MAT_SequenceOfArc::*)(MAT_SequenceOfArc::Iterator &, const opencascade::handle<MAT_Arc> &)) &MAT_SequenceOfArc::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_MAT_SequenceOfArc.def("InsertAfter", (void (MAT_SequenceOfArc::*)(const Standard_Integer, MAT_SequenceOfArc &)) &MAT_SequenceOfArc::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT_SequenceOfArc.def("InsertAfter", (void (MAT_SequenceOfArc::*)(const Standard_Integer, const opencascade::handle<MAT_Arc> &)) &MAT_SequenceOfArc::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT_SequenceOfArc.def("Split", (void (MAT_SequenceOfArc::*)(const Standard_Integer, MAT_SequenceOfArc &)) &MAT_SequenceOfArc::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT_SequenceOfArc.def("First", (const opencascade::handle<MAT_Arc> & (MAT_SequenceOfArc::*)() const ) &MAT_SequenceOfArc::First, "First item access");
	cls_MAT_SequenceOfArc.def("ChangeFirst", (opencascade::handle<MAT_Arc> & (MAT_SequenceOfArc::*)()) &MAT_SequenceOfArc::ChangeFirst, "First item access");
	cls_MAT_SequenceOfArc.def("Last", (const opencascade::handle<MAT_Arc> & (MAT_SequenceOfArc::*)() const ) &MAT_SequenceOfArc::Last, "Last item access");
	cls_MAT_SequenceOfArc.def("ChangeLast", (opencascade::handle<MAT_Arc> & (MAT_SequenceOfArc::*)()) &MAT_SequenceOfArc::ChangeLast, "Last item access");
	cls_MAT_SequenceOfArc.def("Value", (const opencascade::handle<MAT_Arc> & (MAT_SequenceOfArc::*)(const Standard_Integer) const ) &MAT_SequenceOfArc::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_MAT_SequenceOfArc.def("__call__", (const opencascade::handle<MAT_Arc> & (MAT_SequenceOfArc::*)(const Standard_Integer) const ) &MAT_SequenceOfArc::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_MAT_SequenceOfArc.def("ChangeValue", (opencascade::handle<MAT_Arc> & (MAT_SequenceOfArc::*)(const Standard_Integer)) &MAT_SequenceOfArc::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_MAT_SequenceOfArc.def("__call__", (opencascade::handle<MAT_Arc> & (MAT_SequenceOfArc::*)(const Standard_Integer)) &MAT_SequenceOfArc::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_MAT_SequenceOfArc.def("SetValue", (void (MAT_SequenceOfArc::*)(const Standard_Integer, const opencascade::handle<MAT_Arc> &)) &MAT_SequenceOfArc::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT_SequenceOfArc.def("__iter__", [](const MAT_SequenceOfArc &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<MAT_SequenceOfBasicElt, std::unique_ptr<MAT_SequenceOfBasicElt, Deleter<MAT_SequenceOfBasicElt>>, NCollection_BaseSequence> cls_MAT_SequenceOfBasicElt(mod, "MAT_SequenceOfBasicElt", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_MAT_SequenceOfBasicElt.def(py::init<>());
	cls_MAT_SequenceOfBasicElt.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_MAT_SequenceOfBasicElt.def(py::init([] (const MAT_SequenceOfBasicElt &other) {return new MAT_SequenceOfBasicElt(other);}), "Copy constructor", py::arg("other"));
	cls_MAT_SequenceOfBasicElt.def("begin", (MAT_SequenceOfBasicElt::iterator (MAT_SequenceOfBasicElt::*)() const ) &MAT_SequenceOfBasicElt::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_MAT_SequenceOfBasicElt.def("end", (MAT_SequenceOfBasicElt::iterator (MAT_SequenceOfBasicElt::*)() const ) &MAT_SequenceOfBasicElt::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_MAT_SequenceOfBasicElt.def("cbegin", (MAT_SequenceOfBasicElt::const_iterator (MAT_SequenceOfBasicElt::*)() const ) &MAT_SequenceOfBasicElt::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_MAT_SequenceOfBasicElt.def("cend", (MAT_SequenceOfBasicElt::const_iterator (MAT_SequenceOfBasicElt::*)() const ) &MAT_SequenceOfBasicElt::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_MAT_SequenceOfBasicElt.def("Size", (Standard_Integer (MAT_SequenceOfBasicElt::*)() const ) &MAT_SequenceOfBasicElt::Size, "Number of items");
	cls_MAT_SequenceOfBasicElt.def("Length", (Standard_Integer (MAT_SequenceOfBasicElt::*)() const ) &MAT_SequenceOfBasicElt::Length, "Number of items");
	cls_MAT_SequenceOfBasicElt.def("Lower", (Standard_Integer (MAT_SequenceOfBasicElt::*)() const ) &MAT_SequenceOfBasicElt::Lower, "Method for consistency with other collections.");
	cls_MAT_SequenceOfBasicElt.def("Upper", (Standard_Integer (MAT_SequenceOfBasicElt::*)() const ) &MAT_SequenceOfBasicElt::Upper, "Method for consistency with other collections.");
	cls_MAT_SequenceOfBasicElt.def("IsEmpty", (Standard_Boolean (MAT_SequenceOfBasicElt::*)() const ) &MAT_SequenceOfBasicElt::IsEmpty, "Empty query");
	cls_MAT_SequenceOfBasicElt.def("Reverse", (void (MAT_SequenceOfBasicElt::*)()) &MAT_SequenceOfBasicElt::Reverse, "Reverse sequence");
	cls_MAT_SequenceOfBasicElt.def("Exchange", (void (MAT_SequenceOfBasicElt::*)(const Standard_Integer, const Standard_Integer)) &MAT_SequenceOfBasicElt::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_MAT_SequenceOfBasicElt.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &MAT_SequenceOfBasicElt::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_MAT_SequenceOfBasicElt.def("Clear", [](MAT_SequenceOfBasicElt &self) -> void { return self.Clear(); });
	cls_MAT_SequenceOfBasicElt.def("Clear", (void (MAT_SequenceOfBasicElt::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT_SequenceOfBasicElt::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_MAT_SequenceOfBasicElt.def("Assign", (MAT_SequenceOfBasicElt & (MAT_SequenceOfBasicElt::*)(const MAT_SequenceOfBasicElt &)) &MAT_SequenceOfBasicElt::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT_SequenceOfBasicElt.def("assign", (MAT_SequenceOfBasicElt & (MAT_SequenceOfBasicElt::*)(const MAT_SequenceOfBasicElt &)) &MAT_SequenceOfBasicElt::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_MAT_SequenceOfBasicElt.def("Remove", (void (MAT_SequenceOfBasicElt::*)(MAT_SequenceOfBasicElt::Iterator &)) &MAT_SequenceOfBasicElt::Remove, "Remove one item", py::arg("thePosition"));
	cls_MAT_SequenceOfBasicElt.def("Remove", (void (MAT_SequenceOfBasicElt::*)(const Standard_Integer)) &MAT_SequenceOfBasicElt::Remove, "Remove one item", py::arg("theIndex"));
	cls_MAT_SequenceOfBasicElt.def("Remove", (void (MAT_SequenceOfBasicElt::*)(const Standard_Integer, const Standard_Integer)) &MAT_SequenceOfBasicElt::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_MAT_SequenceOfBasicElt.def("Append", (void (MAT_SequenceOfBasicElt::*)(const opencascade::handle<MAT_BasicElt> &)) &MAT_SequenceOfBasicElt::Append, "Append one item", py::arg("theItem"));
	cls_MAT_SequenceOfBasicElt.def("Append", (void (MAT_SequenceOfBasicElt::*)(MAT_SequenceOfBasicElt &)) &MAT_SequenceOfBasicElt::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_MAT_SequenceOfBasicElt.def("Prepend", (void (MAT_SequenceOfBasicElt::*)(const opencascade::handle<MAT_BasicElt> &)) &MAT_SequenceOfBasicElt::Prepend, "Prepend one item", py::arg("theItem"));
	cls_MAT_SequenceOfBasicElt.def("Prepend", (void (MAT_SequenceOfBasicElt::*)(MAT_SequenceOfBasicElt &)) &MAT_SequenceOfBasicElt::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_MAT_SequenceOfBasicElt.def("InsertBefore", (void (MAT_SequenceOfBasicElt::*)(const Standard_Integer, const opencascade::handle<MAT_BasicElt> &)) &MAT_SequenceOfBasicElt::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT_SequenceOfBasicElt.def("InsertBefore", (void (MAT_SequenceOfBasicElt::*)(const Standard_Integer, MAT_SequenceOfBasicElt &)) &MAT_SequenceOfBasicElt::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT_SequenceOfBasicElt.def("InsertAfter", (void (MAT_SequenceOfBasicElt::*)(MAT_SequenceOfBasicElt::Iterator &, const opencascade::handle<MAT_BasicElt> &)) &MAT_SequenceOfBasicElt::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_MAT_SequenceOfBasicElt.def("InsertAfter", (void (MAT_SequenceOfBasicElt::*)(const Standard_Integer, MAT_SequenceOfBasicElt &)) &MAT_SequenceOfBasicElt::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT_SequenceOfBasicElt.def("InsertAfter", (void (MAT_SequenceOfBasicElt::*)(const Standard_Integer, const opencascade::handle<MAT_BasicElt> &)) &MAT_SequenceOfBasicElt::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT_SequenceOfBasicElt.def("Split", (void (MAT_SequenceOfBasicElt::*)(const Standard_Integer, MAT_SequenceOfBasicElt &)) &MAT_SequenceOfBasicElt::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT_SequenceOfBasicElt.def("First", (const opencascade::handle<MAT_BasicElt> & (MAT_SequenceOfBasicElt::*)() const ) &MAT_SequenceOfBasicElt::First, "First item access");
	cls_MAT_SequenceOfBasicElt.def("ChangeFirst", (opencascade::handle<MAT_BasicElt> & (MAT_SequenceOfBasicElt::*)()) &MAT_SequenceOfBasicElt::ChangeFirst, "First item access");
	cls_MAT_SequenceOfBasicElt.def("Last", (const opencascade::handle<MAT_BasicElt> & (MAT_SequenceOfBasicElt::*)() const ) &MAT_SequenceOfBasicElt::Last, "Last item access");
	cls_MAT_SequenceOfBasicElt.def("ChangeLast", (opencascade::handle<MAT_BasicElt> & (MAT_SequenceOfBasicElt::*)()) &MAT_SequenceOfBasicElt::ChangeLast, "Last item access");
	cls_MAT_SequenceOfBasicElt.def("Value", (const opencascade::handle<MAT_BasicElt> & (MAT_SequenceOfBasicElt::*)(const Standard_Integer) const ) &MAT_SequenceOfBasicElt::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_MAT_SequenceOfBasicElt.def("__call__", (const opencascade::handle<MAT_BasicElt> & (MAT_SequenceOfBasicElt::*)(const Standard_Integer) const ) &MAT_SequenceOfBasicElt::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_MAT_SequenceOfBasicElt.def("ChangeValue", (opencascade::handle<MAT_BasicElt> & (MAT_SequenceOfBasicElt::*)(const Standard_Integer)) &MAT_SequenceOfBasicElt::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_MAT_SequenceOfBasicElt.def("__call__", (opencascade::handle<MAT_BasicElt> & (MAT_SequenceOfBasicElt::*)(const Standard_Integer)) &MAT_SequenceOfBasicElt::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_MAT_SequenceOfBasicElt.def("SetValue", (void (MAT_SequenceOfBasicElt::*)(const Standard_Integer, const opencascade::handle<MAT_BasicElt> &)) &MAT_SequenceOfBasicElt::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT_SequenceOfBasicElt.def("__iter__", [](const MAT_SequenceOfBasicElt &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MAT_DataMapOfIntegerBasicElt, std::unique_ptr<MAT_DataMapOfIntegerBasicElt, Deleter<MAT_DataMapOfIntegerBasicElt>>, NCollection_BaseMap> cls_MAT_DataMapOfIntegerBasicElt(mod, "MAT_DataMapOfIntegerBasicElt", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MAT_DataMapOfIntegerBasicElt.def(py::init<>());
	cls_MAT_DataMapOfIntegerBasicElt.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MAT_DataMapOfIntegerBasicElt.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MAT_DataMapOfIntegerBasicElt.def(py::init([] (const MAT_DataMapOfIntegerBasicElt &other) {return new MAT_DataMapOfIntegerBasicElt(other);}), "Copy constructor", py::arg("other"));
	cls_MAT_DataMapOfIntegerBasicElt.def("begin", (MAT_DataMapOfIntegerBasicElt::iterator (MAT_DataMapOfIntegerBasicElt::*)() const ) &MAT_DataMapOfIntegerBasicElt::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MAT_DataMapOfIntegerBasicElt.def("end", (MAT_DataMapOfIntegerBasicElt::iterator (MAT_DataMapOfIntegerBasicElt::*)() const ) &MAT_DataMapOfIntegerBasicElt::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MAT_DataMapOfIntegerBasicElt.def("cbegin", (MAT_DataMapOfIntegerBasicElt::const_iterator (MAT_DataMapOfIntegerBasicElt::*)() const ) &MAT_DataMapOfIntegerBasicElt::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MAT_DataMapOfIntegerBasicElt.def("cend", (MAT_DataMapOfIntegerBasicElt::const_iterator (MAT_DataMapOfIntegerBasicElt::*)() const ) &MAT_DataMapOfIntegerBasicElt::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MAT_DataMapOfIntegerBasicElt.def("Exchange", (void (MAT_DataMapOfIntegerBasicElt::*)(MAT_DataMapOfIntegerBasicElt &)) &MAT_DataMapOfIntegerBasicElt::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerBasicElt.def("Assign", (MAT_DataMapOfIntegerBasicElt & (MAT_DataMapOfIntegerBasicElt::*)(const MAT_DataMapOfIntegerBasicElt &)) &MAT_DataMapOfIntegerBasicElt::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerBasicElt.def("assign", (MAT_DataMapOfIntegerBasicElt & (MAT_DataMapOfIntegerBasicElt::*)(const MAT_DataMapOfIntegerBasicElt &)) &MAT_DataMapOfIntegerBasicElt::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerBasicElt.def("ReSize", (void (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer)) &MAT_DataMapOfIntegerBasicElt::ReSize, "ReSize", py::arg("N"));
	cls_MAT_DataMapOfIntegerBasicElt.def("Bind", (Standard_Boolean (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer &, const opencascade::handle<MAT_BasicElt> &)) &MAT_DataMapOfIntegerBasicElt::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MAT_DataMapOfIntegerBasicElt.def("Bound", (opencascade::handle<MAT_BasicElt> * (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer &, const opencascade::handle<MAT_BasicElt> &)) &MAT_DataMapOfIntegerBasicElt::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MAT_DataMapOfIntegerBasicElt.def("IsBound", (Standard_Boolean (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerBasicElt::IsBound, "IsBound", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerBasicElt.def("UnBind", (Standard_Boolean (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerBasicElt::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerBasicElt.def("Seek", (const opencascade::handle<MAT_BasicElt> * (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerBasicElt::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerBasicElt.def("Find", (const opencascade::handle<MAT_BasicElt> & (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerBasicElt::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerBasicElt.def("Find", (Standard_Boolean (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer &, opencascade::handle<MAT_BasicElt> &) const ) &MAT_DataMapOfIntegerBasicElt::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MAT_DataMapOfIntegerBasicElt.def("__call__", (const opencascade::handle<MAT_BasicElt> & (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerBasicElt::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerBasicElt.def("ChangeSeek", (opencascade::handle<MAT_BasicElt> * (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerBasicElt::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerBasicElt.def("ChangeFind", (opencascade::handle<MAT_BasicElt> & (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerBasicElt::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerBasicElt.def("__call__", (opencascade::handle<MAT_BasicElt> & (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerBasicElt::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerBasicElt.def("Clear", [](MAT_DataMapOfIntegerBasicElt &self) -> void { return self.Clear(); });
	cls_MAT_DataMapOfIntegerBasicElt.def("Clear", (void (MAT_DataMapOfIntegerBasicElt::*)(const Standard_Boolean)) &MAT_DataMapOfIntegerBasicElt::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MAT_DataMapOfIntegerBasicElt.def("Clear", (void (MAT_DataMapOfIntegerBasicElt::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT_DataMapOfIntegerBasicElt::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MAT_DataMapOfIntegerBasicElt.def("Size", (Standard_Integer (MAT_DataMapOfIntegerBasicElt::*)() const ) &MAT_DataMapOfIntegerBasicElt::Size, "Size");
	cls_MAT_DataMapOfIntegerBasicElt.def("__iter__", [](const MAT_DataMapOfIntegerBasicElt &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_DataMapOfIntegerBasicElt.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MAT_DataMapOfIntegerBisector, std::unique_ptr<MAT_DataMapOfIntegerBisector, Deleter<MAT_DataMapOfIntegerBisector>>, NCollection_BaseMap> cls_MAT_DataMapOfIntegerBisector(mod, "MAT_DataMapOfIntegerBisector", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MAT_DataMapOfIntegerBisector.def(py::init<>());
	cls_MAT_DataMapOfIntegerBisector.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MAT_DataMapOfIntegerBisector.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MAT_DataMapOfIntegerBisector.def(py::init([] (const MAT_DataMapOfIntegerBisector &other) {return new MAT_DataMapOfIntegerBisector(other);}), "Copy constructor", py::arg("other"));
	cls_MAT_DataMapOfIntegerBisector.def("begin", (MAT_DataMapOfIntegerBisector::iterator (MAT_DataMapOfIntegerBisector::*)() const ) &MAT_DataMapOfIntegerBisector::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MAT_DataMapOfIntegerBisector.def("end", (MAT_DataMapOfIntegerBisector::iterator (MAT_DataMapOfIntegerBisector::*)() const ) &MAT_DataMapOfIntegerBisector::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MAT_DataMapOfIntegerBisector.def("cbegin", (MAT_DataMapOfIntegerBisector::const_iterator (MAT_DataMapOfIntegerBisector::*)() const ) &MAT_DataMapOfIntegerBisector::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MAT_DataMapOfIntegerBisector.def("cend", (MAT_DataMapOfIntegerBisector::const_iterator (MAT_DataMapOfIntegerBisector::*)() const ) &MAT_DataMapOfIntegerBisector::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MAT_DataMapOfIntegerBisector.def("Exchange", (void (MAT_DataMapOfIntegerBisector::*)(MAT_DataMapOfIntegerBisector &)) &MAT_DataMapOfIntegerBisector::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerBisector.def("Assign", (MAT_DataMapOfIntegerBisector & (MAT_DataMapOfIntegerBisector::*)(const MAT_DataMapOfIntegerBisector &)) &MAT_DataMapOfIntegerBisector::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerBisector.def("assign", (MAT_DataMapOfIntegerBisector & (MAT_DataMapOfIntegerBisector::*)(const MAT_DataMapOfIntegerBisector &)) &MAT_DataMapOfIntegerBisector::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerBisector.def("ReSize", (void (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer)) &MAT_DataMapOfIntegerBisector::ReSize, "ReSize", py::arg("N"));
	cls_MAT_DataMapOfIntegerBisector.def("Bind", (Standard_Boolean (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer &, const opencascade::handle<MAT_Bisector> &)) &MAT_DataMapOfIntegerBisector::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MAT_DataMapOfIntegerBisector.def("Bound", (opencascade::handle<MAT_Bisector> * (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer &, const opencascade::handle<MAT_Bisector> &)) &MAT_DataMapOfIntegerBisector::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MAT_DataMapOfIntegerBisector.def("IsBound", (Standard_Boolean (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerBisector::IsBound, "IsBound", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerBisector.def("UnBind", (Standard_Boolean (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerBisector::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerBisector.def("Seek", (const opencascade::handle<MAT_Bisector> * (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerBisector::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerBisector.def("Find", (const opencascade::handle<MAT_Bisector> & (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerBisector::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerBisector.def("Find", (Standard_Boolean (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer &, opencascade::handle<MAT_Bisector> &) const ) &MAT_DataMapOfIntegerBisector::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MAT_DataMapOfIntegerBisector.def("__call__", (const opencascade::handle<MAT_Bisector> & (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerBisector::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerBisector.def("ChangeSeek", (opencascade::handle<MAT_Bisector> * (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerBisector::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerBisector.def("ChangeFind", (opencascade::handle<MAT_Bisector> & (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerBisector::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerBisector.def("__call__", (opencascade::handle<MAT_Bisector> & (MAT_DataMapOfIntegerBisector::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerBisector::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerBisector.def("Clear", [](MAT_DataMapOfIntegerBisector &self) -> void { return self.Clear(); });
	cls_MAT_DataMapOfIntegerBisector.def("Clear", (void (MAT_DataMapOfIntegerBisector::*)(const Standard_Boolean)) &MAT_DataMapOfIntegerBisector::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MAT_DataMapOfIntegerBisector.def("Clear", (void (MAT_DataMapOfIntegerBisector::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT_DataMapOfIntegerBisector::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MAT_DataMapOfIntegerBisector.def("Size", (Standard_Integer (MAT_DataMapOfIntegerBisector::*)() const ) &MAT_DataMapOfIntegerBisector::Size, "Size");
	cls_MAT_DataMapOfIntegerBisector.def("__iter__", [](const MAT_DataMapOfIntegerBisector &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_DataMapOfIntegerBisector.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MAT_DataMapOfIntegerArc, std::unique_ptr<MAT_DataMapOfIntegerArc, Deleter<MAT_DataMapOfIntegerArc>>, NCollection_BaseMap> cls_MAT_DataMapOfIntegerArc(mod, "MAT_DataMapOfIntegerArc", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MAT_DataMapOfIntegerArc.def(py::init<>());
	cls_MAT_DataMapOfIntegerArc.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MAT_DataMapOfIntegerArc.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MAT_DataMapOfIntegerArc.def(py::init([] (const MAT_DataMapOfIntegerArc &other) {return new MAT_DataMapOfIntegerArc(other);}), "Copy constructor", py::arg("other"));
	cls_MAT_DataMapOfIntegerArc.def("begin", (MAT_DataMapOfIntegerArc::iterator (MAT_DataMapOfIntegerArc::*)() const ) &MAT_DataMapOfIntegerArc::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MAT_DataMapOfIntegerArc.def("end", (MAT_DataMapOfIntegerArc::iterator (MAT_DataMapOfIntegerArc::*)() const ) &MAT_DataMapOfIntegerArc::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MAT_DataMapOfIntegerArc.def("cbegin", (MAT_DataMapOfIntegerArc::const_iterator (MAT_DataMapOfIntegerArc::*)() const ) &MAT_DataMapOfIntegerArc::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MAT_DataMapOfIntegerArc.def("cend", (MAT_DataMapOfIntegerArc::const_iterator (MAT_DataMapOfIntegerArc::*)() const ) &MAT_DataMapOfIntegerArc::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MAT_DataMapOfIntegerArc.def("Exchange", (void (MAT_DataMapOfIntegerArc::*)(MAT_DataMapOfIntegerArc &)) &MAT_DataMapOfIntegerArc::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerArc.def("Assign", (MAT_DataMapOfIntegerArc & (MAT_DataMapOfIntegerArc::*)(const MAT_DataMapOfIntegerArc &)) &MAT_DataMapOfIntegerArc::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerArc.def("assign", (MAT_DataMapOfIntegerArc & (MAT_DataMapOfIntegerArc::*)(const MAT_DataMapOfIntegerArc &)) &MAT_DataMapOfIntegerArc::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerArc.def("ReSize", (void (MAT_DataMapOfIntegerArc::*)(const Standard_Integer)) &MAT_DataMapOfIntegerArc::ReSize, "ReSize", py::arg("N"));
	cls_MAT_DataMapOfIntegerArc.def("Bind", (Standard_Boolean (MAT_DataMapOfIntegerArc::*)(const Standard_Integer &, const opencascade::handle<MAT_Arc> &)) &MAT_DataMapOfIntegerArc::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MAT_DataMapOfIntegerArc.def("Bound", (opencascade::handle<MAT_Arc> * (MAT_DataMapOfIntegerArc::*)(const Standard_Integer &, const opencascade::handle<MAT_Arc> &)) &MAT_DataMapOfIntegerArc::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MAT_DataMapOfIntegerArc.def("IsBound", (Standard_Boolean (MAT_DataMapOfIntegerArc::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerArc::IsBound, "IsBound", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerArc.def("UnBind", (Standard_Boolean (MAT_DataMapOfIntegerArc::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerArc::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerArc.def("Seek", (const opencascade::handle<MAT_Arc> * (MAT_DataMapOfIntegerArc::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerArc::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerArc.def("Find", (const opencascade::handle<MAT_Arc> & (MAT_DataMapOfIntegerArc::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerArc::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerArc.def("Find", (Standard_Boolean (MAT_DataMapOfIntegerArc::*)(const Standard_Integer &, opencascade::handle<MAT_Arc> &) const ) &MAT_DataMapOfIntegerArc::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MAT_DataMapOfIntegerArc.def("__call__", (const opencascade::handle<MAT_Arc> & (MAT_DataMapOfIntegerArc::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerArc::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerArc.def("ChangeSeek", (opencascade::handle<MAT_Arc> * (MAT_DataMapOfIntegerArc::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerArc::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerArc.def("ChangeFind", (opencascade::handle<MAT_Arc> & (MAT_DataMapOfIntegerArc::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerArc::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerArc.def("__call__", (opencascade::handle<MAT_Arc> & (MAT_DataMapOfIntegerArc::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerArc::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerArc.def("Clear", [](MAT_DataMapOfIntegerArc &self) -> void { return self.Clear(); });
	cls_MAT_DataMapOfIntegerArc.def("Clear", (void (MAT_DataMapOfIntegerArc::*)(const Standard_Boolean)) &MAT_DataMapOfIntegerArc::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MAT_DataMapOfIntegerArc.def("Clear", (void (MAT_DataMapOfIntegerArc::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT_DataMapOfIntegerArc::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MAT_DataMapOfIntegerArc.def("Size", (Standard_Integer (MAT_DataMapOfIntegerArc::*)() const ) &MAT_DataMapOfIntegerArc::Size, "Size");
	cls_MAT_DataMapOfIntegerArc.def("__iter__", [](const MAT_DataMapOfIntegerArc &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_DataMapOfIntegerArc.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MAT_DataMapOfIntegerNode, std::unique_ptr<MAT_DataMapOfIntegerNode, Deleter<MAT_DataMapOfIntegerNode>>, NCollection_BaseMap> cls_MAT_DataMapOfIntegerNode(mod, "MAT_DataMapOfIntegerNode", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MAT_DataMapOfIntegerNode.def(py::init<>());
	cls_MAT_DataMapOfIntegerNode.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MAT_DataMapOfIntegerNode.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MAT_DataMapOfIntegerNode.def(py::init([] (const MAT_DataMapOfIntegerNode &other) {return new MAT_DataMapOfIntegerNode(other);}), "Copy constructor", py::arg("other"));
	cls_MAT_DataMapOfIntegerNode.def("begin", (MAT_DataMapOfIntegerNode::iterator (MAT_DataMapOfIntegerNode::*)() const ) &MAT_DataMapOfIntegerNode::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MAT_DataMapOfIntegerNode.def("end", (MAT_DataMapOfIntegerNode::iterator (MAT_DataMapOfIntegerNode::*)() const ) &MAT_DataMapOfIntegerNode::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MAT_DataMapOfIntegerNode.def("cbegin", (MAT_DataMapOfIntegerNode::const_iterator (MAT_DataMapOfIntegerNode::*)() const ) &MAT_DataMapOfIntegerNode::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MAT_DataMapOfIntegerNode.def("cend", (MAT_DataMapOfIntegerNode::const_iterator (MAT_DataMapOfIntegerNode::*)() const ) &MAT_DataMapOfIntegerNode::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MAT_DataMapOfIntegerNode.def("Exchange", (void (MAT_DataMapOfIntegerNode::*)(MAT_DataMapOfIntegerNode &)) &MAT_DataMapOfIntegerNode::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerNode.def("Assign", (MAT_DataMapOfIntegerNode & (MAT_DataMapOfIntegerNode::*)(const MAT_DataMapOfIntegerNode &)) &MAT_DataMapOfIntegerNode::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerNode.def("assign", (MAT_DataMapOfIntegerNode & (MAT_DataMapOfIntegerNode::*)(const MAT_DataMapOfIntegerNode &)) &MAT_DataMapOfIntegerNode::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT_DataMapOfIntegerNode.def("ReSize", (void (MAT_DataMapOfIntegerNode::*)(const Standard_Integer)) &MAT_DataMapOfIntegerNode::ReSize, "ReSize", py::arg("N"));
	cls_MAT_DataMapOfIntegerNode.def("Bind", (Standard_Boolean (MAT_DataMapOfIntegerNode::*)(const Standard_Integer &, const opencascade::handle<MAT_Node> &)) &MAT_DataMapOfIntegerNode::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MAT_DataMapOfIntegerNode.def("Bound", (opencascade::handle<MAT_Node> * (MAT_DataMapOfIntegerNode::*)(const Standard_Integer &, const opencascade::handle<MAT_Node> &)) &MAT_DataMapOfIntegerNode::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MAT_DataMapOfIntegerNode.def("IsBound", (Standard_Boolean (MAT_DataMapOfIntegerNode::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerNode::IsBound, "IsBound", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerNode.def("UnBind", (Standard_Boolean (MAT_DataMapOfIntegerNode::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerNode::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerNode.def("Seek", (const opencascade::handle<MAT_Node> * (MAT_DataMapOfIntegerNode::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerNode::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerNode.def("Find", (const opencascade::handle<MAT_Node> & (MAT_DataMapOfIntegerNode::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerNode::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerNode.def("Find", (Standard_Boolean (MAT_DataMapOfIntegerNode::*)(const Standard_Integer &, opencascade::handle<MAT_Node> &) const ) &MAT_DataMapOfIntegerNode::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MAT_DataMapOfIntegerNode.def("__call__", (const opencascade::handle<MAT_Node> & (MAT_DataMapOfIntegerNode::*)(const Standard_Integer &) const ) &MAT_DataMapOfIntegerNode::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MAT_DataMapOfIntegerNode.def("ChangeSeek", (opencascade::handle<MAT_Node> * (MAT_DataMapOfIntegerNode::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerNode::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerNode.def("ChangeFind", (opencascade::handle<MAT_Node> & (MAT_DataMapOfIntegerNode::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerNode::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerNode.def("__call__", (opencascade::handle<MAT_Node> & (MAT_DataMapOfIntegerNode::*)(const Standard_Integer &)) &MAT_DataMapOfIntegerNode::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MAT_DataMapOfIntegerNode.def("Clear", [](MAT_DataMapOfIntegerNode &self) -> void { return self.Clear(); });
	cls_MAT_DataMapOfIntegerNode.def("Clear", (void (MAT_DataMapOfIntegerNode::*)(const Standard_Boolean)) &MAT_DataMapOfIntegerNode::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MAT_DataMapOfIntegerNode.def("Clear", (void (MAT_DataMapOfIntegerNode::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT_DataMapOfIntegerNode::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MAT_DataMapOfIntegerNode.def("Size", (Standard_Integer (MAT_DataMapOfIntegerNode::*)() const ) &MAT_DataMapOfIntegerNode::Size, "Size");
	cls_MAT_DataMapOfIntegerNode.def("__iter__", [](const MAT_DataMapOfIntegerNode &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT_DataMapOfIntegerNode.hxx

}
