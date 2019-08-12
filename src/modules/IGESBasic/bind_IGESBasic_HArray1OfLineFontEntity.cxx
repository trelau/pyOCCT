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
#include <IGESBasic_Array1OfLineFontEntity.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <IGESBasic_HArray1OfLineFontEntity.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_HArray1OfLineFontEntity(py::module &mod){

py::class_<IGESBasic_HArray1OfLineFontEntity, opencascade::handle<IGESBasic_HArray1OfLineFontEntity>, Standard_Transient> cls_IGESBasic_HArray1OfLineFontEntity(mod, "IGESBasic_HArray1OfLineFontEntity", "None", py::multiple_inheritance());

// Constructors
cls_IGESBasic_HArray1OfLineFontEntity.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESBasic_HArray1OfLineFontEntity.def(py::init<const Standard_Integer, const Standard_Integer, const IGESBasic_Array1OfLineFontEntity::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESBasic_HArray1OfLineFontEntity.def(py::init<const IGESBasic_Array1OfLineFontEntity &>(), py::arg("theOther"));

// Fields

// Methods
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_HArray1OfLineFontEntity::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator delete_", (void (*)(void *)) &IGESBasic_HArray1OfLineFontEntity::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_HArray1OfLineFontEntity::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_HArray1OfLineFontEntity::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_HArray1OfLineFontEntity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_HArray1OfLineFontEntity::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESBasic_HArray1OfLineFontEntity::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESBasic_HArray1OfLineFontEntity::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESBasic_HArray1OfLineFontEntity.def("Array1", (const IGESBasic_Array1OfLineFontEntity & (IGESBasic_HArray1OfLineFontEntity::*)() const) &IGESBasic_HArray1OfLineFontEntity::Array1, "None");
cls_IGESBasic_HArray1OfLineFontEntity.def("ChangeArray1", (IGESBasic_Array1OfLineFontEntity & (IGESBasic_HArray1OfLineFontEntity::*)()) &IGESBasic_HArray1OfLineFontEntity::ChangeArray1, "None");
cls_IGESBasic_HArray1OfLineFontEntity.def_static("get_type_name_", (const char * (*)()) &IGESBasic_HArray1OfLineFontEntity::get_type_name, "None");
cls_IGESBasic_HArray1OfLineFontEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_HArray1OfLineFontEntity::get_type_descriptor, "None");
cls_IGESBasic_HArray1OfLineFontEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_HArray1OfLineFontEntity::*)() const) &IGESBasic_HArray1OfLineFontEntity::DynamicType, "None");

// Enums

}