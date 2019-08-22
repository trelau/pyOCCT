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
#include <TCollection_AsciiString.hxx>
#include <OSD_WhoAmI.hxx>
#include <OSD_Error.hxx>

void bind_OSD_Error(py::module &mod){

py::class_<OSD_Error> cls_OSD_Error(mod, "OSD_Error", "Accurate management of OSD specific errors.");

// Constructors
cls_OSD_Error.def(py::init<>());

// Fields

// Methods
// cls_OSD_Error.def_static("operator new_", (void * (*)(size_t)) &OSD_Error::operator new, "None", py::arg("theSize"));
// cls_OSD_Error.def_static("operator delete_", (void (*)(void *)) &OSD_Error::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Error.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Error::operator new[], "None", py::arg("theSize"));
// cls_OSD_Error.def_static("operator delete[]_", (void (*)(void *)) &OSD_Error::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Error.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Error::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Error.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Error::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Error.def("Perror", (void (OSD_Error::*)()) &OSD_Error::Perror, "Raises OSD_Error with accurate error message.");
cls_OSD_Error.def("SetValue", (void (OSD_Error::*)(const Standard_Integer, const Standard_Integer, const TCollection_AsciiString &)) &OSD_Error::SetValue, "Instantiates error This is only used by OSD methods to instantiates an error code. No description is done for the programmer.", py::arg("Errcode"), py::arg("From"), py::arg("Message"));
cls_OSD_Error.def("Error", (Standard_Integer (OSD_Error::*)() const) &OSD_Error::Error, "Returns an accurate error code. To test these values, you must include 'OSD_ErrorList.hxx'");
cls_OSD_Error.def("Failed", (Standard_Boolean (OSD_Error::*)() const) &OSD_Error::Failed, "Returns TRUE if an error occurs This is a way to test if a system call succeeded or not.");
cls_OSD_Error.def("Reset", (void (OSD_Error::*)()) &OSD_Error::Reset, "Resets error counter to zero This allows the user to ignore an error (WARNING).");

// Enums

}