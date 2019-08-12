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
#include <TDataStd_Expression.hxx>
#include <TDF_Label.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TDF_AttributeList.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_Expression(py::module &mod){

py::class_<TDataStd_Expression, opencascade::handle<TDataStd_Expression>, TDF_Attribute> cls_TDataStd_Expression(mod, "TDataStd_Expression", "Expression attribute. ====================");

// Constructors
cls_TDataStd_Expression.def(py::init<>());

// Fields

// Methods
cls_TDataStd_Expression.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Expression::GetID, "class methods =============");
cls_TDataStd_Expression.def_static("Set_", (opencascade::handle<TDataStd_Expression> (*)(const TDF_Label &)) &TDataStd_Expression::Set, "Find, or create, an Expression attribute. Expressionmethods ============", py::arg("label"));
cls_TDataStd_Expression.def("Name", (TCollection_ExtendedString (TDataStd_Expression::*)() const) &TDataStd_Expression::Name, "build and return the expression name");
cls_TDataStd_Expression.def("SetExpression", (void (TDataStd_Expression::*)(const TCollection_ExtendedString &)) &TDataStd_Expression::SetExpression, "None", py::arg("E"));
cls_TDataStd_Expression.def("GetExpression", (const TCollection_ExtendedString & (TDataStd_Expression::*)() const) &TDataStd_Expression::GetExpression, "None");
cls_TDataStd_Expression.def("GetVariables", (TDF_AttributeList & (TDataStd_Expression::*)()) &TDataStd_Expression::GetVariables, "None");
cls_TDataStd_Expression.def("ID", (const Standard_GUID & (TDataStd_Expression::*)() const) &TDataStd_Expression::ID, "None");
cls_TDataStd_Expression.def("Restore", (void (TDataStd_Expression::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Expression::Restore, "None", py::arg("With"));
cls_TDataStd_Expression.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Expression::*)() const) &TDataStd_Expression::NewEmpty, "None");
cls_TDataStd_Expression.def("Paste", (void (TDataStd_Expression::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Expression::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Expression.def("Dump", (Standard_OStream & (TDataStd_Expression::*)(Standard_OStream &) const) &TDataStd_Expression::Dump, "None", py::arg("anOS"));
cls_TDataStd_Expression.def_static("get_type_name_", (const char * (*)()) &TDataStd_Expression::get_type_name, "None");
cls_TDataStd_Expression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Expression::get_type_descriptor, "None");
cls_TDataStd_Expression.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Expression::*)() const) &TDataStd_Expression::DynamicType, "None");

// Enums

}