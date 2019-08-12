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
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <TDF_LabelMap.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_AttributeMap.hxx>
#include <TDF_LabelList.hxx>
#include <Standard_OStream.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_Type.hxx>

void bind_TDF_DataSet(py::module &mod){

py::class_<TDF_DataSet, opencascade::handle<TDF_DataSet>, Standard_Transient> cls_TDF_DataSet(mod, "TDF_DataSet", "This class is a set of TDF informations like labels and attributes.");

// Constructors
cls_TDF_DataSet.def(py::init<>());

// Fields

// Methods
cls_TDF_DataSet.def("Clear", (void (TDF_DataSet::*)()) &TDF_DataSet::Clear, "Clears all information.");
cls_TDF_DataSet.def("IsEmpty", (Standard_Boolean (TDF_DataSet::*)() const) &TDF_DataSet::IsEmpty, "Returns true if there is at least one label or one attribute.");
cls_TDF_DataSet.def("AddLabel", (void (TDF_DataSet::*)(const TDF_Label &)) &TDF_DataSet::AddLabel, "Adds <aLabel> in the current data set.", py::arg("aLabel"));
cls_TDF_DataSet.def("ContainsLabel", (Standard_Boolean (TDF_DataSet::*)(const TDF_Label &) const) &TDF_DataSet::ContainsLabel, "Returns true if the label <alabel> is in the data set.", py::arg("aLabel"));
cls_TDF_DataSet.def("Labels", (TDF_LabelMap & (TDF_DataSet::*)()) &TDF_DataSet::Labels, "Returns the map of labels in this data set. This map can be used directly, or updated.");
cls_TDF_DataSet.def("AddAttribute", (void (TDF_DataSet::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_DataSet::AddAttribute, "Adds <anAttribute> into the current data set.", py::arg("anAttribute"));
cls_TDF_DataSet.def("ContainsAttribute", (Standard_Boolean (TDF_DataSet::*)(const opencascade::handle<TDF_Attribute> &) const) &TDF_DataSet::ContainsAttribute, "Returns true if <anAttribute> is in the data set.", py::arg("anAttribute"));
cls_TDF_DataSet.def("Attributes", (TDF_AttributeMap & (TDF_DataSet::*)()) &TDF_DataSet::Attributes, "Returns the map of attributes in the current data set. This map can be used directly, or updated.");
cls_TDF_DataSet.def("AddRoot", (void (TDF_DataSet::*)(const TDF_Label &)) &TDF_DataSet::AddRoot, "Adds a root label to <myRootLabels>.", py::arg("aLabel"));
cls_TDF_DataSet.def("Roots", (TDF_LabelList & (TDF_DataSet::*)()) &TDF_DataSet::Roots, "Returns <myRootLabels> to be used or updated.");
cls_TDF_DataSet.def("Dump", (Standard_OStream & (TDF_DataSet::*)(Standard_OStream &) const) &TDF_DataSet::Dump, "Dumps the minimum information about <me> on <aStream>.", py::arg("anOS"));
cls_TDF_DataSet.def("bits_left", (Standard_OStream & (TDF_DataSet::*)(Standard_OStream &) const) &TDF_DataSet::operator<<, py::is_operator(), "None", py::arg("anOS"));
cls_TDF_DataSet.def_static("get_type_name_", (const char * (*)()) &TDF_DataSet::get_type_name, "None");
cls_TDF_DataSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DataSet::get_type_descriptor, "None");
cls_TDF_DataSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DataSet::*)() const) &TDF_DataSet::DynamicType, "None");

// Enums

}