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
#include <Standard_Handle.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESDefs_UnitsData.hxx>
#include <Standard_Type.hxx>

void bind_IGESDefs_UnitsData(py::module &mod){

py::class_<IGESDefs_UnitsData, opencascade::handle<IGESDefs_UnitsData>, IGESData_IGESEntity> cls_IGESDefs_UnitsData(mod, "IGESDefs_UnitsData", "defines IGES UnitsData Entity, Type <316> Form <0> in package IGESDefs This class stores data about a model's fundamental units.");

// Constructors
cls_IGESDefs_UnitsData.def(py::init<>());

// Fields

// Methods
cls_IGESDefs_UnitsData.def("Init", (void (IGESDefs_UnitsData::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<TColStd_HArray1OfReal> &)) &IGESDefs_UnitsData::Init, "This method is used to set the fields of the class UnitsData - unitTypes : Types of the units being defined - unitValues : Unit Values of the units - unitScales : Multiplicative Scale Factors raises exception if lengths of unitTypes, unitValues and unitScale are not same", py::arg("unitTypes"), py::arg("unitValues"), py::arg("unitScales"));
cls_IGESDefs_UnitsData.def("NbUnits", (Standard_Integer (IGESDefs_UnitsData::*)() const) &IGESDefs_UnitsData::NbUnits, "returns the Number of units defined by this entity");
cls_IGESDefs_UnitsData.def("UnitType", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_UnitsData::*)(const Standard_Integer) const) &IGESDefs_UnitsData::UnitType, "returns the Type of the UnitNum'th unit being defined raises exception if UnitNum <= 0 or UnitNum > NbUnits()", py::arg("UnitNum"));
cls_IGESDefs_UnitsData.def("UnitValue", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_UnitsData::*)(const Standard_Integer) const) &IGESDefs_UnitsData::UnitValue, "returns the Units of the UnitNum'th unit being defined raises exception if UnitNum <= 0 or UnitNum > NbUnits()", py::arg("UnitNum"));
cls_IGESDefs_UnitsData.def("ScaleFactor", (Standard_Real (IGESDefs_UnitsData::*)(const Standard_Integer) const) &IGESDefs_UnitsData::ScaleFactor, "returns the multiplicative scale factor to be apllied to the UnitNum'th unit being defined raises exception if UnitNum <= 0 or UnitNum > NbUnits()", py::arg("UnitNum"));
cls_IGESDefs_UnitsData.def_static("get_type_name_", (const char * (*)()) &IGESDefs_UnitsData::get_type_name, "None");
cls_IGESDefs_UnitsData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_UnitsData::get_type_descriptor, "None");
cls_IGESDefs_UnitsData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_UnitsData::*)() const) &IGESDefs_UnitsData::DynamicType, "None");

// Enums

}