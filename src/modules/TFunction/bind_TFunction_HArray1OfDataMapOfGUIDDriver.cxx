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
#include <TFunction_Array1OfDataMapOfGUIDDriver.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TFunction_HArray1OfDataMapOfGUIDDriver.hxx>
#include <Standard_Type.hxx>

void bind_TFunction_HArray1OfDataMapOfGUIDDriver(py::module &mod){

py::class_<TFunction_HArray1OfDataMapOfGUIDDriver, opencascade::handle<TFunction_HArray1OfDataMapOfGUIDDriver>, Standard_Transient> cls_TFunction_HArray1OfDataMapOfGUIDDriver(mod, "TFunction_HArray1OfDataMapOfGUIDDriver", "None", py::multiple_inheritance());

// Constructors
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def(py::init<const Standard_Integer, const Standard_Integer, const TFunction_Array1OfDataMapOfGUIDDriver::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def(py::init<const TFunction_Array1OfDataMapOfGUIDDriver &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator new_", (void * (*)(size_t)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator new, "None", py::arg("theSize"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator delete_", (void (*)(void *)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator delete, "None", py::arg("theAddress"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator new[]_", (void * (*)(size_t)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator new[], "None", py::arg("theSize"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator delete[]_", (void (*)(void *)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator delete[], "None", py::arg("theAddress"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator new_", (void * (*)(size_t, void *)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator delete_", (void (*)(void *, void *)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator delete, "None", py::arg(""), py::arg(""));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def("Array1", (const TFunction_Array1OfDataMapOfGUIDDriver & (TFunction_HArray1OfDataMapOfGUIDDriver::*)() const) &TFunction_HArray1OfDataMapOfGUIDDriver::Array1, "None");
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def("ChangeArray1", (TFunction_Array1OfDataMapOfGUIDDriver & (TFunction_HArray1OfDataMapOfGUIDDriver::*)()) &TFunction_HArray1OfDataMapOfGUIDDriver::ChangeArray1, "None");
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("get_type_name_", (const char * (*)()) &TFunction_HArray1OfDataMapOfGUIDDriver::get_type_name, "None");
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_HArray1OfDataMapOfGUIDDriver::get_type_descriptor, "None");
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_HArray1OfDataMapOfGUIDDriver::*)() const) &TFunction_HArray1OfDataMapOfGUIDDriver::DynamicType, "None");

// Enums

}