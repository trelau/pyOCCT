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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TObj_TXYZ.hxx>
#include <TDF_Label.hxx>
#include <gp_XYZ.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TObj_TXYZ(py::module &mod){

py::class_<TObj_TXYZ, opencascade::handle<TObj_TXYZ>, TDF_Attribute> cls_TObj_TXYZ(mod, "TObj_TXYZ", "None");

// Constructors
cls_TObj_TXYZ.def(py::init<>());

// Fields

// Methods
cls_TObj_TXYZ.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TXYZ::GetID, "This method is used in implementation of ID()");
cls_TObj_TXYZ.def("ID", (const Standard_GUID & (TObj_TXYZ::*)() const) &TObj_TXYZ::ID, "Returns the ID of TObj_TXYZ attribute.");
cls_TObj_TXYZ.def_static("Set_", (opencascade::handle<TObj_TXYZ> (*)(const TDF_Label &, const gp_XYZ &)) &TObj_TXYZ::Set, "Creates attribute and sets the XYZ", py::arg("theLabel"), py::arg("theXYZ"));
cls_TObj_TXYZ.def("Set", (void (TObj_TXYZ::*)(const gp_XYZ &)) &TObj_TXYZ::Set, "Sets the XYZ", py::arg("theXYZ"));
cls_TObj_TXYZ.def("Get", (gp_XYZ (TObj_TXYZ::*)() const) &TObj_TXYZ::Get, "Returns the XYZ");
cls_TObj_TXYZ.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TXYZ::*)() const) &TObj_TXYZ::NewEmpty, "Returns an new empty TObj_TXYZ attribute. It is used by the copy algorithm.");
cls_TObj_TXYZ.def("Restore", (void (TObj_TXYZ::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TXYZ::Restore, "Restores the backuped contents from <theWith> into this one. It is used when aborting a transaction.", py::arg("theWith"));
cls_TObj_TXYZ.def("Paste", (void (TObj_TXYZ::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TObj_TXYZ::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
cls_TObj_TXYZ.def("Dump", (Standard_OStream & (TObj_TXYZ::*)(Standard_OStream &) const) &TObj_TXYZ::Dump, "This method dumps the attribute value into the stream", py::arg("theOS"));
cls_TObj_TXYZ.def_static("get_type_name_", (const char * (*)()) &TObj_TXYZ::get_type_name, "None");
cls_TObj_TXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TXYZ::get_type_descriptor, "None");
cls_TObj_TXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TXYZ::*)() const) &TObj_TXYZ::DynamicType, "None");

// Enums

}