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
#include <TColStd_HSequenceOfTransient.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_IntVal.hxx>

void bind_Interface_EntityIterator(py::module &mod){

py::class_<Interface_EntityIterator, std::unique_ptr<Interface_EntityIterator, Deleter<Interface_EntityIterator>>> cls_Interface_EntityIterator(mod, "Interface_EntityIterator", "Defines an Iterator on Entities. Allows considering of various criteria");

// Constructors
cls_Interface_EntityIterator.def(py::init<>());
cls_Interface_EntityIterator.def(py::init<const opencascade::handle<TColStd_HSequenceOfTransient> &>(), py::arg("list"));

// Fields

// Methods
// cls_Interface_EntityIterator.def_static("operator new_", (void * (*)(size_t)) &Interface_EntityIterator::operator new, "None", py::arg("theSize"));
// cls_Interface_EntityIterator.def_static("operator delete_", (void (*)(void *)) &Interface_EntityIterator::operator delete, "None", py::arg("theAddress"));
// cls_Interface_EntityIterator.def_static("operator new[]_", (void * (*)(size_t)) &Interface_EntityIterator::operator new[], "None", py::arg("theSize"));
// cls_Interface_EntityIterator.def_static("operator delete[]_", (void (*)(void *)) &Interface_EntityIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_EntityIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_EntityIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_EntityIterator.def_static("operator delete_", (void (*)(void *, void *)) &Interface_EntityIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_EntityIterator.def("AddList", (void (Interface_EntityIterator::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &Interface_EntityIterator::AddList, "Gets a list of entities and adds its to the iteration list", py::arg("list"));
cls_Interface_EntityIterator.def("AddItem", (void (Interface_EntityIterator::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityIterator::AddItem, "Adds to the iteration list a defined entity", py::arg("anentity"));
cls_Interface_EntityIterator.def("GetOneItem", (void (Interface_EntityIterator::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityIterator::GetOneItem, "same as AddItem (kept for compatibility)", py::arg("anentity"));
cls_Interface_EntityIterator.def("SelectType", (void (Interface_EntityIterator::*)(const opencascade::handle<Standard_Type> &, const Standard_Boolean)) &Interface_EntityIterator::SelectType, "Selects entities with are Kind of a given type, keep only them (is keep is True) or reject only them (if keep is False)", py::arg("atype"), py::arg("keep"));
cls_Interface_EntityIterator.def("NbEntities", (Standard_Integer (Interface_EntityIterator::*)() const) &Interface_EntityIterator::NbEntities, "Returns count of entities which will be iterated on Calls Start if not yet done");
cls_Interface_EntityIterator.def("NbTyped", (Standard_Integer (Interface_EntityIterator::*)(const opencascade::handle<Standard_Type> &) const) &Interface_EntityIterator::NbTyped, "Returns count of entities of a given type (kind of)", py::arg("type"));
cls_Interface_EntityIterator.def("Typed", (Interface_EntityIterator (Interface_EntityIterator::*)(const opencascade::handle<Standard_Type> &) const) &Interface_EntityIterator::Typed, "Returns the list of entities of a given type (kind of)", py::arg("type"));
cls_Interface_EntityIterator.def("Start", (void (Interface_EntityIterator::*)() const) &Interface_EntityIterator::Start, "Allows re-iteration (useless for the first iteration)");
cls_Interface_EntityIterator.def("More", (Standard_Boolean (Interface_EntityIterator::*)() const) &Interface_EntityIterator::More, "Says if there are other entities (vertices) to iterate the first time, calls Start");
cls_Interface_EntityIterator.def("Next", (void (Interface_EntityIterator::*)() const) &Interface_EntityIterator::Next, "Sets iteration to the next entity (vertex) to give");
cls_Interface_EntityIterator.def("Value", (const opencascade::handle<Standard_Transient> & (Interface_EntityIterator::*)() const) &Interface_EntityIterator::Value, "Returns the current Entity iterated, to be used by Interface tools");
cls_Interface_EntityIterator.def("Content", (opencascade::handle<TColStd_HSequenceOfTransient> (Interface_EntityIterator::*)() const) &Interface_EntityIterator::Content, "Returns the content of the Iterator, accessed through a Handle to be used by a frontal-engine logic Returns an empty Sequence if the Iterator is empty Calls Start if not yet done");
cls_Interface_EntityIterator.def("Destroy", (void (Interface_EntityIterator::*)()) &Interface_EntityIterator::Destroy, "Clears data of iteration");

// Enums

}