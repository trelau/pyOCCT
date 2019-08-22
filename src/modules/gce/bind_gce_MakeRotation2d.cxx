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
#include <Standard_TypeDef.hxx>
#include <gp_Trsf2d.hxx>
#include <gce_MakeRotation2d.hxx>

void bind_gce_MakeRotation2d(py::module &mod){

py::class_<gce_MakeRotation2d> cls_gce_MakeRotation2d(mod, "gce_MakeRotation2d", "Implements an elementary construction algorithm for a rotation in 2D space. The result is a gp_Trsf2d transformation. A MakeRotation2d object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_gce_MakeRotation2d.def(py::init<const gp_Pnt2d &, const Standard_Real>(), py::arg("Point"), py::arg("Angle"));

// Fields

// Methods
// cls_gce_MakeRotation2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeRotation2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeRotation2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeRotation2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeRotation2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeRotation2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeRotation2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeRotation2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeRotation2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeRotation2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeRotation2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeRotation2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeRotation2d.def("Value", (const gp_Trsf2d & (gce_MakeRotation2d::*)() const) &gce_MakeRotation2d::Value, "Returns the constructed transformation.");
cls_gce_MakeRotation2d.def("Operator", (const gp_Trsf2d & (gce_MakeRotation2d::*)() const) &gce_MakeRotation2d::Operator, "None");

// Enums

}