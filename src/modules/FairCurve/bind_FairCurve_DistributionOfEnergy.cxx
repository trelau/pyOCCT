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
#include <math_FunctionSet.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <FairCurve_DistributionOfEnergy.hxx>

void bind_FairCurve_DistributionOfEnergy(py::module &mod){

py::class_<FairCurve_DistributionOfEnergy, std::unique_ptr<FairCurve_DistributionOfEnergy, Deleter<FairCurve_DistributionOfEnergy>>, math_FunctionSet> cls_FairCurve_DistributionOfEnergy(mod, "FairCurve_DistributionOfEnergy", "Abstract class to use the Energy of an FairCurve");

// Fields

// Methods
// cls_FairCurve_DistributionOfEnergy.def_static("operator new_", (void * (*)(size_t)) &FairCurve_DistributionOfEnergy::operator new, "None", py::arg("theSize"));
// cls_FairCurve_DistributionOfEnergy.def_static("operator delete_", (void (*)(void *)) &FairCurve_DistributionOfEnergy::operator delete, "None", py::arg("theAddress"));
// cls_FairCurve_DistributionOfEnergy.def_static("operator new[]_", (void * (*)(size_t)) &FairCurve_DistributionOfEnergy::operator new[], "None", py::arg("theSize"));
// cls_FairCurve_DistributionOfEnergy.def_static("operator delete[]_", (void (*)(void *)) &FairCurve_DistributionOfEnergy::operator delete[], "None", py::arg("theAddress"));
// cls_FairCurve_DistributionOfEnergy.def_static("operator new_", (void * (*)(size_t, void *)) &FairCurve_DistributionOfEnergy::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FairCurve_DistributionOfEnergy.def_static("operator delete_", (void (*)(void *, void *)) &FairCurve_DistributionOfEnergy::operator delete, "None", py::arg(""), py::arg(""));
cls_FairCurve_DistributionOfEnergy.def("NbVariables", (Standard_Integer (FairCurve_DistributionOfEnergy::*)() const) &FairCurve_DistributionOfEnergy::NbVariables, "returns the number of variables of the function.");
cls_FairCurve_DistributionOfEnergy.def("NbEquations", (Standard_Integer (FairCurve_DistributionOfEnergy::*)() const) &FairCurve_DistributionOfEnergy::NbEquations, "returns the number of equations of the function.");
cls_FairCurve_DistributionOfEnergy.def("SetDerivativeOrder", (void (FairCurve_DistributionOfEnergy::*)(const Standard_Integer)) &FairCurve_DistributionOfEnergy::SetDerivativeOrder, "None", py::arg("DerivativeOrder"));

// Enums

}