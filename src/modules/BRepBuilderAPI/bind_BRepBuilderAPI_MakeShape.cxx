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
#include <BRepBuilderAPI_Command.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>

void bind_BRepBuilderAPI_MakeShape(py::module &mod){

py::class_<BRepBuilderAPI_MakeShape, std::unique_ptr<BRepBuilderAPI_MakeShape>, BRepBuilderAPI_Command> cls_BRepBuilderAPI_MakeShape(mod, "BRepBuilderAPI_MakeShape", "This is the root class for all shape constructions. It stores the result.");

// Constructors

// Fields

// Methods
// cls_BRepBuilderAPI_MakeShape.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeShape::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeShape.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeShape::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShape.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeShape::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeShape.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeShape::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShape.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShape.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeShape.def("Build", (void (BRepBuilderAPI_MakeShape::*)()) &BRepBuilderAPI_MakeShape::Build, "This is called by Shape(). It does nothing but may be redefined.");
cls_BRepBuilderAPI_MakeShape.def("Shape", (const TopoDS_Shape & (BRepBuilderAPI_MakeShape::*)()) &BRepBuilderAPI_MakeShape::Shape, "Returns a shape built by the shape construction algorithm. Raises exception StdFail_NotDone if the shape was not built.");
cls_BRepBuilderAPI_MakeShape.def("Generated", (const TopTools_ListOfShape & (BRepBuilderAPI_MakeShape::*)(const TopoDS_Shape &)) &BRepBuilderAPI_MakeShape::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepBuilderAPI_MakeShape.def("Modified", (const TopTools_ListOfShape & (BRepBuilderAPI_MakeShape::*)(const TopoDS_Shape &)) &BRepBuilderAPI_MakeShape::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepBuilderAPI_MakeShape.def("IsDeleted", (Standard_Boolean (BRepBuilderAPI_MakeShape::*)(const TopoDS_Shape &)) &BRepBuilderAPI_MakeShape::IsDeleted, "Returns true if the shape S has been deleted.", py::arg("S"));

// Enums

}