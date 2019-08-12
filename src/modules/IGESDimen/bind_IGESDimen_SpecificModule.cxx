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
#include <IGESData_SpecificModule.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <IGESDimen_SpecificModule.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_SpecificModule(py::module &mod){

py::class_<IGESDimen_SpecificModule, opencascade::handle<IGESDimen_SpecificModule>, IGESData_SpecificModule> cls_IGESDimen_SpecificModule(mod, "IGESDimen_SpecificModule", "Defines Services attached to IGES Entities : Dump & OwnCorrect, for IGESDimen");

// Constructors
cls_IGESDimen_SpecificModule.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_SpecificModule.def("OwnDump", (void (IGESDimen_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_SpecificModule::OwnDump, "Specific Dump (own parameters) for IGESDimen", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
cls_IGESDimen_SpecificModule.def("OwnCorrect", (Standard_Boolean (IGESDimen_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESDimen_SpecificModule::OwnCorrect, "Performs non-ambiguous Corrections on Entities which support them (BasicDimension,CenterLine,DimensionDisplayData, DimensionTolerance,DimensionUnits,DimensionedGeometry, NewDimensionedGeometry,Section,WitnessLine)", py::arg("CN"), py::arg("ent"));
cls_IGESDimen_SpecificModule.def_static("get_type_name_", (const char * (*)()) &IGESDimen_SpecificModule::get_type_name, "None");
cls_IGESDimen_SpecificModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_SpecificModule::get_type_descriptor, "None");
cls_IGESDimen_SpecificModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_SpecificModule::*)() const) &IGESDimen_SpecificModule::DynamicType, "None");

// Enums

}