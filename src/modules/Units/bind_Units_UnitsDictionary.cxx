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
#include <Standard_Handle.hxx>
#include <Units_QuantitiesSequence.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Units_Dimensions.hxx>
#include <Units_UnitsDictionary.hxx>
#include <Standard_Type.hxx>

void bind_Units_UnitsDictionary(py::module &mod){

py::class_<Units_UnitsDictionary, opencascade::handle<Units_UnitsDictionary>, Standard_Transient> cls_Units_UnitsDictionary(mod, "Units_UnitsDictionary", "This class creates a dictionary of all the units you want to know.");

// Constructors
cls_Units_UnitsDictionary.def(py::init<>());

// Fields

// Methods
cls_Units_UnitsDictionary.def("Creates", (void (Units_UnitsDictionary::*)()) &Units_UnitsDictionary::Creates, "Returns a UnitsDictionary object which contains the sequence of all the units you want to consider, physical quantity by physical quantity.");
cls_Units_UnitsDictionary.def("Sequence", (opencascade::handle<Units_QuantitiesSequence> (Units_UnitsDictionary::*)() const) &Units_UnitsDictionary::Sequence, "Returns the head of the sequence of physical quantities.");
cls_Units_UnitsDictionary.def("ActiveUnit", (TCollection_AsciiString (Units_UnitsDictionary::*)(const Standard_CString) const) &Units_UnitsDictionary::ActiveUnit, "Returns for <aquantity> the active unit.", py::arg("aquantity"));
cls_Units_UnitsDictionary.def("Dump", (void (Units_UnitsDictionary::*)(const Standard_Integer) const) &Units_UnitsDictionary::Dump, "Dumps only the sequence of quantities without the units if <alevel> is equal to zero, and for each quantity all the units stored if <alevel> is equal to one.", py::arg("alevel"));
cls_Units_UnitsDictionary.def("Dump", (void (Units_UnitsDictionary::*)(const opencascade::handle<Units_Dimensions> &) const) &Units_UnitsDictionary::Dump, "Dumps for a designated physical dimensions <adimensions> all the previously stored units.", py::arg("adimensions"));
cls_Units_UnitsDictionary.def_static("get_type_name_", (const char * (*)()) &Units_UnitsDictionary::get_type_name, "None");
cls_Units_UnitsDictionary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_UnitsDictionary::get_type_descriptor, "None");
cls_Units_UnitsDictionary.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_UnitsDictionary::*)() const) &Units_UnitsDictionary::DynamicType, "None");

// Enums

}