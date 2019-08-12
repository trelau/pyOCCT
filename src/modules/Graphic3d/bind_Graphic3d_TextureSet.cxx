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
#include <Graphic3d_TextureSet.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Array1.hxx>
#include <Graphic3d_TextureMap.hxx>
#include <Standard_TypeDef.hxx>

void bind_Graphic3d_TextureSet(py::module &mod){

py::class_<Graphic3d_TextureSet, opencascade::handle<Graphic3d_TextureSet>, Standard_Transient> cls_Graphic3d_TextureSet(mod, "Graphic3d_TextureSet", "Class holding array of textures to be mapped as a set.");

// Constructors
cls_Graphic3d_TextureSet.def(py::init<>());
cls_Graphic3d_TextureSet.def(py::init<Standard_Integer>(), py::arg("theNbTextures"));
cls_Graphic3d_TextureSet.def(py::init<const opencascade::handle<Graphic3d_TextureMap> &>(), py::arg("theTexture"));

// Fields

// Methods
cls_Graphic3d_TextureSet.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TextureSet::get_type_name, "None");
cls_Graphic3d_TextureSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TextureSet::get_type_descriptor, "None");
cls_Graphic3d_TextureSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TextureSet::*)() const) &Graphic3d_TextureSet::DynamicType, "None");
cls_Graphic3d_TextureSet.def("IsEmpty", (Standard_Boolean (Graphic3d_TextureSet::*)() const) &Graphic3d_TextureSet::IsEmpty, "Return TRUE if texture array is empty.");
cls_Graphic3d_TextureSet.def("Size", (Standard_Integer (Graphic3d_TextureSet::*)() const) &Graphic3d_TextureSet::Size, "Return number of textures.");
cls_Graphic3d_TextureSet.def("Lower", (Standard_Integer (Graphic3d_TextureSet::*)() const) &Graphic3d_TextureSet::Lower, "Return the lower index in texture set.");
cls_Graphic3d_TextureSet.def("Upper", (Standard_Integer (Graphic3d_TextureSet::*)() const) &Graphic3d_TextureSet::Upper, "Return the upper index in texture set.");
cls_Graphic3d_TextureSet.def("First", (const opencascade::handle<Graphic3d_TextureMap> & (Graphic3d_TextureSet::*)() const) &Graphic3d_TextureSet::First, "Return the first texture.");
cls_Graphic3d_TextureSet.def("SetFirst", (void (Graphic3d_TextureSet::*)(const opencascade::handle<Graphic3d_TextureMap> &)) &Graphic3d_TextureSet::SetFirst, "Return the first texture.", py::arg("theTexture"));
cls_Graphic3d_TextureSet.def("Value", (const opencascade::handle<Graphic3d_TextureMap> & (Graphic3d_TextureSet::*)(Standard_Integer) const) &Graphic3d_TextureSet::Value, "Return the texture at specified position within [0, Size()) range.", py::arg("theIndex"));
cls_Graphic3d_TextureSet.def("SetValue", (void (Graphic3d_TextureSet::*)(Standard_Integer, const opencascade::handle<Graphic3d_TextureMap> &)) &Graphic3d_TextureSet::SetValue, "Return the texture at specified position within [0, Size()) range.", py::arg("theIndex"), py::arg("theTexture"));

// Enums

}