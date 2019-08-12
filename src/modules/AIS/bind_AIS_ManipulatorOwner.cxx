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
#include <SelectMgr_EntityOwner.hxx>
#include <Standard_Handle.hxx>
#include <AIS_ManipulatorOwner.hxx>
#include <Standard_Type.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <Standard_TypeDef.hxx>
#include <AIS_ManipulatorMode.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Drawer.hxx>
#include <PrsMgr_PresentationManager.hxx>

void bind_AIS_ManipulatorOwner(py::module &mod){

py::class_<AIS_ManipulatorOwner, opencascade::handle<AIS_ManipulatorOwner>, SelectMgr_EntityOwner> cls_AIS_ManipulatorOwner(mod, "AIS_ManipulatorOwner", "Entity owner for selection management of AIS_Manipulator object.");

// Constructors
cls_AIS_ManipulatorOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const AIS_ManipulatorMode>(), py::arg("theSelObject"), py::arg("theIndex"), py::arg("theMode"));
cls_AIS_ManipulatorOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const AIS_ManipulatorMode, const Standard_Integer>(), py::arg("theSelObject"), py::arg("theIndex"), py::arg("theMode"), py::arg("thePriority"));

// Fields

// Methods
cls_AIS_ManipulatorOwner.def_static("get_type_name_", (const char * (*)()) &AIS_ManipulatorOwner::get_type_name, "None");
cls_AIS_ManipulatorOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ManipulatorOwner::get_type_descriptor, "None");
cls_AIS_ManipulatorOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ManipulatorOwner::*)() const) &AIS_ManipulatorOwner::DynamicType, "None");
cls_AIS_ManipulatorOwner.def("HilightWithColor", (void (AIS_ManipulatorOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &AIS_ManipulatorOwner::HilightWithColor, "None", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
cls_AIS_ManipulatorOwner.def("IsHilighted", (Standard_Boolean (AIS_ManipulatorOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const) &AIS_ManipulatorOwner::IsHilighted, "None", py::arg("thePM"), py::arg("theMode"));
cls_AIS_ManipulatorOwner.def("Unhilight", (void (AIS_ManipulatorOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &AIS_ManipulatorOwner::Unhilight, "None", py::arg("thePM"), py::arg("theMode"));
cls_AIS_ManipulatorOwner.def("Mode", (AIS_ManipulatorMode (AIS_ManipulatorOwner::*)() const) &AIS_ManipulatorOwner::Mode, "None");
cls_AIS_ManipulatorOwner.def("Index", (Standard_Integer (AIS_ManipulatorOwner::*)() const) &AIS_ManipulatorOwner::Index, "Returns index of manipulator axis.");

// Enums

}