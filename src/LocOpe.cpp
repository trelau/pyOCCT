#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <LocOpe_Operation.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <LocOpe_Gluer.hxx>
#include <Standard_Transient.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <LocOpe_WiresOnShape.hxx>
#include <LocOpe_Spliter.hxx>
#include <LocOpe_SplitShape.hxx>
#include <LocOpe_GeneratedShape.hxx>
#include <LocOpe_Generator.hxx>
#include <LocOpe_GluedShape.hxx>
#include <gp_Vec.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Geom_Curve.hxx>
#include <LocOpe_Prism.hxx>
#include <gp_Ax1.hxx>
#include <LocOpe_Revol.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <LocOpe_Pipe.hxx>
#include <LocOpe_DPrism.hxx>
#include <gp_Pnt.hxx>
#include <LocOpe_LinearForm.hxx>
#include <LocOpe_RevolutionForm.hxx>
#include <LocOpe_FindEdges.hxx>
#include <LocOpe_FindEdgesInFace.hxx>
#include <TopAbs_Orientation.hxx>
#include <LocOpe_PntFace.hxx>
#include <gp_Circ.hxx>
#include <LocOpe_CurveShapeIntersector.hxx>
#include <LocOpe_SequenceOfLin.hxx>
#include <LocOpe_SequenceOfCirc.hxx>
#include <LocOpe_CSIntersector.hxx>
#include <LocOpe_BuildShape.hxx>
#include <gp_Dir.hxx>
#include <gp_Pln.hxx>
#include <LocOpe_SplitDrafts.hxx>
#include <LocOpe_BuildWires.hxx>
#include <LocOpe.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <LocOpe_SequenceOfPntFace.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <LocOpe_DataMapOfShapePnt.hxx>

PYBIND11_MODULE(LocOpe, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TColGeom");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_Operation.hxx
	py::enum_<LocOpe_Operation>(mod, "LocOpe_Operation", "None")
		.value("LocOpe_FUSE", LocOpe_Operation::LocOpe_FUSE)
		.value("LocOpe_CUT", LocOpe_Operation::LocOpe_CUT)
		.value("LocOpe_INVALID", LocOpe_Operation::LocOpe_INVALID)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_Gluer.hxx
	py::class_<LocOpe_Gluer, std::unique_ptr<LocOpe_Gluer, Deleter<LocOpe_Gluer>>> cls_LocOpe_Gluer(mod, "LocOpe_Gluer", "None");
	cls_LocOpe_Gluer.def(py::init<>());
	cls_LocOpe_Gluer.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("Sbase"), py::arg("Snew"));
	cls_LocOpe_Gluer.def("Init", (void (LocOpe_Gluer::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &LocOpe_Gluer::Init, "None", py::arg("Sbase"), py::arg("Snew"));
	cls_LocOpe_Gluer.def("Bind", (void (LocOpe_Gluer::*)(const TopoDS_Face &, const TopoDS_Face &)) &LocOpe_Gluer::Bind, "None", py::arg("Fnew"), py::arg("Fbase"));
	cls_LocOpe_Gluer.def("Bind", (void (LocOpe_Gluer::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &LocOpe_Gluer::Bind, "None", py::arg("Enew"), py::arg("Ebase"));
	cls_LocOpe_Gluer.def("OpeType", (LocOpe_Operation (LocOpe_Gluer::*)() const ) &LocOpe_Gluer::OpeType, "None");
	cls_LocOpe_Gluer.def("Perform", (void (LocOpe_Gluer::*)()) &LocOpe_Gluer::Perform, "None");
	cls_LocOpe_Gluer.def("IsDone", (Standard_Boolean (LocOpe_Gluer::*)() const ) &LocOpe_Gluer::IsDone, "None");
	cls_LocOpe_Gluer.def("ResultingShape", (const TopoDS_Shape & (LocOpe_Gluer::*)() const ) &LocOpe_Gluer::ResultingShape, "None");
	cls_LocOpe_Gluer.def("DescendantFaces", (const TopTools_ListOfShape & (LocOpe_Gluer::*)(const TopoDS_Face &) const ) &LocOpe_Gluer::DescendantFaces, "None", py::arg("F"));
	cls_LocOpe_Gluer.def("BasisShape", (const TopoDS_Shape & (LocOpe_Gluer::*)() const ) &LocOpe_Gluer::BasisShape, "None");
	cls_LocOpe_Gluer.def("GluedShape", (const TopoDS_Shape & (LocOpe_Gluer::*)() const ) &LocOpe_Gluer::GluedShape, "None");
	cls_LocOpe_Gluer.def("Edges", (const TopTools_ListOfShape & (LocOpe_Gluer::*)() const ) &LocOpe_Gluer::Edges, "None");
	cls_LocOpe_Gluer.def("TgtEdges", (const TopTools_ListOfShape & (LocOpe_Gluer::*)() const ) &LocOpe_Gluer::TgtEdges, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_WiresOnShape.hxx
	py::class_<LocOpe_WiresOnShape, opencascade::handle<LocOpe_WiresOnShape>, Standard_Transient> cls_LocOpe_WiresOnShape(mod, "LocOpe_WiresOnShape", "None");
	cls_LocOpe_WiresOnShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_LocOpe_WiresOnShape.def("Init", (void (LocOpe_WiresOnShape::*)(const TopoDS_Shape &)) &LocOpe_WiresOnShape::Init, "None", py::arg("S"));
	cls_LocOpe_WiresOnShape.def("Add", (Standard_Boolean (LocOpe_WiresOnShape::*)(const TopTools_SequenceOfShape &)) &LocOpe_WiresOnShape::Add, "Add splitting edges or wires for whole initial shape withot additional specification edge->face, edge->edge This method puts edge on the corresponding faces from initial shape", py::arg("theEdges"));
	cls_LocOpe_WiresOnShape.def("SetCheckInterior", (void (LocOpe_WiresOnShape::*)(const Standard_Boolean)) &LocOpe_WiresOnShape::SetCheckInterior, "Set the flag of check internal intersections default value is True (to check)", py::arg("ToCheckInterior"));
	cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("W"), py::arg("F"));
	cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Compound &, const TopoDS_Face &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("Comp"), py::arg("F"));
	cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Edge &, const TopoDS_Face &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("E"), py::arg("F"));
	cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("EfromW"), py::arg("EonFace"));
	cls_LocOpe_WiresOnShape.def("BindAll", (void (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::BindAll, "None");
	cls_LocOpe_WiresOnShape.def("IsDone", (Standard_Boolean (LocOpe_WiresOnShape::*)() const ) &LocOpe_WiresOnShape::IsDone, "None");
	cls_LocOpe_WiresOnShape.def("InitEdgeIterator", (void (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::InitEdgeIterator, "None");
	cls_LocOpe_WiresOnShape.def("MoreEdge", (Standard_Boolean (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::MoreEdge, "None");
	cls_LocOpe_WiresOnShape.def("Edge", (TopoDS_Edge (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::Edge, "None");
	cls_LocOpe_WiresOnShape.def("OnFace", (TopoDS_Face (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::OnFace, "Returns the face of the shape on which the current edge is projected.");
	cls_LocOpe_WiresOnShape.def("OnEdge", (Standard_Boolean (LocOpe_WiresOnShape::*)(TopoDS_Edge &)) &LocOpe_WiresOnShape::OnEdge, "If the current edge is projected on an edge, returns <Standard_True> and sets the value of <E>. Otherwise, returns <Standard_False>.", py::arg("E"));
	cls_LocOpe_WiresOnShape.def("NextEdge", (void (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::NextEdge, "None");
	cls_LocOpe_WiresOnShape.def("OnVertex", (Standard_Boolean (LocOpe_WiresOnShape::*)(const TopoDS_Vertex &, TopoDS_Vertex &)) &LocOpe_WiresOnShape::OnVertex, "None", py::arg("Vwire"), py::arg("Vshape"));
	cls_LocOpe_WiresOnShape.def("OnEdge", (Standard_Boolean (LocOpe_WiresOnShape::*)(const TopoDS_Vertex &, TopoDS_Edge &, Standard_Real &)) &LocOpe_WiresOnShape::OnEdge, "If the vertex <V> lies on an edge of the original shape, returns <Standard_True> and sets the concerned edge in <E>, and the parameter on the edge in <P>. Else returns <Standard_False>.", py::arg("V"), py::arg("E"), py::arg("P"));
	cls_LocOpe_WiresOnShape.def("OnEdge", (Standard_Boolean (LocOpe_WiresOnShape::*)(const TopoDS_Vertex &, const TopoDS_Edge &, TopoDS_Edge &, Standard_Real &)) &LocOpe_WiresOnShape::OnEdge, "If the vertex <V> lies on an edge of the original shape, returns <Standard_True> and sets the concerned edge in <E>, and the parameter on the edge in <P>. Else returns <Standard_False>.", py::arg("V"), py::arg("EdgeFrom"), py::arg("E"), py::arg("P"));
	cls_LocOpe_WiresOnShape.def("IsFaceWithSection", (Standard_Boolean (LocOpe_WiresOnShape::*)(const TopoDS_Shape &) const ) &LocOpe_WiresOnShape::IsFaceWithSection, "tells is the face to be split by section or not", py::arg("aFace"));
	cls_LocOpe_WiresOnShape.def_static("get_type_name_", (const char * (*)()) &LocOpe_WiresOnShape::get_type_name, "None");
	cls_LocOpe_WiresOnShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LocOpe_WiresOnShape::get_type_descriptor, "None");
	cls_LocOpe_WiresOnShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (LocOpe_WiresOnShape::*)() const ) &LocOpe_WiresOnShape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_Spliter.hxx
	py::class_<LocOpe_Spliter, std::unique_ptr<LocOpe_Spliter, Deleter<LocOpe_Spliter>>> cls_LocOpe_Spliter(mod, "LocOpe_Spliter", "None");
	cls_LocOpe_Spliter.def(py::init<>());
	cls_LocOpe_Spliter.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_LocOpe_Spliter.def("Init", (void (LocOpe_Spliter::*)(const TopoDS_Shape &)) &LocOpe_Spliter::Init, "Initializes the algorithm on the shape <S>.", py::arg("S"));
	cls_LocOpe_Spliter.def("Perform", (void (LocOpe_Spliter::*)(const opencascade::handle<LocOpe_WiresOnShape> &)) &LocOpe_Spliter::Perform, "None", py::arg("PW"));
	cls_LocOpe_Spliter.def("IsDone", (Standard_Boolean (LocOpe_Spliter::*)() const ) &LocOpe_Spliter::IsDone, "None");
	cls_LocOpe_Spliter.def("ResultingShape", (const TopoDS_Shape & (LocOpe_Spliter::*)() const ) &LocOpe_Spliter::ResultingShape, "Returns the new shape");
	cls_LocOpe_Spliter.def("Shape", (const TopoDS_Shape & (LocOpe_Spliter::*)() const ) &LocOpe_Spliter::Shape, "Returns the initial shape");
	cls_LocOpe_Spliter.def("DirectLeft", (const TopTools_ListOfShape & (LocOpe_Spliter::*)() const ) &LocOpe_Spliter::DirectLeft, "Returns the faces which are the left of the projected wires and which are");
	cls_LocOpe_Spliter.def("Left", (const TopTools_ListOfShape & (LocOpe_Spliter::*)() const ) &LocOpe_Spliter::Left, "Returns the faces of the 'left' part on the shape. (It is build from DirectLeft, with the faces connected to this set, and so on...).");
	cls_LocOpe_Spliter.def("DescendantShapes", (const TopTools_ListOfShape & (LocOpe_Spliter::*)(const TopoDS_Shape &)) &LocOpe_Spliter::DescendantShapes, "Returns the list of descendant shapes of <S>.", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_SplitShape.hxx
	py::class_<LocOpe_SplitShape, std::unique_ptr<LocOpe_SplitShape, Deleter<LocOpe_SplitShape>>> cls_LocOpe_SplitShape(mod, "LocOpe_SplitShape", "Provides a tool to cut : - edges with a vertices, - faces with wires, and rebuilds the shape containing the edges and the faces.");
	cls_LocOpe_SplitShape.def(py::init<>());
	cls_LocOpe_SplitShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_LocOpe_SplitShape.def("Init", (void (LocOpe_SplitShape::*)(const TopoDS_Shape &)) &LocOpe_SplitShape::Init, "Initializes the process on the shape <S>.", py::arg("S"));
	cls_LocOpe_SplitShape.def("CanSplit", (Standard_Boolean (LocOpe_SplitShape::*)(const TopoDS_Edge &) const ) &LocOpe_SplitShape::CanSplit, "Tests if it is possible to split the edge <E>.", py::arg("E"));
	cls_LocOpe_SplitShape.def("Add", (void (LocOpe_SplitShape::*)(const TopoDS_Vertex &, const Standard_Real, const TopoDS_Edge &)) &LocOpe_SplitShape::Add, "Adds the vertex <V> on the edge <E>, at parameter <P>.", py::arg("V"), py::arg("P"), py::arg("E"));
	cls_LocOpe_SplitShape.def("Add", (Standard_Boolean (LocOpe_SplitShape::*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe_SplitShape::Add, "Adds the wire <W> on the face <F>.", py::arg("W"), py::arg("F"));
	cls_LocOpe_SplitShape.def("Add", (Standard_Boolean (LocOpe_SplitShape::*)(const TopTools_ListOfShape &, const TopoDS_Face &)) &LocOpe_SplitShape::Add, "Adds the list of wires <Lwires> on the face <F>.", py::arg("Lwires"), py::arg("F"));
	cls_LocOpe_SplitShape.def("Shape", (const TopoDS_Shape & (LocOpe_SplitShape::*)() const ) &LocOpe_SplitShape::Shape, "Returns the 'original' shape.");
	cls_LocOpe_SplitShape.def("DescendantShapes", (const TopTools_ListOfShape & (LocOpe_SplitShape::*)(const TopoDS_Shape &)) &LocOpe_SplitShape::DescendantShapes, "Returns the list of descendant shapes of <S>.", py::arg("S"));
	cls_LocOpe_SplitShape.def("LeftOf", (const TopTools_ListOfShape & (LocOpe_SplitShape::*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe_SplitShape::LeftOf, "Returns the 'left' part defined by the wire <W> on the face <F>. The returned list of shape is in fact a list of faces. The face <F> is considered with its topological orientation in the original shape. <W> is considered with its orientation.", py::arg("W"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_Generator.hxx
	py::class_<LocOpe_Generator, std::unique_ptr<LocOpe_Generator, Deleter<LocOpe_Generator>>> cls_LocOpe_Generator(mod, "LocOpe_Generator", "None");
	cls_LocOpe_Generator.def(py::init<>());
	cls_LocOpe_Generator.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_LocOpe_Generator.def("Init", (void (LocOpe_Generator::*)(const TopoDS_Shape &)) &LocOpe_Generator::Init, "Initializes the algorithm on the shape <S>.", py::arg("S"));
	cls_LocOpe_Generator.def("Perform", (void (LocOpe_Generator::*)(const opencascade::handle<LocOpe_GeneratedShape> &)) &LocOpe_Generator::Perform, "None", py::arg("G"));
	cls_LocOpe_Generator.def("IsDone", (Standard_Boolean (LocOpe_Generator::*)() const ) &LocOpe_Generator::IsDone, "None");
	cls_LocOpe_Generator.def("ResultingShape", (const TopoDS_Shape & (LocOpe_Generator::*)() const ) &LocOpe_Generator::ResultingShape, "Returns the new shape");
	cls_LocOpe_Generator.def("Shape", (const TopoDS_Shape & (LocOpe_Generator::*)() const ) &LocOpe_Generator::Shape, "Returns the initial shape");
	cls_LocOpe_Generator.def("DescendantFace", (const TopTools_ListOfShape & (LocOpe_Generator::*)(const TopoDS_Face &)) &LocOpe_Generator::DescendantFace, "Returns the descendant face of <F>. <F> may belong to the original shape or to the 'generated' shape. The returned face may be a null shape (when <F> disappears).", py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_GeneratedShape.hxx
	py::class_<LocOpe_GeneratedShape, opencascade::handle<LocOpe_GeneratedShape>, Standard_Transient> cls_LocOpe_GeneratedShape(mod, "LocOpe_GeneratedShape", "None");
	cls_LocOpe_GeneratedShape.def("GeneratingEdges", (const TopTools_ListOfShape & (LocOpe_GeneratedShape::*)()) &LocOpe_GeneratedShape::GeneratingEdges, "None");
	cls_LocOpe_GeneratedShape.def("Generated", (TopoDS_Edge (LocOpe_GeneratedShape::*)(const TopoDS_Vertex &)) &LocOpe_GeneratedShape::Generated, "Returns the edge created by the vertex <V>. If none, must return a null shape.", py::arg("V"));
	cls_LocOpe_GeneratedShape.def("Generated", (TopoDS_Face (LocOpe_GeneratedShape::*)(const TopoDS_Edge &)) &LocOpe_GeneratedShape::Generated, "Returns the face created by the edge <E>. If none, must return a null shape.", py::arg("E"));
	cls_LocOpe_GeneratedShape.def("OrientedFaces", (const TopTools_ListOfShape & (LocOpe_GeneratedShape::*)()) &LocOpe_GeneratedShape::OrientedFaces, "Returns the list of correctly oriented generated faces.");
	cls_LocOpe_GeneratedShape.def_static("get_type_name_", (const char * (*)()) &LocOpe_GeneratedShape::get_type_name, "None");
	cls_LocOpe_GeneratedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LocOpe_GeneratedShape::get_type_descriptor, "None");
	cls_LocOpe_GeneratedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (LocOpe_GeneratedShape::*)() const ) &LocOpe_GeneratedShape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_GluedShape.hxx
	py::class_<LocOpe_GluedShape, opencascade::handle<LocOpe_GluedShape>, LocOpe_GeneratedShape> cls_LocOpe_GluedShape(mod, "LocOpe_GluedShape", "None");
	cls_LocOpe_GluedShape.def(py::init<>());
	cls_LocOpe_GluedShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_LocOpe_GluedShape.def("Init", (void (LocOpe_GluedShape::*)(const TopoDS_Shape &)) &LocOpe_GluedShape::Init, "None", py::arg("S"));
	cls_LocOpe_GluedShape.def("GlueOnFace", (void (LocOpe_GluedShape::*)(const TopoDS_Face &)) &LocOpe_GluedShape::GlueOnFace, "None", py::arg("F"));
	cls_LocOpe_GluedShape.def("GeneratingEdges", (const TopTools_ListOfShape & (LocOpe_GluedShape::*)()) &LocOpe_GluedShape::GeneratingEdges, "None");
	cls_LocOpe_GluedShape.def("Generated", (TopoDS_Edge (LocOpe_GluedShape::*)(const TopoDS_Vertex &)) &LocOpe_GluedShape::Generated, "Returns the edge created by the vertex <V>. If none, must return a null shape.", py::arg("V"));
	cls_LocOpe_GluedShape.def("Generated", (TopoDS_Face (LocOpe_GluedShape::*)(const TopoDS_Edge &)) &LocOpe_GluedShape::Generated, "Returns the face created by the edge <E>. If none, must return a null shape.", py::arg("E"));
	cls_LocOpe_GluedShape.def("OrientedFaces", (const TopTools_ListOfShape & (LocOpe_GluedShape::*)()) &LocOpe_GluedShape::OrientedFaces, "Returns the list of correctly oriented generated faces.");
	cls_LocOpe_GluedShape.def_static("get_type_name_", (const char * (*)()) &LocOpe_GluedShape::get_type_name, "None");
	cls_LocOpe_GluedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LocOpe_GluedShape::get_type_descriptor, "None");
	cls_LocOpe_GluedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (LocOpe_GluedShape::*)() const ) &LocOpe_GluedShape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_Prism.hxx
	py::class_<LocOpe_Prism, std::unique_ptr<LocOpe_Prism, Deleter<LocOpe_Prism>>> cls_LocOpe_Prism(mod, "LocOpe_Prism", "Defines a prism (using Prism from BRepSweep) with modifications provided for the Prism feature.");
	cls_LocOpe_Prism.def(py::init<>());
	cls_LocOpe_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &>(), py::arg("Base"), py::arg("V"));
	cls_LocOpe_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &, const gp_Vec &>(), py::arg("Base"), py::arg("V"), py::arg("Vectra"));
	cls_LocOpe_Prism.def("Perform", (void (LocOpe_Prism::*)(const TopoDS_Shape &, const gp_Vec &)) &LocOpe_Prism::Perform, "None", py::arg("Base"), py::arg("V"));
	cls_LocOpe_Prism.def("Perform", (void (LocOpe_Prism::*)(const TopoDS_Shape &, const gp_Vec &, const gp_Vec &)) &LocOpe_Prism::Perform, "None", py::arg("Base"), py::arg("V"), py::arg("Vtra"));
	cls_LocOpe_Prism.def("FirstShape", (const TopoDS_Shape & (LocOpe_Prism::*)() const ) &LocOpe_Prism::FirstShape, "None");
	cls_LocOpe_Prism.def("LastShape", (const TopoDS_Shape & (LocOpe_Prism::*)() const ) &LocOpe_Prism::LastShape, "None");
	cls_LocOpe_Prism.def("Shape", (const TopoDS_Shape & (LocOpe_Prism::*)() const ) &LocOpe_Prism::Shape, "None");
	cls_LocOpe_Prism.def("Shapes", (const TopTools_ListOfShape & (LocOpe_Prism::*)(const TopoDS_Shape &) const ) &LocOpe_Prism::Shapes, "None", py::arg("S"));
	cls_LocOpe_Prism.def("Curves", (void (LocOpe_Prism::*)(TColGeom_SequenceOfCurve &) const ) &LocOpe_Prism::Curves, "None", py::arg("SCurves"));
	cls_LocOpe_Prism.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_Prism::*)() const ) &LocOpe_Prism::BarycCurve, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_Revol.hxx
	py::class_<LocOpe_Revol, std::unique_ptr<LocOpe_Revol, Deleter<LocOpe_Revol>>> cls_LocOpe_Revol(mod, "LocOpe_Revol", "Defines a prism (using Prism from BRepSweep) with modifications provided for the Prism feature.");
	cls_LocOpe_Revol.def(py::init<>());
	cls_LocOpe_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real, const Standard_Real>(), py::arg("Base"), py::arg("Axis"), py::arg("Angle"), py::arg("angledec"));
	cls_LocOpe_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real>(), py::arg("Base"), py::arg("Axis"), py::arg("Angle"));
	cls_LocOpe_Revol.def("Perform", (void (LocOpe_Revol::*)(const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real, const Standard_Real)) &LocOpe_Revol::Perform, "None", py::arg("Base"), py::arg("Axis"), py::arg("Angle"), py::arg("angledec"));
	cls_LocOpe_Revol.def("Perform", (void (LocOpe_Revol::*)(const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real)) &LocOpe_Revol::Perform, "None", py::arg("Base"), py::arg("Axis"), py::arg("Angle"));
	cls_LocOpe_Revol.def("FirstShape", (const TopoDS_Shape & (LocOpe_Revol::*)() const ) &LocOpe_Revol::FirstShape, "None");
	cls_LocOpe_Revol.def("LastShape", (const TopoDS_Shape & (LocOpe_Revol::*)() const ) &LocOpe_Revol::LastShape, "None");
	cls_LocOpe_Revol.def("Shape", (const TopoDS_Shape & (LocOpe_Revol::*)() const ) &LocOpe_Revol::Shape, "None");
	cls_LocOpe_Revol.def("Shapes", (const TopTools_ListOfShape & (LocOpe_Revol::*)(const TopoDS_Shape &) const ) &LocOpe_Revol::Shapes, "None", py::arg("S"));
	cls_LocOpe_Revol.def("Curves", (void (LocOpe_Revol::*)(TColGeom_SequenceOfCurve &) const ) &LocOpe_Revol::Curves, "None", py::arg("SCurves"));
	cls_LocOpe_Revol.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_Revol::*)() const ) &LocOpe_Revol::BarycCurve, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_Pipe.hxx
	py::class_<LocOpe_Pipe, std::unique_ptr<LocOpe_Pipe, Deleter<LocOpe_Pipe>>> cls_LocOpe_Pipe(mod, "LocOpe_Pipe", "Defines a pipe (near from Pipe from BRepFill), with modifications provided for the Pipe feature.");
	cls_LocOpe_Pipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &>(), py::arg("Spine"), py::arg("Profile"));
	cls_LocOpe_Pipe.def("Spine", (const TopoDS_Shape & (LocOpe_Pipe::*)() const ) &LocOpe_Pipe::Spine, "None");
	cls_LocOpe_Pipe.def("Profile", (const TopoDS_Shape & (LocOpe_Pipe::*)() const ) &LocOpe_Pipe::Profile, "None");
	cls_LocOpe_Pipe.def("FirstShape", (const TopoDS_Shape & (LocOpe_Pipe::*)() const ) &LocOpe_Pipe::FirstShape, "None");
	cls_LocOpe_Pipe.def("LastShape", (const TopoDS_Shape & (LocOpe_Pipe::*)() const ) &LocOpe_Pipe::LastShape, "None");
	cls_LocOpe_Pipe.def("Shape", (const TopoDS_Shape & (LocOpe_Pipe::*)() const ) &LocOpe_Pipe::Shape, "None");
	cls_LocOpe_Pipe.def("Shapes", (const TopTools_ListOfShape & (LocOpe_Pipe::*)(const TopoDS_Shape &)) &LocOpe_Pipe::Shapes, "None", py::arg("S"));
	cls_LocOpe_Pipe.def("Curves", (const TColGeom_SequenceOfCurve & (LocOpe_Pipe::*)(const TColgp_SequenceOfPnt &)) &LocOpe_Pipe::Curves, "None", py::arg("Spt"));
	cls_LocOpe_Pipe.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_Pipe::*)()) &LocOpe_Pipe::BarycCurve, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_DPrism.hxx
	py::class_<LocOpe_DPrism, std::unique_ptr<LocOpe_DPrism, Deleter<LocOpe_DPrism>>> cls_LocOpe_DPrism(mod, "LocOpe_DPrism", "Defines a pipe (near from Pipe from BRepFill), with modifications provided for the Pipe feature.");
	cls_LocOpe_DPrism.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Spine"), py::arg("Height1"), py::arg("Height2"), py::arg("Angle"));
	cls_LocOpe_DPrism.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Real>(), py::arg("Spine"), py::arg("Height"), py::arg("Angle"));
	cls_LocOpe_DPrism.def("IsDone", (Standard_Boolean (LocOpe_DPrism::*)() const ) &LocOpe_DPrism::IsDone, "None");
	cls_LocOpe_DPrism.def("Spine", (const TopoDS_Shape & (LocOpe_DPrism::*)() const ) &LocOpe_DPrism::Spine, "None");
	cls_LocOpe_DPrism.def("Profile", (const TopoDS_Shape & (LocOpe_DPrism::*)() const ) &LocOpe_DPrism::Profile, "None");
	cls_LocOpe_DPrism.def("FirstShape", (const TopoDS_Shape & (LocOpe_DPrism::*)() const ) &LocOpe_DPrism::FirstShape, "None");
	cls_LocOpe_DPrism.def("LastShape", (const TopoDS_Shape & (LocOpe_DPrism::*)() const ) &LocOpe_DPrism::LastShape, "None");
	cls_LocOpe_DPrism.def("Shape", (const TopoDS_Shape & (LocOpe_DPrism::*)() const ) &LocOpe_DPrism::Shape, "None");
	cls_LocOpe_DPrism.def("Shapes", (const TopTools_ListOfShape & (LocOpe_DPrism::*)(const TopoDS_Shape &) const ) &LocOpe_DPrism::Shapes, "None", py::arg("S"));
	cls_LocOpe_DPrism.def("Curves", (void (LocOpe_DPrism::*)(TColGeom_SequenceOfCurve &) const ) &LocOpe_DPrism::Curves, "None", py::arg("SCurves"));
	cls_LocOpe_DPrism.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_DPrism::*)() const ) &LocOpe_DPrism::BarycCurve, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_LinearForm.hxx
	py::class_<LocOpe_LinearForm, std::unique_ptr<LocOpe_LinearForm, Deleter<LocOpe_LinearForm>>> cls_LocOpe_LinearForm(mod, "LocOpe_LinearForm", "Defines a linear form (using Prism from BRepSweep) with modifications provided for the LinearForm feature.");
	cls_LocOpe_LinearForm.def(py::init<>());
	cls_LocOpe_LinearForm.def(py::init<const TopoDS_Shape &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Base"), py::arg("V"), py::arg("Pnt1"), py::arg("Pnt2"));
	cls_LocOpe_LinearForm.def(py::init<const TopoDS_Shape &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Base"), py::arg("V"), py::arg("Vectra"), py::arg("Pnt1"), py::arg("Pnt2"));
	cls_LocOpe_LinearForm.def("Perform", (void (LocOpe_LinearForm::*)(const TopoDS_Shape &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &)) &LocOpe_LinearForm::Perform, "None", py::arg("Base"), py::arg("V"), py::arg("Pnt1"), py::arg("Pnt2"));
	cls_LocOpe_LinearForm.def("Perform", (void (LocOpe_LinearForm::*)(const TopoDS_Shape &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &)) &LocOpe_LinearForm::Perform, "None", py::arg("Base"), py::arg("V"), py::arg("Vectra"), py::arg("Pnt1"), py::arg("Pnt2"));
	cls_LocOpe_LinearForm.def("FirstShape", (const TopoDS_Shape & (LocOpe_LinearForm::*)() const ) &LocOpe_LinearForm::FirstShape, "None");
	cls_LocOpe_LinearForm.def("LastShape", (const TopoDS_Shape & (LocOpe_LinearForm::*)() const ) &LocOpe_LinearForm::LastShape, "None");
	cls_LocOpe_LinearForm.def("Shape", (const TopoDS_Shape & (LocOpe_LinearForm::*)() const ) &LocOpe_LinearForm::Shape, "None");
	cls_LocOpe_LinearForm.def("Shapes", (const TopTools_ListOfShape & (LocOpe_LinearForm::*)(const TopoDS_Shape &) const ) &LocOpe_LinearForm::Shapes, "None", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_RevolutionForm.hxx
	py::class_<LocOpe_RevolutionForm, std::unique_ptr<LocOpe_RevolutionForm, Deleter<LocOpe_RevolutionForm>>> cls_LocOpe_RevolutionForm(mod, "LocOpe_RevolutionForm", "Defines a revolution form (using Revol from BRepSweep) with modifications provided for the RevolutionForm feature.");
	cls_LocOpe_RevolutionForm.def(py::init<>());
	cls_LocOpe_RevolutionForm.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real>(), py::arg("Base"), py::arg("Axe"), py::arg("Angle"));
	cls_LocOpe_RevolutionForm.def("Perform", (void (LocOpe_RevolutionForm::*)(const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real)) &LocOpe_RevolutionForm::Perform, "None", py::arg("Base"), py::arg("Axe"), py::arg("Angle"));
	cls_LocOpe_RevolutionForm.def("FirstShape", (const TopoDS_Shape & (LocOpe_RevolutionForm::*)() const ) &LocOpe_RevolutionForm::FirstShape, "None");
	cls_LocOpe_RevolutionForm.def("LastShape", (const TopoDS_Shape & (LocOpe_RevolutionForm::*)() const ) &LocOpe_RevolutionForm::LastShape, "None");
	cls_LocOpe_RevolutionForm.def("Shape", (const TopoDS_Shape & (LocOpe_RevolutionForm::*)() const ) &LocOpe_RevolutionForm::Shape, "None");
	cls_LocOpe_RevolutionForm.def("Shapes", (const TopTools_ListOfShape & (LocOpe_RevolutionForm::*)(const TopoDS_Shape &) const ) &LocOpe_RevolutionForm::Shapes, "None", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_FindEdges.hxx
	py::class_<LocOpe_FindEdges, std::unique_ptr<LocOpe_FindEdges, Deleter<LocOpe_FindEdges>>> cls_LocOpe_FindEdges(mod, "LocOpe_FindEdges", "None");
	cls_LocOpe_FindEdges.def(py::init<>());
	cls_LocOpe_FindEdges.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("FFrom"), py::arg("FTo"));
	cls_LocOpe_FindEdges.def("Set", (void (LocOpe_FindEdges::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &LocOpe_FindEdges::Set, "None", py::arg("FFrom"), py::arg("FTo"));
	cls_LocOpe_FindEdges.def("InitIterator", (void (LocOpe_FindEdges::*)()) &LocOpe_FindEdges::InitIterator, "None");
	cls_LocOpe_FindEdges.def("More", (Standard_Boolean (LocOpe_FindEdges::*)() const ) &LocOpe_FindEdges::More, "None");
	cls_LocOpe_FindEdges.def("EdgeFrom", (const TopoDS_Edge & (LocOpe_FindEdges::*)() const ) &LocOpe_FindEdges::EdgeFrom, "None");
	cls_LocOpe_FindEdges.def("EdgeTo", (const TopoDS_Edge & (LocOpe_FindEdges::*)() const ) &LocOpe_FindEdges::EdgeTo, "None");
	cls_LocOpe_FindEdges.def("Next", (void (LocOpe_FindEdges::*)()) &LocOpe_FindEdges::Next, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_FindEdgesInFace.hxx
	py::class_<LocOpe_FindEdgesInFace, std::unique_ptr<LocOpe_FindEdgesInFace, Deleter<LocOpe_FindEdgesInFace>>> cls_LocOpe_FindEdgesInFace(mod, "LocOpe_FindEdgesInFace", "None");
	cls_LocOpe_FindEdgesInFace.def(py::init<>());
	cls_LocOpe_FindEdgesInFace.def(py::init<const TopoDS_Shape &, const TopoDS_Face &>(), py::arg("S"), py::arg("F"));
	cls_LocOpe_FindEdgesInFace.def("Set", (void (LocOpe_FindEdgesInFace::*)(const TopoDS_Shape &, const TopoDS_Face &)) &LocOpe_FindEdgesInFace::Set, "None", py::arg("S"), py::arg("F"));
	cls_LocOpe_FindEdgesInFace.def("Init", (void (LocOpe_FindEdgesInFace::*)()) &LocOpe_FindEdgesInFace::Init, "None");
	cls_LocOpe_FindEdgesInFace.def("More", (Standard_Boolean (LocOpe_FindEdgesInFace::*)() const ) &LocOpe_FindEdgesInFace::More, "None");
	cls_LocOpe_FindEdgesInFace.def("Edge", (const TopoDS_Edge & (LocOpe_FindEdgesInFace::*)() const ) &LocOpe_FindEdgesInFace::Edge, "None");
	cls_LocOpe_FindEdgesInFace.def("Next", (void (LocOpe_FindEdgesInFace::*)()) &LocOpe_FindEdgesInFace::Next, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_PntFace.hxx
	py::class_<LocOpe_PntFace, std::unique_ptr<LocOpe_PntFace, Deleter<LocOpe_PntFace>>> cls_LocOpe_PntFace(mod, "LocOpe_PntFace", "None");
	cls_LocOpe_PntFace.def(py::init<>());
	cls_LocOpe_PntFace.def(py::init<const gp_Pnt &, const TopoDS_Face &, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("F"), py::arg("Or"), py::arg("Param"), py::arg("UPar"), py::arg("VPar"));
	cls_LocOpe_PntFace.def("Pnt", (const gp_Pnt & (LocOpe_PntFace::*)() const ) &LocOpe_PntFace::Pnt, "None");
	cls_LocOpe_PntFace.def("Face", (const TopoDS_Face & (LocOpe_PntFace::*)() const ) &LocOpe_PntFace::Face, "None");
	cls_LocOpe_PntFace.def("Orientation", (TopAbs_Orientation (LocOpe_PntFace::*)() const ) &LocOpe_PntFace::Orientation, "None");
	cls_LocOpe_PntFace.def("ChangeOrientation", (TopAbs_Orientation & (LocOpe_PntFace::*)()) &LocOpe_PntFace::ChangeOrientation, "None");
	cls_LocOpe_PntFace.def("Parameter", (Standard_Real (LocOpe_PntFace::*)() const ) &LocOpe_PntFace::Parameter, "None");
	cls_LocOpe_PntFace.def("UParameter", (Standard_Real (LocOpe_PntFace::*)() const ) &LocOpe_PntFace::UParameter, "None");
	cls_LocOpe_PntFace.def("VParameter", (Standard_Real (LocOpe_PntFace::*)() const ) &LocOpe_PntFace::VParameter, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_CurveShapeIntersector.hxx
	py::class_<LocOpe_CurveShapeIntersector, std::unique_ptr<LocOpe_CurveShapeIntersector, Deleter<LocOpe_CurveShapeIntersector>>> cls_LocOpe_CurveShapeIntersector(mod, "LocOpe_CurveShapeIntersector", "This class provides the intersection between an axis or a circle and the faces of a shape. The intersection points are sorted in increasing parameter along the axis.");
	cls_LocOpe_CurveShapeIntersector.def(py::init<>());
	cls_LocOpe_CurveShapeIntersector.def(py::init<const gp_Ax1 &, const TopoDS_Shape &>(), py::arg("Axis"), py::arg("S"));
	cls_LocOpe_CurveShapeIntersector.def(py::init<const gp_Circ &, const TopoDS_Shape &>(), py::arg("C"), py::arg("S"));
	cls_LocOpe_CurveShapeIntersector.def("Init", (void (LocOpe_CurveShapeIntersector::*)(const gp_Ax1 &, const TopoDS_Shape &)) &LocOpe_CurveShapeIntersector::Init, "Performs the intersection between <Ax1 and <S>.", py::arg("Axis"), py::arg("S"));
	cls_LocOpe_CurveShapeIntersector.def("Init", (void (LocOpe_CurveShapeIntersector::*)(const gp_Circ &, const TopoDS_Shape &)) &LocOpe_CurveShapeIntersector::Init, "Performs the intersection between <Ax1 and <S>.", py::arg("C"), py::arg("S"));
	cls_LocOpe_CurveShapeIntersector.def("IsDone", (Standard_Boolean (LocOpe_CurveShapeIntersector::*)() const ) &LocOpe_CurveShapeIntersector::IsDone, "Returns <Standard_True> if the intersection has been done.");
	cls_LocOpe_CurveShapeIntersector.def("NbPoints", (Standard_Integer (LocOpe_CurveShapeIntersector::*)() const ) &LocOpe_CurveShapeIntersector::NbPoints, "Returns the number of intersection point.");
	cls_LocOpe_CurveShapeIntersector.def("Point", (const LocOpe_PntFace & (LocOpe_CurveShapeIntersector::*)(const Standard_Integer) const ) &LocOpe_CurveShapeIntersector::Point, "Returns the intersection point of range <Index>. The points are sorted in increasing order of parameter along the axis.", py::arg("Index"));
	cls_LocOpe_CurveShapeIntersector.def("LocalizeAfter", (Standard_Boolean (LocOpe_CurveShapeIntersector::*)(const Standard_Real, TopAbs_Orientation &, Standard_Integer &, Standard_Integer &) const ) &LocOpe_CurveShapeIntersector::LocalizeAfter, "Searches the first intersection point located after the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo).", py::arg("From"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
	cls_LocOpe_CurveShapeIntersector.def("LocalizeBefore", (Standard_Boolean (LocOpe_CurveShapeIntersector::*)(const Standard_Real, TopAbs_Orientation &, Standard_Integer &, Standard_Integer &) const ) &LocOpe_CurveShapeIntersector::LocalizeBefore, "Searches the first intersection point located before the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo).", py::arg("From"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
	cls_LocOpe_CurveShapeIntersector.def("LocalizeAfter", (Standard_Boolean (LocOpe_CurveShapeIntersector::*)(const Standard_Integer, TopAbs_Orientation &, Standard_Integer &, Standard_Integer &) const ) &LocOpe_CurveShapeIntersector::LocalizeAfter, "Searches the first intersection point located after the index <FromInd> ( >= FromInd + 1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo).", py::arg("FromInd"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
	cls_LocOpe_CurveShapeIntersector.def("LocalizeBefore", (Standard_Boolean (LocOpe_CurveShapeIntersector::*)(const Standard_Integer, TopAbs_Orientation &, Standard_Integer &, Standard_Integer &) const ) &LocOpe_CurveShapeIntersector::LocalizeBefore, "Searches the first intersection point located before the index <FromInd> ( <= FromInd -1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo).", py::arg("FromInd"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_CSIntersector.hxx
	py::class_<LocOpe_CSIntersector, std::unique_ptr<LocOpe_CSIntersector, Deleter<LocOpe_CSIntersector>>> cls_LocOpe_CSIntersector(mod, "LocOpe_CSIntersector", "This class provides the intersection between a set of axis or a circle and the faces of a shape. The intersection points are sorted in increasing parameter along each axis or circle.");
	cls_LocOpe_CSIntersector.def(py::init<>());
	cls_LocOpe_CSIntersector.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_LocOpe_CSIntersector.def("Init", (void (LocOpe_CSIntersector::*)(const TopoDS_Shape &)) &LocOpe_CSIntersector::Init, "Performs the intersection between <Ax1 and <S>.", py::arg("S"));
	cls_LocOpe_CSIntersector.def("Perform", (void (LocOpe_CSIntersector::*)(const LocOpe_SequenceOfLin &)) &LocOpe_CSIntersector::Perform, "None", py::arg("Slin"));
	cls_LocOpe_CSIntersector.def("Perform", (void (LocOpe_CSIntersector::*)(const LocOpe_SequenceOfCirc &)) &LocOpe_CSIntersector::Perform, "None", py::arg("Scir"));
	cls_LocOpe_CSIntersector.def("Perform", (void (LocOpe_CSIntersector::*)(const TColGeom_SequenceOfCurve &)) &LocOpe_CSIntersector::Perform, "None", py::arg("Scur"));
	cls_LocOpe_CSIntersector.def("IsDone", (Standard_Boolean (LocOpe_CSIntersector::*)() const ) &LocOpe_CSIntersector::IsDone, "Returns <Standard_True> if the intersection has been done.");
	cls_LocOpe_CSIntersector.def("NbPoints", (Standard_Integer (LocOpe_CSIntersector::*)(const Standard_Integer) const ) &LocOpe_CSIntersector::NbPoints, "Returns the number of intersection point on the element of range <I>.", py::arg("I"));
	cls_LocOpe_CSIntersector.def("Point", (const LocOpe_PntFace & (LocOpe_CSIntersector::*)(const Standard_Integer, const Standard_Integer) const ) &LocOpe_CSIntersector::Point, "Returns the intersection point of range <Index> on element of range <I>. The points are sorted in increasing order of parameter along the axis.", py::arg("I"), py::arg("Index"));
	cls_LocOpe_CSIntersector.def("LocalizeAfter", (Standard_Boolean (LocOpe_CSIntersector::*)(const Standard_Integer, const Standard_Real, const Standard_Real, TopAbs_Orientation &, Standard_Integer &, Standard_Integer &) const ) &LocOpe_CSIntersector::LocalizeAfter, "On the element of range <I>, searches the first intersection point located after the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("From"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
	cls_LocOpe_CSIntersector.def("LocalizeBefore", (Standard_Boolean (LocOpe_CSIntersector::*)(const Standard_Integer, const Standard_Real, const Standard_Real, TopAbs_Orientation &, Standard_Integer &, Standard_Integer &) const ) &LocOpe_CSIntersector::LocalizeBefore, "On the element of range <I>, searches the first intersection point located before the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("From"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
	cls_LocOpe_CSIntersector.def("LocalizeAfter", (Standard_Boolean (LocOpe_CSIntersector::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, TopAbs_Orientation &, Standard_Integer &, Standard_Integer &) const ) &LocOpe_CSIntersector::LocalizeAfter, "On the element of range <I>, searches the first intersection point located after the index <FromInd> ( >= FromInd + 1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("FromInd"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
	cls_LocOpe_CSIntersector.def("LocalizeBefore", (Standard_Boolean (LocOpe_CSIntersector::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, TopAbs_Orientation &, Standard_Integer &, Standard_Integer &) const ) &LocOpe_CSIntersector::LocalizeBefore, "On the element of range <I>, searches the first intersection point located before the index <FromInd> ( <= FromInd -1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("FromInd"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
	cls_LocOpe_CSIntersector.def("Destroy", (void (LocOpe_CSIntersector::*)()) &LocOpe_CSIntersector::Destroy, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_BuildShape.hxx
	py::class_<LocOpe_BuildShape, std::unique_ptr<LocOpe_BuildShape, Deleter<LocOpe_BuildShape>>> cls_LocOpe_BuildShape(mod, "LocOpe_BuildShape", "None");
	cls_LocOpe_BuildShape.def(py::init<>());
	cls_LocOpe_BuildShape.def(py::init<const TopTools_ListOfShape &>(), py::arg("L"));
	cls_LocOpe_BuildShape.def("Perform", (void (LocOpe_BuildShape::*)(const TopTools_ListOfShape &)) &LocOpe_BuildShape::Perform, "Builds shape(s) from the list <L>. Uses only the faces of <L>.", py::arg("L"));
	cls_LocOpe_BuildShape.def("Shape", (const TopoDS_Shape & (LocOpe_BuildShape::*)() const ) &LocOpe_BuildShape::Shape, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_SplitDrafts.hxx
	py::class_<LocOpe_SplitDrafts, std::unique_ptr<LocOpe_SplitDrafts, Deleter<LocOpe_SplitDrafts>>> cls_LocOpe_SplitDrafts(mod, "LocOpe_SplitDrafts", "This class provides a tool to realize the following operations on a shape : - split a face of the shape with a wire, - put draft angle on both side of the wire. For each side, the draft angle may be different.");
	cls_LocOpe_SplitDrafts.def(py::init<>());
	cls_LocOpe_SplitDrafts.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_LocOpe_SplitDrafts.def("Init", (void (LocOpe_SplitDrafts::*)(const TopoDS_Shape &)) &LocOpe_SplitDrafts::Init, "Initializes the algoritm with the shape <S>.", py::arg("S"));
	cls_LocOpe_SplitDrafts.def("Perform", [](LocOpe_SplitDrafts &self, const TopoDS_Face & a0, const TopoDS_Wire & a1, const gp_Dir & a2, const gp_Pln & a3, const Standard_Real a4, const gp_Dir & a5, const gp_Pln & a6, const Standard_Real a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("F"), py::arg("W"), py::arg("Extractg"), py::arg("NPlg"), py::arg("Angleg"), py::arg("Extractd"), py::arg("NPld"), py::arg("Angled"));
	cls_LocOpe_SplitDrafts.def("Perform", [](LocOpe_SplitDrafts &self, const TopoDS_Face & a0, const TopoDS_Wire & a1, const gp_Dir & a2, const gp_Pln & a3, const Standard_Real a4, const gp_Dir & a5, const gp_Pln & a6, const Standard_Real a7, const Standard_Boolean a8) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8); }, py::arg("F"), py::arg("W"), py::arg("Extractg"), py::arg("NPlg"), py::arg("Angleg"), py::arg("Extractd"), py::arg("NPld"), py::arg("Angled"), py::arg("ModifyLeft"));
	cls_LocOpe_SplitDrafts.def("Perform", (void (LocOpe_SplitDrafts::*)(const TopoDS_Face &, const TopoDS_Wire &, const gp_Dir &, const gp_Pln &, const Standard_Real, const gp_Dir &, const gp_Pln &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &LocOpe_SplitDrafts::Perform, "Splits the face <F> of the former given shape with the wire <W>. The wire is assumed to lie on the face. Puts a draft angle on both parts of the wire. <Extractg>, <Nplg>, <Angleg> define the arguments for the left part of the wire. <Extractd>, <Npld>, <Angled> define the arguments for the right part of the wire. The draft angle is measured with the direction <Extract>. <Npl> defines the neutral plane (points belonging to the neutral plane are not modified). <Angle> is the value of the draft angle. If <ModifyLeft> is set to <Standard_False>, no draft angle is applied to the left part of the wire. If <ModifyRight> is set to <Standard_False>,no draft angle is applied to the right part of the wire.", py::arg("F"), py::arg("W"), py::arg("Extractg"), py::arg("NPlg"), py::arg("Angleg"), py::arg("Extractd"), py::arg("NPld"), py::arg("Angled"), py::arg("ModifyLeft"), py::arg("ModifyRight"));
	cls_LocOpe_SplitDrafts.def("Perform", (void (LocOpe_SplitDrafts::*)(const TopoDS_Face &, const TopoDS_Wire &, const gp_Dir &, const gp_Pln &, const Standard_Real)) &LocOpe_SplitDrafts::Perform, "Splits the face <F> of the former given shape with the wire <W>. The wire is assumed to lie on the face. Puts a draft angle on the left part of the wire. The draft angle is measured with the direction <Extract>. <Npl> defines the neutral plane (points belonging to the neutral plane are not modified). <Angle> is the value of the draft angle.", py::arg("F"), py::arg("W"), py::arg("Extract"), py::arg("NPl"), py::arg("Angle"));
	cls_LocOpe_SplitDrafts.def("IsDone", (Standard_Boolean (LocOpe_SplitDrafts::*)() const ) &LocOpe_SplitDrafts::IsDone, "Returns <Standard_True> if the modification has been succesfully performed.");
	cls_LocOpe_SplitDrafts.def("OriginalShape", (const TopoDS_Shape & (LocOpe_SplitDrafts::*)() const ) &LocOpe_SplitDrafts::OriginalShape, "None");
	cls_LocOpe_SplitDrafts.def("Shape", (const TopoDS_Shape & (LocOpe_SplitDrafts::*)() const ) &LocOpe_SplitDrafts::Shape, "Returns the modified shape.");
	cls_LocOpe_SplitDrafts.def("ShapesFromShape", (const TopTools_ListOfShape & (LocOpe_SplitDrafts::*)(const TopoDS_Shape &) const ) &LocOpe_SplitDrafts::ShapesFromShape, "Manages the descendant shapes.", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_BuildWires.hxx
	py::class_<LocOpe_BuildWires, std::unique_ptr<LocOpe_BuildWires, Deleter<LocOpe_BuildWires>>> cls_LocOpe_BuildWires(mod, "LocOpe_BuildWires", "None");
	cls_LocOpe_BuildWires.def(py::init<>());
	cls_LocOpe_BuildWires.def(py::init<const TopTools_ListOfShape &, const opencascade::handle<LocOpe_WiresOnShape> &>(), py::arg("Ledges"), py::arg("PW"));
	cls_LocOpe_BuildWires.def("Perform", (void (LocOpe_BuildWires::*)(const TopTools_ListOfShape &, const opencascade::handle<LocOpe_WiresOnShape> &)) &LocOpe_BuildWires::Perform, "None", py::arg("Ledges"), py::arg("PW"));
	cls_LocOpe_BuildWires.def("IsDone", (Standard_Boolean (LocOpe_BuildWires::*)() const ) &LocOpe_BuildWires::IsDone, "None");
	cls_LocOpe_BuildWires.def("Result", (const TopTools_ListOfShape & (LocOpe_BuildWires::*)() const ) &LocOpe_BuildWires::Result, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe.hxx
	py::class_<LocOpe, std::unique_ptr<LocOpe, Deleter<LocOpe>>> cls_LocOpe(mod, "LocOpe", "Provides tools to implement local topological operations on a shape.");
	cls_LocOpe.def(py::init<>());
	cls_LocOpe.def_static("Closed_", (Standard_Boolean (*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe::Closed, "Returns Standard_True when the wire <W> is closed on the face <OnF>.", py::arg("W"), py::arg("OnF"));
	cls_LocOpe.def_static("Closed_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &LocOpe::Closed, "Returns Standard_True when the edge <E> is closed on the face <OnF>.", py::arg("E"), py::arg("OnF"));
	cls_LocOpe.def_static("TgtFaces_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &LocOpe::TgtFaces, "Returns Standard_True when the faces are tangent", py::arg("E"), py::arg("F1"), py::arg("F2"));
	cls_LocOpe.def_static("SampleEdges_", (void (*)(const TopoDS_Shape &, TColgp_SequenceOfPnt &)) &LocOpe::SampleEdges, "None", py::arg("S"), py::arg("Pt"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<LocOpe_SequenceOfLin, std::unique_ptr<LocOpe_SequenceOfLin, Deleter<LocOpe_SequenceOfLin>>, NCollection_BaseSequence> cls_LocOpe_SequenceOfLin(mod, "LocOpe_SequenceOfLin", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_LocOpe_SequenceOfLin.def(py::init<>());
	cls_LocOpe_SequenceOfLin.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_LocOpe_SequenceOfLin.def(py::init([] (const LocOpe_SequenceOfLin &other) {return new LocOpe_SequenceOfLin(other);}), "Copy constructor", py::arg("other"));
	cls_LocOpe_SequenceOfLin.def("begin", (LocOpe_SequenceOfLin::iterator (LocOpe_SequenceOfLin::*)() const ) &LocOpe_SequenceOfLin::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_LocOpe_SequenceOfLin.def("end", (LocOpe_SequenceOfLin::iterator (LocOpe_SequenceOfLin::*)() const ) &LocOpe_SequenceOfLin::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_LocOpe_SequenceOfLin.def("cbegin", (LocOpe_SequenceOfLin::const_iterator (LocOpe_SequenceOfLin::*)() const ) &LocOpe_SequenceOfLin::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_LocOpe_SequenceOfLin.def("cend", (LocOpe_SequenceOfLin::const_iterator (LocOpe_SequenceOfLin::*)() const ) &LocOpe_SequenceOfLin::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_LocOpe_SequenceOfLin.def("Size", (Standard_Integer (LocOpe_SequenceOfLin::*)() const ) &LocOpe_SequenceOfLin::Size, "Number of items");
	cls_LocOpe_SequenceOfLin.def("Length", (Standard_Integer (LocOpe_SequenceOfLin::*)() const ) &LocOpe_SequenceOfLin::Length, "Number of items");
	cls_LocOpe_SequenceOfLin.def("Lower", (Standard_Integer (LocOpe_SequenceOfLin::*)() const ) &LocOpe_SequenceOfLin::Lower, "Method for consistency with other collections.");
	cls_LocOpe_SequenceOfLin.def("Upper", (Standard_Integer (LocOpe_SequenceOfLin::*)() const ) &LocOpe_SequenceOfLin::Upper, "Method for consistency with other collections.");
	cls_LocOpe_SequenceOfLin.def("IsEmpty", (Standard_Boolean (LocOpe_SequenceOfLin::*)() const ) &LocOpe_SequenceOfLin::IsEmpty, "Empty query");
	cls_LocOpe_SequenceOfLin.def("Reverse", (void (LocOpe_SequenceOfLin::*)()) &LocOpe_SequenceOfLin::Reverse, "Reverse sequence");
	cls_LocOpe_SequenceOfLin.def("Exchange", (void (LocOpe_SequenceOfLin::*)(const Standard_Integer, const Standard_Integer)) &LocOpe_SequenceOfLin::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_LocOpe_SequenceOfLin.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &LocOpe_SequenceOfLin::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_LocOpe_SequenceOfLin.def("Clear", [](LocOpe_SequenceOfLin &self) -> void { return self.Clear(); });
	cls_LocOpe_SequenceOfLin.def("Clear", (void (LocOpe_SequenceOfLin::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &LocOpe_SequenceOfLin::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_LocOpe_SequenceOfLin.def("Assign", (LocOpe_SequenceOfLin & (LocOpe_SequenceOfLin::*)(const LocOpe_SequenceOfLin &)) &LocOpe_SequenceOfLin::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_LocOpe_SequenceOfLin.def("assign", (LocOpe_SequenceOfLin & (LocOpe_SequenceOfLin::*)(const LocOpe_SequenceOfLin &)) &LocOpe_SequenceOfLin::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_LocOpe_SequenceOfLin.def("Remove", (void (LocOpe_SequenceOfLin::*)(LocOpe_SequenceOfLin::Iterator &)) &LocOpe_SequenceOfLin::Remove, "Remove one item", py::arg("thePosition"));
	cls_LocOpe_SequenceOfLin.def("Remove", (void (LocOpe_SequenceOfLin::*)(const Standard_Integer)) &LocOpe_SequenceOfLin::Remove, "Remove one item", py::arg("theIndex"));
	cls_LocOpe_SequenceOfLin.def("Remove", (void (LocOpe_SequenceOfLin::*)(const Standard_Integer, const Standard_Integer)) &LocOpe_SequenceOfLin::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_LocOpe_SequenceOfLin.def("Append", (void (LocOpe_SequenceOfLin::*)(const gp_Lin &)) &LocOpe_SequenceOfLin::Append, "Append one item", py::arg("theItem"));
	cls_LocOpe_SequenceOfLin.def("Append", (void (LocOpe_SequenceOfLin::*)(LocOpe_SequenceOfLin &)) &LocOpe_SequenceOfLin::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_LocOpe_SequenceOfLin.def("Prepend", (void (LocOpe_SequenceOfLin::*)(const gp_Lin &)) &LocOpe_SequenceOfLin::Prepend, "Prepend one item", py::arg("theItem"));
	cls_LocOpe_SequenceOfLin.def("Prepend", (void (LocOpe_SequenceOfLin::*)(LocOpe_SequenceOfLin &)) &LocOpe_SequenceOfLin::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_LocOpe_SequenceOfLin.def("InsertBefore", (void (LocOpe_SequenceOfLin::*)(const Standard_Integer, const gp_Lin &)) &LocOpe_SequenceOfLin::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_LocOpe_SequenceOfLin.def("InsertBefore", (void (LocOpe_SequenceOfLin::*)(const Standard_Integer, LocOpe_SequenceOfLin &)) &LocOpe_SequenceOfLin::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_LocOpe_SequenceOfLin.def("InsertAfter", (void (LocOpe_SequenceOfLin::*)(LocOpe_SequenceOfLin::Iterator &, const gp_Lin &)) &LocOpe_SequenceOfLin::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_LocOpe_SequenceOfLin.def("InsertAfter", (void (LocOpe_SequenceOfLin::*)(const Standard_Integer, LocOpe_SequenceOfLin &)) &LocOpe_SequenceOfLin::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_LocOpe_SequenceOfLin.def("InsertAfter", (void (LocOpe_SequenceOfLin::*)(const Standard_Integer, const gp_Lin &)) &LocOpe_SequenceOfLin::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_LocOpe_SequenceOfLin.def("Split", (void (LocOpe_SequenceOfLin::*)(const Standard_Integer, LocOpe_SequenceOfLin &)) &LocOpe_SequenceOfLin::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_LocOpe_SequenceOfLin.def("First", (const gp_Lin & (LocOpe_SequenceOfLin::*)() const ) &LocOpe_SequenceOfLin::First, "First item access");
	cls_LocOpe_SequenceOfLin.def("ChangeFirst", (gp_Lin & (LocOpe_SequenceOfLin::*)()) &LocOpe_SequenceOfLin::ChangeFirst, "First item access");
	cls_LocOpe_SequenceOfLin.def("Last", (const gp_Lin & (LocOpe_SequenceOfLin::*)() const ) &LocOpe_SequenceOfLin::Last, "Last item access");
	cls_LocOpe_SequenceOfLin.def("ChangeLast", (gp_Lin & (LocOpe_SequenceOfLin::*)()) &LocOpe_SequenceOfLin::ChangeLast, "Last item access");
	cls_LocOpe_SequenceOfLin.def("Value", (const gp_Lin & (LocOpe_SequenceOfLin::*)(const Standard_Integer) const ) &LocOpe_SequenceOfLin::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_LocOpe_SequenceOfLin.def("__call__", (const gp_Lin & (LocOpe_SequenceOfLin::*)(const Standard_Integer) const ) &LocOpe_SequenceOfLin::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_LocOpe_SequenceOfLin.def("ChangeValue", (gp_Lin & (LocOpe_SequenceOfLin::*)(const Standard_Integer)) &LocOpe_SequenceOfLin::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_LocOpe_SequenceOfLin.def("__call__", (gp_Lin & (LocOpe_SequenceOfLin::*)(const Standard_Integer)) &LocOpe_SequenceOfLin::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_LocOpe_SequenceOfLin.def("SetValue", (void (LocOpe_SequenceOfLin::*)(const Standard_Integer, const gp_Lin &)) &LocOpe_SequenceOfLin::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_LocOpe_SequenceOfLin.def("__iter__", [](const LocOpe_SequenceOfLin &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<LocOpe_SequenceOfCirc, std::unique_ptr<LocOpe_SequenceOfCirc, Deleter<LocOpe_SequenceOfCirc>>, NCollection_BaseSequence> cls_LocOpe_SequenceOfCirc(mod, "LocOpe_SequenceOfCirc", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_LocOpe_SequenceOfCirc.def(py::init<>());
	cls_LocOpe_SequenceOfCirc.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_LocOpe_SequenceOfCirc.def(py::init([] (const LocOpe_SequenceOfCirc &other) {return new LocOpe_SequenceOfCirc(other);}), "Copy constructor", py::arg("other"));
	cls_LocOpe_SequenceOfCirc.def("begin", (LocOpe_SequenceOfCirc::iterator (LocOpe_SequenceOfCirc::*)() const ) &LocOpe_SequenceOfCirc::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_LocOpe_SequenceOfCirc.def("end", (LocOpe_SequenceOfCirc::iterator (LocOpe_SequenceOfCirc::*)() const ) &LocOpe_SequenceOfCirc::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_LocOpe_SequenceOfCirc.def("cbegin", (LocOpe_SequenceOfCirc::const_iterator (LocOpe_SequenceOfCirc::*)() const ) &LocOpe_SequenceOfCirc::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_LocOpe_SequenceOfCirc.def("cend", (LocOpe_SequenceOfCirc::const_iterator (LocOpe_SequenceOfCirc::*)() const ) &LocOpe_SequenceOfCirc::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_LocOpe_SequenceOfCirc.def("Size", (Standard_Integer (LocOpe_SequenceOfCirc::*)() const ) &LocOpe_SequenceOfCirc::Size, "Number of items");
	cls_LocOpe_SequenceOfCirc.def("Length", (Standard_Integer (LocOpe_SequenceOfCirc::*)() const ) &LocOpe_SequenceOfCirc::Length, "Number of items");
	cls_LocOpe_SequenceOfCirc.def("Lower", (Standard_Integer (LocOpe_SequenceOfCirc::*)() const ) &LocOpe_SequenceOfCirc::Lower, "Method for consistency with other collections.");
	cls_LocOpe_SequenceOfCirc.def("Upper", (Standard_Integer (LocOpe_SequenceOfCirc::*)() const ) &LocOpe_SequenceOfCirc::Upper, "Method for consistency with other collections.");
	cls_LocOpe_SequenceOfCirc.def("IsEmpty", (Standard_Boolean (LocOpe_SequenceOfCirc::*)() const ) &LocOpe_SequenceOfCirc::IsEmpty, "Empty query");
	cls_LocOpe_SequenceOfCirc.def("Reverse", (void (LocOpe_SequenceOfCirc::*)()) &LocOpe_SequenceOfCirc::Reverse, "Reverse sequence");
	cls_LocOpe_SequenceOfCirc.def("Exchange", (void (LocOpe_SequenceOfCirc::*)(const Standard_Integer, const Standard_Integer)) &LocOpe_SequenceOfCirc::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_LocOpe_SequenceOfCirc.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &LocOpe_SequenceOfCirc::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_LocOpe_SequenceOfCirc.def("Clear", [](LocOpe_SequenceOfCirc &self) -> void { return self.Clear(); });
	cls_LocOpe_SequenceOfCirc.def("Clear", (void (LocOpe_SequenceOfCirc::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &LocOpe_SequenceOfCirc::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_LocOpe_SequenceOfCirc.def("Assign", (LocOpe_SequenceOfCirc & (LocOpe_SequenceOfCirc::*)(const LocOpe_SequenceOfCirc &)) &LocOpe_SequenceOfCirc::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_LocOpe_SequenceOfCirc.def("assign", (LocOpe_SequenceOfCirc & (LocOpe_SequenceOfCirc::*)(const LocOpe_SequenceOfCirc &)) &LocOpe_SequenceOfCirc::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_LocOpe_SequenceOfCirc.def("Remove", (void (LocOpe_SequenceOfCirc::*)(LocOpe_SequenceOfCirc::Iterator &)) &LocOpe_SequenceOfCirc::Remove, "Remove one item", py::arg("thePosition"));
	cls_LocOpe_SequenceOfCirc.def("Remove", (void (LocOpe_SequenceOfCirc::*)(const Standard_Integer)) &LocOpe_SequenceOfCirc::Remove, "Remove one item", py::arg("theIndex"));
	cls_LocOpe_SequenceOfCirc.def("Remove", (void (LocOpe_SequenceOfCirc::*)(const Standard_Integer, const Standard_Integer)) &LocOpe_SequenceOfCirc::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_LocOpe_SequenceOfCirc.def("Append", (void (LocOpe_SequenceOfCirc::*)(const gp_Circ &)) &LocOpe_SequenceOfCirc::Append, "Append one item", py::arg("theItem"));
	cls_LocOpe_SequenceOfCirc.def("Append", (void (LocOpe_SequenceOfCirc::*)(LocOpe_SequenceOfCirc &)) &LocOpe_SequenceOfCirc::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_LocOpe_SequenceOfCirc.def("Prepend", (void (LocOpe_SequenceOfCirc::*)(const gp_Circ &)) &LocOpe_SequenceOfCirc::Prepend, "Prepend one item", py::arg("theItem"));
	cls_LocOpe_SequenceOfCirc.def("Prepend", (void (LocOpe_SequenceOfCirc::*)(LocOpe_SequenceOfCirc &)) &LocOpe_SequenceOfCirc::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_LocOpe_SequenceOfCirc.def("InsertBefore", (void (LocOpe_SequenceOfCirc::*)(const Standard_Integer, const gp_Circ &)) &LocOpe_SequenceOfCirc::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_LocOpe_SequenceOfCirc.def("InsertBefore", (void (LocOpe_SequenceOfCirc::*)(const Standard_Integer, LocOpe_SequenceOfCirc &)) &LocOpe_SequenceOfCirc::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_LocOpe_SequenceOfCirc.def("InsertAfter", (void (LocOpe_SequenceOfCirc::*)(LocOpe_SequenceOfCirc::Iterator &, const gp_Circ &)) &LocOpe_SequenceOfCirc::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_LocOpe_SequenceOfCirc.def("InsertAfter", (void (LocOpe_SequenceOfCirc::*)(const Standard_Integer, LocOpe_SequenceOfCirc &)) &LocOpe_SequenceOfCirc::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_LocOpe_SequenceOfCirc.def("InsertAfter", (void (LocOpe_SequenceOfCirc::*)(const Standard_Integer, const gp_Circ &)) &LocOpe_SequenceOfCirc::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_LocOpe_SequenceOfCirc.def("Split", (void (LocOpe_SequenceOfCirc::*)(const Standard_Integer, LocOpe_SequenceOfCirc &)) &LocOpe_SequenceOfCirc::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_LocOpe_SequenceOfCirc.def("First", (const gp_Circ & (LocOpe_SequenceOfCirc::*)() const ) &LocOpe_SequenceOfCirc::First, "First item access");
	cls_LocOpe_SequenceOfCirc.def("ChangeFirst", (gp_Circ & (LocOpe_SequenceOfCirc::*)()) &LocOpe_SequenceOfCirc::ChangeFirst, "First item access");
	cls_LocOpe_SequenceOfCirc.def("Last", (const gp_Circ & (LocOpe_SequenceOfCirc::*)() const ) &LocOpe_SequenceOfCirc::Last, "Last item access");
	cls_LocOpe_SequenceOfCirc.def("ChangeLast", (gp_Circ & (LocOpe_SequenceOfCirc::*)()) &LocOpe_SequenceOfCirc::ChangeLast, "Last item access");
	cls_LocOpe_SequenceOfCirc.def("Value", (const gp_Circ & (LocOpe_SequenceOfCirc::*)(const Standard_Integer) const ) &LocOpe_SequenceOfCirc::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_LocOpe_SequenceOfCirc.def("__call__", (const gp_Circ & (LocOpe_SequenceOfCirc::*)(const Standard_Integer) const ) &LocOpe_SequenceOfCirc::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_LocOpe_SequenceOfCirc.def("ChangeValue", (gp_Circ & (LocOpe_SequenceOfCirc::*)(const Standard_Integer)) &LocOpe_SequenceOfCirc::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_LocOpe_SequenceOfCirc.def("__call__", (gp_Circ & (LocOpe_SequenceOfCirc::*)(const Standard_Integer)) &LocOpe_SequenceOfCirc::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_LocOpe_SequenceOfCirc.def("SetValue", (void (LocOpe_SequenceOfCirc::*)(const Standard_Integer, const gp_Circ &)) &LocOpe_SequenceOfCirc::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_LocOpe_SequenceOfCirc.def("__iter__", [](const LocOpe_SequenceOfCirc &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<LocOpe_SequenceOfPntFace, std::unique_ptr<LocOpe_SequenceOfPntFace, Deleter<LocOpe_SequenceOfPntFace>>, NCollection_BaseSequence> cls_LocOpe_SequenceOfPntFace(mod, "LocOpe_SequenceOfPntFace", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_LocOpe_SequenceOfPntFace.def(py::init<>());
	cls_LocOpe_SequenceOfPntFace.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_LocOpe_SequenceOfPntFace.def(py::init([] (const LocOpe_SequenceOfPntFace &other) {return new LocOpe_SequenceOfPntFace(other);}), "Copy constructor", py::arg("other"));
	cls_LocOpe_SequenceOfPntFace.def("begin", (LocOpe_SequenceOfPntFace::iterator (LocOpe_SequenceOfPntFace::*)() const ) &LocOpe_SequenceOfPntFace::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_LocOpe_SequenceOfPntFace.def("end", (LocOpe_SequenceOfPntFace::iterator (LocOpe_SequenceOfPntFace::*)() const ) &LocOpe_SequenceOfPntFace::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_LocOpe_SequenceOfPntFace.def("cbegin", (LocOpe_SequenceOfPntFace::const_iterator (LocOpe_SequenceOfPntFace::*)() const ) &LocOpe_SequenceOfPntFace::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_LocOpe_SequenceOfPntFace.def("cend", (LocOpe_SequenceOfPntFace::const_iterator (LocOpe_SequenceOfPntFace::*)() const ) &LocOpe_SequenceOfPntFace::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_LocOpe_SequenceOfPntFace.def("Size", (Standard_Integer (LocOpe_SequenceOfPntFace::*)() const ) &LocOpe_SequenceOfPntFace::Size, "Number of items");
	cls_LocOpe_SequenceOfPntFace.def("Length", (Standard_Integer (LocOpe_SequenceOfPntFace::*)() const ) &LocOpe_SequenceOfPntFace::Length, "Number of items");
	cls_LocOpe_SequenceOfPntFace.def("Lower", (Standard_Integer (LocOpe_SequenceOfPntFace::*)() const ) &LocOpe_SequenceOfPntFace::Lower, "Method for consistency with other collections.");
	cls_LocOpe_SequenceOfPntFace.def("Upper", (Standard_Integer (LocOpe_SequenceOfPntFace::*)() const ) &LocOpe_SequenceOfPntFace::Upper, "Method for consistency with other collections.");
	cls_LocOpe_SequenceOfPntFace.def("IsEmpty", (Standard_Boolean (LocOpe_SequenceOfPntFace::*)() const ) &LocOpe_SequenceOfPntFace::IsEmpty, "Empty query");
	cls_LocOpe_SequenceOfPntFace.def("Reverse", (void (LocOpe_SequenceOfPntFace::*)()) &LocOpe_SequenceOfPntFace::Reverse, "Reverse sequence");
	cls_LocOpe_SequenceOfPntFace.def("Exchange", (void (LocOpe_SequenceOfPntFace::*)(const Standard_Integer, const Standard_Integer)) &LocOpe_SequenceOfPntFace::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_LocOpe_SequenceOfPntFace.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &LocOpe_SequenceOfPntFace::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_LocOpe_SequenceOfPntFace.def("Clear", [](LocOpe_SequenceOfPntFace &self) -> void { return self.Clear(); });
	cls_LocOpe_SequenceOfPntFace.def("Clear", (void (LocOpe_SequenceOfPntFace::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &LocOpe_SequenceOfPntFace::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_LocOpe_SequenceOfPntFace.def("Assign", (LocOpe_SequenceOfPntFace & (LocOpe_SequenceOfPntFace::*)(const LocOpe_SequenceOfPntFace &)) &LocOpe_SequenceOfPntFace::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_LocOpe_SequenceOfPntFace.def("assign", (LocOpe_SequenceOfPntFace & (LocOpe_SequenceOfPntFace::*)(const LocOpe_SequenceOfPntFace &)) &LocOpe_SequenceOfPntFace::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_LocOpe_SequenceOfPntFace.def("Remove", (void (LocOpe_SequenceOfPntFace::*)(LocOpe_SequenceOfPntFace::Iterator &)) &LocOpe_SequenceOfPntFace::Remove, "Remove one item", py::arg("thePosition"));
	cls_LocOpe_SequenceOfPntFace.def("Remove", (void (LocOpe_SequenceOfPntFace::*)(const Standard_Integer)) &LocOpe_SequenceOfPntFace::Remove, "Remove one item", py::arg("theIndex"));
	cls_LocOpe_SequenceOfPntFace.def("Remove", (void (LocOpe_SequenceOfPntFace::*)(const Standard_Integer, const Standard_Integer)) &LocOpe_SequenceOfPntFace::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_LocOpe_SequenceOfPntFace.def("Append", (void (LocOpe_SequenceOfPntFace::*)(const LocOpe_PntFace &)) &LocOpe_SequenceOfPntFace::Append, "Append one item", py::arg("theItem"));
	cls_LocOpe_SequenceOfPntFace.def("Append", (void (LocOpe_SequenceOfPntFace::*)(LocOpe_SequenceOfPntFace &)) &LocOpe_SequenceOfPntFace::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_LocOpe_SequenceOfPntFace.def("Prepend", (void (LocOpe_SequenceOfPntFace::*)(const LocOpe_PntFace &)) &LocOpe_SequenceOfPntFace::Prepend, "Prepend one item", py::arg("theItem"));
	cls_LocOpe_SequenceOfPntFace.def("Prepend", (void (LocOpe_SequenceOfPntFace::*)(LocOpe_SequenceOfPntFace &)) &LocOpe_SequenceOfPntFace::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_LocOpe_SequenceOfPntFace.def("InsertBefore", (void (LocOpe_SequenceOfPntFace::*)(const Standard_Integer, const LocOpe_PntFace &)) &LocOpe_SequenceOfPntFace::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_LocOpe_SequenceOfPntFace.def("InsertBefore", (void (LocOpe_SequenceOfPntFace::*)(const Standard_Integer, LocOpe_SequenceOfPntFace &)) &LocOpe_SequenceOfPntFace::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_LocOpe_SequenceOfPntFace.def("InsertAfter", (void (LocOpe_SequenceOfPntFace::*)(LocOpe_SequenceOfPntFace::Iterator &, const LocOpe_PntFace &)) &LocOpe_SequenceOfPntFace::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_LocOpe_SequenceOfPntFace.def("InsertAfter", (void (LocOpe_SequenceOfPntFace::*)(const Standard_Integer, LocOpe_SequenceOfPntFace &)) &LocOpe_SequenceOfPntFace::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_LocOpe_SequenceOfPntFace.def("InsertAfter", (void (LocOpe_SequenceOfPntFace::*)(const Standard_Integer, const LocOpe_PntFace &)) &LocOpe_SequenceOfPntFace::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_LocOpe_SequenceOfPntFace.def("Split", (void (LocOpe_SequenceOfPntFace::*)(const Standard_Integer, LocOpe_SequenceOfPntFace &)) &LocOpe_SequenceOfPntFace::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_LocOpe_SequenceOfPntFace.def("First", (const LocOpe_PntFace & (LocOpe_SequenceOfPntFace::*)() const ) &LocOpe_SequenceOfPntFace::First, "First item access");
	cls_LocOpe_SequenceOfPntFace.def("ChangeFirst", (LocOpe_PntFace & (LocOpe_SequenceOfPntFace::*)()) &LocOpe_SequenceOfPntFace::ChangeFirst, "First item access");
	cls_LocOpe_SequenceOfPntFace.def("Last", (const LocOpe_PntFace & (LocOpe_SequenceOfPntFace::*)() const ) &LocOpe_SequenceOfPntFace::Last, "Last item access");
	cls_LocOpe_SequenceOfPntFace.def("ChangeLast", (LocOpe_PntFace & (LocOpe_SequenceOfPntFace::*)()) &LocOpe_SequenceOfPntFace::ChangeLast, "Last item access");
	cls_LocOpe_SequenceOfPntFace.def("Value", (const LocOpe_PntFace & (LocOpe_SequenceOfPntFace::*)(const Standard_Integer) const ) &LocOpe_SequenceOfPntFace::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_LocOpe_SequenceOfPntFace.def("__call__", (const LocOpe_PntFace & (LocOpe_SequenceOfPntFace::*)(const Standard_Integer) const ) &LocOpe_SequenceOfPntFace::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_LocOpe_SequenceOfPntFace.def("ChangeValue", (LocOpe_PntFace & (LocOpe_SequenceOfPntFace::*)(const Standard_Integer)) &LocOpe_SequenceOfPntFace::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_LocOpe_SequenceOfPntFace.def("__call__", (LocOpe_PntFace & (LocOpe_SequenceOfPntFace::*)(const Standard_Integer)) &LocOpe_SequenceOfPntFace::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_LocOpe_SequenceOfPntFace.def("SetValue", (void (LocOpe_SequenceOfPntFace::*)(const Standard_Integer, const LocOpe_PntFace &)) &LocOpe_SequenceOfPntFace::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_LocOpe_SequenceOfPntFace.def("__iter__", [](const LocOpe_SequenceOfPntFace &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<LocOpe_DataMapOfShapePnt, std::unique_ptr<LocOpe_DataMapOfShapePnt, Deleter<LocOpe_DataMapOfShapePnt>>, NCollection_BaseMap> cls_LocOpe_DataMapOfShapePnt(mod, "LocOpe_DataMapOfShapePnt", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_LocOpe_DataMapOfShapePnt.def(py::init<>());
	cls_LocOpe_DataMapOfShapePnt.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_LocOpe_DataMapOfShapePnt.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_LocOpe_DataMapOfShapePnt.def(py::init([] (const LocOpe_DataMapOfShapePnt &other) {return new LocOpe_DataMapOfShapePnt(other);}), "Copy constructor", py::arg("other"));
	cls_LocOpe_DataMapOfShapePnt.def("begin", (LocOpe_DataMapOfShapePnt::iterator (LocOpe_DataMapOfShapePnt::*)() const ) &LocOpe_DataMapOfShapePnt::begin, "Returns an iterator pointing to the first element in the map.");
	cls_LocOpe_DataMapOfShapePnt.def("end", (LocOpe_DataMapOfShapePnt::iterator (LocOpe_DataMapOfShapePnt::*)() const ) &LocOpe_DataMapOfShapePnt::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_LocOpe_DataMapOfShapePnt.def("cbegin", (LocOpe_DataMapOfShapePnt::const_iterator (LocOpe_DataMapOfShapePnt::*)() const ) &LocOpe_DataMapOfShapePnt::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_LocOpe_DataMapOfShapePnt.def("cend", (LocOpe_DataMapOfShapePnt::const_iterator (LocOpe_DataMapOfShapePnt::*)() const ) &LocOpe_DataMapOfShapePnt::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_LocOpe_DataMapOfShapePnt.def("Exchange", (void (LocOpe_DataMapOfShapePnt::*)(LocOpe_DataMapOfShapePnt &)) &LocOpe_DataMapOfShapePnt::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_LocOpe_DataMapOfShapePnt.def("Assign", (LocOpe_DataMapOfShapePnt & (LocOpe_DataMapOfShapePnt::*)(const LocOpe_DataMapOfShapePnt &)) &LocOpe_DataMapOfShapePnt::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_LocOpe_DataMapOfShapePnt.def("assign", (LocOpe_DataMapOfShapePnt & (LocOpe_DataMapOfShapePnt::*)(const LocOpe_DataMapOfShapePnt &)) &LocOpe_DataMapOfShapePnt::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_LocOpe_DataMapOfShapePnt.def("ReSize", (void (LocOpe_DataMapOfShapePnt::*)(const Standard_Integer)) &LocOpe_DataMapOfShapePnt::ReSize, "ReSize", py::arg("N"));
	cls_LocOpe_DataMapOfShapePnt.def("Bind", (Standard_Boolean (LocOpe_DataMapOfShapePnt::*)(const TopoDS_Shape &, const gp_Pnt &)) &LocOpe_DataMapOfShapePnt::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_LocOpe_DataMapOfShapePnt.def("Bound", (gp_Pnt * (LocOpe_DataMapOfShapePnt::*)(const TopoDS_Shape &, const gp_Pnt &)) &LocOpe_DataMapOfShapePnt::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_LocOpe_DataMapOfShapePnt.def("IsBound", (Standard_Boolean (LocOpe_DataMapOfShapePnt::*)(const TopoDS_Shape &) const ) &LocOpe_DataMapOfShapePnt::IsBound, "IsBound", py::arg("theKey"));
	cls_LocOpe_DataMapOfShapePnt.def("UnBind", (Standard_Boolean (LocOpe_DataMapOfShapePnt::*)(const TopoDS_Shape &)) &LocOpe_DataMapOfShapePnt::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_LocOpe_DataMapOfShapePnt.def("Seek", (const gp_Pnt * (LocOpe_DataMapOfShapePnt::*)(const TopoDS_Shape &) const ) &LocOpe_DataMapOfShapePnt::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_LocOpe_DataMapOfShapePnt.def("Find", (const gp_Pnt & (LocOpe_DataMapOfShapePnt::*)(const TopoDS_Shape &) const ) &LocOpe_DataMapOfShapePnt::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_LocOpe_DataMapOfShapePnt.def("Find", (Standard_Boolean (LocOpe_DataMapOfShapePnt::*)(const TopoDS_Shape &, gp_Pnt &) const ) &LocOpe_DataMapOfShapePnt::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_LocOpe_DataMapOfShapePnt.def("__call__", (const gp_Pnt & (LocOpe_DataMapOfShapePnt::*)(const TopoDS_Shape &) const ) &LocOpe_DataMapOfShapePnt::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_LocOpe_DataMapOfShapePnt.def("ChangeSeek", (gp_Pnt * (LocOpe_DataMapOfShapePnt::*)(const TopoDS_Shape &)) &LocOpe_DataMapOfShapePnt::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_LocOpe_DataMapOfShapePnt.def("ChangeFind", (gp_Pnt & (LocOpe_DataMapOfShapePnt::*)(const TopoDS_Shape &)) &LocOpe_DataMapOfShapePnt::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_LocOpe_DataMapOfShapePnt.def("__call__", (gp_Pnt & (LocOpe_DataMapOfShapePnt::*)(const TopoDS_Shape &)) &LocOpe_DataMapOfShapePnt::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_LocOpe_DataMapOfShapePnt.def("Clear", [](LocOpe_DataMapOfShapePnt &self) -> void { return self.Clear(); });
	cls_LocOpe_DataMapOfShapePnt.def("Clear", (void (LocOpe_DataMapOfShapePnt::*)(const Standard_Boolean)) &LocOpe_DataMapOfShapePnt::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_LocOpe_DataMapOfShapePnt.def("Clear", (void (LocOpe_DataMapOfShapePnt::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &LocOpe_DataMapOfShapePnt::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_LocOpe_DataMapOfShapePnt.def("Size", (Standard_Integer (LocOpe_DataMapOfShapePnt::*)() const ) &LocOpe_DataMapOfShapePnt::Size, "Size");
	cls_LocOpe_DataMapOfShapePnt.def("__iter__", [](const LocOpe_DataMapOfShapePnt &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocOpe_DataMapOfShapePnt.hxx

}
