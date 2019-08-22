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
#include <TopOpeBRepDS_InterferenceIterator.hxx>
#include <Standard.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopAbs_State.hxx>
#include <TopOpeBRepDS_SurfaceIterator.hxx>

void bind_TopOpeBRepDS_SurfaceIterator(py::module &mod){

py::class_<TopOpeBRepDS_SurfaceIterator, TopOpeBRepDS_InterferenceIterator> cls_TopOpeBRepDS_SurfaceIterator(mod, "TopOpeBRepDS_SurfaceIterator", "None");

// Constructors
cls_TopOpeBRepDS_SurfaceIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));

// Fields

// Methods
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_SurfaceIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_SurfaceIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_SurfaceIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_SurfaceIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_SurfaceIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_SurfaceIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_SurfaceIterator.def("Current", (Standard_Integer (TopOpeBRepDS_SurfaceIterator::*)() const) &TopOpeBRepDS_SurfaceIterator::Current, "Index of the surface in the data structure.");
cls_TopOpeBRepDS_SurfaceIterator.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_SurfaceIterator::*)(const TopAbs_State) const) &TopOpeBRepDS_SurfaceIterator::Orientation, "None", py::arg("S"));

// Enums

}