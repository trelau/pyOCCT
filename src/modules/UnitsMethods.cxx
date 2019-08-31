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
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <UnitsMethods.hxx>

PYBIND11_MODULE(UnitsMethods, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom");

// CLASS: UNITSMETHODS
py::class_<UnitsMethods> cls_UnitsMethods(mod, "UnitsMethods", "None");

// Methods
// cls_UnitsMethods.def_static("operator new_", (void * (*)(size_t)) &UnitsMethods::operator new, "None", py::arg("theSize"));
// cls_UnitsMethods.def_static("operator delete_", (void (*)(void *)) &UnitsMethods::operator delete, "None", py::arg("theAddress"));
// cls_UnitsMethods.def_static("operator new[]_", (void * (*)(size_t)) &UnitsMethods::operator new[], "None", py::arg("theSize"));
// cls_UnitsMethods.def_static("operator delete[]_", (void (*)(void *)) &UnitsMethods::operator delete[], "None", py::arg("theAddress"));
// cls_UnitsMethods.def_static("operator new_", (void * (*)(size_t, void *)) &UnitsMethods::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_UnitsMethods.def_static("operator delete_", (void (*)(void *, void *)) &UnitsMethods::operator delete, "None", py::arg(""), py::arg(""));
cls_UnitsMethods.def_static("InitializeFactors_", (void (*)(const Standard_Real, const Standard_Real, const Standard_Real)) &UnitsMethods::InitializeFactors, "Initializes the 3 factors for the conversion of units", py::arg("LengthFactor"), py::arg("PlaneAngleFactor"), py::arg("SolidAngleFactor"));
cls_UnitsMethods.def_static("LengthFactor_", (Standard_Real (*)()) &UnitsMethods::LengthFactor, "None");
cls_UnitsMethods.def_static("PlaneAngleFactor_", (Standard_Real (*)()) &UnitsMethods::PlaneAngleFactor, "None");
cls_UnitsMethods.def_static("SolidAngleFactor_", (Standard_Real (*)()) &UnitsMethods::SolidAngleFactor, "None");
cls_UnitsMethods.def_static("Set3dConversion_", (void (*)(const Standard_Boolean)) &UnitsMethods::Set3dConversion, "None", py::arg("B"));
cls_UnitsMethods.def_static("Convert3d_", (Standard_Boolean (*)()) &UnitsMethods::Convert3d, "None");
cls_UnitsMethods.def_static("RadianToDegree_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &)) &UnitsMethods::RadianToDegree, "None", py::arg("C"), py::arg("S"));
cls_UnitsMethods.def_static("DegreeToRadian_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &)) &UnitsMethods::DegreeToRadian, "None", py::arg("C"), py::arg("S"));
cls_UnitsMethods.def_static("MirrorPCurve_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom2d_Curve> &)) &UnitsMethods::MirrorPCurve, "None", py::arg("C"));
cls_UnitsMethods.def_static("GetLengthFactorValue_", (Standard_Real (*)(const Standard_Integer)) &UnitsMethods::GetLengthFactorValue, "Returns value of unit encoded by parameter param (integer value denoting unit, as described in IGES standard) in millimeters", py::arg("param"));
cls_UnitsMethods.def_static("GetCasCadeLengthUnit_", (Standard_Real (*)()) &UnitsMethods::GetCasCadeLengthUnit, "Returns value of current internal unit for CASCADE in millemeters");
cls_UnitsMethods.def_static("SetCasCadeLengthUnit_", (void (*)(const Standard_Integer)) &UnitsMethods::SetCasCadeLengthUnit, "Sets value of current internal unit for CASCADE by parameter param (integer value denoting unit, as described in IGES standard) GetCasCadeLengthUnit() will then return value equal to GetLengthFactorValue(param)", py::arg("param"));


}
