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
#include <Standard_TypeDef.hxx>
#include <IntTools_BaseRangeSample.hxx>

void bind_IntTools_BaseRangeSample(py::module &mod){

py::class_<IntTools_BaseRangeSample> cls_IntTools_BaseRangeSample(mod, "IntTools_BaseRangeSample", "base class for range index management");

// Constructors
cls_IntTools_BaseRangeSample.def(py::init<>());
cls_IntTools_BaseRangeSample.def(py::init<const Standard_Integer>(), py::arg("theDepth"));

// Fields

// Methods
// cls_IntTools_BaseRangeSample.def_static("operator new_", (void * (*)(size_t)) &IntTools_BaseRangeSample::operator new, "None", py::arg("theSize"));
// cls_IntTools_BaseRangeSample.def_static("operator delete_", (void (*)(void *)) &IntTools_BaseRangeSample::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_BaseRangeSample.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_BaseRangeSample::operator new[], "None", py::arg("theSize"));
// cls_IntTools_BaseRangeSample.def_static("operator delete[]_", (void (*)(void *)) &IntTools_BaseRangeSample::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_BaseRangeSample.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_BaseRangeSample::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_BaseRangeSample.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_BaseRangeSample::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_BaseRangeSample.def("SetDepth", (void (IntTools_BaseRangeSample::*)(const Standard_Integer)) &IntTools_BaseRangeSample::SetDepth, "None", py::arg("theDepth"));
cls_IntTools_BaseRangeSample.def("GetDepth", (Standard_Integer (IntTools_BaseRangeSample::*)() const) &IntTools_BaseRangeSample::GetDepth, "None");

// Enums

}