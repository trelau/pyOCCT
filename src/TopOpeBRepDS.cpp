#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TopOpeBRepTool_ShapeClassifier.hxx>

#include <TopAbs_State.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <Standard_Type.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TopOpeBRepDS_ShapeShapeInterference.hxx>
#include <TopOpeBRepDS_CurvePointInterference.hxx>
#include <TopOpeBRepDS_EdgeVertexInterference.hxx>
#include <TopOpeBRepDS_FaceEdgeInterference.hxx>
#include <TopOpeBRepDS_InterferenceIterator.hxx>
#include <Geom_Surface.hxx>
#include <TopOpeBRepDS_Surface.hxx>
#include <TopOpeBRepDS_GeometryData.hxx>
#include <TopOpeBRepDS_Curve.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepDS_MapOfShapeData.hxx>
#include <TopOpeBRepDS_IndexedDataMapOfShapeWithState.hxx>
#include <TopOpeBRepDS_ShapeWithState.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <TopOpeBRepDS_SurfaceData.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <TopOpeBRepDS_MapOfSurface.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <TopOpeBRepDS_CurveData.hxx>
#include <TopOpeBRepDS_MapOfCurve.hxx>
#include <gp_Pnt.hxx>
#include <TopOpeBRepDS_PointData.hxx>
#include <TopOpeBRepDS_MapOfPoint.hxx>
#include <TopOpeBRepDS_ShapeData.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TopOpeBRepDS_ShapeSurface.hxx>
#include <TopOpeBRepDS_SurfaceExplorer.hxx>
#include <TopOpeBRepDS_CurveExplorer.hxx>
#include <TopOpeBRepDS_PointExplorer.hxx>
#include <TopOpeBRepDS_CurveIterator.hxx>
#include <TopOpeBRepDS_PointIterator.hxx>
#include <TopOpeBRepDS_SurfaceIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopOpeBRepDS_PDataStructure.hxx>
#include <TopOpeBRepDS_SurfaceCurveInterference.hxx>
#include <TopOpeBRepTool_OutCurveType.hxx>
#include <TopOpeBRepTool_GeomTool.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRepDS_BuildTool.hxx>
#include <TopOpeBRepDS_ListOfShapeOn1State.hxx>
#include <TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.hxx>
#include <TopOpeBRepDS_DataMapOfShapeState.hxx>
#include <TopOpeBRepDS_TKI.hxx>
#include <TopOpeBRepDS_SolidSurfaceInterference.hxx>
#include <TopOpeBRepDS.hxx>
#include <TopOpeBRepDS_InterferenceTool.hxx>
#include <TopOpeBRepDS_Dumper.hxx>
#include <TopOpeBRepDS_Marker.hxx>
#include <TopOpeBRepDS_EdgeInterferenceTool.hxx>
#include <TopOpeBRepDS_Edge3dInterferenceTool.hxx>
#include <TopOpeBRepDS_FaceInterferenceTool.hxx>
#include <TopOpeBRepTool_PShapeClassifier.hxx>
#include <TopOpeBRepDS_Filter.hxx>
#include <TopOpeBRepDS_Reducer.hxx>
#include <TopOpeBRepDS_TOOL.hxx>
#include <TopOpeBRepDS_FIR.hxx>
#include <TopOpeBRepDS_EIR.hxx>
#include <Standard_OStream.hxx>
#include <TopOpeBRepDS_CheckStatus.hxx>
#include <TopOpeBRepDS_Check.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TopOpeBRepDS_GapFiller.hxx>
#include <TopOpeBRepDS_GapTool.hxx>
#include <TopOpeBRepDS_Association.hxx>
#include <TopOpeBRepDS_Explorer.hxx>
#include <TopOpeBRepDS_DataMapOfIntegerListOfInterference.hxx>
#include <NCollection_Array1.hxx>
#include <TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.hxx>
#include <TopOpeBRepDS_DataMapOfInterferenceListOfInterference.hxx>
#include <TopOpeBRepDS_DataMapOfCheckStatus.hxx>
#include <TopOpeBRepDS_connex.hxx>
#include <TopOpeBRepDS_DataMapOfInterferenceShape.hxx>
#include <TopOpeBRepDS_MapOfIntegerShapeData.hxx>
#include <NCollection_DoubleMap.hxx>
#include <TopOpeBRepDS_DoubleMapOfIntegerShape.hxx>
#include <TopOpeBRepDS_EXPORT.hxx>
#include <TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.hxx>
#include <TopOpeBRepDS_IndexedDataMapOfVertexPoint.hxx>
#include <TopOpeBRepDS_ProcessInterferencesTool.hxx>
#include <TopOpeBRepDS_repvg.hxx>
#include <TopOpeBRepDS_samdom.hxx>

PYBIND11_MODULE(TopOpeBRepDS, mod) {

	// IMPORT
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TopOpeBRepTool");
	py::module::import("OCCT.TColStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Config.hxx
	py::enum_<TopOpeBRepDS_Config>(mod, "TopOpeBRepDS_Config", "None")
		.value("TopOpeBRepDS_UNSHGEOMETRY", TopOpeBRepDS_Config::TopOpeBRepDS_UNSHGEOMETRY)
		.value("TopOpeBRepDS_SAMEORIENTED", TopOpeBRepDS_Config::TopOpeBRepDS_SAMEORIENTED)
		.value("TopOpeBRepDS_DIFFORIENTED", TopOpeBRepDS_Config::TopOpeBRepDS_DIFFORIENTED)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Kind.hxx
	py::enum_<TopOpeBRepDS_Kind>(mod, "TopOpeBRepDS_Kind", "different types of objects in DataStructure")
		.value("TopOpeBRepDS_POINT", TopOpeBRepDS_Kind::TopOpeBRepDS_POINT)
		.value("TopOpeBRepDS_CURVE", TopOpeBRepDS_Kind::TopOpeBRepDS_CURVE)
		.value("TopOpeBRepDS_SURFACE", TopOpeBRepDS_Kind::TopOpeBRepDS_SURFACE)
		.value("TopOpeBRepDS_VERTEX", TopOpeBRepDS_Kind::TopOpeBRepDS_VERTEX)
		.value("TopOpeBRepDS_EDGE", TopOpeBRepDS_Kind::TopOpeBRepDS_EDGE)
		.value("TopOpeBRepDS_WIRE", TopOpeBRepDS_Kind::TopOpeBRepDS_WIRE)
		.value("TopOpeBRepDS_FACE", TopOpeBRepDS_Kind::TopOpeBRepDS_FACE)
		.value("TopOpeBRepDS_SHELL", TopOpeBRepDS_Kind::TopOpeBRepDS_SHELL)
		.value("TopOpeBRepDS_SOLID", TopOpeBRepDS_Kind::TopOpeBRepDS_SOLID)
		.value("TopOpeBRepDS_COMPSOLID", TopOpeBRepDS_Kind::TopOpeBRepDS_COMPSOLID)
		.value("TopOpeBRepDS_COMPOUND", TopOpeBRepDS_Kind::TopOpeBRepDS_COMPOUND)
		.value("TopOpeBRepDS_UNKNOWN", TopOpeBRepDS_Kind::TopOpeBRepDS_UNKNOWN)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_CheckStatus.hxx
	py::enum_<TopOpeBRepDS_CheckStatus>(mod, "TopOpeBRepDS_CheckStatus", "None")
		.value("TopOpeBRepDS_OK", TopOpeBRepDS_CheckStatus::TopOpeBRepDS_OK)
		.value("TopOpeBRepDS_NOK", TopOpeBRepDS_CheckStatus::TopOpeBRepDS_NOK)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_connex.hxx
	mod.def("FDSCNX_EdgeConnexityShapeIndex", (const TopTools_ListOfShape & (*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Integer)) &FDSCNX_EdgeConnexityShapeIndex, "None", py::arg("E"), py::arg("HDS"), py::arg("SI"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_connex.hxx
	mod.def("FDSCNX_EdgeConnexitySameShape", (const TopTools_ListOfShape & (*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FDSCNX_EdgeConnexitySameShape, "None", py::arg("E"), py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_connex.hxx
	mod.def("FDSCNX_Prepare", (void (*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FDSCNX_Prepare, "None", py::arg("S1"), py::arg("S2"), py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_connex.hxx
	mod.def("FDSCNX_HasConnexFace", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FDSCNX_HasConnexFace, "None", py::arg("S"), py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_connex.hxx
	mod.def("FDSCNX_FaceEdgeConnexFaces", (void (*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &, TopTools_ListOfShape &)) &FDSCNX_FaceEdgeConnexFaces, "None", py::arg("F"), py::arg("E"), py::arg("HDS"), py::arg("LF"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_connex.hxx
	mod.def("FDSCNX_Dump", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Integer)) &FDSCNX_Dump, "None", py::arg("HDS"), py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_connex.hxx
	mod.def("FDSCNX_DumpIndex", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Integer)) &FDSCNX_DumpIndex, "None", py::arg("HDS"), py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_scanloi", (void (*)(const TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &, Standard_Integer &, TopOpeBRepDS_ListOfInterference &, Standard_Integer &, TopOpeBRepDS_ListOfInterference &, Standard_Integer &)) &FUN_scanloi, "None", py::arg("lII"), py::arg("lFOR"), py::arg("FOR"), py::arg("lREV"), py::arg("REV"), py::arg("lINT"), py::arg("INT"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_redu2d1d", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const Standard_Integer, const opencascade::handle<TopOpeBRepDS_Interference> &, const TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_Transition &)) &FUN_ds_redu2d1d, "None", py::arg("BDS"), py::arg("ISE"), py::arg("I2d"), py::arg("l1d"), py::arg("newT2d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_GetTr", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const Standard_Integer, const Standard_Integer, const TopOpeBRepDS_ListOfInterference &, TopAbs_State &, Standard_Integer &, Standard_Integer &, TopAbs_State &, Standard_Integer &, Standard_Integer &)) &FUN_ds_GetTr, "None", py::arg("BDS"), py::arg("ISE"), py::arg("G"), py::arg("LIG"), py::arg("stb"), py::arg("isb"), py::arg("bdim"), py::arg("sta"), py::arg("isa"), py::arg("adim"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_SetT", (void (*)(TopOpeBRepDS_Transition &, const TopOpeBRepDS_Transition &)) &FDS_SetT, "None", py::arg("T"), py::arg("T0"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_hasUNK", (Standard_Boolean (*)(const TopOpeBRepDS_Transition &)) &FDS_hasUNK, "None", py::arg("T"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_copy", (void (*)(const TopTools_ListOfShape &, TopTools_ListOfShape &)) &FDS_copy, "None", py::arg("LI"), py::arg("LII"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_assign", (void (*)(const TopTools_ListOfShape &, TopTools_ListOfShape &)) &FDS_assign, "None", py::arg("LI"), py::arg("LII"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_samRk", (void (*)(const TopOpeBRepDS_DataStructure &, const Standard_Integer, TopTools_ListOfShape &, TopTools_ListOfShape &)) &FUN_ds_samRk, "None", py::arg("BDS"), py::arg("Rk"), py::arg("LI"), py::arg("LIsrk"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_data", (Standard_Boolean (*)(const TopOpeBRepDS_ListIteratorOfListOfInterference &, opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_Kind &, Standard_Integer &, TopOpeBRepDS_Kind &, Standard_Integer &)) &FDS_data, "None", py::arg("it"), py::arg("I"), py::arg("GT1"), py::arg("G1"), py::arg("ST1"), py::arg("S1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_Tdata", (void (*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopAbs_ShapeEnum &, Standard_Integer &, TopAbs_ShapeEnum &, Standard_Integer &)) &FDS_Tdata, "None", py::arg("I"), py::arg("SB"), py::arg("IB"), py::arg("SA"), py::arg("IA"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_Idata", (void (*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopAbs_ShapeEnum &, Standard_Integer &, TopAbs_ShapeEnum &, Standard_Integer &, TopOpeBRepDS_Kind &, Standard_Integer &, TopOpeBRepDS_Kind &, Standard_Integer &)) &FDS_Idata, "None", py::arg("I"), py::arg("SB"), py::arg("IB"), py::arg("SA"), py::arg("IA"), py::arg("GT1"), py::arg("G1"), py::arg("ST1"), py::arg("S1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_getVsdm", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const Standard_Integer, Standard_Integer &)) &FUN_ds_getVsdm, "None", py::arg("BDS"), py::arg("iV"), py::arg("iVsdm"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_sdm", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const TopoDS_Shape &, const TopoDS_Shape &)) &FUN_ds_sdm, "None", py::arg("BDS"), py::arg("s1"), py::arg("s2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_aresamdom", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &FDS_aresamdom, "None", py::arg("BDS"), py::arg("SI"), py::arg("isb1"), py::arg("isb2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_EdgeIsConnexToSameDomainFaces", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FDS_EdgeIsConnexToSameDomainFaces, "None", py::arg("E"), py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_SIisGIofIofSBAofTofI", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const Standard_Integer, const opencascade::handle<TopOpeBRepDS_Interference> &)) &FDS_SIisGIofIofSBAofTofI, "None", py::arg("BDS"), py::arg("SI"), py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_Parameter", (Standard_Boolean (*)(const opencascade::handle<TopOpeBRepDS_Interference> &, Standard_Real &)) &FDS_Parameter, "None", py::arg("I"), py::arg("par"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_HasSameDomain3d", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const TopoDS_Shape &, TopTools_ListOfShape *)) &FDS_HasSameDomain3d, "None", py::arg("BDS"), py::arg("E"), py::arg("PLSD") = (TopTools_ListOfShape *) nullptr);

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_Config3d", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &, TopOpeBRepDS_Config &)) &FDS_Config3d, "None", py::arg("E1"), py::arg("E2"), py::arg("c"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_HasSameDomain2d", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const TopoDS_Shape &, TopTools_ListOfShape *)) &FDS_HasSameDomain2d, "None", py::arg("BDS"), py::arg("E"), py::arg("PLSD") = (TopTools_ListOfShape *) nullptr);

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_getupperlower", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Integer, const Standard_Real, Standard_Real &, Standard_Real &)) &FDS_getupperlower, "None", py::arg("HDS"), py::arg("edgeIndex"), py::arg("paredge"), py::arg("p1"), py::arg("p2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_getoov", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &, TopoDS_Shape &)) &FUN_ds_getoov, "None", py::arg("v"), py::arg("HDS"), py::arg("oov"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_selectTRAINTinterference", (Standard_Boolean (*)(const TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &)) &FUN_selectTRAINTinterference, "None", py::arg("li"), py::arg("liINTERNAL"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_completeforSE1", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_completeforSE1, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_completeforSE2", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_completeforSE2, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_completeforSE3", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_completeforSE3, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_completeforSE4", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_completeforSE4, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_completeforSE5", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_completeforSE5, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_completeforSE6", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_completeforSE6, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_completeforE7", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_completeforE7, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_completeforSE8", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_completeforSE8, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_PURGEforE9", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_PURGEforE9, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_completeforSE9", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_completeforSE9, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_complete1dForSESDM", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_complete1dForSESDM, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_redusamsha", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_redusamsha, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_shareG", (Standard_Boolean (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TopoDS_Edge &, Standard_Boolean &)) &FUN_ds_shareG, "None", py::arg("HDS"), py::arg("iF1"), py::arg("iF2"), py::arg("iE2"), py::arg("Esp"), py::arg("shareG"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_mkTonFsdm", (Standard_Boolean (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const TopoDS_Edge &, const Standard_Boolean, TopOpeBRepDS_Transition &)) &FUN_ds_mkTonFsdm, "None", py::arg("HDS"), py::arg("iF1"), py::arg("iF2"), py::arg("iE2"), py::arg("iEG"), py::arg("paronEG"), py::arg("Esp"), py::arg("pardef"), py::arg("T"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_oriEinF", (Standard_Integer (*)(const TopOpeBRepDS_DataStructure &, const TopoDS_Edge &, const TopoDS_Shape &, TopAbs_Orientation &)) &FUN_ds_oriEinF, "None", py::arg("BDS"), py::arg("E"), py::arg("F"), py::arg("O"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_FillSDMFaces", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_FillSDMFaces, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_addSEsdm1d", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_addSEsdm1d, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_hasI2d", (Standard_Integer (*)(const Standard_Integer, const TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &)) &FUN_ds_hasI2d, "None", py::arg("EIX"), py::arg("LI"), py::arg("LI2d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_PointToVertex", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FUN_ds_PointToVertex, "None", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_hasFEI", (Standard_Boolean (*)(const TopOpeBRepDS_PDataStructure &, const TopoDS_Shape &, const Standard_Integer, const Standard_Integer)) &FUN_ds_hasFEI, "None", py::arg("pDS2d"), py::arg("F"), py::arg("GI"), py::arg("ITRA"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_ONesd", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const Standard_Integer, const TopoDS_Shape &, Standard_Integer &)) &FUN_ds_ONesd, "None", py::arg("BDS"), py::arg("IE"), py::arg("EspON"), py::arg("IEsd"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_stateEwithF2d", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const TopoDS_Edge &, const Standard_Real, const TopOpeBRepDS_Kind, const Standard_Integer, const TopoDS_Face &, TopOpeBRepDS_Transition &)) &FDS_stateEwithF2d, "None", py::arg("BDS"), py::arg("E"), py::arg("pE"), py::arg("KDS"), py::arg("GDS"), py::arg("F1"), py::arg("TrmemeS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_parbefaft", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const TopoDS_Edge &, const Standard_Real, const Standard_Real &, const Standard_Real &, const Standard_Boolean &, Standard_Real &, Standard_Real &)) &FDS_parbefaft, "None", py::arg("BDS"), py::arg("E"), py::arg("pE"), py::arg("pbef"), py::arg("paft"), py::arg("isonboundper"), py::arg("p1"), py::arg("p2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FDS_LOIinfsup", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const TopoDS_Edge &, const Standard_Real, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_ListOfInterference &, Standard_Real &, Standard_Real &, Standard_Boolean &)) &FDS_LOIinfsup, "None", py::arg("BDS"), py::arg("E"), py::arg("pE"), py::arg("KDS"), py::arg("GDS"), py::arg("LOI"), py::arg("pbef"), py::arg("paft"), py::arg("isonboundper"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EXPORT.hxx
	mod.def("FUN_ds_FEIGb1TO0", (void (*)(opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &FUN_ds_FEIGb1TO0, "None", py::arg("HDS"), py::arg("MEspON"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("MakeCPVInterference", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Real, const TopOpeBRepDS_Kind)) &MakeCPVInterference, "None", py::arg("T"), py::arg("S"), py::arg("G"), py::arg("P"), py::arg("GK"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("MakeEPVInterference", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Real, const TopOpeBRepDS_Kind, const TopOpeBRepDS_Kind, const Standard_Boolean)) &MakeEPVInterference, "None", py::arg("T"), py::arg("S"), py::arg("G"), py::arg("P"), py::arg("GK"), py::arg("SK"), py::arg("B"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_hasStateShape", (Standard_Boolean (*)(const TopOpeBRepDS_Transition &, const TopAbs_State, const TopAbs_ShapeEnum)) &FUN_hasStateShape, "None", py::arg("T"), py::arg("state"), py::arg("shape"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_selectTRASHAinterference", (Standard_Integer (*)(TopOpeBRepDS_ListOfInterference &, const TopAbs_ShapeEnum, TopOpeBRepDS_ListOfInterference &)) &FUN_selectTRASHAinterference, "None", py::arg("L1"), py::arg("sha"), py::arg("L2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_selectITRASHAinterference", (Standard_Integer (*)(TopOpeBRepDS_ListOfInterference &, const Standard_Integer, TopOpeBRepDS_ListOfInterference &)) &FUN_selectITRASHAinterference, "None", py::arg("L1"), py::arg("Index"), py::arg("L2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_selectTRAUNKinterference", (Standard_Integer (*)(TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &)) &FUN_selectTRAUNKinterference, "None", py::arg("L1"), py::arg("L2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_selectTRAORIinterference", (Standard_Integer (*)(TopOpeBRepDS_ListOfInterference &, const TopAbs_Orientation, TopOpeBRepDS_ListOfInterference &)) &FUN_selectTRAORIinterference, "None", py::arg("L1"), py::arg("O"), py::arg("L2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_selectGKinterference", (Standard_Integer (*)(TopOpeBRepDS_ListOfInterference &, const TopOpeBRepDS_Kind, TopOpeBRepDS_ListOfInterference &)) &FUN_selectGKinterference, "None", py::arg("L1"), py::arg("GK"), py::arg("L2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_selectSKinterference", (Standard_Integer (*)(TopOpeBRepDS_ListOfInterference &, const TopOpeBRepDS_Kind, TopOpeBRepDS_ListOfInterference &)) &FUN_selectSKinterference, "None", py::arg("L1"), py::arg("SK"), py::arg("L2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_selectGIinterference", (Standard_Integer (*)(TopOpeBRepDS_ListOfInterference &, const Standard_Integer, TopOpeBRepDS_ListOfInterference &)) &FUN_selectGIinterference, "None", py::arg("L1"), py::arg("GI"), py::arg("L2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_selectSIinterference", (Standard_Integer (*)(TopOpeBRepDS_ListOfInterference &, const Standard_Integer, TopOpeBRepDS_ListOfInterference &)) &FUN_selectSIinterference, "None", py::arg("L1"), py::arg("SI"), py::arg("L2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_interfhassupport", (Standard_Boolean (*)(const TopOpeBRepDS_DataStructure &, const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &)) &FUN_interfhassupport, "None", py::arg("DS"), py::arg("I"), py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_transitionEQUAL", (Standard_Boolean (*)(const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Transition &)) &FUN_transitionEQUAL, "None", py::arg(""), py::arg(""));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_transitionSTATEEQUAL", (Standard_Boolean (*)(const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Transition &)) &FUN_transitionSTATEEQUAL, "None", py::arg(""), py::arg(""));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_transitionSHAPEEQUAL", (Standard_Boolean (*)(const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Transition &)) &FUN_transitionSHAPEEQUAL, "None", py::arg(""), py::arg(""));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_transitionINDEXEQUAL", (Standard_Boolean (*)(const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Transition &)) &FUN_transitionINDEXEQUAL, "None", py::arg(""), py::arg(""));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_reducedoublons", (void (*)(TopOpeBRepDS_ListOfInterference &, const TopOpeBRepDS_DataStructure &, const Standard_Integer)) &FUN_reducedoublons, "None", py::arg("LI"), py::arg("BDS"), py::arg("SIX"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_unkeepUNKNOWN", (void (*)(TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_DataStructure &, const Standard_Integer)) &FUN_unkeepUNKNOWN, "None", py::arg("LI"), py::arg("BDS"), py::arg("SIX"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_select2dI", (Standard_Integer (*)(const Standard_Integer, TopOpeBRepDS_DataStructure &, const TopAbs_ShapeEnum, TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &)) &FUN_select2dI, "None", py::arg("SIX"), py::arg("BDS"), py::arg("TRASHAk"), py::arg("lI"), py::arg("l2dI"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_selectpure2dI", (Standard_Integer (*)(const TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &)) &FUN_selectpure2dI, "None", py::arg("lF"), py::arg("lFE"), py::arg("l2dFE"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_select1dI", (Standard_Integer (*)(const Standard_Integer, TopOpeBRepDS_DataStructure &, TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &)) &FUN_select1dI, "None", py::arg("SIX"), py::arg("BDS"), py::arg("LI"), py::arg("l1dI"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ProcessInterferencesTool.hxx
	mod.def("FUN_select3dinterference", (void (*)(const Standard_Integer, TopOpeBRepDS_DataStructure &, TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &)) &FUN_select3dinterference, "None", py::arg("SIX"), py::arg("BDS"), py::arg("lF"), py::arg("l3dF"), py::arg("lFE"), py::arg("lFEresi"), py::arg("l3dFE"), py::arg("l3dFEresi"), py::arg("l2dFE"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_repvg.hxx
	mod.def("FDS_repvg", (void (*)(const TopOpeBRepDS_DataStructure &, const Standard_Integer, const TopOpeBRepDS_Kind, TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &)) &FDS_repvg, "None", py::arg("BDS"), py::arg("EIX"), py::arg("GT"), py::arg("LI"), py::arg("reducedLI"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_repvg.hxx
	mod.def("FDS_repvg2", (void (*)(const TopOpeBRepDS_DataStructure &, const Standard_Integer, const TopOpeBRepDS_Kind, TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &)) &FDS_repvg2, "None", py::arg("BDS"), py::arg("EIX"), py::arg("GT"), py::arg("LI"), py::arg("reducedLI"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_samdom.hxx
	mod.def("FDSSDM_prepare", (void (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &FDSSDM_prepare, "None", py::arg(""));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_samdom.hxx
	mod.def("FDSSDM_makes1s2", (void (*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &FDSSDM_makes1s2, "None", py::arg("S"), py::arg("L1"), py::arg("L2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_samdom.hxx
	mod.def("FDSSDM_s1s2makesordor", (void (*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &FDSSDM_s1s2makesordor, "None", py::arg("L1"), py::arg("L2"), py::arg("S"), py::arg("LSO"), py::arg("LDO"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_samdom.hxx
	mod.def("FDSSDM_s1s2", (void (*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &FDSSDM_s1s2, "None", py::arg("S"), py::arg("LS1"), py::arg("LS2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_samdom.hxx
	mod.def("FDSSDM_sordor", (void (*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &FDSSDM_sordor, "None", py::arg("S"), py::arg("LSO"), py::arg("LDO"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_samdom.hxx
	mod.def("FDSSDM_contains", (Standard_Boolean (*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &FDSSDM_contains, "None", py::arg("S"), py::arg("L"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_samdom.hxx
	mod.def("FDSSDM_copylist", (void (*)(const TopTools_ListOfShape &, TopTools_ListOfShape &)) &FDSSDM_copylist, "None", py::arg("Lin"), py::arg("Lou"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Transition.hxx
	py::class_<TopOpeBRepDS_Transition, std::unique_ptr<TopOpeBRepDS_Transition, Deleter<TopOpeBRepDS_Transition>>> cls_TopOpeBRepDS_Transition(mod, "TopOpeBRepDS_Transition", "None");
	cls_TopOpeBRepDS_Transition.def(py::init<>());
	cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_State, const TopAbs_State>(), py::arg("StateBefore"), py::arg("StateAfter"));
	cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_State, const TopAbs_State, const TopAbs_ShapeEnum>(), py::arg("StateBefore"), py::arg("StateAfter"), py::arg("ShapeBefore"));
	cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_State, const TopAbs_State, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum>(), py::arg("StateBefore"), py::arg("StateAfter"), py::arg("ShapeBefore"), py::arg("ShapeAfter"));
	cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_Orientation>(), py::arg("O"));
	cls_TopOpeBRepDS_Transition.def("Set", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0, const TopAbs_State a1) -> void { return self.Set(a0, a1); }, py::arg("StateBefore"), py::arg("StateAfter"));
	cls_TopOpeBRepDS_Transition.def("Set", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0, const TopAbs_State a1, const TopAbs_ShapeEnum a2) -> void { return self.Set(a0, a1, a2); }, py::arg("StateBefore"), py::arg("StateAfter"), py::arg("ShapeBefore"));
	cls_TopOpeBRepDS_Transition.def("Set", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_State, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::Set, "None", py::arg("StateBefore"), py::arg("StateAfter"), py::arg("ShapeBefore"), py::arg("ShapeAfter"));
	cls_TopOpeBRepDS_Transition.def("StateBefore", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State)) &TopOpeBRepDS_Transition::StateBefore, "None", py::arg("S"));
	cls_TopOpeBRepDS_Transition.def("StateAfter", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State)) &TopOpeBRepDS_Transition::StateAfter, "None", py::arg("S"));
	cls_TopOpeBRepDS_Transition.def("ShapeBefore", (void (TopOpeBRepDS_Transition::*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::ShapeBefore, "None", py::arg("SE"));
	cls_TopOpeBRepDS_Transition.def("ShapeAfter", (void (TopOpeBRepDS_Transition::*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::ShapeAfter, "None", py::arg("SE"));
	cls_TopOpeBRepDS_Transition.def("Before", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0) -> void { return self.Before(a0); }, py::arg("S"));
	cls_TopOpeBRepDS_Transition.def("Before", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::Before, "None", py::arg("S"), py::arg("ShapeBefore"));
	cls_TopOpeBRepDS_Transition.def("After", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0) -> void { return self.After(a0); }, py::arg("S"));
	cls_TopOpeBRepDS_Transition.def("After", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::After, "None", py::arg("S"), py::arg("ShapeAfter"));
	cls_TopOpeBRepDS_Transition.def("Index", (void (TopOpeBRepDS_Transition::*)(const Standard_Integer)) &TopOpeBRepDS_Transition::Index, "None", py::arg("I"));
	cls_TopOpeBRepDS_Transition.def("IndexBefore", (void (TopOpeBRepDS_Transition::*)(const Standard_Integer)) &TopOpeBRepDS_Transition::IndexBefore, "None", py::arg("I"));
	cls_TopOpeBRepDS_Transition.def("IndexAfter", (void (TopOpeBRepDS_Transition::*)(const Standard_Integer)) &TopOpeBRepDS_Transition::IndexAfter, "None", py::arg("I"));
	cls_TopOpeBRepDS_Transition.def("Before", (TopAbs_State (TopOpeBRepDS_Transition::*)() const ) &TopOpeBRepDS_Transition::Before, "None");
	cls_TopOpeBRepDS_Transition.def("ONBefore", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const ) &TopOpeBRepDS_Transition::ONBefore, "None");
	cls_TopOpeBRepDS_Transition.def("After", (TopAbs_State (TopOpeBRepDS_Transition::*)() const ) &TopOpeBRepDS_Transition::After, "None");
	cls_TopOpeBRepDS_Transition.def("ONAfter", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const ) &TopOpeBRepDS_Transition::ONAfter, "None");
	cls_TopOpeBRepDS_Transition.def("ShapeBefore", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const ) &TopOpeBRepDS_Transition::ShapeBefore, "None");
	cls_TopOpeBRepDS_Transition.def("ShapeAfter", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const ) &TopOpeBRepDS_Transition::ShapeAfter, "None");
	cls_TopOpeBRepDS_Transition.def("Index", (Standard_Integer (TopOpeBRepDS_Transition::*)() const ) &TopOpeBRepDS_Transition::Index, "None");
	cls_TopOpeBRepDS_Transition.def("IndexBefore", (Standard_Integer (TopOpeBRepDS_Transition::*)() const ) &TopOpeBRepDS_Transition::IndexBefore, "None");
	cls_TopOpeBRepDS_Transition.def("IndexAfter", (Standard_Integer (TopOpeBRepDS_Transition::*)() const ) &TopOpeBRepDS_Transition::IndexAfter, "None");
	cls_TopOpeBRepDS_Transition.def("Set", (void (TopOpeBRepDS_Transition::*)(const TopAbs_Orientation)) &TopOpeBRepDS_Transition::Set, "set the transition corresponding to orientation <O>", py::arg("O"));
	cls_TopOpeBRepDS_Transition.def("Orientation", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0) -> TopAbs_Orientation { return self.Orientation(a0); }, py::arg("S"));
	cls_TopOpeBRepDS_Transition.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_ShapeEnum) const ) &TopOpeBRepDS_Transition::Orientation, "returns the orientation corresponding to state <S>", py::arg("S"), py::arg("T"));
	cls_TopOpeBRepDS_Transition.def("Complement", (TopOpeBRepDS_Transition (TopOpeBRepDS_Transition::*)() const ) &TopOpeBRepDS_Transition::Complement, "None");
	cls_TopOpeBRepDS_Transition.def("IsUnknown", (Standard_Boolean (TopOpeBRepDS_Transition::*)() const ) &TopOpeBRepDS_Transition::IsUnknown, "returns True if both states are UNKNOWN");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Interference.hxx
	py::class_<TopOpeBRepDS_Interference, opencascade::handle<TopOpeBRepDS_Interference>, Standard_Transient> cls_TopOpeBRepDS_Interference(mod, "TopOpeBRepDS_Interference", "An interference is the description of the attachment of a new geometry on a geometry. For example an intersection point on an Edge or on a Curve.");
	cls_TopOpeBRepDS_Interference.def(py::init<>());
	cls_TopOpeBRepDS_Interference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer>(), py::arg("Transition"), py::arg("SupportType"), py::arg("Support"), py::arg("GeometryType"), py::arg("Geometry"));
	cls_TopOpeBRepDS_Interference.def(py::init<const opencascade::handle<TopOpeBRepDS_Interference> &>(), py::arg("I"));
	cls_TopOpeBRepDS_Interference.def("Transition", (const TopOpeBRepDS_Transition & (TopOpeBRepDS_Interference::*)() const ) &TopOpeBRepDS_Interference::Transition, "None");
	cls_TopOpeBRepDS_Interference.def("ChangeTransition", (TopOpeBRepDS_Transition & (TopOpeBRepDS_Interference::*)()) &TopOpeBRepDS_Interference::ChangeTransition, "None");
	cls_TopOpeBRepDS_Interference.def("Transition", (void (TopOpeBRepDS_Interference::*)(const TopOpeBRepDS_Transition &)) &TopOpeBRepDS_Interference::Transition, "None", py::arg("T"));
	cls_TopOpeBRepDS_Interference.def("GKGSKS", (void (TopOpeBRepDS_Interference::*)(TopOpeBRepDS_Kind &, Standard_Integer &, TopOpeBRepDS_Kind &, Standard_Integer &) const ) &TopOpeBRepDS_Interference::GKGSKS, "return GeometryType + Geometry + SupportType + Support", py::arg("GK"), py::arg("G"), py::arg("SK"), py::arg("S"));
	cls_TopOpeBRepDS_Interference.def("SupportType", (TopOpeBRepDS_Kind (TopOpeBRepDS_Interference::*)() const ) &TopOpeBRepDS_Interference::SupportType, "None");
	cls_TopOpeBRepDS_Interference.def("Support", (Standard_Integer (TopOpeBRepDS_Interference::*)() const ) &TopOpeBRepDS_Interference::Support, "None");
	cls_TopOpeBRepDS_Interference.def("GeometryType", (TopOpeBRepDS_Kind (TopOpeBRepDS_Interference::*)() const ) &TopOpeBRepDS_Interference::GeometryType, "None");
	cls_TopOpeBRepDS_Interference.def("Geometry", (Standard_Integer (TopOpeBRepDS_Interference::*)() const ) &TopOpeBRepDS_Interference::Geometry, "None");
	cls_TopOpeBRepDS_Interference.def("SetGeometry", (void (TopOpeBRepDS_Interference::*)(const Standard_Integer)) &TopOpeBRepDS_Interference::SetGeometry, "None", py::arg("GI"));
	cls_TopOpeBRepDS_Interference.def("SupportType", (void (TopOpeBRepDS_Interference::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_Interference::SupportType, "None", py::arg("ST"));
	cls_TopOpeBRepDS_Interference.def("Support", (void (TopOpeBRepDS_Interference::*)(const Standard_Integer)) &TopOpeBRepDS_Interference::Support, "None", py::arg("S"));
	cls_TopOpeBRepDS_Interference.def("GeometryType", (void (TopOpeBRepDS_Interference::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_Interference::GeometryType, "None", py::arg("GT"));
	cls_TopOpeBRepDS_Interference.def("Geometry", (void (TopOpeBRepDS_Interference::*)(const Standard_Integer)) &TopOpeBRepDS_Interference::Geometry, "None", py::arg("G"));
	cls_TopOpeBRepDS_Interference.def("HasSameSupport", (Standard_Boolean (TopOpeBRepDS_Interference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_Interference::HasSameSupport, "None", py::arg("Other"));
	cls_TopOpeBRepDS_Interference.def("HasSameGeometry", (Standard_Boolean (TopOpeBRepDS_Interference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_Interference::HasSameGeometry, "None", py::arg("Other"));
	cls_TopOpeBRepDS_Interference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Interference::get_type_name, "None");
	cls_TopOpeBRepDS_Interference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Interference::get_type_descriptor, "None");
	cls_TopOpeBRepDS_Interference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Interference::*)() const ) &TopOpeBRepDS_Interference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ShapeShapeInterference.hxx
	py::class_<TopOpeBRepDS_ShapeShapeInterference, opencascade::handle<TopOpeBRepDS_ShapeShapeInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_ShapeShapeInterference(mod, "TopOpeBRepDS_ShapeShapeInterference", "Interference");
	cls_TopOpeBRepDS_ShapeShapeInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config>(), py::arg("T"), py::arg("ST"), py::arg("S"), py::arg("GT"), py::arg("G"), py::arg("GBound"), py::arg("C"));
	cls_TopOpeBRepDS_ShapeShapeInterference.def("Config", (TopOpeBRepDS_Config (TopOpeBRepDS_ShapeShapeInterference::*)() const ) &TopOpeBRepDS_ShapeShapeInterference::Config, "None");
	cls_TopOpeBRepDS_ShapeShapeInterference.def("GBound", (Standard_Boolean (TopOpeBRepDS_ShapeShapeInterference::*)() const ) &TopOpeBRepDS_ShapeShapeInterference::GBound, "None");
	cls_TopOpeBRepDS_ShapeShapeInterference.def("SetGBound", (void (TopOpeBRepDS_ShapeShapeInterference::*)(const Standard_Boolean)) &TopOpeBRepDS_ShapeShapeInterference::SetGBound, "None", py::arg("b"));
	cls_TopOpeBRepDS_ShapeShapeInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_ShapeShapeInterference::get_type_name, "None");
	cls_TopOpeBRepDS_ShapeShapeInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_ShapeShapeInterference::get_type_descriptor, "None");
	cls_TopOpeBRepDS_ShapeShapeInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_ShapeShapeInterference::*)() const ) &TopOpeBRepDS_ShapeShapeInterference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_CurvePointInterference.hxx
	py::class_<TopOpeBRepDS_CurvePointInterference, opencascade::handle<TopOpeBRepDS_CurvePointInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_CurvePointInterference(mod, "TopOpeBRepDS_CurvePointInterference", "An interference with a parameter.");
	cls_TopOpeBRepDS_CurvePointInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Real>(), py::arg("T"), py::arg("ST"), py::arg("S"), py::arg("GT"), py::arg("G"), py::arg("P"));
	cls_TopOpeBRepDS_CurvePointInterference.def("Parameter", (Standard_Real (TopOpeBRepDS_CurvePointInterference::*)() const ) &TopOpeBRepDS_CurvePointInterference::Parameter, "None");
	cls_TopOpeBRepDS_CurvePointInterference.def("Parameter", (void (TopOpeBRepDS_CurvePointInterference::*)(const Standard_Real)) &TopOpeBRepDS_CurvePointInterference::Parameter, "None", py::arg("P"));
	cls_TopOpeBRepDS_CurvePointInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_CurvePointInterference::get_type_name, "None");
	cls_TopOpeBRepDS_CurvePointInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_CurvePointInterference::get_type_descriptor, "None");
	cls_TopOpeBRepDS_CurvePointInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_CurvePointInterference::*)() const ) &TopOpeBRepDS_CurvePointInterference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EdgeVertexInterference.hxx
	py::class_<TopOpeBRepDS_EdgeVertexInterference, opencascade::handle<TopOpeBRepDS_EdgeVertexInterference>, TopOpeBRepDS_ShapeShapeInterference> cls_TopOpeBRepDS_EdgeVertexInterference(mod, "TopOpeBRepDS_EdgeVertexInterference", "An interference with a parameter (ShapeShapeInterference).");
	cls_TopOpeBRepDS_EdgeVertexInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config, const Standard_Real>(), py::arg("T"), py::arg("ST"), py::arg("S"), py::arg("G"), py::arg("GIsBound"), py::arg("C"), py::arg("P"));
	cls_TopOpeBRepDS_EdgeVertexInterference.def(py::init<const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config, const Standard_Real>(), py::arg("T"), py::arg("S"), py::arg("G"), py::arg("GIsBound"), py::arg("C"), py::arg("P"));
	cls_TopOpeBRepDS_EdgeVertexInterference.def("Parameter", (Standard_Real (TopOpeBRepDS_EdgeVertexInterference::*)() const ) &TopOpeBRepDS_EdgeVertexInterference::Parameter, "None");
	cls_TopOpeBRepDS_EdgeVertexInterference.def("Parameter", (void (TopOpeBRepDS_EdgeVertexInterference::*)(const Standard_Real)) &TopOpeBRepDS_EdgeVertexInterference::Parameter, "None", py::arg("P"));
	cls_TopOpeBRepDS_EdgeVertexInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_EdgeVertexInterference::get_type_name, "None");
	cls_TopOpeBRepDS_EdgeVertexInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_EdgeVertexInterference::get_type_descriptor, "None");
	cls_TopOpeBRepDS_EdgeVertexInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_EdgeVertexInterference::*)() const ) &TopOpeBRepDS_EdgeVertexInterference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_FaceEdgeInterference.hxx
	py::class_<TopOpeBRepDS_FaceEdgeInterference, opencascade::handle<TopOpeBRepDS_FaceEdgeInterference>, TopOpeBRepDS_ShapeShapeInterference> cls_TopOpeBRepDS_FaceEdgeInterference(mod, "TopOpeBRepDS_FaceEdgeInterference", "ShapeShapeInterference");
	cls_TopOpeBRepDS_FaceEdgeInterference.def(py::init<const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config>(), py::arg("T"), py::arg("S"), py::arg("G"), py::arg("GIsBound"), py::arg("C"));
	cls_TopOpeBRepDS_FaceEdgeInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_FaceEdgeInterference::get_type_name, "None");
	cls_TopOpeBRepDS_FaceEdgeInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_FaceEdgeInterference::get_type_descriptor, "None");
	cls_TopOpeBRepDS_FaceEdgeInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_FaceEdgeInterference::*)() const ) &TopOpeBRepDS_FaceEdgeInterference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_InterferenceIterator.hxx
	py::class_<TopOpeBRepDS_InterferenceIterator, std::unique_ptr<TopOpeBRepDS_InterferenceIterator, Deleter<TopOpeBRepDS_InterferenceIterator>>> cls_TopOpeBRepDS_InterferenceIterator(mod, "TopOpeBRepDS_InterferenceIterator", "Iterate on interferences of a list, matching conditions on interferences. Nota : inheritance of ListIteratorOfListOfInterference from TopOpeBRepDS has not been done because of the impossibility of naming the classical More, Next methods which are declared as static in TCollection_ListIteratorOfList ... . ListIteratorOfList has benn placed as a field of InterferenceIterator.");
	cls_TopOpeBRepDS_InterferenceIterator.def(py::init<>());
	cls_TopOpeBRepDS_InterferenceIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));
	cls_TopOpeBRepDS_InterferenceIterator.def("Init", (void (TopOpeBRepDS_InterferenceIterator::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_InterferenceIterator::Init, "re-initialize interference iteration process on the list of interference <L>. Conditions are not modified.", py::arg("L"));
	cls_TopOpeBRepDS_InterferenceIterator.def("GeometryKind", (void (TopOpeBRepDS_InterferenceIterator::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_InterferenceIterator::GeometryKind, "define a condition on interference iteration process. Interference must match the Geometry Kind <ST>", py::arg("GK"));
	cls_TopOpeBRepDS_InterferenceIterator.def("Geometry", (void (TopOpeBRepDS_InterferenceIterator::*)(const Standard_Integer)) &TopOpeBRepDS_InterferenceIterator::Geometry, "define a condition on interference iteration process. Interference must match the Geometry <G>", py::arg("G"));
	cls_TopOpeBRepDS_InterferenceIterator.def("SupportKind", (void (TopOpeBRepDS_InterferenceIterator::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_InterferenceIterator::SupportKind, "define a condition on interference iteration process. Interference must match the Support Kind <ST>", py::arg("ST"));
	cls_TopOpeBRepDS_InterferenceIterator.def("Support", (void (TopOpeBRepDS_InterferenceIterator::*)(const Standard_Integer)) &TopOpeBRepDS_InterferenceIterator::Support, "define a condition on interference iteration process. Interference must match the Support <S>", py::arg("S"));
	cls_TopOpeBRepDS_InterferenceIterator.def("Match", (void (TopOpeBRepDS_InterferenceIterator::*)()) &TopOpeBRepDS_InterferenceIterator::Match, "reach for an interference matching the conditions (if defined).");
	cls_TopOpeBRepDS_InterferenceIterator.def("MatchInterference", (Standard_Boolean (TopOpeBRepDS_InterferenceIterator::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_InterferenceIterator::MatchInterference, "Returns True if the Interference <I> matches the conditions (if defined). If no conditions defined, returns True.", py::arg("I"));
	cls_TopOpeBRepDS_InterferenceIterator.def("More", (Standard_Boolean (TopOpeBRepDS_InterferenceIterator::*)() const ) &TopOpeBRepDS_InterferenceIterator::More, "Returns True if there is a current Interference in the iteration.");
	cls_TopOpeBRepDS_InterferenceIterator.def("Next", (void (TopOpeBRepDS_InterferenceIterator::*)()) &TopOpeBRepDS_InterferenceIterator::Next, "Move to the next Interference.");
	cls_TopOpeBRepDS_InterferenceIterator.def("Value", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_InterferenceIterator::*)() const ) &TopOpeBRepDS_InterferenceIterator::Value, "Returns the current Interference, matching the conditions (if defined).");
	cls_TopOpeBRepDS_InterferenceIterator.def("ChangeIterator", (TopOpeBRepDS_ListIteratorOfListOfInterference & (TopOpeBRepDS_InterferenceIterator::*)()) &TopOpeBRepDS_InterferenceIterator::ChangeIterator, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Surface.hxx
	py::class_<TopOpeBRepDS_Surface, std::unique_ptr<TopOpeBRepDS_Surface, Deleter<TopOpeBRepDS_Surface>>> cls_TopOpeBRepDS_Surface(mod, "TopOpeBRepDS_Surface", "A Geom surface and a tolerance.");
	cls_TopOpeBRepDS_Surface.def(py::init<>());
	cls_TopOpeBRepDS_Surface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("P"), py::arg("T"));
	cls_TopOpeBRepDS_Surface.def(py::init([] (const TopOpeBRepDS_Surface &other) {return new TopOpeBRepDS_Surface(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_Surface.def("Assign", (void (TopOpeBRepDS_Surface::*)(const TopOpeBRepDS_Surface &)) &TopOpeBRepDS_Surface::Assign, "None", py::arg("Other"));
	cls_TopOpeBRepDS_Surface.def("assign", (void (TopOpeBRepDS_Surface::*)(const TopOpeBRepDS_Surface &)) &TopOpeBRepDS_Surface::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_TopOpeBRepDS_Surface.def("Surface", (const opencascade::handle<Geom_Surface> & (TopOpeBRepDS_Surface::*)() const ) &TopOpeBRepDS_Surface::Surface, "None");
	cls_TopOpeBRepDS_Surface.def("Tolerance", (Standard_Real (TopOpeBRepDS_Surface::*)() const ) &TopOpeBRepDS_Surface::Tolerance, "None");
	cls_TopOpeBRepDS_Surface.def("Tolerance", (void (TopOpeBRepDS_Surface::*)(const Standard_Real)) &TopOpeBRepDS_Surface::Tolerance, "Update the tolerance", py::arg("tol"));
	cls_TopOpeBRepDS_Surface.def("Keep", (Standard_Boolean (TopOpeBRepDS_Surface::*)() const ) &TopOpeBRepDS_Surface::Keep, "None");
	cls_TopOpeBRepDS_Surface.def("ChangeKeep", (void (TopOpeBRepDS_Surface::*)(const Standard_Boolean)) &TopOpeBRepDS_Surface::ChangeKeep, "None", py::arg("B"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_GeometryData.hxx
	py::class_<TopOpeBRepDS_GeometryData, std::unique_ptr<TopOpeBRepDS_GeometryData, Deleter<TopOpeBRepDS_GeometryData>>> cls_TopOpeBRepDS_GeometryData(mod, "TopOpeBRepDS_GeometryData", "mother-class of SurfaceData, CurveData, PointData");
	cls_TopOpeBRepDS_GeometryData.def(py::init<>());
	cls_TopOpeBRepDS_GeometryData.def(py::init([] (const TopOpeBRepDS_GeometryData &other) {return new TopOpeBRepDS_GeometryData(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_GeometryData.def("Assign", (void (TopOpeBRepDS_GeometryData::*)(const TopOpeBRepDS_GeometryData &)) &TopOpeBRepDS_GeometryData::Assign, "None", py::arg("Other"));
	cls_TopOpeBRepDS_GeometryData.def("assign", (void (TopOpeBRepDS_GeometryData::*)(const TopOpeBRepDS_GeometryData &)) &TopOpeBRepDS_GeometryData::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_TopOpeBRepDS_GeometryData.def("Interferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GeometryData::*)() const ) &TopOpeBRepDS_GeometryData::Interferences, "None");
	cls_TopOpeBRepDS_GeometryData.def("ChangeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GeometryData::*)()) &TopOpeBRepDS_GeometryData::ChangeInterferences, "None");
	cls_TopOpeBRepDS_GeometryData.def("AddInterference", (void (TopOpeBRepDS_GeometryData::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_GeometryData::AddInterference, "None", py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_DataStructure.hxx
	py::class_<TopOpeBRepDS_DataStructure, std::unique_ptr<TopOpeBRepDS_DataStructure, Deleter<TopOpeBRepDS_DataStructure>>> cls_TopOpeBRepDS_DataStructure(mod, "TopOpeBRepDS_DataStructure", "The DataStructure stores :");
	cls_TopOpeBRepDS_DataStructure.def(py::init<>());
	cls_TopOpeBRepDS_DataStructure.def("Init", (void (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::Init, "reset the data structure");
	cls_TopOpeBRepDS_DataStructure.def("AddSurface", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Surface &)) &TopOpeBRepDS_DataStructure::AddSurface, "Insert a new surface. Returns the index.", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("RemoveSurface", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::RemoveSurface, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("KeepSurface", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::KeepSurface, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("KeepSurface", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Surface &) const ) &TopOpeBRepDS_DataStructure::KeepSurface, "None", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeKeepSurface", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepSurface, "None", py::arg("I"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeKeepSurface", (void (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Surface &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepSurface, "None", py::arg("S"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("AddCurve", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Curve &)) &TopOpeBRepDS_DataStructure::AddCurve, "Insert a new curve. Returns the index.", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("RemoveCurve", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::RemoveCurve, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("KeepCurve", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::KeepCurve, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("KeepCurve", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Curve &) const ) &TopOpeBRepDS_DataStructure::KeepCurve, "None", py::arg("C"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeKeepCurve", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepCurve, "None", py::arg("I"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeKeepCurve", (void (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Curve &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepCurve, "None", py::arg("C"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("AddPoint", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Point &)) &TopOpeBRepDS_DataStructure::AddPoint, "Insert a new point. Returns the index.", py::arg("PDS"));
	cls_TopOpeBRepDS_DataStructure.def("AddPointSS", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Point &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::AddPointSS, "Insert a new point. Returns the index.", py::arg("PDS"), py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRepDS_DataStructure.def("RemovePoint", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::RemovePoint, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("KeepPoint", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::KeepPoint, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("KeepPoint", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Point &) const ) &TopOpeBRepDS_DataStructure::KeepPoint, "None", py::arg("P"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeKeepPoint", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepPoint, "None", py::arg("I"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeKeepPoint", (void (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Point &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepPoint, "None", py::arg("P"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("AddShape", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::AddShape, "Insert a shape S. Returns the index.", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("AddShape", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::AddShape, "Insert a shape S which ancestor is I = 1 or 2. Returns the index.", py::arg("S"), py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("KeepShape", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> Standard_Boolean { return self.KeepShape(a0); }, py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("KeepShape", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const ) &TopOpeBRepDS_DataStructure::KeepShape, "None", py::arg("I"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("KeepShape", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.KeepShape(a0); }, py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("KeepShape", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const ) &TopOpeBRepDS_DataStructure::KeepShape, "None", py::arg("S"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeKeepShape", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepShape, "None", py::arg("I"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeKeepShape", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepShape, "None", py::arg("S"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("InitSectionEdges", (void (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::InitSectionEdges, "None");
	cls_TopOpeBRepDS_DataStructure.def("AddSectionEdge", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Edge &)) &TopOpeBRepDS_DataStructure::AddSectionEdge, "None", py::arg("E"));
	cls_TopOpeBRepDS_DataStructure.def("SurfaceInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::SurfaceInterferences, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeSurfaceInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeSurfaceInterferences, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("CurveInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::CurveInterferences, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeCurveInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeCurveInterferences, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("PointInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::PointInterferences, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("ChangePointInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangePointInterferences, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> const TopOpeBRepDS_ListOfInterference & { return self.ShapeInterferences(a0); }, py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const ) &TopOpeBRepDS_DataStructure::ShapeInterferences, "None", py::arg("S"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeShapeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::ChangeShapeInterferences, "None", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> const TopOpeBRepDS_ListOfInterference & { return self.ShapeInterferences(a0); }, py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const ) &TopOpeBRepDS_DataStructure::ShapeInterferences, "None", py::arg("I"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeShapeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeShapeInterferences, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("ShapeSameDomain", (const TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataStructure::ShapeSameDomain, "None", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeShapeSameDomain", (TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::ChangeShapeSameDomain, "None", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("ShapeSameDomain", (const TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::ShapeSameDomain, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeShapeSameDomain", (TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeShapeSameDomain, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeShapes", (TopOpeBRepDS_MapOfShapeData & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeShapes, "None");
	cls_TopOpeBRepDS_DataStructure.def("AddShapeSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::AddShapeSameDomain, "None", py::arg("S"), py::arg("SSD"));
	cls_TopOpeBRepDS_DataStructure.def("RemoveShapeSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::RemoveShapeSameDomain, "None", py::arg("S"), py::arg("SSD"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("I"), py::arg("Ref"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("S"), py::arg("Ref"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (TopOpeBRepDS_Config (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (TopOpeBRepDS_Config (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const TopOpeBRepDS_Config)) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("I"), py::arg("Ori"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopOpeBRepDS_Config)) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("S"), py::arg("Ori"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("I"), py::arg("Ind"));
	cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("S"), py::arg("Ind"));
	cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("I"), py::arg("Ianc"));
	cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("S"), py::arg("Ianc"));
	cls_TopOpeBRepDS_DataStructure.def("AddShapeInterference", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataStructure::AddShapeInterference, "None", py::arg("S"), py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("RemoveShapeInterference", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataStructure::RemoveShapeInterference, "None", py::arg("S"), py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> void { return self.FillShapesSameDomain(a0, a1); }, py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::FillShapesSameDomain, "None", py::arg("S1"), py::arg("S2"), py::arg("refFirst"));
	cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const TopOpeBRepDS_Config a2, const TopOpeBRepDS_Config a3) -> void { return self.FillShapesSameDomain(a0, a1, a2, a3); }, py::arg("S1"), py::arg("S2"), py::arg("c1"), py::arg("c2"));
	cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopOpeBRepDS_Config, const TopOpeBRepDS_Config, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::FillShapesSameDomain, "None", py::arg("S1"), py::arg("S2"), py::arg("c1"), py::arg("c2"), py::arg("refFirst"));
	cls_TopOpeBRepDS_DataStructure.def("UnfillShapesSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::UnfillShapesSameDomain, "None", py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRepDS_DataStructure.def("NbSurfaces", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const ) &TopOpeBRepDS_DataStructure::NbSurfaces, "None");
	cls_TopOpeBRepDS_DataStructure.def("NbCurves", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const ) &TopOpeBRepDS_DataStructure::NbCurves, "None");
	cls_TopOpeBRepDS_DataStructure.def("ChangeNbCurves", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeNbCurves, "None", py::arg("N"));
	cls_TopOpeBRepDS_DataStructure.def("NbPoints", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const ) &TopOpeBRepDS_DataStructure::NbPoints, "None");
	cls_TopOpeBRepDS_DataStructure.def("NbShapes", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const ) &TopOpeBRepDS_DataStructure::NbShapes, "None");
	cls_TopOpeBRepDS_DataStructure.def("NbSectionEdges", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const ) &TopOpeBRepDS_DataStructure::NbSectionEdges, "None");
	cls_TopOpeBRepDS_DataStructure.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::Surface, "Returns the surface of index <I>.", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeSurface", (TopOpeBRepDS_Surface & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeSurface, "Returns the surface of index <I>.", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::Curve, "Returns the Curve of index <I>.", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeCurve", (TopOpeBRepDS_Curve & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeCurve, "Returns the Curve of index <I>.", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_DataStructure::Point, "Returns the point of index <I>.", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("ChangePoint", (TopOpeBRepDS_Point & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangePoint, "Returns the point of index <I>.", py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("Shape", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> const TopoDS_Shape & { return self.Shape(a0); }, py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("Shape", (const TopoDS_Shape & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const ) &TopOpeBRepDS_DataStructure::Shape, "returns the shape of index I stored in the map myShapes, accessing a list of interference.", py::arg("I"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("Shape", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> Standard_Integer { return self.Shape(a0); }, py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("Shape", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const ) &TopOpeBRepDS_DataStructure::Shape, "returns the index of shape <S> stored in the map myShapes, accessing a list of interference. returns 0 if <S> is not in the map.", py::arg("S"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("SectionEdge", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> const TopoDS_Edge & { return self.SectionEdge(a0); }, py::arg("I"));
	cls_TopOpeBRepDS_DataStructure.def("SectionEdge", (const TopoDS_Edge & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const ) &TopOpeBRepDS_DataStructure::SectionEdge, "None", py::arg("I"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("SectionEdge", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Edge & a0) -> Standard_Integer { return self.SectionEdge(a0); }, py::arg("E"));
	cls_TopOpeBRepDS_DataStructure.def("SectionEdge", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Edge &, const Standard_Boolean) const ) &TopOpeBRepDS_DataStructure::SectionEdge, "None", py::arg("E"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("IsSectionEdge", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Edge & a0) -> Standard_Boolean { return self.IsSectionEdge(a0); }, py::arg("E"));
	cls_TopOpeBRepDS_DataStructure.def("IsSectionEdge", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Edge &, const Standard_Boolean) const ) &TopOpeBRepDS_DataStructure::IsSectionEdge, "None", py::arg("E"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("HasGeometry", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataStructure::HasGeometry, "Returns True if <S> has new geometries, i.e : True si : HasShape(S) True S a une liste d'interferences non vide. S = SOLID, FACE, EDGE : true/false S = SHELL, WIRE, VERTEX : false.", py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("HasShape", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.HasShape(a0); }, py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("HasShape", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const ) &TopOpeBRepDS_DataStructure::HasShape, "Returns True if <S> est dans myShapes", py::arg("S"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_DataStructure.def("SetNewSurface", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &)) &TopOpeBRepDS_DataStructure::SetNewSurface, "None", py::arg("F"), py::arg("S"));
	cls_TopOpeBRepDS_DataStructure.def("HasNewSurface", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataStructure::HasNewSurface, "None", py::arg("F"));
	cls_TopOpeBRepDS_DataStructure.def("NewSurface", (const opencascade::handle<Geom_Surface> & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataStructure::NewSurface, "None", py::arg("F"));
	cls_TopOpeBRepDS_DataStructure.def("Isfafa", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Boolean)) &TopOpeBRepDS_DataStructure::Isfafa, "None", py::arg("isfafa"));
	cls_TopOpeBRepDS_DataStructure.def("Isfafa", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)() const ) &TopOpeBRepDS_DataStructure::Isfafa, "None");
	cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfShapeWithStateObj", (TopOpeBRepDS_IndexedDataMapOfShapeWithState & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfShapeWithStateObj, "None");
	cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfShapeWithStateTool", (TopOpeBRepDS_IndexedDataMapOfShapeWithState & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfShapeWithStateTool, "None");
	cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfShapeWithState", (TopOpeBRepDS_IndexedDataMapOfShapeWithState & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, Standard_Boolean &)) &TopOpeBRepDS_DataStructure::ChangeMapOfShapeWithState, "None", py::arg("aShape"), py::arg("aFlag"));
	cls_TopOpeBRepDS_DataStructure.def("GetShapeWithState", (const TopOpeBRepDS_ShapeWithState & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataStructure::GetShapeWithState, "None", py::arg("aShape"));
	cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfRejectedShapesObj", (TopTools_IndexedMapOfShape & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfRejectedShapesObj, "None");
	cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfRejectedShapesTool", (TopTools_IndexedMapOfShape & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfRejectedShapesTool, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_SurfaceData.hxx
	py::class_<TopOpeBRepDS_SurfaceData, std::unique_ptr<TopOpeBRepDS_SurfaceData, Deleter<TopOpeBRepDS_SurfaceData>>, TopOpeBRepDS_GeometryData> cls_TopOpeBRepDS_SurfaceData(mod, "TopOpeBRepDS_SurfaceData", "None");
	cls_TopOpeBRepDS_SurfaceData.def(py::init<>());
	cls_TopOpeBRepDS_SurfaceData.def(py::init<const TopOpeBRepDS_Surface &>(), py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Curve.hxx
	py::class_<TopOpeBRepDS_Curve, std::unique_ptr<TopOpeBRepDS_Curve, Deleter<TopOpeBRepDS_Curve>>> cls_TopOpeBRepDS_Curve(mod, "TopOpeBRepDS_Curve", "A Geom curve and a tolerance.");
	cls_TopOpeBRepDS_Curve.def(py::init<>());
	cls_TopOpeBRepDS_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("P"), py::arg("T"));
	cls_TopOpeBRepDS_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Boolean>(), py::arg("P"), py::arg("T"), py::arg("IsWalk"));
	cls_TopOpeBRepDS_Curve.def("DefineCurve", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Boolean)) &TopOpeBRepDS_Curve::DefineCurve, "None", py::arg("P"), py::arg("T"), py::arg("IsWalk"));
	cls_TopOpeBRepDS_Curve.def("Tolerance", (void (TopOpeBRepDS_Curve::*)(const Standard_Real)) &TopOpeBRepDS_Curve::Tolerance, "Update the tolerance", py::arg("tol"));
	cls_TopOpeBRepDS_Curve.def("SetSCI", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Curve::SetSCI, "define the interferences face/curve.", py::arg("I1"), py::arg("I2"));
	cls_TopOpeBRepDS_Curve.def("GetSCI1", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::GetSCI1, "None");
	cls_TopOpeBRepDS_Curve.def("GetSCI2", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::GetSCI2, "None");
	cls_TopOpeBRepDS_Curve.def("GetSCI", (void (TopOpeBRepDS_Curve::*)(opencascade::handle<TopOpeBRepDS_Interference> &, opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_Curve::GetSCI, "None", py::arg("I1"), py::arg("I2"));
	cls_TopOpeBRepDS_Curve.def("SetShapes", (void (TopOpeBRepDS_Curve::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_Curve::SetShapes, "None", py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRepDS_Curve.def("GetShapes", (void (TopOpeBRepDS_Curve::*)(TopoDS_Shape &, TopoDS_Shape &) const ) &TopOpeBRepDS_Curve::GetShapes, "None", py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRepDS_Curve.def("Shape1", (const TopoDS_Shape & (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::Shape1, "None");
	cls_TopOpeBRepDS_Curve.def("ChangeShape1", (TopoDS_Shape & (TopOpeBRepDS_Curve::*)()) &TopOpeBRepDS_Curve::ChangeShape1, "None");
	cls_TopOpeBRepDS_Curve.def("Shape2", (const TopoDS_Shape & (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::Shape2, "None");
	cls_TopOpeBRepDS_Curve.def("ChangeShape2", (TopoDS_Shape & (TopOpeBRepDS_Curve::*)()) &TopOpeBRepDS_Curve::ChangeShape2, "None");
	cls_TopOpeBRepDS_Curve.def("Curve", (const opencascade::handle<Geom_Curve> & (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::Curve, "None");
	cls_TopOpeBRepDS_Curve.def("SetRange", (void (TopOpeBRepDS_Curve::*)(const Standard_Real, const Standard_Real)) &TopOpeBRepDS_Curve::SetRange, "None", py::arg("First"), py::arg("Last"));
	cls_TopOpeBRepDS_Curve.def("Range", (Standard_Boolean (TopOpeBRepDS_Curve::*)(Standard_Real &, Standard_Real &) const ) &TopOpeBRepDS_Curve::Range, "None", py::arg("First"), py::arg("Last"));
	cls_TopOpeBRepDS_Curve.def("Tolerance", (Standard_Real (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::Tolerance, "None");
	cls_TopOpeBRepDS_Curve.def("ChangeCurve", (opencascade::handle<Geom_Curve> & (TopOpeBRepDS_Curve::*)()) &TopOpeBRepDS_Curve::ChangeCurve, "None");
	cls_TopOpeBRepDS_Curve.def("Curve", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real)) &TopOpeBRepDS_Curve::Curve, "None", py::arg("C3D"), py::arg("Tol"));
	cls_TopOpeBRepDS_Curve.def("Curve1", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::Curve1, "None");
	cls_TopOpeBRepDS_Curve.def("Curve1", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_Curve::Curve1, "None", py::arg("PC1"));
	cls_TopOpeBRepDS_Curve.def("Curve2", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::Curve2, "None");
	cls_TopOpeBRepDS_Curve.def("Curve2", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_Curve::Curve2, "None", py::arg("PC2"));
	cls_TopOpeBRepDS_Curve.def("IsWalk", (Standard_Boolean (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::IsWalk, "None");
	cls_TopOpeBRepDS_Curve.def("ChangeIsWalk", (void (TopOpeBRepDS_Curve::*)(const Standard_Boolean)) &TopOpeBRepDS_Curve::ChangeIsWalk, "None", py::arg("B"));
	cls_TopOpeBRepDS_Curve.def("Keep", (Standard_Boolean (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::Keep, "None");
	cls_TopOpeBRepDS_Curve.def("ChangeKeep", (void (TopOpeBRepDS_Curve::*)(const Standard_Boolean)) &TopOpeBRepDS_Curve::ChangeKeep, "None", py::arg("B"));
	cls_TopOpeBRepDS_Curve.def("Mother", (Standard_Integer (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::Mother, "None");
	cls_TopOpeBRepDS_Curve.def("ChangeMother", (void (TopOpeBRepDS_Curve::*)(const Standard_Integer)) &TopOpeBRepDS_Curve::ChangeMother, "None", py::arg("I"));
	cls_TopOpeBRepDS_Curve.def("DSIndex", (Standard_Integer (TopOpeBRepDS_Curve::*)() const ) &TopOpeBRepDS_Curve::DSIndex, "None");
	cls_TopOpeBRepDS_Curve.def("ChangeDSIndex", (void (TopOpeBRepDS_Curve::*)(const Standard_Integer)) &TopOpeBRepDS_Curve::ChangeDSIndex, "None", py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_CurveData.hxx
	py::class_<TopOpeBRepDS_CurveData, std::unique_ptr<TopOpeBRepDS_CurveData, Deleter<TopOpeBRepDS_CurveData>>, TopOpeBRepDS_GeometryData> cls_TopOpeBRepDS_CurveData(mod, "TopOpeBRepDS_CurveData", "None");
	cls_TopOpeBRepDS_CurveData.def(py::init<>());
	cls_TopOpeBRepDS_CurveData.def(py::init<const TopOpeBRepDS_Curve &>(), py::arg("C"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Point.hxx
	py::class_<TopOpeBRepDS_Point, std::unique_ptr<TopOpeBRepDS_Point, Deleter<TopOpeBRepDS_Point>>> cls_TopOpeBRepDS_Point(mod, "TopOpeBRepDS_Point", "A Geom point and a tolerance.");
	cls_TopOpeBRepDS_Point.def(py::init<>());
	cls_TopOpeBRepDS_Point.def(py::init<const gp_Pnt &, const Standard_Real>(), py::arg("P"), py::arg("T"));
	cls_TopOpeBRepDS_Point.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_TopOpeBRepDS_Point.def("IsEqual", (Standard_Boolean (TopOpeBRepDS_Point::*)(const TopOpeBRepDS_Point &) const ) &TopOpeBRepDS_Point::IsEqual, "None", py::arg("other"));
	cls_TopOpeBRepDS_Point.def("Point", (const gp_Pnt & (TopOpeBRepDS_Point::*)() const ) &TopOpeBRepDS_Point::Point, "None");
	cls_TopOpeBRepDS_Point.def("ChangePoint", (gp_Pnt & (TopOpeBRepDS_Point::*)()) &TopOpeBRepDS_Point::ChangePoint, "None");
	cls_TopOpeBRepDS_Point.def("Tolerance", (Standard_Real (TopOpeBRepDS_Point::*)() const ) &TopOpeBRepDS_Point::Tolerance, "None");
	cls_TopOpeBRepDS_Point.def("Tolerance", (void (TopOpeBRepDS_Point::*)(const Standard_Real)) &TopOpeBRepDS_Point::Tolerance, "None", py::arg("Tol"));
	cls_TopOpeBRepDS_Point.def("Keep", (Standard_Boolean (TopOpeBRepDS_Point::*)() const ) &TopOpeBRepDS_Point::Keep, "None");
	cls_TopOpeBRepDS_Point.def("ChangeKeep", (void (TopOpeBRepDS_Point::*)(const Standard_Boolean)) &TopOpeBRepDS_Point::ChangeKeep, "None", py::arg("B"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_PointData.hxx
	py::class_<TopOpeBRepDS_PointData, std::unique_ptr<TopOpeBRepDS_PointData, Deleter<TopOpeBRepDS_PointData>>, TopOpeBRepDS_GeometryData> cls_TopOpeBRepDS_PointData(mod, "TopOpeBRepDS_PointData", "None");
	cls_TopOpeBRepDS_PointData.def(py::init<>());
	cls_TopOpeBRepDS_PointData.def(py::init<const TopOpeBRepDS_Point &>(), py::arg("P"));
	cls_TopOpeBRepDS_PointData.def(py::init<const TopOpeBRepDS_Point &, const Standard_Integer, const Standard_Integer>(), py::arg("P"), py::arg("I1"), py::arg("I2"));
	cls_TopOpeBRepDS_PointData.def("SetShapes", (void (TopOpeBRepDS_PointData::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_PointData::SetShapes, "None", py::arg("I1"), py::arg("I2"));
	cls_TopOpeBRepDS_PointData.def("GetShapes", (void (TopOpeBRepDS_PointData::*)(Standard_Integer &, Standard_Integer &) const ) &TopOpeBRepDS_PointData::GetShapes, "None", py::arg("I1"), py::arg("I2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ShapeData.hxx
	py::class_<TopOpeBRepDS_ShapeData, std::unique_ptr<TopOpeBRepDS_ShapeData, Deleter<TopOpeBRepDS_ShapeData>>> cls_TopOpeBRepDS_ShapeData(mod, "TopOpeBRepDS_ShapeData", "None");
	cls_TopOpeBRepDS_ShapeData.def(py::init<>());
	cls_TopOpeBRepDS_ShapeData.def("Interferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_ShapeData::*)() const ) &TopOpeBRepDS_ShapeData::Interferences, "None");
	cls_TopOpeBRepDS_ShapeData.def("ChangeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_ShapeData::*)()) &TopOpeBRepDS_ShapeData::ChangeInterferences, "None");
	cls_TopOpeBRepDS_ShapeData.def("Keep", (Standard_Boolean (TopOpeBRepDS_ShapeData::*)() const ) &TopOpeBRepDS_ShapeData::Keep, "None");
	cls_TopOpeBRepDS_ShapeData.def("ChangeKeep", (void (TopOpeBRepDS_ShapeData::*)(const Standard_Boolean)) &TopOpeBRepDS_ShapeData::ChangeKeep, "None", py::arg("B"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ShapeWithState.hxx
	py::class_<TopOpeBRepDS_ShapeWithState, std::unique_ptr<TopOpeBRepDS_ShapeWithState, Deleter<TopOpeBRepDS_ShapeWithState>>> cls_TopOpeBRepDS_ShapeWithState(mod, "TopOpeBRepDS_ShapeWithState", "None");
	cls_TopOpeBRepDS_ShapeWithState.def(py::init<>());
	cls_TopOpeBRepDS_ShapeWithState.def("Part", (const TopTools_ListOfShape & (TopOpeBRepDS_ShapeWithState::*)(const TopAbs_State) const ) &TopOpeBRepDS_ShapeWithState::Part, "None", py::arg("aState"));
	cls_TopOpeBRepDS_ShapeWithState.def("AddPart", (void (TopOpeBRepDS_ShapeWithState::*)(const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepDS_ShapeWithState::AddPart, "None", py::arg("aShape"), py::arg("aState"));
	cls_TopOpeBRepDS_ShapeWithState.def("AddParts", (void (TopOpeBRepDS_ShapeWithState::*)(const TopTools_ListOfShape &, const TopAbs_State)) &TopOpeBRepDS_ShapeWithState::AddParts, "None", py::arg("aListOfShape"), py::arg("aState"));
	cls_TopOpeBRepDS_ShapeWithState.def("SetState", (void (TopOpeBRepDS_ShapeWithState::*)(const TopAbs_State)) &TopOpeBRepDS_ShapeWithState::SetState, "None", py::arg("aState"));
	cls_TopOpeBRepDS_ShapeWithState.def("State", (TopAbs_State (TopOpeBRepDS_ShapeWithState::*)() const ) &TopOpeBRepDS_ShapeWithState::State, "None");
	cls_TopOpeBRepDS_ShapeWithState.def("SetIsSplitted", (void (TopOpeBRepDS_ShapeWithState::*)(const Standard_Boolean)) &TopOpeBRepDS_ShapeWithState::SetIsSplitted, "None", py::arg("anIsSplitted"));
	cls_TopOpeBRepDS_ShapeWithState.def("IsSplitted", (Standard_Boolean (TopOpeBRepDS_ShapeWithState::*)() const ) &TopOpeBRepDS_ShapeWithState::IsSplitted, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_SurfaceExplorer.hxx
	py::class_<TopOpeBRepDS_SurfaceExplorer, std::unique_ptr<TopOpeBRepDS_SurfaceExplorer, Deleter<TopOpeBRepDS_SurfaceExplorer>>> cls_TopOpeBRepDS_SurfaceExplorer(mod, "TopOpeBRepDS_SurfaceExplorer", "None");
	cls_TopOpeBRepDS_SurfaceExplorer.def(py::init<>());
	cls_TopOpeBRepDS_SurfaceExplorer.def(py::init<const TopOpeBRepDS_DataStructure &>(), py::arg("DS"));
	cls_TopOpeBRepDS_SurfaceExplorer.def(py::init<const TopOpeBRepDS_DataStructure &, const Standard_Boolean>(), py::arg("DS"), py::arg("FindOnlyKeep"));
	cls_TopOpeBRepDS_SurfaceExplorer.def("Init", [](TopOpeBRepDS_SurfaceExplorer &self, const TopOpeBRepDS_DataStructure & a0) -> void { return self.Init(a0); }, py::arg("DS"));
	cls_TopOpeBRepDS_SurfaceExplorer.def("Init", (void (TopOpeBRepDS_SurfaceExplorer::*)(const TopOpeBRepDS_DataStructure &, const Standard_Boolean)) &TopOpeBRepDS_SurfaceExplorer::Init, "None", py::arg("DS"), py::arg("FindOnlyKeep"));
	cls_TopOpeBRepDS_SurfaceExplorer.def("More", (Standard_Boolean (TopOpeBRepDS_SurfaceExplorer::*)() const ) &TopOpeBRepDS_SurfaceExplorer::More, "None");
	cls_TopOpeBRepDS_SurfaceExplorer.def("Next", (void (TopOpeBRepDS_SurfaceExplorer::*)()) &TopOpeBRepDS_SurfaceExplorer::Next, "None");
	cls_TopOpeBRepDS_SurfaceExplorer.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_SurfaceExplorer::*)() const ) &TopOpeBRepDS_SurfaceExplorer::Surface, "None");
	cls_TopOpeBRepDS_SurfaceExplorer.def("IsSurface", (Standard_Boolean (TopOpeBRepDS_SurfaceExplorer::*)(const Standard_Integer) const ) &TopOpeBRepDS_SurfaceExplorer::IsSurface, "None", py::arg("I"));
	cls_TopOpeBRepDS_SurfaceExplorer.def("IsSurfaceKeep", (Standard_Boolean (TopOpeBRepDS_SurfaceExplorer::*)(const Standard_Integer) const ) &TopOpeBRepDS_SurfaceExplorer::IsSurfaceKeep, "None", py::arg("I"));
	cls_TopOpeBRepDS_SurfaceExplorer.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_SurfaceExplorer::*)(const Standard_Integer) const ) &TopOpeBRepDS_SurfaceExplorer::Surface, "None", py::arg("I"));
	cls_TopOpeBRepDS_SurfaceExplorer.def("NbSurface", (Standard_Integer (TopOpeBRepDS_SurfaceExplorer::*)()) &TopOpeBRepDS_SurfaceExplorer::NbSurface, "None");
	cls_TopOpeBRepDS_SurfaceExplorer.def("Index", (Standard_Integer (TopOpeBRepDS_SurfaceExplorer::*)() const ) &TopOpeBRepDS_SurfaceExplorer::Index, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_CurveExplorer.hxx
	py::class_<TopOpeBRepDS_CurveExplorer, std::unique_ptr<TopOpeBRepDS_CurveExplorer, Deleter<TopOpeBRepDS_CurveExplorer>>> cls_TopOpeBRepDS_CurveExplorer(mod, "TopOpeBRepDS_CurveExplorer", "None");
	cls_TopOpeBRepDS_CurveExplorer.def(py::init<>());
	cls_TopOpeBRepDS_CurveExplorer.def(py::init<const TopOpeBRepDS_DataStructure &>(), py::arg("DS"));
	cls_TopOpeBRepDS_CurveExplorer.def(py::init<const TopOpeBRepDS_DataStructure &, const Standard_Boolean>(), py::arg("DS"), py::arg("FindOnlyKeep"));
	cls_TopOpeBRepDS_CurveExplorer.def("Init", [](TopOpeBRepDS_CurveExplorer &self, const TopOpeBRepDS_DataStructure & a0) -> void { return self.Init(a0); }, py::arg("DS"));
	cls_TopOpeBRepDS_CurveExplorer.def("Init", (void (TopOpeBRepDS_CurveExplorer::*)(const TopOpeBRepDS_DataStructure &, const Standard_Boolean)) &TopOpeBRepDS_CurveExplorer::Init, "None", py::arg("DS"), py::arg("FindOnlyKeep"));
	cls_TopOpeBRepDS_CurveExplorer.def("More", (Standard_Boolean (TopOpeBRepDS_CurveExplorer::*)() const ) &TopOpeBRepDS_CurveExplorer::More, "None");
	cls_TopOpeBRepDS_CurveExplorer.def("Next", (void (TopOpeBRepDS_CurveExplorer::*)()) &TopOpeBRepDS_CurveExplorer::Next, "None");
	cls_TopOpeBRepDS_CurveExplorer.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_CurveExplorer::*)() const ) &TopOpeBRepDS_CurveExplorer::Curve, "None");
	cls_TopOpeBRepDS_CurveExplorer.def("IsCurve", (Standard_Boolean (TopOpeBRepDS_CurveExplorer::*)(const Standard_Integer) const ) &TopOpeBRepDS_CurveExplorer::IsCurve, "None", py::arg("I"));
	cls_TopOpeBRepDS_CurveExplorer.def("IsCurveKeep", (Standard_Boolean (TopOpeBRepDS_CurveExplorer::*)(const Standard_Integer) const ) &TopOpeBRepDS_CurveExplorer::IsCurveKeep, "None", py::arg("I"));
	cls_TopOpeBRepDS_CurveExplorer.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_CurveExplorer::*)(const Standard_Integer) const ) &TopOpeBRepDS_CurveExplorer::Curve, "None", py::arg("I"));
	cls_TopOpeBRepDS_CurveExplorer.def("NbCurve", (Standard_Integer (TopOpeBRepDS_CurveExplorer::*)()) &TopOpeBRepDS_CurveExplorer::NbCurve, "None");
	cls_TopOpeBRepDS_CurveExplorer.def("Index", (Standard_Integer (TopOpeBRepDS_CurveExplorer::*)() const ) &TopOpeBRepDS_CurveExplorer::Index, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_PointExplorer.hxx
	py::class_<TopOpeBRepDS_PointExplorer, std::unique_ptr<TopOpeBRepDS_PointExplorer, Deleter<TopOpeBRepDS_PointExplorer>>> cls_TopOpeBRepDS_PointExplorer(mod, "TopOpeBRepDS_PointExplorer", "None");
	cls_TopOpeBRepDS_PointExplorer.def(py::init<>());
	cls_TopOpeBRepDS_PointExplorer.def(py::init<const TopOpeBRepDS_DataStructure &>(), py::arg("DS"));
	cls_TopOpeBRepDS_PointExplorer.def(py::init<const TopOpeBRepDS_DataStructure &, const Standard_Boolean>(), py::arg("DS"), py::arg("FindOnlyKeep"));
	cls_TopOpeBRepDS_PointExplorer.def("Init", [](TopOpeBRepDS_PointExplorer &self, const TopOpeBRepDS_DataStructure & a0) -> void { return self.Init(a0); }, py::arg("DS"));
	cls_TopOpeBRepDS_PointExplorer.def("Init", (void (TopOpeBRepDS_PointExplorer::*)(const TopOpeBRepDS_DataStructure &, const Standard_Boolean)) &TopOpeBRepDS_PointExplorer::Init, "None", py::arg("DS"), py::arg("FindOnlyKeep"));
	cls_TopOpeBRepDS_PointExplorer.def("More", (Standard_Boolean (TopOpeBRepDS_PointExplorer::*)() const ) &TopOpeBRepDS_PointExplorer::More, "None");
	cls_TopOpeBRepDS_PointExplorer.def("Next", (void (TopOpeBRepDS_PointExplorer::*)()) &TopOpeBRepDS_PointExplorer::Next, "None");
	cls_TopOpeBRepDS_PointExplorer.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_PointExplorer::*)() const ) &TopOpeBRepDS_PointExplorer::Point, "None");
	cls_TopOpeBRepDS_PointExplorer.def("IsPoint", (Standard_Boolean (TopOpeBRepDS_PointExplorer::*)(const Standard_Integer) const ) &TopOpeBRepDS_PointExplorer::IsPoint, "None", py::arg("I"));
	cls_TopOpeBRepDS_PointExplorer.def("IsPointKeep", (Standard_Boolean (TopOpeBRepDS_PointExplorer::*)(const Standard_Integer) const ) &TopOpeBRepDS_PointExplorer::IsPointKeep, "None", py::arg("I"));
	cls_TopOpeBRepDS_PointExplorer.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_PointExplorer::*)(const Standard_Integer) const ) &TopOpeBRepDS_PointExplorer::Point, "None", py::arg("I"));
	cls_TopOpeBRepDS_PointExplorer.def("NbPoint", (Standard_Integer (TopOpeBRepDS_PointExplorer::*)()) &TopOpeBRepDS_PointExplorer::NbPoint, "None");
	cls_TopOpeBRepDS_PointExplorer.def("Index", (Standard_Integer (TopOpeBRepDS_PointExplorer::*)() const ) &TopOpeBRepDS_PointExplorer::Index, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_CurveIterator.hxx
	py::class_<TopOpeBRepDS_CurveIterator, std::unique_ptr<TopOpeBRepDS_CurveIterator, Deleter<TopOpeBRepDS_CurveIterator>>, TopOpeBRepDS_InterferenceIterator> cls_TopOpeBRepDS_CurveIterator(mod, "TopOpeBRepDS_CurveIterator", "None");
	cls_TopOpeBRepDS_CurveIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));
	cls_TopOpeBRepDS_CurveIterator.def("MatchInterference", (Standard_Boolean (TopOpeBRepDS_CurveIterator::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_CurveIterator::MatchInterference, "Returns True if the Interference <I> has a GeometryType() TopOpeBRepDS_CURVE returns False else.", py::arg("I"));
	cls_TopOpeBRepDS_CurveIterator.def("Current", (Standard_Integer (TopOpeBRepDS_CurveIterator::*)() const ) &TopOpeBRepDS_CurveIterator::Current, "Index of the curve in the data structure.");
	cls_TopOpeBRepDS_CurveIterator.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_CurveIterator::*)(const TopAbs_State) const ) &TopOpeBRepDS_CurveIterator::Orientation, "None", py::arg("S"));
	cls_TopOpeBRepDS_CurveIterator.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_CurveIterator::*)() const ) &TopOpeBRepDS_CurveIterator::PCurve, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_PointIterator.hxx
	py::class_<TopOpeBRepDS_PointIterator, std::unique_ptr<TopOpeBRepDS_PointIterator, Deleter<TopOpeBRepDS_PointIterator>>, TopOpeBRepDS_InterferenceIterator> cls_TopOpeBRepDS_PointIterator(mod, "TopOpeBRepDS_PointIterator", "None");
	cls_TopOpeBRepDS_PointIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));
	cls_TopOpeBRepDS_PointIterator.def("MatchInterference", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_PointIterator::MatchInterference, "Returns True if the Interference <I> has a GeometryType() TopOpeBRepDS_POINT or TopOpeBRepDS_VERTEX returns False else.", py::arg("I"));
	cls_TopOpeBRepDS_PointIterator.def("Current", (Standard_Integer (TopOpeBRepDS_PointIterator::*)() const ) &TopOpeBRepDS_PointIterator::Current, "Index of the point in the data structure.");
	cls_TopOpeBRepDS_PointIterator.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_PointIterator::*)(const TopAbs_State) const ) &TopOpeBRepDS_PointIterator::Orientation, "None", py::arg("S"));
	cls_TopOpeBRepDS_PointIterator.def("Parameter", (Standard_Real (TopOpeBRepDS_PointIterator::*)() const ) &TopOpeBRepDS_PointIterator::Parameter, "None");
	cls_TopOpeBRepDS_PointIterator.def("IsVertex", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const ) &TopOpeBRepDS_PointIterator::IsVertex, "None");
	cls_TopOpeBRepDS_PointIterator.def("IsPoint", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const ) &TopOpeBRepDS_PointIterator::IsPoint, "None");
	cls_TopOpeBRepDS_PointIterator.def("DiffOriented", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const ) &TopOpeBRepDS_PointIterator::DiffOriented, "None");
	cls_TopOpeBRepDS_PointIterator.def("SameOriented", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const ) &TopOpeBRepDS_PointIterator::SameOriented, "None");
	cls_TopOpeBRepDS_PointIterator.def("Support", (Standard_Integer (TopOpeBRepDS_PointIterator::*)() const ) &TopOpeBRepDS_PointIterator::Support, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_SurfaceIterator.hxx
	py::class_<TopOpeBRepDS_SurfaceIterator, std::unique_ptr<TopOpeBRepDS_SurfaceIterator, Deleter<TopOpeBRepDS_SurfaceIterator>>, TopOpeBRepDS_InterferenceIterator> cls_TopOpeBRepDS_SurfaceIterator(mod, "TopOpeBRepDS_SurfaceIterator", "None");
	cls_TopOpeBRepDS_SurfaceIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));
	cls_TopOpeBRepDS_SurfaceIterator.def("Current", (Standard_Integer (TopOpeBRepDS_SurfaceIterator::*)() const ) &TopOpeBRepDS_SurfaceIterator::Current, "Index of the surface in the data structure.");
	cls_TopOpeBRepDS_SurfaceIterator.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_SurfaceIterator::*)(const TopAbs_State) const ) &TopOpeBRepDS_SurfaceIterator::Orientation, "None", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_HDataStructure.hxx
	py::class_<TopOpeBRepDS_HDataStructure, opencascade::handle<TopOpeBRepDS_HDataStructure>, Standard_Transient> cls_TopOpeBRepDS_HDataStructure(mod, "TopOpeBRepDS_HDataStructure", "None");
	cls_TopOpeBRepDS_HDataStructure.def(py::init<>());
	cls_TopOpeBRepDS_HDataStructure.def("AddAncestors", (void (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_HDataStructure::AddAncestors, "None", py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("AddAncestors", (void (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepDS_HDataStructure::AddAncestors, "Update the data structure with shapes of type T1 containing a subshape of type T2 which is stored in the DS. Used by the previous one.", py::arg("S"), py::arg("T1"), py::arg("T2"));
	cls_TopOpeBRepDS_HDataStructure.def("ChkIntg", (void (TopOpeBRepDS_HDataStructure::*)()) &TopOpeBRepDS_HDataStructure::ChkIntg, "Check the integrity of the DS");
	cls_TopOpeBRepDS_HDataStructure.def("DS", (const TopOpeBRepDS_DataStructure & (TopOpeBRepDS_HDataStructure::*)() const ) &TopOpeBRepDS_HDataStructure::DS, "None");
	cls_TopOpeBRepDS_HDataStructure.def("ChangeDS", (TopOpeBRepDS_DataStructure & (TopOpeBRepDS_HDataStructure::*)()) &TopOpeBRepDS_HDataStructure::ChangeDS, "None");
	cls_TopOpeBRepDS_HDataStructure.def("NbSurfaces", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const ) &TopOpeBRepDS_HDataStructure::NbSurfaces, "None");
	cls_TopOpeBRepDS_HDataStructure.def("NbCurves", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const ) &TopOpeBRepDS_HDataStructure::NbCurves, "None");
	cls_TopOpeBRepDS_HDataStructure.def("NbPoints", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const ) &TopOpeBRepDS_HDataStructure::NbPoints, "None");
	cls_TopOpeBRepDS_HDataStructure.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_HDataStructure::Surface, "Returns the surface of index <I>.", py::arg("I"));
	cls_TopOpeBRepDS_HDataStructure.def("SurfaceCurves", (TopOpeBRepDS_CurveIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_HDataStructure::SurfaceCurves, "Returns an iterator on the curves on the surface <I>.", py::arg("I"));
	cls_TopOpeBRepDS_HDataStructure.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_HDataStructure::Curve, "Returns the Curve of index <I>.", py::arg("I"));
	cls_TopOpeBRepDS_HDataStructure.def("ChangeCurve", (TopOpeBRepDS_Curve & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_HDataStructure::ChangeCurve, "Returns the Curve of index <I>.", py::arg("I"));
	cls_TopOpeBRepDS_HDataStructure.def("CurvePoints", (TopOpeBRepDS_PointIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_HDataStructure::CurvePoints, "Returns an iterator on the points on the curve <I>.", py::arg("I"));
	cls_TopOpeBRepDS_HDataStructure.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_HDataStructure::Point, "Returns the point of index <I>.", py::arg("I"));
	cls_TopOpeBRepDS_HDataStructure.def("NbShapes", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const ) &TopOpeBRepDS_HDataStructure::NbShapes, "None");
	cls_TopOpeBRepDS_HDataStructure.def("Shape", [](TopOpeBRepDS_HDataStructure &self, const Standard_Integer a0) -> const TopoDS_Shape & { return self.Shape(a0); }, py::arg("I"));
	cls_TopOpeBRepDS_HDataStructure.def("Shape", (const TopoDS_Shape & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer, const Standard_Boolean) const ) &TopOpeBRepDS_HDataStructure::Shape, "Returns the shape of index <I> in the DS", py::arg("I"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_HDataStructure.def("Shape", [](TopOpeBRepDS_HDataStructure &self, const TopoDS_Shape & a0) -> Standard_Integer { return self.Shape(a0); }, py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("Shape", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const ) &TopOpeBRepDS_HDataStructure::Shape, "Returns the index of shape <S> in the DS returns 0 if <S> is not in the DS", py::arg("S"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_HDataStructure.def("HasGeometry", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_HDataStructure::HasGeometry, "Returns True if <S> has new geometries.", py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("HasShape", [](TopOpeBRepDS_HDataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.HasShape(a0); }, py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("HasShape", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const ) &TopOpeBRepDS_HDataStructure::HasShape, "Returns True if <S> has new geometries (SOLID,FACE,EDGE) or if <S> (SHELL,WIRE) has sub-shape (FACE,EDGE) with new geometries", py::arg("S"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_HDataStructure.def("HasSameDomain", [](TopOpeBRepDS_HDataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.HasSameDomain(a0); }, py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("HasSameDomain", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const ) &TopOpeBRepDS_HDataStructure::HasSameDomain, "Returns True if <S> share a geometrical domain with some other shapes.", py::arg("S"), py::arg("FindKeep"));
	cls_TopOpeBRepDS_HDataStructure.def("SameDomain", (TopTools_ListIteratorOfListOfShape (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_HDataStructure::SameDomain, "Returns an iterator on the SameDomain shapes attached to the shape <S>.", py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("SameDomainOrientation", (TopOpeBRepDS_Config (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_HDataStructure::SameDomainOrientation, "Returns orientation of shape <S> compared with its reference shape", py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("SameDomainReference", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_HDataStructure::SameDomainReference, "Returns orientation of shape <S> compared with its reference shape", py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("SolidSurfaces", (TopOpeBRepDS_SurfaceIterator (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_HDataStructure::SolidSurfaces, "Returns an iterator on the surfaces attached to the solid <S>.", py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("SolidSurfaces", (TopOpeBRepDS_SurfaceIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_HDataStructure::SolidSurfaces, "Returns an iterator on the surfaces attached to the solid <I>.", py::arg("I"));
	cls_TopOpeBRepDS_HDataStructure.def("FaceCurves", (TopOpeBRepDS_CurveIterator (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_HDataStructure::FaceCurves, "Returns an iterator on the curves attached to the face <F>.", py::arg("F"));
	cls_TopOpeBRepDS_HDataStructure.def("FaceCurves", (TopOpeBRepDS_CurveIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const ) &TopOpeBRepDS_HDataStructure::FaceCurves, "Returns an iterator on the curves attached to the face <I>.", py::arg("I"));
	cls_TopOpeBRepDS_HDataStructure.def("EdgePoints", (TopOpeBRepDS_PointIterator (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_HDataStructure::EdgePoints, "Returns an iterator on the points attached to the edge <E>.", py::arg("E"));
	cls_TopOpeBRepDS_HDataStructure.def("MakeCurve", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_Curve &, TopOpeBRepDS_Curve &)) &TopOpeBRepDS_HDataStructure::MakeCurve, "None", py::arg("C1"), py::arg("C2"));
	cls_TopOpeBRepDS_HDataStructure.def("RemoveCurve", (void (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_HDataStructure::RemoveCurve, "None", py::arg("iC"));
	cls_TopOpeBRepDS_HDataStructure.def("NbGeometry", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_Kind) const ) &TopOpeBRepDS_HDataStructure::NbGeometry, "None", py::arg("K"));
	cls_TopOpeBRepDS_HDataStructure.def("NbTopology", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_Kind) const ) &TopOpeBRepDS_HDataStructure::NbTopology, "None", py::arg("K"));
	cls_TopOpeBRepDS_HDataStructure.def("NbTopology", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const ) &TopOpeBRepDS_HDataStructure::NbTopology, "None");
	cls_TopOpeBRepDS_HDataStructure.def("EdgesSameParameter", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)() const ) &TopOpeBRepDS_HDataStructure::EdgesSameParameter, "returns True if all the edges stored as shapes in the DS are SameParameter, otherwise False.");
	cls_TopOpeBRepDS_HDataStructure.def("SortOnParameter", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &) const ) &TopOpeBRepDS_HDataStructure::SortOnParameter, "None", py::arg("L1"), py::arg("L2"));
	cls_TopOpeBRepDS_HDataStructure.def("SortOnParameter", (void (TopOpeBRepDS_HDataStructure::*)(TopOpeBRepDS_ListOfInterference &) const ) &TopOpeBRepDS_HDataStructure::SortOnParameter, "None", py::arg("L"));
	cls_TopOpeBRepDS_HDataStructure.def("MinMaxOnParameter", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, Standard_Real &, Standard_Real &) const ) &TopOpeBRepDS_HDataStructure::MinMaxOnParameter, "None", py::arg("L"), py::arg("Min"), py::arg("Max"));
	cls_TopOpeBRepDS_HDataStructure.def("ScanInterfList", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(TopOpeBRepDS_ListIteratorOfListOfInterference &, const TopOpeBRepDS_Point &) const ) &TopOpeBRepDS_HDataStructure::ScanInterfList, "Search, among a list of interferences accessed by the iterator <IT>, a geometry <G> whose 3D point is identical to the 3D point of the TheDSPoint <PDS>. returns True if such an interference has been found, False else. if True, iterator It points (by the Value() method) on the first interference accessing an identical 3D point.", py::arg("IT"), py::arg("PDS"));
	cls_TopOpeBRepDS_HDataStructure.def("GetGeometry", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(TopOpeBRepDS_ListIteratorOfListOfInterference &, const TopOpeBRepDS_Point &, Standard_Integer &, TopOpeBRepDS_Kind &) const ) &TopOpeBRepDS_HDataStructure::GetGeometry, "Get the geometry of a DS point <PDS>. Search for it with ScanInterfList (previous method). if found, set <G,K> to the geometry,kind of the interference found. returns the value of ScanInterfList().", py::arg("IT"), py::arg("PDS"), py::arg("G"), py::arg("K"));
	cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", [](TopOpeBRepDS_HDataStructure &self, const opencascade::handle<TopOpeBRepDS_Interference> & a0, TopOpeBRepDS_ListOfInterference & a1) -> void { return self.StoreInterference(a0, a1); }, py::arg("I"), py::arg("LI"));
	cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", (void (TopOpeBRepDS_HDataStructure::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterference, "Add interference <I> to list <LI>.", py::arg("I"), py::arg("LI"), py::arg("str"));
	cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", [](TopOpeBRepDS_HDataStructure &self, const opencascade::handle<TopOpeBRepDS_Interference> & a0, const TopoDS_Shape & a1) -> void { return self.StoreInterference(a0, a1); }, py::arg("I"), py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", (void (TopOpeBRepDS_HDataStructure::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterference, "Add interference <I> to list of interference of shape <S>.", py::arg("I"), py::arg("S"), py::arg("str"));
	cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", [](TopOpeBRepDS_HDataStructure &self, const opencascade::handle<TopOpeBRepDS_Interference> & a0, const Standard_Integer a1) -> void { return self.StoreInterference(a0, a1); }, py::arg("I"), py::arg("IS"));
	cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", (void (TopOpeBRepDS_HDataStructure::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const Standard_Integer, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterference, "Add interference <I> to list of interference of shape <IS>.", py::arg("I"), py::arg("IS"), py::arg("str"));
	cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const TopoDS_Shape & a1) -> void { return self.StoreInterferences(a0, a1); }, py::arg("LI"), py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const TopoDS_Shape &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterferences, "None", py::arg("LI"), py::arg("S"), py::arg("str"));
	cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const Standard_Integer a1) -> void { return self.StoreInterferences(a0, a1); }, py::arg("LI"), py::arg("IS"));
	cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const Standard_Integer, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterferences, "None", py::arg("LI"), py::arg("IS"), py::arg("str"));
	cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const TopoDS_Shape & a1) -> void { return self.ClearStoreInterferences(a0, a1); }, py::arg("LI"), py::arg("S"));
	cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const TopoDS_Shape &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::ClearStoreInterferences, "None", py::arg("LI"), py::arg("S"), py::arg("str"));
	cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const Standard_Integer a1) -> void { return self.ClearStoreInterferences(a0, a1); }, py::arg("LI"), py::arg("IS"));
	cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const Standard_Integer, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::ClearStoreInterferences, "None", py::arg("LI"), py::arg("IS"), py::arg("str"));
	cls_TopOpeBRepDS_HDataStructure.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_HDataStructure::get_type_name, "None");
	cls_TopOpeBRepDS_HDataStructure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_HDataStructure::get_type_descriptor, "None");
	cls_TopOpeBRepDS_HDataStructure.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_HDataStructure::*)() const ) &TopOpeBRepDS_HDataStructure::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_SurfaceCurveInterference.hxx
	py::class_<TopOpeBRepDS_SurfaceCurveInterference, opencascade::handle<TopOpeBRepDS_SurfaceCurveInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_SurfaceCurveInterference(mod, "TopOpeBRepDS_SurfaceCurveInterference", "an interference with a 2d curve");
	cls_TopOpeBRepDS_SurfaceCurveInterference.def(py::init<>());
	cls_TopOpeBRepDS_SurfaceCurveInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const opencascade::handle<Geom2d_Curve> &>(), py::arg("Transition"), py::arg("SupportType"), py::arg("Support"), py::arg("GeometryType"), py::arg("Geometry"), py::arg("PC"));
	cls_TopOpeBRepDS_SurfaceCurveInterference.def(py::init<const opencascade::handle<TopOpeBRepDS_Interference> &>(), py::arg("I"));
	cls_TopOpeBRepDS_SurfaceCurveInterference.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_SurfaceCurveInterference::*)() const ) &TopOpeBRepDS_SurfaceCurveInterference::PCurve, "None");
	cls_TopOpeBRepDS_SurfaceCurveInterference.def("PCurve", (void (TopOpeBRepDS_SurfaceCurveInterference::*)(const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_SurfaceCurveInterference::PCurve, "None", py::arg("PC"));
	cls_TopOpeBRepDS_SurfaceCurveInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_SurfaceCurveInterference::get_type_name, "None");
	cls_TopOpeBRepDS_SurfaceCurveInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_SurfaceCurveInterference::get_type_descriptor, "None");
	cls_TopOpeBRepDS_SurfaceCurveInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_SurfaceCurveInterference::*)() const ) &TopOpeBRepDS_SurfaceCurveInterference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_BuildTool.hxx
	py::class_<TopOpeBRepDS_BuildTool, std::unique_ptr<TopOpeBRepDS_BuildTool, Deleter<TopOpeBRepDS_BuildTool>>> cls_TopOpeBRepDS_BuildTool(mod, "TopOpeBRepDS_BuildTool", "Provides a Tool to build topologies. Used to instantiate the Builder algorithm.");
	cls_TopOpeBRepDS_BuildTool.def(py::init<>());
	cls_TopOpeBRepDS_BuildTool.def(py::init<const TopOpeBRepTool_OutCurveType>(), py::arg("OutCurveType"));
	cls_TopOpeBRepDS_BuildTool.def(py::init<const TopOpeBRepTool_GeomTool &>(), py::arg("GT"));
	cls_TopOpeBRepDS_BuildTool.def("GetGeomTool", (const TopOpeBRepTool_GeomTool & (TopOpeBRepDS_BuildTool::*)() const ) &TopOpeBRepDS_BuildTool::GetGeomTool, "None");
	cls_TopOpeBRepDS_BuildTool.def("ChangeGeomTool", (TopOpeBRepTool_GeomTool & (TopOpeBRepDS_BuildTool::*)()) &TopOpeBRepDS_BuildTool::ChangeGeomTool, "None");
	cls_TopOpeBRepDS_BuildTool.def("MakeVertex", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Point &) const ) &TopOpeBRepDS_BuildTool::MakeVertex, "None", py::arg("V"), py::arg("P"));
	cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Curve &) const ) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"), py::arg("C"));
	cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Curve &, const TopOpeBRepDS_DataStructure &) const ) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"), py::arg("C"), py::arg("DS"));
	cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const opencascade::handle<Geom_Curve> &, const Standard_Real) const ) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"), py::arg("C"), py::arg("Tol"));
	cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"));
	cls_TopOpeBRepDS_BuildTool.def("MakeWire", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::MakeWire, "None", py::arg("W"));
	cls_TopOpeBRepDS_BuildTool.def("MakeFace", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Surface &) const ) &TopOpeBRepDS_BuildTool::MakeFace, "None", py::arg("F"), py::arg("S"));
	cls_TopOpeBRepDS_BuildTool.def("MakeShell", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::MakeShell, "None", py::arg("Sh"));
	cls_TopOpeBRepDS_BuildTool.def("MakeSolid", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::MakeSolid, "None", py::arg("S"));
	cls_TopOpeBRepDS_BuildTool.def("CopyEdge", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::CopyEdge, "Make an edge <Eou> with the curve of the edge <Ein>", py::arg("Ein"), py::arg("Eou"));
	cls_TopOpeBRepDS_BuildTool.def("GetOrientedEdgeVertices", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Edge &, TopoDS_Vertex &, TopoDS_Vertex &, Standard_Real &, Standard_Real &) const ) &TopOpeBRepDS_BuildTool::GetOrientedEdgeVertices, "None", py::arg("E"), py::arg("Vmin"), py::arg("Vmax"), py::arg("Parmin"), py::arg("Parmax"));
	cls_TopOpeBRepDS_BuildTool.def("UpdateEdgeCurveTol", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Face &, const TopoDS_Face &, TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, Standard_Real &, Standard_Real &, Standard_Real &) const ) &TopOpeBRepDS_BuildTool::UpdateEdgeCurveTol, "None", py::arg("F1"), py::arg("F2"), py::arg("E"), py::arg("C3Dnew"), py::arg("tol3d"), py::arg("tol2d1"), py::arg("tol2d2"), py::arg("newtol"), py::arg("newparmin"), py::arg("newparmax"));
	cls_TopOpeBRepDS_BuildTool.def("ApproxCurves", (void (TopOpeBRepDS_BuildTool::*)(const TopOpeBRepDS_Curve &, TopoDS_Edge &, Standard_Integer &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const ) &TopOpeBRepDS_BuildTool::ApproxCurves, "None", py::arg("C"), py::arg("E"), py::arg("inewC"), py::arg("HDS"));
	cls_TopOpeBRepDS_BuildTool.def("ComputePCurves", (void (TopOpeBRepDS_BuildTool::*)(const TopOpeBRepDS_Curve &, TopoDS_Edge &, TopOpeBRepDS_Curve &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean) const ) &TopOpeBRepDS_BuildTool::ComputePCurves, "None", py::arg("C"), py::arg("E"), py::arg("newC"), py::arg("CompPC1"), py::arg("CompPC2"), py::arg("CompC3D"));
	cls_TopOpeBRepDS_BuildTool.def("PutPCurves", (void (TopOpeBRepDS_BuildTool::*)(const TopOpeBRepDS_Curve &, TopoDS_Edge &, const Standard_Boolean, const Standard_Boolean) const ) &TopOpeBRepDS_BuildTool::PutPCurves, "None", py::arg("newC"), py::arg("E"), py::arg("CompPC1"), py::arg("CompPC2"));
	cls_TopOpeBRepDS_BuildTool.def("RecomputeCurves", (void (TopOpeBRepDS_BuildTool::*)(const TopOpeBRepDS_Curve &, const TopoDS_Edge &, TopoDS_Edge &, Standard_Integer &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const ) &TopOpeBRepDS_BuildTool::RecomputeCurves, "None", py::arg("C"), py::arg("oldE"), py::arg("E"), py::arg("inewC"), py::arg("HDS"));
	cls_TopOpeBRepDS_BuildTool.def("CopyFace", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::CopyFace, "Make a face <Fou> with the surface of the face <Fin>", py::arg("Fin"), py::arg("Fou"));
	cls_TopOpeBRepDS_BuildTool.def("AddEdgeVertex", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::AddEdgeVertex, "None", py::arg("Ein"), py::arg("Eou"), py::arg("V"));
	cls_TopOpeBRepDS_BuildTool.def("AddEdgeVertex", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::AddEdgeVertex, "None", py::arg("E"), py::arg("V"));
	cls_TopOpeBRepDS_BuildTool.def("AddWireEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::AddWireEdge, "None", py::arg("W"), py::arg("E"));
	cls_TopOpeBRepDS_BuildTool.def("AddFaceWire", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::AddFaceWire, "None", py::arg("F"), py::arg("W"));
	cls_TopOpeBRepDS_BuildTool.def("AddShellFace", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::AddShellFace, "None", py::arg("Sh"), py::arg("F"));
	cls_TopOpeBRepDS_BuildTool.def("AddSolidShell", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::AddSolidShell, "None", py::arg("S"), py::arg("Sh"));
	cls_TopOpeBRepDS_BuildTool.def("Parameter", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real) const ) &TopOpeBRepDS_BuildTool::Parameter, "Sets the parameter <P> for the vertex <V> on the edge <E>.", py::arg("E"), py::arg("V"), py::arg("P"));
	cls_TopOpeBRepDS_BuildTool.def("Range", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real) const ) &TopOpeBRepDS_BuildTool::Range, "Sets the range of edge <E>.", py::arg("E"), py::arg("first"), py::arg("last"));
	cls_TopOpeBRepDS_BuildTool.def("UpdateEdge", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::UpdateEdge, "Sets the range of edge <Eou> from <Ein> only when <Ein> has a closed geometry.", py::arg("Ein"), py::arg("Eou"));
	cls_TopOpeBRepDS_BuildTool.def("Parameter", (void (TopOpeBRepDS_BuildTool::*)(const TopOpeBRepDS_Curve &, TopoDS_Shape &, TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::Parameter, "Compute the parameter of the vertex <V>, supported by the edge <E>, on the curve <C>.", py::arg("C"), py::arg("E"), py::arg("V"));
	cls_TopOpeBRepDS_BuildTool.def("Curve3D", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const opencascade::handle<Geom_Curve> &, const Standard_Real) const ) &TopOpeBRepDS_BuildTool::Curve3D, "Sets the curve <C> for the edge <E>", py::arg("E"), py::arg("C"), py::arg("Tol"));
	cls_TopOpeBRepDS_BuildTool.def("PCurve", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, TopoDS_Shape &, const opencascade::handle<Geom2d_Curve> &) const ) &TopOpeBRepDS_BuildTool::PCurve, "Sets the pcurve <C> for the edge <E> on the face <F>. If OverWrite is True the old pcurve if there is one is overwritten, else the two pcurves are set.", py::arg("F"), py::arg("E"), py::arg("C"));
	cls_TopOpeBRepDS_BuildTool.def("PCurve", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, TopoDS_Shape &, const TopOpeBRepDS_Curve &, const opencascade::handle<Geom2d_Curve> &) const ) &TopOpeBRepDS_BuildTool::PCurve, "None", py::arg("F"), py::arg("E"), py::arg("CDS"), py::arg("C"));
	cls_TopOpeBRepDS_BuildTool.def("Orientation", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopAbs_Orientation) const ) &TopOpeBRepDS_BuildTool::Orientation, "None", py::arg("S"), py::arg("O"));
	cls_TopOpeBRepDS_BuildTool.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::Orientation, "None", py::arg("S"));
	cls_TopOpeBRepDS_BuildTool.def("Closed", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const Standard_Boolean) const ) &TopOpeBRepDS_BuildTool::Closed, "None", py::arg("S"), py::arg("B"));
	cls_TopOpeBRepDS_BuildTool.def("Approximation", (Standard_Boolean (TopOpeBRepDS_BuildTool::*)() const ) &TopOpeBRepDS_BuildTool::Approximation, "None");
	cls_TopOpeBRepDS_BuildTool.def("UpdateSurface", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &) const ) &TopOpeBRepDS_BuildTool::UpdateSurface, "None", py::arg("F"), py::arg("SU"));
	cls_TopOpeBRepDS_BuildTool.def("UpdateSurface", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &) const ) &TopOpeBRepDS_BuildTool::UpdateSurface, "None", py::arg("E"), py::arg("oldF"), py::arg("newF"));
	cls_TopOpeBRepDS_BuildTool.def("OverWrite", (Standard_Boolean (TopOpeBRepDS_BuildTool::*)() const ) &TopOpeBRepDS_BuildTool::OverWrite, "None");
	cls_TopOpeBRepDS_BuildTool.def("OverWrite", (void (TopOpeBRepDS_BuildTool::*)(const Standard_Boolean)) &TopOpeBRepDS_BuildTool::OverWrite, "None", py::arg("O"));
	cls_TopOpeBRepDS_BuildTool.def("Translate", (Standard_Boolean (TopOpeBRepDS_BuildTool::*)() const ) &TopOpeBRepDS_BuildTool::Translate, "None");
	cls_TopOpeBRepDS_BuildTool.def("Translate", (void (TopOpeBRepDS_BuildTool::*)(const Standard_Boolean)) &TopOpeBRepDS_BuildTool::Translate, "None", py::arg("T"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ListOfShapeOn1State.hxx
	py::class_<TopOpeBRepDS_ListOfShapeOn1State, std::unique_ptr<TopOpeBRepDS_ListOfShapeOn1State, Deleter<TopOpeBRepDS_ListOfShapeOn1State>>> cls_TopOpeBRepDS_ListOfShapeOn1State(mod, "TopOpeBRepDS_ListOfShapeOn1State", "represent a list of shape");
	cls_TopOpeBRepDS_ListOfShapeOn1State.def(py::init<>());
	cls_TopOpeBRepDS_ListOfShapeOn1State.def("ListOnState", (const TopTools_ListOfShape & (TopOpeBRepDS_ListOfShapeOn1State::*)() const ) &TopOpeBRepDS_ListOfShapeOn1State::ListOnState, "None");
	cls_TopOpeBRepDS_ListOfShapeOn1State.def("ChangeListOnState", (TopTools_ListOfShape & (TopOpeBRepDS_ListOfShapeOn1State::*)()) &TopOpeBRepDS_ListOfShapeOn1State::ChangeListOnState, "None");
	cls_TopOpeBRepDS_ListOfShapeOn1State.def("IsSplit", (Standard_Boolean (TopOpeBRepDS_ListOfShapeOn1State::*)() const ) &TopOpeBRepDS_ListOfShapeOn1State::IsSplit, "None");
	cls_TopOpeBRepDS_ListOfShapeOn1State.def("Split", [](TopOpeBRepDS_ListOfShapeOn1State &self) -> void { return self.Split(); });
	cls_TopOpeBRepDS_ListOfShapeOn1State.def("Split", (void (TopOpeBRepDS_ListOfShapeOn1State::*)(const Standard_Boolean)) &TopOpeBRepDS_ListOfShapeOn1State::Split, "None", py::arg("B"));
	cls_TopOpeBRepDS_ListOfShapeOn1State.def("Clear", (void (TopOpeBRepDS_ListOfShapeOn1State::*)()) &TopOpeBRepDS_ListOfShapeOn1State::Clear, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_TKI.hxx
	py::class_<TopOpeBRepDS_TKI, std::unique_ptr<TopOpeBRepDS_TKI, Deleter<TopOpeBRepDS_TKI>>> cls_TopOpeBRepDS_TKI(mod, "TopOpeBRepDS_TKI", "None");
	cls_TopOpeBRepDS_TKI.def(py::init<>());
	cls_TopOpeBRepDS_TKI.def("Clear", (void (TopOpeBRepDS_TKI::*)()) &TopOpeBRepDS_TKI::Clear, "None");
	cls_TopOpeBRepDS_TKI.def("FillOnGeometry", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_TKI::FillOnGeometry, "None", py::arg("L"));
	cls_TopOpeBRepDS_TKI.def("FillOnSupport", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_TKI::FillOnSupport, "None", py::arg("L"));
	cls_TopOpeBRepDS_TKI.def("IsBound", (Standard_Boolean (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const ) &TopOpeBRepDS_TKI::IsBound, "None", py::arg("K"), py::arg("G"));
	cls_TopOpeBRepDS_TKI.def("Interferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const ) &TopOpeBRepDS_TKI::Interferences, "None", py::arg("K"), py::arg("G"));
	cls_TopOpeBRepDS_TKI.def("ChangeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer)) &TopOpeBRepDS_TKI::ChangeInterferences, "None", py::arg("K"), py::arg("G"));
	cls_TopOpeBRepDS_TKI.def("HasInterferences", (Standard_Boolean (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const ) &TopOpeBRepDS_TKI::HasInterferences, "None", py::arg("K"), py::arg("G"));
	cls_TopOpeBRepDS_TKI.def("Add", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer)) &TopOpeBRepDS_TKI::Add, "None", py::arg("K"), py::arg("G"));
	cls_TopOpeBRepDS_TKI.def("Add", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_TKI::Add, "None", py::arg("K"), py::arg("G"), py::arg("HI"));
	cls_TopOpeBRepDS_TKI.def("DumpTKIIterator", [](TopOpeBRepDS_TKI &self) -> void { return self.DumpTKIIterator(); });
	cls_TopOpeBRepDS_TKI.def("DumpTKIIterator", [](TopOpeBRepDS_TKI &self, const TCollection_AsciiString & a0) -> void { return self.DumpTKIIterator(a0); }, py::arg("s1"));
	cls_TopOpeBRepDS_TKI.def("DumpTKIIterator", (void (TopOpeBRepDS_TKI::*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &TopOpeBRepDS_TKI::DumpTKIIterator, "None", py::arg("s1"), py::arg("s2"));
	cls_TopOpeBRepDS_TKI.def("Init", (void (TopOpeBRepDS_TKI::*)()) &TopOpeBRepDS_TKI::Init, "None");
	cls_TopOpeBRepDS_TKI.def("More", (Standard_Boolean (TopOpeBRepDS_TKI::*)() const ) &TopOpeBRepDS_TKI::More, "None");
	cls_TopOpeBRepDS_TKI.def("Next", (void (TopOpeBRepDS_TKI::*)()) &TopOpeBRepDS_TKI::Next, "None");
	cls_TopOpeBRepDS_TKI.def("Value", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_TKI::*)(TopOpeBRepDS_Kind &, Standard_Integer &) const ) &TopOpeBRepDS_TKI::Value, "None", py::arg("K"), py::arg("G"));
	cls_TopOpeBRepDS_TKI.def("ChangeValue", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_TKI::*)(TopOpeBRepDS_Kind &, Standard_Integer &)) &TopOpeBRepDS_TKI::ChangeValue, "None", py::arg("K"), py::arg("G"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_SolidSurfaceInterference.hxx
	py::class_<TopOpeBRepDS_SolidSurfaceInterference, opencascade::handle<TopOpeBRepDS_SolidSurfaceInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_SolidSurfaceInterference(mod, "TopOpeBRepDS_SolidSurfaceInterference", "Interference");
	cls_TopOpeBRepDS_SolidSurfaceInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer>(), py::arg("Transition"), py::arg("SupportType"), py::arg("Support"), py::arg("GeometryType"), py::arg("Geometry"));
	cls_TopOpeBRepDS_SolidSurfaceInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_SolidSurfaceInterference::get_type_name, "None");
	cls_TopOpeBRepDS_SolidSurfaceInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_SolidSurfaceInterference::get_type_descriptor, "None");
	cls_TopOpeBRepDS_SolidSurfaceInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_SolidSurfaceInterference::*)() const ) &TopOpeBRepDS_SolidSurfaceInterference::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS.hxx
	py::class_<TopOpeBRepDS_DSS, std::unique_ptr<TopOpeBRepDS_DSS, Deleter<TopOpeBRepDS_DSS>>> cls_TopOpeBRepDS_DSS(mod, "TopOpeBRepDS_DSS", "None");
	cls_TopOpeBRepDS_DSS.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_InterferenceTool.hxx
	py::class_<TopOpeBRepDS_InterferenceTool, std::unique_ptr<TopOpeBRepDS_InterferenceTool, Deleter<TopOpeBRepDS_InterferenceTool>>> cls_TopOpeBRepDS_InterferenceTool(mod, "TopOpeBRepDS_InterferenceTool", "None");
	cls_TopOpeBRepDS_InterferenceTool.def(py::init<>());
	cls_TopOpeBRepDS_InterferenceTool.def_static("MakeEdgeInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::MakeEdgeInterference, "None", py::arg("T"), py::arg("SK"), py::arg("SI"), py::arg("GK"), py::arg("GI"), py::arg("P"));
	cls_TopOpeBRepDS_InterferenceTool.def_static("MakeCurveInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::MakeCurveInterference, "None", py::arg("T"), py::arg("SK"), py::arg("SI"), py::arg("GK"), py::arg("GI"), py::arg("P"));
	cls_TopOpeBRepDS_InterferenceTool.def_static("DuplicateCurvePointInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_InterferenceTool::DuplicateCurvePointInterference, "duplicate I in a new interference with Complement() transition.", py::arg("I"));
	cls_TopOpeBRepDS_InterferenceTool.def_static("MakeFaceCurveInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_InterferenceTool::MakeFaceCurveInterference, "None", py::arg("Transition"), py::arg("FaceI"), py::arg("CurveI"), py::arg("PC"));
	cls_TopOpeBRepDS_InterferenceTool.def_static("MakeSolidSurfaceInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_InterferenceTool::MakeSolidSurfaceInterference, "None", py::arg("Transition"), py::arg("SolidI"), py::arg("SurfaceI"));
	cls_TopOpeBRepDS_InterferenceTool.def_static("MakeEdgeVertexInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::MakeEdgeVertexInterference, "None", py::arg("Transition"), py::arg("EdgeI"), py::arg("VertexI"), py::arg("VertexIsBound"), py::arg("Config"), py::arg("param"));
	cls_TopOpeBRepDS_InterferenceTool.def_static("MakeFaceEdgeInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config)) &TopOpeBRepDS_InterferenceTool::MakeFaceEdgeInterference, "None", py::arg("Transition"), py::arg("FaceI"), py::arg("EdgeI"), py::arg("EdgeIsBound"), py::arg("Config"));
	cls_TopOpeBRepDS_InterferenceTool.def_static("Parameter_", (Standard_Real (*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_InterferenceTool::Parameter, "None", py::arg("CPI"));
	cls_TopOpeBRepDS_InterferenceTool.def_static("Parameter_", (void (*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::Parameter, "None", py::arg("CPI"), py::arg("Par"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Dumper.hxx
	py::class_<TopOpeBRepDS_Dumper, std::unique_ptr<TopOpeBRepDS_Dumper, Deleter<TopOpeBRepDS_Dumper>>> cls_TopOpeBRepDS_Dumper(mod, "TopOpeBRepDS_Dumper", "None");
	cls_TopOpeBRepDS_Dumper.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
	cls_TopOpeBRepDS_Dumper.def("SDumpRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const ) &TopOpeBRepDS_Dumper::SDumpRefOri, "None", py::arg("K"), py::arg("I"));
	cls_TopOpeBRepDS_Dumper.def("SDumpRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_Dumper::SDumpRefOri, "None", py::arg("S"));
	cls_TopOpeBRepDS_Dumper.def("SPrintShape", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const Standard_Integer) const ) &TopOpeBRepDS_Dumper::SPrintShape, "None", py::arg("I"));
	cls_TopOpeBRepDS_Dumper.def("SPrintShape", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_Dumper::SPrintShape, "None", py::arg("S"));
	cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", [](TopOpeBRepDS_Dumper &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SPrintShapeRefOri(a0); }, py::arg("S"));
	cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopoDS_Shape &, const TCollection_AsciiString &) const ) &TopOpeBRepDS_Dumper::SPrintShapeRefOri, "None", py::arg("S"), py::arg("B"));
	cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", [](TopOpeBRepDS_Dumper &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SPrintShapeRefOri(a0); }, py::arg("L"));
	cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &) const ) &TopOpeBRepDS_Dumper::SPrintShapeRefOri, "None", py::arg("L"), py::arg("B"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Marker.hxx
	py::class_<TopOpeBRepDS_Marker, opencascade::handle<TopOpeBRepDS_Marker>, Standard_Transient> cls_TopOpeBRepDS_Marker(mod, "TopOpeBRepDS_Marker", "None");
	cls_TopOpeBRepDS_Marker.def(py::init<>());
	cls_TopOpeBRepDS_Marker.def("Reset", (void (TopOpeBRepDS_Marker::*)()) &TopOpeBRepDS_Marker::Reset, "None");
	cls_TopOpeBRepDS_Marker.def("Set", (void (TopOpeBRepDS_Marker::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_Marker::Set, "None", py::arg("i"), py::arg("b"));
	cls_TopOpeBRepDS_Marker.def("Set", (void (TopOpeBRepDS_Marker::*)(const Standard_Boolean, const Standard_Integer, const Standard_Address)) &TopOpeBRepDS_Marker::Set, "None", py::arg("b"), py::arg("n"), py::arg("a"));
	cls_TopOpeBRepDS_Marker.def("GetI", (Standard_Boolean (TopOpeBRepDS_Marker::*)(const Standard_Integer) const ) &TopOpeBRepDS_Marker::GetI, "None", py::arg("i"));
	cls_TopOpeBRepDS_Marker.def("Allocate", (void (TopOpeBRepDS_Marker::*)(const Standard_Integer)) &TopOpeBRepDS_Marker::Allocate, "None", py::arg("n"));
	cls_TopOpeBRepDS_Marker.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Marker::get_type_name, "None");
	cls_TopOpeBRepDS_Marker.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Marker::get_type_descriptor, "None");
	cls_TopOpeBRepDS_Marker.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Marker::*)() const ) &TopOpeBRepDS_Marker::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EdgeInterferenceTool.hxx
	py::class_<TopOpeBRepDS_EdgeInterferenceTool, std::unique_ptr<TopOpeBRepDS_EdgeInterferenceTool, Deleter<TopOpeBRepDS_EdgeInterferenceTool>>> cls_TopOpeBRepDS_EdgeInterferenceTool(mod, "TopOpeBRepDS_EdgeInterferenceTool", "a tool computing complex transition on Edge.");
	cls_TopOpeBRepDS_EdgeInterferenceTool.def(py::init<>());
	cls_TopOpeBRepDS_EdgeInterferenceTool.def("Init", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_EdgeInterferenceTool::Init, "None", py::arg("E"), py::arg("I"));
	cls_TopOpeBRepDS_EdgeInterferenceTool.def("Add", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_EdgeInterferenceTool::Add, "None", py::arg("E"), py::arg("V"), py::arg("I"));
	cls_TopOpeBRepDS_EdgeInterferenceTool.def("Add", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const TopoDS_Shape &, const TopOpeBRepDS_Point &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_EdgeInterferenceTool::Add, "None", py::arg("E"), py::arg("P"), py::arg("I"));
	cls_TopOpeBRepDS_EdgeInterferenceTool.def("Transition", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_EdgeInterferenceTool::Transition, "None", py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Edge3dInterferenceTool.hxx
	py::class_<TopOpeBRepDS_Edge3dInterferenceTool, std::unique_ptr<TopOpeBRepDS_Edge3dInterferenceTool, Deleter<TopOpeBRepDS_Edge3dInterferenceTool>>> cls_TopOpeBRepDS_Edge3dInterferenceTool(mod, "TopOpeBRepDS_Edge3dInterferenceTool", "a tool computing edge / face complex transition, Interferences of edge reference are given by I = (T on face, G = point or vertex, S = edge)");
	cls_TopOpeBRepDS_Edge3dInterferenceTool.def(py::init<>());
	cls_TopOpeBRepDS_Edge3dInterferenceTool.def("InitPointVertex", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const Standard_Integer, const TopoDS_Shape &)) &TopOpeBRepDS_Edge3dInterferenceTool::InitPointVertex, "None", py::arg("IsVertex"), py::arg("VonOO"));
	cls_TopOpeBRepDS_Edge3dInterferenceTool.def("Init", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Edge3dInterferenceTool::Init, "None", py::arg("Eref"), py::arg("E"), py::arg("F"), py::arg("I"));
	cls_TopOpeBRepDS_Edge3dInterferenceTool.def("Add", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Edge3dInterferenceTool::Add, "None", py::arg("Eref"), py::arg("E"), py::arg("F"), py::arg("I"));
	cls_TopOpeBRepDS_Edge3dInterferenceTool.def("Transition", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_Edge3dInterferenceTool::Transition, "None", py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_FaceInterferenceTool.hxx
	py::class_<TopOpeBRepDS_FaceInterferenceTool, std::unique_ptr<TopOpeBRepDS_FaceInterferenceTool, Deleter<TopOpeBRepDS_FaceInterferenceTool>>> cls_TopOpeBRepDS_FaceInterferenceTool(mod, "TopOpeBRepDS_FaceInterferenceTool", "a tool computing complex transition on Face.");
	cls_TopOpeBRepDS_FaceInterferenceTool.def(py::init<const TopOpeBRepDS_PDataStructure &>(), py::arg("P"));
	cls_TopOpeBRepDS_FaceInterferenceTool.def("Init", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_FaceInterferenceTool::Init, "Eisnew = true if E is a new edge built on edge I->Geometry() false if E is shape <=> I->Geometry()", py::arg("FI"), py::arg("E"), py::arg("Eisnew"), py::arg("I"));
	cls_TopOpeBRepDS_FaceInterferenceTool.def("Add", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_FaceInterferenceTool::Add, "Eisnew = true if E is a new edge built on edge I->Geometry() false if E is shape <=> I->Geometry()", py::arg("FI"), py::arg("F"), py::arg("E"), py::arg("Eisnew"), py::arg("I"));
	cls_TopOpeBRepDS_FaceInterferenceTool.def("Add", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const TopoDS_Shape &, const TopOpeBRepDS_Curve &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_FaceInterferenceTool::Add, "None", py::arg("E"), py::arg("C"), py::arg("I"));
	cls_TopOpeBRepDS_FaceInterferenceTool.def("SetEdgePntPar", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const gp_Pnt &, const Standard_Real)) &TopOpeBRepDS_FaceInterferenceTool::SetEdgePntPar, "None", py::arg("P"), py::arg("par"));
	cls_TopOpeBRepDS_FaceInterferenceTool.def("GetEdgePntPar", (void (TopOpeBRepDS_FaceInterferenceTool::*)(gp_Pnt &, Standard_Real &) const ) &TopOpeBRepDS_FaceInterferenceTool::GetEdgePntPar, "None", py::arg("P"), py::arg("par"));
	cls_TopOpeBRepDS_FaceInterferenceTool.def("IsEdgePntParDef", (Standard_Boolean (TopOpeBRepDS_FaceInterferenceTool::*)() const ) &TopOpeBRepDS_FaceInterferenceTool::IsEdgePntParDef, "None");
	cls_TopOpeBRepDS_FaceInterferenceTool.def("Transition", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_FaceInterferenceTool::Transition, "None", py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Filter.hxx
	py::class_<TopOpeBRepDS_Filter, std::unique_ptr<TopOpeBRepDS_Filter, Deleter<TopOpeBRepDS_Filter>>> cls_TopOpeBRepDS_Filter(mod, "TopOpeBRepDS_Filter", "None");
	cls_TopOpeBRepDS_Filter.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
	cls_TopOpeBRepDS_Filter.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopOpeBRepTool_PShapeClassifier &>(), py::arg("HDS"), py::arg("pClassif"));
	cls_TopOpeBRepDS_Filter.def("ProcessInterferences", (void (TopOpeBRepDS_Filter::*)()) &TopOpeBRepDS_Filter::ProcessInterferences, "None");
	cls_TopOpeBRepDS_Filter.def("ProcessFaceInterferences", (void (TopOpeBRepDS_Filter::*)(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_Filter::ProcessFaceInterferences, "None", py::arg("MEsp"));
	cls_TopOpeBRepDS_Filter.def("ProcessFaceInterferences", (void (TopOpeBRepDS_Filter::*)(const Standard_Integer, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_Filter::ProcessFaceInterferences, "None", py::arg("I"), py::arg("MEsp"));
	cls_TopOpeBRepDS_Filter.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_Filter::*)()) &TopOpeBRepDS_Filter::ProcessEdgeInterferences, "None");
	cls_TopOpeBRepDS_Filter.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_Filter::*)(const Standard_Integer)) &TopOpeBRepDS_Filter::ProcessEdgeInterferences, "None", py::arg("I"));
	cls_TopOpeBRepDS_Filter.def("ProcessCurveInterferences", (void (TopOpeBRepDS_Filter::*)()) &TopOpeBRepDS_Filter::ProcessCurveInterferences, "None");
	cls_TopOpeBRepDS_Filter.def("ProcessCurveInterferences", (void (TopOpeBRepDS_Filter::*)(const Standard_Integer)) &TopOpeBRepDS_Filter::ProcessCurveInterferences, "None", py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Reducer.hxx
	py::class_<TopOpeBRepDS_Reducer, std::unique_ptr<TopOpeBRepDS_Reducer, Deleter<TopOpeBRepDS_Reducer>>> cls_TopOpeBRepDS_Reducer(mod, "TopOpeBRepDS_Reducer", "reduce interferences of a data structure (HDS) used in topological operations.");
	cls_TopOpeBRepDS_Reducer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
	cls_TopOpeBRepDS_Reducer.def("ProcessFaceInterferences", (void (TopOpeBRepDS_Reducer::*)(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_Reducer::ProcessFaceInterferences, "None", py::arg("M"));
	cls_TopOpeBRepDS_Reducer.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_Reducer::*)()) &TopOpeBRepDS_Reducer::ProcessEdgeInterferences, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_TOOL.hxx
	py::class_<TopOpeBRepDS_TOOL, std::unique_ptr<TopOpeBRepDS_TOOL, Deleter<TopOpeBRepDS_TOOL>>> cls_TopOpeBRepDS_TOOL(mod, "TopOpeBRepDS_TOOL", "None");
	cls_TopOpeBRepDS_TOOL.def(py::init<>());
	cls_TopOpeBRepDS_TOOL.def_static("EShareG_", (Standard_Integer (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopoDS_Edge &, TopTools_ListOfShape &)) &TopOpeBRepDS_TOOL::EShareG, "None", py::arg("HDS"), py::arg("E"), py::arg("lEsd"));
	cls_TopOpeBRepDS_TOOL.def_static("ShareG_", (Standard_Boolean (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_TOOL::ShareG, "None", py::arg("HDS"), py::arg("is1"), py::arg("is2"));
	cls_TopOpeBRepDS_TOOL.def_static("GetEsd_", (Standard_Boolean (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopoDS_Shape &, const Standard_Integer, Standard_Integer &)) &TopOpeBRepDS_TOOL::GetEsd, "None", py::arg("HDS"), py::arg("S"), py::arg("ie"), py::arg("iesd"));
	cls_TopOpeBRepDS_TOOL.def_static("ShareSplitON_", (Standard_Boolean (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &, const Standard_Integer, const Standard_Integer, TopoDS_Shape &)) &TopOpeBRepDS_TOOL::ShareSplitON, "None", py::arg("HDS"), py::arg("MspON"), py::arg("i1"), py::arg("i2"), py::arg("spON"));
	cls_TopOpeBRepDS_TOOL.def_static("GetConfig_", (Standard_Boolean (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &, const Standard_Integer, const Standard_Integer, Standard_Integer &)) &TopOpeBRepDS_TOOL::GetConfig, "None", py::arg("HDS"), py::arg("MEspON"), py::arg("ie"), py::arg("iesd"), py::arg("conf"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_FIR.hxx
	py::class_<TopOpeBRepDS_FIR, std::unique_ptr<TopOpeBRepDS_FIR, Deleter<TopOpeBRepDS_FIR>>> cls_TopOpeBRepDS_FIR(mod, "TopOpeBRepDS_FIR", "FaceInterferenceReducer");
	cls_TopOpeBRepDS_FIR.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
	cls_TopOpeBRepDS_FIR.def("ProcessFaceInterferences", (void (TopOpeBRepDS_FIR::*)(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_FIR::ProcessFaceInterferences, "None", py::arg("M"));
	cls_TopOpeBRepDS_FIR.def("ProcessFaceInterferences", (void (TopOpeBRepDS_FIR::*)(const Standard_Integer, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_FIR::ProcessFaceInterferences, "None", py::arg("I"), py::arg("M"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_EIR.hxx
	py::class_<TopOpeBRepDS_EIR, std::unique_ptr<TopOpeBRepDS_EIR, Deleter<TopOpeBRepDS_EIR>>> cls_TopOpeBRepDS_EIR(mod, "TopOpeBRepDS_EIR", "EdgeInterferenceReducer");
	cls_TopOpeBRepDS_EIR.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
	cls_TopOpeBRepDS_EIR.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_EIR::*)()) &TopOpeBRepDS_EIR::ProcessEdgeInterferences, "None");
	cls_TopOpeBRepDS_EIR.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_EIR::*)(const Standard_Integer)) &TopOpeBRepDS_EIR::ProcessEdgeInterferences, "None", py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Check.hxx
	py::class_<TopOpeBRepDS_Check, opencascade::handle<TopOpeBRepDS_Check>, Standard_Transient> cls_TopOpeBRepDS_Check(mod, "TopOpeBRepDS_Check", "a tool verifing integrity and structure of DS");
	cls_TopOpeBRepDS_Check.def(py::init<>());
	cls_TopOpeBRepDS_Check.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
	cls_TopOpeBRepDS_Check.def("ChkIntg", (Standard_Boolean (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::ChkIntg, "Check integrition of DS");
	cls_TopOpeBRepDS_Check.def("ChkIntgInterf", (Standard_Boolean (TopOpeBRepDS_Check::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_Check::ChkIntgInterf, "Check integrition of interferences (les supports et les geometries de LI)", py::arg("LI"));
	cls_TopOpeBRepDS_Check.def("CheckDS", (Standard_Boolean (TopOpeBRepDS_Check::*)(const Standard_Integer, const TopOpeBRepDS_Kind)) &TopOpeBRepDS_Check::CheckDS, "Verifie que le ieme element de la DS existe, et pour un K de type topologique, verifie qu'il est du bon type (VERTEX, EDGE, WIRE, FACE, SHELL ou SOLID)", py::arg("i"), py::arg("K"));
	cls_TopOpeBRepDS_Check.def("ChkIntgSamDom", (Standard_Boolean (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::ChkIntgSamDom, "Check integrition des champs SameDomain de la DS");
	cls_TopOpeBRepDS_Check.def("CheckShapes", (Standard_Boolean (TopOpeBRepDS_Check::*)(const TopTools_ListOfShape &) const ) &TopOpeBRepDS_Check::CheckShapes, "Verifie que les Shapes existent bien dans la DS Utile pour les Shapes SameDomain si la liste est vide, renvoie vrai", py::arg("LS"));
	cls_TopOpeBRepDS_Check.def("OneVertexOnPnt", (Standard_Boolean (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::OneVertexOnPnt, "Verifie que les Vertex non SameDomain sont bien nonSameDomain, que les vertex sameDomain sont bien SameDomain, que les Points sont non confondus ni entre eux, ni avec des Vertex.");
	cls_TopOpeBRepDS_Check.def("HDS", (const opencascade::handle<TopOpeBRepDS_HDataStructure> & (TopOpeBRepDS_Check::*)() const ) &TopOpeBRepDS_Check::HDS, "None");
	cls_TopOpeBRepDS_Check.def("ChangeHDS", (opencascade::handle<TopOpeBRepDS_HDataStructure> & (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::ChangeHDS, "None");
	cls_TopOpeBRepDS_Check.def("PrintIntg", (Standard_OStream & (TopOpeBRepDS_Check::*)(Standard_OStream &)) &TopOpeBRepDS_Check::PrintIntg, "None", py::arg("S"));
	cls_TopOpeBRepDS_Check.def("Print", (Standard_OStream & (TopOpeBRepDS_Check::*)(const TopOpeBRepDS_CheckStatus, Standard_OStream &)) &TopOpeBRepDS_Check::Print, "Prints the name of CheckStatus <stat> as a String", py::arg("stat"), py::arg("S"));
	cls_TopOpeBRepDS_Check.def("PrintShape", (Standard_OStream & (TopOpeBRepDS_Check::*)(const TopAbs_ShapeEnum, Standard_OStream &)) &TopOpeBRepDS_Check::PrintShape, "Prints the name of CheckStatus <stat> as a String", py::arg("SE"), py::arg("S"));
	cls_TopOpeBRepDS_Check.def("PrintShape", (Standard_OStream & (TopOpeBRepDS_Check::*)(const Standard_Integer, Standard_OStream &)) &TopOpeBRepDS_Check::PrintShape, "Prints the name of CheckStatus <stat> as a String", py::arg("index"), py::arg("S"));
	cls_TopOpeBRepDS_Check.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Check::get_type_name, "None");
	cls_TopOpeBRepDS_Check.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Check::get_type_descriptor, "None");
	cls_TopOpeBRepDS_Check.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Check::*)() const ) &TopOpeBRepDS_Check::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_GapFiller.hxx
	py::class_<TopOpeBRepDS_GapFiller, std::unique_ptr<TopOpeBRepDS_GapFiller, Deleter<TopOpeBRepDS_GapFiller>>> cls_TopOpeBRepDS_GapFiller(mod, "TopOpeBRepDS_GapFiller", "None");
	cls_TopOpeBRepDS_GapFiller.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
	cls_TopOpeBRepDS_GapFiller.def("Perform", (void (TopOpeBRepDS_GapFiller::*)()) &TopOpeBRepDS_GapFiller::Perform, "None");
	cls_TopOpeBRepDS_GapFiller.def("FindAssociatedPoints", (void (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FindAssociatedPoints, "Recherche parmi l'ensemble des points d'Interference la Liste <LI> des points qui correspondent au point d'indice <Index>", py::arg("I"), py::arg("LI"));
	cls_TopOpeBRepDS_GapFiller.def("CheckConnexity", (Standard_Boolean (TopOpeBRepDS_GapFiller::*)(TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::CheckConnexity, "Enchaine les sections via les points d'Interferences deja associe; Renvoit dans <L> les points extremites des Lignes. Methodes pour construire la liste des Points qui peuvent correspondre a une Point donne.", py::arg("LI"));
	cls_TopOpeBRepDS_GapFiller.def("AddPointsOnShape", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Shape &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::AddPointsOnShape, "None", py::arg("S"), py::arg("LI"));
	cls_TopOpeBRepDS_GapFiller.def("AddPointsOnConnexShape", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Shape &, const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::AddPointsOnConnexShape, "Methodes pour reduire la liste des Points qui peuvent correspondre a une Point donne.", py::arg("F"), py::arg("LI"));
	cls_TopOpeBRepDS_GapFiller.def("FilterByFace", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Face &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FilterByFace, "None", py::arg("F"), py::arg("LI"));
	cls_TopOpeBRepDS_GapFiller.def("FilterByEdge", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Edge &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FilterByEdge, "None", py::arg("E"), py::arg("LI"));
	cls_TopOpeBRepDS_GapFiller.def("FilterByIncidentDistance", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Face &, const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FilterByIncidentDistance, "None", py::arg("F"), py::arg("I"), py::arg("LI"));
	cls_TopOpeBRepDS_GapFiller.def("IsOnFace", (Standard_Boolean (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Face &) const ) &TopOpeBRepDS_GapFiller::IsOnFace, "Return TRUE si I a ete obtenu par une intersection avec <F>.", py::arg("I"), py::arg("F"));
	cls_TopOpeBRepDS_GapFiller.def("IsOnEdge", (Standard_Boolean (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Edge &) const ) &TopOpeBRepDS_GapFiller::IsOnEdge, "Return TRUE si I ou une de ses representaions a pour support <E>. Methodes de reconstructions des geometries des point et des courbes de section", py::arg("I"), py::arg("E"));
	cls_TopOpeBRepDS_GapFiller.def("BuildNewGeometries", (void (TopOpeBRepDS_GapFiller::*)()) &TopOpeBRepDS_GapFiller::BuildNewGeometries, "None");
	cls_TopOpeBRepDS_GapFiller.def("ReBuildGeom", (void (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TColStd_MapOfInteger &)) &TopOpeBRepDS_GapFiller::ReBuildGeom, "None", py::arg("I1"), py::arg("Done"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_GapTool.hxx
	py::class_<TopOpeBRepDS_GapTool, opencascade::handle<TopOpeBRepDS_GapTool>, Standard_Transient> cls_TopOpeBRepDS_GapTool(mod, "TopOpeBRepDS_GapTool", "None");
	cls_TopOpeBRepDS_GapTool.def(py::init<>());
	cls_TopOpeBRepDS_GapTool.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
	cls_TopOpeBRepDS_GapTool.def("Init", (void (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepDS_GapTool::Init, "None", py::arg("HDS"));
	cls_TopOpeBRepDS_GapTool.def("Interferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GapTool::*)(const Standard_Integer) const ) &TopOpeBRepDS_GapTool::Interferences, "None", py::arg("IndexPoint"));
	cls_TopOpeBRepDS_GapTool.def("SameInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_GapTool::SameInterferences, "None", py::arg("I"));
	cls_TopOpeBRepDS_GapTool.def("ChangeSameInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_GapTool::ChangeSameInterferences, "None", py::arg("I"));
	cls_TopOpeBRepDS_GapTool.def("Curve", (Standard_Boolean (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_Curve &) const ) &TopOpeBRepDS_GapTool::Curve, "None", py::arg("I"), py::arg("C"));
	cls_TopOpeBRepDS_GapTool.def("EdgeSupport", (Standard_Boolean (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopoDS_Shape &) const ) &TopOpeBRepDS_GapTool::EdgeSupport, "None", py::arg("I"), py::arg("E"));
	cls_TopOpeBRepDS_GapTool.def("FacesSupport", (Standard_Boolean (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopoDS_Shape &, TopoDS_Shape &) const ) &TopOpeBRepDS_GapTool::FacesSupport, "Return les faces qui ont genere la section origine de I", py::arg("I"), py::arg("F1"), py::arg("F2"));
	cls_TopOpeBRepDS_GapTool.def("ParameterOnEdge", (Standard_Boolean (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &, Standard_Real &) const ) &TopOpeBRepDS_GapTool::ParameterOnEdge, "None", py::arg("I"), py::arg("E"), py::arg("U"));
	cls_TopOpeBRepDS_GapTool.def("SetPoint", (void (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const Standard_Integer)) &TopOpeBRepDS_GapTool::SetPoint, "None", py::arg("I"), py::arg("IndexPoint"));
	cls_TopOpeBRepDS_GapTool.def("SetParameterOnEdge", (void (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &, const Standard_Real)) &TopOpeBRepDS_GapTool::SetParameterOnEdge, "None", py::arg("I"), py::arg("E"), py::arg("U"));
	cls_TopOpeBRepDS_GapTool.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_GapTool::get_type_name, "None");
	cls_TopOpeBRepDS_GapTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_GapTool::get_type_descriptor, "None");
	cls_TopOpeBRepDS_GapTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_GapTool::*)() const ) &TopOpeBRepDS_GapTool::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Association.hxx
	py::class_<TopOpeBRepDS_Association, opencascade::handle<TopOpeBRepDS_Association>, Standard_Transient> cls_TopOpeBRepDS_Association(mod, "TopOpeBRepDS_Association", "None");
	cls_TopOpeBRepDS_Association.def(py::init<>());
	cls_TopOpeBRepDS_Association.def("Associate", (void (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Association::Associate, "None", py::arg("I"), py::arg("K"));
	cls_TopOpeBRepDS_Association.def("Associate", (void (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_Association::Associate, "None", py::arg("I"), py::arg("LI"));
	cls_TopOpeBRepDS_Association.def("HasAssociation", (Standard_Boolean (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_Association::HasAssociation, "None", py::arg("I"));
	cls_TopOpeBRepDS_Association.def("Associated", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Association::Associated, "None", py::arg("I"));
	cls_TopOpeBRepDS_Association.def("AreAssociated", (Standard_Boolean (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_Association::AreAssociated, "None", py::arg("I"), py::arg("K"));
	cls_TopOpeBRepDS_Association.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Association::get_type_name, "None");
	cls_TopOpeBRepDS_Association.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Association::get_type_descriptor, "None");
	cls_TopOpeBRepDS_Association.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Association::*)() const ) &TopOpeBRepDS_Association::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_Explorer.hxx
	py::class_<TopOpeBRepDS_Explorer, std::unique_ptr<TopOpeBRepDS_Explorer, Deleter<TopOpeBRepDS_Explorer>>> cls_TopOpeBRepDS_Explorer(mod, "TopOpeBRepDS_Explorer", "None");
	cls_TopOpeBRepDS_Explorer.def(py::init<>());
	cls_TopOpeBRepDS_Explorer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
	cls_TopOpeBRepDS_Explorer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopAbs_ShapeEnum>(), py::arg("HDS"), py::arg("T"));
	cls_TopOpeBRepDS_Explorer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopAbs_ShapeEnum, const Standard_Boolean>(), py::arg("HDS"), py::arg("T"), py::arg("findkeep"));
	cls_TopOpeBRepDS_Explorer.def("Init", [](TopOpeBRepDS_Explorer &self, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a0) -> void { return self.Init(a0); }, py::arg("HDS"));
	cls_TopOpeBRepDS_Explorer.def("Init", [](TopOpeBRepDS_Explorer &self, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a0, const TopAbs_ShapeEnum a1) -> void { return self.Init(a0, a1); }, py::arg("HDS"), py::arg("T"));
	cls_TopOpeBRepDS_Explorer.def("Init", (void (TopOpeBRepDS_Explorer::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopAbs_ShapeEnum, const Standard_Boolean)) &TopOpeBRepDS_Explorer::Init, "None", py::arg("HDS"), py::arg("T"), py::arg("findkeep"));
	cls_TopOpeBRepDS_Explorer.def("Type", (TopAbs_ShapeEnum (TopOpeBRepDS_Explorer::*)() const ) &TopOpeBRepDS_Explorer::Type, "None");
	cls_TopOpeBRepDS_Explorer.def("More", (Standard_Boolean (TopOpeBRepDS_Explorer::*)() const ) &TopOpeBRepDS_Explorer::More, "None");
	cls_TopOpeBRepDS_Explorer.def("Next", (void (TopOpeBRepDS_Explorer::*)()) &TopOpeBRepDS_Explorer::Next, "None");
	cls_TopOpeBRepDS_Explorer.def("Current", (const TopoDS_Shape & (TopOpeBRepDS_Explorer::*)() const ) &TopOpeBRepDS_Explorer::Current, "None");
	cls_TopOpeBRepDS_Explorer.def("Index", (Standard_Integer (TopOpeBRepDS_Explorer::*)() const ) &TopOpeBRepDS_Explorer::Index, "None");
	cls_TopOpeBRepDS_Explorer.def("Face", (const TopoDS_Face & (TopOpeBRepDS_Explorer::*)() const ) &TopOpeBRepDS_Explorer::Face, "None");
	cls_TopOpeBRepDS_Explorer.def("Edge", (const TopoDS_Edge & (TopOpeBRepDS_Explorer::*)() const ) &TopOpeBRepDS_Explorer::Edge, "None");
	cls_TopOpeBRepDS_Explorer.def("Vertex", (const TopoDS_Vertex & (TopOpeBRepDS_Explorer::*)() const ) &TopOpeBRepDS_Explorer::Vertex, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS.hxx
	py::class_<TopOpeBRepDS, std::unique_ptr<TopOpeBRepDS, Deleter<TopOpeBRepDS>>> cls_TopOpeBRepDS(mod, "TopOpeBRepDS", "This package provides services used by the TopOpeBRepBuild package performing topological operations on the BRep data structure.");
	cls_TopOpeBRepDS.def(py::init<>());
	cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_State)) &TopOpeBRepDS::SPrint, "IN OU ON UN", py::arg("S"));
	cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopAbs_State, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("S"), py::arg("OS"));
	cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::SPrint, "<K>", py::arg("K"));
	cls_TopOpeBRepDS.def_static("SPrint_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1) -> TCollection_AsciiString { return TopOpeBRepDS::SPrint(a0, a1); }, py::arg("K"), py::arg("I"));
	cls_TopOpeBRepDS.def_static("SPrint_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1, const TCollection_AsciiString & a2) -> TCollection_AsciiString { return TopOpeBRepDS::SPrint(a0, a1, a2); }, py::arg("K"), py::arg("I"), py::arg("B"));
	cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopOpeBRepDS_Kind, const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &)) &TopOpeBRepDS::SPrint, "S1(<K>,<I>)S2", py::arg("K"), py::arg("I"), py::arg("B"), py::arg("A"));
	cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepDS_Kind, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("K"), py::arg("S"));
	cls_TopOpeBRepDS.def_static("Print_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1, Standard_OStream & a2) -> Standard_OStream & { return TopOpeBRepDS::Print(a0, a1, a2); }, py::arg("K"), py::arg("I"), py::arg("S"));
	cls_TopOpeBRepDS.def_static("Print_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1, Standard_OStream & a2, const TCollection_AsciiString & a3) -> Standard_OStream & { return TopOpeBRepDS::Print(a0, a1, a2, a3); }, py::arg("K"), py::arg("I"), py::arg("S"), py::arg("B"));
	cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepDS_Kind, const Standard_Integer, Standard_OStream &, const TCollection_AsciiString &, const TCollection_AsciiString &)) &TopOpeBRepDS::Print, "None", py::arg("K"), py::arg("I"), py::arg("S"), py::arg("B"), py::arg("A"));
	cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS::SPrint, "None", py::arg("T"));
	cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_ShapeEnum, const Standard_Integer)) &TopOpeBRepDS::SPrint, "(<T>,<I>)", py::arg("T"), py::arg("I"));
	cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopAbs_ShapeEnum, const Standard_Integer, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("T"), py::arg("I"), py::arg("S"));
	cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_Orientation)) &TopOpeBRepDS::SPrint, "None", py::arg("O"));
	cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopOpeBRepDS_Config)) &TopOpeBRepDS::SPrint, "None", py::arg("C"));
	cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepDS_Config, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("C"), py::arg("S"));
	cls_TopOpeBRepDS.def_static("IsGeometry_", (Standard_Boolean (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::IsGeometry, "None", py::arg("K"));
	cls_TopOpeBRepDS.def_static("IsTopology_", (Standard_Boolean (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::IsTopology, "None", py::arg("K"));
	cls_TopOpeBRepDS.def_static("KindToShape_", (TopAbs_ShapeEnum (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::KindToShape, "None", py::arg("K"));
	cls_TopOpeBRepDS.def_static("ShapeToKind_", (TopOpeBRepDS_Kind (*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS::ShapeToKind, "None", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference, std::unique_ptr<TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference, Deleter<TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference>>> cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference(mod, "TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def(py::init<>());
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def(py::init([] (const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference &other) {return new TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def(py::init<TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference &&>(), py::arg("theOther"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def(py::init<const TopOpeBRepDS_DataMapOfIntegerListOfInterference &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("begin", (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::iterator (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("end", (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::iterator (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("cbegin", (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::const_iterator (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("cend", (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::const_iterator (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("Init", (void (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)(const TopOpeBRepDS_DataMapOfIntegerListOfInterference &)) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("Size", (Standard_Integer (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::Size, "Size query");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("Length", (Standard_Integer (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::Length, "Length query (the same)");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("IsEmpty", (Standard_Boolean (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::IsEmpty, "Return TRUE if array has zero length.");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("Lower", (Standard_Integer (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::Lower, "Lower bound");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("Upper", (Standard_Integer (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::Upper, "Upper bound");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("IsDeletable", (Standard_Boolean (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::IsDeletable, "myDeletable flag");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("IsAllocated", (Standard_Boolean (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("Assign", (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)(const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference &)) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("Move", (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)(TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference &&)) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::Move, "Move assignment", py::arg("theOther"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("assign", (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)(const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference &)) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("assign", (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)(TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference &&)) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("First", (const TopOpeBRepDS_DataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::First, "Returns first element");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("ChangeFirst", (TopOpeBRepDS_DataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)()) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::ChangeFirst, "Returns first element");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("Last", (const TopOpeBRepDS_DataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::Last, "Returns last element");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("ChangeLast", (TopOpeBRepDS_DataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)()) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::ChangeLast, "Returns last element");
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("Value", (const TopOpeBRepDS_DataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)(const Standard_Integer) const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::Value, "Constant value access", py::arg("theIndex"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("__call__", (const TopOpeBRepDS_DataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)(const Standard_Integer) const ) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("ChangeValue", (TopOpeBRepDS_DataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)(const Standard_Integer)) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("__call__", (TopOpeBRepDS_DataMapOfIntegerListOfInterference & (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)(const Standard_Integer)) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("SetValue", (void (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)(const Standard_Integer, const TopOpeBRepDS_DataMapOfIntegerListOfInterference &)) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("Resize", (void (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.def("__iter__", [](const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TopOpeBRepDS_ListOfInterference, std::unique_ptr<TopOpeBRepDS_ListOfInterference, Deleter<TopOpeBRepDS_ListOfInterference>>, NCollection_BaseList> cls_TopOpeBRepDS_ListOfInterference(mod, "TopOpeBRepDS_ListOfInterference", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TopOpeBRepDS_ListOfInterference.def(py::init<>());
	cls_TopOpeBRepDS_ListOfInterference.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TopOpeBRepDS_ListOfInterference.def(py::init([] (const TopOpeBRepDS_ListOfInterference &other) {return new TopOpeBRepDS_ListOfInterference(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_ListOfInterference.def("begin", (TopOpeBRepDS_ListOfInterference::iterator (TopOpeBRepDS_ListOfInterference::*)() const ) &TopOpeBRepDS_ListOfInterference::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TopOpeBRepDS_ListOfInterference.def("end", (TopOpeBRepDS_ListOfInterference::iterator (TopOpeBRepDS_ListOfInterference::*)() const ) &TopOpeBRepDS_ListOfInterference::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TopOpeBRepDS_ListOfInterference.def("cbegin", (TopOpeBRepDS_ListOfInterference::const_iterator (TopOpeBRepDS_ListOfInterference::*)() const ) &TopOpeBRepDS_ListOfInterference::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TopOpeBRepDS_ListOfInterference.def("cend", (TopOpeBRepDS_ListOfInterference::const_iterator (TopOpeBRepDS_ListOfInterference::*)() const ) &TopOpeBRepDS_ListOfInterference::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TopOpeBRepDS_ListOfInterference.def("Size", (Standard_Integer (TopOpeBRepDS_ListOfInterference::*)() const ) &TopOpeBRepDS_ListOfInterference::Size, "Size - Number of items");
	cls_TopOpeBRepDS_ListOfInterference.def("Assign", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_ListOfInterference::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_ListOfInterference::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_ListOfInterference.def("assign", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_ListOfInterference::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_ListOfInterference::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TopOpeBRepDS_ListOfInterference.def("Clear", [](TopOpeBRepDS_ListOfInterference &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_ListOfInterference.def("Clear", (void (TopOpeBRepDS_ListOfInterference::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_ListOfInterference::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TopOpeBRepDS_ListOfInterference.def("First", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_ListOfInterference::*)() const ) &TopOpeBRepDS_ListOfInterference::First, "First item");
	cls_TopOpeBRepDS_ListOfInterference.def("First", (opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_ListOfInterference::*)()) &TopOpeBRepDS_ListOfInterference::First, "First item (non-const)");
	cls_TopOpeBRepDS_ListOfInterference.def("Last", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_ListOfInterference::*)() const ) &TopOpeBRepDS_ListOfInterference::Last, "Last item");
	cls_TopOpeBRepDS_ListOfInterference.def("Last", (opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_ListOfInterference::*)()) &TopOpeBRepDS_ListOfInterference::Last, "Last item (non-const)");
	cls_TopOpeBRepDS_ListOfInterference.def("Append", (opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_ListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_ListOfInterference::Append, "Append one item at the end", py::arg("theItem"));
	cls_TopOpeBRepDS_ListOfInterference.def("Append", (void (TopOpeBRepDS_ListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference::Iterator &)) &TopOpeBRepDS_ListOfInterference::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TopOpeBRepDS_ListOfInterference.def("Append", (void (TopOpeBRepDS_ListOfInterference::*)(TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_ListOfInterference::Append, "Append another list at the end", py::arg("theOther"));
	cls_TopOpeBRepDS_ListOfInterference.def("Prepend", (opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_ListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_ListOfInterference::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TopOpeBRepDS_ListOfInterference.def("Prepend", (void (TopOpeBRepDS_ListOfInterference::*)(TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_ListOfInterference::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TopOpeBRepDS_ListOfInterference.def("RemoveFirst", (void (TopOpeBRepDS_ListOfInterference::*)()) &TopOpeBRepDS_ListOfInterference::RemoveFirst, "RemoveFirst item");
	cls_TopOpeBRepDS_ListOfInterference.def("Remove", (void (TopOpeBRepDS_ListOfInterference::*)(TopOpeBRepDS_ListOfInterference::Iterator &)) &TopOpeBRepDS_ListOfInterference::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TopOpeBRepDS_ListOfInterference.def("InsertBefore", (opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_ListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference::Iterator &)) &TopOpeBRepDS_ListOfInterference::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TopOpeBRepDS_ListOfInterference.def("InsertBefore", (void (TopOpeBRepDS_ListOfInterference::*)(TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference::Iterator &)) &TopOpeBRepDS_ListOfInterference::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TopOpeBRepDS_ListOfInterference.def("InsertAfter", (opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_ListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference::Iterator &)) &TopOpeBRepDS_ListOfInterference::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TopOpeBRepDS_ListOfInterference.def("InsertAfter", (void (TopOpeBRepDS_ListOfInterference::*)(TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference::Iterator &)) &TopOpeBRepDS_ListOfInterference::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TopOpeBRepDS_ListOfInterference.def("Reverse", (void (TopOpeBRepDS_ListOfInterference::*)()) &TopOpeBRepDS_ListOfInterference::Reverse, "Reverse the list");
	cls_TopOpeBRepDS_ListOfInterference.def("__iter__", [](const TopOpeBRepDS_ListOfInterference &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TopOpeBRepDS_ListIteratorOfListOfInterference, std::unique_ptr<TopOpeBRepDS_ListIteratorOfListOfInterference, Deleter<TopOpeBRepDS_ListIteratorOfListOfInterference>>> cls_TopOpeBRepDS_ListIteratorOfListOfInterference(mod, "TopOpeBRepDS_ListIteratorOfListOfInterference", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TopOpeBRepDS_ListIteratorOfListOfInterference.def(py::init<>());
	cls_TopOpeBRepDS_ListIteratorOfListOfInterference.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TopOpeBRepDS_ListIteratorOfListOfInterference.def("More", (Standard_Boolean (TopOpeBRepDS_ListIteratorOfListOfInterference::*)() const ) &TopOpeBRepDS_ListIteratorOfListOfInterference::More, "Check end");
	cls_TopOpeBRepDS_ListIteratorOfListOfInterference.def("Next", (void (TopOpeBRepDS_ListIteratorOfListOfInterference::*)()) &TopOpeBRepDS_ListIteratorOfListOfInterference::Next, "Make step");
	cls_TopOpeBRepDS_ListIteratorOfListOfInterference.def("Value", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_ListIteratorOfListOfInterference::*)() const ) &TopOpeBRepDS_ListIteratorOfListOfInterference::Value, "Constant Value access");
	cls_TopOpeBRepDS_ListIteratorOfListOfInterference.def("Value", (opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_ListIteratorOfListOfInterference::*)()) &TopOpeBRepDS_ListIteratorOfListOfInterference::Value, "Non-const Value access");
	cls_TopOpeBRepDS_ListIteratorOfListOfInterference.def("ChangeValue", (opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_ListIteratorOfListOfInterference::*)() const ) &TopOpeBRepDS_ListIteratorOfListOfInterference::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepDS_MapOfSurface, std::unique_ptr<TopOpeBRepDS_MapOfSurface, Deleter<TopOpeBRepDS_MapOfSurface>>, NCollection_BaseMap> cls_TopOpeBRepDS_MapOfSurface(mod, "TopOpeBRepDS_MapOfSurface", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepDS_MapOfSurface.def(py::init<>());
	cls_TopOpeBRepDS_MapOfSurface.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_MapOfSurface.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_MapOfSurface.def(py::init([] (const TopOpeBRepDS_MapOfSurface &other) {return new TopOpeBRepDS_MapOfSurface(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_MapOfSurface.def("begin", (TopOpeBRepDS_MapOfSurface::iterator (TopOpeBRepDS_MapOfSurface::*)() const ) &TopOpeBRepDS_MapOfSurface::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_MapOfSurface.def("end", (TopOpeBRepDS_MapOfSurface::iterator (TopOpeBRepDS_MapOfSurface::*)() const ) &TopOpeBRepDS_MapOfSurface::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_MapOfSurface.def("cbegin", (TopOpeBRepDS_MapOfSurface::const_iterator (TopOpeBRepDS_MapOfSurface::*)() const ) &TopOpeBRepDS_MapOfSurface::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_MapOfSurface.def("cend", (TopOpeBRepDS_MapOfSurface::const_iterator (TopOpeBRepDS_MapOfSurface::*)() const ) &TopOpeBRepDS_MapOfSurface::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_MapOfSurface.def("Exchange", (void (TopOpeBRepDS_MapOfSurface::*)(TopOpeBRepDS_MapOfSurface &)) &TopOpeBRepDS_MapOfSurface::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfSurface.def("Assign", (TopOpeBRepDS_MapOfSurface & (TopOpeBRepDS_MapOfSurface::*)(const TopOpeBRepDS_MapOfSurface &)) &TopOpeBRepDS_MapOfSurface::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfSurface.def("assign", (TopOpeBRepDS_MapOfSurface & (TopOpeBRepDS_MapOfSurface::*)(const TopOpeBRepDS_MapOfSurface &)) &TopOpeBRepDS_MapOfSurface::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfSurface.def("ReSize", (void (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer)) &TopOpeBRepDS_MapOfSurface::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_MapOfSurface.def("Bind", (Standard_Boolean (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer &, const TopOpeBRepDS_SurfaceData &)) &TopOpeBRepDS_MapOfSurface::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepDS_MapOfSurface.def("Bound", (TopOpeBRepDS_SurfaceData * (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer &, const TopOpeBRepDS_SurfaceData &)) &TopOpeBRepDS_MapOfSurface::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepDS_MapOfSurface.def("IsBound", (Standard_Boolean (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfSurface::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfSurface.def("UnBind", (Standard_Boolean (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfSurface::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfSurface.def("Seek", (const TopOpeBRepDS_SurfaceData * (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfSurface::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfSurface.def("Find", (const TopOpeBRepDS_SurfaceData & (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfSurface::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfSurface.def("Find", (Standard_Boolean (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer &, TopOpeBRepDS_SurfaceData &) const ) &TopOpeBRepDS_MapOfSurface::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepDS_MapOfSurface.def("__call__", (const TopOpeBRepDS_SurfaceData & (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfSurface::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfSurface.def("ChangeSeek", (TopOpeBRepDS_SurfaceData * (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfSurface::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfSurface.def("ChangeFind", (TopOpeBRepDS_SurfaceData & (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfSurface::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfSurface.def("__call__", (TopOpeBRepDS_SurfaceData & (TopOpeBRepDS_MapOfSurface::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfSurface::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfSurface.def("Clear", [](TopOpeBRepDS_MapOfSurface &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_MapOfSurface.def("Clear", (void (TopOpeBRepDS_MapOfSurface::*)(const Standard_Boolean)) &TopOpeBRepDS_MapOfSurface::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_MapOfSurface.def("Clear", (void (TopOpeBRepDS_MapOfSurface::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_MapOfSurface::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_MapOfSurface.def("Size", (Standard_Integer (TopOpeBRepDS_MapOfSurface::*)() const ) &TopOpeBRepDS_MapOfSurface::Size, "Size");
	cls_TopOpeBRepDS_MapOfSurface.def("__iter__", [](const TopOpeBRepDS_MapOfSurface &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_MapOfSurface.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepDS_MapOfCurve, std::unique_ptr<TopOpeBRepDS_MapOfCurve, Deleter<TopOpeBRepDS_MapOfCurve>>, NCollection_BaseMap> cls_TopOpeBRepDS_MapOfCurve(mod, "TopOpeBRepDS_MapOfCurve", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepDS_MapOfCurve.def(py::init<>());
	cls_TopOpeBRepDS_MapOfCurve.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_MapOfCurve.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_MapOfCurve.def(py::init([] (const TopOpeBRepDS_MapOfCurve &other) {return new TopOpeBRepDS_MapOfCurve(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_MapOfCurve.def("begin", (TopOpeBRepDS_MapOfCurve::iterator (TopOpeBRepDS_MapOfCurve::*)() const ) &TopOpeBRepDS_MapOfCurve::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_MapOfCurve.def("end", (TopOpeBRepDS_MapOfCurve::iterator (TopOpeBRepDS_MapOfCurve::*)() const ) &TopOpeBRepDS_MapOfCurve::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_MapOfCurve.def("cbegin", (TopOpeBRepDS_MapOfCurve::const_iterator (TopOpeBRepDS_MapOfCurve::*)() const ) &TopOpeBRepDS_MapOfCurve::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_MapOfCurve.def("cend", (TopOpeBRepDS_MapOfCurve::const_iterator (TopOpeBRepDS_MapOfCurve::*)() const ) &TopOpeBRepDS_MapOfCurve::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_MapOfCurve.def("Exchange", (void (TopOpeBRepDS_MapOfCurve::*)(TopOpeBRepDS_MapOfCurve &)) &TopOpeBRepDS_MapOfCurve::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfCurve.def("Assign", (TopOpeBRepDS_MapOfCurve & (TopOpeBRepDS_MapOfCurve::*)(const TopOpeBRepDS_MapOfCurve &)) &TopOpeBRepDS_MapOfCurve::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfCurve.def("assign", (TopOpeBRepDS_MapOfCurve & (TopOpeBRepDS_MapOfCurve::*)(const TopOpeBRepDS_MapOfCurve &)) &TopOpeBRepDS_MapOfCurve::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfCurve.def("ReSize", (void (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer)) &TopOpeBRepDS_MapOfCurve::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_MapOfCurve.def("Bind", (Standard_Boolean (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer &, const TopOpeBRepDS_CurveData &)) &TopOpeBRepDS_MapOfCurve::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepDS_MapOfCurve.def("Bound", (TopOpeBRepDS_CurveData * (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer &, const TopOpeBRepDS_CurveData &)) &TopOpeBRepDS_MapOfCurve::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepDS_MapOfCurve.def("IsBound", (Standard_Boolean (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfCurve::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfCurve.def("UnBind", (Standard_Boolean (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfCurve::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfCurve.def("Seek", (const TopOpeBRepDS_CurveData * (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfCurve::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfCurve.def("Find", (const TopOpeBRepDS_CurveData & (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfCurve::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfCurve.def("Find", (Standard_Boolean (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer &, TopOpeBRepDS_CurveData &) const ) &TopOpeBRepDS_MapOfCurve::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepDS_MapOfCurve.def("__call__", (const TopOpeBRepDS_CurveData & (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfCurve::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfCurve.def("ChangeSeek", (TopOpeBRepDS_CurveData * (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfCurve::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfCurve.def("ChangeFind", (TopOpeBRepDS_CurveData & (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfCurve::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfCurve.def("__call__", (TopOpeBRepDS_CurveData & (TopOpeBRepDS_MapOfCurve::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfCurve::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfCurve.def("Clear", [](TopOpeBRepDS_MapOfCurve &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_MapOfCurve.def("Clear", (void (TopOpeBRepDS_MapOfCurve::*)(const Standard_Boolean)) &TopOpeBRepDS_MapOfCurve::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_MapOfCurve.def("Clear", (void (TopOpeBRepDS_MapOfCurve::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_MapOfCurve::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_MapOfCurve.def("Size", (Standard_Integer (TopOpeBRepDS_MapOfCurve::*)() const ) &TopOpeBRepDS_MapOfCurve::Size, "Size");
	cls_TopOpeBRepDS_MapOfCurve.def("__iter__", [](const TopOpeBRepDS_MapOfCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_MapOfCurve.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepDS_MapOfPoint, std::unique_ptr<TopOpeBRepDS_MapOfPoint, Deleter<TopOpeBRepDS_MapOfPoint>>, NCollection_BaseMap> cls_TopOpeBRepDS_MapOfPoint(mod, "TopOpeBRepDS_MapOfPoint", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepDS_MapOfPoint.def(py::init<>());
	cls_TopOpeBRepDS_MapOfPoint.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_MapOfPoint.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_MapOfPoint.def(py::init([] (const TopOpeBRepDS_MapOfPoint &other) {return new TopOpeBRepDS_MapOfPoint(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_MapOfPoint.def("begin", (TopOpeBRepDS_MapOfPoint::iterator (TopOpeBRepDS_MapOfPoint::*)() const ) &TopOpeBRepDS_MapOfPoint::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_MapOfPoint.def("end", (TopOpeBRepDS_MapOfPoint::iterator (TopOpeBRepDS_MapOfPoint::*)() const ) &TopOpeBRepDS_MapOfPoint::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_MapOfPoint.def("cbegin", (TopOpeBRepDS_MapOfPoint::const_iterator (TopOpeBRepDS_MapOfPoint::*)() const ) &TopOpeBRepDS_MapOfPoint::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_MapOfPoint.def("cend", (TopOpeBRepDS_MapOfPoint::const_iterator (TopOpeBRepDS_MapOfPoint::*)() const ) &TopOpeBRepDS_MapOfPoint::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_MapOfPoint.def("Exchange", (void (TopOpeBRepDS_MapOfPoint::*)(TopOpeBRepDS_MapOfPoint &)) &TopOpeBRepDS_MapOfPoint::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfPoint.def("Assign", (TopOpeBRepDS_MapOfPoint & (TopOpeBRepDS_MapOfPoint::*)(const TopOpeBRepDS_MapOfPoint &)) &TopOpeBRepDS_MapOfPoint::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfPoint.def("assign", (TopOpeBRepDS_MapOfPoint & (TopOpeBRepDS_MapOfPoint::*)(const TopOpeBRepDS_MapOfPoint &)) &TopOpeBRepDS_MapOfPoint::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfPoint.def("ReSize", (void (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer)) &TopOpeBRepDS_MapOfPoint::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_MapOfPoint.def("Bind", (Standard_Boolean (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer &, const TopOpeBRepDS_PointData &)) &TopOpeBRepDS_MapOfPoint::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepDS_MapOfPoint.def("Bound", (TopOpeBRepDS_PointData * (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer &, const TopOpeBRepDS_PointData &)) &TopOpeBRepDS_MapOfPoint::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepDS_MapOfPoint.def("IsBound", (Standard_Boolean (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfPoint::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfPoint.def("UnBind", (Standard_Boolean (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfPoint::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfPoint.def("Seek", (const TopOpeBRepDS_PointData * (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfPoint::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfPoint.def("Find", (const TopOpeBRepDS_PointData & (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfPoint::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfPoint.def("Find", (Standard_Boolean (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer &, TopOpeBRepDS_PointData &) const ) &TopOpeBRepDS_MapOfPoint::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepDS_MapOfPoint.def("__call__", (const TopOpeBRepDS_PointData & (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfPoint::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfPoint.def("ChangeSeek", (TopOpeBRepDS_PointData * (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfPoint::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfPoint.def("ChangeFind", (TopOpeBRepDS_PointData & (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfPoint::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfPoint.def("__call__", (TopOpeBRepDS_PointData & (TopOpeBRepDS_MapOfPoint::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfPoint::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfPoint.def("Clear", [](TopOpeBRepDS_MapOfPoint &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_MapOfPoint.def("Clear", (void (TopOpeBRepDS_MapOfPoint::*)(const Standard_Boolean)) &TopOpeBRepDS_MapOfPoint::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_MapOfPoint.def("Clear", (void (TopOpeBRepDS_MapOfPoint::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_MapOfPoint::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_MapOfPoint.def("Size", (Standard_Integer (TopOpeBRepDS_MapOfPoint::*)() const ) &TopOpeBRepDS_MapOfPoint::Size, "Size");
	cls_TopOpeBRepDS_MapOfPoint.def("__iter__", [](const TopOpeBRepDS_MapOfPoint &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_MapOfPoint.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<TopOpeBRepDS_MapOfShapeData, std::unique_ptr<TopOpeBRepDS_MapOfShapeData, Deleter<TopOpeBRepDS_MapOfShapeData>>, NCollection_BaseMap> cls_TopOpeBRepDS_MapOfShapeData(mod, "TopOpeBRepDS_MapOfShapeData", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_TopOpeBRepDS_MapOfShapeData.def(py::init<>());
	cls_TopOpeBRepDS_MapOfShapeData.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_MapOfShapeData.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_MapOfShapeData.def(py::init([] (const TopOpeBRepDS_MapOfShapeData &other) {return new TopOpeBRepDS_MapOfShapeData(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_MapOfShapeData.def("begin", (TopOpeBRepDS_MapOfShapeData::iterator (TopOpeBRepDS_MapOfShapeData::*)() const ) &TopOpeBRepDS_MapOfShapeData::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_MapOfShapeData.def("end", (TopOpeBRepDS_MapOfShapeData::iterator (TopOpeBRepDS_MapOfShapeData::*)() const ) &TopOpeBRepDS_MapOfShapeData::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_MapOfShapeData.def("cbegin", (TopOpeBRepDS_MapOfShapeData::const_iterator (TopOpeBRepDS_MapOfShapeData::*)() const ) &TopOpeBRepDS_MapOfShapeData::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_MapOfShapeData.def("cend", (TopOpeBRepDS_MapOfShapeData::const_iterator (TopOpeBRepDS_MapOfShapeData::*)() const ) &TopOpeBRepDS_MapOfShapeData::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_MapOfShapeData.def("Exchange", (void (TopOpeBRepDS_MapOfShapeData::*)(TopOpeBRepDS_MapOfShapeData &)) &TopOpeBRepDS_MapOfShapeData::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfShapeData.def("Assign", (TopOpeBRepDS_MapOfShapeData & (TopOpeBRepDS_MapOfShapeData::*)(const TopOpeBRepDS_MapOfShapeData &)) &TopOpeBRepDS_MapOfShapeData::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfShapeData.def("assign", (TopOpeBRepDS_MapOfShapeData & (TopOpeBRepDS_MapOfShapeData::*)(const TopOpeBRepDS_MapOfShapeData &)) &TopOpeBRepDS_MapOfShapeData::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfShapeData.def("ReSize", (void (TopOpeBRepDS_MapOfShapeData::*)(const Standard_Integer)) &TopOpeBRepDS_MapOfShapeData::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_MapOfShapeData.def("Add", (Standard_Integer (TopOpeBRepDS_MapOfShapeData::*)(const TopoDS_Shape &, const TopOpeBRepDS_ShapeData &)) &TopOpeBRepDS_MapOfShapeData::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepDS_MapOfShapeData.def("Contains", (Standard_Boolean (TopOpeBRepDS_MapOfShapeData::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_MapOfShapeData::Contains, "Contains", py::arg("theKey1"));
	cls_TopOpeBRepDS_MapOfShapeData.def("Substitute", (void (TopOpeBRepDS_MapOfShapeData::*)(const Standard_Integer, const TopoDS_Shape &, const TopOpeBRepDS_ShapeData &)) &TopOpeBRepDS_MapOfShapeData::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepDS_MapOfShapeData.def("Swap", (void (TopOpeBRepDS_MapOfShapeData::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_MapOfShapeData::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TopOpeBRepDS_MapOfShapeData.def("RemoveLast", (void (TopOpeBRepDS_MapOfShapeData::*)()) &TopOpeBRepDS_MapOfShapeData::RemoveLast, "RemoveLast");
	cls_TopOpeBRepDS_MapOfShapeData.def("RemoveFromIndex", (void (TopOpeBRepDS_MapOfShapeData::*)(const Standard_Integer)) &TopOpeBRepDS_MapOfShapeData::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TopOpeBRepDS_MapOfShapeData.def("RemoveKey", (void (TopOpeBRepDS_MapOfShapeData::*)(const TopoDS_Shape &)) &TopOpeBRepDS_MapOfShapeData::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TopOpeBRepDS_MapOfShapeData.def("FindKey", (const TopoDS_Shape & (TopOpeBRepDS_MapOfShapeData::*)(const Standard_Integer) const ) &TopOpeBRepDS_MapOfShapeData::FindKey, "FindKey", py::arg("theKey2"));
	cls_TopOpeBRepDS_MapOfShapeData.def("FindFromIndex", (const TopOpeBRepDS_ShapeData & (TopOpeBRepDS_MapOfShapeData::*)(const Standard_Integer) const ) &TopOpeBRepDS_MapOfShapeData::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepDS_MapOfShapeData.def("__call__", (const TopOpeBRepDS_ShapeData & (TopOpeBRepDS_MapOfShapeData::*)(const Standard_Integer) const ) &TopOpeBRepDS_MapOfShapeData::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepDS_MapOfShapeData.def("ChangeFromIndex", (TopOpeBRepDS_ShapeData & (TopOpeBRepDS_MapOfShapeData::*)(const Standard_Integer)) &TopOpeBRepDS_MapOfShapeData::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepDS_MapOfShapeData.def("__call__", (TopOpeBRepDS_ShapeData & (TopOpeBRepDS_MapOfShapeData::*)(const Standard_Integer)) &TopOpeBRepDS_MapOfShapeData::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepDS_MapOfShapeData.def("FindIndex", (Standard_Integer (TopOpeBRepDS_MapOfShapeData::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_MapOfShapeData::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TopOpeBRepDS_MapOfShapeData.def("FindFromKey", (const TopOpeBRepDS_ShapeData & (TopOpeBRepDS_MapOfShapeData::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_MapOfShapeData::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_TopOpeBRepDS_MapOfShapeData.def("ChangeFromKey", (TopOpeBRepDS_ShapeData & (TopOpeBRepDS_MapOfShapeData::*)(const TopoDS_Shape &)) &TopOpeBRepDS_MapOfShapeData::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepDS_MapOfShapeData.def("Seek", (const TopOpeBRepDS_ShapeData * (TopOpeBRepDS_MapOfShapeData::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_MapOfShapeData::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepDS_MapOfShapeData.def("ChangeSeek", (TopOpeBRepDS_ShapeData * (TopOpeBRepDS_MapOfShapeData::*)(const TopoDS_Shape &)) &TopOpeBRepDS_MapOfShapeData::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_TopOpeBRepDS_MapOfShapeData.def("FindFromKey", (Standard_Boolean (TopOpeBRepDS_MapOfShapeData::*)(const TopoDS_Shape &, TopOpeBRepDS_ShapeData &) const ) &TopOpeBRepDS_MapOfShapeData::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_TopOpeBRepDS_MapOfShapeData.def("Clear", [](TopOpeBRepDS_MapOfShapeData &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_MapOfShapeData.def("Clear", (void (TopOpeBRepDS_MapOfShapeData::*)(const Standard_Boolean)) &TopOpeBRepDS_MapOfShapeData::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_MapOfShapeData.def("Clear", (void (TopOpeBRepDS_MapOfShapeData::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_MapOfShapeData::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_MapOfShapeData.def("Size", (Standard_Integer (TopOpeBRepDS_MapOfShapeData::*)() const ) &TopOpeBRepDS_MapOfShapeData::Size, "Size");
	cls_TopOpeBRepDS_MapOfShapeData.def("__iter__", [](const TopOpeBRepDS_MapOfShapeData &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepDS_ShapeSurface, std::unique_ptr<TopOpeBRepDS_ShapeSurface, Deleter<TopOpeBRepDS_ShapeSurface>>, NCollection_BaseMap> cls_TopOpeBRepDS_ShapeSurface(mod, "TopOpeBRepDS_ShapeSurface", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepDS_ShapeSurface.def(py::init<>());
	cls_TopOpeBRepDS_ShapeSurface.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_ShapeSurface.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_ShapeSurface.def(py::init([] (const TopOpeBRepDS_ShapeSurface &other) {return new TopOpeBRepDS_ShapeSurface(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_ShapeSurface.def("begin", (TopOpeBRepDS_ShapeSurface::iterator (TopOpeBRepDS_ShapeSurface::*)() const ) &TopOpeBRepDS_ShapeSurface::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_ShapeSurface.def("end", (TopOpeBRepDS_ShapeSurface::iterator (TopOpeBRepDS_ShapeSurface::*)() const ) &TopOpeBRepDS_ShapeSurface::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_ShapeSurface.def("cbegin", (TopOpeBRepDS_ShapeSurface::const_iterator (TopOpeBRepDS_ShapeSurface::*)() const ) &TopOpeBRepDS_ShapeSurface::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_ShapeSurface.def("cend", (TopOpeBRepDS_ShapeSurface::const_iterator (TopOpeBRepDS_ShapeSurface::*)() const ) &TopOpeBRepDS_ShapeSurface::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_ShapeSurface.def("Exchange", (void (TopOpeBRepDS_ShapeSurface::*)(TopOpeBRepDS_ShapeSurface &)) &TopOpeBRepDS_ShapeSurface::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_ShapeSurface.def("Assign", (TopOpeBRepDS_ShapeSurface & (TopOpeBRepDS_ShapeSurface::*)(const TopOpeBRepDS_ShapeSurface &)) &TopOpeBRepDS_ShapeSurface::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_ShapeSurface.def("assign", (TopOpeBRepDS_ShapeSurface & (TopOpeBRepDS_ShapeSurface::*)(const TopOpeBRepDS_ShapeSurface &)) &TopOpeBRepDS_ShapeSurface::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_ShapeSurface.def("ReSize", (void (TopOpeBRepDS_ShapeSurface::*)(const Standard_Integer)) &TopOpeBRepDS_ShapeSurface::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_ShapeSurface.def("Bind", (Standard_Boolean (TopOpeBRepDS_ShapeSurface::*)(const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &)) &TopOpeBRepDS_ShapeSurface::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepDS_ShapeSurface.def("Bound", (opencascade::handle<Geom_Surface> * (TopOpeBRepDS_ShapeSurface::*)(const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &)) &TopOpeBRepDS_ShapeSurface::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepDS_ShapeSurface.def("IsBound", (Standard_Boolean (TopOpeBRepDS_ShapeSurface::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_ShapeSurface::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepDS_ShapeSurface.def("UnBind", (Standard_Boolean (TopOpeBRepDS_ShapeSurface::*)(const TopoDS_Shape &)) &TopOpeBRepDS_ShapeSurface::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_ShapeSurface.def("Seek", (const opencascade::handle<Geom_Surface> * (TopOpeBRepDS_ShapeSurface::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_ShapeSurface::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_ShapeSurface.def("Find", (const opencascade::handle<Geom_Surface> & (TopOpeBRepDS_ShapeSurface::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_ShapeSurface::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_ShapeSurface.def("Find", (Standard_Boolean (TopOpeBRepDS_ShapeSurface::*)(const TopoDS_Shape &, opencascade::handle<Geom_Surface> &) const ) &TopOpeBRepDS_ShapeSurface::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepDS_ShapeSurface.def("__call__", (const opencascade::handle<Geom_Surface> & (TopOpeBRepDS_ShapeSurface::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_ShapeSurface::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_ShapeSurface.def("ChangeSeek", (opencascade::handle<Geom_Surface> * (TopOpeBRepDS_ShapeSurface::*)(const TopoDS_Shape &)) &TopOpeBRepDS_ShapeSurface::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepDS_ShapeSurface.def("ChangeFind", (opencascade::handle<Geom_Surface> & (TopOpeBRepDS_ShapeSurface::*)(const TopoDS_Shape &)) &TopOpeBRepDS_ShapeSurface::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepDS_ShapeSurface.def("__call__", (opencascade::handle<Geom_Surface> & (TopOpeBRepDS_ShapeSurface::*)(const TopoDS_Shape &)) &TopOpeBRepDS_ShapeSurface::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepDS_ShapeSurface.def("Clear", [](TopOpeBRepDS_ShapeSurface &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_ShapeSurface.def("Clear", (void (TopOpeBRepDS_ShapeSurface::*)(const Standard_Boolean)) &TopOpeBRepDS_ShapeSurface::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_ShapeSurface.def("Clear", (void (TopOpeBRepDS_ShapeSurface::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_ShapeSurface::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_ShapeSurface.def("Size", (Standard_Integer (TopOpeBRepDS_ShapeSurface::*)() const ) &TopOpeBRepDS_ShapeSurface::Size, "Size");
	cls_TopOpeBRepDS_ShapeSurface.def("__iter__", [](const TopOpeBRepDS_ShapeSurface &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_ShapeSurface.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<TopOpeBRepDS_IndexedDataMapOfShapeWithState, std::unique_ptr<TopOpeBRepDS_IndexedDataMapOfShapeWithState, Deleter<TopOpeBRepDS_IndexedDataMapOfShapeWithState>>, NCollection_BaseMap> cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState(mod, "TopOpeBRepDS_IndexedDataMapOfShapeWithState", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def(py::init<>());
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def(py::init([] (const TopOpeBRepDS_IndexedDataMapOfShapeWithState &other) {return new TopOpeBRepDS_IndexedDataMapOfShapeWithState(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("begin", (TopOpeBRepDS_IndexedDataMapOfShapeWithState::iterator (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)() const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("end", (TopOpeBRepDS_IndexedDataMapOfShapeWithState::iterator (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)() const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("cbegin", (TopOpeBRepDS_IndexedDataMapOfShapeWithState::const_iterator (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)() const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("cend", (TopOpeBRepDS_IndexedDataMapOfShapeWithState::const_iterator (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)() const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("Exchange", (void (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(TopOpeBRepDS_IndexedDataMapOfShapeWithState &)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("Assign", (TopOpeBRepDS_IndexedDataMapOfShapeWithState & (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const TopOpeBRepDS_IndexedDataMapOfShapeWithState &)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("assign", (TopOpeBRepDS_IndexedDataMapOfShapeWithState & (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const TopOpeBRepDS_IndexedDataMapOfShapeWithState &)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("ReSize", (void (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const Standard_Integer)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("Add", (Standard_Integer (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const TopoDS_Shape &, const TopOpeBRepDS_ShapeWithState &)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("Contains", (Standard_Boolean (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::Contains, "Contains", py::arg("theKey1"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("Substitute", (void (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const Standard_Integer, const TopoDS_Shape &, const TopOpeBRepDS_ShapeWithState &)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("Swap", (void (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("RemoveLast", (void (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)()) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::RemoveLast, "RemoveLast");
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("RemoveFromIndex", (void (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const Standard_Integer)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("RemoveKey", (void (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const TopoDS_Shape &)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("FindKey", (const TopoDS_Shape & (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const Standard_Integer) const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::FindKey, "FindKey", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("FindFromIndex", (const TopOpeBRepDS_ShapeWithState & (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const Standard_Integer) const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("__call__", (const TopOpeBRepDS_ShapeWithState & (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const Standard_Integer) const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("ChangeFromIndex", (TopOpeBRepDS_ShapeWithState & (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const Standard_Integer)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("__call__", (TopOpeBRepDS_ShapeWithState & (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const Standard_Integer)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("FindIndex", (Standard_Integer (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("FindFromKey", (const TopOpeBRepDS_ShapeWithState & (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("ChangeFromKey", (TopOpeBRepDS_ShapeWithState & (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const TopoDS_Shape &)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("Seek", (const TopOpeBRepDS_ShapeWithState * (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("ChangeSeek", (TopOpeBRepDS_ShapeWithState * (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const TopoDS_Shape &)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("FindFromKey", (Standard_Boolean (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const TopoDS_Shape &, TopOpeBRepDS_ShapeWithState &) const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("Clear", [](TopOpeBRepDS_IndexedDataMapOfShapeWithState &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("Clear", (void (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const Standard_Boolean)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("Clear", (void (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("Size", (Standard_Integer (TopOpeBRepDS_IndexedDataMapOfShapeWithState::*)() const ) &TopOpeBRepDS_IndexedDataMapOfShapeWithState::Size, "Size");
	cls_TopOpeBRepDS_IndexedDataMapOfShapeWithState.def("__iter__", [](const TopOpeBRepDS_IndexedDataMapOfShapeWithState &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_PDataStructure.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State, std::unique_ptr<TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State, Deleter<TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State>>, NCollection_BaseMap> cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State(mod, "TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def(py::init<>());
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def(py::init([] (const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &other) {return new TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("begin", (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::iterator (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)() const ) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("end", (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::iterator (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)() const ) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("cbegin", (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::const_iterator (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)() const ) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("cend", (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::const_iterator (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)() const ) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("Exchange", (void (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("Assign", (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State & (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("assign", (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State & (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("ReSize", (void (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const Standard_Integer)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("Bind", (Standard_Boolean (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopoDS_Shape &, const TopOpeBRepDS_ListOfShapeOn1State &)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("Bound", (TopOpeBRepDS_ListOfShapeOn1State * (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopoDS_Shape &, const TopOpeBRepDS_ListOfShapeOn1State &)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("IsBound", (Standard_Boolean (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("UnBind", (Standard_Boolean (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("Seek", (const TopOpeBRepDS_ListOfShapeOn1State * (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("Find", (const TopOpeBRepDS_ListOfShapeOn1State & (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("Find", (Standard_Boolean (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopoDS_Shape &, TopOpeBRepDS_ListOfShapeOn1State &) const ) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("__call__", (const TopOpeBRepDS_ListOfShapeOn1State & (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("ChangeSeek", (TopOpeBRepDS_ListOfShapeOn1State * (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("ChangeFind", (TopOpeBRepDS_ListOfShapeOn1State & (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("__call__", (TopOpeBRepDS_ListOfShapeOn1State & (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("Clear", [](TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("Clear", (void (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const Standard_Boolean)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("Clear", (void (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("Size", (Standard_Integer (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::*)() const ) &TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State::Size, "Size");
	cls_TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.def("__iter__", [](const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepDS_DataMapOfShapeState, std::unique_ptr<TopOpeBRepDS_DataMapOfShapeState, Deleter<TopOpeBRepDS_DataMapOfShapeState>>, NCollection_BaseMap> cls_TopOpeBRepDS_DataMapOfShapeState(mod, "TopOpeBRepDS_DataMapOfShapeState", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepDS_DataMapOfShapeState.def(py::init<>());
	cls_TopOpeBRepDS_DataMapOfShapeState.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def(py::init([] (const TopOpeBRepDS_DataMapOfShapeState &other) {return new TopOpeBRepDS_DataMapOfShapeState(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("begin", (TopOpeBRepDS_DataMapOfShapeState::iterator (TopOpeBRepDS_DataMapOfShapeState::*)() const ) &TopOpeBRepDS_DataMapOfShapeState::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfShapeState.def("end", (TopOpeBRepDS_DataMapOfShapeState::iterator (TopOpeBRepDS_DataMapOfShapeState::*)() const ) &TopOpeBRepDS_DataMapOfShapeState::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfShapeState.def("cbegin", (TopOpeBRepDS_DataMapOfShapeState::const_iterator (TopOpeBRepDS_DataMapOfShapeState::*)() const ) &TopOpeBRepDS_DataMapOfShapeState::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfShapeState.def("cend", (TopOpeBRepDS_DataMapOfShapeState::const_iterator (TopOpeBRepDS_DataMapOfShapeState::*)() const ) &TopOpeBRepDS_DataMapOfShapeState::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfShapeState.def("Exchange", (void (TopOpeBRepDS_DataMapOfShapeState::*)(TopOpeBRepDS_DataMapOfShapeState &)) &TopOpeBRepDS_DataMapOfShapeState::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("Assign", (TopOpeBRepDS_DataMapOfShapeState & (TopOpeBRepDS_DataMapOfShapeState::*)(const TopOpeBRepDS_DataMapOfShapeState &)) &TopOpeBRepDS_DataMapOfShapeState::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("assign", (TopOpeBRepDS_DataMapOfShapeState & (TopOpeBRepDS_DataMapOfShapeState::*)(const TopOpeBRepDS_DataMapOfShapeState &)) &TopOpeBRepDS_DataMapOfShapeState::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("ReSize", (void (TopOpeBRepDS_DataMapOfShapeState::*)(const Standard_Integer)) &TopOpeBRepDS_DataMapOfShapeState::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("Bind", (Standard_Boolean (TopOpeBRepDS_DataMapOfShapeState::*)(const TopoDS_Shape &, const TopAbs_State &)) &TopOpeBRepDS_DataMapOfShapeState::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepDS_DataMapOfShapeState.def("Bound", (TopAbs_State * (TopOpeBRepDS_DataMapOfShapeState::*)(const TopoDS_Shape &, const TopAbs_State &)) &TopOpeBRepDS_DataMapOfShapeState::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("IsBound", (Standard_Boolean (TopOpeBRepDS_DataMapOfShapeState::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataMapOfShapeState::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("UnBind", (Standard_Boolean (TopOpeBRepDS_DataMapOfShapeState::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataMapOfShapeState::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfShapeState.def("Seek", (const TopAbs_State * (TopOpeBRepDS_DataMapOfShapeState::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataMapOfShapeState::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfShapeState.def("Find", (const TopAbs_State & (TopOpeBRepDS_DataMapOfShapeState::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataMapOfShapeState::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfShapeState.def("Find", (Standard_Boolean (TopOpeBRepDS_DataMapOfShapeState::*)(const TopoDS_Shape &, TopAbs_State &) const ) &TopOpeBRepDS_DataMapOfShapeState::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("__call__", (const TopAbs_State & (TopOpeBRepDS_DataMapOfShapeState::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DataMapOfShapeState::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfShapeState.def("ChangeSeek", (TopAbs_State * (TopOpeBRepDS_DataMapOfShapeState::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataMapOfShapeState::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("ChangeFind", (TopAbs_State & (TopOpeBRepDS_DataMapOfShapeState::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataMapOfShapeState::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("__call__", (TopAbs_State & (TopOpeBRepDS_DataMapOfShapeState::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataMapOfShapeState::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("Clear", [](TopOpeBRepDS_DataMapOfShapeState &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_DataMapOfShapeState.def("Clear", (void (TopOpeBRepDS_DataMapOfShapeState::*)(const Standard_Boolean)) &TopOpeBRepDS_DataMapOfShapeState::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("Clear", (void (TopOpeBRepDS_DataMapOfShapeState::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_DataMapOfShapeState::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfShapeState.def("Size", (Standard_Integer (TopOpeBRepDS_DataMapOfShapeState::*)() const ) &TopOpeBRepDS_DataMapOfShapeState::Size, "Size");
	cls_TopOpeBRepDS_DataMapOfShapeState.def("__iter__", [](const TopOpeBRepDS_DataMapOfShapeState &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_DataMapOfShapeState.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepDS_DataMapOfIntegerListOfInterference, std::unique_ptr<TopOpeBRepDS_DataMapOfIntegerListOfInterference, Deleter<TopOpeBRepDS_DataMapOfIntegerListOfInterference>>, NCollection_BaseMap> cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference(mod, "TopOpeBRepDS_DataMapOfIntegerListOfInterference", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def(py::init<>());
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def(py::init([] (const TopOpeBRepDS_DataMapOfIntegerListOfInterference &other) {return new TopOpeBRepDS_DataMapOfIntegerListOfInterference(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("begin", (TopOpeBRepDS_DataMapOfIntegerListOfInterference::iterator (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("end", (TopOpeBRepDS_DataMapOfIntegerListOfInterference::iterator (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("cbegin", (TopOpeBRepDS_DataMapOfIntegerListOfInterference::const_iterator (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("cend", (TopOpeBRepDS_DataMapOfIntegerListOfInterference::const_iterator (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("Exchange", (void (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(TopOpeBRepDS_DataMapOfIntegerListOfInterference &)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("Assign", (TopOpeBRepDS_DataMapOfIntegerListOfInterference & (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const TopOpeBRepDS_DataMapOfIntegerListOfInterference &)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("assign", (TopOpeBRepDS_DataMapOfIntegerListOfInterference & (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const TopOpeBRepDS_DataMapOfIntegerListOfInterference &)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("ReSize", (void (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("Bind", (Standard_Boolean (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer &, const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("Bound", (TopOpeBRepDS_ListOfInterference * (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer &, const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("IsBound", (Standard_Boolean (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer &) const ) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("UnBind", (Standard_Boolean (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer &)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("Seek", (const TopOpeBRepDS_ListOfInterference * (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer &) const ) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("Find", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer &) const ) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("Find", (Standard_Boolean (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer &, TopOpeBRepDS_ListOfInterference &) const ) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("__call__", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer &) const ) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("ChangeSeek", (TopOpeBRepDS_ListOfInterference * (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer &)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("ChangeFind", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer &)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("__call__", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Integer &)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("Clear", [](TopOpeBRepDS_DataMapOfIntegerListOfInterference &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("Clear", (void (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const Standard_Boolean)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("Clear", (void (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("Size", (Standard_Integer (TopOpeBRepDS_DataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_DataMapOfIntegerListOfInterference::Size, "Size");
	cls_TopOpeBRepDS_DataMapOfIntegerListOfInterference.def("__iter__", [](const TopOpeBRepDS_DataMapOfIntegerListOfInterference &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_DataMapOfIntegerListOfInterference.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.hxx
	py::class_<TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference, opencascade::handle<TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference>, TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference, Standard_Transient> cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference(mod, "TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference", "None");
	cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def(py::init<const Standard_Integer, const Standard_Integer, const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def(py::init<const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference &>(), py::arg("theOther"));
	cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def("Array1", (const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference & (TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::Array1, "None");
	cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def("ChangeArray1", (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference & (TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::*)()) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::ChangeArray1, "None");
	cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::get_type_name, "None");
	cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::get_type_descriptor, "None");
	cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::*)() const ) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepDS_DataMapOfInterferenceListOfInterference, std::unique_ptr<TopOpeBRepDS_DataMapOfInterferenceListOfInterference, Deleter<TopOpeBRepDS_DataMapOfInterferenceListOfInterference>>, NCollection_BaseMap> cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference(mod, "TopOpeBRepDS_DataMapOfInterferenceListOfInterference", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def(py::init<>());
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def(py::init([] (const TopOpeBRepDS_DataMapOfInterferenceListOfInterference &other) {return new TopOpeBRepDS_DataMapOfInterferenceListOfInterference(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("begin", (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::iterator (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)() const ) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("end", (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::iterator (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)() const ) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("cbegin", (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::const_iterator (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)() const ) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("cend", (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::const_iterator (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)() const ) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("Exchange", (void (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(TopOpeBRepDS_DataMapOfInterferenceListOfInterference &)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("Assign", (TopOpeBRepDS_DataMapOfInterferenceListOfInterference & (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const TopOpeBRepDS_DataMapOfInterferenceListOfInterference &)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("assign", (TopOpeBRepDS_DataMapOfInterferenceListOfInterference & (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const TopOpeBRepDS_DataMapOfInterferenceListOfInterference &)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("ReSize", (void (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const Standard_Integer)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("Bind", (Standard_Boolean (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("Bound", (TopOpeBRepDS_ListOfInterference * (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("IsBound", (Standard_Boolean (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("UnBind", (Standard_Boolean (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("Seek", (const TopOpeBRepDS_ListOfInterference * (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("Find", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("Find", (Standard_Boolean (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference &) const ) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("__call__", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("ChangeSeek", (TopOpeBRepDS_ListOfInterference * (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("ChangeFind", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("__call__", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("Clear", [](TopOpeBRepDS_DataMapOfInterferenceListOfInterference &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("Clear", (void (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const Standard_Boolean)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("Clear", (void (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("Size", (Standard_Integer (TopOpeBRepDS_DataMapOfInterferenceListOfInterference::*)() const ) &TopOpeBRepDS_DataMapOfInterferenceListOfInterference::Size, "Size");
	cls_TopOpeBRepDS_DataMapOfInterferenceListOfInterference.def("__iter__", [](const TopOpeBRepDS_DataMapOfInterferenceListOfInterference &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_DataMapOfInterferenceListOfInterference.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepDS_DataMapOfCheckStatus, std::unique_ptr<TopOpeBRepDS_DataMapOfCheckStatus, Deleter<TopOpeBRepDS_DataMapOfCheckStatus>>, NCollection_BaseMap> cls_TopOpeBRepDS_DataMapOfCheckStatus(mod, "TopOpeBRepDS_DataMapOfCheckStatus", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def(py::init<>());
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def(py::init([] (const TopOpeBRepDS_DataMapOfCheckStatus &other) {return new TopOpeBRepDS_DataMapOfCheckStatus(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("begin", (TopOpeBRepDS_DataMapOfCheckStatus::iterator (TopOpeBRepDS_DataMapOfCheckStatus::*)() const ) &TopOpeBRepDS_DataMapOfCheckStatus::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("end", (TopOpeBRepDS_DataMapOfCheckStatus::iterator (TopOpeBRepDS_DataMapOfCheckStatus::*)() const ) &TopOpeBRepDS_DataMapOfCheckStatus::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("cbegin", (TopOpeBRepDS_DataMapOfCheckStatus::const_iterator (TopOpeBRepDS_DataMapOfCheckStatus::*)() const ) &TopOpeBRepDS_DataMapOfCheckStatus::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("cend", (TopOpeBRepDS_DataMapOfCheckStatus::const_iterator (TopOpeBRepDS_DataMapOfCheckStatus::*)() const ) &TopOpeBRepDS_DataMapOfCheckStatus::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("Exchange", (void (TopOpeBRepDS_DataMapOfCheckStatus::*)(TopOpeBRepDS_DataMapOfCheckStatus &)) &TopOpeBRepDS_DataMapOfCheckStatus::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("Assign", (TopOpeBRepDS_DataMapOfCheckStatus & (TopOpeBRepDS_DataMapOfCheckStatus::*)(const TopOpeBRepDS_DataMapOfCheckStatus &)) &TopOpeBRepDS_DataMapOfCheckStatus::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("assign", (TopOpeBRepDS_DataMapOfCheckStatus & (TopOpeBRepDS_DataMapOfCheckStatus::*)(const TopOpeBRepDS_DataMapOfCheckStatus &)) &TopOpeBRepDS_DataMapOfCheckStatus::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("ReSize", (void (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer)) &TopOpeBRepDS_DataMapOfCheckStatus::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("Bind", (Standard_Boolean (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer &, const TopOpeBRepDS_CheckStatus &)) &TopOpeBRepDS_DataMapOfCheckStatus::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepDS_DataMapOfCheckStatus.def("Bound", (TopOpeBRepDS_CheckStatus * (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer &, const TopOpeBRepDS_CheckStatus &)) &TopOpeBRepDS_DataMapOfCheckStatus::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("IsBound", (Standard_Boolean (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer &) const ) &TopOpeBRepDS_DataMapOfCheckStatus::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("UnBind", (Standard_Boolean (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer &)) &TopOpeBRepDS_DataMapOfCheckStatus::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfCheckStatus.def("Seek", (const TopOpeBRepDS_CheckStatus * (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer &) const ) &TopOpeBRepDS_DataMapOfCheckStatus::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfCheckStatus.def("Find", (const TopOpeBRepDS_CheckStatus & (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer &) const ) &TopOpeBRepDS_DataMapOfCheckStatus::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfCheckStatus.def("Find", (Standard_Boolean (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer &, TopOpeBRepDS_CheckStatus &) const ) &TopOpeBRepDS_DataMapOfCheckStatus::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("__call__", (const TopOpeBRepDS_CheckStatus & (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer &) const ) &TopOpeBRepDS_DataMapOfCheckStatus::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfCheckStatus.def("ChangeSeek", (TopOpeBRepDS_CheckStatus * (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer &)) &TopOpeBRepDS_DataMapOfCheckStatus::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("ChangeFind", (TopOpeBRepDS_CheckStatus & (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer &)) &TopOpeBRepDS_DataMapOfCheckStatus::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("__call__", (TopOpeBRepDS_CheckStatus & (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Integer &)) &TopOpeBRepDS_DataMapOfCheckStatus::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("Clear", [](TopOpeBRepDS_DataMapOfCheckStatus &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("Clear", (void (TopOpeBRepDS_DataMapOfCheckStatus::*)(const Standard_Boolean)) &TopOpeBRepDS_DataMapOfCheckStatus::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("Clear", (void (TopOpeBRepDS_DataMapOfCheckStatus::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_DataMapOfCheckStatus::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("Size", (Standard_Integer (TopOpeBRepDS_DataMapOfCheckStatus::*)() const ) &TopOpeBRepDS_DataMapOfCheckStatus::Size, "Size");
	cls_TopOpeBRepDS_DataMapOfCheckStatus.def("__iter__", [](const TopOpeBRepDS_DataMapOfCheckStatus &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_DataMapOfCheckStatus.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepDS_DataMapOfInterferenceShape, std::unique_ptr<TopOpeBRepDS_DataMapOfInterferenceShape, Deleter<TopOpeBRepDS_DataMapOfInterferenceShape>>, NCollection_BaseMap> cls_TopOpeBRepDS_DataMapOfInterferenceShape(mod, "TopOpeBRepDS_DataMapOfInterferenceShape", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def(py::init<>());
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def(py::init([] (const TopOpeBRepDS_DataMapOfInterferenceShape &other) {return new TopOpeBRepDS_DataMapOfInterferenceShape(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("begin", (TopOpeBRepDS_DataMapOfInterferenceShape::iterator (TopOpeBRepDS_DataMapOfInterferenceShape::*)() const ) &TopOpeBRepDS_DataMapOfInterferenceShape::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("end", (TopOpeBRepDS_DataMapOfInterferenceShape::iterator (TopOpeBRepDS_DataMapOfInterferenceShape::*)() const ) &TopOpeBRepDS_DataMapOfInterferenceShape::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("cbegin", (TopOpeBRepDS_DataMapOfInterferenceShape::const_iterator (TopOpeBRepDS_DataMapOfInterferenceShape::*)() const ) &TopOpeBRepDS_DataMapOfInterferenceShape::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("cend", (TopOpeBRepDS_DataMapOfInterferenceShape::const_iterator (TopOpeBRepDS_DataMapOfInterferenceShape::*)() const ) &TopOpeBRepDS_DataMapOfInterferenceShape::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("Exchange", (void (TopOpeBRepDS_DataMapOfInterferenceShape::*)(TopOpeBRepDS_DataMapOfInterferenceShape &)) &TopOpeBRepDS_DataMapOfInterferenceShape::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("Assign", (TopOpeBRepDS_DataMapOfInterferenceShape & (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const TopOpeBRepDS_DataMapOfInterferenceShape &)) &TopOpeBRepDS_DataMapOfInterferenceShape::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("assign", (TopOpeBRepDS_DataMapOfInterferenceShape & (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const TopOpeBRepDS_DataMapOfInterferenceShape &)) &TopOpeBRepDS_DataMapOfInterferenceShape::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("ReSize", (void (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const Standard_Integer)) &TopOpeBRepDS_DataMapOfInterferenceShape::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("Bind", (Standard_Boolean (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &)) &TopOpeBRepDS_DataMapOfInterferenceShape::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("Bound", (TopoDS_Shape * (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &)) &TopOpeBRepDS_DataMapOfInterferenceShape::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("IsBound", (Standard_Boolean (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_DataMapOfInterferenceShape::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("UnBind", (Standard_Boolean (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataMapOfInterferenceShape::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("Seek", (const TopoDS_Shape * (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_DataMapOfInterferenceShape::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("Find", (const TopoDS_Shape & (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_DataMapOfInterferenceShape::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("Find", (Standard_Boolean (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopoDS_Shape &) const ) &TopOpeBRepDS_DataMapOfInterferenceShape::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("__call__", (const TopoDS_Shape & (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const ) &TopOpeBRepDS_DataMapOfInterferenceShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("ChangeSeek", (TopoDS_Shape * (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataMapOfInterferenceShape::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("ChangeFind", (TopoDS_Shape & (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataMapOfInterferenceShape::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("__call__", (TopoDS_Shape & (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataMapOfInterferenceShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("Clear", [](TopOpeBRepDS_DataMapOfInterferenceShape &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("Clear", (void (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const Standard_Boolean)) &TopOpeBRepDS_DataMapOfInterferenceShape::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("Clear", (void (TopOpeBRepDS_DataMapOfInterferenceShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_DataMapOfInterferenceShape::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("Size", (Standard_Integer (TopOpeBRepDS_DataMapOfInterferenceShape::*)() const ) &TopOpeBRepDS_DataMapOfInterferenceShape::Size, "Size");
	cls_TopOpeBRepDS_DataMapOfInterferenceShape.def("__iter__", [](const TopOpeBRepDS_DataMapOfInterferenceShape &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_DataMapOfInterferenceShape.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepDS_MapOfIntegerShapeData, std::unique_ptr<TopOpeBRepDS_MapOfIntegerShapeData, Deleter<TopOpeBRepDS_MapOfIntegerShapeData>>, NCollection_BaseMap> cls_TopOpeBRepDS_MapOfIntegerShapeData(mod, "TopOpeBRepDS_MapOfIntegerShapeData", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def(py::init<>());
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def(py::init([] (const TopOpeBRepDS_MapOfIntegerShapeData &other) {return new TopOpeBRepDS_MapOfIntegerShapeData(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("begin", (TopOpeBRepDS_MapOfIntegerShapeData::iterator (TopOpeBRepDS_MapOfIntegerShapeData::*)() const ) &TopOpeBRepDS_MapOfIntegerShapeData::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("end", (TopOpeBRepDS_MapOfIntegerShapeData::iterator (TopOpeBRepDS_MapOfIntegerShapeData::*)() const ) &TopOpeBRepDS_MapOfIntegerShapeData::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("cbegin", (TopOpeBRepDS_MapOfIntegerShapeData::const_iterator (TopOpeBRepDS_MapOfIntegerShapeData::*)() const ) &TopOpeBRepDS_MapOfIntegerShapeData::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("cend", (TopOpeBRepDS_MapOfIntegerShapeData::const_iterator (TopOpeBRepDS_MapOfIntegerShapeData::*)() const ) &TopOpeBRepDS_MapOfIntegerShapeData::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("Exchange", (void (TopOpeBRepDS_MapOfIntegerShapeData::*)(TopOpeBRepDS_MapOfIntegerShapeData &)) &TopOpeBRepDS_MapOfIntegerShapeData::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("Assign", (TopOpeBRepDS_MapOfIntegerShapeData & (TopOpeBRepDS_MapOfIntegerShapeData::*)(const TopOpeBRepDS_MapOfIntegerShapeData &)) &TopOpeBRepDS_MapOfIntegerShapeData::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("assign", (TopOpeBRepDS_MapOfIntegerShapeData & (TopOpeBRepDS_MapOfIntegerShapeData::*)(const TopOpeBRepDS_MapOfIntegerShapeData &)) &TopOpeBRepDS_MapOfIntegerShapeData::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("ReSize", (void (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer)) &TopOpeBRepDS_MapOfIntegerShapeData::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("Bind", (Standard_Boolean (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer &, const TopOpeBRepDS_ShapeData &)) &TopOpeBRepDS_MapOfIntegerShapeData::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepDS_MapOfIntegerShapeData.def("Bound", (TopOpeBRepDS_ShapeData * (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer &, const TopOpeBRepDS_ShapeData &)) &TopOpeBRepDS_MapOfIntegerShapeData::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("IsBound", (Standard_Boolean (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfIntegerShapeData::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("UnBind", (Standard_Boolean (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfIntegerShapeData::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfIntegerShapeData.def("Seek", (const TopOpeBRepDS_ShapeData * (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfIntegerShapeData::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfIntegerShapeData.def("Find", (const TopOpeBRepDS_ShapeData & (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfIntegerShapeData::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfIntegerShapeData.def("Find", (Standard_Boolean (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer &, TopOpeBRepDS_ShapeData &) const ) &TopOpeBRepDS_MapOfIntegerShapeData::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("__call__", (const TopOpeBRepDS_ShapeData & (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer &) const ) &TopOpeBRepDS_MapOfIntegerShapeData::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepDS_MapOfIntegerShapeData.def("ChangeSeek", (TopOpeBRepDS_ShapeData * (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfIntegerShapeData::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("ChangeFind", (TopOpeBRepDS_ShapeData & (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfIntegerShapeData::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("__call__", (TopOpeBRepDS_ShapeData & (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Integer &)) &TopOpeBRepDS_MapOfIntegerShapeData::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("Clear", [](TopOpeBRepDS_MapOfIntegerShapeData &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("Clear", (void (TopOpeBRepDS_MapOfIntegerShapeData::*)(const Standard_Boolean)) &TopOpeBRepDS_MapOfIntegerShapeData::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("Clear", (void (TopOpeBRepDS_MapOfIntegerShapeData::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_MapOfIntegerShapeData::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("Size", (Standard_Integer (TopOpeBRepDS_MapOfIntegerShapeData::*)() const ) &TopOpeBRepDS_MapOfIntegerShapeData::Size, "Size");
	cls_TopOpeBRepDS_MapOfIntegerShapeData.def("__iter__", [](const TopOpeBRepDS_MapOfIntegerShapeData &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_MapOfIntegerShapeData.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DoubleMap.hxx
	py::class_<TopOpeBRepDS_DoubleMapOfIntegerShape, std::unique_ptr<TopOpeBRepDS_DoubleMapOfIntegerShape, Deleter<TopOpeBRepDS_DoubleMapOfIntegerShape>>, NCollection_BaseMap> cls_TopOpeBRepDS_DoubleMapOfIntegerShape(mod, "TopOpeBRepDS_DoubleMapOfIntegerShape", "Purpose: The DoubleMap is used to bind pairs (Key1,Key2) and retrieve them in linear time.");
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def(py::init<>());
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def(py::init([] (const TopOpeBRepDS_DoubleMapOfIntegerShape &other) {return new TopOpeBRepDS_DoubleMapOfIntegerShape(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("Exchange", (void (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(TopOpeBRepDS_DoubleMapOfIntegerShape &)) &TopOpeBRepDS_DoubleMapOfIntegerShape::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("Assign", (TopOpeBRepDS_DoubleMapOfIntegerShape & (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const TopOpeBRepDS_DoubleMapOfIntegerShape &)) &TopOpeBRepDS_DoubleMapOfIntegerShape::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("assign", (TopOpeBRepDS_DoubleMapOfIntegerShape & (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const TopOpeBRepDS_DoubleMapOfIntegerShape &)) &TopOpeBRepDS_DoubleMapOfIntegerShape::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("ReSize", (void (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const Standard_Integer)) &TopOpeBRepDS_DoubleMapOfIntegerShape::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("Bind", (void (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const Standard_Integer &, const TopoDS_Shape &)) &TopOpeBRepDS_DoubleMapOfIntegerShape::Bind, "Bind", py::arg("theKey1"), py::arg("theKey2"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("AreBound", (Standard_Boolean (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const Standard_Integer &, const TopoDS_Shape &) const ) &TopOpeBRepDS_DoubleMapOfIntegerShape::AreBound, "* AreBound", py::arg("theKey1"), py::arg("theKey2"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("IsBound1", (Standard_Boolean (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const Standard_Integer &) const ) &TopOpeBRepDS_DoubleMapOfIntegerShape::IsBound1, "IsBound1", py::arg("theKey1"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("IsBound2", (Standard_Boolean (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DoubleMapOfIntegerShape::IsBound2, "IsBound2", py::arg("theKey2"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("UnBind1", (Standard_Boolean (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const Standard_Integer &)) &TopOpeBRepDS_DoubleMapOfIntegerShape::UnBind1, "UnBind1", py::arg("theKey1"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("UnBind2", (Standard_Boolean (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DoubleMapOfIntegerShape::UnBind2, "UnBind2", py::arg("theKey2"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("Find1", (const TopoDS_Shape & (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const Standard_Integer &) const ) &TopOpeBRepDS_DoubleMapOfIntegerShape::Find1, "Find1", py::arg("theKey1"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("Find2", (const Standard_Integer & (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_DoubleMapOfIntegerShape::Find2, "Find2", py::arg("theKey2"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("Clear", [](TopOpeBRepDS_DoubleMapOfIntegerShape &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("Clear", (void (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const Standard_Boolean)) &TopOpeBRepDS_DoubleMapOfIntegerShape::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("Clear", (void (TopOpeBRepDS_DoubleMapOfIntegerShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_DoubleMapOfIntegerShape::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_DoubleMapOfIntegerShape.def("Size", (Standard_Integer (TopOpeBRepDS_DoubleMapOfIntegerShape::*)() const ) &TopOpeBRepDS_DoubleMapOfIntegerShape::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepDS_DoubleMapOfIntegerShape.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<TopOpeBRepDS_IndexedDataMapOfVertexPoint, std::unique_ptr<TopOpeBRepDS_IndexedDataMapOfVertexPoint, Deleter<TopOpeBRepDS_IndexedDataMapOfVertexPoint>>, NCollection_BaseMap> cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint(mod, "TopOpeBRepDS_IndexedDataMapOfVertexPoint", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def(py::init<>());
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def(py::init([] (const TopOpeBRepDS_IndexedDataMapOfVertexPoint &other) {return new TopOpeBRepDS_IndexedDataMapOfVertexPoint(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("begin", (TopOpeBRepDS_IndexedDataMapOfVertexPoint::iterator (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)() const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("end", (TopOpeBRepDS_IndexedDataMapOfVertexPoint::iterator (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)() const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("cbegin", (TopOpeBRepDS_IndexedDataMapOfVertexPoint::const_iterator (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)() const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("cend", (TopOpeBRepDS_IndexedDataMapOfVertexPoint::const_iterator (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)() const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("Exchange", (void (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(TopOpeBRepDS_IndexedDataMapOfVertexPoint &)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("Assign", (TopOpeBRepDS_IndexedDataMapOfVertexPoint & (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const TopOpeBRepDS_IndexedDataMapOfVertexPoint &)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("assign", (TopOpeBRepDS_IndexedDataMapOfVertexPoint & (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const TopOpeBRepDS_IndexedDataMapOfVertexPoint &)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("ReSize", (void (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const Standard_Integer)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("Add", (Standard_Integer (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const TopoDS_Shape &, const TopOpeBRepDS_Point &)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("Contains", (Standard_Boolean (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::Contains, "Contains", py::arg("theKey1"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("Substitute", (void (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const Standard_Integer, const TopoDS_Shape &, const TopOpeBRepDS_Point &)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("Swap", (void (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("RemoveLast", (void (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)()) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::RemoveLast, "RemoveLast");
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("RemoveFromIndex", (void (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const Standard_Integer)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("RemoveKey", (void (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const TopoDS_Shape &)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("FindKey", (const TopoDS_Shape & (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const Standard_Integer) const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::FindKey, "FindKey", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("FindFromIndex", (const TopOpeBRepDS_Point & (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const Standard_Integer) const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("__call__", (const TopOpeBRepDS_Point & (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const Standard_Integer) const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("ChangeFromIndex", (TopOpeBRepDS_Point & (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const Standard_Integer)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("__call__", (TopOpeBRepDS_Point & (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const Standard_Integer)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("FindIndex", (Standard_Integer (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("FindFromKey", (const TopOpeBRepDS_Point & (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("ChangeFromKey", (TopOpeBRepDS_Point & (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const TopoDS_Shape &)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("Seek", (const TopOpeBRepDS_Point * (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const TopoDS_Shape &) const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("ChangeSeek", (TopOpeBRepDS_Point * (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const TopoDS_Shape &)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("FindFromKey", (Standard_Boolean (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const TopoDS_Shape &, TopOpeBRepDS_Point &) const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("Clear", [](TopOpeBRepDS_IndexedDataMapOfVertexPoint &self) -> void { return self.Clear(); });
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("Clear", (void (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const Standard_Boolean)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("Clear", (void (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("Size", (Standard_Integer (TopOpeBRepDS_IndexedDataMapOfVertexPoint::*)() const ) &TopOpeBRepDS_IndexedDataMapOfVertexPoint::Size, "Size");
	cls_TopOpeBRepDS_IndexedDataMapOfVertexPoint.def("__iter__", [](const TopOpeBRepDS_IndexedDataMapOfVertexPoint &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
