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
#include <gce_Root.hxx>
#include <Standard.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Hypr.hxx>
#include <gce_MakeHypr.hxx>

void bind_gce_MakeHypr(py::module &mod){

py::class_<gce_MakeHypr, std::unique_ptr<gce_MakeHypr, Deleter<gce_MakeHypr>>, gce_Root> cls_gce_MakeHypr(mod, "gce_MakeHypr", "This class implements the following algorithms used to create Hyperbola from gp. * Create an Hyperbola from its center, and two points: one on its axis of symmetry giving the major radius, the other giving the value of the small radius. The three points give the plane of the hyperbola. * Create an hyperbola from its axisplacement and its MajorRadius and its MinorRadius.");

// Constructors
cls_gce_MakeHypr.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_gce_MakeHypr.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));

// Fields

// Methods
// cls_gce_MakeHypr.def_static("operator new_", (void * (*)(size_t)) &gce_MakeHypr::operator new, "None", py::arg("theSize"));
// cls_gce_MakeHypr.def_static("operator delete_", (void (*)(void *)) &gce_MakeHypr::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeHypr.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeHypr::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeHypr.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeHypr::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeHypr.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeHypr::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeHypr.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeHypr::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeHypr.def("Value", (const gp_Hypr & (gce_MakeHypr::*)() const) &gce_MakeHypr::Value, "Returns the constructed hyperbola. Exceptions StdFail_NotDone if no hyperbola is constructed.");
cls_gce_MakeHypr.def("Operator", (const gp_Hypr & (gce_MakeHypr::*)() const) &gce_MakeHypr::Operator, "None");

// Enums

}