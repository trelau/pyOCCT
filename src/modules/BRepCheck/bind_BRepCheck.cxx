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
#include <BRepCheck_ListOfStatus.hxx>
#include <BRepCheck_Status.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepCheck_Result.hxx>
#include <BRepCheck_Vertex.hxx>
#include <BRepCheck_Edge.hxx>
#include <BRepCheck_Wire.hxx>
#include <BRepCheck_Face.hxx>
#include <BRepCheck_Shell.hxx>
#include <BRepCheck_Solid.hxx>
#include <BRepCheck_Analyzer.hxx>
#include <BRepCheck.hxx>

void bind_BRepCheck(py::module &mod){

py::class_<BRepCheck, std::unique_ptr<BRepCheck, Deleter<BRepCheck>>> cls_BRepCheck(mod, "BRepCheck", "This package provides tools to check the validity of the BRep.");

// Constructors

// Fields

// Methods
// cls_BRepCheck.def_static("operator new_", (void * (*)(size_t)) &BRepCheck::operator new, "None", py::arg("theSize"));
// cls_BRepCheck.def_static("operator delete_", (void (*)(void *)) &BRepCheck::operator delete, "None", py::arg("theAddress"));
// cls_BRepCheck.def_static("operator new[]_", (void * (*)(size_t)) &BRepCheck::operator new[], "None", py::arg("theSize"));
// cls_BRepCheck.def_static("operator delete[]_", (void (*)(void *)) &BRepCheck::operator delete[], "None", py::arg("theAddress"));
// cls_BRepCheck.def_static("operator new_", (void * (*)(size_t, void *)) &BRepCheck::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepCheck.def_static("operator delete_", (void (*)(void *, void *)) &BRepCheck::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepCheck.def_static("Add_", (void (*)(BRepCheck_ListOfStatus &, const BRepCheck_Status)) &BRepCheck::Add, "None", py::arg("List"), py::arg("Stat"));
cls_BRepCheck.def_static("Print_", (void (*)(const BRepCheck_Status, Standard_OStream &)) &BRepCheck::Print, "None", py::arg("Stat"), py::arg("OS"));
cls_BRepCheck.def_static("SelfIntersection_", (Standard_Boolean (*)(const TopoDS_Wire &, const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &)) &BRepCheck::SelfIntersection, "None", py::arg("W"), py::arg("F"), py::arg("E1"), py::arg("E2"));

// Enums

}