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
#include <IGESSelect_SignLevelNumber.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SignLevelNumber(py::module &mod){

py::class_<IGESSelect_SignLevelNumber, opencascade::handle<IGESSelect_SignLevelNumber>, IFSelect_Signature> cls_IGESSelect_SignLevelNumber(mod, "IGESSelect_SignLevelNumber", "Gives D.E. Level Number under two possible forms : * for counter : 'LEVEL nnnnnnn', ' NO LEVEL', ' LEVEL LIST' * for selection : '/nnn/', '/0/', '/1/2/nnn/'");

// Constructors
cls_IGESSelect_SignLevelNumber.def(py::init<const Standard_Boolean>(), py::arg("countmode"));

// Fields

// Methods
cls_IGESSelect_SignLevelNumber.def("Value", (Standard_CString (IGESSelect_SignLevelNumber::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SignLevelNumber::Value, "Returns the value (see above)", py::arg("ent"), py::arg("model"));
cls_IGESSelect_SignLevelNumber.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SignLevelNumber::get_type_name, "None");
cls_IGESSelect_SignLevelNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SignLevelNumber::get_type_descriptor, "None");
cls_IGESSelect_SignLevelNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SignLevelNumber::*)() const) &IGESSelect_SignLevelNumber::DynamicType, "None");

// Enums

}