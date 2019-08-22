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
#include <gp_Cylinder.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pln.hxx>
#include <gp_Cone.hxx>
#include <gp_Torus.hxx>
#include <gp_Sphere.hxx>
#include <Extrema_POnSurf.hxx>
#include <Extrema_ExtPElS.hxx>

void bind_Extrema_ExtPElS(py::module &mod){

py::class_<Extrema_ExtPElS> cls_Extrema_ExtPElS(mod, "Extrema_ExtPElS", "It calculates all the extremum distances between a point and a surface. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtPElS.def(py::init<>());
cls_Extrema_ExtPElS.def(py::init<const gp_Pnt &, const gp_Cylinder &, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def(py::init<const gp_Pnt &, const gp_Pln &, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def(py::init<const gp_Pnt &, const gp_Cone &, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def(py::init<const gp_Pnt &, const gp_Torus &, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def(py::init<const gp_Pnt &, const gp_Sphere &, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Tol"));

// Fields

// Methods
// cls_Extrema_ExtPElS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtPElS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtPElS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtPElS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtPElS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtPElS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtPElS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtPElS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtPElS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtPElS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtPElS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtPElS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtPElS.def("Perform", (void (Extrema_ExtPElS::*)(const gp_Pnt &, const gp_Cylinder &, const Standard_Real)) &Extrema_ExtPElS::Perform, "None", py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def("Perform", (void (Extrema_ExtPElS::*)(const gp_Pnt &, const gp_Pln &, const Standard_Real)) &Extrema_ExtPElS::Perform, "None", py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def("Perform", (void (Extrema_ExtPElS::*)(const gp_Pnt &, const gp_Cone &, const Standard_Real)) &Extrema_ExtPElS::Perform, "None", py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def("Perform", (void (Extrema_ExtPElS::*)(const gp_Pnt &, const gp_Torus &, const Standard_Real)) &Extrema_ExtPElS::Perform, "None", py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def("Perform", (void (Extrema_ExtPElS::*)(const gp_Pnt &, const gp_Sphere &, const Standard_Real)) &Extrema_ExtPElS::Perform, "None", py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def("IsDone", (Standard_Boolean (Extrema_ExtPElS::*)() const) &Extrema_ExtPElS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtPElS.def("NbExt", (Standard_Integer (Extrema_ExtPElS::*)() const) &Extrema_ExtPElS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPElS.def("SquareDistance", (Standard_Real (Extrema_ExtPElS::*)(const Standard_Integer) const) &Extrema_ExtPElS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_ExtPElS.def("Point", (const Extrema_POnSurf & (Extrema_ExtPElS::*)(const Standard_Integer) const) &Extrema_ExtPElS::Point, "Returns the point of the Nth resulting distance.", py::arg("N"));

// Enums

}