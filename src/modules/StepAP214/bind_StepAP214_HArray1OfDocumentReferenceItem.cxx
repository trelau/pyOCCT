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
#include <StepAP214_Array1OfDocumentReferenceItem.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepAP214_HArray1OfDocumentReferenceItem.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_HArray1OfDocumentReferenceItem(py::module &mod){

py::class_<StepAP214_HArray1OfDocumentReferenceItem, opencascade::handle<StepAP214_HArray1OfDocumentReferenceItem>, Standard_Transient> cls_StepAP214_HArray1OfDocumentReferenceItem(mod, "StepAP214_HArray1OfDocumentReferenceItem", "None", py::multiple_inheritance());

// Constructors
cls_StepAP214_HArray1OfDocumentReferenceItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepAP214_HArray1OfDocumentReferenceItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP214_Array1OfDocumentReferenceItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepAP214_HArray1OfDocumentReferenceItem.def(py::init<const StepAP214_Array1OfDocumentReferenceItem &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepAP214_HArray1OfDocumentReferenceItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_HArray1OfDocumentReferenceItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_HArray1OfDocumentReferenceItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_HArray1OfDocumentReferenceItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_HArray1OfDocumentReferenceItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_HArray1OfDocumentReferenceItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_HArray1OfDocumentReferenceItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_HArray1OfDocumentReferenceItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_HArray1OfDocumentReferenceItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_HArray1OfDocumentReferenceItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_HArray1OfDocumentReferenceItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_HArray1OfDocumentReferenceItem::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepAP214_HArray1OfDocumentReferenceItem.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepAP214_HArray1OfDocumentReferenceItem::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepAP214_HArray1OfDocumentReferenceItem.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepAP214_HArray1OfDocumentReferenceItem::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepAP214_HArray1OfDocumentReferenceItem.def("Array1", (const StepAP214_Array1OfDocumentReferenceItem & (StepAP214_HArray1OfDocumentReferenceItem::*)() const) &StepAP214_HArray1OfDocumentReferenceItem::Array1, "None");
cls_StepAP214_HArray1OfDocumentReferenceItem.def("ChangeArray1", (StepAP214_Array1OfDocumentReferenceItem & (StepAP214_HArray1OfDocumentReferenceItem::*)()) &StepAP214_HArray1OfDocumentReferenceItem::ChangeArray1, "None");
cls_StepAP214_HArray1OfDocumentReferenceItem.def_static("get_type_name_", (const char * (*)()) &StepAP214_HArray1OfDocumentReferenceItem::get_type_name, "None");
cls_StepAP214_HArray1OfDocumentReferenceItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_HArray1OfDocumentReferenceItem::get_type_descriptor, "None");
cls_StepAP214_HArray1OfDocumentReferenceItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_HArray1OfDocumentReferenceItem::*)() const) &StepAP214_HArray1OfDocumentReferenceItem::DynamicType, "None");

// Enums

}