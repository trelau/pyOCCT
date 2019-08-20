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
#include <AppParCurves_MultiCurve.hxx>
#include <BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.hxx>

void bind_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox(py::module &mod){

py::class_<BRepApprox_MyGradientOfTheComputeLineBezierOfApprox, std::unique_ptr<BRepApprox_MyGradientOfTheComputeLineBezierOfApprox>> cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox(mod, "BRepApprox_MyGradientOfTheComputeLineBezierOfApprox", "None");

// Constructors
cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"));
cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIterations"));

// Fields

// Methods
// cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def("IsDone", (Standard_Boolean (BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::*)() const) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::IsDone, "returns True if all has been correctly done.");
cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def("Value", (AppParCurves_MultiCurve (BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::*)() const) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::Value, "returns all the Bezier curves approximating the MultiLine SSP after minimization of the parameter.");
cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def("Error", (Standard_Real (BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::*)(const Standard_Integer) const) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::Error, "returns the difference between the old and the new approximation. An exception is raised if NotDone. An exception is raised if Index<1 or Index>NbParameters.", py::arg("Index"));
cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def("MaxError3d", (Standard_Real (BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::*)() const) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::MaxError3d, "returns the maximum difference between the old and the new approximation.");
cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def("MaxError2d", (Standard_Real (BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::*)() const) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::MaxError2d, "returns the maximum difference between the old and the new approximation.");
cls_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.def("AverageError", (Standard_Real (BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::*)() const) &BRepApprox_MyGradientOfTheComputeLineBezierOfApprox::AverageError, "returns the average error between the old and the new approximation.");

// Enums

}