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
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <NCollection_CellFilter.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_IncAllocator.hxx>
#include <BRepMesh.hxx>
#include <Precision.hxx>
#include <BRepMesh_Vertex.hxx>
#include <BRepMesh_VertexInspector.hxx>

void bind_BRepMesh_VertexInspector(py::module &mod){

py::class_<BRepMesh_VertexInspector, std::unique_ptr<BRepMesh_VertexInspector, Deleter<BRepMesh_VertexInspector>>, NCollection_CellFilter_InspectorXY> cls_BRepMesh_VertexInspector(mod, "BRepMesh_VertexInspector", "Class intended for fast searching of the coincidence points.");

// Constructors
cls_BRepMesh_VertexInspector.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));

// Fields

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
cls_BRepMesh_VertexInspector.def("GetListOfDelPoints", (const BRepMesh::ListOfInteger & (BRepMesh_VertexInspector::*)() const) &BRepMesh_VertexInspector::GetListOfDelPoints, "Returns list with indexes of vertices that have movability attribute equal to BRepMesh_Deleted and can be replaced with another node.");
cls_BRepMesh_VertexInspector.def("Vertices", (const BRepMesh::HVectorOfVertex & (BRepMesh_VertexInspector::*)() const) &BRepMesh_VertexInspector::Vertices, "Returns set of mesh vertices.");
cls_BRepMesh_VertexInspector.def("ChangeVertices", (BRepMesh::HVectorOfVertex & (BRepMesh_VertexInspector::*)()) &BRepMesh_VertexInspector::ChangeVertices, "Returns set of mesh vertices for modification.");
cls_BRepMesh_VertexInspector.def("Inspect", (NCollection_CellFilter_Action (BRepMesh_VertexInspector::*)(const Standard_Integer)) &BRepMesh_VertexInspector::Inspect, "Performs inspection of a point with the given index.", py::arg("theTargetIndex"));
cls_BRepMesh_VertexInspector.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_Integer, const Standard_Integer)) &BRepMesh_VertexInspector::IsEqual, "Checks indices for equlity.", py::arg("theIndex"), py::arg("theTargetIndex"));

// Enums

}