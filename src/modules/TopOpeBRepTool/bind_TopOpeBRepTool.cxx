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
#include <TopoDS_Face.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopoDS_Solid.hxx>
#include <Standard_OStream.hxx>
#include <TopOpeBRepTool_OutCurveType.hxx>
#include <TopOpeBRepTool_GeomTool.hxx>
#include <TopOpeBRepTool_AncestorsTool.hxx>
#include <TopOpeBRepTool_C2DF.hxx>
#include <TopOpeBRepTool_SolidClassifier.hxx>
#include <TopOpeBRepTool_CurveTool.hxx>
#include <TopOpeBRepTool_HBoxTool.hxx>
#include <TopOpeBRepTool_BoxSort.hxx>
#include <TopOpeBRepTool_ShapeExplorer.hxx>
#include <TopOpeBRepTool_ShapeTool.hxx>
#include <TopOpeBRepTool_ShapeClassifier.hxx>
#include <TopOpeBRepTool_connexity.hxx>
#include <TopOpeBRepTool_face.hxx>
#include <TopOpeBRepTool_CLASSI.hxx>
#include <TopOpeBRepTool_TOOL.hxx>
#include <TopOpeBRepTool_CORRISO.hxx>
#include <TopOpeBRepTool_REGUW.hxx>
#include <TopOpeBRepTool_REGUS.hxx>
#include <TopOpeBRepTool_makeTransition.hxx>
#include <TopOpeBRepTool_mkTondgE.hxx>
#include <TopOpeBRepTool_PurgeInternalEdges.hxx>
#include <TopOpeBRepTool_FuseEdges.hxx>
#include <TopOpeBRepTool.hxx>

void bind_TopOpeBRepTool(py::module &mod){

py::class_<TopOpeBRepTool, std::unique_ptr<TopOpeBRepTool>> cls_TopOpeBRepTool(mod, "TopOpeBRepTool", "This package provides services used by the TopOpeBRep package performing topological operations on the BRep data structure.");

// Constructors

// Fields

// Methods
// cls_TopOpeBRepTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool.def_static("PurgeClosingEdges_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const TopTools_DataMapOfShapeInteger &, TopTools_IndexedMapOfOrientedShape &)) &TopOpeBRepTool::PurgeClosingEdges, "Fuse edges (in a wire) of a shape where we have useless vertex. In case face <FF> is built on UV-non-connexed wires (with the two closing edges FORWARD and REVERSED, in spite of one only), we find out the faulty edge, add the faulty shapes (edge,wire,face) to <MshNOK>. <FF> is a face descendant of <F>. <MWisOld>(wire) = 1 if wire is wire of <F> 0 wire results from <F>'s wire splitted. returns false if purge fails", py::arg("F"), py::arg("FF"), py::arg("MWisOld"), py::arg("MshNOK"));
cls_TopOpeBRepTool.def_static("PurgeClosingEdges_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_ListOfShape &, const TopTools_DataMapOfShapeInteger &, TopTools_IndexedMapOfOrientedShape &)) &TopOpeBRepTool::PurgeClosingEdges, "None", py::arg("F"), py::arg("LOF"), py::arg("MWisOld"), py::arg("MshNOK"));
cls_TopOpeBRepTool.def_static("CorrectONUVISO_", (Standard_Boolean (*)(const TopoDS_Face &, TopoDS_Face &)) &TopOpeBRepTool::CorrectONUVISO, "None", py::arg("F"), py::arg("Fsp"));
cls_TopOpeBRepTool.def_static("MakeFaces_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_ListOfShape &, const TopTools_IndexedMapOfOrientedShape &, TopTools_ListOfShape &)) &TopOpeBRepTool::MakeFaces, "Builds up the correct list of faces <LOFF> from <LOF>, using faulty shapes from map <MshNOK>. <LOF> is the list of <F>'s descendant faces. returns false if building fails", py::arg("F"), py::arg("LOF"), py::arg("MshNOK"), py::arg("LOFF"));
cls_TopOpeBRepTool.def_static("Regularize_", (Standard_Boolean (*)(const TopoDS_Face &, TopTools_ListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool::Regularize, "Returns <False> if the face is valid (the UV representation of the face is a set of pcurves connexed by points with connexity 2). Else, splits <aFace> in order to return a list of valid faces.", py::arg("aFace"), py::arg("aListOfFaces"), py::arg("ESplits"));
cls_TopOpeBRepTool.def_static("RegularizeWires_", (Standard_Boolean (*)(const TopoDS_Face &, TopTools_DataMapOfShapeListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool::RegularizeWires, "Returns <False> if the face is valid (the UV representation of the face is a set of pcurves connexed by points with connexity 2). Else, splits wires of the face, these are boundaries of the new faces to build up; <OldWiresNewWires> describes (wire, splits of wire); <ESplits> describes (edge, edge's splits)", py::arg("aFace"), py::arg("OldWiresNewWires"), py::arg("ESplits"));
cls_TopOpeBRepTool.def_static("RegularizeFace_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_DataMapOfShapeListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepTool::RegularizeFace, "Classify wire's splits of map <OldWiresnewWires> in order to compute <aListOfFaces>, the splits of <aFace>.", py::arg("aFace"), py::arg("OldWiresnewWires"), py::arg("aListOfFaces"));
cls_TopOpeBRepTool.def_static("RegularizeShells_", (Standard_Boolean (*)(const TopoDS_Solid &, TopTools_DataMapOfShapeListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool::RegularizeShells, "Returns <False> if the shell is valid (the solid is a set of faces connexed by edges with connexity 2). Else, splits faces of the shell; <OldFacesnewFaces> describes (face, splits of face).", py::arg("aSolid"), py::arg("OldSheNewShe"), py::arg("FSplits"));
cls_TopOpeBRepTool.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepTool_OutCurveType, Standard_OStream &)) &TopOpeBRepTool::Print, "Prints <OCT> as string on stream <S>; returns <S>.", py::arg("OCT"), py::arg("S"));

// Enums

}