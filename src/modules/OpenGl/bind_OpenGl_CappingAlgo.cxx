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
#include <OpenGl_Structure.hxx>
#include <OpenGl_CappingAlgo.hxx>

void bind_OpenGl_CappingAlgo(py::module &mod){

py::class_<OpenGl_CappingAlgo> cls_OpenGl_CappingAlgo(mod, "OpenGl_CappingAlgo", "Capping surface rendering algorithm.");

// Constructors

// Fields

// Methods
cls_OpenGl_CappingAlgo.def_static("RenderCapping_", (void (*)(const opencascade::handle<OpenGl_Workspace> &, const OpenGl_Structure &)) &OpenGl_CappingAlgo::RenderCapping, "Draw capping surfaces by OpenGl for the clipping planes enabled in current context state. Depth buffer must be generated for the passed groups.", py::arg("theWorkspace"), py::arg("theStructure"));

// Enums

}