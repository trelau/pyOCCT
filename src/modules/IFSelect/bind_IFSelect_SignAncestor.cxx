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
#include <IFSelect_SignType.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SignAncestor.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SignAncestor(py::module &mod){

py::class_<IFSelect_SignAncestor, opencascade::handle<IFSelect_SignAncestor>, IFSelect_SignType> cls_IFSelect_SignAncestor(mod, "IFSelect_SignAncestor", "None");

// Constructors
cls_IFSelect_SignAncestor.def(py::init<>());
cls_IFSelect_SignAncestor.def(py::init<const Standard_Boolean>(), py::arg("nopk"));

// Fields

// Methods
cls_IFSelect_SignAncestor.def("Matches", (Standard_Boolean (IFSelect_SignAncestor::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &, const TCollection_AsciiString &, const Standard_Boolean) const) &IFSelect_SignAncestor::Matches, "None", py::arg("ent"), py::arg("model"), py::arg("text"), py::arg("exact"));
cls_IFSelect_SignAncestor.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignAncestor::get_type_name, "None");
cls_IFSelect_SignAncestor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignAncestor::get_type_descriptor, "None");
cls_IFSelect_SignAncestor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignAncestor::*)() const) &IFSelect_SignAncestor::DynamicType, "None");

// Enums

}