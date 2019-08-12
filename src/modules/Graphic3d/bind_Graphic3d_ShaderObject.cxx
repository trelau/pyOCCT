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
#include <Graphic3d_TypeOfShaderObject.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_Path.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_ShaderObject.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_ShaderObject(py::module &mod){

py::class_<Graphic3d_ShaderObject, opencascade::handle<Graphic3d_ShaderObject>, Standard_Transient> cls_Graphic3d_ShaderObject(mod, "Graphic3d_ShaderObject", "This class is responsible for managing shader objects.");

// Constructors

// Fields

// Methods
cls_Graphic3d_ShaderObject.def("IsDone", (Standard_Boolean (Graphic3d_ShaderObject::*)() const) &Graphic3d_ShaderObject::IsDone, "Checks if the shader object is valid or not.");
cls_Graphic3d_ShaderObject.def("Path", (const OSD_Path & (Graphic3d_ShaderObject::*)() const) &Graphic3d_ShaderObject::Path, "Returns the full path to the shader source.");
cls_Graphic3d_ShaderObject.def("Source", (const TCollection_AsciiString & (Graphic3d_ShaderObject::*)() const) &Graphic3d_ShaderObject::Source, "Returns the source code of the shader object.");
cls_Graphic3d_ShaderObject.def("Type", (Graphic3d_TypeOfShaderObject (Graphic3d_ShaderObject::*)() const) &Graphic3d_ShaderObject::Type, "Returns type of the shader object.");
cls_Graphic3d_ShaderObject.def("GetId", (const TCollection_AsciiString & (Graphic3d_ShaderObject::*)() const) &Graphic3d_ShaderObject::GetId, "Returns unique ID used to manage resource in graphic driver.");
cls_Graphic3d_ShaderObject.def_static("CreateFromFile_", (opencascade::handle<Graphic3d_ShaderObject> (*)(const Graphic3d_TypeOfShaderObject, const TCollection_AsciiString &)) &Graphic3d_ShaderObject::CreateFromFile, "Creates new shader object from specified file.", py::arg("theType"), py::arg("thePath"));
cls_Graphic3d_ShaderObject.def_static("CreateFromSource_", (opencascade::handle<Graphic3d_ShaderObject> (*)(const Graphic3d_TypeOfShaderObject, const TCollection_AsciiString &)) &Graphic3d_ShaderObject::CreateFromSource, "Creates new shader object from specified source.", py::arg("theType"), py::arg("theSource"));
cls_Graphic3d_ShaderObject.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ShaderObject::get_type_name, "None");
cls_Graphic3d_ShaderObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ShaderObject::get_type_descriptor, "None");
cls_Graphic3d_ShaderObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ShaderObject::*)() const) &Graphic3d_ShaderObject::DynamicType, "None");

// Enums

}