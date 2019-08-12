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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <ChFiDS_State.hxx>
#include <Standard_Handle.hxx>
#include <ChFiDS_HElSpine.hxx>
#include <ChFiDS_ListOfHElSpine.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <TopoDS_Vertex.hxx>
#include <ChFiDS_ErrorStatus.hxx>
#include <ChFiDS_Spine.hxx>
#include <Standard_Type.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TColStd_HArray1OfReal.hxx>

void bind_ChFiDS_Spine(py::module &mod){

py::class_<ChFiDS_Spine, opencascade::handle<ChFiDS_Spine>, Standard_Transient> cls_ChFiDS_Spine(mod, "ChFiDS_Spine", "Contains information necessary for construction of a 3D fillet or chamfer:");

// Constructors
cls_ChFiDS_Spine.def(py::init<>());
cls_ChFiDS_Spine.def(py::init<const Standard_Real>(), py::arg("Tol"));

// Fields

// Methods
cls_ChFiDS_Spine.def("SetEdges", (void (ChFiDS_Spine::*)(const TopoDS_Edge &)) &ChFiDS_Spine::SetEdges, "store edges composing the guideline", py::arg("E"));
cls_ChFiDS_Spine.def("PutInFirst", (void (ChFiDS_Spine::*)(const TopoDS_Edge &)) &ChFiDS_Spine::PutInFirst, "store the edge at the first position before all others", py::arg("E"));
cls_ChFiDS_Spine.def("NbEdges", (Standard_Integer (ChFiDS_Spine::*)() const) &ChFiDS_Spine::NbEdges, "None");
cls_ChFiDS_Spine.def("Edges", (const TopoDS_Edge & (ChFiDS_Spine::*)(const Standard_Integer) const) &ChFiDS_Spine::Edges, "None", py::arg("I"));
cls_ChFiDS_Spine.def("SetFirstStatus", (void (ChFiDS_Spine::*)(const ChFiDS_State)) &ChFiDS_Spine::SetFirstStatus, "stores if the start of a set of edges starts on a section of free border or forms a closed contour", py::arg("S"));
cls_ChFiDS_Spine.def("SetLastStatus", (void (ChFiDS_Spine::*)(const ChFiDS_State)) &ChFiDS_Spine::SetLastStatus, "stores if the end of a set of edges starts on a section of free border or forms a closed contour", py::arg("S"));
cls_ChFiDS_Spine.def("AppendElSpine", (void (ChFiDS_Spine::*)(const opencascade::handle<ChFiDS_HElSpine> &)) &ChFiDS_Spine::AppendElSpine, "None", py::arg("Els"));
cls_ChFiDS_Spine.def("ElSpine", (opencascade::handle<ChFiDS_HElSpine> (ChFiDS_Spine::*)(const Standard_Integer) const) &ChFiDS_Spine::ElSpine, "None", py::arg("IE"));
cls_ChFiDS_Spine.def("ElSpine", (opencascade::handle<ChFiDS_HElSpine> (ChFiDS_Spine::*)(const TopoDS_Edge &) const) &ChFiDS_Spine::ElSpine, "None", py::arg("E"));
cls_ChFiDS_Spine.def("ElSpine", (opencascade::handle<ChFiDS_HElSpine> (ChFiDS_Spine::*)(const Standard_Real) const) &ChFiDS_Spine::ElSpine, "None", py::arg("W"));
cls_ChFiDS_Spine.def("ChangeElSpines", (ChFiDS_ListOfHElSpine & (ChFiDS_Spine::*)()) &ChFiDS_Spine::ChangeElSpines, "None");
cls_ChFiDS_Spine.def("Reset", [](ChFiDS_Spine &self) -> void { return self.Reset(); });
cls_ChFiDS_Spine.def("Reset", (void (ChFiDS_Spine::*)(const Standard_Boolean)) &ChFiDS_Spine::Reset, "None", py::arg("AllData"));
cls_ChFiDS_Spine.def("SplitDone", (Standard_Boolean (ChFiDS_Spine::*)() const) &ChFiDS_Spine::SplitDone, "None");
cls_ChFiDS_Spine.def("SplitDone", (void (ChFiDS_Spine::*)(const Standard_Boolean)) &ChFiDS_Spine::SplitDone, "None", py::arg("B"));
cls_ChFiDS_Spine.def("Load", (void (ChFiDS_Spine::*)()) &ChFiDS_Spine::Load, "prepare the guideline depending on the edges that are elementary arks (take parameters from a single curvilinear abscissa); to be able to call methods on the geometry (first,last,value,d1,d2) it is necessary to start with preparation otherwise an exception will be raised");
cls_ChFiDS_Spine.def("Resolution", (Standard_Real (ChFiDS_Spine::*)(const Standard_Real) const) &ChFiDS_Spine::Resolution, "None", py::arg("R3d"));
cls_ChFiDS_Spine.def("IsClosed", (Standard_Boolean (ChFiDS_Spine::*)() const) &ChFiDS_Spine::IsClosed, "None");
cls_ChFiDS_Spine.def("FirstParameter", (Standard_Real (ChFiDS_Spine::*)() const) &ChFiDS_Spine::FirstParameter, "None");
cls_ChFiDS_Spine.def("LastParameter", (Standard_Real (ChFiDS_Spine::*)() const) &ChFiDS_Spine::LastParameter, "None");
cls_ChFiDS_Spine.def("SetFirstParameter", (void (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::SetFirstParameter, "None", py::arg("Par"));
cls_ChFiDS_Spine.def("SetLastParameter", (void (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::SetLastParameter, "None", py::arg("Par"));
cls_ChFiDS_Spine.def("FirstParameter", (Standard_Real (ChFiDS_Spine::*)(const Standard_Integer) const) &ChFiDS_Spine::FirstParameter, "gives the total length of all arcs before the number IndexSp", py::arg("IndexSpine"));
cls_ChFiDS_Spine.def("LastParameter", (Standard_Real (ChFiDS_Spine::*)(const Standard_Integer) const) &ChFiDS_Spine::LastParameter, "gives the total length till the ark with number IndexSpine (inclus)", py::arg("IndexSpine"));
cls_ChFiDS_Spine.def("Length", (Standard_Real (ChFiDS_Spine::*)(const Standard_Integer) const) &ChFiDS_Spine::Length, "gives the length of ark with number IndexSp", py::arg("IndexSpine"));
cls_ChFiDS_Spine.def("IsPeriodic", (Standard_Boolean (ChFiDS_Spine::*)() const) &ChFiDS_Spine::IsPeriodic, "None");
cls_ChFiDS_Spine.def("Period", (Standard_Real (ChFiDS_Spine::*)() const) &ChFiDS_Spine::Period, "None");
cls_ChFiDS_Spine.def("Absc", (Standard_Real (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::Absc, "None", py::arg("U"));
cls_ChFiDS_Spine.def("Absc", (Standard_Real (ChFiDS_Spine::*)(const Standard_Real, const Standard_Integer)) &ChFiDS_Spine::Absc, "None", py::arg("U"), py::arg("I"));
cls_ChFiDS_Spine.def("Parameter", [](ChFiDS_Spine &self, const Standard_Real AbsC, Standard_Real & U, const Standard_Boolean Oriented){ self.Parameter(AbsC, U, Oriented); return U; }, "None", py::arg("AbsC"), py::arg("U"), py::arg("Oriented"));
cls_ChFiDS_Spine.def("Parameter", [](ChFiDS_Spine &self, const Standard_Integer Index, const Standard_Real AbsC, Standard_Real & U, const Standard_Boolean Oriented){ self.Parameter(Index, AbsC, U, Oriented); return U; }, "None", py::arg("Index"), py::arg("AbsC"), py::arg("U"), py::arg("Oriented"));
cls_ChFiDS_Spine.def("Value", (gp_Pnt (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::Value, "None", py::arg("AbsC"));
cls_ChFiDS_Spine.def("D0", (void (ChFiDS_Spine::*)(const Standard_Real, gp_Pnt &)) &ChFiDS_Spine::D0, "None", py::arg("AbsC"), py::arg("P"));
cls_ChFiDS_Spine.def("D1", (void (ChFiDS_Spine::*)(const Standard_Real, gp_Pnt &, gp_Vec &)) &ChFiDS_Spine::D1, "None", py::arg("AbsC"), py::arg("P"), py::arg("V1"));
cls_ChFiDS_Spine.def("D2", (void (ChFiDS_Spine::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &ChFiDS_Spine::D2, "None", py::arg("AbsC"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_ChFiDS_Spine.def("SetCurrent", (void (ChFiDS_Spine::*)(const Standard_Integer)) &ChFiDS_Spine::SetCurrent, "None", py::arg("Index"));
cls_ChFiDS_Spine.def("CurrentElementarySpine", (const BRepAdaptor_Curve & (ChFiDS_Spine::*)(const Standard_Integer)) &ChFiDS_Spine::CurrentElementarySpine, "sets the current curve and returns it", py::arg("Index"));
cls_ChFiDS_Spine.def("CurrentIndexOfElementarySpine", (Standard_Integer (ChFiDS_Spine::*)() const) &ChFiDS_Spine::CurrentIndexOfElementarySpine, "None");
cls_ChFiDS_Spine.def("GetType", (GeomAbs_CurveType (ChFiDS_Spine::*)() const) &ChFiDS_Spine::GetType, "None");
cls_ChFiDS_Spine.def("Line", (gp_Lin (ChFiDS_Spine::*)() const) &ChFiDS_Spine::Line, "None");
cls_ChFiDS_Spine.def("Circle", (gp_Circ (ChFiDS_Spine::*)() const) &ChFiDS_Spine::Circle, "None");
cls_ChFiDS_Spine.def("FirstStatus", (ChFiDS_State (ChFiDS_Spine::*)() const) &ChFiDS_Spine::FirstStatus, "returns if the set of edges starts on a free boundary or if the first vertex is a breakpoint or if the set is closed");
cls_ChFiDS_Spine.def("LastStatus", (ChFiDS_State (ChFiDS_Spine::*)() const) &ChFiDS_Spine::LastStatus, "returns the state at the end of the set");
cls_ChFiDS_Spine.def("Status", (ChFiDS_State (ChFiDS_Spine::*)(const Standard_Boolean) const) &ChFiDS_Spine::Status, "None", py::arg("IsFirst"));
cls_ChFiDS_Spine.def("SetStatus", (void (ChFiDS_Spine::*)(const ChFiDS_State, const Standard_Boolean)) &ChFiDS_Spine::SetStatus, "None", py::arg("S"), py::arg("IsFirst"));
cls_ChFiDS_Spine.def("IsTangencyExtremity", (Standard_Boolean (ChFiDS_Spine::*)(const Standard_Boolean) const) &ChFiDS_Spine::IsTangencyExtremity, "returns if the set of edges starts (or end) on Tangency point.", py::arg("IsFirst"));
cls_ChFiDS_Spine.def("SetTangencyExtremity", (void (ChFiDS_Spine::*)(const Standard_Boolean, const Standard_Boolean)) &ChFiDS_Spine::SetTangencyExtremity, "None", py::arg("IsTangency"), py::arg("IsFirst"));
cls_ChFiDS_Spine.def("Absc", (Standard_Real (ChFiDS_Spine::*)(const TopoDS_Vertex &) const) &ChFiDS_Spine::Absc, "None", py::arg("V"));
cls_ChFiDS_Spine.def("FirstVertex", (TopoDS_Vertex (ChFiDS_Spine::*)() const) &ChFiDS_Spine::FirstVertex, "None");
cls_ChFiDS_Spine.def("LastVertex", (TopoDS_Vertex (ChFiDS_Spine::*)() const) &ChFiDS_Spine::LastVertex, "None");
cls_ChFiDS_Spine.def("SetFirstTgt", (void (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::SetFirstTgt, "None", py::arg("W"));
cls_ChFiDS_Spine.def("SetLastTgt", (void (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::SetLastTgt, "None", py::arg("W"));
cls_ChFiDS_Spine.def("HasFirstTgt", (Standard_Boolean (ChFiDS_Spine::*)() const) &ChFiDS_Spine::HasFirstTgt, "None");
cls_ChFiDS_Spine.def("HasLastTgt", (Standard_Boolean (ChFiDS_Spine::*)() const) &ChFiDS_Spine::HasLastTgt, "None");
cls_ChFiDS_Spine.def("SetReference", (void (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::SetReference, "set a parameter reference for the approx.", py::arg("W"));
cls_ChFiDS_Spine.def("SetReference", (void (ChFiDS_Spine::*)(const Standard_Integer)) &ChFiDS_Spine::SetReference, "set a parameter reference for the approx, at the middle of edge I.", py::arg("I"));
cls_ChFiDS_Spine.def("Index", [](ChFiDS_Spine &self, const Standard_Real a0) -> Standard_Integer { return self.Index(a0); });
cls_ChFiDS_Spine.def("Index", (Standard_Integer (ChFiDS_Spine::*)(const Standard_Real, const Standard_Boolean) const) &ChFiDS_Spine::Index, "None", py::arg("W"), py::arg("Forward"));
cls_ChFiDS_Spine.def("Index", (Standard_Integer (ChFiDS_Spine::*)(const TopoDS_Edge &) const) &ChFiDS_Spine::Index, "None", py::arg("E"));
cls_ChFiDS_Spine.def("UnsetReference", (void (ChFiDS_Spine::*)()) &ChFiDS_Spine::UnsetReference, "None");
cls_ChFiDS_Spine.def("SetErrorStatus", (void (ChFiDS_Spine::*)(const ChFiDS_ErrorStatus)) &ChFiDS_Spine::SetErrorStatus, "None", py::arg("state"));
cls_ChFiDS_Spine.def("ErrorStatus", (ChFiDS_ErrorStatus (ChFiDS_Spine::*)() const) &ChFiDS_Spine::ErrorStatus, "None");
cls_ChFiDS_Spine.def_static("get_type_name_", (const char * (*)()) &ChFiDS_Spine::get_type_name, "None");
cls_ChFiDS_Spine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_Spine::get_type_descriptor, "None");
cls_ChFiDS_Spine.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_Spine::*)() const) &ChFiDS_Spine::DynamicType, "None");

// Enums

}