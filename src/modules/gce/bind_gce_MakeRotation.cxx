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
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Trsf.hxx>
#include <gce_MakeRotation.hxx>

void bind_gce_MakeRotation(py::module &mod){

py::class_<gce_MakeRotation, std::unique_ptr<gce_MakeRotation>> cls_gce_MakeRotation(mod, "gce_MakeRotation", "This class implements elementary construction algorithms for a rotation in 3D space. The result is a gp_Trsf transformation. A MakeRotation object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_gce_MakeRotation.def(py::init<const gp_Lin &, const Standard_Real>(), py::arg("Line"), py::arg("Angle"));
cls_gce_MakeRotation.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Angle"));
cls_gce_MakeRotation.def(py::init<const gp_Pnt &, const gp_Dir &, const Standard_Real>(), py::arg("Point"), py::arg("Direc"), py::arg("Angle"));

// Fields

// Methods
// cls_gce_MakeRotation.def_static("operator new_", (void * (*)(size_t)) &gce_MakeRotation::operator new, "None", py::arg("theSize"));
// cls_gce_MakeRotation.def_static("operator delete_", (void (*)(void *)) &gce_MakeRotation::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeRotation.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeRotation::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeRotation.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeRotation::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeRotation.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeRotation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeRotation.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeRotation::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeRotation.def("Value", (const gp_Trsf & (gce_MakeRotation::*)() const) &gce_MakeRotation::Value, "Returns the constructed transformation.");
cls_gce_MakeRotation.def("Operator", (const gp_Trsf & (gce_MakeRotation::*)() const) &gce_MakeRotation::Operator, "None");

// Enums

}