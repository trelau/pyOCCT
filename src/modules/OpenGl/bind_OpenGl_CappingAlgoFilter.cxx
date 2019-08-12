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
#include <OpenGl_CappingAlgo.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_CappingAlgoFilter(py::module &mod){

/*
py::class_<OpenGl_CappingAlgoFilter, opencascade::handle<OpenGl_CappingAlgoFilter>, OpenGl_RenderFilter> cls_OpenGl_CappingAlgoFilter(mod, "OpenGl_CappingAlgoFilter", "Graphical capping rendering algorithm filter. Filters out everything except shaded primitives.");

// Constructors
cls_OpenGl_CappingAlgoFilter.def(py::init<>());

// Fields

// Methods
cls_OpenGl_CappingAlgoFilter.def("SetPreviousFilter", (void (OpenGl_CappingAlgoFilter::*)(const opencascade::handle<OpenGl_RenderFilter> &)) &OpenGl_CappingAlgoFilter::SetPreviousFilter, "Sets the current active filter in workspace.", py::arg("thePrevFitler"));
cls_OpenGl_CappingAlgoFilter.def("ShouldRender", (Standard_Boolean (OpenGl_CappingAlgoFilter::*)(const opencascade::handle<OpenGl_Workspace> &, const OpenGl_Element *)) &OpenGl_CappingAlgoFilter::ShouldRender, "Checks whether the element can be rendered or not.", py::arg("theWorkspace"), py::arg("theGlElement"));
cls_OpenGl_CappingAlgoFilter.def_static("get_type_name_", (const char * (*)()) &OpenGl_CappingAlgoFilter::get_type_name, "None");
cls_OpenGl_CappingAlgoFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_CappingAlgoFilter::get_type_descriptor, "None");
cls_OpenGl_CappingAlgoFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_CappingAlgoFilter::*)() const) &OpenGl_CappingAlgoFilter::DynamicType, "None");

// Enums
*/

}