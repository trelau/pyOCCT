#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BRepLib_EdgeError.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepLib_Command.hxx>
#include <BRepLib_ShapeModification.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepLib_MakeShape.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <BRepLib_MakeEdge.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <BRepLib_MakeEdge2d.hxx>
#include <BRepLib_FaceError.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepLib_MakeFace.hxx>
#include <BRepLib_MakePolygon.hxx>
#include <BRepLib_ShellError.hxx>
#include <TopoDS_Shell.hxx>
#include <BRepLib_MakeShell.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Solid.hxx>
#include <BRepLib_MakeSolid.hxx>
#include <BRepLib_MakeVertex.hxx>
#include <BRepLib_WireError.hxx>
#include <BRepLib_MakeWire.hxx>
#include <TopLoc_Location.hxx>
#include <BRepLib_FindSurface.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepLib_FuseEdges.hxx>
#include <BRepLib_CheckCurveOnSurface.hxx>
#include <Geom_Plane.hxx>
#include <GeomAbs_Shape.hxx>
#include <BRepTools_ReShape.hxx>
#include <NCollection_List.hxx>
#include <Adaptor3d_Curve.hxx>
#include <BRepLib.hxx>

PYBIND11_MODULE(BRepLib, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.BRepTools");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Adaptor3d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_EdgeError.hxx
	py::enum_<BRepLib_EdgeError>(mod, "BRepLib_EdgeError", "Errors that can occur at edge construction. no error")
		.value("BRepLib_EdgeDone", BRepLib_EdgeError::BRepLib_EdgeDone)
		.value("BRepLib_PointProjectionFailed", BRepLib_EdgeError::BRepLib_PointProjectionFailed)
		.value("BRepLib_ParameterOutOfRange", BRepLib_EdgeError::BRepLib_ParameterOutOfRange)
		.value("BRepLib_DifferentPointsOnClosedCurve", BRepLib_EdgeError::BRepLib_DifferentPointsOnClosedCurve)
		.value("BRepLib_PointWithInfiniteParameter", BRepLib_EdgeError::BRepLib_PointWithInfiniteParameter)
		.value("BRepLib_DifferentsPointAndParameter", BRepLib_EdgeError::BRepLib_DifferentsPointAndParameter)
		.value("BRepLib_LineThroughIdenticPoints", BRepLib_EdgeError::BRepLib_LineThroughIdenticPoints)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_ShapeModification.hxx
	py::enum_<BRepLib_ShapeModification>(mod, "BRepLib_ShapeModification", "Modification type after a topologic operation.")
		.value("BRepLib_Preserved", BRepLib_ShapeModification::BRepLib_Preserved)
		.value("BRepLib_Deleted", BRepLib_ShapeModification::BRepLib_Deleted)
		.value("BRepLib_Trimmed", BRepLib_ShapeModification::BRepLib_Trimmed)
		.value("BRepLib_Merged", BRepLib_ShapeModification::BRepLib_Merged)
		.value("BRepLib_BoundaryModified", BRepLib_ShapeModification::BRepLib_BoundaryModified)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_FaceError.hxx
	py::enum_<BRepLib_FaceError>(mod, "BRepLib_FaceError", "Errors that can occur at face construction. no error not initialised")
		.value("BRepLib_FaceDone", BRepLib_FaceError::BRepLib_FaceDone)
		.value("BRepLib_NoFace", BRepLib_FaceError::BRepLib_NoFace)
		.value("BRepLib_NotPlanar", BRepLib_FaceError::BRepLib_NotPlanar)
		.value("BRepLib_CurveProjectionFailed", BRepLib_FaceError::BRepLib_CurveProjectionFailed)
		.value("BRepLib_ParametersOutOfRange", BRepLib_FaceError::BRepLib_ParametersOutOfRange)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_ShellError.hxx
	py::enum_<BRepLib_ShellError>(mod, "BRepLib_ShellError", "Errors that can occur at shell construction.")
		.value("BRepLib_ShellDone", BRepLib_ShellError::BRepLib_ShellDone)
		.value("BRepLib_EmptyShell", BRepLib_ShellError::BRepLib_EmptyShell)
		.value("BRepLib_DisconnectedShell", BRepLib_ShellError::BRepLib_DisconnectedShell)
		.value("BRepLib_ShellParametersOutOfRange", BRepLib_ShellError::BRepLib_ShellParametersOutOfRange)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_WireError.hxx
	py::enum_<BRepLib_WireError>(mod, "BRepLib_WireError", "Errors that can occur at wire construction. no error")
		.value("BRepLib_WireDone", BRepLib_WireError::BRepLib_WireDone)
		.value("BRepLib_EmptyWire", BRepLib_WireError::BRepLib_EmptyWire)
		.value("BRepLib_DisconnectedWire", BRepLib_WireError::BRepLib_DisconnectedWire)
		.value("BRepLib_NonManifoldWire", BRepLib_WireError::BRepLib_NonManifoldWire)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_Command.hxx
	py::class_<BRepLib_Command, std::unique_ptr<BRepLib_Command, Deleter<BRepLib_Command>>> cls_BRepLib_Command(mod, "BRepLib_Command", "Root class for all commands in BRepLib.");
	cls_BRepLib_Command.def("IsDone", (Standard_Boolean (BRepLib_Command::*)() const ) &BRepLib_Command::IsDone, "None");
	cls_BRepLib_Command.def("Check", (void (BRepLib_Command::*)() const ) &BRepLib_Command::Check, "Raises NotDone if done is false.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_MakeShape.hxx
	py::class_<BRepLib_MakeShape, std::unique_ptr<BRepLib_MakeShape, Deleter<BRepLib_MakeShape>>, BRepLib_Command> cls_BRepLib_MakeShape(mod, "BRepLib_MakeShape", "This is the root class for all shape constructions. It stores the result.");
	cls_BRepLib_MakeShape.def("Build", (void (BRepLib_MakeShape::*)()) &BRepLib_MakeShape::Build, "This is called by Shape(). It does nothing but may be redefined.");
	cls_BRepLib_MakeShape.def("Shape", (const TopoDS_Shape & (BRepLib_MakeShape::*)()) &BRepLib_MakeShape::Shape, "None");
	cls_BRepLib_MakeShape.def("FaceStatus", (BRepLib_ShapeModification (BRepLib_MakeShape::*)(const TopoDS_Face &) const ) &BRepLib_MakeShape::FaceStatus, "returns the status of the Face after the shape creation.", py::arg("F"));
	cls_BRepLib_MakeShape.def("HasDescendants", (Standard_Boolean (BRepLib_MakeShape::*)(const TopoDS_Face &) const ) &BRepLib_MakeShape::HasDescendants, "Returns True if the Face generates new topology.", py::arg("F"));
	cls_BRepLib_MakeShape.def("DescendantFaces", (const TopTools_ListOfShape & (BRepLib_MakeShape::*)(const TopoDS_Face &)) &BRepLib_MakeShape::DescendantFaces, "returns the list of generated Faces.", py::arg("F"));
	cls_BRepLib_MakeShape.def("NbSurfaces", (Standard_Integer (BRepLib_MakeShape::*)() const ) &BRepLib_MakeShape::NbSurfaces, "returns the number of surfaces after the shape creation.");
	cls_BRepLib_MakeShape.def("NewFaces", (const TopTools_ListOfShape & (BRepLib_MakeShape::*)(const Standard_Integer)) &BRepLib_MakeShape::NewFaces, "Return the faces created for surface I.", py::arg("I"));
	cls_BRepLib_MakeShape.def("FacesFromEdges", (const TopTools_ListOfShape & (BRepLib_MakeShape::*)(const TopoDS_Edge &)) &BRepLib_MakeShape::FacesFromEdges, "returns a list of the created faces from the edge <E>.", py::arg("E"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_MakeEdge.hxx
	py::class_<BRepLib_MakeEdge, std::unique_ptr<BRepLib_MakeEdge, Deleter<BRepLib_MakeEdge>>, BRepLib_MakeShape> cls_BRepLib_MakeEdge(mod, "BRepLib_MakeEdge", "Provides methods to build edges.");
	cls_BRepLib_MakeEdge.def(py::init<>());
	cls_BRepLib_MakeEdge.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &>(), py::arg("L"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &>(), py::arg("L"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &>(), py::arg("L"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &>(), py::arg("L"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &>(), py::arg("L"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("L"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &>(), py::arg("L"), py::arg("S"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("S"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("S"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge.def("Error", (BRepLib_EdgeError (BRepLib_MakeEdge::*)() const ) &BRepLib_MakeEdge::Error, "Returns the error description when NotDone.");
	cls_BRepLib_MakeEdge.def("Edge", (const TopoDS_Edge & (BRepLib_MakeEdge::*)()) &BRepLib_MakeEdge::Edge, "None");
	cls_BRepLib_MakeEdge.def("Vertex1", (const TopoDS_Vertex & (BRepLib_MakeEdge::*)() const ) &BRepLib_MakeEdge::Vertex1, "Returns the first vertex of the edge. May be Null.");
	cls_BRepLib_MakeEdge.def("Vertex2", (const TopoDS_Vertex & (BRepLib_MakeEdge::*)() const ) &BRepLib_MakeEdge::Vertex2, "Returns the second vertex of the edge. May be Null.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_MakeEdge2d.hxx
	py::class_<BRepLib_MakeEdge2d, std::unique_ptr<BRepLib_MakeEdge2d, Deleter<BRepLib_MakeEdge2d>>, BRepLib_MakeShape> cls_BRepLib_MakeEdge2d(mod, "BRepLib_MakeEdge2d", "Provides methods to build edges.");
	cls_BRepLib_MakeEdge2d.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Lin2d &>(), py::arg("L"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Lin2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Lin2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Circ2d &>(), py::arg("L"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Circ2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Circ2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Circ2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Elips2d &>(), py::arg("L"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Elips2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Elips2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Elips2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Hypr2d &>(), py::arg("L"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Hypr2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Hypr2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Hypr2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Parab2d &>(), py::arg("L"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Parab2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Parab2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const gp_Parab2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &>(), py::arg("L"));
	cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"));
	cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
	cls_BRepLib_MakeEdge2d.def("Error", (BRepLib_EdgeError (BRepLib_MakeEdge2d::*)() const ) &BRepLib_MakeEdge2d::Error, "Returns the error description when NotDone.");
	cls_BRepLib_MakeEdge2d.def("Edge", (const TopoDS_Edge & (BRepLib_MakeEdge2d::*)()) &BRepLib_MakeEdge2d::Edge, "None");
	cls_BRepLib_MakeEdge2d.def("Vertex1", (const TopoDS_Vertex & (BRepLib_MakeEdge2d::*)() const ) &BRepLib_MakeEdge2d::Vertex1, "Returns the first vertex of the edge. May be Null.");
	cls_BRepLib_MakeEdge2d.def("Vertex2", (const TopoDS_Vertex & (BRepLib_MakeEdge2d::*)() const ) &BRepLib_MakeEdge2d::Vertex2, "Returns the second vertex of the edge. May be Null.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_MakeFace.hxx
	py::class_<BRepLib_MakeFace, std::unique_ptr<BRepLib_MakeFace, Deleter<BRepLib_MakeFace>>, BRepLib_MakeShape> cls_BRepLib_MakeFace(mod, "BRepLib_MakeFace", "Provides methods to build faces.");
	cls_BRepLib_MakeFace.def(py::init<>());
	cls_BRepLib_MakeFace.def(py::init<const TopoDS_Face &>(), py::arg("F"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Pln &>(), py::arg("P"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &>(), py::arg("C"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Cone &>(), py::arg("C"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &>(), py::arg("S"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Torus &>(), py::arg("C"));
	cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("S"), py::arg("TolDegen"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Pln &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
	cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("TolDegen"));
	cls_BRepLib_MakeFace.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
	cls_BRepLib_MakeFace.def(py::init<const TopoDS_Wire &, const Standard_Boolean>(), py::arg("W"), py::arg("OnlyPlane"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Pln &, const TopoDS_Wire &>(), py::arg("P"), py::arg("W"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Pln &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("P"), py::arg("W"), py::arg("Inside"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Cone &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Cone &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &, const TopoDS_Wire &>(), py::arg("S"), py::arg("W"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("S"), py::arg("W"), py::arg("Inside"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Torus &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
	cls_BRepLib_MakeFace.def(py::init<const gp_Torus &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
	cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Wire &>(), py::arg("S"), py::arg("W"));
	cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("S"), py::arg("W"), py::arg("Inside"));
	cls_BRepLib_MakeFace.def(py::init<const TopoDS_Face &, const TopoDS_Wire &>(), py::arg("F"), py::arg("W"));
	cls_BRepLib_MakeFace.def("Init", (void (BRepLib_MakeFace::*)(const TopoDS_Face &)) &BRepLib_MakeFace::Init, "Load the face.", py::arg("F"));
	cls_BRepLib_MakeFace.def("Init", (void (BRepLib_MakeFace::*)(const opencascade::handle<Geom_Surface> &, const Standard_Boolean, const Standard_Real)) &BRepLib_MakeFace::Init, "Creates the face from the surface. If Bound is True a wire is made from the natural bounds. Accepts tolerance value (TolDegen) for resolution of degenerated edges.", py::arg("S"), py::arg("Bound"), py::arg("TolDegen"));
	cls_BRepLib_MakeFace.def("Init", (void (BRepLib_MakeFace::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepLib_MakeFace::Init, "Creates the face from the surface and the min-max values. Accepts tolerance value (TolDegen) for resolution of degenerated edges.", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("TolDegen"));
	cls_BRepLib_MakeFace.def("Add", (void (BRepLib_MakeFace::*)(const TopoDS_Wire &)) &BRepLib_MakeFace::Add, "Adds the wire <W> in the current face.", py::arg("W"));
	cls_BRepLib_MakeFace.def("Error", (BRepLib_FaceError (BRepLib_MakeFace::*)() const ) &BRepLib_MakeFace::Error, "None");
	cls_BRepLib_MakeFace.def("Face", (const TopoDS_Face & (BRepLib_MakeFace::*)() const ) &BRepLib_MakeFace::Face, "Returns the new face.");
	cls_BRepLib_MakeFace.def_static("IsDegenerated_", (Standard_Boolean (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, Standard_Real &)) &BRepLib_MakeFace::IsDegenerated, "Checks the specified curve is degenerated according to specified tolerance. Returns <theActTol> less than <theMaxTol>, which shows actual tolerance to decide the curve is degenerated. Warning: For internal use of BRepLib_MakeFace and BRepLib_MakeShell.", py::arg("theCurve"), py::arg("theMaxTol"), py::arg("theActTol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_MakePolygon.hxx
	py::class_<BRepLib_MakePolygon, std::unique_ptr<BRepLib_MakePolygon, Deleter<BRepLib_MakePolygon>>, BRepLib_MakeShape> cls_BRepLib_MakePolygon(mod, "BRepLib_MakePolygon", "Class to build polygonal wires.");
	cls_BRepLib_MakePolygon.def(py::init<>());
	cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
	cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
	cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("Close"));
	cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
	cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("Close"));
	cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
	cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("Close"));
	cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"));
	cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"), py::arg("Close"));
	cls_BRepLib_MakePolygon.def("Add", (void (BRepLib_MakePolygon::*)(const gp_Pnt &)) &BRepLib_MakePolygon::Add, "None", py::arg("P"));
	cls_BRepLib_MakePolygon.def("Add", (void (BRepLib_MakePolygon::*)(const TopoDS_Vertex &)) &BRepLib_MakePolygon::Add, "None", py::arg("V"));
	cls_BRepLib_MakePolygon.def("Added", (Standard_Boolean (BRepLib_MakePolygon::*)() const ) &BRepLib_MakePolygon::Added, "Returns True if the last vertex or point was succesfully added.");
	cls_BRepLib_MakePolygon.def("Close", (void (BRepLib_MakePolygon::*)()) &BRepLib_MakePolygon::Close, "None");
	cls_BRepLib_MakePolygon.def("FirstVertex", (const TopoDS_Vertex & (BRepLib_MakePolygon::*)() const ) &BRepLib_MakePolygon::FirstVertex, "None");
	cls_BRepLib_MakePolygon.def("LastVertex", (const TopoDS_Vertex & (BRepLib_MakePolygon::*)() const ) &BRepLib_MakePolygon::LastVertex, "None");
	cls_BRepLib_MakePolygon.def("Edge", (const TopoDS_Edge & (BRepLib_MakePolygon::*)() const ) &BRepLib_MakePolygon::Edge, "Returns the last edge added to the polygon.");
	cls_BRepLib_MakePolygon.def("Wire", (const TopoDS_Wire & (BRepLib_MakePolygon::*)()) &BRepLib_MakePolygon::Wire, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_MakeShell.hxx
	py::class_<BRepLib_MakeShell, std::unique_ptr<BRepLib_MakeShell, Deleter<BRepLib_MakeShell>>, BRepLib_MakeShape> cls_BRepLib_MakeShell(mod, "BRepLib_MakeShell", "Provides methos to build shells.");
	cls_BRepLib_MakeShell.def(py::init<>());
	cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));
	cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("S"), py::arg("Segment"));
	cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
	cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Segment"));
	cls_BRepLib_MakeShell.def("Init", [](BRepLib_MakeShell &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Init(a0, a1, a2, a3, a4); }, py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
	cls_BRepLib_MakeShell.def("Init", (void (BRepLib_MakeShell::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepLib_MakeShell::Init, "Creates the shell from the surface and the min-max values.", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Segment"));
	cls_BRepLib_MakeShell.def("Error", (BRepLib_ShellError (BRepLib_MakeShell::*)() const ) &BRepLib_MakeShell::Error, "None");
	cls_BRepLib_MakeShell.def("Shell", (const TopoDS_Shell & (BRepLib_MakeShell::*)() const ) &BRepLib_MakeShell::Shell, "Returns the new Shell.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_MakeSolid.hxx
	py::class_<BRepLib_MakeSolid, std::unique_ptr<BRepLib_MakeSolid, Deleter<BRepLib_MakeSolid>>, BRepLib_MakeShape> cls_BRepLib_MakeSolid(mod, "BRepLib_MakeSolid", "Makes a solid from compsolid or shells.");
	cls_BRepLib_MakeSolid.def(py::init<>());
	cls_BRepLib_MakeSolid.def(py::init<const TopoDS_CompSolid &>(), py::arg("S"));
	cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Shell &>(), py::arg("S"));
	cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Shell &, const TopoDS_Shell &>(), py::arg("S1"), py::arg("S2"));
	cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Shell &, const TopoDS_Shell &, const TopoDS_Shell &>(), py::arg("S1"), py::arg("S2"), py::arg("S3"));
	cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Solid &>(), py::arg("So"));
	cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Solid &, const TopoDS_Shell &>(), py::arg("So"), py::arg("S"));
	cls_BRepLib_MakeSolid.def("Add", (void (BRepLib_MakeSolid::*)(const TopoDS_Shell &)) &BRepLib_MakeSolid::Add, "Add the shell to the current solid.", py::arg("S"));
	cls_BRepLib_MakeSolid.def("Solid", (const TopoDS_Solid & (BRepLib_MakeSolid::*)()) &BRepLib_MakeSolid::Solid, "Returns the new Solid.");
	cls_BRepLib_MakeSolid.def("FaceStatus", (BRepLib_ShapeModification (BRepLib_MakeSolid::*)(const TopoDS_Face &) const ) &BRepLib_MakeSolid::FaceStatus, "returns the status of the Face after the shape creation.", py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_MakeVertex.hxx
	py::class_<BRepLib_MakeVertex, std::unique_ptr<BRepLib_MakeVertex, Deleter<BRepLib_MakeVertex>>, BRepLib_MakeShape> cls_BRepLib_MakeVertex(mod, "BRepLib_MakeVertex", "Provides methods to build vertices.");
	cls_BRepLib_MakeVertex.def(py::init<const gp_Pnt &>(), py::arg("P"));
	cls_BRepLib_MakeVertex.def("Vertex", (const TopoDS_Vertex & (BRepLib_MakeVertex::*)()) &BRepLib_MakeVertex::Vertex, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_MakeWire.hxx
	py::class_<BRepLib_MakeWire, std::unique_ptr<BRepLib_MakeWire, Deleter<BRepLib_MakeWire>>, BRepLib_MakeShape> cls_BRepLib_MakeWire(mod, "BRepLib_MakeWire", "Provides methods to build wires.");
	cls_BRepLib_MakeWire.def(py::init<>());
	cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &>(), py::arg("E"));
	cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"));
	cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"), py::arg("E3"));
	cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"), py::arg("E3"), py::arg("E4"));
	cls_BRepLib_MakeWire.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
	cls_BRepLib_MakeWire.def(py::init<const TopoDS_Wire &, const TopoDS_Edge &>(), py::arg("W"), py::arg("E"));
	cls_BRepLib_MakeWire.def("Add", (void (BRepLib_MakeWire::*)(const TopoDS_Edge &)) &BRepLib_MakeWire::Add, "Add the edge <E> to the current wire.", py::arg("E"));
	cls_BRepLib_MakeWire.def("Add", (void (BRepLib_MakeWire::*)(const TopoDS_Wire &)) &BRepLib_MakeWire::Add, "Add the edges of <W> to the current wire.", py::arg("W"));
	cls_BRepLib_MakeWire.def("Add", (void (BRepLib_MakeWire::*)(const TopTools_ListOfShape &)) &BRepLib_MakeWire::Add, "Add the edges of <L> to the current wire. The edges are not to be consecutive. But they are to be all connected geometrically or topologically.", py::arg("L"));
	cls_BRepLib_MakeWire.def("Error", (BRepLib_WireError (BRepLib_MakeWire::*)() const ) &BRepLib_MakeWire::Error, "None");
	cls_BRepLib_MakeWire.def("Wire", (const TopoDS_Wire & (BRepLib_MakeWire::*)()) &BRepLib_MakeWire::Wire, "Returns the new wire.");
	cls_BRepLib_MakeWire.def("Edge", (const TopoDS_Edge & (BRepLib_MakeWire::*)() const ) &BRepLib_MakeWire::Edge, "Returns the last edge added to the wire.");
	cls_BRepLib_MakeWire.def("Vertex", (const TopoDS_Vertex & (BRepLib_MakeWire::*)() const ) &BRepLib_MakeWire::Vertex, "Returns the last connecting vertex.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_FindSurface.hxx
	py::class_<BRepLib_FindSurface, std::unique_ptr<BRepLib_FindSurface, Deleter<BRepLib_FindSurface>>> cls_BRepLib_FindSurface(mod, "BRepLib_FindSurface", "Provides an algorithm to find a Surface through a set of edges.");
	cls_BRepLib_FindSurface.def(py::init<>());
	cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("S"), py::arg("Tol"));
	cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("Tol"), py::arg("OnlyPlane"));
	cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("Tol"), py::arg("OnlyPlane"), py::arg("OnlyClosed"));
	cls_BRepLib_FindSurface.def("Init", [](BRepLib_FindSurface &self, const TopoDS_Shape & a0) -> void { return self.Init(a0); }, py::arg("S"));
	cls_BRepLib_FindSurface.def("Init", [](BRepLib_FindSurface &self, const TopoDS_Shape & a0, const Standard_Real a1) -> void { return self.Init(a0, a1); }, py::arg("S"), py::arg("Tol"));
	cls_BRepLib_FindSurface.def("Init", [](BRepLib_FindSurface &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Boolean a2) -> void { return self.Init(a0, a1, a2); }, py::arg("S"), py::arg("Tol"), py::arg("OnlyPlane"));
	cls_BRepLib_FindSurface.def("Init", (void (BRepLib_FindSurface::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &BRepLib_FindSurface::Init, "Computes the Surface from the edges of <S> with the given tolerance. if <OnlyPlane> is true, the computed surface will be a plane. If it is not possible to find a plane, the flag NotDone will be set. If <OnlyClosed> is true, then S sould be a wire and the existing surface, on which wire S is not closed in 2D, will be ignored.", py::arg("S"), py::arg("Tol"), py::arg("OnlyPlane"), py::arg("OnlyClosed"));
	cls_BRepLib_FindSurface.def("Found", (Standard_Boolean (BRepLib_FindSurface::*)() const ) &BRepLib_FindSurface::Found, "None");
	cls_BRepLib_FindSurface.def("Surface", (opencascade::handle<Geom_Surface> (BRepLib_FindSurface::*)() const ) &BRepLib_FindSurface::Surface, "None");
	cls_BRepLib_FindSurface.def("Tolerance", (Standard_Real (BRepLib_FindSurface::*)() const ) &BRepLib_FindSurface::Tolerance, "None");
	cls_BRepLib_FindSurface.def("ToleranceReached", (Standard_Real (BRepLib_FindSurface::*)() const ) &BRepLib_FindSurface::ToleranceReached, "None");
	cls_BRepLib_FindSurface.def("Existed", (Standard_Boolean (BRepLib_FindSurface::*)() const ) &BRepLib_FindSurface::Existed, "None");
	cls_BRepLib_FindSurface.def("Location", (TopLoc_Location (BRepLib_FindSurface::*)() const ) &BRepLib_FindSurface::Location, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_FuseEdges.hxx
	py::class_<BRepLib_FuseEdges, std::unique_ptr<BRepLib_FuseEdges, Deleter<BRepLib_FuseEdges>>> cls_BRepLib_FuseEdges(mod, "BRepLib_FuseEdges", "This class can detect vertices in a face that can be considered useless and then perform the fuse of the edges and remove the useless vertices. By useles vertices, we mean : * vertices that have exactly two connex edges * the edges connex to the vertex must have exactly the same 2 connex faces . * The edges connex to the vertex must have the same geometric support.");
	cls_BRepLib_FuseEdges.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BRepLib_FuseEdges.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theShape"), py::arg("PerformNow"));
	cls_BRepLib_FuseEdges.def("AvoidEdges", (void (BRepLib_FuseEdges::*)(const TopTools_IndexedMapOfShape &)) &BRepLib_FuseEdges::AvoidEdges, "set edges to avoid being fused", py::arg("theMapEdg"));
	cls_BRepLib_FuseEdges.def("SetConcatBSpl", [](BRepLib_FuseEdges &self) -> void { return self.SetConcatBSpl(); });
	cls_BRepLib_FuseEdges.def("SetConcatBSpl", (void (BRepLib_FuseEdges::*)(const Standard_Boolean)) &BRepLib_FuseEdges::SetConcatBSpl, "set mode to enable concatenation G1 BSpline edges in one End Modified by IFV 19.04.07", py::arg("theConcatBSpl"));
	cls_BRepLib_FuseEdges.def("Edges", (void (BRepLib_FuseEdges::*)(TopTools_DataMapOfIntegerListOfShape &)) &BRepLib_FuseEdges::Edges, "returns all the list of edges to be fused each list of the map represent a set of connex edges that can be fused.", py::arg("theMapLstEdg"));
	cls_BRepLib_FuseEdges.def("ResultEdges", (void (BRepLib_FuseEdges::*)(TopTools_DataMapOfIntegerShape &)) &BRepLib_FuseEdges::ResultEdges, "returns all the fused edges. each integer entry in the map corresponds to the integer in the DataMapOfIntegerListOfShape we get in method Edges. That is to say, to the list of edges in theMapLstEdg(i) corresponds the resulting edge theMapEdge(i)", py::arg("theMapEdg"));
	cls_BRepLib_FuseEdges.def("Faces", (void (BRepLib_FuseEdges::*)(TopTools_DataMapOfShapeShape &)) &BRepLib_FuseEdges::Faces, "returns the map of modified faces.", py::arg("theMapFac"));
	cls_BRepLib_FuseEdges.def("Shape", (TopoDS_Shape & (BRepLib_FuseEdges::*)()) &BRepLib_FuseEdges::Shape, "returns myShape modified with the list of internal edges removed from it.");
	cls_BRepLib_FuseEdges.def("NbVertices", (Standard_Integer (BRepLib_FuseEdges::*)()) &BRepLib_FuseEdges::NbVertices, "returns the number of vertices candidate to be removed");
	cls_BRepLib_FuseEdges.def("Perform", (void (BRepLib_FuseEdges::*)()) &BRepLib_FuseEdges::Perform, "Using map of list of connex edges, fuse each list to one edge and then update myShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib_CheckCurveOnSurface.hxx
	py::class_<BRepLib_CheckCurveOnSurface, std::unique_ptr<BRepLib_CheckCurveOnSurface, Deleter<BRepLib_CheckCurveOnSurface>>> cls_BRepLib_CheckCurveOnSurface(mod, "BRepLib_CheckCurveOnSurface", "Computes the max distance between edge and its 2d representation on the face.");
	cls_BRepLib_CheckCurveOnSurface.def(py::init<>());
	cls_BRepLib_CheckCurveOnSurface.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("theEdge"), py::arg("theFace"));
	cls_BRepLib_CheckCurveOnSurface.def("Init", (void (BRepLib_CheckCurveOnSurface::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepLib_CheckCurveOnSurface::Init, "Sets the data for the algorithm", py::arg("theEdge"), py::arg("theFace"));
	cls_BRepLib_CheckCurveOnSurface.def("Perform", [](BRepLib_CheckCurveOnSurface &self) -> void { return self.Perform(); });
	cls_BRepLib_CheckCurveOnSurface.def("Perform", (void (BRepLib_CheckCurveOnSurface::*)(const Standard_Boolean)) &BRepLib_CheckCurveOnSurface::Perform, "Performs the calculation If isTheMultyTheadDisabled == TRUE then computation will be made without any parallelization.", py::arg("isTheMultyTheradDisabled"));
	cls_BRepLib_CheckCurveOnSurface.def("Curve", (const opencascade::handle<Geom_Curve> & (BRepLib_CheckCurveOnSurface::*)() const ) &BRepLib_CheckCurveOnSurface::Curve, "Returns source 3D-Curve");
	cls_BRepLib_CheckCurveOnSurface.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (BRepLib_CheckCurveOnSurface::*)() const ) &BRepLib_CheckCurveOnSurface::PCurve, "Returns mine 2D-Curve");
	cls_BRepLib_CheckCurveOnSurface.def("PCurve2", (const opencascade::handle<Geom2d_Curve> & (BRepLib_CheckCurveOnSurface::*)() const ) &BRepLib_CheckCurveOnSurface::PCurve2, "Returns 2nd 2D-Curve (if it exists, e.g. for seam-edge)");
	cls_BRepLib_CheckCurveOnSurface.def("Surface", (const opencascade::handle<Geom_Surface> & (BRepLib_CheckCurveOnSurface::*)() const ) &BRepLib_CheckCurveOnSurface::Surface, "Returns source surface");
	cls_BRepLib_CheckCurveOnSurface.def("Range", (void (BRepLib_CheckCurveOnSurface::*)(Standard_Real &, Standard_Real &)) &BRepLib_CheckCurveOnSurface::Range, "Returns first and last parameter of the curves (2D- and 3D-curves are considered to have same range)", py::arg("theFirst"), py::arg("theLast"));
	cls_BRepLib_CheckCurveOnSurface.def("IsDone", (Standard_Boolean (BRepLib_CheckCurveOnSurface::*)() const ) &BRepLib_CheckCurveOnSurface::IsDone, "Returns true if the max distance has been found");
	cls_BRepLib_CheckCurveOnSurface.def("ErrorStatus", (Standard_Integer (BRepLib_CheckCurveOnSurface::*)() const ) &BRepLib_CheckCurveOnSurface::ErrorStatus, "Returns error status The possible values are: 0 - OK; 1 - null curve or surface or 2d curve; 2 - invalid parametric range; 3 - error in calculations.");
	cls_BRepLib_CheckCurveOnSurface.def("MaxDistance", (Standard_Real (BRepLib_CheckCurveOnSurface::*)() const ) &BRepLib_CheckCurveOnSurface::MaxDistance, "Returns max distance");
	cls_BRepLib_CheckCurveOnSurface.def("MaxParameter", (Standard_Real (BRepLib_CheckCurveOnSurface::*)() const ) &BRepLib_CheckCurveOnSurface::MaxParameter, "Returns parameter in which the distance is maximal");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepLib.hxx
	py::class_<BRepLib, std::unique_ptr<BRepLib, Deleter<BRepLib>>> cls_BRepLib(mod, "BRepLib", "The BRepLib package provides general utilities for BRep.");
	cls_BRepLib.def(py::init<>());
	cls_BRepLib.def_static("Precision_", (void (*)(const Standard_Real)) &BRepLib::Precision, "Computes the max distance between edge and its 2d representation on the face. Sets the default precision. The current Precision is returned.", py::arg("P"));
	cls_BRepLib.def_static("Precision_", (Standard_Real (*)()) &BRepLib::Precision, "Returns the default precision.");
	cls_BRepLib.def_static("Plane_", (void (*)(const opencascade::handle<Geom_Plane> &)) &BRepLib::Plane, "Sets the current plane to P.", py::arg("P"));
	cls_BRepLib.def_static("Plane_", (const opencascade::handle<Geom_Plane> & (*)()) &BRepLib::Plane, "Returns the current plane.");
	cls_BRepLib.def_static("CheckSameRange_", [](const TopoDS_Edge & a0) -> Standard_Boolean { return BRepLib::CheckSameRange(a0); }, py::arg("E"));
	cls_BRepLib.def_static("CheckSameRange_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real)) &BRepLib::CheckSameRange, "checks if the Edge is same range IGNORING the same range flag of the edge Confusion argument is to compare real numbers idenpendently of any model space tolerance", py::arg("E"), py::arg("Confusion"));
	cls_BRepLib.def_static("SameRange_", [](const TopoDS_Edge & a0) -> void { return BRepLib::SameRange(a0); }, py::arg("E"));
	cls_BRepLib.def_static("SameRange_", (void (*)(const TopoDS_Edge &, const Standard_Real)) &BRepLib::SameRange, "will make all the curve representation have the same range domain for the parameters. This will IGNORE the same range flag value to proceed. If there is a 3D curve there it will the range of that curve. If not the first curve representation encountered in the list will give its range to the all the other curves.", py::arg("E"), py::arg("Tolerance"));
	cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0); }, py::arg("E"));
	cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0, const Standard_Real a1) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0, a1); }, py::arg("E"), py::arg("Tolerance"));
	cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0, const Standard_Real a1, const GeomAbs_Shape a2) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0, a1, a2); }, py::arg("E"), py::arg("Tolerance"), py::arg("Continuity"));
	cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0, const Standard_Real a1, const GeomAbs_Shape a2, const Standard_Integer a3) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0, a1, a2, a3); }, py::arg("E"), py::arg("Tolerance"), py::arg("Continuity"), py::arg("MaxDegree"));
	cls_BRepLib.def_static("BuildCurve3d_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &BRepLib::BuildCurve3d, "Computes the 3d curve for the edge <E> if it does not exist. Returns True if the curve was computed or existed. Returns False if there is no planar pcurve or the computation failed. <MaxSegment> >= 30 in approximation", py::arg("E"), py::arg("Tolerance"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegment"));
	cls_BRepLib.def_static("BuildCurves3d_", [](const TopoDS_Shape & a0, const Standard_Real a1) -> Standard_Boolean { return BRepLib::BuildCurves3d(a0, a1); }, py::arg("S"), py::arg("Tolerance"));
	cls_BRepLib.def_static("BuildCurves3d_", [](const TopoDS_Shape & a0, const Standard_Real a1, const GeomAbs_Shape a2) -> Standard_Boolean { return BRepLib::BuildCurves3d(a0, a1, a2); }, py::arg("S"), py::arg("Tolerance"), py::arg("Continuity"));
	cls_BRepLib.def_static("BuildCurves3d_", [](const TopoDS_Shape & a0, const Standard_Real a1, const GeomAbs_Shape a2, const Standard_Integer a3) -> Standard_Boolean { return BRepLib::BuildCurves3d(a0, a1, a2, a3); }, py::arg("S"), py::arg("Tolerance"), py::arg("Continuity"), py::arg("MaxDegree"));
	cls_BRepLib.def_static("BuildCurves3d_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &BRepLib::BuildCurves3d, "Computes the 3d curves for all the edges of <S> return False if one of the computation failed. <MaxSegment> >= 30 in approximation", py::arg("S"), py::arg("Tolerance"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegment"));
	cls_BRepLib.def_static("BuildCurves3d_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BRepLib::BuildCurves3d, "Computes the 3d curves for all the edges of <S> return False if one of the computation failed.", py::arg("S"));
	cls_BRepLib.def_static("UpdateEdgeTol_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &BRepLib::UpdateEdgeTol, "Checks if the edge has a Tolerance smaller than -- -- -- -- MaxToleranceToCheck if so it will compute the radius of -- the cylindrical pipe surface that MinToleranceRequest is the minimum tolerance before it is usefull to start testing. Usually it should be arround 10e-5 contains all -- the curve represenation of the edge returns True if the Edge tolerance had to be updated", py::arg("E"), py::arg("MinToleranceRequest"), py::arg("MaxToleranceToCheck"));
	cls_BRepLib.def_static("UpdateEdgeTolerance_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real)) &BRepLib::UpdateEdgeTolerance, "-- Checks all the edges of the shape whose -- -- -- Tolerance is smaller than MaxToleranceToCheck -- Returns True if at least one edge was updated -- MinToleranceRequest is the minimum tolerance before -- it -- is usefull to start testing. Usually it should be arround -- 10e-5--", py::arg("S"), py::arg("MinToleranceRequest"), py::arg("MaxToleranceToCheck"));
	cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Edge & a0) -> void { return BRepLib::SameParameter(a0); }, py::arg("theEdge"));
	cls_BRepLib.def_static("SameParameter_", (void (*)(const TopoDS_Edge &, const Standard_Real)) &BRepLib::SameParameter, "Computes new 2d curve(s) for the edge <theEdge> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on the Edge.", py::arg("theEdge"), py::arg("Tolerance"));
	cls_BRepLib.def_static("SameParameter_", (TopoDS_Edge (*)(const TopoDS_Edge &, const Standard_Real, Standard_Real &, const Standard_Boolean)) &BRepLib::SameParameter, "Computes new 2d curve(s) for the edge <theEdge> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on the Edge. theNewTol is a new tolerance of vertices of the input edge (not applied inside the algorithm, but pre-computed). If IsUseOldEdge is true then the input edge will be modified, otherwise the new copy of input edge will be created. Returns the new edge as a result, can be ignored if IsUseOldEdge is true.", py::arg("theEdge"), py::arg("theTolerance"), py::arg("theNewTol"), py::arg("IsUseOldEdge"));
	cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0) -> void { return BRepLib::SameParameter(a0); }, py::arg("S"));
	cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0, const Standard_Real a1) -> void { return BRepLib::SameParameter(a0, a1); }, py::arg("S"), py::arg("Tolerance"));
	cls_BRepLib.def_static("SameParameter_", (void (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Boolean)) &BRepLib::SameParameter, "Computes new 2d curve(s) for all the edges of <S> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on an Edge.", py::arg("S"), py::arg("Tolerance"), py::arg("forced"));
	cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0, BRepTools_ReShape & a1) -> void { return BRepLib::SameParameter(a0, a1); }, py::arg("S"), py::arg("theReshaper"));
	cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0, BRepTools_ReShape & a1, const Standard_Real a2) -> void { return BRepLib::SameParameter(a0, a1, a2); }, py::arg("S"), py::arg("theReshaper"), py::arg("Tolerance"));
	cls_BRepLib.def_static("SameParameter_", (void (*)(const TopoDS_Shape &, BRepTools_ReShape &, const Standard_Real, const Standard_Boolean)) &BRepLib::SameParameter, "Computes new 2d curve(s) for all the edges of <S> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on an Edge. theReshaper is used to record the modifications of input shape <S> to prevent any modifications on the shape itself. Thus the input shape (and its subshapes) will not be modified, instead the reshaper will contain a modified empty-copies of original subshapes as substitutions.", py::arg("S"), py::arg("theReshaper"), py::arg("Tolerance"), py::arg("forced"));
	cls_BRepLib.def_static("UpdateTolerances_", [](const TopoDS_Shape & a0) -> void { return BRepLib::UpdateTolerances(a0); }, py::arg("S"));
	cls_BRepLib.def_static("UpdateTolerances_", (void (*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepLib::UpdateTolerances, "Replaces tolerance of FACE EDGE VERTEX by the tolerance Max of their connected handling shapes. It is not necessary to use this call after SameParameter. (called in)", py::arg("S"), py::arg("verifyFaceTolerance"));
	cls_BRepLib.def_static("UpdateTolerances_", [](const TopoDS_Shape & a0, BRepTools_ReShape & a1) -> void { return BRepLib::UpdateTolerances(a0, a1); }, py::arg("S"), py::arg("theReshaper"));
	cls_BRepLib.def_static("UpdateTolerances_", (void (*)(const TopoDS_Shape &, BRepTools_ReShape &, const Standard_Boolean)) &BRepLib::UpdateTolerances, "Replaces tolerance of FACE EDGE VERTEX by the tolerance Max of their connected handling shapes. It is not necessary to use this call after SameParameter. (called in) theReshaper is used to record the modifications of input shape <S> to prevent any modifications on the shape itself. Thus the input shape (and its subshapes) will not be modified, instead the reshaper will contain a modified empty-copies of original subshapes as substitutions.", py::arg("S"), py::arg("theReshaper"), py::arg("verifyFaceTolerance"));
	cls_BRepLib.def_static("UpdateInnerTolerances_", (void (*)(const TopoDS_Shape &)) &BRepLib::UpdateInnerTolerances, "Checks tolerances of edges (including inner points) and vertices of a shape and updates them to satisfy 'SameParameter' condition", py::arg("S"));
	cls_BRepLib.def_static("OrientClosedSolid_", (Standard_Boolean (*)(TopoDS_Solid &)) &BRepLib::OrientClosedSolid, "Orients the solid forward and the shell with the orientation to have matter in the solid. Returns False if the solid is unOrientable (open or incoherent)", py::arg("solid"));
	cls_BRepLib.def_static("EncodeRegularity_", [](const TopoDS_Shape & a0) -> void { return BRepLib::EncodeRegularity(a0); }, py::arg("S"));
	cls_BRepLib.def_static("EncodeRegularity_", (void (*)(const TopoDS_Shape &, const Standard_Real)) &BRepLib::EncodeRegularity, "Encodes the Regularity of edges on a Shape. Warning: <TolAng> is an angular tolerance, expressed in Rad. Warning: If the edges's regularity are coded before, nothing is done.", py::arg("S"), py::arg("TolAng"));
	cls_BRepLib.def_static("EncodeRegularity_", [](const TopoDS_Shape & a0, const TopTools_ListOfShape & a1) -> void { return BRepLib::EncodeRegularity(a0, a1); }, py::arg("S"), py::arg("LE"));
	cls_BRepLib.def_static("EncodeRegularity_", (void (*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real)) &BRepLib::EncodeRegularity, "Encodes the Regularity of edges in list <LE> on the shape <S> Warning: <TolAng> is an angular tolerance, expressed in Rad. Warning: If the edges's regularity are coded before, nothing is done.", py::arg("S"), py::arg("LE"), py::arg("TolAng"));
	cls_BRepLib.def_static("EncodeRegularity_", [](TopoDS_Edge & a0, const TopoDS_Face & a1, const TopoDS_Face & a2) -> void { return BRepLib::EncodeRegularity(a0, a1, a2); }, py::arg("E"), py::arg("F1"), py::arg("F2"));
	cls_BRepLib.def_static("EncodeRegularity_", (void (*)(TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real)) &BRepLib::EncodeRegularity, "Encodes the Regularity beetween <F1> and <F2> by <E> Warning: <TolAng> is an angular tolerance, expressed in Rad. Warning: If the edge's regularity is coded before, nothing is done.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("TolAng"));
	cls_BRepLib.def_static("SortFaces_", (void (*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepLib::SortFaces, "Sorts in LF the Faces of S on the complexity of their surfaces (Plane,Cylinder,Cone,Sphere,Torus,other)", py::arg("S"), py::arg("LF"));
	cls_BRepLib.def_static("ReverseSortFaces_", (void (*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepLib::ReverseSortFaces, "Sorts in LF the Faces of S on the reverse complexity of their surfaces (other,Torus,Sphere,Cone,Cylinder,Plane)", py::arg("S"), py::arg("LF"));
	cls_BRepLib.def_static("EnsureNormalConsistency_", [](const TopoDS_Shape & a0) -> Standard_Boolean { return BRepLib::EnsureNormalConsistency(a0); }, py::arg("S"));
	cls_BRepLib.def_static("EnsureNormalConsistency_", [](const TopoDS_Shape & a0, const Standard_Real a1) -> Standard_Boolean { return BRepLib::EnsureNormalConsistency(a0, a1); }, py::arg("S"), py::arg("theAngTol"));
	cls_BRepLib.def_static("EnsureNormalConsistency_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Boolean)) &BRepLib::EnsureNormalConsistency, "Corrects the normals in Poly_Triangulation of faces, in such way that normals at nodes lying along smooth edges have the same value on both adjacent triangulations. Returns TRUE if any correction is done.", py::arg("S"), py::arg("theAngTol"), py::arg("ForceComputeNormals"));
	cls_BRepLib.def_static("BoundingVertex_", (void (*)(const NCollection_List<TopoDS_Shape> &, gp_Pnt &, Standard_Real &)) &BRepLib::BoundingVertex, "Calculates the bounding sphere around the set of vertexes from the theLV list. Returns the center (theNewCenter) and the radius (theNewTol) of this sphere. This can be used to construct the new vertex which covers the given set of other vertices.", py::arg("theLV"), py::arg("theNewCenter"), py::arg("theNewTol"));
	cls_BRepLib.def_static("FindValidRange_", (Standard_Boolean (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const gp_Pnt &, const Standard_Real, const Standard_Real, const gp_Pnt &, const Standard_Real, Standard_Real &, Standard_Real &)) &BRepLib::FindValidRange, "For an edge defined by 3d curve and tolerance and vertices defined by points, parameters on curve and tolerances, finds a range of curve between vertices not covered by vertices tolerances. Returns false if there is no such range. Otherwise, sets theFirst and theLast as its bounds.", py::arg("theCurve"), py::arg("theTolE"), py::arg("theParV1"), py::arg("thePntV1"), py::arg("theTolV1"), py::arg("theParV2"), py::arg("thePntV2"), py::arg("theTolV2"), py::arg("theFirst"), py::arg("theLast"));
	cls_BRepLib.def_static("FindValidRange_", (Standard_Boolean (*)(const TopoDS_Edge &, Standard_Real &, Standard_Real &)) &BRepLib::FindValidRange, "Finds a range of 3d curve of the edge not covered by vertices tolerances. Returns false if there is no such range. Otherwise, sets theFirst and theLast as its bounds.", py::arg("theEdge"), py::arg("theFirst"), py::arg("theLast"));


}
