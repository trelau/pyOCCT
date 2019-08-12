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
#include <GeomAbs_Shape.hxx>
#include <Standard_Handle.hxx>
#include <PLib_JacobiPolynomial.hxx>
#include <AdvApprox_EvaluatorFunction.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <Standard_OStream.hxx>
#include <AdvApprox_SimpleApprox.hxx>

void bind_AdvApprox_SimpleApprox(py::module &mod){

py::class_<AdvApprox_SimpleApprox, std::unique_ptr<AdvApprox_SimpleApprox, Deleter<AdvApprox_SimpleApprox>>> cls_AdvApprox_SimpleApprox(mod, "AdvApprox_SimpleApprox", "Approximate a function on an intervall [First,Last] The result is a simple polynomial whose degree is as low as possible to satisfy the required tolerance and the maximum degree. The maximum error and the averrage error resulting from approximating the function by the polynomial are computed");

// Constructors
cls_AdvApprox_SimpleApprox.def(py::init<const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const opencascade::handle<PLib_JacobiPolynomial> &, const AdvApprox_EvaluatorFunction &>(), py::arg("TotalDimension"), py::arg("TotalNumSS"), py::arg("Continuity"), py::arg("WorkDegree"), py::arg("NbGaussPoints"), py::arg("JacobiBase"), py::arg("Func"));

// Fields

// Methods
// cls_AdvApprox_SimpleApprox.def_static("operator new_", (void * (*)(size_t)) &AdvApprox_SimpleApprox::operator new, "None", py::arg("theSize"));
// cls_AdvApprox_SimpleApprox.def_static("operator delete_", (void (*)(void *)) &AdvApprox_SimpleApprox::operator delete, "None", py::arg("theAddress"));
// cls_AdvApprox_SimpleApprox.def_static("operator new[]_", (void * (*)(size_t)) &AdvApprox_SimpleApprox::operator new[], "None", py::arg("theSize"));
// cls_AdvApprox_SimpleApprox.def_static("operator delete[]_", (void (*)(void *)) &AdvApprox_SimpleApprox::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApprox_SimpleApprox.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApprox_SimpleApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApprox_SimpleApprox.def_static("operator delete_", (void (*)(void *, void *)) &AdvApprox_SimpleApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApprox_SimpleApprox.def("Perform", (void (AdvApprox_SimpleApprox::*)(const TColStd_Array1OfInteger &, const TColStd_Array1OfReal &, const Standard_Real, const Standard_Real, const Standard_Integer)) &AdvApprox_SimpleApprox::Perform, "Constructs approximator tool.", py::arg("LocalDimension"), py::arg("LocalTolerancesArray"), py::arg("First"), py::arg("Last"), py::arg("MaxDegree"));
cls_AdvApprox_SimpleApprox.def("IsDone", (Standard_Boolean (AdvApprox_SimpleApprox::*)() const) &AdvApprox_SimpleApprox::IsDone, "None");
cls_AdvApprox_SimpleApprox.def("Degree", (Standard_Integer (AdvApprox_SimpleApprox::*)() const) &AdvApprox_SimpleApprox::Degree, "None");
cls_AdvApprox_SimpleApprox.def("Coefficients", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_SimpleApprox::*)() const) &AdvApprox_SimpleApprox::Coefficients, "returns the coefficients in the Jacobi Base");
cls_AdvApprox_SimpleApprox.def("FirstConstr", (opencascade::handle<TColStd_HArray2OfReal> (AdvApprox_SimpleApprox::*)() const) &AdvApprox_SimpleApprox::FirstConstr, "returns the constraints at First");
cls_AdvApprox_SimpleApprox.def("LastConstr", (opencascade::handle<TColStd_HArray2OfReal> (AdvApprox_SimpleApprox::*)() const) &AdvApprox_SimpleApprox::LastConstr, "returns the constraints at Last");
cls_AdvApprox_SimpleApprox.def("SomTab", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_SimpleApprox::*)() const) &AdvApprox_SimpleApprox::SomTab, "None");
cls_AdvApprox_SimpleApprox.def("DifTab", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_SimpleApprox::*)() const) &AdvApprox_SimpleApprox::DifTab, "None");
cls_AdvApprox_SimpleApprox.def("MaxError", (Standard_Real (AdvApprox_SimpleApprox::*)(const Standard_Integer) const) &AdvApprox_SimpleApprox::MaxError, "None", py::arg("Index"));
cls_AdvApprox_SimpleApprox.def("AverageError", (Standard_Real (AdvApprox_SimpleApprox::*)(const Standard_Integer) const) &AdvApprox_SimpleApprox::AverageError, "None", py::arg("Index"));
cls_AdvApprox_SimpleApprox.def("Dump", (void (AdvApprox_SimpleApprox::*)(Standard_OStream &) const) &AdvApprox_SimpleApprox::Dump, "display information on approximation", py::arg("o"));

// Enums

}