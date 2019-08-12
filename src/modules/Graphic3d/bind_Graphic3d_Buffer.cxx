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
#include <Graphic3d_Buffer.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_Buffer(py::module &mod){

py::class_<Graphic3d_Buffer, opencascade::handle<Graphic3d_Buffer>, NCollection_Buffer> cls_Graphic3d_Buffer(mod, "Graphic3d_Buffer", "Buffer of vertex attributes.");

// Constructors
cls_Graphic3d_Buffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));

// Fields
cls_Graphic3d_Buffer.def_readwrite("Stride", &Graphic3d_Buffer::Stride, "the distance to the attributes of the next vertex");
cls_Graphic3d_Buffer.def_readwrite("NbElements", &Graphic3d_Buffer::NbElements, "number of the elements");
cls_Graphic3d_Buffer.def_readwrite("NbAttributes", &Graphic3d_Buffer::NbAttributes, "number of vertex attributes");

// Methods
cls_Graphic3d_Buffer.def("AttributesArray", (const Graphic3d_Attribute * (Graphic3d_Buffer::*)() const) &Graphic3d_Buffer::AttributesArray, "Returns array of attributes definitions");
cls_Graphic3d_Buffer.def("Attribute", (const Graphic3d_Attribute & (Graphic3d_Buffer::*)(const Standard_Integer) const) &Graphic3d_Buffer::Attribute, "Returns attribute definition", py::arg("theAttribIndex"));
cls_Graphic3d_Buffer.def("ChangeAttribute", (Graphic3d_Attribute & (Graphic3d_Buffer::*)(const Standard_Integer)) &Graphic3d_Buffer::ChangeAttribute, "Returns attribute definition", py::arg("theAttribIndex"));
cls_Graphic3d_Buffer.def("AttributeOffset", (Standard_Integer (Graphic3d_Buffer::*)(const Standard_Integer) const) &Graphic3d_Buffer::AttributeOffset, "Returns data offset to specified attribute", py::arg("theAttribIndex"));
cls_Graphic3d_Buffer.def("Data", (const Standard_Byte * (Graphic3d_Buffer::*)(const Standard_Integer) const) &Graphic3d_Buffer::Data, "Returns data for specified attribute", py::arg("theAttribIndex"));
cls_Graphic3d_Buffer.def("ChangeData", (Standard_Byte * (Graphic3d_Buffer::*)(const Standard_Integer)) &Graphic3d_Buffer::ChangeData, "Returns data for specified attribute", py::arg("theAttribIndex"));
cls_Graphic3d_Buffer.def("value", (const Standard_Byte * (Graphic3d_Buffer::*)(const Standard_Integer) const) &Graphic3d_Buffer::value, "Access specified element.", py::arg("theElem"));
cls_Graphic3d_Buffer.def("changeValue", (Standard_Byte * (Graphic3d_Buffer::*)(const Standard_Integer)) &Graphic3d_Buffer::changeValue, "Access specified element.", py::arg("theElem"));
cls_Graphic3d_Buffer.def("release", (void (Graphic3d_Buffer::*)()) &Graphic3d_Buffer::release, "Release buffer.");
cls_Graphic3d_Buffer.def("Init", (bool (Graphic3d_Buffer::*)(const Standard_Integer, const Graphic3d_Attribute *, const Standard_Integer)) &Graphic3d_Buffer::Init, "Allocates new empty array", py::arg("theNbElems"), py::arg("theAttribs"), py::arg("theNbAttribs"));
cls_Graphic3d_Buffer.def("Init", (bool (Graphic3d_Buffer::*)(const Standard_Integer, const Graphic3d_Array1OfAttribute &)) &Graphic3d_Buffer::Init, "Allocates new empty array", py::arg("theNbElems"), py::arg("theAttribs"));
cls_Graphic3d_Buffer.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Buffer::get_type_name, "None");
cls_Graphic3d_Buffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Buffer::get_type_descriptor, "None");
cls_Graphic3d_Buffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Buffer::*)() const) &Graphic3d_Buffer::DynamicType, "None");

// Enums

}