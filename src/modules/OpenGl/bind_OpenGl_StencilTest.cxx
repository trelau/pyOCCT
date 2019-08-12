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
#include <Standard_Handle.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_Context.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard.hxx>
#include <OpenGl_StencilTest.hxx>

void bind_OpenGl_StencilTest(py::module &mod){

/*
py::class_<OpenGl_StencilTest, std::unique_ptr<OpenGl_StencilTest, py::nodelete>, OpenGl_Element> cls_OpenGl_StencilTest(mod, "OpenGl_StencilTest", "None");

// Constructors
cls_OpenGl_StencilTest.def(py::init<>());

// Fields

// Methods
cls_OpenGl_StencilTest.def("Render", (void (OpenGl_StencilTest::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_StencilTest::Render, "Render primitives to the window", py::arg("theWorkspace"));
cls_OpenGl_StencilTest.def("Release", (void (OpenGl_StencilTest::*)(OpenGl_Context *)) &OpenGl_StencilTest::Release, "None", py::arg("theContext"));
cls_OpenGl_StencilTest.def("SetOptions", (void (OpenGl_StencilTest::*)(const Standard_Boolean)) &OpenGl_StencilTest::SetOptions, "None", py::arg("theIsEnabled"));
// cls_OpenGl_StencilTest.def_static("operator new_", (void * (*)(size_t)) &OpenGl_StencilTest::operator new, "None", py::arg("theSize"));
// cls_OpenGl_StencilTest.def_static("operator delete_", (void (*)(void *)) &OpenGl_StencilTest::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_StencilTest.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_StencilTest::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_StencilTest.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_StencilTest::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_StencilTest.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_StencilTest::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_StencilTest.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_StencilTest::operator delete, "None", py::arg(""), py::arg(""));

// Enums
*/

}