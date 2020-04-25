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
#include <pyOCCT_Common.hxx>

#include <SMDS_Mesh.hxx>
#include <TopoDS_Shape.hxx>
#include <SMESHDS_Hypothesis.hxx>
#include <SMDS_MeshNode.hxx>
#include <SMDS_Mesh0DElement.hxx>
#include <SMDS_BallElement.hxx>
#include <SMDS_MeshEdge.hxx>
#include <SMDS_MeshFace.hxx>
#include <SMDS_MeshVolume.hxx>
#include <SMDS_MeshElement.hxx>
#include <SMESHDS_SubMesh.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <SMESHDS_Mesh.hxx>
#include <SMESHDS_Script.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <SMESHDS_GroupBase.hxx>
#include <SMDSAbs_ElementType.hxx>
#include <SMDS_ElemIterator.hxx>
#include <Quantity_Color.hxx>
#include <SMESHDS_Document.hxx>
#include <SMESHDS_CommandType.hxx>
#include <SMESHDS_Command.hxx>
#include <Standard_TypeDef.hxx>
#include <SMESHDS_DataMapOfShape.hxx>
#include <NCollection_BaseMap.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <SMDS_MeshGroup.hxx>
#include <SMESHDS_Group.hxx>
#include <SMESH_Controls.hxx>
#include <SMESHDS_GroupOnFilter.hxx>
#include <SMESHDS_GroupOnGeom.hxx>
#include <SMDS_Iterator.hxx>
#include <SMDS_Templates.hxx>
#include <NCollection_Templates.hxx>

PYBIND11_MODULE(SMESHDS, mod) {

	// IMPORT
	py::module::import("OCCT.SMDS");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.SMDSAbs");
	py::module::import("OCCT.Quantity");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS
	struct ImportSMESH{
		ImportSMESH() { py::module::import("OCCT.SMESH"); }
	};


	// ENUMS
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_CommandType.hxx
	py::enum_<SMESHDS_CommandType>(mod, "SMESHDS_CommandType", "None")
		.value("SMESHDS_AddNode", SMESHDS_CommandType::SMESHDS_AddNode)
		.value("SMESHDS_AddEdge", SMESHDS_CommandType::SMESHDS_AddEdge)
		.value("SMESHDS_AddTriangle", SMESHDS_CommandType::SMESHDS_AddTriangle)
		.value("SMESHDS_AddQuadrangle", SMESHDS_CommandType::SMESHDS_AddQuadrangle)
		.value("SMESHDS_AddPolygon", SMESHDS_CommandType::SMESHDS_AddPolygon)
		.value("SMESHDS_AddTetrahedron", SMESHDS_CommandType::SMESHDS_AddTetrahedron)
		.value("SMESHDS_AddPyramid", SMESHDS_CommandType::SMESHDS_AddPyramid)
		.value("SMESHDS_AddPrism", SMESHDS_CommandType::SMESHDS_AddPrism)
		.value("SMESHDS_AddHexahedron", SMESHDS_CommandType::SMESHDS_AddHexahedron)
		.value("SMESHDS_AddPolyhedron", SMESHDS_CommandType::SMESHDS_AddPolyhedron)
		.value("SMESHDS_RemoveNode", SMESHDS_CommandType::SMESHDS_RemoveNode)
		.value("SMESHDS_RemoveElement", SMESHDS_CommandType::SMESHDS_RemoveElement)
		.value("SMESHDS_MoveNode", SMESHDS_CommandType::SMESHDS_MoveNode)
		.value("SMESHDS_ChangeElementNodes", SMESHDS_CommandType::SMESHDS_ChangeElementNodes)
		.value("SMESHDS_ChangePolyhedronNodes", SMESHDS_CommandType::SMESHDS_ChangePolyhedronNodes)
		.value("SMESHDS_Renumber", SMESHDS_CommandType::SMESHDS_Renumber)
		.value("SMESHDS_ClearAll", SMESHDS_CommandType::SMESHDS_ClearAll)
		.value("SMESHDS_AddQuadEdge", SMESHDS_CommandType::SMESHDS_AddQuadEdge)
		.value("SMESHDS_AddQuadTriangle", SMESHDS_CommandType::SMESHDS_AddQuadTriangle)
		.value("SMESHDS_AddQuadQuadrangle", SMESHDS_CommandType::SMESHDS_AddQuadQuadrangle)
		.value("SMESHDS_AddQuadPolygon", SMESHDS_CommandType::SMESHDS_AddQuadPolygon)
		.value("SMESHDS_AddQuadTetrahedron", SMESHDS_CommandType::SMESHDS_AddQuadTetrahedron)
		.value("SMESHDS_AddQuadPyramid", SMESHDS_CommandType::SMESHDS_AddQuadPyramid)
		.value("SMESHDS_AddQuadPentahedron", SMESHDS_CommandType::SMESHDS_AddQuadPentahedron)
		.value("SMESHDS_AddQuadHexahedron", SMESHDS_CommandType::SMESHDS_AddQuadHexahedron)
		.value("SMESHDS_Add0DElement", SMESHDS_CommandType::SMESHDS_Add0DElement)
		.value("SMESHDS_AddBiQuadTriangle", SMESHDS_CommandType::SMESHDS_AddBiQuadTriangle)
		.value("SMESHDS_AddBiQuadQuadrangle", SMESHDS_CommandType::SMESHDS_AddBiQuadQuadrangle)
		.value("SMESHDS_AddTriQuadHexa", SMESHDS_CommandType::SMESHDS_AddTriQuadHexa)
		.value("SMESHDS_AddHexagonalPrism", SMESHDS_CommandType::SMESHDS_AddHexagonalPrism)
		.value("SMESHDS_AddBall", SMESHDS_CommandType::SMESHDS_AddBall)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_Mesh.hxx
	py::class_<SMESHDS_Mesh, std::unique_ptr<SMESHDS_Mesh, py::nodelete>, SMDS_Mesh> cls_SMESHDS_Mesh(mod, "SMESHDS_Mesh", "None");
	cls_SMESHDS_Mesh.def(py::init<int, bool>(), py::arg("theMeshID"), py::arg("theIsEmbeddedMode"));
	cls_SMESHDS_Mesh.def("IsEmbeddedMode", (bool (SMESHDS_Mesh::*)()) &SMESHDS_Mesh::IsEmbeddedMode, "None");
	cls_SMESHDS_Mesh.def("SetPersistentId", (void (SMESHDS_Mesh::*)(int)) &SMESHDS_Mesh::SetPersistentId, "None", py::arg("id"));
	cls_SMESHDS_Mesh.def("GetPersistentId", (int (SMESHDS_Mesh::*)() const ) &SMESHDS_Mesh::GetPersistentId, "None");
	cls_SMESHDS_Mesh.def("ShapeToMesh", (void (SMESHDS_Mesh::*)(const TopoDS_Shape &)) &SMESHDS_Mesh::ShapeToMesh, "None", py::arg("S"));
	cls_SMESHDS_Mesh.def("ShapeToMesh", (TopoDS_Shape (SMESHDS_Mesh::*)() const ) &SMESHDS_Mesh::ShapeToMesh, "None");
	cls_SMESHDS_Mesh.def("AddHypothesis", (bool (SMESHDS_Mesh::*)(const TopoDS_Shape &, const SMESHDS_Hypothesis *)) &SMESHDS_Mesh::AddHypothesis, "None", py::arg("SS"), py::arg("H"));
	cls_SMESHDS_Mesh.def("RemoveHypothesis", (bool (SMESHDS_Mesh::*)(const TopoDS_Shape &, const SMESHDS_Hypothesis *)) &SMESHDS_Mesh::RemoveHypothesis, "None", py::arg("S"), py::arg("H"));
	cls_SMESHDS_Mesh.def("AddNodeWithID", (SMDS_MeshNode * (SMESHDS_Mesh::*)(double, double, double, int)) &SMESHDS_Mesh::AddNodeWithID, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddNode", (SMDS_MeshNode * (SMESHDS_Mesh::*)(double, double, double)) &SMESHDS_Mesh::AddNode, "None", py::arg("x"), py::arg("y"), py::arg("z"));
	cls_SMESHDS_Mesh.def("Add0DElementWithID", (SMDS_Mesh0DElement * (SMESHDS_Mesh::*)(int, int)) &SMESHDS_Mesh::Add0DElementWithID, "None", py::arg("nodeID"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("Add0DElementWithID", (SMDS_Mesh0DElement * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, int)) &SMESHDS_Mesh::Add0DElementWithID, "None", py::arg("node"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("Add0DElement", (SMDS_Mesh0DElement * (SMESHDS_Mesh::*)(const SMDS_MeshNode *)) &SMESHDS_Mesh::Add0DElement, "None", py::arg("node"));
	cls_SMESHDS_Mesh.def("AddBallWithID", (SMDS_BallElement * (SMESHDS_Mesh::*)(int, double, int)) &SMESHDS_Mesh::AddBallWithID, "None", py::arg("n"), py::arg("diameter"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddBallWithID", (SMDS_BallElement * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, double, int)) &SMESHDS_Mesh::AddBallWithID, "None", py::arg("n"), py::arg("diameter"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddBall", (SMDS_BallElement * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, double)) &SMESHDS_Mesh::AddBall, "None", py::arg("n"), py::arg("diameter"));
	cls_SMESHDS_Mesh.def("AddEdgeWithID", (SMDS_MeshEdge * (SMESHDS_Mesh::*)(int, int, int)) &SMESHDS_Mesh::AddEdgeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddEdgeWithID", (SMDS_MeshEdge * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddEdgeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddEdge", (SMDS_MeshEdge * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddEdge, "None", py::arg("n1"), py::arg("n2"));
	cls_SMESHDS_Mesh.def("AddEdgeWithID", (SMDS_MeshEdge * (SMESHDS_Mesh::*)(int, int, int, int)) &SMESHDS_Mesh::AddEdgeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n12"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddEdgeWithID", (SMDS_MeshEdge * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddEdgeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n12"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddEdge", (SMDS_MeshEdge * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddEdge, "None", py::arg("n1"), py::arg("n2"), py::arg("n12"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(int, int, int, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(int, int, int, int, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("nCenter"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("nCenter"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("nCenter"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("nCenter"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("nCenter"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("nCenter"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(int, int, int, int, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(int, int, int, int, int, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n9"), py::arg("n10"), py::arg("n11"), py::arg("n12"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n9"), py::arg("n10"), py::arg("n11"), py::arg("n12"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n9"), py::arg("n10"), py::arg("n11"), py::arg("n12"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n14"), py::arg("n24"), py::arg("n34"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n14"), py::arg("n24"), py::arg("n34"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n14"), py::arg("n24"), py::arg("n34"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n15"), py::arg("n25"), py::arg("n35"), py::arg("n45"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n15"), py::arg("n25"), py::arg("n35"), py::arg("n45"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n15"), py::arg("n25"), py::arg("n35"), py::arg("n45"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n45"), py::arg("n56"), py::arg("n64"), py::arg("n14"), py::arg("n25"), py::arg("n36"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n45"), py::arg("n56"), py::arg("n64"), py::arg("n14"), py::arg("n25"), py::arg("n36"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n45"), py::arg("n56"), py::arg("n64"), py::arg("n14"), py::arg("n25"), py::arg("n36"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("n1234"), py::arg("n1256"), py::arg("n2367"), py::arg("n3478"), py::arg("n1458"), py::arg("n5678"), py::arg("nCenter"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMESHDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("n1234"), py::arg("n1256"), py::arg("n2367"), py::arg("n3478"), py::arg("n1458"), py::arg("n5678"), py::arg("nCenter"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESHDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("n1234"), py::arg("n1256"), py::arg("n2367"), py::arg("n3478"), py::arg("n1458"), py::arg("n5678"), py::arg("nCenter"));
	cls_SMESHDS_Mesh.def("AddPolygonalFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const std::vector<int> &, const int)) &SMESHDS_Mesh::AddPolygonalFaceWithID, "None", py::arg("nodes_ids"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddPolygonalFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &, const int)) &SMESHDS_Mesh::AddPolygonalFaceWithID, "None", py::arg("nodes"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddPolygonalFace", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &)) &SMESHDS_Mesh::AddPolygonalFace, "None", py::arg("nodes"));
	cls_SMESHDS_Mesh.def("AddQuadPolygonalFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const std::vector<int> &, const int)) &SMESHDS_Mesh::AddQuadPolygonalFaceWithID, "None", py::arg("nodes_ids"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddQuadPolygonalFaceWithID", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &, const int)) &SMESHDS_Mesh::AddQuadPolygonalFaceWithID, "None", py::arg("nodes"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddQuadPolygonalFace", (SMDS_MeshFace * (SMESHDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &)) &SMESHDS_Mesh::AddQuadPolygonalFace, "None", py::arg("nodes"));
	cls_SMESHDS_Mesh.def("AddPolyhedralVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const std::vector<int> &, const std::vector<int> &, const int)) &SMESHDS_Mesh::AddPolyhedralVolumeWithID, "None", py::arg("nodes_ids"), py::arg("quantities"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddPolyhedralVolumeWithID", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &, const std::vector<int> &, const int)) &SMESHDS_Mesh::AddPolyhedralVolumeWithID, "None", py::arg("nodes"), py::arg("quantities"), py::arg("ID"));
	cls_SMESHDS_Mesh.def("AddPolyhedralVolume", (SMDS_MeshVolume * (SMESHDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &, const std::vector<int> &)) &SMESHDS_Mesh::AddPolyhedralVolume, "None", py::arg("nodes"), py::arg("quantities"));
	cls_SMESHDS_Mesh.def("MoveNode", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *, double, double, double)) &SMESHDS_Mesh::MoveNode, "None", py::arg(""), py::arg("x"), py::arg("y"), py::arg("z"));
	cls_SMESHDS_Mesh.def("RemoveNode", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *)) &SMESHDS_Mesh::RemoveNode, "None", py::arg(""));
	cls_SMESHDS_Mesh.def("RemoveElement", (void (SMESHDS_Mesh::*)(const SMDS_MeshElement *)) &SMESHDS_Mesh::RemoveElement, "None", py::arg(""));
	cls_SMESHDS_Mesh.def("RemoveFreeNode", [](SMESHDS_Mesh &self, const SMDS_MeshNode * a0, SMESHDS_SubMesh * a1) -> void { return self.RemoveFreeNode(a0, a1); }, py::arg(""), py::arg(""));
	cls_SMESHDS_Mesh.def("RemoveFreeNode", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *, SMESHDS_SubMesh *, bool)) &SMESHDS_Mesh::RemoveFreeNode, "Remove only the given element/node and only if it is free. Methods do not work for meshes with descendants. Implemented for fast cleaning of meshes.", py::arg(""), py::arg(""), py::arg("fromGroups"));
	cls_SMESHDS_Mesh.def("RemoveFreeElement", [](SMESHDS_Mesh &self, const SMDS_MeshElement * a0, SMESHDS_SubMesh * a1) -> void { return self.RemoveFreeElement(a0, a1); }, py::arg(""), py::arg(""));
	cls_SMESHDS_Mesh.def("RemoveFreeElement", (void (SMESHDS_Mesh::*)(const SMDS_MeshElement *, SMESHDS_SubMesh *, bool)) &SMESHDS_Mesh::RemoveFreeElement, "None", py::arg(""), py::arg(""), py::arg("fromGroups"));
	cls_SMESHDS_Mesh.def("ClearMesh", (void (SMESHDS_Mesh::*)()) &SMESHDS_Mesh::ClearMesh, "None");
	// FIXME cls_SMESHDS_Mesh.def("ChangeElementNodes", (bool (SMESHDS_Mesh::*)(const SMDS_MeshElement *, const SMDS_MeshNode *[], const int)) &SMESHDS_Mesh::ChangeElementNodes, "None", py::arg("elem"), py::arg("nodes"), py::arg("nbnodes"));
	cls_SMESHDS_Mesh.def("ChangePolygonNodes", (bool (SMESHDS_Mesh::*)(const SMDS_MeshElement *, std::vector<const SMDS_MeshNode *>)) &SMESHDS_Mesh::ChangePolygonNodes, "None", py::arg("elem"), py::arg("nodes"));
	cls_SMESHDS_Mesh.def("ChangePolyhedronNodes", (bool (SMESHDS_Mesh::*)(const SMDS_MeshElement *, std::vector<const SMDS_MeshNode *>, std::vector<int>)) &SMESHDS_Mesh::ChangePolyhedronNodes, "None", py::arg("elem"), py::arg("nodes"), py::arg("quantities"));
	cls_SMESHDS_Mesh.def("ModifyCellNodes", (bool (SMESHDS_Mesh::*)(int, std::map<int, int>)) &SMESHDS_Mesh::ModifyCellNodes, "None", py::arg("smdsVolId"), py::arg("localClonedNodeIds"));
	cls_SMESHDS_Mesh.def("Renumber", [](SMESHDS_Mesh &self, const bool a0) -> void { return self.Renumber(a0); }, py::arg("isNodes"));
	cls_SMESHDS_Mesh.def("Renumber", [](SMESHDS_Mesh &self, const bool a0, const int a1) -> void { return self.Renumber(a0, a1); }, py::arg("isNodes"), py::arg("startID"));
	cls_SMESHDS_Mesh.def("Renumber", (void (SMESHDS_Mesh::*)(const bool, const int, const int)) &SMESHDS_Mesh::Renumber, "None", py::arg("isNodes"), py::arg("startID"), py::arg("deltaID"));
	cls_SMESHDS_Mesh.def("SetNodeInVolume", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const TopoDS_Shell &)) &SMESHDS_Mesh::SetNodeInVolume, "None", py::arg("aNode"), py::arg("S"));
	cls_SMESHDS_Mesh.def("SetNodeInVolume", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const TopoDS_Solid &)) &SMESHDS_Mesh::SetNodeInVolume, "None", py::arg("aNode"), py::arg("S"));
	cls_SMESHDS_Mesh.def("SetNodeOnFace", [](SMESHDS_Mesh &self, const SMDS_MeshNode * a0, const TopoDS_Face & a1) -> void { return self.SetNodeOnFace(a0, a1); }, py::arg("aNode"), py::arg("S"));
	cls_SMESHDS_Mesh.def("SetNodeOnFace", [](SMESHDS_Mesh &self, const SMDS_MeshNode * a0, const TopoDS_Face & a1, double a2) -> void { return self.SetNodeOnFace(a0, a1, a2); }, py::arg("aNode"), py::arg("S"), py::arg("u"));
	cls_SMESHDS_Mesh.def("SetNodeOnFace", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const TopoDS_Face &, double, double)) &SMESHDS_Mesh::SetNodeOnFace, "None", py::arg("aNode"), py::arg("S"), py::arg("u"), py::arg("v"));
	cls_SMESHDS_Mesh.def("SetNodeOnEdge", [](SMESHDS_Mesh &self, const SMDS_MeshNode * a0, const TopoDS_Edge & a1) -> void { return self.SetNodeOnEdge(a0, a1); }, py::arg("aNode"), py::arg("S"));
	cls_SMESHDS_Mesh.def("SetNodeOnEdge", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const TopoDS_Edge &, double)) &SMESHDS_Mesh::SetNodeOnEdge, "None", py::arg("aNode"), py::arg("S"), py::arg("u"));
	cls_SMESHDS_Mesh.def("SetNodeOnVertex", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *, const TopoDS_Vertex &)) &SMESHDS_Mesh::SetNodeOnVertex, "None", py::arg("aNode"), py::arg("S"));
	cls_SMESHDS_Mesh.def("UnSetNodeOnShape", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *)) &SMESHDS_Mesh::UnSetNodeOnShape, "None", py::arg("aNode"));
	cls_SMESHDS_Mesh.def("SetMeshElementOnShape", (void (SMESHDS_Mesh::*)(const SMDS_MeshElement *, const TopoDS_Shape &)) &SMESHDS_Mesh::SetMeshElementOnShape, "None", py::arg("anElt"), py::arg("S"));
	cls_SMESHDS_Mesh.def("UnSetMeshElementOnShape", (void (SMESHDS_Mesh::*)(const SMDS_MeshElement *, const TopoDS_Shape &)) &SMESHDS_Mesh::UnSetMeshElementOnShape, "None", py::arg("anElt"), py::arg("S"));
	cls_SMESHDS_Mesh.def("SetNodeInVolume", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *, int)) &SMESHDS_Mesh::SetNodeInVolume, "None", py::arg("aNode"), py::arg("Index"));
	cls_SMESHDS_Mesh.def("SetNodeOnFace", [](SMESHDS_Mesh &self, const SMDS_MeshNode * a0, int a1) -> void { return self.SetNodeOnFace(a0, a1); }, py::arg("aNode"), py::arg("Index"));
	cls_SMESHDS_Mesh.def("SetNodeOnFace", [](SMESHDS_Mesh &self, const SMDS_MeshNode * a0, int a1, double a2) -> void { return self.SetNodeOnFace(a0, a1, a2); }, py::arg("aNode"), py::arg("Index"), py::arg("u"));
	cls_SMESHDS_Mesh.def("SetNodeOnFace", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *, int, double, double)) &SMESHDS_Mesh::SetNodeOnFace, "None", py::arg("aNode"), py::arg("Index"), py::arg("u"), py::arg("v"));
	cls_SMESHDS_Mesh.def("SetNodeOnEdge", [](SMESHDS_Mesh &self, const SMDS_MeshNode * a0, int a1) -> void { return self.SetNodeOnEdge(a0, a1); }, py::arg("aNode"), py::arg("Index"));
	cls_SMESHDS_Mesh.def("SetNodeOnEdge", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *, int, double)) &SMESHDS_Mesh::SetNodeOnEdge, "None", py::arg("aNode"), py::arg("Index"), py::arg("u"));
	cls_SMESHDS_Mesh.def("SetNodeOnVertex", (void (SMESHDS_Mesh::*)(const SMDS_MeshNode *, int)) &SMESHDS_Mesh::SetNodeOnVertex, "None", py::arg("aNode"), py::arg("Index"));
	cls_SMESHDS_Mesh.def("SetMeshElementOnShape", (void (SMESHDS_Mesh::*)(const SMDS_MeshElement *, int)) &SMESHDS_Mesh::SetMeshElementOnShape, "None", py::arg("anElt"), py::arg("Index"));
	cls_SMESHDS_Mesh.def("HasMeshElements", (bool (SMESHDS_Mesh::*)(const TopoDS_Shape &) const ) &SMESHDS_Mesh::HasMeshElements, "None", py::arg("S"));
	cls_SMESHDS_Mesh.def("MeshElements", (SMESHDS_SubMesh * (SMESHDS_Mesh::*)(const TopoDS_Shape &) const ) &SMESHDS_Mesh::MeshElements, "None", py::arg("S"));
	cls_SMESHDS_Mesh.def("MeshElements", (SMESHDS_SubMesh * (SMESHDS_Mesh::*)(const int) const ) &SMESHDS_Mesh::MeshElements, "None", py::arg("Index"));
	cls_SMESHDS_Mesh.def("SubMeshIndices", (std::list<int> (SMESHDS_Mesh::*)() const ) &SMESHDS_Mesh::SubMeshIndices, "None");
	cls_SMESHDS_Mesh.def("SubMeshes", (SMESHDS_SubMeshIteratorPtr (SMESHDS_Mesh::*)() const ) &SMESHDS_Mesh::SubMeshes, "None");
	cls_SMESHDS_Mesh.def("HasHypothesis", (bool (SMESHDS_Mesh::*)(const TopoDS_Shape &)) &SMESHDS_Mesh::HasHypothesis, "None", py::arg("S"));
	cls_SMESHDS_Mesh.def("GetHypothesis", (const std::list<const SMESHDS_Hypothesis *> & (SMESHDS_Mesh::*)(const TopoDS_Shape &) const ) &SMESHDS_Mesh::GetHypothesis, "None", py::arg("S"));
	cls_SMESHDS_Mesh.def("IsUsedHypothesis", (bool (SMESHDS_Mesh::*)(const SMESHDS_Hypothesis *) const ) &SMESHDS_Mesh::IsUsedHypothesis, "None", py::arg("H"));
	cls_SMESHDS_Mesh.def("GetHypotheses", (const ShapeToHypothesis & (SMESHDS_Mesh::*)() const ) &SMESHDS_Mesh::GetHypotheses, "None");
	cls_SMESHDS_Mesh.def("GetScript", (SMESHDS_Script * (SMESHDS_Mesh::*)()) &SMESHDS_Mesh::GetScript, "None");
	cls_SMESHDS_Mesh.def("ClearScript", (void (SMESHDS_Mesh::*)()) &SMESHDS_Mesh::ClearScript, "None");
	cls_SMESHDS_Mesh.def("ShapeToIndex", (int (SMESHDS_Mesh::*)(const TopoDS_Shape &) const ) &SMESHDS_Mesh::ShapeToIndex, "None", py::arg("aShape"));
	cls_SMESHDS_Mesh.def("IndexToShape", (const TopoDS_Shape & (SMESHDS_Mesh::*)(int) const ) &SMESHDS_Mesh::IndexToShape, "None", py::arg("ShapeIndex"));
	cls_SMESHDS_Mesh.def("MaxShapeIndex", (int (SMESHDS_Mesh::*)() const ) &SMESHDS_Mesh::MaxShapeIndex, "None");
	cls_SMESHDS_Mesh.def("MaxSubMeshIndex", (int (SMESHDS_Mesh::*)() const ) &SMESHDS_Mesh::MaxSubMeshIndex, "None");
	cls_SMESHDS_Mesh.def("NewSubMesh", (SMESHDS_SubMesh * (SMESHDS_Mesh::*)(int)) &SMESHDS_Mesh::NewSubMesh, "None", py::arg("Index"));
	cls_SMESHDS_Mesh.def("AddCompoundSubmesh", [](SMESHDS_Mesh &self, const TopoDS_Shape & a0) -> int { return self.AddCompoundSubmesh(a0); }, py::arg("S"));
	cls_SMESHDS_Mesh.def("AddCompoundSubmesh", (int (SMESHDS_Mesh::*)(const TopoDS_Shape &, TopAbs_ShapeEnum)) &SMESHDS_Mesh::AddCompoundSubmesh, "None", py::arg("S"), py::arg("type"));
	cls_SMESHDS_Mesh.def("AddGroup", (void (SMESHDS_Mesh::*)(SMESHDS_GroupBase *)) &SMESHDS_Mesh::AddGroup, "None", py::arg("theGroup"));
	cls_SMESHDS_Mesh.def("RemoveGroup", (void (SMESHDS_Mesh::*)(SMESHDS_GroupBase *)) &SMESHDS_Mesh::RemoveGroup, "None", py::arg("theGroup"));
	cls_SMESHDS_Mesh.def("GetNbGroups", (int (SMESHDS_Mesh::*)() const ) &SMESHDS_Mesh::GetNbGroups, "None");
	cls_SMESHDS_Mesh.def("GetGroups", (const std::set<SMESHDS_GroupBase *> & (SMESHDS_Mesh::*)() const ) &SMESHDS_Mesh::GetGroups, "None");
	cls_SMESHDS_Mesh.def("IsGroupOfSubShapes", (bool (SMESHDS_Mesh::*)(const TopoDS_Shape &) const ) &SMESHDS_Mesh::IsGroupOfSubShapes, "None", py::arg("aSubShape"));
	cls_SMESHDS_Mesh.def("compactMesh", (void (SMESHDS_Mesh::*)()) &SMESHDS_Mesh::compactMesh, "None");
	cls_SMESHDS_Mesh.def("CleanDownWardConnectivity", (void (SMESHDS_Mesh::*)()) &SMESHDS_Mesh::CleanDownWardConnectivity, "None");
	cls_SMESHDS_Mesh.def("BuildDownWardConnectivity", (void (SMESHDS_Mesh::*)(bool)) &SMESHDS_Mesh::BuildDownWardConnectivity, "None", py::arg("withEdges"));

	// Callback for SMESHDS_GroupBase.
	class PyCallback_SMESHDS_GroupBase : public SMESHDS_GroupBase {
	public:
		using SMESHDS_GroupBase::SMESHDS_GroupBase;

		SMDS_ElemIteratorPtr GetElements() const  override { PYBIND11_OVERLOAD_PURE(SMDS_ElemIteratorPtr, SMESHDS_GroupBase, GetElements, ); }
		int GetTic() const  override { PYBIND11_OVERLOAD_PURE(int, SMESHDS_GroupBase, GetTic, ); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_GroupBase.hxx
	py::class_<SMESHDS_GroupBase, std::unique_ptr<SMESHDS_GroupBase, py::nodelete>, PyCallback_SMESHDS_GroupBase> cls_SMESHDS_GroupBase(mod, "SMESHDS_GroupBase", "None");
	cls_SMESHDS_GroupBase.def(py::init<const int, const SMESHDS_Mesh *, const SMDSAbs_ElementType>(), py::arg("theID"), py::arg("theMesh"), py::arg("theType"));
	cls_SMESHDS_GroupBase.def("GetID", (int (SMESHDS_GroupBase::*)() const ) &SMESHDS_GroupBase::GetID, "None");
	cls_SMESHDS_GroupBase.def("GetMesh", (const SMESHDS_Mesh * (SMESHDS_GroupBase::*)() const ) &SMESHDS_GroupBase::GetMesh, "None");
	cls_SMESHDS_GroupBase.def("SetType", (void (SMESHDS_GroupBase::*)(SMDSAbs_ElementType)) &SMESHDS_GroupBase::SetType, "None", py::arg("theType"));
	cls_SMESHDS_GroupBase.def("GetType", (SMDSAbs_ElementType (SMESHDS_GroupBase::*)() const ) &SMESHDS_GroupBase::GetType, "None");
	cls_SMESHDS_GroupBase.def("SetStoreName", (void (SMESHDS_GroupBase::*)(const char *)) &SMESHDS_GroupBase::SetStoreName, "None", py::arg("theName"));
	cls_SMESHDS_GroupBase.def("GetStoreName", (const char * (SMESHDS_GroupBase::*)() const ) &SMESHDS_GroupBase::GetStoreName, "None");
	cls_SMESHDS_GroupBase.def("Extent", (int (SMESHDS_GroupBase::*)() const ) &SMESHDS_GroupBase::Extent, "None");
	cls_SMESHDS_GroupBase.def("IsEmpty", (bool (SMESHDS_GroupBase::*)()) &SMESHDS_GroupBase::IsEmpty, "None");
	cls_SMESHDS_GroupBase.def("Contains", (bool (SMESHDS_GroupBase::*)(const int)) &SMESHDS_GroupBase::Contains, "None", py::arg("theID"));
	cls_SMESHDS_GroupBase.def("Contains", (bool (SMESHDS_GroupBase::*)(const SMDS_MeshElement *)) &SMESHDS_GroupBase::Contains, "None", py::arg("elem"));
	cls_SMESHDS_GroupBase.def("GetElements", (SMDS_ElemIteratorPtr (SMESHDS_GroupBase::*)() const ) &SMESHDS_GroupBase::GetElements, "None");
	cls_SMESHDS_GroupBase.def("GetID", (int (SMESHDS_GroupBase::*)(const int)) &SMESHDS_GroupBase::GetID, "None", py::arg("theIndex"));
	cls_SMESHDS_GroupBase.def("GetTic", (int (SMESHDS_GroupBase::*)() const ) &SMESHDS_GroupBase::GetTic, "None");
	cls_SMESHDS_GroupBase.def("SetColor", (void (SMESHDS_GroupBase::*)(const Quantity_Color &)) &SMESHDS_GroupBase::SetColor, "None", py::arg("theColor"));
	cls_SMESHDS_GroupBase.def("GetColor", (Quantity_Color (SMESHDS_GroupBase::*)() const ) &SMESHDS_GroupBase::GetColor, "None");
	cls_SMESHDS_GroupBase.def("SetColorGroup", (void (SMESHDS_GroupBase::*)(int)) &SMESHDS_GroupBase::SetColorGroup, "None", py::arg("theColorGroup"));
	cls_SMESHDS_GroupBase.def("GetColorGroup", (int (SMESHDS_GroupBase::*)() const ) &SMESHDS_GroupBase::GetColorGroup, "None");
	cls_SMESHDS_GroupBase.def_static("SetDefaultColor_", (void (*)(const Quantity_Color &)) &SMESHDS_GroupBase::SetDefaultColor, "None", py::arg("theColor"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_Document.hxx
	py::class_<SMESHDS_Document, std::unique_ptr<SMESHDS_Document, Deleter<SMESHDS_Document>>> cls_SMESHDS_Document(mod, "SMESHDS_Document", "None");
	cls_SMESHDS_Document.def(py::init<int>(), py::arg("UserID"));
	cls_SMESHDS_Document.def("NewMesh", (SMESHDS_Mesh * (SMESHDS_Document::*)(bool, int)) &SMESHDS_Document::NewMesh, "None", py::arg("theIsEmbeddedMode"), py::arg("MeshID"));
	cls_SMESHDS_Document.def("RemoveMesh", (void (SMESHDS_Document::*)(int)) &SMESHDS_Document::RemoveMesh, "None", py::arg("MeshID"));
	cls_SMESHDS_Document.def("GetMesh", (SMESHDS_Mesh * (SMESHDS_Document::*)(int)) &SMESHDS_Document::GetMesh, "None", py::arg("MeshID"));
	cls_SMESHDS_Document.def("AddHypothesis", (void (SMESHDS_Document::*)(SMESHDS_Hypothesis *)) &SMESHDS_Document::AddHypothesis, "None", py::arg("H"));
	cls_SMESHDS_Document.def("RemoveHypothesis", (void (SMESHDS_Document::*)(int)) &SMESHDS_Document::RemoveHypothesis, "None", py::arg("HypID"));
	cls_SMESHDS_Document.def("GetHypothesis", (SMESHDS_Hypothesis * (SMESHDS_Document::*)(int)) &SMESHDS_Document::GetHypothesis, "None", py::arg("HypID"));
	cls_SMESHDS_Document.def("NbMeshes", (int (SMESHDS_Document::*)()) &SMESHDS_Document::NbMeshes, "None");
	cls_SMESHDS_Document.def("NbHypothesis", (int (SMESHDS_Document::*)()) &SMESHDS_Document::NbHypothesis, "None");
	cls_SMESHDS_Document.def("InitMeshesIterator", (void (SMESHDS_Document::*)()) &SMESHDS_Document::InitMeshesIterator, "None");
	cls_SMESHDS_Document.def("NextMesh", (SMESHDS_Mesh * (SMESHDS_Document::*)()) &SMESHDS_Document::NextMesh, "None");
	cls_SMESHDS_Document.def("MoreMesh", (bool (SMESHDS_Document::*)()) &SMESHDS_Document::MoreMesh, "None");
	cls_SMESHDS_Document.def("InitHypothesisIterator", (void (SMESHDS_Document::*)()) &SMESHDS_Document::InitHypothesisIterator, "None");
	cls_SMESHDS_Document.def("NextHypothesis", (SMESHDS_Hypothesis * (SMESHDS_Document::*)()) &SMESHDS_Document::NextHypothesis, "None");
	cls_SMESHDS_Document.def("MoreHypothesis", (bool (SMESHDS_Document::*)()) &SMESHDS_Document::MoreHypothesis, "None");

	// Callback for SMESHDS_Hypothesis.
	class PyCallback_SMESHDS_Hypothesis : public SMESHDS_Hypothesis {
	public:
		using SMESHDS_Hypothesis::SMESHDS_Hypothesis;

		std::ostream & SaveTo(std::ostream & save) override { PYBIND11_OVERLOAD_PURE(std::ostream &, SMESHDS_Hypothesis, SaveTo, save); }
		std::istream & LoadFrom(std::istream & load) override { PYBIND11_OVERLOAD_PURE(std::istream &, SMESHDS_Hypothesis, LoadFrom, load); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_Hypothesis.hxx
	py::class_<SMESHDS_Hypothesis, std::unique_ptr<SMESHDS_Hypothesis, py::nodelete>, PyCallback_SMESHDS_Hypothesis> cls_SMESHDS_Hypothesis(mod, "SMESHDS_Hypothesis", "None");
	cls_SMESHDS_Hypothesis.def(py::init<int>(), py::arg("hypId"));
	cls_SMESHDS_Hypothesis.def("GetName", (const char * (SMESHDS_Hypothesis::*)() const ) &SMESHDS_Hypothesis::GetName, "None");
	cls_SMESHDS_Hypothesis.def("GetID", (int (SMESHDS_Hypothesis::*)() const ) &SMESHDS_Hypothesis::GetID, "None");
	cls_SMESHDS_Hypothesis.def("GetType", (int (SMESHDS_Hypothesis::*)() const ) &SMESHDS_Hypothesis::GetType, "None");
	cls_SMESHDS_Hypothesis.def("SaveTo", (std::ostream & (SMESHDS_Hypothesis::*)(std::ostream &)) &SMESHDS_Hypothesis::SaveTo, "None", py::arg("save"));
	cls_SMESHDS_Hypothesis.def("LoadFrom", (std::istream & (SMESHDS_Hypothesis::*)(std::istream &)) &SMESHDS_Hypothesis::LoadFrom, "None", py::arg("load"));
	cls_SMESHDS_Hypothesis.def("IsSameName", (bool (SMESHDS_Hypothesis::*)(const SMESHDS_Hypothesis &) const ) &SMESHDS_Hypothesis::IsSameName, "None", py::arg("other"));
	cls_SMESHDS_Hypothesis.def("__eq__", (bool (SMESHDS_Hypothesis::*)(const SMESHDS_Hypothesis &) const ) &SMESHDS_Hypothesis::operator==, py::is_operator(), "None", py::arg("other"));
	cls_SMESHDS_Hypothesis.def("__ne__", (bool (SMESHDS_Hypothesis::*)(const SMESHDS_Hypothesis &) const ) &SMESHDS_Hypothesis::operator!=, py::is_operator(), "None", py::arg("other"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_Hypothesis.hxx
	py::enum_<SMESHDS_Hypothesis::hypothesis_type>(cls_SMESHDS_Hypothesis, "hypothesis_type", "None")
		.value("PARAM_ALGO", SMESHDS_Hypothesis::hypothesis_type::PARAM_ALGO)
		.value("ALGO_0D", SMESHDS_Hypothesis::hypothesis_type::ALGO_0D)
		.value("ALGO_1D", SMESHDS_Hypothesis::hypothesis_type::ALGO_1D)
		.value("ALGO_2D", SMESHDS_Hypothesis::hypothesis_type::ALGO_2D)
		.value("ALGO_3D", SMESHDS_Hypothesis::hypothesis_type::ALGO_3D)
		.export_values();

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_SubMesh.hxx
	py::class_<SMESHDS_SubMesh, std::unique_ptr<SMESHDS_SubMesh, py::nodelete>> cls_SMESHDS_SubMesh(mod, "SMESHDS_SubMesh", "None");
	cls_SMESHDS_SubMesh.def(py::init<SMESHDS_Mesh *, int>(), py::arg("parent"), py::arg("index"));
	cls_SMESHDS_SubMesh.def("IsComplexSubmesh", (bool (SMESHDS_SubMesh::*)() const ) &SMESHDS_SubMesh::IsComplexSubmesh, "None");
	cls_SMESHDS_SubMesh.def("AddElement", (void (SMESHDS_SubMesh::*)(const SMDS_MeshElement *)) &SMESHDS_SubMesh::AddElement, "None", py::arg("ME"));
	cls_SMESHDS_SubMesh.def("RemoveElement", (bool (SMESHDS_SubMesh::*)(const SMDS_MeshElement *, bool)) &SMESHDS_SubMesh::RemoveElement, "None", py::arg("ME"), py::arg("isElemDeleted"));
	cls_SMESHDS_SubMesh.def("AddNode", (void (SMESHDS_SubMesh::*)(const SMDS_MeshNode *)) &SMESHDS_SubMesh::AddNode, "None", py::arg("ME"));
	cls_SMESHDS_SubMesh.def("RemoveNode", (bool (SMESHDS_SubMesh::*)(const SMDS_MeshNode *, bool)) &SMESHDS_SubMesh::RemoveNode, "None", py::arg("ME"), py::arg("isNodeDeleted"));
	cls_SMESHDS_SubMesh.def("GetElement", (const SMDS_MeshElement * (SMESHDS_SubMesh::*)(size_t) const ) &SMESHDS_SubMesh::GetElement, "None", py::arg("idInShape"));
	cls_SMESHDS_SubMesh.def("GetNode", (const SMDS_MeshNode * (SMESHDS_SubMesh::*)(size_t) const ) &SMESHDS_SubMesh::GetNode, "None", py::arg("idInShape"));
	cls_SMESHDS_SubMesh.def("AddSubMesh", (void (SMESHDS_SubMesh::*)(const SMESHDS_SubMesh *)) &SMESHDS_SubMesh::AddSubMesh, "None", py::arg("theSubMesh"));
	cls_SMESHDS_SubMesh.def("RemoveSubMesh", (bool (SMESHDS_SubMesh::*)(const SMESHDS_SubMesh *)) &SMESHDS_SubMesh::RemoveSubMesh, "None", py::arg("theSubMesh"));
	cls_SMESHDS_SubMesh.def("RemoveAllSubmeshes", (void (SMESHDS_SubMesh::*)()) &SMESHDS_SubMesh::RemoveAllSubmeshes, "None");
	cls_SMESHDS_SubMesh.def("ContainsSubMesh", (bool (SMESHDS_SubMesh::*)(const SMESHDS_SubMesh *) const ) &SMESHDS_SubMesh::ContainsSubMesh, "None", py::arg("theSubMesh"));
	cls_SMESHDS_SubMesh.def("NbSubMeshes", (int (SMESHDS_SubMesh::*)() const ) &SMESHDS_SubMesh::NbSubMeshes, "None");
	cls_SMESHDS_SubMesh.def("GetSubMeshIterator", (SMESHDS_SubMeshIteratorPtr (SMESHDS_SubMesh::*)() const ) &SMESHDS_SubMesh::GetSubMeshIterator, "None");
	cls_SMESHDS_SubMesh.def("NbElements", (int (SMESHDS_SubMesh::*)() const ) &SMESHDS_SubMesh::NbElements, "None");
	cls_SMESHDS_SubMesh.def("GetElements", [](SMESHDS_SubMesh &self) -> SMDS_ElemIteratorPtr { return self.GetElements(); });
	cls_SMESHDS_SubMesh.def("GetElements", (SMDS_ElemIteratorPtr (SMESHDS_SubMesh::*)(bool) const ) &SMESHDS_SubMesh::GetElements, "None", py::arg("reverse"));
	cls_SMESHDS_SubMesh.def("NbNodes", (int (SMESHDS_SubMesh::*)() const ) &SMESHDS_SubMesh::NbNodes, "None");
	cls_SMESHDS_SubMesh.def("GetNodes", [](SMESHDS_SubMesh &self) -> SMDS_NodeIteratorPtr { return self.GetNodes(); });
	cls_SMESHDS_SubMesh.def("GetNodes", (SMDS_NodeIteratorPtr (SMESHDS_SubMesh::*)(bool) const ) &SMESHDS_SubMesh::GetNodes, "None", py::arg("reverse"));
	cls_SMESHDS_SubMesh.def("Contains", (bool (SMESHDS_SubMesh::*)(const SMDS_MeshElement *) const ) &SMESHDS_SubMesh::Contains, "None", py::arg("ME"));
	cls_SMESHDS_SubMesh.def("IsQuadratic", (bool (SMESHDS_SubMesh::*)() const ) &SMESHDS_SubMesh::IsQuadratic, "None");
	cls_SMESHDS_SubMesh.def("Clear", (void (SMESHDS_SubMesh::*)()) &SMESHDS_SubMesh::Clear, "None");
	cls_SMESHDS_SubMesh.def("getSize", (int (SMESHDS_SubMesh::*)()) &SMESHDS_SubMesh::getSize, "None");
	cls_SMESHDS_SubMesh.def("compactList", (void (SMESHDS_SubMesh::*)()) &SMESHDS_SubMesh::compactList, "None");
	cls_SMESHDS_SubMesh.def("GetParent", (SMESHDS_Mesh * (SMESHDS_SubMesh::*)() const ) &SMESHDS_SubMesh::GetParent, "None");
	cls_SMESHDS_SubMesh.def("GetID", (int (SMESHDS_SubMesh::*)() const ) &SMESHDS_SubMesh::GetID, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_Command.hxx
	py::class_<SMESHDS_Command, std::unique_ptr<SMESHDS_Command, Deleter<SMESHDS_Command>>> cls_SMESHDS_Command(mod, "SMESHDS_Command", "None");
	cls_SMESHDS_Command.def(py::init<const SMESHDS_CommandType>(), py::arg("aType"));
	cls_SMESHDS_Command.def("AddNode", (void (SMESHDS_Command::*)(int, double, double, double)) &SMESHDS_Command::AddNode, "None", py::arg("NewNodeID"), py::arg("x"), py::arg("y"), py::arg("z"));
	cls_SMESHDS_Command.def("Add0DElement", (void (SMESHDS_Command::*)(int, int)) &SMESHDS_Command::Add0DElement, "None", py::arg("New0DElementID"), py::arg("idnode"));
	cls_SMESHDS_Command.def("AddEdge", (void (SMESHDS_Command::*)(int, int, int)) &SMESHDS_Command::AddEdge, "None", py::arg("NewEdgeID"), py::arg("idnode1"), py::arg("idnode2"));
	cls_SMESHDS_Command.def("AddFace", (void (SMESHDS_Command::*)(int, int, int, int)) &SMESHDS_Command::AddFace, "None", py::arg("NewFaceID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"));
	cls_SMESHDS_Command.def("AddFace", (void (SMESHDS_Command::*)(int, int, int, int, int)) &SMESHDS_Command::AddFace, "None", py::arg("NewFaceID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"));
	cls_SMESHDS_Command.def("AddVolume", (void (SMESHDS_Command::*)(int, int, int, int, int)) &SMESHDS_Command::AddVolume, "None", py::arg("NewVolID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"));
	cls_SMESHDS_Command.def("AddVolume", (void (SMESHDS_Command::*)(int, int, int, int, int, int)) &SMESHDS_Command::AddVolume, "None", py::arg("NewVolID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"), py::arg("idnode5"));
	cls_SMESHDS_Command.def("AddVolume", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int)) &SMESHDS_Command::AddVolume, "None", py::arg("NewVolID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"), py::arg("idnode5"), py::arg("idnode6"));
	cls_SMESHDS_Command.def("AddVolume", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int, int, int)) &SMESHDS_Command::AddVolume, "None", py::arg("NewVolID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"), py::arg("idnode5"), py::arg("idnode6"), py::arg("idnode7"), py::arg("idnode8"));
	cls_SMESHDS_Command.def("AddVolume", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Command::AddVolume, "None", py::arg("NewVolID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"), py::arg("idnode5"), py::arg("idnode6"), py::arg("idnode7"), py::arg("idnode8"), py::arg("idnode9"), py::arg("idnode10"), py::arg("idnode11"), py::arg("idnode12"));
	cls_SMESHDS_Command.def("AddPolygonalFace", (void (SMESHDS_Command::*)(const int, const std::vector<int> &)) &SMESHDS_Command::AddPolygonalFace, "None", py::arg("ElementID"), py::arg("nodes_ids"));
	cls_SMESHDS_Command.def("AddQuadPolygonalFace", (void (SMESHDS_Command::*)(const int, const std::vector<int> &)) &SMESHDS_Command::AddQuadPolygonalFace, "None", py::arg("ElementID"), py::arg("nodes_ids"));
	cls_SMESHDS_Command.def("AddPolyhedralVolume", (void (SMESHDS_Command::*)(const int, const std::vector<int> &, const std::vector<int> &)) &SMESHDS_Command::AddPolyhedralVolume, "None", py::arg("ElementID"), py::arg("nodes_ids"), py::arg("quantities"));
	cls_SMESHDS_Command.def("AddBall", (void (SMESHDS_Command::*)(int, int, double)) &SMESHDS_Command::AddBall, "None", py::arg("NewBallID"), py::arg("node"), py::arg("diameter"));
	cls_SMESHDS_Command.def("AddEdge", (void (SMESHDS_Command::*)(int, int, int, int)) &SMESHDS_Command::AddEdge, "None", py::arg("NewEdgeID"), py::arg("n1"), py::arg("n2"), py::arg("n12"));
	cls_SMESHDS_Command.def("AddFace", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int)) &SMESHDS_Command::AddFace, "None", py::arg("NewFaceID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"));
	cls_SMESHDS_Command.def("AddFace", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int, int)) &SMESHDS_Command::AddFace, "None", py::arg("NewFaceID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("nCenter"));
	cls_SMESHDS_Command.def("AddFace", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int, int, int)) &SMESHDS_Command::AddFace, "None", py::arg("NewFaceID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"));
	cls_SMESHDS_Command.def("AddFace", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Command::AddFace, "None", py::arg("NewFaceID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("nCenter"));
	cls_SMESHDS_Command.def("AddVolume", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Command::AddVolume, "None", py::arg("NewVolID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n14"), py::arg("n24"), py::arg("n34"));
	cls_SMESHDS_Command.def("AddVolume", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Command::AddVolume, "None", py::arg("NewVolID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n15"), py::arg("n25"), py::arg("n35"), py::arg("n45"));
	cls_SMESHDS_Command.def("AddVolume", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Command::AddVolume, "None", py::arg("NewVolID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n45"), py::arg("n56"), py::arg("n64"), py::arg("n14"), py::arg("n25"), py::arg("n36"));
	cls_SMESHDS_Command.def("AddVolume", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Command::AddVolume, "None", py::arg("NewVolID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"));
	cls_SMESHDS_Command.def("AddVolume", (void (SMESHDS_Command::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Command::AddVolume, "None", py::arg("NewVolID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("n1234"), py::arg("n1256"), py::arg("n2367"), py::arg("n3478"), py::arg("n1458"), py::arg("n5678"), py::arg("nCenter"));
	cls_SMESHDS_Command.def("MoveNode", (void (SMESHDS_Command::*)(int, double, double, double)) &SMESHDS_Command::MoveNode, "None", py::arg("NewNodeID"), py::arg("x"), py::arg("y"), py::arg("z"));
	cls_SMESHDS_Command.def("RemoveNode", (void (SMESHDS_Command::*)(int)) &SMESHDS_Command::RemoveNode, "None", py::arg("NodeID"));
	cls_SMESHDS_Command.def("RemoveElement", (void (SMESHDS_Command::*)(int)) &SMESHDS_Command::RemoveElement, "None", py::arg("ElementID"));
	// FIXME cls_SMESHDS_Command.def("ChangeElementNodes", (void (SMESHDS_Command::*)(int, int [], int)) &SMESHDS_Command::ChangeElementNodes, "None", py::arg("ElementID"), py::arg("nodes"), py::arg("nbnodes"));
	cls_SMESHDS_Command.def("ChangePolyhedronNodes", (void (SMESHDS_Command::*)(const int, const std::vector<int> &, const std::vector<int> &)) &SMESHDS_Command::ChangePolyhedronNodes, "None", py::arg("ElementID"), py::arg("nodes_ids"), py::arg("quantities"));
	cls_SMESHDS_Command.def("Renumber", (void (SMESHDS_Command::*)(const bool, const int, const int)) &SMESHDS_Command::Renumber, "None", py::arg("isNodes"), py::arg("startID"), py::arg("deltaID"));
	cls_SMESHDS_Command.def("GetType", (SMESHDS_CommandType (SMESHDS_Command::*)()) &SMESHDS_Command::GetType, "None");
	cls_SMESHDS_Command.def("GetNumber", (int (SMESHDS_Command::*)()) &SMESHDS_Command::GetNumber, "None");
	cls_SMESHDS_Command.def("GetIndexes", (const std::list<int> & (SMESHDS_Command::*)()) &SMESHDS_Command::GetIndexes, "None");
	cls_SMESHDS_Command.def("GetCoords", (const std::list<double> & (SMESHDS_Command::*)()) &SMESHDS_Command::GetCoords, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_DataMapOfShape.hxx
	py::class_<SMESHDS_Hasher, std::unique_ptr<SMESHDS_Hasher, Deleter<SMESHDS_Hasher>>> cls_SMESHDS_Hasher(mod, "SMESHDS_Hasher", "None");
	cls_SMESHDS_Hasher.def(py::init<>());
	cls_SMESHDS_Hasher.def_static("IsEqual_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &SMESHDS_Hasher::IsEqual, "None", py::arg("S1"), py::arg("S2"));
	cls_SMESHDS_Hasher.def_static("HashCode_", (Standard_Integer (*)(const TopoDS_Shape &, const Standard_Integer)) &SMESHDS_Hasher::HashCode, "None", py::arg("S"), py::arg("Upper"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_Script.hxx
	py::class_<SMESHDS_Script, std::unique_ptr<SMESHDS_Script, py::nodelete>> cls_SMESHDS_Script(mod, "SMESHDS_Script", "None");
	cls_SMESHDS_Script.def(py::init<bool>(), py::arg("theIsEmbeddedMode"));
	cls_SMESHDS_Script.def("SetModified", (void (SMESHDS_Script::*)(bool)) &SMESHDS_Script::SetModified, "None", py::arg("theModified"));
	cls_SMESHDS_Script.def("IsModified", (bool (SMESHDS_Script::*)()) &SMESHDS_Script::IsModified, "None");
	cls_SMESHDS_Script.def("AddNode", (void (SMESHDS_Script::*)(int, double, double, double)) &SMESHDS_Script::AddNode, "None", py::arg("NewNodeID"), py::arg("x"), py::arg("y"), py::arg("z"));
	cls_SMESHDS_Script.def("Add0DElement", (void (SMESHDS_Script::*)(int, int)) &SMESHDS_Script::Add0DElement, "None", py::arg("New0DElementID"), py::arg("idnode"));
	cls_SMESHDS_Script.def("AddEdge", (void (SMESHDS_Script::*)(int, int, int)) &SMESHDS_Script::AddEdge, "None", py::arg("NewEdgeID"), py::arg("idnode1"), py::arg("idnode2"));
	cls_SMESHDS_Script.def("AddFace", (void (SMESHDS_Script::*)(int, int, int, int)) &SMESHDS_Script::AddFace, "None", py::arg("NewFaceID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"));
	cls_SMESHDS_Script.def("AddFace", (void (SMESHDS_Script::*)(int, int, int, int, int)) &SMESHDS_Script::AddFace, "None", py::arg("NewFaceID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"));
	cls_SMESHDS_Script.def("AddVolume", (void (SMESHDS_Script::*)(int, int, int, int, int)) &SMESHDS_Script::AddVolume, "None", py::arg("NewVolID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"));
	cls_SMESHDS_Script.def("AddVolume", (void (SMESHDS_Script::*)(int, int, int, int, int, int)) &SMESHDS_Script::AddVolume, "None", py::arg("NewVolID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"), py::arg("idnode5"));
	cls_SMESHDS_Script.def("AddVolume", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int)) &SMESHDS_Script::AddVolume, "None", py::arg("NewVolID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"), py::arg("idnode5"), py::arg("idnode6"));
	cls_SMESHDS_Script.def("AddVolume", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int, int, int)) &SMESHDS_Script::AddVolume, "None", py::arg("NewVolID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"), py::arg("idnode5"), py::arg("idnode6"), py::arg("idnode7"), py::arg("idnode8"));
	cls_SMESHDS_Script.def("AddVolume", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Script::AddVolume, "None", py::arg("NewVolID"), py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"), py::arg("idnode5"), py::arg("idnode6"), py::arg("idnode7"), py::arg("idnode8"), py::arg("idnode9"), py::arg("idnode10"), py::arg("idnode11"), py::arg("idnode12"));
	cls_SMESHDS_Script.def("AddPolygonalFace", (void (SMESHDS_Script::*)(const int, const std::vector<int> &)) &SMESHDS_Script::AddPolygonalFace, "None", py::arg("NewFaceID"), py::arg("nodes_ids"));
	cls_SMESHDS_Script.def("AddQuadPolygonalFace", (void (SMESHDS_Script::*)(const int, const std::vector<int> &)) &SMESHDS_Script::AddQuadPolygonalFace, "None", py::arg("NewFaceID"), py::arg("nodes_ids"));
	cls_SMESHDS_Script.def("AddPolyhedralVolume", (void (SMESHDS_Script::*)(const int, const std::vector<int> &, const std::vector<int> &)) &SMESHDS_Script::AddPolyhedralVolume, "None", py::arg("NewVolID"), py::arg("nodes_ids"), py::arg("quantities"));
	cls_SMESHDS_Script.def("AddBall", (void (SMESHDS_Script::*)(int, int, double)) &SMESHDS_Script::AddBall, "None", py::arg("NewBallID"), py::arg("node"), py::arg("diameter"));
	cls_SMESHDS_Script.def("AddEdge", (void (SMESHDS_Script::*)(int, int, int, int)) &SMESHDS_Script::AddEdge, "None", py::arg("NewEdgeID"), py::arg("n1"), py::arg("n2"), py::arg("n12"));
	cls_SMESHDS_Script.def("AddFace", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int)) &SMESHDS_Script::AddFace, "None", py::arg("NewFaceID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"));
	cls_SMESHDS_Script.def("AddFace", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int, int)) &SMESHDS_Script::AddFace, "None", py::arg("NewFaceID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("nCenter"));
	cls_SMESHDS_Script.def("AddFace", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int, int, int)) &SMESHDS_Script::AddFace, "None", py::arg("NewFaceID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"));
	cls_SMESHDS_Script.def("AddFace", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Script::AddFace, "None", py::arg("NewFaceID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("nCenter"));
	cls_SMESHDS_Script.def("AddVolume", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Script::AddVolume, "None", py::arg("NewVolID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n14"), py::arg("n24"), py::arg("n34"));
	cls_SMESHDS_Script.def("AddVolume", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Script::AddVolume, "None", py::arg("NewVolID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n15"), py::arg("n25"), py::arg("n35"), py::arg("n45"));
	cls_SMESHDS_Script.def("AddVolume", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Script::AddVolume, "None", py::arg("NewVolID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n45"), py::arg("n56"), py::arg("n64"), py::arg("n14"), py::arg("n25"), py::arg("n36"));
	cls_SMESHDS_Script.def("AddVolume", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Script::AddVolume, "None", py::arg("NewVolID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"));
	cls_SMESHDS_Script.def("AddVolume", (void (SMESHDS_Script::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMESHDS_Script::AddVolume, "None", py::arg("NewVolID"), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("n1234"), py::arg("n1256"), py::arg("n2367"), py::arg("n3478"), py::arg("n1458"), py::arg("n5678"), py::arg("nCenter"));
	cls_SMESHDS_Script.def("MoveNode", (void (SMESHDS_Script::*)(int, double, double, double)) &SMESHDS_Script::MoveNode, "None", py::arg("NewNodeID"), py::arg("x"), py::arg("y"), py::arg("z"));
	cls_SMESHDS_Script.def("RemoveNode", (void (SMESHDS_Script::*)(int)) &SMESHDS_Script::RemoveNode, "None", py::arg("NodeID"));
	cls_SMESHDS_Script.def("RemoveElement", (void (SMESHDS_Script::*)(int)) &SMESHDS_Script::RemoveElement, "None", py::arg("ElementID"));
	// FIXME cls_SMESHDS_Script.def("ChangeElementNodes", (void (SMESHDS_Script::*)(int, int [], int)) &SMESHDS_Script::ChangeElementNodes, "None", py::arg("ElementID"), py::arg("nodes"), py::arg("nbnodes"));
	cls_SMESHDS_Script.def("ChangePolyhedronNodes", (void (SMESHDS_Script::*)(const int, const std::vector<int> &, const std::vector<int> &)) &SMESHDS_Script::ChangePolyhedronNodes, "None", py::arg("ElementID"), py::arg("nodes_ids"), py::arg("quantities"));
	cls_SMESHDS_Script.def("Renumber", (void (SMESHDS_Script::*)(const bool, const int, const int)) &SMESHDS_Script::Renumber, "None", py::arg("isNodes"), py::arg("startID"), py::arg("deltaID"));
	cls_SMESHDS_Script.def("ClearMesh", (void (SMESHDS_Script::*)()) &SMESHDS_Script::ClearMesh, "None");
	cls_SMESHDS_Script.def("Clear", (void (SMESHDS_Script::*)()) &SMESHDS_Script::Clear, "None");
	cls_SMESHDS_Script.def("GetCommands", (const std::list<SMESHDS_Command *> & (SMESHDS_Script::*)()) &SMESHDS_Script::GetCommands, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_Group.hxx
	py::class_<SMESHDS_Group, std::unique_ptr<SMESHDS_Group, py::nodelete>, SMESHDS_GroupBase> cls_SMESHDS_Group(mod, "SMESHDS_Group", "None");
	cls_SMESHDS_Group.def(py::init<const int, const SMESHDS_Mesh *, const SMDSAbs_ElementType>(), py::arg("theID"), py::arg("theMesh"), py::arg("theType"));
	cls_SMESHDS_Group.def("SetType", (void (SMESHDS_Group::*)(SMDSAbs_ElementType)) &SMESHDS_Group::SetType, "None", py::arg("theType"));
	cls_SMESHDS_Group.def("Extent", (int (SMESHDS_Group::*)() const ) &SMESHDS_Group::Extent, "None");
	cls_SMESHDS_Group.def("IsEmpty", (bool (SMESHDS_Group::*)()) &SMESHDS_Group::IsEmpty, "None");
	cls_SMESHDS_Group.def("Contains", (bool (SMESHDS_Group::*)(const int)) &SMESHDS_Group::Contains, "None", py::arg("theID"));
	cls_SMESHDS_Group.def("Contains", (bool (SMESHDS_Group::*)(const SMDS_MeshElement *)) &SMESHDS_Group::Contains, "None", py::arg("elem"));
	cls_SMESHDS_Group.def("GetElements", (SMDS_ElemIteratorPtr (SMESHDS_Group::*)() const ) &SMESHDS_Group::GetElements, "None");
	cls_SMESHDS_Group.def("GetTic", (int (SMESHDS_Group::*)() const ) &SMESHDS_Group::GetTic, "None");
	cls_SMESHDS_Group.def("Add", (bool (SMESHDS_Group::*)(const int)) &SMESHDS_Group::Add, "None", py::arg("theID"));
	cls_SMESHDS_Group.def("Add", (bool (SMESHDS_Group::*)(const SMDS_MeshElement *)) &SMESHDS_Group::Add, "None", py::arg("theElem"));
	cls_SMESHDS_Group.def("Remove", (bool (SMESHDS_Group::*)(const int)) &SMESHDS_Group::Remove, "None", py::arg("theID"));
	cls_SMESHDS_Group.def("Clear", (void (SMESHDS_Group::*)()) &SMESHDS_Group::Clear, "None");
	cls_SMESHDS_Group.def("SMDSGroup", (SMDS_MeshGroup & (SMESHDS_Group::*)()) &SMESHDS_Group::SMDSGroup, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_GroupOnFilter.hxx
	py::class_<SMESHDS_GroupOnFilter, std::unique_ptr<SMESHDS_GroupOnFilter, py::nodelete>, SMESHDS_GroupBase> cls_SMESHDS_GroupOnFilter(mod, "SMESHDS_GroupOnFilter", "Groups whose contents is dynamically updated using the filter");
	cls_SMESHDS_GroupOnFilter.def(py::init<const int, const SMESHDS_Mesh *, const SMDSAbs_ElementType, const SMESH_PredicatePtr &>(), py::arg("theID"), py::arg("theMesh"), py::arg("theType"), py::arg("thePredicate"), py::call_guard<ImportSMESH>());
	cls_SMESHDS_GroupOnFilter.def("SetPredicate", (void (SMESHDS_GroupOnFilter::*)(const SMESH_PredicatePtr &)) &SMESHDS_GroupOnFilter::SetPredicate, "None", py::arg("thePredicate"), py::call_guard<ImportSMESH>());
	cls_SMESHDS_GroupOnFilter.def("GetPredicate", (SMESH_PredicatePtr (SMESHDS_GroupOnFilter::*)() const ) &SMESHDS_GroupOnFilter::GetPredicate, "None", py::call_guard<ImportSMESH>());
	cls_SMESHDS_GroupOnFilter.def("GetMeshInfo", (std::vector<int> (SMESHDS_GroupOnFilter::*)() const ) &SMESHDS_GroupOnFilter::GetMeshInfo, "None");
	cls_SMESHDS_GroupOnFilter.def("Extent", (int (SMESHDS_GroupOnFilter::*)() const ) &SMESHDS_GroupOnFilter::Extent, "None");
	cls_SMESHDS_GroupOnFilter.def("IsEmpty", (bool (SMESHDS_GroupOnFilter::*)()) &SMESHDS_GroupOnFilter::IsEmpty, "None");
	cls_SMESHDS_GroupOnFilter.def("Contains", (bool (SMESHDS_GroupOnFilter::*)(const int)) &SMESHDS_GroupOnFilter::Contains, "None", py::arg("theID"));
	cls_SMESHDS_GroupOnFilter.def("Contains", (bool (SMESHDS_GroupOnFilter::*)(const SMDS_MeshElement *)) &SMESHDS_GroupOnFilter::Contains, "None", py::arg("elem"));
	cls_SMESHDS_GroupOnFilter.def("GetElements", (SMDS_ElemIteratorPtr (SMESHDS_GroupOnFilter::*)() const ) &SMESHDS_GroupOnFilter::GetElements, "None");
	cls_SMESHDS_GroupOnFilter.def("GetTic", (int (SMESHDS_GroupOnFilter::*)() const ) &SMESHDS_GroupOnFilter::GetTic, "None");
	cls_SMESHDS_GroupOnFilter.def("IsUpToDate", (bool (SMESHDS_GroupOnFilter::*)() const ) &SMESHDS_GroupOnFilter::IsUpToDate, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_GroupOnGeom.hxx
	py::class_<SMESHDS_GroupOnGeom, std::unique_ptr<SMESHDS_GroupOnGeom, py::nodelete>, SMESHDS_GroupBase> cls_SMESHDS_GroupOnGeom(mod, "SMESHDS_GroupOnGeom", "None");
	cls_SMESHDS_GroupOnGeom.def(py::init<const int, const SMESHDS_Mesh *, const SMDSAbs_ElementType, const TopoDS_Shape &>(), py::arg("theID"), py::arg("theMesh"), py::arg("theType"), py::arg("theShape"));
	cls_SMESHDS_GroupOnGeom.def("SetShape", (void (SMESHDS_GroupOnGeom::*)(const TopoDS_Shape &)) &SMESHDS_GroupOnGeom::SetShape, "None", py::arg("theShape"));
	cls_SMESHDS_GroupOnGeom.def("GetShape", (TopoDS_Shape (SMESHDS_GroupOnGeom::*)() const ) &SMESHDS_GroupOnGeom::GetShape, "None");
	cls_SMESHDS_GroupOnGeom.def("Contains", (bool (SMESHDS_GroupOnGeom::*)(const int)) &SMESHDS_GroupOnGeom::Contains, "None", py::arg("theID"));
	cls_SMESHDS_GroupOnGeom.def("Contains", (bool (SMESHDS_GroupOnGeom::*)(const SMDS_MeshElement *)) &SMESHDS_GroupOnGeom::Contains, "None", py::arg("elem"));
	cls_SMESHDS_GroupOnGeom.def("GetElements", (SMDS_ElemIteratorPtr (SMESHDS_GroupOnGeom::*)() const ) &SMESHDS_GroupOnGeom::GetElements, "None");
	cls_SMESHDS_GroupOnGeom.def("GetTic", (int (SMESHDS_GroupOnGeom::*)() const ) &SMESHDS_GroupOnGeom::GetTic, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_SubMesh.hxx
	bind_SMDS_Iterator<const SMESHDS_SubMesh *>(mod, "SMESHDS_SubMeshIterator");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_SubMesh.hxx
	// FIXME bind_boost::shared_ptr<SMDS_Iterator<const SMESHDS_SubMesh *> >(mod, "SMESHDS_SubMeshIteratorPtr");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_Mesh.hxx
	// FIXME bind_std::list<const SMESHDS_Hypothesis *, std::allocator<const SMESHDS_Hypothesis *> >(mod, "THypList");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_Mesh.hxx
	bind_NCollection_DataMap<TopoDS_Shape, std::list<const SMESHDS_Hypothesis *, std::allocator<const SMESHDS_Hypothesis *> >, SMESHDS_Hasher>(mod, "ShapeToHypothesis", py::module_local(false));


}
