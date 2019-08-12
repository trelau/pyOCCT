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
#include <OpenGl_GraphicDriver.hxx>
#include <Aspect_Window.hxx>
#include <Aspect_RenderingContext.hxx>
#include <OpenGl_Caps.hxx>
#include <OpenGl_Context.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_Window.hxx>
#include <Standard_Type.hxx>
#include <Standard.hxx>

void bind_OpenGl_Window(py::module &mod){

py::class_<OpenGl_Window, opencascade::handle<OpenGl_Window>, Standard_Transient> cls_OpenGl_Window(mod, "OpenGl_Window", "This class represents low-level wrapper over window with GL context. The window itself should be provided to constructor.");

// Constructors
cls_OpenGl_Window.def(py::init<const opencascade::handle<OpenGl_GraphicDriver> &, const opencascade::handle<Aspect_Window> &, Aspect_RenderingContext, const opencascade::handle<OpenGl_Caps> &, const opencascade::handle<OpenGl_Context> &>(), py::arg("theDriver"), py::arg("thePlatformWindow"), py::arg("theGContext"), py::arg("theCaps"), py::arg("theShareCtx"));

// Fields

// Methods
cls_OpenGl_Window.def("Resize", (void (OpenGl_Window::*)()) &OpenGl_Window::Resize, "Resizes the window.");
cls_OpenGl_Window.def("PlatformWindow", (opencascade::handle<Aspect_Window> (OpenGl_Window::*)()) &OpenGl_Window::PlatformWindow, "None");
cls_OpenGl_Window.def("Width", (Standard_Integer (OpenGl_Window::*)() const) &OpenGl_Window::Width, "None");
cls_OpenGl_Window.def("Height", (Standard_Integer (OpenGl_Window::*)() const) &OpenGl_Window::Height, "None");
cls_OpenGl_Window.def("GetGlContext", (const opencascade::handle<OpenGl_Context> & (OpenGl_Window::*)() const) &OpenGl_Window::GetGlContext, "None");
cls_OpenGl_Window.def("Init", (void (OpenGl_Window::*)()) &OpenGl_Window::Init, "Activates GL context and setup viewport.");
cls_OpenGl_Window.def("Activate", (Standard_Boolean (OpenGl_Window::*)()) &OpenGl_Window::Activate, "Makes GL context for this window active in current thread");
cls_OpenGl_Window.def("SetSwapInterval", (void (OpenGl_Window::*)()) &OpenGl_Window::SetSwapInterval, "Sets swap interval for this window according to the context's settings.");
cls_OpenGl_Window.def_static("get_type_name_", (const char * (*)()) &OpenGl_Window::get_type_name, "None");
cls_OpenGl_Window.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Window::get_type_descriptor, "None");
cls_OpenGl_Window.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Window::*)() const) &OpenGl_Window::DynamicType, "None");
// cls_OpenGl_Window.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Window::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Window.def_static("operator delete_", (void (*)(void *)) &OpenGl_Window::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Window.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Window::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Window.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Window::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Window.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Window::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Window.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Window::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}