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
#include <StdStorage_RootData.hxx>
#include <Standard_Handle.hxx>
#include <StdStorage_Root.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>

void bind_StdStorage_Root(py::module &mod){

py::class_<StdStorage_Root, opencascade::handle<StdStorage_Root>, Standard_Transient> cls_StdStorage_Root(mod, "StdStorage_Root", "Describes a named persistent root");

// Constructors
cls_StdStorage_Root.def(py::init<>());
cls_StdStorage_Root.def(py::init<const TCollection_AsciiString &, const opencascade::handle<StdObjMgt_Persistent> &>(), py::arg("theName"), py::arg("theObject"));

// Fields

// Methods
cls_StdStorage_Root.def_static("get_type_name_", (const char * (*)()) &StdStorage_Root::get_type_name, "None");
cls_StdStorage_Root.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdStorage_Root::get_type_descriptor, "None");
cls_StdStorage_Root.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdStorage_Root::*)() const) &StdStorage_Root::DynamicType, "None");
cls_StdStorage_Root.def("Name", (TCollection_AsciiString (StdStorage_Root::*)() const) &StdStorage_Root::Name, "Returns a name of the root");
cls_StdStorage_Root.def("SetName", (void (StdStorage_Root::*)(const TCollection_AsciiString &)) &StdStorage_Root::SetName, "Sets a name to the root object", py::arg("theName"));
cls_StdStorage_Root.def("Object", (opencascade::handle<StdObjMgt_Persistent> (StdStorage_Root::*)() const) &StdStorage_Root::Object, "Returns a root's persistent object");
cls_StdStorage_Root.def("SetObject", (void (StdStorage_Root::*)(const opencascade::handle<StdObjMgt_Persistent> &)) &StdStorage_Root::SetObject, "Sets a root's persistent object", py::arg("anObject"));
cls_StdStorage_Root.def("Type", (TCollection_AsciiString (StdStorage_Root::*)() const) &StdStorage_Root::Type, "Returns a root's persistent type");
cls_StdStorage_Root.def("SetType", (void (StdStorage_Root::*)(const TCollection_AsciiString &)) &StdStorage_Root::SetType, "Sets a root's persistent type", py::arg("aType"));
cls_StdStorage_Root.def("Reference", (Standard_Integer (StdStorage_Root::*)() const) &StdStorage_Root::Reference, "Returns root's position in the root data section");

// Enums

}