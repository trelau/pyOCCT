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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <StepShape_ShapeDefinitionRepresentation.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <Standard_Transient.hxx>
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Graph.hxx>
#include <StepShape_ContextDependentShapeRepresentation.hxx>
#include <StepShape_ShapeRepresentation.hxx>
#include <STEPConstruct_Assembly.hxx>

void bind_STEPConstruct_Assembly(py::module &mod){

py::class_<STEPConstruct_Assembly, std::unique_ptr<STEPConstruct_Assembly, Deleter<STEPConstruct_Assembly>>> cls_STEPConstruct_Assembly(mod, "STEPConstruct_Assembly", "This operator creates and checks an item of an assembly, from its basic data : a ShapeRepresentation, a Location ...");

// Constructors
cls_STEPConstruct_Assembly.def(py::init<>());

// Fields

// Methods
// cls_STEPConstruct_Assembly.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_Assembly::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_Assembly.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_Assembly::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_Assembly.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_Assembly::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_Assembly.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_Assembly::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_Assembly.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_Assembly::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_Assembly.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_Assembly::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_Assembly.def("Init", (void (STEPConstruct_Assembly::*)(const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<StepGeom_Axis2Placement3d> &)) &STEPConstruct_Assembly::Init, "Initialises with starting values Ax0 : origin axis (typically, standard XYZ) Loc : location to which place the item Makes a MappedItem Resulting Value is returned by ItemValue", py::arg("aSR"), py::arg("SDR0"), py::arg("Ax0"), py::arg("Loc"));
cls_STEPConstruct_Assembly.def("MakeRelationship", (void (STEPConstruct_Assembly::*)()) &STEPConstruct_Assembly::MakeRelationship, "Make a (ShapeRepresentationRelationship,...WithTransformation) Resulting Value is returned by ItemValue");
cls_STEPConstruct_Assembly.def("ItemValue", (opencascade::handle<Standard_Transient> (STEPConstruct_Assembly::*)() const) &STEPConstruct_Assembly::ItemValue, "Returns the Value If no Make... has been called, returns the starting SR");
cls_STEPConstruct_Assembly.def("ItemLocation", (opencascade::handle<StepGeom_Axis2Placement3d> (STEPConstruct_Assembly::*)() const) &STEPConstruct_Assembly::ItemLocation, "Returns the location of the item, computed from starting aLoc");
cls_STEPConstruct_Assembly.def("GetNAUO", (opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> (STEPConstruct_Assembly::*)() const) &STEPConstruct_Assembly::GetNAUO, "Returns NAUO object describing the assembly link");
cls_STEPConstruct_Assembly.def_static("CheckSRRReversesNAUO_", (Standard_Boolean (*)(const Interface_Graph &, const opencascade::handle<StepShape_ContextDependentShapeRepresentation> &)) &STEPConstruct_Assembly::CheckSRRReversesNAUO, "Checks whether SRR's definition of assembly and component contradicts with NAUO definition or not, according to model schema (AP214 or AP203)", py::arg("theGraph"), py::arg("CDSR"));

// Enums

}