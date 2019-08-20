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
#include <FairCurve_Energy.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <FairCurve_BattenLaw.hxx>
#include <FairCurve_AnalysisCode.hxx>
#include <math_Vector.hxx>
#include <FairCurve_DistributionOfTension.hxx>
#include <FairCurve_DistributionOfSagging.hxx>
#include <FairCurve_EnergyOfBatten.hxx>

void bind_FairCurve_EnergyOfBatten(py::module &mod){

py::class_<FairCurve_EnergyOfBatten, std::unique_ptr<FairCurve_EnergyOfBatten>, FairCurve_Energy> cls_FairCurve_EnergyOfBatten(mod, "FairCurve_EnergyOfBatten", "Energy Criterium to minimize in Batten.");

// Constructors
cls_FairCurve_EnergyOfBatten.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("LengthSliding"));
cls_FairCurve_EnergyOfBatten.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Boolean>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("LengthSliding"), py::arg("FreeSliding"));
cls_FairCurve_EnergyOfBatten.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("LengthSliding"), py::arg("FreeSliding"), py::arg("Angle1"));
cls_FairCurve_EnergyOfBatten.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Real>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("LengthSliding"), py::arg("FreeSliding"), py::arg("Angle1"), py::arg("Angle2"));

// Fields

// Methods
// cls_FairCurve_EnergyOfBatten.def_static("operator new_", (void * (*)(size_t)) &FairCurve_EnergyOfBatten::operator new, "None", py::arg("theSize"));
// cls_FairCurve_EnergyOfBatten.def_static("operator delete_", (void (*)(void *)) &FairCurve_EnergyOfBatten::operator delete, "None", py::arg("theAddress"));
// cls_FairCurve_EnergyOfBatten.def_static("operator new[]_", (void * (*)(size_t)) &FairCurve_EnergyOfBatten::operator new[], "None", py::arg("theSize"));
// cls_FairCurve_EnergyOfBatten.def_static("operator delete[]_", (void (*)(void *)) &FairCurve_EnergyOfBatten::operator delete[], "None", py::arg("theAddress"));
// cls_FairCurve_EnergyOfBatten.def_static("operator new_", (void * (*)(size_t, void *)) &FairCurve_EnergyOfBatten::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FairCurve_EnergyOfBatten.def_static("operator delete_", (void (*)(void *, void *)) &FairCurve_EnergyOfBatten::operator delete, "None", py::arg(""), py::arg(""));
cls_FairCurve_EnergyOfBatten.def("LengthSliding", (Standard_Real (FairCurve_EnergyOfBatten::*)() const) &FairCurve_EnergyOfBatten::LengthSliding, "return the lengthSliding = P1P2 + Sliding");
cls_FairCurve_EnergyOfBatten.def("Status", (FairCurve_AnalysisCode (FairCurve_EnergyOfBatten::*)() const) &FairCurve_EnergyOfBatten::Status, "return the status");
cls_FairCurve_EnergyOfBatten.def("Variable", (Standard_Boolean (FairCurve_EnergyOfBatten::*)(math_Vector &) const) &FairCurve_EnergyOfBatten::Variable, "compute the variables <X> wich correspond with the field <MyPoles>", py::arg("X"));

// Enums

}