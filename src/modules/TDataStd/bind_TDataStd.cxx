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
#include <Standard.hxx>
#include <TDF_IDList.hxx>
#include <Standard_OStream.hxx>
#include <TDataStd_RealEnum.hxx>
#include <TDataStd_Current.hxx>
#include <TDataStd_Name.hxx>
#include <TDataStd_Comment.hxx>
#include <TDataStd_Integer.hxx>
#include <TDataStd_IntegerArray.hxx>
#include <TDataStd_Real.hxx>
#include <TDataStd_RealArray.hxx>
#include <TDataStd_ExtStringArray.hxx>
#include <TDataStd_UAttribute.hxx>
#include <TDataStd_TreeNode.hxx>
#include <TDataStd_ChildNodeIterator.hxx>
#include <TDataStd_Directory.hxx>
#include <TDataStd_NoteBook.hxx>
#include <TDataStd_Expression.hxx>
#include <TDataStd_Relation.hxx>
#include <TDataStd_Variable.hxx>
#include <TDataStd_DeltaOnModificationOfIntArray.hxx>
#include <TDataStd_DeltaOnModificationOfRealArray.hxx>
#include <TDataStd_DeltaOnModificationOfExtStringArray.hxx>
#include <TDataStd_DeltaOnModificationOfIntPackedMap.hxx>
#include <TDataStd_DeltaOnModificationOfByteArray.hxx>
#include <TDataStd_Tick.hxx>
#include <TDataStd_AsciiString.hxx>
#include <TDataStd_IntPackedMap.hxx>
#include <TDataStd_IntegerList.hxx>
#include <TDataStd_RealList.hxx>
#include <TDataStd_ExtStringList.hxx>
#include <TDataStd_BooleanList.hxx>
#include <TDataStd_ReferenceList.hxx>
#include <TDataStd_BooleanArray.hxx>
#include <TDataStd_ReferenceArray.hxx>
#include <TDataStd_ByteArray.hxx>
#include <TDataStd_NamedData.hxx>
#include <TDataStd_HDataMapOfStringInteger.hxx>
#include <TDataStd_HDataMapOfStringReal.hxx>
#include <TDataStd_HDataMapOfStringString.hxx>
#include <TDataStd_HDataMapOfStringByte.hxx>
#include <TDataStd_HDataMapOfStringHArray1OfInteger.hxx>
#include <TDataStd_HDataMapOfStringHArray1OfReal.hxx>
#include <TDataStd.hxx>

void bind_TDataStd(py::module &mod){

py::class_<TDataStd, std::unique_ptr<TDataStd, Deleter<TDataStd>>> cls_TDataStd(mod, "TDataStd", "This package defines standard attributes for modelling. These allow you to create and modify labels and attributes for many basic data types. Standard topological and visualization attributes have also been created. To find an attribute attached to a specific label, you use the GUID of the type of attribute you are looking for. To do this, first find this information using the method GetID as follows: Standard_GUID anID = MyAttributeClass::GetID(); Then, use the method Find for the label as follows: Standard_Boolean HasAttribute = aLabel.Find(anID,anAttribute); Note For information on the relations between this component of OCAF and the others, refer to the OCAF User's Guide.");

// Constructors

// Fields

// Methods
// cls_TDataStd.def_static("operator new_", (void * (*)(size_t)) &TDataStd::operator new, "None", py::arg("theSize"));
// cls_TDataStd.def_static("operator delete_", (void (*)(void *)) &TDataStd::operator delete, "None", py::arg("theAddress"));
// cls_TDataStd.def_static("operator new[]_", (void * (*)(size_t)) &TDataStd::operator new[], "None", py::arg("theSize"));
// cls_TDataStd.def_static("operator delete[]_", (void (*)(void *)) &TDataStd::operator delete[], "None", py::arg("theAddress"));
// cls_TDataStd.def_static("operator new_", (void * (*)(size_t, void *)) &TDataStd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDataStd.def_static("operator delete_", (void (*)(void *, void *)) &TDataStd::operator delete, "None", py::arg(""), py::arg(""));
cls_TDataStd.def_static("IDList_", (void (*)(TDF_IDList &)) &TDataStd::IDList, "Appends to <anIDList> the list of the attributes IDs of this package. CAUTION: <anIDList> is NOT cleared before use.", py::arg("anIDList"));
cls_TDataStd.def_static("Print_", (Standard_OStream & (*)(const TDataStd_RealEnum, Standard_OStream &)) &TDataStd::Print, "Prints the name of the real dimension <DIM> as a String on the Stream <S> and returns <S>.", py::arg("DIM"), py::arg("S"));

// Enums

}