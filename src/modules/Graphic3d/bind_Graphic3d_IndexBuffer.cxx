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
#include <Graphic3d_Buffer.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_IndexBuffer.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_IndexBuffer(py::module &mod){

py::class_<Graphic3d_IndexBuffer, opencascade::handle<Graphic3d_IndexBuffer>, Graphic3d_Buffer> cls_Graphic3d_IndexBuffer(mod, "Graphic3d_IndexBuffer", "Index buffer.");

// Constructors
cls_Graphic3d_IndexBuffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));

// Fields

// Methods
cls_Graphic3d_IndexBuffer.def("InitInt32", (bool (Graphic3d_IndexBuffer::*)(const Standard_Integer)) &Graphic3d_IndexBuffer::InitInt32, "Allocates new empty index array", py::arg("theNbElems"));
cls_Graphic3d_IndexBuffer.def("Index", (Standard_Integer (Graphic3d_IndexBuffer::*)(const Standard_Integer) const) &Graphic3d_IndexBuffer::Index, "Access index at specified position", py::arg("theIndex"));
cls_Graphic3d_IndexBuffer.def("SetIndex", (void (Graphic3d_IndexBuffer::*)(const Standard_Integer, const Standard_Integer)) &Graphic3d_IndexBuffer::SetIndex, "Change index at specified position", py::arg("theIndex"), py::arg("theValue"));
cls_Graphic3d_IndexBuffer.def_static("get_type_name_", (const char * (*)()) &Graphic3d_IndexBuffer::get_type_name, "None");
cls_Graphic3d_IndexBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_IndexBuffer::get_type_descriptor, "None");
cls_Graphic3d_IndexBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_IndexBuffer::*)() const) &Graphic3d_IndexBuffer::DynamicType, "None");

// Enums

}