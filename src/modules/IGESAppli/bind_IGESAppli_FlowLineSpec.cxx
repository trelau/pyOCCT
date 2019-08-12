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
#include <Standard_TypeDef.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESAppli_FlowLineSpec.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_FlowLineSpec(py::module &mod){

py::class_<IGESAppli_FlowLineSpec, opencascade::handle<IGESAppli_FlowLineSpec>, IGESData_IGESEntity> cls_IGESAppli_FlowLineSpec(mod, "IGESAppli_FlowLineSpec", "defines FlowLineSpec, Type <406> Form <14> in package IGESAppli Attaches one or more text strings to entities being used to represent a flow line");

// Constructors
cls_IGESAppli_FlowLineSpec.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_FlowLineSpec.def("Init", (void (IGESAppli_FlowLineSpec::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &IGESAppli_FlowLineSpec::Init, "This method is used to set the fields of the class FlowLineSpec - allProperties : primary flow line specification and modifiers", py::arg("allProperties"));
cls_IGESAppli_FlowLineSpec.def("NbPropertyValues", (Standard_Integer (IGESAppli_FlowLineSpec::*)() const) &IGESAppli_FlowLineSpec::NbPropertyValues, "returns the number of property values");
cls_IGESAppli_FlowLineSpec.def("FlowLineName", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_FlowLineSpec::*)() const) &IGESAppli_FlowLineSpec::FlowLineName, "returns primary flow line specification name");
cls_IGESAppli_FlowLineSpec.def("Modifier", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_FlowLineSpec::*)(const Standard_Integer) const) &IGESAppli_FlowLineSpec::Modifier, "returns specified modifier element raises exception if Index <= 1 or Index > NbPropertyValues", py::arg("Index"));
cls_IGESAppli_FlowLineSpec.def_static("get_type_name_", (const char * (*)()) &IGESAppli_FlowLineSpec::get_type_name, "None");
cls_IGESAppli_FlowLineSpec.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_FlowLineSpec::get_type_descriptor, "None");
cls_IGESAppli_FlowLineSpec.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_FlowLineSpec::*)() const) &IGESAppli_FlowLineSpec::DynamicType, "None");

// Enums

}