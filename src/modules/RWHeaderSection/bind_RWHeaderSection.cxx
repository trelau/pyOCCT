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
#include <RWHeaderSection_ReadWriteModule.hxx>
#include <RWHeaderSection_GeneralModule.hxx>
#include <RWHeaderSection_RWFileName.hxx>
#include <RWHeaderSection_RWFileDescription.hxx>
#include <RWHeaderSection_RWFileSchema.hxx>
#include <RWHeaderSection.hxx>

void bind_RWHeaderSection(py::module &mod){

py::class_<RWHeaderSection, std::unique_ptr<RWHeaderSection, Deleter<RWHeaderSection>>> cls_RWHeaderSection(mod, "RWHeaderSection", "None");

// Constructors

// Fields

// Methods
// cls_RWHeaderSection.def_static("operator new_", (void * (*)(size_t)) &RWHeaderSection::operator new, "None", py::arg("theSize"));
// cls_RWHeaderSection.def_static("operator delete_", (void (*)(void *)) &RWHeaderSection::operator delete, "None", py::arg("theAddress"));
// cls_RWHeaderSection.def_static("operator new[]_", (void * (*)(size_t)) &RWHeaderSection::operator new[], "None", py::arg("theSize"));
// cls_RWHeaderSection.def_static("operator delete[]_", (void (*)(void *)) &RWHeaderSection::operator delete[], "None", py::arg("theAddress"));
// cls_RWHeaderSection.def_static("operator new_", (void * (*)(size_t, void *)) &RWHeaderSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWHeaderSection.def_static("operator delete_", (void (*)(void *, void *)) &RWHeaderSection::operator delete, "None", py::arg(""), py::arg(""));
cls_RWHeaderSection.def_static("Init_", (void (*)()) &RWHeaderSection::Init, "enforced the initialisation of the libraries");

// Enums

}