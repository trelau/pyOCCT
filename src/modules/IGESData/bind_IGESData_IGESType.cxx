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
#include <IGESData_IGESType.hxx>

void bind_IGESData_IGESType(py::module &mod){

py::class_<IGESData_IGESType, std::unique_ptr<IGESData_IGESType>> cls_IGESData_IGESType(mod, "IGESData_IGESType", "taken from directory part of an entity (from file or model), gives 'type' and 'form' data, used to recognize entity's type");

// Constructors
cls_IGESData_IGESType.def(py::init<>());
cls_IGESData_IGESType.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("atype"), py::arg("aform"));

// Fields

// Methods
// cls_IGESData_IGESType.def_static("operator new_", (void * (*)(size_t)) &IGESData_IGESType::operator new, "None", py::arg("theSize"));
// cls_IGESData_IGESType.def_static("operator delete_", (void (*)(void *)) &IGESData_IGESType::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_IGESType.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_IGESType::operator new[], "None", py::arg("theSize"));
// cls_IGESData_IGESType.def_static("operator delete[]_", (void (*)(void *)) &IGESData_IGESType::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_IGESType.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_IGESType::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_IGESType.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_IGESType::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_IGESType.def("Type", (Standard_Integer (IGESData_IGESType::*)() const) &IGESData_IGESType::Type, "returns 'type' data");
cls_IGESData_IGESType.def("Form", (Standard_Integer (IGESData_IGESType::*)() const) &IGESData_IGESType::Form, "returns 'form' data");
cls_IGESData_IGESType.def("IsEqual", (Standard_Boolean (IGESData_IGESType::*)(const IGESData_IGESType &) const) &IGESData_IGESType::IsEqual, "compares two IGESTypes, avoiding comparing their fields", py::arg("another"));
cls_IGESData_IGESType.def("__eq__", (Standard_Boolean (IGESData_IGESType::*)(const IGESData_IGESType &) const) &IGESData_IGESType::operator==, py::is_operator(), "None", py::arg("another"));
cls_IGESData_IGESType.def("Nullify", (void (IGESData_IGESType::*)()) &IGESData_IGESType::Nullify, "resets fields (usefull when an IGESType is stored as mask)");

// Enums

}