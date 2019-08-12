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
#include <OpenGl_Context.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OpenGl_Resource.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_Resource(py::module &mod){

py::class_<OpenGl_Resource, opencascade::handle<OpenGl_Resource>, Standard_Transient> cls_OpenGl_Resource(mod, "OpenGl_Resource", "Interface for OpenGl resource with following meaning: - object can be constructed at any time; - should be explicitly Initialized within active OpenGL context; - should be explicitly Released within active OpenGL context (virtual Release() method); - can be destroyed at any time. Destruction of object with unreleased GPU resources will cause leaks which will be ignored in release mode and will immediately stop program execution in debug mode using assert.");

// Fields

// Methods
cls_OpenGl_Resource.def("Release", (void (OpenGl_Resource::*)(OpenGl_Context *)) &OpenGl_Resource::Release, "Release GPU resources. Notice that implementation should be SAFE for several consecutive calls (thus should invalidate internal structures / ids to avoid multiple-free errors).", py::arg("theGlCtx"));
cls_OpenGl_Resource.def("EstimatedDataSize", (Standard_Size (OpenGl_Resource::*)() const) &OpenGl_Resource::EstimatedDataSize, "Returns estimated GPU memory usage for holding data without considering overheads and allocation alignment rules.");
cls_OpenGl_Resource.def_static("get_type_name_", (const char * (*)()) &OpenGl_Resource::get_type_name, "None");
cls_OpenGl_Resource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Resource::get_type_descriptor, "None");
cls_OpenGl_Resource.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Resource::*)() const) &OpenGl_Resource::DynamicType, "None");

// Enums

}