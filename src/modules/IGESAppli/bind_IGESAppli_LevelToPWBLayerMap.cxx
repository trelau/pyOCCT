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
#include <TColStd_HArray1OfInteger.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESAppli_LevelToPWBLayerMap.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_LevelToPWBLayerMap(py::module &mod){

py::class_<IGESAppli_LevelToPWBLayerMap, opencascade::handle<IGESAppli_LevelToPWBLayerMap>, IGESData_IGESEntity> cls_IGESAppli_LevelToPWBLayerMap(mod, "IGESAppli_LevelToPWBLayerMap", "defines LevelToPWBLayerMap, Type <406> Form <24> in package IGESAppli Used to correlate an exchange file level number with its corresponding native level identifier, physical PWB layer number and predefined functional level identification");

// Constructors
cls_IGESAppli_LevelToPWBLayerMap.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_LevelToPWBLayerMap.def("Init", (void (IGESAppli_LevelToPWBLayerMap::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &IGESAppli_LevelToPWBLayerMap::Init, "This method is used to set the fields of the class LevelToPWBLayerMap - nbPropVal : Number of property values - allExchLevels : Exchange File Level Numbers - allNativeLevels : Native Level Identifications - allPhysLevels : Physical Layer Numbers - allExchIdents : Exchange File Level Identifications raises exception if allExchLevels, allNativeLevels, allPhysLevels and all ExchIdents are not of same dimensions", py::arg("nbPropVal"), py::arg("allExchLevels"), py::arg("allNativeLevels"), py::arg("allPhysLevels"), py::arg("allExchIdents"));
cls_IGESAppli_LevelToPWBLayerMap.def("NbPropertyValues", (Standard_Integer (IGESAppli_LevelToPWBLayerMap::*)() const) &IGESAppli_LevelToPWBLayerMap::NbPropertyValues, "returns number of property values");
cls_IGESAppli_LevelToPWBLayerMap.def("NbLevelToLayerDefs", (Standard_Integer (IGESAppli_LevelToPWBLayerMap::*)() const) &IGESAppli_LevelToPWBLayerMap::NbLevelToLayerDefs, "returns number of level to layer definitions");
cls_IGESAppli_LevelToPWBLayerMap.def("ExchangeFileLevelNumber", (Standard_Integer (IGESAppli_LevelToPWBLayerMap::*)(const Standard_Integer) const) &IGESAppli_LevelToPWBLayerMap::ExchangeFileLevelNumber, "returns Exchange File Level Number raises exception if Index <= 0 or Index > NbLevelToLayerDefs", py::arg("Index"));
cls_IGESAppli_LevelToPWBLayerMap.def("NativeLevel", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_LevelToPWBLayerMap::*)(const Standard_Integer) const) &IGESAppli_LevelToPWBLayerMap::NativeLevel, "returns Native Level Identification raises exception if Index <= 0 or Index > NbLevelToLayerDefs", py::arg("Index"));
cls_IGESAppli_LevelToPWBLayerMap.def("PhysicalLayerNumber", (Standard_Integer (IGESAppli_LevelToPWBLayerMap::*)(const Standard_Integer) const) &IGESAppli_LevelToPWBLayerMap::PhysicalLayerNumber, "returns Physical Layer Number raises exception if Index <= 0 or Index > NbLevelToLayerDefs", py::arg("Index"));
cls_IGESAppli_LevelToPWBLayerMap.def("ExchangeFileLevelIdent", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_LevelToPWBLayerMap::*)(const Standard_Integer) const) &IGESAppli_LevelToPWBLayerMap::ExchangeFileLevelIdent, "None", py::arg("Index"));
cls_IGESAppli_LevelToPWBLayerMap.def_static("get_type_name_", (const char * (*)()) &IGESAppli_LevelToPWBLayerMap::get_type_name, "None");
cls_IGESAppli_LevelToPWBLayerMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_LevelToPWBLayerMap::get_type_descriptor, "None");
cls_IGESAppli_LevelToPWBLayerMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_LevelToPWBLayerMap::*)() const) &IGESAppli_LevelToPWBLayerMap::DynamicType, "None");

// Enums

}