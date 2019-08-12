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
#include <StepDimTol_GeometricTolerance.hxx>
#include <StepDimTol_GeometricToleranceRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_GeometricToleranceRelationship(py::module &mod){

py::class_<StepDimTol_GeometricToleranceRelationship, opencascade::handle<StepDimTol_GeometricToleranceRelationship>, Standard_Transient> cls_StepDimTol_GeometricToleranceRelationship(mod, "StepDimTol_GeometricToleranceRelationship", "Representation of STEP entity GeometricToleranceRelationship");

// Constructors
cls_StepDimTol_GeometricToleranceRelationship.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_GeometricToleranceRelationship.def("Init", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepDimTol_GeometricTolerance> &, const opencascade::handle<StepDimTol_GeometricTolerance> &)) &StepDimTol_GeometricToleranceRelationship::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theRelatingGeometricTolerance"), py::arg("theRelatedGeometricTolerance"));
cls_StepDimTol_GeometricToleranceRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricToleranceRelationship::*)() const) &StepDimTol_GeometricToleranceRelationship::Name, "Returns field Name");
cls_StepDimTol_GeometricToleranceRelationship.def("SetName", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricToleranceRelationship::SetName, "Set field Name", py::arg("theName"));
cls_StepDimTol_GeometricToleranceRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricToleranceRelationship::*)() const) &StepDimTol_GeometricToleranceRelationship::Description, "Returns field Description");
cls_StepDimTol_GeometricToleranceRelationship.def("SetDescription", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricToleranceRelationship::SetDescription, "Set field Description", py::arg("theDescription"));
cls_StepDimTol_GeometricToleranceRelationship.def("RelatingGeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepDimTol_GeometricToleranceRelationship::*)() const) &StepDimTol_GeometricToleranceRelationship::RelatingGeometricTolerance, "Returns field RelatingGeometricTolerance");
cls_StepDimTol_GeometricToleranceRelationship.def("SetRelatingGeometricTolerance", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<StepDimTol_GeometricTolerance> &)) &StepDimTol_GeometricToleranceRelationship::SetRelatingGeometricTolerance, "Set field RelatingGeometricTolerance", py::arg("theRelatingGeometricTolerance"));
cls_StepDimTol_GeometricToleranceRelationship.def("RelatedGeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepDimTol_GeometricToleranceRelationship::*)() const) &StepDimTol_GeometricToleranceRelationship::RelatedGeometricTolerance, "Returns field RelatedGeometricTolerance");
cls_StepDimTol_GeometricToleranceRelationship.def("SetRelatedGeometricTolerance", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<StepDimTol_GeometricTolerance> &)) &StepDimTol_GeometricToleranceRelationship::SetRelatedGeometricTolerance, "Set field RelatedGeometricTolerance", py::arg("theRelatedGeometricTolerance"));
cls_StepDimTol_GeometricToleranceRelationship.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceRelationship::get_type_name, "None");
cls_StepDimTol_GeometricToleranceRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceRelationship::get_type_descriptor, "None");
cls_StepDimTol_GeometricToleranceRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceRelationship::*)() const) &StepDimTol_GeometricToleranceRelationship::DynamicType, "None");

// Enums

}