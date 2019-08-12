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

void bind_IGESGraph_TextDisplayTemplate(py::module &);
void bind_IGESGraph_Array1OfTextDisplayTemplate(py::module &);
void bind_IGESGraph_HArray1OfTextDisplayTemplate(py::module &);
void bind_IGESGraph_TextFontDef(py::module &);
void bind_IGESGraph_Array1OfTextFontDef(py::module &);
void bind_IGESGraph_HArray1OfTextFontDef(py::module &);
void bind_IGESGraph_Color(py::module &);
void bind_IGESGraph_Array1OfColor(py::module &);
void bind_IGESGraph_HArray1OfColor(py::module &);
void bind_IGESGraph(py::module &);
void bind_IGESGraph_DefinitionLevel(py::module &);
void bind_IGESGraph_DrawingSize(py::module &);
void bind_IGESGraph_DrawingUnits(py::module &);
void bind_IGESGraph_GeneralModule(py::module &);
void bind_IGESGraph_HighLight(py::module &);
void bind_IGESGraph_IntercharacterSpacing(py::module &);
void bind_IGESGraph_LineFontDefPattern(py::module &);
void bind_IGESGraph_LineFontDefTemplate(py::module &);
void bind_IGESGraph_LineFontPredefined(py::module &);
void bind_IGESGraph_NominalSize(py::module &);
void bind_IGESGraph_Pick(py::module &);
void bind_IGESGraph_Protocol(py::module &);
void bind_IGESGraph_ReadWriteModule(py::module &);
void bind_IGESGraph_SpecificModule(py::module &);
void bind_IGESGraph_ToolColor(py::module &);
void bind_IGESGraph_ToolDefinitionLevel(py::module &);
void bind_IGESGraph_ToolDrawingSize(py::module &);
void bind_IGESGraph_ToolDrawingUnits(py::module &);
void bind_IGESGraph_ToolHighLight(py::module &);
void bind_IGESGraph_ToolIntercharacterSpacing(py::module &);
void bind_IGESGraph_ToolLineFontDefPattern(py::module &);
void bind_IGESGraph_ToolLineFontDefTemplate(py::module &);
void bind_IGESGraph_ToolLineFontPredefined(py::module &);
void bind_IGESGraph_ToolNominalSize(py::module &);
void bind_IGESGraph_ToolPick(py::module &);
void bind_IGESGraph_ToolTextDisplayTemplate(py::module &);
void bind_IGESGraph_ToolTextFontDef(py::module &);
void bind_IGESGraph_ToolUniformRectGrid(py::module &);
void bind_IGESGraph_UniformRectGrid(py::module &);

PYBIND11_MODULE(IGESGraph, mod) {

py::module::import("OCCT.IGESData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.IGESBasic");
py::module::import("OCCT.Interface");
py::module::import("OCCT.Message");

bind_IGESGraph_TextDisplayTemplate(mod);
bind_IGESGraph_Array1OfTextDisplayTemplate(mod);
bind_IGESGraph_HArray1OfTextDisplayTemplate(mod);
bind_IGESGraph_TextFontDef(mod);
bind_IGESGraph_Array1OfTextFontDef(mod);
bind_IGESGraph_HArray1OfTextFontDef(mod);
bind_IGESGraph_Color(mod);
bind_IGESGraph_Array1OfColor(mod);
bind_IGESGraph_HArray1OfColor(mod);
bind_IGESGraph(mod);
bind_IGESGraph_DefinitionLevel(mod);
bind_IGESGraph_DrawingSize(mod);
bind_IGESGraph_DrawingUnits(mod);
bind_IGESGraph_GeneralModule(mod);
bind_IGESGraph_HighLight(mod);
bind_IGESGraph_IntercharacterSpacing(mod);
bind_IGESGraph_LineFontDefPattern(mod);
bind_IGESGraph_LineFontDefTemplate(mod);
bind_IGESGraph_LineFontPredefined(mod);
bind_IGESGraph_NominalSize(mod);
bind_IGESGraph_Pick(mod);
bind_IGESGraph_Protocol(mod);
bind_IGESGraph_ReadWriteModule(mod);
bind_IGESGraph_SpecificModule(mod);
bind_IGESGraph_ToolColor(mod);
bind_IGESGraph_ToolDefinitionLevel(mod);
bind_IGESGraph_ToolDrawingSize(mod);
bind_IGESGraph_ToolDrawingUnits(mod);
bind_IGESGraph_ToolHighLight(mod);
bind_IGESGraph_ToolIntercharacterSpacing(mod);
bind_IGESGraph_ToolLineFontDefPattern(mod);
bind_IGESGraph_ToolLineFontDefTemplate(mod);
bind_IGESGraph_ToolLineFontPredefined(mod);
bind_IGESGraph_ToolNominalSize(mod);
bind_IGESGraph_ToolPick(mod);
bind_IGESGraph_ToolTextDisplayTemplate(mod);
bind_IGESGraph_ToolTextFontDef(mod);
bind_IGESGraph_ToolUniformRectGrid(mod);
bind_IGESGraph_UniformRectGrid(mod);

}
