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
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <CPnts_AbscissaPoint.hxx>
#include <GCPnts_AbscissaPoint.hxx>

void bind_GCPnts_AbscissaPoint(py::module &mod){

py::class_<GCPnts_AbscissaPoint> cls_GCPnts_AbscissaPoint(mod, "GCPnts_AbscissaPoint", "Provides an algorithm to compute a point on a curve situated at a given distance from another point on the curve, the distance being measured along the curve (curvilinear abscissa on the curve). This algorithm is also used to compute the length of a curve. An AbscissaPoint object provides a framework for: - defining the point to compute - implementing the construction algorithm - consulting the result.");

// Constructors
cls_GCPnts_AbscissaPoint.def(py::init<>());
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"));
cls_GCPnts_AbscissaPoint.def(py::init<const Standard_Real, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Tol"), py::arg("C"), py::arg("Abscissa"), py::arg("U0"));
cls_GCPnts_AbscissaPoint.def(py::init<const Standard_Real, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("Tol"), py::arg("C"), py::arg("Abscissa"), py::arg("U0"));
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"));
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"));
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"));
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Tol"));
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Tol"));

// Fields

// Methods
// cls_GCPnts_AbscissaPoint.def_static("operator new_", (void * (*)(size_t)) &GCPnts_AbscissaPoint::operator new, "None", py::arg("theSize"));
// cls_GCPnts_AbscissaPoint.def_static("operator delete_", (void (*)(void *)) &GCPnts_AbscissaPoint::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_AbscissaPoint.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_AbscissaPoint::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_AbscissaPoint.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_AbscissaPoint::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_AbscissaPoint.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_AbscissaPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_AbscissaPoint.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_AbscissaPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance.", py::arg("C"), py::arg("Tol"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance.", py::arg("C"), py::arg("Tol"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance. Constructs an empty algorithm. This function is used only for initializing a framework to compute the length of a curve (or a series of curves). Warning The function IsDone will return the value false after the use of this function.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
cls_GCPnts_AbscissaPoint.def("IsDone", (Standard_Boolean (GCPnts_AbscissaPoint::*)() const) &GCPnts_AbscissaPoint::IsDone, "True if the computation was successful, False otherwise. IsDone is a protection against: - non-convergence of the algorithm - querying the results before computation.");
cls_GCPnts_AbscissaPoint.def("Parameter", (Standard_Real (GCPnts_AbscissaPoint::*)() const) &GCPnts_AbscissaPoint::Parameter, "Returns the parameter on the curve of the point solution of this algorithm. Exceptions StdFail_NotDone if the computation was not successful, or was not done.");

// Enums

}