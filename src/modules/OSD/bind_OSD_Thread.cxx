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
#include <OSD_ThreadFunction.hxx>
#include <OSD_Thread.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_ThreadId.hxx>
#include <OSD_PThread.hxx>

void bind_OSD_Thread(py::module &mod){

py::class_<OSD_Thread> cls_OSD_Thread(mod, "OSD_Thread", "A simple platform-intependent interface to execute and control threads.");

// Constructors
cls_OSD_Thread.def(py::init<>());
cls_OSD_Thread.def(py::init<const OSD_ThreadFunction &>(), py::arg("func"));
cls_OSD_Thread.def(py::init<const OSD_Thread &>(), py::arg("other"));

// Fields

// Methods
// cls_OSD_Thread.def_static("operator new_", (void * (*)(size_t)) &OSD_Thread::operator new, "None", py::arg("theSize"));
// cls_OSD_Thread.def_static("operator delete_", (void (*)(void *)) &OSD_Thread::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Thread.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Thread::operator new[], "None", py::arg("theSize"));
// cls_OSD_Thread.def_static("operator delete[]_", (void (*)(void *)) &OSD_Thread::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Thread.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Thread::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Thread.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Thread::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Thread.def("Assign", (void (OSD_Thread::*)(const OSD_Thread &)) &OSD_Thread::Assign, "Copy thread handle from other OSD_Thread object.", py::arg("other"));
// cls_OSD_Thread.def("operator=", (void (OSD_Thread::*)(const OSD_Thread &)) &OSD_Thread::operator=, "None", py::arg("other"));
cls_OSD_Thread.def("SetPriority", (void (OSD_Thread::*)(const Standard_Integer)) &OSD_Thread::SetPriority, "None", py::arg("thePriority"));
cls_OSD_Thread.def("SetFunction", (void (OSD_Thread::*)(const OSD_ThreadFunction &)) &OSD_Thread::SetFunction, "Initialize the tool by the thread function. If the current thread handle is not null, nullifies it.", py::arg("func"));
cls_OSD_Thread.def("Run", [](OSD_Thread &self) -> Standard_Boolean { return self.Run(); });
cls_OSD_Thread.def("Run", [](OSD_Thread &self, const Standard_Address a0) -> Standard_Boolean { return self.Run(a0); });
cls_OSD_Thread.def("Run", (Standard_Boolean (OSD_Thread::*)(const Standard_Address, const Standard_Integer)) &OSD_Thread::Run, "Starts a thread with thread function given in constructor, passing the specified input data (as void *) to it. The parameter WNTStackSize (on Windows only) specifies size of the stack to be allocated for the thread (by default - the same as for the current executable). Returns True if thread started successfully", py::arg("data"), py::arg("WNTStackSize"));
cls_OSD_Thread.def("Detach", (void (OSD_Thread::*)()) &OSD_Thread::Detach, "Detaches the execution thread from this Thread object, so that it cannot be waited. Note that mechanics of this operation is different on UNIX/Linux (the thread is put to detached state) and Windows (the handle is closed). However, the purpose is the same: to instruct the system to release all thread data upon its completion.");
cls_OSD_Thread.def("Wait", (Standard_Boolean (OSD_Thread::*)()) &OSD_Thread::Wait, "Waits till the thread finishes execution.");
cls_OSD_Thread.def("Wait", (Standard_Boolean (OSD_Thread::*)(Standard_Address &)) &OSD_Thread::Wait, "Wait till the thread finishes execution. Returns True if wait was successful, False in case of error.", py::arg("theResult"));
cls_OSD_Thread.def("Wait", (Standard_Boolean (OSD_Thread::*)(const Standard_Integer, Standard_Address &)) &OSD_Thread::Wait, "Waits for some time and if the thread is finished, it returns the result. The function returns false if the thread is not finished yet.", py::arg("time"), py::arg("theResult"));
cls_OSD_Thread.def("GetId", (Standard_ThreadId (OSD_Thread::*)() const) &OSD_Thread::GetId, "Returns ID of the currently controlled thread ID, or 0 if no thread is run");
cls_OSD_Thread.def_static("Current_", (Standard_ThreadId (*)()) &OSD_Thread::Current, "Auxiliary: returns ID of the current thread");

// Enums

}