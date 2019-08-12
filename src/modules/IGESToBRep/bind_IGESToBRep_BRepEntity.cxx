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
#include <IGESToBRep_CurveAndSurface.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <TopoDS_Vertex.hxx>
#include <IGESSolid_VertexList.hxx>
#include <IGESSolid_EdgeList.hxx>
#include <IGESSolid_Loop.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Trsf2d.hxx>
#include <IGESSolid_Face.hxx>
#include <IGESSolid_Shell.hxx>
#include <IGESSolid_ManifoldSolid.hxx>
#include <IGESToBRep_BRepEntity.hxx>

void bind_IGESToBRep_BRepEntity(py::module &mod){

py::class_<IGESToBRep_BRepEntity, std::unique_ptr<IGESToBRep_BRepEntity, Deleter<IGESToBRep_BRepEntity>>, IGESToBRep_CurveAndSurface> cls_IGESToBRep_BRepEntity(mod, "IGESToBRep_BRepEntity", "Provides methods to transfer BRep entities ( VertexList 502, EdgeList 504, Loop 508, Face 510, Shell 514, ManifoldSolid 186) from IGES to CASCADE.");

// Constructors
cls_IGESToBRep_BRepEntity.def(py::init<>());
cls_IGESToBRep_BRepEntity.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
cls_IGESToBRep_BRepEntity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));

// Fields

// Methods
// cls_IGESToBRep_BRepEntity.def_static("operator new_", (void * (*)(size_t)) &IGESToBRep_BRepEntity::operator new, "None", py::arg("theSize"));
// cls_IGESToBRep_BRepEntity.def_static("operator delete_", (void (*)(void *)) &IGESToBRep_BRepEntity::operator delete, "None", py::arg("theAddress"));
// cls_IGESToBRep_BRepEntity.def_static("operator new[]_", (void * (*)(size_t)) &IGESToBRep_BRepEntity::operator new[], "None", py::arg("theSize"));
// cls_IGESToBRep_BRepEntity.def_static("operator delete[]_", (void (*)(void *)) &IGESToBRep_BRepEntity::operator delete[], "None", py::arg("theAddress"));
// cls_IGESToBRep_BRepEntity.def_static("operator new_", (void * (*)(size_t, void *)) &IGESToBRep_BRepEntity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESToBRep_BRepEntity.def_static("operator delete_", (void (*)(void *, void *)) &IGESToBRep_BRepEntity::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESToBRep_BRepEntity.def("TransferBRepEntity", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_BRepEntity::TransferBRepEntity, "Transfer the BRepEntity' : Face, Shell or ManifoldSolid.", py::arg("start"));
cls_IGESToBRep_BRepEntity.def("TransferVertex", (TopoDS_Vertex (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_VertexList> &, const Standard_Integer)) &IGESToBRep_BRepEntity::TransferVertex, "Transfer the entity number 'index' of the VertexList 'start'", py::arg("start"), py::arg("index"));
cls_IGESToBRep_BRepEntity.def("TransferEdge", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_EdgeList> &, const Standard_Integer)) &IGESToBRep_BRepEntity::TransferEdge, "Transfer the entity number 'index' of the EdgeList 'start'.", py::arg("start"), py::arg("index"));
cls_IGESToBRep_BRepEntity.def("TransferLoop", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_Loop> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_BRepEntity::TransferLoop, "Transfer the Loop Entity", py::arg("start"), py::arg("Face"), py::arg("trans"), py::arg("uFact"));
cls_IGESToBRep_BRepEntity.def("TransferFace", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_Face> &)) &IGESToBRep_BRepEntity::TransferFace, "Transfer the Face Entity", py::arg("start"));
cls_IGESToBRep_BRepEntity.def("TransferShell", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_Shell> &)) &IGESToBRep_BRepEntity::TransferShell, "Transfer the Shell Entity", py::arg("start"));
cls_IGESToBRep_BRepEntity.def("TransferManifoldSolid", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_ManifoldSolid> &)) &IGESToBRep_BRepEntity::TransferManifoldSolid, "Transfer the ManifoldSolid Entity", py::arg("start"));

// Enums

}