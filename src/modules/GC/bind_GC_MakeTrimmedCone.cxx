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
#include <GC_Root.hxx>
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <GC_MakeTrimmedCone.hxx>

void bind_GC_MakeTrimmedCone(py::module &mod){

py::class_<GC_MakeTrimmedCone, GC_Root> cls_GC_MakeTrimmedCone(mod, "GC_MakeTrimmedCone", "Implements construction algorithms for a trimmed cone limited by two planes orthogonal to its axis. The result is a Geom_RectangularTrimmedSurface surface. A MakeTrimmedCone provides a framework for: - defining the construction of the trimmed cone, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed trimmed cone.");

// Constructors
cls_GC_MakeTrimmedCone.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GC_MakeTrimmedCone.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("R1"), py::arg("R2"));

// Fields

// Methods
// cls_GC_MakeTrimmedCone.def_static("operator new_", (void * (*)(size_t)) &GC_MakeTrimmedCone::operator new, "None", py::arg("theSize"));
// cls_GC_MakeTrimmedCone.def_static("operator delete_", (void (*)(void *)) &GC_MakeTrimmedCone::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeTrimmedCone.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeTrimmedCone::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeTrimmedCone.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeTrimmedCone::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeTrimmedCone.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeTrimmedCone::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeTrimmedCone.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeTrimmedCone::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeTrimmedCone.def("Value", (const opencascade::handle<Geom_RectangularTrimmedSurface> & (GC_MakeTrimmedCone::*)() const) &GC_MakeTrimmedCone::Value, "Returns the constructed trimmed cone. StdFail_NotDone if no trimmed cone is constructed.");

// Enums

}