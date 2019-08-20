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
#include <TopOpeBRepDS_Surface.hxx>
#include <TopOpeBRepDS_SurfaceExplorer.hxx>

void bind_TopOpeBRepDS_SurfaceExplorer(py::module &mod){

py::class_<TopOpeBRepDS_SurfaceExplorer, std::unique_ptr<TopOpeBRepDS_SurfaceExplorer>> cls_TopOpeBRepDS_SurfaceExplorer(mod, "TopOpeBRepDS_SurfaceExplorer", "None");

// Constructors
cls_TopOpeBRepDS_SurfaceExplorer.def(py::init<>());
cls_TopOpeBRepDS_SurfaceExplorer.def(py::init<const TopOpeBRepDS_DataStructure &>(), py::arg("DS"));
cls_TopOpeBRepDS_SurfaceExplorer.def(py::init<const TopOpeBRepDS_DataStructure &, const Standard_Boolean>(), py::arg("DS"), py::arg("FindOnlyKeep"));

// Fields

// Methods
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_SurfaceExplorer::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_SurfaceExplorer::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_SurfaceExplorer::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_SurfaceExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_SurfaceExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_SurfaceExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_SurfaceExplorer.def("Init", [](TopOpeBRepDS_SurfaceExplorer &self, const TopOpeBRepDS_DataStructure & a0) -> void { return self.Init(a0); });
cls_TopOpeBRepDS_SurfaceExplorer.def("Init", (void (TopOpeBRepDS_SurfaceExplorer::*)(const TopOpeBRepDS_DataStructure &, const Standard_Boolean)) &TopOpeBRepDS_SurfaceExplorer::Init, "None", py::arg("DS"), py::arg("FindOnlyKeep"));
cls_TopOpeBRepDS_SurfaceExplorer.def("More", (Standard_Boolean (TopOpeBRepDS_SurfaceExplorer::*)() const) &TopOpeBRepDS_SurfaceExplorer::More, "None");
cls_TopOpeBRepDS_SurfaceExplorer.def("Next", (void (TopOpeBRepDS_SurfaceExplorer::*)()) &TopOpeBRepDS_SurfaceExplorer::Next, "None");
cls_TopOpeBRepDS_SurfaceExplorer.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_SurfaceExplorer::*)() const) &TopOpeBRepDS_SurfaceExplorer::Surface, "None");
cls_TopOpeBRepDS_SurfaceExplorer.def("IsSurface", (Standard_Boolean (TopOpeBRepDS_SurfaceExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_SurfaceExplorer::IsSurface, "None", py::arg("I"));
cls_TopOpeBRepDS_SurfaceExplorer.def("IsSurfaceKeep", (Standard_Boolean (TopOpeBRepDS_SurfaceExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_SurfaceExplorer::IsSurfaceKeep, "None", py::arg("I"));
cls_TopOpeBRepDS_SurfaceExplorer.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_SurfaceExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_SurfaceExplorer::Surface, "None", py::arg("I"));
cls_TopOpeBRepDS_SurfaceExplorer.def("NbSurface", (Standard_Integer (TopOpeBRepDS_SurfaceExplorer::*)()) &TopOpeBRepDS_SurfaceExplorer::NbSurface, "None");
cls_TopOpeBRepDS_SurfaceExplorer.def("Index", (Standard_Integer (TopOpeBRepDS_SurfaceExplorer::*)() const) &TopOpeBRepDS_SurfaceExplorer::Index, "None");

// Enums

}