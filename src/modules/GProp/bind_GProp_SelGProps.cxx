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
#include <GProp_GProps.hxx>
#include <Standard.hxx>
#include <gp_Cylinder.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <GProp_SelGProps.hxx>

void bind_GProp_SelGProps(py::module &mod){

py::class_<GProp_SelGProps, std::unique_ptr<GProp_SelGProps>, GProp_GProps> cls_GProp_SelGProps(mod, "GProp_SelGProps", "Computes the global properties of a bounded elementary surface in 3d (surface of the gp package)");

// Constructors
cls_GProp_SelGProps.def(py::init<>());
cls_GProp_SelGProps.def(py::init<const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"), py::arg("SLocation"));
cls_GProp_SelGProps.def(py::init<const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"), py::arg("SLocation"));
cls_GProp_SelGProps.def(py::init<const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("SLocation"));
cls_GProp_SelGProps.def(py::init<const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("SLocation"));

// Fields

// Methods
// cls_GProp_SelGProps.def_static("operator new_", (void * (*)(size_t)) &GProp_SelGProps::operator new, "None", py::arg("theSize"));
// cls_GProp_SelGProps.def_static("operator delete_", (void (*)(void *)) &GProp_SelGProps::operator delete, "None", py::arg("theAddress"));
// cls_GProp_SelGProps.def_static("operator new[]_", (void * (*)(size_t)) &GProp_SelGProps::operator new[], "None", py::arg("theSize"));
// cls_GProp_SelGProps.def_static("operator delete[]_", (void (*)(void *)) &GProp_SelGProps::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_SelGProps.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_SelGProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_SelGProps.def_static("operator delete_", (void (*)(void *, void *)) &GProp_SelGProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_SelGProps.def("SetLocation", (void (GProp_SelGProps::*)(const gp_Pnt &)) &GProp_SelGProps::SetLocation, "None", py::arg("SLocation"));
cls_GProp_SelGProps.def("Perform", (void (GProp_SelGProps::*)(const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_SelGProps::Perform, "None", py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"));
cls_GProp_SelGProps.def("Perform", (void (GProp_SelGProps::*)(const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_SelGProps::Perform, "None", py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"));
cls_GProp_SelGProps.def("Perform", (void (GProp_SelGProps::*)(const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_SelGProps::Perform, "None", py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"));
cls_GProp_SelGProps.def("Perform", (void (GProp_SelGProps::*)(const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_SelGProps::Perform, "None", py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"));

// Enums

}