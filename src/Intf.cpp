/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hpp>

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
#include <NCollection_Templates.hpp>

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
	cls_Intf_SectionPoint.def("InfoFirst", [](Intf_SectionPoint &self, Intf_PIType & Dim, Standard_Integer & Add1, Standard_Integer & Add2, Standard_Real & Param){ self.InfoFirst(Dim, Add1, Add2, Param); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Real &>(Add1, Add2, Param); }, "None", py::arg("Dim"), py::arg("Add1"), py::arg("Add2"), py::arg("Param"));
	cls_Intf_SectionPoint.def("InfoFirst", [](Intf_SectionPoint &self, Intf_PIType & Dim, Standard_Integer & Addr, Standard_Real & Param){ self.InfoFirst(Dim, Addr, Param); return std::tuple<Standard_Integer &, Standard_Real &>(Addr, Param); }, "Gives the datas about the first argument of the Interference.", py::arg("Dim"), py::arg("Addr"), py::arg("Param"));
	cls_Intf_SectionPoint.def("InfoSecond", [](Intf_SectionPoint &self, Intf_PIType & Dim, Standard_Integer & Add1, Standard_Integer & Add2, Standard_Real & Param){ self.InfoSecond(Dim, Add1, Add2, Param); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Real &>(Add1, Add2, Param); }, "None", py::arg("Dim"), py::arg("Add1"), py::arg("Add2"), py::arg("Param"));
	cls_Intf_SectionPoint.def("InfoSecond", [](Intf_SectionPoint &self, Intf_PIType & Dim, Standard_Integer & Addr, Standard_Real & Param){ self.InfoSecond(Dim, Addr, Param); return std::tuple<Standard_Integer &, Standard_Real &>(Addr, Param); }, "Gives the datas about the second argument of the Interference.", py::arg("Dim"), py::arg("Addr"), py::arg("Param"));
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
	cls_Intf_TangentZone.def("ParamOnFirst", [](Intf_TangentZone &self, Standard_Real & paraMin, Standard_Real & paraMax){ self.ParamOnFirst(paraMin, paraMax); return std::tuple<Standard_Real &, Standard_Real &>(paraMin, paraMax); }, "Gives the parameter range of the TangentZone on the first argument of the Interference. (Usable only for polygon)", py::arg("paraMin"), py::arg("paraMax"));
	cls_Intf_TangentZone.def("ParamOnSecond", [](Intf_TangentZone &self, Standard_Real & paraMin, Standard_Real & paraMax){ self.ParamOnSecond(paraMin, paraMax); return std::tuple<Standard_Real &, Standard_Real &>(paraMin, paraMax); }, "Gives the parameter range of the TangentZone on the second argument of the Interference. (Usable only for polygon)", py::arg("paraMin"), py::arg("paraMax"));
	cls_Intf_TangentZone.def("InfoFirst", [](Intf_TangentZone &self, Standard_Integer & segMin, Standard_Real & paraMin, Standard_Integer & segMax, Standard_Real & paraMax){ self.InfoFirst(segMin, paraMin, segMax, paraMax); return std::tuple<Standard_Integer &, Standard_Real &, Standard_Integer &, Standard_Real &>(segMin, paraMin, segMax, paraMax); }, "Gives information about the first argument of the Interference. (Usable only for polygon)", py::arg("segMin"), py::arg("paraMin"), py::arg("segMax"), py::arg("paraMax"));
	cls_Intf_TangentZone.def("InfoSecond", [](Intf_TangentZone &self, Standard_Integer & segMin, Standard_Real & paraMin, Standard_Integer & segMax, Standard_Real & paraMax){ self.InfoSecond(segMin, paraMin, segMax, paraMax); return std::tuple<Standard_Integer &, Standard_Real &, Standard_Integer &, Standard_Real &>(segMin, paraMin, segMax, paraMax); }, "Gives informations about the second argument of the Interference. (Usable only for polygon)", py::arg("segMin"), py::arg("paraMin"), py::arg("segMax"), py::arg("paraMax"));
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
	cls_Intf.def_static("PlaneEquation_", [](const gp_Pnt & P1, const gp_Pnt & P2, const gp_Pnt & P3, gp_XYZ & NormalVector, Standard_Real & PolarDistance){ Intf::PlaneEquation(P1, P2, P3, NormalVector, PolarDistance); return PolarDistance; }, "Computes the interference between two polygons in 2d. Result : points of intersections and zones of tangence. Computes the interference between a polygon or a straight line and a polyhedron. Points of intersection and zones of tangence. Give the plane equation of the triangle <P1> <P2> <P3>.", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("NormalVector"), py::arg("PolarDistance"));
	cls_Intf.def_static("Contain_", (Standard_Boolean (*)(const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &Intf::Contain, "Compute if the triangle <P1> <P2> <P3> contain <ThePnt>.", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("ThePnt"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_SeqOfSectionPoint.hxx
	bind_NCollection_Sequence<Intf_SectionPoint>(mod, "Intf_SeqOfSectionPoint");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_SeqOfSectionLine.hxx
	bind_NCollection_Sequence<Intf_SectionLine>(mod, "Intf_SeqOfSectionLine");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_SeqOfTangentZone.hxx
	bind_NCollection_Sequence<Intf_TangentZone>(mod, "Intf_SeqOfTangentZone");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intf_Array1OfLin.hxx
	bind_NCollection_Array1<gp_Lin>(mod, "Intf_Array1OfLin");


}
