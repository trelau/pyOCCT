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
#include <AIS_DimensionOwner.hxx>
#include <Standard_Type.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <AIS_DimensionSelectionMode.hxx>
#include <Standard_TypeDef.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Drawer.hxx>
#include <PrsMgr_PresentationManager.hxx>

void bind_AIS_DimensionOwner(py::module &mod){

py::class_<AIS_DimensionOwner, opencascade::handle<AIS_DimensionOwner>, SelectMgr_EntityOwner> cls_AIS_DimensionOwner(mod, "AIS_DimensionOwner", "The owner is the entity which makes it possible to link the sensitive primitives and the reference shapes that you want to detect. It stocks the various pieces of information which make it possible to find objects. An owner has a priority which you can modulate, so as to make one entity more selectable than another. You might want to make edges more selectable than faces, for example. In that case, you could attribute sa higher priority to the one compared to the other. An edge, could have priority 5, for example, and a face, priority 4. The default priority is 5.");

// Constructors
cls_AIS_DimensionOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const AIS_DimensionSelectionMode>(), py::arg("theSelObject"), py::arg("theSelMode"));
cls_AIS_DimensionOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const AIS_DimensionSelectionMode, const Standard_Integer>(), py::arg("theSelObject"), py::arg("theSelMode"), py::arg("thePriority"));

// Fields

// Methods
cls_AIS_DimensionOwner.def_static("get_type_name_", (const char * (*)()) &AIS_DimensionOwner::get_type_name, "None");
cls_AIS_DimensionOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_DimensionOwner::get_type_descriptor, "None");
cls_AIS_DimensionOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_DimensionOwner::*)() const) &AIS_DimensionOwner::DynamicType, "None");
cls_AIS_DimensionOwner.def("SelectionMode", (AIS_DimensionSelectionMode (AIS_DimensionOwner::*)() const) &AIS_DimensionOwner::SelectionMode, "None");
cls_AIS_DimensionOwner.def("HilightWithColor", [](AIS_DimensionOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); });
cls_AIS_DimensionOwner.def("HilightWithColor", (void (AIS_DimensionOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &AIS_DimensionOwner::HilightWithColor, "None", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
cls_AIS_DimensionOwner.def("IsHilighted", [](AIS_DimensionOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> Standard_Boolean { return self.IsHilighted(a0); });
cls_AIS_DimensionOwner.def("IsHilighted", (Standard_Boolean (AIS_DimensionOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const) &AIS_DimensionOwner::IsHilighted, "Returns true if an object with the selection mode aMode is highlighted in the presentation manager aPM.", py::arg("thePM"), py::arg("theMode"));
cls_AIS_DimensionOwner.def("Unhilight", [](AIS_DimensionOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); });
cls_AIS_DimensionOwner.def("Unhilight", (void (AIS_DimensionOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &AIS_DimensionOwner::Unhilight, "Removes highlighting from the selected part of dimension.", py::arg("thePM"), py::arg("theMode"));

// Enums

}