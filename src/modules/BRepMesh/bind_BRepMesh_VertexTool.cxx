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
#include <Standard_Handle.hxx>
#include <NCollection_IncAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <BRepMesh_Vertex.hxx>
#include <BRepMesh.hxx>
#include <Standard_OStream.hxx>
#include <gp_XY.hxx>
#include <BRepMesh_VertexInspector.hxx>
#include <BRepMesh_VertexTool.hxx>

void bind_BRepMesh_VertexTool(py::module &mod){

py::class_<BRepMesh_VertexTool, std::unique_ptr<BRepMesh_VertexTool>> cls_BRepMesh_VertexTool(mod, "BRepMesh_VertexTool", "Describes data structure intended to keep mesh nodes defined in UV space and implements functionality providing their uniqueness regarding thir position.");

// Constructors
cls_BRepMesh_VertexTool.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BRepMesh_VertexTool.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_VertexTool::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_VertexTool.def_static("operator delete_", (void (*)(void *)) &BRepMesh_VertexTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_VertexTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_VertexTool::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_VertexTool.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_VertexTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_VertexTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_VertexTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_VertexTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_VertexTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_VertexTool.def("SetCellSize", (void (BRepMesh_VertexTool::*)(const Standard_Real)) &BRepMesh_VertexTool::SetCellSize, "Sets new size of cell for cellfilter equal in both directions.", py::arg("theSize"));
cls_BRepMesh_VertexTool.def("SetCellSize", (void (BRepMesh_VertexTool::*)(const Standard_Real, const Standard_Real)) &BRepMesh_VertexTool::SetCellSize, "Sets new size of cell for cellfilter.", py::arg("theSizeX"), py::arg("theSizeY"));
cls_BRepMesh_VertexTool.def("SetTolerance", (void (BRepMesh_VertexTool::*)(const Standard_Real)) &BRepMesh_VertexTool::SetTolerance, "Sets the tolerance to be used for identification of coincident vertices equal for both dimensions.", py::arg("theTolerance"));
cls_BRepMesh_VertexTool.def("SetTolerance", (void (BRepMesh_VertexTool::*)(const Standard_Real, const Standard_Real)) &BRepMesh_VertexTool::SetTolerance, "Sets the tolerance to be used for identification of coincident vertices.", py::arg("theToleranceX"), py::arg("theToleranceY"));
cls_BRepMesh_VertexTool.def("GetTolerance", [](BRepMesh_VertexTool &self, Standard_Real & theToleranceX, Standard_Real & theToleranceY){ self.GetTolerance(theToleranceX, theToleranceY); return std::tuple<Standard_Real &, Standard_Real &>(theToleranceX, theToleranceY); }, "Gets the tolerance to be used for identification of coincident vertices.", py::arg("theToleranceX"), py::arg("theToleranceY"));
cls_BRepMesh_VertexTool.def("Add", (Standard_Integer (BRepMesh_VertexTool::*)(const BRepMesh_Vertex &, const Standard_Boolean)) &BRepMesh_VertexTool::Add, "Adds vertex with empty data to the tool.", py::arg("theVertex"), py::arg("isForceAdd"));
cls_BRepMesh_VertexTool.def("Delete", (void (BRepMesh_VertexTool::*)(const Standard_Integer)) &BRepMesh_VertexTool::Delete, "Deletes vertex with the given index from the tool.", py::arg("theIndex"));
cls_BRepMesh_VertexTool.def("Vertices", (const BRepMesh::HVectorOfVertex & (BRepMesh_VertexTool::*)() const) &BRepMesh_VertexTool::Vertices, "Returns set of mesh vertices.");
cls_BRepMesh_VertexTool.def("ChangeVertices", (BRepMesh::HVectorOfVertex & (BRepMesh_VertexTool::*)()) &BRepMesh_VertexTool::ChangeVertices, "Returns set of mesh vertices.");
cls_BRepMesh_VertexTool.def("FindKey", (const BRepMesh_Vertex & (BRepMesh_VertexTool::*)(const Standard_Integer)) &BRepMesh_VertexTool::FindKey, "Returns vertex by the given index.", py::arg("theIndex"));
cls_BRepMesh_VertexTool.def("FindIndex", (Standard_Integer (BRepMesh_VertexTool::*)(const BRepMesh_Vertex &)) &BRepMesh_VertexTool::FindIndex, "Returns index of the given vertex.", py::arg("theVertex"));
cls_BRepMesh_VertexTool.def("Extent", (Standard_Integer (BRepMesh_VertexTool::*)() const) &BRepMesh_VertexTool::Extent, "Returns a number of vertices.");
cls_BRepMesh_VertexTool.def("IsEmpty", (Standard_Boolean (BRepMesh_VertexTool::*)() const) &BRepMesh_VertexTool::IsEmpty, "Returns True when the map contains no keys.");
cls_BRepMesh_VertexTool.def("Substitute", (void (BRepMesh_VertexTool::*)(const Standard_Integer, const BRepMesh_Vertex &)) &BRepMesh_VertexTool::Substitute, "Substitutes vertex with the given by the given vertex with attributes.", py::arg("theIndex"), py::arg("theVertex"));
cls_BRepMesh_VertexTool.def("RemoveLast", (void (BRepMesh_VertexTool::*)()) &BRepMesh_VertexTool::RemoveLast, "Remove last node from the structure.");
cls_BRepMesh_VertexTool.def("GetListOfDelNodes", (const BRepMesh::ListOfInteger & (BRepMesh_VertexTool::*)() const) &BRepMesh_VertexTool::GetListOfDelNodes, "Returns the list with indexes of vertices that have movability attribute equal to BRepMesh_Deleted and can be replaced with another node.");
cls_BRepMesh_VertexTool.def("Statistics", (void (BRepMesh_VertexTool::*)(Standard_OStream &) const) &BRepMesh_VertexTool::Statistics, "Prints statistics.", py::arg("theStream"));

// Enums

}