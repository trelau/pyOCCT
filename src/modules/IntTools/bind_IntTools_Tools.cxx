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
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <TopoDS_Edge.hxx>
#include <IntTools_CommonPrt.hxx>
#include <gp_Pnt.hxx>
#include <IntTools_Curve.hxx>
#include <IntTools_SequenceOfCurves.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Bnd_Box.hxx>
#include <IntTools_Range.hxx>
#include <gp_Lin.hxx>
#include <gp_Pln.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Precision.hxx>
#include <IntTools_Tools.hxx>

void bind_IntTools_Tools(py::module &mod){

py::class_<IntTools_Tools, std::unique_ptr<IntTools_Tools>> cls_IntTools_Tools(mod, "IntTools_Tools", "The class contains handy static functions dealing with the geometry and topology.");

// Constructors

// Fields

// Methods
// cls_IntTools_Tools.def_static("operator new_", (void * (*)(size_t)) &IntTools_Tools::operator new, "None", py::arg("theSize"));
// cls_IntTools_Tools.def_static("operator delete_", (void (*)(void *)) &IntTools_Tools::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_Tools.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_Tools::operator new[], "None", py::arg("theSize"));
// cls_IntTools_Tools.def_static("operator delete[]_", (void (*)(void *)) &IntTools_Tools::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_Tools.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_Tools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_Tools.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_Tools::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_Tools.def_static("ComputeVV_", (Standard_Integer (*)(const TopoDS_Vertex &, const TopoDS_Vertex &)) &IntTools_Tools::ComputeVV, "Computes distance between vertex V1 and vertex V2, if the distance is less than sum of vertex tolerances returns zero, otherwise returns negative value", py::arg("V1"), py::arg("V2"));
cls_IntTools_Tools.def_static("HasInternalEdge_", (Standard_Boolean (*)(const TopoDS_Wire &)) &IntTools_Tools::HasInternalEdge, "Returns True if wire aW contains edges with INTERNAL orientation", py::arg("aW"));
cls_IntTools_Tools.def_static("MakeFaceFromWireAndFace_", (void (*)(const TopoDS_Wire &, const TopoDS_Face &, TopoDS_Face &)) &IntTools_Tools::MakeFaceFromWireAndFace, "Build a face based on surface of given face aF and bounded by wire aW", py::arg("aW"), py::arg("aF"), py::arg("aFNew"));
cls_IntTools_Tools.def_static("ClassifyPointByFace_", (TopAbs_State (*)(const TopoDS_Face &, const gp_Pnt2d &)) &IntTools_Tools::ClassifyPointByFace, "None", py::arg("aF"), py::arg("P"));
cls_IntTools_Tools.def_static("IsVertex_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real)) &IntTools_Tools::IsVertex, "Computes square distance between a point on the edge E corresponded to parameter t and vertices of edge E. Returns True if this distance is less than square tolerance of vertex, otherwise returns false.", py::arg("E"), py::arg("t"));
cls_IntTools_Tools.def_static("IsVertex_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Vertex &, const Standard_Real)) &IntTools_Tools::IsVertex, "Returns True if square distance between vertex V and a point on the edge E corresponded to parameter t is less than square tolerance of V", py::arg("E"), py::arg("V"), py::arg("t"));
cls_IntTools_Tools.def_static("IsVertex_", (Standard_Boolean (*)(const IntTools_CommonPrt &)) &IntTools_Tools::IsVertex, "Returns True if IsVertx for middle parameter of fist range and first edge returns True and if IsVertex for middle parameter of second range and second range returns True, otherwise returns False", py::arg("aCmnPrt"));
cls_IntTools_Tools.def_static("IsMiddlePointsEqual_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Edge &)) &IntTools_Tools::IsMiddlePointsEqual, "Gets boundary of parameters of E1 and E2. Computes 3d points on each corresponded to average parameters. Returns True if distance between computed points is less than sum of edge tolerance, otherwise returns False.", py::arg("E1"), py::arg("E2"));
cls_IntTools_Tools.def_static("IsVertex_", (Standard_Boolean (*)(const gp_Pnt &, const Standard_Real, const TopoDS_Vertex &)) &IntTools_Tools::IsVertex, "Returns True if the distance between point aP and vertex aV is less or equal to sum of aTolPV and vertex tolerance, otherwise returns False", py::arg("aP"), py::arg("aTolPV"), py::arg("aV"));
cls_IntTools_Tools.def_static("IntermediatePoint_", (Standard_Real (*)(const Standard_Real, const Standard_Real)) &IntTools_Tools::IntermediatePoint, "Returns some value between aFirst and aLast", py::arg("aFirst"), py::arg("aLast"));
cls_IntTools_Tools.def_static("SplitCurve_", (Standard_Integer (*)(const IntTools_Curve &, IntTools_SequenceOfCurves &)) &IntTools_Tools::SplitCurve, "Split aC by average parameter if aC is closed in 3D. Returns positive value if splitting has been done, otherwise returns zero.", py::arg("aC"), py::arg("aS"));
cls_IntTools_Tools.def_static("RejectLines_", (void (*)(const IntTools_SequenceOfCurves &, IntTools_SequenceOfCurves &)) &IntTools_Tools::RejectLines, "Puts curves from aSIn to aSOut except those curves that are coincide with first curve from aSIn.", py::arg("aSIn"), py::arg("aSOut"));
cls_IntTools_Tools.def_static("IsDirsCoinside_", (Standard_Boolean (*)(const gp_Dir &, const gp_Dir &)) &IntTools_Tools::IsDirsCoinside, "Returns True if D1 and D2 coinside", py::arg("D1"), py::arg("D2"));
cls_IntTools_Tools.def_static("IsDirsCoinside_", (Standard_Boolean (*)(const gp_Dir &, const gp_Dir &, const Standard_Real)) &IntTools_Tools::IsDirsCoinside, "Returns True if D1 and D2 coinside with given tolerance", py::arg("D1"), py::arg("D2"), py::arg("aTol"));
cls_IntTools_Tools.def_static("IsClosed_", (Standard_Boolean (*)(const opencascade::handle<Geom_Curve> &)) &IntTools_Tools::IsClosed, "Returns True if aC is BoundedCurve from Geom and the distance between first point of the curve aC and last point is less than 1.e-12", py::arg("aC"));
cls_IntTools_Tools.def_static("CurveTolerance_", (Standard_Real (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real)) &IntTools_Tools::CurveTolerance, "Returns adaptive tolerance for given aTolBase if aC is trimmed curve and basis curve is parabola, otherwise returns value of aTolBase", py::arg("aC"), py::arg("aTolBase"));
cls_IntTools_Tools.def_static("CheckCurve_", (Standard_Boolean (*)(const IntTools_Curve &, Bnd_Box &)) &IntTools_Tools::CheckCurve, "Checks if the curve is not covered by the default tolerance (confusion). Builds bounding box for the curve and stores it into <theBox>.", py::arg("theCurve"), py::arg("theBox"));
cls_IntTools_Tools.def_static("IsOnPave_", (Standard_Boolean (*)(const Standard_Real, const IntTools_Range &, const Standard_Real)) &IntTools_Tools::IsOnPave, "None", py::arg("theT"), py::arg("theRange"), py::arg("theTol"));
cls_IntTools_Tools.def_static("VertexParameters_", [](const IntTools_CommonPrt & theCP, Standard_Real & theT1, Standard_Real & theT2){ IntTools_Tools::VertexParameters(theCP, theT1, theT2); return std::tuple<Standard_Real &, Standard_Real &>(theT1, theT2); }, "None", py::arg("theCP"), py::arg("theT1"), py::arg("theT2"));
cls_IntTools_Tools.def_static("VertexParameter_", [](const IntTools_CommonPrt & theCP, Standard_Real & theT){ IntTools_Tools::VertexParameter(theCP, theT); return theT; }, "None", py::arg("theCP"), py::arg("theT"));
cls_IntTools_Tools.def_static("IsOnPave1_", (Standard_Boolean (*)(const Standard_Real, const IntTools_Range &, const Standard_Real)) &IntTools_Tools::IsOnPave1, "None", py::arg("theT"), py::arg("theRange"), py::arg("theTol"));
cls_IntTools_Tools.def_static("IsInRange_", (Standard_Boolean (*)(const IntTools_Range &, const IntTools_Range &, const Standard_Real)) &IntTools_Tools::IsInRange, "Checks if the range <theR> interfere with the range <theRRef>", py::arg("theRRef"), py::arg("theR"), py::arg("theTol"));
cls_IntTools_Tools.def_static("SegPln_", [](const gp_Lin & theLin, const Standard_Real theTLin1, const Standard_Real theTLin2, const Standard_Real theTolLin, const gp_Pln & thePln, const Standard_Real theTolPln, gp_Pnt & theP, Standard_Real & theT, Standard_Real & theTolP, Standard_Real & theTmin, Standard_Real & theTmax){ Standard_Integer rv = IntTools_Tools::SegPln(theLin, theTLin1, theTLin2, theTolLin, thePln, theTolPln, theP, theT, theTolP, theTmin, theTmax); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(rv, theT, theTolP, theTmin, theTmax); }, "None", py::arg("theLin"), py::arg("theTLin1"), py::arg("theTLin2"), py::arg("theTolLin"), py::arg("thePln"), py::arg("theTolPln"), py::arg("theP"), py::arg("theT"), py::arg("theTolP"), py::arg("theTmin"), py::arg("theTmax"));
cls_IntTools_Tools.def_static("ComputeTolerance_", [](const opencascade::handle<Geom_Curve> & theCurve3D, const opencascade::handle<Geom2d_Curve> & theCurve2D, const opencascade::handle<Geom_Surface> & theSurf, const Standard_Real theFirst, const Standard_Real theLast, Standard_Real & theMaxDist, Standard_Real & theMaxPar, const Standard_Real theTolRange){ Standard_Boolean rv = IntTools_Tools::ComputeTolerance(theCurve3D, theCurve2D, theSurf, theFirst, theLast, theMaxDist, theMaxPar, theTolRange); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theMaxDist, theMaxPar); }, "Computes the max distance between points taken from 3D and 2D curves by the same parameter", py::arg("theCurve3D"), py::arg("theCurve2D"), py::arg("theSurf"), py::arg("theFirst"), py::arg("theLast"), py::arg("theMaxDist"), py::arg("theMaxPar"), py::arg("theTolRange"));
cls_IntTools_Tools.def_static("ComputeIntRange_", (Standard_Real (*)(const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_Tools::ComputeIntRange, "Computes the correct Intersection range for Line/Line, Line/Plane and Plane/Plane intersections", py::arg("theTol1"), py::arg("theTol2"), py::arg("theAngle"));

// Enums

}