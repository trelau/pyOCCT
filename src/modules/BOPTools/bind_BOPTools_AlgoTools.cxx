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
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <Precision.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <IntTools_Curve.hxx>
#include <TopAbs_State.hxx>
#include <TopoDS_Solid.hxx>
#include <Standard_Handle.hxx>
#include <IntTools_Context.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <BOPTools_ListOfCoupleOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <Message_Report.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_ListOfListOfShape.hxx>
#include <BOPTools_ListOfConnexityBlock.hxx>
#include <IntTools_Range.hxx>
#include <TopoDS_Shell.hxx>
#include <BOPTools_AlgoTools.hxx>

void bind_BOPTools_AlgoTools(py::module &mod){

py::class_<BOPTools_AlgoTools, std::unique_ptr<BOPTools_AlgoTools>> cls_BOPTools_AlgoTools(mod, "BOPTools_AlgoTools", "Provides tools used in Boolean Operations algorithm: - Vertices intersection; - Vertex construction; - Edge construction; - Classification algorithms; - Making connexity blocks; - Shape validation.");

// Constructors

// Fields

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

// Enums

}