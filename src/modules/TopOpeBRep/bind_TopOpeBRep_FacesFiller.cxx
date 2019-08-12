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
#include <TopOpeBRepTool_ShapeClassifier.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRep_FacesIntersector.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopOpeBRep_PointClassifier.hxx>
#include <TopOpeBRepTool_PShapeClassifier.hxx>
#include <TopOpeBRep_LineInter.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRep_VPointInter.hxx>
#include <TopOpeBRep_VPointInterClassifier.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRep_FacesFiller.hxx>
#include <TopOpeBRep_VPointInterIterator.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRep_PFacesIntersector.hxx>
#include <TopOpeBRepDS_PDataStructure.hxx>
#include <TopOpeBRep_PLineInter.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopOpeBRep_FFDumper.hxx>

void bind_TopOpeBRep_FacesFiller(py::module &mod){

py::class_<TopOpeBRep_FacesFiller, std::unique_ptr<TopOpeBRep_FacesFiller, Deleter<TopOpeBRep_FacesFiller>>> cls_TopOpeBRep_FacesFiller(mod, "TopOpeBRep_FacesFiller", "Fills a DataStructure from TopOpeBRepDS with the result of Face/Face instersection described by FacesIntersector from TopOpeBRep. if the faces have same Domain, record it in the DS. else record lines and points and attach list of interferences to the faces, the lines and the edges.");

// Constructors
cls_TopOpeBRep_FacesFiller.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_FacesFiller.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_FacesFiller::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_FacesFiller.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_FacesFiller::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_FacesFiller.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_FacesFiller::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_FacesFiller.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_FacesFiller::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_FacesFiller.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_FacesFiller::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_FacesFiller.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_FacesFiller::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_FacesFiller.def("Insert", (void (TopOpeBRep_FacesFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopOpeBRep_FacesIntersector &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_FacesFiller::Insert, "Stores in <DS> the intersections of <S1> and <S2>.", py::arg("F1"), py::arg("F2"), py::arg("FACINT"), py::arg("HDS"));
cls_TopOpeBRep_FacesFiller.def("ProcessSectionEdges", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ProcessSectionEdges, "None");
cls_TopOpeBRep_FacesFiller.def("ChangePointClassifier", (TopOpeBRep_PointClassifier & (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ChangePointClassifier, "None");
cls_TopOpeBRep_FacesFiller.def("PShapeClassifier", (TopOpeBRepTool_PShapeClassifier (TopOpeBRep_FacesFiller::*)() const) &TopOpeBRep_FacesFiller::PShapeClassifier, "return field myPShapeClassifier.");
cls_TopOpeBRep_FacesFiller.def("SetPShapeClassifier", (void (TopOpeBRep_FacesFiller::*)(const TopOpeBRepTool_PShapeClassifier &)) &TopOpeBRep_FacesFiller::SetPShapeClassifier, "set field myPShapeClassifier.", py::arg("PSC"));
cls_TopOpeBRep_FacesFiller.def("LoadLine", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_LineInter &)) &TopOpeBRep_FacesFiller::LoadLine, "None", py::arg("L"));
cls_TopOpeBRep_FacesFiller.def("CheckLine", (Standard_Boolean (TopOpeBRep_FacesFiller::*)(TopOpeBRep_LineInter &) const) &TopOpeBRep_FacesFiller::CheckLine, "None", py::arg("L"));
cls_TopOpeBRep_FacesFiller.def("VP_Position", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_FacesIntersector &)) &TopOpeBRep_FacesFiller::VP_Position, "compute position of VPoints of lines", py::arg("FACINT"));
cls_TopOpeBRep_FacesFiller.def("VP_Position", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_LineInter &)) &TopOpeBRep_FacesFiller::VP_Position, "compute position of VPoints of line L", py::arg("L"));
cls_TopOpeBRep_FacesFiller.def("VP_PositionOnL", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_LineInter &)) &TopOpeBRep_FacesFiller::VP_PositionOnL, "compute position of VPoints of non-restriction line L.", py::arg("L"));
cls_TopOpeBRep_FacesFiller.def("VP_PositionOnR", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_LineInter &)) &TopOpeBRep_FacesFiller::VP_PositionOnR, "compute position of VPoints of restriction line L.", py::arg("L"));
cls_TopOpeBRep_FacesFiller.def("VP_Position", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_VPointInter &, TopOpeBRep_VPointInterClassifier &)) &TopOpeBRep_FacesFiller::VP_Position, "compute position of VP with current faces, according to VP.ShapeIndex() .", py::arg("VP"), py::arg("VPC"));
cls_TopOpeBRep_FacesFiller.def("ProcessLine", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ProcessLine, "Process current intersection line (set by LoadLine)");
cls_TopOpeBRep_FacesFiller.def("ResetDSC", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ResetDSC, "None");
cls_TopOpeBRep_FacesFiller.def("ProcessRLine", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ProcessRLine, "Process current restriction line, adding restriction edge and computing face/edge interference.");
cls_TopOpeBRep_FacesFiller.def("FillLineVPonR", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::FillLineVPonR, "VP processing for restriction line and line sharing same domain with section edges : - if restriction : Adds restriction edges as section edges and compute face/edge interference. - if same domain : If line share same domain with section edges, compute parts of line IN/IN the two faces, and compute curve/point interference for VP boundaries.");
cls_TopOpeBRep_FacesFiller.def("FillLine", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::FillLine, "None");
cls_TopOpeBRep_FacesFiller.def("AddShapesLine", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::AddShapesLine, "compute 3d curve, pcurves and face/curve interferences for current NDSC. Add them to the DS.");
cls_TopOpeBRep_FacesFiller.def("GetESL", (void (TopOpeBRep_FacesFiller::*)(TopTools_ListOfShape &)) &TopOpeBRep_FacesFiller::GetESL, "Get map <mapES > of restriction edges having parts IN one of the 2 faces.", py::arg("LES"));
cls_TopOpeBRep_FacesFiller.def("ProcessVPR", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_FacesFiller &, const TopOpeBRep_VPointInter &)) &TopOpeBRep_FacesFiller::ProcessVPR, "calling the followings ProcessVPIonR and ProcessVPonR.", py::arg("FF"), py::arg("VP"));
cls_TopOpeBRep_FacesFiller.def("ProcessVPIonR", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_VPointInterIterator &, const TopOpeBRepDS_Transition &, const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRep_FacesFiller::ProcessVPIonR, "processing ProcessVPonR for VPI.", py::arg("VPI"), py::arg("trans1"), py::arg("F1"), py::arg("ShapeIndex"));
cls_TopOpeBRep_FacesFiller.def("ProcessVPonR", (void (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_VPointInter &, const TopOpeBRepDS_Transition &, const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRep_FacesFiller::ProcessVPonR, "adds <VP>'s geometric point (if not stored) and computes (curve or edge)/(point or vertex) interference.", py::arg("VP"), py::arg("trans1"), py::arg("F1"), py::arg("ShapeIndex"));
cls_TopOpeBRep_FacesFiller.def("ProcessVPonclosingR", (void (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_VPointInter &, const TopoDS_Shape &, const Standard_Integer, const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Boolean, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRep_FacesFiller::ProcessVPonclosingR, "VP processing on closing arc.", py::arg("VP"), py::arg("F1"), py::arg("ShapeIndex"), py::arg("transEdge"), py::arg("PVKind"), py::arg("PVIndex"), py::arg("EPIfound"), py::arg("IEPI"));
cls_TopOpeBRep_FacesFiller.def("ProcessVPondgE", [](TopOpeBRep_FacesFiller &self, const TopOpeBRep_VPointInter & VP, const Standard_Integer ShapeIndex, TopOpeBRepDS_Kind & PVKind, Standard_Integer & PVIndex, Standard_Boolean & EPIfound, opencascade::handle<TopOpeBRepDS_Interference> & IEPI, Standard_Boolean & CPIfound, opencascade::handle<TopOpeBRepDS_Interference> & ICPI){ Standard_Boolean rv = self.ProcessVPondgE(VP, ShapeIndex, PVKind, PVIndex, EPIfound, IEPI, CPIfound, ICPI); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Boolean &, Standard_Boolean &>(rv, PVIndex, EPIfound, CPIfound); }, "VP processing on degenerated arc.", py::arg("VP"), py::arg("ShapeIndex"), py::arg("PVKind"), py::arg("PVIndex"), py::arg("EPIfound"), py::arg("IEPI"), py::arg("CPIfound"), py::arg("ICPI"));
cls_TopOpeBRep_FacesFiller.def("ProcessVPInotonR", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_VPointInterIterator &)) &TopOpeBRep_FacesFiller::ProcessVPInotonR, "processing ProcessVPnotonR for VPI.", py::arg("VPI"));
cls_TopOpeBRep_FacesFiller.def("ProcessVPnotonR", (void (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_VPointInter &)) &TopOpeBRep_FacesFiller::ProcessVPnotonR, "adds <VP>'s geometrical point to the DS (if not stored) and computes curve point interference.", py::arg("VP"));
cls_TopOpeBRep_FacesFiller.def("GetGeometry", [](TopOpeBRep_FacesFiller &self, TopOpeBRepDS_ListIteratorOfListOfInterference & IT, const TopOpeBRep_VPointInter & VP, Standard_Integer & G, TopOpeBRepDS_Kind & K){ Standard_Boolean rv = self.GetGeometry(IT, VP, G, K); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, G); }, "Get the geometry of a DS point <DSP>. Search for it with ScanInterfList (previous method). if found, set <G> to the geometry of the interference found. else, add the point <DSP> in the <DS> and set <G> to the value of the new geometry such created. returns the value of ScanInterfList().", py::arg("IT"), py::arg("VP"), py::arg("G"), py::arg("K"));
cls_TopOpeBRep_FacesFiller.def("MakeGeometry", (Standard_Integer (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_VPointInter &, const Standard_Integer, TopOpeBRepDS_Kind &)) &TopOpeBRep_FacesFiller::MakeGeometry, "None", py::arg("VP"), py::arg("ShapeIndex"), py::arg("K"));
cls_TopOpeBRep_FacesFiller.def("StoreCurveInterference", (void (TopOpeBRep_FacesFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRep_FacesFiller::StoreCurveInterference, "Add interference <I> to list myDSCIL. on a given line, at first call, add a new DS curve.", py::arg("I"));
cls_TopOpeBRep_FacesFiller.def("GetFFGeometry", [](TopOpeBRep_FacesFiller &self, const TopOpeBRepDS_Point & DSP, TopOpeBRepDS_Kind & K, Standard_Integer & G){ Standard_Boolean rv = self.GetFFGeometry(DSP, K, G); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, G); }, "search for G = geometry of Point which is identical to <DSP> among the DS Points created in the CURRENT face/face intersection ( current Insert() call).", py::arg("DSP"), py::arg("K"), py::arg("G"));
cls_TopOpeBRep_FacesFiller.def("GetFFGeometry", [](TopOpeBRep_FacesFiller &self, const TopOpeBRep_VPointInter & VP, TopOpeBRepDS_Kind & K, Standard_Integer & G){ Standard_Boolean rv = self.GetFFGeometry(VP, K, G); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, G); }, "search for G = geometry of Point which is identical to <VP> among the DS Points created in the CURRENT face/face intersection ( current Insert() call).", py::arg("VP"), py::arg("K"), py::arg("G"));
cls_TopOpeBRep_FacesFiller.def("ChangeFacesIntersector", (TopOpeBRep_FacesIntersector & (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ChangeFacesIntersector, "None");
cls_TopOpeBRep_FacesFiller.def("HDataStructure", (opencascade::handle<TopOpeBRepDS_HDataStructure> (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::HDataStructure, "None");
cls_TopOpeBRep_FacesFiller.def("ChangeDataStructure", (TopOpeBRepDS_DataStructure & (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ChangeDataStructure, "None");
cls_TopOpeBRep_FacesFiller.def("Face", (const TopoDS_Face & (TopOpeBRep_FacesFiller::*)(const Standard_Integer) const) &TopOpeBRep_FacesFiller::Face, "None", py::arg("I"));
cls_TopOpeBRep_FacesFiller.def("FaceFaceTransition", (const TopOpeBRepDS_Transition & (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_LineInter &, const Standard_Integer) const) &TopOpeBRep_FacesFiller::FaceFaceTransition, "None", py::arg("L"), py::arg("I"));
cls_TopOpeBRep_FacesFiller.def("FaceFaceTransition", (const TopOpeBRepDS_Transition & (TopOpeBRep_FacesFiller::*)(const Standard_Integer) const) &TopOpeBRep_FacesFiller::FaceFaceTransition, "None", py::arg("I"));
cls_TopOpeBRep_FacesFiller.def("PFacesIntersectorDummy", (TopOpeBRep_PFacesIntersector (TopOpeBRep_FacesFiller::*)() const) &TopOpeBRep_FacesFiller::PFacesIntersectorDummy, "None");
cls_TopOpeBRep_FacesFiller.def("PDataStructureDummy", (TopOpeBRepDS_PDataStructure (TopOpeBRep_FacesFiller::*)() const) &TopOpeBRep_FacesFiller::PDataStructureDummy, "None");
cls_TopOpeBRep_FacesFiller.def("PLineInterDummy", (TopOpeBRep_PLineInter (TopOpeBRep_FacesFiller::*)() const) &TopOpeBRep_FacesFiller::PLineInterDummy, "None");
cls_TopOpeBRep_FacesFiller.def("SetTraceIndex", (void (TopOpeBRep_FacesFiller::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRep_FacesFiller::SetTraceIndex, "None", py::arg("exF1"), py::arg("exF2"));
cls_TopOpeBRep_FacesFiller.def("GetTraceIndex", [](TopOpeBRep_FacesFiller &self, Standard_Integer & exF1, Standard_Integer & exF2){ self.GetTraceIndex(exF1, exF2); return std::tuple<Standard_Integer &, Standard_Integer &>(exF1, exF2); }, "None", py::arg("exF1"), py::arg("exF2"));
cls_TopOpeBRep_FacesFiller.def_static("Lminmax_", [](const TopOpeBRep_LineInter & L, Standard_Real & pmin, Standard_Real & pmax){ TopOpeBRep_FacesFiller::Lminmax(L, pmin, pmax); return std::tuple<Standard_Real &, Standard_Real &>(pmin, pmax); }, "Computes <pmin> and <pmax> the upper and lower bounds of <L> enclosing all vpoints.", py::arg("L"), py::arg("pmin"), py::arg("pmax"));
cls_TopOpeBRep_FacesFiller.def_static("LSameDomainERL_", (Standard_Boolean (*)(const TopOpeBRep_LineInter &, const TopTools_ListOfShape &)) &TopOpeBRep_FacesFiller::LSameDomainERL, "Returns <True> if <L> shares a same geometric domain with at least one of the section edges of <ERL>.", py::arg("L"), py::arg("ERL"));
cls_TopOpeBRep_FacesFiller.def_static("IsVPtransLok_", (Standard_Boolean (*)(const TopOpeBRep_LineInter &, const Standard_Integer, const Standard_Integer, TopOpeBRepDS_Transition &)) &TopOpeBRep_FacesFiller::IsVPtransLok, "Computes the transition <T> of the VPoint <iVP> on the edge of <SI12>. Returns <False> if the status is unknown.", py::arg("L"), py::arg("iVP"), py::arg("SI12"), py::arg("T"));
cls_TopOpeBRep_FacesFiller.def_static("TransvpOK_", (Standard_Boolean (*)(const TopOpeBRep_LineInter &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TopOpeBRep_FacesFiller::TransvpOK, "Computes transition on line for VP<iVP> on edge restriction of <SI>. If <isINOUT> : returns <true> if transition computed is IN/OUT else : returns <true> if transition computed is OUT/IN.", py::arg("L"), py::arg("iVP"), py::arg("SI"), py::arg("isINOUT"));
cls_TopOpeBRep_FacesFiller.def_static("VPParamOnER_", (Standard_Real (*)(const TopOpeBRep_VPointInter &, const TopOpeBRep_LineInter &)) &TopOpeBRep_FacesFiller::VPParamOnER, "Returns parameter u of vp on the restriction edge.", py::arg("vp"), py::arg("Lrest"));
cls_TopOpeBRep_FacesFiller.def_static("EqualpPonR_", (Standard_Boolean (*)(const TopOpeBRep_LineInter &, const TopOpeBRep_VPointInter &, const TopOpeBRep_VPointInter &)) &TopOpeBRep_FacesFiller::EqualpPonR, "None", py::arg("Lrest"), py::arg("VP1"), py::arg("VP2"));

// Enums

}