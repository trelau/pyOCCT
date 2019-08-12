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
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_Schema.hxx>
#include <Storage_Root.hxx>
#include <Standard_Type.hxx>

void bind_Storage_Root(py::module &mod){

py::class_<Storage_Root, opencascade::handle<Storage_Root>, Standard_Transient> cls_Storage_Root(mod, "Storage_Root", "A root object extracted from a Storage_Data object. A Storage_Root encapsulates a persistent object which is a root of a Storage_Data object. It contains additional information: the name and the data type of the persistent object. When retrieving a Storage_Data object from a container (for example, a file) you access its roots with the function Roots which returns a sequence of root objects. The provided functions allow you to request information about each root of the sequence. You do not create explicit roots: when inserting data in a Storage_Data object, you just provide the persistent object and optionally its name to the function AddRoot.");

// Constructors
cls_Storage_Root.def(py::init<>());
cls_Storage_Root.def(py::init<const TCollection_AsciiString &, const opencascade::handle<Standard_Persistent> &>(), py::arg("theName"), py::arg("theObject"));
cls_Storage_Root.def(py::init<const TCollection_AsciiString &, const Standard_Integer, const TCollection_AsciiString &>(), py::arg("theName"), py::arg("theRef"), py::arg("theType"));

// Fields

// Methods
cls_Storage_Root.def("SetName", (void (Storage_Root::*)(const TCollection_AsciiString &)) &Storage_Root::SetName, "None", py::arg("theName"));
cls_Storage_Root.def("Name", (TCollection_AsciiString (Storage_Root::*)() const) &Storage_Root::Name, "Returns the name of this root object. The name may have been given explicitly when the root was inserted into the Storage_Data object. If not, the name is a reference number which was assigned automatically by the driver when writing the set of data into the container. When naming the roots, it is easier to retrieve objects by significant references rather than by references without any semantic values. Warning The returned string will be empty if you call this function before having named this root object, either explicitly, or when writing the set of data into the container.");
cls_Storage_Root.def("SetObject", (void (Storage_Root::*)(const opencascade::handle<Standard_Persistent> &)) &Storage_Root::SetObject, "None", py::arg("anObject"));
cls_Storage_Root.def("Object", (opencascade::handle<Standard_Persistent> (Storage_Root::*)() const) &Storage_Root::Object, "Returns the persistent object encapsulated by this root.");
cls_Storage_Root.def("Type", (TCollection_AsciiString (Storage_Root::*)() const) &Storage_Root::Type, "Returns the name of this root type.");
cls_Storage_Root.def("SetReference", (void (Storage_Root::*)(const Standard_Integer)) &Storage_Root::SetReference, "None", py::arg("aRef"));
cls_Storage_Root.def("Reference", (Standard_Integer (Storage_Root::*)() const) &Storage_Root::Reference, "None");
cls_Storage_Root.def("SetType", (void (Storage_Root::*)(const TCollection_AsciiString &)) &Storage_Root::SetType, "None", py::arg("aType"));
cls_Storage_Root.def_static("get_type_name_", (const char * (*)()) &Storage_Root::get_type_name, "None");
cls_Storage_Root.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_Root::get_type_descriptor, "None");
cls_Storage_Root.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_Root::*)() const) &Storage_Root::DynamicType, "None");

// Enums

}