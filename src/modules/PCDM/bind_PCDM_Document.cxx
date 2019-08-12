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
#include <Standard_Persistent.hxx>
#include <Standard_Handle.hxx>
#include <PCDM_Document.hxx>
#include <Standard_Type.hxx>

void bind_PCDM_Document(py::module &mod){

py::class_<PCDM_Document, opencascade::handle<PCDM_Document>, Standard_Persistent> cls_PCDM_Document(mod, "PCDM_Document", "None");

// Constructors

// Fields

// Methods
cls_PCDM_Document.def_static("get_type_name_", (const char * (*)()) &PCDM_Document::get_type_name, "None");
cls_PCDM_Document.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_Document::get_type_descriptor, "None");
cls_PCDM_Document.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_Document::*)() const) &PCDM_Document::DynamicType, "None");

// Enums

}