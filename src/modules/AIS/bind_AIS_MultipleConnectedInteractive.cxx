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
#include <AIS_InteractiveObject.hxx>
#include <Standard_Handle.hxx>
#include <AIS_MultipleConnectedInteractive.hxx>
#include <Standard_Type.hxx>
#include <Geom_Transformation.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Projector.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <AIS_InteractiveContext.hxx>
#include <gp_Trsf.hxx>
#include <Graphic3d_TransModeFlags.hxx>
#include <gp_Pnt.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>

void bind_AIS_MultipleConnectedInteractive(py::module &mod){

py::class_<AIS_MultipleConnectedInteractive, opencascade::handle<AIS_MultipleConnectedInteractive>, AIS_InteractiveObject> cls_AIS_MultipleConnectedInteractive(mod, "AIS_MultipleConnectedInteractive", "Defines an Interactive Object by gathering together several object presentations. This is done through a list of interactive objects. These can also be Connected objects. That way memory-costly calculations of presentation are avoided.");

// Constructors
cls_AIS_MultipleConnectedInteractive.def(py::init<>());

// Fields

// Methods
cls_AIS_MultipleConnectedInteractive.def_static("get_type_name_", (const char * (*)()) &AIS_MultipleConnectedInteractive::get_type_name, "None");
cls_AIS_MultipleConnectedInteractive.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_MultipleConnectedInteractive::get_type_descriptor, "None");
cls_AIS_MultipleConnectedInteractive.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::DynamicType, "None");
cls_AIS_MultipleConnectedInteractive.def("Connect", (opencascade::handle<AIS_InteractiveObject> (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Graphic3d_TransformPers> &)) &AIS_MultipleConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, theInteractive, and its reference. Locates instance in theLocation and applies specified transformation persistence mode.", py::arg("theAnotherObj"), py::arg("theLocation"), py::arg("theTrsfPers"));
cls_AIS_MultipleConnectedInteractive.def("Type", (AIS_KindOfInteractive (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::Type, "None");
cls_AIS_MultipleConnectedInteractive.def("Signature", (Standard_Integer (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::Signature, "None");
cls_AIS_MultipleConnectedInteractive.def("HasConnection", (Standard_Boolean (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::HasConnection, "Returns true if the object is connected to others.");
cls_AIS_MultipleConnectedInteractive.def("Disconnect", (void (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_MultipleConnectedInteractive::Disconnect, "Removes the connection with theInteractive.", py::arg("theInteractive"));
cls_AIS_MultipleConnectedInteractive.def("DisconnectAll", (void (AIS_MultipleConnectedInteractive::*)()) &AIS_MultipleConnectedInteractive::DisconnectAll, "Clears all the connections to objects.");
cls_AIS_MultipleConnectedInteractive.def("Compute", (void (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_MultipleConnectedInteractive::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_MultipleConnectedInteractive.def("Compute", (void (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_MultipleConnectedInteractive::Compute, "None", py::arg("aProjector"), py::arg("aPresentation"));
cls_AIS_MultipleConnectedInteractive.def("AcceptShapeDecomposition", (Standard_Boolean (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::AcceptShapeDecomposition, "Informs the graphic context that the interactive Object may be decomposed into sub-shapes for dynamic selection.");
cls_AIS_MultipleConnectedInteractive.def("GetAssemblyOwner", (const opencascade::handle<SelectMgr_EntityOwner> & (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::GetAssemblyOwner, "Returns common entity owner if the object is an assembly");
cls_AIS_MultipleConnectedInteractive.def("GlobalSelOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::GlobalSelOwner, "Returns the owner of mode for selection of object as a whole");
cls_AIS_MultipleConnectedInteractive.def("SetContext", (void (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveContext> &)) &AIS_MultipleConnectedInteractive::SetContext, "Assigns interactive context.", py::arg("theCtx"));
cls_AIS_MultipleConnectedInteractive.def("Connect", (opencascade::handle<AIS_InteractiveObject> (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_MultipleConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, theInteractive, and its reference. Copies local transformation and transformation persistence mode from theInteractive.", py::arg("theAnotherObj"));
cls_AIS_MultipleConnectedInteractive.def("Connect", (opencascade::handle<AIS_InteractiveObject> (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const gp_Trsf &)) &AIS_MultipleConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, theInteractive, and its reference. Locates instance in theLocation and copies transformation persistence mode from theInteractive.", py::arg("theAnotherObj"), py::arg("theLocation"));
cls_AIS_MultipleConnectedInteractive.def("Connect", (opencascade::handle<AIS_InteractiveObject> (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const gp_Trsf &, const opencascade::handle<Graphic3d_TransformPers> &)) &AIS_MultipleConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, theInteractive, and its reference. Locates instance in theLocation and applies specified transformation persistence mode.", py::arg("theAnotherObj"), py::arg("theLocation"), py::arg("theTrsfPers"));
cls_AIS_MultipleConnectedInteractive.def("Connect", (opencascade::handle<AIS_InteractiveObject> (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const gp_Trsf &, const Graphic3d_TransModeFlags &, const gp_Pnt &)) &AIS_MultipleConnectedInteractive::Connect, "None", py::arg("theInteractive"), py::arg("theLocation"), py::arg("theTrsfPersFlag"), py::arg("theTrsfPersPoint"));

// Enums

}