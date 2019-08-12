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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_NamedData.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_DataMapOfStringInteger.hxx>
#include <TDataStd_DataMapOfStringReal.hxx>
#include <TDataStd_DataMapOfStringString.hxx>
#include <TDataStd_DataMapOfStringByte.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TDataStd_DataMapOfStringHArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TDataStd_DataMapOfStringHArray1OfReal.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>
#include <TDataStd_HDataMapOfStringInteger.hxx>
#include <TDataStd_HDataMapOfStringReal.hxx>
#include <TDataStd_HDataMapOfStringString.hxx>
#include <TDataStd_HDataMapOfStringByte.hxx>
#include <TDataStd_HDataMapOfStringHArray1OfInteger.hxx>
#include <TDataStd_HDataMapOfStringHArray1OfReal.hxx>

void bind_TDataStd_NamedData(py::module &mod){

py::class_<TDataStd_NamedData, opencascade::handle<TDataStd_NamedData>, TDF_Attribute> cls_TDataStd_NamedData(mod, "TDataStd_NamedData", "Contains a named data.");

// Constructors
cls_TDataStd_NamedData.def(py::init<>());

// Fields

// Methods
cls_TDataStd_NamedData.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_NamedData::GetID, "Static methods ============== Returns the ID of the named data attribute.");
cls_TDataStd_NamedData.def_static("Set_", (opencascade::handle<TDataStd_NamedData> (*)(const TDF_Label &)) &TDataStd_NamedData::Set, "Finds or creates a named data attribute.", py::arg("label"));
cls_TDataStd_NamedData.def("HasIntegers", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasIntegers, "Returns true if at least one named integer value is kept in the attribute.");
cls_TDataStd_NamedData.def("HasInteger", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasInteger, "Returns true if the attribute contains specified by Name integer value.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetInteger", (Standard_Integer (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetInteger, "Returns the integer value specified by the Name. It returns 0 if internal map doesn't contain the specified integer (use HasInteger() to check before).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetInteger", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const Standard_Integer)) &TDataStd_NamedData::SetInteger, "Defines a named integer. If the integer already exists, it changes its value to <theInteger>.", py::arg("theName"), py::arg("theInteger"));
cls_TDataStd_NamedData.def("GetIntegersContainer", (const TColStd_DataMapOfStringInteger & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetIntegersContainer, "Returns the internal container of named integers.");
cls_TDataStd_NamedData.def("ChangeIntegers", (void (TDataStd_NamedData::*)(const TColStd_DataMapOfStringInteger &)) &TDataStd_NamedData::ChangeIntegers, "Replace the container content by new content of the <theIntegers>.", py::arg("theIntegers"));
cls_TDataStd_NamedData.def("HasReals", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasReals, "Returns true if at least one named real value is kept in the attribute.");
cls_TDataStd_NamedData.def("HasReal", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasReal, "Returns true if the attribute contains a real specified by Name.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetReal", (Standard_Real (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetReal, "Returns the named real. It returns 0.0 if there is no such a named real (use HasReal()).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetReal", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const Standard_Real)) &TDataStd_NamedData::SetReal, "Defines a named real. If the real already exists, it changes its value to <theReal>.", py::arg("theName"), py::arg("theReal"));
cls_TDataStd_NamedData.def("GetRealsContainer", (const TDataStd_DataMapOfStringReal & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetRealsContainer, "Returns the internal container of named reals.");
cls_TDataStd_NamedData.def("ChangeReals", (void (TDataStd_NamedData::*)(const TDataStd_DataMapOfStringReal &)) &TDataStd_NamedData::ChangeReals, "Replace the container content by new content of the <theReals>.", py::arg("theReals"));
cls_TDataStd_NamedData.def("HasStrings", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasStrings, "Returns true if there are some named strings in the attribute.");
cls_TDataStd_NamedData.def("HasString", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasString, "Returns true if the attribute contains this named string.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetString", (const TCollection_ExtendedString & (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetString, "Returns the named string. It returns an empty string if there is no such a named string (use HasString()).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetString", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &TDataStd_NamedData::SetString, "Defines a named string. If the string already exists, it changes its value to <theString>.", py::arg("theName"), py::arg("theString"));
cls_TDataStd_NamedData.def("GetStringsContainer", (const TDataStd_DataMapOfStringString & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetStringsContainer, "Returns the internal container of named strings.");
cls_TDataStd_NamedData.def("ChangeStrings", (void (TDataStd_NamedData::*)(const TDataStd_DataMapOfStringString &)) &TDataStd_NamedData::ChangeStrings, "Replace the container content by new content of the <theStrings>.", py::arg("theStrings"));
cls_TDataStd_NamedData.def("HasBytes", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasBytes, "Returns true if there are some named bytes in the attribute.");
cls_TDataStd_NamedData.def("HasByte", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasByte, "Returns true if the attribute contains this named byte.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetByte", (Standard_Byte (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetByte, "Returns the named byte. It returns 0 if there is no such a named byte (use HasByte()).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetByte", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const Standard_Byte)) &TDataStd_NamedData::SetByte, "Defines a named byte. If the byte already exists, it changes its value to <theByte>.", py::arg("theName"), py::arg("theByte"));
cls_TDataStd_NamedData.def("GetBytesContainer", (const TDataStd_DataMapOfStringByte & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetBytesContainer, "Returns the internal container of named bytes.");
cls_TDataStd_NamedData.def("ChangeBytes", (void (TDataStd_NamedData::*)(const TDataStd_DataMapOfStringByte &)) &TDataStd_NamedData::ChangeBytes, "Replace the container content by new content of the <theBytes>.", py::arg("theBytes"));
cls_TDataStd_NamedData.def("HasArraysOfIntegers", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasArraysOfIntegers, "Returns true if there are some named arrays of integer values in the attribute.");
cls_TDataStd_NamedData.def("HasArrayOfIntegers", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasArrayOfIntegers, "Returns true if the attribute contains this named array of integer values.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetArrayOfIntegers", (const opencascade::handle<TColStd_HArray1OfInteger> & (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetArrayOfIntegers, "Returns the named array of integer values. It returns a NULL Handle if there is no such a named array of integers (use HasArrayOfIntegers()).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetArrayOfIntegers", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &TDataStd_NamedData::SetArrayOfIntegers, "Defines a named array of integer values. If the array already exists, it changes its value to <theArrayOfIntegers>.", py::arg("theName"), py::arg("theArrayOfIntegers"));
cls_TDataStd_NamedData.def("GetArraysOfIntegersContainer", (const TDataStd_DataMapOfStringHArray1OfInteger & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetArraysOfIntegersContainer, "Returns the internal container of named arrays of integer values.");
cls_TDataStd_NamedData.def("ChangeArraysOfIntegers", (void (TDataStd_NamedData::*)(const TDataStd_DataMapOfStringHArray1OfInteger &)) &TDataStd_NamedData::ChangeArraysOfIntegers, "Replace the container content by new content of the <theArraysOfIntegers>.", py::arg("theArraysOfIntegers"));
cls_TDataStd_NamedData.def("HasArraysOfReals", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasArraysOfReals, "Returns true if there are some named arrays of real values in the attribute.");
cls_TDataStd_NamedData.def("HasArrayOfReals", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasArrayOfReals, "Returns true if the attribute contains this named array of real values.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetArrayOfReals", (const opencascade::handle<TColStd_HArray1OfReal> & (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetArrayOfReals, "Returns the named array of real values. It returns a NULL Handle if there is no such a named array of reals (use HasArrayOfReals()).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetArrayOfReals", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const opencascade::handle<TColStd_HArray1OfReal> &)) &TDataStd_NamedData::SetArrayOfReals, "Defines a named array of real values. If the array already exists, it changes its value to <theArrayOfReals>.", py::arg("theName"), py::arg("theArrayOfReals"));
cls_TDataStd_NamedData.def("GetArraysOfRealsContainer", (const TDataStd_DataMapOfStringHArray1OfReal & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetArraysOfRealsContainer, "Returns the internal container of named arrays of real values.");
cls_TDataStd_NamedData.def("ChangeArraysOfReals", (void (TDataStd_NamedData::*)(const TDataStd_DataMapOfStringHArray1OfReal &)) &TDataStd_NamedData::ChangeArraysOfReals, "Replace the container content by new content of the <theArraysOfReals>.", py::arg("theArraysOfReals"));
cls_TDataStd_NamedData.def("ID", (const Standard_GUID & (TDataStd_NamedData::*)() const) &TDataStd_NamedData::ID, "None");
cls_TDataStd_NamedData.def("Restore", (void (TDataStd_NamedData::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_NamedData::Restore, "None", py::arg("With"));
cls_TDataStd_NamedData.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_NamedData::*)() const) &TDataStd_NamedData::NewEmpty, "None");
cls_TDataStd_NamedData.def("Paste", (void (TDataStd_NamedData::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_NamedData::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_NamedData.def("Dump", (Standard_OStream & (TDataStd_NamedData::*)(Standard_OStream &) const) &TDataStd_NamedData::Dump, "None", py::arg("anOS"));
cls_TDataStd_NamedData.def_static("get_type_name_", (const char * (*)()) &TDataStd_NamedData::get_type_name, "None");
cls_TDataStd_NamedData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_NamedData::get_type_descriptor, "None");
cls_TDataStd_NamedData.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_NamedData::*)() const) &TDataStd_NamedData::DynamicType, "None");

// Enums

}