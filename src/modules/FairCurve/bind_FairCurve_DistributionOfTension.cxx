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
#include <FairCurve_DistributionOfEnergy.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <FairCurve_BattenLaw.hxx>
#include <math_Vector.hxx>
#include <FairCurve_DistributionOfTension.hxx>

void bind_FairCurve_DistributionOfTension(py::module &mod){

py::class_<FairCurve_DistributionOfTension, std::unique_ptr<FairCurve_DistributionOfTension>, FairCurve_DistributionOfEnergy> cls_FairCurve_DistributionOfTension(mod, "FairCurve_DistributionOfTension", "Compute the Tension Distribution");

// Constructors
cls_FairCurve_DistributionOfTension.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Real, const FairCurve_BattenLaw &>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("DerivativeOrder"), py::arg("LengthSliding"), py::arg("Law"));
cls_FairCurve_DistributionOfTension.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Real, const FairCurve_BattenLaw &, const Standard_Integer>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("DerivativeOrder"), py::arg("LengthSliding"), py::arg("Law"), py::arg("NbValAux"));
cls_FairCurve_DistributionOfTension.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Real, const FairCurve_BattenLaw &, const Standard_Integer, const Standard_Boolean>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("DerivativeOrder"), py::arg("LengthSliding"), py::arg("Law"), py::arg("NbValAux"), py::arg("Uniform"));

// Fields

// Methods
// cls_FairCurve_DistributionOfTension.def_static("operator new_", (void * (*)(size_t)) &FairCurve_DistributionOfTension::operator new, "None", py::arg("theSize"));
// cls_FairCurve_DistributionOfTension.def_static("operator delete_", (void (*)(void *)) &FairCurve_DistributionOfTension::operator delete, "None", py::arg("theAddress"));
// cls_FairCurve_DistributionOfTension.def_static("operator new[]_", (void * (*)(size_t)) &FairCurve_DistributionOfTension::operator new[], "None", py::arg("theSize"));
// cls_FairCurve_DistributionOfTension.def_static("operator delete[]_", (void (*)(void *)) &FairCurve_DistributionOfTension::operator delete[], "None", py::arg("theAddress"));
// cls_FairCurve_DistributionOfTension.def_static("operator new_", (void * (*)(size_t, void *)) &FairCurve_DistributionOfTension::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FairCurve_DistributionOfTension.def_static("operator delete_", (void (*)(void *, void *)) &FairCurve_DistributionOfTension::operator delete, "None", py::arg(""), py::arg(""));
cls_FairCurve_DistributionOfTension.def("SetLengthSliding", (void (FairCurve_DistributionOfTension::*)(const Standard_Real)) &FairCurve_DistributionOfTension::SetLengthSliding, "change the length sliding", py::arg("LengthSliding"));
cls_FairCurve_DistributionOfTension.def("Value", (Standard_Boolean (FairCurve_DistributionOfTension::*)(const math_Vector &, math_Vector &)) &FairCurve_DistributionOfTension::Value, "computes the values <F> of the functions for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));

// Enums

}