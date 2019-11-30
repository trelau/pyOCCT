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
#include <TopTools_ListOfShape.hxx>
#include <HLRTopoBRep_FaceData.hxx>
#include <NCollection_DataMap.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <HLRTopoBRep_DataMapOfShapeFaceData.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRTopoBRep_VData.hxx>
#include <NCollection_List.hxx>
#include <HLRTopoBRep_ListOfVData.hxx>
#include <HLRTopoBRep_MapOfShapeListOfVData.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <HLRTopoBRep_Data.hxx>
#include <Contap_Contour.hxx>
#include <BRepTopAdaptor_MapOfShapeTool.hxx>
#include <Contap_Point.hxx>
#include <HLRTopoBRep_DSFiller.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Line.hxx>
#include <HLRTopoBRep_FaceIsoLiner.hxx>
#include <Standard_Transient.hxx>
#include <HLRAlgo_Projector.hxx>
#include <Standard_Std.hxx>
#include <HLRTopoBRep_OutLiner.hxx>
#include <Standard_Type.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>

PYBIND11_MODULE(HLRTopoBRep, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Contap");
py::module::import("OCCT.BRepTopAdaptor");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.HLRAlgo");

// CLASS: HLRTOPOBREP_FACEDATA
py::class_<HLRTopoBRep_FaceData> cls_HLRTopoBRep_FaceData(mod, "HLRTopoBRep_FaceData", "Contains the 3 ListOfShape of a Face ( Internal OutLines, OutLines on restriction and IsoLines ).");

// Constructors
cls_HLRTopoBRep_FaceData.def(py::init<>());

// Methods
// cls_HLRTopoBRep_FaceData.def_static("operator new_", (void * (*)(size_t)) &HLRTopoBRep_FaceData::operator new, "None", py::arg("theSize"));
// cls_HLRTopoBRep_FaceData.def_static("operator delete_", (void (*)(void *)) &HLRTopoBRep_FaceData::operator delete, "None", py::arg("theAddress"));
// cls_HLRTopoBRep_FaceData.def_static("operator new[]_", (void * (*)(size_t)) &HLRTopoBRep_FaceData::operator new[], "None", py::arg("theSize"));
// cls_HLRTopoBRep_FaceData.def_static("operator delete[]_", (void (*)(void *)) &HLRTopoBRep_FaceData::operator delete[], "None", py::arg("theAddress"));
// cls_HLRTopoBRep_FaceData.def_static("operator new_", (void * (*)(size_t, void *)) &HLRTopoBRep_FaceData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRTopoBRep_FaceData.def_static("operator delete_", (void (*)(void *, void *)) &HLRTopoBRep_FaceData::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRTopoBRep_FaceData.def("FaceIntL", (const TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)() const) &HLRTopoBRep_FaceData::FaceIntL, "None");
cls_HLRTopoBRep_FaceData.def("FaceOutL", (const TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)() const) &HLRTopoBRep_FaceData::FaceOutL, "None");
cls_HLRTopoBRep_FaceData.def("FaceIsoL", (const TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)() const) &HLRTopoBRep_FaceData::FaceIsoL, "None");
cls_HLRTopoBRep_FaceData.def("AddIntL", (TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)()) &HLRTopoBRep_FaceData::AddIntL, "None");
cls_HLRTopoBRep_FaceData.def("AddOutL", (TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)()) &HLRTopoBRep_FaceData::AddOutL, "None");
cls_HLRTopoBRep_FaceData.def("AddIsoL", (TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)()) &HLRTopoBRep_FaceData::AddIsoL, "None");

// TYPEDEF: HLRTOPOBREP_DATAMAPOFSHAPEFACEDATA
bind_NCollection_DataMap<TopoDS_Shape, HLRTopoBRep_FaceData, TopTools_ShapeMapHasher>(mod, "HLRTopoBRep_DataMapOfShapeFaceData", py::module_local(false));

// TYPEDEF: HLRTOPOBREP_DATAMAPITERATOROFDATAMAPOFSHAPEFACEDATA

// CLASS: HLRTOPOBREP_VDATA
py::class_<HLRTopoBRep_VData> cls_HLRTopoBRep_VData(mod, "HLRTopoBRep_VData", "None");

// Constructors
cls_HLRTopoBRep_VData.def(py::init<>());
cls_HLRTopoBRep_VData.def(py::init<const Standard_Real, const TopoDS_Shape &>(), py::arg("P"), py::arg("V"));

// Methods
// cls_HLRTopoBRep_VData.def_static("operator new_", (void * (*)(size_t)) &HLRTopoBRep_VData::operator new, "None", py::arg("theSize"));
// cls_HLRTopoBRep_VData.def_static("operator delete_", (void (*)(void *)) &HLRTopoBRep_VData::operator delete, "None", py::arg("theAddress"));
// cls_HLRTopoBRep_VData.def_static("operator new[]_", (void * (*)(size_t)) &HLRTopoBRep_VData::operator new[], "None", py::arg("theSize"));
// cls_HLRTopoBRep_VData.def_static("operator delete[]_", (void (*)(void *)) &HLRTopoBRep_VData::operator delete[], "None", py::arg("theAddress"));
// cls_HLRTopoBRep_VData.def_static("operator new_", (void * (*)(size_t, void *)) &HLRTopoBRep_VData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRTopoBRep_VData.def_static("operator delete_", (void (*)(void *, void *)) &HLRTopoBRep_VData::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRTopoBRep_VData.def("Parameter", (Standard_Real (HLRTopoBRep_VData::*)() const) &HLRTopoBRep_VData::Parameter, "None");
cls_HLRTopoBRep_VData.def("Vertex", (const TopoDS_Shape & (HLRTopoBRep_VData::*)() const) &HLRTopoBRep_VData::Vertex, "None");

// TYPEDEF: HLRTOPOBREP_LISTOFVDATA
bind_NCollection_List<HLRTopoBRep_VData>(mod, "HLRTopoBRep_ListOfVData", py::module_local(false));

// TYPEDEF: HLRTOPOBREP_LISTITERATOROFLISTOFVDATA
bind_NCollection_TListIterator<HLRTopoBRep_VData>(mod, "HLRTopoBRep_ListIteratorOfListOfVData", py::module_local(false));

// TYPEDEF: HLRTOPOBREP_MAPOFSHAPELISTOFVDATA
bind_NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>(mod, "HLRTopoBRep_MapOfShapeListOfVData", py::module_local(false));

// TYPEDEF: HLRTOPOBREP_DATAMAPITERATOROFMAPOFSHAPELISTOFVDATA
py::class_<NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator, NCollection_BaseMap::Iterator> cls_NCollection_DataMap_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData(mod, "HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData", "None");

// Constructors
cls_NCollection_DataMap_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def(py::init<>());
cls_NCollection_DataMap_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def(py::init<const NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher> &>(), py::arg("theMap"));

// Methods
cls_NCollection_DataMap_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def("More", (Standard_Boolean (NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::More, "Query if the end of collection is reached by iterator");
cls_NCollection_DataMap_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def("Next", (void (NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::*)()) &NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::Next, "Make a step along the collection");
cls_NCollection_DataMap_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def("Value", (const NCollection_List<HLRTopoBRep_VData> & (NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::Value, "Value inquiry");
cls_NCollection_DataMap_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def("ChangeValue", (NCollection_List<HLRTopoBRep_VData> & (NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::ChangeValue, "Value change access");
cls_NCollection_DataMap_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def("Key", (const TopoDS_Shape & (NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::Key, "Key");

// CLASS: HLRTOPOBREP_DATA
py::class_<HLRTopoBRep_Data> cls_HLRTopoBRep_Data(mod, "HLRTopoBRep_Data", "Stores the results of the OutLine and IsoLine processes.");

// Constructors
cls_HLRTopoBRep_Data.def(py::init<>());

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

// CLASS: HLRTOPOBREP_DSFILLER
py::class_<HLRTopoBRep_DSFiller> cls_HLRTopoBRep_DSFiller(mod, "HLRTopoBRep_DSFiller", "Provides methods to fill a HLRTopoBRep_Data.");

// Methods
// cls_HLRTopoBRep_DSFiller.def_static("operator new_", (void * (*)(size_t)) &HLRTopoBRep_DSFiller::operator new, "None", py::arg("theSize"));
// cls_HLRTopoBRep_DSFiller.def_static("operator delete_", (void (*)(void *)) &HLRTopoBRep_DSFiller::operator delete, "None", py::arg("theAddress"));
// cls_HLRTopoBRep_DSFiller.def_static("operator new[]_", (void * (*)(size_t)) &HLRTopoBRep_DSFiller::operator new[], "None", py::arg("theSize"));
// cls_HLRTopoBRep_DSFiller.def_static("operator delete[]_", (void (*)(void *)) &HLRTopoBRep_DSFiller::operator delete[], "None", py::arg("theAddress"));
// cls_HLRTopoBRep_DSFiller.def_static("operator new_", (void * (*)(size_t, void *)) &HLRTopoBRep_DSFiller::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRTopoBRep_DSFiller.def_static("operator delete_", (void (*)(void *, void *)) &HLRTopoBRep_DSFiller::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRTopoBRep_DSFiller.def_static("Insert_", (void (*)(const TopoDS_Shape &, Contap_Contour &, HLRTopoBRep_Data &, BRepTopAdaptor_MapOfShapeTool &, const Standard_Integer)) &HLRTopoBRep_DSFiller::Insert, "Stores in <DS> the outlines of <S> using the current outliner and stores the isolines in <DS> using a Hatcher.", py::arg("S"), py::arg("FO"), py::arg("DS"), py::arg("MST"), py::arg("nbIso"));

// CLASS: HLRTOPOBREP_FACEISOLINER
py::class_<HLRTopoBRep_FaceIsoLiner> cls_HLRTopoBRep_FaceIsoLiner(mod, "HLRTopoBRep_FaceIsoLiner", "None");

// Methods
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator new_", (void * (*)(size_t)) &HLRTopoBRep_FaceIsoLiner::operator new, "None", py::arg("theSize"));
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator delete_", (void (*)(void *)) &HLRTopoBRep_FaceIsoLiner::operator delete, "None", py::arg("theAddress"));
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator new[]_", (void * (*)(size_t)) &HLRTopoBRep_FaceIsoLiner::operator new[], "None", py::arg("theSize"));
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator delete[]_", (void (*)(void *)) &HLRTopoBRep_FaceIsoLiner::operator delete[], "None", py::arg("theAddress"));
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator new_", (void * (*)(size_t, void *)) &HLRTopoBRep_FaceIsoLiner::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRTopoBRep_FaceIsoLiner.def_static("operator delete_", (void (*)(void *, void *)) &HLRTopoBRep_FaceIsoLiner::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRTopoBRep_FaceIsoLiner.def_static("Perform_", (void (*)(const Standard_Integer, const TopoDS_Face &, HLRTopoBRep_Data &, const Standard_Integer)) &HLRTopoBRep_FaceIsoLiner::Perform, "None", py::arg("FI"), py::arg("F"), py::arg("DS"), py::arg("nbIsos"));
cls_HLRTopoBRep_FaceIsoLiner.def_static("MakeVertex_", (TopoDS_Vertex (*)(const TopoDS_Edge &, const gp_Pnt &, const Standard_Real, const Standard_Real, HLRTopoBRep_Data &)) &HLRTopoBRep_FaceIsoLiner::MakeVertex, "None", py::arg("E"), py::arg("P"), py::arg("Par"), py::arg("Tol"), py::arg("DS"));
cls_HLRTopoBRep_FaceIsoLiner.def_static("MakeIsoLine_", (void (*)(const TopoDS_Face &, const opencascade::handle<Geom2d_Line> &, TopoDS_Vertex &, TopoDS_Vertex &, const Standard_Real, const Standard_Real, const Standard_Real, HLRTopoBRep_Data &)) &HLRTopoBRep_FaceIsoLiner::MakeIsoLine, "None", py::arg("F"), py::arg("Iso"), py::arg("V1"), py::arg("V2"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("DS"));

// CLASS: HLRTOPOBREP_OUTLINER
py::class_<HLRTopoBRep_OutLiner, opencascade::handle<HLRTopoBRep_OutLiner>, Standard_Transient> cls_HLRTopoBRep_OutLiner(mod, "HLRTopoBRep_OutLiner", "None");

// Constructors
cls_HLRTopoBRep_OutLiner.def(py::init<>());
cls_HLRTopoBRep_OutLiner.def(py::init<const TopoDS_Shape &>(), py::arg("OriSh"));
cls_HLRTopoBRep_OutLiner.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("OriS"), py::arg("OutS"));

// Methods
cls_HLRTopoBRep_OutLiner.def("OriginalShape", (void (HLRTopoBRep_OutLiner::*)(const TopoDS_Shape &)) &HLRTopoBRep_OutLiner::OriginalShape, "None", py::arg("OriS"));
cls_HLRTopoBRep_OutLiner.def("OriginalShape", (TopoDS_Shape & (HLRTopoBRep_OutLiner::*)()) &HLRTopoBRep_OutLiner::OriginalShape, "None");
cls_HLRTopoBRep_OutLiner.def("OutLinedShape", (void (HLRTopoBRep_OutLiner::*)(const TopoDS_Shape &)) &HLRTopoBRep_OutLiner::OutLinedShape, "None", py::arg("OutS"));
cls_HLRTopoBRep_OutLiner.def("OutLinedShape", (TopoDS_Shape & (HLRTopoBRep_OutLiner::*)()) &HLRTopoBRep_OutLiner::OutLinedShape, "None");
cls_HLRTopoBRep_OutLiner.def("DataStructure", (HLRTopoBRep_Data & (HLRTopoBRep_OutLiner::*)()) &HLRTopoBRep_OutLiner::DataStructure, "None");
cls_HLRTopoBRep_OutLiner.def("Fill", (void (HLRTopoBRep_OutLiner::*)(const HLRAlgo_Projector &, BRepTopAdaptor_MapOfShapeTool &, const Standard_Integer)) &HLRTopoBRep_OutLiner::Fill, "None", py::arg("P"), py::arg("MST"), py::arg("nbIso"));
cls_HLRTopoBRep_OutLiner.def_static("get_type_name_", (const char * (*)()) &HLRTopoBRep_OutLiner::get_type_name, "None");
cls_HLRTopoBRep_OutLiner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRTopoBRep_OutLiner::get_type_descriptor, "None");
cls_HLRTopoBRep_OutLiner.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRTopoBRep_OutLiner::*)() const) &HLRTopoBRep_OutLiner::DynamicType, "None");


}
