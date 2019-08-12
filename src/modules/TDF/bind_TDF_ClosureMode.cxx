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
#include <TDF_ClosureMode.hxx>

void bind_TDF_ClosureMode(py::module &mod){

py::class_<TDF_ClosureMode, std::unique_ptr<TDF_ClosureMode, Deleter<TDF_ClosureMode>>> cls_TDF_ClosureMode(mod, "TDF_ClosureMode", "This class provides options closure management.");

// Constructors
cls_TDF_ClosureMode.def(py::init<>());
cls_TDF_ClosureMode.def(py::init<const Standard_Boolean>(), py::arg("aMode"));

// Fields

// Methods
// cls_TDF_ClosureMode.def_static("operator new_", (void * (*)(size_t)) &TDF_ClosureMode::operator new, "None", py::arg("theSize"));
// cls_TDF_ClosureMode.def_static("operator delete_", (void (*)(void *)) &TDF_ClosureMode::operator delete, "None", py::arg("theAddress"));
// cls_TDF_ClosureMode.def_static("operator new[]_", (void * (*)(size_t)) &TDF_ClosureMode::operator new[], "None", py::arg("theSize"));
// cls_TDF_ClosureMode.def_static("operator delete[]_", (void (*)(void *)) &TDF_ClosureMode::operator delete[], "None", py::arg("theAddress"));
// cls_TDF_ClosureMode.def_static("operator new_", (void * (*)(size_t, void *)) &TDF_ClosureMode::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF_ClosureMode.def_static("operator delete_", (void (*)(void *, void *)) &TDF_ClosureMode::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF_ClosureMode.def("Descendants", (void (TDF_ClosureMode::*)(const Standard_Boolean)) &TDF_ClosureMode::Descendants, "Sets the mode 'Descendants' to <aStatus>.", py::arg("aStatus"));
cls_TDF_ClosureMode.def("Descendants", (Standard_Boolean (TDF_ClosureMode::*)() const) &TDF_ClosureMode::Descendants, "Returns true if the mode 'Descendants' is set.");
cls_TDF_ClosureMode.def("References", (void (TDF_ClosureMode::*)(const Standard_Boolean)) &TDF_ClosureMode::References, "Sets the mode 'References' to <aStatus>.", py::arg("aStatus"));
cls_TDF_ClosureMode.def("References", (Standard_Boolean (TDF_ClosureMode::*)() const) &TDF_ClosureMode::References, "Returns true if the mode 'References' is set.");

// Enums

}