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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TNaming_Evolution.hxx>
#include <Standard_Handle.hxx>
#include <TDF_DeltaOnModification.hxx>
#include <TDF_DeltaOnRemoval.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <TDF_AttributeDelta.hxx>
#include <Standard_OStream.hxx>
#include <TNaming_Builder.hxx>
#include <TNaming_Iterator.hxx>
#include <TNaming_NewShapeIterator.hxx>
#include <TNaming_OldShapeIterator.hxx>
#include <TNaming_NamedShape.hxx>
#include <Standard_Type.hxx>
#include <TNaming_PtrNode.hxx>

void bind_TNaming_NamedShape(py::module &mod){

py::class_<TNaming_NamedShape, opencascade::handle<TNaming_NamedShape>, TDF_Attribute> cls_TNaming_NamedShape(mod, "TNaming_NamedShape", "The basis to define an attribute for the storage of topology and naming data. This attribute contains two parts: - The type of evolution, a term of the enumeration TNaming_Evolution - A list of pairs of shapes called the 'old' shape and the 'new' shape. The meaning depends on the type of evolution.");

// Constructors
cls_TNaming_NamedShape.def(py::init<>());

// Fields

// Methods
cls_TNaming_NamedShape.def_static("GetID_", (const Standard_GUID & (*)()) &TNaming_NamedShape::GetID, "class method ============ Returns the GUID for named shapes.");
cls_TNaming_NamedShape.def("IsEmpty", (Standard_Boolean (TNaming_NamedShape::*)() const) &TNaming_NamedShape::IsEmpty, "None");
cls_TNaming_NamedShape.def("Get", (TopoDS_Shape (TNaming_NamedShape::*)() const) &TNaming_NamedShape::Get, "Returns the shapes contained in <NS>. Returns a null shape if IsEmpty.");
cls_TNaming_NamedShape.def("Evolution", (TNaming_Evolution (TNaming_NamedShape::*)() const) &TNaming_NamedShape::Evolution, "Returns the Evolution of the attribute.");
cls_TNaming_NamedShape.def("Version", (Standard_Integer (TNaming_NamedShape::*)() const) &TNaming_NamedShape::Version, "Returns the Version of the attribute.");
cls_TNaming_NamedShape.def("SetVersion", (void (TNaming_NamedShape::*)(const Standard_Integer)) &TNaming_NamedShape::SetVersion, "Set the Version of the attribute.", py::arg("version"));
cls_TNaming_NamedShape.def("Clear", (void (TNaming_NamedShape::*)()) &TNaming_NamedShape::Clear, "None");
cls_TNaming_NamedShape.def("ID", (const Standard_GUID & (TNaming_NamedShape::*)() const) &TNaming_NamedShape::ID, "Returns the ID of the attribute.");
cls_TNaming_NamedShape.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TNaming_NamedShape::*)() const) &TNaming_NamedShape::BackupCopy, "Copies the attribute contents into a new other attribute. It is used by Backup().");
cls_TNaming_NamedShape.def("Restore", (void (TNaming_NamedShape::*)(const opencascade::handle<TDF_Attribute> &)) &TNaming_NamedShape::Restore, "Restores the contents from <anAttribute> into this one. It is used when aborting a transaction.", py::arg("anAttribute"));
cls_TNaming_NamedShape.def("DeltaOnModification", (opencascade::handle<TDF_DeltaOnModification> (TNaming_NamedShape::*)(const opencascade::handle<TDF_Attribute> &) const) &TNaming_NamedShape::DeltaOnModification, "Makes a DeltaOnModification between <me> and <anOldAttribute.", py::arg("anOldAttribute"));
cls_TNaming_NamedShape.def("DeltaOnModification", (void (TNaming_NamedShape::*)(const opencascade::handle<TDF_DeltaOnModification> &)) &TNaming_NamedShape::DeltaOnModification, "Applies a DeltaOnModification to <me>.", py::arg("aDelta"));
cls_TNaming_NamedShape.def("DeltaOnRemoval", (opencascade::handle<TDF_DeltaOnRemoval> (TNaming_NamedShape::*)() const) &TNaming_NamedShape::DeltaOnRemoval, "Makes a DeltaOnRemoval on <me> because <me> has disappeared from the DS.");
cls_TNaming_NamedShape.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TNaming_NamedShape::*)() const) &TNaming_NamedShape::NewEmpty, "Returns an new empty attribute from the good end type. It is used by the copy algorithm.");
cls_TNaming_NamedShape.def("Paste", (void (TNaming_NamedShape::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TNaming_NamedShape::Paste, "This method is different from the 'Copy' one, because it is used when copying an attribute from a source structure into a target structure. This method pastes the current attribute to the label corresponding to the insertor. The pasted attribute may be a brand new one or a new version of the previous one.", py::arg("intoAttribute"), py::arg("aRelocTationable"));
cls_TNaming_NamedShape.def("References", (void (TNaming_NamedShape::*)(const opencascade::handle<TDF_DataSet> &) const) &TNaming_NamedShape::References, "Adds the directly referenced attributes and labels to <aDataSet>. 'Directly' means we have only to look at the first level of references.", py::arg("aDataSet"));
cls_TNaming_NamedShape.def("BeforeRemoval", (void (TNaming_NamedShape::*)()) &TNaming_NamedShape::BeforeRemoval, "None");
cls_TNaming_NamedShape.def("BeforeUndo", [](TNaming_NamedShape &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); });
cls_TNaming_NamedShape.def("BeforeUndo", (Standard_Boolean (TNaming_NamedShape::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TNaming_NamedShape::BeforeUndo, "Something to do before applying <anAttDelta>", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TNaming_NamedShape.def("AfterUndo", [](TNaming_NamedShape &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); });
cls_TNaming_NamedShape.def("AfterUndo", (Standard_Boolean (TNaming_NamedShape::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TNaming_NamedShape::AfterUndo, "Something to do after applying <anAttDelta>.", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TNaming_NamedShape.def("Dump", (Standard_OStream & (TNaming_NamedShape::*)(Standard_OStream &) const) &TNaming_NamedShape::Dump, "Dumps the attribute on <aStream>.", py::arg("anOS"));
cls_TNaming_NamedShape.def_static("get_type_name_", (const char * (*)()) &TNaming_NamedShape::get_type_name, "None");
cls_TNaming_NamedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TNaming_NamedShape::get_type_descriptor, "None");
cls_TNaming_NamedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TNaming_NamedShape::*)() const) &TNaming_NamedShape::DynamicType, "None");

// Enums

}