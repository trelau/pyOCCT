/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <BOPCol_BaseAllocator.hxx>
#include <BOPCol_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPDS_IndexRange.hxx>
#include <BOPDS_ShapeInfo.hxx>
#include <TopoDS_Shape.hxx>
#include <BOPDS_VectorOfListOfPaveBlock.hxx>
#include <BOPDS_ListOfPaveBlock.hxx>
#include <Standard_Handle.hxx>
#include <BOPDS_PaveBlock.hxx>
#include <BOPDS_CommonBlock.hxx>
#include <BOPDS_VectorOfFaceInfo.hxx>
#include <BOPDS_FaceInfo.hxx>
#include <BOPDS_IndexedMapOfPaveBlock.hxx>
#include <BOPCol_MapOfInteger.hxx>
#include <BOPCol_ListOfInteger.hxx>
#include <BOPDS_MapOfPaveBlock.hxx>
#include <BOPCol_DataMapOfIntegerInteger.hxx>
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
#include <BOPDS_DS.hxx>
#include <BOPDS_PDS.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <BOPDS_Iterator.hxx>
#include <BOPDS_PIterator.hxx>
#include <BOPDS_Pave.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <Standard_Transient.hxx>
#include <Bnd_Box.hxx>
#include <Standard_Type.hxx>
#include <BOPDS_CoupleOfPaveBlocks.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.hxx>
#include <NCollection_IndexedMap.hxx>
#include <NCollection_DataMap.hxx>
#include <BOPDS_DataMapOfPaveBlockListOfPaveBlock.hxx>
#include <NCollection_Map.hxx>
#include <BOPDS_Pair.hxx>
#include <BOPDS_PairMapHasher.hxx>
#include <IntTools_Curve.hxx>
#include <BOPDS_Curve.hxx>
#include <ApproxInt_KnotTools.hxx>
#include <BOPDS_VectorOfCurve.hxx>
#include <BOPDS_IndexedDataMapOfPaveBlockListOfInteger.hxx>
#include <BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.hxx>
#include <BOPDS_DataMapOfIntegerListOfPaveBlock.hxx>
#include <BOPDS_PassKey.hxx>
#include <BOPDS_PassKeyMapHasher.hxx>
#include <BOPDS_DataMapOfPassKeyListOfPaveBlock.hxx>
#include <BOPDS_DataMapOfPaveBlockCommonBlock.hxx>
#include <BOPDS_DataMapOfPaveBlockListOfInteger.hxx>
#include <BOPDS_DataMapOfShapeCoupleOfPaveBlocks.hxx>
#include <BOPDS_VectorOfIndexRange.hxx>
#include <BOPDS_Tools.hxx>
#include <BOPDS_VectorOfShapeInfo.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <BOPDS_Point.hxx>
#include <BOPDS_VectorOfPoint.hxx>
#include <BOPDS_Interf.hxx>
#include <IntTools_CommonPrt.hxx>
#include <BOPDS_VectorOfPair.hxx>
#include <BOPDS_VectorOfVectorOfPair.hxx>
#include <BOPDS_IteratorSI.hxx>
#include <BOPDS_PassKeyBoolean.hxx>
#include <BOPDS_ListOfPassKeyBoolean.hxx>
#include <BOPDS_MapOfCommonBlock.hxx>
#include <BOPDS_MapOfPassKey.hxx>
#include <BOPDS_MapOfPassKeyBoolean.hxx>
#include <BOPDS_PaveMapHasher.hxx>
#include <BOPDS_MapOfPave.hxx>
#include <BOPDS_PIteratorSI.hxx>
#include <BOPDS_SubIterator.hxx>
#include <BOPDS_VectorOfListOfPassKeyBoolean.hxx>
#include <NCollection_Array1.hxx>
#include <BOPDS_VectorOfPave.hxx>
#include <NCollection_Templates.hpp>
#include <BOPCol_Templates.hpp>

PYBIND11_MODULE(BOPDS, mod) {

	// IMPORT
	py::module::import("OCCT.BOPCol");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.IntTools");
	py::module::import("OCCT.ApproxInt");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PassKey.lxx
	mod.def("NormalizedId", (Standard_Integer (*)(const Standard_Integer, const Standard_Integer)) &NormalizedId, "None", py::arg("aId"), py::arg("aDiv"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PassKey.lxx
	mod.def("SortShell", (void (*)(const Standard_Integer, Standard_Integer *)) &SortShell, "None", py::arg("n"), py::arg("a"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DS.hxx
	py::class_<BOPDS_DS, std::unique_ptr<BOPDS_DS, Deleter<BOPDS_DS>>> cls_BOPDS_DS(mod, "BOPDS_DS", "The class BOPDS_DS provides the control of data structure for the algorithms in the Boolean Component such as General Fuse, Boolean operations, Section, Maker Volume, Splitter and Cells Builder.");
	cls_BOPDS_DS.def(py::init<>());
	cls_BOPDS_DS.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPDS_DS.def("Clear", (void (BOPDS_DS::*)()) &BOPDS_DS::Clear, "Clears the contents");
	cls_BOPDS_DS.def("Allocator", (const BOPCol_BaseAllocator & (BOPDS_DS::*)() const ) &BOPDS_DS::Allocator, "Selector");
	cls_BOPDS_DS.def("SetArguments", (void (BOPDS_DS::*)(const BOPCol_ListOfShape &)) &BOPDS_DS::SetArguments, "Modifier Sets the arguments [theLS] of an operation", py::arg("theLS"));
	cls_BOPDS_DS.def("Arguments", (const BOPCol_ListOfShape & (BOPDS_DS::*)() const ) &BOPDS_DS::Arguments, "Selector Returns the arguments of an operation");
	cls_BOPDS_DS.def("Init", [](BOPDS_DS &self) -> void { return self.Init(); });
	cls_BOPDS_DS.def("Init", (void (BOPDS_DS::*)(const Standard_Real)) &BOPDS_DS::Init, "Initializes the data structure for the arguments", py::arg("theFuzz"));
	cls_BOPDS_DS.def("NbShapes", (Standard_Integer (BOPDS_DS::*)() const ) &BOPDS_DS::NbShapes, "Selector Returns the total number of shapes stored");
	cls_BOPDS_DS.def("NbSourceShapes", (Standard_Integer (BOPDS_DS::*)() const ) &BOPDS_DS::NbSourceShapes, "Selector Returns the total number of source shapes stored");
	cls_BOPDS_DS.def("NbRanges", (Standard_Integer (BOPDS_DS::*)() const ) &BOPDS_DS::NbRanges, "Selector Returns the number of index ranges");
	cls_BOPDS_DS.def("Range", (const BOPDS_IndexRange & (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::Range, "Selector Returns the index range 'i'", py::arg("theIndex"));
	cls_BOPDS_DS.def("Rank", (Standard_Integer (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::Rank, "Selector Returns the rank of the shape of index 'i'", py::arg("theIndex"));
	cls_BOPDS_DS.def("IsNewShape", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::IsNewShape, "Returns true if the shape of index 'i' is not the source shape/sub-shape", py::arg("theIndex"));
	cls_BOPDS_DS.def("Append", (Standard_Integer (BOPDS_DS::*)(const BOPDS_ShapeInfo &)) &BOPDS_DS::Append, "Modifier Appends the information about the shape [theSI] to the data structure Returns the index of theSI in the data structure", py::arg("theSI"));
	cls_BOPDS_DS.def("Append", (Standard_Integer (BOPDS_DS::*)(const TopoDS_Shape &)) &BOPDS_DS::Append, "Modifier Appends the default information about the shape [theS] to the data structure Returns the index of theS in the data structure", py::arg("theS"));
	cls_BOPDS_DS.def("ShapeInfo", (const BOPDS_ShapeInfo & (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::ShapeInfo, "Selector Returns the information about the shape with index theIndex", py::arg("theIndex"));
	cls_BOPDS_DS.def("ChangeShapeInfo", (BOPDS_ShapeInfo & (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::ChangeShapeInfo, "Selector/Modifier Returns the information about the shape with index theIndex", py::arg("theIndex"));
	cls_BOPDS_DS.def("Shape", (const TopoDS_Shape & (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::Shape, "Selector Returns the shape with index theIndex", py::arg("theIndex"));
	cls_BOPDS_DS.def("Index", (Standard_Integer (BOPDS_DS::*)(const TopoDS_Shape &) const ) &BOPDS_DS::Index, "Selector Returns the index of the shape theS", py::arg("theS"));
	cls_BOPDS_DS.def("PaveBlocksPool", (const BOPDS_VectorOfListOfPaveBlock & (BOPDS_DS::*)() const ) &BOPDS_DS::PaveBlocksPool, "Selector Returns the information about pave blocks on source edges");
	cls_BOPDS_DS.def("ChangePaveBlocksPool", (BOPDS_VectorOfListOfPaveBlock & (BOPDS_DS::*)()) &BOPDS_DS::ChangePaveBlocksPool, "Selector/Modifier Returns the information about pave blocks on source edges");
	cls_BOPDS_DS.def("HasPaveBlocks", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::HasPaveBlocks, "Query Returns true if the shape with index theIndex has the information about pave blocks", py::arg("theIndex"));
	cls_BOPDS_DS.def("PaveBlocks", (const BOPDS_ListOfPaveBlock & (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::PaveBlocks, "Selector Returns the pave blocks for the shape with index theIndex", py::arg("theIndex"));
	cls_BOPDS_DS.def("ChangePaveBlocks", (BOPDS_ListOfPaveBlock & (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::ChangePaveBlocks, "Selector/Modifier Returns the pave blocks for the shape with index theIndex", py::arg("theIndex"));
	cls_BOPDS_DS.def("UpdatePaveBlocks", (void (BOPDS_DS::*)()) &BOPDS_DS::UpdatePaveBlocks, "Update the pave blocks for the all shapes in data structure");
	cls_BOPDS_DS.def("UpdatePaveBlock", (void (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DS::UpdatePaveBlock, "Update the pave block thePB", py::arg("thePB"));
	cls_BOPDS_DS.def("UpdateCommonBlock", (void (BOPDS_DS::*)(const opencascade::handle<BOPDS_CommonBlock> &, const Standard_Real)) &BOPDS_DS::UpdateCommonBlock, "Update the common block theCB", py::arg("theCB"), py::arg("theFuzz"));
	cls_BOPDS_DS.def("IsCommonBlock", (Standard_Boolean (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DS::IsCommonBlock, "Query Returns true if the pave block is common block", py::arg("thePB"));
	cls_BOPDS_DS.def("CommonBlock", (opencascade::handle<BOPDS_CommonBlock> (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DS::CommonBlock, "Selector Returns the common block", py::arg("thePB"));
	cls_BOPDS_DS.def("SetCommonBlock", (void (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &, const opencascade::handle<BOPDS_CommonBlock> &)) &BOPDS_DS::SetCommonBlock, "Modifier Sets the common block <theCB>", py::arg("thePB"), py::arg("theCB"));
	cls_BOPDS_DS.def("RealPaveBlock", (opencascade::handle<BOPDS_PaveBlock> (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DS::RealPaveBlock, "Selector Returns the real first pave block", py::arg("thePB"));
	cls_BOPDS_DS.def("IsCommonBlockOnEdge", (Standard_Boolean (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DS::IsCommonBlockOnEdge, "Query Returns true if common block contains more then one pave block", py::arg("thePB"));
	cls_BOPDS_DS.def("FaceInfoPool", (const BOPDS_VectorOfFaceInfo & (BOPDS_DS::*)() const ) &BOPDS_DS::FaceInfoPool, "Selector Returns the information about state of faces");
	cls_BOPDS_DS.def("HasFaceInfo", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::HasFaceInfo, "Query Returns true if the shape with index theIndex has the information about state of face", py::arg("theIndex"));
	cls_BOPDS_DS.def("FaceInfo", (const BOPDS_FaceInfo & (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::FaceInfo, "Selector Returns the state of face with index theIndex", py::arg("theIndex"));
	cls_BOPDS_DS.def("ChangeFaceInfo", (BOPDS_FaceInfo & (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::ChangeFaceInfo, "Selector/Modifier Returns the state of face with index theIndex", py::arg("theIndex"));
	cls_BOPDS_DS.def("UpdateFaceInfoIn", (void (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::UpdateFaceInfoIn, "Update the state In of face with index theIndex", py::arg("theIndex"));
	cls_BOPDS_DS.def("UpdateFaceInfoOn", (void (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::UpdateFaceInfoOn, "Update the state On of face with index theIndex", py::arg("theIndex"));
	cls_BOPDS_DS.def("FaceInfoOn", (void (BOPDS_DS::*)(const Standard_Integer, BOPDS_IndexedMapOfPaveBlock &, BOPCol_MapOfInteger &)) &BOPDS_DS::FaceInfoOn, "Selector Returns the state On [theMPB,theMVP] of face with index theIndex", py::arg("theIndex"), py::arg("theMPB"), py::arg("theMVP"));
	cls_BOPDS_DS.def("FaceInfoIn", (void (BOPDS_DS::*)(const Standard_Integer, BOPDS_IndexedMapOfPaveBlock &, BOPCol_MapOfInteger &)) &BOPDS_DS::FaceInfoIn, "Selector Returns the state In [theMPB,theMVP] of face with index theIndex", py::arg("theIndex"), py::arg("theMPB"), py::arg("theMVP"));
	cls_BOPDS_DS.def("AloneVertices", (void (BOPDS_DS::*)(const Standard_Integer, BOPCol_ListOfInteger &) const ) &BOPDS_DS::AloneVertices, "Selector Returns the indices of alone vertices for the face with index theIndex", py::arg("theF"), py::arg("theLI"));
	cls_BOPDS_DS.def("RefineFaceInfoOn", (void (BOPDS_DS::*)()) &BOPDS_DS::RefineFaceInfoOn, "Refine the state On for the all faces having state information");
	cls_BOPDS_DS.def("SubShapesOnIn", (void (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer, BOPCol_MapOfInteger &, BOPDS_IndexedMapOfPaveBlock &, BOPDS_MapOfPaveBlock &) const ) &BOPDS_DS::SubShapesOnIn, "Returns information about ON/IN subshapes of the given faces.", py::arg("theF1"), py::arg("theF2"), py::arg("theMVOnIn"), py::arg("thePBOnIn"), py::arg("theCommonPB"));
	cls_BOPDS_DS.def("SharedEdges", (void (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer, BOPCol_ListOfInteger &, const BOPCol_BaseAllocator &)) &BOPDS_DS::SharedEdges, "Returns the indices of edges that are shared for the faces with indices theF1, theF2", py::arg("theF1"), py::arg("theF2"), py::arg("theLI"), py::arg("theAllocator"));
	cls_BOPDS_DS.def("ShapesSD", (BOPCol_DataMapOfIntegerInteger & (BOPDS_DS::*)()) &BOPDS_DS::ShapesSD, "Selector Returns the collection same domain shapes");
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
	cls_BOPDS_DS.def("HasInterf", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::HasInterf, "Query Returns true if the shape with index theI is interferred", py::arg("theI"));
	cls_BOPDS_DS.def("HasInterf", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer) const ) &BOPDS_DS::HasInterf, "Query Returns true if the shapes with indices theI1, theI2 are interferred", py::arg("theI1"), py::arg("theI2"));
	cls_BOPDS_DS.def("HasInterfShapeSubShapes", [](BOPDS_DS &self, const Standard_Integer a0, const Standard_Integer a1) -> Standard_Boolean { return self.HasInterfShapeSubShapes(a0, a1); }, py::arg("theI1"), py::arg("theI2"));
	cls_BOPDS_DS.def("HasInterfShapeSubShapes", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean) const ) &BOPDS_DS::HasInterfShapeSubShapes, "Query Returns true if the shape with index theI1 is interfered with any sub-shape of the shape with index theI2 (theFlag=true) all sub-shapes of the shape with index theI2 (theFlag=false)", py::arg("theI1"), py::arg("theI2"), py::arg("theFlag"));
	cls_BOPDS_DS.def("HasInterfSubShapes", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer) const ) &BOPDS_DS::HasInterfSubShapes, "Query Returns true if the shapes with indices theI1, theI2 have interferred sub-shapes", py::arg("theI1"), py::arg("theI2"));
	cls_BOPDS_DS.def("Interferences", (const BOPDS_MapOfPair & (BOPDS_DS::*)() const ) &BOPDS_DS::Interferences, "Selector Returns the table of interferences");
	// FIXME cls_BOPDS_DS.def("Dump", (void (BOPDS_DS::*)() const ) &BOPDS_DS::Dump, "None");
	cls_BOPDS_DS.def("IsSubShape", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_DS::IsSubShape, "None", py::arg("theI1"), py::arg("theI2"));
	cls_BOPDS_DS.def("Paves", (void (BOPDS_DS::*)(const Standard_Integer, BOPDS_ListOfPave &)) &BOPDS_DS::Paves, "Fills theLP with sorted paves of the shape with index theIndex", py::arg("theIndex"), py::arg("theLP"));
	cls_BOPDS_DS.def("UpdateEdgeTolerance", [](BOPDS_DS &self, const Standard_Integer a0, const Standard_Real a1) -> void { return self.UpdateEdgeTolerance(a0, a1); }, py::arg("theIndex"), py::arg("theTolerance"));
	cls_BOPDS_DS.def("UpdateEdgeTolerance", (void (BOPDS_DS::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &BOPDS_DS::UpdateEdgeTolerance, "Updates tolerance of the sub-shapes of the shape with index <theIndex>.", py::arg("theIndex"), py::arg("theTolerance"), py::arg("theFuzz"));
	cls_BOPDS_DS.def("UpdatePaveBlocksWithSDVertices", (void (BOPDS_DS::*)()) &BOPDS_DS::UpdatePaveBlocksWithSDVertices, "Update the pave blocks for all shapes in data structure");
	cls_BOPDS_DS.def("UpdatePaveBlockWithSDVertices", (void (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DS::UpdatePaveBlockWithSDVertices, "Update the pave block for all shapes in data structure", py::arg("thePB"));
	cls_BOPDS_DS.def("UpdateCommonBlockWithSDVertices", (void (BOPDS_DS::*)(const opencascade::handle<BOPDS_CommonBlock> &)) &BOPDS_DS::UpdateCommonBlockWithSDVertices, "Update the pave block of the common block for all shapes in data structure", py::arg("theCB"));
	cls_BOPDS_DS.def("InitPaveBlocksForVertex", (void (BOPDS_DS::*)(const Standard_Integer)) &BOPDS_DS::InitPaveBlocksForVertex, "None", py::arg("theNV"));
	cls_BOPDS_DS.def("ReleasePaveBlocks", (void (BOPDS_DS::*)()) &BOPDS_DS::ReleasePaveBlocks, "Clears information about PaveBlocks for the untouched edges");
	cls_BOPDS_DS.def("IsValidShrunkData", (Standard_Boolean (BOPDS_DS::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DS::IsValidShrunkData, "Checks if the existing shrunk data of the pave block is still valid. The shrunk data may become invalid if e.g. the vertices of the pave block have been replaced with the new one with bigger tolerances, or the tolerances of the existing vertices have been increased.", py::arg("thePB"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Iterator.hxx
	py::class_<BOPDS_Iterator, std::unique_ptr<BOPDS_Iterator, Deleter<BOPDS_Iterator>>> cls_BOPDS_Iterator(mod, "BOPDS_Iterator", "The class BOPDS_Iterator is 1.to compute intersections between BRep sub-shapes of arguments of an operation (see the class BOPDS_DS) in terms of theirs bounding boxes 2.provides interface to iterare the pairs of intersected sub-shapes of given type");
	cls_BOPDS_Iterator.def(py::init<>());
	cls_BOPDS_Iterator.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPDS_Iterator.def("SetDS", (void (BOPDS_Iterator::*)(const BOPDS_PDS &)) &BOPDS_Iterator::SetDS, "Modifier Sets the data structure <pDS> to process", py::arg("pDS"));
	cls_BOPDS_Iterator.def("DS", (const BOPDS_DS & (BOPDS_Iterator::*)() const ) &BOPDS_Iterator::DS, "Selector Returns the data structure");
	cls_BOPDS_Iterator.def("Initialize", (void (BOPDS_Iterator::*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &BOPDS_Iterator::Initialize, "Initializes the iterator theType1 - the first type of shape theType2 - the second type of shape", py::arg("theType1"), py::arg("theType2"));
	cls_BOPDS_Iterator.def("More", (Standard_Boolean (BOPDS_Iterator::*)() const ) &BOPDS_Iterator::More, "Returns true if still there are pairs of intersected shapes");
	cls_BOPDS_Iterator.def("Next", (void (BOPDS_Iterator::*)()) &BOPDS_Iterator::Next, "Moves iterations ahead");
	cls_BOPDS_Iterator.def("Value", [](BOPDS_Iterator &self, Standard_Integer & theIndex1, Standard_Integer & theIndex2){ self.Value(theIndex1, theIndex2); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndex1, theIndex2); }, "Returns indices (DS) of intersected shapes theIndex1 - the index of the first shape theIndex2 - the index of the second shape", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_Iterator.def("Prepare", (void (BOPDS_Iterator::*)()) &BOPDS_Iterator::Prepare, "Perform the intersection algorithm and prepare the results to be used");
	cls_BOPDS_Iterator.def("ExpectedLength", (Standard_Integer (BOPDS_Iterator::*)() const ) &BOPDS_Iterator::ExpectedLength, "Returns the number of intersections founded");
	cls_BOPDS_Iterator.def("BlockLength", (Standard_Integer (BOPDS_Iterator::*)() const ) &BOPDS_Iterator::BlockLength, "Returns the block length");
	cls_BOPDS_Iterator.def("SetRunParallel", (void (BOPDS_Iterator::*)(const Standard_Boolean)) &BOPDS_Iterator::SetRunParallel, "Set the flag of parallel processing if <theFlag> is true the parallel processing is switched on if <theFlag> is false the parallel processing is switched off", py::arg("theFlag"));
	cls_BOPDS_Iterator.def("RunParallel", (Standard_Boolean (BOPDS_Iterator::*)() const ) &BOPDS_Iterator::RunParallel, "Returns the flag of parallel processing");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Pave.hxx
	py::class_<BOPDS_Pave, std::unique_ptr<BOPDS_Pave, Deleter<BOPDS_Pave>>> cls_BOPDS_Pave(mod, "BOPDS_Pave", "The class BOPDS_Pave is to store information about vertex on an edge");
	cls_BOPDS_Pave.def(py::init<>());
	cls_BOPDS_Pave.def("SetIndex", (void (BOPDS_Pave::*)(const Standard_Integer)) &BOPDS_Pave::SetIndex, "Modifier Sets the index of vertex <theIndex>", py::arg("theIndex"));
	cls_BOPDS_Pave.def("Index", (Standard_Integer (BOPDS_Pave::*)() const ) &BOPDS_Pave::Index, "Selector Returns the index of vertex");
	cls_BOPDS_Pave.def("SetParameter", (void (BOPDS_Pave::*)(const Standard_Real)) &BOPDS_Pave::SetParameter, "Modifier Sets the parameter of vertex <theParameter>", py::arg("theParameter"));
	cls_BOPDS_Pave.def("Parameter", (Standard_Real (BOPDS_Pave::*)() const ) &BOPDS_Pave::Parameter, "Selector Returns the parameter of vertex");
	cls_BOPDS_Pave.def("Contents", [](BOPDS_Pave &self, Standard_Integer & theIndex, Standard_Real & theParameter){ self.Contents(theIndex, theParameter); return std::tuple<Standard_Integer &, Standard_Real &>(theIndex, theParameter); }, "Selector Returns the index of vertex <theIndex> Returns the parameter of vertex <theParameter>", py::arg("theIndex"), py::arg("theParameter"));
	cls_BOPDS_Pave.def("IsLess", (Standard_Boolean (BOPDS_Pave::*)(const BOPDS_Pave &) const ) &BOPDS_Pave::IsLess, "Query Returns true if thr parameter od this is less than the parameter of <theOther>", py::arg("theOther"));
	cls_BOPDS_Pave.def("__lt__", (Standard_Boolean (BOPDS_Pave::*)(const BOPDS_Pave &) const ) &BOPDS_Pave::operator<, py::is_operator(), "None", py::arg("theOther"));
	cls_BOPDS_Pave.def("IsEqual", (Standard_Boolean (BOPDS_Pave::*)(const BOPDS_Pave &) const ) &BOPDS_Pave::IsEqual, "Query Returns true if thr parameter od this is equal to the parameter of <theOther>", py::arg("theOther"));
	cls_BOPDS_Pave.def("__eq__", (Standard_Boolean (BOPDS_Pave::*)(const BOPDS_Pave &) const ) &BOPDS_Pave::operator==, py::is_operator(), "None", py::arg("theOther"));
	// FIXME cls_BOPDS_Pave.def("Dump", (void (BOPDS_Pave::*)() const ) &BOPDS_Pave::Dump, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PaveBlock.hxx
	py::class_<BOPDS_PaveBlock, opencascade::handle<BOPDS_PaveBlock>, Standard_Transient> cls_BOPDS_PaveBlock(mod, "BOPDS_PaveBlock", "The class BOPDS_PaveBlock is to store the information about pave block on an edge. Two adjacent paves on edge make up pave block.");
	cls_BOPDS_PaveBlock.def(py::init<>());
	cls_BOPDS_PaveBlock.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPDS_PaveBlock.def("SetPave1", (void (BOPDS_PaveBlock::*)(const BOPDS_Pave &)) &BOPDS_PaveBlock::SetPave1, "Modifier Sets the first pave <thePave>", py::arg("thePave"));
	cls_BOPDS_PaveBlock.def("Pave1", (const BOPDS_Pave & (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::Pave1, "Selector Returns the first pave");
	cls_BOPDS_PaveBlock.def("SetPave2", (void (BOPDS_PaveBlock::*)(const BOPDS_Pave &)) &BOPDS_PaveBlock::SetPave2, "Modifier Sets the second pave <thePave>", py::arg("thePave"));
	cls_BOPDS_PaveBlock.def("Pave2", (const BOPDS_Pave & (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::Pave2, "Selector Returns the second pave");
	cls_BOPDS_PaveBlock.def("SetEdge", (void (BOPDS_PaveBlock::*)(const Standard_Integer)) &BOPDS_PaveBlock::SetEdge, "Modifier Sets the index of edge of pave block <theEdge>", py::arg("theEdge"));
	cls_BOPDS_PaveBlock.def("Edge", (Standard_Integer (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::Edge, "Selector Returns the index of edge of pave block");
	cls_BOPDS_PaveBlock.def("HasEdge", (Standard_Boolean (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::HasEdge, "Query Returns true if the pave block has edge");
	cls_BOPDS_PaveBlock.def("HasEdge", [](BOPDS_PaveBlock &self, Standard_Integer & theEdge){ Standard_Boolean rv = self.HasEdge(theEdge); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theEdge); }, "Query Returns true if the pave block has edge Returns the index of edge <theEdge>", py::arg("theEdge"));
	cls_BOPDS_PaveBlock.def("SetOriginalEdge", (void (BOPDS_PaveBlock::*)(const Standard_Integer)) &BOPDS_PaveBlock::SetOriginalEdge, "Modifier Sets the index of original edge of the pave block <theEdge>", py::arg("theEdge"));
	cls_BOPDS_PaveBlock.def("OriginalEdge", (Standard_Integer (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::OriginalEdge, "Selector Returns the index of original edge of pave block");
	cls_BOPDS_PaveBlock.def("IsSplitEdge", (Standard_Boolean (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::IsSplitEdge, "Query Returns true if the edge is equal to the original edge of the pave block");
	cls_BOPDS_PaveBlock.def("Range", [](BOPDS_PaveBlock &self, Standard_Real & theT1, Standard_Real & theT2){ self.Range(theT1, theT2); return std::tuple<Standard_Real &, Standard_Real &>(theT1, theT2); }, "Selector Returns the parametric range <theT1,theT2> of the pave block", py::arg("theT1"), py::arg("theT2"));
	cls_BOPDS_PaveBlock.def("HasSameBounds", (Standard_Boolean (BOPDS_PaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_PaveBlock::HasSameBounds, "Query Returns true if the pave block has pave indices that equal to the pave indices of the pave block <theOther>", py::arg("theOther"));
	cls_BOPDS_PaveBlock.def("Indices", [](BOPDS_PaveBlock &self, Standard_Integer & theIndex1, Standard_Integer & theIndex2){ self.Indices(theIndex1, theIndex2); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndex1, theIndex2); }, "Selector Returns the pave indices <theIndex1,theIndex2> of the pave block", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_PaveBlock.def("IsToUpdate", (Standard_Boolean (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::IsToUpdate, "Query Returns true if the pave block contains extra paves");
	cls_BOPDS_PaveBlock.def("AppendExtPave", (void (BOPDS_PaveBlock::*)(const BOPDS_Pave &)) &BOPDS_PaveBlock::AppendExtPave, "Modifier Appends extra paves <thePave>", py::arg("thePave"));
	cls_BOPDS_PaveBlock.def("AppendExtPave1", (void (BOPDS_PaveBlock::*)(const BOPDS_Pave &)) &BOPDS_PaveBlock::AppendExtPave1, "Modifier Appends extra pave <thePave>", py::arg("thePave"));
	cls_BOPDS_PaveBlock.def("RemoveExtPave", (void (BOPDS_PaveBlock::*)(const Standard_Integer)) &BOPDS_PaveBlock::RemoveExtPave, "Modifier Removes a pave with the given vertex number from extra paves", py::arg("theVertNum"));
	cls_BOPDS_PaveBlock.def("ExtPaves", (const BOPDS_ListOfPave & (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::ExtPaves, "Selector Returns the extra paves");
	cls_BOPDS_PaveBlock.def("ChangeExtPaves", (BOPDS_ListOfPave & (BOPDS_PaveBlock::*)()) &BOPDS_PaveBlock::ChangeExtPaves, "Selector / Modifier Returns the extra paves");
	cls_BOPDS_PaveBlock.def("Update", [](BOPDS_PaveBlock &self, BOPDS_ListOfPaveBlock & a0) -> void { return self.Update(a0); }, py::arg("theLPB"));
	cls_BOPDS_PaveBlock.def("Update", (void (BOPDS_PaveBlock::*)(BOPDS_ListOfPaveBlock &, const Standard_Boolean)) &BOPDS_PaveBlock::Update, "Modifier Updates the pave block. The extra paves are used to create new pave blocks <theLPB>. <theFlag> - if true, the first pave and the second pave are used to produce new pave blocks.", py::arg("theLPB"), py::arg("theFlag"));
	cls_BOPDS_PaveBlock.def("ContainsParameter", [](BOPDS_PaveBlock &self, const Standard_Real thePrm, const Standard_Real theTol, Standard_Integer & theInd){ Standard_Boolean rv = self.ContainsParameter(thePrm, theTol, theInd); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theInd); }, "Query Returns true if the extra paves contain the pave with given value of the parameter <thePrm> <theTol> - the value of the tolerance to compare <theInd> - index of the found pave", py::arg("thePrm"), py::arg("theTol"), py::arg("theInd"));
	cls_BOPDS_PaveBlock.def("SetShrunkData", (void (BOPDS_PaveBlock::*)(const Standard_Real, const Standard_Real, const Bnd_Box &, const Standard_Boolean)) &BOPDS_PaveBlock::SetShrunkData, "Modifier Sets the shrunk data for the pave block <theTS1>, <theTS2> - shrunk range <theBox> - the bounding box <theIsSplittable> - defines whether the edge can be split", py::arg("theTS1"), py::arg("theTS2"), py::arg("theBox"), py::arg("theIsSplittable"));
	cls_BOPDS_PaveBlock.def("ShrunkData", [](BOPDS_PaveBlock &self, Standard_Real & theTS1, Standard_Real & theTS2, Bnd_Box & theBox, Standard_Boolean & theIsSplittable){ self.ShrunkData(theTS1, theTS2, theBox, theIsSplittable); return std::tuple<Standard_Real &, Standard_Real &, Standard_Boolean &>(theTS1, theTS2, theIsSplittable); }, "Selector Returns the shrunk data for the pave block <theTS1>, <theTS2> - shrunk range <theBox> - the bounding box <theIsSplittable> - defines whether the edge can be split", py::arg("theTS1"), py::arg("theTS2"), py::arg("theBox"), py::arg("theIsSplittable"));
	cls_BOPDS_PaveBlock.def("HasShrunkData", (Standard_Boolean (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::HasShrunkData, "Query Returns true if the pave block contains the shrunk data");
	// FIXME cls_BOPDS_PaveBlock.def("Dump", (void (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::Dump, "None");
	cls_BOPDS_PaveBlock.def("IsSplittable", (Standard_Boolean (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::IsSplittable, "Query Returns FALSE if the pave block has a too short shrunk range and cannot be split, otherwise returns TRUE");
	cls_BOPDS_PaveBlock.def_static("get_type_name_", (const char * (*)()) &BOPDS_PaveBlock::get_type_name, "None");
	cls_BOPDS_PaveBlock.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPDS_PaveBlock::get_type_descriptor, "None");
	cls_BOPDS_PaveBlock.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_CoupleOfPaveBlocks.hxx
	py::class_<BOPDS_CoupleOfPaveBlocks, std::unique_ptr<BOPDS_CoupleOfPaveBlocks, Deleter<BOPDS_CoupleOfPaveBlocks>>> cls_BOPDS_CoupleOfPaveBlocks(mod, "BOPDS_CoupleOfPaveBlocks", "The Class BOPDS_CoupleOfPaveBlocks is to store the information about two pave blocks and some satellite information");
	cls_BOPDS_CoupleOfPaveBlocks.def(py::init<>());
	cls_BOPDS_CoupleOfPaveBlocks.def(py::init<const opencascade::handle<BOPDS_PaveBlock> &, const opencascade::handle<BOPDS_PaveBlock> &>(), py::arg("thePB1"), py::arg("thePB2"));
	cls_BOPDS_CoupleOfPaveBlocks.def("SetIndex", (void (BOPDS_CoupleOfPaveBlocks::*)(const Standard_Integer)) &BOPDS_CoupleOfPaveBlocks::SetIndex, "Sets an index", py::arg("theIndex"));
	cls_BOPDS_CoupleOfPaveBlocks.def("Index", (Standard_Integer (BOPDS_CoupleOfPaveBlocks::*)() const ) &BOPDS_CoupleOfPaveBlocks::Index, "Returns the index");
	cls_BOPDS_CoupleOfPaveBlocks.def("SetIndexInterf", (void (BOPDS_CoupleOfPaveBlocks::*)(const Standard_Integer)) &BOPDS_CoupleOfPaveBlocks::SetIndexInterf, "Sets an index of an interference", py::arg("theIndex"));
	cls_BOPDS_CoupleOfPaveBlocks.def("IndexInterf", (Standard_Integer (BOPDS_CoupleOfPaveBlocks::*)() const ) &BOPDS_CoupleOfPaveBlocks::IndexInterf, "Returns the index of an interference");
	cls_BOPDS_CoupleOfPaveBlocks.def("SetPaveBlocks", (void (BOPDS_CoupleOfPaveBlocks::*)(const opencascade::handle<BOPDS_PaveBlock> &, const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_CoupleOfPaveBlocks::SetPaveBlocks, "Sets pave blocks", py::arg("thePB1"), py::arg("thePB2"));
	cls_BOPDS_CoupleOfPaveBlocks.def("PaveBlocks", (void (BOPDS_CoupleOfPaveBlocks::*)(opencascade::handle<BOPDS_PaveBlock> &, opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_CoupleOfPaveBlocks::PaveBlocks, "Returns pave blocks", py::arg("thePB1"), py::arg("thePB2"));
	cls_BOPDS_CoupleOfPaveBlocks.def("SetPaveBlock1", (void (BOPDS_CoupleOfPaveBlocks::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_CoupleOfPaveBlocks::SetPaveBlock1, "Sets the first pave block", py::arg("thePB"));
	cls_BOPDS_CoupleOfPaveBlocks.def("PaveBlock1", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_CoupleOfPaveBlocks::*)() const ) &BOPDS_CoupleOfPaveBlocks::PaveBlock1, "Returns the first pave block");
	cls_BOPDS_CoupleOfPaveBlocks.def("SetPaveBlock2", (void (BOPDS_CoupleOfPaveBlocks::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_CoupleOfPaveBlocks::SetPaveBlock2, "Sets the second pave block", py::arg("thePB"));
	cls_BOPDS_CoupleOfPaveBlocks.def("PaveBlock2", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_CoupleOfPaveBlocks::*)() const ) &BOPDS_CoupleOfPaveBlocks::PaveBlock2, "Returns the second pave block");
	cls_BOPDS_CoupleOfPaveBlocks.def("SetTolerance", (void (BOPDS_CoupleOfPaveBlocks::*)(const Standard_Real)) &BOPDS_CoupleOfPaveBlocks::SetTolerance, "Sets the tolerance associated with this couple", py::arg("theTol"));
	cls_BOPDS_CoupleOfPaveBlocks.def("Tolerance", (Standard_Real (BOPDS_CoupleOfPaveBlocks::*)() const ) &BOPDS_CoupleOfPaveBlocks::Tolerance, "Returns the tolerance associated with this couple");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Pair.hxx
	py::class_<BOPDS_Pair, std::unique_ptr<BOPDS_Pair, Deleter<BOPDS_Pair>>> cls_BOPDS_Pair(mod, "BOPDS_Pair", "The class is to provide the pair of indices of interfering shapes.");
	cls_BOPDS_Pair.def(py::init<>());
	cls_BOPDS_Pair.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_Pair.def("SetIndices", (void (BOPDS_Pair::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_Pair::SetIndices, "Sets the indices", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_Pair.def("Indices", [](BOPDS_Pair &self, Standard_Integer & theIndex1, Standard_Integer & theIndex2){ self.Indices(theIndex1, theIndex2); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndex1, theIndex2); }, "Gets the indices", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_Pair.def("__lt__", (Standard_Boolean (BOPDS_Pair::*)(const BOPDS_Pair &) const ) &BOPDS_Pair::operator<, py::is_operator(), "Operator less", py::arg("theOther"));
	cls_BOPDS_Pair.def("IsEqual", (Standard_Boolean (BOPDS_Pair::*)(const BOPDS_Pair &) const ) &BOPDS_Pair::IsEqual, "Returns true if the Pair is equal to <the theOther>", py::arg("theOther"));
	cls_BOPDS_Pair.def("HashCode", (Standard_Integer (BOPDS_Pair::*)(const Standard_Integer) const ) &BOPDS_Pair::HashCode, "Returns hash code", py::arg("theUpper"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PairMapHasher.hxx
	py::class_<BOPDS_PairMapHasher, std::unique_ptr<BOPDS_PairMapHasher, Deleter<BOPDS_PairMapHasher>>> cls_BOPDS_PairMapHasher(mod, "BOPDS_PairMapHasher", "None");
	cls_BOPDS_PairMapHasher.def(py::init<>());
	cls_BOPDS_PairMapHasher.def_static("HashCode_", (Standard_Integer (*)(const BOPDS_Pair &, const Standard_Integer)) &BOPDS_PairMapHasher::HashCode, "None", py::arg("thePair"), py::arg("Upper"));
	cls_BOPDS_PairMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const BOPDS_Pair &, const BOPDS_Pair &)) &BOPDS_PairMapHasher::IsEqual, "None", py::arg("thePair1"), py::arg("thePair2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Curve.hxx
	py::class_<BOPDS_Curve, std::unique_ptr<BOPDS_Curve, Deleter<BOPDS_Curve>>> cls_BOPDS_Curve(mod, "BOPDS_Curve", "The class BOPDS_Curve is to store the information about intersection curve");
	cls_BOPDS_Curve.def(py::init<>());
	cls_BOPDS_Curve.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPDS_Curve.def("SetCurve", (void (BOPDS_Curve::*)(const IntTools_Curve &)) &BOPDS_Curve::SetCurve, "Modifier Sets the curve <theC>", py::arg("theC"));
	cls_BOPDS_Curve.def("Curve", (const IntTools_Curve & (BOPDS_Curve::*)() const ) &BOPDS_Curve::Curve, "Selector Returns the curve");
	cls_BOPDS_Curve.def("SetBox", (void (BOPDS_Curve::*)(const Bnd_Box &)) &BOPDS_Curve::SetBox, "Modifier Sets the bounding box <theBox> of the curve", py::arg("theBox"));
	cls_BOPDS_Curve.def("Box", (const Bnd_Box & (BOPDS_Curve::*)() const ) &BOPDS_Curve::Box, "Selector Returns the bounding box of the curve");
	cls_BOPDS_Curve.def("ChangeBox", (Bnd_Box & (BOPDS_Curve::*)()) &BOPDS_Curve::ChangeBox, "Selector/Modifier Returns the bounding box of the curve");
	cls_BOPDS_Curve.def("SetPaveBlocks", (void (BOPDS_Curve::*)(const BOPDS_ListOfPaveBlock &)) &BOPDS_Curve::SetPaveBlocks, "None", py::arg("theLPB"));
	cls_BOPDS_Curve.def("PaveBlocks", (const BOPDS_ListOfPaveBlock & (BOPDS_Curve::*)() const ) &BOPDS_Curve::PaveBlocks, "Selector Returns the list of pave blocks of the curve");
	cls_BOPDS_Curve.def("ChangePaveBlocks", (BOPDS_ListOfPaveBlock & (BOPDS_Curve::*)()) &BOPDS_Curve::ChangePaveBlocks, "Selector/Modifier Returns the list of pave blocks of the curve");
	cls_BOPDS_Curve.def("InitPaveBlock1", (void (BOPDS_Curve::*)()) &BOPDS_Curve::InitPaveBlock1, "Creates initial pave block of the curve");
	cls_BOPDS_Curve.def("ChangePaveBlock1", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_Curve::*)()) &BOPDS_Curve::ChangePaveBlock1, "Selector/Modifier Returns initial pave block of the curve");
	cls_BOPDS_Curve.def("TechnoVertices", (const BOPCol_ListOfInteger & (BOPDS_Curve::*)() const ) &BOPDS_Curve::TechnoVertices, "Selector Returns list of indices of technologic vertices of the curve");
	cls_BOPDS_Curve.def("ChangeTechnoVertices", (BOPCol_ListOfInteger & (BOPDS_Curve::*)()) &BOPDS_Curve::ChangeTechnoVertices, "Selector/Modifier Returns list of indices of technologic vertices of the curve");
	cls_BOPDS_Curve.def("HasEdge", (Standard_Boolean (BOPDS_Curve::*)() const ) &BOPDS_Curve::HasEdge, "Query Returns true if at least one pave block of the curve has edge");
	cls_BOPDS_Curve.def("SetTolerance", (void (BOPDS_Curve::*)(const Standard_Real)) &BOPDS_Curve::SetTolerance, "Sets the tolerance for the curve.", py::arg("theTol"));
	cls_BOPDS_Curve.def("Tolerance", (Standard_Real (BOPDS_Curve::*)() const ) &BOPDS_Curve::Tolerance, "Returns the tolerance of the curve");
	cls_BOPDS_Curve.def("TangentialTolerance", (Standard_Real (BOPDS_Curve::*)() const ) &BOPDS_Curve::TangentialTolerance, "Returns the tangential tolerance of the curve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_CommonBlock.hxx
	py::class_<BOPDS_CommonBlock, opencascade::handle<BOPDS_CommonBlock>, Standard_Transient> cls_BOPDS_CommonBlock(mod, "BOPDS_CommonBlock", "The class BOPDS_CommonBlock is to store the information about pave blocks that have geometrical coincidence (in terms of a tolerance) with: a) other pave block(s); b) face(s). First pave block in the common block (real pave block) is always a pave block with the minimal index of the original edge.");
	cls_BOPDS_CommonBlock.def(py::init<>());
	cls_BOPDS_CommonBlock.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPDS_CommonBlock.def("AddPaveBlock", (void (BOPDS_CommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_CommonBlock::AddPaveBlock, "Modifier Adds the pave block <aPB> to the list of pave blocks of the common block", py::arg("aPB"));
	cls_BOPDS_CommonBlock.def("SetPaveBlocks", (void (BOPDS_CommonBlock::*)(const BOPDS_ListOfPaveBlock &)) &BOPDS_CommonBlock::SetPaveBlocks, "Modifier Adds the list of pave blocks <aLPB> to the list of pave blocks of the common block", py::arg("aLPB"));
	cls_BOPDS_CommonBlock.def("AddFace", (void (BOPDS_CommonBlock::*)(const Standard_Integer)) &BOPDS_CommonBlock::AddFace, "Modifier Adds the index of the face <aF> to the list of indices of faces of the common block", py::arg("aF"));
	cls_BOPDS_CommonBlock.def("SetFaces", (void (BOPDS_CommonBlock::*)(const BOPCol_ListOfInteger &)) &BOPDS_CommonBlock::SetFaces, "Modifier Sets the list of indices of faces <aLF> of the common block", py::arg("aLF"));
	cls_BOPDS_CommonBlock.def("AppendFaces", (void (BOPDS_CommonBlock::*)(BOPCol_ListOfInteger &)) &BOPDS_CommonBlock::AppendFaces, "Modifier Appends the list of indices of faces <aLF> to the list of indices of faces of the common block (the input list is emptied)", py::arg("aLF"));
	cls_BOPDS_CommonBlock.def("PaveBlocks", (const BOPDS_ListOfPaveBlock & (BOPDS_CommonBlock::*)() const ) &BOPDS_CommonBlock::PaveBlocks, "Selector Returns the list of pave blocks of the common block");
	cls_BOPDS_CommonBlock.def("Faces", (const BOPCol_ListOfInteger & (BOPDS_CommonBlock::*)() const ) &BOPDS_CommonBlock::Faces, "Selector Returns the list of indices of faces of the common block");
	cls_BOPDS_CommonBlock.def("PaveBlock1", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_CommonBlock::*)() const ) &BOPDS_CommonBlock::PaveBlock1, "Selector Returns the first pave block of the common block");
	cls_BOPDS_CommonBlock.def("PaveBlockOnEdge", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_CommonBlock::*)(const Standard_Integer)) &BOPDS_CommonBlock::PaveBlockOnEdge, "Selector Returns the pave block that belongs to the edge with index <theIx>", py::arg("theIndex"));
	cls_BOPDS_CommonBlock.def("IsPaveBlockOnFace", (Standard_Boolean (BOPDS_CommonBlock::*)(const Standard_Integer) const ) &BOPDS_CommonBlock::IsPaveBlockOnFace, "Query Returns true if the common block contains a pave block that belongs to the face with index <theIx>", py::arg("theIndex"));
	cls_BOPDS_CommonBlock.def("IsPaveBlockOnEdge", (Standard_Boolean (BOPDS_CommonBlock::*)(const Standard_Integer) const ) &BOPDS_CommonBlock::IsPaveBlockOnEdge, "Query Returns true if the common block contains a pave block that belongs to the edge with index <theIx>", py::arg("theIndex"));
	cls_BOPDS_CommonBlock.def("Contains", (Standard_Boolean (BOPDS_CommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_CommonBlock::Contains, "Query Returns true if the common block contains a pave block that is equal to <thePB>", py::arg("thePB"));
	cls_BOPDS_CommonBlock.def("Contains", (Standard_Boolean (BOPDS_CommonBlock::*)(const Standard_Integer) const ) &BOPDS_CommonBlock::Contains, "Query Returns true if the common block contains the face with index equal to <theF>", py::arg("theF"));
	cls_BOPDS_CommonBlock.def("SetEdge", (void (BOPDS_CommonBlock::*)(const Standard_Integer)) &BOPDS_CommonBlock::SetEdge, "Modifier Assign the index <theEdge> as the edge index to all pave blocks of the common block", py::arg("theEdge"));
	cls_BOPDS_CommonBlock.def("Edge", (Standard_Integer (BOPDS_CommonBlock::*)() const ) &BOPDS_CommonBlock::Edge, "Selector Returns the index of the edge of all pave blocks of the common block");
	// FIXME cls_BOPDS_CommonBlock.def("Dump", (void (BOPDS_CommonBlock::*)() const ) &BOPDS_CommonBlock::Dump, "None");
	cls_BOPDS_CommonBlock.def_static("get_type_name_", (const char * (*)()) &BOPDS_CommonBlock::get_type_name, "None");
	cls_BOPDS_CommonBlock.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPDS_CommonBlock::get_type_descriptor, "None");
	cls_BOPDS_CommonBlock.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPDS_CommonBlock::*)() const ) &BOPDS_CommonBlock::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PassKey.hxx
	py::class_<BOPDS_PassKey, std::unique_ptr<BOPDS_PassKey, Deleter<BOPDS_PassKey>>> cls_BOPDS_PassKey(mod, "BOPDS_PassKey", "The class BOPDS_PassKey is to provide possibility to map objects that have a set of integer IDs as a base");
	cls_BOPDS_PassKey.def(py::init<>());
	cls_BOPDS_PassKey.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPDS_PassKey.def(py::init([] (const BOPDS_PassKey &other) {return new BOPDS_PassKey(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_PassKey.def("assign", (BOPDS_PassKey & (BOPDS_PassKey::*)(const BOPDS_PassKey &)) &BOPDS_PassKey::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_BOPDS_PassKey.def("Clear", (void (BOPDS_PassKey::*)()) &BOPDS_PassKey::Clear, "Clear the contents");
	cls_BOPDS_PassKey.def("SetIds", (void (BOPDS_PassKey::*)(const Standard_Integer)) &BOPDS_PassKey::SetIds, "Modifier Sets one Id <theI1>", py::arg("theI1"));
	cls_BOPDS_PassKey.def("SetIds", (void (BOPDS_PassKey::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_PassKey::SetIds, "Modifier Sets two Id <theI1>,<theI2>", py::arg("theI1"), py::arg("theI2"));
	cls_BOPDS_PassKey.def("SetIds", (void (BOPDS_PassKey::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &BOPDS_PassKey::SetIds, "Modifier Sets three Id <theI1>,<theI2>,<theI3>", py::arg("theI1"), py::arg("theI2"), py::arg("theI3"));
	cls_BOPDS_PassKey.def("SetIds", (void (BOPDS_PassKey::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &BOPDS_PassKey::SetIds, "Modifier Sets four Id <theI1>,<theI2>,<theI3>,<theI4>", py::arg("theI1"), py::arg("theI2"), py::arg("theI3"), py::arg("theI4"));
	cls_BOPDS_PassKey.def("SetIds", (void (BOPDS_PassKey::*)(const BOPCol_ListOfInteger &)) &BOPDS_PassKey::SetIds, "Modifier Sets the list of Id <theLI>", py::arg("theLI"));
	cls_BOPDS_PassKey.def("NbIds", (Standard_Integer (BOPDS_PassKey::*)() const ) &BOPDS_PassKey::NbIds, "Selector Returns the number of Ids>");
	cls_BOPDS_PassKey.def("IsEqual", (Standard_Boolean (BOPDS_PassKey::*)(const BOPDS_PassKey &) const ) &BOPDS_PassKey::IsEqual, "Query Returns true if the PassKey is equal to <the theOther>", py::arg("theOther"));
	cls_BOPDS_PassKey.def("HashCode", (Standard_Integer (BOPDS_PassKey::*)(const Standard_Integer) const ) &BOPDS_PassKey::HashCode, "Query Returns hash code", py::arg("theUpper"));
	cls_BOPDS_PassKey.def("Id", (Standard_Integer (BOPDS_PassKey::*)(const Standard_Integer) const ) &BOPDS_PassKey::Id, "Selector Returns Id of index <theIndex>", py::arg("theIndex"));
	cls_BOPDS_PassKey.def("Ids", [](BOPDS_PassKey &self, Standard_Integer & theI1, Standard_Integer & theI2){ self.Ids(theI1, theI2); return std::tuple<Standard_Integer &, Standard_Integer &>(theI1, theI2); }, "Selector Returns the first two Ids <theI1>,<theI2>", py::arg("theI1"), py::arg("theI2"));
	// FIXME cls_BOPDS_PassKey.def("Dump", [](BOPDS_PassKey &self) -> void { return self.Dump(); });
	// FIXME cls_BOPDS_PassKey.def("Dump", (void (BOPDS_PassKey::*)(const Standard_Integer) const ) &BOPDS_PassKey::Dump, "None", py::arg("aHex"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PassKeyMapHasher.hxx
	py::class_<BOPDS_PassKeyMapHasher, std::unique_ptr<BOPDS_PassKeyMapHasher, Deleter<BOPDS_PassKeyMapHasher>>> cls_BOPDS_PassKeyMapHasher(mod, "BOPDS_PassKeyMapHasher", "None");
	cls_BOPDS_PassKeyMapHasher.def(py::init<>());
	cls_BOPDS_PassKeyMapHasher.def_static("HashCode_", (Standard_Integer (*)(const BOPDS_PassKey &, const Standard_Integer)) &BOPDS_PassKeyMapHasher::HashCode, "None", py::arg("aPKey"), py::arg("Upper"));
	cls_BOPDS_PassKeyMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const BOPDS_PassKey &, const BOPDS_PassKey &)) &BOPDS_PassKeyMapHasher::IsEqual, "None", py::arg("aPKey1"), py::arg("aPKey2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_IndexRange.hxx
	py::class_<BOPDS_IndexRange, std::unique_ptr<BOPDS_IndexRange, Deleter<BOPDS_IndexRange>>> cls_BOPDS_IndexRange(mod, "BOPDS_IndexRange", "The class BOPDS_IndexRange is to store the information about range of two indices");
	cls_BOPDS_IndexRange.def(py::init<>());
	cls_BOPDS_IndexRange.def("SetFirst", (void (BOPDS_IndexRange::*)(const Standard_Integer)) &BOPDS_IndexRange::SetFirst, "Modifier Sets the first index <theI1> of the range", py::arg("theI1"));
	cls_BOPDS_IndexRange.def("SetLast", (void (BOPDS_IndexRange::*)(const Standard_Integer)) &BOPDS_IndexRange::SetLast, "Modifier Sets the second index <theI2> of the range", py::arg("theI2"));
	cls_BOPDS_IndexRange.def("First", (Standard_Integer (BOPDS_IndexRange::*)() const ) &BOPDS_IndexRange::First, "Selector Returns the first index of the range");
	cls_BOPDS_IndexRange.def("Last", (Standard_Integer (BOPDS_IndexRange::*)() const ) &BOPDS_IndexRange::Last, "Selector Returns the second index of the range");
	cls_BOPDS_IndexRange.def("SetIndices", (void (BOPDS_IndexRange::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_IndexRange::SetIndices, "Modifier Sets the first index of the range <theI1> Sets the second index of the range <theI2>", py::arg("theI1"), py::arg("theI2"));
	cls_BOPDS_IndexRange.def("Indices", [](BOPDS_IndexRange &self, Standard_Integer & theI1, Standard_Integer & theI2){ self.Indices(theI1, theI2); return std::tuple<Standard_Integer &, Standard_Integer &>(theI1, theI2); }, "Selector Returns the first index of the range <theI1> Returns the second index of the range <theI2>", py::arg("theI1"), py::arg("theI2"));
	cls_BOPDS_IndexRange.def("Contains", (Standard_Boolean (BOPDS_IndexRange::*)(const Standard_Integer) const ) &BOPDS_IndexRange::Contains, "Query Returns true if the range contains <theIndex>", py::arg("theIndex"));
	// FIXME cls_BOPDS_IndexRange.def("Dump", (void (BOPDS_IndexRange::*)() const ) &BOPDS_IndexRange::Dump, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_ShapeInfo.hxx
	py::class_<BOPDS_ShapeInfo, std::unique_ptr<BOPDS_ShapeInfo, Deleter<BOPDS_ShapeInfo>>> cls_BOPDS_ShapeInfo(mod, "BOPDS_ShapeInfo", "The class BOPDS_ShapeInfo is to store handy information about shape");
	cls_BOPDS_ShapeInfo.def(py::init<>());
	cls_BOPDS_ShapeInfo.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPDS_ShapeInfo.def("SetShape", (void (BOPDS_ShapeInfo::*)(const TopoDS_Shape &)) &BOPDS_ShapeInfo::SetShape, "Modifier Sets the shape <theS>", py::arg("theS"));
	cls_BOPDS_ShapeInfo.def("Shape", (const TopoDS_Shape & (BOPDS_ShapeInfo::*)() const ) &BOPDS_ShapeInfo::Shape, "Selector Returns the shape");
	cls_BOPDS_ShapeInfo.def("SetShapeType", (void (BOPDS_ShapeInfo::*)(const TopAbs_ShapeEnum)) &BOPDS_ShapeInfo::SetShapeType, "Modifier Sets the type of shape theType", py::arg("theType"));
	cls_BOPDS_ShapeInfo.def("ShapeType", (TopAbs_ShapeEnum (BOPDS_ShapeInfo::*)() const ) &BOPDS_ShapeInfo::ShapeType, "Selector Returns the type of shape");
	cls_BOPDS_ShapeInfo.def("SetBox", (void (BOPDS_ShapeInfo::*)(const Bnd_Box &)) &BOPDS_ShapeInfo::SetBox, "Modifier Sets the boundung box of the shape theBox", py::arg("theBox"));
	cls_BOPDS_ShapeInfo.def("Box", (const Bnd_Box & (BOPDS_ShapeInfo::*)() const ) &BOPDS_ShapeInfo::Box, "Selector Returns the boundung box of the shape");
	cls_BOPDS_ShapeInfo.def("ChangeBox", (Bnd_Box & (BOPDS_ShapeInfo::*)()) &BOPDS_ShapeInfo::ChangeBox, "Selector/Modifier Returns the boundung box of the shape");
	cls_BOPDS_ShapeInfo.def("SubShapes", (const BOPCol_ListOfInteger & (BOPDS_ShapeInfo::*)() const ) &BOPDS_ShapeInfo::SubShapes, "Selector Returns the list of indices of sub-shapes");
	cls_BOPDS_ShapeInfo.def("ChangeSubShapes", (BOPCol_ListOfInteger & (BOPDS_ShapeInfo::*)()) &BOPDS_ShapeInfo::ChangeSubShapes, "Selector/ Modifier Returns the list of indices of sub-shapes");
	cls_BOPDS_ShapeInfo.def("HasSubShape", (Standard_Boolean (BOPDS_ShapeInfo::*)(const Standard_Integer) const ) &BOPDS_ShapeInfo::HasSubShape, "Query Returns true if the shape has sub-shape with index theI", py::arg("theI"));
	cls_BOPDS_ShapeInfo.def("HasReference", (Standard_Boolean (BOPDS_ShapeInfo::*)() const ) &BOPDS_ShapeInfo::HasReference, "None");
	cls_BOPDS_ShapeInfo.def("SetReference", (void (BOPDS_ShapeInfo::*)(const Standard_Integer)) &BOPDS_ShapeInfo::SetReference, "Modifier Sets the index of a reference information", py::arg("theI"));
	cls_BOPDS_ShapeInfo.def("Reference", (Standard_Integer (BOPDS_ShapeInfo::*)() const ) &BOPDS_ShapeInfo::Reference, "Selector Returns the index of a reference information");
	cls_BOPDS_ShapeInfo.def("HasBRep", (Standard_Boolean (BOPDS_ShapeInfo::*)() const ) &BOPDS_ShapeInfo::HasBRep, "Query Returns true if the shape has boundary representation");
	cls_BOPDS_ShapeInfo.def("IsInterfering", (Standard_Boolean (BOPDS_ShapeInfo::*)() const ) &BOPDS_ShapeInfo::IsInterfering, "Returns true if the shape can be participant of an interference");
	cls_BOPDS_ShapeInfo.def("HasFlag", (Standard_Boolean (BOPDS_ShapeInfo::*)() const ) &BOPDS_ShapeInfo::HasFlag, "Query Returns true if there is flag.");
	cls_BOPDS_ShapeInfo.def("HasFlag", [](BOPDS_ShapeInfo &self, Standard_Integer & theFlag){ Standard_Boolean rv = self.HasFlag(theFlag); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theFlag); }, "Query Returns true if there is flag. Returns the the flag theFlag", py::arg("theFlag"));
	cls_BOPDS_ShapeInfo.def("SetFlag", (void (BOPDS_ShapeInfo::*)(const Standard_Integer)) &BOPDS_ShapeInfo::SetFlag, "Modifier Sets the flag", py::arg("theI"));
	cls_BOPDS_ShapeInfo.def("Flag", (Standard_Integer (BOPDS_ShapeInfo::*)() const ) &BOPDS_ShapeInfo::Flag, "Returns the flag");
	// FIXME cls_BOPDS_ShapeInfo.def("Dump", (void (BOPDS_ShapeInfo::*)() const ) &BOPDS_ShapeInfo::Dump, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Tools.hxx
	py::class_<BOPDS_Tools, std::unique_ptr<BOPDS_Tools, Deleter<BOPDS_Tools>>> cls_BOPDS_Tools(mod, "BOPDS_Tools", "The class BOPDS_Tools contains a set auxiliary static functions of the package BOPDS");
	cls_BOPDS_Tools.def(py::init<>());
	cls_BOPDS_Tools.def_static("TypeToInteger_", (Standard_Integer (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &BOPDS_Tools::TypeToInteger, "Converts the conmbination of two types of shape <theT1>,<theT2> to the one integer value, that is returned", py::arg("theT1"), py::arg("theT2"));
	cls_BOPDS_Tools.def_static("TypeToInteger_", (Standard_Integer (*)(const TopAbs_ShapeEnum)) &BOPDS_Tools::TypeToInteger, "Converts the type of shape <theT>, to integer value, that is returned", py::arg("theT"));
	cls_BOPDS_Tools.def_static("HasBRep_", (Standard_Boolean (*)(const TopAbs_ShapeEnum)) &BOPDS_Tools::HasBRep, "Returns true if the type <theT> correspond to a shape having boundary representation", py::arg("theT"));
	cls_BOPDS_Tools.def_static("IsInterfering_", (Standard_Boolean (*)(const TopAbs_ShapeEnum)) &BOPDS_Tools::IsInterfering, "Returns true if the type <theT> can be participant of an interference", py::arg("theT"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_FaceInfo.hxx
	py::class_<BOPDS_FaceInfo, std::unique_ptr<BOPDS_FaceInfo, Deleter<BOPDS_FaceInfo>>> cls_BOPDS_FaceInfo(mod, "BOPDS_FaceInfo", "The class BOPDS_FaceInfo is to store handy information about state of face");
	cls_BOPDS_FaceInfo.def(py::init<>());
	cls_BOPDS_FaceInfo.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPDS_FaceInfo.def("Clear", (void (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::Clear, "Clears the contents");
	cls_BOPDS_FaceInfo.def("SetIndex", (void (BOPDS_FaceInfo::*)(const Standard_Integer)) &BOPDS_FaceInfo::SetIndex, "Modifier Sets the index of the face <theI>", py::arg("theI"));
	cls_BOPDS_FaceInfo.def("Index", (Standard_Integer (BOPDS_FaceInfo::*)() const ) &BOPDS_FaceInfo::Index, "Selector Returns the index of the face");
	cls_BOPDS_FaceInfo.def("PaveBlocksIn", (const BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)() const ) &BOPDS_FaceInfo::PaveBlocksIn, "Selector Returns the pave blocks of the face that have state In");
	cls_BOPDS_FaceInfo.def("ChangePaveBlocksIn", (BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangePaveBlocksIn, "Selector/Modifier Returns the pave blocks of the face that have state In");
	cls_BOPDS_FaceInfo.def("VerticesIn", (const BOPCol_MapOfInteger & (BOPDS_FaceInfo::*)() const ) &BOPDS_FaceInfo::VerticesIn, "Selector Returns the list of indices for vertices of the face that have state In");
	cls_BOPDS_FaceInfo.def("ChangeVerticesIn", (BOPCol_MapOfInteger & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangeVerticesIn, "Selector/Modifier Returns the list of indices for vertices of the face that have state In");
	cls_BOPDS_FaceInfo.def("PaveBlocksOn", (const BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)() const ) &BOPDS_FaceInfo::PaveBlocksOn, "Selector Returns the pave blocks of the face that have state On");
	cls_BOPDS_FaceInfo.def("ChangePaveBlocksOn", (BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangePaveBlocksOn, "Selector/Modifier Returns the pave blocks of the face that have state On");
	cls_BOPDS_FaceInfo.def("VerticesOn", (const BOPCol_MapOfInteger & (BOPDS_FaceInfo::*)() const ) &BOPDS_FaceInfo::VerticesOn, "Selector Returns the list of indices for vertices of the face that have state On");
	cls_BOPDS_FaceInfo.def("ChangeVerticesOn", (BOPCol_MapOfInteger & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangeVerticesOn, "Selector/Modifier Returns the list of indices for vertices of the face that have state On");
	cls_BOPDS_FaceInfo.def("PaveBlocksSc", (const BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)() const ) &BOPDS_FaceInfo::PaveBlocksSc, "Selector Returns the pave blocks of the face that are pave blocks of section edges");
	cls_BOPDS_FaceInfo.def("ChangePaveBlocksSc", (BOPDS_IndexedMapOfPaveBlock & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangePaveBlocksSc, "None");
	cls_BOPDS_FaceInfo.def("VerticesSc", (const BOPCol_MapOfInteger & (BOPDS_FaceInfo::*)() const ) &BOPDS_FaceInfo::VerticesSc, "Selector Returns the list of indices for section vertices of the face");
	cls_BOPDS_FaceInfo.def("ChangeVerticesSc", (BOPCol_MapOfInteger & (BOPDS_FaceInfo::*)()) &BOPDS_FaceInfo::ChangeVerticesSc, "Selector/Modifier Returns the list of indices for section vertices of the face");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Point.hxx
	py::class_<BOPDS_Point, std::unique_ptr<BOPDS_Point, Deleter<BOPDS_Point>>> cls_BOPDS_Point(mod, "BOPDS_Point", "The class BOPDS_Point is to store the information about intersection point");
	cls_BOPDS_Point.def(py::init<>());
	cls_BOPDS_Point.def("SetPnt", (void (BOPDS_Point::*)(const gp_Pnt &)) &BOPDS_Point::SetPnt, "Modifier Sets 3D point <thePnt>", py::arg("thePnt"));
	cls_BOPDS_Point.def("Pnt", (const gp_Pnt & (BOPDS_Point::*)() const ) &BOPDS_Point::Pnt, "Selector Returns 3D point");
	cls_BOPDS_Point.def("SetPnt2D1", (void (BOPDS_Point::*)(const gp_Pnt2d &)) &BOPDS_Point::SetPnt2D1, "Modifier Sets 2D point on the first face <thePnt>", py::arg("thePnt"));
	cls_BOPDS_Point.def("Pnt2D1", (const gp_Pnt2d & (BOPDS_Point::*)() const ) &BOPDS_Point::Pnt2D1, "Selector Returns 2D point on the first face <thePnt>");
	cls_BOPDS_Point.def("SetPnt2D2", (void (BOPDS_Point::*)(const gp_Pnt2d &)) &BOPDS_Point::SetPnt2D2, "Modifier Sets 2D point on the second face <thePnt>", py::arg("thePnt"));
	cls_BOPDS_Point.def("Pnt2D2", (const gp_Pnt2d & (BOPDS_Point::*)() const ) &BOPDS_Point::Pnt2D2, "Selector Returns 2D point on the second face <thePnt>");
	cls_BOPDS_Point.def("SetIndex", (void (BOPDS_Point::*)(const Standard_Integer)) &BOPDS_Point::SetIndex, "Modifier Sets the index of the vertex <theIndex>", py::arg("theIndex"));
	cls_BOPDS_Point.def("Index", (Standard_Integer (BOPDS_Point::*)() const ) &BOPDS_Point::Index, "Selector Returns index of the vertex");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Interf.hxx
	py::class_<BOPDS_Interf, std::unique_ptr<BOPDS_Interf, py::nodelete>> cls_BOPDS_Interf(mod, "BOPDS_Interf", "The class BOPDS_Interf is is to store the information about the interference between two shapes. The class BOPDS_Interf is root class");
	cls_BOPDS_Interf.def("SetIndices", (void (BOPDS_Interf::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_Interf::SetIndices, "Sets the indices of interferred shapes", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_Interf.def("Indices", [](BOPDS_Interf &self, Standard_Integer & theIndex1, Standard_Integer & theIndex2){ self.Indices(theIndex1, theIndex2); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndex1, theIndex2); }, "Returns the indices of interferred shapes", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_Interf.def("SetIndex1", (void (BOPDS_Interf::*)(const Standard_Integer)) &BOPDS_Interf::SetIndex1, "Sets the index of the first interferred shape", py::arg("theIndex"));
	cls_BOPDS_Interf.def("SetIndex2", (void (BOPDS_Interf::*)(const Standard_Integer)) &BOPDS_Interf::SetIndex2, "Sets the index of the second interferred shape", py::arg("theIndex"));
	cls_BOPDS_Interf.def("Index1", (Standard_Integer (BOPDS_Interf::*)() const ) &BOPDS_Interf::Index1, "Returns the index of the first interferred shape");
	cls_BOPDS_Interf.def("Index2", (Standard_Integer (BOPDS_Interf::*)() const ) &BOPDS_Interf::Index2, "Returns the index of the second interferred shape");
	cls_BOPDS_Interf.def("OppositeIndex", (Standard_Integer (BOPDS_Interf::*)(const Standard_Integer) const ) &BOPDS_Interf::OppositeIndex, "Returns the index of that are opposite to the given index", py::arg("theI"));
	cls_BOPDS_Interf.def("Contains", (Standard_Boolean (BOPDS_Interf::*)(const Standard_Integer) const ) &BOPDS_Interf::Contains, "Returns true if the interference contains given index", py::arg("theIndex"));
	cls_BOPDS_Interf.def("SetIndexNew", (void (BOPDS_Interf::*)(const Standard_Integer)) &BOPDS_Interf::SetIndexNew, "Sets the index of new shape", py::arg("theIndex"));
	cls_BOPDS_Interf.def("IndexNew", (Standard_Integer (BOPDS_Interf::*)() const ) &BOPDS_Interf::IndexNew, "Returns the index of new shape");
	cls_BOPDS_Interf.def("HasIndexNew", [](BOPDS_Interf &self, Standard_Integer & theIndex){ Standard_Boolean rv = self.HasIndexNew(theIndex); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theIndex); }, "Returns true if the interference has index of new shape that is equal to the given index", py::arg("theIndex"));
	cls_BOPDS_Interf.def("HasIndexNew", (Standard_Boolean (BOPDS_Interf::*)() const ) &BOPDS_Interf::HasIndexNew, "Returns true if the interference has index of new shape the index");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Interf.hxx
	py::class_<BOPDS_InterfVV, std::unique_ptr<BOPDS_InterfVV, Deleter<BOPDS_InterfVV>>, BOPDS_Interf> cls_BOPDS_InterfVV(mod, "BOPDS_InterfVV", "The class BOPDS_InterfVV is is to store the information about the interference of the type vertex/vertex.");
	cls_BOPDS_InterfVV.def(py::init<>());
	cls_BOPDS_InterfVV.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Interf.hxx
	py::class_<BOPDS_InterfVE, std::unique_ptr<BOPDS_InterfVE, Deleter<BOPDS_InterfVE>>, BOPDS_Interf> cls_BOPDS_InterfVE(mod, "BOPDS_InterfVE", "The class BOPDS_InterfVE is is to store the information about the interference of the type vertex/edge.");
	cls_BOPDS_InterfVE.def(py::init<>());
	cls_BOPDS_InterfVE.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPDS_InterfVE.def("SetParameter", (void (BOPDS_InterfVE::*)(const Standard_Real)) &BOPDS_InterfVE::SetParameter, "Modifier Sets the value of parameter of the point of the vertex on the curve of the edge", py::arg("theT"));
	cls_BOPDS_InterfVE.def("Parameter", (Standard_Real (BOPDS_InterfVE::*)() const ) &BOPDS_InterfVE::Parameter, "Selector Returrns the value of parameter of the point of the vertex on the curve of the edge");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Interf.hxx
	py::class_<BOPDS_InterfVF, std::unique_ptr<BOPDS_InterfVF, Deleter<BOPDS_InterfVF>>, BOPDS_Interf> cls_BOPDS_InterfVF(mod, "BOPDS_InterfVF", "The class BOPDS_InterfVF is is to store the information about the interference of the type vertex/face");
	cls_BOPDS_InterfVF.def(py::init<>());
	cls_BOPDS_InterfVF.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPDS_InterfVF.def("SetUV", (void (BOPDS_InterfVF::*)(const Standard_Real, const Standard_Real)) &BOPDS_InterfVF::SetUV, "Modifier Sets the value of parameters of the point of the vertex on the surface of of the face", py::arg("theU"), py::arg("theV"));
	cls_BOPDS_InterfVF.def("UV", [](BOPDS_InterfVF &self, Standard_Real & theU, Standard_Real & theV){ self.UV(theU, theV); return std::tuple<Standard_Real &, Standard_Real &>(theU, theV); }, "Selector Returns the value of parameters of the point of the vertex on the surface of of the face", py::arg("theU"), py::arg("theV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Interf.hxx
	py::class_<BOPDS_InterfEE, std::unique_ptr<BOPDS_InterfEE, Deleter<BOPDS_InterfEE>>, BOPDS_Interf> cls_BOPDS_InterfEE(mod, "BOPDS_InterfEE", "The class BOPDS_InterfEE is is to store the information about the interference of the type edge/edge.");
	cls_BOPDS_InterfEE.def(py::init<>());
	cls_BOPDS_InterfEE.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPDS_InterfEE.def("SetCommonPart", (void (BOPDS_InterfEE::*)(const IntTools_CommonPrt &)) &BOPDS_InterfEE::SetCommonPart, "Modifier Sets the info of common part", py::arg("theCP"));
	cls_BOPDS_InterfEE.def("CommonPart", (const IntTools_CommonPrt & (BOPDS_InterfEE::*)() const ) &BOPDS_InterfEE::CommonPart, "Selector Returns the info of common part");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Interf.hxx
	py::class_<BOPDS_InterfEF, std::unique_ptr<BOPDS_InterfEF, Deleter<BOPDS_InterfEF>>, BOPDS_Interf> cls_BOPDS_InterfEF(mod, "BOPDS_InterfEF", "The class BOPDS_InterfEF is is to store the information about the interference of the type edge/face.");
	cls_BOPDS_InterfEF.def(py::init<>());
	cls_BOPDS_InterfEF.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPDS_InterfEF.def("SetCommonPart", (void (BOPDS_InterfEF::*)(const IntTools_CommonPrt &)) &BOPDS_InterfEF::SetCommonPart, "Modifier Sets the info of common part", py::arg("theCP"));
	cls_BOPDS_InterfEF.def("CommonPart", (const IntTools_CommonPrt & (BOPDS_InterfEF::*)() const ) &BOPDS_InterfEF::CommonPart, "Selector Returns the info of common part");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Interf.hxx
	py::class_<BOPDS_InterfFF, std::unique_ptr<BOPDS_InterfFF, Deleter<BOPDS_InterfFF>>, BOPDS_Interf> cls_BOPDS_InterfFF(mod, "BOPDS_InterfFF", "None");
	cls_BOPDS_InterfFF.def(py::init<>());
	cls_BOPDS_InterfFF.def("Init", (void (BOPDS_InterfFF::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_InterfFF::Init, "Initializer", py::arg("theNbCurves"), py::arg("theNbPoints"));
	cls_BOPDS_InterfFF.def("SetTangentFaces", (void (BOPDS_InterfFF::*)(const Standard_Boolean)) &BOPDS_InterfFF::SetTangentFaces, "Modifier Sets the flag of whether the faces are tangent", py::arg("theFlag"));
	cls_BOPDS_InterfFF.def("TangentFaces", (Standard_Boolean (BOPDS_InterfFF::*)() const ) &BOPDS_InterfFF::TangentFaces, "Selector Returns the flag whether the faces are tangent");
	cls_BOPDS_InterfFF.def("Curves", (const BOPDS_VectorOfCurve & (BOPDS_InterfFF::*)() const ) &BOPDS_InterfFF::Curves, "Selector Returns the intersection curves");
	cls_BOPDS_InterfFF.def("ChangeCurves", (BOPDS_VectorOfCurve & (BOPDS_InterfFF::*)()) &BOPDS_InterfFF::ChangeCurves, "Selector/Modifier Returns the intersection curves");
	cls_BOPDS_InterfFF.def("Points", (const BOPDS_VectorOfPoint & (BOPDS_InterfFF::*)() const ) &BOPDS_InterfFF::Points, "Selector Returns the intersection points");
	cls_BOPDS_InterfFF.def("ChangePoints", (BOPDS_VectorOfPoint & (BOPDS_InterfFF::*)()) &BOPDS_InterfFF::ChangePoints, "Selector/Modifier Returns the intersection points");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Interf.hxx
	py::class_<BOPDS_InterfVZ, std::unique_ptr<BOPDS_InterfVZ, Deleter<BOPDS_InterfVZ>>, BOPDS_Interf> cls_BOPDS_InterfVZ(mod, "BOPDS_InterfVZ", "The class BOPDS_InterfVZ is is to store the information about the interference of the type vertex/solid.");
	cls_BOPDS_InterfVZ.def(py::init<>());
	cls_BOPDS_InterfVZ.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Interf.hxx
	py::class_<BOPDS_InterfEZ, std::unique_ptr<BOPDS_InterfEZ, Deleter<BOPDS_InterfEZ>>, BOPDS_Interf> cls_BOPDS_InterfEZ(mod, "BOPDS_InterfEZ", "The class BOPDS_InterfEZ is is to store the information about the interference of the type edge/solid.");
	cls_BOPDS_InterfEZ.def(py::init<>());
	cls_BOPDS_InterfEZ.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Interf.hxx
	py::class_<BOPDS_InterfFZ, std::unique_ptr<BOPDS_InterfFZ, Deleter<BOPDS_InterfFZ>>, BOPDS_Interf> cls_BOPDS_InterfFZ(mod, "BOPDS_InterfFZ", "The class BOPDS_InterfFZ is is to store the information about the interference of the type face/solid.");
	cls_BOPDS_InterfFZ.def(py::init<>());
	cls_BOPDS_InterfFZ.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_Interf.hxx
	py::class_<BOPDS_InterfZZ, std::unique_ptr<BOPDS_InterfZZ, Deleter<BOPDS_InterfZZ>>, BOPDS_Interf> cls_BOPDS_InterfZZ(mod, "BOPDS_InterfZZ", "The class BOPDS_InterfZZ is is to store the information about the interference of the type solid/solid.");
	cls_BOPDS_InterfZZ.def(py::init<>());
	cls_BOPDS_InterfZZ.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_IteratorSI.hxx
	py::class_<BOPDS_IteratorSI, std::unique_ptr<BOPDS_IteratorSI, Deleter<BOPDS_IteratorSI>>, BOPDS_Iterator> cls_BOPDS_IteratorSI(mod, "BOPDS_IteratorSI", "The class BOPDS_IteratorSI is 1.to compute self-intersections between BRep sub-shapes of each argument of an operation (see the class BOPDS_DS) in terms of theirs bounding boxes 2.provides interface to iterare the pairs of intersected sub-shapes of given type");
	cls_BOPDS_IteratorSI.def(py::init<>());
	cls_BOPDS_IteratorSI.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPDS_IteratorSI.def("UpdateByLevelOfCheck", (void (BOPDS_IteratorSI::*)(const Standard_Integer)) &BOPDS_IteratorSI::UpdateByLevelOfCheck, "Updates the lists of possible intersections according to the value of <theLevel>. It defines which interferferences will be checked: 0 - only V/V; 1 - V/V and V/E; 2 - V/V, V/E and E/E; 3 - V/V, V/E, E/E and V/F; 4 - V/V, V/E, E/E, V/F and E/F; other - all interferences.", py::arg("theLevel"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PassKeyBoolean.hxx
	py::class_<BOPDS_PassKeyBoolean, std::unique_ptr<BOPDS_PassKeyBoolean, Deleter<BOPDS_PassKeyBoolean>>, BOPDS_PassKey> cls_BOPDS_PassKeyBoolean(mod, "BOPDS_PassKeyBoolean", "None");
	cls_BOPDS_PassKeyBoolean.def(py::init<>());
	cls_BOPDS_PassKeyBoolean.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPDS_PassKeyBoolean.def(py::init([] (const BOPDS_PassKeyBoolean &other) {return new BOPDS_PassKeyBoolean(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_PassKeyBoolean.def("SetFlag", (void (BOPDS_PassKeyBoolean::*)(const Standard_Boolean)) &BOPDS_PassKeyBoolean::SetFlag, "None", py::arg("theFlag"));
	cls_BOPDS_PassKeyBoolean.def("assign", (BOPDS_PassKeyBoolean & (BOPDS_PassKeyBoolean::*)(const BOPDS_PassKeyBoolean &)) &BOPDS_PassKeyBoolean::operator=, py::is_operator(), "None", py::arg(""));
	cls_BOPDS_PassKeyBoolean.def("Flag", (Standard_Boolean (BOPDS_PassKeyBoolean::*)() const ) &BOPDS_PassKeyBoolean::Flag, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PaveMapHasher.hxx
	py::class_<BOPDS_PaveMapHasher, std::unique_ptr<BOPDS_PaveMapHasher, Deleter<BOPDS_PaveMapHasher>>> cls_BOPDS_PaveMapHasher(mod, "BOPDS_PaveMapHasher", "None");
	cls_BOPDS_PaveMapHasher.def(py::init<>());
	cls_BOPDS_PaveMapHasher.def_static("HashCode_", (Standard_Integer (*)(const BOPDS_Pave &, const Standard_Integer)) &BOPDS_PaveMapHasher::HashCode, "None", py::arg("aPave"), py::arg("Upper"));
	cls_BOPDS_PaveMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const BOPDS_Pave &, const BOPDS_Pave &)) &BOPDS_PaveMapHasher::IsEqual, "None", py::arg("aPave1"), py::arg("aPave2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_SubIterator.hxx
	py::class_<BOPDS_SubIterator, std::unique_ptr<BOPDS_SubIterator, Deleter<BOPDS_SubIterator>>> cls_BOPDS_SubIterator(mod, "BOPDS_SubIterator", "The class BOPDS_SubIterator is used to compute intersections between bounding boxes of two sub-sets of BRep sub-shapes of arguments of an operation (see the class BOPDS_DS). The class provides interface to iterate the pairs of intersected sub-shapes.");
	cls_BOPDS_SubIterator.def(py::init<>());
	cls_BOPDS_SubIterator.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPDS_SubIterator.def("SetDS", (void (BOPDS_SubIterator::*)(const BOPDS_PDS &)) &BOPDS_SubIterator::SetDS, "Sets the data structure <pDS> to process. It is used to access the shapes and their bounding boxes.", py::arg("pDS"));
	cls_BOPDS_SubIterator.def("DS", (const BOPDS_DS & (BOPDS_SubIterator::*)() const ) &BOPDS_SubIterator::DS, "Returns the data structure");
	cls_BOPDS_SubIterator.def("SetSubSet1", (void (BOPDS_SubIterator::*)(const BOPCol_ListOfInteger &)) &BOPDS_SubIterator::SetSubSet1, "Sets the first set of indices <theLI> to process", py::arg("theLI"));
	cls_BOPDS_SubIterator.def("SubSet1", (const BOPCol_ListOfInteger & (BOPDS_SubIterator::*)() const ) &BOPDS_SubIterator::SubSet1, "Returns the first set of indices to process");
	cls_BOPDS_SubIterator.def("SetSubSet2", (void (BOPDS_SubIterator::*)(const BOPCol_ListOfInteger &)) &BOPDS_SubIterator::SetSubSet2, "Sets the second set of indices <theLI> to process", py::arg("theLI"));
	cls_BOPDS_SubIterator.def("SubSet2", (const BOPCol_ListOfInteger & (BOPDS_SubIterator::*)() const ) &BOPDS_SubIterator::SubSet2, "Returns the second set of indices to process");
	cls_BOPDS_SubIterator.def("Initialize", (void (BOPDS_SubIterator::*)()) &BOPDS_SubIterator::Initialize, "Initializes the iterator");
	cls_BOPDS_SubIterator.def("More", (Standard_Boolean (BOPDS_SubIterator::*)() const ) &BOPDS_SubIterator::More, "Returns true if there are more pairs of intersected shapes");
	cls_BOPDS_SubIterator.def("Next", (void (BOPDS_SubIterator::*)()) &BOPDS_SubIterator::Next, "Moves iterations ahead");
	cls_BOPDS_SubIterator.def("Value", [](BOPDS_SubIterator &self, Standard_Integer & theIndex1, Standard_Integer & theIndex2){ self.Value(theIndex1, theIndex2); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndex1, theIndex2); }, "Returns indices (DS) of intersected shapes theIndex1 - the index of the first shape theIndex2 - the index of the second shape", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_SubIterator.def("Prepare", (void (BOPDS_SubIterator::*)()) &BOPDS_SubIterator::Prepare, "Perform the intersection algorithm and prepare the results to be used");
	cls_BOPDS_SubIterator.def("ExpectedLength", (Standard_Integer (BOPDS_SubIterator::*)() const ) &BOPDS_SubIterator::ExpectedLength, "Returns the number of interfering pairs");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PDS.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PIterator.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_ListOfPave.hxx
	bind_NCollection_List<BOPDS_Pave>(mod, "BOPDS_ListOfPave");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_ListOfPave.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_ListOfPaveBlock.hxx
	bind_NCollection_List<opencascade::handle<BOPDS_PaveBlock> >(mod, "BOPDS_ListOfPaveBlock");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_ListOfPaveBlock.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.hxx
	bind_NCollection_IndexedDataMap<TopoDS_Shape, BOPDS_CoupleOfPaveBlocks, TopTools_ShapeMapHasher>(mod, "BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_IndexedMapOfPaveBlock.hxx
	bind_NCollection_IndexedMap<opencascade::handle<BOPDS_PaveBlock>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "BOPDS_IndexedMapOfPaveBlock");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPaveBlockListOfPaveBlock.hxx
	bind_NCollection_DataMap<opencascade::handle<BOPDS_PaveBlock>, NCollection_List<opencascade::handle<BOPDS_PaveBlock> >, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "BOPDS_DataMapOfPaveBlockListOfPaveBlock");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPaveBlockListOfPaveBlock.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPaveBlock.hxx
	bind_NCollection_Map<opencascade::handle<BOPDS_PaveBlock>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "BOPDS_MapOfPaveBlock");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPaveBlock.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPair.hxx
	bind_NCollection_Map<BOPDS_Pair, BOPDS_PairMapHasher>(mod, "BOPDS_MapOfPair");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPair.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfCurve.hxx
	bind_BOPCol_NCVector<BOPDS_Curve>(mod, "BOPDS_VectorOfCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_IndexedDataMapOfPaveBlockListOfInteger.hxx
	bind_NCollection_IndexedDataMap<opencascade::handle<BOPDS_PaveBlock>, NCollection_List<int>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "BOPDS_IndexedDataMapOfPaveBlockListOfInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.hxx
	bind_NCollection_IndexedDataMap<opencascade::handle<BOPDS_PaveBlock>, NCollection_List<opencascade::handle<BOPDS_PaveBlock> >, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfIntegerListOfPaveBlock.hxx
	bind_NCollection_DataMap<int, NCollection_List<opencascade::handle<BOPDS_PaveBlock> >, NCollection_DefaultHasher<int> >(mod, "BOPDS_DataMapOfIntegerListOfPaveBlock");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPassKeyListOfPaveBlock.hxx
	bind_NCollection_DataMap<BOPDS_PassKey, NCollection_List<opencascade::handle<BOPDS_PaveBlock> >, BOPDS_PassKeyMapHasher>(mod, "BOPDS_DataMapOfPassKeyListOfPaveBlock");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPassKeyListOfPaveBlock.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPaveBlockCommonBlock.hxx
	bind_NCollection_DataMap<opencascade::handle<BOPDS_PaveBlock>, opencascade::handle<BOPDS_CommonBlock>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "BOPDS_DataMapOfPaveBlockCommonBlock");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPaveBlockCommonBlock.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPaveBlockListOfInteger.hxx
	bind_NCollection_DataMap<opencascade::handle<BOPDS_PaveBlock>, NCollection_List<int>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "BOPDS_DataMapOfPaveBlockListOfInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPaveBlockListOfInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfShapeCoupleOfPaveBlocks.hxx
	bind_NCollection_DataMap<TopoDS_Shape, BOPDS_CoupleOfPaveBlocks, TopTools_ShapeMapHasher>(mod, "BOPDS_DataMapOfShapeCoupleOfPaveBlocks");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfShapeCoupleOfPaveBlocks.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfIndexRange.hxx
	bind_BOPCol_NCVector<BOPDS_IndexRange>(mod, "BOPDS_VectorOfIndexRange");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfShapeInfo.hxx
	bind_BOPCol_NCVector<BOPDS_ShapeInfo>(mod, "BOPDS_VectorOfShapeInfo");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfListOfPaveBlock.hxx
	bind_BOPCol_NCVector<NCollection_List<opencascade::handle<BOPDS_PaveBlock> > >(mod, "BOPDS_VectorOfListOfPaveBlock");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfFaceInfo.hxx
	bind_BOPCol_NCVector<BOPDS_FaceInfo>(mod, "BOPDS_VectorOfFaceInfo");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfPoint.hxx
	bind_BOPCol_NCVector<BOPDS_Point>(mod, "BOPDS_VectorOfPoint");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfInterfVV.hxx
	bind_BOPCol_NCVector<BOPDS_InterfVV>(mod, "BOPDS_VectorOfInterfVV");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfInterfVE.hxx
	bind_BOPCol_NCVector<BOPDS_InterfVE>(mod, "BOPDS_VectorOfInterfVE");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfInterfVF.hxx
	bind_BOPCol_NCVector<BOPDS_InterfVF>(mod, "BOPDS_VectorOfInterfVF");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfInterfEE.hxx
	bind_BOPCol_NCVector<BOPDS_InterfEE>(mod, "BOPDS_VectorOfInterfEE");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfInterfEF.hxx
	bind_BOPCol_NCVector<BOPDS_InterfEF>(mod, "BOPDS_VectorOfInterfEF");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfInterfFF.hxx
	bind_BOPCol_NCVector<BOPDS_InterfFF>(mod, "BOPDS_VectorOfInterfFF");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfInterfVZ.hxx
	bind_BOPCol_NCVector<BOPDS_InterfVZ>(mod, "BOPDS_VectorOfInterfVZ");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfInterfEZ.hxx
	bind_BOPCol_NCVector<BOPDS_InterfEZ>(mod, "BOPDS_VectorOfInterfEZ");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfInterfFZ.hxx
	bind_BOPCol_NCVector<BOPDS_InterfFZ>(mod, "BOPDS_VectorOfInterfFZ");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfInterfZZ.hxx
	bind_BOPCol_NCVector<BOPDS_InterfZZ>(mod, "BOPDS_VectorOfInterfZZ");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfPair.hxx
	bind_BOPCol_NCVector<BOPDS_Pair>(mod, "BOPDS_VectorOfPair");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfVectorOfPair.hxx
	bind_BOPCol_NCVector<BOPCol_NCVector<BOPDS_Pair> >(mod, "BOPDS_VectorOfVectorOfPair");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_ListOfPassKeyBoolean.hxx
	bind_NCollection_List<BOPDS_PassKeyBoolean>(mod, "BOPDS_ListOfPassKeyBoolean");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_ListOfPassKeyBoolean.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfCommonBlock.hxx
	bind_NCollection_Map<opencascade::handle<BOPDS_CommonBlock>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "BOPDS_MapOfCommonBlock");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfCommonBlock.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPassKey.hxx
	bind_NCollection_Map<BOPDS_PassKey, BOPDS_PassKeyMapHasher>(mod, "BOPDS_MapOfPassKey");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPassKey.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPassKeyBoolean.hxx
	bind_NCollection_Map<BOPDS_PassKeyBoolean, BOPDS_PassKeyMapHasher>(mod, "BOPDS_MapOfPassKeyBoolean");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPassKeyBoolean.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPave.hxx
	bind_NCollection_Map<BOPDS_Pave, BOPDS_PaveMapHasher>(mod, "BOPDS_MapOfPave");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPave.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PIteratorSI.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfListOfPassKeyBoolean.hxx
	bind_BOPCol_NCVector<NCollection_List<BOPDS_PassKeyBoolean> >(mod, "BOPDS_VectorOfListOfPassKeyBoolean");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_VectorOfPave.hxx
	bind_NCollection_Array1<BOPDS_Pave>(mod, "BOPDS_VectorOfPave");


}
