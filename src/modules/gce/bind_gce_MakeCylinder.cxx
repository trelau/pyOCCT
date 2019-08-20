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
#include <gp_Cylinder.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Circ.hxx>
#include <gce_MakeCylinder.hxx>

void bind_gce_MakeCylinder(py::module &mod){

py::class_<gce_MakeCylinder, std::unique_ptr<gce_MakeCylinder>, gce_Root> cls_gce_MakeCylinder(mod, "gce_MakeCylinder", "This class implements the following algorithms used to create a Cylinder from gp. * Create a Cylinder coaxial to another and passing through a point. * Create a Cylinder coaxial to another at a distance <Dist>. * Create a Cylinder with 3 points. * Create a Cylinder by its axis and radius. * Create a cylinder by its circular base.");

// Constructors
cls_gce_MakeCylinder.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Radius"));
cls_gce_MakeCylinder.def(py::init<const gp_Cylinder &, const gp_Pnt &>(), py::arg("Cyl"), py::arg("Point"));
cls_gce_MakeCylinder.def(py::init<const gp_Cylinder &, const Standard_Real>(), py::arg("Cyl"), py::arg("Dist"));
cls_gce_MakeCylinder.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_gce_MakeCylinder.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Radius"));
cls_gce_MakeCylinder.def(py::init<const gp_Circ &>(), py::arg("Circ"));

// Fields

// Methods
// cls_gce_MakeCylinder.def_static("operator new_", (void * (*)(size_t)) &gce_MakeCylinder::operator new, "None", py::arg("theSize"));
// cls_gce_MakeCylinder.def_static("operator delete_", (void (*)(void *)) &gce_MakeCylinder::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeCylinder.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeCylinder::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeCylinder.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeCylinder::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeCylinder.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeCylinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeCylinder.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeCylinder::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeCylinder.def("Value", (const gp_Cylinder & (gce_MakeCylinder::*)() const) &gce_MakeCylinder::Value, "Returns the constructed cylinder. Exceptions StdFail_NotDone if no cylinder is constructed.");
cls_gce_MakeCylinder.def("Operator", (const gp_Cylinder & (gce_MakeCylinder::*)() const) &gce_MakeCylinder::Operator, "None");

// Enums

}