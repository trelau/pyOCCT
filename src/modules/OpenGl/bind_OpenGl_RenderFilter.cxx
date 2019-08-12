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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_Element.hxx>
#include <OpenGl_RenderFilter.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_RenderFilter(py::module &mod){

py::class_<OpenGl_RenderFilter, opencascade::handle<OpenGl_RenderFilter>, Standard_Transient> cls_OpenGl_RenderFilter(mod, "OpenGl_RenderFilter", "Base class for defining element rendering filters. This class can be used in pair with advance rendering passes, and for disabling rendering (setting up) graphical aspects.");

// Fields

// Methods
cls_OpenGl_RenderFilter.def("ShouldRender", (Standard_Boolean (OpenGl_RenderFilter::*)(const opencascade::handle<OpenGl_Workspace> &, const OpenGl_Element *)) &OpenGl_RenderFilter::ShouldRender, "Checks whether the element can be rendered or not.", py::arg("theWorkspace"), py::arg("theElement"));
cls_OpenGl_RenderFilter.def_static("get_type_name_", (const char * (*)()) &OpenGl_RenderFilter::get_type_name, "None");
cls_OpenGl_RenderFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_RenderFilter::get_type_descriptor, "None");
cls_OpenGl_RenderFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_RenderFilter::*)() const) &OpenGl_RenderFilter::DynamicType, "None");

// Enums

}