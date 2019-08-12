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
#include <Units_Dimensions.hxx>
#include <Units_UnitsSequence.hxx>
#include <TCollection_AsciiString.hxx>
#include <Units_Quantity.hxx>
#include <Standard_Type.hxx>
#include <TCollection_HAsciiString.hxx>

void bind_Units_Quantity(py::module &mod){

py::class_<Units_Quantity, opencascade::handle<Units_Quantity>, Standard_Transient> cls_Units_Quantity(mod, "Units_Quantity", "This class stores in its field all the possible units of all the unit systems for a given physical quantity. Each unit's value is expressed in the S.I. unit system.");

// Constructors
cls_Units_Quantity.def(py::init<const Standard_CString, const opencascade::handle<Units_Dimensions> &, const opencascade::handle<Units_UnitsSequence> &>(), py::arg("aname"), py::arg("adimensions"), py::arg("aunitssequence"));

// Fields

// Methods
cls_Units_Quantity.def("Name", (TCollection_AsciiString (Units_Quantity::*)() const) &Units_Quantity::Name, "Returns in a AsciiString from TCollection the name of the quantity.");
cls_Units_Quantity.def("Dimensions", (opencascade::handle<Units_Dimensions> (Units_Quantity::*)() const) &Units_Quantity::Dimensions, "Returns the physical dimensions of the quantity.");
cls_Units_Quantity.def("Sequence", (opencascade::handle<Units_UnitsSequence> (Units_Quantity::*)() const) &Units_Quantity::Sequence, "Returns <theunitssequence>, which is the sequence of all the units stored for this physical quantity.");
cls_Units_Quantity.def("IsEqual", (Standard_Boolean (Units_Quantity::*)(const Standard_CString) const) &Units_Quantity::IsEqual, "Returns True if the name of the Quantity <me> is equal to <astring>, False otherwise.", py::arg("astring"));
cls_Units_Quantity.def("Dump", (void (Units_Quantity::*)(const Standard_Integer, const Standard_Integer) const) &Units_Quantity::Dump, "Useful for debugging.", py::arg("ashift"), py::arg("alevel"));
cls_Units_Quantity.def_static("get_type_name_", (const char * (*)()) &Units_Quantity::get_type_name, "None");
cls_Units_Quantity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_Quantity::get_type_descriptor, "None");
cls_Units_Quantity.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_Quantity::*)() const) &Units_Quantity::DynamicType, "None");

// Enums

}