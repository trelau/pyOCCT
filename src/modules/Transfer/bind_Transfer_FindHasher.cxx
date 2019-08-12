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
#include <Transfer_Finder.hxx>
#include <Transfer_FindHasher.hxx>

void bind_Transfer_FindHasher(py::module &mod){

py::class_<Transfer_FindHasher, std::unique_ptr<Transfer_FindHasher, Deleter<Transfer_FindHasher>>> cls_Transfer_FindHasher(mod, "Transfer_FindHasher", "FindHasher defines HashCode for Finder, which is : ask a Finder its HashCode ! Because this is the Finder itself which brings the HashCode for its Key");

// Constructors

// Fields

// Methods
// cls_Transfer_FindHasher.def_static("operator new_", (void * (*)(size_t)) &Transfer_FindHasher::operator new, "None", py::arg("theSize"));
// cls_Transfer_FindHasher.def_static("operator delete_", (void (*)(void *)) &Transfer_FindHasher::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_FindHasher.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_FindHasher::operator new[], "None", py::arg("theSize"));
// cls_Transfer_FindHasher.def_static("operator delete[]_", (void (*)(void *)) &Transfer_FindHasher::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_FindHasher.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_FindHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_FindHasher.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_FindHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_FindHasher.def_static("HashCode_", (Standard_Integer (*)(const opencascade::handle<Transfer_Finder> &, const Standard_Integer)) &Transfer_FindHasher::HashCode, "Returns a HashCode in the range <0,Upper> for a Finder : asks the Finder its HashCode then transforms it to be in the required range", py::arg("K"), py::arg("Upper"));
cls_Transfer_FindHasher.def_static("IsEqual_", (Standard_Boolean (*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_Finder> &)) &Transfer_FindHasher::IsEqual, "Returns True if two keys are the same. The test does not work on the Finders themselves but by calling their methods Equates", py::arg("K1"), py::arg("K2"));

// Enums

}