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
#include <Standard_Handle.hxx>
#include <Geom_BSplineSurface.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomLib_DenominatorMultiplier.hxx>

void bind_GeomLib_DenominatorMultiplier(py::module &mod){

py::class_<GeomLib_DenominatorMultiplier, std::unique_ptr<GeomLib_DenominatorMultiplier, Deleter<GeomLib_DenominatorMultiplier>>> cls_GeomLib_DenominatorMultiplier(mod, "GeomLib_DenominatorMultiplier", "this defines an evaluator for a function of 2 variables that will be used by CancelDenominatorDerivative in one direction.");

// Constructors
cls_GeomLib_DenominatorMultiplier.def(py::init<const opencascade::handle<Geom_BSplineSurface> &, const TColStd_Array1OfReal &>(), py::arg("Surface"), py::arg("KnotVector"));

// Fields

// Methods
// cls_GeomLib_DenominatorMultiplier.def_static("operator new_", (void * (*)(size_t)) &GeomLib_DenominatorMultiplier::operator new, "None", py::arg("theSize"));
// cls_GeomLib_DenominatorMultiplier.def_static("operator delete_", (void (*)(void *)) &GeomLib_DenominatorMultiplier::operator delete, "None", py::arg("theAddress"));
// cls_GeomLib_DenominatorMultiplier.def_static("operator new[]_", (void * (*)(size_t)) &GeomLib_DenominatorMultiplier::operator new[], "None", py::arg("theSize"));
// cls_GeomLib_DenominatorMultiplier.def_static("operator delete[]_", (void (*)(void *)) &GeomLib_DenominatorMultiplier::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLib_DenominatorMultiplier.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLib_DenominatorMultiplier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLib_DenominatorMultiplier.def_static("operator delete_", (void (*)(void *, void *)) &GeomLib_DenominatorMultiplier::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLib_DenominatorMultiplier.def("Value", (Standard_Real (GeomLib_DenominatorMultiplier::*)(const Standard_Real, const Standard_Real) const) &GeomLib_DenominatorMultiplier::Value, "Returns the value of a(UParameter,VParameter)=", py::arg("UParameter"), py::arg("VParameter"));

// Enums

}