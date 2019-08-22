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
#include <MoniTool_Timer.hxx>
#include <MoniTool_TimerSentry.hxx>

void bind_MoniTool_TimerSentry(py::module &mod){

py::class_<MoniTool_TimerSentry> cls_MoniTool_TimerSentry(mod, "MoniTool_TimerSentry", "A tool to facilitate using MoniTool_Timer functionality by automatically ensuring consistency of start/stop actions");

// Constructors
cls_MoniTool_TimerSentry.def(py::init<const Standard_CString>(), py::arg("cname"));
cls_MoniTool_TimerSentry.def(py::init<const opencascade::handle<MoniTool_Timer> &>(), py::arg("timer"));

// Fields

// Methods
// cls_MoniTool_TimerSentry.def_static("operator new_", (void * (*)(size_t)) &MoniTool_TimerSentry::operator new, "None", py::arg("theSize"));
// cls_MoniTool_TimerSentry.def_static("operator delete_", (void (*)(void *)) &MoniTool_TimerSentry::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_TimerSentry.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_TimerSentry::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_TimerSentry.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_TimerSentry::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_TimerSentry.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_TimerSentry::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_TimerSentry.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_TimerSentry::operator delete, "None", py::arg(""), py::arg(""));
cls_MoniTool_TimerSentry.def("Timer", (opencascade::handle<MoniTool_Timer> (MoniTool_TimerSentry::*)() const) &MoniTool_TimerSentry::Timer, "None");
cls_MoniTool_TimerSentry.def("Stop", (void (MoniTool_TimerSentry::*)()) &MoniTool_TimerSentry::Stop, "Manually stops the timer");

// Enums

}