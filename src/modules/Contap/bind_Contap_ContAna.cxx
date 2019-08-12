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
#include <gp_Sphere.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Circ.hxx>
#include <gp_Lin.hxx>
#include <Contap_ContAna.hxx>

void bind_Contap_ContAna(py::module &mod){

py::class_<Contap_ContAna, std::unique_ptr<Contap_ContAna, Deleter<Contap_ContAna>>> cls_Contap_ContAna(mod, "Contap_ContAna", "This class provides the computation of the contours for quadric surfaces.");

// Constructors
cls_Contap_ContAna.def(py::init<>());

// Fields

// Methods
// cls_Contap_ContAna.def_static("operator new_", (void * (*)(size_t)) &Contap_ContAna::operator new, "None", py::arg("theSize"));
// cls_Contap_ContAna.def_static("operator delete_", (void (*)(void *)) &Contap_ContAna::operator delete, "None", py::arg("theAddress"));
// cls_Contap_ContAna.def_static("operator new[]_", (void * (*)(size_t)) &Contap_ContAna::operator new[], "None", py::arg("theSize"));
// cls_Contap_ContAna.def_static("operator delete[]_", (void (*)(void *)) &Contap_ContAna::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_ContAna.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_ContAna::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_ContAna.def_static("operator delete_", (void (*)(void *, void *)) &Contap_ContAna::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Sphere &, const gp_Dir &)) &Contap_ContAna::Perform, "None", py::arg("S"), py::arg("D"));
cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Sphere &, const gp_Dir &, const Standard_Real)) &Contap_ContAna::Perform, "None", py::arg("S"), py::arg("D"), py::arg("Ang"));
cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Sphere &, const gp_Pnt &)) &Contap_ContAna::Perform, "None", py::arg("S"), py::arg("Eye"));
cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cylinder &, const gp_Dir &)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("D"));
cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cylinder &, const gp_Dir &, const Standard_Real)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("D"), py::arg("Ang"));
cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cylinder &, const gp_Pnt &)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("Eye"));
cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cone &, const gp_Dir &)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("D"));
cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cone &, const gp_Dir &, const Standard_Real)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("D"), py::arg("Ang"));
cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cone &, const gp_Pnt &)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("Eye"));
cls_Contap_ContAna.def("IsDone", (Standard_Boolean (Contap_ContAna::*)() const) &Contap_ContAna::IsDone, "None");
cls_Contap_ContAna.def("NbContours", (Standard_Integer (Contap_ContAna::*)() const) &Contap_ContAna::NbContours, "None");
cls_Contap_ContAna.def("TypeContour", (GeomAbs_CurveType (Contap_ContAna::*)() const) &Contap_ContAna::TypeContour, "Returns GeomAbs_Line or GeomAbs_Circle, when IsDone() returns True.");
cls_Contap_ContAna.def("Circle", (gp_Circ (Contap_ContAna::*)() const) &Contap_ContAna::Circle, "None");
cls_Contap_ContAna.def("Line", (gp_Lin (Contap_ContAna::*)(const Standard_Integer) const) &Contap_ContAna::Line, "None", py::arg("Index"));

// Enums

}