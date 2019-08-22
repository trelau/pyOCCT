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
#include <Graphic3d_AspectMarker3d.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_TextureSet.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <OpenGl_Workspace.hxx>
#include <Graphic3d_MarkerImage.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <Graphic3d_Vec4.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard.hxx>
#include <OpenGl_AspectMarker.hxx>

void bind_OpenGl_AspectMarker(py::module &mod){

py::class_<OpenGl_AspectMarker, OpenGl_Element> cls_OpenGl_AspectMarker(mod, "OpenGl_AspectMarker", "The element holding Graphic3d_AspectMarker3d.");

// Constructors
cls_OpenGl_AspectMarker.def(py::init<>());
cls_OpenGl_AspectMarker.def(py::init<const opencascade::handle<Graphic3d_AspectMarker3d> &>(), py::arg("theAspect"));

// Fields

// Methods
cls_OpenGl_AspectMarker.def("Aspect", (const opencascade::handle<Graphic3d_AspectMarker3d> & (OpenGl_AspectMarker::*)() const) &OpenGl_AspectMarker::Aspect, "Return the aspect.");
cls_OpenGl_AspectMarker.def("SetAspect", (void (OpenGl_AspectMarker::*)(const opencascade::handle<Graphic3d_AspectMarker3d> &)) &OpenGl_AspectMarker::SetAspect, "Assign new aspect.", py::arg("theAspect"));
cls_OpenGl_AspectMarker.def("MarkerSize", (Standard_ShortReal (OpenGl_AspectMarker::*)() const) &OpenGl_AspectMarker::MarkerSize, "Returns marker size");
cls_OpenGl_AspectMarker.def("SpriteRes", (const opencascade::handle<OpenGl_TextureSet> & (OpenGl_AspectMarker::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_AspectMarker::SpriteRes, "Init and return OpenGl point sprite resource.", py::arg("theCtx"));
cls_OpenGl_AspectMarker.def("SpriteHighlightRes", (const opencascade::handle<OpenGl_TextureSet> & (OpenGl_AspectMarker::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_AspectMarker::SpriteHighlightRes, "Init and return OpenGl highlight point sprite resource.", py::arg("theCtx"));
cls_OpenGl_AspectMarker.def("ShaderProgramRes", (const opencascade::handle<OpenGl_ShaderProgram> & (OpenGl_AspectMarker::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_AspectMarker::ShaderProgramRes, "Init and return OpenGl shader program resource.", py::arg("theCtx"));
cls_OpenGl_AspectMarker.def("Render", (void (OpenGl_AspectMarker::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_AspectMarker::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_AspectMarker.def("Release", (void (OpenGl_AspectMarker::*)(OpenGl_Context *)) &OpenGl_AspectMarker::Release, "None", py::arg("theContext"));
// cls_OpenGl_AspectMarker.def_static("operator new_", (void * (*)(size_t)) &OpenGl_AspectMarker::operator new, "None", py::arg("theSize"));
// cls_OpenGl_AspectMarker.def_static("operator delete_", (void (*)(void *)) &OpenGl_AspectMarker::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_AspectMarker.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_AspectMarker::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_AspectMarker.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_AspectMarker::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_AspectMarker.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_AspectMarker::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_AspectMarker.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_AspectMarker::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}