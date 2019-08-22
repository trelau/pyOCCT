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
#include <Standard_IStream.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlData_InBuffer.hxx>

void bind_VrmlData_InBuffer(py::module &mod){

py::class_<VrmlData_InBuffer> cls_VrmlData_InBuffer(mod, "VrmlData_InBuffer", "Structure passed to the methods dealing with input stream.");

// Constructors
cls_VrmlData_InBuffer.def(py::init<Standard_IStream &>(), py::arg("theStream"));

// Fields
// cls_VrmlData_InBuffer.def_readwrite("Input", &VrmlData_InBuffer::Input, "None");
// cls_VrmlData_InBuffer.def_readwrite("Line", &VrmlData_InBuffer::Line, "None");
cls_VrmlData_InBuffer.def_readwrite("LinePtr", &VrmlData_InBuffer::LinePtr, "None");
cls_VrmlData_InBuffer.def_readwrite("IsProcessed", &VrmlData_InBuffer::IsProcessed, "None");
cls_VrmlData_InBuffer.def_readwrite("LineCount", &VrmlData_InBuffer::LineCount, "None");

// Methods

// Enums

}