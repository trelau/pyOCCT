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
#include <BRepToIGES_BREntity.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <IGESSolid_Loop.hxx>
#include <TopoDS_Wire.hxx>
#include <IGESSolid_Face.hxx>
#include <IGESSolid_Shell.hxx>
#include <TopoDS_Shell.hxx>
#include <IGESSolid_ManifoldSolid.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Compound.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <IGESSolid_EdgeList.hxx>
#include <IGESSolid_VertexList.hxx>
#include <BRepToIGESBRep_Entity.hxx>

void bind_BRepToIGESBRep_Entity(py::module &mod){

py::class_<BRepToIGESBRep_Entity, BRepToIGES_BREntity> cls_BRepToIGESBRep_Entity(mod, "BRepToIGESBRep_Entity", "provides methods to transfer BRep entity from CASCADE to IGESBRep.");

// Constructors
cls_BRepToIGESBRep_Entity.def(py::init<>());

// Fields

// Methods
// cls_BRepToIGESBRep_Entity.def_static("operator new_", (void * (*)(size_t)) &BRepToIGESBRep_Entity::operator new, "None", py::arg("theSize"));
// cls_BRepToIGESBRep_Entity.def_static("operator delete_", (void (*)(void *)) &BRepToIGESBRep_Entity::operator delete, "None", py::arg("theAddress"));
// cls_BRepToIGESBRep_Entity.def_static("operator new[]_", (void * (*)(size_t)) &BRepToIGESBRep_Entity::operator new[], "None", py::arg("theSize"));
// cls_BRepToIGESBRep_Entity.def_static("operator delete[]_", (void (*)(void *)) &BRepToIGESBRep_Entity::operator delete[], "None", py::arg("theAddress"));
// cls_BRepToIGESBRep_Entity.def_static("operator new_", (void * (*)(size_t, void *)) &BRepToIGESBRep_Entity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepToIGESBRep_Entity.def_static("operator delete_", (void (*)(void *, void *)) &BRepToIGESBRep_Entity::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepToIGESBRep_Entity.def("Clear", (void (BRepToIGESBRep_Entity::*)()) &BRepToIGESBRep_Entity::Clear, "Clears the contents of the fields");
cls_BRepToIGESBRep_Entity.def("TransferVertexList", (void (BRepToIGESBRep_Entity::*)()) &BRepToIGESBRep_Entity::TransferVertexList, "Create the VertexList entity");
cls_BRepToIGESBRep_Entity.def("IndexVertex", (Standard_Integer (BRepToIGESBRep_Entity::*)(const TopoDS_Vertex &) const) &BRepToIGESBRep_Entity::IndexVertex, "Returns the index of <myvertex> in 'myVertices'", py::arg("myvertex"));
cls_BRepToIGESBRep_Entity.def("AddVertex", (Standard_Integer (BRepToIGESBRep_Entity::*)(const TopoDS_Vertex &)) &BRepToIGESBRep_Entity::AddVertex, "Stores <myvertex> in 'myVertices' Returns the index of <myvertex>.", py::arg("myvertex"));
cls_BRepToIGESBRep_Entity.def("TransferEdgeList", (void (BRepToIGESBRep_Entity::*)()) &BRepToIGESBRep_Entity::TransferEdgeList, "Transfert an Edge entity from TopoDS to IGES");
cls_BRepToIGESBRep_Entity.def("IndexEdge", (Standard_Integer (BRepToIGESBRep_Entity::*)(const TopoDS_Edge &) const) &BRepToIGESBRep_Entity::IndexEdge, "Returns the index of <myedge> in 'myEdges'", py::arg("myedge"));
cls_BRepToIGESBRep_Entity.def("AddEdge", (Standard_Integer (BRepToIGESBRep_Entity::*)(const TopoDS_Edge &, const opencascade::handle<IGESData_IGESEntity> &)) &BRepToIGESBRep_Entity::AddEdge, "Stores <myedge> in 'myEdges' and <mycurve3d> in 'myCurves'. Returns the index of <myedge>.", py::arg("myedge"), py::arg("mycurve3d"));
cls_BRepToIGESBRep_Entity.def("TransferShape", (opencascade::handle<IGESData_IGESEntity> (BRepToIGESBRep_Entity::*)(const TopoDS_Shape &)) &BRepToIGESBRep_Entity::TransferShape, "Returns the result of the transfert of any Shape If the transfer has failed, this member return a NullEntity.", py::arg("start"));
cls_BRepToIGESBRep_Entity.def("TransferEdge", (opencascade::handle<IGESData_IGESEntity> (BRepToIGESBRep_Entity::*)(const TopoDS_Edge &)) &BRepToIGESBRep_Entity::TransferEdge, "Transfert an Edge entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("myedge"));
cls_BRepToIGESBRep_Entity.def("TransferEdge", (opencascade::handle<IGESData_IGESEntity> (BRepToIGESBRep_Entity::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real)) &BRepToIGESBRep_Entity::TransferEdge, "Transfert an Edge entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("myedge"), py::arg("myface"), py::arg("length"));
cls_BRepToIGESBRep_Entity.def("TransferWire", (opencascade::handle<IGESSolid_Loop> (BRepToIGESBRep_Entity::*)(const TopoDS_Wire &, const TopoDS_Face &, const Standard_Real)) &BRepToIGESBRep_Entity::TransferWire, "Transfert a Wire entity from TopoDS to IGES. Returns the curve associated to mywire in the parametric space of myface. If this Entity could not be converted, this member returns a NullEntity.", py::arg("mywire"), py::arg("myface"), py::arg("length"));
cls_BRepToIGESBRep_Entity.def("TransferFace", (opencascade::handle<IGESSolid_Face> (BRepToIGESBRep_Entity::*)(const TopoDS_Face &)) &BRepToIGESBRep_Entity::TransferFace, "Transfert a Face entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_BRepToIGESBRep_Entity.def("TransferShell", (opencascade::handle<IGESSolid_Shell> (BRepToIGESBRep_Entity::*)(const TopoDS_Shell &)) &BRepToIGESBRep_Entity::TransferShell, "Transfert an Shell entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_BRepToIGESBRep_Entity.def("TransferSolid", (opencascade::handle<IGESSolid_ManifoldSolid> (BRepToIGESBRep_Entity::*)(const TopoDS_Solid &)) &BRepToIGESBRep_Entity::TransferSolid, "Transfert a Solid entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_BRepToIGESBRep_Entity.def("TransferCompSolid", (opencascade::handle<IGESData_IGESEntity> (BRepToIGESBRep_Entity::*)(const TopoDS_CompSolid &)) &BRepToIGESBRep_Entity::TransferCompSolid, "Transfert an CompSolid entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_BRepToIGESBRep_Entity.def("TransferCompound", (opencascade::handle<IGESData_IGESEntity> (BRepToIGESBRep_Entity::*)(const TopoDS_Compound &)) &BRepToIGESBRep_Entity::TransferCompound, "Transfert a Compound entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));

// Enums

}