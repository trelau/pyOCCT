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
#ifndef __Define_HSequence__
#define __Define_HSequence__

#include <pyOCCT_Common.hxx>

#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_BaseAllocator.hxx>

template<typename TheHSequenceType, typename TheSequenceType>
void bind_Define_HSequence(py::module &mod, std::string const &name) {

py::class_<TheHSequenceType, opencascade::handle<TheHSequenceType>, Standard_Transient> cls(mod, name.c_str(), "None", py::multiple_inheritance());

// Constructors
cls.def(py::init<>());
cls.def(py::init<const TheSequenceType &>(), py::arg("theOther"));

// Methods
// Write "Sequence" and "ChangeSequence" because pybind11 seems to just return itself instead of the right object?
//cls.def("Sequence", (const TheSequenceType & (TheHSequenceType::*)() const) &TheHSequenceType::Sequence, "None");
cls.def("Sequence", [](const TheHSequenceType &self) {const TheSequenceType &out = self.Sequence(); return out; }, "None");
cls.def("Append", (void (TheHSequenceType::*)(const typename TheSequenceType::value_type &)) &TheHSequenceType::Append, "None", py::arg("theItem"));
cls.def("Append", (void (TheHSequenceType::*)(TheSequenceType &)) &TheHSequenceType::Append, "None", py::arg("theSequence"));
// cls.def("ChangeSequence", (TheSequenceType & (TheHSequenceType::*)()) &TheHSequenceType::ChangeSequence, "None");
cls.def("ChangeSequence", [](TheHSequenceType &self) {TheSequenceType &out = self.ChangeSequence(); return out; }, "None");
cls.def_static("get_type_name_", (const char * (*)()) &TheHSequenceType::get_type_name, "None");
cls.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TheHSequenceType::get_type_descriptor, "None");
cls.def("DynamicType", (const opencascade::handle<Standard_Type> & (TheHSequenceType::*)() const) &TheHSequenceType::DynamicType, "None");

// Methods for excluded base of TheSequenceType which is the NCollection_Sequence<TheItemType> class template
cls.def("Size", (Standard_Integer(TheHSequenceType::*)() const) &TheHSequenceType::Size, "Number of items");
cls.def("Length", (Standard_Integer(TheHSequenceType::*)() const) &TheHSequenceType::Length, "Number of items");
cls.def("Lower", (Standard_Integer(TheHSequenceType::*)() const) &TheHSequenceType::Lower, "Method for consistency with other collections.");
cls.def("Upper", (Standard_Integer(TheHSequenceType::*)() const) &TheHSequenceType::Upper, "Method for consistency with other collections.");
cls.def("IsEmpty", (Standard_Boolean(TheHSequenceType::*)() const) &TheHSequenceType::IsEmpty, "Empty query");
cls.def("Reverse", (void (TheHSequenceType::*)()) &TheHSequenceType::Reverse, "Reverse sequence");
cls.def("Exchange", (void (TheHSequenceType::*)(const Standard_Integer, const Standard_Integer)) &TheHSequenceType::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
cls.def_static("delNode_", (void(*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TheHSequenceType::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
cls.def("Clear", [](TheHSequenceType &self) -> void { return self.Clear(); });
cls.def("Clear", (void (TheHSequenceType::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TheHSequenceType::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
cls.def("Assign", (TheSequenceType & (TheHSequenceType::*)(const TheSequenceType &)) &TheHSequenceType::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
// cls_NCollection_Sequence.def("operator=", (NCollection_Sequence<TheItemType> & (TheHSequenceType::*)(const NCollection_Sequence<TheItemType> &)) &TheHSequenceType::operator=, "Replacement operator", py::arg("theOther"));
cls.def("Remove", (void (TheHSequenceType::*)(typename TheHSequenceType::Iterator &)) &TheHSequenceType::Remove, "Remove one item", py::arg("thePosition"));
cls.def("Remove", (void (TheHSequenceType::*)(const Standard_Integer)) &TheHSequenceType::Remove, "Remove one item", py::arg("theIndex"));
cls.def("Remove", (void (TheHSequenceType::*)(const Standard_Integer, const Standard_Integer)) &TheHSequenceType::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
cls.def("Append", (void (TheHSequenceType::*)(const typename TheSequenceType::value_type &)) &TheHSequenceType::Append, "Append one item", py::arg("theItem"));
cls.def("Append", (void (TheHSequenceType::*)(TheSequenceType &)) &TheHSequenceType::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
cls.def("Prepend", (void (TheHSequenceType::*)(const typename TheSequenceType::value_type &)) &TheHSequenceType::Prepend, "Prepend one item", py::arg("theItem"));
cls.def("Prepend", (void (TheHSequenceType::*)(TheSequenceType &)) &TheHSequenceType::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
cls.def("InsertBefore", (void (TheHSequenceType::*)(const Standard_Integer, const typename TheSequenceType::value_type &)) &TheHSequenceType::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
cls.def("InsertBefore", (void (TheHSequenceType::*)(const Standard_Integer, TheSequenceType &)) &TheHSequenceType::InsertBefore, "InsertBefore theIndex another sequence (making it empty)", py::arg("theIndex"), py::arg("theSeq"));
cls.def("InsertAfter", (void (TheHSequenceType::*)(typename TheHSequenceType::Iterator &, const typename TheSequenceType::value_type &)) &TheHSequenceType::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
cls.def("InsertAfter", (void (TheHSequenceType::*)(const Standard_Integer, TheSequenceType &)) &TheHSequenceType::InsertAfter, "InsertAfter theIndex another sequence (making it empty)", py::arg("theIndex"), py::arg("theSeq"));
cls.def("InsertAfter", (void (TheHSequenceType::*)(const Standard_Integer, const typename TheSequenceType::value_type &)) &TheHSequenceType::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
cls.def("Split", (void (TheHSequenceType::*)(const Standard_Integer, TheSequenceType &)) &TheHSequenceType::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
cls.def("First", (const typename TheSequenceType::value_type & (TheHSequenceType::*)() const) &TheHSequenceType::First, "First item access");
cls.def("ChangeFirst", (typename TheSequenceType::value_type & (TheHSequenceType::*)()) &TheHSequenceType::ChangeFirst, "First item access");
cls.def("Last", (const typename TheSequenceType::value_type & (TheHSequenceType::*)() const) &TheHSequenceType::Last, "Last item access");
cls.def("ChangeLast", (typename TheSequenceType::value_type & (TheHSequenceType::*)()) &TheHSequenceType::ChangeLast, "Last item access");
cls.def("Value", (const typename TheSequenceType::value_type & (TheHSequenceType::*)(const Standard_Integer) const) &TheHSequenceType::Value, "Constant item access by theIndex", py::arg("theIndex"));
cls.def("__call__", (const typename TheSequenceType::value_type & (TheHSequenceType::*)(const Standard_Integer) const) &TheHSequenceType::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
cls.def("ChangeValue", (typename TheSequenceType::value_type & (TheHSequenceType::*)(const Standard_Integer)) &TheHSequenceType::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
cls.def("__call__", (typename TheSequenceType::value_type & (TheHSequenceType::*)(const Standard_Integer)) &TheHSequenceType::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
cls.def("SetValue", (void (TheHSequenceType::*)(const Standard_Integer, const typename TheSequenceType::value_type &)) &TheHSequenceType::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
cls.def("__iter__", [](const TheHSequenceType &self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

}
#endif
