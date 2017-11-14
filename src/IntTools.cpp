#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <BOPCol_BaseAllocator.hxx>
#include <IntTools_FClass2d.hxx>
#include <TopoDS_Face.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <GeomAPI_ProjectPointOnCurve.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <IntTools_SurfaceRangeLocalizeData.hxx>
#include <BRepClass3d_SolidClassifier.hxx>
#include <TopoDS_Solid.hxx>
#include <Geom2dHatch_Hatcher.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <IntTools_Curve.hxx>
#include <Bnd_Box.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Type.hxx>
#include <IntTools_Context.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAbs_CurveType.hxx>
#include <IntTools_ShrunkRange.hxx>
#include <IntTools_SurfaceRangeSample.hxx>
#include <IntTools_ListOfSurfaceRangeSample.hxx>
#include <IntTools_Range.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <IntTools_SequenceOfRanges.hxx>
#include <IntTools_CommonPrt.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <IntTools_Root.hxx>
#include <IntTools_SequenceOfRoots.hxx>
#include <IntTools_CArray1OfReal.hxx>
#include <IntTools_SequenceOfCommonPrts.hxx>
#include <IntTools_EdgeEdge.hxx>
#include <IntTools_EdgeFace.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <IntTools_MarkedRangeSet.hxx>
#include <IntTools_BaseRangeSample.hxx>
#include <IntTools_CurveRangeSample.hxx>
#include <IntTools_ListOfCurveRangeSample.hxx>
#include <IntTools_CurveRangeLocalizeData.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <IntTools_BeanFaceIntersector.hxx>
#include <IntTools_PntOnFace.hxx>
#include <IntTools_PntOn2Faces.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntTools_TopolTool.hxx>
#include <IntTools_SequenceOfCurves.hxx>
#include <IntTools_SequenceOfPntOn2Faces.hxx>
#include <IntSurf_ListOfPntOn2S.hxx>
#include <IntTools_FaceFace.hxx>
#include <TopoDS_Wire.hxx>
#include <gp_Dir.hxx>
#include <gp_Lin.hxx>
#include <gp_Pln.hxx>
#include <Geom_Surface.hxx>
#include <IntTools_Tools.hxx>
#include <IntTools.hxx>
#include <IntTools_CArray1OfInteger.hxx>
#include <IntTools_CurveRangeSampleMapHasher.hxx>
#include <IntTools_SurfaceRangeSampleMapHasher.hxx>
#include <NCollection_Array1.hxx>
#include <IntTools_Array1OfRange.hxx>
#include <IntTools_Array1OfRoots.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_Map.hxx>
#include <IntTools_MapOfCurveSample.hxx>
#include <NCollection_DataMap.hxx>
#include <IntTools_DataMapOfCurveSampleBox.hxx>
#include <IntTools_DataMapOfSurfaceSampleBox.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <IntTools_IndexedDataMapOfTransientAddress.hxx>
#include <IntTools_ListOfBox.hxx>
#include <IntTools_MapOfSurfaceSample.hxx>
#include <IntPatch_WLine.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <GeomInt_LineConstructor.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <IntTools_WLineTool.hxx>

PYBIND11_MODULE(IntTools, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.BOPCol");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.GeomAPI");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.BRepClass3d");
	py::module::import("OCCT.Geom2dHatch");
	py::module::import("OCCT.BRepAdaptor");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.IntSurf");
	py::module::import("OCCT.IntPatch");
	py::module::import("OCCT.GeomAdaptor");
	py::module::import("OCCT.GeomInt");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_Context.hxx
	py::class_<IntTools_Context, opencascade::handle<IntTools_Context>, Standard_Transient> cls_IntTools_Context(mod, "IntTools_Context", "The intersection Context contains geometrical and topological toolkit (classifiers, projectors, etc). The intersection Context is for caching the tools to increase the performance.");
	cls_IntTools_Context.def(py::init<>());
	cls_IntTools_Context.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_IntTools_Context.def("FClass2d", (IntTools_FClass2d & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::FClass2d, "Returns a reference to point classifier for given face", py::arg("aF"));
	cls_IntTools_Context.def("ProjPS", (GeomAPI_ProjectPointOnSurf & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::ProjPS, "Returns a reference to point projector for given face", py::arg("aF"));
	cls_IntTools_Context.def("ProjPC", (GeomAPI_ProjectPointOnCurve & (IntTools_Context::*)(const TopoDS_Edge &)) &IntTools_Context::ProjPC, "Returns a reference to point projector for given edge", py::arg("aE"));
	cls_IntTools_Context.def("ProjPT", (GeomAPI_ProjectPointOnCurve & (IntTools_Context::*)(const opencascade::handle<Geom_Curve> &)) &IntTools_Context::ProjPT, "Returns a reference to point projector for given curve", py::arg("aC"));
	cls_IntTools_Context.def("SurfaceData", (IntTools_SurfaceRangeLocalizeData & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::SurfaceData, "Returns a reference to surface localization data for given face", py::arg("aF"));
	cls_IntTools_Context.def("SolidClassifier", (BRepClass3d_SolidClassifier & (IntTools_Context::*)(const TopoDS_Solid &)) &IntTools_Context::SolidClassifier, "Returns a reference to solid classifier for given solid", py::arg("aSolid"));
	cls_IntTools_Context.def("Hatcher", (Geom2dHatch_Hatcher & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::Hatcher, "Returns a reference to 2D hatcher for given face", py::arg("aF"));
	cls_IntTools_Context.def("SurfaceAdaptor", (BRepAdaptor_Surface & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::SurfaceAdaptor, "Returns a reference to surface adaptor for given face", py::arg("theFace"));
	cls_IntTools_Context.def("UVBounds", (void (IntTools_Context::*)(const TopoDS_Face &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &IntTools_Context::UVBounds, "Computes the boundaries of the face using surface adaptor", py::arg("theFace"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
	cls_IntTools_Context.def("ComputePE", (Standard_Integer (IntTools_Context::*)(const gp_Pnt &, const Standard_Real, const TopoDS_Edge &, Standard_Real &, Standard_Real &)) &IntTools_Context::ComputePE, "Computes parameter of the Point theP on the edge aE. Returns zero if the distance between point and edge is less than sum of tolerance value of edge and theTopP, otherwise and for following conditions returns negative value 1. the edge is degenerated (-1) 2. the edge does not contain 3d curve and pcurves (-2) 3. projection algorithm failed (-3)", py::arg("theP"), py::arg("theTolP"), py::arg("theE"), py::arg("theT"), py::arg("theDist"));
	cls_IntTools_Context.def("ComputeVE", [](IntTools_Context &self, const TopoDS_Vertex & a0, const TopoDS_Edge & a1, Standard_Real & a2, Standard_Real & a3) -> Standard_Integer { return self.ComputeVE(a0, a1, a2, a3); }, py::arg("theV"), py::arg("theE"), py::arg("theT"), py::arg("theTol"));
	cls_IntTools_Context.def("ComputeVE", (Standard_Integer (IntTools_Context::*)(const TopoDS_Vertex &, const TopoDS_Edge &, Standard_Real &, Standard_Real &, const Standard_Real)) &IntTools_Context::ComputeVE, "Computes parameter of the vertex aV on the edge aE and correct tolerance value for the vertex on the edge. Returns zero if the distance between vertex and edge is less than sum of tolerances and the fuzzy value, otherwise and for following conditions returns negative value: 1. the edge is degenerated (-1) 2. the edge does not contain 3d curve and pcurves (-2) 3. projection algorithm failed (-3)", py::arg("theV"), py::arg("theE"), py::arg("theT"), py::arg("theTol"), py::arg("theFuzz"));
	cls_IntTools_Context.def("ComputeVF", [](IntTools_Context &self, const TopoDS_Vertex & a0, const TopoDS_Face & a1, Standard_Real & a2, Standard_Real & a3, Standard_Real & a4) -> Standard_Integer { return self.ComputeVF(a0, a1, a2, a3, a4); }, py::arg("theVertex"), py::arg("theFace"), py::arg("theU"), py::arg("theV"), py::arg("theTol"));
	cls_IntTools_Context.def("ComputeVF", (Standard_Integer (IntTools_Context::*)(const TopoDS_Vertex &, const TopoDS_Face &, Standard_Real &, Standard_Real &, Standard_Real &, const Standard_Real)) &IntTools_Context::ComputeVF, "Computes UV parameters of the vertex aV on face aF and correct tolerance value for the vertex on the face. Returns zero if the distance between vertex and face is less than or equal the sum of tolerances and the fuzzy value and the projection point lays inside boundaries of the face. For following conditions returns negative value 1. projection algorithm failed (-1) 2. distance is more than sum of tolerances (-2) 3. projection point out or on the boundaries of face (-3)", py::arg("theVertex"), py::arg("theFace"), py::arg("theU"), py::arg("theV"), py::arg("theTol"), py::arg("theFuzz"));
	cls_IntTools_Context.def("StatePointFace", (TopAbs_State (IntTools_Context::*)(const TopoDS_Face &, const gp_Pnt2d &)) &IntTools_Context::StatePointFace, "Returns the state of the point aP2D relative to face aF", py::arg("aF"), py::arg("aP2D"));
	cls_IntTools_Context.def("IsPointInFace", (Standard_Boolean (IntTools_Context::*)(const TopoDS_Face &, const gp_Pnt2d &)) &IntTools_Context::IsPointInFace, "Returns true if the point aP2D is inside the boundaries of the face aF, otherwise returns false", py::arg("aF"), py::arg("aP2D"));
	cls_IntTools_Context.def("IsPointInFace", (Standard_Boolean (IntTools_Context::*)(const gp_Pnt &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsPointInFace, "Returns true if the point aP2D is inside the boundaries of the face aF, otherwise returns false", py::arg("aP3D"), py::arg("aF"), py::arg("aTol"));
	cls_IntTools_Context.def("IsPointInOnFace", (Standard_Boolean (IntTools_Context::*)(const TopoDS_Face &, const gp_Pnt2d &)) &IntTools_Context::IsPointInOnFace, "Returns true if the point aP2D is inside or on the boundaries of aF", py::arg("aF"), py::arg("aP2D"));
	cls_IntTools_Context.def("IsValidPointForFace", (Standard_Boolean (IntTools_Context::*)(const gp_Pnt &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidPointForFace, "Returns true if the distance between point aP3D and face aF is less or equal to tolerance aTol and projection point is inside or on the boundaries of the face aF", py::arg("aP3D"), py::arg("aF"), py::arg("aTol"));
	cls_IntTools_Context.def("IsValidPointForFaces", (Standard_Boolean (IntTools_Context::*)(const gp_Pnt &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidPointForFaces, "Returns true if IsValidPointForFace returns true for both face aF1 and aF2", py::arg("aP3D"), py::arg("aF1"), py::arg("aF2"), py::arg("aTol"));
	cls_IntTools_Context.def("IsValidBlockForFace", (Standard_Boolean (IntTools_Context::*)(const Standard_Real, const Standard_Real, const IntTools_Curve &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidBlockForFace, "Returns true if IsValidPointForFace returns true for some 3d point that lay on the curve aIC bounded by parameters aT1 and aT2", py::arg("aT1"), py::arg("aT2"), py::arg("aIC"), py::arg("aF"), py::arg("aTol"));
	cls_IntTools_Context.def("IsValidBlockForFaces", (Standard_Boolean (IntTools_Context::*)(const Standard_Real, const Standard_Real, const IntTools_Curve &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidBlockForFaces, "Returns true if IsValidBlockForFace returns true for both faces aF1 and aF2", py::arg("aT1"), py::arg("aT2"), py::arg("aIC"), py::arg("aF1"), py::arg("aF2"), py::arg("aTol"));
	cls_IntTools_Context.def("IsVertexOnLine", (Standard_Boolean (IntTools_Context::*)(const TopoDS_Vertex &, const IntTools_Curve &, const Standard_Real, Standard_Real &)) &IntTools_Context::IsVertexOnLine, "Computes parameter of the vertex aV on the curve aIC. Returns true if the distance between vertex and curve is less than sum of tolerance of aV and aTolC, otherwise or if projection algorithm failed returns false (in this case aT isn't significant)", py::arg("aV"), py::arg("aIC"), py::arg("aTolC"), py::arg("aT"));
	cls_IntTools_Context.def("IsVertexOnLine", (Standard_Boolean (IntTools_Context::*)(const TopoDS_Vertex &, const Standard_Real, const IntTools_Curve &, const Standard_Real, Standard_Real &)) &IntTools_Context::IsVertexOnLine, "Computes parameter of the vertex aV on the curve aIC. Returns true if the distance between vertex and curve is less than sum of tolerance of aV and aTolC, otherwise or if projection algorithm failed returns false (in this case aT isn't significant)", py::arg("aV"), py::arg("aTolV"), py::arg("aIC"), py::arg("aTolC"), py::arg("aT"));
	cls_IntTools_Context.def("ProjectPointOnEdge", (Standard_Boolean (IntTools_Context::*)(const gp_Pnt &, const TopoDS_Edge &, Standard_Real &)) &IntTools_Context::ProjectPointOnEdge, "Computes parameter of the point aP on the edge aE. Returns false if projection algorithm failed other wiese returns true.", py::arg("aP"), py::arg("aE"), py::arg("aT"));
	cls_IntTools_Context.def("BndBox", (Bnd_Box & (IntTools_Context::*)(const TopoDS_Shape &)) &IntTools_Context::BndBox, "None", py::arg("theS"));
	cls_IntTools_Context.def("IsInfiniteFace", (Standard_Boolean (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::IsInfiniteFace, "Returns true if the solid <theFace> has infinite bounds", py::arg("theFace"));
	cls_IntTools_Context.def("SetPOnSProjectionTolerance", (void (IntTools_Context::*)(const Standard_Real)) &IntTools_Context::SetPOnSProjectionTolerance, "Sets tolerance to be used for projection of point on surface. Clears map of already cached projectors in order to maintain correct value for all projectors", py::arg("theValue"));
	cls_IntTools_Context.def_static("get_type_name_", (const char * (*)()) &IntTools_Context::get_type_name, "None");
	cls_IntTools_Context.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntTools_Context::get_type_descriptor, "None");
	cls_IntTools_Context.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntTools_Context::*)() const ) &IntTools_Context::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_Curve.hxx
	py::class_<IntTools_Curve, std::unique_ptr<IntTools_Curve, Deleter<IntTools_Curve>>> cls_IntTools_Curve(mod, "IntTools_Curve", "The class is a container of one 3D curve, two 2D curves and two Tolerance values. It is used in the Face/Face intersection algorithm to store the results of intersection. In this context: **the 3D curve** is the intersection curve; **the 2D curves** are the PCurves of the 3D curve on the intersecting faces; **the tolerance** is the valid tolerance for 3D curve computed as maximal deviation between 3D curve and 2D curves (or surfaces in case there are no 2D curves); **the tangential tolerance** is the maximal distance from 3D curve to the end of the tangential zone between faces in terms of their tolerance values.");
	cls_IntTools_Curve.def(py::init<>());
	cls_IntTools_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &>(), py::arg("the3dCurve3d"), py::arg("the2dCurve1"), py::arg("the2dCurve2"));
	cls_IntTools_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real>(), py::arg("the3dCurve3d"), py::arg("the2dCurve1"), py::arg("the2dCurve2"), py::arg("theTolerance"));
	cls_IntTools_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("the3dCurve3d"), py::arg("the2dCurve1"), py::arg("the2dCurve2"), py::arg("theTolerance"), py::arg("theTangentialTolerance"));
	cls_IntTools_Curve.def("SetCurves", (void (IntTools_Curve::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &)) &IntTools_Curve::SetCurves, "Sets the curves", py::arg("the3dCurve"), py::arg("the2dCurve1"), py::arg("the2dCurve2"));
	cls_IntTools_Curve.def("SetCurve", (void (IntTools_Curve::*)(const opencascade::handle<Geom_Curve> &)) &IntTools_Curve::SetCurve, "Sets the 3d curve", py::arg("the3dCurve"));
	cls_IntTools_Curve.def("SetFirstCurve2d", (void (IntTools_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &IntTools_Curve::SetFirstCurve2d, "Sets the first 2d curve", py::arg("the2dCurve1"));
	cls_IntTools_Curve.def("SetSecondCurve2d", (void (IntTools_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &IntTools_Curve::SetSecondCurve2d, "Sets the second 2d curve", py::arg("the2dCurve2"));
	cls_IntTools_Curve.def("SetTolerance", (void (IntTools_Curve::*)(const Standard_Real)) &IntTools_Curve::SetTolerance, "Sets the tolerance for the curve", py::arg("theTolerance"));
	cls_IntTools_Curve.def("SetTangentialTolerance", (void (IntTools_Curve::*)(const Standard_Real)) &IntTools_Curve::SetTangentialTolerance, "Sets the tangential tolerance", py::arg("theTangentialTolerance"));
	cls_IntTools_Curve.def("Curve", (const opencascade::handle<Geom_Curve> & (IntTools_Curve::*)() const ) &IntTools_Curve::Curve, "Returns 3d curve");
	cls_IntTools_Curve.def("FirstCurve2d", (const opencascade::handle<Geom2d_Curve> & (IntTools_Curve::*)() const ) &IntTools_Curve::FirstCurve2d, "Returns first 2d curve");
	cls_IntTools_Curve.def("SecondCurve2d", (const opencascade::handle<Geom2d_Curve> & (IntTools_Curve::*)() const ) &IntTools_Curve::SecondCurve2d, "Returns second 2d curve");
	cls_IntTools_Curve.def("Tolerance", (Standard_Real (IntTools_Curve::*)() const ) &IntTools_Curve::Tolerance, "Returns the tolerance");
	cls_IntTools_Curve.def("TangentialTolerance", (Standard_Real (IntTools_Curve::*)() const ) &IntTools_Curve::TangentialTolerance, "Returns the tangential tolerance");
	cls_IntTools_Curve.def("HasBounds", (Standard_Boolean (IntTools_Curve::*)() const ) &IntTools_Curve::HasBounds, "Returns TRUE if 3d curve is BoundedCurve");
	cls_IntTools_Curve.def("Bounds", (Standard_Boolean (IntTools_Curve::*)(Standard_Real &, Standard_Real &, gp_Pnt &, gp_Pnt &) const ) &IntTools_Curve::Bounds, "If the 3d curve is bounded curve the method will return TRUE and modify the output parameters with boundary parameters of the curve and corresponded 3d points. If the curve does not have bounds, the method will return false and the output parameters will stay untouched.", py::arg("theFirst"), py::arg("theLast"), py::arg("theFirstPnt"), py::arg("theLastPnt"));
	cls_IntTools_Curve.def("D0", (Standard_Boolean (IntTools_Curve::*)(const Standard_Real &, gp_Pnt &) const ) &IntTools_Curve::D0, "Computes 3d point corresponded to the given parameter if this parameter is inside the boundaries of the curve. Returns TRUE in this case. Otherwise, the point will not be computed and the method will return FALSE.", py::arg("thePar"), py::arg("thePnt"));
	cls_IntTools_Curve.def("Type", (GeomAbs_CurveType (IntTools_Curve::*)() const ) &IntTools_Curve::Type, "Returns the type of the 3d curve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_ShrunkRange.hxx
	py::class_<IntTools_ShrunkRange, std::unique_ptr<IntTools_ShrunkRange, Deleter<IntTools_ShrunkRange>>> cls_IntTools_ShrunkRange(mod, "IntTools_ShrunkRange", "The class provides the computation of a working (shrunk) range [t1, t2] for the 3D-curve of the edge.");
	cls_IntTools_ShrunkRange.def(py::init<>());
	cls_IntTools_ShrunkRange.def("SetData", (void (IntTools_ShrunkRange::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real, const TopoDS_Vertex &, const TopoDS_Vertex &)) &IntTools_ShrunkRange::SetData, "None", py::arg("aE"), py::arg("aT1"), py::arg("aT2"), py::arg("aV1"), py::arg("aV2"));
	cls_IntTools_ShrunkRange.def("SetContext", (void (IntTools_ShrunkRange::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_ShrunkRange::SetContext, "None", py::arg("aCtx"));
	cls_IntTools_ShrunkRange.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_ShrunkRange::*)() const ) &IntTools_ShrunkRange::Context, "None");
	cls_IntTools_ShrunkRange.def("SetShrunkRange", (void (IntTools_ShrunkRange::*)(const Standard_Real, const Standard_Real)) &IntTools_ShrunkRange::SetShrunkRange, "None", py::arg("aT1"), py::arg("aT2"));
	cls_IntTools_ShrunkRange.def("ShrunkRange", (void (IntTools_ShrunkRange::*)(Standard_Real &, Standard_Real &) const ) &IntTools_ShrunkRange::ShrunkRange, "None", py::arg("aT1"), py::arg("aT2"));
	cls_IntTools_ShrunkRange.def("BndBox", (const Bnd_Box & (IntTools_ShrunkRange::*)() const ) &IntTools_ShrunkRange::BndBox, "None");
	cls_IntTools_ShrunkRange.def("Edge", (const TopoDS_Edge & (IntTools_ShrunkRange::*)() const ) &IntTools_ShrunkRange::Edge, "None");
	cls_IntTools_ShrunkRange.def("Perform", (void (IntTools_ShrunkRange::*)()) &IntTools_ShrunkRange::Perform, "None");
	cls_IntTools_ShrunkRange.def("IsDone", (Standard_Boolean (IntTools_ShrunkRange::*)() const ) &IntTools_ShrunkRange::IsDone, "Returns TRUE in case the shrunk range is computed");
	cls_IntTools_ShrunkRange.def("IsSplittable", (Standard_Boolean (IntTools_ShrunkRange::*)() const ) &IntTools_ShrunkRange::IsSplittable, "Returns FALSE in case the shrunk range is too short and the edge cannot be split, otherwise returns TRUE");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_FClass2d.hxx
	py::class_<IntTools_FClass2d, std::unique_ptr<IntTools_FClass2d, Deleter<IntTools_FClass2d>>> cls_IntTools_FClass2d(mod, "IntTools_FClass2d", "Class provides an algorithm to classify a 2d Point in 2d space of face using boundaries of the face.");
	cls_IntTools_FClass2d.def(py::init<>());
	cls_IntTools_FClass2d.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("F"), py::arg("Tol"));
	cls_IntTools_FClass2d.def("Init", (void (IntTools_FClass2d::*)(const TopoDS_Face &, const Standard_Real)) &IntTools_FClass2d::Init, "Initializes algorithm by the face F and tolerance Tol", py::arg("F"), py::arg("Tol"));
	cls_IntTools_FClass2d.def("PerformInfinitePoint", (TopAbs_State (IntTools_FClass2d::*)() const ) &IntTools_FClass2d::PerformInfinitePoint, "Returns state of infinite 2d point relatively to (0, 0)");
	cls_IntTools_FClass2d.def("Perform", [](IntTools_FClass2d &self, const gp_Pnt2d & a0) -> TopAbs_State { return self.Perform(a0); }, py::arg("Puv"));
	cls_IntTools_FClass2d.def("Perform", (TopAbs_State (IntTools_FClass2d::*)(const gp_Pnt2d &, const Standard_Boolean) const ) &IntTools_FClass2d::Perform, "Returns state of the 2d point Puv. If RecadreOnPeriodic is true (defalut value), for the periodic surface 2d point, adjusted to period, is classified.", py::arg("Puv"), py::arg("RecadreOnPeriodic"));
	cls_IntTools_FClass2d.def("Destroy", (void (IntTools_FClass2d::*)()) &IntTools_FClass2d::Destroy, "Destructor");
	cls_IntTools_FClass2d.def("TestOnRestriction", [](IntTools_FClass2d &self, const gp_Pnt2d & a0, const Standard_Real a1) -> TopAbs_State { return self.TestOnRestriction(a0, a1); }, py::arg("Puv"), py::arg("Tol"));
	cls_IntTools_FClass2d.def("TestOnRestriction", (TopAbs_State (IntTools_FClass2d::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean) const ) &IntTools_FClass2d::TestOnRestriction, "Test a point with +- an offset (Tol) and returns On if some points are OUT an some are IN (Caution: Internal use . see the code for more details)", py::arg("Puv"), py::arg("Tol"), py::arg("RecadreOnPeriodic"));
	cls_IntTools_FClass2d.def("IsHole", (Standard_Boolean (IntTools_FClass2d::*)() const ) &IntTools_FClass2d::IsHole, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_SurfaceRangeLocalizeData.hxx
	py::class_<IntTools_SurfaceRangeLocalizeData, std::unique_ptr<IntTools_SurfaceRangeLocalizeData, Deleter<IntTools_SurfaceRangeLocalizeData>>> cls_IntTools_SurfaceRangeLocalizeData(mod, "IntTools_SurfaceRangeLocalizeData", "None");
	cls_IntTools_SurfaceRangeLocalizeData.def(py::init<>());
	cls_IntTools_SurfaceRangeLocalizeData.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("theNbSampleU"), py::arg("theNbSampleV"), py::arg("theMinRangeU"), py::arg("theMinRangeV"));
	cls_IntTools_SurfaceRangeLocalizeData.def(py::init([] (const IntTools_SurfaceRangeLocalizeData &other) {return new IntTools_SurfaceRangeLocalizeData(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_SurfaceRangeLocalizeData.def("Assign", (IntTools_SurfaceRangeLocalizeData & (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeLocalizeData &)) &IntTools_SurfaceRangeLocalizeData::Assign, "None", py::arg("Other"));
	cls_IntTools_SurfaceRangeLocalizeData.def("assign", (IntTools_SurfaceRangeLocalizeData & (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeLocalizeData &)) &IntTools_SurfaceRangeLocalizeData::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_IntTools_SurfaceRangeLocalizeData.def("GetNbSampleU", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const ) &IntTools_SurfaceRangeLocalizeData::GetNbSampleU, "None");
	cls_IntTools_SurfaceRangeLocalizeData.def("GetNbSampleV", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const ) &IntTools_SurfaceRangeLocalizeData::GetNbSampleV, "None");
	cls_IntTools_SurfaceRangeLocalizeData.def("GetMinRangeU", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)() const ) &IntTools_SurfaceRangeLocalizeData::GetMinRangeU, "None");
	cls_IntTools_SurfaceRangeLocalizeData.def("GetMinRangeV", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)() const ) &IntTools_SurfaceRangeLocalizeData::GetMinRangeV, "None");
	cls_IntTools_SurfaceRangeLocalizeData.def("AddOutRange", (void (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeLocalizeData::AddOutRange, "None", py::arg("theRange"));
	cls_IntTools_SurfaceRangeLocalizeData.def("AddBox", (void (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &, const Bnd_Box &)) &IntTools_SurfaceRangeLocalizeData::AddBox, "None", py::arg("theRange"), py::arg("theBox"));
	cls_IntTools_SurfaceRangeLocalizeData.def("FindBox", (Standard_Boolean (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &, Bnd_Box &) const ) &IntTools_SurfaceRangeLocalizeData::FindBox, "None", py::arg("theRange"), py::arg("theBox"));
	cls_IntTools_SurfaceRangeLocalizeData.def("IsRangeOut", (Standard_Boolean (IntTools_SurfaceRangeLocalizeData::*)(const IntTools_SurfaceRangeSample &) const ) &IntTools_SurfaceRangeLocalizeData::IsRangeOut, "None", py::arg("theRange"));
	cls_IntTools_SurfaceRangeLocalizeData.def("ListRangeOut", (void (IntTools_SurfaceRangeLocalizeData::*)(IntTools_ListOfSurfaceRangeSample &) const ) &IntTools_SurfaceRangeLocalizeData::ListRangeOut, "None", py::arg("theList"));
	cls_IntTools_SurfaceRangeLocalizeData.def("RemoveRangeOutAll", (void (IntTools_SurfaceRangeLocalizeData::*)()) &IntTools_SurfaceRangeLocalizeData::RemoveRangeOutAll, "None");
	cls_IntTools_SurfaceRangeLocalizeData.def("SetGridDeflection", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetGridDeflection, "Set the grid deflection.", py::arg("theDeflection"));
	cls_IntTools_SurfaceRangeLocalizeData.def("GetGridDeflection", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)() const ) &IntTools_SurfaceRangeLocalizeData::GetGridDeflection, "Query the grid deflection.");
	cls_IntTools_SurfaceRangeLocalizeData.def("SetRangeUGrid", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer)) &IntTools_SurfaceRangeLocalizeData::SetRangeUGrid, "Set the range U of the grid of points.", py::arg("theNbUGrid"));
	cls_IntTools_SurfaceRangeLocalizeData.def("GetRangeUGrid", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const ) &IntTools_SurfaceRangeLocalizeData::GetRangeUGrid, "Query the range U of the grid of points.");
	cls_IntTools_SurfaceRangeLocalizeData.def("SetUParam", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetUParam, "Set the U parameter of the grid points at that index.", py::arg("theIndex"), py::arg("theUParam"));
	cls_IntTools_SurfaceRangeLocalizeData.def("GetUParam", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const ) &IntTools_SurfaceRangeLocalizeData::GetUParam, "Query the U parameter of the grid points at that index.", py::arg("theIndex"));
	cls_IntTools_SurfaceRangeLocalizeData.def("SetRangeVGrid", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer)) &IntTools_SurfaceRangeLocalizeData::SetRangeVGrid, "Set the range V of the grid of points.", py::arg("theNbVGrid"));
	cls_IntTools_SurfaceRangeLocalizeData.def("GetRangeVGrid", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const ) &IntTools_SurfaceRangeLocalizeData::GetRangeVGrid, "Query the range V of the grid of points.");
	cls_IntTools_SurfaceRangeLocalizeData.def("SetVParam", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetVParam, "Set the V parameter of the grid points at that index.", py::arg("theIndex"), py::arg("theVParam"));
	cls_IntTools_SurfaceRangeLocalizeData.def("GetVParam", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const ) &IntTools_SurfaceRangeLocalizeData::GetVParam, "Query the V parameter of the grid points at that index.", py::arg("theIndex"));
	cls_IntTools_SurfaceRangeLocalizeData.def("SetGridPoint", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Integer, const gp_Pnt &)) &IntTools_SurfaceRangeLocalizeData::SetGridPoint, "Set the grid point.", py::arg("theUIndex"), py::arg("theVIndex"), py::arg("thePoint"));
	cls_IntTools_SurfaceRangeLocalizeData.def("GetGridPoint", (const gp_Pnt & (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Integer) const ) &IntTools_SurfaceRangeLocalizeData::GetGridPoint, "Set the grid point.", py::arg("theUIndex"), py::arg("theVIndex"));
	cls_IntTools_SurfaceRangeLocalizeData.def("SetFrame", (void (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_SurfaceRangeLocalizeData::SetFrame, "Sets the frame area. Used to work with grid points.", py::arg("theUMin"), py::arg("theUMax"), py::arg("theVMin"), py::arg("theVMax"));
	cls_IntTools_SurfaceRangeLocalizeData.def("GetNBUPointsInFrame", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const ) &IntTools_SurfaceRangeLocalizeData::GetNBUPointsInFrame, "Returns the number of grid points on U direction in frame.");
	cls_IntTools_SurfaceRangeLocalizeData.def("GetNBVPointsInFrame", (Standard_Integer (IntTools_SurfaceRangeLocalizeData::*)() const ) &IntTools_SurfaceRangeLocalizeData::GetNBVPointsInFrame, "Returns the number of grid points on V direction in frame.");
	cls_IntTools_SurfaceRangeLocalizeData.def("GetPointInFrame", (const gp_Pnt & (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer, const Standard_Integer) const ) &IntTools_SurfaceRangeLocalizeData::GetPointInFrame, "Returns the grid point in frame.", py::arg("theUIndex"), py::arg("theVIndex"));
	cls_IntTools_SurfaceRangeLocalizeData.def("GetUParamInFrame", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const ) &IntTools_SurfaceRangeLocalizeData::GetUParamInFrame, "Query the U parameter of the grid points at that index in frame.", py::arg("theIndex"));
	cls_IntTools_SurfaceRangeLocalizeData.def("GetVParamInFrame", (Standard_Real (IntTools_SurfaceRangeLocalizeData::*)(const Standard_Integer) const ) &IntTools_SurfaceRangeLocalizeData::GetVParamInFrame, "Query the V parameter of the grid points at that index in frame.", py::arg("theIndex"));
	cls_IntTools_SurfaceRangeLocalizeData.def("ClearGrid", (void (IntTools_SurfaceRangeLocalizeData::*)()) &IntTools_SurfaceRangeLocalizeData::ClearGrid, "Clears the grid of points.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_Range.hxx
	py::class_<IntTools_Range, std::unique_ptr<IntTools_Range, Deleter<IntTools_Range>>> cls_IntTools_Range(mod, "IntTools_Range", "The class describes the 1-d range [myFirst, myLast].");
	cls_IntTools_Range.def(py::init<>());
	cls_IntTools_Range.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("aFirst"), py::arg("aLast"));
	cls_IntTools_Range.def("SetFirst", (void (IntTools_Range::*)(const Standard_Real)) &IntTools_Range::SetFirst, "Modifier", py::arg("aFirst"));
	cls_IntTools_Range.def("SetLast", (void (IntTools_Range::*)(const Standard_Real)) &IntTools_Range::SetLast, "Modifier", py::arg("aLast"));
	cls_IntTools_Range.def("First", (Standard_Real (IntTools_Range::*)() const ) &IntTools_Range::First, "Selector");
	cls_IntTools_Range.def("Last", (Standard_Real (IntTools_Range::*)() const ) &IntTools_Range::Last, "Selector");
	cls_IntTools_Range.def("Range", (void (IntTools_Range::*)(Standard_Real &, Standard_Real &) const ) &IntTools_Range::Range, "Selector", py::arg("aFirst"), py::arg("aLast"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_CommonPrt.hxx
	py::class_<IntTools_CommonPrt, std::unique_ptr<IntTools_CommonPrt, Deleter<IntTools_CommonPrt>>> cls_IntTools_CommonPrt(mod, "IntTools_CommonPrt", "The class is to describe a common part between two edges in 3-d space.");
	cls_IntTools_CommonPrt.def(py::init<>());
	cls_IntTools_CommonPrt.def(py::init([] (const IntTools_CommonPrt &other) {return new IntTools_CommonPrt(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_CommonPrt.def("Assign", (IntTools_CommonPrt & (IntTools_CommonPrt::*)(const IntTools_CommonPrt &)) &IntTools_CommonPrt::Assign, "None", py::arg("Other"));
	cls_IntTools_CommonPrt.def("assign", (IntTools_CommonPrt & (IntTools_CommonPrt::*)(const IntTools_CommonPrt &)) &IntTools_CommonPrt::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_IntTools_CommonPrt.def("SetEdge1", (void (IntTools_CommonPrt::*)(const TopoDS_Edge &)) &IntTools_CommonPrt::SetEdge1, "Sets the first edge.", py::arg("anE"));
	cls_IntTools_CommonPrt.def("SetEdge2", (void (IntTools_CommonPrt::*)(const TopoDS_Edge &)) &IntTools_CommonPrt::SetEdge2, "Sets the second edge.", py::arg("anE"));
	cls_IntTools_CommonPrt.def("SetType", (void (IntTools_CommonPrt::*)(const TopAbs_ShapeEnum)) &IntTools_CommonPrt::SetType, "Sets the type of the common part Vertex or Edge", py::arg("aType"));
	cls_IntTools_CommonPrt.def("SetRange1", (void (IntTools_CommonPrt::*)(const IntTools_Range &)) &IntTools_CommonPrt::SetRange1, "Sets the range of first edge.", py::arg("aR"));
	cls_IntTools_CommonPrt.def("SetRange1", (void (IntTools_CommonPrt::*)(const Standard_Real, const Standard_Real)) &IntTools_CommonPrt::SetRange1, "Sets the range of first edge.", py::arg("tf"), py::arg("tl"));
	cls_IntTools_CommonPrt.def("AppendRange2", (void (IntTools_CommonPrt::*)(const IntTools_Range &)) &IntTools_CommonPrt::AppendRange2, "Appends the range of second edge.", py::arg("aR"));
	cls_IntTools_CommonPrt.def("AppendRange2", (void (IntTools_CommonPrt::*)(const Standard_Real, const Standard_Real)) &IntTools_CommonPrt::AppendRange2, "Appends the range of second edge.", py::arg("tf"), py::arg("tl"));
	cls_IntTools_CommonPrt.def("SetVertexParameter1", (void (IntTools_CommonPrt::*)(const Standard_Real)) &IntTools_CommonPrt::SetVertexParameter1, "Sets a parameter of first vertex", py::arg("tV"));
	cls_IntTools_CommonPrt.def("SetVertexParameter2", (void (IntTools_CommonPrt::*)(const Standard_Real)) &IntTools_CommonPrt::SetVertexParameter2, "Sets a parameter of second vertex", py::arg("tV"));
	cls_IntTools_CommonPrt.def("Edge1", (const TopoDS_Edge & (IntTools_CommonPrt::*)() const ) &IntTools_CommonPrt::Edge1, "Returns the first edge.");
	cls_IntTools_CommonPrt.def("Edge2", (const TopoDS_Edge & (IntTools_CommonPrt::*)() const ) &IntTools_CommonPrt::Edge2, "Returns the second edge");
	cls_IntTools_CommonPrt.def("Type", (TopAbs_ShapeEnum (IntTools_CommonPrt::*)() const ) &IntTools_CommonPrt::Type, "Returns the type of the common part");
	cls_IntTools_CommonPrt.def("Range1", (const IntTools_Range & (IntTools_CommonPrt::*)() const ) &IntTools_CommonPrt::Range1, "Returns the range of first edge");
	cls_IntTools_CommonPrt.def("Range1", (void (IntTools_CommonPrt::*)(Standard_Real &, Standard_Real &) const ) &IntTools_CommonPrt::Range1, "Returns the range of first edge.", py::arg("tf"), py::arg("tl"));
	cls_IntTools_CommonPrt.def("Ranges2", (const IntTools_SequenceOfRanges & (IntTools_CommonPrt::*)() const ) &IntTools_CommonPrt::Ranges2, "Returns the ranges of second edge.");
	cls_IntTools_CommonPrt.def("ChangeRanges2", (IntTools_SequenceOfRanges & (IntTools_CommonPrt::*)()) &IntTools_CommonPrt::ChangeRanges2, "Returns the ranges of second edge.");
	cls_IntTools_CommonPrt.def("VertexParameter1", (Standard_Real (IntTools_CommonPrt::*)() const ) &IntTools_CommonPrt::VertexParameter1, "Returns parameter of first vertex");
	cls_IntTools_CommonPrt.def("VertexParameter2", (Standard_Real (IntTools_CommonPrt::*)() const ) &IntTools_CommonPrt::VertexParameter2, "Returns parameter of second vertex");
	cls_IntTools_CommonPrt.def("Copy", (void (IntTools_CommonPrt::*)(IntTools_CommonPrt &) const ) &IntTools_CommonPrt::Copy, "Copies me to anOther", py::arg("anOther"));
	cls_IntTools_CommonPrt.def("AllNullFlag", (Standard_Boolean (IntTools_CommonPrt::*)() const ) &IntTools_CommonPrt::AllNullFlag, "Modifier");
	cls_IntTools_CommonPrt.def("SetAllNullFlag", (void (IntTools_CommonPrt::*)(const Standard_Boolean)) &IntTools_CommonPrt::SetAllNullFlag, "Selector", py::arg("aFlag"));
	cls_IntTools_CommonPrt.def("SetBoundingPoints", (void (IntTools_CommonPrt::*)(const gp_Pnt &, const gp_Pnt &)) &IntTools_CommonPrt::SetBoundingPoints, "Modifier", py::arg("aP1"), py::arg("aP2"));
	cls_IntTools_CommonPrt.def("BoundingPoints", (void (IntTools_CommonPrt::*)(gp_Pnt &, gp_Pnt &) const ) &IntTools_CommonPrt::BoundingPoints, "Selector", py::arg("aP1"), py::arg("aP2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_Root.hxx
	py::class_<IntTools_Root, std::unique_ptr<IntTools_Root, Deleter<IntTools_Root>>> cls_IntTools_Root(mod, "IntTools_Root", "The class is to describe the root of function of one variable for Edge/Edge and Edge/Surface algorithms.");
	cls_IntTools_Root.def(py::init<>());
	cls_IntTools_Root.def(py::init<const Standard_Real, const Standard_Integer>(), py::arg("aRoot"), py::arg("aType"));
	cls_IntTools_Root.def("SetRoot", (void (IntTools_Root::*)(const Standard_Real)) &IntTools_Root::SetRoot, "Sets the Root's value", py::arg("aRoot"));
	cls_IntTools_Root.def("SetType", (void (IntTools_Root::*)(const Standard_Integer)) &IntTools_Root::SetType, "Sets the Root's Type", py::arg("aType"));
	cls_IntTools_Root.def("SetStateBefore", (void (IntTools_Root::*)(const TopAbs_State)) &IntTools_Root::SetStateBefore, "Set the value of the state before the root (at t=Root-dt)", py::arg("aState"));
	cls_IntTools_Root.def("SetStateAfter", (void (IntTools_Root::*)(const TopAbs_State)) &IntTools_Root::SetStateAfter, "Set the value of the state after the root (at t=Root-dt)", py::arg("aState"));
	cls_IntTools_Root.def("SetLayerHeight", (void (IntTools_Root::*)(const Standard_Real)) &IntTools_Root::SetLayerHeight, "Not used in Edge/Edge algorithm", py::arg("aHeight"));
	// FIXME cls_IntTools_Root.def("SetInterval", (void (IntTools_Root::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_Root::SetInterval, "Sets the interval from which the Root was found [t1,t2] and the corresponding values of the function on the bounds f(t1), f(t2).", py::arg("t1"), py::arg("t2"), py::arg("f1"), py::arg("f2"));
	cls_IntTools_Root.def("Root", (Standard_Real (IntTools_Root::*)() const ) &IntTools_Root::Root, "Returns the Root value");
	// FIXME cls_IntTools_Root.def("Type", (Standard_Integer (IntTools_Root::*)() const ) &IntTools_Root::Type, "Returns the type of the root =0 - Simple (was found by bisection method); =2 - Smart when f1=0, f2!=0 or vice versa (was found by Fibbonacci method); =1 - Pure (pure zero for all t [t1,t2] );");
	cls_IntTools_Root.def("StateBefore", (TopAbs_State (IntTools_Root::*)() const ) &IntTools_Root::StateBefore, "Returns the state before the root");
	cls_IntTools_Root.def("StateAfter", (TopAbs_State (IntTools_Root::*)() const ) &IntTools_Root::StateAfter, "Returns the state after the root");
	cls_IntTools_Root.def("LayerHeight", (Standard_Real (IntTools_Root::*)() const ) &IntTools_Root::LayerHeight, "Not used in Edge/Edge algorithm");
	// FIXME cls_IntTools_Root.def("IsValid", (Standard_Boolean (IntTools_Root::*)() const ) &IntTools_Root::IsValid, "Returns the validity flag for the root, True if myStateBefore==TopAbs_OUT && myStateAfter==TopAbs_IN or myStateBefore==TopAbs_OUT && myStateAfter==TopAbs_ON or myStateBefore==TopAbs_ON && myStateAfter==TopAbs_OUT or myStateBefore==TopAbs_IN && myStateAfter==TopAbs_OUT . For other cases it returns False.");
	// FIXME cls_IntTools_Root.def("Interval", (void (IntTools_Root::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &IntTools_Root::Interval, "Returns the values of interval from which the Root was found [t1,t2] and the corresponding values of the function on the bounds f(t1), f(t2).", py::arg("t1"), py::arg("t2"), py::arg("f1"), py::arg("f2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_CArray1OfReal.hxx
	py::class_<IntTools_CArray1OfReal, std::unique_ptr<IntTools_CArray1OfReal, Deleter<IntTools_CArray1OfReal>>> cls_IntTools_CArray1OfReal(mod, "IntTools_CArray1OfReal", "None");
	cls_IntTools_CArray1OfReal.def(py::init<>());
	cls_IntTools_CArray1OfReal.def(py::init<const Standard_Integer>(), py::arg("Length"));
	cls_IntTools_CArray1OfReal.def(py::init<const Standard_Real &, const Standard_Integer>(), py::arg("Item"), py::arg("Length"));
	cls_IntTools_CArray1OfReal.def("Init", (void (IntTools_CArray1OfReal::*)(const Standard_Real &)) &IntTools_CArray1OfReal::Init, "Initializes the array with a given value.", py::arg("V"));
	cls_IntTools_CArray1OfReal.def("Resize", (void (IntTools_CArray1OfReal::*)(const Standard_Integer)) &IntTools_CArray1OfReal::Resize, "destroy current content and realloc the new size does nothing if Length() == theLength", py::arg("theNewLength"));
	cls_IntTools_CArray1OfReal.def("Destroy", (void (IntTools_CArray1OfReal::*)()) &IntTools_CArray1OfReal::Destroy, "Frees the allocated area corresponding to the array.");
	cls_IntTools_CArray1OfReal.def("Length", (Standard_Integer (IntTools_CArray1OfReal::*)() const ) &IntTools_CArray1OfReal::Length, "Returns the number of elements of <me>.");
	cls_IntTools_CArray1OfReal.def("Append", (void (IntTools_CArray1OfReal::*)(const Standard_Real &)) &IntTools_CArray1OfReal::Append, "None", py::arg("Value"));
	cls_IntTools_CArray1OfReal.def("SetValue", (void (IntTools_CArray1OfReal::*)(const Standard_Integer, const Standard_Real &)) &IntTools_CArray1OfReal::SetValue, "Sets the <Index>th element of the array to <Value>.", py::arg("Index"), py::arg("Value"));
	cls_IntTools_CArray1OfReal.def("Value", (const Standard_Real & (IntTools_CArray1OfReal::*)(const Standard_Integer) const ) &IntTools_CArray1OfReal::Value, "Returns the value of the <Index>th element of the array.", py::arg("Index"));
	cls_IntTools_CArray1OfReal.def("__call__", (const Standard_Real & (IntTools_CArray1OfReal::*)(const Standard_Integer) const ) &IntTools_CArray1OfReal::operator(), py::is_operator(), "None", py::arg("Index"));
	cls_IntTools_CArray1OfReal.def("ChangeValue", (Standard_Real & (IntTools_CArray1OfReal::*)(const Standard_Integer)) &IntTools_CArray1OfReal::ChangeValue, "Returns the value of the <Index>th element of the array.", py::arg("Index"));
	cls_IntTools_CArray1OfReal.def("__call__", (Standard_Real & (IntTools_CArray1OfReal::*)(const Standard_Integer)) &IntTools_CArray1OfReal::operator(), py::is_operator(), "None", py::arg("Index"));
	cls_IntTools_CArray1OfReal.def("IsEqual", (Standard_Boolean (IntTools_CArray1OfReal::*)(const IntTools_CArray1OfReal &) const ) &IntTools_CArray1OfReal::IsEqual, "Applys the == operator on each array item", py::arg("Other"));
	cls_IntTools_CArray1OfReal.def("__eq__", (Standard_Boolean (IntTools_CArray1OfReal::*)(const IntTools_CArray1OfReal &) const ) &IntTools_CArray1OfReal::operator==, py::is_operator(), "None", py::arg("Other"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_EdgeEdge.hxx
	py::class_<IntTools_EdgeEdge, std::unique_ptr<IntTools_EdgeEdge, Deleter<IntTools_EdgeEdge>>> cls_IntTools_EdgeEdge(mod, "IntTools_EdgeEdge", "The class provides Edge/Edge intersection algorithm based on the intersection between edges bounding boxes.");
	cls_IntTools_EdgeEdge.def(py::init<>());
	cls_IntTools_EdgeEdge.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("theEdge1"), py::arg("theEdge2"));
	cls_IntTools_EdgeEdge.def(py::init<const TopoDS_Edge &, const Standard_Real, const Standard_Real, const TopoDS_Edge &, const Standard_Real, const Standard_Real>(), py::arg("theEdge1"), py::arg("aT11"), py::arg("aT12"), py::arg("theEdge2"), py::arg("aT21"), py::arg("aT22"));
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
	cls_IntTools_EdgeEdge.def("IsDone", (Standard_Boolean (IntTools_EdgeEdge::*)() const ) &IntTools_EdgeEdge::IsDone, "Returns TRUE if common part(s) is(are) found");
	cls_IntTools_EdgeEdge.def("FuzzyValue", (Standard_Real (IntTools_EdgeEdge::*)() const ) &IntTools_EdgeEdge::FuzzyValue, "Returns Fuzzy value");
	cls_IntTools_EdgeEdge.def("CommonParts", (const IntTools_SequenceOfCommonPrts & (IntTools_EdgeEdge::*)() const ) &IntTools_EdgeEdge::CommonParts, "Returns common parts");
	cls_IntTools_EdgeEdge.def("UseQuickCoincidenceCheck", (void (IntTools_EdgeEdge::*)(const Standard_Boolean)) &IntTools_EdgeEdge::UseQuickCoincidenceCheck, "Sets the flag myQuickCoincidenceCheck", py::arg("bFlag"));
	cls_IntTools_EdgeEdge.def("IsCoincidenceCheckedQuickly", (Standard_Boolean (IntTools_EdgeEdge::*)()) &IntTools_EdgeEdge::IsCoincidenceCheckedQuickly, "Returns the flag myQuickCoincidenceCheck");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_EdgeFace.hxx
	py::class_<IntTools_EdgeFace, std::unique_ptr<IntTools_EdgeFace, Deleter<IntTools_EdgeFace>>> cls_IntTools_EdgeFace(mod, "IntTools_EdgeFace", "The class provides Edge/Face algorithm to determine common parts between edge and face in 3-d space. Common parts can be : Vertices or Edges.");
	cls_IntTools_EdgeFace.def(py::init<>());
	cls_IntTools_EdgeFace.def("SetEdge", (void (IntTools_EdgeFace::*)(const TopoDS_Edge &)) &IntTools_EdgeFace::SetEdge, "Initializes algorithm by the edge anEdge", py::arg("anEdge"));
	cls_IntTools_EdgeFace.def("SetFace", (void (IntTools_EdgeFace::*)(const TopoDS_Face &)) &IntTools_EdgeFace::SetFace, "Initializes algorithm by the face aFace", py::arg("aFace"));
	cls_IntTools_EdgeFace.def("Edge", (const TopoDS_Edge & (IntTools_EdgeFace::*)() const ) &IntTools_EdgeFace::Edge, "Returns edge");
	cls_IntTools_EdgeFace.def("Face", (const TopoDS_Face & (IntTools_EdgeFace::*)() const ) &IntTools_EdgeFace::Face, "Returns face");
	cls_IntTools_EdgeFace.def("SetDiscretize", (void (IntTools_EdgeFace::*)(const Standard_Integer)) &IntTools_EdgeFace::SetDiscretize, "Initializes algorithm by discretization value", py::arg("aDiscret"));
	cls_IntTools_EdgeFace.def("SetDeflection", (void (IntTools_EdgeFace::*)(const Standard_Real)) &IntTools_EdgeFace::SetDeflection, "Initializes algorithm by deflection value", py::arg("aDeflection"));
	cls_IntTools_EdgeFace.def("SetEpsilonT", (void (IntTools_EdgeFace::*)(const Standard_Real)) &IntTools_EdgeFace::SetEpsilonT, "Initializes algorithm by parameter tolerance", py::arg("anEpsT"));
	cls_IntTools_EdgeFace.def("SetRange", (void (IntTools_EdgeFace::*)(const IntTools_Range &)) &IntTools_EdgeFace::SetRange, "Sets boundaries for edge. The algorithm processes edge inside these boundaries.", py::arg("aRange"));
	cls_IntTools_EdgeFace.def("SetRange", (void (IntTools_EdgeFace::*)(const Standard_Real, const Standard_Real)) &IntTools_EdgeFace::SetRange, "Sets boundaries for edge. The algorithm processes edge inside these boundaries.", py::arg("aFirst"), py::arg("aLast"));
	cls_IntTools_EdgeFace.def("SetContext", (void (IntTools_EdgeFace::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_EdgeFace::SetContext, "Sets the intersecton context", py::arg("theContext"));
	cls_IntTools_EdgeFace.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_EdgeFace::*)() const ) &IntTools_EdgeFace::Context, "Gets the intersecton context");
	cls_IntTools_EdgeFace.def("SetFuzzyValue", (void (IntTools_EdgeFace::*)(const Standard_Real)) &IntTools_EdgeFace::SetFuzzyValue, "Sets the Fuzzy value", py::arg("theFuzz"));
	cls_IntTools_EdgeFace.def("FuzzyValue", (Standard_Real (IntTools_EdgeFace::*)() const ) &IntTools_EdgeFace::FuzzyValue, "Returns Fuzzy value");
	cls_IntTools_EdgeFace.def("Perform", (void (IntTools_EdgeFace::*)()) &IntTools_EdgeFace::Perform, "Launches the process");
	cls_IntTools_EdgeFace.def("IsDone", (Standard_Boolean (IntTools_EdgeFace::*)() const ) &IntTools_EdgeFace::IsDone, "Returns true if computation was done successfully, otherwise returns false");
	cls_IntTools_EdgeFace.def("ErrorStatus", (Standard_Integer (IntTools_EdgeFace::*)() const ) &IntTools_EdgeFace::ErrorStatus, "Returns code of completion 0 - means successful completion 1 - the process was not started 2,3,4,5 - invalid source data for the algorithm 6 - discretization failed 7 - no projectable ranges found 11 - distance computing error");
	cls_IntTools_EdgeFace.def("CommonParts", (const IntTools_SequenceOfCommonPrts & (IntTools_EdgeFace::*)() const ) &IntTools_EdgeFace::CommonParts, "Returns results");
	cls_IntTools_EdgeFace.def("Range", (const IntTools_Range & (IntTools_EdgeFace::*)() const ) &IntTools_EdgeFace::Range, "Returns boundaries for edge");
	cls_IntTools_EdgeFace.def("UseQuickCoincidenceCheck", (void (IntTools_EdgeFace::*)(const Standard_Boolean)) &IntTools_EdgeFace::UseQuickCoincidenceCheck, "Sets the flag myQuickCoincidenceCheck", py::arg("bFlag"));
	cls_IntTools_EdgeFace.def("IsCoincidenceCheckedQuickly", (Standard_Boolean (IntTools_EdgeFace::*)()) &IntTools_EdgeFace::IsCoincidenceCheckedQuickly, "Returns the flag myQuickCoincidenceCheck");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_MarkedRangeSet.hxx
	py::class_<IntTools_MarkedRangeSet, std::unique_ptr<IntTools_MarkedRangeSet, Deleter<IntTools_MarkedRangeSet>>> cls_IntTools_MarkedRangeSet(mod, "IntTools_MarkedRangeSet", "class MarkedRangeSet provides continuous set of ranges marked with flags");
	cls_IntTools_MarkedRangeSet.def(py::init<>());
	cls_IntTools_MarkedRangeSet.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theInitFlag"));
	cls_IntTools_MarkedRangeSet.def(py::init<const IntTools_CArray1OfReal &, const Standard_Integer>(), py::arg("theSortedArray"), py::arg("theInitFlag"));
	cls_IntTools_MarkedRangeSet.def("SetBoundaries", (void (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &IntTools_MarkedRangeSet::SetBoundaries, "build set of ranges which consists of one range with boundary values theFirstBoundary and theLastBoundary", py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theInitFlag"));
	cls_IntTools_MarkedRangeSet.def("SetRanges", (void (IntTools_MarkedRangeSet::*)(const IntTools_CArray1OfReal &, const Standard_Integer)) &IntTools_MarkedRangeSet::SetRanges, "Build set of ranges based on the array of progressive sorted values", py::arg("theSortedArray"), py::arg("theInitFlag"));
	cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theFlag"));
	cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const IntTools_Range &, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theRange"), py::arg("theFlag"));
	cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. The index theIndex is a position where the range will be inserted. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theFlag"), py::arg("theIndex"));
	cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const IntTools_Range &, const Standard_Integer, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. The index theIndex is a position where the range will be inserted. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theRange"), py::arg("theFlag"), py::arg("theIndex"));
	cls_IntTools_MarkedRangeSet.def("SetFlag", (void (IntTools_MarkedRangeSet::*)(const Standard_Integer, const Standard_Integer)) &IntTools_MarkedRangeSet::SetFlag, "Set flag theFlag for range with index theIndex", py::arg("theIndex"), py::arg("theFlag"));
	cls_IntTools_MarkedRangeSet.def("Flag", (Standard_Integer (IntTools_MarkedRangeSet::*)(const Standard_Integer) const ) &IntTools_MarkedRangeSet::Flag, "Returns flag of the range with index theIndex", py::arg("theIndex"));
	cls_IntTools_MarkedRangeSet.def("GetIndex", (Standard_Integer (IntTools_MarkedRangeSet::*)(const Standard_Real) const ) &IntTools_MarkedRangeSet::GetIndex, "Returns index of range which contains theValue. If theValue do not belong any range returns 0.", py::arg("theValue"));
	cls_IntTools_MarkedRangeSet.def("GetIndices", (const TColStd_SequenceOfInteger & (IntTools_MarkedRangeSet::*)(const Standard_Real)) &IntTools_MarkedRangeSet::GetIndices, "None", py::arg("theValue"));
	cls_IntTools_MarkedRangeSet.def("GetIndex", (Standard_Integer (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Boolean) const ) &IntTools_MarkedRangeSet::GetIndex, "Returns index of range which contains theValue If theValue do not belong any range returns 0. If UseLower is Standard_True then lower boundary of the range can be equal to theValue, otherwise upper boundary of the range can be equal to theValue.", py::arg("theValue"), py::arg("UseLower"));
	cls_IntTools_MarkedRangeSet.def("Length", (Standard_Integer (IntTools_MarkedRangeSet::*)() const ) &IntTools_MarkedRangeSet::Length, "Returns number of ranges");
	cls_IntTools_MarkedRangeSet.def("Range", (IntTools_Range (IntTools_MarkedRangeSet::*)(const Standard_Integer) const ) &IntTools_MarkedRangeSet::Range, "Returns the range with index theIndex. the Index can be from 1 to Length()", py::arg("theIndex"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_BaseRangeSample.hxx
	py::class_<IntTools_BaseRangeSample, std::unique_ptr<IntTools_BaseRangeSample, Deleter<IntTools_BaseRangeSample>>> cls_IntTools_BaseRangeSample(mod, "IntTools_BaseRangeSample", "base class for range index management");
	cls_IntTools_BaseRangeSample.def(py::init<>());
	cls_IntTools_BaseRangeSample.def(py::init<const Standard_Integer>(), py::arg("theDepth"));
	cls_IntTools_BaseRangeSample.def("SetDepth", (void (IntTools_BaseRangeSample::*)(const Standard_Integer)) &IntTools_BaseRangeSample::SetDepth, "None", py::arg("theDepth"));
	cls_IntTools_BaseRangeSample.def("GetDepth", (Standard_Integer (IntTools_BaseRangeSample::*)() const ) &IntTools_BaseRangeSample::GetDepth, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_CurveRangeSample.hxx
	py::class_<IntTools_CurveRangeSample, std::unique_ptr<IntTools_CurveRangeSample, Deleter<IntTools_CurveRangeSample>>, IntTools_BaseRangeSample> cls_IntTools_CurveRangeSample(mod, "IntTools_CurveRangeSample", "class for range index management of curve");
	cls_IntTools_CurveRangeSample.def(py::init<>());
	cls_IntTools_CurveRangeSample.def(py::init<const Standard_Integer>(), py::arg("theIndex"));
	cls_IntTools_CurveRangeSample.def("SetRangeIndex", (void (IntTools_CurveRangeSample::*)(const Standard_Integer)) &IntTools_CurveRangeSample::SetRangeIndex, "None", py::arg("theIndex"));
	cls_IntTools_CurveRangeSample.def("GetRangeIndex", (Standard_Integer (IntTools_CurveRangeSample::*)() const ) &IntTools_CurveRangeSample::GetRangeIndex, "None");
	cls_IntTools_CurveRangeSample.def("IsEqual", (Standard_Boolean (IntTools_CurveRangeSample::*)(const IntTools_CurveRangeSample &) const ) &IntTools_CurveRangeSample::IsEqual, "None", py::arg("Other"));
	cls_IntTools_CurveRangeSample.def("GetRange", (IntTools_Range (IntTools_CurveRangeSample::*)(const Standard_Real, const Standard_Real, const Standard_Integer) const ) &IntTools_CurveRangeSample::GetRange, "None", py::arg("theFirst"), py::arg("theLast"), py::arg("theNbSample"));
	cls_IntTools_CurveRangeSample.def("GetRangeIndexDeeper", (Standard_Integer (IntTools_CurveRangeSample::*)(const Standard_Integer) const ) &IntTools_CurveRangeSample::GetRangeIndexDeeper, "None", py::arg("theNbSample"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_SurfaceRangeSample.hxx
	py::class_<IntTools_SurfaceRangeSample, std::unique_ptr<IntTools_SurfaceRangeSample, Deleter<IntTools_SurfaceRangeSample>>> cls_IntTools_SurfaceRangeSample(mod, "IntTools_SurfaceRangeSample", "class for range index management of surface");
	cls_IntTools_SurfaceRangeSample.def(py::init<>());
	cls_IntTools_SurfaceRangeSample.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theIndexU"), py::arg("theDepthU"), py::arg("theIndexV"), py::arg("theDepthV"));
	cls_IntTools_SurfaceRangeSample.def(py::init<const IntTools_CurveRangeSample &, const IntTools_CurveRangeSample &>(), py::arg("theRangeU"), py::arg("theRangeV"));
	cls_IntTools_SurfaceRangeSample.def(py::init([] (const IntTools_SurfaceRangeSample &other) {return new IntTools_SurfaceRangeSample(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_SurfaceRangeSample.def("Assign", (IntTools_SurfaceRangeSample & (IntTools_SurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeSample::Assign, "None", py::arg("Other"));
	cls_IntTools_SurfaceRangeSample.def("assign", (IntTools_SurfaceRangeSample & (IntTools_SurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeSample::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_IntTools_SurfaceRangeSample.def("SetRanges", (void (IntTools_SurfaceRangeSample::*)(const IntTools_CurveRangeSample &, const IntTools_CurveRangeSample &)) &IntTools_SurfaceRangeSample::SetRanges, "None", py::arg("theRangeU"), py::arg("theRangeV"));
	cls_IntTools_SurfaceRangeSample.def("GetRanges", (void (IntTools_SurfaceRangeSample::*)(IntTools_CurveRangeSample &, IntTools_CurveRangeSample &) const ) &IntTools_SurfaceRangeSample::GetRanges, "None", py::arg("theRangeU"), py::arg("theRangeV"));
	cls_IntTools_SurfaceRangeSample.def("SetIndexes", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SurfaceRangeSample::SetIndexes, "None", py::arg("theIndexU"), py::arg("theIndexV"));
	cls_IntTools_SurfaceRangeSample.def("GetIndexes", (void (IntTools_SurfaceRangeSample::*)(Standard_Integer &, Standard_Integer &) const ) &IntTools_SurfaceRangeSample::GetIndexes, "None", py::arg("theIndexU"), py::arg("theIndexV"));
	cls_IntTools_SurfaceRangeSample.def("GetDepths", (void (IntTools_SurfaceRangeSample::*)(Standard_Integer &, Standard_Integer &) const ) &IntTools_SurfaceRangeSample::GetDepths, "None", py::arg("theDepthU"), py::arg("theDepthV"));
	cls_IntTools_SurfaceRangeSample.def("SetSampleRangeU", (void (IntTools_SurfaceRangeSample::*)(const IntTools_CurveRangeSample &)) &IntTools_SurfaceRangeSample::SetSampleRangeU, "None", py::arg("theRangeSampleU"));
	cls_IntTools_SurfaceRangeSample.def("GetSampleRangeU", (const IntTools_CurveRangeSample & (IntTools_SurfaceRangeSample::*)() const ) &IntTools_SurfaceRangeSample::GetSampleRangeU, "None");
	cls_IntTools_SurfaceRangeSample.def("SetSampleRangeV", (void (IntTools_SurfaceRangeSample::*)(const IntTools_CurveRangeSample &)) &IntTools_SurfaceRangeSample::SetSampleRangeV, "None", py::arg("theRangeSampleV"));
	cls_IntTools_SurfaceRangeSample.def("GetSampleRangeV", (const IntTools_CurveRangeSample & (IntTools_SurfaceRangeSample::*)() const ) &IntTools_SurfaceRangeSample::GetSampleRangeV, "None");
	cls_IntTools_SurfaceRangeSample.def("SetIndexU", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetIndexU, "None", py::arg("theIndexU"));
	cls_IntTools_SurfaceRangeSample.def("GetIndexU", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const ) &IntTools_SurfaceRangeSample::GetIndexU, "None");
	cls_IntTools_SurfaceRangeSample.def("SetIndexV", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetIndexV, "None", py::arg("theIndexV"));
	cls_IntTools_SurfaceRangeSample.def("GetIndexV", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const ) &IntTools_SurfaceRangeSample::GetIndexV, "None");
	cls_IntTools_SurfaceRangeSample.def("SetDepthU", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetDepthU, "None", py::arg("theDepthU"));
	cls_IntTools_SurfaceRangeSample.def("GetDepthU", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const ) &IntTools_SurfaceRangeSample::GetDepthU, "None");
	cls_IntTools_SurfaceRangeSample.def("SetDepthV", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetDepthV, "None", py::arg("theDepthV"));
	cls_IntTools_SurfaceRangeSample.def("GetDepthV", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const ) &IntTools_SurfaceRangeSample::GetDepthV, "None");
	cls_IntTools_SurfaceRangeSample.def("GetRangeU", (IntTools_Range (IntTools_SurfaceRangeSample::*)(const Standard_Real, const Standard_Real, const Standard_Integer) const ) &IntTools_SurfaceRangeSample::GetRangeU, "None", py::arg("theFirstU"), py::arg("theLastU"), py::arg("theNbSampleU"));
	cls_IntTools_SurfaceRangeSample.def("GetRangeV", (IntTools_Range (IntTools_SurfaceRangeSample::*)(const Standard_Real, const Standard_Real, const Standard_Integer) const ) &IntTools_SurfaceRangeSample::GetRangeV, "None", py::arg("theFirstV"), py::arg("theLastV"), py::arg("theNbSampleV"));
	cls_IntTools_SurfaceRangeSample.def("IsEqual", (Standard_Boolean (IntTools_SurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &) const ) &IntTools_SurfaceRangeSample::IsEqual, "None", py::arg("Other"));
	cls_IntTools_SurfaceRangeSample.def("GetRangeIndexUDeeper", (Standard_Integer (IntTools_SurfaceRangeSample::*)(const Standard_Integer) const ) &IntTools_SurfaceRangeSample::GetRangeIndexUDeeper, "None", py::arg("theNbSampleU"));
	cls_IntTools_SurfaceRangeSample.def("GetRangeIndexVDeeper", (Standard_Integer (IntTools_SurfaceRangeSample::*)(const Standard_Integer) const ) &IntTools_SurfaceRangeSample::GetRangeIndexVDeeper, "None", py::arg("theNbSampleV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_CurveRangeLocalizeData.hxx
	py::class_<IntTools_CurveRangeLocalizeData, std::unique_ptr<IntTools_CurveRangeLocalizeData, Deleter<IntTools_CurveRangeLocalizeData>>> cls_IntTools_CurveRangeLocalizeData(mod, "IntTools_CurveRangeLocalizeData", "None");
	cls_IntTools_CurveRangeLocalizeData.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("theNbSample"), py::arg("theMinRange"));
	cls_IntTools_CurveRangeLocalizeData.def("GetNbSample", (Standard_Integer (IntTools_CurveRangeLocalizeData::*)() const ) &IntTools_CurveRangeLocalizeData::GetNbSample, "None");
	cls_IntTools_CurveRangeLocalizeData.def("GetMinRange", (Standard_Real (IntTools_CurveRangeLocalizeData::*)() const ) &IntTools_CurveRangeLocalizeData::GetMinRange, "None");
	cls_IntTools_CurveRangeLocalizeData.def("AddOutRange", (void (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &)) &IntTools_CurveRangeLocalizeData::AddOutRange, "None", py::arg("theRange"));
	cls_IntTools_CurveRangeLocalizeData.def("AddBox", (void (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &, const Bnd_Box &)) &IntTools_CurveRangeLocalizeData::AddBox, "None", py::arg("theRange"), py::arg("theBox"));
	cls_IntTools_CurveRangeLocalizeData.def("FindBox", (Standard_Boolean (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &, Bnd_Box &) const ) &IntTools_CurveRangeLocalizeData::FindBox, "None", py::arg("theRange"), py::arg("theBox"));
	cls_IntTools_CurveRangeLocalizeData.def("IsRangeOut", (Standard_Boolean (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &) const ) &IntTools_CurveRangeLocalizeData::IsRangeOut, "None", py::arg("theRange"));
	cls_IntTools_CurveRangeLocalizeData.def("ListRangeOut", (void (IntTools_CurveRangeLocalizeData::*)(IntTools_ListOfCurveRangeSample &) const ) &IntTools_CurveRangeLocalizeData::ListRangeOut, "None", py::arg("theList"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_BeanFaceIntersector.hxx
	py::class_<IntTools_BeanFaceIntersector, std::unique_ptr<IntTools_BeanFaceIntersector, Deleter<IntTools_BeanFaceIntersector>>> cls_IntTools_BeanFaceIntersector(mod, "IntTools_BeanFaceIntersector", "The class BeanFaceIntersector computes ranges of parameters on the curve of a bean(part of edge) that bound the parts of bean which are on the surface of a face according to edge and face tolerances. Warning: The real boundaries of the face are not taken into account, Most of the result parts of the bean lays only inside the region of the surface, which includes the inside of the face. And the parts which are out of this region can be excluded from the result.");
	cls_IntTools_BeanFaceIntersector.def(py::init<>());
	cls_IntTools_BeanFaceIntersector.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("theEdge"), py::arg("theFace"));
	cls_IntTools_BeanFaceIntersector.def(py::init<const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theSurface"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));
	cls_IntTools_BeanFaceIntersector.def(py::init<const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirstParOnCurve"), py::arg("theLastParOnCurve"), py::arg("theUMinParameter"), py::arg("theUMaxParameter"), py::arg("theVMinParameter"), py::arg("theVMaxParameter"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));
	cls_IntTools_BeanFaceIntersector.def("Init", (void (IntTools_BeanFaceIntersector::*)(const TopoDS_Edge &, const TopoDS_Face &)) &IntTools_BeanFaceIntersector::Init, "Initializes the algorithm", py::arg("theEdge"), py::arg("theFace"));
	cls_IntTools_BeanFaceIntersector.def("Init", (void (IntTools_BeanFaceIntersector::*)(const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::Init, "Initializes the algorithm", py::arg("theCurve"), py::arg("theSurface"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));
	cls_IntTools_BeanFaceIntersector.def("Init", (void (IntTools_BeanFaceIntersector::*)(const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::Init, "Initializes the algorithm theUMinParameter, ... are used for optimization purposes", py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirstParOnCurve"), py::arg("theLastParOnCurve"), py::arg("theUMinParameter"), py::arg("theUMaxParameter"), py::arg("theVMinParameter"), py::arg("theVMaxParameter"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));
	cls_IntTools_BeanFaceIntersector.def("SetContext", (void (IntTools_BeanFaceIntersector::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_BeanFaceIntersector::SetContext, "Sets the intersecton context", py::arg("theContext"));
	cls_IntTools_BeanFaceIntersector.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_BeanFaceIntersector::*)() const ) &IntTools_BeanFaceIntersector::Context, "Gets the intersecton context");
	cls_IntTools_BeanFaceIntersector.def("SetBeanParameters", (void (IntTools_BeanFaceIntersector::*)(const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::SetBeanParameters, "Set restrictions for curve", py::arg("theFirstParOnCurve"), py::arg("theLastParOnCurve"));
	cls_IntTools_BeanFaceIntersector.def("SetSurfaceParameters", (void (IntTools_BeanFaceIntersector::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::SetSurfaceParameters, "Set restrictions for surface", py::arg("theUMinParameter"), py::arg("theUMaxParameter"), py::arg("theVMinParameter"), py::arg("theVMaxParameter"));
	cls_IntTools_BeanFaceIntersector.def("Perform", (void (IntTools_BeanFaceIntersector::*)()) &IntTools_BeanFaceIntersector::Perform, "Launches the algorithm");
	cls_IntTools_BeanFaceIntersector.def("IsDone", (Standard_Boolean (IntTools_BeanFaceIntersector::*)() const ) &IntTools_BeanFaceIntersector::IsDone, "None");
	cls_IntTools_BeanFaceIntersector.def("Result", (const IntTools_SequenceOfRanges & (IntTools_BeanFaceIntersector::*)() const ) &IntTools_BeanFaceIntersector::Result, "None");
	cls_IntTools_BeanFaceIntersector.def("Result", (void (IntTools_BeanFaceIntersector::*)(IntTools_SequenceOfRanges &) const ) &IntTools_BeanFaceIntersector::Result, "None", py::arg("theResults"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_PntOnFace.hxx
	py::class_<IntTools_PntOnFace, std::unique_ptr<IntTools_PntOnFace, Deleter<IntTools_PntOnFace>>> cls_IntTools_PntOnFace(mod, "IntTools_PntOnFace", "Contains a Face, a 3d point, corresponded UV parameters and a flag");
	cls_IntTools_PntOnFace.def(py::init<>());
	cls_IntTools_PntOnFace.def("Init", (void (IntTools_PntOnFace::*)(const TopoDS_Face &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &IntTools_PntOnFace::Init, "Initializes me by aFace, a 3d point and it's UV parameters on face", py::arg("aF"), py::arg("aP"), py::arg("U"), py::arg("V"));
	cls_IntTools_PntOnFace.def("SetFace", (void (IntTools_PntOnFace::*)(const TopoDS_Face &)) &IntTools_PntOnFace::SetFace, "Modifier", py::arg("aF"));
	cls_IntTools_PntOnFace.def("SetPnt", (void (IntTools_PntOnFace::*)(const gp_Pnt &)) &IntTools_PntOnFace::SetPnt, "Modifier", py::arg("aP"));
	cls_IntTools_PntOnFace.def("SetParameters", (void (IntTools_PntOnFace::*)(const Standard_Real, const Standard_Real)) &IntTools_PntOnFace::SetParameters, "Modifier", py::arg("U"), py::arg("V"));
	cls_IntTools_PntOnFace.def("SetValid", (void (IntTools_PntOnFace::*)(const Standard_Boolean)) &IntTools_PntOnFace::SetValid, "Modifier", py::arg("bF"));
	cls_IntTools_PntOnFace.def("Valid", (Standard_Boolean (IntTools_PntOnFace::*)() const ) &IntTools_PntOnFace::Valid, "Selector");
	cls_IntTools_PntOnFace.def("Face", (const TopoDS_Face & (IntTools_PntOnFace::*)() const ) &IntTools_PntOnFace::Face, "Selector");
	cls_IntTools_PntOnFace.def("Pnt", (const gp_Pnt & (IntTools_PntOnFace::*)() const ) &IntTools_PntOnFace::Pnt, "Selector");
	cls_IntTools_PntOnFace.def("Parameters", (void (IntTools_PntOnFace::*)(Standard_Real &, Standard_Real &) const ) &IntTools_PntOnFace::Parameters, "Selector", py::arg("U"), py::arg("V"));
	cls_IntTools_PntOnFace.def("IsValid", (Standard_Boolean (IntTools_PntOnFace::*)() const ) &IntTools_PntOnFace::IsValid, "Selector");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_PntOn2Faces.hxx
	py::class_<IntTools_PntOn2Faces, std::unique_ptr<IntTools_PntOn2Faces, Deleter<IntTools_PntOn2Faces>>> cls_IntTools_PntOn2Faces(mod, "IntTools_PntOn2Faces", "Contains two points PntOnFace from IntTools and a flag");
	cls_IntTools_PntOn2Faces.def(py::init<>());
	cls_IntTools_PntOn2Faces.def(py::init<const IntTools_PntOnFace &, const IntTools_PntOnFace &>(), py::arg("aP1"), py::arg("aP2"));
	cls_IntTools_PntOn2Faces.def("SetP1", (void (IntTools_PntOn2Faces::*)(const IntTools_PntOnFace &)) &IntTools_PntOn2Faces::SetP1, "Modifier", py::arg("aP1"));
	cls_IntTools_PntOn2Faces.def("SetP2", (void (IntTools_PntOn2Faces::*)(const IntTools_PntOnFace &)) &IntTools_PntOn2Faces::SetP2, "Modifier", py::arg("aP2"));
	cls_IntTools_PntOn2Faces.def("SetValid", (void (IntTools_PntOn2Faces::*)(const Standard_Boolean)) &IntTools_PntOn2Faces::SetValid, "Modifier", py::arg("bF"));
	cls_IntTools_PntOn2Faces.def("P1", (const IntTools_PntOnFace & (IntTools_PntOn2Faces::*)() const ) &IntTools_PntOn2Faces::P1, "Selector");
	cls_IntTools_PntOn2Faces.def("P2", (const IntTools_PntOnFace & (IntTools_PntOn2Faces::*)() const ) &IntTools_PntOn2Faces::P2, "Selector");
	cls_IntTools_PntOn2Faces.def("IsValid", (Standard_Boolean (IntTools_PntOn2Faces::*)() const ) &IntTools_PntOn2Faces::IsValid, "Selector");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_TopolTool.hxx
	py::class_<IntTools_TopolTool, opencascade::handle<IntTools_TopolTool>, Adaptor3d_TopolTool> cls_IntTools_TopolTool(mod, "IntTools_TopolTool", "Class redefine methods of TopolTool from Adaptor3d concerning sample points");
	cls_IntTools_TopolTool.def(py::init<>());
	cls_IntTools_TopolTool.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("theSurface"));
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
	cls_IntTools_TopolTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntTools_TopolTool::*)() const ) &IntTools_TopolTool::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_FaceFace.hxx
	py::class_<IntTools_FaceFace, std::unique_ptr<IntTools_FaceFace, Deleter<IntTools_FaceFace>>> cls_IntTools_FaceFace(mod, "IntTools_FaceFace", "This class provides the intersection of face's underlying surfaces.");
	cls_IntTools_FaceFace.def(py::init<>());
	cls_IntTools_FaceFace.def("SetParameters", (void (IntTools_FaceFace::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real)) &IntTools_FaceFace::SetParameters, "Modifier", py::arg("ApproxCurves"), py::arg("ComputeCurveOnS1"), py::arg("ComputeCurveOnS2"), py::arg("ApproximationTolerance"));
	cls_IntTools_FaceFace.def("Perform", (void (IntTools_FaceFace::*)(const TopoDS_Face &, const TopoDS_Face &)) &IntTools_FaceFace::Perform, "Intersects underliing surfaces of F1 and F2 Use sum of tolerance of F1 and F2 as intersection criteria", py::arg("F1"), py::arg("F2"));
	cls_IntTools_FaceFace.def("IsDone", (Standard_Boolean (IntTools_FaceFace::*)() const ) &IntTools_FaceFace::IsDone, "Returns True if the intersection was successful");
	cls_IntTools_FaceFace.def("Lines", (const IntTools_SequenceOfCurves & (IntTools_FaceFace::*)() const ) &IntTools_FaceFace::Lines, "Returns sequence of 3d curves as result of intersection");
	cls_IntTools_FaceFace.def("Points", (const IntTools_SequenceOfPntOn2Faces & (IntTools_FaceFace::*)() const ) &IntTools_FaceFace::Points, "Returns sequence of 3d curves as result of intersection");
	cls_IntTools_FaceFace.def("Face1", (const TopoDS_Face & (IntTools_FaceFace::*)() const ) &IntTools_FaceFace::Face1, "Returns first of processed faces");
	cls_IntTools_FaceFace.def("Face2", (const TopoDS_Face & (IntTools_FaceFace::*)() const ) &IntTools_FaceFace::Face2, "Returns second of processed faces");
	cls_IntTools_FaceFace.def("TangentFaces", (Standard_Boolean (IntTools_FaceFace::*)() const ) &IntTools_FaceFace::TangentFaces, "Returns True if faces are tangent");
	cls_IntTools_FaceFace.def("PrepareLines3D", [](IntTools_FaceFace &self) -> void { return self.PrepareLines3D(); });
	cls_IntTools_FaceFace.def("PrepareLines3D", (void (IntTools_FaceFace::*)(const Standard_Boolean)) &IntTools_FaceFace::PrepareLines3D, "Provides post-processing the result lines. <bToSplit> - the flag. In case of <bToSplit> is true the closed 3D-curves will be splitted on parts. In case of <bToSplit> is false the closed 3D-curves remain untouched.", py::arg("bToSplit"));
	cls_IntTools_FaceFace.def("SetList", (void (IntTools_FaceFace::*)(IntSurf_ListOfPntOn2S &)) &IntTools_FaceFace::SetList, "None", py::arg("ListOfPnts"));
	cls_IntTools_FaceFace.def("SetContext", (void (IntTools_FaceFace::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_FaceFace::SetContext, "Sets the intersecton context", py::arg("aContext"));
	cls_IntTools_FaceFace.def("SetFuzzyValue", (void (IntTools_FaceFace::*)(const Standard_Real)) &IntTools_FaceFace::SetFuzzyValue, "Sets the Fuzzy value", py::arg("theFuzz"));
	cls_IntTools_FaceFace.def("FuzzyValue", (Standard_Real (IntTools_FaceFace::*)() const ) &IntTools_FaceFace::FuzzyValue, "Returns Fuzzy value");
	cls_IntTools_FaceFace.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_FaceFace::*)() const ) &IntTools_FaceFace::Context, "Gets the intersecton context");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_Tools.hxx
	py::class_<IntTools_Tools, std::unique_ptr<IntTools_Tools, Deleter<IntTools_Tools>>> cls_IntTools_Tools(mod, "IntTools_Tools", "The class contains handy static functions dealing with the geometry and topology.");
	cls_IntTools_Tools.def(py::init<>());
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
	cls_IntTools_Tools.def_static("VertexParameters_", (void (*)(const IntTools_CommonPrt &, Standard_Real &, Standard_Real &)) &IntTools_Tools::VertexParameters, "None", py::arg("theCP"), py::arg("theT1"), py::arg("theT2"));
	cls_IntTools_Tools.def_static("VertexParameter_", (void (*)(const IntTools_CommonPrt &, Standard_Real &)) &IntTools_Tools::VertexParameter, "None", py::arg("theCP"), py::arg("theT"));
	cls_IntTools_Tools.def_static("IsOnPave1_", (Standard_Boolean (*)(const Standard_Real, const IntTools_Range &, const Standard_Real)) &IntTools_Tools::IsOnPave1, "None", py::arg("theT"), py::arg("theRange"), py::arg("theTol"));
	cls_IntTools_Tools.def_static("IsInRange_", (Standard_Boolean (*)(const IntTools_Range &, const IntTools_Range &, const Standard_Real)) &IntTools_Tools::IsInRange, "Checks if the range <theR> interfere with the range <theRRef>", py::arg("theRRef"), py::arg("theR"), py::arg("theTol"));
	cls_IntTools_Tools.def_static("SegPln_", (Standard_Integer (*)(const gp_Lin &, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pln &, const Standard_Real, gp_Pnt &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &IntTools_Tools::SegPln, "None", py::arg("theLin"), py::arg("theTLin1"), py::arg("theTLin2"), py::arg("theTolLin"), py::arg("thePln"), py::arg("theTolPln"), py::arg("theP"), py::arg("theT"), py::arg("theTolP"), py::arg("theTmin"), py::arg("theTmax"));
	cls_IntTools_Tools.def_static("ComputeTolerance_", [](const opencascade::handle<Geom_Curve> & a0, const opencascade::handle<Geom2d_Curve> & a1, const opencascade::handle<Geom_Surface> & a2, const Standard_Real a3, const Standard_Real a4, Standard_Real & a5, Standard_Real & a6) -> Standard_Boolean { return IntTools_Tools::ComputeTolerance(a0, a1, a2, a3, a4, a5, a6); }, py::arg("theCurve3D"), py::arg("theCurve2D"), py::arg("theSurf"), py::arg("theFirst"), py::arg("theLast"), py::arg("theMaxDist"), py::arg("theMaxPar"));
	cls_IntTools_Tools.def_static("ComputeTolerance_", (Standard_Boolean (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, Standard_Real &, Standard_Real &, const Standard_Real)) &IntTools_Tools::ComputeTolerance, "Computes the max distance between points taken from 3D and 2D curves by the same parameter", py::arg("theCurve3D"), py::arg("theCurve2D"), py::arg("theSurf"), py::arg("theFirst"), py::arg("theLast"), py::arg("theMaxDist"), py::arg("theMaxPar"), py::arg("theTolRange"));
	cls_IntTools_Tools.def_static("ComputeIntRange_", (Standard_Real (*)(const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_Tools::ComputeIntRange, "Computes the correct Intersection range for Line/Line, Line/Plane and Plane/Plane intersections", py::arg("theTol1"), py::arg("theTol2"), py::arg("theAngle"));

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools.hxx
	py::class_<IntTools_CArray1, std::unique_ptr<IntTools_CArray1, Deleter<IntTools_CArray1>>> cls_IntTools_CArray1(mod, "IntTools_CArray1", "None");
	cls_IntTools_CArray1.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_CArray1OfInteger.hxx
	py::class_<IntTools_CArray1OfInteger, std::unique_ptr<IntTools_CArray1OfInteger, Deleter<IntTools_CArray1OfInteger>>> cls_IntTools_CArray1OfInteger(mod, "IntTools_CArray1OfInteger", "None");
	cls_IntTools_CArray1OfInteger.def(py::init<>());
	cls_IntTools_CArray1OfInteger.def(py::init<const Standard_Integer>(), py::arg("Length"));
	cls_IntTools_CArray1OfInteger.def(py::init<const Standard_Integer &, const Standard_Integer>(), py::arg("Item"), py::arg("Length"));
	cls_IntTools_CArray1OfInteger.def("Init", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer &)) &IntTools_CArray1OfInteger::Init, "Initializes the array with a given value.", py::arg("V"));
	cls_IntTools_CArray1OfInteger.def("Resize", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer)) &IntTools_CArray1OfInteger::Resize, "destroy current content and realloc the new size does nothing if Length() == theLength", py::arg("theNewLength"));
	cls_IntTools_CArray1OfInteger.def("Destroy", (void (IntTools_CArray1OfInteger::*)()) &IntTools_CArray1OfInteger::Destroy, "Frees the allocated area corresponding to the array.");
	cls_IntTools_CArray1OfInteger.def("Length", (Standard_Integer (IntTools_CArray1OfInteger::*)() const ) &IntTools_CArray1OfInteger::Length, "Returns the number of elements of <me>.");
	cls_IntTools_CArray1OfInteger.def("Append", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer &)) &IntTools_CArray1OfInteger::Append, "None", py::arg("Value"));
	cls_IntTools_CArray1OfInteger.def("SetValue", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer, const Standard_Integer &)) &IntTools_CArray1OfInteger::SetValue, "Sets the <Index>th element of the array to <Value>.", py::arg("Index"), py::arg("Value"));
	cls_IntTools_CArray1OfInteger.def("Value", (const Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer) const ) &IntTools_CArray1OfInteger::Value, "Returns the value of the <Index>th element of the array.", py::arg("Index"));
	cls_IntTools_CArray1OfInteger.def("__call__", (const Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer) const ) &IntTools_CArray1OfInteger::operator(), py::is_operator(), "None", py::arg("Index"));
	cls_IntTools_CArray1OfInteger.def("ChangeValue", (Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer)) &IntTools_CArray1OfInteger::ChangeValue, "Returns the value of the <Index>th element of the array.", py::arg("Index"));
	cls_IntTools_CArray1OfInteger.def("__call__", (Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer)) &IntTools_CArray1OfInteger::operator(), py::is_operator(), "None", py::arg("Index"));
	cls_IntTools_CArray1OfInteger.def("IsEqual", (Standard_Boolean (IntTools_CArray1OfInteger::*)(const IntTools_CArray1OfInteger &) const ) &IntTools_CArray1OfInteger::IsEqual, "Applys the == operator on each array item", py::arg("Other"));
	cls_IntTools_CArray1OfInteger.def("__eq__", (Standard_Boolean (IntTools_CArray1OfInteger::*)(const IntTools_CArray1OfInteger &) const ) &IntTools_CArray1OfInteger::operator==, py::is_operator(), "None", py::arg("Other"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_CurveRangeSampleMapHasher.hxx
	py::class_<IntTools_CurveRangeSampleMapHasher, std::unique_ptr<IntTools_CurveRangeSampleMapHasher, Deleter<IntTools_CurveRangeSampleMapHasher>>> cls_IntTools_CurveRangeSampleMapHasher(mod, "IntTools_CurveRangeSampleMapHasher", "class for range index management of curve");
	cls_IntTools_CurveRangeSampleMapHasher.def(py::init<>());
	cls_IntTools_CurveRangeSampleMapHasher.def_static("HashCode_", (Standard_Integer (*)(const IntTools_CurveRangeSample &, const Standard_Integer)) &IntTools_CurveRangeSampleMapHasher::HashCode, "Returns a HasCode value for the Key <K> in the range 0..Upper.", py::arg("K"), py::arg("Upper"));
	cls_IntTools_CurveRangeSampleMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const IntTools_CurveRangeSample &, const IntTools_CurveRangeSample &)) &IntTools_CurveRangeSampleMapHasher::IsEqual, "Returns True when the two keys are the same. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("S1"), py::arg("S2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_SurfaceRangeSampleMapHasher.hxx
	py::class_<IntTools_SurfaceRangeSampleMapHasher, std::unique_ptr<IntTools_SurfaceRangeSampleMapHasher, Deleter<IntTools_SurfaceRangeSampleMapHasher>>> cls_IntTools_SurfaceRangeSampleMapHasher(mod, "IntTools_SurfaceRangeSampleMapHasher", "None");
	cls_IntTools_SurfaceRangeSampleMapHasher.def(py::init<>());
	cls_IntTools_SurfaceRangeSampleMapHasher.def_static("HashCode_", (Standard_Integer (*)(const IntTools_SurfaceRangeSample &, const Standard_Integer)) &IntTools_SurfaceRangeSampleMapHasher::HashCode, "Returns a HasCode value for the Key <K> in the range 0..Upper.", py::arg("K"), py::arg("Upper"));
	cls_IntTools_SurfaceRangeSampleMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const IntTools_SurfaceRangeSample &, const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeSampleMapHasher::IsEqual, "Returns True when the two keys are the same. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("S1"), py::arg("S2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools.hxx
	py::class_<IntTools, std::unique_ptr<IntTools, Deleter<IntTools>>> cls_IntTools(mod, "IntTools", "Contains classes for intersection and classification purposes and accompanying classes");
	cls_IntTools.def(py::init<>());
	cls_IntTools.def_static("Length_", (Standard_Real (*)(const TopoDS_Edge &)) &IntTools::Length, "returns the length of the edge;", py::arg("E"));
	cls_IntTools.def_static("RemoveIdenticalRoots_", (void (*)(IntTools_SequenceOfRoots &, const Standard_Real)) &IntTools::RemoveIdenticalRoots, "Remove from the sequence aSeq the Roots that have values ti and tj such as |ti-tj] < anEpsT.", py::arg("aSeq"), py::arg("anEpsT"));
	cls_IntTools.def_static("SortRoots_", (void (*)(IntTools_SequenceOfRoots &, const Standard_Real)) &IntTools::SortRoots, "Sort the sequence aSeq of the Roots to arrange the Roons in increasing order", py::arg("aSeq"), py::arg("anEpsT"));
	cls_IntTools.def_static("FindRootStates_", (void (*)(IntTools_SequenceOfRoots &, const Standard_Real)) &IntTools::FindRootStates, "Find the states (before and after) for each Root from the sequence aSeq", py::arg("aSeq"), py::arg("anEpsNull"));
	cls_IntTools.def_static("Parameter_", (Standard_Integer (*)(const gp_Pnt &, const opencascade::handle<Geom_Curve> &, Standard_Real &)) &IntTools::Parameter, "None", py::arg("P"), py::arg("Curve"), py::arg("aParm"));
	cls_IntTools.def_static("GetRadius_", (Standard_Integer (*)(const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, Standard_Real &)) &IntTools::GetRadius, "None", py::arg("C"), py::arg("t1"), py::arg("t3"), py::arg("R"));
	cls_IntTools.def_static("PrepareArgs_", (Standard_Integer (*)(BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, IntTools_CArray1OfReal &)) &IntTools::PrepareArgs, "None", py::arg("C"), py::arg("tMax"), py::arg("tMin"), py::arg("Discret"), py::arg("Deflect"), py::arg("anArgs"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_WLineTool.hxx
	py::class_<IntTools_WLineTool, std::unique_ptr<IntTools_WLineTool, Deleter<IntTools_WLineTool>>> cls_IntTools_WLineTool(mod, "IntTools_WLineTool", "IntTools_WLineTool provides set of static methods related to walking lines.");
	cls_IntTools_WLineTool.def(py::init<>());
	cls_IntTools_WLineTool.def_static("NotUseSurfacesForApprox_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const opencascade::handle<IntPatch_WLine> &, const Standard_Integer, const Standard_Integer)) &IntTools_WLineTool::NotUseSurfacesForApprox, "None", py::arg("aF1"), py::arg("aF2"), py::arg("WL"), py::arg("ifprm"), py::arg("ilprm"));
	cls_IntTools_WLineTool.def_static("DecompositionOfWLine_", (Standard_Boolean (*)(const opencascade::handle<IntPatch_WLine> &, const opencascade::handle<GeomAdaptor_HSurface> &, const opencascade::handle<GeomAdaptor_HSurface> &, const TopoDS_Face &, const TopoDS_Face &, const GeomInt_LineConstructor &, const Standard_Boolean, const Standard_Real, IntPatch_SequenceOfLine &, Standard_Real &, const opencascade::handle<IntTools_Context> &)) &IntTools_WLineTool::DecompositionOfWLine, "None", py::arg("theWLine"), py::arg("theSurface1"), py::arg("theSurface2"), py::arg("theFace1"), py::arg("theFace2"), py::arg("theLConstructor"), py::arg("theAvoidLConstructor"), py::arg("theTol"), py::arg("theNewLines"), py::arg("theReachedTol3d"), py::arg(""));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntTools_SequenceOfRanges, std::unique_ptr<IntTools_SequenceOfRanges, Deleter<IntTools_SequenceOfRanges>>, NCollection_BaseSequence> cls_IntTools_SequenceOfRanges(mod, "IntTools_SequenceOfRanges", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntTools_SequenceOfRanges.def(py::init<>());
	cls_IntTools_SequenceOfRanges.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntTools_SequenceOfRanges.def(py::init([] (const IntTools_SequenceOfRanges &other) {return new IntTools_SequenceOfRanges(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_SequenceOfRanges.def("begin", (IntTools_SequenceOfRanges::iterator (IntTools_SequenceOfRanges::*)() const ) &IntTools_SequenceOfRanges::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntTools_SequenceOfRanges.def("end", (IntTools_SequenceOfRanges::iterator (IntTools_SequenceOfRanges::*)() const ) &IntTools_SequenceOfRanges::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntTools_SequenceOfRanges.def("cbegin", (IntTools_SequenceOfRanges::const_iterator (IntTools_SequenceOfRanges::*)() const ) &IntTools_SequenceOfRanges::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntTools_SequenceOfRanges.def("cend", (IntTools_SequenceOfRanges::const_iterator (IntTools_SequenceOfRanges::*)() const ) &IntTools_SequenceOfRanges::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntTools_SequenceOfRanges.def("Size", (Standard_Integer (IntTools_SequenceOfRanges::*)() const ) &IntTools_SequenceOfRanges::Size, "Number of items");
	cls_IntTools_SequenceOfRanges.def("Length", (Standard_Integer (IntTools_SequenceOfRanges::*)() const ) &IntTools_SequenceOfRanges::Length, "Number of items");
	cls_IntTools_SequenceOfRanges.def("Lower", (Standard_Integer (IntTools_SequenceOfRanges::*)() const ) &IntTools_SequenceOfRanges::Lower, "Method for consistency with other collections.");
	cls_IntTools_SequenceOfRanges.def("Upper", (Standard_Integer (IntTools_SequenceOfRanges::*)() const ) &IntTools_SequenceOfRanges::Upper, "Method for consistency with other collections.");
	cls_IntTools_SequenceOfRanges.def("IsEmpty", (Standard_Boolean (IntTools_SequenceOfRanges::*)() const ) &IntTools_SequenceOfRanges::IsEmpty, "Empty query");
	cls_IntTools_SequenceOfRanges.def("Reverse", (void (IntTools_SequenceOfRanges::*)()) &IntTools_SequenceOfRanges::Reverse, "Reverse sequence");
	cls_IntTools_SequenceOfRanges.def("Exchange", (void (IntTools_SequenceOfRanges::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SequenceOfRanges::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntTools_SequenceOfRanges.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_SequenceOfRanges::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntTools_SequenceOfRanges.def("Clear", [](IntTools_SequenceOfRanges &self) -> void { return self.Clear(); });
	cls_IntTools_SequenceOfRanges.def("Clear", (void (IntTools_SequenceOfRanges::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_SequenceOfRanges::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntTools_SequenceOfRanges.def("Assign", (IntTools_SequenceOfRanges & (IntTools_SequenceOfRanges::*)(const IntTools_SequenceOfRanges &)) &IntTools_SequenceOfRanges::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_SequenceOfRanges.def("assign", (IntTools_SequenceOfRanges & (IntTools_SequenceOfRanges::*)(const IntTools_SequenceOfRanges &)) &IntTools_SequenceOfRanges::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntTools_SequenceOfRanges.def("Remove", (void (IntTools_SequenceOfRanges::*)(IntTools_SequenceOfRanges::Iterator &)) &IntTools_SequenceOfRanges::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntTools_SequenceOfRanges.def("Remove", (void (IntTools_SequenceOfRanges::*)(const Standard_Integer)) &IntTools_SequenceOfRanges::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntTools_SequenceOfRanges.def("Remove", (void (IntTools_SequenceOfRanges::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SequenceOfRanges::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntTools_SequenceOfRanges.def("Append", (void (IntTools_SequenceOfRanges::*)(const IntTools_Range &)) &IntTools_SequenceOfRanges::Append, "Append one item", py::arg("theItem"));
	cls_IntTools_SequenceOfRanges.def("Append", (void (IntTools_SequenceOfRanges::*)(IntTools_SequenceOfRanges &)) &IntTools_SequenceOfRanges::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntTools_SequenceOfRanges.def("Prepend", (void (IntTools_SequenceOfRanges::*)(const IntTools_Range &)) &IntTools_SequenceOfRanges::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntTools_SequenceOfRanges.def("Prepend", (void (IntTools_SequenceOfRanges::*)(IntTools_SequenceOfRanges &)) &IntTools_SequenceOfRanges::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntTools_SequenceOfRanges.def("InsertBefore", (void (IntTools_SequenceOfRanges::*)(const Standard_Integer, const IntTools_Range &)) &IntTools_SequenceOfRanges::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfRanges.def("InsertBefore", (void (IntTools_SequenceOfRanges::*)(const Standard_Integer, IntTools_SequenceOfRanges &)) &IntTools_SequenceOfRanges::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfRanges.def("InsertAfter", (void (IntTools_SequenceOfRanges::*)(IntTools_SequenceOfRanges::Iterator &, const IntTools_Range &)) &IntTools_SequenceOfRanges::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntTools_SequenceOfRanges.def("InsertAfter", (void (IntTools_SequenceOfRanges::*)(const Standard_Integer, IntTools_SequenceOfRanges &)) &IntTools_SequenceOfRanges::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfRanges.def("InsertAfter", (void (IntTools_SequenceOfRanges::*)(const Standard_Integer, const IntTools_Range &)) &IntTools_SequenceOfRanges::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfRanges.def("Split", (void (IntTools_SequenceOfRanges::*)(const Standard_Integer, IntTools_SequenceOfRanges &)) &IntTools_SequenceOfRanges::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfRanges.def("First", (const IntTools_Range & (IntTools_SequenceOfRanges::*)() const ) &IntTools_SequenceOfRanges::First, "First item access");
	cls_IntTools_SequenceOfRanges.def("ChangeFirst", (IntTools_Range & (IntTools_SequenceOfRanges::*)()) &IntTools_SequenceOfRanges::ChangeFirst, "First item access");
	cls_IntTools_SequenceOfRanges.def("Last", (const IntTools_Range & (IntTools_SequenceOfRanges::*)() const ) &IntTools_SequenceOfRanges::Last, "Last item access");
	cls_IntTools_SequenceOfRanges.def("ChangeLast", (IntTools_Range & (IntTools_SequenceOfRanges::*)()) &IntTools_SequenceOfRanges::ChangeLast, "Last item access");
	cls_IntTools_SequenceOfRanges.def("Value", (const IntTools_Range & (IntTools_SequenceOfRanges::*)(const Standard_Integer) const ) &IntTools_SequenceOfRanges::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntTools_SequenceOfRanges.def("__call__", (const IntTools_Range & (IntTools_SequenceOfRanges::*)(const Standard_Integer) const ) &IntTools_SequenceOfRanges::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntTools_SequenceOfRanges.def("ChangeValue", (IntTools_Range & (IntTools_SequenceOfRanges::*)(const Standard_Integer)) &IntTools_SequenceOfRanges::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntTools_SequenceOfRanges.def("__call__", (IntTools_Range & (IntTools_SequenceOfRanges::*)(const Standard_Integer)) &IntTools_SequenceOfRanges::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntTools_SequenceOfRanges.def("SetValue", (void (IntTools_SequenceOfRanges::*)(const Standard_Integer, const IntTools_Range &)) &IntTools_SequenceOfRanges::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfRanges.def("__iter__", [](const IntTools_SequenceOfRanges &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntTools_SequenceOfRoots, std::unique_ptr<IntTools_SequenceOfRoots, Deleter<IntTools_SequenceOfRoots>>, NCollection_BaseSequence> cls_IntTools_SequenceOfRoots(mod, "IntTools_SequenceOfRoots", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntTools_SequenceOfRoots.def(py::init<>());
	cls_IntTools_SequenceOfRoots.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntTools_SequenceOfRoots.def(py::init([] (const IntTools_SequenceOfRoots &other) {return new IntTools_SequenceOfRoots(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_SequenceOfRoots.def("begin", (IntTools_SequenceOfRoots::iterator (IntTools_SequenceOfRoots::*)() const ) &IntTools_SequenceOfRoots::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntTools_SequenceOfRoots.def("end", (IntTools_SequenceOfRoots::iterator (IntTools_SequenceOfRoots::*)() const ) &IntTools_SequenceOfRoots::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntTools_SequenceOfRoots.def("cbegin", (IntTools_SequenceOfRoots::const_iterator (IntTools_SequenceOfRoots::*)() const ) &IntTools_SequenceOfRoots::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntTools_SequenceOfRoots.def("cend", (IntTools_SequenceOfRoots::const_iterator (IntTools_SequenceOfRoots::*)() const ) &IntTools_SequenceOfRoots::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntTools_SequenceOfRoots.def("Size", (Standard_Integer (IntTools_SequenceOfRoots::*)() const ) &IntTools_SequenceOfRoots::Size, "Number of items");
	cls_IntTools_SequenceOfRoots.def("Length", (Standard_Integer (IntTools_SequenceOfRoots::*)() const ) &IntTools_SequenceOfRoots::Length, "Number of items");
	cls_IntTools_SequenceOfRoots.def("Lower", (Standard_Integer (IntTools_SequenceOfRoots::*)() const ) &IntTools_SequenceOfRoots::Lower, "Method for consistency with other collections.");
	cls_IntTools_SequenceOfRoots.def("Upper", (Standard_Integer (IntTools_SequenceOfRoots::*)() const ) &IntTools_SequenceOfRoots::Upper, "Method for consistency with other collections.");
	cls_IntTools_SequenceOfRoots.def("IsEmpty", (Standard_Boolean (IntTools_SequenceOfRoots::*)() const ) &IntTools_SequenceOfRoots::IsEmpty, "Empty query");
	cls_IntTools_SequenceOfRoots.def("Reverse", (void (IntTools_SequenceOfRoots::*)()) &IntTools_SequenceOfRoots::Reverse, "Reverse sequence");
	cls_IntTools_SequenceOfRoots.def("Exchange", (void (IntTools_SequenceOfRoots::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SequenceOfRoots::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntTools_SequenceOfRoots.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_SequenceOfRoots::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntTools_SequenceOfRoots.def("Clear", [](IntTools_SequenceOfRoots &self) -> void { return self.Clear(); });
	cls_IntTools_SequenceOfRoots.def("Clear", (void (IntTools_SequenceOfRoots::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_SequenceOfRoots::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntTools_SequenceOfRoots.def("Assign", (IntTools_SequenceOfRoots & (IntTools_SequenceOfRoots::*)(const IntTools_SequenceOfRoots &)) &IntTools_SequenceOfRoots::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_SequenceOfRoots.def("assign", (IntTools_SequenceOfRoots & (IntTools_SequenceOfRoots::*)(const IntTools_SequenceOfRoots &)) &IntTools_SequenceOfRoots::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntTools_SequenceOfRoots.def("Remove", (void (IntTools_SequenceOfRoots::*)(IntTools_SequenceOfRoots::Iterator &)) &IntTools_SequenceOfRoots::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntTools_SequenceOfRoots.def("Remove", (void (IntTools_SequenceOfRoots::*)(const Standard_Integer)) &IntTools_SequenceOfRoots::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntTools_SequenceOfRoots.def("Remove", (void (IntTools_SequenceOfRoots::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SequenceOfRoots::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntTools_SequenceOfRoots.def("Append", (void (IntTools_SequenceOfRoots::*)(const IntTools_Root &)) &IntTools_SequenceOfRoots::Append, "Append one item", py::arg("theItem"));
	cls_IntTools_SequenceOfRoots.def("Append", (void (IntTools_SequenceOfRoots::*)(IntTools_SequenceOfRoots &)) &IntTools_SequenceOfRoots::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntTools_SequenceOfRoots.def("Prepend", (void (IntTools_SequenceOfRoots::*)(const IntTools_Root &)) &IntTools_SequenceOfRoots::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntTools_SequenceOfRoots.def("Prepend", (void (IntTools_SequenceOfRoots::*)(IntTools_SequenceOfRoots &)) &IntTools_SequenceOfRoots::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntTools_SequenceOfRoots.def("InsertBefore", (void (IntTools_SequenceOfRoots::*)(const Standard_Integer, const IntTools_Root &)) &IntTools_SequenceOfRoots::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfRoots.def("InsertBefore", (void (IntTools_SequenceOfRoots::*)(const Standard_Integer, IntTools_SequenceOfRoots &)) &IntTools_SequenceOfRoots::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfRoots.def("InsertAfter", (void (IntTools_SequenceOfRoots::*)(IntTools_SequenceOfRoots::Iterator &, const IntTools_Root &)) &IntTools_SequenceOfRoots::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntTools_SequenceOfRoots.def("InsertAfter", (void (IntTools_SequenceOfRoots::*)(const Standard_Integer, IntTools_SequenceOfRoots &)) &IntTools_SequenceOfRoots::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfRoots.def("InsertAfter", (void (IntTools_SequenceOfRoots::*)(const Standard_Integer, const IntTools_Root &)) &IntTools_SequenceOfRoots::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfRoots.def("Split", (void (IntTools_SequenceOfRoots::*)(const Standard_Integer, IntTools_SequenceOfRoots &)) &IntTools_SequenceOfRoots::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfRoots.def("First", (const IntTools_Root & (IntTools_SequenceOfRoots::*)() const ) &IntTools_SequenceOfRoots::First, "First item access");
	cls_IntTools_SequenceOfRoots.def("ChangeFirst", (IntTools_Root & (IntTools_SequenceOfRoots::*)()) &IntTools_SequenceOfRoots::ChangeFirst, "First item access");
	cls_IntTools_SequenceOfRoots.def("Last", (const IntTools_Root & (IntTools_SequenceOfRoots::*)() const ) &IntTools_SequenceOfRoots::Last, "Last item access");
	cls_IntTools_SequenceOfRoots.def("ChangeLast", (IntTools_Root & (IntTools_SequenceOfRoots::*)()) &IntTools_SequenceOfRoots::ChangeLast, "Last item access");
	cls_IntTools_SequenceOfRoots.def("Value", (const IntTools_Root & (IntTools_SequenceOfRoots::*)(const Standard_Integer) const ) &IntTools_SequenceOfRoots::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntTools_SequenceOfRoots.def("__call__", (const IntTools_Root & (IntTools_SequenceOfRoots::*)(const Standard_Integer) const ) &IntTools_SequenceOfRoots::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntTools_SequenceOfRoots.def("ChangeValue", (IntTools_Root & (IntTools_SequenceOfRoots::*)(const Standard_Integer)) &IntTools_SequenceOfRoots::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntTools_SequenceOfRoots.def("__call__", (IntTools_Root & (IntTools_SequenceOfRoots::*)(const Standard_Integer)) &IntTools_SequenceOfRoots::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntTools_SequenceOfRoots.def("SetValue", (void (IntTools_SequenceOfRoots::*)(const Standard_Integer, const IntTools_Root &)) &IntTools_SequenceOfRoots::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfRoots.def("__iter__", [](const IntTools_SequenceOfRoots &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<IntTools_Array1OfRange, std::unique_ptr<IntTools_Array1OfRange, Deleter<IntTools_Array1OfRange>>> cls_IntTools_Array1OfRange(mod, "IntTools_Array1OfRange", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_IntTools_Array1OfRange.def(py::init<>());
	cls_IntTools_Array1OfRange.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IntTools_Array1OfRange.def(py::init([] (const IntTools_Array1OfRange &other) {return new IntTools_Array1OfRange(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_IntTools_Array1OfRange.def(py::init<IntTools_Array1OfRange &&>(), py::arg("theOther"));
	cls_IntTools_Array1OfRange.def(py::init<const IntTools_Range &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_IntTools_Array1OfRange.def("begin", (IntTools_Array1OfRange::iterator (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::begin, "Returns an iterator pointing to the first element in the array.");
	cls_IntTools_Array1OfRange.def("end", (IntTools_Array1OfRange::iterator (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_IntTools_Array1OfRange.def("cbegin", (IntTools_Array1OfRange::const_iterator (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_IntTools_Array1OfRange.def("cend", (IntTools_Array1OfRange::const_iterator (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_IntTools_Array1OfRange.def("Init", (void (IntTools_Array1OfRange::*)(const IntTools_Range &)) &IntTools_Array1OfRange::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_IntTools_Array1OfRange.def("Size", (Standard_Integer (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::Size, "Size query");
	cls_IntTools_Array1OfRange.def("Length", (Standard_Integer (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::Length, "Length query (the same)");
	cls_IntTools_Array1OfRange.def("IsEmpty", (Standard_Boolean (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::IsEmpty, "Return TRUE if array has zero length.");
	cls_IntTools_Array1OfRange.def("Lower", (Standard_Integer (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::Lower, "Lower bound");
	cls_IntTools_Array1OfRange.def("Upper", (Standard_Integer (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::Upper, "Upper bound");
	cls_IntTools_Array1OfRange.def("IsDeletable", (Standard_Boolean (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::IsDeletable, "myDeletable flag");
	cls_IntTools_Array1OfRange.def("IsAllocated", (Standard_Boolean (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_IntTools_Array1OfRange.def("Assign", (IntTools_Array1OfRange & (IntTools_Array1OfRange::*)(const IntTools_Array1OfRange &)) &IntTools_Array1OfRange::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_IntTools_Array1OfRange.def("Move", (IntTools_Array1OfRange & (IntTools_Array1OfRange::*)(IntTools_Array1OfRange &&)) &IntTools_Array1OfRange::Move, "Move assignment", py::arg("theOther"));
	cls_IntTools_Array1OfRange.def("assign", (IntTools_Array1OfRange & (IntTools_Array1OfRange::*)(const IntTools_Array1OfRange &)) &IntTools_Array1OfRange::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_IntTools_Array1OfRange.def("assign", (IntTools_Array1OfRange & (IntTools_Array1OfRange::*)(IntTools_Array1OfRange &&)) &IntTools_Array1OfRange::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_IntTools_Array1OfRange.def("First", (const IntTools_Range & (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::First, "Returns first element");
	cls_IntTools_Array1OfRange.def("ChangeFirst", (IntTools_Range & (IntTools_Array1OfRange::*)()) &IntTools_Array1OfRange::ChangeFirst, "Returns first element");
	cls_IntTools_Array1OfRange.def("Last", (const IntTools_Range & (IntTools_Array1OfRange::*)() const ) &IntTools_Array1OfRange::Last, "Returns last element");
	cls_IntTools_Array1OfRange.def("ChangeLast", (IntTools_Range & (IntTools_Array1OfRange::*)()) &IntTools_Array1OfRange::ChangeLast, "Returns last element");
	cls_IntTools_Array1OfRange.def("Value", (const IntTools_Range & (IntTools_Array1OfRange::*)(const Standard_Integer) const ) &IntTools_Array1OfRange::Value, "Constant value access", py::arg("theIndex"));
	cls_IntTools_Array1OfRange.def("__call__", (const IntTools_Range & (IntTools_Array1OfRange::*)(const Standard_Integer) const ) &IntTools_Array1OfRange::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_IntTools_Array1OfRange.def("ChangeValue", (IntTools_Range & (IntTools_Array1OfRange::*)(const Standard_Integer)) &IntTools_Array1OfRange::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_IntTools_Array1OfRange.def("__call__", (IntTools_Range & (IntTools_Array1OfRange::*)(const Standard_Integer)) &IntTools_Array1OfRange::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_IntTools_Array1OfRange.def("SetValue", (void (IntTools_Array1OfRange::*)(const Standard_Integer, const IntTools_Range &)) &IntTools_Array1OfRange::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_Array1OfRange.def("Resize", (void (IntTools_Array1OfRange::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &IntTools_Array1OfRange::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_IntTools_Array1OfRange.def("__iter__", [](const IntTools_Array1OfRange &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<IntTools_Array1OfRoots, std::unique_ptr<IntTools_Array1OfRoots, Deleter<IntTools_Array1OfRoots>>> cls_IntTools_Array1OfRoots(mod, "IntTools_Array1OfRoots", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_IntTools_Array1OfRoots.def(py::init<>());
	cls_IntTools_Array1OfRoots.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IntTools_Array1OfRoots.def(py::init([] (const IntTools_Array1OfRoots &other) {return new IntTools_Array1OfRoots(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_IntTools_Array1OfRoots.def(py::init<IntTools_Array1OfRoots &&>(), py::arg("theOther"));
	cls_IntTools_Array1OfRoots.def(py::init<const IntTools_Root &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_IntTools_Array1OfRoots.def("begin", (IntTools_Array1OfRoots::iterator (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::begin, "Returns an iterator pointing to the first element in the array.");
	cls_IntTools_Array1OfRoots.def("end", (IntTools_Array1OfRoots::iterator (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_IntTools_Array1OfRoots.def("cbegin", (IntTools_Array1OfRoots::const_iterator (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_IntTools_Array1OfRoots.def("cend", (IntTools_Array1OfRoots::const_iterator (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_IntTools_Array1OfRoots.def("Init", (void (IntTools_Array1OfRoots::*)(const IntTools_Root &)) &IntTools_Array1OfRoots::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_IntTools_Array1OfRoots.def("Size", (Standard_Integer (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::Size, "Size query");
	cls_IntTools_Array1OfRoots.def("Length", (Standard_Integer (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::Length, "Length query (the same)");
	cls_IntTools_Array1OfRoots.def("IsEmpty", (Standard_Boolean (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::IsEmpty, "Return TRUE if array has zero length.");
	cls_IntTools_Array1OfRoots.def("Lower", (Standard_Integer (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::Lower, "Lower bound");
	cls_IntTools_Array1OfRoots.def("Upper", (Standard_Integer (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::Upper, "Upper bound");
	cls_IntTools_Array1OfRoots.def("IsDeletable", (Standard_Boolean (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::IsDeletable, "myDeletable flag");
	cls_IntTools_Array1OfRoots.def("IsAllocated", (Standard_Boolean (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_IntTools_Array1OfRoots.def("Assign", (IntTools_Array1OfRoots & (IntTools_Array1OfRoots::*)(const IntTools_Array1OfRoots &)) &IntTools_Array1OfRoots::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_IntTools_Array1OfRoots.def("Move", (IntTools_Array1OfRoots & (IntTools_Array1OfRoots::*)(IntTools_Array1OfRoots &&)) &IntTools_Array1OfRoots::Move, "Move assignment", py::arg("theOther"));
	cls_IntTools_Array1OfRoots.def("assign", (IntTools_Array1OfRoots & (IntTools_Array1OfRoots::*)(const IntTools_Array1OfRoots &)) &IntTools_Array1OfRoots::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_IntTools_Array1OfRoots.def("assign", (IntTools_Array1OfRoots & (IntTools_Array1OfRoots::*)(IntTools_Array1OfRoots &&)) &IntTools_Array1OfRoots::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_IntTools_Array1OfRoots.def("First", (const IntTools_Root & (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::First, "Returns first element");
	cls_IntTools_Array1OfRoots.def("ChangeFirst", (IntTools_Root & (IntTools_Array1OfRoots::*)()) &IntTools_Array1OfRoots::ChangeFirst, "Returns first element");
	cls_IntTools_Array1OfRoots.def("Last", (const IntTools_Root & (IntTools_Array1OfRoots::*)() const ) &IntTools_Array1OfRoots::Last, "Returns last element");
	cls_IntTools_Array1OfRoots.def("ChangeLast", (IntTools_Root & (IntTools_Array1OfRoots::*)()) &IntTools_Array1OfRoots::ChangeLast, "Returns last element");
	cls_IntTools_Array1OfRoots.def("Value", (const IntTools_Root & (IntTools_Array1OfRoots::*)(const Standard_Integer) const ) &IntTools_Array1OfRoots::Value, "Constant value access", py::arg("theIndex"));
	cls_IntTools_Array1OfRoots.def("__call__", (const IntTools_Root & (IntTools_Array1OfRoots::*)(const Standard_Integer) const ) &IntTools_Array1OfRoots::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_IntTools_Array1OfRoots.def("ChangeValue", (IntTools_Root & (IntTools_Array1OfRoots::*)(const Standard_Integer)) &IntTools_Array1OfRoots::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_IntTools_Array1OfRoots.def("__call__", (IntTools_Root & (IntTools_Array1OfRoots::*)(const Standard_Integer)) &IntTools_Array1OfRoots::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_IntTools_Array1OfRoots.def("SetValue", (void (IntTools_Array1OfRoots::*)(const Standard_Integer, const IntTools_Root &)) &IntTools_Array1OfRoots::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_Array1OfRoots.def("Resize", (void (IntTools_Array1OfRoots::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &IntTools_Array1OfRoots::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_IntTools_Array1OfRoots.def("__iter__", [](const IntTools_Array1OfRoots &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<IntTools_ListOfCurveRangeSample, std::unique_ptr<IntTools_ListOfCurveRangeSample, Deleter<IntTools_ListOfCurveRangeSample>>, NCollection_BaseList> cls_IntTools_ListOfCurveRangeSample(mod, "IntTools_ListOfCurveRangeSample", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_IntTools_ListOfCurveRangeSample.def(py::init<>());
	cls_IntTools_ListOfCurveRangeSample.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntTools_ListOfCurveRangeSample.def(py::init([] (const IntTools_ListOfCurveRangeSample &other) {return new IntTools_ListOfCurveRangeSample(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_ListOfCurveRangeSample.def("begin", (IntTools_ListOfCurveRangeSample::iterator (IntTools_ListOfCurveRangeSample::*)() const ) &IntTools_ListOfCurveRangeSample::begin, "Returns an iterator pointing to the first element in the list.");
	cls_IntTools_ListOfCurveRangeSample.def("end", (IntTools_ListOfCurveRangeSample::iterator (IntTools_ListOfCurveRangeSample::*)() const ) &IntTools_ListOfCurveRangeSample::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_IntTools_ListOfCurveRangeSample.def("cbegin", (IntTools_ListOfCurveRangeSample::const_iterator (IntTools_ListOfCurveRangeSample::*)() const ) &IntTools_ListOfCurveRangeSample::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_IntTools_ListOfCurveRangeSample.def("cend", (IntTools_ListOfCurveRangeSample::const_iterator (IntTools_ListOfCurveRangeSample::*)() const ) &IntTools_ListOfCurveRangeSample::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_IntTools_ListOfCurveRangeSample.def("Size", (Standard_Integer (IntTools_ListOfCurveRangeSample::*)() const ) &IntTools_ListOfCurveRangeSample::Size, "Size - Number of items");
	cls_IntTools_ListOfCurveRangeSample.def("Assign", (IntTools_ListOfCurveRangeSample & (IntTools_ListOfCurveRangeSample::*)(const IntTools_ListOfCurveRangeSample &)) &IntTools_ListOfCurveRangeSample::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_ListOfCurveRangeSample.def("assign", (IntTools_ListOfCurveRangeSample & (IntTools_ListOfCurveRangeSample::*)(const IntTools_ListOfCurveRangeSample &)) &IntTools_ListOfCurveRangeSample::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntTools_ListOfCurveRangeSample.def("Clear", [](IntTools_ListOfCurveRangeSample &self) -> void { return self.Clear(); });
	cls_IntTools_ListOfCurveRangeSample.def("Clear", (void (IntTools_ListOfCurveRangeSample::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_ListOfCurveRangeSample::Clear, "Clear this list", py::arg("theAllocator"));
	cls_IntTools_ListOfCurveRangeSample.def("First", (const IntTools_CurveRangeSample & (IntTools_ListOfCurveRangeSample::*)() const ) &IntTools_ListOfCurveRangeSample::First, "First item");
	cls_IntTools_ListOfCurveRangeSample.def("First", (IntTools_CurveRangeSample & (IntTools_ListOfCurveRangeSample::*)()) &IntTools_ListOfCurveRangeSample::First, "First item (non-const)");
	cls_IntTools_ListOfCurveRangeSample.def("Last", (const IntTools_CurveRangeSample & (IntTools_ListOfCurveRangeSample::*)() const ) &IntTools_ListOfCurveRangeSample::Last, "Last item");
	cls_IntTools_ListOfCurveRangeSample.def("Last", (IntTools_CurveRangeSample & (IntTools_ListOfCurveRangeSample::*)()) &IntTools_ListOfCurveRangeSample::Last, "Last item (non-const)");
	cls_IntTools_ListOfCurveRangeSample.def("Append", (IntTools_CurveRangeSample & (IntTools_ListOfCurveRangeSample::*)(const IntTools_CurveRangeSample &)) &IntTools_ListOfCurveRangeSample::Append, "Append one item at the end", py::arg("theItem"));
	cls_IntTools_ListOfCurveRangeSample.def("Append", (void (IntTools_ListOfCurveRangeSample::*)(const IntTools_CurveRangeSample &, IntTools_ListOfCurveRangeSample::Iterator &)) &IntTools_ListOfCurveRangeSample::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_IntTools_ListOfCurveRangeSample.def("Append", (void (IntTools_ListOfCurveRangeSample::*)(IntTools_ListOfCurveRangeSample &)) &IntTools_ListOfCurveRangeSample::Append, "Append another list at the end", py::arg("theOther"));
	cls_IntTools_ListOfCurveRangeSample.def("Prepend", (IntTools_CurveRangeSample & (IntTools_ListOfCurveRangeSample::*)(const IntTools_CurveRangeSample &)) &IntTools_ListOfCurveRangeSample::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_IntTools_ListOfCurveRangeSample.def("Prepend", (void (IntTools_ListOfCurveRangeSample::*)(IntTools_ListOfCurveRangeSample &)) &IntTools_ListOfCurveRangeSample::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_IntTools_ListOfCurveRangeSample.def("RemoveFirst", (void (IntTools_ListOfCurveRangeSample::*)()) &IntTools_ListOfCurveRangeSample::RemoveFirst, "RemoveFirst item");
	cls_IntTools_ListOfCurveRangeSample.def("Remove", (void (IntTools_ListOfCurveRangeSample::*)(IntTools_ListOfCurveRangeSample::Iterator &)) &IntTools_ListOfCurveRangeSample::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_IntTools_ListOfCurveRangeSample.def("InsertBefore", (IntTools_CurveRangeSample & (IntTools_ListOfCurveRangeSample::*)(const IntTools_CurveRangeSample &, IntTools_ListOfCurveRangeSample::Iterator &)) &IntTools_ListOfCurveRangeSample::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_IntTools_ListOfCurveRangeSample.def("InsertBefore", (void (IntTools_ListOfCurveRangeSample::*)(IntTools_ListOfCurveRangeSample &, IntTools_ListOfCurveRangeSample::Iterator &)) &IntTools_ListOfCurveRangeSample::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_IntTools_ListOfCurveRangeSample.def("InsertAfter", (IntTools_CurveRangeSample & (IntTools_ListOfCurveRangeSample::*)(const IntTools_CurveRangeSample &, IntTools_ListOfCurveRangeSample::Iterator &)) &IntTools_ListOfCurveRangeSample::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_IntTools_ListOfCurveRangeSample.def("InsertAfter", (void (IntTools_ListOfCurveRangeSample::*)(IntTools_ListOfCurveRangeSample &, IntTools_ListOfCurveRangeSample::Iterator &)) &IntTools_ListOfCurveRangeSample::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_IntTools_ListOfCurveRangeSample.def("Reverse", (void (IntTools_ListOfCurveRangeSample::*)()) &IntTools_ListOfCurveRangeSample::Reverse, "Reverse the list");
	cls_IntTools_ListOfCurveRangeSample.def("__iter__", [](const IntTools_ListOfCurveRangeSample &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<IntTools_ListIteratorOfListOfCurveRangeSample, std::unique_ptr<IntTools_ListIteratorOfListOfCurveRangeSample, Deleter<IntTools_ListIteratorOfListOfCurveRangeSample>>> cls_IntTools_ListIteratorOfListOfCurveRangeSample(mod, "IntTools_ListIteratorOfListOfCurveRangeSample", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_IntTools_ListIteratorOfListOfCurveRangeSample.def(py::init<>());
	cls_IntTools_ListIteratorOfListOfCurveRangeSample.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_IntTools_ListIteratorOfListOfCurveRangeSample.def("More", (Standard_Boolean (IntTools_ListIteratorOfListOfCurveRangeSample::*)() const ) &IntTools_ListIteratorOfListOfCurveRangeSample::More, "Check end");
	cls_IntTools_ListIteratorOfListOfCurveRangeSample.def("Next", (void (IntTools_ListIteratorOfListOfCurveRangeSample::*)()) &IntTools_ListIteratorOfListOfCurveRangeSample::Next, "Make step");
	cls_IntTools_ListIteratorOfListOfCurveRangeSample.def("Value", (const IntTools_CurveRangeSample & (IntTools_ListIteratorOfListOfCurveRangeSample::*)() const ) &IntTools_ListIteratorOfListOfCurveRangeSample::Value, "Constant Value access");
	cls_IntTools_ListIteratorOfListOfCurveRangeSample.def("Value", (IntTools_CurveRangeSample & (IntTools_ListIteratorOfListOfCurveRangeSample::*)()) &IntTools_ListIteratorOfListOfCurveRangeSample::Value, "Non-const Value access");
	cls_IntTools_ListIteratorOfListOfCurveRangeSample.def("ChangeValue", (IntTools_CurveRangeSample & (IntTools_ListIteratorOfListOfCurveRangeSample::*)() const ) &IntTools_ListIteratorOfListOfCurveRangeSample::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<IntTools_ListOfSurfaceRangeSample, std::unique_ptr<IntTools_ListOfSurfaceRangeSample, Deleter<IntTools_ListOfSurfaceRangeSample>>, NCollection_BaseList> cls_IntTools_ListOfSurfaceRangeSample(mod, "IntTools_ListOfSurfaceRangeSample", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_IntTools_ListOfSurfaceRangeSample.def(py::init<>());
	cls_IntTools_ListOfSurfaceRangeSample.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntTools_ListOfSurfaceRangeSample.def(py::init([] (const IntTools_ListOfSurfaceRangeSample &other) {return new IntTools_ListOfSurfaceRangeSample(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_ListOfSurfaceRangeSample.def("begin", (IntTools_ListOfSurfaceRangeSample::iterator (IntTools_ListOfSurfaceRangeSample::*)() const ) &IntTools_ListOfSurfaceRangeSample::begin, "Returns an iterator pointing to the first element in the list.");
	cls_IntTools_ListOfSurfaceRangeSample.def("end", (IntTools_ListOfSurfaceRangeSample::iterator (IntTools_ListOfSurfaceRangeSample::*)() const ) &IntTools_ListOfSurfaceRangeSample::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_IntTools_ListOfSurfaceRangeSample.def("cbegin", (IntTools_ListOfSurfaceRangeSample::const_iterator (IntTools_ListOfSurfaceRangeSample::*)() const ) &IntTools_ListOfSurfaceRangeSample::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_IntTools_ListOfSurfaceRangeSample.def("cend", (IntTools_ListOfSurfaceRangeSample::const_iterator (IntTools_ListOfSurfaceRangeSample::*)() const ) &IntTools_ListOfSurfaceRangeSample::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_IntTools_ListOfSurfaceRangeSample.def("Size", (Standard_Integer (IntTools_ListOfSurfaceRangeSample::*)() const ) &IntTools_ListOfSurfaceRangeSample::Size, "Size - Number of items");
	cls_IntTools_ListOfSurfaceRangeSample.def("Assign", (IntTools_ListOfSurfaceRangeSample & (IntTools_ListOfSurfaceRangeSample::*)(const IntTools_ListOfSurfaceRangeSample &)) &IntTools_ListOfSurfaceRangeSample::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_ListOfSurfaceRangeSample.def("assign", (IntTools_ListOfSurfaceRangeSample & (IntTools_ListOfSurfaceRangeSample::*)(const IntTools_ListOfSurfaceRangeSample &)) &IntTools_ListOfSurfaceRangeSample::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntTools_ListOfSurfaceRangeSample.def("Clear", [](IntTools_ListOfSurfaceRangeSample &self) -> void { return self.Clear(); });
	cls_IntTools_ListOfSurfaceRangeSample.def("Clear", (void (IntTools_ListOfSurfaceRangeSample::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_ListOfSurfaceRangeSample::Clear, "Clear this list", py::arg("theAllocator"));
	cls_IntTools_ListOfSurfaceRangeSample.def("First", (const IntTools_SurfaceRangeSample & (IntTools_ListOfSurfaceRangeSample::*)() const ) &IntTools_ListOfSurfaceRangeSample::First, "First item");
	cls_IntTools_ListOfSurfaceRangeSample.def("First", (IntTools_SurfaceRangeSample & (IntTools_ListOfSurfaceRangeSample::*)()) &IntTools_ListOfSurfaceRangeSample::First, "First item (non-const)");
	cls_IntTools_ListOfSurfaceRangeSample.def("Last", (const IntTools_SurfaceRangeSample & (IntTools_ListOfSurfaceRangeSample::*)() const ) &IntTools_ListOfSurfaceRangeSample::Last, "Last item");
	cls_IntTools_ListOfSurfaceRangeSample.def("Last", (IntTools_SurfaceRangeSample & (IntTools_ListOfSurfaceRangeSample::*)()) &IntTools_ListOfSurfaceRangeSample::Last, "Last item (non-const)");
	cls_IntTools_ListOfSurfaceRangeSample.def("Append", (IntTools_SurfaceRangeSample & (IntTools_ListOfSurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &)) &IntTools_ListOfSurfaceRangeSample::Append, "Append one item at the end", py::arg("theItem"));
	cls_IntTools_ListOfSurfaceRangeSample.def("Append", (void (IntTools_ListOfSurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &, IntTools_ListOfSurfaceRangeSample::Iterator &)) &IntTools_ListOfSurfaceRangeSample::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_IntTools_ListOfSurfaceRangeSample.def("Append", (void (IntTools_ListOfSurfaceRangeSample::*)(IntTools_ListOfSurfaceRangeSample &)) &IntTools_ListOfSurfaceRangeSample::Append, "Append another list at the end", py::arg("theOther"));
	cls_IntTools_ListOfSurfaceRangeSample.def("Prepend", (IntTools_SurfaceRangeSample & (IntTools_ListOfSurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &)) &IntTools_ListOfSurfaceRangeSample::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_IntTools_ListOfSurfaceRangeSample.def("Prepend", (void (IntTools_ListOfSurfaceRangeSample::*)(IntTools_ListOfSurfaceRangeSample &)) &IntTools_ListOfSurfaceRangeSample::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_IntTools_ListOfSurfaceRangeSample.def("RemoveFirst", (void (IntTools_ListOfSurfaceRangeSample::*)()) &IntTools_ListOfSurfaceRangeSample::RemoveFirst, "RemoveFirst item");
	cls_IntTools_ListOfSurfaceRangeSample.def("Remove", (void (IntTools_ListOfSurfaceRangeSample::*)(IntTools_ListOfSurfaceRangeSample::Iterator &)) &IntTools_ListOfSurfaceRangeSample::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_IntTools_ListOfSurfaceRangeSample.def("InsertBefore", (IntTools_SurfaceRangeSample & (IntTools_ListOfSurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &, IntTools_ListOfSurfaceRangeSample::Iterator &)) &IntTools_ListOfSurfaceRangeSample::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_IntTools_ListOfSurfaceRangeSample.def("InsertBefore", (void (IntTools_ListOfSurfaceRangeSample::*)(IntTools_ListOfSurfaceRangeSample &, IntTools_ListOfSurfaceRangeSample::Iterator &)) &IntTools_ListOfSurfaceRangeSample::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_IntTools_ListOfSurfaceRangeSample.def("InsertAfter", (IntTools_SurfaceRangeSample & (IntTools_ListOfSurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &, IntTools_ListOfSurfaceRangeSample::Iterator &)) &IntTools_ListOfSurfaceRangeSample::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_IntTools_ListOfSurfaceRangeSample.def("InsertAfter", (void (IntTools_ListOfSurfaceRangeSample::*)(IntTools_ListOfSurfaceRangeSample &, IntTools_ListOfSurfaceRangeSample::Iterator &)) &IntTools_ListOfSurfaceRangeSample::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_IntTools_ListOfSurfaceRangeSample.def("Reverse", (void (IntTools_ListOfSurfaceRangeSample::*)()) &IntTools_ListOfSurfaceRangeSample::Reverse, "Reverse the list");
	cls_IntTools_ListOfSurfaceRangeSample.def("__iter__", [](const IntTools_ListOfSurfaceRangeSample &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<IntTools_ListIteratorOfListOfSurfaceRangeSample, std::unique_ptr<IntTools_ListIteratorOfListOfSurfaceRangeSample, Deleter<IntTools_ListIteratorOfListOfSurfaceRangeSample>>> cls_IntTools_ListIteratorOfListOfSurfaceRangeSample(mod, "IntTools_ListIteratorOfListOfSurfaceRangeSample", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_IntTools_ListIteratorOfListOfSurfaceRangeSample.def(py::init<>());
	cls_IntTools_ListIteratorOfListOfSurfaceRangeSample.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_IntTools_ListIteratorOfListOfSurfaceRangeSample.def("More", (Standard_Boolean (IntTools_ListIteratorOfListOfSurfaceRangeSample::*)() const ) &IntTools_ListIteratorOfListOfSurfaceRangeSample::More, "Check end");
	cls_IntTools_ListIteratorOfListOfSurfaceRangeSample.def("Next", (void (IntTools_ListIteratorOfListOfSurfaceRangeSample::*)()) &IntTools_ListIteratorOfListOfSurfaceRangeSample::Next, "Make step");
	cls_IntTools_ListIteratorOfListOfSurfaceRangeSample.def("Value", (const IntTools_SurfaceRangeSample & (IntTools_ListIteratorOfListOfSurfaceRangeSample::*)() const ) &IntTools_ListIteratorOfListOfSurfaceRangeSample::Value, "Constant Value access");
	cls_IntTools_ListIteratorOfListOfSurfaceRangeSample.def("Value", (IntTools_SurfaceRangeSample & (IntTools_ListIteratorOfListOfSurfaceRangeSample::*)()) &IntTools_ListIteratorOfListOfSurfaceRangeSample::Value, "Non-const Value access");
	cls_IntTools_ListIteratorOfListOfSurfaceRangeSample.def("ChangeValue", (IntTools_SurfaceRangeSample & (IntTools_ListIteratorOfListOfSurfaceRangeSample::*)() const ) &IntTools_ListIteratorOfListOfSurfaceRangeSample::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<IntTools_MapOfCurveSample, std::unique_ptr<IntTools_MapOfCurveSample, Deleter<IntTools_MapOfCurveSample>>, NCollection_BaseMap> cls_IntTools_MapOfCurveSample(mod, "IntTools_MapOfCurveSample", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_IntTools_MapOfCurveSample.def(py::init<>());
	cls_IntTools_MapOfCurveSample.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_IntTools_MapOfCurveSample.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_IntTools_MapOfCurveSample.def(py::init([] (const IntTools_MapOfCurveSample &other) {return new IntTools_MapOfCurveSample(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_MapOfCurveSample.def("cbegin", (IntTools_MapOfCurveSample::const_iterator (IntTools_MapOfCurveSample::*)() const ) &IntTools_MapOfCurveSample::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_IntTools_MapOfCurveSample.def("cend", (IntTools_MapOfCurveSample::const_iterator (IntTools_MapOfCurveSample::*)() const ) &IntTools_MapOfCurveSample::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_IntTools_MapOfCurveSample.def("Exchange", (void (IntTools_MapOfCurveSample::*)(IntTools_MapOfCurveSample &)) &IntTools_MapOfCurveSample::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_IntTools_MapOfCurveSample.def("Assign", (IntTools_MapOfCurveSample & (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &)) &IntTools_MapOfCurveSample::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_MapOfCurveSample.def("assign", (IntTools_MapOfCurveSample & (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &)) &IntTools_MapOfCurveSample::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_IntTools_MapOfCurveSample.def("ReSize", (void (IntTools_MapOfCurveSample::*)(const Standard_Integer)) &IntTools_MapOfCurveSample::ReSize, "ReSize", py::arg("N"));
	cls_IntTools_MapOfCurveSample.def("Add", (Standard_Boolean (IntTools_MapOfCurveSample::*)(const IntTools_CurveRangeSample &)) &IntTools_MapOfCurveSample::Add, "Add", py::arg("K"));
	cls_IntTools_MapOfCurveSample.def("Added", (const IntTools_CurveRangeSample & (IntTools_MapOfCurveSample::*)(const IntTools_CurveRangeSample &)) &IntTools_MapOfCurveSample::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_IntTools_MapOfCurveSample.def("Contains", (Standard_Boolean (IntTools_MapOfCurveSample::*)(const IntTools_CurveRangeSample &) const ) &IntTools_MapOfCurveSample::Contains, "Contains", py::arg("K"));
	cls_IntTools_MapOfCurveSample.def("Remove", (Standard_Boolean (IntTools_MapOfCurveSample::*)(const IntTools_CurveRangeSample &)) &IntTools_MapOfCurveSample::Remove, "Remove", py::arg("K"));
	cls_IntTools_MapOfCurveSample.def("Clear", [](IntTools_MapOfCurveSample &self) -> void { return self.Clear(); });
	cls_IntTools_MapOfCurveSample.def("Clear", (void (IntTools_MapOfCurveSample::*)(const Standard_Boolean)) &IntTools_MapOfCurveSample::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_IntTools_MapOfCurveSample.def("Clear", (void (IntTools_MapOfCurveSample::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_MapOfCurveSample::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_IntTools_MapOfCurveSample.def("Size", (Standard_Integer (IntTools_MapOfCurveSample::*)() const ) &IntTools_MapOfCurveSample::Size, "Size");
	cls_IntTools_MapOfCurveSample.def("IsEqual", (Standard_Boolean (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &) const ) &IntTools_MapOfCurveSample::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_IntTools_MapOfCurveSample.def("Contains", (Standard_Boolean (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &) const ) &IntTools_MapOfCurveSample::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_IntTools_MapOfCurveSample.def("Union", (void (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &, const IntTools_MapOfCurveSample &)) &IntTools_MapOfCurveSample::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_IntTools_MapOfCurveSample.def("Unite", (Standard_Boolean (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &)) &IntTools_MapOfCurveSample::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_IntTools_MapOfCurveSample.def("HasIntersection", (Standard_Boolean (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &) const ) &IntTools_MapOfCurveSample::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_IntTools_MapOfCurveSample.def("Intersection", (void (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &, const IntTools_MapOfCurveSample &)) &IntTools_MapOfCurveSample::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_IntTools_MapOfCurveSample.def("Intersect", (Standard_Boolean (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &)) &IntTools_MapOfCurveSample::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_IntTools_MapOfCurveSample.def("Subtraction", (void (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &, const IntTools_MapOfCurveSample &)) &IntTools_MapOfCurveSample::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_IntTools_MapOfCurveSample.def("Subtract", (Standard_Boolean (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &)) &IntTools_MapOfCurveSample::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_IntTools_MapOfCurveSample.def("Difference", (void (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &, const IntTools_MapOfCurveSample &)) &IntTools_MapOfCurveSample::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_IntTools_MapOfCurveSample.def("Differ", (Standard_Boolean (IntTools_MapOfCurveSample::*)(const IntTools_MapOfCurveSample &)) &IntTools_MapOfCurveSample::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_MapOfCurveSample.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<IntTools_DataMapOfCurveSampleBox, std::unique_ptr<IntTools_DataMapOfCurveSampleBox, Deleter<IntTools_DataMapOfCurveSampleBox>>, NCollection_BaseMap> cls_IntTools_DataMapOfCurveSampleBox(mod, "IntTools_DataMapOfCurveSampleBox", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_IntTools_DataMapOfCurveSampleBox.def(py::init<>());
	cls_IntTools_DataMapOfCurveSampleBox.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_IntTools_DataMapOfCurveSampleBox.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_IntTools_DataMapOfCurveSampleBox.def(py::init([] (const IntTools_DataMapOfCurveSampleBox &other) {return new IntTools_DataMapOfCurveSampleBox(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_DataMapOfCurveSampleBox.def("begin", (IntTools_DataMapOfCurveSampleBox::iterator (IntTools_DataMapOfCurveSampleBox::*)() const ) &IntTools_DataMapOfCurveSampleBox::begin, "Returns an iterator pointing to the first element in the map.");
	cls_IntTools_DataMapOfCurveSampleBox.def("end", (IntTools_DataMapOfCurveSampleBox::iterator (IntTools_DataMapOfCurveSampleBox::*)() const ) &IntTools_DataMapOfCurveSampleBox::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_IntTools_DataMapOfCurveSampleBox.def("cbegin", (IntTools_DataMapOfCurveSampleBox::const_iterator (IntTools_DataMapOfCurveSampleBox::*)() const ) &IntTools_DataMapOfCurveSampleBox::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_IntTools_DataMapOfCurveSampleBox.def("cend", (IntTools_DataMapOfCurveSampleBox::const_iterator (IntTools_DataMapOfCurveSampleBox::*)() const ) &IntTools_DataMapOfCurveSampleBox::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_IntTools_DataMapOfCurveSampleBox.def("Exchange", (void (IntTools_DataMapOfCurveSampleBox::*)(IntTools_DataMapOfCurveSampleBox &)) &IntTools_DataMapOfCurveSampleBox::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_IntTools_DataMapOfCurveSampleBox.def("Assign", (IntTools_DataMapOfCurveSampleBox & (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_DataMapOfCurveSampleBox &)) &IntTools_DataMapOfCurveSampleBox::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_DataMapOfCurveSampleBox.def("assign", (IntTools_DataMapOfCurveSampleBox & (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_DataMapOfCurveSampleBox &)) &IntTools_DataMapOfCurveSampleBox::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_IntTools_DataMapOfCurveSampleBox.def("ReSize", (void (IntTools_DataMapOfCurveSampleBox::*)(const Standard_Integer)) &IntTools_DataMapOfCurveSampleBox::ReSize, "ReSize", py::arg("N"));
	cls_IntTools_DataMapOfCurveSampleBox.def("Bind", (Standard_Boolean (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_CurveRangeSample &, const Bnd_Box &)) &IntTools_DataMapOfCurveSampleBox::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_IntTools_DataMapOfCurveSampleBox.def("Bound", (Bnd_Box * (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_CurveRangeSample &, const Bnd_Box &)) &IntTools_DataMapOfCurveSampleBox::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_IntTools_DataMapOfCurveSampleBox.def("IsBound", (Standard_Boolean (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_CurveRangeSample &) const ) &IntTools_DataMapOfCurveSampleBox::IsBound, "IsBound", py::arg("theKey"));
	cls_IntTools_DataMapOfCurveSampleBox.def("UnBind", (Standard_Boolean (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_CurveRangeSample &)) &IntTools_DataMapOfCurveSampleBox::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_IntTools_DataMapOfCurveSampleBox.def("Seek", (const Bnd_Box * (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_CurveRangeSample &) const ) &IntTools_DataMapOfCurveSampleBox::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_IntTools_DataMapOfCurveSampleBox.def("Find", (const Bnd_Box & (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_CurveRangeSample &) const ) &IntTools_DataMapOfCurveSampleBox::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_IntTools_DataMapOfCurveSampleBox.def("Find", (Standard_Boolean (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_CurveRangeSample &, Bnd_Box &) const ) &IntTools_DataMapOfCurveSampleBox::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_IntTools_DataMapOfCurveSampleBox.def("__call__", (const Bnd_Box & (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_CurveRangeSample &) const ) &IntTools_DataMapOfCurveSampleBox::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_IntTools_DataMapOfCurveSampleBox.def("ChangeSeek", (Bnd_Box * (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_CurveRangeSample &)) &IntTools_DataMapOfCurveSampleBox::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_IntTools_DataMapOfCurveSampleBox.def("ChangeFind", (Bnd_Box & (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_CurveRangeSample &)) &IntTools_DataMapOfCurveSampleBox::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_IntTools_DataMapOfCurveSampleBox.def("__call__", (Bnd_Box & (IntTools_DataMapOfCurveSampleBox::*)(const IntTools_CurveRangeSample &)) &IntTools_DataMapOfCurveSampleBox::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_IntTools_DataMapOfCurveSampleBox.def("Clear", [](IntTools_DataMapOfCurveSampleBox &self) -> void { return self.Clear(); });
	cls_IntTools_DataMapOfCurveSampleBox.def("Clear", (void (IntTools_DataMapOfCurveSampleBox::*)(const Standard_Boolean)) &IntTools_DataMapOfCurveSampleBox::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_IntTools_DataMapOfCurveSampleBox.def("Clear", (void (IntTools_DataMapOfCurveSampleBox::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_DataMapOfCurveSampleBox::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_IntTools_DataMapOfCurveSampleBox.def("Size", (Standard_Integer (IntTools_DataMapOfCurveSampleBox::*)() const ) &IntTools_DataMapOfCurveSampleBox::Size, "Size");
	cls_IntTools_DataMapOfCurveSampleBox.def("__iter__", [](const IntTools_DataMapOfCurveSampleBox &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_DataMapOfCurveSampleBox.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<IntTools_DataMapOfSurfaceSampleBox, std::unique_ptr<IntTools_DataMapOfSurfaceSampleBox, Deleter<IntTools_DataMapOfSurfaceSampleBox>>, NCollection_BaseMap> cls_IntTools_DataMapOfSurfaceSampleBox(mod, "IntTools_DataMapOfSurfaceSampleBox", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_IntTools_DataMapOfSurfaceSampleBox.def(py::init<>());
	cls_IntTools_DataMapOfSurfaceSampleBox.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def(py::init([] (const IntTools_DataMapOfSurfaceSampleBox &other) {return new IntTools_DataMapOfSurfaceSampleBox(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("begin", (IntTools_DataMapOfSurfaceSampleBox::iterator (IntTools_DataMapOfSurfaceSampleBox::*)() const ) &IntTools_DataMapOfSurfaceSampleBox::begin, "Returns an iterator pointing to the first element in the map.");
	cls_IntTools_DataMapOfSurfaceSampleBox.def("end", (IntTools_DataMapOfSurfaceSampleBox::iterator (IntTools_DataMapOfSurfaceSampleBox::*)() const ) &IntTools_DataMapOfSurfaceSampleBox::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_IntTools_DataMapOfSurfaceSampleBox.def("cbegin", (IntTools_DataMapOfSurfaceSampleBox::const_iterator (IntTools_DataMapOfSurfaceSampleBox::*)() const ) &IntTools_DataMapOfSurfaceSampleBox::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_IntTools_DataMapOfSurfaceSampleBox.def("cend", (IntTools_DataMapOfSurfaceSampleBox::const_iterator (IntTools_DataMapOfSurfaceSampleBox::*)() const ) &IntTools_DataMapOfSurfaceSampleBox::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_IntTools_DataMapOfSurfaceSampleBox.def("Exchange", (void (IntTools_DataMapOfSurfaceSampleBox::*)(IntTools_DataMapOfSurfaceSampleBox &)) &IntTools_DataMapOfSurfaceSampleBox::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("Assign", (IntTools_DataMapOfSurfaceSampleBox & (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_DataMapOfSurfaceSampleBox &)) &IntTools_DataMapOfSurfaceSampleBox::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("assign", (IntTools_DataMapOfSurfaceSampleBox & (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_DataMapOfSurfaceSampleBox &)) &IntTools_DataMapOfSurfaceSampleBox::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("ReSize", (void (IntTools_DataMapOfSurfaceSampleBox::*)(const Standard_Integer)) &IntTools_DataMapOfSurfaceSampleBox::ReSize, "ReSize", py::arg("N"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("Bind", (Standard_Boolean (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_SurfaceRangeSample &, const Bnd_Box &)) &IntTools_DataMapOfSurfaceSampleBox::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_IntTools_DataMapOfSurfaceSampleBox.def("Bound", (Bnd_Box * (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_SurfaceRangeSample &, const Bnd_Box &)) &IntTools_DataMapOfSurfaceSampleBox::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("IsBound", (Standard_Boolean (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_SurfaceRangeSample &) const ) &IntTools_DataMapOfSurfaceSampleBox::IsBound, "IsBound", py::arg("theKey"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("UnBind", (Standard_Boolean (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_SurfaceRangeSample &)) &IntTools_DataMapOfSurfaceSampleBox::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_IntTools_DataMapOfSurfaceSampleBox.def("Seek", (const Bnd_Box * (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_SurfaceRangeSample &) const ) &IntTools_DataMapOfSurfaceSampleBox::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_IntTools_DataMapOfSurfaceSampleBox.def("Find", (const Bnd_Box & (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_SurfaceRangeSample &) const ) &IntTools_DataMapOfSurfaceSampleBox::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_IntTools_DataMapOfSurfaceSampleBox.def("Find", (Standard_Boolean (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_SurfaceRangeSample &, Bnd_Box &) const ) &IntTools_DataMapOfSurfaceSampleBox::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("__call__", (const Bnd_Box & (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_SurfaceRangeSample &) const ) &IntTools_DataMapOfSurfaceSampleBox::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_IntTools_DataMapOfSurfaceSampleBox.def("ChangeSeek", (Bnd_Box * (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_SurfaceRangeSample &)) &IntTools_DataMapOfSurfaceSampleBox::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("ChangeFind", (Bnd_Box & (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_SurfaceRangeSample &)) &IntTools_DataMapOfSurfaceSampleBox::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("__call__", (Bnd_Box & (IntTools_DataMapOfSurfaceSampleBox::*)(const IntTools_SurfaceRangeSample &)) &IntTools_DataMapOfSurfaceSampleBox::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("Clear", [](IntTools_DataMapOfSurfaceSampleBox &self) -> void { return self.Clear(); });
	cls_IntTools_DataMapOfSurfaceSampleBox.def("Clear", (void (IntTools_DataMapOfSurfaceSampleBox::*)(const Standard_Boolean)) &IntTools_DataMapOfSurfaceSampleBox::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("Clear", (void (IntTools_DataMapOfSurfaceSampleBox::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_DataMapOfSurfaceSampleBox::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_IntTools_DataMapOfSurfaceSampleBox.def("Size", (Standard_Integer (IntTools_DataMapOfSurfaceSampleBox::*)() const ) &IntTools_DataMapOfSurfaceSampleBox::Size, "Size");
	cls_IntTools_DataMapOfSurfaceSampleBox.def("__iter__", [](const IntTools_DataMapOfSurfaceSampleBox &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_DataMapOfSurfaceSampleBox.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntTools_SequenceOfCommonPrts, std::unique_ptr<IntTools_SequenceOfCommonPrts, Deleter<IntTools_SequenceOfCommonPrts>>, NCollection_BaseSequence> cls_IntTools_SequenceOfCommonPrts(mod, "IntTools_SequenceOfCommonPrts", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntTools_SequenceOfCommonPrts.def(py::init<>());
	cls_IntTools_SequenceOfCommonPrts.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntTools_SequenceOfCommonPrts.def(py::init([] (const IntTools_SequenceOfCommonPrts &other) {return new IntTools_SequenceOfCommonPrts(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_SequenceOfCommonPrts.def("begin", (IntTools_SequenceOfCommonPrts::iterator (IntTools_SequenceOfCommonPrts::*)() const ) &IntTools_SequenceOfCommonPrts::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntTools_SequenceOfCommonPrts.def("end", (IntTools_SequenceOfCommonPrts::iterator (IntTools_SequenceOfCommonPrts::*)() const ) &IntTools_SequenceOfCommonPrts::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntTools_SequenceOfCommonPrts.def("cbegin", (IntTools_SequenceOfCommonPrts::const_iterator (IntTools_SequenceOfCommonPrts::*)() const ) &IntTools_SequenceOfCommonPrts::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntTools_SequenceOfCommonPrts.def("cend", (IntTools_SequenceOfCommonPrts::const_iterator (IntTools_SequenceOfCommonPrts::*)() const ) &IntTools_SequenceOfCommonPrts::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntTools_SequenceOfCommonPrts.def("Size", (Standard_Integer (IntTools_SequenceOfCommonPrts::*)() const ) &IntTools_SequenceOfCommonPrts::Size, "Number of items");
	cls_IntTools_SequenceOfCommonPrts.def("Length", (Standard_Integer (IntTools_SequenceOfCommonPrts::*)() const ) &IntTools_SequenceOfCommonPrts::Length, "Number of items");
	cls_IntTools_SequenceOfCommonPrts.def("Lower", (Standard_Integer (IntTools_SequenceOfCommonPrts::*)() const ) &IntTools_SequenceOfCommonPrts::Lower, "Method for consistency with other collections.");
	cls_IntTools_SequenceOfCommonPrts.def("Upper", (Standard_Integer (IntTools_SequenceOfCommonPrts::*)() const ) &IntTools_SequenceOfCommonPrts::Upper, "Method for consistency with other collections.");
	cls_IntTools_SequenceOfCommonPrts.def("IsEmpty", (Standard_Boolean (IntTools_SequenceOfCommonPrts::*)() const ) &IntTools_SequenceOfCommonPrts::IsEmpty, "Empty query");
	cls_IntTools_SequenceOfCommonPrts.def("Reverse", (void (IntTools_SequenceOfCommonPrts::*)()) &IntTools_SequenceOfCommonPrts::Reverse, "Reverse sequence");
	cls_IntTools_SequenceOfCommonPrts.def("Exchange", (void (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SequenceOfCommonPrts::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntTools_SequenceOfCommonPrts.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_SequenceOfCommonPrts::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntTools_SequenceOfCommonPrts.def("Clear", [](IntTools_SequenceOfCommonPrts &self) -> void { return self.Clear(); });
	cls_IntTools_SequenceOfCommonPrts.def("Clear", (void (IntTools_SequenceOfCommonPrts::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_SequenceOfCommonPrts::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntTools_SequenceOfCommonPrts.def("Assign", (IntTools_SequenceOfCommonPrts & (IntTools_SequenceOfCommonPrts::*)(const IntTools_SequenceOfCommonPrts &)) &IntTools_SequenceOfCommonPrts::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_SequenceOfCommonPrts.def("assign", (IntTools_SequenceOfCommonPrts & (IntTools_SequenceOfCommonPrts::*)(const IntTools_SequenceOfCommonPrts &)) &IntTools_SequenceOfCommonPrts::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntTools_SequenceOfCommonPrts.def("Remove", (void (IntTools_SequenceOfCommonPrts::*)(IntTools_SequenceOfCommonPrts::Iterator &)) &IntTools_SequenceOfCommonPrts::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntTools_SequenceOfCommonPrts.def("Remove", (void (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer)) &IntTools_SequenceOfCommonPrts::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntTools_SequenceOfCommonPrts.def("Remove", (void (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SequenceOfCommonPrts::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntTools_SequenceOfCommonPrts.def("Append", (void (IntTools_SequenceOfCommonPrts::*)(const IntTools_CommonPrt &)) &IntTools_SequenceOfCommonPrts::Append, "Append one item", py::arg("theItem"));
	cls_IntTools_SequenceOfCommonPrts.def("Append", (void (IntTools_SequenceOfCommonPrts::*)(IntTools_SequenceOfCommonPrts &)) &IntTools_SequenceOfCommonPrts::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntTools_SequenceOfCommonPrts.def("Prepend", (void (IntTools_SequenceOfCommonPrts::*)(const IntTools_CommonPrt &)) &IntTools_SequenceOfCommonPrts::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntTools_SequenceOfCommonPrts.def("Prepend", (void (IntTools_SequenceOfCommonPrts::*)(IntTools_SequenceOfCommonPrts &)) &IntTools_SequenceOfCommonPrts::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntTools_SequenceOfCommonPrts.def("InsertBefore", (void (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer, const IntTools_CommonPrt &)) &IntTools_SequenceOfCommonPrts::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfCommonPrts.def("InsertBefore", (void (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer, IntTools_SequenceOfCommonPrts &)) &IntTools_SequenceOfCommonPrts::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfCommonPrts.def("InsertAfter", (void (IntTools_SequenceOfCommonPrts::*)(IntTools_SequenceOfCommonPrts::Iterator &, const IntTools_CommonPrt &)) &IntTools_SequenceOfCommonPrts::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntTools_SequenceOfCommonPrts.def("InsertAfter", (void (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer, IntTools_SequenceOfCommonPrts &)) &IntTools_SequenceOfCommonPrts::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfCommonPrts.def("InsertAfter", (void (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer, const IntTools_CommonPrt &)) &IntTools_SequenceOfCommonPrts::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfCommonPrts.def("Split", (void (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer, IntTools_SequenceOfCommonPrts &)) &IntTools_SequenceOfCommonPrts::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfCommonPrts.def("First", (const IntTools_CommonPrt & (IntTools_SequenceOfCommonPrts::*)() const ) &IntTools_SequenceOfCommonPrts::First, "First item access");
	cls_IntTools_SequenceOfCommonPrts.def("ChangeFirst", (IntTools_CommonPrt & (IntTools_SequenceOfCommonPrts::*)()) &IntTools_SequenceOfCommonPrts::ChangeFirst, "First item access");
	cls_IntTools_SequenceOfCommonPrts.def("Last", (const IntTools_CommonPrt & (IntTools_SequenceOfCommonPrts::*)() const ) &IntTools_SequenceOfCommonPrts::Last, "Last item access");
	cls_IntTools_SequenceOfCommonPrts.def("ChangeLast", (IntTools_CommonPrt & (IntTools_SequenceOfCommonPrts::*)()) &IntTools_SequenceOfCommonPrts::ChangeLast, "Last item access");
	cls_IntTools_SequenceOfCommonPrts.def("Value", (const IntTools_CommonPrt & (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer) const ) &IntTools_SequenceOfCommonPrts::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntTools_SequenceOfCommonPrts.def("__call__", (const IntTools_CommonPrt & (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer) const ) &IntTools_SequenceOfCommonPrts::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntTools_SequenceOfCommonPrts.def("ChangeValue", (IntTools_CommonPrt & (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer)) &IntTools_SequenceOfCommonPrts::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntTools_SequenceOfCommonPrts.def("__call__", (IntTools_CommonPrt & (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer)) &IntTools_SequenceOfCommonPrts::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntTools_SequenceOfCommonPrts.def("SetValue", (void (IntTools_SequenceOfCommonPrts::*)(const Standard_Integer, const IntTools_CommonPrt &)) &IntTools_SequenceOfCommonPrts::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfCommonPrts.def("__iter__", [](const IntTools_SequenceOfCommonPrts &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntTools_SequenceOfCurves, std::unique_ptr<IntTools_SequenceOfCurves, Deleter<IntTools_SequenceOfCurves>>, NCollection_BaseSequence> cls_IntTools_SequenceOfCurves(mod, "IntTools_SequenceOfCurves", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntTools_SequenceOfCurves.def(py::init<>());
	cls_IntTools_SequenceOfCurves.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntTools_SequenceOfCurves.def(py::init([] (const IntTools_SequenceOfCurves &other) {return new IntTools_SequenceOfCurves(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_SequenceOfCurves.def("begin", (IntTools_SequenceOfCurves::iterator (IntTools_SequenceOfCurves::*)() const ) &IntTools_SequenceOfCurves::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntTools_SequenceOfCurves.def("end", (IntTools_SequenceOfCurves::iterator (IntTools_SequenceOfCurves::*)() const ) &IntTools_SequenceOfCurves::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntTools_SequenceOfCurves.def("cbegin", (IntTools_SequenceOfCurves::const_iterator (IntTools_SequenceOfCurves::*)() const ) &IntTools_SequenceOfCurves::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntTools_SequenceOfCurves.def("cend", (IntTools_SequenceOfCurves::const_iterator (IntTools_SequenceOfCurves::*)() const ) &IntTools_SequenceOfCurves::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntTools_SequenceOfCurves.def("Size", (Standard_Integer (IntTools_SequenceOfCurves::*)() const ) &IntTools_SequenceOfCurves::Size, "Number of items");
	cls_IntTools_SequenceOfCurves.def("Length", (Standard_Integer (IntTools_SequenceOfCurves::*)() const ) &IntTools_SequenceOfCurves::Length, "Number of items");
	cls_IntTools_SequenceOfCurves.def("Lower", (Standard_Integer (IntTools_SequenceOfCurves::*)() const ) &IntTools_SequenceOfCurves::Lower, "Method for consistency with other collections.");
	cls_IntTools_SequenceOfCurves.def("Upper", (Standard_Integer (IntTools_SequenceOfCurves::*)() const ) &IntTools_SequenceOfCurves::Upper, "Method for consistency with other collections.");
	cls_IntTools_SequenceOfCurves.def("IsEmpty", (Standard_Boolean (IntTools_SequenceOfCurves::*)() const ) &IntTools_SequenceOfCurves::IsEmpty, "Empty query");
	cls_IntTools_SequenceOfCurves.def("Reverse", (void (IntTools_SequenceOfCurves::*)()) &IntTools_SequenceOfCurves::Reverse, "Reverse sequence");
	cls_IntTools_SequenceOfCurves.def("Exchange", (void (IntTools_SequenceOfCurves::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SequenceOfCurves::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntTools_SequenceOfCurves.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_SequenceOfCurves::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntTools_SequenceOfCurves.def("Clear", [](IntTools_SequenceOfCurves &self) -> void { return self.Clear(); });
	cls_IntTools_SequenceOfCurves.def("Clear", (void (IntTools_SequenceOfCurves::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_SequenceOfCurves::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntTools_SequenceOfCurves.def("Assign", (IntTools_SequenceOfCurves & (IntTools_SequenceOfCurves::*)(const IntTools_SequenceOfCurves &)) &IntTools_SequenceOfCurves::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_SequenceOfCurves.def("assign", (IntTools_SequenceOfCurves & (IntTools_SequenceOfCurves::*)(const IntTools_SequenceOfCurves &)) &IntTools_SequenceOfCurves::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntTools_SequenceOfCurves.def("Remove", (void (IntTools_SequenceOfCurves::*)(IntTools_SequenceOfCurves::Iterator &)) &IntTools_SequenceOfCurves::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntTools_SequenceOfCurves.def("Remove", (void (IntTools_SequenceOfCurves::*)(const Standard_Integer)) &IntTools_SequenceOfCurves::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntTools_SequenceOfCurves.def("Remove", (void (IntTools_SequenceOfCurves::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SequenceOfCurves::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntTools_SequenceOfCurves.def("Append", (void (IntTools_SequenceOfCurves::*)(const IntTools_Curve &)) &IntTools_SequenceOfCurves::Append, "Append one item", py::arg("theItem"));
	cls_IntTools_SequenceOfCurves.def("Append", (void (IntTools_SequenceOfCurves::*)(IntTools_SequenceOfCurves &)) &IntTools_SequenceOfCurves::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntTools_SequenceOfCurves.def("Prepend", (void (IntTools_SequenceOfCurves::*)(const IntTools_Curve &)) &IntTools_SequenceOfCurves::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntTools_SequenceOfCurves.def("Prepend", (void (IntTools_SequenceOfCurves::*)(IntTools_SequenceOfCurves &)) &IntTools_SequenceOfCurves::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntTools_SequenceOfCurves.def("InsertBefore", (void (IntTools_SequenceOfCurves::*)(const Standard_Integer, const IntTools_Curve &)) &IntTools_SequenceOfCurves::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfCurves.def("InsertBefore", (void (IntTools_SequenceOfCurves::*)(const Standard_Integer, IntTools_SequenceOfCurves &)) &IntTools_SequenceOfCurves::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfCurves.def("InsertAfter", (void (IntTools_SequenceOfCurves::*)(IntTools_SequenceOfCurves::Iterator &, const IntTools_Curve &)) &IntTools_SequenceOfCurves::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntTools_SequenceOfCurves.def("InsertAfter", (void (IntTools_SequenceOfCurves::*)(const Standard_Integer, IntTools_SequenceOfCurves &)) &IntTools_SequenceOfCurves::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfCurves.def("InsertAfter", (void (IntTools_SequenceOfCurves::*)(const Standard_Integer, const IntTools_Curve &)) &IntTools_SequenceOfCurves::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfCurves.def("Split", (void (IntTools_SequenceOfCurves::*)(const Standard_Integer, IntTools_SequenceOfCurves &)) &IntTools_SequenceOfCurves::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfCurves.def("First", (const IntTools_Curve & (IntTools_SequenceOfCurves::*)() const ) &IntTools_SequenceOfCurves::First, "First item access");
	cls_IntTools_SequenceOfCurves.def("ChangeFirst", (IntTools_Curve & (IntTools_SequenceOfCurves::*)()) &IntTools_SequenceOfCurves::ChangeFirst, "First item access");
	cls_IntTools_SequenceOfCurves.def("Last", (const IntTools_Curve & (IntTools_SequenceOfCurves::*)() const ) &IntTools_SequenceOfCurves::Last, "Last item access");
	cls_IntTools_SequenceOfCurves.def("ChangeLast", (IntTools_Curve & (IntTools_SequenceOfCurves::*)()) &IntTools_SequenceOfCurves::ChangeLast, "Last item access");
	cls_IntTools_SequenceOfCurves.def("Value", (const IntTools_Curve & (IntTools_SequenceOfCurves::*)(const Standard_Integer) const ) &IntTools_SequenceOfCurves::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntTools_SequenceOfCurves.def("__call__", (const IntTools_Curve & (IntTools_SequenceOfCurves::*)(const Standard_Integer) const ) &IntTools_SequenceOfCurves::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntTools_SequenceOfCurves.def("ChangeValue", (IntTools_Curve & (IntTools_SequenceOfCurves::*)(const Standard_Integer)) &IntTools_SequenceOfCurves::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntTools_SequenceOfCurves.def("__call__", (IntTools_Curve & (IntTools_SequenceOfCurves::*)(const Standard_Integer)) &IntTools_SequenceOfCurves::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntTools_SequenceOfCurves.def("SetValue", (void (IntTools_SequenceOfCurves::*)(const Standard_Integer, const IntTools_Curve &)) &IntTools_SequenceOfCurves::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfCurves.def("__iter__", [](const IntTools_SequenceOfCurves &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntTools_SequenceOfPntOn2Faces, std::unique_ptr<IntTools_SequenceOfPntOn2Faces, Deleter<IntTools_SequenceOfPntOn2Faces>>, NCollection_BaseSequence> cls_IntTools_SequenceOfPntOn2Faces(mod, "IntTools_SequenceOfPntOn2Faces", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntTools_SequenceOfPntOn2Faces.def(py::init<>());
	cls_IntTools_SequenceOfPntOn2Faces.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntTools_SequenceOfPntOn2Faces.def(py::init([] (const IntTools_SequenceOfPntOn2Faces &other) {return new IntTools_SequenceOfPntOn2Faces(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_SequenceOfPntOn2Faces.def("begin", (IntTools_SequenceOfPntOn2Faces::iterator (IntTools_SequenceOfPntOn2Faces::*)() const ) &IntTools_SequenceOfPntOn2Faces::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntTools_SequenceOfPntOn2Faces.def("end", (IntTools_SequenceOfPntOn2Faces::iterator (IntTools_SequenceOfPntOn2Faces::*)() const ) &IntTools_SequenceOfPntOn2Faces::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntTools_SequenceOfPntOn2Faces.def("cbegin", (IntTools_SequenceOfPntOn2Faces::const_iterator (IntTools_SequenceOfPntOn2Faces::*)() const ) &IntTools_SequenceOfPntOn2Faces::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntTools_SequenceOfPntOn2Faces.def("cend", (IntTools_SequenceOfPntOn2Faces::const_iterator (IntTools_SequenceOfPntOn2Faces::*)() const ) &IntTools_SequenceOfPntOn2Faces::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntTools_SequenceOfPntOn2Faces.def("Size", (Standard_Integer (IntTools_SequenceOfPntOn2Faces::*)() const ) &IntTools_SequenceOfPntOn2Faces::Size, "Number of items");
	cls_IntTools_SequenceOfPntOn2Faces.def("Length", (Standard_Integer (IntTools_SequenceOfPntOn2Faces::*)() const ) &IntTools_SequenceOfPntOn2Faces::Length, "Number of items");
	cls_IntTools_SequenceOfPntOn2Faces.def("Lower", (Standard_Integer (IntTools_SequenceOfPntOn2Faces::*)() const ) &IntTools_SequenceOfPntOn2Faces::Lower, "Method for consistency with other collections.");
	cls_IntTools_SequenceOfPntOn2Faces.def("Upper", (Standard_Integer (IntTools_SequenceOfPntOn2Faces::*)() const ) &IntTools_SequenceOfPntOn2Faces::Upper, "Method for consistency with other collections.");
	cls_IntTools_SequenceOfPntOn2Faces.def("IsEmpty", (Standard_Boolean (IntTools_SequenceOfPntOn2Faces::*)() const ) &IntTools_SequenceOfPntOn2Faces::IsEmpty, "Empty query");
	cls_IntTools_SequenceOfPntOn2Faces.def("Reverse", (void (IntTools_SequenceOfPntOn2Faces::*)()) &IntTools_SequenceOfPntOn2Faces::Reverse, "Reverse sequence");
	cls_IntTools_SequenceOfPntOn2Faces.def("Exchange", (void (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SequenceOfPntOn2Faces::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntTools_SequenceOfPntOn2Faces.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_SequenceOfPntOn2Faces::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntTools_SequenceOfPntOn2Faces.def("Clear", [](IntTools_SequenceOfPntOn2Faces &self) -> void { return self.Clear(); });
	cls_IntTools_SequenceOfPntOn2Faces.def("Clear", (void (IntTools_SequenceOfPntOn2Faces::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_SequenceOfPntOn2Faces::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntTools_SequenceOfPntOn2Faces.def("Assign", (IntTools_SequenceOfPntOn2Faces & (IntTools_SequenceOfPntOn2Faces::*)(const IntTools_SequenceOfPntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_SequenceOfPntOn2Faces.def("assign", (IntTools_SequenceOfPntOn2Faces & (IntTools_SequenceOfPntOn2Faces::*)(const IntTools_SequenceOfPntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntTools_SequenceOfPntOn2Faces.def("Remove", (void (IntTools_SequenceOfPntOn2Faces::*)(IntTools_SequenceOfPntOn2Faces::Iterator &)) &IntTools_SequenceOfPntOn2Faces::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntTools_SequenceOfPntOn2Faces.def("Remove", (void (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer)) &IntTools_SequenceOfPntOn2Faces::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntTools_SequenceOfPntOn2Faces.def("Remove", (void (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SequenceOfPntOn2Faces::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntTools_SequenceOfPntOn2Faces.def("Append", (void (IntTools_SequenceOfPntOn2Faces::*)(const IntTools_PntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::Append, "Append one item", py::arg("theItem"));
	cls_IntTools_SequenceOfPntOn2Faces.def("Append", (void (IntTools_SequenceOfPntOn2Faces::*)(IntTools_SequenceOfPntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntTools_SequenceOfPntOn2Faces.def("Prepend", (void (IntTools_SequenceOfPntOn2Faces::*)(const IntTools_PntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntTools_SequenceOfPntOn2Faces.def("Prepend", (void (IntTools_SequenceOfPntOn2Faces::*)(IntTools_SequenceOfPntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntTools_SequenceOfPntOn2Faces.def("InsertBefore", (void (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer, const IntTools_PntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfPntOn2Faces.def("InsertBefore", (void (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer, IntTools_SequenceOfPntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfPntOn2Faces.def("InsertAfter", (void (IntTools_SequenceOfPntOn2Faces::*)(IntTools_SequenceOfPntOn2Faces::Iterator &, const IntTools_PntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntTools_SequenceOfPntOn2Faces.def("InsertAfter", (void (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer, IntTools_SequenceOfPntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfPntOn2Faces.def("InsertAfter", (void (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer, const IntTools_PntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfPntOn2Faces.def("Split", (void (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer, IntTools_SequenceOfPntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntTools_SequenceOfPntOn2Faces.def("First", (const IntTools_PntOn2Faces & (IntTools_SequenceOfPntOn2Faces::*)() const ) &IntTools_SequenceOfPntOn2Faces::First, "First item access");
	cls_IntTools_SequenceOfPntOn2Faces.def("ChangeFirst", (IntTools_PntOn2Faces & (IntTools_SequenceOfPntOn2Faces::*)()) &IntTools_SequenceOfPntOn2Faces::ChangeFirst, "First item access");
	cls_IntTools_SequenceOfPntOn2Faces.def("Last", (const IntTools_PntOn2Faces & (IntTools_SequenceOfPntOn2Faces::*)() const ) &IntTools_SequenceOfPntOn2Faces::Last, "Last item access");
	cls_IntTools_SequenceOfPntOn2Faces.def("ChangeLast", (IntTools_PntOn2Faces & (IntTools_SequenceOfPntOn2Faces::*)()) &IntTools_SequenceOfPntOn2Faces::ChangeLast, "Last item access");
	cls_IntTools_SequenceOfPntOn2Faces.def("Value", (const IntTools_PntOn2Faces & (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer) const ) &IntTools_SequenceOfPntOn2Faces::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntTools_SequenceOfPntOn2Faces.def("__call__", (const IntTools_PntOn2Faces & (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer) const ) &IntTools_SequenceOfPntOn2Faces::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntTools_SequenceOfPntOn2Faces.def("ChangeValue", (IntTools_PntOn2Faces & (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer)) &IntTools_SequenceOfPntOn2Faces::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntTools_SequenceOfPntOn2Faces.def("__call__", (IntTools_PntOn2Faces & (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer)) &IntTools_SequenceOfPntOn2Faces::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntTools_SequenceOfPntOn2Faces.def("SetValue", (void (IntTools_SequenceOfPntOn2Faces::*)(const Standard_Integer, const IntTools_PntOn2Faces &)) &IntTools_SequenceOfPntOn2Faces::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntTools_SequenceOfPntOn2Faces.def("__iter__", [](const IntTools_SequenceOfPntOn2Faces &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<IntTools_IndexedDataMapOfTransientAddress, std::unique_ptr<IntTools_IndexedDataMapOfTransientAddress, Deleter<IntTools_IndexedDataMapOfTransientAddress>>, NCollection_BaseMap> cls_IntTools_IndexedDataMapOfTransientAddress(mod, "IntTools_IndexedDataMapOfTransientAddress", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_IntTools_IndexedDataMapOfTransientAddress.def(py::init<>());
	cls_IntTools_IndexedDataMapOfTransientAddress.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def(py::init([] (const IntTools_IndexedDataMapOfTransientAddress &other) {return new IntTools_IndexedDataMapOfTransientAddress(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("begin", (IntTools_IndexedDataMapOfTransientAddress::iterator (IntTools_IndexedDataMapOfTransientAddress::*)() const ) &IntTools_IndexedDataMapOfTransientAddress::begin, "Returns an iterator pointing to the first element in the map.");
	cls_IntTools_IndexedDataMapOfTransientAddress.def("end", (IntTools_IndexedDataMapOfTransientAddress::iterator (IntTools_IndexedDataMapOfTransientAddress::*)() const ) &IntTools_IndexedDataMapOfTransientAddress::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_IntTools_IndexedDataMapOfTransientAddress.def("cbegin", (IntTools_IndexedDataMapOfTransientAddress::const_iterator (IntTools_IndexedDataMapOfTransientAddress::*)() const ) &IntTools_IndexedDataMapOfTransientAddress::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_IntTools_IndexedDataMapOfTransientAddress.def("cend", (IntTools_IndexedDataMapOfTransientAddress::const_iterator (IntTools_IndexedDataMapOfTransientAddress::*)() const ) &IntTools_IndexedDataMapOfTransientAddress::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_IntTools_IndexedDataMapOfTransientAddress.def("Exchange", (void (IntTools_IndexedDataMapOfTransientAddress::*)(IntTools_IndexedDataMapOfTransientAddress &)) &IntTools_IndexedDataMapOfTransientAddress::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("Assign", (IntTools_IndexedDataMapOfTransientAddress & (IntTools_IndexedDataMapOfTransientAddress::*)(const IntTools_IndexedDataMapOfTransientAddress &)) &IntTools_IndexedDataMapOfTransientAddress::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("assign", (IntTools_IndexedDataMapOfTransientAddress & (IntTools_IndexedDataMapOfTransientAddress::*)(const IntTools_IndexedDataMapOfTransientAddress &)) &IntTools_IndexedDataMapOfTransientAddress::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("ReSize", (void (IntTools_IndexedDataMapOfTransientAddress::*)(const Standard_Integer)) &IntTools_IndexedDataMapOfTransientAddress::ReSize, "ReSize", py::arg("N"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("Add", (Standard_Integer (IntTools_IndexedDataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &, const Standard_Address &)) &IntTools_IndexedDataMapOfTransientAddress::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("Contains", (Standard_Boolean (IntTools_IndexedDataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &) const ) &IntTools_IndexedDataMapOfTransientAddress::Contains, "Contains", py::arg("theKey1"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("Substitute", (void (IntTools_IndexedDataMapOfTransientAddress::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Standard_Address &)) &IntTools_IndexedDataMapOfTransientAddress::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("Swap", (void (IntTools_IndexedDataMapOfTransientAddress::*)(const Standard_Integer, const Standard_Integer)) &IntTools_IndexedDataMapOfTransientAddress::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("RemoveLast", (void (IntTools_IndexedDataMapOfTransientAddress::*)()) &IntTools_IndexedDataMapOfTransientAddress::RemoveLast, "RemoveLast");
	cls_IntTools_IndexedDataMapOfTransientAddress.def("RemoveFromIndex", (void (IntTools_IndexedDataMapOfTransientAddress::*)(const Standard_Integer)) &IntTools_IndexedDataMapOfTransientAddress::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("RemoveKey", (void (IntTools_IndexedDataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &)) &IntTools_IndexedDataMapOfTransientAddress::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("FindKey", (const opencascade::handle<Standard_Transient> & (IntTools_IndexedDataMapOfTransientAddress::*)(const Standard_Integer) const ) &IntTools_IndexedDataMapOfTransientAddress::FindKey, "FindKey", py::arg("theKey2"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("FindFromIndex", (const Standard_Address & (IntTools_IndexedDataMapOfTransientAddress::*)(const Standard_Integer) const ) &IntTools_IndexedDataMapOfTransientAddress::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("__call__", (const Standard_Address & (IntTools_IndexedDataMapOfTransientAddress::*)(const Standard_Integer) const ) &IntTools_IndexedDataMapOfTransientAddress::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("ChangeFromIndex", (Standard_Address & (IntTools_IndexedDataMapOfTransientAddress::*)(const Standard_Integer)) &IntTools_IndexedDataMapOfTransientAddress::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("__call__", (Standard_Address & (IntTools_IndexedDataMapOfTransientAddress::*)(const Standard_Integer)) &IntTools_IndexedDataMapOfTransientAddress::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("FindIndex", (Standard_Integer (IntTools_IndexedDataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &) const ) &IntTools_IndexedDataMapOfTransientAddress::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("FindFromKey", (const Standard_Address & (IntTools_IndexedDataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &) const ) &IntTools_IndexedDataMapOfTransientAddress::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("ChangeFromKey", (Standard_Address & (IntTools_IndexedDataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &)) &IntTools_IndexedDataMapOfTransientAddress::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_IntTools_IndexedDataMapOfTransientAddress.def("Seek", (const Standard_Address * (IntTools_IndexedDataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &) const ) &IntTools_IndexedDataMapOfTransientAddress::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_IntTools_IndexedDataMapOfTransientAddress.def("ChangeSeek", (Standard_Address * (IntTools_IndexedDataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &)) &IntTools_IndexedDataMapOfTransientAddress::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("FindFromKey", (Standard_Boolean (IntTools_IndexedDataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &, Standard_Address &) const ) &IntTools_IndexedDataMapOfTransientAddress::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("Clear", [](IntTools_IndexedDataMapOfTransientAddress &self) -> void { return self.Clear(); });
	cls_IntTools_IndexedDataMapOfTransientAddress.def("Clear", (void (IntTools_IndexedDataMapOfTransientAddress::*)(const Standard_Boolean)) &IntTools_IndexedDataMapOfTransientAddress::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("Clear", (void (IntTools_IndexedDataMapOfTransientAddress::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_IndexedDataMapOfTransientAddress::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_IntTools_IndexedDataMapOfTransientAddress.def("Size", (Standard_Integer (IntTools_IndexedDataMapOfTransientAddress::*)() const ) &IntTools_IndexedDataMapOfTransientAddress::Size, "Size");
	cls_IntTools_IndexedDataMapOfTransientAddress.def("__iter__", [](const IntTools_IndexedDataMapOfTransientAddress &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<IntTools_ListOfBox, std::unique_ptr<IntTools_ListOfBox, Deleter<IntTools_ListOfBox>>, NCollection_BaseList> cls_IntTools_ListOfBox(mod, "IntTools_ListOfBox", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_IntTools_ListOfBox.def(py::init<>());
	cls_IntTools_ListOfBox.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntTools_ListOfBox.def(py::init([] (const IntTools_ListOfBox &other) {return new IntTools_ListOfBox(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_ListOfBox.def("begin", (IntTools_ListOfBox::iterator (IntTools_ListOfBox::*)() const ) &IntTools_ListOfBox::begin, "Returns an iterator pointing to the first element in the list.");
	cls_IntTools_ListOfBox.def("end", (IntTools_ListOfBox::iterator (IntTools_ListOfBox::*)() const ) &IntTools_ListOfBox::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_IntTools_ListOfBox.def("cbegin", (IntTools_ListOfBox::const_iterator (IntTools_ListOfBox::*)() const ) &IntTools_ListOfBox::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_IntTools_ListOfBox.def("cend", (IntTools_ListOfBox::const_iterator (IntTools_ListOfBox::*)() const ) &IntTools_ListOfBox::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_IntTools_ListOfBox.def("Size", (Standard_Integer (IntTools_ListOfBox::*)() const ) &IntTools_ListOfBox::Size, "Size - Number of items");
	cls_IntTools_ListOfBox.def("Assign", (IntTools_ListOfBox & (IntTools_ListOfBox::*)(const IntTools_ListOfBox &)) &IntTools_ListOfBox::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_ListOfBox.def("assign", (IntTools_ListOfBox & (IntTools_ListOfBox::*)(const IntTools_ListOfBox &)) &IntTools_ListOfBox::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntTools_ListOfBox.def("Clear", [](IntTools_ListOfBox &self) -> void { return self.Clear(); });
	cls_IntTools_ListOfBox.def("Clear", (void (IntTools_ListOfBox::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_ListOfBox::Clear, "Clear this list", py::arg("theAllocator"));
	cls_IntTools_ListOfBox.def("First", (const Bnd_Box & (IntTools_ListOfBox::*)() const ) &IntTools_ListOfBox::First, "First item");
	cls_IntTools_ListOfBox.def("First", (Bnd_Box & (IntTools_ListOfBox::*)()) &IntTools_ListOfBox::First, "First item (non-const)");
	cls_IntTools_ListOfBox.def("Last", (const Bnd_Box & (IntTools_ListOfBox::*)() const ) &IntTools_ListOfBox::Last, "Last item");
	cls_IntTools_ListOfBox.def("Last", (Bnd_Box & (IntTools_ListOfBox::*)()) &IntTools_ListOfBox::Last, "Last item (non-const)");
	cls_IntTools_ListOfBox.def("Append", (Bnd_Box & (IntTools_ListOfBox::*)(const Bnd_Box &)) &IntTools_ListOfBox::Append, "Append one item at the end", py::arg("theItem"));
	cls_IntTools_ListOfBox.def("Append", (void (IntTools_ListOfBox::*)(const Bnd_Box &, IntTools_ListOfBox::Iterator &)) &IntTools_ListOfBox::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_IntTools_ListOfBox.def("Append", (void (IntTools_ListOfBox::*)(IntTools_ListOfBox &)) &IntTools_ListOfBox::Append, "Append another list at the end", py::arg("theOther"));
	cls_IntTools_ListOfBox.def("Prepend", (Bnd_Box & (IntTools_ListOfBox::*)(const Bnd_Box &)) &IntTools_ListOfBox::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_IntTools_ListOfBox.def("Prepend", (void (IntTools_ListOfBox::*)(IntTools_ListOfBox &)) &IntTools_ListOfBox::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_IntTools_ListOfBox.def("RemoveFirst", (void (IntTools_ListOfBox::*)()) &IntTools_ListOfBox::RemoveFirst, "RemoveFirst item");
	cls_IntTools_ListOfBox.def("Remove", (void (IntTools_ListOfBox::*)(IntTools_ListOfBox::Iterator &)) &IntTools_ListOfBox::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_IntTools_ListOfBox.def("InsertBefore", (Bnd_Box & (IntTools_ListOfBox::*)(const Bnd_Box &, IntTools_ListOfBox::Iterator &)) &IntTools_ListOfBox::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_IntTools_ListOfBox.def("InsertBefore", (void (IntTools_ListOfBox::*)(IntTools_ListOfBox &, IntTools_ListOfBox::Iterator &)) &IntTools_ListOfBox::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_IntTools_ListOfBox.def("InsertAfter", (Bnd_Box & (IntTools_ListOfBox::*)(const Bnd_Box &, IntTools_ListOfBox::Iterator &)) &IntTools_ListOfBox::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_IntTools_ListOfBox.def("InsertAfter", (void (IntTools_ListOfBox::*)(IntTools_ListOfBox &, IntTools_ListOfBox::Iterator &)) &IntTools_ListOfBox::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_IntTools_ListOfBox.def("Reverse", (void (IntTools_ListOfBox::*)()) &IntTools_ListOfBox::Reverse, "Reverse the list");
	cls_IntTools_ListOfBox.def("__iter__", [](const IntTools_ListOfBox &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<IntTools_ListIteratorOfListOfBox, std::unique_ptr<IntTools_ListIteratorOfListOfBox, Deleter<IntTools_ListIteratorOfListOfBox>>> cls_IntTools_ListIteratorOfListOfBox(mod, "IntTools_ListIteratorOfListOfBox", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_IntTools_ListIteratorOfListOfBox.def(py::init<>());
	cls_IntTools_ListIteratorOfListOfBox.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_IntTools_ListIteratorOfListOfBox.def("More", (Standard_Boolean (IntTools_ListIteratorOfListOfBox::*)() const ) &IntTools_ListIteratorOfListOfBox::More, "Check end");
	cls_IntTools_ListIteratorOfListOfBox.def("Next", (void (IntTools_ListIteratorOfListOfBox::*)()) &IntTools_ListIteratorOfListOfBox::Next, "Make step");
	cls_IntTools_ListIteratorOfListOfBox.def("Value", (const Bnd_Box & (IntTools_ListIteratorOfListOfBox::*)() const ) &IntTools_ListIteratorOfListOfBox::Value, "Constant Value access");
	cls_IntTools_ListIteratorOfListOfBox.def("Value", (Bnd_Box & (IntTools_ListIteratorOfListOfBox::*)()) &IntTools_ListIteratorOfListOfBox::Value, "Non-const Value access");
	cls_IntTools_ListIteratorOfListOfBox.def("ChangeValue", (Bnd_Box & (IntTools_ListIteratorOfListOfBox::*)() const ) &IntTools_ListIteratorOfListOfBox::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<IntTools_MapOfSurfaceSample, std::unique_ptr<IntTools_MapOfSurfaceSample, Deleter<IntTools_MapOfSurfaceSample>>, NCollection_BaseMap> cls_IntTools_MapOfSurfaceSample(mod, "IntTools_MapOfSurfaceSample", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_IntTools_MapOfSurfaceSample.def(py::init<>());
	cls_IntTools_MapOfSurfaceSample.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_IntTools_MapOfSurfaceSample.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_IntTools_MapOfSurfaceSample.def(py::init([] (const IntTools_MapOfSurfaceSample &other) {return new IntTools_MapOfSurfaceSample(other);}), "Copy constructor", py::arg("other"));
	cls_IntTools_MapOfSurfaceSample.def("cbegin", (IntTools_MapOfSurfaceSample::const_iterator (IntTools_MapOfSurfaceSample::*)() const ) &IntTools_MapOfSurfaceSample::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_IntTools_MapOfSurfaceSample.def("cend", (IntTools_MapOfSurfaceSample::const_iterator (IntTools_MapOfSurfaceSample::*)() const ) &IntTools_MapOfSurfaceSample::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_IntTools_MapOfSurfaceSample.def("Exchange", (void (IntTools_MapOfSurfaceSample::*)(IntTools_MapOfSurfaceSample &)) &IntTools_MapOfSurfaceSample::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_IntTools_MapOfSurfaceSample.def("Assign", (IntTools_MapOfSurfaceSample & (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &)) &IntTools_MapOfSurfaceSample::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntTools_MapOfSurfaceSample.def("assign", (IntTools_MapOfSurfaceSample & (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &)) &IntTools_MapOfSurfaceSample::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_IntTools_MapOfSurfaceSample.def("ReSize", (void (IntTools_MapOfSurfaceSample::*)(const Standard_Integer)) &IntTools_MapOfSurfaceSample::ReSize, "ReSize", py::arg("N"));
	cls_IntTools_MapOfSurfaceSample.def("Add", (Standard_Boolean (IntTools_MapOfSurfaceSample::*)(const IntTools_SurfaceRangeSample &)) &IntTools_MapOfSurfaceSample::Add, "Add", py::arg("K"));
	cls_IntTools_MapOfSurfaceSample.def("Added", (const IntTools_SurfaceRangeSample & (IntTools_MapOfSurfaceSample::*)(const IntTools_SurfaceRangeSample &)) &IntTools_MapOfSurfaceSample::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_IntTools_MapOfSurfaceSample.def("Contains", (Standard_Boolean (IntTools_MapOfSurfaceSample::*)(const IntTools_SurfaceRangeSample &) const ) &IntTools_MapOfSurfaceSample::Contains, "Contains", py::arg("K"));
	cls_IntTools_MapOfSurfaceSample.def("Remove", (Standard_Boolean (IntTools_MapOfSurfaceSample::*)(const IntTools_SurfaceRangeSample &)) &IntTools_MapOfSurfaceSample::Remove, "Remove", py::arg("K"));
	cls_IntTools_MapOfSurfaceSample.def("Clear", [](IntTools_MapOfSurfaceSample &self) -> void { return self.Clear(); });
	cls_IntTools_MapOfSurfaceSample.def("Clear", (void (IntTools_MapOfSurfaceSample::*)(const Standard_Boolean)) &IntTools_MapOfSurfaceSample::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_IntTools_MapOfSurfaceSample.def("Clear", (void (IntTools_MapOfSurfaceSample::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntTools_MapOfSurfaceSample::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_IntTools_MapOfSurfaceSample.def("Size", (Standard_Integer (IntTools_MapOfSurfaceSample::*)() const ) &IntTools_MapOfSurfaceSample::Size, "Size");
	cls_IntTools_MapOfSurfaceSample.def("IsEqual", (Standard_Boolean (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &) const ) &IntTools_MapOfSurfaceSample::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_IntTools_MapOfSurfaceSample.def("Contains", (Standard_Boolean (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &) const ) &IntTools_MapOfSurfaceSample::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_IntTools_MapOfSurfaceSample.def("Union", (void (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &, const IntTools_MapOfSurfaceSample &)) &IntTools_MapOfSurfaceSample::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_IntTools_MapOfSurfaceSample.def("Unite", (Standard_Boolean (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &)) &IntTools_MapOfSurfaceSample::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_IntTools_MapOfSurfaceSample.def("HasIntersection", (Standard_Boolean (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &) const ) &IntTools_MapOfSurfaceSample::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_IntTools_MapOfSurfaceSample.def("Intersection", (void (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &, const IntTools_MapOfSurfaceSample &)) &IntTools_MapOfSurfaceSample::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_IntTools_MapOfSurfaceSample.def("Intersect", (Standard_Boolean (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &)) &IntTools_MapOfSurfaceSample::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_IntTools_MapOfSurfaceSample.def("Subtraction", (void (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &, const IntTools_MapOfSurfaceSample &)) &IntTools_MapOfSurfaceSample::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_IntTools_MapOfSurfaceSample.def("Subtract", (Standard_Boolean (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &)) &IntTools_MapOfSurfaceSample::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_IntTools_MapOfSurfaceSample.def("Difference", (void (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &, const IntTools_MapOfSurfaceSample &)) &IntTools_MapOfSurfaceSample::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_IntTools_MapOfSurfaceSample.def("Differ", (Standard_Boolean (IntTools_MapOfSurfaceSample::*)(const IntTools_MapOfSurfaceSample &)) &IntTools_MapOfSurfaceSample::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntTools_MapOfSurfaceSample.hxx

}
