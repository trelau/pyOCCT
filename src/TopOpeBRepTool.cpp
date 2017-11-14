#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TopExp_Explorer.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <TopOpeBRepTool_ShapeExplorer.hxx>
#include <Standard_Transient.hxx>
#include <Bnd_Box.hxx>
#include <TopOpeBRepTool_IndexedDataMapOfShapeBox.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <TopOpeBRepTool_HBoxTool.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TopOpeBRepTool_BoxSort.hxx>
#include <TopAbs_State.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepTool_SolidClassifier.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <TopOpeBRepTool_ShapeClassifier.hxx>
#include <TopOpeBRepTool_PShapeClassifier.hxx>
#include <TopOpeBRepTool_OutCurveType.hxx>
#include <TopOpeBRepTool_GeomTool.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TopOpeBRepTool_CurveTool.hxx>
#include <TopOpeBRepTool_Plos.hxx>
#include <TopOpeBRepTool_PSoClassif.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Shell.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopOpeBRepTool_AncestorsTool.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRepTool_C2DF.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Surface.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <gp_Dir.hxx>
#include <TopOpeBRepTool_ShapeTool.hxx>
#include <TopOpeBRepTool_connexity.hxx>
#include <TopoDS_Wire.hxx>
#include <TopOpeBRepTool_face.hxx>
#include <Bnd_Box2d.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopOpeBRepTool_CLASSI.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Vec2d.hxx>
#include <TopOpeBRepTool_TOOL.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <TopTools_DataMapOfOrientedShapeInteger.hxx>
#include <TopOpeBRepTool_CORRISO.hxx>
#include <TopOpeBRepTool_REGUW.hxx>
#include <TopOpeBRepTool_REGUS.hxx>
#include <TopOpeBRepTool_makeTransition.hxx>
#include <TopOpeBRepTool_mkTondgE.hxx>
#include <TopOpeBRepTool_PurgeInternalEdges.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopOpeBRepTool_FuseEdges.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TopOpeBRepTool.hxx>
#include <TopOpeBRepTool_2d.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TopOpeBRepTool_box.hxx>
#include <TopOpeBRepTool_IndexedDataMapOfShapeBox2d.hxx>
#include <NCollection_DataMap.hxx>
#include <TopOpeBRepTool_DataMapOfShapeface.hxx>
#include <TopOpeBRepTool_DataMapOfOrientedShapeC2DF.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <TopOpeBRepTool_ListOfC2DF.hxx>
#include <TopOpeBRepTool_DataMapOfShapeListOfC2DF.hxx>
#include <TopOpeBRepTool_GEOMETRY.hxx>
#include <TopOpeBRepTool_TOPOLOGY.hxx>
#include <GeomAbs_CurveType.hxx>
#include <TopOpeBRepTool_PROJECT.hxx>
#include <Extrema_ExtPC2d.hxx>
#include <BRepAdaptor_Curve2d.hxx>
#include <Extrema_ExtFlag.hxx>
#include <Extrema_ExtAlgo.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopOpeBRepTool_IndexedDataMapOfShapeconnexity.hxx>
#include <TopOpeBRepTool_IndexedDataMapOfSolidClassifier.hxx>
#include <TopOpeBRepTool_SC.hxx>
#include <TopOpeBRepTool_tol.hxx>

PYBIND11_MODULE(TopOpeBRepTool, mod) {

	// IMPORT
	py::module::import("OCCT.TopExp");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.BRepAdaptor");
	py::module::import("OCCT.GeomAdaptor");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.Extrema");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_OutCurveType.hxx
	py::enum_<TopOpeBRepTool_OutCurveType>(mod, "TopOpeBRepTool_OutCurveType", "None")
		.value("TopOpeBRepTool_BSPLINE1", TopOpeBRepTool_OutCurveType::TopOpeBRepTool_BSPLINE1)
		.value("TopOpeBRepTool_APPROX", TopOpeBRepTool_OutCurveType::TopOpeBRepTool_APPROX)
		.value("TopOpeBRepTool_INTERPOL", TopOpeBRepTool_OutCurveType::TopOpeBRepTool_INTERPOL)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_2d.hxx
	mod.def("FC2D_Prepare", (Standard_Integer (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &FC2D_Prepare, "None", py::arg("S1"), py::arg("S2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_2d.hxx
	mod.def("FC2D_HasC3D", (Standard_Boolean (*)(const TopoDS_Edge &)) &FC2D_HasC3D, "None", py::arg("E"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_2d.hxx
	mod.def("FC2D_HasCurveOnSurface", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &FC2D_HasCurveOnSurface, "None", py::arg("E"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_2d.hxx
	mod.def("FC2D_HasOldCurveOnSurface", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, opencascade::handle<Geom2d_Curve> &)) &FC2D_HasOldCurveOnSurface, "None", py::arg("E"), py::arg("F"), py::arg("C2D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_2d.hxx
	mod.def("FC2D_HasNewCurveOnSurface", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, opencascade::handle<Geom2d_Curve> &)) &FC2D_HasNewCurveOnSurface, "None", py::arg("E"), py::arg("F"), py::arg("C2D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_2d.hxx
	mod.def("FC2D_CurveOnSurface", (opencascade::handle<Geom2d_Curve> (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Edge &, Standard_Real &, Standard_Real &, Standard_Real &, const Standard_Boolean)) &FC2D_CurveOnSurface, "None", py::arg("E"), py::arg("F"), py::arg("EF"), py::arg("f"), py::arg("l"), py::arg("tol"), py::arg("trim3d") = Standard_False);

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_2d.hxx
	mod.def("FC2D_MakeCurveOnSurface", (opencascade::handle<Geom2d_Curve> (*)(const TopoDS_Edge &, const TopoDS_Face &, Standard_Real &, Standard_Real &, Standard_Real &, const Standard_Boolean)) &FC2D_MakeCurveOnSurface, "None", py::arg("E"), py::arg("F"), py::arg("f"), py::arg("l"), py::arg("tol"), py::arg("trim3d") = Standard_False);

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_2d.hxx
	mod.def("FC2D_EditableCurveOnSurface", (opencascade::handle<Geom2d_Curve> (*)(const TopoDS_Edge &, const TopoDS_Face &, Standard_Real &, Standard_Real &, Standard_Real &, const Standard_Boolean)) &FC2D_EditableCurveOnSurface, "None", py::arg("E"), py::arg("F"), py::arg("f"), py::arg("l"), py::arg("tol"), py::arg("trim3d") = Standard_False);

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_2d.hxx
	mod.def("FC2D_AddNewCurveOnSurface", (Standard_Integer (*)(opencascade::handle<Geom2d_Curve>, const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real &, const Standard_Real &, const Standard_Real &)) &FC2D_AddNewCurveOnSurface, "None", py::arg("PC"), py::arg("E"), py::arg("F"), py::arg("f"), py::arg("l"), py::arg("tol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_box.hxx
	mod.def("FBOX_Prepare", (void (*)()) &FBOX_Prepare, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_box.hxx
	mod.def("FBOX_GetHBoxTool", (opencascade::handle<TopOpeBRepTool_HBoxTool> (*)()) &FBOX_GetHBoxTool, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_box.hxx
	mod.def("FBOX_Box", (const Bnd_Box & (*)(const TopoDS_Shape &)) &FBOX_Box, "None", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_GEOMETRY.hxx
	mod.def("BASISCURVE2D", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom2d_Curve> &)) &BASISCURVE2D, "None", py::arg("C"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_dirC", (gp_Dir (*)(const Standard_Real, const BRepAdaptor_Curve &)) &FUN_tool_dirC, "None", py::arg("par"), py::arg("BAC"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_GEOMETRY.hxx
	mod.def("FUN_tool_onapex", (Standard_Boolean (*)(const gp_Pnt2d &, const opencascade::handle<Geom_Surface> &)) &FUN_tool_onapex, "None", py::arg("p2d"), py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_GEOMETRY.hxx
	mod.def("FUN_tool_ngS", (gp_Dir (*)(const gp_Pnt2d &, const opencascade::handle<Geom_Surface> &)) &FUN_tool_ngS, "None", py::arg("p2d"), py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_line", (Standard_Boolean (*)(const BRepAdaptor_Curve &)) &FUN_tool_line, "None", py::arg("BAC"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_GEOMETRY.hxx
	mod.def("FUN_quadCT", (Standard_Boolean (*)(const GeomAbs_CurveType &)) &FUN_quadCT, "None", py::arg("CT"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_quad", (Standard_Boolean (*)(const TopoDS_Face &)) &FUN_tool_quad, "None", py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_GEOMETRY.hxx
	mod.def("FUN_tool_closed", (Standard_Boolean (*)(const opencascade::handle<Geom_Surface> &, Standard_Boolean &, Standard_Real &, Standard_Boolean &, Standard_Real &)) &FUN_tool_closed, "None", py::arg("S"), py::arg("uclosed"), py::arg("uperiod"), py::arg("vclosed"), py::arg("vperiod"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_GEOMETRY.hxx
	mod.def("FUN_tool_UpdateBnd2d", (void (*)(Bnd_Box2d &, const Bnd_Box2d &)) &FUN_tool_UpdateBnd2d, "None", py::arg("B2d"), py::arg("newB2d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_GEOMETRY.hxx
	mod.def("FUN_tool_nCinsideS", (gp_Dir (*)(const gp_Dir &, const gp_Dir &)) &FUN_tool_nCinsideS, "None", py::arg("tgC"), py::arg("ngS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_GEOMETRY.hxx
	mod.def("FUN_tool_nC2dINSIDES", (gp_Dir2d (*)(const gp_Dir2d &)) &FUN_tool_nC2dINSIDES, "None", py::arg("tgC2d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_bounds", (Standard_Boolean (*)(const TopoDS_Shape &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &FUN_tool_bounds, "None", py::arg("F"), py::arg("u1"), py::arg("u2"), py::arg("v1"), py::arg("v2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_PROJECT.hxx
	mod.def("FUN_tool_getindex", (Standard_Integer (*)(const Extrema_ExtPC2d &)) &FUN_tool_getindex, "None", py::arg("ponc"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_PROJECT.hxx
	mod.def("FUN_tool_projPonC", (Standard_Boolean (*)(const gp_Pnt &, const BRepAdaptor_Curve &, Standard_Real &, Standard_Real &)) &FUN_tool_projPonC, "None", py::arg("P"), py::arg("BAC"), py::arg("param"), py::arg("dist"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_PROJECT.hxx
	mod.def("FUN_tool_projPonC2D", (Standard_Boolean (*)(const gp_Pnt &, const BRepAdaptor_Curve2d &, Standard_Real &, Standard_Real &)) &FUN_tool_projPonC2D, "None", py::arg("P"), py::arg("BAC2D"), py::arg("param"), py::arg("dist"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_PROJECT.hxx
	mod.def("FUN_tool_projPonS", (Standard_Boolean (*)(const gp_Pnt &, const opencascade::handle<Geom_Surface> &, gp_Pnt2d &, Standard_Real &, const Extrema_ExtFlag, const Extrema_ExtAlgo)) &FUN_tool_projPonS, "None", py::arg("P"), py::arg("S"), py::arg("UV"), py::arg("dist"), py::arg("anExtFlag") = Extrema_ExtFlag_MINMAX, py::arg("anExtAlgo") = Extrema_ExtAlgo_Grad);

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_PROJECT.hxx
	mod.def("FUN_tool_projPonE", (Standard_Boolean (*)(const gp_Pnt &, const TopoDS_Edge &, Standard_Real &, Standard_Real &)) &FUN_tool_projPonE, "None", py::arg("P"), py::arg("E"), py::arg("param"), py::arg("dist"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_PROJECT.hxx
	mod.def("FUN_tool_projPonboundedF", (Standard_Boolean (*)(const gp_Pnt &, const TopoDS_Face &, gp_Pnt2d &, Standard_Real &)) &FUN_tool_projPonboundedF, "None", py::arg("P"), py::arg("F"), py::arg("UV"), py::arg("dist"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_PROJECT.hxx
	mod.def("FUN_tool_projPonF", (Standard_Boolean (*)(const gp_Pnt &, const TopoDS_Face &, gp_Pnt2d &, Standard_Real &, const Extrema_ExtFlag, const Extrema_ExtAlgo)) &FUN_tool_projPonF, "None", py::arg("P"), py::arg("F"), py::arg("UV"), py::arg("dist"), py::arg("anExtFlag") = Extrema_ExtFlag_MINMAX, py::arg("anExtAlgo") = Extrema_ExtAlgo_Grad);

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_tolUV", (void (*)(const TopoDS_Face &, Standard_Real &, Standard_Real &)) &FUN_tool_tolUV, "None", py::arg("F"), py::arg("tolu"), py::arg("tolv"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_direct", (Standard_Boolean (*)(const TopoDS_Face &, Standard_Boolean &)) &FUN_tool_direct, "None", py::arg("F"), py::arg("direct"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_geombounds", (Standard_Boolean (*)(const TopoDS_Face &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &FUN_tool_geombounds, "None", py::arg("F"), py::arg("u1"), py::arg("u2"), py::arg("v1"), py::arg("v2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_isobounds", (Standard_Boolean (*)(const TopoDS_Shape &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &FUN_tool_isobounds, "None", py::arg("F"), py::arg("u1"), py::arg("u2"), py::arg("v1"), py::arg("v2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_outbounds", (Standard_Boolean (*)(const TopoDS_Shape &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Boolean &)) &FUN_tool_outbounds, "None", py::arg("Sh"), py::arg("u1"), py::arg("u2"), py::arg("v1"), py::arg("v2"), py::arg("outbounds"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_PinC", (Standard_Boolean (*)(const gp_Pnt &, const BRepAdaptor_Curve &, const Standard_Real)) &FUN_tool_PinC, "None", py::arg("P"), py::arg("BAC"), py::arg("tol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_value", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &, gp_Pnt &)) &FUN_tool_value, "None", py::arg("UV"), py::arg("F"), py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_staPinE", (TopAbs_State (*)(const gp_Pnt &, const TopoDS_Edge &)) &FUN_tool_staPinE, "None", py::arg("P"), py::arg("E"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_orientVinE", (Standard_Integer (*)(const TopoDS_Vertex &, const TopoDS_Edge &)) &FUN_tool_orientVinE, "None", py::arg("v"), py::arg("e"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_orientEinF", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, TopAbs_Orientation &)) &FUN_tool_orientEinF, "None", py::arg("E"), py::arg("F"), py::arg("oriEinF"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_orientEinFFORWARD", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, TopAbs_Orientation &)) &FUN_tool_orientEinFFORWARD, "None", py::arg("E"), py::arg("F"), py::arg("oriEinF"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_EboundF", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &FUN_tool_EboundF, "None", py::arg("E"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_nggeomF", (Standard_Boolean (*)(const Standard_Real &, const TopoDS_Edge &, const TopoDS_Face &, gp_Vec &, const Standard_Real)) &FUN_tool_nggeomF, "None", py::arg("paronE"), py::arg("E"), py::arg("F"), py::arg("nggeomF"), py::arg("tol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_EtgF", (Standard_Boolean (*)(const Standard_Real &, const TopoDS_Edge &, const gp_Pnt2d &, const TopoDS_Face &, const Standard_Real)) &FUN_tool_EtgF, "None", py::arg("paronE"), py::arg("E"), py::arg("p2d"), py::arg("F"), py::arg("tola"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_EtgOOE", (Standard_Boolean (*)(const Standard_Real &, const TopoDS_Edge &, const Standard_Real &, const TopoDS_Edge &, const Standard_Real)) &FUN_tool_EtgOOE, "None", py::arg("paronE"), py::arg("E"), py::arg("paronOOE"), py::arg("OOE"), py::arg("tola"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_getgeomxx", (gp_Vec (*)(const TopoDS_Face &, const TopoDS_Edge &, const Standard_Real)) &FUN_tool_getgeomxx, "None", py::arg("Fi"), py::arg("Ei"), py::arg("parOnEi"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_nearestISO", (Standard_Boolean (*)(const TopoDS_Face &, const Standard_Real, const Standard_Boolean, Standard_Real &, Standard_Real &)) &FUN_nearestISO, "None", py::arg("F"), py::arg("xpar"), py::arg("isoU"), py::arg("xinf"), py::arg("xsup"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_getxx", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Edge &, const Standard_Real, gp_Dir &)) &FUN_tool_getxx, "None", py::arg("Fi"), py::arg("Ei"), py::arg("parOnEi"), py::arg("XX"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_getdxx", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Edge &, const Standard_Real, gp_Vec2d &)) &FUN_tool_getdxx, "None", py::arg("F"), py::arg("E"), py::arg("parE"), py::arg("XX"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_EitangenttoFe", (Standard_Boolean (*)(const gp_Dir &, const TopoDS_Edge &, const Standard_Real)) &FUN_tool_EitangenttoFe, "None", py::arg("ngFe"), py::arg("Ei"), py::arg("parOnEi"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_typ", (GeomAbs_CurveType (*)(const TopoDS_Edge &)) &FUN_tool_typ, "None", py::arg("E"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_plane", (Standard_Boolean (*)(const TopoDS_Shape &)) &FUN_tool_plane, "None", py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_cylinder", (Standard_Boolean (*)(const TopoDS_Shape &)) &FUN_tool_cylinder, "None", py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_closedS", (Standard_Boolean (*)(const TopoDS_Shape &, Standard_Boolean &, Standard_Real &, Standard_Real &)) &FUN_tool_closedS, "None", py::arg("F"), py::arg("inU"), py::arg("xmin"), py::arg("xper"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_mkBnd2d", (void (*)(const TopoDS_Shape &, const TopoDS_Shape &, Bnd_Box2d &)) &FUN_tool_mkBnd2d, "None", py::arg("W"), py::arg("FF"), py::arg("B2d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_IsClosingE", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Shape &, const TopoDS_Face &)) &FUN_tool_IsClosingE, "None", py::arg("E"), py::arg("S"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_ClosingE", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Wire &, const TopoDS_Face &)) &FUN_tool_ClosingE, "None", py::arg("E"), py::arg("W"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_inS", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &FUN_tool_inS, "None", py::arg("subshape"), py::arg("shape"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_Eshared", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, TopoDS_Shape &)) &FUN_tool_Eshared, "None", py::arg("v"), py::arg("F1"), py::arg("F2"), py::arg("Eshared"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_parVonE", (Standard_Boolean (*)(const TopoDS_Vertex &, const TopoDS_Edge &, Standard_Real &)) &FUN_tool_parVonE, "None", py::arg("v"), py::arg("E"), py::arg("par"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_parE", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real &, const TopoDS_Edge &, Standard_Real &)) &FUN_tool_parE, "None", py::arg("E0"), py::arg("par0"), py::arg("E"), py::arg("par"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_paronEF", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real &, const TopoDS_Face &, gp_Pnt2d &)) &FUN_tool_paronEF, "None", py::arg("E"), py::arg("par"), py::arg("F"), py::arg("UV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_parF", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real &, const TopoDS_Face &, gp_Pnt2d &)) &FUN_tool_parF, "None", py::arg("E"), py::arg("par"), py::arg("F"), py::arg("UV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_tggeomE", (gp_Vec (*)(const Standard_Real, const TopoDS_Edge &)) &FUN_tool_tggeomE, "None", py::arg("paronE"), py::arg("E"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_findPinBAC", (Standard_Boolean (*)(const BRepAdaptor_Curve &, gp_Pnt &, Standard_Real &)) &FUN_tool_findPinBAC, "None", py::arg("BAC"), py::arg("P"), py::arg("par"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_findparinBAC", (Standard_Boolean (*)(const BRepAdaptor_Curve &, Standard_Real &)) &FUN_tool_findparinBAC, "None", py::arg("BAC"), py::arg("par"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_findparinE", (Standard_Boolean (*)(const TopoDS_Shape &, Standard_Real &)) &FUN_tool_findparinE, "None", py::arg("E"), py::arg("par"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_findPinE", (Standard_Boolean (*)(const TopoDS_Shape &, gp_Pnt &, Standard_Real &)) &FUN_tool_findPinE, "None", py::arg("E"), py::arg("P"), py::arg("par"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_maxtol", (Standard_Real (*)(const TopoDS_Shape &)) &FUN_tool_maxtol, "None", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_nbshapes", (Standard_Integer (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum &)) &FUN_tool_nbshapes, "None", py::arg("S"), py::arg("typ"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_shapes", (void (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum &, TopTools_ListOfShape &)) &FUN_tool_shapes, "None", py::arg("S"), py::arg("typ"), py::arg("ltyp"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_comparebndkole", (Standard_Integer (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &FUN_tool_comparebndkole, "None", py::arg("sh1"), py::arg("sh2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_SameOri", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Edge &)) &FUN_tool_SameOri, "None", py::arg("E1"), py::arg("E2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_haspc", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &FUN_tool_haspc, "None", py::arg("E"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_pcurveonF", (Standard_Boolean (*)(const TopoDS_Face &, TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, TopoDS_Face &)) &FUN_tool_pcurveonF, "None", py::arg("fF"), py::arg("faultyE"), py::arg("C2d"), py::arg("newf"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_curvesSO", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Edge &, Standard_Boolean &)) &FUN_tool_curvesSO, "None", py::arg("E1"), py::arg("E2"), py::arg("so"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_findAncestor", (Standard_Boolean (*)(const TopTools_ListOfShape &, const TopoDS_Edge &, TopoDS_Face &)) &FUN_tool_findAncestor, "None", py::arg("lF"), py::arg("E"), py::arg("Fanc"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_ds_CopyEdge", (void (*)(const TopoDS_Shape &, TopoDS_Shape &)) &FUN_ds_CopyEdge, "None", py::arg("Ein"), py::arg("Eou"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_ds_Parameter", (void (*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real)) &FUN_ds_Parameter, "None", py::arg("E"), py::arg("V"), py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOPOLOGY.hxx
	mod.def("FUN_tool_MakeWire", (Standard_Boolean (*)(const TopTools_ListOfShape &, TopoDS_Wire &)) &FUN_tool_MakeWire, "None", py::arg("loE"), py::arg("newW"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_SC.hxx
	mod.def("FSC_GetPSC", (TopOpeBRepTool_ShapeClassifier & (*)(const TopoDS_Shape &)) &FSC_GetPSC, "None", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_SC.hxx
	mod.def("FSC_StatePonFace", (TopAbs_State (*)(const gp_Pnt &, const TopoDS_Shape &, TopOpeBRepTool_ShapeClassifier &)) &FSC_StatePonFace, "None", py::arg("P"), py::arg("F"), py::arg("PSC"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_SC.hxx
	mod.def("FSC_StateEonFace", (TopAbs_State (*)(const TopoDS_Shape &, const Standard_Real, const TopoDS_Shape &, TopOpeBRepTool_ShapeClassifier &)) &FSC_StateEonFace, "None", py::arg("E"), py::arg("t"), py::arg("F"), py::arg("PSC"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_tol.hxx
	mod.def("FTOL_FaceTolerances", (void (*)(const Bnd_Box &, const Bnd_Box &, const TopoDS_Face &, const TopoDS_Face &, const BRepAdaptor_Surface &, const BRepAdaptor_Surface &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &FTOL_FaceTolerances, "None", py::arg("B1"), py::arg("B2"), py::arg("myFace1"), py::arg("myFace2"), py::arg("mySurface1"), py::arg("mySurface2"), py::arg("myTol1"), py::arg("myTol2"), py::arg("Deflection"), py::arg("MaxUV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_tol.hxx
	mod.def("FTOL_FaceTolerances3d", (void (*)(const Bnd_Box &, const Bnd_Box &, const TopoDS_Face &, const TopoDS_Face &, const BRepAdaptor_Surface &, const BRepAdaptor_Surface &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &FTOL_FaceTolerances3d, "None", py::arg("B1"), py::arg("B2"), py::arg("myFace1"), py::arg("myFace2"), py::arg("mySurface1"), py::arg("mySurface2"), py::arg("myTol1"), py::arg("myTol2"), py::arg("Deflection"), py::arg("MaxUV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_tol.hxx
	mod.def("FTOL_FaceTolerances2d", (void (*)(const Bnd_Box &, const Bnd_Box &, const TopoDS_Face &, const TopoDS_Face &, const BRepAdaptor_Surface &, const BRepAdaptor_Surface &, Standard_Real &, Standard_Real &)) &FTOL_FaceTolerances2d, "None", py::arg("B1"), py::arg("B2"), py::arg("myFace1"), py::arg("myFace2"), py::arg("mySurface1"), py::arg("mySurface2"), py::arg("myTol1"), py::arg("myTol2"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_ShapeExplorer.hxx
	py::class_<TopOpeBRepTool_ShapeExplorer, std::unique_ptr<TopOpeBRepTool_ShapeExplorer, Deleter<TopOpeBRepTool_ShapeExplorer>>, TopExp_Explorer> cls_TopOpeBRepTool_ShapeExplorer(mod, "TopOpeBRepTool_ShapeExplorer", "Extends TopExp_Explorer by counting index of current item (for tracing and debug)");
	cls_TopOpeBRepTool_ShapeExplorer.def(py::init<>());
	cls_TopOpeBRepTool_ShapeExplorer.def(py::init<const TopoDS_Shape &, const TopAbs_ShapeEnum>(), py::arg("S"), py::arg("ToFind"));
	cls_TopOpeBRepTool_ShapeExplorer.def(py::init<const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum>(), py::arg("S"), py::arg("ToFind"), py::arg("ToAvoid"));
	cls_TopOpeBRepTool_ShapeExplorer.def("Init", [](TopOpeBRepTool_ShapeExplorer &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.Init(a0, a1); }, py::arg("S"), py::arg("ToFind"));
	cls_TopOpeBRepTool_ShapeExplorer.def("Init", (void (TopOpeBRepTool_ShapeExplorer::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_ShapeExplorer::Init, "None", py::arg("S"), py::arg("ToFind"), py::arg("ToAvoid"));
	cls_TopOpeBRepTool_ShapeExplorer.def("Next", (void (TopOpeBRepTool_ShapeExplorer::*)()) &TopOpeBRepTool_ShapeExplorer::Next, "Moves to the next Shape in the exploration.");
	cls_TopOpeBRepTool_ShapeExplorer.def("Index", (Standard_Integer (TopOpeBRepTool_ShapeExplorer::*)() const ) &TopOpeBRepTool_ShapeExplorer::Index, "Index of current sub-shape");
	cls_TopOpeBRepTool_ShapeExplorer.def("DumpCurrent", (Standard_OStream & (TopOpeBRepTool_ShapeExplorer::*)(Standard_OStream &) const ) &TopOpeBRepTool_ShapeExplorer::DumpCurrent, "Dump info on current shape to stream", py::arg("OS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_HBoxTool.hxx
	py::class_<TopOpeBRepTool_HBoxTool, opencascade::handle<TopOpeBRepTool_HBoxTool>, Standard_Transient> cls_TopOpeBRepTool_HBoxTool(mod, "TopOpeBRepTool_HBoxTool", "None");
	cls_TopOpeBRepTool_HBoxTool.def(py::init<>());
	cls_TopOpeBRepTool_HBoxTool.def("Clear", (void (TopOpeBRepTool_HBoxTool::*)()) &TopOpeBRepTool_HBoxTool::Clear, "None");
	cls_TopOpeBRepTool_HBoxTool.def("AddBoxes", [](TopOpeBRepTool_HBoxTool &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.AddBoxes(a0, a1); }, py::arg("S"), py::arg("TS"));
	cls_TopOpeBRepTool_HBoxTool.def("AddBoxes", (void (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_HBoxTool::AddBoxes, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
	cls_TopOpeBRepTool_HBoxTool.def("AddBox", (void (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &)) &TopOpeBRepTool_HBoxTool::AddBox, "None", py::arg("S"));
	cls_TopOpeBRepTool_HBoxTool.def_static("ComputeBox_", (void (*)(const TopoDS_Shape &, Bnd_Box &)) &TopOpeBRepTool_HBoxTool::ComputeBox, "None", py::arg("S"), py::arg("B"));
	cls_TopOpeBRepTool_HBoxTool.def_static("ComputeBoxOnVertices_", (void (*)(const TopoDS_Shape &, Bnd_Box &)) &TopOpeBRepTool_HBoxTool::ComputeBoxOnVertices, "None", py::arg("S"), py::arg("B"));
	cls_TopOpeBRepTool_HBoxTool.def_static("DumpB_", (void (*)(const Bnd_Box &)) &TopOpeBRepTool_HBoxTool::DumpB, "None", py::arg("B"));
	cls_TopOpeBRepTool_HBoxTool.def("Box", (const Bnd_Box & (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &)) &TopOpeBRepTool_HBoxTool::Box, "None", py::arg("S"));
	cls_TopOpeBRepTool_HBoxTool.def("Box", (const Bnd_Box & (TopOpeBRepTool_HBoxTool::*)(const Standard_Integer) const ) &TopOpeBRepTool_HBoxTool::Box, "None", py::arg("I"));
	cls_TopOpeBRepTool_HBoxTool.def("HasBox", (Standard_Boolean (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_HBoxTool::HasBox, "None", py::arg("S"));
	cls_TopOpeBRepTool_HBoxTool.def("Shape", (const TopoDS_Shape & (TopOpeBRepTool_HBoxTool::*)(const Standard_Integer) const ) &TopOpeBRepTool_HBoxTool::Shape, "None", py::arg("I"));
	cls_TopOpeBRepTool_HBoxTool.def("Index", (Standard_Integer (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_HBoxTool::Index, "None", py::arg("S"));
	cls_TopOpeBRepTool_HBoxTool.def("Extent", (Standard_Integer (TopOpeBRepTool_HBoxTool::*)() const ) &TopOpeBRepTool_HBoxTool::Extent, "None");
	cls_TopOpeBRepTool_HBoxTool.def("ChangeIMS", (TopOpeBRepTool_IndexedDataMapOfShapeBox & (TopOpeBRepTool_HBoxTool::*)()) &TopOpeBRepTool_HBoxTool::ChangeIMS, "None");
	cls_TopOpeBRepTool_HBoxTool.def("IMS", (const TopOpeBRepTool_IndexedDataMapOfShapeBox & (TopOpeBRepTool_HBoxTool::*)() const ) &TopOpeBRepTool_HBoxTool::IMS, "None");
	cls_TopOpeBRepTool_HBoxTool.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepTool_HBoxTool::get_type_name, "None");
	cls_TopOpeBRepTool_HBoxTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepTool_HBoxTool::get_type_descriptor, "None");
	cls_TopOpeBRepTool_HBoxTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepTool_HBoxTool::*)() const ) &TopOpeBRepTool_HBoxTool::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_BoxSort.hxx
	py::class_<TopOpeBRepTool_BoxSort, std::unique_ptr<TopOpeBRepTool_BoxSort, Deleter<TopOpeBRepTool_BoxSort>>> cls_TopOpeBRepTool_BoxSort(mod, "TopOpeBRepTool_BoxSort", "None");
	cls_TopOpeBRepTool_BoxSort.def(py::init<>());
	cls_TopOpeBRepTool_BoxSort.def(py::init<const opencascade::handle<TopOpeBRepTool_HBoxTool> &>(), py::arg("T"));
	cls_TopOpeBRepTool_BoxSort.def("SetHBoxTool", (void (TopOpeBRepTool_BoxSort::*)(const opencascade::handle<TopOpeBRepTool_HBoxTool> &)) &TopOpeBRepTool_BoxSort::SetHBoxTool, "None", py::arg("T"));
	cls_TopOpeBRepTool_BoxSort.def("HBoxTool", (const opencascade::handle<TopOpeBRepTool_HBoxTool> & (TopOpeBRepTool_BoxSort::*)() const ) &TopOpeBRepTool_BoxSort::HBoxTool, "None");
	cls_TopOpeBRepTool_BoxSort.def("Clear", (void (TopOpeBRepTool_BoxSort::*)()) &TopOpeBRepTool_BoxSort::Clear, "None");
	cls_TopOpeBRepTool_BoxSort.def("AddBoxes", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.AddBoxes(a0, a1); }, py::arg("S"), py::arg("TS"));
	cls_TopOpeBRepTool_BoxSort.def("AddBoxes", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::AddBoxes, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
	cls_TopOpeBRepTool_BoxSort.def("MakeHAB", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.MakeHAB(a0, a1); }, py::arg("S"), py::arg("TS"));
	cls_TopOpeBRepTool_BoxSort.def("MakeHAB", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::MakeHAB, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
	cls_TopOpeBRepTool_BoxSort.def("HAB", (const opencascade::handle<Bnd_HArray1OfBox> & (TopOpeBRepTool_BoxSort::*)() const ) &TopOpeBRepTool_BoxSort::HAB, "None");
	cls_TopOpeBRepTool_BoxSort.def_static("MakeHABCOB_", (void (*)(const opencascade::handle<Bnd_HArray1OfBox> &, Bnd_Box &)) &TopOpeBRepTool_BoxSort::MakeHABCOB, "None", py::arg("HAB"), py::arg("COB"));
	cls_TopOpeBRepTool_BoxSort.def("HABShape", (const TopoDS_Shape & (TopOpeBRepTool_BoxSort::*)(const Standard_Integer) const ) &TopOpeBRepTool_BoxSort::HABShape, "None", py::arg("I"));
	cls_TopOpeBRepTool_BoxSort.def("MakeCOB", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.MakeCOB(a0, a1); }, py::arg("S"), py::arg("TS"));
	cls_TopOpeBRepTool_BoxSort.def("MakeCOB", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::MakeCOB, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
	cls_TopOpeBRepTool_BoxSort.def("AddBoxesMakeCOB", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.AddBoxesMakeCOB(a0, a1); }, py::arg("S"), py::arg("TS"));
	cls_TopOpeBRepTool_BoxSort.def("AddBoxesMakeCOB", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::AddBoxesMakeCOB, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
	cls_TopOpeBRepTool_BoxSort.def("Compare", (const TColStd_ListIteratorOfListOfInteger & (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &)) &TopOpeBRepTool_BoxSort::Compare, "None", py::arg("S"));
	cls_TopOpeBRepTool_BoxSort.def("TouchedShape", (const TopoDS_Shape & (TopOpeBRepTool_BoxSort::*)(const TColStd_ListIteratorOfListOfInteger &) const ) &TopOpeBRepTool_BoxSort::TouchedShape, "None", py::arg("I"));
	cls_TopOpeBRepTool_BoxSort.def("Box", (const Bnd_Box & (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_BoxSort::Box, "None", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_ShapeClassifier.hxx
	py::class_<TopOpeBRepTool_ShapeClassifier, std::unique_ptr<TopOpeBRepTool_ShapeClassifier, Deleter<TopOpeBRepTool_ShapeClassifier>>> cls_TopOpeBRepTool_ShapeClassifier(mod, "TopOpeBRepTool_ShapeClassifier", "None");
	cls_TopOpeBRepTool_ShapeClassifier.def(py::init<>());
	cls_TopOpeBRepTool_ShapeClassifier.def(py::init<const TopoDS_Shape &>(), py::arg("SRef"));
	cls_TopOpeBRepTool_ShapeClassifier.def("ClearAll", (void (TopOpeBRepTool_ShapeClassifier::*)()) &TopOpeBRepTool_ShapeClassifier::ClearAll, "reset all internal data (SolidClassifier included)");
	cls_TopOpeBRepTool_ShapeClassifier.def("ClearCurrent", (void (TopOpeBRepTool_ShapeClassifier::*)()) &TopOpeBRepTool_ShapeClassifier::ClearCurrent, "reset all internal data (except SolidClassified)");
	cls_TopOpeBRepTool_ShapeClassifier.def("SetReference", (void (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::SetReference, "Set SRef as reference shape the next StateShapeReference(S,AvoidS) calls will classify S with SRef.", py::arg("SRef"));
	cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", [](TopOpeBRepTool_ShapeClassifier &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> TopAbs_State { return self.StateShapeShape(a0, a1); }, py::arg("S"), py::arg("SRef"));
	cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepTool_ShapeClassifier::StateShapeShape, "classify shape S compared with shape SRef. samedomain = 0 : S1,S2 are not same domain samedomain = 1 : S1,S2 are same domain", py::arg("S"), py::arg("SRef"), py::arg("samedomain"));
	cls_TopOpeBRepTool_ShapeClassifier.def("SameDomain", (Standard_Integer (TopOpeBRepTool_ShapeClassifier::*)() const ) &TopOpeBRepTool_ShapeClassifier::SameDomain, "None");
	cls_TopOpeBRepTool_ShapeClassifier.def("SameDomain", (void (TopOpeBRepTool_ShapeClassifier::*)(const Standard_Integer)) &TopOpeBRepTool_ShapeClassifier::SameDomain, "set mode for next StateShapeShape call samedomain = true --> S,Sref are same domain --> point on restriction (ON S) is used to classify S. samedomain = false --> S,Sref are not domain --> point not on restriction of S (IN S) is used to classify S. samedomain value is used only in next StateShapeShape call", py::arg("samedomain"));
	cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeShape, "classify shape S compared with shape SRef. AvoidS is not used in classification; AvoidS may be IsNull(). (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("AvoidS"), py::arg("SRef"));
	cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeShape, "classify shape S compared with shape SRef. LAvoidS is list of S subshapes to avoid in classification AvoidS is not used in classification; AvoidS may be IsNull(). (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("LAvoidS"), py::arg("SRef"));
	cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeReference", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeReference, "classify shape S compared with reference shape. AvoidS is not used in classification; AvoidS may be IsNull(). (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("AvoidS"));
	cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeReference", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeReference, "classify shape S compared with reference shape. LAvoidS is list of S subshapes to avoid in classification (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("LAvoidS"));
	cls_TopOpeBRepTool_ShapeClassifier.def("ChangeSolidClassifier", (TopOpeBRepTool_SolidClassifier & (TopOpeBRepTool_ShapeClassifier::*)()) &TopOpeBRepTool_ShapeClassifier::ChangeSolidClassifier, "None");
	cls_TopOpeBRepTool_ShapeClassifier.def("StateP2DReference", (void (TopOpeBRepTool_ShapeClassifier::*)(const gp_Pnt2d &)) &TopOpeBRepTool_ShapeClassifier::StateP2DReference, "classify point P2D with myRef", py::arg("P2D"));
	cls_TopOpeBRepTool_ShapeClassifier.def("StateP3DReference", (void (TopOpeBRepTool_ShapeClassifier::*)(const gp_Pnt &)) &TopOpeBRepTool_ShapeClassifier::StateP3DReference, "classify point P3D with myRef", py::arg("P3D"));
	cls_TopOpeBRepTool_ShapeClassifier.def("State", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)() const ) &TopOpeBRepTool_ShapeClassifier::State, "return field myState");
	cls_TopOpeBRepTool_ShapeClassifier.def("P2D", (const gp_Pnt2d & (TopOpeBRepTool_ShapeClassifier::*)() const ) &TopOpeBRepTool_ShapeClassifier::P2D, "None");
	cls_TopOpeBRepTool_ShapeClassifier.def("P3D", (const gp_Pnt & (TopOpeBRepTool_ShapeClassifier::*)() const ) &TopOpeBRepTool_ShapeClassifier::P3D, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_GeomTool.hxx
	py::class_<TopOpeBRepTool_GeomTool, std::unique_ptr<TopOpeBRepTool_GeomTool, Deleter<TopOpeBRepTool_GeomTool>>> cls_TopOpeBRepTool_GeomTool(mod, "TopOpeBRepTool_GeomTool", "None");
	cls_TopOpeBRepTool_GeomTool.def(py::init<>());
	cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType>(), py::arg("TypeC3D"));
	cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType, const Standard_Boolean>(), py::arg("TypeC3D"), py::arg("CompC3D"));
	cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType, const Standard_Boolean, const Standard_Boolean>(), py::arg("TypeC3D"), py::arg("CompC3D"), py::arg("CompPC1"));
	cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("TypeC3D"), py::arg("CompC3D"), py::arg("CompPC1"), py::arg("CompPC2"));
	cls_TopOpeBRepTool_GeomTool.def("Define", (void (TopOpeBRepTool_GeomTool::*)(const TopOpeBRepTool_OutCurveType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &TopOpeBRepTool_GeomTool::Define, "None", py::arg("TypeC3D"), py::arg("CompC3D"), py::arg("CompPC1"), py::arg("CompPC2"));
	cls_TopOpeBRepTool_GeomTool.def("Define", (void (TopOpeBRepTool_GeomTool::*)(const TopOpeBRepTool_OutCurveType)) &TopOpeBRepTool_GeomTool::Define, "None", py::arg("TypeC3D"));
	cls_TopOpeBRepTool_GeomTool.def("DefineCurves", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Boolean)) &TopOpeBRepTool_GeomTool::DefineCurves, "None", py::arg("CompC3D"));
	cls_TopOpeBRepTool_GeomTool.def("DefinePCurves1", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Boolean)) &TopOpeBRepTool_GeomTool::DefinePCurves1, "None", py::arg("CompPC1"));
	cls_TopOpeBRepTool_GeomTool.def("DefinePCurves2", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Boolean)) &TopOpeBRepTool_GeomTool::DefinePCurves2, "None", py::arg("CompPC2"));
	cls_TopOpeBRepTool_GeomTool.def("Define", (void (TopOpeBRepTool_GeomTool::*)(const TopOpeBRepTool_GeomTool &)) &TopOpeBRepTool_GeomTool::Define, "None", py::arg("GT"));
	cls_TopOpeBRepTool_GeomTool.def("GetTolerances", (void (TopOpeBRepTool_GeomTool::*)(Standard_Real &, Standard_Real &) const ) &TopOpeBRepTool_GeomTool::GetTolerances, "None", py::arg("tol3d"), py::arg("tol2d"));
	cls_TopOpeBRepTool_GeomTool.def("SetTolerances", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Real, const Standard_Real)) &TopOpeBRepTool_GeomTool::SetTolerances, "None", py::arg("tol3d"), py::arg("tol2d"));
	cls_TopOpeBRepTool_GeomTool.def("NbPntMax", (Standard_Integer (TopOpeBRepTool_GeomTool::*)() const ) &TopOpeBRepTool_GeomTool::NbPntMax, "None");
	cls_TopOpeBRepTool_GeomTool.def("SetNbPntMax", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Integer)) &TopOpeBRepTool_GeomTool::SetNbPntMax, "None", py::arg("NbPntMax"));
	cls_TopOpeBRepTool_GeomTool.def("TypeC3D", (TopOpeBRepTool_OutCurveType (TopOpeBRepTool_GeomTool::*)() const ) &TopOpeBRepTool_GeomTool::TypeC3D, "None");
	cls_TopOpeBRepTool_GeomTool.def("CompC3D", (Standard_Boolean (TopOpeBRepTool_GeomTool::*)() const ) &TopOpeBRepTool_GeomTool::CompC3D, "None");
	cls_TopOpeBRepTool_GeomTool.def("CompPC1", (Standard_Boolean (TopOpeBRepTool_GeomTool::*)() const ) &TopOpeBRepTool_GeomTool::CompPC1, "None");
	cls_TopOpeBRepTool_GeomTool.def("CompPC2", (Standard_Boolean (TopOpeBRepTool_GeomTool::*)() const ) &TopOpeBRepTool_GeomTool::CompPC2, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_CurveTool.hxx
	py::class_<TopOpeBRepTool_CurveTool, std::unique_ptr<TopOpeBRepTool_CurveTool, Deleter<TopOpeBRepTool_CurveTool>>> cls_TopOpeBRepTool_CurveTool(mod, "TopOpeBRepTool_CurveTool", "None");
	cls_TopOpeBRepTool_CurveTool.def(py::init<>());
	cls_TopOpeBRepTool_CurveTool.def(py::init<const TopOpeBRepTool_OutCurveType>(), py::arg("OCT"));
	cls_TopOpeBRepTool_CurveTool.def(py::init<const TopOpeBRepTool_GeomTool &>(), py::arg("GT"));
	cls_TopOpeBRepTool_CurveTool.def("ChangeGeomTool", (TopOpeBRepTool_GeomTool & (TopOpeBRepTool_CurveTool::*)()) &TopOpeBRepTool_CurveTool::ChangeGeomTool, "None");
	cls_TopOpeBRepTool_CurveTool.def("GetGeomTool", (const TopOpeBRepTool_GeomTool & (TopOpeBRepTool_CurveTool::*)() const ) &TopOpeBRepTool_CurveTool::GetGeomTool, "None");
	cls_TopOpeBRepTool_CurveTool.def("SetGeomTool", (void (TopOpeBRepTool_CurveTool::*)(const TopOpeBRepTool_GeomTool &)) &TopOpeBRepTool_CurveTool::SetGeomTool, "None", py::arg("GT"));
	cls_TopOpeBRepTool_CurveTool.def("MakeCurves", (Standard_Boolean (TopOpeBRepTool_CurveTool::*)(const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const TopoDS_Shape &, const TopoDS_Shape &, opencascade::handle<Geom_Curve> &, opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &, Standard_Real &, Standard_Real &) const ) &TopOpeBRepTool_CurveTool::MakeCurves, "Approximates curves. Returns False in the case of failure", py::arg("min"), py::arg("max"), py::arg("C3D"), py::arg("PC1"), py::arg("PC2"), py::arg("S1"), py::arg("S2"), py::arg("C3DN"), py::arg("PC1N"), py::arg("PC2N"), py::arg("Tol3d"), py::arg("Tol2d"));
	cls_TopOpeBRepTool_CurveTool.def_static("MakeBSpline1fromPnt_", (opencascade::handle<Geom_Curve> (*)(const TColgp_Array1OfPnt &)) &TopOpeBRepTool_CurveTool::MakeBSpline1fromPnt, "None", py::arg("P"));
	cls_TopOpeBRepTool_CurveTool.def_static("MakeBSpline1fromPnt2d_", (opencascade::handle<Geom2d_Curve> (*)(const TColgp_Array1OfPnt2d &)) &TopOpeBRepTool_CurveTool::MakeBSpline1fromPnt2d, "None", py::arg("P"));
	cls_TopOpeBRepTool_CurveTool.def_static("IsProjectable_", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<Geom_Curve> &)) &TopOpeBRepTool_CurveTool::IsProjectable, "None", py::arg("S"), py::arg("C"));
	cls_TopOpeBRepTool_CurveTool.def_static("MakePCurveOnFace_", [](const TopoDS_Shape & a0, const opencascade::handle<Geom_Curve> & a1, Standard_Real & a2) -> opencascade::handle<Geom2d_Curve> { return TopOpeBRepTool_CurveTool::MakePCurveOnFace(a0, a1, a2); }, py::arg("S"), py::arg("C"), py::arg("TolReached2d"));
	cls_TopOpeBRepTool_CurveTool.def_static("MakePCurveOnFace_", [](const TopoDS_Shape & a0, const opencascade::handle<Geom_Curve> & a1, Standard_Real & a2, const Standard_Real a3) -> opencascade::handle<Geom2d_Curve> { return TopOpeBRepTool_CurveTool::MakePCurveOnFace(a0, a1, a2, a3); }, py::arg("S"), py::arg("C"), py::arg("TolReached2d"), py::arg("first"));
	cls_TopOpeBRepTool_CurveTool.def_static("MakePCurveOnFace_", (opencascade::handle<Geom2d_Curve> (*)(const TopoDS_Shape &, const opencascade::handle<Geom_Curve> &, Standard_Real &, const Standard_Real, const Standard_Real)) &TopOpeBRepTool_CurveTool::MakePCurveOnFace, "None", py::arg("S"), py::arg("C"), py::arg("TolReached2d"), py::arg("first"), py::arg("last"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_SolidClassifier.hxx
	py::class_<TopOpeBRepTool_SolidClassifier, std::unique_ptr<TopOpeBRepTool_SolidClassifier, Deleter<TopOpeBRepTool_SolidClassifier>>> cls_TopOpeBRepTool_SolidClassifier(mod, "TopOpeBRepTool_SolidClassifier", "None");
	cls_TopOpeBRepTool_SolidClassifier.def(py::init<>());
	cls_TopOpeBRepTool_SolidClassifier.def("Clear", (void (TopOpeBRepTool_SolidClassifier::*)()) &TopOpeBRepTool_SolidClassifier::Clear, "None");
	cls_TopOpeBRepTool_SolidClassifier.def("LoadSolid", (void (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Solid &)) &TopOpeBRepTool_SolidClassifier::LoadSolid, "None", py::arg("S"));
	cls_TopOpeBRepTool_SolidClassifier.def("Classify", (TopAbs_State (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Solid &, const gp_Pnt &, const Standard_Real)) &TopOpeBRepTool_SolidClassifier::Classify, "compute the position of point <P> regarding with the geometric domain of the solid <S>.", py::arg("S"), py::arg("P"), py::arg("Tol"));
	cls_TopOpeBRepTool_SolidClassifier.def("LoadShell", (void (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Shell &)) &TopOpeBRepTool_SolidClassifier::LoadShell, "None", py::arg("S"));
	cls_TopOpeBRepTool_SolidClassifier.def("Classify", (TopAbs_State (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Shell &, const gp_Pnt &, const Standard_Real)) &TopOpeBRepTool_SolidClassifier::Classify, "compute the position of point <P> regarding with the geometric domain of the shell <S>.", py::arg("S"), py::arg("P"), py::arg("Tol"));
	cls_TopOpeBRepTool_SolidClassifier.def("State", (TopAbs_State (TopOpeBRepTool_SolidClassifier::*)() const ) &TopOpeBRepTool_SolidClassifier::State, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_AncestorsTool.hxx
	py::class_<TopOpeBRepTool_AncestorsTool, std::unique_ptr<TopOpeBRepTool_AncestorsTool, Deleter<TopOpeBRepTool_AncestorsTool>>> cls_TopOpeBRepTool_AncestorsTool(mod, "TopOpeBRepTool_AncestorsTool", "Describes the ancestors tool needed by the class DSFiller from TopOpeInter.");
	cls_TopOpeBRepTool_AncestorsTool.def(py::init<>());
	cls_TopOpeBRepTool_AncestorsTool.def_static("MakeAncestors_", (void (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, TopTools_IndexedDataMapOfShapeListOfShape &)) &TopOpeBRepTool_AncestorsTool::MakeAncestors, "same as package method TopExp::MapShapeListOfShapes()", py::arg("S"), py::arg("TS"), py::arg("TA"), py::arg("M"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_C2DF.hxx
	py::class_<TopOpeBRepTool_C2DF, std::unique_ptr<TopOpeBRepTool_C2DF, Deleter<TopOpeBRepTool_C2DF>>> cls_TopOpeBRepTool_C2DF(mod, "TopOpeBRepTool_C2DF", "None");
	cls_TopOpeBRepTool_C2DF.def(py::init<>());
	cls_TopOpeBRepTool_C2DF.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const TopoDS_Face &>(), py::arg("PC"), py::arg("f2d"), py::arg("l2d"), py::arg("tol"), py::arg("F"));
	cls_TopOpeBRepTool_C2DF.def("SetPC", (void (TopOpeBRepTool_C2DF::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real)) &TopOpeBRepTool_C2DF::SetPC, "None", py::arg("PC"), py::arg("f2d"), py::arg("l2d"), py::arg("tol"));
	cls_TopOpeBRepTool_C2DF.def("SetFace", (void (TopOpeBRepTool_C2DF::*)(const TopoDS_Face &)) &TopOpeBRepTool_C2DF::SetFace, "None", py::arg("F"));
	cls_TopOpeBRepTool_C2DF.def("PC", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepTool_C2DF::*)(Standard_Real &, Standard_Real &, Standard_Real &) const ) &TopOpeBRepTool_C2DF::PC, "None", py::arg("f2d"), py::arg("l2d"), py::arg("tol"));
	cls_TopOpeBRepTool_C2DF.def("Face", (const TopoDS_Face & (TopOpeBRepTool_C2DF::*)() const ) &TopOpeBRepTool_C2DF::Face, "None");
	cls_TopOpeBRepTool_C2DF.def("IsPC", (Standard_Boolean (TopOpeBRepTool_C2DF::*)(const opencascade::handle<Geom2d_Curve> &) const ) &TopOpeBRepTool_C2DF::IsPC, "None", py::arg("PC"));
	cls_TopOpeBRepTool_C2DF.def("IsFace", (Standard_Boolean (TopOpeBRepTool_C2DF::*)(const TopoDS_Face &) const ) &TopOpeBRepTool_C2DF::IsFace, "None", py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_ShapeTool.hxx
	py::class_<TopOpeBRepTool_ShapeTool, std::unique_ptr<TopOpeBRepTool_ShapeTool, Deleter<TopOpeBRepTool_ShapeTool>>> cls_TopOpeBRepTool_ShapeTool(mod, "TopOpeBRepTool_ShapeTool", "None");
	cls_TopOpeBRepTool_ShapeTool.def(py::init<>());
	cls_TopOpeBRepTool_ShapeTool.def_static("Tolerance_", (Standard_Real (*)(const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::Tolerance, "Returns the tolerance of the shape <S>. If the shape <S> is Null, returns 0.", py::arg("S"));
	cls_TopOpeBRepTool_ShapeTool.def_static("Pnt_", (gp_Pnt (*)(const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::Pnt, "Returns 3D point of vertex <S>.", py::arg("S"));
	cls_TopOpeBRepTool_ShapeTool.def_static("BASISCURVE_", (opencascade::handle<Geom_Curve> (*)(const opencascade::handle<Geom_Curve> &)) &TopOpeBRepTool_ShapeTool::BASISCURVE, "None", py::arg("C"));
	cls_TopOpeBRepTool_ShapeTool.def_static("BASISCURVE_", (opencascade::handle<Geom_Curve> (*)(const TopoDS_Edge &)) &TopOpeBRepTool_ShapeTool::BASISCURVE, "None", py::arg("E"));
	cls_TopOpeBRepTool_ShapeTool.def_static("BASISSURFACE_", (opencascade::handle<Geom_Surface> (*)(const opencascade::handle<Geom_Surface> &)) &TopOpeBRepTool_ShapeTool::BASISSURFACE, "None", py::arg("S"));
	cls_TopOpeBRepTool_ShapeTool.def_static("BASISSURFACE_", (opencascade::handle<Geom_Surface> (*)(const TopoDS_Face &)) &TopOpeBRepTool_ShapeTool::BASISSURFACE, "None", py::arg("F"));
	cls_TopOpeBRepTool_ShapeTool.def_static("UVBOUNDS_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &TopOpeBRepTool_ShapeTool::UVBOUNDS, "None", py::arg("S"), py::arg("UPeri"), py::arg("VPeri"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
	cls_TopOpeBRepTool_ShapeTool.def_static("UVBOUNDS_", (void (*)(const TopoDS_Face &, Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &TopOpeBRepTool_ShapeTool::UVBOUNDS, "None", py::arg("F"), py::arg("UPeri"), py::arg("VPeri"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
	cls_TopOpeBRepTool_ShapeTool.def_static("AdjustOnPeriodic_", (void (*)(const TopoDS_Shape &, Standard_Real &, Standard_Real &)) &TopOpeBRepTool_ShapeTool::AdjustOnPeriodic, "ajust u,v values in UVBounds of the domain of the geometric shape <S>, according to Uperiodicity and VPeriodicity of the domain. <S> is assumed to be a face. u and/or v is/are not modified when the domain is not periodic in U and/or V .", py::arg("S"), py::arg("u"), py::arg("v"));
	cls_TopOpeBRepTool_ShapeTool.def_static("Closed_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::Closed, "indicates wheter shape S1 is a closing shape on S2 or not.", py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRepTool_ShapeTool.def_static("PeriodizeParameter_", (Standard_Real (*)(const Standard_Real, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::PeriodizeParameter, "None", py::arg("par"), py::arg("EE"), py::arg("FF"));
	cls_TopOpeBRepTool_ShapeTool.def_static("ShapesSameOriented_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::ShapesSameOriented, "None", py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRepTool_ShapeTool.def_static("SurfacesSameOriented_", (Standard_Boolean (*)(const BRepAdaptor_Surface &, const BRepAdaptor_Surface &)) &TopOpeBRepTool_ShapeTool::SurfacesSameOriented, "None", py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRepTool_ShapeTool.def_static("FacesSameOriented_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::FacesSameOriented, "None", py::arg("F1"), py::arg("F2"));
	cls_TopOpeBRepTool_ShapeTool.def_static("CurvesSameOriented_", (Standard_Boolean (*)(const BRepAdaptor_Curve &, const BRepAdaptor_Curve &)) &TopOpeBRepTool_ShapeTool::CurvesSameOriented, "None", py::arg("C1"), py::arg("C2"));
	cls_TopOpeBRepTool_ShapeTool.def_static("EdgesSameOriented_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::EdgesSameOriented, "None", py::arg("E1"), py::arg("E2"));
	cls_TopOpeBRepTool_ShapeTool.def_static("EdgeData_", (Standard_Real (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Dir &, gp_Dir &, Standard_Real &)) &TopOpeBRepTool_ShapeTool::EdgeData, "Compute tangent T, normal N, curvature C at point of parameter P on curve BRAC. Returns the tolerance indicating if T,N are null.", py::arg("BRAC"), py::arg("P"), py::arg("T"), py::arg("N"), py::arg("C"));
	cls_TopOpeBRepTool_ShapeTool.def_static("EdgeData_", (Standard_Real (*)(const TopoDS_Shape &, const Standard_Real, gp_Dir &, gp_Dir &, Standard_Real &)) &TopOpeBRepTool_ShapeTool::EdgeData, "Same as previous on edge E.", py::arg("E"), py::arg("P"), py::arg("T"), py::arg("N"), py::arg("C"));
	cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3dU_", (Standard_Real (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3dU, "None", py::arg("SU"), py::arg("Tol2d"));
	cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3dV_", (Standard_Real (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3dV, "None", py::arg("SU"), py::arg("Tol2d"));
	cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3d_", (Standard_Real (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3d, "None", py::arg("SU"), py::arg("Tol2d"));
	cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3d_", (Standard_Real (*)(const TopoDS_Face &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3d, "None", py::arg("F"), py::arg("Tol2d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_connexity.hxx
	py::class_<TopOpeBRepTool_connexity, std::unique_ptr<TopOpeBRepTool_connexity, Deleter<TopOpeBRepTool_connexity>>> cls_TopOpeBRepTool_connexity(mod, "TopOpeBRepTool_connexity", "None");
	cls_TopOpeBRepTool_connexity.def(py::init<>());
	cls_TopOpeBRepTool_connexity.def(py::init<const TopoDS_Shape &>(), py::arg("Key"));
	cls_TopOpeBRepTool_connexity.def("SetKey", (void (TopOpeBRepTool_connexity::*)(const TopoDS_Shape &)) &TopOpeBRepTool_connexity::SetKey, "None", py::arg("Key"));
	cls_TopOpeBRepTool_connexity.def("Key", (const TopoDS_Shape & (TopOpeBRepTool_connexity::*)() const ) &TopOpeBRepTool_connexity::Key, "None");
	cls_TopOpeBRepTool_connexity.def("Item", (Standard_Integer (TopOpeBRepTool_connexity::*)(const Standard_Integer, TopTools_ListOfShape &) const ) &TopOpeBRepTool_connexity::Item, "None", py::arg("OriKey"), py::arg("Item"));
	cls_TopOpeBRepTool_connexity.def("AllItems", (Standard_Integer (TopOpeBRepTool_connexity::*)(TopTools_ListOfShape &) const ) &TopOpeBRepTool_connexity::AllItems, "None", py::arg("Item"));
	cls_TopOpeBRepTool_connexity.def("AddItem", (void (TopOpeBRepTool_connexity::*)(const Standard_Integer, const TopTools_ListOfShape &)) &TopOpeBRepTool_connexity::AddItem, "None", py::arg("OriKey"), py::arg("Item"));
	cls_TopOpeBRepTool_connexity.def("AddItem", (void (TopOpeBRepTool_connexity::*)(const Standard_Integer, const TopoDS_Shape &)) &TopOpeBRepTool_connexity::AddItem, "None", py::arg("OriKey"), py::arg("Item"));
	cls_TopOpeBRepTool_connexity.def("RemoveItem", (Standard_Boolean (TopOpeBRepTool_connexity::*)(const Standard_Integer, const TopoDS_Shape &)) &TopOpeBRepTool_connexity::RemoveItem, "None", py::arg("OriKey"), py::arg("Item"));
	cls_TopOpeBRepTool_connexity.def("RemoveItem", (Standard_Boolean (TopOpeBRepTool_connexity::*)(const TopoDS_Shape &)) &TopOpeBRepTool_connexity::RemoveItem, "None", py::arg("Item"));
	cls_TopOpeBRepTool_connexity.def("ChangeItem", (TopTools_ListOfShape & (TopOpeBRepTool_connexity::*)(const Standard_Integer)) &TopOpeBRepTool_connexity::ChangeItem, "None", py::arg("OriKey"));
	cls_TopOpeBRepTool_connexity.def("IsMultiple", (Standard_Boolean (TopOpeBRepTool_connexity::*)() const ) &TopOpeBRepTool_connexity::IsMultiple, "None");
	cls_TopOpeBRepTool_connexity.def("IsFaulty", (Standard_Boolean (TopOpeBRepTool_connexity::*)() const ) &TopOpeBRepTool_connexity::IsFaulty, "None");
	cls_TopOpeBRepTool_connexity.def("IsInternal", (Standard_Integer (TopOpeBRepTool_connexity::*)(TopTools_ListOfShape &) const ) &TopOpeBRepTool_connexity::IsInternal, "None", py::arg("Item"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_face.hxx
	py::class_<TopOpeBRepTool_face, std::unique_ptr<TopOpeBRepTool_face, Deleter<TopOpeBRepTool_face>>> cls_TopOpeBRepTool_face(mod, "TopOpeBRepTool_face", "None");
	cls_TopOpeBRepTool_face.def(py::init<>());
	cls_TopOpeBRepTool_face.def("Init", (Standard_Boolean (TopOpeBRepTool_face::*)(const TopoDS_Wire &, const TopoDS_Face &)) &TopOpeBRepTool_face::Init, "None", py::arg("W"), py::arg("Fref"));
	cls_TopOpeBRepTool_face.def("W", (const TopoDS_Wire & (TopOpeBRepTool_face::*)() const ) &TopOpeBRepTool_face::W, "None");
	cls_TopOpeBRepTool_face.def("IsDone", (Standard_Boolean (TopOpeBRepTool_face::*)() const ) &TopOpeBRepTool_face::IsDone, "None");
	cls_TopOpeBRepTool_face.def("Finite", (Standard_Boolean (TopOpeBRepTool_face::*)() const ) &TopOpeBRepTool_face::Finite, "None");
	cls_TopOpeBRepTool_face.def("Ffinite", (const TopoDS_Face & (TopOpeBRepTool_face::*)() const ) &TopOpeBRepTool_face::Ffinite, "None");
	cls_TopOpeBRepTool_face.def("RealF", (TopoDS_Face (TopOpeBRepTool_face::*)() const ) &TopOpeBRepTool_face::RealF, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_CLASSI.hxx
	py::class_<TopOpeBRepTool_CLASSI, std::unique_ptr<TopOpeBRepTool_CLASSI, Deleter<TopOpeBRepTool_CLASSI>>> cls_TopOpeBRepTool_CLASSI(mod, "TopOpeBRepTool_CLASSI", "None");
	cls_TopOpeBRepTool_CLASSI.def(py::init<>());
	cls_TopOpeBRepTool_CLASSI.def("Init2d", (void (TopOpeBRepTool_CLASSI::*)(const TopoDS_Face &)) &TopOpeBRepTool_CLASSI::Init2d, "None", py::arg("Fref"));
	cls_TopOpeBRepTool_CLASSI.def("HasInit2d", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)() const ) &TopOpeBRepTool_CLASSI::HasInit2d, "None");
	cls_TopOpeBRepTool_CLASSI.def("Add2d", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &)) &TopOpeBRepTool_CLASSI::Add2d, "None", py::arg("S"));
	cls_TopOpeBRepTool_CLASSI.def("GetBox2d", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, Bnd_Box2d &)) &TopOpeBRepTool_CLASSI::GetBox2d, "None", py::arg("S"), py::arg("Box2d"));
	cls_TopOpeBRepTool_CLASSI.def("ClassiBnd2d", (Standard_Integer (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real, const Standard_Boolean)) &TopOpeBRepTool_CLASSI::ClassiBnd2d, "None", py::arg("S1"), py::arg("S2"), py::arg("tol"), py::arg("checklarge"));
	cls_TopOpeBRepTool_CLASSI.def("Classip2d", (Standard_Integer (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepTool_CLASSI::Classip2d, "None", py::arg("S1"), py::arg("S2"), py::arg("stabnd2d12"));
	cls_TopOpeBRepTool_CLASSI.def("Getface", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, TopOpeBRepTool_face &) const ) &TopOpeBRepTool_CLASSI::Getface, "None", py::arg("S"), py::arg("fa"));
	cls_TopOpeBRepTool_CLASSI.def("Classilist", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopTools_ListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_CLASSI::Classilist, "None", py::arg("lS"), py::arg("mapgreasma"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_TOOL.hxx
	py::class_<TopOpeBRepTool_TOOL, std::unique_ptr<TopOpeBRepTool_TOOL, Deleter<TopOpeBRepTool_TOOL>>> cls_TopOpeBRepTool_TOOL(mod, "TopOpeBRepTool_TOOL", "None");
	cls_TopOpeBRepTool_TOOL.def(py::init<>());
	cls_TopOpeBRepTool_TOOL.def_static("OriinSor_", [](const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> Standard_Integer { return TopOpeBRepTool_TOOL::OriinSor(a0, a1); }, py::arg("sub"), py::arg("S"));
	cls_TopOpeBRepTool_TOOL.def_static("OriinSor_", (Standard_Integer (*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepTool_TOOL::OriinSor, "None", py::arg("sub"), py::arg("S"), py::arg("checkclo"));
	cls_TopOpeBRepTool_TOOL.def_static("OriinSorclosed_", (Standard_Integer (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_TOOL::OriinSorclosed, "None", py::arg("sub"), py::arg("S"));
	cls_TopOpeBRepTool_TOOL.def_static("ClosedE_", (Standard_Boolean (*)(const TopoDS_Edge &, TopoDS_Vertex &)) &TopOpeBRepTool_TOOL::ClosedE, "None", py::arg("E"), py::arg("vclo"));
	cls_TopOpeBRepTool_TOOL.def_static("ClosedS_", (Standard_Boolean (*)(const TopoDS_Face &)) &TopOpeBRepTool_TOOL::ClosedS, "None", py::arg("F"));
	cls_TopOpeBRepTool_TOOL.def_static("IsClosingE_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::IsClosingE, "None", py::arg("E"), py::arg("F"));
	cls_TopOpeBRepTool_TOOL.def_static("IsClosingE_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Shape &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::IsClosingE, "None", py::arg("E"), py::arg("W"), py::arg("F"));
	cls_TopOpeBRepTool_TOOL.def_static("Vertices_", (void (*)(const TopoDS_Edge &, TopTools_Array1OfShape &)) &TopOpeBRepTool_TOOL::Vertices, "None", py::arg("E"), py::arg("Vces"));
	cls_TopOpeBRepTool_TOOL.def_static("Vertex_", (TopoDS_Vertex (*)(const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::Vertex, "None", py::arg("Iv"), py::arg("E"));
	cls_TopOpeBRepTool_TOOL.def_static("ParE_", (Standard_Real (*)(const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::ParE, "None", py::arg("Iv"), py::arg("E"));
	cls_TopOpeBRepTool_TOOL.def_static("OnBoundary_", (Standard_Integer (*)(const Standard_Real, const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::OnBoundary, "None", py::arg("par"), py::arg("E"));
	cls_TopOpeBRepTool_TOOL.def_static("UVF_", (gp_Pnt2d (*)(const Standard_Real, const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_TOOL::UVF, "None", py::arg("par"), py::arg("C2DF"));
	cls_TopOpeBRepTool_TOOL.def_static("ParISO_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Edge &, const TopoDS_Face &, Standard_Real &)) &TopOpeBRepTool_TOOL::ParISO, "None", py::arg("p2d"), py::arg("e"), py::arg("f"), py::arg("pare"));
	cls_TopOpeBRepTool_TOOL.def_static("ParE2d_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Edge &, const TopoDS_Face &, Standard_Real &, Standard_Real &)) &TopOpeBRepTool_TOOL::ParE2d, "None", py::arg("p2d"), py::arg("e"), py::arg("f"), py::arg("par"), py::arg("dist"));
	cls_TopOpeBRepTool_TOOL.def_static("Getduv_", (Standard_Boolean (*)(const TopoDS_Face &, const gp_Pnt2d &, const gp_Vec &, const Standard_Real, gp_Dir2d &)) &TopOpeBRepTool_TOOL::Getduv, "None", py::arg("f"), py::arg("uv"), py::arg("dir"), py::arg("factor"), py::arg("duv"));
	cls_TopOpeBRepTool_TOOL.def_static("uvApp_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Edge &, const Standard_Real, const Standard_Real, gp_Pnt2d &)) &TopOpeBRepTool_TOOL::uvApp, "None", py::arg("f"), py::arg("e"), py::arg("par"), py::arg("eps"), py::arg("uvapp"));
	cls_TopOpeBRepTool_TOOL.def_static("TolUV_", (Standard_Real (*)(const TopoDS_Face &, const Standard_Real)) &TopOpeBRepTool_TOOL::TolUV, "None", py::arg("F"), py::arg("tol3d"));
	cls_TopOpeBRepTool_TOOL.def_static("TolP_", (Standard_Real (*)(const TopoDS_Edge &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::TolP, "None", py::arg("E"), py::arg("F"));
	cls_TopOpeBRepTool_TOOL.def_static("minDUV_", (Standard_Real (*)(const TopoDS_Face &)) &TopOpeBRepTool_TOOL::minDUV, "None", py::arg("F"));
	cls_TopOpeBRepTool_TOOL.def_static("outUVbounds_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::outUVbounds, "None", py::arg("uv"), py::arg("F"));
	cls_TopOpeBRepTool_TOOL.def_static("stuvF_", (void (*)(const gp_Pnt2d &, const TopoDS_Face &, Standard_Integer &, Standard_Integer &)) &TopOpeBRepTool_TOOL::stuvF, "None", py::arg("uv"), py::arg("F"), py::arg("onU"), py::arg("onV"));
	cls_TopOpeBRepTool_TOOL.def_static("TggeomE_", (Standard_Boolean (*)(const Standard_Real, const BRepAdaptor_Curve &, gp_Vec &)) &TopOpeBRepTool_TOOL::TggeomE, "None", py::arg("par"), py::arg("BC"), py::arg("Tg"));
	cls_TopOpeBRepTool_TOOL.def_static("TggeomE_", (Standard_Boolean (*)(const Standard_Real, const TopoDS_Edge &, gp_Vec &)) &TopOpeBRepTool_TOOL::TggeomE, "None", py::arg("par"), py::arg("E"), py::arg("Tg"));
	cls_TopOpeBRepTool_TOOL.def_static("TgINSIDE_", (Standard_Boolean (*)(const TopoDS_Vertex &, const TopoDS_Edge &, gp_Vec &, Standard_Integer &)) &TopOpeBRepTool_TOOL::TgINSIDE, "None", py::arg("v"), py::arg("E"), py::arg("Tg"), py::arg("OvinE"));
	cls_TopOpeBRepTool_TOOL.def_static("Tg2d_", (gp_Vec2d (*)(const Standard_Integer, const TopoDS_Edge &, const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_TOOL::Tg2d, "None", py::arg("iv"), py::arg("E"), py::arg("C2DF"));
	cls_TopOpeBRepTool_TOOL.def_static("Tg2dApp_", (gp_Vec2d (*)(const Standard_Integer, const TopoDS_Edge &, const TopOpeBRepTool_C2DF &, const Standard_Real)) &TopOpeBRepTool_TOOL::Tg2dApp, "None", py::arg("iv"), py::arg("E"), py::arg("C2DF"), py::arg("factor"));
	cls_TopOpeBRepTool_TOOL.def_static("tryTg2dApp_", (gp_Vec2d (*)(const Standard_Integer, const TopoDS_Edge &, const TopOpeBRepTool_C2DF &, const Standard_Real)) &TopOpeBRepTool_TOOL::tryTg2dApp, "None", py::arg("iv"), py::arg("E"), py::arg("C2DF"), py::arg("factor"));
	cls_TopOpeBRepTool_TOOL.def_static("XX_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &, const Standard_Real, const TopoDS_Edge &, gp_Dir &)) &TopOpeBRepTool_TOOL::XX, "None", py::arg("uv"), py::arg("f"), py::arg("par"), py::arg("e"), py::arg("xx"));
	cls_TopOpeBRepTool_TOOL.def_static("Nt_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &, gp_Dir &)) &TopOpeBRepTool_TOOL::Nt, "None", py::arg("uv"), py::arg("f"), py::arg("normt"));
	cls_TopOpeBRepTool_TOOL.def_static("NggeomF_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &, gp_Vec &)) &TopOpeBRepTool_TOOL::NggeomF, "None", py::arg("uv"), py::arg("F"), py::arg("ng"));
	cls_TopOpeBRepTool_TOOL.def_static("NgApp_", (Standard_Boolean (*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Dir &)) &TopOpeBRepTool_TOOL::NgApp, "None", py::arg("par"), py::arg("E"), py::arg("F"), py::arg("tola"), py::arg("ngApp"));
	cls_TopOpeBRepTool_TOOL.def_static("tryNgApp_", (Standard_Boolean (*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Dir &)) &TopOpeBRepTool_TOOL::tryNgApp, "None", py::arg("par"), py::arg("E"), py::arg("F"), py::arg("tola"), py::arg("ng"));
	cls_TopOpeBRepTool_TOOL.def_static("tryOriEinF_", (Standard_Integer (*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::tryOriEinF, "None", py::arg("par"), py::arg("E"), py::arg("F"));
	cls_TopOpeBRepTool_TOOL.def_static("IsQuad_", (Standard_Boolean (*)(const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::IsQuad, "None", py::arg("E"));
	cls_TopOpeBRepTool_TOOL.def_static("IsQuad_", (Standard_Boolean (*)(const TopoDS_Face &)) &TopOpeBRepTool_TOOL::IsQuad, "None", py::arg("F"));
	cls_TopOpeBRepTool_TOOL.def_static("CurvE_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real, const gp_Dir &, Standard_Real &)) &TopOpeBRepTool_TOOL::CurvE, "None", py::arg("E"), py::arg("par"), py::arg("tg0"), py::arg("Curv"));
	cls_TopOpeBRepTool_TOOL.def_static("CurvF_", (Standard_Boolean (*)(const TopoDS_Face &, const gp_Pnt2d &, const gp_Dir &, Standard_Real &, Standard_Boolean &)) &TopOpeBRepTool_TOOL::CurvF, "None", py::arg("F"), py::arg("uv"), py::arg("tg0"), py::arg("Curv"), py::arg("direct"));
	cls_TopOpeBRepTool_TOOL.def_static("UVISO_", (Standard_Boolean (*)(const opencascade::handle<Geom2d_Curve> &, Standard_Boolean &, Standard_Boolean &, gp_Dir2d &, gp_Pnt2d &)) &TopOpeBRepTool_TOOL::UVISO, "None", py::arg("PC"), py::arg("isou"), py::arg("isov"), py::arg("d2d"), py::arg("o2d"));
	cls_TopOpeBRepTool_TOOL.def_static("UVISO_", (Standard_Boolean (*)(const TopOpeBRepTool_C2DF &, Standard_Boolean &, Standard_Boolean &, gp_Dir2d &, gp_Pnt2d &)) &TopOpeBRepTool_TOOL::UVISO, "None", py::arg("C2DF"), py::arg("isou"), py::arg("isov"), py::arg("d2d"), py::arg("o2d"));
	cls_TopOpeBRepTool_TOOL.def_static("UVISO_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, Standard_Boolean &, Standard_Boolean &, gp_Dir2d &, gp_Pnt2d &)) &TopOpeBRepTool_TOOL::UVISO, "None", py::arg("E"), py::arg("F"), py::arg("isou"), py::arg("isov"), py::arg("d2d"), py::arg("o2d"));
	cls_TopOpeBRepTool_TOOL.def_static("IsonCLO_", (Standard_Boolean (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real)) &TopOpeBRepTool_TOOL::IsonCLO, "None", py::arg("PC"), py::arg("onU"), py::arg("xfirst"), py::arg("xperiod"), py::arg("xtol"));
	cls_TopOpeBRepTool_TOOL.def_static("IsonCLO_", (Standard_Boolean (*)(const TopOpeBRepTool_C2DF &, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real)) &TopOpeBRepTool_TOOL::IsonCLO, "None", py::arg("C2DF"), py::arg("onU"), py::arg("xfirst"), py::arg("xperiod"), py::arg("xtol"));
	cls_TopOpeBRepTool_TOOL.def_static("TrslUV_", (void (*)(const gp_Vec2d &, TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_TOOL::TrslUV, "None", py::arg("t2d"), py::arg("C2DF"));
	cls_TopOpeBRepTool_TOOL.def_static("TrslUVModifE_", (Standard_Boolean (*)(const gp_Vec2d &, const TopoDS_Face &, TopoDS_Edge &)) &TopOpeBRepTool_TOOL::TrslUVModifE, "None", py::arg("t2d"), py::arg("F"), py::arg("E"));
	cls_TopOpeBRepTool_TOOL.def_static("Matter_", (Standard_Real (*)(const gp_Vec &, const gp_Vec &, const gp_Vec &)) &TopOpeBRepTool_TOOL::Matter, "None", py::arg("d1"), py::arg("d2"), py::arg("ref"));
	cls_TopOpeBRepTool_TOOL.def_static("Matter_", (Standard_Real (*)(const gp_Vec2d &, const gp_Vec2d &)) &TopOpeBRepTool_TOOL::Matter, "None", py::arg("d1"), py::arg("d2"));
	cls_TopOpeBRepTool_TOOL.def_static("Matter_", (Standard_Boolean (*)(const gp_Dir &, const gp_Dir &, const gp_Dir &, const gp_Dir &, const Standard_Real, Standard_Real &)) &TopOpeBRepTool_TOOL::Matter, "None", py::arg("xx1"), py::arg("nt1"), py::arg("xx2"), py::arg("nt2"), py::arg("tola"), py::arg("Ang"));
	cls_TopOpeBRepTool_TOOL.def_static("Matter_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const Standard_Real, const Standard_Real, Standard_Real &)) &TopOpeBRepTool_TOOL::Matter, "None", py::arg("f1"), py::arg("f2"), py::arg("e"), py::arg("pare"), py::arg("tola"), py::arg("Ang"));
	cls_TopOpeBRepTool_TOOL.def_static("MatterKPtg_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, Standard_Real &)) &TopOpeBRepTool_TOOL::MatterKPtg, "None", py::arg("f1"), py::arg("f2"), py::arg("e"), py::arg("Ang"));
	cls_TopOpeBRepTool_TOOL.def_static("Getstp3dF_", (Standard_Boolean (*)(const gp_Pnt &, const TopoDS_Face &, gp_Pnt2d &, TopAbs_State &)) &TopOpeBRepTool_TOOL::Getstp3dF, "None", py::arg("p"), py::arg("f"), py::arg("uv"), py::arg("st"));
	cls_TopOpeBRepTool_TOOL.def_static("SplitE_", (Standard_Boolean (*)(const TopoDS_Edge &, TopTools_ListOfShape &)) &TopOpeBRepTool_TOOL::SplitE, "None", py::arg("Eanc"), py::arg("Splits"));
	cls_TopOpeBRepTool_TOOL.def_static("MkShell_", (void (*)(const TopTools_ListOfShape &, TopoDS_Shape &)) &TopOpeBRepTool_TOOL::MkShell, "None", py::arg("lF"), py::arg("She"));
	cls_TopOpeBRepTool_TOOL.def_static("Remove_", (Standard_Boolean (*)(TopTools_ListOfShape &, const TopoDS_Shape &)) &TopOpeBRepTool_TOOL::Remove, "None", py::arg("loS"), py::arg("toremove"));
	cls_TopOpeBRepTool_TOOL.def_static("WireToFace_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_DataMapOfShapeListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepTool_TOOL::WireToFace, "None", py::arg("Fref"), py::arg("mapWlow"), py::arg("lFs"));
	cls_TopOpeBRepTool_TOOL.def_static("EdgeONFace_", (Standard_Boolean (*)(const Standard_Real, const TopoDS_Edge &, const gp_Pnt2d &, const TopoDS_Face &, Standard_Boolean &)) &TopOpeBRepTool_TOOL::EdgeONFace, "None", py::arg("par"), py::arg("ed"), py::arg("uv"), py::arg("fa"), py::arg("isonfa"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_CORRISO.hxx
	py::class_<TopOpeBRepTool_CORRISO, std::unique_ptr<TopOpeBRepTool_CORRISO, Deleter<TopOpeBRepTool_CORRISO>>> cls_TopOpeBRepTool_CORRISO(mod, "TopOpeBRepTool_CORRISO", "Fref is built on x-periodic surface (x=u,v). S built on Fref's geometry, should be UVClosed.");
	cls_TopOpeBRepTool_CORRISO.def(py::init<>());
	cls_TopOpeBRepTool_CORRISO.def(py::init<const TopoDS_Face &>(), py::arg("FRef"));
	cls_TopOpeBRepTool_CORRISO.def("Fref", (const TopoDS_Face & (TopOpeBRepTool_CORRISO::*)() const ) &TopOpeBRepTool_CORRISO::Fref, "None");
	cls_TopOpeBRepTool_CORRISO.def("GASref", (const GeomAdaptor_Surface & (TopOpeBRepTool_CORRISO::*)() const ) &TopOpeBRepTool_CORRISO::GASref, "None");
	cls_TopOpeBRepTool_CORRISO.def("Refclosed", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const Standard_Integer, Standard_Real &) const ) &TopOpeBRepTool_CORRISO::Refclosed, "None", py::arg("x"), py::arg("xperiod"));
	cls_TopOpeBRepTool_CORRISO.def("Init", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Shape &)) &TopOpeBRepTool_CORRISO::Init, "None", py::arg("S"));
	cls_TopOpeBRepTool_CORRISO.def("S", (const TopoDS_Shape & (TopOpeBRepTool_CORRISO::*)() const ) &TopOpeBRepTool_CORRISO::S, "None");
	cls_TopOpeBRepTool_CORRISO.def("Eds", (const TopTools_ListOfShape & (TopOpeBRepTool_CORRISO::*)() const ) &TopOpeBRepTool_CORRISO::Eds, "None");
	cls_TopOpeBRepTool_CORRISO.def("UVClosed", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)() const ) &TopOpeBRepTool_CORRISO::UVClosed, "None");
	cls_TopOpeBRepTool_CORRISO.def("Tol", (Standard_Real (TopOpeBRepTool_CORRISO::*)(const Standard_Integer, const Standard_Real) const ) &TopOpeBRepTool_CORRISO::Tol, "None", py::arg("I"), py::arg("tol3d"));
	cls_TopOpeBRepTool_CORRISO.def("PurgeFyClosingE", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopTools_ListOfShape &, TopTools_ListOfShape &) const ) &TopOpeBRepTool_CORRISO::PurgeFyClosingE, "None", py::arg("ClEds"), py::arg("fyClEds"));
	cls_TopOpeBRepTool_CORRISO.def("EdgeOUTofBoundsUV", (Standard_Integer (TopOpeBRepTool_CORRISO::*)(const TopoDS_Edge &, const Standard_Boolean, const Standard_Real, Standard_Real &) const ) &TopOpeBRepTool_CORRISO::EdgeOUTofBoundsUV, "None", py::arg("E"), py::arg("onU"), py::arg("tolx"), py::arg("parspE"));
	cls_TopOpeBRepTool_CORRISO.def("EdgesOUTofBoundsUV", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopTools_ListOfShape &, const Standard_Boolean, const Standard_Real, TopTools_DataMapOfOrientedShapeInteger &) const ) &TopOpeBRepTool_CORRISO::EdgesOUTofBoundsUV, "None", py::arg("EdsToCheck"), py::arg("onU"), py::arg("tolx"), py::arg("FyEds"));
	cls_TopOpeBRepTool_CORRISO.def("EdgeWithFaultyUV", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Edge &, Standard_Integer &) const ) &TopOpeBRepTool_CORRISO::EdgeWithFaultyUV, "None", py::arg("E"), py::arg("Ivfaulty"));
	cls_TopOpeBRepTool_CORRISO.def("EdgesWithFaultyUV", [](TopOpeBRepTool_CORRISO &self, const TopTools_ListOfShape & a0, const Standard_Integer a1, TopTools_DataMapOfOrientedShapeInteger & a2) -> Standard_Boolean { return self.EdgesWithFaultyUV(a0, a1, a2); }, py::arg("EdsToCheck"), py::arg("nfybounds"), py::arg("FyEds"));
	cls_TopOpeBRepTool_CORRISO.def("EdgesWithFaultyUV", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopTools_ListOfShape &, const Standard_Integer, TopTools_DataMapOfOrientedShapeInteger &, const Standard_Boolean) const ) &TopOpeBRepTool_CORRISO::EdgesWithFaultyUV, "None", py::arg("EdsToCheck"), py::arg("nfybounds"), py::arg("FyEds"), py::arg("stopatfirst"));
	cls_TopOpeBRepTool_CORRISO.def("EdgeWithFaultyUV", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopTools_ListOfShape &, const Standard_Integer, TopoDS_Shape &, Standard_Integer &) const ) &TopOpeBRepTool_CORRISO::EdgeWithFaultyUV, "None", py::arg("EdsToCheck"), py::arg("nfybounds"), py::arg("fyE"), py::arg("Ifaulty"));
	cls_TopOpeBRepTool_CORRISO.def("TrslUV", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const Standard_Boolean, const TopTools_DataMapOfOrientedShapeInteger &)) &TopOpeBRepTool_CORRISO::TrslUV, "None", py::arg("onU"), py::arg("FyEds"));
	cls_TopOpeBRepTool_CORRISO.def("GetnewS", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(TopoDS_Face &) const ) &TopOpeBRepTool_CORRISO::GetnewS, "None", py::arg("newS"));
	cls_TopOpeBRepTool_CORRISO.def("UVRep", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Edge &, TopOpeBRepTool_C2DF &) const ) &TopOpeBRepTool_CORRISO::UVRep, "None", py::arg("E"), py::arg("C2DF"));
	cls_TopOpeBRepTool_CORRISO.def("SetUVRep", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Edge &, const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_CORRISO::SetUVRep, "None", py::arg("E"), py::arg("C2DF"));
	cls_TopOpeBRepTool_CORRISO.def("Connexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, TopTools_ListOfShape &) const ) &TopOpeBRepTool_CORRISO::Connexity, "None", py::arg("V"), py::arg("Eds"));
	cls_TopOpeBRepTool_CORRISO.def("SetConnexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, const TopTools_ListOfShape &)) &TopOpeBRepTool_CORRISO::SetConnexity, "None", py::arg("V"), py::arg("Eds"));
	cls_TopOpeBRepTool_CORRISO.def("AddNewConnexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, const TopoDS_Edge &)) &TopOpeBRepTool_CORRISO::AddNewConnexity, "None", py::arg("V"), py::arg("E"));
	cls_TopOpeBRepTool_CORRISO.def("RemoveOldConnexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, const TopoDS_Edge &)) &TopOpeBRepTool_CORRISO::RemoveOldConnexity, "None", py::arg("V"), py::arg("E"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_REGUW.hxx
	py::class_<TopOpeBRepTool_REGUW, std::unique_ptr<TopOpeBRepTool_REGUW, Deleter<TopOpeBRepTool_REGUW>>> cls_TopOpeBRepTool_REGUW(mod, "TopOpeBRepTool_REGUW", "None");
	cls_TopOpeBRepTool_REGUW.def(py::init<const TopoDS_Face &>(), py::arg("FRef"));
	cls_TopOpeBRepTool_REGUW.def("Fref", (const TopoDS_Face & (TopOpeBRepTool_REGUW::*)() const ) &TopOpeBRepTool_REGUW::Fref, "None");
	cls_TopOpeBRepTool_REGUW.def("SetEsplits", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUW::SetEsplits, "None", py::arg("Esplits"));
	cls_TopOpeBRepTool_REGUW.def("GetEsplits", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &) const ) &TopOpeBRepTool_REGUW::GetEsplits, "None", py::arg("Esplits"));
	cls_TopOpeBRepTool_REGUW.def("SetOwNw", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUW::SetOwNw, "None", py::arg("OwNw"));
	cls_TopOpeBRepTool_REGUW.def("GetOwNw", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &) const ) &TopOpeBRepTool_REGUW::GetOwNw, "None", py::arg("OwNw"));
	cls_TopOpeBRepTool_REGUW.def("SplitEds", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::SplitEds, "None");
	cls_TopOpeBRepTool_REGUW.def("Init", (void (TopOpeBRepTool_REGUW::*)(const TopoDS_Shape &)) &TopOpeBRepTool_REGUW::Init, "None", py::arg("S"));
	cls_TopOpeBRepTool_REGUW.def("S", (const TopoDS_Shape & (TopOpeBRepTool_REGUW::*)() const ) &TopOpeBRepTool_REGUW::S, "None");
	cls_TopOpeBRepTool_REGUW.def("HasInit", (Standard_Boolean (TopOpeBRepTool_REGUW::*)() const ) &TopOpeBRepTool_REGUW::HasInit, "None");
	cls_TopOpeBRepTool_REGUW.def("MapS", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::MapS, "None");
	cls_TopOpeBRepTool_REGUW.def("REGU", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const Standard_Integer, const TopoDS_Shape &, TopTools_ListOfShape &)) &TopOpeBRepTool_REGUW::REGU, "None", py::arg("istep"), py::arg("Scur"), py::arg("Splits"));
	cls_TopOpeBRepTool_REGUW.def("REGU", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::REGU, "None");
	cls_TopOpeBRepTool_REGUW.def("GetSplits", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(TopTools_ListOfShape &) const ) &TopOpeBRepTool_REGUW::GetSplits, "None", py::arg("Splits"));
	cls_TopOpeBRepTool_REGUW.def("InitBlock", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::InitBlock, "None");
	cls_TopOpeBRepTool_REGUW.def("NextinBlock", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::NextinBlock, "None");
	cls_TopOpeBRepTool_REGUW.def("NearestE", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopTools_ListOfShape &, TopoDS_Edge &) const ) &TopOpeBRepTool_REGUW::NearestE, "None", py::arg("loe"), py::arg("efound"));
	cls_TopOpeBRepTool_REGUW.def("Connexity", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &, TopOpeBRepTool_connexity &) const ) &TopOpeBRepTool_REGUW::Connexity, "None", py::arg("v"), py::arg("co"));
	cls_TopOpeBRepTool_REGUW.def("AddNewConnexity", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &, const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_REGUW::AddNewConnexity, "None", py::arg("v"), py::arg("OriKey"), py::arg("e"));
	cls_TopOpeBRepTool_REGUW.def("RemoveOldConnexity", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &, const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_REGUW::RemoveOldConnexity, "None", py::arg("v"), py::arg("OriKey"), py::arg("e"));
	cls_TopOpeBRepTool_REGUW.def("UpdateMultiple", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &)) &TopOpeBRepTool_REGUW::UpdateMultiple, "None", py::arg("v"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_REGUS.hxx
	py::class_<TopOpeBRepTool_REGUS, std::unique_ptr<TopOpeBRepTool_REGUS, Deleter<TopOpeBRepTool_REGUS>>> cls_TopOpeBRepTool_REGUS(mod, "TopOpeBRepTool_REGUS", "None");
	cls_TopOpeBRepTool_REGUS.def(py::init<>());
	cls_TopOpeBRepTool_REGUS.def("Init", (void (TopOpeBRepTool_REGUS::*)(const TopoDS_Shape &)) &TopOpeBRepTool_REGUS::Init, "None", py::arg("S"));
	cls_TopOpeBRepTool_REGUS.def("S", (const TopoDS_Shape & (TopOpeBRepTool_REGUS::*)() const ) &TopOpeBRepTool_REGUS::S, "None");
	cls_TopOpeBRepTool_REGUS.def("MapS", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::MapS, "None");
	cls_TopOpeBRepTool_REGUS.def_static("WireToFace_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepTool_REGUS::WireToFace, "None", py::arg("Fanc"), py::arg("nWs"), py::arg("nFs"));
	cls_TopOpeBRepTool_REGUS.def_static("SplitF_", (Standard_Boolean (*)(const TopoDS_Face &, TopTools_ListOfShape &)) &TopOpeBRepTool_REGUS::SplitF, "None", py::arg("Fanc"), py::arg("FSplits"));
	cls_TopOpeBRepTool_REGUS.def("SplitFaces", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::SplitFaces, "None");
	cls_TopOpeBRepTool_REGUS.def("REGU", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::REGU, "None");
	cls_TopOpeBRepTool_REGUS.def("SetFsplits", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUS::SetFsplits, "None", py::arg("Fsplits"));
	cls_TopOpeBRepTool_REGUS.def("GetFsplits", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &) const ) &TopOpeBRepTool_REGUS::GetFsplits, "None", py::arg("Fsplits"));
	cls_TopOpeBRepTool_REGUS.def("SetOshNsh", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUS::SetOshNsh, "None", py::arg("OshNsh"));
	cls_TopOpeBRepTool_REGUS.def("GetOshNsh", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &) const ) &TopOpeBRepTool_REGUS::GetOshNsh, "None", py::arg("OshNsh"));
	cls_TopOpeBRepTool_REGUS.def("InitBlock", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::InitBlock, "None");
	cls_TopOpeBRepTool_REGUS.def("NextinBlock", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::NextinBlock, "None");
	cls_TopOpeBRepTool_REGUS.def("NearestF", (Standard_Boolean (TopOpeBRepTool_REGUS::*)(const TopoDS_Edge &, const TopTools_ListOfShape &, TopoDS_Face &) const ) &TopOpeBRepTool_REGUS::NearestF, "None", py::arg("e"), py::arg("lof"), py::arg("ffound"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_makeTransition.hxx
	py::class_<TopOpeBRepTool_makeTransition, std::unique_ptr<TopOpeBRepTool_makeTransition, Deleter<TopOpeBRepTool_makeTransition>>> cls_TopOpeBRepTool_makeTransition(mod, "TopOpeBRepTool_makeTransition", "None");
	cls_TopOpeBRepTool_makeTransition.def(py::init<>());
	cls_TopOpeBRepTool_makeTransition.def("Initialize", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real, const Standard_Real, const TopoDS_Face &, const gp_Pnt2d &, const Standard_Real)) &TopOpeBRepTool_makeTransition::Initialize, "None", py::arg("E"), py::arg("pbef"), py::arg("paft"), py::arg("parE"), py::arg("FS"), py::arg("uv"), py::arg("factor"));
	cls_TopOpeBRepTool_makeTransition.def("Setfactor", (void (TopOpeBRepTool_makeTransition::*)(const Standard_Real)) &TopOpeBRepTool_makeTransition::Setfactor, "None", py::arg("factor"));
	cls_TopOpeBRepTool_makeTransition.def("Getfactor", (Standard_Real (TopOpeBRepTool_makeTransition::*)() const ) &TopOpeBRepTool_makeTransition::Getfactor, "None");
	cls_TopOpeBRepTool_makeTransition.def("IsT2d", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)() const ) &TopOpeBRepTool_makeTransition::IsT2d, "None");
	cls_TopOpeBRepTool_makeTransition.def("SetRest", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(const TopoDS_Edge &, const Standard_Real)) &TopOpeBRepTool_makeTransition::SetRest, "None", py::arg("ES"), py::arg("parES"));
	cls_TopOpeBRepTool_makeTransition.def("HasRest", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)() const ) &TopOpeBRepTool_makeTransition::HasRest, "None");
	cls_TopOpeBRepTool_makeTransition.def("MkT2donE", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &) const ) &TopOpeBRepTool_makeTransition::MkT2donE, "None", py::arg("stb"), py::arg("sta"));
	cls_TopOpeBRepTool_makeTransition.def("MkT3onE", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &) const ) &TopOpeBRepTool_makeTransition::MkT3onE, "None", py::arg("stb"), py::arg("sta"));
	cls_TopOpeBRepTool_makeTransition.def("MkT3dproj", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &) const ) &TopOpeBRepTool_makeTransition::MkT3dproj, "None", py::arg("stb"), py::arg("sta"));
	cls_TopOpeBRepTool_makeTransition.def("MkTonE", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &)) &TopOpeBRepTool_makeTransition::MkTonE, "None", py::arg("stb"), py::arg("sta"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_mkTondgE.hxx
	py::class_<TopOpeBRepTool_mkTondgE, std::unique_ptr<TopOpeBRepTool_mkTondgE, Deleter<TopOpeBRepTool_mkTondgE>>> cls_TopOpeBRepTool_mkTondgE(mod, "TopOpeBRepTool_mkTondgE", "None");
	cls_TopOpeBRepTool_mkTondgE.def(py::init<>());
	cls_TopOpeBRepTool_mkTondgE.def("Initialize", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)(const TopoDS_Edge &, const TopoDS_Face &, const gp_Pnt2d &, const TopoDS_Face &)) &TopOpeBRepTool_mkTondgE::Initialize, "None", py::arg("dgE"), py::arg("F"), py::arg("uvi"), py::arg("Fi"));
	cls_TopOpeBRepTool_mkTondgE.def("SetclE", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)(const TopoDS_Edge &)) &TopOpeBRepTool_mkTondgE::SetclE, "None", py::arg("clE"));
	cls_TopOpeBRepTool_mkTondgE.def("IsT2d", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)() const ) &TopOpeBRepTool_mkTondgE::IsT2d, "None");
	cls_TopOpeBRepTool_mkTondgE.def("SetRest", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)(const Standard_Real, const TopoDS_Edge &)) &TopOpeBRepTool_mkTondgE::SetRest, "None", py::arg("pari"), py::arg("Ei"));
	cls_TopOpeBRepTool_mkTondgE.def("GetAllRest", (Standard_Integer (TopOpeBRepTool_mkTondgE::*)(TopTools_ListOfShape &)) &TopOpeBRepTool_mkTondgE::GetAllRest, "None", py::arg("lEi"));
	cls_TopOpeBRepTool_mkTondgE.def("MkTonE", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)(Standard_Integer &, Standard_Real &, Standard_Real &)) &TopOpeBRepTool_mkTondgE::MkTonE, "None", py::arg("mkT"), py::arg("par1"), py::arg("par2"));
	cls_TopOpeBRepTool_mkTondgE.def("MkTonE", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)(const TopoDS_Edge &, Standard_Integer &, Standard_Real &, Standard_Real &)) &TopOpeBRepTool_mkTondgE::MkTonE, "None", py::arg("Ei"), py::arg("mkT"), py::arg("par1"), py::arg("par2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_PurgeInternalEdges.hxx
	py::class_<TopOpeBRepTool_PurgeInternalEdges, std::unique_ptr<TopOpeBRepTool_PurgeInternalEdges, Deleter<TopOpeBRepTool_PurgeInternalEdges>>> cls_TopOpeBRepTool_PurgeInternalEdges(mod, "TopOpeBRepTool_PurgeInternalEdges", "remove from a shape, the internal edges that are not connected to any face in the shape. We can get the list of the edges as a DataMapOfShapeListOfShape with a Face of the Shape as the key and a list of internal edges as the value. The list of internal edges means edges that are not connected to any face in the shape.");
	cls_TopOpeBRepTool_PurgeInternalEdges.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_TopOpeBRepTool_PurgeInternalEdges.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theShape"), py::arg("PerformNow"));
	cls_TopOpeBRepTool_PurgeInternalEdges.def("Faces", (void (TopOpeBRepTool_PurgeInternalEdges::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_PurgeInternalEdges::Faces, "returns the list internal edges associated with the faces of the myShape. If PerformNow was False when created, then call the private Perform method that do the main job.", py::arg("theMapFacLstEdg"));
	cls_TopOpeBRepTool_PurgeInternalEdges.def("Shape", (TopoDS_Shape & (TopOpeBRepTool_PurgeInternalEdges::*)()) &TopOpeBRepTool_PurgeInternalEdges::Shape, "returns myShape modified with the list of internal edges removed from it.");
	cls_TopOpeBRepTool_PurgeInternalEdges.def("NbEdges", (Standard_Integer (TopOpeBRepTool_PurgeInternalEdges::*)() const ) &TopOpeBRepTool_PurgeInternalEdges::NbEdges, "returns the number of edges candidate to be removed");
	cls_TopOpeBRepTool_PurgeInternalEdges.def("IsDone", (Standard_Boolean (TopOpeBRepTool_PurgeInternalEdges::*)() const ) &TopOpeBRepTool_PurgeInternalEdges::IsDone, "returns False if the list of internal edges has not been extracted");
	cls_TopOpeBRepTool_PurgeInternalEdges.def("Perform", (void (TopOpeBRepTool_PurgeInternalEdges::*)()) &TopOpeBRepTool_PurgeInternalEdges::Perform, "Using the list of internal edge from each face, rebuild myShape by removing thoses edges.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_FuseEdges.hxx
	py::class_<TopOpeBRepTool_FuseEdges, std::unique_ptr<TopOpeBRepTool_FuseEdges, Deleter<TopOpeBRepTool_FuseEdges>>> cls_TopOpeBRepTool_FuseEdges(mod, "TopOpeBRepTool_FuseEdges", "This class can detect vertices in a face that can be considered useless and then perform the fuse of the edges and remove the useless vertices. By useles vertices, we mean : * vertices that have exactly two connex edges * the edges connex to the vertex must have exactly the same 2 connex faces . * The edges connex to the vertex must have the same geometric support.");
	cls_TopOpeBRepTool_FuseEdges.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_TopOpeBRepTool_FuseEdges.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theShape"), py::arg("PerformNow"));
	cls_TopOpeBRepTool_FuseEdges.def("AvoidEdges", (void (TopOpeBRepTool_FuseEdges::*)(const TopTools_IndexedMapOfShape &)) &TopOpeBRepTool_FuseEdges::AvoidEdges, "set edges to avoid being fused", py::arg("theMapEdg"));
	cls_TopOpeBRepTool_FuseEdges.def("Edges", (void (TopOpeBRepTool_FuseEdges::*)(TopTools_DataMapOfIntegerListOfShape &)) &TopOpeBRepTool_FuseEdges::Edges, "returns all the list of edges to be fused each list of the map represent a set of connex edges that can be fused.", py::arg("theMapLstEdg"));
	cls_TopOpeBRepTool_FuseEdges.def("ResultEdges", (void (TopOpeBRepTool_FuseEdges::*)(TopTools_DataMapOfIntegerShape &)) &TopOpeBRepTool_FuseEdges::ResultEdges, "returns all the fused edges. each integer entry in the map corresponds to the integer in the DataMapOfIntegerListOfShape we get in method Edges. That is to say, to the list of edges in theMapLstEdg(i) corresponds the resulting edge theMapEdge(i)", py::arg("theMapEdg"));
	cls_TopOpeBRepTool_FuseEdges.def("Faces", (void (TopOpeBRepTool_FuseEdges::*)(TopTools_DataMapOfShapeShape &)) &TopOpeBRepTool_FuseEdges::Faces, "returns the map of modified faces.", py::arg("theMapFac"));
	cls_TopOpeBRepTool_FuseEdges.def("Shape", (TopoDS_Shape & (TopOpeBRepTool_FuseEdges::*)()) &TopOpeBRepTool_FuseEdges::Shape, "returns myShape modified with the list of internal edges removed from it.");
	cls_TopOpeBRepTool_FuseEdges.def("NbVertices", (Standard_Integer (TopOpeBRepTool_FuseEdges::*)()) &TopOpeBRepTool_FuseEdges::NbVertices, "returns the number of vertices candidate to be removed");
	cls_TopOpeBRepTool_FuseEdges.def("Perform", (void (TopOpeBRepTool_FuseEdges::*)()) &TopOpeBRepTool_FuseEdges::Perform, "Using map of list of connex edges, fuse each list to one edge and then update myShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool.hxx
	py::class_<TopOpeBRepTool, std::unique_ptr<TopOpeBRepTool, Deleter<TopOpeBRepTool>>> cls_TopOpeBRepTool(mod, "TopOpeBRepTool", "This package provides services used by the TopOpeBRep package performing topological operations on the BRep data structure.");
	cls_TopOpeBRepTool.def(py::init<>());
	cls_TopOpeBRepTool.def_static("PurgeClosingEdges_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const TopTools_DataMapOfShapeInteger &, TopTools_IndexedMapOfOrientedShape &)) &TopOpeBRepTool::PurgeClosingEdges, "Fuse edges (in a wire) of a shape where we have useless vertex. In case face <FF> is built on UV-non-connexed wires (with the two closing edges FORWARD and REVERSED, in spite of one only), we find out the faulty edge, add the faulty shapes (edge,wire,face) to <MshNOK>. <FF> is a face descendant of <F>. <MWisOld>(wire) = 1 if wire is wire of <F> 0 wire results from <F>'s wire splitted. returns false if purge fails", py::arg("F"), py::arg("FF"), py::arg("MWisOld"), py::arg("MshNOK"));
	cls_TopOpeBRepTool.def_static("PurgeClosingEdges_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_ListOfShape &, const TopTools_DataMapOfShapeInteger &, TopTools_IndexedMapOfOrientedShape &)) &TopOpeBRepTool::PurgeClosingEdges, "None", py::arg("F"), py::arg("LOF"), py::arg("MWisOld"), py::arg("MshNOK"));
	cls_TopOpeBRepTool.def_static("CorrectONUVISO_", (Standard_Boolean (*)(const TopoDS_Face &, TopoDS_Face &)) &TopOpeBRepTool::CorrectONUVISO, "None", py::arg("F"), py::arg("Fsp"));
	cls_TopOpeBRepTool.def_static("MakeFaces_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_ListOfShape &, const TopTools_IndexedMapOfOrientedShape &, TopTools_ListOfShape &)) &TopOpeBRepTool::MakeFaces, "Builds up the correct list of faces <LOFF> from <LOF>, using faulty shapes from map <MshNOK>. <LOF> is the list of <F>'s descendant faces. returns false if building fails", py::arg("F"), py::arg("LOF"), py::arg("MshNOK"), py::arg("LOFF"));
	cls_TopOpeBRepTool.def_static("Regularize_", (Standard_Boolean (*)(const TopoDS_Face &, TopTools_ListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool::Regularize, "Returns <False> if the face is valid (the UV representation of the face is a set of pcurves connexed by points with connexity 2). Else, splits <aFace> in order to return a list of valid faces.", py::arg("aFace"), py::arg("aListOfFaces"), py::arg("ESplits"));
	cls_TopOpeBRepTool.def_static("RegularizeWires_", (Standard_Boolean (*)(const TopoDS_Face &, TopTools_DataMapOfShapeListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool::RegularizeWires, "Returns <False> if the face is valid (the UV representation of the face is a set of pcurves connexed by points with connexity 2). Else, splits wires of the face, these are boundaries of the new faces to build up; <OldWiresNewWires> describes (wire, splits of wire); <ESplits> describes (edge, edge's splits)", py::arg("aFace"), py::arg("OldWiresNewWires"), py::arg("ESplits"));
	cls_TopOpeBRepTool.def_static("RegularizeFace_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_DataMapOfShapeListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepTool::RegularizeFace, "Classify wire's splits of map <OldWiresnewWires> in order to compute <aListOfFaces>, the splits of <aFace>.", py::arg("aFace"), py::arg("OldWiresnewWires"), py::arg("aListOfFaces"));
	cls_TopOpeBRepTool.def_static("RegularizeShells_", (Standard_Boolean (*)(const TopoDS_Solid &, TopTools_DataMapOfShapeListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool::RegularizeShells, "Returns <False> if the shell is valid (the solid is a set of faces connexed by edges with connexity 2). Else, splits faces of the shell; <OldFacesnewFaces> describes (face, splits of face).", py::arg("aSolid"), py::arg("OldSheNewShe"), py::arg("FSplits"));
	cls_TopOpeBRepTool.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepTool_OutCurveType, Standard_OStream &)) &TopOpeBRepTool::Print, "Prints <OCT> as string on stream <S>; returns <S>.", py::arg("OCT"), py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_PShapeClassifier.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_Plos.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_PSoClassif.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<TopOpeBRepTool_IndexedDataMapOfShapeBox, std::unique_ptr<TopOpeBRepTool_IndexedDataMapOfShapeBox, Deleter<TopOpeBRepTool_IndexedDataMapOfShapeBox>>, NCollection_BaseMap> cls_TopOpeBRepTool_IndexedDataMapOfShapeBox(mod, "TopOpeBRepTool_IndexedDataMapOfShapeBox", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def(py::init<>());
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def(py::init([] (const TopOpeBRepTool_IndexedDataMapOfShapeBox &other) {return new TopOpeBRepTool_IndexedDataMapOfShapeBox(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("begin", (TopOpeBRepTool_IndexedDataMapOfShapeBox::iterator (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("end", (TopOpeBRepTool_IndexedDataMapOfShapeBox::iterator (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("cbegin", (TopOpeBRepTool_IndexedDataMapOfShapeBox::const_iterator (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("cend", (TopOpeBRepTool_IndexedDataMapOfShapeBox::const_iterator (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("Exchange", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(TopOpeBRepTool_IndexedDataMapOfShapeBox &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("Assign", (TopOpeBRepTool_IndexedDataMapOfShapeBox & (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const TopOpeBRepTool_IndexedDataMapOfShapeBox &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("assign", (TopOpeBRepTool_IndexedDataMapOfShapeBox & (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const TopOpeBRepTool_IndexedDataMapOfShapeBox &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("ReSize", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("Add", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &, const Bnd_Box &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("Contains", (Standard_Boolean (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::Contains, "Contains", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("Substitute", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const Standard_Integer, const TopoDS_Shape &, const Bnd_Box &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("Swap", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("RemoveLast", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)()) &TopOpeBRepTool_IndexedDataMapOfShapeBox::RemoveLast, "RemoveLast");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("RemoveFromIndex", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("RemoveKey", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("FindKey", (const TopoDS_Shape & (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::FindKey, "FindKey", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("FindFromIndex", (const Bnd_Box & (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("__call__", (const Bnd_Box & (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("ChangeFromIndex", (Bnd_Box & (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("__call__", (Bnd_Box & (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("FindIndex", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("FindFromKey", (const Bnd_Box & (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("ChangeFromKey", (Bnd_Box & (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("Seek", (const Bnd_Box * (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("ChangeSeek", (Bnd_Box * (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("FindFromKey", (Standard_Boolean (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &, Bnd_Box &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("Clear", [](TopOpeBRepTool_IndexedDataMapOfShapeBox &self) -> void { return self.Clear(); });
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("Clear", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const Standard_Boolean)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("Clear", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("Size", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfShapeBox::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox::Size, "Size");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox.def("__iter__", [](const TopOpeBRepTool_IndexedDataMapOfShapeBox &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<TopOpeBRepTool_IndexedDataMapOfShapeBox2d, std::unique_ptr<TopOpeBRepTool_IndexedDataMapOfShapeBox2d, Deleter<TopOpeBRepTool_IndexedDataMapOfShapeBox2d>>, NCollection_BaseMap> cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d(mod, "TopOpeBRepTool_IndexedDataMapOfShapeBox2d", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def(py::init<>());
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def(py::init([] (const TopOpeBRepTool_IndexedDataMapOfShapeBox2d &other) {return new TopOpeBRepTool_IndexedDataMapOfShapeBox2d(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("begin", (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::iterator (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("end", (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::iterator (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("cbegin", (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::const_iterator (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("cend", (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::const_iterator (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("Exchange", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(TopOpeBRepTool_IndexedDataMapOfShapeBox2d &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("Assign", (TopOpeBRepTool_IndexedDataMapOfShapeBox2d & (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const TopOpeBRepTool_IndexedDataMapOfShapeBox2d &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("assign", (TopOpeBRepTool_IndexedDataMapOfShapeBox2d & (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const TopOpeBRepTool_IndexedDataMapOfShapeBox2d &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("ReSize", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("Add", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const TopoDS_Shape &, const Bnd_Box2d &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("Contains", (Standard_Boolean (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::Contains, "Contains", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("Substitute", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const Standard_Integer, const TopoDS_Shape &, const Bnd_Box2d &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("Swap", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("RemoveLast", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)()) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::RemoveLast, "RemoveLast");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("RemoveFromIndex", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("RemoveKey", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("FindKey", (const TopoDS_Shape & (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::FindKey, "FindKey", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("FindFromIndex", (const Bnd_Box2d & (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("__call__", (const Bnd_Box2d & (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("ChangeFromIndex", (Bnd_Box2d & (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("__call__", (Bnd_Box2d & (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("FindIndex", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("FindFromKey", (const Bnd_Box2d & (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("ChangeFromKey", (Bnd_Box2d & (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("Seek", (const Bnd_Box2d * (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("ChangeSeek", (Bnd_Box2d * (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("FindFromKey", (Standard_Boolean (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const TopoDS_Shape &, Bnd_Box2d &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("Clear", [](TopOpeBRepTool_IndexedDataMapOfShapeBox2d &self) -> void { return self.Clear(); });
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("Clear", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const Standard_Boolean)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("Clear", (void (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("Size", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfShapeBox2d::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeBox2d::Size, "Size");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeBox2d.def("__iter__", [](const TopOpeBRepTool_IndexedDataMapOfShapeBox2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepTool_DataMapOfShapeface, std::unique_ptr<TopOpeBRepTool_DataMapOfShapeface, Deleter<TopOpeBRepTool_DataMapOfShapeface>>, NCollection_BaseMap> cls_TopOpeBRepTool_DataMapOfShapeface(mod, "TopOpeBRepTool_DataMapOfShapeface", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepTool_DataMapOfShapeface.def(py::init<>());
	cls_TopOpeBRepTool_DataMapOfShapeface.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def(py::init([] (const TopOpeBRepTool_DataMapOfShapeface &other) {return new TopOpeBRepTool_DataMapOfShapeface(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("begin", (TopOpeBRepTool_DataMapOfShapeface::iterator (TopOpeBRepTool_DataMapOfShapeface::*)() const ) &TopOpeBRepTool_DataMapOfShapeface::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_DataMapOfShapeface.def("end", (TopOpeBRepTool_DataMapOfShapeface::iterator (TopOpeBRepTool_DataMapOfShapeface::*)() const ) &TopOpeBRepTool_DataMapOfShapeface::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_DataMapOfShapeface.def("cbegin", (TopOpeBRepTool_DataMapOfShapeface::const_iterator (TopOpeBRepTool_DataMapOfShapeface::*)() const ) &TopOpeBRepTool_DataMapOfShapeface::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_DataMapOfShapeface.def("cend", (TopOpeBRepTool_DataMapOfShapeface::const_iterator (TopOpeBRepTool_DataMapOfShapeface::*)() const ) &TopOpeBRepTool_DataMapOfShapeface::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_DataMapOfShapeface.def("Exchange", (void (TopOpeBRepTool_DataMapOfShapeface::*)(TopOpeBRepTool_DataMapOfShapeface &)) &TopOpeBRepTool_DataMapOfShapeface::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("Assign", (TopOpeBRepTool_DataMapOfShapeface & (TopOpeBRepTool_DataMapOfShapeface::*)(const TopOpeBRepTool_DataMapOfShapeface &)) &TopOpeBRepTool_DataMapOfShapeface::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("assign", (TopOpeBRepTool_DataMapOfShapeface & (TopOpeBRepTool_DataMapOfShapeface::*)(const TopOpeBRepTool_DataMapOfShapeface &)) &TopOpeBRepTool_DataMapOfShapeface::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("ReSize", (void (TopOpeBRepTool_DataMapOfShapeface::*)(const Standard_Integer)) &TopOpeBRepTool_DataMapOfShapeface::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("Bind", (Standard_Boolean (TopOpeBRepTool_DataMapOfShapeface::*)(const TopoDS_Shape &, const TopOpeBRepTool_face &)) &TopOpeBRepTool_DataMapOfShapeface::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepTool_DataMapOfShapeface.def("Bound", (TopOpeBRepTool_face * (TopOpeBRepTool_DataMapOfShapeface::*)(const TopoDS_Shape &, const TopOpeBRepTool_face &)) &TopOpeBRepTool_DataMapOfShapeface::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("IsBound", (Standard_Boolean (TopOpeBRepTool_DataMapOfShapeface::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfShapeface::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("UnBind", (Standard_Boolean (TopOpeBRepTool_DataMapOfShapeface::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfShapeface::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfShapeface.def("Seek", (const TopOpeBRepTool_face * (TopOpeBRepTool_DataMapOfShapeface::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfShapeface::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfShapeface.def("Find", (const TopOpeBRepTool_face & (TopOpeBRepTool_DataMapOfShapeface::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfShapeface::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfShapeface.def("Find", (Standard_Boolean (TopOpeBRepTool_DataMapOfShapeface::*)(const TopoDS_Shape &, TopOpeBRepTool_face &) const ) &TopOpeBRepTool_DataMapOfShapeface::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("__call__", (const TopOpeBRepTool_face & (TopOpeBRepTool_DataMapOfShapeface::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfShapeface::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfShapeface.def("ChangeSeek", (TopOpeBRepTool_face * (TopOpeBRepTool_DataMapOfShapeface::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfShapeface::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("ChangeFind", (TopOpeBRepTool_face & (TopOpeBRepTool_DataMapOfShapeface::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfShapeface::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("__call__", (TopOpeBRepTool_face & (TopOpeBRepTool_DataMapOfShapeface::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfShapeface::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("Clear", [](TopOpeBRepTool_DataMapOfShapeface &self) -> void { return self.Clear(); });
	cls_TopOpeBRepTool_DataMapOfShapeface.def("Clear", (void (TopOpeBRepTool_DataMapOfShapeface::*)(const Standard_Boolean)) &TopOpeBRepTool_DataMapOfShapeface::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("Clear", (void (TopOpeBRepTool_DataMapOfShapeface::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepTool_DataMapOfShapeface::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepTool_DataMapOfShapeface.def("Size", (Standard_Integer (TopOpeBRepTool_DataMapOfShapeface::*)() const ) &TopOpeBRepTool_DataMapOfShapeface::Size, "Size");
	cls_TopOpeBRepTool_DataMapOfShapeface.def("__iter__", [](const TopOpeBRepTool_DataMapOfShapeface &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_DataMapOfShapeface.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepTool_DataMapOfOrientedShapeC2DF, std::unique_ptr<TopOpeBRepTool_DataMapOfOrientedShapeC2DF, Deleter<TopOpeBRepTool_DataMapOfOrientedShapeC2DF>>, NCollection_BaseMap> cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF(mod, "TopOpeBRepTool_DataMapOfOrientedShapeC2DF", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def(py::init<>());
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def(py::init([] (const TopOpeBRepTool_DataMapOfOrientedShapeC2DF &other) {return new TopOpeBRepTool_DataMapOfOrientedShapeC2DF(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("begin", (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::iterator (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)() const ) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("end", (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::iterator (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)() const ) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("cbegin", (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::const_iterator (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)() const ) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("cend", (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::const_iterator (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)() const ) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("Exchange", (void (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(TopOpeBRepTool_DataMapOfOrientedShapeC2DF &)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("Assign", (TopOpeBRepTool_DataMapOfOrientedShapeC2DF & (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopOpeBRepTool_DataMapOfOrientedShapeC2DF &)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("assign", (TopOpeBRepTool_DataMapOfOrientedShapeC2DF & (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopOpeBRepTool_DataMapOfOrientedShapeC2DF &)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("ReSize", (void (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const Standard_Integer)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("Bind", (Standard_Boolean (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopoDS_Shape &, const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("Bound", (TopOpeBRepTool_C2DF * (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopoDS_Shape &, const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("IsBound", (Standard_Boolean (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("UnBind", (Standard_Boolean (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("Seek", (const TopOpeBRepTool_C2DF * (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("Find", (const TopOpeBRepTool_C2DF & (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("Find", (Standard_Boolean (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopoDS_Shape &, TopOpeBRepTool_C2DF &) const ) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("__call__", (const TopOpeBRepTool_C2DF & (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("ChangeSeek", (TopOpeBRepTool_C2DF * (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("ChangeFind", (TopOpeBRepTool_C2DF & (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("__call__", (TopOpeBRepTool_C2DF & (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("Clear", [](TopOpeBRepTool_DataMapOfOrientedShapeC2DF &self) -> void { return self.Clear(); });
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("Clear", (void (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const Standard_Boolean)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("Clear", (void (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("Size", (Standard_Integer (TopOpeBRepTool_DataMapOfOrientedShapeC2DF::*)() const ) &TopOpeBRepTool_DataMapOfOrientedShapeC2DF::Size, "Size");
	cls_TopOpeBRepTool_DataMapOfOrientedShapeC2DF.def("__iter__", [](const TopOpeBRepTool_DataMapOfOrientedShapeC2DF &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_DataMapOfOrientedShapeC2DF.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TopOpeBRepTool_ListOfC2DF, std::unique_ptr<TopOpeBRepTool_ListOfC2DF, Deleter<TopOpeBRepTool_ListOfC2DF>>, NCollection_BaseList> cls_TopOpeBRepTool_ListOfC2DF(mod, "TopOpeBRepTool_ListOfC2DF", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TopOpeBRepTool_ListOfC2DF.def(py::init<>());
	cls_TopOpeBRepTool_ListOfC2DF.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TopOpeBRepTool_ListOfC2DF.def(py::init([] (const TopOpeBRepTool_ListOfC2DF &other) {return new TopOpeBRepTool_ListOfC2DF(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepTool_ListOfC2DF.def("begin", (TopOpeBRepTool_ListOfC2DF::iterator (TopOpeBRepTool_ListOfC2DF::*)() const ) &TopOpeBRepTool_ListOfC2DF::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TopOpeBRepTool_ListOfC2DF.def("end", (TopOpeBRepTool_ListOfC2DF::iterator (TopOpeBRepTool_ListOfC2DF::*)() const ) &TopOpeBRepTool_ListOfC2DF::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TopOpeBRepTool_ListOfC2DF.def("cbegin", (TopOpeBRepTool_ListOfC2DF::const_iterator (TopOpeBRepTool_ListOfC2DF::*)() const ) &TopOpeBRepTool_ListOfC2DF::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TopOpeBRepTool_ListOfC2DF.def("cend", (TopOpeBRepTool_ListOfC2DF::const_iterator (TopOpeBRepTool_ListOfC2DF::*)() const ) &TopOpeBRepTool_ListOfC2DF::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TopOpeBRepTool_ListOfC2DF.def("Size", (Standard_Integer (TopOpeBRepTool_ListOfC2DF::*)() const ) &TopOpeBRepTool_ListOfC2DF::Size, "Size - Number of items");
	cls_TopOpeBRepTool_ListOfC2DF.def("Assign", (TopOpeBRepTool_ListOfC2DF & (TopOpeBRepTool_ListOfC2DF::*)(const TopOpeBRepTool_ListOfC2DF &)) &TopOpeBRepTool_ListOfC2DF::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepTool_ListOfC2DF.def("assign", (TopOpeBRepTool_ListOfC2DF & (TopOpeBRepTool_ListOfC2DF::*)(const TopOpeBRepTool_ListOfC2DF &)) &TopOpeBRepTool_ListOfC2DF::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TopOpeBRepTool_ListOfC2DF.def("Clear", [](TopOpeBRepTool_ListOfC2DF &self) -> void { return self.Clear(); });
	cls_TopOpeBRepTool_ListOfC2DF.def("Clear", (void (TopOpeBRepTool_ListOfC2DF::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepTool_ListOfC2DF::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TopOpeBRepTool_ListOfC2DF.def("First", (const TopOpeBRepTool_C2DF & (TopOpeBRepTool_ListOfC2DF::*)() const ) &TopOpeBRepTool_ListOfC2DF::First, "First item");
	cls_TopOpeBRepTool_ListOfC2DF.def("First", (TopOpeBRepTool_C2DF & (TopOpeBRepTool_ListOfC2DF::*)()) &TopOpeBRepTool_ListOfC2DF::First, "First item (non-const)");
	cls_TopOpeBRepTool_ListOfC2DF.def("Last", (const TopOpeBRepTool_C2DF & (TopOpeBRepTool_ListOfC2DF::*)() const ) &TopOpeBRepTool_ListOfC2DF::Last, "Last item");
	cls_TopOpeBRepTool_ListOfC2DF.def("Last", (TopOpeBRepTool_C2DF & (TopOpeBRepTool_ListOfC2DF::*)()) &TopOpeBRepTool_ListOfC2DF::Last, "Last item (non-const)");
	cls_TopOpeBRepTool_ListOfC2DF.def("Append", (TopOpeBRepTool_C2DF & (TopOpeBRepTool_ListOfC2DF::*)(const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_ListOfC2DF::Append, "Append one item at the end", py::arg("theItem"));
	cls_TopOpeBRepTool_ListOfC2DF.def("Append", (void (TopOpeBRepTool_ListOfC2DF::*)(const TopOpeBRepTool_C2DF &, TopOpeBRepTool_ListOfC2DF::Iterator &)) &TopOpeBRepTool_ListOfC2DF::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TopOpeBRepTool_ListOfC2DF.def("Append", (void (TopOpeBRepTool_ListOfC2DF::*)(TopOpeBRepTool_ListOfC2DF &)) &TopOpeBRepTool_ListOfC2DF::Append, "Append another list at the end", py::arg("theOther"));
	cls_TopOpeBRepTool_ListOfC2DF.def("Prepend", (TopOpeBRepTool_C2DF & (TopOpeBRepTool_ListOfC2DF::*)(const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_ListOfC2DF::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TopOpeBRepTool_ListOfC2DF.def("Prepend", (void (TopOpeBRepTool_ListOfC2DF::*)(TopOpeBRepTool_ListOfC2DF &)) &TopOpeBRepTool_ListOfC2DF::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TopOpeBRepTool_ListOfC2DF.def("RemoveFirst", (void (TopOpeBRepTool_ListOfC2DF::*)()) &TopOpeBRepTool_ListOfC2DF::RemoveFirst, "RemoveFirst item");
	cls_TopOpeBRepTool_ListOfC2DF.def("Remove", (void (TopOpeBRepTool_ListOfC2DF::*)(TopOpeBRepTool_ListOfC2DF::Iterator &)) &TopOpeBRepTool_ListOfC2DF::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TopOpeBRepTool_ListOfC2DF.def("InsertBefore", (TopOpeBRepTool_C2DF & (TopOpeBRepTool_ListOfC2DF::*)(const TopOpeBRepTool_C2DF &, TopOpeBRepTool_ListOfC2DF::Iterator &)) &TopOpeBRepTool_ListOfC2DF::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TopOpeBRepTool_ListOfC2DF.def("InsertBefore", (void (TopOpeBRepTool_ListOfC2DF::*)(TopOpeBRepTool_ListOfC2DF &, TopOpeBRepTool_ListOfC2DF::Iterator &)) &TopOpeBRepTool_ListOfC2DF::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TopOpeBRepTool_ListOfC2DF.def("InsertAfter", (TopOpeBRepTool_C2DF & (TopOpeBRepTool_ListOfC2DF::*)(const TopOpeBRepTool_C2DF &, TopOpeBRepTool_ListOfC2DF::Iterator &)) &TopOpeBRepTool_ListOfC2DF::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TopOpeBRepTool_ListOfC2DF.def("InsertAfter", (void (TopOpeBRepTool_ListOfC2DF::*)(TopOpeBRepTool_ListOfC2DF &, TopOpeBRepTool_ListOfC2DF::Iterator &)) &TopOpeBRepTool_ListOfC2DF::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TopOpeBRepTool_ListOfC2DF.def("Reverse", (void (TopOpeBRepTool_ListOfC2DF::*)()) &TopOpeBRepTool_ListOfC2DF::Reverse, "Reverse the list");
	cls_TopOpeBRepTool_ListOfC2DF.def("__iter__", [](const TopOpeBRepTool_ListOfC2DF &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TopOpeBRepTool_ListIteratorOfListOfC2DF, std::unique_ptr<TopOpeBRepTool_ListIteratorOfListOfC2DF, Deleter<TopOpeBRepTool_ListIteratorOfListOfC2DF>>> cls_TopOpeBRepTool_ListIteratorOfListOfC2DF(mod, "TopOpeBRepTool_ListIteratorOfListOfC2DF", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TopOpeBRepTool_ListIteratorOfListOfC2DF.def(py::init<>());
	cls_TopOpeBRepTool_ListIteratorOfListOfC2DF.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TopOpeBRepTool_ListIteratorOfListOfC2DF.def("More", (Standard_Boolean (TopOpeBRepTool_ListIteratorOfListOfC2DF::*)() const ) &TopOpeBRepTool_ListIteratorOfListOfC2DF::More, "Check end");
	cls_TopOpeBRepTool_ListIteratorOfListOfC2DF.def("Next", (void (TopOpeBRepTool_ListIteratorOfListOfC2DF::*)()) &TopOpeBRepTool_ListIteratorOfListOfC2DF::Next, "Make step");
	cls_TopOpeBRepTool_ListIteratorOfListOfC2DF.def("Value", (const TopOpeBRepTool_C2DF & (TopOpeBRepTool_ListIteratorOfListOfC2DF::*)() const ) &TopOpeBRepTool_ListIteratorOfListOfC2DF::Value, "Constant Value access");
	cls_TopOpeBRepTool_ListIteratorOfListOfC2DF.def("Value", (TopOpeBRepTool_C2DF & (TopOpeBRepTool_ListIteratorOfListOfC2DF::*)()) &TopOpeBRepTool_ListIteratorOfListOfC2DF::Value, "Non-const Value access");
	cls_TopOpeBRepTool_ListIteratorOfListOfC2DF.def("ChangeValue", (TopOpeBRepTool_C2DF & (TopOpeBRepTool_ListIteratorOfListOfC2DF::*)() const ) &TopOpeBRepTool_ListIteratorOfListOfC2DF::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRepTool_DataMapOfShapeListOfC2DF, std::unique_ptr<TopOpeBRepTool_DataMapOfShapeListOfC2DF, Deleter<TopOpeBRepTool_DataMapOfShapeListOfC2DF>>, NCollection_BaseMap> cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF(mod, "TopOpeBRepTool_DataMapOfShapeListOfC2DF", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def(py::init<>());
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def(py::init([] (const TopOpeBRepTool_DataMapOfShapeListOfC2DF &other) {return new TopOpeBRepTool_DataMapOfShapeListOfC2DF(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("begin", (TopOpeBRepTool_DataMapOfShapeListOfC2DF::iterator (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)() const ) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("end", (TopOpeBRepTool_DataMapOfShapeListOfC2DF::iterator (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)() const ) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("cbegin", (TopOpeBRepTool_DataMapOfShapeListOfC2DF::const_iterator (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)() const ) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("cend", (TopOpeBRepTool_DataMapOfShapeListOfC2DF::const_iterator (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)() const ) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("Exchange", (void (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(TopOpeBRepTool_DataMapOfShapeListOfC2DF &)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("Assign", (TopOpeBRepTool_DataMapOfShapeListOfC2DF & (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopOpeBRepTool_DataMapOfShapeListOfC2DF &)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("assign", (TopOpeBRepTool_DataMapOfShapeListOfC2DF & (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopOpeBRepTool_DataMapOfShapeListOfC2DF &)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("ReSize", (void (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const Standard_Integer)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("Bind", (Standard_Boolean (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopoDS_Shape &, const TopOpeBRepTool_ListOfC2DF &)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("Bound", (TopOpeBRepTool_ListOfC2DF * (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopoDS_Shape &, const TopOpeBRepTool_ListOfC2DF &)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("IsBound", (Standard_Boolean (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("UnBind", (Standard_Boolean (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("Seek", (const TopOpeBRepTool_ListOfC2DF * (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("Find", (const TopOpeBRepTool_ListOfC2DF & (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("Find", (Standard_Boolean (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopoDS_Shape &, TopOpeBRepTool_ListOfC2DF &) const ) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("__call__", (const TopOpeBRepTool_ListOfC2DF & (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("ChangeSeek", (TopOpeBRepTool_ListOfC2DF * (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("ChangeFind", (TopOpeBRepTool_ListOfC2DF & (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("__call__", (TopOpeBRepTool_ListOfC2DF & (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const TopoDS_Shape &)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("Clear", [](TopOpeBRepTool_DataMapOfShapeListOfC2DF &self) -> void { return self.Clear(); });
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("Clear", (void (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const Standard_Boolean)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("Clear", (void (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("Size", (Standard_Integer (TopOpeBRepTool_DataMapOfShapeListOfC2DF::*)() const ) &TopOpeBRepTool_DataMapOfShapeListOfC2DF::Size, "Size");
	cls_TopOpeBRepTool_DataMapOfShapeListOfC2DF.def("__iter__", [](const TopOpeBRepTool_DataMapOfShapeListOfC2DF &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRepTool_DataMapOfShapeListOfC2DF.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<TopOpeBRepTool_IndexedDataMapOfShapeconnexity, std::unique_ptr<TopOpeBRepTool_IndexedDataMapOfShapeconnexity, Deleter<TopOpeBRepTool_IndexedDataMapOfShapeconnexity>>, NCollection_BaseMap> cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity(mod, "TopOpeBRepTool_IndexedDataMapOfShapeconnexity", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def(py::init<>());
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def(py::init([] (const TopOpeBRepTool_IndexedDataMapOfShapeconnexity &other) {return new TopOpeBRepTool_IndexedDataMapOfShapeconnexity(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("begin", (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::iterator (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("end", (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::iterator (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("cbegin", (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::const_iterator (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("cend", (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::const_iterator (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("Exchange", (void (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(TopOpeBRepTool_IndexedDataMapOfShapeconnexity &)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("Assign", (TopOpeBRepTool_IndexedDataMapOfShapeconnexity & (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const TopOpeBRepTool_IndexedDataMapOfShapeconnexity &)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("assign", (TopOpeBRepTool_IndexedDataMapOfShapeconnexity & (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const TopOpeBRepTool_IndexedDataMapOfShapeconnexity &)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("ReSize", (void (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("Add", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const TopoDS_Shape &, const TopOpeBRepTool_connexity &)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("Contains", (Standard_Boolean (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::Contains, "Contains", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("Substitute", (void (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const Standard_Integer, const TopoDS_Shape &, const TopOpeBRepTool_connexity &)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("Swap", (void (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("RemoveLast", (void (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)()) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::RemoveLast, "RemoveLast");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("RemoveFromIndex", (void (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("RemoveKey", (void (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("FindKey", (const TopoDS_Shape & (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::FindKey, "FindKey", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("FindFromIndex", (const TopOpeBRepTool_connexity & (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("__call__", (const TopOpeBRepTool_connexity & (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("ChangeFromIndex", (TopOpeBRepTool_connexity & (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("__call__", (TopOpeBRepTool_connexity & (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("FindIndex", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("FindFromKey", (const TopOpeBRepTool_connexity & (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("ChangeFromKey", (TopOpeBRepTool_connexity & (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("Seek", (const TopOpeBRepTool_connexity * (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("ChangeSeek", (TopOpeBRepTool_connexity * (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("FindFromKey", (Standard_Boolean (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const TopoDS_Shape &, TopOpeBRepTool_connexity &) const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("Clear", [](TopOpeBRepTool_IndexedDataMapOfShapeconnexity &self) -> void { return self.Clear(); });
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("Clear", (void (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const Standard_Boolean)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("Clear", (void (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("Size", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfShapeconnexity::*)() const ) &TopOpeBRepTool_IndexedDataMapOfShapeconnexity::Size, "Size");
	cls_TopOpeBRepTool_IndexedDataMapOfShapeconnexity.def("__iter__", [](const TopOpeBRepTool_IndexedDataMapOfShapeconnexity &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<TopOpeBRepTool_IndexedDataMapOfSolidClassifier, std::unique_ptr<TopOpeBRepTool_IndexedDataMapOfSolidClassifier, Deleter<TopOpeBRepTool_IndexedDataMapOfSolidClassifier>>, NCollection_BaseMap> cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier(mod, "TopOpeBRepTool_IndexedDataMapOfSolidClassifier", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def(py::init<>());
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def(py::init([] (const TopOpeBRepTool_IndexedDataMapOfSolidClassifier &other) {return new TopOpeBRepTool_IndexedDataMapOfSolidClassifier(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("begin", (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::iterator (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)() const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("end", (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::iterator (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)() const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("cbegin", (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::const_iterator (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)() const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("cend", (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::const_iterator (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)() const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("Exchange", (void (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(TopOpeBRepTool_IndexedDataMapOfSolidClassifier &)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("Assign", (TopOpeBRepTool_IndexedDataMapOfSolidClassifier & (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const TopOpeBRepTool_IndexedDataMapOfSolidClassifier &)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("assign", (TopOpeBRepTool_IndexedDataMapOfSolidClassifier & (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const TopOpeBRepTool_IndexedDataMapOfSolidClassifier &)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("ReSize", (void (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("Add", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const TopoDS_Shape &, const BRepClass3d_SolidClassifier &)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("Contains", (Standard_Boolean (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::Contains, "Contains", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("Substitute", (void (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const Standard_Integer, const TopoDS_Shape &, const BRepClass3d_SolidClassifier &)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("Swap", (void (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("RemoveLast", (void (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)()) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::RemoveLast, "RemoveLast");
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("RemoveFromIndex", (void (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("RemoveKey", (void (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("FindKey", (const TopoDS_Shape & (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::FindKey, "FindKey", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("FindFromIndex", (const BRepClass3d_SolidClassifier & (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("__call__", (const BRepClass3d_SolidClassifier & (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const Standard_Integer) const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("ChangeFromIndex", (BRepClass3d_SolidClassifier & (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("__call__", (BRepClass3d_SolidClassifier & (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const Standard_Integer)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("FindIndex", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("FindFromKey", (const BRepClass3d_SolidClassifier & (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("ChangeFromKey", (BRepClass3d_SolidClassifier & (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("Seek", (const BRepClass3d_SolidClassifier * (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const TopoDS_Shape &) const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("ChangeSeek", (BRepClass3d_SolidClassifier * (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("FindFromKey", (Standard_Boolean (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const TopoDS_Shape &, BRepClass3d_SolidClassifier &) const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("Clear", [](TopOpeBRepTool_IndexedDataMapOfSolidClassifier &self) -> void { return self.Clear(); });
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("Clear", (void (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const Standard_Boolean)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("Clear", (void (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("Size", (Standard_Integer (TopOpeBRepTool_IndexedDataMapOfSolidClassifier::*)() const ) &TopOpeBRepTool_IndexedDataMapOfSolidClassifier::Size, "Size");
	cls_TopOpeBRepTool_IndexedDataMapOfSolidClassifier.def("__iter__", [](const TopOpeBRepTool_IndexedDataMapOfSolidClassifier &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	*/


}
