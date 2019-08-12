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
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ShaderVariable.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_ShaderVariable(py::module &mod){

py::class_<Graphic3d_ShaderVariable, opencascade::handle<Graphic3d_ShaderVariable>, Standard_Transient> cls_Graphic3d_ShaderVariable(mod, "Graphic3d_ShaderVariable", "Describes custom uniform shader variable.");

// Constructors

// Fields

// Methods
cls_Graphic3d_ShaderVariable.def("Name", (const TCollection_AsciiString & (Graphic3d_ShaderVariable::*)() const) &Graphic3d_ShaderVariable::Name, "Returns name of shader variable.");
cls_Graphic3d_ShaderVariable.def("IsDone", (Standard_Boolean (Graphic3d_ShaderVariable::*)() const) &Graphic3d_ShaderVariable::IsDone, "Checks if the shader variable is valid or not.");
cls_Graphic3d_ShaderVariable.def("Value", (Graphic3d_ValueInterface * (Graphic3d_ShaderVariable::*)()) &Graphic3d_ShaderVariable::Value, "Returns interface of shader variable value.");
cls_Graphic3d_ShaderVariable.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ShaderVariable::get_type_name, "None");
cls_Graphic3d_ShaderVariable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ShaderVariable::get_type_descriptor, "None");
cls_Graphic3d_ShaderVariable.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ShaderVariable::*)() const) &Graphic3d_ShaderVariable::DynamicType, "None");

// Enums

}