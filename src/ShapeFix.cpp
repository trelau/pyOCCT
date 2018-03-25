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

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <ShapeFix_Root.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Message_Msg.hxx>
#include <Message_Gravity.hxx>
#include <Standard_Type.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <ShapeFix_DataMapOfShapeBox2d.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <ShapeAnalysis_Wire.hxx>
#include <ShapeExtend_WireData.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <ShapeAnalysis_WireOrder.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeFix_Edge.hxx>
#include <ShapeFix_Wire.hxx>
#include <ShapeAnalysis_Surface.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <ShapeFix_Face.hxx>
#include <Message_ProgressIndicator.hxx>
#include <ShapeFix_Solid.hxx>
#include <ShapeFix_Shell.hxx>
#include <ShapeFix_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom2d_Curve.hxx>
#include <ShapeFix_EdgeProjAux.hxx>
#include <ShapeConstruct_ProjectCurveOnSurface.hxx>
#include <TopoDS_Compound.hxx>
#include <ShapeFix_FixSmallFace.hxx>
#include <ShapeFix_FixSmallSolid.hxx>
#include <ShapeAnalysis_WireVertex.hxx>
#include <ShapeFix_WireVertex.hxx>
#include <TopTools_MapOfShape.hxx>
#include <ShapeFix_Wireframe.hxx>
#include <ShapeFix_FreeBounds.hxx>
#include <TopoDS_Shell.hxx>
#include <ShapeFix_FaceConnect.hxx>
#include <TopoDS_Solid.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <ShapeFix_ShapeTolerance.hxx>
#include <ShapeFix_EdgeConnect.hxx>
#include <ShapeExtend_CompositeSurface.hxx>
#include <ShapeFix_SequenceOfWireSegment.hxx>
#include <ShapeAnalysis_TransferParameters.hxx>
#include <ShapeFix_ComposeShell.hxx>
#include <ShapeFix_SplitCommonVertex.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopoDS_Vertex.hxx>
#include <ShapeFix_WireSegment.hxx>
#include <ShapeFix_IntersectionTool.hxx>
#include <ShapeFix_SplitTool.hxx>
#include <ShapeFix.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(ShapeFix, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.ShapeBuild");
	py::module::import("OCCT.ShapeExtend");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Message");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.ShapeAnalysis");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.ShapeConstruct");
	py::module::import("OCCT.TopAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_Root.hxx
	py::class_<ShapeFix_Root, opencascade::handle<ShapeFix_Root>, Standard_Transient> cls_ShapeFix_Root(mod, "ShapeFix_Root", "Root class for fixing operations Provides context for recording changes (optional), basic precision value and limit (minimal and maximal) values for tolerances, and message registrator");
	cls_ShapeFix_Root.def(py::init<>());
	cls_ShapeFix_Root.def("Set", (void (ShapeFix_Root::*)(const opencascade::handle<ShapeFix_Root> &)) &ShapeFix_Root::Set, "Copy all fields from another Root object", py::arg("Root"));
	cls_ShapeFix_Root.def("SetContext", (void (ShapeFix_Root::*)(const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeFix_Root::SetContext, "Sets context", py::arg("context"));
	cls_ShapeFix_Root.def("Context", (opencascade::handle<ShapeBuild_ReShape> (ShapeFix_Root::*)() const ) &ShapeFix_Root::Context, "Returns context");
	cls_ShapeFix_Root.def("SetMsgRegistrator", (void (ShapeFix_Root::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix_Root::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
	cls_ShapeFix_Root.def("MsgRegistrator", (opencascade::handle<ShapeExtend_BasicMsgRegistrator> (ShapeFix_Root::*)() const ) &ShapeFix_Root::MsgRegistrator, "Returns message registrator");
	cls_ShapeFix_Root.def("SetPrecision", (void (ShapeFix_Root::*)(const Standard_Real)) &ShapeFix_Root::SetPrecision, "Sets basic precision value", py::arg("preci"));
	cls_ShapeFix_Root.def("Precision", (Standard_Real (ShapeFix_Root::*)() const ) &ShapeFix_Root::Precision, "Returns basic precision value");
	cls_ShapeFix_Root.def("SetMinTolerance", (void (ShapeFix_Root::*)(const Standard_Real)) &ShapeFix_Root::SetMinTolerance, "Sets minimal allowed tolerance", py::arg("mintol"));
	cls_ShapeFix_Root.def("MinTolerance", (Standard_Real (ShapeFix_Root::*)() const ) &ShapeFix_Root::MinTolerance, "Returns minimal allowed tolerance");
	cls_ShapeFix_Root.def("SetMaxTolerance", (void (ShapeFix_Root::*)(const Standard_Real)) &ShapeFix_Root::SetMaxTolerance, "Sets maximal allowed tolerance", py::arg("maxtol"));
	cls_ShapeFix_Root.def("MaxTolerance", (Standard_Real (ShapeFix_Root::*)() const ) &ShapeFix_Root::MaxTolerance, "Returns maximal allowed tolerance");
	cls_ShapeFix_Root.def("LimitTolerance", (Standard_Real (ShapeFix_Root::*)(const Standard_Real) const ) &ShapeFix_Root::LimitTolerance, "Returns tolerance limited by [myMinTol,myMaxTol]", py::arg("toler"));
	cls_ShapeFix_Root.def("SendMsg", [](ShapeFix_Root &self, const TopoDS_Shape & a0, const Message_Msg & a1) -> void { return self.SendMsg(a0, a1); }, py::arg("shape"), py::arg("message"));
	cls_ShapeFix_Root.def("SendMsg", (void (ShapeFix_Root::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity) const ) &ShapeFix_Root::SendMsg, "Sends a message to be attached to the shape. Calls corresponding message of message registrator.", py::arg("shape"), py::arg("message"), py::arg("gravity"));
	cls_ShapeFix_Root.def("SendMsg", [](ShapeFix_Root &self, const Message_Msg & a0) -> void { return self.SendMsg(a0); }, py::arg("message"));
	cls_ShapeFix_Root.def("SendMsg", (void (ShapeFix_Root::*)(const Message_Msg &, const Message_Gravity) const ) &ShapeFix_Root::SendMsg, "Sends a message to be attached to myShape. Calls previous method.", py::arg("message"), py::arg("gravity"));
	cls_ShapeFix_Root.def("SendWarning", (void (ShapeFix_Root::*)(const TopoDS_Shape &, const Message_Msg &) const ) &ShapeFix_Root::SendWarning, "Sends a warning to be attached to the shape. Calls SendMsg with gravity set to Message_Warning.", py::arg("shape"), py::arg("message"));
	cls_ShapeFix_Root.def("SendWarning", (void (ShapeFix_Root::*)(const Message_Msg &) const ) &ShapeFix_Root::SendWarning, "Calls previous method for myShape.", py::arg("message"));
	cls_ShapeFix_Root.def("SendFail", (void (ShapeFix_Root::*)(const TopoDS_Shape &, const Message_Msg &) const ) &ShapeFix_Root::SendFail, "Sends a fail to be attached to the shape. Calls SendMsg with gravity set to Message_Fail.", py::arg("shape"), py::arg("message"));
	cls_ShapeFix_Root.def("SendFail", (void (ShapeFix_Root::*)(const Message_Msg &) const ) &ShapeFix_Root::SendFail, "Calls previous method for myShape.", py::arg("message"));
	cls_ShapeFix_Root.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Root::get_type_name, "None");
	cls_ShapeFix_Root.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Root::get_type_descriptor, "None");
	cls_ShapeFix_Root.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Root::*)() const ) &ShapeFix_Root::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_Wire.hxx
	py::class_<ShapeFix_Wire, opencascade::handle<ShapeFix_Wire>, ShapeFix_Root> cls_ShapeFix_Wire(mod, "ShapeFix_Wire", "This class provides a set of tools for repairing a wire.");
	cls_ShapeFix_Wire.def(py::init<>());
	cls_ShapeFix_Wire.def(py::init<const TopoDS_Wire &, const TopoDS_Face &, const Standard_Real>(), py::arg("wire"), py::arg("face"), py::arg("prec"));
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
	cls_ShapeFix_Wire.def("IsLoaded", (Standard_Boolean (ShapeFix_Wire::*)() const ) &ShapeFix_Wire::IsLoaded, "Tells if the wire is loaded");
	cls_ShapeFix_Wire.def("IsReady", (Standard_Boolean (ShapeFix_Wire::*)() const ) &ShapeFix_Wire::IsReady, "Tells if the wire and face are loaded");
	cls_ShapeFix_Wire.def("NbEdges", (Standard_Integer (ShapeFix_Wire::*)() const ) &ShapeFix_Wire::NbEdges, "returns number of edges in the working wire");
	cls_ShapeFix_Wire.def("Wire", (TopoDS_Wire (ShapeFix_Wire::*)() const ) &ShapeFix_Wire::Wire, "Makes the resulting Wire (by basic Brep_Builder)");
	cls_ShapeFix_Wire.def("WireAPIMake", (TopoDS_Wire (ShapeFix_Wire::*)() const ) &ShapeFix_Wire::WireAPIMake, "Makes the resulting Wire (by BRepAPI_MakeWire)");
	cls_ShapeFix_Wire.def("Analyzer", (opencascade::handle<ShapeAnalysis_Wire> (ShapeFix_Wire::*)() const ) &ShapeFix_Wire::Analyzer, "returns field Analyzer (working tool)");
	cls_ShapeFix_Wire.def("WireData", (const opencascade::handle<ShapeExtend_WireData> & (ShapeFix_Wire::*)() const ) &ShapeFix_Wire::WireData, "returns working wire");
	cls_ShapeFix_Wire.def("Face", (const TopoDS_Face & (ShapeFix_Wire::*)() const ) &ShapeFix_Wire::Face, "returns working face (Analyzer.Face())");
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
	cls_ShapeFix_Wire.def("FixSmall", [](ShapeFix_Wire &self, const Standard_Boolean a0) -> Standard_Integer { return self.FixSmall(a0); }, py::arg("lockvtx"));
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
	cls_ShapeFix_Wire.def("FixLacking", [](ShapeFix_Wire &self, const Standard_Integer a0) -> Standard_Boolean { return self.FixLacking(a0); }, py::arg("num"));
	cls_ShapeFix_Wire.def("FixLacking", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Integer, const Standard_Boolean)) &ShapeFix_Wire::FixLacking, "Fixes Lacking Edge Test if two adjucent edges are disconnected in 2d (while connected in 3d), and in that case either increase tolerance of the vertex or add a new edge (straight in 2d space), in order to close wire in 2d. Returns True if edge was added or tolerance was increased.", py::arg("num"), py::arg("force"));
	cls_ShapeFix_Wire.def("FixNotchedEdges", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixNotchedEdges, "None");
	cls_ShapeFix_Wire.def("FixGap3d", [](ShapeFix_Wire &self, const Standard_Integer a0) -> Standard_Boolean { return self.FixGap3d(a0); }, py::arg("num"));
	cls_ShapeFix_Wire.def("FixGap3d", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Integer, const Standard_Boolean)) &ShapeFix_Wire::FixGap3d, "Fixes gap between ends of 3d curves on num-1 and num-th edges. myPrecision is used to detect the gap. If convert is True, converts curves to bsplines to bend.", py::arg("num"), py::arg("convert"));
	cls_ShapeFix_Wire.def("FixGap2d", [](ShapeFix_Wire &self, const Standard_Integer a0) -> Standard_Boolean { return self.FixGap2d(a0); }, py::arg("num"));
	cls_ShapeFix_Wire.def("FixGap2d", (Standard_Boolean (ShapeFix_Wire::*)(const Standard_Integer, const Standard_Boolean)) &ShapeFix_Wire::FixGap2d, "Fixes gap between ends of pcurves on num-1 and num-th edges. myPrecision is used to detect the gap. If convert is True, converts pcurves to bsplines to bend.", py::arg("num"), py::arg("convert"));
	cls_ShapeFix_Wire.def("FixTails", (Standard_Boolean (ShapeFix_Wire::*)()) &ShapeFix_Wire::FixTails, "None");
	cls_ShapeFix_Wire.def("StatusReorder", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusReorder, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("StatusSmall", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusSmall, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("StatusConnected", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusConnected, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("StatusEdgeCurves", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusEdgeCurves, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("StatusDegenerated", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusDegenerated, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("StatusSelfIntersection", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusSelfIntersection, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("StatusLacking", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusLacking, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("StatusClosed", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusClosed, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("StatusGaps3d", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusGaps3d, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("StatusGaps2d", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusGaps2d, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("StatusNotches", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusNotches, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("StatusRemovedSegment", (Standard_Boolean (ShapeFix_Wire::*)() const ) &ShapeFix_Wire::StatusRemovedSegment, "Querying the status of perfomed API fixing procedures Each Status..() methods gives information about the last call to the corresponding Fix..() method of API level: OK : no problems detected; nothing done DONE: some problem(s) was(were) detected and successfully fixed FAIL: some problem(s) cannot be fixed");
	cls_ShapeFix_Wire.def("StatusFixTails", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::StatusFixTails, "None", py::arg("status"));
	cls_ShapeFix_Wire.def("LastFixStatus", (Standard_Boolean (ShapeFix_Wire::*)(const ShapeExtend_Status) const ) &ShapeFix_Wire::LastFixStatus, "Queries the status of last call to methods Fix... of advanced level For details see corresponding methods; universal statuses are: OK : problem not detected; nothing done DONE: problem was detected and successfully fixed FAIL: problem cannot be fixed", py::arg("status"));
	cls_ShapeFix_Wire.def("FixEdgeTool", (opencascade::handle<ShapeFix_Edge> (ShapeFix_Wire::*)() const ) &ShapeFix_Wire::FixEdgeTool, "Returns tool for fixing wires.");
	cls_ShapeFix_Wire.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Wire::get_type_name, "None");
	cls_ShapeFix_Wire.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Wire::get_type_descriptor, "None");
	cls_ShapeFix_Wire.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Wire::*)() const ) &ShapeFix_Wire::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_Face.hxx
	py::class_<ShapeFix_Face, opencascade::handle<ShapeFix_Face>, ShapeFix_Root> cls_ShapeFix_Face(mod, "ShapeFix_Face", "This operator allows to perform various fixes on face and its wires: fixes provided by ShapeFix_Wire, fixing orientation of wires, addition of natural bounds, fixing of missing seam edge, and detection and removal of null-area wires");
	cls_ShapeFix_Face.def(py::init<>());
	cls_ShapeFix_Face.def(py::init<const TopoDS_Face &>(), py::arg("face"));
	cls_ShapeFix_Face.def("ClearModes", (void (ShapeFix_Face::*)()) &ShapeFix_Face::ClearModes, "Sets all modes to default");
	cls_ShapeFix_Face.def("Init", (void (ShapeFix_Face::*)(const TopoDS_Face &)) &ShapeFix_Face::Init, "Loads a whole face already created, with its wires, sense and location", py::arg("face"));
	cls_ShapeFix_Face.def("Init", [](ShapeFix_Face &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1) -> void { return self.Init(a0, a1); }, py::arg("surf"), py::arg("preci"));
	cls_ShapeFix_Face.def("Init", (void (ShapeFix_Face::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Boolean)) &ShapeFix_Face::Init, "Starts the creation of the face By default it will be FORWARD, or REVERSED if <fwd> is False", py::arg("surf"), py::arg("preci"), py::arg("fwd"));
	cls_ShapeFix_Face.def("Init", [](ShapeFix_Face &self, const opencascade::handle<ShapeAnalysis_Surface> & a0, const Standard_Real a1) -> void { return self.Init(a0, a1); }, py::arg("surf"), py::arg("preci"));
	cls_ShapeFix_Face.def("Init", (void (ShapeFix_Face::*)(const opencascade::handle<ShapeAnalysis_Surface> &, const Standard_Real, const Standard_Boolean)) &ShapeFix_Face::Init, "Starts the creation of the face By default it will be FORWARD, or REVERSED if <fwd> is False", py::arg("surf"), py::arg("preci"), py::arg("fwd"));
	cls_ShapeFix_Face.def("SetMsgRegistrator", (void (ShapeFix_Face::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix_Face::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
	cls_ShapeFix_Face.def("SetPrecision", (void (ShapeFix_Face::*)(const Standard_Real)) &ShapeFix_Face::SetPrecision, "Sets basic precision value (also to FixWireTool)", py::arg("preci"));
	cls_ShapeFix_Face.def("SetMinTolerance", (void (ShapeFix_Face::*)(const Standard_Real)) &ShapeFix_Face::SetMinTolerance, "Sets minimal allowed tolerance (also to FixWireTool)", py::arg("mintol"));
	cls_ShapeFix_Face.def("SetMaxTolerance", (void (ShapeFix_Face::*)(const Standard_Real)) &ShapeFix_Face::SetMaxTolerance, "Sets maximal allowed tolerance (also to FixWireTool)", py::arg("maxtol"));
	cls_ShapeFix_Face.def("FixWireMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixWireMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Wire, by default True.");
	cls_ShapeFix_Face.def("FixOrientationMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixOrientationMode, "Returns (modifiable) the fix orientation mode, by default True. If True, wires oriented to border limited square.");
	cls_ShapeFix_Face.def("FixAddNaturalBoundMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixAddNaturalBoundMode, "Returns (modifiable) the add natural bound mode. If true, natural boundary is added on faces that miss them. Default is False for faces with single wire (they are handled by FixOrientation in that case) and True for others.");
	cls_ShapeFix_Face.def("FixMissingSeamMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixMissingSeamMode, "Returns (modifiable) the fix missing seam mode, by default True. If True, tries to insert seam is missed.");
	cls_ShapeFix_Face.def("FixSmallAreaWireMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixSmallAreaWireMode, "Returns (modifiable) the fix small area wire mode, by default False. If True, drops small wires.");
	cls_ShapeFix_Face.def("RemoveSmallAreaFaceMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::RemoveSmallAreaFaceMode, "Returns (modifiable) the remove face with small area, by default False. If True, drops faces with small outer wires.");
	cls_ShapeFix_Face.def("FixIntersectingWiresMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixIntersectingWiresMode, "Returns (modifiable) the fix intersecting wires mode by default True.");
	cls_ShapeFix_Face.def("FixLoopWiresMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixLoopWiresMode, "Returns (modifiable) the fix loop wires mode by default True.");
	cls_ShapeFix_Face.def("FixSplitFaceMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixSplitFaceMode, "Returns (modifiable) the fix split face mode by default True.");
	cls_ShapeFix_Face.def("AutoCorrectPrecisionMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::AutoCorrectPrecisionMode, "Returns (modifiable) the auto-correct precision mode by default False.");
	cls_ShapeFix_Face.def("FixPeriodicDegeneratedMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixPeriodicDegeneratedMode, "Returns (modifiable) the activation flag for periodic degenerated fix. False by default.");
	cls_ShapeFix_Face.def("Face", (TopoDS_Face (ShapeFix_Face::*)() const ) &ShapeFix_Face::Face, "Returns a face which corresponds to the current state Warning: The finally produced face may be another one ... but with the same support");
	cls_ShapeFix_Face.def("Result", (TopoDS_Shape (ShapeFix_Face::*)() const ) &ShapeFix_Face::Result, "Returns resulting shape (Face or Shell if splitted) To be used instead of Face() if FixMissingSeam involved");
	cls_ShapeFix_Face.def("Add", (void (ShapeFix_Face::*)(const TopoDS_Wire &)) &ShapeFix_Face::Add, "Add a wire to current face using BRep_Builder. Wire is added without taking into account orientation of face (as if face were FORWARD).", py::arg("wire"));
	cls_ShapeFix_Face.def("Perform", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::Perform, "Performs all the fixes, depending on modes Function Status returns the status of last call to Perform() ShapeExtend_OK : face was OK, nothing done ShapeExtend_DONE1: some wires are fixed ShapeExtend_DONE2: orientation of wires fixed ShapeExtend_DONE3: missing seam added ShapeExtend_DONE4: small area wire removed ShapeExtend_DONE5: natural bounds added ShapeExtend_FAIL1: some fails during fixing wires ShapeExtend_FAIL2: cannot fix orientation of wires ShapeExtend_FAIL3: cannot add missing seam ShapeExtend_FAIL4: cannot remove small area wire");
	cls_ShapeFix_Face.def("FixOrientation", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixOrientation, "Fixes orientation of wires on the face It tries to make all wires lie outside all others (according to orientation) by reversing orientation of some of them. If face lying on sphere or torus has single wire and AddNaturalBoundMode is True, that wire is not reversed in any case (supposing that natural bound will be added). Returns True if wires were reversed");
	cls_ShapeFix_Face.def("FixOrientation", (Standard_Boolean (ShapeFix_Face::*)(TopTools_DataMapOfShapeListOfShape &)) &ShapeFix_Face::FixOrientation, "Fixes orientation of wires on the face It tries to make all wires lie outside all others (according to orientation) by reversing orientation of some of them. If face lying on sphere or torus has single wire and AddNaturalBoundMode is True, that wire is not reversed in any case (supposing that natural bound will be added). Returns True if wires were reversed OutWires return information about out wires + list of internal wires for each (for performing split face).", py::arg("MapWires"));
	cls_ShapeFix_Face.def("FixAddNaturalBound", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixAddNaturalBound, "Adds natural boundary on face if it is missing. Two cases are supported: - face has no wires - face lies on geometrically double-closed surface (sphere or torus) and none of wires is left-oriented Returns True if natural boundary was added");
	cls_ShapeFix_Face.def("FixMissingSeam", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixMissingSeam, "Detects and fixes the special case when face on a closed surface is given by two wires closed in 3d but with gap in 2d. In that case it creates a new wire from the two, and adds a missing seam edge Returns True if missing seam was added");
	cls_ShapeFix_Face.def("FixSmallAreaWire", (Standard_Boolean (ShapeFix_Face::*)(const Standard_Boolean)) &ShapeFix_Face::FixSmallAreaWire, "Detects wires with small area (that is less than 100*Precision::PConfusion(). Removes these wires if they are internal. Returns : True if at least one small wire removed, False if does nothing.", py::arg("theIsRemoveSmallFace"));
	cls_ShapeFix_Face.def("FixLoopWire", (Standard_Boolean (ShapeFix_Face::*)(TopTools_SequenceOfShape &)) &ShapeFix_Face::FixLoopWire, "Detects if wire has a loop and fixes this situation by splitting on the few parts. if wire has a loops and it was splitted Status was set to value ShapeExtend_DONE6.", py::arg("aResWires"));
	cls_ShapeFix_Face.def("FixIntersectingWires", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixIntersectingWires, "Detects and fixes the special case when face has more than one wire and this wires have intersection point");
	cls_ShapeFix_Face.def("FixWiresTwoCoincEdges", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixWiresTwoCoincEdges, "If wire contains two coincidence edges it must be removed Queries on status after Perform()");
	cls_ShapeFix_Face.def("FixSplitFace", (Standard_Boolean (ShapeFix_Face::*)(const TopTools_DataMapOfShapeListOfShape &)) &ShapeFix_Face::FixSplitFace, "Split face if there are more than one out wire using inrormation after FixOrientation()", py::arg("MapWires"));
	cls_ShapeFix_Face.def("FixPeriodicDegenerated", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixPeriodicDegenerated, "Fixes topology for a specific case when face is composed by a single wire belting a periodic surface. In that case a degenerated edge is reconstructed in the degenerated pole of the surface. Initial wire gets consistent orientation. Must be used in couple and before FixMissingSeam routine");
	cls_ShapeFix_Face.def("Status", (Standard_Boolean (ShapeFix_Face::*)(const ShapeExtend_Status) const ) &ShapeFix_Face::Status, "Returns the status of last call to Perform() ShapeExtend_OK : face was OK, nothing done ShapeExtend_DONE1: some wires are fixed ShapeExtend_DONE2: orientation of wires fixed ShapeExtend_DONE3: missing seam added ShapeExtend_DONE4: small area wire removed ShapeExtend_DONE5: natural bounds added ShapeExtend_DONE8: face may be splited ShapeExtend_FAIL1: some fails during fixing wires ShapeExtend_FAIL2: cannot fix orientation of wires ShapeExtend_FAIL3: cannot add missing seam ShapeExtend_FAIL4: cannot remove small area wire", py::arg("status"));
	cls_ShapeFix_Face.def("FixWireTool", (opencascade::handle<ShapeFix_Wire> (ShapeFix_Face::*)()) &ShapeFix_Face::FixWireTool, "Returns tool for fixing wires.");
	cls_ShapeFix_Face.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Face::get_type_name, "None");
	cls_ShapeFix_Face.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Face::get_type_descriptor, "None");
	cls_ShapeFix_Face.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Face::*)() const ) &ShapeFix_Face::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_Shape.hxx
	py::class_<ShapeFix_Shape, opencascade::handle<ShapeFix_Shape>, ShapeFix_Root> cls_ShapeFix_Shape(mod, "ShapeFix_Shape", "Fixing shape in general");
	cls_ShapeFix_Shape.def(py::init<>());
	cls_ShapeFix_Shape.def(py::init<const TopoDS_Shape &>(), py::arg("shape"));
	cls_ShapeFix_Shape.def("Init", (void (ShapeFix_Shape::*)(const TopoDS_Shape &)) &ShapeFix_Shape::Init, "Initislises by shape.", py::arg("shape"));
	cls_ShapeFix_Shape.def("Perform", [](ShapeFix_Shape &self) -> Standard_Boolean { return self.Perform(); });
	cls_ShapeFix_Shape.def("Perform", (Standard_Boolean (ShapeFix_Shape::*)(const opencascade::handle<Message_ProgressIndicator> &)) &ShapeFix_Shape::Perform, "Iterates on sub- shape and performs fixes", py::arg("theProgress"));
	cls_ShapeFix_Shape.def("Shape", (TopoDS_Shape (ShapeFix_Shape::*)() const ) &ShapeFix_Shape::Shape, "Returns resulting shape");
	cls_ShapeFix_Shape.def("FixSolidTool", (opencascade::handle<ShapeFix_Solid> (ShapeFix_Shape::*)() const ) &ShapeFix_Shape::FixSolidTool, "Returns tool for fixing solids.");
	cls_ShapeFix_Shape.def("FixShellTool", (opencascade::handle<ShapeFix_Shell> (ShapeFix_Shape::*)() const ) &ShapeFix_Shape::FixShellTool, "Returns tool for fixing shells.");
	cls_ShapeFix_Shape.def("FixFaceTool", (opencascade::handle<ShapeFix_Face> (ShapeFix_Shape::*)() const ) &ShapeFix_Shape::FixFaceTool, "Returns tool for fixing faces.");
	cls_ShapeFix_Shape.def("FixWireTool", (opencascade::handle<ShapeFix_Wire> (ShapeFix_Shape::*)() const ) &ShapeFix_Shape::FixWireTool, "Returns tool for fixing wires.");
	cls_ShapeFix_Shape.def("FixEdgeTool", (opencascade::handle<ShapeFix_Edge> (ShapeFix_Shape::*)() const ) &ShapeFix_Shape::FixEdgeTool, "Returns tool for fixing edges.");
	cls_ShapeFix_Shape.def("Status", (Standard_Boolean (ShapeFix_Shape::*)(const ShapeExtend_Status) const ) &ShapeFix_Shape::Status, "Returns the status of the last Fix. This can be a combination of the following flags: ShapeExtend_DONE1: some free edges were fixed ShapeExtend_DONE2: some free wires were fixed ShapeExtend_DONE3: some free faces were fixed ShapeExtend_DONE4: some free shells were fixed ShapeExtend_DONE5: some free solids were fixed ShapeExtend_DONE6: shapes in compound(s) were fixed", py::arg("status"));
	cls_ShapeFix_Shape.def("SetMsgRegistrator", (void (ShapeFix_Shape::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix_Shape::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
	cls_ShapeFix_Shape.def("SetPrecision", (void (ShapeFix_Shape::*)(const Standard_Real)) &ShapeFix_Shape::SetPrecision, "Sets basic precision value (also to FixSolidTool)", py::arg("preci"));
	cls_ShapeFix_Shape.def("SetMinTolerance", (void (ShapeFix_Shape::*)(const Standard_Real)) &ShapeFix_Shape::SetMinTolerance, "Sets minimal allowed tolerance (also to FixSolidTool)", py::arg("mintol"));
	cls_ShapeFix_Shape.def("SetMaxTolerance", (void (ShapeFix_Shape::*)(const Standard_Real)) &ShapeFix_Shape::SetMaxTolerance, "Sets maximal allowed tolerance (also to FixSolidTool)", py::arg("maxtol"));
	cls_ShapeFix_Shape.def("FixSolidMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixSolidMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Solid, by default True.");
	cls_ShapeFix_Shape.def("FixFreeShellMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixFreeShellMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Shell, by default True.");
	cls_ShapeFix_Shape.def("FixFreeFaceMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixFreeFaceMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Face, by default True.");
	cls_ShapeFix_Shape.def("FixFreeWireMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixFreeWireMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Wire, by default True.");
	cls_ShapeFix_Shape.def("FixSameParameterMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixSameParameterMode, "Returns (modifiable) the mode for applying ShapeFix::SameParameter after all fixes, by default True.");
	cls_ShapeFix_Shape.def("FixVertexPositionMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixVertexPositionMode, "Returns (modifiable) the mode for applying ShapeFix::FixVertexPosition before all fixes, by default False.");
	cls_ShapeFix_Shape.def("FixVertexTolMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixVertexTolMode, "Returns (modifiable) the mode for fixing tolerances of vertices on whole shape after performing all fixes");
	cls_ShapeFix_Shape.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Shape::get_type_name, "None");
	cls_ShapeFix_Shape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Shape::get_type_descriptor, "None");
	cls_ShapeFix_Shape.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Shape::*)() const ) &ShapeFix_Shape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_EdgeProjAux.hxx
	py::class_<ShapeFix_EdgeProjAux, opencascade::handle<ShapeFix_EdgeProjAux>, Standard_Transient> cls_ShapeFix_EdgeProjAux(mod, "ShapeFix_EdgeProjAux", "Project 3D point (vertex) on pcurves to find Vertex Parameter on parametric representation of an edge");
	cls_ShapeFix_EdgeProjAux.def(py::init<>());
	cls_ShapeFix_EdgeProjAux.def(py::init<const TopoDS_Face &, const TopoDS_Edge &>(), py::arg("F"), py::arg("E"));
	cls_ShapeFix_EdgeProjAux.def("Init", (void (ShapeFix_EdgeProjAux::*)(const TopoDS_Face &, const TopoDS_Edge &)) &ShapeFix_EdgeProjAux::Init, "None", py::arg("F"), py::arg("E"));
	cls_ShapeFix_EdgeProjAux.def("Compute", (void (ShapeFix_EdgeProjAux::*)(const Standard_Real)) &ShapeFix_EdgeProjAux::Compute, "None", py::arg("preci"));
	cls_ShapeFix_EdgeProjAux.def("IsFirstDone", (Standard_Boolean (ShapeFix_EdgeProjAux::*)() const ) &ShapeFix_EdgeProjAux::IsFirstDone, "None");
	cls_ShapeFix_EdgeProjAux.def("IsLastDone", (Standard_Boolean (ShapeFix_EdgeProjAux::*)() const ) &ShapeFix_EdgeProjAux::IsLastDone, "None");
	cls_ShapeFix_EdgeProjAux.def("FirstParam", (Standard_Real (ShapeFix_EdgeProjAux::*)() const ) &ShapeFix_EdgeProjAux::FirstParam, "None");
	cls_ShapeFix_EdgeProjAux.def("LastParam", (Standard_Real (ShapeFix_EdgeProjAux::*)() const ) &ShapeFix_EdgeProjAux::LastParam, "None");
	cls_ShapeFix_EdgeProjAux.def("IsIso", (Standard_Boolean (ShapeFix_EdgeProjAux::*)(const opencascade::handle<Geom2d_Curve> &)) &ShapeFix_EdgeProjAux::IsIso, "None", py::arg("C"));
	cls_ShapeFix_EdgeProjAux.def_static("get_type_name_", (const char * (*)()) &ShapeFix_EdgeProjAux::get_type_name, "None");
	cls_ShapeFix_EdgeProjAux.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_EdgeProjAux::get_type_descriptor, "None");
	cls_ShapeFix_EdgeProjAux.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_EdgeProjAux::*)() const ) &ShapeFix_EdgeProjAux::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_Edge.hxx
	py::class_<ShapeFix_Edge, opencascade::handle<ShapeFix_Edge>, Standard_Transient> cls_ShapeFix_Edge(mod, "ShapeFix_Edge", "Fixing invalid edge. Geometrical and/or topological inconsistency: - no 3d curve or pcurve, - mismatching orientation of 3d curve and pcurve, - incorrect SameParameter flag (curve deviation is greater than edge tolerance), - not adjacent curves (3d or pcurve) to the vertices.");
	cls_ShapeFix_Edge.def(py::init<>());
	cls_ShapeFix_Edge.def("Projector", (opencascade::handle<ShapeConstruct_ProjectCurveOnSurface> (ShapeFix_Edge::*)()) &ShapeFix_Edge::Projector, "Returns the projector used for recomputing missing pcurves Can be used for adjusting parameters of projector");
	cls_ShapeFix_Edge.def("FixRemovePCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &)) &ShapeFix_Edge::FixRemovePCurve, "None", py::arg("edge"), py::arg("face"));
	cls_ShapeFix_Edge.def("FixRemovePCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &ShapeFix_Edge::FixRemovePCurve, "Removes the pcurve(s) of the edge if it does not match the vertices Check is done Use : It is to be called when pcurve of an edge can be wrong (e.g., after import from IGES) Returns: True, if does not match, removed (status DONE) False, (status OK) if matches or (status FAIL) if no pcurve, nothing done", py::arg("edge"), py::arg("surface"), py::arg("location"));
	cls_ShapeFix_Edge.def("FixRemoveCurve3d", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &)) &ShapeFix_Edge::FixRemoveCurve3d, "Removes 3d curve of the edge if it does not match the vertices Returns: True, if does not match, removed (status DONE) False, (status OK) if matches or (status FAIL) if no 3d curve, nothing done", py::arg("edge"));
	cls_ShapeFix_Edge.def("FixAddPCurve", [](ShapeFix_Edge &self, const TopoDS_Edge & a0, const TopoDS_Face & a1, const Standard_Boolean a2) -> Standard_Boolean { return self.FixAddPCurve(a0, a1, a2); }, py::arg("edge"), py::arg("face"), py::arg("isSeam"));
	cls_ShapeFix_Edge.def("FixAddPCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Boolean, const Standard_Real)) &ShapeFix_Edge::FixAddPCurve, "See method below for information", py::arg("edge"), py::arg("face"), py::arg("isSeam"), py::arg("prec"));
	cls_ShapeFix_Edge.def("FixAddPCurve", [](ShapeFix_Edge &self, const TopoDS_Edge & a0, const opencascade::handle<Geom_Surface> & a1, const TopLoc_Location & a2, const Standard_Boolean a3) -> Standard_Boolean { return self.FixAddPCurve(a0, a1, a2, a3); }, py::arg("edge"), py::arg("surface"), py::arg("location"), py::arg("isSeam"));
	cls_ShapeFix_Edge.def("FixAddPCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Boolean, const Standard_Real)) &ShapeFix_Edge::FixAddPCurve, "See method below for information", py::arg("edge"), py::arg("surface"), py::arg("location"), py::arg("isSeam"), py::arg("prec"));
	cls_ShapeFix_Edge.def("FixAddPCurve", [](ShapeFix_Edge &self, const TopoDS_Edge & a0, const TopoDS_Face & a1, const Standard_Boolean a2, const opencascade::handle<ShapeAnalysis_Surface> & a3) -> Standard_Boolean { return self.FixAddPCurve(a0, a1, a2, a3); }, py::arg("edge"), py::arg("face"), py::arg("isSeam"), py::arg("surfana"));
	cls_ShapeFix_Edge.def("FixAddPCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Boolean, const opencascade::handle<ShapeAnalysis_Surface> &, const Standard_Real)) &ShapeFix_Edge::FixAddPCurve, "See method below for information", py::arg("edge"), py::arg("face"), py::arg("isSeam"), py::arg("surfana"), py::arg("prec"));
	cls_ShapeFix_Edge.def("FixAddPCurve", [](ShapeFix_Edge &self, const TopoDS_Edge & a0, const opencascade::handle<Geom_Surface> & a1, const TopLoc_Location & a2, const Standard_Boolean a3, const opencascade::handle<ShapeAnalysis_Surface> & a4) -> Standard_Boolean { return self.FixAddPCurve(a0, a1, a2, a3, a4); }, py::arg("edge"), py::arg("surface"), py::arg("location"), py::arg("isSeam"), py::arg("surfana"));
	cls_ShapeFix_Edge.def("FixAddPCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Boolean, const opencascade::handle<ShapeAnalysis_Surface> &, const Standard_Real)) &ShapeFix_Edge::FixAddPCurve, "Adds pcurve(s) of the edge if missing (by projecting 3d curve) Parameter isSeam indicates if the edge is a seam. The parameter <prec> defines the precision for calculations. If it is 0 (default), the tolerance of the edge is taken. Remark : This method is rather for internal use since it accepts parameter <surfana> for optimization of computations Use : It is to be called after FixRemovePCurve (if removed) or in any case when edge can have no pcurve Returns: True if pcurve was added, else False Status : OK : Pcurve exists FAIL1: No 3d curve FAIL2: fail during projecting DONE1: Pcurve was added DONE2: specific case of pcurve going through degenerated point on sphere encountered during projection (see class ShapeConstruct_ProjectCurveOnSurface for more info)", py::arg("edge"), py::arg("surface"), py::arg("location"), py::arg("isSeam"), py::arg("surfana"), py::arg("prec"));
	cls_ShapeFix_Edge.def("FixAddCurve3d", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &)) &ShapeFix_Edge::FixAddCurve3d, "Tries to build 3d curve of the edge if missing Use : It is to be called after FixRemoveCurve3d (if removed) or in any case when edge can have no 3d curve Returns: True if 3d curve was added, else False Status : OK : 3d curve exists FAIL1: BRepLib::BuildCurve3d() has failed DONE1: 3d curve was added", py::arg("edge"));
	cls_ShapeFix_Edge.def("FixVertexTolerance", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &)) &ShapeFix_Edge::FixVertexTolerance, "None", py::arg("edge"), py::arg("face"));
	cls_ShapeFix_Edge.def("FixVertexTolerance", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &)) &ShapeFix_Edge::FixVertexTolerance, "Increases the tolerances of the edge vertices to comprise the ends of 3d curve and pcurve on the given face (first method) or all pcurves stored in an edge (second one) Returns: True, if tolerances have been increased, otherwise False Status: OK : the original tolerances have not been changed DONE1: the tolerance of first vertex has been increased DONE2: the tolerance of last vertex has been increased", py::arg("edge"));
	cls_ShapeFix_Edge.def("FixReversed2d", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &)) &ShapeFix_Edge::FixReversed2d, "None", py::arg("edge"), py::arg("face"));
	cls_ShapeFix_Edge.def("FixReversed2d", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &ShapeFix_Edge::FixReversed2d, "Fixes edge if pcurve is directed opposite to 3d curve Check is done by call to the function ShapeAnalysis_Edge::CheckCurve3dWithPCurve() Warning: For seam edge this method will check and fix the pcurve in only one direction. Hence, it should be called twice for seam edge: once with edge orientation FORWARD and once with REVERSED. Returns: False if nothing done, True if reversed (status DONE) Status: OK - pcurve OK, nothing done FAIL1 - no pcurve FAIL2 - no 3d curve DONE1 - pcurve was reversed", py::arg("edge"), py::arg("surface"), py::arg("location"));
	cls_ShapeFix_Edge.def("FixSameParameter", [](ShapeFix_Edge &self, const TopoDS_Edge & a0) -> Standard_Boolean { return self.FixSameParameter(a0); }, py::arg("edge"));
	cls_ShapeFix_Edge.def("FixSameParameter", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const Standard_Real)) &ShapeFix_Edge::FixSameParameter, "Tries to make edge SameParameter and sets corresponding tolerance and SameParameter flag. First, it makes edge same range if SameRange flag is not set.", py::arg("edge"), py::arg("tolerance"));
	cls_ShapeFix_Edge.def("FixSameParameter", [](ShapeFix_Edge &self, const TopoDS_Edge & a0, const TopoDS_Face & a1) -> Standard_Boolean { return self.FixSameParameter(a0, a1); }, py::arg("edge"), py::arg("face"));
	cls_ShapeFix_Edge.def("FixSameParameter", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real)) &ShapeFix_Edge::FixSameParameter, "Tries to make edge SameParameter and sets corresponding tolerance and SameParameter flag. First, it makes edge same range if SameRange flag is not set.", py::arg("edge"), py::arg("face"), py::arg("tolerance"));
	cls_ShapeFix_Edge.def("Status", (Standard_Boolean (ShapeFix_Edge::*)(const ShapeExtend_Status) const ) &ShapeFix_Edge::Status, "Returns the status (in the form of True/False) of last Fix", py::arg("status"));
	cls_ShapeFix_Edge.def("SetContext", (void (ShapeFix_Edge::*)(const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeFix_Edge::SetContext, "Sets context", py::arg("context"));
	// FIXME Mismatch between signature here and in OCCT .h file
        //cls_ShapeFix_Edge.def("Context", (opencascade::handle<ShapeBuild_ReShape> (ShapeFix_Edge::*)() const ) &ShapeFix_Edge::Context, "Returns context");
	cls_ShapeFix_Edge.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Edge::get_type_name, "None");
	cls_ShapeFix_Edge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Edge::get_type_descriptor, "None");
	cls_ShapeFix_Edge.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Edge::*)() const ) &ShapeFix_Edge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_FixSmallFace.hxx
	py::class_<ShapeFix_FixSmallFace, opencascade::handle<ShapeFix_FixSmallFace>, ShapeFix_Root> cls_ShapeFix_FixSmallFace(mod, "ShapeFix_FixSmallFace", "Fixing face with small size");
	cls_ShapeFix_FixSmallFace.def(py::init<>());
	cls_ShapeFix_FixSmallFace.def("Init", (void (ShapeFix_FixSmallFace::*)(const TopoDS_Shape &)) &ShapeFix_FixSmallFace::Init, "None", py::arg("S"));
	cls_ShapeFix_FixSmallFace.def("Perform", (void (ShapeFix_FixSmallFace::*)()) &ShapeFix_FixSmallFace::Perform, "Fixing case of spot face");
	cls_ShapeFix_FixSmallFace.def("FixSpotFace", (TopoDS_Shape (ShapeFix_FixSmallFace::*)()) &ShapeFix_FixSmallFace::FixSpotFace, "Fixing case of spot face, if tol = -1 used local tolerance.");
	cls_ShapeFix_FixSmallFace.def("ReplaceVerticesInCaseOfSpot", (Standard_Boolean (ShapeFix_FixSmallFace::*)(TopoDS_Face &, const Standard_Real) const ) &ShapeFix_FixSmallFace::ReplaceVerticesInCaseOfSpot, "Compute average vertex and replacing vertices by new one.", py::arg("F"), py::arg("tol"));
	cls_ShapeFix_FixSmallFace.def("RemoveFacesInCaseOfSpot", (Standard_Boolean (ShapeFix_FixSmallFace::*)(const TopoDS_Face &) const ) &ShapeFix_FixSmallFace::RemoveFacesInCaseOfSpot, "Remove spot face from compound", py::arg("F"));
	cls_ShapeFix_FixSmallFace.def("FixStripFace", [](ShapeFix_FixSmallFace &self) -> TopoDS_Shape { return self.FixStripFace(); });
	cls_ShapeFix_FixSmallFace.def("FixStripFace", (TopoDS_Shape (ShapeFix_FixSmallFace::*)(const Standard_Boolean)) &ShapeFix_FixSmallFace::FixStripFace, "Fixing case of strip face, if tol = -1 used local tolerance", py::arg("wasdone"));
	cls_ShapeFix_FixSmallFace.def("ReplaceInCaseOfStrip", (Standard_Boolean (ShapeFix_FixSmallFace::*)(TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Real) const ) &ShapeFix_FixSmallFace::ReplaceInCaseOfStrip, "Replace veretces and edges.", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("tol"));
	cls_ShapeFix_FixSmallFace.def("RemoveFacesInCaseOfStrip", (Standard_Boolean (ShapeFix_FixSmallFace::*)(const TopoDS_Face &) const ) &ShapeFix_FixSmallFace::RemoveFacesInCaseOfStrip, "Remove strip face from compound.", py::arg("F"));
	cls_ShapeFix_FixSmallFace.def("ComputeSharedEdgeForStripFace", (TopoDS_Edge (ShapeFix_FixSmallFace::*)(const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real) const ) &ShapeFix_FixSmallFace::ComputeSharedEdgeForStripFace, "Compute average edge for strip face", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("F1"), py::arg("tol"));
	cls_ShapeFix_FixSmallFace.def("FixSplitFace", (TopoDS_Shape (ShapeFix_FixSmallFace::*)(const TopoDS_Shape &)) &ShapeFix_FixSmallFace::FixSplitFace, "None", py::arg("S"));
	cls_ShapeFix_FixSmallFace.def("SplitOneFace", (Standard_Boolean (ShapeFix_FixSmallFace::*)(TopoDS_Face &, TopoDS_Compound &)) &ShapeFix_FixSmallFace::SplitOneFace, "Compute data for face splitting.", py::arg("F"), py::arg("theSplittedFaces"));
	cls_ShapeFix_FixSmallFace.def("FixFace", (TopoDS_Face (ShapeFix_FixSmallFace::*)(const TopoDS_Face &)) &ShapeFix_FixSmallFace::FixFace, "None", py::arg("F"));
	cls_ShapeFix_FixSmallFace.def("FixShape", (TopoDS_Shape (ShapeFix_FixSmallFace::*)()) &ShapeFix_FixSmallFace::FixShape, "None");
	cls_ShapeFix_FixSmallFace.def("Shape", (TopoDS_Shape (ShapeFix_FixSmallFace::*)()) &ShapeFix_FixSmallFace::Shape, "None");
	cls_ShapeFix_FixSmallFace.def("FixPinFace", (Standard_Boolean (ShapeFix_FixSmallFace::*)(TopoDS_Face &)) &ShapeFix_FixSmallFace::FixPinFace, "None", py::arg("F"));
	cls_ShapeFix_FixSmallFace.def_static("get_type_name_", (const char * (*)()) &ShapeFix_FixSmallFace::get_type_name, "None");
	cls_ShapeFix_FixSmallFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_FixSmallFace::get_type_descriptor, "None");
	cls_ShapeFix_FixSmallFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_FixSmallFace::*)() const ) &ShapeFix_FixSmallFace::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_FixSmallSolid.hxx
	py::class_<ShapeFix_FixSmallSolid, opencascade::handle<ShapeFix_FixSmallSolid>, ShapeFix_Root> cls_ShapeFix_FixSmallSolid(mod, "ShapeFix_FixSmallSolid", "Fixing solids with small size");
	cls_ShapeFix_FixSmallSolid.def(py::init<>());
	cls_ShapeFix_FixSmallSolid.def("SetFixMode", (void (ShapeFix_FixSmallSolid::*)(const Standard_Integer)) &ShapeFix_FixSmallSolid::SetFixMode, "Set working mode for operator: - theMode = 0 use both WidthFactorThreshold and VolumeThreshold parameters - theMode = 1 use only WidthFactorThreshold parameter - theMode = 2 use only VolumeThreshold parameter", py::arg("theMode"));
	cls_ShapeFix_FixSmallSolid.def("SetVolumeThreshold", [](ShapeFix_FixSmallSolid &self) -> void { return self.SetVolumeThreshold(); });
	cls_ShapeFix_FixSmallSolid.def("SetVolumeThreshold", (void (ShapeFix_FixSmallSolid::*)(const Standard_Real)) &ShapeFix_FixSmallSolid::SetVolumeThreshold, "Set or clear volume threshold for small solids", py::arg("theThreshold"));
	cls_ShapeFix_FixSmallSolid.def("SetWidthFactorThreshold", [](ShapeFix_FixSmallSolid &self) -> void { return self.SetWidthFactorThreshold(); });
	cls_ShapeFix_FixSmallSolid.def("SetWidthFactorThreshold", (void (ShapeFix_FixSmallSolid::*)(const Standard_Real)) &ShapeFix_FixSmallSolid::SetWidthFactorThreshold, "Set or clear width factor threshold for small solids", py::arg("theThreshold"));
	cls_ShapeFix_FixSmallSolid.def("Remove", (TopoDS_Shape (ShapeFix_FixSmallSolid::*)(const TopoDS_Shape &, const opencascade::handle<ShapeBuild_ReShape> &) const ) &ShapeFix_FixSmallSolid::Remove, "Remove small solids from the given shape", py::arg("theShape"), py::arg("theContext"));
	cls_ShapeFix_FixSmallSolid.def("Merge", (TopoDS_Shape (ShapeFix_FixSmallSolid::*)(const TopoDS_Shape &, const opencascade::handle<ShapeBuild_ReShape> &) const ) &ShapeFix_FixSmallSolid::Merge, "Merge small solids in the given shape to adjacent non-small ones", py::arg("theShape"), py::arg("theContext"));
	cls_ShapeFix_FixSmallSolid.def_static("get_type_name_", (const char * (*)()) &ShapeFix_FixSmallSolid::get_type_name, "None");
	cls_ShapeFix_FixSmallSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_FixSmallSolid::get_type_descriptor, "None");
	cls_ShapeFix_FixSmallSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_FixSmallSolid::*)() const ) &ShapeFix_FixSmallSolid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_WireVertex.hxx
	py::class_<ShapeFix_WireVertex, std::unique_ptr<ShapeFix_WireVertex, Deleter<ShapeFix_WireVertex>>> cls_ShapeFix_WireVertex(mod, "ShapeFix_WireVertex", "Fixing disconnected edges in the wire Fixes vertices in the wire on the basis of pre-analysis made by ShapeAnalysis_WireVertex (given as argument). The Wire has formerly been loaded in a ShapeExtend_WireData.");
	cls_ShapeFix_WireVertex.def(py::init<>());
	cls_ShapeFix_WireVertex.def("Init", (void (ShapeFix_WireVertex::*)(const TopoDS_Wire &, const Standard_Real)) &ShapeFix_WireVertex::Init, "Loads the wire, ininializes internal analyzer (ShapeAnalysis_WireVertex) with the given precision, and performs analysis", py::arg("wire"), py::arg("preci"));
	cls_ShapeFix_WireVertex.def("Init", (void (ShapeFix_WireVertex::*)(const opencascade::handle<ShapeExtend_WireData> &, const Standard_Real)) &ShapeFix_WireVertex::Init, "Loads the wire, ininializes internal analyzer (ShapeAnalysis_WireVertex) with the given precision, and performs analysis", py::arg("sbwd"), py::arg("preci"));
	cls_ShapeFix_WireVertex.def("Init", (void (ShapeFix_WireVertex::*)(const ShapeAnalysis_WireVertex &)) &ShapeFix_WireVertex::Init, "Loads all the data on wire, already analysed by ShapeAnalysis_WireVertex", py::arg("sawv"));
	cls_ShapeFix_WireVertex.def("Analyzer", (const ShapeAnalysis_WireVertex & (ShapeFix_WireVertex::*)() const ) &ShapeFix_WireVertex::Analyzer, "returns internal analyzer");
	cls_ShapeFix_WireVertex.def("WireData", (const opencascade::handle<ShapeExtend_WireData> & (ShapeFix_WireVertex::*)() const ) &ShapeFix_WireVertex::WireData, "returns data on wire (fixed)");
	cls_ShapeFix_WireVertex.def("Wire", (TopoDS_Wire (ShapeFix_WireVertex::*)() const ) &ShapeFix_WireVertex::Wire, "returns resulting wire (fixed)");
	cls_ShapeFix_WireVertex.def("FixSame", (Standard_Integer (ShapeFix_WireVertex::*)()) &ShapeFix_WireVertex::FixSame, "Fixes 'Same' or 'Close' status (same vertex may be set, without changing parameters) Returns the count of fixed vertices, 0 if none");
	cls_ShapeFix_WireVertex.def("Fix", (Standard_Integer (ShapeFix_WireVertex::*)()) &ShapeFix_WireVertex::Fix, "Fixes all statuses except 'Disjoined', i.e. the cases in which a common value has been set, with or without changing parameters Returns the count of fixed vertices, 0 if none");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_Wireframe.hxx
	py::class_<ShapeFix_Wireframe, opencascade::handle<ShapeFix_Wireframe>, ShapeFix_Root> cls_ShapeFix_Wireframe(mod, "ShapeFix_Wireframe", "Provides methods for fixing wireframe of shape");
	cls_ShapeFix_Wireframe.def(py::init<>());
	cls_ShapeFix_Wireframe.def(py::init<const TopoDS_Shape &>(), py::arg("shape"));
	cls_ShapeFix_Wireframe.def("ClearStatuses", (void (ShapeFix_Wireframe::*)()) &ShapeFix_Wireframe::ClearStatuses, "Clears all statuses");
	cls_ShapeFix_Wireframe.def("Load", (void (ShapeFix_Wireframe::*)(const TopoDS_Shape &)) &ShapeFix_Wireframe::Load, "Loads a shape, resets statuses", py::arg("shape"));
	cls_ShapeFix_Wireframe.def("FixWireGaps", (Standard_Boolean (ShapeFix_Wireframe::*)()) &ShapeFix_Wireframe::FixWireGaps, "Fixes gaps between ends of curves of adjacent edges (both 3d and pcurves) in wires If precision is 0.0, uses Precision::Confusion().");
	cls_ShapeFix_Wireframe.def("FixSmallEdges", (Standard_Boolean (ShapeFix_Wireframe::*)()) &ShapeFix_Wireframe::FixSmallEdges, "Fixes small edges in shape by merging adjacent edges If precision is 0.0, uses Precision::Confusion().");
	cls_ShapeFix_Wireframe.def("CheckSmallEdges", (Standard_Boolean (ShapeFix_Wireframe::*)(TopTools_MapOfShape &, TopTools_DataMapOfShapeListOfShape &, TopTools_DataMapOfShapeListOfShape &, TopTools_MapOfShape &)) &ShapeFix_Wireframe::CheckSmallEdges, "Auxiliary tool for FixSmallEdges which checks for small edges and fills the maps. Returns True if at least one small edge has been found.", py::arg("theSmallEdges"), py::arg("theEdgeToFaces"), py::arg("theFaceWithSmall"), py::arg("theMultyEdges"));
	cls_ShapeFix_Wireframe.def("MergeSmallEdges", [](ShapeFix_Wireframe &self, TopTools_MapOfShape & a0, TopTools_DataMapOfShapeListOfShape & a1, TopTools_DataMapOfShapeListOfShape & a2, TopTools_MapOfShape & a3) -> Standard_Boolean { return self.MergeSmallEdges(a0, a1, a2, a3); }, py::arg("theSmallEdges"), py::arg("theEdgeToFaces"), py::arg("theFaceWithSmall"), py::arg("theMultyEdges"));
	cls_ShapeFix_Wireframe.def("MergeSmallEdges", [](ShapeFix_Wireframe &self, TopTools_MapOfShape & a0, TopTools_DataMapOfShapeListOfShape & a1, TopTools_DataMapOfShapeListOfShape & a2, TopTools_MapOfShape & a3, const Standard_Boolean a4) -> Standard_Boolean { return self.MergeSmallEdges(a0, a1, a2, a3, a4); }, py::arg("theSmallEdges"), py::arg("theEdgeToFaces"), py::arg("theFaceWithSmall"), py::arg("theMultyEdges"), py::arg("theModeDrop"));
	cls_ShapeFix_Wireframe.def("MergeSmallEdges", (Standard_Boolean (ShapeFix_Wireframe::*)(TopTools_MapOfShape &, TopTools_DataMapOfShapeListOfShape &, TopTools_DataMapOfShapeListOfShape &, TopTools_MapOfShape &, const Standard_Boolean, const Standard_Real)) &ShapeFix_Wireframe::MergeSmallEdges, "Auxiliary tool for FixSmallEdges which merges small edges. If theModeDrop is equal to Standard_True then small edges, which cannot be connected with adjacent edges are dropped. Otherwise they are kept. theLimitAngle specifies maximum allowed tangency discontinuity between adjacent edges. If theLimitAngle is equal to -1, this angle is not taken into account.", py::arg("theSmallEdges"), py::arg("theEdgeToFaces"), py::arg("theFaceWithSmall"), py::arg("theMultyEdges"), py::arg("theModeDrop"), py::arg("theLimitAngle"));
	cls_ShapeFix_Wireframe.def("StatusWireGaps", (Standard_Boolean (ShapeFix_Wireframe::*)(const ShapeExtend_Status) const ) &ShapeFix_Wireframe::StatusWireGaps, "Decodes the status of the last FixWireGaps. OK - No gaps were found DONE1 - Some gaps in 3D were fixed DONE2 - Some gaps in 2D were fixed FAIL1 - Failed to fix some gaps in 3D FAIL2 - Failed to fix some gaps in 2D", py::arg("status"));
	cls_ShapeFix_Wireframe.def("StatusSmallEdges", (Standard_Boolean (ShapeFix_Wireframe::*)(const ShapeExtend_Status) const ) &ShapeFix_Wireframe::StatusSmallEdges, "Decodes the status of the last FixSmallEdges. OK - No small edges were found DONE1 - Some small edges were fixed FAIL1 - Failed to fix some small edges", py::arg("status"));
	cls_ShapeFix_Wireframe.def("Shape", (TopoDS_Shape (ShapeFix_Wireframe::*)()) &ShapeFix_Wireframe::Shape, "None");
	cls_ShapeFix_Wireframe.def("ModeDropSmallEdges", (Standard_Boolean & (ShapeFix_Wireframe::*)()) &ShapeFix_Wireframe::ModeDropSmallEdges, "Returns mode managing removing small edges.");
	cls_ShapeFix_Wireframe.def("SetLimitAngle", (void (ShapeFix_Wireframe::*)(const Standard_Real)) &ShapeFix_Wireframe::SetLimitAngle, "Set limit angle for merging edges.", py::arg("theLimitAngle"));
	cls_ShapeFix_Wireframe.def("LimitAngle", (Standard_Real (ShapeFix_Wireframe::*)() const ) &ShapeFix_Wireframe::LimitAngle, "Get limit angle for merging edges.");
	cls_ShapeFix_Wireframe.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Wireframe::get_type_name, "None");
	cls_ShapeFix_Wireframe.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Wireframe::get_type_descriptor, "None");
	cls_ShapeFix_Wireframe.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Wireframe::*)() const ) &ShapeFix_Wireframe::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_FreeBounds.hxx
	py::class_<ShapeFix_FreeBounds, std::unique_ptr<ShapeFix_FreeBounds, Deleter<ShapeFix_FreeBounds>>> cls_ShapeFix_FreeBounds(mod, "ShapeFix_FreeBounds", "This class is intended to output free bounds of the shape (free bounds are the wires consisting of edges referenced by the only face). For building free bounds it uses ShapeAnalysis_FreeBounds class. This class complements it with the feature to reduce the number of open wires. This reduction is performed with help of connecting several adjacent open wires one to another what can lead to: 1. making an open wire with greater length out of several open wires 2. making closed wire out of several open wires");
	cls_ShapeFix_FreeBounds.def(py::init<>());
	cls_ShapeFix_FreeBounds.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("shape"), py::arg("sewtoler"), py::arg("closetoler"), py::arg("splitclosed"), py::arg("splitopen"));
	cls_ShapeFix_FreeBounds.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("shape"), py::arg("closetoler"), py::arg("splitclosed"), py::arg("splitopen"));
	cls_ShapeFix_FreeBounds.def("GetClosedWires", (const TopoDS_Compound & (ShapeFix_FreeBounds::*)() const ) &ShapeFix_FreeBounds::GetClosedWires, "Returns compound of closed wires out of free edges.");
	cls_ShapeFix_FreeBounds.def("GetOpenWires", (const TopoDS_Compound & (ShapeFix_FreeBounds::*)() const ) &ShapeFix_FreeBounds::GetOpenWires, "Returns compound of open wires out of free edges.");
	cls_ShapeFix_FreeBounds.def("GetShape", (const TopoDS_Shape & (ShapeFix_FreeBounds::*)() const ) &ShapeFix_FreeBounds::GetShape, "Returns modified source shape.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_FaceConnect.hxx
	py::class_<ShapeFix_FaceConnect, std::unique_ptr<ShapeFix_FaceConnect, Deleter<ShapeFix_FaceConnect>>> cls_ShapeFix_FaceConnect(mod, "ShapeFix_FaceConnect", "Rebuilds connectivity between faces in shell");
	cls_ShapeFix_FaceConnect.def(py::init<>());
	cls_ShapeFix_FaceConnect.def("Add", (Standard_Boolean (ShapeFix_FaceConnect::*)(const TopoDS_Face &, const TopoDS_Face &)) &ShapeFix_FaceConnect::Add, "None", py::arg("aFirst"), py::arg("aSecond"));
	cls_ShapeFix_FaceConnect.def("Build", (TopoDS_Shell (ShapeFix_FaceConnect::*)(const TopoDS_Shell &, const Standard_Real, const Standard_Real)) &ShapeFix_FaceConnect::Build, "None", py::arg("shell"), py::arg("sewtoler"), py::arg("fixtoler"));
	cls_ShapeFix_FaceConnect.def("Clear", (void (ShapeFix_FaceConnect::*)()) &ShapeFix_FaceConnect::Clear, "Clears internal data structure");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_Shell.hxx
	py::class_<ShapeFix_Shell, opencascade::handle<ShapeFix_Shell>, ShapeFix_Root> cls_ShapeFix_Shell(mod, "ShapeFix_Shell", "Fixing orientation of faces in shell");
	cls_ShapeFix_Shell.def(py::init<>());
	cls_ShapeFix_Shell.def(py::init<const TopoDS_Shell &>(), py::arg("shape"));
	cls_ShapeFix_Shell.def("Init", (void (ShapeFix_Shell::*)(const TopoDS_Shell &)) &ShapeFix_Shell::Init, "Initializes by shell.", py::arg("shell"));
	cls_ShapeFix_Shell.def("Perform", [](ShapeFix_Shell &self) -> Standard_Boolean { return self.Perform(); });
	cls_ShapeFix_Shell.def("Perform", (Standard_Boolean (ShapeFix_Shell::*)(const opencascade::handle<Message_ProgressIndicator> &)) &ShapeFix_Shell::Perform, "Iterates on subshapes and performs fixes (for each face calls ShapeFix_Face::Perform and then calls FixFaceOrientation). The passed progress indicator allows user to consult the current progress stage and abort algorithm if needed.", py::arg("theProgress"));
	cls_ShapeFix_Shell.def("FixFaceOrientation", [](ShapeFix_Shell &self, const TopoDS_Shell & a0) -> Standard_Boolean { return self.FixFaceOrientation(a0); }, py::arg("shell"));
	cls_ShapeFix_Shell.def("FixFaceOrientation", [](ShapeFix_Shell &self, const TopoDS_Shell & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.FixFaceOrientation(a0, a1); }, py::arg("shell"), py::arg("isAccountMultiConex"));
	cls_ShapeFix_Shell.def("FixFaceOrientation", (Standard_Boolean (ShapeFix_Shell::*)(const TopoDS_Shell &, const Standard_Boolean, const Standard_Boolean)) &ShapeFix_Shell::FixFaceOrientation, "Fixes orientation of faces in shell. Changes orientation of face in the shell, if it is oriented opposite to neigbouring faces. If it is not possible to orient all faces in the shell (like in case of mebious band), this method orients only subset of faces. Other faces are stored in Error compound. Modes : isAccountMultiConex - mode for account cases of multiconnexity. If this mode is equal to Standard_True, separate shells will be created in the cases of multiconnexity. If this mode is equal to Standard_False, one shell will be created without account of multiconnexity.By defautt - Standard_True; NonManifold - mode for creation of non-manifold shells. If this mode is equal to Standard_True one non-manifold will be created from shell contains multishared edges. Else if this mode is equal to Standard_False only manifold shells will be created. By default - Standard_False.", py::arg("shell"), py::arg("isAccountMultiConex"), py::arg("NonManifold"));
	cls_ShapeFix_Shell.def("Shell", (TopoDS_Shell (ShapeFix_Shell::*)()) &ShapeFix_Shell::Shell, "Returns fixed shell (or subset of oriented faces).");
	cls_ShapeFix_Shell.def("Shape", (TopoDS_Shape (ShapeFix_Shell::*)()) &ShapeFix_Shell::Shape, "In case of multiconnexity returns compound of fixed shells else returns one shell..");
	cls_ShapeFix_Shell.def("NbShells", (Standard_Integer (ShapeFix_Shell::*)() const ) &ShapeFix_Shell::NbShells, "Returns Number of obtainrd shells;");
	cls_ShapeFix_Shell.def("ErrorFaces", (TopoDS_Compound (ShapeFix_Shell::*)() const ) &ShapeFix_Shell::ErrorFaces, "Returns not oriented subset of faces.");
	cls_ShapeFix_Shell.def("Status", (Standard_Boolean (ShapeFix_Shell::*)(const ShapeExtend_Status) const ) &ShapeFix_Shell::Status, "Returns the status of the last Fix.", py::arg("status"));
	cls_ShapeFix_Shell.def("FixFaceTool", (opencascade::handle<ShapeFix_Face> (ShapeFix_Shell::*)()) &ShapeFix_Shell::FixFaceTool, "Returns tool for fixing faces.");
	cls_ShapeFix_Shell.def("SetMsgRegistrator", (void (ShapeFix_Shell::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix_Shell::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
	cls_ShapeFix_Shell.def("SetPrecision", (void (ShapeFix_Shell::*)(const Standard_Real)) &ShapeFix_Shell::SetPrecision, "Sets basic precision value (also to FixWireTool)", py::arg("preci"));
	cls_ShapeFix_Shell.def("SetMinTolerance", (void (ShapeFix_Shell::*)(const Standard_Real)) &ShapeFix_Shell::SetMinTolerance, "Sets minimal allowed tolerance (also to FixWireTool)", py::arg("mintol"));
	cls_ShapeFix_Shell.def("SetMaxTolerance", (void (ShapeFix_Shell::*)(const Standard_Real)) &ShapeFix_Shell::SetMaxTolerance, "Sets maximal allowed tolerance (also to FixWireTool)", py::arg("maxtol"));
	cls_ShapeFix_Shell.def("FixFaceMode", (Standard_Integer & (ShapeFix_Shell::*)()) &ShapeFix_Shell::FixFaceMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Face, by default True.");
	cls_ShapeFix_Shell.def("FixOrientationMode", (Standard_Integer & (ShapeFix_Shell::*)()) &ShapeFix_Shell::FixOrientationMode, "Returns (modifiable) the mode for applying FixFaceOrientation, by default True.");
	cls_ShapeFix_Shell.def("SetNonManifoldFlag", (void (ShapeFix_Shell::*)(const Standard_Boolean)) &ShapeFix_Shell::SetNonManifoldFlag, "Sets NonManifold flag", py::arg("isNonManifold"));
	cls_ShapeFix_Shell.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Shell::get_type_name, "None");
	cls_ShapeFix_Shell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Shell::get_type_descriptor, "None");
	cls_ShapeFix_Shell.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Shell::*)() const ) &ShapeFix_Shell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_Solid.hxx
	py::class_<ShapeFix_Solid, opencascade::handle<ShapeFix_Solid>, ShapeFix_Root> cls_ShapeFix_Solid(mod, "ShapeFix_Solid", "Provides method to build a solid from a shells and orients them in order to have a valid solid with finite volume");
	cls_ShapeFix_Solid.def(py::init<>());
	cls_ShapeFix_Solid.def(py::init<const TopoDS_Solid &>(), py::arg("solid"));
	cls_ShapeFix_Solid.def("Init", (void (ShapeFix_Solid::*)(const TopoDS_Solid &)) &ShapeFix_Solid::Init, "Initializes by solid .", py::arg("solid"));
	cls_ShapeFix_Solid.def("Perform", [](ShapeFix_Solid &self) -> Standard_Boolean { return self.Perform(); });
	cls_ShapeFix_Solid.def("Perform", (Standard_Boolean (ShapeFix_Solid::*)(const opencascade::handle<Message_ProgressIndicator> &)) &ShapeFix_Solid::Perform, "Iterates on shells and performs fixes (calls ShapeFix_Shell for each subshell). The passed progress indicator allows user to consult the current progress stage and abort algorithm if needed.", py::arg("theProgress"));
	cls_ShapeFix_Solid.def("SolidFromShell", (TopoDS_Solid (ShapeFix_Solid::*)(const TopoDS_Shell &)) &ShapeFix_Solid::SolidFromShell, "Calls MakeSolid and orients the solid to be 'not infinite'", py::arg("shell"));
	cls_ShapeFix_Solid.def("Status", (Standard_Boolean (ShapeFix_Solid::*)(const ShapeExtend_Status) const ) &ShapeFix_Solid::Status, "Returns the status of the last Fix.", py::arg("status"));
	cls_ShapeFix_Solid.def("Solid", (TopoDS_Shape (ShapeFix_Solid::*)() const ) &ShapeFix_Solid::Solid, "Returns resulting solid.");
	cls_ShapeFix_Solid.def("FixShellTool", (opencascade::handle<ShapeFix_Shell> (ShapeFix_Solid::*)() const ) &ShapeFix_Solid::FixShellTool, "Returns tool for fixing shells.");
	cls_ShapeFix_Solid.def("SetMsgRegistrator", (void (ShapeFix_Solid::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix_Solid::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
	cls_ShapeFix_Solid.def("SetPrecision", (void (ShapeFix_Solid::*)(const Standard_Real)) &ShapeFix_Solid::SetPrecision, "Sets basic precision value (also to FixShellTool)", py::arg("preci"));
	cls_ShapeFix_Solid.def("SetMinTolerance", (void (ShapeFix_Solid::*)(const Standard_Real)) &ShapeFix_Solid::SetMinTolerance, "Sets minimal allowed tolerance (also to FixShellTool)", py::arg("mintol"));
	cls_ShapeFix_Solid.def("SetMaxTolerance", (void (ShapeFix_Solid::*)(const Standard_Real)) &ShapeFix_Solid::SetMaxTolerance, "Sets maximal allowed tolerance (also to FixShellTool)", py::arg("maxtol"));
	cls_ShapeFix_Solid.def("FixShellMode", (Standard_Integer & (ShapeFix_Solid::*)()) &ShapeFix_Solid::FixShellMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Shell, by default True.");
	cls_ShapeFix_Solid.def("FixShellOrientationMode", (Standard_Integer & (ShapeFix_Solid::*)()) &ShapeFix_Solid::FixShellOrientationMode, "Returns (modifiable) the mode for applying analysis and fixes of orientation of shells in the solid; by default True.");
	cls_ShapeFix_Solid.def("CreateOpenSolidMode", (Standard_Boolean & (ShapeFix_Solid::*)()) &ShapeFix_Solid::CreateOpenSolidMode, "Returns (modifiable) the mode for creation of solids. If mode myCreateOpenSolidMode is equal to true solids are created from open shells else solids are created from closed shells only. ShapeFix_Shell, by default False.");
	cls_ShapeFix_Solid.def("Shape", (TopoDS_Shape (ShapeFix_Solid::*)()) &ShapeFix_Solid::Shape, "In case of multiconnexity returns compound of fixed solids else returns one solid.");
	cls_ShapeFix_Solid.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Solid::get_type_name, "None");
	cls_ShapeFix_Solid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Solid::get_type_descriptor, "None");
	cls_ShapeFix_Solid.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Solid::*)() const ) &ShapeFix_Solid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_ShapeTolerance.hxx
	py::class_<ShapeFix_ShapeTolerance, std::unique_ptr<ShapeFix_ShapeTolerance, Deleter<ShapeFix_ShapeTolerance>>> cls_ShapeFix_ShapeTolerance(mod, "ShapeFix_ShapeTolerance", "Modifies tolerances of sub-shapes (vertices, edges, faces)");
	cls_ShapeFix_ShapeTolerance.def(py::init<>());
	cls_ShapeFix_ShapeTolerance.def("LimitTolerance", [](ShapeFix_ShapeTolerance &self, const TopoDS_Shape & a0, const Standard_Real a1) -> Standard_Boolean { return self.LimitTolerance(a0, a1); }, py::arg("shape"), py::arg("tmin"));
	cls_ShapeFix_ShapeTolerance.def("LimitTolerance", [](ShapeFix_ShapeTolerance &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2) -> Standard_Boolean { return self.LimitTolerance(a0, a1, a2); }, py::arg("shape"), py::arg("tmin"), py::arg("tmax"));
	cls_ShapeFix_ShapeTolerance.def("LimitTolerance", (Standard_Boolean (ShapeFix_ShapeTolerance::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const TopAbs_ShapeEnum) const ) &ShapeFix_ShapeTolerance::LimitTolerance, "Limits tolerances in a shape as follows : tmin = tmax -> as SetTolerance (forces) tmin = 0 -> maximum tolerance will be <tmax> tmax = 0 or not given (more generally, tmax < tmin) -> <tmax> ignored, minimum will be <tmin> else, maximum will be <max> and minimum will be <min> styp = VERTEX : only vertices are set styp = EDGE : only edges are set styp = FACE : only faces are set styp = WIRE : to have edges and their vertices set styp = other value : all (vertices,edges,faces) are set Returns True if at least one tolerance of the sub-shape has been modified", py::arg("shape"), py::arg("tmin"), py::arg("tmax"), py::arg("styp"));
	cls_ShapeFix_ShapeTolerance.def("SetTolerance", [](ShapeFix_ShapeTolerance &self, const TopoDS_Shape & a0, const Standard_Real a1) -> void { return self.SetTolerance(a0, a1); }, py::arg("shape"), py::arg("preci"));
	cls_ShapeFix_ShapeTolerance.def("SetTolerance", (void (ShapeFix_ShapeTolerance::*)(const TopoDS_Shape &, const Standard_Real, const TopAbs_ShapeEnum) const ) &ShapeFix_ShapeTolerance::SetTolerance, "Sets (enforces) tolerances in a shape to the given value styp = VERTEX : only vertices are set styp = EDGE : only edges are set styp = FACE : only faces are set styp = WIRE : to have edges and their vertices set styp = other value : all (vertices,edges,faces) are set", py::arg("shape"), py::arg("preci"), py::arg("styp"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_EdgeConnect.hxx
	py::class_<ShapeFix_EdgeConnect, std::unique_ptr<ShapeFix_EdgeConnect, Deleter<ShapeFix_EdgeConnect>>> cls_ShapeFix_EdgeConnect(mod, "ShapeFix_EdgeConnect", "Rebuilds edges to connect with new vertices, was moved from ShapeBuild. Makes vertices to be shared to connect edges, updates positions and tolerances for shared vertices. Accepts edges bounded by two vertices each.");
	cls_ShapeFix_EdgeConnect.def(py::init<>());
	cls_ShapeFix_EdgeConnect.def("Add", (void (ShapeFix_EdgeConnect::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &ShapeFix_EdgeConnect::Add, "Adds information on connectivity between start vertex of second edge and end vertex of first edge, taking edges orientation into account", py::arg("aFirst"), py::arg("aSecond"));
	cls_ShapeFix_EdgeConnect.def("Add", (void (ShapeFix_EdgeConnect::*)(const TopoDS_Shape &)) &ShapeFix_EdgeConnect::Add, "Adds connectivity information for the whole shape. Note: edges in wires must be well ordered Note: flag Closed should be set for closed wires", py::arg("aShape"));
	cls_ShapeFix_EdgeConnect.def("Build", (void (ShapeFix_EdgeConnect::*)()) &ShapeFix_EdgeConnect::Build, "Builds shared vertices, updates their positions and tolerances");
	cls_ShapeFix_EdgeConnect.def("Clear", (void (ShapeFix_EdgeConnect::*)()) &ShapeFix_EdgeConnect::Clear, "Clears internal data structure");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_ComposeShell.hxx
	py::class_<ShapeFix_ComposeShell, opencascade::handle<ShapeFix_ComposeShell>, ShapeFix_Root> cls_ShapeFix_ComposeShell(mod, "ShapeFix_ComposeShell", "This class is intended to create a shell from the composite surface (grid of surfaces) and set of wires. It may be either division of the supporting surface of the face, or creating a shape corresponding to face on composite surface which is missing in CAS.CADE but exists in some other systems.");
	cls_ShapeFix_ComposeShell.def(py::init<>());
	cls_ShapeFix_ComposeShell.def("Init", (void (ShapeFix_ComposeShell::*)(const opencascade::handle<ShapeExtend_CompositeSurface> &, const TopLoc_Location &, const TopoDS_Face &, const Standard_Real)) &ShapeFix_ComposeShell::Init, "Initializes with composite surface, face and precision. Here face defines both set of wires and way of getting pcurves. Precision is used (together with tolerance of edges) for handling subtle cases, such as tangential intersections.", py::arg("Grid"), py::arg("L"), py::arg("Face"), py::arg("Prec"));
	cls_ShapeFix_ComposeShell.def("ClosedMode", (Standard_Boolean & (ShapeFix_ComposeShell::*)()) &ShapeFix_ComposeShell::ClosedMode, "Returns (modifiable) flag for special 'closed' mode which forces ComposeShell to consider all pcurves on closed surface as modulo period. This can reduce reliability, but allows to deal with wires closed in 3d but open in 2d (missing seam) Default is False");
	cls_ShapeFix_ComposeShell.def("Perform", (Standard_Boolean (ShapeFix_ComposeShell::*)()) &ShapeFix_ComposeShell::Perform, "Performs the work on already loaded data.");
	cls_ShapeFix_ComposeShell.def("SplitEdges", (void (ShapeFix_ComposeShell::*)()) &ShapeFix_ComposeShell::SplitEdges, "Splits edges in the original shape by grid. This is a part of Perform() which does not produce any resulting shape; the only result is filled context where splittings are recorded.");
	cls_ShapeFix_ComposeShell.def("Result", (const TopoDS_Shape & (ShapeFix_ComposeShell::*)() const ) &ShapeFix_ComposeShell::Result, "Returns resulting shell or face (or Null shape if not done)");
	cls_ShapeFix_ComposeShell.def("Status", (Standard_Boolean (ShapeFix_ComposeShell::*)(const ShapeExtend_Status) const ) &ShapeFix_ComposeShell::Status, "Queries status of last call to Perform() OK : nothing done (some kind of error) DONE1: splitting is done, at least one new face created DONE2: splitting is done, several new faces obtained FAIL1: misoriented wire encountered (handled) FAIL2: recoverable parity error FAIL3: edge with no pcurve on supporting face FAIL4: unrecoverable algorithm error (parity check)", py::arg("status"));
	cls_ShapeFix_ComposeShell.def("DispatchWires", (void (ShapeFix_ComposeShell::*)(TopTools_SequenceOfShape &, ShapeFix_SequenceOfWireSegment &) const ) &ShapeFix_ComposeShell::DispatchWires, "Creates new faces from the set of (closed) wires. Each wire is put on corresponding patch in the composite surface, and all pcurves on the initial (pseudo)face are reassigned to that surface. If several wires are one inside another, single face is created.", py::arg("faces"), py::arg("wires"));
	cls_ShapeFix_ComposeShell.def("SetTransferParamTool", (void (ShapeFix_ComposeShell::*)(const opencascade::handle<ShapeAnalysis_TransferParameters> &)) &ShapeFix_ComposeShell::SetTransferParamTool, "Sets tool for transfer parameters from 3d to 2d and vice versa.", py::arg("TransferParam"));
	cls_ShapeFix_ComposeShell.def("GetTransferParamTool", (opencascade::handle<ShapeAnalysis_TransferParameters> (ShapeFix_ComposeShell::*)() const ) &ShapeFix_ComposeShell::GetTransferParamTool, "Gets tool for transfer parameters from 3d to 2d and vice versa.");
	cls_ShapeFix_ComposeShell.def_static("get_type_name_", (const char * (*)()) &ShapeFix_ComposeShell::get_type_name, "None");
	cls_ShapeFix_ComposeShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_ComposeShell::get_type_descriptor, "None");
	cls_ShapeFix_ComposeShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_ComposeShell::*)() const ) &ShapeFix_ComposeShell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_SplitCommonVertex.hxx
	py::class_<ShapeFix_SplitCommonVertex, opencascade::handle<ShapeFix_SplitCommonVertex>, ShapeFix_Root> cls_ShapeFix_SplitCommonVertex(mod, "ShapeFix_SplitCommonVertex", "Two wires have common vertex - this case is valid in BRep model and isn't valid in STEP => before writing into STEP it is necessary to split this vertex (each wire must has one vertex)");
	cls_ShapeFix_SplitCommonVertex.def(py::init<>());
	cls_ShapeFix_SplitCommonVertex.def("Init", (void (ShapeFix_SplitCommonVertex::*)(const TopoDS_Shape &)) &ShapeFix_SplitCommonVertex::Init, "None", py::arg("S"));
	cls_ShapeFix_SplitCommonVertex.def("Perform", (void (ShapeFix_SplitCommonVertex::*)()) &ShapeFix_SplitCommonVertex::Perform, "None");
	cls_ShapeFix_SplitCommonVertex.def("Shape", (TopoDS_Shape (ShapeFix_SplitCommonVertex::*)()) &ShapeFix_SplitCommonVertex::Shape, "None");
	cls_ShapeFix_SplitCommonVertex.def_static("get_type_name_", (const char * (*)()) &ShapeFix_SplitCommonVertex::get_type_name, "None");
	cls_ShapeFix_SplitCommonVertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_SplitCommonVertex::get_type_descriptor, "None");
	cls_ShapeFix_SplitCommonVertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_SplitCommonVertex::*)() const ) &ShapeFix_SplitCommonVertex::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_WireSegment.hxx
	py::class_<ShapeFix_WireSegment, std::unique_ptr<ShapeFix_WireSegment, Deleter<ShapeFix_WireSegment>>> cls_ShapeFix_WireSegment(mod, "ShapeFix_WireSegment", "This class is auxiliary class (data storage) used in ComposeShell. It is intended for representing segment of the wire (or whole wire). The segment itself is represented by ShapeExtend_WireData. In addition, some associated data necessary for computations are stored:");
	cls_ShapeFix_WireSegment.def(py::init<>());
	cls_ShapeFix_WireSegment.def(py::init<const opencascade::handle<ShapeExtend_WireData> &>(), py::arg("wire"));
	cls_ShapeFix_WireSegment.def(py::init<const opencascade::handle<ShapeExtend_WireData> &, const TopAbs_Orientation>(), py::arg("wire"), py::arg("ori"));
	// cls_ShapeFix_WireSegment.def(py::init<const TopoDS_Wire &>(), py::arg("wire"));
	// cls_ShapeFix_WireSegment.def(py::init<const TopoDS_Wire &, const TopAbs_Orientation>(), py::arg("wire"), py::arg("ori"));
	cls_ShapeFix_WireSegment.def("Clear", (void (ShapeFix_WireSegment::*)()) &ShapeFix_WireSegment::Clear, "Clears all fields.");
	cls_ShapeFix_WireSegment.def("Load", (void (ShapeFix_WireSegment::*)(const opencascade::handle<ShapeExtend_WireData> &)) &ShapeFix_WireSegment::Load, "Loads wire.", py::arg("wire"));
	cls_ShapeFix_WireSegment.def("WireData", (const opencascade::handle<ShapeExtend_WireData> & (ShapeFix_WireSegment::*)() const ) &ShapeFix_WireSegment::WireData, "Returns wire.");
	cls_ShapeFix_WireSegment.def("Orientation", (void (ShapeFix_WireSegment::*)(const TopAbs_Orientation)) &ShapeFix_WireSegment::Orientation, "Sets orientation flag.", py::arg("ori"));
	cls_ShapeFix_WireSegment.def("Orientation", (TopAbs_Orientation (ShapeFix_WireSegment::*)() const ) &ShapeFix_WireSegment::Orientation, "Returns orientation flag.");
	cls_ShapeFix_WireSegment.def("FirstVertex", (TopoDS_Vertex (ShapeFix_WireSegment::*)() const ) &ShapeFix_WireSegment::FirstVertex, "Returns first vertex of the first edge in the wire (no dependance on Orientation()).");
	cls_ShapeFix_WireSegment.def("LastVertex", (TopoDS_Vertex (ShapeFix_WireSegment::*)() const ) &ShapeFix_WireSegment::LastVertex, "Returns last vertex of the last edge in the wire (no dependance on Orientation()).");
	cls_ShapeFix_WireSegment.def("IsClosed", (Standard_Boolean (ShapeFix_WireSegment::*)() const ) &ShapeFix_WireSegment::IsClosed, "Returns True if FirstVertex() == LastVertex()");
	cls_ShapeFix_WireSegment.def("NbEdges", (Standard_Integer (ShapeFix_WireSegment::*)() const ) &ShapeFix_WireSegment::NbEdges, "Returns Number of edges in the wire");
	cls_ShapeFix_WireSegment.def("Edge", (TopoDS_Edge (ShapeFix_WireSegment::*)(const Standard_Integer) const ) &ShapeFix_WireSegment::Edge, "Returns edge by given index in the wire", py::arg("i"));
	cls_ShapeFix_WireSegment.def("SetEdge", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const TopoDS_Edge &)) &ShapeFix_WireSegment::SetEdge, "Replaces edge at index i by new one.", py::arg("i"), py::arg("edge"));
	cls_ShapeFix_WireSegment.def("AddEdge", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const TopoDS_Edge &)) &ShapeFix_WireSegment::AddEdge, "Insert a new edge with index i and implicitly defined patch indices (indefinite patch). If i==0, edge is inserted at end of wire.", py::arg("i"), py::arg("edge"));
	cls_ShapeFix_WireSegment.def("AddEdge", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const TopoDS_Edge &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::AddEdge, "Insert a new edge with index i and explicitly defined patch indices. If i==0, edge is inserted at end of wire.", py::arg("i"), py::arg("edge"), py::arg("iumin"), py::arg("iumax"), py::arg("ivmin"), py::arg("ivmax"));
	cls_ShapeFix_WireSegment.def("SetPatchIndex", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::SetPatchIndex, "Set patch indices for edge i.", py::arg("i"), py::arg("iumin"), py::arg("iumax"), py::arg("ivmin"), py::arg("ivmax"));
	cls_ShapeFix_WireSegment.def("DefineIUMin", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::DefineIUMin, "None", py::arg("i"), py::arg("iumin"));
	cls_ShapeFix_WireSegment.def("DefineIUMax", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::DefineIUMax, "None", py::arg("i"), py::arg("iumax"));
	cls_ShapeFix_WireSegment.def("DefineIVMin", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::DefineIVMin, "None", py::arg("i"), py::arg("ivmin"));
	cls_ShapeFix_WireSegment.def("DefineIVMax", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::DefineIVMax, "Modify minimal or maximal patch index for edge i. The corresponding patch index for that edge is modified so as to satisfy eq. iumin <= myIUMin(i) <= myIUMax(i) <= iumax", py::arg("i"), py::arg("ivmax"));
	cls_ShapeFix_WireSegment.def("GetPatchIndex", [](ShapeFix_WireSegment &self, const Standard_Integer i, Standard_Integer & iumin, Standard_Integer & iumax, Standard_Integer & ivmin, Standard_Integer & ivmax){ self.GetPatchIndex(i, iumin, iumax, ivmin, ivmax); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(iumin, iumax, ivmin, ivmax); }, "Returns patch indices for edge i.", py::arg("i"), py::arg("iumin"), py::arg("iumax"), py::arg("ivmin"), py::arg("ivmax"));
	cls_ShapeFix_WireSegment.def("CheckPatchIndex", (Standard_Boolean (ShapeFix_WireSegment::*)(const Standard_Integer) const ) &ShapeFix_WireSegment::CheckPatchIndex, "Checks patch indices for edge i to satisfy equations IUMin(i) <= IUMax(i) <= IUMin(i)+1", py::arg("i"));
	cls_ShapeFix_WireSegment.def("SetVertex", (void (ShapeFix_WireSegment::*)(const TopoDS_Vertex &)) &ShapeFix_WireSegment::SetVertex, "None", py::arg("theVertex"));
	cls_ShapeFix_WireSegment.def("GetVertex", (TopoDS_Vertex (ShapeFix_WireSegment::*)() const ) &ShapeFix_WireSegment::GetVertex, "None");
	cls_ShapeFix_WireSegment.def("IsVertex", (Standard_Boolean (ShapeFix_WireSegment::*)() const ) &ShapeFix_WireSegment::IsVertex, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_IntersectionTool.hxx
	py::class_<ShapeFix_IntersectionTool, std::unique_ptr<ShapeFix_IntersectionTool, Deleter<ShapeFix_IntersectionTool>>> cls_ShapeFix_IntersectionTool(mod, "ShapeFix_IntersectionTool", "Tool for fixing selfintersecting wire and intersecting wires");
	cls_ShapeFix_IntersectionTool.def(py::init<const opencascade::handle<ShapeBuild_ReShape> &, const Standard_Real>(), py::arg("context"), py::arg("preci"));
	cls_ShapeFix_IntersectionTool.def(py::init<const opencascade::handle<ShapeBuild_ReShape> &, const Standard_Real, const Standard_Real>(), py::arg("context"), py::arg("preci"), py::arg("maxtol"));
	cls_ShapeFix_IntersectionTool.def("Context", (opencascade::handle<ShapeBuild_ReShape> (ShapeFix_IntersectionTool::*)() const ) &ShapeFix_IntersectionTool::Context, "Returns context");
	cls_ShapeFix_IntersectionTool.def("SplitEdge", (Standard_Boolean (ShapeFix_IntersectionTool::*)(const TopoDS_Edge &, const Standard_Real, const TopoDS_Vertex &, const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Real) const ) &ShapeFix_IntersectionTool::SplitEdge, "Split edge on two new edges using new vertex 'vert' and 'param' - parameter for splitting The 'face' is necessary for pcurves and using TransferParameterProj", py::arg("edge"), py::arg("param"), py::arg("vert"), py::arg("face"), py::arg("newE1"), py::arg("newE2"), py::arg("preci"));
	cls_ShapeFix_IntersectionTool.def("CutEdge", [](ShapeFix_IntersectionTool &self, const TopoDS_Edge & edge, const Standard_Real pend, const Standard_Real cut, const TopoDS_Face & face, Standard_Boolean & iscutline){ Standard_Boolean rv = self.CutEdge(edge, pend, cut, face, iscutline); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, iscutline); }, "Cut edge by parameters pend and cut", py::arg("edge"), py::arg("pend"), py::arg("cut"), py::arg("face"), py::arg("iscutline"));
	cls_ShapeFix_IntersectionTool.def("FixSelfIntersectWire", [](ShapeFix_IntersectionTool &self, opencascade::handle<ShapeExtend_WireData> & sewd, const TopoDS_Face & face, Standard_Integer & NbSplit, Standard_Integer & NbCut, Standard_Integer & NbRemoved){ Standard_Boolean rv = self.FixSelfIntersectWire(sewd, face, NbSplit, NbCut, NbRemoved); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &, Standard_Integer &>(rv, NbSplit, NbCut, NbRemoved); }, "None", py::arg("sewd"), py::arg("face"), py::arg("NbSplit"), py::arg("NbCut"), py::arg("NbRemoved"));
	cls_ShapeFix_IntersectionTool.def("FixIntersectingWires", (Standard_Boolean (ShapeFix_IntersectionTool::*)(TopoDS_Face &) const ) &ShapeFix_IntersectionTool::FixIntersectingWires, "None", py::arg("face"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_SplitTool.hxx
	py::class_<ShapeFix_SplitTool, std::unique_ptr<ShapeFix_SplitTool, Deleter<ShapeFix_SplitTool>>> cls_ShapeFix_SplitTool(mod, "ShapeFix_SplitTool", "Tool for splitting and cutting edges; includes methods used in OverlappingTool and IntersectionTool");
	cls_ShapeFix_SplitTool.def(py::init<>());
	cls_ShapeFix_SplitTool.def("SplitEdge", (Standard_Boolean (ShapeFix_SplitTool::*)(const TopoDS_Edge &, const Standard_Real, const TopoDS_Vertex &, const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Real, const Standard_Real) const ) &ShapeFix_SplitTool::SplitEdge, "Split edge on two new edges using new vertex 'vert' and 'param' - parameter for splitting The 'face' is necessary for pcurves and using TransferParameterProj", py::arg("edge"), py::arg("param"), py::arg("vert"), py::arg("face"), py::arg("newE1"), py::arg("newE2"), py::arg("tol3d"), py::arg("tol2d"));
	cls_ShapeFix_SplitTool.def("SplitEdge", (Standard_Boolean (ShapeFix_SplitTool::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real, const TopoDS_Vertex &, const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Real, const Standard_Real) const ) &ShapeFix_SplitTool::SplitEdge, "Split edge on two new edges using new vertex 'vert' and 'param1' and 'param2' - parameter for splitting and cutting The 'face' is necessary for pcurves and using TransferParameterProj", py::arg("edge"), py::arg("param1"), py::arg("param2"), py::arg("vert"), py::arg("face"), py::arg("newE1"), py::arg("newE2"), py::arg("tol3d"), py::arg("tol2d"));
	cls_ShapeFix_SplitTool.def("CutEdge", [](ShapeFix_SplitTool &self, const TopoDS_Edge & edge, const Standard_Real pend, const Standard_Real cut, const TopoDS_Face & face, Standard_Boolean & iscutline){ Standard_Boolean rv = self.CutEdge(edge, pend, cut, face, iscutline); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, iscutline); }, "Cut edge by parameters pend and cut", py::arg("edge"), py::arg("pend"), py::arg("cut"), py::arg("face"), py::arg("iscutline"));
	cls_ShapeFix_SplitTool.def("SplitEdge", [](ShapeFix_SplitTool &self, const TopoDS_Edge & edge, const Standard_Real fp, const TopoDS_Vertex & V1, const Standard_Real lp, const TopoDS_Vertex & V2, const TopoDS_Face & face, TopTools_SequenceOfShape & SeqE, Standard_Integer & aNum, const opencascade::handle<ShapeBuild_ReShape> & context, const Standard_Real tol3d, const Standard_Real tol2d){ Standard_Boolean rv = self.SplitEdge(edge, fp, V1, lp, V2, face, SeqE, aNum, context, tol3d, tol2d); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, aNum); }, "Split edge on two new edges using two new vertex V1 and V2 and two parameters for splitting - fp and lp correspondingly The 'face' is necessary for pcurves and using TransferParameterProj aNum - number of edge in SeqE which corresponding to [fp,lp]", py::arg("edge"), py::arg("fp"), py::arg("V1"), py::arg("lp"), py::arg("V2"), py::arg("face"), py::arg("SeqE"), py::arg("aNum"), py::arg("context"), py::arg("tol3d"), py::arg("tol2d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix.hxx
	py::class_<ShapeFix, std::unique_ptr<ShapeFix, Deleter<ShapeFix>>> cls_ShapeFix(mod, "ShapeFix", "This package provides algorithms for fixing problematic (violating Open CASCADE requirements) shapes. Tools from package ShapeAnalysis are used for detecting the problems. The detecting and fixing is done taking in account various criteria implemented in BRepCheck package. Each class of package ShapeFix deals with one certain type of shapes or with some family of problems.");
	cls_ShapeFix.def(py::init<>());
	cls_ShapeFix.def_static("SameParameter_", [](const TopoDS_Shape & a0, const Standard_Boolean a1) -> Standard_Boolean { return ShapeFix::SameParameter(a0, a1); }, py::arg("shape"), py::arg("enforce"));
	cls_ShapeFix.def_static("SameParameter_", [](const TopoDS_Shape & a0, const Standard_Boolean a1, const Standard_Real a2) -> Standard_Boolean { return ShapeFix::SameParameter(a0, a1, a2); }, py::arg("shape"), py::arg("enforce"), py::arg("preci"));
	cls_ShapeFix.def_static("SameParameter_", [](const TopoDS_Shape & a0, const Standard_Boolean a1, const Standard_Real a2, const opencascade::handle<Message_ProgressIndicator> & a3) -> Standard_Boolean { return ShapeFix::SameParameter(a0, a1, a2, a3); }, py::arg("shape"), py::arg("enforce"), py::arg("preci"), py::arg("theProgress"));
	cls_ShapeFix.def_static("SameParameter_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Real, const opencascade::handle<Message_ProgressIndicator> &, const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix::SameParameter, "Runs SameParameter from BRepLib with these adaptations : <enforce> forces computations, else they are made only on Edges with flag SameParameter false <preci>, if not precised, is taken for each EDge as its own Tolerance Returns True when done, False if an exception has been raised In case of exception anyway, as many edges as possible have been processed. The passed progress indicator allows user to consult the current progress stage and abort algorithm if needed.", py::arg("shape"), py::arg("enforce"), py::arg("preci"), py::arg("theProgress"), py::arg("theMsgReg"));
	cls_ShapeFix.def_static("EncodeRegularity_", [](const TopoDS_Shape & a0) -> void { return ShapeFix::EncodeRegularity(a0); }, py::arg("shape"));
	cls_ShapeFix.def_static("EncodeRegularity_", (void (*)(const TopoDS_Shape &, const Standard_Real)) &ShapeFix::EncodeRegularity, "Runs EncodeRegularity from BRepLib taking into account shared components of assemblies, so that each component is processed only once", py::arg("shape"), py::arg("tolang"));
	cls_ShapeFix.def_static("RemoveSmallEdges_", (TopoDS_Shape (*)(TopoDS_Shape &, const Standard_Real, opencascade::handle<ShapeBuild_ReShape> &)) &ShapeFix::RemoveSmallEdges, "Removes edges which are less than given tolerance from shape with help of ShapeFix_Wire::FixSmall()", py::arg("shape"), py::arg("Tolerance"), py::arg("context"));
	cls_ShapeFix.def_static("FixVertexPosition_", (Standard_Boolean (*)(TopoDS_Shape &, const Standard_Real, const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeFix::FixVertexPosition, "Fix position of the vertices having tolerance more tnan specified one.;", py::arg("theshape"), py::arg("theTolerance"), py::arg("thecontext"));
	cls_ShapeFix.def_static("LeastEdgeSize_", (Standard_Real (*)(TopoDS_Shape &)) &ShapeFix::LeastEdgeSize, "Calculate size of least edge;", py::arg("theshape"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_DataMapOfShapeBox2d.hxx
	bind_NCollection_DataMap<TopoDS_Shape, Bnd_Box2d, TopTools_ShapeMapHasher>(mod, "ShapeFix_DataMapOfShapeBox2d");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeFix_SequenceOfWireSegment.hxx
	bind_NCollection_Sequence<ShapeFix_WireSegment>(mod, "ShapeFix_SequenceOfWireSegment");


}
