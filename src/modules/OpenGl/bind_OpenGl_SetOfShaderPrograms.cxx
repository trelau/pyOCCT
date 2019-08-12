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
#include <OpenGl_SetOfShaderPrograms.hxx>
#include <Standard_Type.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <Standard_TypeDef.hxx>

void bind_OpenGl_SetOfShaderPrograms(py::module &mod){

py::class_<OpenGl_SetOfShaderPrograms, opencascade::handle<OpenGl_SetOfShaderPrograms>, Standard_Transient> cls_OpenGl_SetOfShaderPrograms(mod, "OpenGl_SetOfShaderPrograms", "Alias to programs array of predefined length");

// Constructors
cls_OpenGl_SetOfShaderPrograms.def(py::init<>());

// Fields

// Methods
cls_OpenGl_SetOfShaderPrograms.def_static("get_type_name_", (const char * (*)()) &OpenGl_SetOfShaderPrograms::get_type_name, "None");
cls_OpenGl_SetOfShaderPrograms.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_SetOfShaderPrograms::get_type_descriptor, "None");
cls_OpenGl_SetOfShaderPrograms.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_SetOfShaderPrograms::*)() const) &OpenGl_SetOfShaderPrograms::DynamicType, "None");
cls_OpenGl_SetOfShaderPrograms.def("ChangeValue", (opencascade::handle<OpenGl_ShaderProgram> & (OpenGl_SetOfShaderPrograms::*)(Graphic3d_TypeOfShadingModel, Standard_Integer)) &OpenGl_SetOfShaderPrograms::ChangeValue, "Access program by index", py::arg("theShadingModel"), py::arg("theProgramBits"));

// Enums

}