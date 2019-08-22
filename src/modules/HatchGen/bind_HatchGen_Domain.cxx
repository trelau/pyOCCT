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
#include <HatchGen_PointOnHatching.hxx>
#include <Standard_TypeDef.hxx>
#include <HatchGen_Domain.hxx>

void bind_HatchGen_Domain(py::module &mod){

py::class_<HatchGen_Domain> cls_HatchGen_Domain(mod, "HatchGen_Domain", "None");

// Constructors
cls_HatchGen_Domain.def(py::init<>());
cls_HatchGen_Domain.def(py::init<const HatchGen_PointOnHatching &, const HatchGen_PointOnHatching &>(), py::arg("P1"), py::arg("P2"));
cls_HatchGen_Domain.def(py::init<const HatchGen_PointOnHatching &, const Standard_Boolean>(), py::arg("P"), py::arg("First"));

// Fields

// Methods
// cls_HatchGen_Domain.def_static("operator new_", (void * (*)(size_t)) &HatchGen_Domain::operator new, "None", py::arg("theSize"));
// cls_HatchGen_Domain.def_static("operator delete_", (void (*)(void *)) &HatchGen_Domain::operator delete, "None", py::arg("theAddress"));
// cls_HatchGen_Domain.def_static("operator new[]_", (void * (*)(size_t)) &HatchGen_Domain::operator new[], "None", py::arg("theSize"));
// cls_HatchGen_Domain.def_static("operator delete[]_", (void (*)(void *)) &HatchGen_Domain::operator delete[], "None", py::arg("theAddress"));
// cls_HatchGen_Domain.def_static("operator new_", (void * (*)(size_t, void *)) &HatchGen_Domain::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HatchGen_Domain.def_static("operator delete_", (void (*)(void *, void *)) &HatchGen_Domain::operator delete, "None", py::arg(""), py::arg(""));
cls_HatchGen_Domain.def("SetPoints", (void (HatchGen_Domain::*)(const HatchGen_PointOnHatching &, const HatchGen_PointOnHatching &)) &HatchGen_Domain::SetPoints, "Sets the first and the second points of the domain.", py::arg("P1"), py::arg("P2"));
cls_HatchGen_Domain.def("SetPoints", (void (HatchGen_Domain::*)()) &HatchGen_Domain::SetPoints, "Sets the first and the second points of the domain as the infinite.");
cls_HatchGen_Domain.def("SetFirstPoint", (void (HatchGen_Domain::*)(const HatchGen_PointOnHatching &)) &HatchGen_Domain::SetFirstPoint, "Sets the first point of the domain.", py::arg("P"));
cls_HatchGen_Domain.def("SetFirstPoint", (void (HatchGen_Domain::*)()) &HatchGen_Domain::SetFirstPoint, "Sets the first point of the domain at the infinite.");
cls_HatchGen_Domain.def("SetSecondPoint", (void (HatchGen_Domain::*)(const HatchGen_PointOnHatching &)) &HatchGen_Domain::SetSecondPoint, "Sets the second point of the domain.", py::arg("P"));
cls_HatchGen_Domain.def("SetSecondPoint", (void (HatchGen_Domain::*)()) &HatchGen_Domain::SetSecondPoint, "Sets the second point of the domain at the infinite.");
cls_HatchGen_Domain.def("HasFirstPoint", (Standard_Boolean (HatchGen_Domain::*)() const) &HatchGen_Domain::HasFirstPoint, "Returns True if the domain has a first point.");
cls_HatchGen_Domain.def("FirstPoint", (const HatchGen_PointOnHatching & (HatchGen_Domain::*)() const) &HatchGen_Domain::FirstPoint, "Returns the first point of the domain. The exception DomainError is raised if HasFirstPoint returns False.");
cls_HatchGen_Domain.def("HasSecondPoint", (Standard_Boolean (HatchGen_Domain::*)() const) &HatchGen_Domain::HasSecondPoint, "Returns True if the domain has a second point.");
cls_HatchGen_Domain.def("SecondPoint", (const HatchGen_PointOnHatching & (HatchGen_Domain::*)() const) &HatchGen_Domain::SecondPoint, "Returns the second point of the domain. The exception DomainError is raised if HasSecondPoint returns False.");
cls_HatchGen_Domain.def("Dump", [](HatchGen_Domain &self) -> void { return self.Dump(); });
cls_HatchGen_Domain.def("Dump", (void (HatchGen_Domain::*)(const Standard_Integer) const) &HatchGen_Domain::Dump, "Dump of the domain.", py::arg("Index"));

// Enums

}