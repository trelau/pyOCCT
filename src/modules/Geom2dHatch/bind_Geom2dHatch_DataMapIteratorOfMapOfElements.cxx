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
#include <Geom2dHatch_Element.hxx>
#include <TColStd_MapIntegerHasher.hxx>
#include <Geom2dHatch_MapOfElements.hxx>

void bind_Geom2dHatch_DataMapIteratorOfMapOfElements(py::module &mod){

py::class_<NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator, std::unique_ptr<NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator>, NCollection_BaseMap::Iterator> cls_Geom2dHatch_DataMapIteratorOfMapOfElements(mod, "Geom2dHatch_DataMapIteratorOfMapOfElements", "None");

// Constructors
cls_Geom2dHatch_DataMapIteratorOfMapOfElements.def(py::init<>());
cls_Geom2dHatch_DataMapIteratorOfMapOfElements.def(py::init<const NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> > &>(), py::arg("theMap"));

// Fields

// Methods
cls_Geom2dHatch_DataMapIteratorOfMapOfElements.def("More", (Standard_Boolean (NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator::More, "Query if the end of collection is reached by iterator");
cls_Geom2dHatch_DataMapIteratorOfMapOfElements.def("Next", (void (NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator::*)()) &NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator::Next, "Make a step along the collection");
cls_Geom2dHatch_DataMapIteratorOfMapOfElements.def("Value", (const Geom2dHatch_Element & (NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator::Value, "Value inquiry");
cls_Geom2dHatch_DataMapIteratorOfMapOfElements.def("ChangeValue", (Geom2dHatch_Element & (NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator::ChangeValue, "Value change access");
cls_Geom2dHatch_DataMapIteratorOfMapOfElements.def("Key", (const int & (NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, Geom2dHatch_Element, NCollection_DefaultHasher<int> >::Iterator::Key, "Key");

// Enums

}