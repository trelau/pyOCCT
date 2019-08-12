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
#include <TopOpeBRepDS_DataStructure.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <TopOpeBRepDS_PointExplorer.hxx>

void bind_TopOpeBRepDS_PointExplorer(py::module &mod){

py::class_<TopOpeBRepDS_PointExplorer, std::unique_ptr<TopOpeBRepDS_PointExplorer, Deleter<TopOpeBRepDS_PointExplorer>>> cls_TopOpeBRepDS_PointExplorer(mod, "TopOpeBRepDS_PointExplorer", "None");

// Constructors
cls_TopOpeBRepDS_PointExplorer.def(py::init<>());
cls_TopOpeBRepDS_PointExplorer.def(py::init<const TopOpeBRepDS_DataStructure &>(), py::arg("DS"));
cls_TopOpeBRepDS_PointExplorer.def(py::init<const TopOpeBRepDS_DataStructure &, const Standard_Boolean>(), py::arg("DS"), py::arg("FindOnlyKeep"));

// Fields

// Methods
// cls_TopOpeBRepDS_PointExplorer.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_PointExplorer::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointExplorer.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_PointExplorer::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointExplorer.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_PointExplorer::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointExplorer.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_PointExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_PointExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_PointExplorer.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_PointExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_PointExplorer.def("Init", [](TopOpeBRepDS_PointExplorer &self, const TopOpeBRepDS_DataStructure & a0) -> void { return self.Init(a0); });
cls_TopOpeBRepDS_PointExplorer.def("Init", (void (TopOpeBRepDS_PointExplorer::*)(const TopOpeBRepDS_DataStructure &, const Standard_Boolean)) &TopOpeBRepDS_PointExplorer::Init, "None", py::arg("DS"), py::arg("FindOnlyKeep"));
cls_TopOpeBRepDS_PointExplorer.def("More", (Standard_Boolean (TopOpeBRepDS_PointExplorer::*)() const) &TopOpeBRepDS_PointExplorer::More, "None");
cls_TopOpeBRepDS_PointExplorer.def("Next", (void (TopOpeBRepDS_PointExplorer::*)()) &TopOpeBRepDS_PointExplorer::Next, "None");
cls_TopOpeBRepDS_PointExplorer.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_PointExplorer::*)() const) &TopOpeBRepDS_PointExplorer::Point, "None");
cls_TopOpeBRepDS_PointExplorer.def("IsPoint", (Standard_Boolean (TopOpeBRepDS_PointExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_PointExplorer::IsPoint, "None", py::arg("I"));
cls_TopOpeBRepDS_PointExplorer.def("IsPointKeep", (Standard_Boolean (TopOpeBRepDS_PointExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_PointExplorer::IsPointKeep, "None", py::arg("I"));
cls_TopOpeBRepDS_PointExplorer.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_PointExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_PointExplorer::Point, "None", py::arg("I"));
cls_TopOpeBRepDS_PointExplorer.def("NbPoint", (Standard_Integer (TopOpeBRepDS_PointExplorer::*)()) &TopOpeBRepDS_PointExplorer::NbPoint, "None");
cls_TopOpeBRepDS_PointExplorer.def("Index", (Standard_Integer (TopOpeBRepDS_PointExplorer::*)() const) &TopOpeBRepDS_PointExplorer::Index, "None");

// Enums

}