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
#include <TNaming_DataMapOfShapePtrRefShape.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_AttributeDelta.hxx>
#include <TDF_DeltaOnAddition.hxx>
#include <TDF_DeltaOnRemoval.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <TNaming_Builder.hxx>
#include <TNaming_UsedShapes.hxx>
#include <Standard_Type.hxx>

void bind_TNaming_UsedShapes(py::module &mod){

py::class_<TNaming_UsedShapes, opencascade::handle<TNaming_UsedShapes>, TDF_Attribute> cls_TNaming_UsedShapes(mod, "TNaming_UsedShapes", "Global attribute located under root label to store all the shapes handled by the framework Set of Shapes Used in a Data from TDF Only one instance by Data, it always Stored as Attribute of The Root.");

// Constructors

// Fields

// Methods
cls_TNaming_UsedShapes.def("Destroy", (void (TNaming_UsedShapes::*)()) &TNaming_UsedShapes::Destroy, "None");
cls_TNaming_UsedShapes.def("Map", (TNaming_DataMapOfShapePtrRefShape & (TNaming_UsedShapes::*)()) &TNaming_UsedShapes::Map, "None");
cls_TNaming_UsedShapes.def("ID", (const Standard_GUID & (TNaming_UsedShapes::*)() const) &TNaming_UsedShapes::ID, "Returns the ID of the attribute.");
cls_TNaming_UsedShapes.def_static("GetID_", (const Standard_GUID & (*)()) &TNaming_UsedShapes::GetID, "Returns the ID: 2a96b614-ec8b-11d0-bee7-080009dc3333.");
cls_TNaming_UsedShapes.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TNaming_UsedShapes::*)() const) &TNaming_UsedShapes::BackupCopy, "Copies the attribute contents into a new other attribute. It is used by Backup().");
cls_TNaming_UsedShapes.def("Restore", (void (TNaming_UsedShapes::*)(const opencascade::handle<TDF_Attribute> &)) &TNaming_UsedShapes::Restore, "Restores the contents from <anAttribute> into this one. It is used when aborting a transaction.", py::arg("anAttribute"));
cls_TNaming_UsedShapes.def("BeforeRemoval", (void (TNaming_UsedShapes::*)()) &TNaming_UsedShapes::BeforeRemoval, "Clears the table.");
cls_TNaming_UsedShapes.def("AfterUndo", [](TNaming_UsedShapes &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); });
cls_TNaming_UsedShapes.def("AfterUndo", (Standard_Boolean (TNaming_UsedShapes::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TNaming_UsedShapes::AfterUndo, "Something to do after applying <anAttDelta>.", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TNaming_UsedShapes.def("DeltaOnAddition", (opencascade::handle<TDF_DeltaOnAddition> (TNaming_UsedShapes::*)() const) &TNaming_UsedShapes::DeltaOnAddition, "this method returns a null handle (no delta).");
cls_TNaming_UsedShapes.def("DeltaOnRemoval", (opencascade::handle<TDF_DeltaOnRemoval> (TNaming_UsedShapes::*)() const) &TNaming_UsedShapes::DeltaOnRemoval, "this method returns a null handle (no delta).");
cls_TNaming_UsedShapes.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TNaming_UsedShapes::*)() const) &TNaming_UsedShapes::NewEmpty, "Returns an new empty attribute from the good end type. It is used by the copy algorithm.");
cls_TNaming_UsedShapes.def("Paste", (void (TNaming_UsedShapes::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TNaming_UsedShapes::Paste, "This method is different from the 'Copy' one, because it is used when copying an attribute from a source structure into a target structure. This method pastes the current attribute to the label corresponding to the insertor. The pasted attribute may be a brand new one or a new version of the previous one.", py::arg("intoAttribute"), py::arg("aRelocTationable"));
cls_TNaming_UsedShapes.def("References", (void (TNaming_UsedShapes::*)(const opencascade::handle<TDF_DataSet> &) const) &TNaming_UsedShapes::References, "Adds the directly referenced attributes and labels to <aDataSet>. 'Directly' means we have only to look at the first level of references.", py::arg("aDataSet"));
cls_TNaming_UsedShapes.def("Dump", (Standard_OStream & (TNaming_UsedShapes::*)(Standard_OStream &) const) &TNaming_UsedShapes::Dump, "Dumps the attribute on <aStream>.", py::arg("anOS"));
cls_TNaming_UsedShapes.def_static("get_type_name_", (const char * (*)()) &TNaming_UsedShapes::get_type_name, "None");
cls_TNaming_UsedShapes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TNaming_UsedShapes::get_type_descriptor, "None");
cls_TNaming_UsedShapes.def("DynamicType", (const opencascade::handle<Standard_Type> & (TNaming_UsedShapes::*)() const) &TNaming_UsedShapes::DynamicType, "None");

// Enums

}