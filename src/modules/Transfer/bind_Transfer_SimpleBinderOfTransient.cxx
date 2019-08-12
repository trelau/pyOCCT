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
#include <Standard_Transient.hxx>
#include <Transfer_SimpleBinderOfTransient.hxx>

void bind_Transfer_SimpleBinderOfTransient(py::module &mod){

py::class_<Transfer_SimpleBinderOfTransient, opencascade::handle<Transfer_SimpleBinderOfTransient>, Transfer_Binder> cls_Transfer_SimpleBinderOfTransient(mod, "Transfer_SimpleBinderOfTransient", "An adapted instantiation of SimpleBinder for Transient Result, i.e. ResultType can be computed from the Result itself, instead of being static");

// Constructors
cls_Transfer_SimpleBinderOfTransient.def(py::init<>());

// Fields

// Methods
cls_Transfer_SimpleBinderOfTransient.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_SimpleBinderOfTransient::*)() const) &Transfer_SimpleBinderOfTransient::ResultType, "Returns the Effective (Dynamic) Type of the Result (Standard_Transient if no Result is defined)");
cls_Transfer_SimpleBinderOfTransient.def("ResultTypeName", (Standard_CString (Transfer_SimpleBinderOfTransient::*)() const) &Transfer_SimpleBinderOfTransient::ResultTypeName, "Returns the Effective Name of (Dynamic) Type of the Result (void) if no result is defined");
cls_Transfer_SimpleBinderOfTransient.def("SetResult", (void (Transfer_SimpleBinderOfTransient::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_SimpleBinderOfTransient::SetResult, "Defines the Result", py::arg("res"));
cls_Transfer_SimpleBinderOfTransient.def("Result", (const opencascade::handle<Standard_Transient> & (Transfer_SimpleBinderOfTransient::*)() const) &Transfer_SimpleBinderOfTransient::Result, "Returns the defined Result, if there is one");
cls_Transfer_SimpleBinderOfTransient.def_static("GetTypedResult_", (Standard_Boolean (*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &)) &Transfer_SimpleBinderOfTransient::GetTypedResult, "Returns a transient result according to its type (IsKind) i.e. the result itself if IsKind(atype), else searches in NextResult, until first found, then returns True If not found, returns False (res is NOT touched)", py::arg("bnd"), py::arg("atype"), py::arg("res"));
cls_Transfer_SimpleBinderOfTransient.def_static("get_type_name_", (const char * (*)()) &Transfer_SimpleBinderOfTransient::get_type_name, "None");
cls_Transfer_SimpleBinderOfTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_SimpleBinderOfTransient::get_type_descriptor, "None");
cls_Transfer_SimpleBinderOfTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_SimpleBinderOfTransient::*)() const) &Transfer_SimpleBinderOfTransient::DynamicType, "None");

// Enums

}