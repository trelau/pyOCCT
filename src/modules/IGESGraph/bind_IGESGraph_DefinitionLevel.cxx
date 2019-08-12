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
#include <IGESData_LevelListEntity.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESGraph_DefinitionLevel.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_DefinitionLevel(py::module &mod){

py::class_<IGESGraph_DefinitionLevel, opencascade::handle<IGESGraph_DefinitionLevel>, IGESData_LevelListEntity> cls_IGESGraph_DefinitionLevel(mod, "IGESGraph_DefinitionLevel", "defines IGESDefinitionLevel, Type <406> Form <1> in package IGESGraph");

// Constructors
cls_IGESGraph_DefinitionLevel.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_DefinitionLevel.def("Init", (void (IGESGraph_DefinitionLevel::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESGraph_DefinitionLevel::Init, "This method is used to set the fields of the class DefinitionLevel - allLevelNumbers : Values of Level Numbers", py::arg("allLevelNumbers"));
cls_IGESGraph_DefinitionLevel.def("NbPropertyValues", (Standard_Integer (IGESGraph_DefinitionLevel::*)() const) &IGESGraph_DefinitionLevel::NbPropertyValues, "returns the number of property values in <me>");
cls_IGESGraph_DefinitionLevel.def("NbLevelNumbers", (Standard_Integer (IGESGraph_DefinitionLevel::*)() const) &IGESGraph_DefinitionLevel::NbLevelNumbers, "Must return the count of levels (== NbPropertyValues)");
cls_IGESGraph_DefinitionLevel.def("LevelNumber", (Standard_Integer (IGESGraph_DefinitionLevel::*)(const Standard_Integer) const) &IGESGraph_DefinitionLevel::LevelNumber, "returns the Level Number of <me> indicated by <LevelIndex> raises an exception if LevelIndex is <= 0 or LevelIndex > NbPropertyValues", py::arg("LevelIndex"));
cls_IGESGraph_DefinitionLevel.def_static("get_type_name_", (const char * (*)()) &IGESGraph_DefinitionLevel::get_type_name, "None");
cls_IGESGraph_DefinitionLevel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_DefinitionLevel::get_type_descriptor, "None");
cls_IGESGraph_DefinitionLevel.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_DefinitionLevel::*)() const) &IGESGraph_DefinitionLevel::DynamicType, "None");

// Enums

}