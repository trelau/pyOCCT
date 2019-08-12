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
#include <gp_Vec.hxx>
#include <gp_Pnt.hxx>
#include <gp_Trsf.hxx>
#include <gce_MakeTranslation.hxx>

void bind_gce_MakeTranslation(py::module &mod){

py::class_<gce_MakeTranslation, std::unique_ptr<gce_MakeTranslation, Deleter<gce_MakeTranslation>>> cls_gce_MakeTranslation(mod, "gce_MakeTranslation", "This class implements elementary construction algorithms for a translation in 3D space. The result is a gp_Trsf transformation. A MakeTranslation object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_gce_MakeTranslation.def(py::init<const gp_Vec &>(), py::arg("Vect"));
cls_gce_MakeTranslation.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("Point1"), py::arg("Point2"));

// Fields

// Methods
// cls_gce_MakeTranslation.def_static("operator new_", (void * (*)(size_t)) &gce_MakeTranslation::operator new, "None", py::arg("theSize"));
// cls_gce_MakeTranslation.def_static("operator delete_", (void (*)(void *)) &gce_MakeTranslation::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeTranslation.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeTranslation::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeTranslation.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeTranslation::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeTranslation.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeTranslation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeTranslation.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeTranslation::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeTranslation.def("Value", (const gp_Trsf & (gce_MakeTranslation::*)() const) &gce_MakeTranslation::Value, "Returns the constructed transformation.");
cls_gce_MakeTranslation.def("Operator", (const gp_Trsf & (gce_MakeTranslation::*)() const) &gce_MakeTranslation::Operator, "None");

// Enums

}