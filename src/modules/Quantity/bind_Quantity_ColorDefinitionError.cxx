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
#include <Standard_DomainError.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Quantity_ColorDefinitionError.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Quantity_ColorDefinitionError(py::module &mod){

py::class_<Quantity_ColorDefinitionError, opencascade::handle<Quantity_ColorDefinitionError>, Standard_DomainError> cls_Quantity_ColorDefinitionError(mod, "Quantity_ColorDefinitionError", "None");

// Constructors
cls_Quantity_ColorDefinitionError.def(py::init<>());
cls_Quantity_ColorDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Quantity_ColorDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Quantity_ColorDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Quantity_ColorDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Quantity_ColorDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Quantity_ColorDefinitionError.def_static("NewInstance_", (opencascade::handle<Quantity_ColorDefinitionError> (*)(const Standard_CString)) &Quantity_ColorDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_Quantity_ColorDefinitionError.def_static("get_type_name_", (const char * (*)()) &Quantity_ColorDefinitionError::get_type_name, "None");
cls_Quantity_ColorDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Quantity_ColorDefinitionError::get_type_descriptor, "None");
cls_Quantity_ColorDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Quantity_ColorDefinitionError::*)() const) &Quantity_ColorDefinitionError::DynamicType, "None");

// Enums

}