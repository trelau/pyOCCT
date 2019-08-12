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
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <math_Vector.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_ECC2d.hxx>

void bind_Extrema_ECC2d(py::module &mod){

py::class_<Extrema_ECC2d, std::unique_ptr<Extrema_ECC2d, Deleter<Extrema_ECC2d>>> cls_Extrema_ECC2d(mod, "Extrema_ECC2d", "None");

// Constructors
cls_Extrema_ECC2d.def(py::init<>());
cls_Extrema_ECC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ECC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"));

// Fields

// Methods
// cls_Extrema_ECC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_ECC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_ECC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_ECC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ECC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ECC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ECC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ECC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ECC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ECC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ECC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ECC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ECC2d.def("SetParams", (void (Extrema_ECC2d::*)(const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ECC2d::SetParams, "Set params in case of empty constructor is usage.", py::arg("C1"), py::arg("C2"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"));
cls_Extrema_ECC2d.def("SetTolerance", (void (Extrema_ECC2d::*)(const Standard_Real)) &Extrema_ECC2d::SetTolerance, "None", py::arg("Tol"));
cls_Extrema_ECC2d.def("SetSingleSolutionFlag", (void (Extrema_ECC2d::*)(const Standard_Boolean)) &Extrema_ECC2d::SetSingleSolutionFlag, "Set flag for single extrema computation. Works on parametric solver only.", py::arg("theSingleSolutionFlag"));
cls_Extrema_ECC2d.def("GetSingleSolutionFlag", (Standard_Boolean (Extrema_ECC2d::*)() const) &Extrema_ECC2d::GetSingleSolutionFlag, "Get flag for single extrema computation. Works on parametric solver only.");
cls_Extrema_ECC2d.def("Perform", (void (Extrema_ECC2d::*)()) &Extrema_ECC2d::Perform, "Performs calculations.");
cls_Extrema_ECC2d.def("IsDone", (Standard_Boolean (Extrema_ECC2d::*)() const) &Extrema_ECC2d::IsDone, "Returns True if the distances are found.");
cls_Extrema_ECC2d.def("IsParallel", (Standard_Boolean (Extrema_ECC2d::*)() const) &Extrema_ECC2d::IsParallel, "Returns state of myParallel flag.");
cls_Extrema_ECC2d.def("NbExt", (Standard_Integer (Extrema_ECC2d::*)() const) &Extrema_ECC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ECC2d.def("SquareDistance", [](Extrema_ECC2d &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ECC2d.def("SquareDistance", (Standard_Real (Extrema_ECC2d::*)(const Standard_Integer) const) &Extrema_ECC2d::SquareDistance, "Returns the value of the Nth square extremum distance.", py::arg("N"));
cls_Extrema_ECC2d.def("Points", (void (Extrema_ECC2d::*)(const Standard_Integer, Extrema_POnCurv2d &, Extrema_POnCurv2d &) const) &Extrema_ECC2d::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// Enums

}