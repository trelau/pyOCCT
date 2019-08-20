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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_JmpBuf.hxx>
#include <Standard_Failure.hxx>
#include <Standard_PErrorHandler.hxx>
#include <Standard_HandlerStatus.hxx>
#include <Standard_ErrorHandler.hxx>
#include <Standard_ThreadId.hxx>

void bind_Standard_ErrorHandler(py::module &mod){

py::class_<Standard_ErrorHandler, std::unique_ptr<Standard_ErrorHandler>> cls_Standard_ErrorHandler(mod, "Standard_ErrorHandler", "Class implementing mechanics of conversion of signals to exceptions.");

// Constructors
cls_Standard_ErrorHandler.def(py::init<>());

// Fields

// Methods
// cls_Standard_ErrorHandler.def_static("operator new_", (void * (*)(size_t)) &Standard_ErrorHandler::operator new, "None", py::arg("theSize"));
// cls_Standard_ErrorHandler.def_static("operator delete_", (void (*)(void *)) &Standard_ErrorHandler::operator delete, "None", py::arg("theAddress"));
// cls_Standard_ErrorHandler.def_static("operator new[]_", (void * (*)(size_t)) &Standard_ErrorHandler::operator new[], "None", py::arg("theSize"));
// cls_Standard_ErrorHandler.def_static("operator delete[]_", (void (*)(void *)) &Standard_ErrorHandler::operator delete[], "None", py::arg("theAddress"));
// cls_Standard_ErrorHandler.def_static("operator new_", (void * (*)(size_t, void *)) &Standard_ErrorHandler::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard_ErrorHandler.def_static("operator delete_", (void (*)(void *, void *)) &Standard_ErrorHandler::operator delete, "None", py::arg(""), py::arg(""));
cls_Standard_ErrorHandler.def("Destroy", (void (Standard_ErrorHandler::*)()) &Standard_ErrorHandler::Destroy, "Unlinks and checks if there is a raised exception.");
cls_Standard_ErrorHandler.def("Unlink", (void (Standard_ErrorHandler::*)()) &Standard_ErrorHandler::Unlink, "Removes handler from the handlers list");
cls_Standard_ErrorHandler.def("Catches", (Standard_Boolean (Standard_ErrorHandler::*)(const opencascade::handle<Standard_Type> &)) &Standard_ErrorHandler::Catches, "Returns 'True' if the caught exception has the same type or inherits from 'aType'", py::arg("aType"));
cls_Standard_ErrorHandler.def("Label", (Standard_JmpBuf & (Standard_ErrorHandler::*)()) &Standard_ErrorHandler::Label, "Returns label for jump");
cls_Standard_ErrorHandler.def("Error", (opencascade::handle<Standard_Failure> (Standard_ErrorHandler::*)() const) &Standard_ErrorHandler::Error, "Returns the current Error.");
cls_Standard_ErrorHandler.def_static("LastCaughtError_", (opencascade::handle<Standard_Failure> (*)()) &Standard_ErrorHandler::LastCaughtError, "Returns the caught exception.");
cls_Standard_ErrorHandler.def_static("IsInTryBlock_", (Standard_Boolean (*)()) &Standard_ErrorHandler::IsInTryBlock, "Test if the code is currently running in a try block");

// Enums

}