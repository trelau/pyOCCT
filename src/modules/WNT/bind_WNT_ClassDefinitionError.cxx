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
#include <Standard_ConstructionError.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <WNT_ClassDefinitionError.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_WNT_ClassDefinitionError(py::module &mod){

py::class_<WNT_ClassDefinitionError, opencascade::handle<WNT_ClassDefinitionError>, Standard_ConstructionError> cls_WNT_ClassDefinitionError(mod, "WNT_ClassDefinitionError", "None");

// Constructors
cls_WNT_ClassDefinitionError.def(py::init<>());
cls_WNT_ClassDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_WNT_ClassDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &WNT_ClassDefinitionError::Raise, "None", py::arg("theMessage"));
cls_WNT_ClassDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &WNT_ClassDefinitionError::Raise, "None", py::arg("theMessage"));
cls_WNT_ClassDefinitionError.def_static("NewInstance_", (opencascade::handle<WNT_ClassDefinitionError> (*)(const Standard_CString)) &WNT_ClassDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_WNT_ClassDefinitionError.def_static("get_type_name_", (const char * (*)()) &WNT_ClassDefinitionError::get_type_name, "None");
cls_WNT_ClassDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &WNT_ClassDefinitionError::get_type_descriptor, "None");
cls_WNT_ClassDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (WNT_ClassDefinitionError::*)() const) &WNT_ClassDefinitionError::DynamicType, "None");

// Enums

}