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
#include <NCollection_DataMap.hxx>
#include <TopoDS_Shape.hxx>
#include <HLRTopoBRep_ListOfVData.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <HLRTopoBRep_MapOfShapeListOfVData.hxx>

void bind_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData(py::module &mod){

py::class_<NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator, std::unique_ptr<NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator, Deleter<NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator>>, NCollection_BaseMap::Iterator> cls_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData(mod, "HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData", "None");

// Constructors
cls_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def(py::init<>());
cls_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def(py::init<const NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher> &>(), py::arg("theMap"));

// Fields

// Methods
cls_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def("More", (Standard_Boolean (NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::More, "Query if the end of collection is reached by iterator");
cls_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def("Next", (void (NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::*)()) &NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::Next, "Make a step along the collection");
cls_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def("Value", (const NCollection_List<HLRTopoBRep_VData> & (NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::Value, "Value inquiry");
cls_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def("ChangeValue", (NCollection_List<HLRTopoBRep_VData> & (NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::ChangeValue, "Value change access");
cls_HLRTopoBRep_DataMapIteratorOfMapOfShapeListOfVData.def("Key", (const TopoDS_Shape & (NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<HLRTopoBRep_VData>, TopTools_ShapeMapHasher>::Iterator::Key, "Key");

// Enums

}