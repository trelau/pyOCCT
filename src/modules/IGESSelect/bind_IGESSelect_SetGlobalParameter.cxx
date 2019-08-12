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
#include <IGESSelect_ModelModifier.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IFSelect_ContextModif.hxx>
#include <IGESData_IGESModel.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_SetGlobalParameter.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SetGlobalParameter(py::module &mod){

py::class_<IGESSelect_SetGlobalParameter, opencascade::handle<IGESSelect_SetGlobalParameter>, IGESSelect_ModelModifier> cls_IGESSelect_SetGlobalParameter(mod, "IGESSelect_SetGlobalParameter", "Sets a Global (Header) Parameter to a new value, directly given Controls the form of the parameter (Integer, Real, String with such or such form), but not the consistence of the new value regarding the rest of the file.");

// Constructors
cls_IGESSelect_SetGlobalParameter.def(py::init<const Standard_Integer>(), py::arg("numpar"));

// Fields

// Methods
cls_IGESSelect_SetGlobalParameter.def("GlobalNumber", (Standard_Integer (IGESSelect_SetGlobalParameter::*)() const) &IGESSelect_SetGlobalParameter::GlobalNumber, "Returns the global parameter number to which this modifiers applies");
cls_IGESSelect_SetGlobalParameter.def("SetValue", (void (IGESSelect_SetGlobalParameter::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESSelect_SetGlobalParameter::SetValue, "Sets a Text Parameter for the new value", py::arg("text"));
cls_IGESSelect_SetGlobalParameter.def("Value", (opencascade::handle<TCollection_HAsciiString> (IGESSelect_SetGlobalParameter::*)() const) &IGESSelect_SetGlobalParameter::Value, "Returns the value to set to the global parameter (Text Param)");
cls_IGESSelect_SetGlobalParameter.def("Performing", (void (IGESSelect_SetGlobalParameter::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_SetGlobalParameter::Performing, "Specific action : only <target> is used : the form of the new value is checked regarding the parameter number (given at creation time).", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_SetGlobalParameter.def("Label", (TCollection_AsciiString (IGESSelect_SetGlobalParameter::*)() const) &IGESSelect_SetGlobalParameter::Label, "Returns a text which is 'Sets Global Parameter <numpar> to <new value>'");
cls_IGESSelect_SetGlobalParameter.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SetGlobalParameter::get_type_name, "None");
cls_IGESSelect_SetGlobalParameter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SetGlobalParameter::get_type_descriptor, "None");
cls_IGESSelect_SetGlobalParameter.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SetGlobalParameter::*)() const) &IGESSelect_SetGlobalParameter::DynamicType, "None");

// Enums

}