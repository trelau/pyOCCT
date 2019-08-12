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
#include <TopOpeBRepBuild_Builder.hxx>
#include <Standard.hxx>
#include <TopOpeBRepDS_BuildTool.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_State.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepBuild_GTopo.hxx>
#include <TopOpeBRepBuild_ShellFaceSet.hxx>
#include <TopOpeBRepBuild_WireEdgeSet.hxx>
#include <TopOpeBRepBuild_PaveSet.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <TopOpeBRepDS_DataMapOfShapeState.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <NCollection_DataMap.hxx>
#include <TopTools_OrientedShapeMapHasher.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopOpeBRepBuild_Builder1.hxx>

void bind_TopOpeBRepBuild_Builder1(py::module &mod){

py::class_<TopOpeBRepBuild_Builder1, std::unique_ptr<TopOpeBRepBuild_Builder1, Deleter<TopOpeBRepBuild_Builder1>>, TopOpeBRepBuild_Builder> cls_TopOpeBRepBuild_Builder1(mod, "TopOpeBRepBuild_Builder1", "extension of the class TopOpeBRepBuild_Builder dedicated to avoid bugs in 'Rebuilding Result' algorithm for the case of SOLID/SOLID Boolean Operations");

// Constructors
cls_TopOpeBRepBuild_Builder1.def(py::init<const TopOpeBRepDS_BuildTool &>(), py::arg("BT"));

// Fields

// Methods
// cls_TopOpeBRepBuild_Builder1.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_Builder1::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Builder1.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_Builder1::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder1.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_Builder1::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Builder1.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_Builder1::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder1.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_Builder1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder1.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_Builder1::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_Builder1.def("Clear", (void (TopOpeBRepBuild_Builder1::*)()) &TopOpeBRepBuild_Builder1::Clear, "Removes all splits and merges already performed. Does NOT clear the handled DS (except ShapeWithStatesMaps).");
cls_TopOpeBRepBuild_Builder1.def("Perform", (void (TopOpeBRepBuild_Builder1::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepBuild_Builder1::Perform, "None", py::arg("HDS"));
cls_TopOpeBRepBuild_Builder1.def("Perform", (void (TopOpeBRepBuild_Builder1::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder1::Perform, "None", py::arg("HDS"), py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder1.def("MergeKPart", (void (TopOpeBRepBuild_Builder1::*)()) &TopOpeBRepBuild_Builder1::MergeKPart, "None");
cls_TopOpeBRepBuild_Builder1.def("MergeKPart", (void (TopOpeBRepBuild_Builder1::*)(const TopAbs_State, const TopAbs_State)) &TopOpeBRepBuild_Builder1::MergeKPart, "None", py::arg("TB1"), py::arg("TB2"));
cls_TopOpeBRepBuild_Builder1.def("GFillSolidSFS", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder1::GFillSolidSFS, "None", py::arg("SO1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder1.def("GFillShellSFS", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder1::GFillShellSFS, "None", py::arg("SH1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder1.def("GWESMakeFaces", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, TopOpeBRepBuild_WireEdgeSet &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder1::GWESMakeFaces, "None", py::arg("FF"), py::arg("WES"), py::arg("LOF"));
// cls_TopOpeBRepBuild_Builder1.def("GFillSplitsPVS", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_PaveSet &)) &TopOpeBRepBuild_Builder1::GFillSplitsPVS, "None", py::arg("anEdge"), py::arg("G1"), py::arg("PVS"));
cls_TopOpeBRepBuild_Builder1.def("GFillFaceNotSameDomSFS", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder1::GFillFaceNotSameDomSFS, "None", py::arg("F1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder1.def("GFillFaceNotSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillFaceNotSameDomWES, "None", py::arg("F1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("GFillWireNotSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillWireNotSameDomWES, "None", py::arg("W1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("GFillEdgeNotSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillEdgeNotSameDomWES, "None", py::arg("E1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("GFillFaceSameDomSFS", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder1::GFillFaceSameDomSFS, "None", py::arg("F1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder1.def("GFillFaceSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillFaceSameDomWES, "None", py::arg("F1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("GFillWireSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillWireSameDomWES, "None", py::arg("W1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("GFillEdgeSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillEdgeSameDomWES, "None", py::arg("E1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("PerformONParts", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_IndexedMapOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::PerformONParts, "None", py::arg("F"), py::arg("SDfaces"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("PerformPieceIn2D", [](TopOpeBRepBuild_Builder1 &self, const TopoDS_Edge & aPieceToPerform, const TopoDS_Edge & aOriginalEdge, const TopoDS_Face & edgeFace, const TopoDS_Face & toFace, const TopOpeBRepBuild_GTopo & G, Standard_Boolean & keep){ self.PerformPieceIn2D(aPieceToPerform, aOriginalEdge, edgeFace, toFace, G, keep); return keep; }, "None", py::arg("aPieceToPerform"), py::arg("aOriginalEdge"), py::arg("edgeFace"), py::arg("toFace"), py::arg("G"), py::arg("keep"));
cls_TopOpeBRepBuild_Builder1.def("PerformPieceOn2D", (Standard_Integer (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder1::PerformPieceOn2D, "None", py::arg("aPieceObj"), py::arg("aFaceObj"), py::arg("aEdgeObj"), py::arg("aListOfPieces"), py::arg("aListOfFaces"), py::arg("aListOfPiecesOut2d"));
cls_TopOpeBRepBuild_Builder1.def("TwoPiecesON", (Standard_Integer (TopOpeBRepBuild_Builder1::*)(const TopTools_SequenceOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder1::TwoPiecesON, "None", py::arg("aSeq"), py::arg("aListOfPieces"), py::arg("aListOfFaces"), py::arg("aListOfPiecesOut2d"));
cls_TopOpeBRepBuild_Builder1.def("CorrectResult2d", (Standard_Integer (TopOpeBRepBuild_Builder1::*)(TopoDS_Shape &)) &TopOpeBRepBuild_Builder1::CorrectResult2d, "None", py::arg("aResult"));

// Enums

}