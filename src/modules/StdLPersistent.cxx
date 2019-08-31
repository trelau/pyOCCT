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
#include <bind_StdObjMgt_Attribute.hxx>
#include <NCollection_Array1.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <Standard_Type.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <NCollection_Array2.hxx>
#include <StdLPersistent_HArray2.hxx>
#include <TColStd_HArray2OfInteger.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <StdLPersistent.hxx>
#include <StdLPersistent_Collection.hxx>
#include <StdObjMgt_Attribute.hxx>
#include <TDataStd_BooleanArray.hxx>
#include <TDataStd_IntegerArray.hxx>
#include <TDataStd_RealArray.hxx>
#include <TDataStd_ByteArray.hxx>
#include <TDataStd_ExtStringArray.hxx>
#include <TDataStd_ReferenceArray.hxx>
#include <TDataStd_IntegerList.hxx>
#include <TDataStd_RealList.hxx>
#include <TDataStd_BooleanList.hxx>
#include <TDataStd_ExtStringList.hxx>
#include <TDataStd_ReferenceList.hxx>
#include <TDataStd_IntPackedMap.hxx>
#include <TDF_Data.hxx>
#include <StdLPersistent_Data.hxx>
#include <TDF_Label.hxx>
#include <StdLPersistent_HString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_HExtendedString.hxx>
#include <StdLPersistent_Dependency.hxx>
#include <TDataStd_Expression.hxx>
#include <TDataStd_Relation.hxx>
#include <TDocStd_Document.hxx>
#include <StdLPersistent_Document.hxx>
#include <TFunction_Function.hxx>
#include <Standard_GUID.hxx>
#include <StdLPersistent_Function.hxx>
#include <TDataStd_NamedData.hxx>
#include <StdLPersistent_NamedData.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TDataStd_Real.hxx>
#include <TDataStd_RealEnum.hxx>
#include <StdLPersistent_Real.hxx>
#include <TDataStd_TreeNode.hxx>
#include <TDF_Attribute.hxx>
#include <StdLPersistent_TreeNode.hxx>
#include <StdLPersistent_Value.hxx>
#include <TDF_TagSource.hxx>
#include <TDF_Reference.hxx>
#include <TDataStd_Comment.hxx>
#include <TDataStd_UAttribute.hxx>
#include <TDataStd_Integer.hxx>
#include <TDataStd_Name.hxx>
#include <TDataStd_AsciiString.hxx>
#include <TDataStd_Variable.hxx>
#include <StdLPersistent_Variable.hxx>
#include <StdLPersistent_Void.hxx>
#include <TDataStd_Directory.hxx>
#include <TDataStd_Tick.hxx>
#include <TDataStd_NoteBook.hxx>
#include <TDocStd_XLink.hxx>
#include <StdLPersistent_XLink.hxx>

PYBIND11_MODULE(StdLPersistent, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.StdObjMgt");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TDataStd");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.TFunction");

// CLASS: STDLPERSISTENT_HARRAY1OFPERSISTENT
py::class_<StdLPersistent_HArray1OfPersistent, opencascade::handle<StdLPersistent_HArray1OfPersistent>, Standard_Transient> cls_StdLPersistent_HArray1OfPersistent(mod, "StdLPersistent_HArray1OfPersistent", "None", py::multiple_inheritance());

// Constructors
cls_StdLPersistent_HArray1OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StdLPersistent_HArray1OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer, const NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> >::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StdLPersistent_HArray1OfPersistent.def(py::init<const NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> > &>(), py::arg("theOther"));

// Methods
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator new_", (void * (*)(size_t)) &StdLPersistent_HArray1OfPersistent::operator new, "None", py::arg("theSize"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator delete_", (void (*)(void *)) &StdLPersistent_HArray1OfPersistent::operator delete, "None", py::arg("theAddress"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator new[]_", (void * (*)(size_t)) &StdLPersistent_HArray1OfPersistent::operator new[], "None", py::arg("theSize"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator delete[]_", (void (*)(void *)) &StdLPersistent_HArray1OfPersistent::operator delete[], "None", py::arg("theAddress"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator new_", (void * (*)(size_t, void *)) &StdLPersistent_HArray1OfPersistent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator delete_", (void (*)(void *, void *)) &StdLPersistent_HArray1OfPersistent::operator delete, "None", py::arg(""), py::arg(""));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StdLPersistent_HArray1OfPersistent::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StdLPersistent_HArray1OfPersistent::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StdLPersistent_HArray1OfPersistent.def("Array1", (const NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray1OfPersistent::*)() const) &StdLPersistent_HArray1OfPersistent::Array1, "None");
cls_StdLPersistent_HArray1OfPersistent.def("ChangeArray1", (NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray1OfPersistent::*)()) &StdLPersistent_HArray1OfPersistent::ChangeArray1, "None");
cls_StdLPersistent_HArray1OfPersistent.def_static("get_type_name_", (const char * (*)()) &StdLPersistent_HArray1OfPersistent::get_type_name, "None");
cls_StdLPersistent_HArray1OfPersistent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdLPersistent_HArray1OfPersistent::get_type_descriptor, "None");
cls_StdLPersistent_HArray1OfPersistent.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdLPersistent_HArray1OfPersistent::*)() const) &StdLPersistent_HArray1OfPersistent::DynamicType, "None");

// CLASS: STDLPERSISTENT_HARRAY1
py::class_<StdLPersistent_HArray1> cls_StdLPersistent_HArray1(mod, "StdLPersistent_HArray1", "None");

// CLASS: STDLPERSISTENT_HARRAY2OFPERSISTENT
py::class_<StdLPersistent_HArray2OfPersistent, opencascade::handle<StdLPersistent_HArray2OfPersistent>, Standard_Transient> cls_StdLPersistent_HArray2OfPersistent(mod, "StdLPersistent_HArray2OfPersistent", "None", py::multiple_inheritance());

// Constructors
cls_StdLPersistent_HArray2OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_StdLPersistent_HArray2OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> >::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_StdLPersistent_HArray2OfPersistent.def(py::init<const NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> > &>(), py::arg("theOther"));

// Methods
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator new_", (void * (*)(size_t)) &StdLPersistent_HArray2OfPersistent::operator new, "None", py::arg("theSize"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator delete_", (void (*)(void *)) &StdLPersistent_HArray2OfPersistent::operator delete, "None", py::arg("theAddress"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator new[]_", (void * (*)(size_t)) &StdLPersistent_HArray2OfPersistent::operator new[], "None", py::arg("theSize"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator delete[]_", (void (*)(void *)) &StdLPersistent_HArray2OfPersistent::operator delete[], "None", py::arg("theAddress"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator new_", (void * (*)(size_t, void *)) &StdLPersistent_HArray2OfPersistent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator delete_", (void (*)(void *, void *)) &StdLPersistent_HArray2OfPersistent::operator delete, "None", py::arg(""), py::arg(""));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StdLPersistent_HArray2OfPersistent::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StdLPersistent_HArray2OfPersistent::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StdLPersistent_HArray2OfPersistent.def("Array2", (const NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray2OfPersistent::*)() const) &StdLPersistent_HArray2OfPersistent::Array2, "None");
cls_StdLPersistent_HArray2OfPersistent.def("ChangeArray2", (NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray2OfPersistent::*)()) &StdLPersistent_HArray2OfPersistent::ChangeArray2, "None");
cls_StdLPersistent_HArray2OfPersistent.def_static("get_type_name_", (const char * (*)()) &StdLPersistent_HArray2OfPersistent::get_type_name, "None");
cls_StdLPersistent_HArray2OfPersistent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdLPersistent_HArray2OfPersistent::get_type_descriptor, "None");
cls_StdLPersistent_HArray2OfPersistent.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdLPersistent_HArray2OfPersistent::*)() const) &StdLPersistent_HArray2OfPersistent::DynamicType, "None");

// CLASS: STDLPERSISTENT_HARRAY2
py::class_<StdLPersistent_HArray2> cls_StdLPersistent_HArray2(mod, "StdLPersistent_HArray2", "None");

// CLASS: STDLPERSISTENT
py::class_<StdLPersistent> cls_StdLPersistent(mod, "StdLPersistent", "None");

// Methods
cls_StdLPersistent.def_static("BindTypes_", (void (*)(StdObjMgt_MapOfInstantiators &)) &StdLPersistent::BindTypes, "Register types.", py::arg("theMap"));

// CLASS: STDLPERSISTENT_COLLECTION
py::class_<StdLPersistent_Collection> cls_StdLPersistent_Collection(mod, "StdLPersistent_Collection", "None");

// CLASS: STDLPERSISTENT_DATA
py::class_<StdLPersistent_Data, opencascade::handle<StdLPersistent_Data>, StdObjMgt_Persistent> cls_StdLPersistent_Data(mod, "StdLPersistent_Data", "None");

// Methods
cls_StdLPersistent_Data.def("Read", (void (StdLPersistent_Data::*)(StdObjMgt_ReadData &)) &StdLPersistent_Data::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_Data.def("Write", (void (StdLPersistent_Data::*)(StdObjMgt_WriteData &) const) &StdLPersistent_Data::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdLPersistent_Data.def("PChildren", (void (StdLPersistent_Data::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_Data::PChildren, "Gets persistent child objects", py::arg("theChildren"));
cls_StdLPersistent_Data.def("PName", (Standard_CString (StdLPersistent_Data::*)() const) &StdLPersistent_Data::PName, "Returns persistent type name");
cls_StdLPersistent_Data.def("Import", (opencascade::handle<TDF_Data> (StdLPersistent_Data::*)() const) &StdLPersistent_Data::Import, "Import transient data from the persistent data.");

// CLASS: STDLPERSISTENT_HSTRING
py::class_<StdLPersistent_HString> cls_StdLPersistent_HString(mod, "StdLPersistent_HString", "None");

// CLASS: STDLPERSISTENT_DEPENDENCY
py::class_<StdLPersistent_Dependency> cls_StdLPersistent_Dependency(mod, "StdLPersistent_Dependency", "None");

// CLASS: STDLPERSISTENT_DOCUMENT
py::class_<StdLPersistent_Document, opencascade::handle<StdLPersistent_Document>, StdObjMgt_Persistent> cls_StdLPersistent_Document(mod, "StdLPersistent_Document", "None");

// Methods
cls_StdLPersistent_Document.def("Read", (void (StdLPersistent_Document::*)(StdObjMgt_ReadData &)) &StdLPersistent_Document::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_Document.def("Write", (void (StdLPersistent_Document::*)(StdObjMgt_WriteData &) const) &StdLPersistent_Document::Write, "Read persistent data from a file.", py::arg("theWriteData"));
cls_StdLPersistent_Document.def("PChildren", (void (StdLPersistent_Document::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_Document::PChildren, "Gets persistent child objects", py::arg(""));
cls_StdLPersistent_Document.def("PName", (Standard_CString (StdLPersistent_Document::*)() const) &StdLPersistent_Document::PName, "Returns persistent type name");
cls_StdLPersistent_Document.def("ImportDocument", (void (StdLPersistent_Document::*)(const opencascade::handle<TDocStd_Document> &) const) &StdLPersistent_Document::ImportDocument, "Import transient document from the persistent data.", py::arg("theDocument"));

// CLASS: STDLPERSISTENT_FUNCTION
bind_StdObjMgt_Attribute<TFunction_Function>(mod, "StdObjMgt_Attribute_TFunction_Function", py::module_local());

py::class_<StdLPersistent_Function, opencascade::handle<StdLPersistent_Function>, StdObjMgt_Attribute<TFunction_Function>> cls_StdLPersistent_Function(mod, "StdLPersistent_Function", "None");

// Methods
cls_StdLPersistent_Function.def("Read", (void (StdLPersistent_Function::*)(StdObjMgt_ReadData &)) &StdLPersistent_Function::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_Function.def("Write", (void (StdLPersistent_Function::*)(StdObjMgt_WriteData &) const) &StdLPersistent_Function::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdLPersistent_Function.def("PChildren", (void (StdLPersistent_Function::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_Function::PChildren, "Gets persistent child objects", py::arg(""));
cls_StdLPersistent_Function.def("PName", (Standard_CString (StdLPersistent_Function::*)() const) &StdLPersistent_Function::PName, "Returns persistent type name");
cls_StdLPersistent_Function.def("Import", (void (StdLPersistent_Function::*)(const opencascade::handle<TFunction_Function> &) const) &StdLPersistent_Function::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// CLASS: STDLPERSISTENT_NAMEDDATA
bind_StdObjMgt_Attribute<TDataStd_NamedData>(mod, "StdObjMgt_Attribute_TDataStd_NamedData", py::module_local());

py::class_<StdLPersistent_NamedData, opencascade::handle<StdLPersistent_NamedData>, StdObjMgt_Attribute<TDataStd_NamedData>> cls_StdLPersistent_NamedData(mod, "StdLPersistent_NamedData", "None");

// Methods
cls_StdLPersistent_NamedData.def("Read", (void (StdLPersistent_NamedData::*)(StdObjMgt_ReadData &)) &StdLPersistent_NamedData::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_NamedData.def("Write", (void (StdLPersistent_NamedData::*)(StdObjMgt_WriteData &) const) &StdLPersistent_NamedData::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdLPersistent_NamedData.def("PChildren", (void (StdLPersistent_NamedData::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_NamedData::PChildren, "Gets persistent child objects", py::arg(""));
cls_StdLPersistent_NamedData.def("PName", (Standard_CString (StdLPersistent_NamedData::*)() const) &StdLPersistent_NamedData::PName, "Returns persistent type name");
// cls_StdLPersistent_NamedData.def("Import", (void (StdLPersistent_NamedData::*)(const opencascade::handle<TDataStd_NamedData> &) const) &StdLPersistent_NamedData::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// CLASS: STDLPERSISTENT_REAL
bind_StdObjMgt_Attribute<TDataStd_Real>(mod, "StdObjMgt_Attribute_TDataStd_Real", py::module_local());

py::class_<StdLPersistent_Real, opencascade::handle<StdLPersistent_Real>, StdObjMgt_Attribute<TDataStd_Real>> cls_StdLPersistent_Real(mod, "StdLPersistent_Real", "None");

// Methods
cls_StdLPersistent_Real.def("Read", (void (StdLPersistent_Real::*)(StdObjMgt_ReadData &)) &StdLPersistent_Real::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_Real.def("Write", (void (StdLPersistent_Real::*)(StdObjMgt_WriteData &) const) &StdLPersistent_Real::Write, "Write persistent data from a file.", py::arg("theWriteData"));
cls_StdLPersistent_Real.def("PChildren", (void (StdLPersistent_Real::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_Real::PChildren, "Gets persistent child objects", py::arg(""));
cls_StdLPersistent_Real.def("PName", (Standard_CString (StdLPersistent_Real::*)() const) &StdLPersistent_Real::PName, "Returns persistent type name");
cls_StdLPersistent_Real.def("Import", (void (StdLPersistent_Real::*)(const opencascade::handle<TDataStd_Real> &) const) &StdLPersistent_Real::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// CLASS: STDLPERSISTENT_TREENODE
py::class_<StdLPersistent_TreeNode, opencascade::handle<StdLPersistent_TreeNode>> cls_StdLPersistent_TreeNode(mod, "StdLPersistent_TreeNode", "None");

// Methods
cls_StdLPersistent_TreeNode.def("Read", (void (StdLPersistent_TreeNode::*)(StdObjMgt_ReadData &)) &StdLPersistent_TreeNode::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_TreeNode.def("Write", (void (StdLPersistent_TreeNode::*)(StdObjMgt_WriteData &) const) &StdLPersistent_TreeNode::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdLPersistent_TreeNode.def("PChildren", (void (StdLPersistent_TreeNode::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_TreeNode::PChildren, "Gets persistent child objects", py::arg(""));
cls_StdLPersistent_TreeNode.def("PName", (Standard_CString (StdLPersistent_TreeNode::*)() const) &StdLPersistent_TreeNode::PName, "Returns persistent type name");
cls_StdLPersistent_TreeNode.def("CreateAttribute", (opencascade::handle<TDF_Attribute> (StdLPersistent_TreeNode::*)()) &StdLPersistent_TreeNode::CreateAttribute, "Create an empty transient attribuite");
cls_StdLPersistent_TreeNode.def("ImportAttribute", (void (StdLPersistent_TreeNode::*)()) &StdLPersistent_TreeNode::ImportAttribute, "Import transient attribuite from the persistent data.");

// CLASS: STDLPERSISTENT_VALUE
py::class_<StdLPersistent_Value> cls_StdLPersistent_Value(mod, "StdLPersistent_Value", "None");

// CLASS: STDLPERSISTENT_VARIABLE
bind_StdObjMgt_Attribute<TDataStd_Variable>(mod, "StdObjMgt_Attribute_TDataStd_Variable", py::module_local());

py::class_<StdLPersistent_Variable, opencascade::handle<StdLPersistent_Variable>, StdObjMgt_Attribute<TDataStd_Variable>> cls_StdLPersistent_Variable(mod, "StdLPersistent_Variable", "None");

// Methods
cls_StdLPersistent_Variable.def("Read", (void (StdLPersistent_Variable::*)(StdObjMgt_ReadData &)) &StdLPersistent_Variable::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_Variable.def("Write", (void (StdLPersistent_Variable::*)(StdObjMgt_WriteData &) const) &StdLPersistent_Variable::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdLPersistent_Variable.def("PChildren", (void (StdLPersistent_Variable::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_Variable::PChildren, "Gets persistent child objects", py::arg("theChildren"));
cls_StdLPersistent_Variable.def("PName", (Standard_CString (StdLPersistent_Variable::*)() const) &StdLPersistent_Variable::PName, "Returns persistent type name");
cls_StdLPersistent_Variable.def("Import", (void (StdLPersistent_Variable::*)(const opencascade::handle<TDataStd_Variable> &) const) &StdLPersistent_Variable::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// CLASS: STDLPERSISTENT_VOID
py::class_<StdLPersistent_Void> cls_StdLPersistent_Void(mod, "StdLPersistent_Void", "None");

// CLASS: STDLPERSISTENT_XLINK
bind_StdObjMgt_Attribute<TDocStd_XLink>(mod, "StdObjMgt_Attribute_TDocStd_XLink", py::module_local());

py::class_<StdLPersistent_XLink, opencascade::handle<StdLPersistent_XLink>, StdObjMgt_Attribute<TDocStd_XLink>> cls_StdLPersistent_XLink(mod, "StdLPersistent_XLink", "None");

// Methods
cls_StdLPersistent_XLink.def("Read", (void (StdLPersistent_XLink::*)(StdObjMgt_ReadData &)) &StdLPersistent_XLink::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_XLink.def("Write", (void (StdLPersistent_XLink::*)(StdObjMgt_WriteData &) const) &StdLPersistent_XLink::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdLPersistent_XLink.def("PChildren", (void (StdLPersistent_XLink::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_XLink::PChildren, "Gets persistent child objects", py::arg("theChildren"));
cls_StdLPersistent_XLink.def("PName", (Standard_CString (StdLPersistent_XLink::*)() const) &StdLPersistent_XLink::PName, "Returns persistent type name");
cls_StdLPersistent_XLink.def("Import", (void (StdLPersistent_XLink::*)(const opencascade::handle<TDocStd_XLink> &) const) &StdLPersistent_XLink::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));


}
