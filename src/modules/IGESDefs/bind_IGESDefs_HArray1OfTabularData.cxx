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
#include <IGESDefs_Array1OfTabularData.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <IGESDefs_HArray1OfTabularData.hxx>
#include <Standard_Type.hxx>

void bind_IGESDefs_HArray1OfTabularData(py::module &mod){

py::class_<IGESDefs_HArray1OfTabularData, opencascade::handle<IGESDefs_HArray1OfTabularData>, Standard_Transient> cls_IGESDefs_HArray1OfTabularData(mod, "IGESDefs_HArray1OfTabularData", "None", py::multiple_inheritance());

// Constructors
cls_IGESDefs_HArray1OfTabularData.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESDefs_HArray1OfTabularData.def(py::init<const Standard_Integer, const Standard_Integer, const IGESDefs_Array1OfTabularData::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESDefs_HArray1OfTabularData.def(py::init<const IGESDefs_Array1OfTabularData &>(), py::arg("theOther"));

// Fields

// Methods
// cls_IGESDefs_HArray1OfTabularData.def_static("operator new_", (void * (*)(size_t)) &IGESDefs_HArray1OfTabularData::operator new, "None", py::arg("theSize"));
// cls_IGESDefs_HArray1OfTabularData.def_static("operator delete_", (void (*)(void *)) &IGESDefs_HArray1OfTabularData::operator delete, "None", py::arg("theAddress"));
// cls_IGESDefs_HArray1OfTabularData.def_static("operator new[]_", (void * (*)(size_t)) &IGESDefs_HArray1OfTabularData::operator new[], "None", py::arg("theSize"));
// cls_IGESDefs_HArray1OfTabularData.def_static("operator delete[]_", (void (*)(void *)) &IGESDefs_HArray1OfTabularData::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDefs_HArray1OfTabularData.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDefs_HArray1OfTabularData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDefs_HArray1OfTabularData.def_static("operator delete_", (void (*)(void *, void *)) &IGESDefs_HArray1OfTabularData::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESDefs_HArray1OfTabularData.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESDefs_HArray1OfTabularData::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESDefs_HArray1OfTabularData.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESDefs_HArray1OfTabularData::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESDefs_HArray1OfTabularData.def("Array1", (const IGESDefs_Array1OfTabularData & (IGESDefs_HArray1OfTabularData::*)() const) &IGESDefs_HArray1OfTabularData::Array1, "None");
cls_IGESDefs_HArray1OfTabularData.def("ChangeArray1", (IGESDefs_Array1OfTabularData & (IGESDefs_HArray1OfTabularData::*)()) &IGESDefs_HArray1OfTabularData::ChangeArray1, "None");
cls_IGESDefs_HArray1OfTabularData.def_static("get_type_name_", (const char * (*)()) &IGESDefs_HArray1OfTabularData::get_type_name, "None");
cls_IGESDefs_HArray1OfTabularData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_HArray1OfTabularData::get_type_descriptor, "None");
cls_IGESDefs_HArray1OfTabularData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_HArray1OfTabularData::*)() const) &IGESDefs_HArray1OfTabularData::DynamicType, "None");

// Enums

}