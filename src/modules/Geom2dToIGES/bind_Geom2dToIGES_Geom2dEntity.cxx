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
#include <Geom2dToIGES_Geom2dEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <Standard_TypeDef.hxx>

void bind_Geom2dToIGES_Geom2dEntity(py::module &mod){

py::class_<Geom2dToIGES_Geom2dEntity, std::unique_ptr<Geom2dToIGES_Geom2dEntity, Deleter<Geom2dToIGES_Geom2dEntity>>> cls_Geom2dToIGES_Geom2dEntity(mod, "Geom2dToIGES_Geom2dEntity", "provides methods to transfer Geom2d entity from CASCADE to IGES.");

// Constructors
cls_Geom2dToIGES_Geom2dEntity.def(py::init<>());
cls_Geom2dToIGES_Geom2dEntity.def(py::init<const Geom2dToIGES_Geom2dEntity &>(), py::arg("GE"));

// Fields

// Methods
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator new_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dEntity::operator new, "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator delete_", (void (*)(void *)) &Geom2dToIGES_Geom2dEntity::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dEntity::operator new[], "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator delete[]_", (void (*)(void *)) &Geom2dToIGES_Geom2dEntity::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dToIGES_Geom2dEntity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dToIGES_Geom2dEntity::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dToIGES_Geom2dEntity.def("SetModel", (void (Geom2dToIGES_Geom2dEntity::*)(const opencascade::handle<IGESData_IGESModel> &)) &Geom2dToIGES_Geom2dEntity::SetModel, "Set the value of 'TheModel'", py::arg("model"));
cls_Geom2dToIGES_Geom2dEntity.def("GetModel", (opencascade::handle<IGESData_IGESModel> (Geom2dToIGES_Geom2dEntity::*)() const) &Geom2dToIGES_Geom2dEntity::GetModel, "Returns the value of 'TheModel'");
cls_Geom2dToIGES_Geom2dEntity.def("SetUnit", (void (Geom2dToIGES_Geom2dEntity::*)(const Standard_Real)) &Geom2dToIGES_Geom2dEntity::SetUnit, "Sets the value of the UnitFlag", py::arg("unit"));
cls_Geom2dToIGES_Geom2dEntity.def("GetUnit", (Standard_Real (Geom2dToIGES_Geom2dEntity::*)() const) &Geom2dToIGES_Geom2dEntity::GetUnit, "Returns the value of the UnitFlag of the header of the model in millimeters.");

// Enums

}