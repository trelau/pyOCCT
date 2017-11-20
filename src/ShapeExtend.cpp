#include <pyOCCT_Common.hpp>

#include <ShapeExtend_Status.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Message_Msg.hxx>
#include <Message_Gravity.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Type.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <TopoDS_Wire.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeExtend_WireData.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <Geom_Curve.hxx>
#include <gp_Trsf.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Geom_Geometry.hxx>
#include <ShapeExtend_ComplexCurve.hxx>
#include <Geom_Surface.hxx>
#include <TColGeom_HArray2OfSurface.hxx>
#include <ShapeExtend_Parametrisation.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Trsf2d.hxx>
#include <ShapeExtend_CompositeSurface.hxx>
#include <ShapeExtend_DataMapOfTransientListOfMsg.hxx>
#include <ShapeExtend_DataMapOfShapeListOfMsg.hxx>
#include <ShapeExtend_MsgRegistrator.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <ShapeExtend_Explorer.hxx>
#include <ShapeExtend.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(ShapeExtend, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Message");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColGeom");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeExtend_Status.hxx
	py::enum_<ShapeExtend_Status>(mod, "ShapeExtend_Status", "This enumeration is used in ShapeHealing toolkit for representing flags in the return statuses of class methods. The status is a field of the class which is set by one or several methods of that class. It is used for reporting about errors and other situations encountered during execution of the method. There are defined 8 values for DONE and 8 for FAIL flags: ShapeExtend_DONE1 ... ShapeExtend_DONE8, ShapeExtend_FAIL1 ... ShapeExtend_FAIL8 and also enumerations for representing combinations of flags: ShapeExtend_OK - no flags at all, ShapeExtend_DONE - any of flags DONEi, ShapeExtend_FAIL - any of flags FAILi. The class that uses statuses provides a method(s) which answers whether the flag corresponding to a given enumerative value is (are) set: Standard_Boolean Status(const ShapeExtend_Status test); Note that status can have several flags set simultaneously. Status(ShapeExtend_OK) gives True when no flags are set. Nothing done, everything OK Something was done, case 1 Something was done, case 2 Something was done, case 3 Something was done, case 4 Something was done, case 5 Something was done, case 6 Something was done, case 7 Something was done, case 8 Something was done (any of DONE#) The method failed, case 1 The method failed, case 2 The method failed, case 3 The method failed, case 4 The method failed, case 5 The method failed, case 6 The method failed, case 7 The method failed, case 8 The mathod failed (any of FAIL# occured)")
		.value("ShapeExtend_OK", ShapeExtend_Status::ShapeExtend_OK)
		.value("ShapeExtend_DONE1", ShapeExtend_Status::ShapeExtend_DONE1)
		.value("ShapeExtend_DONE2", ShapeExtend_Status::ShapeExtend_DONE2)
		.value("ShapeExtend_DONE3", ShapeExtend_Status::ShapeExtend_DONE3)
		.value("ShapeExtend_DONE4", ShapeExtend_Status::ShapeExtend_DONE4)
		.value("ShapeExtend_DONE5", ShapeExtend_Status::ShapeExtend_DONE5)
		.value("ShapeExtend_DONE6", ShapeExtend_Status::ShapeExtend_DONE6)
		.value("ShapeExtend_DONE7", ShapeExtend_Status::ShapeExtend_DONE7)
		.value("ShapeExtend_DONE8", ShapeExtend_Status::ShapeExtend_DONE8)
		.value("ShapeExtend_DONE", ShapeExtend_Status::ShapeExtend_DONE)
		.value("ShapeExtend_FAIL1", ShapeExtend_Status::ShapeExtend_FAIL1)
		.value("ShapeExtend_FAIL2", ShapeExtend_Status::ShapeExtend_FAIL2)
		.value("ShapeExtend_FAIL3", ShapeExtend_Status::ShapeExtend_FAIL3)
		.value("ShapeExtend_FAIL4", ShapeExtend_Status::ShapeExtend_FAIL4)
		.value("ShapeExtend_FAIL5", ShapeExtend_Status::ShapeExtend_FAIL5)
		.value("ShapeExtend_FAIL6", ShapeExtend_Status::ShapeExtend_FAIL6)
		.value("ShapeExtend_FAIL7", ShapeExtend_Status::ShapeExtend_FAIL7)
		.value("ShapeExtend_FAIL8", ShapeExtend_Status::ShapeExtend_FAIL8)
		.value("ShapeExtend_FAIL", ShapeExtend_Status::ShapeExtend_FAIL)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeExtend_Parametrisation.hxx
	py::enum_<ShapeExtend_Parametrisation>(mod, "ShapeExtend_Parametrisation", "Defines kind of global parametrisation on the composite surface each patch of the 1st row and column adds its range, Ui+1 = Ui + URange(i,1), etc. each patch gives range 1.: Ui = i-1, Vj = j-1 uniform parametrisation with global range [0,1]")
		.value("ShapeExtend_Natural", ShapeExtend_Parametrisation::ShapeExtend_Natural)
		.value("ShapeExtend_Uniform", ShapeExtend_Parametrisation::ShapeExtend_Uniform)
		.value("ShapeExtend_Unitary", ShapeExtend_Parametrisation::ShapeExtend_Unitary)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeExtend_BasicMsgRegistrator.hxx
	py::class_<ShapeExtend_BasicMsgRegistrator, opencascade::handle<ShapeExtend_BasicMsgRegistrator>, Standard_Transient> cls_ShapeExtend_BasicMsgRegistrator(mod, "ShapeExtend_BasicMsgRegistrator", "Abstract class that can be used for attaching messages to the objects (e.g. shapes). It is used by ShapeHealing algorithms to attach a message describing encountered case (e.g. removing small edge from a wire).");
	cls_ShapeExtend_BasicMsgRegistrator.def(py::init<>());
	cls_ShapeExtend_BasicMsgRegistrator.def("Send", (void (ShapeExtend_BasicMsgRegistrator::*)(const opencascade::handle<Standard_Transient> &, const Message_Msg &, const Message_Gravity)) &ShapeExtend_BasicMsgRegistrator::Send, "Sends a message to be attached to the object. Object can be of any type interpreted by redefined MsgRegistrator.", py::arg("object"), py::arg("message"), py::arg("gravity"));
	cls_ShapeExtend_BasicMsgRegistrator.def("Send", (void (ShapeExtend_BasicMsgRegistrator::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity)) &ShapeExtend_BasicMsgRegistrator::Send, "Sends a message to be attached to the shape.", py::arg("shape"), py::arg("message"), py::arg("gravity"));
	cls_ShapeExtend_BasicMsgRegistrator.def("Send", (void (ShapeExtend_BasicMsgRegistrator::*)(const Message_Msg &, const Message_Gravity)) &ShapeExtend_BasicMsgRegistrator::Send, "Calls Send method with Null Transient.", py::arg("message"), py::arg("gravity"));
	cls_ShapeExtend_BasicMsgRegistrator.def_static("get_type_name_", (const char * (*)()) &ShapeExtend_BasicMsgRegistrator::get_type_name, "None");
	cls_ShapeExtend_BasicMsgRegistrator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeExtend_BasicMsgRegistrator::get_type_descriptor, "None");
	cls_ShapeExtend_BasicMsgRegistrator.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeExtend_BasicMsgRegistrator::*)() const ) &ShapeExtend_BasicMsgRegistrator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeExtend_WireData.hxx
	py::class_<ShapeExtend_WireData, opencascade::handle<ShapeExtend_WireData>, Standard_Transient> cls_ShapeExtend_WireData(mod, "ShapeExtend_WireData", "This class provides a data structure necessary for work with the wire as with ordered list of edges, what is required for many algorithms. The advantage of this class is that it allows to work with wires which are not correct. The object of the class ShapeExtend_WireData can be initialized by TopoDS_Wire, and converted back to TopoDS_Wire. An edge in the wire is defined by its rank number. Operations of accessing, adding and removing edge at the given rank number are provided. On the whole wire, operations of circular permutation and reversing (both orientations of all edges and order of edges) are provided as well. This class also provides a method to check if the edge in the wire is a seam (if the wire lies on a face). This class is handled by reference. Such an approach gives the following advantages: 1. Sharing the object of this class strongly optimizes the processes of analysis and fixing performed in parallel on the wire stored in the form of this class. Fixing tool (e.g. ShapeFix_Wire) fixes problems one by one using analyzing tool (e.g. ShapeAnalysis_Wire). Sharing allows not to reinitialize each time the analyzing tool with modified ShapeExtend_WireData what consumes certain time. 2. No copying of contents. The object of ShapeExtend_WireData class has quite big size, returning it as a result of the function would cause additional copying of contents if this class were one handled by value. Moreover, this class is stored as a field in other classes which are they returned as results of functions, storing only a handle to ShapeExtend_WireData saves time and memory.");
	cls_ShapeExtend_WireData.def(py::init<>());
	cls_ShapeExtend_WireData.def(py::init<const TopoDS_Wire &>(), py::arg("wire"));
	cls_ShapeExtend_WireData.def(py::init<const TopoDS_Wire &, const Standard_Boolean>(), py::arg("wire"), py::arg("chained"));
	cls_ShapeExtend_WireData.def(py::init<const TopoDS_Wire &, const Standard_Boolean, const Standard_Boolean>(), py::arg("wire"), py::arg("chained"), py::arg("theManifoldMode"));
	cls_ShapeExtend_WireData.def("Init", (void (ShapeExtend_WireData::*)(const opencascade::handle<ShapeExtend_WireData> &)) &ShapeExtend_WireData::Init, "Copies data from another WireData", py::arg("other"));
	cls_ShapeExtend_WireData.def("Init", [](ShapeExtend_WireData &self, const TopoDS_Wire & a0) -> Standard_Boolean { return self.Init(a0); }, py::arg("wire"));
	cls_ShapeExtend_WireData.def("Init", [](ShapeExtend_WireData &self, const TopoDS_Wire & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.Init(a0, a1); }, py::arg("wire"), py::arg("chained"));
	cls_ShapeExtend_WireData.def("Init", (Standard_Boolean (ShapeExtend_WireData::*)(const TopoDS_Wire &, const Standard_Boolean, const Standard_Boolean)) &ShapeExtend_WireData::Init, "Loads an already existing wire If <chained> is True (default), edges are added in the sequence as they are explored by TopoDS_Iterator Else, if <chained> is False, wire is explored by BRepTools_WireExplorer and it is guaranteed that edges will be sequencially connected. Remark : In the latter case it can happen that not all edges will be found (because of limitations of BRepTools_WireExplorer for disconnected wires and wires with seam edges).", py::arg("wire"), py::arg("chained"), py::arg("theManifoldMode"));
	cls_ShapeExtend_WireData.def("Clear", (void (ShapeExtend_WireData::*)()) &ShapeExtend_WireData::Clear, "Clears data about Wire.");
	cls_ShapeExtend_WireData.def("ComputeSeams", [](ShapeExtend_WireData &self) -> void { return self.ComputeSeams(); });
	cls_ShapeExtend_WireData.def("ComputeSeams", (void (ShapeExtend_WireData::*)(const Standard_Boolean)) &ShapeExtend_WireData::ComputeSeams, "Computes the list of seam edges By default (direct call), computing is enforced For indirect call (from IsSeam) it is redone only if not yet already done or if the list of edges has changed Remark : A Seam Edge is an Edge present twice in the list, once as FORWARD and once as REVERSED Each sense has its own PCurve, the one for FORWARD must be set in first", py::arg("enforce"));
	cls_ShapeExtend_WireData.def("SetLast", (void (ShapeExtend_WireData::*)(const Standard_Integer)) &ShapeExtend_WireData::SetLast, "Does a circular permutation in order to set <num>th edge last", py::arg("num"));
	cls_ShapeExtend_WireData.def("SetDegeneratedLast", (void (ShapeExtend_WireData::*)()) &ShapeExtend_WireData::SetDegeneratedLast, "When the wire contains at least one degenerated edge, sets it as last one Note : It is useful to process pcurves, for instance, while the pcurve of a DGNR may not be computed from its 3D part (there is none) it is computed after the other edges have been computed and chained.");
	cls_ShapeExtend_WireData.def("Add", [](ShapeExtend_WireData &self, const TopoDS_Edge & a0) -> void { return self.Add(a0); }, py::arg("edge"));
	cls_ShapeExtend_WireData.def("Add", (void (ShapeExtend_WireData::*)(const TopoDS_Edge &, const Standard_Integer)) &ShapeExtend_WireData::Add, "Adds an edge to a wire, being defined (not yet ended) This is the plain, basic, function to add an edge <num> = 0 (D): Appends at end <num> = 1: Preprends at start else, Insert before <num> Remark : Null Edge is simply ignored", py::arg("edge"), py::arg("atnum"));
	cls_ShapeExtend_WireData.def("Add", [](ShapeExtend_WireData &self, const TopoDS_Wire & a0) -> void { return self.Add(a0); }, py::arg("wire"));
	cls_ShapeExtend_WireData.def("Add", (void (ShapeExtend_WireData::*)(const TopoDS_Wire &, const Standard_Integer)) &ShapeExtend_WireData::Add, "Adds an entire wire, considered as a list of edges Remark : The wire is assumed to be ordered (TopoDS_Iterator is used)", py::arg("wire"), py::arg("atnum"));
	cls_ShapeExtend_WireData.def("Add", [](ShapeExtend_WireData &self, const opencascade::handle<ShapeExtend_WireData> & a0) -> void { return self.Add(a0); }, py::arg("wire"));
	cls_ShapeExtend_WireData.def("Add", (void (ShapeExtend_WireData::*)(const opencascade::handle<ShapeExtend_WireData> &, const Standard_Integer)) &ShapeExtend_WireData::Add, "Adds a wire in the form of WireData", py::arg("wire"), py::arg("atnum"));
	cls_ShapeExtend_WireData.def("Add", [](ShapeExtend_WireData &self, const TopoDS_Shape & a0) -> void { return self.Add(a0); }, py::arg("shape"));
	cls_ShapeExtend_WireData.def("Add", (void (ShapeExtend_WireData::*)(const TopoDS_Shape &, const Standard_Integer)) &ShapeExtend_WireData::Add, "Adds an edge or a wire invoking corresponding method Add", py::arg("shape"), py::arg("atnum"));
	cls_ShapeExtend_WireData.def("AddOriented", (void (ShapeExtend_WireData::*)(const TopoDS_Edge &, const Standard_Integer)) &ShapeExtend_WireData::AddOriented, "Adds an edge to start or end of <me>, according to <mode> 0: at end, as direct 1: at end, as reversed 2: at start, as direct 3: at start, as reversed < 0: no adding", py::arg("edge"), py::arg("mode"));
	cls_ShapeExtend_WireData.def("AddOriented", (void (ShapeExtend_WireData::*)(const TopoDS_Wire &, const Standard_Integer)) &ShapeExtend_WireData::AddOriented, "Adds a wire to start or end of <me>, according to <mode> 0: at end, as direct 1: at end, as reversed 2: at start, as direct 3: at start, as reversed < 0: no adding", py::arg("wire"), py::arg("mode"));
	cls_ShapeExtend_WireData.def("AddOriented", (void (ShapeExtend_WireData::*)(const TopoDS_Shape &, const Standard_Integer)) &ShapeExtend_WireData::AddOriented, "Adds an edge or a wire invoking corresponding method AddOriented", py::arg("shape"), py::arg("mode"));
	cls_ShapeExtend_WireData.def("Remove", [](ShapeExtend_WireData &self) -> void { return self.Remove(); });
	cls_ShapeExtend_WireData.def("Remove", (void (ShapeExtend_WireData::*)(const Standard_Integer)) &ShapeExtend_WireData::Remove, "Removes an Edge, given its rank. By default removes the last edge.", py::arg("num"));
	cls_ShapeExtend_WireData.def("Set", [](ShapeExtend_WireData &self, const TopoDS_Edge & a0) -> void { return self.Set(a0); }, py::arg("edge"));
	cls_ShapeExtend_WireData.def("Set", (void (ShapeExtend_WireData::*)(const TopoDS_Edge &, const Standard_Integer)) &ShapeExtend_WireData::Set, "Replaces an edge at the given rank number <num> with new one. Default is last edge (<num> = 0).", py::arg("edge"), py::arg("num"));
	cls_ShapeExtend_WireData.def("Reverse", (void (ShapeExtend_WireData::*)()) &ShapeExtend_WireData::Reverse, "Reverses the sense of the list and the orientation of each Edge This method should be called when either wire has no seam edges or face is not available");
	cls_ShapeExtend_WireData.def("Reverse", (void (ShapeExtend_WireData::*)(const TopoDS_Face &)) &ShapeExtend_WireData::Reverse, "Reverses the sense of the list and the orientation of each Edge The face is necessary for swapping pcurves for seam edges (first pcurve corresponds to orientation FORWARD, and second to REVERSED; when edge is reversed, pcurves must be swapped) If face is NULL, no swapping is performed", py::arg("face"));
	cls_ShapeExtend_WireData.def("NbEdges", (Standard_Integer (ShapeExtend_WireData::*)() const ) &ShapeExtend_WireData::NbEdges, "Returns the count of currently recorded edges");
	cls_ShapeExtend_WireData.def("NbNonManifoldEdges", (Standard_Integer (ShapeExtend_WireData::*)() const ) &ShapeExtend_WireData::NbNonManifoldEdges, "Returns the count of currently recorded non-manifold edges");
	cls_ShapeExtend_WireData.def("NonmanifoldEdge", (TopoDS_Edge (ShapeExtend_WireData::*)(const Standard_Integer) const ) &ShapeExtend_WireData::NonmanifoldEdge, "Returns <num>th nonmanifold Edge", py::arg("num"));
	cls_ShapeExtend_WireData.def("NonmanifoldEdges", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeExtend_WireData::*)() const ) &ShapeExtend_WireData::NonmanifoldEdges, "Returns sequence of non-manifold edges This sequence can be not empty if wire data set in manifold mode but initial wire has INTERNAL orientation or contains INTERNAL edges");
	cls_ShapeExtend_WireData.def("ManifoldMode", (Standard_Boolean & (ShapeExtend_WireData::*)()) &ShapeExtend_WireData::ManifoldMode, "Returns mode defining manifold wire data or not. If manifold that nonmanifold edges will not be not consider during operations(previous behaviour) and they will be added only in result wire else non-manifold edges will consider during operations");
	cls_ShapeExtend_WireData.def("Edge", (TopoDS_Edge (ShapeExtend_WireData::*)(const Standard_Integer) const ) &ShapeExtend_WireData::Edge, "Returns <num>th Edge", py::arg("num"));
	cls_ShapeExtend_WireData.def("Index", (Standard_Integer (ShapeExtend_WireData::*)(const TopoDS_Edge &)) &ShapeExtend_WireData::Index, "Returns the index of the edge If the edge is a seam the orientation is also checked Returns 0 if the edge is not found in the list", py::arg("edge"));
	cls_ShapeExtend_WireData.def("IsSeam", (Standard_Boolean (ShapeExtend_WireData::*)(const Standard_Integer)) &ShapeExtend_WireData::IsSeam, "Tells if an Edge is seam (see ComputeSeams) An edge is considered as seam if it presents twice in the edge list, once as FORWARD and once as REVERSED.", py::arg("num"));
	cls_ShapeExtend_WireData.def("Wire", (TopoDS_Wire (ShapeExtend_WireData::*)() const ) &ShapeExtend_WireData::Wire, "Makes TopoDS_Wire using BRep_Builder (just creates the TopoDS_Wire object and adds all edges into it). This method should be called when the wire is correct (for example, after successful fixes by ShapeFix_Wire) and adjacent edges share common vertices. In case if adjacent edges do not share the same vertices the resulting TopoDS_Wire will be invalid.");
	cls_ShapeExtend_WireData.def("WireAPIMake", (TopoDS_Wire (ShapeExtend_WireData::*)() const ) &ShapeExtend_WireData::WireAPIMake, "Makes TopoDS_Wire using BRepAPI_MakeWire. Class BRepAPI_MakeWire merges geometrically coincided vertices and can disturb correct order of edges in the wire. If this class fails, null shape is returned.");
	cls_ShapeExtend_WireData.def_static("get_type_name_", (const char * (*)()) &ShapeExtend_WireData::get_type_name, "None");
	cls_ShapeExtend_WireData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeExtend_WireData::get_type_descriptor, "None");
	cls_ShapeExtend_WireData.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeExtend_WireData::*)() const ) &ShapeExtend_WireData::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeExtend_ComplexCurve.hxx
	py::class_<ShapeExtend_ComplexCurve, opencascade::handle<ShapeExtend_ComplexCurve>, Geom_Curve> cls_ShapeExtend_ComplexCurve(mod, "ShapeExtend_ComplexCurve", "Defines a curve which consists of several segments. Implements basic interface to it.");
	cls_ShapeExtend_ComplexCurve.def("NbCurves", (Standard_Integer (ShapeExtend_ComplexCurve::*)() const ) &ShapeExtend_ComplexCurve::NbCurves, "Returns number of curves");
	cls_ShapeExtend_ComplexCurve.def("Curve", (const opencascade::handle<Geom_Curve> & (ShapeExtend_ComplexCurve::*)(const Standard_Integer) const ) &ShapeExtend_ComplexCurve::Curve, "Returns curve given by its index", py::arg("index"));
	cls_ShapeExtend_ComplexCurve.def("LocateParameter", [](ShapeExtend_ComplexCurve &self, const Standard_Real U, Standard_Real & UOut){ Standard_Integer rv = self.LocateParameter(U, UOut); return std::tuple<Standard_Integer, Standard_Real &>(rv, UOut); }, "Returns number of the curve for the given parameter U and local paramete r UOut for the found curve", py::arg("U"), py::arg("UOut"));
	cls_ShapeExtend_ComplexCurve.def("LocalToGlobal", (Standard_Real (ShapeExtend_ComplexCurve::*)(const Standard_Integer, const Standard_Real) const ) &ShapeExtend_ComplexCurve::LocalToGlobal, "Returns global parameter for the whole curve according to the segment and local parameter on it", py::arg("index"), py::arg("Ulocal"));
	cls_ShapeExtend_ComplexCurve.def("Transform", (void (ShapeExtend_ComplexCurve::*)(const gp_Trsf &)) &ShapeExtend_ComplexCurve::Transform, "Applies transformation to each curve", py::arg("T"));
	cls_ShapeExtend_ComplexCurve.def("ReversedParameter", (Standard_Real (ShapeExtend_ComplexCurve::*)(const Standard_Real) const ) &ShapeExtend_ComplexCurve::ReversedParameter, "Returns 1 - U", py::arg("U"));
	cls_ShapeExtend_ComplexCurve.def("FirstParameter", (Standard_Real (ShapeExtend_ComplexCurve::*)() const ) &ShapeExtend_ComplexCurve::FirstParameter, "Returns 0");
	cls_ShapeExtend_ComplexCurve.def("LastParameter", (Standard_Real (ShapeExtend_ComplexCurve::*)() const ) &ShapeExtend_ComplexCurve::LastParameter, "Returns 1");
	cls_ShapeExtend_ComplexCurve.def("IsClosed", (Standard_Boolean (ShapeExtend_ComplexCurve::*)() const ) &ShapeExtend_ComplexCurve::IsClosed, "Returns True if the curve is closed");
	cls_ShapeExtend_ComplexCurve.def("IsPeriodic", (Standard_Boolean (ShapeExtend_ComplexCurve::*)() const ) &ShapeExtend_ComplexCurve::IsPeriodic, "Returns False");
	cls_ShapeExtend_ComplexCurve.def("Continuity", (GeomAbs_Shape (ShapeExtend_ComplexCurve::*)() const ) &ShapeExtend_ComplexCurve::Continuity, "Returns GeomAbs_C0");
	cls_ShapeExtend_ComplexCurve.def("IsCN", (Standard_Boolean (ShapeExtend_ComplexCurve::*)(const Standard_Integer) const ) &ShapeExtend_ComplexCurve::IsCN, "Returns False if N > 0", py::arg("N"));
	cls_ShapeExtend_ComplexCurve.def("D0", (void (ShapeExtend_ComplexCurve::*)(const Standard_Real, gp_Pnt &) const ) &ShapeExtend_ComplexCurve::D0, "Returns point at parameter U. Finds appropriate curve and local parameter on it.", py::arg("U"), py::arg("P"));
	cls_ShapeExtend_ComplexCurve.def("D1", (void (ShapeExtend_ComplexCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &ShapeExtend_ComplexCurve::D1, "None", py::arg("U"), py::arg("P"), py::arg("V1"));
	cls_ShapeExtend_ComplexCurve.def("D2", (void (ShapeExtend_ComplexCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &ShapeExtend_ComplexCurve::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_ShapeExtend_ComplexCurve.def("D3", (void (ShapeExtend_ComplexCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &ShapeExtend_ComplexCurve::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_ShapeExtend_ComplexCurve.def("DN", (gp_Vec (ShapeExtend_ComplexCurve::*)(const Standard_Real, const Standard_Integer) const ) &ShapeExtend_ComplexCurve::DN, "None", py::arg("U"), py::arg("N"));
	cls_ShapeExtend_ComplexCurve.def("GetScaleFactor", (Standard_Real (ShapeExtend_ComplexCurve::*)(const Standard_Integer) const ) &ShapeExtend_ComplexCurve::GetScaleFactor, "Returns scale factor for recomputing of deviatives.", py::arg("ind"));
	cls_ShapeExtend_ComplexCurve.def("CheckConnectivity", (Standard_Boolean (ShapeExtend_ComplexCurve::*)(const Standard_Real)) &ShapeExtend_ComplexCurve::CheckConnectivity, "Checks geometrical connectivity of the curves, including closure (sets fields myClosed)", py::arg("Preci"));
	cls_ShapeExtend_ComplexCurve.def_static("get_type_name_", (const char * (*)()) &ShapeExtend_ComplexCurve::get_type_name, "None");
	cls_ShapeExtend_ComplexCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeExtend_ComplexCurve::get_type_descriptor, "None");
	cls_ShapeExtend_ComplexCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeExtend_ComplexCurve::*)() const ) &ShapeExtend_ComplexCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeExtend_CompositeSurface.hxx
	py::class_<ShapeExtend_CompositeSurface, opencascade::handle<ShapeExtend_CompositeSurface>, Geom_Surface> cls_ShapeExtend_CompositeSurface(mod, "ShapeExtend_CompositeSurface", "Composite surface is represented by a grid of surfaces (patches) connected geometrically. Patches may have different parametrisation ranges, but they should be parametrised in the same manner so that parameter of each patch (u,v) can be converted to global parameter on the whole surface (U,V) with help of linear transformation:");
	cls_ShapeExtend_CompositeSurface.def(py::init<>());
	cls_ShapeExtend_CompositeSurface.def(py::init<const opencascade::handle<TColGeom_HArray2OfSurface> &>(), py::arg("GridSurf"));
	cls_ShapeExtend_CompositeSurface.def(py::init<const opencascade::handle<TColGeom_HArray2OfSurface> &, const ShapeExtend_Parametrisation>(), py::arg("GridSurf"), py::arg("param"));
	cls_ShapeExtend_CompositeSurface.def(py::init<const opencascade::handle<TColGeom_HArray2OfSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("GridSurf"), py::arg("UJoints"), py::arg("VJoints"));
	cls_ShapeExtend_CompositeSurface.def("Init", [](ShapeExtend_CompositeSurface &self, const opencascade::handle<TColGeom_HArray2OfSurface> & a0) -> Standard_Boolean { return self.Init(a0); }, py::arg("GridSurf"));
	cls_ShapeExtend_CompositeSurface.def("Init", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const opencascade::handle<TColGeom_HArray2OfSurface> &, const ShapeExtend_Parametrisation)) &ShapeExtend_CompositeSurface::Init, "Initializes by a grid of surfaces. All the Surfaces of the grid must have geometrical connectivity as stated above. If geometrical connectivity is not satisfied, method returns False. However, class is initialized even in that case.", py::arg("GridSurf"), py::arg("param"));
	cls_ShapeExtend_CompositeSurface.def("Init", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const opencascade::handle<TColGeom_HArray2OfSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &ShapeExtend_CompositeSurface::Init, "Initializes by a grid of surfaces with given global parametrisation defined by UJoints and VJoints arrays, each having langth equal to number of patches in corresponding direction + 1. Global joint values should be sorted in increasing order. All the Surfaces of the grid must have geometrical connectivity as stated above. If geometrical connectivity is not satisfied, method returns False. However, class is initialized even in that case.", py::arg("GridSurf"), py::arg("UJoints"), py::arg("VJoints"));
	cls_ShapeExtend_CompositeSurface.def("NbUPatches", (Standard_Integer (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::NbUPatches, "Returns number of patches in U direction.");
	cls_ShapeExtend_CompositeSurface.def("NbVPatches", (Standard_Integer (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::NbVPatches, "Returns number of patches in V direction.");
	cls_ShapeExtend_CompositeSurface.def("Patch", (const opencascade::handle<Geom_Surface> & (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer) const ) &ShapeExtend_CompositeSurface::Patch, "Returns one surface patch", py::arg("i"), py::arg("j"));
	cls_ShapeExtend_CompositeSurface.def("Patches", (const opencascade::handle<TColGeom_HArray2OfSurface> & (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::Patches, "Returns grid of surfaces");
	cls_ShapeExtend_CompositeSurface.def("UJointValues", (opencascade::handle<TColStd_HArray1OfReal> (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::UJointValues, "Returns the array of U values corresponding to joint points between patches as well as to start and end points, which define global parametrisation of the surface");
	cls_ShapeExtend_CompositeSurface.def("VJointValues", (opencascade::handle<TColStd_HArray1OfReal> (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::VJointValues, "Returns the array of V values corresponding to joint points between patches as well as to start and end points, which define global parametrisation of the surface");
	cls_ShapeExtend_CompositeSurface.def("UJointValue", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer) const ) &ShapeExtend_CompositeSurface::UJointValue, "Returns i-th joint value in U direction (1-st is global Umin, (NbUPatches()+1)-th is global Umax on the composite surface)", py::arg("i"));
	cls_ShapeExtend_CompositeSurface.def("VJointValue", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer) const ) &ShapeExtend_CompositeSurface::VJointValue, "Returns j-th joint value in V direction (1-st is global Vmin, (NbVPatches()+1)-th is global Vmax on the composite surface)", py::arg("j"));
	cls_ShapeExtend_CompositeSurface.def("SetUJointValues", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const TColStd_Array1OfReal &)) &ShapeExtend_CompositeSurface::SetUJointValues, "Sets the array of U values corresponding to joint points, which define global parametrisation of the surface. Number of values in array should be equal to NbUPatches()+1. All the values should be sorted in increasing order. If this is not satisfied, does nothing and returns False.", py::arg("UJoints"));
	cls_ShapeExtend_CompositeSurface.def("SetVJointValues", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const TColStd_Array1OfReal &)) &ShapeExtend_CompositeSurface::SetVJointValues, "Sets the array of V values corresponding to joint points, which define global parametrisation of the surface Number of values in array should be equal to NbVPatches()+1. All the values should be sorted in increasing order. If this is not satisfied, does nothing and returns False.", py::arg("VJoints"));
	cls_ShapeExtend_CompositeSurface.def("SetUFirstValue", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real)) &ShapeExtend_CompositeSurface::SetUFirstValue, "Changes starting value for global U parametrisation (all other joint values are shifted accordingly)", py::arg("UFirst"));
	cls_ShapeExtend_CompositeSurface.def("SetVFirstValue", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real)) &ShapeExtend_CompositeSurface::SetVFirstValue, "Changes starting value for global V parametrisation (all other joint values are shifted accordingly)", py::arg("VFirst"));
	cls_ShapeExtend_CompositeSurface.def("LocateUParameter", (Standard_Integer (ShapeExtend_CompositeSurface::*)(const Standard_Real) const ) &ShapeExtend_CompositeSurface::LocateUParameter, "Returns number of col that contains given (global) parameter", py::arg("U"));
	cls_ShapeExtend_CompositeSurface.def("LocateVParameter", (Standard_Integer (ShapeExtend_CompositeSurface::*)(const Standard_Real) const ) &ShapeExtend_CompositeSurface::LocateVParameter, "Returns number of row that contains given (global) parameter", py::arg("V"));
	cls_ShapeExtend_CompositeSurface.def("LocateUVPoint", [](ShapeExtend_CompositeSurface &self, const gp_Pnt2d & pnt, Standard_Integer & i, Standard_Integer & j){ self.LocateUVPoint(pnt, i, j); return std::tuple<Standard_Integer &, Standard_Integer &>(i, j); }, "Returns number of row and col of surface that contains given point", py::arg("pnt"), py::arg("i"), py::arg("j"));
	cls_ShapeExtend_CompositeSurface.def("Patch", (const opencascade::handle<Geom_Surface> & (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real) const ) &ShapeExtend_CompositeSurface::Patch, "Returns one surface patch that contains given (global) parameters", py::arg("U"), py::arg("V"));
	cls_ShapeExtend_CompositeSurface.def("Patch", (const opencascade::handle<Geom_Surface> & (ShapeExtend_CompositeSurface::*)(const gp_Pnt2d &) const ) &ShapeExtend_CompositeSurface::Patch, "Returns one surface patch that contains given point", py::arg("pnt"));
	cls_ShapeExtend_CompositeSurface.def("ULocalToGlobal", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const Standard_Real) const ) &ShapeExtend_CompositeSurface::ULocalToGlobal, "Converts local parameter u on patch i,j to global parameter U", py::arg("i"), py::arg("j"), py::arg("u"));
	cls_ShapeExtend_CompositeSurface.def("VLocalToGlobal", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const Standard_Real) const ) &ShapeExtend_CompositeSurface::VLocalToGlobal, "Converts local parameter v on patch i,j to global parameter V", py::arg("i"), py::arg("j"), py::arg("v"));
	cls_ShapeExtend_CompositeSurface.def("LocalToGlobal", (gp_Pnt2d (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const gp_Pnt2d &) const ) &ShapeExtend_CompositeSurface::LocalToGlobal, "Converts local parameters uv on patch i,j to global parameters UV", py::arg("i"), py::arg("j"), py::arg("uv"));
	cls_ShapeExtend_CompositeSurface.def("UGlobalToLocal", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const Standard_Real) const ) &ShapeExtend_CompositeSurface::UGlobalToLocal, "Converts global parameter U to local parameter u on patch i,j", py::arg("i"), py::arg("j"), py::arg("U"));
	cls_ShapeExtend_CompositeSurface.def("VGlobalToLocal", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const Standard_Real) const ) &ShapeExtend_CompositeSurface::VGlobalToLocal, "Converts global parameter V to local parameter v on patch i,j", py::arg("i"), py::arg("j"), py::arg("V"));
	cls_ShapeExtend_CompositeSurface.def("GlobalToLocal", (gp_Pnt2d (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const gp_Pnt2d &) const ) &ShapeExtend_CompositeSurface::GlobalToLocal, "Converts global parameters UV to local parameters uv on patch i,j", py::arg("i"), py::arg("j"), py::arg("UV"));
	cls_ShapeExtend_CompositeSurface.def("GlobalToLocalTransformation", [](ShapeExtend_CompositeSurface &self, const Standard_Integer i, const Standard_Integer j, Standard_Real & uFact, gp_Trsf2d & Trsf){ Standard_Boolean rv = self.GlobalToLocalTransformation(i, j, uFact, Trsf); return std::tuple<Standard_Boolean, Standard_Real &>(rv, uFact); }, "Computes transformation operator and uFactor descrinbing affine transformation required to convert global parameters on composite surface to local parameters on patch (i,j): uv = ( uFactor, 1. ) X Trsf * UV; NOTE: Thus Trsf contains shift and scale by V, scale by U is stored in uFact. Returns True if transformation is not an identity", py::arg("i"), py::arg("j"), py::arg("uFact"), py::arg("Trsf"));
	cls_ShapeExtend_CompositeSurface.def("Transform", (void (ShapeExtend_CompositeSurface::*)(const gp_Trsf &)) &ShapeExtend_CompositeSurface::Transform, "Applies transformation to all the patches", py::arg("T"));
	cls_ShapeExtend_CompositeSurface.def("Copy", (opencascade::handle<Geom_Geometry> (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::Copy, "Returns a copy of the surface");
	cls_ShapeExtend_CompositeSurface.def("UReverse", (void (ShapeExtend_CompositeSurface::*)()) &ShapeExtend_CompositeSurface::UReverse, "NOT IMPLEMENTED (does nothing)");
	cls_ShapeExtend_CompositeSurface.def("UReversedParameter", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Real) const ) &ShapeExtend_CompositeSurface::UReversedParameter, "Returns U", py::arg("U"));
	cls_ShapeExtend_CompositeSurface.def("VReverse", (void (ShapeExtend_CompositeSurface::*)()) &ShapeExtend_CompositeSurface::VReverse, "NOT IMPLEMENTED (does nothing)");
	cls_ShapeExtend_CompositeSurface.def("VReversedParameter", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Real) const ) &ShapeExtend_CompositeSurface::VReversedParameter, "Returns V", py::arg("V"));
	cls_ShapeExtend_CompositeSurface.def("Bounds", [](ShapeExtend_CompositeSurface &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "Returns the parametric bounds of grid", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
	cls_ShapeExtend_CompositeSurface.def("IsUClosed", (Standard_Boolean (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::IsUClosed, "Returns True if grid is closed in U direction (i.e. connected with Precision::Confusion)");
	cls_ShapeExtend_CompositeSurface.def("IsVClosed", (Standard_Boolean (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::IsVClosed, "Returns True if grid is closed in V direction (i.e. connected with Precision::Confusion)");
	cls_ShapeExtend_CompositeSurface.def("IsUPeriodic", (Standard_Boolean (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::IsUPeriodic, "Returns False");
	cls_ShapeExtend_CompositeSurface.def("IsVPeriodic", (Standard_Boolean (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::IsVPeriodic, "Returns False");
	cls_ShapeExtend_CompositeSurface.def("UIso", (opencascade::handle<Geom_Curve> (ShapeExtend_CompositeSurface::*)(const Standard_Real) const ) &ShapeExtend_CompositeSurface::UIso, "NOT IMPLEMENTED (returns Null curve)", py::arg("U"));
	cls_ShapeExtend_CompositeSurface.def("VIso", (opencascade::handle<Geom_Curve> (ShapeExtend_CompositeSurface::*)(const Standard_Real) const ) &ShapeExtend_CompositeSurface::VIso, "NOT IMPLEMENTED (returns Null curve)", py::arg("V"));
	cls_ShapeExtend_CompositeSurface.def("Continuity", (GeomAbs_Shape (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::Continuity, "returns C0");
	cls_ShapeExtend_CompositeSurface.def("IsCNu", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const Standard_Integer) const ) &ShapeExtend_CompositeSurface::IsCNu, "returns True if N <=0", py::arg("N"));
	cls_ShapeExtend_CompositeSurface.def("IsCNv", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const Standard_Integer) const ) &ShapeExtend_CompositeSurface::IsCNv, "returns True if N <=0", py::arg("N"));
	cls_ShapeExtend_CompositeSurface.def("D0", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const ) &ShapeExtend_CompositeSurface::D0, "Computes the point of parameter U,V on the grid.", py::arg("U"), py::arg("V"), py::arg("P"));
	cls_ShapeExtend_CompositeSurface.def("D1", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &ShapeExtend_CompositeSurface::D1, "Computes the point P and the first derivatives in the directions U and V at this point.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
	cls_ShapeExtend_CompositeSurface.def("D2", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &ShapeExtend_CompositeSurface::D2, "Computes the point P, the first and the second derivatives in the directions U and V at this point.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
	cls_ShapeExtend_CompositeSurface.def("D3", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &ShapeExtend_CompositeSurface::D3, "Computes the point P, the first,the second and the third derivatives in the directions U and V at this point.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
	cls_ShapeExtend_CompositeSurface.def("DN", (gp_Vec (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const ) &ShapeExtend_CompositeSurface::DN, "Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V).", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
	cls_ShapeExtend_CompositeSurface.def("Value", (gp_Pnt (ShapeExtend_CompositeSurface::*)(const gp_Pnt2d &) const ) &ShapeExtend_CompositeSurface::Value, "Computes the point of parameter pnt on the grid.", py::arg("pnt"));
	cls_ShapeExtend_CompositeSurface.def("ComputeJointValues", [](ShapeExtend_CompositeSurface &self) -> void { return self.ComputeJointValues(); });
	cls_ShapeExtend_CompositeSurface.def("ComputeJointValues", (void (ShapeExtend_CompositeSurface::*)(const ShapeExtend_Parametrisation)) &ShapeExtend_CompositeSurface::ComputeJointValues, "Computes Joint values according to parameter", py::arg("param"));
	cls_ShapeExtend_CompositeSurface.def("CheckConnectivity", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const Standard_Real)) &ShapeExtend_CompositeSurface::CheckConnectivity, "Checks geometrical connectivity of the patches, including closedness (sets fields muUClosed and myVClosed)", py::arg("prec"));
	cls_ShapeExtend_CompositeSurface.def_static("get_type_name_", (const char * (*)()) &ShapeExtend_CompositeSurface::get_type_name, "None");
	cls_ShapeExtend_CompositeSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeExtend_CompositeSurface::get_type_descriptor, "None");
	cls_ShapeExtend_CompositeSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeExtend_CompositeSurface::*)() const ) &ShapeExtend_CompositeSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeExtend_MsgRegistrator.hxx
	py::class_<ShapeExtend_MsgRegistrator, opencascade::handle<ShapeExtend_MsgRegistrator>, ShapeExtend_BasicMsgRegistrator> cls_ShapeExtend_MsgRegistrator(mod, "ShapeExtend_MsgRegistrator", "Attaches messages to the objects (generic Transient or shape). The objects of this class are transmitted to the Shape Healing algorithms so that they could collect messages occurred during processing.");
	cls_ShapeExtend_MsgRegistrator.def(py::init<>());
	cls_ShapeExtend_MsgRegistrator.def("Send", (void (ShapeExtend_MsgRegistrator::*)(const opencascade::handle<Standard_Transient> &, const Message_Msg &, const Message_Gravity)) &ShapeExtend_MsgRegistrator::Send, "Sends a message to be attached to the object. If the object is in the map then the message is added to the list, otherwise the object is firstly added to the map.", py::arg("object"), py::arg("message"), py::arg("gravity"));
	cls_ShapeExtend_MsgRegistrator.def("Send", (void (ShapeExtend_MsgRegistrator::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity)) &ShapeExtend_MsgRegistrator::Send, "Sends a message to be attached to the shape. If the shape is in the map then the message is added to the list, otherwise the shape is firstly added to the map.", py::arg("shape"), py::arg("message"), py::arg("gravity"));
	cls_ShapeExtend_MsgRegistrator.def("MapTransient", (const ShapeExtend_DataMapOfTransientListOfMsg & (ShapeExtend_MsgRegistrator::*)() const ) &ShapeExtend_MsgRegistrator::MapTransient, "Returns a Map of objects and message list");
	cls_ShapeExtend_MsgRegistrator.def("MapShape", (const ShapeExtend_DataMapOfShapeListOfMsg & (ShapeExtend_MsgRegistrator::*)() const ) &ShapeExtend_MsgRegistrator::MapShape, "Returns a Map of shapes and message list");
	cls_ShapeExtend_MsgRegistrator.def_static("get_type_name_", (const char * (*)()) &ShapeExtend_MsgRegistrator::get_type_name, "None");
	cls_ShapeExtend_MsgRegistrator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeExtend_MsgRegistrator::get_type_descriptor, "None");
	cls_ShapeExtend_MsgRegistrator.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeExtend_MsgRegistrator::*)() const ) &ShapeExtend_MsgRegistrator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeExtend_Explorer.hxx
	py::class_<ShapeExtend_Explorer, std::unique_ptr<ShapeExtend_Explorer, Deleter<ShapeExtend_Explorer>>> cls_ShapeExtend_Explorer(mod, "ShapeExtend_Explorer", "This class is intended to explore shapes and convert different representations (list, sequence, compound) of complex shapes. It provides tools for: - obtaining type of the shapes in context of TopoDS_Compound, - exploring shapes in context of TopoDS_Compound, - converting different representations of shapes (list, sequence, compound).");
	cls_ShapeExtend_Explorer.def(py::init<>());
	cls_ShapeExtend_Explorer.def("CompoundFromSeq", (TopoDS_Shape (ShapeExtend_Explorer::*)(const opencascade::handle<TopTools_HSequenceOfShape> &) const ) &ShapeExtend_Explorer::CompoundFromSeq, "Converts a sequence of Shapes to a Compound", py::arg("seqval"));
	cls_ShapeExtend_Explorer.def("SeqFromCompound", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeExtend_Explorer::*)(const TopoDS_Shape &, const Standard_Boolean) const ) &ShapeExtend_Explorer::SeqFromCompound, "Converts a Compound to a list of Shapes if <comp> is not a compound, the list contains only <comp> if <comp> is Null, the list is empty if <comp> is a Compound, its sub-shapes are put into the list then if <expcomp> is True, if a sub-shape is a Compound, it is not put to the list but its sub-shapes are (recursive)", py::arg("comp"), py::arg("expcomp"));
	cls_ShapeExtend_Explorer.def("ListFromSeq", [](ShapeExtend_Explorer &self, const opencascade::handle<TopTools_HSequenceOfShape> & a0, TopTools_ListOfShape & a1) -> void { return self.ListFromSeq(a0, a1); }, py::arg("seqval"), py::arg("lisval"));
	cls_ShapeExtend_Explorer.def("ListFromSeq", (void (ShapeExtend_Explorer::*)(const opencascade::handle<TopTools_HSequenceOfShape> &, TopTools_ListOfShape &, const Standard_Boolean) const ) &ShapeExtend_Explorer::ListFromSeq, "Converts a Sequence of Shapes to a List of Shapes <clear> if True (D), commands the list to start from scratch else, the list is cumulated", py::arg("seqval"), py::arg("lisval"), py::arg("clear"));
	cls_ShapeExtend_Explorer.def("SeqFromList", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeExtend_Explorer::*)(const TopTools_ListOfShape &) const ) &ShapeExtend_Explorer::SeqFromList, "Converts a List of Shapes to a Sequence of Shapes", py::arg("lisval"));
	cls_ShapeExtend_Explorer.def("ShapeType", (TopAbs_ShapeEnum (ShapeExtend_Explorer::*)(const TopoDS_Shape &, const Standard_Boolean) const ) &ShapeExtend_Explorer::ShapeType, "Returns the type of a Shape: true type if <compound> is False If <compound> is True and <shape> is a Compound, iterates on its items. If all are of the same type, returns this type. Else, returns COMPOUND. If it is empty, returns SHAPE For a Null Shape, returns SHAPE", py::arg("shape"), py::arg("compound"));
	cls_ShapeExtend_Explorer.def("SortedCompound", (TopoDS_Shape (ShapeExtend_Explorer::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const Standard_Boolean, const Standard_Boolean) const ) &ShapeExtend_Explorer::SortedCompound, "Builds a COMPOUND from the given shape. It explores the shape level by level, according to the <explore> argument. If <explore> is False, only COMPOUND items are explored, else all items are. The following shapes are added to resulting compound: - shapes which comply to <type> - if <type> is WIRE, considers also free edges (and makes wires) - if <type> is SHELL, considers also free faces (and makes shells) If <compound> is True, gathers items in compounds which correspond to starting COMPOUND,SOLID or SHELL containers, or items directly contained in a Compound", py::arg("shape"), py::arg("type"), py::arg("explore"), py::arg("compound"));
	cls_ShapeExtend_Explorer.def("DispatchList", (void (ShapeExtend_Explorer::*)(const opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &) const ) &ShapeExtend_Explorer::DispatchList, "Dispatches starting list of shapes according to their type, to the appropriate resulting lists For each of these lists, if it is null, it is firstly created else, new items are appended to the already existing ones", py::arg("list"), py::arg("vertices"), py::arg("edges"), py::arg("wires"), py::arg("faces"), py::arg("shells"), py::arg("solids"), py::arg("compsols"), py::arg("compounds"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeExtend.hxx
	py::class_<ShapeExtend, std::unique_ptr<ShapeExtend, Deleter<ShapeExtend>>> cls_ShapeExtend(mod, "ShapeExtend", "This package provides general tools and data structures common for other packages in SHAPEWORKS and extending CAS.CADE structures. The following items are provided by this package: - enumeration Status used for coding status flags in methods inside the SHAPEWORKS - enumeration Parametrisation used for setting global parametrisation on the composite surface - class CompositeSurface representing a composite surface made of a grid of surface patches - class WireData representing a wire in the form of ordered list of edges - class MsgRegistrator for attaching messages to the objects - tools for exploring the shapes - tools for creating new shapes.");
	cls_ShapeExtend.def(py::init<>());
	cls_ShapeExtend.def_static("Init_", (void (*)()) &ShapeExtend::Init, "Inits using of ShapeExtend. Currently, loads messages output by ShapeHealing algorithms.");
	cls_ShapeExtend.def_static("EncodeStatus_", (Standard_Integer (*)(const ShapeExtend_Status)) &ShapeExtend::EncodeStatus, "Encodes status (enumeration) to a bit flag", py::arg("status"));
	cls_ShapeExtend.def_static("DecodeStatus_", (Standard_Boolean (*)(const Standard_Integer, const ShapeExtend_Status)) &ShapeExtend::DecodeStatus, "Tells if a bit flag contains bit corresponding to enumerated status", py::arg("flag"), py::arg("status"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeExtend_DataMapOfShapeListOfMsg.hxx
	bind_NCollection_DataMap<TopoDS_Shape, NCollection_List<Message_Msg>, TopTools_ShapeMapHasher>(mod, "ShapeExtend_DataMapOfShapeListOfMsg");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeExtend_DataMapOfTransientListOfMsg.hxx
	bind_NCollection_DataMap<opencascade::handle<Standard_Transient>, NCollection_List<Message_Msg>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "ShapeExtend_DataMapOfTransientListOfMsg");

	/* FIXME

	*/


}
