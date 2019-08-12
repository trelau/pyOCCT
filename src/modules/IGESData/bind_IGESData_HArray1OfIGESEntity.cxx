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
#include <IGESData_Array1OfIGESEntity.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_HArray1OfIGESEntity(py::module &mod){

py::class_<IGESData_HArray1OfIGESEntity, opencascade::handle<IGESData_HArray1OfIGESEntity>, Standard_Transient> cls_IGESData_HArray1OfIGESEntity(mod, "IGESData_HArray1OfIGESEntity", "None", py::multiple_inheritance());

// Constructors
cls_IGESData_HArray1OfIGESEntity.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESData_HArray1OfIGESEntity.def(py::init<const Standard_Integer, const Standard_Integer, const IGESData_Array1OfIGESEntity::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESData_HArray1OfIGESEntity.def(py::init<const IGESData_Array1OfIGESEntity &>(), py::arg("theOther"));

// Fields

// Methods
// cls_IGESData_HArray1OfIGESEntity.def_static("operator new_", (void * (*)(size_t)) &IGESData_HArray1OfIGESEntity::operator new, "None", py::arg("theSize"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator delete_", (void (*)(void *)) &IGESData_HArray1OfIGESEntity::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_HArray1OfIGESEntity::operator new[], "None", py::arg("theSize"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator delete[]_", (void (*)(void *)) &IGESData_HArray1OfIGESEntity::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_HArray1OfIGESEntity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_HArray1OfIGESEntity::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESData_HArray1OfIGESEntity::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESData_HArray1OfIGESEntity::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESData_HArray1OfIGESEntity.def("Array1", (const IGESData_Array1OfIGESEntity & (IGESData_HArray1OfIGESEntity::*)() const) &IGESData_HArray1OfIGESEntity::Array1, "None");
cls_IGESData_HArray1OfIGESEntity.def("ChangeArray1", (IGESData_Array1OfIGESEntity & (IGESData_HArray1OfIGESEntity::*)()) &IGESData_HArray1OfIGESEntity::ChangeArray1, "None");
cls_IGESData_HArray1OfIGESEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_HArray1OfIGESEntity::get_type_name, "None");
cls_IGESData_HArray1OfIGESEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_HArray1OfIGESEntity::get_type_descriptor, "None");
cls_IGESData_HArray1OfIGESEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_HArray1OfIGESEntity::*)() const) &IGESData_HArray1OfIGESEntity::DynamicType, "None");

// Enums

}