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
#pragma once

#include <pyOCCT_Common.hxx>
#include <NCollection_Array2.hxx>
#include <Standard_TypeDef.hxx>

template <typename TheItemType>
void bind_NCollection_Array2(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Array2<TheItemType>> cls_NCollection_Array2(mod, name.c_str(), "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.", local);

// Constructors
cls_NCollection_Array2.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
cls_NCollection_Array2.def(py::init<const NCollection_Array2<TheItemType> &>(), py::arg("theOther"));
cls_NCollection_Array2.def(py::init<const TheItemType &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));

// Methods
cls_NCollection_Array2.def("Init", (void (NCollection_Array2<TheItemType>::*)(const TheItemType &)) &NCollection_Array2<TheItemType>::Init, "Initialise the values", py::arg("theValue"));
cls_NCollection_Array2.def("Size", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const) &NCollection_Array2<TheItemType>::Size, "Size (number of items)");
cls_NCollection_Array2.def("Length", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const) &NCollection_Array2<TheItemType>::Length, "Length (number of items)");
cls_NCollection_Array2.def("RowLength", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const) &NCollection_Array2<TheItemType>::RowLength, "Returns length of the row, i.e. number of columns");
cls_NCollection_Array2.def("ColLength", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const) &NCollection_Array2<TheItemType>::ColLength, "Returns length of the column, i.e. number of rows");
cls_NCollection_Array2.def("LowerRow", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const) &NCollection_Array2<TheItemType>::LowerRow, "LowerRow");
cls_NCollection_Array2.def("UpperRow", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const) &NCollection_Array2<TheItemType>::UpperRow, "UpperRow");
cls_NCollection_Array2.def("LowerCol", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const) &NCollection_Array2<TheItemType>::LowerCol, "LowerCol");
cls_NCollection_Array2.def("UpperCol", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const) &NCollection_Array2<TheItemType>::UpperCol, "UpperCol");
cls_NCollection_Array2.def("IsDeletable", (Standard_Boolean (NCollection_Array2<TheItemType>::*)() const) &NCollection_Array2<TheItemType>::IsDeletable, "myDeletable flag");
cls_NCollection_Array2.def("Assign", (NCollection_Array2<TheItemType> & (NCollection_Array2<TheItemType>::*)(const NCollection_Array2<TheItemType> &)) &NCollection_Array2<TheItemType>::Assign, "Assignment", py::arg("theOther"));
// cls_NCollection_Array2.def("operator=", (NCollection_Array2<TheItemType> & (NCollection_Array2<TheItemType>::*)(const NCollection_Array2<TheItemType> &)) &NCollection_Array2<TheItemType>::operator=, "Assignment operator", py::arg("theOther"));
cls_NCollection_Array2.def("Value", (const TheItemType & (NCollection_Array2<TheItemType>::*)(const Standard_Integer, const Standard_Integer) const) &NCollection_Array2<TheItemType>::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
cls_NCollection_Array2.def("__call__", (const TheItemType & (NCollection_Array2<TheItemType>::*)(const Standard_Integer, const Standard_Integer) const) &NCollection_Array2<TheItemType>::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
cls_NCollection_Array2.def("ChangeValue", (TheItemType & (NCollection_Array2<TheItemType>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_Array2<TheItemType>::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
cls_NCollection_Array2.def("__call__", (TheItemType & (NCollection_Array2<TheItemType>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_Array2<TheItemType>::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
cls_NCollection_Array2.def("SetValue", (void (NCollection_Array2<TheItemType>::*)(const Standard_Integer, const Standard_Integer, const TheItemType &)) &NCollection_Array2<TheItemType>::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

}
