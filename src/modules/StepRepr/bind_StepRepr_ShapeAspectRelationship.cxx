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
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ShapeAspectRelationship(py::module &mod){

py::class_<StepRepr_ShapeAspectRelationship, opencascade::handle<StepRepr_ShapeAspectRelationship>, Standard_Transient> cls_StepRepr_ShapeAspectRelationship(mod, "StepRepr_ShapeAspectRelationship", "Representation of STEP entity ShapeAspectRelationship");

// Constructors
cls_StepRepr_ShapeAspectRelationship.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ShapeAspectRelationship.def("Init", (void (StepRepr_ShapeAspectRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepRepr_ShapeAspectRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aRelatingShapeAspect"), py::arg("aRelatedShapeAspect"));
cls_StepRepr_ShapeAspectRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::Name, "Returns field Name");
cls_StepRepr_ShapeAspectRelationship.def("SetName", (void (StepRepr_ShapeAspectRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ShapeAspectRelationship::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_ShapeAspectRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::Description, "Returns field Description");
cls_StepRepr_ShapeAspectRelationship.def("SetDescription", (void (StepRepr_ShapeAspectRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ShapeAspectRelationship::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_ShapeAspectRelationship.def("HasDescription", (Standard_Boolean (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::HasDescription, "Returns True if optional field Description is defined");
cls_StepRepr_ShapeAspectRelationship.def("RelatingShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::RelatingShapeAspect, "Returns field RelatingShapeAspect");
cls_StepRepr_ShapeAspectRelationship.def("SetRelatingShapeAspect", (void (StepRepr_ShapeAspectRelationship::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepRepr_ShapeAspectRelationship::SetRelatingShapeAspect, "Set field RelatingShapeAspect", py::arg("RelatingShapeAspect"));
cls_StepRepr_ShapeAspectRelationship.def("RelatedShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::RelatedShapeAspect, "Returns field RelatedShapeAspect");
cls_StepRepr_ShapeAspectRelationship.def("SetRelatedShapeAspect", (void (StepRepr_ShapeAspectRelationship::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepRepr_ShapeAspectRelationship::SetRelatedShapeAspect, "Set field RelatedShapeAspect", py::arg("RelatedShapeAspect"));
cls_StepRepr_ShapeAspectRelationship.def_static("get_type_name_", (const char * (*)()) &StepRepr_ShapeAspectRelationship::get_type_name, "None");
cls_StepRepr_ShapeAspectRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ShapeAspectRelationship::get_type_descriptor, "None");
cls_StepRepr_ShapeAspectRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::DynamicType, "None");

// Enums

}