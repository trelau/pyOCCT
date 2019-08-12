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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Units_QuantitiesSequence.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <TCollection_AsciiString.hxx>
#include <Units_UnitsSystem.hxx>
#include <Standard_Type.hxx>

void bind_Units_UnitsSystem(py::module &mod){

py::class_<Units_UnitsSystem, opencascade::handle<Units_UnitsSystem>, Standard_Transient> cls_Units_UnitsSystem(mod, "Units_UnitsSystem", "This class allows the user to define his own system of units.");

// Constructors
cls_Units_UnitsSystem.def(py::init<>());
cls_Units_UnitsSystem.def(py::init<const Standard_CString>(), py::arg("aName"));
cls_Units_UnitsSystem.def(py::init<const Standard_CString, const Standard_Boolean>(), py::arg("aName"), py::arg("Verbose"));

// Fields

// Methods
cls_Units_UnitsSystem.def("QuantitiesSequence", (opencascade::handle<Units_QuantitiesSequence> (Units_UnitsSystem::*)() const) &Units_UnitsSystem::QuantitiesSequence, "Returns the sequence of refined quantities.");
cls_Units_UnitsSystem.def("ActiveUnitsSequence", (opencascade::handle<TColStd_HSequenceOfInteger> (Units_UnitsSystem::*)() const) &Units_UnitsSystem::ActiveUnitsSequence, "Returns a sequence of integer in correspondance with the sequence of quantities, which indicates, for each redefined quantity, the index into the sequence of units, of the active unit.");
cls_Units_UnitsSystem.def("Specify", (void (Units_UnitsSystem::*)(const Standard_CString, const Standard_CString)) &Units_UnitsSystem::Specify, "Specifies for <aquantity> the unit <aunit> used.", py::arg("aquantity"), py::arg("aunit"));
cls_Units_UnitsSystem.def("Remove", (void (Units_UnitsSystem::*)(const Standard_CString, const Standard_CString)) &Units_UnitsSystem::Remove, "Removes for <aquantity> the unit <aunit> used.", py::arg("aquantity"), py::arg("aunit"));
cls_Units_UnitsSystem.def("Activate", (void (Units_UnitsSystem::*)(const Standard_CString, const Standard_CString)) &Units_UnitsSystem::Activate, "Specifies for <aquantity> the unit <aunit> used.", py::arg("aquantity"), py::arg("aunit"));
cls_Units_UnitsSystem.def("Activates", (void (Units_UnitsSystem::*)()) &Units_UnitsSystem::Activates, "Activates the first unit of all defined system quantities");
cls_Units_UnitsSystem.def("ActiveUnit", (TCollection_AsciiString (Units_UnitsSystem::*)(const Standard_CString) const) &Units_UnitsSystem::ActiveUnit, "Returns for <aquantity> the active unit.", py::arg("aquantity"));
cls_Units_UnitsSystem.def("ConvertValueToUserSystem", (Standard_Real (Units_UnitsSystem::*)(const Standard_CString, const Standard_Real, const Standard_CString) const) &Units_UnitsSystem::ConvertValueToUserSystem, "Converts a real value <avalue> from the unit <aunit> belonging to the physical dimensions <aquantity> to the corresponding unit of the user system.", py::arg("aquantity"), py::arg("avalue"), py::arg("aunit"));
cls_Units_UnitsSystem.def("ConvertSIValueToUserSystem", (Standard_Real (Units_UnitsSystem::*)(const Standard_CString, const Standard_Real) const) &Units_UnitsSystem::ConvertSIValueToUserSystem, "Converts the real value <avalue> from the S.I. system of units to the user system of units. <aquantity> is the physical dimensions of the measurement.", py::arg("aquantity"), py::arg("avalue"));
cls_Units_UnitsSystem.def("ConvertUserSystemValueToSI", (Standard_Real (Units_UnitsSystem::*)(const Standard_CString, const Standard_Real) const) &Units_UnitsSystem::ConvertUserSystemValueToSI, "Converts the real value <avalue> from the user system of units to the S.I. system of units. <aquantity> is the physical dimensions of the measurement.", py::arg("aquantity"), py::arg("avalue"));
cls_Units_UnitsSystem.def("Dump", (void (Units_UnitsSystem::*)() const) &Units_UnitsSystem::Dump, "None");
cls_Units_UnitsSystem.def("IsEmpty", (Standard_Boolean (Units_UnitsSystem::*)() const) &Units_UnitsSystem::IsEmpty, "Returns TRUE if no units has been defined in the system.");
cls_Units_UnitsSystem.def_static("get_type_name_", (const char * (*)()) &Units_UnitsSystem::get_type_name, "None");
cls_Units_UnitsSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_UnitsSystem::get_type_descriptor, "None");
cls_Units_UnitsSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_UnitsSystem::*)() const) &Units_UnitsSystem::DynamicType, "None");

// Enums

}