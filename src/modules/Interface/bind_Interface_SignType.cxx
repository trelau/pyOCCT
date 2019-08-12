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
#include <MoniTool_SignText.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_SignType.hxx>
#include <Standard_Type.hxx>

void bind_Interface_SignType(py::module &mod){

py::class_<Interface_SignType, opencascade::handle<Interface_SignType>, MoniTool_SignText> cls_Interface_SignType(mod, "Interface_SignType", "Provides the basic service to get a type name, according to a norm It can be used for other classes (general signatures ...)");

// Fields

// Methods
cls_Interface_SignType.def("Text", (TCollection_AsciiString (Interface_SignType::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &) const) &Interface_SignType::Text, "Returns an identification of the Signature (a word), given at initialization time Specialised to consider context as an InterfaceModel", py::arg("ent"), py::arg("context"));
cls_Interface_SignType.def("Value", (Standard_CString (Interface_SignType::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &Interface_SignType::Value, "Returns the Signature for a Transient object. It is specific of each sub-class of Signature. For a Null Handle, it should provide '' It can work with the model which contains the entity", py::arg("ent"), py::arg("model"));
cls_Interface_SignType.def_static("ClassName_", (Standard_CString (*)(const Standard_CString)) &Interface_SignType::ClassName, "From a CDL Type Name, returns the Class part (package dropped) WARNING : buffered, to be immediately copied or printed", py::arg("typnam"));
cls_Interface_SignType.def_static("get_type_name_", (const char * (*)()) &Interface_SignType::get_type_name, "None");
cls_Interface_SignType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_SignType::get_type_descriptor, "None");
cls_Interface_SignType.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_SignType::*)() const) &Interface_SignType::DynamicType, "None");

// Enums

}