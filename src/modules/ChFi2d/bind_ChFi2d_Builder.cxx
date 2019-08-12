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
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <ChFi2d_ConstructionError.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <ChFi2d_Builder.hxx>

void bind_ChFi2d_Builder(py::module &mod){

py::class_<ChFi2d_Builder, std::unique_ptr<ChFi2d_Builder, Deleter<ChFi2d_Builder>>> cls_ChFi2d_Builder(mod, "ChFi2d_Builder", "This class contains the algorithm used to build fillet on planar wire.");

// Constructors
cls_ChFi2d_Builder.def(py::init<>());
cls_ChFi2d_Builder.def(py::init<const TopoDS_Face &>(), py::arg("F"));

// Fields

// Methods
// cls_ChFi2d_Builder.def_static("operator new_", (void * (*)(size_t)) &ChFi2d_Builder::operator new, "None", py::arg("theSize"));
// cls_ChFi2d_Builder.def_static("operator delete_", (void (*)(void *)) &ChFi2d_Builder::operator delete, "None", py::arg("theAddress"));
// cls_ChFi2d_Builder.def_static("operator new[]_", (void * (*)(size_t)) &ChFi2d_Builder::operator new[], "None", py::arg("theSize"));
// cls_ChFi2d_Builder.def_static("operator delete[]_", (void (*)(void *)) &ChFi2d_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_ChFi2d_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &ChFi2d_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFi2d_Builder.def_static("operator delete_", (void (*)(void *, void *)) &ChFi2d_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFi2d_Builder.def("Init", (void (ChFi2d_Builder::*)(const TopoDS_Face &)) &ChFi2d_Builder::Init, "None", py::arg("F"));
cls_ChFi2d_Builder.def("Init", (void (ChFi2d_Builder::*)(const TopoDS_Face &, const TopoDS_Face &)) &ChFi2d_Builder::Init, "None", py::arg("RefFace"), py::arg("ModFace"));
cls_ChFi2d_Builder.def("AddFillet", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Vertex &, const Standard_Real)) &ChFi2d_Builder::AddFillet, "Add a fillet of radius <Radius> on the wire between the two edges connected to the vertex <V>. <AddFillet> returns the fillet edge. The returned edge has sense only if the status <status> is <IsDone>", py::arg("V"), py::arg("Radius"));
cls_ChFi2d_Builder.def("ModifyFillet", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Edge &, const Standard_Real)) &ChFi2d_Builder::ModifyFillet, "modify the fillet radius and return the new fillet edge. this edge has sense only if the status <status> is <IsDone>.", py::arg("Fillet"), py::arg("Radius"));
cls_ChFi2d_Builder.def("RemoveFillet", (TopoDS_Vertex (ChFi2d_Builder::*)(const TopoDS_Edge &)) &ChFi2d_Builder::RemoveFillet, "removes the fillet <Fillet> and returns the vertex connecting the two adjacent edges to this fillet.", py::arg("Fillet"));
cls_ChFi2d_Builder.def("AddChamfer", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &ChFi2d_Builder::AddChamfer, "Add a chamfer on the wire between the two edges connected <E1> and <E2>. <AddChamfer> returns the chamfer edge. This edge has sense only if the status <status> is <IsDone>.", py::arg("E1"), py::arg("E2"), py::arg("D1"), py::arg("D2"));
cls_ChFi2d_Builder.def("AddChamfer", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Edge &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &ChFi2d_Builder::AddChamfer, "Add a chamfer on the wire between the two edges connected to the vertex <V>. The chamfer will make an angle <Ang> with the edge <E>, and one of its extremities will be on <E> at distance <D>. The returned edge has sense only if the status <status> is <IsDone>. Warning: The value of <Ang> must be expressed in Radian.", py::arg("E"), py::arg("V"), py::arg("D"), py::arg("Ang"));
cls_ChFi2d_Builder.def("ModifyChamfer", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &ChFi2d_Builder::ModifyChamfer, "modify the chamfer <Chamfer> and returns the new chamfer edge. This edge as sense only if the status <status> is <IsDone>.", py::arg("Chamfer"), py::arg("E1"), py::arg("E2"), py::arg("D1"), py::arg("D2"));
cls_ChFi2d_Builder.def("ModifyChamfer", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &ChFi2d_Builder::ModifyChamfer, "modify the chamfer <Chamfer> and returns the new chamfer edge. This edge as sense only if the status <status> is <IsDone>. Warning: The value of <Ang> must be expressed in Radian.", py::arg("Chamfer"), py::arg("E"), py::arg("D"), py::arg("Ang"));
cls_ChFi2d_Builder.def("RemoveChamfer", (TopoDS_Vertex (ChFi2d_Builder::*)(const TopoDS_Edge &)) &ChFi2d_Builder::RemoveChamfer, "removes the chamfer <Chamfer> and returns the vertex connecting the two adjacent edges to this chamfer.", py::arg("Chamfer"));
cls_ChFi2d_Builder.def("Result", (TopoDS_Face (ChFi2d_Builder::*)() const) &ChFi2d_Builder::Result, "returns the modified face");
cls_ChFi2d_Builder.def("IsModified", (Standard_Boolean (ChFi2d_Builder::*)(const TopoDS_Edge &) const) &ChFi2d_Builder::IsModified, "None", py::arg("E"));
cls_ChFi2d_Builder.def("FilletEdges", (const TopTools_SequenceOfShape & (ChFi2d_Builder::*)() const) &ChFi2d_Builder::FilletEdges, "returns the list of new edges");
cls_ChFi2d_Builder.def("NbFillet", (Standard_Integer (ChFi2d_Builder::*)() const) &ChFi2d_Builder::NbFillet, "None");
cls_ChFi2d_Builder.def("ChamferEdges", (const TopTools_SequenceOfShape & (ChFi2d_Builder::*)() const) &ChFi2d_Builder::ChamferEdges, "returns the list of new edges");
cls_ChFi2d_Builder.def("NbChamfer", (Standard_Integer (ChFi2d_Builder::*)() const) &ChFi2d_Builder::NbChamfer, "None");
cls_ChFi2d_Builder.def("HasDescendant", (Standard_Boolean (ChFi2d_Builder::*)(const TopoDS_Edge &) const) &ChFi2d_Builder::HasDescendant, "None", py::arg("E"));
cls_ChFi2d_Builder.def("DescendantEdge", (const TopoDS_Edge & (ChFi2d_Builder::*)(const TopoDS_Edge &) const) &ChFi2d_Builder::DescendantEdge, "returns the modified edge if <E> has descendant or <E> in the other case.", py::arg("E"));
cls_ChFi2d_Builder.def("BasisEdge", (const TopoDS_Edge & (ChFi2d_Builder::*)(const TopoDS_Edge &) const) &ChFi2d_Builder::BasisEdge, "Returns the parent edge of <E> Warning: If <E>is a basis edge, the returned edge would be equal to <E>", py::arg("E"));
cls_ChFi2d_Builder.def("Status", (ChFi2d_ConstructionError (ChFi2d_Builder::*)() const) &ChFi2d_Builder::Status, "None");

// Enums

}