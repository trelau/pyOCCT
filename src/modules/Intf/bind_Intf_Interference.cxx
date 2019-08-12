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
#include <Intf_SectionLine.hxx>
#include <Intf_TangentZone.hxx>
#include <Intf_SeqOfSectionPoint.hxx>
#include <Intf_SeqOfSectionLine.hxx>
#include <Intf_SeqOfTangentZone.hxx>
#include <Intf_Interference.hxx>

void bind_Intf_Interference(py::module &mod){

py::class_<Intf_Interference, std::unique_ptr<Intf_Interference, py::nodelete>> cls_Intf_Interference(mod, "Intf_Interference", "Describes the Interference computation result between polygon2d or polygon3d or polyhedron (as three sequences of points of intersection, polylines of intersection and zones de tangence).");

// Constructors

// Fields

// Methods
// cls_Intf_Interference.def_static("operator new_", (void * (*)(size_t)) &Intf_Interference::operator new, "None", py::arg("theSize"));
// cls_Intf_Interference.def_static("operator delete_", (void (*)(void *)) &Intf_Interference::operator delete, "None", py::arg("theAddress"));
// cls_Intf_Interference.def_static("operator new[]_", (void * (*)(size_t)) &Intf_Interference::operator new[], "None", py::arg("theSize"));
// cls_Intf_Interference.def_static("operator delete[]_", (void (*)(void *)) &Intf_Interference::operator delete[], "None", py::arg("theAddress"));
// cls_Intf_Interference.def_static("operator new_", (void * (*)(size_t, void *)) &Intf_Interference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Intf_Interference.def_static("operator delete_", (void (*)(void *, void *)) &Intf_Interference::operator delete, "None", py::arg(""), py::arg(""));
cls_Intf_Interference.def("NbSectionPoints", (Standard_Integer (Intf_Interference::*)() const) &Intf_Interference::NbSectionPoints, "Gives the number of points of intersection in the interference.");
cls_Intf_Interference.def("PntValue", (const Intf_SectionPoint & (Intf_Interference::*)(const Standard_Integer) const) &Intf_Interference::PntValue, "Gives the point of intersection of address Index in the interference.", py::arg("Index"));
cls_Intf_Interference.def("NbSectionLines", (Standard_Integer (Intf_Interference::*)() const) &Intf_Interference::NbSectionLines, "Gives the number of polylines of intersection in the interference.");
cls_Intf_Interference.def("LineValue", (const Intf_SectionLine & (Intf_Interference::*)(const Standard_Integer) const) &Intf_Interference::LineValue, "Gives the polyline of intersection at address <Index> in the interference.", py::arg("Index"));
cls_Intf_Interference.def("NbTangentZones", (Standard_Integer (Intf_Interference::*)() const) &Intf_Interference::NbTangentZones, "Gives the number of zones of tangence in the interference.");
cls_Intf_Interference.def("ZoneValue", (const Intf_TangentZone & (Intf_Interference::*)(const Standard_Integer) const) &Intf_Interference::ZoneValue, "Gives the zone of tangence at address Index in the interference.", py::arg("Index"));
cls_Intf_Interference.def("GetTolerance", (Standard_Real (Intf_Interference::*)() const) &Intf_Interference::GetTolerance, "Gives the tolerance used for the calculation.");
cls_Intf_Interference.def("Contains", (Standard_Boolean (Intf_Interference::*)(const Intf_SectionPoint &) const) &Intf_Interference::Contains, "Tests if the polylines of intersection or the zones of tangence contain the point of intersection <ThePnt>.", py::arg("ThePnt"));
cls_Intf_Interference.def("Insert", (Standard_Boolean (Intf_Interference::*)(const Intf_TangentZone &)) &Intf_Interference::Insert, "Inserts a new zone of tangence in the current list of tangent zones of the interference and returns True when done.", py::arg("TheZone"));
cls_Intf_Interference.def("Insert", (void (Intf_Interference::*)(const Intf_SectionPoint &, const Intf_SectionPoint &)) &Intf_Interference::Insert, "Insert a new segment of intersection in the current list of polylines of intersection of the interference.", py::arg("pdeb"), py::arg("pfin"));
cls_Intf_Interference.def("Dump", (void (Intf_Interference::*)() const) &Intf_Interference::Dump, "None");

// Enums

}