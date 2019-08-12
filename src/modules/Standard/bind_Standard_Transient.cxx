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
#include <Standard.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_Standard_Transient(py::module &mod){

py::class_<Standard_Transient, opencascade::handle<Standard_Transient>> cls_Standard_Transient(mod, "Standard_Transient", "Abstract class which forms the root of the entire Transient class hierarchy.");

// Constructors
cls_Standard_Transient.def(py::init<>());
cls_Standard_Transient.def(py::init<const Standard_Transient &>(), py::arg(""));

// Fields

// Methods
// cls_Standard_Transient.def_static("operator new_", (void * (*)(size_t)) &Standard_Transient::operator new, "None", py::arg("theSize"));
// cls_Standard_Transient.def_static("operator delete_", (void (*)(void *)) &Standard_Transient::operator delete, "None", py::arg("theAddress"));
// cls_Standard_Transient.def_static("operator new[]_", (void * (*)(size_t)) &Standard_Transient::operator new[], "None", py::arg("theSize"));
// cls_Standard_Transient.def_static("operator delete[]_", (void (*)(void *)) &Standard_Transient::operator delete[], "None", py::arg("theAddress"));
// cls_Standard_Transient.def_static("operator new_", (void * (*)(size_t, void *)) &Standard_Transient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard_Transient.def_static("operator delete_", (void (*)(void *, void *)) &Standard_Transient::operator delete, "None", py::arg(""), py::arg(""));
// cls_Standard_Transient.def("operator=", (Standard_Transient & (Standard_Transient::*)(const Standard_Transient &)) &Standard_Transient::operator=, "Assignment operator, needed to avoid copying reference counter", py::arg(""));
cls_Standard_Transient.def("Delete", (void (Standard_Transient::*)() const) &Standard_Transient::Delete, "Memory deallocator for transient classes");
cls_Standard_Transient.def_static("get_type_name_", (const char * (*)()) &Standard_Transient::get_type_name, "None");
cls_Standard_Transient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_Transient::get_type_descriptor, "Returns type descriptor of Standard_Transient class");
cls_Standard_Transient.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_Transient::*)() const) &Standard_Transient::DynamicType, "Returns a type descriptor about this object.");
cls_Standard_Transient.def("IsInstance", (Standard_Boolean (Standard_Transient::*)(const opencascade::handle<Standard_Type> &) const) &Standard_Transient::IsInstance, "Returns a true value if this is an instance of Type.", py::arg("theType"));
cls_Standard_Transient.def("IsInstance", (Standard_Boolean (Standard_Transient::*)(const Standard_CString) const) &Standard_Transient::IsInstance, "Returns a true value if this is an instance of TypeName.", py::arg("theTypeName"));
cls_Standard_Transient.def("IsKind", (Standard_Boolean (Standard_Transient::*)(const opencascade::handle<Standard_Type> &) const) &Standard_Transient::IsKind, "Returns true if this is an instance of Type or an instance of any class that inherits from Type. Note that multiple inheritance is not supported by OCCT RTTI mechanism.", py::arg("theType"));
cls_Standard_Transient.def("IsKind", (Standard_Boolean (Standard_Transient::*)(const Standard_CString) const) &Standard_Transient::IsKind, "Returns true if this is an instance of TypeName or an instance of any class that inherits from TypeName. Note that multiple inheritance is not supported by OCCT RTTI mechanism.", py::arg("theTypeName"));
cls_Standard_Transient.def("This", (Standard_Transient * (Standard_Transient::*)() const) &Standard_Transient::This, "Returns non-const pointer to this object (like const_cast). For protection against creating handle to objects allocated in stack or call from constructor, it will raise exception Standard_ProgramError if reference counter is zero.");
cls_Standard_Transient.def("GetRefCount", (Standard_Integer (Standard_Transient::*)() const) &Standard_Transient::GetRefCount, "Get the reference counter of this object");
cls_Standard_Transient.def("IncrementRefCounter", (void (Standard_Transient::*)() const) &Standard_Transient::IncrementRefCounter, "Increments the reference counter of this object");
cls_Standard_Transient.def("DecrementRefCounter", (Standard_Integer (Standard_Transient::*)() const) &Standard_Transient::DecrementRefCounter, "Decrements the reference counter of this object; returns the decremented value");

// Enums

}