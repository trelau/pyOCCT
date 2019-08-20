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
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopOpeBRepDS_ShapeData.hxx>

void bind_TopOpeBRepDS_ShapeData(py::module &mod){

py::class_<TopOpeBRepDS_ShapeData, std::unique_ptr<TopOpeBRepDS_ShapeData>> cls_TopOpeBRepDS_ShapeData(mod, "TopOpeBRepDS_ShapeData", "None");

// Constructors
cls_TopOpeBRepDS_ShapeData.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepDS_ShapeData.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_ShapeData::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ShapeData.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_ShapeData::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeData.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_ShapeData::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ShapeData.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_ShapeData::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeData.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_ShapeData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeData.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_ShapeData::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_ShapeData.def("Interferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_ShapeData::*)() const) &TopOpeBRepDS_ShapeData::Interferences, "None");
cls_TopOpeBRepDS_ShapeData.def("ChangeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_ShapeData::*)()) &TopOpeBRepDS_ShapeData::ChangeInterferences, "None");
cls_TopOpeBRepDS_ShapeData.def("Keep", (Standard_Boolean (TopOpeBRepDS_ShapeData::*)() const) &TopOpeBRepDS_ShapeData::Keep, "None");
cls_TopOpeBRepDS_ShapeData.def("ChangeKeep", (void (TopOpeBRepDS_ShapeData::*)(const Standard_Boolean)) &TopOpeBRepDS_ShapeData::ChangeKeep, "None", py::arg("B"));

// Enums

}