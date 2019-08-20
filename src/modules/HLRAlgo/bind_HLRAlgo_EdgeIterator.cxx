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
#include <HLRAlgo_EdgeStatus.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRAlgo_EdgeIterator.hxx>

void bind_HLRAlgo_EdgeIterator(py::module &mod){

py::class_<HLRAlgo_EdgeIterator, std::unique_ptr<HLRAlgo_EdgeIterator>> cls_HLRAlgo_EdgeIterator(mod, "HLRAlgo_EdgeIterator", "None");

// Constructors
cls_HLRAlgo_EdgeIterator.def(py::init<>());

// Fields

// Methods
// cls_HLRAlgo_EdgeIterator.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_EdgeIterator::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_EdgeIterator.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_EdgeIterator::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_EdgeIterator.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_EdgeIterator::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_EdgeIterator.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_EdgeIterator::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_EdgeIterator.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_EdgeIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_EdgeIterator.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_EdgeIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_EdgeIterator.def("InitHidden", (void (HLRAlgo_EdgeIterator::*)(HLRAlgo_EdgeStatus &)) &HLRAlgo_EdgeIterator::InitHidden, "None", py::arg("status"));
cls_HLRAlgo_EdgeIterator.def("MoreHidden", (Standard_Boolean (HLRAlgo_EdgeIterator::*)() const) &HLRAlgo_EdgeIterator::MoreHidden, "None");
cls_HLRAlgo_EdgeIterator.def("NextHidden", (void (HLRAlgo_EdgeIterator::*)()) &HLRAlgo_EdgeIterator::NextHidden, "None");
cls_HLRAlgo_EdgeIterator.def("Hidden", [](HLRAlgo_EdgeIterator &self, Standard_Real & Start, Standard_ShortReal & TolStart, Standard_Real & End, Standard_ShortReal & TolEnd){ self.Hidden(Start, TolStart, End, TolEnd); return std::tuple<Standard_Real &, Standard_Real &>(Start, End); }, "Returns the bounds and the tolerances of the current Hidden Interval", py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));
cls_HLRAlgo_EdgeIterator.def("InitVisible", (void (HLRAlgo_EdgeIterator::*)(HLRAlgo_EdgeStatus &)) &HLRAlgo_EdgeIterator::InitVisible, "None", py::arg("status"));
cls_HLRAlgo_EdgeIterator.def("MoreVisible", (Standard_Boolean (HLRAlgo_EdgeIterator::*)() const) &HLRAlgo_EdgeIterator::MoreVisible, "None");
cls_HLRAlgo_EdgeIterator.def("NextVisible", (void (HLRAlgo_EdgeIterator::*)()) &HLRAlgo_EdgeIterator::NextVisible, "None");
cls_HLRAlgo_EdgeIterator.def("Visible", [](HLRAlgo_EdgeIterator &self, Standard_Real & Start, Standard_ShortReal & TolStart, Standard_Real & End, Standard_ShortReal & TolEnd){ self.Visible(Start, TolStart, End, TolEnd); return std::tuple<Standard_Real &, Standard_Real &>(Start, End); }, "Returns the bounds and the tolerances of the current Visible Interval", py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));

// Enums

}