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
#include <PCDM_Reader.hxx>
#include <PCDM_ReferenceIterator.hxx>
#include <Standard_Handle.hxx>
#include <CDM_MetaData.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Message_Messenger.hxx>
#include <PCDM_RetrievalDriver.hxx>
#include <Standard_Type.hxx>
#include <PCDM_SequenceOfReference.hxx>

void bind_PCDM_RetrievalDriver(py::module &mod){

py::class_<PCDM_RetrievalDriver, opencascade::handle<PCDM_RetrievalDriver>, PCDM_Reader> cls_PCDM_RetrievalDriver(mod, "PCDM_RetrievalDriver", "None");

// Fields

// Methods
cls_PCDM_RetrievalDriver.def_static("DocumentVersion_", (Standard_Integer (*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &)) &PCDM_RetrievalDriver::DocumentVersion, "None", py::arg("theFileName"), py::arg("theMsgDriver"));
cls_PCDM_RetrievalDriver.def_static("ReferenceCounter_", (Standard_Integer (*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &)) &PCDM_RetrievalDriver::ReferenceCounter, "None", py::arg("theFileName"), py::arg("theMsgDriver"));
cls_PCDM_RetrievalDriver.def("SetFormat", (void (PCDM_RetrievalDriver::*)(const TCollection_ExtendedString &)) &PCDM_RetrievalDriver::SetFormat, "None", py::arg("aformat"));
cls_PCDM_RetrievalDriver.def("GetFormat", (TCollection_ExtendedString (PCDM_RetrievalDriver::*)() const) &PCDM_RetrievalDriver::GetFormat, "None");
cls_PCDM_RetrievalDriver.def_static("get_type_name_", (const char * (*)()) &PCDM_RetrievalDriver::get_type_name, "None");
cls_PCDM_RetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_RetrievalDriver::get_type_descriptor, "None");
cls_PCDM_RetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_RetrievalDriver::*)() const) &PCDM_RetrievalDriver::DynamicType, "None");

// Enums

}