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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepBuilderAPI_Collect.hxx>

void bind_BRepBuilderAPI_Collect(py::module &mod){

py::class_<BRepBuilderAPI_Collect> cls_BRepBuilderAPI_Collect(mod, "BRepBuilderAPI_Collect", "None");

// Constructors
cls_BRepBuilderAPI_Collect.def(py::init<>());

// Fields

// Methods
// cls_BRepBuilderAPI_Collect.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_Collect::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Collect.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_Collect::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Collect.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_Collect::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Collect.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_Collect::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Collect.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_Collect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_Collect.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_Collect::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_Collect.def("Add", (void (BRepBuilderAPI_Collect::*)(const TopoDS_Shape &, BRepBuilderAPI_MakeShape &)) &BRepBuilderAPI_Collect::Add, "None", py::arg("SI"), py::arg("MKS"));
cls_BRepBuilderAPI_Collect.def("AddGenerated", (void (BRepBuilderAPI_Collect::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepBuilderAPI_Collect::AddGenerated, "None", py::arg("S"), py::arg("Gen"));
cls_BRepBuilderAPI_Collect.def("AddModif", (void (BRepBuilderAPI_Collect::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepBuilderAPI_Collect::AddModif, "None", py::arg("S"), py::arg("Mod"));
cls_BRepBuilderAPI_Collect.def("Filter", (void (BRepBuilderAPI_Collect::*)(const TopoDS_Shape &)) &BRepBuilderAPI_Collect::Filter, "None", py::arg("SF"));
cls_BRepBuilderAPI_Collect.def("Modification", (const TopTools_DataMapOfShapeListOfShape & (BRepBuilderAPI_Collect::*)() const) &BRepBuilderAPI_Collect::Modification, "None");
cls_BRepBuilderAPI_Collect.def("Generated", (const TopTools_DataMapOfShapeListOfShape & (BRepBuilderAPI_Collect::*)() const) &BRepBuilderAPI_Collect::Generated, "None");

// Enums

}