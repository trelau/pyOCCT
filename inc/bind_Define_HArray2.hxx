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
#ifndef __Define_HArray2__
#define __Define_HArray2__

#include <pyOCCT_Common.hxx>

#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <Standard_Integer.hxx>
#include <Standard_TypeDef.hxx>


template<typename TheHArray2Type, typename TheArray2Type>
void bind_Define_HArray2(py::module &mod, std::string const &name) {

py::class_<TheHArray2Type, opencascade::handle<TheHArray2Type>, Standard_Transient> cls(mod, name.c_str(), "None", py::multiple_inheritance());

// Constructors
cls.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const typename TheArray2Type::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls.def(py::init<const TheArray2Type &>(), py::arg("theOther"));

// Methods
cls.def("Array2", (const TheArray2Type & (TheHArray2Type::*)() const) &TheHArray2Type::Array2, "None");
cls.def("ChangeArray2", (TheArray2Type & (TheHArray2Type::*)()) &TheHArray2Type::ChangeArray2, "None");
cls.def_static("get_type_name_", (const char * (*)()) &TheHArray2Type::get_type_name, "None");
cls.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TheHArray2Type::get_type_descriptor, "None");
cls.def("DynamicType", (const opencascade::handle<Standard_Type> & (TheHArray2Type::*)() const) &TheHArray2Type::DynamicType, "None");

// Methods for excluded base of TheArray2Type which is the NCollection_Array2<TheItemType> class template
cls.def("Init", (void (TheHArray2Type::*)(const typename TheArray2Type::value_type &)) &TheHArray2Type::Init, "Initialise the values", py::arg("theValue"));
cls.def("Size", (Standard_Integer(TheHArray2Type::*)() const) &TheHArray2Type::Size, "Size (number of items)");
cls.def("Length", (Standard_Integer(TheHArray2Type::*)() const) &TheHArray2Type::Length, "Length (number of items)");
cls.def("NbRows", (Standard_Integer(TheHArray2Type::*)() const) &TheHArray2Type::NbRows, "Returns number of rows");
cls.def("NbColumns", (Standard_Integer(TheHArray2Type::*)() const) &TheHArray2Type::NbColumns, "Returns number of columns");
cls.def("RowLength", (Standard_Integer(TheHArray2Type::*)() const) &TheHArray2Type::RowLength, "Returns length of the row, i.e. number of columns");
cls.def("ColLength", (Standard_Integer(TheHArray2Type::*)() const) &TheHArray2Type::ColLength, "Returns length of the column, i.e. number of rows");
cls.def("LowerRow", (Standard_Integer(TheHArray2Type::*)() const) &TheHArray2Type::LowerRow, "LowerRow");
cls.def("UpperRow", (Standard_Integer(TheHArray2Type::*)() const) &TheHArray2Type::UpperRow, "UpperRow");
cls.def("LowerCol", (Standard_Integer(TheHArray2Type::*)() const) &TheHArray2Type::LowerCol, "LowerCol");
cls.def("UpperCol", (Standard_Integer(TheHArray2Type::*)() const) &TheHArray2Type::UpperCol, "UpperCol");
cls.def("IsDeletable", (Standard_Boolean(TheHArray2Type::*)() const) &TheHArray2Type::IsDeletable, "myDeletable flag");
cls.def("Assign", (TheArray2Type & (TheHArray2Type::*)(const TheArray2Type &)) &TheHArray2Type::Assign, "Assignment", py::arg("theOther"));
cls.def("Move", (TheArray2Type & (TheHArray2Type::*)(TheArray2Type &)) &TheHArray2Type::Move, "Move assignment. This array will borrow all the data from theOther. The moved object will be left unitialized and should not be used anymore.", py::arg("theOther"));
// cls.def("operator=", (TheArray2Type & (TheHArray2Type::*)(const TheArray2Type &)) &TheHArray2Type::operator=, "Assignment operator", py::arg("theOther"));
// cls.def("operator=", (TheArray2Type & (TheHArray2Type::*)(TheArray2Type &&)) &TheHArray2Type::operator=, "Move assignment operator;", py::arg("theOther"));
cls.def("Value", (const typename TheArray2Type::value_type & (TheHArray2Type::*)(const Standard_Integer, const Standard_Integer) const) &TheHArray2Type::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
cls.def("__call__", (const typename TheArray2Type::value_type & (TheHArray2Type::*)(const Standard_Integer, const Standard_Integer) const) &TheHArray2Type::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
cls.def("ChangeValue", (typename TheArray2Type::value_type & (TheHArray2Type::*)(const Standard_Integer, const Standard_Integer)) &TheHArray2Type::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
cls.def("__call__", (typename TheArray2Type::value_type & (TheHArray2Type::*)(const Standard_Integer, const Standard_Integer)) &TheHArray2Type::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
cls.def("SetValue", (void (TheHArray2Type::*)(const Standard_Integer, const Standard_Integer, const typename TheArray2Type::value_type &)) &TheHArray2Type::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));
cls.def("Resize", (void (TheHArray2Type::*)(Standard_Integer, Standard_Integer, Standard_Integer, Standard_Integer, Standard_Boolean)) &TheHArray2Type::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"), py::arg("theToCopyData"));


}

#endif