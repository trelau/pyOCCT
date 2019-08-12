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
#include <ProjLib_Projector.hxx>
#include <Standard.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab.hxx>
#include <gp_Hypr.hxx>
#include <ProjLib_Cylinder.hxx>

void bind_ProjLib_Cylinder(py::module &mod){

py::class_<ProjLib_Cylinder, std::unique_ptr<ProjLib_Cylinder, Deleter<ProjLib_Cylinder>>, ProjLib_Projector> cls_ProjLib_Cylinder(mod, "ProjLib_Cylinder", "Projects elementary curves on a cylinder.");

// Constructors
cls_ProjLib_Cylinder.def(py::init<>());
cls_ProjLib_Cylinder.def(py::init<const gp_Cylinder &>(), py::arg("Cyl"));
cls_ProjLib_Cylinder.def(py::init<const gp_Cylinder &, const gp_Lin &>(), py::arg("Cyl"), py::arg("L"));
cls_ProjLib_Cylinder.def(py::init<const gp_Cylinder &, const gp_Circ &>(), py::arg("Cyl"), py::arg("C"));
cls_ProjLib_Cylinder.def(py::init<const gp_Cylinder &, const gp_Elips &>(), py::arg("Cyl"), py::arg("E"));

// Fields

// Methods
// cls_ProjLib_Cylinder.def_static("operator new_", (void * (*)(size_t)) &ProjLib_Cylinder::operator new, "None", py::arg("theSize"));
// cls_ProjLib_Cylinder.def_static("operator delete_", (void (*)(void *)) &ProjLib_Cylinder::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_Cylinder.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_Cylinder::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_Cylinder.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_Cylinder::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_Cylinder.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_Cylinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_Cylinder.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_Cylinder::operator delete, "None", py::arg(""), py::arg(""));
cls_ProjLib_Cylinder.def("Init", (void (ProjLib_Cylinder::*)(const gp_Cylinder &)) &ProjLib_Cylinder::Init, "None", py::arg("Cyl"));
cls_ProjLib_Cylinder.def("Project", (void (ProjLib_Cylinder::*)(const gp_Lin &)) &ProjLib_Cylinder::Project, "None", py::arg("L"));
cls_ProjLib_Cylinder.def("Project", (void (ProjLib_Cylinder::*)(const gp_Circ &)) &ProjLib_Cylinder::Project, "None", py::arg("C"));
cls_ProjLib_Cylinder.def("Project", (void (ProjLib_Cylinder::*)(const gp_Elips &)) &ProjLib_Cylinder::Project, "None", py::arg("E"));
cls_ProjLib_Cylinder.def("Project", (void (ProjLib_Cylinder::*)(const gp_Parab &)) &ProjLib_Cylinder::Project, "None", py::arg("P"));
cls_ProjLib_Cylinder.def("Project", (void (ProjLib_Cylinder::*)(const gp_Hypr &)) &ProjLib_Cylinder::Project, "None", py::arg("H"));

// Enums

}