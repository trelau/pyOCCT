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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <HLRTopoBRep_DataMapOfShapeFaceData.hxx>
#include <TopTools_MapOfShape.hxx>
#include <HLRTopoBRep_MapOfShapeListOfVData.hxx>
#include <HLRTopoBRep_ListOfVData.hxx>
#include <HLRTopoBRep_Data.hxx>

void bind_HLRTopoBRep_Data(py::module &mod){

py::class_<HLRTopoBRep_Data, std::unique_ptr<HLRTopoBRep_Data, Deleter<HLRTopoBRep_Data>>> cls_HLRTopoBRep_Data(mod, "HLRTopoBRep_Data", "Stores the results of the OutLine and IsoLine processes.");

// Constructors
cls_HLRTopoBRep_Data.def(py::init<>());

// Fields

// Methods
// cls_HLRTopoBRep_Data.def_static("operator new_", (void * (*)(size_t)) &HLRTopoBRep_Data::operator new, "None", py::arg("theSize"));
// cls_HLRTopoBRep_Data.def_static("operator delete_", (void (*)(void *)) &HLRTopoBRep_Data::operator delete, "None", py::arg("theAddress"));
// cls_HLRTopoBRep_Data.def_static("operator new[]_", (void * (*)(size_t)) &HLRTopoBRep_Data::operator new[], "None", py::arg("theSize"));
// cls_HLRTopoBRep_Data.def_static("operator delete[]_", (void (*)(void *)) &HLRTopoBRep_Data::operator delete[], "None", py::arg("theAddress"));
// cls_HLRTopoBRep_Data.def_static("operator new_", (void * (*)(size_t, void *)) &HLRTopoBRep_Data::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRTopoBRep_Data.def_static("operator delete_", (void (*)(void *, void *)) &HLRTopoBRep_Data::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRTopoBRep_Data.def("Clear", (void (HLRTopoBRep_Data::*)()) &HLRTopoBRep_Data::Clear, "Clear of all the maps.");
cls_HLRTopoBRep_Data.def("Clean", (void (HLRTopoBRep_Data::*)()) &HLRTopoBRep_Data::Clean, "Clear of all the data not needed during and after the hiding process.");
cls_HLRTopoBRep_Data.def("EdgeHasSplE", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Edge &) const) &HLRTopoBRep_Data::EdgeHasSplE, "Returns True if the Edge is split.", py::arg("E"));
cls_HLRTopoBRep_Data.def("FaceHasIntL", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &) const) &HLRTopoBRep_Data::FaceHasIntL, "Returns True if the Face has internal outline.", py::arg("F"));
cls_HLRTopoBRep_Data.def("FaceHasOutL", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &) const) &HLRTopoBRep_Data::FaceHasOutL, "Returns True if the Face has outlines on restriction.", py::arg("F"));
cls_HLRTopoBRep_Data.def("FaceHasIsoL", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &) const) &HLRTopoBRep_Data::FaceHasIsoL, "Returns True if the Face has isolines.", py::arg("F"));
cls_HLRTopoBRep_Data.def("IsSplEEdgeEdge", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Edge &, const TopoDS_Edge &) const) &HLRTopoBRep_Data::IsSplEEdgeEdge, "None", py::arg("E1"), py::arg("E2"));
cls_HLRTopoBRep_Data.def("IsIntLFaceEdge", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &, const TopoDS_Edge &) const) &HLRTopoBRep_Data::IsIntLFaceEdge, "None", py::arg("F"), py::arg("E"));
cls_HLRTopoBRep_Data.def("IsOutLFaceEdge", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &, const TopoDS_Edge &) const) &HLRTopoBRep_Data::IsOutLFaceEdge, "None", py::arg("F"), py::arg("E"));
cls_HLRTopoBRep_Data.def("IsIsoLFaceEdge", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &, const TopoDS_Edge &) const) &HLRTopoBRep_Data::IsIsoLFaceEdge, "None", py::arg("F"), py::arg("E"));
cls_HLRTopoBRep_Data.def("NewSOldS", (TopoDS_Shape (HLRTopoBRep_Data::*)(const TopoDS_Shape &) const) &HLRTopoBRep_Data::NewSOldS, "None", py::arg("New"));
cls_HLRTopoBRep_Data.def("EdgeSplE", (const TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Edge &) const) &HLRTopoBRep_Data::EdgeSplE, "Returns the list of the edges.", py::arg("E"));
cls_HLRTopoBRep_Data.def("FaceIntL", (const TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &) const) &HLRTopoBRep_Data::FaceIntL, "Returns the list of the internal OutLines.", py::arg("F"));
cls_HLRTopoBRep_Data.def("FaceOutL", (const TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &) const) &HLRTopoBRep_Data::FaceOutL, "Returns the list of the OutLines on restriction.", py::arg("F"));
cls_HLRTopoBRep_Data.def("FaceIsoL", (const TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &) const) &HLRTopoBRep_Data::FaceIsoL, "Returns the list of the IsoLines.", py::arg("F"));
cls_HLRTopoBRep_Data.def("IsOutV", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Vertex &) const) &HLRTopoBRep_Data::IsOutV, "Returns True if V is an outline vertex on a restriction.", py::arg("V"));
cls_HLRTopoBRep_Data.def("IsIntV", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Vertex &) const) &HLRTopoBRep_Data::IsIntV, "Returns True if V is an internal outline vertex.", py::arg("V"));
cls_HLRTopoBRep_Data.def("AddOldS", (void (HLRTopoBRep_Data::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &HLRTopoBRep_Data::AddOldS, "None", py::arg("NewS"), py::arg("OldS"));
cls_HLRTopoBRep_Data.def("AddSplE", (TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Edge &)) &HLRTopoBRep_Data::AddSplE, "None", py::arg("E"));
cls_HLRTopoBRep_Data.def("AddIntL", (TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &)) &HLRTopoBRep_Data::AddIntL, "None", py::arg("F"));
cls_HLRTopoBRep_Data.def("AddOutL", (TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &)) &HLRTopoBRep_Data::AddOutL, "None", py::arg("F"));
cls_HLRTopoBRep_Data.def("AddIsoL", (TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &)) &HLRTopoBRep_Data::AddIsoL, "None", py::arg("F"));
cls_HLRTopoBRep_Data.def("AddOutV", (void (HLRTopoBRep_Data::*)(const TopoDS_Vertex &)) &HLRTopoBRep_Data::AddOutV, "None", py::arg("V"));
cls_HLRTopoBRep_Data.def("AddIntV", (void (HLRTopoBRep_Data::*)(const TopoDS_Vertex &)) &HLRTopoBRep_Data::AddIntV, "None", py::arg("V"));
cls_HLRTopoBRep_Data.def("InitEdge", (void (HLRTopoBRep_Data::*)()) &HLRTopoBRep_Data::InitEdge, "None");
cls_HLRTopoBRep_Data.def("MoreEdge", (Standard_Boolean (HLRTopoBRep_Data::*)() const) &HLRTopoBRep_Data::MoreEdge, "None");
cls_HLRTopoBRep_Data.def("NextEdge", (void (HLRTopoBRep_Data::*)()) &HLRTopoBRep_Data::NextEdge, "None");
cls_HLRTopoBRep_Data.def("Edge", (const TopoDS_Edge & (HLRTopoBRep_Data::*)() const) &HLRTopoBRep_Data::Edge, "None");
cls_HLRTopoBRep_Data.def("InitVertex", (void (HLRTopoBRep_Data::*)(const TopoDS_Edge &)) &HLRTopoBRep_Data::InitVertex, "Start an iteration on the vertices of E.", py::arg("E"));
cls_HLRTopoBRep_Data.def("MoreVertex", (Standard_Boolean (HLRTopoBRep_Data::*)() const) &HLRTopoBRep_Data::MoreVertex, "None");
cls_HLRTopoBRep_Data.def("NextVertex", (void (HLRTopoBRep_Data::*)()) &HLRTopoBRep_Data::NextVertex, "None");
cls_HLRTopoBRep_Data.def("Vertex", (const TopoDS_Vertex & (HLRTopoBRep_Data::*)() const) &HLRTopoBRep_Data::Vertex, "None");
cls_HLRTopoBRep_Data.def("Parameter", (Standard_Real (HLRTopoBRep_Data::*)() const) &HLRTopoBRep_Data::Parameter, "None");
cls_HLRTopoBRep_Data.def("InsertBefore", (void (HLRTopoBRep_Data::*)(const TopoDS_Vertex &, const Standard_Real)) &HLRTopoBRep_Data::InsertBefore, "Insert before the current position.", py::arg("V"), py::arg("P"));
cls_HLRTopoBRep_Data.def("Append", (void (HLRTopoBRep_Data::*)(const TopoDS_Vertex &, const Standard_Real)) &HLRTopoBRep_Data::Append, "None", py::arg("V"), py::arg("P"));

// Enums

}