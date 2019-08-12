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
#include <MeshVS_Array1OfSequenceOfInteger.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <MeshVS_HArray1OfSequenceOfInteger.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_HArray1OfSequenceOfInteger(py::module &mod){

py::class_<MeshVS_HArray1OfSequenceOfInteger, opencascade::handle<MeshVS_HArray1OfSequenceOfInteger>, Standard_Transient> cls_MeshVS_HArray1OfSequenceOfInteger(mod, "MeshVS_HArray1OfSequenceOfInteger", "None", py::multiple_inheritance());

// Constructors
cls_MeshVS_HArray1OfSequenceOfInteger.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_MeshVS_HArray1OfSequenceOfInteger.def(py::init<const Standard_Integer, const Standard_Integer, const MeshVS_Array1OfSequenceOfInteger::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_MeshVS_HArray1OfSequenceOfInteger.def(py::init<const MeshVS_Array1OfSequenceOfInteger &>(), py::arg("theOther"));

// Fields

// Methods
// cls_MeshVS_HArray1OfSequenceOfInteger.def_static("operator new_", (void * (*)(size_t)) &MeshVS_HArray1OfSequenceOfInteger::operator new, "None", py::arg("theSize"));
// cls_MeshVS_HArray1OfSequenceOfInteger.def_static("operator delete_", (void (*)(void *)) &MeshVS_HArray1OfSequenceOfInteger::operator delete, "None", py::arg("theAddress"));
// cls_MeshVS_HArray1OfSequenceOfInteger.def_static("operator new[]_", (void * (*)(size_t)) &MeshVS_HArray1OfSequenceOfInteger::operator new[], "None", py::arg("theSize"));
// cls_MeshVS_HArray1OfSequenceOfInteger.def_static("operator delete[]_", (void (*)(void *)) &MeshVS_HArray1OfSequenceOfInteger::operator delete[], "None", py::arg("theAddress"));
// cls_MeshVS_HArray1OfSequenceOfInteger.def_static("operator new_", (void * (*)(size_t, void *)) &MeshVS_HArray1OfSequenceOfInteger::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MeshVS_HArray1OfSequenceOfInteger.def_static("operator delete_", (void (*)(void *, void *)) &MeshVS_HArray1OfSequenceOfInteger::operator delete, "None", py::arg(""), py::arg(""));
// cls_MeshVS_HArray1OfSequenceOfInteger.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_HArray1OfSequenceOfInteger::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_MeshVS_HArray1OfSequenceOfInteger.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_HArray1OfSequenceOfInteger::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_MeshVS_HArray1OfSequenceOfInteger.def("Array1", (const MeshVS_Array1OfSequenceOfInteger & (MeshVS_HArray1OfSequenceOfInteger::*)() const) &MeshVS_HArray1OfSequenceOfInteger::Array1, "None");
cls_MeshVS_HArray1OfSequenceOfInteger.def("ChangeArray1", (MeshVS_Array1OfSequenceOfInteger & (MeshVS_HArray1OfSequenceOfInteger::*)()) &MeshVS_HArray1OfSequenceOfInteger::ChangeArray1, "None");
cls_MeshVS_HArray1OfSequenceOfInteger.def_static("get_type_name_", (const char * (*)()) &MeshVS_HArray1OfSequenceOfInteger::get_type_name, "None");
cls_MeshVS_HArray1OfSequenceOfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_HArray1OfSequenceOfInteger::get_type_descriptor, "None");
cls_MeshVS_HArray1OfSequenceOfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_HArray1OfSequenceOfInteger::*)() const) &MeshVS_HArray1OfSequenceOfInteger::DynamicType, "None");

// Enums

}