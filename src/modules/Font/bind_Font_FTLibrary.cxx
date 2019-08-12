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
#include <Font_FTLibrary.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_Font_FTLibrary(py::module &mod){

py::class_<Font_FTLibrary, opencascade::handle<Font_FTLibrary>, Standard_Transient> cls_Font_FTLibrary(mod, "Font_FTLibrary", "Wrapper over FT_Library. Provides access to FreeType library.");

// Constructors
cls_Font_FTLibrary.def(py::init<>());

// Fields

// Methods
cls_Font_FTLibrary.def("IsValid", (bool (Font_FTLibrary::*)() const) &Font_FTLibrary::IsValid, "This method should always return true.");
// cls_Font_FTLibrary.def("Instance", (FT_Library (Font_FTLibrary::*)() const) &Font_FTLibrary::Instance, "Access FT_Library instance.");
cls_Font_FTLibrary.def_static("get_type_name_", (const char * (*)()) &Font_FTLibrary::get_type_name, "None");
cls_Font_FTLibrary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FTLibrary::get_type_descriptor, "None");
cls_Font_FTLibrary.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FTLibrary::*)() const) &Font_FTLibrary::DynamicType, "None");

// Enums

}