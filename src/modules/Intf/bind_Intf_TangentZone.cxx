/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

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
#include <pyOCCT_Common.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Intf_SectionPoint.hxx>
#include <Intf_TangentZone.hxx>
#include <Intf_SeqOfSectionPoint.hxx>

void bind_Intf_TangentZone(py::module &mod){

py::class_<Intf_TangentZone, std::unique_ptr<Intf_TangentZone>> cls_Intf_TangentZone(mod, "Intf_TangentZone", "Describes a zone of tangence between polygons or polyhedra as a sequence of points of intersection.");

// Constructors
cls_Intf_TangentZone.def(py::init<>());
cls_Intf_TangentZone.def(py::init<const Intf_TangentZone &>(), py::arg("Other"));

// Fields

// Methods
// cls_Intf_TangentZone.def_static("operator new_", (void * (*)(size_t)) &Intf_TangentZone::operator new, "None", py::arg("theSize"));
// cls_Intf_TangentZone.def_static("operator delete_", (void (*)(void *)) &Intf_TangentZone::operator delete, "None", py::arg("theAddress"));
// cls_Intf_TangentZone.def_static("operator new[]_", (void * (*)(size_t)) &Intf_TangentZone::operator new[], "None", py::arg("theSize"));
// cls_Intf_TangentZone.def_static("operator delete[]_", (void (*)(void *)) &Intf_TangentZone::operator delete[], "None", py::arg("theAddress"));
// cls_Intf_TangentZone.def_static("operator new_", (void * (*)(size_t, void *)) &Intf_TangentZone::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Intf_TangentZone.def_static("operator delete_", (void (*)(void *, void *)) &Intf_TangentZone::operator delete, "None", py::arg(""), py::arg(""));
cls_Intf_TangentZone.def("NumberOfPoints", (Standard_Integer (Intf_TangentZone::*)() const) &Intf_TangentZone::NumberOfPoints, "Returns number of SectionPoint in this TangentZone.");
cls_Intf_TangentZone.def("GetPoint", (const Intf_SectionPoint & (Intf_TangentZone::*)(const Standard_Integer) const) &Intf_TangentZone::GetPoint, "Gives the SectionPoint of address <Index> in the TangentZone.", py::arg("Index"));
cls_Intf_TangentZone.def("IsEqual", (Standard_Boolean (Intf_TangentZone::*)(const Intf_TangentZone &) const) &Intf_TangentZone::IsEqual, "Compares two TangentZones.", py::arg("Other"));
cls_Intf_TangentZone.def("__eq__", (Standard_Boolean (Intf_TangentZone::*)(const Intf_TangentZone &) const) &Intf_TangentZone::operator==, py::is_operator(), "None", py::arg("Other"));
cls_Intf_TangentZone.def("Contains", (Standard_Boolean (Intf_TangentZone::*)(const Intf_SectionPoint &) const) &Intf_TangentZone::Contains, "Checks if <ThePI> is in TangentZone.", py::arg("ThePI"));
cls_Intf_TangentZone.def("ParamOnFirst", [](Intf_TangentZone &self, Standard_Real & paraMin, Standard_Real & paraMax){ self.ParamOnFirst(paraMin, paraMax); return std::tuple<Standard_Real &, Standard_Real &>(paraMin, paraMax); }, "Gives the parameter range of the TangentZone on the first argument of the Interference. (Usable only for polygon)", py::arg("paraMin"), py::arg("paraMax"));
cls_Intf_TangentZone.def("ParamOnSecond", [](Intf_TangentZone &self, Standard_Real & paraMin, Standard_Real & paraMax){ self.ParamOnSecond(paraMin, paraMax); return std::tuple<Standard_Real &, Standard_Real &>(paraMin, paraMax); }, "Gives the parameter range of the TangentZone on the second argument of the Interference. (Usable only for polygon)", py::arg("paraMin"), py::arg("paraMax"));
cls_Intf_TangentZone.def("InfoFirst", [](Intf_TangentZone &self, Standard_Integer & segMin, Standard_Real & paraMin, Standard_Integer & segMax, Standard_Real & paraMax){ self.InfoFirst(segMin, paraMin, segMax, paraMax); return std::tuple<Standard_Integer &, Standard_Real &, Standard_Integer &, Standard_Real &>(segMin, paraMin, segMax, paraMax); }, "Gives information about the first argument of the Interference. (Usable only for polygon)", py::arg("segMin"), py::arg("paraMin"), py::arg("segMax"), py::arg("paraMax"));
cls_Intf_TangentZone.def("InfoSecond", [](Intf_TangentZone &self, Standard_Integer & segMin, Standard_Real & paraMin, Standard_Integer & segMax, Standard_Real & paraMax){ self.InfoSecond(segMin, paraMin, segMax, paraMax); return std::tuple<Standard_Integer &, Standard_Real &, Standard_Integer &, Standard_Real &>(segMin, paraMin, segMax, paraMax); }, "Gives informations about the second argument of the Interference. (Usable only for polygon)", py::arg("segMin"), py::arg("paraMin"), py::arg("segMax"), py::arg("paraMax"));
cls_Intf_TangentZone.def("RangeContains", (Standard_Boolean (Intf_TangentZone::*)(const Intf_SectionPoint &) const) &Intf_TangentZone::RangeContains, "Returns True if <ThePI> is in the parameter range of the TangentZone.", py::arg("ThePI"));
cls_Intf_TangentZone.def("HasCommonRange", (Standard_Boolean (Intf_TangentZone::*)(const Intf_TangentZone &) const) &Intf_TangentZone::HasCommonRange, "Returns True if the TangentZone <Other> has a common part with <me>.", py::arg("Other"));
cls_Intf_TangentZone.def("Append", (void (Intf_TangentZone::*)(const Intf_SectionPoint &)) &Intf_TangentZone::Append, "Adds a SectionPoint to the TangentZone.", py::arg("Pi"));
cls_Intf_TangentZone.def("Append", (void (Intf_TangentZone::*)(const Intf_TangentZone &)) &Intf_TangentZone::Append, "Adds the TangentZone <Tzi> to <me>.", py::arg("Tzi"));
cls_Intf_TangentZone.def("Insert", (Standard_Boolean (Intf_TangentZone::*)(const Intf_SectionPoint &)) &Intf_TangentZone::Insert, "Inserts a SectionPoint in the TangentZone.", py::arg("Pi"));
cls_Intf_TangentZone.def("PolygonInsert", (void (Intf_TangentZone::*)(const Intf_SectionPoint &)) &Intf_TangentZone::PolygonInsert, "Inserts a point in the polygonal TangentZone.", py::arg("Pi"));
cls_Intf_TangentZone.def("InsertBefore", (void (Intf_TangentZone::*)(const Standard_Integer, const Intf_SectionPoint &)) &Intf_TangentZone::InsertBefore, "Inserts a SectionPoint before <Index> in the TangentZone.", py::arg("Index"), py::arg("Pi"));
cls_Intf_TangentZone.def("InsertAfter", (void (Intf_TangentZone::*)(const Standard_Integer, const Intf_SectionPoint &)) &Intf_TangentZone::InsertAfter, "Inserts a SectionPoint after <Index> in the TangentZone.", py::arg("Index"), py::arg("Pi"));
cls_Intf_TangentZone.def("Dump", (void (Intf_TangentZone::*)(const Standard_Integer) const) &Intf_TangentZone::Dump, "None", py::arg("Indent"));

// Enums

}