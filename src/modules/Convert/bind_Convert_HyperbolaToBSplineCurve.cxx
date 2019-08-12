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
#include <gp_Hypr2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Convert_HyperbolaToBSplineCurve.hxx>

void bind_Convert_HyperbolaToBSplineCurve(py::module &mod){

py::class_<Convert_HyperbolaToBSplineCurve, std::unique_ptr<Convert_HyperbolaToBSplineCurve, Deleter<Convert_HyperbolaToBSplineCurve>>, Convert_ConicToBSplineCurve> cls_Convert_HyperbolaToBSplineCurve(mod, "Convert_HyperbolaToBSplineCurve", "This algorithm converts a hyperbola into a rational B-spline curve. The hyperbola is an Hypr2d from package gp with the parametrization : P (U) = Loc + (MajorRadius * Cosh(U) * Xdir + MinorRadius * Sinh(U) * Ydir) where Loc is the location point of the hyperbola, Xdir and Ydir are the normalized directions of the local cartesian coordinate system of the hyperbola. KeyWords : Convert, Hyperbola, BSplineCurve, 2D .");

// Constructors
cls_Convert_HyperbolaToBSplineCurve.def(py::init<const gp_Hypr2d &, const Standard_Real, const Standard_Real>(), py::arg("H"), py::arg("U1"), py::arg("U2"));

// Fields

// Methods
// cls_Convert_HyperbolaToBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &Convert_HyperbolaToBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_Convert_HyperbolaToBSplineCurve.def_static("operator delete_", (void (*)(void *)) &Convert_HyperbolaToBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_Convert_HyperbolaToBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &Convert_HyperbolaToBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_Convert_HyperbolaToBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &Convert_HyperbolaToBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_HyperbolaToBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_HyperbolaToBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_HyperbolaToBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &Convert_HyperbolaToBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}