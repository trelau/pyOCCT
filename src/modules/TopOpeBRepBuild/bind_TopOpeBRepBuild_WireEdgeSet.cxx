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
#include <TopOpeBRepBuild_ShapeSet.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopAbs_Orientation.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <TopOpeBRepBuild_WireEdgeSet.hxx>

void bind_TopOpeBRepBuild_WireEdgeSet(py::module &mod){

py::class_<TopOpeBRepBuild_WireEdgeSet, TopOpeBRepBuild_ShapeSet> cls_TopOpeBRepBuild_WireEdgeSet(mod, "TopOpeBRepBuild_WireEdgeSet", "a bound is a wire, a boundelement is an edge. The ShapeSet stores : - a list of wire (bounds), - a list of edge (boundelements) to start reconstructions, - a map of vertex giving the list of edge incident to a vertex.");

// Constructors
cls_TopOpeBRepBuild_WireEdgeSet.def(py::init<const TopoDS_Shape &>(), py::arg("F"));
cls_TopOpeBRepBuild_WireEdgeSet.def(py::init<const TopoDS_Shape &, const Standard_Address>(), py::arg("F"), py::arg("Addr"));

// Fields

// Methods
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_WireEdgeSet::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_WireEdgeSet::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_WireEdgeSet::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_WireEdgeSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_WireEdgeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_WireEdgeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_WireEdgeSet.def("Face", (const TopoDS_Face & (TopOpeBRepBuild_WireEdgeSet::*)() const) &TopOpeBRepBuild_WireEdgeSet::Face, "value of field myFace");
cls_TopOpeBRepBuild_WireEdgeSet.def("AddShape", (void (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeSet::AddShape, "None", py::arg("S"));
cls_TopOpeBRepBuild_WireEdgeSet.def("AddStartElement", (void (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeSet::AddStartElement, "None", py::arg("S"));
cls_TopOpeBRepBuild_WireEdgeSet.def("AddElement", (void (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeSet::AddElement, "None", py::arg("S"));
cls_TopOpeBRepBuild_WireEdgeSet.def("InitNeighbours", (void (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeSet::InitNeighbours, "None", py::arg("E"));
cls_TopOpeBRepBuild_WireEdgeSet.def("FindNeighbours", (void (TopOpeBRepBuild_WireEdgeSet::*)()) &TopOpeBRepBuild_WireEdgeSet::FindNeighbours, "Build the list of neighbour edges of edge myCurrentShape Initialize iterator of neighbour edges to edge myCurrentShape");
cls_TopOpeBRepBuild_WireEdgeSet.def("MakeNeighboursList", (const TopTools_ListOfShape & (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeSet::MakeNeighboursList, "None", py::arg("E"), py::arg("V"));
cls_TopOpeBRepBuild_WireEdgeSet.def_static("IsUVISO_", [](const TopoDS_Edge & E, const TopoDS_Face & F, Standard_Boolean & uiso, Standard_Boolean & viso){ TopOpeBRepBuild_WireEdgeSet::IsUVISO(E, F, uiso, viso); return std::tuple<Standard_Boolean &, Standard_Boolean &>(uiso, viso); }, "None", py::arg("E"), py::arg("F"), py::arg("uiso"), py::arg("viso"));
cls_TopOpeBRepBuild_WireEdgeSet.def("DumpSS", (void (TopOpeBRepBuild_WireEdgeSet::*)()) &TopOpeBRepBuild_WireEdgeSet::DumpSS, "None");
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", [](TopOpeBRepBuild_WireEdgeSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", [](TopOpeBRepBuild_WireEdgeSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_WireEdgeSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", [](TopOpeBRepBuild_WireEdgeSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", [](TopOpeBRepBuild_WireEdgeSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_WireEdgeSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_WireEdgeSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", [](TopOpeBRepBuild_WireEdgeSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", [](TopOpeBRepBuild_WireEdgeSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_WireEdgeSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", [](TopOpeBRepBuild_WireEdgeSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", [](TopOpeBRepBuild_WireEdgeSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_WireEdgeSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_WireEdgeSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));

// Enums

}