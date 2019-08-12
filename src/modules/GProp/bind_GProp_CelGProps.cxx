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
#include <gp_Circ.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin.hxx>
#include <GProp_CelGProps.hxx>

void bind_GProp_CelGProps(py::module &mod){

py::class_<GProp_CelGProps, std::unique_ptr<GProp_CelGProps, Deleter<GProp_CelGProps>>, GProp_GProps> cls_GProp_CelGProps(mod, "GProp_CelGProps", "Computes the global properties of bounded curves in 3D space. It can be an elementary curve from package gp such as Lin, Circ, Elips, Parab .");

// Constructors
cls_GProp_CelGProps.def(py::init<>());
cls_GProp_CelGProps.def(py::init<const gp_Circ &, const gp_Pnt &>(), py::arg("C"), py::arg("CLocation"));
cls_GProp_CelGProps.def(py::init<const gp_Circ &, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("CLocation"));
cls_GProp_CelGProps.def(py::init<const gp_Lin &, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("CLocation"));

// Fields

// Methods
// cls_GProp_CelGProps.def_static("operator new_", (void * (*)(size_t)) &GProp_CelGProps::operator new, "None", py::arg("theSize"));
// cls_GProp_CelGProps.def_static("operator delete_", (void (*)(void *)) &GProp_CelGProps::operator delete, "None", py::arg("theAddress"));
// cls_GProp_CelGProps.def_static("operator new[]_", (void * (*)(size_t)) &GProp_CelGProps::operator new[], "None", py::arg("theSize"));
// cls_GProp_CelGProps.def_static("operator delete[]_", (void (*)(void *)) &GProp_CelGProps::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_CelGProps.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_CelGProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_CelGProps.def_static("operator delete_", (void (*)(void *, void *)) &GProp_CelGProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_CelGProps.def("SetLocation", (void (GProp_CelGProps::*)(const gp_Pnt &)) &GProp_CelGProps::SetLocation, "None", py::arg("CLocation"));
cls_GProp_CelGProps.def("Perform", (void (GProp_CelGProps::*)(const gp_Circ &, const Standard_Real, const Standard_Real)) &GProp_CelGProps::Perform, "None", py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_GProp_CelGProps.def("Perform", (void (GProp_CelGProps::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &GProp_CelGProps::Perform, "None", py::arg("C"), py::arg("U1"), py::arg("U2"));

// Enums

}