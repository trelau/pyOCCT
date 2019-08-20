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
#include <OSD_Directory.hxx>
#include <OSD_Error.hxx>
#include <OSD_DirectoryIterator.hxx>

void bind_OSD_DirectoryIterator(py::module &mod){

py::class_<OSD_DirectoryIterator, std::unique_ptr<OSD_DirectoryIterator>> cls_OSD_DirectoryIterator(mod, "OSD_DirectoryIterator", "Manages a breadth-only search for sub-directories in the specified Path. There is no specific order of results.");

// Constructors
cls_OSD_DirectoryIterator.def(py::init<>());
cls_OSD_DirectoryIterator.def(py::init<const OSD_Path &, const TCollection_AsciiString &>(), py::arg("where"), py::arg("Mask"));

// Fields

// Methods
// cls_OSD_DirectoryIterator.def_static("operator new_", (void * (*)(size_t)) &OSD_DirectoryIterator::operator new, "None", py::arg("theSize"));
// cls_OSD_DirectoryIterator.def_static("operator delete_", (void (*)(void *)) &OSD_DirectoryIterator::operator delete, "None", py::arg("theAddress"));
// cls_OSD_DirectoryIterator.def_static("operator new[]_", (void * (*)(size_t)) &OSD_DirectoryIterator::operator new[], "None", py::arg("theSize"));
// cls_OSD_DirectoryIterator.def_static("operator delete[]_", (void (*)(void *)) &OSD_DirectoryIterator::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_DirectoryIterator.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_DirectoryIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_DirectoryIterator.def_static("operator delete_", (void (*)(void *, void *)) &OSD_DirectoryIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_DirectoryIterator.def("Destroy", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Destroy, "None");
cls_OSD_DirectoryIterator.def("Initialize", (void (OSD_DirectoryIterator::*)(const OSD_Path &, const TCollection_AsciiString &)) &OSD_DirectoryIterator::Initialize, "Initializes the current File Directory", py::arg("where"), py::arg("Mask"));
cls_OSD_DirectoryIterator.def("More", (Standard_Boolean (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::More, "Returns TRUE if other items are found while using the 'Tree' method.");
cls_OSD_DirectoryIterator.def("Next", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Next, "Sets the iterator to the next item. Returns the item value corresponding to the current position of the iterator.");
cls_OSD_DirectoryIterator.def("Values", (OSD_Directory (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Values, "Returns the next item found .");
cls_OSD_DirectoryIterator.def("Failed", (Standard_Boolean (OSD_DirectoryIterator::*)() const) &OSD_DirectoryIterator::Failed, "Returns TRUE if an error occurs");
cls_OSD_DirectoryIterator.def("Reset", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Reset, "Resets error counter to zero");
cls_OSD_DirectoryIterator.def("Perror", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Perror, "Raises OSD_Error");
cls_OSD_DirectoryIterator.def("Error", (Standard_Integer (OSD_DirectoryIterator::*)() const) &OSD_DirectoryIterator::Error, "Returns error number if 'Failed' is TRUE.");

// Enums

}