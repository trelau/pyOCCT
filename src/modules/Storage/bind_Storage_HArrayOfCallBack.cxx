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
#include <Storage_ArrayOfCallBack.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <Storage_HArrayOfCallBack.hxx>
#include <Standard_Type.hxx>

void bind_Storage_HArrayOfCallBack(py::module &mod){

py::class_<Storage_HArrayOfCallBack, opencascade::handle<Storage_HArrayOfCallBack>, Standard_Transient> cls_Storage_HArrayOfCallBack(mod, "Storage_HArrayOfCallBack", "None", py::multiple_inheritance());

// Constructors
cls_Storage_HArrayOfCallBack.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Storage_HArrayOfCallBack.def(py::init<const Standard_Integer, const Standard_Integer, const Storage_ArrayOfCallBack::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Storage_HArrayOfCallBack.def(py::init<const Storage_ArrayOfCallBack &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Storage_HArrayOfCallBack.def_static("operator new_", (void * (*)(size_t)) &Storage_HArrayOfCallBack::operator new, "None", py::arg("theSize"));
// cls_Storage_HArrayOfCallBack.def_static("operator delete_", (void (*)(void *)) &Storage_HArrayOfCallBack::operator delete, "None", py::arg("theAddress"));
// cls_Storage_HArrayOfCallBack.def_static("operator new[]_", (void * (*)(size_t)) &Storage_HArrayOfCallBack::operator new[], "None", py::arg("theSize"));
// cls_Storage_HArrayOfCallBack.def_static("operator delete[]_", (void (*)(void *)) &Storage_HArrayOfCallBack::operator delete[], "None", py::arg("theAddress"));
// cls_Storage_HArrayOfCallBack.def_static("operator new_", (void * (*)(size_t, void *)) &Storage_HArrayOfCallBack::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Storage_HArrayOfCallBack.def_static("operator delete_", (void (*)(void *, void *)) &Storage_HArrayOfCallBack::operator delete, "None", py::arg(""), py::arg(""));
// cls_Storage_HArrayOfCallBack.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Storage_HArrayOfCallBack::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Storage_HArrayOfCallBack.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Storage_HArrayOfCallBack::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Storage_HArrayOfCallBack.def("Array1", (const Storage_ArrayOfCallBack & (Storage_HArrayOfCallBack::*)() const) &Storage_HArrayOfCallBack::Array1, "None");
cls_Storage_HArrayOfCallBack.def("ChangeArray1", (Storage_ArrayOfCallBack & (Storage_HArrayOfCallBack::*)()) &Storage_HArrayOfCallBack::ChangeArray1, "None");
cls_Storage_HArrayOfCallBack.def_static("get_type_name_", (const char * (*)()) &Storage_HArrayOfCallBack::get_type_name, "None");
cls_Storage_HArrayOfCallBack.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_HArrayOfCallBack::get_type_descriptor, "None");
cls_Storage_HArrayOfCallBack.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_HArrayOfCallBack::*)() const) &Storage_HArrayOfCallBack::DynamicType, "None");

// Enums

}