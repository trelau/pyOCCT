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
#include <TDataStd_Variable.hxx>
#include <TDF_Label.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <TDataStd_RealEnum.hxx>
#include <TDataStd_Real.hxx>
#include <TDataStd_Expression.hxx>
#include <TCollection_AsciiString.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_Variable(py::module &mod){

py::class_<TDataStd_Variable, opencascade::handle<TDataStd_Variable>, TDF_Attribute> cls_TDataStd_Variable(mod, "TDataStd_Variable", "Variable attribute. ==================");

// Constructors
cls_TDataStd_Variable.def(py::init<>());

// Fields

// Methods
cls_TDataStd_Variable.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Variable::GetID, "class methods =============");
cls_TDataStd_Variable.def_static("Set_", (opencascade::handle<TDataStd_Variable> (*)(const TDF_Label &)) &TDataStd_Variable::Set, "Find, or create, a Variable attribute. Real methods ============", py::arg("label"));
cls_TDataStd_Variable.def("Name", (void (TDataStd_Variable::*)(const TCollection_ExtendedString &)) &TDataStd_Variable::Name, "set or change the name of the variable, in myUnknown and my associated Name attribute.", py::arg("string"));
cls_TDataStd_Variable.def("Name", (const TCollection_ExtendedString & (TDataStd_Variable::*)() const) &TDataStd_Variable::Name, "returns string stored in the associated Name attribute.");
cls_TDataStd_Variable.def("Set", (void (TDataStd_Variable::*)(const Standard_Real) const) &TDataStd_Variable::Set, "retrieve or create the associated real attribute and set the value <value>.", py::arg("value"));
cls_TDataStd_Variable.def("Set", (void (TDataStd_Variable::*)(const Standard_Real, const TDataStd_RealEnum) const) &TDataStd_Variable::Set, "Obsolete method that will be removed in next versions. The dimension argument is not supported in the persistence mechanism.", py::arg("value"), py::arg("dimension"));
cls_TDataStd_Variable.def("IsValued", (Standard_Boolean (TDataStd_Variable::*)() const) &TDataStd_Variable::IsValued, "returns True if a Real attribute is associated.");
cls_TDataStd_Variable.def("Get", (Standard_Real (TDataStd_Variable::*)() const) &TDataStd_Variable::Get, "returns value stored in associated Real attribute.");
cls_TDataStd_Variable.def("Real", (opencascade::handle<TDataStd_Real> (TDataStd_Variable::*)() const) &TDataStd_Variable::Real, "returns associated Real attribute.");
cls_TDataStd_Variable.def("IsAssigned", (Standard_Boolean (TDataStd_Variable::*)() const) &TDataStd_Variable::IsAssigned, "returns True if an Expression attribute is associated. create(if doesn't exist), set and returns the assigned expression attribute.");
cls_TDataStd_Variable.def("Assign", (opencascade::handle<TDataStd_Expression> (TDataStd_Variable::*)() const) &TDataStd_Variable::Assign, "create(if doesn't exist) and returns the assigned expression attribute. fill it after.");
cls_TDataStd_Variable.def("Desassign", (void (TDataStd_Variable::*)() const) &TDataStd_Variable::Desassign, "if <me> is assigned delete the associated expression attribute.");
cls_TDataStd_Variable.def("Expression", (opencascade::handle<TDataStd_Expression> (TDataStd_Variable::*)() const) &TDataStd_Variable::Expression, "if <me> is assigned, returns associated Expression attribute.");
cls_TDataStd_Variable.def("IsCaptured", (Standard_Boolean (TDataStd_Variable::*)() const) &TDataStd_Variable::IsCaptured, "shortcut for <Real()->IsCaptured()>");
cls_TDataStd_Variable.def("IsConstant", (Standard_Boolean (TDataStd_Variable::*)() const) &TDataStd_Variable::IsConstant, "A constant value is not modified by regeneration.");
cls_TDataStd_Variable.def("Unit", (void (TDataStd_Variable::*)(const TCollection_AsciiString &)) &TDataStd_Variable::Unit, "None", py::arg("unit"));
cls_TDataStd_Variable.def("Unit", (const TCollection_AsciiString & (TDataStd_Variable::*)() const) &TDataStd_Variable::Unit, "to read/write fields ===================");
cls_TDataStd_Variable.def("Constant", (void (TDataStd_Variable::*)(const Standard_Boolean)) &TDataStd_Variable::Constant, "if <status> is True, this variable will not be modified by the solver.", py::arg("status"));
cls_TDataStd_Variable.def("ID", (const Standard_GUID & (TDataStd_Variable::*)() const) &TDataStd_Variable::ID, "None");
cls_TDataStd_Variable.def("Restore", (void (TDataStd_Variable::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Variable::Restore, "None", py::arg("With"));
cls_TDataStd_Variable.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Variable::*)() const) &TDataStd_Variable::NewEmpty, "None");
cls_TDataStd_Variable.def("Paste", (void (TDataStd_Variable::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Variable::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Variable.def("References", (void (TDataStd_Variable::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataStd_Variable::References, "to export reference to the associated Name attribute.", py::arg("DS"));
cls_TDataStd_Variable.def("Dump", (Standard_OStream & (TDataStd_Variable::*)(Standard_OStream &) const) &TDataStd_Variable::Dump, "None", py::arg("anOS"));
cls_TDataStd_Variable.def_static("get_type_name_", (const char * (*)()) &TDataStd_Variable::get_type_name, "None");
cls_TDataStd_Variable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Variable::get_type_descriptor, "None");
cls_TDataStd_Variable.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Variable::*)() const) &TDataStd_Variable::DynamicType, "None");

// Enums

}