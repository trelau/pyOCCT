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
#include <TopLoc_ItemLocation.hxx>
#include <TopLoc_SListOfItemLocation.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopLoc_SListNodeOfItemLocation.hxx>

void bind_TopLoc_SListOfItemLocation(py::module &mod){

py::class_<TopLoc_SListOfItemLocation, std::unique_ptr<TopLoc_SListOfItemLocation, Deleter<TopLoc_SListOfItemLocation>>> cls_TopLoc_SListOfItemLocation(mod, "TopLoc_SListOfItemLocation", "An SListOfItemLocation is a LISP like list of Items. An SListOfItemLocation is : . Empty. . Or it has a Value and a Tail which is an other SListOfItemLocation.");

// Constructors
cls_TopLoc_SListOfItemLocation.def(py::init<>());
cls_TopLoc_SListOfItemLocation.def(py::init<const TopLoc_ItemLocation &, const TopLoc_SListOfItemLocation &>(), py::arg("anItem"), py::arg("aTail"));
cls_TopLoc_SListOfItemLocation.def(py::init<const TopLoc_SListOfItemLocation &>(), py::arg("Other"));

// Fields

// Methods
// cls_TopLoc_SListOfItemLocation.def_static("operator new_", (void * (*)(size_t)) &TopLoc_SListOfItemLocation::operator new, "None", py::arg("theSize"));
// cls_TopLoc_SListOfItemLocation.def_static("operator delete_", (void (*)(void *)) &TopLoc_SListOfItemLocation::operator delete, "None", py::arg("theAddress"));
// cls_TopLoc_SListOfItemLocation.def_static("operator new[]_", (void * (*)(size_t)) &TopLoc_SListOfItemLocation::operator new[], "None", py::arg("theSize"));
// cls_TopLoc_SListOfItemLocation.def_static("operator delete[]_", (void (*)(void *)) &TopLoc_SListOfItemLocation::operator delete[], "None", py::arg("theAddress"));
// cls_TopLoc_SListOfItemLocation.def_static("operator new_", (void * (*)(size_t, void *)) &TopLoc_SListOfItemLocation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopLoc_SListOfItemLocation.def_static("operator delete_", (void (*)(void *, void *)) &TopLoc_SListOfItemLocation::operator delete, "None", py::arg(""), py::arg(""));
cls_TopLoc_SListOfItemLocation.def("Assign", (TopLoc_SListOfItemLocation & (TopLoc_SListOfItemLocation::*)(const TopLoc_SListOfItemLocation &)) &TopLoc_SListOfItemLocation::Assign, "Sets a list from an other one. The lists are shared. The list itself is returned.", py::arg("Other"));
// cls_TopLoc_SListOfItemLocation.def("operator=", (TopLoc_SListOfItemLocation & (TopLoc_SListOfItemLocation::*)(const TopLoc_SListOfItemLocation &)) &TopLoc_SListOfItemLocation::operator=, "None", py::arg("Other"));
cls_TopLoc_SListOfItemLocation.def("IsEmpty", (Standard_Boolean (TopLoc_SListOfItemLocation::*)() const) &TopLoc_SListOfItemLocation::IsEmpty, "None");
cls_TopLoc_SListOfItemLocation.def("Clear", (void (TopLoc_SListOfItemLocation::*)()) &TopLoc_SListOfItemLocation::Clear, "Sets the list to be empty.");
cls_TopLoc_SListOfItemLocation.def("Value", (const TopLoc_ItemLocation & (TopLoc_SListOfItemLocation::*)() const) &TopLoc_SListOfItemLocation::Value, "Returns the current value of the list. An error is raised if the list is empty.");
cls_TopLoc_SListOfItemLocation.def("Tail", (const TopLoc_SListOfItemLocation & (TopLoc_SListOfItemLocation::*)() const) &TopLoc_SListOfItemLocation::Tail, "Returns the current tail of the list. On an empty list the tail is the list itself.");
cls_TopLoc_SListOfItemLocation.def("Construct", (void (TopLoc_SListOfItemLocation::*)(const TopLoc_ItemLocation &)) &TopLoc_SListOfItemLocation::Construct, "Replaces the list by a list with <anItem> as Value and the list <me> as tail.", py::arg("anItem"));
cls_TopLoc_SListOfItemLocation.def("ToTail", (void (TopLoc_SListOfItemLocation::*)()) &TopLoc_SListOfItemLocation::ToTail, "Replaces the list <me> by its tail.");
cls_TopLoc_SListOfItemLocation.def("More", (Standard_Boolean (TopLoc_SListOfItemLocation::*)() const) &TopLoc_SListOfItemLocation::More, "Returns True if the iterator has a current value. This is !IsEmpty()");
cls_TopLoc_SListOfItemLocation.def("Next", (void (TopLoc_SListOfItemLocation::*)()) &TopLoc_SListOfItemLocation::Next, "Moves the iterator to the next object in the list. If the iterator is empty it will stay empty. This is ToTail()");

// Enums

}