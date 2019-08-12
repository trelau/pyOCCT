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
#include <Transfer_Binder.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Transfer_VoidBinder.hxx>

void bind_Transfer_VoidBinder(py::module &mod){

py::class_<Transfer_VoidBinder, opencascade::handle<Transfer_VoidBinder>, Transfer_Binder> cls_Transfer_VoidBinder(mod, "Transfer_VoidBinder", "a VoidBinder is used to bind a starting item with a status, error or warning messages, but no result It is interpreted by TransferProcess, which admits a VoidBinder to be over-written, and copies its check to the new Binder");

// Constructors
cls_Transfer_VoidBinder.def(py::init<>());

// Fields

// Methods
cls_Transfer_VoidBinder.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_VoidBinder::*)() const) &Transfer_VoidBinder::ResultType, "while a VoidBinder admits no Result, its ResultType returns the type of <me>");
cls_Transfer_VoidBinder.def("ResultTypeName", (Standard_CString (Transfer_VoidBinder::*)() const) &Transfer_VoidBinder::ResultTypeName, "Returns '(void)'");
cls_Transfer_VoidBinder.def_static("get_type_name_", (const char * (*)()) &Transfer_VoidBinder::get_type_name, "None");
cls_Transfer_VoidBinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_VoidBinder::get_type_descriptor, "None");
cls_Transfer_VoidBinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_VoidBinder::*)() const) &Transfer_VoidBinder::DynamicType, "None");

// Enums

}