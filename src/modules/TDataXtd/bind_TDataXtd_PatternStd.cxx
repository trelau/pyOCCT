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
#include <TDataXtd_Pattern.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TDataXtd_PatternStd.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TNaming_NamedShape.hxx>
#include <TDataStd_Real.hxx>
#include <TDataStd_Integer.hxx>
#include <TDataXtd_Array1OfTrsf.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataXtd_PatternStd(py::module &mod){

py::class_<TDataXtd_PatternStd, opencascade::handle<TDataXtd_PatternStd>, TDataXtd_Pattern> cls_TDataXtd_PatternStd(mod, "TDataXtd_PatternStd", "to create a PatternStd (LinearPattern, CircularPattern, RectangularPattern, RadialCircularPattern, MirrorPattern)");

// Constructors
cls_TDataXtd_PatternStd.def(py::init<>());

// Fields

// Methods
cls_TDataXtd_PatternStd.def_static("GetPatternID_", (const Standard_GUID & (*)()) &TDataXtd_PatternStd::GetPatternID, "None");
cls_TDataXtd_PatternStd.def_static("Set_", (opencascade::handle<TDataXtd_PatternStd> (*)(const TDF_Label &)) &TDataXtd_PatternStd::Set, "Find, or create, a PatternStd attribute", py::arg("label"));
cls_TDataXtd_PatternStd.def("Signature", (void (TDataXtd_PatternStd::*)(const Standard_Integer)) &TDataXtd_PatternStd::Signature, "None", py::arg("signature"));
cls_TDataXtd_PatternStd.def("Axis1", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_PatternStd::Axis1, "None", py::arg("Axis1"));
cls_TDataXtd_PatternStd.def("Axis2", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_PatternStd::Axis2, "None", py::arg("Axis2"));
cls_TDataXtd_PatternStd.def("Axis1Reversed", (void (TDataXtd_PatternStd::*)(const Standard_Boolean)) &TDataXtd_PatternStd::Axis1Reversed, "None", py::arg("Axis1Reversed"));
cls_TDataXtd_PatternStd.def("Axis2Reversed", (void (TDataXtd_PatternStd::*)(const Standard_Boolean)) &TDataXtd_PatternStd::Axis2Reversed, "None", py::arg("Axis2Reversed"));
cls_TDataXtd_PatternStd.def("Value1", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDataStd_Real> &)) &TDataXtd_PatternStd::Value1, "None", py::arg("value"));
cls_TDataXtd_PatternStd.def("Value2", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDataStd_Real> &)) &TDataXtd_PatternStd::Value2, "None", py::arg("value"));
cls_TDataXtd_PatternStd.def("NbInstances1", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDataStd_Integer> &)) &TDataXtd_PatternStd::NbInstances1, "None", py::arg("NbInstances1"));
cls_TDataXtd_PatternStd.def("NbInstances2", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDataStd_Integer> &)) &TDataXtd_PatternStd::NbInstances2, "None", py::arg("NbInstances2"));
cls_TDataXtd_PatternStd.def("Mirror", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_PatternStd::Mirror, "None", py::arg("plane"));
cls_TDataXtd_PatternStd.def("Signature", (Standard_Integer (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Signature, "None");
cls_TDataXtd_PatternStd.def("Axis1", (opencascade::handle<TNaming_NamedShape> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Axis1, "None");
cls_TDataXtd_PatternStd.def("Axis2", (opencascade::handle<TNaming_NamedShape> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Axis2, "None");
cls_TDataXtd_PatternStd.def("Axis1Reversed", (Standard_Boolean (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Axis1Reversed, "None");
cls_TDataXtd_PatternStd.def("Axis2Reversed", (Standard_Boolean (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Axis2Reversed, "None");
cls_TDataXtd_PatternStd.def("Value1", (opencascade::handle<TDataStd_Real> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Value1, "None");
cls_TDataXtd_PatternStd.def("Value2", (opencascade::handle<TDataStd_Real> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Value2, "None");
cls_TDataXtd_PatternStd.def("NbInstances1", (opencascade::handle<TDataStd_Integer> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::NbInstances1, "None");
cls_TDataXtd_PatternStd.def("NbInstances2", (opencascade::handle<TDataStd_Integer> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::NbInstances2, "None");
cls_TDataXtd_PatternStd.def("Mirror", (opencascade::handle<TNaming_NamedShape> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Mirror, "None");
cls_TDataXtd_PatternStd.def("NbTrsfs", (Standard_Integer (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::NbTrsfs, "None");
cls_TDataXtd_PatternStd.def("ComputeTrsfs", (void (TDataXtd_PatternStd::*)(TDataXtd_Array1OfTrsf &) const) &TDataXtd_PatternStd::ComputeTrsfs, "None", py::arg("Trsfs"));
cls_TDataXtd_PatternStd.def("PatternID", (const Standard_GUID & (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::PatternID, "None");
cls_TDataXtd_PatternStd.def("Restore", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_PatternStd::Restore, "None", py::arg("With"));
cls_TDataXtd_PatternStd.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::NewEmpty, "None");
cls_TDataXtd_PatternStd.def("Paste", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_PatternStd::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataXtd_PatternStd.def("References", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataXtd_PatternStd::References, "None", py::arg("aDataSet"));
cls_TDataXtd_PatternStd.def("Dump", (Standard_OStream & (TDataXtd_PatternStd::*)(Standard_OStream &) const) &TDataXtd_PatternStd::Dump, "None", py::arg("anOS"));
cls_TDataXtd_PatternStd.def_static("get_type_name_", (const char * (*)()) &TDataXtd_PatternStd::get_type_name, "None");
cls_TDataXtd_PatternStd.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_PatternStd::get_type_descriptor, "None");
cls_TDataXtd_PatternStd.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::DynamicType, "None");

// Enums

}