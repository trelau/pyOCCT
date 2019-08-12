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
#include <StepRepr_ShapeRepresentationRelationship.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_Transformation.hxx>
#include <StepRepr_RepresentationRelationshipWithTransformation.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_RepresentationRelationshipWithTransformation(py::module &mod){

py::class_<StepRepr_RepresentationRelationshipWithTransformation, opencascade::handle<StepRepr_RepresentationRelationshipWithTransformation>, StepRepr_ShapeRepresentationRelationship> cls_StepRepr_RepresentationRelationshipWithTransformation(mod, "StepRepr_RepresentationRelationshipWithTransformation", "None");

// Constructors
cls_StepRepr_RepresentationRelationshipWithTransformation.def(py::init<>());

// Fields

// Methods
cls_StepRepr_RepresentationRelationshipWithTransformation.def("Init", (void (StepRepr_RepresentationRelationshipWithTransformation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<StepRepr_Representation> &, const StepRepr_Transformation &)) &StepRepr_RepresentationRelationshipWithTransformation::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aRep1"), py::arg("aRep2"), py::arg("aTransf"));
cls_StepRepr_RepresentationRelationshipWithTransformation.def("TransformationOperator", (StepRepr_Transformation (StepRepr_RepresentationRelationshipWithTransformation::*)() const) &StepRepr_RepresentationRelationshipWithTransformation::TransformationOperator, "None");
cls_StepRepr_RepresentationRelationshipWithTransformation.def("SetTransformationOperator", (void (StepRepr_RepresentationRelationshipWithTransformation::*)(const StepRepr_Transformation &)) &StepRepr_RepresentationRelationshipWithTransformation::SetTransformationOperator, "None", py::arg("aTrans"));
cls_StepRepr_RepresentationRelationshipWithTransformation.def_static("get_type_name_", (const char * (*)()) &StepRepr_RepresentationRelationshipWithTransformation::get_type_name, "None");
cls_StepRepr_RepresentationRelationshipWithTransformation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_RepresentationRelationshipWithTransformation::get_type_descriptor, "None");
cls_StepRepr_RepresentationRelationshipWithTransformation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_RepresentationRelationshipWithTransformation::*)() const) &StepRepr_RepresentationRelationshipWithTransformation::DynamicType, "None");

// Enums

}