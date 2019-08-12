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
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_ChildIterator.hxx>
#include <TDF_ChildIDIterator.hxx>

void bind_TDF_ChildIDIterator(py::module &mod){

py::class_<TDF_ChildIDIterator, std::unique_ptr<TDF_ChildIDIterator, Deleter<TDF_ChildIDIterator>>> cls_TDF_ChildIDIterator(mod, "TDF_ChildIDIterator", "Iterates on the children of a label, to find attributes having ID as Attribute ID.");

// Constructors
cls_TDF_ChildIDIterator.def(py::init<>());
cls_TDF_ChildIDIterator.def(py::init<const TDF_Label &, const Standard_GUID &>(), py::arg("aLabel"), py::arg("anID"));
cls_TDF_ChildIDIterator.def(py::init<const TDF_Label &, const Standard_GUID &, const Standard_Boolean>(), py::arg("aLabel"), py::arg("anID"), py::arg("allLevels"));

// Fields

// Methods
// cls_TDF_ChildIDIterator.def_static("operator new_", (void * (*)(size_t)) &TDF_ChildIDIterator::operator new, "None", py::arg("theSize"));
// cls_TDF_ChildIDIterator.def_static("operator delete_", (void (*)(void *)) &TDF_ChildIDIterator::operator delete, "None", py::arg("theAddress"));
// cls_TDF_ChildIDIterator.def_static("operator new[]_", (void * (*)(size_t)) &TDF_ChildIDIterator::operator new[], "None", py::arg("theSize"));
// cls_TDF_ChildIDIterator.def_static("operator delete[]_", (void (*)(void *)) &TDF_ChildIDIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TDF_ChildIDIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TDF_ChildIDIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF_ChildIDIterator.def_static("operator delete_", (void (*)(void *, void *)) &TDF_ChildIDIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF_ChildIDIterator.def("Initialize", [](TDF_ChildIDIterator &self, const TDF_Label & a0, const Standard_GUID & a1) -> void { return self.Initialize(a0, a1); });
cls_TDF_ChildIDIterator.def("Initialize", (void (TDF_ChildIDIterator::*)(const TDF_Label &, const Standard_GUID &, const Standard_Boolean)) &TDF_ChildIDIterator::Initialize, "Initializes the iteration on the children of the given label. If <allLevels> option is set to true, it explores not only the first, but all the sub label levels.", py::arg("aLabel"), py::arg("anID"), py::arg("allLevels"));
cls_TDF_ChildIDIterator.def("More", (Standard_Boolean (TDF_ChildIDIterator::*)() const) &TDF_ChildIDIterator::More, "Returns True if there is a current Item in the iteration.");
cls_TDF_ChildIDIterator.def("Next", (void (TDF_ChildIDIterator::*)()) &TDF_ChildIDIterator::Next, "Move to the next Item");
cls_TDF_ChildIDIterator.def("NextBrother", (void (TDF_ChildIDIterator::*)()) &TDF_ChildIDIterator::NextBrother, "Move to the next Brother. If there is none, go up etc. This method is interesting only with 'allLevels' behavior, because it avoids to explore the current label children.");
cls_TDF_ChildIDIterator.def("Value", (opencascade::handle<TDF_Attribute> (TDF_ChildIDIterator::*)() const) &TDF_ChildIDIterator::Value, "Returns the current item; a null handle if there is none.");

// Enums

}