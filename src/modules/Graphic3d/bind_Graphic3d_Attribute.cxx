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
#include <Standard_TypeDef.hxx>
#include <Graphic3d_Vec2.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Graphic3d_Vec4.hxx>

void bind_Graphic3d_Attribute(py::module &mod){

py::class_<Graphic3d_Attribute, std::unique_ptr<Graphic3d_Attribute>> cls_Graphic3d_Attribute(mod, "Graphic3d_Attribute", "Vertex attribute definition.");

// Constructors

// Fields
cls_Graphic3d_Attribute.def_readwrite("Id", &Graphic3d_Attribute::Id, "attribute identifier in vertex shader, 0 is reserved for vertex position");
cls_Graphic3d_Attribute.def_readwrite("DataType", &Graphic3d_Attribute::DataType, "vec2,vec3,vec4,vec4ub");

// Methods
cls_Graphic3d_Attribute.def("Stride", (Standard_Integer (Graphic3d_Attribute::*)() const) &Graphic3d_Attribute::Stride, "None");
cls_Graphic3d_Attribute.def_static("Stride_", (Standard_Integer (*)(const Graphic3d_TypeOfData)) &Graphic3d_Attribute::Stride, "Returns size of attribute of specified data type", py::arg("theType"));

// Enums

}