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
#include <ShapeFix_Root.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeAnalysis_Wire.hxx>
#include <ShapeExtend_WireData.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <ShapeAnalysis_WireOrder.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeFix_Edge.hxx>
#include <ShapeFix_Wire.hxx>
#include <Standard_Type.hxx>

void bind_ShapeFix_Wire(py::module &mod){

py::class_<ShapeFix_Wire, opencascade::handle<ShapeFix_Wire>, ShapeFix_Root> cls_ShapeFix_Wire(mod, "ShapeFix_Wire", "This class provides a set of tools for repairing a wire.");

// Constructors
cls_ShapeFix_Wire.def(py::init<>());
cls_ShapeFix_Wire.def(py::init<const TopoDS_Wire &, const TopoDS_Face &, const Standard_Real>(), py::arg("wire"), py::arg("face"), py::arg("prec"));

// Fields

// Methods
cls_ShapeFix_Wire.def("ClearModes", (void (ShapeFix_Wire::*)()) &ShapeFix_Wire::ClearModes, "Sets all modes to default");
cls_ShapeFix_Wire.def("ClearStatuses", (void (ShapeFix_Wire::*)()) &ShapeFix_Wire::ClearStatuses, "Clears all statuses");
cls_ShapeFix_Wire.def("Init", (void (ShapeFix_Wire::*)(const TopoDS_Wire &, const TopoDS_Face &, const Standard_Real)) &ShapeFix_Wire::Init, "Load analyzer with all the data for the wire and face and drops all fixing statuses", py::arg("wire"), py::arg("face"), py::arg("prec"));
cls_ShapeFix_Wire.def("Init", (void (ShapeFix_Wire::*)(const opencascade::handle<ShapeAnalysis_Wire> &)) &ShapeFix_Wire::Init, "Load analyzer with all the data already prepared and drops all fixing statuses If analyzer contains face, there is no need to set it by SetFace or SetSurface", py::arg("saw"));
cls_ShapeFix_Wire.def("Load", (void (ShapeFix_Wire::*)(const TopoDS_Wire &)) &ShapeFix_Wire::Load, "Load data for the wire, and drops all fixing statuses", py::arg("wire"));
cls_ShapeFix_Wire.def("Load", (void (ShapeFix_Wire::*)(const opencascade::handle<ShapeExtend_WireData> &)) &ShapeFix_Wire::Load, "Load data for the wire, and drops all fixing statuses", py::arg("sbwd"));
cls_ShapeFix_Wire.def("SetFace", (void (ShapeFix_Wire::*)(const TopoDS_Face &)) &ShapeFix_Wire::SetFace, "Set working face for the wire", py::arg("face"));
cls_ShapeFix_Wire.def("SetSurface", (void (ShapeFix_Wire::*)(const opencascade::handle<Geom_Surface> &)) &ShapeFix_Wire::SetSurface, "Set surface for the wire", py::arg("surf"));
cls_ShapeFix_Wire.def("SetSurface", (void (ShapeFix_Wire::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &ShapeFix_Wire::SetSurface, "Set surface for the wire", py::arg("surf"), py::arg("loc"));
cls_ShapeFix_Wire.def("SetPrecision", (void (ShapeFix_Wire::*)(const Standard_Real)) &ShapeFix_Wire::SetPrecision, "Set working precision (to root and to analyzer)", py::arg("prec"));
cls_ShapeFix_Wire.def("SetMaxTailAngle", (void (ShapeFix_Wire::*)(const Standard_Real)) &ShapeFix_Wire::SetMaxTailAngle, "Sets the maximal allowed angle of the tails in radians.", py::arg("theMaxTailAngle"));
cls_ShapeFix_Wire.def("SetMaxTailWidth", (void (ShapeFix_Wire::*)(const Standard_Real)) &ShapeFix_Wire::SetMaxTailWidth, "Sets the maximal allowed width of the tails.", py::arg("theMaxTailWidth"));
cls_ShapeFix_Wire.def("IsLoaded", (Standard_Boolean (ShapeFix_Wire::*)() const) &ShapeFix_Wire::IsLoaded, "Tells if the wire is loaded");
cls_ShapeFix_Wire.def("IsReady", (Standard_Boolean (ShapeFix_Wire::*)() const) &ShapeFix_Wire::IsReady, "Tells if the wire and face are loaded");
cls_ShapeFix_Wire.def("NbEdges", (Standard_Integer (ShapeFix_Wire::*)() const) &ShapeFix_Wire::NbEdges, "returns number of edges in the working wire");
cls_ShapeFix_Wire.def("Wire", (TopoDS_Wire (ShapeFix_Wire::*)() const) &ShapeFix_Wire::Wire, "Makes the resulting Wire (by basic Brep_Builder)");
cls_ShapeFix_Wire.def("WireAPIMake", (TopoDS_Wire (ShapeFix_Wire::*)() const) &ShapeFix_Wire::WireAPIMake, "Makes the resulting Wire (by BRepAPI_MakeWire)");
cls_ShapeFix_Wire.def("Analyzer", (opencascade::handle<ShapeAnalysis_Wire> (ShapeFix_Wire::*)() const) &ShapeFix_Wire::Analyzer, "returns field Analyzer (working tool)");
cls_ShapeFix_Wire.def("WireData", (const opencascade::handle<ShapeExtend_WireData> & (ShapeFix_Wire::*)() const) &ShapeFix_Wire::WireData, "returns working wire");
cls_ShapeFix_Wire.def("Face", (const TopoDS_Face & (ShapeFix_Wire::*)() const) &ShapeFix_Wire::Face, "returns working face (Analyzer.Face())");
cls_ShapeFix_Wire.def("ModifyTopologyMode", (Standard_Boolean & (ShapeFix_Wire::*)()) &ShapeFix_Wire::ModifyTopologyMode, "Returns (modifiable) the flag which defines whether it is allowed to modify topology of the wire during fixing (adding/removing edges etc.)");
cls_ShapeFix_Wire.def("ModifyGeometryMode", (Standard_Boolean & (ShapeFix_Wire::*)()) &ShapeFix_Wire::ModifyGeometryMode, "Returns (modifiable) the flag which defines whether the Fix..() methods are allowed to modify geometry of the edges and vertices");
cls_ShapeFix_Wire.def("ModifyRemoveLoopMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::ModifyRemoveLoopMode, "Returns (modifiable) the flag which defines whether the Fix..() methods are allowed to modify RemoveLoop of the edges");
cls_ShapeFix_Wire.def("ClosedWireMode", (Standard_Boolean & (ShapeFix_Wire::*)()) &ShapeFix_Wire::ClosedWireMode, "Returns (modifiable) the flag which defines whether the wire is to be closed (by calling methods like FixDegenerated() and FixConnected() for last and first edges).");
cls_ShapeFix_Wire.def("PreferencePCurveMode", (Standard_Boolean & (ShapeFix_Wire::*)()) &ShapeFix_Wire::PreferencePCurveMode, "Returns (modifiable) the flag which defines whether the 2d (True) representation of the wire is preferable over 3d one (in the case of ambiguity in FixEdgeCurves).");
cls_ShapeFix_Wire.def("FixGapsByRangesMode", (Standard_Boolean & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixGapsByRangesMode, "Returns (modifiable) the flag which defines whether tool tries to fix gaps first by changing curves ranges (i.e. using intersection, extrema, projections) or not.");
cls_ShapeFix_Wire.def("FixReorderMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixReorderMode, "None");
cls_ShapeFix_Wire.def("FixSmallMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixSmallMode, "None");
cls_ShapeFix_Wire.def("FixConnectedMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixConnectedMode, "None");
cls_ShapeFix_Wire.def("FixEdgeCurvesMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixEdgeCurvesMode, "None");
cls_ShapeFix_Wire.def("FixDegeneratedMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixDegeneratedMode, "None");
cls_ShapeFix_Wire.def("FixSelfIntersectionMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixSelfIntersectionMode, "None");
cls_ShapeFix_Wire.def("FixLackingMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixLackingMode, "None");
cls_ShapeFix_Wire.def("FixGaps3dMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixGaps3dMode, "None");
cls_ShapeFix_Wire.def("FixGaps2dMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixGaps2dMode, "Returns (modifiable) the flag for corresponding Fix..() method which defines whether this method will be called from the method APIFix(): -1 default 1 method will be called 0 method will not be called");
cls_ShapeFix_Wire.def("FixReversed2dMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixReversed2dMode, "None");
cls_ShapeFix_Wire.def("FixRemovePCurveMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixRemovePCurveMode, "None");
cls_ShapeFix_Wire.def("FixAddPCurveMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixAddPCurveMode, "None");
cls_ShapeFix_Wire.def("FixRemoveCurve3dMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixRemoveCurve3dMode, "None");
cls_ShapeFix_Wire.def("FixAddCurve3dMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixAddCurve3dMode, "None");
cls_ShapeFix_Wire.def("FixSeamMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixSeamMode, "None");
cls_ShapeFix_Wire.def("FixShiftedMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixShiftedMode, "None");
cls_ShapeFix_Wire.def("FixSameParameterMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixSameParameterMode, "None");
cls_ShapeFix_Wire.def("FixVertexToleranceMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixVertexToleranceMode, "None");
cls_ShapeFix_Wire.def("FixNotchedEdgesMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixNotchedEdgesMode, "None");
cls_ShapeFix_Wire.def("FixSelfIntersectingEdgeMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixSelfIntersectingEdgeMode, "None");
cls_ShapeFix_Wire.def("FixIntersectingEdgesMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixIntersectingEdgesMode, "None");
cls_ShapeFix_Wire.def("FixNonAdjacentIntersectingEdgesMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixNonAdjacentIntersectingEdgesMode, "Returns (modifiable) the flag for corresponding Fix..() method which defines whether this method will be called from the corresponding Fix..() method of the public level: -1 default 1 method will be called 0 method will not be called");
cls_ShapeFix_Wire.def("FixTailMode", (Standard_Integer & (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixTailMode, "None");
cls_ShapeFix_Wire.def("Perform", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::Perform, "This method performs all the available fixes. If some fix is turned on or off explicitly by the Fix..Mode() flag, this fix is either called or not depending on that flag. Else (i.e. if flag is default) fix is called depending on the situation: some fixes are not called or are limited if order of edges in the wire is not OK, or depending on modes");
cls_ShapeFix_Wire.def("FixReorder", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixReorder, "Performs an analysis and reorders edges in the wire using class WireOrder");
cls_ShapeFix_Wire.def("FixSmall", [](ShapeFix_Wire &self, const Standard_Boolean a0) -> Standard_Integer { return self.FixSmall(a0); });
cls_ShapeFix_Wire.def("FixSmall", (Standard_Integer (ShapeFix_Wire::*)(const Standard_Boolean, const Standard_Real)) &ShapeFix_Wire::FixSmall, "Applies FixSmall(num) to all edges in the wire", py::arg("lockvtx"), py::arg("precsmall"));
cls_ShapeFix_Wire.def("FixConnected", [](ShapeFix_Wire &self) -> Standard_Boolean { return self.FixConnected(); });
cls_ShapeFix_Wire.def("FixConnected", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Real)) &ShapeFix_Wire::FixConnected, "Applies FixConnected(num) to all edges in the wire Connection between first and last edges is treated only if flag ClosedMode is True If <prec> is -1 then MaxTolerance() is taken.", py::arg("prec"));
cls_ShapeFix_Wire.def("FixEdgeCurves", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixEdgeCurves, "Groups the fixes dealing with 3d and pcurves of the edges. The order of the fixes and the default behaviour are: ShapeFix_Edge::FixReversed2d ShapeFix_Edge::FixRemovePCurve (only if forced) ShapeFix_Edge::FixAddPCurve ShapeFix_Edge::FixRemoveCurve3d (only if forced) ShapeFix_Edge::FixAddCurve3d FixSeam, FixShifted, ShapeFix_Edge::FixSameParameter");
cls_ShapeFix_Wire.def("FixDegenerated", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixDegenerated, "Applies FixDegenerated(num) to all edges in the wire Connection between first and last edges is treated only if flag ClosedMode is True");
cls_ShapeFix_Wire.def("FixSelfIntersection", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixSelfIntersection, "Applies FixSelfIntersectingEdge(num) and FixIntersectingEdges(num) to all edges in the wire and FixIntersectingEdges(num1, num2) for all pairs num1 and num2 such that num2 >= num1 + 2 and removes wrong edges if any");
cls_ShapeFix_Wire.def("FixLacking", [](ShapeFix_Wire &self) -> Standard_Boolean { return self.FixLacking(); });
cls_ShapeFix_Wire.def("FixLacking", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Boolean)) &ShapeFix_Wire::FixLacking, "Applies FixLacking(num) to all edges in the wire Connection between first and last edges is treated only if flag ClosedMode is True If <force> is False (default), test for connectness is done with precision of vertex between edges, else it is done with minimal value of vertex tolerance and Analyzer.Precision(). Hence, <force> will lead to inserting lacking edges in replacement of vertices which have big tolerances.", py::arg("force"));
cls_ShapeFix_Wire.def("FixClosed", [](ShapeFix_Wire &self) -> Standard_Boolean { return self.FixClosed(); });
cls_ShapeFix_Wire.def("FixClosed", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Real)) &ShapeFix_Wire::FixClosed, "Fixes a wire to be well closed It performs FixConnected, FixDegenerated and FixLacking between last and first edges (independingly on flag ClosedMode and modes for these fixings) If <prec> is -1 then MaxTolerance() is taken.", py::arg("prec"));
cls_ShapeFix_Wire.def("FixGaps3d", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixGaps3d, "Fixes gaps between ends of 3d curves on adjacent edges myPrecision is used to detect the gaps.");
cls_ShapeFix_Wire.def("FixGaps2d", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixGaps2d, "Fixes gaps between ends of pcurves on adjacent edges myPrecision is used to detect the gaps.");
cls_ShapeFix_Wire.def("FixReorder", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeAnalysis_WireOrder &)) &ShapeFix_Wire::FixReorder, "Reorder edges in the wire as determined by WireOrder that should be filled and computed before", py::arg("wi"));
cls_ShapeFix_Wire.def("FixSmall", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Integer, const Standard_Boolean, const Standard_Real)) &ShapeFix_Wire::FixSmall, "Fixes Null Length Edge to be removed If an Edge has Null Length (regarding preci, or <precsmall> - what is smaller), it should be removed It can be with no problem if its two vertices are the same Else, if lockvtx is False, it is removed and its end vertex is put on the preceeding edge But if lockvtx is True, this edge must be kept ...", py::arg("num"), py::arg("lockvtx"), py::arg("precsmall"));
cls_ShapeFix_Wire.def("FixConnected", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Integer, const Standard_Real)) &ShapeFix_Wire::FixConnected, "Fixes connected edges (preceeding and current) Forces Vertices (end of preceeding-begin of current) to be the same one Tests with starting preci or, if given greater, <prec> If <prec> is -1 then MaxTolerance() is taken.", py::arg("num"), py::arg("prec"));
cls_ShapeFix_Wire.def("FixSeam", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Integer)) &ShapeFix_Wire::FixSeam, "Fixes a seam edge A Seam edge has two pcurves, one for forward. one for reversed The forward pcurve must be set as first", py::arg("num"));
cls_ShapeFix_Wire.def("FixShifted", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixShifted, "Fixes edges which have pcurves shifted by whole parameter range on the closed surface (the case may occur if pcurve of edge was computed by projecting 3d curve, which goes along the seam). It compares each two consequent edges and tries to connect them if distance between ends is near to range of the surface. It also can detect and fix the case if all pcurves are connected, but lie out of parametric bounds of the surface. In addition to FixShifted from ShapeFix_Wire, more sophisticated check of degenerate points is performed, and special cases like sphere given by two meridians are treated.");
cls_ShapeFix_Wire.def("FixDegenerated", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Integer)) &ShapeFix_Wire::FixDegenerated, "Fixes Degenerated Edge Checks an <num-th> edge or a point between <num>th-1 and <num>th edges for a singularity on a supporting surface. If singularity is detected, either adds new degenerated edge (before <num>th), or makes <num>th edge to be degenerated.", py::arg("num"));
cls_ShapeFix_Wire.def("FixLacking", [](ShapeFix_Wire &self, const Standard_Integer a0) -> Standard_Boolean { return self.FixLacking(a0); });
cls_ShapeFix_Wire.def("FixLacking", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Integer, const Standard_Boolean)) &ShapeFix_Wire::FixLacking, "Fixes Lacking Edge Test if two adjucent edges are disconnected in 2d (while connected in 3d), and in that case either increase tolerance of the vertex or add a new edge (straight in 2d space), in order to close wire in 2d. Returns True if edge was added or tolerance was increased.", py::arg("num"), py::arg("force"));
cls_ShapeFix_Wire.def("FixNotchedEdges", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixNotchedEdges, "None");
cls_ShapeFix_Wire.def("FixGap3d", [](ShapeFix_Wire &self, const Standard_Integer a0) -> Standard_Boolean { return self.FixGap3d(a0); });
cls_ShapeFix_Wire.def("FixGap3d", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Integer, const Standard_Boolean)) &ShapeFix_Wire::FixGap3d, "Fixes gap between ends of 3d curves on num-1 and num-th edges. myPrecision is used to detect the gap. If convert is True, converts curves to bsplines to bend.", py::arg("num"), py::arg("convert"));
cls_ShapeFix_Wire.def("FixGap2d", [](ShapeFix_Wire &self, const Standard_Integer a0) -> Standard_Boolean { return self.FixGap2d(a0); });
cls_ShapeFix_Wire.def("FixGap2d", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Integer, const Standard_Boolean)) &ShapeFix_Wire::FixGap2d, "Fixes gap between ends of pcurves on num-1 and num-th edges. myPrecision is used to detect the gap. If convert is True, converts pcurves to bsplines to bend.", py::arg("num"), py::arg("convert"));
cls_ShapeFix_Wire.def("FixTails", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixTails, "None");
cls_ShapeFix_Wire.def("StatusReorder", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusReorder, "None", py::arg("status"));
cls_ShapeFix_Wire.def("StatusSmall", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusSmall, "None", py::arg("status"));
cls_ShapeFix_Wire.def("StatusConnected", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusConnected, "None", py::arg("status"));
cls_ShapeFix_Wire.def("StatusEdgeCurves", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusEdgeCurves, "None", py::arg("status"));
cls_ShapeFix_Wire.def("StatusDegenerated", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusDegenerated, "None", py::arg("status"));
cls_ShapeFix_Wire.def("StatusSelfIntersection", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusSelfIntersection, "None", py::arg("status"));
cls_ShapeFix_Wire.def("StatusLacking", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusLacking, "None", py::arg("status"));
cls_ShapeFix_Wire.def("StatusClosed", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusClosed, "None", py::arg("status"));
cls_ShapeFix_Wire.def("StatusGaps3d", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusGaps3d, "None", py::arg("status"));
cls_ShapeFix_Wire.def("StatusGaps2d", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusGaps2d, "None", py::arg("status"));
cls_ShapeFix_Wire.def("StatusNotches", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusNotches, "None", py::arg("status"));
cls_ShapeFix_Wire.def("StatusRemovedSegment", (Standard_Boolean (ShapeFix_Wire::*)() const) &ShapeFix_Wire::StatusRemovedSegment, "Querying the status of perfomed API fixing procedures Each Status..() methods gives information about the last call to the corresponding Fix..() method of API level: OK : no problems detected; nothing done DONE: some problem(s) was(were) detected and successfully fixed FAIL: some problem(s) cannot be fixed");
cls_ShapeFix_Wire.def("StatusFixTails", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::StatusFixTails, "None", py::arg("status"));
cls_ShapeFix_Wire.def("LastFixStatus", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const) &ShapeFix_Wire::LastFixStatus, "Queries the status of last call to methods Fix... of advanced level For details see corresponding methods; universal statuses are: OK : problem not detected; nothing done DONE: problem was detected and successfully fixed FAIL: problem cannot be fixed", py::arg("status"));
cls_ShapeFix_Wire.def("FixEdgeTool", (opencascade::handle<ShapeFix_Edge> (ShapeFix_Wire::*)() const) &ShapeFix_Wire::FixEdgeTool, "Returns tool for fixing wires.");
cls_ShapeFix_Wire.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Wire::get_type_name, "None");
cls_ShapeFix_Wire.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Wire::get_type_descriptor, "None");
cls_ShapeFix_Wire.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Wire::*)() const) &ShapeFix_Wire::DynamicType, "None");

// Enums

}