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
#include <ShapeUpgrade_ShapeDivide.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeUpgrade_ShapeDivideClosedEdges.hxx>

void bind_ShapeUpgrade_ShapeDivideClosedEdges(py::module &mod){

py::class_<ShapeUpgrade_ShapeDivideClosedEdges, std::unique_ptr<ShapeUpgrade_ShapeDivideClosedEdges>, ShapeUpgrade_ShapeDivide> cls_ShapeUpgrade_ShapeDivideClosedEdges(mod, "ShapeUpgrade_ShapeDivideClosedEdges", "None");

// Constructors
cls_ShapeUpgrade_ShapeDivideClosedEdges.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_ShapeUpgrade_ShapeDivideClosedEdges.def_static("operator new_", (void * (*)(size_t)) &ShapeUpgrade_ShapeDivideClosedEdges::operator new, "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShapeDivideClosedEdges.def_static("operator delete_", (void (*)(void *)) &ShapeUpgrade_ShapeDivideClosedEdges::operator delete, "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivideClosedEdges.def_static("operator new[]_", (void * (*)(size_t)) &ShapeUpgrade_ShapeDivideClosedEdges::operator new[], "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShapeDivideClosedEdges.def_static("operator delete[]_", (void (*)(void *)) &ShapeUpgrade_ShapeDivideClosedEdges::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivideClosedEdges.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeUpgrade_ShapeDivideClosedEdges::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivideClosedEdges.def_static("operator delete_", (void (*)(void *, void *)) &ShapeUpgrade_ShapeDivideClosedEdges::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeUpgrade_ShapeDivideClosedEdges.def("SetNbSplitPoints", (void (ShapeUpgrade_ShapeDivideClosedEdges::*)(const Standard_Integer)) &ShapeUpgrade_ShapeDivideClosedEdges::SetNbSplitPoints, "Sets the number of cuts applied to divide closed edges. The number of resulting faces will be num+1.", py::arg("num"));

// Enums

}