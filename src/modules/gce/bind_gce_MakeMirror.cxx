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
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Lin.hxx>
#include <gp_Dir.hxx>
#include <gp_Pln.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>
#include <gce_MakeMirror.hxx>

void bind_gce_MakeMirror(py::module &mod){

py::class_<gce_MakeMirror, std::unique_ptr<gce_MakeMirror>> cls_gce_MakeMirror(mod, "gce_MakeMirror", "This class mplements elementary construction algorithms for a symmetrical transformation in 3D space about a point, axis or plane. The result is a gp_Trsf transformation. A MakeMirror object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_gce_MakeMirror.def(py::init<const gp_Pnt &>(), py::arg("Point"));
cls_gce_MakeMirror.def(py::init<const gp_Ax1 &>(), py::arg("Axis"));
cls_gce_MakeMirror.def(py::init<const gp_Lin &>(), py::arg("Line"));
cls_gce_MakeMirror.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("Point"), py::arg("Direc"));
cls_gce_MakeMirror.def(py::init<const gp_Pln &>(), py::arg("Plane"));
cls_gce_MakeMirror.def(py::init<const gp_Ax2 &>(), py::arg("Plane"));

// Fields

// Methods
// cls_gce_MakeMirror.def_static("operator new_", (void * (*)(size_t)) &gce_MakeMirror::operator new, "None", py::arg("theSize"));
// cls_gce_MakeMirror.def_static("operator delete_", (void (*)(void *)) &gce_MakeMirror::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeMirror.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeMirror::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeMirror.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeMirror::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeMirror.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeMirror::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeMirror.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeMirror::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeMirror.def("Value", (const gp_Trsf & (gce_MakeMirror::*)() const) &gce_MakeMirror::Value, "Returns the constructed transformation.");
cls_gce_MakeMirror.def("Operator", (const gp_Trsf & (gce_MakeMirror::*)() const) &gce_MakeMirror::Operator, "None");

// Enums

}