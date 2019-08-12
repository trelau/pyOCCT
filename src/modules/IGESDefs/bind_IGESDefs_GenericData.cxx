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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfTransient.hxx>
#include <Standard_Transient.hxx>
#include <IGESDefs_GenericData.hxx>
#include <Standard_Type.hxx>

void bind_IGESDefs_GenericData(py::module &mod){

py::class_<IGESDefs_GenericData, opencascade::handle<IGESDefs_GenericData>, IGESData_IGESEntity> cls_IGESDefs_GenericData(mod, "IGESDefs_GenericData", "defines IGES Generic Data, Type <406> Form <27> in package IGESDefs Used to communicate information defined by the system operator while creating the model. The information is system specific and does not map into one of the predefined properties or associativities. Properties and property values can be defined by multiple instances of this property.");

// Constructors
cls_IGESDefs_GenericData.def(py::init<>());

// Fields

// Methods
cls_IGESDefs_GenericData.def("Init", (void (IGESDefs_GenericData::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfTransient> &)) &IGESDefs_GenericData::Init, "This method is used to set the fields of the class GenericData - nbPropVal : Number of property values - aName : Property Name - allTypes : Property Types - allValues : Property Values", py::arg("nbPropVal"), py::arg("aName"), py::arg("allTypes"), py::arg("allValues"));
cls_IGESDefs_GenericData.def("NbPropertyValues", (Standard_Integer (IGESDefs_GenericData::*)() const) &IGESDefs_GenericData::NbPropertyValues, "returns the number of property values");
cls_IGESDefs_GenericData.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_GenericData::*)() const) &IGESDefs_GenericData::Name, "returns property name");
cls_IGESDefs_GenericData.def("NbTypeValuePairs", (Standard_Integer (IGESDefs_GenericData::*)() const) &IGESDefs_GenericData::NbTypeValuePairs, "returns the number of TYPE/VALUE pairs");
cls_IGESDefs_GenericData.def("Type", (Standard_Integer (IGESDefs_GenericData::*)(const Standard_Integer) const) &IGESDefs_GenericData::Type, "returns the Index'th property value data type raises exception if Index <= 0 or Index > NbTypeValuePairs()", py::arg("Index"));
cls_IGESDefs_GenericData.def("Value", (opencascade::handle<Standard_Transient> (IGESDefs_GenericData::*)(const Standard_Integer) const) &IGESDefs_GenericData::Value, "HArray1OfInteger (length 1), HArray1OfReal (length 1) for Integer, Real, Boolean (= Integer 0/1), HAsciiString for String (the value itself), IGESEntity for Entity (the value itself)", py::arg("Index"));
cls_IGESDefs_GenericData.def("ValueAsInteger", (Standard_Integer (IGESDefs_GenericData::*)(const Standard_Integer) const) &IGESDefs_GenericData::ValueAsInteger, "Returns Attribute Value <AttrNum, rank ValueNum> as an Integer Error if Index out of Range, or not an Integer", py::arg("ValueNum"));
cls_IGESDefs_GenericData.def("ValueAsReal", (Standard_Real (IGESDefs_GenericData::*)(const Standard_Integer) const) &IGESDefs_GenericData::ValueAsReal, "Returns Attribute Value <AttrNum, rank ValueNum> as a Real Error if Index out of Range, or not a Real", py::arg("ValueNum"));
cls_IGESDefs_GenericData.def("ValueAsString", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_GenericData::*)(const Standard_Integer) const) &IGESDefs_GenericData::ValueAsString, "Returns Attribute Value <AttrNum, rank ValueNum> as an Integer", py::arg("ValueNum"));
cls_IGESDefs_GenericData.def("ValueAsEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDefs_GenericData::*)(const Standard_Integer) const) &IGESDefs_GenericData::ValueAsEntity, "Returns Attribute Value <AttrNum, rank ValueNum> as an Entity Error if Index out of Range, or not a Entity", py::arg("ValueNum"));
cls_IGESDefs_GenericData.def("ValueAsLogical", (Standard_Boolean (IGESDefs_GenericData::*)(const Standard_Integer) const) &IGESDefs_GenericData::ValueAsLogical, "Returns Attribute Value <AttrNum, rank ValueNum> as a Boolean Error if Index out of Range, or not a Logical", py::arg("ValueNum"));
cls_IGESDefs_GenericData.def_static("get_type_name_", (const char * (*)()) &IGESDefs_GenericData::get_type_name, "None");
cls_IGESDefs_GenericData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_GenericData::get_type_descriptor, "None");
cls_IGESDefs_GenericData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_GenericData::*)() const) &IGESDefs_GenericData::DynamicType, "None");

// Enums

}