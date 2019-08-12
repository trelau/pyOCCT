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
#include <Standard_TypeDef.hxx>
#include <TDF_LabelNodePtr.hxx>
#include <TDF_ChildIterator.hxx>

void bind_TDF_ChildIterator(py::module &mod){

py::class_<TDF_ChildIterator, std::unique_ptr<TDF_ChildIterator, Deleter<TDF_ChildIterator>>> cls_TDF_ChildIterator(mod, "TDF_ChildIterator", "Iterates on the children of a label, at the first level only. It is possible to ask the iterator to explore all the sub label levels of the given one, with the option 'allLevels'.");

// Constructors
cls_TDF_ChildIterator.def(py::init<>());
cls_TDF_ChildIterator.def(py::init<const TDF_Label &>(), py::arg("aLabel"));
cls_TDF_ChildIterator.def(py::init<const TDF_Label &, const Standard_Boolean>(), py::arg("aLabel"), py::arg("allLevels"));

// Fields

// Methods
// cls_TDF_ChildIterator.def_static("operator new_", (void * (*)(size_t)) &TDF_ChildIterator::operator new, "None", py::arg("theSize"));
// cls_TDF_ChildIterator.def_static("operator delete_", (void (*)(void *)) &TDF_ChildIterator::operator delete, "None", py::arg("theAddress"));
// cls_TDF_ChildIterator.def_static("operator new[]_", (void * (*)(size_t)) &TDF_ChildIterator::operator new[], "None", py::arg("theSize"));
// cls_TDF_ChildIterator.def_static("operator delete[]_", (void (*)(void *)) &TDF_ChildIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TDF_ChildIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TDF_ChildIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF_ChildIterator.def_static("operator delete_", (void (*)(void *, void *)) &TDF_ChildIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF_ChildIterator.def("Initialize", [](TDF_ChildIterator &self, const TDF_Label & a0) -> void { return self.Initialize(a0); });
cls_TDF_ChildIterator.def("Initialize", (void (TDF_ChildIterator::*)(const TDF_Label &, const Standard_Boolean)) &TDF_ChildIterator::Initialize, "Initializes the iteration on the children of the given label. If <allLevels> option is set to true, it explores not only the first, but all the sub label levels. If allLevels is false, only the first level of child labels is explored. In the example below, the label is iterated using Initialize, More and Next and its child labels dumped using TDF_Tool::Entry. Example void DumpChildren(const TDF_Label& aLabel) { TDF_ChildIterator it; TCollection_AsciiString es; for (it.Initialize(aLabel,Standard_True); it.More(); it.Next()){ TDF_Tool::Entry(it.Value(),es); cout << as.ToCString() << endl; } }", py::arg("aLabel"), py::arg("allLevels"));
cls_TDF_ChildIterator.def("More", (Standard_Boolean (TDF_ChildIterator::*)() const) &TDF_ChildIterator::More, "Returns true if a current label is found in the iteration process.");
cls_TDF_ChildIterator.def("Next", (void (TDF_ChildIterator::*)()) &TDF_ChildIterator::Next, "Move the current iteration to the next Item.");
cls_TDF_ChildIterator.def("NextBrother", (void (TDF_ChildIterator::*)()) &TDF_ChildIterator::NextBrother, "Moves this iteration to the next brother label. A brother label is one with the same father as an initial label. Use this function when the non-empty constructor or Initialize has allLevels set to true. The result is that the iteration does not explore the children of the current label. This method is interesting only with 'allLevels' behavior, because it avoids to explore the current label children.");
cls_TDF_ChildIterator.def("Value", (const TDF_Label (TDF_ChildIterator::*)() const) &TDF_ChildIterator::Value, "Returns the current label; or, if there is none, a null label.");

// Enums

}