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
#include <TopOpeBRep_VPointInter.hxx>
#include <TopOpeBRep_PLineInter.hxx>
#include <TopOpeBRep_VPointInterIterator.hxx>

void bind_TopOpeBRep_VPointInterIterator(py::module &mod){

py::class_<TopOpeBRep_VPointInterIterator, std::unique_ptr<TopOpeBRep_VPointInterIterator, Deleter<TopOpeBRep_VPointInterIterator>>> cls_TopOpeBRep_VPointInterIterator(mod, "TopOpeBRep_VPointInterIterator", "None");

// Constructors
cls_TopOpeBRep_VPointInterIterator.def(py::init<>());
cls_TopOpeBRep_VPointInterIterator.def(py::init<const TopOpeBRep_LineInter &>(), py::arg("LI"));

// Fields

// Methods
// cls_TopOpeBRep_VPointInterIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_VPointInterIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_VPointInterIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_VPointInterIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_VPointInterIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_VPointInterIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_VPointInterIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_VPointInterIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_VPointInterIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_VPointInterIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_VPointInterIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_VPointInterIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_VPointInterIterator.def("Init", [](TopOpeBRep_VPointInterIterator &self, const TopOpeBRep_LineInter & a0) -> void { return self.Init(a0); });
cls_TopOpeBRep_VPointInterIterator.def("Init", (void (TopOpeBRep_VPointInterIterator::*)(const TopOpeBRep_LineInter &, const Standard_Boolean)) &TopOpeBRep_VPointInterIterator::Init, "None", py::arg("LI"), py::arg("checkkeep"));
cls_TopOpeBRep_VPointInterIterator.def("Init", (void (TopOpeBRep_VPointInterIterator::*)()) &TopOpeBRep_VPointInterIterator::Init, "None");
cls_TopOpeBRep_VPointInterIterator.def("More", (Standard_Boolean (TopOpeBRep_VPointInterIterator::*)() const) &TopOpeBRep_VPointInterIterator::More, "None");
cls_TopOpeBRep_VPointInterIterator.def("Next", (void (TopOpeBRep_VPointInterIterator::*)()) &TopOpeBRep_VPointInterIterator::Next, "None");
cls_TopOpeBRep_VPointInterIterator.def("CurrentVP", (const TopOpeBRep_VPointInter & (TopOpeBRep_VPointInterIterator::*)()) &TopOpeBRep_VPointInterIterator::CurrentVP, "None");
cls_TopOpeBRep_VPointInterIterator.def("CurrentVPIndex", (Standard_Integer (TopOpeBRep_VPointInterIterator::*)() const) &TopOpeBRep_VPointInterIterator::CurrentVPIndex, "None");
cls_TopOpeBRep_VPointInterIterator.def("ChangeCurrentVP", (TopOpeBRep_VPointInter & (TopOpeBRep_VPointInterIterator::*)()) &TopOpeBRep_VPointInterIterator::ChangeCurrentVP, "None");
cls_TopOpeBRep_VPointInterIterator.def("PLineInterDummy", (TopOpeBRep_PLineInter (TopOpeBRep_VPointInterIterator::*)() const) &TopOpeBRep_VPointInterIterator::PLineInterDummy, "None");

// Enums

}