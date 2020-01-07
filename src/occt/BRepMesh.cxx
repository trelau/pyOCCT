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
#include <IMeshData_Wire.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <BRepMesh_DegreeOfFreedom.hxx>
#include <BRepMesh_FactoryError.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_OrientedEdge.hxx>
#include <BRepMesh_Vertex.hxx>
#include <BRepMesh_Triangle.hxx>
#include <BRepMesh_Edge.hxx>
#include <Standard.hxx>
#include <Precision.hxx>
#include <BRepMesh_Circle.hxx>
#include <Standard_OutOfRange.hxx>
#include <BRepMesh_PairOfIndex.hxx>
#include <IMeshTools_MeshAlgo.hxx>
#include <NCollection_Vector.hxx>
#include <gp_Pnt.hxx>
#include <IMeshData_Types.hxx>
#include <IMeshTools_Parameters.hxx>
#include <Standard_Std.hxx>
#include <BRepMesh_BaseMeshAlgo.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <NCollection_IncAllocator.hxx>
#include <BRepMesh_DataStructureOfDelaun.hxx>
#include <gp_Pnt2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <Poly_Triangulation.hxx>
#include <NCollection_DataMap.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <BRepMesh_DefaultRangeSplitter.hxx>
#include <BRepMesh_UVParamRangeSplitter.hxx>
#include <BRepMesh_NURBSRangeSplitter.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <BRepMesh_BoundaryParamsRangeSplitter.hxx>
#include <NCollection_CellFilter.hxx>
#include <BRepMesh_CircleInspector.hxx>
#include <NCollection_Array1.hxx>
#include <gp_Circ2d.hxx>
#include <BRepMesh_CircleTool.hxx>
#include <Standard_Transient.hxx>
#include <TopAbs_State.hxx>
#include <NCollection_Sequence.hxx>
#include <BRepMesh_Classifier.hxx>
#include <NCollection_Handle.hxx>
#include <CSLib_Class2d.hxx>
#include <BRepMesh_ConeRangeSplitter.hxx>
#include <BRepMesh_ConstrainedBaseMeshAlgo.hxx>
#include <BRepMesh_Delaun.hxx>
#include <IMeshTools_Context.hxx>
#include <BRepMesh_Context.hxx>
#include <IMeshTools_CurveTessellator.hxx>
#include <BRepMesh_CurveTessellator.hxx>
#include <Geom_Surface.hxx>
#include <Geom2d_Curve.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <GCPnts_TangentialDeflection.hxx>
#include <BRepMesh_VertexInspector.hxx>
#include <Standard_OStream.hxx>
#include <BRepMesh_VertexTool.hxx>
#include <GeomAbs_IsoType.hxx>
#include <gp_Dir.hxx>
#include <BRepMesh_GeomTool.hxx>
#include <gp_Lin.hxx>
#include <gp_Vec.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Bnd_Box2d.hxx>
#include <gp_Vec2d.hxx>
#include <Bnd_B2d.hxx>
#include <gp.hxx>
#include <BRepMesh_MeshTool.hxx>
#include <gp_Lin2d.hxx>
#include <BRepMesh_CylinderRangeSplitter.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepMesh_Deflection.hxx>
#include <BRepMesh_DelaunayBaseMeshAlgo.hxx>
#include <BRepMesh_DiscretRoot.hxx>
#include <BRepMesh_PluginEntryType.hxx>
#include <BRepMesh_DiscretFactory.hxx>
#include <TColStd_MapOfAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <Plugin_MapOfFunctions.hxx>
#include <IMeshTools_ModelAlgo.hxx>
#include <BRepMesh_EdgeDiscret.hxx>
#include <IMeshData_Model.hxx>
#include <BRepMesh_EdgeTessellationExtractor.hxx>
#include <BRepMesh_EdgeParameterProvider.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TopLoc_Location.hxx>
#include <BRepMesh_FaceChecker.hxx>
#include <IMeshTools_MeshAlgoFactory.hxx>
#include <BRepMesh_FaceDiscret.hxx>
#include <BRepMesh_FastDiscret.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepMesh_MeshAlgoFactory.hxx>
#include <IMeshTools_ModelBuilder.hxx>
#include <BRepMesh_ModelBuilder.hxx>
#include <BRepMesh_ModelHealer.hxx>
#include <BRepMesh_ModelPostProcessor.hxx>
#include <BRepMesh_ModelPreProcessor.hxx>
#include <BRepMesh_SelectorOfDataStructureOfDelaun.hxx>
#include <TopoDS_Face.hxx>
#include <Bnd_Box.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Poly_Polygon3D.hxx>
#include <Geom_Curve.hxx>
#include <BRepMesh_ShapeTool.hxx>
#include <IMeshTools_ShapeVisitor.hxx>
#include <BRepMesh_ShapeVisitor.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepMesh_SphereRangeSplitter.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <BRepMesh_TorusRangeSplitter.hxx>

PYBIND11_MODULE(BRepMesh, mod) {

py::module::import("OCCT.IMeshData");
py::module::import("OCCT.gp");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Precision");
py::module::import("OCCT.IMeshTools");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Poly");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.CSLib");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.GCPnts");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Plugin");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TopLoc");

// ENUM: BREPMESH_DEGREEOFFREEDOM
py::enum_<BRepMesh_DegreeOfFreedom>(mod, "BRepMesh_DegreeOfFreedom", "None")
	.value("BRepMesh_Free", BRepMesh_DegreeOfFreedom::BRepMesh_Free)
	.value("BRepMesh_InVolume", BRepMesh_DegreeOfFreedom::BRepMesh_InVolume)
	.value("BRepMesh_OnSurface", BRepMesh_DegreeOfFreedom::BRepMesh_OnSurface)
	.value("BRepMesh_OnCurve", BRepMesh_DegreeOfFreedom::BRepMesh_OnCurve)
	.value("BRepMesh_Fixed", BRepMesh_DegreeOfFreedom::BRepMesh_Fixed)
	.value("BRepMesh_Frontier", BRepMesh_DegreeOfFreedom::BRepMesh_Frontier)
	.value("BRepMesh_Deleted", BRepMesh_DegreeOfFreedom::BRepMesh_Deleted)
	.export_values();


// ENUM: BREPMESH_FACTORYERROR
py::enum_<BRepMesh_FactoryError>(mod, "BRepMesh_FactoryError", "None")
	.value("BRepMesh_FE_NOERROR", BRepMesh_FactoryError::BRepMesh_FE_NOERROR)
	.value("BRepMesh_FE_LIBRARYNOTFOUND", BRepMesh_FactoryError::BRepMesh_FE_LIBRARYNOTFOUND)
	.value("BRepMesh_FE_FUNCTIONNOTFOUND", BRepMesh_FactoryError::BRepMesh_FE_FUNCTIONNOTFOUND)
	.value("BRepMesh_FE_CANNOTCREATEALGO", BRepMesh_FactoryError::BRepMesh_FE_CANNOTCREATEALGO)
	.export_values();


// FUNCTION: HASHCODE
mod.def("HashCode", (Standard_Integer (*) (const BRepMesh_OrientedEdge &, const Standard_Integer)) &HashCode, "Computes a hash code for the given oriented edge, in the range [1, theUpperBound]", py::arg("theOrientedEdge"), py::arg("theUpperBound"));

mod.def("HashCode", (Standard_Integer (*) (const BRepMesh_Vertex &, const Standard_Integer)) &HashCode, "Computes a hash code for the given vertex, in the range [1, theUpperBound]", py::arg("theVertex"), py::arg("theUpperBound"));

mod.def("HashCode", (Standard_Integer (*) (const BRepMesh_Triangle &, const Standard_Integer)) &HashCode, "Computes a hash code for the given triangle, in the range [1, theUpperBound]", py::arg("theTriangle"), py::arg("theUpperBound"));

mod.def("HashCode", (Standard_Integer (*) (const BRepMesh_Edge &, const Standard_Integer)) &HashCode, "Computes a hash code for the given edge, in the range [1, theUpperBound]", py::arg("theEdge"), py::arg("theUpperBound"));

// CLASS: BREPMESH_ORIENTEDEDGE
py::class_<BRepMesh_OrientedEdge> cls_BRepMesh_OrientedEdge(mod, "BRepMesh_OrientedEdge", "Light weighted structure representing simple link.");

// Constructors
cls_BRepMesh_OrientedEdge.def(py::init<>());
cls_BRepMesh_OrientedEdge.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theFirstNode"), py::arg("theLastNode"));

// Methods
// cls_BRepMesh_OrientedEdge.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_OrientedEdge::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_OrientedEdge.def_static("operator delete_", (void (*)(void *)) &BRepMesh_OrientedEdge::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_OrientedEdge.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_OrientedEdge::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_OrientedEdge.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_OrientedEdge::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_OrientedEdge.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_OrientedEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_OrientedEdge.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_OrientedEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_OrientedEdge.def("FirstNode", (Standard_Integer (BRepMesh_OrientedEdge::*)() const) &BRepMesh_OrientedEdge::FirstNode, "Returns index of first node of the Link.");
cls_BRepMesh_OrientedEdge.def("LastNode", (Standard_Integer (BRepMesh_OrientedEdge::*)() const) &BRepMesh_OrientedEdge::LastNode, "Returns index of last node of the Link.");
cls_BRepMesh_OrientedEdge.def("HashCode", (Standard_Integer (BRepMesh_OrientedEdge::*)(const Standard_Integer) const) &BRepMesh_OrientedEdge::HashCode, "Computes a hash code for this oriented edge, in the range [1, theUpperBound]", py::arg("theUpperBound"));
cls_BRepMesh_OrientedEdge.def("IsEqual", (Standard_Boolean (BRepMesh_OrientedEdge::*)(const BRepMesh_OrientedEdge &) const) &BRepMesh_OrientedEdge::IsEqual, "Checks this and other edge for equality.", py::arg("theOther"));
cls_BRepMesh_OrientedEdge.def("__eq__", (Standard_Boolean (BRepMesh_OrientedEdge::*)(const BRepMesh_OrientedEdge &) const) &BRepMesh_OrientedEdge::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("Other"));

// CLASS: BREPMESH_VERTEX
py::class_<BRepMesh_Vertex> cls_BRepMesh_Vertex(mod, "BRepMesh_Vertex", "Light weighted structure representing vertex of the mesh in parametric space. Vertex could be associated with 3d point stored in external map.");

// Constructors
cls_BRepMesh_Vertex.def(py::init<>());
cls_BRepMesh_Vertex.def(py::init<const gp_XY &, const Standard_Integer, const BRepMesh_DegreeOfFreedom>(), py::arg("theUV"), py::arg("theLocation3d"), py::arg("theMovability"));
cls_BRepMesh_Vertex.def(py::init<const Standard_Real, const Standard_Real, const BRepMesh_DegreeOfFreedom>(), py::arg("theU"), py::arg("theV"), py::arg("theMovability"));

// Methods
// cls_BRepMesh_Vertex.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_Vertex::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_Vertex.def_static("operator delete_", (void (*)(void *)) &BRepMesh_Vertex::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_Vertex.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_Vertex::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_Vertex.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_Vertex::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_Vertex.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_Vertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_Vertex.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_Vertex::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_Vertex.def("Initialize", (void (BRepMesh_Vertex::*)(const gp_XY &, const Standard_Integer, const BRepMesh_DegreeOfFreedom)) &BRepMesh_Vertex::Initialize, "Initializes vertex associated with point in 3d space.", py::arg("theUV"), py::arg("theLocation3d"), py::arg("theMovability"));
cls_BRepMesh_Vertex.def("Coord", (const gp_XY & (BRepMesh_Vertex::*)() const) &BRepMesh_Vertex::Coord, "Returns position of the vertex in parametric space.");
cls_BRepMesh_Vertex.def("ChangeCoord", (gp_XY & (BRepMesh_Vertex::*)()) &BRepMesh_Vertex::ChangeCoord, "Returns position of the vertex in parametric space for modification.");
cls_BRepMesh_Vertex.def("Location3d", (Standard_Integer (BRepMesh_Vertex::*)() const) &BRepMesh_Vertex::Location3d, "Returns index of 3d point associated with the vertex.");
cls_BRepMesh_Vertex.def("Movability", (BRepMesh_DegreeOfFreedom (BRepMesh_Vertex::*)() const) &BRepMesh_Vertex::Movability, "Returns movability of the vertex.");
cls_BRepMesh_Vertex.def("SetMovability", (void (BRepMesh_Vertex::*)(const BRepMesh_DegreeOfFreedom)) &BRepMesh_Vertex::SetMovability, "Sets movability of the vertex.", py::arg("theMovability"));
cls_BRepMesh_Vertex.def("HashCode", (Standard_Integer (BRepMesh_Vertex::*)(const Standard_Integer) const) &BRepMesh_Vertex::HashCode, "Computes a hash code for this vertex, in the range [1, theUpperBound]", py::arg("theUpperBound"));
cls_BRepMesh_Vertex.def("IsEqual", (Standard_Boolean (BRepMesh_Vertex::*)(const BRepMesh_Vertex &) const) &BRepMesh_Vertex::IsEqual, "Checks for equality with another vertex.", py::arg("theOther"));
cls_BRepMesh_Vertex.def("__eq__", (Standard_Boolean (BRepMesh_Vertex::*)(const BRepMesh_Vertex &) const) &BRepMesh_Vertex::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("Other"));

// CLASS: BREPMESH_CIRCLE
py::class_<BRepMesh_Circle> cls_BRepMesh_Circle(mod, "BRepMesh_Circle", "Describes a 2d circle with a size of only 3 Standard_Real numbers instead of gp who needs 7 Standard_Real numbers.");

// Constructors
cls_BRepMesh_Circle.def(py::init<>());
cls_BRepMesh_Circle.def(py::init<const gp_XY &, const Standard_Real>(), py::arg("theLocation"), py::arg("theRadius"));

// Methods
// cls_BRepMesh_Circle.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_Circle::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_Circle.def_static("operator delete_", (void (*)(void *)) &BRepMesh_Circle::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_Circle.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_Circle::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_Circle.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_Circle::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_Circle.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_Circle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_Circle.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_Circle::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_Circle.def("SetLocation", (void (BRepMesh_Circle::*)(const gp_XY &)) &BRepMesh_Circle::SetLocation, "Sets location of a circle.", py::arg("theLocation"));
cls_BRepMesh_Circle.def("SetRadius", (void (BRepMesh_Circle::*)(const Standard_Real)) &BRepMesh_Circle::SetRadius, "Sets radius of a circle.", py::arg("theRadius"));
cls_BRepMesh_Circle.def("Location", (const gp_XY & (BRepMesh_Circle::*)() const) &BRepMesh_Circle::Location, "Returns location of a circle.");
cls_BRepMesh_Circle.def("Radius", (const Standard_Real & (BRepMesh_Circle::*)() const) &BRepMesh_Circle::Radius, "Returns radius of a circle.");

// CLASS: BREPMESH_TRIANGLE
py::class_<BRepMesh_Triangle> cls_BRepMesh_Triangle(mod, "BRepMesh_Triangle", "Light weighted structure representing triangle of mesh consisting of oriented links.");

// Constructors
cls_BRepMesh_Triangle.def(py::init<>());
// cls_BRepMesh_Triangle.def(py::init<const Standard_Integer (&)[3], const Standard_Boolean (&)[3], const BRepMesh_DegreeOfFreedom>(), py::arg("theEdges"), py::arg("theOrientations"), py::arg("theMovability"));

// Fields
// cls_BRepMesh_Triangle.def_readwrite("myEdges", &BRepMesh_Triangle::myEdges, "None");
// cls_BRepMesh_Triangle.def_readwrite("myOrientations", &BRepMesh_Triangle::myOrientations, "None");
cls_BRepMesh_Triangle.def_readwrite("myMovability", &BRepMesh_Triangle::myMovability, "None");

// Methods
// cls_BRepMesh_Triangle.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_Triangle::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_Triangle.def_static("operator delete_", (void (*)(void *)) &BRepMesh_Triangle::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_Triangle.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_Triangle::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_Triangle.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_Triangle::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_Triangle.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_Triangle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_Triangle.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_Triangle::operator delete, "None", py::arg(""), py::arg(""));
// cls_BRepMesh_Triangle.def("Initialize", (void (BRepMesh_Triangle::*)(const Standard_Integer (&)[3], const Standard_Boolean (&)[3], const BRepMesh_DegreeOfFreedom)) &BRepMesh_Triangle::Initialize, "Initializes the triangle by the given parameters.", py::arg("theEdges"), py::arg("theOrientations"), py::arg("theMovability"));
// cls_BRepMesh_Triangle.def("Edges", (void (BRepMesh_Triangle::*)(Standard_Integer (&)[3], Standard_Boolean (&)[3]) const) &BRepMesh_Triangle::Edges, "Gets edges with orientations composing the triangle.", py::arg("theEdges"), py::arg("theOrientations"));
cls_BRepMesh_Triangle.def("Movability", (BRepMesh_DegreeOfFreedom (BRepMesh_Triangle::*)() const) &BRepMesh_Triangle::Movability, "Returns movability of the triangle.");
cls_BRepMesh_Triangle.def("SetMovability", (void (BRepMesh_Triangle::*)(const BRepMesh_DegreeOfFreedom)) &BRepMesh_Triangle::SetMovability, "Sets movability of the triangle.", py::arg("theMovability"));
cls_BRepMesh_Triangle.def("HashCode", (Standard_Integer (BRepMesh_Triangle::*)(const Standard_Integer) const) &BRepMesh_Triangle::HashCode, "Computes a hash code for this triangle, in the range [1, theUpperBound]", py::arg("theUpperBound"));
cls_BRepMesh_Triangle.def("IsEqual", (Standard_Boolean (BRepMesh_Triangle::*)(const BRepMesh_Triangle &) const) &BRepMesh_Triangle::IsEqual, "Checks for equality with another triangle.", py::arg("theOther"));
cls_BRepMesh_Triangle.def("__eq__", (Standard_Boolean (BRepMesh_Triangle::*)(const BRepMesh_Triangle &) const) &BRepMesh_Triangle::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("theOther"));

// CLASS: BREPMESH_PAIROFINDEX
py::class_<BRepMesh_PairOfIndex> cls_BRepMesh_PairOfIndex(mod, "BRepMesh_PairOfIndex", "This class represents a pair of integer indices to store element indices connected to link. It is restricted to store more than two indices in it.");

// Constructors
cls_BRepMesh_PairOfIndex.def(py::init<>());

// Methods
cls_BRepMesh_PairOfIndex.def("Clear", (void (BRepMesh_PairOfIndex::*)()) &BRepMesh_PairOfIndex::Clear, "Clears indices.");
cls_BRepMesh_PairOfIndex.def("Append", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer)) &BRepMesh_PairOfIndex::Append, "Appends index to the pair.", py::arg("theIndex"));
cls_BRepMesh_PairOfIndex.def("Prepend", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer)) &BRepMesh_PairOfIndex::Prepend, "Prepends index to the pair.", py::arg("theIndex"));
cls_BRepMesh_PairOfIndex.def("IsEmpty", (Standard_Boolean (BRepMesh_PairOfIndex::*)() const) &BRepMesh_PairOfIndex::IsEmpty, "Returns is pair is empty.");
cls_BRepMesh_PairOfIndex.def("Extent", (Standard_Integer (BRepMesh_PairOfIndex::*)() const) &BRepMesh_PairOfIndex::Extent, "Returns number of initialized indeces.");
cls_BRepMesh_PairOfIndex.def("FirstIndex", (Standard_Integer (BRepMesh_PairOfIndex::*)() const) &BRepMesh_PairOfIndex::FirstIndex, "Returns first index of pair.");
cls_BRepMesh_PairOfIndex.def("LastIndex", (Standard_Integer (BRepMesh_PairOfIndex::*)() const) &BRepMesh_PairOfIndex::LastIndex, "Returns last index of pair");
cls_BRepMesh_PairOfIndex.def("Index", (Standard_Integer (BRepMesh_PairOfIndex::*)(const Standard_Integer) const) &BRepMesh_PairOfIndex::Index, "Returns index corresponding to the given position in the pair.", py::arg("thePairPos"));
cls_BRepMesh_PairOfIndex.def("SetIndex", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer, const Standard_Integer)) &BRepMesh_PairOfIndex::SetIndex, "Sets index corresponding to the given position in the pair.", py::arg("thePairPos"), py::arg("theIndex"));
cls_BRepMesh_PairOfIndex.def("RemoveIndex", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer)) &BRepMesh_PairOfIndex::RemoveIndex, "Remove index from the given position.", py::arg("thePairPos"));

// CLASS: BREPMESH_EDGE
py::class_<BRepMesh_Edge, BRepMesh_OrientedEdge> cls_BRepMesh_Edge(mod, "BRepMesh_Edge", "Light weighted structure representing link of the mesh.");

// Constructors
cls_BRepMesh_Edge.def(py::init<>());
cls_BRepMesh_Edge.def(py::init<const Standard_Integer, const Standard_Integer, const BRepMesh_DegreeOfFreedom>(), py::arg("theFirstNode"), py::arg("theLastNode"), py::arg("theMovability"));

// Methods
cls_BRepMesh_Edge.def("Movability", (BRepMesh_DegreeOfFreedom (BRepMesh_Edge::*)() const) &BRepMesh_Edge::Movability, "Returns movability flag of the Link.");
cls_BRepMesh_Edge.def("SetMovability", (void (BRepMesh_Edge::*)(const BRepMesh_DegreeOfFreedom)) &BRepMesh_Edge::SetMovability, "Sets movability flag of the Link.", py::arg("theMovability"));
cls_BRepMesh_Edge.def("IsSameOrientation", (Standard_Boolean (BRepMesh_Edge::*)(const BRepMesh_Edge &) const) &BRepMesh_Edge::IsSameOrientation, "Checks if the given edge and this one have the same orientation.", py::arg("theOther"));
cls_BRepMesh_Edge.def("IsEqual", (Standard_Boolean (BRepMesh_Edge::*)(const BRepMesh_Edge &) const) &BRepMesh_Edge::IsEqual, "Checks for equality with another edge.", py::arg("theOther"));
cls_BRepMesh_Edge.def("__eq__", (Standard_Boolean (BRepMesh_Edge::*)(const BRepMesh_Edge &) const) &BRepMesh_Edge::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("Other"));

// CLASS: BREPMESH_BASEMESHALGO
py::class_<BRepMesh_BaseMeshAlgo, opencascade::handle<BRepMesh_BaseMeshAlgo>, IMeshTools_MeshAlgo> cls_BRepMesh_BaseMeshAlgo(mod, "BRepMesh_BaseMeshAlgo", "Class provides base fuctionality for algorithms building face triangulation. Performs initialization of BRepMesh_DataStructureOfDelaun and nodes map structures.");

// Methods
cls_BRepMesh_BaseMeshAlgo.def("Perform", (void (BRepMesh_BaseMeshAlgo::*)(const IMeshData::IFaceHandle &, const IMeshTools_Parameters &)) &BRepMesh_BaseMeshAlgo::Perform, "Performs processing of the given face.", py::arg("theDFace"), py::arg("theParameters"));
cls_BRepMesh_BaseMeshAlgo.def_static("get_type_name_", (const char * (*)()) &BRepMesh_BaseMeshAlgo::get_type_name, "None");
cls_BRepMesh_BaseMeshAlgo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_BaseMeshAlgo::get_type_descriptor, "None");
cls_BRepMesh_BaseMeshAlgo.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_BaseMeshAlgo::*)() const) &BRepMesh_BaseMeshAlgo::DynamicType, "None");

// CLASS: BREPMESH_DEFAULTRANGESPLITTER
/*
py::class_<BRepMesh_DefaultRangeSplitter> cls_BRepMesh_DefaultRangeSplitter(mod, "BRepMesh_DefaultRangeSplitter", "Default tool to define range of discrete face model and obtain grid points distributed within this range.");

// Constructors
cls_BRepMesh_DefaultRangeSplitter.def(py::init<>());

// Methods
cls_BRepMesh_DefaultRangeSplitter.def("Reset", (void (BRepMesh_DefaultRangeSplitter::*)(const IMeshData::IFaceHandle &, const IMeshTools_Parameters &)) &BRepMesh_DefaultRangeSplitter::Reset, "Resets this splitter. Must be called before first use.", py::arg("theDFace"), py::arg("theParameters"));
cls_BRepMesh_DefaultRangeSplitter.def("AddPoint", (void (BRepMesh_DefaultRangeSplitter::*)(const gp_Pnt2d &)) &BRepMesh_DefaultRangeSplitter::AddPoint, "Registers border point.", py::arg("thePoint"));
cls_BRepMesh_DefaultRangeSplitter.def("AdjustRange", (void (BRepMesh_DefaultRangeSplitter::*)()) &BRepMesh_DefaultRangeSplitter::AdjustRange, "Updates discrete range of surface according to its geometric range.");
cls_BRepMesh_DefaultRangeSplitter.def("IsValid", (Standard_Boolean (BRepMesh_DefaultRangeSplitter::*)()) &BRepMesh_DefaultRangeSplitter::IsValid, "Returns True if computed range is valid.");
cls_BRepMesh_DefaultRangeSplitter.def("Scale", (gp_Pnt2d (BRepMesh_DefaultRangeSplitter::*)(const gp_Pnt2d &, const Standard_Boolean) const) &BRepMesh_DefaultRangeSplitter::Scale, "Scales the given point from real parametric space to face basis and otherwise.", py::arg("thePoint"), py::arg("isToFaceBasis"));
cls_BRepMesh_DefaultRangeSplitter.def("GenerateSurfaceNodes", (opencascade::handle<IMeshData::ListOfPnt2d> (BRepMesh_DefaultRangeSplitter::*)(const IMeshTools_Parameters &) const) &BRepMesh_DefaultRangeSplitter::GenerateSurfaceNodes, "Returns list of nodes generated using surface data and specified parameters. By default returns null ptr.", py::arg("theParameters"));
cls_BRepMesh_DefaultRangeSplitter.def("Point", (gp_Pnt (BRepMesh_DefaultRangeSplitter::*)(const gp_Pnt2d &) const) &BRepMesh_DefaultRangeSplitter::Point, "Returns point in 3d space corresponded to the given point defined in parameteric space of surface.", py::arg("thePoint2d"));
cls_BRepMesh_DefaultRangeSplitter.def("GetDFace", (const IMeshData::IFaceHandle & (BRepMesh_DefaultRangeSplitter::*)() const) &BRepMesh_DefaultRangeSplitter::GetDFace, "Returns face model.");
cls_BRepMesh_DefaultRangeSplitter.def("GetSurface", (const opencascade::handle<BRepAdaptor_HSurface> & (BRepMesh_DefaultRangeSplitter::*)() const) &BRepMesh_DefaultRangeSplitter::GetSurface, "Returns surface.");
cls_BRepMesh_DefaultRangeSplitter.def("GetRangeU", (const std::pair<Standard_Real, Standard_Real> & (BRepMesh_DefaultRangeSplitter::*)() const) &BRepMesh_DefaultRangeSplitter::GetRangeU, "Returns U range.");
cls_BRepMesh_DefaultRangeSplitter.def("GetRangeV", (const std::pair<Standard_Real, Standard_Real> & (BRepMesh_DefaultRangeSplitter::*)() const) &BRepMesh_DefaultRangeSplitter::GetRangeV, "Returns V range.");
cls_BRepMesh_DefaultRangeSplitter.def("GetDelta", (const std::pair<Standard_Real, Standard_Real> & (BRepMesh_DefaultRangeSplitter::*)() const) &BRepMesh_DefaultRangeSplitter::GetDelta, "Returns delta.");
cls_BRepMesh_DefaultRangeSplitter.def("GetToleranceUV", (const std::pair<Standard_Real, Standard_Real> & (BRepMesh_DefaultRangeSplitter::*)() const) &BRepMesh_DefaultRangeSplitter::GetToleranceUV, "None");
*/

// CLASS: BREPMESH_UVPARAMRANGESPLITTER
/*
py::class_<BRepMesh_UVParamRangeSplitter> cls_BRepMesh_UVParamRangeSplitter(mod, "BRepMesh_UVParamRangeSplitter", "Intended to generate internal mesh nodes using UV parameters of boundary discrete points.");

// Constructors
cls_BRepMesh_UVParamRangeSplitter.def(py::init<>());

// Methods
cls_BRepMesh_UVParamRangeSplitter.def("Reset", (void (BRepMesh_UVParamRangeSplitter::*)(const IMeshData::IFaceHandle &, const IMeshTools_Parameters &)) &BRepMesh_UVParamRangeSplitter::Reset, "Resets this splitter.", py::arg("theDFace"), py::arg("theParameters"));
cls_BRepMesh_UVParamRangeSplitter.def("GetParametersU", (const IMeshData::IMapOfReal & (BRepMesh_UVParamRangeSplitter::*)() const) &BRepMesh_UVParamRangeSplitter::GetParametersU, "Returns U parameters.");
cls_BRepMesh_UVParamRangeSplitter.def("GetParametersU", (IMeshData::IMapOfReal & (BRepMesh_UVParamRangeSplitter::*)()) &BRepMesh_UVParamRangeSplitter::GetParametersU, "Returns U parameters.");
cls_BRepMesh_UVParamRangeSplitter.def("GetParametersV", (const IMeshData::IMapOfReal & (BRepMesh_UVParamRangeSplitter::*)() const) &BRepMesh_UVParamRangeSplitter::GetParametersV, "Returns V parameters.");
cls_BRepMesh_UVParamRangeSplitter.def("GetParametersV", (IMeshData::IMapOfReal & (BRepMesh_UVParamRangeSplitter::*)()) &BRepMesh_UVParamRangeSplitter::GetParametersV, "Returns V parameters.");
*/

// CLASS: BREPMESH_NURBSRANGESPLITTER
/*
py::class_<BRepMesh_NURBSRangeSplitter> cls_BRepMesh_NURBSRangeSplitter(mod, "BRepMesh_NURBSRangeSplitter", "Auxiliary class extending UV range splitter in order to generate internal nodes for NURBS surface.");

// Constructors
cls_BRepMesh_NURBSRangeSplitter.def(py::init<>());

// Methods
cls_BRepMesh_NURBSRangeSplitter.def("AdjustRange", (void (BRepMesh_NURBSRangeSplitter::*)()) &BRepMesh_NURBSRangeSplitter::AdjustRange, "Updates discrete range of surface according to its geometric range.");
cls_BRepMesh_NURBSRangeSplitter.def("GenerateSurfaceNodes", (opencascade::handle<IMeshData::ListOfPnt2d> (BRepMesh_NURBSRangeSplitter::*)(const IMeshTools_Parameters &) const) &BRepMesh_NURBSRangeSplitter::GenerateSurfaceNodes, "Returns list of nodes generated using surface data and specified parameters.", py::arg("theParameters"));
*/

// CLASS: BREPMESH_BOUNDARYPARAMSRANGESPLITTER
/*
py::class_<BRepMesh_BoundaryParamsRangeSplitter> cls_BRepMesh_BoundaryParamsRangeSplitter(mod, "BRepMesh_BoundaryParamsRangeSplitter", "Auxiliary class extending UV range splitter in order to generate internal nodes for NURBS surface.");

// Constructors
cls_BRepMesh_BoundaryParamsRangeSplitter.def(py::init<>());

// Methods
cls_BRepMesh_BoundaryParamsRangeSplitter.def("AddPoint", (void (BRepMesh_BoundaryParamsRangeSplitter::*)(const gp_Pnt2d &)) &BRepMesh_BoundaryParamsRangeSplitter::AddPoint, "Registers border point.", py::arg("thePoint"));
*/

// CLASS: BREPMESH_CIRCLEINSPECTOR
py::class_<BRepMesh_CircleInspector, NCollection_CellFilter_InspectorXY> cls_BRepMesh_CircleInspector(mod, "BRepMesh_CircleInspector", "Auxilary class to find circles shot by the given point.");

// Constructors
cls_BRepMesh_CircleInspector.def(py::init<const Standard_Real, const Standard_Integer, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theTolerance"), py::arg("theReservedSize"), py::arg("theAllocator"));

// Methods
cls_BRepMesh_CircleInspector.def("Bind", (void (BRepMesh_CircleInspector::*)(const Standard_Integer, const BRepMesh_Circle &)) &BRepMesh_CircleInspector::Bind, "Adds the circle to vector of circles at the given position.", py::arg("theIndex"), py::arg("theCircle"));
cls_BRepMesh_CircleInspector.def("Circles", (const IMeshData::VectorOfCircle & (BRepMesh_CircleInspector::*)() const) &BRepMesh_CircleInspector::Circles, "Resutns vector of registered circles.");
cls_BRepMesh_CircleInspector.def("Circle", (BRepMesh_Circle & (BRepMesh_CircleInspector::*)(const Standard_Integer)) &BRepMesh_CircleInspector::Circle, "Returns circle with the given index.", py::arg("theIndex"));
cls_BRepMesh_CircleInspector.def("SetPoint", (void (BRepMesh_CircleInspector::*)(const gp_XY &)) &BRepMesh_CircleInspector::SetPoint, "Set reference point to be checked.", py::arg("thePoint"));
cls_BRepMesh_CircleInspector.def("GetShotCircles", (IMeshData::ListOfInteger & (BRepMesh_CircleInspector::*)()) &BRepMesh_CircleInspector::GetShotCircles, "Returns list of circles shot by the reference point.");
cls_BRepMesh_CircleInspector.def("Inspect", (NCollection_CellFilter_Action (BRepMesh_CircleInspector::*)(const Standard_Integer)) &BRepMesh_CircleInspector::Inspect, "Performs inspection of a circle with the given index.", py::arg("theTargetIndex"));
cls_BRepMesh_CircleInspector.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_Integer, const Standard_Integer)) &BRepMesh_CircleInspector::IsEqual, "Checks indices for equlity.", py::arg("theIndex"), py::arg("theTargetIndex"));

// CLASS: BREPMESH_CIRCLETOOL
py::class_<BRepMesh_CircleTool> cls_BRepMesh_CircleTool(mod, "BRepMesh_CircleTool", "Create sort and destroy the circles used in triangulation.");

// Constructors
cls_BRepMesh_CircleTool.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));
cls_BRepMesh_CircleTool.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theReservedSize"), py::arg("theAllocator"));

// Methods
// cls_BRepMesh_CircleTool.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_CircleTool::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_CircleTool.def_static("operator delete_", (void (*)(void *)) &BRepMesh_CircleTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_CircleTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_CircleTool::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_CircleTool.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_CircleTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_CircleTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_CircleTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_CircleTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_CircleTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_CircleTool.def("Init", (void (BRepMesh_CircleTool::*)(const Standard_Integer)) &BRepMesh_CircleTool::Init, "Initializes the tool.", py::arg(""));
cls_BRepMesh_CircleTool.def("SetCellSize", (void (BRepMesh_CircleTool::*)(const Standard_Real)) &BRepMesh_CircleTool::SetCellSize, "Sets new size for cell filter.", py::arg("theSize"));
cls_BRepMesh_CircleTool.def("SetCellSize", (void (BRepMesh_CircleTool::*)(const Standard_Real, const Standard_Real)) &BRepMesh_CircleTool::SetCellSize, "Sets new size for cell filter.", py::arg("theSizeX"), py::arg("theSizeY"));
cls_BRepMesh_CircleTool.def("SetMinMaxSize", (void (BRepMesh_CircleTool::*)(const gp_XY &, const gp_XY &)) &BRepMesh_CircleTool::SetMinMaxSize, "Sets limits of inspection area.", py::arg("theMin"), py::arg("theMax"));
cls_BRepMesh_CircleTool.def("IsEmpty", (Standard_Boolean (BRepMesh_CircleTool::*)() const) &BRepMesh_CircleTool::IsEmpty, "Retruns true if cell filter contains no circle.");
cls_BRepMesh_CircleTool.def("Bind", (void (BRepMesh_CircleTool::*)(const Standard_Integer, const gp_Circ2d &)) &BRepMesh_CircleTool::Bind, "Binds the circle to the tool.", py::arg("theIndex"), py::arg("theCircle"));
cls_BRepMesh_CircleTool.def_static("MakeCircle_", [](const gp_XY & thePoint1, const gp_XY & thePoint2, const gp_XY & thePoint3, gp_XY & theLocation, Standard_Real & theRadius){ Standard_Boolean rv = BRepMesh_CircleTool::MakeCircle(thePoint1, thePoint2, thePoint3, theLocation, theRadius); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theRadius); }, "Computes circle on three points.", py::arg("thePoint1"), py::arg("thePoint2"), py::arg("thePoint3"), py::arg("theLocation"), py::arg("theRadius"));
cls_BRepMesh_CircleTool.def("Bind", (Standard_Boolean (BRepMesh_CircleTool::*)(const Standard_Integer, const gp_XY &, const gp_XY &, const gp_XY &)) &BRepMesh_CircleTool::Bind, "Computes circle on three points and bind it to the tool.", py::arg("theIndex"), py::arg("thePoint1"), py::arg("thePoint2"), py::arg("thePoint3"));
cls_BRepMesh_CircleTool.def("MocBind", (void (BRepMesh_CircleTool::*)(const Standard_Integer)) &BRepMesh_CircleTool::MocBind, "Binds implicit zero circle.", py::arg("theIndex"));
cls_BRepMesh_CircleTool.def("Delete", (void (BRepMesh_CircleTool::*)(const Standard_Integer)) &BRepMesh_CircleTool::Delete, "Deletes a circle from the tool.", py::arg("theIndex"));
cls_BRepMesh_CircleTool.def("Select", (IMeshData::ListOfInteger & (BRepMesh_CircleTool::*)(const gp_XY &)) &BRepMesh_CircleTool::Select, "Select the circles shot by the given point.", py::arg("thePoint"));

// CLASS: BREPMESH_CLASSIFIER
py::class_<BRepMesh_Classifier, opencascade::handle<BRepMesh_Classifier>, Standard_Transient> cls_BRepMesh_Classifier(mod, "BRepMesh_Classifier", "Auxilary class intended for classification of points regarding internals of discrete face.");

// Constructors
cls_BRepMesh_Classifier.def(py::init<>());

// Methods
cls_BRepMesh_Classifier.def("Perform", (TopAbs_State (BRepMesh_Classifier::*)(const gp_Pnt2d &) const) &BRepMesh_Classifier::Perform, "Performs classification of the given point regarding to face internals.", py::arg("thePoint"));
cls_BRepMesh_Classifier.def("RegisterWire", (void (BRepMesh_Classifier::*)(const NCollection_Sequence<const gp_Pnt2d *> &, const std::pair<Standard_Real, Standard_Real> &, const std::pair<Standard_Real, Standard_Real> &, const std::pair<Standard_Real, Standard_Real> &)) &BRepMesh_Classifier::RegisterWire, "Registers wire specified by sequence of points for further classification of points.", py::arg("theWire"), py::arg("theTolUV"), py::arg("theRangeU"), py::arg("theRangeV"));
cls_BRepMesh_Classifier.def_static("get_type_name_", (const char * (*)()) &BRepMesh_Classifier::get_type_name, "None");
cls_BRepMesh_Classifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_Classifier::get_type_descriptor, "None");
cls_BRepMesh_Classifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_Classifier::*)() const) &BRepMesh_Classifier::DynamicType, "None");

// CLASS: BREPMESH_CONERANGESPLITTER
/*
py::class_<BRepMesh_ConeRangeSplitter> cls_BRepMesh_ConeRangeSplitter(mod, "BRepMesh_ConeRangeSplitter", "Auxiliary class extending default range splitter in order to generate internal nodes for conical surface.");

// Constructors
cls_BRepMesh_ConeRangeSplitter.def(py::init<>());

// Methods
// cls_BRepMesh_ConeRangeSplitter.def("GetSplitSteps", (std::pair<Standard_Real, Standard_Real> (BRepMesh_ConeRangeSplitter::*)(const IMeshTools_Parameters &, std::pair<Standard_Integer, Standard_Integer> &) const) &BRepMesh_ConeRangeSplitter::GetSplitSteps, "Returns split intervals along U and V direction.", py::arg("theParameters"), py::arg("theStepsNb"));
cls_BRepMesh_ConeRangeSplitter.def("GenerateSurfaceNodes", (opencascade::handle<IMeshData::ListOfPnt2d> (BRepMesh_ConeRangeSplitter::*)(const IMeshTools_Parameters &) const) &BRepMesh_ConeRangeSplitter::GenerateSurfaceNodes, "Returns list of nodes generated using surface data and specified parameters.", py::arg("theParameters"));
*/

// CLASS: BREPMESH_CONSTRAINEDBASEMESHALGO
py::class_<BRepMesh_ConstrainedBaseMeshAlgo, opencascade::handle<BRepMesh_ConstrainedBaseMeshAlgo>, BRepMesh_BaseMeshAlgo> cls_BRepMesh_ConstrainedBaseMeshAlgo(mod, "BRepMesh_ConstrainedBaseMeshAlgo", "Class provides base fuctionality to build face triangulation using Dealunay approach. Performs generation of mesh using raw data from model.");

// Methods
cls_BRepMesh_ConstrainedBaseMeshAlgo.def_static("get_type_name_", (const char * (*)()) &BRepMesh_ConstrainedBaseMeshAlgo::get_type_name, "None");
cls_BRepMesh_ConstrainedBaseMeshAlgo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_ConstrainedBaseMeshAlgo::get_type_descriptor, "None");
cls_BRepMesh_ConstrainedBaseMeshAlgo.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_ConstrainedBaseMeshAlgo::*)() const) &BRepMesh_ConstrainedBaseMeshAlgo::DynamicType, "None");

// CLASS: BREPMESH_CONTEXT
py::class_<BRepMesh_Context, opencascade::handle<BRepMesh_Context>, IMeshTools_Context> cls_BRepMesh_Context(mod, "BRepMesh_Context", "Class implemeting default context of BRepMesh algorithm. Initializes context by default algorithms.");

// Constructors
cls_BRepMesh_Context.def(py::init<>());

// Methods
cls_BRepMesh_Context.def_static("get_type_name_", (const char * (*)()) &BRepMesh_Context::get_type_name, "None");
cls_BRepMesh_Context.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_Context::get_type_descriptor, "None");
cls_BRepMesh_Context.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_Context::*)() const) &BRepMesh_Context::DynamicType, "None");

// CLASS: BREPMESH_CURVETESSELLATOR
py::class_<BRepMesh_CurveTessellator, opencascade::handle<BRepMesh_CurveTessellator>, IMeshTools_CurveTessellator> cls_BRepMesh_CurveTessellator(mod, "BRepMesh_CurveTessellator", "Auxiliary class performing tessellation of passed edge according to specified parameters.");

// Constructors
cls_BRepMesh_CurveTessellator.def(py::init<const IMeshData::IEdgeHandle &, const IMeshTools_Parameters &>(), py::arg("theEdge"), py::arg("theParameters"));
cls_BRepMesh_CurveTessellator.def(py::init<const IMeshData::IEdgeHandle &, const TopAbs_Orientation, const IMeshData::IFaceHandle &, const IMeshTools_Parameters &>(), py::arg("theEdge"), py::arg("theOrientation"), py::arg("theFace"), py::arg("theParameters"));

// Methods
cls_BRepMesh_CurveTessellator.def("PointsNb", (Standard_Integer (BRepMesh_CurveTessellator::*)() const) &BRepMesh_CurveTessellator::PointsNb, "Returns number of tessellation points.");
cls_BRepMesh_CurveTessellator.def("Value", [](BRepMesh_CurveTessellator &self, const Standard_Integer theIndex, gp_Pnt & thePoint, Standard_Real & theParameter){ Standard_Boolean rv = self.Value(theIndex, thePoint, theParameter); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParameter); }, "Returns parameters of solution with the given index.", py::arg("theIndex"), py::arg("thePoint"), py::arg("theParameter"));
cls_BRepMesh_CurveTessellator.def_static("get_type_name_", (const char * (*)()) &BRepMesh_CurveTessellator::get_type_name, "None");
cls_BRepMesh_CurveTessellator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_CurveTessellator::get_type_descriptor, "None");
cls_BRepMesh_CurveTessellator.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_CurveTessellator::*)() const) &BRepMesh_CurveTessellator::DynamicType, "None");

// CLASS: BREPMESH_VERTEXINSPECTOR
py::class_<BRepMesh_VertexInspector, NCollection_CellFilter_InspectorXY> cls_BRepMesh_VertexInspector(mod, "BRepMesh_VertexInspector", "Class intended for fast searching of the coincidence points.");

// Constructors
cls_BRepMesh_VertexInspector.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));

// Methods
cls_BRepMesh_VertexInspector.def("Add", (Standard_Integer (BRepMesh_VertexInspector::*)(const BRepMesh_Vertex &)) &BRepMesh_VertexInspector::Add, "Registers the given vertex.", py::arg("theVertex"));
cls_BRepMesh_VertexInspector.def("SetTolerance", (void (BRepMesh_VertexInspector::*)(const Standard_Real)) &BRepMesh_VertexInspector::SetTolerance, "Sets the tolerance to be used for identification of coincident vertices equal for both dimensions.", py::arg("theTolerance"));
cls_BRepMesh_VertexInspector.def("SetTolerance", (void (BRepMesh_VertexInspector::*)(const Standard_Real, const Standard_Real)) &BRepMesh_VertexInspector::SetTolerance, "Sets the tolerance to be used for identification of coincident vertices.", py::arg("theToleranceX"), py::arg("theToleranceY"));
cls_BRepMesh_VertexInspector.def("Clear", (void (BRepMesh_VertexInspector::*)()) &BRepMesh_VertexInspector::Clear, "Clear inspector's internal data structures.");
cls_BRepMesh_VertexInspector.def("Delete", (void (BRepMesh_VertexInspector::*)(const Standard_Integer)) &BRepMesh_VertexInspector::Delete, "Deletes vertex with the given index.", py::arg("theIndex"));
cls_BRepMesh_VertexInspector.def("NbVertices", (Standard_Integer (BRepMesh_VertexInspector::*)() const) &BRepMesh_VertexInspector::NbVertices, "Returns number of registered vertices.");
cls_BRepMesh_VertexInspector.def("GetVertex", (BRepMesh_Vertex & (BRepMesh_VertexInspector::*)(Standard_Integer)) &BRepMesh_VertexInspector::GetVertex, "Returns vertex with the given index.", py::arg("theIndex"));
cls_BRepMesh_VertexInspector.def("SetPoint", (void (BRepMesh_VertexInspector::*)(const gp_XY &)) &BRepMesh_VertexInspector::SetPoint, "Set reference point to be checked.", py::arg("thePoint"));
cls_BRepMesh_VertexInspector.def("GetCoincidentPoint", (Standard_Integer (BRepMesh_VertexInspector::*)() const) &BRepMesh_VertexInspector::GetCoincidentPoint, "Returns index of point coinciding with regerence one.");
cls_BRepMesh_VertexInspector.def("GetListOfDelPoints", (const IMeshData::ListOfInteger & (BRepMesh_VertexInspector::*)() const) &BRepMesh_VertexInspector::GetListOfDelPoints, "Returns list with indexes of vertices that have movability attribute equal to BRepMesh_Deleted and can be replaced with another node.");
cls_BRepMesh_VertexInspector.def("Vertices", (const opencascade::handle<IMeshData::VectorOfVertex> & (BRepMesh_VertexInspector::*)() const) &BRepMesh_VertexInspector::Vertices, "Returns set of mesh vertices.");
cls_BRepMesh_VertexInspector.def("ChangeVertices", (opencascade::handle<IMeshData::VectorOfVertex> & (BRepMesh_VertexInspector::*)()) &BRepMesh_VertexInspector::ChangeVertices, "Returns set of mesh vertices for modification.");
cls_BRepMesh_VertexInspector.def("Inspect", (NCollection_CellFilter_Action (BRepMesh_VertexInspector::*)(const Standard_Integer)) &BRepMesh_VertexInspector::Inspect, "Performs inspection of a point with the given index.", py::arg("theTargetIndex"));
cls_BRepMesh_VertexInspector.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_Integer, const Standard_Integer)) &BRepMesh_VertexInspector::IsEqual, "Checks indices for equlity.", py::arg("theIndex"), py::arg("theTargetIndex"));

// CLASS: BREPMESH_VERTEXTOOL
py::class_<BRepMesh_VertexTool, opencascade::handle<BRepMesh_VertexTool>, Standard_Transient> cls_BRepMesh_VertexTool(mod, "BRepMesh_VertexTool", "Describes data structure intended to keep mesh nodes defined in UV space and implements functionality providing their uniqueness regarding their position.");

// Constructors
cls_BRepMesh_VertexTool.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));

// Methods
cls_BRepMesh_VertexTool.def("SetCellSize", (void (BRepMesh_VertexTool::*)(const Standard_Real)) &BRepMesh_VertexTool::SetCellSize, "Sets new size of cell for cellfilter equal in both directions.", py::arg("theSize"));
cls_BRepMesh_VertexTool.def("SetCellSize", (void (BRepMesh_VertexTool::*)(const Standard_Real, const Standard_Real)) &BRepMesh_VertexTool::SetCellSize, "Sets new size of cell for cellfilter.", py::arg("theSizeX"), py::arg("theSizeY"));
cls_BRepMesh_VertexTool.def("SetTolerance", (void (BRepMesh_VertexTool::*)(const Standard_Real)) &BRepMesh_VertexTool::SetTolerance, "Sets the tolerance to be used for identification of coincident vertices equal for both dimensions.", py::arg("theTolerance"));
cls_BRepMesh_VertexTool.def("SetTolerance", (void (BRepMesh_VertexTool::*)(const Standard_Real, const Standard_Real)) &BRepMesh_VertexTool::SetTolerance, "Sets the tolerance to be used for identification of coincident vertices.", py::arg("theToleranceX"), py::arg("theToleranceY"));
cls_BRepMesh_VertexTool.def("GetTolerance", [](BRepMesh_VertexTool &self, Standard_Real & theToleranceX, Standard_Real & theToleranceY){ self.GetTolerance(theToleranceX, theToleranceY); return std::tuple<Standard_Real &, Standard_Real &>(theToleranceX, theToleranceY); }, "Gets the tolerance to be used for identification of coincident vertices.", py::arg("theToleranceX"), py::arg("theToleranceY"));
cls_BRepMesh_VertexTool.def("Add", (Standard_Integer (BRepMesh_VertexTool::*)(const BRepMesh_Vertex &, const Standard_Boolean)) &BRepMesh_VertexTool::Add, "Adds vertex with empty data to the tool.", py::arg("theVertex"), py::arg("isForceAdd"));
cls_BRepMesh_VertexTool.def("DeleteVertex", (void (BRepMesh_VertexTool::*)(const Standard_Integer)) &BRepMesh_VertexTool::DeleteVertex, "Deletes vertex with the given index from the tool.", py::arg("theIndex"));
cls_BRepMesh_VertexTool.def("Vertices", (const opencascade::handle<IMeshData::VectorOfVertex> & (BRepMesh_VertexTool::*)() const) &BRepMesh_VertexTool::Vertices, "Returns set of mesh vertices.");
cls_BRepMesh_VertexTool.def("ChangeVertices", (opencascade::handle<IMeshData::VectorOfVertex> & (BRepMesh_VertexTool::*)()) &BRepMesh_VertexTool::ChangeVertices, "Returns set of mesh vertices.");
cls_BRepMesh_VertexTool.def("FindKey", (const BRepMesh_Vertex & (BRepMesh_VertexTool::*)(const Standard_Integer)) &BRepMesh_VertexTool::FindKey, "Returns vertex by the given index.", py::arg("theIndex"));
cls_BRepMesh_VertexTool.def("FindIndex", (Standard_Integer (BRepMesh_VertexTool::*)(const BRepMesh_Vertex &)) &BRepMesh_VertexTool::FindIndex, "Returns index of the given vertex.", py::arg("theVertex"));
cls_BRepMesh_VertexTool.def("Extent", (Standard_Integer (BRepMesh_VertexTool::*)() const) &BRepMesh_VertexTool::Extent, "Returns a number of vertices.");
cls_BRepMesh_VertexTool.def("IsEmpty", (Standard_Boolean (BRepMesh_VertexTool::*)() const) &BRepMesh_VertexTool::IsEmpty, "Returns True when the map contains no keys.");
cls_BRepMesh_VertexTool.def("Substitute", (void (BRepMesh_VertexTool::*)(const Standard_Integer, const BRepMesh_Vertex &)) &BRepMesh_VertexTool::Substitute, "Substitutes vertex with the given by the given vertex with attributes.", py::arg("theIndex"), py::arg("theVertex"));
cls_BRepMesh_VertexTool.def("RemoveLast", (void (BRepMesh_VertexTool::*)()) &BRepMesh_VertexTool::RemoveLast, "Remove last node from the structure.");
cls_BRepMesh_VertexTool.def("GetListOfDelNodes", (const IMeshData::ListOfInteger & (BRepMesh_VertexTool::*)() const) &BRepMesh_VertexTool::GetListOfDelNodes, "Returns the list with indexes of vertices that have movability attribute equal to BRepMesh_Deleted and can be replaced with another node.");
cls_BRepMesh_VertexTool.def("Statistics", (void (BRepMesh_VertexTool::*)(Standard_OStream &) const) &BRepMesh_VertexTool::Statistics, "Prints statistics.", py::arg("theStream"));
cls_BRepMesh_VertexTool.def_static("get_type_name_", (const char * (*)()) &BRepMesh_VertexTool::get_type_name, "None");
cls_BRepMesh_VertexTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_VertexTool::get_type_descriptor, "None");
cls_BRepMesh_VertexTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_VertexTool::*)() const) &BRepMesh_VertexTool::DynamicType, "None");

// CLASS: BREPMESH_DATASTRUCTUREOFDELAUN
py::class_<BRepMesh_DataStructureOfDelaun, opencascade::handle<BRepMesh_DataStructureOfDelaun>, Standard_Transient> cls_BRepMesh_DataStructureOfDelaun(mod, "BRepMesh_DataStructureOfDelaun", "Describes the data structure necessary for the mesh algorithms in two dimensions plane or on surface by meshing in UV space.");

// Constructors
cls_BRepMesh_DataStructureOfDelaun.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));
cls_BRepMesh_DataStructureOfDelaun.def(py::init<const opencascade::handle<NCollection_IncAllocator> &, const Standard_Integer>(), py::arg("theAllocator"), py::arg("theReservedNodeSize"));

// Methods
cls_BRepMesh_DataStructureOfDelaun.def("NbNodes", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::NbNodes, "Returns number of nodes.");
cls_BRepMesh_DataStructureOfDelaun.def("AddNode", [](BRepMesh_DataStructureOfDelaun &self, const BRepMesh_Vertex & a0) -> Standard_Integer { return self.AddNode(a0); });
cls_BRepMesh_DataStructureOfDelaun.def("AddNode", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Vertex &, const Standard_Boolean)) &BRepMesh_DataStructureOfDelaun::AddNode, "Adds node to the mesh if it is not already in the mesh.", py::arg("theNode"), py::arg("isForceAdd"));
cls_BRepMesh_DataStructureOfDelaun.def("IndexOf", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Vertex &)) &BRepMesh_DataStructureOfDelaun::IndexOf, "Finds the index of the given node.", py::arg("theNode"));
cls_BRepMesh_DataStructureOfDelaun.def("GetNode", (const BRepMesh_Vertex & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::GetNode, "Get node by the index.", py::arg("theIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("__call__", (const BRepMesh_Vertex & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::operator(), py::is_operator(), "Alias for GetNode.", py::arg("theIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("SubstituteNode", (Standard_Boolean (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const BRepMesh_Vertex &)) &BRepMesh_DataStructureOfDelaun::SubstituteNode, "Substitutes the node with the given index by new one.", py::arg("theIndex"), py::arg("theNewNode"));
cls_BRepMesh_DataStructureOfDelaun.def("RemoveNode", [](BRepMesh_DataStructureOfDelaun &self, const Standard_Integer a0) -> void { return self.RemoveNode(a0); });
cls_BRepMesh_DataStructureOfDelaun.def("RemoveNode", (void (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const Standard_Boolean)) &BRepMesh_DataStructureOfDelaun::RemoveNode, "Removes node from the mesh in case if it has no connected links and its type is Free.", py::arg("theIndex"), py::arg("isForce"));
cls_BRepMesh_DataStructureOfDelaun.def("LinksConnectedTo", (const IMeshData::ListOfInteger & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer) const) &BRepMesh_DataStructureOfDelaun::LinksConnectedTo, "Get list of links attached to the node with the given index.", py::arg("theIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("NbLinks", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::NbLinks, "Returns number of links.");
cls_BRepMesh_DataStructureOfDelaun.def("AddLink", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Edge &)) &BRepMesh_DataStructureOfDelaun::AddLink, "Adds link to the mesh if it is not already in the mesh.", py::arg("theLink"));
cls_BRepMesh_DataStructureOfDelaun.def("IndexOf", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Edge &) const) &BRepMesh_DataStructureOfDelaun::IndexOf, "Finds the index of the given link.", py::arg("theLink"));
cls_BRepMesh_DataStructureOfDelaun.def("GetLink", (const BRepMesh_Edge & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::GetLink, "Get link by the index.", py::arg("theIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("LinksOfDomain", (const IMeshData::MapOfInteger & (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::LinksOfDomain, "Returns map of indices of links registered in mesh.");
cls_BRepMesh_DataStructureOfDelaun.def("SubstituteLink", (Standard_Boolean (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const BRepMesh_Edge &)) &BRepMesh_DataStructureOfDelaun::SubstituteLink, "Substitutes the link with the given index by new one.", py::arg("theIndex"), py::arg("theNewLink"));
cls_BRepMesh_DataStructureOfDelaun.def("RemoveLink", [](BRepMesh_DataStructureOfDelaun &self, const Standard_Integer a0) -> void { return self.RemoveLink(a0); });
cls_BRepMesh_DataStructureOfDelaun.def("RemoveLink", (void (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const Standard_Boolean)) &BRepMesh_DataStructureOfDelaun::RemoveLink, "Removes link from the mesh in case if it has no connected elements and its type is Free.", py::arg("theIndex"), py::arg("isForce"));
cls_BRepMesh_DataStructureOfDelaun.def("ElementsConnectedTo", (const BRepMesh_PairOfIndex & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer) const) &BRepMesh_DataStructureOfDelaun::ElementsConnectedTo, "Returns indices of elements conected to the link with the given index.", py::arg("theLinkIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("NbElements", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::NbElements, "Returns number of links.");
cls_BRepMesh_DataStructureOfDelaun.def("AddElement", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Triangle &)) &BRepMesh_DataStructureOfDelaun::AddElement, "Adds element to the mesh if it is not already in the mesh.", py::arg("theElement"));
cls_BRepMesh_DataStructureOfDelaun.def("GetElement", (const BRepMesh_Triangle & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::GetElement, "Get element by the index.", py::arg("theIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("ElementsOfDomain", (const IMeshData::MapOfInteger & (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::ElementsOfDomain, "Returns map of indices of elements registered in mesh.");
cls_BRepMesh_DataStructureOfDelaun.def("SubstituteElement", (Standard_Boolean (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const BRepMesh_Triangle &)) &BRepMesh_DataStructureOfDelaun::SubstituteElement, "Substitutes the element with the given index by new one.", py::arg("theIndex"), py::arg("theNewElement"));
cls_BRepMesh_DataStructureOfDelaun.def("RemoveElement", (void (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::RemoveElement, "Removes element from the mesh.", py::arg("theIndex"));
// cls_BRepMesh_DataStructureOfDelaun.def("ElementNodes", (void (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Triangle &, Standard_Integer (&)[3])) &BRepMesh_DataStructureOfDelaun::ElementNodes, "Returns indices of nodes forming the given element.", py::arg("theElement"), py::arg("theNodes"));
cls_BRepMesh_DataStructureOfDelaun.def("Dump", (void (BRepMesh_DataStructureOfDelaun::*)(Standard_CString)) &BRepMesh_DataStructureOfDelaun::Dump, "None", py::arg("theFileNameStr"));
cls_BRepMesh_DataStructureOfDelaun.def("Statistics", (void (BRepMesh_DataStructureOfDelaun::*)(Standard_OStream &) const) &BRepMesh_DataStructureOfDelaun::Statistics, "Dumps information about this structure.", py::arg("theStream"));
cls_BRepMesh_DataStructureOfDelaun.def("Allocator", (const opencascade::handle<NCollection_IncAllocator> & (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::Allocator, "Returns memory allocator used by the structure.");
cls_BRepMesh_DataStructureOfDelaun.def("Data", (const opencascade::handle<BRepMesh_VertexTool> & (BRepMesh_DataStructureOfDelaun::*)()) &BRepMesh_DataStructureOfDelaun::Data, "Gives the data structure for initialization of cell size and tolerance.");
cls_BRepMesh_DataStructureOfDelaun.def("ClearDomain", (void (BRepMesh_DataStructureOfDelaun::*)()) &BRepMesh_DataStructureOfDelaun::ClearDomain, "Removes all elements.");
cls_BRepMesh_DataStructureOfDelaun.def("ClearDeleted", (void (BRepMesh_DataStructureOfDelaun::*)()) &BRepMesh_DataStructureOfDelaun::ClearDeleted, "Substitutes deleted items by the last one from corresponding map to have only non-deleted elements, links or nodes in the structure.");
cls_BRepMesh_DataStructureOfDelaun.def_static("get_type_name_", (const char * (*)()) &BRepMesh_DataStructureOfDelaun::get_type_name, "None");
cls_BRepMesh_DataStructureOfDelaun.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_DataStructureOfDelaun::get_type_descriptor, "None");
cls_BRepMesh_DataStructureOfDelaun.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::DynamicType, "None");

// CLASS: BREPMESH_GEOMTOOL
py::class_<BRepMesh_GeomTool> cls_BRepMesh_GeomTool(mod, "BRepMesh_GeomTool", "Tool class accumulating common geometrical functions as well as functionality using shape geometry to produce data necessary for tessellation. General aim is to calculate discretization points for the given curve or iso curve of surface according to the specified parameters.");

// Constructors
cls_BRepMesh_GeomTool.def(py::init<const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"));
cls_BRepMesh_GeomTool.def(py::init<const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"));
cls_BRepMesh_GeomTool.def(py::init<const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"), py::arg("theMinSize"));
cls_BRepMesh_GeomTool.def(py::init<const opencascade::handle<BRepAdaptor_HSurface> &, const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theSurface"), py::arg("theIsoType"), py::arg("theParamIso"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"));
cls_BRepMesh_GeomTool.def(py::init<const opencascade::handle<BRepAdaptor_HSurface> &, const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theSurface"), py::arg("theIsoType"), py::arg("theParamIso"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"));
cls_BRepMesh_GeomTool.def(py::init<const opencascade::handle<BRepAdaptor_HSurface> &, const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theSurface"), py::arg("theIsoType"), py::arg("theParamIso"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"), py::arg("theMinSize"));

// Methods
// cls_BRepMesh_GeomTool.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_GeomTool::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_GeomTool.def_static("operator delete_", (void (*)(void *)) &BRepMesh_GeomTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_GeomTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_GeomTool::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_GeomTool.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_GeomTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_GeomTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_GeomTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_GeomTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_GeomTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_GeomTool.def("AddPoint", [](BRepMesh_GeomTool &self, const gp_Pnt & a0, const Standard_Real a1) -> Standard_Integer { return self.AddPoint(a0, a1); });
cls_BRepMesh_GeomTool.def("AddPoint", (Standard_Integer (BRepMesh_GeomTool::*)(const gp_Pnt &, const Standard_Real, const Standard_Boolean)) &BRepMesh_GeomTool::AddPoint, "Adds point to already calculated points (or replaces existing).", py::arg("thePoint"), py::arg("theParam"), py::arg("theIsReplace"));
cls_BRepMesh_GeomTool.def("NbPoints", (Standard_Integer (BRepMesh_GeomTool::*)() const) &BRepMesh_GeomTool::NbPoints, "Returns number of discretization points.");
cls_BRepMesh_GeomTool.def("Value", [](BRepMesh_GeomTool &self, const Standard_Integer theIndex, const Standard_Real theIsoParam, Standard_Real & theParam, gp_Pnt & thePoint, gp_Pnt2d & theUV){ Standard_Boolean rv = self.Value(theIndex, theIsoParam, theParam, thePoint, theUV); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParam); }, "Gets parameters of discretization point with the given index.", py::arg("theIndex"), py::arg("theIsoParam"), py::arg("theParam"), py::arg("thePoint"), py::arg("theUV"));
cls_BRepMesh_GeomTool.def("Value", [](BRepMesh_GeomTool &self, const Standard_Integer theIndex, const opencascade::handle<BRepAdaptor_HSurface> & theSurface, Standard_Real & theParam, gp_Pnt & thePoint, gp_Pnt2d & theUV){ Standard_Boolean rv = self.Value(theIndex, theSurface, theParam, thePoint, theUV); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParam); }, "Gets parameters of discretization point with the given index.", py::arg("theIndex"), py::arg("theSurface"), py::arg("theParam"), py::arg("thePoint"), py::arg("theUV"));
cls_BRepMesh_GeomTool.def_static("Normal_", (Standard_Boolean (*)(const opencascade::handle<BRepAdaptor_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Dir &)) &BRepMesh_GeomTool::Normal, "Computes normal to the given surface at the specified position in parametric space.", py::arg("theSurface"), py::arg("theParamU"), py::arg("theParamV"), py::arg("thePoint"), py::arg("theNormal"));
// cls_BRepMesh_GeomTool.def_static("IntLinLin_", (BRepMesh_GeomTool::IntFlag (*)(const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, gp_XY &, Standard_Real (&)[2])) &BRepMesh_GeomTool::IntLinLin, "Checks intersection between two lines defined by two points.", py::arg("theStartPnt1"), py::arg("theEndPnt1"), py::arg("theStartPnt2"), py::arg("theEndPnt2"), py::arg("theIntPnt"), py::arg("theParamOnSegment"));
cls_BRepMesh_GeomTool.def_static("IntSegSeg_", (BRepMesh_GeomTool::IntFlag (*)(const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, const Standard_Boolean, const Standard_Boolean, gp_Pnt2d &)) &BRepMesh_GeomTool::IntSegSeg, "Checks intersection between the two segments. Checks that intersection point lies within ranges of both segments.", py::arg("theStartPnt1"), py::arg("theEndPnt1"), py::arg("theStartPnt2"), py::arg("theEndPnt2"), py::arg("isConsiderEndPointTouch"), py::arg("isConsiderPointOnSegment"), py::arg("theIntPnt"));
cls_BRepMesh_GeomTool.def_static("SquareDeflectionOfSegment_", (Standard_Real (*)(const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &BRepMesh_GeomTool::SquareDeflectionOfSegment, "Compute deflection of the given segment.", py::arg("theFirstPoint"), py::arg("theLastPoint"), py::arg("theMidPoint"));
cls_BRepMesh_GeomTool.def_static("CellsCount_", (std::pair<Standard_Integer, Standard_Integer> (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Real, const BRepMesh_DefaultRangeSplitter *)) &BRepMesh_GeomTool::CellsCount, "None", py::arg("theSurface"), py::arg("theVerticesNb"), py::arg("theDeflection"), py::arg("theRangeSplitter"));

// Enums
py::enum_<BRepMesh_GeomTool::IntFlag>(cls_BRepMesh_GeomTool, "IntFlag", "Enumerates states of segments intersection check.")
	.value("NoIntersection", BRepMesh_GeomTool::IntFlag::NoIntersection)
	.value("Cross", BRepMesh_GeomTool::IntFlag::Cross)
	.value("EndPointTouch", BRepMesh_GeomTool::IntFlag::EndPointTouch)
	.value("PointOnSegment", BRepMesh_GeomTool::IntFlag::PointOnSegment)
	.value("Glued", BRepMesh_GeomTool::IntFlag::Glued)
	.value("Same", BRepMesh_GeomTool::IntFlag::Same)
	.export_values();

// CLASS: BREPMESH_DELAUN
py::class_<BRepMesh_Delaun> cls_BRepMesh_Delaun(mod, "BRepMesh_Delaun", "Compute the Delaunay's triangulation with the algorithm of Watson.");

// Constructors
cls_BRepMesh_Delaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("theOldMesh"), py::arg("theCellsCountU"), py::arg("theCellsCountV"), py::arg("isFillCircles"));
cls_BRepMesh_Delaun.def(py::init<IMeshData::Array1OfVertexOfDelaun &>(), py::arg("theVertices"));
cls_BRepMesh_Delaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &, IMeshData::Array1OfVertexOfDelaun &>(), py::arg("theOldMesh"), py::arg("theVertices"));
cls_BRepMesh_Delaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &, IMeshData::VectorOfInteger &>(), py::arg("theOldMesh"), py::arg("theVertexIndices"));
cls_BRepMesh_Delaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &, IMeshData::VectorOfInteger &, const Standard_Integer, const Standard_Integer>(), py::arg("theOldMesh"), py::arg("theVertexIndices"), py::arg("theCellsCountU"), py::arg("theCellsCountV"));

// Methods
// cls_BRepMesh_Delaun.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_Delaun::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_Delaun.def_static("operator delete_", (void (*)(void *)) &BRepMesh_Delaun::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_Delaun.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_Delaun::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_Delaun.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_Delaun::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_Delaun.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_Delaun::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_Delaun.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_Delaun::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_Delaun.def("Init", (void (BRepMesh_Delaun::*)(IMeshData::Array1OfVertexOfDelaun &)) &BRepMesh_Delaun::Init, "Initializes the triangulation with an array of vertices.", py::arg("theVertices"));
cls_BRepMesh_Delaun.def("InitCirclesTool", (void (BRepMesh_Delaun::*)(const Standard_Integer, const Standard_Integer)) &BRepMesh_Delaun::InitCirclesTool, "Forces initialization of circles cell filter using working structure.", py::arg("theCellsCountU"), py::arg("theCellsCountV"));
cls_BRepMesh_Delaun.def("RemoveVertex", (void (BRepMesh_Delaun::*)(const BRepMesh_Vertex &)) &BRepMesh_Delaun::RemoveVertex, "Removes a vertex from the triangulation.", py::arg("theVertex"));
cls_BRepMesh_Delaun.def("AddVertices", (void (BRepMesh_Delaun::*)(IMeshData::VectorOfInteger &)) &BRepMesh_Delaun::AddVertices, "Adds some vertices into the triangulation.", py::arg("theVerticesIndices"));
cls_BRepMesh_Delaun.def("UseEdge", (Standard_Boolean (BRepMesh_Delaun::*)(const Standard_Integer)) &BRepMesh_Delaun::UseEdge, "Modify mesh to use the edge.", py::arg("theEdge"));
cls_BRepMesh_Delaun.def("Result", (const opencascade::handle<BRepMesh_DataStructureOfDelaun> & (BRepMesh_Delaun::*)() const) &BRepMesh_Delaun::Result, "Gives the Mesh data structure.");
// cls_BRepMesh_Delaun.def("ProcessConstraints", (void (BRepMesh_Delaun::*)()) &BRepMesh_Delaun::ProcessConstraints, "Forces insertion of constraint edges into the base triangulation.");
// cls_BRepMesh_Delaun.def("Frontier", (opencascade::handle<IMeshData::MapOfInteger> (BRepMesh_Delaun::*)() const) &BRepMesh_Delaun::Frontier, "Gives the list of frontier edges.");
// cls_BRepMesh_Delaun.def("InternalEdges", (opencascade::handle<IMeshData::MapOfInteger> (BRepMesh_Delaun::*)() const) &BRepMesh_Delaun::InternalEdges, "Gives the list of internal edges.");
// cls_BRepMesh_Delaun.def("FreeEdges", (opencascade::handle<IMeshData::MapOfInteger> (BRepMesh_Delaun::*)() const) &BRepMesh_Delaun::FreeEdges, "Gives the list of free edges used only one time");
cls_BRepMesh_Delaun.def("GetVertex", (const BRepMesh_Vertex & (BRepMesh_Delaun::*)(const Standard_Integer) const) &BRepMesh_Delaun::GetVertex, "Gives vertex with the given index", py::arg("theIndex"));
cls_BRepMesh_Delaun.def("GetEdge", (const BRepMesh_Edge & (BRepMesh_Delaun::*)(const Standard_Integer) const) &BRepMesh_Delaun::GetEdge, "Gives edge with the given index", py::arg("theIndex"));
cls_BRepMesh_Delaun.def("GetTriangle", (const BRepMesh_Triangle & (BRepMesh_Delaun::*)(const Standard_Integer) const) &BRepMesh_Delaun::GetTriangle, "Gives triangle with the given index", py::arg("theIndex"));
cls_BRepMesh_Delaun.def("Circles", (const BRepMesh_CircleTool & (BRepMesh_Delaun::*)() const) &BRepMesh_Delaun::Circles, "Returns tool used to build mesh consistent to Delaunay criteria.");
cls_BRepMesh_Delaun.def("Contains", [](BRepMesh_Delaun &self, const Standard_Integer theTriangleId, const BRepMesh_Vertex & theVertex, const Standard_Real theSqTolerance, Standard_Integer & theEdgeOn){ Standard_Boolean rv = self.Contains(theTriangleId, theVertex, theSqTolerance, theEdgeOn); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theEdgeOn); }, "Test is the given triangle contains the given vertex.", py::arg("theTriangleId"), py::arg("theVertex"), py::arg("theSqTolerance"), py::arg("theEdgeOn"));

// CLASS: BREPMESH_MESHTOOL
py::class_<BRepMesh_MeshTool, opencascade::handle<BRepMesh_MeshTool>, Standard_Transient> cls_BRepMesh_MeshTool(mod, "BRepMesh_MeshTool", "Auxiliary tool providing API for manipulation with BRepMesh_DataStructureOfDelaun.");

// Constructors
cls_BRepMesh_MeshTool.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &>(), py::arg("theStructure"));

// Methods
cls_BRepMesh_MeshTool.def("GetStructure", (const opencascade::handle<BRepMesh_DataStructureOfDelaun> & (BRepMesh_MeshTool::*)() const) &BRepMesh_MeshTool::GetStructure, "Returns data structure manipulated by this tool.");
// cls_BRepMesh_MeshTool.def("DumpTriangles", (void (BRepMesh_MeshTool::*)(const Standard_CString, IMeshData::MapOfInteger *)) &BRepMesh_MeshTool::DumpTriangles, "Dumps triangles to specified file.", py::arg("theFileName"), py::arg("theTriangles"));
cls_BRepMesh_MeshTool.def("AddAndLegalizeTriangle", (void (BRepMesh_MeshTool::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &BRepMesh_MeshTool::AddAndLegalizeTriangle, "Adds new triangle with specified nodes to mesh. Legalizes triangle in case if it violates circle criteria.", py::arg("thePoint1"), py::arg("thePoint2"), py::arg("thePoint3"));
// cls_BRepMesh_MeshTool.def("AddTriangle", (void (BRepMesh_MeshTool::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, Standard_Integer (&)[3])) &BRepMesh_MeshTool::AddTriangle, "Adds new triangle with specified nodes to mesh.", py::arg("thePoint1"), py::arg("thePoint2"), py::arg("thePoint3"), py::arg("theEdges"));
cls_BRepMesh_MeshTool.def("AddLink", [](BRepMesh_MeshTool &self, const Standard_Integer theFirstNode, const Standard_Integer theLastNode, Standard_Integer & theLinkIndex, Standard_Boolean & theLinkOri){ self.AddLink(theFirstNode, theLastNode, theLinkIndex, theLinkOri); return std::tuple<Standard_Integer &, Standard_Boolean &>(theLinkIndex, theLinkOri); }, "Adds new link to mesh. Updates link index and link orientaion parameters.", py::arg("theFirstNode"), py::arg("theLastNode"), py::arg("theLinkIndex"), py::arg("theLinkOri"));
cls_BRepMesh_MeshTool.def("Legalize", (void (BRepMesh_MeshTool::*)(const Standard_Integer)) &BRepMesh_MeshTool::Legalize, "Performs legalization of triangles connected to the specified link.", py::arg("theLinkIndex"));
cls_BRepMesh_MeshTool.def("EraseItemsConnectedTo", (void (BRepMesh_MeshTool::*)(const Standard_Integer)) &BRepMesh_MeshTool::EraseItemsConnectedTo, "Erases all elements connected to the specified artificial node. In addition, erases the artificial node itself.", py::arg("theNodeIndex"));
cls_BRepMesh_MeshTool.def("CleanFrontierLinks", (void (BRepMesh_MeshTool::*)()) &BRepMesh_MeshTool::CleanFrontierLinks, "Cleans frontier links from triangles to the right.");
// cls_BRepMesh_MeshTool.def("EraseTriangles", (void (BRepMesh_MeshTool::*)(const IMeshData::MapOfInteger &, IMeshData::MapOfIntegerInteger &)) &BRepMesh_MeshTool::EraseTriangles, "Erases the given set of triangles. Fills map of loop edges forming the countour surrounding the erased triangles.", py::arg("theTriangles"), py::arg("theLoopEdges"));
cls_BRepMesh_MeshTool.def("EraseTriangle", (void (BRepMesh_MeshTool::*)(const Standard_Integer, IMeshData::MapOfIntegerInteger &)) &BRepMesh_MeshTool::EraseTriangle, "Erases triangle with the given index and adds the free edges into the map. When an edge is suppressed more than one time it is destroyed.", py::arg("theTriangleIndex"), py::arg("theLoopEdges"));
cls_BRepMesh_MeshTool.def("EraseFreeLinks", (void (BRepMesh_MeshTool::*)()) &BRepMesh_MeshTool::EraseFreeLinks, "Erases all links that have no elements connected to them.");
cls_BRepMesh_MeshTool.def("EraseFreeLinks", (void (BRepMesh_MeshTool::*)(const IMeshData::MapOfIntegerInteger &)) &BRepMesh_MeshTool::EraseFreeLinks, "Erases links from the specified map that have no elements connected to them.", py::arg("theLinks"));
cls_BRepMesh_MeshTool.def("GetEdgesByType", (opencascade::handle<IMeshData::MapOfInteger> (BRepMesh_MeshTool::*)(const BRepMesh_DegreeOfFreedom) const) &BRepMesh_MeshTool::GetEdgesByType, "Gives the list of edges with type defined by input parameter.", py::arg("theEdgeType"));
cls_BRepMesh_MeshTool.def_static("get_type_name_", (const char * (*)()) &BRepMesh_MeshTool::get_type_name, "None");
cls_BRepMesh_MeshTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_MeshTool::get_type_descriptor, "None");
cls_BRepMesh_MeshTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_MeshTool::*)() const) &BRepMesh_MeshTool::DynamicType, "None");

// CLASS: BREPMESH_CYLINDERRANGESPLITTER
/*
py::class_<BRepMesh_CylinderRangeSplitter> cls_BRepMesh_CylinderRangeSplitter(mod, "BRepMesh_CylinderRangeSplitter", "Auxiliary class extending default range splitter in order to generate internal nodes for cylindrical surface.");

// Constructors
cls_BRepMesh_CylinderRangeSplitter.def(py::init<>());

// Methods
cls_BRepMesh_CylinderRangeSplitter.def("Reset", (void (BRepMesh_CylinderRangeSplitter::*)(const IMeshData::IFaceHandle &, const IMeshTools_Parameters &)) &BRepMesh_CylinderRangeSplitter::Reset, "Resets this splitter. Must be called before first use.", py::arg("theDFace"), py::arg("theParameters"));
cls_BRepMesh_CylinderRangeSplitter.def("GenerateSurfaceNodes", (opencascade::handle<IMeshData::ListOfPnt2d> (BRepMesh_CylinderRangeSplitter::*)(const IMeshTools_Parameters &) const) &BRepMesh_CylinderRangeSplitter::GenerateSurfaceNodes, "Returns list of nodes generated using surface data and specified parameters.", py::arg("theParameters"));
*/

// CLASS: BREPMESH_DEFLECTION
py::class_<BRepMesh_Deflection, opencascade::handle<BRepMesh_Deflection>, Standard_Transient> cls_BRepMesh_Deflection(mod, "BRepMesh_Deflection", "Auxiliary tool encompassing methods to compute deflection of shapes.");

// Constructors
cls_BRepMesh_Deflection.def(py::init<>());

// Methods
cls_BRepMesh_Deflection.def_static("ComputeAbsoluteDeflection_", (Standard_Real (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real)) &BRepMesh_Deflection::ComputeAbsoluteDeflection, "Returns absolute deflection for theShape with respect to the relative deflection and theMaxShapeSize.", py::arg("theShape"), py::arg("theRelativeDeflection"), py::arg("theMaxShapeSize"));
cls_BRepMesh_Deflection.def_static("ComputeDeflection_", (void (*)(const IMeshData::IEdgeHandle &, const Standard_Real, const IMeshTools_Parameters &)) &BRepMesh_Deflection::ComputeDeflection, "Computes and updates deflection of the given discrete edge.", py::arg("theDEdge"), py::arg("theMaxShapeSize"), py::arg("theParameters"));
cls_BRepMesh_Deflection.def_static("ComputeDeflection_", (void (*)(const IMeshData::IWireHandle &, const IMeshTools_Parameters &)) &BRepMesh_Deflection::ComputeDeflection, "Computes and updates deflection of the given discrete wire.", py::arg("theDWire"), py::arg("theParameters"));
cls_BRepMesh_Deflection.def_static("ComputeDeflection_", (void (*)(const IMeshData::IFaceHandle &, const IMeshTools_Parameters &)) &BRepMesh_Deflection::ComputeDeflection, "Computes and updates deflection of the given discrete face.", py::arg("theDFace"), py::arg("theParameters"));
cls_BRepMesh_Deflection.def_static("get_type_name_", (const char * (*)()) &BRepMesh_Deflection::get_type_name, "None");
cls_BRepMesh_Deflection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_Deflection::get_type_descriptor, "None");
cls_BRepMesh_Deflection.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_Deflection::*)() const) &BRepMesh_Deflection::DynamicType, "None");

// CLASS: BREPMESH_DELAUNAYBASEMESHALGO
py::class_<BRepMesh_DelaunayBaseMeshAlgo, opencascade::handle<BRepMesh_DelaunayBaseMeshAlgo>, BRepMesh_ConstrainedBaseMeshAlgo> cls_BRepMesh_DelaunayBaseMeshAlgo(mod, "BRepMesh_DelaunayBaseMeshAlgo", "Class provides base fuctionality to build face triangulation using Dealunay approach. Performs generation of mesh using raw data from model.");

// Constructors
cls_BRepMesh_DelaunayBaseMeshAlgo.def(py::init<>());

// Methods
cls_BRepMesh_DelaunayBaseMeshAlgo.def_static("get_type_name_", (const char * (*)()) &BRepMesh_DelaunayBaseMeshAlgo::get_type_name, "None");
cls_BRepMesh_DelaunayBaseMeshAlgo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_DelaunayBaseMeshAlgo::get_type_descriptor, "None");
cls_BRepMesh_DelaunayBaseMeshAlgo.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_DelaunayBaseMeshAlgo::*)() const) &BRepMesh_DelaunayBaseMeshAlgo::DynamicType, "None");

// TYPEDEF: BREPMESH_PLUGINENTRYTYPE

// CLASS: BREPMESH_DISCRETROOT
py::class_<BRepMesh_DiscretRoot, opencascade::handle<BRepMesh_DiscretRoot>, Standard_Transient> cls_BRepMesh_DiscretRoot(mod, "BRepMesh_DiscretRoot", "This is a common interface for meshing algorithms instantiated by Mesh Factory and implemented by plugins.");

// Methods
cls_BRepMesh_DiscretRoot.def("SetShape", (void (BRepMesh_DiscretRoot::*)(const TopoDS_Shape &)) &BRepMesh_DiscretRoot::SetShape, "Set the shape to triangulate.", py::arg("theShape"));
cls_BRepMesh_DiscretRoot.def("Shape", (const TopoDS_Shape & (BRepMesh_DiscretRoot::*)() const) &BRepMesh_DiscretRoot::Shape, "None");
cls_BRepMesh_DiscretRoot.def("IsDone", (Standard_Boolean (BRepMesh_DiscretRoot::*)() const) &BRepMesh_DiscretRoot::IsDone, "Returns true if triangualtion was performed and has success.");
cls_BRepMesh_DiscretRoot.def("Perform", (void (BRepMesh_DiscretRoot::*)()) &BRepMesh_DiscretRoot::Perform, "Compute triangulation for set shape.");
cls_BRepMesh_DiscretRoot.def_static("get_type_name_", (const char * (*)()) &BRepMesh_DiscretRoot::get_type_name, "None");
cls_BRepMesh_DiscretRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_DiscretRoot::get_type_descriptor, "None");
cls_BRepMesh_DiscretRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_DiscretRoot::*)() const) &BRepMesh_DiscretRoot::DynamicType, "None");

// CLASS: BREPMESH_DISCRETFACTORY
py::class_<BRepMesh_DiscretFactory, std::unique_ptr<BRepMesh_DiscretFactory, py::nodelete>> cls_BRepMesh_DiscretFactory(mod, "BRepMesh_DiscretFactory", "This class intended to setup / retrieve default triangulation algorithm. Use BRepMesh_DiscretFactory::Get() static method to retrieve global Factory instance. Use BRepMesh_DiscretFactory::Discret() method to retrieve meshing tool.");

// Methods
// cls_BRepMesh_DiscretFactory.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_DiscretFactory::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_DiscretFactory.def_static("operator delete_", (void (*)(void *)) &BRepMesh_DiscretFactory::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_DiscretFactory.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_DiscretFactory::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_DiscretFactory.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_DiscretFactory::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_DiscretFactory.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_DiscretFactory::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_DiscretFactory.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_DiscretFactory::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_DiscretFactory.def_static("Get_", (BRepMesh_DiscretFactory & (*)()) &BRepMesh_DiscretFactory::Get, "Returns the global factory instance.");
cls_BRepMesh_DiscretFactory.def("Names", (const TColStd_MapOfAsciiString & (BRepMesh_DiscretFactory::*)() const) &BRepMesh_DiscretFactory::Names, "Returns the list of registered meshing algorithms.");
cls_BRepMesh_DiscretFactory.def("SetDefaultName", (Standard_Boolean (BRepMesh_DiscretFactory::*)(const TCollection_AsciiString &)) &BRepMesh_DiscretFactory::SetDefaultName, "Setup meshing algorithm by name. Returns TRUE if requested tool is available. On fail Factory will continue to use previous algo.", py::arg("theName"));
cls_BRepMesh_DiscretFactory.def("DefaultName", (const TCollection_AsciiString & (BRepMesh_DiscretFactory::*)() const) &BRepMesh_DiscretFactory::DefaultName, "Returns name for current meshing algorithm.");
cls_BRepMesh_DiscretFactory.def("SetFunctionName", (Standard_Boolean (BRepMesh_DiscretFactory::*)(const TCollection_AsciiString &)) &BRepMesh_DiscretFactory::SetFunctionName, "Advanced function. Changes function name to retrieve from plugin. Returns TRUE if requested tool is available. On fail Factory will continue to use previous algo.", py::arg("theFuncName"));
cls_BRepMesh_DiscretFactory.def("FunctionName", (const TCollection_AsciiString & (BRepMesh_DiscretFactory::*)() const) &BRepMesh_DiscretFactory::FunctionName, "Returns function name that should be exported by plugin.");
cls_BRepMesh_DiscretFactory.def("ErrorStatus", (BRepMesh_FactoryError (BRepMesh_DiscretFactory::*)() const) &BRepMesh_DiscretFactory::ErrorStatus, "Returns error status for last meshing algorithm switch.");
cls_BRepMesh_DiscretFactory.def("SetDefault", [](BRepMesh_DiscretFactory &self, const TCollection_AsciiString & a0) -> Standard_Boolean { return self.SetDefault(a0); });
cls_BRepMesh_DiscretFactory.def("SetDefault", (Standard_Boolean (BRepMesh_DiscretFactory::*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &BRepMesh_DiscretFactory::SetDefault, "Setup meshing algorithm that should be created by this Factory. Returns TRUE if requested tool is available. On fail Factory will continue to use previous algo. Call ::ErrorStatus() method to retrieve fault reason.", py::arg("theName"), py::arg("theFuncName"));
cls_BRepMesh_DiscretFactory.def("Discret", (opencascade::handle<BRepMesh_DiscretRoot> (BRepMesh_DiscretFactory::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real)) &BRepMesh_DiscretFactory::Discret, "Returns triangulation algorithm instance.", py::arg("theShape"), py::arg("theLinDeflection"), py::arg("theAngDeflection"));

// CLASS: BREPMESH_EDGEDISCRET
py::class_<BRepMesh_EdgeDiscret, opencascade::handle<BRepMesh_EdgeDiscret>, IMeshTools_ModelAlgo> cls_BRepMesh_EdgeDiscret(mod, "BRepMesh_EdgeDiscret", "Class implements functionality of edge discret tool. Performs check of the edges for existing Poly_PolygonOnTriangulation. In case if it fits specified deflection, restores data structure using it, else clears edges from outdated data.");

// Constructors
cls_BRepMesh_EdgeDiscret.def(py::init<>());

// Methods
cls_BRepMesh_EdgeDiscret.def_static("CreateEdgeTessellator_", (opencascade::handle<IMeshTools_CurveTessellator> (*)(const IMeshData::IEdgeHandle &, const IMeshTools_Parameters &)) &BRepMesh_EdgeDiscret::CreateEdgeTessellator, "Creates instance of free edge tessellator.", py::arg("theDEdge"), py::arg("theParameters"));
cls_BRepMesh_EdgeDiscret.def_static("CreateEdgeTessellator_", (opencascade::handle<IMeshTools_CurveTessellator> (*)(const IMeshData::IEdgeHandle &, const TopAbs_Orientation, const IMeshData::IFaceHandle &, const IMeshTools_Parameters &)) &BRepMesh_EdgeDiscret::CreateEdgeTessellator, "Creates instance of edge tessellator.", py::arg("theDEdge"), py::arg("theOrientation"), py::arg("theDFace"), py::arg("theParameters"));
cls_BRepMesh_EdgeDiscret.def_static("CreateEdgeTessellationExtractor_", (opencascade::handle<IMeshTools_CurveTessellator> (*)(const IMeshData::IEdgeHandle &, const IMeshData::IFaceHandle &)) &BRepMesh_EdgeDiscret::CreateEdgeTessellationExtractor, "Creates instance of tessellation extractor.", py::arg("theDEdge"), py::arg("theDFace"));
// cls_BRepMesh_EdgeDiscret.def("__call__", (void (BRepMesh_EdgeDiscret::*)(const Standard_Integer) const) &BRepMesh_EdgeDiscret::operator(), py::is_operator(), "Functor API to discretize the given edge.", py::arg("theEdgeIndex"));
cls_BRepMesh_EdgeDiscret.def_static("Tessellate3d_", (void (*)(const IMeshData::IEdgeHandle &, const opencascade::handle<IMeshTools_CurveTessellator> &, const Standard_Boolean)) &BRepMesh_EdgeDiscret::Tessellate3d, "Updates 3d discrete edge model using the given tessellation tool.", py::arg("theDEdge"), py::arg("theTessellator"), py::arg("theUpdateEnds"));
cls_BRepMesh_EdgeDiscret.def_static("Tessellate2d_", (void (*)(const IMeshData::IEdgeHandle &, const Standard_Boolean)) &BRepMesh_EdgeDiscret::Tessellate2d, "Updates 2d discrete edge model using tessellation of 3D curve.", py::arg("theDEdge"), py::arg("theUpdateEnds"));
cls_BRepMesh_EdgeDiscret.def_static("get_type_name_", (const char * (*)()) &BRepMesh_EdgeDiscret::get_type_name, "None");
cls_BRepMesh_EdgeDiscret.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_EdgeDiscret::get_type_descriptor, "None");
cls_BRepMesh_EdgeDiscret.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_EdgeDiscret::*)() const) &BRepMesh_EdgeDiscret::DynamicType, "None");

// CLASS: BREPMESH_EDGETESSELLATIONEXTRACTOR
py::class_<BRepMesh_EdgeTessellationExtractor, opencascade::handle<BRepMesh_EdgeTessellationExtractor>, IMeshTools_CurveTessellator> cls_BRepMesh_EdgeTessellationExtractor(mod, "BRepMesh_EdgeTessellationExtractor", "Auxiliary class implements functionality retrieving tessellated representation of an edge stored in polygon.");

// Constructors
// cls_BRepMesh_EdgeTessellationExtractor.def(py::init<const IMeshData::IEdgeHandle &, const IMeshData::IFaceHandle &>(), py::arg("theEdge"), py::arg("theFace"));

// Methods
cls_BRepMesh_EdgeTessellationExtractor.def("PointsNb", (Standard_Integer (BRepMesh_EdgeTessellationExtractor::*)() const) &BRepMesh_EdgeTessellationExtractor::PointsNb, "Returns number of tessellation points.");
cls_BRepMesh_EdgeTessellationExtractor.def("Value", [](BRepMesh_EdgeTessellationExtractor &self, const Standard_Integer theIndex, gp_Pnt & thePoint, Standard_Real & theParameter){ Standard_Boolean rv = self.Value(theIndex, thePoint, theParameter); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParameter); }, "Returns parameters of solution with the given index.", py::arg("theIndex"), py::arg("thePoint"), py::arg("theParameter"));
cls_BRepMesh_EdgeTessellationExtractor.def_static("get_type_name_", (const char * (*)()) &BRepMesh_EdgeTessellationExtractor::get_type_name, "None");
cls_BRepMesh_EdgeTessellationExtractor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_EdgeTessellationExtractor::get_type_descriptor, "None");
cls_BRepMesh_EdgeTessellationExtractor.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_EdgeTessellationExtractor::*)() const) &BRepMesh_EdgeTessellationExtractor::DynamicType, "None");

// CLASS: BREPMESH_FACECHECKER
py::class_<BRepMesh_FaceChecker, opencascade::handle<BRepMesh_FaceChecker>, Standard_Transient> cls_BRepMesh_FaceChecker(mod, "BRepMesh_FaceChecker", "Auxiliary class checking wires of target face for self-intersections. Explodes wires of discrete face on sets of segments using tessellation data stored in model. Each segment is then checked for intersection with other ones. All collisions are registerd and returned as result of check.");

// Constructors
cls_BRepMesh_FaceChecker.def(py::init<const IMeshData::IFaceHandle &, const IMeshTools_Parameters &>(), py::arg("theFace"), py::arg("theParameters"));

// Methods
cls_BRepMesh_FaceChecker.def("Perform", (Standard_Boolean (BRepMesh_FaceChecker::*)()) &BRepMesh_FaceChecker::Perform, "Performs check wires of the face for intersections.");
cls_BRepMesh_FaceChecker.def("GetIntersectingEdges", (const opencascade::handle<IMeshData::MapOfIEdgePtr> & (BRepMesh_FaceChecker::*)() const) &BRepMesh_FaceChecker::GetIntersectingEdges, "Returns intersecting edges.");
// cls_BRepMesh_FaceChecker.def("__call__", (void (BRepMesh_FaceChecker::*)(const Standard_Integer) const) &BRepMesh_FaceChecker::operator(), py::is_operator(), "Checks wire with the given index for intersection with others.", py::arg("theWireIndex"));
cls_BRepMesh_FaceChecker.def_static("get_type_name_", (const char * (*)()) &BRepMesh_FaceChecker::get_type_name, "None");
cls_BRepMesh_FaceChecker.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_FaceChecker::get_type_descriptor, "None");
cls_BRepMesh_FaceChecker.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_FaceChecker::*)() const) &BRepMesh_FaceChecker::DynamicType, "None");

// CLASS: BREPMESH_FACEDISCRET
py::class_<BRepMesh_FaceDiscret, opencascade::handle<BRepMesh_FaceDiscret>, IMeshTools_ModelAlgo> cls_BRepMesh_FaceDiscret(mod, "BRepMesh_FaceDiscret", "Class implements functionality starting triangulation of model's faces. Each face is processed separately and can be executed in parallel mode. Uses mesh algo factory passed as initializer to create instance of triangulation algorithm according to type of surface of target face.");

// Constructors
cls_BRepMesh_FaceDiscret.def(py::init<const opencascade::handle<IMeshTools_MeshAlgoFactory> &>(), py::arg("theAlgoFactory"));

// Methods
// cls_BRepMesh_FaceDiscret.def("__call__", (void (BRepMesh_FaceDiscret::*)(const Standard_Integer) const) &BRepMesh_FaceDiscret::operator(), py::is_operator(), "Functor API to discretize the given edge.", py::arg("theFaceIndex"));
cls_BRepMesh_FaceDiscret.def_static("get_type_name_", (const char * (*)()) &BRepMesh_FaceDiscret::get_type_name, "None");
cls_BRepMesh_FaceDiscret.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_FaceDiscret::get_type_descriptor, "None");
cls_BRepMesh_FaceDiscret.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_FaceDiscret::*)() const) &BRepMesh_FaceDiscret::DynamicType, "None");

// CLASS: BREPMESH_FASTDISCRET
py::class_<BRepMesh_FastDiscret> cls_BRepMesh_FastDiscret(mod, "BRepMesh_FastDiscret", "None");

// Constructors
cls_BRepMesh_FastDiscret.def(py::init<>());

// CLASS: BREPMESH_INCREMENTALMESH
py::class_<BRepMesh_IncrementalMesh, opencascade::handle<BRepMesh_IncrementalMesh>, BRepMesh_DiscretRoot> cls_BRepMesh_IncrementalMesh(mod, "BRepMesh_IncrementalMesh", "Builds the mesh of a shape with respect of their correctly triangulated parts");

// Constructors
cls_BRepMesh_IncrementalMesh.def(py::init<>());
cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("theShape"), py::arg("theLinDeflection"));
cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean>(), py::arg("theShape"), py::arg("theLinDeflection"), py::arg("isRelative"));
cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("theShape"), py::arg("theLinDeflection"), py::arg("isRelative"), py::arg("theAngDeflection"));
cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Boolean>(), py::arg("theShape"), py::arg("theLinDeflection"), py::arg("isRelative"), py::arg("theAngDeflection"), py::arg("isInParallel"));
cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const IMeshTools_Parameters &>(), py::arg("theShape"), py::arg("theParameters"));

// Methods
cls_BRepMesh_IncrementalMesh.def("Perform", (void (BRepMesh_IncrementalMesh::*)()) &BRepMesh_IncrementalMesh::Perform, "Performs meshing ot the shape.");
cls_BRepMesh_IncrementalMesh.def("Perform", (void (BRepMesh_IncrementalMesh::*)(const opencascade::handle<IMeshTools_Context> &)) &BRepMesh_IncrementalMesh::Perform, "Performs meshing using custom context;", py::arg("theContext"));
cls_BRepMesh_IncrementalMesh.def("Parameters", (const IMeshTools_Parameters & (BRepMesh_IncrementalMesh::*)() const) &BRepMesh_IncrementalMesh::Parameters, "Returns meshing parameters");
cls_BRepMesh_IncrementalMesh.def("ChangeParameters", (IMeshTools_Parameters & (BRepMesh_IncrementalMesh::*)()) &BRepMesh_IncrementalMesh::ChangeParameters, "Returns modifiable meshing parameters");
cls_BRepMesh_IncrementalMesh.def("IsModified", (Standard_Boolean (BRepMesh_IncrementalMesh::*)() const) &BRepMesh_IncrementalMesh::IsModified, "Returns modified flag.");
cls_BRepMesh_IncrementalMesh.def("GetStatusFlags", (Standard_Integer (BRepMesh_IncrementalMesh::*)() const) &BRepMesh_IncrementalMesh::GetStatusFlags, "Returns accumulated status flags faced during meshing.");
// cls_BRepMesh_IncrementalMesh.def_static("Discret_", (Standard_Integer (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, BRepMesh_DiscretRoot *&)) &BRepMesh_IncrementalMesh::Discret, "Plugin interface for the Mesh Factories. Initializes meshing algorithm with the given parameters.", py::arg("theShape"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theAlgo"));
cls_BRepMesh_IncrementalMesh.def_static("IsParallelDefault_", (Standard_Boolean (*)()) &BRepMesh_IncrementalMesh::IsParallelDefault, "Returns multi-threading usage flag set by default in Discret() static method (thus applied only to Mesh Factories).");
cls_BRepMesh_IncrementalMesh.def_static("SetParallelDefault_", (void (*)(const Standard_Boolean)) &BRepMesh_IncrementalMesh::SetParallelDefault, "Setup multi-threading usage flag set by default in Discret() static method (thus applied only to Mesh Factories).", py::arg("isInParallel"));
cls_BRepMesh_IncrementalMesh.def_static("get_type_name_", (const char * (*)()) &BRepMesh_IncrementalMesh::get_type_name, "None");
cls_BRepMesh_IncrementalMesh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_IncrementalMesh::get_type_descriptor, "None");
cls_BRepMesh_IncrementalMesh.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_IncrementalMesh::*)() const) &BRepMesh_IncrementalMesh::DynamicType, "None");

// CLASS: BREPMESH_MESHALGOFACTORY
py::class_<BRepMesh_MeshAlgoFactory, opencascade::handle<BRepMesh_MeshAlgoFactory>, IMeshTools_MeshAlgoFactory> cls_BRepMesh_MeshAlgoFactory(mod, "BRepMesh_MeshAlgoFactory", "Default implementation of IMeshTools_MeshAlgoFactory providing algorithms of different compexity depending on type of target surface.");

// Constructors
cls_BRepMesh_MeshAlgoFactory.def(py::init<>());

// Methods
cls_BRepMesh_MeshAlgoFactory.def("GetAlgo", (opencascade::handle<IMeshTools_MeshAlgo> (BRepMesh_MeshAlgoFactory::*)(const GeomAbs_SurfaceType, const IMeshTools_Parameters &) const) &BRepMesh_MeshAlgoFactory::GetAlgo, "Creates instance of meshing algorithm for the given type of surface.", py::arg("theSurfaceType"), py::arg("theParameters"));
cls_BRepMesh_MeshAlgoFactory.def_static("get_type_name_", (const char * (*)()) &BRepMesh_MeshAlgoFactory::get_type_name, "None");
cls_BRepMesh_MeshAlgoFactory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_MeshAlgoFactory::get_type_descriptor, "None");
cls_BRepMesh_MeshAlgoFactory.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_MeshAlgoFactory::*)() const) &BRepMesh_MeshAlgoFactory::DynamicType, "None");

// CLASS: BREPMESH_MODELBUILDER
py::class_<BRepMesh_ModelBuilder, opencascade::handle<BRepMesh_ModelBuilder>, IMeshTools_ModelBuilder> cls_BRepMesh_ModelBuilder(mod, "BRepMesh_ModelBuilder", "Class implements interface representing tool for discrete model building.");

// Constructors
cls_BRepMesh_ModelBuilder.def(py::init<>());

// Methods
cls_BRepMesh_ModelBuilder.def_static("get_type_name_", (const char * (*)()) &BRepMesh_ModelBuilder::get_type_name, "None");
cls_BRepMesh_ModelBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_ModelBuilder::get_type_descriptor, "None");
cls_BRepMesh_ModelBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_ModelBuilder::*)() const) &BRepMesh_ModelBuilder::DynamicType, "None");

// CLASS: BREPMESH_MODELHEALER
py::class_<BRepMesh_ModelHealer, opencascade::handle<BRepMesh_ModelHealer>, IMeshTools_ModelAlgo> cls_BRepMesh_ModelHealer(mod, "BRepMesh_ModelHealer", "Class implements functionality of model healer tool. Iterates over model's faces and checks consistency of their wires, i.e.whether wires are closed and do not contain self - intersections. In case if wire contains disconnected parts, ends of adjacent edges forming the gaps are connected in parametric space forcibly. The notion of this operation is to create correct discrete model defined relatively parametric space of target face taking into account connectivity and tolerances of 3D space only. This means that there are no specific computations are made for the sake of determination of U and V tolerance. Registers intersections on edges forming the face's shape and tries to amplify discrete represenation by decreasing of deflection for the target edge. Checks can be performed in parallel mode.");

// Constructors
cls_BRepMesh_ModelHealer.def(py::init<>());

// Methods
// cls_BRepMesh_ModelHealer.def("__call__", (void (BRepMesh_ModelHealer::*)(const Standard_Integer) const) &BRepMesh_ModelHealer::operator(), py::is_operator(), "Functor API to discretize the given edge.", py::arg("theEdgeIndex"));
// cls_BRepMesh_ModelHealer.def("__call__", (void (BRepMesh_ModelHealer::*)(const IMeshData::IFaceHandle &) const) &BRepMesh_ModelHealer::operator(), py::is_operator(), "Functor API to discretize the given edge.", py::arg("theDFace"));
cls_BRepMesh_ModelHealer.def_static("get_type_name_", (const char * (*)()) &BRepMesh_ModelHealer::get_type_name, "None");
cls_BRepMesh_ModelHealer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_ModelHealer::get_type_descriptor, "None");
cls_BRepMesh_ModelHealer.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_ModelHealer::*)() const) &BRepMesh_ModelHealer::DynamicType, "None");

// CLASS: BREPMESH_MODELPOSTPROCESSOR
py::class_<BRepMesh_ModelPostProcessor, opencascade::handle<BRepMesh_ModelPostProcessor>, IMeshTools_ModelAlgo> cls_BRepMesh_ModelPostProcessor(mod, "BRepMesh_ModelPostProcessor", "Class implements functionality of model post-processing tool. Stores polygons on triangulations to TopoDS_Edge.");

// Constructors
cls_BRepMesh_ModelPostProcessor.def(py::init<>());

// Methods
cls_BRepMesh_ModelPostProcessor.def_static("get_type_name_", (const char * (*)()) &BRepMesh_ModelPostProcessor::get_type_name, "None");
cls_BRepMesh_ModelPostProcessor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_ModelPostProcessor::get_type_descriptor, "None");
cls_BRepMesh_ModelPostProcessor.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_ModelPostProcessor::*)() const) &BRepMesh_ModelPostProcessor::DynamicType, "None");

// CLASS: BREPMESH_MODELPREPROCESSOR
py::class_<BRepMesh_ModelPreProcessor, opencascade::handle<BRepMesh_ModelPreProcessor>, IMeshTools_ModelAlgo> cls_BRepMesh_ModelPreProcessor(mod, "BRepMesh_ModelPreProcessor", "Class implements functionality of model pre-processing tool. Nullifies existing polygonal data in case if model elements have IMeshData_Outdated status.");

// Constructors
cls_BRepMesh_ModelPreProcessor.def(py::init<>());

// Methods
cls_BRepMesh_ModelPreProcessor.def_static("get_type_name_", (const char * (*)()) &BRepMesh_ModelPreProcessor::get_type_name, "None");
cls_BRepMesh_ModelPreProcessor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_ModelPreProcessor::get_type_descriptor, "None");
cls_BRepMesh_ModelPreProcessor.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_ModelPreProcessor::*)() const) &BRepMesh_ModelPreProcessor::DynamicType, "None");

// CLASS: BREPMESH_SELECTOROFDATASTRUCTUREOFDELAUN
py::class_<BRepMesh_SelectorOfDataStructureOfDelaun, opencascade::handle<BRepMesh_SelectorOfDataStructureOfDelaun>, Standard_Transient> cls_BRepMesh_SelectorOfDataStructureOfDelaun(mod, "BRepMesh_SelectorOfDataStructureOfDelaun", "Describes a selector and an iterator on a selector of components of a mesh.");

// Constructors
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def(py::init<>());
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &>(), py::arg("theMesh"));

// Methods
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
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("Nodes", (const IMeshData::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const) &BRepMesh_SelectorOfDataStructureOfDelaun::Nodes, "Returns selected nodes.");
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("Links", (const IMeshData::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const) &BRepMesh_SelectorOfDataStructureOfDelaun::Links, "Returns selected links.");
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("Elements", (const IMeshData::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const) &BRepMesh_SelectorOfDataStructureOfDelaun::Elements, "Returns selected elements.");
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("FrontierLinks", (const IMeshData::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const) &BRepMesh_SelectorOfDataStructureOfDelaun::FrontierLinks, "Gives the list of incices of frontier links.");
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def_static("get_type_name_", (const char * (*)()) &BRepMesh_SelectorOfDataStructureOfDelaun::get_type_name, "None");
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_SelectorOfDataStructureOfDelaun::get_type_descriptor, "None");
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const) &BRepMesh_SelectorOfDataStructureOfDelaun::DynamicType, "None");

// CLASS: BREPMESH_SHAPETOOL
py::class_<BRepMesh_ShapeTool, opencascade::handle<BRepMesh_ShapeTool>, Standard_Transient> cls_BRepMesh_ShapeTool(mod, "BRepMesh_ShapeTool", "Auxiliary class providing functionality to compute, retrieve and store data to TopoDS and model shape.");

// Constructors
cls_BRepMesh_ShapeTool.def(py::init<>());

// Methods
cls_BRepMesh_ShapeTool.def_static("MaxFaceTolerance_", (Standard_Real (*)(const TopoDS_Face &)) &BRepMesh_ShapeTool::MaxFaceTolerance, "Returns maximum tolerance of the given face. Considers tolerances of edges and vertices contained in the given face.", py::arg("theFace"));
cls_BRepMesh_ShapeTool.def_static("BoxMaxDimension_", [](const Bnd_Box & theBox, Standard_Real & theMaxDimension){ BRepMesh_ShapeTool::BoxMaxDimension(theBox, theMaxDimension); return theMaxDimension; }, "Gets the maximum dimension of the given bounding box. If the given bounding box is void leaves the resulting value unchanged.", py::arg("theBox"), py::arg("theMaxDimension"));
cls_BRepMesh_ShapeTool.def_static("CheckAndUpdateFlags_", (void (*)(const IMeshData::IEdgeHandle &, const IMeshData::IPCurveHandle &)) &BRepMesh_ShapeTool::CheckAndUpdateFlags, "Checks same parameter, same range and degenerativity attributes using geometrical data of the given edge and updates edge model by computed parameters in case of worst case - it can drop flags same parameter and same range to False but never to True if it is already set to False. In contrary, it can also drop degenerated flag to True, but never to False if it is already set to True.", py::arg("theEdge"), py::arg("thePCurve"));
cls_BRepMesh_ShapeTool.def_static("AddInFace_", (void (*)(const TopoDS_Face &, opencascade::handle<Poly_Triangulation> &)) &BRepMesh_ShapeTool::AddInFace, "Stores the given triangulation into the given face.", py::arg("theFace"), py::arg("theTriangulation"));
cls_BRepMesh_ShapeTool.def_static("NullifyFace_", (void (*)(const TopoDS_Face &)) &BRepMesh_ShapeTool::NullifyFace, "Nullifies triangulation stored in the face.", py::arg("theFace"));
cls_BRepMesh_ShapeTool.def_static("NullifyEdge_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRepMesh_ShapeTool::NullifyEdge, "Nullifies polygon on triangulation stored in the edge.", py::arg("theEdge"), py::arg("theTriangulation"), py::arg("theLocation"));
cls_BRepMesh_ShapeTool.def_static("NullifyEdge_", (void (*)(const TopoDS_Edge &, const TopLoc_Location &)) &BRepMesh_ShapeTool::NullifyEdge, "Nullifies 3d polygon stored in the edge.", py::arg("theEdge"), py::arg("theLocation"));
cls_BRepMesh_ShapeTool.def_static("UpdateEdge_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRepMesh_ShapeTool::UpdateEdge, "Updates the given edge by the given tessellated representation.", py::arg("theEdge"), py::arg("thePolygon"), py::arg("theTriangulation"), py::arg("theLocation"));
cls_BRepMesh_ShapeTool.def_static("UpdateEdge_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon3D> &)) &BRepMesh_ShapeTool::UpdateEdge, "Updates the given edge by the given tessellated representation.", py::arg("theEdge"), py::arg("thePolygon"));
cls_BRepMesh_ShapeTool.def_static("UpdateEdge_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRepMesh_ShapeTool::UpdateEdge, "Updates the given seam edge by the given tessellated representations.", py::arg("theEdge"), py::arg("thePolygon1"), py::arg("thePolygon2"), py::arg("theTriangulation"), py::arg("theLocation"));
cls_BRepMesh_ShapeTool.def_static("UseLocation_", (gp_Pnt (*)(const gp_Pnt &, const TopLoc_Location &)) &BRepMesh_ShapeTool::UseLocation, "Applies location to the given point and return result.", py::arg("thePnt"), py::arg("theLoc"));
cls_BRepMesh_ShapeTool.def_static("UVPoints_", [](const TopoDS_Edge & a0, const TopoDS_Face & a1, gp_Pnt2d & a2, gp_Pnt2d & a3) -> Standard_Boolean { return BRepMesh_ShapeTool::UVPoints(a0, a1, a2, a3); });
cls_BRepMesh_ShapeTool.def_static("UVPoints_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, gp_Pnt2d &, gp_Pnt2d &, const Standard_Boolean)) &BRepMesh_ShapeTool::UVPoints, "Gets the strict UV locations of the extremities of the edge using pcurve.", py::arg("theEdge"), py::arg("theFace"), py::arg("theFirstPoint2d"), py::arg("theLastPoint2d"), py::arg("isConsiderOrientation"));
cls_BRepMesh_ShapeTool.def_static("Range_", [](const TopoDS_Edge & theEdge, const TopoDS_Face & theFace, opencascade::handle<Geom2d_Curve> & thePCurve, Standard_Real & theFirstParam, Standard_Real & theLastParam, const Standard_Boolean isConsiderOrientation){ Standard_Boolean rv = BRepMesh_ShapeTool::Range(theEdge, theFace, thePCurve, theFirstParam, theLastParam, isConsiderOrientation); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theFirstParam, theLastParam); }, "Gets the parametric range of the given edge on the given face.", py::arg("theEdge"), py::arg("theFace"), py::arg("thePCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("isConsiderOrientation"));
cls_BRepMesh_ShapeTool.def_static("Range_", [](const TopoDS_Edge & theEdge, opencascade::handle<Geom_Curve> & theCurve, Standard_Real & theFirstParam, Standard_Real & theLastParam, const Standard_Boolean isConsiderOrientation){ Standard_Boolean rv = BRepMesh_ShapeTool::Range(theEdge, theCurve, theFirstParam, theLastParam, isConsiderOrientation); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theFirstParam, theLastParam); }, "Gets the 3d range of the given edge.", py::arg("theEdge"), py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("isConsiderOrientation"));
cls_BRepMesh_ShapeTool.def_static("get_type_name_", (const char * (*)()) &BRepMesh_ShapeTool::get_type_name, "None");
cls_BRepMesh_ShapeTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_ShapeTool::get_type_descriptor, "None");
cls_BRepMesh_ShapeTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_ShapeTool::*)() const) &BRepMesh_ShapeTool::DynamicType, "None");

// CLASS: BREPMESH_SHAPEVISITOR
py::class_<BRepMesh_ShapeVisitor, opencascade::handle<BRepMesh_ShapeVisitor>, IMeshTools_ShapeVisitor> cls_BRepMesh_ShapeVisitor(mod, "BRepMesh_ShapeVisitor", "Builds discrete model of a shape by adding faces and free edges. Computes deflection for corresponded shape and checks whether it fits existing polygonal representation. If not, cleans shape from outdated info.");

// Constructors
cls_BRepMesh_ShapeVisitor.def(py::init<const opencascade::handle<IMeshData_Model> &>(), py::arg("theModel"));

// Methods
cls_BRepMesh_ShapeVisitor.def("Visit", (void (BRepMesh_ShapeVisitor::*)(const TopoDS_Face &)) &BRepMesh_ShapeVisitor::Visit, "Handles TopoDS_Face object.", py::arg("theFace"));
cls_BRepMesh_ShapeVisitor.def("Visit", (void (BRepMesh_ShapeVisitor::*)(const TopoDS_Edge &)) &BRepMesh_ShapeVisitor::Visit, "Handles TopoDS_Edge object.", py::arg("theEdge"));
cls_BRepMesh_ShapeVisitor.def_static("get_type_name_", (const char * (*)()) &BRepMesh_ShapeVisitor::get_type_name, "None");
cls_BRepMesh_ShapeVisitor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_ShapeVisitor::get_type_descriptor, "None");
cls_BRepMesh_ShapeVisitor.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_ShapeVisitor::*)() const) &BRepMesh_ShapeVisitor::DynamicType, "None");

// CLASS: BREPMESH_SPHERERANGESPLITTER
/*
py::class_<BRepMesh_SphereRangeSplitter> cls_BRepMesh_SphereRangeSplitter(mod, "BRepMesh_SphereRangeSplitter", "Auxiliary class extending default range splitter in order to generate internal nodes for spherical surface.");

// Constructors
cls_BRepMesh_SphereRangeSplitter.def(py::init<>());

// Methods
cls_BRepMesh_SphereRangeSplitter.def("GenerateSurfaceNodes", (opencascade::handle<IMeshData::ListOfPnt2d> (BRepMesh_SphereRangeSplitter::*)(const IMeshTools_Parameters &) const) &BRepMesh_SphereRangeSplitter::GenerateSurfaceNodes, "Returns list of nodes generated using surface data and specified parameters.", py::arg("theParameters"));
*/

// CLASS: BREPMESH_TORUSRANGESPLITTER
/*
py::class_<BRepMesh_TorusRangeSplitter> cls_BRepMesh_TorusRangeSplitter(mod, "BRepMesh_TorusRangeSplitter", "Auxiliary class extending UV range splitter in order to generate internal nodes for NURBS surface.");

// Constructors
cls_BRepMesh_TorusRangeSplitter.def(py::init<>());

// Methods
cls_BRepMesh_TorusRangeSplitter.def("GenerateSurfaceNodes", (opencascade::handle<IMeshData::ListOfPnt2d> (BRepMesh_TorusRangeSplitter::*)(const IMeshTools_Parameters &) const) &BRepMesh_TorusRangeSplitter::GenerateSurfaceNodes, "Returns list of nodes generated using surface data and specified parameters.", py::arg("theParameters"));
cls_BRepMesh_TorusRangeSplitter.def("AddPoint", (void (BRepMesh_TorusRangeSplitter::*)(const gp_Pnt2d &)) &BRepMesh_TorusRangeSplitter::AddPoint, "Registers border point.", py::arg("thePoint"));
*/


}
