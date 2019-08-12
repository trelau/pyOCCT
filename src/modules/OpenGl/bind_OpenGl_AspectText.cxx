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
#include <Graphic3d_AspectText3d.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_Workspace.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard.hxx>
#include <OpenGl_AspectText.hxx>

void bind_OpenGl_AspectText(py::module &mod){

py::class_<OpenGl_AspectText, std::unique_ptr<OpenGl_AspectText, Deleter<OpenGl_AspectText>>, OpenGl_Element> cls_OpenGl_AspectText(mod, "OpenGl_AspectText", "Text representation parameters");

// Constructors
cls_OpenGl_AspectText.def(py::init<>());
cls_OpenGl_AspectText.def(py::init<const opencascade::handle<Graphic3d_AspectText3d> &>(), py::arg("theAspect"));

// Fields

// Methods
cls_OpenGl_AspectText.def("Aspect", (const opencascade::handle<Graphic3d_AspectText3d> & (OpenGl_AspectText::*)() const) &OpenGl_AspectText::Aspect, "Return text aspect.");
cls_OpenGl_AspectText.def("SetAspect", (void (OpenGl_AspectText::*)(const opencascade::handle<Graphic3d_AspectText3d> &)) &OpenGl_AspectText::SetAspect, "Assign new parameters.", py::arg("theAspect"));
cls_OpenGl_AspectText.def("ShaderProgramRes", (const opencascade::handle<OpenGl_ShaderProgram> & (OpenGl_AspectText::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_AspectText::ShaderProgramRes, "Init and return OpenGl shader program resource.", py::arg("theCtx"));
cls_OpenGl_AspectText.def("Render", (void (OpenGl_AspectText::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_AspectText::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_AspectText.def("Release", (void (OpenGl_AspectText::*)(OpenGl_Context *)) &OpenGl_AspectText::Release, "None", py::arg("theContext"));
// cls_OpenGl_AspectText.def_static("operator new_", (void * (*)(size_t)) &OpenGl_AspectText::operator new, "None", py::arg("theSize"));
// cls_OpenGl_AspectText.def_static("operator delete_", (void (*)(void *)) &OpenGl_AspectText::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_AspectText.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_AspectText::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_AspectText.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_AspectText::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_AspectText.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_AspectText::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_AspectText.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_AspectText::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}