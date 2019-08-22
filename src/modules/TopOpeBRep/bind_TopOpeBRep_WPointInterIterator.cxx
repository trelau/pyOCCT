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
#include <TopOpeBRep_LineInter.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRep_WPointInter.hxx>
#include <TopOpeBRep_PLineInter.hxx>
#include <TopOpeBRep_WPointInterIterator.hxx>

void bind_TopOpeBRep_WPointInterIterator(py::module &mod){

py::class_<TopOpeBRep_WPointInterIterator> cls_TopOpeBRep_WPointInterIterator(mod, "TopOpeBRep_WPointInterIterator", "None");

// Constructors
cls_TopOpeBRep_WPointInterIterator.def(py::init<>());
cls_TopOpeBRep_WPointInterIterator.def(py::init<const TopOpeBRep_LineInter &>(), py::arg("LI"));

// Fields

// Methods
// cls_TopOpeBRep_WPointInterIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_WPointInterIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_WPointInterIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_WPointInterIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_WPointInterIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_WPointInterIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_WPointInterIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_WPointInterIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_WPointInterIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_WPointInterIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_WPointInterIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_WPointInterIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_WPointInterIterator.def("Init", (void (TopOpeBRep_WPointInterIterator::*)(const TopOpeBRep_LineInter &)) &TopOpeBRep_WPointInterIterator::Init, "None", py::arg("LI"));
cls_TopOpeBRep_WPointInterIterator.def("Init", (void (TopOpeBRep_WPointInterIterator::*)()) &TopOpeBRep_WPointInterIterator::Init, "None");
cls_TopOpeBRep_WPointInterIterator.def("More", (Standard_Boolean (TopOpeBRep_WPointInterIterator::*)() const) &TopOpeBRep_WPointInterIterator::More, "None");
cls_TopOpeBRep_WPointInterIterator.def("Next", (void (TopOpeBRep_WPointInterIterator::*)()) &TopOpeBRep_WPointInterIterator::Next, "None");
cls_TopOpeBRep_WPointInterIterator.def("CurrentWP", (const TopOpeBRep_WPointInter & (TopOpeBRep_WPointInterIterator::*)()) &TopOpeBRep_WPointInterIterator::CurrentWP, "None");
cls_TopOpeBRep_WPointInterIterator.def("PLineInterDummy", (TopOpeBRep_PLineInter (TopOpeBRep_WPointInterIterator::*)() const) &TopOpeBRep_WPointInterIterator::PLineInterDummy, "None");

// Enums

}