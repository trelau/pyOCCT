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
#include <Convert_ConicToBSplineCurve.hxx>
#include <Standard.hxx>
#include <gp_Circ2d.hxx>
#include <Convert_ParameterisationType.hxx>
#include <Standard_TypeDef.hxx>
#include <Convert_CircleToBSplineCurve.hxx>

void bind_Convert_CircleToBSplineCurve(py::module &mod){

py::class_<Convert_CircleToBSplineCurve, std::unique_ptr<Convert_CircleToBSplineCurve>, Convert_ConicToBSplineCurve> cls_Convert_CircleToBSplineCurve(mod, "Convert_CircleToBSplineCurve", "This algorithm converts a circle into a rational B-spline curve. The circle is a Circ2d from package gp and its parametrization is : P (U) = Loc + R * (Cos(U) * Xdir + Sin(U) * YDir) where Loc is the center of the circle Xdir and Ydir are the normalized directions of the local cartesian coordinate system of the circle. The parametrization range for the circle is U [0, 2Pi].");

// Constructors
cls_Convert_CircleToBSplineCurve.def(py::init<const gp_Circ2d &>(), py::arg("C"));
cls_Convert_CircleToBSplineCurve.def(py::init<const gp_Circ2d &, const Convert_ParameterisationType>(), py::arg("C"), py::arg("Parameterisation"));
cls_Convert_CircleToBSplineCurve.def(py::init<const gp_Circ2d &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_Convert_CircleToBSplineCurve.def(py::init<const gp_Circ2d &, const Standard_Real, const Standard_Real, const Convert_ParameterisationType>(), py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Parameterisation"));

// Fields

// Methods
// cls_Convert_CircleToBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &Convert_CircleToBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_Convert_CircleToBSplineCurve.def_static("operator delete_", (void (*)(void *)) &Convert_CircleToBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_Convert_CircleToBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &Convert_CircleToBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_Convert_CircleToBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &Convert_CircleToBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_CircleToBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_CircleToBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_CircleToBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &Convert_CircleToBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}