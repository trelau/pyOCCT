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
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_LabelMap.hxx>
#include <TDF_AttributeMap.hxx>
#include <TDF_LabelDataMap.hxx>
#include <TDF_AttributeDataMap.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDF_RelocationTable(py::module &mod){

py::class_<TDF_RelocationTable, opencascade::handle<TDF_RelocationTable>, Standard_Transient> cls_TDF_RelocationTable(mod, "TDF_RelocationTable", "This is a relocation dictionnary between source and target labels, attributes or any transient(useful for copy or paste actions). Note that one target value may be the relocation value of more than one source object.");

// Constructors
cls_TDF_RelocationTable.def(py::init<>());
cls_TDF_RelocationTable.def(py::init<const Standard_Boolean>(), py::arg("selfRelocate"));

// Fields

// Methods
cls_TDF_RelocationTable.def("SelfRelocate", (void (TDF_RelocationTable::*)(const Standard_Boolean)) &TDF_RelocationTable::SelfRelocate, "Sets <mySelfRelocate> to <selfRelocate>.", py::arg("selfRelocate"));
cls_TDF_RelocationTable.def("SelfRelocate", (Standard_Boolean (TDF_RelocationTable::*)() const) &TDF_RelocationTable::SelfRelocate, "Returns <mySelfRelocate>.");
cls_TDF_RelocationTable.def("AfterRelocate", (void (TDF_RelocationTable::*)(const Standard_Boolean)) &TDF_RelocationTable::AfterRelocate, "None", py::arg("afterRelocate"));
cls_TDF_RelocationTable.def("AfterRelocate", (Standard_Boolean (TDF_RelocationTable::*)() const) &TDF_RelocationTable::AfterRelocate, "Returns <myAfterRelocate>.");
cls_TDF_RelocationTable.def("SetRelocation", (void (TDF_RelocationTable::*)(const TDF_Label &, const TDF_Label &)) &TDF_RelocationTable::SetRelocation, "Sets the relocation value of <aSourceLabel> to <aTargetLabel>.", py::arg("aSourceLabel"), py::arg("aTargetLabel"));
cls_TDF_RelocationTable.def("HasRelocation", (Standard_Boolean (TDF_RelocationTable::*)(const TDF_Label &, TDF_Label &) const) &TDF_RelocationTable::HasRelocation, "Finds the relocation value of <aSourceLabel> and returns it into <aTargetLabel>.", py::arg("aSourceLabel"), py::arg("aTargetLabel"));
cls_TDF_RelocationTable.def("SetRelocation", (void (TDF_RelocationTable::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_Attribute> &)) &TDF_RelocationTable::SetRelocation, "Sets the relocation value of <aSourceAttribute> to <aTargetAttribute>.", py::arg("aSourceAttribute"), py::arg("aTargetAttribute"));
cls_TDF_RelocationTable.def("HasRelocation", (Standard_Boolean (TDF_RelocationTable::*)(const opencascade::handle<TDF_Attribute> &, opencascade::handle<TDF_Attribute> &) const) &TDF_RelocationTable::HasRelocation, "Finds the relocation value of <aSourceAttribute> and returns it into <aTargetAttribute>.", py::arg("aSourceAttribute"), py::arg("aTargetAttribute"));
cls_TDF_RelocationTable.def("SetTransientRelocation", (void (TDF_RelocationTable::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &TDF_RelocationTable::SetTransientRelocation, "Sets the relocation value of <aSourceTransient> to <aTargetTransient>.", py::arg("aSourceTransient"), py::arg("aTargetTransient"));
cls_TDF_RelocationTable.def("HasTransientRelocation", (Standard_Boolean (TDF_RelocationTable::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &TDF_RelocationTable::HasTransientRelocation, "Finds the relocation value of <aSourceTransient> and returns it into <aTargetTransient>.", py::arg("aSourceTransient"), py::arg("aTargetTransient"));
cls_TDF_RelocationTable.def("Clear", (void (TDF_RelocationTable::*)()) &TDF_RelocationTable::Clear, "Clears the relocation dictionnary, but lets the self relocation flag to its current value.");
cls_TDF_RelocationTable.def("TargetLabelMap", (void (TDF_RelocationTable::*)(TDF_LabelMap &) const) &TDF_RelocationTable::TargetLabelMap, "Fills <aLabelMap> with target relocation labels. <aLabelMap> is not cleared before use.", py::arg("aLabelMap"));
cls_TDF_RelocationTable.def("TargetAttributeMap", (void (TDF_RelocationTable::*)(TDF_AttributeMap &) const) &TDF_RelocationTable::TargetAttributeMap, "Fills <anAttributeMap> with target relocation attributes. <anAttributeMap> is not cleared before use.", py::arg("anAttributeMap"));
cls_TDF_RelocationTable.def("LabelTable", (TDF_LabelDataMap & (TDF_RelocationTable::*)()) &TDF_RelocationTable::LabelTable, "Returns <myLabelTable> to be used or updated.");
cls_TDF_RelocationTable.def("AttributeTable", (TDF_AttributeDataMap & (TDF_RelocationTable::*)()) &TDF_RelocationTable::AttributeTable, "Returns <myAttributeTable> to be used or updated.");
cls_TDF_RelocationTable.def("TransientTable", (TColStd_IndexedDataMapOfTransientTransient & (TDF_RelocationTable::*)()) &TDF_RelocationTable::TransientTable, "Returns <myTransientTable> to be used or updated.");
cls_TDF_RelocationTable.def("Dump", (Standard_OStream & (TDF_RelocationTable::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, Standard_OStream &) const) &TDF_RelocationTable::Dump, "Dumps the relocation table.", py::arg("dumpLabels"), py::arg("dumpAttributes"), py::arg("dumpTransients"), py::arg("anOS"));
cls_TDF_RelocationTable.def_static("get_type_name_", (const char * (*)()) &TDF_RelocationTable::get_type_name, "None");
cls_TDF_RelocationTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_RelocationTable::get_type_descriptor, "None");
cls_TDF_RelocationTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_RelocationTable::*)() const) &TDF_RelocationTable::DynamicType, "None");

// Enums

}