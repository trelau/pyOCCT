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
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <GeomAbs_CurveType.hxx>
#include <IntTools_Curve.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <IntTools_Context.hxx>
#include <Bnd_Box.hxx>
#include <IntTools_ShrunkRange.hxx>
#include <Standard_Transient.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <IntTools_FClass2d.hxx>
#include <TopoDS_Face.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <GeomAPI_ProjectPointOnCurve.hxx>
#include <IntTools_SurfaceRangeLocalizeData.hxx>
#include <BRepClass3d_SolidClassifier.hxx>
#include <TopoDS_Solid.hxx>
#include <Geom2dHatch_Hatcher.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <Bnd_OBB.hxx>
#include <TopoDS_Shape.hxx>
#include <Precision.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <NCollection_DataMap.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <IntTools_Range.hxx>
#include <NCollection_Sequence.hxx>
#include <IntTools_SequenceOfRanges.hxx>
#include <IntTools_CommonPrt.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <IntTools_Root.hxx>
#include <IntTools_SequenceOfRoots.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <IntTools_CArray1OfReal.hxx>
#include <IntTools_EdgeEdge.hxx>
#include <IntTools_EdgeFace.hxx>
#include <IntTools_MarkedRangeSet.hxx>
#include <IntTools_BaseRangeSample.hxx>
#include <IntTools_CurveRangeSample.hxx>
#include <IntTools_SurfaceRangeSample.hxx>
#include <IntTools_CurveRangeLocalizeData.hxx>
#include <IntTools_BeanFaceIntersector.hxx>
#include <IntTools_PntOnFace.hxx>
#include <IntTools_PntOn2Faces.hxx>
#include <IntTools_TopolTool.hxx>
#include <IntTools_FaceFace.hxx>
#include <IntTools_Tools.hxx>
#include <IntTools_CArray1OfInteger.hxx>
#include <IntTools_CurveRangeSampleMapHasher.hxx>
#include <IntTools_SurfaceRangeSampleMapHasher.hxx>
#include <IntTools.hxx>
#include <NCollection_Array1.hxx>
#include <IntTools_Array1OfRange.hxx>
#include <IntTools_Array1OfRoots.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <NCollection_List.hxx>
#include <IntTools_ListOfCurveRangeSample.hxx>
#include <IntTools_ListOfSurfaceRangeSample.hxx>
#include <Geom_Surface.hxx>
#include <Extrema_ExtCS.hxx>
#include <NCollection_Map.hxx>
#include <IntTools_MapOfCurveSample.hxx>
#include <IntTools_DataMapOfCurveSampleBox.hxx>
#include <IntTools_DataMapOfSurfaceSampleBox.hxx>
#include <IntTools_SequenceOfCommonPrts.hxx>
#include <IntTools_SequenceOfCurves.hxx>
#include <IntTools_SequenceOfPntOn2Faces.hxx>
#include <IntSurf_ListOfPntOn2S.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <IntPatch_Intersection.hxx>
#include <GeomInt_LineConstructor.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <BRepTopAdaptor_SeqOfPtr.hxx>
#include <BRepClass_FaceExplorer.hxx>
#include <IntTools_ListOfBox.hxx>
#include <IntTools_MapOfSurfaceSample.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TopoDS_Wire.hxx>
#include <gp_Dir.hxx>
#include <gp_Lin.hxx>
#include <gp_Pln.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntPatch_WLine.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <IntTools_WLineTool.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_Map.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(IntTools, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.GeomAPI");
py::module::import("OCCT.BRepClass3d");
py::module::import("OCCT.Geom2dHatch");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.Precision");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.IntSurf");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.IntPatch");
py::module::import("OCCT.GeomInt");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.BRepTopAdaptor");
py::module::import("OCCT.BRepClass");
py::module::import("OCCT.TColgp");

// CLASS: INTTOOLS_CURVE
py::class_<IntTools_Curve> cls_IntTools_Curve(mod, "IntTools_Curve", "The class is a container of one 3D curve, two 2D curves and two Tolerance values. It is used in the Face/Face intersection algorithm to store the results of intersection. In this context: **the 3D curve** is the intersection curve; **the 2D curves** are the PCurves of the 3D curve on the intersecting faces; **the tolerance** is the valid tolerance for 3D curve computed as maximal deviation between 3D curve and 2D curves (or surfaces in case there are no 2D curves); **the tangential tolerance** is the maximal distance from 3D curve to the end of the tangential zone between faces in terms of their tolerance values.");

// Constructors
cls_IntTools_Curve.def(py::init<>());
cls_IntTools_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &>(), py::arg("the3dCurve3d"), py::arg("the2dCurve1"), py::arg("the2dCurve2"));
cls_IntTools_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real>(), py::arg("the3dCurve3d"), py::arg("the2dCurve1"), py::arg("the2dCurve2"), py::arg("theTolerance"));
cls_IntTools_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("the3dCurve3d"), py::arg("the2dCurve1"), py::arg("the2dCurve2"), py::arg("theTolerance"), py::arg("theTangentialTolerance"));

// Methods
// cls_IntTools_Curve.def_static("operator new_", (void * (*)(size_t)) &IntTools_Curve::operator new, "None", py::arg("theSize"));
// cls_IntTools_Curve.def_static("operator delete_", (void (*)(void *)) &IntTools_Curve::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_Curve.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_Curve::operator new[], "None", py::arg("theSize"));
// cls_IntTools_Curve.def_static("operator delete[]_", (void (*)(void *)) &IntTools_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_Curve.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_Curve.def("SetCurves", (void (IntTools_Curve::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &)) &IntTools_Curve::SetCurves, "Sets the curves", py::arg("the3dCurve"), py::arg("the2dCurve1"), py::arg("the2dCurve2"));
cls_IntTools_Curve.def("SetCurve", (void (IntTools_Curve::*)(const opencascade::handle<Geom_Curve> &)) &IntTools_Curve::SetCurve, "Sets the 3d curve", py::arg("the3dCurve"));
cls_IntTools_Curve.def("SetFirstCurve2d", (void (IntTools_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &IntTools_Curve::SetFirstCurve2d, "Sets the first 2d curve", py::arg("the2dCurve1"));
cls_IntTools_Curve.def("SetSecondCurve2d", (void (IntTools_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &IntTools_Curve::SetSecondCurve2d, "Sets the second 2d curve", py::arg("the2dCurve2"));
cls_IntTools_Curve.def("SetTolerance", (void (IntTools_Curve::*)(const Standard_Real)) &IntTools_Curve::SetTolerance, "Sets the tolerance for the curve", py::arg("theTolerance"));
cls_IntTools_Curve.def("SetTangentialTolerance", (void (IntTools_Curve::*)(const Standard_Real)) &IntTools_Curve::SetTangentialTolerance, "Sets the tangential tolerance", py::arg("theTangentialTolerance"));
cls_IntTools_Curve.def("Curve", (const opencascade::handle<Geom_Curve> & (IntTools_Curve::*)() const) &IntTools_Curve::Curve, "Returns 3d curve");
cls_IntTools_Curve.def("FirstCurve2d", (const opencascade::handle<Geom2d_Curve> & (IntTools_Curve::*)() const) &IntTools_Curve::FirstCurve2d, "Returns first 2d curve");
cls_IntTools_Curve.def("SecondCurve2d", (const opencascade::handle<Geom2d_Curve> & (IntTools_Curve::*)() const) &IntTools_Curve::SecondCurve2d, "Returns second 2d curve");
cls_IntTools_Curve.def("Tolerance", (Standard_Real (IntTools_Curve::*)() const) &IntTools_Curve::Tolerance, "Returns the tolerance");
cls_IntTools_Curve.def("TangentialTolerance", (Standard_Real (IntTools_Curve::*)() const) &IntTools_Curve::TangentialTolerance, "Returns the tangential tolerance");
cls_IntTools_Curve.def("HasBounds", (Standard_Boolean (IntTools_Curve::*)() const) &IntTools_Curve::HasBounds, "Returns TRUE if 3d curve is BoundedCurve");
cls_IntTools_Curve.def("Bounds", [](IntTools_Curve &self, Standard_Real & theFirst, Standard_Real & theLast, gp_Pnt & theFirstPnt, gp_Pnt & theLastPnt){ Standard_Boolean rv = self.Bounds(theFirst, theLast, theFirstPnt, theLastPnt); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theFirst, theLast); }, "If the 3d curve is bounded curve the method will return TRUE and modify the output parameters with boundary parameters of the curve and corresponded 3d points. If the curve does not have bounds, the method will return false and the output parameters will stay untouched.", py::arg("theFirst"), py::arg("theLast"), py::arg("theFirstPnt"), py::arg("theLastPnt"));
cls_IntTools_Curve.def("D0", (Standard_Boolean (IntTools_Curve::*)(const Standard_Real &, gp_Pnt &) const) &IntTools_Curve::D0, "Computes 3d point corresponded to the given parameter if this parameter is inside the boundaries of the curve. Returns TRUE in this case. Otherwise, the point will not be computed and the method will return FALSE.", py::arg("thePar"), py::arg("thePnt"));
cls_IntTools_Curve.def("Type", (GeomAbs_CurveType (IntTools_Curve::*)() const) &IntTools_Curve::Type, "Returns the type of the 3d curve");

// CLASS: INTTOOLS_SHRUNKRANGE
py::class_<IntTools_ShrunkRange> cls_IntTools_ShrunkRange(mod, "IntTools_ShrunkRange", "The class provides the computation of a working (shrunk) range [t1, t2] for the 3D-curve of the edge.");

// Constructors
cls_IntTools_ShrunkRange.def(py::init<>());

// Methods
// cls_IntTools_ShrunkRange.def_static("operator new_", (void * (*)(size_t)) &IntTools_ShrunkRange::operator new, "None", py::arg("theSize"));
// cls_IntTools_ShrunkRange.def_static("operator delete_", (void (*)(void *)) &IntTools_ShrunkRange::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_ShrunkRange.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_ShrunkRange::operator new[], "None", py::arg("theSize"));
// cls_IntTools_ShrunkRange.def_static("operator delete[]_", (void (*)(void *)) &IntTools_ShrunkRange::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_ShrunkRange.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_ShrunkRange::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_ShrunkRange.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_ShrunkRange::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_ShrunkRange.def("SetData", (void (IntTools_ShrunkRange::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real, const TopoDS_Vertex &, const TopoDS_Vertex &)) &IntTools_ShrunkRange::SetData, "None", py::arg("aE"), py::arg("aT1"), py::arg("aT2"), py::arg("aV1"), py::arg("aV2"));
cls_IntTools_ShrunkRange.def("SetContext", (void (IntTools_ShrunkRange::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_ShrunkRange::SetContext, "None", py::arg("aCtx"));
cls_IntTools_ShrunkRange.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_ShrunkRange::*)() const) &IntTools_ShrunkRange::Context, "None");
cls_IntTools_ShrunkRange.def("SetShrunkRange", (void (IntTools_ShrunkRange::*)(const Standard_Real, const Standard_Real)) &IntTools_ShrunkRange::SetShrunkRange, "None", py::arg("aT1"), py::arg("aT2"));
cls_IntTools_ShrunkRange.def("ShrunkRange", [](IntTools_ShrunkRange &self, Standard_Real & aT1, Standard_Real & aT2){ self.ShrunkRange(aT1, aT2); return std::tuple<Standard_Real &, Standard_Real &>(aT1, aT2); }, "None", py::arg("aT1"), py::arg("aT2"));
cls_IntTools_ShrunkRange.def("BndBox", (const Bnd_Box & (IntTools_ShrunkRange::*)() const) &IntTools_ShrunkRange::BndBox, "None");
cls_IntTools_ShrunkRange.def("Edge", (const TopoDS_Edge & (IntTools_ShrunkRange::*)() const) &IntTools_ShrunkRange::Edge, "None");
cls_IntTools_ShrunkRange.def("Perform", (void (IntTools_ShrunkRange::*)()) &IntTools_ShrunkRange::Perform, "None");
cls_IntTools_ShrunkRange.def("IsDone", (Standard_Boolean (IntTools_ShrunkRange::*)() const) &IntTools_ShrunkRange::IsDone, "Returns TRUE in case the shrunk range is computed");
cls_IntTools_ShrunkRange.def("IsSplittable", (Standard_Boolean (IntTools_ShrunkRange::*)() const) &IntTools_ShrunkRange::IsSplittable, "Returns FALSE in case the shrunk range is too short and the edge cannot be split, otherwise returns TRUE");
cls_IntTools_ShrunkRange.def("Length", (Standard_Real (IntTools_ShrunkRange::*)() const) &IntTools_ShrunkRange::Length, "Returns the length of the edge if computed.");

// CLASS: INTTOOLS_CONTEXT
py::class_<IntTools_Context, opencascade::handle<IntTools_Context>, Standard_Transient> cls_IntTools_Context(mod, "IntTools_Context", "The intersection Context contains geometrical and topological toolkit (classifiers, projectors, etc). The intersection Context is for caching the tools to increase the performance.");

// Constructors
cls_IntTools_Context.def(py::init<>());
cls_IntTools_Context.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
cls_IntTools_Context.def("FClass2d", (IntTools_FClass2d & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::FClass2d, "Returns a reference to point classifier for given face", py::arg("aF"));
cls_IntTools_Context.def("ProjPS", (GeomAPI_ProjectPointOnSurf & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::ProjPS, "Returns a reference to point projector for given face", py::arg("aF"));
cls_IntTools_Context.def("ProjPC", (GeomAPI_ProjectPointOnCurve & (IntTools_Context::*)(const TopoDS_Edge &)) &IntTools_Context::ProjPC, "Returns a reference to point projector for given edge", py::arg("aE"));
cls_IntTools_Context.def("ProjPT", (GeomAPI_ProjectPointOnCurve & (IntTools_Context::*)(const opencascade::handle<Geom_Curve> &)) &IntTools_Context::ProjPT, "Returns a reference to point projector for given curve", py::arg("aC"));
cls_IntTools_Context.def("SurfaceData", (IntTools_SurfaceRangeLocalizeData & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::SurfaceData, "Returns a reference to surface localization data for given face", py::arg("aF"));
cls_IntTools_Context.def("SolidClassifier", (BRepClass3d_SolidClassifier & (IntTools_Context::*)(const TopoDS_Solid &)) &IntTools_Context::SolidClassifier, "Returns a reference to solid classifier for given solid", py::arg("aSolid"));
cls_IntTools_Context.def("Hatcher", (Geom2dHatch_Hatcher & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::Hatcher, "Returns a reference to 2D hatcher for given face", py::arg("aF"));
cls_IntTools_Context.def("SurfaceAdaptor", (BRepAdaptor_Surface & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::SurfaceAdaptor, "Returns a reference to surface adaptor for given face", py::arg("theFace"));
cls_IntTools_Context.def("OBB", [](IntTools_Context &self, const TopoDS_Shape & a0) -> Bnd_OBB & { return self.OBB(a0); });
cls_IntTools_Context.def("OBB", (Bnd_OBB & (IntTools_Context::*)(const TopoDS_Shape &, const Standard_Real)) &IntTools_Context::OBB, "Builds and stores an Oriented Bounding Box for the shape. Returns a reference to OBB.", py::arg("theShape"), py::arg("theFuzzyValue"));
cls_IntTools_Context.def("UVBounds", [](IntTools_Context &self, const TopoDS_Face & theFace, Standard_Real & UMin, Standard_Real & UMax, Standard_Real & VMin, Standard_Real & VMax){ self.UVBounds(theFace, UMin, UMax, VMin, VMax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(UMin, UMax, VMin, VMax); }, "Computes the boundaries of the face using surface adaptor", py::arg("theFace"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_IntTools_Context.def("ComputePE", [](IntTools_Context &self, const gp_Pnt & theP, const Standard_Real theTolP, const TopoDS_Edge & theE, Standard_Real & theT, Standard_Real & theDist){ Standard_Integer rv = self.ComputePE(theP, theTolP, theE, theT, theDist); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &>(rv, theT, theDist); }, "Computes parameter of the Point theP on the edge aE. Returns zero if the distance between point and edge is less than sum of tolerance value of edge and theTopP, otherwise and for following conditions returns negative value 1. the edge is degenerated (-1) 2. the edge does not contain 3d curve and pcurves (-2) 3. projection algorithm failed (-3)", py::arg("theP"), py::arg("theTolP"), py::arg("theE"), py::arg("theT"), py::arg("theDist"));
cls_IntTools_Context.def("ComputeVE", [](IntTools_Context &self, const TopoDS_Vertex & theV, const TopoDS_Edge & theE, Standard_Real & theT, Standard_Real & theTol, const Standard_Real theFuzz){ Standard_Integer rv = self.ComputeVE(theV, theE, theT, theTol, theFuzz); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &>(rv, theT, theTol); }, "Computes parameter of the vertex aV on the edge aE and correct tolerance value for the vertex on the edge. Returns zero if the distance between vertex and edge is less than sum of tolerances and the fuzzy value, otherwise and for following conditions returns negative value: 1. the edge is degenerated (-1) 2. the edge does not contain 3d curve and pcurves (-2) 3. projection algorithm failed (-3)", py::arg("theV"), py::arg("theE"), py::arg("theT"), py::arg("theTol"), py::arg("theFuzz"));
cls_IntTools_Context.def("ComputeVF", [](IntTools_Context &self, const TopoDS_Vertex & theVertex, const TopoDS_Face & theFace, Standard_Real & theU, Standard_Real & theV, Standard_Real & theTol, const Standard_Real theFuzz){ Standard_Integer rv = self.ComputeVF(theVertex, theFace, theU, theV, theTol, theFuzz); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &>(rv, theU, theV, theTol); }, "Computes UV parameters of the vertex aV on face aF and correct tolerance value for the vertex on the face. Returns zero if the distance between vertex and face is less than or equal the sum of tolerances and the fuzzy value and the projection point lays inside boundaries of the face. For following conditions returns negative value 1. projection algorithm failed (-1) 2. distance is more than sum of tolerances (-2) 3. projection point out or on the boundaries of face (-3)", py::arg("theVertex"), py::arg("theFace"), py::arg("theU"), py::arg("theV"), py::arg("theTol"), py::arg("theFuzz"));
cls_IntTools_Context.def("StatePointFace", (TopAbs_State (IntTools_Context::*)(const TopoDS_Face &, const gp_Pnt2d &)) &IntTools_Context::StatePointFace, "Returns the state of the point aP2D relative to face aF", py::arg("aF"), py::arg("aP2D"));
cls_IntTools_Context.def("IsPointInFace", (Standard_Boolean (IntTools_Context::*)(const TopoDS_Face &, const gp_Pnt2d &)) &IntTools_Context::IsPointInFace, "Returns true if the point aP2D is inside the boundaries of the face aF, otherwise returns false", py::arg("aF"), py::arg("aP2D"));
cls_IntTools_Context.def("IsPointInFace", (Standard_Boolean (IntTools_Context::*)(const gp_Pnt &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsPointInFace, "Returns true if the point aP2D is inside the boundaries of the face aF, otherwise returns false", py::arg("aP3D"), py::arg("aF"), py::arg("aTol"));
cls_IntTools_Context.def("IsPointInOnFace", (Standard_Boolean (IntTools_Context::*)(const TopoDS_Face &, const gp_Pnt2d &)) &IntTools_Context::IsPointInOnFace, "Returns true if the point aP2D is inside or on the boundaries of aF", py::arg("aF"), py::arg("aP2D"));
cls_IntTools_Context.def("IsValidPointForFace", (Standard_Boolean (IntTools_Context::*)(const gp_Pnt &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidPointForFace, "Returns true if the distance between point aP3D and face aF is less or equal to tolerance aTol and projection point is inside or on the boundaries of the face aF", py::arg("aP3D"), py::arg("aF"), py::arg("aTol"));
cls_IntTools_Context.def("IsValidPointForFaces", (Standard_Boolean (IntTools_Context::*)(const gp_Pnt &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidPointForFaces, "Returns true if IsValidPointForFace returns true for both face aF1 and aF2", py::arg("aP3D"), py::arg("aF1"), py::arg("aF2"), py::arg("aTol"));
cls_IntTools_Context.def("IsValidBlockForFace", (Standard_Boolean (IntTools_Context::*)(const Standard_Real, const Standard_Real, const IntTools_Curve &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidBlockForFace, "Returns true if IsValidPointForFace returns true for some 3d point that lay on the curve aIC bounded by parameters aT1 and aT2", py::arg("aT1"), py::arg("aT2"), py::arg("aIC"), py::arg("aF"), py::arg("aTol"));
cls_IntTools_Context.def("IsValidBlockForFaces", (Standard_Boolean (IntTools_Context::*)(const Standard_Real, const Standard_Real, const IntTools_Curve &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidBlockForFaces, "Returns true if IsValidBlockForFace returns true for both faces aF1 and aF2", py::arg("aT1"), py::arg("aT2"), py::arg("aIC"), py::arg("aF1"), py::arg("aF2"), py::arg("aTol"));
cls_IntTools_Context.def("IsVertexOnLine", [](IntTools_Context &self, const TopoDS_Vertex & aV, const IntTools_Curve & aIC, const Standard_Real aTolC, Standard_Real & aT){ Standard_Boolean rv = self.IsVertexOnLine(aV, aIC, aTolC, aT); return std::tuple<Standard_Boolean, Standard_Real &>(rv, aT); }, "Computes parameter of the vertex aV on the curve aIC. Returns true if the distance between vertex and curve is less than sum of tolerance of aV and aTolC, otherwise or if projection algorithm failed returns false (in this case aT isn't significant)", py::arg("aV"), py::arg("aIC"), py::arg("aTolC"), py::arg("aT"));
cls_IntTools_Context.def("IsVertexOnLine", [](IntTools_Context &self, const TopoDS_Vertex & aV, const Standard_Real aTolV, const IntTools_Curve & aIC, const Standard_Real aTolC, Standard_Real & aT){ Standard_Boolean rv = self.IsVertexOnLine(aV, aTolV, aIC, aTolC, aT); return std::tuple<Standard_Boolean, Standard_Real &>(rv, aT); }, "Computes parameter of the vertex aV on the curve aIC. Returns true if the distance between vertex and curve is less than sum of tolerance of aV and aTolC, otherwise or if projection algorithm failed returns false (in this case aT isn't significant)", py::arg("aV"), py::arg("aTolV"), py::arg("aIC"), py::arg("aTolC"), py::arg("aT"));
cls_IntTools_Context.def("ProjectPointOnEdge", [](IntTools_Context &self, const gp_Pnt & aP, const TopoDS_Edge & aE, Standard_Real & aT){ Standard_Boolean rv = self.ProjectPointOnEdge(aP, aE, aT); return std::tuple<Standard_Boolean, Standard_Real &>(rv, aT); }, "Computes parameter of the point aP on the edge aE. Returns false if projection algorithm failed other wiese returns true.", py::arg("aP"), py::arg("aE"), py::arg("aT"));
cls_IntTools_Context.def("BndBox", (Bnd_Box & (IntTools_Context::*)(const TopoDS_Shape &)) &IntTools_Context::BndBox, "None", py::arg("theS"));
cls_IntTools_Context.def("IsInfiniteFace", (Standard_Boolean (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::IsInfiniteFace, "Returns true if the solid <theFace> has infinite bounds", py::arg("theFace"));
cls_IntTools_Context.def("SetPOnSProjectionTolerance", (void (IntTools_Context::*)(const Standard_Real)) &IntTools_Context::SetPOnSProjectionTolerance, "Sets tolerance to be used for projection of point on surface. Clears map of already cached projectors in order to maintain correct value for all projectors", py::arg("theValue"));
cls_IntTools_Context.def_static("get_type_name_", (const char * (*)()) &IntTools_Context::get_type_name, "None");
cls_IntTools_Context.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntTools_Context::get_type_descriptor, "None");
cls_IntTools_Context.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntTools_Context::*)() const) &IntTools_Context::DynamicType, "None");

// CLASS: INTTOOLS_RANGE
py::class_<IntTools_Range> cls_IntTools_Range(mod, "IntTools_Range", "The class describes the 1-d range [myFirst, myLast].");

// Constructors
cls_IntTools_Range.def(py::init<>());
cls_IntTools_Range.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("aFirst"), py::arg("aLast"));

// Methods
// cls_IntTools_Range.def_static("operator new_", (void * (*)(size_t)) &IntTools_Range::operator new, "None", py::arg("theSize"));
// cls_IntTools_Range.def_static("operator delete_", (void (*)(void *)) &IntTools_Range::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_Range.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_Range::operator new[], "None", py::arg("theSize"));
// cls_IntTools_Range.def_static("operator delete[]_", (void (*)(void *)) &IntTools_Range::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_Range.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_Range::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_Range.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_Range::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_Range.def("SetFirst", (void (IntTools_Range::*)(const Standard_Real)) &IntTools_Range::SetFirst, "Modifier", py::arg("aFirst"));
cls_IntTools_Range.def("SetLast", (void (IntTools_Range::*)(const Standard_Real)) &IntTools_Range::SetLast, "Modifier", py::arg("aLast"));
cls_IntTools_Range.def("First", (Standard_Real (IntTools_Range::*)() const) &IntTools_Range::First, "Selector");
cls_IntTools_Range.def("Last", (Standard_Real (IntTools_Range::*)() const) &IntTools_Range::Last, "Selector");
cls_IntTools_Range.def("Range", [](IntTools_Range &self, Standard_Real & aFirst, Standard_Real & aLast){ self.Range(aFirst, aLast); return std::tuple<Standard_Real &, Standard_Real &>(aFirst, aLast); }, "Selector", py::arg("aFirst"), py::arg("aLast"));

// TYPEDEF: INTTOOLS_SEQUENCEOFRANGES
bind_NCollection_Sequence<IntTools_Range>(mod, "IntTools_SequenceOfRanges", py::module_local(false));

// CLASS: INTTOOLS_COMMONPRT
py::class_<IntTools_CommonPrt> cls_IntTools_CommonPrt(mod, "IntTools_CommonPrt", "The class is to describe a common part between two edges in 3-d space.");

// Constructors
cls_IntTools_CommonPrt.def(py::init<>());
cls_IntTools_CommonPrt.def(py::init<const IntTools_CommonPrt &>(), py::arg("aCPrt"));

// Methods
// cls_IntTools_CommonPrt.def_static("operator new_", (void * (*)(size_t)) &IntTools_CommonPrt::operator new, "None", py::arg("theSize"));
// cls_IntTools_CommonPrt.def_static("operator delete_", (void (*)(void *)) &IntTools_CommonPrt::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_CommonPrt.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_CommonPrt::operator new[], "None", py::arg("theSize"));
// cls_IntTools_CommonPrt.def_static("operator delete[]_", (void (*)(void *)) &IntTools_CommonPrt::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_CommonPrt.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_CommonPrt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_CommonPrt.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_CommonPrt::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_CommonPrt.def("Assign", (IntTools_CommonPrt & (IntTools_CommonPrt::*)(const IntTools_CommonPrt &)) &IntTools_CommonPrt::Assign, "None", py::arg("Other"));
// cls_IntTools_CommonPrt.def("operator=", (IntTools_CommonPrt & (IntTools_CommonPrt::*)(const IntTools_CommonPrt &)) &IntTools_CommonPrt::operator=, "None", py::arg("Other"));
cls_IntTools_CommonPrt.def("SetEdge1", (void (IntTools_CommonPrt::*)(const TopoDS_Edge &)) &IntTools_CommonPrt::SetEdge1, "Sets the first edge.", py::arg("anE"));
cls_IntTools_CommonPrt.def("SetEdge2", (void (IntTools_CommonPrt::*)(const TopoDS_Edge &)) &IntTools_CommonPrt::SetEdge2, "Sets the second edge.", py::arg("anE"));
cls_IntTools_CommonPrt.def("SetType", (void (IntTools_CommonPrt::*)(const TopAbs_ShapeEnum)) &IntTools_CommonPrt::SetType, "Sets the type of the common part Vertex or Edge", py::arg("aType"));
cls_IntTools_CommonPrt.def("SetRange1", (void (IntTools_CommonPrt::*)(const IntTools_Range &)) &IntTools_CommonPrt::SetRange1, "Sets the range of first edge.", py::arg("aR"));
cls_IntTools_CommonPrt.def("SetRange1", (void (IntTools_CommonPrt::*)(const Standard_Real, const Standard_Real)) &IntTools_CommonPrt::SetRange1, "Sets the range of first edge.", py::arg("tf"), py::arg("tl"));
cls_IntTools_CommonPrt.def("AppendRange2", (void (IntTools_CommonPrt::*)(const IntTools_Range &)) &IntTools_CommonPrt::AppendRange2, "Appends the range of second edge.", py::arg("aR"));
cls_IntTools_CommonPrt.def("AppendRange2", (void (IntTools_CommonPrt::*)(const Standard_Real, const Standard_Real)) &IntTools_CommonPrt::AppendRange2, "Appends the range of second edge.", py::arg("tf"), py::arg("tl"));
cls_IntTools_CommonPrt.def("SetVertexParameter1", (void (IntTools_CommonPrt::*)(const Standard_Real)) &IntTools_CommonPrt::SetVertexParameter1, "Sets a parameter of first vertex", py::arg("tV"));
cls_IntTools_CommonPrt.def("SetVertexParameter2", (void (IntTools_CommonPrt::*)(const Standard_Real)) &IntTools_CommonPrt::SetVertexParameter2, "Sets a parameter of second vertex", py::arg("tV"));
cls_IntTools_CommonPrt.def("Edge1", (const TopoDS_Edge & (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::Edge1, "Returns the first edge.");
cls_IntTools_CommonPrt.def("Edge2", (const TopoDS_Edge & (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::Edge2, "Returns the second edge");
cls_IntTools_CommonPrt.def("Type", (TopAbs_ShapeEnum (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::Type, "Returns the type of the common part");
cls_IntTools_CommonPrt.def("Range1", (const IntTools_Range & (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::Range1, "Returns the range of first edge");
cls_IntTools_CommonPrt.def("Range1", [](IntTools_CommonPrt &self, Standard_Real & tf, Standard_Real & tl){ self.Range1(tf, tl); return std::tuple<Standard_Real &, Standard_Real &>(tf, tl); }, "Returns the range of first edge.", py::arg("tf"), py::arg("tl"));
cls_IntTools_CommonPrt.def("Ranges2", (const IntTools_SequenceOfRanges & (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::Ranges2, "Returns the ranges of second edge.");
cls_IntTools_CommonPrt.def("ChangeRanges2", (IntTools_SequenceOfRanges & (IntTools_CommonPrt::*)()) &IntTools_CommonPrt::ChangeRanges2, "Returns the ranges of second edge.");
cls_IntTools_CommonPrt.def("VertexParameter1", (Standard_Real (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::VertexParameter1, "Returns parameter of first vertex");
cls_IntTools_CommonPrt.def("VertexParameter2", (Standard_Real (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::VertexParameter2, "Returns parameter of second vertex");
cls_IntTools_CommonPrt.def("Copy", (void (IntTools_CommonPrt::*)(IntTools_CommonPrt &) const) &IntTools_CommonPrt::Copy, "Copies me to anOther", py::arg("anOther"));
cls_IntTools_CommonPrt.def("AllNullFlag", (Standard_Boolean (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::AllNullFlag, "Modifier");
cls_IntTools_CommonPrt.def("SetAllNullFlag", (void (IntTools_CommonPrt::*)(const Standard_Boolean)) &IntTools_CommonPrt::SetAllNullFlag, "Selector", py::arg("aFlag"));
cls_IntTools_CommonPrt.def("SetBoundingPoints", (void (IntTools_CommonPrt::*)(const gp_Pnt &, const gp_Pnt &)) &IntTools_CommonPrt::SetBoundingPoints, "Modifier", py::arg("aP1"), py::arg("aP2"));
cls_IntTools_CommonPrt.def("BoundingPoints", (void (IntTools_CommonPrt::*)(gp_Pnt &, gp_Pnt &) const) &IntTools_CommonPrt::BoundingPoints, "Selector", py::arg("aP1"), py::arg("aP2"));

// CLASS: INTTOOLS_ROOT
py::class_<IntTools_Root> cls_IntTools_Root(mod, "IntTools_Root", "The class is to describe the root of function of one variable for Edge/Edge and Edge/Surface algorithms.");

// Constructors
cls_IntTools_Root.def(py::init<>());
cls_IntTools_Root.def(py::init<const Standard_Real, const Standard_Integer>(), py::arg("aRoot"), py::arg("aType"));

// Methods
// cls_IntTools_Root.def_static("operator new_", (void * (*)(size_t)) &IntTools_Root::operator new, "None", py::arg("theSize"));
// cls_IntTools_Root.def_static("operator delete_", (void (*)(void *)) &IntTools_Root::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_Root.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_Root::operator new[], "None", py::arg("theSize"));
// cls_IntTools_Root.def_static("operator delete[]_", (void (*)(void *)) &IntTools_Root::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_Root.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_Root::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_Root.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_Root::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_Root.def("SetRoot", (void (IntTools_Root::*)(const Standard_Real)) &IntTools_Root::SetRoot, "Sets the Root's value", py::arg("aRoot"));
cls_IntTools_Root.def("SetType", (void (IntTools_Root::*)(const Standard_Integer)) &IntTools_Root::SetType, "Sets the Root's Type", py::arg("aType"));
cls_IntTools_Root.def("SetStateBefore", (void (IntTools_Root::*)(const TopAbs_State)) &IntTools_Root::SetStateBefore, "Set the value of the state before the root (at t=Root-dt)", py::arg("aState"));
cls_IntTools_Root.def("SetStateAfter", (void (IntTools_Root::*)(const TopAbs_State)) &IntTools_Root::SetStateAfter, "Set the value of the state after the root (at t=Root-dt)", py::arg("aState"));
cls_IntTools_Root.def("SetLayerHeight", (void (IntTools_Root::*)(const Standard_Real)) &IntTools_Root::SetLayerHeight, "Not used in Edge/Edge algorithm", py::arg("aHeight"));
cls_IntTools_Root.def("SetInterval", (void (IntTools_Root::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_Root::SetInterval, "Sets the interval from which the Root was found [t1,t2] and the corresponding values of the function on the bounds f(t1), f(t2).", py::arg("t1"), py::arg("t2"), py::arg("f1"), py::arg("f2"));
cls_IntTools_Root.def("Root", (Standard_Real (IntTools_Root::*)() const) &IntTools_Root::Root, "Returns the Root value");
cls_IntTools_Root.def("Type", (Standard_Integer (IntTools_Root::*)() const) &IntTools_Root::Type, "Returns the type of the root =0 - Simple (was found by bisection method); =2 - Smart when f1=0, f2!=0 or vice versa (was found by Fibbonacci method); =1 - Pure (pure zero for all t [t1,t2] );");
cls_IntTools_Root.def("StateBefore", (TopAbs_State (IntTools_Root::*)() const) &IntTools_Root::StateBefore, "Returns the state before the root");
cls_IntTools_Root.def("StateAfter", (TopAbs_State (IntTools_Root::*)() const) &IntTools_Root::StateAfter, "Returns the state after the root");
cls_IntTools_Root.def("LayerHeight", (Standard_Real (IntTools_Root::*)() const) &IntTools_Root::LayerHeight, "Not used in Edge/Edge algorithm");
cls_IntTools_Root.def("IsValid", (Standard_Boolean (IntTools_Root::*)() const) &IntTools_Root::IsValid, "Returns the validity flag for the root, True if myStateBefore==TopAbs_OUT && myStateAfter==TopAbs_IN or myStateBefore==TopAbs_OUT && myStateAfter==TopAbs_ON or myStateBefore==TopAbs_ON && myStateAfter==TopAbs_OUT or myStateBefore==TopAbs_IN && myStateAfter==TopAbs_OUT . For other cases it returns False.");
cls_IntTools_Root.def("Interval", [](IntTools_Root &self, Standard_Real & t1, Standard_Real & t2, Standard_Real & f1, Standard_Real & f2){ self.Interval(t1, t2, f1, f2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(t1, t2, f1, f2); }, "Returns the values of interval from which the Root was found [t1,t2] and the corresponding values of the function on the bounds f(t1), f(t2).", py::arg("t1"), py::arg("t2"), py::arg("f1"), py::arg("f2"));

// TYPEDEF: INTTOOLS_SEQUENCEOFROOTS
bind_NCollection_Sequence<IntTools_Root>(mod, "IntTools_SequenceOfRoots", py::module_local(false));

// CLASS: INTTOOLS
py::class_<IntTools> cls_IntTools(mod, "IntTools", "Contains classes for intersection and classification purposes and accompanying classes");

// Constructors
cls_IntTools.def(py::init<>());

// Methods
// cls_IntTools.def_static("operator new_", (void * (*)(size_t)) &IntTools::operator new, "None", py::arg("theSize"));
// cls_IntTools.def_static("operator delete_", (void (*)(void *)) &IntTools::operator delete, "None", py::arg("theAddress"));
// cls_IntTools.def_static("operator new[]_", (void * (*)(size_t)) &IntTools::operator new[], "None", py::arg("theSize"));
// cls_IntTools.def_static("operator delete[]_", (void (*)(void *)) &IntTools::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools.def_static("operator delete_", (void (*)(void *, void *)) &IntTools::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools.def_static("Length_", (Standard_Real (*)(const TopoDS_Edge &)) &IntTools::Length, "returns the length of the edge;", py::arg("E"));
cls_IntTools.def_static("RemoveIdenticalRoots_", (void (*)(IntTools_SequenceOfRoots &, const Standard_Real)) &IntTools::RemoveIdenticalRoots, "Remove from the sequence aSeq the Roots that have values ti and tj such as |ti-tj] < anEpsT.", py::arg("aSeq"), py::arg("anEpsT"));
cls_IntTools.def_static("SortRoots_", (void (*)(IntTools_SequenceOfRoots &, const Standard_Real)) &IntTools::SortRoots, "Sort the sequence aSeq of the Roots to arrange the Roons in increasing order", py::arg("aSeq"), py::arg("anEpsT"));
cls_IntTools.def_static("FindRootStates_", (void (*)(IntTools_SequenceOfRoots &, const Standard_Real)) &IntTools::FindRootStates, "Find the states (before and after) for each Root from the sequence aSeq", py::arg("aSeq"), py::arg("anEpsNull"));
cls_IntTools.def_static("Parameter_", [](const gp_Pnt & P, const opencascade::handle<Geom_Curve> & Curve, Standard_Real & aParm){ Standard_Integer rv = IntTools::Parameter(P, Curve, aParm); return std::tuple<Standard_Integer, Standard_Real &>(rv, aParm); }, "None", py::arg("P"), py::arg("Curve"), py::arg("aParm"));
cls_IntTools.def_static("GetRadius_", [](const BRepAdaptor_Curve & C, const Standard_Real t1, const Standard_Real t3, Standard_Real & R){ Standard_Integer rv = IntTools::GetRadius(C, t1, t3, R); return std::tuple<Standard_Integer, Standard_Real &>(rv, R); }, "None", py::arg("C"), py::arg("t1"), py::arg("t3"), py::arg("R"));
cls_IntTools.def_static("PrepareArgs_", (Standard_Integer (*)(BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, IntTools_CArray1OfReal &)) &IntTools::PrepareArgs, "None", py::arg("C"), py::arg("tMax"), py::arg("tMin"), py::arg("Discret"), py::arg("Deflect"), py::arg("anArgs"));

// TYPEDEF: INTTOOLS_ARRAY1OFRANGE
bind_NCollection_Array1<IntTools_Range>(mod, "IntTools_Array1OfRange", py::module_local(false));

// TYPEDEF: INTTOOLS_ARRAY1OFROOTS
bind_NCollection_Array1<IntTools_Root>(mod, "IntTools_Array1OfRoots", py::module_local(false));

// CLASS: INTTOOLS_BASERANGESAMPLE
py::class_<IntTools_BaseRangeSample> cls_IntTools_BaseRangeSample(mod, "IntTools_BaseRangeSample", "base class for range index management");

// Constructors
cls_IntTools_BaseRangeSample.def(py::init<>());
cls_IntTools_BaseRangeSample.def(py::init<const Standard_Integer>(), py::arg("theDepth"));

// Methods
// cls_IntTools_BaseRangeSample.def_static("operator new_", (void * (*)(size_t)) &IntTools_BaseRangeSample::operator new, "None", py::arg("theSize"));
// cls_IntTools_BaseRangeSample.def_static("operator delete_", (void (*)(void *)) &IntTools_BaseRangeSample::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_BaseRangeSample.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_BaseRangeSample::operator new[], "None", py::arg("theSize"));
// cls_IntTools_BaseRangeSample.def_static("operator delete[]_", (void (*)(void *)) &IntTools_BaseRangeSample::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_BaseRangeSample.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_BaseRangeSample::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_BaseRangeSample.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_BaseRangeSample::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_BaseRangeSample.def("SetDepth", (void (IntTools_BaseRangeSample::*)(const Standard_Integer)) &IntTools_BaseRangeSample::SetDepth, "None", py::arg("theDepth"));
cls_IntTools_BaseRangeSample.def("GetDepth", (Standard_Integer (IntTools_BaseRangeSample::*)() const) &IntTools_BaseRangeSample::GetDepth, "None");

// CLASS: INTTOOLS_MARKEDRANGESET
py::class_<IntTools_MarkedRangeSet> cls_IntTools_MarkedRangeSet(mod, "IntTools_MarkedRangeSet", "class MarkedRangeSet provides continuous set of ranges marked with flags");

// Constructors
cls_IntTools_MarkedRangeSet.def(py::init<>());
cls_IntTools_MarkedRangeSet.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theInitFlag"));
cls_IntTools_MarkedRangeSet.def(py::init<const IntTools_CArray1OfReal &, const Standard_Integer>(), py::arg("theSortedArray"), py::arg("theInitFlag"));

// Methods
// cls_IntTools_MarkedRangeSet.def_static("operator new_", (void * (*)(size_t)) &IntTools_MarkedRangeSet::operator new, "None", py::arg("theSize"));
// cls_IntTools_MarkedRangeSet.def_static("operator delete_", (void (*)(void *)) &IntTools_MarkedRangeSet::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_MarkedRangeSet.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_MarkedRangeSet::operator new[], "None", py::arg("theSize"));
// cls_IntTools_MarkedRangeSet.def_static("operator delete[]_", (void (*)(void *)) &IntTools_MarkedRangeSet::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_MarkedRangeSet.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_MarkedRangeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_MarkedRangeSet.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_MarkedRangeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_MarkedRangeSet.def("SetBoundaries", (void (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &IntTools_MarkedRangeSet::SetBoundaries, "build set of ranges which consists of one range with boundary values theFirstBoundary and theLastBoundary", py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theInitFlag"));
cls_IntTools_MarkedRangeSet.def("SetRanges", (void (IntTools_MarkedRangeSet::*)(const IntTools_CArray1OfReal &, const Standard_Integer)) &IntTools_MarkedRangeSet::SetRanges, "Build set of ranges based on the array of progressive sorted values", py::arg("theSortedArray"), py::arg("theInitFlag"));
cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theFlag"));
cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const IntTools_Range &, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theRange"), py::arg("theFlag"));
cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. The index theIndex is a position where the range will be inserted. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theFlag"), py::arg("theIndex"));
cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const IntTools_Range &, const Standard_Integer, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. The index theIndex is a position where the range will be inserted. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theRange"), py::arg("theFlag"), py::arg("theIndex"));
cls_IntTools_MarkedRangeSet.def("SetFlag", (void (IntTools_MarkedRangeSet::*)(const Standard_Integer, const Standard_Integer)) &IntTools_MarkedRangeSet::SetFlag, "Set flag theFlag for range with index theIndex", py::arg("theIndex"), py::arg("theFlag"));
cls_IntTools_MarkedRangeSet.def("Flag", (Standard_Integer (IntTools_MarkedRangeSet::*)(const Standard_Integer) const) &IntTools_MarkedRangeSet::Flag, "Returns flag of the range with index theIndex", py::arg("theIndex"));
cls_IntTools_MarkedRangeSet.def("GetIndex", (Standard_Integer (IntTools_MarkedRangeSet::*)(const Standard_Real) const) &IntTools_MarkedRangeSet::GetIndex, "Returns index of range which contains theValue. If theValue do not belong any range returns 0.", py::arg("theValue"));
cls_IntTools_MarkedRangeSet.def("GetIndices", (const TColStd_SequenceOfInteger & (IntTools_MarkedRangeSet::*)(const Standard_Real)) &IntTools_MarkedRangeSet::GetIndices, "None", py::arg("theValue"));
cls_IntTools_MarkedRangeSet.def("GetIndex", (Standard_Integer (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Boolean) const) &IntTools_MarkedRangeSet::GetIndex, "Returns index of range which contains theValue If theValue do not belong any range returns 0. If UseLower is Standard_True then lower boundary of the range can be equal to theValue, otherwise upper boundary of the range can be equal to theValue.", py::arg("theValue"), py::arg("UseLower"));
cls_IntTools_MarkedRangeSet.def("Length", (Standard_Integer (IntTools_MarkedRangeSet::*)() const) &IntTools_MarkedRangeSet::Length, "Returns number of ranges");
cls_IntTools_MarkedRangeSet.def("Range", (IntTools_Range (IntTools_MarkedRangeSet::*)(const Standard_Integer) const) &IntTools_MarkedRangeSet::Range, "Returns the range with index theIndex. the Index can be from 1 to Length()", py::arg("theIndex"));

// CLASS: INTTOOLS_CURVERANGESAMPLE
py::class_<IntTools_CurveRangeSample, IntTools_BaseRangeSample> cls_IntTools_CurveRangeSample(mod, "IntTools_CurveRangeSample", "class for range index management of curve");

// Constructors
cls_IntTools_CurveRangeSample.def(py::init<>());
cls_IntTools_CurveRangeSample.def(py::init<const Standard_Integer>(), py::arg("theIndex"));

// Methods
// cls_IntTools_CurveRangeSample.def_static("operator new_", (void * (*)(size_t)) &IntTools_CurveRangeSample::operator new, "None", py::arg("theSize"));
// cls_IntTools_CurveRangeSample.def_static("operator delete_", (void (*)(void *)) &IntTools_CurveRangeSample::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_CurveRangeSample.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_CurveRangeSample::operator new[], "None", py::arg("theSize"));
// cls_IntTools_CurveRangeSample.def_static("operator delete[]_", (void (*)(void *)) &IntTools_CurveRangeSample::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_CurveRangeSample.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_CurveRangeSample::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_CurveRangeSample.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_CurveRangeSample::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_CurveRangeSample.def("SetRangeIndex", (void (IntTools_CurveRangeSample::*)(const Standard_Integer)) &IntTools_CurveRangeSample::SetRangeIndex, "None", py::arg("theIndex"));
cls_IntTools_CurveRangeSample.def("GetRangeIndex", (Standard_Integer (IntTools_CurveRangeSample::*)() const) &IntTools_CurveRangeSample::GetRangeIndex, "None");
cls_IntTools_CurveRangeSample.def("IsEqual", (Standard_Boolean (IntTools_CurveRangeSample::*)(const IntTools_CurveRangeSample &) const) &IntTools_CurveRangeSample::IsEqual, "None", py::arg("Other"));
cls_IntTools_CurveRangeSample.def("GetRange", (IntTools_Range (IntTools_CurveRangeSample::*)(const Standard_Real, const Standard_Real, const Standard_Integer) const) &IntTools_CurveRangeSample::GetRange, "None", py::arg("theFirst"), py::arg("theLast"), py::arg("theNbSample"));
cls_IntTools_CurveRangeSample.def("GetRangeIndexDeeper", (Standard_Integer (IntTools_CurveRangeSample::*)(const Standard_Integer) const) &IntTools_CurveRangeSample::GetRangeIndexDeeper, "None", py::arg("theNbSample"));

// TYPEDEF: INTTOOLS_LISTOFCURVERANGESAMPLE
bind_NCollection_List<IntTools_CurveRangeSample>(mod, "IntTools_ListOfCurveRangeSample", py::module_local(false));

// TYPEDEF: INTTOOLS_LISTITERATOROFLISTOFCURVERANGESAMPLE
bind_NCollection_TListIterator<IntTools_CurveRangeSample>(mod, "IntTools_ListIteratorOfListOfCurveRangeSample", py::module_local(false));

// CLASS: INTTOOLS_SURFACERANGESAMPLE
py::class_<IntTools_SurfaceRangeSample> cls_IntTools_SurfaceRangeSample(mod, "IntTools_SurfaceRangeSample", "class for range index management of surface");

// Constructors
cls_IntTools_SurfaceRangeSample.def(py::init<>());
cls_IntTools_SurfaceRangeSample.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theIndexU"), py::arg("theDepthU"), py::arg("theIndexV"), py::arg("theDepthV"));
cls_IntTools_SurfaceRangeSample.def(py::init<const IntTools_CurveRangeSample &, const IntTools_CurveRangeSample &>(), py::arg("theRangeU"), py::arg("theRangeV"));
cls_IntTools_SurfaceRangeSample.def(py::init<const IntTools_SurfaceRangeSample &>(), py::arg("Other"));

// Methods
// cls_IntTools_SurfaceRangeSample.def_static("operator new_", (void * (*)(size_t)) &IntTools_SurfaceRangeSample::operator new, "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeSample.def_static("operator delete_", (void (*)(void *)) &IntTools_SurfaceRangeSample::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSample.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_SurfaceRangeSample::operator new[], "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeSample.def_static("operator delete[]_", (void (*)(void *)) &IntTools_SurfaceRangeSample::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSample.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_SurfaceRangeSample::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSample.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_SurfaceRangeSample::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_SurfaceRangeSample.def("Assign", (IntTools_SurfaceRangeSample & (IntTools_SurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeSample::Assign, "None", py::arg("Other"));
// cls_IntTools_SurfaceRangeSample.def("operator=", (IntTools_SurfaceRangeSample & (IntTools_SurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeSample::operator=, "None", py::arg("Other"));
cls_IntTools_SurfaceRangeSample.def("SetRanges", (void (IntTools_SurfaceRangeSample::*)(const IntTools_CurveRangeSample &, const IntTools_CurveRangeSample &)) &IntTools_SurfaceRangeSample::SetRanges, "None", py::arg("theRangeU"), py::arg("theRangeV"));
cls_IntTools_SurfaceRangeSample.def("GetRanges", (void (IntTools_SurfaceRangeSample::*)(IntTools_CurveRangeSample &, IntTools_CurveRangeSample &) const) &IntTools_SurfaceRangeSample::GetRanges, "None", py::arg("theRangeU"), py::arg("theRangeV"));
cls_IntTools_SurfaceRangeSample.def("SetIndexes", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SurfaceRangeSample::SetIndexes, "None", py::arg("theIndexU"), py::arg("theIndexV"));
cls_IntTools_SurfaceRangeSample.def("GetIndexes", [](IntTools_SurfaceRangeSample &self, Standard_Integer & theIndexU, Standard_Integer & theIndexV){ self.GetIndexes(theIndexU, theIndexV); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndexU, theIndexV); }, "None", py::arg("theIndexU"), py::arg("theIndexV"));
cls_IntTools_SurfaceRangeSample.def("GetDepths", [](IntTools_SurfaceRangeSample &self, Standard_Integer & theDepthU, Standard_Integer & theDepthV){ self.GetDepths(theDepthU, theDepthV); return std::tuple<Standard_Integer &, Standard_Integer &>(theDepthU, theDepthV); }, "None", py::arg("theDepthU"), py::arg("theDepthV"));
cls_IntTools_SurfaceRangeSample.def("SetSampleRangeU", (void (IntTools_SurfaceRangeSample::*)(const IntTools_CurveRangeSample &)) &IntTools_SurfaceRangeSample::SetSampleRangeU, "None", py::arg("theRangeSampleU"));
cls_IntTools_SurfaceRangeSample.def("GetSampleRangeU", (const IntTools_CurveRangeSample & (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetSampleRangeU, "None");
cls_IntTools_SurfaceRangeSample.def("SetSampleRangeV", (void (IntTools_SurfaceRangeSample::*)(const IntTools_CurveRangeSample &)) &IntTools_SurfaceRangeSample::SetSampleRangeV, "None", py::arg("theRangeSampleV"));
cls_IntTools_SurfaceRangeSample.def("GetSampleRangeV", (const IntTools_CurveRangeSample & (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetSampleRangeV, "None");
cls_IntTools_SurfaceRangeSample.def("SetIndexU", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetIndexU, "None", py::arg("theIndexU"));
cls_IntTools_SurfaceRangeSample.def("GetIndexU", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetIndexU, "None");
cls_IntTools_SurfaceRangeSample.def("SetIndexV", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetIndexV, "None", py::arg("theIndexV"));
cls_IntTools_SurfaceRangeSample.def("GetIndexV", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetIndexV, "None");
cls_IntTools_SurfaceRangeSample.def("SetDepthU", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetDepthU, "None", py::arg("theDepthU"));
cls_IntTools_SurfaceRangeSample.def("GetDepthU", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetDepthU, "None");
cls_IntTools_SurfaceRangeSample.def("SetDepthV", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetDepthV, "None", py::arg("theDepthV"));
cls_IntTools_SurfaceRangeSample.def("GetDepthV", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetDepthV, "None");
cls_IntTools_SurfaceRangeSample.def("GetRangeU", (IntTools_Range (IntTools_SurfaceRangeSample::*)(const Standard_Real, const Standard_Real, const Standard_Integer) const) &IntTools_SurfaceRangeSample::GetRangeU, "None", py::arg("theFirstU"), py::arg("theLastU"), py::arg("theNbSampleU"));
cls_IntTools_SurfaceRangeSample.def("GetRangeV", (IntTools_Range (IntTools_SurfaceRangeSample::*)(const Standard_Real, const Standard_Real, const Standard_Integer) const) &IntTools_SurfaceRangeSample::GetRangeV, "None", py::arg("theFirstV"), py::arg("theLastV"), py::arg("theNbSampleV"));
cls_IntTools_SurfaceRangeSample.def("IsEqual", (Standard_Boolean (IntTools_SurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &) const) &IntTools_SurfaceRangeSample::IsEqual, "None", py::arg("Other"));
cls_IntTools_SurfaceRangeSample.def("GetRangeIndexUDeeper", (Standard_Integer (IntTools_SurfaceRangeSample::*)(const Standard_Integer) const) &IntTools_SurfaceRangeSample::GetRangeIndexUDeeper, "None", py::arg("theNbSampleU"));
cls_IntTools_SurfaceRangeSample.def("GetRangeIndexVDeeper", (Standard_Integer (IntTools_SurfaceRangeSample::*)(const Standard_Integer) const) &IntTools_SurfaceRangeSample::GetRangeIndexVDeeper, "None", py::arg("theNbSampleV"));

// TYPEDEF: INTTOOLS_LISTOFSURFACERANGESAMPLE
bind_NCollection_List<IntTools_SurfaceRangeSample>(mod, "IntTools_ListOfSurfaceRangeSample", py::module_local(false));

// TYPEDEF: INTTOOLS_LISTITERATOROFLISTOFSURFACERANGESAMPLE
bind_NCollection_TListIterator<IntTools_SurfaceRangeSample>(mod, "IntTools_ListIteratorOfListOfSurfaceRangeSample", py::module_local(false));

// CLASS: INTTOOLS_BEANFACEINTERSECTOR
py::class_<IntTools_BeanFaceIntersector> cls_IntTools_BeanFaceIntersector(mod, "IntTools_BeanFaceIntersector", "The class BeanFaceIntersector computes ranges of parameters on the curve of a bean(part of edge) that bound the parts of bean which are on the surface of a face according to edge and face tolerances. Warning: The real boundaries of the face are not taken into account, Most of the result parts of the bean lays only inside the region of the surface, which includes the inside of the face. And the parts which are out of this region can be excluded from the result.");

// Constructors
cls_IntTools_BeanFaceIntersector.def(py::init<>());
cls_IntTools_BeanFaceIntersector.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("theEdge"), py::arg("theFace"));
cls_IntTools_BeanFaceIntersector.def(py::init<const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theSurface"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));
cls_IntTools_BeanFaceIntersector.def(py::init<const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirstParOnCurve"), py::arg("theLastParOnCurve"), py::arg("theUMinParameter"), py::arg("theUMaxParameter"), py::arg("theVMinParameter"), py::arg("theVMaxParameter"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));

// Methods
// cls_IntTools_BeanFaceIntersector.def_static("operator new_", (void * (*)(size_t)) &IntTools_BeanFaceIntersector::operator new, "None", py::arg("theSize"));
// cls_IntTools_BeanFaceIntersector.def_static("operator delete_", (void (*)(void *)) &IntTools_BeanFaceIntersector::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_BeanFaceIntersector.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_BeanFaceIntersector::operator new[], "None", py::arg("theSize"));
// cls_IntTools_BeanFaceIntersector.def_static("operator delete[]_", (void (*)(void *)) &IntTools_BeanFaceIntersector::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_BeanFaceIntersector.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_BeanFaceIntersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_BeanFaceIntersector.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_BeanFaceIntersector::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_BeanFaceIntersector.def("Init", (void (IntTools_BeanFaceIntersector::*)(const TopoDS_Edge &, const TopoDS_Face &)) &IntTools_BeanFaceIntersector::Init, "Initializes the algorithm", py::arg("theEdge"), py::arg("theFace"));
cls_IntTools_BeanFaceIntersector.def("Init", (void (IntTools_BeanFaceIntersector::*)(const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::Init, "Initializes the algorithm", py::arg("theCurve"), py::arg("theSurface"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));
cls_IntTools_BeanFaceIntersector.def("Init", (void (IntTools_BeanFaceIntersector::*)(const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::Init, "Initializes the algorithm theUMinParameter, ... are used for optimization purposes", py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirstParOnCurve"), py::arg("theLastParOnCurve"), py::arg("theUMinParameter"), py::arg("theUMaxParameter"), py::arg("theVMinParameter"), py::arg("theVMaxParameter"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));
cls_IntTools_BeanFaceIntersector.def("SetContext", (void (IntTools_BeanFaceIntersector::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_BeanFaceIntersector::SetContext, "Sets the intersecton context", py::arg("theContext"));
cls_IntTools_BeanFaceIntersector.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_BeanFaceIntersector::*)() const) &IntTools_BeanFaceIntersector::Context, "Gets the intersecton context");
cls_IntTools_BeanFaceIntersector.def("SetBeanParameters", (void (IntTools_BeanFaceIntersector::*)(const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::SetBeanParameters, "Set restrictions for curve", py::arg("theFirstParOnCurve"), py::arg("theLastParOnCurve"));
cls_IntTools_BeanFaceIntersector.def("SetSurfaceParameters", (void (IntTools_BeanFaceIntersector::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::SetSurfaceParameters, "Set restrictions for surface", py::arg("theUMinParameter"), py::arg("theUMaxParameter"), py::arg("theVMinParameter"), py::arg("theVMaxParameter"));
cls_IntTools_BeanFaceIntersector.def("Perform", (void (IntTools_BeanFaceIntersector::*)()) &IntTools_BeanFaceIntersector::Perform, "Launches the algorithm");
cls_IntTools_BeanFaceIntersector.def("IsDone", (Standard_Boolean (IntTools_BeanFaceIntersector::*)() const) &IntTools_BeanFaceIntersector::IsDone, "Returns Done/NotDone state of the algorithm.");
cls_IntTools_BeanFaceIntersector.def("Result", (const IntTools_SequenceOfRanges & (IntTools_BeanFaceIntersector::*)() const) &IntTools_BeanFaceIntersector::Result, "None");
cls_IntTools_BeanFaceIntersector.def("Result", (void (IntTools_BeanFaceIntersector::*)(IntTools_SequenceOfRanges &) const) &IntTools_BeanFaceIntersector::Result, "None", py::arg("theResults"));

// CLASS: INTTOOLS_CARRAY1OFINTEGER
py::class_<IntTools_CArray1OfInteger> cls_IntTools_CArray1OfInteger(mod, "IntTools_CArray1OfInteger", "None");

// Constructors
cls_IntTools_CArray1OfInteger.def(py::init<>());
cls_IntTools_CArray1OfInteger.def(py::init<const Standard_Integer>(), py::arg("Length"));
cls_IntTools_CArray1OfInteger.def(py::init<const Standard_Integer &, const Standard_Integer>(), py::arg("Item"), py::arg("Length"));

// Methods
// cls_IntTools_CArray1OfInteger.def_static("operator new_", (void * (*)(size_t)) &IntTools_CArray1OfInteger::operator new, "None", py::arg("theSize"));
// cls_IntTools_CArray1OfInteger.def_static("operator delete_", (void (*)(void *)) &IntTools_CArray1OfInteger::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_CArray1OfInteger.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_CArray1OfInteger::operator new[], "None", py::arg("theSize"));
// cls_IntTools_CArray1OfInteger.def_static("operator delete[]_", (void (*)(void *)) &IntTools_CArray1OfInteger::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_CArray1OfInteger.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_CArray1OfInteger::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_CArray1OfInteger.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_CArray1OfInteger::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_CArray1OfInteger.def("Init", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer &)) &IntTools_CArray1OfInteger::Init, "Initializes the array with a given value.", py::arg("V"));
cls_IntTools_CArray1OfInteger.def("Resize", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer)) &IntTools_CArray1OfInteger::Resize, "destroy current content and realloc the new size does nothing if Length() == theLength", py::arg("theNewLength"));
cls_IntTools_CArray1OfInteger.def("Destroy", (void (IntTools_CArray1OfInteger::*)()) &IntTools_CArray1OfInteger::Destroy, "Frees the allocated area corresponding to the array.");
cls_IntTools_CArray1OfInteger.def("Length", (Standard_Integer (IntTools_CArray1OfInteger::*)() const) &IntTools_CArray1OfInteger::Length, "Returns the number of elements of <me>.");
cls_IntTools_CArray1OfInteger.def("Append", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer &)) &IntTools_CArray1OfInteger::Append, "None", py::arg("Value"));
cls_IntTools_CArray1OfInteger.def("SetValue", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer, const Standard_Integer &)) &IntTools_CArray1OfInteger::SetValue, "Sets the <Index>th element of the array to <Value>.", py::arg("Index"), py::arg("Value"));
cls_IntTools_CArray1OfInteger.def("Value", (const Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer) const) &IntTools_CArray1OfInteger::Value, "Returns the value of the <Index>th element of the array.", py::arg("Index"));
cls_IntTools_CArray1OfInteger.def("__call__", (const Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer) const) &IntTools_CArray1OfInteger::operator(), py::is_operator(), "None", py::arg("Index"));
cls_IntTools_CArray1OfInteger.def("ChangeValue", (Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer)) &IntTools_CArray1OfInteger::ChangeValue, "Returns the value of the <Index>th element of the array.", py::arg("Index"));
cls_IntTools_CArray1OfInteger.def("__call__", (Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer)) &IntTools_CArray1OfInteger::operator(), py::is_operator(), "None", py::arg("Index"));
cls_IntTools_CArray1OfInteger.def("IsEqual", (Standard_Boolean (IntTools_CArray1OfInteger::*)(const IntTools_CArray1OfInteger &) const) &IntTools_CArray1OfInteger::IsEqual, "Applys the == operator on each array item", py::arg("Other"));
cls_IntTools_CArray1OfInteger.def("__eq__", (Standard_Boolean (IntTools_CArray1OfInteger::*)(const IntTools_CArray1OfInteger &) const) &IntTools_CArray1OfInteger::operator==, py::is_operator(), "None", py::arg("Other"));

// CLASS: INTTOOLS_CARRAY1OFREAL
py::class_<IntTools_CArray1OfReal> cls_IntTools_CArray1OfReal(mod, "IntTools_CArray1OfReal", "None");

// Constructors
cls_IntTools_CArray1OfReal.def(py::init<>());
cls_IntTools_CArray1OfReal.def(py::init<const Standard_Integer>(), py::arg("Length"));
cls_IntTools_CArray1OfReal.def(py::init<const Standard_Real &, const Standard_Integer>(), py::arg("Item"), py::arg("Length"));

// Methods
// cls_IntTools_CArray1OfReal.def_static("operator new_", (void * (*)(size_t)) &IntTools_CArray1OfReal::operator new, "None", py::arg("theSize"));
// cls_IntTools_CArray1OfReal.def_static("operator delete_", (void (*)(void *)) &IntTools_CArray1OfReal::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_CArray1OfReal.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_CArray1OfReal::operator new[], "None", py::arg("theSize"));
// cls_IntTools_CArray1OfReal.def_static("operator delete[]_", (void (*)(void *)) &IntTools_CArray1OfReal::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_CArray1OfReal.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_CArray1OfReal::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_CArray1OfReal.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_CArray1OfReal::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_CArray1OfReal.def("Init", (void (IntTools_CArray1OfReal::*)(const Standard_Real &)) &IntTools_CArray1OfReal::Init, "Initializes the array with a given value.", py::arg("V"));
cls_IntTools_CArray1OfReal.def("Resize", (void (IntTools_CArray1OfReal::*)(const Standard_Integer)) &IntTools_CArray1OfReal::Resize, "destroy current content and realloc the new size does nothing if Length() == theLength", py::arg("theNewLength"));
cls_IntTools_CArray1OfReal.def("Destroy", (void (IntTools_CArray1OfReal::*)()) &IntTools_CArray1OfReal::Destroy, "Frees the allocated area corresponding to the array.");
cls_IntTools_CArray1OfReal.def("Length", (Standard_Integer (IntTools_CArray1OfReal::*)() const) &IntTools_CArray1OfReal::Length, "Returns the number of elements of <me>.");
cls_IntTools_CArray1OfReal.def("Append", (void (IntTools_CArray1OfReal::*)(const Standard_Real &)) &IntTools_CArray1OfReal::Append, "None", py::arg("Value"));
cls_IntTools_CArray1OfReal.def("SetValue", (void (IntTools_CArray1OfReal::*)(const Standard_Integer, const Standard_Real &)) &IntTools_CArray1OfReal::SetValue, "Sets the <Index>th element of the array to <Value>.", py::arg("Index"), py::arg("Value"));
cls_IntTools_CArray1OfReal.def("Value", (const Standard_Real & (IntTools_CArray1OfReal::*)(const Standard_Integer) const) &IntTools_CArray1OfReal::Value, "Returns the value of the <Index>th element of the array.", py::arg("Index"));
cls_IntTools_CArray1OfReal.def("__call__", (const Standard_Real & (IntTools_CArray1OfReal::*)(const Standard_Integer) const) &IntTools_CArray1OfReal::operator(), py::is_operator(), "None", py::arg("Index"));
cls_IntTools_CArray1OfReal.def("ChangeValue", (Standard_Real & (IntTools_CArray1OfReal::*)(const Standard_Integer)) &IntTools_CArray1OfReal::ChangeValue, "Returns the value of the <Index>th element of the array.", py::arg("Index"));
cls_IntTools_CArray1OfReal.def("__call__", (Standard_Real & (IntTools_CArray1OfReal::*)(const Standard_Integer)) &IntTools_CArray1OfReal::operator(), py::is_operator(), "None", py::arg("Index"));
cls_IntTools_CArray1OfReal.def("IsEqual", (Standard_Boolean (IntTools_CArray1OfReal::*)(const IntTools_CArray1OfReal &) const) &IntTools_CArray1OfReal::IsEqual, "Applys the == operator on each array item", py::arg("Other"));
cls_IntTools_CArray1OfReal.def("__eq__", (Standard_Boolean (IntTools_CArray1OfReal::*)(const IntTools_CArray1OfReal &) const) &IntTools_CArray1OfReal::operator==, py::is_operator(), "None", py::arg("Other"));

// CLASS: INTTOOLS_CURVERANGESAMPLEMAPHASHER
py::class_<IntTools_CurveRangeSampleMapHasher> cls_IntTools_CurveRangeSampleMapHasher(mod, "IntTools_CurveRangeSampleMapHasher", "class for range index management of curve");

// Constructors
cls_IntTools_CurveRangeSampleMapHasher.def(py::init<>());

// Methods
// cls_IntTools_CurveRangeSampleMapHasher.def_static("operator new_", (void * (*)(size_t)) &IntTools_CurveRangeSampleMapHasher::operator new, "None", py::arg("theSize"));
// cls_IntTools_CurveRangeSampleMapHasher.def_static("operator delete_", (void (*)(void *)) &IntTools_CurveRangeSampleMapHasher::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_CurveRangeSampleMapHasher.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_CurveRangeSampleMapHasher::operator new[], "None", py::arg("theSize"));
// cls_IntTools_CurveRangeSampleMapHasher.def_static("operator delete[]_", (void (*)(void *)) &IntTools_CurveRangeSampleMapHasher::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_CurveRangeSampleMapHasher.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_CurveRangeSampleMapHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_CurveRangeSampleMapHasher.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_CurveRangeSampleMapHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_CurveRangeSampleMapHasher.def_static("HashCode_", (Standard_Integer (*)(const IntTools_CurveRangeSample &, const Standard_Integer)) &IntTools_CurveRangeSampleMapHasher::HashCode, "Computes a hash code for the given key, in the range [1, theUpperBound]", py::arg("theKey"), py::arg("theUpperBound"));
cls_IntTools_CurveRangeSampleMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const IntTools_CurveRangeSample &, const IntTools_CurveRangeSample &)) &IntTools_CurveRangeSampleMapHasher::IsEqual, "Returns True when the two keys are the same. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("S1"), py::arg("S2"));

// TYPEDEF: INTTOOLS_MAPOFCURVESAMPLE
bind_NCollection_Map<IntTools_CurveRangeSample, IntTools_CurveRangeSampleMapHasher>(mod, "IntTools_MapOfCurveSample", py::module_local(false));

// TYPEDEF: INTTOOLS_MAPITERATOROFMAPOFCURVESAMPLE

// TYPEDEF: INTTOOLS_DATAMAPOFCURVESAMPLEBOX
bind_NCollection_DataMap<IntTools_CurveRangeSample, Bnd_Box, IntTools_CurveRangeSampleMapHasher>(mod, "IntTools_DataMapOfCurveSampleBox", py::module_local(false));

// TYPEDEF: INTTOOLS_DATAMAPITERATOROFDATAMAPOFCURVESAMPLEBOX

// CLASS: INTTOOLS_CURVERANGELOCALIZEDATA
py::class_<IntTools_CurveRangeLocalizeData> cls_IntTools_CurveRangeLocalizeData(mod, "IntTools_CurveRangeLocalizeData", "None");

// Constructors
cls_IntTools_CurveRangeLocalizeData.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("theNbSample"), py::arg("theMinRange"));

// Methods
// cls_IntTools_CurveRangeLocalizeData.def_static("operator new_", (void * (*)(size_t)) &IntTools_CurveRangeLocalizeData::operator new, "None", py::arg("theSize"));
// cls_IntTools_CurveRangeLocalizeData.def_static("operator delete_", (void (*)(void *)) &IntTools_CurveRangeLocalizeData::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_CurveRangeLocalizeData.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_CurveRangeLocalizeData::operator new[], "None", py::arg("theSize"));
// cls_IntTools_CurveRangeLocalizeData.def_static("operator delete[]_", (void (*)(void *)) &IntTools_CurveRangeLocalizeData::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_CurveRangeLocalizeData.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_CurveRangeLocalizeData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_CurveRangeLocalizeData.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_CurveRangeLocalizeData::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_CurveRangeLocalizeData.def("GetNbSample", (Standard_Integer (IntTools_CurveRangeLocalizeData::*)() const) &IntTools_CurveRangeLocalizeData::GetNbSample, "None");
cls_IntTools_CurveRangeLocalizeData.def("GetMinRange", (Standard_Real (IntTools_CurveRangeLocalizeData::*)() const) &IntTools_CurveRangeLocalizeData::GetMinRange, "None");
cls_IntTools_CurveRangeLocalizeData.def("AddOutRange", (void (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &)) &IntTools_CurveRangeLocalizeData::AddOutRange, "None", py::arg("theRange"));
cls_IntTools_CurveRangeLocalizeData.def("AddBox", (void (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &, const Bnd_Box &)) &IntTools_CurveRangeLocalizeData::AddBox, "None", py::arg("theRange"), py::arg("theBox"));
cls_IntTools_CurveRangeLocalizeData.def("FindBox", (Standard_Boolean (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &, Bnd_Box &) const) &IntTools_CurveRangeLocalizeData::FindBox, "None", py::arg("theRange"), py::arg("theBox"));
cls_IntTools_CurveRangeLocalizeData.def("IsRangeOut", (Standard_Boolean (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &) const) &IntTools_CurveRangeLocalizeData::IsRangeOut, "None", py::arg("theRange"));
cls_IntTools_CurveRangeLocalizeData.def("ListRangeOut", (void (IntTools_CurveRangeLocalizeData::*)(IntTools_ListOfCurveRangeSample &) const) &IntTools_CurveRangeLocalizeData::ListRangeOut, "None", py::arg("theList"));

// CLASS: INTTOOLS_SURFACERANGESAMPLEMAPHASHER
py::class_<IntTools_SurfaceRangeSampleMapHasher> cls_IntTools_SurfaceRangeSampleMapHasher(mod, "IntTools_SurfaceRangeSampleMapHasher", "None");

// Constructors
cls_IntTools_SurfaceRangeSampleMapHasher.def(py::init<>());

// Methods
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator new_", (void * (*)(size_t)) &IntTools_SurfaceRangeSampleMapHasher::operator new, "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator delete_", (void (*)(void *)) &IntTools_SurfaceRangeSampleMapHasher::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_SurfaceRangeSampleMapHasher::operator new[], "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator delete[]_", (void (*)(void *)) &IntTools_SurfaceRangeSampleMapHasher::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_SurfaceRangeSampleMapHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_SurfaceRangeSampleMapHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_SurfaceRangeSampleMapHasher.def_static("HashCode_", (Standard_Integer (*)(const IntTools_SurfaceRangeSample &, Standard_Integer)) &IntTools_SurfaceRangeSampleMapHasher::HashCode, "Computes a hash code for the given key, in the range [1, theUpperBound]", py::arg("theKey"), py::arg("theUpperBound"));
cls_IntTools_SurfaceRangeSampleMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const IntTools_SurfaceRangeSample &, const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeSampleMapHasher::IsEqual, "Returns True when the two keys are the same. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("S1"), py::arg("S2"));

// TYPEDEF: INTTOOLS_DATAMAPOFSURFACESAMPLEBOX
bind_NCollection_DataMap<IntTools_SurfaceRangeSample, Bnd_Box, IntTools_SurfaceRangeSampleMapHasher>(mod, "IntTools_DataMapOfSurfaceSampleBox", py::module_local(false));

// TYPEDEF: INTTOOLS_DATAMAPITERATOROFDATAMAPOFSURFACESAMPLEBOX

// TYPEDEF: INTTOOLS_SEQUENCEOFCOMMONPRTS
bind_NCollection_Sequence<IntTools_CommonPrt>(mod, "IntTools_SequenceOfCommonPrts", py::module_local(false));

// CLASS: INTTOOLS_EDGEEDGE
py::class_<IntTools_EdgeEdge> cls_IntTools_EdgeEdge(mod, "IntTools_EdgeEdge", "The class provides Edge/Edge intersection algorithm based on the intersection between edges bounding boxes.");

// Constructors
cls_IntTools_EdgeEdge.def(py::init<>());
cls_IntTools_EdgeEdge.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("theEdge1"), py::arg("theEdge2"));
cls_IntTools_EdgeEdge.def(py::init<const TopoDS_Edge &, const Standard_Real, const Standard_Real, const TopoDS_Edge &, const Standard_Real, const Standard_Real>(), py::arg("theEdge1"), py::arg("aT11"), py::arg("aT12"), py::arg("theEdge2"), py::arg("aT21"), py::arg("aT22"));

// Methods
// cls_IntTools_EdgeEdge.def_static("operator new_", (void * (*)(size_t)) &IntTools_EdgeEdge::operator new, "None", py::arg("theSize"));
// cls_IntTools_EdgeEdge.def_static("operator delete_", (void (*)(void *)) &IntTools_EdgeEdge::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_EdgeEdge.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_EdgeEdge::operator new[], "None", py::arg("theSize"));
// cls_IntTools_EdgeEdge.def_static("operator delete[]_", (void (*)(void *)) &IntTools_EdgeEdge::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_EdgeEdge.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_EdgeEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_EdgeEdge.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_EdgeEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_EdgeEdge.def("SetEdge1", (void (IntTools_EdgeEdge::*)(const TopoDS_Edge &)) &IntTools_EdgeEdge::SetEdge1, "Sets the first edge", py::arg("theEdge"));
cls_IntTools_EdgeEdge.def("SetEdge1", (void (IntTools_EdgeEdge::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &IntTools_EdgeEdge::SetEdge1, "Sets the first edge and its range", py::arg("theEdge"), py::arg("aT1"), py::arg("aT2"));
cls_IntTools_EdgeEdge.def("SetRange1", (void (IntTools_EdgeEdge::*)(const IntTools_Range &)) &IntTools_EdgeEdge::SetRange1, "Sets the range for the first edge", py::arg("theRange1"));
cls_IntTools_EdgeEdge.def("SetRange1", (void (IntTools_EdgeEdge::*)(const Standard_Real, const Standard_Real)) &IntTools_EdgeEdge::SetRange1, "Sets the range for the first edge", py::arg("aT1"), py::arg("aT2"));
cls_IntTools_EdgeEdge.def("SetEdge2", (void (IntTools_EdgeEdge::*)(const TopoDS_Edge &)) &IntTools_EdgeEdge::SetEdge2, "Sets the second edge", py::arg("theEdge"));
cls_IntTools_EdgeEdge.def("SetEdge2", (void (IntTools_EdgeEdge::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &IntTools_EdgeEdge::SetEdge2, "Sets the first edge and its range", py::arg("theEdge"), py::arg("aT1"), py::arg("aT2"));
cls_IntTools_EdgeEdge.def("SetRange2", (void (IntTools_EdgeEdge::*)(const IntTools_Range &)) &IntTools_EdgeEdge::SetRange2, "Sets the range for the second edge", py::arg("theRange"));
cls_IntTools_EdgeEdge.def("SetRange2", (void (IntTools_EdgeEdge::*)(const Standard_Real, const Standard_Real)) &IntTools_EdgeEdge::SetRange2, "Sets the range for the second edge", py::arg("aT1"), py::arg("aT2"));
cls_IntTools_EdgeEdge.def("SetFuzzyValue", (void (IntTools_EdgeEdge::*)(const Standard_Real)) &IntTools_EdgeEdge::SetFuzzyValue, "Sets the Fuzzy value", py::arg("theFuzz"));
cls_IntTools_EdgeEdge.def("Perform", (void (IntTools_EdgeEdge::*)()) &IntTools_EdgeEdge::Perform, "Performs the intersection between edges");
cls_IntTools_EdgeEdge.def("IsDone", (Standard_Boolean (IntTools_EdgeEdge::*)() const) &IntTools_EdgeEdge::IsDone, "Returns TRUE if common part(s) is(are) found");
cls_IntTools_EdgeEdge.def("FuzzyValue", (Standard_Real (IntTools_EdgeEdge::*)() const) &IntTools_EdgeEdge::FuzzyValue, "Returns Fuzzy value");
cls_IntTools_EdgeEdge.def("CommonParts", (const IntTools_SequenceOfCommonPrts & (IntTools_EdgeEdge::*)() const) &IntTools_EdgeEdge::CommonParts, "Returns common parts");
cls_IntTools_EdgeEdge.def("UseQuickCoincidenceCheck", (void (IntTools_EdgeEdge::*)(const Standard_Boolean)) &IntTools_EdgeEdge::UseQuickCoincidenceCheck, "Sets the flag myQuickCoincidenceCheck", py::arg("bFlag"));
cls_IntTools_EdgeEdge.def("IsCoincidenceCheckedQuickly", (Standard_Boolean (IntTools_EdgeEdge::*)()) &IntTools_EdgeEdge::IsCoincidenceCheckedQuickly, "Returns the flag myQuickCoincidenceCheck");

// CLASS: INTTOOLS_EDGEFACE
py::class_<IntTools_EdgeFace> cls_IntTools_EdgeFace(mod, "IntTools_EdgeFace", "The class provides Edge/Face intersection algorithm to determine common parts between edge and face in 3-d space. Common parts between Edge and Face can be: - Vertices - in case of intersection or touching; - Edge - in case of full coincidence of the edge with the face.");

// Constructors
cls_IntTools_EdgeFace.def(py::init<>());

// Methods
// cls_IntTools_EdgeFace.def_static("operator new_", (void * (*)(size_t)) &IntTools_EdgeFace::operator new, "None", py::arg("theSize"));
// cls_IntTools_EdgeFace.def_static("operator delete_", (void (*)(void *)) &IntTools_EdgeFace::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_EdgeFace.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_EdgeFace::operator new[], "None", py::arg("theSize"));
// cls_IntTools_EdgeFace.def_static("operator delete[]_", (void (*)(void *)) &IntTools_EdgeFace::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_EdgeFace.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_EdgeFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_EdgeFace.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_EdgeFace::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_EdgeFace.def("SetEdge", (void (IntTools_EdgeFace::*)(const TopoDS_Edge &)) &IntTools_EdgeFace::SetEdge, "Sets the edge for intersection", py::arg("theEdge"));
cls_IntTools_EdgeFace.def("Edge", (const TopoDS_Edge & (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::Edge, "Returns the edge");
cls_IntTools_EdgeFace.def("SetFace", (void (IntTools_EdgeFace::*)(const TopoDS_Face &)) &IntTools_EdgeFace::SetFace, "Sets the face for intersection", py::arg("theFace"));
cls_IntTools_EdgeFace.def("Face", (const TopoDS_Face & (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::Face, "Returns the face");
cls_IntTools_EdgeFace.def("SetRange", (void (IntTools_EdgeFace::*)(const IntTools_Range &)) &IntTools_EdgeFace::SetRange, "Sets the boundaries for the edge. The algorithm processes edge inside these boundaries.", py::arg("theRange"));
cls_IntTools_EdgeFace.def("SetRange", (void (IntTools_EdgeFace::*)(const Standard_Real, const Standard_Real)) &IntTools_EdgeFace::SetRange, "Sets the boundaries for the edge. The algorithm processes edge inside these boundaries.", py::arg("theFirst"), py::arg("theLast"));
cls_IntTools_EdgeFace.def("Range", (const IntTools_Range & (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::Range, "Returns intersection range of the edge");
cls_IntTools_EdgeFace.def("SetContext", (void (IntTools_EdgeFace::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_EdgeFace::SetContext, "Sets the intersection context", py::arg("theContext"));
cls_IntTools_EdgeFace.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::Context, "Returns the intersection context");
cls_IntTools_EdgeFace.def("SetFuzzyValue", (void (IntTools_EdgeFace::*)(const Standard_Real)) &IntTools_EdgeFace::SetFuzzyValue, "Sets the Fuzzy value", py::arg("theFuzz"));
cls_IntTools_EdgeFace.def("FuzzyValue", (Standard_Real (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::FuzzyValue, "Returns the Fuzzy value");
cls_IntTools_EdgeFace.def("UseQuickCoincidenceCheck", (void (IntTools_EdgeFace::*)(const Standard_Boolean)) &IntTools_EdgeFace::UseQuickCoincidenceCheck, "Sets the flag for quick coincidence check. It is safe to use the quick check for coincidence only if both of the following conditions are met: - The vertices of edge are lying on the face; - The edge does not intersect the boundaries of the face on the given range.", py::arg("theFlag"));
cls_IntTools_EdgeFace.def("IsCoincidenceCheckedQuickly", (Standard_Boolean (IntTools_EdgeFace::*)()) &IntTools_EdgeFace::IsCoincidenceCheckedQuickly, "Returns the flag myQuickCoincidenceCheck");
cls_IntTools_EdgeFace.def("Perform", (void (IntTools_EdgeFace::*)()) &IntTools_EdgeFace::Perform, "Launches the process");
cls_IntTools_EdgeFace.def("IsDone", (Standard_Boolean (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::IsDone, "Returns TRUE if computation was successful. Otherwise returns FALSE.");
cls_IntTools_EdgeFace.def("ErrorStatus", (Standard_Integer (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::ErrorStatus, "Returns the code of completion: 0 - means successful completion; 1 - the process was not started; 2,3 - invalid source data for the algorithm; 4 - projection failed.");
cls_IntTools_EdgeFace.def("CommonParts", (const IntTools_SequenceOfCommonPrts & (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::CommonParts, "Returns resulting common parts");

// TYPEDEF: INTTOOLS_SEQUENCEOFCURVES
bind_NCollection_Sequence<IntTools_Curve>(mod, "IntTools_SequenceOfCurves", py::module_local(false));

// CLASS: INTTOOLS_PNTONFACE
py::class_<IntTools_PntOnFace> cls_IntTools_PntOnFace(mod, "IntTools_PntOnFace", "Contains a Face, a 3d point, corresponded UV parameters and a flag");

// Constructors
cls_IntTools_PntOnFace.def(py::init<>());

// Methods
// cls_IntTools_PntOnFace.def_static("operator new_", (void * (*)(size_t)) &IntTools_PntOnFace::operator new, "None", py::arg("theSize"));
// cls_IntTools_PntOnFace.def_static("operator delete_", (void (*)(void *)) &IntTools_PntOnFace::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_PntOnFace.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_PntOnFace::operator new[], "None", py::arg("theSize"));
// cls_IntTools_PntOnFace.def_static("operator delete[]_", (void (*)(void *)) &IntTools_PntOnFace::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_PntOnFace.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_PntOnFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_PntOnFace.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_PntOnFace::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_PntOnFace.def("Init", (void (IntTools_PntOnFace::*)(const TopoDS_Face &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &IntTools_PntOnFace::Init, "Initializes me by aFace, a 3d point and it's UV parameters on face", py::arg("aF"), py::arg("aP"), py::arg("U"), py::arg("V"));
cls_IntTools_PntOnFace.def("SetFace", (void (IntTools_PntOnFace::*)(const TopoDS_Face &)) &IntTools_PntOnFace::SetFace, "Modifier", py::arg("aF"));
cls_IntTools_PntOnFace.def("SetPnt", (void (IntTools_PntOnFace::*)(const gp_Pnt &)) &IntTools_PntOnFace::SetPnt, "Modifier", py::arg("aP"));
cls_IntTools_PntOnFace.def("SetParameters", (void (IntTools_PntOnFace::*)(const Standard_Real, const Standard_Real)) &IntTools_PntOnFace::SetParameters, "Modifier", py::arg("U"), py::arg("V"));
cls_IntTools_PntOnFace.def("SetValid", (void (IntTools_PntOnFace::*)(const Standard_Boolean)) &IntTools_PntOnFace::SetValid, "Modifier", py::arg("bF"));
cls_IntTools_PntOnFace.def("Valid", (Standard_Boolean (IntTools_PntOnFace::*)() const) &IntTools_PntOnFace::Valid, "Selector");
cls_IntTools_PntOnFace.def("Face", (const TopoDS_Face & (IntTools_PntOnFace::*)() const) &IntTools_PntOnFace::Face, "Selector");
cls_IntTools_PntOnFace.def("Pnt", (const gp_Pnt & (IntTools_PntOnFace::*)() const) &IntTools_PntOnFace::Pnt, "Selector");
cls_IntTools_PntOnFace.def("Parameters", [](IntTools_PntOnFace &self, Standard_Real & U, Standard_Real & V){ self.Parameters(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Selector", py::arg("U"), py::arg("V"));
// cls_IntTools_PntOnFace.def("IsValid", (Standard_Boolean (IntTools_PntOnFace::*)() const) &IntTools_PntOnFace::IsValid, "Selector");

// CLASS: INTTOOLS_PNTON2FACES
py::class_<IntTools_PntOn2Faces> cls_IntTools_PntOn2Faces(mod, "IntTools_PntOn2Faces", "Contains two points PntOnFace from IntTools and a flag");

// Constructors
cls_IntTools_PntOn2Faces.def(py::init<>());
cls_IntTools_PntOn2Faces.def(py::init<const IntTools_PntOnFace &, const IntTools_PntOnFace &>(), py::arg("aP1"), py::arg("aP2"));

// Methods
// cls_IntTools_PntOn2Faces.def_static("operator new_", (void * (*)(size_t)) &IntTools_PntOn2Faces::operator new, "None", py::arg("theSize"));
// cls_IntTools_PntOn2Faces.def_static("operator delete_", (void (*)(void *)) &IntTools_PntOn2Faces::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_PntOn2Faces.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_PntOn2Faces::operator new[], "None", py::arg("theSize"));
// cls_IntTools_PntOn2Faces.def_static("operator delete[]_", (void (*)(void *)) &IntTools_PntOn2Faces::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_PntOn2Faces.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_PntOn2Faces::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_PntOn2Faces.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_PntOn2Faces::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_PntOn2Faces.def("SetP1", (void (IntTools_PntOn2Faces::*)(const IntTools_PntOnFace &)) &IntTools_PntOn2Faces::SetP1, "Modifier", py::arg("aP1"));
cls_IntTools_PntOn2Faces.def("SetP2", (void (IntTools_PntOn2Faces::*)(const IntTools_PntOnFace &)) &IntTools_PntOn2Faces::SetP2, "Modifier", py::arg("aP2"));
cls_IntTools_PntOn2Faces.def("SetValid", (void (IntTools_PntOn2Faces::*)(const Standard_Boolean)) &IntTools_PntOn2Faces::SetValid, "Modifier", py::arg("bF"));
cls_IntTools_PntOn2Faces.def("P1", (const IntTools_PntOnFace & (IntTools_PntOn2Faces::*)() const) &IntTools_PntOn2Faces::P1, "Selector");
cls_IntTools_PntOn2Faces.def("P2", (const IntTools_PntOnFace & (IntTools_PntOn2Faces::*)() const) &IntTools_PntOn2Faces::P2, "Selector");
cls_IntTools_PntOn2Faces.def("IsValid", (Standard_Boolean (IntTools_PntOn2Faces::*)() const) &IntTools_PntOn2Faces::IsValid, "Selector");

// TYPEDEF: INTTOOLS_SEQUENCEOFPNTON2FACES
bind_NCollection_Sequence<IntTools_PntOn2Faces>(mod, "IntTools_SequenceOfPntOn2Faces", py::module_local(false));

// CLASS: INTTOOLS_FACEFACE
py::class_<IntTools_FaceFace> cls_IntTools_FaceFace(mod, "IntTools_FaceFace", "This class provides the intersection of face's underlying surfaces.");

// Constructors
cls_IntTools_FaceFace.def(py::init<>());

// Methods
// cls_IntTools_FaceFace.def_static("operator new_", (void * (*)(size_t)) &IntTools_FaceFace::operator new, "None", py::arg("theSize"));
// cls_IntTools_FaceFace.def_static("operator delete_", (void (*)(void *)) &IntTools_FaceFace::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_FaceFace.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_FaceFace::operator new[], "None", py::arg("theSize"));
// cls_IntTools_FaceFace.def_static("operator delete[]_", (void (*)(void *)) &IntTools_FaceFace::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_FaceFace.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_FaceFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_FaceFace.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_FaceFace::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_FaceFace.def("SetParameters", (void (IntTools_FaceFace::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real)) &IntTools_FaceFace::SetParameters, "Modifier", py::arg("ApproxCurves"), py::arg("ComputeCurveOnS1"), py::arg("ComputeCurveOnS2"), py::arg("ApproximationTolerance"));
cls_IntTools_FaceFace.def("Perform", (void (IntTools_FaceFace::*)(const TopoDS_Face &, const TopoDS_Face &)) &IntTools_FaceFace::Perform, "Intersects underliing surfaces of F1 and F2 Use sum of tolerance of F1 and F2 as intersection criteria", py::arg("F1"), py::arg("F2"));
cls_IntTools_FaceFace.def("IsDone", (Standard_Boolean (IntTools_FaceFace::*)() const) &IntTools_FaceFace::IsDone, "Returns True if the intersection was successful");
cls_IntTools_FaceFace.def("Lines", (const IntTools_SequenceOfCurves & (IntTools_FaceFace::*)() const) &IntTools_FaceFace::Lines, "Returns sequence of 3d curves as result of intersection");
cls_IntTools_FaceFace.def("Points", (const IntTools_SequenceOfPntOn2Faces & (IntTools_FaceFace::*)() const) &IntTools_FaceFace::Points, "Returns sequence of 3d curves as result of intersection");
cls_IntTools_FaceFace.def("Face1", (const TopoDS_Face & (IntTools_FaceFace::*)() const) &IntTools_FaceFace::Face1, "Returns first of processed faces");
cls_IntTools_FaceFace.def("Face2", (const TopoDS_Face & (IntTools_FaceFace::*)() const) &IntTools_FaceFace::Face2, "Returns second of processed faces");
cls_IntTools_FaceFace.def("TangentFaces", (Standard_Boolean (IntTools_FaceFace::*)() const) &IntTools_FaceFace::TangentFaces, "Returns True if faces are tangent");
cls_IntTools_FaceFace.def("PrepareLines3D", [](IntTools_FaceFace &self) -> void { return self.PrepareLines3D(); });
cls_IntTools_FaceFace.def("PrepareLines3D", (void (IntTools_FaceFace::*)(const Standard_Boolean)) &IntTools_FaceFace::PrepareLines3D, "Provides post-processing the result lines. <bToSplit> - the flag. In case of <bToSplit> is true the closed 3D-curves will be splitted on parts. In case of <bToSplit> is false the closed 3D-curves remain untouched.", py::arg("bToSplit"));
cls_IntTools_FaceFace.def("SetList", (void (IntTools_FaceFace::*)(IntSurf_ListOfPntOn2S &)) &IntTools_FaceFace::SetList, "None", py::arg("ListOfPnts"));
cls_IntTools_FaceFace.def("SetContext", (void (IntTools_FaceFace::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_FaceFace::SetContext, "Sets the intersecton context", py::arg("aContext"));
cls_IntTools_FaceFace.def("SetFuzzyValue", (void (IntTools_FaceFace::*)(const Standard_Real)) &IntTools_FaceFace::SetFuzzyValue, "Sets the Fuzzy value", py::arg("theFuzz"));
cls_IntTools_FaceFace.def("FuzzyValue", (Standard_Real (IntTools_FaceFace::*)() const) &IntTools_FaceFace::FuzzyValue, "Returns Fuzzy value");
cls_IntTools_FaceFace.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_FaceFace::*)() const) &IntTools_FaceFace::Context, "Gets the intersecton context");

// CLASS: INTTOOLS_FCLASS2D
py::class_<IntTools_FClass2d> cls_IntTools_FClass2d(mod, "IntTools_FClass2d", "Class provides an algorithm to classify a 2d Point in 2d space of face using boundaries of the face.");

// Constructors
cls_IntTools_FClass2d.def(py::init<>());
cls_IntTools_FClass2d.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("F"), py::arg("Tol"));

// Methods
// cls_IntTools_FClass2d.def_static("operator new_", (void * (*)(size_t)) &IntTools_FClass2d::operator new, "None", py::arg("theSize"));
// cls_IntTools_FClass2d.def_static("operator delete_", (void (*)(void *)) &IntTools_FClass2d::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_FClass2d.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_FClass2d::operator new[], "None", py::arg("theSize"));
// cls_IntTools_FClass2d.def_static("operator delete[]_", (void (*)(void *)) &IntTools_FClass2d::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_FClass2d.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_FClass2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_FClass2d.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_FClass2d::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_FClass2d.def("Init", (void (IntTools_FClass2d::*)(const TopoDS_Face &, const Standard_Real)) &IntTools_FClass2d::Init, "Initializes algorithm by the face F and tolerance Tol", py::arg("F"), py::arg("Tol"));
cls_IntTools_FClass2d.def("PerformInfinitePoint", (TopAbs_State (IntTools_FClass2d::*)() const) &IntTools_FClass2d::PerformInfinitePoint, "Returns state of infinite 2d point relatively to (0, 0)");
cls_IntTools_FClass2d.def("Perform", [](IntTools_FClass2d &self, const gp_Pnt2d & a0) -> TopAbs_State { return self.Perform(a0); });
cls_IntTools_FClass2d.def("Perform", (TopAbs_State (IntTools_FClass2d::*)(const gp_Pnt2d &, const Standard_Boolean) const) &IntTools_FClass2d::Perform, "Returns state of the 2d point Puv. If RecadreOnPeriodic is true (defalut value), for the periodic surface 2d point, adjusted to period, is classified.", py::arg("Puv"), py::arg("RecadreOnPeriodic"));
cls_IntTools_FClass2d.def("Destroy", (void (IntTools_FClass2d::*)()) &IntTools_FClass2d::Destroy, "Destructor");
cls_IntTools_FClass2d.def("TestOnRestriction", [](IntTools_FClass2d &self, const gp_Pnt2d & a0, const Standard_Real a1) -> TopAbs_State { return self.TestOnRestriction(a0, a1); });
cls_IntTools_FClass2d.def("TestOnRestriction", (TopAbs_State (IntTools_FClass2d::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean) const) &IntTools_FClass2d::TestOnRestriction, "Test a point with +- an offset (Tol) and returns On if some points are OUT an some are IN (Caution: Internal use . see the code for more details)", py::arg("Puv"), py::arg("Tol"), py::arg("RecadreOnPeriodic"));
cls_IntTools_FClass2d.def("IsHole", (Standard_Boolean (IntTools_FClass2d::*)() const) &IntTools_FClass2d::IsHole, "None");

// TYPEDEF: INTTOOLS_LISTOFBOX
bind_NCollection_List<Bnd_Box>(mod, "IntTools_ListOfBox", py::module_local(false));

// TYPEDEF: INTTOOLS_LISTITERATOROFLISTOFBOX
bind_NCollection_TListIterator<Bnd_Box>(mod, "IntTools_ListIteratorOfListOfBox", py::module_local(false));

// TYPEDEF: INTTOOLS_MAPOFSURFACESAMPLE
bind_NCollection_Map<IntTools_SurfaceRangeSample, IntTools_SurfaceRangeSampleMapHasher>(mod, "IntTools_MapOfSurfaceSample", py::module_local(false));

// TYPEDEF: INTTOOLS_MAPITERATOROFMAPOFSURFACESAMPLE

// CLASS: INTTOOLS_SURFACERANGELOCALIZEDATA
py::class_<IntTools_SurfaceRangeLocalizeData> cls_IntTools_SurfaceRangeLocalizeData(mod, "IntTools_SurfaceRangeLocalizeData", "None");

// Constructors
cls_IntTools_SurfaceRangeLocalizeData.def(py::init<>());
cls_IntTools_SurfaceRangeLocalizeData.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("theNbSampleU"), py::arg("theNbSampleV"), py::arg("theMinRangeU"), py::arg("theMinRangeV"));
cls_IntTools_SurfaceRangeLocalizeData.def(py::init<const IntTools_SurfaceRangeLocalizeData &>(), py::arg("Other"));

// Methods
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator new_", (void * (*)(size_t)) &IntTools_SurfaceRangeLocalizeData::operator new, "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator delete_", (void (*)(void *)) &IntTools_SurfaceRangeLocalizeData::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_SurfaceRangeLocalizeData::operator new[], "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator delete[]_", (void (*)(void *)) &IntTools_SurfaceRangeLocalizeData::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_SurfaceRangeLocalizeData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_SurfaceRangeLocalizeData.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_SurfaceRangeLocalizeData::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_SurfaceRangeLocalizeData.def("Assign", (IntTools_SurfaceRangeLocalizeData & (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeLocalizeData &)) &IntTools_SurfaceRangeLocalizeData::Assign, "None", py::arg("Other"));
// cls_IntTools_SurfaceRangeLocalizeData.def("operator=", (IntTools_SurfaceRangeLocalizeData & (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeLocalizeData &)) &IntTools_SurfaceRangeLocalizeData::operator=, "None", py::arg("Other"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetNbSampleU", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetNbSampleU, "None");
cls_IntTools_SurfaceRangeLocalizeData.def("GetNbSampleV", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetNbSampleV, "None");
cls_IntTools_SurfaceRangeLocalizeData.def("GetMinRangeU", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetMinRangeU, "None");
cls_IntTools_SurfaceRangeLocalizeData.def("GetMinRangeV", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetMinRangeV, "None");
cls_IntTools_SurfaceRangeLocalizeData.def("AddOutRange", (void (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeLocalizeData::AddOutRange, "None", py::arg("theRange"));
cls_IntTools_SurfaceRangeLocalizeData.def("AddBox", (void (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &, const Bnd_Box &)) &IntTools_SurfaceRangeLocalizeData::AddBox, "None", py::arg("theRange"), py::arg("theBox"));
cls_IntTools_SurfaceRangeLocalizeData.def("FindBox", (Standard_Boolean (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &, Bnd_Box &) const) &IntTools_SurfaceRangeLocalizeData::FindBox, "None", py::arg("theRange"), py::arg("theBox"));
cls_IntTools_SurfaceRangeLocalizeData.def("IsRangeOut", (Standard_Boolean (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &) const) &IntTools_SurfaceRangeLocalizeData::IsRangeOut, "None", py::arg("theRange"));
cls_IntTools_SurfaceRangeLocalizeData.def("ListRangeOut", (void (IntTools_SurfaceRangeLocalizeData::*)(IntTools_ListOfSurfaceRangeSample &) const) &IntTools_SurfaceRangeLocalizeData::ListRangeOut, "None", py::arg("theList"));
cls_IntTools_SurfaceRangeLocalizeData.def("RemoveRangeOutAll", (void (IntTools_SurfaceRangeLocalizeData::*)()) &IntTools_SurfaceRangeLocalizeData::RemoveRangeOutAll, "None");
cls_IntTools_SurfaceRangeLocalizeData.def("SetGridDeflection", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetGridDeflection, "Set the grid deflection.", py::arg("theDeflection"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetGridDeflection", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetGridDeflection, "Query the grid deflection.");
cls_IntTools_SurfaceRangeLocalizeData.def("SetRangeUGrid", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer)) &IntTools_SurfaceRangeLocalizeData::SetRangeUGrid, "Set the range U of the grid of points.", py::arg("theNbUGrid"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetRangeUGrid", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetRangeUGrid, "Query the range U of the grid of points.");
cls_IntTools_SurfaceRangeLocalizeData.def("SetUParam", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetUParam, "Set the U parameter of the grid points at that index.", py::arg("theIndex"), py::arg("theUParam"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetUParam", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetUParam, "Query the U parameter of the grid points at that index.", py::arg("theIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("SetRangeVGrid", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer)) &IntTools_SurfaceRangeLocalizeData::SetRangeVGrid, "Set the range V of the grid of points.", py::arg("theNbVGrid"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetRangeVGrid", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetRangeVGrid, "Query the range V of the grid of points.");
cls_IntTools_SurfaceRangeLocalizeData.def("SetVParam", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetVParam, "Set the V parameter of the grid points at that index.", py::arg("theIndex"), py::arg("theVParam"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetVParam", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetVParam, "Query the V parameter of the grid points at that index.", py::arg("theIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("SetGridPoint", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Integer, const gp_Pnt &)) &IntTools_SurfaceRangeLocalizeData::SetGridPoint, "Set the grid point.", py::arg("theUIndex"), py::arg("theVIndex"), py::arg("thePoint"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetGridPoint", (const gp_Pnt & (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetGridPoint, "Set the grid point.", py::arg("theUIndex"), py::arg("theVIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("SetFrame", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetFrame, "Sets the frame area. Used to work with grid points.", py::arg("theUMin"), py::arg("theUMax"), py::arg("theVMin"), py::arg("theVMax"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetNBUPointsInFrame", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetNBUPointsInFrame, "Returns the number of grid points on U direction in frame.");
cls_IntTools_SurfaceRangeLocalizeData.def("GetNBVPointsInFrame", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const) &IntTools_SurfaceRangeLocalizeData::GetNBVPointsInFrame, "Returns the number of grid points on V direction in frame.");
cls_IntTools_SurfaceRangeLocalizeData.def("GetPointInFrame", (const gp_Pnt & (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetPointInFrame, "Returns the grid point in frame.", py::arg("theUIndex"), py::arg("theVIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetUParamInFrame", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetUParamInFrame, "Query the U parameter of the grid points at that index in frame.", py::arg("theIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("GetVParamInFrame", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const) &IntTools_SurfaceRangeLocalizeData::GetVParamInFrame, "Query the V parameter of the grid points at that index in frame.", py::arg("theIndex"));
cls_IntTools_SurfaceRangeLocalizeData.def("ClearGrid", (void (IntTools_SurfaceRangeLocalizeData::*)()) &IntTools_SurfaceRangeLocalizeData::ClearGrid, "Clears the grid of points.");

// CLASS: INTTOOLS_TOOLS
py::class_<IntTools_Tools> cls_IntTools_Tools(mod, "IntTools_Tools", "The class contains handy static functions dealing with the geometry and topology.");

// Constructors
cls_IntTools_Tools.def(py::init<>());

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

// CLASS: INTTOOLS_TOPOLTOOL
py::class_<IntTools_TopolTool, opencascade::handle<IntTools_TopolTool>, Adaptor3d_TopolTool> cls_IntTools_TopolTool(mod, "IntTools_TopolTool", "Class redefine methods of TopolTool from Adaptor3d concerning sample points");

// Constructors
cls_IntTools_TopolTool.def(py::init<>());
cls_IntTools_TopolTool.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("theSurface"));

// Methods
cls_IntTools_TopolTool.def("Initialize", (void (IntTools_TopolTool::*)()) &IntTools_TopolTool::Initialize, "Redefined empty initializer");
cls_IntTools_TopolTool.def("Initialize", (void (IntTools_TopolTool::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntTools_TopolTool::Initialize, "Initializes me by surface", py::arg("theSurface"));
cls_IntTools_TopolTool.def("ComputeSamplePoints", (void (IntTools_TopolTool::*)()) &IntTools_TopolTool::ComputeSamplePoints, "None");
cls_IntTools_TopolTool.def("NbSamplesU", (Standard_Integer (IntTools_TopolTool::*)()) &IntTools_TopolTool::NbSamplesU, "Computes the sample-points for the intersections algorithms");
cls_IntTools_TopolTool.def("NbSamplesV", (Standard_Integer (IntTools_TopolTool::*)()) &IntTools_TopolTool::NbSamplesV, "Computes the sample-points for the intersections algorithms");
cls_IntTools_TopolTool.def("NbSamples", (Standard_Integer (IntTools_TopolTool::*)()) &IntTools_TopolTool::NbSamples, "Computes the sample-points for the intersections algorithms");
cls_IntTools_TopolTool.def("SamplePoint", (void (IntTools_TopolTool::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt &)) &IntTools_TopolTool::SamplePoint, "Returns a 2d point from surface myS and a corresponded 3d point for given index. The index should be from 1 to NbSamples()", py::arg("Index"), py::arg("P2d"), py::arg("P3d"));
cls_IntTools_TopolTool.def("SamplePnts", (void (IntTools_TopolTool::*)(const Standard_Real, const Standard_Integer, const Standard_Integer)) &IntTools_TopolTool::SamplePnts, "compute the sample-points for the intersections algorithms by adaptive algorithm for BSpline surfaces. For other surfaces algorithm is the same as in method ComputeSamplePoints(), but only fill arrays of U and V sample parameters; theDefl is a requred deflection theNUmin, theNVmin are minimal nb points for U and V.", py::arg("theDefl"), py::arg("theNUmin"), py::arg("theNVmin"));
cls_IntTools_TopolTool.def_static("get_type_name_", (const char * (*)()) &IntTools_TopolTool::get_type_name, "None");
cls_IntTools_TopolTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntTools_TopolTool::get_type_descriptor, "None");
cls_IntTools_TopolTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntTools_TopolTool::*)() const) &IntTools_TopolTool::DynamicType, "None");

// CLASS: INTTOOLS_WLINETOOL
py::class_<IntTools_WLineTool> cls_IntTools_WLineTool(mod, "IntTools_WLineTool", "IntTools_WLineTool provides set of static methods related to walking lines.");

// Constructors
cls_IntTools_WLineTool.def(py::init<>());

// Methods
// cls_IntTools_WLineTool.def_static("operator new_", (void * (*)(size_t)) &IntTools_WLineTool::operator new, "None", py::arg("theSize"));
// cls_IntTools_WLineTool.def_static("operator delete_", (void (*)(void *)) &IntTools_WLineTool::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_WLineTool.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_WLineTool::operator new[], "None", py::arg("theSize"));
// cls_IntTools_WLineTool.def_static("operator delete[]_", (void (*)(void *)) &IntTools_WLineTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_WLineTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_WLineTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_WLineTool.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_WLineTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_WLineTool.def_static("NotUseSurfacesForApprox_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const opencascade::handle<IntPatch_WLine> &, const Standard_Integer, const Standard_Integer)) &IntTools_WLineTool::NotUseSurfacesForApprox, "None", py::arg("aF1"), py::arg("aF2"), py::arg("WL"), py::arg("ifprm"), py::arg("ilprm"));
cls_IntTools_WLineTool.def_static("DecompositionOfWLine_", [](const opencascade::handle<IntPatch_WLine> & theWLine, const opencascade::handle<GeomAdaptor_HSurface> & theSurface1, const opencascade::handle<GeomAdaptor_HSurface> & theSurface2, const TopoDS_Face & theFace1, const TopoDS_Face & theFace2, const GeomInt_LineConstructor & theLConstructor, const Standard_Boolean theAvoidLConstructor, const Standard_Real theTol, IntPatch_SequenceOfLine & theNewLines, Standard_Real & theReachedTol3d, const opencascade::handle<IntTools_Context> & a0){ Standard_Boolean rv = IntTools_WLineTool::DecompositionOfWLine(theWLine, theSurface1, theSurface2, theFace1, theFace2, theLConstructor, theAvoidLConstructor, theTol, theNewLines, theReachedTol3d, a0); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theReachedTol3d); }, "None", py::arg("theWLine"), py::arg("theSurface1"), py::arg("theSurface2"), py::arg("theFace1"), py::arg("theFace2"), py::arg("theLConstructor"), py::arg("theAvoidLConstructor"), py::arg("theTol"), py::arg("theNewLines"), py::arg("theReachedTol3d"), py::arg(""));


}
