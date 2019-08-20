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
#include <IntTools_SurfaceRangeSample.hxx>
#include <IntTools_SurfaceRangeSampleMapHasher.hxx>

void bind_IntTools_SurfaceRangeSampleMapHasher(py::module &mod){

py::class_<IntTools_SurfaceRangeSampleMapHasher, std::unique_ptr<IntTools_SurfaceRangeSampleMapHasher>> cls_IntTools_SurfaceRangeSampleMapHasher(mod, "IntTools_SurfaceRangeSampleMapHasher", "None");

// Constructors

// Fields

// Methods
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator new_", (void * (*)(size_t)) &IntTools_SurfaceRangeSampleMapHasher::operator new, "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator delete_", (void (*)(void *)) &IntTools_SurfaceRangeSampleMapHasher::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_SurfaceRangeSampleMapHasher::operator new[], "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator delete[]_", (void (*)(void *)) &IntTools_SurfaceRangeSampleMapHasher::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_SurfaceRangeSampleMapHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSampleMapHasher.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_SurfaceRangeSampleMapHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_SurfaceRangeSampleMapHasher.def_static("HashCode_", (Standard_Integer (*)(const IntTools_SurfaceRangeSample &, const Standard_Integer)) &IntTools_SurfaceRangeSampleMapHasher::HashCode, "Returns a HasCode value for the Key <K> in the range 0..Upper.", py::arg("K"), py::arg("Upper"));
cls_IntTools_SurfaceRangeSampleMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const IntTools_SurfaceRangeSample &, const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeSampleMapHasher::IsEqual, "Returns True when the two keys are the same. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("S1"), py::arg("S2"));

// Enums

}