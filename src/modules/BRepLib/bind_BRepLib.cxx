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
#include <Standard_Handle.hxx>
#include <Geom_Plane.hxx>
#include <TopoDS_Edge.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <Geom2d_Curve.hxx>
#include <BRepLib.hxx>
#include <BRepTools_ReShape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopTools_ListOfShape.hxx>
#include <NCollection_List.hxx>
#include <gp_Pnt.hxx>
#include <Adaptor3d_Curve.hxx>
#include <BRepLib_Command.hxx>
#include <BRepLib_MakeShape.hxx>
#include <BRepLib_MakeVertex.hxx>
#include <BRepLib_MakeEdge.hxx>
#include <BRepLib_MakeEdge2d.hxx>
#include <BRepLib_MakePolygon.hxx>
#include <BRepLib_MakeFace.hxx>
#include <BRepLib_MakeWire.hxx>
#include <BRepLib_MakeShell.hxx>
#include <BRepLib_MakeSolid.hxx>
#include <BRepLib_FindSurface.hxx>
#include <BRepLib_FuseEdges.hxx>
#include <BRepLib_CheckCurveOnSurface.hxx>

void bind_BRepLib(py::module &mod){

py::class_<BRepLib> cls_BRepLib(mod, "BRepLib", "The BRepLib package provides general utilities for BRep.");

// Constructors

// Fields

// Methods
// cls_BRepLib.def_static("operator new_", (void * (*)(size_t)) &BRepLib::operator new, "None", py::arg("theSize"));
// cls_BRepLib.def_static("operator delete_", (void (*)(void *)) &BRepLib::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib::operator new[], "None", py::arg("theSize"));
// cls_BRepLib.def_static("operator delete[]_", (void (*)(void *)) &BRepLib::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib.def_static("Precision_", (void (*)(const Standard_Real)) &BRepLib::Precision, "Computes the max distance between edge and its 2d representation on the face. Sets the default precision. The current Precision is returned.", py::arg("P"));
cls_BRepLib.def_static("Precision_", (Standard_Real (*)()) &BRepLib::Precision, "Returns the default precision.");
cls_BRepLib.def_static("Plane_", (void (*)(const opencascade::handle<Geom_Plane> &)) &BRepLib::Plane, "Sets the current plane to P.", py::arg("P"));
cls_BRepLib.def_static("Plane_", (const opencascade::handle<Geom_Plane> & (*)()) &BRepLib::Plane, "Returns the current plane.");
cls_BRepLib.def_static("CheckSameRange_", [](const TopoDS_Edge & a0) -> Standard_Boolean { return BRepLib::CheckSameRange(a0); });
cls_BRepLib.def_static("CheckSameRange_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real)) &BRepLib::CheckSameRange, "checks if the Edge is same range IGNORING the same range flag of the edge Confusion argument is to compare real numbers idenpendently of any model space tolerance", py::arg("E"), py::arg("Confusion"));
cls_BRepLib.def_static("SameRange_", [](const TopoDS_Edge & a0) -> void { return BRepLib::SameRange(a0); });
cls_BRepLib.def_static("SameRange_", (void (*)(const TopoDS_Edge &, const Standard_Real)) &BRepLib::SameRange, "will make all the curve representation have the same range domain for the parameters. This will IGNORE the same range flag value to proceed. If there is a 3D curve there it will the range of that curve. If not the first curve representation encountered in the list will give its range to the all the other curves.", py::arg("E"), py::arg("Tolerance"));
cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0); });
cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0, const Standard_Real a1) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0, a1); });
cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0, const Standard_Real a1, const GeomAbs_Shape a2) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0, a1, a2); });
cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0, const Standard_Real a1, const GeomAbs_Shape a2, const Standard_Integer a3) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0, a1, a2, a3); });
cls_BRepLib.def_static("BuildCurve3d_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &BRepLib::BuildCurve3d, "Computes the 3d curve for the edge <E> if it does not exist. Returns True if the curve was computed or existed. Returns False if there is no planar pcurve or the computation failed. <MaxSegment> >= 30 in approximation", py::arg("E"), py::arg("Tolerance"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegment"));
cls_BRepLib.def_static("BuildCurves3d_", [](const TopoDS_Shape & a0, const Standard_Real a1) -> Standard_Boolean { return BRepLib::BuildCurves3d(a0, a1); });
cls_BRepLib.def_static("BuildCurves3d_", [](const TopoDS_Shape & a0, const Standard_Real a1, const GeomAbs_Shape a2) -> Standard_Boolean { return BRepLib::BuildCurves3d(a0, a1, a2); });
cls_BRepLib.def_static("BuildCurves3d_", [](const TopoDS_Shape & a0, const Standard_Real a1, const GeomAbs_Shape a2, const Standard_Integer a3) -> Standard_Boolean { return BRepLib::BuildCurves3d(a0, a1, a2, a3); });
cls_BRepLib.def_static("BuildCurves3d_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &BRepLib::BuildCurves3d, "Computes the 3d curves for all the edges of <S> return False if one of the computation failed. <MaxSegment> >= 30 in approximation", py::arg("S"), py::arg("Tolerance"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegment"));
cls_BRepLib.def_static("BuildCurves3d_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BRepLib::BuildCurves3d, "Computes the 3d curves for all the edges of <S> return False if one of the computation failed.", py::arg("S"));
cls_BRepLib.def_static("BuildPCurveForEdgeOnPlane_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepLib::BuildPCurveForEdgeOnPlane, "Builds pcurve of edge on face if the surface is plane, and updates the edge.", py::arg("theE"), py::arg("theF"));
cls_BRepLib.def_static("BuildPCurveForEdgeOnPlane_", [](const TopoDS_Edge & theE, const TopoDS_Face & theF, opencascade::handle<Geom2d_Curve> & aC2D, Standard_Boolean & bToUpdate){ BRepLib::BuildPCurveForEdgeOnPlane(theE, theF, aC2D, bToUpdate); return bToUpdate; }, "Builds pcurve of edge on face if the surface is plane, but does not update the edge. The output are the pcurve and the flag telling that pcurve was built.", py::arg("theE"), py::arg("theF"), py::arg("aC2D"), py::arg("bToUpdate"));
cls_BRepLib.def_static("UpdateEdgeTol_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &BRepLib::UpdateEdgeTol, "Checks if the edge has a Tolerance smaller than -- -- -- -- MaxToleranceToCheck if so it will compute the radius of -- the cylindrical pipe surface that MinToleranceRequest is the minimum tolerance before it is usefull to start testing. Usually it should be arround 10e-5 contains all -- the curve represenation of the edge returns True if the Edge tolerance had to be updated", py::arg("E"), py::arg("MinToleranceRequest"), py::arg("MaxToleranceToCheck"));
cls_BRepLib.def_static("UpdateEdgeTolerance_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real)) &BRepLib::UpdateEdgeTolerance, "-- Checks all the edges of the shape whose -- -- -- Tolerance is smaller than MaxToleranceToCheck -- Returns True if at least one edge was updated -- MinToleranceRequest is the minimum tolerance before -- it -- is usefull to start testing. Usually it should be arround -- 10e-5--", py::arg("S"), py::arg("MinToleranceRequest"), py::arg("MaxToleranceToCheck"));
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Edge & a0) -> void { return BRepLib::SameParameter(a0); });
cls_BRepLib.def_static("SameParameter_", (void (*)(const TopoDS_Edge &, const Standard_Real)) &BRepLib::SameParameter, "Computes new 2d curve(s) for the edge <theEdge> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on the Edge.", py::arg("theEdge"), py::arg("Tolerance"));
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Edge & theEdge, const Standard_Real theTolerance, Standard_Real & theNewTol, const Standard_Boolean IsUseOldEdge){ TopoDS_Edge rv = BRepLib::SameParameter(theEdge, theTolerance, theNewTol, IsUseOldEdge); return std::tuple<TopoDS_Edge, Standard_Real &>(rv, theNewTol); }, "Computes new 2d curve(s) for the edge <theEdge> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on the Edge. theNewTol is a new tolerance of vertices of the input edge (not applied inside the algorithm, but pre-computed). If IsUseOldEdge is true then the input edge will be modified, otherwise the new copy of input edge will be created. Returns the new edge as a result, can be ignored if IsUseOldEdge is true.", py::arg("theEdge"), py::arg("theTolerance"), py::arg("theNewTol"), py::arg("IsUseOldEdge"));
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0) -> void { return BRepLib::SameParameter(a0); });
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0, const Standard_Real a1) -> void { return BRepLib::SameParameter(a0, a1); });
cls_BRepLib.def_static("SameParameter_", (void (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Boolean)) &BRepLib::SameParameter, "Computes new 2d curve(s) for all the edges of <S> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on an Edge.", py::arg("S"), py::arg("Tolerance"), py::arg("forced"));
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0, BRepTools_ReShape & a1) -> void { return BRepLib::SameParameter(a0, a1); });
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0, BRepTools_ReShape & a1, const Standard_Real a2) -> void { return BRepLib::SameParameter(a0, a1, a2); });
cls_BRepLib.def_static("SameParameter_", (void (*)(const TopoDS_Shape &, BRepTools_ReShape &, const Standard_Real, const Standard_Boolean)) &BRepLib::SameParameter, "Computes new 2d curve(s) for all the edges of <S> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on an Edge. theReshaper is used to record the modifications of input shape <S> to prevent any modifications on the shape itself. Thus the input shape (and its subshapes) will not be modified, instead the reshaper will contain a modified empty-copies of original subshapes as substitutions.", py::arg("S"), py::arg("theReshaper"), py::arg("Tolerance"), py::arg("forced"));
cls_BRepLib.def_static("UpdateTolerances_", [](const TopoDS_Shape & a0) -> void { return BRepLib::UpdateTolerances(a0); });
cls_BRepLib.def_static("UpdateTolerances_", (void (*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepLib::UpdateTolerances, "Replaces tolerance of FACE EDGE VERTEX by the tolerance Max of their connected handling shapes. It is not necessary to use this call after SameParameter. (called in)", py::arg("S"), py::arg("verifyFaceTolerance"));
cls_BRepLib.def_static("UpdateTolerances_", [](const TopoDS_Shape & a0, BRepTools_ReShape & a1) -> void { return BRepLib::UpdateTolerances(a0, a1); });
cls_BRepLib.def_static("UpdateTolerances_", (void (*)(const TopoDS_Shape &, BRepTools_ReShape &, const Standard_Boolean)) &BRepLib::UpdateTolerances, "Replaces tolerance of FACE EDGE VERTEX by the tolerance Max of their connected handling shapes. It is not necessary to use this call after SameParameter. (called in) theReshaper is used to record the modifications of input shape <S> to prevent any modifications on the shape itself. Thus the input shape (and its subshapes) will not be modified, instead the reshaper will contain a modified empty-copies of original subshapes as substitutions.", py::arg("S"), py::arg("theReshaper"), py::arg("verifyFaceTolerance"));
cls_BRepLib.def_static("UpdateInnerTolerances_", (void (*)(const TopoDS_Shape &)) &BRepLib::UpdateInnerTolerances, "Checks tolerances of edges (including inner points) and vertices of a shape and updates them to satisfy 'SameParameter' condition", py::arg("S"));
cls_BRepLib.def_static("OrientClosedSolid_", (Standard_Boolean (*)(TopoDS_Solid &)) &BRepLib::OrientClosedSolid, "Orients the solid forward and the shell with the orientation to have matter in the solid. Returns False if the solid is unOrientable (open or incoherent)", py::arg("solid"));
cls_BRepLib.def_static("EncodeRegularity_", [](const TopoDS_Shape & a0) -> void { return BRepLib::EncodeRegularity(a0); });
cls_BRepLib.def_static("EncodeRegularity_", (void (*)(const TopoDS_Shape &, const Standard_Real)) &BRepLib::EncodeRegularity, "Encodes the Regularity of edges on a Shape. Warning: <TolAng> is an angular tolerance, expressed in Rad. Warning: If the edges's regularity are coded before, nothing is done.", py::arg("S"), py::arg("TolAng"));
cls_BRepLib.def_static("EncodeRegularity_", [](const TopoDS_Shape & a0, const TopTools_ListOfShape & a1) -> void { return BRepLib::EncodeRegularity(a0, a1); });
cls_BRepLib.def_static("EncodeRegularity_", (void (*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real)) &BRepLib::EncodeRegularity, "Encodes the Regularity of edges in list <LE> on the shape <S> Warning: <TolAng> is an angular tolerance, expressed in Rad. Warning: If the edges's regularity are coded before, nothing is done.", py::arg("S"), py::arg("LE"), py::arg("TolAng"));
cls_BRepLib.def_static("EncodeRegularity_", [](TopoDS_Edge & a0, const TopoDS_Face & a1, const TopoDS_Face & a2) -> void { return BRepLib::EncodeRegularity(a0, a1, a2); });
cls_BRepLib.def_static("EncodeRegularity_", (void (*)(TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real)) &BRepLib::EncodeRegularity, "Encodes the Regularity beetween <F1> and <F2> by <E> Warning: <TolAng> is an angular tolerance, expressed in Rad. Warning: If the edge's regularity is coded before, nothing is done.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("TolAng"));
cls_BRepLib.def_static("SortFaces_", (void (*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepLib::SortFaces, "Sorts in LF the Faces of S on the complexity of their surfaces (Plane,Cylinder,Cone,Sphere,Torus,other)", py::arg("S"), py::arg("LF"));
cls_BRepLib.def_static("ReverseSortFaces_", (void (*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepLib::ReverseSortFaces, "Sorts in LF the Faces of S on the reverse complexity of their surfaces (other,Torus,Sphere,Cone,Cylinder,Plane)", py::arg("S"), py::arg("LF"));
cls_BRepLib.def_static("EnsureNormalConsistency_", [](const TopoDS_Shape & a0) -> Standard_Boolean { return BRepLib::EnsureNormalConsistency(a0); });
cls_BRepLib.def_static("EnsureNormalConsistency_", [](const TopoDS_Shape & a0, const Standard_Real a1) -> Standard_Boolean { return BRepLib::EnsureNormalConsistency(a0, a1); });
cls_BRepLib.def_static("EnsureNormalConsistency_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Boolean)) &BRepLib::EnsureNormalConsistency, "Corrects the normals in Poly_Triangulation of faces, in such way that normals at nodes lying along smooth edges have the same value on both adjacent triangulations. Returns TRUE if any correction is done.", py::arg("S"), py::arg("theAngTol"), py::arg("ForceComputeNormals"));
cls_BRepLib.def_static("BoundingVertex_", [](const NCollection_List<TopoDS_Shape> & theLV, gp_Pnt & theNewCenter, Standard_Real & theNewTol){ BRepLib::BoundingVertex(theLV, theNewCenter, theNewTol); return theNewTol; }, "Calculates the bounding sphere around the set of vertexes from the theLV list. Returns the center (theNewCenter) and the radius (theNewTol) of this sphere. This can be used to construct the new vertex which covers the given set of other vertices.", py::arg("theLV"), py::arg("theNewCenter"), py::arg("theNewTol"));
cls_BRepLib.def_static("FindValidRange_", [](const Adaptor3d_Curve & theCurve, const Standard_Real theTolE, const Standard_Real theParV1, const gp_Pnt & thePntV1, const Standard_Real theTolV1, const Standard_Real theParV2, const gp_Pnt & thePntV2, const Standard_Real theTolV2, Standard_Real & theFirst, Standard_Real & theLast){ Standard_Boolean rv = BRepLib::FindValidRange(theCurve, theTolE, theParV1, thePntV1, theTolV1, theParV2, thePntV2, theTolV2, theFirst, theLast); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theFirst, theLast); }, "For an edge defined by 3d curve and tolerance and vertices defined by points, parameters on curve and tolerances, finds a range of curve between vertices not covered by vertices tolerances. Returns false if there is no such range. Otherwise, sets theFirst and theLast as its bounds.", py::arg("theCurve"), py::arg("theTolE"), py::arg("theParV1"), py::arg("thePntV1"), py::arg("theTolV1"), py::arg("theParV2"), py::arg("thePntV2"), py::arg("theTolV2"), py::arg("theFirst"), py::arg("theLast"));
cls_BRepLib.def_static("FindValidRange_", [](const TopoDS_Edge & theEdge, Standard_Real & theFirst, Standard_Real & theLast){ Standard_Boolean rv = BRepLib::FindValidRange(theEdge, theFirst, theLast); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theFirst, theLast); }, "Finds a range of 3d curve of the edge not covered by vertices tolerances. Returns false if there is no such range. Otherwise, sets theFirst and theLast as its bounds.", py::arg("theEdge"), py::arg("theFirst"), py::arg("theLast"));
cls_BRepLib.def_static("ExtendFace_", (void (*)(const TopoDS_Face &, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, TopoDS_Face &)) &BRepLib::ExtendFace, "Enlarges the face on the given value.", py::arg("theF"), py::arg("theExtVal"), py::arg("theExtUMin"), py::arg("theExtUMax"), py::arg("theExtVMin"), py::arg("theExtVMax"), py::arg("theFExtended"));

// Enums

}