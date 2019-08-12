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
#include <BRepApprox_TheMultiLineOfApprox.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <math_Vector.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.hxx>

void bind_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox(py::module &mod){

py::class_<BRepApprox_MyBSplGradientOfTheComputeLineOfApprox, std::unique_ptr<BRepApprox_MyBSplGradientOfTheComputeLineOfApprox, Deleter<BRepApprox_MyBSplGradientOfTheComputeLineOfApprox>>> cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox(mod, "BRepApprox_MyBSplGradientOfTheComputeLineOfApprox", "None");

// Constructors
cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Knots"), py::arg("Mults"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"));
cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Knots"), py::arg("Mults"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIterations"));
cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Knots"), py::arg("Mults"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIterations"), py::arg("lambda1"), py::arg("lambda2"));

// Fields

// Methods
// cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def("IsDone", (Standard_Boolean (BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::*)() const) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::IsDone, "returns True if all has been correctly done.");
cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def("Value", (AppParCurves_MultiBSpCurve (BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::*)() const) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::Value, "returns all the BSpline curves approximating the MultiLine SSP after minimization of the parameter.");
cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def("Error", (Standard_Real (BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::*)(const Standard_Integer) const) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::Error, "returns the difference between the old and the new approximation. An exception is raised if NotDone. An exception is raised if Index<1 or Index>NbParameters.", py::arg("Index"));
cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def("MaxError3d", (Standard_Real (BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::*)() const) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::MaxError3d, "returns the maximum difference between the old and the new approximation.");
cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def("MaxError2d", (Standard_Real (BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::*)() const) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::MaxError2d, "returns the maximum difference between the old and the new approximation.");
cls_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.def("AverageError", (Standard_Real (BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::*)() const) &BRepApprox_MyBSplGradientOfTheComputeLineOfApprox::AverageError, "returns the average error between the old and the new approximation.");

// Enums

}