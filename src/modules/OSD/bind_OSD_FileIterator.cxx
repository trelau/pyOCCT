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
#include <OSD_Path.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_File.hxx>
#include <OSD_Error.hxx>
#include <OSD_FileIterator.hxx>

void bind_OSD_FileIterator(py::module &mod){

py::class_<OSD_FileIterator> cls_OSD_FileIterator(mod, "OSD_FileIterator", "Manages a breadth-only search for files in the specified Path. There is no specific order of results.");

// Constructors
cls_OSD_FileIterator.def(py::init<>());
cls_OSD_FileIterator.def(py::init<const OSD_Path &, const TCollection_AsciiString &>(), py::arg("where"), py::arg("Mask"));

// Fields

// Methods
// cls_OSD_FileIterator.def_static("operator new_", (void * (*)(size_t)) &OSD_FileIterator::operator new, "None", py::arg("theSize"));
// cls_OSD_FileIterator.def_static("operator delete_", (void (*)(void *)) &OSD_FileIterator::operator delete, "None", py::arg("theAddress"));
// cls_OSD_FileIterator.def_static("operator new[]_", (void * (*)(size_t)) &OSD_FileIterator::operator new[], "None", py::arg("theSize"));
// cls_OSD_FileIterator.def_static("operator delete[]_", (void (*)(void *)) &OSD_FileIterator::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_FileIterator.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_FileIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_FileIterator.def_static("operator delete_", (void (*)(void *, void *)) &OSD_FileIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_FileIterator.def("Destroy", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Destroy, "None");
cls_OSD_FileIterator.def("Initialize", (void (OSD_FileIterator::*)(const OSD_Path &, const TCollection_AsciiString &)) &OSD_FileIterator::Initialize, "Initializes the current File Iterator", py::arg("where"), py::arg("Mask"));
cls_OSD_FileIterator.def("More", (Standard_Boolean (OSD_FileIterator::*)()) &OSD_FileIterator::More, "Returns TRUE if there are other items using the 'Tree' method.");
cls_OSD_FileIterator.def("Next", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Next, "Sets the iterator to the next item. Returns the item value corresponding to the current position of the iterator.");
cls_OSD_FileIterator.def("Values", (OSD_File (OSD_FileIterator::*)()) &OSD_FileIterator::Values, "Returns the next file found .");
cls_OSD_FileIterator.def("Failed", (Standard_Boolean (OSD_FileIterator::*)() const) &OSD_FileIterator::Failed, "Returns TRUE if an error occurs");
cls_OSD_FileIterator.def("Reset", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Reset, "Resets error counter to zero");
cls_OSD_FileIterator.def("Perror", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Perror, "Raises OSD_Error");
cls_OSD_FileIterator.def("Error", (Standard_Integer (OSD_FileIterator::*)() const) &OSD_FileIterator::Error, "Returns error number if 'Failed' is TRUE.");

// Enums

}