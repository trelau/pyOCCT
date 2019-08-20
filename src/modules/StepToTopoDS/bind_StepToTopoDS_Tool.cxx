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
#include <StepToTopoDS_DataMapOfTRI.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <TopoDS_Shape.hxx>
#include <StepToTopoDS_PointPair.hxx>
#include <TopoDS_Edge.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <TopoDS_Vertex.hxx>
#include <Geom_Surface.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <StepToTopoDS_PointVertexMap.hxx>
#include <StepToTopoDS_PointEdgeMap.hxx>
#include <StepToTopoDS_Tool.hxx>

void bind_StepToTopoDS_Tool(py::module &mod){

py::class_<StepToTopoDS_Tool, std::unique_ptr<StepToTopoDS_Tool>> cls_StepToTopoDS_Tool(mod, "StepToTopoDS_Tool", "This Tool Class provides Information to build a Cas.Cad BRep from a ProSTEP Shape model.");

// Constructors
cls_StepToTopoDS_Tool.def(py::init<>());
cls_StepToTopoDS_Tool.def(py::init<const StepToTopoDS_DataMapOfTRI &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("Map"), py::arg("TP"));

// Fields

// Methods
// cls_StepToTopoDS_Tool.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_Tool::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_Tool.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_Tool::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_Tool.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_Tool::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_Tool.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_Tool.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_Tool.def("Init", (void (StepToTopoDS_Tool::*)(const StepToTopoDS_DataMapOfTRI &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Tool::Init, "None", py::arg("Map"), py::arg("TP"));
cls_StepToTopoDS_Tool.def("IsBound", (Standard_Boolean (StepToTopoDS_Tool::*)(const opencascade::handle<StepShape_TopologicalRepresentationItem> &)) &StepToTopoDS_Tool::IsBound, "None", py::arg("TRI"));
cls_StepToTopoDS_Tool.def("Bind", (void (StepToTopoDS_Tool::*)(const opencascade::handle<StepShape_TopologicalRepresentationItem> &, const TopoDS_Shape &)) &StepToTopoDS_Tool::Bind, "None", py::arg("TRI"), py::arg("S"));
cls_StepToTopoDS_Tool.def("Find", (const TopoDS_Shape & (StepToTopoDS_Tool::*)(const opencascade::handle<StepShape_TopologicalRepresentationItem> &)) &StepToTopoDS_Tool::Find, "None", py::arg("TRI"));
cls_StepToTopoDS_Tool.def("ClearEdgeMap", (void (StepToTopoDS_Tool::*)()) &StepToTopoDS_Tool::ClearEdgeMap, "None");
cls_StepToTopoDS_Tool.def("IsEdgeBound", (Standard_Boolean (StepToTopoDS_Tool::*)(const StepToTopoDS_PointPair &)) &StepToTopoDS_Tool::IsEdgeBound, "None", py::arg("PP"));
cls_StepToTopoDS_Tool.def("BindEdge", (void (StepToTopoDS_Tool::*)(const StepToTopoDS_PointPair &, const TopoDS_Edge &)) &StepToTopoDS_Tool::BindEdge, "None", py::arg("PP"), py::arg("E"));
cls_StepToTopoDS_Tool.def("FindEdge", (const TopoDS_Edge & (StepToTopoDS_Tool::*)(const StepToTopoDS_PointPair &)) &StepToTopoDS_Tool::FindEdge, "None", py::arg("PP"));
cls_StepToTopoDS_Tool.def("ClearVertexMap", (void (StepToTopoDS_Tool::*)()) &StepToTopoDS_Tool::ClearVertexMap, "None");
cls_StepToTopoDS_Tool.def("IsVertexBound", (Standard_Boolean (StepToTopoDS_Tool::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepToTopoDS_Tool::IsVertexBound, "None", py::arg("PG"));
cls_StepToTopoDS_Tool.def("BindVertex", (void (StepToTopoDS_Tool::*)(const opencascade::handle<StepGeom_CartesianPoint> &, const TopoDS_Vertex &)) &StepToTopoDS_Tool::BindVertex, "None", py::arg("P"), py::arg("V"));
cls_StepToTopoDS_Tool.def("FindVertex", (const TopoDS_Vertex & (StepToTopoDS_Tool::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepToTopoDS_Tool::FindVertex, "None", py::arg("P"));
cls_StepToTopoDS_Tool.def("ComputePCurve", (void (StepToTopoDS_Tool::*)(const Standard_Boolean)) &StepToTopoDS_Tool::ComputePCurve, "None", py::arg("B"));
cls_StepToTopoDS_Tool.def("ComputePCurve", (Standard_Boolean (StepToTopoDS_Tool::*)() const) &StepToTopoDS_Tool::ComputePCurve, "None");
cls_StepToTopoDS_Tool.def("TransientProcess", (opencascade::handle<Transfer_TransientProcess> (StepToTopoDS_Tool::*)() const) &StepToTopoDS_Tool::TransientProcess, "None");
cls_StepToTopoDS_Tool.def("AddContinuity", (void (StepToTopoDS_Tool::*)(const opencascade::handle<Geom_Surface> &)) &StepToTopoDS_Tool::AddContinuity, "None", py::arg("GeomSurf"));
cls_StepToTopoDS_Tool.def("AddContinuity", (void (StepToTopoDS_Tool::*)(const opencascade::handle<Geom_Curve> &)) &StepToTopoDS_Tool::AddContinuity, "None", py::arg("GeomCurve"));
cls_StepToTopoDS_Tool.def("AddContinuity", (void (StepToTopoDS_Tool::*)(const opencascade::handle<Geom2d_Curve> &)) &StepToTopoDS_Tool::AddContinuity, "None", py::arg("GeomCur2d"));
cls_StepToTopoDS_Tool.def("C0Surf", (Standard_Integer (StepToTopoDS_Tool::*)() const) &StepToTopoDS_Tool::C0Surf, "None");
cls_StepToTopoDS_Tool.def("C1Surf", (Standard_Integer (StepToTopoDS_Tool::*)() const) &StepToTopoDS_Tool::C1Surf, "None");
cls_StepToTopoDS_Tool.def("C2Surf", (Standard_Integer (StepToTopoDS_Tool::*)() const) &StepToTopoDS_Tool::C2Surf, "None");
cls_StepToTopoDS_Tool.def("C0Cur2", (Standard_Integer (StepToTopoDS_Tool::*)() const) &StepToTopoDS_Tool::C0Cur2, "None");
cls_StepToTopoDS_Tool.def("C1Cur2", (Standard_Integer (StepToTopoDS_Tool::*)() const) &StepToTopoDS_Tool::C1Cur2, "None");
cls_StepToTopoDS_Tool.def("C2Cur2", (Standard_Integer (StepToTopoDS_Tool::*)() const) &StepToTopoDS_Tool::C2Cur2, "None");
cls_StepToTopoDS_Tool.def("C0Cur3", (Standard_Integer (StepToTopoDS_Tool::*)() const) &StepToTopoDS_Tool::C0Cur3, "None");
cls_StepToTopoDS_Tool.def("C1Cur3", (Standard_Integer (StepToTopoDS_Tool::*)() const) &StepToTopoDS_Tool::C1Cur3, "None");
cls_StepToTopoDS_Tool.def("C2Cur3", (Standard_Integer (StepToTopoDS_Tool::*)() const) &StepToTopoDS_Tool::C2Cur3, "None");

// Enums

}