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
#include <Quantity_PeriodDefinitionError.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Quantity_PeriodDefinitionError(py::module &mod){

py::class_<Quantity_PeriodDefinitionError, opencascade::handle<Quantity_PeriodDefinitionError>, Standard_DomainError> cls_Quantity_PeriodDefinitionError(mod, "Quantity_PeriodDefinitionError", "None");

// Constructors
cls_Quantity_PeriodDefinitionError.def(py::init<>());
cls_Quantity_PeriodDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Quantity_PeriodDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Quantity_PeriodDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Quantity_PeriodDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Quantity_PeriodDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Quantity_PeriodDefinitionError.def_static("NewInstance_", (opencascade::handle<Quantity_PeriodDefinitionError> (*)(const Standard_CString)) &Quantity_PeriodDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_Quantity_PeriodDefinitionError.def_static("get_type_name_", (const char * (*)()) &Quantity_PeriodDefinitionError::get_type_name, "None");
cls_Quantity_PeriodDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Quantity_PeriodDefinitionError::get_type_descriptor, "None");
cls_Quantity_PeriodDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Quantity_PeriodDefinitionError::*)() const) &Quantity_PeriodDefinitionError::DynamicType, "None");

// Enums

}