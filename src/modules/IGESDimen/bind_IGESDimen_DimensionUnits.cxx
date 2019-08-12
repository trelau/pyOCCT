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
#include <TCollection_HAsciiString.hxx>
#include <IGESDimen_DimensionUnits.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_DimensionUnits(py::module &mod){

py::class_<IGESDimen_DimensionUnits, opencascade::handle<IGESDimen_DimensionUnits>, IGESData_IGESEntity> cls_IGESDimen_DimensionUnits(mod, "IGESDimen_DimensionUnits", "defines Dimension Units, Type <406>, Form <28> in package IGESDimen Describes the units and formatting details of the nominal value of a dimension.");

// Constructors
cls_IGESDimen_DimensionUnits.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_DimensionUnits.def("Init", (void (IGESDimen_DimensionUnits::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer)) &IGESDimen_DimensionUnits::Init, "This method is used to set the fields of the class DimensionUnits - nbPropVal : Number of property values, always = 6 - aSecondPos : Secondary Dimension Position 0 = This is the main text 1 = Before primary dimension 2 = After primary dimension 3 = Above primary dimension 4 = Below primary dimension - aUnitsInd : Units Indicator - aCharSet : Character Set used - aFormat : Format HAsciiString 1 = Standard ASCII 1001 = Symbol Font 1 1002 = Symbol Font 2 1003 = Drafting Font - aFracFlag : Fraction Flag 0 = Display values as decimal numbers 1 = Display values as fractions - aPrecision : Precision Value", py::arg("nbPropVal"), py::arg("aSecondPos"), py::arg("aUnitsInd"), py::arg("aCharSet"), py::arg("aFormat"), py::arg("aFracFlag"), py::arg("aPrecision"));
cls_IGESDimen_DimensionUnits.def("NbPropertyValues", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::NbPropertyValues, "returns the number of property values");
cls_IGESDimen_DimensionUnits.def("SecondaryDimenPosition", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::SecondaryDimenPosition, "returns position of secondary dimension w.r.t. primary dimension");
cls_IGESDimen_DimensionUnits.def("UnitsIndicator", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::UnitsIndicator, "returns the units indicator");
cls_IGESDimen_DimensionUnits.def("CharacterSet", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::CharacterSet, "returns the character set interpretation");
cls_IGESDimen_DimensionUnits.def("FormatString", (opencascade::handle<TCollection_HAsciiString> (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::FormatString, "returns the string used in formatting value");
cls_IGESDimen_DimensionUnits.def("FractionFlag", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::FractionFlag, "returns the fraction flag");
cls_IGESDimen_DimensionUnits.def("PrecisionOrDenominator", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::PrecisionOrDenominator, "returns the precision/denominator number of decimal places when FractionFlag() = 0 denominator of fraction when FractionFlag() = 1");
cls_IGESDimen_DimensionUnits.def_static("get_type_name_", (const char * (*)()) &IGESDimen_DimensionUnits::get_type_name, "None");
cls_IGESDimen_DimensionUnits.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_DimensionUnits::get_type_descriptor, "None");
cls_IGESDimen_DimensionUnits.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::DynamicType, "None");

// Enums

}