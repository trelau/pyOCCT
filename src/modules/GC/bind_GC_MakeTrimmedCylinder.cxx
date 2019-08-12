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
#include <gp_Circ.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <Standard_Handle.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <GC_MakeTrimmedCylinder.hxx>

void bind_GC_MakeTrimmedCylinder(py::module &mod){

py::class_<GC_MakeTrimmedCylinder, std::unique_ptr<GC_MakeTrimmedCylinder, Deleter<GC_MakeTrimmedCylinder>>, GC_Root> cls_GC_MakeTrimmedCylinder(mod, "GC_MakeTrimmedCylinder", "Implements construction algorithms for a trimmed cylinder limited by two planes orthogonal to its axis. The result is a Geom_RectangularTrimmedSurface surface. A MakeTrimmedCylinder provides a framework for: - defining the construction of the trimmed cylinder, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed trimmed cylinder.");

// Constructors
cls_GC_MakeTrimmedCylinder.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_GC_MakeTrimmedCylinder.def(py::init<const gp_Circ &, const Standard_Real>(), py::arg("Circ"), py::arg("Height"));
cls_GC_MakeTrimmedCylinder.def(py::init<const gp_Ax1 &, const Standard_Real, const Standard_Real>(), py::arg("A1"), py::arg("Radius"), py::arg("Height"));

// Fields

// Methods
// cls_GC_MakeTrimmedCylinder.def_static("operator new_", (void * (*)(size_t)) &GC_MakeTrimmedCylinder::operator new, "None", py::arg("theSize"));
// cls_GC_MakeTrimmedCylinder.def_static("operator delete_", (void (*)(void *)) &GC_MakeTrimmedCylinder::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeTrimmedCylinder.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeTrimmedCylinder::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeTrimmedCylinder.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeTrimmedCylinder::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeTrimmedCylinder.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeTrimmedCylinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeTrimmedCylinder.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeTrimmedCylinder::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeTrimmedCylinder.def("Value", (const opencascade::handle<Geom_RectangularTrimmedSurface> & (GC_MakeTrimmedCylinder::*)() const) &GC_MakeTrimmedCylinder::Value, "Returns the constructed trimmed cylinder. Exceptions StdFail_NotDone if no trimmed cylinder is constructed.");

// Enums

}