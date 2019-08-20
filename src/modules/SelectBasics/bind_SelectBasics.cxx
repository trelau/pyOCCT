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
#include <SelectBasics.hxx>

void bind_SelectBasics(py::module &mod){

py::class_<SelectBasics, std::unique_ptr<SelectBasics>> cls_SelectBasics(mod, "SelectBasics", "interface class for dynamic selection");

// Constructors

// Fields

// Methods
// cls_SelectBasics.def_static("operator new_", (void * (*)(size_t)) &SelectBasics::operator new, "None", py::arg("theSize"));
// cls_SelectBasics.def_static("operator delete_", (void (*)(void *)) &SelectBasics::operator delete, "None", py::arg("theAddress"));
// cls_SelectBasics.def_static("operator new[]_", (void * (*)(size_t)) &SelectBasics::operator new[], "None", py::arg("theSize"));
// cls_SelectBasics.def_static("operator delete[]_", (void (*)(void *)) &SelectBasics::operator delete[], "None", py::arg("theAddress"));
// cls_SelectBasics.def_static("operator new_", (void * (*)(size_t, void *)) &SelectBasics::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_SelectBasics.def_static("operator delete_", (void (*)(void *, void *)) &SelectBasics::operator delete, "None", py::arg(""), py::arg(""));
cls_SelectBasics.def_static("MaxOwnerPriority_", (Standard_Integer (*)()) &SelectBasics::MaxOwnerPriority, "Structure to provide all-in-one result of selection of sensitive for 'Matches' method of SelectBasics_SensitiveEntity.");
cls_SelectBasics.def_static("MinOwnerPriority_", (Standard_Integer (*)()) &SelectBasics::MinOwnerPriority, "None");

// Enums

}