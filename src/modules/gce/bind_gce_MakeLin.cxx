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
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Lin.hxx>
#include <gce_MakeLin.hxx>

void bind_gce_MakeLin(py::module &mod){

py::class_<gce_MakeLin, std::unique_ptr<gce_MakeLin, Deleter<gce_MakeLin>>, gce_Root> cls_gce_MakeLin(mod, "gce_MakeLin", "This class implements the following algorithms used to create a Lin from gp. * Create a Lin parallel to another and passing through a point. * Create a Lin passing through 2 points. * Create a lin from its axis (Ax1 from gp). * Create a lin from a point and a direction.");

// Constructors
cls_gce_MakeLin.def(py::init<const gp_Ax1 &>(), py::arg("A1"));
cls_gce_MakeLin.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));
cls_gce_MakeLin.def(py::init<const gp_Lin &, const gp_Pnt &>(), py::arg("Lin"), py::arg("Point"));
cls_gce_MakeLin.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
// cls_gce_MakeLin.def_static("operator new_", (void * (*)(size_t)) &gce_MakeLin::operator new, "None", py::arg("theSize"));
// cls_gce_MakeLin.def_static("operator delete_", (void (*)(void *)) &gce_MakeLin::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeLin.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeLin::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeLin.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeLin::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeLin.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeLin::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeLin.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeLin::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeLin.def("Value", (const gp_Lin & (gce_MakeLin::*)() const) &gce_MakeLin::Value, "Returns the constructed line. Exceptions StdFail_NotDone is raised if no line is constructed.");
cls_gce_MakeLin.def("Operator", (const gp_Lin & (gce_MakeLin::*)() const) &gce_MakeLin::Operator, "None");

// Enums

}