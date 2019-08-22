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
#include <gp_Pln.hxx>
#include <gp_Sphere.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax3.hxx>
#include <IntAna_Quadric.hxx>

void bind_IntAna_Quadric(py::module &mod){

py::class_<IntAna_Quadric> cls_IntAna_Quadric(mod, "IntAna_Quadric", "This class provides a description of Quadrics by their Coefficients in natural coordinate system.");

// Constructors
cls_IntAna_Quadric.def(py::init<>());
cls_IntAna_Quadric.def(py::init<const gp_Pln &>(), py::arg("P"));
cls_IntAna_Quadric.def(py::init<const gp_Sphere &>(), py::arg("Sph"));
cls_IntAna_Quadric.def(py::init<const gp_Cylinder &>(), py::arg("Cyl"));
cls_IntAna_Quadric.def(py::init<const gp_Cone &>(), py::arg("Cone"));

// Fields

// Methods
// cls_IntAna_Quadric.def_static("operator new_", (void * (*)(size_t)) &IntAna_Quadric::operator new, "None", py::arg("theSize"));
// cls_IntAna_Quadric.def_static("operator delete_", (void (*)(void *)) &IntAna_Quadric::operator delete, "None", py::arg("theAddress"));
// cls_IntAna_Quadric.def_static("operator new[]_", (void * (*)(size_t)) &IntAna_Quadric::operator new[], "None", py::arg("theSize"));
// cls_IntAna_Quadric.def_static("operator delete[]_", (void (*)(void *)) &IntAna_Quadric::operator delete[], "None", py::arg("theAddress"));
// cls_IntAna_Quadric.def_static("operator new_", (void * (*)(size_t, void *)) &IntAna_Quadric::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntAna_Quadric.def_static("operator delete_", (void (*)(void *, void *)) &IntAna_Quadric::operator delete, "None", py::arg(""), py::arg(""));
cls_IntAna_Quadric.def("SetQuadric", (void (IntAna_Quadric::*)(const gp_Pln &)) &IntAna_Quadric::SetQuadric, "Initializes the quadric with a Pln", py::arg("P"));
cls_IntAna_Quadric.def("SetQuadric", (void (IntAna_Quadric::*)(const gp_Sphere &)) &IntAna_Quadric::SetQuadric, "Initialize the quadric with a Sphere", py::arg("Sph"));
cls_IntAna_Quadric.def("SetQuadric", (void (IntAna_Quadric::*)(const gp_Cone &)) &IntAna_Quadric::SetQuadric, "Initializes the quadric with a Cone", py::arg("Con"));
cls_IntAna_Quadric.def("SetQuadric", (void (IntAna_Quadric::*)(const gp_Cylinder &)) &IntAna_Quadric::SetQuadric, "Initializes the quadric with a Cylinder", py::arg("Cyl"));
cls_IntAna_Quadric.def("Coefficients", [](IntAna_Quadric &self, Standard_Real & xCXX, Standard_Real & xCYY, Standard_Real & xCZZ, Standard_Real & xCXY, Standard_Real & xCXZ, Standard_Real & xCYZ, Standard_Real & xCX, Standard_Real & xCY, Standard_Real & xCZ, Standard_Real & xCCte){ self.Coefficients(xCXX, xCYY, xCZZ, xCXY, xCXZ, xCYZ, xCX, xCY, xCZ, xCCte); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(xCXX, xCYY, xCZZ, xCXY, xCXZ, xCYZ, xCX, xCY, xCZ, xCCte); }, "Returns the coefficients of the polynomial equation which define the quadric: xCXX x**2 + xCYY y**2 + xCZZ z**2 + 2 ( xCXY x y + xCXZ x z + xCYZ y z ) + 2 ( xCX x + xCY y + xCZ z ) + xCCte", py::arg("xCXX"), py::arg("xCYY"), py::arg("xCZZ"), py::arg("xCXY"), py::arg("xCXZ"), py::arg("xCYZ"), py::arg("xCX"), py::arg("xCY"), py::arg("xCZ"), py::arg("xCCte"));
cls_IntAna_Quadric.def("NewCoefficients", [](IntAna_Quadric &self, Standard_Real & xCXX, Standard_Real & xCYY, Standard_Real & xCZZ, Standard_Real & xCXY, Standard_Real & xCXZ, Standard_Real & xCYZ, Standard_Real & xCX, Standard_Real & xCY, Standard_Real & xCZ, Standard_Real & xCCte, const gp_Ax3 & Axis){ self.NewCoefficients(xCXX, xCYY, xCZZ, xCXY, xCXZ, xCYZ, xCX, xCY, xCZ, xCCte, Axis); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(xCXX, xCYY, xCZZ, xCXY, xCXZ, xCYZ, xCX, xCY, xCZ, xCCte); }, "Returns the coefficients of the polynomial equation ( written in the natural coordinates system ) in the local coordinates system defined by Axis", py::arg("xCXX"), py::arg("xCYY"), py::arg("xCZZ"), py::arg("xCXY"), py::arg("xCXZ"), py::arg("xCYZ"), py::arg("xCX"), py::arg("xCY"), py::arg("xCZ"), py::arg("xCCte"), py::arg("Axis"));

// Enums

}