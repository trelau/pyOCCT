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

#include <Precision.hxx>

#include <BRepMesh_DegreeOfFreedom.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_OrientedEdge.hxx>
#include <BRepMesh_Vertex.hxx>
#include <BRepMesh_Edge.hxx>
#include <BRepMesh_Triangle.hxx>
#include <Standard_Handle.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <BRepMesh_PairOfPolygon.hxx>
#include <BRepMesh_PairOfIndex.hxx>
#include <gp_XY.hxx>
#include <BRepMesh_Circle.hxx>
#include <Standard_Transient.hxx>
#include <BRepMesh.hxx>
#include <TopoDS_Face.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <BRepMesh_Status.hxx>
#include <BRepMesh_DataStructureOfDelaun.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Type.hxx>
#include <BRepMesh_FaceAttribute.hxx>
#include <NCollection_CellFilter.hxx>
#include <NCollection_IncAllocator.hxx>
#include <BRepMesh_VertexInspector.hxx>
#include <BRepMesh_CircleInspector.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <NCollection_Sequence.hxx>
#include <BRepMesh_Classifier.hxx>
#include <Standard_OStream.hxx>
#include <BRepMesh_VertexTool.hxx>
#include <gp_Circ2d.hxx>
#include <BRepMesh_CircleTool.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <GeomAbs_IsoType.hxx>
#include <gp_Dir.hxx>
#include <BRepMesh_GeomTool.hxx>
#include <BRepMesh_Delaun.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepMesh_DiscretRoot.hxx>
#include <BRepMesh_PluginEntryType.hxx>
#include <BRepMesh_FactoryError.hxx>
#include <BRepMesh_DiscretFactory.hxx>
#include <TColStd_MapOfAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopoDS_Edge.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <BRepMesh_EdgeParameterProvider.hxx>
#include <BRepMesh_IEdgeTool.hxx>
#include <Geom2dAdaptor_HCurve.hxx>
#include <Poly_Triangulation.hxx>
#include <TopLoc_Location.hxx>
#include <BRepMesh_EdgeTessellationExtractor.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <BRepMesh_EdgeTessellator.hxx>
#include <Bnd_Box.hxx>
#include <BRepMesh_ShapeTool.hxx>
#include <BRepMesh_FastDiscret.hxx>
#include <BRepMesh_FastDiscretFace.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepMesh_SelectorOfDataStructureOfDelaun.hxx>
#include <BRepMesh_WireChecker.hxx>
#include <Standard_Mutex.hxx>
#include <BRepMesh_WireInterferenceChecker.hxx>

PYBIND11_MODULE(BRepMesh, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Poly");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.BRepAdaptor");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Geom2dAdaptor");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Bnd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_DegreeOfFreedom.hxx
	py::enum_<BRepMesh_DegreeOfFreedom>(mod, "BRepMesh_DegreeOfFreedom", "None")
		.value("BRepMesh_Free", BRepMesh_DegreeOfFreedom::BRepMesh_Free)
		.value("BRepMesh_InVolume", BRepMesh_DegreeOfFreedom::BRepMesh_InVolume)
		.value("BRepMesh_OnSurface", BRepMesh_DegreeOfFreedom::BRepMesh_OnSurface)
		.value("BRepMesh_OnCurve", BRepMesh_DegreeOfFreedom::BRepMesh_OnCurve)
		.value("BRepMesh_Fixed", BRepMesh_DegreeOfFreedom::BRepMesh_Fixed)
		.value("BRepMesh_Frontier", BRepMesh_DegreeOfFreedom::BRepMesh_Frontier)
		.value("BRepMesh_Deleted", BRepMesh_DegreeOfFreedom::BRepMesh_Deleted)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_FactoryError.hxx
	py::enum_<BRepMesh_FactoryError>(mod, "BRepMesh_FactoryError", "None")
		.value("BRepMesh_FE_NOERROR", BRepMesh_FactoryError::BRepMesh_FE_NOERROR)
		.value("BRepMesh_FE_LIBRARYNOTFOUND", BRepMesh_FactoryError::BRepMesh_FE_LIBRARYNOTFOUND)
		.value("BRepMesh_FE_FUNCTIONNOTFOUND", BRepMesh_FactoryError::BRepMesh_FE_FUNCTIONNOTFOUND)
		.value("BRepMesh_FE_CANNOTCREATEALGO", BRepMesh_FactoryError::BRepMesh_FE_CANNOTCREATEALGO)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_Status.hxx
	py::enum_<BRepMesh_Status>(mod, "BRepMesh_Status", "Discribes the wires discretisation.")
		.value("BRepMesh_NoError", BRepMesh_Status::BRepMesh_NoError)
		.value("BRepMesh_OpenWire", BRepMesh_Status::BRepMesh_OpenWire)
		.value("BRepMesh_SelfIntersectingWire", BRepMesh_Status::BRepMesh_SelfIntersectingWire)
		.value("BRepMesh_Failure", BRepMesh_Status::BRepMesh_Failure)
		.value("BRepMesh_ReMesh", BRepMesh_Status::BRepMesh_ReMesh)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_Vertex.hxx
	mod.def("HashCode", (Standard_Integer (*)(const BRepMesh_Vertex &, const Standard_Integer)) &HashCode, "None", py::arg("me"), py::arg("Upper"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_OrientedEdge.hxx
	py::class_<BRepMesh_OrientedEdge, std::unique_ptr<BRepMesh_OrientedEdge, Deleter<BRepMesh_OrientedEdge>>> cls_BRepMesh_OrientedEdge(mod, "BRepMesh_OrientedEdge", "Light weighted structure representing simple link.");
	cls_BRepMesh_OrientedEdge.def(py::init<>());
	cls_BRepMesh_OrientedEdge.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theFirstNode"), py::arg("theLastNode"));
	cls_BRepMesh_OrientedEdge.def("FirstNode", (Standard_Integer (BRepMesh_OrientedEdge::*)() const ) &BRepMesh_OrientedEdge::FirstNode, "Returns index of first node of the Link.");
	cls_BRepMesh_OrientedEdge.def("LastNode", (Standard_Integer (BRepMesh_OrientedEdge::*)() const ) &BRepMesh_OrientedEdge::LastNode, "Returns index of last node of the Link.");
	cls_BRepMesh_OrientedEdge.def("HashCode", (Standard_Integer (BRepMesh_OrientedEdge::*)(const Standard_Integer) const ) &BRepMesh_OrientedEdge::HashCode, "Returns hash code for this edge.", py::arg("theUpper"));
	cls_BRepMesh_OrientedEdge.def("IsEqual", (Standard_Boolean (BRepMesh_OrientedEdge::*)(const BRepMesh_OrientedEdge &) const ) &BRepMesh_OrientedEdge::IsEqual, "Checks this and other edge for equality.", py::arg("theOther"));
	cls_BRepMesh_OrientedEdge.def("__eq__", (Standard_Boolean (BRepMesh_OrientedEdge::*)(const BRepMesh_OrientedEdge &) const ) &BRepMesh_OrientedEdge::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("Other"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_Edge.hxx
	py::class_<BRepMesh_Edge, std::unique_ptr<BRepMesh_Edge, Deleter<BRepMesh_Edge>>, BRepMesh_OrientedEdge> cls_BRepMesh_Edge(mod, "BRepMesh_Edge", "Light weighted structure representing link of the mesh.");
	cls_BRepMesh_Edge.def(py::init<>());
	cls_BRepMesh_Edge.def(py::init<const Standard_Integer, const Standard_Integer, const BRepMesh_DegreeOfFreedom>(), py::arg("theFirstNode"), py::arg("theLastNode"), py::arg("theMovability"));
	cls_BRepMesh_Edge.def("Movability", (BRepMesh_DegreeOfFreedom (BRepMesh_Edge::*)() const ) &BRepMesh_Edge::Movability, "Returns movability flag of the Link.");
	cls_BRepMesh_Edge.def("SetMovability", (void (BRepMesh_Edge::*)(const BRepMesh_DegreeOfFreedom)) &BRepMesh_Edge::SetMovability, "Sets movability flag of the Link.", py::arg("theMovability"));
	cls_BRepMesh_Edge.def("IsSameOrientation", (Standard_Boolean (BRepMesh_Edge::*)(const BRepMesh_Edge &) const ) &BRepMesh_Edge::IsSameOrientation, "Checks if the given edge and this one have the same orientation.", py::arg("theOther"));
	cls_BRepMesh_Edge.def("IsEqual", (Standard_Boolean (BRepMesh_Edge::*)(const BRepMesh_Edge &) const ) &BRepMesh_Edge::IsEqual, "Checks for equality with another edge.", py::arg("theOther"));
	cls_BRepMesh_Edge.def("__eq__", (Standard_Boolean (BRepMesh_Edge::*)(const BRepMesh_Edge &) const ) &BRepMesh_Edge::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("Other"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_Triangle.hxx
	py::class_<BRepMesh_Triangle, std::unique_ptr<BRepMesh_Triangle, Deleter<BRepMesh_Triangle>>> cls_BRepMesh_Triangle(mod, "BRepMesh_Triangle", "Light weighted structure representing triangle of mesh consisting of oriented links.");
	cls_BRepMesh_Triangle.def(py::init<>());
	// FIXME cls_BRepMesh_Triangle.def(py::init<const Standard_Integer (&)[3], const Standard_Boolean (&)[3], const BRepMesh_DegreeOfFreedom>(), py::arg("theEdges"), py::arg("theOrientations"), py::arg("theMovability"));
	// FIXME cls_BRepMesh_Triangle.def("Initialize", (void (BRepMesh_Triangle::*)(const Standard_Integer (&)[3], const Standard_Boolean (&)[3], const BRepMesh_DegreeOfFreedom)) &BRepMesh_Triangle::Initialize, "Initializes the triangle by the given parameters.", py::arg("theEdges"), py::arg("theOrientations"), py::arg("theMovability"));
	// FIXME cls_BRepMesh_Triangle.def("Edges", (void (BRepMesh_Triangle::*)(Standard_Integer (&)[3], Standard_Boolean (&)[3]) const ) &BRepMesh_Triangle::Edges, "Gets edges with orientations composing the triangle.", py::arg("theEdges"), py::arg("theOrientations"));
	cls_BRepMesh_Triangle.def("Movability", (BRepMesh_DegreeOfFreedom (BRepMesh_Triangle::*)() const ) &BRepMesh_Triangle::Movability, "Returns movability of the triangle.");
	cls_BRepMesh_Triangle.def("SetMovability", (void (BRepMesh_Triangle::*)(const BRepMesh_DegreeOfFreedom)) &BRepMesh_Triangle::SetMovability, "Sets movability of the triangle.", py::arg("theMovability"));
	cls_BRepMesh_Triangle.def("HashCode", (Standard_Integer (BRepMesh_Triangle::*)(const Standard_Integer) const ) &BRepMesh_Triangle::HashCode, "Returns hash code for this triangle.", py::arg("theUpper"));
	cls_BRepMesh_Triangle.def("IsEqual", (Standard_Boolean (BRepMesh_Triangle::*)(const BRepMesh_Triangle &) const ) &BRepMesh_Triangle::IsEqual, "Checks for equality with another triangle.", py::arg("theOther"));
	cls_BRepMesh_Triangle.def("__eq__", (Standard_Boolean (BRepMesh_Triangle::*)(const BRepMesh_Triangle &) const ) &BRepMesh_Triangle::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_PairOfPolygon.hxx
	py::class_<BRepMesh_PairOfPolygon, std::unique_ptr<BRepMesh_PairOfPolygon, Deleter<BRepMesh_PairOfPolygon>>> cls_BRepMesh_PairOfPolygon(mod, "BRepMesh_PairOfPolygon", "None");
	cls_BRepMesh_PairOfPolygon.def(py::init<>());
	cls_BRepMesh_PairOfPolygon.def("Clear", (void (BRepMesh_PairOfPolygon::*)()) &BRepMesh_PairOfPolygon::Clear, "Clears pair handles.");
	cls_BRepMesh_PairOfPolygon.def("Prepend", (void (BRepMesh_PairOfPolygon::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRepMesh_PairOfPolygon::Prepend, "Sets the first element of the pair. If last element is empty, also assignes the given polygon to it.", py::arg("thePolygon"));
	cls_BRepMesh_PairOfPolygon.def("Append", (void (BRepMesh_PairOfPolygon::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRepMesh_PairOfPolygon::Append, "Sets the last element of the pair. If first element is empty, also assignes the given polygon to it.", py::arg("thePolygon"));
	cls_BRepMesh_PairOfPolygon.def("First", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRepMesh_PairOfPolygon::*)() const ) &BRepMesh_PairOfPolygon::First, "Returns first polygon on triangulation.");
	cls_BRepMesh_PairOfPolygon.def("Last", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRepMesh_PairOfPolygon::*)() const ) &BRepMesh_PairOfPolygon::Last, "Returns last polygon on triangulation.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_PairOfIndex.hxx
	py::class_<BRepMesh_PairOfIndex, std::unique_ptr<BRepMesh_PairOfIndex, Deleter<BRepMesh_PairOfIndex>>> cls_BRepMesh_PairOfIndex(mod, "BRepMesh_PairOfIndex", "This class represents a pair of integer indices to store element indices connected to link. It is restricted to store more than two indices in it.");
	cls_BRepMesh_PairOfIndex.def(py::init<>());
	cls_BRepMesh_PairOfIndex.def("Clear", (void (BRepMesh_PairOfIndex::*)()) &BRepMesh_PairOfIndex::Clear, "Clears indices.");
	cls_BRepMesh_PairOfIndex.def("Append", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer)) &BRepMesh_PairOfIndex::Append, "Appends index to the pair.", py::arg("theIndex"));
	cls_BRepMesh_PairOfIndex.def("Prepend", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer)) &BRepMesh_PairOfIndex::Prepend, "Prepends index to the pair.", py::arg("theIndex"));
	cls_BRepMesh_PairOfIndex.def("IsEmpty", (Standard_Boolean (BRepMesh_PairOfIndex::*)() const ) &BRepMesh_PairOfIndex::IsEmpty, "Returns is pair is empty.");
	cls_BRepMesh_PairOfIndex.def("Extent", (Standard_Integer (BRepMesh_PairOfIndex::*)() const ) &BRepMesh_PairOfIndex::Extent, "Returns number of initialized indeces.");
	cls_BRepMesh_PairOfIndex.def("FirstIndex", (Standard_Integer (BRepMesh_PairOfIndex::*)() const ) &BRepMesh_PairOfIndex::FirstIndex, "Returns first index of pair.");
	cls_BRepMesh_PairOfIndex.def("LastIndex", (Standard_Integer (BRepMesh_PairOfIndex::*)() const ) &BRepMesh_PairOfIndex::LastIndex, "Returns last index of pair");
	cls_BRepMesh_PairOfIndex.def("Index", (Standard_Integer (BRepMesh_PairOfIndex::*)(const Standard_Integer) const ) &BRepMesh_PairOfIndex::Index, "Returns index corresponding to the given position in the pair.", py::arg("thePairPos"));
	cls_BRepMesh_PairOfIndex.def("SetIndex", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer, const Standard_Integer)) &BRepMesh_PairOfIndex::SetIndex, "Sets index corresponding to the given position in the pair.", py::arg("thePairPos"), py::arg("theIndex"));
	cls_BRepMesh_PairOfIndex.def("RemoveIndex", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer)) &BRepMesh_PairOfIndex::RemoveIndex, "Remove index from the given position.", py::arg("thePairPos"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_Circle.hxx
	py::class_<BRepMesh_Circle, std::unique_ptr<BRepMesh_Circle, Deleter<BRepMesh_Circle>>> cls_BRepMesh_Circle(mod, "BRepMesh_Circle", "Describes a 2d circle with a size of only 3 Standard_Real numbers instead of gp who needs 7 Standard_Real numbers.");
	cls_BRepMesh_Circle.def(py::init<>());
	cls_BRepMesh_Circle.def(py::init<const gp_XY &, const Standard_Real>(), py::arg("theLocation"), py::arg("theRadius"));
	cls_BRepMesh_Circle.def("SetLocation", (void (BRepMesh_Circle::*)(const gp_XY &)) &BRepMesh_Circle::SetLocation, "Sets location of a circle.", py::arg("theLocation"));
	cls_BRepMesh_Circle.def("SetRadius", (void (BRepMesh_Circle::*)(const Standard_Real)) &BRepMesh_Circle::SetRadius, "Sets radius of a circle.", py::arg("theRadius"));
	cls_BRepMesh_Circle.def("Location", (const gp_XY & (BRepMesh_Circle::*)() const ) &BRepMesh_Circle::Location, "Returns location of a circle.");
	cls_BRepMesh_Circle.def("Radius", (const Standard_Real & (BRepMesh_Circle::*)() const ) &BRepMesh_Circle::Radius, "Returns radius of a circle.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_Vertex.hxx
	py::class_<BRepMesh_Vertex, std::unique_ptr<BRepMesh_Vertex, Deleter<BRepMesh_Vertex>>> cls_BRepMesh_Vertex(mod, "BRepMesh_Vertex", "Light weighted structure representing vertex of the mesh in parametric space. Vertex could be associated with 3d point stored in external map.");
	cls_BRepMesh_Vertex.def(py::init<>());
	cls_BRepMesh_Vertex.def(py::init<const gp_XY &, const Standard_Integer, const BRepMesh_DegreeOfFreedom>(), py::arg("theUV"), py::arg("theLocation3d"), py::arg("theMovability"));
	cls_BRepMesh_Vertex.def(py::init<const Standard_Real, const Standard_Real, const BRepMesh_DegreeOfFreedom>(), py::arg("theU"), py::arg("theV"), py::arg("theMovability"));
	cls_BRepMesh_Vertex.def("Initialize", (void (BRepMesh_Vertex::*)(const gp_XY &, const Standard_Integer, const BRepMesh_DegreeOfFreedom)) &BRepMesh_Vertex::Initialize, "Initializes vertex associated with point in 3d space.", py::arg("theUV"), py::arg("theLocation3d"), py::arg("theMovability"));
	cls_BRepMesh_Vertex.def("Coord", (const gp_XY & (BRepMesh_Vertex::*)() const ) &BRepMesh_Vertex::Coord, "Returns position of the vertex in parametric space.");
	cls_BRepMesh_Vertex.def("ChangeCoord", (gp_XY & (BRepMesh_Vertex::*)()) &BRepMesh_Vertex::ChangeCoord, "Returns position of the vertex in parametric space for modification.");
	cls_BRepMesh_Vertex.def("Location3d", (Standard_Integer (BRepMesh_Vertex::*)() const ) &BRepMesh_Vertex::Location3d, "Returns index of 3d point associated with the vertex.");
	cls_BRepMesh_Vertex.def("Movability", (BRepMesh_DegreeOfFreedom (BRepMesh_Vertex::*)() const ) &BRepMesh_Vertex::Movability, "Returns movability of the vertex.");
	cls_BRepMesh_Vertex.def("SetMovability", (void (BRepMesh_Vertex::*)(const BRepMesh_DegreeOfFreedom)) &BRepMesh_Vertex::SetMovability, "Sets movability of the vertex.", py::arg("theMovability"));
	cls_BRepMesh_Vertex.def("HashCode", (Standard_Integer (BRepMesh_Vertex::*)(const Standard_Integer) const ) &BRepMesh_Vertex::HashCode, "Returns hash code for this vertex.", py::arg("Upper"));
	cls_BRepMesh_Vertex.def("IsEqual", (Standard_Boolean (BRepMesh_Vertex::*)(const BRepMesh_Vertex &) const ) &BRepMesh_Vertex::IsEqual, "Checks for equality with another vertex.", py::arg("theOther"));
	cls_BRepMesh_Vertex.def("__eq__", (Standard_Boolean (BRepMesh_Vertex::*)(const BRepMesh_Vertex &) const ) &BRepMesh_Vertex::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("Other"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_FaceAttribute.hxx
	py::class_<BRepMesh_FaceAttribute, opencascade::handle<BRepMesh_FaceAttribute>, Standard_Transient> cls_BRepMesh_FaceAttribute(mod, "BRepMesh_FaceAttribute", "Auxiliary class for FastDiscret and FastDiscretFace classes.");
	cls_BRepMesh_FaceAttribute.def(py::init<const BRepMesh::HDMapOfVertexInteger &, const BRepMesh::HDMapOfIntegerPnt &>(), py::arg("theBoundaryVertices"), py::arg("theBoundaryPoints"));
	cls_BRepMesh_FaceAttribute.def(py::init<const TopoDS_Face &, const BRepMesh::HDMapOfVertexInteger &, const BRepMesh::HDMapOfIntegerPnt &, const Standard_Boolean>(), py::arg("theFace"), py::arg("theBoundaryVertices"), py::arg("theBoundaryPoints"), py::arg("theAdaptiveMin"));
	cls_BRepMesh_FaceAttribute.def("Surface", (const opencascade::handle<BRepAdaptor_HSurface> & (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::Surface, "Returns face's surface.");
	cls_BRepMesh_FaceAttribute.def("IsInitialized", (Standard_Boolean (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::IsInitialized, "Returns True in case if this attribute has already been intialized.");
	cls_BRepMesh_FaceAttribute.def("SetFace", (void (BRepMesh_FaceAttribute::*)(const TopoDS_Face &, const Standard_Boolean)) &BRepMesh_FaceAttribute::SetFace, "Initializes this attribute by the given face.", py::arg("theFace"), py::arg("theAdaptiveMin"));
	cls_BRepMesh_FaceAttribute.def("Face", (const TopoDS_Face & (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::Face, "Returns forward oriented face to be used for calculations.");
	cls_BRepMesh_FaceAttribute.def("SetBoundaryVertices", (void (BRepMesh_FaceAttribute::*)(const BRepMesh::HDMapOfVertexInteger &)) &BRepMesh_FaceAttribute::SetBoundaryVertices, "Sets boundary vertices map.", py::arg("theVertices"));
	cls_BRepMesh_FaceAttribute.def("SetBoundaryPoints", (void (BRepMesh_FaceAttribute::*)(const BRepMesh::HDMapOfIntegerPnt &)) &BRepMesh_FaceAttribute::SetBoundaryPoints, "Sets boundary points map.", py::arg("theBoundaryPoints"));
	cls_BRepMesh_FaceAttribute.def("ToleranceU", (Standard_Real (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::ToleranceU, "Returns U tolerance of face calculated regarding its parameters.");
	cls_BRepMesh_FaceAttribute.def("ToleranceV", (Standard_Real (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::ToleranceV, "Returns V tolerance of face calculated regarding its parameters.");
	cls_BRepMesh_FaceAttribute.def("GetDefFace", (Standard_Real (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::GetDefFace, "Gives face deflection parameter.");
	cls_BRepMesh_FaceAttribute.def("SetDefFace", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetDefFace, "Sets face deflection.", py::arg("theDefFace"));
	cls_BRepMesh_FaceAttribute.def("GetUMin", (Standard_Real (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::GetUMin, "Gives minimal value in U domain.");
	cls_BRepMesh_FaceAttribute.def("SetUMin", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetUMin, "Sets minimal value in U domain.", py::arg("theUMin"));
	cls_BRepMesh_FaceAttribute.def("GetVMin", (Standard_Real (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::GetVMin, "Gives minimal value in V domain.");
	cls_BRepMesh_FaceAttribute.def("SetVMin", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetVMin, "Sets minimal value in V domain.", py::arg("theVMin"));
	cls_BRepMesh_FaceAttribute.def("GetUMax", (Standard_Real (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::GetUMax, "Gives maximal value in U domain.");
	cls_BRepMesh_FaceAttribute.def("SetUMax", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetUMax, "Sets maximal value in U domain.", py::arg("theUMax"));
	cls_BRepMesh_FaceAttribute.def("GetVMax", (Standard_Real (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::GetVMax, "Gives maximal value in V domain.");
	cls_BRepMesh_FaceAttribute.def("SetVMax", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetVMax, "Sets maximal value in V domain.", py::arg("theVMax"));
	cls_BRepMesh_FaceAttribute.def("GetDeltaX", (Standard_Real (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::GetDeltaX, "Gives value of step in U domain.");
	cls_BRepMesh_FaceAttribute.def("SetDeltaX", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetDeltaX, "Sets value of step in U domain.", py::arg("theDeltaX"));
	cls_BRepMesh_FaceAttribute.def("GetDeltaY", (Standard_Real (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::GetDeltaY, "Gives value of step in V domain.");
	cls_BRepMesh_FaceAttribute.def("SetDeltaY", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetDeltaY, "Sets value of step in V domain.", py::arg("theDeltaY"));
	cls_BRepMesh_FaceAttribute.def("GetStatus", (Standard_Integer (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::GetStatus, "Sets set of status flags for this face.");
	cls_BRepMesh_FaceAttribute.def("SetStatus", (void (BRepMesh_FaceAttribute::*)(const BRepMesh_Status)) &BRepMesh_FaceAttribute::SetStatus, "Sets status flag for this face.", py::arg("theStatus"));
	cls_BRepMesh_FaceAttribute.def("IsValid", (Standard_Boolean (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::IsValid, "Returns TRUE in case if computed data is valid.");
	cls_BRepMesh_FaceAttribute.def("Clear", (void (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::Clear, "Clear face attribute.");
	cls_BRepMesh_FaceAttribute.def("ChangeInternalEdges", (BRepMesh::HDMapOfShapePairOfPolygon & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeInternalEdges, "Gives reference to map of internal edges of face.");
	cls_BRepMesh_FaceAttribute.def("ChangeLocation2D", (BRepMesh::HDMapOfIntegerListOfXY & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeLocation2D, "Gives reference to map of 2D points of discretization.");
	cls_BRepMesh_FaceAttribute.def("ChangeSurfacePoints", (BRepMesh::HDMapOfIntegerPnt & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeSurfacePoints, "Gives reference to map of 3D points of discretization.");
	cls_BRepMesh_FaceAttribute.def("ChangeSurfaceVertices", (BRepMesh::HDMapOfVertexInteger & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeSurfaceVertices, "Gives reference to map of vertices of discretization.");
	cls_BRepMesh_FaceAttribute.def("ChangeVertexEdgeMap", (BRepMesh::HIMapOfInteger & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeVertexEdgeMap, "Gives reference on map of (vertex, edge) pairs of face.");
	cls_BRepMesh_FaceAttribute.def("ChangeStructure", (opencascade::handle<BRepMesh_DataStructureOfDelaun> & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeStructure, "Gives Delaunay data structure.");
	cls_BRepMesh_FaceAttribute.def("ChangeClassifier", (BRepMesh::HClassifier & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeClassifier, "Returns classifier.");
	cls_BRepMesh_FaceAttribute.def("ChangeMeshNodes", (BRepMesh::HVectorOfVertex & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeMeshNodes, "Returns mesh nodes calculated for boundaries.");
	cls_BRepMesh_FaceAttribute.def("LastPointId", (Standard_Integer (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::LastPointId, "Gives the number of different locations in 3D space.");
	cls_BRepMesh_FaceAttribute.def("GetPoint", (const gp_Pnt & (BRepMesh_FaceAttribute::*)(const BRepMesh_Vertex &) const ) &BRepMesh_FaceAttribute::GetPoint, "Gives the 3D location of the vertex.", py::arg("theVertex"));
	cls_BRepMesh_FaceAttribute.def("GetPoint", (const gp_Pnt & (BRepMesh_FaceAttribute::*)(const Standard_Integer) const ) &BRepMesh_FaceAttribute::GetPoint, "Gives the 3D location of the vertex.", py::arg("theIndex"));
	cls_BRepMesh_FaceAttribute.def("AddNode", [](BRepMesh_FaceAttribute &self, const Standard_Integer theIndex, const gp_XY & theUV, const BRepMesh_DegreeOfFreedom theMovability, Standard_Integer & theNodeIndex, Standard_Integer & theNodeOnEdgeIndex){ self.AddNode(theIndex, theUV, theMovability, theNodeIndex, theNodeOnEdgeIndex); return std::tuple<Standard_Integer &, Standard_Integer &>(theNodeIndex, theNodeOnEdgeIndex); }, "Adds node with the given parameters to mesh.", py::arg("theIndex"), py::arg("theUV"), py::arg("theMovability"), py::arg("theNodeIndex"), py::arg("theNodeOnEdgeIndex"));
	cls_BRepMesh_FaceAttribute.def("Scale", (gp_XY (BRepMesh_FaceAttribute::*)(const gp_XY &, const Standard_Boolean)) &BRepMesh_FaceAttribute::Scale, "Scales the given point from real parametric space to face basis and otherwise.", py::arg("thePoint2d"), py::arg("isToFaceBasis"));
	cls_BRepMesh_FaceAttribute.def_static("get_type_name_", (const char * (*)()) &BRepMesh_FaceAttribute::get_type_name, "None");
	cls_BRepMesh_FaceAttribute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_FaceAttribute::get_type_descriptor, "None");
	cls_BRepMesh_FaceAttribute.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_FaceAttribute::*)() const ) &BRepMesh_FaceAttribute::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_VertexInspector.hxx
	py::class_<BRepMesh_VertexInspector, std::unique_ptr<BRepMesh_VertexInspector, Deleter<BRepMesh_VertexInspector>>, NCollection_CellFilter_InspectorXY> cls_BRepMesh_VertexInspector(mod, "BRepMesh_VertexInspector", "Class intended for fast searching of the coincidence points.");
	cls_BRepMesh_VertexInspector.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));
	cls_BRepMesh_VertexInspector.def("Add", (Standard_Integer (BRepMesh_VertexInspector::*)(const BRepMesh_Vertex &)) &BRepMesh_VertexInspector::Add, "Registers the given vertex.", py::arg("theVertex"));
	cls_BRepMesh_VertexInspector.def("SetTolerance", (void (BRepMesh_VertexInspector::*)(const Standard_Real)) &BRepMesh_VertexInspector::SetTolerance, "Sets the tolerance to be used for identification of coincident vertices equal for both dimensions.", py::arg("theTolerance"));
	cls_BRepMesh_VertexInspector.def("SetTolerance", (void (BRepMesh_VertexInspector::*)(const Standard_Real, const Standard_Real)) &BRepMesh_VertexInspector::SetTolerance, "Sets the tolerance to be used for identification of coincident vertices.", py::arg("theToleranceX"), py::arg("theToleranceY"));
	cls_BRepMesh_VertexInspector.def("Clear", (void (BRepMesh_VertexInspector::*)()) &BRepMesh_VertexInspector::Clear, "Clear inspector's internal data structures.");
	cls_BRepMesh_VertexInspector.def("Delete", (void (BRepMesh_VertexInspector::*)(const Standard_Integer)) &BRepMesh_VertexInspector::Delete, "Deletes vertex with the given index.", py::arg("theIndex"));
	cls_BRepMesh_VertexInspector.def("NbVertices", (Standard_Integer (BRepMesh_VertexInspector::*)() const ) &BRepMesh_VertexInspector::NbVertices, "Returns number of registered vertices.");
	cls_BRepMesh_VertexInspector.def("GetVertex", (BRepMesh_Vertex & (BRepMesh_VertexInspector::*)(Standard_Integer)) &BRepMesh_VertexInspector::GetVertex, "Returns vertex with the given index.", py::arg("theIndex"));
	cls_BRepMesh_VertexInspector.def("SetPoint", (void (BRepMesh_VertexInspector::*)(const gp_XY &)) &BRepMesh_VertexInspector::SetPoint, "Set reference point to be checked.", py::arg("thePoint"));
	cls_BRepMesh_VertexInspector.def("GetCoincidentPoint", (Standard_Integer (BRepMesh_VertexInspector::*)() const ) &BRepMesh_VertexInspector::GetCoincidentPoint, "Returns index of point coinciding with regerence one.");
	cls_BRepMesh_VertexInspector.def("GetListOfDelPoints", (const BRepMesh::ListOfInteger & (BRepMesh_VertexInspector::*)() const ) &BRepMesh_VertexInspector::GetListOfDelPoints, "Returns list with indexes of vertices that have movability attribute equal to BRepMesh_Deleted and can be replaced with another node.");
	cls_BRepMesh_VertexInspector.def("Vertices", (const BRepMesh::HVectorOfVertex & (BRepMesh_VertexInspector::*)() const ) &BRepMesh_VertexInspector::Vertices, "Returns set of mesh vertices.");
	cls_BRepMesh_VertexInspector.def("ChangeVertices", (BRepMesh::HVectorOfVertex & (BRepMesh_VertexInspector::*)()) &BRepMesh_VertexInspector::ChangeVertices, "Returns set of mesh vertices for modification.");
	cls_BRepMesh_VertexInspector.def("Inspect", (NCollection_CellFilter_Action (BRepMesh_VertexInspector::*)(const Standard_Integer)) &BRepMesh_VertexInspector::Inspect, "Performs inspection of a point with the given index.", py::arg("theTargetIndex"));
	cls_BRepMesh_VertexInspector.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_Integer, const Standard_Integer)) &BRepMesh_VertexInspector::IsEqual, "Checks indices for equlity.", py::arg("theIndex"), py::arg("theTargetIndex"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_CircleInspector.hxx
	py::class_<BRepMesh_CircleInspector, std::unique_ptr<BRepMesh_CircleInspector, Deleter<BRepMesh_CircleInspector>>, NCollection_CellFilter_InspectorXY> cls_BRepMesh_CircleInspector(mod, "BRepMesh_CircleInspector", "Auxilary class to find circles shot by the given point.");
	cls_BRepMesh_CircleInspector.def(py::init<const Standard_Real, const Standard_Integer, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theTolerance"), py::arg("theReservedSize"), py::arg("theAllocator"));
	cls_BRepMesh_CircleInspector.def("Bind", (void (BRepMesh_CircleInspector::*)(const Standard_Integer, const BRepMesh_Circle &)) &BRepMesh_CircleInspector::Bind, "Adds the circle to vector of circles at the given position.", py::arg("theIndex"), py::arg("theCircle"));
	cls_BRepMesh_CircleInspector.def("Circles", (const BRepMesh::VectorOfCircle & (BRepMesh_CircleInspector::*)() const ) &BRepMesh_CircleInspector::Circles, "Resutns vector of registered circles.");
	cls_BRepMesh_CircleInspector.def("Circle", (BRepMesh_Circle & (BRepMesh_CircleInspector::*)(const Standard_Integer)) &BRepMesh_CircleInspector::Circle, "Returns circle with the given index.", py::arg("theIndex"));
	cls_BRepMesh_CircleInspector.def("SetPoint", (void (BRepMesh_CircleInspector::*)(const gp_XY &)) &BRepMesh_CircleInspector::SetPoint, "Set reference point to be checked.", py::arg("thePoint"));
	cls_BRepMesh_CircleInspector.def("GetShotCircles", (BRepMesh::ListOfInteger & (BRepMesh_CircleInspector::*)()) &BRepMesh_CircleInspector::GetShotCircles, "Returns list of circles shot by the reference point.");
	cls_BRepMesh_CircleInspector.def("Inspect", (NCollection_CellFilter_Action (BRepMesh_CircleInspector::*)(const Standard_Integer)) &BRepMesh_CircleInspector::Inspect, "Performs inspection of a circle with the given index.", py::arg("theTargetIndex"));
	cls_BRepMesh_CircleInspector.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_Integer, const Standard_Integer)) &BRepMesh_CircleInspector::IsEqual, "Checks indices for equlity.", py::arg("theIndex"), py::arg("theTargetIndex"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_Classifier.hxx
	py::class_<BRepMesh_Classifier, std::unique_ptr<BRepMesh_Classifier, Deleter<BRepMesh_Classifier>>> cls_BRepMesh_Classifier(mod, "BRepMesh_Classifier", "Auxilary class contains information about correctness of discretized face and used for classification of points regarding face internals.");
	cls_BRepMesh_Classifier.def(py::init<>());
	cls_BRepMesh_Classifier.def("Destroy", (void (BRepMesh_Classifier::*)()) &BRepMesh_Classifier::Destroy, "Method is called on destruction. Clears internal data structures.");
	cls_BRepMesh_Classifier.def("Perform", (TopAbs_State (BRepMesh_Classifier::*)(const gp_Pnt2d &) const ) &BRepMesh_Classifier::Perform, "Performs classification of the given point regarding to face internals.", py::arg("thePoint"));
	cls_BRepMesh_Classifier.def("RegisterWire", (void (BRepMesh_Classifier::*)(const NCollection_Sequence<gp_Pnt2d> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepMesh_Classifier::RegisterWire, "Registers wire specified by sequence of points for further classification of points.", py::arg("theWire"), py::arg("theTolUV"), py::arg("theUmin"), py::arg("theUmax"), py::arg("theVmin"), py::arg("theVmax"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_VertexTool.hxx
	py::class_<BRepMesh_VertexTool, std::unique_ptr<BRepMesh_VertexTool, Deleter<BRepMesh_VertexTool>>> cls_BRepMesh_VertexTool(mod, "BRepMesh_VertexTool", "Describes data structure intended to keep mesh nodes defined in UV space and implements functionality providing their uniqueness regarding thir position.");
	cls_BRepMesh_VertexTool.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));
	cls_BRepMesh_VertexTool.def("SetCellSize", (void (BRepMesh_VertexTool::*)(const Standard_Real)) &BRepMesh_VertexTool::SetCellSize, "Sets new size of cell for cellfilter equal in both directions.", py::arg("theSize"));
	cls_BRepMesh_VertexTool.def("SetCellSize", (void (BRepMesh_VertexTool::*)(const Standard_Real, const Standard_Real)) &BRepMesh_VertexTool::SetCellSize, "Sets new size of cell for cellfilter.", py::arg("theSizeX"), py::arg("theSizeY"));
	cls_BRepMesh_VertexTool.def("SetTolerance", (void (BRepMesh_VertexTool::*)(const Standard_Real)) &BRepMesh_VertexTool::SetTolerance, "Sets the tolerance to be used for identification of coincident vertices equal for both dimensions.", py::arg("theTolerance"));
	cls_BRepMesh_VertexTool.def("SetTolerance", (void (BRepMesh_VertexTool::*)(const Standard_Real, const Standard_Real)) &BRepMesh_VertexTool::SetTolerance, "Sets the tolerance to be used for identification of coincident vertices.", py::arg("theToleranceX"), py::arg("theToleranceY"));
	cls_BRepMesh_VertexTool.def("GetTolerance", [](BRepMesh_VertexTool &self, Standard_Real & theToleranceX, Standard_Real & theToleranceY){ self.GetTolerance(theToleranceX, theToleranceY); return std::tuple<Standard_Real &, Standard_Real &>(theToleranceX, theToleranceY); }, "Gets the tolerance to be used for identification of coincident vertices.", py::arg("theToleranceX"), py::arg("theToleranceY"));
	cls_BRepMesh_VertexTool.def("Add", (Standard_Integer (BRepMesh_VertexTool::*)(const BRepMesh_Vertex &, const Standard_Boolean)) &BRepMesh_VertexTool::Add, "Adds vertex with empty data to the tool.", py::arg("theVertex"), py::arg("isForceAdd"));
	cls_BRepMesh_VertexTool.def("Delete", (void (BRepMesh_VertexTool::*)(const Standard_Integer)) &BRepMesh_VertexTool::Delete, "Deletes vertex with the given index from the tool.", py::arg("theIndex"));
	cls_BRepMesh_VertexTool.def("Vertices", (const BRepMesh::HVectorOfVertex & (BRepMesh_VertexTool::*)() const ) &BRepMesh_VertexTool::Vertices, "Returns set of mesh vertices.");
	cls_BRepMesh_VertexTool.def("ChangeVertices", (BRepMesh::HVectorOfVertex & (BRepMesh_VertexTool::*)()) &BRepMesh_VertexTool::ChangeVertices, "Returns set of mesh vertices.");
	cls_BRepMesh_VertexTool.def("FindKey", (const BRepMesh_Vertex & (BRepMesh_VertexTool::*)(const Standard_Integer)) &BRepMesh_VertexTool::FindKey, "Returns vertex by the given index.", py::arg("theIndex"));
	cls_BRepMesh_VertexTool.def("FindIndex", (Standard_Integer (BRepMesh_VertexTool::*)(const BRepMesh_Vertex &)) &BRepMesh_VertexTool::FindIndex, "Returns index of the given vertex.", py::arg("theVertex"));
	cls_BRepMesh_VertexTool.def("Extent", (Standard_Integer (BRepMesh_VertexTool::*)() const ) &BRepMesh_VertexTool::Extent, "Returns a number of vertices.");
	cls_BRepMesh_VertexTool.def("IsEmpty", (Standard_Boolean (BRepMesh_VertexTool::*)() const ) &BRepMesh_VertexTool::IsEmpty, "Returns True when the map contains no keys.");
	cls_BRepMesh_VertexTool.def("Substitute", (void (BRepMesh_VertexTool::*)(const Standard_Integer, const BRepMesh_Vertex &)) &BRepMesh_VertexTool::Substitute, "Substitutes vertex with the given by the given vertex with attributes.", py::arg("theIndex"), py::arg("theVertex"));
	cls_BRepMesh_VertexTool.def("RemoveLast", (void (BRepMesh_VertexTool::*)()) &BRepMesh_VertexTool::RemoveLast, "Remove last node from the structure.");
	cls_BRepMesh_VertexTool.def("GetListOfDelNodes", (const BRepMesh::ListOfInteger & (BRepMesh_VertexTool::*)() const ) &BRepMesh_VertexTool::GetListOfDelNodes, "Returns the list with indexes of vertices that have movability attribute equal to BRepMesh_Deleted and can be replaced with another node.");
	cls_BRepMesh_VertexTool.def("Statistics", (void (BRepMesh_VertexTool::*)(Standard_OStream &) const ) &BRepMesh_VertexTool::Statistics, "Prints statistics.", py::arg("theStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_CircleTool.hxx
	py::class_<BRepMesh_CircleTool, std::unique_ptr<BRepMesh_CircleTool, Deleter<BRepMesh_CircleTool>>> cls_BRepMesh_CircleTool(mod, "BRepMesh_CircleTool", "Create sort and destroy the circles used in triangulation.");
	cls_BRepMesh_CircleTool.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));
	cls_BRepMesh_CircleTool.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theReservedSize"), py::arg("theAllocator"));
	cls_BRepMesh_CircleTool.def("Init", (void (BRepMesh_CircleTool::*)(const Standard_Integer)) &BRepMesh_CircleTool::Init, "Initializes the tool.", py::arg(""));
	cls_BRepMesh_CircleTool.def("SetCellSize", (void (BRepMesh_CircleTool::*)(const Standard_Real)) &BRepMesh_CircleTool::SetCellSize, "Sets new size for cell filter.", py::arg("theSize"));
	cls_BRepMesh_CircleTool.def("SetCellSize", (void (BRepMesh_CircleTool::*)(const Standard_Real, const Standard_Real)) &BRepMesh_CircleTool::SetCellSize, "Sets new size for cell filter.", py::arg("theSizeX"), py::arg("theSizeY"));
	cls_BRepMesh_CircleTool.def("SetMinMaxSize", (void (BRepMesh_CircleTool::*)(const gp_XY &, const gp_XY &)) &BRepMesh_CircleTool::SetMinMaxSize, "Sets limits of inspection area.", py::arg("theMin"), py::arg("theMax"));
	cls_BRepMesh_CircleTool.def("Bind", (void (BRepMesh_CircleTool::*)(const Standard_Integer, const gp_Circ2d &)) &BRepMesh_CircleTool::Bind, "Binds the circle to the tool.", py::arg("theIndex"), py::arg("theCircle"));
	cls_BRepMesh_CircleTool.def_static("MakeCircle_", [](const gp_XY & thePoint1, const gp_XY & thePoint2, const gp_XY & thePoint3, gp_XY & theLocation, Standard_Real & theRadius){ Standard_Boolean rv = BRepMesh_CircleTool::MakeCircle(thePoint1, thePoint2, thePoint3, theLocation, theRadius); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theRadius); }, "Computes circle on three points.", py::arg("thePoint1"), py::arg("thePoint2"), py::arg("thePoint3"), py::arg("theLocation"), py::arg("theRadius"));
	cls_BRepMesh_CircleTool.def("Bind", (Standard_Boolean (BRepMesh_CircleTool::*)(const Standard_Integer, const gp_XY &, const gp_XY &, const gp_XY &)) &BRepMesh_CircleTool::Bind, "Computes circle on three points and bind it to the tool.", py::arg("theIndex"), py::arg("thePoint1"), py::arg("thePoint2"), py::arg("thePoint3"));
	cls_BRepMesh_CircleTool.def("MocBind", (void (BRepMesh_CircleTool::*)(const Standard_Integer)) &BRepMesh_CircleTool::MocBind, "Binds implicit zero circle.", py::arg("theIndex"));
	cls_BRepMesh_CircleTool.def("Delete", (void (BRepMesh_CircleTool::*)(const Standard_Integer)) &BRepMesh_CircleTool::Delete, "Deletes a circle from the tool.", py::arg("theIndex"));
	cls_BRepMesh_CircleTool.def("Select", (BRepMesh::ListOfInteger & (BRepMesh_CircleTool::*)(const gp_XY &)) &BRepMesh_CircleTool::Select, "Select the circles shot by the given point.", py::arg("thePoint"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_DataStructureOfDelaun.hxx
	py::class_<BRepMesh_DataStructureOfDelaun, opencascade::handle<BRepMesh_DataStructureOfDelaun>, Standard_Transient> cls_BRepMesh_DataStructureOfDelaun(mod, "BRepMesh_DataStructureOfDelaun", "Describes the data structure necessary for the mesh algorithms in two dimensions plane or on surface by meshing in UV space.");
	cls_BRepMesh_DataStructureOfDelaun.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));
	cls_BRepMesh_DataStructureOfDelaun.def(py::init<const opencascade::handle<NCollection_IncAllocator> &, const Standard_Integer>(), py::arg("theAllocator"), py::arg("theReservedNodeSize"));
	cls_BRepMesh_DataStructureOfDelaun.def("NbNodes", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)() const ) &BRepMesh_DataStructureOfDelaun::NbNodes, "Returns number of nodes.");
	cls_BRepMesh_DataStructureOfDelaun.def("AddNode", [](BRepMesh_DataStructureOfDelaun &self, const BRepMesh_Vertex & a0) -> Standard_Integer { return self.AddNode(a0); }, py::arg("theNode"));
	cls_BRepMesh_DataStructureOfDelaun.def("AddNode", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Vertex &, const Standard_Boolean)) &BRepMesh_DataStructureOfDelaun::AddNode, "Adds node to the mesh if it is not already in the mesh.", py::arg("theNode"), py::arg("isForceAdd"));
	cls_BRepMesh_DataStructureOfDelaun.def("IndexOf", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Vertex &)) &BRepMesh_DataStructureOfDelaun::IndexOf, "Finds the index of the given node.", py::arg("theNode"));
	cls_BRepMesh_DataStructureOfDelaun.def("GetNode", (const BRepMesh_Vertex & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::GetNode, "Get node by the index.", py::arg("theIndex"));
	cls_BRepMesh_DataStructureOfDelaun.def("__call__", (const BRepMesh_Vertex & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::operator(), py::is_operator(), "Alias for GetNode.", py::arg("theIndex"));
	cls_BRepMesh_DataStructureOfDelaun.def("SubstituteNode", (Standard_Boolean (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const BRepMesh_Vertex &)) &BRepMesh_DataStructureOfDelaun::SubstituteNode, "Substitutes the node with the given index by new one.", py::arg("theIndex"), py::arg("theNewNode"));
	cls_BRepMesh_DataStructureOfDelaun.def("RemoveNode", [](BRepMesh_DataStructureOfDelaun &self, const Standard_Integer a0) -> void { return self.RemoveNode(a0); }, py::arg("theIndex"));
	cls_BRepMesh_DataStructureOfDelaun.def("RemoveNode", (void (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const Standard_Boolean)) &BRepMesh_DataStructureOfDelaun::RemoveNode, "Removes node from the mesh in case if it has no connected links and its type is Free.", py::arg("theIndex"), py::arg("isForce"));
	cls_BRepMesh_DataStructureOfDelaun.def("LinksConnectedTo", (const BRepMesh::ListOfInteger & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer) const ) &BRepMesh_DataStructureOfDelaun::LinksConnectedTo, "Get list of links attached to the node with the given index.", py::arg("theIndex"));
	cls_BRepMesh_DataStructureOfDelaun.def("NbLinks", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)() const ) &BRepMesh_DataStructureOfDelaun::NbLinks, "Returns number of links.");
	cls_BRepMesh_DataStructureOfDelaun.def("AddLink", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Edge &)) &BRepMesh_DataStructureOfDelaun::AddLink, "Adds link to the mesh if it is not already in the mesh.", py::arg("theLink"));
	cls_BRepMesh_DataStructureOfDelaun.def("IndexOf", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Edge &) const ) &BRepMesh_DataStructureOfDelaun::IndexOf, "Finds the index of the given link.", py::arg("theLink"));
	cls_BRepMesh_DataStructureOfDelaun.def("GetLink", (const BRepMesh_Edge & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::GetLink, "Get link by the index.", py::arg("theIndex"));
	cls_BRepMesh_DataStructureOfDelaun.def("LinksOfDomain", (const BRepMesh::MapOfInteger & (BRepMesh_DataStructureOfDelaun::*)() const ) &BRepMesh_DataStructureOfDelaun::LinksOfDomain, "Returns map of indices of links registered in mesh.");
	cls_BRepMesh_DataStructureOfDelaun.def("SubstituteLink", (Standard_Boolean (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const BRepMesh_Edge &)) &BRepMesh_DataStructureOfDelaun::SubstituteLink, "Substitutes the link with the given index by new one.", py::arg("theIndex"), py::arg("theNewLink"));
	cls_BRepMesh_DataStructureOfDelaun.def("RemoveLink", [](BRepMesh_DataStructureOfDelaun &self, const Standard_Integer a0) -> void { return self.RemoveLink(a0); }, py::arg("theIndex"));
	cls_BRepMesh_DataStructureOfDelaun.def("RemoveLink", (void (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const Standard_Boolean)) &BRepMesh_DataStructureOfDelaun::RemoveLink, "Removes link from the mesh in case if it has no connected elements and its type is Free.", py::arg("theIndex"), py::arg("isForce"));
	cls_BRepMesh_DataStructureOfDelaun.def("ElementsConnectedTo", (const BRepMesh_PairOfIndex & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer) const ) &BRepMesh_DataStructureOfDelaun::ElementsConnectedTo, "Returns indices of elements conected to the link with the given index.", py::arg("theLinkIndex"));
	cls_BRepMesh_DataStructureOfDelaun.def("NbElements", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)() const ) &BRepMesh_DataStructureOfDelaun::NbElements, "Returns number of links.");
	cls_BRepMesh_DataStructureOfDelaun.def("AddElement", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Triangle &)) &BRepMesh_DataStructureOfDelaun::AddElement, "Adds element to the mesh if it is not already in the mesh.", py::arg("theElement"));
	cls_BRepMesh_DataStructureOfDelaun.def("IndexOf", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Triangle &) const ) &BRepMesh_DataStructureOfDelaun::IndexOf, "Finds the index of the given element.", py::arg("theElement"));
	cls_BRepMesh_DataStructureOfDelaun.def("GetElement", (const BRepMesh_Triangle & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::GetElement, "Get element by the index.", py::arg("theIndex"));
	cls_BRepMesh_DataStructureOfDelaun.def("ElementsOfDomain", (const BRepMesh::MapOfInteger & (BRepMesh_DataStructureOfDelaun::*)() const ) &BRepMesh_DataStructureOfDelaun::ElementsOfDomain, "Returns map of indices of elements registered in mesh.");
	cls_BRepMesh_DataStructureOfDelaun.def("SubstituteElement", (Standard_Boolean (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const BRepMesh_Triangle &)) &BRepMesh_DataStructureOfDelaun::SubstituteElement, "Substitutes the element with the given index by new one.", py::arg("theIndex"), py::arg("theNewElement"));
	cls_BRepMesh_DataStructureOfDelaun.def("RemoveElement", (void (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::RemoveElement, "Removes element from the mesh.", py::arg("theIndex"));
	// FIXME cls_BRepMesh_DataStructureOfDelaun.def("ElementNodes", (void (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Triangle &, Standard_Integer (&)[3])) &BRepMesh_DataStructureOfDelaun::ElementNodes, "Returns indices of nodes forming the given element.", py::arg("theElement"), py::arg("theNodes"));
	cls_BRepMesh_DataStructureOfDelaun.def("Statistics", (void (BRepMesh_DataStructureOfDelaun::*)(Standard_OStream &) const ) &BRepMesh_DataStructureOfDelaun::Statistics, "Dumps information about this structure.", py::arg("theStream"));
	cls_BRepMesh_DataStructureOfDelaun.def("Allocator", (const opencascade::handle<NCollection_IncAllocator> & (BRepMesh_DataStructureOfDelaun::*)() const ) &BRepMesh_DataStructureOfDelaun::Allocator, "Returns memory allocator used by the structure.");
	cls_BRepMesh_DataStructureOfDelaun.def("Data", (BRepMesh::HVertexTool & (BRepMesh_DataStructureOfDelaun::*)()) &BRepMesh_DataStructureOfDelaun::Data, "Gives the data structure for initialization of cell size and tolerance.");
	cls_BRepMesh_DataStructureOfDelaun.def("ClearDomain", (void (BRepMesh_DataStructureOfDelaun::*)()) &BRepMesh_DataStructureOfDelaun::ClearDomain, "Removes all elements.");
	cls_BRepMesh_DataStructureOfDelaun.def("ClearDeleted", (void (BRepMesh_DataStructureOfDelaun::*)()) &BRepMesh_DataStructureOfDelaun::ClearDeleted, "Substitutes deleted items by the last one from corresponding map to have only non-deleted elements, links or nodes in the structure.");
	cls_BRepMesh_DataStructureOfDelaun.def_static("get_type_name_", (const char * (*)()) &BRepMesh_DataStructureOfDelaun::get_type_name, "None");
	cls_BRepMesh_DataStructureOfDelaun.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_DataStructureOfDelaun::get_type_descriptor, "None");
	cls_BRepMesh_DataStructureOfDelaun.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_DataStructureOfDelaun::*)() const ) &BRepMesh_DataStructureOfDelaun::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_GeomTool.hxx
	py::class_<BRepMesh_GeomTool, std::unique_ptr<BRepMesh_GeomTool, Deleter<BRepMesh_GeomTool>>> cls_BRepMesh_GeomTool(mod, "BRepMesh_GeomTool", "Tool class accumulating common geometrical functions as well as functionality using shape geometry to produce data necessary for tessellation. General aim is to calculate discretization points for the given curve or iso curve of surface according to the specified parameters.");
	cls_BRepMesh_GeomTool.def(py::init<const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"));
	cls_BRepMesh_GeomTool.def(py::init<const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"));
	cls_BRepMesh_GeomTool.def(py::init<const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"), py::arg("theMinSize"));
	cls_BRepMesh_GeomTool.def(py::init<const opencascade::handle<BRepAdaptor_HSurface> &, const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theSurface"), py::arg("theIsoType"), py::arg("theParamIso"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"));
	cls_BRepMesh_GeomTool.def(py::init<const opencascade::handle<BRepAdaptor_HSurface> &, const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theSurface"), py::arg("theIsoType"), py::arg("theParamIso"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"));
	cls_BRepMesh_GeomTool.def(py::init<const opencascade::handle<BRepAdaptor_HSurface> &, const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theSurface"), py::arg("theIsoType"), py::arg("theParamIso"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"), py::arg("theMinSize"));
	cls_BRepMesh_GeomTool.def("AddPoint", [](BRepMesh_GeomTool &self, const gp_Pnt & a0, const Standard_Real a1) -> Standard_Integer { return self.AddPoint(a0, a1); }, py::arg("thePoint"), py::arg("theParam"));
	cls_BRepMesh_GeomTool.def("AddPoint", (Standard_Integer (BRepMesh_GeomTool::*)(const gp_Pnt &, const Standard_Real, const Standard_Boolean)) &BRepMesh_GeomTool::AddPoint, "Adds point to already calculated points (or replaces existing).", py::arg("thePoint"), py::arg("theParam"), py::arg("theIsReplace"));
	cls_BRepMesh_GeomTool.def("NbPoints", (Standard_Integer (BRepMesh_GeomTool::*)() const ) &BRepMesh_GeomTool::NbPoints, "Returns number of discretization points.");
	cls_BRepMesh_GeomTool.def("Value", [](BRepMesh_GeomTool &self, const Standard_Integer theIndex, const Standard_Real theIsoParam, Standard_Real & theParam, gp_Pnt & thePoint, gp_Pnt2d & theUV){ Standard_Boolean rv = self.Value(theIndex, theIsoParam, theParam, thePoint, theUV); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParam); }, "Gets parameters of discretization point with the given index.", py::arg("theIndex"), py::arg("theIsoParam"), py::arg("theParam"), py::arg("thePoint"), py::arg("theUV"));
	cls_BRepMesh_GeomTool.def("Value", [](BRepMesh_GeomTool &self, const Standard_Integer theIndex, Standard_Real & theParam, gp_Pnt & thePoint){ Standard_Boolean rv = self.Value(theIndex, theParam, thePoint); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParam); }, "Gets parameters of discretization point with the given index.", py::arg("theIndex"), py::arg("theParam"), py::arg("thePoint"));
	cls_BRepMesh_GeomTool.def_static("Normal_", (Standard_Boolean (*)(const opencascade::handle<BRepAdaptor_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Dir &)) &BRepMesh_GeomTool::Normal, "Computes normal to the given surface at the specified position in parametric space.", py::arg("theSurface"), py::arg("theParamU"), py::arg("theParamV"), py::arg("thePoint"), py::arg("theNormal"));
	// FIXME cls_BRepMesh_GeomTool.def_static("IntLinLin_", (BRepMesh_GeomTool::IntFlag (*)(const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, gp_XY &, Standard_Real (&)[2])) &BRepMesh_GeomTool::IntLinLin, "Checks intersection between two lines defined by two points.", py::arg("theStartPnt1"), py::arg("theEndPnt1"), py::arg("theStartPnt2"), py::arg("theEndPnt2"), py::arg("theIntPnt"), py::arg("theParamOnSegment"));
	cls_BRepMesh_GeomTool.def_static("IntSegSeg_", (BRepMesh_GeomTool::IntFlag (*)(const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, const Standard_Boolean, const Standard_Boolean, gp_Pnt2d &)) &BRepMesh_GeomTool::IntSegSeg, "Checks intersection between the two segments. Checks that intersection point lies within ranges of both segments.", py::arg("theStartPnt1"), py::arg("theEndPnt1"), py::arg("theStartPnt2"), py::arg("theEndPnt2"), py::arg("isConsiderEndPointTouch"), py::arg("isConsiderPointOnSegment"), py::arg("theIntPnt"));
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_GeomTool.hxx
	py::enum_<BRepMesh_GeomTool::IntFlag>(cls_BRepMesh_GeomTool, "IntFlag", "Enumerates states of segments intersection check.")
		.value("NoIntersection", BRepMesh_GeomTool::IntFlag::NoIntersection)
		.value("Cross", BRepMesh_GeomTool::IntFlag::Cross)
		.value("EndPointTouch", BRepMesh_GeomTool::IntFlag::EndPointTouch)
		.value("PointOnSegment", BRepMesh_GeomTool::IntFlag::PointOnSegment)
		.value("Glued", BRepMesh_GeomTool::IntFlag::Glued)
		.value("Same", BRepMesh_GeomTool::IntFlag::Same)
		.export_values();

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_Delaun.hxx
	py::class_<BRepMesh_Delaun, std::unique_ptr<BRepMesh_Delaun, Deleter<BRepMesh_Delaun>>> cls_BRepMesh_Delaun(mod, "BRepMesh_Delaun", "Compute the Delaunay's triangulation with the algorithm of Watson.");
	cls_BRepMesh_Delaun.def(py::init<BRepMesh::Array1OfVertexOfDelaun &>(), py::arg("theVertices"));
	cls_BRepMesh_Delaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &, BRepMesh::Array1OfVertexOfDelaun &>(), py::arg("theOldMesh"), py::arg("theVertices"));
	cls_BRepMesh_Delaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &, BRepMesh::Array1OfInteger &>(), py::arg("theOldMesh"), py::arg("theVertexIndices"));
	cls_BRepMesh_Delaun.def("Init", (void (BRepMesh_Delaun::*)(BRepMesh::Array1OfVertexOfDelaun &)) &BRepMesh_Delaun::Init, "Initializes the triangulation with an array of vertices.", py::arg("theVertices"));
	cls_BRepMesh_Delaun.def("RemoveVertex", (void (BRepMesh_Delaun::*)(const BRepMesh_Vertex &)) &BRepMesh_Delaun::RemoveVertex, "Removes a vertex from the triangulation.", py::arg("theVertex"));
	cls_BRepMesh_Delaun.def("AddVertices", (void (BRepMesh_Delaun::*)(BRepMesh::Array1OfVertexOfDelaun &)) &BRepMesh_Delaun::AddVertices, "Adds some vertices into the triangulation.", py::arg("theVertices"));
	cls_BRepMesh_Delaun.def("UseEdge", (Standard_Boolean (BRepMesh_Delaun::*)(const Standard_Integer)) &BRepMesh_Delaun::UseEdge, "Modify mesh to use the edge.", py::arg("theEdge"));
	cls_BRepMesh_Delaun.def("Result", (const opencascade::handle<BRepMesh_DataStructureOfDelaun> & (BRepMesh_Delaun::*)() const ) &BRepMesh_Delaun::Result, "Gives the Mesh data structure.");
	// cls_BRepMesh_Delaun.def("Frontier", (BRepMesh::HMapOfInteger (BRepMesh_Delaun::*)() const ) &BRepMesh_Delaun::Frontier, "Gives the list of frontier edges.");
	// cls_BRepMesh_Delaun.def("InternalEdges", (BRepMesh::HMapOfInteger (BRepMesh_Delaun::*)() const ) &BRepMesh_Delaun::InternalEdges, "Gives the list of internal edges.");
	// cls_BRepMesh_Delaun.def("FreeEdges", (BRepMesh::HMapOfInteger (BRepMesh_Delaun::*)() const ) &BRepMesh_Delaun::FreeEdges, "Gives the list of free edges used only one time");
	cls_BRepMesh_Delaun.def("GetVertex", (const BRepMesh_Vertex & (BRepMesh_Delaun::*)(const Standard_Integer) const ) &BRepMesh_Delaun::GetVertex, "Gives vertex with the given index", py::arg("theIndex"));
	cls_BRepMesh_Delaun.def("GetEdge", (const BRepMesh_Edge & (BRepMesh_Delaun::*)(const Standard_Integer) const ) &BRepMesh_Delaun::GetEdge, "Gives edge with the given index", py::arg("theIndex"));
	cls_BRepMesh_Delaun.def("GetTriangle", (const BRepMesh_Triangle & (BRepMesh_Delaun::*)(const Standard_Integer) const ) &BRepMesh_Delaun::GetTriangle, "Gives triangle with the given index", py::arg("theIndex"));
	cls_BRepMesh_Delaun.def("Circles", (const BRepMesh_CircleTool & (BRepMesh_Delaun::*)() const ) &BRepMesh_Delaun::Circles, "Returns tool used to build mesh consistent to Delaunay criteria.");
	cls_BRepMesh_Delaun.def("Contains", [](BRepMesh_Delaun &self, const Standard_Integer theTriangleId, const BRepMesh_Vertex & theVertex, const Standard_Real theSqTolerance, Standard_Integer & theEdgeOn){ Standard_Boolean rv = self.Contains(theTriangleId, theVertex, theSqTolerance, theEdgeOn); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theEdgeOn); }, "Test is the given triangle contains the given vertex.", py::arg("theTriangleId"), py::arg("theVertex"), py::arg("theSqTolerance"), py::arg("theEdgeOn"));
	
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_DiscretRoot.hxx
	py::class_<BRepMesh_DiscretRoot, opencascade::handle<BRepMesh_DiscretRoot>, Standard_Transient> cls_BRepMesh_DiscretRoot(mod, "BRepMesh_DiscretRoot", "This is a common interface for meshing algorithms instantiated by Mesh Factory and implemented by plugins.");
	cls_BRepMesh_DiscretRoot.def("SetShape", (void (BRepMesh_DiscretRoot::*)(const TopoDS_Shape &)) &BRepMesh_DiscretRoot::SetShape, "Set the shape to triangulate.", py::arg("theShape"));
	cls_BRepMesh_DiscretRoot.def("Shape", (const TopoDS_Shape & (BRepMesh_DiscretRoot::*)() const ) &BRepMesh_DiscretRoot::Shape, "None");
	cls_BRepMesh_DiscretRoot.def("IsDone", (Standard_Boolean (BRepMesh_DiscretRoot::*)() const ) &BRepMesh_DiscretRoot::IsDone, "Returns true if triangualtion was performed and has success.");
	cls_BRepMesh_DiscretRoot.def("Perform", (void (BRepMesh_DiscretRoot::*)()) &BRepMesh_DiscretRoot::Perform, "Compute triangulation for set shape.");
	cls_BRepMesh_DiscretRoot.def_static("get_type_name_", (const char * (*)()) &BRepMesh_DiscretRoot::get_type_name, "None");
	cls_BRepMesh_DiscretRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_DiscretRoot::get_type_descriptor, "None");
	cls_BRepMesh_DiscretRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_DiscretRoot::*)() const ) &BRepMesh_DiscretRoot::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_DiscretFactory.hxx
	py::class_<BRepMesh_DiscretFactory, std::unique_ptr<BRepMesh_DiscretFactory, py::nodelete>> cls_BRepMesh_DiscretFactory(mod, "BRepMesh_DiscretFactory", "This class intended to setup / retrieve default triangulation algorithm. Use BRepMesh_DiscretFactory::Get() static method to retrieve global Factory instance. Use BRepMesh_DiscretFactory::Discret() method to retrieve meshing tool.");
	cls_BRepMesh_DiscretFactory.def_static("Get_", (BRepMesh_DiscretFactory & (*)()) &BRepMesh_DiscretFactory::Get, "Returns the global factory instance.");
	cls_BRepMesh_DiscretFactory.def("Names", (const TColStd_MapOfAsciiString & (BRepMesh_DiscretFactory::*)() const ) &BRepMesh_DiscretFactory::Names, "Returns the list of registered meshing algorithms.");
	cls_BRepMesh_DiscretFactory.def("SetDefaultName", (Standard_Boolean (BRepMesh_DiscretFactory::*)(const TCollection_AsciiString &)) &BRepMesh_DiscretFactory::SetDefaultName, "Setup meshing algorithm by name. Returns TRUE if requested tool is available. On fail Factory will continue to use previous algo.", py::arg("theName"));
	cls_BRepMesh_DiscretFactory.def("DefaultName", (const TCollection_AsciiString & (BRepMesh_DiscretFactory::*)() const ) &BRepMesh_DiscretFactory::DefaultName, "Returns name for current meshing algorithm.");
	cls_BRepMesh_DiscretFactory.def("SetFunctionName", (Standard_Boolean (BRepMesh_DiscretFactory::*)(const TCollection_AsciiString &)) &BRepMesh_DiscretFactory::SetFunctionName, "Advanced function. Changes function name to retrieve from plugin. Returns TRUE if requested tool is available. On fail Factory will continue to use previous algo.", py::arg("theFuncName"));
	cls_BRepMesh_DiscretFactory.def("FunctionName", (const TCollection_AsciiString & (BRepMesh_DiscretFactory::*)() const ) &BRepMesh_DiscretFactory::FunctionName, "Returns function name that should be exported by plugin.");
	cls_BRepMesh_DiscretFactory.def("ErrorStatus", (BRepMesh_FactoryError (BRepMesh_DiscretFactory::*)() const ) &BRepMesh_DiscretFactory::ErrorStatus, "Returns error status for last meshing algorithm switch.");
	cls_BRepMesh_DiscretFactory.def("SetDefault", [](BRepMesh_DiscretFactory &self, const TCollection_AsciiString & a0) -> Standard_Boolean { return self.SetDefault(a0); }, py::arg("theName"));
	cls_BRepMesh_DiscretFactory.def("SetDefault", (Standard_Boolean (BRepMesh_DiscretFactory::*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &BRepMesh_DiscretFactory::SetDefault, "Setup meshing algorithm that should be created by this Factory. Returns TRUE if requested tool is available. On fail Factory will continue to use previous algo. Call ::ErrorStatus() method to retrieve fault reason.", py::arg("theName"), py::arg("theFuncName"));
	cls_BRepMesh_DiscretFactory.def("Discret", (opencascade::handle<BRepMesh_DiscretRoot> (BRepMesh_DiscretFactory::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real)) &BRepMesh_DiscretFactory::Discret, "Returns triangulation algorithm instance.", py::arg("theShape"), py::arg("theLinDeflection"), py::arg("theAngDeflection"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_EdgeParameterProvider.hxx
	py::class_<BRepMesh_EdgeParameterProvider, std::unique_ptr<BRepMesh_EdgeParameterProvider, Deleter<BRepMesh_EdgeParameterProvider>>> cls_BRepMesh_EdgeParameterProvider(mod, "BRepMesh_EdgeParameterProvider", "Auxiliary class provides correct parameters on curve regarding SameParameter flag.");
	// cls_BRepMesh_EdgeParameterProvider.def(py::init<const TopoDS_Edge &, const TopoDS_Face &, const opencascade::handle<TColStd_HArray1OfReal> &>(), py::arg("theEdge"), py::arg("theFace"), py::arg("theParameters"));
	// cls_BRepMesh_EdgeParameterProvider.def("Parameter", (Standard_Real (BRepMesh_EdgeParameterProvider::*)(const Standard_Integer, const gp_Pnt &)) &BRepMesh_EdgeParameterProvider::Parameter, "Returns parameter according to SameParameter flag of the edge. If SameParameter is TRUE returns value from parameters w/o changes, elsewhere scales initial parameter and tries to determine resulting value using projection of the corresponded 3D point on PCurve.", py::arg("theIndex"), py::arg("thePoint3d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_IEdgeTool.hxx
	py::class_<BRepMesh_IEdgeTool, opencascade::handle<BRepMesh_IEdgeTool>, Standard_Transient> cls_BRepMesh_IEdgeTool(mod, "BRepMesh_IEdgeTool", "Interface class providing API for edge tessellation tools.");
	cls_BRepMesh_IEdgeTool.def("NbPoints", (Standard_Integer (BRepMesh_IEdgeTool::*)() const ) &BRepMesh_IEdgeTool::NbPoints, "Returns number of tessellation points.");
	cls_BRepMesh_IEdgeTool.def("Value", [](BRepMesh_IEdgeTool &self, const Standard_Integer theIndex, Standard_Real & theParameter, gp_Pnt & thePoint, gp_Pnt2d & theUV){ Standard_Boolean rv = self.Value(theIndex, theParameter, thePoint, theUV); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParameter); }, "Returns parameters of solution with the given index.", py::arg("theIndex"), py::arg("theParameter"), py::arg("thePoint"), py::arg("theUV"));
	cls_BRepMesh_IEdgeTool.def_static("get_type_name_", (const char * (*)()) &BRepMesh_IEdgeTool::get_type_name, "None");
	cls_BRepMesh_IEdgeTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_IEdgeTool::get_type_descriptor, "None");
	cls_BRepMesh_IEdgeTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_IEdgeTool::*)() const ) &BRepMesh_IEdgeTool::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_EdgeTessellationExtractor.hxx
	py::class_<BRepMesh_EdgeTessellationExtractor, opencascade::handle<BRepMesh_EdgeTessellationExtractor>, BRepMesh_IEdgeTool> cls_BRepMesh_EdgeTessellationExtractor(mod, "BRepMesh_EdgeTessellationExtractor", "Auxiliary class implements functionality retrieving tessellated representation of an edge stored in polygon.");
	// cls_BRepMesh_EdgeTessellationExtractor.def(py::init<const TopoDS_Edge &, const opencascade::handle<Geom2dAdaptor_HCurve> &, const TopoDS_Face &, const opencascade::handle<Poly_Triangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const TopLoc_Location &>(), py::arg("theEdge"), py::arg("thePCurve"), py::arg("theFace"), py::arg("theTriangulation"), py::arg("thePolygon"), py::arg("theLocation"));
	cls_BRepMesh_EdgeTessellationExtractor.def("NbPoints", (Standard_Integer (BRepMesh_EdgeTessellationExtractor::*)() const ) &BRepMesh_EdgeTessellationExtractor::NbPoints, "Returns number of dicretization points.");
	cls_BRepMesh_EdgeTessellationExtractor.def("Value", [](BRepMesh_EdgeTessellationExtractor &self, const Standard_Integer theIndex, Standard_Real & theParameter, gp_Pnt & thePoint, gp_Pnt2d & theUV){ Standard_Boolean rv = self.Value(theIndex, theParameter, thePoint, theUV); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParameter); }, "Returns parameters of solution with the given index.", py::arg("theIndex"), py::arg("theParameter"), py::arg("thePoint"), py::arg("theUV"));
	cls_BRepMesh_EdgeTessellationExtractor.def_static("get_type_name_", (const char * (*)()) &BRepMesh_EdgeTessellationExtractor::get_type_name, "None");
	cls_BRepMesh_EdgeTessellationExtractor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_EdgeTessellationExtractor::get_type_descriptor, "None");
	cls_BRepMesh_EdgeTessellationExtractor.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_EdgeTessellationExtractor::*)() const ) &BRepMesh_EdgeTessellationExtractor::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_EdgeTessellator.hxx
	py::class_<BRepMesh_EdgeTessellator, opencascade::handle<BRepMesh_EdgeTessellator>, BRepMesh_IEdgeTool> cls_BRepMesh_EdgeTessellator(mod, "BRepMesh_EdgeTessellator", "Auxiliary class implements functionality producing tessellated representation of an edge based on edge geometry.");
	// cls_BRepMesh_EdgeTessellator.def(py::init<const TopoDS_Edge &, const opencascade::handle<BRepMesh_FaceAttribute> &, const TopTools_IndexedDataMapOfShapeListOfShape &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theEdge"), py::arg("theFaceAttribute"), py::arg("theMapOfSharedFaces"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinSize"));
	cls_BRepMesh_EdgeTessellator.def("NbPoints", (Standard_Integer (BRepMesh_EdgeTessellator::*)() const ) &BRepMesh_EdgeTessellator::NbPoints, "Returns number of dicretization points.");
	cls_BRepMesh_EdgeTessellator.def("Value", [](BRepMesh_EdgeTessellator &self, const Standard_Integer theIndex, Standard_Real & theParameter, gp_Pnt & thePoint, gp_Pnt2d & theUV){ Standard_Boolean rv = self.Value(theIndex, theParameter, thePoint, theUV); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParameter); }, "Returns parameters of solution with the given index.", py::arg("theIndex"), py::arg("theParameter"), py::arg("thePoint"), py::arg("theUV"));
	cls_BRepMesh_EdgeTessellator.def_static("get_type_name_", (const char * (*)()) &BRepMesh_EdgeTessellator::get_type_name, "None");
	cls_BRepMesh_EdgeTessellator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_EdgeTessellator::get_type_descriptor, "None");
	cls_BRepMesh_EdgeTessellator.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_EdgeTessellator::*)() const ) &BRepMesh_EdgeTessellator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_ShapeTool.hxx
	py::class_<BRepMesh_ShapeTool, std::unique_ptr<BRepMesh_ShapeTool, Deleter<BRepMesh_ShapeTool>>> cls_BRepMesh_ShapeTool(mod, "BRepMesh_ShapeTool", "None");
	cls_BRepMesh_ShapeTool.def(py::init<>());
	cls_BRepMesh_ShapeTool.def_static("MaxFaceTolerance_", (Standard_Real (*)(const TopoDS_Face &)) &BRepMesh_ShapeTool::MaxFaceTolerance, "Returns maximum tolerance of the given face. Considers tolerances of edges and vertices contained in the given face.", py::arg("theFace"));
	cls_BRepMesh_ShapeTool.def_static("BoxMaxDimension_", [](const Bnd_Box & theBox, Standard_Real & theMaxDimension){ BRepMesh_ShapeTool::BoxMaxDimension(theBox, theMaxDimension); return theMaxDimension; }, "Gets the maximum dimension of the given bounding box. If the given bounding box is void leaves the resulting value unchanged.", py::arg("theBox"), py::arg("theMaxDimension"));
	cls_BRepMesh_ShapeTool.def_static("RelativeEdgeDeflection_", [](const TopoDS_Edge & theEdge, const Standard_Real theDeflection, const Standard_Real theMaxShapeSize, Standard_Real & theAdjustmentCoefficient){ Standard_Real rv = BRepMesh_ShapeTool::RelativeEdgeDeflection(theEdge, theDeflection, theMaxShapeSize, theAdjustmentCoefficient); return std::tuple<Standard_Real, Standard_Real &>(rv, theAdjustmentCoefficient); }, "Returns relative deflection for edge with respect to shape size.", py::arg("theEdge"), py::arg("theDeflection"), py::arg("theMaxShapeSize"), py::arg("theAdjustmentCoefficient"));
	cls_BRepMesh_ShapeTool.def_static("FindUV_", (gp_XY (*)(const Standard_Integer, const gp_Pnt2d &, const Standard_Real, const opencascade::handle<BRepMesh_FaceAttribute> &)) &BRepMesh_ShapeTool::FindUV, "Checks 2d representations of 3d point with the given index for equality to avoid duplications.", py::arg("theIndexOfPnt3d"), py::arg("thePnt2d"), py::arg("theMinDistance"), py::arg("theFaceAttribute"));
	cls_BRepMesh_ShapeTool.def_static("AddInFace_", (void (*)(const TopoDS_Face &, opencascade::handle<Poly_Triangulation> &)) &BRepMesh_ShapeTool::AddInFace, "Stores the given triangulation into the given face.", py::arg("theFace"), py::arg("theTriangulation"));
	cls_BRepMesh_ShapeTool.def_static("NullifyFace_", (void (*)(const TopoDS_Face &)) &BRepMesh_ShapeTool::NullifyFace, "Nullifies triangulation stored in the face.", py::arg("theFace"));
	cls_BRepMesh_ShapeTool.def_static("NullifyEdge_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRepMesh_ShapeTool::NullifyEdge, "Nullifies polygon on triangulation stored in the edge.", py::arg("theEdge"), py::arg("theTriangulation"), py::arg("theLocation"));
	cls_BRepMesh_ShapeTool.def_static("UpdateEdge_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRepMesh_ShapeTool::UpdateEdge, "Updates the given edge by the given tessellated representation.", py::arg("theEdge"), py::arg("thePolygon"), py::arg("theTriangulation"), py::arg("theLocation"));
	cls_BRepMesh_ShapeTool.def_static("UpdateEdge_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRepMesh_ShapeTool::UpdateEdge, "Updates the given seam edge by the given tessellated representations.", py::arg("theEdge"), py::arg("thePolygon1"), py::arg("thePolygon2"), py::arg("theTriangulation"), py::arg("theLocation"));
	cls_BRepMesh_ShapeTool.def_static("UseLocation_", (gp_Pnt (*)(const gp_Pnt &, const TopLoc_Location &)) &BRepMesh_ShapeTool::UseLocation, "Applies location to the given point and return result.", py::arg("thePnt"), py::arg("theLoc"));
	cls_BRepMesh_ShapeTool.def_static("IsDegenerated_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepMesh_ShapeTool::IsDegenerated, "Checks is the given edge degenerated. Checks geometrical parameters in case if IsDegenerated flag is not set.", py::arg("theEdge"), py::arg("theFace"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_FastDiscret.hxx
	py::class_<BRepMesh_FastDiscret, opencascade::handle<BRepMesh_FastDiscret>, Standard_Transient> cls_BRepMesh_FastDiscret(mod, "BRepMesh_FastDiscret", "Algorithm to mesh a shape with respect of the frontier the deflection and by option the shared components.");
	cls_BRepMesh_FastDiscret.def(py::init<const Bnd_Box &, const BRepMesh_FastDiscret::Parameters &>(), py::arg("B"), py::arg("theParams"));
	cls_BRepMesh_FastDiscret.def("Perform", (void (BRepMesh_FastDiscret::*)(const TopoDS_Shape &)) &BRepMesh_FastDiscret::Perform, "Build triangulation on the whole shape.", py::arg("shape"));
	cls_BRepMesh_FastDiscret.def("Add", (Standard_Integer (BRepMesh_FastDiscret::*)(const TopoDS_Face &)) &BRepMesh_FastDiscret::Add, "Record a face for further processing.", py::arg("face"));
	cls_BRepMesh_FastDiscret.def("Process", (void (BRepMesh_FastDiscret::*)(const TopoDS_Face &) const ) &BRepMesh_FastDiscret::Process, "Triangulate a face previously recorded for processing by call to Add(). Can be executed in parallel threads.", py::arg("face"));
	cls_BRepMesh_FastDiscret.def("__call__", (void (BRepMesh_FastDiscret::*)(const TopoDS_Face &) const ) &BRepMesh_FastDiscret::operator(), py::is_operator(), "None", py::arg("face"));
	cls_BRepMesh_FastDiscret.def("MeshParameters", (const BRepMesh_FastDiscret::Parameters & (BRepMesh_FastDiscret::*)() const ) &BRepMesh_FastDiscret::MeshParameters, "Returns parameters of meshing");
	cls_BRepMesh_FastDiscret.def("ChangeMeshParameters", (BRepMesh_FastDiscret::Parameters & (BRepMesh_FastDiscret::*)()) &BRepMesh_FastDiscret::ChangeMeshParameters, "Returns modificable mesh parameters");
	cls_BRepMesh_FastDiscret.def("InitSharedFaces", (void (BRepMesh_FastDiscret::*)(const TopoDS_Shape &)) &BRepMesh_FastDiscret::InitSharedFaces, "None", py::arg("theShape"));
	cls_BRepMesh_FastDiscret.def("SharedFaces", (const TopTools_IndexedDataMapOfShapeListOfShape & (BRepMesh_FastDiscret::*)() const ) &BRepMesh_FastDiscret::SharedFaces, "None");
	cls_BRepMesh_FastDiscret.def("GetFaceAttribute", [](BRepMesh_FastDiscret &self, const TopoDS_Face & a0, opencascade::handle<BRepMesh_FaceAttribute> & a1) -> Standard_Boolean { return self.GetFaceAttribute(a0, a1); }, py::arg("theFace"), py::arg("theAttribute"));
	cls_BRepMesh_FastDiscret.def("GetFaceAttribute", (Standard_Boolean (BRepMesh_FastDiscret::*)(const TopoDS_Face &, opencascade::handle<BRepMesh_FaceAttribute> &, const Standard_Boolean) const ) &BRepMesh_FastDiscret::GetFaceAttribute, "Returns attribute descriptor for the given face.", py::arg("theFace"), py::arg("theAttribute"), py::arg("isForceCreate"));
	cls_BRepMesh_FastDiscret.def("RemoveFaceAttribute", (void (BRepMesh_FastDiscret::*)(const TopoDS_Face &)) &BRepMesh_FastDiscret::RemoveFaceAttribute, "Remove face attribute as useless to free locate memory.", py::arg("theFace"));
	cls_BRepMesh_FastDiscret.def("NbBoundaryPoints", (Standard_Integer (BRepMesh_FastDiscret::*)() const ) &BRepMesh_FastDiscret::NbBoundaryPoints, "Returns number of boundary 3d points.");
	cls_BRepMesh_FastDiscret.def_static("get_type_name_", (const char * (*)()) &BRepMesh_FastDiscret::get_type_name, "None");
	cls_BRepMesh_FastDiscret.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_FastDiscret::get_type_descriptor, "None");
	cls_BRepMesh_FastDiscret.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_FastDiscret::*)() const ) &BRepMesh_FastDiscret::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_FastDiscretFace.hxx
	py::class_<BRepMesh_FastDiscretFace, opencascade::handle<BRepMesh_FastDiscretFace>, Standard_Transient> cls_BRepMesh_FastDiscretFace(mod, "BRepMesh_FastDiscretFace", "Algorithm to mesh a face with respect of the frontier the deflection and by option the shared components.");
	cls_BRepMesh_FastDiscretFace.def(py::init<const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("theAngle"), py::arg("theMinSize"), py::arg("isInternalVerticesMode"), py::arg("isControlSurfaceDeflection"));
	cls_BRepMesh_FastDiscretFace.def("Perform", (void (BRepMesh_FastDiscretFace::*)(const opencascade::handle<BRepMesh_FaceAttribute> &)) &BRepMesh_FastDiscretFace::Perform, "None", py::arg("theAttribute"));
	cls_BRepMesh_FastDiscretFace.def_static("get_type_name_", (const char * (*)()) &BRepMesh_FastDiscretFace::get_type_name, "None");
	cls_BRepMesh_FastDiscretFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_FastDiscretFace::get_type_descriptor, "None");
	cls_BRepMesh_FastDiscretFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_FastDiscretFace::*)() const ) &BRepMesh_FastDiscretFace::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_IncrementalMesh.hxx
	py::class_<BRepMesh_IncrementalMesh, opencascade::handle<BRepMesh_IncrementalMesh>, BRepMesh_DiscretRoot> cls_BRepMesh_IncrementalMesh(mod, "BRepMesh_IncrementalMesh", "Builds the mesh of a shape with respect of their correctly triangulated parts");
	cls_BRepMesh_IncrementalMesh.def(py::init<>());
	cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("theShape"), py::arg("theLinDeflection"));
	cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean>(), py::arg("theShape"), py::arg("theLinDeflection"), py::arg("isRelative"));
	cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("theShape"), py::arg("theLinDeflection"), py::arg("isRelative"), py::arg("theAngDeflection"));
	cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Boolean>(), py::arg("theShape"), py::arg("theLinDeflection"), py::arg("isRelative"), py::arg("theAngDeflection"), py::arg("isInParallel"));
	cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("theShape"), py::arg("theLinDeflection"), py::arg("isRelative"), py::arg("theAngDeflection"), py::arg("isInParallel"), py::arg("adaptiveMin"));
	cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const BRepMesh_FastDiscret::Parameters &>(), py::arg("theShape"), py::arg("theParameters"));
	cls_BRepMesh_IncrementalMesh.def("Perform", (void (BRepMesh_IncrementalMesh::*)()) &BRepMesh_IncrementalMesh::Perform, "Performs meshing ot the shape.");
	cls_BRepMesh_IncrementalMesh.def("Parameters", (const BRepMesh_FastDiscret::Parameters & (BRepMesh_IncrementalMesh::*)() const ) &BRepMesh_IncrementalMesh::Parameters, "Returns meshing parameters");
	cls_BRepMesh_IncrementalMesh.def("ChangeParameters", (BRepMesh_FastDiscret::Parameters & (BRepMesh_IncrementalMesh::*)()) &BRepMesh_IncrementalMesh::ChangeParameters, "Returns modifiable meshing parameters");
	cls_BRepMesh_IncrementalMesh.def("IsModified", (Standard_Boolean (BRepMesh_IncrementalMesh::*)() const ) &BRepMesh_IncrementalMesh::IsModified, "Returns modified flag.");
	cls_BRepMesh_IncrementalMesh.def("GetStatusFlags", (Standard_Integer (BRepMesh_IncrementalMesh::*)() const ) &BRepMesh_IncrementalMesh::GetStatusFlags, "Returns accumulated status flags faced during meshing.");
	// FIXME cls_BRepMesh_IncrementalMesh.def_static("Discret_", (Standard_Integer (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, BRepMesh_DiscretRoot *&)) &BRepMesh_IncrementalMesh::Discret, "Plugin interface for the Mesh Factories. Initializes meshing algorithm with the given parameters.", py::arg("theShape"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theAlgo"));
	cls_BRepMesh_IncrementalMesh.def_static("IsParallelDefault_", (Standard_Boolean (*)()) &BRepMesh_IncrementalMesh::IsParallelDefault, "Returns multi-threading usage flag set by default in Discret() static method (thus applied only to Mesh Factories).");
	cls_BRepMesh_IncrementalMesh.def_static("SetParallelDefault_", (void (*)(const Standard_Boolean)) &BRepMesh_IncrementalMesh::SetParallelDefault, "Setup multi-threading usage flag set by default in Discret() static method (thus applied only to Mesh Factories).", py::arg("isInParallel"));
	cls_BRepMesh_IncrementalMesh.def_static("get_type_name_", (const char * (*)()) &BRepMesh_IncrementalMesh::get_type_name, "None");
	cls_BRepMesh_IncrementalMesh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_IncrementalMesh::get_type_descriptor, "None");
	cls_BRepMesh_IncrementalMesh.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_IncrementalMesh::*)() const ) &BRepMesh_IncrementalMesh::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_SelectorOfDataStructureOfDelaun.hxx
	py::class_<BRepMesh_SelectorOfDataStructureOfDelaun, std::unique_ptr<BRepMesh_SelectorOfDataStructureOfDelaun, Deleter<BRepMesh_SelectorOfDataStructureOfDelaun>>> cls_BRepMesh_SelectorOfDataStructureOfDelaun(mod, "BRepMesh_SelectorOfDataStructureOfDelaun", "Describes a selector and an iterator on a selector of components of a mesh.");
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def(py::init<>());
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &>(), py::arg("theMesh"));
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("Initialize", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const opencascade::handle<BRepMesh_DataStructureOfDelaun> &)) &BRepMesh_SelectorOfDataStructureOfDelaun::Initialize, "Initializes selector by the mesh.", py::arg("theMesh"));
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOf", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const BRepMesh_Vertex &)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOf, "Selects all neighboring elements of the given node.", py::arg("theNode"));
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOfNode", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOfNode, "Selects all neighboring elements of node with the given index.", py::arg("theNodeIndex"));
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOf", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const BRepMesh_Edge &)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOf, "Selects all neighboring elements of the given link.", py::arg("theLink"));
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOfLink", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOfLink, "Selects all neighboring elements of link with the given index.", py::arg("theLinkIndex"));
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOf", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const BRepMesh_Triangle &)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOf, "Selects all neighboring elements of the given element.", py::arg("theElement"));
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOfElement", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOfElement, "Selects all neighboring elements by nodes of the given element.", py::arg("theElementIndex"));
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursByEdgeOf", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const BRepMesh_Triangle &)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursByEdgeOf, "Selects all neighboring elements by links of the given element.", py::arg("theElement"));
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOf", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const BRepMesh_SelectorOfDataStructureOfDelaun &)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOf, "Adds a level of neighbours by edge to the selector.", py::arg(""));
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("AddNeighbours", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)()) &BRepMesh_SelectorOfDataStructureOfDelaun::AddNeighbours, "Adds a level of neighbours by edge the selector.");
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("Nodes", (const BRepMesh::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const ) &BRepMesh_SelectorOfDataStructureOfDelaun::Nodes, "Returns selected nodes.");
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("Links", (const BRepMesh::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const ) &BRepMesh_SelectorOfDataStructureOfDelaun::Links, "Returns selected links.");
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("Elements", (const BRepMesh::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const ) &BRepMesh_SelectorOfDataStructureOfDelaun::Elements, "Returns selected elements.");
	cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("FrontierLinks", (const BRepMesh::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const ) &BRepMesh_SelectorOfDataStructureOfDelaun::FrontierLinks, "Gives the list of incices of frontier links.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_WireChecker.hxx
	py::class_<BRepMesh_WireChecker, std::unique_ptr<BRepMesh_WireChecker, Deleter<BRepMesh_WireChecker>>> cls_BRepMesh_WireChecker(mod, "BRepMesh_WireChecker", "Auxilary class intended to check correctness of discretized face. In particular, checks boundaries of discretized face for self intersections and gaps.");
	cls_BRepMesh_WireChecker.def(py::init<const TopoDS_Face &, const Standard_Real, const BRepMesh::HDMapOfShapePairOfPolygon &, const BRepMesh::HIMapOfInteger &, const opencascade::handle<BRepMesh_DataStructureOfDelaun> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("theFace"), py::arg("theTolUV"), py::arg("theEdges"), py::arg("theVertexMap"), py::arg("theStructure"), py::arg("theUmin"), py::arg("theUmax"), py::arg("theVmin"), py::arg("theVmax"), py::arg("isInParallel"));
	cls_BRepMesh_WireChecker.def("ReCompute", (void (BRepMesh_WireChecker::*)(BRepMesh::HClassifier &)) &BRepMesh_WireChecker::ReCompute, "Recompute data using parameters passed in constructor.", py::arg("theClassifier"));
	cls_BRepMesh_WireChecker.def("Status", (BRepMesh_Status (BRepMesh_WireChecker::*)() const ) &BRepMesh_WireChecker::Status, "Returns status of the check.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_WireInterferenceChecker.hxx
	py::class_<BRepMesh_WireInterferenceChecker, std::unique_ptr<BRepMesh_WireInterferenceChecker, Deleter<BRepMesh_WireInterferenceChecker>>> cls_BRepMesh_WireInterferenceChecker(mod, "BRepMesh_WireInterferenceChecker", "Auxilary class implementing functionality for checking interference between two discretized wires.");
	// cls_BRepMesh_WireInterferenceChecker.def(py::init<const BRepMesh::Array1OfSegmentsTree &, BRepMesh_Status *>(), py::arg("theWires"), py::arg("theStatus"));
	// cls_BRepMesh_WireInterferenceChecker.def(py::init<const BRepMesh::Array1OfSegmentsTree &, BRepMesh_Status *, Standard_Mutex *>(), py::arg("theWires"), py::arg("theStatus"), py::arg("theMutex"));
	// cls_BRepMesh_WireInterferenceChecker.def("__call__", (void (BRepMesh_WireInterferenceChecker::*)(const Standard_Integer &) const ) &BRepMesh_WireInterferenceChecker::operator(), py::is_operator(), "Checker's body.", py::arg("theWireId"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_WireInterferenceChecker.hxx
	py::enum_<BRepMesh_WireInterferenceChecker::IntFlag>(cls_BRepMesh_WireInterferenceChecker, "IntFlag", "Enumerates states of segments intersection check.")
		.value("NoIntersection", BRepMesh_WireInterferenceChecker::IntFlag::NoIntersection)
		.value("Cross", BRepMesh_WireInterferenceChecker::IntFlag::Cross)
		.value("EndPointTouch", BRepMesh_WireInterferenceChecker::IntFlag::EndPointTouch)
		.value("PointOnSegment", BRepMesh_WireInterferenceChecker::IntFlag::PointOnSegment)
		.value("Glued", BRepMesh_WireInterferenceChecker::IntFlag::Glued)
		.value("Same", BRepMesh_WireInterferenceChecker::IntFlag::Same)
		.export_values();

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMesh_PluginEntryType.hxx

}
