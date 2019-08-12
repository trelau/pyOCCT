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
#include <OpenGl_Resource.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_NamedResource.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>

void bind_OpenGl_NamedResource(py::module &mod){

py::class_<OpenGl_NamedResource, opencascade::handle<OpenGl_NamedResource>, OpenGl_Resource> cls_OpenGl_NamedResource(mod, "OpenGl_NamedResource", "Named resource object.");

// Fields

// Methods
cls_OpenGl_NamedResource.def_static("get_type_name_", (const char * (*)()) &OpenGl_NamedResource::get_type_name, "None");
cls_OpenGl_NamedResource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_NamedResource::get_type_descriptor, "None");
cls_OpenGl_NamedResource.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_NamedResource::*)() const) &OpenGl_NamedResource::DynamicType, "None");
cls_OpenGl_NamedResource.def("ResourceId", (const TCollection_AsciiString & (OpenGl_NamedResource::*)() const) &OpenGl_NamedResource::ResourceId, "Return resource name.");

// Enums

}