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
#include <AIS_GlobalStatus.hxx>
#include <Standard_Type.hxx>
#include <AIS_DisplayStatus.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Drawer.hxx>
#include <TColStd_ListOfInteger.hxx>

void bind_AIS_GlobalStatus(py::module &mod){

py::class_<AIS_GlobalStatus, opencascade::handle<AIS_GlobalStatus>, Standard_Transient> cls_AIS_GlobalStatus(mod, "AIS_GlobalStatus", "Stores information about objects in graphic context: - Status Of Display : in the main viewer hidden in the main viewer - Displayed Modes - Active Selection Modes - is the Interactive Object Current ? - Layer Index");

// Constructors
cls_AIS_GlobalStatus.def(py::init<>());
cls_AIS_GlobalStatus.def(py::init<const AIS_DisplayStatus, const Standard_Integer, const Standard_Integer>(), py::arg("aStat"), py::arg("aDispMode"), py::arg("aSelMode"));
cls_AIS_GlobalStatus.def(py::init<const AIS_DisplayStatus, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("aStat"), py::arg("aDispMode"), py::arg("aSelMode"), py::arg("ishilighted"));
cls_AIS_GlobalStatus.def(py::init<const AIS_DisplayStatus, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Integer>(), py::arg("aStat"), py::arg("aDispMode"), py::arg("aSelMode"), py::arg("ishilighted"), py::arg("aLayerIndex"));

// Fields

// Methods
cls_AIS_GlobalStatus.def_static("get_type_name_", (const char * (*)()) &AIS_GlobalStatus::get_type_name, "None");
cls_AIS_GlobalStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_GlobalStatus::get_type_descriptor, "None");
cls_AIS_GlobalStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::DynamicType, "None");
cls_AIS_GlobalStatus.def("SetGraphicStatus", (void (AIS_GlobalStatus::*)(const AIS_DisplayStatus)) &AIS_GlobalStatus::SetGraphicStatus, "None", py::arg("theStatus"));
cls_AIS_GlobalStatus.def("AddSelectionMode", (void (AIS_GlobalStatus::*)(const Standard_Integer)) &AIS_GlobalStatus::AddSelectionMode, "None", py::arg("theMode"));
cls_AIS_GlobalStatus.def("SetDisplayMode", (void (AIS_GlobalStatus::*)(const Standard_Integer)) &AIS_GlobalStatus::SetDisplayMode, "Sets display mode.", py::arg("theMode"));
cls_AIS_GlobalStatus.def("DisplayMode", (Standard_Integer (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::DisplayMode, "Returns the display mode.");
cls_AIS_GlobalStatus.def("SetLayerIndex", (void (AIS_GlobalStatus::*)(const Standard_Integer)) &AIS_GlobalStatus::SetLayerIndex, "None", py::arg("theIndex"));
cls_AIS_GlobalStatus.def("SetHilightStatus", (void (AIS_GlobalStatus::*)(const Standard_Boolean)) &AIS_GlobalStatus::SetHilightStatus, "None", py::arg("theStatus"));
cls_AIS_GlobalStatus.def("SetHilightStyle", (void (AIS_GlobalStatus::*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_GlobalStatus::SetHilightStyle, "Changes applied highlight style for a particular object", py::arg("theStyle"));
cls_AIS_GlobalStatus.def("HilightStyle", (const opencascade::handle<Prs3d_Drawer> & (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::HilightStyle, "Returns applied highlight style for a particular object");
cls_AIS_GlobalStatus.def("IsSubIntensityOn", (Standard_Boolean (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::IsSubIntensityOn, "None");
cls_AIS_GlobalStatus.def("SubIntensityOn", (void (AIS_GlobalStatus::*)()) &AIS_GlobalStatus::SubIntensityOn, "None");
cls_AIS_GlobalStatus.def("SubIntensityOff", (void (AIS_GlobalStatus::*)()) &AIS_GlobalStatus::SubIntensityOff, "None");
cls_AIS_GlobalStatus.def("RemoveSelectionMode", (void (AIS_GlobalStatus::*)(const Standard_Integer)) &AIS_GlobalStatus::RemoveSelectionMode, "None", py::arg("aMode"));
cls_AIS_GlobalStatus.def("ClearSelectionModes", (void (AIS_GlobalStatus::*)()) &AIS_GlobalStatus::ClearSelectionModes, "None");
cls_AIS_GlobalStatus.def("GraphicStatus", (AIS_DisplayStatus (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::GraphicStatus, "None");
cls_AIS_GlobalStatus.def("SelectionModes", (const TColStd_ListOfInteger & (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::SelectionModes, "keeps the active selection modes of the object in the main viewer.");
cls_AIS_GlobalStatus.def("IsHilighted", (Standard_Boolean (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::IsHilighted, "None");
cls_AIS_GlobalStatus.def("IsSModeIn", (Standard_Boolean (AIS_GlobalStatus::*)(const Standard_Integer) const) &AIS_GlobalStatus::IsSModeIn, "None", py::arg("aMode"));
cls_AIS_GlobalStatus.def("GetLayerIndex", (Standard_Integer (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::GetLayerIndex, "Returns layer index.");

// Enums

}