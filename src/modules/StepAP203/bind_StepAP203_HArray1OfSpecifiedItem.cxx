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
#include <StepAP203_Array1OfSpecifiedItem.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepAP203_HArray1OfSpecifiedItem.hxx>
#include <Standard_Type.hxx>

void bind_StepAP203_HArray1OfSpecifiedItem(py::module &mod){

py::class_<StepAP203_HArray1OfSpecifiedItem, opencascade::handle<StepAP203_HArray1OfSpecifiedItem>, Standard_Transient> cls_StepAP203_HArray1OfSpecifiedItem(mod, "StepAP203_HArray1OfSpecifiedItem", "None", py::multiple_inheritance());

// Constructors
cls_StepAP203_HArray1OfSpecifiedItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepAP203_HArray1OfSpecifiedItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP203_Array1OfSpecifiedItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepAP203_HArray1OfSpecifiedItem.def(py::init<const StepAP203_Array1OfSpecifiedItem &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepAP203_HArray1OfSpecifiedItem.def_static("operator new_", (void * (*)(size_t)) &StepAP203_HArray1OfSpecifiedItem::operator new, "None", py::arg("theSize"));
// cls_StepAP203_HArray1OfSpecifiedItem.def_static("operator delete_", (void (*)(void *)) &StepAP203_HArray1OfSpecifiedItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP203_HArray1OfSpecifiedItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP203_HArray1OfSpecifiedItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP203_HArray1OfSpecifiedItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP203_HArray1OfSpecifiedItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP203_HArray1OfSpecifiedItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP203_HArray1OfSpecifiedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP203_HArray1OfSpecifiedItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP203_HArray1OfSpecifiedItem::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepAP203_HArray1OfSpecifiedItem.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepAP203_HArray1OfSpecifiedItem::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepAP203_HArray1OfSpecifiedItem.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepAP203_HArray1OfSpecifiedItem::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepAP203_HArray1OfSpecifiedItem.def("Array1", (const StepAP203_Array1OfSpecifiedItem & (StepAP203_HArray1OfSpecifiedItem::*)() const) &StepAP203_HArray1OfSpecifiedItem::Array1, "None");
cls_StepAP203_HArray1OfSpecifiedItem.def("ChangeArray1", (StepAP203_Array1OfSpecifiedItem & (StepAP203_HArray1OfSpecifiedItem::*)()) &StepAP203_HArray1OfSpecifiedItem::ChangeArray1, "None");
cls_StepAP203_HArray1OfSpecifiedItem.def_static("get_type_name_", (const char * (*)()) &StepAP203_HArray1OfSpecifiedItem::get_type_name, "None");
cls_StepAP203_HArray1OfSpecifiedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_HArray1OfSpecifiedItem::get_type_descriptor, "None");
cls_StepAP203_HArray1OfSpecifiedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_HArray1OfSpecifiedItem::*)() const) &StepAP203_HArray1OfSpecifiedItem::DynamicType, "None");

// Enums

}