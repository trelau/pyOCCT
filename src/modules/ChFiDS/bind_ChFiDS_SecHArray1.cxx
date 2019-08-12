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
#include <ChFiDS_SecArray1.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <ChFiDS_SecHArray1.hxx>
#include <Standard_Type.hxx>

void bind_ChFiDS_SecHArray1(py::module &mod){

py::class_<ChFiDS_SecHArray1, opencascade::handle<ChFiDS_SecHArray1>, Standard_Transient> cls_ChFiDS_SecHArray1(mod, "ChFiDS_SecHArray1", "None", py::multiple_inheritance());

// Constructors
cls_ChFiDS_SecHArray1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_ChFiDS_SecHArray1.def(py::init<const Standard_Integer, const Standard_Integer, const ChFiDS_SecArray1::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_ChFiDS_SecHArray1.def(py::init<const ChFiDS_SecArray1 &>(), py::arg("theOther"));

// Fields

// Methods
// cls_ChFiDS_SecHArray1.def_static("operator new_", (void * (*)(size_t)) &ChFiDS_SecHArray1::operator new, "None", py::arg("theSize"));
// cls_ChFiDS_SecHArray1.def_static("operator delete_", (void (*)(void *)) &ChFiDS_SecHArray1::operator delete, "None", py::arg("theAddress"));
// cls_ChFiDS_SecHArray1.def_static("operator new[]_", (void * (*)(size_t)) &ChFiDS_SecHArray1::operator new[], "None", py::arg("theSize"));
// cls_ChFiDS_SecHArray1.def_static("operator delete[]_", (void (*)(void *)) &ChFiDS_SecHArray1::operator delete[], "None", py::arg("theAddress"));
// cls_ChFiDS_SecHArray1.def_static("operator new_", (void * (*)(size_t, void *)) &ChFiDS_SecHArray1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFiDS_SecHArray1.def_static("operator delete_", (void (*)(void *, void *)) &ChFiDS_SecHArray1::operator delete, "None", py::arg(""), py::arg(""));
// cls_ChFiDS_SecHArray1.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &ChFiDS_SecHArray1::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_ChFiDS_SecHArray1.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &ChFiDS_SecHArray1::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_ChFiDS_SecHArray1.def("Array1", (const ChFiDS_SecArray1 & (ChFiDS_SecHArray1::*)() const) &ChFiDS_SecHArray1::Array1, "None");
cls_ChFiDS_SecHArray1.def("ChangeArray1", (ChFiDS_SecArray1 & (ChFiDS_SecHArray1::*)()) &ChFiDS_SecHArray1::ChangeArray1, "None");
cls_ChFiDS_SecHArray1.def_static("get_type_name_", (const char * (*)()) &ChFiDS_SecHArray1::get_type_name, "None");
cls_ChFiDS_SecHArray1.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_SecHArray1::get_type_descriptor, "None");
cls_ChFiDS_SecHArray1.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_SecHArray1::*)() const) &ChFiDS_SecHArray1::DynamicType, "None");

// Enums

}