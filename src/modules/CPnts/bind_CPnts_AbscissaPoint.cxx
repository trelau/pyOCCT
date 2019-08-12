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
#include <CPnts_MyRootFunction.hxx>
#include <CPnts_AbscissaPoint.hxx>

void bind_CPnts_AbscissaPoint(py::module &mod){

py::class_<CPnts_AbscissaPoint, std::unique_ptr<CPnts_AbscissaPoint, Deleter<CPnts_AbscissaPoint>>> cls_CPnts_AbscissaPoint(mod, "CPnts_AbscissaPoint", "the algorithm computes a point on a curve at a given distance from another point on the curve");

// Constructors
cls_CPnts_AbscissaPoint.def(py::init<>());
cls_CPnts_AbscissaPoint.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Resolution"));
cls_CPnts_AbscissaPoint.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Resolution"));
cls_CPnts_AbscissaPoint.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Resolution"));
cls_CPnts_AbscissaPoint.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Resolution"));

// Fields

// Methods
// cls_CPnts_AbscissaPoint.def_static("operator new_", (void * (*)(size_t)) &CPnts_AbscissaPoint::operator new, "None", py::arg("theSize"));
// cls_CPnts_AbscissaPoint.def_static("operator delete_", (void (*)(void *)) &CPnts_AbscissaPoint::operator delete, "None", py::arg("theAddress"));
// cls_CPnts_AbscissaPoint.def_static("operator new[]_", (void * (*)(size_t)) &CPnts_AbscissaPoint::operator new[], "None", py::arg("theSize"));
// cls_CPnts_AbscissaPoint.def_static("operator delete[]_", (void (*)(void *)) &CPnts_AbscissaPoint::operator delete[], "None", py::arg("theAddress"));
// cls_CPnts_AbscissaPoint.def_static("operator new_", (void * (*)(size_t, void *)) &CPnts_AbscissaPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CPnts_AbscissaPoint.def_static("operator delete_", (void (*)(void *, void *)) &CPnts_AbscissaPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"));
cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"));
cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance.", py::arg("C"), py::arg("Tol"));
cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance.", py::arg("C"), py::arg("Tol"));
cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> between <U1> and <U2>.", py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> between <U1> and <U2>.", py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> between <U1> and <U2> with the given tolerance.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> between <U1> and <U2> with the given tolerance. creation of a indefinite AbscissaPoint.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor3d_Curve &)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C>.", py::arg("C"));
cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor2d_Curve2d &)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C>.", py::arg("C"));
cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor3d_Curve &, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C>.", py::arg("C"), py::arg("Tol"));
cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor2d_Curve2d &, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C>.", py::arg("C"), py::arg("Tol"));
cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C> between U1 and U2.", py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C> between U1 and U2.", py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C> between U1 and U2.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C> between U1 and U2.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
cls_CPnts_AbscissaPoint.def("Perform", (void (CPnts_AbscissaPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Perform, "Computes the point at the distance <Abscissa> of the curve. U0 is the parameter of the point from which the distance is measured.", py::arg("Abscissa"), py::arg("U0"), py::arg("Resolution"));
cls_CPnts_AbscissaPoint.def("Perform", (void (CPnts_AbscissaPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Perform, "Computes the point at the distance <Abscissa> of the curve. U0 is the parameter of the point from which the distance is measured and Ui is the starting value for the iterative process (should be close to the final solution).", py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Resolution"));
cls_CPnts_AbscissaPoint.def("AdvPerform", (void (CPnts_AbscissaPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::AdvPerform, "Computes the point at the distance <Abscissa> of the curve; performs more appropriate tolerance managment; to use this method in right way it is necessary to call empty consructor. then call method Init with Tolerance = Resolution, then call AdvPermorm. U0 is the parameter of the point from which the distance is measured and Ui is the starting value for the iterative process (should be close to the final solution).", py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Resolution"));
cls_CPnts_AbscissaPoint.def("IsDone", (Standard_Boolean (CPnts_AbscissaPoint::*)() const) &CPnts_AbscissaPoint::IsDone, "True if the computation was successful, False otherwise.");
cls_CPnts_AbscissaPoint.def("Parameter", (Standard_Real (CPnts_AbscissaPoint::*)() const) &CPnts_AbscissaPoint::Parameter, "Returns the parameter of the solution.");
cls_CPnts_AbscissaPoint.def("SetParameter", (void (CPnts_AbscissaPoint::*)(const Standard_Real)) &CPnts_AbscissaPoint::SetParameter, "Enforce the solution, used by GCPnts.", py::arg("P"));

// Enums

}