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
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.hxx>
#include <TopOpeBRepDS_Reducer.hxx>

void bind_TopOpeBRepDS_Reducer(py::module &mod){

py::class_<TopOpeBRepDS_Reducer, std::unique_ptr<TopOpeBRepDS_Reducer>> cls_TopOpeBRepDS_Reducer(mod, "TopOpeBRepDS_Reducer", "reduce interferences of a data structure (HDS) used in topological operations.");

// Constructors
cls_TopOpeBRepDS_Reducer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Fields

// Methods
// cls_TopOpeBRepDS_Reducer.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Reducer::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Reducer.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Reducer::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Reducer.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Reducer::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Reducer.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Reducer::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Reducer.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Reducer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Reducer.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Reducer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Reducer.def("ProcessFaceInterferences", (void (TopOpeBRepDS_Reducer::*)(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_Reducer::ProcessFaceInterferences, "None", py::arg("M"));
cls_TopOpeBRepDS_Reducer.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_Reducer::*)()) &TopOpeBRepDS_Reducer::ProcessEdgeInterferences, "None");

// Enums

}