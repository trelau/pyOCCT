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
#include <Standard_Handle.hxx>
#include <Units_UnitsSystem.hxx>
#include <Units_UnitsDictionary.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Units_QuantitiesSequence.hxx>
#include <Units_UnitsSequence.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <Units_Explorer.hxx>

void bind_Units_Explorer(py::module &mod){

py::class_<Units_Explorer> cls_Units_Explorer(mod, "Units_Explorer", "This class provides all the services to explore UnitsSystem or UnitsDictionary.");

// Constructors
cls_Units_Explorer.def(py::init<>());
cls_Units_Explorer.def(py::init<const opencascade::handle<Units_UnitsSystem> &>(), py::arg("aunitssystem"));
cls_Units_Explorer.def(py::init<const opencascade::handle<Units_UnitsDictionary> &>(), py::arg("aunitsdictionary"));
cls_Units_Explorer.def(py::init<const opencascade::handle<Units_UnitsSystem> &, const Standard_CString>(), py::arg("aunitssystem"), py::arg("aquantity"));
cls_Units_Explorer.def(py::init<const opencascade::handle<Units_UnitsDictionary> &, const Standard_CString>(), py::arg("aunitsdictionary"), py::arg("aquantity"));

// Fields

// Methods
// cls_Units_Explorer.def_static("operator new_", (void * (*)(size_t)) &Units_Explorer::operator new, "None", py::arg("theSize"));
// cls_Units_Explorer.def_static("operator delete_", (void (*)(void *)) &Units_Explorer::operator delete, "None", py::arg("theAddress"));
// cls_Units_Explorer.def_static("operator new[]_", (void * (*)(size_t)) &Units_Explorer::operator new[], "None", py::arg("theSize"));
// cls_Units_Explorer.def_static("operator delete[]_", (void (*)(void *)) &Units_Explorer::operator delete[], "None", py::arg("theAddress"));
// cls_Units_Explorer.def_static("operator new_", (void * (*)(size_t, void *)) &Units_Explorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_Explorer.def_static("operator delete_", (void (*)(void *, void *)) &Units_Explorer::operator delete, "None", py::arg(""), py::arg(""));
cls_Units_Explorer.def("Init", (void (Units_Explorer::*)(const opencascade::handle<Units_UnitsSystem> &)) &Units_Explorer::Init, "Initializes the instance of the class with the UnitsSystem <aunitssystem>.", py::arg("aunitssystem"));
cls_Units_Explorer.def("Init", (void (Units_Explorer::*)(const opencascade::handle<Units_UnitsDictionary> &)) &Units_Explorer::Init, "Initializes the instance of the class with the UnitsDictionary <aunitsdictionary>.", py::arg("aunitsdictionary"));
cls_Units_Explorer.def("Init", (void (Units_Explorer::*)(const opencascade::handle<Units_UnitsSystem> &, const Standard_CString)) &Units_Explorer::Init, "Initializes the instance of the class with the UnitsSystem <aunitssystem> and positioned at the quantity <aquantity>.", py::arg("aunitssystem"), py::arg("aquantity"));
cls_Units_Explorer.def("Init", (void (Units_Explorer::*)(const opencascade::handle<Units_UnitsDictionary> &, const Standard_CString)) &Units_Explorer::Init, "Initializes the instance of the class with the UnitsDictionary <aunitsdictionary> and positioned at the quantity <aquantity>.", py::arg("aunitsdictionary"), py::arg("aquantity"));
cls_Units_Explorer.def("MoreQuantity", (Standard_Boolean (Units_Explorer::*)() const) &Units_Explorer::MoreQuantity, "Returns True if there is another Quantity to explore, False otherwise.");
cls_Units_Explorer.def("NextQuantity", (void (Units_Explorer::*)()) &Units_Explorer::NextQuantity, "Sets the next Quantity current.");
cls_Units_Explorer.def("Quantity", (TCollection_AsciiString (Units_Explorer::*)() const) &Units_Explorer::Quantity, "Returns the name of the current Quantity.");
cls_Units_Explorer.def("MoreUnit", (Standard_Boolean (Units_Explorer::*)() const) &Units_Explorer::MoreUnit, "Returns True if there is another Unit to explore, False otherwise.");
cls_Units_Explorer.def("NextUnit", (void (Units_Explorer::*)()) &Units_Explorer::NextUnit, "Sets the next Unit current.");
cls_Units_Explorer.def("Unit", (TCollection_AsciiString (Units_Explorer::*)() const) &Units_Explorer::Unit, "Returns the name of the current unit.");
cls_Units_Explorer.def("IsActive", (Standard_Boolean (Units_Explorer::*)() const) &Units_Explorer::IsActive, "If the units system to explore is a user system, returns True if the current unit is active, False otherwise.");

// Enums

}