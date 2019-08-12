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
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TColStd_MapIntegerHasher.hxx>
#include <TopOpeBRepDS_DataMapOfIntegerListOfInterference.hxx>

void bind_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference(py::module &mod){

py::class_<NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator, std::unique_ptr<NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator, Deleter<NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator>>, NCollection_BaseMap::Iterator> cls_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference(mod, "TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference", "None");

// Constructors
cls_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def(py::init<>());
cls_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def(py::init<const NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> > &>(), py::arg("theMap"));

// Fields

// Methods
cls_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def("More", (Standard_Boolean (NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::More, "Query if the end of collection is reached by iterator");
cls_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def("Next", (void (NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::*)()) &NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::Next, "Make a step along the collection");
cls_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def("Value", (const NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> > & (NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::Value, "Value inquiry");
cls_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def("ChangeValue", (NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> > & (NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::ChangeValue, "Value change access");
cls_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def("Key", (const int & (NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::Key, "Key");

// Enums

}