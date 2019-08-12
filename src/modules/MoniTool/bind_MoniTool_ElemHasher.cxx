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
#include <MoniTool_Element.hxx>
#include <MoniTool_ElemHasher.hxx>

void bind_MoniTool_ElemHasher(py::module &mod){

py::class_<MoniTool_ElemHasher, std::unique_ptr<MoniTool_ElemHasher, Deleter<MoniTool_ElemHasher>>> cls_MoniTool_ElemHasher(mod, "MoniTool_ElemHasher", "ElemHasher defines HashCode for Element, which is : ask a Element its HashCode ! Because this is the Element itself which brings the HashCode for its Key");

// Constructors

// Fields

// Methods
// cls_MoniTool_ElemHasher.def_static("operator new_", (void * (*)(size_t)) &MoniTool_ElemHasher::operator new, "None", py::arg("theSize"));
// cls_MoniTool_ElemHasher.def_static("operator delete_", (void (*)(void *)) &MoniTool_ElemHasher::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_ElemHasher.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_ElemHasher::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_ElemHasher.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_ElemHasher::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_ElemHasher.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_ElemHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_ElemHasher.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_ElemHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_MoniTool_ElemHasher.def_static("HashCode_", (Standard_Integer (*)(const opencascade::handle<MoniTool_Element> &, const Standard_Integer)) &MoniTool_ElemHasher::HashCode, "Returns a HashCode in the range <0,Upper> for a Element : asks the Element its HashCode then transforms it to be in the required range", py::arg("K"), py::arg("Upper"));
cls_MoniTool_ElemHasher.def_static("IsEqual_", (Standard_Boolean (*)(const opencascade::handle<MoniTool_Element> &, const opencascade::handle<MoniTool_Element> &)) &MoniTool_ElemHasher::IsEqual, "Returns True if two keys are the same. The test does not work on the Elements themselves but by calling their methods Equates", py::arg("K1"), py::arg("K2"));

// Enums

}