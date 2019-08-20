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
#include <Standard_Handle.hxx>
#include <HeaderSection_Protocol.hxx>
#include <HeaderSection_FileName.hxx>
#include <HeaderSection_FileDescription.hxx>
#include <HeaderSection_FileSchema.hxx>
#include <HeaderSection_HeaderRecognizer.hxx>
#include <HeaderSection.hxx>

void bind_HeaderSection(py::module &mod){

py::class_<HeaderSection, std::unique_ptr<HeaderSection>> cls_HeaderSection(mod, "HeaderSection", "None");

// Constructors

// Fields

// Methods
// cls_HeaderSection.def_static("operator new_", (void * (*)(size_t)) &HeaderSection::operator new, "None", py::arg("theSize"));
// cls_HeaderSection.def_static("operator delete_", (void (*)(void *)) &HeaderSection::operator delete, "None", py::arg("theAddress"));
// cls_HeaderSection.def_static("operator new[]_", (void * (*)(size_t)) &HeaderSection::operator new[], "None", py::arg("theSize"));
// cls_HeaderSection.def_static("operator delete[]_", (void (*)(void *)) &HeaderSection::operator delete[], "None", py::arg("theAddress"));
// cls_HeaderSection.def_static("operator new_", (void * (*)(size_t, void *)) &HeaderSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HeaderSection.def_static("operator delete_", (void (*)(void *, void *)) &HeaderSection::operator delete, "None", py::arg(""), py::arg(""));
cls_HeaderSection.def_static("Protocol_", (opencascade::handle<HeaderSection_Protocol> (*)()) &HeaderSection::Protocol, "creates a Protocol");

// Enums

}