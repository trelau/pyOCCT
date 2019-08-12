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
#include <gp_Pln.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab.hxx>
#include <gp_Hypr.hxx>
#include <ProjLib_Plane.hxx>

void bind_ProjLib_Plane(py::module &mod){

py::class_<ProjLib_Plane, std::unique_ptr<ProjLib_Plane, Deleter<ProjLib_Plane>>, ProjLib_Projector> cls_ProjLib_Plane(mod, "ProjLib_Plane", "Projects elementary curves on a plane.");

// Constructors
cls_ProjLib_Plane.def(py::init<>());
cls_ProjLib_Plane.def(py::init<const gp_Pln &>(), py::arg("Pl"));
cls_ProjLib_Plane.def(py::init<const gp_Pln &, const gp_Lin &>(), py::arg("Pl"), py::arg("L"));
cls_ProjLib_Plane.def(py::init<const gp_Pln &, const gp_Circ &>(), py::arg("Pl"), py::arg("C"));
cls_ProjLib_Plane.def(py::init<const gp_Pln &, const gp_Elips &>(), py::arg("Pl"), py::arg("E"));
cls_ProjLib_Plane.def(py::init<const gp_Pln &, const gp_Parab &>(), py::arg("Pl"), py::arg("P"));
cls_ProjLib_Plane.def(py::init<const gp_Pln &, const gp_Hypr &>(), py::arg("Pl"), py::arg("H"));

// Fields

// Methods
// cls_ProjLib_Plane.def_static("operator new_", (void * (*)(size_t)) &ProjLib_Plane::operator new, "None", py::arg("theSize"));
// cls_ProjLib_Plane.def_static("operator delete_", (void (*)(void *)) &ProjLib_Plane::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_Plane.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_Plane::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_Plane.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_Plane::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_Plane.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_Plane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_Plane.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_Plane::operator delete, "None", py::arg(""), py::arg(""));
cls_ProjLib_Plane.def("Init", (void (ProjLib_Plane::*)(const gp_Pln &)) &ProjLib_Plane::Init, "None", py::arg("Pl"));
cls_ProjLib_Plane.def("Project", (void (ProjLib_Plane::*)(const gp_Lin &)) &ProjLib_Plane::Project, "None", py::arg("L"));
cls_ProjLib_Plane.def("Project", (void (ProjLib_Plane::*)(const gp_Circ &)) &ProjLib_Plane::Project, "None", py::arg("C"));
cls_ProjLib_Plane.def("Project", (void (ProjLib_Plane::*)(const gp_Elips &)) &ProjLib_Plane::Project, "None", py::arg("E"));
cls_ProjLib_Plane.def("Project", (void (ProjLib_Plane::*)(const gp_Parab &)) &ProjLib_Plane::Project, "None", py::arg("P"));
cls_ProjLib_Plane.def("Project", (void (ProjLib_Plane::*)(const gp_Hypr &)) &ProjLib_Plane::Project, "None", py::arg("H"));

// Enums

}