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
#include <gp_Cone.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Lin.hxx>
#include <gce_MakeCone.hxx>

void bind_gce_MakeCone(py::module &mod){

py::class_<gce_MakeCone, std::unique_ptr<gce_MakeCone, Deleter<gce_MakeCone>>, gce_Root> cls_gce_MakeCone(mod, "gce_MakeCone", "This class implements the following algorithms used to create a Cone from gp. * Create a Cone coaxial to another and passing through a point. * Create a Cone coaxial to another at a distance <Dist>. * Create a Cone by 4 points. * Create a Cone by its axis and 2 points. * Create a Cone by 2 points and 2 radius. * Create a Cone by an Ax2 an angle and the radius of its reference section.");

// Constructors
cls_gce_MakeCone.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("Ang"), py::arg("Radius"));
cls_gce_MakeCone.def(py::init<const gp_Cone &, const gp_Pnt &>(), py::arg("Cone"), py::arg("Point"));
cls_gce_MakeCone.def(py::init<const gp_Cone &, const Standard_Real>(), py::arg("Cone"), py::arg("Dist"));
cls_gce_MakeCone.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_gce_MakeCone.def(py::init<const gp_Ax1 &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Axis"), py::arg("P1"), py::arg("P2"));
cls_gce_MakeCone.def(py::init<const gp_Lin &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Axis"), py::arg("P1"), py::arg("P2"));
cls_gce_MakeCone.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("R1"), py::arg("R2"));

// Fields

// Methods
// cls_gce_MakeCone.def_static("operator new_", (void * (*)(size_t)) &gce_MakeCone::operator new, "None", py::arg("theSize"));
// cls_gce_MakeCone.def_static("operator delete_", (void (*)(void *)) &gce_MakeCone::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeCone.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeCone::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeCone.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeCone::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeCone.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeCone::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeCone.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeCone::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeCone.def("Value", (const gp_Cone & (gce_MakeCone::*)() const) &gce_MakeCone::Value, "Returns the constructed cone. Exceptions StdFail_NotDone if no cone is constructed.");
cls_gce_MakeCone.def("Operator", (const gp_Cone & (gce_MakeCone::*)() const) &gce_MakeCone::Operator, "None");

// Enums

}