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
#include <gp_Pln.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Plane.hxx>
#include <GC_MakePlane.hxx>

void bind_GC_MakePlane(py::module &mod){

py::class_<GC_MakePlane, std::unique_ptr<GC_MakePlane, Deleter<GC_MakePlane>>, GC_Root> cls_GC_MakePlane(mod, "GC_MakePlane", "This class implements the following algorithms used to create a Plane from gp. * Create a Plane parallel to another and passing through a point. * Create a Plane passing through 3 points. * Create a Plane by its normal A MakePlane object provides a framework for: - defining the construction of the plane, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed plane.");

// Constructors
cls_GC_MakePlane.def(py::init<const gp_Pln &>(), py::arg("Pl"));
cls_GC_MakePlane.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));
cls_GC_MakePlane.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_GC_MakePlane.def(py::init<const gp_Pln &, const gp_Pnt &>(), py::arg("Pln"), py::arg("Point"));
cls_GC_MakePlane.def(py::init<const gp_Pln &, const Standard_Real>(), py::arg("Pln"), py::arg("Dist"));
cls_GC_MakePlane.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_GC_MakePlane.def(py::init<const gp_Ax1 &>(), py::arg("Axis"));

// Fields

// Methods
// cls_GC_MakePlane.def_static("operator new_", (void * (*)(size_t)) &GC_MakePlane::operator new, "None", py::arg("theSize"));
// cls_GC_MakePlane.def_static("operator delete_", (void (*)(void *)) &GC_MakePlane::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakePlane.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakePlane::operator new[], "None", py::arg("theSize"));
// cls_GC_MakePlane.def_static("operator delete[]_", (void (*)(void *)) &GC_MakePlane::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakePlane.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakePlane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakePlane.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakePlane::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakePlane.def("Value", (const opencascade::handle<Geom_Plane> & (GC_MakePlane::*)() const) &GC_MakePlane::Value, "Returns the constructed plane. Exceptions StdFail_NotDone if no plane is constructed.");

// Enums

}