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
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv.hxx>
#include <math_Vector.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_ECC.hxx>

void bind_Extrema_ECC(py::module &mod){

py::class_<Extrema_ECC, std::unique_ptr<Extrema_ECC, Deleter<Extrema_ECC>>> cls_Extrema_ECC(mod, "Extrema_ECC", "None");

// Constructors
cls_Extrema_ECC.def(py::init<>());
cls_Extrema_ECC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ECC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"));

// Fields

// Methods
// cls_Extrema_ECC.def_static("operator new_", (void * (*)(size_t)) &Extrema_ECC::operator new, "None", py::arg("theSize"));
// cls_Extrema_ECC.def_static("operator delete_", (void (*)(void *)) &Extrema_ECC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ECC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ECC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ECC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ECC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ECC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ECC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ECC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ECC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ECC.def("SetParams", (void (Extrema_ECC::*)(const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ECC::SetParams, "Set params in case of empty constructor is usage.", py::arg("C1"), py::arg("C2"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"));
cls_Extrema_ECC.def("SetTolerance", (void (Extrema_ECC::*)(const Standard_Real)) &Extrema_ECC::SetTolerance, "None", py::arg("Tol"));
cls_Extrema_ECC.def("SetSingleSolutionFlag", (void (Extrema_ECC::*)(const Standard_Boolean)) &Extrema_ECC::SetSingleSolutionFlag, "Set flag for single extrema computation. Works on parametric solver only.", py::arg("theSingleSolutionFlag"));
cls_Extrema_ECC.def("GetSingleSolutionFlag", (Standard_Boolean (Extrema_ECC::*)() const) &Extrema_ECC::GetSingleSolutionFlag, "Get flag for single extrema computation. Works on parametric solver only.");
cls_Extrema_ECC.def("Perform", (void (Extrema_ECC::*)()) &Extrema_ECC::Perform, "Performs calculations.");
cls_Extrema_ECC.def("IsDone", (Standard_Boolean (Extrema_ECC::*)() const) &Extrema_ECC::IsDone, "Returns True if the distances are found.");
cls_Extrema_ECC.def("IsParallel", (Standard_Boolean (Extrema_ECC::*)() const) &Extrema_ECC::IsParallel, "Returns state of myParallel flag.");
cls_Extrema_ECC.def("NbExt", (Standard_Integer (Extrema_ECC::*)() const) &Extrema_ECC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ECC.def("SquareDistance", [](Extrema_ECC &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ECC.def("SquareDistance", (Standard_Real (Extrema_ECC::*)(const Standard_Integer) const) &Extrema_ECC::SquareDistance, "Returns the value of the Nth square extremum distance.", py::arg("N"));
cls_Extrema_ECC.def("Points", (void (Extrema_ECC::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_ECC::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// Enums

}