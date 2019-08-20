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
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_Type.hxx>
#include <Interface_EntityList.hxx>

void bind_Interface_EntityList(py::module &mod){

py::class_<Interface_EntityList, std::unique_ptr<Interface_EntityList>> cls_Interface_EntityList(mod, "Interface_EntityList", "This class defines a list of Entities (Transient Objects), it can be used as a field of other Transient classes, with these features : - oriented to define a little list, that is, slower than an Array or a Map of Entities for a big count (about 100 and over), but faster than a Sequence - allows to work as a Sequence, limited to Clear, Append, Remove, Access to an Item identified by its rank in the list - space saving, compared to a Sequence, especially for little amounts; better than an Array for a very little amount (less than 10) but less good for a greater amount");

// Constructors
cls_Interface_EntityList.def(py::init<>());

// Fields

// Methods
// cls_Interface_EntityList.def_static("operator new_", (void * (*)(size_t)) &Interface_EntityList::operator new, "None", py::arg("theSize"));
// cls_Interface_EntityList.def_static("operator delete_", (void (*)(void *)) &Interface_EntityList::operator delete, "None", py::arg("theAddress"));
// cls_Interface_EntityList.def_static("operator new[]_", (void * (*)(size_t)) &Interface_EntityList::operator new[], "None", py::arg("theSize"));
// cls_Interface_EntityList.def_static("operator delete[]_", (void (*)(void *)) &Interface_EntityList::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_EntityList.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_EntityList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_EntityList.def_static("operator delete_", (void (*)(void *, void *)) &Interface_EntityList::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_EntityList.def("Clear", (void (Interface_EntityList::*)()) &Interface_EntityList::Clear, "Clears the List");
cls_Interface_EntityList.def("Append", (void (Interface_EntityList::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityList::Append, "Appends an Entity, that is to the END of the list (keeps order, but works slowerly than Add, see below)", py::arg("ent"));
cls_Interface_EntityList.def("Add", (void (Interface_EntityList::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityList::Add, "Adds an Entity to the list, that is, with NO REGARD about the order (faster than Append if count becomes greater than 10)", py::arg("ent"));
cls_Interface_EntityList.def("Remove", (void (Interface_EntityList::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityList::Remove, "Removes an Entity from the list, if it is there", py::arg("ent"));
cls_Interface_EntityList.def("Remove", (void (Interface_EntityList::*)(const Standard_Integer)) &Interface_EntityList::Remove, "Removes an Entity from the list, given its rank", py::arg("num"));
cls_Interface_EntityList.def("IsEmpty", (Standard_Boolean (Interface_EntityList::*)() const) &Interface_EntityList::IsEmpty, "Returns True if the list is empty");
cls_Interface_EntityList.def("NbEntities", (Standard_Integer (Interface_EntityList::*)() const) &Interface_EntityList::NbEntities, "Returns count of recorded Entities");
cls_Interface_EntityList.def("Value", (const opencascade::handle<Standard_Transient> & (Interface_EntityList::*)(const Standard_Integer) const) &Interface_EntityList::Value, "Returns an Item given its number. Beware about the way the list was filled (see above, Add and Append)", py::arg("num"));
cls_Interface_EntityList.def("SetValue", (void (Interface_EntityList::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &Interface_EntityList::SetValue, "Returns an Item given its number. Beware about the way the list was filled (see above, Add and Append)", py::arg("num"), py::arg("ent"));
cls_Interface_EntityList.def("FillIterator", (void (Interface_EntityList::*)(Interface_EntityIterator &) const) &Interface_EntityList::FillIterator, "fills an Iterator with the content of the list (normal way to consult a list which has been filled with Add)", py::arg("iter"));
cls_Interface_EntityList.def("NbTypedEntities", (Standard_Integer (Interface_EntityList::*)(const opencascade::handle<Standard_Type> &) const) &Interface_EntityList::NbTypedEntities, "Returns count of Entities of a given Type (0 : none)", py::arg("atype"));
cls_Interface_EntityList.def("TypedEntity", [](Interface_EntityList &self, const opencascade::handle<Standard_Type> & a0) -> opencascade::handle<Standard_Transient> { return self.TypedEntity(a0); });
cls_Interface_EntityList.def("TypedEntity", (opencascade::handle<Standard_Transient> (Interface_EntityList::*)(const opencascade::handle<Standard_Type> &, const Standard_Integer) const) &Interface_EntityList::TypedEntity, "Returns the Entity which is of a given type. If num = 0 (D), there must be ONE AND ONLY ONE If num > 0, returns the num-th entity of this type", py::arg("atype"), py::arg("num"));

// Enums

}