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
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Lin2d.hxx>
#include <BRepClass_Edge.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopExp_Explorer.hxx>
#include <BRepClass_FaceExplorer.hxx>

void bind_BRepClass_FaceExplorer(py::module &mod){

py::class_<BRepClass_FaceExplorer, std::unique_ptr<BRepClass_FaceExplorer>> cls_BRepClass_FaceExplorer(mod, "BRepClass_FaceExplorer", "Provide an exploration of a BRep Face for the classification. Return UV edges.");

// Constructors
cls_BRepClass_FaceExplorer.def(py::init<const TopoDS_Face &>(), py::arg("F"));

// Fields

// Methods
// cls_BRepClass_FaceExplorer.def_static("operator new_", (void * (*)(size_t)) &BRepClass_FaceExplorer::operator new, "None", py::arg("theSize"));
// cls_BRepClass_FaceExplorer.def_static("operator delete_", (void (*)(void *)) &BRepClass_FaceExplorer::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_FaceExplorer.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_FaceExplorer::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_FaceExplorer.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_FaceExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_FaceExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_FaceExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_FaceExplorer.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_FaceExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_FaceExplorer.def("CheckPoint", (Standard_Boolean (BRepClass_FaceExplorer::*)(gp_Pnt2d &)) &BRepClass_FaceExplorer::CheckPoint, "Checks the point and change its coords if it is located too far from the bounding box of the face. New Coordinates of the point will be on the line between the point and the center of the bounding box. Returns True if point was not changed.", py::arg("thePoint"));
cls_BRepClass_FaceExplorer.def("Reject", (Standard_Boolean (BRepClass_FaceExplorer::*)(const gp_Pnt2d &) const) &BRepClass_FaceExplorer::Reject, "Should return True if the point is outside a bounding volume of the face.", py::arg("P"));
cls_BRepClass_FaceExplorer.def("Segment", [](BRepClass_FaceExplorer &self, const gp_Pnt2d & P, gp_Lin2d & L, Standard_Real & Par){ Standard_Boolean rv = self.Segment(P, L, Par); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Par); }, "Returns in <L>, <Par> a segment having at least one intersection with the face boundary to compute intersections.", py::arg("P"), py::arg("L"), py::arg("Par"));
cls_BRepClass_FaceExplorer.def("OtherSegment", [](BRepClass_FaceExplorer &self, const gp_Pnt2d & P, gp_Lin2d & L, Standard_Real & Par){ Standard_Boolean rv = self.OtherSegment(P, L, Par); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Par); }, "Returns in <L>, <Par> a segment having at least one intersection with the face boundary to compute intersections. Each call gives another segment.", py::arg("P"), py::arg("L"), py::arg("Par"));
cls_BRepClass_FaceExplorer.def("InitWires", (void (BRepClass_FaceExplorer::*)()) &BRepClass_FaceExplorer::InitWires, "Starts an exploration of the wires.");
cls_BRepClass_FaceExplorer.def("MoreWires", (Standard_Boolean (BRepClass_FaceExplorer::*)() const) &BRepClass_FaceExplorer::MoreWires, "Returns True if there is a current wire.");
cls_BRepClass_FaceExplorer.def("NextWire", (void (BRepClass_FaceExplorer::*)()) &BRepClass_FaceExplorer::NextWire, "Sets the explorer to the next wire.");
cls_BRepClass_FaceExplorer.def("RejectWire", (Standard_Boolean (BRepClass_FaceExplorer::*)(const gp_Lin2d &, const Standard_Real) const) &BRepClass_FaceExplorer::RejectWire, "Returns True if the wire bounding volume does not intersect the segment.", py::arg("L"), py::arg("Par"));
cls_BRepClass_FaceExplorer.def("InitEdges", (void (BRepClass_FaceExplorer::*)()) &BRepClass_FaceExplorer::InitEdges, "Starts an exploration of the edges of the current wire.");
cls_BRepClass_FaceExplorer.def("MoreEdges", (Standard_Boolean (BRepClass_FaceExplorer::*)() const) &BRepClass_FaceExplorer::MoreEdges, "Returns True if there is a current edge.");
cls_BRepClass_FaceExplorer.def("NextEdge", (void (BRepClass_FaceExplorer::*)()) &BRepClass_FaceExplorer::NextEdge, "Sets the explorer to the next edge.");
cls_BRepClass_FaceExplorer.def("RejectEdge", (Standard_Boolean (BRepClass_FaceExplorer::*)(const gp_Lin2d &, const Standard_Real) const) &BRepClass_FaceExplorer::RejectEdge, "Returns True if the edge bounding volume does not intersect the segment.", py::arg("L"), py::arg("Par"));
cls_BRepClass_FaceExplorer.def("CurrentEdge", (void (BRepClass_FaceExplorer::*)(BRepClass_Edge &, TopAbs_Orientation &) const) &BRepClass_FaceExplorer::CurrentEdge, "Current edge in current wire and its orientation.", py::arg("E"), py::arg("Or"));

// Enums

}