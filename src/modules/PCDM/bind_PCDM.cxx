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
#include <Storage_BaseDriver.hxx>
#include <PCDM_TypeOfFileDriver.hxx>
#include <TCollection_AsciiString.hxx>
#include <PCDM_BaseDriverPointer.hxx>
#include <Standard_IStream.hxx>
#include <Standard.hxx>
#include <PCDM.hxx>

void bind_PCDM(py::module &mod){

py::class_<PCDM> cls_PCDM(mod, "PCDM", "None");

// Constructors

// Fields

// Methods
// cls_PCDM.def_static("FileDriverType_", (PCDM_TypeOfFileDriver (*)(const TCollection_AsciiString &, PCDM_BaseDriverPointer &)) &PCDM::FileDriverType, "None", py::arg("aFileName"), py::arg("aBaseDriver"));
// cls_PCDM.def_static("FileDriverType_", (PCDM_TypeOfFileDriver (*)(Standard_IStream &, PCDM_BaseDriverPointer &)) &PCDM::FileDriverType, "None", py::arg("theIStream"), py::arg("theBaseDriver"));
// cls_PCDM.def_static("operator new_", (void * (*)(size_t)) &PCDM::operator new, "None", py::arg("theSize"));
// cls_PCDM.def_static("operator delete_", (void (*)(void *)) &PCDM::operator delete, "None", py::arg("theAddress"));
// cls_PCDM.def_static("operator new[]_", (void * (*)(size_t)) &PCDM::operator new[], "None", py::arg("theSize"));
// cls_PCDM.def_static("operator delete[]_", (void (*)(void *)) &PCDM::operator delete[], "None", py::arg("theAddress"));
// cls_PCDM.def_static("operator new_", (void * (*)(size_t, void *)) &PCDM::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_PCDM.def_static("operator delete_", (void (*)(void *, void *)) &PCDM::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}