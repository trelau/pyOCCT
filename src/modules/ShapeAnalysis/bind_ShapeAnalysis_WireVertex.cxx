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
#include <TopoDS_Wire.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeExtend_WireData.hxx>
#include <gp_XYZ.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <ShapeAnalysis_WireVertex.hxx>

void bind_ShapeAnalysis_WireVertex(py::module &mod){

py::class_<ShapeAnalysis_WireVertex, std::unique_ptr<ShapeAnalysis_WireVertex>> cls_ShapeAnalysis_WireVertex(mod, "ShapeAnalysis_WireVertex", "Analyzes and records status of vertices in a Wire");

// Constructors
cls_ShapeAnalysis_WireVertex.def(py::init<>());

// Fields

// Methods
// cls_ShapeAnalysis_WireVertex.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis_WireVertex::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis_WireVertex.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis_WireVertex::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis_WireVertex.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis_WireVertex::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis_WireVertex.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis_WireVertex::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis_WireVertex.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis_WireVertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis_WireVertex.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis_WireVertex::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis_WireVertex.def("Init", (void (ShapeAnalysis_WireVertex::*)(const TopoDS_Wire &, const Standard_Real)) &ShapeAnalysis_WireVertex::Init, "None", py::arg("wire"), py::arg("preci"));
cls_ShapeAnalysis_WireVertex.def("Init", (void (ShapeAnalysis_WireVertex::*)(const opencascade::handle<ShapeExtend_WireData> &, const Standard_Real)) &ShapeAnalysis_WireVertex::Init, "None", py::arg("swbd"), py::arg("preci"));
cls_ShapeAnalysis_WireVertex.def("Load", (void (ShapeAnalysis_WireVertex::*)(const TopoDS_Wire &)) &ShapeAnalysis_WireVertex::Load, "None", py::arg("wire"));
cls_ShapeAnalysis_WireVertex.def("Load", (void (ShapeAnalysis_WireVertex::*)(const opencascade::handle<ShapeExtend_WireData> &)) &ShapeAnalysis_WireVertex::Load, "None", py::arg("sbwd"));
cls_ShapeAnalysis_WireVertex.def("SetPrecision", (void (ShapeAnalysis_WireVertex::*)(const Standard_Real)) &ShapeAnalysis_WireVertex::SetPrecision, "Sets the precision for work Analysing: for each Vertex, comparison between the end of the preceeding edge and the start of the following edge Each Vertex rank corresponds to the End Vertex of the Edge of same rank, in the ShapeExtend_WireData. I.E. for Vertex <num>, Edge <num> is the preceeding one, <num+1> is the following one", py::arg("preci"));
cls_ShapeAnalysis_WireVertex.def("Analyze", (void (ShapeAnalysis_WireVertex::*)()) &ShapeAnalysis_WireVertex::Analyze, "None");
cls_ShapeAnalysis_WireVertex.def("SetSameVertex", (void (ShapeAnalysis_WireVertex::*)(const Standard_Integer)) &ShapeAnalysis_WireVertex::SetSameVertex, "Records status 'Same Vertex' (logically) on Vertex <num>", py::arg("num"));
cls_ShapeAnalysis_WireVertex.def("SetSameCoords", (void (ShapeAnalysis_WireVertex::*)(const Standard_Integer)) &ShapeAnalysis_WireVertex::SetSameCoords, "Records status 'Same Coords' (at the Vertices Tolerances)", py::arg("num"));
cls_ShapeAnalysis_WireVertex.def("SetClose", (void (ShapeAnalysis_WireVertex::*)(const Standard_Integer)) &ShapeAnalysis_WireVertex::SetClose, "Records status 'Close Coords' (at the Precision of <me>)", py::arg("num"));
cls_ShapeAnalysis_WireVertex.def("SetEnd", (void (ShapeAnalysis_WireVertex::*)(const Standard_Integer, const gp_XYZ &, const Standard_Real)) &ShapeAnalysis_WireVertex::SetEnd, "<num> is the End of preceeding Edge, and its projection on the following one lies on it at the Precision of <me> <ufol> gives the parameter on the following edge", py::arg("num"), py::arg("pos"), py::arg("ufol"));
cls_ShapeAnalysis_WireVertex.def("SetStart", (void (ShapeAnalysis_WireVertex::*)(const Standard_Integer, const gp_XYZ &, const Standard_Real)) &ShapeAnalysis_WireVertex::SetStart, "<num> is the Start of following Edge, its projection on the preceeding one lies on it at the Precision of <me> <upre> gives the parameter on the preceeding edge", py::arg("num"), py::arg("pos"), py::arg("upre"));
cls_ShapeAnalysis_WireVertex.def("SetInters", (void (ShapeAnalysis_WireVertex::*)(const Standard_Integer, const gp_XYZ &, const Standard_Real, const Standard_Real)) &ShapeAnalysis_WireVertex::SetInters, "<num> is the Intersection of both Edges <upre> is the parameter on preceeding edge, <ufol> on following edge", py::arg("num"), py::arg("pos"), py::arg("upre"), py::arg("ufol"));
cls_ShapeAnalysis_WireVertex.def("SetDisjoined", (void (ShapeAnalysis_WireVertex::*)(const Standard_Integer)) &ShapeAnalysis_WireVertex::SetDisjoined, "<num> cannot be said as same vertex", py::arg("num"));
cls_ShapeAnalysis_WireVertex.def("IsDone", (Standard_Boolean (ShapeAnalysis_WireVertex::*)() const) &ShapeAnalysis_WireVertex::IsDone, "Returns True if analysis was performed, else returns False");
cls_ShapeAnalysis_WireVertex.def("Precision", (Standard_Real (ShapeAnalysis_WireVertex::*)() const) &ShapeAnalysis_WireVertex::Precision, "Returns precision value used in analysis");
cls_ShapeAnalysis_WireVertex.def("NbEdges", (Standard_Integer (ShapeAnalysis_WireVertex::*)() const) &ShapeAnalysis_WireVertex::NbEdges, "Returns the number of edges in analyzed wire (i.e. the length of all arrays)");
cls_ShapeAnalysis_WireVertex.def("WireData", (const opencascade::handle<ShapeExtend_WireData> & (ShapeAnalysis_WireVertex::*)() const) &ShapeAnalysis_WireVertex::WireData, "Returns analyzed wire");
cls_ShapeAnalysis_WireVertex.def("Status", (Standard_Integer (ShapeAnalysis_WireVertex::*)(const Standard_Integer) const) &ShapeAnalysis_WireVertex::Status, "Returns the recorded status for a vertex More detail by method Data", py::arg("num"));
cls_ShapeAnalysis_WireVertex.def("Position", (gp_XYZ (ShapeAnalysis_WireVertex::*)(const Standard_Integer) const) &ShapeAnalysis_WireVertex::Position, "None", py::arg("num"));
cls_ShapeAnalysis_WireVertex.def("UPrevious", (Standard_Real (ShapeAnalysis_WireVertex::*)(const Standard_Integer) const) &ShapeAnalysis_WireVertex::UPrevious, "None", py::arg("num"));
cls_ShapeAnalysis_WireVertex.def("UFollowing", (Standard_Real (ShapeAnalysis_WireVertex::*)(const Standard_Integer) const) &ShapeAnalysis_WireVertex::UFollowing, "None", py::arg("num"));
cls_ShapeAnalysis_WireVertex.def("Data", [](ShapeAnalysis_WireVertex &self, const Standard_Integer num, gp_XYZ & pos, Standard_Real & upre, Standard_Real & ufol){ Standard_Integer rv = self.Data(num, pos, upre, ufol); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &>(rv, upre, ufol); }, "Returns the recorded status for a vertex With its recorded position and parameters on both edges These values are relevant regarding the status: Status Meaning Position Preceeding Following 0 Same no no no 1 SameCoord no no no 2 Close no no no 3 End yes no yes 4 Start yes yes no 5 Inters yes yes yes -1 Disjoined no no no", py::arg("num"), py::arg("pos"), py::arg("upre"), py::arg("ufol"));
cls_ShapeAnalysis_WireVertex.def("NextStatus", [](ShapeAnalysis_WireVertex &self, const Standard_Integer a0) -> Standard_Integer { return self.NextStatus(a0); });
cls_ShapeAnalysis_WireVertex.def("NextStatus", (Standard_Integer (ShapeAnalysis_WireVertex::*)(const Standard_Integer, const Standard_Integer) const) &ShapeAnalysis_WireVertex::NextStatus, "For a given status, returns the rank of the vertex which follows <num> and has the same status. 0 if no more Acts as an iterator, starts on the first one", py::arg("stat"), py::arg("num"));
cls_ShapeAnalysis_WireVertex.def("NextCriter", [](ShapeAnalysis_WireVertex &self, const Standard_Integer a0) -> Standard_Integer { return self.NextCriter(a0); });
cls_ShapeAnalysis_WireVertex.def("NextCriter", (Standard_Integer (ShapeAnalysis_WireVertex::*)(const Standard_Integer, const Standard_Integer) const) &ShapeAnalysis_WireVertex::NextCriter, "For a given criter, returns the rank of the vertex which follows <num> and has the same status. 0 if no more Acts as an iterator, starts on the first one Criters are: 0: same vertex (status 0) 1: a solution exists (status >= 0) 2: same coords (i.e. same params) (status 0 1 2) 3: same coods but not same vertex (status 1 2) 4: redefined coords (status 3 4 5) -1: no solution (status -1)", py::arg("crit"), py::arg("num"));

// Enums

}