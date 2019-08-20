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
#include <AppParCurves_MultiCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.hxx>

void bind_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox(py::module &mod){

py::class_<BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox, std::unique_ptr<BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox>> cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox(mod, "BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox", "None");

// Constructors
cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"));
cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &, const Standard_Real>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"), py::arg("Tolerance"));

// Fields

// Methods
// cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def("IsDone", (Standard_Boolean (BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::*)() const) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::IsDone, "returns True if all has been correctly done.");
// cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def("Error", (Standard_Real (BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::*)() const) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::Error, "returns the maximum difference value between the curve and the given points.");
cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def("ConstraintMatrix", (const math_Matrix & (BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::*)() const) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::ConstraintMatrix, "None");
cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def("Duale", (const math_Vector & (BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::*)() const) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::Duale, "returns the duale variables of the system.");
cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def("ConstraintDerivative", (const math_Matrix & (BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::*)(const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const math_Matrix &)) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::ConstraintDerivative, "Returns the derivative of the constraint matrix.", py::arg("SSP"), py::arg("Parameters"), py::arg("Deg"), py::arg("DA"));
cls_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.def("InverseMatrix", (const math_Matrix & (BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::*)() const) &BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox::InverseMatrix, "returns the Inverse of Cont*Transposed(Cont), where Cont is the constraint matrix for the algorithm.");

// Enums

}