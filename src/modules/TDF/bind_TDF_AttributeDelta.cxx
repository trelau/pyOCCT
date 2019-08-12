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
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_OStream.hxx>
#include <TDF_AttributeDelta.hxx>
#include <Standard_Type.hxx>

void bind_TDF_AttributeDelta(py::module &mod){

py::class_<TDF_AttributeDelta, opencascade::handle<TDF_AttributeDelta>, Standard_Transient> cls_TDF_AttributeDelta(mod, "TDF_AttributeDelta", "This class discribes the services we need to implement Delta and Undo/Redo services.");

// Fields

// Methods
cls_TDF_AttributeDelta.def("Apply", (void (TDF_AttributeDelta::*)()) &TDF_AttributeDelta::Apply, "Applies the delta to the attribute.");
cls_TDF_AttributeDelta.def("Label", (TDF_Label (TDF_AttributeDelta::*)() const) &TDF_AttributeDelta::Label, "Returns the label concerned by <me>.");
cls_TDF_AttributeDelta.def("Attribute", (opencascade::handle<TDF_Attribute> (TDF_AttributeDelta::*)() const) &TDF_AttributeDelta::Attribute, "Returns the reference attribute.");
cls_TDF_AttributeDelta.def("ID", (Standard_GUID (TDF_AttributeDelta::*)() const) &TDF_AttributeDelta::ID, "Returns the ID of the attribute concerned by <me>.");
cls_TDF_AttributeDelta.def("Dump", (Standard_OStream & (TDF_AttributeDelta::*)(Standard_OStream &) const) &TDF_AttributeDelta::Dump, "Dumps the contents.", py::arg("OS"));
cls_TDF_AttributeDelta.def("bits_left", (Standard_OStream & (TDF_AttributeDelta::*)(Standard_OStream &) const) &TDF_AttributeDelta::operator<<, py::is_operator(), "None", py::arg("OS"));
cls_TDF_AttributeDelta.def_static("get_type_name_", (const char * (*)()) &TDF_AttributeDelta::get_type_name, "None");
cls_TDF_AttributeDelta.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_AttributeDelta::get_type_descriptor, "None");
cls_TDF_AttributeDelta.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_AttributeDelta::*)() const) &TDF_AttributeDelta::DynamicType, "None");

// Enums

}