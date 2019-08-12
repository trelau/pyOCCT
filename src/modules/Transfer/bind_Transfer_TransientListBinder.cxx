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
#include <TColStd_HSequenceOfTransient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <Standard_Transient.hxx>
#include <Transfer_TransientListBinder.hxx>

void bind_Transfer_TransientListBinder(py::module &mod){

py::class_<Transfer_TransientListBinder, opencascade::handle<Transfer_TransientListBinder>, Transfer_Binder> cls_Transfer_TransientListBinder(mod, "Transfer_TransientListBinder", "This binder binds several (a list of) Transients with a starting entity, when this entity itself corresponds to a simple list of Transients. Each part is not seen as a sub-result of an independant componant, but as an item of a built-in list");

// Constructors
cls_Transfer_TransientListBinder.def(py::init<>());
cls_Transfer_TransientListBinder.def(py::init<const opencascade::handle<TColStd_HSequenceOfTransient> &>(), py::arg("list"));

// Fields

// Methods
cls_Transfer_TransientListBinder.def("IsMultiple", (Standard_Boolean (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::IsMultiple, "None");
cls_Transfer_TransientListBinder.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::ResultType, "None");
cls_Transfer_TransientListBinder.def("ResultTypeName", (Standard_CString (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::ResultTypeName, "None");
cls_Transfer_TransientListBinder.def("AddResult", (void (Transfer_TransientListBinder::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_TransientListBinder::AddResult, "Adds an item to the result list", py::arg("res"));
cls_Transfer_TransientListBinder.def("Result", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::Result, "None");
cls_Transfer_TransientListBinder.def("SetResult", (void (Transfer_TransientListBinder::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &Transfer_TransientListBinder::SetResult, "Changes an already defined sub-result", py::arg("num"), py::arg("res"));
cls_Transfer_TransientListBinder.def("NbTransients", (Standard_Integer (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::NbTransients, "None");
cls_Transfer_TransientListBinder.def("Transient", (const opencascade::handle<Standard_Transient> & (Transfer_TransientListBinder::*)(const Standard_Integer) const) &Transfer_TransientListBinder::Transient, "None", py::arg("num"));
cls_Transfer_TransientListBinder.def_static("get_type_name_", (const char * (*)()) &Transfer_TransientListBinder::get_type_name, "None");
cls_Transfer_TransientListBinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_TransientListBinder::get_type_descriptor, "None");
cls_Transfer_TransientListBinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::DynamicType, "None");

// Enums

}