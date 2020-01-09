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
#ifndef __Define_HArray1__
#define __Define_HArray1__

#include <pyOCCT_Common.hxx>

#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <Standard_Integer.hxx>
#include <Standard_TypeDef.hxx>


template<typename TheHArray1Type, typename TheArray1Type>
void bind_Define_HArray1(py::module &mod, std::string const &name) {

py::class_<TheHArray1Type, opencascade::handle<TheHArray1Type>, Standard_Transient> cls(mod, name.c_str(), "None", py::multiple_inheritance());

// Constructors
cls.def(py::init<>());
cls.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls.def(py::init<const Standard_Integer, const Standard_Integer, const typename TheArray1Type::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls.def(py::init<const TheArray1Type &>(), py::arg("theOther"));

// Methods
cls.def("Array1", (const TheArray1Type & (TheHArray1Type::*)() const) &TheHArray1Type::Array1, "None");
cls.def("ChangeArray1", (TheArray1Type & (TheHArray1Type::*)()) &TheHArray1Type::ChangeArray1, "None");
cls.def_static("get_type_name_", (const char * (*)()) &TheHArray1Type::get_type_name, "None");
cls.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TheHArray1Type::get_type_descriptor, "None");
cls.def("DynamicType", (const opencascade::handle<Standard_Type> & (TheHArray1Type::*)() const) &TheHArray1Type::DynamicType, "None");

// Methods for excluded base of TheArray1Type which is the NCollection_Array1<TheItemType> class template
cls.def("Init", (void (TheHArray1Type::*)(const typename TheArray1Type::value_type &)) &TheHArray1Type::Init, "Initialise the items with theValue", py::arg("theValue"));
cls.def("Size", (Standard_Integer(TheHArray1Type::*)() const) &TheHArray1Type::Size, "Size query");
cls.def("Length", (Standard_Integer(TheHArray1Type::*)() const) &TheHArray1Type::Length, "Length query (the same)");
cls.def("IsEmpty", (Standard_Boolean(TheHArray1Type::*)() const) &TheHArray1Type::IsEmpty, "Return TRUE if array has zero length.");
cls.def("Lower", (Standard_Integer(TheHArray1Type::*)() const) &TheHArray1Type::Lower, "Lower bound");
cls.def("Upper", (Standard_Integer(TheHArray1Type::*)() const) &TheHArray1Type::Upper, "Upper bound");
cls.def("IsDeletable", (Standard_Boolean(TheHArray1Type::*)() const) &TheHArray1Type::IsDeletable, "myDeletable flag");
cls.def("IsAllocated", (Standard_Boolean(TheHArray1Type::*)() const) &TheHArray1Type::IsAllocated, "IsAllocated flag - for naming compatibility");
cls.def("Assign", (TheArray1Type & (TheHArray1Type::*)(const TheArray1Type &)) &TheHArray1Type::Assign, "Copies data of theOther array to this. This array should be pre-allocated and have the same length as theOther; otherwise exception Standard_DimensionMismatch is thrown.", py::arg("theOther"));
cls.def("Move", (TheArray1Type & (TheHArray1Type::*)(TheArray1Type &)) &TheHArray1Type::Move, "Move assignment. This array will borrow all the data from theOther. The moved object will keep pointer to the memory buffer and range, but it will not free the buffer on destruction.", py::arg("theOther"));
// cls.def("operator=", (TheArray1Type & (TheHArray1Type::*)(const TheArray1Type &)) &TheHArray1Type::operator=, "Assignment operator;", py::arg("theOther"));
// cls.def("operator=", (TheArray1Type & (TheHArray1Type::*)(TheArray1Type &&)) &TheHArray1Type::operator=, "Move assignment operator;", py::arg("theOther"));
cls.def("First", (const typename TheArray1Type::value_type & (TheHArray1Type::*)() const) &TheHArray1Type::First, "Returns first element");
cls.def("ChangeFirst", (typename TheArray1Type::value_type & (TheHArray1Type::*)()) &TheHArray1Type::ChangeFirst, "Returns first element");
cls.def("Last", (const typename TheArray1Type::value_type & (TheHArray1Type::*)() const) &TheHArray1Type::Last, "Returns last element");
cls.def("ChangeLast", (typename TheArray1Type::value_type & (TheHArray1Type::*)()) &TheHArray1Type::ChangeLast, "Returns last element");
cls.def("Value", (const typename TheArray1Type::value_type & (TheHArray1Type::*)(const Standard_Integer) const) &TheHArray1Type::Value, "Constant value access", py::arg("theIndex"));
cls.def("__call__", (const typename TheArray1Type::value_type & (TheHArray1Type::*)(const Standard_Integer) const) &TheHArray1Type::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
cls.def("__getitem__", (const typename TheArray1Type::value_type & (TheHArray1Type::*)(Standard_Integer) const) &TheHArray1Type::operator[], py::is_operator(), "operator[] - alias to Value", py::arg("theIndex"));
cls.def("ChangeValue", (typename TheArray1Type::value_type & (TheHArray1Type::*)(const Standard_Integer)) &TheHArray1Type::ChangeValue, "Variable value access", py::arg("theIndex"));
cls.def("__call__", (typename TheArray1Type::value_type & (TheHArray1Type::*)(const Standard_Integer)) &TheHArray1Type::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
cls.def("__getitem__", (typename TheArray1Type::value_type & (TheHArray1Type::*)(Standard_Integer)) &TheHArray1Type::operator[], py::is_operator(), "operator[] - alias to ChangeValue", py::arg("theIndex"));
cls.def("SetValue", (void (TheHArray1Type::*)(const Standard_Integer, const typename TheArray1Type::value_type &)) &TheHArray1Type::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
cls.def("Resize", (void (TheHArray1Type::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TheHArray1Type::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
cls.def("__iter__", [](const TheArray1Type &self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

}

#endif