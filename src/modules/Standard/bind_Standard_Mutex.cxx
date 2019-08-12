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
#include <Standard_Mutex.hxx>
#include <Standard_TypeDef.hxx>

void bind_Standard_Mutex(py::module &mod){

py::class_<Standard_Mutex, std::unique_ptr<Standard_Mutex, Deleter<Standard_Mutex>>> cls_Standard_Mutex(mod, "Standard_Mutex", "Mutex: a class to synchronize access to shared data.");

// Constructors
cls_Standard_Mutex.def(py::init<>());

// Fields

// Methods
cls_Standard_Mutex.def("Lock", (void (Standard_Mutex::*)()) &Standard_Mutex::Lock, "Method to lock the mutex; waits until the mutex is released by other threads, locks it and then returns");
cls_Standard_Mutex.def("TryLock", (Standard_Boolean (Standard_Mutex::*)()) &Standard_Mutex::TryLock, "Method to test the mutex; if the mutex is not hold by other thread, locks it and returns True; otherwise returns False without waiting mutex to be released.");
cls_Standard_Mutex.def("Unlock", (void (Standard_Mutex::*)()) &Standard_Mutex::Unlock, "Method to unlock the mutex; releases it to other users");

// Enums

}