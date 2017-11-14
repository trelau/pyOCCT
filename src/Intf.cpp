#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Bnd_Box2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <Intf_Polygon2d.hxx>
#include <Intf_PIType.hxx>
#include <gp_Pnt.hxx>
#include <Intf_SectionPoint.hxx>
#include <NCollection_BaseSequence.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Intf_SeqOfSectionPoint.hxx>
#include <Intf_SectionLine.hxx>
#include <Intf_SeqOfSectionLine.hxx>
#include <Intf_TangentZone.hxx>
#include <Intf_SeqOfTangentZone.hxx>
#include <Intf_Interference.hxx>
#include <NCollection_Array1.hxx>
#include <Intf_Array1OfLin.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Lin.hxx>
#include <Bnd_Box.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Intf_Tool.hxx>
#include <Intf_InterferencePolygon2d.hxx>
#include <Intf.hxx>
#include <gp_XYZ.hxx>

PYBIND11_MODULE(Intf, mod) {

	// IMPORT
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_PIType.hxx
	py::enum_<Intf_PIType>(mod, "Intf_PIType", "Describes the different intersection point types for this application.")
		.value("Intf_EXTERNAL", Intf_PIType::Intf_EXTERNAL)
		.value("Intf_FACE", Intf_PIType::Intf_FACE)
		.value("Intf_EDGE", Intf_PIType::Intf_EDGE)
		.value("Intf_VERTEX", Intf_PIType::Intf_VERTEX)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_Polygon2d.hxx
	py::class_<Intf_Polygon2d, std::unique_ptr<Intf_Polygon2d, Deleter<Intf_Polygon2d>>> cls_Intf_Polygon2d(mod, "Intf_Polygon2d", "Describes the necessary polygon information to compute the interferences.");
	cls_Intf_Polygon2d.def("Bounding", (const Bnd_Box2d & (Intf_Polygon2d::*)() const ) &Intf_Polygon2d::Bounding, "Returns the bounding box of the polygon.");
	cls_Intf_Polygon2d.def("Closed", (Standard_Boolean (Intf_Polygon2d::*)() const ) &Intf_Polygon2d::Closed, "Returns True if the polyline is closed.");
	cls_Intf_Polygon2d.def("DeflectionOverEstimation", (Standard_Real (Intf_Polygon2d::*)() const ) &Intf_Polygon2d::DeflectionOverEstimation, "Returns the tolerance of the polygon.");
	cls_Intf_Polygon2d.def("NbSegments", (Standard_Integer (Intf_Polygon2d::*)() const ) &Intf_Polygon2d::NbSegments, "Returns the number of Segments in the polyline.");
	cls_Intf_Polygon2d.def("Segment", (void (Intf_Polygon2d::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt2d &) const ) &Intf_Polygon2d::Segment, "Returns the points of the segment <Index> in the Polygon.", py::arg("theIndex"), py::arg("theBegin"), py::arg("theEnd"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_SectionPoint.hxx
	py::class_<Intf_SectionPoint, std::unique_ptr<Intf_SectionPoint, Deleter<Intf_SectionPoint>>> cls_Intf_SectionPoint(mod, "Intf_SectionPoint", "Describes an intersection point between polygons and polyedra.");
	cls_Intf_SectionPoint.def(py::init<>());
	cls_Intf_SectionPoint.def(py::init<const gp_Pnt &, const Intf_PIType, const Standard_Integer, const Standard_Integer, const Standard_Real, const Intf_PIType, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Where"), py::arg("DimeO"), py::arg("AddrO1"), py::arg("AddrO2"), py::arg("ParamO"), py::arg("DimeT"), py::arg("AddrT1"), py::arg("AddrT2"), py::arg("ParamT"), py::arg("Incid"));
	cls_Intf_SectionPoint.def(py::init<const gp_Pnt2d &, const Intf_PIType, const Standard_Integer, const Standard_Real, const Intf_PIType, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Where"), py::arg("DimeO"), py::arg("AddrO1"), py::arg("ParamO"), py::arg("DimeT"), py::arg("AddrT1"), py::arg("ParamT"), py::arg("Incid"));
	cls_Intf_SectionPoint.def("Pnt", (const gp_Pnt & (Intf_SectionPoint::*)() const ) &Intf_SectionPoint::Pnt, "Returns the location of the SectionPoint.");
	cls_Intf_SectionPoint.def("ParamOnFirst", (Standard_Real (Intf_SectionPoint::*)() const ) &Intf_SectionPoint::ParamOnFirst, "Returns the cumulated Parameter of the SectionPoint on the first element.");
	cls_Intf_SectionPoint.def("ParamOnSecond", (Standard_Real (Intf_SectionPoint::*)() const ) &Intf_SectionPoint::ParamOnSecond, "Returns the cumulated Parameter of the section point on the second element.");
	cls_Intf_SectionPoint.def("TypeOnFirst", (Intf_PIType (Intf_SectionPoint::*)() const ) &Intf_SectionPoint::TypeOnFirst, "Returns the type of the section point on the first element.");
	cls_Intf_SectionPoint.def("TypeOnSecond", (Intf_PIType (Intf_SectionPoint::*)() const ) &Intf_SectionPoint::TypeOnSecond, "Returns the type of the section point on the second element.");
	cls_Intf_SectionPoint.def("InfoFirst", (void (Intf_SectionPoint::*)(Intf_PIType &, Standard_Integer &, Standard_Integer &, Standard_Real &) const ) &Intf_SectionPoint::InfoFirst, "None", py::arg("Dim"), py::arg("Add1"), py::arg("Add2"), py::arg("Param"));
	cls_Intf_SectionPoint.def("InfoFirst", (void (Intf_SectionPoint::*)(Intf_PIType &, Standard_Integer &, Standard_Real &) const ) &Intf_SectionPoint::InfoFirst, "Gives the datas about the first argument of the Interference.", py::arg("Dim"), py::arg("Addr"), py::arg("Param"));
	cls_Intf_SectionPoint.def("InfoSecond", (void (Intf_SectionPoint::*)(Intf_PIType &, Standard_Integer &, Standard_Integer &, Standard_Real &) const ) &Intf_SectionPoint::InfoSecond, "None", py::arg("Dim"), py::arg("Add1"), py::arg("Add2"), py::arg("Param"));
	cls_Intf_SectionPoint.def("InfoSecond", (void (Intf_SectionPoint::*)(Intf_PIType &, Standard_Integer &, Standard_Real &) const ) &Intf_SectionPoint::InfoSecond, "Gives the datas about the second argument of the Interference.", py::arg("Dim"), py::arg("Addr"), py::arg("Param"));
	cls_Intf_SectionPoint.def("Incidence", (Standard_Real (Intf_SectionPoint::*)() const ) &Intf_SectionPoint::Incidence, "Gives the incidence at this section point. The incidence between the two triangles is given by the cosine. The best incidence is 0. (PI/2). The worst is 1. (null angle).");
	cls_Intf_SectionPoint.def("IsEqual", (Standard_Boolean (Intf_SectionPoint::*)(const Intf_SectionPoint &) const ) &Intf_SectionPoint::IsEqual, "Returns True if the two SectionPoint have the same logical informations.", py::arg("Other"));
	cls_Intf_SectionPoint.def("__eq__", (Standard_Boolean (Intf_SectionPoint::*)(const Intf_SectionPoint &) const ) &Intf_SectionPoint::operator==, py::is_operator(), "None", py::arg("Other"));
	cls_Intf_SectionPoint.def("IsOnSameEdge", (Standard_Boolean (Intf_SectionPoint::*)(const Intf_SectionPoint &) const ) &Intf_SectionPoint::IsOnSameEdge, "Returns True if the two SectionPoints are on the same edge of the first or the second element.", py::arg("Other"));
	cls_Intf_SectionPoint.def("Merge", (void (Intf_SectionPoint::*)(Intf_SectionPoint &)) &Intf_SectionPoint::Merge, "Merges two SectionPoints.", py::arg("Other"));
	// FIXME cls_Intf_SectionPoint.def("Dump", (void (Intf_SectionPoint::*)(const Standard_Integer) const ) &Intf_SectionPoint::Dump, "None", py::arg("Indent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_SectionLine.hxx
	py::class_<Intf_SectionLine, std::unique_ptr<Intf_SectionLine, Deleter<Intf_SectionLine>>> cls_Intf_SectionLine(mod, "Intf_SectionLine", "Describe a polyline of intersection between two polyhedra as a sequence of points of intersection.");
	cls_Intf_SectionLine.def(py::init<>());
	cls_Intf_SectionLine.def(py::init([] (const Intf_SectionLine &other) {return new Intf_SectionLine(other);}), "Copy constructor", py::arg("other"));
	cls_Intf_SectionLine.def("NumberOfPoints", (Standard_Integer (Intf_SectionLine::*)() const ) &Intf_SectionLine::NumberOfPoints, "Returns number of points in this SectionLine.");
	cls_Intf_SectionLine.def("GetPoint", (const Intf_SectionPoint & (Intf_SectionLine::*)(const Standard_Integer) const ) &Intf_SectionLine::GetPoint, "Gives the point of intersection of address <Index> in the SectionLine.", py::arg("Index"));
	cls_Intf_SectionLine.def("IsClosed", (Standard_Boolean (Intf_SectionLine::*)() const ) &Intf_SectionLine::IsClosed, "Returns True if the SectionLine is closed.");
	cls_Intf_SectionLine.def("Contains", (Standard_Boolean (Intf_SectionLine::*)(const Intf_SectionPoint &) const ) &Intf_SectionLine::Contains, "Returns True if ThePI is in the SectionLine <me>.", py::arg("ThePI"));
	cls_Intf_SectionLine.def("IsEnd", (Standard_Integer (Intf_SectionLine::*)(const Intf_SectionPoint &) const ) &Intf_SectionLine::IsEnd, "Checks if <ThePI> is an end of the SectionLine. Returns 1 for the beginning, 2 for the end, otherwise 0.", py::arg("ThePI"));
	cls_Intf_SectionLine.def("IsEqual", (Standard_Boolean (Intf_SectionLine::*)(const Intf_SectionLine &) const ) &Intf_SectionLine::IsEqual, "Compares two SectionLines.", py::arg("Other"));
	cls_Intf_SectionLine.def("__eq__", (Standard_Boolean (Intf_SectionLine::*)(const Intf_SectionLine &) const ) &Intf_SectionLine::operator==, py::is_operator(), "None", py::arg("Other"));
	cls_Intf_SectionLine.def("Append", (void (Intf_SectionLine::*)(const Intf_SectionPoint &)) &Intf_SectionLine::Append, "Adds a point at the end of the SectionLine.", py::arg("Pi"));
	cls_Intf_SectionLine.def("Append", (void (Intf_SectionLine::*)(Intf_SectionLine &)) &Intf_SectionLine::Append, "Concatenates the SectionLine <LS> at the end of the SectionLine <me>.", py::arg("LS"));
	cls_Intf_SectionLine.def("Prepend", (void (Intf_SectionLine::*)(const Intf_SectionPoint &)) &Intf_SectionLine::Prepend, "Adds a point to the beginning of the SectionLine <me>.", py::arg("Pi"));
	cls_Intf_SectionLine.def("Prepend", (void (Intf_SectionLine::*)(Intf_SectionLine &)) &Intf_SectionLine::Prepend, "Concatenates a SectionLine <LS> at the beginning of the SectionLine <me>.", py::arg("LS"));
	cls_Intf_SectionLine.def("Reverse", (void (Intf_SectionLine::*)()) &Intf_SectionLine::Reverse, "Reverses the order of the elements of the SectionLine.");
	cls_Intf_SectionLine.def("Close", (void (Intf_SectionLine::*)()) &Intf_SectionLine::Close, "Closes the SectionLine.");
	// FIXME cls_Intf_SectionLine.def("Dump", (void (Intf_SectionLine::*)(const Standard_Integer) const ) &Intf_SectionLine::Dump, "None", py::arg("Indent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_TangentZone.hxx
	py::class_<Intf_TangentZone, std::unique_ptr<Intf_TangentZone, Deleter<Intf_TangentZone>>> cls_Intf_TangentZone(mod, "Intf_TangentZone", "Describes a zone of tangence between polygons or polyhedra as a sequence of points of intersection.");
	cls_Intf_TangentZone.def(py::init<>());
	cls_Intf_TangentZone.def(py::init([] (const Intf_TangentZone &other) {return new Intf_TangentZone(other);}), "Copy constructor", py::arg("other"));
	cls_Intf_TangentZone.def("NumberOfPoints", (Standard_Integer (Intf_TangentZone::*)() const ) &Intf_TangentZone::NumberOfPoints, "Returns number of SectionPoint in this TangentZone.");
	cls_Intf_TangentZone.def("GetPoint", (const Intf_SectionPoint & (Intf_TangentZone::*)(const Standard_Integer) const ) &Intf_TangentZone::GetPoint, "Gives the SectionPoint of address <Index> in the TangentZone.", py::arg("Index"));
	cls_Intf_TangentZone.def("IsEqual", (Standard_Boolean (Intf_TangentZone::*)(const Intf_TangentZone &) const ) &Intf_TangentZone::IsEqual, "Compares two TangentZones.", py::arg("Other"));
	cls_Intf_TangentZone.def("__eq__", (Standard_Boolean (Intf_TangentZone::*)(const Intf_TangentZone &) const ) &Intf_TangentZone::operator==, py::is_operator(), "None", py::arg("Other"));
	cls_Intf_TangentZone.def("Contains", (Standard_Boolean (Intf_TangentZone::*)(const Intf_SectionPoint &) const ) &Intf_TangentZone::Contains, "Checks if <ThePI> is in TangentZone.", py::arg("ThePI"));
	cls_Intf_TangentZone.def("ParamOnFirst", (void (Intf_TangentZone::*)(Standard_Real &, Standard_Real &) const ) &Intf_TangentZone::ParamOnFirst, "Gives the parameter range of the TangentZone on the first argument of the Interference. (Usable only for polygon)", py::arg("paraMin"), py::arg("paraMax"));
	cls_Intf_TangentZone.def("ParamOnSecond", (void (Intf_TangentZone::*)(Standard_Real &, Standard_Real &) const ) &Intf_TangentZone::ParamOnSecond, "Gives the parameter range of the TangentZone on the second argument of the Interference. (Usable only for polygon)", py::arg("paraMin"), py::arg("paraMax"));
	cls_Intf_TangentZone.def("InfoFirst", (void (Intf_TangentZone::*)(Standard_Integer &, Standard_Real &, Standard_Integer &, Standard_Real &) const ) &Intf_TangentZone::InfoFirst, "Gives information about the first argument of the Interference. (Usable only for polygon)", py::arg("segMin"), py::arg("paraMin"), py::arg("segMax"), py::arg("paraMax"));
	cls_Intf_TangentZone.def("InfoSecond", (void (Intf_TangentZone::*)(Standard_Integer &, Standard_Real &, Standard_Integer &, Standard_Real &) const ) &Intf_TangentZone::InfoSecond, "Gives informations about the second argument of the Interference. (Usable only for polygon)", py::arg("segMin"), py::arg("paraMin"), py::arg("segMax"), py::arg("paraMax"));
	cls_Intf_TangentZone.def("RangeContains", (Standard_Boolean (Intf_TangentZone::*)(const Intf_SectionPoint &) const ) &Intf_TangentZone::RangeContains, "Returns True if <ThePI> is in the parameter range of the TangentZone.", py::arg("ThePI"));
	cls_Intf_TangentZone.def("HasCommonRange", (Standard_Boolean (Intf_TangentZone::*)(const Intf_TangentZone &) const ) &Intf_TangentZone::HasCommonRange, "Returns True if the TangentZone <Other> has a common part with <me>.", py::arg("Other"));
	cls_Intf_TangentZone.def("Append", (void (Intf_TangentZone::*)(const Intf_SectionPoint &)) &Intf_TangentZone::Append, "Adds a SectionPoint to the TangentZone.", py::arg("Pi"));
	cls_Intf_TangentZone.def("Append", (void (Intf_TangentZone::*)(const Intf_TangentZone &)) &Intf_TangentZone::Append, "Adds the TangentZone <Tzi> to <me>.", py::arg("Tzi"));
	cls_Intf_TangentZone.def("Insert", (Standard_Boolean (Intf_TangentZone::*)(const Intf_SectionPoint &)) &Intf_TangentZone::Insert, "Inserts a SectionPoint in the TangentZone.", py::arg("Pi"));
	cls_Intf_TangentZone.def("PolygonInsert", (void (Intf_TangentZone::*)(const Intf_SectionPoint &)) &Intf_TangentZone::PolygonInsert, "Inserts a point in the polygonal TangentZone.", py::arg("Pi"));
	cls_Intf_TangentZone.def("InsertBefore", (void (Intf_TangentZone::*)(const Standard_Integer, const Intf_SectionPoint &)) &Intf_TangentZone::InsertBefore, "Inserts a SectionPoint before <Index> in the TangentZone.", py::arg("Index"), py::arg("Pi"));
	cls_Intf_TangentZone.def("InsertAfter", (void (Intf_TangentZone::*)(const Standard_Integer, const Intf_SectionPoint &)) &Intf_TangentZone::InsertAfter, "Inserts a SectionPoint after <Index> in the TangentZone.", py::arg("Index"), py::arg("Pi"));
	// FIXME cls_Intf_TangentZone.def("Dump", (void (Intf_TangentZone::*)(const Standard_Integer) const ) &Intf_TangentZone::Dump, "None", py::arg("Indent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_Interference.hxx
	py::class_<Intf_Interference, std::unique_ptr<Intf_Interference, py::nodelete>> cls_Intf_Interference(mod, "Intf_Interference", "Describes the Interference computation result between polygon2d or polygon3d or polyhedron (as three sequences of points of intersection, polylines of intersection and zones de tangence).");
	cls_Intf_Interference.def("NbSectionPoints", (Standard_Integer (Intf_Interference::*)() const ) &Intf_Interference::NbSectionPoints, "Gives the number of points of intersection in the interference.");
	cls_Intf_Interference.def("PntValue", (const Intf_SectionPoint & (Intf_Interference::*)(const Standard_Integer) const ) &Intf_Interference::PntValue, "Gives the point of intersection of address Index in the interference.", py::arg("Index"));
	cls_Intf_Interference.def("NbSectionLines", (Standard_Integer (Intf_Interference::*)() const ) &Intf_Interference::NbSectionLines, "Gives the number of polylines of intersection in the interference.");
	cls_Intf_Interference.def("LineValue", (const Intf_SectionLine & (Intf_Interference::*)(const Standard_Integer) const ) &Intf_Interference::LineValue, "Gives the polyline of intersection at address <Index> in the interference.", py::arg("Index"));
	cls_Intf_Interference.def("NbTangentZones", (Standard_Integer (Intf_Interference::*)() const ) &Intf_Interference::NbTangentZones, "Gives the number of zones of tangence in the interference.");
	cls_Intf_Interference.def("ZoneValue", (const Intf_TangentZone & (Intf_Interference::*)(const Standard_Integer) const ) &Intf_Interference::ZoneValue, "Gives the zone of tangence at address Index in the interference.", py::arg("Index"));
	cls_Intf_Interference.def("GetTolerance", (Standard_Real (Intf_Interference::*)() const ) &Intf_Interference::GetTolerance, "Gives the tolerance used for the calculation.");
	cls_Intf_Interference.def("Contains", (Standard_Boolean (Intf_Interference::*)(const Intf_SectionPoint &) const ) &Intf_Interference::Contains, "Tests if the polylines of intersection or the zones of tangence contain the point of intersection <ThePnt>.", py::arg("ThePnt"));
	cls_Intf_Interference.def("Insert", (Standard_Boolean (Intf_Interference::*)(const Intf_TangentZone &)) &Intf_Interference::Insert, "Inserts a new zone of tangence in the current list of tangent zones of the interference and returns True when done.", py::arg("TheZone"));
	cls_Intf_Interference.def("Insert", (void (Intf_Interference::*)(const Intf_SectionPoint &, const Intf_SectionPoint &)) &Intf_Interference::Insert, "Insert a new segment of intersection in the current list of polylines of intersection of the interference.", py::arg("pdeb"), py::arg("pfin"));
	// FIXME cls_Intf_Interference.def("Dump", (void (Intf_Interference::*)() const ) &Intf_Interference::Dump, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_Tool.hxx
	py::class_<Intf_Tool, std::unique_ptr<Intf_Tool, Deleter<Intf_Tool>>> cls_Intf_Tool(mod, "Intf_Tool", "Provides services to create box for infinites lines in a given contexte.");
	cls_Intf_Tool.def(py::init<>());
	cls_Intf_Tool.def("Lin2dBox", (void (Intf_Tool::*)(const gp_Lin2d &, const Bnd_Box2d &, Bnd_Box2d &)) &Intf_Tool::Lin2dBox, "None", py::arg("theLin2d"), py::arg("bounding"), py::arg("boxLin"));
	cls_Intf_Tool.def("Hypr2dBox", (void (Intf_Tool::*)(const gp_Hypr2d &, const Bnd_Box2d &, Bnd_Box2d &)) &Intf_Tool::Hypr2dBox, "None", py::arg("theHypr2d"), py::arg("bounding"), py::arg("boxHypr"));
	cls_Intf_Tool.def("Parab2dBox", (void (Intf_Tool::*)(const gp_Parab2d &, const Bnd_Box2d &, Bnd_Box2d &)) &Intf_Tool::Parab2dBox, "None", py::arg("theParab2d"), py::arg("bounding"), py::arg("boxHypr"));
	cls_Intf_Tool.def("LinBox", (void (Intf_Tool::*)(const gp_Lin &, const Bnd_Box &, Bnd_Box &)) &Intf_Tool::LinBox, "None", py::arg("theLin"), py::arg("bounding"), py::arg("boxLin"));
	cls_Intf_Tool.def("HyprBox", (void (Intf_Tool::*)(const gp_Hypr &, const Bnd_Box &, Bnd_Box &)) &Intf_Tool::HyprBox, "None", py::arg("theHypr"), py::arg("bounding"), py::arg("boxHypr"));
	cls_Intf_Tool.def("ParabBox", (void (Intf_Tool::*)(const gp_Parab &, const Bnd_Box &, Bnd_Box &)) &Intf_Tool::ParabBox, "None", py::arg("theParab"), py::arg("bounding"), py::arg("boxHypr"));
	cls_Intf_Tool.def("NbSegments", (Standard_Integer (Intf_Tool::*)() const ) &Intf_Tool::NbSegments, "None");
	cls_Intf_Tool.def("BeginParam", (Standard_Real (Intf_Tool::*)(const Standard_Integer) const ) &Intf_Tool::BeginParam, "None", py::arg("SegmentNum"));
	cls_Intf_Tool.def("EndParam", (Standard_Real (Intf_Tool::*)(const Standard_Integer) const ) &Intf_Tool::EndParam, "None", py::arg("SegmentNum"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_InterferencePolygon2d.hxx
	py::class_<Intf_InterferencePolygon2d, std::unique_ptr<Intf_InterferencePolygon2d, Deleter<Intf_InterferencePolygon2d>>, Intf_Interference> cls_Intf_InterferencePolygon2d(mod, "Intf_InterferencePolygon2d", "Computes the interference between two polygons or the self intersection of a polygon in two dimensions.");
	cls_Intf_InterferencePolygon2d.def(py::init<>());
	cls_Intf_InterferencePolygon2d.def(py::init<const Intf_Polygon2d &, const Intf_Polygon2d &>(), py::arg("Obje1"), py::arg("Obje2"));
	cls_Intf_InterferencePolygon2d.def(py::init<const Intf_Polygon2d &>(), py::arg("Obje"));
	cls_Intf_InterferencePolygon2d.def("Perform", (void (Intf_InterferencePolygon2d::*)(const Intf_Polygon2d &, const Intf_Polygon2d &)) &Intf_InterferencePolygon2d::Perform, "Computes an interference between two Polygons.", py::arg("Obje1"), py::arg("Obje2"));
	cls_Intf_InterferencePolygon2d.def("Perform", (void (Intf_InterferencePolygon2d::*)(const Intf_Polygon2d &)) &Intf_InterferencePolygon2d::Perform, "Computes the self interference of a Polygon.", py::arg("Obje"));
	cls_Intf_InterferencePolygon2d.def("Pnt2dValue", (gp_Pnt2d (Intf_InterferencePolygon2d::*)(const Standard_Integer) const ) &Intf_InterferencePolygon2d::Pnt2dValue, "Gives the geometrical 2d point of the intersection point at address <Index> in the interference.", py::arg("Index"));

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf.hxx
	py::class_<Intf_InterferencePolygonPolyhedron, std::unique_ptr<Intf_InterferencePolygonPolyhedron, Deleter<Intf_InterferencePolygonPolyhedron>>> cls_Intf_InterferencePolygonPolyhedron(mod, "Intf_InterferencePolygonPolyhedron", "None");
	cls_Intf_InterferencePolygonPolyhedron.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf.hxx
	py::class_<Intf, std::unique_ptr<Intf, Deleter<Intf>>> cls_Intf(mod, "Intf", "Interference computation between polygons, lines and polyhedra with only triangular facets. These objects are polygonal representations of complex curves and triangulated representations of complex surfaces.");
	cls_Intf.def(py::init<>());
	cls_Intf.def_static("PlaneEquation_", (void (*)(const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, gp_XYZ &, Standard_Real &)) &Intf::PlaneEquation, "Computes the interference between two polygons in 2d. Result : points of intersections and zones of tangence. Computes the interference between a polygon or a straight line and a polyhedron. Points of intersection and zones of tangence. Give the plane equation of the triangle <P1> <P2> <P3>.", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("NormalVector"), py::arg("PolarDistance"));
	cls_Intf.def_static("Contain_", (Standard_Boolean (*)(const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &Intf::Contain, "Compute if the triangle <P1> <P2> <P3> contain <ThePnt>.", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("ThePnt"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<Intf_SeqOfSectionPoint, std::unique_ptr<Intf_SeqOfSectionPoint, Deleter<Intf_SeqOfSectionPoint>>, NCollection_BaseSequence> cls_Intf_SeqOfSectionPoint(mod, "Intf_SeqOfSectionPoint", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_Intf_SeqOfSectionPoint.def(py::init<>());
	cls_Intf_SeqOfSectionPoint.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Intf_SeqOfSectionPoint.def(py::init([] (const Intf_SeqOfSectionPoint &other) {return new Intf_SeqOfSectionPoint(other);}), "Copy constructor", py::arg("other"));
	cls_Intf_SeqOfSectionPoint.def("begin", (Intf_SeqOfSectionPoint::iterator (Intf_SeqOfSectionPoint::*)() const ) &Intf_SeqOfSectionPoint::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_Intf_SeqOfSectionPoint.def("end", (Intf_SeqOfSectionPoint::iterator (Intf_SeqOfSectionPoint::*)() const ) &Intf_SeqOfSectionPoint::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_Intf_SeqOfSectionPoint.def("cbegin", (Intf_SeqOfSectionPoint::const_iterator (Intf_SeqOfSectionPoint::*)() const ) &Intf_SeqOfSectionPoint::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_Intf_SeqOfSectionPoint.def("cend", (Intf_SeqOfSectionPoint::const_iterator (Intf_SeqOfSectionPoint::*)() const ) &Intf_SeqOfSectionPoint::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_Intf_SeqOfSectionPoint.def("Size", (Standard_Integer (Intf_SeqOfSectionPoint::*)() const ) &Intf_SeqOfSectionPoint::Size, "Number of items");
	cls_Intf_SeqOfSectionPoint.def("Length", (Standard_Integer (Intf_SeqOfSectionPoint::*)() const ) &Intf_SeqOfSectionPoint::Length, "Number of items");
	cls_Intf_SeqOfSectionPoint.def("Lower", (Standard_Integer (Intf_SeqOfSectionPoint::*)() const ) &Intf_SeqOfSectionPoint::Lower, "Method for consistency with other collections.");
	cls_Intf_SeqOfSectionPoint.def("Upper", (Standard_Integer (Intf_SeqOfSectionPoint::*)() const ) &Intf_SeqOfSectionPoint::Upper, "Method for consistency with other collections.");
	cls_Intf_SeqOfSectionPoint.def("IsEmpty", (Standard_Boolean (Intf_SeqOfSectionPoint::*)() const ) &Intf_SeqOfSectionPoint::IsEmpty, "Empty query");
	cls_Intf_SeqOfSectionPoint.def("Reverse", (void (Intf_SeqOfSectionPoint::*)()) &Intf_SeqOfSectionPoint::Reverse, "Reverse sequence");
	cls_Intf_SeqOfSectionPoint.def("Exchange", (void (Intf_SeqOfSectionPoint::*)(const Standard_Integer, const Standard_Integer)) &Intf_SeqOfSectionPoint::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_Intf_SeqOfSectionPoint.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &Intf_SeqOfSectionPoint::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_Intf_SeqOfSectionPoint.def("Clear", [](Intf_SeqOfSectionPoint &self) -> void { return self.Clear(); });
	cls_Intf_SeqOfSectionPoint.def("Clear", (void (Intf_SeqOfSectionPoint::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Intf_SeqOfSectionPoint::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_Intf_SeqOfSectionPoint.def("Assign", (Intf_SeqOfSectionPoint & (Intf_SeqOfSectionPoint::*)(const Intf_SeqOfSectionPoint &)) &Intf_SeqOfSectionPoint::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Intf_SeqOfSectionPoint.def("assign", (Intf_SeqOfSectionPoint & (Intf_SeqOfSectionPoint::*)(const Intf_SeqOfSectionPoint &)) &Intf_SeqOfSectionPoint::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Intf_SeqOfSectionPoint.def("Remove", (void (Intf_SeqOfSectionPoint::*)(Intf_SeqOfSectionPoint::Iterator &)) &Intf_SeqOfSectionPoint::Remove, "Remove one item", py::arg("thePosition"));
	cls_Intf_SeqOfSectionPoint.def("Remove", (void (Intf_SeqOfSectionPoint::*)(const Standard_Integer)) &Intf_SeqOfSectionPoint::Remove, "Remove one item", py::arg("theIndex"));
	cls_Intf_SeqOfSectionPoint.def("Remove", (void (Intf_SeqOfSectionPoint::*)(const Standard_Integer, const Standard_Integer)) &Intf_SeqOfSectionPoint::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_Intf_SeqOfSectionPoint.def("Append", (void (Intf_SeqOfSectionPoint::*)(const Intf_SectionPoint &)) &Intf_SeqOfSectionPoint::Append, "Append one item", py::arg("theItem"));
	cls_Intf_SeqOfSectionPoint.def("Append", (void (Intf_SeqOfSectionPoint::*)(Intf_SeqOfSectionPoint &)) &Intf_SeqOfSectionPoint::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_Intf_SeqOfSectionPoint.def("Prepend", (void (Intf_SeqOfSectionPoint::*)(const Intf_SectionPoint &)) &Intf_SeqOfSectionPoint::Prepend, "Prepend one item", py::arg("theItem"));
	cls_Intf_SeqOfSectionPoint.def("Prepend", (void (Intf_SeqOfSectionPoint::*)(Intf_SeqOfSectionPoint &)) &Intf_SeqOfSectionPoint::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_Intf_SeqOfSectionPoint.def("InsertBefore", (void (Intf_SeqOfSectionPoint::*)(const Standard_Integer, const Intf_SectionPoint &)) &Intf_SeqOfSectionPoint::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_Intf_SeqOfSectionPoint.def("InsertBefore", (void (Intf_SeqOfSectionPoint::*)(const Standard_Integer, Intf_SeqOfSectionPoint &)) &Intf_SeqOfSectionPoint::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intf_SeqOfSectionPoint.def("InsertAfter", (void (Intf_SeqOfSectionPoint::*)(Intf_SeqOfSectionPoint::Iterator &, const Intf_SectionPoint &)) &Intf_SeqOfSectionPoint::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_Intf_SeqOfSectionPoint.def("InsertAfter", (void (Intf_SeqOfSectionPoint::*)(const Standard_Integer, Intf_SeqOfSectionPoint &)) &Intf_SeqOfSectionPoint::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intf_SeqOfSectionPoint.def("InsertAfter", (void (Intf_SeqOfSectionPoint::*)(const Standard_Integer, const Intf_SectionPoint &)) &Intf_SeqOfSectionPoint::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_Intf_SeqOfSectionPoint.def("Split", (void (Intf_SeqOfSectionPoint::*)(const Standard_Integer, Intf_SeqOfSectionPoint &)) &Intf_SeqOfSectionPoint::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intf_SeqOfSectionPoint.def("First", (const Intf_SectionPoint & (Intf_SeqOfSectionPoint::*)() const ) &Intf_SeqOfSectionPoint::First, "First item access");
	cls_Intf_SeqOfSectionPoint.def("ChangeFirst", (Intf_SectionPoint & (Intf_SeqOfSectionPoint::*)()) &Intf_SeqOfSectionPoint::ChangeFirst, "First item access");
	cls_Intf_SeqOfSectionPoint.def("Last", (const Intf_SectionPoint & (Intf_SeqOfSectionPoint::*)() const ) &Intf_SeqOfSectionPoint::Last, "Last item access");
	cls_Intf_SeqOfSectionPoint.def("ChangeLast", (Intf_SectionPoint & (Intf_SeqOfSectionPoint::*)()) &Intf_SeqOfSectionPoint::ChangeLast, "Last item access");
	cls_Intf_SeqOfSectionPoint.def("Value", (const Intf_SectionPoint & (Intf_SeqOfSectionPoint::*)(const Standard_Integer) const ) &Intf_SeqOfSectionPoint::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_Intf_SeqOfSectionPoint.def("__call__", (const Intf_SectionPoint & (Intf_SeqOfSectionPoint::*)(const Standard_Integer) const ) &Intf_SeqOfSectionPoint::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_Intf_SeqOfSectionPoint.def("ChangeValue", (Intf_SectionPoint & (Intf_SeqOfSectionPoint::*)(const Standard_Integer)) &Intf_SeqOfSectionPoint::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_Intf_SeqOfSectionPoint.def("__call__", (Intf_SectionPoint & (Intf_SeqOfSectionPoint::*)(const Standard_Integer)) &Intf_SeqOfSectionPoint::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_Intf_SeqOfSectionPoint.def("SetValue", (void (Intf_SeqOfSectionPoint::*)(const Standard_Integer, const Intf_SectionPoint &)) &Intf_SeqOfSectionPoint::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_Intf_SeqOfSectionPoint.def("__iter__", [](const Intf_SeqOfSectionPoint &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<Intf_SeqOfSectionLine, std::unique_ptr<Intf_SeqOfSectionLine, Deleter<Intf_SeqOfSectionLine>>, NCollection_BaseSequence> cls_Intf_SeqOfSectionLine(mod, "Intf_SeqOfSectionLine", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_Intf_SeqOfSectionLine.def(py::init<>());
	cls_Intf_SeqOfSectionLine.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Intf_SeqOfSectionLine.def(py::init([] (const Intf_SeqOfSectionLine &other) {return new Intf_SeqOfSectionLine(other);}), "Copy constructor", py::arg("other"));
	cls_Intf_SeqOfSectionLine.def("begin", (Intf_SeqOfSectionLine::iterator (Intf_SeqOfSectionLine::*)() const ) &Intf_SeqOfSectionLine::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_Intf_SeqOfSectionLine.def("end", (Intf_SeqOfSectionLine::iterator (Intf_SeqOfSectionLine::*)() const ) &Intf_SeqOfSectionLine::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_Intf_SeqOfSectionLine.def("cbegin", (Intf_SeqOfSectionLine::const_iterator (Intf_SeqOfSectionLine::*)() const ) &Intf_SeqOfSectionLine::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_Intf_SeqOfSectionLine.def("cend", (Intf_SeqOfSectionLine::const_iterator (Intf_SeqOfSectionLine::*)() const ) &Intf_SeqOfSectionLine::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_Intf_SeqOfSectionLine.def("Size", (Standard_Integer (Intf_SeqOfSectionLine::*)() const ) &Intf_SeqOfSectionLine::Size, "Number of items");
	cls_Intf_SeqOfSectionLine.def("Length", (Standard_Integer (Intf_SeqOfSectionLine::*)() const ) &Intf_SeqOfSectionLine::Length, "Number of items");
	cls_Intf_SeqOfSectionLine.def("Lower", (Standard_Integer (Intf_SeqOfSectionLine::*)() const ) &Intf_SeqOfSectionLine::Lower, "Method for consistency with other collections.");
	cls_Intf_SeqOfSectionLine.def("Upper", (Standard_Integer (Intf_SeqOfSectionLine::*)() const ) &Intf_SeqOfSectionLine::Upper, "Method for consistency with other collections.");
	cls_Intf_SeqOfSectionLine.def("IsEmpty", (Standard_Boolean (Intf_SeqOfSectionLine::*)() const ) &Intf_SeqOfSectionLine::IsEmpty, "Empty query");
	cls_Intf_SeqOfSectionLine.def("Reverse", (void (Intf_SeqOfSectionLine::*)()) &Intf_SeqOfSectionLine::Reverse, "Reverse sequence");
	cls_Intf_SeqOfSectionLine.def("Exchange", (void (Intf_SeqOfSectionLine::*)(const Standard_Integer, const Standard_Integer)) &Intf_SeqOfSectionLine::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_Intf_SeqOfSectionLine.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &Intf_SeqOfSectionLine::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_Intf_SeqOfSectionLine.def("Clear", [](Intf_SeqOfSectionLine &self) -> void { return self.Clear(); });
	cls_Intf_SeqOfSectionLine.def("Clear", (void (Intf_SeqOfSectionLine::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Intf_SeqOfSectionLine::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_Intf_SeqOfSectionLine.def("Assign", (Intf_SeqOfSectionLine & (Intf_SeqOfSectionLine::*)(const Intf_SeqOfSectionLine &)) &Intf_SeqOfSectionLine::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Intf_SeqOfSectionLine.def("assign", (Intf_SeqOfSectionLine & (Intf_SeqOfSectionLine::*)(const Intf_SeqOfSectionLine &)) &Intf_SeqOfSectionLine::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Intf_SeqOfSectionLine.def("Remove", (void (Intf_SeqOfSectionLine::*)(Intf_SeqOfSectionLine::Iterator &)) &Intf_SeqOfSectionLine::Remove, "Remove one item", py::arg("thePosition"));
	cls_Intf_SeqOfSectionLine.def("Remove", (void (Intf_SeqOfSectionLine::*)(const Standard_Integer)) &Intf_SeqOfSectionLine::Remove, "Remove one item", py::arg("theIndex"));
	cls_Intf_SeqOfSectionLine.def("Remove", (void (Intf_SeqOfSectionLine::*)(const Standard_Integer, const Standard_Integer)) &Intf_SeqOfSectionLine::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_Intf_SeqOfSectionLine.def("Append", (void (Intf_SeqOfSectionLine::*)(const Intf_SectionLine &)) &Intf_SeqOfSectionLine::Append, "Append one item", py::arg("theItem"));
	cls_Intf_SeqOfSectionLine.def("Append", (void (Intf_SeqOfSectionLine::*)(Intf_SeqOfSectionLine &)) &Intf_SeqOfSectionLine::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_Intf_SeqOfSectionLine.def("Prepend", (void (Intf_SeqOfSectionLine::*)(const Intf_SectionLine &)) &Intf_SeqOfSectionLine::Prepend, "Prepend one item", py::arg("theItem"));
	cls_Intf_SeqOfSectionLine.def("Prepend", (void (Intf_SeqOfSectionLine::*)(Intf_SeqOfSectionLine &)) &Intf_SeqOfSectionLine::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_Intf_SeqOfSectionLine.def("InsertBefore", (void (Intf_SeqOfSectionLine::*)(const Standard_Integer, const Intf_SectionLine &)) &Intf_SeqOfSectionLine::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_Intf_SeqOfSectionLine.def("InsertBefore", (void (Intf_SeqOfSectionLine::*)(const Standard_Integer, Intf_SeqOfSectionLine &)) &Intf_SeqOfSectionLine::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intf_SeqOfSectionLine.def("InsertAfter", (void (Intf_SeqOfSectionLine::*)(Intf_SeqOfSectionLine::Iterator &, const Intf_SectionLine &)) &Intf_SeqOfSectionLine::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_Intf_SeqOfSectionLine.def("InsertAfter", (void (Intf_SeqOfSectionLine::*)(const Standard_Integer, Intf_SeqOfSectionLine &)) &Intf_SeqOfSectionLine::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intf_SeqOfSectionLine.def("InsertAfter", (void (Intf_SeqOfSectionLine::*)(const Standard_Integer, const Intf_SectionLine &)) &Intf_SeqOfSectionLine::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_Intf_SeqOfSectionLine.def("Split", (void (Intf_SeqOfSectionLine::*)(const Standard_Integer, Intf_SeqOfSectionLine &)) &Intf_SeqOfSectionLine::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intf_SeqOfSectionLine.def("First", (const Intf_SectionLine & (Intf_SeqOfSectionLine::*)() const ) &Intf_SeqOfSectionLine::First, "First item access");
	cls_Intf_SeqOfSectionLine.def("ChangeFirst", (Intf_SectionLine & (Intf_SeqOfSectionLine::*)()) &Intf_SeqOfSectionLine::ChangeFirst, "First item access");
	cls_Intf_SeqOfSectionLine.def("Last", (const Intf_SectionLine & (Intf_SeqOfSectionLine::*)() const ) &Intf_SeqOfSectionLine::Last, "Last item access");
	cls_Intf_SeqOfSectionLine.def("ChangeLast", (Intf_SectionLine & (Intf_SeqOfSectionLine::*)()) &Intf_SeqOfSectionLine::ChangeLast, "Last item access");
	cls_Intf_SeqOfSectionLine.def("Value", (const Intf_SectionLine & (Intf_SeqOfSectionLine::*)(const Standard_Integer) const ) &Intf_SeqOfSectionLine::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_Intf_SeqOfSectionLine.def("__call__", (const Intf_SectionLine & (Intf_SeqOfSectionLine::*)(const Standard_Integer) const ) &Intf_SeqOfSectionLine::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_Intf_SeqOfSectionLine.def("ChangeValue", (Intf_SectionLine & (Intf_SeqOfSectionLine::*)(const Standard_Integer)) &Intf_SeqOfSectionLine::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_Intf_SeqOfSectionLine.def("__call__", (Intf_SectionLine & (Intf_SeqOfSectionLine::*)(const Standard_Integer)) &Intf_SeqOfSectionLine::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_Intf_SeqOfSectionLine.def("SetValue", (void (Intf_SeqOfSectionLine::*)(const Standard_Integer, const Intf_SectionLine &)) &Intf_SeqOfSectionLine::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_Intf_SeqOfSectionLine.def("__iter__", [](const Intf_SeqOfSectionLine &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<Intf_SeqOfTangentZone, std::unique_ptr<Intf_SeqOfTangentZone, Deleter<Intf_SeqOfTangentZone>>, NCollection_BaseSequence> cls_Intf_SeqOfTangentZone(mod, "Intf_SeqOfTangentZone", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_Intf_SeqOfTangentZone.def(py::init<>());
	cls_Intf_SeqOfTangentZone.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Intf_SeqOfTangentZone.def(py::init([] (const Intf_SeqOfTangentZone &other) {return new Intf_SeqOfTangentZone(other);}), "Copy constructor", py::arg("other"));
	cls_Intf_SeqOfTangentZone.def("begin", (Intf_SeqOfTangentZone::iterator (Intf_SeqOfTangentZone::*)() const ) &Intf_SeqOfTangentZone::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_Intf_SeqOfTangentZone.def("end", (Intf_SeqOfTangentZone::iterator (Intf_SeqOfTangentZone::*)() const ) &Intf_SeqOfTangentZone::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_Intf_SeqOfTangentZone.def("cbegin", (Intf_SeqOfTangentZone::const_iterator (Intf_SeqOfTangentZone::*)() const ) &Intf_SeqOfTangentZone::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_Intf_SeqOfTangentZone.def("cend", (Intf_SeqOfTangentZone::const_iterator (Intf_SeqOfTangentZone::*)() const ) &Intf_SeqOfTangentZone::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_Intf_SeqOfTangentZone.def("Size", (Standard_Integer (Intf_SeqOfTangentZone::*)() const ) &Intf_SeqOfTangentZone::Size, "Number of items");
	cls_Intf_SeqOfTangentZone.def("Length", (Standard_Integer (Intf_SeqOfTangentZone::*)() const ) &Intf_SeqOfTangentZone::Length, "Number of items");
	cls_Intf_SeqOfTangentZone.def("Lower", (Standard_Integer (Intf_SeqOfTangentZone::*)() const ) &Intf_SeqOfTangentZone::Lower, "Method for consistency with other collections.");
	cls_Intf_SeqOfTangentZone.def("Upper", (Standard_Integer (Intf_SeqOfTangentZone::*)() const ) &Intf_SeqOfTangentZone::Upper, "Method for consistency with other collections.");
	cls_Intf_SeqOfTangentZone.def("IsEmpty", (Standard_Boolean (Intf_SeqOfTangentZone::*)() const ) &Intf_SeqOfTangentZone::IsEmpty, "Empty query");
	cls_Intf_SeqOfTangentZone.def("Reverse", (void (Intf_SeqOfTangentZone::*)()) &Intf_SeqOfTangentZone::Reverse, "Reverse sequence");
	cls_Intf_SeqOfTangentZone.def("Exchange", (void (Intf_SeqOfTangentZone::*)(const Standard_Integer, const Standard_Integer)) &Intf_SeqOfTangentZone::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_Intf_SeqOfTangentZone.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &Intf_SeqOfTangentZone::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_Intf_SeqOfTangentZone.def("Clear", [](Intf_SeqOfTangentZone &self) -> void { return self.Clear(); });
	cls_Intf_SeqOfTangentZone.def("Clear", (void (Intf_SeqOfTangentZone::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Intf_SeqOfTangentZone::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_Intf_SeqOfTangentZone.def("Assign", (Intf_SeqOfTangentZone & (Intf_SeqOfTangentZone::*)(const Intf_SeqOfTangentZone &)) &Intf_SeqOfTangentZone::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Intf_SeqOfTangentZone.def("assign", (Intf_SeqOfTangentZone & (Intf_SeqOfTangentZone::*)(const Intf_SeqOfTangentZone &)) &Intf_SeqOfTangentZone::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Intf_SeqOfTangentZone.def("Remove", (void (Intf_SeqOfTangentZone::*)(Intf_SeqOfTangentZone::Iterator &)) &Intf_SeqOfTangentZone::Remove, "Remove one item", py::arg("thePosition"));
	cls_Intf_SeqOfTangentZone.def("Remove", (void (Intf_SeqOfTangentZone::*)(const Standard_Integer)) &Intf_SeqOfTangentZone::Remove, "Remove one item", py::arg("theIndex"));
	cls_Intf_SeqOfTangentZone.def("Remove", (void (Intf_SeqOfTangentZone::*)(const Standard_Integer, const Standard_Integer)) &Intf_SeqOfTangentZone::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_Intf_SeqOfTangentZone.def("Append", (void (Intf_SeqOfTangentZone::*)(const Intf_TangentZone &)) &Intf_SeqOfTangentZone::Append, "Append one item", py::arg("theItem"));
	cls_Intf_SeqOfTangentZone.def("Append", (void (Intf_SeqOfTangentZone::*)(Intf_SeqOfTangentZone &)) &Intf_SeqOfTangentZone::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_Intf_SeqOfTangentZone.def("Prepend", (void (Intf_SeqOfTangentZone::*)(const Intf_TangentZone &)) &Intf_SeqOfTangentZone::Prepend, "Prepend one item", py::arg("theItem"));
	cls_Intf_SeqOfTangentZone.def("Prepend", (void (Intf_SeqOfTangentZone::*)(Intf_SeqOfTangentZone &)) &Intf_SeqOfTangentZone::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_Intf_SeqOfTangentZone.def("InsertBefore", (void (Intf_SeqOfTangentZone::*)(const Standard_Integer, const Intf_TangentZone &)) &Intf_SeqOfTangentZone::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_Intf_SeqOfTangentZone.def("InsertBefore", (void (Intf_SeqOfTangentZone::*)(const Standard_Integer, Intf_SeqOfTangentZone &)) &Intf_SeqOfTangentZone::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intf_SeqOfTangentZone.def("InsertAfter", (void (Intf_SeqOfTangentZone::*)(Intf_SeqOfTangentZone::Iterator &, const Intf_TangentZone &)) &Intf_SeqOfTangentZone::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_Intf_SeqOfTangentZone.def("InsertAfter", (void (Intf_SeqOfTangentZone::*)(const Standard_Integer, Intf_SeqOfTangentZone &)) &Intf_SeqOfTangentZone::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intf_SeqOfTangentZone.def("InsertAfter", (void (Intf_SeqOfTangentZone::*)(const Standard_Integer, const Intf_TangentZone &)) &Intf_SeqOfTangentZone::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_Intf_SeqOfTangentZone.def("Split", (void (Intf_SeqOfTangentZone::*)(const Standard_Integer, Intf_SeqOfTangentZone &)) &Intf_SeqOfTangentZone::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intf_SeqOfTangentZone.def("First", (const Intf_TangentZone & (Intf_SeqOfTangentZone::*)() const ) &Intf_SeqOfTangentZone::First, "First item access");
	cls_Intf_SeqOfTangentZone.def("ChangeFirst", (Intf_TangentZone & (Intf_SeqOfTangentZone::*)()) &Intf_SeqOfTangentZone::ChangeFirst, "First item access");
	cls_Intf_SeqOfTangentZone.def("Last", (const Intf_TangentZone & (Intf_SeqOfTangentZone::*)() const ) &Intf_SeqOfTangentZone::Last, "Last item access");
	cls_Intf_SeqOfTangentZone.def("ChangeLast", (Intf_TangentZone & (Intf_SeqOfTangentZone::*)()) &Intf_SeqOfTangentZone::ChangeLast, "Last item access");
	cls_Intf_SeqOfTangentZone.def("Value", (const Intf_TangentZone & (Intf_SeqOfTangentZone::*)(const Standard_Integer) const ) &Intf_SeqOfTangentZone::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_Intf_SeqOfTangentZone.def("__call__", (const Intf_TangentZone & (Intf_SeqOfTangentZone::*)(const Standard_Integer) const ) &Intf_SeqOfTangentZone::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_Intf_SeqOfTangentZone.def("ChangeValue", (Intf_TangentZone & (Intf_SeqOfTangentZone::*)(const Standard_Integer)) &Intf_SeqOfTangentZone::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_Intf_SeqOfTangentZone.def("__call__", (Intf_TangentZone & (Intf_SeqOfTangentZone::*)(const Standard_Integer)) &Intf_SeqOfTangentZone::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_Intf_SeqOfTangentZone.def("SetValue", (void (Intf_SeqOfTangentZone::*)(const Standard_Integer, const Intf_TangentZone &)) &Intf_SeqOfTangentZone::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_Intf_SeqOfTangentZone.def("__iter__", [](const Intf_SeqOfTangentZone &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<Intf_Array1OfLin, std::unique_ptr<Intf_Array1OfLin, Deleter<Intf_Array1OfLin>>> cls_Intf_Array1OfLin(mod, "Intf_Array1OfLin", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_Intf_Array1OfLin.def(py::init<>());
	cls_Intf_Array1OfLin.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Intf_Array1OfLin.def(py::init([] (const Intf_Array1OfLin &other) {return new Intf_Array1OfLin(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_Intf_Array1OfLin.def(py::init<Intf_Array1OfLin &&>(), py::arg("theOther"));
	cls_Intf_Array1OfLin.def(py::init<const gp_Lin &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_Intf_Array1OfLin.def("begin", (Intf_Array1OfLin::iterator (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::begin, "Returns an iterator pointing to the first element in the array.");
	cls_Intf_Array1OfLin.def("end", (Intf_Array1OfLin::iterator (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_Intf_Array1OfLin.def("cbegin", (Intf_Array1OfLin::const_iterator (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_Intf_Array1OfLin.def("cend", (Intf_Array1OfLin::const_iterator (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_Intf_Array1OfLin.def("Init", (void (Intf_Array1OfLin::*)(const gp_Lin &)) &Intf_Array1OfLin::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_Intf_Array1OfLin.def("Size", (Standard_Integer (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::Size, "Size query");
	cls_Intf_Array1OfLin.def("Length", (Standard_Integer (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::Length, "Length query (the same)");
	cls_Intf_Array1OfLin.def("IsEmpty", (Standard_Boolean (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::IsEmpty, "Return TRUE if array has zero length.");
	cls_Intf_Array1OfLin.def("Lower", (Standard_Integer (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::Lower, "Lower bound");
	cls_Intf_Array1OfLin.def("Upper", (Standard_Integer (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::Upper, "Upper bound");
	cls_Intf_Array1OfLin.def("IsDeletable", (Standard_Boolean (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::IsDeletable, "myDeletable flag");
	cls_Intf_Array1OfLin.def("IsAllocated", (Standard_Boolean (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_Intf_Array1OfLin.def("Assign", (Intf_Array1OfLin & (Intf_Array1OfLin::*)(const Intf_Array1OfLin &)) &Intf_Array1OfLin::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_Intf_Array1OfLin.def("Move", (Intf_Array1OfLin & (Intf_Array1OfLin::*)(Intf_Array1OfLin &&)) &Intf_Array1OfLin::Move, "Move assignment", py::arg("theOther"));
	cls_Intf_Array1OfLin.def("assign", (Intf_Array1OfLin & (Intf_Array1OfLin::*)(const Intf_Array1OfLin &)) &Intf_Array1OfLin::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_Intf_Array1OfLin.def("assign", (Intf_Array1OfLin & (Intf_Array1OfLin::*)(Intf_Array1OfLin &&)) &Intf_Array1OfLin::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_Intf_Array1OfLin.def("First", (const gp_Lin & (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::First, "Returns first element");
	cls_Intf_Array1OfLin.def("ChangeFirst", (gp_Lin & (Intf_Array1OfLin::*)()) &Intf_Array1OfLin::ChangeFirst, "Returns first element");
	cls_Intf_Array1OfLin.def("Last", (const gp_Lin & (Intf_Array1OfLin::*)() const ) &Intf_Array1OfLin::Last, "Returns last element");
	cls_Intf_Array1OfLin.def("ChangeLast", (gp_Lin & (Intf_Array1OfLin::*)()) &Intf_Array1OfLin::ChangeLast, "Returns last element");
	cls_Intf_Array1OfLin.def("Value", (const gp_Lin & (Intf_Array1OfLin::*)(const Standard_Integer) const ) &Intf_Array1OfLin::Value, "Constant value access", py::arg("theIndex"));
	cls_Intf_Array1OfLin.def("__call__", (const gp_Lin & (Intf_Array1OfLin::*)(const Standard_Integer) const ) &Intf_Array1OfLin::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_Intf_Array1OfLin.def("ChangeValue", (gp_Lin & (Intf_Array1OfLin::*)(const Standard_Integer)) &Intf_Array1OfLin::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_Intf_Array1OfLin.def("__call__", (gp_Lin & (Intf_Array1OfLin::*)(const Standard_Integer)) &Intf_Array1OfLin::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_Intf_Array1OfLin.def("SetValue", (void (Intf_Array1OfLin::*)(const Standard_Integer, const gp_Lin &)) &Intf_Array1OfLin::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_Intf_Array1OfLin.def("Resize", (void (Intf_Array1OfLin::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Intf_Array1OfLin::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_Intf_Array1OfLin.def("__iter__", [](const Intf_Array1OfLin &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
