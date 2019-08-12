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
#include <StepAP214_Array1OfApprovalItem.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepAP214_HArray1OfApprovalItem.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_HArray1OfApprovalItem(py::module &mod){

py::class_<StepAP214_HArray1OfApprovalItem, opencascade::handle<StepAP214_HArray1OfApprovalItem>, Standard_Transient> cls_StepAP214_HArray1OfApprovalItem(mod, "StepAP214_HArray1OfApprovalItem", "None", py::multiple_inheritance());

// Constructors
cls_StepAP214_HArray1OfApprovalItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepAP214_HArray1OfApprovalItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP214_Array1OfApprovalItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepAP214_HArray1OfApprovalItem.def(py::init<const StepAP214_Array1OfApprovalItem &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepAP214_HArray1OfApprovalItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_HArray1OfApprovalItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_HArray1OfApprovalItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_HArray1OfApprovalItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_HArray1OfApprovalItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_HArray1OfApprovalItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_HArray1OfApprovalItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_HArray1OfApprovalItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_HArray1OfApprovalItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_HArray1OfApprovalItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_HArray1OfApprovalItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_HArray1OfApprovalItem::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepAP214_HArray1OfApprovalItem.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepAP214_HArray1OfApprovalItem::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepAP214_HArray1OfApprovalItem.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepAP214_HArray1OfApprovalItem::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepAP214_HArray1OfApprovalItem.def("Array1", (const StepAP214_Array1OfApprovalItem & (StepAP214_HArray1OfApprovalItem::*)() const) &StepAP214_HArray1OfApprovalItem::Array1, "None");
cls_StepAP214_HArray1OfApprovalItem.def("ChangeArray1", (StepAP214_Array1OfApprovalItem & (StepAP214_HArray1OfApprovalItem::*)()) &StepAP214_HArray1OfApprovalItem::ChangeArray1, "None");
cls_StepAP214_HArray1OfApprovalItem.def_static("get_type_name_", (const char * (*)()) &StepAP214_HArray1OfApprovalItem::get_type_name, "None");
cls_StepAP214_HArray1OfApprovalItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_HArray1OfApprovalItem::get_type_descriptor, "None");
cls_StepAP214_HArray1OfApprovalItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_HArray1OfApprovalItem::*)() const) &StepAP214_HArray1OfApprovalItem::DynamicType, "None");

// Enums

}