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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_IntParam.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>

void bind_IFSelect_IntParam(py::module &mod){

py::class_<IFSelect_IntParam, opencascade::handle<IFSelect_IntParam>, Standard_Transient> cls_IFSelect_IntParam(mod, "IFSelect_IntParam", "This class simply allows to access an Integer value through a Handle, as a String can be (by using HString). Hence, this value can be accessed : read and modified, without passing through the specific object which detains it. Thus, parameters of a Selection or a Dispatch (according its type) can be controlled directly from the ShareOut which contains them");

// Constructors
cls_IFSelect_IntParam.def(py::init<>());

// Fields

// Methods
cls_IFSelect_IntParam.def("SetStaticName", (void (IFSelect_IntParam::*)(const Standard_CString)) &IFSelect_IntParam::SetStaticName, "Commands this IntParam to be bound to a Static Hence, Value will return the value if this Static if it is set Else, Value works on the locally stored value SetValue also will set the value of the Static This works only for a present static of type integer or enum Else, it is ignored", py::arg("statname"));
// cls_IFSelect_IntParam.def("StaticName", (Standard_CString (IFSelect_IntParam::*)() const) &IFSelect_IntParam::StaticName, "Returns the name of static parameter to which this IntParam is bound, empty if none");
cls_IFSelect_IntParam.def("Value", (Standard_Integer (IFSelect_IntParam::*)() const) &IFSelect_IntParam::Value, "Reads Integer Value of the IntParam. If a StaticName is defined and the Static is set, looks in priority the value of the static");
cls_IFSelect_IntParam.def("SetValue", (void (IFSelect_IntParam::*)(const Standard_Integer)) &IFSelect_IntParam::SetValue, "Sets a new Integer Value for the IntParam. If a StaticName is defined and the Static is set, also sets the value of the static", py::arg("val"));
cls_IFSelect_IntParam.def_static("get_type_name_", (const char * (*)()) &IFSelect_IntParam::get_type_name, "None");
cls_IFSelect_IntParam.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_IntParam::get_type_descriptor, "None");
cls_IFSelect_IntParam.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_IntParam::*)() const) &IFSelect_IntParam::DynamicType, "None");

// Enums

}