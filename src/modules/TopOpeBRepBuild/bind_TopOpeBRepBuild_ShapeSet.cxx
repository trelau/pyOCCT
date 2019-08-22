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
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_OStream.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopOpeBRepTool_ShapeExplorer.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TopOpeBRepBuild_ShapeSet.hxx>

void bind_TopOpeBRepBuild_ShapeSet(py::module &mod){

py::class_<TopOpeBRepBuild_ShapeSet> cls_TopOpeBRepBuild_ShapeSet(mod, "TopOpeBRepBuild_ShapeSet", "Auxiliary class providing an exploration of a set of shapes to build faces or solids. To build faces : shapes are wires, elements are edges. To build solids : shapes are shells, elements are faces. The ShapeSet stores a list of shapes, a list of elements to start reconstructions, and a map to search neighbours. The map stores the connection between elements through subshapes of type <SubShapeType> given in constructor. <SubShapeType> is : - TopAbs_VERTEX to connect edges - TopAbs_EDGE to connect faces");

// Constructors
cls_TopOpeBRepBuild_ShapeSet.def(py::init<const TopAbs_ShapeEnum>(), py::arg("SubShapeType"));
cls_TopOpeBRepBuild_ShapeSet.def(py::init<const TopAbs_ShapeEnum, const Standard_Boolean>(), py::arg("SubShapeType"), py::arg("checkshape"));

// Fields

// Methods
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_ShapeSet::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_ShapeSet::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_ShapeSet::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_ShapeSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_ShapeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_ShapeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_ShapeSet.def("AddShape", (void (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::AddShape, "Adds <S> to the list of shapes. (wires or shells).", py::arg("S"));
cls_TopOpeBRepBuild_ShapeSet.def("AddStartElement", (void (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::AddStartElement, "(S is a face or edge) Add S to the list of starting shapes used for reconstructions. apply AddElement(S).", py::arg("S"));
cls_TopOpeBRepBuild_ShapeSet.def("AddElement", (void (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::AddElement, "for each subshape SE of S of type mySubShapeType - Add subshapes of S to the map of subshapes (mySubShapeMap) - Add S to the list of shape incident to subshapes of S.", py::arg("S"));
cls_TopOpeBRepBuild_ShapeSet.def("StartElements", (const TopTools_ListOfShape & (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::StartElements, "return a reference on myStartShapes");
cls_TopOpeBRepBuild_ShapeSet.def("InitShapes", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::InitShapes, "None");
cls_TopOpeBRepBuild_ShapeSet.def("MoreShapes", (Standard_Boolean (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::MoreShapes, "None");
cls_TopOpeBRepBuild_ShapeSet.def("NextShape", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::NextShape, "None");
cls_TopOpeBRepBuild_ShapeSet.def("Shape", (const TopoDS_Shape & (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::Shape, "None");
cls_TopOpeBRepBuild_ShapeSet.def("InitStartElements", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::InitStartElements, "None");
cls_TopOpeBRepBuild_ShapeSet.def("MoreStartElements", (Standard_Boolean (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::MoreStartElements, "None");
cls_TopOpeBRepBuild_ShapeSet.def("NextStartElement", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::NextStartElement, "None");
cls_TopOpeBRepBuild_ShapeSet.def("StartElement", (const TopoDS_Shape & (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::StartElement, "None");
cls_TopOpeBRepBuild_ShapeSet.def("InitNeighbours", (void (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::InitNeighbours, "None", py::arg("S"));
cls_TopOpeBRepBuild_ShapeSet.def("MoreNeighbours", (Standard_Boolean (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::MoreNeighbours, "None");
cls_TopOpeBRepBuild_ShapeSet.def("NextNeighbour", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::NextNeighbour, "None");
cls_TopOpeBRepBuild_ShapeSet.def("Neighbour", (const TopoDS_Shape & (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::Neighbour, "None");
cls_TopOpeBRepBuild_ShapeSet.def("ChangeStartShapes", (TopTools_ListOfShape & (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::ChangeStartShapes, "None");
cls_TopOpeBRepBuild_ShapeSet.def("FindNeighbours", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::FindNeighbours, "Build the list of neighbour shapes of myCurrentShape (neighbour shapes and myCurrentShapes are of type t) Initialize myIncidentShapesIter on neighbour shapes.");
cls_TopOpeBRepBuild_ShapeSet.def("MakeNeighboursList", (const TopTools_ListOfShape & (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::MakeNeighboursList, "None", py::arg("E"), py::arg("V"));
cls_TopOpeBRepBuild_ShapeSet.def("MaxNumberSubShape", (Standard_Integer (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::MaxNumberSubShape, "None", py::arg("Shape"));
cls_TopOpeBRepBuild_ShapeSet.def("CheckShape", (void (TopOpeBRepBuild_ShapeSet::*)(const Standard_Boolean)) &TopOpeBRepBuild_ShapeSet::CheckShape, "None", py::arg("checkshape"));
cls_TopOpeBRepBuild_ShapeSet.def("CheckShape", (Standard_Boolean (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::CheckShape, "None");
cls_TopOpeBRepBuild_ShapeSet.def("CheckShape", [](TopOpeBRepBuild_ShapeSet &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.CheckShape(a0); });
cls_TopOpeBRepBuild_ShapeSet.def("CheckShape", (Standard_Boolean (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepBuild_ShapeSet::CheckShape, "None", py::arg("S"), py::arg("checkgeom"));
cls_TopOpeBRepBuild_ShapeSet.def("DumpName", (void (TopOpeBRepBuild_ShapeSet::*)(Standard_OStream &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShapeSet::DumpName, "None", py::arg("OS"), py::arg("str"));
cls_TopOpeBRepBuild_ShapeSet.def("DumpCheck", (void (TopOpeBRepBuild_ShapeSet::*)(Standard_OStream &, const TCollection_AsciiString &, const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepBuild_ShapeSet::DumpCheck, "None", py::arg("OS"), py::arg("str"), py::arg("S"), py::arg("chk"));
cls_TopOpeBRepBuild_ShapeSet.def("DumpSS", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::DumpSS, "None");
cls_TopOpeBRepBuild_ShapeSet.def("DumpBB", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::DumpBB, "None");
cls_TopOpeBRepBuild_ShapeSet.def("DEBName", (void (TopOpeBRepBuild_ShapeSet::*)(const TCollection_AsciiString &)) &TopOpeBRepBuild_ShapeSet::DEBName, "None", py::arg("N"));
cls_TopOpeBRepBuild_ShapeSet.def("DEBName", (const TCollection_AsciiString & (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::DEBName, "None");
cls_TopOpeBRepBuild_ShapeSet.def("DEBNumber", (void (TopOpeBRepBuild_ShapeSet::*)(const Standard_Integer)) &TopOpeBRepBuild_ShapeSet::DEBNumber, "None", py::arg("I"));
cls_TopOpeBRepBuild_ShapeSet.def("DEBNumber", (Standard_Integer (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::DEBNumber, "None");
cls_TopOpeBRepBuild_ShapeSet.def("SName", [](TopOpeBRepBuild_ShapeSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_ShapeSet.def("SName", [](TopOpeBRepBuild_ShapeSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_ShapeSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShapeSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", [](TopOpeBRepBuild_ShapeSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", [](TopOpeBRepBuild_ShapeSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShapeSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShapeSet.def("SName", [](TopOpeBRepBuild_ShapeSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_ShapeSet.def("SName", [](TopOpeBRepBuild_ShapeSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_ShapeSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_ShapeSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShapeSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", [](TopOpeBRepBuild_ShapeSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", [](TopOpeBRepBuild_ShapeSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_ShapeSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShapeSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));

// Enums

}