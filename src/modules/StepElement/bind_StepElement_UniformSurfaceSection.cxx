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
#include <StepElement_SurfaceSection.hxx>
#include <StepElement_MeasureOrUnspecifiedValue.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepElement_UniformSurfaceSection.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_UniformSurfaceSection(py::module &mod){

py::class_<StepElement_UniformSurfaceSection, opencascade::handle<StepElement_UniformSurfaceSection>, StepElement_SurfaceSection> cls_StepElement_UniformSurfaceSection(mod, "StepElement_UniformSurfaceSection", "Representation of STEP entity UniformSurfaceSection");

// Constructors
cls_StepElement_UniformSurfaceSection.def(py::init<>());

// Fields

// Methods
cls_StepElement_UniformSurfaceSection.def("Init", (void (StepElement_UniformSurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &, const Standard_Real, const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_UniformSurfaceSection::Init, "Initialize all fields (own and inherited)", py::arg("aSurfaceSection_Offset"), py::arg("aSurfaceSection_NonStructuralMass"), py::arg("aSurfaceSection_NonStructuralMassOffset"), py::arg("aThickness"), py::arg("aBendingThickness"), py::arg("aShearThickness"));
cls_StepElement_UniformSurfaceSection.def("Thickness", (Standard_Real (StepElement_UniformSurfaceSection::*)() const) &StepElement_UniformSurfaceSection::Thickness, "Returns field Thickness");
cls_StepElement_UniformSurfaceSection.def("SetThickness", (void (StepElement_UniformSurfaceSection::*)(const Standard_Real)) &StepElement_UniformSurfaceSection::SetThickness, "Set field Thickness", py::arg("Thickness"));
cls_StepElement_UniformSurfaceSection.def("BendingThickness", (StepElement_MeasureOrUnspecifiedValue (StepElement_UniformSurfaceSection::*)() const) &StepElement_UniformSurfaceSection::BendingThickness, "Returns field BendingThickness");
cls_StepElement_UniformSurfaceSection.def("SetBendingThickness", (void (StepElement_UniformSurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_UniformSurfaceSection::SetBendingThickness, "Set field BendingThickness", py::arg("BendingThickness"));
cls_StepElement_UniformSurfaceSection.def("ShearThickness", (StepElement_MeasureOrUnspecifiedValue (StepElement_UniformSurfaceSection::*)() const) &StepElement_UniformSurfaceSection::ShearThickness, "Returns field ShearThickness");
cls_StepElement_UniformSurfaceSection.def("SetShearThickness", (void (StepElement_UniformSurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_UniformSurfaceSection::SetShearThickness, "Set field ShearThickness", py::arg("ShearThickness"));
cls_StepElement_UniformSurfaceSection.def_static("get_type_name_", (const char * (*)()) &StepElement_UniformSurfaceSection::get_type_name, "None");
cls_StepElement_UniformSurfaceSection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_UniformSurfaceSection::get_type_descriptor, "None");
cls_StepElement_UniformSurfaceSection.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_UniformSurfaceSection::*)() const) &StepElement_UniformSurfaceSection::DynamicType, "None");

// Enums

}