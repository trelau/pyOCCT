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
#include <STEPConstruct_Tool.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepRepr_CharacterizedDefinition.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <gp_Pnt.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <StepRepr_PropertyDefinition.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_Unit.hxx>
#include <STEPConstruct_ValidationProps.hxx>

void bind_STEPConstruct_ValidationProps(py::module &mod){

py::class_<STEPConstruct_ValidationProps, std::unique_ptr<STEPConstruct_ValidationProps, Deleter<STEPConstruct_ValidationProps>>, STEPConstruct_Tool> cls_STEPConstruct_ValidationProps(mod, "STEPConstruct_ValidationProps", "This class provides tools for access (write and read) the validation properties on shapes in the STEP file. These are surface area, solid volume and centroid.");

// Constructors
cls_STEPConstruct_ValidationProps.def(py::init<>());
cls_STEPConstruct_ValidationProps.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));

// Fields

// Methods
// cls_STEPConstruct_ValidationProps.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_ValidationProps::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_ValidationProps.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_ValidationProps::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_ValidationProps.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_ValidationProps::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_ValidationProps.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_ValidationProps::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_ValidationProps.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_ValidationProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_ValidationProps.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_ValidationProps::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_ValidationProps.def("Init", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const opencascade::handle<XSControl_WorkSession> &)) &STEPConstruct_ValidationProps::Init, "Load worksession; returns True if succeeded", py::arg("WS"));
cls_STEPConstruct_ValidationProps.def("AddProp", [](STEPConstruct_ValidationProps &self, const TopoDS_Shape & a0, const opencascade::handle<StepRepr_RepresentationItem> & a1, const Standard_CString a2) -> Standard_Boolean { return self.AddProp(a0, a1, a2); });
cls_STEPConstruct_ValidationProps.def("AddProp", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &, const opencascade::handle<StepRepr_RepresentationItem> &, const Standard_CString, const Standard_Boolean)) &STEPConstruct_ValidationProps::AddProp, "General method for adding (writing) a validation property for shape which should be already mapped on writing itself. It uses FindTarget() to find target STEP entity resulting from given shape, and associated context Returns True if success, False in case of fail", py::arg("Shape"), py::arg("Prop"), py::arg("Descr"), py::arg("instance"));
cls_STEPConstruct_ValidationProps.def("AddProp", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const StepRepr_CharacterizedDefinition &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepRepr_RepresentationItem> &, const Standard_CString)) &STEPConstruct_ValidationProps::AddProp, "General method for adding (writing) a validation property for shape which should be already mapped on writing itself. It takes target and Context entities which correspond to shape Returns True if success, False in case of fail", py::arg("target"), py::arg("Context"), py::arg("Prop"), py::arg("Descr"));
cls_STEPConstruct_ValidationProps.def("AddArea", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &, const Standard_Real)) &STEPConstruct_ValidationProps::AddArea, "Adds surface area property for given shape (already mapped). Returns True if success, False in case of fail", py::arg("Shape"), py::arg("Area"));
cls_STEPConstruct_ValidationProps.def("AddVolume", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &, const Standard_Real)) &STEPConstruct_ValidationProps::AddVolume, "Adds volume property for given shape (already mapped). Returns True if success, False in case of fail", py::arg("Shape"), py::arg("Vol"));
cls_STEPConstruct_ValidationProps.def("AddCentroid", [](STEPConstruct_ValidationProps &self, const TopoDS_Shape & a0, const gp_Pnt & a1) -> Standard_Boolean { return self.AddCentroid(a0, a1); });
cls_STEPConstruct_ValidationProps.def("AddCentroid", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &, const gp_Pnt &, const Standard_Boolean)) &STEPConstruct_ValidationProps::AddCentroid, "Adds centroid property for given shape (already mapped). Returns True if success, False in case of fail If instance is True, then centroid is assigned to an instance of component in assembly", py::arg("Shape"), py::arg("Pnt"), py::arg("instance"));
cls_STEPConstruct_ValidationProps.def("FindTarget", [](STEPConstruct_ValidationProps &self, const TopoDS_Shape & a0, StepRepr_CharacterizedDefinition & a1, opencascade::handle<StepRepr_RepresentationContext> & a2) -> Standard_Boolean { return self.FindTarget(a0, a1, a2); });
cls_STEPConstruct_ValidationProps.def("FindTarget", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &, StepRepr_CharacterizedDefinition &, opencascade::handle<StepRepr_RepresentationContext> &, const Standard_Boolean)) &STEPConstruct_ValidationProps::FindTarget, "Finds target STEP entity to which validation props should be assigned, and corresponding context, starting from shape Returns True if success, False in case of fail", py::arg("S"), py::arg("target"), py::arg("Context"), py::arg("instance"));
cls_STEPConstruct_ValidationProps.def("LoadProps", (Standard_Boolean (STEPConstruct_ValidationProps::*)(TColStd_SequenceOfTransient &) const) &STEPConstruct_ValidationProps::LoadProps, "Searches for entities of the type PropertyDefinitionRepresentation in the model and fills the sequence by them", py::arg("seq"));
cls_STEPConstruct_ValidationProps.def("GetPropNAUO", (opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> (STEPConstruct_ValidationProps::*)(const opencascade::handle<StepRepr_PropertyDefinition> &) const) &STEPConstruct_ValidationProps::GetPropNAUO, "Returns CDSR associated with given PpD or NULL if not found (when, try GetPropSDR)", py::arg("PD"));
cls_STEPConstruct_ValidationProps.def("GetPropPD", (opencascade::handle<StepBasic_ProductDefinition> (STEPConstruct_ValidationProps::*)(const opencascade::handle<StepRepr_PropertyDefinition> &) const) &STEPConstruct_ValidationProps::GetPropPD, "Returns SDR associated with given PpD or NULL if not found (when, try GetPropCDSR)", py::arg("PD"));
cls_STEPConstruct_ValidationProps.def("GetPropShape", (TopoDS_Shape (STEPConstruct_ValidationProps::*)(const opencascade::handle<StepBasic_ProductDefinition> &) const) &STEPConstruct_ValidationProps::GetPropShape, "Returns Shape associated with given SDR or Null Shape if not found", py::arg("ProdDef"));
cls_STEPConstruct_ValidationProps.def("GetPropShape", (TopoDS_Shape (STEPConstruct_ValidationProps::*)(const opencascade::handle<StepRepr_PropertyDefinition> &) const) &STEPConstruct_ValidationProps::GetPropShape, "Returns Shape associated with given PpD or Null Shape if not found", py::arg("PD"));
cls_STEPConstruct_ValidationProps.def("GetPropReal", [](STEPConstruct_ValidationProps &self, const opencascade::handle<StepRepr_RepresentationItem> & item, Standard_Real & Val, Standard_Boolean & isArea){ Standard_Boolean rv = self.GetPropReal(item, Val, isArea); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &>(rv, Val, isArea); }, "Returns value of Real-Valued property (Area or Volume) If Property is neither Area nor Volume, returns False Else returns True and isArea indicates whether property is area or volume", py::arg("item"), py::arg("Val"), py::arg("isArea"));
cls_STEPConstruct_ValidationProps.def("GetPropPnt", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, gp_Pnt &) const) &STEPConstruct_ValidationProps::GetPropPnt, "Returns value of Centriod property (or False if it is not)", py::arg("item"), py::arg("Context"), py::arg("Pnt"));
cls_STEPConstruct_ValidationProps.def("SetAssemblyShape", (void (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &)) &STEPConstruct_ValidationProps::SetAssemblyShape, "Sets current assembly shape SDR (for FindCDSR calls)", py::arg("shape"));

// Enums

}