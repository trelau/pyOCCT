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
#include <IFSelect_SelectExtract.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFSelect_SelectAnyType.hxx>

void bind_IFSelect_SelectAnyType(py::module &mod){

py::class_<IFSelect_SelectAnyType, opencascade::handle<IFSelect_SelectAnyType>, IFSelect_SelectExtract> cls_IFSelect_SelectAnyType(mod, "IFSelect_SelectAnyType", "A SelectAnyType sorts the Entities of which the Type is Kind of a given Type : this Type for Match is specific of each class of SelectAnyType");

// Fields

// Methods
cls_IFSelect_SelectAnyType.def("TypeForMatch", (opencascade::handle<Standard_Type> (IFSelect_SelectAnyType::*)() const) &IFSelect_SelectAnyType::TypeForMatch, "Returns the Type which has to be matched for select");
cls_IFSelect_SelectAnyType.def("Sort", (Standard_Boolean (IFSelect_SelectAnyType::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectAnyType::Sort, "Returns True for an Entity (model->Value(num)) which is kind of the choosen type, given by the method TypeForMatch. Criterium is IsKind.", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectAnyType.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectAnyType::get_type_name, "None");
cls_IFSelect_SelectAnyType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectAnyType::get_type_descriptor, "None");
cls_IFSelect_SelectAnyType.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectAnyType::*)() const) &IFSelect_SelectAnyType::DynamicType, "None");

// Enums

}