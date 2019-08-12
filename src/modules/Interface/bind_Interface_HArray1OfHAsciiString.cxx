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
#include <Interface_Array1OfHAsciiString.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <Standard_Type.hxx>

void bind_Interface_HArray1OfHAsciiString(py::module &mod){

py::class_<Interface_HArray1OfHAsciiString, opencascade::handle<Interface_HArray1OfHAsciiString>, Standard_Transient> cls_Interface_HArray1OfHAsciiString(mod, "Interface_HArray1OfHAsciiString", "None", py::multiple_inheritance());

// Constructors
cls_Interface_HArray1OfHAsciiString.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Interface_HArray1OfHAsciiString.def(py::init<const Standard_Integer, const Standard_Integer, const Interface_Array1OfHAsciiString::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Interface_HArray1OfHAsciiString.def(py::init<const Interface_Array1OfHAsciiString &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Interface_HArray1OfHAsciiString.def_static("operator new_", (void * (*)(size_t)) &Interface_HArray1OfHAsciiString::operator new, "None", py::arg("theSize"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator delete_", (void (*)(void *)) &Interface_HArray1OfHAsciiString::operator delete, "None", py::arg("theAddress"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator new[]_", (void * (*)(size_t)) &Interface_HArray1OfHAsciiString::operator new[], "None", py::arg("theSize"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator delete[]_", (void (*)(void *)) &Interface_HArray1OfHAsciiString::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_HArray1OfHAsciiString::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator delete_", (void (*)(void *, void *)) &Interface_HArray1OfHAsciiString::operator delete, "None", py::arg(""), py::arg(""));
// cls_Interface_HArray1OfHAsciiString.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Interface_HArray1OfHAsciiString::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Interface_HArray1OfHAsciiString::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Interface_HArray1OfHAsciiString.def("Array1", (const Interface_Array1OfHAsciiString & (Interface_HArray1OfHAsciiString::*)() const) &Interface_HArray1OfHAsciiString::Array1, "None");
cls_Interface_HArray1OfHAsciiString.def("ChangeArray1", (Interface_Array1OfHAsciiString & (Interface_HArray1OfHAsciiString::*)()) &Interface_HArray1OfHAsciiString::ChangeArray1, "None");
cls_Interface_HArray1OfHAsciiString.def_static("get_type_name_", (const char * (*)()) &Interface_HArray1OfHAsciiString::get_type_name, "None");
cls_Interface_HArray1OfHAsciiString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_HArray1OfHAsciiString::get_type_descriptor, "None");
cls_Interface_HArray1OfHAsciiString.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_HArray1OfHAsciiString::*)() const) &Interface_HArray1OfHAsciiString::DynamicType, "None");

// Enums

}