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
#include <StepShape_SolidModel.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_ClosedShell.hxx>
#include <StepShape_ConnectedFaceSet.hxx>
#include <StepShape_ManifoldSolidBrep.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_ManifoldSolidBrep(py::module &mod){

py::class_<StepShape_ManifoldSolidBrep, opencascade::handle<StepShape_ManifoldSolidBrep>, StepShape_SolidModel> cls_StepShape_ManifoldSolidBrep(mod, "StepShape_ManifoldSolidBrep", "None");

// Constructors
cls_StepShape_ManifoldSolidBrep.def(py::init<>());

// Fields

// Methods
cls_StepShape_ManifoldSolidBrep.def("Init", (void (StepShape_ManifoldSolidBrep::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ClosedShell> &)) &StepShape_ManifoldSolidBrep::Init, "None", py::arg("aName"), py::arg("aOuter"));
cls_StepShape_ManifoldSolidBrep.def("Init", (void (StepShape_ManifoldSolidBrep::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ConnectedFaceSet> &)) &StepShape_ManifoldSolidBrep::Init, "None", py::arg("aName"), py::arg("aOuter"));
cls_StepShape_ManifoldSolidBrep.def("SetOuter", (void (StepShape_ManifoldSolidBrep::*)(const opencascade::handle<StepShape_ConnectedFaceSet> &)) &StepShape_ManifoldSolidBrep::SetOuter, "None", py::arg("aOuter"));
cls_StepShape_ManifoldSolidBrep.def("Outer", (opencascade::handle<StepShape_ConnectedFaceSet> (StepShape_ManifoldSolidBrep::*)() const) &StepShape_ManifoldSolidBrep::Outer, "None");
cls_StepShape_ManifoldSolidBrep.def_static("get_type_name_", (const char * (*)()) &StepShape_ManifoldSolidBrep::get_type_name, "None");
cls_StepShape_ManifoldSolidBrep.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ManifoldSolidBrep::get_type_descriptor, "None");
cls_StepShape_ManifoldSolidBrep.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ManifoldSolidBrep::*)() const) &StepShape_ManifoldSolidBrep::DynamicType, "None");

// Enums

}