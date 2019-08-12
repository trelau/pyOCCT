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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IntPatch_Line.hxx>
#include <IntPatch_Point.hxx>
#include <IntPatch_WLine.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <GeomInt_LineConstructor.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <GeomInt_LineTool.hxx>

void bind_GeomInt_LineTool(py::module &mod){

py::class_<GeomInt_LineTool, std::unique_ptr<GeomInt_LineTool, Deleter<GeomInt_LineTool>>> cls_GeomInt_LineTool(mod, "GeomInt_LineTool", "None");

// Constructors

// Fields

// Methods
// cls_GeomInt_LineTool.def_static("operator new_", (void * (*)(size_t)) &GeomInt_LineTool::operator new, "None", py::arg("theSize"));
// cls_GeomInt_LineTool.def_static("operator delete_", (void (*)(void *)) &GeomInt_LineTool::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_LineTool.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_LineTool::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_LineTool.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_LineTool::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_LineTool.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_LineTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_LineTool.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_LineTool::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_LineTool.def_static("NbVertex_", (Standard_Integer (*)(const opencascade::handle<IntPatch_Line> &)) &GeomInt_LineTool::NbVertex, "None", py::arg("L"));
cls_GeomInt_LineTool.def_static("Vertex_", (const IntPatch_Point & (*)(const opencascade::handle<IntPatch_Line> &, const Standard_Integer)) &GeomInt_LineTool::Vertex, "None", py::arg("L"), py::arg("I"));
cls_GeomInt_LineTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<IntPatch_Line> &)) &GeomInt_LineTool::FirstParameter, "None", py::arg("L"));
cls_GeomInt_LineTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<IntPatch_Line> &)) &GeomInt_LineTool::LastParameter, "None", py::arg("L"));
cls_GeomInt_LineTool.def_static("DecompositionOfWLine_", (Standard_Boolean (*)(const opencascade::handle<IntPatch_WLine> &, const opencascade::handle<GeomAdaptor_HSurface> &, const opencascade::handle<GeomAdaptor_HSurface> &, const Standard_Real, const GeomInt_LineConstructor &, IntPatch_SequenceOfLine &)) &GeomInt_LineTool::DecompositionOfWLine, "None", py::arg("theWLine"), py::arg("theSurface1"), py::arg("theSurface2"), py::arg("aTolSum"), py::arg("theLConstructor"), py::arg("theNewLines"));

// Enums

}