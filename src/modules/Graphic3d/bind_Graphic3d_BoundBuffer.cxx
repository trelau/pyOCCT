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
#include <NCollection_Buffer.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_Vec4.hxx>
#include <Graphic3d_BoundBuffer.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_BoundBuffer(py::module &mod){

py::class_<Graphic3d_BoundBuffer, opencascade::handle<Graphic3d_BoundBuffer>, NCollection_Buffer> cls_Graphic3d_BoundBuffer(mod, "Graphic3d_BoundBuffer", "Bounds buffer.");

// Constructors
cls_Graphic3d_BoundBuffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));

// Fields
cls_Graphic3d_BoundBuffer.def_readwrite("Colors", &Graphic3d_BoundBuffer::Colors, "pointer to facet color values");
cls_Graphic3d_BoundBuffer.def_readwrite("Bounds", &Graphic3d_BoundBuffer::Bounds, "pointer to bounds array");
cls_Graphic3d_BoundBuffer.def_readwrite("NbBounds", &Graphic3d_BoundBuffer::NbBounds, "number of bounds");

// Methods
cls_Graphic3d_BoundBuffer.def("Init", (bool (Graphic3d_BoundBuffer::*)(const Standard_Integer, const Standard_Boolean)) &Graphic3d_BoundBuffer::Init, "Allocates new empty array", py::arg("theNbBounds"), py::arg("theHasColors"));
cls_Graphic3d_BoundBuffer.def_static("get_type_name_", (const char * (*)()) &Graphic3d_BoundBuffer::get_type_name, "None");
cls_Graphic3d_BoundBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_BoundBuffer::get_type_descriptor, "None");
cls_Graphic3d_BoundBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_BoundBuffer::*)() const) &Graphic3d_BoundBuffer::DynamicType, "None");

// Enums

}