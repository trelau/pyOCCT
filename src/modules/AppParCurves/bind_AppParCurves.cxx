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
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <math_IntegerVector.hxx>
#include <AppParCurves_MultiPoint.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <AppParCurves_ConstraintCouple.hxx>
#include <AppParCurves.hxx>

void bind_AppParCurves(py::module &mod){

py::class_<AppParCurves> cls_AppParCurves(mod, "AppParCurves", "Parallel Approximation in n curves. This package gives all the algorithms used to approximate a MultiLine described by the tool MLineTool. The result of the approximation will be a MultiCurve.");

// Constructors

// Fields

// Methods
// cls_AppParCurves.def_static("operator new_", (void * (*)(size_t)) &AppParCurves::operator new, "None", py::arg("theSize"));
// cls_AppParCurves.def_static("operator delete_", (void (*)(void *)) &AppParCurves::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves::operator delete, "None", py::arg(""), py::arg(""));
cls_AppParCurves.def_static("BernsteinMatrix_", (void (*)(const Standard_Integer, const math_Vector &, math_Matrix &)) &AppParCurves::BernsteinMatrix, "None", py::arg("NbPoles"), py::arg("U"), py::arg("A"));
cls_AppParCurves.def_static("Bernstein_", (void (*)(const Standard_Integer, const math_Vector &, math_Matrix &, math_Matrix &)) &AppParCurves::Bernstein, "None", py::arg("NbPoles"), py::arg("U"), py::arg("A"), py::arg("DA"));
cls_AppParCurves.def_static("SecondDerivativeBernstein_", (void (*)(const Standard_Real, math_Vector &)) &AppParCurves::SecondDerivativeBernstein, "None", py::arg("U"), py::arg("DDA"));
cls_AppParCurves.def_static("SplineFunction_", (void (*)(const Standard_Integer, const Standard_Integer, const math_Vector &, const math_Vector &, math_Matrix &, math_Matrix &, math_IntegerVector &)) &AppParCurves::SplineFunction, "None", py::arg("NbPoles"), py::arg("Degree"), py::arg("Parameters"), py::arg("FlatKnots"), py::arg("A"), py::arg("DA"), py::arg("Index"));

// Enums

}