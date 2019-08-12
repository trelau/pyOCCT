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
#include <GeomToIGES_GeomEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <Standard_TypeDef.hxx>

void bind_GeomToIGES_GeomEntity(py::module &mod){

py::class_<GeomToIGES_GeomEntity, std::unique_ptr<GeomToIGES_GeomEntity, Deleter<GeomToIGES_GeomEntity>>> cls_GeomToIGES_GeomEntity(mod, "GeomToIGES_GeomEntity", "provides methods to transfer Geom entity from CASCADE to IGES.");

// Constructors
cls_GeomToIGES_GeomEntity.def(py::init<>());
cls_GeomToIGES_GeomEntity.def(py::init<const GeomToIGES_GeomEntity &>(), py::arg("GE"));

// Fields

// Methods
// cls_GeomToIGES_GeomEntity.def_static("operator new_", (void * (*)(size_t)) &GeomToIGES_GeomEntity::operator new, "None", py::arg("theSize"));
// cls_GeomToIGES_GeomEntity.def_static("operator delete_", (void (*)(void *)) &GeomToIGES_GeomEntity::operator delete, "None", py::arg("theAddress"));
// cls_GeomToIGES_GeomEntity.def_static("operator new[]_", (void * (*)(size_t)) &GeomToIGES_GeomEntity::operator new[], "None", py::arg("theSize"));
// cls_GeomToIGES_GeomEntity.def_static("operator delete[]_", (void (*)(void *)) &GeomToIGES_GeomEntity::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToIGES_GeomEntity.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToIGES_GeomEntity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToIGES_GeomEntity.def_static("operator delete_", (void (*)(void *, void *)) &GeomToIGES_GeomEntity::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToIGES_GeomEntity.def("SetModel", (void (GeomToIGES_GeomEntity::*)(const opencascade::handle<IGESData_IGESModel> &)) &GeomToIGES_GeomEntity::SetModel, "Set the value of 'TheModel'", py::arg("model"));
cls_GeomToIGES_GeomEntity.def("GetModel", (opencascade::handle<IGESData_IGESModel> (GeomToIGES_GeomEntity::*)() const) &GeomToIGES_GeomEntity::GetModel, "Returns the value of 'TheModel'");
cls_GeomToIGES_GeomEntity.def("SetUnit", (void (GeomToIGES_GeomEntity::*)(const Standard_Real)) &GeomToIGES_GeomEntity::SetUnit, "Sets the value of the UnitFlag", py::arg("unit"));
cls_GeomToIGES_GeomEntity.def("GetUnit", (Standard_Real (GeomToIGES_GeomEntity::*)() const) &GeomToIGES_GeomEntity::GetUnit, "Returns the value of the UnitFlag of the header of the model in meters.");

// Enums

}