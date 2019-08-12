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
#include <Select3D_BVHIndexBuffer.hxx>
#include <Standard_Type.hxx>

void bind_Select3D_BVHIndexBuffer(py::module &mod){

py::class_<Select3D_BVHIndexBuffer, opencascade::handle<Select3D_BVHIndexBuffer>, Graphic3d_Buffer> cls_Select3D_BVHIndexBuffer(mod, "Select3D_BVHIndexBuffer", "Index buffer for BVH tree.");

// Constructors
cls_Select3D_BVHIndexBuffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));

// Fields

// Methods
cls_Select3D_BVHIndexBuffer.def("HasPatches", (bool (Select3D_BVHIndexBuffer::*)() const) &Select3D_BVHIndexBuffer::HasPatches, "None");
cls_Select3D_BVHIndexBuffer.def("Init", (bool (Select3D_BVHIndexBuffer::*)(const Standard_Integer, const bool)) &Select3D_BVHIndexBuffer::Init, "Allocates new empty index array", py::arg("theNbElems"), py::arg("theHasPatches"));
cls_Select3D_BVHIndexBuffer.def("Index", (Standard_Integer (Select3D_BVHIndexBuffer::*)(const Standard_Integer) const) &Select3D_BVHIndexBuffer::Index, "Access index at specified position", py::arg("theIndex"));
cls_Select3D_BVHIndexBuffer.def("PatchSize", (Standard_Integer (Select3D_BVHIndexBuffer::*)(const Standard_Integer) const) &Select3D_BVHIndexBuffer::PatchSize, "Access index at specified position", py::arg("theIndex"));
cls_Select3D_BVHIndexBuffer.def("SetIndex", (void (Select3D_BVHIndexBuffer::*)(const Standard_Integer, const Standard_Integer)) &Select3D_BVHIndexBuffer::SetIndex, "Change index at specified position", py::arg("theIndex"), py::arg("theValue"));
cls_Select3D_BVHIndexBuffer.def("SetIndex", (void (Select3D_BVHIndexBuffer::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Select3D_BVHIndexBuffer::SetIndex, "Change index at specified position", py::arg("theIndex"), py::arg("theValue"), py::arg("thePatchSize"));
cls_Select3D_BVHIndexBuffer.def_static("get_type_name_", (const char * (*)()) &Select3D_BVHIndexBuffer::get_type_name, "None");
cls_Select3D_BVHIndexBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_BVHIndexBuffer::get_type_descriptor, "None");
cls_Select3D_BVHIndexBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_BVHIndexBuffer::*)() const) &Select3D_BVHIndexBuffer::DynamicType, "None");

// Enums

}