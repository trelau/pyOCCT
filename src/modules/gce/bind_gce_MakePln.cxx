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
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pln.hxx>
#include <gp_Ax1.hxx>
#include <gce_MakePln.hxx>

void bind_gce_MakePln(py::module &mod){

py::class_<gce_MakePln, std::unique_ptr<gce_MakePln, Deleter<gce_MakePln>>, gce_Root> cls_gce_MakePln(mod, "gce_MakePln", "This class implements the following algorithms used to create a Plane from gp. * Create a Pln parallel to another and passing through a point. * Create a Pln passing through 3 points. * Create a Pln by its normal. Defines a non-persistent plane. The plane is located in 3D space with an axis placement two axis. It is the local coordinate system of the plane.");

// Constructors
cls_gce_MakePln.def(py::init<const gp_Ax2 &>(), py::arg("A2"));
cls_gce_MakePln.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));
cls_gce_MakePln.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_gce_MakePln.def(py::init<const gp_Pln &, const gp_Pnt &>(), py::arg("Pln"), py::arg("Point"));
cls_gce_MakePln.def(py::init<const gp_Pln &, const Standard_Real>(), py::arg("Pln"), py::arg("Dist"));
cls_gce_MakePln.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_gce_MakePln.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_gce_MakePln.def(py::init<const gp_Ax1 &>(), py::arg("Axis"));

// Fields

// Methods
// cls_gce_MakePln.def_static("operator new_", (void * (*)(size_t)) &gce_MakePln::operator new, "None", py::arg("theSize"));
// cls_gce_MakePln.def_static("operator delete_", (void (*)(void *)) &gce_MakePln::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakePln.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakePln::operator new[], "None", py::arg("theSize"));
// cls_gce_MakePln.def_static("operator delete[]_", (void (*)(void *)) &gce_MakePln::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakePln.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakePln::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakePln.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakePln::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakePln.def("Value", (const gp_Pln & (gce_MakePln::*)() const) &gce_MakePln::Value, "Returns the constructed plane. Exceptions StdFail_NotDone if no plane is constructed.");
cls_gce_MakePln.def("Operator", (const gp_Pln & (gce_MakePln::*)() const) &gce_MakePln::Operator, "None");

// Enums

}