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
#include <LocalAnalysis_SurfaceContinuity.hxx>
#include <Standard_OStream.hxx>
#include <LocalAnalysis_CurveContinuity.hxx>
#include <LocalAnalysis.hxx>

void bind_LocalAnalysis(py::module &mod){

py::class_<LocalAnalysis, std::unique_ptr<LocalAnalysis>> cls_LocalAnalysis(mod, "LocalAnalysis", "This package gives tools to check the local continuity between two points situated on two curves or two surfaces.");

// Constructors

// Fields

// Methods
// cls_LocalAnalysis.def_static("operator new_", (void * (*)(size_t)) &LocalAnalysis::operator new, "None", py::arg("theSize"));
// cls_LocalAnalysis.def_static("operator delete_", (void (*)(void *)) &LocalAnalysis::operator delete, "None", py::arg("theAddress"));
// cls_LocalAnalysis.def_static("operator new[]_", (void * (*)(size_t)) &LocalAnalysis::operator new[], "None", py::arg("theSize"));
// cls_LocalAnalysis.def_static("operator delete[]_", (void (*)(void *)) &LocalAnalysis::operator delete[], "None", py::arg("theAddress"));
// cls_LocalAnalysis.def_static("operator new_", (void * (*)(size_t, void *)) &LocalAnalysis::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocalAnalysis.def_static("operator delete_", (void (*)(void *, void *)) &LocalAnalysis::operator delete, "None", py::arg(""), py::arg(""));
cls_LocalAnalysis.def_static("Dump_", (void (*)(const LocalAnalysis_SurfaceContinuity &, Standard_OStream &)) &LocalAnalysis::Dump, "This class compute s and gives tools to check the local continuity between two points situated on 2 curves)", py::arg("surfconti"), py::arg("o"));
cls_LocalAnalysis.def_static("Dump_", (void (*)(const LocalAnalysis_CurveContinuity &, Standard_OStream &)) &LocalAnalysis::Dump, "This fonction gives informations about a variable SurfaceContinuity", py::arg("curvconti"), py::arg("o"));

// Enums

}