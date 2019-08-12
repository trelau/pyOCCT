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
#include <OpenGl_TextureSet.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Array1.hxx>
#include <OpenGl_Texture.hxx>
#include <Standard_TypeDef.hxx>

void bind_OpenGl_TextureSet(py::module &mod){

py::class_<OpenGl_TextureSet, opencascade::handle<OpenGl_TextureSet>, Standard_Transient> cls_OpenGl_TextureSet(mod, "OpenGl_TextureSet", "Class holding array of textures to be mapped as a set.");

// Constructors
cls_OpenGl_TextureSet.def(py::init<>());
cls_OpenGl_TextureSet.def(py::init<Standard_Integer>(), py::arg("theNbTextures"));
cls_OpenGl_TextureSet.def(py::init<const opencascade::handle<OpenGl_Texture> &>(), py::arg("theTexture"));

// Fields

// Methods
cls_OpenGl_TextureSet.def_static("get_type_name_", (const char * (*)()) &OpenGl_TextureSet::get_type_name, "None");
cls_OpenGl_TextureSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_TextureSet::get_type_descriptor, "None");
cls_OpenGl_TextureSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::DynamicType, "None");
cls_OpenGl_TextureSet.def("IsEmpty", (Standard_Boolean (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::IsEmpty, "Return TRUE if texture array is empty.");
cls_OpenGl_TextureSet.def("Size", (Standard_Integer (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::Size, "Return number of textures.");
cls_OpenGl_TextureSet.def("Lower", (Standard_Integer (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::Lower, "Return the lower index in texture set.");
cls_OpenGl_TextureSet.def("Upper", (Standard_Integer (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::Upper, "Return the upper index in texture set.");
cls_OpenGl_TextureSet.def("First", (const opencascade::handle<OpenGl_Texture> & (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::First, "Return the first texture.");
cls_OpenGl_TextureSet.def("ChangeFirst", (opencascade::handle<OpenGl_Texture> & (OpenGl_TextureSet::*)()) &OpenGl_TextureSet::ChangeFirst, "Return the first texture.");
cls_OpenGl_TextureSet.def("Value", (const opencascade::handle<OpenGl_Texture> & (OpenGl_TextureSet::*)(Standard_Integer) const) &OpenGl_TextureSet::Value, "Return the texture at specified position within [0, Size()) range.", py::arg("theIndex"));
cls_OpenGl_TextureSet.def("ChangeValue", (opencascade::handle<OpenGl_Texture> & (OpenGl_TextureSet::*)(Standard_Integer)) &OpenGl_TextureSet::ChangeValue, "Return the texture at specified position within [0, Size()) range.", py::arg("theIndex"));
cls_OpenGl_TextureSet.def("IsModulate", (bool (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::IsModulate, "Return TRUE if texture color modulation has been enabled for the first texture or if texture is not set at all.");

// Enums

}