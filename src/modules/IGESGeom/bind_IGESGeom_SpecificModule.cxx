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
#include <IGESGeom_SpecificModule.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_SpecificModule(py::module &mod){

py::class_<IGESGeom_SpecificModule, opencascade::handle<IGESGeom_SpecificModule>, IGESData_SpecificModule> cls_IGESGeom_SpecificModule(mod, "IGESGeom_SpecificModule", "Defines Services attached to IGES Entities : Dump & OwnCorrect, for IGESGeom");

// Constructors
cls_IGESGeom_SpecificModule.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_SpecificModule.def("OwnDump", (void (IGESGeom_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESGeom_SpecificModule::OwnDump, "Specific Dump (own parameters) for IGESGeom", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
cls_IGESGeom_SpecificModule.def("OwnCorrect", (Standard_Boolean (IGESGeom_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESGeom_SpecificModule::OwnCorrect, "Performs non-ambiguous Correction on Entities which support them (Boundary,ConicArc,Flash,OffsetCurve,TransformationMatrix)", py::arg("CN"), py::arg("ent"));
cls_IGESGeom_SpecificModule.def_static("get_type_name_", (const char * (*)()) &IGESGeom_SpecificModule::get_type_name, "None");
cls_IGESGeom_SpecificModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_SpecificModule::get_type_descriptor, "None");
cls_IGESGeom_SpecificModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_SpecificModule::*)() const) &IGESGeom_SpecificModule::DynamicType, "None");

// Enums

}