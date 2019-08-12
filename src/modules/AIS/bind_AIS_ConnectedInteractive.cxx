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
#include <AIS_ConnectedInteractive.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_TypeOfPresentation3d.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_Transformation.hxx>
#include <gp_Trsf.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Projector.hxx>
#include <SelectMgr_Selection.hxx>
#include <TopoDS_Shape.hxx>

void bind_AIS_ConnectedInteractive(py::module &mod){

py::class_<AIS_ConnectedInteractive, opencascade::handle<AIS_ConnectedInteractive>, AIS_InteractiveObject> cls_AIS_ConnectedInteractive(mod, "AIS_ConnectedInteractive", "Creates an arbitrary located instance of another Interactive Object, which serves as a reference. This allows you to use the Connected Interactive Object without having to recalculate presentation, selection or graphic structure. These are deduced from your reference object. The relation between the connected interactive object and its source is generally one of geometric transformation. AIS_ConnectedInteractive class supports selection mode 0 for any InteractiveObject and all standard modes if its reference based on AIS_Shape. Descendants may redefine ComputeSelection() though. Also ConnectedInteractive will handle HLR if its reference based on AIS_Shape.");

// Constructors
cls_AIS_ConnectedInteractive.def(py::init<>());
cls_AIS_ConnectedInteractive.def(py::init<const PrsMgr_TypeOfPresentation3d>(), py::arg("aTypeOfPresentation3d"));

// Fields

// Methods
cls_AIS_ConnectedInteractive.def_static("get_type_name_", (const char * (*)()) &AIS_ConnectedInteractive::get_type_name, "None");
cls_AIS_ConnectedInteractive.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ConnectedInteractive::get_type_descriptor, "None");
cls_AIS_ConnectedInteractive.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::DynamicType, "None");
cls_AIS_ConnectedInteractive.def("Type", (AIS_KindOfInteractive (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::Type, "Returns KOI_Object");
cls_AIS_ConnectedInteractive.def("Signature", (Standard_Integer (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::Signature, "Returns 0");
cls_AIS_ConnectedInteractive.def("Connect", (void (AIS_ConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_ConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, anotherIobj, and its reference.", py::arg("theAnotherObj"));
cls_AIS_ConnectedInteractive.def("Connect", (void (AIS_ConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const gp_Trsf &)) &AIS_ConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, anotherIobj, and its reference. Locates instance in aLocation.", py::arg("theAnotherObj"), py::arg("theLocation"));
cls_AIS_ConnectedInteractive.def("Connect", (void (AIS_ConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Geom_Transformation> &)) &AIS_ConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, anotherIobj, and its reference. Locates instance in aLocation.", py::arg("theAnotherObj"), py::arg("theLocation"));
cls_AIS_ConnectedInteractive.def("HasConnection", (Standard_Boolean (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::HasConnection, "Returns true if there is a connection established between the presentation and its source reference.");
cls_AIS_ConnectedInteractive.def("ConnectedTo", (const opencascade::handle<AIS_InteractiveObject> & (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::ConnectedTo, "Returns the connection with the reference Interactive Object.");
cls_AIS_ConnectedInteractive.def("Disconnect", (void (AIS_ConnectedInteractive::*)()) &AIS_ConnectedInteractive::Disconnect, "Clears the connection with a source reference. The presentation will no longer be displayed. Warning Must be done before deleting the presentation.");
cls_AIS_ConnectedInteractive.def("AcceptShapeDecomposition", (Standard_Boolean (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::AcceptShapeDecomposition, "Informs the graphic context that the interactive Object may be decomposed into sub-shapes for dynamic selection.");
cls_AIS_ConnectedInteractive.def("AcceptDisplayMode", (Standard_Boolean (AIS_ConnectedInteractive::*)(const Standard_Integer) const) &AIS_ConnectedInteractive::AcceptDisplayMode, "Return true if reference presentation accepts specified display mode.", py::arg("theMode"));

// Enums

}