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
#include <Graphic3d_AspectFillArea3d.hxx>
#include <OpenGl_AspectLine.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <OpenGl_TextureSet.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <OpenGl_Workspace.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_TextureSet.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard.hxx>
#include <OpenGl_AspectFace.hxx>

void bind_OpenGl_AspectFace(py::module &mod){

py::class_<OpenGl_AspectFace, std::unique_ptr<OpenGl_AspectFace>, OpenGl_Element> cls_OpenGl_AspectFace(mod, "OpenGl_AspectFace", "The element holding Graphic3d_AspectFillArea3d.");

// Constructors
cls_OpenGl_AspectFace.def(py::init<>());
cls_OpenGl_AspectFace.def(py::init<const opencascade::handle<Graphic3d_AspectFillArea3d> &>(), py::arg("theAspect"));

// Fields

// Methods
cls_OpenGl_AspectFace.def("Aspect", (const opencascade::handle<Graphic3d_AspectFillArea3d> & (OpenGl_AspectFace::*)() const) &OpenGl_AspectFace::Aspect, "Return aspect.");
cls_OpenGl_AspectFace.def("SetAspect", (void (OpenGl_AspectFace::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &OpenGl_AspectFace::SetAspect, "Assign parameters.", py::arg("theAspect"));
cls_OpenGl_AspectFace.def("SetAspectEdge", (void (OpenGl_AspectFace::*)(const OpenGl_AspectLine *)) &OpenGl_AspectFace::SetAspectEdge, "Set edge aspect.", py::arg("theAspectEdge"));
cls_OpenGl_AspectFace.def("AspectEdge", (const OpenGl_AspectLine * (OpenGl_AspectFace::*)() const) &OpenGl_AspectFace::AspectEdge, "Returns edge aspect.");
cls_OpenGl_AspectFace.def("ShadingModel", (Graphic3d_TypeOfShadingModel (OpenGl_AspectFace::*)() const) &OpenGl_AspectFace::ShadingModel, "Returns Shading Model.");
cls_OpenGl_AspectFace.def("SetNoLighting", (void (OpenGl_AspectFace::*)()) &OpenGl_AspectFace::SetNoLighting, "Set if lighting should be disabled or not.");
cls_OpenGl_AspectFace.def("TextureSet", (const opencascade::handle<OpenGl_TextureSet> & (OpenGl_AspectFace::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_AspectFace::TextureSet, "Returns textures map.", py::arg("theCtx"));
cls_OpenGl_AspectFace.def("ShaderProgramRes", (const opencascade::handle<OpenGl_ShaderProgram> & (OpenGl_AspectFace::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_AspectFace::ShaderProgramRes, "Init and return OpenGl shader program resource.", py::arg("theCtx"));
cls_OpenGl_AspectFace.def("Render", (void (OpenGl_AspectFace::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_AspectFace::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_AspectFace.def("Release", (void (OpenGl_AspectFace::*)(OpenGl_Context *)) &OpenGl_AspectFace::Release, "None", py::arg("theContext"));
// cls_OpenGl_AspectFace.def_static("operator new_", (void * (*)(size_t)) &OpenGl_AspectFace::operator new, "None", py::arg("theSize"));
// cls_OpenGl_AspectFace.def_static("operator delete_", (void (*)(void *)) &OpenGl_AspectFace::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_AspectFace.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_AspectFace::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_AspectFace.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_AspectFace::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_AspectFace.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_AspectFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_AspectFace.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_AspectFace::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}