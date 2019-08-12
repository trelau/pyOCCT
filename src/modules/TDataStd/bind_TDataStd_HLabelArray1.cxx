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
#include <TDataStd_LabelArray1.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TDataStd_HLabelArray1.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_HLabelArray1(py::module &mod){

py::class_<TDataStd_HLabelArray1, opencascade::handle<TDataStd_HLabelArray1>, Standard_Transient> cls_TDataStd_HLabelArray1(mod, "TDataStd_HLabelArray1", "None", py::multiple_inheritance());

// Constructors
cls_TDataStd_HLabelArray1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TDataStd_HLabelArray1.def(py::init<const Standard_Integer, const Standard_Integer, const TDataStd_LabelArray1::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TDataStd_HLabelArray1.def(py::init<const TDataStd_LabelArray1 &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TDataStd_HLabelArray1.def_static("operator new_", (void * (*)(size_t)) &TDataStd_HLabelArray1::operator new, "None", py::arg("theSize"));
// cls_TDataStd_HLabelArray1.def_static("operator delete_", (void (*)(void *)) &TDataStd_HLabelArray1::operator delete, "None", py::arg("theAddress"));
// cls_TDataStd_HLabelArray1.def_static("operator new[]_", (void * (*)(size_t)) &TDataStd_HLabelArray1::operator new[], "None", py::arg("theSize"));
// cls_TDataStd_HLabelArray1.def_static("operator delete[]_", (void (*)(void *)) &TDataStd_HLabelArray1::operator delete[], "None", py::arg("theAddress"));
// cls_TDataStd_HLabelArray1.def_static("operator new_", (void * (*)(size_t, void *)) &TDataStd_HLabelArray1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDataStd_HLabelArray1.def_static("operator delete_", (void (*)(void *, void *)) &TDataStd_HLabelArray1::operator delete, "None", py::arg(""), py::arg(""));
// cls_TDataStd_HLabelArray1.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TDataStd_HLabelArray1::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TDataStd_HLabelArray1.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TDataStd_HLabelArray1::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TDataStd_HLabelArray1.def("Array1", (const TDataStd_LabelArray1 & (TDataStd_HLabelArray1::*)() const) &TDataStd_HLabelArray1::Array1, "None");
cls_TDataStd_HLabelArray1.def("ChangeArray1", (TDataStd_LabelArray1 & (TDataStd_HLabelArray1::*)()) &TDataStd_HLabelArray1::ChangeArray1, "None");
cls_TDataStd_HLabelArray1.def_static("get_type_name_", (const char * (*)()) &TDataStd_HLabelArray1::get_type_name, "None");
cls_TDataStd_HLabelArray1.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_HLabelArray1::get_type_descriptor, "None");
cls_TDataStd_HLabelArray1.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_HLabelArray1::*)() const) &TDataStd_HLabelArray1::DynamicType, "None");

// Enums

}