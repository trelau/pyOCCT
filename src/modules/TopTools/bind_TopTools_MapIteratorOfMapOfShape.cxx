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
#include <NCollection_Map.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <TopTools_MapOfShape.hxx>

void bind_TopTools_MapIteratorOfMapOfShape(py::module &mod){

py::class_<NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator, std::unique_ptr<NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator>, NCollection_BaseMap::Iterator> cls_TopTools_MapIteratorOfMapOfShape(mod, "TopTools_MapIteratorOfMapOfShape", "Implementation of the Iterator interface.");

// Constructors
cls_TopTools_MapIteratorOfMapOfShape.def(py::init<>());
cls_TopTools_MapIteratorOfMapOfShape.def(py::init<const NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher> &>(), py::arg("theMap"));

// Fields

// Methods
cls_TopTools_MapIteratorOfMapOfShape.def("More", (Standard_Boolean (NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::More, "Query if the end of collection is reached by iterator");
cls_TopTools_MapIteratorOfMapOfShape.def("Next", (void (NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::*)()) &NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::Next, "Make a step along the collection");
cls_TopTools_MapIteratorOfMapOfShape.def("Value", (const TopoDS_Shape & (NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::Value, "Value inquiry");
cls_TopTools_MapIteratorOfMapOfShape.def("Key", (const TopoDS_Shape & (NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::Key, "Key");

// Enums

}