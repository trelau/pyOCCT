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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <PCDM_StoreStatus.hxx>
#include <CDM_MetaData.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDF_StoreList.hxx>
#include <Standard_Type.hxx>
#include <CDM_MapOfDocument.hxx>
#include <CDM_ListOfDocument.hxx>

void bind_CDF_StoreList(py::module &mod){

py::class_<CDF_StoreList, opencascade::handle<CDF_StoreList>, Standard_Transient> cls_CDF_StoreList(mod, "CDF_StoreList", "None");

// Constructors
cls_CDF_StoreList.def(py::init<const opencascade::handle<CDM_Document> &>(), py::arg("aDocument"));

// Fields

// Methods
cls_CDF_StoreList.def("IsConsistent", (Standard_Boolean (CDF_StoreList::*)() const) &CDF_StoreList::IsConsistent, "None");
cls_CDF_StoreList.def("Store", (PCDM_StoreStatus (CDF_StoreList::*)(opencascade::handle<CDM_MetaData> &, TCollection_ExtendedString &)) &CDF_StoreList::Store, "stores each object of the storelist in the reverse order of which they had been added.", py::arg("aMetaData"), py::arg("aStatusAssociatedText"));
cls_CDF_StoreList.def("Init", (void (CDF_StoreList::*)()) &CDF_StoreList::Init, "None");
cls_CDF_StoreList.def("More", (Standard_Boolean (CDF_StoreList::*)() const) &CDF_StoreList::More, "None");
cls_CDF_StoreList.def("Next", (void (CDF_StoreList::*)()) &CDF_StoreList::Next, "None");
cls_CDF_StoreList.def("Value", (opencascade::handle<CDM_Document> (CDF_StoreList::*)() const) &CDF_StoreList::Value, "None");
cls_CDF_StoreList.def_static("get_type_name_", (const char * (*)()) &CDF_StoreList::get_type_name, "None");
cls_CDF_StoreList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_StoreList::get_type_descriptor, "None");
cls_CDF_StoreList.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_StoreList::*)() const) &CDF_StoreList::DynamicType, "None");

// Enums

}