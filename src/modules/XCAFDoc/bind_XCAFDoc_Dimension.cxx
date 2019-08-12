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
#include <XCAFDoc_Dimension.hxx>
#include <TDF_Label.hxx>
#include <TDF_RelocationTable.hxx>
#include <XCAFDimTolObjects_DimensionObject.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_Dimension(py::module &mod){

py::class_<XCAFDoc_Dimension, opencascade::handle<XCAFDoc_Dimension>, TDF_Attribute> cls_XCAFDoc_Dimension(mod, "XCAFDoc_Dimension", "Attribute that identifies a dimension in the GD&T table. Its parent label is used as a container to store data provided by XCAFDimTolObjects_DimensionObject.");

// Constructors
cls_XCAFDoc_Dimension.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_Dimension.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Dimension::GetID, "None");
cls_XCAFDoc_Dimension.def_static("Set_", (opencascade::handle<XCAFDoc_Dimension> (*)(const TDF_Label &)) &XCAFDoc_Dimension::Set, "None", py::arg("theLabel"));
cls_XCAFDoc_Dimension.def("ID", (const Standard_GUID & (XCAFDoc_Dimension::*)() const) &XCAFDoc_Dimension::ID, "None");
cls_XCAFDoc_Dimension.def("Restore", (void (XCAFDoc_Dimension::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Dimension::Restore, "None", py::arg("With"));
cls_XCAFDoc_Dimension.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Dimension::*)() const) &XCAFDoc_Dimension::NewEmpty, "None");
cls_XCAFDoc_Dimension.def("Paste", (void (XCAFDoc_Dimension::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Dimension::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Dimension.def("SetObject", (void (XCAFDoc_Dimension::*)(const opencascade::handle<XCAFDimTolObjects_DimensionObject> &)) &XCAFDoc_Dimension::SetObject, "Updates parent's label and its sub-labels with data taken from theDimensionObject. Old data associated with the label will be lost.", py::arg("theDimensionObject"));
cls_XCAFDoc_Dimension.def("GetObject", (opencascade::handle<XCAFDimTolObjects_DimensionObject> (XCAFDoc_Dimension::*)() const) &XCAFDoc_Dimension::GetObject, "Returns dimension object data taken from the paren's label and its sub-labels.");
cls_XCAFDoc_Dimension.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Dimension::get_type_name, "None");
cls_XCAFDoc_Dimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Dimension::get_type_descriptor, "None");
cls_XCAFDoc_Dimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Dimension::*)() const) &XCAFDoc_Dimension::DynamicType, "None");

// Enums

}