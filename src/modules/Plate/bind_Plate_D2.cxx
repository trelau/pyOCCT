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
#include <Plate_D2.hxx>
#include <Plate_GtoCConstraint.hxx>
#include <Plate_FreeGtoCConstraint.hxx>

void bind_Plate_D2(py::module &mod){

py::class_<Plate_D2, std::unique_ptr<Plate_D2, Deleter<Plate_D2>>> cls_Plate_D2(mod, "Plate_D2", "define an order 2 derivatives of a 3d valued function of a 2d variable");

// Constructors
cls_Plate_D2.def(py::init<const gp_XYZ &, const gp_XYZ &, const gp_XYZ &>(), py::arg("duu"), py::arg("duv"), py::arg("dvv"));
cls_Plate_D2.def(py::init<const Plate_D2 &>(), py::arg("ref"));

// Fields

// Methods
// cls_Plate_D2.def_static("operator new_", (void * (*)(size_t)) &Plate_D2::operator new, "None", py::arg("theSize"));
// cls_Plate_D2.def_static("operator delete_", (void (*)(void *)) &Plate_D2::operator delete, "None", py::arg("theAddress"));
// cls_Plate_D2.def_static("operator new[]_", (void * (*)(size_t)) &Plate_D2::operator new[], "None", py::arg("theSize"));
// cls_Plate_D2.def_static("operator delete[]_", (void (*)(void *)) &Plate_D2::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_D2.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_D2::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_D2.def_static("operator delete_", (void (*)(void *, void *)) &Plate_D2::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}