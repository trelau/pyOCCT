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
#include <TObj_Model.hxx>
#include <TDF_RelocationTable.hxx>
#include <TObj_TModel.hxx>
#include <Standard_Type.hxx>

void bind_TObj_TModel(py::module &mod){

py::class_<TObj_TModel, opencascade::handle<TObj_TModel>, TDF_Attribute> cls_TObj_TModel(mod, "TObj_TModel", "Attribute to store OCAF-based models in OCAF tree The persistency mechanism of the TObj_TModel allowes to save and restore various types of models without recompilation of the schema");

// Constructors
cls_TObj_TModel.def(py::init<>());

// Fields

// Methods
cls_TObj_TModel.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TModel::GetID, "This method is used in implementation of ID()");
cls_TObj_TModel.def("ID", (const Standard_GUID & (TObj_TModel::*)() const) &TObj_TModel::ID, "Returns the ID of TObj_TModel attribute.");
cls_TObj_TModel.def("Set", (void (TObj_TModel::*)(const opencascade::handle<TObj_Model> &)) &TObj_TModel::Set, "Sets the the Model object", py::arg("theModel"));
cls_TObj_TModel.def("Model", (opencascade::handle<TObj_Model> (TObj_TModel::*)() const) &TObj_TModel::Model, "Returns the Model object");
cls_TObj_TModel.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TModel::*)() const) &TObj_TModel::NewEmpty, "Returns an new empty TObj_TModel attribute. It is used by the copy algorithm.");
cls_TObj_TModel.def("Restore", (void (TObj_TModel::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TModel::Restore, "Restores the backuped contents from <theWith> into this one. It is used when aborting a transaction.", py::arg("theWith"));
cls_TObj_TModel.def("Paste", (void (TObj_TModel::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TObj_TModel::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
cls_TObj_TModel.def_static("get_type_name_", (const char * (*)()) &TObj_TModel::get_type_name, "None");
cls_TObj_TModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TModel::get_type_descriptor, "None");
cls_TObj_TModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TModel::*)() const) &TObj_TModel::DynamicType, "None");

// Enums

}