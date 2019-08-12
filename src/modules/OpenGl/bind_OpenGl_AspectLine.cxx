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
#include <Graphic3d_AspectLine3d.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_Workspace.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard.hxx>
#include <OpenGl_AspectLine.hxx>

void bind_OpenGl_AspectLine(py::module &mod){

py::class_<OpenGl_AspectLine, std::unique_ptr<OpenGl_AspectLine, Deleter<OpenGl_AspectLine>>, OpenGl_Element> cls_OpenGl_AspectLine(mod, "OpenGl_AspectLine", "The element holding Graphic3d_AspectLine3d.");

// Constructors
cls_OpenGl_AspectLine.def(py::init<>());
cls_OpenGl_AspectLine.def(py::init<const opencascade::handle<Graphic3d_AspectLine3d> &>(), py::arg("theAspect"));

// Fields

// Methods
cls_OpenGl_AspectLine.def("Aspect", (const opencascade::handle<Graphic3d_AspectLine3d> & (OpenGl_AspectLine::*)() const) &OpenGl_AspectLine::Aspect, "Return line aspect.");
cls_OpenGl_AspectLine.def("SetAspect", (void (OpenGl_AspectLine::*)(const opencascade::handle<Graphic3d_AspectLine3d> &)) &OpenGl_AspectLine::SetAspect, "Assign line aspect.", py::arg("theAspect"));
cls_OpenGl_AspectLine.def("ShaderProgramRes", (const opencascade::handle<OpenGl_ShaderProgram> & (OpenGl_AspectLine::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_AspectLine::ShaderProgramRes, "Init and return OpenGl shader program resource.", py::arg("theCtx"));
cls_OpenGl_AspectLine.def("Render", (void (OpenGl_AspectLine::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_AspectLine::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_AspectLine.def("Release", (void (OpenGl_AspectLine::*)(OpenGl_Context *)) &OpenGl_AspectLine::Release, "None", py::arg("theContext"));
// cls_OpenGl_AspectLine.def_static("operator new_", (void * (*)(size_t)) &OpenGl_AspectLine::operator new, "None", py::arg("theSize"));
// cls_OpenGl_AspectLine.def_static("operator delete_", (void (*)(void *)) &OpenGl_AspectLine::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_AspectLine.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_AspectLine::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_AspectLine.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_AspectLine::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_AspectLine.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_AspectLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_AspectLine.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_AspectLine::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}