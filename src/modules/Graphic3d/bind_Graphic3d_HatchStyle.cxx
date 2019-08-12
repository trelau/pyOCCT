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
#include <Graphic3d_HatchStyle.hxx>
#include <Standard_Type.hxx>
#include <Image_PixMap.hxx>
#include <Aspect_HatchStyle.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Buffer.hxx>

void bind_Graphic3d_HatchStyle(py::module &mod){

py::class_<Graphic3d_HatchStyle, opencascade::handle<Graphic3d_HatchStyle>, Standard_Transient> cls_Graphic3d_HatchStyle(mod, "Graphic3d_HatchStyle", "A class that provides an API to use standard OCCT hatch styles defined in Aspect_HatchStyle enum or to create custom styles from a user-defined bitmap");

// Constructors
cls_Graphic3d_HatchStyle.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("thePattern"));
cls_Graphic3d_HatchStyle.def(py::init<const Aspect_HatchStyle>(), py::arg("theType"));

// Fields

// Methods
cls_Graphic3d_HatchStyle.def_static("get_type_name_", (const char * (*)()) &Graphic3d_HatchStyle::get_type_name, "None");
cls_Graphic3d_HatchStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_HatchStyle::get_type_descriptor, "None");
cls_Graphic3d_HatchStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_HatchStyle::*)() const) &Graphic3d_HatchStyle::DynamicType, "None");
cls_Graphic3d_HatchStyle.def("Pattern", (const Standard_Byte * (Graphic3d_HatchStyle::*)() const) &Graphic3d_HatchStyle::Pattern, "Returns the pattern of custom hatch style");
cls_Graphic3d_HatchStyle.def("HatchType", (Standard_Integer (Graphic3d_HatchStyle::*)() const) &Graphic3d_HatchStyle::HatchType, "In case if predefined OCCT style is used, returns index in Aspect_HatchStyle enumeration. If the style is custom, returns unique index of the style");

// Enums

}