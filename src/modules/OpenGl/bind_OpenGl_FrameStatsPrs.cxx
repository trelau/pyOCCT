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
#include <OpenGl_Text.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_Context.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <OpenGl_AspectText.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <OpenGl_FrameStats.hxx>
#include <OpenGl_FrameStatsPrs.hxx>

void bind_OpenGl_FrameStatsPrs(py::module &mod){

py::class_<OpenGl_FrameStatsPrs, OpenGl_Text> cls_OpenGl_FrameStatsPrs(mod, "OpenGl_FrameStatsPrs", "Element rendering frame statistics.");

// Constructors
cls_OpenGl_FrameStatsPrs.def(py::init<>());

// Fields

// Methods
cls_OpenGl_FrameStatsPrs.def("Render", (void (OpenGl_FrameStatsPrs::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_FrameStatsPrs::Render, "Render element.", py::arg("theWorkspace"));
cls_OpenGl_FrameStatsPrs.def("Release", (void (OpenGl_FrameStatsPrs::*)(OpenGl_Context *)) &OpenGl_FrameStatsPrs::Release, "Release OpenGL resources.", py::arg("theCtx"));
cls_OpenGl_FrameStatsPrs.def("Update", (void (OpenGl_FrameStatsPrs::*)(const opencascade::handle<OpenGl_Workspace> &)) &OpenGl_FrameStatsPrs::Update, "Update text.", py::arg("theWorkspace"));
cls_OpenGl_FrameStatsPrs.def("SetTextAspect", (void (OpenGl_FrameStatsPrs::*)(const opencascade::handle<Graphic3d_AspectText3d> &)) &OpenGl_FrameStatsPrs::SetTextAspect, "Assign text aspect.", py::arg("theAspect"));

// Enums

}