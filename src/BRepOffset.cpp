#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BRepOffset_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepOffset_Interval.hxx>
#include <NCollection_BaseList.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <BRepOffset_ListOfInterval.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <BRepOffset_DataMapOfShapeListOfInterval.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Compound.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepOffset_Analyse.hxx>
#include <BRepOffset_Status.hxx>
#include <GeomAbs_JoinType.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <GeomAbs_Shape.hxx>
#include <BRepOffset_Offset.hxx>
#include <BRepOffset_DataMapOfShapeOffset.hxx>
#include <BRepAlgo_AsDes.hxx>
#include <TopAbs_State.hxx>
#include <BRepAlgo_Image.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BRepOffset_Inter3d.hxx>
#include <Geom_Surface.hxx>
#include <BRepOffset.hxx>
#include <BRepOffset_Mode.hxx>
#include <BRepOffset_Error.hxx>
#include <BRepOffset_MakeLoops.hxx>
#include <BRepOffset_MakeOffset.hxx>
#include <BRepOffset_MakeSimpleOffset.hxx>
#include <TCollection_AsciiString.hxx>
#include <BRepOffset_DataMapOfShapeMapOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <BRepOffset_Inter2d.hxx>
#include <BRepTools_Modification.hxx>
#include <Standard_Type.hxx>
#include <TopLoc_Location.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pnt.hxx>
#include <Geom2d_Curve.hxx>
#include <BRepOffset_SimpleOffset.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Wire.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepOffset_Tool.hxx>

PYBIND11_MODULE(BRepOffset, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.BRepAlgo");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.BRepTools");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom2d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_Type.hxx
	py::enum_<BRepOffset_Type>(mod, "BRepOffset_Type", "None")
		.value("BRepOffset_Concave", BRepOffset_Type::BRepOffset_Concave)
		.value("BRepOffset_Convex", BRepOffset_Type::BRepOffset_Convex)
		.value("BRepOffset_Tangent", BRepOffset_Type::BRepOffset_Tangent)
		.value("BRepOffset_FreeBoundary", BRepOffset_Type::BRepOffset_FreeBoundary)
		.value("BRepOffset_Other", BRepOffset_Type::BRepOffset_Other)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_Status.hxx
	py::enum_<BRepOffset_Status>(mod, "BRepOffset_Status", "status of an offset face Good : Reversed : e.g. Offset > Radius of a cylinder Degenerated : e.g. Offset = Radius of a cylinder Unknown : e.g. for a Beziersurf")
		.value("BRepOffset_Good", BRepOffset_Status::BRepOffset_Good)
		.value("BRepOffset_Reversed", BRepOffset_Status::BRepOffset_Reversed)
		.value("BRepOffset_Degenerated", BRepOffset_Status::BRepOffset_Degenerated)
		.value("BRepOffset_Unknown", BRepOffset_Status::BRepOffset_Unknown)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_Mode.hxx
	py::enum_<BRepOffset_Mode>(mod, "BRepOffset_Mode", "Lists the offset modes. These are the following: - BRepOffset_Skin which describes the offset along the surface of a solid, used to obtain a manifold topological space, - BRepOffset_Pipe which describes the offset of a curve, used to obtain a pre-surface, - BRepOffset_RectoVerso which describes the offset of a given surface shell along both sides of the surface.")
		.value("BRepOffset_Skin", BRepOffset_Mode::BRepOffset_Skin)
		.value("BRepOffset_Pipe", BRepOffset_Mode::BRepOffset_Pipe)
		.value("BRepOffset_RectoVerso", BRepOffset_Mode::BRepOffset_RectoVerso)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_Error.hxx
	py::enum_<BRepOffset_Error>(mod, "BRepOffset_Error", "None")
		.value("BRepOffset_NoError", BRepOffset_Error::BRepOffset_NoError)
		.value("BRepOffset_UnknownError", BRepOffset_Error::BRepOffset_UnknownError)
		.value("BRepOffset_BadNormalsOnGeometry", BRepOffset_Error::BRepOffset_BadNormalsOnGeometry)
		.value("BRepOffset_C0Geometry", BRepOffset_Error::BRepOffset_C0Geometry)
		.value("BRepOffset_NullOffset", BRepOffset_Error::BRepOffset_NullOffset)
		.value("BRepOffset_NotConnectedShell", BRepOffset_Error::BRepOffset_NotConnectedShell)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_MakeSimpleOffset.hxx
	py::enum_<BRepOffsetSimple_Status>(mod, "BRepOffsetSimple_Status", "None")
		.value("BRepOffsetSimple_OK", BRepOffsetSimple_Status::BRepOffsetSimple_OK)
		.value("BRepOffsetSimple_NullInputShape", BRepOffsetSimple_Status::BRepOffsetSimple_NullInputShape)
		.value("BRepOffsetSimple_ErrorOffsetComputation", BRepOffsetSimple_Status::BRepOffsetSimple_ErrorOffsetComputation)
		.value("BRepOffsetSimple_ErrorWallFaceComputation", BRepOffsetSimple_Status::BRepOffsetSimple_ErrorWallFaceComputation)
		.value("BRepOffsetSimple_ErrorInvalidNbShells", BRepOffsetSimple_Status::BRepOffsetSimple_ErrorInvalidNbShells)
		.value("BRepOffsetSimple_ErrorNonClosedShell", BRepOffsetSimple_Status::BRepOffsetSimple_ErrorNonClosedShell)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_Interval.hxx
	py::class_<BRepOffset_Interval, std::unique_ptr<BRepOffset_Interval, Deleter<BRepOffset_Interval>>> cls_BRepOffset_Interval(mod, "BRepOffset_Interval", "None");
	cls_BRepOffset_Interval.def(py::init<>());
	cls_BRepOffset_Interval.def(py::init<const Standard_Real, const Standard_Real, const BRepOffset_Type>(), py::arg("U1"), py::arg("U2"), py::arg("Type"));
	cls_BRepOffset_Interval.def("First", (void (BRepOffset_Interval::*)(const Standard_Real)) &BRepOffset_Interval::First, "None", py::arg("U"));
	cls_BRepOffset_Interval.def("Last", (void (BRepOffset_Interval::*)(const Standard_Real)) &BRepOffset_Interval::Last, "None", py::arg("U"));
	cls_BRepOffset_Interval.def("Type", (void (BRepOffset_Interval::*)(const BRepOffset_Type)) &BRepOffset_Interval::Type, "None", py::arg("T"));
	cls_BRepOffset_Interval.def("First", (Standard_Real (BRepOffset_Interval::*)() const ) &BRepOffset_Interval::First, "None");
	cls_BRepOffset_Interval.def("Last", (Standard_Real (BRepOffset_Interval::*)() const ) &BRepOffset_Interval::Last, "None");
	cls_BRepOffset_Interval.def("Type", (BRepOffset_Type (BRepOffset_Interval::*)() const ) &BRepOffset_Interval::Type, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_Analyse.hxx
	py::class_<BRepOffset_Analyse, std::unique_ptr<BRepOffset_Analyse, Deleter<BRepOffset_Analyse>>> cls_BRepOffset_Analyse(mod, "BRepOffset_Analyse", "Analyse of a shape consit to Find the part of edges convex concave tangent.");
	cls_BRepOffset_Analyse.def(py::init<>());
	cls_BRepOffset_Analyse.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("S"), py::arg("Angle"));
	cls_BRepOffset_Analyse.def("Perform", (void (BRepOffset_Analyse::*)(const TopoDS_Shape &, const Standard_Real)) &BRepOffset_Analyse::Perform, "None", py::arg("S"), py::arg("Angle"));
	cls_BRepOffset_Analyse.def("IsDone", (Standard_Boolean (BRepOffset_Analyse::*)() const ) &BRepOffset_Analyse::IsDone, "None");
	cls_BRepOffset_Analyse.def("Clear", (void (BRepOffset_Analyse::*)()) &BRepOffset_Analyse::Clear, "None");
	cls_BRepOffset_Analyse.def("Type", (const BRepOffset_ListOfInterval & (BRepOffset_Analyse::*)(const TopoDS_Edge &) const ) &BRepOffset_Analyse::Type, "None", py::arg("E"));
	cls_BRepOffset_Analyse.def("Edges", (void (BRepOffset_Analyse::*)(const TopoDS_Vertex &, const BRepOffset_Type, TopTools_ListOfShape &) const ) &BRepOffset_Analyse::Edges, "Stores in <L> all the edges of Type <T> on the vertex <V>.", py::arg("V"), py::arg("T"), py::arg("L"));
	cls_BRepOffset_Analyse.def("Edges", (void (BRepOffset_Analyse::*)(const TopoDS_Face &, const BRepOffset_Type, TopTools_ListOfShape &) const ) &BRepOffset_Analyse::Edges, "Stores in <L> all the edges of Type <T> on the face <F>.", py::arg("F"), py::arg("T"), py::arg("L"));
	cls_BRepOffset_Analyse.def("TangentEdges", (void (BRepOffset_Analyse::*)(const TopoDS_Edge &, const TopoDS_Vertex &, TopTools_ListOfShape &) const ) &BRepOffset_Analyse::TangentEdges, "set in <Edges> all the Edges of <Shape> which are tangent to <Edge> at the vertex <Vertex>.", py::arg("Edge"), py::arg("Vertex"), py::arg("Edges"));
	cls_BRepOffset_Analyse.def("HasAncestor", (Standard_Boolean (BRepOffset_Analyse::*)(const TopoDS_Shape &) const ) &BRepOffset_Analyse::HasAncestor, "None", py::arg("S"));
	cls_BRepOffset_Analyse.def("Ancestors", (const TopTools_ListOfShape & (BRepOffset_Analyse::*)(const TopoDS_Shape &) const ) &BRepOffset_Analyse::Ancestors, "None", py::arg("S"));
	cls_BRepOffset_Analyse.def("Explode", (void (BRepOffset_Analyse::*)(TopTools_ListOfShape &, const BRepOffset_Type) const ) &BRepOffset_Analyse::Explode, "Explode in compounds of faces where all the connex edges are of type <Side>", py::arg("L"), py::arg("Type"));
	cls_BRepOffset_Analyse.def("Explode", (void (BRepOffset_Analyse::*)(TopTools_ListOfShape &, const BRepOffset_Type, const BRepOffset_Type) const ) &BRepOffset_Analyse::Explode, "Explode in compounds of faces where all the connex edges are of type <Side1> or <Side2>", py::arg("L"), py::arg("Type1"), py::arg("Type2"));
	cls_BRepOffset_Analyse.def("AddFaces", (void (BRepOffset_Analyse::*)(const TopoDS_Face &, TopoDS_Compound &, TopTools_MapOfShape &, const BRepOffset_Type) const ) &BRepOffset_Analyse::AddFaces, "Add in <CO> the faces of the shell containing <Face> where all the connex edges are of type <Side>.", py::arg("Face"), py::arg("Co"), py::arg("Map"), py::arg("Type"));
	cls_BRepOffset_Analyse.def("AddFaces", (void (BRepOffset_Analyse::*)(const TopoDS_Face &, TopoDS_Compound &, TopTools_MapOfShape &, const BRepOffset_Type, const BRepOffset_Type) const ) &BRepOffset_Analyse::AddFaces, "Add in <CO> the faces of the shell containing <Face> where all the connex edges are of type <Side1> or <Side2>.", py::arg("Face"), py::arg("Co"), py::arg("Map"), py::arg("Type1"), py::arg("Type2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_Offset.hxx
	py::class_<BRepOffset_Offset, std::unique_ptr<BRepOffset_Offset, Deleter<BRepOffset_Offset>>> cls_BRepOffset_Offset(mod, "BRepOffset_Offset", "This class compute elemenary offset surface. Evaluate the offset generated : 1 - from a face. 2 - from an edge. 3 - from a vertex.");
	cls_BRepOffset_Offset.def(py::init<>());
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("Face"), py::arg("Offset"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Boolean>(), py::arg("Face"), py::arg("Offset"), py::arg("OffsetOutside"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Boolean, const GeomAbs_JoinType>(), py::arg("Face"), py::arg("Offset"), py::arg("OffsetOutside"), py::arg("JoinType"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real, const TopTools_DataMapOfShapeShape &>(), py::arg("Face"), py::arg("Offset"), py::arg("Created"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real, const TopTools_DataMapOfShapeShape &, const Standard_Boolean>(), py::arg("Face"), py::arg("Offset"), py::arg("Created"), py::arg("OffsetOutside"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real, const TopTools_DataMapOfShapeShape &, const Standard_Boolean, const GeomAbs_JoinType>(), py::arg("Face"), py::arg("Offset"), py::arg("Created"), py::arg("OffsetOutside"), py::arg("JoinType"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Boolean>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("Polynomial"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"), py::arg("Polynomial"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean, const Standard_Real>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"), py::arg("Polynomial"), py::arg("Tol"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Vertex &, const TopTools_ListOfShape &, const Standard_Real>(), py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Vertex &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Boolean>(), py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"), py::arg("Polynomial"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Vertex &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"));
	cls_BRepOffset_Offset.def(py::init<const TopoDS_Vertex &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape>(), py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Face & a0, const Standard_Real a1) -> void { return self.Init(a0, a1); }, py::arg("Face"), py::arg("Offset"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Face & a0, const Standard_Real a1, const Standard_Boolean a2) -> void { return self.Init(a0, a1, a2); }, py::arg("Face"), py::arg("Offset"), py::arg("OffsetOutside"));
	cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Face &, const Standard_Real, const Standard_Boolean, const GeomAbs_JoinType)) &BRepOffset_Offset::Init, "None", py::arg("Face"), py::arg("Offset"), py::arg("OffsetOutside"), py::arg("JoinType"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Face & a0, const Standard_Real a1, const TopTools_DataMapOfShapeShape & a2) -> void { return self.Init(a0, a1, a2); }, py::arg("Face"), py::arg("Offset"), py::arg("Created"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Face & a0, const Standard_Real a1, const TopTools_DataMapOfShapeShape & a2, const Standard_Boolean a3) -> void { return self.Init(a0, a1, a2, a3); }, py::arg("Face"), py::arg("Offset"), py::arg("Created"), py::arg("OffsetOutside"));
	cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Face &, const Standard_Real, const TopTools_DataMapOfShapeShape &, const Standard_Boolean, const GeomAbs_JoinType)) &BRepOffset_Offset::Init, "None", py::arg("Face"), py::arg("Offset"), py::arg("Created"), py::arg("OffsetOutside"), py::arg("JoinType"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); }, py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3, const Standard_Boolean a4) -> void { return self.Init(a0, a1, a2, a3, a4); }, py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("Polynomial"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3, const Standard_Boolean a4, const Standard_Real a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); }, py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"));
	cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape)) &BRepOffset_Offset::Init, "None", py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3, const TopoDS_Edge & a4, const TopoDS_Edge & a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); }, py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3, const TopoDS_Edge & a4, const TopoDS_Edge & a5, const Standard_Boolean a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); }, py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"), py::arg("Polynomial"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3, const TopoDS_Edge & a4, const TopoDS_Edge & a5, const Standard_Boolean a6, const Standard_Real a7) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"), py::arg("Polynomial"), py::arg("Tol"));
	cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape)) &BRepOffset_Offset::Init, "None", py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Vertex & a0, const TopTools_ListOfShape & a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); }, py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Vertex & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Boolean a3) -> void { return self.Init(a0, a1, a2, a3); }, py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"), py::arg("Polynomial"));
	cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Vertex & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Boolean a3, const Standard_Real a4) -> void { return self.Init(a0, a1, a2, a3, a4); }, py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"));
	cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Vertex &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape)) &BRepOffset_Offset::Init, "Tol and Conti are only used if Polynomial is True (Used to perfrom the approximation)", py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));
	cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Edge &, const Standard_Real)) &BRepOffset_Offset::Init, "Only used in Rolling Ball. Pipe on Free Boundary", py::arg("Edge"), py::arg("Offset"));
	cls_BRepOffset_Offset.def("InitialShape", (const TopoDS_Shape & (BRepOffset_Offset::*)() const ) &BRepOffset_Offset::InitialShape, "None");
	cls_BRepOffset_Offset.def("Face", (const TopoDS_Face & (BRepOffset_Offset::*)() const ) &BRepOffset_Offset::Face, "None");
	cls_BRepOffset_Offset.def("Generated", (TopoDS_Shape (BRepOffset_Offset::*)(const TopoDS_Shape &) const ) &BRepOffset_Offset::Generated, "None", py::arg("Shape"));
	cls_BRepOffset_Offset.def("Status", (BRepOffset_Status (BRepOffset_Offset::*)() const ) &BRepOffset_Offset::Status, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_Inter3d.hxx
	py::class_<BRepOffset_Inter3d, std::unique_ptr<BRepOffset_Inter3d, Deleter<BRepOffset_Inter3d>>> cls_BRepOffset_Inter3d(mod, "BRepOffset_Inter3d", "Computes the intersection face face in a set of faces Store the result in a SD as AsDes.");
	cls_BRepOffset_Inter3d.def(py::init<const opencascade::handle<BRepAlgo_AsDes> &, const TopAbs_State, const Standard_Real>(), py::arg("AsDes"), py::arg("Side"), py::arg("Tol"));
	cls_BRepOffset_Inter3d.def("CompletInt", (void (BRepOffset_Inter3d::*)(const TopTools_ListOfShape &, const BRepAlgo_Image &)) &BRepOffset_Inter3d::CompletInt, "None", py::arg("SetOfFaces"), py::arg("InitOffsetFace"));
	cls_BRepOffset_Inter3d.def("FaceInter", (void (BRepOffset_Inter3d::*)(const TopoDS_Face &, const TopoDS_Face &, const BRepAlgo_Image &)) &BRepOffset_Inter3d::FaceInter, "None", py::arg("F1"), py::arg("F2"), py::arg("InitOffsetFace"));
	cls_BRepOffset_Inter3d.def("ConnexIntByArc", (void (BRepOffset_Inter3d::*)(const TopTools_ListOfShape &, const TopoDS_Shape &, const BRepOffset_Analyse &, const BRepAlgo_Image &)) &BRepOffset_Inter3d::ConnexIntByArc, "None", py::arg("SetOfFaces"), py::arg("ShapeInit"), py::arg("Analyse"), py::arg("InitOffsetFace"));
	cls_BRepOffset_Inter3d.def("ConnexIntByInt", [](BRepOffset_Inter3d &self, const TopoDS_Shape & a0, const BRepOffset_DataMapOfShapeOffset & a1, const BRepOffset_Analyse & a2, TopTools_DataMapOfShapeShape & a3, TopTools_DataMapOfShapeShape & a4, TopTools_ListOfShape & a5) -> void { return self.ConnexIntByInt(a0, a1, a2, a3, a4, a5); }, py::arg("SI"), py::arg("MapSF"), py::arg("A"), py::arg("MES"), py::arg("Build"), py::arg("Failed"));
	cls_BRepOffset_Inter3d.def("ConnexIntByInt", (void (BRepOffset_Inter3d::*)(const TopoDS_Shape &, const BRepOffset_DataMapOfShapeOffset &, const BRepOffset_Analyse &, TopTools_DataMapOfShapeShape &, TopTools_DataMapOfShapeShape &, TopTools_ListOfShape &, const Standard_Boolean)) &BRepOffset_Inter3d::ConnexIntByInt, "None", py::arg("SI"), py::arg("MapSF"), py::arg("A"), py::arg("MES"), py::arg("Build"), py::arg("Failed"), py::arg("bIsPlanar"));
	cls_BRepOffset_Inter3d.def("ContextIntByInt", [](BRepOffset_Inter3d &self, const TopTools_IndexedMapOfShape & a0, const Standard_Boolean a1, const BRepOffset_DataMapOfShapeOffset & a2, const BRepOffset_Analyse & a3, TopTools_DataMapOfShapeShape & a4, TopTools_DataMapOfShapeShape & a5, TopTools_ListOfShape & a6) -> void { return self.ContextIntByInt(a0, a1, a2, a3, a4, a5, a6); }, py::arg("ContextFaces"), py::arg("ExtentContext"), py::arg("MapSF"), py::arg("A"), py::arg("MES"), py::arg("Build"), py::arg("Failed"));
	cls_BRepOffset_Inter3d.def("ContextIntByInt", (void (BRepOffset_Inter3d::*)(const TopTools_IndexedMapOfShape &, const Standard_Boolean, const BRepOffset_DataMapOfShapeOffset &, const BRepOffset_Analyse &, TopTools_DataMapOfShapeShape &, TopTools_DataMapOfShapeShape &, TopTools_ListOfShape &, const Standard_Boolean)) &BRepOffset_Inter3d::ContextIntByInt, "None", py::arg("ContextFaces"), py::arg("ExtentContext"), py::arg("MapSF"), py::arg("A"), py::arg("MES"), py::arg("Build"), py::arg("Failed"), py::arg("bIsPlanar"));
	cls_BRepOffset_Inter3d.def("ContextIntByArc", (void (BRepOffset_Inter3d::*)(const TopTools_IndexedMapOfShape &, const Standard_Boolean, const BRepOffset_Analyse &, const BRepAlgo_Image &, BRepAlgo_Image &)) &BRepOffset_Inter3d::ContextIntByArc, "None", py::arg("ContextFaces"), py::arg("ExtentContext"), py::arg("Analyse"), py::arg("InitOffsetFace"), py::arg("InitOffsetEdge"));
	cls_BRepOffset_Inter3d.def("AddCommonEdges", (void (BRepOffset_Inter3d::*)(const TopTools_ListOfShape &)) &BRepOffset_Inter3d::AddCommonEdges, "None", py::arg("SetOfFaces"));
	cls_BRepOffset_Inter3d.def("SetDone", (void (BRepOffset_Inter3d::*)(const TopoDS_Face &, const TopoDS_Face &)) &BRepOffset_Inter3d::SetDone, "None", py::arg("F1"), py::arg("F2"));
	cls_BRepOffset_Inter3d.def("IsDone", (Standard_Boolean (BRepOffset_Inter3d::*)(const TopoDS_Face &, const TopoDS_Face &) const ) &BRepOffset_Inter3d::IsDone, "None", py::arg("F1"), py::arg("F2"));
	cls_BRepOffset_Inter3d.def("TouchedFaces", (TopTools_IndexedMapOfShape & (BRepOffset_Inter3d::*)()) &BRepOffset_Inter3d::TouchedFaces, "None");
	cls_BRepOffset_Inter3d.def("AsDes", (opencascade::handle<BRepAlgo_AsDes> (BRepOffset_Inter3d::*)() const ) &BRepOffset_Inter3d::AsDes, "None");
	cls_BRepOffset_Inter3d.def("NewEdges", (TopTools_IndexedMapOfShape & (BRepOffset_Inter3d::*)()) &BRepOffset_Inter3d::NewEdges, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset.hxx
	py::class_<BRepOffset, std::unique_ptr<BRepOffset, Deleter<BRepOffset>>> cls_BRepOffset(mod, "BRepOffset", "Auxiliary tools for offset algorithms");
	cls_BRepOffset.def(py::init<>());
	cls_BRepOffset.def_static("Surface_", [](const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, BRepOffset_Status & a2) -> opencascade::handle<Geom_Surface> { return BRepOffset::Surface(a0, a1, a2); }, py::arg("Surface"), py::arg("Offset"), py::arg("theStatus"));
	cls_BRepOffset.def_static("Surface_", (opencascade::handle<Geom_Surface> (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, BRepOffset_Status &, Standard_Boolean)) &BRepOffset::Surface, "returns the Offset surface computed from the surface <Surface> at an OffsetDistance <Offset>.", py::arg("Surface"), py::arg("Offset"), py::arg("theStatus"), py::arg("allowC0"));
	cls_BRepOffset.def_static("CollapseSingularities_", (opencascade::handle<Geom_Surface> (*)(const opencascade::handle<Geom_Surface> &, const TopoDS_Face &, Standard_Real)) &BRepOffset::CollapseSingularities, "Preprocess surface to be offset (bspline, bezier, or revolution based on bspline or bezier curve), by collapsing each singular side to single point.", py::arg("theSurface"), py::arg("theFace"), py::arg("thePrecision"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_MakeLoops.hxx
	py::class_<BRepOffset_MakeLoops, std::unique_ptr<BRepOffset_MakeLoops, Deleter<BRepOffset_MakeLoops>>> cls_BRepOffset_MakeLoops(mod, "BRepOffset_MakeLoops", "None");
	cls_BRepOffset_MakeLoops.def(py::init<>());
	cls_BRepOffset_MakeLoops.def("Build", (void (BRepOffset_MakeLoops::*)(const TopTools_ListOfShape &, const opencascade::handle<BRepAlgo_AsDes> &, BRepAlgo_Image &)) &BRepOffset_MakeLoops::Build, "None", py::arg("LF"), py::arg("AsDes"), py::arg("Image"));
	cls_BRepOffset_MakeLoops.def("BuildOnContext", (void (BRepOffset_MakeLoops::*)(const TopTools_ListOfShape &, const BRepOffset_Analyse &, const opencascade::handle<BRepAlgo_AsDes> &, BRepAlgo_Image &, const Standard_Boolean)) &BRepOffset_MakeLoops::BuildOnContext, "None", py::arg("LContext"), py::arg("Analyse"), py::arg("AsDes"), py::arg("Image"), py::arg("InSide"));
	cls_BRepOffset_MakeLoops.def("BuildFaces", (void (BRepOffset_MakeLoops::*)(const TopTools_ListOfShape &, const opencascade::handle<BRepAlgo_AsDes> &, BRepAlgo_Image &)) &BRepOffset_MakeLoops::BuildFaces, "None", py::arg("LF"), py::arg("AsDes"), py::arg("Image"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_MakeOffset.hxx
	py::class_<BRepOffset_MakeOffset, std::unique_ptr<BRepOffset_MakeOffset, Deleter<BRepOffset_MakeOffset>>> cls_BRepOffset_MakeOffset(mod, "BRepOffset_MakeOffset", "None");
	cls_BRepOffset_MakeOffset.def(py::init<>());
	cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"));
	cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"));
	cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"));
	cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"));
	cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"));
	cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("Thickening"));
	cls_BRepOffset_MakeOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("Thickening"), py::arg("RemoveIntEdges"));
	cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); }, py::arg("S"), py::arg("Offset"), py::arg("Tol"));
	cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3) -> void { return self.Initialize(a0, a1, a2, a3); }, py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"));
	cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4) -> void { return self.Initialize(a0, a1, a2, a3, a4); }, py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"));
	cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4, const Standard_Boolean a5) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5); }, py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"));
	cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4, const Standard_Boolean a5, const GeomAbs_JoinType a6) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5, a6); }, py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"));
	cls_BRepOffset_MakeOffset.def("Initialize", [](BRepOffset_MakeOffset &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4, const Standard_Boolean a5, const GeomAbs_JoinType a6, const Standard_Boolean a7) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("Thickening"));
	cls_BRepOffset_MakeOffset.def("Initialize", (void (BRepOffset_MakeOffset::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean)) &BRepOffset_MakeOffset::Initialize, "None", py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("Thickening"), py::arg("RemoveIntEdges"));
	cls_BRepOffset_MakeOffset.def("Clear", (void (BRepOffset_MakeOffset::*)()) &BRepOffset_MakeOffset::Clear, "None");
	cls_BRepOffset_MakeOffset.def("AddFace", (void (BRepOffset_MakeOffset::*)(const TopoDS_Face &)) &BRepOffset_MakeOffset::AddFace, "Add Closing Faces, <F> has to be in the initial shape S.", py::arg("F"));
	cls_BRepOffset_MakeOffset.def("SetOffsetOnFace", (void (BRepOffset_MakeOffset::*)(const TopoDS_Face &, const Standard_Real)) &BRepOffset_MakeOffset::SetOffsetOnFace, "set the offset <Off> on the Face <F>", py::arg("F"), py::arg("Off"));
	cls_BRepOffset_MakeOffset.def("MakeOffsetShape", (void (BRepOffset_MakeOffset::*)()) &BRepOffset_MakeOffset::MakeOffsetShape, "None");
	cls_BRepOffset_MakeOffset.def("MakeThickSolid", (void (BRepOffset_MakeOffset::*)()) &BRepOffset_MakeOffset::MakeThickSolid, "None");
	cls_BRepOffset_MakeOffset.def("GetAnalyse", (const BRepOffset_Analyse & (BRepOffset_MakeOffset::*)() const ) &BRepOffset_MakeOffset::GetAnalyse, "None");
	cls_BRepOffset_MakeOffset.def("IsDone", (Standard_Boolean (BRepOffset_MakeOffset::*)() const ) &BRepOffset_MakeOffset::IsDone, "None");
	cls_BRepOffset_MakeOffset.def("Shape", (const TopoDS_Shape & (BRepOffset_MakeOffset::*)() const ) &BRepOffset_MakeOffset::Shape, "None");
	cls_BRepOffset_MakeOffset.def("Error", (BRepOffset_Error (BRepOffset_MakeOffset::*)() const ) &BRepOffset_MakeOffset::Error, "returns information about offset state.");
	cls_BRepOffset_MakeOffset.def("OffsetFacesFromShapes", (const BRepAlgo_Image & (BRepOffset_MakeOffset::*)() const ) &BRepOffset_MakeOffset::OffsetFacesFromShapes, "Returns <Image> containing links between initials shapes and offset faces.");
	cls_BRepOffset_MakeOffset.def("GetJoinType", (GeomAbs_JoinType (BRepOffset_MakeOffset::*)() const ) &BRepOffset_MakeOffset::GetJoinType, "Returns myJoin.");
	cls_BRepOffset_MakeOffset.def("OffsetEdgesFromShapes", (const BRepAlgo_Image & (BRepOffset_MakeOffset::*)() const ) &BRepOffset_MakeOffset::OffsetEdgesFromShapes, "Returns <Image> containing links between initials shapes and offset edges.");
	cls_BRepOffset_MakeOffset.def("ClosingFaces", (const TopTools_IndexedMapOfShape & (BRepOffset_MakeOffset::*)() const ) &BRepOffset_MakeOffset::ClosingFaces, "Returns the list of closing faces stores by AddFace");
	cls_BRepOffset_MakeOffset.def("CheckInputData", (Standard_Boolean (BRepOffset_MakeOffset::*)()) &BRepOffset_MakeOffset::CheckInputData, "Makes pre analysis of possibility offset perform. Use method Error() to get more information. Finds first error. List of checks: 1) Check for existence object with non-null offset. 2) Check for connectivity in offset shell. 3) Check continuity of input surfaces. 4) Check for normals existence on grid.");
	cls_BRepOffset_MakeOffset.def("GetBadShape", (const TopoDS_Shape & (BRepOffset_MakeOffset::*)() const ) &BRepOffset_MakeOffset::GetBadShape, "Return bad shape, which obtained in CheckInputData.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_MakeSimpleOffset.hxx
	py::class_<BRepOffset_MakeSimpleOffset, std::unique_ptr<BRepOffset_MakeSimpleOffset, Deleter<BRepOffset_MakeSimpleOffset>>> cls_BRepOffset_MakeSimpleOffset(mod, "BRepOffset_MakeSimpleOffset", "Limitations: According to the algorithm nature result depends on the smoothness of input data. Smooth (G1-continuity) input shape will lead to the good result.");
	cls_BRepOffset_MakeSimpleOffset.def(py::init<>());
	cls_BRepOffset_MakeSimpleOffset.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("theInputShape"), py::arg("theOffsetValue"));
	cls_BRepOffset_MakeSimpleOffset.def("Initialize", (void (BRepOffset_MakeSimpleOffset::*)(const TopoDS_Shape &, const Standard_Real)) &BRepOffset_MakeSimpleOffset::Initialize, "Initialies shape for modifications.", py::arg("theInputShape"), py::arg("theOffsetValue"));
	cls_BRepOffset_MakeSimpleOffset.def("Perform", (void (BRepOffset_MakeSimpleOffset::*)()) &BRepOffset_MakeSimpleOffset::Perform, "Computes offset shape.");
	cls_BRepOffset_MakeSimpleOffset.def("GetErrorMessage", (TCollection_AsciiString (BRepOffset_MakeSimpleOffset::*)() const ) &BRepOffset_MakeSimpleOffset::GetErrorMessage, "Gets error message.");
	cls_BRepOffset_MakeSimpleOffset.def("GetError", (BRepOffsetSimple_Status (BRepOffset_MakeSimpleOffset::*)() const ) &BRepOffset_MakeSimpleOffset::GetError, "Gets error code.");
	cls_BRepOffset_MakeSimpleOffset.def("GetBuildSolidFlag", (Standard_Boolean (BRepOffset_MakeSimpleOffset::*)() const ) &BRepOffset_MakeSimpleOffset::GetBuildSolidFlag, "Gets solid building flag.");
	cls_BRepOffset_MakeSimpleOffset.def("SetBuildSolidFlag", (void (BRepOffset_MakeSimpleOffset::*)(const Standard_Boolean)) &BRepOffset_MakeSimpleOffset::SetBuildSolidFlag, "Sets solid building flag.", py::arg("theBuildFlag"));
	cls_BRepOffset_MakeSimpleOffset.def("GetOffsetValue", (Standard_Real (BRepOffset_MakeSimpleOffset::*)() const ) &BRepOffset_MakeSimpleOffset::GetOffsetValue, "Gets offset value.");
	cls_BRepOffset_MakeSimpleOffset.def("SetOffsetValue", (void (BRepOffset_MakeSimpleOffset::*)(const Standard_Real)) &BRepOffset_MakeSimpleOffset::SetOffsetValue, "Sets offset value.", py::arg("theOffsetValue"));
	cls_BRepOffset_MakeSimpleOffset.def("GetTolerance", (Standard_Real (BRepOffset_MakeSimpleOffset::*)() const ) &BRepOffset_MakeSimpleOffset::GetTolerance, "Gets tolerance (used for handling singularities).");
	cls_BRepOffset_MakeSimpleOffset.def("SetTolerance", (void (BRepOffset_MakeSimpleOffset::*)(const Standard_Real)) &BRepOffset_MakeSimpleOffset::SetTolerance, "Sets tolerance (used for handling singularities).", py::arg("theValue"));
	cls_BRepOffset_MakeSimpleOffset.def("IsDone", (Standard_Boolean (BRepOffset_MakeSimpleOffset::*)() const ) &BRepOffset_MakeSimpleOffset::IsDone, "Gets done state.");
	cls_BRepOffset_MakeSimpleOffset.def("GetResultShape", (const TopoDS_Shape & (BRepOffset_MakeSimpleOffset::*)() const ) &BRepOffset_MakeSimpleOffset::GetResultShape, "Returns result shape.");
	cls_BRepOffset_MakeSimpleOffset.def("GetSafeOffset", (Standard_Real (BRepOffset_MakeSimpleOffset::*)(const Standard_Real)) &BRepOffset_MakeSimpleOffset::GetSafeOffset, "Computes max safe offset value for the given tolerance.", py::arg("theExpectedToler"));
	cls_BRepOffset_MakeSimpleOffset.def("Generated", (const TopoDS_Shape (BRepOffset_MakeSimpleOffset::*)(const TopoDS_Shape &) const ) &BRepOffset_MakeSimpleOffset::Generated, "Returnes result shape for the given one (if exists).", py::arg("theShape"));
	cls_BRepOffset_MakeSimpleOffset.def("Modified", (const TopoDS_Shape (BRepOffset_MakeSimpleOffset::*)(const TopoDS_Shape &) const ) &BRepOffset_MakeSimpleOffset::Modified, "Returnes modified shape for the given one (if exists).", py::arg("theShape"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_Inter2d.hxx
	py::class_<BRepOffset_Inter2d, std::unique_ptr<BRepOffset_Inter2d, Deleter<BRepOffset_Inter2d>>> cls_BRepOffset_Inter2d(mod, "BRepOffset_Inter2d", "Computes the intersections betwwen edges on a face stores result is SD as AsDes from BRepOffset.");
	cls_BRepOffset_Inter2d.def(py::init<>());
	cls_BRepOffset_Inter2d.def_static("Compute_", (void (*)(const opencascade::handle<BRepAlgo_AsDes> &, const TopoDS_Face &, const TopTools_IndexedMapOfShape &, const Standard_Real, TopTools_IndexedDataMapOfShapeListOfShape &)) &BRepOffset_Inter2d::Compute, "Computes the intersections between the edges stored is AsDes as descendants of <F> . Intersections is computed between two edges if one of them is bound in NewEdges. When all faces of the shape are treated the intersection vertices have to be fused using the FuseVertices method. theDMVV contains the vertices that should be fused", py::arg("AsDes"), py::arg("F"), py::arg("NewEdges"), py::arg("Tol"), py::arg("theDMVV"));
	cls_BRepOffset_Inter2d.def_static("ConnexIntByInt_", (void (*)(const TopoDS_Face &, BRepOffset_Offset &, TopTools_DataMapOfShapeShape &, const TopTools_DataMapOfShapeShape &, const opencascade::handle<BRepAlgo_AsDes> &, const Standard_Real, const Standard_Real, TopTools_IndexedMapOfShape &, TopTools_IndexedDataMapOfShapeListOfShape &)) &BRepOffset_Inter2d::ConnexIntByInt, "Computes the intersection between the offset edges of the <FI>. All intersection vertices will be stored in AsDes2d. When all faces of the shape are treated the intersection vertices have to be fused using the FuseVertices method. theDMVV contains the vertices that should be fused.", py::arg("FI"), py::arg("OFI"), py::arg("MES"), py::arg("Build"), py::arg("AsDes2d"), py::arg("Offset"), py::arg("Tol"), py::arg("FacesWithVerts"), py::arg("theDMVV"));
	cls_BRepOffset_Inter2d.def_static("ConnexIntByIntInVert_", (void (*)(const TopoDS_Face &, BRepOffset_Offset &, TopTools_DataMapOfShapeShape &, const TopTools_DataMapOfShapeShape &, const opencascade::handle<BRepAlgo_AsDes> &, const opencascade::handle<BRepAlgo_AsDes> &, const Standard_Real, TopTools_IndexedDataMapOfShapeListOfShape &)) &BRepOffset_Inter2d::ConnexIntByIntInVert, "Computes the intersection between the offset edges generated from vertices and stored into AsDes as descendants of the <FI>. All intersection vertices will be stored in AsDes2d. When all faces of the shape are treated the intersection vertices have to be fused using the FuseVertices method. theDMVV contains the vertices that should be fused.", py::arg("FI"), py::arg("OFI"), py::arg("MES"), py::arg("Build"), py::arg("AsDes"), py::arg("AsDes2d"), py::arg("Tol"), py::arg("theDMVV"));
	cls_BRepOffset_Inter2d.def_static("FuseVertices_", (void (*)(const TopTools_IndexedDataMapOfShapeListOfShape &, const opencascade::handle<BRepAlgo_AsDes> &)) &BRepOffset_Inter2d::FuseVertices, "Fuses the chains of vertices in the theDMVV and updates AsDes by replacing the old vertices with the new ones.", py::arg("theDMVV"), py::arg("theAsDes"));
	cls_BRepOffset_Inter2d.def_static("ExtentEdge_", (void (*)(const TopoDS_Edge &, TopoDS_Edge &, const Standard_Real)) &BRepOffset_Inter2d::ExtentEdge, "extents the edge", py::arg("E"), py::arg("NE"), py::arg("theOffset"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_SimpleOffset.hxx
	py::class_<BRepOffset_SimpleOffset, opencascade::handle<BRepOffset_SimpleOffset>, BRepTools_Modification> cls_BRepOffset_SimpleOffset(mod, "BRepOffset_SimpleOffset", "This class represents mechanism of simple offset algorithm i. e. topology-preserve offset construction without intersection.");
	cls_BRepOffset_SimpleOffset.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real>(), py::arg("theInputShape"), py::arg("theOffsetValue"), py::arg("theTolerance"));
	cls_BRepOffset_SimpleOffset.def_static("get_type_name_", (const char * (*)()) &BRepOffset_SimpleOffset::get_type_name, "None");
	cls_BRepOffset_SimpleOffset.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepOffset_SimpleOffset::get_type_descriptor, "None");
	cls_BRepOffset_SimpleOffset.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepOffset_SimpleOffset::*)() const ) &BRepOffset_SimpleOffset::DynamicType, "None");
	cls_BRepOffset_SimpleOffset.def("NewSurface", (Standard_Boolean (BRepOffset_SimpleOffset::*)(const TopoDS_Face &, opencascade::handle<Geom_Surface> &, TopLoc_Location &, Standard_Real &, Standard_Boolean &, Standard_Boolean &)) &BRepOffset_SimpleOffset::NewSurface, "Returns Standard_True if the face <F> has been modified. In this case, <S> is the new geometric support of the face, <L> the new location,<Tol> the new tolerance.<RevWires> has to be set to Standard_True when the modification reverses the normal of the surface.(the wires have to be reversed). <RevFace> has to be set to Standard_True if the orientation of the modified face changes in the shells which contain it. -- Here, <RevFace> will return Standard_True if the -- gp_Trsf is negative.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
	cls_BRepOffset_SimpleOffset.def("NewCurve", (Standard_Boolean (BRepOffset_SimpleOffset::*)(const TopoDS_Edge &, opencascade::handle<Geom_Curve> &, TopLoc_Location &, Standard_Real &)) &BRepOffset_SimpleOffset::NewCurve, "Returns Standard_True if the edge <E> has been modified. In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
	cls_BRepOffset_SimpleOffset.def("NewPoint", (Standard_Boolean (BRepOffset_SimpleOffset::*)(const TopoDS_Vertex &, gp_Pnt &, Standard_Real &)) &BRepOffset_SimpleOffset::NewPoint, "Returns Standard_True if the vertex <V> has been modified. In this case, <P> is the new geometric support of the vertex, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
	cls_BRepOffset_SimpleOffset.def("NewCurve2d", (Standard_Boolean (BRepOffset_SimpleOffset::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, opencascade::handle<Geom2d_Curve> &, Standard_Real &)) &BRepOffset_SimpleOffset::NewCurve2d, "Returns Standard_True if the edge <E> has a new curve on surface on the face <F>.In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
	cls_BRepOffset_SimpleOffset.def("NewParameter", (Standard_Boolean (BRepOffset_SimpleOffset::*)(const TopoDS_Vertex &, const TopoDS_Edge &, Standard_Real &, Standard_Real &)) &BRepOffset_SimpleOffset::NewParameter, "Returns Standard_True if the Vertex <V> has a new parameter on the edge <E>. In this case, <P> is the parameter, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
	cls_BRepOffset_SimpleOffset.def("Continuity", (GeomAbs_Shape (BRepOffset_SimpleOffset::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &BRepOffset_SimpleOffset::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_Tool.hxx
	py::class_<BRepOffset_Tool, std::unique_ptr<BRepOffset_Tool, Deleter<BRepOffset_Tool>>> cls_BRepOffset_Tool(mod, "BRepOffset_Tool", "None");
	cls_BRepOffset_Tool.def(py::init<>());
	cls_BRepOffset_Tool.def_static("EdgeVertices_", (void (*)(const TopoDS_Edge &, TopoDS_Vertex &, TopoDS_Vertex &)) &BRepOffset_Tool::EdgeVertices, "<V1> is the FirstVertex ,<V2> is the Last Vertex of <Edge> taking account the orientation of Edge.", py::arg("E"), py::arg("V1"), py::arg("V2"));
	cls_BRepOffset_Tool.def_static("OriEdgeInFace_", (TopAbs_Orientation (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepOffset_Tool::OriEdgeInFace, "returns the cumul of the orientation of <Edge> and thc containing wire in <Face>", py::arg("E"), py::arg("F"));
	cls_BRepOffset_Tool.def_static("OrientSection_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, TopAbs_Orientation &, TopAbs_Orientation &)) &BRepOffset_Tool::OrientSection, "<E> is a section between <F1> and <F2>. Computes <O1> the orientation of <E> in <F1> influenced by <F2>. idem for <O2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("O1"), py::arg("O2"));
	cls_BRepOffset_Tool.def_static("FindCommonShapes_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &BRepOffset_Tool::FindCommonShapes, "Looks for the common Vertices and Edges between faces <theF1> and <theF2>. Returns TRUE if common shapes have been found. <theLE> will contain the found common edges; <theLV> will contain the found common vertices.", py::arg("theF1"), py::arg("theF2"), py::arg("theLE"), py::arg("theLV"));
	cls_BRepOffset_Tool.def_static("FindCommonShapes_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopAbs_ShapeEnum, TopTools_ListOfShape &)) &BRepOffset_Tool::FindCommonShapes, "Looks for the common shapes of type <theType> between shapes <theS1> and <theS2>. Returns TRUE if common shapes have been found. <theLSC> will contain the found common shapes.", py::arg("theS1"), py::arg("theS2"), py::arg("theType"), py::arg("theLSC"));
	cls_BRepOffset_Tool.def_static("Inter3D_", [](const TopoDS_Face & a0, const TopoDS_Face & a1, TopTools_ListOfShape & a2, TopTools_ListOfShape & a3, const TopAbs_State a4, const TopoDS_Edge & a5) -> void { return BRepOffset_Tool::Inter3D(a0, a1, a2, a3, a4, a5); }, py::arg("F1"), py::arg("F2"), py::arg("LInt1"), py::arg("LInt2"), py::arg("Side"), py::arg("RefEdge"));
	cls_BRepOffset_Tool.def_static("Inter3D_", (void (*)(const TopoDS_Face &, const TopoDS_Face &, TopTools_ListOfShape &, TopTools_ListOfShape &, const TopAbs_State, const TopoDS_Edge &, const Standard_Boolean)) &BRepOffset_Tool::Inter3D, "Computes the Section betwwen <F1> and <F2> the edges solution are stored in <LInt1> with the orientation on <F1>, the sames edges are stored in <Lint2> with the orientation on <F2>.", py::arg("F1"), py::arg("F2"), py::arg("LInt1"), py::arg("LInt2"), py::arg("Side"), py::arg("RefEdge"), py::arg("IsRefEdgeDefined"));
	cls_BRepOffset_Tool.def_static("TryProject_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const TopTools_ListOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &, const TopAbs_State, const Standard_Real)) &BRepOffset_Tool::TryProject, "Find if the edges <Edges> of the face <F2> are on the face <F1>. Set in <LInt1> <LInt2> the updated edges. If all the edges are computed, returns true.", py::arg("F1"), py::arg("F2"), py::arg("Edges"), py::arg("LInt1"), py::arg("LInt2"), py::arg("Side"), py::arg("TolConf"));
	cls_BRepOffset_Tool.def_static("PipeInter_", (void (*)(const TopoDS_Face &, const TopoDS_Face &, TopTools_ListOfShape &, TopTools_ListOfShape &, const TopAbs_State)) &BRepOffset_Tool::PipeInter, "None", py::arg("F1"), py::arg("F2"), py::arg("LInt1"), py::arg("LInt2"), py::arg("Side"));
	cls_BRepOffset_Tool.def_static("Inter2d_", (void (*)(const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Edge &, TopTools_ListOfShape &, const Standard_Real)) &BRepOffset_Tool::Inter2d, "None", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("LV"), py::arg("Tol"));
	cls_BRepOffset_Tool.def_static("InterOrExtent_", (void (*)(const TopoDS_Face &, const TopoDS_Face &, TopTools_ListOfShape &, TopTools_ListOfShape &, const TopAbs_State)) &BRepOffset_Tool::InterOrExtent, "None", py::arg("F1"), py::arg("F2"), py::arg("LInt1"), py::arg("LInt2"), py::arg("Side"));
	cls_BRepOffset_Tool.def_static("CheckBounds_", (void (*)(const TopoDS_Face &, const BRepOffset_Analyse &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &)) &BRepOffset_Tool::CheckBounds, "None", py::arg("F"), py::arg("Analyse"), py::arg("enlargeU"), py::arg("enlargeVfirst"), py::arg("enlargeVlast"));
	cls_BRepOffset_Tool.def_static("EnLargeFace_", [](const TopoDS_Face & a0, TopoDS_Face & a1, const Standard_Boolean a2) -> Standard_Boolean { return BRepOffset_Tool::EnLargeFace(a0, a1, a2); }, py::arg("F"), py::arg("NF"), py::arg("ChangeGeom"));
	cls_BRepOffset_Tool.def_static("EnLargeFace_", [](const TopoDS_Face & a0, TopoDS_Face & a1, const Standard_Boolean a2, const Standard_Boolean a3) -> Standard_Boolean { return BRepOffset_Tool::EnLargeFace(a0, a1, a2, a3); }, py::arg("F"), py::arg("NF"), py::arg("ChangeGeom"), py::arg("UpDatePCurve"));
	cls_BRepOffset_Tool.def_static("EnLargeFace_", [](const TopoDS_Face & a0, TopoDS_Face & a1, const Standard_Boolean a2, const Standard_Boolean a3, const Standard_Boolean a4) -> Standard_Boolean { return BRepOffset_Tool::EnLargeFace(a0, a1, a2, a3, a4); }, py::arg("F"), py::arg("NF"), py::arg("ChangeGeom"), py::arg("UpDatePCurve"), py::arg("enlargeU"));
	cls_BRepOffset_Tool.def_static("EnLargeFace_", [](const TopoDS_Face & a0, TopoDS_Face & a1, const Standard_Boolean a2, const Standard_Boolean a3, const Standard_Boolean a4, const Standard_Boolean a5) -> Standard_Boolean { return BRepOffset_Tool::EnLargeFace(a0, a1, a2, a3, a4, a5); }, py::arg("F"), py::arg("NF"), py::arg("ChangeGeom"), py::arg("UpDatePCurve"), py::arg("enlargeU"), py::arg("enlargeVfirst"));
	cls_BRepOffset_Tool.def_static("EnLargeFace_", (Standard_Boolean (*)(const TopoDS_Face &, TopoDS_Face &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &BRepOffset_Tool::EnLargeFace, "if <ChangeGeom> is TRUE , the surface can be changed . if <UpdatePCurve> is TRUE, update the pcurves of the edges of <F> on the new surface.if the surface has been changed, Returns True if The Surface of <NF> has changed.", py::arg("F"), py::arg("NF"), py::arg("ChangeGeom"), py::arg("UpDatePCurve"), py::arg("enlargeU"), py::arg("enlargeVfirst"), py::arg("enlargeVlast"));
	cls_BRepOffset_Tool.def_static("ExtentFace_", (void (*)(const TopoDS_Face &, TopTools_DataMapOfShapeShape &, TopTools_DataMapOfShapeShape &, const TopAbs_State, const Standard_Real, TopoDS_Face &)) &BRepOffset_Tool::ExtentFace, "None", py::arg("F"), py::arg("ConstShapes"), py::arg("ToBuild"), py::arg("Side"), py::arg("TolConf"), py::arg("NF"));
	cls_BRepOffset_Tool.def_static("BuildNeighbour_", (void (*)(const TopoDS_Wire &, const TopoDS_Face &, TopTools_DataMapOfShapeShape &, TopTools_DataMapOfShapeShape &)) &BRepOffset_Tool::BuildNeighbour, "Via the wire explorer store in <NOnV1> for an Edge <E> of <W> his Edge neighbour on the first vertex <V1> of <E>. Store in NOnV2 the Neighbour of <E>on the last vertex <V2> of <E>.", py::arg("W"), py::arg("F"), py::arg("NOnV1"), py::arg("NOnV2"));
	cls_BRepOffset_Tool.def_static("MapVertexEdges_", (void (*)(const TopoDS_Shape &, TopTools_DataMapOfShapeListOfShape &)) &BRepOffset_Tool::MapVertexEdges, "Store in MVE for a vertex <V> in <S> the incident edges <E> in <S>. An Edge is Store only one Time for a vertex.", py::arg("S"), py::arg("MVE"));
	cls_BRepOffset_Tool.def_static("Deboucle3D_", (TopoDS_Shape (*)(const TopoDS_Shape &, const TopTools_MapOfShape &)) &BRepOffset_Tool::Deboucle3D, "Remove the non valid part of an offsetshape 1 - Remove all the free boundary and the faces connex to such edges. 2 - Remove all the shapes not valid in the result (according to the side of offseting) in this verion only the first point is implemented.", py::arg("S"), py::arg("Boundary"));
	cls_BRepOffset_Tool.def_static("CorrectOrientation_", (void (*)(const TopoDS_Shape &, const TopTools_IndexedMapOfShape &, opencascade::handle<BRepAlgo_AsDes> &, BRepAlgo_Image &, const Standard_Real)) &BRepOffset_Tool::CorrectOrientation, "None", py::arg("SI"), py::arg("NewEdges"), py::arg("AsDes"), py::arg("InitOffset"), py::arg("Offset"));
	cls_BRepOffset_Tool.def_static("Gabarit_", (Standard_Real (*)(const opencascade::handle<Geom_Curve> &)) &BRepOffset_Tool::Gabarit, "None", py::arg("aCurve"));
	cls_BRepOffset_Tool.def_static("CheckPlanesNormals_", [](const TopoDS_Face & a0, const TopoDS_Face & a1) -> Standard_Boolean { return BRepOffset_Tool::CheckPlanesNormals(a0, a1); }, py::arg("theFace1"), py::arg("theFace2"));
	cls_BRepOffset_Tool.def_static("CheckPlanesNormals_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const Standard_Real)) &BRepOffset_Tool::CheckPlanesNormals, "Compares the normal directions of the planar faces and returns TRUE if the directions are the same with the given precision.", py::arg("theFace1"), py::arg("theFace2"), py::arg("theTolAng"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<BRepOffset_ListOfInterval, std::unique_ptr<BRepOffset_ListOfInterval, Deleter<BRepOffset_ListOfInterval>>, NCollection_BaseList> cls_BRepOffset_ListOfInterval(mod, "BRepOffset_ListOfInterval", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_BRepOffset_ListOfInterval.def(py::init<>());
	cls_BRepOffset_ListOfInterval.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BRepOffset_ListOfInterval.def(py::init([] (const BRepOffset_ListOfInterval &other) {return new BRepOffset_ListOfInterval(other);}), "Copy constructor", py::arg("other"));
	cls_BRepOffset_ListOfInterval.def("begin", (BRepOffset_ListOfInterval::iterator (BRepOffset_ListOfInterval::*)() const ) &BRepOffset_ListOfInterval::begin, "Returns an iterator pointing to the first element in the list.");
	cls_BRepOffset_ListOfInterval.def("end", (BRepOffset_ListOfInterval::iterator (BRepOffset_ListOfInterval::*)() const ) &BRepOffset_ListOfInterval::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_BRepOffset_ListOfInterval.def("cbegin", (BRepOffset_ListOfInterval::const_iterator (BRepOffset_ListOfInterval::*)() const ) &BRepOffset_ListOfInterval::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_BRepOffset_ListOfInterval.def("cend", (BRepOffset_ListOfInterval::const_iterator (BRepOffset_ListOfInterval::*)() const ) &BRepOffset_ListOfInterval::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_BRepOffset_ListOfInterval.def("Size", (Standard_Integer (BRepOffset_ListOfInterval::*)() const ) &BRepOffset_ListOfInterval::Size, "Size - Number of items");
	cls_BRepOffset_ListOfInterval.def("Assign", (BRepOffset_ListOfInterval & (BRepOffset_ListOfInterval::*)(const BRepOffset_ListOfInterval &)) &BRepOffset_ListOfInterval::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepOffset_ListOfInterval.def("assign", (BRepOffset_ListOfInterval & (BRepOffset_ListOfInterval::*)(const BRepOffset_ListOfInterval &)) &BRepOffset_ListOfInterval::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BRepOffset_ListOfInterval.def("Clear", [](BRepOffset_ListOfInterval &self) -> void { return self.Clear(); });
	cls_BRepOffset_ListOfInterval.def("Clear", (void (BRepOffset_ListOfInterval::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepOffset_ListOfInterval::Clear, "Clear this list", py::arg("theAllocator"));
	cls_BRepOffset_ListOfInterval.def("First", (const BRepOffset_Interval & (BRepOffset_ListOfInterval::*)() const ) &BRepOffset_ListOfInterval::First, "First item");
	cls_BRepOffset_ListOfInterval.def("First", (BRepOffset_Interval & (BRepOffset_ListOfInterval::*)()) &BRepOffset_ListOfInterval::First, "First item (non-const)");
	cls_BRepOffset_ListOfInterval.def("Last", (const BRepOffset_Interval & (BRepOffset_ListOfInterval::*)() const ) &BRepOffset_ListOfInterval::Last, "Last item");
	cls_BRepOffset_ListOfInterval.def("Last", (BRepOffset_Interval & (BRepOffset_ListOfInterval::*)()) &BRepOffset_ListOfInterval::Last, "Last item (non-const)");
	cls_BRepOffset_ListOfInterval.def("Append", (BRepOffset_Interval & (BRepOffset_ListOfInterval::*)(const BRepOffset_Interval &)) &BRepOffset_ListOfInterval::Append, "Append one item at the end", py::arg("theItem"));
	cls_BRepOffset_ListOfInterval.def("Append", (void (BRepOffset_ListOfInterval::*)(const BRepOffset_Interval &, BRepOffset_ListOfInterval::Iterator &)) &BRepOffset_ListOfInterval::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_BRepOffset_ListOfInterval.def("Append", (void (BRepOffset_ListOfInterval::*)(BRepOffset_ListOfInterval &)) &BRepOffset_ListOfInterval::Append, "Append another list at the end", py::arg("theOther"));
	cls_BRepOffset_ListOfInterval.def("Prepend", (BRepOffset_Interval & (BRepOffset_ListOfInterval::*)(const BRepOffset_Interval &)) &BRepOffset_ListOfInterval::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_BRepOffset_ListOfInterval.def("Prepend", (void (BRepOffset_ListOfInterval::*)(BRepOffset_ListOfInterval &)) &BRepOffset_ListOfInterval::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_BRepOffset_ListOfInterval.def("RemoveFirst", (void (BRepOffset_ListOfInterval::*)()) &BRepOffset_ListOfInterval::RemoveFirst, "RemoveFirst item");
	cls_BRepOffset_ListOfInterval.def("Remove", (void (BRepOffset_ListOfInterval::*)(BRepOffset_ListOfInterval::Iterator &)) &BRepOffset_ListOfInterval::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_BRepOffset_ListOfInterval.def("InsertBefore", (BRepOffset_Interval & (BRepOffset_ListOfInterval::*)(const BRepOffset_Interval &, BRepOffset_ListOfInterval::Iterator &)) &BRepOffset_ListOfInterval::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_BRepOffset_ListOfInterval.def("InsertBefore", (void (BRepOffset_ListOfInterval::*)(BRepOffset_ListOfInterval &, BRepOffset_ListOfInterval::Iterator &)) &BRepOffset_ListOfInterval::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_BRepOffset_ListOfInterval.def("InsertAfter", (BRepOffset_Interval & (BRepOffset_ListOfInterval::*)(const BRepOffset_Interval &, BRepOffset_ListOfInterval::Iterator &)) &BRepOffset_ListOfInterval::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_BRepOffset_ListOfInterval.def("InsertAfter", (void (BRepOffset_ListOfInterval::*)(BRepOffset_ListOfInterval &, BRepOffset_ListOfInterval::Iterator &)) &BRepOffset_ListOfInterval::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_BRepOffset_ListOfInterval.def("Reverse", (void (BRepOffset_ListOfInterval::*)()) &BRepOffset_ListOfInterval::Reverse, "Reverse the list");
	cls_BRepOffset_ListOfInterval.def("__iter__", [](const BRepOffset_ListOfInterval &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<BRepOffset_ListIteratorOfListOfInterval, std::unique_ptr<BRepOffset_ListIteratorOfListOfInterval, Deleter<BRepOffset_ListIteratorOfListOfInterval>>> cls_BRepOffset_ListIteratorOfListOfInterval(mod, "BRepOffset_ListIteratorOfListOfInterval", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_BRepOffset_ListIteratorOfListOfInterval.def(py::init<>());
	cls_BRepOffset_ListIteratorOfListOfInterval.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_BRepOffset_ListIteratorOfListOfInterval.def("More", (Standard_Boolean (BRepOffset_ListIteratorOfListOfInterval::*)() const ) &BRepOffset_ListIteratorOfListOfInterval::More, "Check end");
	cls_BRepOffset_ListIteratorOfListOfInterval.def("Next", (void (BRepOffset_ListIteratorOfListOfInterval::*)()) &BRepOffset_ListIteratorOfListOfInterval::Next, "Make step");
	cls_BRepOffset_ListIteratorOfListOfInterval.def("Value", (const BRepOffset_Interval & (BRepOffset_ListIteratorOfListOfInterval::*)() const ) &BRepOffset_ListIteratorOfListOfInterval::Value, "Constant Value access");
	cls_BRepOffset_ListIteratorOfListOfInterval.def("Value", (BRepOffset_Interval & (BRepOffset_ListIteratorOfListOfInterval::*)()) &BRepOffset_ListIteratorOfListOfInterval::Value, "Non-const Value access");
	cls_BRepOffset_ListIteratorOfListOfInterval.def("ChangeValue", (BRepOffset_Interval & (BRepOffset_ListIteratorOfListOfInterval::*)() const ) &BRepOffset_ListIteratorOfListOfInterval::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepOffset_DataMapOfShapeListOfInterval, std::unique_ptr<BRepOffset_DataMapOfShapeListOfInterval, Deleter<BRepOffset_DataMapOfShapeListOfInterval>>, NCollection_BaseMap> cls_BRepOffset_DataMapOfShapeListOfInterval(mod, "BRepOffset_DataMapOfShapeListOfInterval", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepOffset_DataMapOfShapeListOfInterval.def(py::init<>());
	cls_BRepOffset_DataMapOfShapeListOfInterval.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def(py::init([] (const BRepOffset_DataMapOfShapeListOfInterval &other) {return new BRepOffset_DataMapOfShapeListOfInterval(other);}), "Copy constructor", py::arg("other"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("begin", (BRepOffset_DataMapOfShapeListOfInterval::iterator (BRepOffset_DataMapOfShapeListOfInterval::*)() const ) &BRepOffset_DataMapOfShapeListOfInterval::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("end", (BRepOffset_DataMapOfShapeListOfInterval::iterator (BRepOffset_DataMapOfShapeListOfInterval::*)() const ) &BRepOffset_DataMapOfShapeListOfInterval::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("cbegin", (BRepOffset_DataMapOfShapeListOfInterval::const_iterator (BRepOffset_DataMapOfShapeListOfInterval::*)() const ) &BRepOffset_DataMapOfShapeListOfInterval::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("cend", (BRepOffset_DataMapOfShapeListOfInterval::const_iterator (BRepOffset_DataMapOfShapeListOfInterval::*)() const ) &BRepOffset_DataMapOfShapeListOfInterval::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("Exchange", (void (BRepOffset_DataMapOfShapeListOfInterval::*)(BRepOffset_DataMapOfShapeListOfInterval &)) &BRepOffset_DataMapOfShapeListOfInterval::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("Assign", (BRepOffset_DataMapOfShapeListOfInterval & (BRepOffset_DataMapOfShapeListOfInterval::*)(const BRepOffset_DataMapOfShapeListOfInterval &)) &BRepOffset_DataMapOfShapeListOfInterval::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("assign", (BRepOffset_DataMapOfShapeListOfInterval & (BRepOffset_DataMapOfShapeListOfInterval::*)(const BRepOffset_DataMapOfShapeListOfInterval &)) &BRepOffset_DataMapOfShapeListOfInterval::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("ReSize", (void (BRepOffset_DataMapOfShapeListOfInterval::*)(const Standard_Integer)) &BRepOffset_DataMapOfShapeListOfInterval::ReSize, "ReSize", py::arg("N"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("Bind", (Standard_Boolean (BRepOffset_DataMapOfShapeListOfInterval::*)(const TopoDS_Shape &, const BRepOffset_ListOfInterval &)) &BRepOffset_DataMapOfShapeListOfInterval::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepOffset_DataMapOfShapeListOfInterval.def("Bound", (BRepOffset_ListOfInterval * (BRepOffset_DataMapOfShapeListOfInterval::*)(const TopoDS_Shape &, const BRepOffset_ListOfInterval &)) &BRepOffset_DataMapOfShapeListOfInterval::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("IsBound", (Standard_Boolean (BRepOffset_DataMapOfShapeListOfInterval::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeListOfInterval::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("UnBind", (Standard_Boolean (BRepOffset_DataMapOfShapeListOfInterval::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeListOfInterval::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeListOfInterval.def("Seek", (const BRepOffset_ListOfInterval * (BRepOffset_DataMapOfShapeListOfInterval::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeListOfInterval::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeListOfInterval.def("Find", (const BRepOffset_ListOfInterval & (BRepOffset_DataMapOfShapeListOfInterval::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeListOfInterval::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeListOfInterval.def("Find", (Standard_Boolean (BRepOffset_DataMapOfShapeListOfInterval::*)(const TopoDS_Shape &, BRepOffset_ListOfInterval &) const ) &BRepOffset_DataMapOfShapeListOfInterval::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("__call__", (const BRepOffset_ListOfInterval & (BRepOffset_DataMapOfShapeListOfInterval::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeListOfInterval::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeListOfInterval.def("ChangeSeek", (BRepOffset_ListOfInterval * (BRepOffset_DataMapOfShapeListOfInterval::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeListOfInterval::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("ChangeFind", (BRepOffset_ListOfInterval & (BRepOffset_DataMapOfShapeListOfInterval::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeListOfInterval::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("__call__", (BRepOffset_ListOfInterval & (BRepOffset_DataMapOfShapeListOfInterval::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeListOfInterval::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("Clear", [](BRepOffset_DataMapOfShapeListOfInterval &self) -> void { return self.Clear(); });
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("Clear", (void (BRepOffset_DataMapOfShapeListOfInterval::*)(const Standard_Boolean)) &BRepOffset_DataMapOfShapeListOfInterval::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("Clear", (void (BRepOffset_DataMapOfShapeListOfInterval::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepOffset_DataMapOfShapeListOfInterval::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("Size", (Standard_Integer (BRepOffset_DataMapOfShapeListOfInterval::*)() const ) &BRepOffset_DataMapOfShapeListOfInterval::Size, "Size");
	cls_BRepOffset_DataMapOfShapeListOfInterval.def("__iter__", [](const BRepOffset_DataMapOfShapeListOfInterval &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_DataMapOfShapeListOfInterval.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepOffset_DataMapOfShapeOffset, std::unique_ptr<BRepOffset_DataMapOfShapeOffset, Deleter<BRepOffset_DataMapOfShapeOffset>>, NCollection_BaseMap> cls_BRepOffset_DataMapOfShapeOffset(mod, "BRepOffset_DataMapOfShapeOffset", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepOffset_DataMapOfShapeOffset.def(py::init<>());
	cls_BRepOffset_DataMapOfShapeOffset.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepOffset_DataMapOfShapeOffset.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepOffset_DataMapOfShapeOffset.def(py::init([] (const BRepOffset_DataMapOfShapeOffset &other) {return new BRepOffset_DataMapOfShapeOffset(other);}), "Copy constructor", py::arg("other"));
	cls_BRepOffset_DataMapOfShapeOffset.def("begin", (BRepOffset_DataMapOfShapeOffset::iterator (BRepOffset_DataMapOfShapeOffset::*)() const ) &BRepOffset_DataMapOfShapeOffset::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepOffset_DataMapOfShapeOffset.def("end", (BRepOffset_DataMapOfShapeOffset::iterator (BRepOffset_DataMapOfShapeOffset::*)() const ) &BRepOffset_DataMapOfShapeOffset::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepOffset_DataMapOfShapeOffset.def("cbegin", (BRepOffset_DataMapOfShapeOffset::const_iterator (BRepOffset_DataMapOfShapeOffset::*)() const ) &BRepOffset_DataMapOfShapeOffset::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepOffset_DataMapOfShapeOffset.def("cend", (BRepOffset_DataMapOfShapeOffset::const_iterator (BRepOffset_DataMapOfShapeOffset::*)() const ) &BRepOffset_DataMapOfShapeOffset::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepOffset_DataMapOfShapeOffset.def("Exchange", (void (BRepOffset_DataMapOfShapeOffset::*)(BRepOffset_DataMapOfShapeOffset &)) &BRepOffset_DataMapOfShapeOffset::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepOffset_DataMapOfShapeOffset.def("Assign", (BRepOffset_DataMapOfShapeOffset & (BRepOffset_DataMapOfShapeOffset::*)(const BRepOffset_DataMapOfShapeOffset &)) &BRepOffset_DataMapOfShapeOffset::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepOffset_DataMapOfShapeOffset.def("assign", (BRepOffset_DataMapOfShapeOffset & (BRepOffset_DataMapOfShapeOffset::*)(const BRepOffset_DataMapOfShapeOffset &)) &BRepOffset_DataMapOfShapeOffset::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepOffset_DataMapOfShapeOffset.def("ReSize", (void (BRepOffset_DataMapOfShapeOffset::*)(const Standard_Integer)) &BRepOffset_DataMapOfShapeOffset::ReSize, "ReSize", py::arg("N"));
	cls_BRepOffset_DataMapOfShapeOffset.def("Bind", (Standard_Boolean (BRepOffset_DataMapOfShapeOffset::*)(const TopoDS_Shape &, const BRepOffset_Offset &)) &BRepOffset_DataMapOfShapeOffset::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepOffset_DataMapOfShapeOffset.def("Bound", (BRepOffset_Offset * (BRepOffset_DataMapOfShapeOffset::*)(const TopoDS_Shape &, const BRepOffset_Offset &)) &BRepOffset_DataMapOfShapeOffset::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepOffset_DataMapOfShapeOffset.def("IsBound", (Standard_Boolean (BRepOffset_DataMapOfShapeOffset::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeOffset::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeOffset.def("UnBind", (Standard_Boolean (BRepOffset_DataMapOfShapeOffset::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeOffset::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeOffset.def("Seek", (const BRepOffset_Offset * (BRepOffset_DataMapOfShapeOffset::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeOffset::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeOffset.def("Find", (const BRepOffset_Offset & (BRepOffset_DataMapOfShapeOffset::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeOffset::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeOffset.def("Find", (Standard_Boolean (BRepOffset_DataMapOfShapeOffset::*)(const TopoDS_Shape &, BRepOffset_Offset &) const ) &BRepOffset_DataMapOfShapeOffset::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepOffset_DataMapOfShapeOffset.def("__call__", (const BRepOffset_Offset & (BRepOffset_DataMapOfShapeOffset::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeOffset::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeOffset.def("ChangeSeek", (BRepOffset_Offset * (BRepOffset_DataMapOfShapeOffset::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeOffset::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeOffset.def("ChangeFind", (BRepOffset_Offset & (BRepOffset_DataMapOfShapeOffset::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeOffset::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeOffset.def("__call__", (BRepOffset_Offset & (BRepOffset_DataMapOfShapeOffset::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeOffset::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeOffset.def("Clear", [](BRepOffset_DataMapOfShapeOffset &self) -> void { return self.Clear(); });
	cls_BRepOffset_DataMapOfShapeOffset.def("Clear", (void (BRepOffset_DataMapOfShapeOffset::*)(const Standard_Boolean)) &BRepOffset_DataMapOfShapeOffset::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepOffset_DataMapOfShapeOffset.def("Clear", (void (BRepOffset_DataMapOfShapeOffset::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepOffset_DataMapOfShapeOffset::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepOffset_DataMapOfShapeOffset.def("Size", (Standard_Integer (BRepOffset_DataMapOfShapeOffset::*)() const ) &BRepOffset_DataMapOfShapeOffset::Size, "Size");
	cls_BRepOffset_DataMapOfShapeOffset.def("__iter__", [](const BRepOffset_DataMapOfShapeOffset &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_DataMapOfShapeOffset.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepOffset_DataMapOfShapeMapOfShape, std::unique_ptr<BRepOffset_DataMapOfShapeMapOfShape, Deleter<BRepOffset_DataMapOfShapeMapOfShape>>, NCollection_BaseMap> cls_BRepOffset_DataMapOfShapeMapOfShape(mod, "BRepOffset_DataMapOfShapeMapOfShape", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepOffset_DataMapOfShapeMapOfShape.def(py::init<>());
	cls_BRepOffset_DataMapOfShapeMapOfShape.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def(py::init([] (const BRepOffset_DataMapOfShapeMapOfShape &other) {return new BRepOffset_DataMapOfShapeMapOfShape(other);}), "Copy constructor", py::arg("other"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("begin", (BRepOffset_DataMapOfShapeMapOfShape::iterator (BRepOffset_DataMapOfShapeMapOfShape::*)() const ) &BRepOffset_DataMapOfShapeMapOfShape::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("end", (BRepOffset_DataMapOfShapeMapOfShape::iterator (BRepOffset_DataMapOfShapeMapOfShape::*)() const ) &BRepOffset_DataMapOfShapeMapOfShape::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("cbegin", (BRepOffset_DataMapOfShapeMapOfShape::const_iterator (BRepOffset_DataMapOfShapeMapOfShape::*)() const ) &BRepOffset_DataMapOfShapeMapOfShape::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("cend", (BRepOffset_DataMapOfShapeMapOfShape::const_iterator (BRepOffset_DataMapOfShapeMapOfShape::*)() const ) &BRepOffset_DataMapOfShapeMapOfShape::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("Exchange", (void (BRepOffset_DataMapOfShapeMapOfShape::*)(BRepOffset_DataMapOfShapeMapOfShape &)) &BRepOffset_DataMapOfShapeMapOfShape::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("Assign", (BRepOffset_DataMapOfShapeMapOfShape & (BRepOffset_DataMapOfShapeMapOfShape::*)(const BRepOffset_DataMapOfShapeMapOfShape &)) &BRepOffset_DataMapOfShapeMapOfShape::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("assign", (BRepOffset_DataMapOfShapeMapOfShape & (BRepOffset_DataMapOfShapeMapOfShape::*)(const BRepOffset_DataMapOfShapeMapOfShape &)) &BRepOffset_DataMapOfShapeMapOfShape::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("ReSize", (void (BRepOffset_DataMapOfShapeMapOfShape::*)(const Standard_Integer)) &BRepOffset_DataMapOfShapeMapOfShape::ReSize, "ReSize", py::arg("N"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("Bind", (Standard_Boolean (BRepOffset_DataMapOfShapeMapOfShape::*)(const TopoDS_Shape &, const TopTools_MapOfShape &)) &BRepOffset_DataMapOfShapeMapOfShape::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepOffset_DataMapOfShapeMapOfShape.def("Bound", (TopTools_MapOfShape * (BRepOffset_DataMapOfShapeMapOfShape::*)(const TopoDS_Shape &, const TopTools_MapOfShape &)) &BRepOffset_DataMapOfShapeMapOfShape::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("IsBound", (Standard_Boolean (BRepOffset_DataMapOfShapeMapOfShape::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeMapOfShape::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("UnBind", (Standard_Boolean (BRepOffset_DataMapOfShapeMapOfShape::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeMapOfShape::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeMapOfShape.def("Seek", (const TopTools_MapOfShape * (BRepOffset_DataMapOfShapeMapOfShape::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeMapOfShape::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeMapOfShape.def("Find", (const TopTools_MapOfShape & (BRepOffset_DataMapOfShapeMapOfShape::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeMapOfShape::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeMapOfShape.def("Find", (Standard_Boolean (BRepOffset_DataMapOfShapeMapOfShape::*)(const TopoDS_Shape &, TopTools_MapOfShape &) const ) &BRepOffset_DataMapOfShapeMapOfShape::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("__call__", (const TopTools_MapOfShape & (BRepOffset_DataMapOfShapeMapOfShape::*)(const TopoDS_Shape &) const ) &BRepOffset_DataMapOfShapeMapOfShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepOffset_DataMapOfShapeMapOfShape.def("ChangeSeek", (TopTools_MapOfShape * (BRepOffset_DataMapOfShapeMapOfShape::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeMapOfShape::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("ChangeFind", (TopTools_MapOfShape & (BRepOffset_DataMapOfShapeMapOfShape::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeMapOfShape::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("__call__", (TopTools_MapOfShape & (BRepOffset_DataMapOfShapeMapOfShape::*)(const TopoDS_Shape &)) &BRepOffset_DataMapOfShapeMapOfShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("Clear", [](BRepOffset_DataMapOfShapeMapOfShape &self) -> void { return self.Clear(); });
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("Clear", (void (BRepOffset_DataMapOfShapeMapOfShape::*)(const Standard_Boolean)) &BRepOffset_DataMapOfShapeMapOfShape::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("Clear", (void (BRepOffset_DataMapOfShapeMapOfShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepOffset_DataMapOfShapeMapOfShape::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("Size", (Standard_Integer (BRepOffset_DataMapOfShapeMapOfShape::*)() const ) &BRepOffset_DataMapOfShapeMapOfShape::Size, "Size");
	cls_BRepOffset_DataMapOfShapeMapOfShape.def("__iter__", [](const BRepOffset_DataMapOfShapeMapOfShape &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepOffset_DataMapOfShapeMapOfShape.hxx

}
