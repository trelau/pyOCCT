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
#include <ChFiDS_SequenceOfSurfData.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <ChFiDS_HData.hxx>
#include <Standard_Type.hxx>

void bind_ChFiDS_HData(py::module &mod){

py::class_<ChFiDS_HData, opencascade::handle<ChFiDS_HData>, Standard_Transient> cls_ChFiDS_HData(mod, "ChFiDS_HData", "None", py::multiple_inheritance());

// Constructors
cls_ChFiDS_HData.def(py::init<>());
cls_ChFiDS_HData.def(py::init<const ChFiDS_SequenceOfSurfData &>(), py::arg("theOther"));

// Fields

// Methods
// cls_ChFiDS_HData.def_static("operator new_", (void * (*)(size_t)) &ChFiDS_HData::operator new, "None", py::arg("theSize"));
// cls_ChFiDS_HData.def_static("operator delete_", (void (*)(void *)) &ChFiDS_HData::operator delete, "None", py::arg("theAddress"));
// cls_ChFiDS_HData.def_static("operator new[]_", (void * (*)(size_t)) &ChFiDS_HData::operator new[], "None", py::arg("theSize"));
// cls_ChFiDS_HData.def_static("operator delete[]_", (void (*)(void *)) &ChFiDS_HData::operator delete[], "None", py::arg("theAddress"));
// cls_ChFiDS_HData.def_static("operator new_", (void * (*)(size_t, void *)) &ChFiDS_HData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFiDS_HData.def_static("operator delete_", (void (*)(void *, void *)) &ChFiDS_HData::operator delete, "None", py::arg(""), py::arg(""));
// cls_ChFiDS_HData.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &ChFiDS_HData::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_ChFiDS_HData.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &ChFiDS_HData::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_ChFiDS_HData.def("Sequence", (const ChFiDS_SequenceOfSurfData & (ChFiDS_HData::*)() const) &ChFiDS_HData::Sequence, "None");
cls_ChFiDS_HData.def("Append", (void (ChFiDS_HData::*)(const ChFiDS_SequenceOfSurfData::value_type &)) &ChFiDS_HData::Append, "None", py::arg("theItem"));
cls_ChFiDS_HData.def("Append", (void (ChFiDS_HData::*)(ChFiDS_SequenceOfSurfData &)) &ChFiDS_HData::Append, "None", py::arg("theSequence"));
cls_ChFiDS_HData.def("ChangeSequence", (ChFiDS_SequenceOfSurfData & (ChFiDS_HData::*)()) &ChFiDS_HData::ChangeSequence, "None");
cls_ChFiDS_HData.def_static("get_type_name_", (const char * (*)()) &ChFiDS_HData::get_type_name, "None");
cls_ChFiDS_HData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_HData::get_type_descriptor, "None");
cls_ChFiDS_HData.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_HData::*)() const) &ChFiDS_HData::DynamicType, "None");

// Enums

}