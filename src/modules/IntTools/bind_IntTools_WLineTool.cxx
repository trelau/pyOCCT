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
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <IntPatch_WLine.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <GeomInt_LineConstructor.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <IntTools_Context.hxx>
#include <IntTools_WLineTool.hxx>

void bind_IntTools_WLineTool(py::module &mod){

py::class_<IntTools_WLineTool, std::unique_ptr<IntTools_WLineTool>> cls_IntTools_WLineTool(mod, "IntTools_WLineTool", "IntTools_WLineTool provides set of static methods related to walking lines.");

// Constructors

// Fields

// Methods
// cls_IntTools_WLineTool.def_static("operator new_", (void * (*)(size_t)) &IntTools_WLineTool::operator new, "None", py::arg("theSize"));
// cls_IntTools_WLineTool.def_static("operator delete_", (void (*)(void *)) &IntTools_WLineTool::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_WLineTool.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_WLineTool::operator new[], "None", py::arg("theSize"));
// cls_IntTools_WLineTool.def_static("operator delete[]_", (void (*)(void *)) &IntTools_WLineTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_WLineTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_WLineTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_WLineTool.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_WLineTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_WLineTool.def_static("NotUseSurfacesForApprox_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const opencascade::handle<IntPatch_WLine> &, const Standard_Integer, const Standard_Integer)) &IntTools_WLineTool::NotUseSurfacesForApprox, "None", py::arg("aF1"), py::arg("aF2"), py::arg("WL"), py::arg("ifprm"), py::arg("ilprm"));
cls_IntTools_WLineTool.def_static("DecompositionOfWLine_", [](const opencascade::handle<IntPatch_WLine> & theWLine, const opencascade::handle<GeomAdaptor_HSurface> & theSurface1, const opencascade::handle<GeomAdaptor_HSurface> & theSurface2, const TopoDS_Face & theFace1, const TopoDS_Face & theFace2, const GeomInt_LineConstructor & theLConstructor, const Standard_Boolean theAvoidLConstructor, const Standard_Real theTol, IntPatch_SequenceOfLine & theNewLines, Standard_Real & theReachedTol3d, const opencascade::handle<IntTools_Context> & a0){ Standard_Boolean rv = IntTools_WLineTool::DecompositionOfWLine(theWLine, theSurface1, theSurface2, theFace1, theFace2, theLConstructor, theAvoidLConstructor, theTol, theNewLines, theReachedTol3d, a0); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theReachedTol3d); }, "None", py::arg("theWLine"), py::arg("theSurface1"), py::arg("theSurface2"), py::arg("theFace1"), py::arg("theFace2"), py::arg("theLConstructor"), py::arg("theAvoidLConstructor"), py::arg("theTol"), py::arg("theNewLines"), py::arg("theReachedTol3d"), py::arg(""));

// Enums

}