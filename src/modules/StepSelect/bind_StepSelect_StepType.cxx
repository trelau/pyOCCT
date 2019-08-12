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
#include <IFSelect_Signature.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <StepSelect_StepType.hxx>
#include <Standard_Type.hxx>
#include <StepData_WriterLib.hxx>
#include <StepData_Protocol.hxx>

void bind_StepSelect_StepType(py::module &mod){

py::class_<StepSelect_StepType, opencascade::handle<StepSelect_StepType>, IFSelect_Signature> cls_StepSelect_StepType(mod, "StepSelect_StepType", "StepType is a Signature specific to Step definitions : it considers the type as defined in STEP Schemas, the same which is used in files. For a Complex Type, if its definition is known, StepType produces the list of basic types, separated by commas, the whole between brackets : '(TYPE1,TYPE2..)'. If its precise definition is not known (simply it is known as Complex, it can be recognised, but the list is produced at Write time only), StepType produces : '(..COMPLEX TYPE..)'");

// Constructors
cls_StepSelect_StepType.def(py::init<>());

// Fields

// Methods
cls_StepSelect_StepType.def("SetProtocol", (void (StepSelect_StepType::*)(const opencascade::handle<Interface_Protocol> &)) &StepSelect_StepType::SetProtocol, "Sets the StepType signature to work with a Protocol : this initialises the library", py::arg("proto"));
cls_StepSelect_StepType.def("Value", (Standard_CString (StepSelect_StepType::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &StepSelect_StepType::Value, "Returns the Step Type defined from the Protocol (see above). If <ent> is not recognised, produces '..NOT FROM SCHEMA <name>..'", py::arg("ent"), py::arg("model"));
cls_StepSelect_StepType.def_static("get_type_name_", (const char * (*)()) &StepSelect_StepType::get_type_name, "None");
cls_StepSelect_StepType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_StepType::get_type_descriptor, "None");
cls_StepSelect_StepType.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_StepType::*)() const) &StepSelect_StepType::DynamicType, "None");

// Enums

}