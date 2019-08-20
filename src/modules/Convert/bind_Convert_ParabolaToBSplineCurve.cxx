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
#include <gp_Parab2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Convert_ParabolaToBSplineCurve.hxx>

void bind_Convert_ParabolaToBSplineCurve(py::module &mod){

py::class_<Convert_ParabolaToBSplineCurve, std::unique_ptr<Convert_ParabolaToBSplineCurve>, Convert_ConicToBSplineCurve> cls_Convert_ParabolaToBSplineCurve(mod, "Convert_ParabolaToBSplineCurve", "This algorithm converts a parabola into a non rational B-spline curve. The parabola is a Parab2d from package gp with the parametrization P (U) = Loc + F * (U*U * Xdir + 2 * U * Ydir) where Loc is the apex of the parabola, Xdir is the normalized direction of the symmetry axis of the parabola, Ydir is the normalized direction of the directrix and F is the focal length. KeyWords : Convert, Parabola, BSplineCurve, 2D .");

// Constructors
cls_Convert_ParabolaToBSplineCurve.def(py::init<const gp_Parab2d &, const Standard_Real, const Standard_Real>(), py::arg("Prb"), py::arg("U1"), py::arg("U2"));

// Fields

// Methods
// cls_Convert_ParabolaToBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &Convert_ParabolaToBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_Convert_ParabolaToBSplineCurve.def_static("operator delete_", (void (*)(void *)) &Convert_ParabolaToBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_Convert_ParabolaToBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &Convert_ParabolaToBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_Convert_ParabolaToBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &Convert_ParabolaToBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_ParabolaToBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_ParabolaToBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_ParabolaToBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &Convert_ParabolaToBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}