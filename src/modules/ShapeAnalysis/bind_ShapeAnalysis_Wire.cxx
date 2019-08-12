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
#include <Standard_Transient.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeExtend_WireData.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <ShapeAnalysis_Surface.hxx>
#include <ShapeAnalysis_WireOrder.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <IntRes2d_SequenceOfIntersectionPoint.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeAnalysis_Wire.hxx>
#include <Standard_Type.hxx>

void bind_ShapeAnalysis_Wire(py::module &mod){

py::class_<ShapeAnalysis_Wire, opencascade::handle<ShapeAnalysis_Wire>, Standard_Transient> cls_ShapeAnalysis_Wire(mod, "ShapeAnalysis_Wire", "This class provides analysis of a wire to be compliant to CAS.CADE requirements.");

// Constructors
cls_ShapeAnalysis_Wire.def(py::init<>());
cls_ShapeAnalysis_Wire.def(py::init<const TopoDS_Wire &, const TopoDS_Face &, const Standard_Real>(), py::arg("wire"), py::arg("face"), py::arg("precision"));
cls_ShapeAnalysis_Wire.def(py::init<const opencascade::handle<ShapeExtend_WireData> &, const TopoDS_Face &, const Standard_Real>(), py::arg("sbwd"), py::arg("face"), py::arg("precision"));

// Fields

// Methods
cls_ShapeAnalysis_Wire.def("Init", (void (ShapeAnalysis_Wire::*)(const TopoDS_Wire &, const TopoDS_Face &, const Standard_Real)) &ShapeAnalysis_Wire::Init, "Initializes the object with standard TopoDS_Wire, face and precision", py::arg("wire"), py::arg("face"), py::arg("precision"));
cls_ShapeAnalysis_Wire.def("Init", (void (ShapeAnalysis_Wire::*)(const opencascade::handle<ShapeExtend_WireData> &, const TopoDS_Face &, const Standard_Real)) &ShapeAnalysis_Wire::Init, "Initializes the object with WireData object, face and precision", py::arg("sbwd"), py::arg("face"), py::arg("precision"));
cls_ShapeAnalysis_Wire.def("Load", (void (ShapeAnalysis_Wire::*)(const TopoDS_Wire &)) &ShapeAnalysis_Wire::Load, "Loads the object with standard TopoDS_Wire", py::arg("wire"));
cls_ShapeAnalysis_Wire.def("Load", (void (ShapeAnalysis_Wire::*)(const opencascade::handle<ShapeExtend_WireData> &)) &ShapeAnalysis_Wire::Load, "Loads the object with WireData object", py::arg("sbwd"));
cls_ShapeAnalysis_Wire.def("SetFace", (void (ShapeAnalysis_Wire::*)(const TopoDS_Face &)) &ShapeAnalysis_Wire::SetFace, "Loads the face the wire lies on", py::arg("face"));
cls_ShapeAnalysis_Wire.def("SetSurface", (void (ShapeAnalysis_Wire::*)(const opencascade::handle<Geom_Surface> &)) &ShapeAnalysis_Wire::SetSurface, "Loads the surface the wire lies on", py::arg("surface"));
cls_ShapeAnalysis_Wire.def("SetSurface", (void (ShapeAnalysis_Wire::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &ShapeAnalysis_Wire::SetSurface, "Loads the surface the wire lies on", py::arg("surface"), py::arg("location"));
cls_ShapeAnalysis_Wire.def("SetPrecision", (void (ShapeAnalysis_Wire::*)(const Standard_Real)) &ShapeAnalysis_Wire::SetPrecision, "None", py::arg("precision"));
cls_ShapeAnalysis_Wire.def("ClearStatuses", (void (ShapeAnalysis_Wire::*)()) &ShapeAnalysis_Wire::ClearStatuses, "Unsets all the status and distance fields wire, face and precision are not cleared");
cls_ShapeAnalysis_Wire.def("IsLoaded", (Standard_Boolean (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::IsLoaded, "Returns True if wire is loaded and has number of edges >0");
cls_ShapeAnalysis_Wire.def("IsReady", (Standard_Boolean (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::IsReady, "Returns True if IsLoaded and underlying face is not null");
cls_ShapeAnalysis_Wire.def("Precision", (Standard_Real (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::Precision, "Returns the value of precision");
cls_ShapeAnalysis_Wire.def("WireData", (const opencascade::handle<ShapeExtend_WireData> & (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::WireData, "Returns wire object being analyzed");
cls_ShapeAnalysis_Wire.def("NbEdges", (Standard_Integer (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::NbEdges, "Returns the number of edges in the wire, or 0 if it is not loaded");
cls_ShapeAnalysis_Wire.def("Face", (const TopoDS_Face & (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::Face, "Returns the working face");
cls_ShapeAnalysis_Wire.def("Surface", (const opencascade::handle<ShapeAnalysis_Surface> & (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::Surface, "Returns the working surface");
cls_ShapeAnalysis_Wire.def("Perform", (Standard_Boolean (ShapeAnalysis_Wire::*)()) &ShapeAnalysis_Wire::Perform, "Performs all the checks in the following order : CheckOrder, CheckSmall, CheckConected, CheckEdgeCurves, CheckDegenerated, CheckSelfIntersection, CheckLacking, CheckClosed Returns: True if at least one method returned True; For deeper analysis use Status...(status) methods");
cls_ShapeAnalysis_Wire.def("CheckOrder", [](ShapeAnalysis_Wire &self) -> Standard_Boolean { return self.CheckOrder(); });
cls_ShapeAnalysis_Wire.def("CheckOrder", [](ShapeAnalysis_Wire &self, const Standard_Boolean a0) -> Standard_Boolean { return self.CheckOrder(a0); });
cls_ShapeAnalysis_Wire.def("CheckOrder", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Boolean, const Standard_Boolean)) &ShapeAnalysis_Wire::CheckOrder, "Calls CheckOrder and returns False if wire is already ordered (tail-to-head), True otherwise Flag <isClosed> defines if the wire is closed or not Flag <mode3d> defines which mode is used (3d or 2d)", py::arg("isClosed"), py::arg("mode3d"));
cls_ShapeAnalysis_Wire.def("CheckConnected", [](ShapeAnalysis_Wire &self) -> Standard_Boolean { return self.CheckConnected(); });
cls_ShapeAnalysis_Wire.def("CheckConnected", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Real)) &ShapeAnalysis_Wire::CheckConnected, "Calls to CheckConnected for each edge Returns: True if at least one pair of disconnected edges (not sharing the same vertex) was detected", py::arg("prec"));
cls_ShapeAnalysis_Wire.def("CheckSmall", [](ShapeAnalysis_Wire &self) -> Standard_Boolean { return self.CheckSmall(); });
cls_ShapeAnalysis_Wire.def("CheckSmall", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Real)) &ShapeAnalysis_Wire::CheckSmall, "Calls to CheckSmall for each edge Returns: True if at least one small edge was detected", py::arg("precsmall"));
cls_ShapeAnalysis_Wire.def("CheckEdgeCurves", (Standard_Boolean (ShapeAnalysis_Wire::*)()) &ShapeAnalysis_Wire::CheckEdgeCurves, "Checks edges geometry (consitency of 2d and 3d senses, adjasment of curves to the vertices, etc.). The order of the checks : Call ShapeAnalysis_Wire to check: ShapeAnalysis_Edge::CheckCurve3dWithPCurve (1), ShapeAnalysis_Edge::CheckVertcesWithPCurve (2), ShapeAnalysis_Edge::CheckVertcesWithCurve3d (3), CheckSeam (4) Additional: CheckGap3d (5), CheckGap2d (6), ShapeAnalysis_Edge::CheckSameParameter (7) Returns: True if at least one check returned True Remark: The numbers in brackets show with what DONEi or FAILi the status can be queried");
cls_ShapeAnalysis_Wire.def("CheckDegenerated", (Standard_Boolean (ShapeAnalysis_Wire::*)()) &ShapeAnalysis_Wire::CheckDegenerated, "Calls to CheckDegenerated for each edge Returns: True if at least one incorrect degenerated edge was detected");
cls_ShapeAnalysis_Wire.def("CheckClosed", [](ShapeAnalysis_Wire &self) -> Standard_Boolean { return self.CheckClosed(); });
cls_ShapeAnalysis_Wire.def("CheckClosed", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Real)) &ShapeAnalysis_Wire::CheckClosed, "Checks if wire is closed, performs CheckConnected, CheckDegenerated and CheckLacking for the first and the last edges Returns: True if at least one check returned True Status: FAIL1 or DONE1: see CheckConnected FAIL2 or DONE2: see CheckDegenerated", py::arg("prec"));
cls_ShapeAnalysis_Wire.def("CheckSelfIntersection", (Standard_Boolean (ShapeAnalysis_Wire::*)()) &ShapeAnalysis_Wire::CheckSelfIntersection, "Checks self-intersection of the wire (considering pcurves) Looks for self-intersecting edges and each pair of intersecting edges. Warning: It does not check each edge with any other one (only each two adjacent edges) The order of the checks : CheckSelfIntersectingEdge, CheckIntersectingEdges Returns: True if at least one check returned True Status: FAIL1 or DONE1 - see CheckSelfIntersectingEdge FAIL2 or DONE2 - see CheckIntersectingEdges");
cls_ShapeAnalysis_Wire.def("CheckLacking", (Standard_Boolean (ShapeAnalysis_Wire::*)()) &ShapeAnalysis_Wire::CheckLacking, "Calls to CheckLacking for each edge Returns: True if at least one lacking edge was detected");
cls_ShapeAnalysis_Wire.def("CheckGaps3d", (Standard_Boolean (ShapeAnalysis_Wire::*)()) &ShapeAnalysis_Wire::CheckGaps3d, "None");
cls_ShapeAnalysis_Wire.def("CheckGaps2d", (Standard_Boolean (ShapeAnalysis_Wire::*)()) &ShapeAnalysis_Wire::CheckGaps2d, "None");
cls_ShapeAnalysis_Wire.def("CheckCurveGaps", (Standard_Boolean (ShapeAnalysis_Wire::*)()) &ShapeAnalysis_Wire::CheckCurveGaps, "None");
cls_ShapeAnalysis_Wire.def("CheckOrder", [](ShapeAnalysis_Wire &self, ShapeAnalysis_WireOrder & a0) -> Standard_Boolean { return self.CheckOrder(a0); });
cls_ShapeAnalysis_Wire.def("CheckOrder", [](ShapeAnalysis_Wire &self, ShapeAnalysis_WireOrder & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.CheckOrder(a0, a1); });
cls_ShapeAnalysis_Wire.def("CheckOrder", (Standard_Boolean (ShapeAnalysis_Wire::*)(ShapeAnalysis_WireOrder &, const Standard_Boolean, const Standard_Boolean)) &ShapeAnalysis_Wire::CheckOrder, "Analyzes the order of the edges in the wire, uses class WireOrder for that purpose. Flag <isClosed> defines if the wire is closed or not Flag <mode3d> defines which mode is used (3d or 2d) Returns False if wire is already ordered (tail-to-head), True otherwise. Use returned WireOrder object for deeper analysis. Status: OK : the same edges orientation, the same edges sequence DONE1: the same edges orientation, not the same edges sequence DONE2: as DONE1 and gaps more than myPrecision DONE3: not the same edges orientation (some need to be reversed) DONE4: as DONE3 and gaps more than myPrecision FAIL : algorithm failed (could not detect order)", py::arg("sawo"), py::arg("isClosed"), py::arg("mode3d"));
cls_ShapeAnalysis_Wire.def("CheckConnected", [](ShapeAnalysis_Wire &self, const Standard_Integer a0) -> Standard_Boolean { return self.CheckConnected(a0); });
cls_ShapeAnalysis_Wire.def("CheckConnected", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer, const Standard_Real)) &ShapeAnalysis_Wire::CheckConnected, "Checks connected edges (num-th and preceeding). Tests with starting preci from <SBWD> or with <prec> if it is greater. Considers Vertices. Returns: False if edges are connected by the common vertex, else True Status : OK : Vertices (end of num-1 th edge and start on num-th one) are already the same DONE1 : Absolutely confused (gp::Resolution) DONE2 : Confused at starting <preci> from <SBWD> DONE3 : Confused at <prec> but not <preci> FAIL1 : Not confused FAIL2 : Not confused but confused with <preci> if reverse num-th edge", py::arg("num"), py::arg("prec"));
cls_ShapeAnalysis_Wire.def("CheckSmall", [](ShapeAnalysis_Wire &self, const Standard_Integer a0) -> Standard_Boolean { return self.CheckSmall(a0); });
cls_ShapeAnalysis_Wire.def("CheckSmall", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer, const Standard_Real)) &ShapeAnalysis_Wire::CheckSmall, "Checks if an edge has a length not greater than myPreci or precsmall (if it is smaller) Returns: False if its length is greater than precision Status: OK : edge is not small or degenerated DONE1: edge is small, vertices are the same DONE2: edge is small, vertices are not the same FAIL : no 3d curve and pcurve", py::arg("num"), py::arg("precsmall"));
cls_ShapeAnalysis_Wire.def("CheckSeam", [](ShapeAnalysis_Wire &self, const Standard_Integer num, opencascade::handle<Geom2d_Curve> & C1, opencascade::handle<Geom2d_Curve> & C2, Standard_Real & cf, Standard_Real & cl){ Standard_Boolean rv = self.CheckSeam(num, C1, C2, cf, cl); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, cf, cl); }, "Checks if a seam pcurves are correct oriented Returns: False (status OK) if given edge is not a seam or if it is OK C1 - current pcurve for FORWARD edge, C2 - current pcurve for REVERSED edge (if returns True they should be swapped for the seam), cf, cl - first and last parameters on curves Status: OK : Pcurves are correct or edge is not seam DONE : Seam pcurves should be swapped", py::arg("num"), py::arg("C1"), py::arg("C2"), py::arg("cf"), py::arg("cl"));
cls_ShapeAnalysis_Wire.def("CheckSeam", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer)) &ShapeAnalysis_Wire::CheckSeam, "Checks if a seam pcurves are correct oriented See previous functions for details", py::arg("num"));
cls_ShapeAnalysis_Wire.def("CheckDegenerated", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt2d &)) &ShapeAnalysis_Wire::CheckDegenerated, "Checks for degenerated edge between two adjacent ones. Fills parameters dgnr1 and dgnr2 with points in paramterical space that correspond to the singularity (either gap that needs to be filled by degenerated edge or that already filled) Returns: False if no singularity or edge is already degenerated, otherwise True Status: OK : No surface singularity, or edge is already degenerated DONE1: Degenerated edge should be inserted (gap in 2D) DONE2: Edge <num> should be made degenerated (recompute pcurve and set the flag) FAIL1: One of edges neighbouring to degenerated one has no pcurve FAIL2: Edge marked as degenerated and has no pcurve but singularity is not detected", py::arg("num"), py::arg("dgnr1"), py::arg("dgnr2"));
cls_ShapeAnalysis_Wire.def("CheckDegenerated", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer)) &ShapeAnalysis_Wire::CheckDegenerated, "Checks for degenerated edge between two adjacent ones. Remark : Calls previous function Status : See the function above for details", py::arg("num"));
cls_ShapeAnalysis_Wire.def("CheckGap3d", [](ShapeAnalysis_Wire &self) -> Standard_Boolean { return self.CheckGap3d(); });
cls_ShapeAnalysis_Wire.def("CheckGap3d", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer)) &ShapeAnalysis_Wire::CheckGap3d, "Checks gap between edges in 3D (3d curves). Checks the distance between ends of 3d curves of the num-th and preceeding edge. The distance can be queried by MinDistance3d.", py::arg("num"));
cls_ShapeAnalysis_Wire.def("CheckGap2d", [](ShapeAnalysis_Wire &self) -> Standard_Boolean { return self.CheckGap2d(); });
cls_ShapeAnalysis_Wire.def("CheckGap2d", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer)) &ShapeAnalysis_Wire::CheckGap2d, "Checks gap between edges in 2D (pcurves). Checks the distance between ends of pcurves of the num-th and preceeding edge. The distance can be queried by MinDistance2d.", py::arg("num"));
cls_ShapeAnalysis_Wire.def("CheckCurveGap", [](ShapeAnalysis_Wire &self) -> Standard_Boolean { return self.CheckCurveGap(); });
cls_ShapeAnalysis_Wire.def("CheckCurveGap", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer)) &ShapeAnalysis_Wire::CheckCurveGap, "Checks gap between points on 3D curve and points on surface generated by pcurve of the num-th edge. The distance can be queried by MinDistance3d.", py::arg("num"));
cls_ShapeAnalysis_Wire.def("CheckSelfIntersectingEdge", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer, IntRes2d_SequenceOfIntersectionPoint &, TColgp_SequenceOfPnt &)) &ShapeAnalysis_Wire::CheckSelfIntersectingEdge, "Checks if num-th edge is self-intersecting. Self-intersection is reported only if intersection point lies outside of both end vertices of the edge. Returns: True if edge is self-intersecting. If returns True it also fills the sequences of intersection points and corresponding 3d points (only that are not enclosed by a vertices) Status: FAIL1 : No pcurve FAIL2 : No vertices DONE1 : Self-intersection found", py::arg("num"), py::arg("points2d"), py::arg("points3d"));
cls_ShapeAnalysis_Wire.def("CheckSelfIntersectingEdge", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer)) &ShapeAnalysis_Wire::CheckSelfIntersectingEdge, "None", py::arg("num"));
cls_ShapeAnalysis_Wire.def("CheckIntersectingEdges", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer, IntRes2d_SequenceOfIntersectionPoint &, TColgp_SequenceOfPnt &, TColStd_SequenceOfReal &)) &ShapeAnalysis_Wire::CheckIntersectingEdges, "Checks two adjacent edges for intersecting. Intersection is reported only if intersection point is not enclosed by the common end vertex of the edges. Returns: True if intersection is found. If returns True it also fills the sequences of intersection points, corresponding 3d points, and errors for them (half-distances between intersection points in 3d calculated from one and from another edge) Status: FAIL1 : No pcurve FAIL2 : No vertices DONE1 : Self-intersection found", py::arg("num"), py::arg("points2d"), py::arg("points3d"), py::arg("errors"));
cls_ShapeAnalysis_Wire.def("CheckIntersectingEdges", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer)) &ShapeAnalysis_Wire::CheckIntersectingEdges, "Checks two adjacent edges for intersecting. Remark : Calls the previous method Status : See the function above for details", py::arg("num"));
cls_ShapeAnalysis_Wire.def("CheckIntersectingEdges", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer, const Standard_Integer, IntRes2d_SequenceOfIntersectionPoint &, TColgp_SequenceOfPnt &, TColStd_SequenceOfReal &)) &ShapeAnalysis_Wire::CheckIntersectingEdges, "Checks i-th and j-th edges for intersecting. Remark : See the previous method for details", py::arg("num1"), py::arg("num2"), py::arg("points2d"), py::arg("points3d"), py::arg("errors"));
cls_ShapeAnalysis_Wire.def("CheckIntersectingEdges", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer, const Standard_Integer)) &ShapeAnalysis_Wire::CheckIntersectingEdges, "Checks i-th and j-th edges for intersecting. Remark : Calls previous method. Status : See the function above for details", py::arg("num1"), py::arg("num2"));
cls_ShapeAnalysis_Wire.def("CheckLacking", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Pnt2d &)) &ShapeAnalysis_Wire::CheckLacking, "Checks if there is a gap in 2d between edges, not comprised by the tolerance of their common vertex. If <Tolerance> is greater than 0. and less than tolerance of the vertex, then this value is used for check. Returns: True if not closed gap was detected p2d1 and p2d2 are the endpoint of <num-1>th edge and start of the <num>th edge in 2d. Status: OK: No edge is lacking (3d and 2d connection) FAIL1: edges have no vertices (at least one of them) FAIL2: edges are neither connected by common vertex, nor have coincided vertices FAIL1: edges have no pcurves DONE1: the gap is detected which cannot be closed by the tolerance of the common vertex (or with value of <Tolerance>) DONE2: is set (together with DONE1) if gap is detected and the vector (p2d2 - p2d1) goes in direction opposite to the pcurves of the edges (if angle is more than 0.9*PI).", py::arg("num"), py::arg("Tolerance"), py::arg("p2d1"), py::arg("p2d2"));
cls_ShapeAnalysis_Wire.def("CheckLacking", [](ShapeAnalysis_Wire &self, const Standard_Integer a0) -> Standard_Boolean { return self.CheckLacking(a0); });
cls_ShapeAnalysis_Wire.def("CheckLacking", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Integer, const Standard_Real)) &ShapeAnalysis_Wire::CheckLacking, "Checks if there is a gap in 2D between edges and not comprised by vertex tolerance The value of SBWD.thepreci is used. Returns: False if no edge should be inserted Status: OK : No edge is lacking (3d and 2d connection) DONE1 : The vertex tolerance should be increased only (2d gap is small) DONE2 : Edge can be inserted (3d and 2d gaps are large enough)", py::arg("num"), py::arg("Tolerance"));
cls_ShapeAnalysis_Wire.def("CheckOuterBound", [](ShapeAnalysis_Wire &self) -> Standard_Boolean { return self.CheckOuterBound(); });
cls_ShapeAnalysis_Wire.def("CheckOuterBound", (Standard_Boolean (ShapeAnalysis_Wire::*)(const Standard_Boolean)) &ShapeAnalysis_Wire::CheckOuterBound, "Checks if wire defines an outer bound on the face Uses ShapeAnalysis::IsOuterBound for analysis If <APIMake> is True uses BRepAPI_MakeWire to build the wire, if False (to be used only when edges share common vertices) uses BRep_Builder to build the wire", py::arg("APIMake"));
cls_ShapeAnalysis_Wire.def("CheckNotchedEdges", [](ShapeAnalysis_Wire &self, const Standard_Integer num, Standard_Integer & shortNum, Standard_Real & param, const Standard_Real Tolerance){ Standard_Boolean rv = self.CheckNotchedEdges(num, shortNum, param, Tolerance); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Real &>(rv, shortNum, param); }, "Detects a notch", py::arg("num"), py::arg("shortNum"), py::arg("param"), py::arg("Tolerance"));
cls_ShapeAnalysis_Wire.def("CheckSmallArea", (Standard_Boolean (ShapeAnalysis_Wire::*)(const TopoDS_Wire &)) &ShapeAnalysis_Wire::CheckSmallArea, "Checks if wire has parametric area less than precision.", py::arg("theWire"));
cls_ShapeAnalysis_Wire.def("CheckShapeConnect", [](ShapeAnalysis_Wire &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.CheckShapeConnect(a0); });
cls_ShapeAnalysis_Wire.def("CheckShapeConnect", (Standard_Boolean (ShapeAnalysis_Wire::*)(const TopoDS_Shape &, const Standard_Real)) &ShapeAnalysis_Wire::CheckShapeConnect, "Checks with what orientation <shape> (wire or edge) can be connected to the wire. Tests distances with starting <preci> from <SBWD> (close confusion), but if given <prec> is greater, tests with <prec> (coarse confusion). The smallest found distance can be returned by MinDistance3d", py::arg("shape"), py::arg("prec"));
cls_ShapeAnalysis_Wire.def("CheckShapeConnect", [](ShapeAnalysis_Wire &self, Standard_Real & tailhead, Standard_Real & tailtail, Standard_Real & headtail, Standard_Real & headhead, const TopoDS_Shape & shape, const Standard_Real prec){ Standard_Boolean rv = self.CheckShapeConnect(tailhead, tailtail, headtail, headhead, shape, prec); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(rv, tailhead, tailtail, headtail, headhead); }, "The same as previous CheckShapeConnect but is more advanced. It returns the distances between each end of <sbwd> and each end of <shape>. For example, <tailhead> stores distance between tail of <sbwd> and head of <shape> Remark: First method CheckShapeConnect calls this one", py::arg("tailhead"), py::arg("tailtail"), py::arg("headtail"), py::arg("headhead"), py::arg("shape"), py::arg("prec"));
cls_ShapeAnalysis_Wire.def("CheckLoop", (Standard_Boolean (ShapeAnalysis_Wire::*)(TopTools_IndexedMapOfShape &, TopTools_DataMapOfShapeListOfShape &, TopTools_MapOfShape &, TopTools_MapOfShape &)) &ShapeAnalysis_Wire::CheckLoop, "Checks existance of loop on wire and return vertices wich are loop vertices (vertices belonging to a few pairs of edges)", py::arg("aMapLoopVertices"), py::arg("aMapVertexEdges"), py::arg("aMapSmallEdges"), py::arg("aMapSeemEdges"));
cls_ShapeAnalysis_Wire.def("CheckTail", (Standard_Boolean (ShapeAnalysis_Wire::*)(const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real, const Standard_Real, TopoDS_Edge &, TopoDS_Edge &, TopoDS_Edge &, TopoDS_Edge &)) &ShapeAnalysis_Wire::CheckTail, "None", py::arg("theEdge1"), py::arg("theEdge2"), py::arg("theMaxSine"), py::arg("theMaxWidth"), py::arg("theMaxTolerance"), py::arg("theEdge11"), py::arg("theEdge12"), py::arg("theEdge21"), py::arg("theEdge22"));
cls_ShapeAnalysis_Wire.def("StatusOrder", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusOrder, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("StatusConnected", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusConnected, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("StatusEdgeCurves", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusEdgeCurves, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("StatusDegenerated", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusDegenerated, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("StatusClosed", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusClosed, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("StatusSmall", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusSmall, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("StatusSelfIntersection", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusSelfIntersection, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("StatusLacking", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusLacking, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("StatusGaps3d", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusGaps3d, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("StatusGaps2d", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusGaps2d, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("StatusCurveGaps", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusCurveGaps, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("StatusLoop", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::StatusLoop, "None", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("LastCheckStatus", (Standard_Boolean (ShapeAnalysis_Wire::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Wire::LastCheckStatus, "Querying the status of the LAST perfomed 'Advanced' checking procedure", py::arg("Status"));
cls_ShapeAnalysis_Wire.def("MinDistance3d", (Standard_Real (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::MinDistance3d, "Returns the last lowest distance in 3D computed by CheckOrientation, CheckConnected, CheckContinuity3d, CheckVertex, CheckNewVertex");
cls_ShapeAnalysis_Wire.def("MinDistance2d", (Standard_Real (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::MinDistance2d, "Returns the last lowest distance in 2D-UV computed by CheckContinuity2d");
cls_ShapeAnalysis_Wire.def("MaxDistance3d", (Standard_Real (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::MaxDistance3d, "Returns the last maximal distance in 3D computed by CheckOrientation, CheckConnected, CheckContinuity3d, CheckVertex, CheckNewVertex, CheckSameParameter");
cls_ShapeAnalysis_Wire.def("MaxDistance2d", (Standard_Real (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::MaxDistance2d, "Returns the last maximal distance in 2D-UV computed by CheckContinuity2d");
cls_ShapeAnalysis_Wire.def_static("get_type_name_", (const char * (*)()) &ShapeAnalysis_Wire::get_type_name, "None");
cls_ShapeAnalysis_Wire.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeAnalysis_Wire::get_type_descriptor, "None");
cls_ShapeAnalysis_Wire.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeAnalysis_Wire::*)() const) &ShapeAnalysis_Wire::DynamicType, "None");

// Enums

}