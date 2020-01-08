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

#include <SMDS_MeshObject.hxx>
#include <SMDS_ElemIterator.hxx>
#include <SMDSAbs_ElementType.hxx>
#include <SMDS_MeshElement.hxx>
#include <vtkType.h>
#include <SMDS_MeshNode.hxx>
#include <SMDS_UnstructuredGrid.hxx>
#include <SMDS_Mesh.hxx>
#include <SMDS_Mesh0DElement.hxx>
#include <SMDS_BallElement.hxx>
#include <SMDS_MeshEdge.hxx>
#include <SMDS_MeshFace.hxx>
#include <SMDS_MeshVolume.hxx>
#include <SMDS_MeshInfo.hxx>
#include <SMDS_Position.hxx>
#include <SMDS_MeshCell.hxx>
#include <SMDS_MeshGroup.hxx>
#include <SMDS_MeshIDFactory.hxx>
#include <SMDS_MeshNodeIDFactory.hxx>
#include <SMDS_MeshElementIDFactory.hxx>
#include <SMDS_StdIterator.hxx>
#include <SMDS_TypeOfPosition.hxx>
#include <vtkCellType.h>
#include <SMDS_VolumeOfNodes.hxx>
#include <SMDS_VtkEdge.hxx>
#include <SMDS_VtkFace.hxx>
#include <SMDS_Downward.hxx>
#include <vtkCellLinks.h>
#include <vtkDataSet.h>
#include <vtkUnstructuredGrid.h>
#include <vtkPoints.h>
#include <SMDS_VtkVolume.hxx>
#include <SMDS_EdgePosition.hxx>
#include <SMDS_FaceOfEdges.hxx>
#include <SMDS_FaceOfNodes.hxx>
#include <SMDS_FacePosition.hxx>
#include <SMDS_IteratorOfElements.hxx>
#include <SMDS_Iterator.hxx>
#include <SMDS_LinearEdge.hxx>
#include <SMDS_PolygonalFaceOfNodes.hxx>
#include <SMDS_PolyhedralVolumeOfNodes.hxx>
#include <SMDS_QuadraticEdge.hxx>
#include <SMDS_QuadraticFaceOfNodes.hxx>
#include <SMDS_QuadraticVolumeOfNodes.hxx>
#include <SMDS_SetIterator.hxx>
#include <SMDS_SpacePosition.hxx>
#include <SMDS_VertexPosition.hxx>
#include <SMDS_VolumeOfFaces.hxx>
#include <SMDS_VolumeTool.hxx>
#include <SMDS_VtkCellIterator.hxx>
#include <SMDS_Templates.hxx>
#include <STL_Templates.hxx>

// Define this to avoid a link error?
int SMDS_Mesh::chunkSize = 1024;

PYBIND11_MODULE(SMDS, mod) {

	// IMPORT
	py::module::import("OCCT.SMDSAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_TypeOfPosition.hxx
	py::enum_<SMDS_TypeOfPosition>(mod, "SMDS_TypeOfPosition", "None")
		.value("SMDS_TOP_UNSPEC", SMDS_TypeOfPosition::SMDS_TOP_UNSPEC)
		.value("SMDS_TOP_VERTEX", SMDS_TypeOfPosition::SMDS_TOP_VERTEX)
		.value("SMDS_TOP_EDGE", SMDS_TypeOfPosition::SMDS_TOP_EDGE)
		.value("SMDS_TOP_FACE", SMDS_TypeOfPosition::SMDS_TOP_FACE)
		.value("SMDS_TOP_3DSPACE", SMDS_TypeOfPosition::SMDS_TOP_3DSPACE)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshObject.hxx
	py::class_<SMDS_MeshObject, std::unique_ptr<SMDS_MeshObject, py::nodelete>> cls_SMDS_MeshObject(mod, "SMDS_MeshObject", "None");
	cls_SMDS_MeshObject.def(py::init<>());

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Mesh.hxx
	py::class_<SMDS_Mesh, std::unique_ptr<SMDS_Mesh, py::nodelete>, SMDS_MeshObject> cls_SMDS_Mesh(mod, "SMDS_Mesh", "None");
	cls_SMDS_Mesh.def(py::init<>());
	cls_SMDS_Mesh.def("getGrid", (SMDS_UnstructuredGrid * (SMDS_Mesh::*)()) &SMDS_Mesh::getGrid, "actual nodes coordinates, cells definition and reverse connectivity are stored in a vtkUnstructuredGrid");
	cls_SMDS_Mesh.def("getMeshId", (int (SMDS_Mesh::*)()) &SMDS_Mesh::getMeshId, "None");
	cls_SMDS_Mesh.def("nodesIterator", [](SMDS_Mesh &self) -> SMDS_NodeIteratorPtr { return self.nodesIterator(); });
	cls_SMDS_Mesh.def("nodesIterator", (SMDS_NodeIteratorPtr (SMDS_Mesh::*)(bool) const ) &SMDS_Mesh::nodesIterator, "None", py::arg("idInceasingOrder"));
	cls_SMDS_Mesh.def("edgesIterator", [](SMDS_Mesh &self) -> SMDS_EdgeIteratorPtr { return self.edgesIterator(); });
	cls_SMDS_Mesh.def("edgesIterator", (SMDS_EdgeIteratorPtr (SMDS_Mesh::*)(bool) const ) &SMDS_Mesh::edgesIterator, "None", py::arg("idInceasingOrder"));
	cls_SMDS_Mesh.def("facesIterator", [](SMDS_Mesh &self) -> SMDS_FaceIteratorPtr { return self.facesIterator(); });
	cls_SMDS_Mesh.def("facesIterator", (SMDS_FaceIteratorPtr (SMDS_Mesh::*)(bool) const ) &SMDS_Mesh::facesIterator, "None", py::arg("idInceasingOrder"));
	cls_SMDS_Mesh.def("volumesIterator", [](SMDS_Mesh &self) -> SMDS_VolumeIteratorPtr { return self.volumesIterator(); });
	cls_SMDS_Mesh.def("volumesIterator", (SMDS_VolumeIteratorPtr (SMDS_Mesh::*)(bool) const ) &SMDS_Mesh::volumesIterator, "None", py::arg("idInceasingOrder"));
	cls_SMDS_Mesh.def("elementsIterator", [](SMDS_Mesh &self) -> SMDS_ElemIteratorPtr { return self.elementsIterator(); });
	cls_SMDS_Mesh.def("elementsIterator", (SMDS_ElemIteratorPtr (SMDS_Mesh::*)(SMDSAbs_ElementType) const ) &SMDS_Mesh::elementsIterator, "None", py::arg("type"));
	cls_SMDS_Mesh.def("elementGeomIterator", (SMDS_ElemIteratorPtr (SMDS_Mesh::*)(SMDSAbs_GeometryType) const ) &SMDS_Mesh::elementGeomIterator, "None", py::arg("type"));
	cls_SMDS_Mesh.def("elementEntityIterator", (SMDS_ElemIteratorPtr (SMDS_Mesh::*)(SMDSAbs_EntityType) const ) &SMDS_Mesh::elementEntityIterator, "None", py::arg("type"));
	cls_SMDS_Mesh.def("GetElementType", (SMDSAbs_ElementType (SMDS_Mesh::*)(const int, const bool) const ) &SMDS_Mesh::GetElementType, "None", py::arg("id"), py::arg("iselem"));
	cls_SMDS_Mesh.def("AddSubMesh", (SMDS_Mesh * (SMDS_Mesh::*)()) &SMDS_Mesh::AddSubMesh, "None");
	cls_SMDS_Mesh.def("AddNodeWithID", (SMDS_MeshNode * (SMDS_Mesh::*)(double, double, double, int)) &SMDS_Mesh::AddNodeWithID, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddNode", (SMDS_MeshNode * (SMDS_Mesh::*)(double, double, double)) &SMDS_Mesh::AddNode, "None", py::arg("x"), py::arg("y"), py::arg("z"));
	cls_SMDS_Mesh.def("Add0DElementWithID", (SMDS_Mesh0DElement * (SMDS_Mesh::*)(int, int)) &SMDS_Mesh::Add0DElementWithID, "None", py::arg("n"), py::arg("ID"));
	cls_SMDS_Mesh.def("Add0DElementWithID", (SMDS_Mesh0DElement * (SMDS_Mesh::*)(const SMDS_MeshNode *, int)) &SMDS_Mesh::Add0DElementWithID, "None", py::arg("n"), py::arg("ID"));
	cls_SMDS_Mesh.def("Add0DElement", (SMDS_Mesh0DElement * (SMDS_Mesh::*)(const SMDS_MeshNode *)) &SMDS_Mesh::Add0DElement, "None", py::arg("n"));
	cls_SMDS_Mesh.def("AddBallWithID", (SMDS_BallElement * (SMDS_Mesh::*)(int, double, int)) &SMDS_Mesh::AddBallWithID, "None", py::arg("n"), py::arg("diameter"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddBallWithID", (SMDS_BallElement * (SMDS_Mesh::*)(const SMDS_MeshNode *, double, int)) &SMDS_Mesh::AddBallWithID, "None", py::arg("n"), py::arg("diameter"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddBall", (SMDS_BallElement * (SMDS_Mesh::*)(const SMDS_MeshNode *, double)) &SMDS_Mesh::AddBall, "None", py::arg("n"), py::arg("diameter"));
	cls_SMDS_Mesh.def("AddEdgeWithID", (SMDS_MeshEdge * (SMDS_Mesh::*)(int, int, int)) &SMDS_Mesh::AddEdgeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddEdgeWithID", (SMDS_MeshEdge * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddEdgeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddEdge", (SMDS_MeshEdge * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddEdge, "None", py::arg("n1"), py::arg("n2"));
	cls_SMDS_Mesh.def("AddEdgeWithID", (SMDS_MeshEdge * (SMDS_Mesh::*)(int, int, int, int)) &SMDS_Mesh::AddEdgeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n12"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddEdgeWithID", (SMDS_MeshEdge * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddEdgeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n12"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddEdge", (SMDS_MeshEdge * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddEdge, "None", py::arg("n1"), py::arg("n2"), py::arg("n12"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(int, int, int, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(int, int, int, int, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshEdge *, const SMDS_MeshEdge *, const SMDS_MeshEdge *, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("e1"), py::arg("e2"), py::arg("e3"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshEdge *, const SMDS_MeshEdge *, const SMDS_MeshEdge *)) &SMDS_Mesh::AddFace, "None", py::arg("e1"), py::arg("e2"), py::arg("e3"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshEdge *, const SMDS_MeshEdge *, const SMDS_MeshEdge *, const SMDS_MeshEdge *, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("e1"), py::arg("e2"), py::arg("e3"), py::arg("e4"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshEdge *, const SMDS_MeshEdge *, const SMDS_MeshEdge *, const SMDS_MeshEdge *)) &SMDS_Mesh::AddFace, "None", py::arg("e1"), py::arg("e2"), py::arg("e3"), py::arg("e4"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(int, int, int, int, int, int, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(int, int, int, int, int, int, int, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("nCenter"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("nCenter"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("nCenter"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(int, int, int, int, int, int, int, int, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("nCenter"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddFaceWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("nCenter"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFace", (SMDS_MeshFace * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("nCenter"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(int, int, int, int, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(int, int, int, int, int, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(int, int, int, int, int, int, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(int, int, int, int, int, int, int, int, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("f1"), py::arg("f2"), py::arg("f3"), py::arg("f4"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *)) &SMDS_Mesh::AddVolume, "None", py::arg("f1"), py::arg("f2"), py::arg("f3"), py::arg("f4"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("f1"), py::arg("f2"), py::arg("f3"), py::arg("f4"), py::arg("f5"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *)) &SMDS_Mesh::AddVolume, "None", py::arg("f1"), py::arg("f2"), py::arg("f3"), py::arg("f4"), py::arg("f5"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("f1"), py::arg("f2"), py::arg("f3"), py::arg("f4"), py::arg("f5"), py::arg("f6"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *)) &SMDS_Mesh::AddVolume, "None", py::arg("f1"), py::arg("f2"), py::arg("f3"), py::arg("f4"), py::arg("f5"), py::arg("f6"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n9"), py::arg("n10"), py::arg("n11"), py::arg("n12"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n9"), py::arg("n10"), py::arg("n11"), py::arg("n12"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n9"), py::arg("n10"), py::arg("n11"), py::arg("n12"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n14"), py::arg("n24"), py::arg("n34"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n14"), py::arg("n24"), py::arg("n34"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n14"), py::arg("n24"), py::arg("n34"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n15"), py::arg("n25"), py::arg("n35"), py::arg("n45"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n15"), py::arg("n25"), py::arg("n35"), py::arg("n45"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n15"), py::arg("n25"), py::arg("n35"), py::arg("n45"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n45"), py::arg("n56"), py::arg("n64"), py::arg("n14"), py::arg("n25"), py::arg("n36"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n45"), py::arg("n56"), py::arg("n64"), py::arg("n14"), py::arg("n25"), py::arg("n36"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n45"), py::arg("n56"), py::arg("n64"), py::arg("n14"), py::arg("n25"), py::arg("n36"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("n1234"), py::arg("n1256"), py::arg("n2367"), py::arg("n3478"), py::arg("n1458"), py::arg("n5678"), py::arg("nCenter"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, int)) &SMDS_Mesh::AddVolumeWithID, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("n1234"), py::arg("n1256"), py::arg("n2367"), py::arg("n3478"), py::arg("n1458"), py::arg("n5678"), py::arg("nCenter"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::AddVolume, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"), py::arg("n1234"), py::arg("n1256"), py::arg("n2367"), py::arg("n3478"), py::arg("n1458"), py::arg("n5678"), py::arg("nCenter"));
	cls_SMDS_Mesh.def("AddPolygonalFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const std::vector<int> &, const int)) &SMDS_Mesh::AddPolygonalFaceWithID, "None", py::arg("nodes_ids"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddPolygonalFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &, const int)) &SMDS_Mesh::AddPolygonalFaceWithID, "None", py::arg("nodes"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddPolygonalFace", (SMDS_MeshFace * (SMDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &)) &SMDS_Mesh::AddPolygonalFace, "None", py::arg("nodes"));
	cls_SMDS_Mesh.def("AddQuadPolygonalFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const std::vector<int> &, const int)) &SMDS_Mesh::AddQuadPolygonalFaceWithID, "None", py::arg("nodes_ids"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddQuadPolygonalFaceWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &, const int)) &SMDS_Mesh::AddQuadPolygonalFaceWithID, "None", py::arg("nodes"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddQuadPolygonalFace", (SMDS_MeshFace * (SMDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &)) &SMDS_Mesh::AddQuadPolygonalFace, "None", py::arg("nodes"));
	cls_SMDS_Mesh.def("AddPolyhedralVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const std::vector<int> &, const std::vector<int> &, const int)) &SMDS_Mesh::AddPolyhedralVolumeWithID, "None", py::arg("nodes_ids"), py::arg("quantities"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddPolyhedralVolumeWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &, const std::vector<int> &, const int)) &SMDS_Mesh::AddPolyhedralVolumeWithID, "None", py::arg("nodes"), py::arg("quantities"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddPolyhedralVolume", (SMDS_MeshVolume * (SMDS_Mesh::*)(const std::vector<const SMDS_MeshNode *> &, const std::vector<int> &)) &SMDS_Mesh::AddPolyhedralVolume, "None", py::arg("nodes"), py::arg("quantities"));
	cls_SMDS_Mesh.def("AddVolumeFromVtkIds", (SMDS_MeshVolume * (SMDS_Mesh::*)(const std::vector<vtkIdType> &)) &SMDS_Mesh::AddVolumeFromVtkIds, "None", py::arg("vtkNodeIds"));
	cls_SMDS_Mesh.def("AddVolumeFromVtkIdsWithID", (SMDS_MeshVolume * (SMDS_Mesh::*)(const std::vector<vtkIdType> &, const int)) &SMDS_Mesh::AddVolumeFromVtkIdsWithID, "None", py::arg("vtkNodeIds"), py::arg("ID"));
	cls_SMDS_Mesh.def("AddFaceFromVtkIds", (SMDS_MeshFace * (SMDS_Mesh::*)(const std::vector<vtkIdType> &)) &SMDS_Mesh::AddFaceFromVtkIds, "None", py::arg("vtkNodeIds"));
	cls_SMDS_Mesh.def("AddFaceFromVtkIdsWithID", (SMDS_MeshFace * (SMDS_Mesh::*)(const std::vector<vtkIdType> &, const int)) &SMDS_Mesh::AddFaceFromVtkIdsWithID, "None", py::arg("vtkNodeIds"), py::arg("ID"));
	cls_SMDS_Mesh.def("MoveNode", (void (SMDS_Mesh::*)(const SMDS_MeshNode *, double, double, double)) &SMDS_Mesh::MoveNode, "None", py::arg("n"), py::arg("x"), py::arg("y"), py::arg("z"));
	cls_SMDS_Mesh.def("RemoveElement", [](SMDS_Mesh &self, const SMDS_MeshElement * a0, std::list<const SMDS_MeshElement *> & a1, std::list<const SMDS_MeshElement *> & a2) -> void { return self.RemoveElement(a0, a1, a2); }, py::arg("elem"), py::arg("removedElems"), py::arg("removedNodes"));
	cls_SMDS_Mesh.def("RemoveElement", (void (SMDS_Mesh::*)(const SMDS_MeshElement *, std::list<const SMDS_MeshElement *> &, std::list<const SMDS_MeshElement *> &, const bool)) &SMDS_Mesh::RemoveElement, "None", py::arg("elem"), py::arg("removedElems"), py::arg("removedNodes"), py::arg("removenodes"));
	cls_SMDS_Mesh.def("RemoveElement", [](SMDS_Mesh &self, const SMDS_MeshElement * a0) -> void { return self.RemoveElement(a0); }, py::arg("elem"));
	cls_SMDS_Mesh.def("RemoveElement", (void (SMDS_Mesh::*)(const SMDS_MeshElement *, bool)) &SMDS_Mesh::RemoveElement, "None", py::arg("elem"), py::arg("removenodes"));
	cls_SMDS_Mesh.def("RemoveNode", (void (SMDS_Mesh::*)(const SMDS_MeshNode *)) &SMDS_Mesh::RemoveNode, "None", py::arg("node"));
	cls_SMDS_Mesh.def("Remove0DElement", (void (SMDS_Mesh::*)(const SMDS_Mesh0DElement *)) &SMDS_Mesh::Remove0DElement, "None", py::arg("elem0d"));
	cls_SMDS_Mesh.def("RemoveEdge", (void (SMDS_Mesh::*)(const SMDS_MeshEdge *)) &SMDS_Mesh::RemoveEdge, "None", py::arg("edge"));
	cls_SMDS_Mesh.def("RemoveFace", (void (SMDS_Mesh::*)(const SMDS_MeshFace *)) &SMDS_Mesh::RemoveFace, "None", py::arg("face"));
	cls_SMDS_Mesh.def("RemoveVolume", (void (SMDS_Mesh::*)(const SMDS_MeshVolume *)) &SMDS_Mesh::RemoveVolume, "None", py::arg("volume"));
	cls_SMDS_Mesh.def("RemoveFreeElement", (void (SMDS_Mesh::*)(const SMDS_MeshElement *)) &SMDS_Mesh::RemoveFreeElement, "Remove only the given element and only if it is free. Method does not work for meshes with descendants. Implemented for fast cleaning of meshes.", py::arg("elem"));
	cls_SMDS_Mesh.def("Clear", (void (SMDS_Mesh::*)()) &SMDS_Mesh::Clear, "None");
	cls_SMDS_Mesh.def("RemoveFromParent", (bool (SMDS_Mesh::*)()) &SMDS_Mesh::RemoveFromParent, "None");
	cls_SMDS_Mesh.def("RemoveSubMesh", (bool (SMDS_Mesh::*)(const SMDS_Mesh *)) &SMDS_Mesh::RemoveSubMesh, "None", py::arg("aMesh"));
	// FIXME cls_SMDS_Mesh.def("ChangeElementNodes", (bool (SMDS_Mesh::*)(const SMDS_MeshElement *, const SMDS_MeshNode *[], const int)) &SMDS_Mesh::ChangeElementNodes, "None", py::arg("elem"), py::arg("nodes"), py::arg("nbnodes"));
	cls_SMDS_Mesh.def("ChangePolyhedronNodes", (bool (SMDS_Mesh::*)(const SMDS_MeshElement *, const std::vector<const SMDS_MeshNode *> &, const std::vector<int> &)) &SMDS_Mesh::ChangePolyhedronNodes, "None", py::arg("elem"), py::arg("nodes"), py::arg("quantities"));
	cls_SMDS_Mesh.def("Renumber", [](SMDS_Mesh &self, const bool a0) -> void { return self.Renumber(a0); }, py::arg("isNodes"));
	cls_SMDS_Mesh.def("Renumber", [](SMDS_Mesh &self, const bool a0, const int a1) -> void { return self.Renumber(a0, a1); }, py::arg("isNodes"), py::arg("startID"));
	cls_SMDS_Mesh.def("Renumber", (void (SMDS_Mesh::*)(const bool, const int, const int)) &SMDS_Mesh::Renumber, "None", py::arg("isNodes"), py::arg("startID"), py::arg("deltaID"));
	cls_SMDS_Mesh.def("compactMesh", (void (SMDS_Mesh::*)()) &SMDS_Mesh::compactMesh, "None");
	cls_SMDS_Mesh.def("FindNode", (const SMDS_MeshNode * (SMDS_Mesh::*)(int) const ) &SMDS_Mesh::FindNode, "None", py::arg("idnode"));
	cls_SMDS_Mesh.def("FindNodeVtk", (const SMDS_MeshNode * (SMDS_Mesh::*)(int) const ) &SMDS_Mesh::FindNodeVtk, "None", py::arg("idnode"));
	cls_SMDS_Mesh.def("Find0DElement", (const SMDS_Mesh0DElement * (SMDS_Mesh::*)(int) const ) &SMDS_Mesh::Find0DElement, "None", py::arg("idnode"));
	cls_SMDS_Mesh.def("FindBall", (const SMDS_BallElement * (SMDS_Mesh::*)(int) const ) &SMDS_Mesh::FindBall, "None", py::arg("idnode"));
	cls_SMDS_Mesh.def("FindEdge", (const SMDS_MeshEdge * (SMDS_Mesh::*)(int, int) const ) &SMDS_Mesh::FindEdge, "None", py::arg("idnode1"), py::arg("idnode2"));
	cls_SMDS_Mesh.def("FindEdge", (const SMDS_MeshEdge * (SMDS_Mesh::*)(int, int, int) const ) &SMDS_Mesh::FindEdge, "None", py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"));
	cls_SMDS_Mesh.def("FindFace", (const SMDS_MeshFace * (SMDS_Mesh::*)(int, int, int) const ) &SMDS_Mesh::FindFace, "None", py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"));
	cls_SMDS_Mesh.def("FindFace", (const SMDS_MeshFace * (SMDS_Mesh::*)(int, int, int, int) const ) &SMDS_Mesh::FindFace, "None", py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"));
	cls_SMDS_Mesh.def("FindFace", (const SMDS_MeshFace * (SMDS_Mesh::*)(int, int, int, int, int, int) const ) &SMDS_Mesh::FindFace, "None", py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"), py::arg("idnode5"), py::arg("idnode6"));
	cls_SMDS_Mesh.def("FindFace", (const SMDS_MeshFace * (SMDS_Mesh::*)(int, int, int, int, int, int, int, int) const ) &SMDS_Mesh::FindFace, "None", py::arg("idnode1"), py::arg("idnode2"), py::arg("idnode3"), py::arg("idnode4"), py::arg("idnode5"), py::arg("idnode6"), py::arg("idnode7"), py::arg("idnode8"));
	cls_SMDS_Mesh.def("FindElement", (const SMDS_MeshElement * (SMDS_Mesh::*)(int) const ) &SMDS_Mesh::FindElement, "None", py::arg("IDelem"));
	cls_SMDS_Mesh.def_static("Find0DElement_", (const SMDS_Mesh0DElement * (*)(const SMDS_MeshNode *)) &SMDS_Mesh::Find0DElement, "None", py::arg("n"));
	cls_SMDS_Mesh.def_static("FindBall_", (const SMDS_BallElement * (*)(const SMDS_MeshNode *)) &SMDS_Mesh::FindBall, "None", py::arg("n"));
	cls_SMDS_Mesh.def_static("FindEdge_", (const SMDS_MeshEdge * (*)(const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::FindEdge, "None", py::arg("n1"), py::arg("n2"));
	cls_SMDS_Mesh.def_static("FindEdge_", (const SMDS_MeshEdge * (*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::FindEdge, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"));
	cls_SMDS_Mesh.def_static("FindFace_", (const SMDS_MeshFace * (*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::FindFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"));
	cls_SMDS_Mesh.def_static("FindFace_", (const SMDS_MeshFace * (*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::FindFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"));
	cls_SMDS_Mesh.def_static("FindFace_", (const SMDS_MeshFace * (*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::FindFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"));
	cls_SMDS_Mesh.def_static("FindFace_", (const SMDS_MeshFace * (*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_Mesh::FindFace, "None", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"));
	cls_SMDS_Mesh.def("FindFace", (const SMDS_MeshFace * (SMDS_Mesh::*)(const std::vector<int> &) const ) &SMDS_Mesh::FindFace, "None", py::arg("nodes_ids"));
	cls_SMDS_Mesh.def_static("FindFace_", (const SMDS_MeshFace * (*)(const std::vector<const SMDS_MeshNode *> &)) &SMDS_Mesh::FindFace, "None", py::arg("nodes"));
	cls_SMDS_Mesh.def_static("FindElement_", [](const std::vector<const SMDS_MeshNode *> & a0) -> const SMDS_MeshElement * { return SMDS_Mesh::FindElement(a0); }, py::arg("nodes"));
	cls_SMDS_Mesh.def_static("FindElement_", [](const std::vector<const SMDS_MeshNode *> & a0, const SMDSAbs_ElementType a1) -> const SMDS_MeshElement * { return SMDS_Mesh::FindElement(a0, a1); }, py::arg("nodes"), py::arg("type"));
	cls_SMDS_Mesh.def_static("FindElement_", (const SMDS_MeshElement * (*)(const std::vector<const SMDS_MeshNode *> &, const SMDSAbs_ElementType, const bool)) &SMDS_Mesh::FindElement, "None", py::arg("nodes"), py::arg("type"), py::arg("noMedium"));
	cls_SMDS_Mesh.def_static("CheckMemory_", []() -> int { return SMDS_Mesh::CheckMemory(); });
	cls_SMDS_Mesh.def_static("CheckMemory_", (int (*)(const bool)) &SMDS_Mesh::CheckMemory, "Raise an exception if free memory (ram+swap) too low", py::arg("doNotRaise"));
	cls_SMDS_Mesh.def("MaxNodeID", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::MaxNodeID, "None");
	cls_SMDS_Mesh.def("MinNodeID", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::MinNodeID, "None");
	cls_SMDS_Mesh.def("MaxElementID", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::MaxElementID, "None");
	cls_SMDS_Mesh.def("MinElementID", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::MinElementID, "None");
	cls_SMDS_Mesh.def("GetMeshInfo", (const SMDS_MeshInfo & (SMDS_Mesh::*)() const ) &SMDS_Mesh::GetMeshInfo, "None");
	cls_SMDS_Mesh.def("NbNodes", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::NbNodes, "None");
	cls_SMDS_Mesh.def("NbElements", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::NbElements, "None");
	cls_SMDS_Mesh.def("Nb0DElements", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::Nb0DElements, "None");
	cls_SMDS_Mesh.def("NbBalls", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::NbBalls, "None");
	cls_SMDS_Mesh.def("NbEdges", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::NbEdges, "None");
	cls_SMDS_Mesh.def("NbFaces", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::NbFaces, "None");
	cls_SMDS_Mesh.def("NbVolumes", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::NbVolumes, "None");
	cls_SMDS_Mesh.def("NbSubMesh", (int (SMDS_Mesh::*)() const ) &SMDS_Mesh::NbSubMesh, "None");
	cls_SMDS_Mesh.def("DumpNodes", (void (SMDS_Mesh::*)() const ) &SMDS_Mesh::DumpNodes, "None");
	cls_SMDS_Mesh.def("Dump0DElements", (void (SMDS_Mesh::*)() const ) &SMDS_Mesh::Dump0DElements, "None");
	cls_SMDS_Mesh.def("DumpEdges", (void (SMDS_Mesh::*)() const ) &SMDS_Mesh::DumpEdges, "None");
	cls_SMDS_Mesh.def("DumpFaces", (void (SMDS_Mesh::*)() const ) &SMDS_Mesh::DumpFaces, "None");
	cls_SMDS_Mesh.def("DumpVolumes", (void (SMDS_Mesh::*)() const ) &SMDS_Mesh::DumpVolumes, "None");
	cls_SMDS_Mesh.def("DebugStats", (void (SMDS_Mesh::*)() const ) &SMDS_Mesh::DebugStats, "None");
	cls_SMDS_Mesh.def("hasConstructionEdges", (bool (SMDS_Mesh::*)()) &SMDS_Mesh::hasConstructionEdges, "None");
	cls_SMDS_Mesh.def("hasConstructionFaces", (bool (SMDS_Mesh::*)()) &SMDS_Mesh::hasConstructionFaces, "None");
	cls_SMDS_Mesh.def("hasInverseElements", (bool (SMDS_Mesh::*)()) &SMDS_Mesh::hasInverseElements, "None");
	cls_SMDS_Mesh.def("setConstructionEdges", (void (SMDS_Mesh::*)(bool)) &SMDS_Mesh::setConstructionEdges, "None", py::arg(""));
	cls_SMDS_Mesh.def("setConstructionFaces", (void (SMDS_Mesh::*)(bool)) &SMDS_Mesh::setConstructionFaces, "None", py::arg(""));
	cls_SMDS_Mesh.def("setInverseElements", (void (SMDS_Mesh::*)(bool)) &SMDS_Mesh::setInverseElements, "None", py::arg(""));
	cls_SMDS_Mesh.def("Contains", (bool (SMDS_Mesh::*)(const SMDS_MeshElement *) const ) &SMDS_Mesh::Contains, "Checks if the element is present in mesh. Useful to determine dead pointers. Use this function for debug purpose only! Do not check in the code using it even in _DEBUG_ mode", py::arg("elem"));
	cls_SMDS_Mesh.def("getMaxDim", (double (SMDS_Mesh::*)()) &SMDS_Mesh::getMaxDim, "None");
	cls_SMDS_Mesh.def("fromVtkToSmds", (int (SMDS_Mesh::*)(int)) &SMDS_Mesh::fromVtkToSmds, "None", py::arg("vtkid"));
	cls_SMDS_Mesh.def("dumpGrid", [](SMDS_Mesh &self) -> void { return self.dumpGrid(); });
	cls_SMDS_Mesh.def("dumpGrid", (void (SMDS_Mesh::*)(std::string)) &SMDS_Mesh::dumpGrid, "None", py::arg("ficdump"));
	cls_SMDS_Mesh.def("setMyModified", (void (SMDS_Mesh::*)()) &SMDS_Mesh::setMyModified, "low level modification: add, change or remove node or element");
	cls_SMDS_Mesh.def("Modified", (void (SMDS_Mesh::*)()) &SMDS_Mesh::Modified, "None");
	cls_SMDS_Mesh.def("GetMTime", (vtkMTimeType (SMDS_Mesh::*)() const ) &SMDS_Mesh::GetMTime, "None");
	cls_SMDS_Mesh.def("isCompacted", (bool (SMDS_Mesh::*)()) &SMDS_Mesh::isCompacted, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshElement.hxx
	py::class_<SMDS_MeshElement, std::unique_ptr<SMDS_MeshElement, py::nodelete>, SMDS_MeshObject> cls_SMDS_MeshElement(mod, "SMDS_MeshElement", "Base class for elements");
	cls_SMDS_MeshElement.def("nodesIterator", (SMDS_ElemIteratorPtr (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::nodesIterator, "None");
	cls_SMDS_MeshElement.def("edgesIterator", (SMDS_ElemIteratorPtr (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::edgesIterator, "None");
	cls_SMDS_MeshElement.def("facesIterator", (SMDS_ElemIteratorPtr (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::facesIterator, "None");
	cls_SMDS_MeshElement.def("elementsIterator", (SMDS_ElemIteratorPtr (SMDS_MeshElement::*)(SMDSAbs_ElementType) const ) &SMDS_MeshElement::elementsIterator, "None", py::arg("type"));
	cls_SMDS_MeshElement.def("interlacedNodesElemIterator", (SMDS_ElemIteratorPtr (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::interlacedNodesElemIterator, "None");
	cls_SMDS_MeshElement.def("nodeIterator", (SMDS_NodeIteratorPtr (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::nodeIterator, "None");
	cls_SMDS_MeshElement.def("interlacedNodesIterator", (SMDS_NodeIteratorPtr (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::interlacedNodesIterator, "None");
	cls_SMDS_MeshElement.def("nodesIteratorToUNV", (SMDS_NodeIteratorPtr (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::nodesIteratorToUNV, "None");
	cls_SMDS_MeshElement.def("begin_nodes", (SMDS_MeshElement::iterator (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::begin_nodes, "None");
	cls_SMDS_MeshElement.def("end_nodes", (SMDS_MeshElement::iterator (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::end_nodes, "None");
	cls_SMDS_MeshElement.def("NbNodes", (int (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::NbNodes, "None");
	cls_SMDS_MeshElement.def("NbEdges", (int (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::NbEdges, "None");
	cls_SMDS_MeshElement.def("NbFaces", (int (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::NbFaces, "None");
	cls_SMDS_MeshElement.def("GetID", (int (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::GetID, "None");
	cls_SMDS_MeshElement.def("GetType", (SMDSAbs_ElementType (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::GetType, "Return the type of the current element");
	cls_SMDS_MeshElement.def("GetEntityType", (SMDSAbs_EntityType (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::GetEntityType, "None");
	cls_SMDS_MeshElement.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::GetGeomType, "None");
	cls_SMDS_MeshElement.def("GetVtkType", (vtkIdType (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::GetVtkType, "None");
	cls_SMDS_MeshElement.def("IsPoly", (bool (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::IsPoly, "None");
	cls_SMDS_MeshElement.def("IsQuadratic", (bool (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::IsQuadratic, "None");
	cls_SMDS_MeshElement.def("IsMediumNode", (bool (SMDS_MeshElement::*)(const SMDS_MeshNode *) const ) &SMDS_MeshElement::IsMediumNode, "None", py::arg("node"));
	cls_SMDS_MeshElement.def("NbCornerNodes", (int (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::NbCornerNodes, "None");
	cls_SMDS_MeshElement.def("GetNode", (const SMDS_MeshNode * (SMDS_MeshElement::*)(const int) const ) &SMDS_MeshElement::GetNode, "Return node by its index", py::arg("ind"));
	cls_SMDS_MeshElement.def("GetNodeWrap", (const SMDS_MeshNode * (SMDS_MeshElement::*)(const int) const ) &SMDS_MeshElement::GetNodeWrap, "Return node by its index", py::arg("ind"));
	cls_SMDS_MeshElement.def("IsValidIndex", (bool (SMDS_MeshElement::*)(const int) const ) &SMDS_MeshElement::IsValidIndex, "Return true if index of node is valid (0 <= ind < NbNodes())", py::arg("ind"));
	cls_SMDS_MeshElement.def("WrappedIndex", (int (SMDS_MeshElement::*)(const int) const ) &SMDS_MeshElement::WrappedIndex, "Return a valid node index, fixing the given one if necessary", py::arg("ind"));
	cls_SMDS_MeshElement.def("GetNodeIndex", (int (SMDS_MeshElement::*)(const SMDS_MeshNode *) const ) &SMDS_MeshElement::GetNodeIndex, "Check if a node belongs to the element", py::arg("node"));
	cls_SMDS_MeshElement.def("getMeshId", (ShortType (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::getMeshId, "None");
	cls_SMDS_MeshElement.def("getshapeId", (LongType (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::getshapeId, "None");
	cls_SMDS_MeshElement.def("getIdInShape", (int (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::getIdInShape, "None");
	cls_SMDS_MeshElement.def("getVtkId", (int (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::getVtkId, "None");
	cls_SMDS_MeshElement.def("setIsMarked", (void (SMDS_MeshElement::*)(bool) const ) &SMDS_MeshElement::setIsMarked, "None", py::arg("is"));
	cls_SMDS_MeshElement.def("isMarked", (bool (SMDS_MeshElement::*)() const ) &SMDS_MeshElement::isMarked, "None");

	// Callback for SMDS_MeshCell.
	class PyCallback_SMDS_MeshCell : public SMDS_MeshCell {
	public:
		using SMDS_MeshCell::SMDS_MeshCell;

		SMDSAbs_ElementType GetType() const  override { PYBIND11_OVERLOAD_PURE(SMDSAbs_ElementType, SMDS_MeshCell, GetType, ); }
		SMDSAbs_EntityType GetEntityType() const  override { PYBIND11_OVERLOAD_PURE(SMDSAbs_EntityType, SMDS_MeshCell, GetEntityType, ); }
		SMDSAbs_GeometryType GetGeomType() const  override { PYBIND11_OVERLOAD_PURE(SMDSAbs_GeometryType, SMDS_MeshCell, GetGeomType, ); }
		vtkIdType GetVtkType() const  override { PYBIND11_OVERLOAD_PURE(vtkIdType, SMDS_MeshCell, GetVtkType, ); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshCell.hxx
	py::class_<SMDS_MeshCell, std::unique_ptr<SMDS_MeshCell, py::nodelete>, PyCallback_SMDS_MeshCell, SMDS_MeshElement> cls_SMDS_MeshCell(mod, "SMDS_MeshCell", "Base class for all cells");
	// FIXME cls_SMDS_MeshCell.def(py::init<>());
	// FIXME cls_SMDS_MeshCell.def("ChangeNodes", (bool (SMDS_MeshCell::*)(const SMDS_MeshNode *[], const int)) &SMDS_MeshCell::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	// FIXME cls_SMDS_MeshCell.def("vtkOrder", (bool (SMDS_MeshCell::*)(const SMDS_MeshNode *[], const int)) &SMDS_MeshCell::vtkOrder, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_MeshCell.def_static("toVtkType_", (VTKCellType (*)(SMDSAbs_EntityType)) &SMDS_MeshCell::toVtkType, "None", py::arg("vtkType"));
	cls_SMDS_MeshCell.def_static("toSmdsType_", (SMDSAbs_EntityType (*)(VTKCellType)) &SMDS_MeshCell::toSmdsType, "None", py::arg("vtkType"));
	cls_SMDS_MeshCell.def_static("toSmdsType_", (SMDSAbs_ElementType (*)(SMDSAbs_GeometryType)) &SMDS_MeshCell::toSmdsType, "None", py::arg("geomType"));
	cls_SMDS_MeshCell.def_static("toSmdsType_", (SMDSAbs_ElementType (*)(SMDSAbs_EntityType)) &SMDS_MeshCell::toSmdsType, "None", py::arg("entityType"));
	cls_SMDS_MeshCell.def_static("toVtkOrder_", (const std::vector<int> & (*)(VTKCellType)) &SMDS_MeshCell::toVtkOrder, "None", py::arg("vtkType"));
	cls_SMDS_MeshCell.def_static("toVtkOrder_", (const std::vector<int> & (*)(SMDSAbs_EntityType)) &SMDS_MeshCell::toVtkOrder, "None", py::arg("smdsType"));
	cls_SMDS_MeshCell.def_static("fromVtkOrder_", (const std::vector<int> & (*)(VTKCellType)) &SMDS_MeshCell::fromVtkOrder, "None", py::arg("vtkType"));
	cls_SMDS_MeshCell.def_static("fromVtkOrder_", (const std::vector<int> & (*)(SMDSAbs_EntityType)) &SMDS_MeshCell::fromVtkOrder, "None", py::arg("smdsType"));
	cls_SMDS_MeshCell.def_static("reverseSmdsOrder_", [](SMDSAbs_EntityType a0) -> const std::vector<int> & { return SMDS_MeshCell::reverseSmdsOrder(a0); }, py::arg("smdsType"));
	cls_SMDS_MeshCell.def_static("reverseSmdsOrder_", (const std::vector<int> & (*)(SMDSAbs_EntityType, const size_t)) &SMDS_MeshCell::reverseSmdsOrder, "None", py::arg("smdsType"), py::arg("nbNodes"));
	cls_SMDS_MeshCell.def_static("interlacedSmdsOrder_", [](SMDSAbs_EntityType a0) -> const std::vector<int> & { return SMDS_MeshCell::interlacedSmdsOrder(a0); }, py::arg("smdsType"));
	cls_SMDS_MeshCell.def_static("interlacedSmdsOrder_", (const std::vector<int> & (*)(SMDSAbs_EntityType, const size_t)) &SMDS_MeshCell::interlacedSmdsOrder, "None", py::arg("smdsType"), py::arg("nbNodes"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshEdge.hxx
	py::class_<SMDS_MeshEdge, std::unique_ptr<SMDS_MeshEdge, py::nodelete>, SMDS_MeshCell> cls_SMDS_MeshEdge(mod, "SMDS_MeshEdge", "None");
	cls_SMDS_MeshEdge.def("GetType", (SMDSAbs_ElementType (SMDS_MeshEdge::*)() const ) &SMDS_MeshEdge::GetType, "None");
	cls_SMDS_MeshEdge.def("GetVtkType", (vtkIdType (SMDS_MeshEdge::*)() const ) &SMDS_MeshEdge::GetVtkType, "None");
	cls_SMDS_MeshEdge.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_MeshEdge::*)() const ) &SMDS_MeshEdge::GetGeomType, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshFace.hxx
	py::class_<SMDS_MeshFace, std::unique_ptr<SMDS_MeshFace, py::nodelete>, SMDS_MeshCell> cls_SMDS_MeshFace(mod, "SMDS_MeshFace", "None");
	cls_SMDS_MeshFace.def("GetType", (SMDSAbs_ElementType (SMDS_MeshFace::*)() const ) &SMDS_MeshFace::GetType, "None");
	cls_SMDS_MeshFace.def("GetVtkType", (vtkIdType (SMDS_MeshFace::*)() const ) &SMDS_MeshFace::GetVtkType, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshVolume.hxx
	py::class_<SMDS_MeshVolume, std::unique_ptr<SMDS_MeshVolume, py::nodelete>, SMDS_MeshCell> cls_SMDS_MeshVolume(mod, "SMDS_MeshVolume", "None");
	cls_SMDS_MeshVolume.def("GetType", (SMDSAbs_ElementType (SMDS_MeshVolume::*)() const ) &SMDS_MeshVolume::GetType, "None");
	cls_SMDS_MeshVolume.def("GetVtkType", (vtkIdType (SMDS_MeshVolume::*)() const ) &SMDS_MeshVolume::GetVtkType, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshGroup.hxx
	py::class_<SMDS_MeshGroup, std::unique_ptr<SMDS_MeshGroup, py::nodelete>, SMDS_MeshObject> cls_SMDS_MeshGroup(mod, "SMDS_MeshGroup", "None");
	cls_SMDS_MeshGroup.def(py::init<const SMDS_Mesh *>(), py::arg("theMesh"));
	cls_SMDS_MeshGroup.def(py::init<const SMDS_Mesh *, const SMDSAbs_ElementType>(), py::arg("theMesh"), py::arg("theType"));
	cls_SMDS_MeshGroup.def("AddSubGroup", [](SMDS_MeshGroup &self) -> const SMDS_MeshGroup * { return self.AddSubGroup(); });
	cls_SMDS_MeshGroup.def("AddSubGroup", (const SMDS_MeshGroup * (SMDS_MeshGroup::*)(const SMDSAbs_ElementType)) &SMDS_MeshGroup::AddSubGroup, "None", py::arg("theType"));
	cls_SMDS_MeshGroup.def("RemoveSubGroup", (bool (SMDS_MeshGroup::*)(const SMDS_MeshGroup *)) &SMDS_MeshGroup::RemoveSubGroup, "None", py::arg("theGroup"));
	cls_SMDS_MeshGroup.def("RemoveFromParent", (bool (SMDS_MeshGroup::*)()) &SMDS_MeshGroup::RemoveFromParent, "None");
	cls_SMDS_MeshGroup.def("GetMesh", (const SMDS_Mesh * (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::GetMesh, "None");
	cls_SMDS_MeshGroup.def("SetType", (void (SMDS_MeshGroup::*)(const SMDSAbs_ElementType)) &SMDS_MeshGroup::SetType, "None", py::arg("theType"));
	cls_SMDS_MeshGroup.def("Clear", (void (SMDS_MeshGroup::*)()) &SMDS_MeshGroup::Clear, "None");
	cls_SMDS_MeshGroup.def("Add", (bool (SMDS_MeshGroup::*)(const SMDS_MeshElement *)) &SMDS_MeshGroup::Add, "None", py::arg("theElem"));
	cls_SMDS_MeshGroup.def("Remove", (bool (SMDS_MeshGroup::*)(const SMDS_MeshElement *)) &SMDS_MeshGroup::Remove, "None", py::arg("theElem"));
	cls_SMDS_MeshGroup.def("IsEmpty", (bool (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::IsEmpty, "None");
	cls_SMDS_MeshGroup.def("Extent", (int (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::Extent, "None");
	cls_SMDS_MeshGroup.def("Tic", (int (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::Tic, "None");
	cls_SMDS_MeshGroup.def("SubGroupsNb", (int (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::SubGroupsNb, "None");
	cls_SMDS_MeshGroup.def("GetType", (SMDSAbs_ElementType (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::GetType, "None");
	cls_SMDS_MeshGroup.def("Contains", (bool (SMDS_MeshGroup::*)(const SMDS_MeshElement *) const ) &SMDS_MeshGroup::Contains, "None", py::arg("theElem"));
	cls_SMDS_MeshGroup.def("InitIterator", (void (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::InitIterator, "None");
	cls_SMDS_MeshGroup.def("More", (bool (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::More, "None");
	cls_SMDS_MeshGroup.def("Next", (const SMDS_MeshElement * (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::Next, "None");
	cls_SMDS_MeshGroup.def("InitSubGroupsIterator", (void (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::InitSubGroupsIterator, "None");
	cls_SMDS_MeshGroup.def("MoreSubGroups", (bool (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::MoreSubGroups, "None");
	cls_SMDS_MeshGroup.def("NextSubGroup", (const SMDS_MeshGroup * (SMDS_MeshGroup::*)() const ) &SMDS_MeshGroup::NextSubGroup, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshNode.hxx
	py::class_<SMDS_MeshNode, std::unique_ptr<SMDS_MeshNode, py::nodelete>, SMDS_MeshElement> cls_SMDS_MeshNode(mod, "SMDS_MeshNode", "None");
	cls_SMDS_MeshNode.def("Print", (void (SMDS_MeshNode::*)(std::ostream &) const ) &SMDS_MeshNode::Print, "None", py::arg("OS"));
	cls_SMDS_MeshNode.def("X", (double (SMDS_MeshNode::*)() const ) &SMDS_MeshNode::X, "None");
	cls_SMDS_MeshNode.def("Y", (double (SMDS_MeshNode::*)() const ) &SMDS_MeshNode::Y, "None");
	cls_SMDS_MeshNode.def("Z", (double (SMDS_MeshNode::*)() const ) &SMDS_MeshNode::Z, "None");
	// FIXME cls_SMDS_MeshNode.def("GetXYZ", (void (SMDS_MeshNode::*)(double [3]) const ) &SMDS_MeshNode::GetXYZ, "None", py::arg("xyz"));
	cls_SMDS_MeshNode.def("GetInverseElementIterator", [](SMDS_MeshNode &self) -> SMDS_ElemIteratorPtr { return self.GetInverseElementIterator(); });
	cls_SMDS_MeshNode.def("GetInverseElementIterator", (SMDS_ElemIteratorPtr (SMDS_MeshNode::*)(SMDSAbs_ElementType) const ) &SMDS_MeshNode::GetInverseElementIterator, "None", py::arg("type"));
	cls_SMDS_MeshNode.def("NbInverseElements", [](SMDS_MeshNode &self) -> int { return self.NbInverseElements(); });
	cls_SMDS_MeshNode.def("NbInverseElements", (int (SMDS_MeshNode::*)(SMDSAbs_ElementType) const ) &SMDS_MeshNode::NbInverseElements, "None", py::arg("type"));
	cls_SMDS_MeshNode.def("GetPosition", (const SMDS_PositionPtr & (SMDS_MeshNode::*)() const ) &SMDS_MeshNode::GetPosition, "None");
	cls_SMDS_MeshNode.def("GetType", (SMDSAbs_ElementType (SMDS_MeshNode::*)() const ) &SMDS_MeshNode::GetType, "None");
	cls_SMDS_MeshNode.def("GetVtkType", (vtkIdType (SMDS_MeshNode::*)() const ) &SMDS_MeshNode::GetVtkType, "None");
	cls_SMDS_MeshNode.def("GetEntityType", (SMDSAbs_EntityType (SMDS_MeshNode::*)() const ) &SMDS_MeshNode::GetEntityType, "None");
	cls_SMDS_MeshNode.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_MeshNode::*)() const ) &SMDS_MeshNode::GetGeomType, "None");
	cls_SMDS_MeshNode.def("NbNodes", (int (SMDS_MeshNode::*)() const ) &SMDS_MeshNode::NbNodes, "None");
	cls_SMDS_MeshNode.def("SetPosition", (void (SMDS_MeshNode::*)(const SMDS_PositionPtr &)) &SMDS_MeshNode::SetPosition, "None", py::arg("aPos"));
	cls_SMDS_MeshNode.def("setXYZ", (void (SMDS_MeshNode::*)(double, double, double)) &SMDS_MeshNode::setXYZ, "None", py::arg("x"), py::arg("y"), py::arg("z"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshIDFactory.hxx
	py::class_<SMDS_MeshIDFactory, std::unique_ptr<SMDS_MeshIDFactory, py::nodelete>, SMDS_MeshObject> cls_SMDS_MeshIDFactory(mod, "SMDS_MeshIDFactory", "None");
	cls_SMDS_MeshIDFactory.def("GetFreeID", (int (SMDS_MeshIDFactory::*)()) &SMDS_MeshIDFactory::GetFreeID, "None");
	cls_SMDS_MeshIDFactory.def("ReleaseID", [](SMDS_MeshIDFactory &self, int a0) -> void { return self.ReleaseID(a0); }, py::arg("ID"));
	cls_SMDS_MeshIDFactory.def("ReleaseID", (void (SMDS_MeshIDFactory::*)(int, int)) &SMDS_MeshIDFactory::ReleaseID, "None", py::arg("ID"), py::arg("vtkId"));
	cls_SMDS_MeshIDFactory.def("Clear", (void (SMDS_MeshIDFactory::*)()) &SMDS_MeshIDFactory::Clear, "None");
	cls_SMDS_MeshIDFactory.def("SetMesh", (void (SMDS_MeshIDFactory::*)(SMDS_Mesh *)) &SMDS_MeshIDFactory::SetMesh, "None", py::arg("mesh"));
	cls_SMDS_MeshIDFactory.def("GetMesh", (SMDS_Mesh * (SMDS_MeshIDFactory::*)()) &SMDS_MeshIDFactory::GetMesh, "None");
	cls_SMDS_MeshIDFactory.def("isPoolIdEmpty", (bool (SMDS_MeshIDFactory::*)()) &SMDS_MeshIDFactory::isPoolIdEmpty, "None");
	cls_SMDS_MeshIDFactory.def("emptyPool", (void (SMDS_MeshIDFactory::*)(int)) &SMDS_MeshIDFactory::emptyPool, "None", py::arg("maxId"));
	cls_SMDS_MeshIDFactory.def("adjustMaxId", (void (SMDS_MeshIDFactory::*)(int)) &SMDS_MeshIDFactory::adjustMaxId, "None", py::arg("ID"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshNodeIDFactory.hxx
	py::class_<SMDS_MeshNodeIDFactory, std::unique_ptr<SMDS_MeshNodeIDFactory, py::nodelete>, SMDS_MeshIDFactory> cls_SMDS_MeshNodeIDFactory(mod, "SMDS_MeshNodeIDFactory", "None");
	cls_SMDS_MeshNodeIDFactory.def(py::init<>());
	cls_SMDS_MeshNodeIDFactory.def("BindID", (bool (SMDS_MeshNodeIDFactory::*)(int, SMDS_MeshElement *)) &SMDS_MeshNodeIDFactory::BindID, "None", py::arg("ID"), py::arg("elem"));
	cls_SMDS_MeshNodeIDFactory.def("MeshElement", (SMDS_MeshElement * (SMDS_MeshNodeIDFactory::*)(int)) &SMDS_MeshNodeIDFactory::MeshElement, "None", py::arg("ID"));
	cls_SMDS_MeshNodeIDFactory.def("GetFreeID", (int (SMDS_MeshNodeIDFactory::*)()) &SMDS_MeshNodeIDFactory::GetFreeID, "None");
	cls_SMDS_MeshNodeIDFactory.def("ReleaseID", [](SMDS_MeshNodeIDFactory &self, int a0) -> void { return self.ReleaseID(a0); }, py::arg("ID"));
	cls_SMDS_MeshNodeIDFactory.def("ReleaseID", (void (SMDS_MeshNodeIDFactory::*)(int, int)) &SMDS_MeshNodeIDFactory::ReleaseID, "None", py::arg("ID"), py::arg("vtkId"));
	cls_SMDS_MeshNodeIDFactory.def("GetMaxID", (int (SMDS_MeshNodeIDFactory::*)() const ) &SMDS_MeshNodeIDFactory::GetMaxID, "None");
	cls_SMDS_MeshNodeIDFactory.def("GetMinID", (int (SMDS_MeshNodeIDFactory::*)() const ) &SMDS_MeshNodeIDFactory::GetMinID, "None");
	cls_SMDS_MeshNodeIDFactory.def("elementsIterator", (SMDS_ElemIteratorPtr (SMDS_MeshNodeIDFactory::*)() const ) &SMDS_MeshNodeIDFactory::elementsIterator, "None");
	cls_SMDS_MeshNodeIDFactory.def("Clear", (void (SMDS_MeshNodeIDFactory::*)()) &SMDS_MeshNodeIDFactory::Clear, "None");
	cls_SMDS_MeshNodeIDFactory.def("emptyPool", (void (SMDS_MeshNodeIDFactory::*)(int)) &SMDS_MeshNodeIDFactory::emptyPool, "None", py::arg("maxId"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshElementIDFactory.hxx
	py::class_<SMDS_MeshElementIDFactory, std::unique_ptr<SMDS_MeshElementIDFactory, py::nodelete>, SMDS_MeshNodeIDFactory> cls_SMDS_MeshElementIDFactory(mod, "SMDS_MeshElementIDFactory", "None");
	cls_SMDS_MeshElementIDFactory.def(py::init<>());
	cls_SMDS_MeshElementIDFactory.def("BindID", (bool (SMDS_MeshElementIDFactory::*)(int, SMDS_MeshElement *)) &SMDS_MeshElementIDFactory::BindID, "None", py::arg("ID"), py::arg("elem"));
	cls_SMDS_MeshElementIDFactory.def("SetInVtkGrid", (int (SMDS_MeshElementIDFactory::*)(SMDS_MeshElement *)) &SMDS_MeshElementIDFactory::SetInVtkGrid, "None", py::arg("elem"));
	cls_SMDS_MeshElementIDFactory.def("MeshElement", (SMDS_MeshElement * (SMDS_MeshElementIDFactory::*)(int)) &SMDS_MeshElementIDFactory::MeshElement, "None", py::arg("ID"));
	cls_SMDS_MeshElementIDFactory.def("GetFreeID", (int (SMDS_MeshElementIDFactory::*)()) &SMDS_MeshElementIDFactory::GetFreeID, "None");
	cls_SMDS_MeshElementIDFactory.def("ReleaseID", [](SMDS_MeshElementIDFactory &self, int a0) -> void { return self.ReleaseID(a0); }, py::arg("ID"));
	cls_SMDS_MeshElementIDFactory.def("ReleaseID", (void (SMDS_MeshElementIDFactory::*)(int, int)) &SMDS_MeshElementIDFactory::ReleaseID, "None", py::arg("ID"), py::arg("vtkId"));
	cls_SMDS_MeshElementIDFactory.def("elementsIterator", (SMDS_ElemIteratorPtr (SMDS_MeshElementIDFactory::*)() const ) &SMDS_MeshElementIDFactory::elementsIterator, "None");
	cls_SMDS_MeshElementIDFactory.def("Clear", (void (SMDS_MeshElementIDFactory::*)()) &SMDS_MeshElementIDFactory::Clear, "None");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshElement.hxx
	py::class_<TIDTypeCompare, std::unique_ptr<TIDTypeCompare, Deleter<TIDTypeCompare>>> cls_TIDTypeCompare(mod, "TIDTypeCompare", "Comparator of elements by ID for usage in std containers");
	cls_TIDTypeCompare.def(py::init<>());
	cls_TIDTypeCompare.def("__call__", (bool (TIDTypeCompare::*)(const SMDS_MeshElement *, const SMDS_MeshElement *) const ) &TIDTypeCompare::operator(), py::is_operator(), "None", py::arg("e1"), py::arg("e2"));
	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshElement.hxx
	py::class_<TIDCompare, std::unique_ptr<TIDCompare, Deleter<TIDCompare>>> cls_TIDCompare(mod, "TIDCompare", "None");
	cls_TIDCompare.def(py::init<>());
	cls_TIDCompare.def("__call__", (bool (TIDCompare::*)(const SMDS_MeshElement *, const SMDS_MeshElement *) const ) &TIDCompare::operator(), py::is_operator(), "None", py::arg("e1"), py::arg("e2"));
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Position.hxx
	py::class_<SMDS_Position, std::unique_ptr<SMDS_Position, Deleter<SMDS_Position>>> cls_SMDS_Position(mod, "SMDS_Position", "None");
	cls_SMDS_Position.def("GetTypeOfPosition", (SMDS_TypeOfPosition (SMDS_Position::*)() const ) &SMDS_Position::GetTypeOfPosition, "None");
	cls_SMDS_Position.def("GetDim", (int (SMDS_Position::*)() const ) &SMDS_Position::GetDim, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Mesh0DElement.hxx
	py::class_<SMDS_Mesh0DElement, std::unique_ptr<SMDS_Mesh0DElement, py::nodelete>, SMDS_MeshCell> cls_SMDS_Mesh0DElement(mod, "SMDS_Mesh0DElement", "None");
	cls_SMDS_Mesh0DElement.def(py::init<const SMDS_MeshNode *>(), py::arg("node"));
	// FIXME cls_SMDS_Mesh0DElement.def("ChangeNodes", (bool (SMDS_Mesh0DElement::*)(const SMDS_MeshNode *[], const int)) &SMDS_Mesh0DElement::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_Mesh0DElement.def("Print", (void (SMDS_Mesh0DElement::*)(std::ostream &) const ) &SMDS_Mesh0DElement::Print, "None", py::arg("OS"));
	cls_SMDS_Mesh0DElement.def("GetType", (SMDSAbs_ElementType (SMDS_Mesh0DElement::*)() const ) &SMDS_Mesh0DElement::GetType, "None");
	cls_SMDS_Mesh0DElement.def("GetVtkType", (vtkIdType (SMDS_Mesh0DElement::*)() const ) &SMDS_Mesh0DElement::GetVtkType, "None");
	cls_SMDS_Mesh0DElement.def("GetEntityType", (SMDSAbs_EntityType (SMDS_Mesh0DElement::*)() const ) &SMDS_Mesh0DElement::GetEntityType, "None");
	cls_SMDS_Mesh0DElement.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_Mesh0DElement::*)() const ) &SMDS_Mesh0DElement::GetGeomType, "None");
	cls_SMDS_Mesh0DElement.def("GetNode", (const SMDS_MeshNode * (SMDS_Mesh0DElement::*)(const int) const ) &SMDS_Mesh0DElement::GetNode, "None", py::arg("ind"));
	cls_SMDS_Mesh0DElement.def("NbNodes", (int (SMDS_Mesh0DElement::*)() const ) &SMDS_Mesh0DElement::NbNodes, "None");
	cls_SMDS_Mesh0DElement.def("NbEdges", (int (SMDS_Mesh0DElement::*)() const ) &SMDS_Mesh0DElement::NbEdges, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshInfo.hxx
	py::class_<SMDS_MeshInfo, std::unique_ptr<SMDS_MeshInfo, Deleter<SMDS_MeshInfo>>> cls_SMDS_MeshInfo(mod, "SMDS_MeshInfo", "None");
	cls_SMDS_MeshInfo.def(py::init<>());
	cls_SMDS_MeshInfo.def("assign", (SMDS_MeshInfo & (SMDS_MeshInfo::*)(const SMDS_MeshInfo &)) &SMDS_MeshInfo::operator=, py::is_operator(), "None", py::arg("other"));
	cls_SMDS_MeshInfo.def("Clear", (void (SMDS_MeshInfo::*)()) &SMDS_MeshInfo::Clear, "None");
	cls_SMDS_MeshInfo.def("NbElements", [](SMDS_MeshInfo &self) -> int { return self.NbElements(); });
	cls_SMDS_MeshInfo.def("NbElements", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementType) const ) &SMDS_MeshInfo::NbElements, "None", py::arg("type"));
	cls_SMDS_MeshInfo.def("NbElements", (int (SMDS_MeshInfo::*)(SMDSAbs_EntityType) const ) &SMDS_MeshInfo::NbElements, "None", py::arg("type"));
	cls_SMDS_MeshInfo.def("NbElements", (int (SMDS_MeshInfo::*)(SMDSAbs_GeometryType) const ) &SMDS_MeshInfo::NbElements, "None", py::arg("type"));
	cls_SMDS_MeshInfo.def("NbEntities", (int (SMDS_MeshInfo::*)(SMDSAbs_EntityType) const ) &SMDS_MeshInfo::NbEntities, "None", py::arg("type"));
	cls_SMDS_MeshInfo.def("NbElementsOfGeom", (int (SMDS_MeshInfo::*)(SMDSAbs_GeometryType) const ) &SMDS_MeshInfo::NbElementsOfGeom, "None", py::arg("geom"));
	cls_SMDS_MeshInfo.def("NbNodes", (int (SMDS_MeshInfo::*)() const ) &SMDS_MeshInfo::NbNodes, "None");
	cls_SMDS_MeshInfo.def("Nb0DElements", (int (SMDS_MeshInfo::*)() const ) &SMDS_MeshInfo::Nb0DElements, "None");
	cls_SMDS_MeshInfo.def("NbBalls", (int (SMDS_MeshInfo::*)() const ) &SMDS_MeshInfo::NbBalls, "None");
	cls_SMDS_MeshInfo.def("NbEdges", [](SMDS_MeshInfo &self) -> int { return self.NbEdges(); });
	cls_SMDS_MeshInfo.def("NbEdges", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementOrder) const ) &SMDS_MeshInfo::NbEdges, "None", py::arg("order"));
	cls_SMDS_MeshInfo.def("NbFaces", [](SMDS_MeshInfo &self) -> int { return self.NbFaces(); });
	cls_SMDS_MeshInfo.def("NbFaces", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementOrder) const ) &SMDS_MeshInfo::NbFaces, "None", py::arg("order"));
	cls_SMDS_MeshInfo.def("NbTriangles", [](SMDS_MeshInfo &self) -> int { return self.NbTriangles(); });
	cls_SMDS_MeshInfo.def("NbTriangles", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementOrder) const ) &SMDS_MeshInfo::NbTriangles, "None", py::arg("order"));
	cls_SMDS_MeshInfo.def("NbQuadrangles", [](SMDS_MeshInfo &self) -> int { return self.NbQuadrangles(); });
	cls_SMDS_MeshInfo.def("NbQuadrangles", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementOrder) const ) &SMDS_MeshInfo::NbQuadrangles, "None", py::arg("order"));
	cls_SMDS_MeshInfo.def("NbBiQuadTriangles", (int (SMDS_MeshInfo::*)() const ) &SMDS_MeshInfo::NbBiQuadTriangles, "None");
	cls_SMDS_MeshInfo.def("NbBiQuadQuadrangles", (int (SMDS_MeshInfo::*)() const ) &SMDS_MeshInfo::NbBiQuadQuadrangles, "None");
	cls_SMDS_MeshInfo.def("NbPolygons", [](SMDS_MeshInfo &self) -> int { return self.NbPolygons(); });
	cls_SMDS_MeshInfo.def("NbPolygons", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementOrder) const ) &SMDS_MeshInfo::NbPolygons, "None", py::arg("order"));
	cls_SMDS_MeshInfo.def("NbVolumes", [](SMDS_MeshInfo &self) -> int { return self.NbVolumes(); });
	cls_SMDS_MeshInfo.def("NbVolumes", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementOrder) const ) &SMDS_MeshInfo::NbVolumes, "None", py::arg("order"));
	cls_SMDS_MeshInfo.def("NbTetras", [](SMDS_MeshInfo &self) -> int { return self.NbTetras(); });
	cls_SMDS_MeshInfo.def("NbTetras", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementOrder) const ) &SMDS_MeshInfo::NbTetras, "None", py::arg("order"));
	cls_SMDS_MeshInfo.def("NbHexas", [](SMDS_MeshInfo &self) -> int { return self.NbHexas(); });
	cls_SMDS_MeshInfo.def("NbHexas", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementOrder) const ) &SMDS_MeshInfo::NbHexas, "None", py::arg("order"));
	cls_SMDS_MeshInfo.def("NbPyramids", [](SMDS_MeshInfo &self) -> int { return self.NbPyramids(); });
	cls_SMDS_MeshInfo.def("NbPyramids", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementOrder) const ) &SMDS_MeshInfo::NbPyramids, "None", py::arg("order"));
	cls_SMDS_MeshInfo.def("NbPrisms", [](SMDS_MeshInfo &self) -> int { return self.NbPrisms(); });
	cls_SMDS_MeshInfo.def("NbPrisms", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementOrder) const ) &SMDS_MeshInfo::NbPrisms, "None", py::arg("order"));
	cls_SMDS_MeshInfo.def("NbHexPrisms", [](SMDS_MeshInfo &self) -> int { return self.NbHexPrisms(); });
	cls_SMDS_MeshInfo.def("NbHexPrisms", (int (SMDS_MeshInfo::*)(SMDSAbs_ElementOrder) const ) &SMDS_MeshInfo::NbHexPrisms, "None", py::arg("order"));
	cls_SMDS_MeshInfo.def("NbTriQuadHexas", (int (SMDS_MeshInfo::*)() const ) &SMDS_MeshInfo::NbTriQuadHexas, "None");
	cls_SMDS_MeshInfo.def("NbPolyhedrons", (int (SMDS_MeshInfo::*)() const ) &SMDS_MeshInfo::NbPolyhedrons, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_VolumeOfNodes.hxx
	py::class_<SMDS_VolumeOfNodes, std::unique_ptr<SMDS_VolumeOfNodes, py::nodelete>, SMDS_MeshVolume> cls_SMDS_VolumeOfNodes(mod, "SMDS_VolumeOfNodes", "None");
	cls_SMDS_VolumeOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("node1"), py::arg("node2"), py::arg("node3"), py::arg("node4"));
	cls_SMDS_VolumeOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("node1"), py::arg("node2"), py::arg("node3"), py::arg("node4"), py::arg("node5"));
	cls_SMDS_VolumeOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("node1"), py::arg("node2"), py::arg("node3"), py::arg("node4"), py::arg("node5"), py::arg("node6"));
	cls_SMDS_VolumeOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("node1"), py::arg("node2"), py::arg("node3"), py::arg("node4"), py::arg("node5"), py::arg("node6"), py::arg("node7"), py::arg("node8"));
	// FIXME cls_SMDS_VolumeOfNodes.def("ChangeNodes", (bool (SMDS_VolumeOfNodes::*)(const SMDS_MeshNode *[], const int)) &SMDS_VolumeOfNodes::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_VolumeOfNodes.def("Print", (void (SMDS_VolumeOfNodes::*)(std::ostream &) const ) &SMDS_VolumeOfNodes::Print, "None", py::arg("OS"));
	cls_SMDS_VolumeOfNodes.def("NbFaces", (int (SMDS_VolumeOfNodes::*)() const ) &SMDS_VolumeOfNodes::NbFaces, "None");
	cls_SMDS_VolumeOfNodes.def("NbNodes", (int (SMDS_VolumeOfNodes::*)() const ) &SMDS_VolumeOfNodes::NbNodes, "None");
	cls_SMDS_VolumeOfNodes.def("NbEdges", (int (SMDS_VolumeOfNodes::*)() const ) &SMDS_VolumeOfNodes::NbEdges, "None");
	cls_SMDS_VolumeOfNodes.def("GetType", (SMDSAbs_ElementType (SMDS_VolumeOfNodes::*)() const ) &SMDS_VolumeOfNodes::GetType, "None");
	cls_SMDS_VolumeOfNodes.def("GetEntityType", (SMDSAbs_EntityType (SMDS_VolumeOfNodes::*)() const ) &SMDS_VolumeOfNodes::GetEntityType, "None");
	cls_SMDS_VolumeOfNodes.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_VolumeOfNodes::*)() const ) &SMDS_VolumeOfNodes::GetGeomType, "None");
	cls_SMDS_VolumeOfNodes.def("GetNode", (const SMDS_MeshNode * (SMDS_VolumeOfNodes::*)(const int) const ) &SMDS_VolumeOfNodes::GetNode, "Return node by its index", py::arg("ind"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_VtkEdge.hxx
	py::class_<SMDS_VtkEdge, std::unique_ptr<SMDS_VtkEdge, py::nodelete>, SMDS_MeshEdge> cls_SMDS_VtkEdge(mod, "SMDS_VtkEdge", "None");
	cls_SMDS_VtkEdge.def(py::init<>());
	cls_SMDS_VtkEdge.def(py::init<std::vector<vtkIdType> &, SMDS_Mesh *>(), py::arg("nodeIds"), py::arg("mesh"));
	cls_SMDS_VtkEdge.def("init", (void (SMDS_VtkEdge::*)(std::vector<vtkIdType> &, SMDS_Mesh *)) &SMDS_VtkEdge::init, "None", py::arg("nodeIds"), py::arg("mesh"));
	// FIXME cls_SMDS_VtkEdge.def("ChangeNodes", (bool (SMDS_VtkEdge::*)(const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_VtkEdge::ChangeNodes, "None", py::arg("node1"), py::arg("node2"));
	// FIXME cls_SMDS_VtkEdge.def("ChangeNodes", (bool (SMDS_VtkEdge::*)(const SMDS_MeshNode *[], const int)) &SMDS_VtkEdge::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_VtkEdge.def("IsMediumNode", (bool (SMDS_VtkEdge::*)(const SMDS_MeshNode *) const ) &SMDS_VtkEdge::IsMediumNode, "None", py::arg("node"));
	cls_SMDS_VtkEdge.def("Print", (void (SMDS_VtkEdge::*)(std::ostream &) const ) &SMDS_VtkEdge::Print, "None", py::arg("OS"));
	cls_SMDS_VtkEdge.def("NbNodes", (int (SMDS_VtkEdge::*)() const ) &SMDS_VtkEdge::NbNodes, "None");
	cls_SMDS_VtkEdge.def("NbEdges", (int (SMDS_VtkEdge::*)() const ) &SMDS_VtkEdge::NbEdges, "None");
	cls_SMDS_VtkEdge.def("GetVtkType", (vtkIdType (SMDS_VtkEdge::*)() const ) &SMDS_VtkEdge::GetVtkType, "None");
	cls_SMDS_VtkEdge.def("GetEntityType", (SMDSAbs_EntityType (SMDS_VtkEdge::*)() const ) &SMDS_VtkEdge::GetEntityType, "None");
	cls_SMDS_VtkEdge.def("GetNode", (const SMDS_MeshNode * (SMDS_VtkEdge::*)(const int) const ) &SMDS_VtkEdge::GetNode, "None", py::arg("ind"));
	cls_SMDS_VtkEdge.def("IsQuadratic", (bool (SMDS_VtkEdge::*)() const ) &SMDS_VtkEdge::IsQuadratic, "None");
	cls_SMDS_VtkEdge.def("elementsIterator", (SMDS_ElemIteratorPtr (SMDS_VtkEdge::*)(SMDSAbs_ElementType) const ) &SMDS_VtkEdge::elementsIterator, "None", py::arg("type"));
	cls_SMDS_VtkEdge.def("nodesIteratorToUNV", (SMDS_NodeIteratorPtr (SMDS_VtkEdge::*)() const ) &SMDS_VtkEdge::nodesIteratorToUNV, "None");
	cls_SMDS_VtkEdge.def("interlacedNodesIterator", (SMDS_NodeIteratorPtr (SMDS_VtkEdge::*)() const ) &SMDS_VtkEdge::interlacedNodesIterator, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_VtkFace.hxx
	py::class_<SMDS_VtkFace, std::unique_ptr<SMDS_VtkFace, py::nodelete>, SMDS_MeshFace> cls_SMDS_VtkFace(mod, "SMDS_VtkFace", "None");
	cls_SMDS_VtkFace.def(py::init<>());
	cls_SMDS_VtkFace.def(py::init<const std::vector<vtkIdType> &, SMDS_Mesh *>(), py::arg("nodeIds"), py::arg("mesh"));
	cls_SMDS_VtkFace.def("init", (void (SMDS_VtkFace::*)(const std::vector<vtkIdType> &, SMDS_Mesh *)) &SMDS_VtkFace::init, "None", py::arg("nodeIds"), py::arg("mesh"));
	cls_SMDS_VtkFace.def("initPoly", (void (SMDS_VtkFace::*)(const std::vector<vtkIdType> &, SMDS_Mesh *)) &SMDS_VtkFace::initPoly, "None", py::arg("nodeIds"), py::arg("mesh"));
	cls_SMDS_VtkFace.def("initQuadPoly", (void (SMDS_VtkFace::*)(const std::vector<vtkIdType> &, SMDS_Mesh *)) &SMDS_VtkFace::initQuadPoly, "None", py::arg("nodeIds"), py::arg("mesh"));
	// FIXME cls_SMDS_VtkFace.def("ChangeNodes", (bool (SMDS_VtkFace::*)(const SMDS_MeshNode *[], const int)) &SMDS_VtkFace::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_VtkFace.def("ChangeApex", (void (SMDS_VtkFace::*)(SMDS_MeshNode *)) &SMDS_VtkFace::ChangeApex, "None", py::arg("node"));
	cls_SMDS_VtkFace.def("Print", (void (SMDS_VtkFace::*)(std::ostream &) const ) &SMDS_VtkFace::Print, "None", py::arg("OS"));
	cls_SMDS_VtkFace.def("NbEdges", (int (SMDS_VtkFace::*)() const ) &SMDS_VtkFace::NbEdges, "None");
	cls_SMDS_VtkFace.def("NbFaces", (int (SMDS_VtkFace::*)() const ) &SMDS_VtkFace::NbFaces, "None");
	cls_SMDS_VtkFace.def("NbNodes", (int (SMDS_VtkFace::*)() const ) &SMDS_VtkFace::NbNodes, "None");
	cls_SMDS_VtkFace.def("GetVtkType", (vtkIdType (SMDS_VtkFace::*)() const ) &SMDS_VtkFace::GetVtkType, "None");
	cls_SMDS_VtkFace.def("GetEntityType", (SMDSAbs_EntityType (SMDS_VtkFace::*)() const ) &SMDS_VtkFace::GetEntityType, "None");
	cls_SMDS_VtkFace.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_VtkFace::*)() const ) &SMDS_VtkFace::GetGeomType, "None");
	cls_SMDS_VtkFace.def("GetNode", (const SMDS_MeshNode * (SMDS_VtkFace::*)(const int) const ) &SMDS_VtkFace::GetNode, "None", py::arg("ind"));
	cls_SMDS_VtkFace.def("GetNodeIndex", (int (SMDS_VtkFace::*)(const SMDS_MeshNode *) const ) &SMDS_VtkFace::GetNodeIndex, "None", py::arg("node"));
	cls_SMDS_VtkFace.def("IsQuadratic", (bool (SMDS_VtkFace::*)() const ) &SMDS_VtkFace::IsQuadratic, "None");
	cls_SMDS_VtkFace.def("IsPoly", (bool (SMDS_VtkFace::*)() const ) &SMDS_VtkFace::IsPoly, "None");
	cls_SMDS_VtkFace.def("IsMediumNode", (bool (SMDS_VtkFace::*)(const SMDS_MeshNode *) const ) &SMDS_VtkFace::IsMediumNode, "None", py::arg("node"));
	cls_SMDS_VtkFace.def("NbCornerNodes", (int (SMDS_VtkFace::*)() const ) &SMDS_VtkFace::NbCornerNodes, "None");
	cls_SMDS_VtkFace.def("elementsIterator", (SMDS_ElemIteratorPtr (SMDS_VtkFace::*)(SMDSAbs_ElementType) const ) &SMDS_VtkFace::elementsIterator, "None", py::arg("type"));
	cls_SMDS_VtkFace.def("nodesIteratorToUNV", (SMDS_NodeIteratorPtr (SMDS_VtkFace::*)() const ) &SMDS_VtkFace::nodesIteratorToUNV, "None");
	cls_SMDS_VtkFace.def("interlacedNodesIterator", (SMDS_NodeIteratorPtr (SMDS_VtkFace::*)() const ) &SMDS_VtkFace::interlacedNodesIterator, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_Downward, std::unique_ptr<SMDS_Downward, py::nodelete>> cls_SMDS_Downward(mod, "SMDS_Downward", "None");
	cls_SMDS_Downward.def("getNumberOfDownCells", (int (SMDS_Downward::*)(int)) &SMDS_Downward::getNumberOfDownCells, "None", py::arg("cellId"));
	cls_SMDS_Downward.def("getDownCells", (const int * (SMDS_Downward::*)(int)) &SMDS_Downward::getDownCells, "None", py::arg("cellId"));
	cls_SMDS_Downward.def("getDownTypes", (const unsigned char * (SMDS_Downward::*)(int)) &SMDS_Downward::getDownTypes, "None", py::arg("cellId"));
	cls_SMDS_Downward.def("getNumberOfUpCells", (int (SMDS_Downward::*)(int)) &SMDS_Downward::getNumberOfUpCells, "None", py::arg("cellId"));
	cls_SMDS_Downward.def("getUpCells", (const int * (SMDS_Downward::*)(int)) &SMDS_Downward::getUpCells, "None", py::arg("cellId"));
	cls_SMDS_Downward.def("getUpTypes", (const unsigned char * (SMDS_Downward::*)(int)) &SMDS_Downward::getUpTypes, "None", py::arg("cellId"));
	cls_SMDS_Downward.def("getNodeIds", (void (SMDS_Downward::*)(int, std::set<int> &)) &SMDS_Downward::getNodeIds, "None", py::arg("cellId"), py::arg("nodeSet"));
	cls_SMDS_Downward.def("getNodes", (int (SMDS_Downward::*)(int, int *)) &SMDS_Downward::getNodes, "None", py::arg("cellId"), py::arg("nodevec"));
	cls_SMDS_Downward.def("getOrderedNodesOfFace", (void (SMDS_Downward::*)(int, std::vector<vtkIdType> &)) &SMDS_Downward::getOrderedNodesOfFace, "None", py::arg("cellId"), py::arg("orderedNodes"));
	cls_SMDS_Downward.def("getVtkCellId", (int (SMDS_Downward::*)(int)) &SMDS_Downward::getVtkCellId, "None", py::arg("cellId"));
	cls_SMDS_Downward.def("getMaxId", (int (SMDS_Downward::*)()) &SMDS_Downward::getMaxId, "None");
	cls_SMDS_Downward.def_static("getCellDimension_", (int (*)(unsigned char)) &SMDS_Downward::getCellDimension, "None", py::arg("cellType"));

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_UnstructuredGrid.hxx
	py::class_<SMDS_CellLinks, std::unique_ptr<SMDS_CellLinks, py::nodelete>, vtkCellLinks> cls_SMDS_CellLinks(mod, "SMDS_CellLinks", "None");
	cls_SMDS_CellLinks.def("ResizeForPoint", (void (SMDS_CellLinks::*)(vtkIdType)) &SMDS_CellLinks::ResizeForPoint, "None", py::arg("vtkID"));
	cls_SMDS_CellLinks.def("BuildLinks", (void (SMDS_CellLinks::*)(vtkDataSet *, vtkCellArray *, vtkUnsignedCharArray *)) &SMDS_CellLinks::BuildLinks, "None", py::arg("data"), py::arg("Connectivity"), py::arg("types"));
	cls_SMDS_CellLinks.def_static("New_", (SMDS_CellLinks * (*)()) &SMDS_CellLinks::New, "None");
	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_UnstructuredGrid.hxx
	py::class_<SMDS_UnstructuredGrid, std::unique_ptr<SMDS_UnstructuredGrid, py::nodelete>, vtkUnstructuredGrid> cls_SMDS_UnstructuredGrid(mod, "SMDS_UnstructuredGrid", "None");
	cls_SMDS_UnstructuredGrid.def("setSMDS_mesh", (void (SMDS_UnstructuredGrid::*)(SMDS_Mesh *)) &SMDS_UnstructuredGrid::setSMDS_mesh, "None", py::arg("mesh"));
	cls_SMDS_UnstructuredGrid.def("compactGrid", (void (SMDS_UnstructuredGrid::*)(std::vector<int> &, int, std::vector<int> &, int)) &SMDS_UnstructuredGrid::compactGrid, "None", py::arg("idNodesOldToNew"), py::arg("newNodeSize"), py::arg("idCellsOldToNew"), py::arg("newCellSize"));
	cls_SMDS_UnstructuredGrid.def("GetMTime", (vtkMTimeType (SMDS_UnstructuredGrid::*)()) &SMDS_UnstructuredGrid::GetMTime, "None");
	cls_SMDS_UnstructuredGrid.def("GetPoints", (vtkPoints * (SMDS_UnstructuredGrid::*)()) &SMDS_UnstructuredGrid::GetPoints, "None");
	cls_SMDS_UnstructuredGrid.def("InsertNextLinkedCell", (int (SMDS_UnstructuredGrid::*)(int, int, vtkIdType *)) &SMDS_UnstructuredGrid::InsertNextLinkedCell, "None", py::arg("type"), py::arg("npts"), py::arg("pts"));
	cls_SMDS_UnstructuredGrid.def("CellIdToDownId", (int (SMDS_UnstructuredGrid::*)(int)) &SMDS_UnstructuredGrid::CellIdToDownId, "None", py::arg("vtkCellId"));
	cls_SMDS_UnstructuredGrid.def("setCellIdToDownId", (void (SMDS_UnstructuredGrid::*)(int, int)) &SMDS_UnstructuredGrid::setCellIdToDownId, "None", py::arg("vtkCellId"), py::arg("downId"));
	cls_SMDS_UnstructuredGrid.def("CleanDownwardConnectivity", (void (SMDS_UnstructuredGrid::*)()) &SMDS_UnstructuredGrid::CleanDownwardConnectivity, "None");
	cls_SMDS_UnstructuredGrid.def("BuildDownwardConnectivity", (void (SMDS_UnstructuredGrid::*)(bool)) &SMDS_UnstructuredGrid::BuildDownwardConnectivity, "None", py::arg("withEdges"));
	cls_SMDS_UnstructuredGrid.def("GetNeighbors", [](SMDS_UnstructuredGrid &self, int * a0, int * a1, unsigned char * a2, int a3) -> int { return self.GetNeighbors(a0, a1, a2, a3); }, py::arg("neighborsVtkIds"), py::arg("downIds"), py::arg("downTypes"), py::arg("vtkId"));
	cls_SMDS_UnstructuredGrid.def("GetNeighbors", (int (SMDS_UnstructuredGrid::*)(int *, int *, unsigned char *, int, bool)) &SMDS_UnstructuredGrid::GetNeighbors, "None", py::arg("neighborsVtkIds"), py::arg("downIds"), py::arg("downTypes"), py::arg("vtkId"), py::arg("getSkin"));
	cls_SMDS_UnstructuredGrid.def("GetParentVolumes", (int (SMDS_UnstructuredGrid::*)(int *, int)) &SMDS_UnstructuredGrid::GetParentVolumes, "None", py::arg("volVtkIds"), py::arg("vtkId"));
	cls_SMDS_UnstructuredGrid.def("GetParentVolumes", (int (SMDS_UnstructuredGrid::*)(int *, int, unsigned char)) &SMDS_UnstructuredGrid::GetParentVolumes, "None", py::arg("volVtkIds"), py::arg("downId"), py::arg("downType"));
	cls_SMDS_UnstructuredGrid.def("GetNodeIds", (void (SMDS_UnstructuredGrid::*)(std::set<int> &, int, unsigned char)) &SMDS_UnstructuredGrid::GetNodeIds, "None", py::arg("nodeSet"), py::arg("downId"), py::arg("downType"));
	cls_SMDS_UnstructuredGrid.def("ModifyCellNodes", (void (SMDS_UnstructuredGrid::*)(int, std::map<int, int>)) &SMDS_UnstructuredGrid::ModifyCellNodes, "None", py::arg("vtkVolId"), py::arg("localClonedNodeIds"));
	cls_SMDS_UnstructuredGrid.def("getOrderedNodesOfFace", (int (SMDS_UnstructuredGrid::*)(int, int &, std::vector<vtkIdType> &)) &SMDS_UnstructuredGrid::getOrderedNodesOfFace, "None", py::arg("vtkVolId"), py::arg("dim"), py::arg("orderedNodes"));
	cls_SMDS_UnstructuredGrid.def("extrudeVolumeFromFace", (SMDS_MeshCell * (SMDS_UnstructuredGrid::*)(int, int, int, std::set<int> &, std::map<int, std::map<int, int> > &, std::map<int, std::map<long, int> > &)) &SMDS_UnstructuredGrid::extrudeVolumeFromFace, "None", py::arg("vtkVolId"), py::arg("domain1"), py::arg("domain2"), py::arg("originalNodes"), py::arg("nodeDomains"), py::arg("nodeQuadDomains"));
	cls_SMDS_UnstructuredGrid.def("BuildLinks", (void (SMDS_UnstructuredGrid::*)()) &SMDS_UnstructuredGrid::BuildLinks, "None");
	cls_SMDS_UnstructuredGrid.def("DeleteLinks", (void (SMDS_UnstructuredGrid::*)()) &SMDS_UnstructuredGrid::DeleteLinks, "None");
	cls_SMDS_UnstructuredGrid.def("GetLinks", (SMDS_CellLinks * (SMDS_UnstructuredGrid::*)()) &SMDS_UnstructuredGrid::GetLinks, "None");
	cls_SMDS_UnstructuredGrid.def("HasLinks", (bool (SMDS_UnstructuredGrid::*)() const ) &SMDS_UnstructuredGrid::HasLinks, "None");
	cls_SMDS_UnstructuredGrid.def("getDownArray", (SMDS_Downward * (SMDS_UnstructuredGrid::*)(unsigned char)) &SMDS_UnstructuredGrid::getDownArray, "None", py::arg("vtkType"));
	cls_SMDS_UnstructuredGrid.def("AllocateDiameters", (void (SMDS_UnstructuredGrid::*)(vtkIdType)) &SMDS_UnstructuredGrid::AllocateDiameters, "None", py::arg("maxVtkID"));
	cls_SMDS_UnstructuredGrid.def("SetBallDiameter", (void (SMDS_UnstructuredGrid::*)(vtkIdType, double)) &SMDS_UnstructuredGrid::SetBallDiameter, "None", py::arg("vtkID"), py::arg("diameter"));
	cls_SMDS_UnstructuredGrid.def("GetBallDiameter", (double (SMDS_UnstructuredGrid::*)(vtkIdType) const ) &SMDS_UnstructuredGrid::GetBallDiameter, "None", py::arg("vtkID"));
	cls_SMDS_UnstructuredGrid.def_static("New_", (SMDS_UnstructuredGrid * (*)()) &SMDS_UnstructuredGrid::New, "None");
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_VtkVolume.hxx
	py::class_<SMDS_VtkVolume, std::unique_ptr<SMDS_VtkVolume, py::nodelete>, SMDS_MeshVolume> cls_SMDS_VtkVolume(mod, "SMDS_VtkVolume", "None");
	cls_SMDS_VtkVolume.def(py::init<>());
	cls_SMDS_VtkVolume.def(py::init<const std::vector<vtkIdType> &, SMDS_Mesh *>(), py::arg("nodeIds"), py::arg("mesh"));
	cls_SMDS_VtkVolume.def("init", (void (SMDS_VtkVolume::*)(const std::vector<vtkIdType> &, SMDS_Mesh *)) &SMDS_VtkVolume::init, "None", py::arg("nodeIds"), py::arg("mesh"));
	cls_SMDS_VtkVolume.def("initPoly", (void (SMDS_VtkVolume::*)(const std::vector<vtkIdType> &, const std::vector<int> &, SMDS_Mesh *)) &SMDS_VtkVolume::initPoly, "None", py::arg("nodeIds"), py::arg("nbNodesPerFace"), py::arg("mesh"));
	// FIXME cls_SMDS_VtkVolume.def("ChangeNodes", (bool (SMDS_VtkVolume::*)(const SMDS_MeshNode *[], const int)) &SMDS_VtkVolume::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	// FIXME cls_SMDS_VtkVolume.def("vtkOrder", (bool (SMDS_VtkVolume::*)(const SMDS_MeshNode *[], const int)) &SMDS_VtkVolume::vtkOrder, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_VtkVolume.def("Print", (void (SMDS_VtkVolume::*)(std::ostream &) const ) &SMDS_VtkVolume::Print, "None", py::arg("OS"));
	cls_SMDS_VtkVolume.def("NbFaces", (int (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::NbFaces, "None");
	cls_SMDS_VtkVolume.def("NbNodes", (int (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::NbNodes, "None");
	cls_SMDS_VtkVolume.def("NbEdges", (int (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::NbEdges, "None");
	cls_SMDS_VtkVolume.def("NbFaceNodes", (int (SMDS_VtkVolume::*)(const int) const ) &SMDS_VtkVolume::NbFaceNodes, "None", py::arg("face_ind"));
	cls_SMDS_VtkVolume.def("GetFaceNode", (const SMDS_MeshNode * (SMDS_VtkVolume::*)(const int, const int) const ) &SMDS_VtkVolume::GetFaceNode, "None", py::arg("face_ind"), py::arg("node_ind"));
	cls_SMDS_VtkVolume.def("GetType", (SMDSAbs_ElementType (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::GetType, "None");
	cls_SMDS_VtkVolume.def("GetVtkType", (vtkIdType (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::GetVtkType, "None");
	cls_SMDS_VtkVolume.def("GetEntityType", (SMDSAbs_EntityType (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::GetEntityType, "None");
	cls_SMDS_VtkVolume.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::GetGeomType, "None");
	cls_SMDS_VtkVolume.def("GetNode", (const SMDS_MeshNode * (SMDS_VtkVolume::*)(const int) const ) &SMDS_VtkVolume::GetNode, "None", py::arg("ind"));
	cls_SMDS_VtkVolume.def("GetNodeIndex", (int (SMDS_VtkVolume::*)(const SMDS_MeshNode *) const ) &SMDS_VtkVolume::GetNodeIndex, "None", py::arg("node"));
	cls_SMDS_VtkVolume.def("IsQuadratic", (bool (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::IsQuadratic, "None");
	cls_SMDS_VtkVolume.def("IsPoly", (bool (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::IsPoly, "None");
	cls_SMDS_VtkVolume.def("IsMediumNode", (bool (SMDS_VtkVolume::*)(const SMDS_MeshNode *) const ) &SMDS_VtkVolume::IsMediumNode, "None", py::arg("node"));
	cls_SMDS_VtkVolume.def("NbCornerNodes", (int (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::NbCornerNodes, "None");
	cls_SMDS_VtkVolume.def_static("gravityCenter_", (void (*)(SMDS_UnstructuredGrid *, const vtkIdType *, int, double *)) &SMDS_VtkVolume::gravityCenter, "None", py::arg("grid"), py::arg("nodeIds"), py::arg("nbNodes"), py::arg("result"));
	cls_SMDS_VtkVolume.def_static("isForward_", (bool (*)(double *, double *, double *, double *)) &SMDS_VtkVolume::isForward, "None", py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d"));
	cls_SMDS_VtkVolume.def("NbUniqueNodes", (int (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::NbUniqueNodes, "None");
	cls_SMDS_VtkVolume.def("uniqueNodesIterator", (SMDS_ElemIteratorPtr (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::uniqueNodesIterator, "None");
	cls_SMDS_VtkVolume.def("GetQuantities", (std::vector<int> (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::GetQuantities, "None");
	cls_SMDS_VtkVolume.def("elementsIterator", (SMDS_ElemIteratorPtr (SMDS_VtkVolume::*)(SMDSAbs_ElementType) const ) &SMDS_VtkVolume::elementsIterator, "None", py::arg("type"));
	cls_SMDS_VtkVolume.def("nodesIteratorToUNV", (SMDS_NodeIteratorPtr (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::nodesIteratorToUNV, "None");
	cls_SMDS_VtkVolume.def("interlacedNodesIterator", (SMDS_NodeIteratorPtr (SMDS_VtkVolume::*)() const ) &SMDS_VtkVolume::interlacedNodesIterator, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_BallElement.hxx
	py::class_<SMDS_BallElement, std::unique_ptr<SMDS_BallElement, py::nodelete>, SMDS_MeshCell> cls_SMDS_BallElement(mod, "SMDS_BallElement", "None");
	cls_SMDS_BallElement.def(py::init<>());
	cls_SMDS_BallElement.def(py::init<const SMDS_MeshNode *, double>(), py::arg("node"), py::arg("diameter"));
	cls_SMDS_BallElement.def(py::init<vtkIdType, double, SMDS_Mesh *>(), py::arg("nodeId"), py::arg("diameter"), py::arg("mesh"));
	cls_SMDS_BallElement.def("init", (void (SMDS_BallElement::*)(vtkIdType, double, SMDS_Mesh *)) &SMDS_BallElement::init, "None", py::arg("nodeId"), py::arg("diameter"), py::arg("mesh"));
	cls_SMDS_BallElement.def("GetDiameter", (double (SMDS_BallElement::*)() const ) &SMDS_BallElement::GetDiameter, "None");
	cls_SMDS_BallElement.def("SetDiameter", (void (SMDS_BallElement::*)(double)) &SMDS_BallElement::SetDiameter, "None", py::arg("diameter"));
	cls_SMDS_BallElement.def("ChangeNode", (bool (SMDS_BallElement::*)(const SMDS_MeshNode *)) &SMDS_BallElement::ChangeNode, "None", py::arg("node"));
	// FIXME cls_SMDS_BallElement.def("ChangeNodes", (bool (SMDS_BallElement::*)(const SMDS_MeshNode *[], const int)) &SMDS_BallElement::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_BallElement.def("Print", (void (SMDS_BallElement::*)(std::ostream &) const ) &SMDS_BallElement::Print, "None", py::arg("OS"));
	cls_SMDS_BallElement.def("GetType", (SMDSAbs_ElementType (SMDS_BallElement::*)() const ) &SMDS_BallElement::GetType, "None");
	cls_SMDS_BallElement.def("GetVtkType", (vtkIdType (SMDS_BallElement::*)() const ) &SMDS_BallElement::GetVtkType, "None");
	cls_SMDS_BallElement.def("GetEntityType", (SMDSAbs_EntityType (SMDS_BallElement::*)() const ) &SMDS_BallElement::GetEntityType, "None");
	cls_SMDS_BallElement.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_BallElement::*)() const ) &SMDS_BallElement::GetGeomType, "None");
	cls_SMDS_BallElement.def("NbNodes", (int (SMDS_BallElement::*)() const ) &SMDS_BallElement::NbNodes, "None");
	cls_SMDS_BallElement.def("NbEdges", (int (SMDS_BallElement::*)() const ) &SMDS_BallElement::NbEdges, "None");
	cls_SMDS_BallElement.def("NbFaces", (int (SMDS_BallElement::*)() const ) &SMDS_BallElement::NbFaces, "None");
	cls_SMDS_BallElement.def("GetNode", (const SMDS_MeshNode * (SMDS_BallElement::*)(const int) const ) &SMDS_BallElement::GetNode, "None", py::arg("ind"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<ListElemByNodesType, std::unique_ptr<ListElemByNodesType, Deleter<ListElemByNodesType>>> cls_(mod, "", "None");
	cls_.def(py::init<>());

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<DownIdType, std::unique_ptr<DownIdType, Deleter<DownIdType>>> cls_DownIdType(mod, "DownIdType", "None");
	cls_DownIdType.def(py::init<int, unsigned char>(), py::arg("a"), py::arg("b"));

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<DownIdCompare, std::unique_ptr<DownIdCompare, Deleter<DownIdCompare>>> cls_DownIdCompare(mod, "DownIdCompare", "None");
	cls_DownIdCompare.def(py::init<>());
	cls_DownIdCompare.def("__call__", (bool (DownIdCompare::*)(const DownIdType, const DownIdType) const ) &DownIdCompare::operator(), py::is_operator(), "None", py::arg("e1"), py::arg("e2"));
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_Down1D, std::unique_ptr<SMDS_Down1D, py::nodelete>, SMDS_Downward> cls_SMDS_Down1D(mod, "SMDS_Down1D", "None");
	cls_SMDS_Down1D.def("getNumberOfUpCells", (int (SMDS_Down1D::*)(int)) &SMDS_Down1D::getNumberOfUpCells, "None", py::arg("cellId"));
	cls_SMDS_Down1D.def("getUpCells", (const int * (SMDS_Down1D::*)(int)) &SMDS_Down1D::getUpCells, "None", py::arg("cellId"));
	cls_SMDS_Down1D.def("getUpTypes", (const unsigned char * (SMDS_Down1D::*)(int)) &SMDS_Down1D::getUpTypes, "None", py::arg("cellId"));
	cls_SMDS_Down1D.def("getNodeIds", (void (SMDS_Down1D::*)(int, std::set<int> &)) &SMDS_Down1D::getNodeIds, "None", py::arg("cellId"), py::arg("nodeSet"));
	cls_SMDS_Down1D.def("getNodes", (int (SMDS_Down1D::*)(int, int *)) &SMDS_Down1D::getNodes, "None", py::arg("cellId"), py::arg("nodevec"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_Down2D, std::unique_ptr<SMDS_Down2D, py::nodelete>, SMDS_Downward> cls_SMDS_Down2D(mod, "SMDS_Down2D", "None");
	cls_SMDS_Down2D.def("getNumberOfUpCells", (int (SMDS_Down2D::*)(int)) &SMDS_Down2D::getNumberOfUpCells, "None", py::arg("cellId"));
	cls_SMDS_Down2D.def("getUpCells", (const int * (SMDS_Down2D::*)(int)) &SMDS_Down2D::getUpCells, "None", py::arg("cellId"));
	cls_SMDS_Down2D.def("getUpTypes", (const unsigned char * (SMDS_Down2D::*)(int)) &SMDS_Down2D::getUpTypes, "None", py::arg("cellId"));
	cls_SMDS_Down2D.def("getNodeIds", (void (SMDS_Down2D::*)(int, std::set<int> &)) &SMDS_Down2D::getNodeIds, "None", py::arg("cellId"), py::arg("nodeSet"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_Down3D, std::unique_ptr<SMDS_Down3D, py::nodelete>, SMDS_Downward> cls_SMDS_Down3D(mod, "SMDS_Down3D", "None");
	cls_SMDS_Down3D.def("getNumberOfUpCells", (int (SMDS_Down3D::*)(int)) &SMDS_Down3D::getNumberOfUpCells, "None", py::arg("cellId"));
	cls_SMDS_Down3D.def("getUpCells", (const int * (SMDS_Down3D::*)(int)) &SMDS_Down3D::getUpCells, "None", py::arg("cellId"));
	cls_SMDS_Down3D.def("getUpTypes", (const unsigned char * (SMDS_Down3D::*)(int)) &SMDS_Down3D::getUpTypes, "None", py::arg("cellId"));
	cls_SMDS_Down3D.def("getNodeIds", (void (SMDS_Down3D::*)(int, std::set<int> &)) &SMDS_Down3D::getNodeIds, "None", py::arg("cellId"), py::arg("nodeSet"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownEdge, std::unique_ptr<SMDS_DownEdge, py::nodelete>, SMDS_Down1D> cls_SMDS_DownEdge(mod, "SMDS_DownEdge", "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownQuadEdge, std::unique_ptr<SMDS_DownQuadEdge, py::nodelete>, SMDS_Down1D> cls_SMDS_DownQuadEdge(mod, "SMDS_DownQuadEdge", "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownTriangle, std::unique_ptr<SMDS_DownTriangle, py::nodelete>, SMDS_Down2D> cls_SMDS_DownTriangle(mod, "SMDS_DownTriangle", "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownQuadTriangle, std::unique_ptr<SMDS_DownQuadTriangle, py::nodelete>, SMDS_Down2D> cls_SMDS_DownQuadTriangle(mod, "SMDS_DownQuadTriangle", "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownQuadrangle, std::unique_ptr<SMDS_DownQuadrangle, py::nodelete>, SMDS_Down2D> cls_SMDS_DownQuadrangle(mod, "SMDS_DownQuadrangle", "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownQuadQuadrangle, std::unique_ptr<SMDS_DownQuadQuadrangle, py::nodelete>, SMDS_Down2D> cls_SMDS_DownQuadQuadrangle(mod, "SMDS_DownQuadQuadrangle", "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownTetra, std::unique_ptr<SMDS_DownTetra, py::nodelete>, SMDS_Down3D> cls_SMDS_DownTetra(mod, "SMDS_DownTetra", "None");
	cls_SMDS_DownTetra.def("getOrderedNodesOfFace", (void (SMDS_DownTetra::*)(int, std::vector<vtkIdType> &)) &SMDS_DownTetra::getOrderedNodesOfFace, "None", py::arg("cellId"), py::arg("orderedNodes"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownQuadTetra, std::unique_ptr<SMDS_DownQuadTetra, py::nodelete>, SMDS_Down3D> cls_SMDS_DownQuadTetra(mod, "SMDS_DownQuadTetra", "None");
	cls_SMDS_DownQuadTetra.def("getOrderedNodesOfFace", (void (SMDS_DownQuadTetra::*)(int, std::vector<vtkIdType> &)) &SMDS_DownQuadTetra::getOrderedNodesOfFace, "None", py::arg("cellId"), py::arg("orderedNodes"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownPyramid, std::unique_ptr<SMDS_DownPyramid, py::nodelete>, SMDS_Down3D> cls_SMDS_DownPyramid(mod, "SMDS_DownPyramid", "None");
	cls_SMDS_DownPyramid.def("getOrderedNodesOfFace", (void (SMDS_DownPyramid::*)(int, std::vector<vtkIdType> &)) &SMDS_DownPyramid::getOrderedNodesOfFace, "None", py::arg("cellId"), py::arg("orderedNodes"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownQuadPyramid, std::unique_ptr<SMDS_DownQuadPyramid, py::nodelete>, SMDS_Down3D> cls_SMDS_DownQuadPyramid(mod, "SMDS_DownQuadPyramid", "None");
	cls_SMDS_DownQuadPyramid.def("getOrderedNodesOfFace", (void (SMDS_DownQuadPyramid::*)(int, std::vector<vtkIdType> &)) &SMDS_DownQuadPyramid::getOrderedNodesOfFace, "None", py::arg("cellId"), py::arg("orderedNodes"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownPenta, std::unique_ptr<SMDS_DownPenta, py::nodelete>, SMDS_Down3D> cls_SMDS_DownPenta(mod, "SMDS_DownPenta", "None");
	cls_SMDS_DownPenta.def("getOrderedNodesOfFace", (void (SMDS_DownPenta::*)(int, std::vector<vtkIdType> &)) &SMDS_DownPenta::getOrderedNodesOfFace, "None", py::arg("cellId"), py::arg("orderedNodes"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownQuadPenta, std::unique_ptr<SMDS_DownQuadPenta, py::nodelete>, SMDS_Down3D> cls_SMDS_DownQuadPenta(mod, "SMDS_DownQuadPenta", "None");
	cls_SMDS_DownQuadPenta.def("getOrderedNodesOfFace", (void (SMDS_DownQuadPenta::*)(int, std::vector<vtkIdType> &)) &SMDS_DownQuadPenta::getOrderedNodesOfFace, "None", py::arg("cellId"), py::arg("orderedNodes"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownHexa, std::unique_ptr<SMDS_DownHexa, py::nodelete>, SMDS_Down3D> cls_SMDS_DownHexa(mod, "SMDS_DownHexa", "None");
	cls_SMDS_DownHexa.def("getOrderedNodesOfFace", (void (SMDS_DownHexa::*)(int, std::vector<vtkIdType> &)) &SMDS_DownHexa::getOrderedNodesOfFace, "None", py::arg("cellId"), py::arg("orderedNodes"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	py::class_<SMDS_DownQuadHexa, std::unique_ptr<SMDS_DownQuadHexa, py::nodelete>, SMDS_Down3D> cls_SMDS_DownQuadHexa(mod, "SMDS_DownQuadHexa", "None");
	cls_SMDS_DownQuadHexa.def("getOrderedNodesOfFace", (void (SMDS_DownQuadHexa::*)(int, std::vector<vtkIdType> &)) &SMDS_DownQuadHexa::getOrderedNodesOfFace, "None", py::arg("cellId"), py::arg("orderedNodes"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_EdgePosition.hxx
	py::class_<SMDS_EdgePosition, std::unique_ptr<SMDS_EdgePosition, Deleter<SMDS_EdgePosition>>, SMDS_Position> cls_SMDS_EdgePosition(mod, "SMDS_EdgePosition", "None");
	cls_SMDS_EdgePosition.def(py::init<>());
	cls_SMDS_EdgePosition.def(py::init<const double>(), py::arg("aUParam"));
	cls_SMDS_EdgePosition.def("GetTypeOfPosition", (SMDS_TypeOfPosition (SMDS_EdgePosition::*)() const ) &SMDS_EdgePosition::GetTypeOfPosition, "None");
	cls_SMDS_EdgePosition.def("SetUParameter", (void (SMDS_EdgePosition::*)(double)) &SMDS_EdgePosition::SetUParameter, "None", py::arg("aUparam"));
	cls_SMDS_EdgePosition.def("GetUParameter", (double (SMDS_EdgePosition::*)() const ) &SMDS_EdgePosition::GetUParameter, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_FaceOfEdges.hxx
	py::class_<SMDS_FaceOfEdges, std::unique_ptr<SMDS_FaceOfEdges, py::nodelete>, SMDS_MeshFace> cls_SMDS_FaceOfEdges(mod, "SMDS_FaceOfEdges", "None");
	cls_SMDS_FaceOfEdges.def(py::init<const SMDS_MeshEdge *, const SMDS_MeshEdge *, const SMDS_MeshEdge *>(), py::arg("edge1"), py::arg("edge2"), py::arg("edge3"));
	cls_SMDS_FaceOfEdges.def(py::init<const SMDS_MeshEdge *, const SMDS_MeshEdge *, const SMDS_MeshEdge *, const SMDS_MeshEdge *>(), py::arg("edge1"), py::arg("edge2"), py::arg("edge3"), py::arg("edge4"));
	cls_SMDS_FaceOfEdges.def("Print", (void (SMDS_FaceOfEdges::*)(std::ostream &) const ) &SMDS_FaceOfEdges::Print, "None", py::arg("OS"));
	cls_SMDS_FaceOfEdges.def("GetType", (SMDSAbs_ElementType (SMDS_FaceOfEdges::*)() const ) &SMDS_FaceOfEdges::GetType, "None");
	cls_SMDS_FaceOfEdges.def("GetEntityType", (SMDSAbs_EntityType (SMDS_FaceOfEdges::*)() const ) &SMDS_FaceOfEdges::GetEntityType, "None");
	cls_SMDS_FaceOfEdges.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_FaceOfEdges::*)() const ) &SMDS_FaceOfEdges::GetGeomType, "None");
	// FIXME cls_SMDS_FaceOfEdges.def("ChangeNodes", (bool (SMDS_FaceOfEdges::*)(const SMDS_MeshNode *[], const int)) &SMDS_FaceOfEdges::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_FaceOfEdges.def("NbNodes", (int (SMDS_FaceOfEdges::*)() const ) &SMDS_FaceOfEdges::NbNodes, "None");
	cls_SMDS_FaceOfEdges.def("NbEdges", (int (SMDS_FaceOfEdges::*)() const ) &SMDS_FaceOfEdges::NbEdges, "None");
	cls_SMDS_FaceOfEdges.def("NbFaces", (int (SMDS_FaceOfEdges::*)() const ) &SMDS_FaceOfEdges::NbFaces, "None");
	cls_SMDS_FaceOfEdges.def("GetNode", (const SMDS_MeshNode * (SMDS_FaceOfEdges::*)(const int) const ) &SMDS_FaceOfEdges::GetNode, "None", py::arg("ind"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_FaceOfNodes.hxx
	py::class_<SMDS_FaceOfNodes, std::unique_ptr<SMDS_FaceOfNodes, py::nodelete>, SMDS_MeshFace> cls_SMDS_FaceOfNodes(mod, "SMDS_FaceOfNodes", "None");
	cls_SMDS_FaceOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("node1"), py::arg("node2"), py::arg("node3"));
	cls_SMDS_FaceOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("node1"), py::arg("node2"), py::arg("node3"), py::arg("node4"));
	cls_SMDS_FaceOfNodes.def("Print", (void (SMDS_FaceOfNodes::*)(std::ostream &) const ) &SMDS_FaceOfNodes::Print, "None", py::arg("OS"));
	// FIXME cls_SMDS_FaceOfNodes.def("ChangeNodes", (bool (SMDS_FaceOfNodes::*)(const SMDS_MeshNode *[], const int)) &SMDS_FaceOfNodes::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_FaceOfNodes.def("NbEdges", (int (SMDS_FaceOfNodes::*)() const ) &SMDS_FaceOfNodes::NbEdges, "None");
	cls_SMDS_FaceOfNodes.def("NbFaces", (int (SMDS_FaceOfNodes::*)() const ) &SMDS_FaceOfNodes::NbFaces, "None");
	cls_SMDS_FaceOfNodes.def("NbNodes", (int (SMDS_FaceOfNodes::*)() const ) &SMDS_FaceOfNodes::NbNodes, "None");
	cls_SMDS_FaceOfNodes.def("GetNode", (const SMDS_MeshNode * (SMDS_FaceOfNodes::*)(const int) const ) &SMDS_FaceOfNodes::GetNode, "Return node by its index", py::arg("ind"));
	cls_SMDS_FaceOfNodes.def("GetEntityType", (SMDSAbs_EntityType (SMDS_FaceOfNodes::*)() const ) &SMDS_FaceOfNodes::GetEntityType, "None");
	cls_SMDS_FaceOfNodes.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_FaceOfNodes::*)() const ) &SMDS_FaceOfNodes::GetGeomType, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_FacePosition.hxx
	py::class_<SMDS_FacePosition, std::unique_ptr<SMDS_FacePosition, Deleter<SMDS_FacePosition>>, SMDS_Position> cls_SMDS_FacePosition(mod, "SMDS_FacePosition", "None");
	cls_SMDS_FacePosition.def(py::init<>());
	cls_SMDS_FacePosition.def(py::init<double>(), py::arg("aUParam"));
	cls_SMDS_FacePosition.def(py::init<double, double>(), py::arg("aUParam"), py::arg("aVParam"));
	cls_SMDS_FacePosition.def("GetTypeOfPosition", (SMDS_TypeOfPosition (SMDS_FacePosition::*)() const ) &SMDS_FacePosition::GetTypeOfPosition, "None");
	cls_SMDS_FacePosition.def("SetUParameter", (void (SMDS_FacePosition::*)(double)) &SMDS_FacePosition::SetUParameter, "None", py::arg("aUparam"));
	cls_SMDS_FacePosition.def("SetVParameter", (void (SMDS_FacePosition::*)(double)) &SMDS_FacePosition::SetVParameter, "None", py::arg("aVparam"));
	cls_SMDS_FacePosition.def("SetParameters", (void (SMDS_FacePosition::*)(double, double)) &SMDS_FacePosition::SetParameters, "None", py::arg("aUparam"), py::arg("aVparam"));
	cls_SMDS_FacePosition.def("GetUParameter", (double (SMDS_FacePosition::*)() const ) &SMDS_FacePosition::GetUParameter, "None");
	cls_SMDS_FacePosition.def("GetVParameter", (double (SMDS_FacePosition::*)() const ) &SMDS_FacePosition::GetVParameter, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	bind_SMDS_Iterator<const SMDS_MeshElement *>(mod, "SMDS_ElemIterator");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_LinearEdge.hxx
	py::class_<SMDS_LinearEdge, std::unique_ptr<SMDS_LinearEdge, py::nodelete>, SMDS_MeshEdge> cls_SMDS_LinearEdge(mod, "SMDS_LinearEdge", "None");
	cls_SMDS_LinearEdge.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("node1"), py::arg("node2"));
	// FIXME cls_SMDS_LinearEdge.def("ChangeNodes", (bool (SMDS_LinearEdge::*)(const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_LinearEdge::ChangeNodes, "None", py::arg("node1"), py::arg("node2"));
	cls_SMDS_LinearEdge.def("Print", (void (SMDS_LinearEdge::*)(std::ostream &) const ) &SMDS_LinearEdge::Print, "None", py::arg("OS"));
	cls_SMDS_LinearEdge.def("GetEntityType", (SMDSAbs_EntityType (SMDS_LinearEdge::*)() const ) &SMDS_LinearEdge::GetEntityType, "None");
	// FIXME cls_SMDS_LinearEdge.def("ChangeNodes", (bool (SMDS_LinearEdge::*)(const SMDS_MeshNode *[], const int)) &SMDS_LinearEdge::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_LinearEdge.def("NbNodes", (int (SMDS_LinearEdge::*)() const ) &SMDS_LinearEdge::NbNodes, "None");
	cls_SMDS_LinearEdge.def("NbEdges", (int (SMDS_LinearEdge::*)() const ) &SMDS_LinearEdge::NbEdges, "None");
	cls_SMDS_LinearEdge.def("GetNode", (const SMDS_MeshNode * (SMDS_LinearEdge::*)(const int) const ) &SMDS_LinearEdge::GetNode, "Return node by its index", py::arg("ind"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_PolygonalFaceOfNodes.hxx
	py::class_<SMDS_PolygonalFaceOfNodes, std::unique_ptr<SMDS_PolygonalFaceOfNodes, py::nodelete>, SMDS_MeshFace> cls_SMDS_PolygonalFaceOfNodes(mod, "SMDS_PolygonalFaceOfNodes", "None");
	cls_SMDS_PolygonalFaceOfNodes.def(py::init<const std::vector<const SMDS_MeshNode *> &>(), py::arg("nodes"));
	cls_SMDS_PolygonalFaceOfNodes.def("GetType", (SMDSAbs_ElementType (SMDS_PolygonalFaceOfNodes::*)() const ) &SMDS_PolygonalFaceOfNodes::GetType, "None");
	cls_SMDS_PolygonalFaceOfNodes.def("GetEntityType", (SMDSAbs_EntityType (SMDS_PolygonalFaceOfNodes::*)() const ) &SMDS_PolygonalFaceOfNodes::GetEntityType, "None");
	cls_SMDS_PolygonalFaceOfNodes.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_PolygonalFaceOfNodes::*)() const ) &SMDS_PolygonalFaceOfNodes::GetGeomType, "None");
	cls_SMDS_PolygonalFaceOfNodes.def("IsPoly", (bool (SMDS_PolygonalFaceOfNodes::*)() const ) &SMDS_PolygonalFaceOfNodes::IsPoly, "None");
	// FIXME cls_SMDS_PolygonalFaceOfNodes.def("ChangeNodes", (bool (SMDS_PolygonalFaceOfNodes::*)(std::vector<const SMDS_MeshNode *>)) &SMDS_PolygonalFaceOfNodes::ChangeNodes, "None", py::arg("nodes"));
	// FIXME cls_SMDS_PolygonalFaceOfNodes.def("ChangeNodes", (bool (SMDS_PolygonalFaceOfNodes::*)(const SMDS_MeshNode *[], const int)) &SMDS_PolygonalFaceOfNodes::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_PolygonalFaceOfNodes.def("NbNodes", (int (SMDS_PolygonalFaceOfNodes::*)() const ) &SMDS_PolygonalFaceOfNodes::NbNodes, "None");
	cls_SMDS_PolygonalFaceOfNodes.def("NbEdges", (int (SMDS_PolygonalFaceOfNodes::*)() const ) &SMDS_PolygonalFaceOfNodes::NbEdges, "None");
	cls_SMDS_PolygonalFaceOfNodes.def("NbFaces", (int (SMDS_PolygonalFaceOfNodes::*)() const ) &SMDS_PolygonalFaceOfNodes::NbFaces, "None");
	cls_SMDS_PolygonalFaceOfNodes.def("Print", (void (SMDS_PolygonalFaceOfNodes::*)(std::ostream &) const ) &SMDS_PolygonalFaceOfNodes::Print, "None", py::arg("OS"));
	cls_SMDS_PolygonalFaceOfNodes.def("GetNode", (const SMDS_MeshNode * (SMDS_PolygonalFaceOfNodes::*)(const int) const ) &SMDS_PolygonalFaceOfNodes::GetNode, "Return node by its index", py::arg("ind"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_PolyhedralVolumeOfNodes.hxx
	py::class_<SMDS_PolyhedralVolumeOfNodes, std::unique_ptr<SMDS_PolyhedralVolumeOfNodes, py::nodelete>, SMDS_VolumeOfNodes> cls_SMDS_PolyhedralVolumeOfNodes(mod, "SMDS_PolyhedralVolumeOfNodes", "None");
	cls_SMDS_PolyhedralVolumeOfNodes.def(py::init<std::vector<const SMDS_MeshNode *>, std::vector<int>>(), py::arg("nodes"), py::arg("quantities"));
	cls_SMDS_PolyhedralVolumeOfNodes.def("GetType", (SMDSAbs_ElementType (SMDS_PolyhedralVolumeOfNodes::*)() const ) &SMDS_PolyhedralVolumeOfNodes::GetType, "None");
	cls_SMDS_PolyhedralVolumeOfNodes.def("GetEntityType", (SMDSAbs_EntityType (SMDS_PolyhedralVolumeOfNodes::*)() const ) &SMDS_PolyhedralVolumeOfNodes::GetEntityType, "None");
	cls_SMDS_PolyhedralVolumeOfNodes.def("IsPoly", (bool (SMDS_PolyhedralVolumeOfNodes::*)() const ) &SMDS_PolyhedralVolumeOfNodes::IsPoly, "None");
	// FIXME cls_SMDS_PolyhedralVolumeOfNodes.def("ChangeNodes", (bool (SMDS_PolyhedralVolumeOfNodes::*)(const std::vector<const SMDS_MeshNode *> &, const std::vector<int> &)) &SMDS_PolyhedralVolumeOfNodes::ChangeNodes, "None", py::arg("nodes"), py::arg("quantities"));
	cls_SMDS_PolyhedralVolumeOfNodes.def("NbNodes", (int (SMDS_PolyhedralVolumeOfNodes::*)() const ) &SMDS_PolyhedralVolumeOfNodes::NbNodes, "None");
	cls_SMDS_PolyhedralVolumeOfNodes.def("NbEdges", (int (SMDS_PolyhedralVolumeOfNodes::*)() const ) &SMDS_PolyhedralVolumeOfNodes::NbEdges, "None");
	cls_SMDS_PolyhedralVolumeOfNodes.def("NbFaces", (int (SMDS_PolyhedralVolumeOfNodes::*)() const ) &SMDS_PolyhedralVolumeOfNodes::NbFaces, "None");
	cls_SMDS_PolyhedralVolumeOfNodes.def("NbFaceNodes", (int (SMDS_PolyhedralVolumeOfNodes::*)(const int) const ) &SMDS_PolyhedralVolumeOfNodes::NbFaceNodes, "None", py::arg("face_ind"));
	cls_SMDS_PolyhedralVolumeOfNodes.def("GetFaceNode", (const SMDS_MeshNode * (SMDS_PolyhedralVolumeOfNodes::*)(const int, const int) const ) &SMDS_PolyhedralVolumeOfNodes::GetFaceNode, "None", py::arg("face_ind"), py::arg("node_ind"));
	cls_SMDS_PolyhedralVolumeOfNodes.def("GetQuanities", (const std::vector<int> & (SMDS_PolyhedralVolumeOfNodes::*)() const ) &SMDS_PolyhedralVolumeOfNodes::GetQuanities, "None");
	cls_SMDS_PolyhedralVolumeOfNodes.def("Print", (void (SMDS_PolyhedralVolumeOfNodes::*)(std::ostream &) const ) &SMDS_PolyhedralVolumeOfNodes::Print, "None", py::arg("OS"));
	cls_SMDS_PolyhedralVolumeOfNodes.def("GetNode", (const SMDS_MeshNode * (SMDS_PolyhedralVolumeOfNodes::*)(const int) const ) &SMDS_PolyhedralVolumeOfNodes::GetNode, "Return node by its index", py::arg("ind"));
	cls_SMDS_PolyhedralVolumeOfNodes.def("uniqueNodesIterator", (SMDS_ElemIteratorPtr (SMDS_PolyhedralVolumeOfNodes::*)() const ) &SMDS_PolyhedralVolumeOfNodes::uniqueNodesIterator, "Return iterator on unique nodes");
	cls_SMDS_PolyhedralVolumeOfNodes.def("NbUniqueNodes", (int (SMDS_PolyhedralVolumeOfNodes::*)() const ) &SMDS_PolyhedralVolumeOfNodes::NbUniqueNodes, "Return nb of unique nodes");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_QuadraticEdge.hxx
	py::class_<SMDS_QuadraticEdge, std::unique_ptr<SMDS_QuadraticEdge, py::nodelete>, SMDS_LinearEdge> cls_SMDS_QuadraticEdge(mod, "SMDS_QuadraticEdge", "None");
	cls_SMDS_QuadraticEdge.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("node1"), py::arg("node2"), py::arg("node12"));
	// FIXME cls_SMDS_QuadraticEdge.def("ChangeNodes", (bool (SMDS_QuadraticEdge::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMDS_QuadraticEdge::ChangeNodes, "None", py::arg("node1"), py::arg("node2"), py::arg("node12"));
	cls_SMDS_QuadraticEdge.def("Print", (void (SMDS_QuadraticEdge::*)(std::ostream &) const ) &SMDS_QuadraticEdge::Print, "None", py::arg("OS"));
	cls_SMDS_QuadraticEdge.def("NbNodes", (int (SMDS_QuadraticEdge::*)() const ) &SMDS_QuadraticEdge::NbNodes, "None");
	cls_SMDS_QuadraticEdge.def("GetEntityType", (SMDSAbs_EntityType (SMDS_QuadraticEdge::*)() const ) &SMDS_QuadraticEdge::GetEntityType, "None");
	cls_SMDS_QuadraticEdge.def("IsQuadratic", (bool (SMDS_QuadraticEdge::*)() const ) &SMDS_QuadraticEdge::IsQuadratic, "None");
	cls_SMDS_QuadraticEdge.def("IsMediumNode", (bool (SMDS_QuadraticEdge::*)(const SMDS_MeshNode *) const ) &SMDS_QuadraticEdge::IsMediumNode, "None", py::arg("node"));
	cls_SMDS_QuadraticEdge.def("interlacedNodesIterator", (SMDS_NodeIteratorPtr (SMDS_QuadraticEdge::*)() const ) &SMDS_QuadraticEdge::interlacedNodesIterator, "None");

	// Callback for SMDS_QuadraticFaceOfNodes.
	class PyCallback_SMDS_QuadraticFaceOfNodes : public SMDS_QuadraticFaceOfNodes {
	public:
		using SMDS_QuadraticFaceOfNodes::SMDS_QuadraticFaceOfNodes;

		SMDSAbs_GeometryType GetGeomType() const  override { PYBIND11_OVERLOAD_PURE(SMDSAbs_GeometryType, SMDS_QuadraticFaceOfNodes, GetGeomType, ); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_QuadraticFaceOfNodes.hxx
	py::class_<SMDS_QuadraticFaceOfNodes, std::unique_ptr<SMDS_QuadraticFaceOfNodes, py::nodelete>, PyCallback_SMDS_QuadraticFaceOfNodes, SMDS_MeshFace> cls_SMDS_QuadraticFaceOfNodes(mod, "SMDS_QuadraticFaceOfNodes", "None");
	cls_SMDS_QuadraticFaceOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"));
	cls_SMDS_QuadraticFaceOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"));
	cls_SMDS_QuadraticFaceOfNodes.def("GetEntityType", (SMDSAbs_EntityType (SMDS_QuadraticFaceOfNodes::*)() const ) &SMDS_QuadraticFaceOfNodes::GetEntityType, "None");
	cls_SMDS_QuadraticFaceOfNodes.def("IsQuadratic", (bool (SMDS_QuadraticFaceOfNodes::*)() const ) &SMDS_QuadraticFaceOfNodes::IsQuadratic, "None");
	cls_SMDS_QuadraticFaceOfNodes.def("IsMediumNode", (bool (SMDS_QuadraticFaceOfNodes::*)(const SMDS_MeshNode *) const ) &SMDS_QuadraticFaceOfNodes::IsMediumNode, "None", py::arg("node"));
	// FIXME cls_SMDS_QuadraticFaceOfNodes.def("ChangeNodes", (bool (SMDS_QuadraticFaceOfNodes::*)(const SMDS_MeshNode *[], const int)) &SMDS_QuadraticFaceOfNodes::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_QuadraticFaceOfNodes.def("NbNodes", (int (SMDS_QuadraticFaceOfNodes::*)() const ) &SMDS_QuadraticFaceOfNodes::NbNodes, "None");
	cls_SMDS_QuadraticFaceOfNodes.def("NbEdges", (int (SMDS_QuadraticFaceOfNodes::*)() const ) &SMDS_QuadraticFaceOfNodes::NbEdges, "None");
	cls_SMDS_QuadraticFaceOfNodes.def("NbFaces", (int (SMDS_QuadraticFaceOfNodes::*)() const ) &SMDS_QuadraticFaceOfNodes::NbFaces, "None");
	cls_SMDS_QuadraticFaceOfNodes.def("Print", (void (SMDS_QuadraticFaceOfNodes::*)(std::ostream &) const ) &SMDS_QuadraticFaceOfNodes::Print, "None", py::arg("OS"));
	cls_SMDS_QuadraticFaceOfNodes.def("interlacedNodesIterator", (SMDS_NodeIteratorPtr (SMDS_QuadraticFaceOfNodes::*)() const ) &SMDS_QuadraticFaceOfNodes::interlacedNodesIterator, "None");
	cls_SMDS_QuadraticFaceOfNodes.def("GetNode", (const SMDS_MeshNode * (SMDS_QuadraticFaceOfNodes::*)(const int) const ) &SMDS_QuadraticFaceOfNodes::GetNode, "Return node by its index", py::arg("ind"));

	// Callback for SMDS_QuadraticVolumeOfNodes.
	class PyCallback_SMDS_QuadraticVolumeOfNodes : public SMDS_QuadraticVolumeOfNodes {
	public:
		using SMDS_QuadraticVolumeOfNodes::SMDS_QuadraticVolumeOfNodes;

		SMDSAbs_GeometryType GetGeomType() const  override { PYBIND11_OVERLOAD_PURE(SMDSAbs_GeometryType, SMDS_QuadraticVolumeOfNodes, GetGeomType, ); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_QuadraticVolumeOfNodes.hxx
	py::class_<SMDS_QuadraticVolumeOfNodes, std::unique_ptr<SMDS_QuadraticVolumeOfNodes, py::nodelete>, PyCallback_SMDS_QuadraticVolumeOfNodes, SMDS_MeshVolume> cls_SMDS_QuadraticVolumeOfNodes(mod, "SMDS_QuadraticVolumeOfNodes", "None");
	cls_SMDS_QuadraticVolumeOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n14"), py::arg("n24"), py::arg("n34"));
	cls_SMDS_QuadraticVolumeOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n15"), py::arg("n25"), py::arg("n35"), py::arg("n45"));
	cls_SMDS_QuadraticVolumeOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("n45"), py::arg("n56"), py::arg("n64"), py::arg("n14"), py::arg("n25"), py::arg("n36"));
	cls_SMDS_QuadraticVolumeOfNodes.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("n56"), py::arg("n67"), py::arg("n78"), py::arg("n85"), py::arg("n15"), py::arg("n26"), py::arg("n37"), py::arg("n48"));
	cls_SMDS_QuadraticVolumeOfNodes.def("GetEntityType", (SMDSAbs_EntityType (SMDS_QuadraticVolumeOfNodes::*)() const ) &SMDS_QuadraticVolumeOfNodes::GetEntityType, "None");
	cls_SMDS_QuadraticVolumeOfNodes.def("IsQuadratic", (bool (SMDS_QuadraticVolumeOfNodes::*)() const ) &SMDS_QuadraticVolumeOfNodes::IsQuadratic, "None");
	cls_SMDS_QuadraticVolumeOfNodes.def("IsMediumNode", (bool (SMDS_QuadraticVolumeOfNodes::*)(const SMDS_MeshNode *) const ) &SMDS_QuadraticVolumeOfNodes::IsMediumNode, "None", py::arg("node"));
	// FIXME cls_SMDS_QuadraticVolumeOfNodes.def("ChangeNodes", (bool (SMDS_QuadraticVolumeOfNodes::*)(const SMDS_MeshNode *[], const int)) &SMDS_QuadraticVolumeOfNodes::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_QuadraticVolumeOfNodes.def("NbNodes", (int (SMDS_QuadraticVolumeOfNodes::*)() const ) &SMDS_QuadraticVolumeOfNodes::NbNodes, "None");
	cls_SMDS_QuadraticVolumeOfNodes.def("NbEdges", (int (SMDS_QuadraticVolumeOfNodes::*)() const ) &SMDS_QuadraticVolumeOfNodes::NbEdges, "None");
	cls_SMDS_QuadraticVolumeOfNodes.def("NbFaces", (int (SMDS_QuadraticVolumeOfNodes::*)() const ) &SMDS_QuadraticVolumeOfNodes::NbFaces, "None");
	cls_SMDS_QuadraticVolumeOfNodes.def("Print", (void (SMDS_QuadraticVolumeOfNodes::*)(std::ostream &) const ) &SMDS_QuadraticVolumeOfNodes::Print, "None", py::arg("OS"));
	cls_SMDS_QuadraticVolumeOfNodes.def("GetNode", (const SMDS_MeshNode * (SMDS_QuadraticVolumeOfNodes::*)(const int) const ) &SMDS_QuadraticVolumeOfNodes::GetNode, "Return node by its index", py::arg("ind"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SpacePosition.hxx
	py::class_<SMDS_SpacePosition, std::unique_ptr<SMDS_SpacePosition, Deleter<SMDS_SpacePosition>>, SMDS_Position> cls_SMDS_SpacePosition(mod, "SMDS_SpacePosition", "None");
	cls_SMDS_SpacePosition.def(py::init<>());
	cls_SMDS_SpacePosition.def(py::init<double>(), py::arg("x"));
	cls_SMDS_SpacePosition.def(py::init<double, double>(), py::arg("x"), py::arg("y"));
	cls_SMDS_SpacePosition.def(py::init<double, double, double>(), py::arg("x"), py::arg("y"), py::arg("z"));
	cls_SMDS_SpacePosition.def("GetTypeOfPosition", (SMDS_TypeOfPosition (SMDS_SpacePosition::*)() const ) &SMDS_SpacePosition::GetTypeOfPosition, "None");
	cls_SMDS_SpacePosition.def_static("originSpacePosition_", (SMDS_PositionPtr (*)()) &SMDS_SpacePosition::originSpacePosition, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_VertexPosition.hxx
	py::class_<SMDS_VertexPosition, std::unique_ptr<SMDS_VertexPosition, Deleter<SMDS_VertexPosition>>, SMDS_Position> cls_SMDS_VertexPosition(mod, "SMDS_VertexPosition", "None");
	cls_SMDS_VertexPosition.def(py::init<>());
	cls_SMDS_VertexPosition.def("GetTypeOfPosition", (SMDS_TypeOfPosition (SMDS_VertexPosition::*)() const ) &SMDS_VertexPosition::GetTypeOfPosition, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_VolumeOfFaces.hxx
	py::class_<SMDS_VolumeOfFaces, std::unique_ptr<SMDS_VolumeOfFaces, py::nodelete>, SMDS_MeshVolume> cls_SMDS_VolumeOfFaces(mod, "SMDS_VolumeOfFaces", "None");
	cls_SMDS_VolumeOfFaces.def(py::init<const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *>(), py::arg("face1"), py::arg("face2"), py::arg("face3"), py::arg("face4"));
	cls_SMDS_VolumeOfFaces.def(py::init<const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *>(), py::arg("face1"), py::arg("face2"), py::arg("face3"), py::arg("face4"), py::arg("face5"));
	cls_SMDS_VolumeOfFaces.def(py::init<const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *, const SMDS_MeshFace *>(), py::arg("face1"), py::arg("face2"), py::arg("face3"), py::arg("face4"), py::arg("face5"), py::arg("face6"));
	cls_SMDS_VolumeOfFaces.def("GetEntityType", (SMDSAbs_EntityType (SMDS_VolumeOfFaces::*)() const ) &SMDS_VolumeOfFaces::GetEntityType, "None");
	cls_SMDS_VolumeOfFaces.def("GetGeomType", (SMDSAbs_GeometryType (SMDS_VolumeOfFaces::*)() const ) &SMDS_VolumeOfFaces::GetGeomType, "None");
	// FIXME cls_SMDS_VolumeOfFaces.def("ChangeNodes", (bool (SMDS_VolumeOfFaces::*)(const SMDS_MeshNode *[], const int)) &SMDS_VolumeOfFaces::ChangeNodes, "None", py::arg("nodes"), py::arg("nbNodes"));
	cls_SMDS_VolumeOfFaces.def("Print", (void (SMDS_VolumeOfFaces::*)(std::ostream &) const ) &SMDS_VolumeOfFaces::Print, "None", py::arg("OS"));
	cls_SMDS_VolumeOfFaces.def("NbFaces", (int (SMDS_VolumeOfFaces::*)() const ) &SMDS_VolumeOfFaces::NbFaces, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_VolumeTool.hxx
	py::class_<SMDS_VolumeTool, std::unique_ptr<SMDS_VolumeTool, Deleter<SMDS_VolumeTool>>> cls_SMDS_VolumeTool(mod, "SMDS_VolumeTool", "None");
	cls_SMDS_VolumeTool.def(py::init<>());
	cls_SMDS_VolumeTool.def(py::init<const SMDS_MeshElement *>(), py::arg("theVolume"));
	cls_SMDS_VolumeTool.def(py::init<const SMDS_MeshElement *, const bool>(), py::arg("theVolume"), py::arg("ignoreCentralNodes"));
	cls_SMDS_VolumeTool.def("Set", [](SMDS_VolumeTool &self, const SMDS_MeshElement * a0) -> bool { return self.Set(a0); }, py::arg("theVolume"));
	cls_SMDS_VolumeTool.def("Set", [](SMDS_VolumeTool &self, const SMDS_MeshElement * a0, const bool a1) -> bool { return self.Set(a0, a1); }, py::arg("theVolume"), py::arg("ignoreCentralNodes"));
	cls_SMDS_VolumeTool.def("Set", (bool (SMDS_VolumeTool::*)(const SMDS_MeshElement *, const bool, const std::vector<const SMDS_MeshNode *> *)) &SMDS_VolumeTool::Set, "None", py::arg("theVolume"), py::arg("ignoreCentralNodes"), py::arg("nodes"));
	cls_SMDS_VolumeTool.def("Element", (const SMDS_MeshVolume * (SMDS_VolumeTool::*)() const ) &SMDS_VolumeTool::Element, "None");
	cls_SMDS_VolumeTool.def("ID", (int (SMDS_VolumeTool::*)() const ) &SMDS_VolumeTool::ID, "None");
	cls_SMDS_VolumeTool.def("IsPoly", (bool (SMDS_VolumeTool::*)() const ) &SMDS_VolumeTool::IsPoly, "None");
	cls_SMDS_VolumeTool.def("GetVolumeType", (SMDS_VolumeTool::VolumeType (SMDS_VolumeTool::*)() const ) &SMDS_VolumeTool::GetVolumeType, "None");
	cls_SMDS_VolumeTool.def("IsForward", (bool (SMDS_VolumeTool::*)() const ) &SMDS_VolumeTool::IsForward, "None");
	cls_SMDS_VolumeTool.def("Inverse", (void (SMDS_VolumeTool::*)()) &SMDS_VolumeTool::Inverse, "None");
	// FIXME cls_SMDS_VolumeTool.def("GetNodes", (const SMDS_MeshNode ** (SMDS_VolumeTool::*)() const ) &SMDS_VolumeTool::GetNodes, "None");
	cls_SMDS_VolumeTool.def("NbNodes", (int (SMDS_VolumeTool::*)() const ) &SMDS_VolumeTool::NbNodes, "None");
	cls_SMDS_VolumeTool.def("GetSize", (double (SMDS_VolumeTool::*)() const ) &SMDS_VolumeTool::GetSize, "None");
	cls_SMDS_VolumeTool.def("GetBaryCenter", (bool (SMDS_VolumeTool::*)(double &, double &, double &) const ) &SMDS_VolumeTool::GetBaryCenter, "None", py::arg("X"), py::arg("Y"), py::arg("Z"));
	cls_SMDS_VolumeTool.def("IsOut", (bool (SMDS_VolumeTool::*)(double, double, double, double) const ) &SMDS_VolumeTool::IsOut, "None", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("tol"));
	cls_SMDS_VolumeTool.def("IsLinked", [](SMDS_VolumeTool &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1) -> bool { return self.IsLinked(a0, a1); }, py::arg("theNode1"), py::arg("theNode2"));
	cls_SMDS_VolumeTool.def("IsLinked", (bool (SMDS_VolumeTool::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const bool) const ) &SMDS_VolumeTool::IsLinked, "None", py::arg("theNode1"), py::arg("theNode2"), py::arg("theIgnoreMediumNodes"));
	cls_SMDS_VolumeTool.def("IsLinked", [](SMDS_VolumeTool &self, const int a0, const int a1) -> bool { return self.IsLinked(a0, a1); }, py::arg("theNode1Index"), py::arg("theNode2Index"));
	cls_SMDS_VolumeTool.def("IsLinked", (bool (SMDS_VolumeTool::*)(const int, const int, bool) const ) &SMDS_VolumeTool::IsLinked, "None", py::arg("theNode1Index"), py::arg("theNode2Index"), py::arg("theIgnoreMediumNodes"));
	cls_SMDS_VolumeTool.def("GetNodeIndex", (int (SMDS_VolumeTool::*)(const SMDS_MeshNode *) const ) &SMDS_VolumeTool::GetNodeIndex, "None", py::arg("theNode"));
	cls_SMDS_VolumeTool.def("GetAllExistingEdges", (int (SMDS_VolumeTool::*)(std::vector<const SMDS_MeshElement *> &) const ) &SMDS_VolumeTool::GetAllExistingEdges, "None", py::arg("edges"));
	cls_SMDS_VolumeTool.def("MinLinearSize2", (double (SMDS_VolumeTool::*)() const ) &SMDS_VolumeTool::MinLinearSize2, "None");
	cls_SMDS_VolumeTool.def("MaxLinearSize2", (double (SMDS_VolumeTool::*)() const ) &SMDS_VolumeTool::MaxLinearSize2, "None");
	cls_SMDS_VolumeTool.def("SetExternalNormal", (void (SMDS_VolumeTool::*)()) &SMDS_VolumeTool::SetExternalNormal, "None");
	cls_SMDS_VolumeTool.def("NbFaces", (int (SMDS_VolumeTool::*)() const ) &SMDS_VolumeTool::NbFaces, "None");
	cls_SMDS_VolumeTool.def("NbFaceNodes", (int (SMDS_VolumeTool::*)(int) const ) &SMDS_VolumeTool::NbFaceNodes, "None", py::arg("faceIndex"));
	cls_SMDS_VolumeTool.def("GetFaceNodesIndices", (const int * (SMDS_VolumeTool::*)(int) const ) &SMDS_VolumeTool::GetFaceNodesIndices, "None", py::arg("faceIndex"));
	// FIXME cls_SMDS_VolumeTool.def("GetFaceNodes", (const SMDS_MeshNode ** (SMDS_VolumeTool::*)(int) const ) &SMDS_VolumeTool::GetFaceNodes, "None", py::arg("faceIndex"));
	// FIXME cls_SMDS_VolumeTool.def("GetFaceNodes", (bool (SMDS_VolumeTool::*)(int, std::set<const SMDS_MeshNode *> &) const ) &SMDS_VolumeTool::GetFaceNodes, "None", py::arg("faceIndex"), py::arg("theFaceNodes"));
	cls_SMDS_VolumeTool.def("IsFaceExternal", (bool (SMDS_VolumeTool::*)(int) const ) &SMDS_VolumeTool::IsFaceExternal, "None", py::arg("faceIndex"));
	cls_SMDS_VolumeTool.def("IsFreeFace", [](SMDS_VolumeTool &self, int a0) -> bool { return self.IsFreeFace(a0); }, py::arg("faceIndex"));
	// FIXME cls_SMDS_VolumeTool.def("IsFreeFace", (bool (SMDS_VolumeTool::*)(int, const SMDS_MeshElement **) const ) &SMDS_VolumeTool::IsFreeFace, "None", py::arg("faceIndex"), py::arg("otherVol"));
	cls_SMDS_VolumeTool.def("IsFreeFaceAdv", [](SMDS_VolumeTool &self, int a0) -> bool { return self.IsFreeFaceAdv(a0); }, py::arg("faceIndex"));
	// FIXME cls_SMDS_VolumeTool.def("IsFreeFaceAdv", (bool (SMDS_VolumeTool::*)(int, const SMDS_MeshElement **) const ) &SMDS_VolumeTool::IsFreeFaceAdv, "None", py::arg("faceIndex"), py::arg("otherVol"));
	cls_SMDS_VolumeTool.def("GetFaceNormal", (bool (SMDS_VolumeTool::*)(int, double &, double &, double &) const ) &SMDS_VolumeTool::GetFaceNormal, "None", py::arg("faceIndex"), py::arg("X"), py::arg("Y"), py::arg("Z"));
	cls_SMDS_VolumeTool.def("GetFaceBaryCenter", (bool (SMDS_VolumeTool::*)(int, double &, double &, double &) const ) &SMDS_VolumeTool::GetFaceBaryCenter, "None", py::arg("faceIndex"), py::arg("X"), py::arg("Y"), py::arg("Z"));
	cls_SMDS_VolumeTool.def("GetFaceArea", (double (SMDS_VolumeTool::*)(int) const ) &SMDS_VolumeTool::GetFaceArea, "None", py::arg("faceIndex"));
	cls_SMDS_VolumeTool.def("GetOppFaceIndex", (int (SMDS_VolumeTool::*)(int) const ) &SMDS_VolumeTool::GetOppFaceIndex, "None", py::arg("faceIndex"));
	cls_SMDS_VolumeTool.def("GetCenterNodeIndex", (int (SMDS_VolumeTool::*)(int) const ) &SMDS_VolumeTool::GetCenterNodeIndex, "None", py::arg("faceIndex"));
	cls_SMDS_VolumeTool.def("GetFaceIndex", [](SMDS_VolumeTool &self, const std::set<const SMDS_MeshNode *> & a0) -> int { return self.GetFaceIndex(a0); }, py::arg("theFaceNodes"));
	cls_SMDS_VolumeTool.def("GetFaceIndex", (int (SMDS_VolumeTool::*)(const std::set<const SMDS_MeshNode *> &, const int) const ) &SMDS_VolumeTool::GetFaceIndex, "None", py::arg("theFaceNodes"), py::arg("theFaceIndexHint"));
	cls_SMDS_VolumeTool.def("GetAllExistingFaces", (int (SMDS_VolumeTool::*)(std::vector<const SMDS_MeshElement *> &) const ) &SMDS_VolumeTool::GetAllExistingFaces, "None", py::arg("faces"));
	cls_SMDS_VolumeTool.def_static("GetType_", (SMDS_VolumeTool::VolumeType (*)(int)) &SMDS_VolumeTool::GetType, "None", py::arg("nbNodes"));
	cls_SMDS_VolumeTool.def_static("NbFaces_", (int (*)(SMDS_VolumeTool::VolumeType)) &SMDS_VolumeTool::NbFaces, "None", py::arg("type"));
	cls_SMDS_VolumeTool.def_static("GetFaceNodesIndices_", (const int * (*)(SMDS_VolumeTool::VolumeType, int, bool)) &SMDS_VolumeTool::GetFaceNodesIndices, "None", py::arg("type"), py::arg("faceIndex"), py::arg("external"));
	cls_SMDS_VolumeTool.def_static("NbFaceNodes_", (int (*)(SMDS_VolumeTool::VolumeType, int)) &SMDS_VolumeTool::NbFaceNodes, "None", py::arg("type"), py::arg("faceIndex"));
	cls_SMDS_VolumeTool.def_static("NbCornerNodes_", (int (*)(SMDS_VolumeTool::VolumeType)) &SMDS_VolumeTool::NbCornerNodes, "None", py::arg("type"));
	cls_SMDS_VolumeTool.def_static("GetOppFaceIndexOfHex_", (int (*)(int)) &SMDS_VolumeTool::GetOppFaceIndexOfHex, "None", py::arg("faceIndex"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_VolumeTool.hxx
	py::enum_<SMDS_VolumeTool::VolumeType>(cls_SMDS_VolumeTool, "VolumeType", "None")
		.value("UNKNOWN", SMDS_VolumeTool::VolumeType::UNKNOWN)
		.value("TETRA", SMDS_VolumeTool::VolumeType::TETRA)
		.value("PYRAM", SMDS_VolumeTool::VolumeType::PYRAM)
		.value("PENTA", SMDS_VolumeTool::VolumeType::PENTA)
		.value("HEXA", SMDS_VolumeTool::VolumeType::HEXA)
		.value("HEX_PRISM", SMDS_VolumeTool::VolumeType::HEX_PRISM)
		.value("QUAD_TETRA", SMDS_VolumeTool::VolumeType::QUAD_TETRA)
		.value("QUAD_PYRAM", SMDS_VolumeTool::VolumeType::QUAD_PYRAM)
		.value("QUAD_PENTA", SMDS_VolumeTool::VolumeType::QUAD_PENTA)
		.value("QUAD_HEXA", SMDS_VolumeTool::VolumeType::QUAD_HEXA)
		.value("POLYHEDA", SMDS_VolumeTool::VolumeType::POLYHEDA)
		.value("NB_VOLUME_TYPES", SMDS_VolumeTool::VolumeType::NB_VOLUME_TYPES)
		.export_values();

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_VtkCellIterator.hxx
	/*
	py::class_<SMDS_VtkCellIterator, std::unique_ptr<SMDS_VtkCellIterator, Deleter<SMDS_VtkCellIterator>>, SMDS_ElemIterator> cls_SMDS_VtkCellIterator(mod, "SMDS_VtkCellIterator", "None");
	cls_SMDS_VtkCellIterator.def(py::init<SMDS_Mesh *, int, SMDSAbs_EntityType>(), py::arg("mesh"), py::arg("vtkCellId"), py::arg("aType"));
	cls_SMDS_VtkCellIterator.def("more", (bool (SMDS_VtkCellIterator::*)()) &SMDS_VtkCellIterator::more, "None");
	cls_SMDS_VtkCellIterator.def("next", (const SMDS_MeshElement * (SMDS_VtkCellIterator::*)()) &SMDS_VtkCellIterator::next, "None");
	cls_SMDS_VtkCellIterator.def("exchange", (void (SMDS_VtkCellIterator::*)(vtkIdType, vtkIdType)) &SMDS_VtkCellIterator::exchange, "None", py::arg("a"), py::arg("b"));
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	bind_SMDS_Iterator<const SMDS_MeshNode *>(mod, "SMDS_NodeIterator");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_VtkCellIterator.hxx
	/*
	py::class_<SMDS_VtkCellIteratorPolyH, std::unique_ptr<SMDS_VtkCellIteratorPolyH, Deleter<SMDS_VtkCellIteratorPolyH>>, SMDS_VtkCellIterator> cls_SMDS_VtkCellIteratorPolyH(mod, "SMDS_VtkCellIteratorPolyH", "None");
	cls_SMDS_VtkCellIteratorPolyH.def(py::init<SMDS_Mesh *, int, SMDSAbs_EntityType>(), py::arg("mesh"), py::arg("vtkCellId"), py::arg("aType"));
	cls_SMDS_VtkCellIteratorPolyH.def("more", (bool (SMDS_VtkCellIteratorPolyH::*)()) &SMDS_VtkCellIteratorPolyH::more, "None");
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_IteratorOfElements.hxx
	py::class_<SMDS_IteratorOfElements, boost::shared_ptr<SMDS_IteratorOfElements>, SMDS_ElemIterator> cls_SMDS_IteratorOfElements(mod, "SMDS_IteratorOfElements", "None");
	cls_SMDS_IteratorOfElements.def(py::init<const SMDS_MeshElement *, SMDSAbs_ElementType, const SMDS_ElemIteratorPtr &>(), py::arg("element"), py::arg("type"), py::arg("it"));
	cls_SMDS_IteratorOfElements.def("more", (bool (SMDS_IteratorOfElements::*)()) &SMDS_IteratorOfElements::more, "None");
	cls_SMDS_IteratorOfElements.def("next", (const SMDS_MeshElement * (SMDS_IteratorOfElements::*)()) &SMDS_IteratorOfElements::next, "None");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	// FIXME bind_boost::shared_ptr<SMDS_Iterator<const SMDS_MeshElement *> >(mod, "SMDS_ElemIteratorPtr");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_VtkCellIterator.hxx
	/*
	py::class_<SMDS_VtkCellIteratorToUNV, std::unique_ptr<SMDS_VtkCellIteratorToUNV, Deleter<SMDS_VtkCellIteratorToUNV>>, SMDS_NodeIterator> cls_SMDS_VtkCellIteratorToUNV(mod, "SMDS_VtkCellIteratorToUNV", "None");
	cls_SMDS_VtkCellIteratorToUNV.def(py::init<SMDS_Mesh *, int, SMDSAbs_EntityType>(), py::arg("mesh"), py::arg("vtkCellId"), py::arg("aType"));
	cls_SMDS_VtkCellIteratorToUNV.def("next", (const SMDS_MeshNode * (SMDS_VtkCellIteratorToUNV::*)()) &SMDS_VtkCellIteratorToUNV::next, "None");
	cls_SMDS_VtkCellIteratorToUNV.def("more", (bool (SMDS_VtkCellIteratorToUNV::*)()) &SMDS_VtkCellIteratorToUNV::more, "None");
	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	// FIXME bind_boost::shared_ptr<SMDS_Iterator<const SMDS_MeshNode *> >(mod, "SMDS_NodeIteratorPtr");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	bind_SMDS_Iterator<const SMDS_Mesh0DElement *>(mod, "SMDS_0DElementIterator");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	// FIXME bind_boost::shared_ptr<SMDS_Iterator<const SMDS_Mesh0DElement *> >(mod, "SMDS_0DElementIteratorPtr");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	bind_SMDS_Iterator<const SMDS_MeshEdge *>(mod, "SMDS_EdgeIterator");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	// FIXME bind_boost::shared_ptr<SMDS_Iterator<const SMDS_MeshEdge *> >(mod, "SMDS_EdgeIteratorPtr");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	bind_SMDS_Iterator<const SMDS_MeshFace *>(mod, "SMDS_FaceIterator");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	// FIXME bind_boost::shared_ptr<SMDS_Iterator<const SMDS_MeshFace *> >(mod, "SMDS_FaceIteratorPtr");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	bind_SMDS_Iterator<const SMDS_MeshVolume *>(mod, "SMDS_VolumeIterator");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_ElemIterator.hxx
	// FIXME bind_boost::shared_ptr<SMDS_Iterator<const SMDS_MeshVolume *> >(mod, "SMDS_VolumeIteratorPtr");

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshElement.hxx
	other_mod = py::module::import("OCCT.AdvApp2Var");
	if (py::hasattr(other_mod, "shortint")) {
		mod.attr("ShortType") = other_mod.attr("shortint");
	}

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_MeshElement.hxx
	other_mod = py::module::import("OCCT.AdvApp2Var");
	if (py::hasattr(other_mod, "integer")) {
		mod.attr("LongType") = other_mod.attr("integer");
	}

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Position.hxx
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Downward.hxx
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	bind_SMDS_SetIterator<const SMDS_MeshElement *, std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<const SMDS_MeshElement *> > >, SMDS::SimpleAccessor<const SMDS_MeshElement *, std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<const SMDS_MeshElement *> > > >, SMDS::PassAllValueFilter<const SMDS_MeshElement *> >(mod, "SMDS_ElementVectorIterator");

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	bind_SMDS_SetIterator<const SMDS_MeshElement *, const SMDS_MeshElement *const *, SMDS::SimpleAccessor<const SMDS_MeshElement *, const SMDS_MeshElement *const *>, SMDS::PassAllValueFilter<const SMDS_MeshElement *> >(mod, "SMDS_ElementArrayIterator");

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	bind_SMDS_SetIterator<const SMDS_MeshElement *, std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<const SMDS_MeshNode *> > >, SMDS::SimpleAccessor<const SMDS_MeshElement *, std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<const SMDS_MeshNode *> > > >, SMDS::PassAllValueFilter<const SMDS_MeshElement *> >(mod, "SMDS_NodeVectorElemIterator");

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	bind_SMDS_SetIterator<const SMDS_MeshElement *, const SMDS_MeshNode *const *, SMDS::SimpleAccessor<const SMDS_MeshElement *, const SMDS_MeshNode *const *>, SMDS::PassAllValueFilter<const SMDS_MeshElement *> >(mod, "SMDS_NodeArrayElemIterator");

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	bind_SMDS_SetIterator<const SMDS_MeshNode *, std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<const SMDS_MeshNode *> > >, SMDS::SimpleAccessor<const SMDS_MeshNode *, std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<const SMDS_MeshNode *> > > >, SMDS::PassAllValueFilter<const SMDS_MeshNode *> >(mod, "SMDS_NodeVectorIterator");

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	bind_SMDS_SetIterator<const SMDS_MeshNode *, const SMDS_MeshNode *const *, SMDS::SimpleAccessor<const SMDS_MeshNode *, const SMDS_MeshNode *const *>, SMDS::PassAllValueFilter<const SMDS_MeshNode *> >(mod, "SMDS_NodeArrayIterator");

	*/

	// List of nodes
	bind_list<const SMDS_MeshNode*>(mod, "SMDS_ListOfNodes");

	// List of elements
	bind_list<const SMDS_MeshElement*>(mod, "SMDS_ListOfElements");

}
