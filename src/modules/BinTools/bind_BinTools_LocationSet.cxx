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
#include <TopLoc_IndexedMapOfLocation.hxx>
#include <BinTools_LocationSet.hxx>

void bind_BinTools_LocationSet(py::module &mod){

py::class_<BinTools_LocationSet, std::unique_ptr<BinTools_LocationSet>> cls_BinTools_LocationSet(mod, "BinTools_LocationSet", "The class LocationSet stores a set of location in a relocatable state.");

// Constructors
cls_BinTools_LocationSet.def(py::init<>());

// Fields

// Methods
// cls_BinTools_LocationSet.def_static("operator new_", (void * (*)(size_t)) &BinTools_LocationSet::operator new, "None", py::arg("theSize"));
// cls_BinTools_LocationSet.def_static("operator delete_", (void (*)(void *)) &BinTools_LocationSet::operator delete, "None", py::arg("theAddress"));
// cls_BinTools_LocationSet.def_static("operator new[]_", (void * (*)(size_t)) &BinTools_LocationSet::operator new[], "None", py::arg("theSize"));
// cls_BinTools_LocationSet.def_static("operator delete[]_", (void (*)(void *)) &BinTools_LocationSet::operator delete[], "None", py::arg("theAddress"));
// cls_BinTools_LocationSet.def_static("operator new_", (void * (*)(size_t, void *)) &BinTools_LocationSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinTools_LocationSet.def_static("operator delete_", (void (*)(void *, void *)) &BinTools_LocationSet::operator delete, "None", py::arg(""), py::arg(""));
cls_BinTools_LocationSet.def("Clear", (void (BinTools_LocationSet::*)()) &BinTools_LocationSet::Clear, "Clears the content of the set.");
cls_BinTools_LocationSet.def("Add", (Standard_Integer (BinTools_LocationSet::*)(const TopLoc_Location &)) &BinTools_LocationSet::Add, "Incorporate a new Location in the set and returns its index.", py::arg("L"));
cls_BinTools_LocationSet.def("Location", (const TopLoc_Location & (BinTools_LocationSet::*)(const Standard_Integer) const) &BinTools_LocationSet::Location, "Returns the location of index <I>.", py::arg("I"));
cls_BinTools_LocationSet.def("Index", (Standard_Integer (BinTools_LocationSet::*)(const TopLoc_Location &) const) &BinTools_LocationSet::Index, "Returns the index of <L>.", py::arg("L"));
cls_BinTools_LocationSet.def("NbLocations", (Standard_Integer (BinTools_LocationSet::*)() const) &BinTools_LocationSet::NbLocations, "Returns number of locations.");
cls_BinTools_LocationSet.def("Write", (void (BinTools_LocationSet::*)(Standard_OStream &) const) &BinTools_LocationSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_BinTools_LocationSet.def("Read", (void (BinTools_LocationSet::*)(Standard_IStream &)) &BinTools_LocationSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));

// Enums

}