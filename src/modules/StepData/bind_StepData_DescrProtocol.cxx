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
#include <StepData_FileProtocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepData_DescrProtocol.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>

void bind_StepData_DescrProtocol(py::module &mod){

py::class_<StepData_DescrProtocol, opencascade::handle<StepData_DescrProtocol>, StepData_FileProtocol> cls_StepData_DescrProtocol(mod, "StepData_DescrProtocol", "A DescrProtocol is a protocol dynamically (at execution time) defined with : - a list of resources (inherits FileProtocol) - a list of entity descriptions i.e. it can be defined with only C++ writing to initialize it Its initialization must : - set its schema name - define its resources (which can also be other DescrProtocol) - define its entity descriptions - record it in the system by calling RecordLib");

// Constructors
cls_StepData_DescrProtocol.def(py::init<>());

// Fields

// Methods
cls_StepData_DescrProtocol.def("SetSchemaName", (void (StepData_DescrProtocol::*)(const Standard_CString)) &StepData_DescrProtocol::SetSchemaName, "Defines a specific Schema Name for this Protocol", py::arg("name"));
cls_StepData_DescrProtocol.def("LibRecord", (void (StepData_DescrProtocol::*)() const) &StepData_DescrProtocol::LibRecord, "Records this Protocol in the service libraries, with a DescrGeneral and a DescrReadWrite Does nothing if the Protocol brings no proper description");
cls_StepData_DescrProtocol.def("SchemaName", (Standard_CString (StepData_DescrProtocol::*)() const) &StepData_DescrProtocol::SchemaName, "Returns the Schema Name attached to each class of Protocol here, returns the SchemaName set by SetSchemaName was C++ : return const");
cls_StepData_DescrProtocol.def_static("get_type_name_", (const char * (*)()) &StepData_DescrProtocol::get_type_name, "None");
cls_StepData_DescrProtocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_DescrProtocol::get_type_descriptor, "None");
cls_StepData_DescrProtocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_DescrProtocol::*)() const) &StepData_DescrProtocol::DynamicType, "None");

// Enums

}