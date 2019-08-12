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
#include <AIS_TrihedronOwner.hxx>
#include <Standard_Type.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <Prs3d_DatumParts.hxx>
#include <Standard_TypeDef.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Drawer.hxx>
#include <PrsMgr_PresentationManager.hxx>

void bind_AIS_TrihedronOwner(py::module &mod){

py::class_<AIS_TrihedronOwner, opencascade::handle<AIS_TrihedronOwner>, SelectMgr_EntityOwner> cls_AIS_TrihedronOwner(mod, "AIS_TrihedronOwner", "Entity owner for selection management of AIS_Trihedron object.");

// Constructors
cls_AIS_TrihedronOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const Prs3d_DatumParts, const Standard_Integer>(), py::arg("theSelObject"), py::arg("theDatumPart"), py::arg("thePriority"));

// Fields

// Methods
cls_AIS_TrihedronOwner.def_static("get_type_name_", (const char * (*)()) &AIS_TrihedronOwner::get_type_name, "None");
cls_AIS_TrihedronOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_TrihedronOwner::get_type_descriptor, "None");
cls_AIS_TrihedronOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_TrihedronOwner::*)() const) &AIS_TrihedronOwner::DynamicType, "None");
cls_AIS_TrihedronOwner.def("DatumPart", (Prs3d_DatumParts (AIS_TrihedronOwner::*)() const) &AIS_TrihedronOwner::DatumPart, "Returns the datum part identifier.");
cls_AIS_TrihedronOwner.def("HilightWithColor", (void (AIS_TrihedronOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &AIS_TrihedronOwner::HilightWithColor, "Highlights selectable object's presentation.", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
cls_AIS_TrihedronOwner.def("IsHilighted", (Standard_Boolean (AIS_TrihedronOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const) &AIS_TrihedronOwner::IsHilighted, "Returns true if the presentation manager thePM highlights selections corresponding to the selection mode aMode.", py::arg("thePM"), py::arg("theMode"));
cls_AIS_TrihedronOwner.def("Unhilight", (void (AIS_TrihedronOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &AIS_TrihedronOwner::Unhilight, "Removes highlighting from the owner of a detected selectable object in the presentation manager thePM.", py::arg("thePM"), py::arg("theMode"));

// Enums

}