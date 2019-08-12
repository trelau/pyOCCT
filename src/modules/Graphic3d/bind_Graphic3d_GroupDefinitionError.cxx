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
#include <Standard_OutOfRange.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_GroupDefinitionError.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_GroupDefinitionError(py::module &mod){

py::class_<Graphic3d_GroupDefinitionError, opencascade::handle<Graphic3d_GroupDefinitionError>, Standard_OutOfRange> cls_Graphic3d_GroupDefinitionError(mod, "Graphic3d_GroupDefinitionError", "None");

// Constructors
cls_Graphic3d_GroupDefinitionError.def(py::init<>());
cls_Graphic3d_GroupDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Graphic3d_GroupDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Graphic3d_GroupDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Graphic3d_GroupDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Graphic3d_GroupDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Graphic3d_GroupDefinitionError.def_static("NewInstance_", (opencascade::handle<Graphic3d_GroupDefinitionError> (*)(const Standard_CString)) &Graphic3d_GroupDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_Graphic3d_GroupDefinitionError.def_static("get_type_name_", (const char * (*)()) &Graphic3d_GroupDefinitionError::get_type_name, "None");
cls_Graphic3d_GroupDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_GroupDefinitionError::get_type_descriptor, "None");
cls_Graphic3d_GroupDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_GroupDefinitionError::*)() const) &Graphic3d_GroupDefinitionError::DynamicType, "None");

// Enums

}