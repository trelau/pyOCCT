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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESDimen_DimensionTolerance.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_DimensionTolerance(py::module &mod){

py::class_<IGESDimen_DimensionTolerance, opencascade::handle<IGESDimen_DimensionTolerance>, IGESData_IGESEntity> cls_IGESDimen_DimensionTolerance(mod, "IGESDimen_DimensionTolerance", "defines Dimension Tolerance, Type <406>, Form <29> in package IGESDimen Provides tolerance information for a dimension which can be used by the receiving system to regenerate the dimension.");

// Constructors
cls_IGESDimen_DimensionTolerance.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_DimensionTolerance.def("Init", (void (IGESDimen_DimensionTolerance::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Integer)) &IGESDimen_DimensionTolerance::Init, "This method is used to set the fields of the class DimensionTolerance - nbPropVal : Number of property values, default = 8 - aSecTolFlag : Secondary Tolerance Flag 0 = Applies to primary dimension 1 = Applies to secondary dimension 2 = Display values as fractions - aTolType : Tolerance Type 1 = Bilateral 2 = Upper/Lower 3 = Unilateral Upper 4 = Unilateral Lower 5 = Range - min before max 6 = Range - min after max 7 = Range - min above max 8 = Range - min below max 9 = Nominal + Range - min above max 10 = Nominal + Range - min below max - aTolPlaceFlag : Tolerance Placement Flag 1 = Before nominal value 2 = After nominal value 3 = Above nominal value 4 = Below nominal value - anUpperTol : Upper Tolerance - aLowerTol : Lower Tolerance - aSignFlag : Sign Suppression Flag - aFracFlag : Fraction Flag 0 = Display values as decimal numbers 1 = Display values as mixed fractions 2 = Display values as fractions - aPrecision : Precision Value", py::arg("nbPropVal"), py::arg("aSecTolFlag"), py::arg("aTolType"), py::arg("aTolPlaceFlag"), py::arg("anUpperTol"), py::arg("aLowerTol"), py::arg("aSignFlag"), py::arg("aFracFlag"), py::arg("aPrecision"));
cls_IGESDimen_DimensionTolerance.def("NbPropertyValues", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::NbPropertyValues, "returns the number of property values, always = 8");
cls_IGESDimen_DimensionTolerance.def("SecondaryToleranceFlag", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::SecondaryToleranceFlag, "returns the Secondary Tolerance Flag");
cls_IGESDimen_DimensionTolerance.def("ToleranceType", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::ToleranceType, "returns the Tolerance Type");
cls_IGESDimen_DimensionTolerance.def("TolerancePlacementFlag", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::TolerancePlacementFlag, "returns the Tolerance Placement Flag, default = 2");
cls_IGESDimen_DimensionTolerance.def("UpperTolerance", (Standard_Real (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::UpperTolerance, "returns the Upper or Bilateral Tolerance Value");
cls_IGESDimen_DimensionTolerance.def("LowerTolerance", (Standard_Real (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::LowerTolerance, "returns the Lower Tolerance Value");
cls_IGESDimen_DimensionTolerance.def("SignSuppressionFlag", (Standard_Boolean (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::SignSuppressionFlag, "returns the Sign Suppression Flag");
cls_IGESDimen_DimensionTolerance.def("FractionFlag", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::FractionFlag, "returns the Fraction Flag");
cls_IGESDimen_DimensionTolerance.def("Precision", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::Precision, "returns the Precision for Value Display");
cls_IGESDimen_DimensionTolerance.def_static("get_type_name_", (const char * (*)()) &IGESDimen_DimensionTolerance::get_type_name, "None");
cls_IGESDimen_DimensionTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_DimensionTolerance::get_type_descriptor, "None");
cls_IGESDimen_DimensionTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::DynamicType, "None");

// Enums

}