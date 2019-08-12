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
#include <StepShape_ConnectedFaceSet.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_HArray1OfFace.hxx>
#include <StepShape_ConnectedFaceSubSet.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_ConnectedFaceSubSet(py::module &mod){

py::class_<StepShape_ConnectedFaceSubSet, opencascade::handle<StepShape_ConnectedFaceSubSet>, StepShape_ConnectedFaceSet> cls_StepShape_ConnectedFaceSubSet(mod, "StepShape_ConnectedFaceSubSet", "Representation of STEP entity ConnectedFaceSubSet");

// Constructors
cls_StepShape_ConnectedFaceSubSet.def(py::init<>());

// Fields

// Methods
cls_StepShape_ConnectedFaceSubSet.def("Init", (void (StepShape_ConnectedFaceSubSet::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfFace> &, const opencascade::handle<StepShape_ConnectedFaceSet> &)) &StepShape_ConnectedFaceSubSet::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aConnectedFaceSet_CfsFaces"), py::arg("aParentFaceSet"));
cls_StepShape_ConnectedFaceSubSet.def("ParentFaceSet", (opencascade::handle<StepShape_ConnectedFaceSet> (StepShape_ConnectedFaceSubSet::*)() const) &StepShape_ConnectedFaceSubSet::ParentFaceSet, "Returns field ParentFaceSet");
cls_StepShape_ConnectedFaceSubSet.def("SetParentFaceSet", (void (StepShape_ConnectedFaceSubSet::*)(const opencascade::handle<StepShape_ConnectedFaceSet> &)) &StepShape_ConnectedFaceSubSet::SetParentFaceSet, "Set field ParentFaceSet", py::arg("ParentFaceSet"));
cls_StepShape_ConnectedFaceSubSet.def_static("get_type_name_", (const char * (*)()) &StepShape_ConnectedFaceSubSet::get_type_name, "None");
cls_StepShape_ConnectedFaceSubSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ConnectedFaceSubSet::get_type_descriptor, "None");
cls_StepShape_ConnectedFaceSubSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ConnectedFaceSubSet::*)() const) &StepShape_ConnectedFaceSubSet::DynamicType, "None");

// Enums

}