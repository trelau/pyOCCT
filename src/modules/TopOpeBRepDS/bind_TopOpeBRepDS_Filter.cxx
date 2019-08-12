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
#include <TopOpeBRepTool_ShapeClassifier.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopOpeBRepTool_PShapeClassifier.hxx>
#include <TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Filter.hxx>

void bind_TopOpeBRepDS_Filter(py::module &mod){

py::class_<TopOpeBRepDS_Filter, std::unique_ptr<TopOpeBRepDS_Filter, Deleter<TopOpeBRepDS_Filter>>> cls_TopOpeBRepDS_Filter(mod, "TopOpeBRepDS_Filter", "None");

// Constructors
cls_TopOpeBRepDS_Filter.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
cls_TopOpeBRepDS_Filter.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopOpeBRepTool_PShapeClassifier &>(), py::arg("HDS"), py::arg("pClassif"));

// Fields

// Methods
// cls_TopOpeBRepDS_Filter.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Filter::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Filter.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Filter::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Filter.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Filter::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Filter.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Filter::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Filter.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Filter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Filter.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Filter::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Filter.def("ProcessInterferences", (void (TopOpeBRepDS_Filter::*)()) &TopOpeBRepDS_Filter::ProcessInterferences, "None");
cls_TopOpeBRepDS_Filter.def("ProcessFaceInterferences", (void (TopOpeBRepDS_Filter::*)(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_Filter::ProcessFaceInterferences, "None", py::arg("MEsp"));
cls_TopOpeBRepDS_Filter.def("ProcessFaceInterferences", (void (TopOpeBRepDS_Filter::*)(const Standard_Integer, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_Filter::ProcessFaceInterferences, "None", py::arg("I"), py::arg("MEsp"));
cls_TopOpeBRepDS_Filter.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_Filter::*)()) &TopOpeBRepDS_Filter::ProcessEdgeInterferences, "None");
cls_TopOpeBRepDS_Filter.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_Filter::*)(const Standard_Integer)) &TopOpeBRepDS_Filter::ProcessEdgeInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_Filter.def("ProcessCurveInterferences", (void (TopOpeBRepDS_Filter::*)()) &TopOpeBRepDS_Filter::ProcessCurveInterferences, "None");
cls_TopOpeBRepDS_Filter.def("ProcessCurveInterferences", (void (TopOpeBRepDS_Filter::*)(const Standard_Integer)) &TopOpeBRepDS_Filter::ProcessCurveInterferences, "None", py::arg("I"));

// Enums

}