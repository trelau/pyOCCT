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
#include <BOPDS_IndexRange.hxx>

void bind_BOPDS_IndexRange(py::module &mod){

py::class_<BOPDS_IndexRange> cls_BOPDS_IndexRange(mod, "BOPDS_IndexRange", "The class BOPDS_IndexRange is to store the information about range of two indices");

// Constructors
cls_BOPDS_IndexRange.def(py::init<>());

// Fields

// Methods
// cls_BOPDS_IndexRange.def_static("operator new_", (void * (*)(size_t)) &BOPDS_IndexRange::operator new, "None", py::arg("theSize"));
// cls_BOPDS_IndexRange.def_static("operator delete_", (void (*)(void *)) &BOPDS_IndexRange::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_IndexRange.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_IndexRange::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_IndexRange.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_IndexRange::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_IndexRange.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_IndexRange::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_IndexRange.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_IndexRange::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_IndexRange.def("SetFirst", (void (BOPDS_IndexRange::*)(const Standard_Integer)) &BOPDS_IndexRange::SetFirst, "Modifier Sets the first index <theI1> of the range", py::arg("theI1"));
cls_BOPDS_IndexRange.def("SetLast", (void (BOPDS_IndexRange::*)(const Standard_Integer)) &BOPDS_IndexRange::SetLast, "Modifier Sets the second index <theI2> of the range", py::arg("theI2"));
cls_BOPDS_IndexRange.def("First", (Standard_Integer (BOPDS_IndexRange::*)() const) &BOPDS_IndexRange::First, "Selector Returns the first index of the range");
cls_BOPDS_IndexRange.def("Last", (Standard_Integer (BOPDS_IndexRange::*)() const) &BOPDS_IndexRange::Last, "Selector Returns the second index of the range");
cls_BOPDS_IndexRange.def("SetIndices", (void (BOPDS_IndexRange::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_IndexRange::SetIndices, "Modifier Sets the first index of the range <theI1> Sets the second index of the range <theI2>", py::arg("theI1"), py::arg("theI2"));
cls_BOPDS_IndexRange.def("Indices", [](BOPDS_IndexRange &self, Standard_Integer & theI1, Standard_Integer & theI2){ self.Indices(theI1, theI2); return std::tuple<Standard_Integer &, Standard_Integer &>(theI1, theI2); }, "Selector Returns the first index of the range <theI1> Returns the second index of the range <theI2>", py::arg("theI1"), py::arg("theI2"));
cls_BOPDS_IndexRange.def("Contains", (Standard_Boolean (BOPDS_IndexRange::*)(const Standard_Integer) const) &BOPDS_IndexRange::Contains, "Query Returns true if the range contains <theIndex>", py::arg("theIndex"));
cls_BOPDS_IndexRange.def("Dump", (void (BOPDS_IndexRange::*)() const) &BOPDS_IndexRange::Dump, "None");

// Enums

}