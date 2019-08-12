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
#include <BRepMesh.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <BRepMesh_Status.hxx>
#include <BRepMesh_DataStructureOfDelaun.hxx>
#include <gp_Pnt.hxx>
#include <BRepMesh_Vertex.hxx>
#include <BRepMesh_FaceAttribute.hxx>
#include <gp_XY.hxx>
#include <BRepMesh_DegreeOfFreedom.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Vertex.hxx>

void bind_BRepMesh_FaceAttribute(py::module &mod){

py::class_<BRepMesh_FaceAttribute, opencascade::handle<BRepMesh_FaceAttribute>, Standard_Transient> cls_BRepMesh_FaceAttribute(mod, "BRepMesh_FaceAttribute", "Auxiliary class for FastDiscret and FastDiscretFace classes.");

// Constructors
cls_BRepMesh_FaceAttribute.def(py::init<const BRepMesh::HDMapOfVertexInteger &, const BRepMesh::HDMapOfIntegerPnt &>(), py::arg("theBoundaryVertices"), py::arg("theBoundaryPoints"));
cls_BRepMesh_FaceAttribute.def(py::init<const TopoDS_Face &, const BRepMesh::HDMapOfVertexInteger &, const BRepMesh::HDMapOfIntegerPnt &, const Standard_Boolean>(), py::arg("theFace"), py::arg("theBoundaryVertices"), py::arg("theBoundaryPoints"), py::arg("theAdaptiveMin"));

// Fields

// Methods
cls_BRepMesh_FaceAttribute.def("Surface", (const opencascade::handle<BRepAdaptor_HSurface> & (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::Surface, "Returns face's surface.");
cls_BRepMesh_FaceAttribute.def("IsInitialized", (Standard_Boolean (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::IsInitialized, "Returns True in case if this attribute has already been intialized.");
cls_BRepMesh_FaceAttribute.def("SetFace", (void (BRepMesh_FaceAttribute::*)(const TopoDS_Face &, const Standard_Boolean)) &BRepMesh_FaceAttribute::SetFace, "Initializes this attribute by the given face.", py::arg("theFace"), py::arg("theAdaptiveMin"));
cls_BRepMesh_FaceAttribute.def("Face", (const TopoDS_Face & (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::Face, "Returns forward oriented face to be used for calculations.");
cls_BRepMesh_FaceAttribute.def("SetBoundaryVertices", (void (BRepMesh_FaceAttribute::*)(const BRepMesh::HDMapOfVertexInteger &)) &BRepMesh_FaceAttribute::SetBoundaryVertices, "Sets boundary vertices map.", py::arg("theVertices"));
cls_BRepMesh_FaceAttribute.def("SetBoundaryPoints", (void (BRepMesh_FaceAttribute::*)(const BRepMesh::HDMapOfIntegerPnt &)) &BRepMesh_FaceAttribute::SetBoundaryPoints, "Sets boundary points map.", py::arg("theBoundaryPoints"));
cls_BRepMesh_FaceAttribute.def("ToleranceU", (Standard_Real (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::ToleranceU, "Returns U tolerance of face calculated regarding its parameters.");
cls_BRepMesh_FaceAttribute.def("ToleranceV", (Standard_Real (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::ToleranceV, "Returns V tolerance of face calculated regarding its parameters.");
cls_BRepMesh_FaceAttribute.def("GetDefFace", (Standard_Real (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::GetDefFace, "Gives face deflection parameter.");
cls_BRepMesh_FaceAttribute.def("SetDefFace", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetDefFace, "Sets face deflection.", py::arg("theDefFace"));
cls_BRepMesh_FaceAttribute.def("GetUMin", (Standard_Real (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::GetUMin, "Gives minimal value in U domain.");
cls_BRepMesh_FaceAttribute.def("SetUMin", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetUMin, "Sets minimal value in U domain.", py::arg("theUMin"));
cls_BRepMesh_FaceAttribute.def("GetVMin", (Standard_Real (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::GetVMin, "Gives minimal value in V domain.");
cls_BRepMesh_FaceAttribute.def("SetVMin", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetVMin, "Sets minimal value in V domain.", py::arg("theVMin"));
cls_BRepMesh_FaceAttribute.def("GetUMax", (Standard_Real (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::GetUMax, "Gives maximal value in U domain.");
cls_BRepMesh_FaceAttribute.def("SetUMax", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetUMax, "Sets maximal value in U domain.", py::arg("theUMax"));
cls_BRepMesh_FaceAttribute.def("GetVMax", (Standard_Real (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::GetVMax, "Gives maximal value in V domain.");
cls_BRepMesh_FaceAttribute.def("SetVMax", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetVMax, "Sets maximal value in V domain.", py::arg("theVMax"));
cls_BRepMesh_FaceAttribute.def("GetDeltaX", (Standard_Real (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::GetDeltaX, "Gives value of step in U domain.");
cls_BRepMesh_FaceAttribute.def("SetDeltaX", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetDeltaX, "Sets value of step in U domain.", py::arg("theDeltaX"));
cls_BRepMesh_FaceAttribute.def("GetDeltaY", (Standard_Real (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::GetDeltaY, "Gives value of step in V domain.");
cls_BRepMesh_FaceAttribute.def("SetDeltaY", (void (BRepMesh_FaceAttribute::*)(const Standard_Real)) &BRepMesh_FaceAttribute::SetDeltaY, "Sets value of step in V domain.", py::arg("theDeltaY"));
cls_BRepMesh_FaceAttribute.def("GetStatus", (Standard_Integer (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::GetStatus, "Sets set of status flags for this face.");
cls_BRepMesh_FaceAttribute.def("SetStatus", (void (BRepMesh_FaceAttribute::*)(const BRepMesh_Status)) &BRepMesh_FaceAttribute::SetStatus, "Sets status flag for this face.", py::arg("theStatus"));
cls_BRepMesh_FaceAttribute.def("IsValid", (Standard_Boolean (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::IsValid, "Returns TRUE in case if computed data is valid.");
cls_BRepMesh_FaceAttribute.def("Clear", (void (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::Clear, "Clear face attribute.");
cls_BRepMesh_FaceAttribute.def("ChangeInternalEdges", (BRepMesh::HDMapOfShapePairOfPolygon & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeInternalEdges, "Gives reference to map of internal edges of face.");
cls_BRepMesh_FaceAttribute.def("ChangeLocation2D", (BRepMesh::HDMapOfIntegerListOfXY & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeLocation2D, "Gives reference to map of 2D points of discretization.");
cls_BRepMesh_FaceAttribute.def("ChangeSurfacePoints", (BRepMesh::HDMapOfIntegerPnt & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeSurfacePoints, "Gives reference to map of 3D points of discretization.");
cls_BRepMesh_FaceAttribute.def("ChangeSurfaceVertices", (BRepMesh::HDMapOfVertexInteger & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeSurfaceVertices, "Gives reference to map of vertices of discretization.");
cls_BRepMesh_FaceAttribute.def("ChangeVertexEdgeMap", (BRepMesh::HIMapOfInteger & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeVertexEdgeMap, "Gives reference on map of (vertex, edge) pairs of face.");
cls_BRepMesh_FaceAttribute.def("ChangeStructure", (opencascade::handle<BRepMesh_DataStructureOfDelaun> & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeStructure, "Gives Delaunay data structure.");
cls_BRepMesh_FaceAttribute.def("ChangeClassifier", (BRepMesh::HClassifier & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeClassifier, "Returns classifier.");
cls_BRepMesh_FaceAttribute.def("ChangeMeshNodes", (BRepMesh::HVectorOfVertex & (BRepMesh_FaceAttribute::*)()) &BRepMesh_FaceAttribute::ChangeMeshNodes, "Returns mesh nodes calculated for boundaries.");
cls_BRepMesh_FaceAttribute.def("LastPointId", (Standard_Integer (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::LastPointId, "Gives the number of different locations in 3D space.");
cls_BRepMesh_FaceAttribute.def("GetPoint", (const gp_Pnt & (BRepMesh_FaceAttribute::*)(const BRepMesh_Vertex &) const) &BRepMesh_FaceAttribute::GetPoint, "Gives the 3D location of the vertex.", py::arg("theVertex"));
cls_BRepMesh_FaceAttribute.def("GetPoint", (const gp_Pnt & (BRepMesh_FaceAttribute::*)(const Standard_Integer) const) &BRepMesh_FaceAttribute::GetPoint, "Gives the 3D location of the vertex.", py::arg("theIndex"));
cls_BRepMesh_FaceAttribute.def("AddNode", [](BRepMesh_FaceAttribute &self, const Standard_Integer theIndex, const gp_XY & theUV, const BRepMesh_DegreeOfFreedom theMovability, Standard_Integer & theNodeIndex, Standard_Integer & theNodeOnEdgeIndex){ self.AddNode(theIndex, theUV, theMovability, theNodeIndex, theNodeOnEdgeIndex); return std::tuple<Standard_Integer &, Standard_Integer &>(theNodeIndex, theNodeOnEdgeIndex); }, "Adds node with the given parameters to mesh.", py::arg("theIndex"), py::arg("theUV"), py::arg("theMovability"), py::arg("theNodeIndex"), py::arg("theNodeOnEdgeIndex"));
cls_BRepMesh_FaceAttribute.def("Scale", (gp_XY (BRepMesh_FaceAttribute::*)(const gp_XY &, const Standard_Boolean)) &BRepMesh_FaceAttribute::Scale, "Scales the given point from real parametric space to face basis and otherwise.", py::arg("thePoint2d"), py::arg("isToFaceBasis"));
cls_BRepMesh_FaceAttribute.def_static("get_type_name_", (const char * (*)()) &BRepMesh_FaceAttribute::get_type_name, "None");
cls_BRepMesh_FaceAttribute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_FaceAttribute::get_type_descriptor, "None");
cls_BRepMesh_FaceAttribute.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_FaceAttribute::*)() const) &BRepMesh_FaceAttribute::DynamicType, "None");

// Enums

}