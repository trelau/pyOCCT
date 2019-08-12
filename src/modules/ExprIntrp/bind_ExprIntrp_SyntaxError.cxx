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
#include <Standard_Failure.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ExprIntrp_SyntaxError.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_ExprIntrp_SyntaxError(py::module &mod){

py::class_<ExprIntrp_SyntaxError, opencascade::handle<ExprIntrp_SyntaxError>, Standard_Failure> cls_ExprIntrp_SyntaxError(mod, "ExprIntrp_SyntaxError", "None");

// Constructors
cls_ExprIntrp_SyntaxError.def(py::init<>());
cls_ExprIntrp_SyntaxError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_ExprIntrp_SyntaxError.def_static("Raise_", (void (*)(const Standard_CString)) &ExprIntrp_SyntaxError::Raise, "None", py::arg("theMessage"));
cls_ExprIntrp_SyntaxError.def_static("Raise_", (void (*)(Standard_SStream &)) &ExprIntrp_SyntaxError::Raise, "None", py::arg("theMessage"));
cls_ExprIntrp_SyntaxError.def_static("NewInstance_", (opencascade::handle<ExprIntrp_SyntaxError> (*)(const Standard_CString)) &ExprIntrp_SyntaxError::NewInstance, "None", py::arg("theMessage"));
cls_ExprIntrp_SyntaxError.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_SyntaxError::get_type_name, "None");
cls_ExprIntrp_SyntaxError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_SyntaxError::get_type_descriptor, "None");
cls_ExprIntrp_SyntaxError.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_SyntaxError::*)() const) &ExprIntrp_SyntaxError::DynamicType, "None");

// Enums

}