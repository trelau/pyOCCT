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
#include <IFSelect_SelectAnyType.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectType.hxx>

void bind_IFSelect_SelectType(py::module &mod){

py::class_<IFSelect_SelectType, opencascade::handle<IFSelect_SelectType>, IFSelect_SelectAnyType> cls_IFSelect_SelectType(mod, "IFSelect_SelectType", "A SelectType keeps or rejects Entities of which the Type is Kind of a given Cdl Type");

// Constructors
cls_IFSelect_SelectType.def(py::init<>());
cls_IFSelect_SelectType.def(py::init<const opencascade::handle<Standard_Type> &>(), py::arg("atype"));

// Fields

// Methods
cls_IFSelect_SelectType.def("SetType", (void (IFSelect_SelectType::*)(const opencascade::handle<Standard_Type> &)) &IFSelect_SelectType::SetType, "Sets a TYpe for filter", py::arg("atype"));
cls_IFSelect_SelectType.def("TypeForMatch", (opencascade::handle<Standard_Type> (IFSelect_SelectType::*)() const) &IFSelect_SelectType::TypeForMatch, "Returns the Type to be matched for select : this is the type given at instantiation time");
cls_IFSelect_SelectType.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectType::*)() const) &IFSelect_SelectType::ExtractLabel, "Returns a text defining the criterium. (should by gotten from Type of Entity used for instantiation)");
cls_IFSelect_SelectType.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectType::get_type_name, "None");
cls_IFSelect_SelectType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectType::get_type_descriptor, "None");
cls_IFSelect_SelectType.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectType::*)() const) &IFSelect_SelectType::DynamicType, "None");

// Enums

}