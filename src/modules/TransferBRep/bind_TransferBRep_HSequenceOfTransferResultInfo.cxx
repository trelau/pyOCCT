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
#include <TransferBRep_SequenceOfTransferResultInfo.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <TransferBRep_HSequenceOfTransferResultInfo.hxx>
#include <Standard_Type.hxx>

void bind_TransferBRep_HSequenceOfTransferResultInfo(py::module &mod){

py::class_<TransferBRep_HSequenceOfTransferResultInfo, opencascade::handle<TransferBRep_HSequenceOfTransferResultInfo>, Standard_Transient> cls_TransferBRep_HSequenceOfTransferResultInfo(mod, "TransferBRep_HSequenceOfTransferResultInfo", "None", py::multiple_inheritance());

// Constructors
cls_TransferBRep_HSequenceOfTransferResultInfo.def(py::init<>());
cls_TransferBRep_HSequenceOfTransferResultInfo.def(py::init<const TransferBRep_SequenceOfTransferResultInfo &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("operator new_", (void * (*)(size_t)) &TransferBRep_HSequenceOfTransferResultInfo::operator new, "None", py::arg("theSize"));
// cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("operator delete_", (void (*)(void *)) &TransferBRep_HSequenceOfTransferResultInfo::operator delete, "None", py::arg("theAddress"));
// cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("operator new[]_", (void * (*)(size_t)) &TransferBRep_HSequenceOfTransferResultInfo::operator new[], "None", py::arg("theSize"));
// cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("operator delete[]_", (void (*)(void *)) &TransferBRep_HSequenceOfTransferResultInfo::operator delete[], "None", py::arg("theAddress"));
// cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("operator new_", (void * (*)(size_t, void *)) &TransferBRep_HSequenceOfTransferResultInfo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("operator delete_", (void (*)(void *, void *)) &TransferBRep_HSequenceOfTransferResultInfo::operator delete, "None", py::arg(""), py::arg(""));
// cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TransferBRep_HSequenceOfTransferResultInfo::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TransferBRep_HSequenceOfTransferResultInfo::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TransferBRep_HSequenceOfTransferResultInfo.def("Sequence", (const TransferBRep_SequenceOfTransferResultInfo & (TransferBRep_HSequenceOfTransferResultInfo::*)() const) &TransferBRep_HSequenceOfTransferResultInfo::Sequence, "None");
cls_TransferBRep_HSequenceOfTransferResultInfo.def("Append", (void (TransferBRep_HSequenceOfTransferResultInfo::*)(const TransferBRep_SequenceOfTransferResultInfo::value_type &)) &TransferBRep_HSequenceOfTransferResultInfo::Append, "None", py::arg("theItem"));
cls_TransferBRep_HSequenceOfTransferResultInfo.def("Append", (void (TransferBRep_HSequenceOfTransferResultInfo::*)(TransferBRep_SequenceOfTransferResultInfo &)) &TransferBRep_HSequenceOfTransferResultInfo::Append, "None", py::arg("theSequence"));
cls_TransferBRep_HSequenceOfTransferResultInfo.def("ChangeSequence", (TransferBRep_SequenceOfTransferResultInfo & (TransferBRep_HSequenceOfTransferResultInfo::*)()) &TransferBRep_HSequenceOfTransferResultInfo::ChangeSequence, "None");
cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("get_type_name_", (const char * (*)()) &TransferBRep_HSequenceOfTransferResultInfo::get_type_name, "None");
cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_HSequenceOfTransferResultInfo::get_type_descriptor, "None");
cls_TransferBRep_HSequenceOfTransferResultInfo.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_HSequenceOfTransferResultInfo::*)() const) &TransferBRep_HSequenceOfTransferResultInfo::DynamicType, "None");

// Enums

}