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
#include <gp_XYZ.hxx>
#include <Plate_D1.hxx>
#include <Plate_GtoCConstraint.hxx>
#include <Plate_FreeGtoCConstraint.hxx>

void bind_Plate_D1(py::module &mod){

py::class_<Plate_D1, std::unique_ptr<Plate_D1>> cls_Plate_D1(mod, "Plate_D1", "define an order 1 derivatives of a 3d valued function of a 2d variable");

// Constructors
cls_Plate_D1.def(py::init<const gp_XYZ &, const gp_XYZ &>(), py::arg("du"), py::arg("dv"));
cls_Plate_D1.def(py::init<const Plate_D1 &>(), py::arg("ref"));

// Fields

// Methods
// cls_Plate_D1.def_static("operator new_", (void * (*)(size_t)) &Plate_D1::operator new, "None", py::arg("theSize"));
// cls_Plate_D1.def_static("operator delete_", (void (*)(void *)) &Plate_D1::operator delete, "None", py::arg("theAddress"));
// cls_Plate_D1.def_static("operator new[]_", (void * (*)(size_t)) &Plate_D1::operator new[], "None", py::arg("theSize"));
// cls_Plate_D1.def_static("operator delete[]_", (void (*)(void *)) &Plate_D1::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_D1.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_D1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_D1.def_static("operator delete_", (void (*)(void *, void *)) &Plate_D1::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_D1.def("DU", (const gp_XYZ & (Plate_D1::*)() const) &Plate_D1::DU, "None");
cls_Plate_D1.def("DV", (const gp_XYZ & (Plate_D1::*)() const) &Plate_D1::DV, "None");

// Enums

}