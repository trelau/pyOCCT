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
#include <Message_Messenger.hxx>
#include <CDM_Document.hxx>
#include <CDM_MetaData.hxx>
#include <CDM_Application.hxx>
#include <Standard_TypeDef.hxx>
#include <PCDM_ReferenceIterator.hxx>
#include <Standard_Type.hxx>
#include <PCDM_SequenceOfReference.hxx>

void bind_PCDM_ReferenceIterator(py::module &mod){

py::class_<PCDM_ReferenceIterator, opencascade::handle<PCDM_ReferenceIterator>, Standard_Transient> cls_PCDM_ReferenceIterator(mod, "PCDM_ReferenceIterator", "None");

// Constructors
cls_PCDM_ReferenceIterator.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_PCDM_ReferenceIterator.def("LoadReferences", (void (PCDM_ReferenceIterator::*)(const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_MetaData> &, const opencascade::handle<CDM_Application> &, const Standard_Boolean)) &PCDM_ReferenceIterator::LoadReferences, "None", py::arg("aDocument"), py::arg("aMetaData"), py::arg("anApplication"), py::arg("UseStorageConfiguration"));
cls_PCDM_ReferenceIterator.def("Init", (void (PCDM_ReferenceIterator::*)(const opencascade::handle<CDM_MetaData> &)) &PCDM_ReferenceIterator::Init, "None", py::arg("aMetaData"));
cls_PCDM_ReferenceIterator.def_static("get_type_name_", (const char * (*)()) &PCDM_ReferenceIterator::get_type_name, "None");
cls_PCDM_ReferenceIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_ReferenceIterator::get_type_descriptor, "None");
cls_PCDM_ReferenceIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_ReferenceIterator::*)() const) &PCDM_ReferenceIterator::DynamicType, "None");

// Enums

}