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
#include <Intf_SeqOfSectionPoint.hxx>

void bind_Intf_SectionLine(py::module &mod){

py::class_<Intf_SectionLine> cls_Intf_SectionLine(mod, "Intf_SectionLine", "Describe a polyline of intersection between two polyhedra as a sequence of points of intersection.");

// Constructors
cls_Intf_SectionLine.def(py::init<>());
cls_Intf_SectionLine.def(py::init<const Intf_SectionLine &>(), py::arg("Other"));

// Fields

// Methods
// cls_Intf_SectionLine.def_static("operator new_", (void * (*)(size_t)) &Intf_SectionLine::operator new, "None", py::arg("theSize"));
// cls_Intf_SectionLine.def_static("operator delete_", (void (*)(void *)) &Intf_SectionLine::operator delete, "None", py::arg("theAddress"));
// cls_Intf_SectionLine.def_static("operator new[]_", (void * (*)(size_t)) &Intf_SectionLine::operator new[], "None", py::arg("theSize"));
// cls_Intf_SectionLine.def_static("operator delete[]_", (void (*)(void *)) &Intf_SectionLine::operator delete[], "None", py::arg("theAddress"));
// cls_Intf_SectionLine.def_static("operator new_", (void * (*)(size_t, void *)) &Intf_SectionLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Intf_SectionLine.def_static("operator delete_", (void (*)(void *, void *)) &Intf_SectionLine::operator delete, "None", py::arg(""), py::arg(""));
cls_Intf_SectionLine.def("NumberOfPoints", (Standard_Integer (Intf_SectionLine::*)() const) &Intf_SectionLine::NumberOfPoints, "Returns number of points in this SectionLine.");
cls_Intf_SectionLine.def("GetPoint", (const Intf_SectionPoint & (Intf_SectionLine::*)(const Standard_Integer) const) &Intf_SectionLine::GetPoint, "Gives the point of intersection of address <Index> in the SectionLine.", py::arg("Index"));
cls_Intf_SectionLine.def("IsClosed", (Standard_Boolean (Intf_SectionLine::*)() const) &Intf_SectionLine::IsClosed, "Returns True if the SectionLine is closed.");
cls_Intf_SectionLine.def("Contains", (Standard_Boolean (Intf_SectionLine::*)(const Intf_SectionPoint &) const) &Intf_SectionLine::Contains, "Returns True if ThePI is in the SectionLine <me>.", py::arg("ThePI"));
cls_Intf_SectionLine.def("IsEnd", (Standard_Integer (Intf_SectionLine::*)(const Intf_SectionPoint &) const) &Intf_SectionLine::IsEnd, "Checks if <ThePI> is an end of the SectionLine. Returns 1 for the beginning, 2 for the end, otherwise 0.", py::arg("ThePI"));
cls_Intf_SectionLine.def("IsEqual", (Standard_Boolean (Intf_SectionLine::*)(const Intf_SectionLine &) const) &Intf_SectionLine::IsEqual, "Compares two SectionLines.", py::arg("Other"));
cls_Intf_SectionLine.def("__eq__", (Standard_Boolean (Intf_SectionLine::*)(const Intf_SectionLine &) const) &Intf_SectionLine::operator==, py::is_operator(), "None", py::arg("Other"));
cls_Intf_SectionLine.def("Append", (void (Intf_SectionLine::*)(const Intf_SectionPoint &)) &Intf_SectionLine::Append, "Adds a point at the end of the SectionLine.", py::arg("Pi"));
cls_Intf_SectionLine.def("Append", (void (Intf_SectionLine::*)(Intf_SectionLine &)) &Intf_SectionLine::Append, "Concatenates the SectionLine <LS> at the end of the SectionLine <me>.", py::arg("LS"));
cls_Intf_SectionLine.def("Prepend", (void (Intf_SectionLine::*)(const Intf_SectionPoint &)) &Intf_SectionLine::Prepend, "Adds a point to the beginning of the SectionLine <me>.", py::arg("Pi"));
cls_Intf_SectionLine.def("Prepend", (void (Intf_SectionLine::*)(Intf_SectionLine &)) &Intf_SectionLine::Prepend, "Concatenates a SectionLine <LS> at the beginning of the SectionLine <me>.", py::arg("LS"));
cls_Intf_SectionLine.def("Reverse", (void (Intf_SectionLine::*)()) &Intf_SectionLine::Reverse, "Reverses the order of the elements of the SectionLine.");
cls_Intf_SectionLine.def("Close", (void (Intf_SectionLine::*)()) &Intf_SectionLine::Close, "Closes the SectionLine.");
cls_Intf_SectionLine.def("Dump", (void (Intf_SectionLine::*)(const Standard_Integer) const) &Intf_SectionLine::Dump, "None", py::arg("Indent"));

// Enums

}