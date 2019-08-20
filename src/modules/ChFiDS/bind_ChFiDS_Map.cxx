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
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <ChFiDS_Map.hxx>

void bind_ChFiDS_Map(py::module &mod){

py::class_<ChFiDS_Map, std::unique_ptr<ChFiDS_Map>> cls_ChFiDS_Map(mod, "ChFiDS_Map", "Encapsulation of IndexedDataMapOfShapeListOfShape.");

// Constructors
cls_ChFiDS_Map.def(py::init<>());

// Fields

// Methods
// cls_ChFiDS_Map.def_static("operator new_", (void * (*)(size_t)) &ChFiDS_Map::operator new, "None", py::arg("theSize"));
// cls_ChFiDS_Map.def_static("operator delete_", (void (*)(void *)) &ChFiDS_Map::operator delete, "None", py::arg("theAddress"));
// cls_ChFiDS_Map.def_static("operator new[]_", (void * (*)(size_t)) &ChFiDS_Map::operator new[], "None", py::arg("theSize"));
// cls_ChFiDS_Map.def_static("operator delete[]_", (void (*)(void *)) &ChFiDS_Map::operator delete[], "None", py::arg("theAddress"));
// cls_ChFiDS_Map.def_static("operator new_", (void * (*)(size_t, void *)) &ChFiDS_Map::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFiDS_Map.def_static("operator delete_", (void (*)(void *, void *)) &ChFiDS_Map::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFiDS_Map.def("Fill", (void (ChFiDS_Map::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &ChFiDS_Map::Fill, "Fills the map with the subshapes of type T1 as keys and the list of ancestors of type T2 as items.", py::arg("S"), py::arg("T1"), py::arg("T2"));
cls_ChFiDS_Map.def("Contains", (Standard_Boolean (ChFiDS_Map::*)(const TopoDS_Shape &) const) &ChFiDS_Map::Contains, "None", py::arg("S"));
cls_ChFiDS_Map.def("FindFromKey", (const TopTools_ListOfShape & (ChFiDS_Map::*)(const TopoDS_Shape &) const) &ChFiDS_Map::FindFromKey, "None", py::arg("S"));
cls_ChFiDS_Map.def("__call__", (const TopTools_ListOfShape & (ChFiDS_Map::*)(const TopoDS_Shape &) const) &ChFiDS_Map::operator(), py::is_operator(), "None", py::arg("S"));
cls_ChFiDS_Map.def("FindFromIndex", (const TopTools_ListOfShape & (ChFiDS_Map::*)(const Standard_Integer) const) &ChFiDS_Map::FindFromIndex, "None", py::arg("I"));
cls_ChFiDS_Map.def("__call__", (const TopTools_ListOfShape & (ChFiDS_Map::*)(const Standard_Integer) const) &ChFiDS_Map::operator(), py::is_operator(), "None", py::arg("I"));

// Enums

}