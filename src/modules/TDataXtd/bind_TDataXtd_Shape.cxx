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
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <TDataXtd_Shape.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_GUID.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataXtd_Shape(py::module &mod){

py::class_<TDataXtd_Shape, opencascade::handle<TDataXtd_Shape>, TDF_Attribute> cls_TDataXtd_Shape(mod, "TDataXtd_Shape", "A Shape is associated in the framework with : a NamedShape attribute");

// Constructors
cls_TDataXtd_Shape.def(py::init<>());

// Fields

// Methods
cls_TDataXtd_Shape.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TDataXtd_Shape> &)) &TDataXtd_Shape::Find, "class methods ============= try to retrieve a Shape attribute at <current> label or in fathers label of <current>. Returns True if found and set <S>.", py::arg("current"), py::arg("S"));
cls_TDataXtd_Shape.def_static("New_", (opencascade::handle<TDataXtd_Shape> (*)(const TDF_Label &)) &TDataXtd_Shape::New, "Find, or create, a Shape attribute. the Shape attribute is returned. Raises if <label> has attribute.", py::arg("label"));
cls_TDataXtd_Shape.def_static("Set_", (opencascade::handle<TDataXtd_Shape> (*)(const TDF_Label &, const TopoDS_Shape &)) &TDataXtd_Shape::Set, "Create or update associated NamedShape attribute. the Shape attribute is returned.", py::arg("label"), py::arg("shape"));
cls_TDataXtd_Shape.def_static("Get_", (TopoDS_Shape (*)(const TDF_Label &)) &TDataXtd_Shape::Get, "the Shape from associated NamedShape attribute is returned.", py::arg("label"));
cls_TDataXtd_Shape.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Shape::GetID, "Shape methods ============");
cls_TDataXtd_Shape.def("ID", (const Standard_GUID & (TDataXtd_Shape::*)() const) &TDataXtd_Shape::ID, "None");
cls_TDataXtd_Shape.def("Restore", (void (TDataXtd_Shape::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Shape::Restore, "None", py::arg("with"));
cls_TDataXtd_Shape.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Shape::*)() const) &TDataXtd_Shape::NewEmpty, "None");
cls_TDataXtd_Shape.def("Paste", (void (TDataXtd_Shape::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Shape::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataXtd_Shape.def("References", (void (TDataXtd_Shape::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataXtd_Shape::References, "None", py::arg("DS"));
cls_TDataXtd_Shape.def("Dump", (Standard_OStream & (TDataXtd_Shape::*)(Standard_OStream &) const) &TDataXtd_Shape::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Shape.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Shape::get_type_name, "None");
cls_TDataXtd_Shape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Shape::get_type_descriptor, "None");
cls_TDataXtd_Shape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Shape::*)() const) &TDataXtd_Shape::DynamicType, "None");

// Enums

}