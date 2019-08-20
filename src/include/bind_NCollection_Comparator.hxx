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
#ifndef __NCollection_Comparator__
#define __NCollection_Comparator__

#include <pyOCCT_Common.hxx>
#include <Standard_TypeDef.hxx>
#include <Precision.hxx>
#include <NCollection_Comparator.hxx>

template <typename TheItemType>
void bind_NCollection_Comparator(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Comparator<TheItemType>, std::unique_ptr<NCollection_Comparator<TheItemType>>> cls_NCollection_Comparator(mod, name.c_str(), "Class to define basic compare operations. Basic implementation use redirection to standard C++ operators. You can use standard C++ templates mechanisms to redefine these methods or to inherit basic implementation to create multiple comparators for same type with different rules.", local);

// Constructors
cls_NCollection_Comparator.def(py::init<>());
cls_NCollection_Comparator.def(py::init<const Standard_Real>(), py::arg("theTolerance"));

// Fields

// Methods
cls_NCollection_Comparator.def("IsGreater", (Standard_Boolean (NCollection_Comparator<TheItemType>::*)(const TheItemType &, const TheItemType &) const) &NCollection_Comparator<TheItemType>::IsGreater, "Should return true if Left value is greater than Right", py::arg("theLeft"), py::arg("theRight"));
cls_NCollection_Comparator.def("IsEqual", (Standard_Boolean (NCollection_Comparator<TheItemType>::*)(const TheItemType &, const TheItemType &) const) &NCollection_Comparator<TheItemType>::IsEqual, "Should return true if values are equal", py::arg("theLeft"), py::arg("theRight"));
cls_NCollection_Comparator.def("IsLower", (Standard_Boolean (NCollection_Comparator<TheItemType>::*)(const TheItemType &, const TheItemType &) const) &NCollection_Comparator<TheItemType>::IsLower, "Should return true if Left value is lower than Right", py::arg("theLeft"), py::arg("theRight"));
cls_NCollection_Comparator.def("IsLowerEqual", (Standard_Boolean (NCollection_Comparator<TheItemType>::*)(const TheItemType &, const TheItemType &) const) &NCollection_Comparator<TheItemType>::IsLowerEqual, "None", py::arg("theLeft"), py::arg("theRight"));
cls_NCollection_Comparator.def("IsGreaterEqual", (Standard_Boolean (NCollection_Comparator<TheItemType>::*)(const TheItemType &, const TheItemType &) const) &NCollection_Comparator<TheItemType>::IsGreaterEqual, "None", py::arg("theLeft"), py::arg("theRight"));

// Enums

}

#endif