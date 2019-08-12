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
#include <Standard_Handle.hxx>
#include <TColStd_HArray2OfTransient.hxx>
#include <IGESDefs_AttributeDef.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESDefs_AttributeTable.hxx>
#include <Standard_Type.hxx>

void bind_IGESDefs_AttributeTable(py::module &mod){

py::class_<IGESDefs_AttributeTable, opencascade::handle<IGESDefs_AttributeTable>, IGESData_IGESEntity> cls_IGESDefs_AttributeTable(mod, "IGESDefs_AttributeTable", "defines IGES Attribute Table, Type <422> Form <0, 1> in package IGESDefs This class is used to represent an occurence of Attribute Table. This Class may be independent or dependent or pointed at by other Entities.");

// Constructors
cls_IGESDefs_AttributeTable.def(py::init<>());

// Fields

// Methods
cls_IGESDefs_AttributeTable.def("Init", (void (IGESDefs_AttributeTable::*)(const opencascade::handle<TColStd_HArray2OfTransient> &)) &IGESDefs_AttributeTable::Init, "This method is used to set the fields of the class AttributeTable - attributes : Attribute instances, created as (1,NbAttributes,1,NbRows) - NbRows = 1 is a particular case (Form 0)", py::arg("attributes"));
cls_IGESDefs_AttributeTable.def("SetDefinition", (void (IGESDefs_AttributeTable::*)(const opencascade::handle<IGESDefs_AttributeDef> &)) &IGESDefs_AttributeTable::SetDefinition, "Sets a Definition as Structure information (works by calling InitMisc)", py::arg("def"));
cls_IGESDefs_AttributeTable.def("Definition", (opencascade::handle<IGESDefs_AttributeDef> (IGESDefs_AttributeTable::*)() const) &IGESDefs_AttributeTable::Definition, "Return the Structure information in Directory Entry, casted as an AttributeDef");
cls_IGESDefs_AttributeTable.def("NbRows", (Standard_Integer (IGESDefs_AttributeTable::*)() const) &IGESDefs_AttributeTable::NbRows, "returns Number of Rows. Remark that it is always 1 if Form = 0 It means that the list of Attributes (by their number, and for each one its type and ValueCount) is repeated <NbRows> times");
cls_IGESDefs_AttributeTable.def("NbAttributes", (Standard_Integer (IGESDefs_AttributeTable::*)() const) &IGESDefs_AttributeTable::NbAttributes, "returns Number of Attributes");
cls_IGESDefs_AttributeTable.def("DataType", (Standard_Integer (IGESDefs_AttributeTable::*)(const Standard_Integer) const) &IGESDefs_AttributeTable::DataType, "returns the Type of an Attribute, given its No. : it is read in the Definition. (1 : Integer, 2 : Real, 3 : String, 4 : Entity, 6 : Logical)", py::arg("Atnum"));
cls_IGESDefs_AttributeTable.def("ValueCount", (Standard_Integer (IGESDefs_AttributeTable::*)(const Standard_Integer) const) &IGESDefs_AttributeTable::ValueCount, "returns the Count of Value for an Attribute, given its No. : it is read in the Definition.", py::arg("Atnum"));
cls_IGESDefs_AttributeTable.def("AttributeList", (opencascade::handle<Standard_Transient> (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeTable::AttributeList, "None", py::arg("Attribnum"), py::arg("Rownum"));
cls_IGESDefs_AttributeTable.def("AttributeAsInteger", (Standard_Integer (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeTable::AttributeAsInteger, "Returns Attribute Value <AtNum, Rownum, rank ValNum> as an Integer Error if Indices out of Range, or no Value defined, or not an Integer", py::arg("AtNum"), py::arg("Rownum"), py::arg("ValNum"));
cls_IGESDefs_AttributeTable.def("AttributeAsReal", (Standard_Real (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeTable::AttributeAsReal, "Returns Attribute Value <AtNum, Rownum, rank ValNum> as a Real Error if Indices out of Range, or no Value defined, or not a Real", py::arg("AtNum"), py::arg("Rownum"), py::arg("ValNum"));
cls_IGESDefs_AttributeTable.def("AttributeAsString", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeTable::AttributeAsString, "Returns Attribute Value <AtNum, Rownum, rank ValNum> as an Integer", py::arg("AtNum"), py::arg("Rownum"), py::arg("ValNum"));
cls_IGESDefs_AttributeTable.def("AttributeAsEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeTable::AttributeAsEntity, "Returns Attribute Value <AtNum, Rownum, rank ValNum> as an Entity Error if Indices out of Range, or no Value defined, or not an Entity", py::arg("AtNum"), py::arg("Rownum"), py::arg("ValNum"));
cls_IGESDefs_AttributeTable.def("AttributeAsLogical", (Standard_Boolean (IGESDefs_AttributeTable::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeTable::AttributeAsLogical, "Returns Attribute Value <AtNum, Rownum, rank ValNum> as a Boolean Error if Indices out of Range, or no Value defined, or not a Logical", py::arg("AtNum"), py::arg("Rownum"), py::arg("ValNum"));
cls_IGESDefs_AttributeTable.def_static("get_type_name_", (const char * (*)()) &IGESDefs_AttributeTable::get_type_name, "None");
cls_IGESDefs_AttributeTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_AttributeTable::get_type_descriptor, "None");
cls_IGESDefs_AttributeTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_AttributeTable::*)() const) &IGESDefs_AttributeTable::DynamicType, "None");

// Enums

}