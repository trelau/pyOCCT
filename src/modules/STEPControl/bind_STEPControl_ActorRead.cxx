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
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Transfer_Binder.hxx>
#include <Transfer_TransientProcess.hxx>
#include <StepRepr_Representation.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <gp_Trsf.hxx>
#include <StepRepr_RepresentationRelationship.hxx>
#include <STEPControl_ActorRead.hxx>
#include <Standard_Type.hxx>
#include <TransferBRep_ShapeBinder.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <StepShape_ShapeRepresentation.hxx>
#include <StepShape_ContextDependentShapeRepresentation.hxx>
#include <StepRepr_ShapeRepresentationRelationship.hxx>
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <StepRepr_MappedItem.hxx>
#include <StepShape_FaceSurface.hxx>
#include <TopoDS_Shell.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Compound.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <StepToTopoDS_NMTool.hxx>

void bind_STEPControl_ActorRead(py::module &mod){

py::class_<STEPControl_ActorRead, opencascade::handle<STEPControl_ActorRead>, Transfer_ActorOfTransientProcess> cls_STEPControl_ActorRead(mod, "STEPControl_ActorRead", "This class performs the transfer of an Entity from AP214 and AP203, either Geometric or Topologic.");

// Constructors
cls_STEPControl_ActorRead.def(py::init<>());

// Fields

// Methods
cls_STEPControl_ActorRead.def("Recognize", (Standard_Boolean (STEPControl_ActorRead::*)(const opencascade::handle<Standard_Transient> &)) &STEPControl_ActorRead::Recognize, "None", py::arg("start"));
cls_STEPControl_ActorRead.def("Transfer", (opencascade::handle<Transfer_Binder> (STEPControl_ActorRead::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &)) &STEPControl_ActorRead::Transfer, "None", py::arg("start"), py::arg("TP"));
cls_STEPControl_ActorRead.def("TransferShape", [](STEPControl_ActorRead &self, const opencascade::handle<Standard_Transient> & a0, const opencascade::handle<Transfer_TransientProcess> & a1) -> opencascade::handle<Transfer_Binder> { return self.TransferShape(a0, a1); });
cls_STEPControl_ActorRead.def("TransferShape", (opencascade::handle<Transfer_Binder> (STEPControl_ActorRead::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &, const Standard_Boolean)) &STEPControl_ActorRead::TransferShape, "None", py::arg("start"), py::arg("TP"), py::arg("isManifold"));
cls_STEPControl_ActorRead.def("PrepareUnits", (void (STEPControl_ActorRead::*)(const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<Transfer_TransientProcess> &)) &STEPControl_ActorRead::PrepareUnits, "set units and tolerances context by given ShapeRepresentation", py::arg("rep"), py::arg("TP"));
cls_STEPControl_ActorRead.def("ResetUnits", (void (STEPControl_ActorRead::*)()) &STEPControl_ActorRead::ResetUnits, "reset units and tolerances context to default (mm, radians, read.precision.val, etc.)");
cls_STEPControl_ActorRead.def("ComputeTransformation", (Standard_Boolean (STEPControl_ActorRead::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<Transfer_TransientProcess> &, gp_Trsf &)) &STEPControl_ActorRead::ComputeTransformation, "Computes transformation defined by two axis placements (in MAPPED_ITEM or ITEM_DEFINED_TRANSFORMATION) taking into account their representation contexts (i.e. units, which may be different) Returns True if transformation is computed and is not an identity.", py::arg("Origin"), py::arg("Target"), py::arg("OrigContext"), py::arg("TargContext"), py::arg("TP"), py::arg("Trsf"));
cls_STEPControl_ActorRead.def("ComputeSRRWT", (Standard_Boolean (STEPControl_ActorRead::*)(const opencascade::handle<StepRepr_RepresentationRelationship> &, const opencascade::handle<Transfer_TransientProcess> &, gp_Trsf &)) &STEPControl_ActorRead::ComputeSRRWT, "Computes transformation defined by given REPRESENTATION_RELATIONSHIP_WITH_TRANSFORMATION", py::arg("SRR"), py::arg("TP"), py::arg("Trsf"));
cls_STEPControl_ActorRead.def_static("get_type_name_", (const char * (*)()) &STEPControl_ActorRead::get_type_name, "None");
cls_STEPControl_ActorRead.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPControl_ActorRead::get_type_descriptor, "None");
cls_STEPControl_ActorRead.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPControl_ActorRead::*)() const) &STEPControl_ActorRead::DynamicType, "None");

// Enums

}