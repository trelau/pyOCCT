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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Buffer.hxx>
#include <Standard_Type.hxx>

void bind_NCollection_Buffer(py::module &mod){

py::class_<NCollection_Buffer, opencascade::handle<NCollection_Buffer>, Standard_Transient> cls_NCollection_Buffer(mod, "NCollection_Buffer", "Low-level buffer object.");

// Constructors
cls_NCollection_Buffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));
cls_NCollection_Buffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &, const Standard_Size>(), py::arg("theAlloc"), py::arg("theSize"));
cls_NCollection_Buffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &, const Standard_Size, Standard_Byte *>(), py::arg("theAlloc"), py::arg("theSize"), py::arg("theData"));

// Fields

// Methods
cls_NCollection_Buffer.def("Data", (const Standard_Byte * (NCollection_Buffer::*)() const) &NCollection_Buffer::Data, "Returns buffer data");
cls_NCollection_Buffer.def("ChangeData", (Standard_Byte * (NCollection_Buffer::*)()) &NCollection_Buffer::ChangeData, "Returns buffer data");
cls_NCollection_Buffer.def("IsEmpty", (bool (NCollection_Buffer::*)() const) &NCollection_Buffer::IsEmpty, "Returns true if buffer is not allocated");
cls_NCollection_Buffer.def("Size", (Standard_Size (NCollection_Buffer::*)() const) &NCollection_Buffer::Size, "Return buffer length in bytes.");
cls_NCollection_Buffer.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_Buffer::*)() const) &NCollection_Buffer::Allocator, "Returns buffer allocator");
cls_NCollection_Buffer.def("SetAllocator", (void (NCollection_Buffer::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_Buffer::SetAllocator, "Assign new buffer allocator with de-allocation of buffer.", py::arg("theAlloc"));
cls_NCollection_Buffer.def("Allocate", (bool (NCollection_Buffer::*)(const Standard_Size)) &NCollection_Buffer::Allocate, "Allocate the buffer.", py::arg("theSize"));
cls_NCollection_Buffer.def("Free", (void (NCollection_Buffer::*)()) &NCollection_Buffer::Free, "De-allocate buffer.");
cls_NCollection_Buffer.def_static("get_type_name_", (const char * (*)()) &NCollection_Buffer::get_type_name, "None");
cls_NCollection_Buffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_Buffer::get_type_descriptor, "None");
cls_NCollection_Buffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_Buffer::*)() const) &NCollection_Buffer::DynamicType, "None");

// Enums

}