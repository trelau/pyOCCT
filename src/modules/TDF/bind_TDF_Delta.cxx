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
#include <TDF_LabelList.hxx>
#include <TDF_AttributeDeltaList.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_OStream.hxx>
#include <TDF_Data.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Delta.hxx>
#include <Standard_Type.hxx>
#include <TDF_AttributeDelta.hxx>

void bind_TDF_Delta(py::module &mod){

py::class_<TDF_Delta, opencascade::handle<TDF_Delta>, Standard_Transient> cls_TDF_Delta(mod, "TDF_Delta", "A set of AttributeDelta for a given transaction number and reference time number. A delta set is available at <aSourceTime>. If applied, it restores the TDF_Data in the state it was at <aTargetTime>.");

// Constructors
cls_TDF_Delta.def(py::init<>());

// Fields

// Methods
cls_TDF_Delta.def("IsEmpty", (Standard_Boolean (TDF_Delta::*)() const) &TDF_Delta::IsEmpty, "Returns true if there is nothing to undo.");
cls_TDF_Delta.def("IsApplicable", (Standard_Boolean (TDF_Delta::*)(const Standard_Integer) const) &TDF_Delta::IsApplicable, "Returns true if the Undo action of <me> is applicable at <aCurrentTime>.", py::arg("aCurrentTime"));
cls_TDF_Delta.def("BeginTime", (Standard_Integer (TDF_Delta::*)() const) &TDF_Delta::BeginTime, "Returns the field <myBeginTime>.");
cls_TDF_Delta.def("EndTime", (Standard_Integer (TDF_Delta::*)() const) &TDF_Delta::EndTime, "Returns the field <myEndTime>.");
cls_TDF_Delta.def("Labels", (void (TDF_Delta::*)(TDF_LabelList &) const) &TDF_Delta::Labels, "Adds in <aLabelList> the labels of the attribute deltas. Caution: <aLabelList> is not cleared before use.", py::arg("aLabelList"));
cls_TDF_Delta.def("AttributeDeltas", (const TDF_AttributeDeltaList & (TDF_Delta::*)() const) &TDF_Delta::AttributeDeltas, "Returns the field <myAttDeltaList>.");
cls_TDF_Delta.def("Name", (TCollection_ExtendedString (TDF_Delta::*)() const) &TDF_Delta::Name, "Returns a name associated with this delta.");
cls_TDF_Delta.def("SetName", (void (TDF_Delta::*)(const TCollection_ExtendedString &)) &TDF_Delta::SetName, "Associates a name <theName> with this delta", py::arg("theName"));
cls_TDF_Delta.def("Dump", (void (TDF_Delta::*)(Standard_OStream &) const) &TDF_Delta::Dump, "None", py::arg("OS"));
cls_TDF_Delta.def_static("get_type_name_", (const char * (*)()) &TDF_Delta::get_type_name, "None");
cls_TDF_Delta.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_Delta::get_type_descriptor, "None");
cls_TDF_Delta.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_Delta::*)() const) &TDF_Delta::DynamicType, "None");

// Enums

}