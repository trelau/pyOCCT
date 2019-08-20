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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IGESGraph_Protocol.hxx>
#include <IGESGraph_LineFontDefTemplate.hxx>
#include <IGESGraph_LineFontDefPattern.hxx>
#include <IGESGraph_TextFontDef.hxx>
#include <IGESGraph_TextDisplayTemplate.hxx>
#include <IGESGraph_Color.hxx>
#include <IGESGraph_DefinitionLevel.hxx>
#include <IGESGraph_NominalSize.hxx>
#include <IGESGraph_DrawingSize.hxx>
#include <IGESGraph_DrawingUnits.hxx>
#include <IGESGraph_IntercharacterSpacing.hxx>
#include <IGESGraph_LineFontPredefined.hxx>
#include <IGESGraph_HighLight.hxx>
#include <IGESGraph_Pick.hxx>
#include <IGESGraph_UniformRectGrid.hxx>
#include <IGESGraph_ToolLineFontDefTemplate.hxx>
#include <IGESGraph_ToolLineFontDefPattern.hxx>
#include <IGESGraph_ToolTextFontDef.hxx>
#include <IGESGraph_ToolTextDisplayTemplate.hxx>
#include <IGESGraph_ToolColor.hxx>
#include <IGESGraph_ToolDefinitionLevel.hxx>
#include <IGESGraph_ToolNominalSize.hxx>
#include <IGESGraph_ToolDrawingSize.hxx>
#include <IGESGraph_ToolDrawingUnits.hxx>
#include <IGESGraph_ToolIntercharacterSpacing.hxx>
#include <IGESGraph_ToolLineFontPredefined.hxx>
#include <IGESGraph_ToolHighLight.hxx>
#include <IGESGraph_ToolPick.hxx>
#include <IGESGraph_ToolUniformRectGrid.hxx>
#include <IGESGraph_ReadWriteModule.hxx>
#include <IGESGraph_GeneralModule.hxx>
#include <IGESGraph_SpecificModule.hxx>
#include <IGESGraph.hxx>

void bind_IGESGraph(py::module &mod){

py::class_<IGESGraph, std::unique_ptr<IGESGraph>> cls_IGESGraph(mod, "IGESGraph", "This package contains the group of classes necessary to define Graphic data among Structure Entities. (e.g., Fonts, Colors, Screen management ...)");

// Constructors

// Fields

// Methods
// cls_IGESGraph.def_static("operator new_", (void * (*)(size_t)) &IGESGraph::operator new, "None", py::arg("theSize"));
// cls_IGESGraph.def_static("operator delete_", (void (*)(void *)) &IGESGraph::operator delete, "None", py::arg("theAddress"));
// cls_IGESGraph.def_static("operator new[]_", (void * (*)(size_t)) &IGESGraph::operator new[], "None", py::arg("theSize"));
// cls_IGESGraph.def_static("operator delete[]_", (void (*)(void *)) &IGESGraph::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGraph.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGraph::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGraph.def_static("operator delete_", (void (*)(void *, void *)) &IGESGraph::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESGraph.def_static("Init_", (void (*)()) &IGESGraph::Init, "Prepares dynamic data (Protocol, Modules) for this package");
cls_IGESGraph.def_static("Protocol_", (opencascade::handle<IGESGraph_Protocol> (*)()) &IGESGraph::Protocol, "Returns the Protocol for this Package");

// Enums

}