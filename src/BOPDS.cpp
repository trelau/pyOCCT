#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

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
	// FIXME cls_BOPDS_DS.def("SetArguments", (void (BOPDS_DS::*)(const BOPCol_ListOfShape &)) &BOPDS_DS::SetArguments, "Modifier Sets the arguments [theLS] of an operation", py::arg("theLS"));
	cls_BOPDS_DS.def("Arguments", (const BOPCol_ListOfShape & (BOPDS_DS::*)() const ) &BOPDS_DS::Arguments, "Selector Returns the arguments of an operation");
	cls_BOPDS_DS.def("Init", [](BOPDS_DS &self) -> void { return self.Init(); });
	cls_BOPDS_DS.def("Init", (void (BOPDS_DS::*)(const Standard_Real)) &BOPDS_DS::Init, "Initializes the data structure for the arguments", py::arg("theFuzz"));
	cls_BOPDS_DS.def("NbShapes", (Standard_Integer (BOPDS_DS::*)() const ) &BOPDS_DS::NbShapes, "Selector Returns the total number of shapes stored");
	cls_BOPDS_DS.def("NbSourceShapes", (Standard_Integer (BOPDS_DS::*)() const ) &BOPDS_DS::NbSourceShapes, "Selector Returns the total number of source shapes stored");
	cls_BOPDS_DS.def("NbRanges", (Standard_Integer (BOPDS_DS::*)() const ) &BOPDS_DS::NbRanges, "Selector Returns the number of index ranges");
	cls_BOPDS_DS.def("Range", (const BOPDS_IndexRange & (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::Range, "Selector Returns the index range 'i'", py::arg("theIndex"));
	cls_BOPDS_DS.def("Rank", (Standard_Integer (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::Rank, "Selector Returns the rank of the shape of index 'i'", py::arg("theIndex"));
	cls_BOPDS_DS.def("IsNewShape", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer) const ) &BOPDS_DS::IsNewShape, "Returns true if the shape of index 'i' is not the source shape/sub-shape", py::arg("theIndex"));
	// FIXME cls_BOPDS_DS.def("Append", (Standard_Integer (BOPDS_DS::*)(const BOPDS_ShapeInfo &)) &BOPDS_DS::Append, "Modifier Appends the information about the shape [theSI] to the data structure Returns the index of theSI in the data structure", py::arg("theSI"));
	// FIXME cls_BOPDS_DS.def("Append", (Standard_Integer (BOPDS_DS::*)(const TopoDS_Shape &)) &BOPDS_DS::Append, "Modifier Appends the default information about the shape [theS] to the data structure Returns the index of theS in the data structure", py::arg("theS"));
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
	// FIXME cls_BOPDS_DS.def("FaceInfoOn", (void (BOPDS_DS::*)(const Standard_Integer, BOPDS_IndexedMapOfPaveBlock &, BOPCol_MapOfInteger &)) &BOPDS_DS::FaceInfoOn, "Selector Returns the state On [theMPB,theMVP] of face with index theIndex", py::arg("theIndex"), py::arg("theMPB"), py::arg("theMVP"));
	// FIXME cls_BOPDS_DS.def("FaceInfoIn", (void (BOPDS_DS::*)(const Standard_Integer, BOPDS_IndexedMapOfPaveBlock &, BOPCol_MapOfInteger &)) &BOPDS_DS::FaceInfoIn, "Selector Returns the state In [theMPB,theMVP] of face with index theIndex", py::arg("theIndex"), py::arg("theMPB"), py::arg("theMVP"));
	cls_BOPDS_DS.def("AloneVertices", (void (BOPDS_DS::*)(const Standard_Integer, BOPCol_ListOfInteger &) const ) &BOPDS_DS::AloneVertices, "Selector Returns the indices of alone vertices for the face with index theIndex", py::arg("theF"), py::arg("theLI"));
	cls_BOPDS_DS.def("RefineFaceInfoOn", (void (BOPDS_DS::*)()) &BOPDS_DS::RefineFaceInfoOn, "Refine the state On for the all faces having state information");
	cls_BOPDS_DS.def("SubShapesOnIn", (void (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer, BOPCol_MapOfInteger &, BOPDS_IndexedMapOfPaveBlock &, BOPDS_MapOfPaveBlock &) const ) &BOPDS_DS::SubShapesOnIn, "Returns information about ON/IN subshapes of the given faces.", py::arg("theF1"), py::arg("theF2"), py::arg("theMVOnIn"), py::arg("thePBOnIn"), py::arg("theCommonPB"));
	cls_BOPDS_DS.def("SharedEdges", (void (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer, BOPCol_ListOfInteger &, const BOPCol_BaseAllocator &)) &BOPDS_DS::SharedEdges, "Returns the indices of edges that are shared for the faces with indices theF1, theF2", py::arg("theF1"), py::arg("theF2"), py::arg("theLI"), py::arg("theAllocator"));
	cls_BOPDS_DS.def("ShapesSD", (BOPCol_DataMapOfIntegerInteger & (BOPDS_DS::*)()) &BOPDS_DS::ShapesSD, "Selector Returns the collection same domain shapes");
	cls_BOPDS_DS.def("AddShapeSD", (void (BOPDS_DS::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_DS::AddShapeSD, "Modifier Adds the information about same domain shapes with indices theIndex, theIndexSD", py::arg("theIndex"), py::arg("theIndexSD"));
	cls_BOPDS_DS.def("HasShapeSD", (Standard_Boolean (BOPDS_DS::*)(const Standard_Integer, Standard_Integer &) const ) &BOPDS_DS::HasShapeSD, "Query Returns true if the shape with index theIndex has the same domain shape. In this case theIndexSD will contain the index of same domain shape found", py::arg("theIndex"), py::arg("theIndexSD"));
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
	cls_BOPDS_Iterator.def("Value", (void (BOPDS_Iterator::*)(Standard_Integer &, Standard_Integer &) const ) &BOPDS_Iterator::Value, "Returns indices (DS) of intersected shapes theIndex1 - the index of the first shape theIndex2 - the index of the second shape", py::arg("theIndex1"), py::arg("theIndex2"));
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
	cls_BOPDS_Pave.def("Contents", (void (BOPDS_Pave::*)(Standard_Integer &, Standard_Real &) const ) &BOPDS_Pave::Contents, "Selector Returns the index of vertex <theIndex> Returns the parameter of vertex <theParameter>", py::arg("theIndex"), py::arg("theParameter"));
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
	cls_BOPDS_PaveBlock.def("HasEdge", (Standard_Boolean (BOPDS_PaveBlock::*)(Standard_Integer &) const ) &BOPDS_PaveBlock::HasEdge, "Query Returns true if the pave block has edge Returns the index of edge <theEdge>", py::arg("theEdge"));
	cls_BOPDS_PaveBlock.def("SetOriginalEdge", (void (BOPDS_PaveBlock::*)(const Standard_Integer)) &BOPDS_PaveBlock::SetOriginalEdge, "Modifier Sets the index of original edge of the pave block <theEdge>", py::arg("theEdge"));
	cls_BOPDS_PaveBlock.def("OriginalEdge", (Standard_Integer (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::OriginalEdge, "Selector Returns the index of original edge of pave block");
	cls_BOPDS_PaveBlock.def("IsSplitEdge", (Standard_Boolean (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::IsSplitEdge, "Query Returns true if the edge is equal to the original edge of the pave block");
	cls_BOPDS_PaveBlock.def("Range", (void (BOPDS_PaveBlock::*)(Standard_Real &, Standard_Real &) const ) &BOPDS_PaveBlock::Range, "Selector Returns the parametric range <theT1,theT2> of the pave block", py::arg("theT1"), py::arg("theT2"));
	cls_BOPDS_PaveBlock.def("HasSameBounds", (Standard_Boolean (BOPDS_PaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_PaveBlock::HasSameBounds, "Query Returns true if the pave block has pave indices that equal to the pave indices of the pave block <theOther>", py::arg("theOther"));
	cls_BOPDS_PaveBlock.def("Indices", (void (BOPDS_PaveBlock::*)(Standard_Integer &, Standard_Integer &) const ) &BOPDS_PaveBlock::Indices, "Selector Returns the pave indices <theIndex1,theIndex2> of the pave block", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_PaveBlock.def("IsToUpdate", (Standard_Boolean (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::IsToUpdate, "Query Returns true if the pave block contains extra paves");
	cls_BOPDS_PaveBlock.def("AppendExtPave", (void (BOPDS_PaveBlock::*)(const BOPDS_Pave &)) &BOPDS_PaveBlock::AppendExtPave, "Modifier Appends extra paves <thePave>", py::arg("thePave"));
	cls_BOPDS_PaveBlock.def("AppendExtPave1", (void (BOPDS_PaveBlock::*)(const BOPDS_Pave &)) &BOPDS_PaveBlock::AppendExtPave1, "Modifier Appends extra pave <thePave>", py::arg("thePave"));
	cls_BOPDS_PaveBlock.def("RemoveExtPave", (void (BOPDS_PaveBlock::*)(const Standard_Integer)) &BOPDS_PaveBlock::RemoveExtPave, "Modifier Removes a pave with the given vertex number from extra paves", py::arg("theVertNum"));
	cls_BOPDS_PaveBlock.def("ExtPaves", (const BOPDS_ListOfPave & (BOPDS_PaveBlock::*)() const ) &BOPDS_PaveBlock::ExtPaves, "Selector Returns the extra paves");
	cls_BOPDS_PaveBlock.def("ChangeExtPaves", (BOPDS_ListOfPave & (BOPDS_PaveBlock::*)()) &BOPDS_PaveBlock::ChangeExtPaves, "Selector / Modifier Returns the extra paves");
	cls_BOPDS_PaveBlock.def("Update", [](BOPDS_PaveBlock &self, BOPDS_ListOfPaveBlock & a0) -> void { return self.Update(a0); }, py::arg("theLPB"));
	cls_BOPDS_PaveBlock.def("Update", (void (BOPDS_PaveBlock::*)(BOPDS_ListOfPaveBlock &, const Standard_Boolean)) &BOPDS_PaveBlock::Update, "Modifier Updates the pave block. The extra paves are used to create new pave blocks <theLPB>. <theFlag> - if true, the first pave and the second pave are used to produce new pave blocks.", py::arg("theLPB"), py::arg("theFlag"));
	cls_BOPDS_PaveBlock.def("ContainsParameter", (Standard_Boolean (BOPDS_PaveBlock::*)(const Standard_Real, const Standard_Real, Standard_Integer &) const ) &BOPDS_PaveBlock::ContainsParameter, "Query Returns true if the extra paves contain the pave with given value of the parameter <thePrm> <theTol> - the value of the tolerance to compare <theInd> - index of the found pave", py::arg("thePrm"), py::arg("theTol"), py::arg("theInd"));
	cls_BOPDS_PaveBlock.def("SetShrunkData", (void (BOPDS_PaveBlock::*)(const Standard_Real, const Standard_Real, const Bnd_Box &, const Standard_Boolean)) &BOPDS_PaveBlock::SetShrunkData, "Modifier Sets the shrunk data for the pave block <theTS1>, <theTS2> - shrunk range <theBox> - the bounding box <theIsSplittable> - defines whether the edge can be split", py::arg("theTS1"), py::arg("theTS2"), py::arg("theBox"), py::arg("theIsSplittable"));
	cls_BOPDS_PaveBlock.def("ShrunkData", (void (BOPDS_PaveBlock::*)(Standard_Real &, Standard_Real &, Bnd_Box &, Standard_Boolean &) const ) &BOPDS_PaveBlock::ShrunkData, "Selector Returns the shrunk data for the pave block <theTS1>, <theTS2> - shrunk range <theBox> - the bounding box <theIsSplittable> - defines whether the edge can be split", py::arg("theTS1"), py::arg("theTS2"), py::arg("theBox"), py::arg("theIsSplittable"));
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
	cls_BOPDS_Pair.def("Indices", (void (BOPDS_Pair::*)(Standard_Integer &, Standard_Integer &) const ) &BOPDS_Pair::Indices, "Gets the indices", py::arg("theIndex1"), py::arg("theIndex2"));
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
	cls_BOPDS_PassKey.def("Ids", (void (BOPDS_PassKey::*)(Standard_Integer &, Standard_Integer &) const ) &BOPDS_PassKey::Ids, "Selector Returns the first two Ids <theI1>,<theI2>", py::arg("theI1"), py::arg("theI2"));
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
	cls_BOPDS_IndexRange.def("Indices", (void (BOPDS_IndexRange::*)(Standard_Integer &, Standard_Integer &) const ) &BOPDS_IndexRange::Indices, "Selector Returns the first index of the range <theI1> Returns the second index of the range <theI2>", py::arg("theI1"), py::arg("theI2"));
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
	cls_BOPDS_ShapeInfo.def("HasFlag", (Standard_Boolean (BOPDS_ShapeInfo::*)(Standard_Integer &) const ) &BOPDS_ShapeInfo::HasFlag, "Query Returns true if there is flag. Returns the the flag theFlag", py::arg("theFlag"));
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
	cls_BOPDS_Interf.def("Indices", (void (BOPDS_Interf::*)(Standard_Integer &, Standard_Integer &) const ) &BOPDS_Interf::Indices, "Returns the indices of interferred shapes", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_Interf.def("SetIndex1", (void (BOPDS_Interf::*)(const Standard_Integer)) &BOPDS_Interf::SetIndex1, "Sets the index of the first interferred shape", py::arg("theIndex"));
	cls_BOPDS_Interf.def("SetIndex2", (void (BOPDS_Interf::*)(const Standard_Integer)) &BOPDS_Interf::SetIndex2, "Sets the index of the second interferred shape", py::arg("theIndex"));
	cls_BOPDS_Interf.def("Index1", (Standard_Integer (BOPDS_Interf::*)() const ) &BOPDS_Interf::Index1, "Returns the index of the first interferred shape");
	cls_BOPDS_Interf.def("Index2", (Standard_Integer (BOPDS_Interf::*)() const ) &BOPDS_Interf::Index2, "Returns the index of the second interferred shape");
	cls_BOPDS_Interf.def("OppositeIndex", (Standard_Integer (BOPDS_Interf::*)(const Standard_Integer) const ) &BOPDS_Interf::OppositeIndex, "Returns the index of that are opposite to the given index", py::arg("theI"));
	cls_BOPDS_Interf.def("Contains", (Standard_Boolean (BOPDS_Interf::*)(const Standard_Integer) const ) &BOPDS_Interf::Contains, "Returns true if the interference contains given index", py::arg("theIndex"));
	cls_BOPDS_Interf.def("SetIndexNew", (void (BOPDS_Interf::*)(const Standard_Integer)) &BOPDS_Interf::SetIndexNew, "Sets the index of new shape", py::arg("theIndex"));
	cls_BOPDS_Interf.def("IndexNew", (Standard_Integer (BOPDS_Interf::*)() const ) &BOPDS_Interf::IndexNew, "Returns the index of new shape");
	cls_BOPDS_Interf.def("HasIndexNew", (Standard_Boolean (BOPDS_Interf::*)(Standard_Integer &) const ) &BOPDS_Interf::HasIndexNew, "Returns true if the interference has index of new shape that is equal to the given index", py::arg("theIndex"));
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
	cls_BOPDS_InterfVF.def("UV", (void (BOPDS_InterfVF::*)(Standard_Real &, Standard_Real &) const ) &BOPDS_InterfVF::UV, "Selector Returns the value of parameters of the point of the vertex on the surface of of the face", py::arg("theU"), py::arg("theV"));

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
	cls_BOPDS_SubIterator.def("Value", (void (BOPDS_SubIterator::*)(Standard_Integer &, Standard_Integer &) const ) &BOPDS_SubIterator::Value, "Returns indices (DS) of intersected shapes theIndex1 - the index of the first shape theIndex2 - the index of the second shape", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_SubIterator.def("Prepare", (void (BOPDS_SubIterator::*)()) &BOPDS_SubIterator::Prepare, "Perform the intersection algorithm and prepare the results to be used");
	cls_BOPDS_SubIterator.def("ExpectedLength", (Standard_Integer (BOPDS_SubIterator::*)() const ) &BOPDS_SubIterator::ExpectedLength, "Returns the number of interfering pairs");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PDS.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PIterator.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<BOPDS_ListOfPave, std::unique_ptr<BOPDS_ListOfPave, Deleter<BOPDS_ListOfPave>>, NCollection_BaseList> cls_BOPDS_ListOfPave(mod, "BOPDS_ListOfPave", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_BOPDS_ListOfPave.def(py::init<>());
	cls_BOPDS_ListOfPave.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPDS_ListOfPave.def(py::init([] (const BOPDS_ListOfPave &other) {return new BOPDS_ListOfPave(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_ListOfPave.def("begin", (BOPDS_ListOfPave::iterator (BOPDS_ListOfPave::*)() const ) &BOPDS_ListOfPave::begin, "Returns an iterator pointing to the first element in the list.");
	cls_BOPDS_ListOfPave.def("end", (BOPDS_ListOfPave::iterator (BOPDS_ListOfPave::*)() const ) &BOPDS_ListOfPave::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_BOPDS_ListOfPave.def("cbegin", (BOPDS_ListOfPave::const_iterator (BOPDS_ListOfPave::*)() const ) &BOPDS_ListOfPave::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_BOPDS_ListOfPave.def("cend", (BOPDS_ListOfPave::const_iterator (BOPDS_ListOfPave::*)() const ) &BOPDS_ListOfPave::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_BOPDS_ListOfPave.def("Size", (Standard_Integer (BOPDS_ListOfPave::*)() const ) &BOPDS_ListOfPave::Size, "Size - Number of items");
	cls_BOPDS_ListOfPave.def("Assign", (BOPDS_ListOfPave & (BOPDS_ListOfPave::*)(const BOPDS_ListOfPave &)) &BOPDS_ListOfPave::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_ListOfPave.def("assign", (BOPDS_ListOfPave & (BOPDS_ListOfPave::*)(const BOPDS_ListOfPave &)) &BOPDS_ListOfPave::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BOPDS_ListOfPave.def("Clear", [](BOPDS_ListOfPave &self) -> void { return self.Clear(); });
	cls_BOPDS_ListOfPave.def("Clear", (void (BOPDS_ListOfPave::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_ListOfPave::Clear, "Clear this list", py::arg("theAllocator"));
	cls_BOPDS_ListOfPave.def("First", (const BOPDS_Pave & (BOPDS_ListOfPave::*)() const ) &BOPDS_ListOfPave::First, "First item");
	cls_BOPDS_ListOfPave.def("First", (BOPDS_Pave & (BOPDS_ListOfPave::*)()) &BOPDS_ListOfPave::First, "First item (non-const)");
	cls_BOPDS_ListOfPave.def("Last", (const BOPDS_Pave & (BOPDS_ListOfPave::*)() const ) &BOPDS_ListOfPave::Last, "Last item");
	cls_BOPDS_ListOfPave.def("Last", (BOPDS_Pave & (BOPDS_ListOfPave::*)()) &BOPDS_ListOfPave::Last, "Last item (non-const)");
	cls_BOPDS_ListOfPave.def("Append", (BOPDS_Pave & (BOPDS_ListOfPave::*)(const BOPDS_Pave &)) &BOPDS_ListOfPave::Append, "Append one item at the end", py::arg("theItem"));
	cls_BOPDS_ListOfPave.def("Append", (void (BOPDS_ListOfPave::*)(const BOPDS_Pave &, BOPDS_ListOfPave::Iterator &)) &BOPDS_ListOfPave::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_BOPDS_ListOfPave.def("Append", (void (BOPDS_ListOfPave::*)(BOPDS_ListOfPave &)) &BOPDS_ListOfPave::Append, "Append another list at the end", py::arg("theOther"));
	cls_BOPDS_ListOfPave.def("Prepend", (BOPDS_Pave & (BOPDS_ListOfPave::*)(const BOPDS_Pave &)) &BOPDS_ListOfPave::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_BOPDS_ListOfPave.def("Prepend", (void (BOPDS_ListOfPave::*)(BOPDS_ListOfPave &)) &BOPDS_ListOfPave::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_BOPDS_ListOfPave.def("RemoveFirst", (void (BOPDS_ListOfPave::*)()) &BOPDS_ListOfPave::RemoveFirst, "RemoveFirst item");
	cls_BOPDS_ListOfPave.def("Remove", (void (BOPDS_ListOfPave::*)(BOPDS_ListOfPave::Iterator &)) &BOPDS_ListOfPave::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_BOPDS_ListOfPave.def("InsertBefore", (BOPDS_Pave & (BOPDS_ListOfPave::*)(const BOPDS_Pave &, BOPDS_ListOfPave::Iterator &)) &BOPDS_ListOfPave::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_BOPDS_ListOfPave.def("InsertBefore", (void (BOPDS_ListOfPave::*)(BOPDS_ListOfPave &, BOPDS_ListOfPave::Iterator &)) &BOPDS_ListOfPave::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_BOPDS_ListOfPave.def("InsertAfter", (BOPDS_Pave & (BOPDS_ListOfPave::*)(const BOPDS_Pave &, BOPDS_ListOfPave::Iterator &)) &BOPDS_ListOfPave::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_BOPDS_ListOfPave.def("InsertAfter", (void (BOPDS_ListOfPave::*)(BOPDS_ListOfPave &, BOPDS_ListOfPave::Iterator &)) &BOPDS_ListOfPave::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_BOPDS_ListOfPave.def("Reverse", (void (BOPDS_ListOfPave::*)()) &BOPDS_ListOfPave::Reverse, "Reverse the list");
	cls_BOPDS_ListOfPave.def("__iter__", [](const BOPDS_ListOfPave &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<BOPDS_ListIteratorOfListOfPave, std::unique_ptr<BOPDS_ListIteratorOfListOfPave, Deleter<BOPDS_ListIteratorOfListOfPave>>> cls_BOPDS_ListIteratorOfListOfPave(mod, "BOPDS_ListIteratorOfListOfPave", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_BOPDS_ListIteratorOfListOfPave.def(py::init<>());
	cls_BOPDS_ListIteratorOfListOfPave.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_BOPDS_ListIteratorOfListOfPave.def("More", (Standard_Boolean (BOPDS_ListIteratorOfListOfPave::*)() const ) &BOPDS_ListIteratorOfListOfPave::More, "Check end");
	cls_BOPDS_ListIteratorOfListOfPave.def("Next", (void (BOPDS_ListIteratorOfListOfPave::*)()) &BOPDS_ListIteratorOfListOfPave::Next, "Make step");
	cls_BOPDS_ListIteratorOfListOfPave.def("Value", (const BOPDS_Pave & (BOPDS_ListIteratorOfListOfPave::*)() const ) &BOPDS_ListIteratorOfListOfPave::Value, "Constant Value access");
	cls_BOPDS_ListIteratorOfListOfPave.def("Value", (BOPDS_Pave & (BOPDS_ListIteratorOfListOfPave::*)()) &BOPDS_ListIteratorOfListOfPave::Value, "Non-const Value access");
	cls_BOPDS_ListIteratorOfListOfPave.def("ChangeValue", (BOPDS_Pave & (BOPDS_ListIteratorOfListOfPave::*)() const ) &BOPDS_ListIteratorOfListOfPave::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<BOPDS_ListOfPaveBlock, std::unique_ptr<BOPDS_ListOfPaveBlock, Deleter<BOPDS_ListOfPaveBlock>>, NCollection_BaseList> cls_BOPDS_ListOfPaveBlock(mod, "BOPDS_ListOfPaveBlock", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_BOPDS_ListOfPaveBlock.def(py::init<>());
	cls_BOPDS_ListOfPaveBlock.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPDS_ListOfPaveBlock.def(py::init([] (const BOPDS_ListOfPaveBlock &other) {return new BOPDS_ListOfPaveBlock(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_ListOfPaveBlock.def("begin", (BOPDS_ListOfPaveBlock::iterator (BOPDS_ListOfPaveBlock::*)() const ) &BOPDS_ListOfPaveBlock::begin, "Returns an iterator pointing to the first element in the list.");
	cls_BOPDS_ListOfPaveBlock.def("end", (BOPDS_ListOfPaveBlock::iterator (BOPDS_ListOfPaveBlock::*)() const ) &BOPDS_ListOfPaveBlock::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_BOPDS_ListOfPaveBlock.def("cbegin", (BOPDS_ListOfPaveBlock::const_iterator (BOPDS_ListOfPaveBlock::*)() const ) &BOPDS_ListOfPaveBlock::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_BOPDS_ListOfPaveBlock.def("cend", (BOPDS_ListOfPaveBlock::const_iterator (BOPDS_ListOfPaveBlock::*)() const ) &BOPDS_ListOfPaveBlock::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_BOPDS_ListOfPaveBlock.def("Size", (Standard_Integer (BOPDS_ListOfPaveBlock::*)() const ) &BOPDS_ListOfPaveBlock::Size, "Size - Number of items");
	cls_BOPDS_ListOfPaveBlock.def("Assign", (BOPDS_ListOfPaveBlock & (BOPDS_ListOfPaveBlock::*)(const BOPDS_ListOfPaveBlock &)) &BOPDS_ListOfPaveBlock::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_ListOfPaveBlock.def("assign", (BOPDS_ListOfPaveBlock & (BOPDS_ListOfPaveBlock::*)(const BOPDS_ListOfPaveBlock &)) &BOPDS_ListOfPaveBlock::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BOPDS_ListOfPaveBlock.def("Clear", [](BOPDS_ListOfPaveBlock &self) -> void { return self.Clear(); });
	cls_BOPDS_ListOfPaveBlock.def("Clear", (void (BOPDS_ListOfPaveBlock::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_ListOfPaveBlock::Clear, "Clear this list", py::arg("theAllocator"));
	cls_BOPDS_ListOfPaveBlock.def("First", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_ListOfPaveBlock::*)() const ) &BOPDS_ListOfPaveBlock::First, "First item");
	cls_BOPDS_ListOfPaveBlock.def("First", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_ListOfPaveBlock::*)()) &BOPDS_ListOfPaveBlock::First, "First item (non-const)");
	cls_BOPDS_ListOfPaveBlock.def("Last", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_ListOfPaveBlock::*)() const ) &BOPDS_ListOfPaveBlock::Last, "Last item");
	cls_BOPDS_ListOfPaveBlock.def("Last", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_ListOfPaveBlock::*)()) &BOPDS_ListOfPaveBlock::Last, "Last item (non-const)");
	cls_BOPDS_ListOfPaveBlock.def("Append", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_ListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_ListOfPaveBlock::Append, "Append one item at the end", py::arg("theItem"));
	cls_BOPDS_ListOfPaveBlock.def("Append", (void (BOPDS_ListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &, BOPDS_ListOfPaveBlock::Iterator &)) &BOPDS_ListOfPaveBlock::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_BOPDS_ListOfPaveBlock.def("Append", (void (BOPDS_ListOfPaveBlock::*)(BOPDS_ListOfPaveBlock &)) &BOPDS_ListOfPaveBlock::Append, "Append another list at the end", py::arg("theOther"));
	cls_BOPDS_ListOfPaveBlock.def("Prepend", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_ListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_ListOfPaveBlock::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_BOPDS_ListOfPaveBlock.def("Prepend", (void (BOPDS_ListOfPaveBlock::*)(BOPDS_ListOfPaveBlock &)) &BOPDS_ListOfPaveBlock::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_BOPDS_ListOfPaveBlock.def("RemoveFirst", (void (BOPDS_ListOfPaveBlock::*)()) &BOPDS_ListOfPaveBlock::RemoveFirst, "RemoveFirst item");
	cls_BOPDS_ListOfPaveBlock.def("Remove", (void (BOPDS_ListOfPaveBlock::*)(BOPDS_ListOfPaveBlock::Iterator &)) &BOPDS_ListOfPaveBlock::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_BOPDS_ListOfPaveBlock.def("InsertBefore", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_ListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &, BOPDS_ListOfPaveBlock::Iterator &)) &BOPDS_ListOfPaveBlock::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_BOPDS_ListOfPaveBlock.def("InsertBefore", (void (BOPDS_ListOfPaveBlock::*)(BOPDS_ListOfPaveBlock &, BOPDS_ListOfPaveBlock::Iterator &)) &BOPDS_ListOfPaveBlock::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_BOPDS_ListOfPaveBlock.def("InsertAfter", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_ListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &, BOPDS_ListOfPaveBlock::Iterator &)) &BOPDS_ListOfPaveBlock::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_BOPDS_ListOfPaveBlock.def("InsertAfter", (void (BOPDS_ListOfPaveBlock::*)(BOPDS_ListOfPaveBlock &, BOPDS_ListOfPaveBlock::Iterator &)) &BOPDS_ListOfPaveBlock::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_BOPDS_ListOfPaveBlock.def("Reverse", (void (BOPDS_ListOfPaveBlock::*)()) &BOPDS_ListOfPaveBlock::Reverse, "Reverse the list");
	cls_BOPDS_ListOfPaveBlock.def("__iter__", [](const BOPDS_ListOfPaveBlock &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<BOPDS_ListIteratorOfListOfPaveBlock, std::unique_ptr<BOPDS_ListIteratorOfListOfPaveBlock, Deleter<BOPDS_ListIteratorOfListOfPaveBlock>>> cls_BOPDS_ListIteratorOfListOfPaveBlock(mod, "BOPDS_ListIteratorOfListOfPaveBlock", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_BOPDS_ListIteratorOfListOfPaveBlock.def(py::init<>());
	cls_BOPDS_ListIteratorOfListOfPaveBlock.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_BOPDS_ListIteratorOfListOfPaveBlock.def("More", (Standard_Boolean (BOPDS_ListIteratorOfListOfPaveBlock::*)() const ) &BOPDS_ListIteratorOfListOfPaveBlock::More, "Check end");
	cls_BOPDS_ListIteratorOfListOfPaveBlock.def("Next", (void (BOPDS_ListIteratorOfListOfPaveBlock::*)()) &BOPDS_ListIteratorOfListOfPaveBlock::Next, "Make step");
	cls_BOPDS_ListIteratorOfListOfPaveBlock.def("Value", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_ListIteratorOfListOfPaveBlock::*)() const ) &BOPDS_ListIteratorOfListOfPaveBlock::Value, "Constant Value access");
	cls_BOPDS_ListIteratorOfListOfPaveBlock.def("Value", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_ListIteratorOfListOfPaveBlock::*)()) &BOPDS_ListIteratorOfListOfPaveBlock::Value, "Non-const Value access");
	cls_BOPDS_ListIteratorOfListOfPaveBlock.def("ChangeValue", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_ListIteratorOfListOfPaveBlock::*)() const ) &BOPDS_ListIteratorOfListOfPaveBlock::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks, std::unique_ptr<BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks, Deleter<BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks>>, NCollection_BaseMap> cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks(mod, "BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def(py::init<>());
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def(py::init([] (const BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks &other) {return new BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("begin", (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::iterator (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)() const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("end", (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::iterator (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)() const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("cbegin", (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::const_iterator (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)() const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("cend", (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::const_iterator (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)() const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("Exchange", (void (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks &)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("Assign", (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks & (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks &)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("assign", (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks & (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks &)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("ReSize", (void (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("Add", (Standard_Integer (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &, const BOPDS_CoupleOfPaveBlocks &)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("Contains", (Standard_Boolean (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &) const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::Contains, "Contains", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("Substitute", (void (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Integer, const TopoDS_Shape &, const BOPDS_CoupleOfPaveBlocks &)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("Swap", (void (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("RemoveLast", (void (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)()) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::RemoveLast, "RemoveLast");
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("RemoveFromIndex", (void (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("RemoveKey", (void (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("FindKey", (const TopoDS_Shape & (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Integer) const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::FindKey, "FindKey", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("FindFromIndex", (const BOPDS_CoupleOfPaveBlocks & (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Integer) const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("__call__", (const BOPDS_CoupleOfPaveBlocks & (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Integer) const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("ChangeFromIndex", (BOPDS_CoupleOfPaveBlocks & (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("__call__", (BOPDS_CoupleOfPaveBlocks & (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("FindIndex", (Standard_Integer (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &) const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("FindFromKey", (const BOPDS_CoupleOfPaveBlocks & (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &) const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("ChangeFromKey", (BOPDS_CoupleOfPaveBlocks & (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("Seek", (const BOPDS_CoupleOfPaveBlocks * (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &) const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("ChangeSeek", (BOPDS_CoupleOfPaveBlocks * (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("FindFromKey", (Standard_Boolean (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &, BOPDS_CoupleOfPaveBlocks &) const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("Clear", [](BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks &self) -> void { return self.Clear(); });
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("Clear", (void (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Boolean)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("Clear", (void (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("Size", (Standard_Integer (BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::*)() const ) &BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks::Size, "Size");
	cls_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.def("__iter__", [](const BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedMap.hxx
	py::class_<BOPDS_IndexedMapOfPaveBlock, std::unique_ptr<BOPDS_IndexedMapOfPaveBlock, Deleter<BOPDS_IndexedMapOfPaveBlock>>, NCollection_BaseMap> cls_BOPDS_IndexedMapOfPaveBlock(mod, "BOPDS_IndexedMapOfPaveBlock", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1..Extent. See the class Map from NCollection for a discussion about the number of buckets.");
	cls_BOPDS_IndexedMapOfPaveBlock.def(py::init<>());
	cls_BOPDS_IndexedMapOfPaveBlock.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_IndexedMapOfPaveBlock.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_IndexedMapOfPaveBlock.def(py::init([] (const BOPDS_IndexedMapOfPaveBlock &other) {return new BOPDS_IndexedMapOfPaveBlock(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("cbegin", (BOPDS_IndexedMapOfPaveBlock::const_iterator (BOPDS_IndexedMapOfPaveBlock::*)() const ) &BOPDS_IndexedMapOfPaveBlock::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_IndexedMapOfPaveBlock.def("cend", (BOPDS_IndexedMapOfPaveBlock::const_iterator (BOPDS_IndexedMapOfPaveBlock::*)() const ) &BOPDS_IndexedMapOfPaveBlock::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_IndexedMapOfPaveBlock.def("Exchange", (void (BOPDS_IndexedMapOfPaveBlock::*)(BOPDS_IndexedMapOfPaveBlock &)) &BOPDS_IndexedMapOfPaveBlock::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("Assign", (BOPDS_IndexedMapOfPaveBlock & (BOPDS_IndexedMapOfPaveBlock::*)(const BOPDS_IndexedMapOfPaveBlock &)) &BOPDS_IndexedMapOfPaveBlock::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("assign", (BOPDS_IndexedMapOfPaveBlock & (BOPDS_IndexedMapOfPaveBlock::*)(const BOPDS_IndexedMapOfPaveBlock &)) &BOPDS_IndexedMapOfPaveBlock::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("ReSize", (void (BOPDS_IndexedMapOfPaveBlock::*)(const Standard_Integer)) &BOPDS_IndexedMapOfPaveBlock::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("Add", (Standard_Integer (BOPDS_IndexedMapOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_IndexedMapOfPaveBlock::Add, "Add", py::arg("theKey1"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("Contains", (Standard_Boolean (BOPDS_IndexedMapOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_IndexedMapOfPaveBlock::Contains, "Contains", py::arg("theKey1"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("Substitute", (void (BOPDS_IndexedMapOfPaveBlock::*)(const Standard_Integer, const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_IndexedMapOfPaveBlock::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("Swap", (void (BOPDS_IndexedMapOfPaveBlock::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_IndexedMapOfPaveBlock::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("RemoveLast", (void (BOPDS_IndexedMapOfPaveBlock::*)()) &BOPDS_IndexedMapOfPaveBlock::RemoveLast, "RemoveLast");
	cls_BOPDS_IndexedMapOfPaveBlock.def("RemoveFromIndex", (void (BOPDS_IndexedMapOfPaveBlock::*)(const Standard_Integer)) &BOPDS_IndexedMapOfPaveBlock::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("RemoveKey", (Standard_Boolean (BOPDS_IndexedMapOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_IndexedMapOfPaveBlock::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("FindKey", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_IndexedMapOfPaveBlock::*)(const Standard_Integer) const ) &BOPDS_IndexedMapOfPaveBlock::FindKey, "FindKey", py::arg("theKey2"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("__call__", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_IndexedMapOfPaveBlock::*)(const Standard_Integer) const ) &BOPDS_IndexedMapOfPaveBlock::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("FindIndex", (Standard_Integer (BOPDS_IndexedMapOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_IndexedMapOfPaveBlock::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("Clear", [](BOPDS_IndexedMapOfPaveBlock &self) -> void { return self.Clear(); });
	cls_BOPDS_IndexedMapOfPaveBlock.def("Clear", (void (BOPDS_IndexedMapOfPaveBlock::*)(const Standard_Boolean)) &BOPDS_IndexedMapOfPaveBlock::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("Clear", (void (BOPDS_IndexedMapOfPaveBlock::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_IndexedMapOfPaveBlock::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_IndexedMapOfPaveBlock.def("Size", (Standard_Integer (BOPDS_IndexedMapOfPaveBlock::*)() const ) &BOPDS_IndexedMapOfPaveBlock::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BOPDS_DataMapOfPaveBlockListOfPaveBlock, std::unique_ptr<BOPDS_DataMapOfPaveBlockListOfPaveBlock, Deleter<BOPDS_DataMapOfPaveBlockListOfPaveBlock>>, NCollection_BaseMap> cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock(mod, "BOPDS_DataMapOfPaveBlockListOfPaveBlock", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def(py::init<>());
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def(py::init([] (const BOPDS_DataMapOfPaveBlockListOfPaveBlock &other) {return new BOPDS_DataMapOfPaveBlockListOfPaveBlock(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("begin", (BOPDS_DataMapOfPaveBlockListOfPaveBlock::iterator (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)() const ) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("end", (BOPDS_DataMapOfPaveBlockListOfPaveBlock::iterator (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)() const ) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("cbegin", (BOPDS_DataMapOfPaveBlockListOfPaveBlock::const_iterator (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)() const ) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("cend", (BOPDS_DataMapOfPaveBlockListOfPaveBlock::const_iterator (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)() const ) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("Exchange", (void (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(BOPDS_DataMapOfPaveBlockListOfPaveBlock &)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("Assign", (BOPDS_DataMapOfPaveBlockListOfPaveBlock & (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const BOPDS_DataMapOfPaveBlockListOfPaveBlock &)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("assign", (BOPDS_DataMapOfPaveBlockListOfPaveBlock & (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const BOPDS_DataMapOfPaveBlockListOfPaveBlock &)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("ReSize", (void (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Integer)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("Bind", (Standard_Boolean (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &, const BOPDS_ListOfPaveBlock &)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("Bound", (BOPDS_ListOfPaveBlock * (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &, const BOPDS_ListOfPaveBlock &)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("IsBound", (Standard_Boolean (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::IsBound, "IsBound", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("UnBind", (Standard_Boolean (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("Seek", (const BOPDS_ListOfPaveBlock * (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("Find", (const BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("Find", (Standard_Boolean (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &, BOPDS_ListOfPaveBlock &) const ) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("__call__", (const BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("ChangeSeek", (BOPDS_ListOfPaveBlock * (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("ChangeFind", (BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("__call__", (BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("Clear", [](BOPDS_DataMapOfPaveBlockListOfPaveBlock &self) -> void { return self.Clear(); });
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("Clear", (void (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Boolean)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("Clear", (void (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("Size", (Standard_Integer (BOPDS_DataMapOfPaveBlockListOfPaveBlock::*)() const ) &BOPDS_DataMapOfPaveBlockListOfPaveBlock::Size, "Size");
	cls_BOPDS_DataMapOfPaveBlockListOfPaveBlock.def("__iter__", [](const BOPDS_DataMapOfPaveBlockListOfPaveBlock &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPaveBlockListOfPaveBlock.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<BOPDS_MapOfPaveBlock, std::unique_ptr<BOPDS_MapOfPaveBlock, Deleter<BOPDS_MapOfPaveBlock>>, NCollection_BaseMap> cls_BOPDS_MapOfPaveBlock(mod, "BOPDS_MapOfPaveBlock", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_BOPDS_MapOfPaveBlock.def(py::init<>());
	cls_BOPDS_MapOfPaveBlock.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_MapOfPaveBlock.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_MapOfPaveBlock.def(py::init([] (const BOPDS_MapOfPaveBlock &other) {return new BOPDS_MapOfPaveBlock(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_MapOfPaveBlock.def("cbegin", (BOPDS_MapOfPaveBlock::const_iterator (BOPDS_MapOfPaveBlock::*)() const ) &BOPDS_MapOfPaveBlock::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_MapOfPaveBlock.def("cend", (BOPDS_MapOfPaveBlock::const_iterator (BOPDS_MapOfPaveBlock::*)() const ) &BOPDS_MapOfPaveBlock::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_MapOfPaveBlock.def("Exchange", (void (BOPDS_MapOfPaveBlock::*)(BOPDS_MapOfPaveBlock &)) &BOPDS_MapOfPaveBlock::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_MapOfPaveBlock.def("Assign", (BOPDS_MapOfPaveBlock & (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &)) &BOPDS_MapOfPaveBlock::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_MapOfPaveBlock.def("assign", (BOPDS_MapOfPaveBlock & (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &)) &BOPDS_MapOfPaveBlock::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_BOPDS_MapOfPaveBlock.def("ReSize", (void (BOPDS_MapOfPaveBlock::*)(const Standard_Integer)) &BOPDS_MapOfPaveBlock::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_MapOfPaveBlock.def("Add", (Standard_Boolean (BOPDS_MapOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_MapOfPaveBlock::Add, "Add", py::arg("K"));
	cls_BOPDS_MapOfPaveBlock.def("Added", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_MapOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_MapOfPaveBlock::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_BOPDS_MapOfPaveBlock.def("Contains", (Standard_Boolean (BOPDS_MapOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_MapOfPaveBlock::Contains, "Contains", py::arg("K"));
	cls_BOPDS_MapOfPaveBlock.def("Remove", (Standard_Boolean (BOPDS_MapOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_MapOfPaveBlock::Remove, "Remove", py::arg("K"));
	cls_BOPDS_MapOfPaveBlock.def("Clear", [](BOPDS_MapOfPaveBlock &self) -> void { return self.Clear(); });
	cls_BOPDS_MapOfPaveBlock.def("Clear", (void (BOPDS_MapOfPaveBlock::*)(const Standard_Boolean)) &BOPDS_MapOfPaveBlock::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_MapOfPaveBlock.def("Clear", (void (BOPDS_MapOfPaveBlock::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_MapOfPaveBlock::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_MapOfPaveBlock.def("Size", (Standard_Integer (BOPDS_MapOfPaveBlock::*)() const ) &BOPDS_MapOfPaveBlock::Size, "Size");
	cls_BOPDS_MapOfPaveBlock.def("IsEqual", (Standard_Boolean (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &) const ) &BOPDS_MapOfPaveBlock::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_BOPDS_MapOfPaveBlock.def("Contains", (Standard_Boolean (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &) const ) &BOPDS_MapOfPaveBlock::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_BOPDS_MapOfPaveBlock.def("Union", (void (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &, const BOPDS_MapOfPaveBlock &)) &BOPDS_MapOfPaveBlock::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPaveBlock.def("Unite", (Standard_Boolean (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &)) &BOPDS_MapOfPaveBlock::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPaveBlock.def("HasIntersection", (Standard_Boolean (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &) const ) &BOPDS_MapOfPaveBlock::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_BOPDS_MapOfPaveBlock.def("Intersection", (void (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &, const BOPDS_MapOfPaveBlock &)) &BOPDS_MapOfPaveBlock::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPaveBlock.def("Intersect", (Standard_Boolean (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &)) &BOPDS_MapOfPaveBlock::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPaveBlock.def("Subtraction", (void (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &, const BOPDS_MapOfPaveBlock &)) &BOPDS_MapOfPaveBlock::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPaveBlock.def("Subtract", (Standard_Boolean (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &)) &BOPDS_MapOfPaveBlock::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPaveBlock.def("Difference", (void (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &, const BOPDS_MapOfPaveBlock &)) &BOPDS_MapOfPaveBlock::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPaveBlock.def("Differ", (Standard_Boolean (BOPDS_MapOfPaveBlock::*)(const BOPDS_MapOfPaveBlock &)) &BOPDS_MapOfPaveBlock::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPaveBlock.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<BOPDS_MapOfPair, std::unique_ptr<BOPDS_MapOfPair, Deleter<BOPDS_MapOfPair>>, NCollection_BaseMap> cls_BOPDS_MapOfPair(mod, "BOPDS_MapOfPair", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_BOPDS_MapOfPair.def(py::init<>());
	cls_BOPDS_MapOfPair.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_MapOfPair.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_MapOfPair.def(py::init([] (const BOPDS_MapOfPair &other) {return new BOPDS_MapOfPair(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_MapOfPair.def("cbegin", (BOPDS_MapOfPair::const_iterator (BOPDS_MapOfPair::*)() const ) &BOPDS_MapOfPair::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_MapOfPair.def("cend", (BOPDS_MapOfPair::const_iterator (BOPDS_MapOfPair::*)() const ) &BOPDS_MapOfPair::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_MapOfPair.def("Exchange", (void (BOPDS_MapOfPair::*)(BOPDS_MapOfPair &)) &BOPDS_MapOfPair::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_MapOfPair.def("Assign", (BOPDS_MapOfPair & (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &)) &BOPDS_MapOfPair::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_MapOfPair.def("assign", (BOPDS_MapOfPair & (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &)) &BOPDS_MapOfPair::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_BOPDS_MapOfPair.def("ReSize", (void (BOPDS_MapOfPair::*)(const Standard_Integer)) &BOPDS_MapOfPair::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_MapOfPair.def("Add", (Standard_Boolean (BOPDS_MapOfPair::*)(const BOPDS_Pair &)) &BOPDS_MapOfPair::Add, "Add", py::arg("K"));
	cls_BOPDS_MapOfPair.def("Added", (const BOPDS_Pair & (BOPDS_MapOfPair::*)(const BOPDS_Pair &)) &BOPDS_MapOfPair::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_BOPDS_MapOfPair.def("Contains", (Standard_Boolean (BOPDS_MapOfPair::*)(const BOPDS_Pair &) const ) &BOPDS_MapOfPair::Contains, "Contains", py::arg("K"));
	cls_BOPDS_MapOfPair.def("Remove", (Standard_Boolean (BOPDS_MapOfPair::*)(const BOPDS_Pair &)) &BOPDS_MapOfPair::Remove, "Remove", py::arg("K"));
	cls_BOPDS_MapOfPair.def("Clear", [](BOPDS_MapOfPair &self) -> void { return self.Clear(); });
	cls_BOPDS_MapOfPair.def("Clear", (void (BOPDS_MapOfPair::*)(const Standard_Boolean)) &BOPDS_MapOfPair::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_MapOfPair.def("Clear", (void (BOPDS_MapOfPair::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_MapOfPair::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_MapOfPair.def("Size", (Standard_Integer (BOPDS_MapOfPair::*)() const ) &BOPDS_MapOfPair::Size, "Size");
	cls_BOPDS_MapOfPair.def("IsEqual", (Standard_Boolean (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &) const ) &BOPDS_MapOfPair::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_BOPDS_MapOfPair.def("Contains", (Standard_Boolean (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &) const ) &BOPDS_MapOfPair::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_BOPDS_MapOfPair.def("Union", (void (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &, const BOPDS_MapOfPair &)) &BOPDS_MapOfPair::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPair.def("Unite", (Standard_Boolean (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &)) &BOPDS_MapOfPair::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPair.def("HasIntersection", (Standard_Boolean (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &) const ) &BOPDS_MapOfPair::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_BOPDS_MapOfPair.def("Intersection", (void (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &, const BOPDS_MapOfPair &)) &BOPDS_MapOfPair::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPair.def("Intersect", (Standard_Boolean (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &)) &BOPDS_MapOfPair::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPair.def("Subtraction", (void (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &, const BOPDS_MapOfPair &)) &BOPDS_MapOfPair::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPair.def("Subtract", (Standard_Boolean (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &)) &BOPDS_MapOfPair::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPair.def("Difference", (void (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &, const BOPDS_MapOfPair &)) &BOPDS_MapOfPair::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPair.def("Differ", (Standard_Boolean (BOPDS_MapOfPair::*)(const BOPDS_MapOfPair &)) &BOPDS_MapOfPair::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPair.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfCurve, std::unique_ptr<BOPDS_VectorOfCurve, Deleter<BOPDS_VectorOfCurve>>> cls_BOPDS_VectorOfCurve(mod, "BOPDS_VectorOfCurve", "None");
	cls_BOPDS_VectorOfCurve.def(py::init<>());
	cls_BOPDS_VectorOfCurve.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfCurve.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfCurve.def("Append1", (BOPDS_Curve & (BOPDS_VectorOfCurve::*)()) &BOPDS_VectorOfCurve::Append1, "None");
	cls_BOPDS_VectorOfCurve.def("Extent", (Standard_Integer (BOPDS_VectorOfCurve::*)() const ) &BOPDS_VectorOfCurve::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<BOPDS_IndexedDataMapOfPaveBlockListOfInteger, std::unique_ptr<BOPDS_IndexedDataMapOfPaveBlockListOfInteger, Deleter<BOPDS_IndexedDataMapOfPaveBlockListOfInteger>>, NCollection_BaseMap> cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger(mod, "BOPDS_IndexedDataMapOfPaveBlockListOfInteger", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def(py::init<>());
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def(py::init([] (const BOPDS_IndexedDataMapOfPaveBlockListOfInteger &other) {return new BOPDS_IndexedDataMapOfPaveBlockListOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("begin", (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::iterator (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)() const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("end", (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::iterator (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)() const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("cbegin", (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::const_iterator (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)() const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("cend", (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::const_iterator (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)() const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("Exchange", (void (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(BOPDS_IndexedDataMapOfPaveBlockListOfInteger &)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("Assign", (BOPDS_IndexedDataMapOfPaveBlockListOfInteger & (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const BOPDS_IndexedDataMapOfPaveBlockListOfInteger &)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("assign", (BOPDS_IndexedDataMapOfPaveBlockListOfInteger & (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const BOPDS_IndexedDataMapOfPaveBlockListOfInteger &)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("ReSize", (void (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("Add", (Standard_Integer (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &, const BOPCol_ListOfInteger &)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("Contains", (Standard_Boolean (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::Contains, "Contains", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("Substitute", (void (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const Standard_Integer, const opencascade::handle<BOPDS_PaveBlock> &, const BOPCol_ListOfInteger &)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("Swap", (void (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("RemoveLast", (void (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)()) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::RemoveLast, "RemoveLast");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("RemoveFromIndex", (void (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("RemoveKey", (void (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("FindKey", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const Standard_Integer) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::FindKey, "FindKey", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("FindFromIndex", (const BOPCol_ListOfInteger & (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const Standard_Integer) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("__call__", (const BOPCol_ListOfInteger & (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const Standard_Integer) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("ChangeFromIndex", (BOPCol_ListOfInteger & (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("__call__", (BOPCol_ListOfInteger & (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("FindIndex", (Standard_Integer (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("FindFromKey", (const BOPCol_ListOfInteger & (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("ChangeFromKey", (BOPCol_ListOfInteger & (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("Seek", (const BOPCol_ListOfInteger * (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("ChangeSeek", (BOPCol_ListOfInteger * (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("FindFromKey", (Standard_Boolean (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &, BOPCol_ListOfInteger &) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("Clear", [](BOPDS_IndexedDataMapOfPaveBlockListOfInteger &self) -> void { return self.Clear(); });
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("Clear", (void (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const Standard_Boolean)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("Clear", (void (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("Size", (Standard_Integer (BOPDS_IndexedDataMapOfPaveBlockListOfInteger::*)() const ) &BOPDS_IndexedDataMapOfPaveBlockListOfInteger::Size, "Size");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfInteger.def("__iter__", [](const BOPDS_IndexedDataMapOfPaveBlockListOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock, std::unique_ptr<BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock, Deleter<BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock>>, NCollection_BaseMap> cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock(mod, "BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def(py::init<>());
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def(py::init([] (const BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock &other) {return new BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("begin", (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::iterator (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)() const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("end", (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::iterator (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)() const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("cbegin", (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::const_iterator (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)() const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("cend", (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::const_iterator (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)() const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("Exchange", (void (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock &)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("Assign", (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock & (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock &)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("assign", (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock & (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock &)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("ReSize", (void (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("Add", (Standard_Integer (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &, const BOPDS_ListOfPaveBlock &)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("Contains", (Standard_Boolean (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::Contains, "Contains", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("Substitute", (void (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Integer, const opencascade::handle<BOPDS_PaveBlock> &, const BOPDS_ListOfPaveBlock &)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("Swap", (void (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("RemoveLast", (void (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)()) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::RemoveLast, "RemoveLast");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("RemoveFromIndex", (void (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("RemoveKey", (void (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("FindKey", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Integer) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::FindKey, "FindKey", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("FindFromIndex", (const BOPDS_ListOfPaveBlock & (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Integer) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("__call__", (const BOPDS_ListOfPaveBlock & (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Integer) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("ChangeFromIndex", (BOPDS_ListOfPaveBlock & (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("__call__", (BOPDS_ListOfPaveBlock & (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Integer)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("FindIndex", (Standard_Integer (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("FindFromKey", (const BOPDS_ListOfPaveBlock & (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("ChangeFromKey", (BOPDS_ListOfPaveBlock & (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("Seek", (const BOPDS_ListOfPaveBlock * (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("ChangeSeek", (BOPDS_ListOfPaveBlock * (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("FindFromKey", (Standard_Boolean (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &, BOPDS_ListOfPaveBlock &) const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("Clear", [](BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock &self) -> void { return self.Clear(); });
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("Clear", (void (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const Standard_Boolean)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("Clear", (void (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("Size", (Standard_Integer (BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::*)() const ) &BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock::Size, "Size");
	cls_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.def("__iter__", [](const BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BOPDS_DataMapOfIntegerListOfPaveBlock, std::unique_ptr<BOPDS_DataMapOfIntegerListOfPaveBlock, Deleter<BOPDS_DataMapOfIntegerListOfPaveBlock>>, NCollection_BaseMap> cls_BOPDS_DataMapOfIntegerListOfPaveBlock(mod, "BOPDS_DataMapOfIntegerListOfPaveBlock", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def(py::init<>());
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def(py::init([] (const BOPDS_DataMapOfIntegerListOfPaveBlock &other) {return new BOPDS_DataMapOfIntegerListOfPaveBlock(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("begin", (BOPDS_DataMapOfIntegerListOfPaveBlock::iterator (BOPDS_DataMapOfIntegerListOfPaveBlock::*)() const ) &BOPDS_DataMapOfIntegerListOfPaveBlock::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("end", (BOPDS_DataMapOfIntegerListOfPaveBlock::iterator (BOPDS_DataMapOfIntegerListOfPaveBlock::*)() const ) &BOPDS_DataMapOfIntegerListOfPaveBlock::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("cbegin", (BOPDS_DataMapOfIntegerListOfPaveBlock::const_iterator (BOPDS_DataMapOfIntegerListOfPaveBlock::*)() const ) &BOPDS_DataMapOfIntegerListOfPaveBlock::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("cend", (BOPDS_DataMapOfIntegerListOfPaveBlock::const_iterator (BOPDS_DataMapOfIntegerListOfPaveBlock::*)() const ) &BOPDS_DataMapOfIntegerListOfPaveBlock::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("Exchange", (void (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(BOPDS_DataMapOfIntegerListOfPaveBlock &)) &BOPDS_DataMapOfIntegerListOfPaveBlock::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("Assign", (BOPDS_DataMapOfIntegerListOfPaveBlock & (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const BOPDS_DataMapOfIntegerListOfPaveBlock &)) &BOPDS_DataMapOfIntegerListOfPaveBlock::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("assign", (BOPDS_DataMapOfIntegerListOfPaveBlock & (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const BOPDS_DataMapOfIntegerListOfPaveBlock &)) &BOPDS_DataMapOfIntegerListOfPaveBlock::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("ReSize", (void (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer)) &BOPDS_DataMapOfIntegerListOfPaveBlock::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("Bind", (Standard_Boolean (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer &, const BOPDS_ListOfPaveBlock &)) &BOPDS_DataMapOfIntegerListOfPaveBlock::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("Bound", (BOPDS_ListOfPaveBlock * (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer &, const BOPDS_ListOfPaveBlock &)) &BOPDS_DataMapOfIntegerListOfPaveBlock::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("IsBound", (Standard_Boolean (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer &) const ) &BOPDS_DataMapOfIntegerListOfPaveBlock::IsBound, "IsBound", py::arg("theKey"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("UnBind", (Standard_Boolean (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer &)) &BOPDS_DataMapOfIntegerListOfPaveBlock::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("Seek", (const BOPDS_ListOfPaveBlock * (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer &) const ) &BOPDS_DataMapOfIntegerListOfPaveBlock::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("Find", (const BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer &) const ) &BOPDS_DataMapOfIntegerListOfPaveBlock::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("Find", (Standard_Boolean (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer &, BOPDS_ListOfPaveBlock &) const ) &BOPDS_DataMapOfIntegerListOfPaveBlock::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("__call__", (const BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer &) const ) &BOPDS_DataMapOfIntegerListOfPaveBlock::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("ChangeSeek", (BOPDS_ListOfPaveBlock * (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer &)) &BOPDS_DataMapOfIntegerListOfPaveBlock::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("ChangeFind", (BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer &)) &BOPDS_DataMapOfIntegerListOfPaveBlock::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("__call__", (BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Integer &)) &BOPDS_DataMapOfIntegerListOfPaveBlock::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("Clear", [](BOPDS_DataMapOfIntegerListOfPaveBlock &self) -> void { return self.Clear(); });
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("Clear", (void (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const Standard_Boolean)) &BOPDS_DataMapOfIntegerListOfPaveBlock::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("Clear", (void (BOPDS_DataMapOfIntegerListOfPaveBlock::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_DataMapOfIntegerListOfPaveBlock::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("Size", (Standard_Integer (BOPDS_DataMapOfIntegerListOfPaveBlock::*)() const ) &BOPDS_DataMapOfIntegerListOfPaveBlock::Size, "Size");
	cls_BOPDS_DataMapOfIntegerListOfPaveBlock.def("__iter__", [](const BOPDS_DataMapOfIntegerListOfPaveBlock &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BOPDS_DataMapOfPassKeyListOfPaveBlock, std::unique_ptr<BOPDS_DataMapOfPassKeyListOfPaveBlock, Deleter<BOPDS_DataMapOfPassKeyListOfPaveBlock>>, NCollection_BaseMap> cls_BOPDS_DataMapOfPassKeyListOfPaveBlock(mod, "BOPDS_DataMapOfPassKeyListOfPaveBlock", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def(py::init<>());
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def(py::init([] (const BOPDS_DataMapOfPassKeyListOfPaveBlock &other) {return new BOPDS_DataMapOfPassKeyListOfPaveBlock(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("begin", (BOPDS_DataMapOfPassKeyListOfPaveBlock::iterator (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)() const ) &BOPDS_DataMapOfPassKeyListOfPaveBlock::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("end", (BOPDS_DataMapOfPassKeyListOfPaveBlock::iterator (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)() const ) &BOPDS_DataMapOfPassKeyListOfPaveBlock::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("cbegin", (BOPDS_DataMapOfPassKeyListOfPaveBlock::const_iterator (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)() const ) &BOPDS_DataMapOfPassKeyListOfPaveBlock::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("cend", (BOPDS_DataMapOfPassKeyListOfPaveBlock::const_iterator (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)() const ) &BOPDS_DataMapOfPassKeyListOfPaveBlock::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("Exchange", (void (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(BOPDS_DataMapOfPassKeyListOfPaveBlock &)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("Assign", (BOPDS_DataMapOfPassKeyListOfPaveBlock & (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_DataMapOfPassKeyListOfPaveBlock &)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("assign", (BOPDS_DataMapOfPassKeyListOfPaveBlock & (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_DataMapOfPassKeyListOfPaveBlock &)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("ReSize", (void (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const Standard_Integer)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("Bind", (Standard_Boolean (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_PassKey &, const BOPDS_ListOfPaveBlock &)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("Bound", (BOPDS_ListOfPaveBlock * (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_PassKey &, const BOPDS_ListOfPaveBlock &)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("IsBound", (Standard_Boolean (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_PassKey &) const ) &BOPDS_DataMapOfPassKeyListOfPaveBlock::IsBound, "IsBound", py::arg("theKey"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("UnBind", (Standard_Boolean (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_PassKey &)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("Seek", (const BOPDS_ListOfPaveBlock * (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_PassKey &) const ) &BOPDS_DataMapOfPassKeyListOfPaveBlock::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("Find", (const BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_PassKey &) const ) &BOPDS_DataMapOfPassKeyListOfPaveBlock::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("Find", (Standard_Boolean (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_PassKey &, BOPDS_ListOfPaveBlock &) const ) &BOPDS_DataMapOfPassKeyListOfPaveBlock::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("__call__", (const BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_PassKey &) const ) &BOPDS_DataMapOfPassKeyListOfPaveBlock::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("ChangeSeek", (BOPDS_ListOfPaveBlock * (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_PassKey &)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("ChangeFind", (BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_PassKey &)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("__call__", (BOPDS_ListOfPaveBlock & (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const BOPDS_PassKey &)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("Clear", [](BOPDS_DataMapOfPassKeyListOfPaveBlock &self) -> void { return self.Clear(); });
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("Clear", (void (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const Standard_Boolean)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("Clear", (void (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_DataMapOfPassKeyListOfPaveBlock::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("Size", (Standard_Integer (BOPDS_DataMapOfPassKeyListOfPaveBlock::*)() const ) &BOPDS_DataMapOfPassKeyListOfPaveBlock::Size, "Size");
	cls_BOPDS_DataMapOfPassKeyListOfPaveBlock.def("__iter__", [](const BOPDS_DataMapOfPassKeyListOfPaveBlock &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPassKeyListOfPaveBlock.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BOPDS_DataMapOfPaveBlockCommonBlock, std::unique_ptr<BOPDS_DataMapOfPaveBlockCommonBlock, Deleter<BOPDS_DataMapOfPaveBlockCommonBlock>>, NCollection_BaseMap> cls_BOPDS_DataMapOfPaveBlockCommonBlock(mod, "BOPDS_DataMapOfPaveBlockCommonBlock", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def(py::init<>());
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def(py::init([] (const BOPDS_DataMapOfPaveBlockCommonBlock &other) {return new BOPDS_DataMapOfPaveBlockCommonBlock(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("begin", (BOPDS_DataMapOfPaveBlockCommonBlock::iterator (BOPDS_DataMapOfPaveBlockCommonBlock::*)() const ) &BOPDS_DataMapOfPaveBlockCommonBlock::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("end", (BOPDS_DataMapOfPaveBlockCommonBlock::iterator (BOPDS_DataMapOfPaveBlockCommonBlock::*)() const ) &BOPDS_DataMapOfPaveBlockCommonBlock::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("cbegin", (BOPDS_DataMapOfPaveBlockCommonBlock::const_iterator (BOPDS_DataMapOfPaveBlockCommonBlock::*)() const ) &BOPDS_DataMapOfPaveBlockCommonBlock::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("cend", (BOPDS_DataMapOfPaveBlockCommonBlock::const_iterator (BOPDS_DataMapOfPaveBlockCommonBlock::*)() const ) &BOPDS_DataMapOfPaveBlockCommonBlock::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("Exchange", (void (BOPDS_DataMapOfPaveBlockCommonBlock::*)(BOPDS_DataMapOfPaveBlockCommonBlock &)) &BOPDS_DataMapOfPaveBlockCommonBlock::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("Assign", (BOPDS_DataMapOfPaveBlockCommonBlock & (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const BOPDS_DataMapOfPaveBlockCommonBlock &)) &BOPDS_DataMapOfPaveBlockCommonBlock::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("assign", (BOPDS_DataMapOfPaveBlockCommonBlock & (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const BOPDS_DataMapOfPaveBlockCommonBlock &)) &BOPDS_DataMapOfPaveBlockCommonBlock::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("ReSize", (void (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const Standard_Integer)) &BOPDS_DataMapOfPaveBlockCommonBlock::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("Bind", (Standard_Boolean (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &, const opencascade::handle<BOPDS_CommonBlock> &)) &BOPDS_DataMapOfPaveBlockCommonBlock::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("Bound", (opencascade::handle<BOPDS_CommonBlock> * (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &, const opencascade::handle<BOPDS_CommonBlock> &)) &BOPDS_DataMapOfPaveBlockCommonBlock::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("IsBound", (Standard_Boolean (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockCommonBlock::IsBound, "IsBound", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("UnBind", (Standard_Boolean (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockCommonBlock::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("Seek", (const opencascade::handle<BOPDS_CommonBlock> * (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockCommonBlock::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("Find", (const opencascade::handle<BOPDS_CommonBlock> & (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockCommonBlock::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("Find", (Standard_Boolean (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &, opencascade::handle<BOPDS_CommonBlock> &) const ) &BOPDS_DataMapOfPaveBlockCommonBlock::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("__call__", (const opencascade::handle<BOPDS_CommonBlock> & (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockCommonBlock::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("ChangeSeek", (opencascade::handle<BOPDS_CommonBlock> * (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockCommonBlock::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("ChangeFind", (opencascade::handle<BOPDS_CommonBlock> & (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockCommonBlock::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("__call__", (opencascade::handle<BOPDS_CommonBlock> & (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockCommonBlock::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("Clear", [](BOPDS_DataMapOfPaveBlockCommonBlock &self) -> void { return self.Clear(); });
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("Clear", (void (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const Standard_Boolean)) &BOPDS_DataMapOfPaveBlockCommonBlock::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("Clear", (void (BOPDS_DataMapOfPaveBlockCommonBlock::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_DataMapOfPaveBlockCommonBlock::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("Size", (Standard_Integer (BOPDS_DataMapOfPaveBlockCommonBlock::*)() const ) &BOPDS_DataMapOfPaveBlockCommonBlock::Size, "Size");
	cls_BOPDS_DataMapOfPaveBlockCommonBlock.def("__iter__", [](const BOPDS_DataMapOfPaveBlockCommonBlock &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPaveBlockCommonBlock.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BOPDS_DataMapOfPaveBlockListOfInteger, std::unique_ptr<BOPDS_DataMapOfPaveBlockListOfInteger, Deleter<BOPDS_DataMapOfPaveBlockListOfInteger>>, NCollection_BaseMap> cls_BOPDS_DataMapOfPaveBlockListOfInteger(mod, "BOPDS_DataMapOfPaveBlockListOfInteger", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def(py::init<>());
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def(py::init([] (const BOPDS_DataMapOfPaveBlockListOfInteger &other) {return new BOPDS_DataMapOfPaveBlockListOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("begin", (BOPDS_DataMapOfPaveBlockListOfInteger::iterator (BOPDS_DataMapOfPaveBlockListOfInteger::*)() const ) &BOPDS_DataMapOfPaveBlockListOfInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("end", (BOPDS_DataMapOfPaveBlockListOfInteger::iterator (BOPDS_DataMapOfPaveBlockListOfInteger::*)() const ) &BOPDS_DataMapOfPaveBlockListOfInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("cbegin", (BOPDS_DataMapOfPaveBlockListOfInteger::const_iterator (BOPDS_DataMapOfPaveBlockListOfInteger::*)() const ) &BOPDS_DataMapOfPaveBlockListOfInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("cend", (BOPDS_DataMapOfPaveBlockListOfInteger::const_iterator (BOPDS_DataMapOfPaveBlockListOfInteger::*)() const ) &BOPDS_DataMapOfPaveBlockListOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("Exchange", (void (BOPDS_DataMapOfPaveBlockListOfInteger::*)(BOPDS_DataMapOfPaveBlockListOfInteger &)) &BOPDS_DataMapOfPaveBlockListOfInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("Assign", (BOPDS_DataMapOfPaveBlockListOfInteger & (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const BOPDS_DataMapOfPaveBlockListOfInteger &)) &BOPDS_DataMapOfPaveBlockListOfInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("assign", (BOPDS_DataMapOfPaveBlockListOfInteger & (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const BOPDS_DataMapOfPaveBlockListOfInteger &)) &BOPDS_DataMapOfPaveBlockListOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("ReSize", (void (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const Standard_Integer)) &BOPDS_DataMapOfPaveBlockListOfInteger::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("Bind", (Standard_Boolean (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &, const BOPCol_ListOfInteger &)) &BOPDS_DataMapOfPaveBlockListOfInteger::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("Bound", (BOPCol_ListOfInteger * (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &, const BOPCol_ListOfInteger &)) &BOPDS_DataMapOfPaveBlockListOfInteger::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("IsBound", (Standard_Boolean (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockListOfInteger::IsBound, "IsBound", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("UnBind", (Standard_Boolean (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockListOfInteger::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("Seek", (const BOPCol_ListOfInteger * (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockListOfInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("Find", (const BOPCol_ListOfInteger & (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockListOfInteger::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("Find", (Standard_Boolean (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &, BOPCol_ListOfInteger &) const ) &BOPDS_DataMapOfPaveBlockListOfInteger::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("__call__", (const BOPCol_ListOfInteger & (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &) const ) &BOPDS_DataMapOfPaveBlockListOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("ChangeSeek", (BOPCol_ListOfInteger * (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockListOfInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("ChangeFind", (BOPCol_ListOfInteger & (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockListOfInteger::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("__call__", (BOPCol_ListOfInteger & (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_DataMapOfPaveBlockListOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("Clear", [](BOPDS_DataMapOfPaveBlockListOfInteger &self) -> void { return self.Clear(); });
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("Clear", (void (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const Standard_Boolean)) &BOPDS_DataMapOfPaveBlockListOfInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("Clear", (void (BOPDS_DataMapOfPaveBlockListOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_DataMapOfPaveBlockListOfInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("Size", (Standard_Integer (BOPDS_DataMapOfPaveBlockListOfInteger::*)() const ) &BOPDS_DataMapOfPaveBlockListOfInteger::Size, "Size");
	cls_BOPDS_DataMapOfPaveBlockListOfInteger.def("__iter__", [](const BOPDS_DataMapOfPaveBlockListOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfPaveBlockListOfInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BOPDS_DataMapOfShapeCoupleOfPaveBlocks, std::unique_ptr<BOPDS_DataMapOfShapeCoupleOfPaveBlocks, Deleter<BOPDS_DataMapOfShapeCoupleOfPaveBlocks>>, NCollection_BaseMap> cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks(mod, "BOPDS_DataMapOfShapeCoupleOfPaveBlocks", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def(py::init<>());
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def(py::init([] (const BOPDS_DataMapOfShapeCoupleOfPaveBlocks &other) {return new BOPDS_DataMapOfShapeCoupleOfPaveBlocks(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("begin", (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::iterator (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)() const ) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("end", (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::iterator (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)() const ) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("cbegin", (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::const_iterator (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)() const ) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("cend", (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::const_iterator (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)() const ) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("Exchange", (void (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(BOPDS_DataMapOfShapeCoupleOfPaveBlocks &)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("Assign", (BOPDS_DataMapOfShapeCoupleOfPaveBlocks & (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const BOPDS_DataMapOfShapeCoupleOfPaveBlocks &)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("assign", (BOPDS_DataMapOfShapeCoupleOfPaveBlocks & (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const BOPDS_DataMapOfShapeCoupleOfPaveBlocks &)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("ReSize", (void (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Integer)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("Bind", (Standard_Boolean (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &, const BOPDS_CoupleOfPaveBlocks &)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("Bound", (BOPDS_CoupleOfPaveBlocks * (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &, const BOPDS_CoupleOfPaveBlocks &)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("IsBound", (Standard_Boolean (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &) const ) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::IsBound, "IsBound", py::arg("theKey"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("UnBind", (Standard_Boolean (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("Seek", (const BOPDS_CoupleOfPaveBlocks * (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &) const ) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("Find", (const BOPDS_CoupleOfPaveBlocks & (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &) const ) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("Find", (Standard_Boolean (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &, BOPDS_CoupleOfPaveBlocks &) const ) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("__call__", (const BOPDS_CoupleOfPaveBlocks & (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &) const ) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("ChangeSeek", (BOPDS_CoupleOfPaveBlocks * (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("ChangeFind", (BOPDS_CoupleOfPaveBlocks & (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("__call__", (BOPDS_CoupleOfPaveBlocks & (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const TopoDS_Shape &)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("Clear", [](BOPDS_DataMapOfShapeCoupleOfPaveBlocks &self) -> void { return self.Clear(); });
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("Clear", (void (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const Standard_Boolean)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("Clear", (void (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("Size", (Standard_Integer (BOPDS_DataMapOfShapeCoupleOfPaveBlocks::*)() const ) &BOPDS_DataMapOfShapeCoupleOfPaveBlocks::Size, "Size");
	cls_BOPDS_DataMapOfShapeCoupleOfPaveBlocks.def("__iter__", [](const BOPDS_DataMapOfShapeCoupleOfPaveBlocks &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_DataMapOfShapeCoupleOfPaveBlocks.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfIndexRange, std::unique_ptr<BOPDS_VectorOfIndexRange, Deleter<BOPDS_VectorOfIndexRange>>> cls_BOPDS_VectorOfIndexRange(mod, "BOPDS_VectorOfIndexRange", "None");
	cls_BOPDS_VectorOfIndexRange.def(py::init<>());
	cls_BOPDS_VectorOfIndexRange.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfIndexRange.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfIndexRange.def("Append1", (BOPDS_IndexRange & (BOPDS_VectorOfIndexRange::*)()) &BOPDS_VectorOfIndexRange::Append1, "None");
	cls_BOPDS_VectorOfIndexRange.def("Extent", (Standard_Integer (BOPDS_VectorOfIndexRange::*)() const ) &BOPDS_VectorOfIndexRange::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfShapeInfo, std::unique_ptr<BOPDS_VectorOfShapeInfo, Deleter<BOPDS_VectorOfShapeInfo>>> cls_BOPDS_VectorOfShapeInfo(mod, "BOPDS_VectorOfShapeInfo", "None");
	cls_BOPDS_VectorOfShapeInfo.def(py::init<>());
	cls_BOPDS_VectorOfShapeInfo.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfShapeInfo.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfShapeInfo.def("Append1", (BOPDS_ShapeInfo & (BOPDS_VectorOfShapeInfo::*)()) &BOPDS_VectorOfShapeInfo::Append1, "None");
	cls_BOPDS_VectorOfShapeInfo.def("Extent", (Standard_Integer (BOPDS_VectorOfShapeInfo::*)() const ) &BOPDS_VectorOfShapeInfo::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfListOfPaveBlock, std::unique_ptr<BOPDS_VectorOfListOfPaveBlock, Deleter<BOPDS_VectorOfListOfPaveBlock>>> cls_BOPDS_VectorOfListOfPaveBlock(mod, "BOPDS_VectorOfListOfPaveBlock", "None");
	cls_BOPDS_VectorOfListOfPaveBlock.def(py::init<>());
	cls_BOPDS_VectorOfListOfPaveBlock.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfListOfPaveBlock.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfListOfPaveBlock.def("Append1", (BOPDS_ListOfPaveBlock & (BOPDS_VectorOfListOfPaveBlock::*)()) &BOPDS_VectorOfListOfPaveBlock::Append1, "None");
	cls_BOPDS_VectorOfListOfPaveBlock.def("Extent", (Standard_Integer (BOPDS_VectorOfListOfPaveBlock::*)() const ) &BOPDS_VectorOfListOfPaveBlock::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfFaceInfo, std::unique_ptr<BOPDS_VectorOfFaceInfo, Deleter<BOPDS_VectorOfFaceInfo>>> cls_BOPDS_VectorOfFaceInfo(mod, "BOPDS_VectorOfFaceInfo", "None");
	cls_BOPDS_VectorOfFaceInfo.def(py::init<>());
	cls_BOPDS_VectorOfFaceInfo.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfFaceInfo.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfFaceInfo.def("Append1", (BOPDS_FaceInfo & (BOPDS_VectorOfFaceInfo::*)()) &BOPDS_VectorOfFaceInfo::Append1, "None");
	cls_BOPDS_VectorOfFaceInfo.def("Extent", (Standard_Integer (BOPDS_VectorOfFaceInfo::*)() const ) &BOPDS_VectorOfFaceInfo::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfPoint, std::unique_ptr<BOPDS_VectorOfPoint, Deleter<BOPDS_VectorOfPoint>>> cls_BOPDS_VectorOfPoint(mod, "BOPDS_VectorOfPoint", "None");
	cls_BOPDS_VectorOfPoint.def(py::init<>());
	cls_BOPDS_VectorOfPoint.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfPoint.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfPoint.def("Append1", (BOPDS_Point & (BOPDS_VectorOfPoint::*)()) &BOPDS_VectorOfPoint::Append1, "None");
	cls_BOPDS_VectorOfPoint.def("Extent", (Standard_Integer (BOPDS_VectorOfPoint::*)() const ) &BOPDS_VectorOfPoint::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfInterfVV, std::unique_ptr<BOPDS_VectorOfInterfVV, Deleter<BOPDS_VectorOfInterfVV>>> cls_BOPDS_VectorOfInterfVV(mod, "BOPDS_VectorOfInterfVV", "None");
	cls_BOPDS_VectorOfInterfVV.def(py::init<>());
	cls_BOPDS_VectorOfInterfVV.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfInterfVV.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfInterfVV.def("Append1", (BOPDS_InterfVV & (BOPDS_VectorOfInterfVV::*)()) &BOPDS_VectorOfInterfVV::Append1, "None");
	cls_BOPDS_VectorOfInterfVV.def("Extent", (Standard_Integer (BOPDS_VectorOfInterfVV::*)() const ) &BOPDS_VectorOfInterfVV::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfInterfVE, std::unique_ptr<BOPDS_VectorOfInterfVE, Deleter<BOPDS_VectorOfInterfVE>>> cls_BOPDS_VectorOfInterfVE(mod, "BOPDS_VectorOfInterfVE", "None");
	cls_BOPDS_VectorOfInterfVE.def(py::init<>());
	cls_BOPDS_VectorOfInterfVE.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfInterfVE.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfInterfVE.def("Append1", (BOPDS_InterfVE & (BOPDS_VectorOfInterfVE::*)()) &BOPDS_VectorOfInterfVE::Append1, "None");
	cls_BOPDS_VectorOfInterfVE.def("Extent", (Standard_Integer (BOPDS_VectorOfInterfVE::*)() const ) &BOPDS_VectorOfInterfVE::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfInterfVF, std::unique_ptr<BOPDS_VectorOfInterfVF, Deleter<BOPDS_VectorOfInterfVF>>> cls_BOPDS_VectorOfInterfVF(mod, "BOPDS_VectorOfInterfVF", "None");
	cls_BOPDS_VectorOfInterfVF.def(py::init<>());
	cls_BOPDS_VectorOfInterfVF.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfInterfVF.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfInterfVF.def("Append1", (BOPDS_InterfVF & (BOPDS_VectorOfInterfVF::*)()) &BOPDS_VectorOfInterfVF::Append1, "None");
	cls_BOPDS_VectorOfInterfVF.def("Extent", (Standard_Integer (BOPDS_VectorOfInterfVF::*)() const ) &BOPDS_VectorOfInterfVF::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfInterfEE, std::unique_ptr<BOPDS_VectorOfInterfEE, Deleter<BOPDS_VectorOfInterfEE>>> cls_BOPDS_VectorOfInterfEE(mod, "BOPDS_VectorOfInterfEE", "None");
	cls_BOPDS_VectorOfInterfEE.def(py::init<>());
	cls_BOPDS_VectorOfInterfEE.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfInterfEE.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfInterfEE.def("Append1", (BOPDS_InterfEE & (BOPDS_VectorOfInterfEE::*)()) &BOPDS_VectorOfInterfEE::Append1, "None");
	cls_BOPDS_VectorOfInterfEE.def("Extent", (Standard_Integer (BOPDS_VectorOfInterfEE::*)() const ) &BOPDS_VectorOfInterfEE::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfInterfEF, std::unique_ptr<BOPDS_VectorOfInterfEF, Deleter<BOPDS_VectorOfInterfEF>>> cls_BOPDS_VectorOfInterfEF(mod, "BOPDS_VectorOfInterfEF", "None");
	cls_BOPDS_VectorOfInterfEF.def(py::init<>());
	cls_BOPDS_VectorOfInterfEF.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfInterfEF.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfInterfEF.def("Append1", (BOPDS_InterfEF & (BOPDS_VectorOfInterfEF::*)()) &BOPDS_VectorOfInterfEF::Append1, "None");
	cls_BOPDS_VectorOfInterfEF.def("Extent", (Standard_Integer (BOPDS_VectorOfInterfEF::*)() const ) &BOPDS_VectorOfInterfEF::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfInterfFF, std::unique_ptr<BOPDS_VectorOfInterfFF, Deleter<BOPDS_VectorOfInterfFF>>> cls_BOPDS_VectorOfInterfFF(mod, "BOPDS_VectorOfInterfFF", "None");
	cls_BOPDS_VectorOfInterfFF.def(py::init<>());
	cls_BOPDS_VectorOfInterfFF.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfInterfFF.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfInterfFF.def("Append1", (BOPDS_InterfFF & (BOPDS_VectorOfInterfFF::*)()) &BOPDS_VectorOfInterfFF::Append1, "None");
	cls_BOPDS_VectorOfInterfFF.def("Extent", (Standard_Integer (BOPDS_VectorOfInterfFF::*)() const ) &BOPDS_VectorOfInterfFF::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfInterfVZ, std::unique_ptr<BOPDS_VectorOfInterfVZ, Deleter<BOPDS_VectorOfInterfVZ>>> cls_BOPDS_VectorOfInterfVZ(mod, "BOPDS_VectorOfInterfVZ", "None");
	cls_BOPDS_VectorOfInterfVZ.def(py::init<>());
	cls_BOPDS_VectorOfInterfVZ.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfInterfVZ.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfInterfVZ.def("Append1", (BOPDS_InterfVZ & (BOPDS_VectorOfInterfVZ::*)()) &BOPDS_VectorOfInterfVZ::Append1, "None");
	cls_BOPDS_VectorOfInterfVZ.def("Extent", (Standard_Integer (BOPDS_VectorOfInterfVZ::*)() const ) &BOPDS_VectorOfInterfVZ::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfInterfEZ, std::unique_ptr<BOPDS_VectorOfInterfEZ, Deleter<BOPDS_VectorOfInterfEZ>>> cls_BOPDS_VectorOfInterfEZ(mod, "BOPDS_VectorOfInterfEZ", "None");
	cls_BOPDS_VectorOfInterfEZ.def(py::init<>());
	cls_BOPDS_VectorOfInterfEZ.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfInterfEZ.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfInterfEZ.def("Append1", (BOPDS_InterfEZ & (BOPDS_VectorOfInterfEZ::*)()) &BOPDS_VectorOfInterfEZ::Append1, "None");
	cls_BOPDS_VectorOfInterfEZ.def("Extent", (Standard_Integer (BOPDS_VectorOfInterfEZ::*)() const ) &BOPDS_VectorOfInterfEZ::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfInterfFZ, std::unique_ptr<BOPDS_VectorOfInterfFZ, Deleter<BOPDS_VectorOfInterfFZ>>> cls_BOPDS_VectorOfInterfFZ(mod, "BOPDS_VectorOfInterfFZ", "None");
	cls_BOPDS_VectorOfInterfFZ.def(py::init<>());
	cls_BOPDS_VectorOfInterfFZ.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfInterfFZ.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfInterfFZ.def("Append1", (BOPDS_InterfFZ & (BOPDS_VectorOfInterfFZ::*)()) &BOPDS_VectorOfInterfFZ::Append1, "None");
	cls_BOPDS_VectorOfInterfFZ.def("Extent", (Standard_Integer (BOPDS_VectorOfInterfFZ::*)() const ) &BOPDS_VectorOfInterfFZ::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfInterfZZ, std::unique_ptr<BOPDS_VectorOfInterfZZ, Deleter<BOPDS_VectorOfInterfZZ>>> cls_BOPDS_VectorOfInterfZZ(mod, "BOPDS_VectorOfInterfZZ", "None");
	cls_BOPDS_VectorOfInterfZZ.def(py::init<>());
	cls_BOPDS_VectorOfInterfZZ.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfInterfZZ.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfInterfZZ.def("Append1", (BOPDS_InterfZZ & (BOPDS_VectorOfInterfZZ::*)()) &BOPDS_VectorOfInterfZZ::Append1, "None");
	cls_BOPDS_VectorOfInterfZZ.def("Extent", (Standard_Integer (BOPDS_VectorOfInterfZZ::*)() const ) &BOPDS_VectorOfInterfZZ::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfPair, std::unique_ptr<BOPDS_VectorOfPair, Deleter<BOPDS_VectorOfPair>>> cls_BOPDS_VectorOfPair(mod, "BOPDS_VectorOfPair", "None");
	cls_BOPDS_VectorOfPair.def(py::init<>());
	cls_BOPDS_VectorOfPair.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfPair.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfPair.def("Append1", (BOPDS_Pair & (BOPDS_VectorOfPair::*)()) &BOPDS_VectorOfPair::Append1, "None");
	cls_BOPDS_VectorOfPair.def("Extent", (Standard_Integer (BOPDS_VectorOfPair::*)() const ) &BOPDS_VectorOfPair::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfVectorOfPair, std::unique_ptr<BOPDS_VectorOfVectorOfPair, Deleter<BOPDS_VectorOfVectorOfPair>>> cls_BOPDS_VectorOfVectorOfPair(mod, "BOPDS_VectorOfVectorOfPair", "None");
	cls_BOPDS_VectorOfVectorOfPair.def(py::init<>());
	cls_BOPDS_VectorOfVectorOfPair.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfVectorOfPair.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfVectorOfPair.def("Append1", (BOPDS_VectorOfPair & (BOPDS_VectorOfVectorOfPair::*)()) &BOPDS_VectorOfVectorOfPair::Append1, "None");
	cls_BOPDS_VectorOfVectorOfPair.def("Extent", (Standard_Integer (BOPDS_VectorOfVectorOfPair::*)() const ) &BOPDS_VectorOfVectorOfPair::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<BOPDS_ListOfPassKeyBoolean, std::unique_ptr<BOPDS_ListOfPassKeyBoolean, Deleter<BOPDS_ListOfPassKeyBoolean>>, NCollection_BaseList> cls_BOPDS_ListOfPassKeyBoolean(mod, "BOPDS_ListOfPassKeyBoolean", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_BOPDS_ListOfPassKeyBoolean.def(py::init<>());
	cls_BOPDS_ListOfPassKeyBoolean.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPDS_ListOfPassKeyBoolean.def(py::init([] (const BOPDS_ListOfPassKeyBoolean &other) {return new BOPDS_ListOfPassKeyBoolean(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_ListOfPassKeyBoolean.def("begin", (BOPDS_ListOfPassKeyBoolean::iterator (BOPDS_ListOfPassKeyBoolean::*)() const ) &BOPDS_ListOfPassKeyBoolean::begin, "Returns an iterator pointing to the first element in the list.");
	cls_BOPDS_ListOfPassKeyBoolean.def("end", (BOPDS_ListOfPassKeyBoolean::iterator (BOPDS_ListOfPassKeyBoolean::*)() const ) &BOPDS_ListOfPassKeyBoolean::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_BOPDS_ListOfPassKeyBoolean.def("cbegin", (BOPDS_ListOfPassKeyBoolean::const_iterator (BOPDS_ListOfPassKeyBoolean::*)() const ) &BOPDS_ListOfPassKeyBoolean::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_BOPDS_ListOfPassKeyBoolean.def("cend", (BOPDS_ListOfPassKeyBoolean::const_iterator (BOPDS_ListOfPassKeyBoolean::*)() const ) &BOPDS_ListOfPassKeyBoolean::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_BOPDS_ListOfPassKeyBoolean.def("Size", (Standard_Integer (BOPDS_ListOfPassKeyBoolean::*)() const ) &BOPDS_ListOfPassKeyBoolean::Size, "Size - Number of items");
	cls_BOPDS_ListOfPassKeyBoolean.def("Assign", (BOPDS_ListOfPassKeyBoolean & (BOPDS_ListOfPassKeyBoolean::*)(const BOPDS_ListOfPassKeyBoolean &)) &BOPDS_ListOfPassKeyBoolean::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_ListOfPassKeyBoolean.def("assign", (BOPDS_ListOfPassKeyBoolean & (BOPDS_ListOfPassKeyBoolean::*)(const BOPDS_ListOfPassKeyBoolean &)) &BOPDS_ListOfPassKeyBoolean::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BOPDS_ListOfPassKeyBoolean.def("Clear", [](BOPDS_ListOfPassKeyBoolean &self) -> void { return self.Clear(); });
	cls_BOPDS_ListOfPassKeyBoolean.def("Clear", (void (BOPDS_ListOfPassKeyBoolean::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_ListOfPassKeyBoolean::Clear, "Clear this list", py::arg("theAllocator"));
	cls_BOPDS_ListOfPassKeyBoolean.def("First", (const BOPDS_PassKeyBoolean & (BOPDS_ListOfPassKeyBoolean::*)() const ) &BOPDS_ListOfPassKeyBoolean::First, "First item");
	cls_BOPDS_ListOfPassKeyBoolean.def("First", (BOPDS_PassKeyBoolean & (BOPDS_ListOfPassKeyBoolean::*)()) &BOPDS_ListOfPassKeyBoolean::First, "First item (non-const)");
	cls_BOPDS_ListOfPassKeyBoolean.def("Last", (const BOPDS_PassKeyBoolean & (BOPDS_ListOfPassKeyBoolean::*)() const ) &BOPDS_ListOfPassKeyBoolean::Last, "Last item");
	cls_BOPDS_ListOfPassKeyBoolean.def("Last", (BOPDS_PassKeyBoolean & (BOPDS_ListOfPassKeyBoolean::*)()) &BOPDS_ListOfPassKeyBoolean::Last, "Last item (non-const)");
	cls_BOPDS_ListOfPassKeyBoolean.def("Append", (BOPDS_PassKeyBoolean & (BOPDS_ListOfPassKeyBoolean::*)(const BOPDS_PassKeyBoolean &)) &BOPDS_ListOfPassKeyBoolean::Append, "Append one item at the end", py::arg("theItem"));
	cls_BOPDS_ListOfPassKeyBoolean.def("Append", (void (BOPDS_ListOfPassKeyBoolean::*)(const BOPDS_PassKeyBoolean &, BOPDS_ListOfPassKeyBoolean::Iterator &)) &BOPDS_ListOfPassKeyBoolean::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_BOPDS_ListOfPassKeyBoolean.def("Append", (void (BOPDS_ListOfPassKeyBoolean::*)(BOPDS_ListOfPassKeyBoolean &)) &BOPDS_ListOfPassKeyBoolean::Append, "Append another list at the end", py::arg("theOther"));
	cls_BOPDS_ListOfPassKeyBoolean.def("Prepend", (BOPDS_PassKeyBoolean & (BOPDS_ListOfPassKeyBoolean::*)(const BOPDS_PassKeyBoolean &)) &BOPDS_ListOfPassKeyBoolean::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_BOPDS_ListOfPassKeyBoolean.def("Prepend", (void (BOPDS_ListOfPassKeyBoolean::*)(BOPDS_ListOfPassKeyBoolean &)) &BOPDS_ListOfPassKeyBoolean::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_BOPDS_ListOfPassKeyBoolean.def("RemoveFirst", (void (BOPDS_ListOfPassKeyBoolean::*)()) &BOPDS_ListOfPassKeyBoolean::RemoveFirst, "RemoveFirst item");
	cls_BOPDS_ListOfPassKeyBoolean.def("Remove", (void (BOPDS_ListOfPassKeyBoolean::*)(BOPDS_ListOfPassKeyBoolean::Iterator &)) &BOPDS_ListOfPassKeyBoolean::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_BOPDS_ListOfPassKeyBoolean.def("InsertBefore", (BOPDS_PassKeyBoolean & (BOPDS_ListOfPassKeyBoolean::*)(const BOPDS_PassKeyBoolean &, BOPDS_ListOfPassKeyBoolean::Iterator &)) &BOPDS_ListOfPassKeyBoolean::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_BOPDS_ListOfPassKeyBoolean.def("InsertBefore", (void (BOPDS_ListOfPassKeyBoolean::*)(BOPDS_ListOfPassKeyBoolean &, BOPDS_ListOfPassKeyBoolean::Iterator &)) &BOPDS_ListOfPassKeyBoolean::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_BOPDS_ListOfPassKeyBoolean.def("InsertAfter", (BOPDS_PassKeyBoolean & (BOPDS_ListOfPassKeyBoolean::*)(const BOPDS_PassKeyBoolean &, BOPDS_ListOfPassKeyBoolean::Iterator &)) &BOPDS_ListOfPassKeyBoolean::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_BOPDS_ListOfPassKeyBoolean.def("InsertAfter", (void (BOPDS_ListOfPassKeyBoolean::*)(BOPDS_ListOfPassKeyBoolean &, BOPDS_ListOfPassKeyBoolean::Iterator &)) &BOPDS_ListOfPassKeyBoolean::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_BOPDS_ListOfPassKeyBoolean.def("Reverse", (void (BOPDS_ListOfPassKeyBoolean::*)()) &BOPDS_ListOfPassKeyBoolean::Reverse, "Reverse the list");
	cls_BOPDS_ListOfPassKeyBoolean.def("__iter__", [](const BOPDS_ListOfPassKeyBoolean &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<BOPDS_ListIteratorOfListOfPassKeyBoolean, std::unique_ptr<BOPDS_ListIteratorOfListOfPassKeyBoolean, Deleter<BOPDS_ListIteratorOfListOfPassKeyBoolean>>> cls_BOPDS_ListIteratorOfListOfPassKeyBoolean(mod, "BOPDS_ListIteratorOfListOfPassKeyBoolean", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_BOPDS_ListIteratorOfListOfPassKeyBoolean.def(py::init<>());
	cls_BOPDS_ListIteratorOfListOfPassKeyBoolean.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_BOPDS_ListIteratorOfListOfPassKeyBoolean.def("More", (Standard_Boolean (BOPDS_ListIteratorOfListOfPassKeyBoolean::*)() const ) &BOPDS_ListIteratorOfListOfPassKeyBoolean::More, "Check end");
	cls_BOPDS_ListIteratorOfListOfPassKeyBoolean.def("Next", (void (BOPDS_ListIteratorOfListOfPassKeyBoolean::*)()) &BOPDS_ListIteratorOfListOfPassKeyBoolean::Next, "Make step");
	cls_BOPDS_ListIteratorOfListOfPassKeyBoolean.def("Value", (const BOPDS_PassKeyBoolean & (BOPDS_ListIteratorOfListOfPassKeyBoolean::*)() const ) &BOPDS_ListIteratorOfListOfPassKeyBoolean::Value, "Constant Value access");
	cls_BOPDS_ListIteratorOfListOfPassKeyBoolean.def("Value", (BOPDS_PassKeyBoolean & (BOPDS_ListIteratorOfListOfPassKeyBoolean::*)()) &BOPDS_ListIteratorOfListOfPassKeyBoolean::Value, "Non-const Value access");
	cls_BOPDS_ListIteratorOfListOfPassKeyBoolean.def("ChangeValue", (BOPDS_PassKeyBoolean & (BOPDS_ListIteratorOfListOfPassKeyBoolean::*)() const ) &BOPDS_ListIteratorOfListOfPassKeyBoolean::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<BOPDS_MapOfCommonBlock, std::unique_ptr<BOPDS_MapOfCommonBlock, Deleter<BOPDS_MapOfCommonBlock>>, NCollection_BaseMap> cls_BOPDS_MapOfCommonBlock(mod, "BOPDS_MapOfCommonBlock", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_BOPDS_MapOfCommonBlock.def(py::init<>());
	cls_BOPDS_MapOfCommonBlock.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_MapOfCommonBlock.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_MapOfCommonBlock.def(py::init([] (const BOPDS_MapOfCommonBlock &other) {return new BOPDS_MapOfCommonBlock(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_MapOfCommonBlock.def("cbegin", (BOPDS_MapOfCommonBlock::const_iterator (BOPDS_MapOfCommonBlock::*)() const ) &BOPDS_MapOfCommonBlock::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_MapOfCommonBlock.def("cend", (BOPDS_MapOfCommonBlock::const_iterator (BOPDS_MapOfCommonBlock::*)() const ) &BOPDS_MapOfCommonBlock::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_MapOfCommonBlock.def("Exchange", (void (BOPDS_MapOfCommonBlock::*)(BOPDS_MapOfCommonBlock &)) &BOPDS_MapOfCommonBlock::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_MapOfCommonBlock.def("Assign", (BOPDS_MapOfCommonBlock & (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &)) &BOPDS_MapOfCommonBlock::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_MapOfCommonBlock.def("assign", (BOPDS_MapOfCommonBlock & (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &)) &BOPDS_MapOfCommonBlock::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_BOPDS_MapOfCommonBlock.def("ReSize", (void (BOPDS_MapOfCommonBlock::*)(const Standard_Integer)) &BOPDS_MapOfCommonBlock::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_MapOfCommonBlock.def("Add", (Standard_Boolean (BOPDS_MapOfCommonBlock::*)(const opencascade::handle<BOPDS_CommonBlock> &)) &BOPDS_MapOfCommonBlock::Add, "Add", py::arg("K"));
	cls_BOPDS_MapOfCommonBlock.def("Added", (const opencascade::handle<BOPDS_CommonBlock> & (BOPDS_MapOfCommonBlock::*)(const opencascade::handle<BOPDS_CommonBlock> &)) &BOPDS_MapOfCommonBlock::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_BOPDS_MapOfCommonBlock.def("Contains", (Standard_Boolean (BOPDS_MapOfCommonBlock::*)(const opencascade::handle<BOPDS_CommonBlock> &) const ) &BOPDS_MapOfCommonBlock::Contains, "Contains", py::arg("K"));
	cls_BOPDS_MapOfCommonBlock.def("Remove", (Standard_Boolean (BOPDS_MapOfCommonBlock::*)(const opencascade::handle<BOPDS_CommonBlock> &)) &BOPDS_MapOfCommonBlock::Remove, "Remove", py::arg("K"));
	cls_BOPDS_MapOfCommonBlock.def("Clear", [](BOPDS_MapOfCommonBlock &self) -> void { return self.Clear(); });
	cls_BOPDS_MapOfCommonBlock.def("Clear", (void (BOPDS_MapOfCommonBlock::*)(const Standard_Boolean)) &BOPDS_MapOfCommonBlock::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_MapOfCommonBlock.def("Clear", (void (BOPDS_MapOfCommonBlock::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_MapOfCommonBlock::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_MapOfCommonBlock.def("Size", (Standard_Integer (BOPDS_MapOfCommonBlock::*)() const ) &BOPDS_MapOfCommonBlock::Size, "Size");
	cls_BOPDS_MapOfCommonBlock.def("IsEqual", (Standard_Boolean (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &) const ) &BOPDS_MapOfCommonBlock::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_BOPDS_MapOfCommonBlock.def("Contains", (Standard_Boolean (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &) const ) &BOPDS_MapOfCommonBlock::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_BOPDS_MapOfCommonBlock.def("Union", (void (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &, const BOPDS_MapOfCommonBlock &)) &BOPDS_MapOfCommonBlock::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfCommonBlock.def("Unite", (Standard_Boolean (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &)) &BOPDS_MapOfCommonBlock::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfCommonBlock.def("HasIntersection", (Standard_Boolean (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &) const ) &BOPDS_MapOfCommonBlock::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_BOPDS_MapOfCommonBlock.def("Intersection", (void (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &, const BOPDS_MapOfCommonBlock &)) &BOPDS_MapOfCommonBlock::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfCommonBlock.def("Intersect", (Standard_Boolean (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &)) &BOPDS_MapOfCommonBlock::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfCommonBlock.def("Subtraction", (void (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &, const BOPDS_MapOfCommonBlock &)) &BOPDS_MapOfCommonBlock::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfCommonBlock.def("Subtract", (Standard_Boolean (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &)) &BOPDS_MapOfCommonBlock::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfCommonBlock.def("Difference", (void (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &, const BOPDS_MapOfCommonBlock &)) &BOPDS_MapOfCommonBlock::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfCommonBlock.def("Differ", (Standard_Boolean (BOPDS_MapOfCommonBlock::*)(const BOPDS_MapOfCommonBlock &)) &BOPDS_MapOfCommonBlock::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfCommonBlock.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<BOPDS_MapOfPassKey, std::unique_ptr<BOPDS_MapOfPassKey, Deleter<BOPDS_MapOfPassKey>>, NCollection_BaseMap> cls_BOPDS_MapOfPassKey(mod, "BOPDS_MapOfPassKey", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_BOPDS_MapOfPassKey.def(py::init<>());
	cls_BOPDS_MapOfPassKey.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_MapOfPassKey.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_MapOfPassKey.def(py::init([] (const BOPDS_MapOfPassKey &other) {return new BOPDS_MapOfPassKey(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_MapOfPassKey.def("cbegin", (BOPDS_MapOfPassKey::const_iterator (BOPDS_MapOfPassKey::*)() const ) &BOPDS_MapOfPassKey::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_MapOfPassKey.def("cend", (BOPDS_MapOfPassKey::const_iterator (BOPDS_MapOfPassKey::*)() const ) &BOPDS_MapOfPassKey::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_MapOfPassKey.def("Exchange", (void (BOPDS_MapOfPassKey::*)(BOPDS_MapOfPassKey &)) &BOPDS_MapOfPassKey::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_MapOfPassKey.def("Assign", (BOPDS_MapOfPassKey & (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &)) &BOPDS_MapOfPassKey::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_MapOfPassKey.def("assign", (BOPDS_MapOfPassKey & (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &)) &BOPDS_MapOfPassKey::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_BOPDS_MapOfPassKey.def("ReSize", (void (BOPDS_MapOfPassKey::*)(const Standard_Integer)) &BOPDS_MapOfPassKey::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_MapOfPassKey.def("Add", (Standard_Boolean (BOPDS_MapOfPassKey::*)(const BOPDS_PassKey &)) &BOPDS_MapOfPassKey::Add, "Add", py::arg("K"));
	cls_BOPDS_MapOfPassKey.def("Added", (const BOPDS_PassKey & (BOPDS_MapOfPassKey::*)(const BOPDS_PassKey &)) &BOPDS_MapOfPassKey::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_BOPDS_MapOfPassKey.def("Contains", (Standard_Boolean (BOPDS_MapOfPassKey::*)(const BOPDS_PassKey &) const ) &BOPDS_MapOfPassKey::Contains, "Contains", py::arg("K"));
	cls_BOPDS_MapOfPassKey.def("Remove", (Standard_Boolean (BOPDS_MapOfPassKey::*)(const BOPDS_PassKey &)) &BOPDS_MapOfPassKey::Remove, "Remove", py::arg("K"));
	cls_BOPDS_MapOfPassKey.def("Clear", [](BOPDS_MapOfPassKey &self) -> void { return self.Clear(); });
	cls_BOPDS_MapOfPassKey.def("Clear", (void (BOPDS_MapOfPassKey::*)(const Standard_Boolean)) &BOPDS_MapOfPassKey::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_MapOfPassKey.def("Clear", (void (BOPDS_MapOfPassKey::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_MapOfPassKey::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_MapOfPassKey.def("Size", (Standard_Integer (BOPDS_MapOfPassKey::*)() const ) &BOPDS_MapOfPassKey::Size, "Size");
	cls_BOPDS_MapOfPassKey.def("IsEqual", (Standard_Boolean (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &) const ) &BOPDS_MapOfPassKey::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_BOPDS_MapOfPassKey.def("Contains", (Standard_Boolean (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &) const ) &BOPDS_MapOfPassKey::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_BOPDS_MapOfPassKey.def("Union", (void (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &, const BOPDS_MapOfPassKey &)) &BOPDS_MapOfPassKey::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPassKey.def("Unite", (Standard_Boolean (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &)) &BOPDS_MapOfPassKey::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPassKey.def("HasIntersection", (Standard_Boolean (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &) const ) &BOPDS_MapOfPassKey::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_BOPDS_MapOfPassKey.def("Intersection", (void (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &, const BOPDS_MapOfPassKey &)) &BOPDS_MapOfPassKey::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPassKey.def("Intersect", (Standard_Boolean (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &)) &BOPDS_MapOfPassKey::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPassKey.def("Subtraction", (void (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &, const BOPDS_MapOfPassKey &)) &BOPDS_MapOfPassKey::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPassKey.def("Subtract", (Standard_Boolean (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &)) &BOPDS_MapOfPassKey::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPassKey.def("Difference", (void (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &, const BOPDS_MapOfPassKey &)) &BOPDS_MapOfPassKey::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPassKey.def("Differ", (Standard_Boolean (BOPDS_MapOfPassKey::*)(const BOPDS_MapOfPassKey &)) &BOPDS_MapOfPassKey::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPassKey.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<BOPDS_MapOfPassKeyBoolean, std::unique_ptr<BOPDS_MapOfPassKeyBoolean, Deleter<BOPDS_MapOfPassKeyBoolean>>, NCollection_BaseMap> cls_BOPDS_MapOfPassKeyBoolean(mod, "BOPDS_MapOfPassKeyBoolean", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_BOPDS_MapOfPassKeyBoolean.def(py::init<>());
	cls_BOPDS_MapOfPassKeyBoolean.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_MapOfPassKeyBoolean.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_MapOfPassKeyBoolean.def(py::init([] (const BOPDS_MapOfPassKeyBoolean &other) {return new BOPDS_MapOfPassKeyBoolean(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_MapOfPassKeyBoolean.def("cbegin", (BOPDS_MapOfPassKeyBoolean::const_iterator (BOPDS_MapOfPassKeyBoolean::*)() const ) &BOPDS_MapOfPassKeyBoolean::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_MapOfPassKeyBoolean.def("cend", (BOPDS_MapOfPassKeyBoolean::const_iterator (BOPDS_MapOfPassKeyBoolean::*)() const ) &BOPDS_MapOfPassKeyBoolean::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_MapOfPassKeyBoolean.def("Exchange", (void (BOPDS_MapOfPassKeyBoolean::*)(BOPDS_MapOfPassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Assign", (BOPDS_MapOfPassKeyBoolean & (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_MapOfPassKeyBoolean.def("assign", (BOPDS_MapOfPassKeyBoolean & (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_BOPDS_MapOfPassKeyBoolean.def("ReSize", (void (BOPDS_MapOfPassKeyBoolean::*)(const Standard_Integer)) &BOPDS_MapOfPassKeyBoolean::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Add", (Standard_Boolean (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_PassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Add, "Add", py::arg("K"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Added", (const BOPDS_PassKeyBoolean & (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_PassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Contains", (Standard_Boolean (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_PassKeyBoolean &) const ) &BOPDS_MapOfPassKeyBoolean::Contains, "Contains", py::arg("K"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Remove", (Standard_Boolean (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_PassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Remove, "Remove", py::arg("K"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Clear", [](BOPDS_MapOfPassKeyBoolean &self) -> void { return self.Clear(); });
	cls_BOPDS_MapOfPassKeyBoolean.def("Clear", (void (BOPDS_MapOfPassKeyBoolean::*)(const Standard_Boolean)) &BOPDS_MapOfPassKeyBoolean::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Clear", (void (BOPDS_MapOfPassKeyBoolean::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_MapOfPassKeyBoolean::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Size", (Standard_Integer (BOPDS_MapOfPassKeyBoolean::*)() const ) &BOPDS_MapOfPassKeyBoolean::Size, "Size");
	cls_BOPDS_MapOfPassKeyBoolean.def("IsEqual", (Standard_Boolean (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &) const ) &BOPDS_MapOfPassKeyBoolean::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Contains", (Standard_Boolean (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &) const ) &BOPDS_MapOfPassKeyBoolean::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Union", (void (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &, const BOPDS_MapOfPassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Unite", (Standard_Boolean (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPassKeyBoolean.def("HasIntersection", (Standard_Boolean (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &) const ) &BOPDS_MapOfPassKeyBoolean::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Intersection", (void (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &, const BOPDS_MapOfPassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Intersect", (Standard_Boolean (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Subtraction", (void (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &, const BOPDS_MapOfPassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Subtract", (Standard_Boolean (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Difference", (void (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &, const BOPDS_MapOfPassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPassKeyBoolean.def("Differ", (Standard_Boolean (BOPDS_MapOfPassKeyBoolean::*)(const BOPDS_MapOfPassKeyBoolean &)) &BOPDS_MapOfPassKeyBoolean::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPassKeyBoolean.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<BOPDS_MapOfPave, std::unique_ptr<BOPDS_MapOfPave, Deleter<BOPDS_MapOfPave>>, NCollection_BaseMap> cls_BOPDS_MapOfPave(mod, "BOPDS_MapOfPave", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_BOPDS_MapOfPave.def(py::init<>());
	cls_BOPDS_MapOfPave.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPDS_MapOfPave.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPDS_MapOfPave.def(py::init([] (const BOPDS_MapOfPave &other) {return new BOPDS_MapOfPave(other);}), "Copy constructor", py::arg("other"));
	cls_BOPDS_MapOfPave.def("cbegin", (BOPDS_MapOfPave::const_iterator (BOPDS_MapOfPave::*)() const ) &BOPDS_MapOfPave::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPDS_MapOfPave.def("cend", (BOPDS_MapOfPave::const_iterator (BOPDS_MapOfPave::*)() const ) &BOPDS_MapOfPave::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPDS_MapOfPave.def("Exchange", (void (BOPDS_MapOfPave::*)(BOPDS_MapOfPave &)) &BOPDS_MapOfPave::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPDS_MapOfPave.def("Assign", (BOPDS_MapOfPave & (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &)) &BOPDS_MapOfPave::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPDS_MapOfPave.def("assign", (BOPDS_MapOfPave & (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &)) &BOPDS_MapOfPave::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_BOPDS_MapOfPave.def("ReSize", (void (BOPDS_MapOfPave::*)(const Standard_Integer)) &BOPDS_MapOfPave::ReSize, "ReSize", py::arg("N"));
	cls_BOPDS_MapOfPave.def("Add", (Standard_Boolean (BOPDS_MapOfPave::*)(const BOPDS_Pave &)) &BOPDS_MapOfPave::Add, "Add", py::arg("K"));
	cls_BOPDS_MapOfPave.def("Added", (const BOPDS_Pave & (BOPDS_MapOfPave::*)(const BOPDS_Pave &)) &BOPDS_MapOfPave::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_BOPDS_MapOfPave.def("Contains", (Standard_Boolean (BOPDS_MapOfPave::*)(const BOPDS_Pave &) const ) &BOPDS_MapOfPave::Contains, "Contains", py::arg("K"));
	cls_BOPDS_MapOfPave.def("Remove", (Standard_Boolean (BOPDS_MapOfPave::*)(const BOPDS_Pave &)) &BOPDS_MapOfPave::Remove, "Remove", py::arg("K"));
	cls_BOPDS_MapOfPave.def("Clear", [](BOPDS_MapOfPave &self) -> void { return self.Clear(); });
	cls_BOPDS_MapOfPave.def("Clear", (void (BOPDS_MapOfPave::*)(const Standard_Boolean)) &BOPDS_MapOfPave::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPDS_MapOfPave.def("Clear", (void (BOPDS_MapOfPave::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPDS_MapOfPave::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPDS_MapOfPave.def("Size", (Standard_Integer (BOPDS_MapOfPave::*)() const ) &BOPDS_MapOfPave::Size, "Size");
	cls_BOPDS_MapOfPave.def("IsEqual", (Standard_Boolean (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &) const ) &BOPDS_MapOfPave::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_BOPDS_MapOfPave.def("Contains", (Standard_Boolean (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &) const ) &BOPDS_MapOfPave::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_BOPDS_MapOfPave.def("Union", (void (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &, const BOPDS_MapOfPave &)) &BOPDS_MapOfPave::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPave.def("Unite", (Standard_Boolean (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &)) &BOPDS_MapOfPave::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPave.def("HasIntersection", (Standard_Boolean (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &) const ) &BOPDS_MapOfPave::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_BOPDS_MapOfPave.def("Intersection", (void (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &, const BOPDS_MapOfPave &)) &BOPDS_MapOfPave::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPave.def("Intersect", (Standard_Boolean (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &)) &BOPDS_MapOfPave::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPave.def("Subtraction", (void (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &, const BOPDS_MapOfPave &)) &BOPDS_MapOfPave::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPave.def("Subtract", (Standard_Boolean (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &)) &BOPDS_MapOfPave::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_BOPDS_MapOfPave.def("Difference", (void (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &, const BOPDS_MapOfPave &)) &BOPDS_MapOfPave::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_BOPDS_MapOfPave.def("Differ", (Standard_Boolean (BOPDS_MapOfPave::*)(const BOPDS_MapOfPave &)) &BOPDS_MapOfPave::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_MapOfPave.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPDS_PIteratorSI.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPDS_VectorOfListOfPassKeyBoolean, std::unique_ptr<BOPDS_VectorOfListOfPassKeyBoolean, Deleter<BOPDS_VectorOfListOfPassKeyBoolean>>> cls_BOPDS_VectorOfListOfPassKeyBoolean(mod, "BOPDS_VectorOfListOfPassKeyBoolean", "None");
	cls_BOPDS_VectorOfListOfPassKeyBoolean.def(py::init<>());
	cls_BOPDS_VectorOfListOfPassKeyBoolean.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls_BOPDS_VectorOfListOfPassKeyBoolean.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls_BOPDS_VectorOfListOfPassKeyBoolean.def("Append1", (BOPDS_ListOfPassKeyBoolean & (BOPDS_VectorOfListOfPassKeyBoolean::*)()) &BOPDS_VectorOfListOfPassKeyBoolean::Append1, "None");
	cls_BOPDS_VectorOfListOfPassKeyBoolean.def("Extent", (Standard_Integer (BOPDS_VectorOfListOfPassKeyBoolean::*)() const ) &BOPDS_VectorOfListOfPassKeyBoolean::Extent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<BOPDS_VectorOfPave, std::unique_ptr<BOPDS_VectorOfPave, Deleter<BOPDS_VectorOfPave>>> cls_BOPDS_VectorOfPave(mod, "BOPDS_VectorOfPave", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_BOPDS_VectorOfPave.def(py::init<>());
	cls_BOPDS_VectorOfPave.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_BOPDS_VectorOfPave.def(py::init([] (const BOPDS_VectorOfPave &other) {return new BOPDS_VectorOfPave(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_BOPDS_VectorOfPave.def(py::init<BOPDS_VectorOfPave &&>(), py::arg("theOther"));
	cls_BOPDS_VectorOfPave.def(py::init<const BOPDS_Pave &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_BOPDS_VectorOfPave.def("begin", (BOPDS_VectorOfPave::iterator (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::begin, "Returns an iterator pointing to the first element in the array.");
	cls_BOPDS_VectorOfPave.def("end", (BOPDS_VectorOfPave::iterator (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_BOPDS_VectorOfPave.def("cbegin", (BOPDS_VectorOfPave::const_iterator (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_BOPDS_VectorOfPave.def("cend", (BOPDS_VectorOfPave::const_iterator (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_BOPDS_VectorOfPave.def("Init", (void (BOPDS_VectorOfPave::*)(const BOPDS_Pave &)) &BOPDS_VectorOfPave::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_BOPDS_VectorOfPave.def("Size", (Standard_Integer (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::Size, "Size query");
	cls_BOPDS_VectorOfPave.def("Length", (Standard_Integer (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::Length, "Length query (the same)");
	cls_BOPDS_VectorOfPave.def("IsEmpty", (Standard_Boolean (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::IsEmpty, "Return TRUE if array has zero length.");
	cls_BOPDS_VectorOfPave.def("Lower", (Standard_Integer (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::Lower, "Lower bound");
	cls_BOPDS_VectorOfPave.def("Upper", (Standard_Integer (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::Upper, "Upper bound");
	cls_BOPDS_VectorOfPave.def("IsDeletable", (Standard_Boolean (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::IsDeletable, "myDeletable flag");
	cls_BOPDS_VectorOfPave.def("IsAllocated", (Standard_Boolean (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_BOPDS_VectorOfPave.def("Assign", (BOPDS_VectorOfPave & (BOPDS_VectorOfPave::*)(const BOPDS_VectorOfPave &)) &BOPDS_VectorOfPave::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_BOPDS_VectorOfPave.def("Move", (BOPDS_VectorOfPave & (BOPDS_VectorOfPave::*)(BOPDS_VectorOfPave &&)) &BOPDS_VectorOfPave::Move, "Move assignment", py::arg("theOther"));
	cls_BOPDS_VectorOfPave.def("assign", (BOPDS_VectorOfPave & (BOPDS_VectorOfPave::*)(const BOPDS_VectorOfPave &)) &BOPDS_VectorOfPave::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_BOPDS_VectorOfPave.def("assign", (BOPDS_VectorOfPave & (BOPDS_VectorOfPave::*)(BOPDS_VectorOfPave &&)) &BOPDS_VectorOfPave::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_BOPDS_VectorOfPave.def("First", (const BOPDS_Pave & (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::First, "Returns first element");
	cls_BOPDS_VectorOfPave.def("ChangeFirst", (BOPDS_Pave & (BOPDS_VectorOfPave::*)()) &BOPDS_VectorOfPave::ChangeFirst, "Returns first element");
	cls_BOPDS_VectorOfPave.def("Last", (const BOPDS_Pave & (BOPDS_VectorOfPave::*)() const ) &BOPDS_VectorOfPave::Last, "Returns last element");
	cls_BOPDS_VectorOfPave.def("ChangeLast", (BOPDS_Pave & (BOPDS_VectorOfPave::*)()) &BOPDS_VectorOfPave::ChangeLast, "Returns last element");
	cls_BOPDS_VectorOfPave.def("Value", (const BOPDS_Pave & (BOPDS_VectorOfPave::*)(const Standard_Integer) const ) &BOPDS_VectorOfPave::Value, "Constant value access", py::arg("theIndex"));
	cls_BOPDS_VectorOfPave.def("__call__", (const BOPDS_Pave & (BOPDS_VectorOfPave::*)(const Standard_Integer) const ) &BOPDS_VectorOfPave::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_BOPDS_VectorOfPave.def("ChangeValue", (BOPDS_Pave & (BOPDS_VectorOfPave::*)(const Standard_Integer)) &BOPDS_VectorOfPave::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_BOPDS_VectorOfPave.def("__call__", (BOPDS_Pave & (BOPDS_VectorOfPave::*)(const Standard_Integer)) &BOPDS_VectorOfPave::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_BOPDS_VectorOfPave.def("SetValue", (void (BOPDS_VectorOfPave::*)(const Standard_Integer, const BOPDS_Pave &)) &BOPDS_VectorOfPave::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_BOPDS_VectorOfPave.def("Resize", (void (BOPDS_VectorOfPave::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &BOPDS_VectorOfPave::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_BOPDS_VectorOfPave.def("__iter__", [](const BOPDS_VectorOfPave &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
