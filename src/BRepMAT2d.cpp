#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BRepMAT2d_Explorer.hxx>
#include <Standard_TypeDef.hxx>
#include <MAT_Side.hxx>
#include <GeomAbs_JoinType.hxx>
#include <Standard_Handle.hxx>
#include <MAT_Graph.hxx>
#include <MAT_BasicElt.hxx>
#include <Geom2d_Geometry.hxx>
#include <gp_Pnt2d.hxx>
#include <MAT_Node.hxx>
#include <Bisector_Bisec.hxx>
#include <MAT_Arc.hxx>
#include <BRepMAT2d_BisectingLocus.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepMAT2d_LinkTopoBilo.hxx>
#include <TopoDS_Face.hxx>
#include <Geom2d_Curve.hxx>
#include <TColGeom2d_SequenceOfCurve.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.hxx>
#include <BRepMAT2d_DataMapOfBasicEltShape.hxx>

PYBIND11_MODULE(BRepMAT2d, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.MAT");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Bisector");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TColGeom2d");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMAT2d_BisectingLocus.hxx
	py::class_<BRepMAT2d_BisectingLocus, std::unique_ptr<BRepMAT2d_BisectingLocus, Deleter<BRepMAT2d_BisectingLocus>>> cls_BRepMAT2d_BisectingLocus(mod, "BRepMAT2d_BisectingLocus", "BisectingLocus generates and contains the Bisecting_Locus of a set of lines from Geom2d, defined by <ExploSet>.");
	cls_BRepMAT2d_BisectingLocus.def(py::init<>());
	cls_BRepMAT2d_BisectingLocus.def("Compute", [](BRepMAT2d_BisectingLocus &self, BRepMAT2d_Explorer & a0) -> void { return self.Compute(a0); }, py::arg("anExplo"));
	cls_BRepMAT2d_BisectingLocus.def("Compute", [](BRepMAT2d_BisectingLocus &self, BRepMAT2d_Explorer & a0, const Standard_Integer a1) -> void { return self.Compute(a0, a1); }, py::arg("anExplo"), py::arg("LineIndex"));
	cls_BRepMAT2d_BisectingLocus.def("Compute", [](BRepMAT2d_BisectingLocus &self, BRepMAT2d_Explorer & a0, const Standard_Integer a1, const MAT_Side a2) -> void { return self.Compute(a0, a1, a2); }, py::arg("anExplo"), py::arg("LineIndex"), py::arg("aSide"));
	cls_BRepMAT2d_BisectingLocus.def("Compute", [](BRepMAT2d_BisectingLocus &self, BRepMAT2d_Explorer & a0, const Standard_Integer a1, const MAT_Side a2, const GeomAbs_JoinType a3) -> void { return self.Compute(a0, a1, a2, a3); }, py::arg("anExplo"), py::arg("LineIndex"), py::arg("aSide"), py::arg("aJoinType"));
	cls_BRepMAT2d_BisectingLocus.def("Compute", (void (BRepMAT2d_BisectingLocus::*)(BRepMAT2d_Explorer &, const Standard_Integer, const MAT_Side, const GeomAbs_JoinType, const Standard_Boolean)) &BRepMAT2d_BisectingLocus::Compute, "Computation of the Bisector_Locus in a set of Lines defined in <anExplo>. The bisecting locus are computed on the side <aSide> from the line <LineIndex> in <anExplo>.", py::arg("anExplo"), py::arg("LineIndex"), py::arg("aSide"), py::arg("aJoinType"), py::arg("IsOpenResult"));
	cls_BRepMAT2d_BisectingLocus.def("IsDone", (Standard_Boolean (BRepMAT2d_BisectingLocus::*)() const ) &BRepMAT2d_BisectingLocus::IsDone, "Returns True if Compute has succeeded.");
	cls_BRepMAT2d_BisectingLocus.def("Graph", (opencascade::handle<MAT_Graph> (BRepMAT2d_BisectingLocus::*)() const ) &BRepMAT2d_BisectingLocus::Graph, "Returns <theGraph> of <me>.");
	cls_BRepMAT2d_BisectingLocus.def("NumberOfContours", (Standard_Integer (BRepMAT2d_BisectingLocus::*)() const ) &BRepMAT2d_BisectingLocus::NumberOfContours, "Returns the number of contours.");
	cls_BRepMAT2d_BisectingLocus.def("NumberOfElts", (Standard_Integer (BRepMAT2d_BisectingLocus::*)(const Standard_Integer) const ) &BRepMAT2d_BisectingLocus::NumberOfElts, "Returns the number of BasicElts on the line <IndLine>.", py::arg("IndLine"));
	cls_BRepMAT2d_BisectingLocus.def("NumberOfSections", (Standard_Integer (BRepMAT2d_BisectingLocus::*)(const Standard_Integer, const Standard_Integer) const ) &BRepMAT2d_BisectingLocus::NumberOfSections, "Returns the number of sections of a curve. this curve is the Indexth curve in the IndLineth contour given by anExplo.", py::arg("IndLine"), py::arg("Index"));
	cls_BRepMAT2d_BisectingLocus.def("BasicElt", (opencascade::handle<MAT_BasicElt> (BRepMAT2d_BisectingLocus::*)(const Standard_Integer, const Standard_Integer) const ) &BRepMAT2d_BisectingLocus::BasicElt, "Returns the BasicElts located at the position <Index> on the contour designed by <IndLine>. Remark: the BasicElts on a contour are sorted.", py::arg("IndLine"), py::arg("Index"));
	cls_BRepMAT2d_BisectingLocus.def("GeomElt", (opencascade::handle<Geom2d_Geometry> (BRepMAT2d_BisectingLocus::*)(const opencascade::handle<MAT_BasicElt> &) const ) &BRepMAT2d_BisectingLocus::GeomElt, "Returns the geometry linked to the <BasicElt>.", py::arg("aBasicElt"));
	cls_BRepMAT2d_BisectingLocus.def("GeomElt", (gp_Pnt2d (BRepMAT2d_BisectingLocus::*)(const opencascade::handle<MAT_Node> &) const ) &BRepMAT2d_BisectingLocus::GeomElt, "Returns the geometry of type <gp> linked to the <Node>.", py::arg("aNode"));
	cls_BRepMAT2d_BisectingLocus.def("GeomBis", (Bisector_Bisec (BRepMAT2d_BisectingLocus::*)(const opencascade::handle<MAT_Arc> &, Standard_Boolean &) const ) &BRepMAT2d_BisectingLocus::GeomBis, "Returns the geometry of type <Bissec> linked to the arc <ARC>. <Reverse> is False when the FirstNode of <anArc> correspond to the first point of geometry.", py::arg("anArc"), py::arg("Reverse"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMAT2d_LinkTopoBilo.hxx
	py::class_<BRepMAT2d_LinkTopoBilo, std::unique_ptr<BRepMAT2d_LinkTopoBilo, Deleter<BRepMAT2d_LinkTopoBilo>>> cls_BRepMAT2d_LinkTopoBilo(mod, "BRepMAT2d_LinkTopoBilo", "Constucts links between the Wire or the Face of the explorer and the BasicElts contained in the bisecting locus.");
	cls_BRepMAT2d_LinkTopoBilo.def(py::init<>());
	cls_BRepMAT2d_LinkTopoBilo.def(py::init<const BRepMAT2d_Explorer &, const BRepMAT2d_BisectingLocus &>(), py::arg("Explo"), py::arg("BiLo"));
	cls_BRepMAT2d_LinkTopoBilo.def("Perform", (void (BRepMAT2d_LinkTopoBilo::*)(const BRepMAT2d_Explorer &, const BRepMAT2d_BisectingLocus &)) &BRepMAT2d_LinkTopoBilo::Perform, "Constructs the links Between S and BiLo.", py::arg("Explo"), py::arg("BiLo"));
	cls_BRepMAT2d_LinkTopoBilo.def("Init", (void (BRepMAT2d_LinkTopoBilo::*)(const TopoDS_Shape &)) &BRepMAT2d_LinkTopoBilo::Init, "Initialise the Iterator on <S> <S> is an edge or a vertex of the initial wire or face. raises if <S> is not an edge or a vertex.", py::arg("S"));
	cls_BRepMAT2d_LinkTopoBilo.def("More", (Standard_Boolean (BRepMAT2d_LinkTopoBilo::*)()) &BRepMAT2d_LinkTopoBilo::More, "Returns True if there is a current BasicElt.");
	cls_BRepMAT2d_LinkTopoBilo.def("Next", (void (BRepMAT2d_LinkTopoBilo::*)()) &BRepMAT2d_LinkTopoBilo::Next, "Proceed to the next BasicElt.");
	cls_BRepMAT2d_LinkTopoBilo.def("Value", (opencascade::handle<MAT_BasicElt> (BRepMAT2d_LinkTopoBilo::*)() const ) &BRepMAT2d_LinkTopoBilo::Value, "Returns the current BasicElt.");
	cls_BRepMAT2d_LinkTopoBilo.def("GeneratingShape", (TopoDS_Shape (BRepMAT2d_LinkTopoBilo::*)(const opencascade::handle<MAT_BasicElt> &) const ) &BRepMAT2d_LinkTopoBilo::GeneratingShape, "Returns the Shape linked to <aBE>.", py::arg("aBE"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMAT2d_Explorer.hxx
	py::class_<BRepMAT2d_Explorer, std::unique_ptr<BRepMAT2d_Explorer, Deleter<BRepMAT2d_Explorer>>> cls_BRepMAT2d_Explorer(mod, "BRepMAT2d_Explorer", "Construct an explorer from wires, face, set of curves from Geom2d to compute the bisecting Locus.");
	cls_BRepMAT2d_Explorer.def(py::init<>());
	cls_BRepMAT2d_Explorer.def(py::init<const TopoDS_Face &>(), py::arg("aFace"));
	cls_BRepMAT2d_Explorer.def("Clear", (void (BRepMAT2d_Explorer::*)()) &BRepMAT2d_Explorer::Clear, "Clear the contents of <me>.");
	cls_BRepMAT2d_Explorer.def("Perform", (void (BRepMAT2d_Explorer::*)(const TopoDS_Face &)) &BRepMAT2d_Explorer::Perform, "None", py::arg("aFace"));
	cls_BRepMAT2d_Explorer.def("NumberOfContours", (Standard_Integer (BRepMAT2d_Explorer::*)() const ) &BRepMAT2d_Explorer::NumberOfContours, "Returns the Number of contours.");
	cls_BRepMAT2d_Explorer.def("NumberOfCurves", (Standard_Integer (BRepMAT2d_Explorer::*)(const Standard_Integer) const ) &BRepMAT2d_Explorer::NumberOfCurves, "Returns the Number of Curves in the Contour number <IndexContour>.", py::arg("IndexContour"));
	cls_BRepMAT2d_Explorer.def("Init", (void (BRepMAT2d_Explorer::*)(const Standard_Integer)) &BRepMAT2d_Explorer::Init, "Initialisation of an Iterator on the curves of the Contour number <IndexContour>.", py::arg("IndexContour"));
	cls_BRepMAT2d_Explorer.def("More", (Standard_Boolean (BRepMAT2d_Explorer::*)() const ) &BRepMAT2d_Explorer::More, "Return False if there is no more curves on the Contour initialised by the method Init.");
	cls_BRepMAT2d_Explorer.def("Next", (void (BRepMAT2d_Explorer::*)()) &BRepMAT2d_Explorer::Next, "Move to the next curve of the current Contour.");
	cls_BRepMAT2d_Explorer.def("Value", (opencascade::handle<Geom2d_Curve> (BRepMAT2d_Explorer::*)() const ) &BRepMAT2d_Explorer::Value, "Returns the current curve on the current Contour.");
	cls_BRepMAT2d_Explorer.def("Shape", (TopoDS_Shape (BRepMAT2d_Explorer::*)() const ) &BRepMAT2d_Explorer::Shape, "None");
	cls_BRepMAT2d_Explorer.def("Contour", (const TColGeom2d_SequenceOfCurve & (BRepMAT2d_Explorer::*)(const Standard_Integer) const ) &BRepMAT2d_Explorer::Contour, "None", py::arg("IndexContour"));
	cls_BRepMAT2d_Explorer.def("IsModified", (Standard_Boolean (BRepMAT2d_Explorer::*)(const TopoDS_Shape &) const ) &BRepMAT2d_Explorer::IsModified, "None", py::arg("aShape"));
	cls_BRepMAT2d_Explorer.def("ModifiedShape", (TopoDS_Shape (BRepMAT2d_Explorer::*)(const TopoDS_Shape &) const ) &BRepMAT2d_Explorer::ModifiedShape, "If the shape is not modified, returns the shape itself.", py::arg("aShape"));
	cls_BRepMAT2d_Explorer.def("GetIsClosed", (const TColStd_SequenceOfBoolean & (BRepMAT2d_Explorer::*)() const ) &BRepMAT2d_Explorer::GetIsClosed, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepMAT2d_DataMapOfShapeSequenceOfBasicElt, std::unique_ptr<BRepMAT2d_DataMapOfShapeSequenceOfBasicElt, Deleter<BRepMAT2d_DataMapOfShapeSequenceOfBasicElt>>, NCollection_BaseMap> cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt(mod, "BRepMAT2d_DataMapOfShapeSequenceOfBasicElt", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def(py::init<>());
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def(py::init([] (const BRepMAT2d_DataMapOfShapeSequenceOfBasicElt &other) {return new BRepMAT2d_DataMapOfShapeSequenceOfBasicElt(other);}), "Copy constructor", py::arg("other"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("begin", (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::iterator (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)() const ) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("end", (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::iterator (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)() const ) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("cbegin", (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::const_iterator (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)() const ) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("cend", (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::const_iterator (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)() const ) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("Exchange", (void (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(BRepMAT2d_DataMapOfShapeSequenceOfBasicElt &)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("Assign", (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt & (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const BRepMAT2d_DataMapOfShapeSequenceOfBasicElt &)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("assign", (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt & (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const BRepMAT2d_DataMapOfShapeSequenceOfBasicElt &)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("ReSize", (void (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const Standard_Integer)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::ReSize, "ReSize", py::arg("N"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("Bind", (Standard_Boolean (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const TopoDS_Shape &, const MAT_SequenceOfBasicElt &)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("Bound", (MAT_SequenceOfBasicElt * (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const TopoDS_Shape &, const MAT_SequenceOfBasicElt &)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("IsBound", (Standard_Boolean (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const TopoDS_Shape &) const ) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("UnBind", (Standard_Boolean (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const TopoDS_Shape &)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("Seek", (const MAT_SequenceOfBasicElt * (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const TopoDS_Shape &) const ) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("Find", (const MAT_SequenceOfBasicElt & (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const TopoDS_Shape &) const ) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("Find", (Standard_Boolean (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const TopoDS_Shape &, MAT_SequenceOfBasicElt &) const ) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("__call__", (const MAT_SequenceOfBasicElt & (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const TopoDS_Shape &) const ) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("ChangeSeek", (MAT_SequenceOfBasicElt * (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const TopoDS_Shape &)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("ChangeFind", (MAT_SequenceOfBasicElt & (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const TopoDS_Shape &)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("__call__", (MAT_SequenceOfBasicElt & (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const TopoDS_Shape &)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("Clear", [](BRepMAT2d_DataMapOfShapeSequenceOfBasicElt &self) -> void { return self.Clear(); });
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("Clear", (void (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const Standard_Boolean)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("Clear", (void (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("Size", (Standard_Integer (BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::*)() const ) &BRepMAT2d_DataMapOfShapeSequenceOfBasicElt::Size, "Size");
	cls_BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.def("__iter__", [](const BRepMAT2d_DataMapOfShapeSequenceOfBasicElt &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepMAT2d_DataMapOfBasicEltShape, std::unique_ptr<BRepMAT2d_DataMapOfBasicEltShape, Deleter<BRepMAT2d_DataMapOfBasicEltShape>>, NCollection_BaseMap> cls_BRepMAT2d_DataMapOfBasicEltShape(mod, "BRepMAT2d_DataMapOfBasicEltShape", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepMAT2d_DataMapOfBasicEltShape.def(py::init<>());
	cls_BRepMAT2d_DataMapOfBasicEltShape.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def(py::init([] (const BRepMAT2d_DataMapOfBasicEltShape &other) {return new BRepMAT2d_DataMapOfBasicEltShape(other);}), "Copy constructor", py::arg("other"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("begin", (BRepMAT2d_DataMapOfBasicEltShape::iterator (BRepMAT2d_DataMapOfBasicEltShape::*)() const ) &BRepMAT2d_DataMapOfBasicEltShape::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("end", (BRepMAT2d_DataMapOfBasicEltShape::iterator (BRepMAT2d_DataMapOfBasicEltShape::*)() const ) &BRepMAT2d_DataMapOfBasicEltShape::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("cbegin", (BRepMAT2d_DataMapOfBasicEltShape::const_iterator (BRepMAT2d_DataMapOfBasicEltShape::*)() const ) &BRepMAT2d_DataMapOfBasicEltShape::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("cend", (BRepMAT2d_DataMapOfBasicEltShape::const_iterator (BRepMAT2d_DataMapOfBasicEltShape::*)() const ) &BRepMAT2d_DataMapOfBasicEltShape::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("Exchange", (void (BRepMAT2d_DataMapOfBasicEltShape::*)(BRepMAT2d_DataMapOfBasicEltShape &)) &BRepMAT2d_DataMapOfBasicEltShape::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("Assign", (BRepMAT2d_DataMapOfBasicEltShape & (BRepMAT2d_DataMapOfBasicEltShape::*)(const BRepMAT2d_DataMapOfBasicEltShape &)) &BRepMAT2d_DataMapOfBasicEltShape::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("assign", (BRepMAT2d_DataMapOfBasicEltShape & (BRepMAT2d_DataMapOfBasicEltShape::*)(const BRepMAT2d_DataMapOfBasicEltShape &)) &BRepMAT2d_DataMapOfBasicEltShape::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("ReSize", (void (BRepMAT2d_DataMapOfBasicEltShape::*)(const Standard_Integer)) &BRepMAT2d_DataMapOfBasicEltShape::ReSize, "ReSize", py::arg("N"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("Bind", (Standard_Boolean (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<MAT_BasicElt> &, const TopoDS_Shape &)) &BRepMAT2d_DataMapOfBasicEltShape::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepMAT2d_DataMapOfBasicEltShape.def("Bound", (TopoDS_Shape * (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<MAT_BasicElt> &, const TopoDS_Shape &)) &BRepMAT2d_DataMapOfBasicEltShape::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("IsBound", (Standard_Boolean (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<MAT_BasicElt> &) const ) &BRepMAT2d_DataMapOfBasicEltShape::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("UnBind", (Standard_Boolean (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<MAT_BasicElt> &)) &BRepMAT2d_DataMapOfBasicEltShape::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepMAT2d_DataMapOfBasicEltShape.def("Seek", (const TopoDS_Shape * (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<MAT_BasicElt> &) const ) &BRepMAT2d_DataMapOfBasicEltShape::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepMAT2d_DataMapOfBasicEltShape.def("Find", (const TopoDS_Shape & (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<MAT_BasicElt> &) const ) &BRepMAT2d_DataMapOfBasicEltShape::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepMAT2d_DataMapOfBasicEltShape.def("Find", (Standard_Boolean (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<MAT_BasicElt> &, TopoDS_Shape &) const ) &BRepMAT2d_DataMapOfBasicEltShape::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("__call__", (const TopoDS_Shape & (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<MAT_BasicElt> &) const ) &BRepMAT2d_DataMapOfBasicEltShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepMAT2d_DataMapOfBasicEltShape.def("ChangeSeek", (TopoDS_Shape * (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<MAT_BasicElt> &)) &BRepMAT2d_DataMapOfBasicEltShape::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("ChangeFind", (TopoDS_Shape & (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<MAT_BasicElt> &)) &BRepMAT2d_DataMapOfBasicEltShape::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("__call__", (TopoDS_Shape & (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<MAT_BasicElt> &)) &BRepMAT2d_DataMapOfBasicEltShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("Clear", [](BRepMAT2d_DataMapOfBasicEltShape &self) -> void { return self.Clear(); });
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("Clear", (void (BRepMAT2d_DataMapOfBasicEltShape::*)(const Standard_Boolean)) &BRepMAT2d_DataMapOfBasicEltShape::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("Clear", (void (BRepMAT2d_DataMapOfBasicEltShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMAT2d_DataMapOfBasicEltShape::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("Size", (Standard_Integer (BRepMAT2d_DataMapOfBasicEltShape::*)() const ) &BRepMAT2d_DataMapOfBasicEltShape::Size, "Size");
	cls_BRepMAT2d_DataMapOfBasicEltShape.def("__iter__", [](const BRepMAT2d_DataMapOfBasicEltShape &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepMAT2d_DataMapOfBasicEltShape.hxx

}
