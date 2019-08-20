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
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <Precision.hxx>
#include <BOPDS_IndexRange.hxx>
#include <BOPDS_ShapeInfo.hxx>
#include <TopoDS_Shape.hxx>
#include <BOPDS_VectorOfListOfPaveBlock.hxx>
#include <BOPDS_ListOfPaveBlock.hxx>
#include <BOPDS_PaveBlock.hxx>
#include <BOPDS_CommonBlock.hxx>
#include <BOPDS_VectorOfFaceInfo.hxx>
#include <BOPDS_FaceInfo.hxx>
#include <BOPDS_IndexedMapOfPaveBlock.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <BOPDS_MapOfPaveBlock.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <BOPDS_VectorOfInterfVV.hxx>
#include <BOPDS_VectorOfInterfVE.hxx>
#include <BOPDS_VectorOfInterfVF.hxx>
#include <BOPDS_VectorOfInterfEE.hxx>
#include <BOPDS_VectorOfInterfEF.hxx>
#include <BOPDS_VectorOfInterfFF.hxx>
#include <BOPDS_VectorOfInterfVZ.hxx>
#include <BOPDS_VectorOfInterfEZ.hxx>
#include <BOPDS_VectorOfInterfFZ.hxx>
#include <BOPDS_VectorOfInterfZZ.hxx>
#include <BOPDS_MapOfPair.hxx>
#include <BOPDS_ListOfPave.hxx>
#include <Bnd_Box.hxx>
#include <BOPDS_VectorOfIndexRange.hxx>
#include <BOPDS_VectorOfShapeInfo.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <BOPDS_DataMapOfPaveBlockCommonBlock.hxx>
#include <TColStd_DataMapOfIntegerListOfInteger.hxx>
#include <BOPDS_DS.hxx>

void bind_BOPDS_DS(py::module &mod){

py::class_<BOPDS_DS, std::unique_ptr<BOPDS_DS>> cls_BOPDS_DS(mod, "BOPDS_DS", "The class BOPDS_DS provides the control of data structure for the algorithms in the Boolean Component such as General Fuse, Boolean operations, Section, Maker Volume, Splitter and Cells Builder.");

// Constructors
cls_BOPDS_DS.def(py::init<>());
cls_BOPDS_DS.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPDS_DS.def_static("operator new_", (void * (*)(size_t)) &BOPDS_DS::operator new, "None", py::arg("theSize"));
// cls_BOPDS_DS.def_static("operator delete_", (void (*)(void *)) &BOPDS_DS::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_DS.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_DS::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_DS.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_DS::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_DS.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_DS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_DS.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_DS::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_DS.def("Clear", (void (BOPDS_DS::*)()) &BOPDS_DS::Clear, "Clears the contents");
cls_BOPDS_DS.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (BOPDS_DS::*)() const) &BOPDS_DS::Allocator, "Selector");
cls_BOPDS_DS.def("SetArguments", (void (BOPDS_DS::*)(const TopTools_ListOfShape &)) &BOPDS_DS::SetArguments, "Modifier Sets the arguments [theLS] of an operation", py::arg("theLS"));
cls_BOPDS_DS.def("Arguments", (const TopTools_ListOfShape & (BOPDS_DS::*)() const) &BOPDS_DS::Arguments, "Selector Returns the arguments of an operation");
cls_BOPDS_DS.def("Init", [](BOPDS_DS &self) -> void { return self.Init(); });
cls_BOPDS_DS.def("Init", (void (BOPDS_DS::*)(const Standard_Real)) &BOPDS_DS::Init, "Initializes the data structure for the arguments", py::arg("theFuzz"));
cls_BOPDS_DS.def("NbShapes", (Standard_Integer (BOPDS_DS::*)() const) &BOPDS_DS::NbShapes, "Selector Returns the total number of shapes stored");
cls_BOPDS_DS.def("NbSourceShapes", (Standard_Integer (BOPDS_DS::*)() const) &BOPDS_DS::NbSourceShapes, "Selector Returns the total number of source shapes stored");
cls_BOPDS_DS.def("NbRanges", (Standard_Integer (BOPDS_DS::*)() const) &BOPDS_DS::NbRanges, "Selector Returns the number of index ranges");
cls_BOPDS_DS.def("Range", (const BOPDS_IndexRange & (BOPDS_DS::*)(const Standard_Integer) const) &BOPDS_DS::Range, "Selector Returns the index range 'i'", py::arg("theIndex"));
cls_BOPDS_DS.def("Rank", (Standard_Integer (BOPDS_DS::*)(const Standard_Integer) const) &BOPDS_DS::Rank, "Selector Returns the rank of the shape of index 'i'", py::arg("theIndex"));
cls_BOPDS_DS.def("IsNewShape", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer) const) &BOPDS_DS::IsNewShape, "Returns true if the shape of index 'i' is not the source shape/sub-shape", py::arg("theIndex"));
cls_BOPDS_DS.def("Append", (Standard_Integer (BOPDS_DS::*)(const BOPDS_ShapeInfo &)) &BOPDS_DS::Append, "Modifier Appends the information about the shape [theSI] to the data structure Returns the index of theSI in the data structure", py::arg("theSI"));
cls_BOPDS_DS.def("Append", (Standard_Integer (BOPDS_DS::*)(const TopoDS_Shape &)) &BOPDS_DS::Append, "Modifier Appends the default information about the shape [theS] to the data structure Returns the index of theS in the data structure", py::arg("theS"));
cls_BOPDS_DS.def("ShapeInfo", (const BOPDS_ShapeInfo & (BOPDS_DS::*)(const Standard_Integer) const) &BOPDS_DS::ShapeInfo, "Selector Returns the information about the shape with index theIndex", py::arg("theIndex"));
cls_BOPDS_DS.def("ChangeShapeInfo", (BOPDS_ShapeInfo & (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::ChangeShapeInfo, "Selector/Modifier Returns the information about the shape with index theIndex", py::arg("theIndex"));
cls_BOPDS_DS.def("Shape", (const TopoDS_Shape & (BOPDS_DS::*)(const Standard_Integer) const) &BOPDS_DS::Shape, "Selector Returns the shape with index theIndex", py::arg("theIndex"));
cls_BOPDS_DS.def("Index", (Standard_Integer (BOPDS_DS::*)(const TopoDS_Shape &) const) &BOPDS_DS::Index, "Selector Returns the index of the shape theS", py::arg("theS"));
cls_BOPDS_DS.def("PaveBlocksPool", (const BOPDS_VectorOfListOfPaveBlock & (BOPDS_DS::*)() const) &BOPDS_DS::PaveBlocksPool, "Selector Returns the information about pave blocks on source edges");
cls_BOPDS_DS.def("ChangePaveBlocksPool", (BOPDS_VectorOfListOfPaveBlock & (BOPDS_DS::*)()) &BOPDS_DS::ChangePaveBlocksPool, "Selector/Modifier Returns the information about pave blocks on source edges");
cls_BOPDS_DS.def("HasPaveBlocks", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer) const) &BOPDS_DS::HasPaveBlocks, "Query Returns true if the shape with index theIndex has the information about pave blocks", py::arg("theIndex"));
cls_BOPDS_DS.def("PaveBlocks", (const BOPDS_ListOfPaveBlock & (BOPDS_DS::*)(const Standard_Integer) const) &BOPDS_DS::PaveBlocks, "Selector Returns the pave blocks for the shape with index theIndex", py::arg("theIndex"));
cls_BOPDS_DS.def("ChangePaveBlocks", (BOPDS_ListOfPaveBlock & (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::ChangePaveBlocks, "Selector/Modifier Returns the pave blocks for the shape with index theIndex", py::arg("theIndex"));
cls_BOPDS_DS.def("UpdatePaveBlocks", (void (BOPDS_DS::*)()) &BOPDS_DS::UpdatePaveBlocks, "Update the pave blocks for the all shapes in data structure");
cls_BOPDS_DS.def("UpdatePaveBlock", (void (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DS::UpdatePaveBlock, "Update the pave block thePB", py::arg("thePB"));
cls_BOPDS_DS.def("UpdateCommonBlock", (void (BOPDS_DS::*)(const opencascade::handle<BOPDS_CommonBlock> &, const Standard_Real)) &BOPDS_DS::UpdateCommonBlock, "Update the common block theCB", py::arg("theCB"), py::arg("theFuzz"));
cls_BOPDS_DS.def("IsCommonBlock", (Standard_Boolean (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &) const) &BOPDS_DS::IsCommonBlock, "Query Returns true if the pave block is common block", py::arg("thePB"));
cls_BOPDS_DS.def("CommonBlock", (opencascade::handle<BOPDS_CommonBlock> (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &) const) &BOPDS_DS::CommonBlock, "Selector Returns the common block", py::arg("thePB"));
cls_BOPDS_DS.def("SetCommonBlock", (void (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &, const opencascade::handle<BOPDS_CommonBlock> &)) &BOPDS_DS::SetCommonBlock, "Modifier Sets the common block <theCB>", py::arg("thePB"), py::arg("theCB"));
cls_BOPDS_DS.def("RealPaveBlock", (opencascade::handle<BOPDS_PaveBlock> (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &) const) &BOPDS_DS::RealPaveBlock, "Selector Returns the real first pave block", py::arg("thePB"));
cls_BOPDS_DS.def("IsCommonBlockOnEdge", (Standard_Boolean (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &) const) &BOPDS_DS::IsCommonBlockOnEdge, "Query Returns true if common block contains more then one pave block", py::arg("thePB"));
cls_BOPDS_DS.def("FaceInfoPool", (const BOPDS_VectorOfFaceInfo & (BOPDS_DS::*)() const) &BOPDS_DS::FaceInfoPool, "Selector Returns the information about state of faces");
cls_BOPDS_DS.def("HasFaceInfo", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer) const) &BOPDS_DS::HasFaceInfo, "Query Returns true if the shape with index theIndex has the information about state of face", py::arg("theIndex"));
cls_BOPDS_DS.def("FaceInfo", (const BOPDS_FaceInfo & (BOPDS_DS::*)(const Standard_Integer) const) &BOPDS_DS::FaceInfo, "Selector Returns the state of face with index theIndex", py::arg("theIndex"));
cls_BOPDS_DS.def("ChangeFaceInfo", (BOPDS_FaceInfo & (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::ChangeFaceInfo, "Selector/Modifier Returns the state of face with index theIndex", py::arg("theIndex"));
cls_BOPDS_DS.def("UpdateFaceInfoIn", (void (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::UpdateFaceInfoIn, "Update the state In of face with index theIndex", py::arg("theIndex"));
cls_BOPDS_DS.def("UpdateFaceInfoOn", (void (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::UpdateFaceInfoOn, "Update the state On of face with index theIndex", py::arg("theIndex"));
cls_BOPDS_DS.def("FaceInfoOn", (void (BOPDS_DS::*)(const Standard_Integer, BOPDS_IndexedMapOfPaveBlock &, TColStd_MapOfInteger &)) &BOPDS_DS::FaceInfoOn, "Selector Returns the state On [theMPB,theMVP] of face with index theIndex", py::arg("theIndex"), py::arg("theMPB"), py::arg("theMVP"));
cls_BOPDS_DS.def("FaceInfoIn", (void (BOPDS_DS::*)(const Standard_Integer, BOPDS_IndexedMapOfPaveBlock &, TColStd_MapOfInteger &)) &BOPDS_DS::FaceInfoIn, "Selector Returns the state In [theMPB,theMVP] of face with index theIndex", py::arg("theIndex"), py::arg("theMPB"), py::arg("theMVP"));
cls_BOPDS_DS.def("AloneVertices", (void (BOPDS_DS::*)(const Standard_Integer, TColStd_ListOfInteger &) const) &BOPDS_DS::AloneVertices, "Selector Returns the indices of alone vertices for the face with index theIndex", py::arg("theF"), py::arg("theLI"));
cls_BOPDS_DS.def("RefineFaceInfoOn", (void (BOPDS_DS::*)()) &BOPDS_DS::RefineFaceInfoOn, "Refine the state On for the all faces having state information");
cls_BOPDS_DS.def("SubShapesOnIn", (void (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer, TColStd_MapOfInteger &, TColStd_MapOfInteger &, BOPDS_IndexedMapOfPaveBlock &, BOPDS_MapOfPaveBlock &) const) &BOPDS_DS::SubShapesOnIn, "Returns information about ON/IN sub-shapes of the given faces.", py::arg("theNF1"), py::arg("theNF2"), py::arg("theMVOnIn"), py::arg("theMVCommon"), py::arg("thePBOnIn"), py::arg("theCommonPB"));
cls_BOPDS_DS.def("SharedEdges", (void (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer, TColStd_ListOfInteger &, const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_DS::SharedEdges, "Returns the indices of edges that are shared for the faces with indices theF1, theF2", py::arg("theF1"), py::arg("theF2"), py::arg("theLI"), py::arg("theAllocator"));
cls_BOPDS_DS.def("ShapesSD", (TColStd_DataMapOfIntegerInteger & (BOPDS_DS::*)()) &BOPDS_DS::ShapesSD, "Selector Returns the collection same domain shapes");
cls_BOPDS_DS.def("AddShapeSD", (void (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_DS::AddShapeSD, "Modifier Adds the information about same domain shapes with indices theIndex, theIndexSD", py::arg("theIndex"), py::arg("theIndexSD"));
cls_BOPDS_DS.def("HasShapeSD", [](BOPDS_DS &self, const Standard_Integer theIndex, Standard_Integer & theIndexSD){ Standard_Boolean rv = self.HasShapeSD(theIndex, theIndexSD); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theIndexSD); }, "Query Returns true if the shape with index theIndex has the same domain shape. In this case theIndexSD will contain the index of same domain shape found", py::arg("theIndex"), py::arg("theIndexSD"));
cls_BOPDS_DS.def("InterfVV", (BOPDS_VectorOfInterfVV & (BOPDS_DS::*)()) &BOPDS_DS::InterfVV, "Selector/Modifier Returns the collection of interferences Vertex/Vertex");
cls_BOPDS_DS.def("InterfVE", (BOPDS_VectorOfInterfVE & (BOPDS_DS::*)()) &BOPDS_DS::InterfVE, "Selector/Modifier Returns the collection of interferences Vertex/Edge");
cls_BOPDS_DS.def("InterfVF", (BOPDS_VectorOfInterfVF & (BOPDS_DS::*)()) &BOPDS_DS::InterfVF, "Selector/Modifier Returns the collection of interferences Vertex/Face");
cls_BOPDS_DS.def("InterfEE", (BOPDS_VectorOfInterfEE & (BOPDS_DS::*)()) &BOPDS_DS::InterfEE, "Selector/Modifier Returns the collection of interferences Edge/Edge");
cls_BOPDS_DS.def("InterfEF", (BOPDS_VectorOfInterfEF & (BOPDS_DS::*)()) &BOPDS_DS::InterfEF, "Selector/Modifier Returns the collection of interferences Edge/Face");
cls_BOPDS_DS.def("InterfFF", (BOPDS_VectorOfInterfFF & (BOPDS_DS::*)()) &BOPDS_DS::InterfFF, "Selector/Modifier Returns the collection of interferences Face/Face");
cls_BOPDS_DS.def("InterfVZ", (BOPDS_VectorOfInterfVZ & (BOPDS_DS::*)()) &BOPDS_DS::InterfVZ, "Selector/Modifier Returns the collection of interferences Vertex/Solid");
cls_BOPDS_DS.def("InterfEZ", (BOPDS_VectorOfInterfEZ & (BOPDS_DS::*)()) &BOPDS_DS::InterfEZ, "Selector/Modifier Returns the collection of interferences Edge/Solid");
cls_BOPDS_DS.def("InterfFZ", (BOPDS_VectorOfInterfFZ & (BOPDS_DS::*)()) &BOPDS_DS::InterfFZ, "Selector/Modifier Returns the collection of interferences Face/Solid");
cls_BOPDS_DS.def("InterfZZ", (BOPDS_VectorOfInterfZZ & (BOPDS_DS::*)()) &BOPDS_DS::InterfZZ, "Selector/Modifier Returns the collection of interferences Solid/Solid");
cls_BOPDS_DS.def_static("NbInterfTypes_", (Standard_Integer (*)()) &BOPDS_DS::NbInterfTypes, "Returns the number of types of the interferences");
cls_BOPDS_DS.def("AddInterf", (void (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_DS::AddInterf, "Modifier Adds the information about an interference between shapes with indices theI1, theI2 to the summary table of interferences", py::arg("theI1"), py::arg("theI2"));
cls_BOPDS_DS.def("HasInterf", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer) const) &BOPDS_DS::HasInterf, "Query Returns true if the shape with index theI is interferred", py::arg("theI"));
cls_BOPDS_DS.def("HasInterf", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer) const) &BOPDS_DS::HasInterf, "Query Returns true if the shapes with indices theI1, theI2 are interferred", py::arg("theI1"), py::arg("theI2"));
cls_BOPDS_DS.def("HasInterfShapeSubShapes", [](BOPDS_DS &self, const Standard_Integer a0, const Standard_Integer a1) -> Standard_Boolean { return self.HasInterfShapeSubShapes(a0, a1); });
cls_BOPDS_DS.def("HasInterfShapeSubShapes", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean) const) &BOPDS_DS::HasInterfShapeSubShapes, "Query Returns true if the shape with index theI1 is interfered with any sub-shape of the shape with index theI2 (theFlag=true) all sub-shapes of the shape with index theI2 (theFlag=false)", py::arg("theI1"), py::arg("theI2"), py::arg("theFlag"));
cls_BOPDS_DS.def("HasInterfSubShapes", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer) const) &BOPDS_DS::HasInterfSubShapes, "Query Returns true if the shapes with indices theI1, theI2 have interferred sub-shapes", py::arg("theI1"), py::arg("theI2"));
cls_BOPDS_DS.def("Interferences", (const BOPDS_MapOfPair & (BOPDS_DS::*)() const) &BOPDS_DS::Interferences, "Selector Returns the table of interferences");
cls_BOPDS_DS.def("Dump", (void (BOPDS_DS::*)() const) &BOPDS_DS::Dump, "None");
cls_BOPDS_DS.def("IsSubShape", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_DS::IsSubShape, "None", py::arg("theI1"), py::arg("theI2"));
cls_BOPDS_DS.def("Paves", (void (BOPDS_DS::*)(const Standard_Integer, BOPDS_ListOfPave &)) &BOPDS_DS::Paves, "Fills theLP with sorted paves of the shape with index theIndex", py::arg("theIndex"), py::arg("theLP"));
cls_BOPDS_DS.def("UpdateEdgeTolerance", [](BOPDS_DS &self, const Standard_Integer a0, const Standard_Real a1) -> void { return self.UpdateEdgeTolerance(a0, a1); });
cls_BOPDS_DS.def("UpdateEdgeTolerance", (void (BOPDS_DS::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &BOPDS_DS::UpdateEdgeTolerance, "Updates tolerance of the sub-shapes of the shape with index <theIndex>.", py::arg("theIndex"), py::arg("theTolerance"), py::arg("theFuzz"));
cls_BOPDS_DS.def("UpdatePaveBlocksWithSDVertices", (void (BOPDS_DS::*)()) &BOPDS_DS::UpdatePaveBlocksWithSDVertices, "Update the pave blocks for all shapes in data structure");
cls_BOPDS_DS.def("UpdatePaveBlockWithSDVertices", (void (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DS::UpdatePaveBlockWithSDVertices, "Update the pave block for all shapes in data structure", py::arg("thePB"));
cls_BOPDS_DS.def("UpdateCommonBlockWithSDVertices", (void (BOPDS_DS::*)(const opencascade::handle<BOPDS_CommonBlock> &)) &BOPDS_DS::UpdateCommonBlockWithSDVertices, "Update the pave block of the common block for all shapes in data structure", py::arg("theCB"));
cls_BOPDS_DS.def("InitPaveBlocksForVertex", (void (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::InitPaveBlocksForVertex, "None", py::arg("theNV"));
cls_BOPDS_DS.def("ReleasePaveBlocks", (void (BOPDS_DS::*)()) &BOPDS_DS::ReleasePaveBlocks, "Clears information about PaveBlocks for the untouched edges");
cls_BOPDS_DS.def("IsValidShrunkData", (Standard_Boolean (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DS::IsValidShrunkData, "Checks if the existing shrunk data of the pave block is still valid. The shrunk data may become invalid if e.g. the vertices of the pave block have been replaced with the new one with bigger tolerances, or the tolerances of the existing vertices have been increased.", py::arg("thePB"));
cls_BOPDS_DS.def("BuildBndBoxSolid", [](BOPDS_DS &self, const Standard_Integer a0, Bnd_Box & a1) -> void { return self.BuildBndBoxSolid(a0, a1); });
cls_BOPDS_DS.def("BuildBndBoxSolid", (void (BOPDS_DS::*)(const Standard_Integer, Bnd_Box &, const Standard_Boolean)) &BOPDS_DS::BuildBndBoxSolid, "Computes bounding box <theBox> for the solid with DS-index <theIndex>. The flag <theCheckInverted> enables/disables the check of the solid for inverted status. By default the solids will be checked.", py::arg("theIndex"), py::arg("theBox"), py::arg("theCheckInverted"));

// Enums

}