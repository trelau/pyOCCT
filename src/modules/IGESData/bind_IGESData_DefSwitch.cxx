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
#include <IGESData_DefType.hxx>
#include <IGESData_DefSwitch.hxx>

void bind_IGESData_DefSwitch(py::module &mod){

py::class_<IGESData_DefSwitch, std::unique_ptr<IGESData_DefSwitch>> cls_IGESData_DefSwitch(mod, "IGESData_DefSwitch", "description of a directory componant which can be either undefined (let Void), defined as a Reference to an entity, or as a Rank, integer value adressing a builtin table The entity reference is not included here, only reference status is kept (because entity type must be adapted)");

// Constructors
cls_IGESData_DefSwitch.def(py::init<>());

// Fields

// Methods
// cls_IGESData_DefSwitch.def_static("operator new_", (void * (*)(size_t)) &IGESData_DefSwitch::operator new, "None", py::arg("theSize"));
// cls_IGESData_DefSwitch.def_static("operator delete_", (void (*)(void *)) &IGESData_DefSwitch::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_DefSwitch.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_DefSwitch::operator new[], "None", py::arg("theSize"));
// cls_IGESData_DefSwitch.def_static("operator delete[]_", (void (*)(void *)) &IGESData_DefSwitch::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_DefSwitch.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_DefSwitch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_DefSwitch.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_DefSwitch::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_DefSwitch.def("SetVoid", (void (IGESData_DefSwitch::*)()) &IGESData_DefSwitch::SetVoid, "sets DefSwitch to 'Void' status (in file : Integer = 0)");
cls_IGESData_DefSwitch.def("SetReference", (void (IGESData_DefSwitch::*)()) &IGESData_DefSwitch::SetReference, "sets DefSwitch to 'Reference' Status (in file : Integer < 0)");
cls_IGESData_DefSwitch.def("SetRank", (void (IGESData_DefSwitch::*)(const Standard_Integer)) &IGESData_DefSwitch::SetRank, "sets DefSwitch to 'Rank' with a Value (in file : Integer > 0)", py::arg("val"));
cls_IGESData_DefSwitch.def("DefType", (IGESData_DefType (IGESData_DefSwitch::*)() const) &IGESData_DefSwitch::DefType, "returns DefType status (Void,Reference,Rank)");
cls_IGESData_DefSwitch.def("Value", (Standard_Integer (IGESData_DefSwitch::*)() const) &IGESData_DefSwitch::Value, "returns Value as Integer (sensefull for a Rank)");

// Enums

}