#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <NCollection_BaseMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shell.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepFill_Generator.hxx>
#include <Standard_Transient.hxx>
#include <GeomFill_SectionLaw.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Type.hxx>
#include <BRepFill_SectionLaw.hxx>
#include <Law_Function.hxx>
#include <BRepFill_ShapeLaw.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <GeomFill_SequenceOfTrsf.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <BRepFill_NSections.hxx>
#include <gp_Dir.hxx>
#include <BRepFill_TransitionStyle.hxx>
#include <Geom_Surface.hxx>
#include <BRepFill_Draft.hxx>
#include <GeomFill_PipeError.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <GeomFill_LocationLaw.hxx>
#include <BRepFill_LocationLaw.hxx>
#include <BRepFill_Edge3DLaw.hxx>
#include <GeomFill_LocationDraft.hxx>
#include <BRepFill_DraftLaw.hxx>
#include <BRepFill_EdgeOnSurfLaw.hxx>
#include <GeomFill_LocationGuide.hxx>
#include <BRepFill_ACRLaw.hxx>
#include <GeomFill_Trihedron.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pnt.hxx>
#include <BRepFill_Pipe.hxx>
#include <gp_Ax2.hxx>
#include <BRepFill_TypeOfContact.hxx>
#include <BRepFill_PipeShell.hxx>
#include <gp_Ax3.hxx>
#include <GeomAbs_JoinType.hxx>
#include <BRepFill_Evolved.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepFill_DataMapOfShapeHArray2OfShape.hxx>
#include <GeomFill_ApproxStyle.hxx>
#include <TopTools_HArray2OfShape.hxx>
#include <BRepFill_Sweep.hxx>
#include <BRepFill_CompatibleWires.hxx>
#include <BRepMAT2d_BisectingLocus.hxx>
#include <BRepMAT2d_LinkTopoBilo.hxx>
#include <BRepFill_OffsetWire.hxx>
#include <BRepFill_OffsetAncestors.hxx>
#include <BRepFill_MultiLine.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <BRepFill_ApproxSeewing.hxx>
#include <AppParCurves_Constraint.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <BRepFill_ComputeCLine.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepFill_TrimSurfaceTool.hxx>
#include <Bisector_Bisec.hxx>
#include <Geom2d_Geometry.hxx>
#include <BRepFill_TrimEdgeTool.hxx>
#include <gp_Trsf.hxx>
#include <BRepFill_SectionPlacement.hxx>
#include <BRepFill_Section.hxx>
#include <BRepFill_TrimShellCorner.hxx>
#include <GeomPlate_CurveConstraint.hxx>
#include <Adaptor3d_HCurveOnSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <BRepFill_CurveConstraint.hxx>
#include <BRepFill_Filling.hxx>
#include <BRepFill_FaceAndOrder.hxx>
#include <BRepFill_EdgeFaceAndOrder.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <BRepFill.hxx>
#include <AppCont_Function.hxx>
#include <NCollection_Array1.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Vec.hxx>
#include <BRepFill_DataMapOfNodeDataMapOfShapeShape.hxx>
#include <BRepFill_DataMapOfNodeShape.hxx>
#include <BRepFill_DataMapOfOrientedShapeListOfShape.hxx>
#include <BRepFill_DataMapOfShapeSequenceOfPnt.hxx>
#include <BRepFill_DataMapOfShapeSequenceOfReal.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <BRepFill_SequenceOfEdgeFaceAndOrder.hxx>
#include <BRepFill_SequenceOfFaceAndOrder.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <BRepFill_IndexedDataMapOfOrientedShapeListOfShape.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <BRepFill_ListOfOffsetWire.hxx>
#include <BRepFill_SequenceOfSection.hxx>

PYBIND11_MODULE(BRepFill, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.GeomFill");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.Law");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.BRepMAT2d");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.AppParCurves");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.Bisector");
	py::module::import("OCCT.GeomPlate");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.AppCont");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_TransitionStyle.hxx
	py::enum_<BRepFill_TransitionStyle>(mod, "BRepFill_TransitionStyle", "None")
		.value("BRepFill_Modified", BRepFill_TransitionStyle::BRepFill_Modified)
		.value("BRepFill_Right", BRepFill_TransitionStyle::BRepFill_Right)
		.value("BRepFill_Round", BRepFill_TransitionStyle::BRepFill_Round)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_TypeOfContact.hxx
	py::enum_<BRepFill_TypeOfContact>(mod, "BRepFill_TypeOfContact", "A pair of bound shapes with the result.")
		.value("BRepFill_NoContact", BRepFill_TypeOfContact::BRepFill_NoContact)
		.value("BRepFill_Contact", BRepFill_TypeOfContact::BRepFill_Contact)
		.value("BRepFill_ContactOnBorder", BRepFill_TypeOfContact::BRepFill_ContactOnBorder)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_Generator.hxx
	py::class_<BRepFill_Generator, std::unique_ptr<BRepFill_Generator, Deleter<BRepFill_Generator>>> cls_BRepFill_Generator(mod, "BRepFill_Generator", "Compute a topological surface ( a shell) using generating wires. The face of the shell will be ruled surfaces passing by the wires. The wires must have the same number of edges.");
	cls_BRepFill_Generator.def(py::init<>());
	cls_BRepFill_Generator.def("AddWire", (void (BRepFill_Generator::*)(const TopoDS_Wire &)) &BRepFill_Generator::AddWire, "None", py::arg("Wire"));
	cls_BRepFill_Generator.def("Perform", (void (BRepFill_Generator::*)()) &BRepFill_Generator::Perform, "Compute the shell.");
	cls_BRepFill_Generator.def("Shell", (const TopoDS_Shell & (BRepFill_Generator::*)() const ) &BRepFill_Generator::Shell, "None");
	cls_BRepFill_Generator.def("Generated", (const TopTools_DataMapOfShapeListOfShape & (BRepFill_Generator::*)() const ) &BRepFill_Generator::Generated, "Returns all the shapes created");
	cls_BRepFill_Generator.def("GeneratedShapes", (const TopTools_ListOfShape & (BRepFill_Generator::*)(const TopoDS_Shape &) const ) &BRepFill_Generator::GeneratedShapes, "Returns the shapes created from a subshape <SSection> of a section.", py::arg("SSection"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_SectionLaw.hxx
	py::class_<BRepFill_SectionLaw, opencascade::handle<BRepFill_SectionLaw>, Standard_Transient> cls_BRepFill_SectionLaw(mod, "BRepFill_SectionLaw", "Build Section Law, with an Vertex, or an Wire");
	cls_BRepFill_SectionLaw.def("NbLaw", (Standard_Integer (BRepFill_SectionLaw::*)() const ) &BRepFill_SectionLaw::NbLaw, "None");
	cls_BRepFill_SectionLaw.def("Law", (const opencascade::handle<GeomFill_SectionLaw> & (BRepFill_SectionLaw::*)(const Standard_Integer) const ) &BRepFill_SectionLaw::Law, "None", py::arg("Index"));
	cls_BRepFill_SectionLaw.def("IndexOfEdge", (Standard_Integer (BRepFill_SectionLaw::*)(const TopoDS_Shape &) const ) &BRepFill_SectionLaw::IndexOfEdge, "None", py::arg("anEdge"));
	cls_BRepFill_SectionLaw.def("IsConstant", (Standard_Boolean (BRepFill_SectionLaw::*)() const ) &BRepFill_SectionLaw::IsConstant, "None");
	cls_BRepFill_SectionLaw.def("IsUClosed", (Standard_Boolean (BRepFill_SectionLaw::*)() const ) &BRepFill_SectionLaw::IsUClosed, "None");
	cls_BRepFill_SectionLaw.def("IsVClosed", (Standard_Boolean (BRepFill_SectionLaw::*)() const ) &BRepFill_SectionLaw::IsVClosed, "None");
	cls_BRepFill_SectionLaw.def("IsDone", (Standard_Boolean (BRepFill_SectionLaw::*)() const ) &BRepFill_SectionLaw::IsDone, "None");
	cls_BRepFill_SectionLaw.def("IsVertex", (Standard_Boolean (BRepFill_SectionLaw::*)() const ) &BRepFill_SectionLaw::IsVertex, "Say if the input shape is a vertex.");
	cls_BRepFill_SectionLaw.def("ConcatenedLaw", (opencascade::handle<GeomFill_SectionLaw> (BRepFill_SectionLaw::*)() const ) &BRepFill_SectionLaw::ConcatenedLaw, "None");
	cls_BRepFill_SectionLaw.def("Continuity", (GeomAbs_Shape (BRepFill_SectionLaw::*)(const Standard_Integer, const Standard_Real) const ) &BRepFill_SectionLaw::Continuity, "None", py::arg("Index"), py::arg("TolAngular"));
	cls_BRepFill_SectionLaw.def("VertexTol", (Standard_Real (BRepFill_SectionLaw::*)(const Standard_Integer, const Standard_Real) const ) &BRepFill_SectionLaw::VertexTol, "None", py::arg("Index"), py::arg("Param"));
	cls_BRepFill_SectionLaw.def("Vertex", (TopoDS_Vertex (BRepFill_SectionLaw::*)(const Standard_Integer, const Standard_Real) const ) &BRepFill_SectionLaw::Vertex, "None", py::arg("Index"), py::arg("Param"));
	cls_BRepFill_SectionLaw.def("D0", (void (BRepFill_SectionLaw::*)(const Standard_Real, TopoDS_Shape &)) &BRepFill_SectionLaw::D0, "None", py::arg("U"), py::arg("S"));
	cls_BRepFill_SectionLaw.def("Init", (void (BRepFill_SectionLaw::*)(const TopoDS_Wire &)) &BRepFill_SectionLaw::Init, "None", py::arg("W"));
	cls_BRepFill_SectionLaw.def("CurrentEdge", (TopoDS_Edge (BRepFill_SectionLaw::*)()) &BRepFill_SectionLaw::CurrentEdge, "None");
	cls_BRepFill_SectionLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_SectionLaw::get_type_name, "None");
	cls_BRepFill_SectionLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_SectionLaw::get_type_descriptor, "None");
	cls_BRepFill_SectionLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_SectionLaw::*)() const ) &BRepFill_SectionLaw::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_ShapeLaw.hxx
	py::class_<BRepFill_ShapeLaw, opencascade::handle<BRepFill_ShapeLaw>, BRepFill_SectionLaw> cls_BRepFill_ShapeLaw(mod, "BRepFill_ShapeLaw", "Build Section Law, with an Vertex, or an Wire");
	cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Vertex &>(), py::arg("V"));
	cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V"), py::arg("Build"));
	cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
	cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Wire &, const Standard_Boolean>(), py::arg("W"), py::arg("Build"));
	cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Wire &, const opencascade::handle<Law_Function> &>(), py::arg("W"), py::arg("L"));
	cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Wire &, const opencascade::handle<Law_Function> &, const Standard_Boolean>(), py::arg("W"), py::arg("L"), py::arg("Build"));
	cls_BRepFill_ShapeLaw.def("IsVertex", (Standard_Boolean (BRepFill_ShapeLaw::*)() const ) &BRepFill_ShapeLaw::IsVertex, "Say if the input shape is a vertex.");
	cls_BRepFill_ShapeLaw.def("IsConstant", (Standard_Boolean (BRepFill_ShapeLaw::*)() const ) &BRepFill_ShapeLaw::IsConstant, "Say if the Law is Constant.");
	cls_BRepFill_ShapeLaw.def("ConcatenedLaw", (opencascade::handle<GeomFill_SectionLaw> (BRepFill_ShapeLaw::*)() const ) &BRepFill_ShapeLaw::ConcatenedLaw, "Give the law build on a concaneted section");
	cls_BRepFill_ShapeLaw.def("Continuity", (GeomAbs_Shape (BRepFill_ShapeLaw::*)(const Standard_Integer, const Standard_Real) const ) &BRepFill_ShapeLaw::Continuity, "None", py::arg("Index"), py::arg("TolAngular"));
	cls_BRepFill_ShapeLaw.def("VertexTol", (Standard_Real (BRepFill_ShapeLaw::*)(const Standard_Integer, const Standard_Real) const ) &BRepFill_ShapeLaw::VertexTol, "None", py::arg("Index"), py::arg("Param"));
	cls_BRepFill_ShapeLaw.def("Vertex", (TopoDS_Vertex (BRepFill_ShapeLaw::*)(const Standard_Integer, const Standard_Real) const ) &BRepFill_ShapeLaw::Vertex, "None", py::arg("Index"), py::arg("Param"));
	cls_BRepFill_ShapeLaw.def("D0", (void (BRepFill_ShapeLaw::*)(const Standard_Real, TopoDS_Shape &)) &BRepFill_ShapeLaw::D0, "None", py::arg("Param"), py::arg("S"));
	cls_BRepFill_ShapeLaw.def("Edge", (const TopoDS_Edge & (BRepFill_ShapeLaw::*)(const Standard_Integer) const ) &BRepFill_ShapeLaw::Edge, "None", py::arg("Index"));
	cls_BRepFill_ShapeLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_ShapeLaw::get_type_name, "None");
	cls_BRepFill_ShapeLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_ShapeLaw::get_type_descriptor, "None");
	cls_BRepFill_ShapeLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_ShapeLaw::*)() const ) &BRepFill_ShapeLaw::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_NSections.hxx
	py::class_<BRepFill_NSections, opencascade::handle<BRepFill_NSections>, BRepFill_SectionLaw> cls_BRepFill_NSections(mod, "BRepFill_NSections", "Build Section Law, with N Sections");
	cls_BRepFill_NSections.def(py::init<const TopTools_SequenceOfShape &>(), py::arg("S"));
	cls_BRepFill_NSections.def(py::init<const TopTools_SequenceOfShape &, const Standard_Boolean>(), py::arg("S"), py::arg("Build"));
	cls_BRepFill_NSections.def(py::init<const TopTools_SequenceOfShape &, const GeomFill_SequenceOfTrsf &, const TColStd_SequenceOfReal &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("Trsfs"), py::arg("P"), py::arg("VF"), py::arg("VL"));
	cls_BRepFill_NSections.def(py::init<const TopTools_SequenceOfShape &, const GeomFill_SequenceOfTrsf &, const TColStd_SequenceOfReal &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("Trsfs"), py::arg("P"), py::arg("VF"), py::arg("VL"), py::arg("Build"));
	cls_BRepFill_NSections.def("IsVertex", (Standard_Boolean (BRepFill_NSections::*)() const ) &BRepFill_NSections::IsVertex, "Say if the input shape is a vertex.");
	cls_BRepFill_NSections.def("IsConstant", (Standard_Boolean (BRepFill_NSections::*)() const ) &BRepFill_NSections::IsConstant, "Say if the Law is Constant.");
	cls_BRepFill_NSections.def("ConcatenedLaw", (opencascade::handle<GeomFill_SectionLaw> (BRepFill_NSections::*)() const ) &BRepFill_NSections::ConcatenedLaw, "Give the law build on a concatened section");
	cls_BRepFill_NSections.def("Continuity", (GeomAbs_Shape (BRepFill_NSections::*)(const Standard_Integer, const Standard_Real) const ) &BRepFill_NSections::Continuity, "None", py::arg("Index"), py::arg("TolAngular"));
	cls_BRepFill_NSections.def("VertexTol", (Standard_Real (BRepFill_NSections::*)(const Standard_Integer, const Standard_Real) const ) &BRepFill_NSections::VertexTol, "None", py::arg("Index"), py::arg("Param"));
	cls_BRepFill_NSections.def("Vertex", (TopoDS_Vertex (BRepFill_NSections::*)(const Standard_Integer, const Standard_Real) const ) &BRepFill_NSections::Vertex, "None", py::arg("Index"), py::arg("Param"));
	cls_BRepFill_NSections.def("D0", (void (BRepFill_NSections::*)(const Standard_Real, TopoDS_Shape &)) &BRepFill_NSections::D0, "None", py::arg("Param"), py::arg("S"));
	cls_BRepFill_NSections.def_static("get_type_name_", (const char * (*)()) &BRepFill_NSections::get_type_name, "None");
	cls_BRepFill_NSections.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_NSections::get_type_descriptor, "None");
	cls_BRepFill_NSections.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_NSections::*)() const ) &BRepFill_NSections::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_Draft.hxx
	py::class_<BRepFill_Draft, std::unique_ptr<BRepFill_Draft, Deleter<BRepFill_Draft>>> cls_BRepFill_Draft(mod, "BRepFill_Draft", "None");
	cls_BRepFill_Draft.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Real>(), py::arg("Shape"), py::arg("Dir"), py::arg("Angle"));
	cls_BRepFill_Draft.def("SetOptions", [](BRepFill_Draft &self) -> void { return self.SetOptions(); });
	cls_BRepFill_Draft.def("SetOptions", [](BRepFill_Draft &self, const BRepFill_TransitionStyle a0) -> void { return self.SetOptions(a0); }, py::arg("Style"));
	cls_BRepFill_Draft.def("SetOptions", [](BRepFill_Draft &self, const BRepFill_TransitionStyle a0, const Standard_Real a1) -> void { return self.SetOptions(a0, a1); }, py::arg("Style"), py::arg("AngleMin"));
	cls_BRepFill_Draft.def("SetOptions", (void (BRepFill_Draft::*)(const BRepFill_TransitionStyle, const Standard_Real, const Standard_Real)) &BRepFill_Draft::SetOptions, "None", py::arg("Style"), py::arg("AngleMin"), py::arg("AngleMax"));
	cls_BRepFill_Draft.def("SetDraft", [](BRepFill_Draft &self) -> void { return self.SetDraft(); });
	cls_BRepFill_Draft.def("SetDraft", (void (BRepFill_Draft::*)(const Standard_Boolean)) &BRepFill_Draft::SetDraft, "None", py::arg("IsInternal"));
	cls_BRepFill_Draft.def("Perform", (void (BRepFill_Draft::*)(const Standard_Real)) &BRepFill_Draft::Perform, "None", py::arg("LengthMax"));
	cls_BRepFill_Draft.def("Perform", [](BRepFill_Draft &self, const opencascade::handle<Geom_Surface> & a0) -> void { return self.Perform(a0); }, py::arg("Surface"));
	cls_BRepFill_Draft.def("Perform", (void (BRepFill_Draft::*)(const opencascade::handle<Geom_Surface> &, const Standard_Boolean)) &BRepFill_Draft::Perform, "None", py::arg("Surface"), py::arg("KeepInsideSurface"));
	cls_BRepFill_Draft.def("Perform", [](BRepFill_Draft &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); }, py::arg("StopShape"));
	cls_BRepFill_Draft.def("Perform", (void (BRepFill_Draft::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepFill_Draft::Perform, "None", py::arg("StopShape"), py::arg("KeepOutSide"));
	cls_BRepFill_Draft.def("IsDone", (Standard_Boolean (BRepFill_Draft::*)() const ) &BRepFill_Draft::IsDone, "None");
	cls_BRepFill_Draft.def("Shell", (TopoDS_Shell (BRepFill_Draft::*)() const ) &BRepFill_Draft::Shell, "Returns the draft surface To have the complete shape you have to use the Shape() methode.");
	cls_BRepFill_Draft.def("Generated", (const TopTools_ListOfShape & (BRepFill_Draft::*)(const TopoDS_Shape &)) &BRepFill_Draft::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
	cls_BRepFill_Draft.def("Shape", (TopoDS_Shape (BRepFill_Draft::*)() const ) &BRepFill_Draft::Shape, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_LocationLaw.hxx
	py::class_<BRepFill_LocationLaw, opencascade::handle<BRepFill_LocationLaw>, Standard_Transient> cls_BRepFill_LocationLaw(mod, "BRepFill_LocationLaw", "Location Law on a Wire.");
	cls_BRepFill_LocationLaw.def("GetStatus", (GeomFill_PipeError (BRepFill_LocationLaw::*)() const ) &BRepFill_LocationLaw::GetStatus, "Return a error status, if the status is not PipeOk then it exist a parameter tlike the law is not valuable for t.");
	cls_BRepFill_LocationLaw.def("TransformInG0Law", (void (BRepFill_LocationLaw::*)()) &BRepFill_LocationLaw::TransformInG0Law, "Apply a linear transformation on each law, to have continuity of the global law beetween the edges.");
	cls_BRepFill_LocationLaw.def("TransformInCompatibleLaw", (void (BRepFill_LocationLaw::*)(const Standard_Real)) &BRepFill_LocationLaw::TransformInCompatibleLaw, "Apply a linear transformation on each law, to reduce the dicontinuities of law at one rotation.", py::arg("AngularTolerance"));
	cls_BRepFill_LocationLaw.def("DeleteTransform", (void (BRepFill_LocationLaw::*)()) &BRepFill_LocationLaw::DeleteTransform, "None");
	cls_BRepFill_LocationLaw.def("NbHoles", [](BRepFill_LocationLaw &self) -> Standard_Integer { return self.NbHoles(); });
	cls_BRepFill_LocationLaw.def("NbHoles", (Standard_Integer (BRepFill_LocationLaw::*)(const Standard_Real)) &BRepFill_LocationLaw::NbHoles, "None", py::arg("Tol"));
	cls_BRepFill_LocationLaw.def("Holes", (void (BRepFill_LocationLaw::*)(TColStd_Array1OfInteger &) const ) &BRepFill_LocationLaw::Holes, "None", py::arg("Interval"));
	cls_BRepFill_LocationLaw.def("NbLaw", (Standard_Integer (BRepFill_LocationLaw::*)() const ) &BRepFill_LocationLaw::NbLaw, "Return the number of elementary Law");
	cls_BRepFill_LocationLaw.def("Law", (const opencascade::handle<GeomFill_LocationLaw> & (BRepFill_LocationLaw::*)(const Standard_Integer) const ) &BRepFill_LocationLaw::Law, "Return the elementary Law of rank <Index> <Index> have to be in [1, NbLaw()]", py::arg("Index"));
	cls_BRepFill_LocationLaw.def("Wire", (const TopoDS_Wire & (BRepFill_LocationLaw::*)() const ) &BRepFill_LocationLaw::Wire, "return the path");
	cls_BRepFill_LocationLaw.def("Edge", (const TopoDS_Edge & (BRepFill_LocationLaw::*)(const Standard_Integer) const ) &BRepFill_LocationLaw::Edge, "Return the Edge of rank <Index> in the path <Index> have to be in [1, NbLaw()]", py::arg("Index"));
	cls_BRepFill_LocationLaw.def("Vertex", (TopoDS_Vertex (BRepFill_LocationLaw::*)(const Standard_Integer) const ) &BRepFill_LocationLaw::Vertex, "Return the vertex of rank <Index> in the path <Index> have to be in [0, NbLaw()]", py::arg("Index"));
	cls_BRepFill_LocationLaw.def("PerformVertex", [](BRepFill_LocationLaw &self, const Standard_Integer a0, const TopoDS_Vertex & a1, const Standard_Real a2, TopoDS_Vertex & a3) -> void { return self.PerformVertex(a0, a1, a2, a3); }, py::arg("Index"), py::arg("InputVertex"), py::arg("TolMin"), py::arg("OutputVertex"));
	cls_BRepFill_LocationLaw.def("PerformVertex", (void (BRepFill_LocationLaw::*)(const Standard_Integer, const TopoDS_Vertex &, const Standard_Real, TopoDS_Vertex &, const Standard_Integer) const ) &BRepFill_LocationLaw::PerformVertex, "Compute <OutputVertex> like a transformation of <InputVertex> the transformation is given by evaluation of the location law in the vertex of rank <Index>. <Location> is used to manage discontinuities : - -1 : The law before the vertex is used. - 1 : The law after the vertex is used. - 0 : Average of the both laws is used.", py::arg("Index"), py::arg("InputVertex"), py::arg("TolMin"), py::arg("OutputVertex"), py::arg("Location"));
	cls_BRepFill_LocationLaw.def("CurvilinearBounds", (void (BRepFill_LocationLaw::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &BRepFill_LocationLaw::CurvilinearBounds, "Return the Curvilinear Bounds of the <Index> Law", py::arg("Index"), py::arg("First"), py::arg("Last"));
	cls_BRepFill_LocationLaw.def("IsClosed", (Standard_Boolean (BRepFill_LocationLaw::*)() const ) &BRepFill_LocationLaw::IsClosed, "None");
	cls_BRepFill_LocationLaw.def("IsG1", [](BRepFill_LocationLaw &self, const Standard_Integer a0) -> Standard_Integer { return self.IsG1(a0); }, py::arg("Index"));
	cls_BRepFill_LocationLaw.def("IsG1", [](BRepFill_LocationLaw &self, const Standard_Integer a0, const Standard_Real a1) -> Standard_Integer { return self.IsG1(a0, a1); }, py::arg("Index"), py::arg("SpatialTolerance"));
	cls_BRepFill_LocationLaw.def("IsG1", (Standard_Integer (BRepFill_LocationLaw::*)(const Standard_Integer, const Standard_Real, const Standard_Real) const ) &BRepFill_LocationLaw::IsG1, "Compute the Law's continuity beetween 2 edges of the path The result can be : -1 : Case Not connex 0 : It is connex (G0) 1 : It is tangent (G1)", py::arg("Index"), py::arg("SpatialTolerance"), py::arg("AngularTolerance"));
	cls_BRepFill_LocationLaw.def("D0", (void (BRepFill_LocationLaw::*)(const Standard_Real, TopoDS_Shape &)) &BRepFill_LocationLaw::D0, "Apply the Law to a shape, for a given Curnilinear abscissa", py::arg("Abscissa"), py::arg("Section"));
	cls_BRepFill_LocationLaw.def("Parameter", (void (BRepFill_LocationLaw::*)(const Standard_Real, Standard_Integer &, Standard_Real &)) &BRepFill_LocationLaw::Parameter, "Find the index Law and the parmaeter, for a given Curnilinear abscissa", py::arg("Abscissa"), py::arg("Index"), py::arg("Param"));
	cls_BRepFill_LocationLaw.def("Abscissa", (Standard_Real (BRepFill_LocationLaw::*)(const Standard_Integer, const Standard_Real)) &BRepFill_LocationLaw::Abscissa, "Return the curvilinear abscissa corresponding to a point of the path, defined by <Index> of Edge and a parameter on the edge.", py::arg("Index"), py::arg("Param"));
	cls_BRepFill_LocationLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_LocationLaw::get_type_name, "None");
	cls_BRepFill_LocationLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_LocationLaw::get_type_descriptor, "None");
	cls_BRepFill_LocationLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_LocationLaw::*)() const ) &BRepFill_LocationLaw::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_Edge3DLaw.hxx
	py::class_<BRepFill_Edge3DLaw, opencascade::handle<BRepFill_Edge3DLaw>, BRepFill_LocationLaw> cls_BRepFill_Edge3DLaw(mod, "BRepFill_Edge3DLaw", "Build Location Law, with a Wire.");
	cls_BRepFill_Edge3DLaw.def(py::init<const TopoDS_Wire &, const opencascade::handle<GeomFill_LocationLaw> &>(), py::arg("Path"), py::arg("Law"));
	cls_BRepFill_Edge3DLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_Edge3DLaw::get_type_name, "None");
	cls_BRepFill_Edge3DLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_Edge3DLaw::get_type_descriptor, "None");
	cls_BRepFill_Edge3DLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_Edge3DLaw::*)() const ) &BRepFill_Edge3DLaw::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_DraftLaw.hxx
	py::class_<BRepFill_DraftLaw, opencascade::handle<BRepFill_DraftLaw>, BRepFill_Edge3DLaw> cls_BRepFill_DraftLaw(mod, "BRepFill_DraftLaw", "Build Location Law, with a Wire.");
	cls_BRepFill_DraftLaw.def(py::init<const TopoDS_Wire &, const opencascade::handle<GeomFill_LocationDraft> &>(), py::arg("Path"), py::arg("Law"));
	cls_BRepFill_DraftLaw.def("CleanLaw", (void (BRepFill_DraftLaw::*)(const Standard_Real)) &BRepFill_DraftLaw::CleanLaw, "To clean the little discontinuities.", py::arg("TolAngular"));
	cls_BRepFill_DraftLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_DraftLaw::get_type_name, "None");
	cls_BRepFill_DraftLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_DraftLaw::get_type_descriptor, "None");
	cls_BRepFill_DraftLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_DraftLaw::*)() const ) &BRepFill_DraftLaw::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_EdgeOnSurfLaw.hxx
	py::class_<BRepFill_EdgeOnSurfLaw, opencascade::handle<BRepFill_EdgeOnSurfLaw>, BRepFill_LocationLaw> cls_BRepFill_EdgeOnSurfLaw(mod, "BRepFill_EdgeOnSurfLaw", "Build Location Law, with a Wire and a Surface.");
	cls_BRepFill_EdgeOnSurfLaw.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &>(), py::arg("Path"), py::arg("Surf"));
	cls_BRepFill_EdgeOnSurfLaw.def("HasResult", (Standard_Boolean (BRepFill_EdgeOnSurfLaw::*)() const ) &BRepFill_EdgeOnSurfLaw::HasResult, "returns <False> if one Edge of <Path> do not have representation on <Surf>. In this case it is impossible to use this object.");
	cls_BRepFill_EdgeOnSurfLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_EdgeOnSurfLaw::get_type_name, "None");
	cls_BRepFill_EdgeOnSurfLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_EdgeOnSurfLaw::get_type_descriptor, "None");
	cls_BRepFill_EdgeOnSurfLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_EdgeOnSurfLaw::*)() const ) &BRepFill_EdgeOnSurfLaw::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_ACRLaw.hxx
	py::class_<BRepFill_ACRLaw, opencascade::handle<BRepFill_ACRLaw>, BRepFill_LocationLaw> cls_BRepFill_ACRLaw(mod, "BRepFill_ACRLaw", "Build Location Law, with a Wire. In the case of guided contour and trihedron by reduced curvilinear abscissa");
	cls_BRepFill_ACRLaw.def(py::init<const TopoDS_Wire &, const opencascade::handle<GeomFill_LocationGuide> &>(), py::arg("Path"), py::arg("Law"));
	cls_BRepFill_ACRLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_ACRLaw::get_type_name, "None");
	cls_BRepFill_ACRLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_ACRLaw::get_type_descriptor, "None");
	cls_BRepFill_ACRLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_ACRLaw::*)() const ) &BRepFill_ACRLaw::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_Pipe.hxx
	py::class_<BRepFill_Pipe, std::unique_ptr<BRepFill_Pipe, Deleter<BRepFill_Pipe>>> cls_BRepFill_Pipe(mod, "BRepFill_Pipe", "Create a shape by sweeping a shape (the profile) along a wire (the spine).");
	cls_BRepFill_Pipe.def(py::init<>());
	cls_BRepFill_Pipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &>(), py::arg("Spine"), py::arg("Profile"));
	cls_BRepFill_Pipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &, const GeomFill_Trihedron>(), py::arg("Spine"), py::arg("Profile"), py::arg("aMode"));
	cls_BRepFill_Pipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &, const GeomFill_Trihedron, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profile"), py::arg("aMode"), py::arg("ForceApproxC1"));
	cls_BRepFill_Pipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &, const GeomFill_Trihedron, const Standard_Boolean, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profile"), py::arg("aMode"), py::arg("ForceApproxC1"), py::arg("GeneratePartCase"));
	cls_BRepFill_Pipe.def("Perform", [](BRepFill_Pipe &self, const TopoDS_Wire & a0, const TopoDS_Shape & a1) -> void { return self.Perform(a0, a1); }, py::arg("Spine"), py::arg("Profile"));
	cls_BRepFill_Pipe.def("Perform", (void (BRepFill_Pipe::*)(const TopoDS_Wire &, const TopoDS_Shape &, const Standard_Boolean)) &BRepFill_Pipe::Perform, "None", py::arg("Spine"), py::arg("Profile"), py::arg("GeneratePartCase"));
	cls_BRepFill_Pipe.def("Spine", (const TopoDS_Shape & (BRepFill_Pipe::*)() const ) &BRepFill_Pipe::Spine, "None");
	cls_BRepFill_Pipe.def("Profile", (const TopoDS_Shape & (BRepFill_Pipe::*)() const ) &BRepFill_Pipe::Profile, "None");
	cls_BRepFill_Pipe.def("Shape", (const TopoDS_Shape & (BRepFill_Pipe::*)() const ) &BRepFill_Pipe::Shape, "None");
	cls_BRepFill_Pipe.def("ErrorOnSurface", (Standard_Real (BRepFill_Pipe::*)() const ) &BRepFill_Pipe::ErrorOnSurface, "None");
	cls_BRepFill_Pipe.def("FirstShape", (const TopoDS_Shape & (BRepFill_Pipe::*)() const ) &BRepFill_Pipe::FirstShape, "None");
	cls_BRepFill_Pipe.def("LastShape", (const TopoDS_Shape & (BRepFill_Pipe::*)() const ) &BRepFill_Pipe::LastShape, "None");
	cls_BRepFill_Pipe.def("Generated", (void (BRepFill_Pipe::*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepFill_Pipe::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"), py::arg("L"));
	cls_BRepFill_Pipe.def("Face", (TopoDS_Face (BRepFill_Pipe::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BRepFill_Pipe::Face, "Returns the face created from an edge of the spine and an edge of the profile. if the edges are not in the spine or the profile", py::arg("ESpine"), py::arg("EProfile"));
	cls_BRepFill_Pipe.def("Edge", (TopoDS_Edge (BRepFill_Pipe::*)(const TopoDS_Edge &, const TopoDS_Vertex &)) &BRepFill_Pipe::Edge, "Returns the edge created from an edge of the spine and a vertex of the profile. if the edge or the vertex are not in the spine or the profile.", py::arg("ESpine"), py::arg("VProfile"));
	cls_BRepFill_Pipe.def("Section", (TopoDS_Shape (BRepFill_Pipe::*)(const TopoDS_Vertex &) const ) &BRepFill_Pipe::Section, "Returns the shape created from the profile at the position of the vertex VSpine. if the vertex is not in the Spine", py::arg("VSpine"));
	cls_BRepFill_Pipe.def("PipeLine", (TopoDS_Wire (BRepFill_Pipe::*)(const gp_Pnt &)) &BRepFill_Pipe::PipeLine, "Create a Wire by sweeping the Point along the <spine> if the <Spine> is undefined", py::arg("Point"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_PipeShell.hxx
	py::class_<BRepFill_PipeShell, opencascade::handle<BRepFill_PipeShell>, Standard_Transient> cls_BRepFill_PipeShell(mod, "BRepFill_PipeShell", "Computes a topological shell using some wires (spines and profiles) and diplacement option Perform general sweeping construction");
	cls_BRepFill_PipeShell.def(py::init<const TopoDS_Wire &>(), py::arg("Spine"));
	cls_BRepFill_PipeShell.def("Set", [](BRepFill_PipeShell &self) -> void { return self.Set(); });
	cls_BRepFill_PipeShell.def("Set", (void (BRepFill_PipeShell::*)(const Standard_Boolean)) &BRepFill_PipeShell::Set, "Set an Frenet or an CorrectedFrenet trihedron to perform the sweeping", py::arg("Frenet"));
	cls_BRepFill_PipeShell.def("SetDiscrete", (void (BRepFill_PipeShell::*)()) &BRepFill_PipeShell::SetDiscrete, "Set a Discrete trihedron to perform the sweeping");
	cls_BRepFill_PipeShell.def("Set", (void (BRepFill_PipeShell::*)(const gp_Ax2 &)) &BRepFill_PipeShell::Set, "Set an fixed trihedron to perform the sweeping all sections will be parallel.", py::arg("Axe"));
	cls_BRepFill_PipeShell.def("Set", (void (BRepFill_PipeShell::*)(const gp_Dir &)) &BRepFill_PipeShell::Set, "Set an fixed BiNormal direction to perform the sweeping", py::arg("BiNormal"));
	cls_BRepFill_PipeShell.def("Set", (Standard_Boolean (BRepFill_PipeShell::*)(const TopoDS_Shape &)) &BRepFill_PipeShell::Set, "Set support to the spine to define the BiNormal at the spine, like the normal the surfaces. Warning: To be effective, Each edge of the <spine> must have an representaion on one face of<SpineSupport>", py::arg("SpineSupport"));
	cls_BRepFill_PipeShell.def("Set", [](BRepFill_PipeShell &self, const TopoDS_Wire & a0) -> void { return self.Set(a0); }, py::arg("AuxiliarySpine"));
	cls_BRepFill_PipeShell.def("Set", [](BRepFill_PipeShell &self, const TopoDS_Wire & a0, const Standard_Boolean a1) -> void { return self.Set(a0, a1); }, py::arg("AuxiliarySpine"), py::arg("CurvilinearEquivalence"));
	cls_BRepFill_PipeShell.def("Set", (void (BRepFill_PipeShell::*)(const TopoDS_Wire &, const Standard_Boolean, const BRepFill_TypeOfContact)) &BRepFill_PipeShell::Set, "Set an auxiliary spine to define the Normal For each Point of the Spine P, an Point Q is evalued on <AuxiliarySpine> If <CurvilinearEquivalence> Q split <AuxiliarySpine> with the same length ratio than P split <Spline>. Else the plan define by P and the tangent to the <Spine> intersect <AuxiliarySpine> in Q. If <KeepContact> equals BRepFill_NoContact: The Normal is defined by the vector PQ. If <KeepContact> equals BRepFill_Contact: The Normal is defined to achieve that the sweeped section is in contact to the auxiliarySpine. The width of section is constant all along the path. In other words, the auxiliary spine lies on the swept surface, but not necessarily is a boundary of this surface. However, the auxiliary spine has to be close enough to the main spine to provide intersection with any section all along the path. If <KeepContact> equals BRepFill_ContactOnBorder: The auxiliary spine becomes a boundary of the swept surface and the width of section varies along the path.", py::arg("AuxiliarySpine"), py::arg("CurvilinearEquivalence"), py::arg("KeepContact"));
	cls_BRepFill_PipeShell.def("SetMaxDegree", (void (BRepFill_PipeShell::*)(const Standard_Integer)) &BRepFill_PipeShell::SetMaxDegree, "Define the maximum V degree of resulting surface", py::arg("NewMaxDegree"));
	cls_BRepFill_PipeShell.def("SetMaxSegments", (void (BRepFill_PipeShell::*)(const Standard_Integer)) &BRepFill_PipeShell::SetMaxSegments, "Define the maximum number of spans in V-direction on resulting surface", py::arg("NewMaxSegments"));
	cls_BRepFill_PipeShell.def("SetForceApproxC1", (void (BRepFill_PipeShell::*)(const Standard_Boolean)) &BRepFill_PipeShell::SetForceApproxC1, "Set the flag that indicates attempt to approximate a C1-continuous surface if a swept surface proved to be C0. Give section to sweep. Possibilities are : - Give one or sevral profile - Give one profile and an homotetic law. - Automatic compute of correspondance beetween profile, and section on the sweeped shape - correspondance beetween profile, and section on the sweeped shape defined by a vertex of the spine", py::arg("ForceApproxC1"));
	cls_BRepFill_PipeShell.def("Add", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0) -> void { return self.Add(a0); }, py::arg("Profile"));
	cls_BRepFill_PipeShell.def("Add", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.Add(a0, a1); }, py::arg("Profile"), py::arg("WithContact"));
	cls_BRepFill_PipeShell.def("Add", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &BRepFill_PipeShell::Add, "Set an section. The corespondance with the spine, will be automaticaly performed.", py::arg("Profile"), py::arg("WithContact"), py::arg("WithCorrection"));
	cls_BRepFill_PipeShell.def("Add", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const TopoDS_Vertex & a1) -> void { return self.Add(a0, a1); }, py::arg("Profile"), py::arg("Location"));
	cls_BRepFill_PipeShell.def("Add", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const TopoDS_Vertex & a1, const Standard_Boolean a2) -> void { return self.Add(a0, a1, a2); }, py::arg("Profile"), py::arg("Location"), py::arg("WithContact"));
	cls_BRepFill_PipeShell.def("Add", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &, const TopoDS_Vertex &, const Standard_Boolean, const Standard_Boolean)) &BRepFill_PipeShell::Add, "Set an section. The corespondance with the spine, is given by <Location>", py::arg("Profile"), py::arg("Location"), py::arg("WithContact"), py::arg("WithCorrection"));
	cls_BRepFill_PipeShell.def("SetLaw", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1) -> void { return self.SetLaw(a0, a1); }, py::arg("Profile"), py::arg("L"));
	cls_BRepFill_PipeShell.def("SetLaw", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const Standard_Boolean a2) -> void { return self.SetLaw(a0, a1, a2); }, py::arg("Profile"), py::arg("L"), py::arg("WithContact"));
	cls_BRepFill_PipeShell.def("SetLaw", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &, const opencascade::handle<Law_Function> &, const Standard_Boolean, const Standard_Boolean)) &BRepFill_PipeShell::SetLaw, "Set an section and an homotetic law. The homotetie's centers is given by point on the <Spine>.", py::arg("Profile"), py::arg("L"), py::arg("WithContact"), py::arg("WithCorrection"));
	cls_BRepFill_PipeShell.def("SetLaw", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const TopoDS_Vertex & a2) -> void { return self.SetLaw(a0, a1, a2); }, py::arg("Profile"), py::arg("L"), py::arg("Location"));
	cls_BRepFill_PipeShell.def("SetLaw", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const TopoDS_Vertex & a2, const Standard_Boolean a3) -> void { return self.SetLaw(a0, a1, a2, a3); }, py::arg("Profile"), py::arg("L"), py::arg("Location"), py::arg("WithContact"));
	cls_BRepFill_PipeShell.def("SetLaw", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &, const opencascade::handle<Law_Function> &, const TopoDS_Vertex &, const Standard_Boolean, const Standard_Boolean)) &BRepFill_PipeShell::SetLaw, "Set an section and an homotetic law. The homotetie center is given by point on the <Spine>", py::arg("Profile"), py::arg("L"), py::arg("Location"), py::arg("WithContact"), py::arg("WithCorrection"));
	cls_BRepFill_PipeShell.def("DeleteProfile", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &)) &BRepFill_PipeShell::DeleteProfile, "Delete an section.", py::arg("Profile"));
	cls_BRepFill_PipeShell.def("IsReady", (Standard_Boolean (BRepFill_PipeShell::*)() const ) &BRepFill_PipeShell::IsReady, "Say if <me> is ready to build the shape return False if <me> do not have section definition");
	cls_BRepFill_PipeShell.def("GetStatus", (GeomFill_PipeError (BRepFill_PipeShell::*)() const ) &BRepFill_PipeShell::GetStatus, "Get a status, when Simulate or Build failed.");
	cls_BRepFill_PipeShell.def("SetTolerance", [](BRepFill_PipeShell &self) -> void { return self.SetTolerance(); });
	cls_BRepFill_PipeShell.def("SetTolerance", [](BRepFill_PipeShell &self, const Standard_Real a0) -> void { return self.SetTolerance(a0); }, py::arg("Tol3d"));
	cls_BRepFill_PipeShell.def("SetTolerance", [](BRepFill_PipeShell &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetTolerance(a0, a1); }, py::arg("Tol3d"), py::arg("BoundTol"));
	cls_BRepFill_PipeShell.def("SetTolerance", (void (BRepFill_PipeShell::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &BRepFill_PipeShell::SetTolerance, "None", py::arg("Tol3d"), py::arg("BoundTol"), py::arg("TolAngular"));
	cls_BRepFill_PipeShell.def("SetTransition", [](BRepFill_PipeShell &self) -> void { return self.SetTransition(); });
	cls_BRepFill_PipeShell.def("SetTransition", [](BRepFill_PipeShell &self, const BRepFill_TransitionStyle a0) -> void { return self.SetTransition(a0); }, py::arg("Mode"));
	cls_BRepFill_PipeShell.def("SetTransition", [](BRepFill_PipeShell &self, const BRepFill_TransitionStyle a0, const Standard_Real a1) -> void { return self.SetTransition(a0, a1); }, py::arg("Mode"), py::arg("Angmin"));
	cls_BRepFill_PipeShell.def("SetTransition", (void (BRepFill_PipeShell::*)(const BRepFill_TransitionStyle, const Standard_Real, const Standard_Real)) &BRepFill_PipeShell::SetTransition, "Set the Transition Mode to manage discontinuities on the sweep.", py::arg("Mode"), py::arg("Angmin"), py::arg("Angmax"));
	cls_BRepFill_PipeShell.def("Simulate", (void (BRepFill_PipeShell::*)(const Standard_Integer, TopTools_ListOfShape &)) &BRepFill_PipeShell::Simulate, "Perform simulation of the sweep : Somes Section are returned.", py::arg("NumberOfSection"), py::arg("Sections"));
	cls_BRepFill_PipeShell.def("Build", (Standard_Boolean (BRepFill_PipeShell::*)()) &BRepFill_PipeShell::Build, "Builds the resulting shape (redefined from MakeShape).");
	cls_BRepFill_PipeShell.def("MakeSolid", (Standard_Boolean (BRepFill_PipeShell::*)()) &BRepFill_PipeShell::MakeSolid, "Transform the sweeping Shell in Solid. If the section are not closed returns False");
	cls_BRepFill_PipeShell.def("Shape", (const TopoDS_Shape & (BRepFill_PipeShell::*)() const ) &BRepFill_PipeShell::Shape, "Returns the result Shape.");
	cls_BRepFill_PipeShell.def("ErrorOnSurface", (Standard_Real (BRepFill_PipeShell::*)() const ) &BRepFill_PipeShell::ErrorOnSurface, "None");
	cls_BRepFill_PipeShell.def("FirstShape", (const TopoDS_Shape & (BRepFill_PipeShell::*)() const ) &BRepFill_PipeShell::FirstShape, "Returns the TopoDS Shape of the bottom of the sweep.");
	cls_BRepFill_PipeShell.def("LastShape", (const TopoDS_Shape & (BRepFill_PipeShell::*)() const ) &BRepFill_PipeShell::LastShape, "Returns the TopoDS Shape of the top of the sweep.");
	cls_BRepFill_PipeShell.def("Generated", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepFill_PipeShell::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"), py::arg("L"));
	cls_BRepFill_PipeShell.def_static("get_type_name_", (const char * (*)()) &BRepFill_PipeShell::get_type_name, "None");
	cls_BRepFill_PipeShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_PipeShell::get_type_descriptor, "None");
	cls_BRepFill_PipeShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_PipeShell::*)() const ) &BRepFill_PipeShell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_Evolved.hxx
	py::class_<BRepFill_Evolved, std::unique_ptr<BRepFill_Evolved, Deleter<BRepFill_Evolved>>> cls_BRepFill_Evolved(mod, "BRepFill_Evolved", "Constructs an evolved volume from a spine (wire or face) and a profile ( wire).");
	cls_BRepFill_Evolved.def(py::init<>());
	cls_BRepFill_Evolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &, const gp_Ax3 &>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"));
	cls_BRepFill_Evolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"));
	cls_BRepFill_Evolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"), py::arg("Solid"));
	cls_BRepFill_Evolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &, const gp_Ax3 &>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"));
	cls_BRepFill_Evolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"));
	cls_BRepFill_Evolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"), py::arg("Solid"));
	cls_BRepFill_Evolved.def("Perform", [](BRepFill_Evolved &self, const TopoDS_Wire & a0, const TopoDS_Wire & a1, const gp_Ax3 & a2) -> void { return self.Perform(a0, a1, a2); }, py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"));
	cls_BRepFill_Evolved.def("Perform", [](BRepFill_Evolved &self, const TopoDS_Wire & a0, const TopoDS_Wire & a1, const gp_Ax3 & a2, const GeomAbs_JoinType a3) -> void { return self.Perform(a0, a1, a2, a3); }, py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"));
	cls_BRepFill_Evolved.def("Perform", (void (BRepFill_Evolved::*)(const TopoDS_Wire &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType, const Standard_Boolean)) &BRepFill_Evolved::Perform, "Performs an evolved shape by sweeping the <Profile> along the <Spine>", py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"), py::arg("Solid"));
	cls_BRepFill_Evolved.def("Perform", [](BRepFill_Evolved &self, const TopoDS_Face & a0, const TopoDS_Wire & a1, const gp_Ax3 & a2) -> void { return self.Perform(a0, a1, a2); }, py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"));
	cls_BRepFill_Evolved.def("Perform", [](BRepFill_Evolved &self, const TopoDS_Face & a0, const TopoDS_Wire & a1, const gp_Ax3 & a2, const GeomAbs_JoinType a3) -> void { return self.Perform(a0, a1, a2, a3); }, py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"));
	cls_BRepFill_Evolved.def("Perform", (void (BRepFill_Evolved::*)(const TopoDS_Face &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType, const Standard_Boolean)) &BRepFill_Evolved::Perform, "Performs an evolved shape by sweeping the <Profile> along the <Spine>", py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"), py::arg("Solid"));
	cls_BRepFill_Evolved.def("IsDone", (Standard_Boolean (BRepFill_Evolved::*)() const ) &BRepFill_Evolved::IsDone, "None");
	cls_BRepFill_Evolved.def("Shape", (const TopoDS_Shape & (BRepFill_Evolved::*)() const ) &BRepFill_Evolved::Shape, "returns the generated shape.");
	cls_BRepFill_Evolved.def("GeneratedShapes", (const TopTools_ListOfShape & (BRepFill_Evolved::*)(const TopoDS_Shape &, const TopoDS_Shape &) const ) &BRepFill_Evolved::GeneratedShapes, "Returns the shapes created from a subshape <SpineShape> of the spine and a subshape <ProfShape> on the profile.", py::arg("SpineShape"), py::arg("ProfShape"));
	cls_BRepFill_Evolved.def("JoinType", (GeomAbs_JoinType (BRepFill_Evolved::*)() const ) &BRepFill_Evolved::JoinType, "None");
	cls_BRepFill_Evolved.def("Top", (const TopoDS_Shape & (BRepFill_Evolved::*)() const ) &BRepFill_Evolved::Top, "Return the face Top if <Solid> is True in the constructor.");
	cls_BRepFill_Evolved.def("Bottom", (const TopoDS_Shape & (BRepFill_Evolved::*)() const ) &BRepFill_Evolved::Bottom, "Return the face Bottom if <Solid> is True in the constructor.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_Sweep.hxx
	py::class_<BRepFill_Sweep, std::unique_ptr<BRepFill_Sweep, Deleter<BRepFill_Sweep>>> cls_BRepFill_Sweep(mod, "BRepFill_Sweep", "Topological Sweep Algorithm Computes an Sweep shell using a generating wire, an SectionLaw and an LocationLaw.");
	cls_BRepFill_Sweep.def(py::init<const opencascade::handle<BRepFill_SectionLaw> &, const opencascade::handle<BRepFill_LocationLaw> &, const Standard_Boolean>(), py::arg("Section"), py::arg("Location"), py::arg("WithKPart"));
	cls_BRepFill_Sweep.def("SetBounds", (void (BRepFill_Sweep::*)(const TopoDS_Wire &, const TopoDS_Wire &)) &BRepFill_Sweep::SetBounds, "None", py::arg("FirstShape"), py::arg("LastShape"));
	cls_BRepFill_Sweep.def("SetTolerance", [](BRepFill_Sweep &self, const Standard_Real a0) -> void { return self.SetTolerance(a0); }, py::arg("Tol3d"));
	cls_BRepFill_Sweep.def("SetTolerance", [](BRepFill_Sweep &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetTolerance(a0, a1); }, py::arg("Tol3d"), py::arg("BoundTol"));
	cls_BRepFill_Sweep.def("SetTolerance", [](BRepFill_Sweep &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetTolerance(a0, a1, a2); }, py::arg("Tol3d"), py::arg("BoundTol"), py::arg("Tol2d"));
	cls_BRepFill_Sweep.def("SetTolerance", (void (BRepFill_Sweep::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepFill_Sweep::SetTolerance, "Set Approximation Tolerance Tol3d : Tolerance to surface approximation Tol2d : Tolerance used to perform curve approximation Normaly the 2d curve are approximated with a tolerance given by the resolution on support surfaces, but if this tolerance is too large Tol2d is used. TolAngular : Tolerance (in radian) to control the angle beetween tangents on the section law and tangent of iso-v on approximed surface", py::arg("Tol3d"), py::arg("BoundTol"), py::arg("Tol2d"), py::arg("TolAngular"));
	cls_BRepFill_Sweep.def("SetAngularControl", [](BRepFill_Sweep &self) -> void { return self.SetAngularControl(); });
	cls_BRepFill_Sweep.def("SetAngularControl", [](BRepFill_Sweep &self, const Standard_Real a0) -> void { return self.SetAngularControl(a0); }, py::arg("AngleMin"));
	cls_BRepFill_Sweep.def("SetAngularControl", (void (BRepFill_Sweep::*)(const Standard_Real, const Standard_Real)) &BRepFill_Sweep::SetAngularControl, "Tolerance To controle Corner management.", py::arg("AngleMin"), py::arg("AngleMax"));
	cls_BRepFill_Sweep.def("SetForceApproxC1", (void (BRepFill_Sweep::*)(const Standard_Boolean)) &BRepFill_Sweep::SetForceApproxC1, "Set the flag that indicates attempt to approximate a C1-continuous surface if a swept surface proved to be C0.", py::arg("ForceApproxC1"));
	cls_BRepFill_Sweep.def("Build", [](BRepFill_Sweep &self, TopTools_MapOfShape & a0, BRepFill_DataMapOfShapeHArray2OfShape & a1, BRepFill_DataMapOfShapeHArray2OfShape & a2) -> void { return self.Build(a0, a1, a2); }, py::arg("ReversedEdges"), py::arg("Tapes"), py::arg("Rails"));
	cls_BRepFill_Sweep.def("Build", [](BRepFill_Sweep &self, TopTools_MapOfShape & a0, BRepFill_DataMapOfShapeHArray2OfShape & a1, BRepFill_DataMapOfShapeHArray2OfShape & a2, const BRepFill_TransitionStyle a3) -> void { return self.Build(a0, a1, a2, a3); }, py::arg("ReversedEdges"), py::arg("Tapes"), py::arg("Rails"), py::arg("Transition"));
	cls_BRepFill_Sweep.def("Build", [](BRepFill_Sweep &self, TopTools_MapOfShape & a0, BRepFill_DataMapOfShapeHArray2OfShape & a1, BRepFill_DataMapOfShapeHArray2OfShape & a2, const BRepFill_TransitionStyle a3, const GeomAbs_Shape a4) -> void { return self.Build(a0, a1, a2, a3, a4); }, py::arg("ReversedEdges"), py::arg("Tapes"), py::arg("Rails"), py::arg("Transition"), py::arg("Continuity"));
	cls_BRepFill_Sweep.def("Build", [](BRepFill_Sweep &self, TopTools_MapOfShape & a0, BRepFill_DataMapOfShapeHArray2OfShape & a1, BRepFill_DataMapOfShapeHArray2OfShape & a2, const BRepFill_TransitionStyle a3, const GeomAbs_Shape a4, const GeomFill_ApproxStyle a5) -> void { return self.Build(a0, a1, a2, a3, a4, a5); }, py::arg("ReversedEdges"), py::arg("Tapes"), py::arg("Rails"), py::arg("Transition"), py::arg("Continuity"), py::arg("Approx"));
	cls_BRepFill_Sweep.def("Build", [](BRepFill_Sweep &self, TopTools_MapOfShape & a0, BRepFill_DataMapOfShapeHArray2OfShape & a1, BRepFill_DataMapOfShapeHArray2OfShape & a2, const BRepFill_TransitionStyle a3, const GeomAbs_Shape a4, const GeomFill_ApproxStyle a5, const Standard_Integer a6) -> void { return self.Build(a0, a1, a2, a3, a4, a5, a6); }, py::arg("ReversedEdges"), py::arg("Tapes"), py::arg("Rails"), py::arg("Transition"), py::arg("Continuity"), py::arg("Approx"), py::arg("Degmax"));
	cls_BRepFill_Sweep.def("Build", (void (BRepFill_Sweep::*)(TopTools_MapOfShape &, BRepFill_DataMapOfShapeHArray2OfShape &, BRepFill_DataMapOfShapeHArray2OfShape &, const BRepFill_TransitionStyle, const GeomAbs_Shape, const GeomFill_ApproxStyle, const Standard_Integer, const Standard_Integer)) &BRepFill_Sweep::Build, "Build the Sweeep Surface Transition define Transition strategy Approx define Approximation Strategy - GeomFill_Section : The composed Function Location X Section is directly approximed. - GeomFill_Location : The location law is approximed, and the SweepSurface is bulid algebric composition of approximed location law and section law This option is Ok, if Section.Surface() methode is effective. Continuity : The continuity in v waiting on the surface Degmax : The maximum degree in v requiered on the surface Segmax : The maximum number of span in v requiered on the surface.", py::arg("ReversedEdges"), py::arg("Tapes"), py::arg("Rails"), py::arg("Transition"), py::arg("Continuity"), py::arg("Approx"), py::arg("Degmax"), py::arg("Segmax"));
	cls_BRepFill_Sweep.def("IsDone", (Standard_Boolean (BRepFill_Sweep::*)() const ) &BRepFill_Sweep::IsDone, "Say if the Shape is Build.");
	cls_BRepFill_Sweep.def("Shape", (TopoDS_Shape (BRepFill_Sweep::*)() const ) &BRepFill_Sweep::Shape, "returns the Sweeping Shape");
	cls_BRepFill_Sweep.def("ErrorOnSurface", (Standard_Real (BRepFill_Sweep::*)() const ) &BRepFill_Sweep::ErrorOnSurface, "Get the Approximation error.");
	cls_BRepFill_Sweep.def("SubShape", (opencascade::handle<TopTools_HArray2OfShape> (BRepFill_Sweep::*)() const ) &BRepFill_Sweep::SubShape, "None");
	cls_BRepFill_Sweep.def("InterFaces", (opencascade::handle<TopTools_HArray2OfShape> (BRepFill_Sweep::*)() const ) &BRepFill_Sweep::InterFaces, "None");
	cls_BRepFill_Sweep.def("Sections", (opencascade::handle<TopTools_HArray2OfShape> (BRepFill_Sweep::*)() const ) &BRepFill_Sweep::Sections, "None");
	cls_BRepFill_Sweep.def("Tape", (TopoDS_Shape (BRepFill_Sweep::*)(const Standard_Integer) const ) &BRepFill_Sweep::Tape, "returns the Tape corresponding to Index-th edge of section", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_CompatibleWires.hxx
	py::class_<BRepFill_CompatibleWires, std::unique_ptr<BRepFill_CompatibleWires, Deleter<BRepFill_CompatibleWires>>> cls_BRepFill_CompatibleWires(mod, "BRepFill_CompatibleWires", "Constructs a sequence of Wires (with good orientation and origin) agreed each other so that the surface passing through these sections is not twisted");
	cls_BRepFill_CompatibleWires.def(py::init<>());
	cls_BRepFill_CompatibleWires.def(py::init<const TopTools_SequenceOfShape &>(), py::arg("Sections"));
	cls_BRepFill_CompatibleWires.def("Init", (void (BRepFill_CompatibleWires::*)(const TopTools_SequenceOfShape &)) &BRepFill_CompatibleWires::Init, "None", py::arg("Sections"));
	cls_BRepFill_CompatibleWires.def("SetPercent", [](BRepFill_CompatibleWires &self) -> void { return self.SetPercent(); });
	cls_BRepFill_CompatibleWires.def("SetPercent", (void (BRepFill_CompatibleWires::*)(const Standard_Real)) &BRepFill_CompatibleWires::SetPercent, "None", py::arg("percent"));
	cls_BRepFill_CompatibleWires.def("Perform", [](BRepFill_CompatibleWires &self) -> void { return self.Perform(); });
	cls_BRepFill_CompatibleWires.def("Perform", (void (BRepFill_CompatibleWires::*)(const Standard_Boolean)) &BRepFill_CompatibleWires::Perform, "Performs CompatibleWires According to the orientation and the origin of each other", py::arg("WithRotation"));
	cls_BRepFill_CompatibleWires.def("IsDone", (Standard_Boolean (BRepFill_CompatibleWires::*)() const ) &BRepFill_CompatibleWires::IsDone, "None");
	cls_BRepFill_CompatibleWires.def("Shape", (const TopTools_SequenceOfShape & (BRepFill_CompatibleWires::*)() const ) &BRepFill_CompatibleWires::Shape, "returns the generated sequence.");
	cls_BRepFill_CompatibleWires.def("GeneratedShapes", (const TopTools_ListOfShape & (BRepFill_CompatibleWires::*)(const TopoDS_Edge &) const ) &BRepFill_CompatibleWires::GeneratedShapes, "Returns the shapes created from a subshape <SubSection> of a section.", py::arg("SubSection"));
	cls_BRepFill_CompatibleWires.def("Generated", (const TopTools_DataMapOfShapeListOfShape & (BRepFill_CompatibleWires::*)() const ) &BRepFill_CompatibleWires::Generated, "None");
	cls_BRepFill_CompatibleWires.def("IsDegeneratedFirstSection", (Standard_Boolean (BRepFill_CompatibleWires::*)() const ) &BRepFill_CompatibleWires::IsDegeneratedFirstSection, "None");
	cls_BRepFill_CompatibleWires.def("IsDegeneratedLastSection", (Standard_Boolean (BRepFill_CompatibleWires::*)() const ) &BRepFill_CompatibleWires::IsDegeneratedLastSection, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_OffsetWire.hxx
	py::class_<BRepFill_OffsetWire, std::unique_ptr<BRepFill_OffsetWire, Deleter<BRepFill_OffsetWire>>> cls_BRepFill_OffsetWire(mod, "BRepFill_OffsetWire", "Constructs a Offset Wire to a spine (wire or face). Offset direction will be to outer region in case of positive offset value and to inner region in case of negative offset value. Inner/Outer region for open wire is defined by the following rule: when we go along the wire (taking into account of edges orientation) then outer region will be on the right side, inner region will be on the left side. In case of closed wire, inner region will always be inside the wire (at that, edges orientation is not taken into account). The Wire or the Face must be planar and oriented correctly.");
	cls_BRepFill_OffsetWire.def(py::init<>());
	cls_BRepFill_OffsetWire.def(py::init<const TopoDS_Face &>(), py::arg("Spine"));
	cls_BRepFill_OffsetWire.def(py::init<const TopoDS_Face &, const GeomAbs_JoinType>(), py::arg("Spine"), py::arg("Join"));
	cls_BRepFill_OffsetWire.def(py::init<const TopoDS_Face &, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("Spine"), py::arg("Join"), py::arg("IsOpenResult"));
	cls_BRepFill_OffsetWire.def("Init", [](BRepFill_OffsetWire &self, const TopoDS_Face & a0) -> void { return self.Init(a0); }, py::arg("Spine"));
	cls_BRepFill_OffsetWire.def("Init", [](BRepFill_OffsetWire &self, const TopoDS_Face & a0, const GeomAbs_JoinType a1) -> void { return self.Init(a0, a1); }, py::arg("Spine"), py::arg("Join"));
	cls_BRepFill_OffsetWire.def("Init", (void (BRepFill_OffsetWire::*)(const TopoDS_Face &, const GeomAbs_JoinType, const Standard_Boolean)) &BRepFill_OffsetWire::Init, "Initialize the evaluation of Offseting.", py::arg("Spine"), py::arg("Join"), py::arg("IsOpenResult"));
	cls_BRepFill_OffsetWire.def("Perform", [](BRepFill_OffsetWire &self, const Standard_Real a0) -> void { return self.Perform(a0); }, py::arg("Offset"));
	cls_BRepFill_OffsetWire.def("Perform", (void (BRepFill_OffsetWire::*)(const Standard_Real, const Standard_Real)) &BRepFill_OffsetWire::Perform, "Performs an OffsetWire at an altitude <Alt> from the face ( According to the orientation of the face)", py::arg("Offset"), py::arg("Alt"));
	cls_BRepFill_OffsetWire.def("PerformWithBiLo", [](BRepFill_OffsetWire &self, const TopoDS_Face & a0, const Standard_Real a1, const BRepMAT2d_BisectingLocus & a2, BRepMAT2d_LinkTopoBilo & a3) -> void { return self.PerformWithBiLo(a0, a1, a2, a3); }, py::arg("WSP"), py::arg("Offset"), py::arg("Locus"), py::arg("Link"));
	cls_BRepFill_OffsetWire.def("PerformWithBiLo", [](BRepFill_OffsetWire &self, const TopoDS_Face & a0, const Standard_Real a1, const BRepMAT2d_BisectingLocus & a2, BRepMAT2d_LinkTopoBilo & a3, const GeomAbs_JoinType a4) -> void { return self.PerformWithBiLo(a0, a1, a2, a3, a4); }, py::arg("WSP"), py::arg("Offset"), py::arg("Locus"), py::arg("Link"), py::arg("Join"));
	cls_BRepFill_OffsetWire.def("PerformWithBiLo", (void (BRepFill_OffsetWire::*)(const TopoDS_Face &, const Standard_Real, const BRepMAT2d_BisectingLocus &, BRepMAT2d_LinkTopoBilo &, const GeomAbs_JoinType, const Standard_Real)) &BRepFill_OffsetWire::PerformWithBiLo, "Performs an OffsetWire", py::arg("WSP"), py::arg("Offset"), py::arg("Locus"), py::arg("Link"), py::arg("Join"), py::arg("Alt"));
	cls_BRepFill_OffsetWire.def("IsDone", (Standard_Boolean (BRepFill_OffsetWire::*)() const ) &BRepFill_OffsetWire::IsDone, "None");
	cls_BRepFill_OffsetWire.def("Spine", (const TopoDS_Face & (BRepFill_OffsetWire::*)() const ) &BRepFill_OffsetWire::Spine, "None");
	cls_BRepFill_OffsetWire.def("Shape", (const TopoDS_Shape & (BRepFill_OffsetWire::*)() const ) &BRepFill_OffsetWire::Shape, "returns the generated shape.");
	cls_BRepFill_OffsetWire.def("GeneratedShapes", (const TopTools_ListOfShape & (BRepFill_OffsetWire::*)(const TopoDS_Shape &)) &BRepFill_OffsetWire::GeneratedShapes, "Returns the shapes created from a subshape <SpineShape> of the spine. Returns the last computed Offset.", py::arg("SpineShape"));
	cls_BRepFill_OffsetWire.def("JoinType", (GeomAbs_JoinType (BRepFill_OffsetWire::*)() const ) &BRepFill_OffsetWire::JoinType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_OffsetAncestors.hxx
	py::class_<BRepFill_OffsetAncestors, std::unique_ptr<BRepFill_OffsetAncestors, Deleter<BRepFill_OffsetAncestors>>> cls_BRepFill_OffsetAncestors(mod, "BRepFill_OffsetAncestors", "this class is used to find the generating shapes of an OffsetWire.");
	cls_BRepFill_OffsetAncestors.def(py::init<>());
	cls_BRepFill_OffsetAncestors.def(py::init<BRepFill_OffsetWire &>(), py::arg("Paral"));
	cls_BRepFill_OffsetAncestors.def("Perform", (void (BRepFill_OffsetAncestors::*)(BRepFill_OffsetWire &)) &BRepFill_OffsetAncestors::Perform, "None", py::arg("Paral"));
	cls_BRepFill_OffsetAncestors.def("IsDone", (Standard_Boolean (BRepFill_OffsetAncestors::*)() const ) &BRepFill_OffsetAncestors::IsDone, "None");
	cls_BRepFill_OffsetAncestors.def("HasAncestor", (Standard_Boolean (BRepFill_OffsetAncestors::*)(const TopoDS_Edge &) const ) &BRepFill_OffsetAncestors::HasAncestor, "None", py::arg("S1"));
	cls_BRepFill_OffsetAncestors.def("Ancestor", (const TopoDS_Shape & (BRepFill_OffsetAncestors::*)(const TopoDS_Edge &) const ) &BRepFill_OffsetAncestors::Ancestor, "may return a Null Shape if S1 is not a subShape of <Paral>; if Perform is not done.", py::arg("S1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_ApproxSeewing.hxx
	py::class_<BRepFill_ApproxSeewing, std::unique_ptr<BRepFill_ApproxSeewing, Deleter<BRepFill_ApproxSeewing>>> cls_BRepFill_ApproxSeewing(mod, "BRepFill_ApproxSeewing", "Evaluate the 3dCurve and the PCurves described in a MultiLine from BRepFill. The parametrization of those curves is not imposed by the Bissectrice. The parametrization is given approximatively by the abscissa of the curve3d.");
	cls_BRepFill_ApproxSeewing.def(py::init<>());
	cls_BRepFill_ApproxSeewing.def(py::init<const BRepFill_MultiLine &>(), py::arg("ML"));
	cls_BRepFill_ApproxSeewing.def("Perform", (void (BRepFill_ApproxSeewing::*)(const BRepFill_MultiLine &)) &BRepFill_ApproxSeewing::Perform, "None", py::arg("ML"));
	cls_BRepFill_ApproxSeewing.def("IsDone", (Standard_Boolean (BRepFill_ApproxSeewing::*)() const ) &BRepFill_ApproxSeewing::IsDone, "None");
	cls_BRepFill_ApproxSeewing.def("Curve", (const opencascade::handle<Geom_Curve> & (BRepFill_ApproxSeewing::*)() const ) &BRepFill_ApproxSeewing::Curve, "returns the approximation of the 3d Curve");
	cls_BRepFill_ApproxSeewing.def("CurveOnF1", (const opencascade::handle<Geom2d_Curve> & (BRepFill_ApproxSeewing::*)() const ) &BRepFill_ApproxSeewing::CurveOnF1, "returns the approximation of the PCurve on the first face of the MultiLine");
	cls_BRepFill_ApproxSeewing.def("CurveOnF2", (const opencascade::handle<Geom2d_Curve> & (BRepFill_ApproxSeewing::*)() const ) &BRepFill_ApproxSeewing::CurveOnF2, "returns the approximation of the PCurve on the first face of the MultiLine");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_ComputeCLine.hxx
	py::class_<BRepFill_ComputeCLine, std::unique_ptr<BRepFill_ComputeCLine, Deleter<BRepFill_ComputeCLine>>> cls_BRepFill_ComputeCLine(mod, "BRepFill_ComputeCLine", "None");
	cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &>(), py::arg("Line"));
	cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
	cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
	cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
	cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
	cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"));
	cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"));
	cls_BRepFill_ComputeCLine.def(py::init<const BRepFill_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint, const AppParCurves_Constraint>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"), py::arg("LastC"));
	cls_BRepFill_ComputeCLine.def(py::init<>());
	cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
	cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
	cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
	cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
	cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"));
	cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"));
	cls_BRepFill_ComputeCLine.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint, const AppParCurves_Constraint>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"), py::arg("LastC"));
	cls_BRepFill_ComputeCLine.def("Perform", (void (BRepFill_ComputeCLine::*)(const BRepFill_MultiLine &)) &BRepFill_ComputeCLine::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
	cls_BRepFill_ComputeCLine.def("SetDegrees", (void (BRepFill_ComputeCLine::*)(const Standard_Integer, const Standard_Integer)) &BRepFill_ComputeCLine::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
	cls_BRepFill_ComputeCLine.def("SetTolerances", (void (BRepFill_ComputeCLine::*)(const Standard_Real, const Standard_Real)) &BRepFill_ComputeCLine::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
	cls_BRepFill_ComputeCLine.def("SetConstraints", (void (BRepFill_ComputeCLine::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &BRepFill_ComputeCLine::SetConstraints, "Changes the constraints of the approximation.", py::arg("FirstC"), py::arg("LastC"));
	cls_BRepFill_ComputeCLine.def("IsAllApproximated", (Standard_Boolean (BRepFill_ComputeCLine::*)() const ) &BRepFill_ComputeCLine::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
	cls_BRepFill_ComputeCLine.def("IsToleranceReached", (Standard_Boolean (BRepFill_ComputeCLine::*)() const ) &BRepFill_ComputeCLine::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
	cls_BRepFill_ComputeCLine.def("Error", (void (BRepFill_ComputeCLine::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &BRepFill_ComputeCLine::Error, "returns the tolerances 2d and 3d of the <Index> MultiCurve.", py::arg("Index"), py::arg("tol3d"), py::arg("tol2d"));
	cls_BRepFill_ComputeCLine.def("NbMultiCurves", (Standard_Integer (BRepFill_ComputeCLine::*)() const ) &BRepFill_ComputeCLine::NbMultiCurves, "Returns the number of MultiCurve doing the approximation of the MultiLine.");
	cls_BRepFill_ComputeCLine.def("Value", [](BRepFill_ComputeCLine &self) -> AppParCurves_MultiCurve { return self.Value(); });
	cls_BRepFill_ComputeCLine.def("Value", (AppParCurves_MultiCurve (BRepFill_ComputeCLine::*)(const Standard_Integer) const ) &BRepFill_ComputeCLine::Value, "returns the approximation MultiCurve of range <Index>.", py::arg("Index"));
	cls_BRepFill_ComputeCLine.def("Parameters", (void (BRepFill_ComputeCLine::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &BRepFill_ComputeCLine::Parameters, "None", py::arg("Index"), py::arg("firstp"), py::arg("lastp"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_TrimSurfaceTool.hxx
	py::class_<BRepFill_TrimSurfaceTool, std::unique_ptr<BRepFill_TrimSurfaceTool, Deleter<BRepFill_TrimSurfaceTool>>> cls_BRepFill_TrimSurfaceTool(mod, "BRepFill_TrimSurfaceTool", "Compute the Pcurves and the 3d curves resulting of the trimming of a face by an extruded surface.");
	cls_BRepFill_TrimSurfaceTool.def(py::init<const opencascade::handle<Geom2d_Curve> &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean, const Standard_Boolean>(), py::arg("Bis"), py::arg("Face1"), py::arg("Face2"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Inv1"), py::arg("Inv2"));
	cls_BRepFill_TrimSurfaceTool.def("IntersectWith", (void (BRepFill_TrimSurfaceTool::*)(const TopoDS_Edge &, const TopoDS_Edge &, TColgp_SequenceOfPnt &) const ) &BRepFill_TrimSurfaceTool::IntersectWith, "Intersect <Bis> with the projection of the edges <EdgeOnFi> and returns the intersecting parameters on Bis and on the edges P.X() : Parameter on Bis P.Y() : Parameter on EdgeOnF1 P.Z() : Parameter on EdgeOnF2 raises if <Edge> is not a edge of Face1 or Face2.", py::arg("EdgeOnF1"), py::arg("EdgeOnF2"), py::arg("Points"));
	cls_BRepFill_TrimSurfaceTool.def("IsOnFace", (Standard_Boolean (BRepFill_TrimSurfaceTool::*)(const gp_Pnt2d &) const ) &BRepFill_TrimSurfaceTool::IsOnFace, "returns True if the Line (P, DZ) intersect the Faces", py::arg("Point"));
	cls_BRepFill_TrimSurfaceTool.def("ProjOn", (Standard_Real (BRepFill_TrimSurfaceTool::*)(const gp_Pnt2d &, const TopoDS_Edge &) const ) &BRepFill_TrimSurfaceTool::ProjOn, "returns the parameter of the point <Point> on the Edge <Edge>, assuming that the point is on the edge.", py::arg("Point"), py::arg("Edge"));
	cls_BRepFill_TrimSurfaceTool.def("Project", (void (BRepFill_TrimSurfaceTool::*)(const Standard_Real, const Standard_Real, opencascade::handle<Geom_Curve> &, opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &, GeomAbs_Shape &) const ) &BRepFill_TrimSurfaceTool::Project, "None", py::arg("U1"), py::arg("U2"), py::arg("Curve"), py::arg("PCurve1"), py::arg("PCurve2"), py::arg("myCont"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_TrimEdgeTool.hxx
	py::class_<BRepFill_TrimEdgeTool, std::unique_ptr<BRepFill_TrimEdgeTool, Deleter<BRepFill_TrimEdgeTool>>> cls_BRepFill_TrimEdgeTool(mod, "BRepFill_TrimEdgeTool", "Geometric Tool using to construct Offset Wires.");
	cls_BRepFill_TrimEdgeTool.def(py::init<>());
	cls_BRepFill_TrimEdgeTool.def(py::init<const Bisector_Bisec &, const opencascade::handle<Geom2d_Geometry> &, const opencascade::handle<Geom2d_Geometry> &, const Standard_Real>(), py::arg("Bisec"), py::arg("S1"), py::arg("S2"), py::arg("Offset"));
	cls_BRepFill_TrimEdgeTool.def("IntersectWith", (void (BRepFill_TrimEdgeTool::*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Vertex &, const TopoDS_Vertex &, const GeomAbs_JoinType, const Standard_Boolean, TColgp_SequenceOfPnt &)) &BRepFill_TrimEdgeTool::IntersectWith, "None", py::arg("Edge1"), py::arg("Edge2"), py::arg("InitShape1"), py::arg("InitShape2"), py::arg("End1"), py::arg("End2"), py::arg("theJoinType"), py::arg("IsOpenResult"), py::arg("Params"));
	cls_BRepFill_TrimEdgeTool.def("AddOrConfuse", (void (BRepFill_TrimEdgeTool::*)(const Standard_Boolean, const TopoDS_Edge &, const TopoDS_Edge &, TColgp_SequenceOfPnt &) const ) &BRepFill_TrimEdgeTool::AddOrConfuse, "None", py::arg("Start"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Params"));
	cls_BRepFill_TrimEdgeTool.def("IsInside", (Standard_Boolean (BRepFill_TrimEdgeTool::*)(const gp_Pnt2d &) const ) &BRepFill_TrimEdgeTool::IsInside, "None", py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_SectionPlacement.hxx
	py::class_<BRepFill_SectionPlacement, std::unique_ptr<BRepFill_SectionPlacement, Deleter<BRepFill_SectionPlacement>>> cls_BRepFill_SectionPlacement(mod, "BRepFill_SectionPlacement", "Place a shape in a local axis coordinate");
	cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &>(), py::arg("Law"), py::arg("Section"));
	cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Law"), py::arg("Section"), py::arg("WithContact"));
	cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("Law"), py::arg("Section"), py::arg("WithContact"), py::arg("WithCorrection"));
	cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("Law"), py::arg("Section"), py::arg("Vertex"));
	cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Law"), py::arg("Section"), py::arg("Vertex"), py::arg("WithContact"));
	cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("Law"), py::arg("Section"), py::arg("Vertex"), py::arg("WithContact"), py::arg("WithCorrection"));
	cls_BRepFill_SectionPlacement.def("Transformation", (const gp_Trsf & (BRepFill_SectionPlacement::*)() const ) &BRepFill_SectionPlacement::Transformation, "None");
	cls_BRepFill_SectionPlacement.def("AbscissaOnPath", (Standard_Real (BRepFill_SectionPlacement::*)()) &BRepFill_SectionPlacement::AbscissaOnPath, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_Section.hxx
	py::class_<BRepFill_Section, std::unique_ptr<BRepFill_Section, Deleter<BRepFill_Section>>> cls_BRepFill_Section(mod, "BRepFill_Section", "To store section definition");
	cls_BRepFill_Section.def(py::init<>());
	cls_BRepFill_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Vertex &, const Standard_Boolean, const Standard_Boolean>(), py::arg("Profile"), py::arg("V"), py::arg("WithContact"), py::arg("WithCorrection"));
	cls_BRepFill_Section.def("Set", (void (BRepFill_Section::*)(const Standard_Boolean)) &BRepFill_Section::Set, "None", py::arg("IsLaw"));
	cls_BRepFill_Section.def("Wire", (const TopoDS_Wire & (BRepFill_Section::*)() const ) &BRepFill_Section::Wire, "None");
	cls_BRepFill_Section.def("Vertex", (const TopoDS_Vertex & (BRepFill_Section::*)() const ) &BRepFill_Section::Vertex, "None");
	cls_BRepFill_Section.def("IsLaw", (Standard_Boolean (BRepFill_Section::*)() const ) &BRepFill_Section::IsLaw, "None");
	cls_BRepFill_Section.def("IsPunctual", (Standard_Boolean (BRepFill_Section::*)() const ) &BRepFill_Section::IsPunctual, "None");
	cls_BRepFill_Section.def("WithContact", (Standard_Boolean (BRepFill_Section::*)() const ) &BRepFill_Section::WithContact, "None");
	cls_BRepFill_Section.def("WithCorrection", (Standard_Boolean (BRepFill_Section::*)() const ) &BRepFill_Section::WithCorrection, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_TrimShellCorner.hxx
	py::class_<BRepFill_TrimShellCorner, std::unique_ptr<BRepFill_TrimShellCorner, Deleter<BRepFill_TrimShellCorner>>> cls_BRepFill_TrimShellCorner(mod, "BRepFill_TrimShellCorner", "None");
	cls_BRepFill_TrimShellCorner.def(py::init<const opencascade::handle<TopTools_HArray2OfShape> &, const gp_Ax2 &, const TopoDS_Face &>(), py::arg("theFaces"), py::arg("theAxeOfBisPlane"), py::arg("theSecPlane"));
	cls_BRepFill_TrimShellCorner.def(py::init<const opencascade::handle<TopTools_HArray2OfShape> &, const gp_Ax2 &, const TopoDS_Wire &, const TopoDS_Face &>(), py::arg("theFaces"), py::arg("theAxeOfBisPlane"), py::arg("theSpine"), py::arg("theSecPlane"));
	cls_BRepFill_TrimShellCorner.def("SetSpine", (void (BRepFill_TrimShellCorner::*)(const TopoDS_Wire &)) &BRepFill_TrimShellCorner::SetSpine, "None", py::arg("theSpine"));
	cls_BRepFill_TrimShellCorner.def("AddBounds", (void (BRepFill_TrimShellCorner::*)(const opencascade::handle<TopTools_HArray2OfShape> &)) &BRepFill_TrimShellCorner::AddBounds, "None", py::arg("Bounds"));
	cls_BRepFill_TrimShellCorner.def("AddUEdges", (void (BRepFill_TrimShellCorner::*)(const opencascade::handle<TopTools_HArray2OfShape> &)) &BRepFill_TrimShellCorner::AddUEdges, "None", py::arg("theUEdges"));
	cls_BRepFill_TrimShellCorner.def("Perform", (void (BRepFill_TrimShellCorner::*)()) &BRepFill_TrimShellCorner::Perform, "None");
	cls_BRepFill_TrimShellCorner.def("IsDone", (Standard_Boolean (BRepFill_TrimShellCorner::*)() const ) &BRepFill_TrimShellCorner::IsDone, "None");
	cls_BRepFill_TrimShellCorner.def("HasSection", (Standard_Boolean (BRepFill_TrimShellCorner::*)() const ) &BRepFill_TrimShellCorner::HasSection, "None");
	cls_BRepFill_TrimShellCorner.def("Modified", (void (BRepFill_TrimShellCorner::*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepFill_TrimShellCorner::Modified, "None", py::arg("S"), py::arg("theModified"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_CurveConstraint.hxx
	py::class_<BRepFill_CurveConstraint, opencascade::handle<BRepFill_CurveConstraint>, GeomPlate_CurveConstraint> cls_BRepFill_CurveConstraint(mod, "BRepFill_CurveConstraint", "same as CurveConstraint from GeomPlate with BRepAdaptor_Surface instead of GeomAdaptor_Surface");
	cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurveOnSurface> &, const Standard_Integer>(), py::arg("Boundary"), py::arg("Order"));
	cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurveOnSurface> &, const Standard_Integer, const Standard_Integer>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"));
	cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurveOnSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"));
	cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurveOnSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"), py::arg("TolAng"));
	cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurveOnSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"), py::arg("TolAng"), py::arg("TolCurv"));
	cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer>(), py::arg("Boundary"), py::arg("Tang"));
	cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer>(), py::arg("Boundary"), py::arg("Tang"), py::arg("NPt"));
	cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Boundary"), py::arg("Tang"), py::arg("NPt"), py::arg("TolDist"));
	cls_BRepFill_CurveConstraint.def_static("get_type_name_", (const char * (*)()) &BRepFill_CurveConstraint::get_type_name, "None");
	cls_BRepFill_CurveConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_CurveConstraint::get_type_descriptor, "None");
	cls_BRepFill_CurveConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_CurveConstraint::*)() const ) &BRepFill_CurveConstraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_Filling.hxx
	py::class_<BRepFill_Filling, std::unique_ptr<BRepFill_Filling, Deleter<BRepFill_Filling>>> cls_BRepFill_Filling(mod, "BRepFill_Filling", "N-Side Filling This algorithm avoids to build a face from: * a set of edges defining the bounds of the face and some constraints the surface support has to satisfy * a set of edges and points defining some constraints the support surface has to satisfy * an initial surface to deform for satisfying the constraints * a set of parameters to control the constraints.");
	cls_BRepFill_Filling.def(py::init<>());
	cls_BRepFill_Filling.def(py::init<const Standard_Integer>(), py::arg("Degree"));
	cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"));
	cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"));
	cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"));
	cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"));
	cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"));
	cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"));
	cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
	cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("MaxDeg"));
	cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("MaxDeg"), py::arg("MaxSegments"));
	cls_BRepFill_Filling.def("SetConstrParam", [](BRepFill_Filling &self) -> void { return self.SetConstrParam(); });
	cls_BRepFill_Filling.def("SetConstrParam", [](BRepFill_Filling &self, const Standard_Real a0) -> void { return self.SetConstrParam(a0); }, py::arg("Tol2d"));
	cls_BRepFill_Filling.def("SetConstrParam", [](BRepFill_Filling &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetConstrParam(a0, a1); }, py::arg("Tol2d"), py::arg("Tol3d"));
	cls_BRepFill_Filling.def("SetConstrParam", [](BRepFill_Filling &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetConstrParam(a0, a1, a2); }, py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"));
	cls_BRepFill_Filling.def("SetConstrParam", (void (BRepFill_Filling::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepFill_Filling::SetConstrParam, "Sets the values of Tolerances used to control the constraint. Tol2d: Tol3d: it is the maximum distance allowed between the support surface and the constraints TolAng: it is the maximum angle allowed between the normal of the surface and the constraints TolCurv: it is the maximum difference of curvature allowed between the surface and the constraint", py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
	cls_BRepFill_Filling.def("SetResolParam", [](BRepFill_Filling &self) -> void { return self.SetResolParam(); });
	cls_BRepFill_Filling.def("SetResolParam", [](BRepFill_Filling &self, const Standard_Integer a0) -> void { return self.SetResolParam(a0); }, py::arg("Degree"));
	cls_BRepFill_Filling.def("SetResolParam", [](BRepFill_Filling &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.SetResolParam(a0, a1); }, py::arg("Degree"), py::arg("NbPtsOnCur"));
	cls_BRepFill_Filling.def("SetResolParam", [](BRepFill_Filling &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2) -> void { return self.SetResolParam(a0, a1, a2); }, py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"));
	cls_BRepFill_Filling.def("SetResolParam", (void (BRepFill_Filling::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &BRepFill_Filling::SetResolParam, "Sets the parameters used for resolution. The default values of these parameters have been chosen for a good ratio quality/performance. Degree: it is the order of energy criterion to minimize for computing the deformation of the surface. The default value is 3 The recommanded value is i+2 where i is the maximum order of the constraints. NbPtsOnCur: it is the average number of points for discretisation of the edges. NbIter: it is the maximum number of iterations of the process. For each iteration the number of discretisation points is increased. Anisotropie:", py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"));
	cls_BRepFill_Filling.def("SetApproxParam", [](BRepFill_Filling &self) -> void { return self.SetApproxParam(); });
	cls_BRepFill_Filling.def("SetApproxParam", [](BRepFill_Filling &self, const Standard_Integer a0) -> void { return self.SetApproxParam(a0); }, py::arg("MaxDeg"));
	cls_BRepFill_Filling.def("SetApproxParam", (void (BRepFill_Filling::*)(const Standard_Integer, const Standard_Integer)) &BRepFill_Filling::SetApproxParam, "Sets the parameters used for approximation of the surface", py::arg("MaxDeg"), py::arg("MaxSegments"));
	cls_BRepFill_Filling.def("LoadInitSurface", (void (BRepFill_Filling::*)(const TopoDS_Face &)) &BRepFill_Filling::LoadInitSurface, "Loads the initial Surface The initial surface must have orthogonal local coordinates, i.e. partial derivatives dS/du and dS/dv must be orthogonal at each point of surface. If this condition breaks, distortions of resulting surface are possible.", py::arg("aFace"));
	cls_BRepFill_Filling.def("Add", [](BRepFill_Filling &self, const TopoDS_Edge & a0, const GeomAbs_Shape a1) -> Standard_Integer { return self.Add(a0, a1); }, py::arg("anEdge"), py::arg("Order"));
	cls_BRepFill_Filling.def("Add", (Standard_Integer (BRepFill_Filling::*)(const TopoDS_Edge &, const GeomAbs_Shape, const Standard_Boolean)) &BRepFill_Filling::Add, "Adds a new constraint which also defines an edge of the wire of the face Order: Order of the constraint: GeomAbs_C0 : the surface has to pass by 3D representation of the edge GeomAbs_G1 : the surface has to pass by 3D representation of the edge and to respect tangency with the first face of the edge GeomAbs_G2 : the surface has to pass by 3D representation of the edge and to respect tangency and curvature with the first face of the edge.", py::arg("anEdge"), py::arg("Order"), py::arg("IsBound"));
	cls_BRepFill_Filling.def("Add", [](BRepFill_Filling &self, const TopoDS_Edge & a0, const TopoDS_Face & a1, const GeomAbs_Shape a2) -> Standard_Integer { return self.Add(a0, a1, a2); }, py::arg("anEdge"), py::arg("Support"), py::arg("Order"));
	cls_BRepFill_Filling.def("Add", (Standard_Integer (BRepFill_Filling::*)(const TopoDS_Edge &, const TopoDS_Face &, const GeomAbs_Shape, const Standard_Boolean)) &BRepFill_Filling::Add, "Adds a new constraint which also defines an edge of the wire of the face Order: Order of the constraint: GeomAbs_C0 : the surface has to pass by 3D representation of the edge GeomAbs_G1 : the surface has to pass by 3D representation of the edge and to respect tangency with the given face GeomAbs_G2 : the surface has to pass by 3D representation of the edge and to respect tangency and curvature with the given face.", py::arg("anEdge"), py::arg("Support"), py::arg("Order"), py::arg("IsBound"));
	cls_BRepFill_Filling.def("Add", (Standard_Integer (BRepFill_Filling::*)(const TopoDS_Face &, const GeomAbs_Shape)) &BRepFill_Filling::Add, "Adds a free constraint on a face. The corresponding edge has to be automatically recomputed. It is always a bound.", py::arg("Support"), py::arg("Order"));
	cls_BRepFill_Filling.def("Add", (Standard_Integer (BRepFill_Filling::*)(const gp_Pnt &)) &BRepFill_Filling::Add, "Adds a punctual constraint", py::arg("Point"));
	cls_BRepFill_Filling.def("Add", (Standard_Integer (BRepFill_Filling::*)(const Standard_Real, const Standard_Real, const TopoDS_Face &, const GeomAbs_Shape)) &BRepFill_Filling::Add, "Adds a punctual constraint.", py::arg("U"), py::arg("V"), py::arg("Support"), py::arg("Order"));
	cls_BRepFill_Filling.def("Build", (void (BRepFill_Filling::*)()) &BRepFill_Filling::Build, "Builds the resulting faces");
	cls_BRepFill_Filling.def("IsDone", (Standard_Boolean (BRepFill_Filling::*)() const ) &BRepFill_Filling::IsDone, "None");
	cls_BRepFill_Filling.def("Face", (TopoDS_Face (BRepFill_Filling::*)() const ) &BRepFill_Filling::Face, "None");
	cls_BRepFill_Filling.def("Generated", (const TopTools_ListOfShape & (BRepFill_Filling::*)(const TopoDS_Shape &)) &BRepFill_Filling::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
	cls_BRepFill_Filling.def("G0Error", (Standard_Real (BRepFill_Filling::*)() const ) &BRepFill_Filling::G0Error, "None");
	cls_BRepFill_Filling.def("G1Error", (Standard_Real (BRepFill_Filling::*)() const ) &BRepFill_Filling::G1Error, "None");
	cls_BRepFill_Filling.def("G2Error", (Standard_Real (BRepFill_Filling::*)() const ) &BRepFill_Filling::G2Error, "None");
	cls_BRepFill_Filling.def("G0Error", (Standard_Real (BRepFill_Filling::*)(const Standard_Integer)) &BRepFill_Filling::G0Error, "None", py::arg("Index"));
	cls_BRepFill_Filling.def("G1Error", (Standard_Real (BRepFill_Filling::*)(const Standard_Integer)) &BRepFill_Filling::G1Error, "None", py::arg("Index"));
	cls_BRepFill_Filling.def("G2Error", (Standard_Real (BRepFill_Filling::*)(const Standard_Integer)) &BRepFill_Filling::G2Error, "None", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_FaceAndOrder.hxx
	py::class_<BRepFill_FaceAndOrder, std::unique_ptr<BRepFill_FaceAndOrder, Deleter<BRepFill_FaceAndOrder>>> cls_BRepFill_FaceAndOrder(mod, "BRepFill_FaceAndOrder", "A structure containing Face and Order of constraint");
	cls_BRepFill_FaceAndOrder.def(py::init<>());
	cls_BRepFill_FaceAndOrder.def(py::init<const TopoDS_Face &, const GeomAbs_Shape>(), py::arg("aFace"), py::arg("anOrder"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_EdgeFaceAndOrder.hxx
	py::class_<BRepFill_EdgeFaceAndOrder, std::unique_ptr<BRepFill_EdgeFaceAndOrder, Deleter<BRepFill_EdgeFaceAndOrder>>> cls_BRepFill_EdgeFaceAndOrder(mod, "BRepFill_EdgeFaceAndOrder", "None");
	cls_BRepFill_EdgeFaceAndOrder.def(py::init<>());
	cls_BRepFill_EdgeFaceAndOrder.def(py::init<const TopoDS_Edge &, const TopoDS_Face &, const GeomAbs_Shape>(), py::arg("anEdge"), py::arg("aFace"), py::arg("anOrder"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill.hxx
	py::class_<BRepFill, std::unique_ptr<BRepFill, Deleter<BRepFill>>> cls_BRepFill(mod, "BRepFill", "None");
	cls_BRepFill.def(py::init<>());
	cls_BRepFill.def_static("Face_", (TopoDS_Face (*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BRepFill::Face, "Computes a ruled surface between two edges.", py::arg("Edge1"), py::arg("Edge2"));
	cls_BRepFill.def_static("Shell_", (TopoDS_Shell (*)(const TopoDS_Wire &, const TopoDS_Wire &)) &BRepFill::Shell, "Computes a ruled surface between two wires. The wires must have the same number of edges.", py::arg("Wire1"), py::arg("Wire2"));
	cls_BRepFill.def_static("Axe_", (void (*)(const TopoDS_Shape &, const TopoDS_Wire &, gp_Ax3 &, Standard_Boolean &, const Standard_Real)) &BRepFill::Axe, "Computes <AxeProf> as Follow. <Location> is the Position of the nearest vertex V of <Profile> to <Spine>.<XDirection> is confused with the tangent to <Spine> at the projected point of V on the Spine. <Direction> is normal to <Spine>. <Spine> is a plane wire or a plane face.", py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("ProfOnSpine"), py::arg("Tol"));
	cls_BRepFill.def_static("ComputeACR_", (void (*)(const TopoDS_Wire &, TColStd_Array1OfReal &)) &BRepFill::ComputeACR, "Compute ACR on a wire", py::arg("wire"), py::arg("ACR"));
	cls_BRepFill.def_static("InsertACR_", (TopoDS_Wire (*)(const TopoDS_Wire &, const TColStd_Array1OfReal &, const Standard_Real)) &BRepFill::InsertACR, "Insert ACR on a wire", py::arg("wire"), py::arg("ACRcuts"), py::arg("prec"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_MultiLine.hxx
	py::class_<BRepFill_MultiLine, std::unique_ptr<BRepFill_MultiLine, Deleter<BRepFill_MultiLine>>, AppCont_Function> cls_BRepFill_MultiLine(mod, "BRepFill_MultiLine", "Class used to compute the 3d curve and the two 2d curves resulting from the intersection of a surface of linear extrusion( Bissec, Dz) and the 2 faces. This 3 curves will have the same parametrization as the Bissectrice. This class is to be send to an approximation routine.");
	cls_BRepFill_MultiLine.def(py::init<>());
	cls_BRepFill_MultiLine.def(py::init<const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<Geom2d_Curve> &>(), py::arg("Face1"), py::arg("Face2"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Inv1"), py::arg("Inv2"), py::arg("Bissec"));
	cls_BRepFill_MultiLine.def("IsParticularCase", (Standard_Boolean (BRepFill_MultiLine::*)() const ) &BRepFill_MultiLine::IsParticularCase, "Search if the Projection of the Bissectrice on the faces needs an approximation or not. Returns true if the approximation is not needed.");
	cls_BRepFill_MultiLine.def("Continuity", (GeomAbs_Shape (BRepFill_MultiLine::*)() const ) &BRepFill_MultiLine::Continuity, "Returns the continuity betwwen the two faces seShape from GeomAbsparated by myBis.");
	cls_BRepFill_MultiLine.def("Curves", (void (BRepFill_MultiLine::*)(opencascade::handle<Geom_Curve> &, opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &) const ) &BRepFill_MultiLine::Curves, "raises if IsParticularCase is <False>.", py::arg("Curve"), py::arg("PCurve1"), py::arg("PCurve2"));
	cls_BRepFill_MultiLine.def("FirstParameter", (Standard_Real (BRepFill_MultiLine::*)() const ) &BRepFill_MultiLine::FirstParameter, "returns the first parameter of the Bissectrice.");
	cls_BRepFill_MultiLine.def("LastParameter", (Standard_Real (BRepFill_MultiLine::*)() const ) &BRepFill_MultiLine::LastParameter, "returns the last parameter of the Bissectrice.");
	cls_BRepFill_MultiLine.def("Value", (gp_Pnt (BRepFill_MultiLine::*)(const Standard_Real) const ) &BRepFill_MultiLine::Value, "Returns the current point on the 3d curve", py::arg("U"));
	cls_BRepFill_MultiLine.def("ValueOnF1", (gp_Pnt2d (BRepFill_MultiLine::*)(const Standard_Real) const ) &BRepFill_MultiLine::ValueOnF1, "returns the current point on the PCurve of the first face", py::arg("U"));
	cls_BRepFill_MultiLine.def("ValueOnF2", (gp_Pnt2d (BRepFill_MultiLine::*)(const Standard_Real) const ) &BRepFill_MultiLine::ValueOnF2, "returns the current point on the PCurve of the first face", py::arg("U"));
	cls_BRepFill_MultiLine.def("Value3dOnF1OnF2", (void (BRepFill_MultiLine::*)(const Standard_Real, gp_Pnt &, gp_Pnt2d &, gp_Pnt2d &) const ) &BRepFill_MultiLine::Value3dOnF1OnF2, "None", py::arg("U"), py::arg("P3d"), py::arg("PF1"), py::arg("PF2"));
	cls_BRepFill_MultiLine.def("Value", (Standard_Boolean (BRepFill_MultiLine::*)(const Standard_Real, NCollection_Array1<gp_Pnt2d> &, NCollection_Array1<gp_Pnt> &) const ) &BRepFill_MultiLine::Value, "Returns the point at parameter <theU>.", py::arg("theU"), py::arg("thePnt2d"), py::arg("thePnt"));
	cls_BRepFill_MultiLine.def("D1", (Standard_Boolean (BRepFill_MultiLine::*)(const Standard_Real, NCollection_Array1<gp_Vec2d> &, NCollection_Array1<gp_Vec> &) const ) &BRepFill_MultiLine::D1, "Returns the derivative at parameter <theU>.", py::arg("theU"), py::arg("theVec2d"), py::arg("theVec"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepFill_DataMapOfShapeDataMapOfShapeListOfShape, std::unique_ptr<BRepFill_DataMapOfShapeDataMapOfShapeListOfShape, Deleter<BRepFill_DataMapOfShapeDataMapOfShapeListOfShape>>, NCollection_BaseMap> cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape(mod, "BRepFill_DataMapOfShapeDataMapOfShapeListOfShape", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def(py::init<>());
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def(py::init([] (const BRepFill_DataMapOfShapeDataMapOfShapeListOfShape &other) {return new BRepFill_DataMapOfShapeDataMapOfShapeListOfShape(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("begin", (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::iterator (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)() const ) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("end", (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::iterator (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)() const ) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("cbegin", (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::const_iterator (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)() const ) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("cend", (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::const_iterator (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)() const ) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("Exchange", (void (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(BRepFill_DataMapOfShapeDataMapOfShapeListOfShape &)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("Assign", (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape & (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const BRepFill_DataMapOfShapeDataMapOfShapeListOfShape &)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("assign", (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape & (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const BRepFill_DataMapOfShapeDataMapOfShapeListOfShape &)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("ReSize", (void (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const Standard_Integer)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::ReSize, "ReSize", py::arg("N"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("Bind", (Standard_Boolean (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const TopoDS_Shape &, const TopTools_DataMapOfShapeListOfShape &)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("Bound", (TopTools_DataMapOfShapeListOfShape * (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const TopoDS_Shape &, const TopTools_DataMapOfShapeListOfShape &)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("IsBound", (Standard_Boolean (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("UnBind", (Standard_Boolean (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("Seek", (const TopTools_DataMapOfShapeListOfShape * (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("Find", (const TopTools_DataMapOfShapeListOfShape & (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("Find", (Standard_Boolean (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const TopoDS_Shape &, TopTools_DataMapOfShapeListOfShape &) const ) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("__call__", (const TopTools_DataMapOfShapeListOfShape & (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("ChangeSeek", (TopTools_DataMapOfShapeListOfShape * (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("ChangeFind", (TopTools_DataMapOfShapeListOfShape & (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("__call__", (TopTools_DataMapOfShapeListOfShape & (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("Clear", [](BRepFill_DataMapOfShapeDataMapOfShapeListOfShape &self) -> void { return self.Clear(); });
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("Clear", (void (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const Standard_Boolean)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("Clear", (void (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("Size", (Standard_Integer (BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::*)() const ) &BRepFill_DataMapOfShapeDataMapOfShapeListOfShape::Size, "Size");
	cls_BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.def("__iter__", [](const BRepFill_DataMapOfShapeDataMapOfShapeListOfShape &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepFill_DataMapOfNodeDataMapOfShapeShape, std::unique_ptr<BRepFill_DataMapOfNodeDataMapOfShapeShape, Deleter<BRepFill_DataMapOfNodeDataMapOfShapeShape>>, NCollection_BaseMap> cls_BRepFill_DataMapOfNodeDataMapOfShapeShape(mod, "BRepFill_DataMapOfNodeDataMapOfShapeShape", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def(py::init<>());
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def(py::init([] (const BRepFill_DataMapOfNodeDataMapOfShapeShape &other) {return new BRepFill_DataMapOfNodeDataMapOfShapeShape(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("begin", (BRepFill_DataMapOfNodeDataMapOfShapeShape::iterator (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)() const ) &BRepFill_DataMapOfNodeDataMapOfShapeShape::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("end", (BRepFill_DataMapOfNodeDataMapOfShapeShape::iterator (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)() const ) &BRepFill_DataMapOfNodeDataMapOfShapeShape::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("cbegin", (BRepFill_DataMapOfNodeDataMapOfShapeShape::const_iterator (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)() const ) &BRepFill_DataMapOfNodeDataMapOfShapeShape::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("cend", (BRepFill_DataMapOfNodeDataMapOfShapeShape::const_iterator (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)() const ) &BRepFill_DataMapOfNodeDataMapOfShapeShape::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("Exchange", (void (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(BRepFill_DataMapOfNodeDataMapOfShapeShape &)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("Assign", (BRepFill_DataMapOfNodeDataMapOfShapeShape & (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const BRepFill_DataMapOfNodeDataMapOfShapeShape &)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("assign", (BRepFill_DataMapOfNodeDataMapOfShapeShape & (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const BRepFill_DataMapOfNodeDataMapOfShapeShape &)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("ReSize", (void (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const Standard_Integer)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::ReSize, "ReSize", py::arg("N"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("Bind", (Standard_Boolean (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<MAT_Node> &, const TopTools_DataMapOfShapeShape &)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("Bound", (TopTools_DataMapOfShapeShape * (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<MAT_Node> &, const TopTools_DataMapOfShapeShape &)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("IsBound", (Standard_Boolean (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<MAT_Node> &) const ) &BRepFill_DataMapOfNodeDataMapOfShapeShape::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("UnBind", (Standard_Boolean (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<MAT_Node> &)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("Seek", (const TopTools_DataMapOfShapeShape * (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<MAT_Node> &) const ) &BRepFill_DataMapOfNodeDataMapOfShapeShape::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("Find", (const TopTools_DataMapOfShapeShape & (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<MAT_Node> &) const ) &BRepFill_DataMapOfNodeDataMapOfShapeShape::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("Find", (Standard_Boolean (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<MAT_Node> &, TopTools_DataMapOfShapeShape &) const ) &BRepFill_DataMapOfNodeDataMapOfShapeShape::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("__call__", (const TopTools_DataMapOfShapeShape & (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<MAT_Node> &) const ) &BRepFill_DataMapOfNodeDataMapOfShapeShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("ChangeSeek", (TopTools_DataMapOfShapeShape * (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<MAT_Node> &)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("ChangeFind", (TopTools_DataMapOfShapeShape & (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<MAT_Node> &)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("__call__", (TopTools_DataMapOfShapeShape & (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<MAT_Node> &)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("Clear", [](BRepFill_DataMapOfNodeDataMapOfShapeShape &self) -> void { return self.Clear(); });
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("Clear", (void (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const Standard_Boolean)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("Clear", (void (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_DataMapOfNodeDataMapOfShapeShape::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("Size", (Standard_Integer (BRepFill_DataMapOfNodeDataMapOfShapeShape::*)() const ) &BRepFill_DataMapOfNodeDataMapOfShapeShape::Size, "Size");
	cls_BRepFill_DataMapOfNodeDataMapOfShapeShape.def("__iter__", [](const BRepFill_DataMapOfNodeDataMapOfShapeShape &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_DataMapOfNodeDataMapOfShapeShape.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepFill_DataMapOfNodeShape, std::unique_ptr<BRepFill_DataMapOfNodeShape, Deleter<BRepFill_DataMapOfNodeShape>>, NCollection_BaseMap> cls_BRepFill_DataMapOfNodeShape(mod, "BRepFill_DataMapOfNodeShape", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepFill_DataMapOfNodeShape.def(py::init<>());
	cls_BRepFill_DataMapOfNodeShape.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepFill_DataMapOfNodeShape.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepFill_DataMapOfNodeShape.def(py::init([] (const BRepFill_DataMapOfNodeShape &other) {return new BRepFill_DataMapOfNodeShape(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_DataMapOfNodeShape.def("begin", (BRepFill_DataMapOfNodeShape::iterator (BRepFill_DataMapOfNodeShape::*)() const ) &BRepFill_DataMapOfNodeShape::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfNodeShape.def("end", (BRepFill_DataMapOfNodeShape::iterator (BRepFill_DataMapOfNodeShape::*)() const ) &BRepFill_DataMapOfNodeShape::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfNodeShape.def("cbegin", (BRepFill_DataMapOfNodeShape::const_iterator (BRepFill_DataMapOfNodeShape::*)() const ) &BRepFill_DataMapOfNodeShape::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfNodeShape.def("cend", (BRepFill_DataMapOfNodeShape::const_iterator (BRepFill_DataMapOfNodeShape::*)() const ) &BRepFill_DataMapOfNodeShape::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfNodeShape.def("Exchange", (void (BRepFill_DataMapOfNodeShape::*)(BRepFill_DataMapOfNodeShape &)) &BRepFill_DataMapOfNodeShape::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepFill_DataMapOfNodeShape.def("Assign", (BRepFill_DataMapOfNodeShape & (BRepFill_DataMapOfNodeShape::*)(const BRepFill_DataMapOfNodeShape &)) &BRepFill_DataMapOfNodeShape::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_DataMapOfNodeShape.def("assign", (BRepFill_DataMapOfNodeShape & (BRepFill_DataMapOfNodeShape::*)(const BRepFill_DataMapOfNodeShape &)) &BRepFill_DataMapOfNodeShape::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepFill_DataMapOfNodeShape.def("ReSize", (void (BRepFill_DataMapOfNodeShape::*)(const Standard_Integer)) &BRepFill_DataMapOfNodeShape::ReSize, "ReSize", py::arg("N"));
	cls_BRepFill_DataMapOfNodeShape.def("Bind", (Standard_Boolean (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<MAT_Node> &, const TopoDS_Shape &)) &BRepFill_DataMapOfNodeShape::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepFill_DataMapOfNodeShape.def("Bound", (TopoDS_Shape * (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<MAT_Node> &, const TopoDS_Shape &)) &BRepFill_DataMapOfNodeShape::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepFill_DataMapOfNodeShape.def("IsBound", (Standard_Boolean (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<MAT_Node> &) const ) &BRepFill_DataMapOfNodeShape::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepFill_DataMapOfNodeShape.def("UnBind", (Standard_Boolean (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<MAT_Node> &)) &BRepFill_DataMapOfNodeShape::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfNodeShape.def("Seek", (const TopoDS_Shape * (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<MAT_Node> &) const ) &BRepFill_DataMapOfNodeShape::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfNodeShape.def("Find", (const TopoDS_Shape & (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<MAT_Node> &) const ) &BRepFill_DataMapOfNodeShape::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfNodeShape.def("Find", (Standard_Boolean (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<MAT_Node> &, TopoDS_Shape &) const ) &BRepFill_DataMapOfNodeShape::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepFill_DataMapOfNodeShape.def("__call__", (const TopoDS_Shape & (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<MAT_Node> &) const ) &BRepFill_DataMapOfNodeShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfNodeShape.def("ChangeSeek", (TopoDS_Shape * (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<MAT_Node> &)) &BRepFill_DataMapOfNodeShape::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepFill_DataMapOfNodeShape.def("ChangeFind", (TopoDS_Shape & (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<MAT_Node> &)) &BRepFill_DataMapOfNodeShape::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepFill_DataMapOfNodeShape.def("__call__", (TopoDS_Shape & (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<MAT_Node> &)) &BRepFill_DataMapOfNodeShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepFill_DataMapOfNodeShape.def("Clear", [](BRepFill_DataMapOfNodeShape &self) -> void { return self.Clear(); });
	cls_BRepFill_DataMapOfNodeShape.def("Clear", (void (BRepFill_DataMapOfNodeShape::*)(const Standard_Boolean)) &BRepFill_DataMapOfNodeShape::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepFill_DataMapOfNodeShape.def("Clear", (void (BRepFill_DataMapOfNodeShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_DataMapOfNodeShape::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepFill_DataMapOfNodeShape.def("Size", (Standard_Integer (BRepFill_DataMapOfNodeShape::*)() const ) &BRepFill_DataMapOfNodeShape::Size, "Size");
	cls_BRepFill_DataMapOfNodeShape.def("__iter__", [](const BRepFill_DataMapOfNodeShape &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_DataMapOfNodeShape.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepFill_DataMapOfOrientedShapeListOfShape, std::unique_ptr<BRepFill_DataMapOfOrientedShapeListOfShape, Deleter<BRepFill_DataMapOfOrientedShapeListOfShape>>, NCollection_BaseMap> cls_BRepFill_DataMapOfOrientedShapeListOfShape(mod, "BRepFill_DataMapOfOrientedShapeListOfShape", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def(py::init<>());
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def(py::init([] (const BRepFill_DataMapOfOrientedShapeListOfShape &other) {return new BRepFill_DataMapOfOrientedShapeListOfShape(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("begin", (BRepFill_DataMapOfOrientedShapeListOfShape::iterator (BRepFill_DataMapOfOrientedShapeListOfShape::*)() const ) &BRepFill_DataMapOfOrientedShapeListOfShape::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("end", (BRepFill_DataMapOfOrientedShapeListOfShape::iterator (BRepFill_DataMapOfOrientedShapeListOfShape::*)() const ) &BRepFill_DataMapOfOrientedShapeListOfShape::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("cbegin", (BRepFill_DataMapOfOrientedShapeListOfShape::const_iterator (BRepFill_DataMapOfOrientedShapeListOfShape::*)() const ) &BRepFill_DataMapOfOrientedShapeListOfShape::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("cend", (BRepFill_DataMapOfOrientedShapeListOfShape::const_iterator (BRepFill_DataMapOfOrientedShapeListOfShape::*)() const ) &BRepFill_DataMapOfOrientedShapeListOfShape::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("Exchange", (void (BRepFill_DataMapOfOrientedShapeListOfShape::*)(BRepFill_DataMapOfOrientedShapeListOfShape &)) &BRepFill_DataMapOfOrientedShapeListOfShape::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("Assign", (BRepFill_DataMapOfOrientedShapeListOfShape & (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const BRepFill_DataMapOfOrientedShapeListOfShape &)) &BRepFill_DataMapOfOrientedShapeListOfShape::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("assign", (BRepFill_DataMapOfOrientedShapeListOfShape & (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const BRepFill_DataMapOfOrientedShapeListOfShape &)) &BRepFill_DataMapOfOrientedShapeListOfShape::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("ReSize", (void (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const Standard_Integer)) &BRepFill_DataMapOfOrientedShapeListOfShape::ReSize, "ReSize", py::arg("N"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("Bind", (Standard_Boolean (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepFill_DataMapOfOrientedShapeListOfShape::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("Bound", (TopTools_ListOfShape * (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepFill_DataMapOfOrientedShapeListOfShape::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("IsBound", (Standard_Boolean (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfOrientedShapeListOfShape::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("UnBind", (Standard_Boolean (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfOrientedShapeListOfShape::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("Seek", (const TopTools_ListOfShape * (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfOrientedShapeListOfShape::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("Find", (const TopTools_ListOfShape & (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfOrientedShapeListOfShape::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("Find", (Standard_Boolean (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &, TopTools_ListOfShape &) const ) &BRepFill_DataMapOfOrientedShapeListOfShape::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("__call__", (const TopTools_ListOfShape & (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfOrientedShapeListOfShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("ChangeSeek", (TopTools_ListOfShape * (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfOrientedShapeListOfShape::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("ChangeFind", (TopTools_ListOfShape & (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfOrientedShapeListOfShape::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("__call__", (TopTools_ListOfShape & (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfOrientedShapeListOfShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("Clear", [](BRepFill_DataMapOfOrientedShapeListOfShape &self) -> void { return self.Clear(); });
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("Clear", (void (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const Standard_Boolean)) &BRepFill_DataMapOfOrientedShapeListOfShape::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("Clear", (void (BRepFill_DataMapOfOrientedShapeListOfShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_DataMapOfOrientedShapeListOfShape::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("Size", (Standard_Integer (BRepFill_DataMapOfOrientedShapeListOfShape::*)() const ) &BRepFill_DataMapOfOrientedShapeListOfShape::Size, "Size");
	cls_BRepFill_DataMapOfOrientedShapeListOfShape.def("__iter__", [](const BRepFill_DataMapOfOrientedShapeListOfShape &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_DataMapOfOrientedShapeListOfShape.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepFill_DataMapOfShapeHArray2OfShape, std::unique_ptr<BRepFill_DataMapOfShapeHArray2OfShape, Deleter<BRepFill_DataMapOfShapeHArray2OfShape>>, NCollection_BaseMap> cls_BRepFill_DataMapOfShapeHArray2OfShape(mod, "BRepFill_DataMapOfShapeHArray2OfShape", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def(py::init<>());
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def(py::init([] (const BRepFill_DataMapOfShapeHArray2OfShape &other) {return new BRepFill_DataMapOfShapeHArray2OfShape(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("begin", (BRepFill_DataMapOfShapeHArray2OfShape::iterator (BRepFill_DataMapOfShapeHArray2OfShape::*)() const ) &BRepFill_DataMapOfShapeHArray2OfShape::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("end", (BRepFill_DataMapOfShapeHArray2OfShape::iterator (BRepFill_DataMapOfShapeHArray2OfShape::*)() const ) &BRepFill_DataMapOfShapeHArray2OfShape::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("cbegin", (BRepFill_DataMapOfShapeHArray2OfShape::const_iterator (BRepFill_DataMapOfShapeHArray2OfShape::*)() const ) &BRepFill_DataMapOfShapeHArray2OfShape::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("cend", (BRepFill_DataMapOfShapeHArray2OfShape::const_iterator (BRepFill_DataMapOfShapeHArray2OfShape::*)() const ) &BRepFill_DataMapOfShapeHArray2OfShape::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("Exchange", (void (BRepFill_DataMapOfShapeHArray2OfShape::*)(BRepFill_DataMapOfShapeHArray2OfShape &)) &BRepFill_DataMapOfShapeHArray2OfShape::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("Assign", (BRepFill_DataMapOfShapeHArray2OfShape & (BRepFill_DataMapOfShapeHArray2OfShape::*)(const BRepFill_DataMapOfShapeHArray2OfShape &)) &BRepFill_DataMapOfShapeHArray2OfShape::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("assign", (BRepFill_DataMapOfShapeHArray2OfShape & (BRepFill_DataMapOfShapeHArray2OfShape::*)(const BRepFill_DataMapOfShapeHArray2OfShape &)) &BRepFill_DataMapOfShapeHArray2OfShape::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("ReSize", (void (BRepFill_DataMapOfShapeHArray2OfShape::*)(const Standard_Integer)) &BRepFill_DataMapOfShapeHArray2OfShape::ReSize, "ReSize", py::arg("N"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("Bind", (Standard_Boolean (BRepFill_DataMapOfShapeHArray2OfShape::*)(const TopoDS_Shape &, const opencascade::handle<TopTools_HArray2OfShape> &)) &BRepFill_DataMapOfShapeHArray2OfShape::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepFill_DataMapOfShapeHArray2OfShape.def("Bound", (opencascade::handle<TopTools_HArray2OfShape> * (BRepFill_DataMapOfShapeHArray2OfShape::*)(const TopoDS_Shape &, const opencascade::handle<TopTools_HArray2OfShape> &)) &BRepFill_DataMapOfShapeHArray2OfShape::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("IsBound", (Standard_Boolean (BRepFill_DataMapOfShapeHArray2OfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeHArray2OfShape::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("UnBind", (Standard_Boolean (BRepFill_DataMapOfShapeHArray2OfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeHArray2OfShape::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeHArray2OfShape.def("Seek", (const opencascade::handle<TopTools_HArray2OfShape> * (BRepFill_DataMapOfShapeHArray2OfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeHArray2OfShape::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeHArray2OfShape.def("Find", (const opencascade::handle<TopTools_HArray2OfShape> & (BRepFill_DataMapOfShapeHArray2OfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeHArray2OfShape::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeHArray2OfShape.def("Find", (Standard_Boolean (BRepFill_DataMapOfShapeHArray2OfShape::*)(const TopoDS_Shape &, opencascade::handle<TopTools_HArray2OfShape> &) const ) &BRepFill_DataMapOfShapeHArray2OfShape::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("__call__", (const opencascade::handle<TopTools_HArray2OfShape> & (BRepFill_DataMapOfShapeHArray2OfShape::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeHArray2OfShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeHArray2OfShape.def("ChangeSeek", (opencascade::handle<TopTools_HArray2OfShape> * (BRepFill_DataMapOfShapeHArray2OfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeHArray2OfShape::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("ChangeFind", (opencascade::handle<TopTools_HArray2OfShape> & (BRepFill_DataMapOfShapeHArray2OfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeHArray2OfShape::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("__call__", (opencascade::handle<TopTools_HArray2OfShape> & (BRepFill_DataMapOfShapeHArray2OfShape::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeHArray2OfShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("Clear", [](BRepFill_DataMapOfShapeHArray2OfShape &self) -> void { return self.Clear(); });
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("Clear", (void (BRepFill_DataMapOfShapeHArray2OfShape::*)(const Standard_Boolean)) &BRepFill_DataMapOfShapeHArray2OfShape::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("Clear", (void (BRepFill_DataMapOfShapeHArray2OfShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_DataMapOfShapeHArray2OfShape::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("Size", (Standard_Integer (BRepFill_DataMapOfShapeHArray2OfShape::*)() const ) &BRepFill_DataMapOfShapeHArray2OfShape::Size, "Size");
	cls_BRepFill_DataMapOfShapeHArray2OfShape.def("__iter__", [](const BRepFill_DataMapOfShapeHArray2OfShape &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_DataMapOfShapeHArray2OfShape.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepFill_DataMapOfShapeSequenceOfPnt, std::unique_ptr<BRepFill_DataMapOfShapeSequenceOfPnt, Deleter<BRepFill_DataMapOfShapeSequenceOfPnt>>, NCollection_BaseMap> cls_BRepFill_DataMapOfShapeSequenceOfPnt(mod, "BRepFill_DataMapOfShapeSequenceOfPnt", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def(py::init<>());
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def(py::init([] (const BRepFill_DataMapOfShapeSequenceOfPnt &other) {return new BRepFill_DataMapOfShapeSequenceOfPnt(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("begin", (BRepFill_DataMapOfShapeSequenceOfPnt::iterator (BRepFill_DataMapOfShapeSequenceOfPnt::*)() const ) &BRepFill_DataMapOfShapeSequenceOfPnt::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("end", (BRepFill_DataMapOfShapeSequenceOfPnt::iterator (BRepFill_DataMapOfShapeSequenceOfPnt::*)() const ) &BRepFill_DataMapOfShapeSequenceOfPnt::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("cbegin", (BRepFill_DataMapOfShapeSequenceOfPnt::const_iterator (BRepFill_DataMapOfShapeSequenceOfPnt::*)() const ) &BRepFill_DataMapOfShapeSequenceOfPnt::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("cend", (BRepFill_DataMapOfShapeSequenceOfPnt::const_iterator (BRepFill_DataMapOfShapeSequenceOfPnt::*)() const ) &BRepFill_DataMapOfShapeSequenceOfPnt::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("Exchange", (void (BRepFill_DataMapOfShapeSequenceOfPnt::*)(BRepFill_DataMapOfShapeSequenceOfPnt &)) &BRepFill_DataMapOfShapeSequenceOfPnt::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("Assign", (BRepFill_DataMapOfShapeSequenceOfPnt & (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const BRepFill_DataMapOfShapeSequenceOfPnt &)) &BRepFill_DataMapOfShapeSequenceOfPnt::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("assign", (BRepFill_DataMapOfShapeSequenceOfPnt & (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const BRepFill_DataMapOfShapeSequenceOfPnt &)) &BRepFill_DataMapOfShapeSequenceOfPnt::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("ReSize", (void (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const Standard_Integer)) &BRepFill_DataMapOfShapeSequenceOfPnt::ReSize, "ReSize", py::arg("N"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("Bind", (Standard_Boolean (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const TopoDS_Shape &, const TColgp_SequenceOfPnt &)) &BRepFill_DataMapOfShapeSequenceOfPnt::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("Bound", (TColgp_SequenceOfPnt * (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const TopoDS_Shape &, const TColgp_SequenceOfPnt &)) &BRepFill_DataMapOfShapeSequenceOfPnt::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("IsBound", (Standard_Boolean (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeSequenceOfPnt::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("UnBind", (Standard_Boolean (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeSequenceOfPnt::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("Seek", (const TColgp_SequenceOfPnt * (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeSequenceOfPnt::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("Find", (const TColgp_SequenceOfPnt & (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeSequenceOfPnt::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("Find", (Standard_Boolean (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const TopoDS_Shape &, TColgp_SequenceOfPnt &) const ) &BRepFill_DataMapOfShapeSequenceOfPnt::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("__call__", (const TColgp_SequenceOfPnt & (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeSequenceOfPnt::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("ChangeSeek", (TColgp_SequenceOfPnt * (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeSequenceOfPnt::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("ChangeFind", (TColgp_SequenceOfPnt & (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeSequenceOfPnt::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("__call__", (TColgp_SequenceOfPnt & (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeSequenceOfPnt::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("Clear", [](BRepFill_DataMapOfShapeSequenceOfPnt &self) -> void { return self.Clear(); });
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("Clear", (void (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const Standard_Boolean)) &BRepFill_DataMapOfShapeSequenceOfPnt::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("Clear", (void (BRepFill_DataMapOfShapeSequenceOfPnt::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_DataMapOfShapeSequenceOfPnt::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("Size", (Standard_Integer (BRepFill_DataMapOfShapeSequenceOfPnt::*)() const ) &BRepFill_DataMapOfShapeSequenceOfPnt::Size, "Size");
	cls_BRepFill_DataMapOfShapeSequenceOfPnt.def("__iter__", [](const BRepFill_DataMapOfShapeSequenceOfPnt &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_DataMapOfShapeSequenceOfPnt.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepFill_DataMapOfShapeSequenceOfReal, std::unique_ptr<BRepFill_DataMapOfShapeSequenceOfReal, Deleter<BRepFill_DataMapOfShapeSequenceOfReal>>, NCollection_BaseMap> cls_BRepFill_DataMapOfShapeSequenceOfReal(mod, "BRepFill_DataMapOfShapeSequenceOfReal", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def(py::init<>());
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def(py::init([] (const BRepFill_DataMapOfShapeSequenceOfReal &other) {return new BRepFill_DataMapOfShapeSequenceOfReal(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("begin", (BRepFill_DataMapOfShapeSequenceOfReal::iterator (BRepFill_DataMapOfShapeSequenceOfReal::*)() const ) &BRepFill_DataMapOfShapeSequenceOfReal::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("end", (BRepFill_DataMapOfShapeSequenceOfReal::iterator (BRepFill_DataMapOfShapeSequenceOfReal::*)() const ) &BRepFill_DataMapOfShapeSequenceOfReal::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("cbegin", (BRepFill_DataMapOfShapeSequenceOfReal::const_iterator (BRepFill_DataMapOfShapeSequenceOfReal::*)() const ) &BRepFill_DataMapOfShapeSequenceOfReal::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("cend", (BRepFill_DataMapOfShapeSequenceOfReal::const_iterator (BRepFill_DataMapOfShapeSequenceOfReal::*)() const ) &BRepFill_DataMapOfShapeSequenceOfReal::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("Exchange", (void (BRepFill_DataMapOfShapeSequenceOfReal::*)(BRepFill_DataMapOfShapeSequenceOfReal &)) &BRepFill_DataMapOfShapeSequenceOfReal::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("Assign", (BRepFill_DataMapOfShapeSequenceOfReal & (BRepFill_DataMapOfShapeSequenceOfReal::*)(const BRepFill_DataMapOfShapeSequenceOfReal &)) &BRepFill_DataMapOfShapeSequenceOfReal::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("assign", (BRepFill_DataMapOfShapeSequenceOfReal & (BRepFill_DataMapOfShapeSequenceOfReal::*)(const BRepFill_DataMapOfShapeSequenceOfReal &)) &BRepFill_DataMapOfShapeSequenceOfReal::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("ReSize", (void (BRepFill_DataMapOfShapeSequenceOfReal::*)(const Standard_Integer)) &BRepFill_DataMapOfShapeSequenceOfReal::ReSize, "ReSize", py::arg("N"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("Bind", (Standard_Boolean (BRepFill_DataMapOfShapeSequenceOfReal::*)(const TopoDS_Shape &, const TColStd_SequenceOfReal &)) &BRepFill_DataMapOfShapeSequenceOfReal::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepFill_DataMapOfShapeSequenceOfReal.def("Bound", (TColStd_SequenceOfReal * (BRepFill_DataMapOfShapeSequenceOfReal::*)(const TopoDS_Shape &, const TColStd_SequenceOfReal &)) &BRepFill_DataMapOfShapeSequenceOfReal::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("IsBound", (Standard_Boolean (BRepFill_DataMapOfShapeSequenceOfReal::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeSequenceOfReal::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("UnBind", (Standard_Boolean (BRepFill_DataMapOfShapeSequenceOfReal::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeSequenceOfReal::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeSequenceOfReal.def("Seek", (const TColStd_SequenceOfReal * (BRepFill_DataMapOfShapeSequenceOfReal::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeSequenceOfReal::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeSequenceOfReal.def("Find", (const TColStd_SequenceOfReal & (BRepFill_DataMapOfShapeSequenceOfReal::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeSequenceOfReal::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeSequenceOfReal.def("Find", (Standard_Boolean (BRepFill_DataMapOfShapeSequenceOfReal::*)(const TopoDS_Shape &, TColStd_SequenceOfReal &) const ) &BRepFill_DataMapOfShapeSequenceOfReal::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("__call__", (const TColStd_SequenceOfReal & (BRepFill_DataMapOfShapeSequenceOfReal::*)(const TopoDS_Shape &) const ) &BRepFill_DataMapOfShapeSequenceOfReal::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepFill_DataMapOfShapeSequenceOfReal.def("ChangeSeek", (TColStd_SequenceOfReal * (BRepFill_DataMapOfShapeSequenceOfReal::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeSequenceOfReal::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("ChangeFind", (TColStd_SequenceOfReal & (BRepFill_DataMapOfShapeSequenceOfReal::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeSequenceOfReal::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("__call__", (TColStd_SequenceOfReal & (BRepFill_DataMapOfShapeSequenceOfReal::*)(const TopoDS_Shape &)) &BRepFill_DataMapOfShapeSequenceOfReal::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("Clear", [](BRepFill_DataMapOfShapeSequenceOfReal &self) -> void { return self.Clear(); });
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("Clear", (void (BRepFill_DataMapOfShapeSequenceOfReal::*)(const Standard_Boolean)) &BRepFill_DataMapOfShapeSequenceOfReal::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("Clear", (void (BRepFill_DataMapOfShapeSequenceOfReal::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_DataMapOfShapeSequenceOfReal::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("Size", (Standard_Integer (BRepFill_DataMapOfShapeSequenceOfReal::*)() const ) &BRepFill_DataMapOfShapeSequenceOfReal::Size, "Size");
	cls_BRepFill_DataMapOfShapeSequenceOfReal.def("__iter__", [](const BRepFill_DataMapOfShapeSequenceOfReal &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFill_DataMapOfShapeSequenceOfReal.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<BRepFill_SequenceOfEdgeFaceAndOrder, std::unique_ptr<BRepFill_SequenceOfEdgeFaceAndOrder, Deleter<BRepFill_SequenceOfEdgeFaceAndOrder>>, NCollection_BaseSequence> cls_BRepFill_SequenceOfEdgeFaceAndOrder(mod, "BRepFill_SequenceOfEdgeFaceAndOrder", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def(py::init<>());
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def(py::init([] (const BRepFill_SequenceOfEdgeFaceAndOrder &other) {return new BRepFill_SequenceOfEdgeFaceAndOrder(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("begin", (BRepFill_SequenceOfEdgeFaceAndOrder::iterator (BRepFill_SequenceOfEdgeFaceAndOrder::*)() const ) &BRepFill_SequenceOfEdgeFaceAndOrder::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("end", (BRepFill_SequenceOfEdgeFaceAndOrder::iterator (BRepFill_SequenceOfEdgeFaceAndOrder::*)() const ) &BRepFill_SequenceOfEdgeFaceAndOrder::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("cbegin", (BRepFill_SequenceOfEdgeFaceAndOrder::const_iterator (BRepFill_SequenceOfEdgeFaceAndOrder::*)() const ) &BRepFill_SequenceOfEdgeFaceAndOrder::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("cend", (BRepFill_SequenceOfEdgeFaceAndOrder::const_iterator (BRepFill_SequenceOfEdgeFaceAndOrder::*)() const ) &BRepFill_SequenceOfEdgeFaceAndOrder::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Size", (Standard_Integer (BRepFill_SequenceOfEdgeFaceAndOrder::*)() const ) &BRepFill_SequenceOfEdgeFaceAndOrder::Size, "Number of items");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Length", (Standard_Integer (BRepFill_SequenceOfEdgeFaceAndOrder::*)() const ) &BRepFill_SequenceOfEdgeFaceAndOrder::Length, "Number of items");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Lower", (Standard_Integer (BRepFill_SequenceOfEdgeFaceAndOrder::*)() const ) &BRepFill_SequenceOfEdgeFaceAndOrder::Lower, "Method for consistency with other collections.");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Upper", (Standard_Integer (BRepFill_SequenceOfEdgeFaceAndOrder::*)() const ) &BRepFill_SequenceOfEdgeFaceAndOrder::Upper, "Method for consistency with other collections.");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("IsEmpty", (Standard_Boolean (BRepFill_SequenceOfEdgeFaceAndOrder::*)() const ) &BRepFill_SequenceOfEdgeFaceAndOrder::IsEmpty, "Empty query");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Reverse", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)()) &BRepFill_SequenceOfEdgeFaceAndOrder::Reverse, "Reverse sequence");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Exchange", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer, const Standard_Integer)) &BRepFill_SequenceOfEdgeFaceAndOrder::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_SequenceOfEdgeFaceAndOrder::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Clear", [](BRepFill_SequenceOfEdgeFaceAndOrder &self) -> void { return self.Clear(); });
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Clear", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_SequenceOfEdgeFaceAndOrder::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Assign", (BRepFill_SequenceOfEdgeFaceAndOrder & (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const BRepFill_SequenceOfEdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("assign", (BRepFill_SequenceOfEdgeFaceAndOrder & (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const BRepFill_SequenceOfEdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Remove", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(BRepFill_SequenceOfEdgeFaceAndOrder::Iterator &)) &BRepFill_SequenceOfEdgeFaceAndOrder::Remove, "Remove one item", py::arg("thePosition"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Remove", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer)) &BRepFill_SequenceOfEdgeFaceAndOrder::Remove, "Remove one item", py::arg("theIndex"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Remove", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer, const Standard_Integer)) &BRepFill_SequenceOfEdgeFaceAndOrder::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Append", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const BRepFill_EdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::Append, "Append one item", py::arg("theItem"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Append", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(BRepFill_SequenceOfEdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Prepend", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const BRepFill_EdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::Prepend, "Prepend one item", py::arg("theItem"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Prepend", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(BRepFill_SequenceOfEdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("InsertBefore", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer, const BRepFill_EdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("InsertBefore", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer, BRepFill_SequenceOfEdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("InsertAfter", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(BRepFill_SequenceOfEdgeFaceAndOrder::Iterator &, const BRepFill_EdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("InsertAfter", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer, BRepFill_SequenceOfEdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("InsertAfter", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer, const BRepFill_EdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Split", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer, BRepFill_SequenceOfEdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("First", (const BRepFill_EdgeFaceAndOrder & (BRepFill_SequenceOfEdgeFaceAndOrder::*)() const ) &BRepFill_SequenceOfEdgeFaceAndOrder::First, "First item access");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("ChangeFirst", (BRepFill_EdgeFaceAndOrder & (BRepFill_SequenceOfEdgeFaceAndOrder::*)()) &BRepFill_SequenceOfEdgeFaceAndOrder::ChangeFirst, "First item access");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Last", (const BRepFill_EdgeFaceAndOrder & (BRepFill_SequenceOfEdgeFaceAndOrder::*)() const ) &BRepFill_SequenceOfEdgeFaceAndOrder::Last, "Last item access");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("ChangeLast", (BRepFill_EdgeFaceAndOrder & (BRepFill_SequenceOfEdgeFaceAndOrder::*)()) &BRepFill_SequenceOfEdgeFaceAndOrder::ChangeLast, "Last item access");
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("Value", (const BRepFill_EdgeFaceAndOrder & (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer) const ) &BRepFill_SequenceOfEdgeFaceAndOrder::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("__call__", (const BRepFill_EdgeFaceAndOrder & (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer) const ) &BRepFill_SequenceOfEdgeFaceAndOrder::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("ChangeValue", (BRepFill_EdgeFaceAndOrder & (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer)) &BRepFill_SequenceOfEdgeFaceAndOrder::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("__call__", (BRepFill_EdgeFaceAndOrder & (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer)) &BRepFill_SequenceOfEdgeFaceAndOrder::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("SetValue", (void (BRepFill_SequenceOfEdgeFaceAndOrder::*)(const Standard_Integer, const BRepFill_EdgeFaceAndOrder &)) &BRepFill_SequenceOfEdgeFaceAndOrder::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_BRepFill_SequenceOfEdgeFaceAndOrder.def("__iter__", [](const BRepFill_SequenceOfEdgeFaceAndOrder &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<BRepFill_SequenceOfFaceAndOrder, std::unique_ptr<BRepFill_SequenceOfFaceAndOrder, Deleter<BRepFill_SequenceOfFaceAndOrder>>, NCollection_BaseSequence> cls_BRepFill_SequenceOfFaceAndOrder(mod, "BRepFill_SequenceOfFaceAndOrder", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_BRepFill_SequenceOfFaceAndOrder.def(py::init<>());
	cls_BRepFill_SequenceOfFaceAndOrder.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BRepFill_SequenceOfFaceAndOrder.def(py::init([] (const BRepFill_SequenceOfFaceAndOrder &other) {return new BRepFill_SequenceOfFaceAndOrder(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("begin", (BRepFill_SequenceOfFaceAndOrder::iterator (BRepFill_SequenceOfFaceAndOrder::*)() const ) &BRepFill_SequenceOfFaceAndOrder::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_BRepFill_SequenceOfFaceAndOrder.def("end", (BRepFill_SequenceOfFaceAndOrder::iterator (BRepFill_SequenceOfFaceAndOrder::*)() const ) &BRepFill_SequenceOfFaceAndOrder::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_BRepFill_SequenceOfFaceAndOrder.def("cbegin", (BRepFill_SequenceOfFaceAndOrder::const_iterator (BRepFill_SequenceOfFaceAndOrder::*)() const ) &BRepFill_SequenceOfFaceAndOrder::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_BRepFill_SequenceOfFaceAndOrder.def("cend", (BRepFill_SequenceOfFaceAndOrder::const_iterator (BRepFill_SequenceOfFaceAndOrder::*)() const ) &BRepFill_SequenceOfFaceAndOrder::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_BRepFill_SequenceOfFaceAndOrder.def("Size", (Standard_Integer (BRepFill_SequenceOfFaceAndOrder::*)() const ) &BRepFill_SequenceOfFaceAndOrder::Size, "Number of items");
	cls_BRepFill_SequenceOfFaceAndOrder.def("Length", (Standard_Integer (BRepFill_SequenceOfFaceAndOrder::*)() const ) &BRepFill_SequenceOfFaceAndOrder::Length, "Number of items");
	cls_BRepFill_SequenceOfFaceAndOrder.def("Lower", (Standard_Integer (BRepFill_SequenceOfFaceAndOrder::*)() const ) &BRepFill_SequenceOfFaceAndOrder::Lower, "Method for consistency with other collections.");
	cls_BRepFill_SequenceOfFaceAndOrder.def("Upper", (Standard_Integer (BRepFill_SequenceOfFaceAndOrder::*)() const ) &BRepFill_SequenceOfFaceAndOrder::Upper, "Method for consistency with other collections.");
	cls_BRepFill_SequenceOfFaceAndOrder.def("IsEmpty", (Standard_Boolean (BRepFill_SequenceOfFaceAndOrder::*)() const ) &BRepFill_SequenceOfFaceAndOrder::IsEmpty, "Empty query");
	cls_BRepFill_SequenceOfFaceAndOrder.def("Reverse", (void (BRepFill_SequenceOfFaceAndOrder::*)()) &BRepFill_SequenceOfFaceAndOrder::Reverse, "Reverse sequence");
	cls_BRepFill_SequenceOfFaceAndOrder.def("Exchange", (void (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer, const Standard_Integer)) &BRepFill_SequenceOfFaceAndOrder::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_BRepFill_SequenceOfFaceAndOrder.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_SequenceOfFaceAndOrder::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("Clear", [](BRepFill_SequenceOfFaceAndOrder &self) -> void { return self.Clear(); });
	cls_BRepFill_SequenceOfFaceAndOrder.def("Clear", (void (BRepFill_SequenceOfFaceAndOrder::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_SequenceOfFaceAndOrder::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("Assign", (BRepFill_SequenceOfFaceAndOrder & (BRepFill_SequenceOfFaceAndOrder::*)(const BRepFill_SequenceOfFaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("assign", (BRepFill_SequenceOfFaceAndOrder & (BRepFill_SequenceOfFaceAndOrder::*)(const BRepFill_SequenceOfFaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("Remove", (void (BRepFill_SequenceOfFaceAndOrder::*)(BRepFill_SequenceOfFaceAndOrder::Iterator &)) &BRepFill_SequenceOfFaceAndOrder::Remove, "Remove one item", py::arg("thePosition"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("Remove", (void (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer)) &BRepFill_SequenceOfFaceAndOrder::Remove, "Remove one item", py::arg("theIndex"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("Remove", (void (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer, const Standard_Integer)) &BRepFill_SequenceOfFaceAndOrder::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("Append", (void (BRepFill_SequenceOfFaceAndOrder::*)(const BRepFill_FaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::Append, "Append one item", py::arg("theItem"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("Append", (void (BRepFill_SequenceOfFaceAndOrder::*)(BRepFill_SequenceOfFaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("Prepend", (void (BRepFill_SequenceOfFaceAndOrder::*)(const BRepFill_FaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::Prepend, "Prepend one item", py::arg("theItem"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("Prepend", (void (BRepFill_SequenceOfFaceAndOrder::*)(BRepFill_SequenceOfFaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("InsertBefore", (void (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer, const BRepFill_FaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("InsertBefore", (void (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer, BRepFill_SequenceOfFaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("InsertAfter", (void (BRepFill_SequenceOfFaceAndOrder::*)(BRepFill_SequenceOfFaceAndOrder::Iterator &, const BRepFill_FaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("InsertAfter", (void (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer, BRepFill_SequenceOfFaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("InsertAfter", (void (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer, const BRepFill_FaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("Split", (void (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer, BRepFill_SequenceOfFaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("First", (const BRepFill_FaceAndOrder & (BRepFill_SequenceOfFaceAndOrder::*)() const ) &BRepFill_SequenceOfFaceAndOrder::First, "First item access");
	cls_BRepFill_SequenceOfFaceAndOrder.def("ChangeFirst", (BRepFill_FaceAndOrder & (BRepFill_SequenceOfFaceAndOrder::*)()) &BRepFill_SequenceOfFaceAndOrder::ChangeFirst, "First item access");
	cls_BRepFill_SequenceOfFaceAndOrder.def("Last", (const BRepFill_FaceAndOrder & (BRepFill_SequenceOfFaceAndOrder::*)() const ) &BRepFill_SequenceOfFaceAndOrder::Last, "Last item access");
	cls_BRepFill_SequenceOfFaceAndOrder.def("ChangeLast", (BRepFill_FaceAndOrder & (BRepFill_SequenceOfFaceAndOrder::*)()) &BRepFill_SequenceOfFaceAndOrder::ChangeLast, "Last item access");
	cls_BRepFill_SequenceOfFaceAndOrder.def("Value", (const BRepFill_FaceAndOrder & (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer) const ) &BRepFill_SequenceOfFaceAndOrder::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("__call__", (const BRepFill_FaceAndOrder & (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer) const ) &BRepFill_SequenceOfFaceAndOrder::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("ChangeValue", (BRepFill_FaceAndOrder & (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer)) &BRepFill_SequenceOfFaceAndOrder::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("__call__", (BRepFill_FaceAndOrder & (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer)) &BRepFill_SequenceOfFaceAndOrder::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("SetValue", (void (BRepFill_SequenceOfFaceAndOrder::*)(const Standard_Integer, const BRepFill_FaceAndOrder &)) &BRepFill_SequenceOfFaceAndOrder::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_BRepFill_SequenceOfFaceAndOrder.def("__iter__", [](const BRepFill_SequenceOfFaceAndOrder &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<BRepFill_IndexedDataMapOfOrientedShapeListOfShape, std::unique_ptr<BRepFill_IndexedDataMapOfOrientedShapeListOfShape, Deleter<BRepFill_IndexedDataMapOfOrientedShapeListOfShape>>, NCollection_BaseMap> cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape(mod, "BRepFill_IndexedDataMapOfOrientedShapeListOfShape", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def(py::init<>());
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def(py::init([] (const BRepFill_IndexedDataMapOfOrientedShapeListOfShape &other) {return new BRepFill_IndexedDataMapOfOrientedShapeListOfShape(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("begin", (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::iterator (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)() const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("end", (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::iterator (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)() const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("cbegin", (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::const_iterator (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)() const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("cend", (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::const_iterator (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)() const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("Exchange", (void (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(BRepFill_IndexedDataMapOfOrientedShapeListOfShape &)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("Assign", (BRepFill_IndexedDataMapOfOrientedShapeListOfShape & (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const BRepFill_IndexedDataMapOfOrientedShapeListOfShape &)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("assign", (BRepFill_IndexedDataMapOfOrientedShapeListOfShape & (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const BRepFill_IndexedDataMapOfOrientedShapeListOfShape &)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("ReSize", (void (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const Standard_Integer)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::ReSize, "ReSize", py::arg("N"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("Add", (Standard_Integer (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("Contains", (Standard_Boolean (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::Contains, "Contains", py::arg("theKey1"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("Substitute", (void (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const Standard_Integer, const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("Swap", (void (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const Standard_Integer, const Standard_Integer)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("RemoveLast", (void (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)()) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::RemoveLast, "RemoveLast");
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("RemoveFromIndex", (void (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const Standard_Integer)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("RemoveKey", (void (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("FindKey", (const TopoDS_Shape & (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const Standard_Integer) const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::FindKey, "FindKey", py::arg("theKey2"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("FindFromIndex", (const TopTools_ListOfShape & (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const Standard_Integer) const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("__call__", (const TopTools_ListOfShape & (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const Standard_Integer) const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("ChangeFromIndex", (TopTools_ListOfShape & (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const Standard_Integer)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("__call__", (TopTools_ListOfShape & (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const Standard_Integer)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("FindIndex", (Standard_Integer (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("FindFromKey", (const TopTools_ListOfShape & (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("ChangeFromKey", (TopTools_ListOfShape & (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("Seek", (const TopTools_ListOfShape * (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &) const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("ChangeSeek", (TopTools_ListOfShape * (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("FindFromKey", (Standard_Boolean (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const TopoDS_Shape &, TopTools_ListOfShape &) const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("Clear", [](BRepFill_IndexedDataMapOfOrientedShapeListOfShape &self) -> void { return self.Clear(); });
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("Clear", (void (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const Standard_Boolean)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("Clear", (void (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("Size", (Standard_Integer (BRepFill_IndexedDataMapOfOrientedShapeListOfShape::*)() const ) &BRepFill_IndexedDataMapOfOrientedShapeListOfShape::Size, "Size");
	cls_BRepFill_IndexedDataMapOfOrientedShapeListOfShape.def("__iter__", [](const BRepFill_IndexedDataMapOfOrientedShapeListOfShape &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<BRepFill_ListOfOffsetWire, std::unique_ptr<BRepFill_ListOfOffsetWire, Deleter<BRepFill_ListOfOffsetWire>>, NCollection_BaseList> cls_BRepFill_ListOfOffsetWire(mod, "BRepFill_ListOfOffsetWire", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_BRepFill_ListOfOffsetWire.def(py::init<>());
	cls_BRepFill_ListOfOffsetWire.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BRepFill_ListOfOffsetWire.def(py::init([] (const BRepFill_ListOfOffsetWire &other) {return new BRepFill_ListOfOffsetWire(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_ListOfOffsetWire.def("begin", (BRepFill_ListOfOffsetWire::iterator (BRepFill_ListOfOffsetWire::*)() const ) &BRepFill_ListOfOffsetWire::begin, "Returns an iterator pointing to the first element in the list.");
	cls_BRepFill_ListOfOffsetWire.def("end", (BRepFill_ListOfOffsetWire::iterator (BRepFill_ListOfOffsetWire::*)() const ) &BRepFill_ListOfOffsetWire::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_BRepFill_ListOfOffsetWire.def("cbegin", (BRepFill_ListOfOffsetWire::const_iterator (BRepFill_ListOfOffsetWire::*)() const ) &BRepFill_ListOfOffsetWire::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_BRepFill_ListOfOffsetWire.def("cend", (BRepFill_ListOfOffsetWire::const_iterator (BRepFill_ListOfOffsetWire::*)() const ) &BRepFill_ListOfOffsetWire::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_BRepFill_ListOfOffsetWire.def("Size", (Standard_Integer (BRepFill_ListOfOffsetWire::*)() const ) &BRepFill_ListOfOffsetWire::Size, "Size - Number of items");
	cls_BRepFill_ListOfOffsetWire.def("Assign", (BRepFill_ListOfOffsetWire & (BRepFill_ListOfOffsetWire::*)(const BRepFill_ListOfOffsetWire &)) &BRepFill_ListOfOffsetWire::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_ListOfOffsetWire.def("assign", (BRepFill_ListOfOffsetWire & (BRepFill_ListOfOffsetWire::*)(const BRepFill_ListOfOffsetWire &)) &BRepFill_ListOfOffsetWire::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BRepFill_ListOfOffsetWire.def("Clear", [](BRepFill_ListOfOffsetWire &self) -> void { return self.Clear(); });
	cls_BRepFill_ListOfOffsetWire.def("Clear", (void (BRepFill_ListOfOffsetWire::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_ListOfOffsetWire::Clear, "Clear this list", py::arg("theAllocator"));
	cls_BRepFill_ListOfOffsetWire.def("First", (const BRepFill_OffsetWire & (BRepFill_ListOfOffsetWire::*)() const ) &BRepFill_ListOfOffsetWire::First, "First item");
	cls_BRepFill_ListOfOffsetWire.def("First", (BRepFill_OffsetWire & (BRepFill_ListOfOffsetWire::*)()) &BRepFill_ListOfOffsetWire::First, "First item (non-const)");
	cls_BRepFill_ListOfOffsetWire.def("Last", (const BRepFill_OffsetWire & (BRepFill_ListOfOffsetWire::*)() const ) &BRepFill_ListOfOffsetWire::Last, "Last item");
	cls_BRepFill_ListOfOffsetWire.def("Last", (BRepFill_OffsetWire & (BRepFill_ListOfOffsetWire::*)()) &BRepFill_ListOfOffsetWire::Last, "Last item (non-const)");
	cls_BRepFill_ListOfOffsetWire.def("Append", (BRepFill_OffsetWire & (BRepFill_ListOfOffsetWire::*)(const BRepFill_OffsetWire &)) &BRepFill_ListOfOffsetWire::Append, "Append one item at the end", py::arg("theItem"));
	cls_BRepFill_ListOfOffsetWire.def("Append", (void (BRepFill_ListOfOffsetWire::*)(const BRepFill_OffsetWire &, BRepFill_ListOfOffsetWire::Iterator &)) &BRepFill_ListOfOffsetWire::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_BRepFill_ListOfOffsetWire.def("Append", (void (BRepFill_ListOfOffsetWire::*)(BRepFill_ListOfOffsetWire &)) &BRepFill_ListOfOffsetWire::Append, "Append another list at the end", py::arg("theOther"));
	cls_BRepFill_ListOfOffsetWire.def("Prepend", (BRepFill_OffsetWire & (BRepFill_ListOfOffsetWire::*)(const BRepFill_OffsetWire &)) &BRepFill_ListOfOffsetWire::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_BRepFill_ListOfOffsetWire.def("Prepend", (void (BRepFill_ListOfOffsetWire::*)(BRepFill_ListOfOffsetWire &)) &BRepFill_ListOfOffsetWire::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_BRepFill_ListOfOffsetWire.def("RemoveFirst", (void (BRepFill_ListOfOffsetWire::*)()) &BRepFill_ListOfOffsetWire::RemoveFirst, "RemoveFirst item");
	cls_BRepFill_ListOfOffsetWire.def("Remove", (void (BRepFill_ListOfOffsetWire::*)(BRepFill_ListOfOffsetWire::Iterator &)) &BRepFill_ListOfOffsetWire::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_BRepFill_ListOfOffsetWire.def("InsertBefore", (BRepFill_OffsetWire & (BRepFill_ListOfOffsetWire::*)(const BRepFill_OffsetWire &, BRepFill_ListOfOffsetWire::Iterator &)) &BRepFill_ListOfOffsetWire::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_BRepFill_ListOfOffsetWire.def("InsertBefore", (void (BRepFill_ListOfOffsetWire::*)(BRepFill_ListOfOffsetWire &, BRepFill_ListOfOffsetWire::Iterator &)) &BRepFill_ListOfOffsetWire::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_BRepFill_ListOfOffsetWire.def("InsertAfter", (BRepFill_OffsetWire & (BRepFill_ListOfOffsetWire::*)(const BRepFill_OffsetWire &, BRepFill_ListOfOffsetWire::Iterator &)) &BRepFill_ListOfOffsetWire::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_BRepFill_ListOfOffsetWire.def("InsertAfter", (void (BRepFill_ListOfOffsetWire::*)(BRepFill_ListOfOffsetWire &, BRepFill_ListOfOffsetWire::Iterator &)) &BRepFill_ListOfOffsetWire::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_BRepFill_ListOfOffsetWire.def("Reverse", (void (BRepFill_ListOfOffsetWire::*)()) &BRepFill_ListOfOffsetWire::Reverse, "Reverse the list");
	cls_BRepFill_ListOfOffsetWire.def("__iter__", [](const BRepFill_ListOfOffsetWire &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<BRepFill_ListIteratorOfListOfOffsetWire, std::unique_ptr<BRepFill_ListIteratorOfListOfOffsetWire, Deleter<BRepFill_ListIteratorOfListOfOffsetWire>>> cls_BRepFill_ListIteratorOfListOfOffsetWire(mod, "BRepFill_ListIteratorOfListOfOffsetWire", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_BRepFill_ListIteratorOfListOfOffsetWire.def(py::init<>());
	cls_BRepFill_ListIteratorOfListOfOffsetWire.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_BRepFill_ListIteratorOfListOfOffsetWire.def("More", (Standard_Boolean (BRepFill_ListIteratorOfListOfOffsetWire::*)() const ) &BRepFill_ListIteratorOfListOfOffsetWire::More, "Check end");
	cls_BRepFill_ListIteratorOfListOfOffsetWire.def("Next", (void (BRepFill_ListIteratorOfListOfOffsetWire::*)()) &BRepFill_ListIteratorOfListOfOffsetWire::Next, "Make step");
	cls_BRepFill_ListIteratorOfListOfOffsetWire.def("Value", (const BRepFill_OffsetWire & (BRepFill_ListIteratorOfListOfOffsetWire::*)() const ) &BRepFill_ListIteratorOfListOfOffsetWire::Value, "Constant Value access");
	cls_BRepFill_ListIteratorOfListOfOffsetWire.def("Value", (BRepFill_OffsetWire & (BRepFill_ListIteratorOfListOfOffsetWire::*)()) &BRepFill_ListIteratorOfListOfOffsetWire::Value, "Non-const Value access");
	cls_BRepFill_ListIteratorOfListOfOffsetWire.def("ChangeValue", (BRepFill_OffsetWire & (BRepFill_ListIteratorOfListOfOffsetWire::*)() const ) &BRepFill_ListIteratorOfListOfOffsetWire::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<BRepFill_SequenceOfSection, std::unique_ptr<BRepFill_SequenceOfSection, Deleter<BRepFill_SequenceOfSection>>, NCollection_BaseSequence> cls_BRepFill_SequenceOfSection(mod, "BRepFill_SequenceOfSection", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_BRepFill_SequenceOfSection.def(py::init<>());
	cls_BRepFill_SequenceOfSection.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BRepFill_SequenceOfSection.def(py::init([] (const BRepFill_SequenceOfSection &other) {return new BRepFill_SequenceOfSection(other);}), "Copy constructor", py::arg("other"));
	cls_BRepFill_SequenceOfSection.def("begin", (BRepFill_SequenceOfSection::iterator (BRepFill_SequenceOfSection::*)() const ) &BRepFill_SequenceOfSection::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_BRepFill_SequenceOfSection.def("end", (BRepFill_SequenceOfSection::iterator (BRepFill_SequenceOfSection::*)() const ) &BRepFill_SequenceOfSection::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_BRepFill_SequenceOfSection.def("cbegin", (BRepFill_SequenceOfSection::const_iterator (BRepFill_SequenceOfSection::*)() const ) &BRepFill_SequenceOfSection::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_BRepFill_SequenceOfSection.def("cend", (BRepFill_SequenceOfSection::const_iterator (BRepFill_SequenceOfSection::*)() const ) &BRepFill_SequenceOfSection::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_BRepFill_SequenceOfSection.def("Size", (Standard_Integer (BRepFill_SequenceOfSection::*)() const ) &BRepFill_SequenceOfSection::Size, "Number of items");
	cls_BRepFill_SequenceOfSection.def("Length", (Standard_Integer (BRepFill_SequenceOfSection::*)() const ) &BRepFill_SequenceOfSection::Length, "Number of items");
	cls_BRepFill_SequenceOfSection.def("Lower", (Standard_Integer (BRepFill_SequenceOfSection::*)() const ) &BRepFill_SequenceOfSection::Lower, "Method for consistency with other collections.");
	cls_BRepFill_SequenceOfSection.def("Upper", (Standard_Integer (BRepFill_SequenceOfSection::*)() const ) &BRepFill_SequenceOfSection::Upper, "Method for consistency with other collections.");
	cls_BRepFill_SequenceOfSection.def("IsEmpty", (Standard_Boolean (BRepFill_SequenceOfSection::*)() const ) &BRepFill_SequenceOfSection::IsEmpty, "Empty query");
	cls_BRepFill_SequenceOfSection.def("Reverse", (void (BRepFill_SequenceOfSection::*)()) &BRepFill_SequenceOfSection::Reverse, "Reverse sequence");
	cls_BRepFill_SequenceOfSection.def("Exchange", (void (BRepFill_SequenceOfSection::*)(const Standard_Integer, const Standard_Integer)) &BRepFill_SequenceOfSection::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_BRepFill_SequenceOfSection.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_SequenceOfSection::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_BRepFill_SequenceOfSection.def("Clear", [](BRepFill_SequenceOfSection &self) -> void { return self.Clear(); });
	cls_BRepFill_SequenceOfSection.def("Clear", (void (BRepFill_SequenceOfSection::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepFill_SequenceOfSection::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_BRepFill_SequenceOfSection.def("Assign", (BRepFill_SequenceOfSection & (BRepFill_SequenceOfSection::*)(const BRepFill_SequenceOfSection &)) &BRepFill_SequenceOfSection::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepFill_SequenceOfSection.def("assign", (BRepFill_SequenceOfSection & (BRepFill_SequenceOfSection::*)(const BRepFill_SequenceOfSection &)) &BRepFill_SequenceOfSection::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BRepFill_SequenceOfSection.def("Remove", (void (BRepFill_SequenceOfSection::*)(BRepFill_SequenceOfSection::Iterator &)) &BRepFill_SequenceOfSection::Remove, "Remove one item", py::arg("thePosition"));
	cls_BRepFill_SequenceOfSection.def("Remove", (void (BRepFill_SequenceOfSection::*)(const Standard_Integer)) &BRepFill_SequenceOfSection::Remove, "Remove one item", py::arg("theIndex"));
	cls_BRepFill_SequenceOfSection.def("Remove", (void (BRepFill_SequenceOfSection::*)(const Standard_Integer, const Standard_Integer)) &BRepFill_SequenceOfSection::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_BRepFill_SequenceOfSection.def("Append", (void (BRepFill_SequenceOfSection::*)(const BRepFill_Section &)) &BRepFill_SequenceOfSection::Append, "Append one item", py::arg("theItem"));
	cls_BRepFill_SequenceOfSection.def("Append", (void (BRepFill_SequenceOfSection::*)(BRepFill_SequenceOfSection &)) &BRepFill_SequenceOfSection::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_BRepFill_SequenceOfSection.def("Prepend", (void (BRepFill_SequenceOfSection::*)(const BRepFill_Section &)) &BRepFill_SequenceOfSection::Prepend, "Prepend one item", py::arg("theItem"));
	cls_BRepFill_SequenceOfSection.def("Prepend", (void (BRepFill_SequenceOfSection::*)(BRepFill_SequenceOfSection &)) &BRepFill_SequenceOfSection::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_BRepFill_SequenceOfSection.def("InsertBefore", (void (BRepFill_SequenceOfSection::*)(const Standard_Integer, const BRepFill_Section &)) &BRepFill_SequenceOfSection::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_BRepFill_SequenceOfSection.def("InsertBefore", (void (BRepFill_SequenceOfSection::*)(const Standard_Integer, BRepFill_SequenceOfSection &)) &BRepFill_SequenceOfSection::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_BRepFill_SequenceOfSection.def("InsertAfter", (void (BRepFill_SequenceOfSection::*)(BRepFill_SequenceOfSection::Iterator &, const BRepFill_Section &)) &BRepFill_SequenceOfSection::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_BRepFill_SequenceOfSection.def("InsertAfter", (void (BRepFill_SequenceOfSection::*)(const Standard_Integer, BRepFill_SequenceOfSection &)) &BRepFill_SequenceOfSection::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_BRepFill_SequenceOfSection.def("InsertAfter", (void (BRepFill_SequenceOfSection::*)(const Standard_Integer, const BRepFill_Section &)) &BRepFill_SequenceOfSection::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_BRepFill_SequenceOfSection.def("Split", (void (BRepFill_SequenceOfSection::*)(const Standard_Integer, BRepFill_SequenceOfSection &)) &BRepFill_SequenceOfSection::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_BRepFill_SequenceOfSection.def("First", (const BRepFill_Section & (BRepFill_SequenceOfSection::*)() const ) &BRepFill_SequenceOfSection::First, "First item access");
	cls_BRepFill_SequenceOfSection.def("ChangeFirst", (BRepFill_Section & (BRepFill_SequenceOfSection::*)()) &BRepFill_SequenceOfSection::ChangeFirst, "First item access");
	cls_BRepFill_SequenceOfSection.def("Last", (const BRepFill_Section & (BRepFill_SequenceOfSection::*)() const ) &BRepFill_SequenceOfSection::Last, "Last item access");
	cls_BRepFill_SequenceOfSection.def("ChangeLast", (BRepFill_Section & (BRepFill_SequenceOfSection::*)()) &BRepFill_SequenceOfSection::ChangeLast, "Last item access");
	cls_BRepFill_SequenceOfSection.def("Value", (const BRepFill_Section & (BRepFill_SequenceOfSection::*)(const Standard_Integer) const ) &BRepFill_SequenceOfSection::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_BRepFill_SequenceOfSection.def("__call__", (const BRepFill_Section & (BRepFill_SequenceOfSection::*)(const Standard_Integer) const ) &BRepFill_SequenceOfSection::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_BRepFill_SequenceOfSection.def("ChangeValue", (BRepFill_Section & (BRepFill_SequenceOfSection::*)(const Standard_Integer)) &BRepFill_SequenceOfSection::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_BRepFill_SequenceOfSection.def("__call__", (BRepFill_Section & (BRepFill_SequenceOfSection::*)(const Standard_Integer)) &BRepFill_SequenceOfSection::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_BRepFill_SequenceOfSection.def("SetValue", (void (BRepFill_SequenceOfSection::*)(const Standard_Integer, const BRepFill_Section &)) &BRepFill_SequenceOfSection::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_BRepFill_SequenceOfSection.def("__iter__", [](const BRepFill_SequenceOfSection &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
