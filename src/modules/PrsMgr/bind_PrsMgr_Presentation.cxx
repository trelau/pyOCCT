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
#include <PrsMgr_Presentation.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <PrsMgr_PresentableObject.hxx>
#include <PrsMgr_Prs.hxx>
#include <Prs3d_Presentation.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Drawer.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Geom_Transformation.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_DataStructureManager.hxx>
#include <Prs3d_Projector.hxx>
#include <PrsMgr_PresentableObjectPointer.hxx>

void bind_PrsMgr_Presentation(py::module &mod){

py::class_<PrsMgr_Presentation, opencascade::handle<PrsMgr_Presentation>, Standard_Transient> cls_PrsMgr_Presentation(mod, "PrsMgr_Presentation", "None");

// Constructors

// Fields

// Methods
cls_PrsMgr_Presentation.def_static("get_type_name_", (const char * (*)()) &PrsMgr_Presentation::get_type_name, "None");
cls_PrsMgr_Presentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PrsMgr_Presentation::get_type_descriptor, "None");
cls_PrsMgr_Presentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (PrsMgr_Presentation::*)() const) &PrsMgr_Presentation::DynamicType, "None");
cls_PrsMgr_Presentation.def("Presentation", (const opencascade::handle<Prs3d_Presentation> & (PrsMgr_Presentation::*)() const) &PrsMgr_Presentation::Presentation, "None");
cls_PrsMgr_Presentation.def("PresentationManager", (const opencascade::handle<PrsMgr_PresentationManager> & (PrsMgr_Presentation::*)() const) &PrsMgr_Presentation::PresentationManager, "returns the PresentationManager in which the presentation has been created.");
cls_PrsMgr_Presentation.def("SetUpdateStatus", (void (PrsMgr_Presentation::*)(const Standard_Boolean)) &PrsMgr_Presentation::SetUpdateStatus, "None", py::arg("theUpdateStatus"));
cls_PrsMgr_Presentation.def("MustBeUpdated", (Standard_Boolean (PrsMgr_Presentation::*)() const) &PrsMgr_Presentation::MustBeUpdated, "None");

// Enums

}