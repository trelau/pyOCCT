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
#include <gp_Pnt2d.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gce_MakeMirror2d.hxx>

void bind_gce_MakeMirror2d(py::module &mod){

py::class_<gce_MakeMirror2d, std::unique_ptr<gce_MakeMirror2d, Deleter<gce_MakeMirror2d>>> cls_gce_MakeMirror2d(mod, "gce_MakeMirror2d", "This class implements elementary construction algorithms for a symmetrical transformation in 2D space about a point or axis. The result is a gp_Trsf2d transformation. A MakeMirror2d object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and consulting the result.");

// Constructors
cls_gce_MakeMirror2d.def(py::init<const gp_Pnt2d &>(), py::arg("Point"));
cls_gce_MakeMirror2d.def(py::init<const gp_Ax2d &>(), py::arg("Axis"));
cls_gce_MakeMirror2d.def(py::init<const gp_Lin2d &>(), py::arg("Line"));
cls_gce_MakeMirror2d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("Point"), py::arg("Direc"));

// Fields

// Methods
// cls_gce_MakeMirror2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeMirror2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeMirror2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeMirror2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeMirror2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeMirror2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeMirror2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeMirror2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeMirror2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeMirror2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeMirror2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeMirror2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeMirror2d.def("Value", (const gp_Trsf2d & (gce_MakeMirror2d::*)() const) &gce_MakeMirror2d::Value, "Returns the constructed transformation.");
cls_gce_MakeMirror2d.def("Operator", (const gp_Trsf2d & (gce_MakeMirror2d::*)() const) &gce_MakeMirror2d::Operator, "None");

// Enums

}