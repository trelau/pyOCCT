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
#include <Standard_ErrorHandler.hxx>

void bind_Standard_ErrorHandlerCallback(py::module &mod){

/*
py::class_<Standard_ErrorHandler::Callback, std::unique_ptr<Standard_ErrorHandler::Callback>> cls_Standard_ErrorHandlerCallback(mod, "Standard_ErrorHandlerCallback", "Defines a base class for callback objects that can be registered in the OCC error handler (the class simulating C++ exceptions) so as to be correctly destroyed when error handler is activated.");

// Fields

// Methods
// cls_Standard_ErrorHandlerCallback.def_static("operator new_", (void * (*)(size_t)) &Standard_ErrorHandler::Callback::operator new, "None", py::arg("theSize"));
// cls_Standard_ErrorHandlerCallback.def_static("operator delete_", (void (*)(void *)) &Standard_ErrorHandler::Callback::operator delete, "None", py::arg("theAddress"));
// cls_Standard_ErrorHandlerCallback.def_static("operator new[]_", (void * (*)(size_t)) &Standard_ErrorHandler::Callback::operator new[], "None", py::arg("theSize"));
// cls_Standard_ErrorHandlerCallback.def_static("operator delete[]_", (void (*)(void *)) &Standard_ErrorHandler::Callback::operator delete[], "None", py::arg("theAddress"));
// cls_Standard_ErrorHandlerCallback.def_static("operator new_", (void * (*)(size_t, void *)) &Standard_ErrorHandler::Callback::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard_ErrorHandlerCallback.def_static("operator delete_", (void (*)(void *, void *)) &Standard_ErrorHandler::Callback::operator delete, "None", py::arg(""), py::arg(""));
cls_Standard_ErrorHandlerCallback.def("RegisterCallback", (void (Standard_ErrorHandler::Callback::*)()) &Standard_ErrorHandler::Callback::RegisterCallback, "Registers this callback object in the current error handler (if found).");
cls_Standard_ErrorHandlerCallback.def("UnregisterCallback", (void (Standard_ErrorHandler::Callback::*)()) &Standard_ErrorHandler::Callback::UnregisterCallback, "Unregisters this callback object from the error handler.");
cls_Standard_ErrorHandlerCallback.def("DestroyCallback", (void (Standard_ErrorHandler::Callback::*)()) &Standard_ErrorHandler::Callback::DestroyCallback, "The callback function to perform necessary callback action. Called by the exception handler when it is being destroyed but still has this callback registered.");

// Enums
*/

}