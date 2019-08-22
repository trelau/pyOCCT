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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BRepSweep_Tool.hxx>

void bind_BRepSweep_Tool(py::module &mod){

py::class_<BRepSweep_Tool> cls_BRepSweep_Tool(mod, "BRepSweep_Tool", "Provides the indexation and type analysis services required by the TopoDS generating Shape of BRepSweep.");

// Constructors
cls_BRepSweep_Tool.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));

// Fields

// Methods
// cls_BRepSweep_Tool.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Tool::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Tool.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Tool::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Tool.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Tool::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Tool.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Tool.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Tool.def("NbShapes", (Standard_Integer (BRepSweep_Tool::*)() const) &BRepSweep_Tool::NbShapes, "Returns the number of subshapes in the shape.");
cls_BRepSweep_Tool.def("Index", (Standard_Integer (BRepSweep_Tool::*)(const TopoDS_Shape &) const) &BRepSweep_Tool::Index, "Returns the index of <aShape>.", py::arg("aShape"));
cls_BRepSweep_Tool.def("Shape", (TopoDS_Shape (BRepSweep_Tool::*)(const Standard_Integer) const) &BRepSweep_Tool::Shape, "Returns the Shape at Index anIdex.", py::arg("anIndex"));
cls_BRepSweep_Tool.def("Type", (TopAbs_ShapeEnum (BRepSweep_Tool::*)(const TopoDS_Shape &) const) &BRepSweep_Tool::Type, "Returns the type of <aShape>.", py::arg("aShape"));
cls_BRepSweep_Tool.def("Orientation", (TopAbs_Orientation (BRepSweep_Tool::*)(const TopoDS_Shape &) const) &BRepSweep_Tool::Orientation, "Returns the Orientation of <aShape>.", py::arg("aShape"));
cls_BRepSweep_Tool.def("SetOrientation", (void (BRepSweep_Tool::*)(TopoDS_Shape &, const TopAbs_Orientation) const) &BRepSweep_Tool::SetOrientation, "Set the Orientation of <aShape> with Or.", py::arg("aShape"), py::arg("Or"));

// Enums

}