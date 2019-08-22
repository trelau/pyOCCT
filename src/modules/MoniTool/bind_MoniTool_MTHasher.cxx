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
#include <MoniTool_MTHasher.hxx>

void bind_MoniTool_MTHasher(py::module &mod){

py::class_<MoniTool_MTHasher> cls_MoniTool_MTHasher(mod, "MoniTool_MTHasher", "The auxiliary class provides hash code for mapping objects");

// Constructors

// Fields

// Methods
// cls_MoniTool_MTHasher.def_static("operator new_", (void * (*)(size_t)) &MoniTool_MTHasher::operator new, "None", py::arg("theSize"));
// cls_MoniTool_MTHasher.def_static("operator delete_", (void (*)(void *)) &MoniTool_MTHasher::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_MTHasher.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_MTHasher::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_MTHasher.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_MTHasher::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_MTHasher.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_MTHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_MTHasher.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_MTHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_MoniTool_MTHasher.def_static("HashCode_", (Standard_Integer (*)(const Standard_CString, const Standard_Integer)) &MoniTool_MTHasher::HashCode, "Returns a HasCode value for the CString <Str> in the range 0..Upper. Default ::HashCode(Str,Upper)", py::arg("Str"), py::arg("Upper"));
cls_MoniTool_MTHasher.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_CString, const Standard_CString)) &MoniTool_MTHasher::IsEqual, "Returns True when the two CString are the same. Two same strings must have the same hashcode, the contrary is not necessary. Default Str1 == Str2", py::arg("Str1"), py::arg("Str2"));

// Enums

}