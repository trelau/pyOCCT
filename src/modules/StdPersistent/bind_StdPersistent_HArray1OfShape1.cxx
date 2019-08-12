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
#include <NCollection_Array1.hxx>
#include <StdObject_Shape.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <StdPersistent_HArray1.hxx>
#include <Standard_Type.hxx>

void bind_StdPersistent_HArray1OfShape1(py::module &mod){

py::class_<StdPersistent_HArray1OfShape1, opencascade::handle<StdPersistent_HArray1OfShape1>, Standard_Transient> cls_StdPersistent_HArray1OfShape1(mod, "StdPersistent_HArray1OfShape1", "None", py::multiple_inheritance());

// Constructors
cls_StdPersistent_HArray1OfShape1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StdPersistent_HArray1OfShape1.def(py::init<const Standard_Integer, const Standard_Integer, const NCollection_Array1<StdObject_Shape>::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StdPersistent_HArray1OfShape1.def(py::init<const NCollection_Array1<StdObject_Shape> &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StdPersistent_HArray1OfShape1.def_static("operator new_", (void * (*)(size_t)) &StdPersistent_HArray1OfShape1::operator new, "None", py::arg("theSize"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator delete_", (void (*)(void *)) &StdPersistent_HArray1OfShape1::operator delete, "None", py::arg("theAddress"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator new[]_", (void * (*)(size_t)) &StdPersistent_HArray1OfShape1::operator new[], "None", py::arg("theSize"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator delete[]_", (void (*)(void *)) &StdPersistent_HArray1OfShape1::operator delete[], "None", py::arg("theAddress"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator new_", (void * (*)(size_t, void *)) &StdPersistent_HArray1OfShape1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator delete_", (void (*)(void *, void *)) &StdPersistent_HArray1OfShape1::operator delete, "None", py::arg(""), py::arg(""));
// cls_StdPersistent_HArray1OfShape1.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StdPersistent_HArray1OfShape1::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StdPersistent_HArray1OfShape1.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StdPersistent_HArray1OfShape1::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StdPersistent_HArray1OfShape1.def("Array1", (const NCollection_Array1<StdObject_Shape> & (StdPersistent_HArray1OfShape1::*)() const) &StdPersistent_HArray1OfShape1::Array1, "None");
cls_StdPersistent_HArray1OfShape1.def("ChangeArray1", (NCollection_Array1<StdObject_Shape> & (StdPersistent_HArray1OfShape1::*)()) &StdPersistent_HArray1OfShape1::ChangeArray1, "None");
cls_StdPersistent_HArray1OfShape1.def_static("get_type_name_", (const char * (*)()) &StdPersistent_HArray1OfShape1::get_type_name, "None");
cls_StdPersistent_HArray1OfShape1.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdPersistent_HArray1OfShape1::get_type_descriptor, "None");
cls_StdPersistent_HArray1OfShape1.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdPersistent_HArray1OfShape1::*)() const) &StdPersistent_HArray1OfShape1::DynamicType, "None");

// Enums

}