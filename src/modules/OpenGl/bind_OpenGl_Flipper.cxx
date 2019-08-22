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
#include <OpenGl_Element.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_Context.hxx>
#include <Standard.hxx>
#include <OpenGl_Vec.hxx>
#include <OpenGl_Flipper.hxx>

void bind_OpenGl_Flipper(py::module &mod){

py::class_<OpenGl_Flipper, OpenGl_Element> cls_OpenGl_Flipper(mod, "OpenGl_Flipper", "Being rendered, the elements modifies current model-view matrix such that the axes of the specified reference system (in model space) become oriented in the following way: - X - heads to the right side of view. - Y - heads to the up side of view. - N(Z) - heads towards the screen. Originally, this element serves for need of flipping the 3D text of dimension presentations.");

// Constructors
cls_OpenGl_Flipper.def(py::init<const gp_Ax2 &>(), py::arg("theReferenceSystem"));

// Fields

// Methods
cls_OpenGl_Flipper.def("SetOptions", (void (OpenGl_Flipper::*)(const Standard_Boolean)) &OpenGl_Flipper::SetOptions, "Set options for the element.", py::arg("theIsEnabled"));
cls_OpenGl_Flipper.def("Render", (void (OpenGl_Flipper::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_Flipper::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_Flipper.def("Release", (void (OpenGl_Flipper::*)(OpenGl_Context *)) &OpenGl_Flipper::Release, "None", py::arg("theCtx"));
// cls_OpenGl_Flipper.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Flipper::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Flipper.def_static("operator delete_", (void (*)(void *)) &OpenGl_Flipper::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Flipper.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Flipper::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Flipper.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Flipper::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Flipper.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Flipper::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Flipper.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Flipper::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}