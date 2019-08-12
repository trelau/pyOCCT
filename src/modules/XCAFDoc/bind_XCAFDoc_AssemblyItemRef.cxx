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
#include <Standard_Handle.hxx>
#include <XCAFDoc_AssemblyItemRef.hxx>
#include <Standard_Type.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <XCAFDoc_AssemblyItemId.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_ListOfAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>

void bind_XCAFDoc_AssemblyItemRef(py::module &mod){

py::class_<XCAFDoc_AssemblyItemRef, opencascade::handle<XCAFDoc_AssemblyItemRef>, TDF_Attribute> cls_XCAFDoc_AssemblyItemRef(mod, "XCAFDoc_AssemblyItemRef", "An attribute that describes a weak reference to an assembly item or to a subshape or to an assembly label attribute.");

// Constructors
cls_XCAFDoc_AssemblyItemRef.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_AssemblyItemRef.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_AssemblyItemRef::get_type_name, "None");
cls_XCAFDoc_AssemblyItemRef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_AssemblyItemRef::get_type_descriptor, "None");
cls_XCAFDoc_AssemblyItemRef.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::DynamicType, "None");
cls_XCAFDoc_AssemblyItemRef.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_AssemblyItemRef::GetID, "None");
cls_XCAFDoc_AssemblyItemRef.def_static("Get_", (opencascade::handle<XCAFDoc_AssemblyItemRef> (*)(const TDF_Label &)) &XCAFDoc_AssemblyItemRef::Get, "Finds a reference attribute on the given label and returns it, if it is found", py::arg("theLabel"));
cls_XCAFDoc_AssemblyItemRef.def_static("Set_", (opencascade::handle<XCAFDoc_AssemblyItemRef> (*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &)) &XCAFDoc_AssemblyItemRef::Set, "Create (if not exist) a reference to an assembly item.", py::arg("theLabel"), py::arg("theItemId"));
cls_XCAFDoc_AssemblyItemRef.def_static("Set_", (opencascade::handle<XCAFDoc_AssemblyItemRef> (*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, const Standard_GUID &)) &XCAFDoc_AssemblyItemRef::Set, "Create (if not exist) a reference to an assembly item's label attribute.", py::arg("theLabel"), py::arg("theItemId"), py::arg("theGUID"));
cls_XCAFDoc_AssemblyItemRef.def_static("Set_", (opencascade::handle<XCAFDoc_AssemblyItemRef> (*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, const Standard_Integer)) &XCAFDoc_AssemblyItemRef::Set, "Create (if not exist) a reference to an assembly item's subshape.", py::arg("theLabel"), py::arg("theItemId"), py::arg("theShapeIndex"));
cls_XCAFDoc_AssemblyItemRef.def("IsOrphan", (Standard_Boolean (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::IsOrphan, "Checks if the reference points to a really existing item in XDE document.");
cls_XCAFDoc_AssemblyItemRef.def("HasExtraRef", (Standard_Boolean (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::HasExtraRef, "Checks if the reference points on an item's shapeindex or attribute.");
cls_XCAFDoc_AssemblyItemRef.def("IsGUID", (Standard_Boolean (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::IsGUID, "Checks is the reference points to an item's attribute.");
cls_XCAFDoc_AssemblyItemRef.def("IsSubshapeIndex", (Standard_Boolean (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::IsSubshapeIndex, "Checks is the reference points to an item's subshape.");
cls_XCAFDoc_AssemblyItemRef.def("GetGUID", (Standard_GUID (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::GetGUID, "Returns the assembly item's attribute that the reference points to. If the reference doesn't point to an attribute, returns an empty GUID.");
cls_XCAFDoc_AssemblyItemRef.def("GetSubshapeIndex", (Standard_Integer (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::GetSubshapeIndex, "Returns the assembly item's subshape that the reference points to. If the reference doesn't point to a subshape, returns 0.");
cls_XCAFDoc_AssemblyItemRef.def("GetItem", (const XCAFDoc_AssemblyItemId & (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::GetItem, "Returns the assembly item ID that the reference points to.");
cls_XCAFDoc_AssemblyItemRef.def("SetItem", (void (XCAFDoc_AssemblyItemRef::*)(const XCAFDoc_AssemblyItemId &)) &XCAFDoc_AssemblyItemRef::SetItem, "Sets the assembly item ID that the reference points to. Extra reference data (if any) will be cleared.", py::arg("theItemId"));
cls_XCAFDoc_AssemblyItemRef.def("SetItem", (void (XCAFDoc_AssemblyItemRef::*)(const TColStd_ListOfAsciiString &)) &XCAFDoc_AssemblyItemRef::SetItem, "Sets the assembly item ID from a list of label entries that the reference points to. Extra reference data (if any) will be cleared.", py::arg("thePath"));
cls_XCAFDoc_AssemblyItemRef.def("SetItem", (void (XCAFDoc_AssemblyItemRef::*)(const TCollection_AsciiString &)) &XCAFDoc_AssemblyItemRef::SetItem, "Sets the assembly item ID from a formatted path that the reference points to. Extra reference data (if any) will be cleared.", py::arg("theString"));
cls_XCAFDoc_AssemblyItemRef.def("SetGUID", (void (XCAFDoc_AssemblyItemRef::*)(const Standard_GUID &)) &XCAFDoc_AssemblyItemRef::SetGUID, "Sets the assembly item's label attribute that the reference points to. The base assembly item will not change.", py::arg("theAttrGUID"));
cls_XCAFDoc_AssemblyItemRef.def("SetSubshapeIndex", (void (XCAFDoc_AssemblyItemRef::*)(Standard_Integer)) &XCAFDoc_AssemblyItemRef::SetSubshapeIndex, "Sets the assembly item's subshape that the reference points to. The base assembly item will not change.", py::arg("theShapeIndex"));
cls_XCAFDoc_AssemblyItemRef.def("ClearExtraRef", (void (XCAFDoc_AssemblyItemRef::*)()) &XCAFDoc_AssemblyItemRef::ClearExtraRef, "Reverts the reference to empty state.");
cls_XCAFDoc_AssemblyItemRef.def("ID", (const Standard_GUID & (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::ID, "None");
cls_XCAFDoc_AssemblyItemRef.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_AssemblyItemRef::*)() const) &XCAFDoc_AssemblyItemRef::NewEmpty, "None");
cls_XCAFDoc_AssemblyItemRef.def("Restore", (void (XCAFDoc_AssemblyItemRef::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_AssemblyItemRef::Restore, "None", py::arg("theAttrFrom"));
cls_XCAFDoc_AssemblyItemRef.def("Paste", (void (XCAFDoc_AssemblyItemRef::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_AssemblyItemRef::Paste, "None", py::arg("theAttrInto"), py::arg("theRT"));
cls_XCAFDoc_AssemblyItemRef.def("Dump", (Standard_OStream & (XCAFDoc_AssemblyItemRef::*)(Standard_OStream &) const) &XCAFDoc_AssemblyItemRef::Dump, "None", py::arg("theOS"));

// Enums

}