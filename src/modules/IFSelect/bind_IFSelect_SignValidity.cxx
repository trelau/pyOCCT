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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFSelect_SignValidity.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SignValidity(py::module &mod){

py::class_<IFSelect_SignValidity, opencascade::handle<IFSelect_SignValidity>, IFSelect_Signature> cls_IFSelect_SignValidity(mod, "IFSelect_SignValidity", "This Signature returns the Validity Status of an entity, as deducted from data in the model : it can be 'OK' 'Unknown' 'Unloaded' 'Syntactic Fail'(but loaded) 'Syntactic Warning' 'Semantic Fail' 'Semantic Warning'");

// Constructors
cls_IFSelect_SignValidity.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SignValidity.def_static("CVal_", (Standard_CString (*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_SignValidity::CVal, "Returns the Signature for a Transient object, as a validity deducted from data (reports) stored in the model. Class method, can be called by any one", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignValidity.def("Value", (Standard_CString (IFSelect_SignValidity::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SignValidity::Value, "Returns the Signature for a Transient object, as a validity deducted from data (reports) stored in the model Calls the class method CVal", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignValidity.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignValidity::get_type_name, "None");
cls_IFSelect_SignValidity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignValidity::get_type_descriptor, "None");
cls_IFSelect_SignValidity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignValidity::*)() const) &IFSelect_SignValidity::DynamicType, "None");

// Enums

}