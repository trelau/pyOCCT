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
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_SignStatus.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SignStatus(py::module &mod){

py::class_<IGESSelect_SignStatus, opencascade::handle<IGESSelect_SignStatus>, IFSelect_Signature> cls_IGESSelect_SignStatus(mod, "IGESSelect_SignStatus", "Gives D.E. Status under the form i,j,k,l (4 figures) i for BlankStatus j for SubordinateStatus k for UseFlag l for Hierarchy");

// Constructors
cls_IGESSelect_SignStatus.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_SignStatus.def("Value", (Standard_CString (IGESSelect_SignStatus::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SignStatus::Value, "Returns the value (see above)", py::arg("ent"), py::arg("model"));
cls_IGESSelect_SignStatus.def("Matches", (Standard_Boolean (IGESSelect_SignStatus::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &, const TCollection_AsciiString &, const Standard_Boolean) const) &IGESSelect_SignStatus::Matches, "Performs the match rule (see above)", py::arg("ent"), py::arg("model"), py::arg("text"), py::arg("exact"));
cls_IGESSelect_SignStatus.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SignStatus::get_type_name, "None");
cls_IGESSelect_SignStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SignStatus::get_type_descriptor, "None");
cls_IGESSelect_SignStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SignStatus::*)() const) &IGESSelect_SignStatus::DynamicType, "None");

// Enums

}