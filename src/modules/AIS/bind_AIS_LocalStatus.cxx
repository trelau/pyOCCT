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
#include <Standard_Handle.hxx>
#include <AIS_LocalStatus.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Drawer.hxx>
#include <TColStd_ListOfInteger.hxx>

void bind_AIS_LocalStatus(py::module &mod){

py::class_<AIS_LocalStatus, opencascade::handle<AIS_LocalStatus>, Standard_Transient> cls_AIS_LocalStatus(mod, "AIS_LocalStatus", "Stored Info about temporary objects.");

// Constructors
cls_AIS_LocalStatus.def(py::init<>());
cls_AIS_LocalStatus.def(py::init<const Standard_Boolean>(), py::arg("theIsTemporary"));
cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"));
cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Integer>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"), py::arg("theDisplayMode"));
cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"), py::arg("theDisplayMode"), py::arg("theSelectionMode"));
cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"), py::arg("theDisplayMode"), py::arg("theSelectionMode"), py::arg("theHilightMode"));
cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"), py::arg("theDisplayMode"), py::arg("theSelectionMode"), py::arg("theHilightMode"), py::arg("theIsSubIntensity"));
cls_AIS_LocalStatus.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const opencascade::handle<Prs3d_Drawer> &>(), py::arg("theIsTemporary"), py::arg("theIsToDecompose"), py::arg("theDisplayMode"), py::arg("theSelectionMode"), py::arg("theHilightMode"), py::arg("theIsSubIntensity"), py::arg("theStyle"));

// Fields

// Methods
cls_AIS_LocalStatus.def_static("get_type_name_", (const char * (*)()) &AIS_LocalStatus::get_type_name, "None");
cls_AIS_LocalStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_LocalStatus::get_type_descriptor, "None");
cls_AIS_LocalStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_LocalStatus::*)() const) &AIS_LocalStatus::DynamicType, "None");
cls_AIS_LocalStatus.def("Decomposed", (Standard_Boolean (AIS_LocalStatus::*)() const) &AIS_LocalStatus::Decomposed, "None");
cls_AIS_LocalStatus.def("IsTemporary", (Standard_Boolean (AIS_LocalStatus::*)() const) &AIS_LocalStatus::IsTemporary, "None");
cls_AIS_LocalStatus.def("DisplayMode", (Standard_Integer (AIS_LocalStatus::*)() const) &AIS_LocalStatus::DisplayMode, "None");
cls_AIS_LocalStatus.def("SelectionModes", (const TColStd_ListOfInteger & (AIS_LocalStatus::*)() const) &AIS_LocalStatus::SelectionModes, "None");
cls_AIS_LocalStatus.def("IsActivated", (Standard_Boolean (AIS_LocalStatus::*)(const Standard_Integer) const) &AIS_LocalStatus::IsActivated, "None", py::arg("aSelMode"));
cls_AIS_LocalStatus.def("HilightMode", (Standard_Integer (AIS_LocalStatus::*)() const) &AIS_LocalStatus::HilightMode, "None");
cls_AIS_LocalStatus.def("IsSubIntensityOn", (Standard_Boolean (AIS_LocalStatus::*)() const) &AIS_LocalStatus::IsSubIntensityOn, "None");
cls_AIS_LocalStatus.def("HilightStyle", (const opencascade::handle<Prs3d_Drawer> & (AIS_LocalStatus::*)() const) &AIS_LocalStatus::HilightStyle, "None");
cls_AIS_LocalStatus.def("SetDecomposition", (void (AIS_LocalStatus::*)(const Standard_Boolean)) &AIS_LocalStatus::SetDecomposition, "None", py::arg("astatus"));
cls_AIS_LocalStatus.def("SetTemporary", (void (AIS_LocalStatus::*)(const Standard_Boolean)) &AIS_LocalStatus::SetTemporary, "None", py::arg("astatus"));
cls_AIS_LocalStatus.def("SetDisplayMode", (void (AIS_LocalStatus::*)(const Standard_Integer)) &AIS_LocalStatus::SetDisplayMode, "None", py::arg("aMode"));
cls_AIS_LocalStatus.def("SetFirstDisplay", (void (AIS_LocalStatus::*)(const Standard_Boolean)) &AIS_LocalStatus::SetFirstDisplay, "None", py::arg("aStatus"));
cls_AIS_LocalStatus.def("IsFirstDisplay", (Standard_Boolean (AIS_LocalStatus::*)() const) &AIS_LocalStatus::IsFirstDisplay, "None");
cls_AIS_LocalStatus.def("AddSelectionMode", (void (AIS_LocalStatus::*)(const Standard_Integer)) &AIS_LocalStatus::AddSelectionMode, "None", py::arg("aMode"));
cls_AIS_LocalStatus.def("RemoveSelectionMode", (void (AIS_LocalStatus::*)(const Standard_Integer)) &AIS_LocalStatus::RemoveSelectionMode, "None", py::arg("aMode"));
cls_AIS_LocalStatus.def("ClearSelectionModes", (void (AIS_LocalStatus::*)()) &AIS_LocalStatus::ClearSelectionModes, "None");
cls_AIS_LocalStatus.def("IsSelModeIn", (Standard_Boolean (AIS_LocalStatus::*)(const Standard_Integer) const) &AIS_LocalStatus::IsSelModeIn, "None", py::arg("aMode"));
cls_AIS_LocalStatus.def("SetHilightMode", (void (AIS_LocalStatus::*)(const Standard_Integer)) &AIS_LocalStatus::SetHilightMode, "None", py::arg("aMode"));
cls_AIS_LocalStatus.def("SetHilightStyle", (void (AIS_LocalStatus::*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_LocalStatus::SetHilightStyle, "None", py::arg("theStyle"));
cls_AIS_LocalStatus.def("SubIntensityOn", (void (AIS_LocalStatus::*)()) &AIS_LocalStatus::SubIntensityOn, "None");
cls_AIS_LocalStatus.def("SubIntensityOff", (void (AIS_LocalStatus::*)()) &AIS_LocalStatus::SubIntensityOff, "None");
cls_AIS_LocalStatus.def("SetPreviousState", (void (AIS_LocalStatus::*)(const opencascade::handle<Standard_Transient> &)) &AIS_LocalStatus::SetPreviousState, "None", py::arg("aStatus"));
cls_AIS_LocalStatus.def("PreviousState", (const opencascade::handle<Standard_Transient> & (AIS_LocalStatus::*)() const) &AIS_LocalStatus::PreviousState, "None");

// Enums

}