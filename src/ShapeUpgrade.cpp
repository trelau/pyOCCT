#include <pyOCCT_Common.hpp>

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_Tool.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <ShapeUpgrade_SplitCurve2d.hxx>
#include <ShapeUpgrade_SplitCurve3d.hxx>
#include <ShapeUpgrade_EdgeDivide.hxx>
#include <ShapeUpgrade_ClosedEdgeDivide.hxx>
#include <TopoDS_Wire.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeAnalysis_TransferParameters.hxx>
#include <ShapeUpgrade_FixSmallCurves.hxx>
#include <ShapeUpgrade_WireDivide.hxx>
#include <TopoDS_Shape.hxx>
#include <ShapeUpgrade_SplitSurface.hxx>
#include <ShapeUpgrade_FaceDivide.hxx>
#include <ShapeUpgrade_ClosedFaceDivide.hxx>
#include <ShapeUpgrade_FaceDivideArea.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <Message_Msg.hxx>
#include <Message_Gravity.hxx>
#include <ShapeUpgrade_ShapeDivide.hxx>
#include <ShapeUpgrade_ShapeDivideArea.hxx>
#include <GeomAbs_Shape.hxx>
#include <ShapeUpgrade_ShapeDivideContinuity.hxx>
#include <ShapeUpgrade_ShapeDivideAngle.hxx>
#include <ShapeUpgrade_ShapeConvertToBezier.hxx>
#include <ShapeUpgrade_ShapeDivideClosed.hxx>
#include <ShapeUpgrade_ShapeDivideClosedEdges.hxx>
#include <ShapeUpgrade_SplitCurve.hxx>
#include <Geom2d_Curve.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <ShapeUpgrade_SplitCurve2dContinuity.hxx>
#include <ShapeUpgrade_ConvertCurve2dToBezier.hxx>
#include <Geom_Curve.hxx>
#include <TColGeom_HArray1OfCurve.hxx>
#include <ShapeUpgrade_SplitCurve3dContinuity.hxx>
#include <ShapeUpgrade_ConvertCurve3dToBezier.hxx>
#include <ShapeExtend_CompositeSurface.hxx>
#include <ShapeUpgrade_SplitSurfaceContinuity.hxx>
#include <ShapeUpgrade_SplitSurfaceAngle.hxx>
#include <ShapeUpgrade_ConvertSurfaceToBezierBasis.hxx>
#include <ShapeUpgrade_SplitSurfaceArea.hxx>
#include <ShapeUpgrade_ShellSewing.hxx>
#include <ShapeUpgrade_FixSmallBezierCurves.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <ShapeUpgrade_RemoveLocations.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <ShapeUpgrade_RemoveInternalWires.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepTools_History.hxx>
#include <ShapeUpgrade_UnifySameDomain.hxx>
#include <Geom_BSplineCurve.hxx>
#include <TColGeom_HSequenceOfBoundedCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <TColGeom2d_HSequenceOfBoundedCurve.hxx>
#include <ShapeUpgrade.hxx>

PYBIND11_MODULE(ShapeUpgrade, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.ShapeBuild");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.ShapeExtend");
	py::module::import("OCCT.ShapeAnalysis");
	py::module::import("OCCT.Message");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.TColGeom2d");
	py::module::import("OCCT.TColGeom");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.BRepTools");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_Tool.hxx
	py::class_<ShapeUpgrade_Tool, opencascade::handle<ShapeUpgrade_Tool>, Standard_Transient> cls_ShapeUpgrade_Tool(mod, "ShapeUpgrade_Tool", "Tool is a root class for splitting classes Provides context for recording changes, basic precision value and limit (minimal and maximal) values for tolerances");
	cls_ShapeUpgrade_Tool.def(py::init<>());
	cls_ShapeUpgrade_Tool.def("Set", (void (ShapeUpgrade_Tool::*)(const opencascade::handle<ShapeUpgrade_Tool> &)) &ShapeUpgrade_Tool::Set, "Copy all fields from another Root object", py::arg("tool"));
	cls_ShapeUpgrade_Tool.def("SetContext", (void (ShapeUpgrade_Tool::*)(const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeUpgrade_Tool::SetContext, "Sets context", py::arg("context"));
	cls_ShapeUpgrade_Tool.def("Context", (opencascade::handle<ShapeBuild_ReShape> (ShapeUpgrade_Tool::*)() const ) &ShapeUpgrade_Tool::Context, "Returns context");
	cls_ShapeUpgrade_Tool.def("SetPrecision", (void (ShapeUpgrade_Tool::*)(const Standard_Real)) &ShapeUpgrade_Tool::SetPrecision, "Sets basic precision value", py::arg("preci"));
	cls_ShapeUpgrade_Tool.def("Precision", (Standard_Real (ShapeUpgrade_Tool::*)() const ) &ShapeUpgrade_Tool::Precision, "Returns basic precision value");
	cls_ShapeUpgrade_Tool.def("SetMinTolerance", (void (ShapeUpgrade_Tool::*)(const Standard_Real)) &ShapeUpgrade_Tool::SetMinTolerance, "Sets minimal allowed tolerance", py::arg("mintol"));
	cls_ShapeUpgrade_Tool.def("MinTolerance", (Standard_Real (ShapeUpgrade_Tool::*)() const ) &ShapeUpgrade_Tool::MinTolerance, "Returns minimal allowed tolerance");
	cls_ShapeUpgrade_Tool.def("SetMaxTolerance", (void (ShapeUpgrade_Tool::*)(const Standard_Real)) &ShapeUpgrade_Tool::SetMaxTolerance, "Sets maximal allowed tolerance", py::arg("maxtol"));
	cls_ShapeUpgrade_Tool.def("MaxTolerance", (Standard_Real (ShapeUpgrade_Tool::*)() const ) &ShapeUpgrade_Tool::MaxTolerance, "Returns maximal allowed tolerance");
	cls_ShapeUpgrade_Tool.def("LimitTolerance", (Standard_Real (ShapeUpgrade_Tool::*)(const Standard_Real) const ) &ShapeUpgrade_Tool::LimitTolerance, "Returns tolerance limited by [myMinTol,myMaxTol]", py::arg("toler"));
	cls_ShapeUpgrade_Tool.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_Tool::get_type_name, "None");
	cls_ShapeUpgrade_Tool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_Tool::get_type_descriptor, "None");
	cls_ShapeUpgrade_Tool.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_Tool::*)() const ) &ShapeUpgrade_Tool::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_EdgeDivide.hxx
	py::class_<ShapeUpgrade_EdgeDivide, opencascade::handle<ShapeUpgrade_EdgeDivide>, ShapeUpgrade_Tool> cls_ShapeUpgrade_EdgeDivide(mod, "ShapeUpgrade_EdgeDivide", "None");
	cls_ShapeUpgrade_EdgeDivide.def(py::init<>());
	cls_ShapeUpgrade_EdgeDivide.def("Clear", (void (ShapeUpgrade_EdgeDivide::*)()) &ShapeUpgrade_EdgeDivide::Clear, "None");
	cls_ShapeUpgrade_EdgeDivide.def("SetFace", (void (ShapeUpgrade_EdgeDivide::*)(const TopoDS_Face &)) &ShapeUpgrade_EdgeDivide::SetFace, "Sets supporting surface by face", py::arg("F"));
	cls_ShapeUpgrade_EdgeDivide.def("Compute", (Standard_Boolean (ShapeUpgrade_EdgeDivide::*)(const TopoDS_Edge &)) &ShapeUpgrade_EdgeDivide::Compute, "None", py::arg("E"));
	cls_ShapeUpgrade_EdgeDivide.def("HasCurve2d", (Standard_Boolean (ShapeUpgrade_EdgeDivide::*)() const ) &ShapeUpgrade_EdgeDivide::HasCurve2d, "None");
	cls_ShapeUpgrade_EdgeDivide.def("HasCurve3d", (Standard_Boolean (ShapeUpgrade_EdgeDivide::*)() const ) &ShapeUpgrade_EdgeDivide::HasCurve3d, "None");
	cls_ShapeUpgrade_EdgeDivide.def("Knots2d", (opencascade::handle<TColStd_HSequenceOfReal> (ShapeUpgrade_EdgeDivide::*)() const ) &ShapeUpgrade_EdgeDivide::Knots2d, "None");
	cls_ShapeUpgrade_EdgeDivide.def("Knots3d", (opencascade::handle<TColStd_HSequenceOfReal> (ShapeUpgrade_EdgeDivide::*)() const ) &ShapeUpgrade_EdgeDivide::Knots3d, "None");
	cls_ShapeUpgrade_EdgeDivide.def("SetSplitCurve2dTool", (void (ShapeUpgrade_EdgeDivide::*)(const opencascade::handle<ShapeUpgrade_SplitCurve2d> &)) &ShapeUpgrade_EdgeDivide::SetSplitCurve2dTool, "Sets the tool for splitting pcurves.", py::arg("splitCurve2dTool"));
	cls_ShapeUpgrade_EdgeDivide.def("SetSplitCurve3dTool", (void (ShapeUpgrade_EdgeDivide::*)(const opencascade::handle<ShapeUpgrade_SplitCurve3d> &)) &ShapeUpgrade_EdgeDivide::SetSplitCurve3dTool, "Sets the tool for splitting 3D curves.", py::arg("splitCurve3dTool"));
	cls_ShapeUpgrade_EdgeDivide.def("GetSplitCurve2dTool", (opencascade::handle<ShapeUpgrade_SplitCurve2d> (ShapeUpgrade_EdgeDivide::*)() const ) &ShapeUpgrade_EdgeDivide::GetSplitCurve2dTool, "Returns the tool for splitting pcurves.");
	cls_ShapeUpgrade_EdgeDivide.def("GetSplitCurve3dTool", (opencascade::handle<ShapeUpgrade_SplitCurve3d> (ShapeUpgrade_EdgeDivide::*)() const ) &ShapeUpgrade_EdgeDivide::GetSplitCurve3dTool, "Returns the tool for splitting 3D curves.");
	cls_ShapeUpgrade_EdgeDivide.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_EdgeDivide::get_type_name, "None");
	cls_ShapeUpgrade_EdgeDivide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_EdgeDivide::get_type_descriptor, "None");
	cls_ShapeUpgrade_EdgeDivide.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_EdgeDivide::*)() const ) &ShapeUpgrade_EdgeDivide::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ClosedEdgeDivide.hxx
	py::class_<ShapeUpgrade_ClosedEdgeDivide, opencascade::handle<ShapeUpgrade_ClosedEdgeDivide>, ShapeUpgrade_EdgeDivide> cls_ShapeUpgrade_ClosedEdgeDivide(mod, "ShapeUpgrade_ClosedEdgeDivide", "None");
	cls_ShapeUpgrade_ClosedEdgeDivide.def(py::init<>());
	cls_ShapeUpgrade_ClosedEdgeDivide.def("Compute", (Standard_Boolean (ShapeUpgrade_ClosedEdgeDivide::*)(const TopoDS_Edge &)) &ShapeUpgrade_ClosedEdgeDivide::Compute, "None", py::arg("anEdge"));
	cls_ShapeUpgrade_ClosedEdgeDivide.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_ClosedEdgeDivide::get_type_name, "None");
	cls_ShapeUpgrade_ClosedEdgeDivide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_ClosedEdgeDivide::get_type_descriptor, "None");
	cls_ShapeUpgrade_ClosedEdgeDivide.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_ClosedEdgeDivide::*)() const ) &ShapeUpgrade_ClosedEdgeDivide::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_WireDivide.hxx
	py::class_<ShapeUpgrade_WireDivide, opencascade::handle<ShapeUpgrade_WireDivide>, ShapeUpgrade_Tool> cls_ShapeUpgrade_WireDivide(mod, "ShapeUpgrade_WireDivide", "Divides edges in the wire lying on the face or free wires or free edges with a criterion. Splits 3D curve and pcurve(s) of the edge on the face. Other pcurves which may be associated with the edge are simply copied. If 3D curve is splitted then pcurve on the face is splitted as well, and wice-versa. Input shape is not modified. The modifications made are recorded in external context (ShapeBuild_ReShape). This tool is applied to all edges before splitting them in order to keep sharing.");
	cls_ShapeUpgrade_WireDivide.def(py::init<>());
	cls_ShapeUpgrade_WireDivide.def("Init", (void (ShapeUpgrade_WireDivide::*)(const TopoDS_Wire &, const TopoDS_Face &)) &ShapeUpgrade_WireDivide::Init, "Initializes by wire and face", py::arg("W"), py::arg("F"));
	cls_ShapeUpgrade_WireDivide.def("Init", (void (ShapeUpgrade_WireDivide::*)(const TopoDS_Wire &, const opencascade::handle<Geom_Surface> &)) &ShapeUpgrade_WireDivide::Init, "Initializes by wire and surface", py::arg("W"), py::arg("S"));
	cls_ShapeUpgrade_WireDivide.def("Load", (void (ShapeUpgrade_WireDivide::*)(const TopoDS_Wire &)) &ShapeUpgrade_WireDivide::Load, "Loads working wire", py::arg("W"));
	cls_ShapeUpgrade_WireDivide.def("Load", (void (ShapeUpgrade_WireDivide::*)(const TopoDS_Edge &)) &ShapeUpgrade_WireDivide::Load, "Creates wire of one edge and calls Load for wire", py::arg("E"));
	cls_ShapeUpgrade_WireDivide.def("SetFace", (void (ShapeUpgrade_WireDivide::*)(const TopoDS_Face &)) &ShapeUpgrade_WireDivide::SetFace, "Sets supporting surface by face", py::arg("F"));
	cls_ShapeUpgrade_WireDivide.def("SetSurface", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<Geom_Surface> &)) &ShapeUpgrade_WireDivide::SetSurface, "Sets supporting surface", py::arg("S"));
	cls_ShapeUpgrade_WireDivide.def("SetSurface", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &ShapeUpgrade_WireDivide::SetSurface, "Sets supporting surface with location", py::arg("S"), py::arg("L"));
	cls_ShapeUpgrade_WireDivide.def("Perform", (void (ShapeUpgrade_WireDivide::*)()) &ShapeUpgrade_WireDivide::Perform, "Computes the resulting wire by splitting all the edges according to splitting criteria. All the modifications made are recorded in context (ShapeBuild_ReShape). This tool is applied to all edges before splitting them in order to keep sharings. If no supporting face or surface is defined, only 3d splitting criteria are used.");
	cls_ShapeUpgrade_WireDivide.def("Wire", (const TopoDS_Wire & (ShapeUpgrade_WireDivide::*)() const ) &ShapeUpgrade_WireDivide::Wire, "Gives the resulting Wire (equal to initial one if not done or Null if not loaded)");
	cls_ShapeUpgrade_WireDivide.def("Status", (Standard_Boolean (ShapeUpgrade_WireDivide::*)(const ShapeExtend_Status) const ) &ShapeUpgrade_WireDivide::Status, "Queries status of last call to Perform() OK - no edges were splitted, wire left untouched DONE1 - some edges were splitted FAIL1 - some edges have no 3d curve (skipped) FAIL2 - some edges have no pcurve (skipped)", py::arg("status"));
	cls_ShapeUpgrade_WireDivide.def("SetSplitCurve3dTool", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<ShapeUpgrade_SplitCurve3d> &)) &ShapeUpgrade_WireDivide::SetSplitCurve3dTool, "Sets the tool for splitting 3D curves.", py::arg("splitCurve3dTool"));
	cls_ShapeUpgrade_WireDivide.def("SetSplitCurve2dTool", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<ShapeUpgrade_SplitCurve2d> &)) &ShapeUpgrade_WireDivide::SetSplitCurve2dTool, "Sets the tool for splitting pcurves.", py::arg("splitCurve2dTool"));
	cls_ShapeUpgrade_WireDivide.def("SetTransferParamTool", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<ShapeAnalysis_TransferParameters> &)) &ShapeUpgrade_WireDivide::SetTransferParamTool, "Sets the tool for Transfer parameters between curves and pcurves.", py::arg("TransferParam"));
	cls_ShapeUpgrade_WireDivide.def("SetEdgeDivideTool", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<ShapeUpgrade_EdgeDivide> &)) &ShapeUpgrade_WireDivide::SetEdgeDivideTool, "Sets tool for splitting edge", py::arg("edgeDivideTool"));
	cls_ShapeUpgrade_WireDivide.def("GetEdgeDivideTool", (opencascade::handle<ShapeUpgrade_EdgeDivide> (ShapeUpgrade_WireDivide::*)() const ) &ShapeUpgrade_WireDivide::GetEdgeDivideTool, "returns tool for splitting edges");
	cls_ShapeUpgrade_WireDivide.def("GetTransferParamTool", (opencascade::handle<ShapeAnalysis_TransferParameters> (ShapeUpgrade_WireDivide::*)()) &ShapeUpgrade_WireDivide::GetTransferParamTool, "Returns the tool for Transfer of parameters.");
	cls_ShapeUpgrade_WireDivide.def("SetEdgeMode", (void (ShapeUpgrade_WireDivide::*)(const Standard_Integer)) &ShapeUpgrade_WireDivide::SetEdgeMode, "Sets mode for splitting 3d curves from edges. 0 - only curve 3d from free edges. 1 - only curve 3d from shared edges. 2 - all curve 3d.", py::arg("EdgeMode"));
	cls_ShapeUpgrade_WireDivide.def("SetFixSmallCurveTool", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<ShapeUpgrade_FixSmallCurves> &)) &ShapeUpgrade_WireDivide::SetFixSmallCurveTool, "Sets tool for fixing small curves with specified min tolerance;", py::arg("FixSmallCurvesTool"));
	cls_ShapeUpgrade_WireDivide.def("GetFixSmallCurveTool", (opencascade::handle<ShapeUpgrade_FixSmallCurves> (ShapeUpgrade_WireDivide::*)() const ) &ShapeUpgrade_WireDivide::GetFixSmallCurveTool, "Returns tool for fixing small curves");
	cls_ShapeUpgrade_WireDivide.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_WireDivide::get_type_name, "None");
	cls_ShapeUpgrade_WireDivide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_WireDivide::get_type_descriptor, "None");
	cls_ShapeUpgrade_WireDivide.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_WireDivide::*)() const ) &ShapeUpgrade_WireDivide::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_FaceDivide.hxx
	py::class_<ShapeUpgrade_FaceDivide, opencascade::handle<ShapeUpgrade_FaceDivide>, ShapeUpgrade_Tool> cls_ShapeUpgrade_FaceDivide(mod, "ShapeUpgrade_FaceDivide", "Divides a Face (both edges in the wires, by splitting curves and pcurves, and the face itself, by splitting supporting surface) according to splitting criteria. * The domain of the face to divide is defined by the PCurves of the wires on the Face.");
	cls_ShapeUpgrade_FaceDivide.def(py::init<>());
	cls_ShapeUpgrade_FaceDivide.def(py::init<const TopoDS_Face &>(), py::arg("F"));
	cls_ShapeUpgrade_FaceDivide.def("Init", (void (ShapeUpgrade_FaceDivide::*)(const TopoDS_Face &)) &ShapeUpgrade_FaceDivide::Init, "Initialize by a Face.", py::arg("F"));
	cls_ShapeUpgrade_FaceDivide.def("SetSurfaceSegmentMode", (void (ShapeUpgrade_FaceDivide::*)(const Standard_Boolean)) &ShapeUpgrade_FaceDivide::SetSurfaceSegmentMode, "Purpose sets mode for trimming (segment) surface by wire UV bounds.", py::arg("Segment"));
	cls_ShapeUpgrade_FaceDivide.def("Perform", (Standard_Boolean (ShapeUpgrade_FaceDivide::*)()) &ShapeUpgrade_FaceDivide::Perform, "Performs splitting and computes the resulting shell The context is used to keep track of former splittings in order to keep sharings. It is updated according to modifications made.");
	cls_ShapeUpgrade_FaceDivide.def("SplitSurface", (Standard_Boolean (ShapeUpgrade_FaceDivide::*)()) &ShapeUpgrade_FaceDivide::SplitSurface, "Performs splitting of surface and computes the shell from source face.");
	cls_ShapeUpgrade_FaceDivide.def("SplitCurves", (Standard_Boolean (ShapeUpgrade_FaceDivide::*)()) &ShapeUpgrade_FaceDivide::SplitCurves, "Performs splitting of curves of all the edges in the shape and divides these edges.");
	cls_ShapeUpgrade_FaceDivide.def("Result", (TopoDS_Shape (ShapeUpgrade_FaceDivide::*)() const ) &ShapeUpgrade_FaceDivide::Result, "Gives the resulting Shell, or Face, or Null shape if not done.");
	cls_ShapeUpgrade_FaceDivide.def("Status", (Standard_Boolean (ShapeUpgrade_FaceDivide::*)(const ShapeExtend_Status) const ) &ShapeUpgrade_FaceDivide::Status, "Queries the status of last call to Perform OK : no splitting was done (or no call to Perform) DONE1: some edges were splitted DONE2: surface was splitted DONE3: surface was modified without splitting FAIL1: some fails encountered during splitting wires FAIL2: face cannot be splitted", py::arg("status"));
	cls_ShapeUpgrade_FaceDivide.def("SetSplitSurfaceTool", (void (ShapeUpgrade_FaceDivide::*)(const opencascade::handle<ShapeUpgrade_SplitSurface> &)) &ShapeUpgrade_FaceDivide::SetSplitSurfaceTool, "Sets the tool for splitting surfaces.", py::arg("splitSurfaceTool"));
	cls_ShapeUpgrade_FaceDivide.def("SetWireDivideTool", (void (ShapeUpgrade_FaceDivide::*)(const opencascade::handle<ShapeUpgrade_WireDivide> &)) &ShapeUpgrade_FaceDivide::SetWireDivideTool, "Sets the tool for dividing edges on Face.", py::arg("wireDivideTool"));
	cls_ShapeUpgrade_FaceDivide.def("GetSplitSurfaceTool", (opencascade::handle<ShapeUpgrade_SplitSurface> (ShapeUpgrade_FaceDivide::*)() const ) &ShapeUpgrade_FaceDivide::GetSplitSurfaceTool, "Returns the tool for splitting surfaces. This tool must be already initialized.");
	cls_ShapeUpgrade_FaceDivide.def("GetWireDivideTool", (opencascade::handle<ShapeUpgrade_WireDivide> (ShapeUpgrade_FaceDivide::*)() const ) &ShapeUpgrade_FaceDivide::GetWireDivideTool, "Returns the tool for dividing edges on Face. This tool must be already initialized.");
	cls_ShapeUpgrade_FaceDivide.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_FaceDivide::get_type_name, "None");
	cls_ShapeUpgrade_FaceDivide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_FaceDivide::get_type_descriptor, "None");
	cls_ShapeUpgrade_FaceDivide.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_FaceDivide::*)() const ) &ShapeUpgrade_FaceDivide::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ClosedFaceDivide.hxx
	py::class_<ShapeUpgrade_ClosedFaceDivide, opencascade::handle<ShapeUpgrade_ClosedFaceDivide>, ShapeUpgrade_FaceDivide> cls_ShapeUpgrade_ClosedFaceDivide(mod, "ShapeUpgrade_ClosedFaceDivide", "Divides a Face with one or more seam edge to avoid closed faces. Splitting is performed by U and V direction. The number of resulting faces can be defined by user.");
	cls_ShapeUpgrade_ClosedFaceDivide.def(py::init<>());
	cls_ShapeUpgrade_ClosedFaceDivide.def(py::init<const TopoDS_Face &>(), py::arg("F"));
	cls_ShapeUpgrade_ClosedFaceDivide.def("SplitSurface", (Standard_Boolean (ShapeUpgrade_ClosedFaceDivide::*)()) &ShapeUpgrade_ClosedFaceDivide::SplitSurface, "Performs splitting of surface and computes the shell from source face.");
	cls_ShapeUpgrade_ClosedFaceDivide.def("SetNbSplitPoints", (void (ShapeUpgrade_ClosedFaceDivide::*)(const Standard_Integer)) &ShapeUpgrade_ClosedFaceDivide::SetNbSplitPoints, "Sets the number of cutting lines by which closed face will be splitted. The resulting faces will be num+1.", py::arg("num"));
	cls_ShapeUpgrade_ClosedFaceDivide.def("GetNbSplitPoints", (Standard_Integer (ShapeUpgrade_ClosedFaceDivide::*)() const ) &ShapeUpgrade_ClosedFaceDivide::GetNbSplitPoints, "Returns the number of splitting points");
	cls_ShapeUpgrade_ClosedFaceDivide.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_ClosedFaceDivide::get_type_name, "None");
	cls_ShapeUpgrade_ClosedFaceDivide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_ClosedFaceDivide::get_type_descriptor, "None");
	cls_ShapeUpgrade_ClosedFaceDivide.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_ClosedFaceDivide::*)() const ) &ShapeUpgrade_ClosedFaceDivide::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_FaceDivideArea.hxx
	py::class_<ShapeUpgrade_FaceDivideArea, opencascade::handle<ShapeUpgrade_FaceDivideArea>, ShapeUpgrade_FaceDivide> cls_ShapeUpgrade_FaceDivideArea(mod, "ShapeUpgrade_FaceDivideArea", "Divides face by max area criterium.");
	cls_ShapeUpgrade_FaceDivideArea.def(py::init<>());
	cls_ShapeUpgrade_FaceDivideArea.def(py::init<const TopoDS_Face &>(), py::arg("F"));
	cls_ShapeUpgrade_FaceDivideArea.def("Perform", (Standard_Boolean (ShapeUpgrade_FaceDivideArea::*)()) &ShapeUpgrade_FaceDivideArea::Perform, "Performs splitting and computes the resulting shell The context is used to keep track of former splittings");
	cls_ShapeUpgrade_FaceDivideArea.def("MaxArea", (Standard_Real & (ShapeUpgrade_FaceDivideArea::*)()) &ShapeUpgrade_FaceDivideArea::MaxArea, "Set max area allowed for faces");
	cls_ShapeUpgrade_FaceDivideArea.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_FaceDivideArea::get_type_name, "None");
	cls_ShapeUpgrade_FaceDivideArea.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_FaceDivideArea::get_type_descriptor, "None");
	cls_ShapeUpgrade_FaceDivideArea.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_FaceDivideArea::*)() const ) &ShapeUpgrade_FaceDivideArea::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ShapeDivide.hxx
	py::class_<ShapeUpgrade_ShapeDivide, std::unique_ptr<ShapeUpgrade_ShapeDivide, Deleter<ShapeUpgrade_ShapeDivide>>> cls_ShapeUpgrade_ShapeDivide(mod, "ShapeUpgrade_ShapeDivide", "Divides a all faces in shell with given criteria Shell.");
	cls_ShapeUpgrade_ShapeDivide.def(py::init<>());
	cls_ShapeUpgrade_ShapeDivide.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_ShapeUpgrade_ShapeDivide.def("Init", (void (ShapeUpgrade_ShapeDivide::*)(const TopoDS_Shape &)) &ShapeUpgrade_ShapeDivide::Init, "Initialize by a Shape.", py::arg("S"));
	cls_ShapeUpgrade_ShapeDivide.def("SetPrecision", (void (ShapeUpgrade_ShapeDivide::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivide::SetPrecision, "Defines the spatial precision used for splitting", py::arg("Prec"));
	cls_ShapeUpgrade_ShapeDivide.def("SetMaxTolerance", (void (ShapeUpgrade_ShapeDivide::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivide::SetMaxTolerance, "Sets maximal allowed tolerance", py::arg("maxtol"));
	cls_ShapeUpgrade_ShapeDivide.def("SetMinTolerance", (void (ShapeUpgrade_ShapeDivide::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivide::SetMinTolerance, "Sets minimal allowed tolerance", py::arg("mintol"));
	cls_ShapeUpgrade_ShapeDivide.def("SetSurfaceSegmentMode", (void (ShapeUpgrade_ShapeDivide::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeDivide::SetSurfaceSegmentMode, "Purpose sets mode for trimming (segment) surface by wire UV bounds.", py::arg("Segment"));
	cls_ShapeUpgrade_ShapeDivide.def("Perform", [](ShapeUpgrade_ShapeDivide &self) -> Standard_Boolean { return self.Perform(); });
	cls_ShapeUpgrade_ShapeDivide.def("Perform", (Standard_Boolean (ShapeUpgrade_ShapeDivide::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeDivide::Perform, "Performs splitting and computes the resulting shape If newContext is True (default), the internal context will be cleared at start, else previous substitutions will be acting.", py::arg("newContext"));
	cls_ShapeUpgrade_ShapeDivide.def("Result", (TopoDS_Shape (ShapeUpgrade_ShapeDivide::*)() const ) &ShapeUpgrade_ShapeDivide::Result, "Gives the resulting Shape, or Null shape if not done.");
	cls_ShapeUpgrade_ShapeDivide.def("GetContext", (opencascade::handle<ShapeBuild_ReShape> (ShapeUpgrade_ShapeDivide::*)() const ) &ShapeUpgrade_ShapeDivide::GetContext, "Returns context with all the modifications made during last call(s) to Perform() recorded");
	cls_ShapeUpgrade_ShapeDivide.def("SetContext", (void (ShapeUpgrade_ShapeDivide::*)(const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeUpgrade_ShapeDivide::SetContext, "Sets context with recorded modifications to be applied during next call(s) to Perform(shape,Standard_False)", py::arg("context"));
	cls_ShapeUpgrade_ShapeDivide.def("SetMsgRegistrator", (void (ShapeUpgrade_ShapeDivide::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeUpgrade_ShapeDivide::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
	cls_ShapeUpgrade_ShapeDivide.def("MsgRegistrator", (opencascade::handle<ShapeExtend_BasicMsgRegistrator> (ShapeUpgrade_ShapeDivide::*)() const ) &ShapeUpgrade_ShapeDivide::MsgRegistrator, "Returns message registrator");
	cls_ShapeUpgrade_ShapeDivide.def("SendMsg", [](ShapeUpgrade_ShapeDivide &self, const TopoDS_Shape & a0, const Message_Msg & a1) -> void { return self.SendMsg(a0, a1); }, py::arg("shape"), py::arg("message"));
	cls_ShapeUpgrade_ShapeDivide.def("SendMsg", (void (ShapeUpgrade_ShapeDivide::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity) const ) &ShapeUpgrade_ShapeDivide::SendMsg, "Sends a message to be attached to the shape. Calls corresponding message of message registrator.", py::arg("shape"), py::arg("message"), py::arg("gravity"));
	cls_ShapeUpgrade_ShapeDivide.def("Status", (Standard_Boolean (ShapeUpgrade_ShapeDivide::*)(const ShapeExtend_Status) const ) &ShapeUpgrade_ShapeDivide::Status, "Queries the status of last call to Perform OK : no splitting was done (or no call to Perform) DONE1: some edges were splitted DONE2: surface was splitted FAIL1: some errors occured", py::arg("status"));
	cls_ShapeUpgrade_ShapeDivide.def("SetSplitFaceTool", (void (ShapeUpgrade_ShapeDivide::*)(const opencascade::handle<ShapeUpgrade_FaceDivide> &)) &ShapeUpgrade_ShapeDivide::SetSplitFaceTool, "Sets the tool for splitting faces.", py::arg("splitFaceTool"));
	cls_ShapeUpgrade_ShapeDivide.def("SetEdgeMode", (void (ShapeUpgrade_ShapeDivide::*)(const Standard_Integer)) &ShapeUpgrade_ShapeDivide::SetEdgeMode, "Sets mode for splitting 3d curves from edges. 0 - only curve 3d from free edges. 1 - only curve 3d from shared edges. 2 - all curve 3d.", py::arg("aEdgeMode"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ShapeDivideArea.hxx
	py::class_<ShapeUpgrade_ShapeDivideArea, std::unique_ptr<ShapeUpgrade_ShapeDivideArea, Deleter<ShapeUpgrade_ShapeDivideArea>>, ShapeUpgrade_ShapeDivide> cls_ShapeUpgrade_ShapeDivideArea(mod, "ShapeUpgrade_ShapeDivideArea", "Divides faces from sprcified shape by max area criterium.");
	cls_ShapeUpgrade_ShapeDivideArea.def(py::init<>());
	cls_ShapeUpgrade_ShapeDivideArea.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_ShapeUpgrade_ShapeDivideArea.def("MaxArea", (Standard_Real & (ShapeUpgrade_ShapeDivideArea::*)()) &ShapeUpgrade_ShapeDivideArea::MaxArea, "Set max area allowed for faces");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ShapeDivideContinuity.hxx
	py::class_<ShapeUpgrade_ShapeDivideContinuity, std::unique_ptr<ShapeUpgrade_ShapeDivideContinuity, Deleter<ShapeUpgrade_ShapeDivideContinuity>>, ShapeUpgrade_ShapeDivide> cls_ShapeUpgrade_ShapeDivideContinuity(mod, "ShapeUpgrade_ShapeDivideContinuity", "API Tool for converting shapes with C0 geometry into C1 ones");
	cls_ShapeUpgrade_ShapeDivideContinuity.def(py::init<>());
	cls_ShapeUpgrade_ShapeDivideContinuity.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_ShapeUpgrade_ShapeDivideContinuity.def("SetTolerance", (void (ShapeUpgrade_ShapeDivideContinuity::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivideContinuity::SetTolerance, "Sets tolerance.", py::arg("Tol"));
	cls_ShapeUpgrade_ShapeDivideContinuity.def("SetTolerance2d", (void (ShapeUpgrade_ShapeDivideContinuity::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivideContinuity::SetTolerance2d, "Sets tolerance.", py::arg("Tol"));
	cls_ShapeUpgrade_ShapeDivideContinuity.def("SetBoundaryCriterion", [](ShapeUpgrade_ShapeDivideContinuity &self) -> void { return self.SetBoundaryCriterion(); });
	cls_ShapeUpgrade_ShapeDivideContinuity.def("SetBoundaryCriterion", (void (ShapeUpgrade_ShapeDivideContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_ShapeDivideContinuity::SetBoundaryCriterion, "Defines a criterion of continuity for the boundary (all the Wires)", py::arg("Criterion"));
	cls_ShapeUpgrade_ShapeDivideContinuity.def("SetPCurveCriterion", [](ShapeUpgrade_ShapeDivideContinuity &self) -> void { return self.SetPCurveCriterion(); });
	cls_ShapeUpgrade_ShapeDivideContinuity.def("SetPCurveCriterion", (void (ShapeUpgrade_ShapeDivideContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_ShapeDivideContinuity::SetPCurveCriterion, "Defines a criterion of continuity for the boundary (all the pcurves of Wires)", py::arg("Criterion"));
	cls_ShapeUpgrade_ShapeDivideContinuity.def("SetSurfaceCriterion", [](ShapeUpgrade_ShapeDivideContinuity &self) -> void { return self.SetSurfaceCriterion(); });
	cls_ShapeUpgrade_ShapeDivideContinuity.def("SetSurfaceCriterion", (void (ShapeUpgrade_ShapeDivideContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_ShapeDivideContinuity::SetSurfaceCriterion, "Defines a criterion of continuity for the boundary (all the Wires)", py::arg("Criterion"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ShapeDivideAngle.hxx
	py::class_<ShapeUpgrade_ShapeDivideAngle, std::unique_ptr<ShapeUpgrade_ShapeDivideAngle, Deleter<ShapeUpgrade_ShapeDivideAngle>>, ShapeUpgrade_ShapeDivide> cls_ShapeUpgrade_ShapeDivideAngle(mod, "ShapeUpgrade_ShapeDivideAngle", "Splits all surfaces of revolution, cylindrical, toroidal, conical, spherical surfaces in the given shape so that each resulting segment covers not more than defined number of degrees (to segments less than 90).");
	cls_ShapeUpgrade_ShapeDivideAngle.def(py::init<const Standard_Real>(), py::arg("MaxAngle"));
	cls_ShapeUpgrade_ShapeDivideAngle.def(py::init<const Standard_Real, const TopoDS_Shape &>(), py::arg("MaxAngle"), py::arg("S"));
	cls_ShapeUpgrade_ShapeDivideAngle.def("InitTool", (void (ShapeUpgrade_ShapeDivideAngle::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivideAngle::InitTool, "Resets tool for splitting face with given angle", py::arg("MaxAngle"));
	cls_ShapeUpgrade_ShapeDivideAngle.def("SetMaxAngle", (void (ShapeUpgrade_ShapeDivideAngle::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivideAngle::SetMaxAngle, "Set maximal angle (calls InitTool)", py::arg("MaxAngle"));
	cls_ShapeUpgrade_ShapeDivideAngle.def("MaxAngle", (Standard_Real (ShapeUpgrade_ShapeDivideAngle::*)() const ) &ShapeUpgrade_ShapeDivideAngle::MaxAngle, "Returns maximal angle");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ShapeConvertToBezier.hxx
	py::class_<ShapeUpgrade_ShapeConvertToBezier, std::unique_ptr<ShapeUpgrade_ShapeConvertToBezier, Deleter<ShapeUpgrade_ShapeConvertToBezier>>, ShapeUpgrade_ShapeDivide> cls_ShapeUpgrade_ShapeConvertToBezier(mod, "ShapeUpgrade_ShapeConvertToBezier", "API class for performing conversion of 3D, 2D curves to bezier curves and surfaces to bezier based surfaces ( bezier surface, surface of revolution based on bezier curve, offset surface based on any previous type).");
	cls_ShapeUpgrade_ShapeConvertToBezier.def(py::init<>());
	cls_ShapeUpgrade_ShapeConvertToBezier.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Set2dConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Set2dConversion, "Sets mode for conversion 2D curves to bezier.", py::arg("mode"));
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Get2dConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const ) &ShapeUpgrade_ShapeConvertToBezier::Get2dConversion, "Returns the 2D conversion mode.");
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Set3dConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Set3dConversion, "Sets mode for conversion 3d curves to bezier.", py::arg("mode"));
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Get3dConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const ) &ShapeUpgrade_ShapeConvertToBezier::Get3dConversion, "Returns the 3D conversion mode.");
	cls_ShapeUpgrade_ShapeConvertToBezier.def("SetSurfaceConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::SetSurfaceConversion, "Sets mode for conversion surfaces curves to bezier basis.", py::arg("mode"));
	cls_ShapeUpgrade_ShapeConvertToBezier.def("GetSurfaceConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const ) &ShapeUpgrade_ShapeConvertToBezier::GetSurfaceConversion, "Returns the surface conversion mode.");
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Set3dLineConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Set3dLineConversion, "Sets mode for conversion Geom_Line to bezier.", py::arg("mode"));
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Get3dLineConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const ) &ShapeUpgrade_ShapeConvertToBezier::Get3dLineConversion, "Returns the Geom_Line conversion mode.");
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Set3dCircleConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Set3dCircleConversion, "Sets mode for conversion Geom_Circle to bezier.", py::arg("mode"));
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Get3dCircleConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const ) &ShapeUpgrade_ShapeConvertToBezier::Get3dCircleConversion, "Returns the Geom_Circle conversion mode.");
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Set3dConicConversion", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Set3dConicConversion, "Sets mode for conversion Geom_Conic to bezier.", py::arg("mode"));
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Get3dConicConversion", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const ) &ShapeUpgrade_ShapeConvertToBezier::Get3dConicConversion, "Returns the Geom_Conic conversion mode.");
	cls_ShapeUpgrade_ShapeConvertToBezier.def("SetPlaneMode", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::SetPlaneMode, "Sets mode for conversion Geom_Plane to Bezier", py::arg("mode"));
	cls_ShapeUpgrade_ShapeConvertToBezier.def("GetPlaneMode", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const ) &ShapeUpgrade_ShapeConvertToBezier::GetPlaneMode, "Returns the Geom_Pline conversion mode.");
	cls_ShapeUpgrade_ShapeConvertToBezier.def("SetRevolutionMode", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::SetRevolutionMode, "Sets mode for conversion Geom_SurfaceOfRevolution to Bezier", py::arg("mode"));
	cls_ShapeUpgrade_ShapeConvertToBezier.def("GetRevolutionMode", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const ) &ShapeUpgrade_ShapeConvertToBezier::GetRevolutionMode, "Returns the Geom_SurfaceOfRevolution conversion mode.");
	cls_ShapeUpgrade_ShapeConvertToBezier.def("SetExtrusionMode", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::SetExtrusionMode, "Sets mode for conversion Geom_SurfaceOfLinearExtrusion to Bezier", py::arg("mode"));
	cls_ShapeUpgrade_ShapeConvertToBezier.def("GetExtrusionMode", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const ) &ShapeUpgrade_ShapeConvertToBezier::GetExtrusionMode, "Returns the Geom_SurfaceOfLinearExtrusion conversion mode.");
	cls_ShapeUpgrade_ShapeConvertToBezier.def("SetBSplineMode", (void (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::SetBSplineMode, "Sets mode for conversion Geom_BSplineSurface to Bezier", py::arg("mode"));
	cls_ShapeUpgrade_ShapeConvertToBezier.def("GetBSplineMode", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)() const ) &ShapeUpgrade_ShapeConvertToBezier::GetBSplineMode, "Returns the Geom_BSplineSurface conversion mode.");
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Perform", [](ShapeUpgrade_ShapeConvertToBezier &self) -> Standard_Boolean { return self.Perform(); });
	cls_ShapeUpgrade_ShapeConvertToBezier.def("Perform", (Standard_Boolean (ShapeUpgrade_ShapeConvertToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeConvertToBezier::Perform, "Performs converting and computes the resulting shape", py::arg("newContext"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ShapeDivideClosed.hxx
	py::class_<ShapeUpgrade_ShapeDivideClosed, std::unique_ptr<ShapeUpgrade_ShapeDivideClosed, Deleter<ShapeUpgrade_ShapeDivideClosed>>, ShapeUpgrade_ShapeDivide> cls_ShapeUpgrade_ShapeDivideClosed(mod, "ShapeUpgrade_ShapeDivideClosed", "Divides all closed faces in the shape. Class ShapeUpgrade_ClosedFaceDivide is used as divide tool.");
	cls_ShapeUpgrade_ShapeDivideClosed.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_ShapeUpgrade_ShapeDivideClosed.def("SetNbSplitPoints", (void (ShapeUpgrade_ShapeDivideClosed::*)(const Standard_Integer)) &ShapeUpgrade_ShapeDivideClosed::SetNbSplitPoints, "Sets the number of cuts applied to divide closed faces. The number of resulting faces will be num+1.", py::arg("num"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ShapeDivideClosedEdges.hxx
	py::class_<ShapeUpgrade_ShapeDivideClosedEdges, std::unique_ptr<ShapeUpgrade_ShapeDivideClosedEdges, Deleter<ShapeUpgrade_ShapeDivideClosedEdges>>, ShapeUpgrade_ShapeDivide> cls_ShapeUpgrade_ShapeDivideClosedEdges(mod, "ShapeUpgrade_ShapeDivideClosedEdges", "None");
	cls_ShapeUpgrade_ShapeDivideClosedEdges.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_ShapeUpgrade_ShapeDivideClosedEdges.def("SetNbSplitPoints", (void (ShapeUpgrade_ShapeDivideClosedEdges::*)(const Standard_Integer)) &ShapeUpgrade_ShapeDivideClosedEdges::SetNbSplitPoints, "Sets the number of cuts applied to divide closed edges. The number of resulting faces will be num+1.", py::arg("num"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_SplitCurve.hxx
	py::class_<ShapeUpgrade_SplitCurve, opencascade::handle<ShapeUpgrade_SplitCurve>, Standard_Transient> cls_ShapeUpgrade_SplitCurve(mod, "ShapeUpgrade_SplitCurve", "Splits a curve with a criterion.");
	cls_ShapeUpgrade_SplitCurve.def(py::init<>());
	cls_ShapeUpgrade_SplitCurve.def("Init", (void (ShapeUpgrade_SplitCurve::*)(const Standard_Real, const Standard_Real)) &ShapeUpgrade_SplitCurve::Init, "Initializes with curve first and last parameters.", py::arg("First"), py::arg("Last"));
	cls_ShapeUpgrade_SplitCurve.def("SetSplitValues", (void (ShapeUpgrade_SplitCurve::*)(const opencascade::handle<TColStd_HSequenceOfReal> &)) &ShapeUpgrade_SplitCurve::SetSplitValues, "Sets the parameters where splitting has to be done.", py::arg("SplitValues"));
	cls_ShapeUpgrade_SplitCurve.def("Build", (void (ShapeUpgrade_SplitCurve::*)(const Standard_Boolean)) &ShapeUpgrade_SplitCurve::Build, "If Segment is True, the result is composed with segments of the curve bounded by the SplitValues. If Segment is False, the result is composed with trimmed Curves all based on the same complete curve.", py::arg("Segment"));
	cls_ShapeUpgrade_SplitCurve.def("SplitValues", (const opencascade::handle<TColStd_HSequenceOfReal> & (ShapeUpgrade_SplitCurve::*)() const ) &ShapeUpgrade_SplitCurve::SplitValues, "returns all the splitting values including the First and Last parameters of the input curve Merges input split values and new ones into myGlobalKnots");
	cls_ShapeUpgrade_SplitCurve.def("Compute", (void (ShapeUpgrade_SplitCurve::*)()) &ShapeUpgrade_SplitCurve::Compute, "Calculates points for correction/splitting of the curve");
	cls_ShapeUpgrade_SplitCurve.def("Perform", [](ShapeUpgrade_SplitCurve &self) -> void { return self.Perform(); });
	cls_ShapeUpgrade_SplitCurve.def("Perform", (void (ShapeUpgrade_SplitCurve::*)(const Standard_Boolean)) &ShapeUpgrade_SplitCurve::Perform, "Performs correction/splitting of the curve. First defines splitting values by method Compute(), then calls method Build().", py::arg("Segment"));
	cls_ShapeUpgrade_SplitCurve.def("Status", (Standard_Boolean (ShapeUpgrade_SplitCurve::*)(const ShapeExtend_Status) const ) &ShapeUpgrade_SplitCurve::Status, "Returns the status OK - no splitting is needed DONE1 - splitting required and gives more than one segment DONE2 - splitting is required, but gives only one segment (initial) DONE3 - geometric form of the curve or parametrisation is modified", py::arg("status"));
	cls_ShapeUpgrade_SplitCurve.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitCurve::get_type_name, "None");
	cls_ShapeUpgrade_SplitCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitCurve::get_type_descriptor, "None");
	cls_ShapeUpgrade_SplitCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitCurve::*)() const ) &ShapeUpgrade_SplitCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_SplitCurve2d.hxx
	py::class_<ShapeUpgrade_SplitCurve2d, opencascade::handle<ShapeUpgrade_SplitCurve2d>, ShapeUpgrade_SplitCurve> cls_ShapeUpgrade_SplitCurve2d(mod, "ShapeUpgrade_SplitCurve2d", "Splits a 2d curve with a criterion.");
	cls_ShapeUpgrade_SplitCurve2d.def(py::init<>());
	cls_ShapeUpgrade_SplitCurve2d.def("Init", (void (ShapeUpgrade_SplitCurve2d::*)(const opencascade::handle<Geom2d_Curve> &)) &ShapeUpgrade_SplitCurve2d::Init, "Initializes with pcurve with its first and last parameters.", py::arg("C"));
	cls_ShapeUpgrade_SplitCurve2d.def("Init", (void (ShapeUpgrade_SplitCurve2d::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real)) &ShapeUpgrade_SplitCurve2d::Init, "Initializes with pcurve with its parameters.", py::arg("C"), py::arg("First"), py::arg("Last"));
	cls_ShapeUpgrade_SplitCurve2d.def("Build", (void (ShapeUpgrade_SplitCurve2d::*)(const Standard_Boolean)) &ShapeUpgrade_SplitCurve2d::Build, "If Segment is True, the result is composed with segments of the curve bounded by the SplitValues. If Segment is False, the result is composed with trimmed Curves all based on the same complete curve.", py::arg("Segment"));
	cls_ShapeUpgrade_SplitCurve2d.def("GetCurves", (const opencascade::handle<TColGeom2d_HArray1OfCurve> & (ShapeUpgrade_SplitCurve2d::*)() const ) &ShapeUpgrade_SplitCurve2d::GetCurves, "None");
	cls_ShapeUpgrade_SplitCurve2d.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitCurve2d::get_type_name, "None");
	cls_ShapeUpgrade_SplitCurve2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitCurve2d::get_type_descriptor, "None");
	cls_ShapeUpgrade_SplitCurve2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitCurve2d::*)() const ) &ShapeUpgrade_SplitCurve2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_SplitCurve2dContinuity.hxx
	py::class_<ShapeUpgrade_SplitCurve2dContinuity, opencascade::handle<ShapeUpgrade_SplitCurve2dContinuity>, ShapeUpgrade_SplitCurve2d> cls_ShapeUpgrade_SplitCurve2dContinuity(mod, "ShapeUpgrade_SplitCurve2dContinuity", "Corrects/splits a 2d curve with a continuity criterion. Tolerance is used to correct the curve at a knot that respects geometrically the criterion, in order to reduce the multiplicity of the knot.");
	cls_ShapeUpgrade_SplitCurve2dContinuity.def(py::init<>());
	cls_ShapeUpgrade_SplitCurve2dContinuity.def("SetCriterion", (void (ShapeUpgrade_SplitCurve2dContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_SplitCurve2dContinuity::SetCriterion, "Sets criterion for splitting.", py::arg("Criterion"));
	cls_ShapeUpgrade_SplitCurve2dContinuity.def("SetTolerance", (void (ShapeUpgrade_SplitCurve2dContinuity::*)(const Standard_Real)) &ShapeUpgrade_SplitCurve2dContinuity::SetTolerance, "Sets tolerance.", py::arg("Tol"));
	cls_ShapeUpgrade_SplitCurve2dContinuity.def("Compute", (void (ShapeUpgrade_SplitCurve2dContinuity::*)()) &ShapeUpgrade_SplitCurve2dContinuity::Compute, "Calculates points for correction/splitting of the curve");
	cls_ShapeUpgrade_SplitCurve2dContinuity.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitCurve2dContinuity::get_type_name, "None");
	cls_ShapeUpgrade_SplitCurve2dContinuity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitCurve2dContinuity::get_type_descriptor, "None");
	cls_ShapeUpgrade_SplitCurve2dContinuity.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitCurve2dContinuity::*)() const ) &ShapeUpgrade_SplitCurve2dContinuity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ConvertCurve2dToBezier.hxx
	py::class_<ShapeUpgrade_ConvertCurve2dToBezier, opencascade::handle<ShapeUpgrade_ConvertCurve2dToBezier>, ShapeUpgrade_SplitCurve2d> cls_ShapeUpgrade_ConvertCurve2dToBezier(mod, "ShapeUpgrade_ConvertCurve2dToBezier", "converts/splits a 2d curve to a list of beziers");
	cls_ShapeUpgrade_ConvertCurve2dToBezier.def(py::init<>());
	cls_ShapeUpgrade_ConvertCurve2dToBezier.def("Compute", (void (ShapeUpgrade_ConvertCurve2dToBezier::*)()) &ShapeUpgrade_ConvertCurve2dToBezier::Compute, "Converts curve into a list of beziers, and stores the splitting parameters on original curve.");
	cls_ShapeUpgrade_ConvertCurve2dToBezier.def("Build", (void (ShapeUpgrade_ConvertCurve2dToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertCurve2dToBezier::Build, "Splits a list of beziers computed by Compute method according the split values and splitting parameters.", py::arg("Segment"));
	cls_ShapeUpgrade_ConvertCurve2dToBezier.def("SplitParams", (opencascade::handle<TColStd_HSequenceOfReal> (ShapeUpgrade_ConvertCurve2dToBezier::*)() const ) &ShapeUpgrade_ConvertCurve2dToBezier::SplitParams, "Returns the list of splitted parameters in original curve parametrisation.");
	cls_ShapeUpgrade_ConvertCurve2dToBezier.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_ConvertCurve2dToBezier::get_type_name, "None");
	cls_ShapeUpgrade_ConvertCurve2dToBezier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_ConvertCurve2dToBezier::get_type_descriptor, "None");
	cls_ShapeUpgrade_ConvertCurve2dToBezier.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_ConvertCurve2dToBezier::*)() const ) &ShapeUpgrade_ConvertCurve2dToBezier::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_SplitCurve3d.hxx
	py::class_<ShapeUpgrade_SplitCurve3d, opencascade::handle<ShapeUpgrade_SplitCurve3d>, ShapeUpgrade_SplitCurve> cls_ShapeUpgrade_SplitCurve3d(mod, "ShapeUpgrade_SplitCurve3d", "Splits a 3d curve with a criterion.");
	cls_ShapeUpgrade_SplitCurve3d.def(py::init<>());
	cls_ShapeUpgrade_SplitCurve3d.def("Init", (void (ShapeUpgrade_SplitCurve3d::*)(const opencascade::handle<Geom_Curve> &)) &ShapeUpgrade_SplitCurve3d::Init, "Initializes with curve with its first and last parameters.", py::arg("C"));
	cls_ShapeUpgrade_SplitCurve3d.def("Init", (void (ShapeUpgrade_SplitCurve3d::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &ShapeUpgrade_SplitCurve3d::Init, "Initializes with curve with its parameters.", py::arg("C"), py::arg("First"), py::arg("Last"));
	cls_ShapeUpgrade_SplitCurve3d.def("Build", (void (ShapeUpgrade_SplitCurve3d::*)(const Standard_Boolean)) &ShapeUpgrade_SplitCurve3d::Build, "If Segment is True, the result is composed with segments of the curve bounded by the SplitValues. If Segment is False, the result is composed with trimmed Curves all based on the same complete curve.", py::arg("Segment"));
	cls_ShapeUpgrade_SplitCurve3d.def("GetCurves", (const opencascade::handle<TColGeom_HArray1OfCurve> & (ShapeUpgrade_SplitCurve3d::*)() const ) &ShapeUpgrade_SplitCurve3d::GetCurves, "None");
	cls_ShapeUpgrade_SplitCurve3d.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitCurve3d::get_type_name, "None");
	cls_ShapeUpgrade_SplitCurve3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitCurve3d::get_type_descriptor, "None");
	cls_ShapeUpgrade_SplitCurve3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitCurve3d::*)() const ) &ShapeUpgrade_SplitCurve3d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_SplitCurve3dContinuity.hxx
	py::class_<ShapeUpgrade_SplitCurve3dContinuity, opencascade::handle<ShapeUpgrade_SplitCurve3dContinuity>, ShapeUpgrade_SplitCurve3d> cls_ShapeUpgrade_SplitCurve3dContinuity(mod, "ShapeUpgrade_SplitCurve3dContinuity", "Corrects/splits a 2d curve with a continuity criterion. Tolerance is used to correct the curve at a knot that respects geometrically the criterion, in order to reduce the multiplicity of the knot.");
	cls_ShapeUpgrade_SplitCurve3dContinuity.def(py::init<>());
	cls_ShapeUpgrade_SplitCurve3dContinuity.def("SetCriterion", (void (ShapeUpgrade_SplitCurve3dContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_SplitCurve3dContinuity::SetCriterion, "Sets criterion for splitting.", py::arg("Criterion"));
	cls_ShapeUpgrade_SplitCurve3dContinuity.def("SetTolerance", (void (ShapeUpgrade_SplitCurve3dContinuity::*)(const Standard_Real)) &ShapeUpgrade_SplitCurve3dContinuity::SetTolerance, "Sets tolerance.", py::arg("Tol"));
	cls_ShapeUpgrade_SplitCurve3dContinuity.def("Compute", (void (ShapeUpgrade_SplitCurve3dContinuity::*)()) &ShapeUpgrade_SplitCurve3dContinuity::Compute, "Calculates points for correction/splitting of the curve");
	cls_ShapeUpgrade_SplitCurve3dContinuity.def("GetCurve", (const opencascade::handle<Geom_Curve> & (ShapeUpgrade_SplitCurve3dContinuity::*)() const ) &ShapeUpgrade_SplitCurve3dContinuity::GetCurve, "None");
	cls_ShapeUpgrade_SplitCurve3dContinuity.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitCurve3dContinuity::get_type_name, "None");
	cls_ShapeUpgrade_SplitCurve3dContinuity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitCurve3dContinuity::get_type_descriptor, "None");
	cls_ShapeUpgrade_SplitCurve3dContinuity.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitCurve3dContinuity::*)() const ) &ShapeUpgrade_SplitCurve3dContinuity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ConvertCurve3dToBezier.hxx
	py::class_<ShapeUpgrade_ConvertCurve3dToBezier, opencascade::handle<ShapeUpgrade_ConvertCurve3dToBezier>, ShapeUpgrade_SplitCurve3d> cls_ShapeUpgrade_ConvertCurve3dToBezier(mod, "ShapeUpgrade_ConvertCurve3dToBezier", "converts/splits a 3d curve of any type to a list of beziers");
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def(py::init<>());
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def("SetLineMode", (void (ShapeUpgrade_ConvertCurve3dToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertCurve3dToBezier::SetLineMode, "Sets mode for conversion Geom_Line to bezier.", py::arg("mode"));
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def("GetLineMode", (Standard_Boolean (ShapeUpgrade_ConvertCurve3dToBezier::*)() const ) &ShapeUpgrade_ConvertCurve3dToBezier::GetLineMode, "Returns the Geom_Line conversion mode.");
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def("SetCircleMode", (void (ShapeUpgrade_ConvertCurve3dToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertCurve3dToBezier::SetCircleMode, "Sets mode for conversion Geom_Circle to bezier.", py::arg("mode"));
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def("GetCircleMode", (Standard_Boolean (ShapeUpgrade_ConvertCurve3dToBezier::*)() const ) &ShapeUpgrade_ConvertCurve3dToBezier::GetCircleMode, "Returns the Geom_Circle conversion mode.");
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def("SetConicMode", (void (ShapeUpgrade_ConvertCurve3dToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertCurve3dToBezier::SetConicMode, "Returns the Geom_Conic conversion mode.", py::arg("mode"));
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def("GetConicMode", (Standard_Boolean (ShapeUpgrade_ConvertCurve3dToBezier::*)() const ) &ShapeUpgrade_ConvertCurve3dToBezier::GetConicMode, "Performs converting and computes the resulting shape.");
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def("Compute", (void (ShapeUpgrade_ConvertCurve3dToBezier::*)()) &ShapeUpgrade_ConvertCurve3dToBezier::Compute, "Converts curve into a list of beziers, and stores the splitting parameters on original curve.");
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def("Build", (void (ShapeUpgrade_ConvertCurve3dToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertCurve3dToBezier::Build, "Splits a list of beziers computed by Compute method according the split values and splitting parameters.", py::arg("Segment"));
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def("SplitParams", (opencascade::handle<TColStd_HSequenceOfReal> (ShapeUpgrade_ConvertCurve3dToBezier::*)() const ) &ShapeUpgrade_ConvertCurve3dToBezier::SplitParams, "Returns the list of splitted parameters in original curve parametrisation.");
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_ConvertCurve3dToBezier::get_type_name, "None");
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_ConvertCurve3dToBezier::get_type_descriptor, "None");
	cls_ShapeUpgrade_ConvertCurve3dToBezier.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_ConvertCurve3dToBezier::*)() const ) &ShapeUpgrade_ConvertCurve3dToBezier::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_SplitSurface.hxx
	py::class_<ShapeUpgrade_SplitSurface, opencascade::handle<ShapeUpgrade_SplitSurface>, Standard_Transient> cls_ShapeUpgrade_SplitSurface(mod, "ShapeUpgrade_SplitSurface", "Splits a Surface with a criterion.");
	cls_ShapeUpgrade_SplitSurface.def(py::init<>());
	cls_ShapeUpgrade_SplitSurface.def("Init", (void (ShapeUpgrade_SplitSurface::*)(const opencascade::handle<Geom_Surface> &)) &ShapeUpgrade_SplitSurface::Init, "Initializes with single supporting surface.", py::arg("S"));
	cls_ShapeUpgrade_SplitSurface.def("Init", (void (ShapeUpgrade_SplitSurface::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ShapeUpgrade_SplitSurface::Init, "Initializes with single supporting surface with bounding parameters.", py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"));
	cls_ShapeUpgrade_SplitSurface.def("SetUSplitValues", (void (ShapeUpgrade_SplitSurface::*)(const opencascade::handle<TColStd_HSequenceOfReal> &)) &ShapeUpgrade_SplitSurface::SetUSplitValues, "Sets U parameters where splitting has to be done", py::arg("UValues"));
	cls_ShapeUpgrade_SplitSurface.def("SetVSplitValues", (void (ShapeUpgrade_SplitSurface::*)(const opencascade::handle<TColStd_HSequenceOfReal> &)) &ShapeUpgrade_SplitSurface::SetVSplitValues, "Sets V parameters where splitting has to be done", py::arg("VValues"));
	cls_ShapeUpgrade_SplitSurface.def("Build", (void (ShapeUpgrade_SplitSurface::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurface::Build, "Performs splitting of the supporting surface. If resulting surface is B-Spline and Segment is True, the result is composed with segments of the surface bounded by the U and V SplitValues (method Geom_BSplineSurface::Segment is used). If Segment is False, the result is composed with Geom_RectangularTrimmedSurface all based on the same complete surface. Fields myNbResultingRow and myNbResultingCol must be set to specify the size of resulting grid of surfaces.", py::arg("Segment"));
	cls_ShapeUpgrade_SplitSurface.def("Compute", [](ShapeUpgrade_SplitSurface &self) -> void { return self.Compute(); });
	cls_ShapeUpgrade_SplitSurface.def("Compute", (void (ShapeUpgrade_SplitSurface::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurface::Compute, "Calculates points for correction/splitting of the surface.", py::arg("Segment"));
	cls_ShapeUpgrade_SplitSurface.def("Perform", [](ShapeUpgrade_SplitSurface &self) -> void { return self.Perform(); });
	cls_ShapeUpgrade_SplitSurface.def("Perform", (void (ShapeUpgrade_SplitSurface::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurface::Perform, "Performs correction/splitting of the surface. First defines splitting values by method Compute(), then calls method Build().", py::arg("Segment"));
	cls_ShapeUpgrade_SplitSurface.def("USplitValues", (const opencascade::handle<TColStd_HSequenceOfReal> & (ShapeUpgrade_SplitSurface::*)() const ) &ShapeUpgrade_SplitSurface::USplitValues, "returns all the U splitting values including the First and Last parameters of the input surface");
	cls_ShapeUpgrade_SplitSurface.def("VSplitValues", (const opencascade::handle<TColStd_HSequenceOfReal> & (ShapeUpgrade_SplitSurface::*)() const ) &ShapeUpgrade_SplitSurface::VSplitValues, "returns all the splitting V values including the First and Last parameters of the input surface");
	cls_ShapeUpgrade_SplitSurface.def("Status", (Standard_Boolean (ShapeUpgrade_SplitSurface::*)(const ShapeExtend_Status) const ) &ShapeUpgrade_SplitSurface::Status, "Returns the status OK - no splitting is needed DONE1 - splitting required and gives more than one patch DONE2 - splitting is required, but gives only single patch (initial) DONE3 - geometric form of the surface or parametrisation is modified", py::arg("status"));
	cls_ShapeUpgrade_SplitSurface.def("ResSurfaces", (const opencascade::handle<ShapeExtend_CompositeSurface> & (ShapeUpgrade_SplitSurface::*)() const ) &ShapeUpgrade_SplitSurface::ResSurfaces, "Returns obtained surfaces after splitting as CompositeSurface");
	cls_ShapeUpgrade_SplitSurface.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitSurface::get_type_name, "None");
	cls_ShapeUpgrade_SplitSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitSurface::get_type_descriptor, "None");
	cls_ShapeUpgrade_SplitSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitSurface::*)() const ) &ShapeUpgrade_SplitSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_SplitSurfaceContinuity.hxx
	py::class_<ShapeUpgrade_SplitSurfaceContinuity, opencascade::handle<ShapeUpgrade_SplitSurfaceContinuity>, ShapeUpgrade_SplitSurface> cls_ShapeUpgrade_SplitSurfaceContinuity(mod, "ShapeUpgrade_SplitSurfaceContinuity", "Splits a Surface with a continuity criterion. At the present moment C1 criterion is used only. This tool works with tolerance. If C0 surface can be corrected at a knot with given tolerance then the surface is corrected, otherwise it is spltted at that knot.");
	cls_ShapeUpgrade_SplitSurfaceContinuity.def(py::init<>());
	cls_ShapeUpgrade_SplitSurfaceContinuity.def("SetCriterion", (void (ShapeUpgrade_SplitSurfaceContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_SplitSurfaceContinuity::SetCriterion, "Sets criterion for splitting.", py::arg("Criterion"));
	cls_ShapeUpgrade_SplitSurfaceContinuity.def("SetTolerance", (void (ShapeUpgrade_SplitSurfaceContinuity::*)(const Standard_Real)) &ShapeUpgrade_SplitSurfaceContinuity::SetTolerance, "Sets tolerance.", py::arg("Tol"));
	cls_ShapeUpgrade_SplitSurfaceContinuity.def("Compute", (void (ShapeUpgrade_SplitSurfaceContinuity::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurfaceContinuity::Compute, "None", py::arg("Segment"));
	cls_ShapeUpgrade_SplitSurfaceContinuity.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitSurfaceContinuity::get_type_name, "None");
	cls_ShapeUpgrade_SplitSurfaceContinuity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitSurfaceContinuity::get_type_descriptor, "None");
	cls_ShapeUpgrade_SplitSurfaceContinuity.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitSurfaceContinuity::*)() const ) &ShapeUpgrade_SplitSurfaceContinuity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_SplitSurfaceAngle.hxx
	py::class_<ShapeUpgrade_SplitSurfaceAngle, opencascade::handle<ShapeUpgrade_SplitSurfaceAngle>, ShapeUpgrade_SplitSurface> cls_ShapeUpgrade_SplitSurfaceAngle(mod, "ShapeUpgrade_SplitSurfaceAngle", "Splits a surfaces of revolution, cylindrical, toroidal, conical, spherical so that each resulting segment covers not more than defined number of degrees.");
	cls_ShapeUpgrade_SplitSurfaceAngle.def(py::init<const Standard_Real>(), py::arg("MaxAngle"));
	cls_ShapeUpgrade_SplitSurfaceAngle.def("SetMaxAngle", (void (ShapeUpgrade_SplitSurfaceAngle::*)(const Standard_Real)) &ShapeUpgrade_SplitSurfaceAngle::SetMaxAngle, "Set maximal angle", py::arg("MaxAngle"));
	cls_ShapeUpgrade_SplitSurfaceAngle.def("MaxAngle", (Standard_Real (ShapeUpgrade_SplitSurfaceAngle::*)() const ) &ShapeUpgrade_SplitSurfaceAngle::MaxAngle, "Returns maximal angle");
	cls_ShapeUpgrade_SplitSurfaceAngle.def("Compute", (void (ShapeUpgrade_SplitSurfaceAngle::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurfaceAngle::Compute, "Performs splitting of the supporting surface(s). First defines splitting values, then calls inherited method.", py::arg("Segment"));
	cls_ShapeUpgrade_SplitSurfaceAngle.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitSurfaceAngle::get_type_name, "None");
	cls_ShapeUpgrade_SplitSurfaceAngle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitSurfaceAngle::get_type_descriptor, "None");
	cls_ShapeUpgrade_SplitSurfaceAngle.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitSurfaceAngle::*)() const ) &ShapeUpgrade_SplitSurfaceAngle::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ConvertSurfaceToBezierBasis.hxx
	py::class_<ShapeUpgrade_ConvertSurfaceToBezierBasis, opencascade::handle<ShapeUpgrade_ConvertSurfaceToBezierBasis>, ShapeUpgrade_SplitSurface> cls_ShapeUpgrade_ConvertSurfaceToBezierBasis(mod, "ShapeUpgrade_ConvertSurfaceToBezierBasis", "Converts a plane, bspline surface, surface of revolution, surface of extrusion, offset surface to grid of bezier basis surface ( bezier surface, surface of revolution based on bezier curve, offset surface based on any previous type).");
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def(py::init<>());
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("Build", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::Build, "Splits a list of beziers computed by Compute method according the split values and splitting parameters.", py::arg("Segment"));
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("Compute", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::Compute, "Converts surface into a grid of bezier based surfaces, and stores this grid.", py::arg("Segment"));
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("Segments", (opencascade::handle<ShapeExtend_CompositeSurface> (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const ) &ShapeUpgrade_ConvertSurfaceToBezierBasis::Segments, "Returns the grid of bezier based surfaces correspondent to original surface.");
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("SetPlaneMode", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::SetPlaneMode, "Sets mode for conversion Geom_Plane to Bezier", py::arg("mode"));
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("GetPlaneMode", (Standard_Boolean (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const ) &ShapeUpgrade_ConvertSurfaceToBezierBasis::GetPlaneMode, "Returns the Geom_Pline conversion mode.");
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("SetRevolutionMode", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::SetRevolutionMode, "Sets mode for conversion Geom_SurfaceOfRevolution to Bezier", py::arg("mode"));
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("GetRevolutionMode", (Standard_Boolean (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const ) &ShapeUpgrade_ConvertSurfaceToBezierBasis::GetRevolutionMode, "Returns the Geom_SurfaceOfRevolution conversion mode.");
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("SetExtrusionMode", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::SetExtrusionMode, "Sets mode for conversion Geom_SurfaceOfLinearExtrusion to Bezier", py::arg("mode"));
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("GetExtrusionMode", (Standard_Boolean (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const ) &ShapeUpgrade_ConvertSurfaceToBezierBasis::GetExtrusionMode, "Returns the Geom_SurfaceOfLinearExtrusion conversion mode.");
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("SetBSplineMode", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::SetBSplineMode, "Sets mode for conversion Geom_BSplineSurface to Bezier", py::arg("mode"));
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("GetBSplineMode", (Standard_Boolean (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const ) &ShapeUpgrade_ConvertSurfaceToBezierBasis::GetBSplineMode, "Returns the Geom_BSplineSurface conversion mode.");
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_ConvertSurfaceToBezierBasis::get_type_name, "None");
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_ConvertSurfaceToBezierBasis::get_type_descriptor, "None");
	cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const ) &ShapeUpgrade_ConvertSurfaceToBezierBasis::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_SplitSurfaceArea.hxx
	py::class_<ShapeUpgrade_SplitSurfaceArea, opencascade::handle<ShapeUpgrade_SplitSurfaceArea>, ShapeUpgrade_SplitSurface> cls_ShapeUpgrade_SplitSurfaceArea(mod, "ShapeUpgrade_SplitSurfaceArea", "Split surface in the parametric space in according specified number of splits on the");
	cls_ShapeUpgrade_SplitSurfaceArea.def(py::init<>());
	cls_ShapeUpgrade_SplitSurfaceArea.def("NbParts", (Standard_Integer & (ShapeUpgrade_SplitSurfaceArea::*)()) &ShapeUpgrade_SplitSurfaceArea::NbParts, "Set number of split for surfaces");
	cls_ShapeUpgrade_SplitSurfaceArea.def("Compute", [](ShapeUpgrade_SplitSurfaceArea &self) -> void { return self.Compute(); });
	cls_ShapeUpgrade_SplitSurfaceArea.def("Compute", (void (ShapeUpgrade_SplitSurfaceArea::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurfaceArea::Compute, "None", py::arg("Segment"));
	cls_ShapeUpgrade_SplitSurfaceArea.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitSurfaceArea::get_type_name, "None");
	cls_ShapeUpgrade_SplitSurfaceArea.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitSurfaceArea::get_type_descriptor, "None");
	cls_ShapeUpgrade_SplitSurfaceArea.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitSurfaceArea::*)() const ) &ShapeUpgrade_SplitSurfaceArea::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_ShellSewing.hxx
	py::class_<ShapeUpgrade_ShellSewing, std::unique_ptr<ShapeUpgrade_ShellSewing, Deleter<ShapeUpgrade_ShellSewing>>> cls_ShapeUpgrade_ShellSewing(mod, "ShapeUpgrade_ShellSewing", "This class provides a tool for applying sewing algorithm from BRepBuilderAPI: it takes a shape, calls sewing for each shell, and then replaces sewed shells with use of ShapeBuild_ReShape");
	cls_ShapeUpgrade_ShellSewing.def(py::init<>());
	cls_ShapeUpgrade_ShellSewing.def("ApplySewing", [](ShapeUpgrade_ShellSewing &self, const TopoDS_Shape & a0) -> TopoDS_Shape { return self.ApplySewing(a0); }, py::arg("shape"));
	cls_ShapeUpgrade_ShellSewing.def("ApplySewing", (TopoDS_Shape (ShapeUpgrade_ShellSewing::*)(const TopoDS_Shape &, const Standard_Real)) &ShapeUpgrade_ShellSewing::ApplySewing, "Builds a new shape from a former one, by calling Sewing from BRepBuilderAPI. Rebuilt solids are oriented to be 'not infinite'", py::arg("shape"), py::arg("tol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_FixSmallCurves.hxx
	py::class_<ShapeUpgrade_FixSmallCurves, opencascade::handle<ShapeUpgrade_FixSmallCurves>, ShapeUpgrade_Tool> cls_ShapeUpgrade_FixSmallCurves(mod, "ShapeUpgrade_FixSmallCurves", "None");
	cls_ShapeUpgrade_FixSmallCurves.def(py::init<>());
	cls_ShapeUpgrade_FixSmallCurves.def("Init", (void (ShapeUpgrade_FixSmallCurves::*)(const TopoDS_Edge &, const TopoDS_Face &)) &ShapeUpgrade_FixSmallCurves::Init, "None", py::arg("theEdge"), py::arg("theFace"));
	cls_ShapeUpgrade_FixSmallCurves.def("Approx", [](ShapeUpgrade_FixSmallCurves &self, opencascade::handle<Geom_Curve> & Curve3d, opencascade::handle<Geom2d_Curve> & Curve2d, opencascade::handle<Geom2d_Curve> & Curve2dR, Standard_Real & First, Standard_Real & Last){ Standard_Boolean rv = self.Approx(Curve3d, Curve2d, Curve2dR, First, Last); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, First, Last); }, "None", py::arg("Curve3d"), py::arg("Curve2d"), py::arg("Curve2dR"), py::arg("First"), py::arg("Last"));
	cls_ShapeUpgrade_FixSmallCurves.def("SetSplitCurve3dTool", (void (ShapeUpgrade_FixSmallCurves::*)(const opencascade::handle<ShapeUpgrade_SplitCurve3d> &)) &ShapeUpgrade_FixSmallCurves::SetSplitCurve3dTool, "Sets the tool for splitting 3D curves.", py::arg("splitCurve3dTool"));
	cls_ShapeUpgrade_FixSmallCurves.def("SetSplitCurve2dTool", (void (ShapeUpgrade_FixSmallCurves::*)(const opencascade::handle<ShapeUpgrade_SplitCurve2d> &)) &ShapeUpgrade_FixSmallCurves::SetSplitCurve2dTool, "Sets the tool for splitting pcurves.", py::arg("splitCurve2dTool"));
	cls_ShapeUpgrade_FixSmallCurves.def("Status", (Standard_Boolean (ShapeUpgrade_FixSmallCurves::*)(const ShapeExtend_Status) const ) &ShapeUpgrade_FixSmallCurves::Status, "Queries the status of last call to Perform OK : DONE1: DONE2: FAIL1:", py::arg("status"));
	cls_ShapeUpgrade_FixSmallCurves.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_FixSmallCurves::get_type_name, "None");
	cls_ShapeUpgrade_FixSmallCurves.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_FixSmallCurves::get_type_descriptor, "None");
	cls_ShapeUpgrade_FixSmallCurves.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_FixSmallCurves::*)() const ) &ShapeUpgrade_FixSmallCurves::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_FixSmallBezierCurves.hxx
	py::class_<ShapeUpgrade_FixSmallBezierCurves, opencascade::handle<ShapeUpgrade_FixSmallBezierCurves>, ShapeUpgrade_FixSmallCurves> cls_ShapeUpgrade_FixSmallBezierCurves(mod, "ShapeUpgrade_FixSmallBezierCurves", "None");
	cls_ShapeUpgrade_FixSmallBezierCurves.def(py::init<>());
	cls_ShapeUpgrade_FixSmallBezierCurves.def("Approx", [](ShapeUpgrade_FixSmallBezierCurves &self, opencascade::handle<Geom_Curve> & Curve3d, opencascade::handle<Geom2d_Curve> & Curve2d, opencascade::handle<Geom2d_Curve> & Curve2dR, Standard_Real & First, Standard_Real & Last){ Standard_Boolean rv = self.Approx(Curve3d, Curve2d, Curve2dR, First, Last); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, First, Last); }, "None", py::arg("Curve3d"), py::arg("Curve2d"), py::arg("Curve2dR"), py::arg("First"), py::arg("Last"));
	cls_ShapeUpgrade_FixSmallBezierCurves.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_FixSmallBezierCurves::get_type_name, "None");
	cls_ShapeUpgrade_FixSmallBezierCurves.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_FixSmallBezierCurves::get_type_descriptor, "None");
	cls_ShapeUpgrade_FixSmallBezierCurves.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_FixSmallBezierCurves::*)() const ) &ShapeUpgrade_FixSmallBezierCurves::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_RemoveLocations.hxx
	py::class_<ShapeUpgrade_RemoveLocations, opencascade::handle<ShapeUpgrade_RemoveLocations>, Standard_Transient> cls_ShapeUpgrade_RemoveLocations(mod, "ShapeUpgrade_RemoveLocations", "Removes all locations sub-shapes of specified shape");
	cls_ShapeUpgrade_RemoveLocations.def(py::init<>());
	cls_ShapeUpgrade_RemoveLocations.def("Remove", (Standard_Boolean (ShapeUpgrade_RemoveLocations::*)(const TopoDS_Shape &)) &ShapeUpgrade_RemoveLocations::Remove, "Removes all location correspodingly to RemoveLevel.", py::arg("theShape"));
	cls_ShapeUpgrade_RemoveLocations.def("GetResult", (TopoDS_Shape (ShapeUpgrade_RemoveLocations::*)() const ) &ShapeUpgrade_RemoveLocations::GetResult, "Returns shape with removed locatins.");
	cls_ShapeUpgrade_RemoveLocations.def("SetRemoveLevel", (void (ShapeUpgrade_RemoveLocations::*)(const TopAbs_ShapeEnum)) &ShapeUpgrade_RemoveLocations::SetRemoveLevel, "sets level starting with that location will be removed, by default TopAbs_SHAPE. In this case locations will be kept for specified shape and if specified shape is TopAbs_COMPOUND for sub-shapes of first level.", py::arg("theLevel"));
	cls_ShapeUpgrade_RemoveLocations.def("RemoveLevel", (TopAbs_ShapeEnum (ShapeUpgrade_RemoveLocations::*)() const ) &ShapeUpgrade_RemoveLocations::RemoveLevel, "sets level starting with that location will be removed.Value of level can be set to TopAbs_SHAPE,TopAbs_COMPOUND,TopAbs_SOLID,TopAbs_SHELL,TopAbs_FACE.By default TopAbs_SHAPE. In this case location will be removed for all shape types for exception of compound.");
	cls_ShapeUpgrade_RemoveLocations.def("ModifiedShape", (TopoDS_Shape (ShapeUpgrade_RemoveLocations::*)(const TopoDS_Shape &) const ) &ShapeUpgrade_RemoveLocations::ModifiedShape, "Returns modified shape obtained from initial shape.", py::arg("theInitShape"));
	cls_ShapeUpgrade_RemoveLocations.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_RemoveLocations::get_type_name, "None");
	cls_ShapeUpgrade_RemoveLocations.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_RemoveLocations::get_type_descriptor, "None");
	cls_ShapeUpgrade_RemoveLocations.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_RemoveLocations::*)() const ) &ShapeUpgrade_RemoveLocations::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_RemoveInternalWires.hxx
	py::class_<ShapeUpgrade_RemoveInternalWires, opencascade::handle<ShapeUpgrade_RemoveInternalWires>, ShapeUpgrade_Tool> cls_ShapeUpgrade_RemoveInternalWires(mod, "ShapeUpgrade_RemoveInternalWires", "Removes all internal wires having area less than specified min area");
	cls_ShapeUpgrade_RemoveInternalWires.def(py::init<>());
	cls_ShapeUpgrade_RemoveInternalWires.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_ShapeUpgrade_RemoveInternalWires.def("Init", (void (ShapeUpgrade_RemoveInternalWires::*)(const TopoDS_Shape &)) &ShapeUpgrade_RemoveInternalWires::Init, "Initialize by a Shape.", py::arg("theShape"));
	cls_ShapeUpgrade_RemoveInternalWires.def("Perform", (Standard_Boolean (ShapeUpgrade_RemoveInternalWires::*)()) &ShapeUpgrade_RemoveInternalWires::Perform, "Removes all internal wires having area less than area specified as minimal allowed area");
	cls_ShapeUpgrade_RemoveInternalWires.def("Perform", (Standard_Boolean (ShapeUpgrade_RemoveInternalWires::*)(const TopTools_SequenceOfShape &)) &ShapeUpgrade_RemoveInternalWires::Perform, "If specified sequence of shape contains - 1.wires then these wires will be removed if they have area less than allowed min area. 2.faces than internal wires from these faces will be removed if they have area less than allowed min area.", py::arg("theSeqShapes"));
	cls_ShapeUpgrade_RemoveInternalWires.def("GetResult", (TopoDS_Shape (ShapeUpgrade_RemoveInternalWires::*)() const ) &ShapeUpgrade_RemoveInternalWires::GetResult, "Get result shape");
	cls_ShapeUpgrade_RemoveInternalWires.def("MinArea", (Standard_Real & (ShapeUpgrade_RemoveInternalWires::*)()) &ShapeUpgrade_RemoveInternalWires::MinArea, "Set min area allowed for holes( all holes having area less than mi area will be removed)");
	cls_ShapeUpgrade_RemoveInternalWires.def("RemoveFaceMode", (Standard_Boolean & (ShapeUpgrade_RemoveInternalWires::*)()) &ShapeUpgrade_RemoveInternalWires::RemoveFaceMode, "Set mode which manage removing faces which have outer wires consisting only from edges belonginig to removed internal wires. By default it is equal to true.");
	cls_ShapeUpgrade_RemoveInternalWires.def("RemovedFaces", (const TopTools_SequenceOfShape & (ShapeUpgrade_RemoveInternalWires::*)() const ) &ShapeUpgrade_RemoveInternalWires::RemovedFaces, "Returns sequence of removed faces.");
	cls_ShapeUpgrade_RemoveInternalWires.def("RemovedWires", (const TopTools_SequenceOfShape & (ShapeUpgrade_RemoveInternalWires::*)() const ) &ShapeUpgrade_RemoveInternalWires::RemovedWires, "Returns sequence of removed faces.");
	cls_ShapeUpgrade_RemoveInternalWires.def("Status", (Standard_Boolean (ShapeUpgrade_RemoveInternalWires::*)(const ShapeExtend_Status) const ) &ShapeUpgrade_RemoveInternalWires::Status, "Queries status of last call to Perform() : OK - nothing was done :DONE1 - internal wires were removed :DONE2 - small faces were removed. :FAIL1 - initial shape is not specified :FAIL2 - specified sub-shape is not belonged to inotial shape.", py::arg("theStatus"));
	cls_ShapeUpgrade_RemoveInternalWires.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_RemoveInternalWires::get_type_name, "None");
	cls_ShapeUpgrade_RemoveInternalWires.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_RemoveInternalWires::get_type_descriptor, "None");
	cls_ShapeUpgrade_RemoveInternalWires.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_RemoveInternalWires::*)() const ) &ShapeUpgrade_RemoveInternalWires::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade_UnifySameDomain.hxx
	py::class_<ShapeUpgrade_UnifySameDomain, opencascade::handle<ShapeUpgrade_UnifySameDomain>, Standard_Transient> cls_ShapeUpgrade_UnifySameDomain(mod, "ShapeUpgrade_UnifySameDomain", "This tool tries to unify faces and edges of the shape which lies on the same geometry. Faces/edges considering as 'same-domain' if a group of neighbouring faces/edges lying on coincident surfaces/curves. In this case these faces/edges can be unified into one face/edge. ShapeUpgrade_UnifySameDomain initialized by the shape and the next optional parameters: UnifyFaces - tries to unify all possible faces UnifyEdges - tries to unify all possible edges ConcatBSplines - if this flag set to true then all neighbouring edges which lays on the BSpline or Bezier curves with C1 continuity on their common vertices will be merged into one common edge The output result of tool is an unified shape All the modifications of initial shape are recorded during unifying. Methods History are intended to: - set a place holder for the history of the changing of the sub-shapes of the initial shape; - get the collected history. The algorithm provides a place holder for the history and collects the history by default. To avoid collecting of the history the place holder should be set to the null handle.");
	cls_ShapeUpgrade_UnifySameDomain.def(py::init<>());
	cls_ShapeUpgrade_UnifySameDomain.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));
	cls_ShapeUpgrade_UnifySameDomain.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("aShape"), py::arg("UnifyEdges"));
	cls_ShapeUpgrade_UnifySameDomain.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("aShape"), py::arg("UnifyEdges"), py::arg("UnifyFaces"));
	cls_ShapeUpgrade_UnifySameDomain.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("aShape"), py::arg("UnifyEdges"), py::arg("UnifyFaces"), py::arg("ConcatBSplines"));
	cls_ShapeUpgrade_UnifySameDomain.def("Initialize", [](ShapeUpgrade_UnifySameDomain &self, const TopoDS_Shape & a0) -> void { return self.Initialize(a0); }, py::arg("aShape"));
	cls_ShapeUpgrade_UnifySameDomain.def("Initialize", [](ShapeUpgrade_UnifySameDomain &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.Initialize(a0, a1); }, py::arg("aShape"), py::arg("UnifyEdges"));
	cls_ShapeUpgrade_UnifySameDomain.def("Initialize", [](ShapeUpgrade_UnifySameDomain &self, const TopoDS_Shape & a0, const Standard_Boolean a1, const Standard_Boolean a2) -> void { return self.Initialize(a0, a1, a2); }, py::arg("aShape"), py::arg("UnifyEdges"), py::arg("UnifyFaces"));
	cls_ShapeUpgrade_UnifySameDomain.def("Initialize", (void (ShapeUpgrade_UnifySameDomain::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &ShapeUpgrade_UnifySameDomain::Initialize, "Initializes with a shape", py::arg("aShape"), py::arg("UnifyEdges"), py::arg("UnifyFaces"), py::arg("ConcatBSplines"));
	cls_ShapeUpgrade_UnifySameDomain.def("AllowInternalEdges", (void (ShapeUpgrade_UnifySameDomain::*)(const Standard_Boolean)) &ShapeUpgrade_UnifySameDomain::AllowInternalEdges, "Sets the flag defining whether it is allowed to create internal edges inside merged faces in the case of non-manifold topology. Without this flag merging through multi connected edge is forbidden. Default value is false.", py::arg("theValue"));
	cls_ShapeUpgrade_UnifySameDomain.def("KeepShape", (void (ShapeUpgrade_UnifySameDomain::*)(const TopoDS_Shape &)) &ShapeUpgrade_UnifySameDomain::KeepShape, "Sets the shape for avoid merging of the faces in given places. This shape can be vertex or edge. If shape is vertex it forbids merging of connected edges. If shape is edge it forbids merging of connected faces.", py::arg("theShape"));
	cls_ShapeUpgrade_UnifySameDomain.def("KeepShapes", (void (ShapeUpgrade_UnifySameDomain::*)(const TopTools_MapOfShape &)) &ShapeUpgrade_UnifySameDomain::KeepShapes, "Sets the map of shapes for avoid merging of the faces in given places These shapes can be vertexes or edges. If shape is vertex it forbids merging of connected edges. If shape is edge it forbids merging of connected faces.", py::arg("theShapes"));
	cls_ShapeUpgrade_UnifySameDomain.def("SetSafeInputMode", (void (ShapeUpgrade_UnifySameDomain::*)(Standard_Boolean)) &ShapeUpgrade_UnifySameDomain::SetSafeInputMode, "Sets the flag defining the behavior of the algorithm regarding modification of input shape. If this flag is equal to True then the input (original) shape can't be modified during modification process. Default value is true.", py::arg("theValue"));
	cls_ShapeUpgrade_UnifySameDomain.def("SetLinearTolerance", (void (ShapeUpgrade_UnifySameDomain::*)(const Standard_Real)) &ShapeUpgrade_UnifySameDomain::SetLinearTolerance, "Sets the linear tolerance. Default value is Precision::Confusion().", py::arg("theValue"));
	cls_ShapeUpgrade_UnifySameDomain.def("SetAngularTolerance", (void (ShapeUpgrade_UnifySameDomain::*)(const Standard_Real)) &ShapeUpgrade_UnifySameDomain::SetAngularTolerance, "Sets the angular tolerance. Default value is Precision::Angular().", py::arg("theValue"));
	cls_ShapeUpgrade_UnifySameDomain.def("Build", (void (ShapeUpgrade_UnifySameDomain::*)()) &ShapeUpgrade_UnifySameDomain::Build, "Builds the resulting shape");
	cls_ShapeUpgrade_UnifySameDomain.def("Shape", (const TopoDS_Shape & (ShapeUpgrade_UnifySameDomain::*)() const ) &ShapeUpgrade_UnifySameDomain::Shape, "Gives the resulting shape");
	cls_ShapeUpgrade_UnifySameDomain.def("UnifyFaces", (void (ShapeUpgrade_UnifySameDomain::*)()) &ShapeUpgrade_UnifySameDomain::UnifyFaces, "this method makes if possible a common face from each group of faces lying on coincident surfaces");
	cls_ShapeUpgrade_UnifySameDomain.def("UnifyEdges", (void (ShapeUpgrade_UnifySameDomain::*)()) &ShapeUpgrade_UnifySameDomain::UnifyEdges, "this method makes if possible a common edge from each group of edges connecting common couple of faces");
	cls_ShapeUpgrade_UnifySameDomain.def("UnifyFacesAndEdges", (void (ShapeUpgrade_UnifySameDomain::*)()) &ShapeUpgrade_UnifySameDomain::UnifyFacesAndEdges, "this method unifies same domain faces and edges");
	cls_ShapeUpgrade_UnifySameDomain.def("History", (const opencascade::handle<BRepTools_History> & (ShapeUpgrade_UnifySameDomain::*)() const ) &ShapeUpgrade_UnifySameDomain::History, "Returns the history of the processed shapes.");
	cls_ShapeUpgrade_UnifySameDomain.def("History", (opencascade::handle<BRepTools_History> & (ShapeUpgrade_UnifySameDomain::*)()) &ShapeUpgrade_UnifySameDomain::History, "Returns the history of the processed shapes.");
	cls_ShapeUpgrade_UnifySameDomain.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_UnifySameDomain::get_type_name, "None");
	cls_ShapeUpgrade_UnifySameDomain.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_UnifySameDomain::get_type_descriptor, "None");
	cls_ShapeUpgrade_UnifySameDomain.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_UnifySameDomain::*)() const ) &ShapeUpgrade_UnifySameDomain::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeUpgrade.hxx
	py::class_<ShapeUpgrade, std::unique_ptr<ShapeUpgrade, Deleter<ShapeUpgrade>>> cls_ShapeUpgrade(mod, "ShapeUpgrade", "This package provides tools for splitting and converting shapes by some criteria. It provides modifications of the kind when one topological object can be converted or splitted to several ones. In particular this package contains high level API classes which perform: converting geometry of shapes up to given continuity, splitting revolutions by U to segments less than given value, converting to beziers, splitting closed faces.");
	cls_ShapeUpgrade.def(py::init<>());
	cls_ShapeUpgrade.def_static("C0BSplineToSequenceOfC1BSplineCurve_", (Standard_Boolean (*)(const opencascade::handle<Geom_BSplineCurve> &, opencascade::handle<TColGeom_HSequenceOfBoundedCurve> &)) &ShapeUpgrade::C0BSplineToSequenceOfC1BSplineCurve, "Unifies same domain faces and edges of specified shape", py::arg("BS"), py::arg("seqBS"));
	cls_ShapeUpgrade.def_static("C0BSplineToSequenceOfC1BSplineCurve_", (Standard_Boolean (*)(const opencascade::handle<Geom2d_BSplineCurve> &, opencascade::handle<TColGeom2d_HSequenceOfBoundedCurve> &)) &ShapeUpgrade::C0BSplineToSequenceOfC1BSplineCurve, "Converts C0 B-Spline curve into sequence of C1 B-Spline curves. This method splits B-Spline at the knots with multiplicities equal to degree, i.e. unlike method GeomConvert::C0BSplineToArrayOfC1BSplineCurve this one does not use any tolerance and therefore does not change the geometry of B-Spline. Returns True if C0 B-Spline was successfully splitted, else returns False (if BS is C1 B-Spline).", py::arg("BS"), py::arg("seqBS"));


}
