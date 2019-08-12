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
#include <AdvApprox_Cutting.hxx>
#include <Standard.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <AdvApprox_PrefAndRec.hxx>

void bind_AdvApprox_PrefAndRec(py::module &mod){

py::class_<AdvApprox_PrefAndRec, std::unique_ptr<AdvApprox_PrefAndRec, Deleter<AdvApprox_PrefAndRec>>, AdvApprox_Cutting> cls_AdvApprox_PrefAndRec(mod, "AdvApprox_PrefAndRec", "inherits class Cutting; contains a list of preferential points (pi)i and a list of Recommended points used in cutting management. if Cutting is necessary in [a,b], we cut at the di nearest from (a+b)/2");

// Constructors
cls_AdvApprox_PrefAndRec.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("RecomendedCut"), py::arg("PrefferedCut"));
cls_AdvApprox_PrefAndRec.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const Standard_Real>(), py::arg("RecomendedCut"), py::arg("PrefferedCut"), py::arg("Weight"));

// Fields

// Methods
// cls_AdvApprox_PrefAndRec.def_static("operator new_", (void * (*)(size_t)) &AdvApprox_PrefAndRec::operator new, "None", py::arg("theSize"));
// cls_AdvApprox_PrefAndRec.def_static("operator delete_", (void (*)(void *)) &AdvApprox_PrefAndRec::operator delete, "None", py::arg("theAddress"));
// cls_AdvApprox_PrefAndRec.def_static("operator new[]_", (void * (*)(size_t)) &AdvApprox_PrefAndRec::operator new[], "None", py::arg("theSize"));
// cls_AdvApprox_PrefAndRec.def_static("operator delete[]_", (void (*)(void *)) &AdvApprox_PrefAndRec::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApprox_PrefAndRec.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApprox_PrefAndRec::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApprox_PrefAndRec.def_static("operator delete_", (void (*)(void *, void *)) &AdvApprox_PrefAndRec::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApprox_PrefAndRec.def("Value", [](AdvApprox_PrefAndRec &self, const Standard_Real a, const Standard_Real b, Standard_Real & cuttingvalue){ Standard_Boolean rv = self.Value(a, b, cuttingvalue); return std::tuple<Standard_Boolean, Standard_Real &>(rv, cuttingvalue); }, "cuting value is - the recommended point nerest of (a+b)/2 if pi is in ]a,b[ or else - the preferential point nearest of (a+b) / 2 if pi is in ](r*a+b)/(r+1) , (a+r*b)/(r+1)[ where r = Weight - or (a+b)/2 else.", py::arg("a"), py::arg("b"), py::arg("cuttingvalue"));

// Enums

}