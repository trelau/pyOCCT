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
#include <StepElement_MeasureOrUnspecifiedValue.hxx>
#include <Standard_Handle.hxx>
#include <StepElement_SurfaceSection.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_SurfaceSection(py::module &mod){

py::class_<StepElement_SurfaceSection, opencascade::handle<StepElement_SurfaceSection>, Standard_Transient> cls_StepElement_SurfaceSection(mod, "StepElement_SurfaceSection", "Representation of STEP entity SurfaceSection");

// Constructors
cls_StepElement_SurfaceSection.def(py::init<>());

// Fields

// Methods
cls_StepElement_SurfaceSection.def("Init", (void (StepElement_SurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_SurfaceSection::Init, "Initialize all fields (own and inherited)", py::arg("aOffset"), py::arg("aNonStructuralMass"), py::arg("aNonStructuralMassOffset"));
cls_StepElement_SurfaceSection.def("Offset", (StepElement_MeasureOrUnspecifiedValue (StepElement_SurfaceSection::*)() const) &StepElement_SurfaceSection::Offset, "Returns field Offset");
cls_StepElement_SurfaceSection.def("SetOffset", (void (StepElement_SurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_SurfaceSection::SetOffset, "Set field Offset", py::arg("Offset"));
cls_StepElement_SurfaceSection.def("NonStructuralMass", (StepElement_MeasureOrUnspecifiedValue (StepElement_SurfaceSection::*)() const) &StepElement_SurfaceSection::NonStructuralMass, "Returns field NonStructuralMass");
cls_StepElement_SurfaceSection.def("SetNonStructuralMass", (void (StepElement_SurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_SurfaceSection::SetNonStructuralMass, "Set field NonStructuralMass", py::arg("NonStructuralMass"));
cls_StepElement_SurfaceSection.def("NonStructuralMassOffset", (StepElement_MeasureOrUnspecifiedValue (StepElement_SurfaceSection::*)() const) &StepElement_SurfaceSection::NonStructuralMassOffset, "Returns field NonStructuralMassOffset");
cls_StepElement_SurfaceSection.def("SetNonStructuralMassOffset", (void (StepElement_SurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_SurfaceSection::SetNonStructuralMassOffset, "Set field NonStructuralMassOffset", py::arg("NonStructuralMassOffset"));
cls_StepElement_SurfaceSection.def_static("get_type_name_", (const char * (*)()) &StepElement_SurfaceSection::get_type_name, "None");
cls_StepElement_SurfaceSection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_SurfaceSection::get_type_descriptor, "None");
cls_StepElement_SurfaceSection.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_SurfaceSection::*)() const) &StepElement_SurfaceSection::DynamicType, "None");

// Enums

}