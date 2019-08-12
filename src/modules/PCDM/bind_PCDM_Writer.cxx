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
#include <TCollection_ExtendedString.hxx>
#include <Standard_OStream.hxx>
#include <PCDM_Writer.hxx>
#include <Standard_Type.hxx>

void bind_PCDM_Writer(py::module &mod){

py::class_<PCDM_Writer, opencascade::handle<PCDM_Writer>, Standard_Transient> cls_PCDM_Writer(mod, "PCDM_Writer", "None");

// Fields

// Methods
cls_PCDM_Writer.def("Write", (void (PCDM_Writer::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &PCDM_Writer::Write, "None", py::arg("aDocument"), py::arg("aFileName"));
cls_PCDM_Writer.def("Write", (void (PCDM_Writer::*)(const opencascade::handle<CDM_Document> &, Standard_OStream &)) &PCDM_Writer::Write, "Write <theDocument> to theOStream", py::arg("theDocument"), py::arg("theOStream"));
cls_PCDM_Writer.def_static("get_type_name_", (const char * (*)()) &PCDM_Writer::get_type_name, "None");
cls_PCDM_Writer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_Writer::get_type_descriptor, "None");
cls_PCDM_Writer.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_Writer::*)() const) &PCDM_Writer::DynamicType, "None");

// Enums

}