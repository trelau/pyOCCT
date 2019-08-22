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
#include <Standard_PCharacter.hxx>
#include <OSD.hxx>

void bind_OSD(py::module &mod){

py::class_<OSD> cls_OSD(mod, "OSD", "Set of Operating Sytem Dependent Tools (O)perating (S)ystem (D)ependent");

// Constructors

// Fields

// Methods
// cls_OSD.def_static("operator new_", (void * (*)(size_t)) &OSD::operator new, "None", py::arg("theSize"));
// cls_OSD.def_static("operator delete_", (void (*)(void *)) &OSD::operator delete, "None", py::arg("theAddress"));
// cls_OSD.def_static("operator new[]_", (void * (*)(size_t)) &OSD::operator new[], "None", py::arg("theSize"));
// cls_OSD.def_static("operator delete[]_", (void (*)(void *)) &OSD::operator delete[], "None", py::arg("theAddress"));
// cls_OSD.def_static("operator new_", (void * (*)(size_t, void *)) &OSD::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD.def_static("operator delete_", (void (*)(void *, void *)) &OSD::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD.def_static("SetSignal_", []() -> void { return OSD::SetSignal(); });
cls_OSD.def_static("SetSignal_", (void (*)(const Standard_Boolean)) &OSD::SetSignal, "Sets signal and exception handlers.", py::arg("theFloatingSignal"));
cls_OSD.def_static("SecSleep_", (void (*)(const Standard_Integer)) &OSD::SecSleep, "Commands the process to sleep for a number of seconds.", py::arg("aDelay"));
cls_OSD.def_static("MilliSecSleep_", (void (*)(const Standard_Integer)) &OSD::MilliSecSleep, "Commands the process to sleep for a number of milliseconds", py::arg("aDelay"));
// cls_OSD.def_static("RealToCString_", (Standard_Boolean (*)(const Standard_Real, Standard_PCharacter &)) &OSD::RealToCString, "Converts aReal into aCstring in exponential format with a period as decimal point, no thousand separator and no grouping of digits. The conversion is independant from the current locale", py::arg("aReal"), py::arg("aString"));
cls_OSD.def_static("CStringToReal_", [](const Standard_CString aString, Standard_Real & aReal){ Standard_Boolean rv = OSD::CStringToReal(aString, aReal); return std::tuple<Standard_Boolean, Standard_Real &>(rv, aReal); }, "Converts aCstring representing a real with a period as decimal point, no thousand separator and no grouping of digits into aReal . The conversion is independant from the current locale.", py::arg("aString"), py::arg("aReal"));
cls_OSD.def_static("ControlBreak_", (void (*)()) &OSD::ControlBreak, "since Windows NT does not support 'SIGINT' signal like UNIX, then this method checks whether Ctrl-Break keystroke was or not. If yes then raises Exception_CTRL_BREAK.");

// Enums

}