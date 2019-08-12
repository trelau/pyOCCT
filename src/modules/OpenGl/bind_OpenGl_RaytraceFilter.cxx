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
#include <OpenGl_RenderFilter.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_Element.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_RaytraceFilter(py::module &mod){

/*
py::class_<OpenGl_RaytraceFilter, opencascade::handle<OpenGl_RaytraceFilter>, OpenGl_RenderFilter> cls_OpenGl_RaytraceFilter(mod, "OpenGl_RaytraceFilter", "Graphical ray-tracing filter. Filters out all raytracable structures.");

// Constructors
cls_OpenGl_RaytraceFilter.def(py::init<>());

// Fields

// Methods
cls_OpenGl_RaytraceFilter.def("PrevRenderFilter", (const opencascade::handle<OpenGl_RenderFilter> & (OpenGl_RaytraceFilter::*)()) &OpenGl_RaytraceFilter::PrevRenderFilter, "Returns the previously set filter.");
cls_OpenGl_RaytraceFilter.def("SetPrevRenderFilter", (void (OpenGl_RaytraceFilter::*)(const opencascade::handle<OpenGl_RenderFilter> &)) &OpenGl_RaytraceFilter::SetPrevRenderFilter, "Remembers the previously set filter.", py::arg("theFilter"));
cls_OpenGl_RaytraceFilter.def("ShouldRender", (Standard_Boolean (OpenGl_RaytraceFilter::*)(const opencascade::handle<OpenGl_Workspace> &, const OpenGl_Element *)) &OpenGl_RaytraceFilter::ShouldRender, "Checks whether the element can be rendered or not.", py::arg("theWorkspace"), py::arg("theElement"));
cls_OpenGl_RaytraceFilter.def_static("get_type_name_", (const char * (*)()) &OpenGl_RaytraceFilter::get_type_name, "None");
cls_OpenGl_RaytraceFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_RaytraceFilter::get_type_descriptor, "None");
cls_OpenGl_RaytraceFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_RaytraceFilter::*)() const) &OpenGl_RaytraceFilter::DynamicType, "None");

// Enums
*/

}