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
#include <Standard_Transient.hxx>
#include <Standard_Failure.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_Standard_Failure(py::module &mod){

py::class_<Standard_Failure, opencascade::handle<Standard_Failure>, Standard_Transient> cls_Standard_Failure(mod, "Standard_Failure", "Forms the root of the entire exception hierarchy.");

// Constructors
cls_Standard_Failure.def(py::init<>());
cls_Standard_Failure.def(py::init<const Standard_Failure &>(), py::arg("f"));
cls_Standard_Failure.def(py::init<const Standard_CString>(), py::arg("aString"));

// Fields

// Methods
// cls_Standard_Failure.def("operator=", (Standard_Failure & (Standard_Failure::*)(const Standard_Failure &)) &Standard_Failure::operator=, "Assignment operator", py::arg("f"));
cls_Standard_Failure.def("Print", (void (Standard_Failure::*)(Standard_OStream &) const) &Standard_Failure::Print, "Prints on the stream the exception name followed by the error message. Level: Advanced Warning: The operator 'OStream& operator<< (Standard_OStream&, Handle(Standard_Failure)&)' is implemented. (This operator uses the method Print)", py::arg("s"));
cls_Standard_Failure.def("GetMessageString", (Standard_CString (Standard_Failure::*)() const) &Standard_Failure::GetMessageString, "Returns error message");
cls_Standard_Failure.def("SetMessageString", (void (Standard_Failure::*)(const Standard_CString)) &Standard_Failure::SetMessageString, "Sets error message", py::arg("aMessage"));
cls_Standard_Failure.def("Reraise", (void (Standard_Failure::*)()) &Standard_Failure::Reraise, "None");
cls_Standard_Failure.def("Reraise", (void (Standard_Failure::*)(const Standard_CString)) &Standard_Failure::Reraise, "None", py::arg("aMessage"));
cls_Standard_Failure.def("Reraise", (void (Standard_Failure::*)(const Standard_SStream &)) &Standard_Failure::Reraise, "Reraises a caught exception and changes its error message.", py::arg("aReason"));
cls_Standard_Failure.def_static("Raise_", []() -> void { return Standard_Failure::Raise(); });
cls_Standard_Failure.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_Failure::Raise, "Raises an exception of type 'Failure' and associates an error message to it. The message can be printed in an exception handler.", py::arg("aMessage"));
cls_Standard_Failure.def_static("Raise_", (void (*)(const Standard_SStream &)) &Standard_Failure::Raise, "Raises an exception of type 'Failure' and associates an error message to it. The message can be constructed at run-time.", py::arg("aReason"));
cls_Standard_Failure.def_static("NewInstance_", (opencascade::handle<Standard_Failure> (*)(const Standard_CString)) &Standard_Failure::NewInstance, "Used to construct an instance of the exception object as a handle. Shall be used to protect against possible construction of exception object in C stack -- that is dangerous since some of methods require that object was allocated dynamically.", py::arg("aMessage"));
cls_Standard_Failure.def("Jump", (void (Standard_Failure::*)()) &Standard_Failure::Jump, "Used to throw CASCADE exception from C signal handler. On platforms that do not allow throwing C++ exceptions from this handler (e.g. Linux), uses longjump to get to the current active signal handler, and only then is converted to C++ exception.");
cls_Standard_Failure.def_static("Caught_", (opencascade::handle<Standard_Failure> (*)()) &Standard_Failure::Caught, "Returns the last caught exception. Needed when exceptions are emulated by C longjumps, in other cases is also provided for compatibility.");
cls_Standard_Failure.def_static("get_type_name_", (const char * (*)()) &Standard_Failure::get_type_name, "None");
cls_Standard_Failure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_Failure::get_type_descriptor, "None");
cls_Standard_Failure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_Failure::*)() const) &Standard_Failure::DynamicType, "None");

// Enums

}