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
#include <StepRepr_RepresentationItem.hxx>
#include <Transfer_FinderProcess.hxx>
#include <TopoDS_Shape.hxx>
#include <TopLoc_Location.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <Transfer_Binder.hxx>
#include <StepShape_ShapeDefinitionRepresentation.hxx>
#include <StepShape_ContextDependentShapeRepresentation.hxx>
#include <STEPConstruct_Tool.hxx>
#include <STEPConstruct_UnitContext.hxx>
#include <STEPConstruct_Part.hxx>
#include <STEPConstruct_Assembly.hxx>
#include <STEPConstruct_Styles.hxx>
#include <STEPConstruct_ValidationProps.hxx>
#include <STEPConstruct_ExternRefs.hxx>
#include <STEPConstruct_AP203Context.hxx>
#include <STEPConstruct_ContextTool.hxx>
#include <STEPConstruct_PointHasher.hxx>
#include <STEPConstruct.hxx>

void bind_STEPConstruct(py::module &mod){

py::class_<STEPConstruct, std::unique_ptr<STEPConstruct>> cls_STEPConstruct(mod, "STEPConstruct", "Defines tools for creation and investigation STEP constructs used for representing various kinds of data, such as product and assembly structure, unit contexts, associated information The creation of these structures is made according to currently active schema (AP203 or AP214 CD2 or DIS) This is taken from parameter write.step.schema");

// Constructors

// Fields

// Methods
// cls_STEPConstruct.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct.def_static("operator delete_", (void (*)(void *)) &STEPConstruct::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct.def_static("FindEntity_", (opencascade::handle<StepRepr_RepresentationItem> (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &)) &STEPConstruct::FindEntity, "Returns STEP entity of the (sub)type of RepresentationItem which is a result of the tranalation of the Shape, or Null if no result is recorded", py::arg("FinderProcess"), py::arg("Shape"));
cls_STEPConstruct.def_static("FindEntity_", (opencascade::handle<StepRepr_RepresentationItem> (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &, TopLoc_Location &)) &STEPConstruct::FindEntity, "The same as above, but in the case if item not found, repeats search on the same shape without location. The Loc corresponds to the location with which result is found (either location of the Shape, or Null)", py::arg("FinderProcess"), py::arg("Shape"), py::arg("Loc"));
cls_STEPConstruct.def_static("FindShape_", (TopoDS_Shape (*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<StepRepr_RepresentationItem> &)) &STEPConstruct::FindShape, "Returns Shape resulting from given STEP entity (Null if not mapped)", py::arg("TransientProcess"), py::arg("item"));
cls_STEPConstruct.def_static("FindCDSR_", (Standard_Boolean (*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, opencascade::handle<StepShape_ContextDependentShapeRepresentation> &)) &STEPConstruct::FindCDSR, "Find CDSR correcponding to the component in the specified assembly", py::arg("ComponentBinder"), py::arg("AssemblySDR"), py::arg("ComponentCDSR"));

// Enums

}