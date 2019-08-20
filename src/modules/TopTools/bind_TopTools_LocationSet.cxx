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
#include <TopLoc_Location.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <Standard_Handle.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TopLoc_IndexedMapOfLocation.hxx>
#include <TopTools_LocationSet.hxx>

void bind_TopTools_LocationSet(py::module &mod){

py::class_<TopTools_LocationSet, std::unique_ptr<TopTools_LocationSet>> cls_TopTools_LocationSet(mod, "TopTools_LocationSet", "The class LocationSet stores a set of location in a relocatable state.");

// Constructors
cls_TopTools_LocationSet.def(py::init<>());

// Fields

// Methods
// cls_TopTools_LocationSet.def_static("operator new_", (void * (*)(size_t)) &TopTools_LocationSet::operator new, "None", py::arg("theSize"));
// cls_TopTools_LocationSet.def_static("operator delete_", (void (*)(void *)) &TopTools_LocationSet::operator delete, "None", py::arg("theAddress"));
// cls_TopTools_LocationSet.def_static("operator new[]_", (void * (*)(size_t)) &TopTools_LocationSet::operator new[], "None", py::arg("theSize"));
// cls_TopTools_LocationSet.def_static("operator delete[]_", (void (*)(void *)) &TopTools_LocationSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools_LocationSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools_LocationSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools_LocationSet.def_static("operator delete_", (void (*)(void *, void *)) &TopTools_LocationSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopTools_LocationSet.def("Clear", (void (TopTools_LocationSet::*)()) &TopTools_LocationSet::Clear, "Clears the content of the set.");
cls_TopTools_LocationSet.def("Add", (Standard_Integer (TopTools_LocationSet::*)(const TopLoc_Location &)) &TopTools_LocationSet::Add, "Incorporate a new Location in the set and returns its index.", py::arg("L"));
cls_TopTools_LocationSet.def("Location", (const TopLoc_Location & (TopTools_LocationSet::*)(const Standard_Integer) const) &TopTools_LocationSet::Location, "Returns the location of index <I>.", py::arg("I"));
cls_TopTools_LocationSet.def("Index", (Standard_Integer (TopTools_LocationSet::*)(const TopLoc_Location &) const) &TopTools_LocationSet::Index, "Returns the index of <L>.", py::arg("L"));
cls_TopTools_LocationSet.def("Dump", (void (TopTools_LocationSet::*)(Standard_OStream &) const) &TopTools_LocationSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
cls_TopTools_LocationSet.def("Write", (void (TopTools_LocationSet::*)(Standard_OStream &) const) &TopTools_LocationSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_TopTools_LocationSet.def("Read", (void (TopTools_LocationSet::*)(Standard_IStream &)) &TopTools_LocationSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_TopTools_LocationSet.def("SetProgress", (void (TopTools_LocationSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &TopTools_LocationSet::SetProgress, "None", py::arg("PR"));
cls_TopTools_LocationSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (TopTools_LocationSet::*)() const) &TopTools_LocationSet::GetProgress, "None");

// Enums

}