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
#include <AppDef_MultiLine.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <AppDef_ResConstraintOfTheGradient.hxx>

void bind_AppDef_ResConstraintOfTheGradient(py::module &mod){

py::class_<AppDef_ResConstraintOfTheGradient, std::unique_ptr<AppDef_ResConstraintOfTheGradient>> cls_AppDef_ResConstraintOfTheGradient(mod, "AppDef_ResConstraintOfTheGradient", "None");

// Constructors
cls_AppDef_ResConstraintOfTheGradient.def(py::init<const AppDef_MultiLine &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"));
cls_AppDef_ResConstraintOfTheGradient.def(py::init<const AppDef_MultiLine &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &, const Standard_Real>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"), py::arg("Tolerance"));

// Fields

// Methods
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator new_", (void * (*)(size_t)) &AppDef_ResConstraintOfTheGradient::operator new, "None", py::arg("theSize"));
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator delete_", (void (*)(void *)) &AppDef_ResConstraintOfTheGradient::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_ResConstraintOfTheGradient::operator new[], "None", py::arg("theSize"));
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator delete[]_", (void (*)(void *)) &AppDef_ResConstraintOfTheGradient::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_ResConstraintOfTheGradient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_ResConstraintOfTheGradient::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_ResConstraintOfTheGradient.def("IsDone", (Standard_Boolean (AppDef_ResConstraintOfTheGradient::*)() const) &AppDef_ResConstraintOfTheGradient::IsDone, "returns True if all has been correctly done.");
// cls_AppDef_ResConstraintOfTheGradient.def("Error", (Standard_Real (AppDef_ResConstraintOfTheGradient::*)() const) &AppDef_ResConstraintOfTheGradient::Error, "returns the maximum difference value between the curve and the given points.");
cls_AppDef_ResConstraintOfTheGradient.def("ConstraintMatrix", (const math_Matrix & (AppDef_ResConstraintOfTheGradient::*)() const) &AppDef_ResConstraintOfTheGradient::ConstraintMatrix, "None");
cls_AppDef_ResConstraintOfTheGradient.def("Duale", (const math_Vector & (AppDef_ResConstraintOfTheGradient::*)() const) &AppDef_ResConstraintOfTheGradient::Duale, "returns the duale variables of the system.");
cls_AppDef_ResConstraintOfTheGradient.def("ConstraintDerivative", (const math_Matrix & (AppDef_ResConstraintOfTheGradient::*)(const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const math_Matrix &)) &AppDef_ResConstraintOfTheGradient::ConstraintDerivative, "Returns the derivative of the constraint matrix.", py::arg("SSP"), py::arg("Parameters"), py::arg("Deg"), py::arg("DA"));
cls_AppDef_ResConstraintOfTheGradient.def("InverseMatrix", (const math_Matrix & (AppDef_ResConstraintOfTheGradient::*)() const) &AppDef_ResConstraintOfTheGradient::InverseMatrix, "returns the Inverse of Cont*Transposed(Cont), where Cont is the constraint matrix for the algorithm.");

// Enums

}