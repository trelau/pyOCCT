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
#include <IGESData_IGESType.hxx>
#include <IGESData_DirPart.hxx>

void bind_IGESData_DirPart(py::module &mod){

py::class_<IGESData_DirPart, std::unique_ptr<IGESData_DirPart>> cls_IGESData_DirPart(mod, "IGESData_DirPart", "litteral/numeric description of an entity's directory section, taken from file");

// Constructors
cls_IGESData_DirPart.def(py::init<>());

// Fields

// Methods
// cls_IGESData_DirPart.def_static("operator new_", (void * (*)(size_t)) &IGESData_DirPart::operator new, "None", py::arg("theSize"));
// cls_IGESData_DirPart.def_static("operator delete_", (void (*)(void *)) &IGESData_DirPart::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_DirPart.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_DirPart::operator new[], "None", py::arg("theSize"));
// cls_IGESData_DirPart.def_static("operator delete[]_", (void (*)(void *)) &IGESData_DirPart::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_DirPart.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_DirPart::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_DirPart.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_DirPart::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_DirPart.def("Init", (void (IGESData_DirPart::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_CString, const Standard_CString, const Standard_CString, const Standard_CString)) &IGESData_DirPart::Init, "fills DirPart with consistant data read from file", py::arg("i1"), py::arg("i2"), py::arg("i3"), py::arg("i4"), py::arg("i5"), py::arg("i6"), py::arg("i7"), py::arg("i8"), py::arg("i9"), py::arg("i19"), py::arg("i11"), py::arg("i12"), py::arg("i13"), py::arg("i14"), py::arg("i15"), py::arg("i16"), py::arg("i17"), py::arg("res1"), py::arg("res2"), py::arg("label"), py::arg("subscript"));
cls_IGESData_DirPart.def("Values", [](IGESData_DirPart &self, Standard_Integer & i1, Standard_Integer & i2, Standard_Integer & i3, Standard_Integer & i4, Standard_Integer & i5, Standard_Integer & i6, Standard_Integer & i7, Standard_Integer & i8, Standard_Integer & i9, Standard_Integer & i19, Standard_Integer & i11, Standard_Integer & i12, Standard_Integer & i13, Standard_Integer & i14, Standard_Integer & i15, Standard_Integer & i16, Standard_Integer & i17, const Standard_CString res1, const Standard_CString res2, const Standard_CString label, const Standard_CString subscript){ self.Values(i1, i2, i3, i4, i5, i6, i7, i8, i9, i19, i11, i12, i13, i14, i15, i16, i17, res1, res2, label, subscript); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(i1, i2, i3, i4, i5, i6, i7, i8, i9, i19, i11, i12, i13, i14, i15, i16, i17); }, "returns values recorded in DirPart (content of cstrings are modified)", py::arg("i1"), py::arg("i2"), py::arg("i3"), py::arg("i4"), py::arg("i5"), py::arg("i6"), py::arg("i7"), py::arg("i8"), py::arg("i9"), py::arg("i19"), py::arg("i11"), py::arg("i12"), py::arg("i13"), py::arg("i14"), py::arg("i15"), py::arg("i16"), py::arg("i17"), py::arg("res1"), py::arg("res2"), py::arg("label"), py::arg("subscript"));
cls_IGESData_DirPart.def("Type", (IGESData_IGESType (IGESData_DirPart::*)() const) &IGESData_DirPart::Type, "returns 'type' and 'form' info, used to recognize the entity");

// Enums

}