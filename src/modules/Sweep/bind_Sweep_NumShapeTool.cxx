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
#include <Sweep_NumShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_Orientation.hxx>
#include <Sweep_NumShapeTool.hxx>

void bind_Sweep_NumShapeTool(py::module &mod){

py::class_<Sweep_NumShapeTool, std::unique_ptr<Sweep_NumShapeTool, Deleter<Sweep_NumShapeTool>>> cls_Sweep_NumShapeTool(mod, "Sweep_NumShapeTool", "This class provides the indexation and type analysis services required by the NumShape Directing Shapes of Swept Primitives.");

// Constructors
cls_Sweep_NumShapeTool.def(py::init<const Sweep_NumShape &>(), py::arg("aShape"));

// Fields

// Methods
// cls_Sweep_NumShapeTool.def_static("operator new_", (void * (*)(size_t)) &Sweep_NumShapeTool::operator new, "None", py::arg("theSize"));
// cls_Sweep_NumShapeTool.def_static("operator delete_", (void (*)(void *)) &Sweep_NumShapeTool::operator delete, "None", py::arg("theAddress"));
// cls_Sweep_NumShapeTool.def_static("operator new[]_", (void * (*)(size_t)) &Sweep_NumShapeTool::operator new[], "None", py::arg("theSize"));
// cls_Sweep_NumShapeTool.def_static("operator delete[]_", (void (*)(void *)) &Sweep_NumShapeTool::operator delete[], "None", py::arg("theAddress"));
// cls_Sweep_NumShapeTool.def_static("operator new_", (void * (*)(size_t, void *)) &Sweep_NumShapeTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Sweep_NumShapeTool.def_static("operator delete_", (void (*)(void *, void *)) &Sweep_NumShapeTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Sweep_NumShapeTool.def("NbShapes", (Standard_Integer (Sweep_NumShapeTool::*)() const) &Sweep_NumShapeTool::NbShapes, "Returns the number of subshapes in the shape.");
cls_Sweep_NumShapeTool.def("Index", (Standard_Integer (Sweep_NumShapeTool::*)(const Sweep_NumShape &) const) &Sweep_NumShapeTool::Index, "Returns the index of <aShape>.", py::arg("aShape"));
cls_Sweep_NumShapeTool.def("Shape", (Sweep_NumShape (Sweep_NumShapeTool::*)(const Standard_Integer) const) &Sweep_NumShapeTool::Shape, "Returns the Shape at index anIndex", py::arg("anIndex"));
cls_Sweep_NumShapeTool.def("Type", (TopAbs_ShapeEnum (Sweep_NumShapeTool::*)(const Sweep_NumShape &) const) &Sweep_NumShapeTool::Type, "Returns the type of <aShape>.", py::arg("aShape"));
cls_Sweep_NumShapeTool.def("Orientation", (TopAbs_Orientation (Sweep_NumShapeTool::*)(const Sweep_NumShape &) const) &Sweep_NumShapeTool::Orientation, "Returns the orientation of <aShape>.", py::arg("aShape"));
cls_Sweep_NumShapeTool.def("HasFirstVertex", (Standard_Boolean (Sweep_NumShapeTool::*)() const) &Sweep_NumShapeTool::HasFirstVertex, "Returns true if there is a First Vertex in the Shape.");
cls_Sweep_NumShapeTool.def("HasLastVertex", (Standard_Boolean (Sweep_NumShapeTool::*)() const) &Sweep_NumShapeTool::HasLastVertex, "Returns true if there is a Last Vertex in the Shape.");
cls_Sweep_NumShapeTool.def("FirstVertex", (Sweep_NumShape (Sweep_NumShapeTool::*)() const) &Sweep_NumShapeTool::FirstVertex, "Returns the first vertex.");
cls_Sweep_NumShapeTool.def("LastVertex", (Sweep_NumShape (Sweep_NumShapeTool::*)() const) &Sweep_NumShapeTool::LastVertex, "Returns the last vertex.");

// Enums

}