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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Transfer_MultipleBinder.hxx>

void bind_Transfer_MultipleBinder(py::module &mod){

py::class_<Transfer_MultipleBinder, opencascade::handle<Transfer_MultipleBinder>, Transfer_Binder> cls_Transfer_MultipleBinder(mod, "Transfer_MultipleBinder", "Allows direct binding between a starting Object and the Result of its transfer, when it can be made of several Transient Objects. Compared to a Transcriptor, it has no Transfer Action");

// Constructors
cls_Transfer_MultipleBinder.def(py::init<>());

// Fields

// Methods
cls_Transfer_MultipleBinder.def("IsMultiple", (Standard_Boolean (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::IsMultiple, "Returns True if a starting object is bound with SEVERAL results : Here, returns allways True");
cls_Transfer_MultipleBinder.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::ResultType, "Returns the Type permitted for Results, i.e. here Transient");
cls_Transfer_MultipleBinder.def("ResultTypeName", (Standard_CString (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::ResultTypeName, "Returns the Name of the Type which characterizes the Result Here, returns '(list)'");
cls_Transfer_MultipleBinder.def("AddResult", (void (Transfer_MultipleBinder::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_MultipleBinder::AddResult, "Adds a new Item to the Multiple Result", py::arg("res"));
cls_Transfer_MultipleBinder.def("NbResults", (Standard_Integer (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::NbResults, "Returns the actual count of recorded (Transient) results");
cls_Transfer_MultipleBinder.def("ResultValue", (opencascade::handle<Standard_Transient> (Transfer_MultipleBinder::*)(const Standard_Integer) const) &Transfer_MultipleBinder::ResultValue, "Returns the value of the recorded result n0 <num>", py::arg("num"));
cls_Transfer_MultipleBinder.def("MultipleResult", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::MultipleResult, "Returns the Multiple Result, if it is defined (at least one Item). Else, returns a Null Handle");
cls_Transfer_MultipleBinder.def("SetMultipleResult", (void (Transfer_MultipleBinder::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &Transfer_MultipleBinder::SetMultipleResult, "Defines a Binding with a Multiple Result, given as a Sequence Error if a Unique Result has yet been defined", py::arg("mulres"));
cls_Transfer_MultipleBinder.def_static("get_type_name_", (const char * (*)()) &Transfer_MultipleBinder::get_type_name, "None");
cls_Transfer_MultipleBinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_MultipleBinder::get_type_descriptor, "None");
cls_Transfer_MultipleBinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::DynamicType, "None");

// Enums

}