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
#include <Standard_Handle.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_Element.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_RenderFilter.hxx>
#include <Standard.hxx>

void bind_OpenGl_Element(py::module &mod){

py::class_<OpenGl_Element, std::unique_ptr<OpenGl_Element, py::nodelete>> cls_OpenGl_Element(mod, "OpenGl_Element", "Base interface for drawable elements.");

// Fields

// Methods
cls_OpenGl_Element.def("Render", (void (OpenGl_Element::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_Element::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_Element.def("Release", (void (OpenGl_Element::*)(OpenGl_Context *)) &OpenGl_Element::Release, "Release GPU resources. Pointer to the context is used because this method might be called when the context is already being destroyed and usage of a handle would be unsafe", py::arg("theContext"));
cls_OpenGl_Element.def("IsFillDrawMode", (Standard_Boolean (OpenGl_Element::*)() const) &OpenGl_Element::IsFillDrawMode, "Return TRUE if primitive type generates shaded triangulation (to be used in filters).");
cls_OpenGl_Element.def("RenderFiltered", (Standard_Boolean (OpenGl_Element::*)(const opencascade::handle<OpenGl_Workspace> &, const opencascade::handle<OpenGl_RenderFilter> &) const) &OpenGl_Element::RenderFiltered, "Render element if it passes the filtering procedure. This method should be used for elements which can be used in scope of rendering algorithms. E.g. elements of groups during recursive rendering. If render filter is null, pure rendering is performed.", py::arg("theWorkspace"), py::arg("theFilter"));
// cls_OpenGl_Element.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Element::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Element.def_static("operator delete_", (void (*)(void *)) &OpenGl_Element::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Element.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Element::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Element.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Element::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Element.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Element::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Element.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Element::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}