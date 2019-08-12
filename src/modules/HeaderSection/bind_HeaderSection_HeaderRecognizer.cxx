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
#include <StepData_FileRecognizer.hxx>
#include <Standard_Handle.hxx>
#include <HeaderSection_HeaderRecognizer.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>

void bind_HeaderSection_HeaderRecognizer(py::module &mod){

py::class_<HeaderSection_HeaderRecognizer, opencascade::handle<HeaderSection_HeaderRecognizer>, StepData_FileRecognizer> cls_HeaderSection_HeaderRecognizer(mod, "HeaderSection_HeaderRecognizer", "Recognizes STEP Standard Header Entities (FileName, FileDescription, FileSchema)");

// Constructors
cls_HeaderSection_HeaderRecognizer.def(py::init<>());

// Fields

// Methods
cls_HeaderSection_HeaderRecognizer.def_static("get_type_name_", (const char * (*)()) &HeaderSection_HeaderRecognizer::get_type_name, "None");
cls_HeaderSection_HeaderRecognizer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HeaderSection_HeaderRecognizer::get_type_descriptor, "None");
cls_HeaderSection_HeaderRecognizer.def("DynamicType", (const opencascade::handle<Standard_Type> & (HeaderSection_HeaderRecognizer::*)() const) &HeaderSection_HeaderRecognizer::DynamicType, "None");

// Enums

}