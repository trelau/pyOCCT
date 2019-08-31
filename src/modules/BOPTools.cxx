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
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Handle.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPTools_ConnexityBlock.hxx>
#include <NCollection_List.hxx>
#include <BOPTools_ListOfConnexityBlock.hxx>
#include <TopoDS_Shape.hxx>
#include <BOPTools_CoupleOfShape.hxx>
#include <BOPTools_ListOfCoupleOfShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <Precision.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <IntTools_Curve.hxx>
#include <TopAbs_State.hxx>
#include <TopoDS_Solid.hxx>
#include <IntTools_Context.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <Message_Report.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_ListOfListOfShape.hxx>
#include <IntTools_Range.hxx>
#include <TopoDS_Shell.hxx>
#include <BOPTools_AlgoTools.hxx>
#include <gp_Vec.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BOPTools_AlgoTools2D.hxx>
#include <gp_Dir.hxx>
#include <Geom_Surface.hxx>
#include <gp_Pnt2d.hxx>
#include <BOPTools_AlgoTools3D.hxx>
#include <NCollection_UBTree.hxx>
#include <Bnd_Box.hxx>
#include <BOPTools_BoxBndTree.hxx>
#include <BOPTools_BoxSelector.hxx>
#include <BOPTools_Set.hxx>
#include <BOPTools_SetMapHasher.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <BOPTools_IndexedDataMapOfSetShape.hxx>
#include <NCollection_Map.hxx>
#include <BOPTools_MapOfSet.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_UBTree.hxx>
#include <bind_BOPTools_BoxSelector.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>
#include <bind_NCollection_Map.hxx>

PYBIND11_MODULE(BOPTools, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.Precision");
py::module::import("OCCT.IntTools");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Message");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.Bnd");

// CLASS: BOPTOOLS_CONNEXITYBLOCK
py::class_<BOPTools_ConnexityBlock> cls_BOPTools_ConnexityBlock(mod, "BOPTools_ConnexityBlock", "None");

// Constructors
cls_BOPTools_ConnexityBlock.def(py::init<>());
cls_BOPTools_ConnexityBlock.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
cls_BOPTools_ConnexityBlock.def("Shapes", (const TopTools_ListOfShape & (BOPTools_ConnexityBlock::*)() const) &BOPTools_ConnexityBlock::Shapes, "None");
cls_BOPTools_ConnexityBlock.def("ChangeShapes", (TopTools_ListOfShape & (BOPTools_ConnexityBlock::*)()) &BOPTools_ConnexityBlock::ChangeShapes, "None");
cls_BOPTools_ConnexityBlock.def("SetRegular", (void (BOPTools_ConnexityBlock::*)(const Standard_Boolean)) &BOPTools_ConnexityBlock::SetRegular, "None", py::arg("theFlag"));
cls_BOPTools_ConnexityBlock.def("IsRegular", (Standard_Boolean (BOPTools_ConnexityBlock::*)() const) &BOPTools_ConnexityBlock::IsRegular, "None");
cls_BOPTools_ConnexityBlock.def("Loops", (const TopTools_ListOfShape & (BOPTools_ConnexityBlock::*)() const) &BOPTools_ConnexityBlock::Loops, "None");
cls_BOPTools_ConnexityBlock.def("ChangeLoops", (TopTools_ListOfShape & (BOPTools_ConnexityBlock::*)()) &BOPTools_ConnexityBlock::ChangeLoops, "None");

// TYPEDEF: BOPTOOLS_LISTOFCONNEXITYBLOCK
bind_NCollection_List<BOPTools_ConnexityBlock>(mod, "BOPTools_ListOfConnexityBlock", py::module_local(false));

// TYPEDEF: BOPTOOLS_LISTITERATOROFLISTOFCONNEXITYBLOCK
bind_NCollection_TListIterator<BOPTools_ConnexityBlock>(mod, "BOPTools_ListIteratorOfListOfConnexityBlock", py::module_local(false));

// CLASS: BOPTOOLS_COUPLEOFSHAPE
py::class_<BOPTools_CoupleOfShape> cls_BOPTools_CoupleOfShape(mod, "BOPTools_CoupleOfShape", "None");

// Constructors
cls_BOPTools_CoupleOfShape.def(py::init<>());

// Methods
cls_BOPTools_CoupleOfShape.def("SetShape1", (void (BOPTools_CoupleOfShape::*)(const TopoDS_Shape &)) &BOPTools_CoupleOfShape::SetShape1, "None", py::arg("theShape"));
cls_BOPTools_CoupleOfShape.def("Shape1", (const TopoDS_Shape & (BOPTools_CoupleOfShape::*)() const) &BOPTools_CoupleOfShape::Shape1, "None");
cls_BOPTools_CoupleOfShape.def("SetShape2", (void (BOPTools_CoupleOfShape::*)(const TopoDS_Shape &)) &BOPTools_CoupleOfShape::SetShape2, "None", py::arg("theShape"));
cls_BOPTools_CoupleOfShape.def("Shape2", (const TopoDS_Shape & (BOPTools_CoupleOfShape::*)() const) &BOPTools_CoupleOfShape::Shape2, "None");

// TYPEDEF: BOPTOOLS_LISTOFCOUPLEOFSHAPE
bind_NCollection_List<BOPTools_CoupleOfShape>(mod, "BOPTools_ListOfCoupleOfShape", py::module_local(false));

// TYPEDEF: BOPTOOLS_LISTITERATOROFLISTOFCOUPLEOFSHAPE
bind_NCollection_TListIterator<BOPTools_CoupleOfShape>(mod, "BOPTools_ListIteratorOfListOfCoupleOfShape", py::module_local(false));

// CLASS: BOPTOOLS_ALGOTOOLS
py::class_<BOPTools_AlgoTools> cls_BOPTools_AlgoTools(mod, "BOPTools_AlgoTools", "Provides tools used in Boolean Operations algorithm: - Vertices intersection; - Vertex construction; - Edge construction; - Classification algorithms; - Making connexity blocks; - Shape validation.");

// Methods
// cls_BOPTools_AlgoTools.def_static("operator new_", (void * (*)(size_t)) &BOPTools_AlgoTools::operator new, "None", py::arg("theSize"));
// cls_BOPTools_AlgoTools.def_static("operator delete_", (void (*)(void *)) &BOPTools_AlgoTools::operator delete, "None", py::arg("theAddress"));
// cls_BOPTools_AlgoTools.def_static("operator new[]_", (void * (*)(size_t)) &BOPTools_AlgoTools::operator new[], "None", py::arg("theSize"));
// cls_BOPTools_AlgoTools.def_static("operator delete[]_", (void (*)(void *)) &BOPTools_AlgoTools::operator delete[], "None", py::arg("theAddress"));
// cls_BOPTools_AlgoTools.def_static("operator new_", (void * (*)(size_t, void *)) &BOPTools_AlgoTools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPTools_AlgoTools.def_static("operator delete_", (void (*)(void *, void *)) &BOPTools_AlgoTools::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPTools_AlgoTools.def_static("ComputeVV_", (Standard_Integer (*)(const TopoDS_Vertex &, const gp_Pnt &, const Standard_Real)) &BOPTools_AlgoTools::ComputeVV, "Intersects the vertex <theV1> with the point <theP> with tolerance <theTolP>. Returns the error status: - 0 - no error, meaning that the vertex intersects the point; - 1 - the distance between vertex and point is grater than the sum of tolerances.", py::arg("theV"), py::arg("theP"), py::arg("theTolP"));
cls_BOPTools_AlgoTools.def_static("ComputeVV_", [](const TopoDS_Vertex & a0, const TopoDS_Vertex & a1) -> Standard_Integer { return BOPTools_AlgoTools::ComputeVV(a0, a1); });
cls_BOPTools_AlgoTools.def_static("ComputeVV_", (Standard_Integer (*)(const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real)) &BOPTools_AlgoTools::ComputeVV, "Intersects the given vertices with given fuzzy value. Returns the error status: - 0 - no error, meaning that the vertices interferes with given tolerance; - 1 - the distance between vertices is grater than the sum of their tolerances.", py::arg("theV1"), py::arg("theV2"), py::arg("theFuzz"));
cls_BOPTools_AlgoTools.def_static("MakeVertex_", (void (*)(const TopTools_ListOfShape &, TopoDS_Vertex &)) &BOPTools_AlgoTools::MakeVertex, "Makes the vertex in the middle of given vertices with the tolerance covering all tolerance spheres of vertices.", py::arg("theLV"), py::arg("theV"));
cls_BOPTools_AlgoTools.def_static("MakeNewVertex_", (void (*)(const gp_Pnt &, const Standard_Real, TopoDS_Vertex &)) &BOPTools_AlgoTools::MakeNewVertex, "Make a vertex using 3D-point <aP1> and 3D-tolerance value <aTol>", py::arg("aP1"), py::arg("aTol"), py::arg("aNewVertex"));
cls_BOPTools_AlgoTools.def_static("MakeNewVertex_", (void (*)(const TopoDS_Vertex &, const TopoDS_Vertex &, TopoDS_Vertex &)) &BOPTools_AlgoTools::MakeNewVertex, "Make a vertex using couple of vertices <aV1, aV2>", py::arg("aV1"), py::arg("aV2"), py::arg("aNewVertex"));
cls_BOPTools_AlgoTools.def_static("MakeNewVertex_", (void (*)(const TopoDS_Edge &, const Standard_Real, const TopoDS_Edge &, const Standard_Real, TopoDS_Vertex &)) &BOPTools_AlgoTools::MakeNewVertex, "Make a vertex in place of intersection between two edges <aE1, aE2> with parameters <aP1, aP2>", py::arg("aE1"), py::arg("aP1"), py::arg("aE2"), py::arg("aP2"), py::arg("aNewVertex"));
cls_BOPTools_AlgoTools.def_static("MakeNewVertex_", (void (*)(const TopoDS_Edge &, const Standard_Real, const TopoDS_Face &, TopoDS_Vertex &)) &BOPTools_AlgoTools::MakeNewVertex, "Make a vertex in place of intersection between the edge <aE1> with parameter <aP1> and the face <aF2>", py::arg("aE1"), py::arg("aP1"), py::arg("aF2"), py::arg("aNewVertex"));
cls_BOPTools_AlgoTools.def_static("UpdateVertex_", (void (*)(const IntTools_Curve &, const Standard_Real, const TopoDS_Vertex &)) &BOPTools_AlgoTools::UpdateVertex, "Update the tolerance value for vertex <aV> taking into account the fact that <aV> lays on the curve <aIC>", py::arg("aIC"), py::arg("aT"), py::arg("aV"));
cls_BOPTools_AlgoTools.def_static("UpdateVertex_", (void (*)(const TopoDS_Edge &, const Standard_Real, const TopoDS_Vertex &)) &BOPTools_AlgoTools::UpdateVertex, "Update the tolerance value for vertex <aV> taking into account the fact that <aV> lays on the edge <aE>", py::arg("aE"), py::arg("aT"), py::arg("aV"));
cls_BOPTools_AlgoTools.def_static("UpdateVertex_", (void (*)(const TopoDS_Vertex &, const TopoDS_Vertex &)) &BOPTools_AlgoTools::UpdateVertex, "Update the tolerance value for vertex <aVN> taking into account the fact that <aVN> should cover tolerance zone of <aVF>", py::arg("aVF"), py::arg("aVN"));
cls_BOPTools_AlgoTools.def_static("MakeEdge_", (void (*)(const IntTools_Curve &, const TopoDS_Vertex &, const Standard_Real, const TopoDS_Vertex &, const Standard_Real, const Standard_Real, TopoDS_Edge &)) &BOPTools_AlgoTools::MakeEdge, "Makes the edge based on the given curve with given bounding vertices.", py::arg("theCurve"), py::arg("theV1"), py::arg("theT1"), py::arg("theV2"), py::arg("theT2"), py::arg("theTolR3D"), py::arg("theE"));
cls_BOPTools_AlgoTools.def_static("CopyEdge_", (TopoDS_Edge (*)(const TopoDS_Edge &)) &BOPTools_AlgoTools::CopyEdge, "Makes a copy of <theEdge> with vertices.", py::arg("theEdge"));
cls_BOPTools_AlgoTools.def_static("MakeSplitEdge_", (void (*)(const TopoDS_Edge &, const TopoDS_Vertex &, const Standard_Real, const TopoDS_Vertex &, const Standard_Real, TopoDS_Edge &)) &BOPTools_AlgoTools::MakeSplitEdge, "Make the edge from base edge <aE1> and two vertices <aV1,aV2> at parameters <aP1,aP2>", py::arg("aE1"), py::arg("aV1"), py::arg("aP1"), py::arg("aV2"), py::arg("aP2"), py::arg("aNewEdge"));
cls_BOPTools_AlgoTools.def_static("MakeSectEdge_", (void (*)(const IntTools_Curve &, const TopoDS_Vertex &, const Standard_Real, const TopoDS_Vertex &, const Standard_Real, TopoDS_Edge &)) &BOPTools_AlgoTools::MakeSectEdge, "Make the edge from 3D-Curve <aIC> and two vertices <aV1,aV2> at parameters <aP1,aP2>", py::arg("aIC"), py::arg("aV1"), py::arg("aP1"), py::arg("aV2"), py::arg("aP2"), py::arg("aNewEdge"));
cls_BOPTools_AlgoTools.def_static("ComputeState_", (TopAbs_State (*)(const gp_Pnt &, const TopoDS_Solid &, const Standard_Real, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::ComputeState, "Computes the 3-D state of the point thePoint toward solid theSolid. theTol - value of precision of computation theContext- cahed geometrical tools Returns 3-D state.", py::arg("thePoint"), py::arg("theSolid"), py::arg("theTol"), py::arg("theContext"));
cls_BOPTools_AlgoTools.def_static("ComputeState_", (TopAbs_State (*)(const TopoDS_Vertex &, const TopoDS_Solid &, const Standard_Real, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::ComputeState, "Computes the 3-D state of the vertex theVertex toward solid theSolid. theTol - value of precision of computation theContext- cahed geometrical tools Returns 3-D state.", py::arg("theVertex"), py::arg("theSolid"), py::arg("theTol"), py::arg("theContext"));
cls_BOPTools_AlgoTools.def_static("ComputeState_", (TopAbs_State (*)(const TopoDS_Edge &, const TopoDS_Solid &, const Standard_Real, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::ComputeState, "Computes the 3-D state of the edge theEdge toward solid theSolid. theTol - value of precision of computation theContext- cahed geometrical tools Returns 3-D state.", py::arg("theEdge"), py::arg("theSolid"), py::arg("theTol"), py::arg("theContext"));
cls_BOPTools_AlgoTools.def_static("ComputeState_", (TopAbs_State (*)(const TopoDS_Face &, const TopoDS_Solid &, const Standard_Real, TopTools_IndexedMapOfShape &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::ComputeState, "Computes the 3-D state of the face theFace toward solid theSolid. theTol - value of precision of computation theBounds - set of edges of theFace to avoid theContext- cahed geometrical tools Returns 3-D state.", py::arg("theFace"), py::arg("theSolid"), py::arg("theTol"), py::arg("theBounds"), py::arg("theContext"));
cls_BOPTools_AlgoTools.def_static("ComputeStateByOnePoint_", (TopAbs_State (*)(const TopoDS_Shape &, const TopoDS_Solid &, const Standard_Real, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::ComputeStateByOnePoint, "Computes the 3-D state of the shape theShape toward solid theSolid. theTol - value of precision of computation theContext- cahed geometrical tools Returns 3-D state.", py::arg("theShape"), py::arg("theSolid"), py::arg("theTol"), py::arg("theContext"));
cls_BOPTools_AlgoTools.def_static("GetFaceOff_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, BOPTools_ListOfCoupleOfShape &, TopoDS_Face &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::GetFaceOff, "For the face theFace and its edge theEdge finds the face suitable to produce shell. theLCEF - set of faces to search. All faces from theLCEF must share edge theEdge", py::arg("theEdge"), py::arg("theFace"), py::arg("theLCEF"), py::arg("theFaceOff"), py::arg("theContext"));
cls_BOPTools_AlgoTools.def_static("IsInternalFace_", (Standard_Integer (*)(const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::IsInternalFace, "Returns True if the face theFace is inside of the couple of faces theFace1, theFace2. The faces theFace, theFace1, theFace2 must share the edge theEdge Return values: * 0 state is not IN * 1 state is IN * 2 state can not be found by the method of angles", py::arg("theFace"), py::arg("theEdge"), py::arg("theFace1"), py::arg("theFace2"), py::arg("theContext"));
cls_BOPTools_AlgoTools.def_static("IsInternalFace_", (Standard_Integer (*)(const TopoDS_Face &, const TopoDS_Edge &, TopTools_ListOfShape &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::IsInternalFace, "Returns True if the face theFace is inside of the appropriate couple of faces (from the set theLF) . The faces of the set theLF and theFace must share the edge theEdge * 0 state is not IN * 1 state is IN * 2 state can not be found by the method of angles", py::arg("theFace"), py::arg("theEdge"), py::arg("theLF"), py::arg("theContext"));
cls_BOPTools_AlgoTools.def_static("IsInternalFace_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Solid &, TopTools_IndexedDataMapOfShapeListOfShape &, const Standard_Real, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::IsInternalFace, "Returns True if the face theFace is inside the solid theSolid. theMEF - Map Edge/Faces for theSolid theTol - value of precision of computation theContext- cahed geometrical tools", py::arg("theFace"), py::arg("theSolid"), py::arg("theMEF"), py::arg("theTol"), py::arg("theContext"));
cls_BOPTools_AlgoTools.def_static("MakePCurve_", [](const TopoDS_Edge & a0, const TopoDS_Face & a1, const TopoDS_Face & a2, const IntTools_Curve & a3, const Standard_Boolean a4, const Standard_Boolean a5) -> void { return BOPTools_AlgoTools::MakePCurve(a0, a1, a2, a3, a4, a5); });
cls_BOPTools_AlgoTools.def_static("MakePCurve_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const IntTools_Curve &, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::MakePCurve, "Makes 2d curve of the edge <theE> on the faces <theF1> and <theF2>. <theContext> - storage for caching the geometrical tools", py::arg("theE"), py::arg("theF1"), py::arg("theF2"), py::arg("theCurve"), py::arg("thePC1"), py::arg("thePC2"), py::arg("theContext"));
cls_BOPTools_AlgoTools.def_static("IsHole_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BOPTools_AlgoTools::IsHole, "Checks if the wire is a hole for the face.", py::arg("theW"), py::arg("theF"));
cls_BOPTools_AlgoTools.def_static("IsSplitToReverse_", [](const TopoDS_Shape & theSplit, const TopoDS_Shape & theShape, const opencascade::handle<IntTools_Context> & theContext, Standard_Integer * theError){ Standard_Boolean rv = BOPTools_AlgoTools::IsSplitToReverse(theSplit, theShape, theContext, theError); return std::tuple<Standard_Boolean, Standard_Integer *>(rv, theError); }, "Checks if the direction of the split shape is opposite to the direction of the original shape. The method is an overload for (Edge,Edge) and (Face,Face) corresponding methods and checks only these types of shapes. For faces the method checks if normal directions are opposite. For edges the method checks if tangent vectors are opposite.", py::arg("theSplit"), py::arg("theShape"), py::arg("theContext"), py::arg("theError"));
cls_BOPTools_AlgoTools.def_static("IsSplitToReverseWithWarn_", [](const TopoDS_Shape & a0, const TopoDS_Shape & a1, const opencascade::handle<IntTools_Context> & a2) -> Standard_Boolean { return BOPTools_AlgoTools::IsSplitToReverseWithWarn(a0, a1, a2); });
cls_BOPTools_AlgoTools.def_static("IsSplitToReverseWithWarn_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<IntTools_Context> &, const opencascade::handle<Message_Report> &)) &BOPTools_AlgoTools::IsSplitToReverseWithWarn, "Add-on for the *IsSplitToReverse()* to check for its errors and in case of any add the *BOPAlgo_AlertUnableToOrientTheShape* warning to the report.", py::arg("theSplit"), py::arg("theShape"), py::arg("theContext"), py::arg("theReport"));
cls_BOPTools_AlgoTools.def_static("IsSplitToReverse_", [](const TopoDS_Face & theSplit, const TopoDS_Face & theShape, const opencascade::handle<IntTools_Context> & theContext, Standard_Integer * theError){ Standard_Boolean rv = BOPTools_AlgoTools::IsSplitToReverse(theSplit, theShape, theContext, theError); return std::tuple<Standard_Boolean, Standard_Integer *>(rv, theError); }, "Checks if the normal direction of the split face is opposite to the normal direction of the original face. The normal directions for both faces are taken in the same point - point inside the split face is projected onto the original face. Returns TRUE if the normals do not coincide, meaning the necessity to revert the orientation of the split face to match the direction of the original face.", py::arg("theSplit"), py::arg("theShape"), py::arg("theContext"), py::arg("theError"));
cls_BOPTools_AlgoTools.def_static("IsSplitToReverse_", [](const TopoDS_Edge & theSplit, const TopoDS_Edge & theShape, const opencascade::handle<IntTools_Context> & theContext, Standard_Integer * theError){ Standard_Boolean rv = BOPTools_AlgoTools::IsSplitToReverse(theSplit, theShape, theContext, theError); return std::tuple<Standard_Boolean, Standard_Integer *>(rv, theError); }, "Checks if the tangent vector of the split edge is opposite to the tangent vector of the original edge. The tangent vectors for both edges are computed in the same point - point inside the split edge is projected onto the original edge. Returns TRUE if the tangent vectors do not coincide, meaning the necessity to revert the orientation of the split edge to match the direction of the original edge.", py::arg("theSplit"), py::arg("theShape"), py::arg("theContext"), py::arg("theError"));
cls_BOPTools_AlgoTools.def_static("Sense_", (Standard_Integer (*)(const TopoDS_Face &, const TopoDS_Face &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::Sense, "Checks if the normals direction of the given faces computed near the shared edge coincide. Returns the status of operation: * 0 - in case of error (shared edge not found or directions are not collinear) * 1 - normal directions coincide; * -1 - normal directions are opposite.", py::arg("theF1"), py::arg("theF2"), py::arg("theContext"));
cls_BOPTools_AlgoTools.def_static("MakeConnexityBlock_", (void (*)(TopTools_ListOfShape &, TopTools_IndexedMapOfShape &, TopTools_ListOfShape &, const opencascade::handle<NCollection_BaseAllocator> &)) &BOPTools_AlgoTools::MakeConnexityBlock, "For the list of faces theLS build block theLSCB in terms of connexity by edges theMapAvoid - set of edges to avoid for the treatment", py::arg("theLS"), py::arg("theMapAvoid"), py::arg("theLSCB"), py::arg("theAllocator"));
cls_BOPTools_AlgoTools.def_static("MakeConnexityBlocks_", (void (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, TopTools_ListOfShape &)) &BOPTools_AlgoTools::MakeConnexityBlocks, "For the compound <theS> builds the blocks (compounds) of elements of type <theElementType> connected through the shapes of the type <theConnectionType>. The blocks are stored into the list <theLCB>.", py::arg("theS"), py::arg("theConnectionType"), py::arg("theElementType"), py::arg("theLCB"));
cls_BOPTools_AlgoTools.def_static("MakeConnexityBlocks_", (void (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, TopTools_ListOfListOfShape &, TopTools_IndexedDataMapOfShapeListOfShape &)) &BOPTools_AlgoTools::MakeConnexityBlocks, "For the compound <theS> builds the blocks (compounds) of elements of type <theElementType> connected through the shapes of the type <theConnectionType>. The blocks are stored into the list of lists <theLCB>. Returns also the connection map <theConnectionMap>, filled during operation.", py::arg("theS"), py::arg("theConnectionType"), py::arg("theElementType"), py::arg("theLCB"), py::arg("theConnectionMap"));
cls_BOPTools_AlgoTools.def_static("MakeConnexityBlocks_", (void (*)(const TopTools_ListOfShape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, BOPTools_ListOfConnexityBlock &)) &BOPTools_AlgoTools::MakeConnexityBlocks, "Makes connexity blocks of elements of the given type with the given type of the connecting elements. The blocks are checked on regularity (multi-connectivity) and stored to the list of blocks <theLCB>.", py::arg("theLS"), py::arg("theConnectionType"), py::arg("theElementType"), py::arg("theLCB"));
cls_BOPTools_AlgoTools.def_static("OrientEdgesOnWire_", (void (*)(TopoDS_Shape &)) &BOPTools_AlgoTools::OrientEdgesOnWire, "Correctly orients edges on the wire", py::arg("theWire"));
cls_BOPTools_AlgoTools.def_static("OrientFacesOnShell_", (void (*)(TopoDS_Shape &)) &BOPTools_AlgoTools::OrientFacesOnShell, "Correctly orients faces on the shell", py::arg("theShell"));
cls_BOPTools_AlgoTools.def_static("CorrectTolerances_", [](const TopoDS_Shape & a0, const TopTools_IndexedMapOfShape & a1) -> void { return BOPTools_AlgoTools::CorrectTolerances(a0, a1); });
cls_BOPTools_AlgoTools.def_static("CorrectTolerances_", [](const TopoDS_Shape & a0, const TopTools_IndexedMapOfShape & a1, const Standard_Real a2) -> void { return BOPTools_AlgoTools::CorrectTolerances(a0, a1, a2); });
cls_BOPTools_AlgoTools.def_static("CorrectTolerances_", (void (*)(const TopoDS_Shape &, const TopTools_IndexedMapOfShape &, const Standard_Real, const Standard_Boolean)) &BOPTools_AlgoTools::CorrectTolerances, "Provides valid values of tolerances for the shape <theS> <theTolMax> is max value of the tolerance that can be accepted for correction. If real value of the tolerance will be greater than <aTolMax>, the correction does not perform.", py::arg("theS"), py::arg("theMapToAvoid"), py::arg("theTolMax"), py::arg("theRunParallel"));
cls_BOPTools_AlgoTools.def_static("CorrectCurveOnSurface_", [](const TopoDS_Shape & a0, const TopTools_IndexedMapOfShape & a1) -> void { return BOPTools_AlgoTools::CorrectCurveOnSurface(a0, a1); });
cls_BOPTools_AlgoTools.def_static("CorrectCurveOnSurface_", [](const TopoDS_Shape & a0, const TopTools_IndexedMapOfShape & a1, const Standard_Real a2) -> void { return BOPTools_AlgoTools::CorrectCurveOnSurface(a0, a1, a2); });
cls_BOPTools_AlgoTools.def_static("CorrectCurveOnSurface_", (void (*)(const TopoDS_Shape &, const TopTools_IndexedMapOfShape &, const Standard_Real, const Standard_Boolean)) &BOPTools_AlgoTools::CorrectCurveOnSurface, "Provides valid values of tolerances for the shape <theS> in terms of BRepCheck_InvalidCurveOnSurface.", py::arg("theS"), py::arg("theMapToAvoid"), py::arg("theTolMax"), py::arg("theRunParallel"));
cls_BOPTools_AlgoTools.def_static("CorrectPointOnCurve_", [](const TopoDS_Shape & a0, const TopTools_IndexedMapOfShape & a1) -> void { return BOPTools_AlgoTools::CorrectPointOnCurve(a0, a1); });
cls_BOPTools_AlgoTools.def_static("CorrectPointOnCurve_", [](const TopoDS_Shape & a0, const TopTools_IndexedMapOfShape & a1, const Standard_Real a2) -> void { return BOPTools_AlgoTools::CorrectPointOnCurve(a0, a1, a2); });
cls_BOPTools_AlgoTools.def_static("CorrectPointOnCurve_", (void (*)(const TopoDS_Shape &, const TopTools_IndexedMapOfShape &, const Standard_Real, const Standard_Boolean)) &BOPTools_AlgoTools::CorrectPointOnCurve, "Provides valid values of tolerances for the shape <theS> in terms of BRepCheck_InvalidPointOnCurve.", py::arg("theS"), py::arg("theMapToAvoid"), py::arg("theTolMax"), py::arg("theRunParallel"));
cls_BOPTools_AlgoTools.def_static("CorrectShapeTolerances_", [](const TopoDS_Shape & a0, const TopTools_IndexedMapOfShape & a1) -> void { return BOPTools_AlgoTools::CorrectShapeTolerances(a0, a1); });
cls_BOPTools_AlgoTools.def_static("CorrectShapeTolerances_", (void (*)(const TopoDS_Shape &, const TopTools_IndexedMapOfShape &, const Standard_Boolean)) &BOPTools_AlgoTools::CorrectShapeTolerances, "Corrects tolerance values of the sub-shapes of the shape <theS> if needed.", py::arg("theS"), py::arg("theMapToAvoid"), py::arg("theRunParallel"));
cls_BOPTools_AlgoTools.def_static("AreFacesSameDomain_", [](const TopoDS_Face & a0, const TopoDS_Face & a1, const opencascade::handle<IntTools_Context> & a2) -> Standard_Boolean { return BOPTools_AlgoTools::AreFacesSameDomain(a0, a1, a2); });
cls_BOPTools_AlgoTools.def_static("AreFacesSameDomain_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const opencascade::handle<IntTools_Context> &, const Standard_Real)) &BOPTools_AlgoTools::AreFacesSameDomain, "Checks if the given faces are same-domain, i.e. coincide.", py::arg("theF1"), py::arg("theF2"), py::arg("theContext"), py::arg("theFuzz"));
cls_BOPTools_AlgoTools.def_static("GetEdgeOff_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, TopoDS_Edge &)) &BOPTools_AlgoTools::GetEdgeOff, "Returns True if the face theFace contains the edge theEdge but with opposite orientation. If the method returns True theEdgeOff is the edge founded", py::arg("theEdge"), py::arg("theFace"), py::arg("theEdgeOff"));
cls_BOPTools_AlgoTools.def_static("GetEdgeOnFace_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, TopoDS_Edge &)) &BOPTools_AlgoTools::GetEdgeOnFace, "For the face theFace gets the edge theEdgeOnF that is the same as theEdge Returns True if such edge exists Returns False if there is no such edge", py::arg("theEdge"), py::arg("theFace"), py::arg("theEdgeOnF"));
cls_BOPTools_AlgoTools.def_static("CorrectRange_", (void (*)(const TopoDS_Edge &, const TopoDS_Edge &, const IntTools_Range &, IntTools_Range &)) &BOPTools_AlgoTools::CorrectRange, "Correct shrunk range <aSR> taking into account 3D-curve resolution and corresponding tolerance values of <aE1>, <aE2>", py::arg("aE1"), py::arg("aE2"), py::arg("aSR"), py::arg("aNewSR"));
cls_BOPTools_AlgoTools.def_static("CorrectRange_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const IntTools_Range &, IntTools_Range &)) &BOPTools_AlgoTools::CorrectRange, "Correct shrunk range <aSR> taking into account 3D-curve resolution and corresponding tolerance values of <aE>, <aF>", py::arg("aE"), py::arg("aF"), py::arg("aSR"), py::arg("aNewSR"));
cls_BOPTools_AlgoTools.def_static("IsMicroEdge_", [](const TopoDS_Edge & a0, const opencascade::handle<IntTools_Context> & a1) -> Standard_Boolean { return BOPTools_AlgoTools::IsMicroEdge(a0, a1); });
cls_BOPTools_AlgoTools.def_static("IsMicroEdge_", (Standard_Boolean (*)(const TopoDS_Edge &, const opencascade::handle<IntTools_Context> &, const Standard_Boolean)) &BOPTools_AlgoTools::IsMicroEdge, "Checks if it is possible to compute shrunk range for the edge <aE> Flag <theCheckSplittable> defines whether to take into account the possibility to split the edge or not.", py::arg("theEdge"), py::arg("theContext"), py::arg("theCheckSplittable"));
cls_BOPTools_AlgoTools.def_static("IsInvertedSolid_", (Standard_Boolean (*)(const TopoDS_Solid &)) &BOPTools_AlgoTools::IsInvertedSolid, "Returns true if the solid <theSolid> is inverted", py::arg("theSolid"));
cls_BOPTools_AlgoTools.def_static("ComputeTolerance_", [](const TopoDS_Face & theFace, const TopoDS_Edge & theEdge, Standard_Real & theMaxDist, Standard_Real & theMaxPar){ Standard_Boolean rv = BOPTools_AlgoTools::ComputeTolerance(theFace, theEdge, theMaxDist, theMaxPar); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theMaxDist, theMaxPar); }, "Computes the necessary value of the tolerance for the edge", py::arg("theFace"), py::arg("theEdge"), py::arg("theMaxDist"), py::arg("theMaxPar"));
cls_BOPTools_AlgoTools.def_static("MakeContainer_", (void (*)(const TopAbs_ShapeEnum, TopoDS_Shape &)) &BOPTools_AlgoTools::MakeContainer, "Makes empty container of requested type", py::arg("theType"), py::arg("theShape"));
cls_BOPTools_AlgoTools.def_static("PointOnEdge_", (void (*)(const TopoDS_Edge &, const Standard_Real, gp_Pnt &)) &BOPTools_AlgoTools::PointOnEdge, "Compute a 3D-point on the edge <aEdge> at parameter <aPrm>", py::arg("aEdge"), py::arg("aPrm"), py::arg("aP"));
cls_BOPTools_AlgoTools.def_static("IsBlockInOnFace_", (Standard_Boolean (*)(const IntTools_Range &, const TopoDS_Face &, const TopoDS_Edge &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools::IsBlockInOnFace, "Returns TRUE if PaveBlock <aPB> lays on the face <aF>, i.e the <PB> is IN or ON in 2D of <aF>", py::arg("aShR"), py::arg("aF"), py::arg("aE"), py::arg("aContext"));
cls_BOPTools_AlgoTools.def_static("Dimension_", (Standard_Integer (*)(const TopoDS_Shape &)) &BOPTools_AlgoTools::Dimension, "Retutns dimension of the shape <theS>.", py::arg("theS"));
cls_BOPTools_AlgoTools.def_static("IsOpenShell_", (Standard_Boolean (*)(const TopoDS_Shell &)) &BOPTools_AlgoTools::IsOpenShell, "Returns true if the shell <theShell> is open", py::arg("theShell"));

// CLASS: BOPTOOLS_ALGOTOOLS2D
py::class_<BOPTools_AlgoTools2D> cls_BOPTools_AlgoTools2D(mod, "BOPTools_AlgoTools2D", "The class contains handy static functions dealing with the topology This is the copy of the BOPTools_AlgoTools2D.cdl");

// Methods
// cls_BOPTools_AlgoTools2D.def_static("operator new_", (void * (*)(size_t)) &BOPTools_AlgoTools2D::operator new, "None", py::arg("theSize"));
// cls_BOPTools_AlgoTools2D.def_static("operator delete_", (void (*)(void *)) &BOPTools_AlgoTools2D::operator delete, "None", py::arg("theAddress"));
// cls_BOPTools_AlgoTools2D.def_static("operator new[]_", (void * (*)(size_t)) &BOPTools_AlgoTools2D::operator new[], "None", py::arg("theSize"));
// cls_BOPTools_AlgoTools2D.def_static("operator delete[]_", (void (*)(void *)) &BOPTools_AlgoTools2D::operator delete[], "None", py::arg("theAddress"));
// cls_BOPTools_AlgoTools2D.def_static("operator new_", (void * (*)(size_t, void *)) &BOPTools_AlgoTools2D::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPTools_AlgoTools2D.def_static("operator delete_", (void (*)(void *, void *)) &BOPTools_AlgoTools2D::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPTools_AlgoTools2D.def_static("BuildPCurveForEdgeOnFace_", [](const TopoDS_Edge & a0, const TopoDS_Face & a1) -> void { return BOPTools_AlgoTools2D::BuildPCurveForEdgeOnFace(a0, a1); });
cls_BOPTools_AlgoTools2D.def_static("BuildPCurveForEdgeOnFace_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools2D::BuildPCurveForEdgeOnFace, "Compute P-Curve for the edge <aE> on the face <aF>. Raises exception Standard_ConstructionError if projection algorithm fails. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("EdgeTangent_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real, gp_Vec &)) &BOPTools_AlgoTools2D::EdgeTangent, "Compute tangent for the edge <aE> [in 3D] at parameter <aT>", py::arg("anE"), py::arg("aT"), py::arg("Tau"));
cls_BOPTools_AlgoTools2D.def_static("PointOnSurface_", [](const TopoDS_Edge & aE, const TopoDS_Face & aF, const Standard_Real aT, Standard_Real & U, Standard_Real & V, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::PointOnSurface(aE, aF, aT, U, V, theContext); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Compute surface parameters <U,V> of the face <aF> for the point from the edge <aE> at parameter <aT>. If <aE> has't pcurve on surface, algorithm tries to get it by projection and can raise exception Standard_ConstructionError if projection algorithm fails. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("U"), py::arg("V"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("CurveOnSurface_", [](const TopoDS_Edge & aE, const TopoDS_Face & aF, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aToler, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::CurveOnSurface(aE, aF, aC, aToler, theContext); return aToler; }, "Get P-Curve <aC> for the edge <aE> on surface <aF> . If the P-Curve does not exist, build it using Make2D(). [aToler] - reached tolerance Raises exception Standard_ConstructionError if algorithm Make2D() fails. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aC"), py::arg("aToler"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("CurveOnSurface_", [](const TopoDS_Edge & aE, const TopoDS_Face & aF, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aFirst, Standard_Real & aLast, Standard_Real & aToler, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::CurveOnSurface(aE, aF, aC, aFirst, aLast, aToler, theContext); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(aFirst, aLast, aToler); }, "Get P-Curve <aC> for the edge <aE> on surface <aF> . If the P-Curve does not exist, build it using Make2D(). [aFirst, aLast] - range of the P-Curve [aToler] - reached tolerance Raises exception Standard_ConstructionError if algorithm Make2D() fails. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aC"), py::arg("aFirst"), py::arg("aLast"), py::arg("aToler"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("HasCurveOnSurface_", [](const TopoDS_Edge & aE, const TopoDS_Face & aF, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aFirst, Standard_Real & aLast, Standard_Real & aToler){ Standard_Boolean rv = BOPTools_AlgoTools2D::HasCurveOnSurface(aE, aF, aC, aFirst, aLast, aToler); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &>(rv, aFirst, aLast, aToler); }, "Returns TRUE if the edge <aE> has P-Curve <aC> on surface <aF> . [aFirst, aLast] - range of the P-Curve [aToler] - reached tolerance If the P-Curve does not exist, aC.IsNull()=TRUE.", py::arg("aE"), py::arg("aF"), py::arg("aC"), py::arg("aFirst"), py::arg("aLast"), py::arg("aToler"));
cls_BOPTools_AlgoTools2D.def_static("HasCurveOnSurface_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BOPTools_AlgoTools2D::HasCurveOnSurface, "Returns TRUE if the edge <aE> has P-Curve <aC> on surface <aF> . If the P-Curve does not exist, aC.IsNull()=TRUE.", py::arg("aE"), py::arg("aF"));
cls_BOPTools_AlgoTools2D.def_static("AdjustPCurveOnFace_", [](const TopoDS_Face & a0, const opencascade::handle<Geom_Curve> & a1, const opencascade::handle<Geom2d_Curve> & a2, opencascade::handle<Geom2d_Curve> & a3) -> void { return BOPTools_AlgoTools2D::AdjustPCurveOnFace(a0, a1, a2, a3); });
cls_BOPTools_AlgoTools2D.def_static("AdjustPCurveOnFace_", (void (*)(const TopoDS_Face &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools2D::AdjustPCurveOnFace, "Adjust P-Curve <theC2D> (3D-curve <theC3D>) on surface of the face <theF>. <theContext> - storage for caching the geometrical tools", py::arg("theF"), py::arg("theC3D"), py::arg("theC2D"), py::arg("theC2DA"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("AdjustPCurveOnFace_", [](const TopoDS_Face & a0, const Standard_Real a1, const Standard_Real a2, const opencascade::handle<Geom2d_Curve> & a3, opencascade::handle<Geom2d_Curve> & a4) -> void { return BOPTools_AlgoTools2D::AdjustPCurveOnFace(a0, a1, a2, a3, a4); });
cls_BOPTools_AlgoTools2D.def_static("AdjustPCurveOnFace_", (void (*)(const TopoDS_Face &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools2D::AdjustPCurveOnFace, "Adjust P-Curve <aC2D> (3D-curve <C3D>) on surface <aF> . [aT1, aT2] - range to adjust <theContext> - storage for caching the geometrical tools", py::arg("theF"), py::arg("theFirst"), py::arg("theLast"), py::arg("theC2D"), py::arg("theC2DA"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("AdjustPCurveOnSurf_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &)) &BOPTools_AlgoTools2D::AdjustPCurveOnSurf, "Adjust P-Curve <aC2D> (3D-curve <C3D>) on surface <aF> . [aT1, aT2] - range to adjust", py::arg("aF"), py::arg("aT1"), py::arg("aT2"), py::arg("aC2D"), py::arg("aC2DA"));
cls_BOPTools_AlgoTools2D.def_static("IntermediatePoint_", (Standard_Real (*)(const Standard_Real, const Standard_Real)) &BOPTools_AlgoTools2D::IntermediatePoint, "Compute intermediate value in between [aFirst, aLast] .", py::arg("aFirst"), py::arg("aLast"));
cls_BOPTools_AlgoTools2D.def_static("IntermediatePoint_", (Standard_Real (*)(const TopoDS_Edge &)) &BOPTools_AlgoTools2D::IntermediatePoint, "Compute intermediate value of parameter for the edge <anE>.", py::arg("anE"));
cls_BOPTools_AlgoTools2D.def_static("Make2D_", [](const TopoDS_Edge & aE, const TopoDS_Face & aF, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aFirst, Standard_Real & aLast, Standard_Real & aToler, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::Make2D(aE, aF, aC, aFirst, aLast, aToler, theContext); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(aFirst, aLast, aToler); }, "Make P-Curve <aC> for the edge <aE> on surface <aF> . [aFirst, aLast] - range of the P-Curve [aToler] - reached tolerance Raises exception Standard_ConstructionError if algorithm fails. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aC"), py::arg("aFirst"), py::arg("aLast"), py::arg("aToler"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("MakePCurveOnFace_", [](const TopoDS_Face & aF, const opencascade::handle<Geom_Curve> & C3D, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aToler, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::MakePCurveOnFace(aF, C3D, aC, aToler, theContext); return aToler; }, "Make P-Curve <aC> for the 3D-curve <C3D> on surface <aF> . [aToler] - reached tolerance Raises exception Standard_ConstructionError if projection algorithm fails. <theContext> - storage for caching the geometrical tools", py::arg("aF"), py::arg("C3D"), py::arg("aC"), py::arg("aToler"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("MakePCurveOnFace_", [](const TopoDS_Face & aF, const opencascade::handle<Geom_Curve> & C3D, const Standard_Real aT1, const Standard_Real aT2, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aToler, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::MakePCurveOnFace(aF, C3D, aT1, aT2, aC, aToler, theContext); return aToler; }, "Make P-Curve <aC> for the 3D-curve <C3D> on surface <aF> . [aT1, aT2] - range to build [aToler] - reached tolerance Raises exception Standard_ConstructionError if projection algorithm fails. <theContext> - storage for caching the geometrical tools", py::arg("aF"), py::arg("C3D"), py::arg("aT1"), py::arg("aT2"), py::arg("aC"), py::arg("aToler"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("AttachExistingPCurve_", (Standard_Integer (*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Face &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools2D::AttachExistingPCurve, "Attach P-Curve from the edge <aEold> on surface <aF> to the edge <aEnew> Returns 0 in case of success", py::arg("aEold"), py::arg("aEnew"), py::arg("aF"), py::arg("aCtx"));
cls_BOPTools_AlgoTools2D.def_static("IsEdgeIsoline_", [](const TopoDS_Edge & theE, const TopoDS_Face & theF, Standard_Boolean & isTheUIso, Standard_Boolean & isTheVIso){ BOPTools_AlgoTools2D::IsEdgeIsoline(theE, theF, isTheUIso, isTheVIso); return std::tuple<Standard_Boolean &, Standard_Boolean &>(isTheUIso, isTheVIso); }, "Checks if CurveOnSurface of theE on theF matches with isoline of theF surface. Sets corresponding values for isTheUIso and isTheVIso variables. ATTENTION!!! This method is based on comparation between direction of surface (which theF is based on) iso-lines and the direction of the edge p-curve (on theF) in middle-point of the p-curve. This method should be used carefully (e.g. BRep_Tool::IsClosed(...) together) in order to avoid false classification some p-curves as isoline (e.g. circle on a plane).", py::arg("theE"), py::arg("theF"), py::arg("isTheUIso"), py::arg("isTheVIso"));

// CLASS: BOPTOOLS_ALGOTOOLS3D
py::class_<BOPTools_AlgoTools3D> cls_BOPTools_AlgoTools3D(mod, "BOPTools_AlgoTools3D", "The class contains handy static functions dealing with the topology This is the copy of BOPTools_AlgoTools3D.cdl file");

// Methods
// cls_BOPTools_AlgoTools3D.def_static("operator new_", (void * (*)(size_t)) &BOPTools_AlgoTools3D::operator new, "None", py::arg("theSize"));
// cls_BOPTools_AlgoTools3D.def_static("operator delete_", (void (*)(void *)) &BOPTools_AlgoTools3D::operator delete, "None", py::arg("theAddress"));
// cls_BOPTools_AlgoTools3D.def_static("operator new[]_", (void * (*)(size_t)) &BOPTools_AlgoTools3D::operator new[], "None", py::arg("theSize"));
// cls_BOPTools_AlgoTools3D.def_static("operator delete[]_", (void (*)(void *)) &BOPTools_AlgoTools3D::operator delete[], "None", py::arg("theAddress"));
// cls_BOPTools_AlgoTools3D.def_static("operator new_", (void * (*)(size_t, void *)) &BOPTools_AlgoTools3D::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPTools_AlgoTools3D.def_static("operator delete_", (void (*)(void *, void *)) &BOPTools_AlgoTools3D::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPTools_AlgoTools3D.def_static("DoSplitSEAMOnFace_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BOPTools_AlgoTools3D::DoSplitSEAMOnFace, "Make the edge <aSp> seam edge for the face <aF>", py::arg("aSp"), py::arg("aF"));
cls_BOPTools_AlgoTools3D.def_static("GetNormalToFaceOnEdge_", [](const TopoDS_Edge & a0, const TopoDS_Face & a1, const Standard_Real a2, gp_Dir & a3) -> void { return BOPTools_AlgoTools3D::GetNormalToFaceOnEdge(a0, a1, a2, a3); });
cls_BOPTools_AlgoTools3D.def_static("GetNormalToFaceOnEdge_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Dir &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::GetNormalToFaceOnEdge, "Computes normal to the face <aF> for the point on the edge <aE> at parameter <aT>. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("aD"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("GetNormalToFaceOnEdge_", [](const TopoDS_Edge & a0, const TopoDS_Face & a1, gp_Dir & a2) -> void { return BOPTools_AlgoTools3D::GetNormalToFaceOnEdge(a0, a1, a2); });
cls_BOPTools_AlgoTools3D.def_static("GetNormalToFaceOnEdge_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, gp_Dir &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::GetNormalToFaceOnEdge, "Computes normal to the face <aF> for the point on the edge <aE> at arbitrary intermediate parameter. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aD"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("SenseFlag_", (Standard_Integer (*)(const gp_Dir &, const gp_Dir &)) &BOPTools_AlgoTools3D::SenseFlag, "Returns 1 if scalar product aNF1* aNF2>0. Returns 0 if directions aNF1 aNF2 coincide Returns -1 if scalar product aNF1* aNF2<0.", py::arg("aNF1"), py::arg("aNF2"));
cls_BOPTools_AlgoTools3D.def_static("GetNormalToSurface_", (Standard_Boolean (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, gp_Dir &)) &BOPTools_AlgoTools3D::GetNormalToSurface, "Compute normal <aD> to surface <aS> in point (U,V) Returns TRUE if directions aD1U, aD1V coincide", py::arg("aS"), py::arg("U"), py::arg("V"), py::arg("aD"));
cls_BOPTools_AlgoTools3D.def_static("GetApproxNormalToFaceOnEdge_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Pnt &, gp_Dir &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::GetApproxNormalToFaceOnEdge, "Computes normal to the face <aF> for the 3D-point that belongs to the edge <aE> at parameter <aT>. Output: aPx - the 3D-point where the normal computed aD - the normal; Warning: The normal is computed not exactly in the point on the edge, but in point that is near to the edge towards to the face material (so, we'll have approx. normal); The point is computed using PointNearEdge function, with the shifting value BOPTools_AlgoTools3D::MinStepIn2d(), from the edge, but if this value is too big, the point will be computed using Hatcher (PointInFace function). Returns TRUE in case of success.", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("aPx"), py::arg("aD"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("GetApproxNormalToFaceOnEdge_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Pnt &, gp_Dir &, const Standard_Real)) &BOPTools_AlgoTools3D::GetApproxNormalToFaceOnEdge, "Computes normal to the face <aF> for the 3D-point that belongs to the edge <aE> at parameter <aT>. Output: aPx - the 3D-point where the normal computed aD - the normal; Warning: The normal is computed not exactly in the point on the edge, but in point that is near to the edge towards to the face material (so, we'll have approx. normal); The point is computed using PointNearEdge function with the shifting value <aDt2D> from the edge; No checks on this value will be done. Returns TRUE in case of success.", py::arg("theE"), py::arg("theF"), py::arg("aT"), py::arg("aP"), py::arg("aDNF"), py::arg("aDt2D"));
cls_BOPTools_AlgoTools3D.def_static("GetApproxNormalToFaceOnEdge_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Dir &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::GetApproxNormalToFaceOnEdge, "Computes normal to the face <aF> for the 3D-point that belongs to the edge <aE> at parameter <aT>. Output: aPx - the 3D-point where the normal computed aD - the normal; Warning: The normal is computed not exactly in the point on the edge, but in point that is near to the edge towards to the face material (so, we'll have approx. normal); The point is computed using PointNearEdge function with the shifting value <aDt2D> from the edge, but if this value is too big the point will be computed using Hatcher (PointInFace function). Returns TRUE in case of success.", py::arg("theE"), py::arg("theF"), py::arg("aT"), py::arg("aDt2D"), py::arg("aP"), py::arg("aDNF"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("PointNearEdge_", (Standard_Integer (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Real, gp_Pnt2d &, gp_Pnt &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::PointNearEdge, "Compute the point <aPx>, (<aP2D>) that is near to the edge <aE> at parameter <aT> towards to the material of the face <aF>. The value of shifting in 2D is <aDt2D> If the value of shifting is too big the point will be computed using Hatcher (PointInFace function). Returns error status: 0 - in case of success; 1 - <aE> does not have 2d curve on the face <aF>; 2 - the computed point is out of the face.", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("aDt2D"), py::arg("aP2D"), py::arg("aPx"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("PointNearEdge_", (Standard_Integer (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Real, gp_Pnt2d &, gp_Pnt &)) &BOPTools_AlgoTools3D::PointNearEdge, "Compute the point <aPx>, (<aP2D>) that is near to the edge <aE> at parameter <aT> towards to the material of the face <aF>. The value of shifting in 2D is <aDt2D>. No checks on this value will be done. Returns error status: 0 - in case of success; 1 - <aE> does not have 2d curve on the face <aF>.", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("aDt2D"), py::arg("aP2D"), py::arg("aPx"));
cls_BOPTools_AlgoTools3D.def_static("PointNearEdge_", (Standard_Integer (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Pnt2d &, gp_Pnt &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::PointNearEdge, "Computes the point <aPx>, (<aP2D>) that is near to the edge <aE> at parameter <aT> towards to the material of the face <aF>. The value of shifting in 2D is dt2D=BOPTools_AlgoTools3D::MinStepIn2d() If the value of shifting is too big the point will be computed using Hatcher (PointInFace function). Returns error status: 0 - in case of success; 1 - <aE> does not have 2d curve on the face <aF>; 2 - the computed point is out of the face.", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("aP2D"), py::arg("aPx"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("PointNearEdge_", (Standard_Integer (*)(const TopoDS_Edge &, const TopoDS_Face &, gp_Pnt2d &, gp_Pnt &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::PointNearEdge, "Compute the point <aPx>, (<aP2D>) that is near to the edge <aE> at arbitrary parameter towards to the material of the face <aF>. The value of shifting in 2D is dt2D=BOPTools_AlgoTools3D::MinStepIn2d(). If the value of shifting is too big the point will be computed using Hatcher (PointInFace function). Returns error status: 0 - in case of success; 1 - <aE> does not have 2d curve on the face <aF>; 2 - the computed point is out of the face.", py::arg("aE"), py::arg("aF"), py::arg("aP2D"), py::arg("aPx"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("MinStepIn2d_", (Standard_Real (*)()) &BOPTools_AlgoTools3D::MinStepIn2d, "Returns simple step value that is used in 2D-computations = 1.e-5");
cls_BOPTools_AlgoTools3D.def_static("IsEmptyShape_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BOPTools_AlgoTools3D::IsEmptyShape, "Returns TRUE if the shape <aS> does not contain geometry information (e.g. empty compound)", py::arg("aS"));
cls_BOPTools_AlgoTools3D.def_static("OrientEdgeOnFace_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, TopoDS_Edge &)) &BOPTools_AlgoTools3D::OrientEdgeOnFace, "Get the edge <aER> from the face <aF> that is the same as the edge <aE>", py::arg("aE"), py::arg("aF"), py::arg("aER"));
cls_BOPTools_AlgoTools3D.def_static("PointInFace_", (Standard_Integer (*)(const TopoDS_Face &, gp_Pnt &, gp_Pnt2d &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::PointInFace, "Computes arbitrary point <theP> inside the face <theF>. <theP2D> - 2D representation of <theP> on the surface of <theF> Returns 0 in case of success.", py::arg("theF"), py::arg("theP"), py::arg("theP2D"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("PointInFace_", (Standard_Integer (*)(const TopoDS_Face &, const TopoDS_Edge &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Pnt2d &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::PointInFace, "Computes a point <theP> inside the face <theF> using starting point taken by the parameter <theT> from the 2d curve of the edge <theE> on the face <theF> in the direction perpendicular to the tangent vector of the 2d curve of the edge. The point will be distanced on <theDt2D> from the 2d curve. <theP2D> - 2D representation of <theP> on the surface of <theF> Returns 0 in case of success.", py::arg("theF"), py::arg("theE"), py::arg("theT"), py::arg("theDt2D"), py::arg("theP"), py::arg("theP2D"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("PointInFace_", [](const TopoDS_Face & a0, const opencascade::handle<Geom2d_Curve> & a1, gp_Pnt & a2, gp_Pnt2d & a3, const opencascade::handle<IntTools_Context> & a4) -> Standard_Integer { return BOPTools_AlgoTools3D::PointInFace(a0, a1, a2, a3, a4); });
cls_BOPTools_AlgoTools3D.def_static("PointInFace_", (Standard_Integer (*)(const TopoDS_Face &, const opencascade::handle<Geom2d_Curve> &, gp_Pnt &, gp_Pnt2d &, const opencascade::handle<IntTools_Context> &, const Standard_Real)) &BOPTools_AlgoTools3D::PointInFace, "Computes a point <theP> inside the face <theF> using the line <theL> so that 2D point <theP2D>, 2D representation of <theP> on the surface of <theF>, lies on that line. Returns 0 in case of success.", py::arg("theF"), py::arg("theL"), py::arg("theP"), py::arg("theP2D"), py::arg("theContext"), py::arg("theDt2D"));

// TYPEDEF: BOPTOOLS_BOXBNDTREE
bind_NCollection_UBTree<int, Bnd_Box>(mod, "BOPTools_BoxBndTree", py::module_local(false));

// TYPEDEF: BOPTOOLS_BOXBNDTREESELECTOR
bind_BOPTools_BoxSelector<Bnd_Box>(mod, "BOPTools_BoxBndTreeSelector", py::module_local(false));

// CLASS: BOPTOOLS_SET
py::class_<BOPTools_Set> cls_BOPTools_Set(mod, "BOPTools_Set", "None");

// Constructors
cls_BOPTools_Set.def(py::init<>());
cls_BOPTools_Set.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPTools_Set.def_static("operator new_", (void * (*)(size_t)) &BOPTools_Set::operator new, "None", py::arg("theSize"));
// cls_BOPTools_Set.def_static("operator delete_", (void (*)(void *)) &BOPTools_Set::operator delete, "None", py::arg("theAddress"));
// cls_BOPTools_Set.def_static("operator new[]_", (void * (*)(size_t)) &BOPTools_Set::operator new[], "None", py::arg("theSize"));
// cls_BOPTools_Set.def_static("operator delete[]_", (void (*)(void *)) &BOPTools_Set::operator delete[], "None", py::arg("theAddress"));
// cls_BOPTools_Set.def_static("operator new_", (void * (*)(size_t, void *)) &BOPTools_Set::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPTools_Set.def_static("operator delete_", (void (*)(void *, void *)) &BOPTools_Set::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPTools_Set.def("Assign", (BOPTools_Set & (BOPTools_Set::*)(const BOPTools_Set &)) &BOPTools_Set::Assign, "None", py::arg("Other"));
// cls_BOPTools_Set.def("operator=", (BOPTools_Set & (BOPTools_Set::*)(const BOPTools_Set &)) &BOPTools_Set::operator=, "None", py::arg("Other"));
cls_BOPTools_Set.def("Shape", (const TopoDS_Shape & (BOPTools_Set::*)() const) &BOPTools_Set::Shape, "None");
cls_BOPTools_Set.def("Add", (void (BOPTools_Set::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &BOPTools_Set::Add, "None", py::arg("theS"), py::arg("theType"));
cls_BOPTools_Set.def("NbShapes", (Standard_Integer (BOPTools_Set::*)() const) &BOPTools_Set::NbShapes, "None");
cls_BOPTools_Set.def("IsEqual", (Standard_Boolean (BOPTools_Set::*)(const BOPTools_Set &) const) &BOPTools_Set::IsEqual, "None", py::arg("aOther"));
cls_BOPTools_Set.def("HashCode", (Standard_Integer (BOPTools_Set::*)(const Standard_Integer) const) &BOPTools_Set::HashCode, "None", py::arg("Upper"));

// CLASS: BOPTOOLS_SETMAPHASHER
py::class_<BOPTools_SetMapHasher> cls_BOPTools_SetMapHasher(mod, "BOPTools_SetMapHasher", "None");

// Methods
// cls_BOPTools_SetMapHasher.def_static("operator new_", (void * (*)(size_t)) &BOPTools_SetMapHasher::operator new, "None", py::arg("theSize"));
// cls_BOPTools_SetMapHasher.def_static("operator delete_", (void (*)(void *)) &BOPTools_SetMapHasher::operator delete, "None", py::arg("theAddress"));
// cls_BOPTools_SetMapHasher.def_static("operator new[]_", (void * (*)(size_t)) &BOPTools_SetMapHasher::operator new[], "None", py::arg("theSize"));
// cls_BOPTools_SetMapHasher.def_static("operator delete[]_", (void (*)(void *)) &BOPTools_SetMapHasher::operator delete[], "None", py::arg("theAddress"));
// cls_BOPTools_SetMapHasher.def_static("operator new_", (void * (*)(size_t, void *)) &BOPTools_SetMapHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPTools_SetMapHasher.def_static("operator delete_", (void (*)(void *, void *)) &BOPTools_SetMapHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPTools_SetMapHasher.def_static("HashCode_", (Standard_Integer (*)(const BOPTools_Set &, const Standard_Integer)) &BOPTools_SetMapHasher::HashCode, "None", py::arg("aSet"), py::arg("Upper"));
cls_BOPTools_SetMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const BOPTools_Set &, const BOPTools_Set &)) &BOPTools_SetMapHasher::IsEqual, "None", py::arg("aSet1"), py::arg("aSet2"));

// TYPEDEF: BOPTOOLS_INDEXEDDATAMAPOFSETSHAPE
bind_NCollection_IndexedDataMap<BOPTools_Set, TopoDS_Shape, BOPTools_SetMapHasher>(mod, "BOPTools_IndexedDataMapOfSetShape", py::module_local(false));

// TYPEDEF: BOPTOOLS_MAPOFSET
bind_NCollection_Map<BOPTools_Set, BOPTools_SetMapHasher>(mod, "BOPTools_MapOfSet", py::module_local(false));

// TYPEDEF: BOPTOOLS_MAPITERATOROFMAPOFSET


}
