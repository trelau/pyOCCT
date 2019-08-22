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
#include <BOPDS_Pair.hxx>

void bind_BOPDS_Pair(py::module &mod){

py::class_<BOPDS_Pair> cls_BOPDS_Pair(mod, "BOPDS_Pair", "The class is to provide the pair of indices of interfering shapes.");

// Constructors
cls_BOPDS_Pair.def(py::init<>());
cls_BOPDS_Pair.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theIndex1"), py::arg("theIndex2"));

// Fields

// Methods
// cls_BOPDS_Pair.def_static("operator new_", (void * (*)(size_t)) &BOPDS_Pair::operator new, "None", py::arg("theSize"));
// cls_BOPDS_Pair.def_static("operator delete_", (void (*)(void *)) &BOPDS_Pair::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_Pair.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_Pair::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_Pair.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_Pair::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_Pair.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_Pair::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_Pair.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_Pair::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_Pair.def("SetIndices", (void (BOPDS_Pair::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_Pair::SetIndices, "Sets the indices", py::arg("theIndex1"), py::arg("theIndex2"));
cls_BOPDS_Pair.def("Indices", [](BOPDS_Pair &self, Standard_Integer & theIndex1, Standard_Integer & theIndex2){ self.Indices(theIndex1, theIndex2); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndex1, theIndex2); }, "Gets the indices", py::arg("theIndex1"), py::arg("theIndex2"));
cls_BOPDS_Pair.def("__lt__", (Standard_Boolean (BOPDS_Pair::*)(const BOPDS_Pair &) const) &BOPDS_Pair::operator<, py::is_operator(), "Operator less", py::arg("theOther"));
cls_BOPDS_Pair.def("IsEqual", (Standard_Boolean (BOPDS_Pair::*)(const BOPDS_Pair &) const) &BOPDS_Pair::IsEqual, "Returns true if the Pair is equal to <the theOther>", py::arg("theOther"));
cls_BOPDS_Pair.def("HashCode", (Standard_Integer (BOPDS_Pair::*)(const Standard_Integer) const) &BOPDS_Pair::HashCode, "Returns hash code", py::arg("theUpper"));

// Enums

}