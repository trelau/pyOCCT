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
#include <Interface_IntList.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_Interface_IntList(py::module &mod){

py::class_<Interface_IntList> cls_Interface_IntList(mod, "Interface_IntList", "This class detains the data which describe a Graph. A Graph has two lists, one for shared refs, one for sharing refs (the reverses). Each list comprises, for each Entity of the Model of the Graph, a list of Entities (shared or sharing). In fact, entities are identified by their numbers in the Model or Graph : this gives better performances.");

// Constructors
cls_Interface_IntList.def(py::init<>());
cls_Interface_IntList.def(py::init<const Standard_Integer>(), py::arg("nbe"));
cls_Interface_IntList.def(py::init<const Interface_IntList &, const Standard_Boolean>(), py::arg("other"), py::arg("copied"));

// Fields

// Methods
// cls_Interface_IntList.def_static("operator new_", (void * (*)(size_t)) &Interface_IntList::operator new, "None", py::arg("theSize"));
// cls_Interface_IntList.def_static("operator delete_", (void (*)(void *)) &Interface_IntList::operator delete, "None", py::arg("theAddress"));
// cls_Interface_IntList.def_static("operator new[]_", (void * (*)(size_t)) &Interface_IntList::operator new[], "None", py::arg("theSize"));
// cls_Interface_IntList.def_static("operator delete[]_", (void (*)(void *)) &Interface_IntList::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_IntList.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_IntList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_IntList.def_static("operator delete_", (void (*)(void *, void *)) &Interface_IntList::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_IntList.def("Initialize", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::Initialize, "Initialize IntList by number of entities.", py::arg("nbe"));
cls_Interface_IntList.def("Internals", [](Interface_IntList &self, Standard_Integer & nbrefs, opencascade::handle<TColStd_HArray1OfInteger> & ents, opencascade::handle<TColStd_HArray1OfInteger> & refs){ self.Internals(nbrefs, ents, refs); return nbrefs; }, "Returns internal values, used for copying", py::arg("nbrefs"), py::arg("ents"), py::arg("refs"));
cls_Interface_IntList.def("NbEntities", (Standard_Integer (Interface_IntList::*)() const) &Interface_IntList::NbEntities, "Returns count of entities to be aknowledged");
cls_Interface_IntList.def("SetNbEntities", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::SetNbEntities, "Changes the count of entities (ignored if decreased)", py::arg("nbe"));
cls_Interface_IntList.def("SetNumber", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::SetNumber, "Sets an entity number as current (for read and fill)", py::arg("number"));
cls_Interface_IntList.def("Number", (Standard_Integer (Interface_IntList::*)() const) &Interface_IntList::Number, "Returns the current entity number");
cls_Interface_IntList.def("List", [](Interface_IntList &self, const Standard_Integer a0) -> Interface_IntList { return self.List(a0); });
cls_Interface_IntList.def("List", (Interface_IntList (Interface_IntList::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_IntList::List, "Returns an IntList, identical to <me> but set to a specified entity Number By default, not copied (in order to be read) Specified <copied> to produce another list and edit it", py::arg("number"), py::arg("copied"));
cls_Interface_IntList.def("SetRedefined", (void (Interface_IntList::*)(const Standard_Boolean)) &Interface_IntList::SetRedefined, "Sets current entity list to be redefined or not This is used in a Graph for redefinition list : it can be disable (no redefinition, i.e. list is cleared), or enabled (starts as empty). The original list has not to be 'redefined'", py::arg("mode"));
cls_Interface_IntList.def("Reservate", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::Reservate, "Makes a reservation for <count> references to be later attached to the current entity. If required, it increases the size of array used to store refs. Remark that if count is less than two, it does nothing (because immediate storing)", py::arg("count"));
cls_Interface_IntList.def("Add", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::Add, "Adds a reference (as an integer value, an entity number) to the current entity number. Zero is ignored", py::arg("ref"));
cls_Interface_IntList.def("Length", (Standard_Integer (Interface_IntList::*)() const) &Interface_IntList::Length, "Returns the count of refs attached to current entity number");
cls_Interface_IntList.def("IsRedefined", [](Interface_IntList &self) -> Standard_Boolean { return self.IsRedefined(); });
cls_Interface_IntList.def("IsRedefined", (Standard_Boolean (Interface_IntList::*)(const Standard_Integer) const) &Interface_IntList::IsRedefined, "Returns True if the list for a number (default is taken as current) is 'redefined' (usefull for empty list)", py::arg("num"));
cls_Interface_IntList.def("Value", (Standard_Integer (Interface_IntList::*)(const Standard_Integer) const) &Interface_IntList::Value, "Returns a reference number in the list for current number, according to its rank", py::arg("num"));
cls_Interface_IntList.def("Remove", (Standard_Boolean (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::Remove, "Removes an item in the list for current number, given its rank Returns True if done, False else", py::arg("num"));
cls_Interface_IntList.def("Clear", (void (Interface_IntList::*)()) &Interface_IntList::Clear, "Clears all data, hence each entity number has an empty list");
cls_Interface_IntList.def("AdjustSize", [](Interface_IntList &self) -> void { return self.AdjustSize(); });
cls_Interface_IntList.def("AdjustSize", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::AdjustSize, "Resizes lists to exact sizes. For list of refs, a positive margin can be added.", py::arg("margin"));

// Enums

}