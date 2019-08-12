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
#include <IGESSelect_IGESName.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_IGESName(py::module &mod){

py::class_<IGESSelect_IGESName, opencascade::handle<IGESSelect_IGESName>, IFSelect_Signature> cls_IGESSelect_IGESName(mod, "IGESSelect_IGESName", "IGESName is a Signature specific to IGESNorm : it considers the Name of an IGESEntity as being its ShortLabel (some sending systems use name, not to identify entities, but ratjer to classify them)");

// Constructors
cls_IGESSelect_IGESName.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_IGESName.def("Value", (Standard_CString (IGESSelect_IGESName::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_IGESName::Value, "Returns the ShortLabel as being the Name of an IGESEntity If <ent> has no name, it returns empty string ''", py::arg("ent"), py::arg("model"));
cls_IGESSelect_IGESName.def_static("get_type_name_", (const char * (*)()) &IGESSelect_IGESName::get_type_name, "None");
cls_IGESSelect_IGESName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_IGESName::get_type_descriptor, "None");
cls_IGESSelect_IGESName.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_IGESName::*)() const) &IGESSelect_IGESName::DynamicType, "None");

// Enums

}