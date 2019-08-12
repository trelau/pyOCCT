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
#include <StepRepr_DerivedShapeAspect.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepData_Logical.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepRepr_ParallelOffset.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ParallelOffset(py::module &mod){

py::class_<StepRepr_ParallelOffset, opencascade::handle<StepRepr_ParallelOffset>, StepRepr_DerivedShapeAspect> cls_StepRepr_ParallelOffset(mod, "StepRepr_ParallelOffset", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_ParallelOffset.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ParallelOffset.def("Init", (void (StepRepr_ParallelOffset::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_ParallelOffset::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theOfShape"), py::arg("theProductDefinitional"), py::arg("theOffset"));
cls_StepRepr_ParallelOffset.def("Offset", (opencascade::handle<StepBasic_MeasureWithUnit> (StepRepr_ParallelOffset::*)() const) &StepRepr_ParallelOffset::Offset, "Returns field Offset");
cls_StepRepr_ParallelOffset.def("SetOffset", (void (StepRepr_ParallelOffset::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_ParallelOffset::SetOffset, "Set field Offset", py::arg("theOffset"));
cls_StepRepr_ParallelOffset.def_static("get_type_name_", (const char * (*)()) &StepRepr_ParallelOffset::get_type_name, "None");
cls_StepRepr_ParallelOffset.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ParallelOffset::get_type_descriptor, "None");
cls_StepRepr_ParallelOffset.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ParallelOffset::*)() const) &StepRepr_ParallelOffset::DynamicType, "None");

// Enums

}